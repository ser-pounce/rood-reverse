#include "common.h"
#include "44F14.h"
#include "146C.h"
#include "30DB0.h"
#include "38C1C.h"
#include "3A1A0.h"
#include "40564.h"
#include "4A0A8.h"
#include "5BF94.h"
#include "entity.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/31724.h"
#include "src/SLUS_010.40/32154.h"
#include "scratch.h"
#include "vs_inline_c.h"
#include <rand.h>
#include <abs.h>
#include <inline_c.h>

typedef struct {
    u_char unk0[8];
    int first;
    int last;
    u_char** data;
} D_1F8003EC_t;

typedef struct {
    MATRIX bones[63];
    VECTOR scale;
} D_800F3C58_t;

void func_800AB9A4(void*);
int func_800AD714(D_800F4538_t*, D_800F4538_unkC54*, int);
void func_800AE46C(u_char*);
void func_800AE474(u_char*);
void func_800AE6C0(D_800F4538_t*, int, int);
void func_800AE828(int, D_800F4538_t*, int);
void func_800AF844(SVECTOR*, SVECTOR*, int);
void func_800AFDE8(int, SVECTOR*, int);
void func_800B0908(D_800F45E0_t*, int);
int func_800B101C(D_800F45E0_t*);
void func_800B147C(D_800F4538_unkC54*, D_800F4538_unkC54*, int, int, int);
void func_800B17F0(SVECTOR*, MATRIX*);
void func_800B196C(MATRIX*, MATRIX*);
void func_800B1A68(D_800F45E0_t*, MATRIX*);
void func_800B396C(MATRIX*, VECTOR*);
int func_800B3A68(void*, MATRIX*, int, void*);
void func_800B3CF0(D_800F2458_t*, vs_battle_wepModels_t*, CVECTOR*, void*);
void func_800B4594(D_800F2458_t*, D_800F45E0_t*, CVECTOR*, void*);
void func_800B516C(D_800F2458_t*, vs_battle_wepModels_t*, CVECTOR*, void*);
void func_800B5C30(D_800F2458_t*, D_800F45E0_t*, CVECTOR*, void*);
void func_800E4C28(int, int);
void func_800E6898(void*);

extern MATRIX D_8005E218;
extern u_char D_800E91A4[];
extern signed char D_800E91AC[];
extern signed char D_800E91BC[];
extern signed char D_800E91CC[];
extern signed char D_800E91DC[];
extern signed char D_800E91EC[];
extern signed char D_800E91F0[];
extern signed char D_800E91FC[];
extern signed char D_800E9208[];
extern signed char D_800E9218[];
extern u_char D_800E9228[];
extern signed char D_800E9238[];
extern signed char D_800E9248[];
extern signed char D_800E9258[];
extern signed char D_800E9268[];
extern u_char D_800E9278[];
extern u_char D_800E9298[];
extern u_char D_800E92DC[];
extern int D_800E9308;
extern u_short D_800E9A28[][4];
extern int D_800F1868;
extern D_800F3C58_t D_800F3C58;
extern MATRIX D_800F3C78;
extern MATRIX D_800F4910;
extern MATRIX D_800F49B8;
extern u_char D_800F49F8;
extern char D_800F4B18;
extern u_char D_800F4B19;

