#include "common.h"
#include "146C.h"
#include "30DB0.h"
#include "58578.h"
#include "573B8.h"
#include "5BF94.h"
#include "../../SLUS_010.40/main.h"
#include <stddef.h>
#include <inline_c.h>
#include "vs_inline_c.h"

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
    short unk24;
    short unk26;
    short unk28;
    short unk2A;
    char unk2C;
    char unk2D;
    char unk2E;
    char unk2F;
    char unk30;
    char unk31;
    short unk32;
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

int func_800C1034(func_800C1564_t* arg0, u_short* arg1);
int func_800C123C(func_800C1564_t* arg0, u_short* arg1, int arg2);
int func_800C1384(func_800C1564_t* arg0, u_short* arg1, int arg2);
void func_800C1DC4(D_800EB9B8_unk990* arg0);
void func_800C20B4(void);
void func_800C253C(int type);
void func_800C02A8(void);
MATRIX* func_800C085C(u_char* scale, int angle);
void func_800C0B50(func_800C1564_t* shape, int color);
int func_800C0758(int phase, int segments, int index);
int func_800C2368(int step, int radius, int index);

extern short D_800EA234[];
extern short D_800EA2C4[];
extern u_char D_800EA438[];
extern u_short D_800EA46C[];
extern int D_800EA670[];
extern int D_800EA684[];
extern int D_800EA698[];
extern u_char D_800EA6AC;

extern D_800EB9B8_t* D_800EB9B8;

void func_800C0D78(void)
{
    func_800C1564_t* shape = (func_800C1564_t*)0x1F800378;
    int color = 0x10401;
    short* sine;
    MATRIX* m;
    int type;
    int i;
    int j;

    if (D_800EB9B8 == NULL) {
        return;
    }

    sine = (short*)0x1F8003B0;
    for (i = 0; i < 40; ++i) {
        sine[i] = rsin(i << 7);
    }

    for (i = 0; i < 2; color = 0x10104, ++shape, ++i) {
        *shape = D_800EB9B8->unk0[i];
        func_800C02A8();
        gte_ldv0(&shape->unk8);
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
                (&shape->unk8.vx)[j] += m->m[j][1] >> 1;
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
                (&shape->unk8.vx)[j] += m->m[j][1];
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
        arg1->unk10[i] = (&arg0->unk8.vx)[i];
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
        SVECTOR local;
        SVECTOR rotated;
        short origin[4];
    } work;
    MATRIX matrix;
    int i, x, z, offsetX, offsetZ;
    short* ptr;
    void* base;
    int offset;

    work.origin[0] = shape->unk8.vx;
    work.origin[1] = shape->unk8.vy;
    work.origin[2] = shape->unk8.vz;
    work.local.vx = shape->unk4.values[3] << 4;
    work.local.vy = -shape->unk2;
    work.local.vz = 0;
    ptr = (short*)&work;
    RotMatrix_gte(&work.local, &matrix);
    i = 0;
    base = &work;
    offset = 16;
    do {
        *ptr = *position++ - *(u_short*)(base + offset);
        offset += 2;
        ++i;
        ++ptr;
    } while (i < 3);
    ApplyMatrixSV(&matrix, &work.local, &work.rotated);
    if ((u_short)-work.rotated.vy > (shape->unk4.values[1] << 5)) {
        return 0;
    }
    x = shape->unk4.values[0] << 5;
    z = shape->unk4.values[2] << 5;
    if (angled) {
        offsetZ = z;
        offsetX = -x;
    } else {
        offsetZ = 0;
        offsetX = offsetZ;
    }
    i = 0;
    polygon.corners[0] = (u_short)-x | (-offsetZ << 16);
    polygon.corners[1] = -offsetX | (-z << 16);
    polygon.corners[2] = x | (offsetZ << 16);
    polygon.corners[3] = (u_short)offsetX | (z << 16);
    polygon.corners[4] = (u_short)work.rotated.vx | (work.rotated.vz << 16);
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
    int y1;
    int midX;
    int signY;
    int signX;
    int length;
    int dx;
    int i;
    int level;
    int color;
    int gray;
    int start;
    int end;
    int tail;
    int near2;
    int far2;
    int y1Bits;
    int lineColor;
    int segmentEnd;
    int segmentStart;

    signX = signY = 1;
    y1 = x1 >> 16;
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
        level = i - count + 16;
        if (count < i || level < 0) {
            continue;
        }
        gray = ((level * 3) << 6) >> 4;
        gray |= gray << 8;
        color = gray | (((level * 255 + (16 - level) * 32) >> 4) << 16);
        start = segmentStart >> 4;
        if (start < dx) {
            end = segmentEnd >> 4;
            if (end < dx) {
                vs_battle_addTile(vs_scratch.unk8, color | 0x42000000,
                    ((x1 - start * signX) & 0xFFFF) | y1Bits,
                    ((x1 - (end - 1) * signX) & 0xFFFF) | y1Bits);
            } else {
                lineColor = color | 0x42000000;
                vs_battle_addTile(vs_scratch.unk8, lineColor,
                    ((x1 - start * signX) & 0xFFFF) | y1Bits,
                    ((midX + signX) & 0xFFFF) | y1Bits);
                tail = length * (15 - i);
                if (y1 != y0 - (tail >> 4) * signY) {
                    vs_battle_addTile(vs_scratch.unk8, lineColor,
                        (midX & 0xFFFF) | y1Bits,
                        ((x0 + (tail >> 5)) & 0xFFFF)
                            | ((y0 - ((tail + 16) >> 4) * signY) << 16));
                }
            }
        } else {
            far2 = length * (16 - i);
            near2 = length * (15 - i);
            vs_battle_addTile(vs_scratch.unk8, color | 0x42000000,
                ((x0 + (far2 >> 5)) & 0xFFFF) | ((y0 - (far2 >> 4) * signY) << 16),
                ((x0 + (near2 >> 5)) & 0xFFFF)
                    | ((y0 - ((near2 + 16) >> 4) * signY) << 16));
        }
    }
    vs_battle_insertTpage(0xE1000020, vs_scratch.unk8);
}

