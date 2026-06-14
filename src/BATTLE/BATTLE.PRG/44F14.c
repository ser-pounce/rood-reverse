#include "common.h"
#include "44F14.h"
#include "3A1A0.h"
#include "../../SLUS_010.40/main.h"

void func_800AF844(D_800F4538_unkC54*, D_800F4538_unkC54*, int);
void func_800B147C(D_800F4538_unkC54*, D_800F4538_unkC54*, int, int, int);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AD714);

void func_800AE46C(void) { }

void func_800AE474(void) { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE47C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/44F14", func_800AE4FC);

void func_800AE68C(int arg0, int arg1) { func_800AE4FC(D_800F4538[arg0], arg1 + 4); }

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

void func_800AF6E8(void* arg0)
{
    D_800F4538_t* actor = (D_800F4538_t*)arg0;
    int v5b2;
    int next;
    int fa2;
    int fa3;

    func_800AFA28(actor, &actor->unkC54, 0);
    if (actor->unk5CC != 0) {
        if (actor->unk5CC == 1) {
            func_800AF844(&actor->unk704, &actor->unkC54, actor->unk0);
        }
        v5b2 = actor->unk5B2;
        if (v5b2 != 1) {
            next = actor->unk5CC + 0xFF;
            actor->unk5CC = v5b2 + next;
            if ((u_int)((v5b2 + next) & 0xFF) >= actor->unk5CD) {
                actor->unk5CC = 0;
                actor->unk5CD = 0;
                goto tail;
            }
        }
        func_800B147C(
            &actor->unk704, &actor->unkC54, actor->unk0, actor->unk5CC, actor->unk5CD);
        fa2 = (actor->unk704.unk548 & 0xFFFEFFFF)
            | ((((u_short*)&actor->unkC54.unk548)[1] & 1) << 16);
        actor->unk704.unk548 = fa2;
        fa3 = (fa2 & 0xFFFDFFFF) | (actor->unkC54.unk548 & 0x20000);
        actor->unk704.unk548 = fa3;
        func_800B002C(actor, 0, fa2, fa3);
        actor->unk5CC++;
        if (actor->unk5CC >= actor->unk5CD) {
            actor->unk5CC = 0;
            actor->unk5CD = 0;
        }
    } else {
    tail:
        vs_main_memcpy(&actor->unk704, &actor->unkC54, sizeof(actor->unk704));
        func_800B002C(actor, 0);
    }
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