int func_800AD714(D_800F4538_t* actor, D_800F4538_unkC54* state, int mode)
{
    u_char op;
    u_short* point;
    int arg;
    int sfx[2];
    int drawOp;
    short delta;
    short packed;
    D_800F4538_t* target5;
    D_800F4538_t* target7;
    D_800F4538_t* target8;
    int lo51;
    int lo52;
    int lo53a;
    int lo53b;
    int lo54;
    D_800F4538_unk1864* motion = &actor->unk1864;
    int id = actor->unk0.unkF;
    u_char* script = state->unk544;

loop:
    op = *script;

    switch (mode) {
    case 0:
        break;

    case 1:
        if (op == 44 || op == 25 || (op >= 29 && op < 47) || (op >= 16 && op < 19)
            || (op >= 51 && op < 55) || (op >= 56 && op < 58) || (op >= 32 && op < 40)) {
            break;
        }

        goto next;

    case 2:
        if (op < 36 || op >= 40) {
            goto next;
        }
        break;

    case 3:
        if (op != 2) {
            goto next;
        }

        return state->unk542;
    }

    switch (op) {
    case 14:
        func_8006C480(id, script[1]);
        break;

    case 15:
        func_8006C4A4(id, script[1]);
        break;

    case 29:
        actor->unk5AC_21 = 1;
        actor->unk1802[0] = 0;
        actor->unk5AC_22 = 0;
        actor->unk1802[1] = 0x20;
        break;

    case 44:
        func_800AB358(id, script);
        break;

    case 28:
        func_800A41D0(actor, script[1]);
        break;

    case 23:
        arg = actor->animationId - 1;
    playAnimation:
        if (arg >= 100) {
            arg -= 100;
        }

        func_800A0204(id, arg, 0, 0);
        goto reload;

    case 24:
        arg = actor->animationId + 1;
        goto playAnimation;

    case 19:
        arg = script[1];
        sfx[0] = 13;
        goto setAnimation;

    case 55:
        if (state->unk549 == 0) {
            state->unk549 = script[1];
        } else if (--state->unk549 == 0) {
            break;
        }

        --state->unk540;
        return 0;

    case 20:
        arg = script[1];
        sfx[0] = 1;
    setAnimation:
        func_800A0204(id, sfx[0], 0, arg);
        goto reload;

    case 26:
    case 27:
        arg = 0;
        drawOp = op;
        sfx[0] = script[1];

        for (; arg < 20; ++arg) {
            vs_battle_wepModels_t* weapon = vs_battle_wepModels[arg];

            if (weapon == NULL || weapon->nBones == 0 || weapon->unkD == 0
                || weapon->actorId != id) {
                continue;
            }

            if (drawOp == 26) {
                if (func_800BEB00() != 4 && !actor->unk0.weaponDrawn) {
                    break;
                }

                weapon->unk8_4 = 1;
                weapon->unk11 = 0;
                weapon->unk12 = 0x40;
            } else {
                weapon->unk11 = 0x40;
                weapon->unk12 = 0;
            }

            weapon->unk13 = sfx[0];
        }
        break;

    case 21:
        func_800A0204(id, script[1], 0, 0);
        actor->unk5AC_16 = 0;
        goto reload;

    case 22:
        arg = script[1];
        sfx[0] = script[2];
        func_800A0204(id, arg, 0, sfx[0]);
        actor->unk5AC_16 = 0;
        goto reload;

    case 4:
        arg = script[1];

        if (arg == 88) {
            if (actor->unk5B1 == 0 || !actor->unk0.weaponDrawn) {
                arg = D_800E92DC[0];
            } else {
                arg = D_800E92DC[actor->unk5B1];
            }
        }

        if (actor->unk0.position.vy < 3000) {
            func_800AE6C0(actor, arg, 0);
        }
        break;

    case 5:
        arg = script[1];
        target5 = D_800F4538[id];
        sfx[1] = script[2];

        if (target5->unk17E4.unk0 == 2) {
            sfx[0] = 0x80;
        } else {
            if (target5->unk0.unk9_0 || target5->unk0.unk9_4 || !target5->unk0.unk9_7
                || target5->unk0.unkA_0 || target5->unk0.unkA_3 || target5->unk0.unkA_5) {
                func_800A1280(id, 0xFF, &target5->unk6FC, 0);
            }

            sfx[0] =
                vs_main_computeSfxPan(*(int*)&target5->unk6FC, target5->unk6FC.vz) >> 16;

            if (target5->unk17E4.unk1 != 0) {
                sfx[0] = target5->unk17E4.unk1;
            }
        }

        if (sfx[1] != 0) {
            vs_main_playSfx(0x7E, arg, sfx[0], sfx[1]);
        }
        break;

    case 7:
        arg = script[1];
        target7 = D_800F4538[id];

        if (target7->unk17E4.unk0 == 2) {
            sfx[0] = 0x80;
            sfx[1] = 0;
        } else {
            int value;

            if (target7->unk0.unk9_0 || target7->unk0.unk9_4 || !target7->unk0.unk9_7
                || target7->unk0.unkA_0 || target7->unk0.unkA_3 || target7->unk0.unkA_5) {
                func_800A1280(id, 0xFF, &target7->unk6FC, 0);
            }

            value = vs_main_computeSfxPan(*(int*)&target7->unk6FC, target7->unk6FC.vz);
            sfx[0] = value >> 16;

            if (target7->unk17E4.unk1 != 0) {
                sfx[0] = target7->unk17E4.unk1;
            }

            sfx[1] = value & 0xFFFF;

            if (target7->unk17E4.unk2 != 0) {
                sfx[1] = target7->unk17E4.unk2;
            }
        }

        if (sfx[1] != 0) {
            vs_main_playSfx(0xFF000, arg, sfx[0], sfx[1]);
        }
        break;

    case 8:
        arg = script[1];
        target8 = D_800F4538[id];
        sfx[1] = script[2];

        if (target8->unk17E4.unk0 == 2) {
            sfx[0] = 0x80;
        } else {
            if (target8->unk0.unk9_0 || target8->unk0.unk9_4 || !target8->unk0.unk9_7
                || target8->unk0.unkA_0 || target8->unk0.unkA_3 || target8->unk0.unkA_5) {
                func_800A1280(id, 0xFF, &target8->unk6FC, 0);
            }

            sfx[0] =
                vs_main_computeSfxPan(*(int*)&target8->unk6FC, target8->unk6FC.vz) >> 16;

            if (target8->unk17E4.unk1 != 0) {
                sfx[0] = target8->unk17E4.unk1;
            }
        }

        if (sfx[1] != 0) {
            vs_main_playSfx(0xFF000, arg, sfx[0], sfx[1]);
        }
        break;

    case 6:
        func_80045D64(0x7E, script[1]);
        break;

    case 9:
        func_80045D64(0xFF000, script[1]);
        break;

    case 11:
        func_800AE828(id, actor, op);
        break;

    case 1:
        func_800AD008(actor, state);
        actor->unk5AC_16 = 1;
    reload:
        arg = state->unk542;
        script = state->unk544;
        state->unk540 = 0;
        goto check;

    case 12:
        if (!actor->unk5AC_16) {
            func_800CEF74(script[1]);
        }
        break;

    case 13:
        if (D_800F1868 == 1 && !actor->unk5AC_18) {
            func_800AD008(actor, state);
            actor->unk5AC_16 = 1;
            goto reload;
        }

        actor->unk5AC_18 = 0;
        break;

    case 2:
        if (func_8006C84C(id) == 0) {
            sfx[0] = 1;
            goto setAnimation;
        }
        break;

    case 36:
    case 37:
    case 38:
        delta = script[1];
        packed = delta << 8;
        packed |= script[2];
        arg = packed & 0x1FF;
        packed >>= 9;
        delta = packed;

        if (mode == 2) {
            delta = -packed;
        }

        (&((SVECTOR*)actor->unk0.unk68->vertexOffset)[arg].vx)[op - 36] += delta;
        actor->unk5AC_23 = 1;
        break;

    case 39:
        delta = script[1];
        packed = delta << 8;
        packed |= script[2];
        arg = packed & 0x1FF;
        packed >>= 9;

        if (mode == 2) {
            applyVector(&((SVECTOR*)actor->unk0.unk68->vertexOffset)[arg], packed,
                (signed char)script[3], (signed char)script[4], -=);
        } else {
            applyVector(&((SVECTOR*)actor->unk0.unk68->vertexOffset)[arg], packed,
                (signed char)script[3], (signed char)script[4], +=);
        }

        actor->unk5AC_23 = 1;
        break;

    case 30:
    case 31:
        arg = op - 30;
        actor->unk1804[arg].overlay = script[1];
        actor->unk1804[arg].x = script[2];
        actor->unk1804[arg].y = script[3];
        actor->unk1804[arg].columns = script[4];
        break;

    case 32:
        func_800AAD4C(id, 1, 1, 1);
        break;

    case 33:
        func_800AAD4C(id, 1, 1, 0);
        break;

    case 34:
        func_800AAD4C(id, 1, 0, 1);
        break;

    case 35:
        func_800AAD4C(id, 1, 0, 0);
        break;

    case 40:
        func_800AE46C(script);
        break;

    case 41:
        func_800AE474(script);
        script += 5;
        break;

    case 10:
        func_800AE4FC(actor, script[1]);
        break;

    case 25:
        actor->unk5AC_20 = 1;
        break;

    case 51:
        delta = script[1];
        lo51 = script[2];
        motion->unk10 = ((delta << 8) | lo51) - motion->unkC;

    setFrames:
        arg = script[3];
    translate:
        if (arg == 0) {
            motion->unkC += motion->unk10;
            motion->unkE += motion->unk12;
        }

        motion->unk5 = arg;
        break;

    case 52:
        delta = script[1];
        lo52 = script[2];
        motion->unk12 = ((delta << 8) | lo52) - motion->unkE;

        goto setFrames;

    case 53:
        delta = script[1];
        lo53a = script[2];
        motion->unk10 = ((delta << 8) | lo53a) - motion->unkC;

        delta = script[3];
        lo53b = script[4];
        motion->unk12 = ((delta << 8) | lo53b) - motion->unkE;

        arg = script[5];
        goto translate;

    case 54:
        delta = script[1];
        lo54 = script[2];
        motion->unkA = ((delta << 8) | lo54) - motion->unk8;

        if (motion->unkA < -ONE / 2) {
            motion->unkA += ONE;
        }

        if (motion->unkA > ONE / 2) {
            motion->unkA -= ONE;
        }

        arg = script[3];

        if (arg == 0) {
            motion->unk8 = (motion->unk8 + motion->unkA) & 0xFFF;
        }

        motion->unk4 = arg;
        break;

    case 56:
    case 57:
        func_800AC440(actor, script[1], op - 56);
        break;

    case 58:
        actor->unk0.unk9_0 = 2;

        if (actor->unk17FD >= 2) {
            D_800F4538[actor->unk17FD]->unk0.unk9_0 = 2;
        }
        break;

    case 59:
        actor->unk0.unk34.vy = 3;
        actor->unk0.unkA_0 = 3;
        actor->unk0.unkA_3 = 0;
        actor->unk0.unk9_6 = 0;
        break;

    case 61:
        actor->unk5B0_3 = 0;
        break;

    case 62:
        actor->unk5B0_3 = 1;
        break;

    case 60:
        arg = script[1];
        point = D_800E9A28[0];
        point += arg * 4;
        motion->unk10 = point[0] - motion->unkC;
        motion->unk12 = point[1] - motion->unkE;

        if (motion->unk5 == 0) {
            motion->unkC += motion->unk10;
            motion->unkE += motion->unk12;
        }

        delta = point[2];
        motion->unkA = delta - motion->unk8;

        if (motion->unkA < -ONE / 2) {
            motion->unkA += ONE;
        }

        if (motion->unkA > ONE / 2) {
            motion->unkA -= ONE;
        }

        if (motion->unk4 == 0) {
            motion->unk8 = (motion->unk8 + motion->unkA) & 0xFFF;
        }
        break;

    case 63:
        if (!actor->unk5AC_16) {
            func_800CF8BC();
        }
        break;

    case 64:
        actor->unk5AC_20 = 0;
        break;

    case 0:
    default:
        state->unk542 = 0xFFFF;
        return 0;
    }

next:
    script += D_800E9298[op];
    arg = *script;

    if (arg == 255) {
        arg = script[1] + 0xFF;
        script += 2;
    } else {
        ++script;
    }

    state->unk542 = arg;
    state->unk544 = script;
check:
    if ((mode >= 2 ? actor->unk5BC : state->unk540) >= arg) {
        goto loop;
    }

    return 0;
}

void func_800AE46C(u_char* script __attribute__((unused))) { }

void func_800AE474(u_char* script __attribute__((unused))) { }

void func_800AE47C(D_800F4538_t* arg0)
{
    u_short* sp10;
    int var_v1;

    u_char** v0 = func_800AD494(arg0, arg0->animationId, &sp10);
    u_char* temp_a3 = *v0;
    temp_a3 += sp10[2];

    var_v1 = temp_a3[0];

    if (var_v1 == 0xFF) {
        var_v1 = temp_a3[1] + 0xFF;
        temp_a3 = temp_a3 + 2;
    } else {
        temp_a3 = temp_a3 + 1;
    }

    arg0->unk704.unk542 = var_v1;
    arg0->unk704.unk544 = temp_a3;

    func_800AD714(arg0, &arg0->unk704, 2);
}

