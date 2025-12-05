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
#include "../../assets/MENU/MENU4.PRG/status.h"
#include "../../assets/MENU/ITEMHELP.BIN.h"
#include <libetc.h>
#include "gpu.h"

typedef struct {
    int unk0[8];
} D_80108198_t;

typedef struct {
    int unk0[13];
} D_801081B8_t;

extern u_long* D_1F800000[];

static u_short _statusStrings[] = {
#include "../../assets/MENU/MENU4.PRG/status.vsString"
};

static void _drawWeaponInfo(vs_battle_weaponInfo* weapon)
{
    vs_mainMenu_equipmentSubtype = 1;
    vs_mainMenu_resetStats();
    vs_mainMenu_setRangeRisk(0, 0, 0, 1);

    if (weapon->blade.id != 0) {
        int i;

        vs_battle_memcpy(vs_mainMenu_equipmentStats, &weapon->classAffinityCurrent,
            sizeof weapon->classAffinityCurrent);
        vs_battle_memcpy(vs_mainMenu_equipmentStats + 48, &weapon->classAffinityBaseline,
            sizeof weapon->classAffinityBaseline);
        vs_mainMenu_equipmentStats[63] =
            weapon == &vs_battle_characterState->unk3C->weapon;

        for (i = 0; i < 4; ++i) {
            vs_mainMenu_equipmentStats[i + 32] = weapon->grip.types[i];
        }

        do {
            D_80102508 = weapon->unk10E;
        } while (0);

        vs_mainMenu_setDpPp(
            weapon->currentDp, weapon->maxDp, weapon->currentPp, weapon->maxPp);
        vs_mainMenu_setStrIntAgi(
            weapon->currentStr, weapon->currentInt, weapon->currentAgility, 1);

        vs_mainMenu_strIntAgi[1].strength = weapon->baseStr;
        vs_mainMenu_strIntAgi[1].intelligence = weapon->baseInt;
        vs_mainMenu_strIntAgi[1].agility = weapon->baseAgility;
        vs_mainMenu_setRangeRisk(weapon->range, weapon->risk, 0, 1);
    }
    func_800FBB8C(7);
}

static void _drawShieldInfo(vs_battle_shieldInfo* shield)
{
    vs_mainMenu_equipmentSubtype = 8;
    vs_mainMenu_resetStats();

    if (shield->shield.id != 0) {
        int i;

        vs_battle_memcpy(vs_mainMenu_equipmentStats, &shield->classAffinityCurrent,
            sizeof shield->classAffinityCurrent);
        vs_battle_memcpy(vs_mainMenu_equipmentStats + 48, &shield->classAffinityBaseline,
            sizeof shield->classAffinityBaseline);
        vs_mainMenu_equipmentStats[63] =
            shield == &vs_battle_characterState->unk3C->shield;

        for (i = 0; i < 4; ++i) {
            vs_mainMenu_equipmentStats[i + 32] = shield->types[i];
        }

        vs_mainMenu_setDpPp(
            shield->currentPp, shield->maxPp, shield->currentDp, shield->maxDp);
        vs_mainMenu_setStrIntAgi(
            shield->currentStr, shield->currentInt, shield->currentAgility, 1);
        vs_mainMenu_strIntAgi[1].strength = shield->baseStr;
        vs_mainMenu_strIntAgi[1].intelligence = shield->baseInt;
        vs_mainMenu_strIntAgi[1].agility = shield->baseAgility;
    }
    func_800FBB8C(7);
}

static void _drawArmorInfo(vs_battle_armorInfo* armor)
{
    vs_mainMenu_equipmentSubtype = 16;
    vs_mainMenu_resetStats();

    if (armor->armor.id != 0) {
        int i;

        vs_battle_memcpy(vs_mainMenu_equipmentStats, &armor->classAffinityCurrent,
            sizeof armor->classAffinityCurrent);
        vs_battle_memcpy(vs_mainMenu_equipmentStats + 48, &armor->classAffinityBaseline,
            sizeof armor->classAffinityBaseline);
        vs_mainMenu_equipmentStats[63] = 0;

        for (i = 0; i < 5; ++i) {
            vs_mainMenu_equipmentStats[63] |=
                armor == &vs_battle_characterState->unk3C->hitLocations[i].armor;
        }

        for (i = 0; i < 4; ++i) {
            vs_mainMenu_equipmentStats[i + 32] = armor->types[i];
        }

        vs_mainMenu_setDpPp(armor->currentDp, armor->maxDp, 0, 0);
        vs_mainMenu_setStrIntAgi(
            armor->currentStr, armor->currentInt, armor->currentAgility, 1);
        vs_mainMenu_strIntAgi[1].strength = armor->baseStr;
        vs_mainMenu_strIntAgi[1].intelligence = armor->baseInt;
        vs_mainMenu_strIntAgi[1].agility = armor->baseAgility;
    }
    func_800FBB8C(7);
}

static void _drawAccessoryInfo(vs_battle_accessoryInfo* accessory)
{
    vs_mainMenu_equipmentSubtype = 32;
    vs_mainMenu_resetStats();

    if (accessory->accessory.id != 0) {
        int i;
        for (i = 0; i < 16; ++i) {
            vs_mainMenu_equipmentStats[i] = accessory->classes[i & 7];
            vs_mainMenu_equipmentStats[i + 16] = accessory->affinities[i & 7];
            vs_mainMenu_equipmentStats[i + 32] =
                accessory->types[i & 7]; // BUG? Copies past end
        }
        vs_mainMenu_setStrIntAgi(
            accessory->currentStr, accessory->currentInt, accessory->currentAgility, 2);
    }
    func_800FBB8C(7);
}

static void _drawBladeInfo(vs_battle_weaponInfo* weapon)
{
    int i;

    vs_battle_equipment* blade = &weapon->blade;
    vs_mainMenu_equipmentSubtype = 2;

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i] = blade->classes[i & 7];
        vs_mainMenu_equipmentStats[i + 16] = blade->affinities[i & 7];
    }
    vs_mainMenu_setDpPp(blade->currentDp, blade->maxDp, weapon->currentPp, weapon->maxPp);
    vs_mainMenu_setStrIntAgi(blade->strength, blade->intelligence, blade->agility, 1);
    vs_mainMenu_setRangeRisk(blade->range.unk0, blade->cost, 0, 1);
    func_800FBB8C(3);
    vs_mainMenu_drawDpPpbars(11);
}

static void _drawGripInfo(vs_battle_equipment* grip)
{
    int i;

    vs_mainMenu_equipmentSubtype = 4;

    for (i = 0; i < 4; ++i) {
        vs_mainMenu_equipmentStats[i + 32] = grip->types[i];
    }

    vs_mainMenu_setStrIntAgi(grip->strength, grip->intelligence, grip->agility, 1);
    func_800FBB8C(4);
    vs_mainMenu_drawDpPpbars(8);
}

static void _drawGemInfo(vs_battle_equipment* gem)
{
    int i;

    vs_mainMenu_equipmentSubtype = 64;

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i] = gem->classes[i & 7];
        vs_mainMenu_equipmentStats[i + 16] = gem->affinities[i & 7];
    }

    vs_mainMenu_setStrIntAgi(gem->strength, gem->intelligence, gem->agility, 1);
    func_800FBB8C(3);
    vs_mainMenu_drawDpPpbars(8);
}

static void _initBladeInfo(
    vs_battle_equipment* blade, char** arg1, int* arg2 __attribute__((unused)))
{
    char* str;

    vs_battle_stringContext.strings[9] = vs_mainMenu_itemNames[blade->material + 253];
    vs_battle_stringContext.strings[8] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[blade->category + VS_ITEMHELP_BIN_INDEX_dagger - 1]];
    vs_battle_stringContext.strings[7] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[blade->damageType + VS_ITEMHELP_BIN_INDEX_blunt - 1]];
    vs_battle_stringContext.strings[6] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[vs_mainMenu_weaponHands[blade->category - 1]
                              + VS_ITEMHELP_BIN_INDEX_oneHanded]];

    str = vs_battle_printf(vs_battle_stringBuf,
        (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[blade->id - 1]]);
    vs_battle_printf(
        str, (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_weaponDescTemplate]);

    arg1[1] = vs_battle_stringBuf;
}

