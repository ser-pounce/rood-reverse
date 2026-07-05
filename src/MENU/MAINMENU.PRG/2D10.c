#include "2D10.h"
#include "C48.h"
#include "58EC.h"
#include "src/SLUS_010.40/main.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/MENU/MENUD.PRG/234.h"
#include "build/src/include/lbas.h"
#include "build/assets/MENU/ITEMHELP.BIN.h"
#include "build/assets/MENU/ITEMNAME.BIN.h"
#include "gpu.h"
#include "vs_string.h"
#include <libetc.h>

extern u_long* D_1F800000[];

vs_battle_menuItem_t* vs_mainMenu_initWeaponDetailsRow(
    int row, int weaponIndex, int slide)
{
    char* menuText[2];
    int rowType;
    int menuItemId;

    vs_battle_menuItem_t* menuItem = NULL;
    vs_main_inventoryWeapon* weapon = &vs_mainMenu_weapons[weaponIndex - 1];
    int grip = weapon->grip;
    int gemSlots = vs_mainMenu_grips[grip - 1].gemSlots;
    int xOffset = 158;

    if (row == 1) {
        vs_mainMenu_setBladeRow(&vs_mainMenu_blades[weapon->blade - 1], menuText,
            &rowType, vs_battle_stringBuf);
    } else if (row == 2) {
        vs_mainMenu_setGripRow(
            &vs_mainMenu_grips[grip - 1], menuText, &rowType, vs_battle_stringBuf);
    } else {

        xOffset = (row - 3);

        if (xOffset < gemSlots) {
            int gem;

            menuText[1] = NULL;
            rowType = 0x58000000;
            menuText[0] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_none];
            gem = weapon->gems[xOffset];

            if (gem != 0) {
                vs_mainMenu_setGemRow(
                    &vs_mainMenu_gems[gem - 1], menuText, &rowType, vs_battle_stringBuf);
            }

            xOffset = 151;
        } else {
            xOffset = 0;
        }
    }

    menuItemId = row + 10;

    vs_mainMenu_deactivateMenuItem(menuItemId);

    if (xOffset != 0) {

        int x = 320 - xOffset;
        menuItem = vs_battle_setMenuItem(
            menuItemId, x, (row * 16) + 18, xOffset, 0, menuText[0]);
        menuItem->unselectable = menuText[1] == NULL;

        if (slide & 1) {
            menuItem->x = 320;
            menuItem->state = menuItemStateSlideX;
            menuItem->targetPosition0 = x;
        }

        menuItem->rowIcon = (u_int)rowType >> 0x1A;
        menuItem->material = ((u_int)rowType >> 16) & 7;
    }

    return menuItem;
}

vs_battle_menuItem_t* vs_mainMenu_initShieldDetailsRow(
    int row, int shieldIndex, int slide)
{
    char* menuText[2];
    int rowType;

    vs_battle_menuItem_t* menuItem = NULL;
    int xOffset = row - 1;
    vs_main_inventoryShield* shield = &vs_mainMenu_shields[shieldIndex - 1];

    if (xOffset < shield->base.gemSlots) {
        char gem;

        menuText[1] = 0;
        rowType = 0x58000000;
        menuText[0] = (char*)&vs_mainMenu_itemHelp[0x0340B];
        gem = shield->gems[xOffset];

        if (gem != 0) {
            vs_mainMenu_setGemRow(&vs_mainMenu_gems[gem - 1], (char**)&menuText, &rowType,
                vs_battle_stringBuf);
        }

        xOffset = 151;
    } else {
        xOffset = 0;
    }

    vs_mainMenu_deactivateMenuItem(row + 10);

    if (xOffset != 0) {

        menuItem = vs_battle_setMenuItem(
            row + 10, 0x140 - xOffset, (row * 16) + 18, xOffset, 0, (char*)menuText[0]);
        menuItem->unselectable = menuText[1] == 0;

        if (slide & 1) {
            menuItem->x = 320;
            menuItem->state = menuItemStateSlideX;
            menuItem->targetPosition0 = 320 - xOffset;
        }

        menuItem->rowIcon = 0x16;
    }

    return menuItem;
}

u_char vs_mainMenu_weaponHands[] = { 0, 0, 1, 0, 1, 0, 1, 1, 1, 0 };

void vs_mainMenu_setWeaponRow(
    vs_battle_uiWeapon* weapon, char* menuText[], int* rowType, void* buf)
{
    int maxStatRank;

    vs_battle_uiEquipment* blade = &weapon->blade;
    int stats = vs_mainMenu_getEquipmentMaxStats(weapon, 0);

    vs_battle_stringContext.strings[0] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
            [(stats & 0xFF) + VS_ITEMHELP_BIN_INDEX_warriorEquipment - 1]];

    maxStatRank = ((stats >> 8) & 0xFF);

    vs_battle_stringContext.strings[1] = (char*)&vs_mainMenu_itemHelp
        [maxStatRank != 0
                ? vs_mainMenu_itemHelp[maxStatRank + (stats >> 15) - 1
                                       + VS_ITEMHELP_BIN_INDEX_weaponPrestige]
                : vs_mainMenu_itemHelp[blade->category - 1
                                       + VS_ITEMHELP_BIN_INDEX_weaponBasePrestige]];
    vs_battle_stringContext.strings[9] =
        (char*)&vs_mainMenu_itemNames[blade->material - 1 + VS_ITEMNAME_BIN_INDEX_wood];
    vs_battle_stringContext.strings[8] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[blade->category - 1 + VS_ITEMHELP_BIN_INDEX_dagger]];
    vs_battle_stringContext.strings[7] =
        (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[blade->damageType - 1
                                                          + VS_ITEMHELP_BIN_INDEX_blunt]];
    vs_battle_stringContext.strings[6] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[vs_mainMenu_weaponHands[blade->category - 1]
                              + VS_ITEMHELP_BIN_INDEX_oneHanded]];

    vs_battle_printf(
        vs_battle_printf(
            buf, (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_classTemplate]),
        (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_weaponDescTemplate]);

    menuText[1] = buf;
    *rowType = (blade->category << 0x1A) + (blade->material << 0x10);
}

void vs_mainMenu_setWeaponRowFromInventory(
    vs_main_inventoryWeapon* weapon, char* menuText[], int* rowType, void* buf)
{
    vs_battle_uiWeapon uiWeapon;

    if (vs_mainMenu_weapons == vs_main_inventory.weapons) {
        vs_battle_applyWeapon(&uiWeapon, weapon);
    } else {
        vs_menuD_initUiWeapon(&uiWeapon, weapon, &vs_menuD_containerData->data);
    }

    vs_mainMenu_setWeaponRow(&uiWeapon, menuText, rowType, buf);

    menuText[0] = weapon->name;
}

