#include "common.h"
#include "146C.h"
#include "30DB0.h"
#include "58578.h"
#include "5BF94.h"
#include "../../SLUS_010.40/main.h"
#include <stddef.h>
#include <inline_c.h>
#include "vs_inline_c.h"
#include "gpu.h"

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    short unk4;
    char unk6;
    char unk7;
    SVECTOR unk8;
    char* unk10;
} D_800EB9B8_unk990;

typedef struct {
    func_800C1564_t unk0[2];
    short unk20;
    short unk22;
    int unk24;
    short unk28;
    short unk2A;
    char unk2C;
    char unk2D;
    char unk2E;
    char unk2F;
    char unk30;
    char unk31;
    char unk32;
    char unk33;
    int unk34;
    int unk38;
    short unk3C;
    short unk3E;
    int unk40[0x254];
    D_800EB9B8_unk990 unk990[24];
} D_800EB9B8_t;

typedef struct {
    u_short unk0[3];
    u_char unk6;
    u_char unk7;
    u_char unk8;
    u_char unk9;
    signed char unkA;
    char unkB[0xD];
} func_800C4650_t;

typedef struct {
    SVECTOR unk0;
    SVECTOR unk8;
    short unk10[4];
    short unk18[4];
} func_800C0FA8_t2;

typedef struct {
    u_long tag;
    struct {
        VS_TILE tile;
        VS_POLY_G4_TPAGE poly;
        u_long tpage;
    } box;
} labelBoxPrim_t;

void func_800C02A8(void);
MATRIX* func_800C085C(u_char* scale, int angle);
void func_800C0B50(func_800C1564_t* shape, int color);
int func_800C1034(func_800C1564_t* arg0, u_short* arg1);
int func_800C123C(func_800C1564_t* arg0, u_short* arg1, int arg2);
int func_800C1384(func_800C1564_t* arg0, u_short* arg1, int arg2);
void func_800C1DC4(D_800EB9B8_unk990* arg0);
void func_800C20B4(void);
void func_800C253C(int type);

extern D_800EB9B8_t* D_800EB9B8;
extern u_char D_800F4CB4;

void func_800C0D78(void)
{
    func_800C1564_t* shape = (func_800C1564_t*)0x1F800378;
    int color = 0x10401;
    short* sine = (short*)0x1F8003B0;
    int i;

    if (D_800EB9B8 == NULL) {
        return;
    }

    for (i = 0; i < 40; ++i) {
        sine[i] = rsin(i * ONE / 32);
    }

    for (i = 0; i < 2; color = 0x10104, ++shape, ++i) {
        MATRIX* m;
        int type;
        int j;

        *shape = D_800EB9B8->unk0[i];
        func_800C02A8();
        gte_ldv0(shape->unk8);
        gte_rtps2();
        gte_stszotz(&D_800EB9B8->unk20);
        switch (shape->unk0) {
        case 1:
            type = 0;
            break;
        case 2:
            shape->unk4.values[1] <<= 1;
            m = func_800C085C(shape->unk4.values, shape->unk2);
            for (j = 0; j < 3; ++j) {
                shape->unk8[j] += m->m[j][1] >> 1;
            }
            type = 1;
            break;
        case 3:
            type = 1;
            break;
        case 4:
            shape->unk4.values[3] += 0x80;
            m = func_800C085C(shape->unk4.values, shape->unk2);
            for (j = 0; j < 3; ++j) {
                shape->unk8[j] += m->m[j][1];
            }
            type = 2;
            break;
        case 5:
            type = 2;
            break;
        case 6:
            type = 3;
            break;
        case 7:
            type = 4;
            break;
        default:
            continue;
        }
        func_800C253C(type);
        func_800C0B50(shape, color);
    }
    func_800C20B4();
}

void func_800C0FA8(func_800C1564_t* arg0, func_800C0FA8_t2* arg1, MATRIX* arg2)
{
    int temp_v0;
    int i;
    char* new_var;

    for (i = 0; i < 3; ++i) {
        arg1->unk10[i] = arg0->unk8[i];
        arg1->unk18[i] = 0x8000 / *(new_var = &arg0->unk4.values[i]);
    }

    arg1->unk0.vx = arg0->unk4.values[3] * 0x10;
    arg1->unk0.vy = -arg0->unk2;
    arg1->unk0.vz = 0;

    RotMatrix_gte(&arg1->unk0, arg2);
}

