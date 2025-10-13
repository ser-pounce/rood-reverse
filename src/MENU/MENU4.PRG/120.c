#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/278.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/58578.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../assets/MENU/MENU4.PRG/status.h"
#include "../../SLUS_010.40/31724.h"
#include <libetc.h>
#include "gpu.h"
#include "../../assets/MENU/MENU4.PRG/status.h"
#include "../../assets/MENU/ITEMHELP.BIN.h"

typedef struct {
    int unk0[8];
} D_80108198_t;

typedef struct {
    int unk0[13];
} D_801081B8_t;

typedef struct {
    u_short unk0;
    u_short unk2;
    int unk4;
    char unk8;
    char unk9;
    u_short unkA;
    int unkC[9];
} func_80104DFC_t2;

typedef struct {
    int unk0[11];
    char unk2C;
    char unk2D;
    short unk2E;
    int unk30[6];
    func_80104DFC_t2 unk48[2];
} func_80104DFC_t;

extern u_long* D_1F800000[];

static u_short _statusStrings[] = {
#include "../../assets/MENU/MENU4.PRG/status.vsString"
};

static void _drawWeaponInfo(vs_battle_weaponInfo* weapon)
{
    int i;

    D_80102545 = 1;
    func_800FD220();
    func_800FBD0C(0, 0, 0, 1);

    if (weapon->blade.id != 0) {
        vs_battle_memcpy(D_801024C0, &weapon->classAffinityCurrent,
            sizeof weapon->classAffinityCurrent);
        vs_battle_memcpy(D_801024C0 + 0x30, &weapon->classAffinityBaseline,
            sizeof weapon->classAffinityBaseline);
        D_801024C0[0x3F] = weapon == &vs_battle_characterState->unk3C->weapon;
        for (i = 0; i < 4; ++i) {
            D_801024C0[i + 0x20] = weapon->grip.types[i];
        }

        do {
            D_80102508 = weapon->unk10E;
        } while (0);

        vs_mainMenu_setDpPp(
            weapon->currentDp, weapon->maxDp, weapon->currentPp, weapon->maxPp);
        func_800FBD28(weapon->currentStr, weapon->currentInt, weapon->currentAgility, 1);

        D_801024A8[1].strength = weapon->baseStr;
        D_801024A8[1].intelligence = weapon->baseInt;
        D_801024A8[1].agility = weapon->baseAgility;
        func_800FBD0C(weapon->range, weapon->risk, 0, 1);
    }
    func_800FBB8C(7);
}

static void _drawShieldInfo(vs_battle_shieldInfo* shield)
{
    int i;

    D_80102545 = 8;
    func_800FD220();

    if (shield->unk18.id != 0) {
        vs_battle_memcpy(D_801024C0, &shield->classAffinityCurrent,
            sizeof shield->classAffinityCurrent);
        vs_battle_memcpy(D_801024C0 + 0x30, &shield->classAffinityBaseline,
            sizeof shield->classAffinityBaseline);
        D_801024C0[63] = shield == &vs_battle_characterState->unk3C->shield;
        for (i = 0; i < 4; ++i) {
            D_801024C0[i + 0x20] = shield->types[i];
        }

        vs_mainMenu_setDpPp(
            shield->currentPp, shield->maxPp, shield->currentDp, shield->maxDp);
        func_800FBD28(shield->currentStr, shield->currentInt, shield->currentAgility, 1);
        D_801024A8[1].strength = shield->baseStr;
        D_801024A8[1].intelligence = shield->baseInt;
        D_801024A8[1].agility = shield->baseAgility;
    }
    func_800FBB8C(7);
}

static void _drawArmorInfo(vs_battle_armorInfo* armor)
{
    int i;

    D_80102545 = 16;
    func_800FD220();

    if (armor->unk0.id != 0) {
        vs_battle_memcpy(
            D_801024C0, &armor->classAffinityCurrent, sizeof armor->classAffinityCurrent);
        vs_battle_memcpy(D_801024C0 + 0x30, &armor->classAffinityBaseline,
            sizeof armor->classAffinityBaseline);
        D_801024C0[0x3F] = 0;
        for (i = 0; i < 5; ++i) {
            D_801024C0[0x3F]
                |= armor == &vs_battle_characterState->unk3C->hitLocations[i].unk20;
        }

        for (i = 0; i < 4; ++i) {
            D_801024C0[i + 0x20] = armor->types[i];
        }

        vs_mainMenu_setDpPp(armor->currentDp, armor->maxDp, 0, 0);
        func_800FBD28(armor->currentStr, armor->currentInt, armor->currentAgility, 1);
        D_801024A8[1].strength = armor->baseStr;
        D_801024A8[1].intelligence = armor->baseInt;
        D_801024A8[1].agility = armor->baseAgility;
    }
    func_800FBB8C(7);
}

static void _drawAccessoryInfo(vs_battle_accessoryInfo* accessory)
{
    int i;

    D_80102545 = 32;
    func_800FD220();

    if (accessory->unk0.id != 0) {
        for (i = 0; i < 16; ++i) {
            D_801024C0[i] = accessory->classes[i & 7];
            D_801024C0[i + 16] = accessory->affinities[i & 7];
            D_801024C0[i + 32] = accessory->types[i & 7]; // BUG? Copies past end
        }
        func_800FBD28(
            accessory->currentStr, accessory->currentInt, accessory->currentAgility, 2);
    }
    func_800FBB8C(7);
}

static void _drawBladeInfo(vs_battle_weaponInfo* weapon)
{
    int i;
    vs_battle_equipment* blade = &weapon->blade;

    D_80102545 = 2;

    for (i = 0; i < 16; ++i) {
        D_801024C0[i] = blade->classes[i & 7];
        D_801024C0[i + 16] = blade->affinities[i & 7];
    }
    vs_mainMenu_setDpPp(blade->currentDp, blade->maxDp, weapon->currentPp, weapon->maxPp);
    func_800FBD28(blade->strength, blade->intelligence, blade->agility, 1);
    func_800FBD0C(blade->range, blade->cost, 0, 1);
    func_800FBB8C(3);
    func_800FC268(0xB);
}

static void _drawGripInfo(vs_battle_equipment* grip)
{
    int i;

    D_80102545 = 4;

    for (i = 0; i < 4; ++i) {
        D_801024C0[i + 0x20] = grip->types[i];
    }
    func_800FBD28(grip->strength, grip->intelligence, grip->agility, 1);
    func_800FBB8C(4);
    func_800FC268(8);
}

static void _drawGemInfo(vs_battle_equipment* gem)
{
    int i;

    D_80102545 = 64;

    for (i = 0; i < 16; ++i) {
        D_801024C0[i] = gem->classes[i & 7];
        D_801024C0[i + 16] = gem->affinities[i & 7];
    }
    func_800FBD28(gem->strength, gem->intelligence, gem->agility, 1);
    func_800FBB8C(3);
    func_800FC268(8);
}

static void _initBladeInfo(
    vs_battle_equipment* blade, D_800F4E8C_t** arg1, int* arg2 __attribute__((unused)))
{
    vs_battle_stringContext[19] = vs_mainMenu_itemNames[blade->material + 253];
    vs_battle_stringContext[18]
        = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[blade->category
            + VS_ITEMHELP_BIN_INDEX_dagger - 1]];
    vs_battle_stringContext[17]
        = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[blade->damageType
            + VS_ITEMHELP_BIN_INDEX_blunt - 1]];
    vs_battle_stringContext[16] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
            [D_80102140[blade->category - 1] + VS_ITEMHELP_BIN_INDEX_oneHanded]];
    func_800C685C(func_800C685C(D_800F4E8C,
                      (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[blade->id - 1]]),
        (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_weaponDescTemplate]);
    arg1[1] = D_800F4E8C;
}

static void _initGripInfo(
    vs_battle_equipment* grip, D_800F4E8C_t** arg1, int* arg2 __attribute__((unused)))
{
    u_short* gripId = &grip->id;
    D_800F51A4 = &vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[grip->category
        + VS_ITEMHELP_BIN_INDEX_shortGrip - 1]];
    func_800C685C(func_800C685C(D_800F4E8C,
                      (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[*gripId - 6]]),
        (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_gripTemplate]);
    arg1[1] = D_800F4E8C;
}

static void _initGemInfo(
    vs_battle_equipment* gem, D_800F4E8C_t** arg1, int* arg2 __attribute__((unused)))
{
    vs_battle_memcpy(D_800F4E8C,
        &vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[gem->id - 0x8C]], sizeof *D_800F4E8C);
    arg1[1] = D_800F4E8C;
}

static char* _hitLocationStates[]
    = { "DYING", "BAD", "AVERAGE", "GOOD", "EXCELLENT", NULL };

static char* _drawWeaponInfoRow(int row, vs_battle_weaponInfo* weapon)
{
    char* sp10[2];
    int sp18;
    u_short* temp_s0_2;

    sp10[1] = (char*)&vs_mainMenu_itemHelp[0x340E];
    switch (row) {
    case 0:
        func_800FC85C(weapon, sp10, &sp18, D_800F4E8C);
        sp10[0] = (char*)weapon;
        break;
    case 1:
        _initBladeInfo(&weapon->blade, (D_800F4E8C_t**)sp10, &sp18);
        _drawBladeInfo(weapon);
        break;
    case 2:
        _initGripInfo(&weapon->grip, (D_800F4E8C_t**)sp10, &sp18);
        _drawGripInfo(&weapon->grip);
        break;
    case 3:
    case 4:
    case 5:
        if (weapon->gems[row - 3].id != 0) {
            _initGemInfo(&weapon->gems[row - 3], (D_800F4E8C_t**)sp10, &sp18);
            _drawGemInfo(&weapon->gems[row - 3]);
        } else {
            func_800FC268(8);
            func_800FD220();
        }
        break;
    }
    vs_battle_getMenuItem(row + 0x14)->selected = 1;
    return sp10[1];
}