void func_800C1A40(int x0, int x1, int count)
{
    int y0;
    int y1;
    int midX;
    int signY;
    int signX;
    int length;
    int dx;
    int i;
    int level;
    int color;
    int gray;
    int start;
    int end;
    int tail;
    int near2;
    int far2;
    int y1Bits;
    int lineColor;
    int segmentEnd;
    int segmentStart;

    signX = signY = 1;
    y1 = x1 >> 16;
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
        level = i - count + 16;
        if (count < i || level < 0) {
            continue;
        }
        gray = ((level * 3) << 6) >> 4;
        gray |= gray << 8;
        color = gray | (((level * 255 + (16 - level) * 32) >> 4) << 16);
        start = segmentStart >> 4;
        if (start < dx) {
            end = segmentEnd >> 4;
            if (end < dx) {
                vs_battle_addTile(vs_scratch.unk8, color | 0x42000000,
                    ((x1 + start * signX) & 0xFFFF) | y1Bits,
                    ((x1 + (end - 1) * signX) & 0xFFFF) | y1Bits);
            } else {
                lineColor = color | 0x42000000;
                vs_battle_addTile(vs_scratch.unk8, lineColor,
                    ((x1 + start * signX) & 0xFFFF) | y1Bits,
                    ((midX - signX) & 0xFFFF) | y1Bits);
                tail = length * (15 - i);
                if (y1 != y0 - (tail >> 4) * signY) {
                    vs_battle_addTile(vs_scratch.unk8, lineColor,
                        (midX & 0xFFFF) | y1Bits,
                        ((x0 - (tail >> 5)) & 0xFFFF)
                            | ((y0 - ((tail + 16) >> 4) * signY) << 16));
                }
            }
        } else {
            far2 = length * (16 - i);
            near2 = length * (15 - i);
            vs_battle_addTile(vs_scratch.unk8, color | 0x42000000,
                ((x0 - (far2 >> 5)) & 0xFFFF) | ((y0 - (far2 >> 4) * signY) << 16),
                ((x0 - (near2 >> 5)) & 0xFFFF)
                    | ((y0 - ((near2 + 16) >> 4) * signY) << 16));
        }
    }
    vs_battle_insertTpage(0xE1000020, vs_scratch.unk8);
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/58578", func_800C1DC4);

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

typedef struct {
    short xyz[3], flags;
} menuCircleVertex;
int func_800C2254(int angle, int index)
{
    short (*basis)[3] = (void*)0x1F800398;
    int point = 0, component;
    int phase = angle;
    menuCircleVertex* vertex = (void*)((char*)D_800EB9B8 + (index * 8 + 0x48));
    int cosine, sine;
    for (; point < 33; ++index, phase += 128, ++point, ++vertex) {
        for (component = 0; component < 3; ++component) {
            cosine = rcos(phase);
            sine = rsin(phase);
            vertex->xyz[component] = basis[0][component]
                                   + ((basis[1][component] * cosine) >> 12)
                                   + ((basis[2][component] * sine) >> 12);
        }
        component = point != 0;
        vertex->flags = component;
    }
    return index;
}

int func_800C2368(int step, int radius, int index)
{
    short* basis = (short*)0x1F800398;
    int base;
    int point;
    int phase;
    int i;
    int x, y, z;
    menuCircleVertex* vertex = (void*)((char*)D_800EB9B8 + (index * 8 + 0x48));

    for (base = 0; base < 0x1000; base += 0x400) {
        z = y = x = 0;
        phase = base - step * 4;
        for (point = 0; point <= radius; ++index, ++point, phase += step, ++vertex) {
            vertex->xyz[0] = (x * rcos(phase)) >> 12;
            vertex->xyz[1] = y;
            vertex->xyz[2] = (z * rsin(phase)) >> 12;
            i = point != 0;
            vertex->flags = i;
            x += 0x200;
            y -= 0x200;
            z += 0x200;
        }
    }
    radius <<= 9;
    for (i = 8; i >= 0; --i) {
        basis[i] = 0;
    }
    basis[1] = -radius;
    basis[3] = radius;
    basis[8] = radius;
    index = func_800C2254(step * 7, index);
    if (radius >= 5) {
        basis[1] = -0x800;
        basis[3] = 0x800;
        basis[8] = 0x800;
        index = func_800C2254(step * 4, index);
    }
    return index;
}

