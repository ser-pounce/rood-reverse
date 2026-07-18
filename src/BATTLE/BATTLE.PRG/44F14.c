#include "common.h"
#include <rand.h>
#include "146C.h"
#include "3A1A0.h"
#include "44F14.h"
#include "../../SLUS_010.40/main.h"

void func_800AF844(D_800F4538_unkC54*, D_800F4538_unkC54*, int);
void func_800B147C(D_800F4538_unkC54*, D_800F4538_unkC54*, int, int, int);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AD714);

void func_800AE46C(void) { }

void func_800AE474(void) { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE47C);

void func_800AE4FC(D_800F4538_unk0* arg0, int arg1)
{
    D_800F4538_t* actor;
    int temp;
    int sp[2];
    int type = arg1;

    if (arg0->position.vy >= 0xBB8) {
        return;
    }

    actor = D_800F4538[arg0->unkF];

    if (actor->unk17E4.unk0 == 2) {
        sp[0] = 0x80;
        sp[1] = 0;
    } else {
        if ((*((int*)&actor->unk0.nQuads + 1) & 0x3F9F00) != 0x8000) {
            func_800A1280(arg0->unkF, 0xFF, &actor->unk6FC, 0);
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
        func_8006CD60(arg0->unk68->akaoOffset, sp[0], sp[1]);
    } else if (type == 4) {
        func_800461CC(0x7E, arg0->unk68->akaoOffset, rand() % 4 + 4, sp[0], sp[1]);
    } else {
        func_800461CC(0x180, arg0->unk68->akaoOffset, type, sp[0], sp[1]);
    }
}

void func_800AE68C(int arg0, int arg1)
{
    func_800AE4FC(&D_800F4538[arg0]->unk0, arg1 + 4);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE6C0);

void func_800AE7D8(void* arg0, int arg1, int arg2)
{
    SVECTOR* temp_s0;

    temp_s0 = arg0 + 0x1C;
    vs_main_panSfx(0x7E, arg1, temp_s0);
    if (arg2 != 0) {
        vs_main_panSfx(0x7E, arg2, temp_s0);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE828);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE980);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AEAE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AECA0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AEEC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AEF94);

void func_800AF6E8(D_800F4538_t* arg0)
{
    func_800AFA28(arg0, &arg0->unkC54, 0);

    if (arg0->unk5CC != 0) {
        int v5b2;

        if (arg0->unk5CC == 1) {
            func_800AF844(&arg0->unk704, &arg0->unkC54, arg0->unk0.nBones);
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AF844);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AF960);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AFA28);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AFDE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B002C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B07DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B0908);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B101C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B13CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B147C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B16F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B17F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B196C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B1A68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B217C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800B26B8);
