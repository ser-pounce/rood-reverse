#include "common.h"
#include "../SLUS_010.40/main.h"
#include "../BATTLE/BATTLE.PRG/2842C.h"
#include "../BATTLE/BATTLE.PRG/3A1A0.h"
#include "../BATTLE/BATTLE.PRG/40564.h"
#include "../BATTLE/BATTLE.PRG/44F14.h"

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC[0x168];
    int unk5AC;
    int unk5B0;
    int unk5B4;
    char unk5B8;
    char unk5B9;
    char unk5BA;
    char unk5BB;
    short unk5BC;
    short unk5BE;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    char unk5CC;
    char unk5CD;
    short unk5CE;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0[0x40];
    char unk6E0;
    char unk6E1;
    char unk6E2;
    char unk6E3;
    int unk6E4[8];
    char unk704[0x550];
    char unkC54[0x540];
    short unk1194;
    short unk1196;
    int unk1198[0x1B9];
    int unk187C;
} D_800F4538_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    char unk10;
    char unk11;
} D_800F4588_t;

extern D_800F4538_t* D_800F4538;
extern D_800F4538_t* D_800F453C;
extern D_800F4588_t* D_800F4588[];
extern char D_800F49DC;

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9A78);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9CB0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9E0C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/278", func_800F9EB8);

int func_800FA188(int arg0, int arg1, int* arg2)
{
    D_800F45E0_t* temp_v1;
    int temp_a3;
    int i;
    int var_t2;
    int var_t3;

    var_t2 = 0;
    var_t3 = 0;
    for (i = 0; i < 16; ++i) {
        temp_v1 = D_800F45E0[i];
        if (temp_v1 != 0) {
            temp_a3 = temp_v1->unk8;
            if (!(temp_v1->unk8 & 1) && !(temp_a3 & 0xF00) && (temp_v1->unk1A == 0)
                && (temp_v1->unk5C == arg0) && (temp_v1->unk5E == arg1)) {
                if ((temp_v1->unk16C & 0x30) == 0x20) {
                    var_t3 = 1;
                } else {
                    var_t2 -= 0x80;
                }
            }
        }
    }
    *arg2 = var_t2;
    return var_t3;
}

int func_800FA238(int arg0, int arg1, int arg2)
{
    D_800F45E0_t* new_var2;
    int temp_a3;
    int i;
    int new_var = arg2 + 0x80;

    for (i = 0; i < 16; ++i) {
        new_var2 = D_800F45E0[i];
        if ((D_800F45E0[i] != 0) && (temp_a3 = D_800F45E0[i]->unk8, !(temp_a3 & 1))
            && (!(temp_a3 & 0xF00)) && (D_800F45E0[i]->unk5C == arg0)
            && (new_var2->unk5E == arg1) && (D_800F45E0[i]->unk1E >= arg2)
            && (new_var >= D_800F45E0[i]->unk1E)) {
            return 1;
        }
    }
    return 0;
}

void func_800FA2CC()
{
    u_short* sp10;
    int i;
    int i_2;
    char* temp_s0;
    D_800F4538_t* temp_s1;
    D_800F4588_t* temp_v1;
    D_800F4588_t** var_a0;

    temp_s1 = D_800F4538;

    for (i = 0; i < 2; ++i) {
        D_800F4588_t* var_a0 = D_800F4588[i];
        if (var_a0 != 0) {
            if (temp_s1->unk8 & 0x800000) {
                var_a0->unk11 = 0x40;
                var_a0->unk8 |= 0x10;
            } else {
                var_a0->unk11 = 0;
            }
        }
    }

    func_8009E634(temp_s1, i);

    i_2 = 1;
    if (temp_s1->unk8 & 0x800000) {
        i_2 = 0x65;
    }

    temp_s1->unk5B8 = i_2;
    temp_s1->unk5AC = temp_s1->unk5AC & 0xFFEFFFFF;
    temp_s1->unk187C = func_800AD494(temp_s1, i_2, &sp10);
    temp_s1->unk6E3 = D_800F49DC;
    temp_s0 = temp_s1->unkC54;
    temp_s1->unk5BC = *sp10;
    func_800AD008(temp_s1, temp_s0);
    func_800AFA28(temp_s1, temp_s0, 1);
    vs_main_memcpy(temp_s1->unk704, temp_s0, 0x550U);
    temp_s1->unk1194 = 0;
    temp_s1->unk6E0 = 0;
    temp_s1->unk5CD = 0;
    temp_s1->unk5CC = 0;
}

void func_800FA3FC(int arg0)
{
    func_8007C8F8_t sp10;

    func_8009CC20(0, 0);
    sp10.unk0 = 7;
    sp10.unk1 = 0;
    sp10.unk2 = arg0;
    sp10.unk10 = 0;
    func_800995E8(&sp10);
}
