#include "common.h"
#include "../MAINMENU.PRG/278.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/31724.h"
#include "../../BATTLE/BATTLE.PRG/2842C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/44F14.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include <memory.h>

typedef struct {
    u_short unk0;
    char unk2;
} func_8010406C_t;

typedef struct {
    u_short* unk0;
    u_short* unk4;
} func_80106390_t;

// Incomplete def, size correct
typedef struct {
    u_short pad0[13];
    u_short unk1A;
    int unk1C;
    u_short unk20;
    char pad22[92];
    u_short unk7E;
} D_8010975C_t;

typedef struct {
    int unk0;
    char unk4;
    signed char unk5;
    signed char unk6;
    signed char unk7;
    u_short unk8;
    u_short unkA;
    u_short unkC;
    u_short unkE;
    char unk10;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char unk18;
    char unk19;
    char unk1A;
    char unk1B;
    char unk1C;
    char unk1D;
    char unk1E;
    char unk1F;
    int unk20;
    int unk24;
    char unk28;
    char unk29;
    char unk2A;
    char unk2B;
    int unk2C[39];
    char unkC8;
    char unkC9[19];
    u_short unkDC;
    u_short unkDE;
    u_short unkE0;
    u_short unkE2;
    short unkE4;
    short unkE6;
    short unkE8;
    short unkEA;
    short unkEC;
    short unkEE;
    int unkF0;
    short unkF4[13];
    char unk10E;
    char unk10F;
    u_short unk110;
    u_short unk112;
    short unk114[8];
    char unk124;
    char unk125;
    short unk126;
    short unk128[16];
    short unk148[16];
} _getShieldStat_t;

void func_80102BE4(int);
int func_801053EC(int);
int func_80108088(int);
void func_80108518(int);

extern void* D_1F800000[];

extern u_short D_801093B8[];
extern int D_80109568;
extern int (*D_80109570[])(int);
extern char D_80109588[]; // size 0x30?
extern char D_801095A8[]; // size 0x40?
extern char D_801095E8[]; // size 4?
extern char D_801095EC[]; // size 8?
extern u_char* D_801095F4[]; // unknown size
extern void (*D_8010962C[])(int);
extern char D_80109649;
extern char D_8010964C;
extern char D_8010964D;
extern char D_8010964E;
extern u_char D_8010964F;
extern char D_80109650;
extern char D_80109651;
extern char D_80109652;
extern char D_80109653;
extern char D_80109654;
extern char D_8010965F;
extern char D_80109660;
extern char D_80109661;
extern char D_80109662;
extern char D_80109663;
extern char D_80109664;
extern char D_80109665;
extern char D_80109666;
extern u_char D_80109667;
extern u_char D_80109668;
extern u_char D_80109669;
extern u_char D_801096A3;
extern char D_80109710;
extern char D_80109711;
extern char D_80109712;
extern char D_80109713;
extern char D_80109714;
extern char D_80109715;
extern char D_80109716;
extern char D_80109717;
extern int D_80109718;
extern void* D_8010975C;
extern int D_80109760;
extern char D_80109764;
extern char D_80109765;
extern char D_80109766;
extern char D_80109767;

void func_8010296C(char arg0)
{
    D_80109711 = arg0;
    D_80109712 = arg0;
    D_80109713 = arg0;
}

int func_80102988(int arg0, int arg1)
{
    int temp_a1;
    int temp_s1;

    if ((vs_main_buttonsState & 0xC) != 0xC) {
        temp_s1 = arg1;
        temp_a1 = 1;
        arg0 = func_800FEA6C(arg0, 0);
        if (vs_main_buttonRepeat & 4) {
            arg1 = arg1 - temp_a1 + arg0;
        }
        if (vs_main_buttonRepeat & 8) {
            ++arg1;
        }
        if (arg1 >= arg0) {
            arg1 -= arg0;
        }
        if ((vs_main_buttonsPressed.all & 0xC) && (arg1 == temp_s1)) {
            func_800C02E0();
        }
    }
    return arg1;
}