static char* _drawShieldInfoRow(int row, vs_battle_shieldInfo* shield)
{
    char* sp10[2];
    int sp18;
    u_short* temp_s0;

    sp10[1] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noGems];
    if (row == 0) {
        func_800FCCE8(shield, sp10, &sp18, D_800F4E8C);
    } else if (row < 0) {

    } else if (row < 4) {
        if (shield->gems[row - 1].id != 0) {
            _initGemInfo(&shield->gems[row - 1], (D_800F4E8C_t**)&sp10, &sp18);
            _drawGemInfo(&shield->gems[row - 1]);
        } else {
            func_800FC268(8);
            func_800FD220();
        }
    }
    vs_battle_getMenuItem(row + 20)->selected = 1;
    return sp10[1];
}

static char* _drawArmorInfoRow(vs_battle_armorInfo* arg0)
{
    char* sp10[2];
    int sp18;

    func_800FCECC(arg0, sp10, &sp18, D_800F4E8C);
    return sp10[1];
}

static char* _drawAccessoryInfoRow(vs_battle_accessoryInfo* arg0)
{
    char* sp10[2];
    int sp18[10];
    int sp30[2];

    func_8006BADC(sp18, arg0);
    func_800FD084(sp18, sp10, sp30, D_800F4E8C);
    return sp10[1];
}

static int func_8010341C(int arg0, int arg1)
{
    int ret;
    int v0;
    int v1;

    ret = 0;
    switch (arg0) {
    case 0:
        ret = (arg1 >> 5) & 1;
        break;
    case 1:
        ret = (arg1 >> 6) & 1;
        break;
    case 5:
    case 6:
    case 7:
        ret = D_801024B9 != 2;
        break;
    case 8:
        ret = D_801024B9 == 1;
        break;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        v1 = arg0 - 9;
        v0 = arg1 & 0xF;
        ret = (v0 < v1) ^ 1;
        break;
    case 16:
    case 17:
        ret = (arg1 >> 4) & 1;
        break;
    case 2:
    case 3:
    case 4:
    case 18:
    case 19:
    case 20:
        ret = 1;
        break;
    }
    return ret;
}

static int func_801034BC(int arg0, int arg1)
{
    int direction;
    int var_s2;

    direction = 0;
    var_s2 = arg0;
    if (vs_main_buttonRepeat & PADLup) {
        direction = 1;
    } else if (vs_main_buttonRepeat & PADLdown) {
        direction = 2;
    } else if (vs_main_buttonRepeat & PADLleft) {
        direction = 3;
    } else if (vs_main_buttonRepeat & PADLright) {
        direction = 4;
    }
    if (direction != 0) {
        arg0 = D_8010214C[direction - 1 + var_s2 * 4];
    }

    while (1) {
        if (func_8010341C(arg0, arg1) != 0) {
            break;
        }
        if (var_s2 == arg0) {
            if ((u_int)(arg0 - 2) < 14) {
                do {
                    --arg0;
                } while (func_8010341C(arg0, arg1) == 0);
                return arg0;
            }
            do {
                ++arg0;
            } while (func_8010341C(arg0, arg1) == 0);
            return arg0;
        }
        var_s2 = arg0;
        arg0 = D_8010214C[direction - 1 + var_s2 * 4];
    }
    return arg0;
}

static int _xPos = 0;
static int _yPos = 0;
static int D_801080A4 = 0;
static int _selectedActor = 0;
static int D_801080AC = 0;
static int D_801080B0 = 0;
static int D_801080B4 = 0;
static char D_801080B8 = 0;
static char D_801080B9 = 0;
static char D_801080BA = 0;
static char D_801080BB = 0;

static void func_80103608(int arg0)
{
    if (arg0 == 0) {
        D_801080B8 = 1;
        D_801080BA = 4;
    } else if (D_801080BB == 0) {
        func_800CB654(1);
        D_801080B8 = 4;
        D_801080BA = 4;
    } else {
        D_801080B8 = 2;
        D_801080BA = 4;
    }
    D_801080BB = arg0;
}

static int func_80103688(int arg0, int arg1)
{
    int temp_a0;

    while (1) {
        arg0 = (arg0 + arg1) % 15;
        temp_a0 = func_800A0BE0(arg0);
        if ((vs_battle_actors[arg0] != 0) && (vs_battle_actors[arg0]->unk1C < 5)
            && (temp_a0 & 0x01000001) == 1) {
            break;
        }
    }
    return arg0;
}

static char D_801080BC = 0;
static u_int D_801080C0 = 0;

static int func_80103744(int arg0)
{
    if (arg0 != 0) {
        if (_selectedActor == 0) {
            D_801080C0 = 1;
        } else {
            vs_battle_playSfx10();
            D_801080C0 = 0;
        }
        if (arg0 & 0x10) {
            D_801080C0 += 3;
        }
        _selectedActor = arg0 & 0xF;
        vs_battle_setMenuItem(
            4, 0xB4, 0x12, 0x8C, 8, (char*)vs_battle_actors[_selectedActor - 1]->unk3C)
            ->selected
            = 1;
        return 0;
    }
    switch (D_801080C0) {
    case 0:
        if (D_801080B4 < 160) {
            D_801080AC = 1;
            D_801080B4 += 32;
        } else {
            D_801080AC = 0;
            func_800F9E0C();
        case 1:
            D_801080B0 = 1;
            func_800F9A24(_selectedActor - 1);
            D_801080BC = 1;
            D_801080B4 = -160;
            D_801080C0 = 2;
        }
        break;
    case 2:
        if (D_801080B4 < 0) {
            D_801080B4 += 32;
            break;
        }
        D_801080B0 = 0;
        D_801080C0 = 6;
        return 1;
    case 3:
        if (D_801080B4 >= -159) {
            D_801080B0 = 1;
            D_801080B4 -= 32;
            break;
        }
        func_800F9E0C();
    case 4:
        D_801080B0 = 0;
        func_800F9A24(_selectedActor - 1);
        D_801080BC = 1;
        D_801080B4 = 160;
        D_801080C0 = 5;
        break;
    case 5:
        if (D_801080B4 > 0) {
            D_801080AC = 1;
            D_801080B4 -= 32;
            break;
        }
        D_801080AC = 0;
        D_801080C0 = 6;
        return 1;
    case 6:
        return 1;
    }
    return 0;
}

static void func_8010399C(int rgb, int arg1, u_long* nextPrim)
{
    int i;

    if (arg1 != 0) {
        for (i = 0; i < 3; ++i) {
            vs_battle_setSprite(128, rgb, vs_getWH(6, 9), nextPrim)[4] = 0x37F400E4;
            rgb -= 5;
        }
        func_800C9950(2, rgb, 0, nextPrim);
        rgb -= 7;
    }

    rgb += 0xFFFF0000;

    for (i = 0; i < 3; ++i) {
        vs_battle_setSprite(128, rgb, vs_getWH(7, 10), nextPrim)[4] = 0x37F400EA;
        rgb -= 6;
    }
}

static void _drawStatBar(int index, int current, int max, int xy)
{

    if (max == 0) {
        current = 0;
        max = 1;
    }

    if ((index >> 8) == 0) {
        current = max;
    }

    current <<= 6;

    vs_battle_drawStatBar(
        index & 0xFF, ((current + max) - 1) / max, D_1F800000[1] - 3, xy);
}