int func_800C1034(func_800C1564_t* arg0, u_short* arg1)
{
    func_800C0FA8_t2 work;
    MATRIX matrix;
    int sum;
    int term;
    int i;

    func_800C0FA8(arg0, &work, &matrix);

    {
        void* ptr;
        void* base;
        int offset;

        i = 0;
        ptr = &work;
        base = ptr;
        offset = 0x10;

        do {
            *(short*)ptr = *arg1++ - *(u_short*)(base + offset);
            offset += 2;
            ++i;
            ptr += 2;
        } while (i < 3);
    }

    ApplyMatrixSV(&matrix, &work.unk0, &work.unk8);

    sum = 0;

    {
        char* base;
        int offset2;
        int offset;

        i = 0;
        base = (char*)&work;
        offset2 = 0x18;
        offset = 8;

        do {
            term = (*(short*)(base + offset) * *(short*)(base + offset2)) >> 12;
            sum += term * term;
            offset2 += 2;
            offset += 2;
            ++i;
        } while (i < 3);
    }

    return (sum >> 16) < 1u;
}

int func_800C110C(func_800C1564_t* arg0, u_short* arg1, int arg2)
{
    func_800C0FA8_t2 work;
    MATRIX matrix;
    int sum;
    int term;
    int i;

    func_800C0FA8(arg0, &work, &matrix);

    {
        short* ptr;
        void* base;
        int offset;

        i = 0;
        ptr = (short*)&work;
        base = &work;
        offset = 0x10;

        for (; i < 3; ++i) {
            *ptr = *arg1++ - *(u_short*)(base + offset);
            offset += 2;
            ++ptr;
        }
    }

    sum = 0;

    ApplyMatrixSV(&matrix, &work.unk0, &work.unk8);

    if (arg2 != 0) {
        work.unk8.vy -= arg0->unk4.flags.unk1 << 4;
    }

    if (!((u_short)-work.unk8.vy > (arg0->unk4.flags.unk1 << 5))) {
        char* base;
        int offset2;
        int offset;

        i = 0;
        base = (char*)&work;
        offset2 = 0x18;
        offset = 8;

        for (; i < 3; i += 2) {
            term = (*(short*)(base + offset) * *(short*)(base + offset2)) >> 12;
            sum += term * term;
            offset2 += 4;
            offset += 4;
        }

        sum = (sum >> 16) < 1u;
    }
    return sum;
}

int func_800C123C(func_800C1564_t* arg0, u_short* arg1, int arg2)
{
    func_800C0FA8_t2 work;
    MATRIX matrix;
    int temp1;
    int temp2;
    int divisor;
    int radius;

    func_800C0FA8(arg0, &work, &matrix);

    {
        int i;
        void* ptr;
        void* base;
        int offset;

        i = 0;
        ptr = &work;
        base = ptr;
        offset = 0x10;

        do {
            *(short*)ptr = *arg1++ - *(u_short*)(base + offset);
            offset += 2;
            ptr += 2;
            ++i;
        } while ((radius = i) < 3);
    }

    ApplyMatrixSV(&matrix, &work.unk0, &work.unk8);

    if (arg2 != 0) {
        work.unk8.vy -= arg0->unk4.flags.unk1 << 5;
    }

    if (!((u_short)-work.unk8.vy > (arg0->unk4.flags.unk1 << 5))) {
        divisor = -(((int)work.unk8.vy << 16) >> 13) / arg0->unk4.flags.unk1;
        temp1 = (work.unk8.vx * work.unk18[0]) >> 12;
        temp2 = ((radius = work.unk8.vz) * work.unk18[2]) >> 12;
        radius = 0x100 - divisor;

        if ((temp1 * temp1 + temp2 * temp2) < (radius * radius)) {
            return 1;
        }
    }
    return 0;
}