void func_800AE4FC(D_800F4538_t* arg0, int arg1)
{
    D_800F4538_t* actor;
    int temp;
    int sp[2];
    int type = arg1;

    if (arg0->unk0.position.vy >= 0xBB8) {
        return;
    }

    actor = D_800F4538[arg0->unk0.unkF];

    if (actor->unk17E4.unk0 == 2) {
        sp[0] = 0x80;
        sp[1] = 0;
    } else {
        if ((*((int*)&actor->unk0.nQuads + 1) & 0x3F9F00) != 0x8000) {
            func_800A1280(arg0->unk0.unkF, 0xFF, &actor->unk6FC, 0);
        }

        temp = vs_main_computeSfxPan(*(int*)&actor->unk6FC, actor->unk6FC.vz);
        sp[0] = temp >> 0x10;

        if (actor->unk17E4.unk1 != 0) {
            sp[0] = actor->unk17E4.unk1;
        }

        sp[1] = temp & 0xFFFF;

        if (actor->unk17E4.unk2 != 0) {
            sp[1] = actor->unk17E4.unk2;
        }
    }

    if (sp[1] == 0) {
        return;
    }

    if (type == 8) {
        func_8006CD60(arg0->unk0.unk68->akaoOffset, sp[0], sp[1]);
    } else if (type == 4) {
        func_800461CC(0x7E, arg0->unk0.unk68->akaoOffset, rand() % 4 + 4, sp[0], sp[1]);
    } else {
        func_800461CC(0x180, arg0->unk0.unk68->akaoOffset, type, sp[0], sp[1]);
    }
}

void func_800AE68C(int arg0, int arg1) { func_800AE4FC(D_800F4538[arg0], arg1 + 4); }

void func_800AE6C0(D_800F4538_t* arg0, int arg1, int arg2)
{
    int sp10[2];
    D_800F4538_t* temp_s0 = D_800F4538[arg0->unk0.unkF];

    if (temp_s0->unk17E4.unk0 == 2) {
        sp10[0] = 0x80;
        sp10[1] = 0;
    } else {
        int temp_v0;

        if (temp_s0->unk0.unk9_0 || temp_s0->unk0.unk9_4 || !temp_s0->unk0.unk9_7
            || temp_s0->unk0.unkA_0 || temp_s0->unk0.unkA_3 || temp_s0->unk0.unkA_5) {
            func_800A1280(arg0->unk0.unkF, 0xFF, &temp_s0->unk6FC, 0);
        }

        temp_v0 = vs_main_computeSfxPan(*(int*)&temp_s0->unk6FC, temp_s0->unk6FC.vz);
        sp10[0] = temp_v0 >> 0x10;

        if (temp_s0->unk17E4.unk1 != 0) {
            sp10[0] = temp_s0->unk17E4.unk1;
        }

        sp10[1] = temp_v0 & 0xFFFF;

        if (temp_s0->unk17E4.unk2 != 0) {
            sp10[1] = temp_s0->unk17E4.unk2;
        }
    }

    if (sp10[1] != 0) {
        vs_main_playSfx(0x7E, arg1, sp10[0], sp10[1]);
        if (arg2 != 0) {
            vs_main_playSfx(0x7E, arg2, sp10[0], sp10[1]);
        }
    }
}

void func_800AE7D8(void* arg0, int arg1, int arg2)
{
    SVECTOR* temp_s0;

    temp_s0 = arg0 + 0x1C;
    vs_main_panSfx(0x7E, arg1, temp_s0);
    if (arg2 != 0) {
        vs_main_panSfx(0x7E, arg2, temp_s0);
    }
}

void func_800AE828(int arg0, D_800F4538_t* arg1, int arg2)
{
    int sp10;
    int sp14;
    int id;
    int floor;
    _mpdRoomSection3* room;

    if ((u_char)(arg1->animationId - 0xCA) < 18) {
        return;
    }
    if (arg0 == 1) {
        return;
    }
    if (arg1->unk5AC_28) {
        id = D_800E91A4[D_800F45E0[func_800A91DC(arg1->unk0.currentTile.x,
                                       arg1->unk0.currentTile.z, 1)]
                ->unk16C.actorId];
    } else {
        floor = arg1->unk0.currentTile.y;
        id = 0xD;
        if (arg1->unk6E4 != 0) {
            floor = arg1->unk6E4;
        }
        room = func_8008B764(arg1->unk0.currentTile.x, arg1->unk0.currentTile.z, floor);
        if (room != NULL) {
            id = D_800E9278[room->unk0_0];
        }
    }
    if (arg2 == 0x41) {
        id += 0x10;
    } else if (arg2 == 0x42) {
        id += 0x18;
    } else {
        func_8008EB04(&sp10, &sp14);
        if (sp14 >= 6 && sp10 > 0 && sp10 < 3) {
            id += 8;
        }
    }
    func_800AE4FC(arg1, id);
}

void func_800AE980(D_800F4538_unkC54* dst, D_800F4538_unkC54* src, int count)
{
    int i;

    dst->unk0[41].vx = (dst->unk0[41].vx + src->unk0[41].vx) >> 1;
    dst->unk0[41].vy = (dst->unk0[41].vy + src->unk0[41].vy) >> 1;
    dst->unk0[41].vz = (dst->unk0[41].vz + src->unk0[41].vz) >> 1;

    for (i = 0; i < count; ++i) {
        int x = src->unk0[i].vx - dst->unk0[i].vx;
        int y;
        int z;

        if (x >= ONE) {
            x -= ONE * 2;
        } else if (x < -ONE) {
            x += ONE * 2;
        }

        dst->unk0[i].vx += x >> 1;
        y = src->unk0[i].vy - dst->unk0[i].vy;

        if (y >= ONE) {
            y -= ONE * 2;
        } else if (y < -ONE) {
            y += ONE * 2;
        }

        dst->unk0[i].vy += y >> 1;
        z = src->unk0[i].vz - dst->unk0[i].vz;

        if (z >= ONE) {
            z -= ONE * 2;
        } else if (z < -ONE) {
            z += ONE * 2;
        }

        dst->unk0[i].vz += z >> 1;

        dst->unk150[i].vx = (dst->unk150[i].vx + src->unk150[i].vx) >> 1;
        dst->unk150[i].vy = (dst->unk150[i].vy + src->unk150[i].vy) >> 1;
        dst->unk150[i].vz = (dst->unk150[i].vz + src->unk150[i].vz) >> 1;
    }
}

void func_800AEAE8(D_800F4538_t* actor)
{
    D_1F80035C_t* scratch = (void*)0x1F80035C;

    D_800F2458.unk1FD0[0] = 64;
    D_800F2458.unk1FD0[1] = 64;
    D_800F2458.unk1FD0[2] = 64;

    if (actor->unk0.unk2C == ONE && actor->unk0.unk2E == ONE
        && actor->unk0.unk30 == ONE) {
        setVector(&scratch->offset, actor->unk704.unk0[41].vx >> 1,
            actor->unk704.unk0[41].vy >> 1, actor->unk704.unk0[41].vz >> 1);
    } else {
        setVector(&scratch->offset,
            actor->unk704.unk0[41].vx * actor->unk0.unk2C / (ONE * 2),
            actor->unk704.unk0[41].vy * actor->unk0.unk2E / (ONE * 2),
            actor->unk704.unk0[41].vz * actor->unk0.unk30 / (ONE * 2));
    }

    setVector(&scratch->offset, scratch->offset.vx * actor->unk183C / ONE,
        scratch->offset.vy * actor->unk183C / ONE,
        scratch->offset.vz * actor->unk183C / ONE);
    func_800B07DC(actor);
    scratch->unk3A = actor->unk0.unk14;
    scratch->unk3C = actor->unk0.unk16;
}

void func_800AECA0(MATRIX* source)
{
    MATRIX roll;
    D_1F80035C_t* scratch = (void*)0x1F80035C;
    vs_scratch_t* view = (void*)0x1F800000;
    int i;

    for (i = 0; i < 3; ++i) {
        scratch->matrix.m[0][i] = D_8005E218.m[i][0];
        scratch->matrix.m[1][i] = D_8005E218.m[i][1];
        scratch->matrix.m[2][i] = D_8005E218.m[i][2];
    }

    roll.m[1][1] = roll.m[0][0] = rcos(-view->camera.angles.vz);
    roll.m[1][0] = rsin(-view->camera.angles.vz);
    roll.m[0][1] = -roll.m[1][0];
    roll.m[2][2] = ONE;
    roll.m[0][2] = roll.m[1][2] = roll.m[2][0] = roll.m[2][1] = 0;
    setVector(&scratch->scale, 3640, ONE, ONE);
    ScaleMatrix(&scratch->matrix, &scratch->scale);
    func_80041C68(&scratch->matrix, &roll);
    scratch->matrix = roll;
    i = ONE * ONE / view->camera.farClip;
    setVector(&scratch->scale, i, i, i);
    ScaleMatrix(&scratch->matrix, &scratch->scale);
    // BUG: copies from the stack slot of the pointer, not from the matrix it points to
    D_800F4910 = *(MATRIX*)&source;
    D_800F49B8 = scratch->matrix;
    D_800F49B8.t[0] = source->t[0];
    D_800F49B8.t[1] = source->t[1];
    D_800F49B8.t[2] = source->t[2];
}

