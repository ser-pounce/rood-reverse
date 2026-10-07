#include "src/SLUS_010.40/main.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "scratch.h"
#include "gpu.h"
#include "vs_inline_c.h"
#include <inline_c.h>
#include <libgte.h>

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char uBase;
    u_char vBase;
    u_char uScroll;
    u_char vScroll;
    short tpage;
    short clut;
    short unkA;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
    short unk14;
    int curveSampleDistance;
} PLG005_data_t;

typedef struct {
    u_long unk0;
    POLY_FT4 unk4;
    int unk2C;
    int pad[3];
} unkPrim;

int func_800F9818(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    int gridX[9];
    int gridZ[9];
    SVECTOR vertices[9][9];
    int screenXY[9][9];
    int depths[9][9];
    CVECTOR color;
    u_char uCoords[9];
    u_char vCoords[9];
    D_800F53B8_t* sp5A0;
    int retVal;
    int depthMode;
    int phaseX;
    int phaseZ;
    func_800FA098_arg1* s6;
    func_800FA098_arg0* s7;
    PLG005_data_t* fp;
    int j, i, k;
    int var_a0, var_a2, var_t0;
    int var_a1, var_a3;
    int angleX, angleZ;
    int temp;
    unkPrim* prim;
    MATRIX* m;

    s6 = (func_800FA098_arg1*)0x1F8001D0;
    retVal = 1;
    fp = arg0->unk8;
    sp5A0 = D_800F53BC;

    switch (arg1) {
    case 1:
        fp = vs_main_allocHeapR(sizeof *fp);
        arg0->unk8 = fp;
        fp->unk1 = arg2 >> 8;
        fp->unk0 = arg2;
        fp->curveSampleDistance = 0;
        fp->unkC = 0;
        fp->unkA = 0;
        fp->unk10 = 0;
        fp->unkE = 0;
        fp->unk14 = 0;
        fp->unk12 = 0;
        s7 = &D_800F569C->block5Data->unk4[fp->unk1];
        fp->tpage = ((s7->unkCA & 7) | ((s7->transparencyCurve & 7) << 5)) + 0x18;
        fp->clut = ((s7->unkCB & 7) << 6) | 0x3C30;
        fp->uBase = s7->unk94[3][0];
        fp->vBase = s7->unk94[3][2];
        fp->vScroll = 0;
        fp->uScroll = 0;
        break;

    case 2:
        s7 = &D_800F569C->block5Data->unk4[fp->unk1];
        s6->flags = s7->flags;
        m = &sp5A0->unk1C[s7->unkC8].unk38;
        vs_battle_lerpVector(s7->unk18,
            vs_battle_sampleCurve(s7->unk8, fp->curveSampleDistance), &s6->unk98);
        switch (s6->flags & 7) {
        case 0:
            break;
        case 1:
            vs_battle_addVecToSvec(&s6->unk98, D_800F5310, &s6->unk98);
            break;
        case 2:
            applyVector(&s6->unk98, m->t[0], m->t[1], m->t[2], +=);
            break;
        }
        // bad var reuse: j and i accumulate the grid offsets below
        j = 0;
        k = 0;
        vs_battle_lerpVector(s7->unk24,
            vs_battle_sampleCurve(s7->unk9, fp->curveSampleDistance), &s6->unkA8);
        temp = vs_battle_sampleCurve(s7->unkD, fp->curveSampleDistance);
        vs_battle_lerpSvector(&s7->unk34[2][0], temp, &s6->unkF8);
        vs_battle_lerpSvector(&s7->unk34[3][0], temp, &s6->unk100);
        temp = vs_battle_sampleCurve(s7->unkE, fp->curveSampleDistance);
        vs_battle_lerpSvector(&s7->unk34[4][0], temp, &s6->unk108);
        vs_battle_lerpSvector(&s7->unk34[5][0], temp, &s6->unk110);

        vs_battle_lerpVector(&s7->unk34[0][0],
            vs_battle_sampleCurve(s7->unkA, fp->curveSampleDistance), &s6->unkE8);
        vs_battle_lerpVector(&s7->unk34[1][0],
            vs_battle_sampleCurve(s7->unkB, fp->curveSampleDistance), &s6->unkC8);
        vs_battle_lerp2DVector(&s7->unk94[2][0],
            vs_battle_sampleCurve(s7->unkC, fp->curveSampleDistance), s6->unk118);
        vs_battle_lerp2DVector(&s7->unk94[0][0],
            vs_battle_sampleCurve(s7->unk12, fp->curveSampleDistance), s6->unk124);
        vs_battle_lerp2DVector(&s7->unk94[1][0],
            vs_battle_sampleCurve(s7->unk13, fp->curveSampleDistance), s6->unk12C);

        depthMode = func_800CFE1C(
            s7->unk30, vs_battle_sampleCurve(s7->unk17, fp->curveSampleDistance));

        fp->unkC += s6->unk108.vx;
        fp->unkA += s6->unkF8.vx + fp->unkC;
        var_a2 = s6->unkA8.vx + fp->unkA;
        fp->unk10 += s6->unk108.vy;
        fp->unkE += s6->unkF8.vy + fp->unk10;
        var_a1 = s6->unkA8.vy + fp->unkE;
        fp->unk12 += s6->unkC8.vx;
        phaseX = fp->unk12;
        fp->unk14 += s6->unkC8.vy;
        phaseZ = fp->unk14;

        var_t0 = 0;
        for (; k < 5; k++) {
            gridX[4 - k] = s6->unk98.vx - j;
            gridX[4 + k] = j + s6->unk98.vx;
            j += var_a2;
            var_a2 += var_t0 + s6->unk100.vx;
            var_t0 += s6->unk110.vx;
        }

        i = var_a3 = 0;
        for (k = 0; k < 5; k++) {
            gridZ[4 - k] = s6->unk98.vz - i;
            gridZ[4 + k] = i + s6->unk98.vz;
            i += var_a1;
            var_a1 += var_a3 + s6->unk100.vy;
            var_a3 += s6->unk110.vy;
        }

        for (i = 0; i < 9; i++) {
            angleX = phaseX;
            angleZ = phaseZ;
            phaseX += s6->unk118[0];
            phaseZ += s6->unk118[1];
            for (j = 0; j < 9; j++) {
                vertices[i][j].vx = gridX[j] + ((rsin(angleX) * s6->unkE8.vx) >> 12);
                vertices[i][j].vz = gridZ[i] + ((rcos(angleZ) * s6->unkE8.vy) >> 12);
                vertices[i][j].vy = s6->unk98.vy;
                angleX += s6->unkC8.vx;
                angleZ += s6->unkC8.vy;
            }
        }

        if (s7->rCurve != 0) {
            temp = vs_battle_sampleCurve(s7->rCurve, fp->curveSampleDistance) * 2;
            color.r = temp >= 0x100 ? 0xFF : temp;
        } else {
            color.r = 0x80;
        }

        if (s7->gCurve != 0) {
            temp = vs_battle_sampleCurve(s7->gCurve, fp->curveSampleDistance) * 2;
            color.g = temp >= 0x100 ? 0xFF : temp;
        } else {
            color.g = 0x80;
        }

        if (s7->bCurve != 0) {
            temp = vs_battle_sampleCurve(s7->bCurve, fp->curveSampleDistance) * 2;
            color.b = temp >= 0x100 ? 0xFF : temp;
        } else {
            color.b = 0x80;
        }

        color.cd = primPolyFT4 | primSemiTrans;

        var_a0 = fp->uBase + fp->uScroll;
        fp->uScroll = (fp->uScroll + s6->unk12C[0]) % s7->unk94[0][0];
        for (k = 0; k < 9; k++) {
            uCoords[k] = var_a0 + (s7->unk94[0][0] * k) / 8;
        }

        var_a0 = fp->vBase + fp->vScroll;
        fp->vScroll = (fp->vScroll + s6->unk12C[1]) % s7->unk94[0][2];
        for (k = 0; k < 9; k++) {
            vCoords[k] = var_a0 + (s7->unk94[0][2] * k) / 8;
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
                gte_ldv0(&vertices[i][j]);
                gte_rtps2();
                gte_stsxy(&screenXY[i][j]);
                gte_stszotz(&depths[i][j]);
            }
        }

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                int z = (depths[i][j] + depths[i][j + 1] + depths[i + 1][j]
                            + depths[i + 1][j + 1])
                          / 4
                      + s6->unkA8.vz;
                if (z < 0x800 && vs_main_nearClip < z) {
                    switch (depthMode) {
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
                        if (z - 0x10 > vs_main_nearClip) {
                            z -= 0x10;
                        }
                        break;
                    }
                    prim = vs_scratch.unk0;
                    vs_scratch.unk0 = prim + 1;
                    prim->unk4.tag = _get_mode(0, 0, 0);
                    prim->unk2C = _get_mode(0, 1, 0);
                    *(int*)&prim->unk4.x0 = screenXY[i][j];
                    *(int*)&prim->unk4.x1 = screenXY[i][j + 1];
                    *(int*)&prim->unk4.x2 = screenXY[i + 1][j];
                    *(int*)&prim->unk4.x3 = screenXY[i + 1][j + 1];
                    *(int*)&prim->unk4.r0 = *(int*)&color;
                    prim->unk4.u0 = prim->unk4.u2 = uCoords[j];
                    prim->unk4.u1 = prim->unk4.u3 = uCoords[j + 1];
                    prim->unk4.v0 = prim->unk4.v1 = vCoords[i];
                    prim->unk4.v2 = prim->unk4.v3 = vCoords[i + 1];
                    prim->unk4.tpage = fp->tpage;
                    prim->unk4.clut = fp->clut;
                    *(int*)&prim->unk0 =
                        (((u_long*)vs_scratch.unk4)[z] & 0xFFFFFF) | 0x0B000000;
                    ((u_long*)vs_scratch.unk4)[z] =
                        (((u_long*)vs_scratch.unk4)[z] & 0xFF000000)
                        | ((u_long)prim & 0xFFFFFF);
                }
            }
        }

        fp->curveSampleDistance++;
        if (fp->unk0 != 0) {
            fp->unk0--;
            if (fp->unk0 == 0) {
                retVal = 0;
            }
        }
        break;

    case 3:
        fp->unk0 = 1;
        break;

    case 4:
        retVal = 0;
        break;
    }
    return retVal;
}