static void _initGripInfo(
    vs_battle_equipment* grip, char** arg1, int* arg2 __attribute__((unused)))
{
    char* str;

    u_short* gripId = &grip->id;
    vs_battle_stringContext.strings[5] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[grip->category + VS_ITEMHELP_BIN_INDEX_shortGrip - 1]];
    str = vs_battle_printf(vs_battle_stringBuf,
        (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[*gripId - 6]]);
    vs_battle_printf(
        str, (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_gripTemplate]);

    arg1[1] = vs_battle_stringBuf;
}

static void _initGemInfo(
    vs_battle_equipment* gem, char** arg1, int* arg2 __attribute__((unused)))
{
    vs_battle_memcpy(vs_battle_stringBuf,
        &vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[gem->id - 0x8C]], 0x60);
    arg1[1] = vs_battle_stringBuf;
}

static char* _hitLocationStatuses[] = { "DYING", "BAD", "AVERAGE", "GOOD", "EXCELLENT",
    NULL };

static char* _drawWeaponInfoRow(int row, vs_battle_weaponInfo* weapon)
{
    char* sp10[2];
    int sp18;

    sp10[1] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noGems];
    switch (row) {
    case 0:
        vs_mainMenu_setWeaponStrings(weapon, sp10, &sp18, vs_battle_stringBuf);
        sp10[0] = weapon->name;
        break;
    case 1:
        _initBladeInfo(&weapon->blade, sp10, &sp18);
        _drawBladeInfo(weapon);
        break;
    case 2:
        _initGripInfo(&weapon->grip, sp10, &sp18);
        _drawGripInfo(&weapon->grip);
        break;
    case 3:
    case 4:
    case 5:
        if (weapon->gems[row - 3].id != 0) {
            _initGemInfo(&weapon->gems[row - 3], sp10, &sp18);
            _drawGemInfo(&weapon->gems[row - 3]);
        } else {
            vs_mainMenu_drawDpPpbars(8);
            vs_mainMenu_resetStats();
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

    sp10[1] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noGems];
    if (row == 0) {
        vs_mainMenu_setShieldStrings(shield, sp10, &sp18, vs_battle_stringBuf);
    } else if (row < 0) {

    } else if (row < 4) {
        if (shield->gems[row - 1].id != 0) {
            _initGemInfo(&shield->gems[row - 1], (char**)&sp10, &sp18);
            _drawGemInfo(&shield->gems[row - 1]);
        } else {
            vs_mainMenu_drawDpPpbars(8);
            vs_mainMenu_resetStats();
        }
    }
    vs_battle_getMenuItem(row + 20)->selected = 1;
    return sp10[1];
}

static char* _drawArmorInfoRow(vs_battle_armorInfo* arg0)
{
    char* sp10[2];
    int sp18;

    vs_mainMenu_setArmorStrings(arg0, sp10, &sp18, vs_battle_stringBuf);
    return sp10[1];
}

static char* _drawAccessoryInfoRow(vs_battle_accessoryInfo* arg0)
{
    char* sp10[2];
    func_8006B7BC_t sp18;
    int sp30[2];

    func_8006BADC(&sp18, arg0);
    vs_mainMenu_setAccessoryStrings(&sp18, sp10, sp30, vs_battle_stringBuf);
    return sp10[1];
}

static int _equipmentDetailElementSelectable(int arg0, int arg1)
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

static int _updateEquipmentDetailSelection(u_int newSelection, int arg1)
{
    int direction = 0;
    int previousSelection = newSelection;

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
        newSelection =
            vs_mainMenu_equipmentDetailNavigationMap[previousSelection][direction - 1];
    }

    while (1) {
        if (_equipmentDetailElementSelectable(newSelection, arg1) != 0) {
            break;
        }
        if (previousSelection == newSelection) {
            if ((newSelection - 2) < 14) {
                do {
                    --newSelection;
                } while (_equipmentDetailElementSelectable(newSelection, arg1) == 0);
                return newSelection;
            }
            do {
                ++newSelection;
            } while (_equipmentDetailElementSelectable(newSelection, arg1) == 0);
            return newSelection;
        }
        previousSelection = newSelection;
        newSelection =
            vs_mainMenu_equipmentDetailNavigationMap[previousSelection][direction - 1];
    }
    return newSelection;
}

static int _xPos = 0;
static int _yPos = 0;
static int D_801080A4 = 0;
static int _selectedActor = 0;
static int _drawBackgroundFirst = 0;
static int _fadeScreen = 0;
static int _animationStep = 0;
static char D_801080B8 = 0;
static char D_801080B9 = 0;
static char D_801080BA = 0;
static char D_801080BB = 0;

static void _initEquipmentScreen(int arg0)
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

static int _getNextValidActor(int currentActor, int targetActor)
{
    int temp_a0;

    while (1) {
        currentActor = (currentActor + targetActor) % 15;
        temp_a0 = func_800A0BE0(currentActor);
        if ((vs_battle_actors[currentActor] != NULL)
            && (vs_battle_actors[currentActor]->unk1C < 5)
            && (temp_a0 & 0x01000001) == 1) {
            break;
        }
    }
    return currentActor;
}

static char D_801080BC = 0;

static int func_80103744(int arg0)
{
    static u_int D_801080C0 = 0;

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
            4, 180, 18, 0x8C, 8, vs_battle_actors[_selectedActor - 1]->unk3C->name)
            ->selected = 1;
        return 0;
    }

    switch (D_801080C0) {
    case 0:
        if (_animationStep < 160) {
            _drawBackgroundFirst = 1;
            _animationStep += 32;
            break;
        } else {
            _drawBackgroundFirst = 0;
            func_800F9E0C();
        }
        // Fallthrough
    case 1:
        _fadeScreen = 1;
        func_800F9A24(_selectedActor - 1);
        D_801080BC = 1;
        _animationStep = -160;
        D_801080C0 = 2;
        break;
    case 2:
        if (_animationStep < 0) {
            _animationStep += 32;
            break;
        }
        _fadeScreen = 0;
        D_801080C0 = 6;
        return 1;
    case 3:
        if (_animationStep >= -159) {
            _fadeScreen = 1;
            _animationStep -= 32;
            break;
        }
        func_800F9E0C();
    case 4:
        _fadeScreen = 0;
        func_800F9A24(_selectedActor - 1);
        D_801080BC = 1;
        _animationStep = 160;
        D_801080C0 = 5;
        break;
    case 5:
        if (_animationStep > 0) {
            _drawBackgroundFirst = 1;
            _animationStep -= 32;
            break;
        }
        _drawBackgroundFirst = 0;
        D_801080C0 = 6;
        return 1;
    case 6:
        return 1;
    }
    return 0;
}