static void func_80103AC8(void)
{
    int temp_s2;
    int i;
    vs_battle_actor2* temp_v0_2;
    u_long* temp_s4;
    vs_battle_actor2* var_s3;

    var_s3 = vs_battle_actors[_selectedActor - 1]->unk3C;
    temp_s4 = D_1F800000[1] - 3;
    switch (D_801080B8) {
    case 0:
        break;
    case 1:
        if (D_801080B9 == 0) {
            if (D_801080BA == 0) {
                func_800CB654(0);
                D_801080B8 = 0;
            } else {
                --D_801080BA;
            }
        } else {
            --D_801080B9;
            var_s3 = vs_battle_actors[D_801080A4 - 1]->unk3C;
        }
        break;
    case 2:
        if (D_801080B9 != 0) {
            --D_801080B9;
            var_s3 = vs_battle_actors[D_801080A4 - 1]->unk3C;
        } else if (D_801080BA == 0) {
            D_801080B8 = 3;
        } else {
            --D_801080BA;
        }
        break;
    case 3:
        if (D_801080B9 < 4) {
            ++D_801080B9;
        } else {
            D_801080B8 = 0;
        }
        break;
    case 4:
        if (D_800EB9B0 == 0x200000) {
            if (D_801080BA == 0) {
                D_801080B8 = 3;
            } else {
                --D_801080BA;
            }
        }
        break;
    }
    if (D_801080B9 != 0) {
        temp_s2 = ((D_801080B9 * 8) - 0x16) << 0x10;
        if (var_s3->unk954 & 0x20000) {
            i = func_800C9950(0, temp_s2 | 0x42, var_s3->maxHP, temp_s4);
            func_800C9950(2, i, 0, temp_s4);
            func_800C9950(1, i + 0xFFFEFFF9, var_s3->currentHP, temp_s4);
            i = func_800C9950(0, temp_s2 | 0x88, var_s3->maxMP, temp_s4);
            func_800C9950(2, i, 0, temp_s4);
            func_800C9950(1, i + 0xFFFEFFF9, var_s3->currentMP, temp_s4);
            temp_s2 += 0xF0000;
            func_800C9950(1, temp_s2 | 0x40, var_s3->unk20, temp_s4);
            temp_s2 += 0x10000;
        } else {
            func_8010399C(temp_s2 | 0x42, 1, temp_s4);
            func_8010399C(temp_s2 | 0x88, 1, temp_s4);
            temp_s2 += 0x100000;
            func_8010399C(temp_s2 | 0x40, 0, temp_s4);
        }

        for (i = 0; i < 3; ++i) {
            temp_v0_2 = func_800C0224(0x180, D_800EBBEC[i] + ((D_801080B9 - 4) << 0x13),
                *(i + D_800EBBFC) | 0x90000, temp_s4);
            temp_v0_2->unk10 = D_800EBC00[i] | 0x37F60000;
        }
        temp_s2 += 0xFFF80000;
        i = (var_s3->unk954 >> 9) & 0x100;
        _drawStatBar(i, var_s3->currentHP, var_s3->maxHP, temp_s2 | 10);
        _drawStatBar(i | 1, var_s3->currentMP, var_s3->maxMP, temp_s2 | 80);
        temp_s2 += 0x40000;
        _drawStatBar(i | 2, var_s3->unk20, 0x64, temp_s2 | 10);
    }
}

static void func_80103E58(int arg0, int arg1, int arg2)
{
    u_int temp_v0;
    u_long* temp_a0;
    u_long* temp_t1;

    temp_t1 = D_1F800000[2];
    temp_a0 = D_1F800000[0];
    temp_v0 = D_800EBC54[arg0] >> arg2;
    temp_a0[0] = (*temp_t1 & 0xFFFFFF) | 0x06000000;
    temp_a0[1] = temp_v0 | 0x60000000;
    temp_a0[2] = arg1;
    temp_a0[3] = 0x70007;
    temp_a0[4] = (temp_v0 * 2) | 0x60000000;
    temp_a0[5] = arg1 + 0x10001;
    temp_a0[6] = 0x50005;
    *temp_t1 = ((u_long)temp_a0 << 8) >> 8;
    D_1F800000[0] = temp_a0 + 7;
}

static void func_80103EF8(int arg0, int arg1, int arg2, int arg3)
{
    int temp_t2;
    int temp_v0;
    u_long* temp_a2;
    u_long* temp_t0;
    int t4;

    arg3 = (0x687018 << arg3) | ((33 - arg3) << 25);
    temp_t2 = arg0 * 16 + 42;
    arg0 = ((arg1 >> 16) - temp_t2);

    temp_a2 = D_1F800000[0];
    temp_t0 = D_1F800000[1];

    t4 = (short)arg1;

    if (arg0 < 0) {
        arg0 = -arg0;
    }
    arg0 = (arg0 * 3) >> 1;

    temp_a2[0] = (temp_t0[-1] & 0xFFFFFF) | 0x08000000;
    temp_a2[1] = 0xE1000000;
    temp_a2[2] = arg3;
    temp_a2[3] = arg1;
    temp_v0 = ((t4 + ((arg0 * 2) / 3)) & 0xFFFF) | (temp_t2 << 0x10);
    temp_a2[4] = temp_v0;
    temp_a2[5] = (temp_t0[-1] & 0xFFFFFF) | 0x03000000;
    temp_a2[6] = arg3;
    temp_a2[7] = temp_v0;
    temp_a2[8] = (temp_t2 << 0x10) | 0xD8;
    temp_t0[-1] = (((u_long)temp_a2 << 8) >> 8);
    temp_a2 += 9;
    D_1F800000[0] = temp_a2;
}

static void func_80103FEC(vs_battle_actor2* arg0, int arg1)
{
    int temp_a0;
    int temp_s1;
    int temp_s2;
    u_int temp_s6;
    int temp_v1;
    int i;
    int var_s3;

    temp_s6 = vs_battle_getStatusFlags(arg0);
    var_s3 = 0;
    for (i = 0; i < 32; ++i) {
        temp_a0 = var_s3 & 7;
        if ((temp_s6 >> i) & 1) {
            int new_var = 16;
            temp_v1 = var_s3 >> 3;
            ++var_s3;
            temp_a0 *= 16;
            temp_s2 = temp_a0 - (arg1 - new_var);
            temp_s1 = ((temp_v1 * new_var) + 144) << new_var;
            if (i >= new_var) {
                func_800C0224(
                    128, ((temp_s2 + 8) & 0xFFFF) | temp_s1, 0x80008, D_1F800000[1] - 2)
                    ->unk10
                    = ((((i & 3) * 8) + 0x3068) | 0x37FF0000);
            }
            arg0 = func_800C0224(
                0x80, (temp_s2 & 0xFFFF) | temp_s1, 0x100010, D_1F800000[1] - 2);

            arg0->unk10
                = (D_800EBC14[i] | (((0x0F0F906A >> i) & 1) ? 0x37F90000 : 0x37F80000));
        }
    }
}

static char _activeStatusModifiers[32];
static u_char _selectedStatusModifier;
static u_char _statusModifierCount;
static char _0[2];
static vs_battle_actor2* _statusModifersCurrentTarget;
static char _1[8];
static int D_80108168[6];
static char D_80108180;
static char D_80108181;
static char D_80108182;
static char D_80108183;
static char D_80108184;
static u_char D_80108185;
static char _2[2];
static int D_80108188;
static char _3[12];
static D_80108198_t D_80108198;
static D_801081B8_t D_801081B8;
static u_char D_801081EC;
static u_char _selectedRegion;
static char D_801081EE;
static char _4[24];

static int _navigateStatusModifiers(vs_battle_actor2* target, int arg1)
{
    static char D_801080C4 = 0;

    int yPos;
    int xPos;

    if (target != NULL) {
        xPos = vs_battle_getStatusFlags(target);
        if (xPos == 0) {
            return 1;
        }
        _statusModifersCurrentTarget = target;
        _statusModifierCount = 0;
        for (yPos = 0; yPos < 32; ++yPos) {
            if ((xPos >> yPos) & 1) {
                _activeStatusModifiers[_statusModifierCount++] = yPos;
            }
        }
        if (arg1 == 0) {
            if (_selectedStatusModifier >= _statusModifierCount) {
                _selectedStatusModifier = _statusModifierCount - 1;
            }
        } else if (_selectedRegion == 11) {
            _selectedStatusModifier = 0;
        } else {
            if (_statusModifierCount < 8) {
                _selectedStatusModifier = _statusModifierCount - 1;
            } else {
                _selectedStatusModifier = 7;
            }
        }
    } else {
        arg1 = 1;
        if (vs_main_buttonsPressed.all & PADRup) {
            return 2;
        }

        if (vs_main_buttonsPressed.all & PADRdown) {
            return 3;
        }
        if (vs_main_buttonsState & PADRleft) {
            xPos = vs_battle_mapStickDeadZone(vs_main_stickPosBuf.rStickX);
            yPos = vs_battle_mapStickDeadZone(vs_main_stickPosBuf.rStickY);
            if (xPos == 0) {
                if (yPos == 0) {
                    if (vs_main_buttonsState & PADLup) {
                        yPos = -64;
                    }
                    if (vs_main_buttonsState & PADLdown) {
                        yPos = 64;
                    }
                    if (vs_main_buttonsState & PADLleft) {
                        xPos = -64;
                    }
                    if (vs_main_buttonsState & PADLright) {
                        xPos = 64;
                    }
                }
            }
            _xPos += xPos;
            _yPos -= yPos;
            if (_yPos < 0) {
                _yPos = 0;
            }

            if (_yPos > 896) {
                _yPos = 896;
            }
            return 0;
        }
        yPos = _selectedStatusModifier;
        if (vs_main_buttonRepeat & PADLup) {
            if (yPos < 8) {
                vs_battle_playMenuChangeSfx();
                _selectedRegion = 11;
                return 1;
            }
            yPos -= 8;
        }
        if (vs_main_buttonRepeat & PADLdown) {
            if ((_statusModifierCount >= 8) && (yPos < 8)) {
                yPos += 8;
                if (yPos >= _statusModifierCount) {
                    yPos = _statusModifierCount - 1;
                }
            }
        }
        if (vs_main_buttonRepeat & PADLleft) {
            if (yPos & 7) {
                --yPos;
            }
        }
        if (vs_main_buttonRepeat & PADLright) {
            if (((yPos & 7) == 7) || (yPos == _statusModifierCount - 1)) {
                vs_battle_playMenuChangeSfx();
                _selectedRegion = 6;
                return 1;
            }
            if (++yPos >= _statusModifierCount) {
                yPos = _statusModifierCount - 1;
            }
        }

        if (yPos != _selectedStatusModifier) {
            vs_battle_playMenuChangeSfx();
            _selectedStatusModifier = yPos;
        }
    }
    vs_mainmenu_setMessage((char*)&_statusStrings[_statusStrings
            [_activeStatusModifiers[_selectedStatusModifier] + VS_status_INDEX_strDown]]);
    if (arg1 != 0) {
        D_801080C4 = func_800FFCDC(D_801080C4,
            (((_selectedStatusModifier & 7) * 16) + 2)
                | ((((_selectedStatusModifier >> 3) * 16) + 136) << 0x10));
        D_801022D5 = 1;
    }
    return 0;
}

