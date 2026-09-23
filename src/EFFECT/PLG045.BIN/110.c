#include "common.h"
#include "src/SLUS_010.40/32154.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/BATTLE/BATTLE.PRG/6E644.h"
#include "vs_inline_c.h"
#include <rand.h>
#include <inline_c.h>

typedef struct {
    short unk0;
    short unk2;
} func_800FA098_arg3_2;

typedef struct {
    u_char unk0;
    u_char unk1;
    short unk2;
    SVECTOR* unk4;
    int unk8;
    int unkC;
    func_800D6CF_t unk10;
    func_800FA098_arg3_2* unk2C;
} func_800FA098_arg3;

extern int D_800FB5B4;

void func_800FA760(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA098_arg3*);

void func_800F9910(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1, D_800F53B8_t* arg2,
    func_800FA098_arg3* arg3)
{
    int sp10;
    SVECTOR* temp_s1;
    int temp_a1;
    int temp_lo;
    int temp_s0_2;
    int temp_s3;
    int temp_v0;
    int temp_v0_4;
    int var_fp;
    int i;
    u_short var_a0_2;
    u_short var_v1;
    u_short var_v1_2;
    MATRIX* temp_s0;

    vs_battle_lerpVector(
        (short*)arg0->unk18, func_800D118C(arg0->unk8, arg3->unkC), &arg1->unk98);
    temp_s0 = &arg2->unk1C[arg0->unkC8].unk38;

    switch (arg1->unk24 & 7) {
    case 0:
        break;
    case 1:
        vs_battle_addVecToSvec(&arg1->unk98, D_800F5310, &arg1->unk98);
        break;
    case 2:
        arg1->unk98.vx += temp_s0->t[0];
        arg1->unk98.vy += temp_s0->t[1];
        arg1->unk98.vz += temp_s0->t[2];
        break;
    }

    vs_battle_lerpVector(
        (short*)&arg0->unk18[0xC], func_800D118C(arg0->unk9, arg3->unkC), &arg1->unkA8);
    SetRotMatrix(temp_s0);
    gte_zrtr();

    switch (arg1->unk24 & 0x38) {
    case 0:
        for (i = 0; i < arg3->unk2; ++i) {

            temp_s1 = arg3->unk4 + (i * 4);

            temp_v0 = rand();
            arg1->unk170 = rsin(temp_v0);
            arg1->unk178 = rcos(temp_v0);

            temp_v0 = rand();
            arg1->unk174 = rsin(temp_v0);
            arg1->unk17C = rcos(temp_v0);

            temp_s1->vx =
                (((arg1->unkA8.vx * arg1->unk178) >> 0xC) * arg1->unk17C) >> 0xC;
            temp_s1->vy =
                (((arg1->unkA8.vy * arg1->unk178) >> 0xC) * arg1->unk174) >> 0xC;
            temp_s1->vz = (arg1->unkA8.vz * arg1->unk170) >> 0xC;

            if (arg1->unk24 & 0x40000) {
                ApplyRotMatrix(temp_s1, &arg1->unk34);
                temp_s1->vx = arg1->unk34.vx;
                temp_s1->vy = arg1->unk34.vy;
                temp_s1->vz = arg1->unk34.vz;
            }

            temp_s1->vx += arg1->unk98.vx;
            temp_s1->vy += arg1->unk98.vy;
            temp_s1->vz += arg1->unk98.vz;
        }
        return;

    case 8:
        for (i = 0; i < arg3->unk2; ++i) {

            temp_s1 = arg3->unk4 + i * 4;

            switch (arg1->unk24 & 0x1800) {
            case 0x0:
            case 0x800:
                switch (rand() % 6) {
                case 0:
                    temp_s1->vx = arg1->unkA8.vx;
                    goto jump1;

                case 1:
                    temp_s1->vx = -arg1->unkA8.vx;
                jump1:
                    temp_s1->vy = func_800CFB80(arg1->unkA8.vy, -arg1->unkA8.vy);
                    temp_s1->vz = func_800CFB80(arg1->unkA8.vz, -arg1->unkA8.vz);
                    break;

                case 2:
                    temp_s1->vy = arg1->unkA8.vy;
                    goto jump2;

                case 3:
                    temp_s1->vy = -arg1->unkA8.vy;
                jump2:
                    temp_s1->vx = func_800CFB80(arg1->unkA8.vx, -arg1->unkA8.vx);
                    temp_s1->vz = func_800CFB80(arg1->unkA8.vz, -arg1->unkA8.vz);
                    break;

                case 4:
                    temp_s1->vz = arg1->unkA8.vz;
                    goto jump3;

                case 5:
                    temp_s1->vz = -arg1->unkA8.vz;
                jump3:
                    temp_s1->vx = func_800CFB80(arg1->unkA8.vx, -arg1->unkA8.vx);
                    temp_s1->vy = func_800CFB80(arg1->unkA8.vy, -arg1->unkA8.vy);
                    break;
                }
                break;

            case 0x1000:
                temp_a1 = D_800FB5B4 + 1;
                D_800FB5B4 = temp_a1 & 7;

                var_a0_2 = arg1->unkA8.vx;
                if (!(D_800FB5B4 & 1)) {
                    var_a0_2 = -var_a0_2;
                }
                temp_s1->vx = var_a0_2;

                var_v1 = arg1->unkA8.vy;
                if (!(D_800FB5B4 & 2)) {
                    var_v1 = -var_v1;
                }
                temp_s1->vy = var_v1;

                var_v1_2 = arg1->unkA8.vz;
                if (!(D_800FB5B4 & 4)) {
                    var_v1_2 = -var_v1_2;
                }
                temp_s1->vz = var_v1_2;

                break;
            }

            if (arg1->unk24 & 0x40000) {
                ApplyRotMatrix(temp_s1, &arg1->unk34);
                temp_s1->vx = arg1->unk34.vx;
                temp_s1->vy = arg1->unk34.vy;
                temp_s1->vz = arg1->unk34.vz;
            }

            temp_s1->vx = temp_s1->vx + arg1->unk98.vx;
            temp_s1->vy = temp_s1->vy + arg1->unk98.vy;
            temp_s1->vz = temp_s1->vz + arg1->unk98.vz;
        }
        return;

    case 16:
    case 24:
    case 32:
    case 40:
        arg1->unk184 = 4;
        arg1->unk188 = 4;
        break;

    case 48:
        arg1->unk184 = arg0->unkCA;

        if (arg1->unk184 == 0) {
            arg1->unk184 = 1;
        }

        arg1->unk188 = arg0->unkCB;

        if (arg1->unk188 == 0) {
            arg1->unk188 = arg1->unk184;
        }
        break;

    default:
        return;
    }

    temp_lo = 0x1000 / arg1->unk184;

    if ((arg1->unk24 & 0x1800) != 0x1000) {
        D_800FB5B4 %= arg1->unk188;
        temp_s0_2 = (D_800FB5B4 * temp_lo) + 0x200;
        sp10 = (rcos(temp_s0_2) * arg1->unkA8.vx) >> 0xC;
        var_fp = (rsin(temp_s0_2) * arg1->unkA8.vz) >> 0xC;
    }

    for (i = 0; i < arg3->unk2; ++i) {
        temp_s1 = arg3->unk4 + (i * 4);
        D_800FB5B4 = (D_800FB5B4 + 1) % arg1->unk188;
        temp_s0_2 = (D_800FB5B4 * temp_lo) + 0x200;
        temp_s3 = (rcos(temp_s0_2) * arg1->unkA8.vx) >> 0xC;
        temp_s0_2 = (rsin(temp_s0_2) * arg1->unkA8.vz) >> 0xC;

        if ((arg1->unk24 & 0x1800) == 0x1000) {
            temp_s1->vx = temp_s3;
            temp_s1->vz = temp_s0_2;
        } else {
            temp_v0_4 = rand() >> 3;
            temp_s1->vx = (((temp_s3 - sp10) * temp_v0_4) >> 0xC) + sp10;
            temp_s1->vz = (((temp_s0_2 - var_fp) * temp_v0_4) >> 0xC) + var_fp;
        }

        temp_s1->vy = 0;

        if (arg1->unk24 & 0x40000) {
            ApplyRotMatrix(temp_s1, &arg1->unk34);
            temp_s1->vx = arg1->unk34.vx;
            temp_s1->vy = arg1->unk34.vy;
            temp_s1->vz = arg1->unk34.vz;
        }
        temp_s1->vx += arg1->unk98.vx;
        temp_s1->vy += arg1->unk98.vy;
        temp_s1->vz += arg1->unk98.vz;
    }
}

