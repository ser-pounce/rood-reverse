/* SPDX-License-Identifier: MIT
 * Adapted from ReGame-Labs/dcb_decomp src/main/psyq/libcard_end.c
 * (commit 6c9caf124450cafa1b5f402d03d82b90bb02d16e), symbol renames only.
 * Copyright (c) 2026 ReGame Labs. See LICENSES/dcb_decomp-MIT.txt.
 */
#include "common.h"
#include <memory.h>
#include <libapi.h>

int func_8002F154(long chan, long block, u_char* buf)
{
    u_char rbuf[128];
    u_char* p;
    u_char* rp;
    u_char sum;
    int i;
    int n;
    u_char* q;
    int k;

    i = 0;
    p = buf;
    sum = 0;
    for (n = 0; n < 127; n++) {
        sum ^= *p++;
    }
    *p = sum;
    while (1) {
        if (i >= 8) {
            return 0;
        }
        _new_card();
        if (_card_write(chan, block, buf) != 1) {
            return 0;
        }
        while (!(_card_status(chan >> 4) & 1)) { }
        rp = rbuf;
        bzero(rp, 128);
        _new_card();
        if (_card_read(chan, block, rp) == 1) {
            while (!(_card_status(chan >> 4) & 1)) { }
        }
        q = rbuf;
        sum = 0;
        for (k = 0; k < 127; k++) {
            sum ^= *q++;
        }
        if (buf[127] == sum) {
            return 1;
        }
        i++;
    }
}

typedef struct CardDir {
    /* 0x00 */ long attr;
    /* 0x04 */ long size;
    /* 0x08 */ u_short next;
    /* 0x0A */ char name[22];
} CardDir;

/* the sectors are copied into the buffer as unaligned byte blocks */
typedef struct {
    char c[32];
} CardBlk32;
typedef struct {
    char c[4];
} CardBlk4;

extern CardDir D_8003FEF8[15];
extern long D_800400D8[20];
extern u_char D_80040128[128];

/* read a block back and wait for the card to finish */
static inline int card_read_sync(long chan, long block, u_char* buf)
{
    if (_card_read(chan, block, buf) != 1) {
        return 0;
    }
    while (!(_card_status(chan >> 4) & 1)) { }
    return 1;
}

long _card_format(long chan)
{
    int i;

    for (i = 0; i < 15; i++) {
        bzero(D_80040128, 128);
        bzero((u_char*)&D_8003FEF8[i], 32);
        D_8003FEF8[i].attr = 0xA0;
        D_8003FEF8[i].size = 0;
        D_8003FEF8[i].next = 0xFFFF;
        *(CardBlk32*)D_80040128 = *(CardBlk32*)&D_8003FEF8[i];
        if (func_8002F154(chan, i + 1, D_80040128) != 1) {
            return 0;
        }
    }
    for (i = 0; i < 20; i++) {
        D_800400D8[i] = -1;
        bzero(D_80040128, 128);
        *(CardBlk4*)D_80040128 = *(CardBlk4*)&D_800400D8[i];
        if (func_8002F154(chan, i + 16, D_80040128) != 1) {
            return 0;
        }
    }
    bzero(D_80040128, 128);
    D_80040128[0] = 'M';
    D_80040128[1] = 'C';
    if (func_8002F154(chan, 0, D_80040128) != 1) {
        return 0;
    }
    bzero(D_80040128, 128);
    _new_card();
    if (card_read_sync(chan, 0, D_80040128) != 1) {
        return 0;
    }
    _new_card();
    if (_card_load(chan) != 1) {
        return 0;
    }
    while (!(_card_status(chan >> 4) & 1)) { }
    return 1;
}