void vs_mainMenu_setBladeRow(
    vs_main_inventoryBlade* blade, char* menuText[], int* rowType, void* buf)
{
    vs_battle_stringContext.strings[9] =
        (char*)&vs_mainMenu_itemNames[blade->material - 1 + VS_ITEMNAME_BIN_INDEX_wood];
    vs_battle_stringContext.strings[8] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[blade->category - 1 + VS_ITEMHELP_BIN_INDEX_dagger]];
    vs_battle_stringContext.strings[7] =
        (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[blade->damageType - 1
                                                          + VS_ITEMHELP_BIN_INDEX_blunt]];
    vs_battle_stringContext.strings[6] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[vs_mainMenu_weaponHands[blade->category - 1]
                              + VS_ITEMHELP_BIN_INDEX_oneHanded]];
    vs_battle_printf(
        vs_battle_printf(
            buf, (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                         [blade->id - 1 + VS_ITEMHELP_BIN_INDEX_battleKnifeDesc]]),
        (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_weaponDescTemplate]);

    menuText[0] = vs_mainMenu_itemNames[blade->id + VS_ITEMNAME_BIN_INDEX_item0];
    menuText[1] = buf;
    *rowType = (blade->category << 0x1A) + (blade->material << 0x10);
}

void vs_mainMenu_setGripRow(
    vs_main_inventoryGrip* grip, char* menuText[], int* rowType, void* buf)
{
    u_short* id;
    vs_battle_stringContext.strings[5] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[grip->category - 1 + VS_ITEMHELP_BIN_INDEX_shortGrip]];
    id = &grip->id;

    vs_battle_printf(vs_battle_printf(buf,
                         (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[*id - 6]]),
        (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_gripTemplate]);

    menuText[0] = vs_mainMenu_itemNames[grip->id + VS_ITEMNAME_BIN_INDEX_item0];
    menuText[1] = buf;
    *rowType = (grip->category + 0xA) << 0x1A;
}

void vs_mainMenu_setShieldRow(
    vs_battle_uiShield* shield, char* menuText[], int* rowType, void* buf)
{
    int maxStatRank;

    vs_battle_uiEquipment* shieldBase = &shield->base;
    int stats = vs_mainMenu_getEquipmentMaxStats(shield, 1);

    vs_battle_stringContext.strings[0] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
            [(stats & 0xFF) - 1 + VS_ITEMHELP_BIN_INDEX_warriorEquipment]];

    maxStatRank = (stats >> 8) & 0xFF;

    vs_battle_stringContext.strings[1] = (char*)&vs_mainMenu_itemHelp
        [maxStatRank != 0 ? vs_mainMenu_itemHelp[maxStatRank + (stats >> 0xF) - 1
                                                 + VS_ITEMHELP_BIN_INDEX_armorPrestige]
                          : VS_ITEMHELP_BIN_OFFSET_armorBasePrestige];
    vs_battle_stringContext.strings[8] =
        (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_armorCategory];
    vs_battle_stringContext.strings[9] =
        (char*)&vs_mainMenu_itemNames[shieldBase->material - 1
                                      + VS_ITEMNAME_BIN_INDEX_wood];

    vs_battle_printf(
        vs_battle_printf(
            buf, (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_classTemplate]),
        (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_armorTemplate]);

    menuText[0] = vs_mainMenu_itemNames[shieldBase->id + VS_ITEMNAME_BIN_INDEX_item0];
    menuText[1] = buf;
    *rowType = (shieldBase->material << 0x10) + 0x3C000000;
}

void vs_mainMenu_setShieldRowFromInventory(
    vs_main_inventoryShield* shield, char* menuText[], int* rowType, void* buf)
{
    vs_battle_uiShield uiShield;

    if (vs_mainMenu_shields == vs_main_inventory.shields) {
        vs_battle_applyShield(&uiShield, shield);
    } else {
        vs_menuD_initUiShield(&uiShield, shield, &vs_menuD_containerData->data);
    }

    vs_mainMenu_setShieldRow(&uiShield, menuText, rowType, buf);
}

void vs_mainMenu_setArmorRow(
    vs_battle_uiArmor* armor, char* menuText[], int* rowType, void* buf)
{
    int stats;
    int maxStatRank;
    vs_battle_uiEquipment* armorBase = &armor->armor;

    menuText[0] = vs_mainMenu_itemNames[armorBase->id];
    *rowType = ((armorBase->category + 14) << 0x1A) + (armorBase->material << 0x10);

    if (armorBase->category == 7) {
        menuText[1] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                [armorBase->id - 223 + VS_ITEMHELP_BIN_INDEX_roodNecklace]];
        return;
    }

    stats = vs_mainMenu_getEquipmentMaxStats(armor, 2);

    vs_battle_stringContext.strings[0] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
            [(stats & 0xFF) - 1 + VS_ITEMHELP_BIN_INDEX_warriorEquipment]];

    maxStatRank = (stats >> 8) & 0xFF;

    vs_battle_stringContext.strings[1] = (char*)&vs_mainMenu_itemHelp
        [maxStatRank != 0
                ? vs_mainMenu_itemHelp[maxStatRank + (stats >> 0xF) - 1
                                       + VS_ITEMHELP_BIN_INDEX_armorPrestige]
                : vs_mainMenu_itemHelp[armorBase->category - 1
                                       + VS_ITEMHELP_BIN_INDEX_armorBasePrestige]];
    vs_battle_stringContext.strings[8] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
            [armorBase->category - 1 + VS_ITEMHELP_BIN_INDEX_armorCategory]];
    vs_battle_stringContext.strings[9] =
        (char*)&vs_mainMenu_itemNames[armorBase->material - 1
                                      + VS_ITEMNAME_BIN_INDEX_wood];

    vs_battle_printf(
        vs_battle_printf(
            buf, (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_classTemplate]),
        (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_armorTemplate]);

    menuText[1] = (char*)buf;
}

void vs_mainMenu_setArmorRowFromInventory(
    vs_main_inventoryArmor* armor, char* menuText[], int* rowType, void* buf)
{
    vs_battle_uiArmor uiArmor;

    vs_battle_applyArmor(&uiArmor, armor);
    vs_mainMenu_setArmorRow(&uiArmor, menuText, rowType, buf);
}

void vs_mainMenu_setGemRow(
    vs_main_inventoryGem* gem, char* menuText[], int* rowType, void* buf)
{
    vs_battle_memcpy(buf,
        vs_mainMenu_itemHelp
            + vs_mainMenu_itemHelp[gem->id - 261 + VS_ITEMHELP_BIN_INDEX_gemFeldspar],
        96);

    menuText[0] = vs_mainMenu_itemNames[gem->id];
    menuText[1] = buf;
    *rowType = 0x58000000;
}

