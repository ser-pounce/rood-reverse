#include "120.h"
#include "src/SLUS_010.40/31724.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/30D14.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/BATTLE/BATTLE.PRG/58578.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/278.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "build/assets/MENU/MENU4.PRG/status.h"
#include "build/assets/MENU/MENU4.PRG/status.h"
#include "build/assets/MENU/ITEMNAME.BIN.h"
#include "build/assets/MENU/ITEMHELP.BIN.h"
#include "gpu.h"
#include <libetc.h>

typedef struct {
    int unk0[8];
} D_80108198_t;

typedef struct {
    int unk0[13];
} D_801081B8_t;

extern u_long* D_1F800000[];

static u_short _statusStrings[] = {
#include "build/assets/MENU/MENU4.PRG/status.vsString"
};

/**
 * Renders stats for the supplied weapon.
 */
static void _drawWeaponInfo(vs_battle_uiWeapon* weapon)
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

        vs_mainMenu_equipmentStats[36] = weapon->damageType;

        vs_mainMenu_setDpPp(
            weapon->currentDp, weapon->maxDp, weapon->currentPp, weapon->maxPp);
        vs_mainMenu_setStrIntAgi(
            weapon->currentStr, weapon->currentInt, weapon->currentAgility, 1);

        vs_mainMenu_strIntAgi[4] = weapon->baseStr;
        vs_mainMenu_strIntAgi[5] = weapon->baseInt;
        vs_mainMenu_strIntAgi[6] = weapon->baseAgility;

        vs_mainMenu_setRangeRisk(weapon->range.range, weapon->risk, 0, 1);
    }

    func_800FBB8C(7);
}

/**
 * Renders stats for the supplied shield.
 */
static void _drawShieldInfo(vs_battle_uiShield* shield)
{
    vs_mainMenu_equipmentSubtype = 8;

    vs_mainMenu_resetStats();

    if (shield->base.id != 0) {
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

        vs_mainMenu_strIntAgi[4] = shield->baseStr;
        vs_mainMenu_strIntAgi[5] = shield->baseInt;
        vs_mainMenu_strIntAgi[6] = shield->baseAgility;
    }
    func_800FBB8C(7);
}

/**
 * Renders stats for the supplied armor.
 */
static void _drawArmorInfo(vs_battle_uiArmor* armor)
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
                armor == &vs_battle_characterState->unk3C->limbs[i].armor;
        }

        for (i = 0; i < 4; ++i) {
            vs_mainMenu_equipmentStats[i + 32] = armor->types[i];
        }

        vs_mainMenu_setDpPp(armor->currentDp, armor->maxDp, 0, 0);
        vs_mainMenu_setStrIntAgi(
            armor->currentStr, armor->currentInt, armor->currentAgility, 1);

        vs_mainMenu_strIntAgi[4] = armor->baseStr;
        vs_mainMenu_strIntAgi[5] = armor->baseInt;
        vs_mainMenu_strIntAgi[6] = armor->baseAgility;
    }

    func_800FBB8C(7);
}

/**
 * Renders stats for the supplied accessory.
 */
static void _drawAccessoryInfo(vs_battle_uiAccessory* accessory)
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

/**
 * Renders stats for the supplied blade.
 */
static void _drawBladeInfo(vs_battle_uiWeapon* weapon)
{
    int i;

    vs_battle_uiEquipment* blade = &weapon->blade;
    vs_mainMenu_equipmentSubtype = 2;

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i] = blade->classes[i & 7];
        vs_mainMenu_equipmentStats[i + 16] = blade->affinities[i & 7];
    }

    vs_mainMenu_setDpPp(blade->currentDp, blade->maxDp, weapon->currentPp, weapon->maxPp);
    vs_mainMenu_setStrIntAgi(blade->strength, blade->intelligence, blade->agility, 1);
    vs_mainMenu_setRangeRisk(blade->range.range, blade->cost, 0, 1);
    func_800FBB8C(3);
    vs_mainMenu_drawDpPpbars(11);
}

/**
 * Renders stats for the supplied grip.
 */
static void _drawGripInfo(vs_battle_uiEquipment* grip)
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

/**
 * Renders stats for the supplied gem.
 */
static void _drawGemInfo(vs_battle_uiEquipment* gem)
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

/**
 * Prints the blade description.
 */
static void _initBladeDescription(vs_battle_uiEquipment* blade, char* menuText[],
    int rowTypes[] __attribute__((unused)))
{
    char* str;

    vs_battle_stringContext.strings[9] =
        vs_mainMenu_itemNames[blade->material - 1 + VS_ITEMNAME_BIN_INDEX_wood];
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

    menuText[1] = vs_battle_stringBuf;
}

/**
 * Prints the grip description.
 */
static void _initGripInfo(
    vs_battle_uiEquipment* grip, char* menuText[], int rowTypes[] __attribute__((unused)))
{
    char* str;

    u_short* gripId = &grip->id;

    vs_battle_stringContext.strings[5] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[grip->category + VS_ITEMHELP_BIN_INDEX_shortGrip - 1]];

    str = vs_battle_printf(vs_battle_stringBuf,
        (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[*gripId - 6]]);
    vs_battle_printf(
        str, (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_gripTemplate]);

    menuText[1] = vs_battle_stringBuf;
}

/**
 * Prints the gem description.
 */
static void _initGemInfo(
    vs_battle_uiEquipment* gem, char* menuText[], int rowTypes[] __attribute__((unused)))
{
    vs_battle_memcpy(vs_battle_stringBuf,
        &vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[gem->id - 261
                                                   + VS_ITEMHELP_BIN_INDEX_gemFeldspar]],
        96);

    menuText[1] = vs_battle_stringBuf;
}

static char* _limbStatuses[] = { "DYING", "BAD", "AVERAGE", "GOOD", "EXCELLENT", NULL };

/**
 * Renders weapon components.
 *
 * @return The description text.
 */
static char* _drawWeaponInfoRow(int row, vs_battle_uiWeapon* weapon)
{
    char* menuText[2];
    int rowType;

    menuText[1] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noGems];

    switch (row) {
    case 0:
        vs_mainMenu_setUiWeapon(weapon, menuText, &rowType, vs_battle_stringBuf);
        menuText[0] = weapon->name;
        break;

    case 1:
        _initBladeDescription(&weapon->blade, menuText, &rowType);
        _drawBladeInfo(weapon);
        break;

    case 2:
        _initGripInfo(&weapon->grip, menuText, &rowType);
        _drawGripInfo(&weapon->grip);
        break;

    case 3:
    case 4:
    case 5:
        if (weapon->gems[row - 3].id != 0) {
            _initGemInfo(&weapon->gems[row - 3], menuText, &rowType);
            _drawGemInfo(&weapon->gems[row - 3]);
        } else {
            vs_mainMenu_drawDpPpbars(8);
            vs_mainMenu_resetStats();
        }
        break;
    }

    vs_battle_getMenuItem(row + 0x14)->selected = 1;

    return menuText[1];
}

/**
 * Renders shield components.
 *
 * @return The description text.
 */
static char* _drawShieldInfoRow(int row, vs_battle_uiShield* shield)
{
    char* menuText[2];
    int rowType;

    menuText[1] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noGems];

    if (row == 0) {
        vs_mainMenu_setUiShield(shield, menuText, &rowType, vs_battle_stringBuf);
    } else if (row < 0) {

    } else if (row < 4) {
        if (shield->gems[row - 1].id != 0) {
            _initGemInfo(&shield->gems[row - 1], (char**)&menuText, &rowType);
            _drawGemInfo(&shield->gems[row - 1]);
        } else {
            vs_mainMenu_drawDpPpbars(8);
            vs_mainMenu_resetStats();
        }
    }
    vs_battle_getMenuItem(row + 20)->selected = 1;
    return menuText[1];
}

/**
 * Renders armor row.
 *
 * @return The description text.
 */
static char* _drawArmorInfoRow(vs_battle_uiArmor* arg0)
{
    char* menuText[2];
    int rowType;

    vs_mainMenu_setUiArmor(arg0, menuText, &rowType, vs_battle_stringBuf);

    return menuText[1];
}

/**
 * Renders accessory row.
 *
 * @return The description text.
 */