inline void func_800AEEC4(D_800F4538_t* actor)
{
    int _[2] __attribute__((unused));
    int step;
    int delta;

    if (actor->unk17E4.unk0 != 1 || actor->unk17E4.unk3 == 0) {
        return;
    }

    step = vs_gametime_tickspeed / 2;

    if (actor->unk17E4.unk3 < step) {
        step = actor->unk17E4.unk3;
    }

    delta = actor->unk17E8.unk2 - actor->unk17E4.unk2;

    if (delta != 0) {
        delta *= step;
        delta /= actor->unk17E4.unk3;
        actor->unk17E4.unk2 += delta;
    }

    delta = actor->unk17E8.unk1 - actor->unk17E4.unk1;

    if (delta != 0) {
        delta *= step;
        delta /= actor->unk17E4.unk3;
        actor->unk17E4.unk1 += delta;
    }

    actor->unk17E4.unk3 -= step;
}

void func_800AEF94(MATRIX* camera)
{
    D_1F80035C_t* scratch;
    D_800F4538_t* actor;
    vs_scratch_t* view;
    int i;
    int j;
    int _[10] __attribute__((unused));

    func_800AECA0(camera);

    for (i = 0; i < 17; ++i) {
        actor = D_800F4538[i];

        if (actor == NULL || actor->unk0.nBones == 0 || actor->unk0.skip
            || actor->unk0.unk13 == 252) {
            continue;
        }

        func_800AAE9C(actor);

        if (actor->unk0.unk64.unk0 != 0) {
            func_800AB788(actor, NULL, 0);
        }

        if (actor->unk0.unk9_0) {
            func_800AB9A4(actor);
        }

        actor->unk0.unkB_7 = 0;

        if (actor->unk0.freeze) {
            func_800AEEC4(actor);

            for (j = 0; j < i; ++j) {
                if (D_800F4538[j]->unk6E6 == actor->unk6E6) {
                    goto loaded;
                }
            }

            func_800AB4F0(actor);
        loaded:
            if (actor->unk5AC_0) {
                func_800AC540(i, actor);
            }

            if (vs_gametime_tickspeed == 4) {
                actor->unk5B2 *= 2;
            }

            func_800AF6E8(actor);
            actor->unk5B2 = 1;
            actor->unk5B2 = actor->unk5B0_3 + 1;
        } else {
            func_800AEAE8(actor);
        }

        if (actor->unk0.unk9_5) {
            func_800B28A8(
                actor, &D_800F4538[actor->unk0.unk12]->bones[actor->unk0.unk13], 0);
        } else {
            func_800B28A8(actor, camera, 0);

            if (actor->unk17FD != 0) {
                if (actor->unk17FD >= 2) {
                    D_800F4538_t* attached = D_800F4538[actor->unk17FD];

                    func_800AAE9C(attached);

                    if (attached->unk0.unk64.unk0 != 0) {
                        func_800AB788(attached, NULL, 0);
                    }

                    if (attached->unk0.unk9_0) {
                        func_800AB9A4(attached);
                    }

                    if (actor->unk0.freeze) {
                        func_800AEEC4(attached);

                        for (j = 0; j < i; ++j) {
                            if (D_800F4538[j]->unk6E6 == attached->unk6E6) {
                                goto attachedLoaded;
                            }
                        }

                        func_800AB4F0(attached);
                    attachedLoaded:;
                    }
                }

                view = (void*)0x1F800000;
                view->unk4 += actor->unk6F4.unk3 * 4;
                applyVector(&actor->unk0.position, actor->unk6F4.unk0, actor->unk6F4.unk1,
                    actor->unk6F4.unk2, +=);
                func_800B002C(actor, actor->unk17FD);
                func_800B28A8(actor, camera, actor->unk17FD);
                view->unk4 -= actor->unk6F4.unk3 * 4;
                applyVector(&actor->unk0.position, actor->unk6F4.unk0, actor->unk6F4.unk1,
                    actor->unk6F4.unk2, -=);
            }
        }

        if (actor->unk63C >= 128 && actor->unk5CC != 0) {
            actor->unk0.unkB_7 = 1;
        }
    }

    for (i = 0; i < 20; ++i) {
        vs_battle_wepModels_t* weapon = vs_battle_wepModels[i];

        if (weapon == NULL || !weapon->unk8_4 || weapon->unkD == 0) {
            continue;
        }

        actor = D_800F4538[weapon->actorId];

        if (actor == NULL || actor->unk0.skip) {
            continue;
        }

        if (!actor->unk0.visible) {
            continue;
        }

        if (actor->unk0.unk9_4) {
            continue;
        }

        func_800B217C(weapon, &actor->bones[weapon->unkD]);
    }

    scratch = (void*)0x1F80035C;
    view = (void*)0x1F800000;
    view->unk4 += 16;

    for (i = 0; i < 16; ++i) {
        D_800F45E0_t* object = D_800F45E0[i];
        int position;
        int height;

        if (object == NULL || object->unk0.nBones == 0) {
            continue;
        }

        if ((i == D_800F4B19 && D_800F4B18 == 0) || object->unk0.unk1A == 247) {
            func_800B0908(object, vs_gametime_tickspeed / 2);
        }

        position = *(int*)&object->unk0.position.vx;
        scratch->offset.vz = object->unk0.position.vz;
        height = object->unk0.unk68->armatures[1].unk0;
        *(int*)&scratch->offset = position;
        scratch->offset.vy += height / 2;

        if (object->unk0.unk64.unk0 != 0) {
            func_800AB788(NULL, object, 0);
        }

        if (object->unk0.unk9_0) {
            func_800AB9A4(object);
        }

        func_800B1A68(object, camera);
    }

    D_800F4B18 = 0;
    view->unk4 -= 16;
    ++D_800E9308;
}

void func_800AF6E8(D_800F4538_t* arg0)
{
    func_800AFA28(arg0, &arg0->unkC54, 0);

    if (arg0->unk5CC != 0) {
        int v5b2;

        if (arg0->unk5CC == 1) {
            func_800AF844(arg0->unk704.unk0, arg0->unkC54.unk0, arg0->unk0.nBones);
        }

        v5b2 = arg0->unk5B2;

        if (v5b2 != 1) {
            int next = arg0->unk5CC + 0xFF;
            arg0->unk5CC = v5b2 + next;

            if (arg0->unk5CC >= arg0->unk5CD) {
                arg0->unk5CC = 0;
                arg0->unk5CD = 0;
                goto tail;
            }
        }

        func_800B147C(
            &arg0->unk704, &arg0->unkC54, arg0->unk0.nBones, arg0->unk5CC, arg0->unk5CD);

        arg0->unk704.unk548_16 = arg0->unkC54.unk548_16;
        arg0->unk704.unk548_17 = arg0->unkC54.unk548_17;

        func_800B002C(arg0, 0);

        ++arg0->unk5CC;

        if (arg0->unk5CC >= arg0->unk5CD) {
            arg0->unk5CC = 0;
            arg0->unk5CD = 0;
        }
        return;
    }

tail:
    vs_main_memcpy(&arg0->unk704, &arg0->unkC54, sizeof(arg0->unk704));
    func_800B002C(arg0, 0);
}

void func_800AF844(SVECTOR* dst, SVECTOR* src, int count)
{
    int i;

    for (i = 0; i < count; ++i) {
        int x = src[i].vx - dst[i].vx;
        int z;

        if (x >= ONE) {
            x -= ONE * 2;
        } else if (x < -ONE) {
            x += ONE * 2;
        }

        x = ABS(x);
        z = src[i].vz - dst[i].vz;

        if (z >= ONE) {
            z -= ONE * 2;
        } else if (z < -ONE) {
            z += ONE * 2;
        }

        z = ABS(z);

        if (x + z >= ONE) {
            dst[i].vx = (dst[i].vx + ONE) % (ONE * 2);
            dst[i].vz = (dst[i].vz + ONE) % (ONE * 2);
            dst[i].vy = (ONE - dst[i].vy) % (ONE * 2);
        }
    }
}