void func_800FA098(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1, D_800F53B8_t* arg2,
    func_800FA098_arg3* arg3)
{
    int i;

    vs_battle_lerpSvector(
        arg0->unk34[6], func_800D118C(arg0->unkF, arg3->unkC), &arg1->unk13C);
    vs_battle_lerpSvector(
        arg0->unk34[7], func_800D118C(arg0->unk10, arg3->unkC), &arg1->unk144);

    switch (arg1->unk24 & 0x1C0) {
    case 0xC0:
        arg1->unk13C.vx += arg2->unk1C[arg0->unkC9].unk38.t[0];
        arg1->unk13C.vy += arg2->unk1C[arg0->unkC9].unk38.t[1];
        arg1->unk13C.vz += arg2->unk1C[arg0->unkC9].unk38.t[2];
        break;
    case 0x80:
        arg1->unk13C.vx += D_800F5230.unkE0.vx;
        arg1->unk13C.vy += D_800F5230.unkE0.vy;
        arg1->unk13C.vz += D_800F5230.unkE0.vz;
        break;
    case 0:
        break;
    }

    for (i = 0; i < arg3->unk2; ++i) {
        SVECTOR* temp_s0 = &arg3->unk4[i * 4 + 3];
        temp_s0->vx = arg1->unk13C.vx + func_800CFB80(arg1->unk144.vx, -arg1->unk144.vx);
        temp_s0->vy = arg1->unk13C.vy + func_800CFB80(arg1->unk144.vy, -arg1->unk144.vy);
        temp_s0->vz = arg1->unk13C.vz + func_800CFB80(arg1->unk144.vz, -arg1->unk144.vz);
    }
}