static int _getHitLocationCount(int actor)
{
    int i;

    for (i = 0; i < 6; ++i) {
        if (vs_battle_actors[actor]->unk3C->hitLocations[i].nameIndex == 0) {
            break;
        }
    }
    return i;
}

static int func_8010455C(void)
{
    return _getHitLocationCount(_selectedActor - 1) + 2
        + (vs_battle_actors[_selectedActor - 1]->unk3C->accessory.unk0.id != 0);
}

static char D_801080C5 = 0;
static u_char D_801080C6 = 0;

static int func_801045B8(int arg0)
{
    int sp10[2];
    vs_battle_actor2* sp18;
    vs_battle_equipment_hitLocations* hitLocation;
    int hitLocationCount;
    int sp20;
    int sp24;
    int temp_s6;
    int hitLocationState;
    int i;
    int step;

    sp18 = vs_battle_actors[D_801080C6]->unk3C;
    hitLocationCount = _getHitLocationCount(D_801080C6);
    if (arg0 != 0) {
        if (arg0 > 0) {
            D_800F4F6A = arg0 - 1;
            return 0;
        }
        if (arg0 == -3) {
            return D_801080C5;
        }
        if (arg0 == -2) {
            D_801080C5 = 3;
        } else {
            D_801080C6 = _selectedActor - 1;
            func_800FBD80(D_801080C6);
            for (i = 0; i < 6; ++i) {
                D_80108168[i] = 12 + i;
            }
            D_801080C5 = 1;
        }
        return 0;
    }
    switch (D_801080C5) {
    case 0:
        break;
    case 1:
        func_80103FEC(sp18, vs_battle_rowAnimationSteps[D_80108168[0]]);
        for (i = 0; i < hitLocationCount; ++i) {
            hitLocation = &sp18->hitLocations[i];
            step = D_80108168[i];
            vs_battle_renderTextRaw(vs_battle_hitlocations[hitLocation->nameIndex],
                (vs_battle_rowAnimationSteps[step] + 0xD8) | (0x22 + i * 0x10) * 0x10000,
                0);
            hitLocationState = vs_battle_getHitLocationState(hitLocation);
            func_80103E58(hitLocationState,
                (vs_battle_rowAnimationSteps[step] + 0xD8) | (0x24 + i * 0x10) * 0x10000,
                0);
            vs_battle_renderTextRaw(_hitLocationStates[hitLocationState],
                (vs_battle_rowAnimationSteps[step] + 0xE0) | (0x22 + i * 0x10) * 0x10000,
                0);
            if (step < 8) {
                func_800A13EC(1, hitLocation->unk5, sp10, 0);
                func_80103EF8(i, sp10[0], 8 - step, 0);
            }
            hitLocationState = 0;
            if (step != 0) {
                D_80108168[i] = step - 1;
            } else {
                hitLocationState = 1;
            }
        }

        if (hitLocationState != 0) {
            D_801080C5 = 2;
        }
        break;
    case 2:
        func_80103FEC(sp18, 0);

        step = D_800F4F6A;
        for (i = 0; i < hitLocationCount; ++i) {
            hitLocation = &sp18->hitLocations[i];
            temp_s6 = step >> 7;
            sp20 = step - 0x80;
            sp24 = temp_s6 - 1;
            func_800C6540(vs_battle_hitlocations[hitLocation->nameIndex],
                (0x22 + i * 0x10) * 0x10000 | 0xD8,
                i == sp20 ? 0x808080 >> sp24 : 0x808080 >> temp_s6, 0);
            hitLocationState = vs_battle_getHitLocationState(hitLocation);
            func_80103E58(hitLocationState, (0x24 + i * 0x10) * 0x10000 | 0xD8,
                temp_s6 - (i == sp20));
            func_800C6540(_hitLocationStates[hitLocationState],
                (0x22 + i * 0x10) * 0x10000 | 0xE0,
                i == sp20 ? 0x808080 >> sp24 : 0x808080 >> temp_s6, 0);
            func_800A13EC(1, hitLocation->unk5, sp10, 0);
            if (!(step & 0x80) && ((D_801080B0 | D_801080AC) == 0)) {
                func_80103EF8(i, sp10[0], 8, i == step);
            }
        }
        break;
    case 3:
        func_80103FEC(sp18, D_80108168[0] << 5);

        for (i = 0; i < hitLocationCount; ++i) {
            if (D_80108168[i] < 8) {
                hitLocation = &sp18->hitLocations[i];
                ++D_80108168[i];
                vs_battle_renderTextRaw(vs_battle_hitlocations[hitLocation->nameIndex],
                    ((D_80108168[i] << 5) + 0xD8) | (0x22 + i * 0x10) * 0x10000, 0);
                hitLocationState = vs_battle_getHitLocationState(hitLocation);
                func_80103E58(hitLocationState,
                    ((D_80108168[i] << 5) + 0xD8) | (0x24 + i * 0x10) * 0x10000, 0);
                vs_battle_renderTextRaw(_hitLocationStates[hitLocationState],
                    ((D_80108168[i] << 5) + 0xE0) | (0x22 + i * 0x10) * 0x10000, 0);
            } else {
                D_801080C5 = 0;
            }
        }
        break;
    }
    return 0;
}

static void func_80104AEC(int id)
{
    vs_battle_menuItem_t* menuItem;

    func_800FA8A0(4);
    menuItem = vs_battle_getMenuItem(id + 10);
    menuItem->state = 2;
    menuItem->x = 155;
    menuItem->selected = 1;
    menuItem->unk3A = 0;
}

static void func_80104B38(int arg0)
{
    char weaponType;
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_setMenuItem(32, -164, 18, 164, 8,
        (char*)&_statusStrings[_statusStrings[arg0 < 2 ? arg0 + VS_status_INDEX_weapon
                                                       : VS_status_INDEX_armor]]);

    menuItem->state = 5;
    menuItem->x = 16;
    menuItem->selected = 1;

    weaponType = 28;

    if (arg0 == 0) {
        weaponType = 24;
    } else if (arg0 == 1) {
        weaponType = 27;
    }
    menuItem->weaponType = weaponType;
    menuItem = vs_battle_getMenuItem(arg0 + 10);
    menuItem->state = 3;
    menuItem->x = 0x12;
}

static void func_80104C0C(int arg0, int arg1)
{
    func_80104B38(arg0);
    func_800FBBD4(arg1);
    func_800FBEA4(1);
}

static void func_80104C40(int arg0, vs_battle_weaponInfo* arg1, int arg2)
{
    func_800FD0E0_t sp18;
    int sp20[12];
    int sp50[4];
    func_800FD17C_t sp60;
    int dummy[6];
    int sp80;
    int var_s1;
    vs_battle_menuItem_t* temp_v0;
    int v1;

    var_s1 = 0x9E;

    v1 = arg1->grip.gemSlots;

    if (arg0 == 1) {
        func_8006B57C(sp20, &arg1->blade);
        func_800FCAA4(sp20, &sp18, &sp80, D_800F4E8C);
    } else if (arg0 == 2) {
        func_8006B6AC(sp50, &arg1->grip);
        func_800FCC0C(sp50, &sp18, &sp80, D_800F4E8C);
    } else {
        var_s1 = arg0 - 3;
        if (var_s1 < v1) {
            sp18.unk4 = 0;
            sp18.unk0 = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_none];
            sp80 = 0x58000000;
            if (arg1->gems[var_s1].id != 0) {
                func_8006B728(&sp60, &arg1->gems[var_s1]);
                func_800FD0E0(&sp60, (func_800FD0E0_t*)&sp18, &sp80, D_800F4E8C);
            }
            var_s1 = 0x97;
        } else {
            var_s1 = 0;
        }
    }

    func_800FFB90(arg0 + 0x14);

    if (var_s1 != 0) {
        temp_v0 = vs_battle_setMenuItem(
            arg0 + 0x14, 0x140 - var_s1, (arg0 * 0x10) + 0x12, var_s1, 0, sp18.unk0);
        temp_v0->unk7 = sp18.unk4 == 0;
        if (arg2 & 1) {
            temp_v0->animSpeed = 0x140;
            temp_v0->state = 2;
            temp_v0->x = 0x140 - var_s1;
        }
        temp_v0->weaponType = (char)((u_int)sp80 >> 0x1A);
        temp_v0->unkC = ((sp80 & 0xFFFF0000) >> 16) & 7;
    }
}

