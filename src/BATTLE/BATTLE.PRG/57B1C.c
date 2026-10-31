#include "common.h"
#include "57B1C.h"
#include "58578.h"
#include "battleUi.h"
#include "gpu.h"
#include "scratch.h"

extern u_char D_80040A14[];
extern u_char D_800EB9AC;

void func_800C031C(void)
{
    int index;
    int x;
    int y;
    short* edges;

    if (D_800EB9B8 == NULL) {
        D_800EB9B8 = vs_main_allocHeap(sizeof *D_800EB9B8);
    }

    vs_battle_rMemzero(D_800EB9B8, sizeof *D_800EB9B8);
    index = 0;
    D_800EB9B8->unk2D = -1;
    edges = D_800EB9B8->unk44B4;

    for (y = 0;; ++y) {
        for (x = 0; x < 9; ++x) {
            edges[index++] = x + (y << 4) + ((x + 1) << 8) + (y << 12);
        }

        if (y == 9) {
            break;
        }

        for (x = 0; x < 10; ++x) {
            edges[index++] = x + (y << 4) + (x << 8) + ((y + 1) << 12);
        }
    }

    for (x = 0;; ++x) {
        for (y = 9; y > 0; --y) {
            edges[index++] = x + (y << 4) + (x << 8) + ((y - 1) << 12);
        }

        if (x == 9) {
            break;
        }

        for (y = 9; y >= 0; --y) {
            edges[index++] = x + (y << 4) + ((x + 1) << 8) + (y << 12);
        }
    }

    for (y = 9;; --y) {
        for (x = 9; x > 0; --x) {
            edges[index++] = x + (y << 4) + ((x - 1) << 8) + (y << 12);
        }

        if (y == 0) {
            break;
        }

        for (x = 9; x >= 0; --x) {
            edges[index++] = x + (y << 4) + (x << 8) + ((y - 1) << 12);
        }
    }

    for (x = 9;; --x) {
        for (y = 0; y < 9; ++y) {
            edges[index++] = x + (y << 4) + (x << 8) + ((y + 1) << 12);
        }

        if (x == 0) {
            break;
        }

        for (y = 0; y < 10; ++y) {
            edges[index++] = x + (y << 4) + ((x - 1) << 8) + (y << 12);
        }
    }
}

void func_800C05B4(void)
{
    if (D_800EB9B8 != NULL) {
        vs_main_freeHeap(D_800EB9B8);
        D_800EB9B8 = NULL;
    }
}

void func_800C05EC(
    func_800C1564_t* arg0, func_800C1564_t* arg1, int arg2, D_800F19CC_t5* arg3)
{
    D_800EB9B8->unk0[0] = *arg0;

    if (arg0->unk0 != 1) {
        D_800EB9B8->unk24 = 0;
        D_800EB9B8->unk28 = 0;
    }

    if (D_800EB9AC != 0) {
        D_800EB9B8->unk0[0].unk0 |= 0x80;
        D_800EB9B8->unk0[1].unk0 = arg1->unk0;
        D_800EB9AC = 0;
        return;
    }

    ((VECTOR*)&D_800EB9B8->unk38)->vx = 0;
    ((VECTOR*)&D_800EB9B8->unk38)->vy = 0;
    D_800EB9B8->unk2A = 0xF;

    if (arg1 != NULL) {
        D_800EB9B8->unk0[1] = *arg1;
        D_800EB9B8->unk0[1].unk0 |= 0x80;
        D_800EB9B8->unk2E = arg2;
        D_800EB9B8->unk44 = arg3;
        return;
    }

    D_800EB9B8->unk0[1].unk0 = 0;
}

void func_800C06E0(void)
{
    if (D_800EB9B8 != NULL) {
        D_800EB9B8->unk0[0].unk0 = 0;
    }
}

void func_800C0700(func_800C1564_t* arg0)
{
    D_800EB9B8->unk0[1] = *arg0;
    D_800EB9B8->unk2A = 0;
}