int func_800C1384(func_800C1564_t* shape, u_short* position, int angled)
{
    struct {
        int corners[5];
        int clip;
    } polygon;
    struct {
        short local[4];
        SVECTOR rotated;
        short origin[4];
    } work;
    MATRIX matrix;
    int i;
    int x;
    int z;
    int offsetX;
    int offsetZ;
    short* local;
    void* base;
    int offset;

    work.origin[0] = shape->unk8[0];
    work.origin[1] = shape->unk8[1];
    work.origin[2] = shape->unk8[2];
    work.local[0] = shape->unk4.values[3] << 4;
    work.local[1] = -shape->unk2;
    work.local[2] = 0;
    local = work.local;
    RotMatrix_gte((SVECTOR*)work.local, &matrix);
    for (i = 0, base = &work, offset = 16; i < 3; offset += 2, ++i, ++local) {
        *local = *position++ - *(u_short*)(base + offset);
    }
    ApplyMatrixSV(&matrix, (SVECTOR*)work.local, &work.rotated);
    if ((u_short)-work.rotated.vy > shape->unk4.values[1] * ONE / 128) {
        return 0;
    }
    x = shape->unk4.values[0] * ONE / 128;
    z = shape->unk4.values[2] * ONE / 128;
    if (angled) {
        offsetZ = z;
        offsetX = -x;
    } else {
        offsetZ = 0;
        offsetX = offsetZ;
    }
    polygon.corners[0] = (u_short)-x | (-offsetZ << 16);
    polygon.corners[1] = -offsetX | (-z << 16);
    polygon.corners[2] = x | (offsetZ << 16);
    polygon.corners[3] = (u_short)offsetX | (z << 16);
    polygon.corners[4] = (u_short)work.rotated.vx | (work.rotated.vz << 16);
    i = 0;
    do {
        gte_ldsxy3(polygon.corners[4], polygon.corners[i], polygon.corners[(i + 1) & 3]);
        gte_nclip2();
        gte_stopz(&polygon.clip);
        if (polygon.clip < 0) {
            return 0;
        }
        ++i;
    } while (i < 4);
    return 1;
}

int func_800C1564(func_800C1564_t* arg0, u_short* arg1)
{
    func_800C1564_flags saved_unk4 = arg0->unk4.flags;
    int ret = 0;

    switch (arg0->unk0) {
    case 1:
        ret = func_800C1034(arg0, arg1);
        break;
    case 2:
        arg0->unk4.flags.unk1 <<= 1;
        ret = func_800C110C(arg0, arg1, 1);
        break;
    case 3:
        ret = func_800C110C(arg0, arg1, 0);
        break;
    case 4:
        ret = func_800C123C(arg0, arg1, 0);
        break;
    case 5:
        arg0->unk4.flags.unk3 = saved_unk4.unk3 + 0x80;
        ret = func_800C123C(arg0, arg1, 1);
        break;
    case 6:
        ret = func_800C1384(arg0, arg1, 1);
        break;
    case 7:
        ret = func_800C1384(arg0, arg1, 0);
        break;
    }

    arg0->unk4.flags = saved_unk4;
    return ret;
}

void func_800C1664(int arg0, int arg1, int arg2)
{
    int var_a0;
    int var_v0;

    var_a0 = arg0;
    if (D_800EB9B8 != NULL) {
        if (var_a0 >= 0x19) {
            var_a0 = 0x18;
        }
        D_800EB9B8->unk2C = var_a0;
        D_800EB9B8->unk40[0] = arg1;
        if (D_800EB9B8->unk2D >= var_a0) {
            var_v0 = 0;
            if (var_a0 == 0) {
                var_v0 = 0xFF;
            }
            D_800EB9B8->unk2D = var_v0;
        }
        D_800EB9B8->unk31 = arg2;
        func_800C58F8(0);
    }
}

void func_800C16DC(void)
{
    if (D_800EB9B8 != NULL) {
        D_800EB9B8->unk2C = 0;
    }
}

