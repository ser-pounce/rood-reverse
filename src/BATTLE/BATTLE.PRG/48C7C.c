#include "common.h"
#include "48C7C.h"
#include "44F14.h"
#include "src/SLUS_010.40/memory.h"

#ifdef NON_MATCHING

void func_800B147C(
    D_800F4538_unkC54* dst, D_800F4538_unkC54* src, int count, int step, int total)
{
    int ratio;
    int previousZ;
    int i;

    if (step == total) {
        vs_main_memcpy(dst, src, 0x60C);
        return;
    }

    if (step == total >> 1) {
        func_800AE980(dst, src, count);
        return;
    }

    ratio = step * ONE / total;

    previousZ = (src->unk148.vz - dst->unk148.vz) * ratio >> 12;
    dst->unk148.vx += (src->unk148.vx - dst->unk148.vx) * ratio >> 12;
    dst->unk148.vy += (src->unk148.vy - dst->unk148.vy) * ratio >> 12;
    dst->unk148.vz += previousZ;

    for (i = 0; i < count; ++i) {
        int deltaX = src->unk0[i].vx - dst->unk0[i].vx;
        int deltaY;
        int deltaZ;

        if (deltaX >= ONE) {
            deltaX -= ONE * 2;
        } else if (deltaX < -ONE) {
            deltaX += ONE * 2;
        }

        deltaY = src->unk0[i].vy - dst->unk0[i].vy;

        if (deltaY >= ONE) {
            deltaY -= ONE * 2;
        } else if (deltaY < -ONE) {
            deltaY += ONE * 2;
        }

        deltaZ = src->unk0[i].vz - dst->unk0[i].vz;

        if (deltaZ >= ONE) {
            deltaZ -= ONE * 2;
        } else if (deltaZ < -ONE) {
            deltaZ += ONE * 2;
        }

        if ((deltaZ == 0) && ((deltaX != 0) || (deltaY != 0))) {
            deltaZ = previousZ;
        }

        dst->unk0[i].vx += deltaX * ratio >> 12;
        dst->unk0[i].vy += deltaY * ratio >> 12;
        dst->unk0[i].vz += deltaZ * ratio >> 12;

        previousZ = (src->unk150[i].vz - dst->unk150[i].vz) * ratio >> 12;
        dst->unk150[i].vx += (src->unk150[i].vx - dst->unk150[i].vx) * ratio >> 12;
        dst->unk150[i].vy += (src->unk150[i].vy - dst->unk150[i].vy) * ratio >> 12;
        dst->unk150[i].vz += previousZ;
    }
}

MATRIX* func_800B17F0(SVECTOR* rotation, MATRIX* m)
{
    int sinX = rsin(rotation->vx);
    int cosX = rcos(rotation->vx);
    int sinY = rsin(rotation->vy);
    int cosY = rcos(rotation->vy);
    int sinZ = rsin(rotation->vz);
    int cosZ = rcos(rotation->vz);
    int sinZsinX = sinZ * sinX >> 10;
    int sinZcosX = sinZ * cosX >> 10;
    int cosZsinX = cosZ * sinX >> 10;
    int cosZcosX = cosZ * cosX >> 10;

    m->m[0][0] = cosZ * cosY >> 12;
    m->m[0][1] = ((sinY * cosZsinX >> 12) - sinZcosX) >> 2;
    m->m[0][2] = ((sinY * cosZcosX >> 12) + sinZsinX) >> 2;
    m->m[1][0] = sinZ * cosY >> 12;
    m->m[1][1] = ((sinY * sinZsinX >> 12) + cosZcosX) >> 2;
    m->m[1][2] = ((sinY * sinZcosX >> 12) - cosZsinX) >> 2;
    m->m[2][0] = -sinY;
    m->m[2][1] = cosY * sinX >> 12;
    m->m[2][2] = cosY * cosX >> 12;
    return m;
}

MATRIX* func_800B196C(MATRIX* m0, MATRIX* m1)
{
    short product[3][3];
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            product[i][j] = (m0->m[i][0] * m1->m[0][j] + m0->m[i][1] * m1->m[1][j]
                                + m0->m[i][2] * m1->m[2][j])
                         >> 12;
        }
    }

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            m1->m[i][j] = product[i][j];
        }
    }

    return m1;
}

#endif