static void _renderUnknownValue(int x, int withMax, u_long* nextPrim)
{
    int i;

    if (withMax != 0) {
        for (i = 0; i < 3; ++i) {
            vs_battle_setSprite(128, x, vs_getWH(6, 9), nextPrim)[4] =
                vs_getUV0Clut(228, 0, 832, 223);
            x -= 5;
        }
        vs_battle_renderValue(2, x, 0, nextPrim);
        x -= 7;
    }

    x += 0xFFFF0000;

    for (i = 0; i < 3; ++i) {
        vs_battle_setSprite(128, x, vs_getWH(7, 10), nextPrim)[4] =
            vs_getUV0Clut(234, 0, 832, 223);
        x -= 6;
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
    int i;
    int temp_s2;
    vs_battle_actor2* actor = vs_battle_actors[_selectedActor - 1]->unk3C;
    u_long* temp_s4 = D_1F800000[1] - 3;

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
            actor = vs_battle_actors[D_801080A4 - 1]->unk3C;
        }
        break;
    case 2:
        if (D_801080B9 != 0) {
            --D_801080B9;
            actor = vs_battle_actors[D_801080A4 - 1]->unk3C;
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
    if (D_801080B9 == 0) {
        return;
    }

    temp_s2 = ((D_801080B9 * 8) - 0x16) << 0x10;
    if (actor->flags.u32 & 0x20000) {
        i = vs_battle_renderValue(0, temp_s2 | 66, actor->maxHP, temp_s4);
        vs_battle_renderValue(2, i, 0, temp_s4);
        vs_battle_renderValue(1, i + 0xFFFEFFF9, actor->currentHP, temp_s4);
        i = vs_battle_renderValue(0, temp_s2 | 136, actor->maxMP, temp_s4);
        vs_battle_renderValue(2, i, 0, temp_s4);
        vs_battle_renderValue(1, i + 0xFFFEFFF9, actor->currentMP, temp_s4);
        temp_s2 += 0xF0000;
        vs_battle_renderValue(1, temp_s2 | 64, actor->risk, temp_s4);
        temp_s2 += 0x10000;
    } else {
        _renderUnknownValue(temp_s2 | 66, 1, temp_s4);
        _renderUnknownValue(temp_s2 | 136, 1, temp_s4);
        temp_s2 += 0x100000;
        _renderUnknownValue(temp_s2 | 64, 0, temp_s4);
    }

    for (i = 0; i < 3; ++i) {
        func_800C0224(0x180, D_800EBBEC[i] + ((D_801080B9 - 4) << 0x13),
            D_800EBBFC[i] | 0x90000, temp_s4)
            ->unk10 = D_800EBC00[i] | 0x37F60000;
    }
    temp_s2 += 0xFFF80000;
    i = (actor->flags.u32 >> 9) & 0x100;
    _drawStatBar(i, actor->currentHP, actor->maxHP, temp_s2 | 10);
    _drawStatBar(i | 1, actor->currentMP, actor->maxMP, temp_s2 | 80);
    temp_s2 += 0x40000;
    _drawStatBar(i | 2, actor->risk, 100, temp_s2 | 10);
}

static void _drawStatusIndicator(int colorIndex, int xy, int arg2)
{
    u_int color;
    u_long* temp_a0;
    u_long* temp_t1;

    temp_t1 = D_1F800000[2];
    temp_a0 = D_1F800000[0];
    color = D_800EBC54[colorIndex] >> arg2;
    temp_a0[0] = (*temp_t1 & 0xFFFFFF) | 0x06000000;
    temp_a0[1] = color | (primTile << 24);
    temp_a0[2] = xy;
    temp_a0[3] = vs_getWH(7, 7);
    temp_a0[4] = (color * 2) | (primTile << 24);
    temp_a0[5] = xy + vs_getXY(1, 1);
    temp_a0[6] = vs_getWH(5, 5);
    *temp_t1 = ((u_long)temp_a0 << 8) >> 8;
    D_1F800000[0] = temp_a0 + 7;
}

static void _drawHitLocationLeaderLine(
    int hitLocation, int xy, int arg2 __attribute__((unused)), int opaque)
{
    int temp_t2;
    int temp_v0;
    u_long* temp_a2;
    u_long* temp_t0;
    int x;

    opaque = (0x687018 << opaque) | ((33 - opaque) << 25);
    temp_t2 = hitLocation * 16 + 42;
    hitLocation = ((xy >> 16) - temp_t2);

    temp_a2 = D_1F800000[0];
    temp_t0 = D_1F800000[1];

    x = (short)xy;

    if (hitLocation < 0) {
        hitLocation = -hitLocation;
    }
    hitLocation = (hitLocation * 3) >> 1;

    temp_a2[0] = (temp_t0[-1] & 0xFFFFFF) | 0x08000000;
    temp_a2[1] = 0xE1000000;
    temp_a2[2] = opaque;
    temp_a2[3] = xy;
    temp_v0 = ((x + ((hitLocation * 2) / 3)) & 0xFFFF) | (temp_t2 << 0x10);
    temp_a2[4] = temp_v0;
    temp_a2[5] = (temp_t0[-1] & 0xFFFFFF) | 0x03000000;
    temp_a2[6] = opaque;
    temp_a2[7] = temp_v0;
    temp_a2[8] = (temp_t2 << 0x10) | 216;
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
                    ->unk10 = ((((i & 3) * 8) + 0x3068) | 0x37FF0000);
            }
            arg0 = func_800C0224(
                0x80, (temp_s2 & 0xFFFF) | temp_s1, 0x100010, D_1F800000[1] - 2);

            arg0->unk10 =
                (D_800EBC14[i] | (((0x0F0F906A >> i) & 1) ? 0x37F90000 : 0x37F80000));
        }
    }
}