static char* _drawAccessoryInfoRow(vs_battle_uiAccessory* arg0)
{
    char* menuText[2];
    vs_battle_inventoryArmor armor;
    int rowType[2];

    vs_battle_copyUiAccessoryStats(&armor, arg0);
    vs_mainMenu_initUiArmor(&armor, menuText, rowType, vs_battle_stringBuf);

    return menuText[1];
}

/**
 * Indicates whether the desired element is reachable from
 * the current element.
 *
 * @return True / false
 */
static int _equipmentDetailElementSelectable(int newSelection, int flags)
{
    int v0;
    int v1;
    int ret = 0;

    switch (newSelection) {
    case 0:
        ret = (flags >> 5) & 1;
        break;

    case 1:
        ret = (flags >> 6) & 1;
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
        v1 = newSelection - 9;
        v0 = flags & 0xF;
        ret = (v0 < v1) ^ 1;
        break;

    case 16:
    case 17:
        ret = (flags >> 4) & 1;
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

/**
 * Iterates through the navigationMap to determine the next element
 * to select.
 *
 * @return The next element to select.
 */
static int _updateEquipmentDetailSelection(u_int newSelection, int flags)
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
        if (_equipmentDetailElementSelectable(newSelection, flags)) {
            break;
        }

        if (previousSelection == newSelection) {

            if ((newSelection - 2) < 14) {
                do {
                    --newSelection;
                } while (!_equipmentDetailElementSelectable(newSelection, flags));

                return newSelection;
            }

            do {
                ++newSelection;
            } while (!_equipmentDetailElementSelectable(newSelection, flags));

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
static int _previousActor = 0;
static int _selectedActor = 0;
static int _drawBackgroundFirst = 0;
static int _fadeScreen = 0;
static int _animationStep = 0;
static char _renderBasicStatsState = 0;
static char _basicStatsAnimState = 0;
static char _basicStatsAnimDelay = 0;
static char _initializedActor = 0;

/**
 * Resets values.
 *
 * @param arg0
 */
static void _initEquipmentScreen(int actor)
{
    if (actor == 0) {
        _renderBasicStatsState = 1;
        _basicStatsAnimDelay = 4;
    } else if (_initializedActor == 0) {
        func_800CB654(1);
        _renderBasicStatsState = 4;
        _basicStatsAnimDelay = 4;
    } else {
        _renderBasicStatsState = 2;
        _basicStatsAnimDelay = 4;
    }

    _initializedActor = actor;
}

/**
 * Determines the next actor for L1 / R1 navigation.
 */
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

static char _delayScreenUpdate = 0;

/**
 * Slides to the next or previous actor.
 *
 * @param init Packed value
 *
 * - Bits 0-3: Target actor
 *
 * - Bit 4: 1 == forward, 0 == reverse
 * @return True if animation complete.
 */
static int _switchCurrentActor(int init)
{
    enum state {
        menuLoaded,
        menuLoading,
        animateForward,
        menuLoadedReverse,
        menuLoadingReverse,
        animateReverse,
        complete
    };

    static u_int state = menuLoaded;

    if (init != 0) {
        if (_selectedActor == 0) {
            state = menuLoading;
        } else {
            vs_battle_playSfx10();
            state = menuLoaded;
        }

        if (init & 0x10) {
            state += 3;
        }

        _selectedActor = init & 0xF;

        vs_battle_setMenuItem(
            4, 180, 18, 140, 8, vs_battle_actors[_selectedActor - 1]->unk3C->name)
            ->selected = 1;

        return 0;
    }

    switch (state) {
    case menuLoaded:
        if (_animationStep < 160) {
            _drawBackgroundFirst = 1;
            _animationStep += 32;
            break;
        } else {
            _drawBackgroundFirst = 0;
            func_800F9E0C();
        }
        // Fallthrough

    case menuLoading:
        _fadeScreen = 1;

        func_800F9A24(_selectedActor - 1);

        _delayScreenUpdate = 1;
        _animationStep = -160;
        state = animateForward;

        break;

    case animateForward:
        if (_animationStep < 0) {
            _animationStep += 32;
            break;
        }

        _fadeScreen = 0;
        state = complete;

        return 1;

    case menuLoadedReverse:
        if (_animationStep >= -159) {
            _fadeScreen = 1;
            _animationStep -= 32;
            break;
        }

        func_800F9E0C();
        // Fallthrough

    case menuLoadingReverse:
        _fadeScreen = 0;

        func_800F9A24(_selectedActor - 1);

        _delayScreenUpdate = 1;
        _animationStep = 160;
        state = animateReverse;

        break;

    case animateReverse:
        if (_animationStep > 0) {
            _drawBackgroundFirst = 1;
            _animationStep -= 32;
            break;
        }

        _drawBackgroundFirst = 0;
        state = complete;
        return 1;

    case complete:
        return 1;
    }

    return 0;
}

/**
 * Used for the stats of unanalyzed enemies.
 *
 * @param withMax Optionally appends "· ???" for values with a maximum.
 */
static void _renderUnknownValue(int xy, int withMax, u_long* before)
{
    int i;

    if (withMax != 0) {
        for (i = 0; i < 3; ++i) {
            vs_battle_setSprite(128, xy, vs_getWH(6, 9), before)[4] =
                vs_getUV0Clut(228, 0, 832, 223);
            xy -= 5;
        }
        vs_battle_renderValue(2, xy, 0, before);
        xy -= 7;
    }

    xy += -1 << 16;

    for (i = 0; i < 3; ++i) {
        vs_battle_setSprite(128, xy, vs_getWH(7, 10), before)[4] =
            vs_getUV0Clut(234, 0, 832, 223);
        xy -= 6;
    }
}

/**
 * Renders a single bar
 *
 * @param colorIndex High byte indicates if enemy has been analyzed,
 * if not then the bar is rendered as if it were full.
 */
static void _renderStatBar(int colorIndex, int current, int max, int xy)
{
    if (max == 0) {
        current = 0;
        max = 1;
    }

    if ((colorIndex >> 8) == 0) {
        current = max;
    }

    current <<= 6;

    vs_battle_renderStatBar(
        colorIndex & 0xFF, ((current + max) - 1) / max, D_1F800000[1] - 3, xy);
}

/**
 * Renders HP / MP / Risk stats of current actor.
 */
static void _renderBasicStats(void)
{
    int i;
    int y;
    vs_battle_actor2* actor = vs_battle_actors[_selectedActor - 1]->unk3C;
    u_long* insertBefore = D_1F800000[1] - 3;

    switch (_renderBasicStatsState) {
    case 0:
        break;
    case 1:
        if (_basicStatsAnimState == 0) {
            if (_basicStatsAnimDelay == 0) {
                func_800CB654(0);
                _renderBasicStatsState = 0;
            } else {
                --_basicStatsAnimDelay;
            }
        } else {
            --_basicStatsAnimState;
            actor = vs_battle_actors[_previousActor - 1]->unk3C;
        }
        break;

    case 2:
        if (_basicStatsAnimState != 0) {
            --_basicStatsAnimState;
            actor = vs_battle_actors[_previousActor - 1]->unk3C;
        } else if (_basicStatsAnimDelay == 0) {
            _renderBasicStatsState = 3;
        } else {
            --_basicStatsAnimDelay;
        }
        break;

    case 3:
        if (_basicStatsAnimState < 4) {
            ++_basicStatsAnimState;
        } else {
            _renderBasicStatsState = 0;
        }
        break;

    case 4:
        if (D_800EB9B0 == 0x200000) {
            if (_basicStatsAnimDelay == 0) {
                _renderBasicStatsState = 3;
            } else {
                --_basicStatsAnimDelay;
            }
        }
        break;
    }

    if (_basicStatsAnimState == 0) {
        return;
    }

    y = ((_basicStatsAnimState * 8) - 22) << 16;

    if (actor->isAnalyzed) {

        i = vs_battle_renderValue(0, y | 66, actor->maxHP, insertBefore);
        vs_battle_renderValue(2, i, 0, insertBefore);
        vs_battle_renderValue(1, i + 0xFFFEFFF9, actor->currentHP, insertBefore);

        i = vs_battle_renderValue(0, y | 136, actor->maxMP, insertBefore);
        vs_battle_renderValue(2, i, 0, insertBefore);
        vs_battle_renderValue(1, i + vs_getXY(-7, -2), actor->currentMP, insertBefore);

        y += 15 << 16;

        vs_battle_renderValue(1, y | 64, actor->risk, insertBefore);

        y += 1 << 16;
    } else {
        _renderUnknownValue(y | 66, 1, insertBefore);
        _renderUnknownValue(y | 136, 1, insertBefore);

        y += 16 << 16;

        _renderUnknownValue(y | 64, 0, insertBefore);
    }

    for (i = 0; i < 3; ++i) {
        vs_battle_setSpriteDefaultTexPage(384,
            D_800EBBEC[i] + ((_basicStatsAnimState - 4) << 0x13), D_800EBBFC[i] | 0x90000,
            insertBefore)[4] = D_800EBC00[i] | 0x37F60000;
    }

    y += -8 << 16;
    i = actor->isAnalyzed << 8;

    _renderStatBar(i, actor->currentHP, actor->maxHP, y | 10);
    _renderStatBar(i | 1, actor->currentMP, actor->maxMP, y | 80);

    y += 4 << 16;

    _renderStatBar(i | 2, actor->risk, 100, y | 10);
}

/**
 * Status represented as a colored square.
 *
 * @param subdued Final color shifted right by this amount, in practice either 0 or 1.
 */
void _drawStatusIndicator(int colorIndex, int xy, int subdued)
{
    u_int color;
    u_long* prim;
    u_long* temp_t1;

    temp_t1 = D_1F800000[2];
    prim = D_1F800000[0];
    color = D_800EBC54[colorIndex] >> subdued;
    prim[0] = (*temp_t1 & 0xFFFFFF) | 0x06000000;
    prim[1] = color | (primTile << 24);
    prim[2] = xy;
    prim[3] = vs_getWH(7, 7);
    prim[4] = (color * 2) | (primTile << 24);
    prim[5] = xy + vs_getXY(1, 1);
    prim[6] = vs_getWH(5, 5);
    *temp_t1 = ((u_long)prim << 8) >> 8;
    D_1F800000[0] = prim + 7;
}

/**
 * Draws the lines extending from the model to the limb name.
 */
static void _drawLimbLeaderLine(
    int limb, int xy, int arg2 __attribute__((unused)), int opaque)
{
    int temp_t2;
    int temp_v0;
    u_long* prim;
    u_long* temp_t0;
    int x;

    opaque = (0x687018 << opaque) | ((33 - opaque) << 25);
    temp_t2 = limb * 16 + 42;
    limb = ((xy >> 16) - temp_t2);

    prim = D_1F800000[0];
    temp_t0 = D_1F800000[1];

    x = (short)xy;

    if (limb < 0) {
        limb = -limb;
    }

    limb = (limb * 3) >> 1;

    prim[0] = (temp_t0[-1] & 0xFFFFFF) | 0x08000000;
    prim[1] = 0xE1000000;
    prim[2] = opaque;
    prim[3] = xy;
    temp_v0 = ((x + ((limb * 2) / 3)) & 0xFFFF) | (temp_t2 << 0x10);
    prim[4] = temp_v0;
    prim[5] = (temp_t0[-1] & 0xFFFFFF) | 0x03000000;
    prim[6] = opaque;
    prim[7] = temp_v0;
    prim[8] = (temp_t2 << 0x10) | 216;
    temp_t0[-1] = (((u_long)prim << 8) >> 8);
    prim += 9;
    D_1F800000[0] = prim;
}

/**
 * Displays the actor's current status effects, sliding in from the left
 * depending on the animation step.
 */
static void _renderStatusIcons(vs_battle_actor2* actor, int animationStep)
{
    int i;

    u_int flags = vs_battle_getStatusFlags(actor);
    int statusCount = 0;

    for (i = 0; i < 32; ++i) {

        int column = statusCount & 7;

        if ((flags >> i) & 1) {
            int x;
            int y;
            int new_var = 16;
            int row = statusCount >> 3;
            ++statusCount;
            column *= 16;
            x = column - (animationStep - new_var);
            y = ((row * new_var) + 144) << new_var;

            if (i >= new_var) {
                // Element indicator
                vs_battle_setSpriteDefaultTexPage(
                    128, ((x + 8) & 0xFFFF) | y, vs_getWH(8, 8), D_1F800000[1] - 2)[4] =
                    ((((i & 3) * 8) + 0x3068) | (getClut(1008, 223) << 16));
            }

            // Nasty match hack
            actor = (vs_battle_actor2*)vs_battle_setSpriteDefaultTexPage(
                128, (x & 0xFFFF) | y, vs_getWH(16, 16), D_1F800000[1] - 2);

            // 0x0F0F906A = Flags for toggling the icon palette
            ((u_long*)actor)[4] =
                (vs_batle_statusIconTexOffsets[i]
                    | (((0x0F0F906A >> i) & 1) ? (getClut(912, 223) << 16)
                                               : (getClut(896, 223) << 16)));
            // 0x37F90000 : 0x37F80000
        }
    }
}

static u_char _selectedElement;

/**
 * Updates the description box and ensures status navigation is
 * bounded correctly.
 */
static int _navigateStatusModifiers(vs_battle_actor2* actor, int arg1)
{
    static char animationState = 0;
    static char activeStatusModifiers[32];
    static u_char selectedStatusModifier;
    static u_char statusModifierCount;
    static char _[2] __attribute__((unused));
    static vs_battle_actor2* statusModifersCurrentTarget;

    int yPos;
    int xPos;

    if (actor != NULL) {

        xPos = vs_battle_getStatusFlags(actor);

        if (xPos == 0) {
            return 1;
        }

        statusModifersCurrentTarget = actor;
        statusModifierCount = 0;

        for (yPos = 0; yPos < 32; ++yPos) {
            if ((xPos >> yPos) & 1) {
                activeStatusModifiers[statusModifierCount++] = yPos;
            }
        }

        if (arg1 == 0) {
            if (selectedStatusModifier >= statusModifierCount) {
                selectedStatusModifier = statusModifierCount - 1;
            }
        } else if (_selectedElement == 11) {
            selectedStatusModifier = 0;
        } else {
            if (statusModifierCount < 8) {
                selectedStatusModifier = statusModifierCount - 1;
            } else {
                selectedStatusModifier = 7;
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

        yPos = selectedStatusModifier;

        if (vs_main_buttonRepeat & PADLup) {
            if (yPos < 8) {
                vs_battle_playMenuChangeSfx();
                _selectedElement = 11;
                return 1;
            }
            yPos -= 8;
        }

        if (vs_main_buttonRepeat & PADLdown) {
            if ((statusModifierCount >= 8) && (yPos < 8)) {
                yPos += 8;
                if (yPos >= statusModifierCount) {
                    yPos = statusModifierCount - 1;
                }
            }
        }

        if (vs_main_buttonRepeat & PADLleft) {
            if (yPos & 7) {
                --yPos;
            }
        }

        if (vs_main_buttonRepeat & PADLright) {

            if (((yPos & 7) == 7) || (yPos == statusModifierCount - 1)) {
                vs_battle_playMenuChangeSfx();
                _selectedElement = 6;
                return 1;
            }

            if (++yPos >= statusModifierCount) {
                yPos = statusModifierCount - 1;
            }
        }

        if (yPos != selectedStatusModifier) {
            vs_battle_playMenuChangeSfx();
            selectedStatusModifier = yPos;
        }
    }

    vs_mainmenu_setInformationMessage((
        char*)&_statusStrings[_statusStrings[activeStatusModifiers[selectedStatusModifier]
                                             + VS_status_INDEX_strDown]]);

    if (arg1 != 0) {
        animationState = func_800FFCDC(
            animationState, (((selectedStatusModifier & 7) * 16) + 2)
                                | ((((selectedStatusModifier >> 3) * 16) + 136) << 0x10));
        D_801022D5 = 1;
    }

    return 0;
}

/**
 * Returns limb count from 0-6  (although in practice any actor has at least 1).
 */
static int _getLimbCount(int actor)
{
    int i;

    for (i = 0; i < 6; ++i) {
        if (vs_battle_actors[actor]->unk3C->limbs[i].nameIndex == 0) {
            break;
        }
    }

    return i;
}

/**
 * Determines equipment row count.
 *
 * @return Number of limbs + 2, +1 if the actor has an accessory.
 */
static int _getEquipmentListRowCount(void)
{
    return _getLimbCount(_selectedActor - 1) + 2
         + (vs_battle_actors[_selectedActor - 1]->unk3C->accessory.accessory.id != 0);
}

enum _renderLimbUiState { _renderLimbUiNone, _renderLimbUiInit };

/**
 * Draws the condition, text, lines etc. for all limbs.
 *
 * @param init
 * @return Current state if init == -3, 0 otherwise.
 */
static int _renderLimbUi(int init)
{
    static char state = 0;
    static u_char tempSelectedActor = 0;
    static char _[8] __attribute__((unused));
    static int limbAnimSteps[6];

    int lineXy[2];
    vs_battle_actor2* actor;
    vs_battle_uiEquipment_limb* limb;
    int limbCount;
    int sp20;
    int sp24;
    int temp_s6;
    int limbStatus;
    int i;
    int step;

    actor = vs_battle_actors[tempSelectedActor]->unk3C;
    limbCount = _getLimbCount(tempSelectedActor);

    if (init != 0) {
        if (init > 0) {
            D_800F4EE8.unk51[49] = init - 1;
            return 0;
        }

        if (init == -3) {
            return state;
        }

        if (init == -2) {
            state = 3;
        } else {
            tempSelectedActor = _selectedActor - 1;
            func_800FBD80(tempSelectedActor);
            for (i = 0; i < 6; ++i) {
                limbAnimSteps[i] = 12 + i;
            }
            state = 1;
        }

        return 0;
    }

    switch (state) {
    case _renderLimbUiNone:
        break;

    case _renderLimbUiInit:
        _renderStatusIcons(actor, vs_battle_rowAnimationSteps[limbAnimSteps[0]]);

        for (i = 0; i < limbCount; ++i) {

            limb = &actor->limbs[i];
            step = limbAnimSteps[i];

            vs_battle_renderTextRaw(vs_battle_limbNames[limb->nameIndex],
                (vs_battle_rowAnimationSteps[step] + 216) | ((34 + i * 16) << 16), NULL);

            limbStatus = vs_battle_getLimbStatus(limb);

            _drawStatusIndicator(limbStatus,
                (vs_battle_rowAnimationSteps[step] + 216) | ((36 + i * 16) << 16), 0);
            vs_battle_renderTextRaw(_limbStatuses[limbStatus],
                (vs_battle_rowAnimationSteps[step] + 224) | ((34 + i * 16) << 16), 0);

            if (step < 8) {
                func_800A13EC(1, limb->unk5, lineXy, 0);
                _drawLimbLeaderLine(i, lineXy[0], 8 - step, 0);
            }

            limbStatus = 0;

            if (step != 0) {
                limbAnimSteps[i] = step - 1;
            } else {
                limbStatus = 1;
            }
        }

        if (limbStatus != 0) {
            state = 2;
        }

        break;

    case 2:
        _renderStatusIcons(actor, 0);

        step = D_800F4EE8.unk51[49];

        for (i = 0; i < limbCount; ++i) {

            limb = &actor->limbs[i];
            temp_s6 = step >> 7;
            sp20 = step - 128;
            sp24 = temp_s6 - 1;

            vs_battle_renderTextRawColor(vs_battle_limbNames[limb->nameIndex],
                216 | ((34 + i * 16) << 16),
                i == sp20 ? vs_getRGB888(128, 128, 128) >> sp24
                          : vs_getRGB888(128, 128, 128) >> temp_s6,
                0);

            limbStatus = vs_battle_getLimbStatus(limb);

            _drawStatusIndicator(
                limbStatus, (0x24 + i * 0x10) * 0x10000 | 0xD8, temp_s6 - (i == sp20));
            vs_battle_renderTextRawColor(_limbStatuses[limbStatus],
                224 | ((34 + i * 16) << 16),
                i == sp20 ? vs_getRGB888(128, 128, 128) >> sp24
                          : vs_getRGB888(128, 128, 128) >> temp_s6,
                0);

            func_800A13EC(1, limb->unk5, lineXy, 0);

            if (!(step & 0x80) && ((_fadeScreen | _drawBackgroundFirst) == 0)) {
                _drawLimbLeaderLine(i, lineXy[0], 8, i == step);
            }
        }
        break;

    case 3:
        _renderStatusIcons(actor, limbAnimSteps[0] << 5);

        for (i = 0; i < limbCount; ++i) {
            if (limbAnimSteps[i] < 8) {

                limb = &actor->limbs[i];
                ++limbAnimSteps[i];

                vs_battle_renderTextRaw(vs_battle_limbNames[limb->nameIndex],
                    ((limbAnimSteps[i] << 5) + 216) | ((34 + i * 16) << 16), 0);

                limbStatus = vs_battle_getLimbStatus(limb);

                _drawStatusIndicator(limbStatus,
                    ((limbAnimSteps[i] << 5) + 216) | ((36 + i * 16) << 16), 0);
                vs_battle_renderTextRaw(_limbStatuses[limbStatus],
                    ((limbAnimSteps[i] << 5) + 224) | ((34 + i * 16) << 16), 0);
            } else {
                state = 0;
            }
        }
        break;
    }
    return 0;
}

/**
 *  Slides the selected row to the left.
 */
static void _setActiveRow(int row)
{
    vs_battle_menuItem_t* menuItem;

    vs_mainMenu_menuItemFlyoutRight(4);

    menuItem = vs_battle_getMenuItem(row + 10);
    menuItem->state = menuItemTransition_toLeft;
    menuItem->targetPosition0 = 155;
    menuItem->selected = 1;
    menuItem->subText = NULL;
}

/**
 * Sets the title and initiates the transition animation for the
 * equiment details screen.
 *
 * @param selectedRow
 */
static void _animateEquipmentDetailTransition(int selectedRow)
{
    char icon;
    vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(32, -164, 18, 164, 8,
        (char*)&_statusStrings[_statusStrings[selectedRow < 2
                                                  ? selectedRow + VS_status_INDEX_weapon
                                                  : VS_status_INDEX_armor]]);

    menuItem->state = 5;
    menuItem->targetPosition0 = 16;
    menuItem->selected = 1;

    icon = 28;

    if (selectedRow == 0) {
        icon = 24;
    } else if (selectedRow == 1) {
        icon = 27;
    }

    menuItem->icon = icon;

    menuItem = vs_battle_getMenuItem(selectedRow + 10);
    menuItem->state = 3;
    menuItem->targetPosition0 = 18;
}

/**
 * General UI init routines.
 */
static void _initUi(int selectedRow, int classAffinity)
{
    _animateEquipmentDetailTransition(selectedRow);
    vs_mainMenu_drawClassAffinityType(classAffinity);
    vs_mainMenu_renderEquipStats(1);
}

/**
 * Renders the weapon and gems if any.
 */
static void _setWeaponRow(int row, vs_battle_uiWeapon* weapon, int init)
{
    char* menuText[2];
    u_int rowType;

    int xOffset = 158;
    int gemSlots = weapon->grip.gemSlots;

    if (row == 1) {
        vs_battle_inventoryBlade blade;
        vs_battle_copyUiBladeStats(&blade, &weapon->blade);
        vs_mainMenu_setUiBlade(&blade, menuText, &rowType, vs_battle_stringBuf);
    } else if (row == 2) {
        vs_battle_inventoryGrip grip;
        vs_battle_copyUiGripStats(&grip, &weapon->grip);
        vs_mainMenu_setUiGrip(&grip, menuText, &rowType, vs_battle_stringBuf);
    } else {

        // xOffset temporarily reused as the gem index
        xOffset = row - 3;

        if (xOffset < gemSlots) {
            menuText[1] = 0;
            menuText[0] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_none];
            rowType = 0x58000000;

            if (weapon->gems[xOffset].id != 0) {
                vs_battle_inventoryGem gem;
                vs_battle_copyUiGemStats(&gem, &weapon->gems[xOffset]);
                vs_mainMenu_setUiGem(&gem, menuText, &rowType, vs_battle_stringBuf);
            }

            xOffset = 151;
        } else {
            xOffset = 0;
        }
    }

    vs_mainMenu_deactivateMenuItem(row + 20);

    if (xOffset != 0) {
        vs_battle_menuItem_t* menuItem = vs_battle_setMenuItem(
            row + 20, 320 - xOffset, (row * 16) + 18, xOffset, 0, menuText[0]);

        menuItem->unselectable = menuText[1] == 0;

        if (init & 1) {
            menuItem->initialX = 320;
            menuItem->state = 2;
            menuItem->targetPosition0 = 320 - xOffset;
        }

        menuItem->icon = rowType >> 26;
        menuItem->material = ((rowType & 0xFFFF0000) >> 16) & 7;
    }
}

/**
 * Renders the shield and gems if any.
 */
static void _setShieldRow(int row, vs_battle_uiShield* shield, int init)
{
    char* menuText[2];
    int rowType;
    int gemSlot = row - 1;

    if (gemSlot < shield->base.gemSlots) {

        menuText[1] = NULL;
        menuText[0] = (char*)(&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_none]);
        rowType = 0x58000000;

        if (shield->gems[gemSlot].id != 0) {
            vs_battle_inventoryGem gem;
            vs_battle_copyUiGemStats(&gem, &shield->gems[gemSlot]);
            vs_mainMenu_setUiGem(&gem, menuText, &rowType, vs_battle_stringBuf);
        }

        gemSlot = 151;
    } else {
        gemSlot = 0;
    }

    vs_mainMenu_deactivateMenuItem(row + 20);

    if (gemSlot != 0) {
        vs_battle_menuItem_t* meuItem = vs_battle_setMenuItem(
            row + 20, 320 - gemSlot, (row * 16) + 18, gemSlot, 0, menuText[0]);
        meuItem->unselectable = menuText[1] == 0;

        if (init & 1) {
            meuItem->initialX = 320;
            meuItem->state = 2;
            meuItem->targetPosition0 = 320 - gemSlot;
        }

        meuItem->icon = 22;
    }
}

/**
 * Clears and restores UI when leaving the details screen.
 *
 * @param clearDpPp Always true in practice.
 */
static void _exitEquipmentDetail(int clearDpPp)
{
    vs_battle_playMenuLeaveSfx();
    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    vs_mainMenu_menuItemFlyoutLeft(0);
    vs_mainMenu_drawClassAffinityType(-1);
    vs_mainMenu_renderEquipStats(2);

    if (clearDpPp != 0) {
        vs_mainMenu_drawDpPpbars(4);
    }
}

/**
 * Manages the sub-display of the selected equipment item.
 *
 * @return -1 on menu quit, positive equipment row to return to
 * if user returns, 0 otherwise.
 */
static int _equipmentDetailScreen(int row)
{
    enum state { init };

    static char _cursorAnimState = 0;
    static char _equipmentDetailState;
    static char _selectedEquipmentRow;
    static char _equipmentDetailRowToRender;
    static char _equipmentDetailSelectedElement;

    char* sp18[2];
    vs_battle_inventoryArmor armor;
    u_int sp48;
    int limbs;
    int equipmentCount;
    int var_a0_5;
    int var_s0_2;
    int i;
    int var_s2;
    int newSelection;
    char* var_s3;
    int previousSelection;
    vs_battle_menuItem_t* menuItem;
    unsigned char state;

    vs_battle_actor2* actor = vs_battle_actors[_selectedActor - 1]->unk3C;

    if (row != 0) {
        _selectedEquipmentRow = row - 1;
        _renderBasicStatsState = 0;

        func_800CB654(1);
        _setActiveRow(_selectedEquipmentRow);
        vs_mainMenu_setNextMenuAction(menuActionNone);

        _equipmentDetailSelectedElement = 9;
        _equipmentDetailRowToRender = 0;
        _equipmentDetailState = init;

        return 0;
    }

    limbs = _getLimbCount(_selectedActor - 1);

    state = _equipmentDetailState;

    switch (state) {
    case init:
        if (_basicStatsAnimState != 0) {
            --_basicStatsAnimState;
        }

        if (vs_mainmenu_ready() == 0) {
            break;
        }

        _initUi(_selectedEquipmentRow, 7);

        switch (_selectedEquipmentRow) {
        case 0:
            vs_mainMenu_drawDpPpbars(3);
            _drawWeaponInfo(&actor->weapon);
            break;

        case 1:
            vs_mainMenu_drawDpPpbars(3);
            _drawShieldInfo(&actor->shield);
            break;

        default:
            if ((_selectedEquipmentRow - 2) < limbs) {
                vs_mainMenu_drawDpPpbars(1);
                _drawArmorInfo(&actor->limbs[_selectedEquipmentRow - 2].armor);
            } else {
                vs_mainMenu_drawDpPpbars(0);
                _drawAccessoryInfo(&actor->accessory);
            }
            break;
        }

        _equipmentDetailState = 1;
        break;

    case 1:
        if (_equipmentDetailRowToRender < 10) {

            ++_equipmentDetailRowToRender;
            _animationStep =
                128 - vs_battle_rowAnimationSteps[10 - _equipmentDetailRowToRender];

            if (_equipmentDetailRowToRender < 6) {
                if (_basicStatsAnimState != 0) {
                    --_basicStatsAnimState;
                }

                _renderBasicStatsState = 0;

                func_800CB654(1);

                if (_selectedEquipmentRow != 0 && _selectedEquipmentRow != state) {
                    return 0;
                }

                if (_selectedEquipmentRow == 0) {
                    _setWeaponRow(_equipmentDetailRowToRender, &actor->weapon, 1);
                } else if (_selectedEquipmentRow == 1) {
                    _setShieldRow(_equipmentDetailRowToRender, &actor->shield, 1);
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
            equipmentCount = _getEquipmentListRowCount();
            var_s2 = _selectedEquipmentRow;

            if (vs_main_buttonRepeat & PADL1) {
                var_s0_2 = equipmentCount - 1;
            }

            if (vs_main_buttonRepeat & PADR1) {
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
                    if (actor->weapon.blade.id != 0) {
                        equipmentCount = 0;
                    }
                    break;

                case 1:
                    if (actor->shield.base.id != 0) {
                        equipmentCount = 0;
                    }
                    break;

                default:
                    if ((var_s2 - 2) >= limbs
                        || (actor->limbs[var_s2 - 2].armor.armor.id != 0)) {
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
                    vs_mainMenu_deactivateMenuItem(i);
                }

                _selectedEquipmentRow = var_s2;

                switch (var_s2) {
                case 0:
                    vs_mainMenu_drawDpPpbars(0xB);
                    _drawWeaponInfo(&actor->weapon);

                    for (i = 1; i < 6; ++i) {
                        _setWeaponRow(i, &actor->weapon, 0);
                    }

                    vs_mainMenu_setUiWeapon(
                        &actor->weapon, sp18, &sp48, vs_battle_stringBuf);

                    sp18[0] = (char*)&actor->weapon;
                    break;

                case 1:
                    vs_mainMenu_drawDpPpbars(0xB);
                    _drawShieldInfo(&actor->shield);

                    for (i = 1; i < 4; ++i) {
                        _setShieldRow(i, &actor->shield, 0);
                    }

                    vs_mainMenu_setUiShield(
                        &actor->shield, sp18, &sp48, vs_battle_stringBuf);

                    break;

                default:
                    if ((var_s2 - 2) < limbs) {
                        vs_mainMenu_drawDpPpbars(9);
                        _drawArmorInfo(&actor->limbs[var_s2 - 2].armor);
                        vs_mainMenu_setUiArmor(&actor->limbs[var_s2 - 2].armor, sp18,
                            &sp48, vs_battle_stringBuf);
                    } else {
                        vs_mainMenu_drawDpPpbars(8);
                        _drawAccessoryInfo((vs_battle_uiAccessory*)&actor->accessory);
                        vs_battle_copyUiAccessoryStats(&armor, &actor->accessory);
                        vs_mainMenu_initUiArmor(&armor, sp18, &sp48, vs_battle_stringBuf);
                    }

                    break;
                }

                menuItem = vs_battle_setMenuItem(var_s2 + 10, 155, 18, 165, 0, sp18[0]);
                menuItem->selected = 1;
                menuItem->icon = (sp48 >> 0x1A);
                menuItem->material = ((sp48 & 0xFFFF0000) >> 16) & 7;

                vs_mainmenu_setInformationMessage(sp18[1]);

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

                menuItem->icon = i;
                _equipmentDetailSelectedElement = 9;
                D_801022D5 = 0;
                _cursorAnimState =
                    func_800FFCDC(_cursorAnimState, vs_mainMenu_mainCursorXY[0]);
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
            _drawWeaponInfo(&actor->weapon);

            newSelection = _updateEquipmentDetailSelection(
                previousSelection, actor->weapon.grip.gemSlots + 114);

            break;

        case 1:
            vs_mainMenu_drawDpPpbars(11);
            _drawShieldInfo(&actor->shield);

            newSelection = _updateEquipmentDetailSelection(
                previousSelection, actor->shield.base.gemSlots + 96);

            break;

        default:
            var_a0_5 = 8;
            if ((_selectedEquipmentRow - 2) < limbs) {
                var_a0_5 = 9;
            }

            vs_mainMenu_drawDpPpbars(var_a0_5);
            newSelection = _updateEquipmentDetailSelection(
                previousSelection, ((_selectedEquipmentRow - 2) < limbs) << 6);

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
        } else if (newSelection < 16) {
            switch (_selectedEquipmentRow) {
            case 0:
                var_s3 = _drawWeaponInfoRow(newSelection - 9, &actor->weapon);
                break;

            case 1:
                var_s3 = _drawShieldInfoRow(newSelection - 9, &actor->shield);
                break;

            default:
                if ((_selectedEquipmentRow - 2) < limbs) {
                    var_s3 =
                        _drawArmorInfoRow(&actor->limbs[_selectedEquipmentRow - 2].armor);
                } else {
                    var_s3 = _drawAccessoryInfoRow(&actor->accessory);
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
                } else if ((_selectedEquipmentRow - 2) < limbs) {
                    var_s3 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                            [newSelection + VS_ITEMHELP_BIN_INDEX_polearmGrip]];
                }
            }
        }

        vs_mainmenu_setInformationMessage(var_s3);

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
            vs_mainMenu_setNextMenuAction(menuActionMenu);
            return _selectedEquipmentRow + 1;
        }

        D_801023E3 = 1;

        func_801013F8(1);
        break;
    }

    return 0;
}

/**
 * Manages the equipment submenu.
 *
 * @return Negative on user exit, 0 otherwise.
 */
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

    static char _equipmentScreenState;
    static u_char _timer;
    static char _[2] __attribute__((unused));

    char* rowStrings[18];
    int rowTypes[9];
    char equipmentDescriptions[9][96];
    vs_battle_inventoryArmor sp3E0;
    int rowCount;
    int limbCount;
    int rowType;
    int temp_s5;
    int i;
    int temp_s1_2;
    vs_battle_menuItem_t* menuItem;
    int new_var;

    vs_battle_actor2* temp_s6 = vs_battle_actors[_selectedActor - 1]->unk3C;
    vs_battle_uiEquipment_limb* limbs = temp_s6->limbs;

    limbCount = _getLimbCount(_selectedActor - 1);
    rowCount = _getEquipmentListRowCount();

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
            vs_mainMenu_setUiWeapon(
                &temp_s6->weapon, rowStrings, rowTypes, equipmentDescriptions[0]);
            rowStrings[0] = temp_s6->weapon.name;
        }

        if (temp_s6->shield.base.id != 0) {
            vs_mainMenu_setUiShield(
                &temp_s6->shield, &rowStrings[2], rowTypes + 1, equipmentDescriptions[1]);
        }

        temp_s5 = (temp_s6->isAnalyzed == 0) & (_selectedActor != 1); // Disable row
        new_var = 0xF000;
        temp_s1_2 = 0xF200;
        rowTypes[0] |= temp_s5 | new_var;
        rowTypes[1] |= temp_s5 | temp_s1_2;

        for (i = 2; i < rowCount; ++i, ++limbs) {
            vs_battle_inventoryArmor* p = &sp3E0;
            rowType = temp_s5 | 0xF400;

            if ((i - 2) < limbCount) {
                if (limbs->armor.armor.id != 0) {
                    vs_mainMenu_setUiArmor(&limbs->armor, &rowStrings[i * 2],
                        &rowTypes[i], equipmentDescriptions[i]);
                }

                rowTypes[i] |= ((limbs->nameIndex + 103) << 9) + temp_s5;

            } else {
                vs_battle_copyUiAccessoryStats(p, &temp_s6->accessory);
                vs_mainMenu_initUiArmor(
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
            vs_mainMenu_clearMenuExcept(4);

            if (i < 0) {
                temp_s5 = D_800F4EE8.selectedEquipment - 2;
                if (temp_s5 < 0) {
                    temp_s5 = 0;
                }
                if (temp_s5 >= limbCount) {
                    temp_s5 = limbCount - 1;
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
                temp_s5 = 1 | (1 << 4);
            }

            if (i != (_selectedActor - 1)) {

                _previousActor = _selectedActor;

                _initEquipmentScreen(i);
                _switchCurrentActor(i + temp_s5);
                func_80100814();
                vs_mainMenu_clearMenuExcept(4);

                _equipmentScreenState = waitChangeActor;
            }
        }
        break;

    case waitChangeActor:
        if (_switchCurrentActor(0)) {
            _equipmentScreenState = waitActorInit;
        }
        break;

    case waitActorInit:
        if (vs_mainmenu_ready() != 0) {

            menuItem = vs_battle_getMenuItem(4);

            if (menuItem->initialX >= 181) {
                menuItem->state = 2;
                menuItem->targetPosition0 = 180;
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

/**
 * Fade effect for the model when sliding in from the left.
 */
static void _fadeScreenLeft(void)
{
    int uv1Tpage;
    u_long* prim = D_1F800000[0];
    u_long* temp_t1 = D_1F800000[1];

    if (_fadeScreen == 0) {
        return;
    }

    prim[0] = (temp_t1[-1] & 0xFFFFFF) | (13 << 24);
    prim[1] = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOff);
    prim[2] = vs_getRGB0(primPolyGT4, 0, 0, 0);
    prim[3] = vs_getXY(0, 0);
    prim[4] = vs_getUV0Clut(0, 0, 0, 0);
    prim[5] = vs_getRGB888(128, 128, 128);
    prim[6] = vs_getXY(96, 0);

    uv1Tpage = vs_getUV1Tpage(96, 0, 0, 0, direct16Bit, semiTransparencyHalf);

    if (vs_main_frameBuf == 0) {
        uv1Tpage = vs_getUV1Tpage(96, 0, 320, 0, direct16Bit, semiTransparencyHalf);
    }

    prim[7] = uv1Tpage;
    prim[8] = vs_getRGB888(0, 0, 0);
    prim[9] = vs_getXY(0, 240);
    prim[10] = vs_getUV(0, 240);
    prim[11] = vs_getRGB888(128, 128, 128);
    prim[12] = vs_getXY(96, 240);
    prim[13] = vs_getUV(96, 240);

    temp_t1[-1] = (((u_long)prim << 8) >> 8);

    D_1F800000[0] = prim + 14;
}

/**
 *  Re-renders background image each frame.
 */
static void _drawMenuBackground(void)
{
    int uv1Tpage;

    u_long* prim = D_1F800000[0];
    void* temp_a0 = D_1F800000[1];
    u_int* var_t9 = temp_a0 + 0x1FF4;

    if (_drawBackgroundFirst != 0) {
        var_t9 = temp_a0 - 4;
    }

    prim[0] = (*var_t9 & 0xFFFFFF) | (13 << 24);
    prim[1] = vs_getRGB0(primPolyGT4SemiTrans, 16, 16, 16);
    prim[2] = vs_getXY(64, 0);
    prim[3] = vs_getUV0Clut(64, 0, 768, 227);
    prim[4] = vs_getRGB888(144, 144, 144);
    prim[5] = vs_getXY(160, 0);
    prim[6] = vs_getUV1Tpage(160, 0, 640, 256, clut8Bit, semiTransparencyFull);
    prim[7] = vs_getRGB888(16, 16, 16);
    prim[8] = vs_getXY(64, 240);
    prim[9] = vs_getUV(64, 240);
    prim[10] = vs_getRGB888(144, 144, 144);
    prim[11] = vs_getXY(160, 240);
    prim[12] = vs_getUV(160, 240);
    prim[13] = vs_getTpage(0, 0, 0, 0, ditheringOn);
    *var_t9 = ((u_long)prim << 8) >> 8;

    prim += 14;
    prim[0] = (int)((*var_t9 & 0xFFFFFF) | (8 << 24));
    prim[1] = vs_getTpage(704, 256, 1, 1, 0);
    prim[2] = vs_getRGB0(primSprt, 128, 128, 128);
    prim[3] = vs_getXY(160, 0);
    prim[4] = vs_getUV0Clut(32, 0, 768, 227);
    prim[5] = vs_getWH(96, 240);
    prim[6] = vs_getRGB0(primTile, 0, 0, 0);
    prim[7] = vs_getXY(256, 0);
    prim[8] = vs_getWH(64, 240);
    *var_t9 = ((u_long)prim << 8) >> 8;

    prim += 9;
    prim[0] = (int)((*var_t9 & 0xFFFFFF) | (13 << 24));
    prim[1] = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOff);
    prim[2] = vs_getRGB0(primPolyGT4, 128, 128, 128);
    prim[3] = vs_getXY(64, 0);
    prim[4] = vs_getUV0Clut(64, 0, 0, 0);
    prim[5] = vs_getRGB888(0, 0, 0);
    prim[6] = vs_getXY(160, 0);
    uv1Tpage = vs_getUV1Tpage(160, 0, 0, 0, direct16Bit, semiTransparencyHalf);

    if (vs_main_frameBuf == 0) {
        uv1Tpage = vs_getUV1Tpage(160, 0, 320, 0, direct16Bit, semiTransparencyHalf);
    }

    prim[7] = uv1Tpage;
    prim[8] = vs_getRGB888(128, 128, 128);
    prim[9] = vs_getXY(64, 240);
    prim[10] = vs_getUV(64, 240);
    prim[11] = vs_getRGB888(0, 0, 0);
    prim[12] = vs_getXY(160, 240);
    prim[13] = vs_getUV(160, 240);
    *var_t9 = ((u_long)prim << 8) >> 8;

    D_1F800000[0] = prim + 14;
}

/**
 * Updates screen.
 */
static void _drawScreen(void)
{
    int temp_lo_5;
    int xOffset = (128 - _animationStep);
    int z = D_800F4538[1]->unk656;
    int x = D_800F4538[1]->unk63E;
    int* p = (int*)D_1F800000 + 13;

    p[4] = ((-rsin(_xPos) * xOffset) >> 8) * z;
    p[5] = -(x << 0xB);
    p[6] = ((rcos(_xPos) * xOffset) >> 8) * z;
    ((int*)D_1F800000)[13] = p[4] + ((rcos(_xPos) * rcos(_yPos)) >> 0xA) * z;
    p[1] = p[5] - rsin(_yPos) * z * 4;

    temp_lo_5 = (rsin(_xPos) * rcos(_yPos) >> 0xA) * z;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[12] = 0x1000;
    p[2] = p[6] + temp_lo_5;

    func_8007ACB0();

    if (_delayScreenUpdate) {
        --_delayScreenUpdate;
    } else {
        func_800F9EB8(p - 8);
    }

    _drawMenuBackground();
    _fadeScreenLeft();
    _renderLimbUi(0);
    _renderBasicStats();
}

/**
 * Retrieves limb condition text.
 */
static void _renderSelectedLimbCondition(void)
{
    vs_battle_uiEquipment_limb* limb =
        &vs_battle_actors[_selectedActor - 1]->unk3C->limbs[_selectedElement];
    vs_battle_stringContext.strings[0] =
        (char*)&vs_battle_statusStrings[vs_battle_statusStrings[limb->nameIndex]];
    vs_battle_stringContext.strings[1] =
        (char*)&_statusStrings[_statusStrings[vs_battle_getLimbStatus(limb)
                                              + VS_status_INDEX_critical]];
    vs_battle_printf(
        vs_battle_stringBuf, (char*)&_statusStrings[VS_status_OFFSET_values]);
    vs_mainmenu_setInformationMessage(vs_battle_stringBuf);
    _renderLimbUi(_selectedElement + 1);
}

/**
 * Syncs the menu stats with the currently selected limb.
 */
static void _renderSelectedLimbStats(void)
{
    int i;
    vs_battle_uiEquipment_limb* limb =
        &vs_battle_actors[_selectedActor - 1]->unk3C->limbs[_selectedElement];

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i + 16] = limb->affinities[i & 7];
    }
    for (i = 0; i < 4; ++i) {
        vs_mainMenu_equipmentStats[i + 32] = limb->types[i];
    }

    _renderLimbUi(_selectedElement + 0x81);
}

static char _selectedStatRow;
static char _[24] __attribute__((unused));

/**
 * Module entrypoint.
 *
 * @return 1 if user exited, 0 otherwise.
 */
int vs_menu4_exec(char* state)
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

    static int D_801080C8[] = { 0x001400A0, 0x002400A0, 0x003400A0, 0x004400A0,
        0x005400A0, 0x006400A0, 0x00920098, 0x009C0098, 0x00A60098, 0x0004FFFC,
        0x00040042, 0x000CFFFC, 0x000C0042 };

    static int D_801080FC[] = { 0x000A010A, 0x010A0200, 0x020A0301, 0x030A0402,
        0x040A0503, 0x050A0604, 0x060D0705, 0x070D0806, 0x080D0807, 0x0A090B09,
        0x0009000A, 0x000B0D09 };

    static int animWait = 0;
    static int screenEnabled = 0;
    static int D_80108134 = 0;
    static int D_80108188;
    static char _[12] __attribute__((unused));
    static D_80108198_t D_80108198;
    static D_801081B8_t D_801081B8;
    static u_char _animationIndex;

    int limbs;
    int var_s5;
    int var_s6;
    D_801081B8_t* var_a0;
    int userInput;
    int new_var2;

    var_s5 = 0;
    var_s6 = 0;

    switch (*state) {
    case init:
        screenEnabled = 0;
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
        _previousActor = 0;
        _renderBasicStatsState = 0;
        _basicStatsAnimState = 0;
        _initializedActor = 0;

        _switchCurrentActor(1);

        screenEnabled = 1;
        animWait = 1;
        D_80108188 = vs_main_projectionDistance;

        vs_battle_setProjectionDistance(0x200);

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

        vs_mainMenu_initTextBox();

        _selectedElement = 0;
        D_80102544 = 0;

        _renderSelectedLimbCondition();

        *state = 5;
        break;

    case waitForMenu:
        if (animWait != 0) {

            --animWait;

            _renderLimbUi(-1);
            vs_mainMenu_renderEquipStats(1);

        } else {

            _renderSelectedLimbCondition();

            *state = 5;
        }
        break;

    case 5:
        var_s5 = 0;

        if ((_selectedActor == 1)
            || vs_battle_actors[_selectedActor - 1]->unk3C->isAnalyzed) {
            var_s5 = 1;
        }

        if (animWait != 0) {
            if (_switchCurrentActor(0)) {

                animWait = 0;

                _renderLimbUi(-1);
                vs_mainMenu_renderEquipStats(1);

                userInput = _selectedElement;

                if (userInput < VS_status_INDEX_statDesc) {
                    limbs = _getLimbCount(_selectedActor - 1) - 1;
                    if (limbs < userInput) {
                        _selectedElement = limbs;
                    }

                    _renderSelectedLimbCondition();
                } else {
                    vs_mainmenu_setInformationMessage((char*)&_statusStrings
                            [_statusStrings[userInput - VS_status_INDEX_statDesc]]);
                }
            }
        } else if (vs_mainMenu_loadItemNames(0) != 0) {
            if (_renderLimbUi(-3) == 2) {
                if (vs_main_buttonsPressed.all & PADRup) {

                    vs_battle_playMenuLeaveSfx();

                    *state = waitQuitToBattle;
                    break;

                } else if (vs_main_buttonsPressed.all & PADRdown) {

                    vs_battle_playMenuLeaveSfx();

                    *state = waitQuitToMenu;
                    break;

                } else if ((vs_main_buttonsPressed.all & PADRright)
                           && ((_selectedElement < _getLimbCount(_selectedActor - 1))
                               != 0)) {

                    vs_battle_playMenuSelectSfx();
                    vs_mainMenu_renderEquipStats(2);
                    _renderLimbUi(-2);

                    animWait = 8;
                    *state = viewEquipment;
                    break;
                }

                var_s6 = 0;

                if (var_s5 != 0) {
                    int temp_s0_2 = _selectedElement;
                    var_s6 = temp_s0_2 < _getLimbCount(_selectedActor - 1);
                }

                if (vs_main_buttonsPressed.all & PADRleft) {
                    if (var_s6 != 0) {

                        vs_battle_playMenuSelectSfx();
                        _renderSelectedLimbStats();
                        vs_mainMenu_drawClassAffinityType(6);

                        _selectedStatRow = 0;
                        animWait = 10;
                        *state = 9;
                        break;
                    }
                    vs_battle_playInvalidSfx();
                }

                if (vs_main_buttonsState & PADL2) {

                    userInput = vs_battle_mapStickDeadZone(vs_main_stickPosBuf.rStickX);
                    limbs = vs_battle_mapStickDeadZone(vs_main_stickPosBuf.rStickY);

                    if (userInput == 0) {
                        if (limbs == 0) {
                            if (vs_main_buttonsState & PADLup) {
                                limbs = -64;
                            }
                            if (vs_main_buttonsState & PADLdown) {
                                limbs = 64;
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
                    _yPos -= limbs;

                    if (_yPos < 0) {
                        _yPos = 0;
                    }
                    if (_yPos > 896) {
                        _yPos = 896;
                    }
                } else {

                    userInput = _selectedElement;
                    limbs = D_801080FC[userInput];

                    if (vs_main_buttonRepeat & PADLup) {
                        userInput = limbs;
                    } else if (vs_main_buttonRepeat & PADLdown) {
                        userInput = limbs >> 8;
                    } else if (vs_main_buttonRepeat & PADLleft) {
                        userInput = limbs >> 16;
                    } else {
                        userInput = _selectedElement;
                        if (vs_main_buttonRepeat & PADLright) {
                            userInput = limbs >> 24;
                        }
                    }

                    userInput &= 0xFF;

                    _renderLimbUi(7);

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

                        limbs = _getLimbCount(_selectedActor - 1);

                        if (userInput < limbs) {
                            _renderLimbUi(userInput + 1);
                        } else {
                            userInput = 6;
                            if (!(vs_main_buttonRepeat & PADLdown)) {
                                userInput = limbs - 1;
                                if (!(vs_main_buttonRepeat & PADLup)) {
                                    _selectedElement = userInput;
                                }
                            }
                        }
                    }

                    D_801022D5 = (userInput < _getLimbCount(_selectedActor - 1)) ^ 1;
                    D_80108134 = func_800FFCDC(D_80108134, D_801080C8[userInput]);

                    if (userInput != _selectedElement) {

                        vs_battle_playMenuChangeSfx();

                        if (userInput != 13) {
                            _selectedElement = userInput;
                        }
                    }

                    if (userInput < 6) {
                        _renderSelectedLimbCondition();
                    } else {
                        vs_mainmenu_setInformationMessage((char*)&_statusStrings
                                [_statusStrings[userInput - VS_status_INDEX_statDesc]]);
                    }
                }
            }
            userInput = _selectedActor - 1;

            if (vs_main_buttonsPressed.all & PADR1) {
                userInput = _getNextValidActor(userInput, 1);
                limbs = 17;
            }

            if (vs_main_buttonsPressed.all & PADL1) {
                userInput = _getNextValidActor(userInput, 14);
                limbs = 1;
            }

            if (userInput != (_selectedActor - 1)) {

                _previousActor = _selectedActor;

                _renderLimbUi(-2);
                vs_mainMenu_renderEquipStats(2);
                _initEquipmentScreen(userInput);
                _switchCurrentActor(userInput + limbs);

                animWait = 1;
            }
        }

        D_801022D5 = (_selectedElement < _getLimbCount(_selectedActor - 1)) ^ 1;
        break;

    case 6:
        var_s5 = 0;

        if ((_selectedActor == 1)
            || vs_battle_actors[_selectedActor - 1]->unk3C->isAnalyzed) {
            var_s5 = 1;
        }

        if (animWait != 0) {
            if (_switchCurrentActor(0)) {

                _navigateStatusModifiers(vs_battle_actors[_selectedActor - 1]->unk3C, 0);

                animWait = 0;

                _renderLimbUi(-1);
                vs_mainMenu_renderEquipStats(1);
            }
        } else {
            if (_renderLimbUi(-3) == 2) {

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
                limbs = 17;
            }

            if (vs_main_buttonsPressed.all & PADL1) {
                userInput = _getNextValidActor(userInput, 14);
                limbs = 1;
            }

            if (userInput != (_selectedActor - 1)) {

                _previousActor = _selectedActor;

                _renderLimbUi(-2);
                vs_mainMenu_renderEquipStats(2);
                _initEquipmentScreen(userInput);
                _switchCurrentActor(userInput + limbs);

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
            vs_mainMenu_drawClassAffinityType(-1);

            if (vs_main_buttonsPressed.all & PADRup) {
                *state = waitQuitToBattle;
                break;
            }

            animWait = 10;
            *state = 10;
        } else {
            if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {

                userInput = _selectedElement;
                limbs = _getLimbCount(_selectedActor - 1);

                if (vs_main_buttonRepeat & PADL1) {
                    char new_var = 1;
                    userInput = (userInput - new_var) + limbs;
                }

                if (vs_main_buttonRepeat & PADR1) {
                    ++userInput;
                }

                if (userInput >= limbs) {
                    userInput -= limbs;
                }

                if (userInput != _selectedElement) {

                    vs_battle_playMenuChangeSfx();

                    _selectedElement = userInput;

                    _renderSelectedLimbStats();
                }
            }

            userInput = _selectedStatRow;
            limbs = 11 - D_801024B9 * 4;

            if (userInput >= limbs) {
                userInput = limbs - 1;
            }

            if (vs_main_buttonRepeat & PADLup) {
                char new_var = 1;
                userInput = (userInput - new_var) + limbs;
            }

            if (vs_main_buttonRepeat & PADLdown) {
                ++userInput;
            }

            if (userInput >= limbs) {
                userInput -= limbs;
            }

            if (userInput != _selectedStatRow) {
                vs_battle_playMenuChangeSfx();
                _selectedStatRow = userInput;
            }

            vs_mainmenu_setInformationMessage((char*)&_statusStrings
                    [_statusStrings[userInput
                                    + (limbs != 3 ? VS_status_INDEX_physicalDefense
                                                  : VS_status_INDEX_bluntDefense)]]);

            D_80108134 = func_800FFCDC(D_80108134, ((userInput * 16) + 50) << 16);
        }
        break;

    case 10:
        var_s5 = 1;

        if (animWait != 0) {
            _animationStep = vs_battle_rowAnimationSteps[--animWait];
        } else {
            _renderLimbUi(_selectedElement + 1);
            *state = 5;
        }
        break;

    case waitQuitToMenu:
    case waitQuitToBattle:
        vs_mainMenu_renderEquipStats(2);
        _renderLimbUi(-2);
        _renderLimbUi(0);
        _initEquipmentScreen(0);
        _renderBasicStats();
        vs_battle_setProjectionDistance(D_80108188);

        new_var2 = 13;
        var_a0 = (D_801081B8_t*)&D_1F800000[new_var2];
        *(D_80108198_t*)&D_1F800000[5] = D_80108198;
        *var_a0 = D_801081B8;

        func_8008A4DC(1);
        vs_mainMenu_setNextMenuAction(menuActionNone);
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        func_800F9E0C();
        func_80100414(-2, 128);

        D_800EB9AE = 0;
        animWait = 8;
        screenEnabled = 0;
        ++*state;
        break;

    case quitToMenu:
        _renderLimbUi(0);
        _renderBasicStats();
        func_800FFB68(0);
        vs_mainMenu_dismissTextBox();

        if (animWait <= 0) {
            if (vs_mainMenu_ensureItemNamesLoaded() != 0) {
                *state = none;
                return 1;
            }
        }

        --animWait;
        break;

    case quitToBattle:
        _renderLimbUi(0);
        _renderBasicStats();
        func_800FFB68(0);
        vs_mainMenu_dismissTextBox();

        if (animWait <= 0) {
            if (vs_mainMenu_ensureItemNamesLoaded() != 0) {
                vs_battle_menuState.currentState = 5;
                *state = none;
                return 1;
            }
        }

        --animWait;
        break;
    }

    if (screenEnabled != 0) {
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

        vs_mainMenu_drawButtonUiBackground(16 - userInput, 38, 88, 10);
        vs_mainmenu_drawButton(1, 8 - userInput, 36, 0);
        vs_battle_renderTextRawColor(
            "STATUS", ((0x1C - userInput) & 0xFFFF) | 0x260000, 0x404040 << var_s6, 0);
    }

    return 0;
}
