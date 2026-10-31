#include "common.h"
#include <libapi.h>
#include <memory.h>

int func_8002F154(int chan, int block, u_char* buf)
{
    u_char readBuf[128];
    u_char* data;
    u_char sum;
    u_char checksum;
    int i = 0;
    int j;

    data = buf;
    sum = 0;

    for (j = 0; j < 127; ++j) {
        checksum = sum ^ *data;
        ++data;
        sum = checksum;
    }

    *data = checksum;

    for (;;) {
        u_char* dest;
        u_char* readPos;
        u_char readSum;
        int k;

        if (i >= 8) {
            return 0;
        }

        _new_card();

        if (_card_write(chan, block, buf) != 1) {
            return 0;
        }

        while (!(_card_status(chan >> 4) & 1)) { }

        dest = readBuf;
        bzero(dest, 128);
        _new_card();

        if (_card_read(chan, block, dest) == 1) {
            while (!(_card_status(chan >> 4) & 1)) { }
        }

        readPos = readBuf;
        readSum = 0;

        for (k = 0; k < 127; ++k) {
            readSum ^= *readPos;
            ++readPos;
        }

        if (buf[127] == readSum) {
            return 1;
        }

        ++i;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcard/FORMAT", _card_format);