void vs_mainMenu_setMiscRow(
    vs_main_inventoryMisc* misc, char* menuText[], int* rowType, void* buf)
{
    vs_battle_memcpy(buf,
        vs_mainMenu_itemHelp
            + vs_mainMenu_itemHelp[misc->id - 323 + VS_ITEMHELP_BIN_INDEX_cureRootDesc],
        96);

    menuText[0] = vs_mainMenu_itemNames[misc->id];
    menuText[1] = buf;
    *rowType = misc->count << 9;
}

void vs_mainMenu_resetStats(void)
{
    vs_battle_rMemzero(&vs_mainMenu_equipmentStats, sizeof vs_mainMenu_equipmentStats);
    vs_mainMenu_setDpPp(0, 0, 0, 0);
    vs_mainMenu_setStrIntAgi(0, 0, 0, 1);
}

void vs_mainMenu_setStatsFromWeapon(int weaponIndex)
{
    vs_battle_uiWeapon uiWeapon;
    vs_battle_uiWeapon* weapon = &uiWeapon;

    vs_mainMenu_resetStats();
    vs_mainMenu_setRangeRisk(0, 0, 0, 1);

    if (weaponIndex != 0) {
        int i;

        if (vs_mainMenu_weapons[weaponIndex - 1].isEquipped != 0) {
            weapon = &vs_battle_characterState->unk3C->weapon;
        } else if (vs_mainMenu_weapons == vs_main_inventory.weapons) {
            vs_battle_applyWeapon(weapon, &vs_mainMenu_weapons[weaponIndex - 1]);
        } else {
            vs_menuD_initUiWeapon(weapon, &vs_mainMenu_weapons[weaponIndex - 1],
                &vs_menuD_containerData->data);
        }

        vs_battle_memcpy(vs_mainMenu_equipmentStats, &weapon->classAffinityCurrent,
            sizeof weapon->classAffinityCurrent);

        for (i = 0; i < 4; ++i) {
            vs_mainMenu_equipmentStats[32 + i] = weapon->grip.types[i];
        }

        vs_mainMenu_equipmentStats[36] = weapon->damageType;

        do {
        } while (0);

        vs_mainMenu_setDpPp(
            weapon->currentDp, weapon->maxDp, weapon->currentPp, weapon->maxPp);
        vs_mainMenu_setStrIntAgi(
            weapon->currentStr, weapon->currentInt, weapon->currentAgility, 1);
        vs_mainMenu_setRangeRisk(weapon->range.range, weapon->risk, 0, 1);

        vs_mainMenu_strIntAgi[4] = weapon->baseStr;
        vs_mainMenu_strIntAgi[5] = weapon->baseInt;
        vs_mainMenu_strIntAgi[6] = weapon->baseAgility;
    }

    vs_mainMenu_equipmentSubtype = 1;
    vs_mainMenu_currentUiItem = weaponIndex;

    vs_mainMenu_updateStatPage(statPageEnabledAll);
}

void vs_mainMenu_setStatsFromBlade(int bladeIndex)
{
    int i;
    vs_main_inventoryBlade* blade = &vs_mainMenu_blades[bladeIndex - 1];

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i] = blade->classes[i & 7];
        vs_mainMenu_equipmentStats[16 + i] = blade->affinities[i & 7];
    }

    vs_mainMenu_setDpPp(blade->currentDp, blade->maxDp, blade->currentPp, blade->maxPp);
    vs_mainMenu_setStrIntAgi(blade->strength, blade->intelligence, blade->agility, 1);
    vs_mainMenu_setRangeRisk(blade->range.range, blade->cost, 0, 1);

    vs_mainMenu_equipmentSubtype = 2;
    vs_mainMenu_currentUiItem = bladeIndex;

    vs_mainMenu_updateStatPage(statPageEnabledClass | statPageEnabledAffinity);
}

void vs_mainMenu_setStatsFromGrip(int gripIndex)
{
    int i;
    vs_main_inventoryGrip* grip = &vs_mainMenu_grips[gripIndex - 1];

    for (i = 0; i < 4; ++i) {
        vs_mainMenu_equipmentStats[i + 32] = grip->types[i];
    }
    vs_mainMenu_setStrIntAgi(grip->strength, grip->intelligence, grip->agility, 1);

    vs_mainMenu_equipmentSubtype = 4;
    vs_mainMenu_currentUiItem = gripIndex;

    vs_mainMenu_updateStatPage(statPageEnabledType);
}

void vs_mainMenu_setStatsFromShield(int shieldIndex)
{
    vs_battle_uiShield uiShield;
    int i;
    vs_battle_uiShield* shield = &uiShield;

    vs_mainMenu_resetStats();

    if (shieldIndex != 0) {

        if (vs_mainMenu_shields[shieldIndex - 1].isEquipped != 0) {
            shield = &vs_battle_characterState->unk3C->shield;
        } else if (vs_mainMenu_shields == vs_main_inventory.shields) {
            vs_battle_applyShield(shield, &vs_mainMenu_shields[shieldIndex - 1]);
        } else {
            vs_menuD_initUiShield(shield, &vs_mainMenu_shields[shieldIndex - 1],
                &vs_menuD_containerData->data);
        }

        vs_battle_memcpy(vs_mainMenu_equipmentStats, &shield->classAffinityCurrent, 0x40);

        for (i = 0; i < 4; ++i) {
            vs_mainMenu_equipmentStats[32 + i] = shield->types[i];
        }

        vs_mainMenu_setDpPp(
            shield->currentPp, shield->maxPp, shield->currentDp, shield->maxDp);
        vs_mainMenu_setStrIntAgi(
            shield->currentStr, shield->currentInt, shield->currentAgility, 1);

        vs_mainMenu_strIntAgi[4] = shield->baseStr;
        vs_mainMenu_strIntAgi[5] = shield->baseInt;
        vs_mainMenu_strIntAgi[6] = shield->baseAgility;
    }

    vs_mainMenu_equipmentSubtype = 8;
    vs_mainMenu_currentUiItem = shieldIndex;

    vs_mainMenu_updateStatPage(statPageEnabledAll);
}