static char _activeStatusModifiers[32];
static u_char _selectedStatusModifier;
static u_char _statusModifierCount;
static char _0[2];
static vs_battle_actor2* _statusModifersCurrentTarget;
static char _1[8];
static int _hitLocationAnimSteps[6];
static char _equipmentDetailState;
static char _selectedEquipmentRow;
static char _equipmentDetailAnimStep;
static char _equipmentDetailSelectedElement;
static char _equipmentScreenState;
static u_char _timer;
static char _2[2];
static int D_80108188;
static char _3[12];
static D_80108198_t D_80108198;
static D_801081B8_t D_801081B8;
static u_char _animationIndex;
static u_char _selectedElement;
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
        } else if (_selectedElement == 11) {
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
                _selectedElement = 11;
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
                _selectedElement = 6;
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
        D_801080C4 = func_800FFCDC(
            D_801080C4, (((_selectedStatusModifier & 7) * 16) + 2)
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

static int _getEquipmentCount(void)
{
    return _getHitLocationCount(_selectedActor - 1) + 2
         + (vs_battle_actors[_selectedActor - 1]->unk3C->accessory.accessory.id != 0);
}

static int _drawHitLocationStatuses(int arg0)
{
    static char state = 0;
    static u_char tempSelectedActor = 0;

    int sp10[2];
    vs_battle_actor2* actor;
    vs_battle_equipment_hitLocations* hitLocation;
    int hitLocationCount;
    int sp20;
    int sp24;
    int temp_s6;
    int hitLocationStatus;
    int i;
    int step;

    actor = vs_battle_actors[tempSelectedActor]->unk3C;
    hitLocationCount = _getHitLocationCount(tempSelectedActor);
    if (arg0 != 0) {
        if (arg0 > 0) {
            D_800F4EE8.unk3A[0x48] = arg0 - 1;
            return 0;
        }
        if (arg0 == -3) {
            return state;
        }
        if (arg0 == -2) {
            state = 3;
        } else {
            tempSelectedActor = _selectedActor - 1;
            func_800FBD80(tempSelectedActor);
            for (i = 0; i < 6; ++i) {
                _hitLocationAnimSteps[i] = 12 + i;
            }
            state = 1;
        }
        return 0;
    }
    switch (state) {
    case 0:
        break;
    case 1:
        func_80103FEC(actor, vs_battle_rowAnimationSteps[_hitLocationAnimSteps[0]]);
        for (i = 0; i < hitLocationCount; ++i) {
            hitLocation = &actor->hitLocations[i];
            step = _hitLocationAnimSteps[i];
            vs_battle_renderTextRaw(vs_battle_hitlocations[hitLocation->nameIndex],
                (vs_battle_rowAnimationSteps[step] + 216) | ((34 + i * 16) << 16), NULL);
            hitLocationStatus = vs_battle_getHitLocationStatus(hitLocation);
            _drawStatusIndicator(hitLocationStatus,
                (vs_battle_rowAnimationSteps[step] + 216) | ((36 + i * 16) << 16), NULL);
            vs_battle_renderTextRaw(_hitLocationStatuses[hitLocationStatus],
                (vs_battle_rowAnimationSteps[step] + 224) | ((34 + i * 16) << 16), NULL);
            if (step < 8) {
                func_800A13EC(1, hitLocation->unk5, sp10, 0);
                _drawHitLocationLeaderLine(i, sp10[0], 8 - step, 0);
            }
            hitLocationStatus = 0;
            if (step != 0) {
                _hitLocationAnimSteps[i] = step - 1;
            } else {
                hitLocationStatus = 1;
            }
        }

        if (hitLocationStatus != 0) {
            state = 2;
        }
        break;
    case 2:
        func_80103FEC(actor, 0);

        step = D_800F4EE8.unk3A[0x48];
        for (i = 0; i < hitLocationCount; ++i) {
            hitLocation = &actor->hitLocations[i];
            temp_s6 = step >> 7;
            sp20 = step - 128;
            sp24 = temp_s6 - 1;
            func_800C6540(vs_battle_hitlocations[hitLocation->nameIndex],
                216 | ((34 + i * 16) << 16),
                i == sp20 ? vs_getRGB888(128, 128, 128) >> sp24
                          : vs_getRGB888(128, 128, 128) >> temp_s6,
                0);
            hitLocationStatus = vs_battle_getHitLocationStatus(hitLocation);
            _drawStatusIndicator(hitLocationStatus, (0x24 + i * 0x10) * 0x10000 | 0xD8,
                temp_s6 - (i == sp20));
            func_800C6540(_hitLocationStatuses[hitLocationStatus],
                224 | ((34 + i * 16) << 16),
                i == sp20 ? vs_getRGB888(128, 128, 128) >> sp24
                          : vs_getRGB888(128, 128, 128) >> temp_s6,
                0);
            func_800A13EC(1, hitLocation->unk5, sp10, 0);
            if (!(step & 0x80) && ((_fadeScreen | _drawBackgroundFirst) == 0)) {
                _drawHitLocationLeaderLine(i, sp10[0], 8, i == step);
            }
        }
        break;
    case 3:
        func_80103FEC(actor, _hitLocationAnimSteps[0] << 5);

        for (i = 0; i < hitLocationCount; ++i) {
            if (_hitLocationAnimSteps[i] < 8) {
                hitLocation = &actor->hitLocations[i];
                ++_hitLocationAnimSteps[i];
                vs_battle_renderTextRaw(vs_battle_hitlocations[hitLocation->nameIndex],
                    ((_hitLocationAnimSteps[i] << 5) + 216) | ((34 + i * 16) << 16), 0);
                hitLocationStatus = vs_battle_getHitLocationStatus(hitLocation);
                _drawStatusIndicator(hitLocationStatus,
                    ((_hitLocationAnimSteps[i] << 5) + 216) | ((36 + i * 16) << 16), 0);
                vs_battle_renderTextRaw(_hitLocationStatuses[hitLocationStatus],
                    ((_hitLocationAnimSteps[i] << 5) + 224) | ((34 + i * 16) << 16), 0);
            } else {
                state = 0;
            }
        }
        break;
    }
    return 0;
}

static void _setActiveRow(int row)
{
    vs_battle_menuItem_t* menuItem;

    func_800FA8A0(4);
    menuItem = vs_battle_getMenuItem(row + 10);
    menuItem->state = 2;
    menuItem->x = 155;
    menuItem->selected = 1;
    menuItem->unk3A = 0;
}

static void _animateEquipmentDetailTransition(int selectedRow)
{
    char flags;
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_setMenuItem(32, -164, 18, 164, 8,
        (char*)&_statusStrings[_statusStrings[selectedRow < 2
                                                  ? selectedRow + VS_status_INDEX_weapon
                                                  : VS_status_INDEX_armor]]);

    menuItem->state = 5;
    menuItem->x = 16;
    menuItem->selected = 1;

    flags = 28;

    if (selectedRow == 0) {
        flags = 24;
    } else if (selectedRow == 1) {
        flags = 27;
    }
    menuItem->flags = flags;
    menuItem = vs_battle_getMenuItem(selectedRow + 10);
    menuItem->state = 3;
    menuItem->x = 18;
}

static void func_80104C0C(int selectedRow, int arg1)
{
    _animateEquipmentDetailTransition(selectedRow);
    func_800FBBD4(arg1);
    func_800FBEA4(1);
}

static void _setWeaponRow(int row, vs_battle_weaponInfo* weapon, int arg2)
{
    func_800FD0E0_t sp18;
    func_8006B57C_t sp20;
    func_8006B6AC_t sp50;
    func_800FD17C_t sp60;
    u_int sp80;

    int var_s1 = 158;
    int gemSlots = weapon->grip.gemSlots;

    if (row == 1) {
        func_8006B57C(&sp20, &weapon->blade);
        func_800FCAA4(&sp20, &sp18, &sp80, vs_battle_stringBuf);
    } else if (row == 2) {
        func_8006B6AC(&sp50, &weapon->grip);
        func_800FCC0C(&sp50, &sp18, &sp80, vs_battle_stringBuf);
    } else {
        var_s1 = row - 3;
        if (var_s1 < gemSlots) {
            sp18.unk4 = 0;
            sp18.unk0 = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_none];
            sp80 = 0x58000000;
            if (weapon->gems[var_s1].id != 0) {
                func_8006B728(&sp60, &weapon->gems[var_s1]);
                func_800FD0E0(&sp60, (func_800FD0E0_t*)&sp18, &sp80, vs_battle_stringBuf);
            }
            var_s1 = 151;
        } else {
            var_s1 = 0;
        }
    }

    func_800FFB90(row + 20);

    if (var_s1 != 0) {
        vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(
            row + 20, 320 - var_s1, (row * 16) + 18, var_s1, 0, sp18.unk0);
        menuItem->unk7 = sp18.unk4 == 0;
        if (arg2 & 1) {
            menuItem->animSpeed = 320;
            menuItem->state = 2;
            menuItem->x = 320 - var_s1;
        }
        menuItem->flags = sp80 >> 26;
        menuItem->unkC = ((sp80 & 0xFFFF0000) >> 16) & 7;
    }
}

static void _setShieldRow(int row, vs_battle_shieldInfo* shield, int arg2)
{
    func_800FD0E0_t sp18;
    func_800FD17C_t sp20;
    int sp40;
    int var_s0;
    vs_battle_menuItem_t* meuItem;

    var_s0 = row - 1;

    if (var_s0 < shield->shield.gemSlots) {
        sp18.unk4 = 0;
        sp18.unk0 = (char*)(&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_none]);
        sp40 = 0x58000000;
        if (shield->gems[var_s0].id != 0) {
            func_8006B728(&sp20, &shield->gems[var_s0]);
            func_800FD0E0(&sp20, &sp18, &sp40, vs_battle_stringBuf);
        }
        var_s0 = 151;
    } else {
        var_s0 = 0;
    }

    func_800FFB90(row + 20);

    if (var_s0 != 0) {
        meuItem = vs_battle_setMenuItem(
            row + 20, 320 - var_s0, (row * 16) + 18, var_s0, 0, sp18.unk0);
        meuItem->unk7 = sp18.unk4 == 0;
        if (arg2 & 1) {
            meuItem->animSpeed = 320;
            meuItem->state = 2;
            meuItem->x = 320 - var_s0;
        }
        meuItem->flags = 0x16;
    }
}

static void _exitEquipmentDetail(int arg0)
{
    vs_battle_playMenuLeaveSfx();
    func_800FA8E0(40);
    func_800FA810(0);
    func_800FBBD4(-1);
    func_800FBEA4(2);
    if (arg0 != 0) {
        vs_mainMenu_drawDpPpbars(4);
    }
}