static void func_80104DFC(int arg0, func_80104DFC_t* arg1, int arg2)
{
    func_800FD0E0_t sp18;
    func_800FD17C_t sp20;
    int sp40;
    int var_s0;
    vs_battle_menuItem_t* temp_v0;
    int dummy[6] __attribute__((unused));

    var_s0 = arg0 - 1;

    if (var_s0 < arg1->unk2D) {
        sp18.unk4 = 0;
        sp18.unk0 = (char*)&vs_mainMenu_itemHelp[0x340B];
        sp40 = 0x58000000;
        if (arg1->unk48[var_s0].unk0 != 0) {
            func_8006B728(&sp20, &arg1->unk48[var_s0].unk0);
            func_800FD0E0(&sp20, &sp18, &sp40, D_800F4E8C);
        }
        var_s0 = 0x97;
    } else {
        var_s0 = 0;
    }

    func_800FFB90(arg0 + 0x14);
    if (var_s0 != 0) {
        temp_v0 = vs_battle_setMenuItem(
            arg0 + 0x14, 0x140 - var_s0, (arg0 * 0x10) + 0x12, var_s0, 0, sp18.unk0);
        temp_v0->unk7 = sp18.unk4 == 0;
        if (arg2 & 1) {
            temp_v0->animSpeed = 0x140;
            temp_v0->state = 2;
            temp_v0->x = 0x140 - var_s0;
        }
        temp_v0->weaponType = 0x16;
    }
}

static void func_80104F2C(int arg0)
{
    vs_battle_playMenuLeaveSfx();
    func_800FA8E0(0x28);
    func_800FA810(0);
    func_800FBBD4(-1);
    func_800FBEA4(2);
    if (arg0 != 0) {
        func_800FC268(4);
    }
}

static char D_801080C7 = 0;

static int func_80104F80(int arg0)
{
    char* sp18[2];
    int sp20[9];
    u_int sp48;
    int temp_s4;
    int var_a0;
    int var_a0_5;
    int var_s0_2;
    int i;
    int var_s2;
    int var_v0_4;
    char* var_s3;
    int temp_s0_4;
    vs_battle_actor2* temp_s1;
    vs_battle_menuItem_t* menuItem;
    unsigned char s0;

    temp_s1 = vs_battle_actors[_selectedActor - 1]->unk3C;

    if (arg0 != 0) {
        D_80108181 = arg0 - 1;
        D_801080B8 = 0;
        func_800CB654(1);
        func_80104AEC((int)D_80108181);
        func_800FFA88(0);
        D_80108183 = 9;
        D_80108182 = 0;
        D_80108180 = 0;
        return 0;
    }

    temp_s4 = _getHitLocationCount(_selectedActor - 1);

    s0 = D_80108180;
    switch (s0) {
    case 0:
        if (D_801080B9 != 0) {
            --D_801080B9;
        }
        if (vs_mainmenu_ready() != 0) {
            func_80104C0C(D_80108181, 7);
            switch (D_80108181) {
            case 0:
                func_800FC268(3);
                _drawWeaponInfo(&temp_s1->weapon);
                break;
            case 1:
                func_800FC268(3);
                _drawShieldInfo(&temp_s1->shield);
                break;
            default:
                if ((D_80108181 - 2) < temp_s4) {
                    func_800FC268(1);
                    _drawArmorInfo(&temp_s1->hitLocations[D_80108181 - 2].unk20);
                } else {
                    func_800FC268(0);
                    _drawAccessoryInfo(&temp_s1->accessory);
                }
                break;
            }
            D_80108180 = 1;
        }
        break;
    case 1:
        if (D_80108182 < 0xA) {
            ++D_80108182;
            D_801080B4 = 0x80 - vs_battle_rowAnimationSteps[0xA - D_80108182];
            if (D_80108182 < 6) {
                if (D_801080B9 != 0) {
                    --D_801080B9;
                }
                D_801080B8 = 0;
                func_800CB654(1);

                if (D_80108181 != 0 && D_80108181 != s0) {
                    return 0;
                }

                if (D_80108181 == 0) {
                    func_80104C40(D_80108182, &temp_s1->weapon, 1);
                } else if (D_80108181 == s0) {
                    func_80104DFC(D_80108182, (func_80104DFC_t*)&temp_s1->shield, 1);
                }
            }
            break;
        }
        D_80108180 = 2;
        break;
    case 2:
        if ((vs_main_buttonsState & 0xC) != 0xC) {
            int a1;
            var_s0_2 = 0;
            var_a0 = func_8010455C();
            var_s2 = D_80108181;
            if (vs_main_buttonRepeat & 4) {
                var_s0_2 = var_a0 - 1;
            }
            if (vs_main_buttonRepeat & 8) {
                var_s0_2 = 1;
            }

            a1 = var_s2;

            while (1) {
                if ((var_s2 += var_s0_2) >= var_a0) {
                    var_s2 -= var_a0;
                }

                if (var_s2 == a1) {
                    goto here;
                }

                switch (var_s2) {
                case 0:
                    if (temp_s1->weapon.blade.id != 0) {
                        var_a0 = 0;
                    }
                    break;
                case 1:
                    if (temp_s1->shield.unk18.id != 0) {
                        var_a0 = 0;
                    }
                    break;
                default:
                    if ((var_s2 - 2) >= temp_s4
                        || (temp_s1->hitLocations[var_s2 - 2].unk20.unk0.id != 0)) {
                        var_a0 = 0;
                    }
                }

                if (var_a0 == 0) {
                    break;
                }
            }

            if (var_s2 != D_80108181) {
                vs_battle_playMenuChangeSfx();
                for (i = 10; i < 26; ++i) {
                    func_800FFB90(i);
                }
                D_80108181 = var_s2;
                switch (var_s2) {
                case 0:
                    func_800FC268(0xB);
                    _drawWeaponInfo(&temp_s1->weapon);

                    for (i = 1; i < 6; ++i) {
                        func_80104C40(i, &temp_s1->weapon, 0);
                    }
                    func_800FC85C(&temp_s1->weapon, sp18, &sp48, D_800F4E8C);
                    sp18[0] = (char*)&temp_s1->weapon;
                    break;
                case 1:
                    func_800FC268(0xB);
                    _drawShieldInfo(&temp_s1->shield);
                    for (i = 1; i < 4; ++i) {
                        func_80104DFC(i, (func_80104DFC_t*)&temp_s1->shield, 0);
                    }
                    func_800FCCE8(&temp_s1->shield, sp18, &sp48, D_800F4E8C);
                    break;
                default:
                    if ((var_s2 - 2) < temp_s4) {
                        func_800FC268(9);
                        _drawArmorInfo(&temp_s1->hitLocations[var_s2 - 2].unk20);
                        func_800FCECC(&temp_s1->hitLocations[var_s2 - 2].unk20, sp18,
                            &sp48, D_800F4E8C);
                    } else {
                        func_800FC268(8);
                        _drawAccessoryInfo((vs_battle_accessoryInfo*)&temp_s1->accessory);
                        func_8006BADC(sp20, &temp_s1->accessory);
                        func_800FD084(sp20, sp18, &sp48, D_800F4E8C);
                    }
                    break;
                }

                menuItem = vs_battle_setMenuItem(var_s2 + 10, 155, 18, 165, 0, sp18[0]);
                menuItem->selected = 1;
                menuItem->weaponType = (sp48 >> 0x1A);
                menuItem->unkC = ((sp48 & 0xFFFF0000) >> 16) & 7;

                vs_mainmenu_setMessage(sp18[1]);

                menuItem = vs_battle_setMenuItem(0x20, 0x10, 0x12, 0xA4, 8,
                    (char*)&_statusStrings[_statusStrings[var_s2 < 2
                            ? (var_s2 + VS_status_INDEX_weapon)
                            : VS_status_INDEX_armor]]);
                menuItem->selected = 1;
                i = 0x1C;
                if (var_s2 == 0) {
                    i = 0x18;
                } else if (var_s2 == 1) {
                    i = 0x1B;
                }
                menuItem->weaponType = i;
                D_80108183 = 9;
                D_801022D5 = 0;
                D_801080C7 = func_800FFCDC((int)D_801080C7, D_801021C4);
                D_801023E3 = 1;
                func_801013F8(1);
                return 0;
            }
        }
    here:
        for (i = 21; i < 26; ++i) {
            vs_battle_getMenuItem(i)->selected = 0;
        }

        temp_s0_4 = D_80108183;

        switch (D_80108181) {
        case 0:
            func_800FC268(11);
            _drawWeaponInfo(&temp_s1->weapon);
            var_v0_4 = func_801034BC(temp_s0_4, temp_s1->weapon.grip.gemSlots + 0x72);
            break;
        case 1:
            func_800FC268(11);
            _drawShieldInfo(&temp_s1->shield);
            var_v0_4 = func_801034BC(temp_s0_4, temp_s1->shield.unk18.gemSlots + 0x60);
            break;
        default:
            var_a0_5 = 8;
            if ((D_80108181 - 2) < temp_s4) {
                var_a0_5 = 9;
            }
            func_800FC268(var_a0_5);
            var_v0_4 = func_801034BC(temp_s0_4, ((D_80108181 - 2) < temp_s4) << 6);
            break;
        }

        if (var_v0_4 != D_80108183) {
            vs_battle_playMenuChangeSfx();
            D_80108183 = var_v0_4;
        }
        if (var_v0_4 < 2) {
            var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[0x19F - var_v0_4]];
        } else if (var_v0_4 < 9) {
            switch (D_801024B9) {
            case 0:
                var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[var_v0_4
                    + 0x19E]];
                break;
            case 1:
                var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[var_v0_4
                    + 0x1A4]];
                break;
            case 2:
                var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[var_v0_4
                    + 0x1AB]];
                break;
            }
        } else if (var_v0_4 < 0x10) {
            switch (D_80108181) {
            case 0:
                var_s3 = _drawWeaponInfoRow(var_v0_4 - 9, &temp_s1->weapon);
                break;
            case 1:
                var_s3 = _drawShieldInfoRow(var_v0_4 - 9, &temp_s1->shield);
                break;
            default:
                if ((D_80108181 - 2) < temp_s4) {
                    var_s3
                        = _drawArmorInfoRow(&temp_s1->hitLocations[D_80108181 - 2].unk20);
                } else {
                    var_s3 = _drawAccessoryInfoRow(&temp_s1->accessory);
                }
                break;
            }
        } else {
            var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[var_v0_4 + 0x1A0]];
            if (var_v0_4 >= 0x12) {
                if (D_80108181 == 0) {
                    var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[var_v0_4
                        + 0x280]];
                } else if ((D_80108181 - 2) < temp_s4) {
                    var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[var_v0_4
                        + 0x283]];
                }
            }
        }
        vs_mainmenu_setMessage(var_s3);
        i = D_801021A0[var_v0_4];
        if ((D_80108181 == 1) && ((D_80108183 - 0xA) < 2U)) {
            i += 7;
        }
        D_801022D5 = D_80108183 != 9;
        D_801080C7 = func_800FFCDC(D_801080C7, i);
        if (vs_main_buttonsPressed.all & 0x10) {
            func_80104F2C(1);
            return -1;
        }
        if (vs_main_buttonsPressed.all & 0x40) {
            func_80103608(_selectedActor - 1);
            func_80104F2C(1);
            func_800FFA88(2);
            return D_80108181 + 1;
        }
        D_801023E3 = 1;
        func_801013F8(1);
        break;
    }
    return 0;
}

