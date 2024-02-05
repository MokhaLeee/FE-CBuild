#!/usr/bin/python3
# -*- coding: UTF-8 -*-

import sys, ctypes

def main(args):
    try:
        sym = args[1]
    except IndexError:
        sys.exit(f"Usage: {args[0]} sym")

    symbols = {}

    with open(sym, 'r') as f:
        print('.macro dat value, name')
        print('    .global \\name')
        print('    .type \\name, object')
        print('    .set \\name, \\value')
        print('.endm')
        print('')
        print('.macro fun value, name')
        print('    .global \\name')
        print('    .type \\name, function')
        print('    .set \\name, \\value')
        print('.endm')
        print('')

        for line in f.readlines():
            try:
                addr = eval(f"0x{line[0:8]}")
                name = line[9:-1]
            except:
                continue

            # Invalid address
            if addr < 0x02000000 or addr > 0x0A000000:
                continue

            if name in symbols:
                continue

            symbols[name] = addr

            if addr & 1:
                print(f'fun {hex(addr)}, {name}')
            else:
                print(f'dat {hex(addr)}, {name}')

if __name__ == '__main__':
    main(sys.argv)