void vs_mainMenu_setStatsFromArmor(int armorIndex)
{
    vs_battle_uiArmor uiArmor;
    int i;
    vs_battle_uiArmor* armor = &uiArmor;
    int isAccessory = 0;

    vs_mainMenu_resetStats();

    if (armorIndex != 0) {

        u_int limb = vs_mainMenu_armor[armorIndex - 1].limb - 1;

        if (limb < 5) {
            armor = &vs_battle_characterState->unk3C->limbs[limb].armor;
        } else {
            vs_battle_applyArmor(armor, &vs_mainMenu_armor[armorIndex - 1]);
        }

        isAccessory = armor->armor.category == 7;

        vs_battle_memcpy(vs_mainMenu_equipmentStats, &armor->classAffinityCurrent, 0x40);

        for (i = 0; i < 4; ++i) {
            vs_mainMenu_equipmentStats[32 + i] = armor->types[i];
        }

        vs_mainMenu_setDpPp(armor->currentDp, armor->maxDp, 0, 0);
        vs_mainMenu_setStrIntAgi(
            armor->currentStr, armor->currentInt, armor->currentAgility, isAccessory + 1);

        vs_mainMenu_strIntAgi[4] = armor->baseStr;
        vs_mainMenu_strIntAgi[5] = armor->baseInt;
        vs_mainMenu_strIntAgi[6] = armor->baseAgility;
    }

    if (isAccessory != 0) {
        vs_mainMenu_equipmentSubtype = 32;
    } else {
        vs_mainMenu_equipmentSubtype = 16;
    }

    vs_mainMenu_currentUiItem = armorIndex;

    vs_mainMenu_updateStatPage(statPageEnabledAll);
}

void vs_mainMenu_setStatsFromGem(int gemIndex)
{
    int i;
    vs_main_inventoryGem* temp_a2 = &vs_mainMenu_gems[gemIndex - 1];

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i] = temp_a2->classes[i & 7];
        vs_mainMenu_equipmentStats[i + 16] = temp_a2->affinities[i & 7];
    }

    vs_mainMenu_setStrIntAgi(
        temp_a2->strength, temp_a2->intelligence, temp_a2->agility, 1);

    vs_mainMenu_equipmentSubtype = 64;
    vs_mainMenu_currentUiItem = gemIndex;

    vs_mainMenu_updateStatPage(statPageEnabledClass | statPageEnabledAffinity);
}

/**
 * Updates the UI for the selected weapon status row.
 *
 * @param row
 * @return Pointer to description.
 */
static char* _weaponStatusView(int row)
{
    char* menuText[2];
    int rowType;
    int gem;
    int weaponId;
    vs_main_inventoryWeapon* weapon;

    menuText[1] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noGems];
    weaponId = vs_mainMenu_currentUiItem;
    weapon = &vs_mainMenu_weapons[weaponId - 1];

    switch (row) {
    case 0:
        vs_mainMenu_setWeaponRowFromInventory(
            weapon, menuText, &rowType, vs_battle_stringBuf);
        break;

    case 1:
        vs_mainMenu_renderDpPpBars(renderDpPpBarsTargetBoth | renderDpPpBarsStatStatic);
        vs_mainMenu_setBladeRow(&vs_mainMenu_blades[weapon->blade - 1], menuText,
            &rowType, vs_battle_stringBuf);
        vs_mainMenu_setStatsFromBlade(weapon->blade);
        break;

    case 2:
        vs_mainMenu_renderDpPpBars(renderDpPpBarsTargetNone | renderDpPpBarsStatStatic);
        vs_mainMenu_setGripRow(&vs_mainMenu_grips[weapon->grip - 1], menuText, &rowType,
            vs_battle_stringBuf);
        vs_mainMenu_setStatsFromGrip(weapon->grip);
        break;

    case 3:
    case 4:
    case 5:
        vs_mainMenu_renderDpPpBars(renderDpPpBarsTargetNone | renderDpPpBarsStatStatic);
        gem = weapon->gems[row - 3];

        if (gem != 0) {
            vs_mainMenu_setGemRow(
                &vs_mainMenu_gems[gem - 1], menuText, &rowType, vs_battle_stringBuf);
            vs_mainMenu_setStatsFromGem(gem);
        } else {
            vs_mainMenu_resetStats();
        }

        break;
    }

    vs_mainMenu_equipmentSubtype = 1;
    vs_mainMenu_currentUiItem = weaponId;

    vs_battle_getMenuItem(row + 10)->selected = 1;

    // BUG: Returns stack temporary
    return menuText[1];
}

/**
 * Updates the UI for the selected blade status row.
 *
 * @param row
 * @return Pointer to description.
 */
static char* _bladeStatusView(int arg0 __attribute__((unused)))
{
    char* menuText[2];
    int rowType;

    vs_mainMenu_setBladeRow(&vs_mainMenu_blades[vs_mainMenu_currentUiItem - 1], menuText,
        &rowType, vs_battle_stringBuf);

    // BUG: Returns stack temporary
    return menuText[1];
}

/**
 * Updates the UI for the selected grip status row.
 *
 * @param row
 * @return Pointer to description.
 */
static char* _gripStatusView(int arg0 __attribute__((unused)))
{
    char* menuText[2];
    int rowType;

    vs_mainMenu_setGripRow(&vs_mainMenu_grips[vs_mainMenu_currentUiItem - 1], menuText,
        &rowType, vs_battle_stringBuf);

    // BUG: Returns stack temporary
    return menuText[1];
}

/**
 * Updates the UI for the selected shield status row.
 *
 * @param row
 * @return Pointer to description.
 */
static char* _shieldStatusView(int arg0)
{
    char* menuText[2];
    int rowType;
    int gem;
    int temp_s2;
    vs_main_inventoryShield* shield;

    menuText[1] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noGems];
    shield = &vs_mainMenu_shields[vs_mainMenu_currentUiItem - 1];
    temp_s2 = vs_mainMenu_currentUiItem;

    if (arg0 == 0) {
        vs_mainMenu_setShieldRowFromInventory(
            shield, menuText, &rowType, vs_battle_stringBuf);
    } else if (arg0 >= 0) {
        if (arg0 < 4) {

            vs_mainMenu_renderDpPpBars(8);

            gem = shield->gems[arg0 - 1];

            if (gem != 0) {
                vs_mainMenu_setGemRow(
                    &vs_mainMenu_gems[gem - 1], menuText, &rowType, vs_battle_stringBuf);
                vs_mainMenu_setStatsFromGem(gem);
            } else {
                vs_mainMenu_resetStats();
            }
        }
    }

    vs_mainMenu_equipmentSubtype = 8;
    vs_mainMenu_currentUiItem = temp_s2;

    vs_battle_getMenuItem(arg0 + 10)->selected = 1;

    // BUG: Returns stack temporary
    return menuText[1];
}

/**
 * Updates the UI for the selected armor status row.
 *
 * @param row
 * @return Pointer to description.
 */
static char* _armorStatusView(int arg0 __attribute__((unused)))
{
    char* menuText[2];
    int rowType;

    vs_mainMenu_setArmorRowFromInventory(
        &vs_mainMenu_armor[vs_mainMenu_currentUiItem - 1], menuText, &rowType,
        vs_battle_stringBuf);

    // BUG: Returns stack temporary
    return menuText[1];
}