inline void func_800AF960(D_800F4538_t* arg0)
{
    int temp_lo;

    D_800F4538_unk1864* a2 = &arg0->unk1864;

    if (a2->unk4 != 0) {
        temp_lo = a2->unkA / a2->unk4;
        a2->unkA -= temp_lo;
        a2->unk8 += temp_lo;
        --a2->unk4;
    }

    a2->unk8 &= 0xFFF;

    if (a2->unk5 != 0) {
        temp_lo = a2->unk10 / a2->unk5;
        a2->unk10 -= temp_lo;
        a2->unkC += temp_lo;
        temp_lo = a2->unk12 / a2->unk5;
        a2->unk12 -= temp_lo;
        a2->unkE += temp_lo;
        --a2->unk5;
    }
}

void func_800AFA28(D_800F4538_t* actor, D_800F4538_unkC54* state, int mode)
{
    u_short* header;
    D_1F8003EC_t* scratch = (void*)0x1F8003EC;
    int first;
    int last;
    int i;
    u_short track;
    u_char** data;

    state->unk548_17 = 0;
    first = state->unk540;

    for (i = 0; i < actor->unk5B2; ++i) {
        func_800AF960(actor);

        if (state->unk540 >= actor->unk5BC) {
            state->unk548_17 = 1;

            if (actor->unk6E0 != 0) {
                func_800A0618(
                    actor->unk0.unkF, actor->unk6E0, actor->unk6E1, actor->unk6E2);
                actor->unk6E0 = 0;
                return;
            }
        }

        if (actor->unk0.freeze && state->unk542 == state->unk540) {
            func_800AD714(actor, state, mode);
        }

        if (state->unk540 >= actor->unk5BC) {
            --state->unk540;
            state->unk548_16 = 1;
        }

        ++state->unk540;
    }

    if (state->unk540 == 1 || state->unk548_16) {
        return;
    }

    if (state->unk549 != 0) {
        return;
    }

    last = state->unk540 - 1;

    if (last < first) {
        first = 1;
    }

    if (first == 0) {
        first = 1;
    }

    data = func_800AD494(actor, actor->animationId, &header);

    if (data == NULL) {
        return;
    }

    scratch->first = first;
    scratch->last = last;
    scratch->data = data;

    track = header[4];

    if (track != 0) {
        func_800AFDE8(track, &state->unk150[41], 0);
        applyVector(&actor->unk0.position, state->unk150[41].vx / 4,
            state->unk150[41].vy / 4, state->unk150[41].vz / 4, +=);
    }

    func_800AFDE8(header[3], &state->unk0[41], 0);

    for (i = 0; i < actor->unk0.nBones; ++i) {
        func_800AFDE8(header[i + 5], &state->unk0[i], 1);

        if (((u_char*)header)[3] & 2) {
            func_800AFDE8(header[i + actor->unk0.nBones + 5], &state->unk150[i], 0);
        }
    }
}

void func_800AFDE8(int offset, SVECTOR* value, int rotation)
{
    D_1F8003EC_t* scratch = (void*)0x1F8003EC;
    SVECTOR* delta = &value[84];
    u_char* data = (u_char*)(u_int)(u_short)value->pad;
    int nextFrame = (u_short)delta->pad;
    int frame;

    data += offset + (int)*scratch->data;

    for (frame = scratch->first; frame <= scratch->last; ++frame) {
        while (1) {
            int flags;
            int count;

            if (nextFrame >= frame) {
                addVector(value, delta);

                if (rotation) {
                    *(int*)value &= 0x1FFF1FFF;
                    value->vz &= 0x1FFF;
                }
                break;
            }

            flags = *data;

            if (flags == 0) {
                return;
            }

            if (flags & 0xE0) {
                count = flags & 0x1F;

                if (count == 0x1F) {
                    nextFrame += 32;
                    nextFrame += data[1];
                    data += 2;
                } else {
                    nextFrame += count + 1;
                    ++data;
                }
            } else {
                int packed;

                count = flags & 3;

                if (count == 3) {
                    nextFrame += 4;
                    nextFrame += data[1];
                    data += 2;
                } else {
                    nextFrame += count + 1;
                    ++data;
                }

                flags <<= 3;
                count = (signed char)data[0];
                count <<= 8;
                count |= data[1];
                data += 2;
                packed = count;
                count >>= 3;

                if (packed & 4) {
                    delta->vx = count;
                    flags &= 0x60;

                    if (packed & 3) {
                        count = (signed char)data[0];
                        count <<= 8;
                        count |= data[1];
                        data += 2;
                    }
                }

                if (packed & 2) {
                    delta->vy = count;
                    flags &= 0xA0;

                    if (packed & 1) {
                        count = (signed char)data[0];
                        count <<= 8;
                        count |= data[1];
                        data += 2;
                    }
                }

                if (packed & 1) {
                    delta->vz = count;
                    flags &= 0xC0;
                }
            }

            if (flags & 0x80) {
                delta->vx = (signed char)*data++;
            }

            if (flags & 0x40) {
                delta->vy = (signed char)*data++;
            }

            if (flags & 0x20) {
                delta->vz = (signed char)*data++;
            }
        }
    }

    data -= offset + (int)*scratch->data;
    value->pad = (int)data;
    delta->pad = nextFrame;
}

