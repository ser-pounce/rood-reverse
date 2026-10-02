#include "common.h"
#include "src/SLUS_010.40/main.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "scratch.h"
#include <libgte.h>

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    u_char unk4;
    u_char unk5;
    short unk6;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
    short unk14;
    int unk18;
} PLG005_data_t;

typedef struct {
    u_long unk0;
    POLY_FT4 unk4;
    int unk2C;
    int pad[3];
} unkPrim;

int func_800F9818(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    int sp10[10];
    int sp38[10];
    SVECTOR sp60[9][9];
    int sp2E8[9][9];
    int sp430[9][9];
    u_char sp578[4];
    u_char sp580[16];
    u_char sp590[16];
    D_800F53B8_t* sp5A0;
    int retVal;
    int sp5A8;
    int sp5AC;
    int sp5B0;
    int* sp5B4;
    int* sp5B8;
    int sp5BC;
    func_800FA098_arg1* s6;
    func_800FA098_arg0* s7;
    PLG005_data_t* fp;
    int j, i, k;
    int var_a0, var_a2, var_t0;
    int var_a1, var_a3;
    int var_s2, var_s1, var_s4;
    int temp;
    unkPrim* prim;
    MATRIX* m;

    s6 = (func_800FA098_arg1*)0x1F8001D0;
    retVal = 1;
    fp = (PLG005_data_t*)arg0->unk8;
    sp5A0 = D_800F53BC;

    if (arg1 == 2) {
        goto case_2;
    }
    if (arg1 < 3) {
        if (arg1 == 1) {
            goto case_1;
        }
        goto end;
    }
    if (arg1 == 3) {
        goto case_3;
    }
    if (arg1 == 4) {
        goto case_4;
    }
    goto end;

case_1:
    fp = (PLG005_data_t*)vs_main_allocHeapR(0x1C);
    arg0->unk8 = fp;
    fp->unk1 = arg2 >> 8;
    fp->unk0 = arg2;
    fp->unk18 = 0;
    fp->unkC = 0;
    fp->unkA = 0;
    fp->unk10 = 0;
    fp->unkE = 0;
    fp->unk14 = 0;
    fp->unk12 = 0;
    s7 = &D_800F569C->block5Data->unk4[(u_char)fp->unk1];
    fp->unk6 = ((s7->unkCA & 7) | ((*(u_int*)((char*)s7 + 4) >> 21) & 0xE0)) + 0x18;
    fp->unk8 = ((s7->unkCB & 7) << 6) | 0x3C30;
    fp->unk2 = ((u_char*)s7)[0xAC];
    fp->unk3 = ((u_char*)s7)[0xB0];
    fp->unk5 = 0;
    fp->unk4 = 0;
    goto end;

case_2:
    s7 = &D_800F569C->block5Data->unk4[fp->unk1];
    s6->flags = *(u_int*)((char*)s7 + 4) & 0x03FFFFFF;
    m = &sp5A0->unk1C[s7->unkC8].unk38;
    vs_battle_lerpVector(
        s7->unk18, vs_battle_sampleCurve(s7->unk8, fp->unk18), (VECTOR*)0x1F800268);
    switch (s6->flags & 7) {
    case 1:
        vs_battle_addVecToSvec((VECTOR*)0x1F800268, D_800F5310, (VECTOR*)0x1F800268);
        break;
    case 0:
        break;
    case 2:
        s6->unk98.vx += m->t[0];
        s6->unk98.vy += m->t[1];
        s6->unk98.vz += m->t[2];
        break;
    }
    j = 0;
    k = 0;
    vs_battle_lerpVector(
        s7->unk24, vs_battle_sampleCurve(s7->unk9, fp->unk18), &s6->unkA8);
    temp = vs_battle_sampleCurve(s7->unkD, fp->unk18);
    vs_battle_lerpSvector(&s7->unk34[2][0], temp, &s6->unkF8);
    vs_battle_lerpSvector(&s7->unk34[3][0], temp, &s6->unk100);
    temp = vs_battle_sampleCurve(s7->unkE, fp->unk18);
    vs_battle_lerpSvector(&s7->unk34[4][0], temp, &s6->unk108);
    vs_battle_lerpSvector(&s7->unk34[5][0], temp, &s6->unk110);

    vs_battle_lerpVector(
        &s7->unk34[0][0], vs_battle_sampleCurve(s7->unkA, fp->unk18), &s6->unkE8);
    vs_battle_lerpVector(
        &s7->unk34[1][0], vs_battle_sampleCurve(s7->unkB, fp->unk18), &s6->unkC8);
    vs_battle_lerp2DVector(
        &s7->unk94[2][0], vs_battle_sampleCurve(s7->unkC, fp->unk18), s6->unk118);
    vs_battle_lerp2DVector(
        &s7->unk94[0][0], vs_battle_sampleCurve(s7->unk12, fp->unk18), s6->unk124);
    vs_battle_lerp2DVector(
        &s7->unk94[1][0], vs_battle_sampleCurve(s7->unk13, fp->unk18), s6->unk12C);

    sp5A8 = func_800CFE1C(s7->unk30, vs_battle_sampleCurve(s7->unk17, fp->unk18));

    fp->unkC += s6->unk108.vx;
    fp->unkA += s6->unkF8.vx + fp->unkC;
    var_a2 = s6->unkA8.vx + (short)fp->unkA;
    fp->unk10 += s6->unk108.vy;
    fp->unkE += s6->unkF8.vy + fp->unk10;
    var_a1 = s6->unkA8.vy + (short)fp->unkE;
    fp->unk12 += s6->unkC8.vx;
    sp5AC = (short)fp->unk12;
    fp->unk14 += s6->unkC8.vy;
    sp5B0 = (short)fp->unk14;

    var_t0 = 0;
    for (; k < 5; k++) {
        sp10[4 - k] = s6->unk98.vx - j;
        sp10[4 + k] = j + s6->unk98.vx;
        j += var_a2;
        var_a2 += var_t0 + s6->unk100.vx;
        var_t0 += s6->unk110.vx;
    }

    i = var_a3 = 0;
    for (k = 0; k < 5; k++) {
        sp38[4 - k] = s6->unk98.vz - i;
        sp38[4 + k] = i + s6->unk98.vz;
        i += var_a1;
        var_a1 += var_a3 + s6->unk100.vy;
        var_a3 += s6->unk110.vy;
    }

    i = 0;
    sp5B8 = sp38;
    sp5BC = 0;
    do {
        var_s2 = sp5AC;
        var_s1 = sp5B0;
        sp5B4 = sp5B8;
        var_s4 = sp5BC;
        j = 0;
        sp5AC = var_s2 + s6->unk118[0];
        sp5B0 = var_s1 + s6->unk118[1];
        do {
            int sin_v = (rsin(var_s2) * s6->unkE8.vx) >> 12;
            SVECTOR* pt = (SVECTOR*)((char*)sp60 + var_s4);
            pt->vx = sp10[j] + sin_v;
            pt->vz = *sp5B4 + ((rcos(var_s1) * s6->unkE8.vy) >> 12);
            var_s4 += 8;
            j++;
            pt->vy = s6->unk98.vy;
            var_s2 += s6->unkC8.vx;
            var_s1 += s6->unkC8.vy;
        } while (j < 9);
        i++;
        sp5B8++;
        sp5BC += 0x48;
    } while (i < 9);

    if (s7->rCurve != 0) {
        temp = vs_battle_sampleCurve(s7->rCurve, fp->unk18) * 2;
        if (temp < 0x100) {
            sp578[0] = temp;
        } else {
            sp578[0] = 0xFF;
        }
    } else {
        sp578[0] = 0x80;
    }

    if (s7->gCurve != 0) {
        temp = vs_battle_sampleCurve(s7->gCurve, fp->unk18) * 2;
        if (temp < 0x100) {
            sp578[1] = temp;
        } else {
            sp578[1] = 0xFF;
        }
    } else {
        sp578[1] = 0x80;
    }

    if (s7->bCurve != 0) {
        temp = vs_battle_sampleCurve(s7->bCurve, fp->unk18) * 2;
        if (temp < 0x100) {
            sp578[2] = temp;
        } else {
            sp578[2] = 0xFF;
        }
    } else {
        sp578[2] = 0x80;
    }

    sp578[3] = 0x2E;

    var_a0 = fp->unk2 + fp->unk4;
    fp->unk4 = (fp->unk4 + s6->unk12C[0]) % s7->unk94[0][0];
    for (k = 0; k < 9; k++) {
        sp580[k] = var_a0 + (s7->unk94[0][0] * k) / 8;
    }

    var_a0 = fp->unk3 + fp->unk5;
    fp->unk5 = (fp->unk5 + s6->unk12C[1]) % s7->unk94[0][2];
    for (k = 0; k < 9; k++) {
        sp590[k] = var_a0 + (s7->unk94[0][2] * k) / 8;
    }

    if (s6->flags & 0x20000) {
        SetRotMatrix(&sp5A0->unk1C[s7->unkC8].unk58);
        SetTransMatrix(&sp5A0->unk1C[s7->unkC8].unk58);
    } else {
        SetRotMatrix(&vs_scratch.viewMatrix);
        SetTransMatrix(&vs_scratch.viewMatrix);
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            __asm__ volatile(
                "lwc2 $0, 0(%0); lwc2 $1, 4(%0); nop; nop; .word 0x4A180001; swc2 $14, 0(%1); mfc2 $t4, $19; nop; sra $t4, $t4, 2; sw $t4, 0(%2)"
                :
                : "r"(&sp60[i][j]), "r"(&sp2E8[i][j]), "r"(&sp430[i][j])
                : "$12", "memory");
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            int z =
                (sp430[i][j] + sp430[i][j + 1] + sp430[i + 1][j] + sp430[i + 1][j + 1])
                    / 4
                + s6->unkA8.vz;
            if (z < 0x800 && vs_main_nearClip < z) {
                switch (sp5A8) {
                case 0:
                default:
                    break;
                case 1:
                    z = 0x7FE;
                    break;
                case 2:
                    z = -0xF;
                    break;
                case 3:
                    z = -0xD;
                    break;
                case 4:
                    z = -0xB;
                    break;
                case 5:
                    if (({
                            int _nc;
                            __asm__("" : "=r"(_nc) : "0"(vs_main_nearClip));
                            _nc < z - 0x10;
                        }))
                        z -= 0x10;
                    break;
                }
                prim = (unkPrim*)vs_scratch.unk0;
                vs_scratch.unk0 = prim + 1;
                prim->unk4.tag = 0xE1000000;
                prim->unk2C = 0xE1000200;
                *(int*)&prim->unk4.x0 = sp2E8[i][j];
                *(int*)&prim->unk4.x1 = sp2E8[i][j + 1];
                *(int*)&prim->unk4.x2 = sp2E8[i + 1][j];
                *(int*)&prim->unk4.x3 = sp2E8[i + 1][j + 1];
                *(u_int*)&prim->unk4.r0 = *(u_int*)sp578;
                prim->unk4.u0 = prim->unk4.u2 = sp580[j];
                prim->unk4.u1 = prim->unk4.u3 = sp580[j + 1];
                prim->unk4.v0 = prim->unk4.v1 = sp590[i];
                prim->unk4.v2 = prim->unk4.v3 = sp590[i + 1];
                prim->unk4.tpage = fp->unk6;
                prim->unk4.clut = fp->unk8;
                *(int*)&prim->unk0 =
                    (((u_long*)vs_scratch.unk4)[z] & 0xFFFFFF) | 0x0B000000;
                ((u_long*)vs_scratch.unk4)[z] =
                    (((u_long*)vs_scratch.unk4)[z] & 0xFF000000)
                    | ((u_long)prim & 0xFFFFFF);
            }
        }
    }

    fp->unk18++;
    if (fp->unk0 != 0) {
        fp->unk0--;
        if (fp->unk0 == 0) {
            retVal = 0;
        }
    }
    goto end;

case_3:
    fp->unk0 = retVal;
    goto end;

case_4:
    retVal = 0;

end:
    return retVal;
}