/**
 * Updates the UI for the selected gem status row.
 *
 * @param row
 * @return Pointer to description.
 */
static char* _gemStatusView(int arg0 __attribute__((unused)))
{
    char* menuText[2];
    int rowType;

    vs_mainMenu_setGemRow(&vs_mainMenu_gems[vs_mainMenu_currentUiItem - 1], menuText,
        &rowType, vs_battle_stringBuf);

    // BUG: Returns stack temporary
    return menuText[1];
}

void vs_mainMenu_resetStatusViewCursor(void)
{
    vs_mainMenu_selectedStatusViewElement = 9;
}

/**
 * An unused status view UI element that sat between the item
 * details rows and the base stats.
 */
static char _uIElement15Enabled = 0;

/**
 * Indicates whether the selected transition is valid.
 *
 * @return True / false.
 */
static int _isUiElementReachable(int selectedElement)
{
    int var_a0 = 0;
    int subType = vs_mainMenu_equipmentSubtype;

    switch (selectedElement) {
    case 0:
        var_a0 = subType & 0xB;
        break;
    case 1:
        var_a0 = subType & 0x1B;
        break;
    case 2:
    case 3:
    case 4:
        var_a0 = 1;
        break;

    case 5:
    case 6:
    case 7:
        var_a0 = vs_mainMenu_itemStatPage != statPageType;
        break;

    case 8:
        var_a0 = vs_mainMenu_itemStatPage == statPageAffinity;
        break;

    case 9:
        var_a0 = 1;
        // Fallthrough

    case 10:
    case 11:
    case 12:
        if ((subType & 8) && (vs_mainMenu_currentUiItem != 0)) {
            var_a0 = (selectedElement - 10)
                   < vs_mainMenu_shields[vs_mainMenu_currentUiItem - 1].base.gemSlots;
            break;
        }
        // Fallthrough

    case 13:
    case 14:
        if ((subType & 1) && (vs_mainMenu_currentUiItem != 0)) {
            var_a0 = (selectedElement - 12)
                   < vs_mainMenu_grips
                         [vs_mainMenu_weapons[vs_mainMenu_currentUiItem - 1].grip - 1]
                             .gemSlots;
        }
        break;

    case 15:
        var_a0 = _uIElement15Enabled;
        break;

    case 16:
    case 17:
        var_a0 = subType & 3;
        break;

    case 18:
    case 19:
    case 20:
        var_a0 = 1;
        break;
    }

    return var_a0;
}

u_char vs_mainMenu_statusViewNavigationMap[][4] = { { 0, 2, 1, 10 }, { 1, 2, 1, 0 },
    { 1, 3, 2, 11 }, { 2, 4, 3, 12 }, { 3, 5, 4, 13 }, { 4, 6, 5, 14 }, { 5, 7, 6, 16 },
    { 6, 8, 7, 17 }, { 7, 8, 8, 18 }, { 9, 10, 0, 9 }, { 9, 11, 0, 10 },
    { 10, 12, 2, 11 }, { 11, 13, 3, 12 }, { 12, 14, 4, 13 }, { 13, 15, 5, 14 },
    { 14, 16, 5, 15 }, { 15, 17, 6, 16 }, { 16, 18, 7, 17 }, { 17, 19, 8, 18 },
    { 18, 20, 8, 19 }, { 19, 20, 8, 20 } };

int vs_mainMenu_statusViewCursorPositions[] = { vs_getXY(66, 28), vs_getXY(-4, 28),
    vs_getXY(0, 50), vs_getXY(0, 66), vs_getXY(0, 82), vs_getXY(0, 98), vs_getXY(0, 114),
    vs_getXY(0, 130), vs_getXY(0, 146), vs_getXY(141, 10), vs_getXY(148, 26),
    vs_getXY(148, 42), vs_getXY(155, 58), vs_getXY(155, 74), vs_getXY(155, 90),
    vs_getXY(180, 24), vs_getXY(192, 126), vs_getXY(192, 136), vs_getXY(152, 146),
    vs_getXY(152, 156), vs_getXY(152, 166) };