static int func_80105970(int arg0)
{
    char* rowText[18];
    int rowType[9];
    D_800F4E8C_t sp80[9];
    int sp3E0[9];
    int sp408;
    int sp40C;
    int sp410;
    int temp_s5;
    int i;
    int temp_s1_2;
    vs_battle_equipment_hitLocations* var_fp;
    vs_battle_actor2* temp_s6;
    vs_battle_menuItem_t* temp_v0_2;
    int new_var;

    temp_s6 = vs_battle_actors[_selectedActor - 1]->unk3C;
    var_fp = temp_s6->hitLocations;
    sp40C = _getHitLocationCount(_selectedActor - 1);
    sp408 = func_8010455C();

    if (arg0 != 0) {
        D_800F4F6C = arg0 + 1;
        D_80108184 = 0;
        return 0;
    }

    switch (D_80108184) {
    case 0:
        for (i = 0; i < 9; ++i) {
            rowText[i * 2] = (char*)&_statusStrings[VS_status_OFFSET_none];
            rowText[i * 2 + 1] = (char*)&_statusStrings[VS_status_OFFSET_nothingEquipped];
            rowType[i] = 1;
        }
        if (temp_s6->weapon.blade.id != 0) {
            func_800FC85C(&temp_s6->weapon, (char**)rowText, rowType, sp80);
            rowText[0] = (char*)&temp_s6->weapon.unk0;
        }
        if (temp_s6->shield.unk18.id != 0) {
            func_800FCCE8(&temp_s6->shield, (char**)&rowText[2], rowType + 1, sp80 + 1);
        }

        temp_s5 = (((temp_s6->unk954 >> 0x11) ^ 1) & 1 & (_selectedActor != 1));
        new_var = 0xF000;
        temp_s1_2 = 0xF200;
        rowType[0] |= temp_s5 | new_var;
        rowType[1] |= temp_s5 | temp_s1_2;

        for (i = 2; i < sp408; ++i, ++var_fp) {
            int* p = sp3E0;
            sp410 = temp_s5 | 0xF400;
            if ((i - 2) < sp40C) {
                if (var_fp->unk20.unk0.id != 0) {
                    func_800FCECC(
                        &var_fp->unk20, (char**)&rowText[i * 2], &rowType[i], sp80 + i);
                }
                rowType[i] |= (((char)var_fp->nameIndex + 0x67) << 9) + temp_s5;
            } else {
                func_8006BADC(p, &temp_s6->accessory);
                func_800FD084(p, (char**)&rowText[i * 2], &rowType[i], sp80 + i);
                rowType[i] |= sp410;
            }
        }
        temp_s1_2 = vs_main_settings.cursorMemory;
        vs_main_settings.cursorMemory = 1;
        vs_mainmenu_setMenuRows(sp408, 0x19142, (char**)rowText, rowType);
        vs_main_settings.cursorMemory = temp_s1_2;
        if (D_801080B4 != 0) {
            D_80108185 = 0xA;
        } else {
            D_80108185 = 0;
        }
        D_80108184 = 1;
        break;
    case 1:
        if (D_80108185 != 0) {
            --D_80108185;
            D_801080B4 = vs_battle_rowAnimationSteps[D_80108185];
        } else {
            D_80108184 = 2;
        }
        break;
    case 2:
        i = vs_mainmenu_getSelectedRow() + 1;
        if (i != 0) {
            func_800FBD80(_selectedActor + 15);
            func_800FA8E0(4);
            if (i < 0) {
                temp_s5 = D_800F4F6C - 2;
                if (temp_s5 < 0) {
                    temp_s5 = 0;
                }
                if (temp_s5 >= sp40C) {
                    temp_s5 = sp40C - 1;
                }
                _selectedRegion = temp_s5;
                return i;
            }
            func_80104F80(i);
            D_80108184 = 5;
            break;
        }
        if ((vs_main_buttonsState & 0xC) != 0xC) {
            i = _selectedActor - 1;
            if (vs_main_buttonsPressed.all & 4) {
                i = func_80103688(i, 0xE);
                temp_s5 = 1;
            }
            if (vs_main_buttonsPressed.all & 8) {
                i = func_80103688(i, 1);
                temp_s5 = 0x11;
            }
            if (i != (_selectedActor - 1)) {
                D_801080A4 = _selectedActor;
                func_80103608(i);
                func_80103744(i + temp_s5);
                func_80100814();
                func_800FA8E0(4);
                D_80108184 = 3;
            }
        }
        break;
    case 3:
        if (func_80103744(0) != 0) {
            D_80108184 = 4;
        }
        break;
    case 4:
        if (vs_mainmenu_ready() != 0) {
            temp_v0_2 = vs_battle_getMenuItem(4);
            if (temp_v0_2->animSpeed >= 0xB5) {
                temp_v0_2->state = 2;
                temp_v0_2->x = 0xB4;
                temp_v0_2->selected = 1;
            }
            D_80108184 = 0;
        }
        break;
    case 5:
        i = func_80104F80(0);
        if (i != 0) {
            if (i < 0) {
                return -2;
            }
            D_800F4F6C = i - 1;
            D_80108184 = 4;
        }
        break;
    }
    return 0;
}

static void func_80105E94(void)
{
    int var_a2;
    u_long* temp_a1;
    u_long* temp_t1;

    temp_a1 = D_1F800000[0];
    temp_t1 = D_1F800000[1];
    if (D_801080B0 != 0) {
        temp_a1[0] = ((temp_t1[-1] & 0xFFFFFF) | 0x0D000000);
        temp_a1[1] = 0xE1000000;
        temp_a1[2] = 0x3C000000;
        temp_a1[3] = 0;
        temp_a1[4] = 0;
        temp_a1[5] = 0x808080;
        temp_a1[6] = 0x60;

        var_a2 = 0x01000060;
        if (vs_main_frameBuf == 0) {
            var_a2 = 0x01050000 | 0x60;
        }
        temp_a1[7] = var_a2;
        temp_a1[8] = 0;
        temp_a1[9] = 0xF00000;
        temp_a1[10] = 0xF000;
        temp_a1[11] = 0x808080;
        temp_a1[12] = 0xF00060;
        temp_a1[13] = 0xF060;
        temp_t1[-1] = (((u_long)temp_a1 << 8) >> 8);
        D_1F800000[0] = temp_a1 + 14;
    }
}

static void func_80105F60(void)
{
    int var_s1;

    u_long* temp_t8 = D_1F800000[0];
    void* temp_a0 = D_1F800000[1];
    u_int* var_t9 = temp_a0 + 0x1FF4;

    if (D_801080AC != 0) {
        var_t9 = temp_a0 - 4;
    }
    temp_t8[0] = (*var_t9 & 0xFFFFFF) | 0x0D000000;
    temp_t8[1] = 0x3E101010;
    temp_t8[2] = 0x40;
    temp_t8[3] = 0x38F00040;
    temp_t8[4] = 0x909090;
    temp_t8[5] = 0xA0;
    temp_t8[6] = 0xBA00A0;
    temp_t8[7] = 0x101010;
    temp_t8[8] = 0xF00040;
    temp_t8[9] = 0xF040;
    temp_t8[10] = 0x909090;
    temp_t8[11] = 0xF000A0;
    temp_t8[12] = 0xF0A0;
    temp_t8[13] = 0xE1000200;
    *var_t9 = ((u_long)temp_t8 << 8) >> 8;
    temp_t8 += 14;
    temp_t8[0] = (int)((*var_t9 & 0xFFFFFF) | 0x08000000);
    temp_t8[6] = 0x60000000;
    temp_t8[7] = 0x100;
    temp_t8[1] = 0xE10000BB;
    temp_t8[2] = 0x64808080;
    temp_t8[3] = 0xA0;
    temp_t8[4] = 0x38F00020;
    temp_t8[5] = 0xF00060;
    temp_t8[8] = 0xF00040;
    *var_t9 = ((u_long)temp_t8 << 8) >> 8;
    temp_t8 += 9;
    temp_t8[0] = (int)((*var_t9 & 0xFFFFFF) | 0x0D000000);
    temp_t8[1] = 0xE1000000;
    temp_t8[2] = 0x3C808080;
    temp_t8[3] = 0x40;
    temp_t8[4] = 0x40;
    temp_t8[5] = 0;
    temp_t8[6] = 0xA0;
    var_s1 = 0x010000A0;
    if (vs_main_frameBuf == 0) {
        var_s1 = 0x01050000 | 0xA0;
    }
    temp_t8[8] = 0x808080;
    temp_t8[7] = var_s1;
    temp_t8[9] = 0xF00040;
    temp_t8[10] = 0xF040;
    temp_t8[11] = 0;
    temp_t8[12] = 0xF000A0;
    temp_t8[13] = 0xF0A0;
    *var_t9 = ((u_long)temp_t8 << 8) >> 8;
    D_1F800000[0] = temp_t8 + 14;
}

