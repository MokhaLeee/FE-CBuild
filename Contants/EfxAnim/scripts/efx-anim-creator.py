#!/usr/bin/python3
# -*- coding: UTF-8 -*-

import os, sys, argparse, traceback

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
        duration, name = line.split()

        if ".png" in name:
            fpath = os.path.join(os.path.dirname(fpath_abs), name)
            print(fpath, end = ' ')

class FrameEntry:
    def __init__(self, line):
        self.frame = 0
        self.duration = 0

        tokens = gen_tokens(line)

        try:
            self.frame = next(tokens)
            self.duration = next(tokens)

        except StopIteration:
            sys.exit("Not enough components in line `{0}`.".format(line))

class GfxEntry:
    def __init__(self, line):
        self.fPath = ''

        tokens = gen_tokens(line)

        try:
            self.fPath = next(tokens)

        except StopIteration:
            sys.exit("Not enough components in line `{0}`.".format(line))

    def list_data_files(self, parentPath):
        realPath = os.path.join(os.path.dirname(parentPath), self.fPath)
        incBase = os.path.splitext(realPath)[0]

        yield incBase + '.img.bin'
        yield incBase + '.map.bin'
        yield incBase + '.pal.bin'

    def gen_event_img_insert(self, parentPath):
        realPath = os.path.join(os.path.dirname(parentPath), self.fPath)

        if not os.path.exists(realPath):
            sys.exit("File `{0}` doesn't exist.".format(realPath))

        incBase = os.path.splitext(self.fPath)[0]

        yield 'IMG_{0}:\n#incbin {1}\n\n'.format(incBase, incBase + '.img.bin')
        yield 'TSA_{0}:\n#incbin {1}\n\n'.format(incBase, incBase + '.map.bin')
        yield 'PAL_{0}:\n#incbin {1}\n\n'.format(incBase, incBase + '.pal.bin')

def gen_header():
    yield '// File generated from by efx-anim-creator\n'
    yield 'POIN IMGs TSAs PALs\n'

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
            sys.stdout.writelines(img.gen_event_img_insert(arguments.input))

        sys.stdout.writelines('}\n')

if __name__ == '__main__':
    main(sys.argv[1:])