void func_800C16FC(int x0, int x1, int count)
{
    int y0;
    int y1 = x1 >> 16;
    int midX;
    int signY = 1;
    int signX = 1;
    int length;
    int dx;
    int i;
    int y1Bits;
    int segmentEnd;
    int segmentStart;

    x1 = (short)x1;
    y0 = x0 >> 16;
    x0 = (short)x0;
    length = y0 - y1;
    if (length < 0) {
        signY = -1;
        length = -length;
    }
    if (length & 1) {
        y0 -= signY;
    }
    length >>= 1;
    midX = x0 + length;
    dx = x1 - midX;
    if (dx < 0) {
        signX = -1;
        dx = -dx;
    }
    length = length * 2 + dx;
    segmentEnd = length;
    segmentStart = 0;
    y1Bits = y1 << 16;
    for (i = 0; i < 16; ++i, segmentEnd += length, segmentStart += length) {
        int level = i - count + 16;
        int gray;
        int color;
        int start;

        if (count < i || level < 0) {
            continue;
        }
        gray = ((level * 3) << 6) >> 4;
        gray |= gray << 8;
        color = gray | (((level * 255 + (16 - level) * 32) >> 4) << 16);
        start = segmentStart >> 4;
        if (start < dx) {
            int end = segmentEnd >> 4;

            if (end < dx) {
                vs_battle_addTile(vs_scratch.unk8,
                    vs_getRGB0Raw(primLineF2SemiTrans, color),
                    ((x1 - start * signX) & 0xFFFF) | y1Bits,
                    ((x1 - (end - 1) * signX) & 0xFFFF) | y1Bits);
            } else {
                int lineColor = vs_getRGB0Raw(primLineF2SemiTrans, color);
                int tail;

                vs_battle_addTile(vs_scratch.unk8, lineColor,
                    ((x1 - start * signX) & 0xFFFF) | y1Bits,
                    ((midX + signX) & 0xFFFF) | y1Bits);
                tail = length * (15 - i);
                if (y1 != y0 - (tail >> 4) * signY) {
                    vs_battle_addTile(vs_scratch.unk8, lineColor,
                        (midX & 0xFFFF) | y1Bits,
                        vs_getXY_2(x0 + (tail >> 5), y0 - ((tail + 16) >> 4) * signY));
                }
            }
        } else {
            int far2 = length * (16 - i);
            int near2 = length * (15 - i);

            vs_battle_addTile(vs_scratch.unk8, vs_getRGB0Raw(primLineF2SemiTrans, color),
                vs_getXY_2(x0 + (far2 >> 5), y0 - (far2 >> 4) * signY),
                vs_getXY_2(x0 + (near2 >> 5), y0 - ((near2 + 16) >> 4) * signY));
        }
    }
    vs_battle_insertTpage(
        _get_mode(0, 0, getTPage(clut4Bit, semiTransparencyFull, 0, 0)), vs_scratch.unk8);
}

void func_800C1A40(int x0, int x1, int count)
{
    int y0;
    int y1 = x1 >> 16;
    int midX;
    int signY = 1;
    int signX = 1;
    int length;
    int dx;
    int i;
    int y1Bits;
    int segmentEnd;
    int segmentStart;

    x1 = (short)x1;
    y0 = x0 >> 16;
    x0 = (short)x0;
    length = y0 - y1;
    if (length < 0) {
        signY = -1;
        length = -length;
    }
    if (length & 1) {
        y0 -= signY;
    }
    length >>= 1;
    midX = x0 - length;
    dx = midX - x1;
    if (dx < 0) {
        signX = -1;
        dx = -dx;
    }
    length = length * 2 + dx;
    segmentEnd = length;
    segmentStart = 0;
    y1Bits = y1 << 16;
    for (i = 0; i < 16; ++i, segmentEnd += length, segmentStart += length) {
        int level = i - count + 16;
        int gray;
        int color;
        int start;

        if (count < i || level < 0) {
            continue;
        }
        gray = ((level * 3) << 6) >> 4;
        gray |= gray << 8;
        color = gray | (((level * 255 + (16 - level) * 32) >> 4) << 16);
        start = segmentStart >> 4;
        if (start < dx) {
            int end = segmentEnd >> 4;

            if (end < dx) {
                vs_battle_addTile(vs_scratch.unk8,
                    vs_getRGB0Raw(primLineF2SemiTrans, color),
                    ((x1 + start * signX) & 0xFFFF) | y1Bits,
                    ((x1 + (end - 1) * signX) & 0xFFFF) | y1Bits);
            } else {
                int lineColor = vs_getRGB0Raw(primLineF2SemiTrans, color);
                int tail;

                vs_battle_addTile(vs_scratch.unk8, lineColor,
                    ((x1 + start * signX) & 0xFFFF) | y1Bits,
                    ((midX - signX) & 0xFFFF) | y1Bits);
                tail = length * (15 - i);
                if (y1 != y0 - (tail >> 4) * signY) {
                    vs_battle_addTile(vs_scratch.unk8, lineColor,
                        (midX & 0xFFFF) | y1Bits,
                        vs_getXY_2(x0 - (tail >> 5), y0 - ((tail + 16) >> 4) * signY));
                }
            }
        } else {
            int far2 = length * (16 - i);
            int near2 = length * (15 - i);

            vs_battle_addTile(vs_scratch.unk8, vs_getRGB0Raw(primLineF2SemiTrans, color),
                vs_getXY_2(x0 - (far2 >> 5), y0 - (far2 >> 4) * signY),
                vs_getXY_2(x0 - (near2 >> 5), y0 - ((near2 + 16) >> 4) * signY));
        }
    }
    vs_battle_insertTpage(
        _get_mode(0, 0, getTPage(clut4Bit, semiTransparencyFull, 0, 0)), vs_scratch.unk8);
}