void func_800B002C(D_800F4538_t* actor, int arg1)
{
    D_1F80035C_t* scratch = (void*)0x1F80035C;
    int dx;
    int yaw;
    int pitch;
    int limit;

    if (actor->unk0.unk2C == ONE && actor->unk0.unk2E == ONE
        && actor->unk0.unk30 == ONE) {
        setVector(&scratch->offset, actor->unk704.unk0[41].vx >> 1,
            actor->unk704.unk0[41].vy >> 1, actor->unk704.unk0[41].vz >> 1);
    } else {
        setVector(&scratch->offset,
            actor->unk704.unk0[41].vx * actor->unk0.unk2E / (ONE * 2),
            actor->unk704.unk0[41].vy * actor->unk0.unk30 / (ONE * 2),
            actor->unk704.unk0[41].vz * actor->unk0.unk2C / (ONE * 2));
    }

    setVector(&scratch->offset, scratch->offset.vx * actor->unk183C / ONE,
        scratch->offset.vy * actor->unk183C / ONE,
        scratch->offset.vz * actor->unk183C / ONE);

    if (arg1 == 0) {
        if (actor->unk5C8 != 0) {
            dx = actor->unk0.unk44.vx / actor->unk5C8;
            actor->unk0.unk44.vx -= dx;
            actor->unk0.unk2C += dx;
            dx = actor->unk0.unk44.vy / actor->unk5C8;
            actor->unk0.unk44.vy -= dx;
            actor->unk0.unk2E += dx;
            dx = actor->unk0.unk44.vz / actor->unk5C8;
            actor->unk0.unk44.vz -= dx;
            actor->unk0.unk30 += dx;
            --actor->unk5C8;
        }

        if (actor->unk0.unk18 != 0) {
            dx = actor->unk0.unk3C / actor->unk0.unk18;
            actor->unk0.unk3C -= dx;
            actor->unk0.unk24 = (actor->unk0.unk24 + dx) & 0xFFF;
            dx = actor->unk0.unk3E / actor->unk0.unk18;
            actor->unk0.unk3E -= dx;
            actor->unk0.facing = (actor->unk0.facing + dx) & 0xFFF;
            dx = actor->unk0.unk40 / actor->unk0.unk18;
            actor->unk0.unk40 -= dx;
            actor->unk0.unk28 = (actor->unk0.unk28 + dx) & 0xFFF;
            --actor->unk0.unk18;
        }

        if (actor->unk5B0_4) {
            actor->unk704.unk0[0].vx = ONE / 2;
            actor->unkC54.unk0[0].vx = ONE / 2;
        }

        if (actor->unk0.unk1A != 0) {
            dx = actor->unk0.unk34.vx / actor->unk0.unk1A;
            actor->unk0.unk34.vx -= dx;
            actor->unk0.position.vx += dx;
            dx = actor->unk0.unk34.vy / actor->unk0.unk1A;
            actor->unk0.unk34.vy -= dx;
            actor->unk0.position.vy += dx;
            dx = actor->unk0.unk34.vz / actor->unk0.unk1A;
            actor->unk0.unk34.vz -= dx;
            actor->unk0.position.vz += dx;

            if (--actor->unk0.unk1A == 0) {
                if (actor->unk0.unkA_3 == 1) {
                    actor->unk0.unkA_3 = 0;
                    actor->unk0.unk9_6 = 0;
                    actor->unk6E3 = 0xFF;
                }

                if (actor->unk0.unkA_3 != 2) {
                    actor->unk0.currentTile.x = actor->unk0.position.vx / 128;
                    actor->unk0.currentTile.z = actor->unk0.position.vz / 128;
                    func_800A92B8(actor->unk0.currentTile.x, actor->unk0.currentTile.z);
                    actor->unk5AC_28 = D_800F49F8;
                }
            }
        }
    }

    func_800B07DC(actor);

    if (!actor->unk0.unkA_0 && !actor->unk0.unkA_3 && !actor->unk0.unkA_5) {
        actor->unk0.lastTouchedTile = actor->unk0.currentTile;
        memcpy(&actor->unk0.lastPosition, &actor->unk0.position, sizeof(SVECTOR));

        if (actor->unk0.unkC_0 == 0) {
            actor->unk1868 = *(int*)&actor->unk0.currentTile;
        }

        actor->unk0.lastPosition.pad = actor->unk0.facing;
    }

    if (actor->unk17FC != -2) {
        int track = 0;

        if (func_800BEB00() != 4) {
            if (actor->unk0.unkB_7) {
                return;
            }

            dx = actor->animationId;

            if (dx >= 100) {
                dx -= 100;
            }

            if (actor->unk0.unkA_6) {
                if (dx >= 31 && dx < 39) {
                    track = 1;
                }
            } else if (actor->unk0.unkA_5) {
                if (dx >= 8 && dx < 35) {
                    track = 1;
                }
            } else if (dx == 0) {
                goto track;
            } else if (dx == 1 || dx == 6 || dx == 13 || dx == 14 || dx == 17
                       || dx == 18) {
                goto track;
            }

            if (track == 0) {
            reset:
                yaw = 0;
                pitch = yaw;
                goto apply;
            }
        }

    track:
        if (actor->unk17FC == -4) {
            pitch = actor->unk17F4.vx;
            yaw = actor->unk17F4.vy;
        } else if (actor->unk17FC == -3) {
            pitch = actor->unk17F4.vx - actor->unk0.unk24;
            yaw = actor->unk17F4.vy - actor->unk0.facing;
        } else {
            int dz;

            if (actor->unk17FC == -1) {
                dx = actor->unk17F4.vx - actor->unk0.position.vx;
                dz = actor->unk17F4.vz - actor->unk0.position.vz;
            } else {
                dx = D_800F4538[actor->unk17FC]->unk0.position.vx
                   - actor->unk0.position.vx;
                dz = D_800F4538[actor->unk17FC]->unk0.position.vz
                   - actor->unk0.position.vz;
            }

            yaw = ONE * 3 / 4 - ratan2(dz, dx);
            yaw &= 0xFFF;
            yaw -= actor->unk0.facing;
            dx *= dx;

            if (dx < 0) {
                dx = -dx;
            }

            dz *= dz;

            if (dz < 0) {
                dz = -dz;
            }

            dx = vs_gte_rsqrt(dx + dz);

            if (actor->unk17FC == -1) {
                dz = actor->unk17F4.vy - actor->unk0.position.vy;
            } else {
                dz = D_800F4538[actor->unk17FC]->unk0.position.vy
                   - actor->unk0.position.vy;
            }

            pitch = ratan2(dx, dz);
            pitch -= ONE / 4;
            pitch &= 0xFFF;
        }

        if (yaw >= ONE / 2) {
            yaw -= ONE;
        }

        if (yaw < -ONE / 2) {
            yaw += ONE;
        }

        if (yaw > 800) {
            yaw = 800;
        }

        if (yaw < -800) {
            yaw = -800;
        }

        if (pitch >= ONE / 2) {
            pitch -= ONE;
        }

        if (pitch < -ONE / 2) {
            pitch += ONE;
        }

        if (pitch > 800) {
            pitch = 800;
        }

        if (pitch < -800) {
            pitch = -800;
        }

    apply:
        limit = actor->unk17F4.pad;
        yaw -= (short)actor->unk0.unk14;

        if (yaw > limit) {
            yaw = limit;
        }

        if (yaw < -limit) {
            yaw = -limit;
        }

        pitch -= (short)actor->unk0.unk16;

        if (pitch > limit) {
            pitch = limit;
        }

        if (pitch < -limit) {
            pitch = -limit;
        }

        scratch->unk3A = actor->unk0.unk14 + yaw;
        scratch->unk3C = actor->unk0.unk16 + pitch;
        actor->unk0.unk14 = scratch->unk3A;
        actor->unk0.unk16 = scratch->unk3C;
    } else if (actor->unk0.unk14 != 0 || actor->unk0.unk16 != 0) {
        goto reset;
    } else {
        scratch->unk3A = 0;
        scratch->unk3C = 0;
    }
}

void func_800B07DC(D_800F4538_t* actor)
{
    D_1F80035C_t* scratch = (void*)0x1F80035C;

    setVector(
        &scratch->rotation, actor->unk0.unk24, actor->unk0.facing, actor->unk0.unk28);
    RotMatrixYXZ_gte(&scratch->rotation, &scratch->matrix);
    scratch->matrix.t[0] = 0;
    scratch->matrix.t[1] = 0;
    scratch->matrix.t[2] = 0;
    gte_SetRotMatrix(&scratch->matrix);
    gte_SetTransMatrix(&scratch->matrix);
    gte_ldv0(&scratch->offset);
    gte_rtv0tr2();
    gte_stlvnl(scratch->matrix.t);
    setVector(&scratch->offset, scratch->matrix.t[0], scratch->matrix.t[1],
        scratch->matrix.t[2]);
    scratch->offset.vx += actor->unk0.position.vx;
    scratch->offset.vz += actor->unk0.position.vz;
    scratch->offset.vy += actor->unk0.position.vy;
}