static void func_80106150(void)
{
    int temp_lo_5;
    int temp_s1;
    int temp_s0;
    int temp_s2;
    int* p;

    temp_s1 = (0x80 - D_801080B4);
    temp_s2 = D_800F453C[0x32B];
    temp_s0 = D_800F453C[0x31F];
    p = (int*)D_1F800000 + 13;
    p[4] = ((-vs_math_sine(_xPos) * temp_s1) >> 8) * temp_s2;
    p[5] = -(temp_s0 << 0xB);
    p[6] = ((vs_math_cosine(_xPos) * temp_s1) >> 8) * temp_s2;
    ((int*)D_1F800000)[13]
        = p[4] + ((vs_math_cosine(_xPos) * vs_math_cosine(_yPos)) >> 0xA) * temp_s2;
    p[1] = p[5] - vs_math_sine(_yPos) * temp_s2 * 4;
    temp_lo_5 = (vs_math_sine(_xPos) * vs_math_cosine(_yPos) >> 0xA) * temp_s2;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[12] = 0x1000;
    p[2] = p[6] + temp_lo_5;
    func_8007ACB0();
    if (D_801080BC != 0) {
        --D_801080BC;
    } else {
        func_800F9EB8(p - 8);
    }
    func_80105F60();
    func_80105E94();
    func_801045B8(0);
    func_80103AC8();
}

static void func_80106308(void)
{
    vs_battle_equipment_hitLocations* temp_a0;

    temp_a0 = &vs_battle_actors[_selectedActor - 1]->unk3C->hitLocations[_selectedRegion];
    vs_battle_stringContext[10] = (char*)&D_800EA868[D_800EA868[temp_a0->nameIndex]];
    vs_battle_stringContext[11]
        = (char*)&_statusStrings[_statusStrings[vs_battle_getHitLocationState(temp_a0)
            + VS_status_INDEX_critical]];
    func_800C685C(D_800F4E8C, (char*)&_statusStrings[VS_status_OFFSET_values]);
    vs_mainmenu_setMessage(&D_800F4E8C->unk0);
    func_801045B8(_selectedRegion + 1);
}

static void func_801063F8(void)
{
    int i;
    vs_battle_equipment_hitLocations* temp_a0
        = &vs_battle_actors[_selectedActor - 1]->unk3C->hitLocations[_selectedRegion];

    for (i = 0; i < 16; ++i) {
        D_801024C0[i + 16] = temp_a0->unk10[i & 7];
    }
    for (i = 0; i < 4; ++i) {
        D_801024C0[i + 32] = temp_a0->unk8[i];
    }
    func_801045B8(_selectedRegion + 0x81);
}

static int D_801080C8[] = { 0x001400A0, 0x002400A0, 0x003400A0, 0x004400A0, 0x005400A0,
    0x006400A0, 0x00920098, 0x009C0098, 0x00A60098, 0x0004FFFC, 0x00040042, 0x000CFFFC,
    0x000C0042 };

static int D_801080FC[] = { 0x000A010A, 0x010A0200, 0x020A0301, 0x030A0402, 0x040A0503,
    0x050A0604, 0x060D0705, 0x070D0806, 0x080D0807, 0x0A090B09, 0x0009000A, 0x000B0D09 };