int func_800C1D84(void)
{
    int i;
    for (i = 0; i < 24; ++i) {
        if (D_800EB9B8->unk990[i].unk0 > 1) {
            return 0;
        }
    }
    return 1;
}

void func_800C1DC4(D_800EB9B8_unk990* arg0)
{
    int gradient = arg0->unk2;
    u_long* nextPrim = vs_scratch.unk8 - (arg0->unk1 * 4 - 8);
    int color0;
    int color1;
    int isLeft;
    int x;
    int y;
    int xy;
    int textXy;
    int color;
    labelBoxPrim_t* prim;

    if (arg0->unk1 != 0) {
        gradient = 8;
    }
    color0 = 8 - gradient;
    color0 = vs_battle_uiGradientStop(color0, arg0->unk7 * 8, 0x80);
    color1 = vs_battle_uiGradientStop(gradient, arg0->unk7 * 8, 0x80);

    xy = arg0->unk4;
    isLeft = xy < 160;
    if (isLeft) {
        y = color0;
        color0 = color1;
        color1 = y;
    }
    y = arg0->unk6 + D_800F4CB4;
    x = xy;
    if (isLeft) {
        x += 0x42;
    } else {
        x += 6;
    }
    color = 0x404040;
    textXy = vs_getXY_2(x, y - 1);
    if (arg0->unk1 != 0) {
        color = 0x808080;
    }
    vs_battle_renderTextRawColor(arg0->unk10, textXy, color, nextPrim);

    prim = vs_scratch.unk0;
    if (gradient != 0) {
        arg0->unk2 = gradient - 1;
    }
    x = arg0->unk4 & 0xFFFF;
    gradient = (arg0->unk4 < 160) * 2;
    prim->tag = vs_getTag(prim->box, *nextPrim);
    prim->box.tile.r0g0b0code = vs_getRGB0(primTile, 0, 0, 0);
    prim->box.tile.x0y0 = vs_getXY_2(x + 2 - gradient, y + 2);
    prim->box.tile.wh = (gradient + 0x48) | (8 << 16);
    prim->box.poly.tpage = _get_mode(0, 1, 0);
    prim->box.poly.r0g0b0code = vs_getRGB0Raw(primPolyG4, color0);
    prim->box.poly.x0y0 = x | (y << 16);
    prim->box.poly.r1g1b1 = color1;
    prim->box.poly.x1y1 = vs_getXY_2(x + 0x48, y);
    prim->box.poly.r2g2b2 = color0;
    prim->box.poly.x2y2 = x | ((y + 8) << 16);
    prim->box.poly.r3g3b3 = color1;
    prim->box.poly.x3y3 = vs_getXY_2(x + 0x48, y + 8);
    prim->box.tpage = _get_mode(0, 0, 0);
    *nextPrim = ((u_long)prim << 8) >> 8;
    ++prim;
    vs_scratch.unk0 = prim;

    if (arg0->unk1 != 0) {
        int sxy;
        int otz;
        int ringXy;

        y += 4;
        func_800C02A8();
        gte_ldv0(&arg0->unk8);
        gte_rtps2();
        gte_stsxy(&sxy);
        gte_stotz(&otz);
        if (arg0->unk4 < 160) {
            x = (x + 0x47) & 0xFFFF;
            ringXy = x | (y << 16);
            func_800C1A40(sxy, ringXy, arg0->unk3 - 2);
            if (arg0->unk3 >= 18) {
                func_800C1A40(sxy, ringXy, (arg0->unk3 + 14) & 0x1F);
            }
        } else {
            ringXy = x | (y << 16);
            func_800C16FC(sxy, ringXy, arg0->unk3 - 2);
            if (arg0->unk3 >= 18) {
                func_800C16FC(sxy, ringXy, (arg0->unk3 + 14) & 0x1F);
            }
        }
    }
}