void func_800FA2B0(func_800FA098_arg0* arg0, func_800FA098_arg1* arg1, D_800F53B8_t* arg2,
    func_800FA098_arg3* arg3)
{
    SVECTOR sp10;
    SVECTOR sp18;
    int i;
    int temp_s0;
    int var_s0;
    int var_s1;
    int var_s3;
    int var_s4;

    for (i = 0; i < arg3->unk2; ++i) {

        SVECTOR* temp_s5 = &arg3->unk4[i * 4];

        arg1->unk34.vx = temp_s5[3].vx - temp_s5[0].vx;
        arg1->unk34.vy = temp_s5[3].vy - temp_s5[0].vy;
        arg1->unk34.vz = temp_s5[3].vz - temp_s5[0].vz;

        temp_s0 = vs_gte_rsqrt((arg1->unk34.vx * arg1->unk34.vx)
                               + (arg1->unk34.vy * arg1->unk34.vy)
                               + (arg1->unk34.vz * arg1->unk34.vz));

        vs_battle_lerp2DVector(
            arg0->unk94[0], func_800D118C(arg0->unk12, arg3->unkC), arg1->unk124);
        vs_battle_lerp2DVector(
            arg0->unk94[1], func_800D118C(arg0->unk13, arg3->unkC), arg1->unk12C);
        vs_battle_lerp2DVector(
            arg0->unk94[2], func_800D118C(arg0->unkC, arg3->unkC), arg1->unk118);
        vs_battle_lerpVector(
            arg0->unk34[1], func_800D118C(arg0->unkB, arg3->unkC), &arg1->unkC8);
        vs_battle_lerpVector(
            arg0->unk34[0], func_800D118C(arg0->unkA, arg3->unkC), &arg1->unkE8);
        vs_battle_lerpSvector(
            arg0->unk34[2], func_800D118C(arg0->unkD, arg3->unkC), &arg1->unkF8);

        if (arg1->unkF8.vx != 0) {
            int var_v0_2 =
                (arg1->unk118[0] + (rand() % arg1->unkF8.vx)) - (arg1->unkF8.vx / 2);
            if (&arg1->unk34) {
                sp10.vz = (temp_s0 * var_v0_2) / 256;
            } else {
                sp10.vz = (temp_s0 * var_v0_2) / 256;
            }
        } else {
            sp10.vz = (temp_s0 * arg1->unk118[0]) / 256;
        }

        if (arg1->unkF8.vy != 0) {
            int var_v0_3 =
                (arg1->unk118[1] + (rand() % arg1->unkF8.vy)) - (arg1->unkF8.vy / 2);
            sp18.vz = temp_s0 + ((temp_s0 * var_v0_3) / 256);
        } else {
            sp18.vz = temp_s0 + ((temp_s0 * arg1->unk118[1]) / 256);
        }

        var_s3 = arg1->unk124[0];

        if (arg1->unk124[1] != 0) {
            var_s3 += rand() % arg1->unk124[1];
        }

        var_s4 = arg1->unk12C[0];

        if (arg1->unk12C[1] != 0) {
            var_s4 += rand() % arg1->unk12C[1];
        }

        var_s0 = arg1->unkE8.vx;

        if (arg1->unkC8.vx != 0) {
            var_s0 += (rand() % (arg1->unkC8.vx * 2)) - arg1->unkC8.vx;
        }

        var_s1 = arg1->unkE8.vy;

        if (arg1->unkC8.vy != 0) {
            var_s1 += (rand() % (arg1->unkC8.vy * 2)) - arg1->unkC8.vy;
        }

        sp10.vx = (rcos(var_s0) * var_s3) >> 0xC;
        sp10.vy = (rsin(var_s0) * var_s3) >> 0xC;
        sp18.vx = (rcos(var_s1) * var_s4) >> 0xC;
        sp18.vy = (rsin(var_s1) * var_s4) >> 0xC;

        vs_battle_svecToVec(temp_s5, &arg1->unk34);
        vs_battle_svecToVec(temp_s5 + 3, &arg1->unk44);
        vs_battle_lookAt(&arg1->unk34, &arg1->unk44, &arg1->unk64);
        gte_SetRotMatrix(&arg1->unk64);
        gte_SetTransVector2(&arg1->unk34);
        gte_ldv0(&sp10);
        gte_rtv0tr2();
        gte_stlvnl(&arg1->unk34);
        vs_battle_vecToSvec(&arg1->unk34, temp_s5 + 1);
        gte_ldv0(&sp18);
        gte_rtv0tr2();
        gte_stlvnl(&arg1->unk44);
        vs_battle_vecToSvec(&arg1->unk44, temp_s5 + 2);
    }
}