static int _equipmentDetailScreen(int row)
{
    enum state { init };

    static char _cursorAnimState = 0;

    char* sp18[2];
    func_8006B7BC_t sp20;
    u_int sp48;
    int hitLocations;
    int equipmentCount;
    int var_a0_5;
    int var_s0_2;
    int i;
    int var_s2;
    int newSelection;
    char* var_s3;
    int previousSelection;
    vs_battle_actor2* temp_s1;
    vs_battle_menuItem_t* menuItem;
    unsigned char state;

    temp_s1 = vs_battle_actors[_selectedActor - 1]->unk3C;

    if (row != 0) {
        _selectedEquipmentRow = row - 1;
        D_801080B8 = 0;
        func_800CB654(1);
        _setActiveRow(_selectedEquipmentRow);
        func_800FFA88(0);
        _equipmentDetailSelectedElement = 9;
        _equipmentDetailAnimStep = 0;
        _equipmentDetailState = init;
        return 0;
    }

    hitLocations = _getHitLocationCount(_selectedActor - 1);

    state = _equipmentDetailState;
    switch (state) {
    case init:
        if (D_801080B9 != 0) {
            --D_801080B9;
        }
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_80104C0C(_selectedEquipmentRow, 7);
        switch (_selectedEquipmentRow) {
        case 0:
            vs_mainMenu_drawDpPpbars(3);
            _drawWeaponInfo(&temp_s1->weapon);
            break;
        case 1:
            vs_mainMenu_drawDpPpbars(3);
            _drawShieldInfo(&temp_s1->shield);
            break;
        default:
            if ((_selectedEquipmentRow - 2) < hitLocations) {
                vs_mainMenu_drawDpPpbars(1);
                _drawArmorInfo(&temp_s1->hitLocations[_selectedEquipmentRow - 2].armor);
            } else {
                vs_mainMenu_drawDpPpbars(0);
                _drawAccessoryInfo(&temp_s1->accessory);
            }
            break;
        }
        _equipmentDetailState = 1;
        break;
    case 1:
        if (_equipmentDetailAnimStep < 10) {
            ++_equipmentDetailAnimStep;
            _animationStep =
                128 - vs_battle_rowAnimationSteps[10 - _equipmentDetailAnimStep];
            if (_equipmentDetailAnimStep < 6) {
                if (D_801080B9 != 0) {
                    --D_801080B9;
                }
                D_801080B8 = 0;
                func_800CB654(1);

                if (_selectedEquipmentRow != 0 && _selectedEquipmentRow != state) {
                    return 0;
                }

                if (_selectedEquipmentRow == 0) {
                    _setWeaponRow(_equipmentDetailAnimStep, &temp_s1->weapon, 1);
                } else if (_selectedEquipmentRow == 1) {
                    _setShieldRow(_equipmentDetailAnimStep, &temp_s1->shield, 1);
                }
            }
            break;
        }
        _equipmentDetailState = 2;
        break;
    case 2:
        if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {
            int a1;
            var_s0_2 = 0;
            equipmentCount = _getEquipmentCount();
            var_s2 = _selectedEquipmentRow;
            if (vs_main_buttonRepeat & 4) {
                var_s0_2 = equipmentCount - 1;
            }
            if (vs_main_buttonRepeat & 8) {
                var_s0_2 = 1;
            }

            a1 = var_s2;

            while (1) {
                if ((var_s2 += var_s0_2) >= equipmentCount) {
                    var_s2 -= equipmentCount;
                }

                if (var_s2 == a1) {
                    goto here;
                }

                switch (var_s2) {
                case 0:
                    if (temp_s1->weapon.blade.id != 0) {
                        equipmentCount = 0;
                    }
                    break;
                case 1:
                    if (temp_s1->shield.shield.id != 0) {
                        equipmentCount = 0;
                    }
                    break;
                default:
                    if ((var_s2 - 2) >= hitLocations
                        || (temp_s1->hitLocations[var_s2 - 2].armor.armor.id != 0)) {
                        equipmentCount = 0;
                    }
                }

                if (equipmentCount == 0) {
                    break;
                }
            }

            if (var_s2 != _selectedEquipmentRow) {
                vs_battle_playMenuChangeSfx();
                for (i = 10; i < 26; ++i) {
                    func_800FFB90(i);
                }
                _selectedEquipmentRow = var_s2;
                switch (var_s2) {
                case 0:
                    vs_mainMenu_drawDpPpbars(0xB);
                    _drawWeaponInfo(&temp_s1->weapon);

                    for (i = 1; i < 6; ++i) {
                        _setWeaponRow(i, &temp_s1->weapon, 0);
                    }
                    vs_mainMenu_setWeaponStrings(
                        &temp_s1->weapon, sp18, &sp48, vs_battle_stringBuf);
                    sp18[0] = (char*)&temp_s1->weapon;
                    break;
                case 1:
                    vs_mainMenu_drawDpPpbars(0xB);
                    _drawShieldInfo(&temp_s1->shield);
                    for (i = 1; i < 4; ++i) {
                        _setShieldRow(i, &temp_s1->shield, 0);
                    }
                    vs_mainMenu_setShieldStrings(
                        &temp_s1->shield, sp18, &sp48, vs_battle_stringBuf);
                    break;
                default:
                    if ((var_s2 - 2) < hitLocations) {
                        vs_mainMenu_drawDpPpbars(9);
                        _drawArmorInfo(&temp_s1->hitLocations[var_s2 - 2].armor);
                        vs_mainMenu_setArmorStrings(
                            &temp_s1->hitLocations[var_s2 - 2].armor, sp18, &sp48,
                            vs_battle_stringBuf);
                    } else {
                        vs_mainMenu_drawDpPpbars(8);
                        _drawAccessoryInfo((vs_battle_accessoryInfo*)&temp_s1->accessory);
                        func_8006BADC(&sp20, &temp_s1->accessory);
                        vs_mainMenu_setAccessoryStrings(
                            &sp20, sp18, &sp48, vs_battle_stringBuf);
                    }
                    break;
                }

                menuItem = vs_battle_setMenuItem(var_s2 + 10, 155, 18, 165, 0, sp18[0]);
                menuItem->selected = 1;
                menuItem->flags = (sp48 >> 0x1A);
                menuItem->unkC = ((sp48 & 0xFFFF0000) >> 16) & 7;

                vs_mainmenu_setMessage(sp18[1]);

                menuItem = vs_battle_setMenuItem(0x20, 0x10, 0x12, 0xA4, 8,
                    (char*)&_statusStrings
                        [_statusStrings[var_s2 < 2 ? (var_s2 + VS_status_INDEX_weapon)
                                                   : VS_status_INDEX_armor]]);
                menuItem->selected = 1;
                i = 0x1C;
                if (var_s2 == 0) {
                    i = 0x18;
                } else if (var_s2 == 1) {
                    i = 0x1B;
                }
                menuItem->flags = i;
                _equipmentDetailSelectedElement = 9;
                D_801022D5 = 0;
                _cursorAnimState =
                    func_800FFCDC(_cursorAnimState, vs_mainMenu_mainCursorXY);
                D_801023E3 = 1;
                func_801013F8(1);
                return 0;
            }
        }
    here:
        for (i = 21; i < 26; ++i) {
            vs_battle_getMenuItem(i)->selected = 0;
        }

        previousSelection = _equipmentDetailSelectedElement;

        switch (_selectedEquipmentRow) {
        case 0:
            vs_mainMenu_drawDpPpbars(11);
            _drawWeaponInfo(&temp_s1->weapon);
            newSelection = _updateEquipmentDetailSelection(
                previousSelection, temp_s1->weapon.grip.gemSlots + 114);
            break;
        case 1:
            vs_mainMenu_drawDpPpbars(11);
            _drawShieldInfo(&temp_s1->shield);
            newSelection = _updateEquipmentDetailSelection(
                previousSelection, temp_s1->shield.shield.gemSlots + 96);
            break;
        default:
            var_a0_5 = 8;
            if ((_selectedEquipmentRow - 2) < hitLocations) {
                var_a0_5 = 9;
            }
            vs_mainMenu_drawDpPpbars(var_a0_5);
            newSelection = _updateEquipmentDetailSelection(
                previousSelection, ((_selectedEquipmentRow - 2) < hitLocations) << 6);
            break;
        }

        if (newSelection != _equipmentDetailSelectedElement) {
            vs_battle_playMenuChangeSfx();
            _equipmentDetailSelectedElement = newSelection;
        }
        if (newSelection < 2) {
            var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                    [VS_ITEMHELP_BIN_INDEX_phantomPointsDesc - newSelection]];
        } else if (newSelection < 9) {
            switch (D_801024B9) {
            case 0:
                var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                        [newSelection + VS_ITEMHELP_BIN_INDEX_damagePointsDesc]];
                break;
            case 1:
                var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                        [newSelection + VS_ITEMHELP_BIN_INDEX_evilClassDesc - 1]];
                break;
            case 2:
                var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                        [newSelection + VS_ITEMHELP_BIN_INDEX_darkAffinityDesc - 1]];
                break;
            }
        } else if (newSelection < 0x10) {
            switch (_selectedEquipmentRow) {
            case 0:
                var_s3 = _drawWeaponInfoRow(newSelection - 9, &temp_s1->weapon);
                break;
            case 1:
                var_s3 = _drawShieldInfoRow(newSelection - 9, &temp_s1->shield);
                break;
            default:
                if ((_selectedEquipmentRow - 2) < hitLocations) {
                    var_s3 = _drawArmorInfoRow(
                        &temp_s1->hitLocations[_selectedEquipmentRow - 2].armor);
                } else {
                    var_s3 = _drawAccessoryInfoRow(&temp_s1->accessory);
                }
                break;
            }
        } else {
            var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                    [newSelection + VS_ITEMHELP_BIN_INDEX_humanClassDesc]];
            if (newSelection >= 18) {
                if (_selectedEquipmentRow == 0) {
                    var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                            [newSelection + VS_ITEMHELP_BIN_INDEX_shortGrip - 1]];
                } else if ((_selectedEquipmentRow - 2) < hitLocations) {
                    var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                            [newSelection + VS_ITEMHELP_BIN_INDEX_polearmGrip]];
                }
            }
        }
        vs_mainmenu_setMessage(var_s3);
        i = D_801021A0[newSelection];
        if ((_selectedEquipmentRow == 1)
            && ((_equipmentDetailSelectedElement - 10) < 2U)) {
            i += 7;
        }
        D_801022D5 = _equipmentDetailSelectedElement != 9;
        _cursorAnimState = func_800FFCDC(_cursorAnimState, i);
        if (vs_main_buttonsPressed.all & PADRup) {
            _exitEquipmentDetail(1);
            return -1;
        }
        if (vs_main_buttonsPressed.all & PADRdown) {
            _initEquipmentScreen(_selectedActor - 1);
            _exitEquipmentDetail(1);
            func_800FFA88(2);
            return _selectedEquipmentRow + 1;
        }
        D_801023E3 = 1;
        func_801013F8(1);
        break;
    }
    return 0;
}