void vs_mainMenu_renderStatusView(void)
{
    static char* (*statusViewDispatch[])(int row) = { _weaponStatusView, _bladeStatusView,
        _gripStatusView, _shieldStatusView, _armorStatusView, _armorStatusView,
        _gemStatusView };

    static char cursorAnimStep = 0;
    static char previousItem = 0;

    char* infoMsg;
    u_int selectedElement = vs_mainMenu_selectedStatusViewElement;
    int direction = 0;
    int i = selectedElement;

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
        vs_mainMenu_selectedStatusViewElement =
            vs_mainMenu_statusViewNavigationMap[selectedElement][direction - 1];
    }

    while (_isUiElementReachable(vs_mainMenu_selectedStatusViewElement) == 0) {

        if (selectedElement == vs_mainMenu_selectedStatusViewElement) {

            if ((selectedElement - 2) < 14) {
                do {
                    --vs_mainMenu_selectedStatusViewElement;
                } while (
                    _isUiElementReachable(vs_mainMenu_selectedStatusViewElement) == 0);
            } else {
                do {
                    ++vs_mainMenu_selectedStatusViewElement;
                } while (
                    _isUiElementReachable(vs_mainMenu_selectedStatusViewElement) == 0);
            }

            break;

        } else {
            selectedElement = vs_mainMenu_selectedStatusViewElement;
            vs_mainMenu_selectedStatusViewElement =
                vs_mainMenu_statusViewNavigationMap[selectedElement][direction - 1];
        }
    }

    if (previousItem == vs_mainMenu_currentUiItem) {
        if (i != vs_mainMenu_selectedStatusViewElement) {
            vs_battle_playMenuChangeSfx();
        }
    } else {
        previousItem = vs_mainMenu_currentUiItem;
    }

    for (i = 11; i < 16; ++i) {
        vs_battle_getMenuItem(i)->selected = 0;
    }

    if (vs_mainMenu_equipmentSubtype & 1) {
        vs_mainMenu_renderDpPpBars(11);
        vs_mainMenu_setStatsFromWeapon(vs_mainMenu_currentUiItem);
    }

    if (vs_mainMenu_equipmentSubtype & 8) {
        vs_mainMenu_renderDpPpBars(11);
        vs_mainMenu_setStatsFromShield(vs_mainMenu_currentUiItem);
    }

    if (vs_mainMenu_equipmentSubtype & 0x10) {
        vs_mainMenu_renderDpPpBars(9);
    }

    if (vs_mainMenu_equipmentSubtype & 0x20) {
        vs_mainMenu_renderDpPpBars(8);
    }

    if (vs_mainMenu_selectedStatusViewElement < (statusUiDp + 1)) {

        infoMsg = (char*)&vs_mainMenu_itemHelp
            [vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_INDEX_phantomPointsDesc
                                  - vs_mainMenu_selectedStatusViewElement]];

    } else if (vs_mainMenu_selectedStatusViewElement
               < (statusUistatPageLastElement + 1)) {

        switch (vs_mainMenu_itemStatPage) {
        case statPageClass:
            infoMsg = (char*)&vs_mainMenu_itemHelp
                [vs_mainMenu_itemHelp[vs_mainMenu_selectedStatusViewElement - 2
                                      + VS_ITEMHELP_BIN_INDEX_humanClassDesc]];
            break;

        case statPageAffinity:
            infoMsg = (char*)&vs_mainMenu_itemHelp
                [vs_mainMenu_itemHelp[vs_mainMenu_selectedStatusViewElement - 2
                                      + VS_ITEMHELP_BIN_INDEX_physicalAffinityDesc]];
            break;

        case statPageType:
            infoMsg = (char*)&vs_mainMenu_itemHelp
                [vs_mainMenu_itemHelp[vs_mainMenu_selectedStatusViewElement - 2
                                      + VS_ITEMHELP_BIN_INDEX_bluntTypeDesc]];
            break;
        }

    } else {

        if (vs_mainMenu_selectedStatusViewElement < 15) {

            for (i = 0; i < 7; ++i) {
                if ((vs_mainMenu_equipmentSubtype >> i) & 1) {
                    // BUG: The methods in statusViewDispatch return stack temporaries.
                    infoMsg =
                        statusViewDispatch[i](vs_mainMenu_selectedStatusViewElement - 9);
                }
            }

        } else if (vs_mainMenu_selectedStatusViewElement == 15) {
            // Unused, see `_uIElement15Enabled`
            infoMsg = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_endsSetup];
        } else {

            infoMsg = (char*)&vs_mainMenu_itemHelp
                [vs_mainMenu_itemHelp[vs_mainMenu_selectedStatusViewElement - 16
                                      + VS_ITEMHELP_BIN_INDEX_rangeDesc]];

            if (vs_mainMenu_selectedStatusViewElement >= 18) {

                if (vs_mainMenu_equipmentSubtype & 7) {
                    infoMsg = (char*)&vs_mainMenu_itemHelp
                        [vs_mainMenu_itemHelp[vs_mainMenu_selectedStatusViewElement - 18
                                              + VS_ITEMHELP_BIN_INDEX_attackStr]];
                }

                if (vs_mainMenu_equipmentSubtype & 0x18) {
                    infoMsg = (char*)&vs_mainMenu_itemHelp
                        [vs_mainMenu_itemHelp[vs_mainMenu_selectedStatusViewElement - 18
                                              + VS_ITEMHELP_BIN_INDEX_defStr]];
                }
            }
        }
    }

    // BUG: If `infoMsg` resulted from an invocation of one of the statusViewDispatch
    // methods, the only reason this works is due to proximity.
    vs_mainmenu_setInformationMessage(infoMsg);

    i = vs_mainMenu_statusViewCursorPositions[vs_mainMenu_selectedStatusViewElement];

    if (vs_mainMenu_selectedStatusViewElement == 15) {
        i += _uIElement15Enabled << 0x14;
    }

    if (vs_mainMenu_equipmentSubtype & 8) {
        if ((vs_mainMenu_selectedStatusViewElement - 10u) < 2u) {
            i += 7;
        }
    }

    cursorAnimStep = vs_mainMenu_renderCursor(cursorAnimStep, i);
    _uIElement15Enabled = 0;
}

void vs_mainMenu_unequipWeapon(void)
{
    int i;

    vs_battle_equipWeapon(NULL);

    for (i = 0; i < 8; ++i) {
        vs_main_inventory.weapons[i].isEquipped = 0;
    }
}

void vs_mainMenu_unequipShield(void)
{
    int i;

    vs_battle_equipShield(NULL);

    for (i = 0; i < 8; ++i) {
        vs_main_inventory.shields[i].isEquipped = 0;
    }
}

void vs_mainMenu_initItem(int itemCategory, int index)
{
    int i;

    switch (itemCategory) {
    case itemCategoryWeapon: {
        vs_main_inventoryWeapon* weapon = &vs_main_inventory.weapons[index - 1];

        vs_mainMenu_initItem(itemCategoryBlade, weapon->blade);
        vs_mainMenu_initItem(itemCategoryGrip, weapon->grip);

        for (i = 0; i < 3; ++i) {
            int gem = weapon->gems[i];

            if (gem != 0) {
                vs_mainMenu_initItem(itemCategoryGem, gem);
            }
        }

        vs_battle_rMemzero(weapon, sizeof *weapon);

        weapon->index = index;
        break;
    }

    case itemCategoryBlade: {
        vs_main_inventoryBlade* blade = &vs_main_inventory.blades[index - 1];

        vs_battle_rMemzero(blade, sizeof *blade);

        blade->index = index;
        break;
    }

    case itemCategoryGrip: {
        vs_main_inventoryGrip* grip = &vs_main_inventory.grips[index - 1];

        vs_battle_rMemzero(grip, sizeof *grip);

        grip->index = index;
        break;
    }

    case itemCategoryShield: {
        vs_main_inventoryShield* shield = &vs_main_inventory.shields[index - 1];

        for (i = 0; i < 3; ++i) {
            int gem = shield->gems[i];

            if (gem != 0) {
                vs_mainMenu_initItem(itemCategoryGem, gem);
            }
        }

        vs_battle_rMemzero(shield, sizeof *shield);

        shield->index = index;
        break;
    }

    case itemCategoryArmor: {
        vs_main_inventoryArmor* armor = &vs_main_inventory.armor[index - 1];

        vs_battle_rMemzero(armor, sizeof *armor);

        armor->index = index;
        break;
    }

    case itemCategoryGem: {
        vs_main_inventoryGem* gem = &vs_main_inventory.gems[index - 1];

        vs_battle_rMemzero(gem, sizeof *gem);

        gem->index = index;
        break;
    }

    case itemCategoryMisc: {
        vs_main_inventoryMisc* misc = &vs_main_inventory.misc[index - 1];

        vs_battle_rMemzero(misc, sizeof *misc);

        misc->index = index;
        break;
    }
    }
}