void func_800C20B4(void)
{
    int temp_a0;
    int var_s3;
    int var_v1;
    D_800EB9B8_unk990* var_s1 = D_800EB9B8->unk990;
    short* var_s0 = &D_800EB9B8->unk990[0].unk4;

    for (var_s3 = 0; var_s3 < 24; ++var_s3, var_s0 += 10, ++var_s1) {
        int v1 = var_s1->unk0;

        if (v1 == 0) {
            continue;
        }

        switch (v1) {
        case 0:
            break;
        case 2:
            temp_a0 = *var_s0;

            if (temp_a0 >= 160) {
                for (var_v1 = 0; var_v1 < 16; ++var_v1) {
                    if ((vs_battle_rowAnimationSteps[var_v1] + 0xF8) >= temp_a0) {
                        break;
                    }
                }

                if (var_v1 != 0) {
                    *var_s0 = vs_battle_rowAnimationSteps[var_v1 - 1] + 0xF8;
                } else {
                    *var_s0 = 0xF8;
                    var_s1->unk0 = 1;
                }
            } else {
                *var_s0 = temp_a0 - 0x20;
            }
            break;

        case 3:
            temp_a0 = *var_s0;

            if (temp_a0 >= 0xA0) {
                *var_s0 = temp_a0 + 0x20;
            } else {
                for (var_v1 = 0; var_v1 < 16; ++var_v1) {
                    if ((temp_a0 + 4) >= -vs_battle_rowAnimationSteps[var_v1]) {
                        break;
                    }
                }

                if (var_v1 != 0) {
                    temp_a0 = -vs_battle_rowAnimationSteps[var_v1 - 1];
                } else {
                    temp_a0 = 0;
                    var_s1->unk0 = 1;
                }

                *var_s0 = temp_a0 - 4;
            }
            break;
        }

        if ((*var_s0 + 0x7E) < 0x1BEU) {
            func_800C1DC4(var_s1);
        } else {
            var_s1->unk0 = 0;
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C2254);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C2368);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C253C);

void* func_800C282C(void)
{
    _sphericalCamera camera;
    int temp_a0;
    int temp_s2;
    int yaw;
    short* p = (short*)0x1F800350;
    vs_battle_syncCameraAnglesFromPosition(&camera);
    yaw = camera.values.yaw;
    temp_s2 = rcos(yaw);
    temp_a0 = rsin(yaw);
    p[0] = temp_s2;
    p[2] = temp_a0;
    p[8] = -temp_a0;
    p[10] = temp_s2;
    D_800EB9B8->unk22 = yaw;
    return (void*)0x1F800350;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C28AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C2B0C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C2E24);

void func_800C4650(func_800C4650_t* arg0, int arg1)
{
    int i;
    int type;

    for (i = 0; i < arg1; i++, arg0++) {
        type = arg0->unk9;
        if ((type >> 4) == 0) {
            if (func_800C1564(&D_800EB9B8->unk0[1], arg0->unk0)) {
                func_8009FD5C(type, 0, arg0->unkA);
            } else {
                func_8009FE74(type, arg0->unkA);
            }
        }
    }
}

int vs_battle_mapStickDeadZone(int arg0)
{
    if (arg0 < 64) {
        return arg0 - 64;
    }
    if (arg0 >= 192) {
        return arg0 - 192;
    }
    return 0;
}

int func_800C4734(void)
{
    if ((D_800EB9B8 == NULL) || (D_800EB9B8->unk2A != 0)) {
        return 0;
    }
    if ((D_800EB9B8->unk3E == 0) || (vs_main_buttonsState & 0x80)) {
        return 1;
    }
    return 2;
}

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", D_80069860);