static int _equipmentScreen(int element)
{
    enum state {
        init,
        animWait,
        handleInput,
        waitChangeActor,
        waitActorInit,
        equipDetailScreen
    };

    char* rowStrings[18];
    int rowTypes[9];
    char equipmentDescriptions[9][96];
    func_8006B7BC_t sp3E0;
    int rowCount;
    int hitLocationCount;
    int rowType;
    int temp_s5;
    int i;
    int temp_s1_2;
    vs_battle_menuItem_t* menuItem;
    int new_var;

    vs_battle_actor2* temp_s6 = vs_battle_actors[_selectedActor - 1]->unk3C;
    vs_battle_equipment_hitLocations* hitLocations = temp_s6->hitLocations;

    hitLocationCount = _getHitLocationCount(_selectedActor - 1);
    rowCount = _getEquipmentCount();

    if (element != 0) {
        D_800F4EE8.selectedEquipment = element + 1;
        _equipmentScreenState = init;
        return 0;
    }

    switch (_equipmentScreenState) {
    case init:
        for (i = 0; i < 9; ++i) {
            rowStrings[i * 2] = (char*)&_statusStrings[VS_status_OFFSET_none];
            rowStrings[i * 2 + 1] =
                (char*)&_statusStrings[VS_status_OFFSET_nothingEquipped];
            rowTypes[i] = 1;
        }
        if (temp_s6->weapon.blade.id != 0) {
            vs_mainMenu_setWeaponStrings(
                &temp_s6->weapon, rowStrings, rowTypes, equipmentDescriptions[0]);
            rowStrings[0] = temp_s6->weapon.name;
        }
        if (temp_s6->shield.shield.id != 0) {
            vs_mainMenu_setShieldStrings(
                &temp_s6->shield, &rowStrings[2], rowTypes + 1, equipmentDescriptions[1]);
        }

        temp_s5 = (((temp_s6->flags.u32 >> 0x11) ^ 1) & 1
                   & (_selectedActor != 1)); // Disable row
        new_var = 0xF000;
        temp_s1_2 = 0xF200;
        rowTypes[0] |= temp_s5 | new_var;
        rowTypes[1] |= temp_s5 | temp_s1_2;

        for (i = 2; i < rowCount; ++i, ++hitLocations) {
            func_8006B7BC_t* p = &sp3E0;
            rowType = temp_s5 | 0xF400;
            if ((i - 2) < hitLocationCount) {
                if (hitLocations->armor.armor.id != 0) {
                    vs_mainMenu_setArmorStrings(&hitLocations->armor, &rowStrings[i * 2],
                        &rowTypes[i], equipmentDescriptions[i]);
                }
                rowTypes[i] |= ((hitLocations->nameIndex + 103) << 9) + temp_s5;
            } else {
                func_8006BADC(p, &temp_s6->accessory);
                vs_mainMenu_setAccessoryStrings(
                    p, &rowStrings[i * 2], &rowTypes[i], equipmentDescriptions[i]);
                rowTypes[i] |= rowType;
            }
        }
        temp_s1_2 = vs_main_settings.cursorMemory;
        vs_main_settings.cursorMemory = 1;
        vs_mainmenu_setMenuRows(rowCount, 0x19142, (char**)rowStrings, rowTypes);
        vs_main_settings.cursorMemory = temp_s1_2;
        if (_animationStep != 0) {
            _timer = 10;
        } else {
            _timer = 0;
        }
        _equipmentScreenState = animWait;
        break;
    case animWait:
        if (_timer != 0) {
            --_timer;
            _animationStep = vs_battle_rowAnimationSteps[_timer];
        } else {
            _equipmentScreenState = handleInput;
        }
        break;
    case handleInput:
        i = vs_mainmenu_getSelectedRow() + 1;
        if (i != 0) {
            func_800FBD80(_selectedActor + 15);
            func_800FA8E0(4);
            if (i < 0) {
                temp_s5 = D_800F4EE8.selectedEquipment - 2;
                if (temp_s5 < 0) {
                    temp_s5 = 0;
                }
                if (temp_s5 >= hitLocationCount) {
                    temp_s5 = hitLocationCount - 1;
                }
                _selectedElement = temp_s5;
                return i;
            }
            _equipmentDetailScreen(i);
            _equipmentScreenState = equipDetailScreen;
            break;
        }
        if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {
            i = _selectedActor - 1;
            if (vs_main_buttonsPressed.all & PADL1) {
                i = _getNextValidActor(i, 14);
                temp_s5 = 1;
            }
            if (vs_main_buttonsPressed.all & PADR1) {
                i = _getNextValidActor(i, 1);
                temp_s5 = 17;
            }
            if (i != (_selectedActor - 1)) {
                D_801080A4 = _selectedActor;
                _initEquipmentScreen(i);
                func_80103744(i + temp_s5);
                func_80100814();
                func_800FA8E0(4);
                _equipmentScreenState = waitChangeActor;
            }
        }
        break;
    case waitChangeActor:
        if (func_80103744(0) != 0) {
            _equipmentScreenState = waitActorInit;
        }
        break;
    case waitActorInit:
        if (vs_mainmenu_ready() != 0) {
            menuItem = vs_battle_getMenuItem(4);
            if (menuItem->animSpeed >= 181) {
                menuItem->state = 2;
                menuItem->x = 180;
                menuItem->selected = 1;
            }
            _equipmentScreenState = init;
        }
        break;
    case equipDetailScreen:
        i = _equipmentDetailScreen(0);
        if (i != 0) {
            if (i < 0) {
                return -2;
            }
            D_800F4EE8.selectedEquipment = i - 1;
            _equipmentScreenState = waitActorInit;
        }
        break;
    }
    return 0;
}

static void _fadeScreenLeft(void)
{
    int uv1Tpage;
    u_long* temp_a1;
    u_long* temp_t1;

    temp_a1 = D_1F800000[0];
    temp_t1 = D_1F800000[1];
    if (_fadeScreen != 0) {
        temp_a1[0] = (temp_t1[-1] & 0xFFFFFF) | (13 << 24);
        temp_a1[1] = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOff);
        temp_a1[2] = vs_getRGB0(primPolyGT4, 0, 0, 0);
        temp_a1[3] = vs_getXY(0, 0);
        temp_a1[4] = vs_getUV0Clut(0, 0, 0, 0);
        temp_a1[5] = vs_getRGB888(128, 128, 128);
        temp_a1[6] = vs_getXY(96, 0);

        uv1Tpage = vs_getUV1Tpage(96, 0, 0, 0, direct16Bit, semiTransparencyHalf);
        if (vs_main_frameBuf == 0) {
            uv1Tpage = vs_getUV1Tpage(96, 0, 320, 0, direct16Bit, semiTransparencyHalf);
        }

        temp_a1[7] = uv1Tpage;
        temp_a1[8] = vs_getRGB888(0, 0, 0);
        temp_a1[9] = vs_getXY(0, 240);
        temp_a1[10] = vs_getUV(0, 240);
        temp_a1[11] = vs_getRGB888(128, 128, 128);
        temp_a1[12] = vs_getXY(96, 240);
        temp_a1[13] = vs_getUV(96, 240);
        temp_t1[-1] = (((u_long)temp_a1 << 8) >> 8);
        D_1F800000[0] = temp_a1 + 14;
    }
}