int vs_mainMenu_loadItemText(int load)
{
    static int bss_2 __attribute__((unused)); // Garbage, patched in MAINMENU_PRG.py
    static vs_main_CdQueueSlot* _itemNamesCdQueueSlot;
    static char _itemNamesLoading;

    vs_main_CdFile cdFile;

    if (load != 0) {

        vs_mainMenu_itemNames = vs_main_allocHeapR(
            VS_ITEMNAME_BIN_SIZE + VS_ITEMHELP_BIN_SIZE + VS_MENU12_BIN_SIZE);
        vs_mainMenu_itemHelp = (void*)vs_mainMenu_itemNames + VS_ITEMNAME_BIN_SIZE;
        vs_mainMenu_menu12Text = (void*)vs_mainMenu_itemHelp + VS_ITEMHELP_BIN_SIZE;

        // These three files must be contiguous on disk
        cdFile.lba = VS_ITEMNAME_BIN_LBA;
        cdFile.size = VS_ITEMNAME_BIN_SIZE + VS_ITEMHELP_BIN_SIZE + VS_MENU12_BIN_SIZE;

        _itemNamesCdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);

        vs_main_cdEnqueue(_itemNamesCdQueueSlot, vs_mainMenu_itemNames);

        _itemNamesLoading = 1;
        return 0;
    }

    if (_itemNamesLoading == 0) {
        return 1;
    }

    if (_itemNamesCdQueueSlot->state == 4) {

        vs_main_freeCdQueueSlot(_itemNamesCdQueueSlot);

        _itemNamesLoading = 0;
        return 1;
    }

    return 0;
}

int vs_mainMenu_ensureItemTextUnloaded(void)
{
    if (vs_mainMenu_itemNames == NULL) {
        return 1;
    }

    if (vs_mainMenu_loadItemText(0) != 0) {

        vs_main_freeHeapR(vs_mainMenu_itemNames);

        vs_mainMenu_itemNames = NULL;
        return 1;
    }

    return 0;
}

/**
 * Gets the ID for the selected category. Weapons are identified by their attached blade.
 */
static int _getItemId(int category, int index, vs_main_inventory_t* inventory)
{
    int id = 0;

    if (inventory == NULL) {
        inventory = &vs_main_inventory;
    }

    switch (category) {
    case 0:
        id = inventory->weapons[index].blade;
        break;

    case 1:
        id = inventory->blades[index].id;
        break;

    case 2:
        id = inventory->grips[index].id;
        break;

    case 3:
        id = inventory->shields[index].base.id;
        break;

    case 4:
        id = inventory->armor[index].id;
        break;

    case 5:
        id = inventory->gems[index].id;
        break;

    case 6:
        id = inventory->misc[index].id;
        break;
    }

    return id;
}

int vs_mainMenu_findItem(int category, int id)
{
    int i;

    u_char* index = vs_mainMenu_inventoryIndices[category];
    u_char capacity = vs_mainMenu_inventoryItemCapacities[category];

    for (i = 0; i < capacity; ++i) {
        if (index[i] == (id + 1)) {
            return i + 1;
        }
    }

    return 0;
}

/**
 * Updates `vs_mainMenu_inventoryIndices` with the provided id.
 */
static void _setItemIndex(int itemCategory, int id)
{
    int i;
    u_char* index = vs_mainMenu_inventoryIndices[itemCategory];

    for (i = 0; i < vs_mainMenu_inventoryItemCapacities[itemCategory]; ++i) {
        if (index[i] == 0) {
            index[i] = id + 1;
            return;
        }
    }
}

void vs_mainMenu_rebuildInventory(int itemCategory)
{
    int i;
    u_char* indices = vs_mainMenu_inventoryIndices[itemCategory];
    int capacity = vs_mainMenu_inventoryItemCapacities[itemCategory];

    for (i = 0; i < capacity; ++i) {
        int index = indices[i];
        if ((index != 0) && (_getItemId(itemCategory, index - 1, NULL) == 0)) {
            indices[i] = 0;
        }
    }

    i = 0;

    while (1) {
        if (indices[i] != 0) {
            i += 1;
            if (i == (capacity - 1)) {
                break;
            }
        } else {
            int j;
            int k;

            for (j = i + 1; j < capacity; ++j) {
                if (indices[j] != 0) {
                    break;
                }
            }

            if (j == capacity) {
                break;
            }

            for (k = j; k < capacity; ++k) {
                indices[k + i - j] = indices[k];
            }

            for (k = k + (i - j); k < capacity; ++k) {
                indices[k] = 0;
            }
        }
    }

    for (i = 0; i < capacity; ++i) {
        if ((_getItemId(itemCategory, i, NULL) != 0)
            && (vs_mainMenu_findItem(itemCategory, i) == 0)) {
            _setItemIndex(itemCategory, i);
        }
    }
}

int vs_mainMenu_getItemCount(int itemCategory, vs_main_inventory_t* inventory)
{
    int i;
    int count = 0;

    for (i = 0; i < vs_mainMenu_inventoryItemCapacities[itemCategory]; ++i) {
        if (_getItemId(itemCategory, i, inventory) != 0) {
            ++count;
        }
    }

    return count;
}

int vs_mainMenu_getFirstEmptyItemSlot(int itemCategory, vs_main_inventory_t* inventory)
{
    int i;

    for (i = 0; i < vs_mainMenu_inventoryItemCapacities[itemCategory]; ++i) {
        if (_getItemId(itemCategory, i, inventory) == 0) {
            break;
        }
    }

    return i;
}