void func_800C253C(int type)
{
    short* basis = (short*)0x1F800398;
    int index = 0;
    int shape;
    int count;
    int command;
    int i;
    int j;
    int n;
    short* src;
    u_short* commands;
    menuCircleVertex* vertices;
    menuCircleVertex* vertex;

    shape = D_800EB9B8->unk2A;
    vertices = (menuCircleVertex*)((char*)D_800EB9B8 + 0x48);
    if (shape != 0) {
        D_800EB9B8->unk2A = shape - 1;
    }
    if ((u_int)type < 3) {
        if (type == 0) {
            D_800EB9B8->unk24 += (shape + 1) * 3;
            D_800EB9B8->unk28 += (shape + 1) * 11;
        }
        D_800EB9B8->unk26 += (shape * 2 + 1) * 7;
        shape += type * 16;
    } else {
        shape = type + 0x2D;
    }

    command = D_800EA438[shape];
    commands = &D_800EA46C[command];
    count = D_800EA438[shape + 1] - command;

    for (; count > 0; --count) {
        command = *commands++;
        switch ((command >> 14) & 3) {
        case 0:
            src = &D_800EA234[(command << 2) & 0x7C];
            for (i = 0; i < 3; ++i) {
                basis[i] = *src++;
            }
            for (i = 4; i < 11; ++i) {
                basis[i] = 0;
            }
            j = (command >> 3) & 0x1C;
            i = *src;
            basis[(0x546465 >> j) & 0xF] = i;
            basis[(0x8A998A >> j) & 0xF] = i;
            i = (command >> 9) & 0x1C;
            if (i == 0) {
                i = 0x20;
            }
            index = func_800C0758((command >> 6) & 0x1C, i, index);
            break;
        case 1:
            index = func_800C2368(command & 0x3FF, ((command >> 10) & 7) + 1, index);
            break;
        case 2:
            src = &D_800EA2C4[command & 0x3FF];
            command = ((command >> 10) & 7) + 2;
            for (j = 0; j < 2; ++j) {
                for (i = command; i > 0; --i) {
                    vertices[index].xyz[0] = src[0];
                    src[0] = -vertices[index].xyz[0];
                    vertices[index].xyz[1] = src[1];
                    vertices[index].xyz[2] = src[2];
                    src[2] = -vertices[index].xyz[2];
                    vertices[index].flags = 1;
                    ++index;
                    src += 3;
                }
                vertices[index - command].flags = 0;
                src -= command * 3;
            }
            break;
        }
    }
    D_800EB9B8->unk32 = index;
}

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

void func_800C28AC(SVECTOR* position, int arg1)
{
    int xy;
    int i;
    int index;
    int brightness;
    u_long* prim;
    u_long* ot = vs_scratch.unk4 - 4;

    gte_ldv0(position);
    gte_rtps2();
    gte_stsxy(&xy);

    D_800EA6AC = (D_800EA6AC + 1) & 0xF;

    if (arg1 == 0) {
        prim = vs_scratch.unk0;
        prim[0] = (*ot & 0xFFFFFF) | 0x9000000;
        prim[1] = 0x2C808080;
        prim[2] = xy + 0xFFF7FFF3;
        prim[3] = 0x37FD38F1;
        prim[4] = xy + 0xFFF7FFFD;
        prim[5] = 0xC38E7;
        prim[6] = xy + 0xFFFEFFF3;
        prim[7] = 0x3FF1;
        prim[8] = xy + 0xFFFEFFFD;
        prim[9] = 0x3FE7;
        *ot = (u_long)prim;
        prim += 10;
        prim[0] = (*ot & 0xFFFFFF) | 0x9000000;
        prim[1] = 0x2C808080;
        prim[2] = xy + 0x1FFF3;
        prim[3] = 0x37FD40F1;
        prim[4] = xy + 0x1FFFD;
        prim[5] = 0xC40E7;
        prim[6] = xy + 0x8FFF3;
        prim[7] = 0x47F1;
        prim[8] = xy + 0x8FFFD;
        prim[9] = 0x47E7;
        *ot = (u_long)prim;
        prim += 10;
        vs_scratch.unk0 = prim;
    }

    for (i = 0; i < 3; ++i) {
        index = i + arg1 * 2;
        prim = vs_battle_setSpriteDefaultTexPage(
            index == 2 ? vs_battle_cursorBrightnessAnimation[D_800EA6AC] : 0x80,
            xy + D_800EA670[index], D_800EA684[index], ot);
        prim[4] = D_800EA698[index];
    }
}

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