void func_800C0738(void)
{
    if (D_800EB9B8 != NULL) {
        D_800EB9B8->unk0[1].unk0 = 0;
    }
}

int func_800C0758(int phase, int segments, int index)
{
    short* sine = (void*)0x1F8003B0;
    short (*basis)[4] = (void*)0x1F800398;
    int i;
    int component;
    menuShapeVertex* vertex = &D_800EB9B8->unk48[index];

    for (i = 0; i <= segments; ++index, ++i, ++vertex) {
        for (component = 0; component < 3; ++component) {
            vertex->xyz[component] =
                basis[0][component]
                + ((basis[1][component] * sine[(i + phase + 8) & 31]) >> 12)
                + ((basis[2][component] * sine[(i + phase) & 31]) >> 12);
        }

        component = i != 0;

        if (component && segments != 32) {
            component += segments - i < 2;
        }

        vertex->flags = component;
    }

    return index;
}

MATRIX* func_800C085C(u_char* scale, int angle)
{
    short* scratch = (void*)0x1F800350;
    MATRIX* rotation = (void*)0x1F800330;
    int axis;
    int component;

    scratch[0] = -(scale[3] * 16);
    scratch[1] = angle;
    scratch[2] = 0;
    RotMatrixYXZ_gte((SVECTOR*)scratch, rotation);

    for (axis = 0; axis < 3; ++axis) {
        for (component = 0; component < 3; ++component) {
            scratch[component] = axis == component ? scale[axis] * 32 : 0;
        }

        ApplyMatrixSV(rotation, (SVECTOR*)scratch, (SVECTOR*)&scratch[8 + axis * 4]);
    }

    for (axis = 0; axis < 3; ++axis) {
        for (component = 0; component < 3; ++component) {
            scratch[axis * 3 + component] = scratch[8 + component * 4 + axis];
        }
    }

    return (void*)scratch;
}

void func_800C0990(SVECTOR* start, SVECTOR* end, u_int color, int intensity)
{
    int depth = (start->vz + end->vz) >> 1;
    int dx;
    int dy;
    int ax;
    int ay;
    int angle;
    int shift;
    u_long link;
    u_long* primitive;
    u_long* orderingTable;

    if (depth >= 2048u) {
        return;
    }

    dy = end->vy - start->vy;
    dx = end->vx - start->vx;
    angle = 0;
    shift = dy | dx;

    if (shift) {
        ax = dx;
        ay = dy;

        if (ax < 0) {
            ax = -ax;
        }

        if (ay < 0) {
            ay = -ay;
        }

        shift = ONE / 8;

        if (ax < ay) {
            angle = ax << 9;
            angle /= ay;
            angle = D_80040A14[angle];
            angle = shift - angle;
        } else {
            angle = ay << 9;
            angle /= ax;
            angle = D_80040A14[angle];
        }

        shift = ONE / 4;

        if (ax != dx) {
            angle = shift - angle;
        }

        angle *= 2;

        if (ay != dy) {
            angle = -angle;
        }
    }

    shift = 30 - (((angle + 256) >> 8) & 14);
    ay = start->vx + ((0x4FC5 << shift) >> 30);
    ax = start->vy + ((0xFC54 << shift) >> 30);

    if (intensity < 0) {
        intensity = 0;
    } else if (intensity >= 64) {
        intensity = 63;
    }

    primitive = vs_scratch.unk0;
    orderingTable = vs_scratch.unk4;
    orderingTable += depth;
    link = *orderingTable & 0xFFFFFF;
    primitive[1] = _get_mode(0, 1, 0);
    primitive[3] = vs_getXY_2(ay, ax);
    primitive[0] = link | 0x04000000;
    primitive[2] = (((color << 8) >> 8) * intensity) | ((color >> 24) << 24);
    primitive[4] = *(u_long*)end;
    *orderingTable = ((u_long)primitive << 8) >> 8;
    vs_scratch.unk0 = primitive + 5;
}