void func_80102A3C(int arg0, int arg1)
{
    int temp_s0;
    int temp_s4;
    int i;
    u_long* var_v1;
    vs_battle_menuItem_t* temp_v0;
    int new_var;

    temp_s4 = (D_800F4EE8.unk0[58] - 1) & 7;
    if (arg0 == 4) {
        func_801013F8(0);
    }

    new_var = (arg0 * 8);
    arg0 = new_var - 0x10;
    for (i = 0; i < 8; ++i) {
        temp_s0 = (((i + 1) & 7) * 0x10) + 0x20;

        if (i == temp_s4 && arg1 == 1) {
            temp_v0 = vs_battle_getMenuItem(0x1F);
            if (temp_s0 >= (temp_v0->animSpeed - 0xC)) {
                temp_v0->flags = i + 0x18;
                continue;
            } else {
                var_v1 = func_800C0214(0x100010, temp_s0 | 0x100000);
            }
        } else {
            var_v1 =
                func_800C0224(0x80, temp_s0 | (arg0 << 0x10), 0x100010, D_1F800000[1]);
        }

        var_v1[4] = (0x78 + i * 16) | 0x8000 | ((i == temp_s4) ? 0x37FD0000 : 0x37FE0000);
    }
}

void func_80102B78(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    func_800FA8E0(0x28);
    menuItem = vs_battle_getMenuItem(0x1F);
    menuItem->state = 3;
    menuItem->x = 0x12;
    menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 2;
    menuItem->x = 0x9B;
    menuItem->selected = 1;
    menuItem->unk3A = 0;
}

void func_80102BE4(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_getMenuItem(0x1F);
    menuItem->state = 2;
    menuItem->x = 0x10;
    menuItem->unk1 = 0xA4;
    menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 3;
    menuItem->x = 0x12;
}

void func_80102C44(int arg0, int arg1)
{
    D_80109568 = 1;
    D_80109712 = 0;
    D_80109713 = 0;
    func_80102BE4(arg0);
    func_800FBBD4(arg1);
    func_800FBEA4(1);
}

void func_80102C94(int arg0, char** arg1, u_int arg2, int arg3)
{
    vs_battle_menuItem_t* temp_v0;

    vs_battle_playMenuChangeSfx();
    temp_v0 = vs_battle_setMenuItem(arg0, 0x9B, 0x12, 0xA5, 0, arg1[0]);
    temp_v0->selected = 1;
    temp_v0->flags = (arg2 >> 0x1A);
    temp_v0->unkC = (arg2 >> 0x10) & 7;
    vs_mainmenu_setMessage(arg1[1]);
    vs_battle_getMenuItem(0x1F)->unkE = arg3 + 1;
}

int func_80102D30(int arg0, int arg1)
{
    D_800F4EE8.unk0[(arg0 + 0x1E) * 2] = 0;
    D_800F4EE8.unk0[(arg0 + 0x1E) * 2 + 1] = arg1;
    return *(D_801022A8[arg0] + arg1);
}

void func_80102D7C(int arg0)
{
    vs_battle_playMenuLeaveSfx();
    func_800FA8E0(0x28);
    func_800FA810(-1);
    func_800FBBD4(-1);
    func_800FBEA4(2);
    D_80109717 = 2;
    D_80109718 = vs_main_buttonsPressed.all & 0x10;
    if (arg0 != 0) {
        vs_mainMenu_drawDpPpbars(4);
    }
}

int func_80102DEC(int arg0)
{
    char* sp10[2];
    int sp18;
    int temp_v0_2;
    int temp_v0_3;
    int i;

    if (arg0 != 0) {
        D_8010964E = arg0 >> 8;
        D_8010964F = arg0 - 1;
        func_80102B78(D_8010964E);
        D_80109650 = 0;
        D_8010964D = 0;
        D_8010964C = 0;
        return 0;
    }

    switch (D_8010964C) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80102C44(D_8010964E, 7);
            func_800FD270(D_800619D8.unk0[D_8010964F]);
            vs_mainMenu_drawDpPpbars(3);
            D_8010964C = 1;
        }
        break;
    case 1:
        if (D_8010964D < 0xA) {
            if (++D_8010964D < 6) {
                func_800FC510(D_8010964D, D_800619D8.unk0[D_8010964F], 1);
                return 0;
            }
            break;
        }
        D_8010964C = 2;
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80102D7C(1);
            D_8010964C = 3;
            break;
        }
        temp_v0_2 = func_80102988(0, D_8010964F);
        if (temp_v0_2 != D_8010964F) {
            D_8010964F = temp_v0_2;
            temp_v0_3 = func_80102D30(0, temp_v0_2);
            func_800FCA08(&D_80060148[temp_v0_3], sp10, &sp18, vs_battle_stringBuf);
            do {
                func_800FD270(temp_v0_3);
                func_80102C94(D_8010964E, sp10, sp18, temp_v0_2);
                for (i = 1; i < 6; ++i) {
                    func_800FC510(i, D_800619D8.unk0[temp_v0_2], 0);
                }
            } while (0);
        }
        break;
    case 3:
        return vs_mainmenu_ready();
        return 0;
    }
    return 0;
}