static void _drawMenuBackground(void)
{
    int uv1Tpage;

    u_long* temp_t8 = D_1F800000[0];
    void* temp_a0 = D_1F800000[1];
    u_int* var_t9 = temp_a0 + 0x1FF4;

    if (_drawBackgroundFirst != 0) {
        var_t9 = temp_a0 - 4;
    }
    temp_t8[0] = (*var_t9 & 0xFFFFFF) | (13 << 24);
    temp_t8[1] = vs_getRGB0(primPolyGT4SemiTrans, 16, 16, 16);
    temp_t8[2] = vs_getXY(64, 0);
    temp_t8[3] = vs_getUV0Clut(64, 0, 768, 227);
    temp_t8[4] = vs_getRGB888(144, 144, 144);
    temp_t8[5] = vs_getXY(160, 0);
    temp_t8[6] = vs_getUV1Tpage(160, 0, 640, 256, clut8Bit, semiTransparencyFull);
    temp_t8[7] = vs_getRGB888(16, 16, 16);
    temp_t8[8] = vs_getXY(64, 240);
    temp_t8[9] = vs_getUV(64, 240);
    temp_t8[10] = vs_getRGB888(144, 144, 144);
    temp_t8[11] = vs_getXY(160, 240);
    temp_t8[12] = vs_getUV(160, 240);
    temp_t8[13] = vs_getTpage(0, 0, 0, 0, ditheringOn);
    *var_t9 = ((u_long)temp_t8 << 8) >> 8;
    temp_t8 += 14;
    temp_t8[0] = (int)((*var_t9 & 0xFFFFFF) | (8 << 24));
    temp_t8[1] = vs_getTpage(704, 256, 1, 1, 0);
    temp_t8[2] = vs_getRGB0(primSprt, 128, 128, 128);
    temp_t8[3] = vs_getXY(160, 0);
    temp_t8[4] = vs_getUV0Clut(32, 0, 768, 227);
    temp_t8[5] = vs_getWH(96, 240);
    temp_t8[6] = vs_getRGB0(primTile, 0, 0, 0);
    temp_t8[7] = vs_getXY(256, 0);
    temp_t8[8] = vs_getWH(64, 240);
    *var_t9 = ((u_long)temp_t8 << 8) >> 8;
    temp_t8 += 9;
    temp_t8[0] = (int)((*var_t9 & 0xFFFFFF) | (13 << 24));
    temp_t8[1] = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOff);
    temp_t8[2] = vs_getRGB0(primPolyGT4, 128, 128, 128);
    temp_t8[3] = vs_getXY(64, 0);
    temp_t8[4] = vs_getUV0Clut(64, 0, 0, 0);
    temp_t8[5] = vs_getRGB888(0, 0, 0);
    temp_t8[6] = vs_getXY(160, 0);
    uv1Tpage = vs_getUV1Tpage(160, 0, 0, 0, direct16Bit, semiTransparencyHalf);
    if (vs_main_frameBuf == 0) {
        uv1Tpage = vs_getUV1Tpage(160, 0, 320, 0, direct16Bit, semiTransparencyHalf);
    }
    temp_t8[7] = uv1Tpage;
    temp_t8[8] = vs_getRGB888(128, 128, 128);
    temp_t8[9] = vs_getXY(64, 240);
    temp_t8[10] = vs_getUV(64, 240);
    temp_t8[11] = vs_getRGB888(0, 0, 0);
    temp_t8[12] = vs_getXY(160, 240);
    temp_t8[13] = vs_getUV(160, 240);
    *var_t9 = ((u_long)temp_t8 << 8) >> 8;
    D_1F800000[0] = temp_t8 + 14;
}

static void _drawScreen(void)
{
    int temp_lo_5;
    int xOffset;
    int x;
    int z;
    int* p;

    xOffset = (128 - _animationStep);
    z = D_800F453C->unkC[0x325];
    x = D_800F453C->unkC[0x319];
    p = (int*)D_1F800000 + 13;
    p[4] = ((-vs_math_sine(_xPos) * xOffset) >> 8) * z;
    p[5] = -(x << 0xB);
    p[6] = ((vs_math_cosine(_xPos) * xOffset) >> 8) * z;
    ((int*)D_1F800000)[13] =
        p[4] + ((vs_math_cosine(_xPos) * vs_math_cosine(_yPos)) >> 0xA) * z;
    p[1] = p[5] - vs_math_sine(_yPos) * z * 4;
    temp_lo_5 = (vs_math_sine(_xPos) * vs_math_cosine(_yPos) >> 0xA) * z;
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
    _drawMenuBackground();
    _fadeScreenLeft();
    _drawHitLocationStatuses(0);
    func_80103AC8();
}

static void _printSelectedLocationCondition(void)
{
    vs_battle_equipment_hitLocations* location =
        &vs_battle_actors[_selectedActor - 1]->unk3C->hitLocations[_selectedElement];
    vs_battle_stringContext.strings[0] =
        (char*)&D_800EA868[D_800EA868[location->nameIndex]];
    vs_battle_stringContext.strings[1] =
        (char*)&_statusStrings[_statusStrings[vs_battle_getHitLocationStatus(location)
                                              + VS_status_INDEX_critical]];
    vs_battle_printf(
        vs_battle_stringBuf, (char*)&_statusStrings[VS_status_OFFSET_values]);
    vs_mainmenu_setMessage(vs_battle_stringBuf);
    _drawHitLocationStatuses(_selectedElement + 1);
}

static void _printSelectedLocationStats(void)
{
    int i;
    vs_battle_equipment_hitLocations* location =
        &vs_battle_actors[_selectedActor - 1]->unk3C->hitLocations[_selectedElement];

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i + 16] = location->affinities[i & 7];
    }
    for (i = 0; i < 4; ++i) {
        vs_mainMenu_equipmentStats[i + 32] = location->types[i];
    }
    _drawHitLocationStatuses(_selectedElement + 129);
}

