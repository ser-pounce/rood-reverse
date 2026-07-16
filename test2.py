#!/usr/bin/env python3

import sys

def decode_string(payload):

    out = ''
    i = 0
    n = len(payload)
    
    while i < n:

        b = payload[i]
        
        if b == 1:
            out += '|f1|'
        elif b == 2:
            out += '|f2|'
        elif b == 3:
            out += '|f3|'
        elif b == 31:
            out += '|<|'
        else:
            if b == 0x7F:
                out += 'ü'
            else:
                out += chr(b)
        i += 1
    
    return out

def decode_script(payload):

    out = ''
    i = 0
    n = len(payload)

    while i < n:

        b = payload[i]

        if b == 1:
            i += 1            
            out += f"wait {payload[i]}"

        elif b == 2:
            i += 1
            b = payload[i]
            out += decode_string(payload[i : i + b + 1])
            i += b

        elif b == 3:
            out += 'bgenable'

        elif b == 4:
            i += 1
            b = payload[i]

            if b == 0:
                out += 'copyright'

            elif b == 1:
                out += 'gamelogo'

            elif b == 2:
                out += 'endcredits'

            elif b == 3:
                out += 'gametitle'
        
        elif b == 5:
            out += 'fadein'

        elif b == 6:
            out += 'fadeout'

        elif b == 7:
            out += 'freezescrolling'

        elif b == 8:
            i += 1
            b = payload[i]
            i += 1
            v = payload[i] | (payload[i + 1] << 8)
            i += 1
            out += f'bgtimer {b} {v}'

        elif b == 255:
            return out


        out += '\n'
        i += 1

    return out

with open(sys.argv[1], 'rb') as f:
    data = f.read()

offset = int(sys.argv[2], 16)

decode_script(data[offset:])