int func_80103034(int arg0)
{
    func_800FD0E0_t sp10;
    int sp18;
    int temp_v0_2;
    int temp_v0_3;

    if (arg0 != 0) {
        D_80109653 = arg0 >> 8;
        D_80109654 = arg0 - 1;
        func_80102B78(D_80109653);
        D_80109652 = 10;
        D_80109651 = 0;
        return 0;
    }

    switch (D_80109651) {
    case 0:
        if ((D_80109651 == 0) && (vs_mainmenu_ready() != 0)) {
            func_80102C44(D_80109653, 3);
            func_800FD404(D_800619D8.unk0[D_80109654 + 8]);
            vs_mainMenu_drawDpPpbars(3);
            D_80109651 = 1;
        }
        break;
    case 1:
        if (D_80109652 != 0) {
            --D_80109652;
        } else {
            D_80109651 = 2;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80102D7C(1);
            D_80109651 = 3;
            break;
        }
        temp_v0_2 = func_80102988(1, (int)D_80109654);
        if (temp_v0_2 != D_80109654) {
            D_80109654 = temp_v0_2;
            temp_v0_3 = func_80102D30(1, temp_v0_2);
            func_800FCAA4(
                &D_80060168.unk254[temp_v0_3], &sp10, &sp18, vs_battle_stringBuf);
            func_800FD404(temp_v0_3);
            func_80102C94(D_80109653, &sp10.unk0, sp18, temp_v0_2);
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

// https://decomp.me/scratch/Cy7Zo
INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103220);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80103460);

int func_801036BC(int arg0)
{
    char* sp10[2];
    int sp18;
    int temp_v0_2;
    int temp_v0_3;

    if (arg0 != 0) {
        D_80109661 = arg0 >> 8;
        D_80109662 = arg0 - 1;
        func_80102B78(D_80109661);
        D_80109660 = 0xA;
        D_8010965F = 0;
        return 0;
    }

    switch (D_8010965F) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80102C44(D_80109661, 7);
            func_800FD700(D_800619D8.unk0[D_80109662 + 48]);
            if (D_80060168.unk640[D_800619D8.unk0[D_80109662 + 48] - 1].category != 7) {
                vs_mainMenu_drawDpPpbars(1);
            }
            D_8010965F = 1;
        }
        break;
    case 1:
        if (D_80109660 != 0) {
            --D_80109660;
        } else {
            D_8010965F = 2;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80102D7C(1);
            D_8010965F = 3;
            break;
        }
        temp_v0_2 = func_80102988(4, D_80109662);
        if (temp_v0_2 != D_80109662) {
            D_80109662 = temp_v0_2;
            temp_v0_3 = func_80102D30(4, temp_v0_2);
            vs_mainMenu_setAccessoryStrings(
                &D_80060780[temp_v0_3], sp10, &sp18, vs_battle_stringBuf);
            func_800FD700(temp_v0_3);
            func_80102C94(D_80109661, sp10, sp18, temp_v0_2);
            return 0;
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_801038E4(int arg0)
{
    func_800FD0E0_t sp10;
    int sp18;
    int temp_v0_2;
    int temp_v0_3;

    if (arg0 != 0) {
        D_80109665 = arg0 >> 8;
        D_80109666 = arg0 - 1;
        func_80102B78(D_80109665);
        D_80109664 = 0xA;
        D_80109663 = 0;
        return 0;
    }
    switch (D_80109663) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80102C44(D_80109665, 3);
            func_800FD878(D_800619D8.unk0[D_80109666 + 64]);
            D_80109663 = 1;
        }
        break;
    case 1:
        if (D_80109664 != 0) {
            D_80109664 -= 1;
        } else {
            D_80109663 = 2;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80102D7C(0);
            D_80109663 = 3;
            D_80109718 = vs_main_buttonsPressed.all & 0x10;
            break;
        }
        temp_v0_2 = func_80102988(5, D_80109666);
        if (temp_v0_2 != D_80109666) {
            D_80109666 = temp_v0_2;
            temp_v0_3 = func_80102D30(5, temp_v0_2);
            func_800FD0E0(
                &D_80060168.unk8A4[temp_v0_3], &sp10, &sp18, vs_battle_stringBuf);
            func_800FD878(temp_v0_3);
            func_80102C94(D_80109665, (void*)&sp10, sp18, temp_v0_2);
            return 0;
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_80103AD0(int arg0)
{
    int var_s0 = 0;
    int new_var;
    if (arg0 != 0) {
        var_s0 = arg0 >> 4;
        D_80109667 = arg0 & 0xF;
        D_80109717 = 1;
        D_80109718 = 0;
        func_800FDD78();
        vs_battle_getMenuItem(0x1F)->unkE = var_s0 & 0xFF;
        func_800FFA88(0);
    }
    var_s0 = D_80109570[D_80109667](var_s0);
    new_var = var_s0 != 0;
    if (new_var) {
        if (D_80109718 == 0) {
            D_80109712 = 1;
            D_80109717 = 0;
            D_80109713 = 1;
            D_80109568 = 0;
            func_800FFA88(2);
            return var_s0;
        }
        return -2;
    }
    if (vs_mainmenu_ready() != 0) {
        D_801022D5 = D_801024B8 != 9;
        func_801013F8(1);
        func_800FDEBC();
    }
    return var_s0;
}

INCLUDE_RODATA("build/src/MENU/MENU3.PRG/nonmatchings/16C", D_80102800);

int func_80103BE4(int arg0, vs_battle_weaponInfo* weapon)
{
    switch (arg0) {
    case 0:
        return -weapon->blade.category;
    case 1:
        return -weapon->blade.material;
    case 2:
        return weapon->range;
    case 3:
        return -weapon->unk10E;
    case 4:
        return weapon->currentDp;
    case 5:
        return weapon->maxDp;
    case 6:
        return weapon->currentPp;
    case 7:
        return weapon->maxPp;
    case 8:
        return weapon->currentStr;
    case 9:
        return weapon->currentInt;
    case 10:
        return weapon->currentAgility;
    default:
        if (arg0 >= 0x11) {
            return weapon->classAffinityCurrent.affinity[0][arg0 - 0x11];
        }
        return weapon->classAffinityCurrent.class[0][arg0 - 0xB];
    }
}

void func_80103CC8(int arg0)
{
    vs_battle_weaponInfo sp10;
    char sp1A8[8];
    int temp_v0;
    int i;
    int var_s3;
    int var_s4;
    int temp_s0;
    vs_battle_droppedWeapon* new_var2 = D_80060168.unk0;
    char* new_var = D_800619D8.unk0;

    vs_battle_rMemzero(sp1A8, 8);
    var_s4 = 0;

    while (1) {
        var_s3 = 0x80000000;

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                func_8006AEAC(&sp10, &new_var2[temp_s0 - 1]);
                temp_v0 = func_80103BE4(arg0, &sp10);
                if (var_s3 < temp_v0) {
                    var_s3 = temp_v0;
                }
            }
        }

        if (var_s3 == 0x80000000) {
            break;
        }

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                func_8006AEAC(&sp10, &new_var2[temp_s0 - 1]);
                if (func_80103BE4(arg0, &sp10) == var_s3) {
                    sp1A8[var_s4++] = temp_s0;
                    new_var[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(new_var, sp1A8, 8);
}

int _getShieldStat(int arg0, vs_battle_shieldInfo* shield)
{
    switch (arg0) {
    case 1:
        return -shield->shield.material;
    case 4:
        return shield->currentPp;
    case 5:
        return shield->maxPp;
    case 6:
        return shield->currentDp;
    case 7:
        return shield->maxDp;
    case 8:
        return shield->currentStr;
    case 9:
        return shield->currentInt;
    case 10:
        return shield->currentAgility;
    default:
        if (arg0 < 33) {
            return shield->classAffinityCurrent.class[0][arg0 - 27];
        }
        if (arg0 >= 40) {
            return shield->types[arg0 - 39];
        }
        return shield->classAffinityCurrent.affinity[0][arg0 - 33];
    }
}

void func_80103F00(int arg0)
{
    vs_battle_shieldInfo shield;
    char sp1A8[8];
    int temp_v0;
    int i;
    int var_s3;
    int var_s4;
    int temp_s0;
    vs_battle_droppedShield* new_var2 = (vs_battle_droppedShield*)D_80060168.unk100;
    char* new_var = D_800619D8.unk28;

    vs_battle_rMemzero(sp1A8, sizeof sp1A8);
    var_s4 = 0;

    while (1) {
        var_s3 = 0x80000000;

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                func_8006B02C(&shield, &new_var2[temp_s0 - 1]);
                temp_v0 = _getShieldStat(arg0, &shield);
                if (var_s3 < temp_v0) {
                    var_s3 = temp_v0;
                }
            }
        }

        if (var_s3 == 0x80000000) {
            break;
        }

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                func_8006B02C(&shield, &new_var2[temp_s0 - 1]);
                if (_getShieldStat(arg0, &shield) == var_s3) {
                    sp1A8[var_s4++] = temp_s0;
                    new_var[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(new_var, sp1A8, 8);
}

int func_8010406C(int arg0, func_8010406C_t* arg1)
{
    if (arg0 == 0) {
        return -arg1->unk0;
    }
    return arg1->unk2;
}

void func_8010408C(int arg0)
{
    char sp10[0x40];
    int temp_v0;
    int i;
    int var_s3;
    int var_s4;
    int temp_s0;
    u_short(*new_var2)[128] = &D_80060168.unkE00;
    char* new_var = D_800619D8.unk70;

    vs_battle_rMemzero(sp10, 0x40);
    var_s4 = 0;

    while (1) {
        var_s3 = 0x80000000;

        for (i = 0; i < 0x40; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                temp_v0 = func_8010406C(arg0, (void*)(*new_var2 + ((temp_s0 * 2) - 2)));
                if (var_s3 < temp_v0) {
                    var_s3 = temp_v0;
                }
            }
        }

        if (var_s3 == 0x80000000) {
            break;
        }

        for (i = 0; i < 0x40; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                if (func_8010406C(arg0, (void*)(*new_var2 + ((temp_s0 * 2) - 2)))
                    == var_s3) {
                    sp10[var_s4++] = temp_s0;
                    new_var[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(new_var, sp10, 0x40);
}

int func_801041CC(int arg0, vs_battle_equipment* arg1)
{
    switch (arg0) {
    case 0:
        return -arg1->category;
    case 1:
        return -arg1->material;
    case 2:
        return arg1->range.unk0;
    case 3:
        return -arg1->damageType;
    case 4:
        return arg1->currentDp;
    case 5:
        return arg1->maxDp;
    case 6:
        return arg1->currentPp;
    case 7:
        return arg1->maxPp;
    case 8:
        return arg1->strength;
    case 9:
        return arg1->intelligence;
    case 10:
        return arg1->agility;
    default:
        if (arg0 >= 0x1B) {
            arg0 -= 0x10;
        }
        if (arg0 < 0x11) {
            return *(((signed char*)&arg1->gemSlots) + arg0);
        }
        if (arg0 >= 0x18) {
            return *(((signed char*)&arg1->strength) + arg0);
        }
        return *(((signed char*)&arg1->index) + arg0);
    }
}

void func_801042C4(vs_battle_equipment* arg0, int arg1, int arg2)
{
    switch (arg1) {
    case 1:
        func_8006AB44(arg0, &D_80060168.unk280[arg2]);
        return;
    case 2:
        func_8006AC74(arg0, &D_80060168.unk540[arg2]);
        return;
    case 4:
        func_8006ACFC(arg0, &D_80060168.unk640[arg2]);
        return;
    case 5:
        func_8006AE0C(arg0, &D_80060168.unk8C0[arg2]);
        return;
    }
}

void func_8010439C(int arg0, int arg1)
{
    vs_battle_equipment sp10;
    int temp_v0;
    int i;
    int var_s3;
    int var_s5;
    char* temp_s6;
    int temp_s0;
    int temp_s4;

    var_s5 = 0;
    temp_s4 = D_801022A0[arg0];
    {
        char spVLA[temp_s4];
        temp_s6 = D_801022A8[arg0];
        vs_battle_rMemzero(spVLA, temp_s4);

        while (1) {
            var_s3 = 0x80000000;
            for (i = 0; i < temp_s4; ++i) {
                temp_s0 = temp_s6[i];
                if (temp_s0 != 0) {
                    func_801042C4(&sp10, arg0, temp_s0 - 1);
                    temp_v0 = func_801041CC(arg1, &sp10);
                    if (var_s3 < temp_v0) {
                        var_s3 = temp_v0;
                    }
                }
            }

            if (var_s3 == 0x80000000) {
                break;
            }

            for (i = 0; i < temp_s4; ++i) {
                temp_s0 = temp_s6[i];
                if (temp_s0 != 0) {
                    func_801042C4(&sp10, arg0, temp_s0 - 1);
                    if (func_801041CC(arg1, &sp10) == var_s3) {
                        spVLA[var_s5++] = temp_s0;
                        temp_s6[i] = 0;
                    }
                }
            }
        }
        vs_battle_memcpy(temp_s6, spVLA, temp_s4);
    }
}

int func_80104530(int arg0)
{
    char* sp10[48];
    int spD0[24];
    int i;
    u_char* temp;

    if (arg0 != 0) {
        D_80109669 = arg0 - 1;
        D_80109668 = 0;
        return 0;
    }
    switch (D_80109668) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            temp = D_801095F4[D_80109669];
            for (i = 0; i < D_801095EC[D_80109669]; ++i) {
                sp10[i * 2] =
                    (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[temp[i] * 2
                                                                      + 0x1B6]];
                sp10[i * 2 + 1] =
                    (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[temp[i] * 2
                                                                      + 0x1B7]];
                spD0[i] = 0;
            }
            func_800FF0EC(i, D_80109669 + 0x2D, sp10, spD0);
            D_80109668 = 1;
        }
        break;
    case 1:
        func_800FF43C();
        i = func_800FF360();
        if ((i + 1) != 0) {
            if (i >= 0) {
                vs_battle_playMenuSelectSfx();
                switch (D_80109669) {
                case 0:
                    func_80103CC8(D_80109588[i]);
                    break;
                case 3:
                    func_80103F00(D_801095A8[i]);
                    break;
                case 6:
                    func_8010408C(D_801095E8[i]);
                    break;
                default:
                    func_8010439C(D_80109669, D_801095F4[D_80109669][i]);
                    break;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i + 1;
        }
        break;
    default:
        break;
    }
    return 0;
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104788);

int func_80104EC0(int arg0, int arg1)
{
    int var_v1;

    var_v1 = 0;
    if (arg0 == 1) {
        var_v1 = D_80060168.unk280[arg1].unk2A;
    }
    if (arg0 == 2) {
        var_v1 = D_80060168.unk540[arg1].unkC;
    }
    if (arg0 == 5) {
        var_v1 = D_80060168.unk8C0[arg1].unk18;
        if (var_v1 & 0x80) {
            var_v1 = 0;
        }
    }
    return var_v1;
}

int func_80104F50(int arg0, int arg1)
{
    u_short var_v1;

    var_v1 = 0;
    if (arg0 == 5) {
        var_v1 = D_80060168.unk8C0[arg1].unk18;
        if (!(var_v1 & 0x80)) {
            var_v1 = 0;
        }
    }
    return var_v1 & 0x7F;
}

// https://decomp.me/scratch/oTNTS
INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80104F94);

void func_80105314(int arg0)
{
    int i;
    vs_battle_menuItem_t* temp_v0;

    while (D_801023D0 < 16) {
        func_80100A5C();
    }

    for (i = 20; i < 40; ++i) {
        temp_v0 = vs_battle_getMenuItem(i);
        if (temp_v0->state == 2) {
            temp_v0->state = 1;
            temp_v0->animSpeed = temp_v0->x;
        }
        temp_v0->selected = (i ^ (D_800F4EE8.unk0[(arg0 + 0x1E) * 2] + 0x14)) == 0;
    }
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_801053EC);

void func_80106390(int arg0, func_80106390_t* arg1, int* arg2)
{
    int i;
    int j;
    vs_battle_menuItem_t* temp_v0;
    u_short* v;

    D_80109765 = arg0;
    D_80109766 = 0;
    D_80109760 = 0;
    D_80109764 = 1;
    if (D_8010975C && D_8010975C) { }

    D_8010975C = vs_main_allocHeapR(arg0 << 7);

    for (i = 0; i < arg0; ++i) {
        ((D_8010975C_t*)D_8010975C)[i].unk1C = arg2[i];

        v = arg1[i].unk0;
        if (v != NULL) {
            for (j = 0; j < 13; j++) {
                ((u_short*)D_8010975C)[i * 64 + j] = v[j];
            }

            ((D_8010975C_t*)D_8010975C)[i].unk1A = 0xE7E7;
        } else {
            ((u_short*)(i * 128 + D_8010975C))[0] = 0xE7E7;
        }

        v = arg1[i].unk4;
        if (v != NULL) {
            ((D_8010975C_t*)D_8010975C)[i].unk20 = 0xF8;
            for (j = 0; j < 46; ++j) {
                ((u_short*)(D_8010975C))[i * 64 + j + 17] = v[j];
            }
            ((D_8010975C_t*)D_8010975C)[i].unk7E = 0xE7E7;
        } else {
            ((D_8010975C_t*)D_8010975C)[i].unk20 = 0xE7E7;
        }
    }

    j = *arg2;
    temp_v0 = vs_battle_setMenuItem(0x14, 0x9B, 0x12, 0xA5, 0, (char*)D_8010975C);
    temp_v0->unk7 = j & 1;
    temp_v0->flags = j >> 0x1A;
    temp_v0->unkC = (j >> 0x10) & 7;
    temp_v0->selected = 1;
    D_80109767 = (j >> 0x13) & 0x7F;
}

int func_80106574(void) { return D_8010975C != NULL ? -1 : D_80109760; }

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_8010659C);

void func_80106BB4(int arg0)
{
    vs_battle_accessoryInfo accessory;
    int i;

    vs_mainMenu_resetStats();

    if (arg0 != 0) {
        func_8006B194(
            &accessory, (vs_battle_droppedArmor*)(D_80102468 + ((arg0 * 10) - 10)));

        for (i = 0; i < 16; ++i) {
            vs_mainMenu_equipmentStats[i] = accessory.classes[i & 7];
            vs_mainMenu_equipmentStats[i + 16] = accessory.affinities[i & 7];
            vs_mainMenu_equipmentStats[i + 32] = accessory.types[i & 7];
        }
        vs_mainMenu_setStrIntAgi(
            accessory.currentStr, accessory.currentInt, accessory.currentAgility, 2);
    }
    vs_mainMenu_equipmentSubtype = 0x20;
    D_801024A1 = arg0;
    func_800FBB8C(7);
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80106C94);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80107148);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80107620);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80107B14);

void func_80108010(int arg0)
{
    if (arg0 != 0) {
        if (arg0 == 8) {
            D_801096A3 = 3;
        } else {
            if (arg0 >= 3) {
                arg0 -= 2;
                D_801096A3 = 0;
            } else {
                D_801096A3 = arg0;
            }
        }
    }
    D_8010962C[D_801096A3](arg0);
}

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80108088);

INCLUDE_ASM("build/src/MENU/MENU3.PRG/nonmatchings/16C", func_80108518);

int func_80108970(char* arg0)
{
    int temp_s1;
    int var_s0;
    char temp_a1;
    char temp_a1_2;
    char temp_v0;
    vs_battle_menuItem_t* temp_v0_3;

    temp_v0 = *arg0;
    switch (temp_v0) {
    case 3:
        func_8010296C(0);
        func_800FBD80(0x10);
        D_80109714 = 0;
        D_80109715 = 0;
        D_80109716 = 0;
        D_80109717 = 0;
        if (vs_mainMenu_itemNames == NULL) {
            vs_mainMenu_loadItemNames(1);
        }
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_8008A4DC(0);
        func_800FFBC8();
        func_800CB654(1);
        D_800EB9B0 = 0x200000;
        func_80108518(1);
        func_801053EC(D_80109649 + 1);
        D_80109649 = 0;
        *arg0 = 4;
        // Fallthrough
    case 4:
        if (vs_mainMenu_loadItemNames(0) == 0) {
            break;
        }
        *arg0 = 5;
        // Fallthrough
    case 5:
        var_s0 = func_801053EC(0);
        if (var_s0 == 0) {
            break;
        }
        if (var_s0 > 0) {
            switch (var_s0) {
            case 1:
                func_80108088(1);
                D_801023E3 = 0;
                *arg0 = 6;
                break;
            case 2:
                D_80109568 = 3;
                func_800FA8E0(0x28);
                D_80109711 = 0;
                D_80109712 = 0;
                D_80109713 = 0;
                *arg0 = 7;
                break;
            case 3:
                func_8010296C(0);
                func_800FA8E0(0x28);
                func_8008A4DC(1);
                vs_battle_executeAbilityType = 0xD;
                *arg0 = 0xC;
                func_800CB654(0);
                D_800EB9B0 = 0;
                func_80108518(2);
                break;
            }
        } else {
            if (var_s0 == -2) {
                *arg0 = 0xA;
                break;
            } else {
                *arg0 = 9;
                func_8010296C(0);
                func_800FA8E0(0x28);
                func_8008A4DC(1);
                func_800CB654(0);
                D_800EB9B0 = 0;
                func_80108518(2);
                break;
            }
        }
        break;
    case 6:
        var_s0 = func_80108088(0);
        if (var_s0 != 0) {
            if (var_s0 == -2) {
                D_80109711 = 0;
                D_80109714 = 0;
                *arg0 = 0xA;
                break;
            }
            D_80109712 = 1;
            D_80109717 = 0;
            D_80109713 = 1;
            func_801053EC(1);
            *arg0 = 5;
        }
        break;
    case 7:
        if (vs_mainmenu_ready() != 0) {
            func_80108518(2);
            *arg0 = 8;
            temp_a1 = vs_battle_menuState.currentState;
            vs_battle_menuState.currentState = 0xD;
            vs_battle_menuState.returnState = temp_a1;
            D_800F4EA0 |= 0x200;
        }
        break;
    case 8:
        if (D_800F51C1 != 0) {
            func_80100414(-4, 0x80);
            func_8008A4DC(1);
            func_8010296C(0);
            func_800FA8E0(0x28);
            func_800CB654(0);
            D_800EB9B0 = 0;
            D_80109710 = 0xA;
            *arg0 = 0xB;
        } else if (vs_mainmenu_ready() != 0) {
            func_8010296C(0);
            D_80109714 = 0;
            D_80109715 = 0;
            D_80109716 = 0;
            D_80109717 = 0;
            func_80108518(1);
            func_801053EC(1);
            *arg0 = 5;
        }
        break;
    case 9:
        func_800FFB68(0);
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            if (func_800FE694() != 0) {
                *arg0 = 0;
                return 1;
            }
        }
        break;
    case 10:
        func_8008A4DC(1);
        func_8010296C(0);
        func_800FA8E0(0x28);
        func_800CB654(0);
        D_800EB9B0 = 0;
        func_80108518(2);
        D_80109710 = 0xA;
        *arg0 = 0xB;
        break;
    case 11:
        func_800FFB68(0);
        func_800FFBA8();
        func_800FFA88(0);
        if (D_80109710 != 0) {
            D_80109710 -= 1;
            break;
        }
        if (vs_mainmenu_ready() != 0) {
            if (func_800FE694() != 0) {
                vs_battle_menuState.currentState = 4;
                *arg0 = 0;
                return 1;
            }
        }
        break;
    case 12:
        func_800FFB68(0);
        func_800FFBA8();
        func_800FFA88(0);
        if (D_801022D8 == 0) {
            if (func_800FE694() != 0) {
                D_800F4E98.unk2 = 8;
                temp_a1_2 = (char)vs_battle_menuState.currentState;
                vs_battle_menuState.currentState = 4;
                vs_battle_menuState.returnState = (char)temp_a1_2;
                *arg0 = 0;
                return 1;
            }
        }
        break;
    case 13:
        D_80109649 = 1;
        *arg0 = 0;
        break;
    }
    if (D_80109711 != 0) {
        if (D_80109714 < 0xAU) {
            D_80109714 += 1;
        }
        var_s0 = vs_battle_rowAnimationSteps[0xA - D_80109714];
    } else {
        if (D_80109714 != 0) {
            D_80109714 -= 1;
        }
        var_s0 = (0xA - D_80109714) << 5;
    }
    if ((D_80109714 != 0) && (D_80109717 == 0)) {
        temp_s1 = (D_800F4EE8.unk3A[0] - 1) & 7;
        temp_v0_3 = vs_battle_setMenuItem(
            0x1F, var_s0 + 0xB4, 0x22, 0x8C, 8, (char*)&D_801093B8[D_801093B8[temp_s1]]);
        temp_v0_3->selected = 1;
        if (temp_s1 != 7) {
            temp_v0_3->unk12 = D_801022A0[temp_s1];
            temp_v0_3->unk10 = func_800FEA6C(temp_s1, 0);
        }
    }
    func_80108518(0);
    if (D_80109712 != 0) {
        if (D_80109715 < 4U) {
            D_80109715 += 1;
        }
    } else if (D_80109715 != 0) {
        D_80109715 -= 1;
    }
    func_80102A3C(D_80109715, D_80109717);
    if (D_80109713 != 0) {
        if (D_80109716 < 0xAU) {
            D_80109716 += 1;
        }
        var_s0 = vs_battle_rowAnimationSteps[0xA - D_80109716];
    } else {
        if (D_80109716 != 0) {
            D_80109716 -= 1;
        }
        var_s0 = (0xA - D_80109716) << 5;
    }
    if (D_80109716 != 0) {
        func_80100344(0x10 - var_s0, 0x26, 0x58, 0xA);
        vs_mainmenu_drawButton(1, 8 - var_s0, 0x24, NULL);
        func_800C6540("STATUS", ((0x1C - var_s0) & 0xFFFF) | 0x260000,
            0x202020 << D_80109713, NULL);
    }
    return 0;
}