int vs_mainMenu_copyItem(int itemCategory, vs_main_inventory_t* targetInventory,
    int sourceItemIndex, vs_main_inventory_t* sourceInventory)
{
    vs_main_inventoryMisc* temp_a0;
    int emptySlot;
    int itemCount;
    int i;
    int gemCount;
    int index;

    int parentIndex = itemCategory >> 8;
    int write = (itemCategory >> 4) & 1;
    itemCategory &= 0xF;
    index = 0;
    itemCount = vs_mainMenu_getItemCount(itemCategory, targetInventory);
    emptySlot = vs_mainMenu_getFirstEmptyItemSlot(itemCategory, targetInventory);

    switch (itemCategory) {
    case itemCategoryWeapon: {
        vs_main_inventoryWeapon* source = &sourceInventory->weapons[sourceItemIndex];
        vs_main_inventoryWeapon* target = &targetInventory->weapons[emptySlot];

        if ((itemCount != 8)
            && (vs_mainMenu_getItemCount(itemCategoryBlade, targetInventory) != 16)) {
            if (vs_mainMenu_getItemCount(itemCategoryGrip, targetInventory) != 16) {

                gemCount = 0;

                for (i = 0; i < 3; ++i) {
                    if (source->gems[i] != 0) {
                        ++gemCount;
                    }
                }

                if ((vs_mainMenu_getItemCount(itemCategoryGem, targetInventory)
                        + gemCount)
                    < 49) {

                    index = emptySlot + 1;

                    if (write != 0) {

                        vs_battle_rMemzero(target, sizeof *target);

                        target->index = index;
                        target->blade = vs_mainMenu_copyItem(
                            (index << 8) | itemCategoryBlade | copyItemFlagsWrite,
                            targetInventory, source->blade - 1, sourceInventory);
                        target->grip = vs_mainMenu_copyItem(
                            (index << 8) | itemCategoryGrip | copyItemFlagsWrite,
                            targetInventory, source->grip - 1, sourceInventory);

                        for (i = 0; i < 3; ++i) {
                            if (source->gems[i] != 0) {
                                target->gems[i] = vs_mainMenu_copyItem(
                                    (index << 8) | 0x15, targetInventory,
                                    source->gems[i] - 1, sourceInventory);
                            }
                        }

                        vs_battle_rMemcpy(target->name, source->name, 0x18);
                    }
                }
            }
        }
        break;
    }

    case itemCategoryBlade: {
        vs_main_inventoryBlade* source = &sourceInventory->blades[sourceItemIndex];
        vs_main_inventoryBlade* target = &targetInventory->blades[emptySlot];

        if (itemCount != 0x10) {

            index = emptySlot + 1;

            if (write != 0) {

                vs_battle_copyAligned(target, source, sizeof *target);

                target->index = index;
                target->assembledWeaponIndex = parentIndex;
            }
        }
        break;
    }

    case itemCategoryGrip: {
        vs_main_inventoryGrip* source = &sourceInventory->grips[sourceItemIndex];
        vs_main_inventoryGrip* target = &targetInventory->grips[emptySlot];

        if (itemCount != 0x10) {
            index = emptySlot + 1;
            if (write != 0) {

                vs_battle_copyAligned(target, source, sizeof *target);

                target->index = index;
                target->assembledWeaponIndex = parentIndex;
            }
        }
        break;
    }

    case itemCategoryShield: {
        vs_main_inventoryShield* target = &sourceInventory->shields[sourceItemIndex];
        vs_main_inventoryShield* source = &targetInventory->shields[emptySlot];

        if (itemCount != 8) {
            gemCount = 0;
            for (i = 0; i < 3; ++i) {
                if (target->gems[i] != 0) {
                    ++gemCount;
                }
            }
            if ((vs_mainMenu_getItemCount(5, targetInventory) + gemCount) < 49) {

                index = emptySlot + 1;

                if (write != 0) {
                    vs_battle_rMemzero(source, 0x30);
                    vs_battle_copyAligned(
                        &source->base, &target->base, sizeof source->base);

                    source->index = index;

                    for (i = 0; i < 3; ++i) {
                        if (target->gems[i] != 0) {
                            source->gems[i] = vs_mainMenu_copyItem(
                                ((index | 0x80) << 8) | itemCategoryGem
                                    | copyItemFlagsWrite,
                                targetInventory, target->gems[i] - 1, sourceInventory);
                        }
                    }
                }
            }
        }
        break;
    }

    case itemCategoryArmor: {
        vs_main_inventoryArmor* source = &sourceInventory->armor[sourceItemIndex];
        vs_main_inventoryArmor* target = &targetInventory->armor[emptySlot];

        if (itemCount != 16) {

            index = emptySlot + 1;

            if (write != 0) {

                vs_battle_copyAligned(target, source, sizeof *target);

                target->index = index;
            }
        }
        break;
    }

    case itemCategoryGem: {
        vs_main_inventoryGem* source = &sourceInventory->gems[sourceItemIndex];
        vs_main_inventoryGem* target = &targetInventory->gems[emptySlot];

        if (itemCount != 0x30) {
            index = emptySlot + 1;
            if (write != 0) {

                vs_battle_copyAligned(target, source, sizeof *target);

                target->index = index;
                target->setItemIndex = parentIndex;
            }
        }
        break;
    }

    case itemCategoryMisc: {
        vs_main_inventoryMisc* source = &sourceInventory->misc[sourceItemIndex];
        vs_main_inventoryMisc* target = targetInventory->misc;
        int count = source->count;

        vs_mainMenu_rebuildInventory(6);

        for (i = 0; i < 0x40; ++i) {
            int slot = vs_main_inventoryIndices.misc[i];

            if (slot == 0) {
                continue;
            }

            temp_a0 = &target[slot - 1];

            if (temp_a0->id != source->id)
                continue;

            if (write != 0) {
                int space_left = 100 - temp_a0->count;

                if (space_left >= count) {
                    temp_a0->count += count;
                    count = 0;
                } else {
                    count = count + (temp_a0->count - 100);
                    temp_a0->count = 100;
                }
            } else {
                count = count - (100 - temp_a0->count);

                if (count < 0) {
                    count = 0;
                }
            }
        }

        if (count == 0) {
            index = 1;
            break;
        }

        if (itemCount != 0x40) {

            index = emptySlot + 1;

            if (write != 0) {
                target[emptySlot].id = source->id;
                target[emptySlot].count = count;
            }
        }
        break;
    }
    }

    return index;
}

u_char vs_mainMenu_miscItemToSkillMap[] = { 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6,
    0xE7, 0xF3, 0xF4, 0xF5, 0xF6, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEF, 0xEE, 0xF0,
    0xF2, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xF1, 0x00,
    0xFE, 0xFD, 0xFB, 0xF4, 0xFE, 0xFB, 0xF6, 0xF3, 0xF3, 0xFC, 0xFD, 0xFF, 0xFB, 0xF5,
    0xFE, 0xFD, 0xFF, 0xFD, 0xFD, 0xFF, 0xFD, 0xFE, 0xFE, 0xFF, 0xFE, 0xFC, 0xFF, 0xFD,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x00, 0x00, 0x00, 0x6E,
    0x00, 0x00, 0x00, 0x72, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x7A, 0x00, 0x00,
    0x00, 0x7E, 0x00, 0x00, 0x00, 0x82, 0x00, 0x00, 0x00, 0x5E, 0x5F, 0x60, 0x57, 0x58,
    0x5A, 0x5B, 0x4D, 0x3C, 0x36, 0x3D, 0x37, 0x3E, 0x38, 0x3F, 0x39, 0x4B, 0x4C, 0x52,
    0x53, 0x55, 0x4F, 0x50, 0x5C, 0x5D, 0x3A, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
    0x49 };

char (*vs_mainMenu_itemNames)[24] = NULL;

u_char vs_mainMenu_inventoryItemCapacities[] = { 8, 16, 16, 8, 16, 48, 64, 2 };

u_char* vs_mainMenu_inventoryIndices[] = { vs_main_inventoryIndices.weapons,
    vs_main_inventoryIndices.blades, vs_main_inventoryIndices.grips,
    vs_main_inventoryIndices.shields, vs_main_inventoryIndices.armor,
    vs_main_inventoryIndices.gems, vs_main_inventoryIndices.misc };
