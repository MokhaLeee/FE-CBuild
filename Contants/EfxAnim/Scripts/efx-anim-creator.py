#!/usr/bin/python3
# -*- coding: UTF-8 -*-

import os, sys, argparse, traceback, hashlib

def show_exception_and_exit(exc_type, exc_value, tb):
    import traceback

    traceback.print_exception(exc_type, exc_value, tb)
    sys.exit(-1)

def gen_tokens(string):
    pos = 0

    string = string.strip()

    while len(string) > 0:
        if string[0] == '"':
            pos = string.find('"', 1)

            if pos < 0:
                yield string[1:]
                break

            yield string[1:pos]
            string = string[(pos+2):]

        else:
            pos = string.find(' ', 1)

            if pos < 0:
                yield string[:]
                break

            yield string[0:pos]
            string = string[(pos+1):]

        string = string.strip()

def efx_anim_dep(file):
    fpath_abs = os.path.abspath(file.name)
    print(fpath_abs, end = ' ')

    for line in file:
        frame, duration, name = line.split()

        if ".png" in name:
            fpath = os.path.join(os.path.dirname(fpath_abs), name)
            print(fpath, end = ' ')

class GfxEntry:
    def __init__(self, line):
        self.frameIndex = 0
        self.duration = 0
        self.fPath = ''
        self.hash = 0

        tokens = gen_tokens(line)

        try:
            self.frameIndex = next(tokens)
            self.duration = next(tokens)
            self.fPath = next(tokens)

        except StopIteration:
            sys.exit("Not enough components in line `{0}`.".format(line))

        self.hash = abs(hash(os.path.abspath(self.fPath)))

    def list_data_files(self, parentPath):
        realPath = os.path.join(os.path.dirname(parentPath), self.fPath)
        incBase = os.path.splitext(realPath)[0]

        yield incBase + '.img.bin'
        yield incBase + '.map.bin'
        yield incBase + '.pal.bin'

    def gen_event_gfx(self, parentPath):
        realPath = os.path.join(os.path.dirname(parentPath), self.fPath)

        if not os.path.exists(realPath):
            sys.exit("File `{0}` doesn't exist.".format(realPath))

        incBase = os.path.splitext(self.fPath)[0]

        yield '#ifndef IMG_{0}_{1}_INSTALLED\n'.format(incBase, self.hash)
        yield '#define IMG_{0}_{1}_INSTALLED\n'.format(incBase, self.hash)
        yield 'ALIGN 4\n'
        yield 'IMG_{0}:\n#incbin {1}\n'.format(incBase, incBase + '.img.bin')
        yield '#endif\n\n'

        yield '#ifndef TSA_{0}_{1}_INSTALLED\n'.format(incBase, self.hash)
        yield '#define TSA_{0}_{1}_INSTALLED\n'.format(incBase, self.hash)
        yield 'ALIGN 4\n'
        yield 'TSA_{0}:\n#incbin {1}\n'.format(incBase, incBase + '.map.bin')
        yield '#endif\n\n'

        yield '#ifndef PAL_{0}_{1}_INSTALLED\n'.format(incBase, self.hash)
        yield '#define PAL_{0}_{1}_INSTALLED\n'.format(incBase, self.hash)
        yield 'ALIGN 4\n'
        yield 'PAL_{0}:\n#incbin {1}\n'.format(incBase, incBase + '.pal.bin')
        yield '#endif\n\n'

def gen_header():
    yield '// File generated from by efx-anim-creator\n\n'
    yield 'ALIGN 4\n'
    yield 'POIN FRAMEs IMGs TSAs PALs\n'

def main(args):
    sys.excepthook = show_exception_and_exit

    argParser = argparse.ArgumentParser(description = "")

    argParser.add_argument("input", help = "input list file")

    meg = argParser.add_mutually_exclusive_group()
    meg.add_argument("--list-files", action = 'store_true', help = "print installer dependencies")
    meg.add_argument("-o", "--output", help = "output installer filename")

    arguments = argParser.parse_args()

    if not os.path.exists(arguments.input):
        sys.exit("File `{0}` doesn't exist.".format(arguments.input))

    imgs = []

    with open(arguments.input, 'r') as f:
        for line in f.readlines():
            line = line.strip()

            if (len(line) == 0):
                continue

            if line[0] == '#':
                continue

            imgs.append(GfxEntry(line))

    # Generate dependence
    if arguments.list_files:
        for img in imgs:
            for filename in img.list_data_files(arguments.input):
                print(filename, end = ' ')

    else:
        sys.stdout.writelines('{\n')
        sys.stdout.writelines(gen_header())

        # Generate frame lut
        sys.stdout.writelines('\nFRAMEs:\n')
        for img in imgs:
            sys.stdout.writelines('SHORT {0} {1}\n'.format(img.frameIndex, img.duration))
        sys.stdout.writelines('SHORT 0xFFFF\n') # Terminator of frame_lut

        sys.stdout.writelines('\nALIGN 4')

        # Generate image lut
        sys.stdout.writelines('\nIMGs:\n')
        for img in imgs:
            sys.stdout.writelines('POIN IMG_{0}\n'.format(os.path.splitext(img.fPath)[0]))

        # Generate palette lut
        sys.stdout.writelines('\nPALs:\n')
        for img in imgs:
            sys.stdout.writelines('POIN PAL_{0}\n'.format(os.path.splitext(img.fPath)[0]))

        # Generate TSA lut
        sys.stdout.writelines('\nTSAs:\n')
        for img in imgs:
            sys.stdout.writelines('POIN TSA_{0}\n'.format(os.path.splitext(img.fPath)[0]))

        # Insert generated img & tsa & pal
        sys.stdout.writelines('\n')

        for img in imgs:
            sys.stdout.writelines(img.gen_event_gfx(arguments.input))

        sys.stdout.writelines('}\n')

if __name__ == '__main__':
    main(sys.argv[1:])