int vs_menu4_Exec(char* state)
{
    enum state {
        none,
        init = 3,
        waitForMenu,
        waitQuitToMenu = 11,
        quitToMenu,
        waitQuitToBattle,
        quitToBattle
    };

    static int animWait;
    static int D_80108130;
    static int D_80108134;

    int hitLocations;
    int var_s5;
    int var_s6;
    D_801081B8_t* var_a0;
    int userInput;
    int new_var2;

    var_s5 = 0;
    var_s6 = 0;

    switch (*state) {
    case init:
        D_80108130 = 0;
        D_801081EC = 10;
        if (vs_mainMenu_itemNames == NULL) {
            vs_mainMenu_loadItemNames(1);
        }
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        D_800EB9AE = 1;
        func_8008A4DC(0);
        func_80100414(0x7FE, 0x80);
        D_801080AC = 0;
        D_801080B0 = 0;
        _selectedActor = 0;
        D_801080A4 = 0;
        D_801080B8 = 0;
        D_801080B9 = 0;
        D_801080BB = 0;
        func_80103744(1);
        D_80108130 = 1;
        animWait = 1;
        D_80108188 = D_8005E248;
        func_8007CCF0(0x200);
        new_var2 = 13;
        var_a0 = (D_801081B8_t*)(&D_1F800000[new_var2]);
        D_80108198 = *(D_80108198_t*)&D_1F800000[5];
        D_801081B8 = *var_a0;
        D_1F800000[25] = (u_long*)0x1000;
        D_1F800000[21] = 0;
        D_1F800000[22] = 0;
        D_1F800000[23] = 0;
        _xPos = 0xB00;
        _yPos = 0;
        func_800FFBC8();
        _selectedRegion = 0;
        D_80102544 = 0;
        func_80106308();
        *state = 5;
        break;
    case waitForMenu:
        if (animWait != 0) {
            --animWait;
            func_801045B8(-1);
            func_800FBEA4(1);
        } else {
            func_80106308();
            *state = 5;
        }
        break;
    case 5:
        var_s5 = 0;
        if ((_selectedActor == 1)
            || (vs_battle_actors[_selectedActor - 1]->unk3C->unk954 & 0x20000)) {
            var_s5 = 1;
        }
        if (animWait != 0) {
            if (func_80103744(0) != 0) {
                animWait = 0;
                func_801045B8(-1);
                func_800FBEA4(1);
                userInput = _selectedRegion;
                if (userInput < VS_status_INDEX_statDesc) {
                    hitLocations = _getHitLocationCount(_selectedActor - 1) - 1;
                    if (hitLocations < userInput) {
                        _selectedRegion = hitLocations;
                    }
                    func_80106308();
                } else {
                    vs_mainmenu_setMessage((char*)&_statusStrings[_statusStrings[userInput
                        - VS_status_INDEX_statDesc]]);
                }
            }
        } else if (vs_mainMenu_loadItemNames(0) != 0) {
            if (func_801045B8(-3) == 2) {
                if (vs_main_buttonsPressed.all & PADRup) {
                    vs_battle_playMenuLeaveSfx();
                    *state = waitQuitToBattle;
                    break;
                } else if (vs_main_buttonsPressed.all & PADRdown) {
                    vs_battle_playMenuLeaveSfx();
                    *state = waitQuitToMenu;
                    break;
                } else if ((vs_main_buttonsPressed.all & PADRright)
                    && ((_selectedRegion < _getHitLocationCount(_selectedActor - 1))
                        != 0)) {
                    vs_battle_playMenuSelectSfx();
                    func_800FBEA4(2);
                    func_801045B8(-2);
                    animWait = 8;
                    *state = 7;
                    break;
                }
                var_s6 = 0;
                if (var_s5 != 0) {
                    int temp_s0_2 = _selectedRegion;
                    var_s6 = temp_s0_2 < _getHitLocationCount(_selectedActor - 1);
                }
                if (vs_main_buttonsPressed.all & PADRleft) {
                    if (var_s6 != 0) {
                        vs_battle_playMenuSelectSfx();
                        func_801063F8();
                        func_800FBBD4(6);
                        D_801081EE = 0;
                        animWait = 10;
                        *state = 9;
                        break;
                    }
                    func_800C02E0();
                }
                if (vs_main_buttonsState & PADL2) {
                    userInput = vs_battle_mapStickDeadZone(vs_main_stickPosBuf.rStickX);
                    hitLocations
                        = vs_battle_mapStickDeadZone(vs_main_stickPosBuf.rStickY);
                    if (userInput == 0) {
                        if (hitLocations == 0) {
                            if (vs_main_buttonsState & PADLup) {
                                hitLocations = -64;
                            }
                            if (vs_main_buttonsState & PADLdown) {
                                hitLocations = 64;
                            }
                            if (vs_main_buttonsState & PADLleft) {
                                userInput = -64;
                            }
                            if (vs_main_buttonsState & PADLright) {
                                userInput = 64;
                            }
                        }
                    }

                    _xPos += userInput;
                    _yPos -= hitLocations;
                    if (_yPos < 0) {
                        _yPos = 0;
                    }
                    if (_yPos > 896) {
                        _yPos = 896;
                    }
                } else {
                    userInput = _selectedRegion;
                    hitLocations = D_801080FC[userInput];
                    if (vs_main_buttonRepeat & PADLup) {
                        userInput = hitLocations;
                    } else if (vs_main_buttonRepeat & PADLdown) {
                        userInput = hitLocations >> 8;
                    } else if (vs_main_buttonRepeat & PADLleft) {
                        userInput = hitLocations >> 16;
                    } else {
                        userInput = _selectedRegion;
                        if (vs_main_buttonRepeat & PADLright) {
                            userInput = hitLocations >> 24;
                        }
                    }
                    userInput &= 0xFF;
                    func_801045B8(7);
                    if (userInput == 13) {
                        if (_navigateStatusModifiers(
                                vs_battle_actors[_selectedActor - 1]->unk3C, 1)
                            == 0) {
                            vs_battle_playMenuChangeSfx();
                            *state = 6;
                            break;
                        }
                        userInput = _selectedRegion;
                    }
                    if (userInput < 6) {
                        hitLocations = _getHitLocationCount(_selectedActor - 1);
                        if (userInput < hitLocations) {
                            func_801045B8(userInput + 1);
                        } else {
                            userInput = 6;
                            if (!(vs_main_buttonRepeat & PADLdown)) {
                                userInput = hitLocations - 1;
                                if (!(vs_main_buttonRepeat & PADLup)) {
                                    _selectedRegion = userInput;
                                }
                            }
                        }
                    }
                    D_801022D5
                        = (userInput < _getHitLocationCount(_selectedActor - 1)) ^ 1;
                    D_80108134 = func_800FFCDC(D_80108134, D_801080C8[userInput]);
                    if (userInput != _selectedRegion) {
                        vs_battle_playMenuChangeSfx();
                        if (userInput != 13) {
                            _selectedRegion = userInput;
                        }
                    }
                    if (userInput < 6) {
                        func_80106308();
                    } else {
                        vs_mainmenu_setMessage(
                            (char*)&_statusStrings[_statusStrings[userInput
                                - VS_status_INDEX_statDesc]]);
                    }
                }
            }
            userInput = _selectedActor - 1;
            if (vs_main_buttonsPressed.all & PADR1) {
                userInput = func_80103688(userInput, 1);
                hitLocations = 17;
            }
            if (vs_main_buttonsPressed.all & PADL1) {
                userInput = func_80103688(userInput, 14);
                hitLocations = 1;
            }
            if (userInput != (_selectedActor - 1)) {
                D_801080A4 = _selectedActor;
                func_801045B8(-2);
                func_800FBEA4(2);
                func_80103608(userInput);
                func_80103744(userInput + hitLocations);
                animWait = 1;
            }
        }
        D_801022D5 = (_selectedRegion < _getHitLocationCount(_selectedActor - 1)) ^ 1;
        break;
    case 6:
        var_s5 = 0;
        if ((_selectedActor == 1)
            || (vs_battle_actors[_selectedActor - 1]->unk3C->unk954 & 0x20000)) {
            var_s5 = 1;
        }
        if (animWait != 0) {
            if (func_80103744(0) != 0) {
                _navigateStatusModifiers(vs_battle_actors[_selectedActor - 1]->unk3C, 0);
                animWait = 0;
                func_801045B8(-1);
                func_800FBEA4(1);
            }
        } else {
            if (func_801045B8(-3) == 2) {
                userInput = _navigateStatusModifiers(0, 1);
                if (userInput != 0) {
                    switch (userInput) {
                    case 1:
                        *state = 5;
                        break;
                    case 2:
                        vs_battle_playMenuLeaveSfx();
                        *state = 13;
                        break;
                    case 3:
                        vs_battle_playMenuLeaveSfx();
                        *state = 11;
                        break;
                    }
                }
            }
            userInput = _selectedActor - 1;
            if (vs_main_buttonsPressed.all & PADR1) {
                userInput = func_80103688(userInput, 1);
                hitLocations = 17;
            }
            if (vs_main_buttonsPressed.all & PADL1) {
                userInput = func_80103688(userInput, 14);
                hitLocations = 1;
            }
            if (userInput != (_selectedActor - 1)) {
                D_801080A4 = _selectedActor;
                func_801045B8(-2);
                func_800FBEA4(2);
                func_80103608(userInput);
                func_80103744(userInput + hitLocations);
                animWait = 1;
                if (vs_battle_getStatusFlags(vs_battle_actors[userInput]->unk3C) == 0) {
                    *state = 5;
                }
            }
        }
        break;
    case 7:
        if (animWait == 0) {
            func_80105970(_selectedRegion + 1);
            *state = 8;
        } else {
            --animWait;
        }
        break;
    case 8:
        userInput = func_80105970(0);
        if (userInput != 0) {
            if (userInput != -2) {
                animWait = 8;
                *state = waitForMenu;
            } else {
                *state = 13;
            }
        }
        break;
    case 9:
        if (animWait != 0) {
            D_801080B4 = 128 - vs_battle_rowAnimationSteps[--animWait];
        } else if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            vs_battle_playMenuLeaveSfx();
            func_800FBBD4(-1);
            if (vs_main_buttonsPressed.all & PADRup) {
                *state = waitQuitToBattle;
                break;
            }
            animWait = 10;
            *state = 10;
        } else {
            if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {
                userInput = _selectedRegion;
                hitLocations = _getHitLocationCount(_selectedActor - 1);
                if (vs_main_buttonRepeat & PADL1) {
                    char new_var = 1;
                    userInput = (userInput - new_var) + hitLocations;
                }
                if (vs_main_buttonRepeat & PADR1) {
                    ++userInput;
                }
                if (userInput >= hitLocations) {
                    userInput -= hitLocations;
                }
                if (userInput != _selectedRegion) {
                    vs_battle_playMenuChangeSfx();
                    _selectedRegion = userInput;
                    func_801063F8();
                }
            }
            userInput = D_801081EE;
            hitLocations = 11 - D_801024B9 * 4;
            if (userInput >= hitLocations) {
                userInput = hitLocations - 1;
            }
            if (vs_main_buttonRepeat & PADLup) {
                char new_var = 1;
                userInput = (userInput - new_var) + hitLocations;
            }
            if (vs_main_buttonRepeat & PADLdown) {
                ++userInput;
            }
            if (userInput >= hitLocations) {
                userInput -= hitLocations;
            }
            if (userInput != D_801081EE) {
                vs_battle_playMenuChangeSfx();
                D_801081EE = userInput;
            }

            vs_mainmenu_setMessage((char*)&_statusStrings[_statusStrings[userInput
                + (hitLocations != 3 ? VS_status_INDEX_physicalDefense
                                     : VS_status_INDEX_bluntDefense)]]);
            D_80108134 = func_800FFCDC(D_80108134, ((userInput * 16) + 50) << 16);
        }
        break;
    case 10:
        var_s5 = 1;
        if (animWait != 0) {
            D_801080B4 = vs_battle_rowAnimationSteps[--animWait];
        } else {
            func_801045B8(_selectedRegion + 1);
            *state = 5;
        }
        break;
    case waitQuitToMenu:
    case waitQuitToBattle:
        func_800FBEA4(2);
        func_801045B8(-2);
        func_801045B8(0);
        func_80103608(0);
        func_80103AC8();
        func_8007CCF0(D_80108188);
        new_var2 = 13;
        var_a0 = (D_801081B8_t*)&D_1F800000[new_var2];
        *(D_80108198_t*)&D_1F800000[5] = D_80108198;
        *var_a0 = D_801081B8;
        func_8008A4DC(1);
        func_800FFA88(0);
        func_800FA8E0(40);
        func_800F9E0C();
        func_80100414(-2, 128);
        D_800EB9AE = 0;
        animWait = 8;
        D_80108130 = 0;
        ++*state;
        break;
    case quitToMenu:
        func_801045B8(0);
        func_80103AC8();
        func_800FFB68(0);
        func_800FFBA8();
        if (animWait <= 0) {
            if (func_800FE694() != 0) {
                *state = none;
                return 1;
            }
        }
        --animWait;
        break;
    case quitToBattle:
        func_801045B8(0);
        func_80103AC8();
        func_800FFB68(0);
        func_800FFBA8();
        if (animWait <= 0) {
            if (func_800FE694() != 0) {
                vs_battle_menuState.currentState = 5;
                *state = none;
                return 1;
            }
        }
        --animWait;
        break;
    }

    if (D_80108130 != 0) {
        func_80106150();
    }
    if (var_s5 != 0) {
        if (D_801081EC != 0) {
            --D_801081EC;
        }
    } else {
        D_801081EC = D_800EBC7C[D_801081EC];
    }
    if (D_801081EC < 10) {
        userInput = vs_battle_rowAnimationSteps[D_801081EC];
        func_80100344(16 - userInput, 38, 88, 10);
        vs_mainmenu_drawButton(1, 8 - userInput, 36, 0);
        func_800C6540(
            "STATUS", ((0x1C - userInput) & 0xFFFF) | 0x260000, 0x404040 << var_s6, 0);
    }
    return 0;
}