int vs_menu4_Exec(char* state)
{
    enum state {
        none,
        init = 3,
        waitForMenu,
        viewEquipment = 7,
        waitQuitToMenu = 11,
        quitToMenu,
        waitQuitToBattle,
        quitToBattle
    };

    static int animWait;
    static int _screenEnabled;
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
        _screenEnabled = 0;
        _animationIndex = 10;
        if (vs_mainMenu_itemNames == NULL) {
            vs_mainMenu_loadItemNames(1);
        }
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        D_800EB9AE = 1;
        func_8008A4DC(0);
        func_80100414(0x7FE, 0x80);
        _drawBackgroundFirst = 0;
        _fadeScreen = 0;
        _selectedActor = 0;
        D_801080A4 = 0;
        D_801080B8 = 0;
        D_801080B9 = 0;
        D_801080BB = 0;
        func_80103744(1);
        _screenEnabled = 1;
        animWait = 1;
        D_80108188 = vs_main_projectionDistance;
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
        _selectedElement = 0;
        D_80102544 = 0;
        _printSelectedLocationCondition();
        *state = 5;
        break;
    case waitForMenu:
        if (animWait != 0) {
            --animWait;
            _drawHitLocationStatuses(-1);
            func_800FBEA4(1);
        } else {
            _printSelectedLocationCondition();
            *state = 5;
        }
        break;
    case 5:
        var_s5 = 0;
        if ((_selectedActor == 1)
            || (vs_battle_actors[_selectedActor - 1]->unk3C->flags.u32 & 0x20000)) {
            var_s5 = 1;
        }
        if (animWait != 0) {
            if (func_80103744(0) != 0) {
                animWait = 0;
                _drawHitLocationStatuses(-1);
                func_800FBEA4(1);
                userInput = _selectedElement;
                if (userInput < VS_status_INDEX_statDesc) {
                    hitLocations = _getHitLocationCount(_selectedActor - 1) - 1;
                    if (hitLocations < userInput) {
                        _selectedElement = hitLocations;
                    }
                    _printSelectedLocationCondition();
                } else {
                    vs_mainmenu_setMessage((char*)&_statusStrings
                            [_statusStrings[userInput - VS_status_INDEX_statDesc]]);
                }
            }
        } else if (vs_mainMenu_loadItemNames(0) != 0) {
            if (_drawHitLocationStatuses(-3) == 2) {
                if (vs_main_buttonsPressed.all & PADRup) {
                    vs_battle_playMenuLeaveSfx();
                    *state = waitQuitToBattle;
                    break;
                } else if (vs_main_buttonsPressed.all & PADRdown) {
                    vs_battle_playMenuLeaveSfx();
                    *state = waitQuitToMenu;
                    break;
                } else if ((vs_main_buttonsPressed.all & PADRright)
                           && ((_selectedElement
                                   < _getHitLocationCount(_selectedActor - 1))
                               != 0)) {
                    vs_battle_playMenuSelectSfx();
                    func_800FBEA4(2);
                    _drawHitLocationStatuses(-2);
                    animWait = 8;
                    *state = viewEquipment;
                    break;
                }
                var_s6 = 0;
                if (var_s5 != 0) {
                    int temp_s0_2 = _selectedElement;
                    var_s6 = temp_s0_2 < _getHitLocationCount(_selectedActor - 1);
                }
                if (vs_main_buttonsPressed.all & PADRleft) {
                    if (var_s6 != 0) {
                        vs_battle_playMenuSelectSfx();
                        _printSelectedLocationStats();
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
                    hitLocations =
                        vs_battle_mapStickDeadZone(vs_main_stickPosBuf.rStickY);
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
                    static int D_801080C8[] = { 0x001400A0, 0x002400A0, 0x003400A0,
                        0x004400A0, 0x005400A0, 0x006400A0, 0x00920098, 0x009C0098,
                        0x00A60098, 0x0004FFFC, 0x00040042, 0x000CFFFC, 0x000C0042 };

                    static int D_801080FC[] = { 0x000A010A, 0x010A0200, 0x020A0301,
                        0x030A0402, 0x040A0503, 0x050A0604, 0x060D0705, 0x070D0806,
                        0x080D0807, 0x0A090B09, 0x0009000A, 0x000B0D09 };

                    userInput = _selectedElement;
                    hitLocations = D_801080FC[userInput];
                    if (vs_main_buttonRepeat & PADLup) {
                        userInput = hitLocations;
                    } else if (vs_main_buttonRepeat & PADLdown) {
                        userInput = hitLocations >> 8;
                    } else if (vs_main_buttonRepeat & PADLleft) {
                        userInput = hitLocations >> 16;
                    } else {
                        userInput = _selectedElement;
                        if (vs_main_buttonRepeat & PADLright) {
                            userInput = hitLocations >> 24;
                        }
                    }
                    userInput &= 0xFF;
                    _drawHitLocationStatuses(7);
                    if (userInput == 13) {
                        if (_navigateStatusModifiers(
                                vs_battle_actors[_selectedActor - 1]->unk3C, 1)
                            == 0) {
                            vs_battle_playMenuChangeSfx();
                            *state = 6;
                            break;
                        }
                        userInput = _selectedElement;
                    }
                    if (userInput < 6) {
                        hitLocations = _getHitLocationCount(_selectedActor - 1);
                        if (userInput < hitLocations) {
                            _drawHitLocationStatuses(userInput + 1);
                        } else {
                            userInput = 6;
                            if (!(vs_main_buttonRepeat & PADLdown)) {
                                userInput = hitLocations - 1;
                                if (!(vs_main_buttonRepeat & PADLup)) {
                                    _selectedElement = userInput;
                                }
                            }
                        }
                    }
                    D_801022D5 =
                        (userInput < _getHitLocationCount(_selectedActor - 1)) ^ 1;
                    D_80108134 = func_800FFCDC(D_80108134, D_801080C8[userInput]);
                    if (userInput != _selectedElement) {
                        vs_battle_playMenuChangeSfx();
                        if (userInput != 13) {
                            _selectedElement = userInput;
                        }
                    }
                    if (userInput < 6) {
                        _printSelectedLocationCondition();
                    } else {
                        vs_mainmenu_setMessage((char*)&_statusStrings
                                [_statusStrings[userInput - VS_status_INDEX_statDesc]]);
                    }
                }
            }
            userInput = _selectedActor - 1;
            if (vs_main_buttonsPressed.all & PADR1) {
                userInput = _getNextValidActor(userInput, 1);
                hitLocations = 17;
            }
            if (vs_main_buttonsPressed.all & PADL1) {
                userInput = _getNextValidActor(userInput, 14);
                hitLocations = 1;
            }
            if (userInput != (_selectedActor - 1)) {
                D_801080A4 = _selectedActor;
                _drawHitLocationStatuses(-2);
                func_800FBEA4(2);
                _initEquipmentScreen(userInput);
                func_80103744(userInput + hitLocations);
                animWait = 1;
            }
        }
        D_801022D5 = (_selectedElement < _getHitLocationCount(_selectedActor - 1)) ^ 1;
        break;
    case 6:
        var_s5 = 0;
        if ((_selectedActor == 1)
            || (vs_battle_actors[_selectedActor - 1]->unk3C->flags.u32 & 0x20000)) {
            var_s5 = 1;
        }
        if (animWait != 0) {
            if (func_80103744(0) != 0) {
                _navigateStatusModifiers(vs_battle_actors[_selectedActor - 1]->unk3C, 0);
                animWait = 0;
                _drawHitLocationStatuses(-1);
                func_800FBEA4(1);
            }
        } else {
            if (_drawHitLocationStatuses(-3) == 2) {
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
                userInput = _getNextValidActor(userInput, 1);
                hitLocations = 17;
            }
            if (vs_main_buttonsPressed.all & PADL1) {
                userInput = _getNextValidActor(userInput, 14);
                hitLocations = 1;
            }
            if (userInput != (_selectedActor - 1)) {
                D_801080A4 = _selectedActor;
                _drawHitLocationStatuses(-2);
                func_800FBEA4(2);
                _initEquipmentScreen(userInput);
                func_80103744(userInput + hitLocations);
                animWait = 1;
                if (vs_battle_getStatusFlags(vs_battle_actors[userInput]->unk3C) == 0) {
                    *state = 5;
                }
            }
        }
        break;
    case viewEquipment:
        if (animWait == 0) {
            _equipmentScreen(_selectedElement + 1);
            *state = 8;
        } else {
            --animWait;
        }
        break;
    case 8:
        userInput = _equipmentScreen(0);
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
            _animationStep = 128 - vs_battle_rowAnimationSteps[--animWait];
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
                userInput = _selectedElement;
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
                if (userInput != _selectedElement) {
                    vs_battle_playMenuChangeSfx();
                    _selectedElement = userInput;
                    _printSelectedLocationStats();
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

            vs_mainmenu_setMessage((char*)&_statusStrings[_statusStrings
                    [userInput
                        + (hitLocations != 3 ? VS_status_INDEX_physicalDefense
                                             : VS_status_INDEX_bluntDefense)]]);
            D_80108134 = func_800FFCDC(D_80108134, ((userInput * 16) + 50) << 16);
        }
        break;
    case 10:
        var_s5 = 1;
        if (animWait != 0) {
            _animationStep = vs_battle_rowAnimationSteps[--animWait];
        } else {
            _drawHitLocationStatuses(_selectedElement + 1);
            *state = 5;
        }
        break;
    case waitQuitToMenu:
    case waitQuitToBattle:
        func_800FBEA4(2);
        _drawHitLocationStatuses(-2);
        _drawHitLocationStatuses(0);
        _initEquipmentScreen(0);
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
        _screenEnabled = 0;
        ++*state;
        break;
    case quitToMenu:
        _drawHitLocationStatuses(0);
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
        _drawHitLocationStatuses(0);
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

    if (_screenEnabled != 0) {
        _drawScreen();
    }
    if (var_s5 != 0) {
        if (_animationIndex != 0) {
            --_animationIndex;
        }
    } else {
        _animationIndex = vs_battle_animationIndices[_animationIndex];
    }
    if (_animationIndex < 10) {
        userInput = vs_battle_rowAnimationSteps[_animationIndex];
        func_80100344(16 - userInput, 38, 88, 10);
        vs_mainmenu_drawButton(1, 8 - userInput, 36, 0);
        func_800C6540(
            "STATUS", ((0x1C - userInput) & 0xFFFF) | 0x260000, 0x404040 << var_s6, 0);
    }
    return 0;
}