void func_800B0908(D_800F45E0_t* object, int arg1 __attribute__((unused)))
{
    D_1F80035C_t* scratch = (void*)0x1F80035C;
    int step;
    int mode;
    int other;
    if (object->unk0.unk11) {
        --object->unk0.unk11;
        return;
    }

    if (object->unk0.unk18) {
        step = object->unk0.unk3C / object->unk0.unk18;
        object->unk0.unk3C -= step;
        object->unk0.unk24 = (object->unk0.unk24 + step) & 0xFFF;
        step = object->unk0.unk3E / object->unk0.unk18;
        object->unk0.unk3E -= step;
        object->unk0.facing = (object->unk0.facing + step) & 0xFFF;
        step = object->unk0.unk40 / object->unk0.unk18;
        object->unk0.unk40 -= step;
        object->unk0.unk28 = (object->unk0.unk28 + step) & 0xFFF;
        --object->unk0.unk18;
    }

    mode = object->unk0.unk1A;
    if (mode == 0) {
        return;
    }

    if (mode == 255) {
        if (object->unk0.unk34.vx == 0 && object->unk0.unk34.vz == 0) {
            object->unk16C.unk4 = 0;
            goto fall;
        }

        object->unk16C.unk4 = 1;
        step = object->unk0.unk34.vx / 2;
        object->unk0.unk34.vx -= step;
        object->unk0.position.vx += step;
        if (object->unk0.unk34.vx < 0) {
            if (object->unk0.unk34.vx >= -1) {
                object->unk0.position.vx += object->unk0.unk34.vx;
                object->unk0.unk34.vx = 0;
            }
        } else if (object->unk0.unk34.vx < 2) {
            object->unk0.position.vx += object->unk0.unk34.vx;
            object->unk0.unk34.vx = 0;
        }

        step = object->unk0.unk34.vz / 2;
        object->unk0.unk34.vz -= step;
        object->unk0.position.vz += step;
        if (object->unk0.unk34.vz < 0) {
            if (object->unk0.unk34.vz >= -1) {
                object->unk0.position.vz += object->unk0.unk34.vz;
                object->unk0.unk34.vz = 0;
            }
        } else if (object->unk0.unk34.vz < 2) {
            object->unk0.position.vz += object->unk0.unk34.vz;
            object->unk0.unk34.vz = 0;
        }

        return;
    } else if (mode == 254) {
        if ((object->unk0.position.vx & 0x7F) == 64
            && (object->unk0.position.vz & 0x7F) == 64) {
            scratch->rotation.vx = object->unk0.position.vx;
            scratch->rotation.vz = object->unk0.position.vz;
            step = object->unk0.unk34.pad;
            other = 128;
            if (step < 2) {
                other = -128;
            }

            if (step & 1) {
                scratch->rotation.vx += other;
            } else {
                scratch->rotation.vz += other;
            }

            if (func_800A3DB4(
                    scratch->rotation.vx, scratch->rotation.vz, object->unk0.position.vy)
                && func_800A6EE8(&object->unk0.position, 0, 0, 1)
                       == object->unk0.position.vy) {
                object->unk0.currentTile.x = 0xFF;
                object->unk0.currentTile.z = 0xFF;
            } else {
                goto fall;
            }
        }

        object->unk0.position.vx += object->unk0.unk34.vx;
        object->unk0.position.vz += object->unk0.unk34.vz;
        return;
    } else if (mode == 253) {
        if (!func_800B101C(object)) {
            func_800E6898(object);
            func_800E6898(object);
            func_800E4C28(object->unk0.currentTile.x, object->unk0.currentTile.z);
        }

        return;
    } else if (mode == 252) {
        u_short y;

    fall:
        object->unk0.currentTile.x = object->unk0.position.vx / 128;
        object->unk0.currentTile.z = object->unk0.position.vz / 128;
        step = func_800A6EE8(&object->unk0.position, 0, 0, 2);
        if (object->unk0.position.vy < step) {
            object->unk0.unk34.vy += 3;
            object->unk0.position.vy += object->unk0.unk34.vy;
            if (object->unk0.position.vy < step) {
                object->unk0.unk1A = 0xFC;
                goto children;
            }
        }

        y = object->unk0.position.vy;
        object->unk0.position.vy = step;
        object->unk0.unk34.vy += step - y;
        other = object->unk16C.actorId;
        if (other >= 5) {
            object->unk16C.unk0_4 = 0;
            other =
                func_800A91DC(object->unk0.currentTile.x, object->unk0.currentTile.z, 1);
            if (other) {
                other = D_800F45E0[other]->unk16C.actorId;
                if (other >= 5) {
                    if (other == object->unk16C.actorId) {
                        object->unk0.unk1A = 0xFD;
                        object->unk16C.unk4 = 0;
                        object->unk16C.unk0_4 = 2;
                        vs_main_panSfx(0x7E, 0x30, &object->unk0.position);
                    } else {
                        object->unk16C.unk0_4 = 1;
                        vs_main_panSfx(0x7E, 0x31, &object->unk0.position);
                        object->unk0.unk1A = 0;
                        func_800E6898(object);
                        func_800E4C28(
                            object->unk0.currentTile.x, object->unk0.currentTile.z);
                    }

                    goto children;
                }
            }
        }

        object->unk0.currentTile.x = object->unk0.position.vx / 128;
        object->unk0.currentTile.z = object->unk0.position.vz / 128;
        func_800E6898(object);
        func_800E4C28(object->unk0.currentTile.x, object->unk0.currentTile.z);
        if (object->unk16C.actorId == 1) {
            if (--object->unk16C.unk1 == 0) {
                object->unk0.unk1A = 0xF8;
                object->unk16C.unk4 = 0;
                return;
            }
        }

        step = object->unk0.unk1A;
        if (step == 254) {
            vs_main_panSfx(0x7E, 0x30, &object->unk0.position);
            object->unk0.unk1A = 0xFB;
            object->unk16C.unk4 = 0;
        } else if (step == 255 || step == 249) {
            object->unk0.unk1A = 0;
        } else {
            vs_main_panSfx(0x7E, 0x30, &object->unk0.position);
            object->unk0.unk1A = 0xFA;
            object->unk16C.unk4 = 0;
        }
    children:
        for (step = 0; step < 16; ++step) {
            D_800F45E0_t* child = D_800F45E0[step];

            if (child != NULL && !child->unk0.skip
                && child->unk16C.unk3 == object->unk0.unkF) {
                child->unk0.position.vy += object->unk0.unk34.vy;
                if (object->unk0.unk1A == 0) {
                    child->unk16C.unk3 = 0xFF;
                }
            }
        }

        return;
    } else if (mode == 251) {
        func_800B101C(object);
        return;
    } else if (mode == 250) {
        func_800B101C(object);
        goto children;
    } else if (mode == 249) {
        if (func_800B101C(object)) {
            return;
        }

        goto fall;
    } else if (mode == 247) {
        func_800B101C(object);
        return;
    } else if (mode == 248) {
        func_800B101C(object);
        return;
    }

    step = object->unk0.unk34.vx / object->unk0.unk1A;
    object->unk0.unk34.vx -= step;
    object->unk0.position.vx += step;
    step = object->unk0.unk34.vy / object->unk0.unk1A;
    object->unk0.unk34.vy -= step;
    object->unk0.position.vy += step;
    step = object->unk0.unk34.vz / object->unk0.unk1A;
    object->unk0.unk34.vz -= step;
    object->unk0.position.vz += step;
    if (--object->unk0.unk1A == 0 && object->unk0.unk12 == 255) {
        goto fall;
    }
}

int func_800B101C(D_800F45E0_t* object)
{
    int frame = object->unk16C.unk4;
    int value;
    int delta;

    if (frame == 0) {
        frame = 1;
    }

    value = object->unk0.unk1A;

    if (value == 253) {
        object->unk0.position.vy += D_800E91AC[frame];
        object->unk0.unk24 += D_800E91BC[frame];
        object->unk0.facing += D_800E91CC[frame];
        object->unk0.unk28 += D_800E91DC[frame];

        if (frame == 14) {
            goto complete;
        }
    } else if (value == 251) {
        value = object->unk0.unk34.pad;
        object->unk0.position.vz += D_800E91F0[frame];
        delta = D_800E91FC[frame];

        if (value == 0 || value == 3) {
            delta = -delta;
        }

        if (value & 1) {
            object->unk0.unk28 += delta;
        } else {
            object->unk0.unk24 += delta;
        }

        if (frame == 9) {
            goto complete;
        }
    } else if (value == 250) {
        object->unk0.position.vy += D_800E91EC[frame];
        object->unk0.unk34.vy = D_800E91EC[frame];

        if (frame == 3) {
            goto complete;
        }
    } else if (value == 249) {
        int orientation;

        object->unk0.position.vy += D_800E9208[frame];
        value = D_800E9218[frame];
        orientation = object->unk0.unk34.pad;
        delta = D_800E9228[frame];

        if (orientation >= 2) {
            value = -value;
        }

        if (orientation == 1 || orientation == 2) {
            delta = -delta;
        }

        if (orientation & 1) {
            object->unk0.position.vx += value;
            object->unk0.unk28 += delta;
        } else {
            object->unk0.position.vz += value;
            object->unk0.unk24 += delta;
        }

        if (frame == 14) {
            func_800A0104(object->unk0.unkF, object->unk16C.unk2);
            goto complete;
        }
    } else if (value == 248) {
        if (frame >= 9) {
            object->unk0.position.vy += 3;

            if (frame == 9) {
                vs_main_memcpy(object->unk14C, object->unk12C, sizeof object->unk14C);
                object->unk0.unk9_0 = 0xC;
            }

            if (frame == 40) {
                func_80099D6C(object->unk0.unkF);
                goto complete;
            }
        }
    } else if (value == 247) {
        object->unk0.position.vy += D_800E9238[frame];
        object->unk0.unk2C = D_800E9248[frame];
        object->unk0.unk2E = D_800E9258[frame];
        object->unk0.unk30 = D_800E9268[frame];

        if (frame == 14) {
            goto complete;
        }
    }

    object->unk16C.unk4 = frame + 1;
    return 1;

complete:
    object->unk0.unk1A = 0;
    return 0;
}

int func_800B13CC(int arg0, int arg1, int arg2)
{
    int i;
    int var_a3 = 0xBB8;

    for (i = 0; i < 16; ++i) {

        D_800F45E0_t* temp_v1 = D_800F45E0[i];

        if ((temp_v1 != NULL) && !(temp_v1->unk0.skip) && !(temp_v1->unk16C.unk0_3)
            && (temp_v1->unk0.currentTile.x == arg0)
            && (temp_v1->unk0.currentTile.z == arg1)) {

            int temp_v1_2 = temp_v1->unk0.position.vy;

            if ((arg2 < temp_v1_2) && (temp_v1_2 < var_a3)) {
                var_a3 = temp_v1_2;
            }
        }
    }

    var_a3 -= 128;

    if (var_a3 > 0) {
        var_a3 = 0;
    }

    return var_a3;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B147C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B16F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B17F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B196C);

