/* SPDX-License-Identifier: MIT
 * FntOpen and FntFlush adapted from Xeeynamo/psyz decomp/src/libgpu/font.c
 * (commit bed6ece8becbc6fae3a41285018c47fb1914c2d6), with the character test of
 * Xeeynamo/sotn-decomp src/main/psxsdk/libgpu/font.c
 * (commit ddfe818338828624899aaa9caf34cc2851786527).
 * Copyright (c) 2024 github.com/psyqz members
 * Copyright (c) 2025 github.com/xeeynamo/sotn-decomp contributors
 * See LICENSES/psyz-MIT.txt.
 */
#include "common.h"
#include <libgte.h>
#include <libgpu.h>
#include <memory.h>

typedef struct {
    TILE tile; /* 0x00: background */
    DR_MODE mode; /* 0x10 */
    int maxchars; /* 0x1C */
    SPRT_8* sprt; /* 0x20 */
    char* text; /* 0x24 */
    int count; /* 0x28 */
    int noclip; /* 0x2C */
} FntStream;

extern FntStream D_80032864[8];
extern u_long D_800329EC[]; /* font clut + 4-bit texture */
extern int D_800329E4; /* number of opened streams */
extern int D_800333EC; /* characters allocated */
extern char D_80039EA0[0x400];
extern SPRT_8 D_8003A2A0[0x400];
extern u_short D_8003E2A0; /* font tpage */
extern u_short D_8003E2A2; /* font clut */
extern int D_800329E8; /* stream printed by the GPU debug printf */
extern int (*D_80033440)(); /* GPU debug printf */

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/FONT", SetDumpFnt);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/FONT", FntLoad);

#define FONT_TILE (*&D_80032864[D_800329E4].tile)
int FntOpen(int x, int y, int w, int h, int isbg, int n)
{
    int i;
    RECT rect;
    SPRT_8* sprites;

    if (D_800329E4 >= 8) {
        return -1;
    }
    if (D_800329E4 == 0) {
        D_800333EC = 0;
    }
    D_80032864[D_800329E4].noclip = w == 0;
    if (D_800333EC + n > 0x400) {
        n = 0x400 - D_800333EC;
    }
    rect.x = 0;
    rect.y = 0;
    rect.w = 256;
    rect.h = 256;
    SetDrawMode(&D_80032864[D_800329E4].mode, 0, 0, D_8003E2A0, &rect);
    if (isbg) {
        SetTile(&D_80032864[D_800329E4].tile);
        FONT_TILE.r0 = 0;
        FONT_TILE.g0 = 0;
        FONT_TILE.b0 = 0;
        SetSemiTrans(&D_80032864[D_800329E4].tile, isbg == 2);
    }
    FONT_TILE.x0 = x;
    FONT_TILE.y0 = y;
    FONT_TILE.w = w;
    FONT_TILE.h = h;
    D_80032864[D_800329E4].maxchars = n;
    D_80032864[D_800329E4].count = 0;
    D_80032864[D_800329E4].text = &D_80039EA0[D_800333EC];
    D_80032864[D_800329E4].sprt = &D_8003A2A0[D_800333EC];
    D_80032864[D_800329E4].text[0] = '\0';
    sprites = D_80032864[D_800329E4].sprt;
    for (i = 0; i < n; i++, sprites++) {
        SetSprt8(sprites);
        sprites->clut = D_8003E2A2;
    }
    D_800333EC += n;
    return D_800329E4++;
}

u_long* FntFlush(int id)
{
    DR_MODE* dr;
    FntStream* font;
    int x, y;
    int xscreen;
    int max_y;
    SPRT_8* sprt;
    int max_x;
    int unwrap;
    int len;
    int line_break;
    char* buf;
    int ch2;
    u_char u, v;
    int r, g, b;

    xscreen = 0;
    r = 0x80;
    g = 0x80;
    b = 0x80;
    if (id < 0 || id >= D_800329E4) {
        id = D_800329E8;
        if (!D_80032864[id].text) {
            return NULL;
        }
    }
    font = &D_80032864[id];
    dr = &font->mode;
    sprt = font->sprt;
    unwrap = font->noclip;
    buf = font->text;
    len = font->maxchars;
    x = font->tile.x0;
    y = font->tile.y0;
    max_x = font->tile.w;
    max_x = x + (short)max_x;
    max_y = y + font->tile.h;
    TermPrim(dr);
    while (*buf) {
        if (!len) {
            break;
        }
        line_break = 0;
        ch2 = *buf;
        if (ch2 != ' ') {
            if (ch2 <= ' ') {
                switch (ch2) {
                case '\t':
                    goto do_tab;
                case '\n':
                    goto set_linebreak;
                }
                goto do_char;
            } else if (ch2 == '~') {
                if (*++buf == 'c') {
                    r = 16 * (*++buf - 48);
                    g = 16 * (*++buf - 48);
                    b = 16 * (*++buf - 48);
                }
            } else {
                goto do_char;
            do_tab:
                x += 0x20;
                goto check_x_boundary;
            do_char:
                if (*buf >= 'a' && *buf <= 'z') {
                    ch2 = *buf - 0x40;
                } else {
                    ch2 = *buf - 0x20;
                }
                u = (ch2 % 16) * 8;
                v = (ch2 / 16) * 8;
                sprt->u0 = u;
                sprt->v0 = v;
                sprt->x0 = x;
                sprt->y0 = y;
                sprt->r0 = r;
                sprt->g0 = g;
                sprt->b0 = b;
                AddPrim(dr, sprt++);
                x += 8;
            check_x_boundary:
                if (x >= max_x && !unwrap) {
                set_linebreak:
                    line_break = 1;
                }
            }
        } else {
            x += 8;
            if (x >= max_x && !unwrap) {
                line_break = 1;
            }
        }
        if (line_break) {
            if (xscreen < x) {
                xscreen = x;
            }
            y += 8;
            x = font->tile.x0;
            if (y >= max_y) {
                break;
            }
        }
        buf++;
        len--;
    }
    if (font->tile.code) {
        AddPrim(dr, &font->tile);
        if (unwrap) {
            unwrap = xscreen;
            font->tile.w = unwrap - font->tile.x0;
            font->tile.h = y - ((u_short)font->tile.y0 - 8);
        }
    }
    DrawOTag((u_long*)dr);
    font->count = 0;
    *font->text = '\0';
    return (u_long*)dr;
}

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libgpu/FONT", D_800107C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/FONT", FntPrint);