INCLUDE_ASM("build/src/EFFECT/PLG045.BIN/nonmatchings/110", func_800FA760);

int func_800FB320(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    func_800FA098_arg0* temp_s2;
    int var_a0;
    short var_v0;
    func_800FA098_arg1* a2 = (func_800FA098_arg1*)0x1F8001D0;
    func_800FA098_arg3* temp_s1 = arg0->unk8;
    D_800F53B8_t* temp_s0 = D_800F53BC;
    int s3 = 1;

    switch (arg1) {
    case 1:
        temp_s1 = vs_main_allocHeapR(0x30);
        arg0->unk8 = temp_s1;
        temp_s1->unk1 = arg2 >> 8;
        temp_s1->unk0 = arg2;
        temp_s1->unkC = 0;
        temp_s1->unk8 = 0;
        temp_s2 = &D_800F569C->block5Data->unk4[temp_s1->unk1];

        var_v0 = temp_s2->unkC0[1];
        if (temp_s2->unkC0[1] < temp_s2->unkC0[0]) {
            var_v0 = temp_s2->unkC0[0];
        }

        var_a0 = var_v0;

        if (var_a0 >= 9) {
            var_a0 = 8;
        }

        temp_s1->unk4 = vs_main_allocHeapR(var_a0 << 5);
        func_800D6CCC((int*)(&temp_s1->unk10));
        func_800D6CF0(&temp_s1->unk10, temp_s2->unk1, temp_s2->unk0);
        break;

    case 2:
        temp_s2 = &D_800F569C->block5Data->unk4[temp_s1->unk1];
        a2->unk24 = temp_s2->unk4_0;
        temp_s1->unk2 =
            func_800CFE1C(temp_s2->unkC0, func_800D118C(temp_s2->unk16, temp_s1->unkC));

        if (temp_s1->unk2 >= 9) {
            temp_s1->unk2 = 8;
        }

        if (temp_s1->unk8 <= 0) {
            func_800F9910(temp_s2, a2, temp_s0, temp_s1);
            func_800FA098(temp_s2, a2, temp_s0, temp_s1);
            temp_s1->unk8 = temp_s2->unk34[5][2];
        }

        temp_s1->unk8 = (temp_s1->unk8 - 1);

        func_800FA2B0(temp_s2, a2, temp_s0, temp_s1);
        func_800FA760(temp_s2, a2, temp_s0, temp_s1);

        ++temp_s1->unkC;

        if (temp_s1->unk0 != 0) {
            --temp_s1->unk0;
            if (!temp_s1->unk0) {
                vs_main_freeHeapR(temp_s1->unk4);
                s3 = 0;
            }
        }
        break;

    case 3:
        temp_s1->unk0 = 1;
        break;

    case 4:
        vs_main_freeHeapR(temp_s1->unk4);
        s3 = 0;
        break;
    }

    return s3;
}