void func_800B1A68(D_800F45E0_t* object, MATRIX* camera)
{
    D_1F80035C_t* scratch = (void*)0x1F80035C;
    u_int attachment;
    int value;

    scratch->model = object->unk0.unk68;
    gte_SetRotMatrix(camera);
    gte_SetTransMatrix(camera);
    setVector(&scratch->position, scratch->offset.vx, scratch->offset.vy + 16,
        scratch->offset.vz);
    gte_ldv0(&scratch->position);
    gte_rtv0tr2();
    attachment = object->unk16C.actorId;

    if (attachment >= 4) {
        MATRIX holderRotation;
        SVECTOR anchors[2];
        D_800F4538_t* holder;

        if (object->unk0.unk12 == 0xFF) {
            goto rotate;
        }

        holder = D_800F4538[object->unk0.unk12];
        func_800A190C(object->unk0.unk12, 0xF0, &anchors[0], 1);
        func_800A190C(object->unk0.unk12, 0xF1, &anchors[1], 1);
        gte_SetRotMatrix(camera);
        gte_SetTransMatrix(camera);
        setVector(&scratch->position, (anchors[0].vx + anchors[1].vx) / 2,
            (anchors[0].vy + anchors[1].vy) / 2, (anchors[0].vz + anchors[1].vz) / 2);
        gte_ldv0(&scratch->position);
        gte_rtv0tr2();
        setVector(&scratch->rotation, object->unk10C.vx + object->unk0.unk24,
            object->unk10C.vy + object->unk0.facing,
            object->unk10C.vz + object->unk0.unk28);
        gte_stlvnl(scratch->matrix.t);
        func_800B17F0(&scratch->rotation, &scratch->matrix);
        setVector(&scratch->rotation, holder->unk0.unk24, holder->unk0.facing,
            holder->unk0.unk28);
        func_800B17F0(&scratch->rotation, &holderRotation);
        func_800B196C(&holderRotation, &scratch->matrix);
    } else if (attachment < 2) {
        if (object->unk0.unk1A != 0) {
            setVector(&scratch->rotation, object->unk0.unk24, object->unk0.facing,
                object->unk0.unk28);
            gte_stlvnl(scratch->matrix.t);
            RotMatrixYXZ_gte(&scratch->rotation, &scratch->matrix);
            func_800B196C(camera, &scratch->matrix);
            MulMatrix(&scratch->matrix, &object->bones[4]);
            goto composed;
        }

        scratch->matrix = object->bones[4];
        gte_stlvnl(scratch->matrix.t);
    } else {
    rotate:
        copyVector(&scratch->rotation, &object->unk10C);
        gte_stlvnl(scratch->matrix.t);
        applyVector(&scratch->rotation, object->unk0.unk24, object->unk0.facing,
            object->unk0.unk28, +=);
        *(int*)&scratch->rotation &= 0x0FFF0FFF;
        *(int*)&scratch->rotation.vz &= 0xFFF;
        func_800B17F0(&scratch->rotation, &scratch->matrix);
    }

    func_800B196C(camera, &scratch->matrix);
composed:
    func_800B396C(&scratch->matrix, &D_800F3C58.scale);
    D_800F3C58.bones[0] = scratch->matrix;
    object->bones[0] = scratch->matrix;

    if (object->unk0.unk2C != 64 || object->unk0.unk2E != 64
        || object->unk0.unk30 != 64) {
        setVector(
            &scratch->scale, object->unk0.unk2C, object->unk0.unk2E, object->unk0.unk30);
        applyVector(&scratch->scale, 64, 64, 64, *=);
        func_800B396C(&scratch->matrix, &scratch->scale);
        D_800F3C58.bones[0] = scratch->matrix;
        object->bones[0] = scratch->matrix;
    }

    D_800F3C78 = scratch->matrix;
    object->bones[1] = scratch->matrix;

    if (!object->unk0.visible
        || !func_800B3A68(
            object, &object->bones[0], -vs_main_nearClip * 4, object->unk0.unk68)) {
        return;
    }

    scratch->tpage = GetTPage(0, 0, 64, 256);

    if (object->unk0.unk64.unk0 != 0 || object->unk0.unk9_0 >= 6) {
        scratch->clut = GetClut(object->unk0.unkF * 16 + 768, 255);
    } else {
        scratch->clut = GetClut(object->unk0.unkF * 16 + 768, 237);
    }

    value =
        object->unk0.unk9_0 >= 4 && object->unk0.unk9_0 < 9 && object->unk0.unk9_0 != 6;

    if (object->unk0.unk9_0 >= 12) {
        value = 1;
    }

    if (value) {
        func_800B5C30(&D_800F2458, object, &object->unk0.unk54, scratch->model);
    } else {
        func_800B4594(&D_800F2458, object, &object->unk0.unk54, scratch->model);
    }
}

void func_800B217C(vs_battle_wepModels_t* weapon, MATRIX* source)
{
    CVECTOR color;
    D_1F80035C_t* scratch = (void*)0x1F80035C;
    D_800F4538_t* actor = D_800F4538[weapon->actorId];
    int value;
    int i;

    scratch->model = (D_800F4538_unk68*)weapon->offsets;
    scratch->matrix = *source;

    if (weapon->unk13 != 0) {
        int target = weapon->unk12;
        int current = weapon->unk11;

        value = target - current;
        value /= weapon->unk13;
        weapon->unk11 = current + value;
        --weapon->unk13;

        if (weapon->unk11 == 0 && weapon->unk13 == 0) {
            weapon->unk8_4 = 0;
        }
    }

    if (weapon->unk11 != 64) {
        value = weapon->unk11;
        value *= 64;
        setVector(&scratch->scale, value, value, value);
        func_800B396C(&scratch->matrix, &scratch->scale);
    }

    D_800F3C58.bones[0] = scratch->matrix;
    weapon->unk20[0] = scratch->matrix;
    scratch->position.vx = scratch->position.vy = 0;

    for (i = 1; i < weapon->nBones; ++i) {
        int parentBone = scratch->model->armatures[i].unk4;

        scratch->parent = &weapon->unk20[parentBone];
        gte_SetRotMatrix(scratch->parent);
        gte_SetTransMatrix(scratch->parent);
        setVector(&scratch->position, -scratch->model->armatures[parentBone].unk0, 0, 0);
        gte_ldv0(&scratch->position);
        gte_rtv0tr2();
        scratch->rotation.vx = weapon->unkBoneInfo[i].vx;
        scratch->rotation.vy = weapon->unkBoneInfo[i].vy;
        scratch->rotation.vz = weapon->unkBoneInfo[i].vz;
        gte_stlvnl(scratch->matrix.t);
        *(int*)&scratch->rotation &= 0x0FFF0FFF;
        *(int*)&scratch->rotation.vz &= 0xFFF;
        func_800B17F0(&scratch->rotation, &scratch->matrix);
        func_800B196C(&D_800F3C58.bones[parentBone], &scratch->matrix);
        D_800F3C58.bones[i] = scratch->matrix;
        weapon->unk20[i] = scratch->matrix;
    }

    if (!actor->unk0.visible
        || (actor->unk0.position.vy >= 256
            && (actor->unk0.unkF == 0 || func_800BEB00() != 4))) {
        return;
    }

    if (!func_800B3A68(
            weapon, &weapon->unk20[0], -vs_main_nearClip * 4, weapon->offsets)) {
        return;
    }

    scratch->tpage = vs_battle_wepTextures[weapon->texSlot].tpage;
    scratch->clut = vs_battle_wepTextures[weapon->clutSlotOffset].clut0;
    value = actor->unk0.unk9_0 >= 4 && actor->unk0.unk9_0 < 9 && actor->unk0.unk9_0 != 6;

    if (actor->unk0.unk9_0 == 15) {
        value = 1;
    }

    if (weapon->unk8_6) {
        color.r = weapon->unk5C0;
        color.g = weapon->unk5C0;
        color.b = weapon->unk5C0;
    } else {
        memcpy(&color, &actor->unk0.unk54, sizeof color);
    }

    if (value) {
        func_800B516C(&D_800F2458, weapon, &color, scratch->model);
    } else {
        func_800B3CF0(&D_800F2458, weapon, &color, scratch->model);
    }
}

void func_800B26B8(D_800F4538_t* actor, MATRIX* parent, int bone, int saved)
{
    D_1F80035C_t* scratch = (void*)0x1F80035C;

    scratch->matrix = *(actor->unk1890 + saved - 1);
    func_800B196C(parent, &scratch->matrix);
    gte_SetRotMatrix(parent);
    gte_SetTransMatrix(parent);
    --saved;
    setVector(&scratch->position, actor->unk1890[saved].t[0], actor->unk1890[saved].t[1],
        actor->unk1890[saved].t[2]);
    gte_ldv0(&scratch->position);
    gte_rtv0tr2();
    gte_stlvnl(scratch->matrix.t);
    D_800F3C58.bones[bone] = scratch->matrix;
    actor->bones[bone] = scratch->matrix;
}
