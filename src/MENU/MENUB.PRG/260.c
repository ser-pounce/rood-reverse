#include "common.h"
#include "../MAINMENU.PRG/278.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/2D10.h"
#include "../MAINMENU.PRG/58EC.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/4A0A8.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../assets/MENU/MENUB.PRG/menuText.h"
#include "../../assets/MENU/ITEMHELP.BIN.h"
#include "vs_string.h"
#include "gpu.h"
#include <libetc.h>
#include <stddef.h>
#include <memory.h>
#include <limits.h>

typedef struct {
    char unk0;
    u_char unk1;
    char unk2;
    char unk3;
} D_8010A6A0_t;

extern u_long* D_1F800000[];

static int _handleItemPaging(int items, int page)
{
    if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {
        int previousPage = page;
        items = vs_mainMenu_getItemCount(items, NULL);
        if (vs_main_buttonRepeat & PADL1) {
            page += items - 1;
        }
        if (vs_main_buttonRepeat & PADR1) {
            ++page;
        }
        if (page >= items) {
            page -= items;
        }
        if ((vs_main_buttonsPressed.all & (PADL1 | PADR1)) && (page == previousPage)) {
            vs_battle_playInvalidSfx();
        }
    }
    return page;
}

static void func_80102B14(int arg0, int arg1)
{
    int i;

    int temp_s4 = (D_800F4EE8.unk3A.itemCategory - 1) & 7;

    if (arg0 == 4) {
        func_801013F8(0);
    }

    arg0 = (arg0 * 8) - 16;

    for (i = 0; i < 8; ++i) {
        u_long* var_v1;
        int temp_s0 = (((i + 1) & 7) * 16) + 32;
        if (i == temp_s4 && arg1 == 1) {
            vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(31);
            if (temp_s0 >= (menuItem->initialX - 12)) {
                menuItem->icon = i + 24;
                continue;
            } else {
                var_v1 = func_800C0214(0x100010, temp_s0 | 0x100000);
            }
        } else {
            var_v1 =
                func_800C0224(0x80, temp_s0 | (arg0 << 0x10), 0x100010, D_1F800000[1]);
        }
        var_v1[4] = (0x78 + i * 0x10) | 0x8000 | (i == temp_s4 ? 0x37FD0000 : 0x37FE0000);
    }
}

static void _initMenuItem(int menuItemId)
{
    vs_battle_menuItem_t* menuItem;

    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    menuItem = vs_battle_getMenuItem(31);
    menuItem->state = 3;
    menuItem->targetX = 18;
    menuItem = vs_battle_getMenuItem(menuItemId);
    menuItem->state = 2;
    menuItem->targetX = 155;
    menuItem->selected = 1;
    menuItem->unk3C = NULL;
}

static void _transitionToSubMenu(int id)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_getMenuItem(31);
    menuItem->state = 2;
    menuItem->targetX = 16;
    menuItem->w = 164;
    menuItem = vs_battle_getMenuItem(id);
    menuItem->state = 3;
    menuItem->targetX = 18;
}

static u_short _menuText[] = {
#include "../../assets/MENU/MENUB.PRG/menuText.vsString"
};

static char D_8010A504 = 0;
static char D_8010A505 = 0;
static int D_8010A508 = 0;
static int D_8010A50C = 0;

static D_8010A6A0_t* D_8010A6A0;
static D_8010A6A0_t* D_8010A6A4;
static vs_battle_inventory_t* _inventory;
static vs_battle_inventory_t* D_8010A6AC;
static char D_8010A6B0;
static u_char D_8010A6B1;
static char D_8010A6B2;
static u_char D_8010A6B3;
static char D_8010A6B4;
static u_char D_8010A6B5;
static u_char D_8010A6B6;
static char D_8010A6B7;
static char D_8010A6B8;
static char D_8010A6B9;
static char D_8010A6BA;
static char D_8010A6BB;

static void _initMenuLayout(int menuItemId, int layout)
{
    D_8010A50C = 1;
    D_8010A6BA = 0;
    D_8010A6BB = 0;
    _transitionToSubMenu(menuItemId);
    vs_mainMenu_drawClassAffinityType(layout);
    vs_mainMenu_renderEquipStats(1);
}

static void _setSubMenu(int id, char** menuText, u_int rowType, int arg3)
{
    vs_battle_menuItem_t* temp_v0;

    vs_battle_playMenuChangeSfx();
    temp_v0 = vs_battle_setMenuItem(id, 155, 18, 0xA5, 0, menuText[0]);
    temp_v0->selected = 1;
    temp_v0->icon = rowType >> 0x1A;
    temp_v0->material = (rowType >> 0x10) & 7;
    vs_mainmenu_setInformationMessage(menuText[1]);
    vs_battle_getMenuItem(31)->unkE = arg3 + 1;
}

static int _getItemIndex(int itemCategory, int index)
{
    D_800F4EE8.unk0[(itemCategory + 30) * 2] = 0;
    D_800F4EE8.unk0[(itemCategory + 30) * 2 + 1] = index;
    return vs_mainMenu_inventoryIndices[itemCategory][index];
}

static char D_8010A6BC;
static char D_8010A6BD;
static char D_8010A6BE;
static char D_8010A6BF;
static int _exitToBattle;

static void _initMenuLeave(int withDpPpbars)
{
    vs_battle_playMenuLeaveSfx();
    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    vs_mainMenu_menuItemLeaveLeft(-1);
    vs_mainMenu_drawClassAffinityType(-1);
    vs_mainMenu_renderEquipStats(2);
    D_8010A6BF = 2;
    _exitToBattle = vs_main_buttonsPressed.all & PADRup;
    if (withDpPpbars != 0) {
        vs_mainMenu_drawDpPpbars(4);
    }
}

static int _weaponDetailsPage(int selectedMenuItem)
{
    enum state { init, initRows, render, leave };
    static char state;
    static char row;
    static char menuItemId;
    static u_char selectedWeapon;
    static char _ __attribute__((unused));

    if (selectedMenuItem != 0) {
        menuItemId = selectedMenuItem >> 8;
        selectedWeapon = selectedMenuItem - 1;
        _initMenuItem(menuItemId);
        _ = 0;
        row = 0;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(menuItemId, 7);
            vs_mainMenu_setUiWeaponStats(
                vs_main_inventoryIndices.weapons[selectedWeapon]);
            vs_mainMenu_drawDpPpbars(3);
            state = initRows;
        }
        break;
    case initRows:
        if (row < 10) {
            ++row;
            if (row < 6) {
                vs_mainMenu_initSetWeaponGemMenu(
                    row, vs_main_inventoryIndices.weapons[selectedWeapon], 1);
            }
            break;
        }
        state = render;
        break;
    case render:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _initMenuLeave(1);
            state = leave;
        } else {
            int weaponPage = _handleItemPaging(0, selectedWeapon);
            if (weaponPage != selectedWeapon) {
                char* text[2];
                int rowType;
                int i;
                selectedWeapon = weaponPage;
                i = _getItemIndex(0, weaponPage);
                vs_mainMenu_initUiWeapon(&vs_battle_inventory.weapons[i - 1], text,
                    &rowType, vs_battle_stringBuf);
                vs_mainMenu_setUiWeaponStats(i);

                _setSubMenu(menuItemId, text, rowType, weaponPage);
                for (i = 1; i < 6; ++i) {
                    vs_mainMenu_initSetWeaponGemMenu(
                        i, vs_main_inventoryIndices.weapons[weaponPage], 0);
                }
            }
        }
        break;
    case leave:
        return vs_mainmenu_ready();
    }
    return 0;
}

static int _bladeDetailsPage(int selectedMenuItem)
{
    enum state { init, animationWait, render, leave };

    static char state;
    static char animationTimer;
    static char menuItemId;
    static u_char selectedBlade;

    if (selectedMenuItem != 0) {
        menuItemId = selectedMenuItem >> 8;
        selectedBlade = selectedMenuItem - 1;
        _initMenuItem(menuItemId);
        animationTimer = 10;
        state = init;
        return 0;
    }

    switch (state)
    case init: {
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(menuItemId, 3);
            vs_mainMenu_setUiBladeStats(vs_main_inventoryIndices.blades[selectedBlade]);
            vs_mainMenu_drawDpPpbars(3);
            state = animationWait;
        }
        break;
    case animationWait:
        if (animationTimer != 0) {
            --animationTimer;
        } else {
            state = render;
        }
        break;
    case render:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _initMenuLeave(1);
            state = leave;
        } else {
            int selectedBladePage = _handleItemPaging(1, selectedBlade);
            if (selectedBladePage != selectedBlade) {
                char* text[2];
                int rowType;
                int bladeIndex;
                selectedBlade = selectedBladePage;
                bladeIndex = _getItemIndex(1, selectedBladePage);
                vs_mainMenu_setBladeUi(&vs_battle_inventory.blades[bladeIndex - 1], text,
                    &rowType, vs_battle_stringBuf);
                vs_mainMenu_setUiBladeStats(bladeIndex);
                _setSubMenu(menuItemId, text, rowType, selectedBladePage);
            }
        }
        break;
    case leave:
        return vs_mainmenu_ready();
    }

        return 0;
}

static int _gripDetailsPage(int selectedMenuItem)
{
    enum state { init, animationWait, render, leave };

    static char* gemCountText = "X     0";
    static char state;
    static char animationTimer;
    static char menuItemId;
    static char selectedGrip;
    static char _ __attribute__((unused));

    if (selectedMenuItem != 0) {
        menuItemId = selectedMenuItem >> 8;
        selectedGrip = selectedMenuItem - 1;
        _initMenuItem(menuItemId);
        _ = 0;
        animationTimer = 0;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(menuItemId, 4);
            vs_mainMenu_setUiGripStats(vs_main_inventoryIndices.grips[selectedGrip]);
            state = animationWait;
        }
        break;
    case animationWait:
        if (animationTimer < 10) {
            ++animationTimer;
        } else {
            state = render;
        }
        break;
    case render:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _initMenuLeave(0);
            state = leave;
        } else {
            int selectedGripPage = _handleItemPaging(2, selectedGrip);
            if (selectedGripPage != selectedGrip) {
                char* menuText[2];
                int rowType;
                int gripIndex;
                selectedGrip = selectedGripPage;
                gripIndex = _getItemIndex(2, selectedGripPage);
                vs_mainMenu_setGripUi(&vs_battle_inventory.grips[gripIndex - 1], menuText,
                    &rowType, vs_battle_stringBuf);
                vs_mainMenu_setUiGripStats(gripIndex);
                _setSubMenu(menuItemId, menuText, rowType, selectedGripPage);
            }
        }
        gemCountText[6] =
            (vs_battle_inventory.grips[vs_main_inventoryIndices.grips[selectedGrip] - 1]
                    .gemSlots
                + '0'); // BUG: Write to const char
        vs_mainMenu_drawRowIcon(0x116, 0x100, 0x20);
        vs_battle_renderTextRaw(gemCountText, vs_getXY(280, 36), NULL);
        break;
    case leave:
        return vs_mainmenu_ready();
    }
    return 0;
}

static int _shieldDetailsPage(int selectedMenuItem)
{
    enum state { init, animationWait, render, leave };

    static char state;
    static char animationTimer;
    static char menuItemId;
    static u_char selectedShield;
    static char _ __attribute__((unused));

    if (selectedMenuItem != 0) {
        menuItemId = selectedMenuItem >> 8;
        selectedShield = selectedMenuItem - 1;
        _initMenuItem(menuItemId);
        _ = 0;
        animationTimer = 0;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(menuItemId, 7);
            vs_mainMenu_setShieldStats(vs_main_inventoryIndices.shields[selectedShield]);
            vs_mainMenu_drawDpPpbars(3);
            state = animationWait;
        }
        break;
    case animationWait:
        if (animationTimer < 10) {
            ++animationTimer;
            if (animationTimer < 4) {
                vs_mainMenu_initSetShieldGemMenu(
                    animationTimer, vs_main_inventoryIndices.shields[selectedShield], 1);
            }
            break;
        }
        if (vs_mainmenu_ready() != 0) {
            state = render;
        }
        break;
    case render:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _initMenuLeave(1);
            state = leave;
        } else {
            int selectedShieldPage = _handleItemPaging(3, selectedShield);
            if (selectedShieldPage != selectedShield) {
                char* text[2];
                int rowType;
                int i;
                selectedShield = selectedShieldPage;
                i = _getItemIndex(3, selectedShieldPage);
                vs_mainMenu_initUiShield(&vs_battle_inventory.shields[i - 1], text,
                    &rowType, vs_battle_stringBuf);
                vs_mainMenu_setShieldStats(i);
                _setSubMenu(menuItemId, text, rowType, selectedShieldPage);

                for (i = 1; i < 4; ++i) {
                    vs_mainMenu_initSetShieldGemMenu(
                        i, vs_main_inventoryIndices.shields[selectedShieldPage], 0);
                }
            }
        }
        break;
    case leave:
        return vs_mainmenu_ready();
    }
    return 0;
}

static int _armorDetailsPage(int selectedMenuItem)
{
    enum state { init, animationWait, render, leave };

    static char state;
    static char animationTimer;
    static char menuItemId;
    static char selectedArmor;

    if (selectedMenuItem != 0) {
        menuItemId = selectedMenuItem >> 8;
        selectedArmor = selectedMenuItem - 1;
        _initMenuItem(menuItemId);
        animationTimer = 10;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(menuItemId, 7);
            vs_mainMenu_setArmorStats(vs_main_inventoryIndices.armor[selectedArmor]);
            if (vs_battle_inventory
                    .armor[vs_main_inventoryIndices.armor[selectedArmor] - 1]
                    .category
                != 7) {
                vs_mainMenu_drawDpPpbars(1);
            }
            state = animationWait;
        }
        break;
    case animationWait:
        if (animationTimer != 0) {
            --animationTimer;
        } else {
            state = render;
        }
        break;
    case render:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _initMenuLeave(1);
            state = leave;
        } else {
            int selectedArmorPage = _handleItemPaging(4, selectedArmor);
            if (selectedArmorPage != selectedArmor) {
                char* text[2];
                int rowType;
                int armorIndex;
                selectedArmor = selectedArmorPage;
                armorIndex = _getItemIndex(4, selectedArmorPage);
                vs_mainMenu_setAccessoryUi(&vs_battle_inventory.armor[armorIndex - 1],
                    text, &rowType, vs_battle_stringBuf);
                vs_mainMenu_setArmorStats(armorIndex);
                _setSubMenu(menuItemId, text, rowType, selectedArmorPage);
            }
        }
        break;
    case leave:
        return vs_mainmenu_ready();
    }
    return 0;
}

static int _gemDetailsPage(int selectedMenuItem)
{
    enum state { init, animationWait, render, leave };

    static char state;
    static char animationTimer;
    static char menuItemId;
    static char selectedGem;

    if (selectedMenuItem != 0) {
        menuItemId = selectedMenuItem >> 8;
        selectedGem = selectedMenuItem - 1;
        _initMenuItem(menuItemId);
        animationTimer = 10;
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            _initMenuLayout(menuItemId, 3);
            vs_mainMenu_setGemStats(vs_main_inventoryIndices.gems[selectedGem]);
            state = animationWait;
        }
        break;
    case animationWait:
        if (animationTimer != 0) {
            --animationTimer;
        } else {
            state = render;
        }
        break;
    case render:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            _initMenuLeave(0);
            state = leave;
            _exitToBattle = vs_main_buttonsPressed.all & PADRup;
        } else {
            int selectedGemPage = _handleItemPaging(5, selectedGem);
            if (selectedGemPage != selectedGem) {
                char* text[2];
                int rowType;
                int gemIndex;
                selectedGem = selectedGemPage;
                gemIndex = _getItemIndex(5, selectedGemPage);
                vs_mainMenu_setGemUi(&vs_battle_inventory.gems[gemIndex - 1], text,
                    &rowType, vs_battle_stringBuf);
                vs_mainMenu_setGemStats(gemIndex);
                _setSubMenu(menuItemId, text, rowType, selectedGemPage);
            }
        }
        break;
    case leave:
        return vs_mainmenu_ready();
    }
    return 0;
}

static int _invokeDetailsPageHandler(int arg0)
{
    static int (*detailsPageHandlers[])(int) = { _weaponDetailsPage, _bladeDetailsPage,
        _gripDetailsPage, _shieldDetailsPage, _armorDetailsPage, _gemDetailsPage };

    static u_char currentDetailsPageCategory;

    int handlerResult;
    int selectedMenuItem = 0;

    if (arg0 != 0) {
        selectedMenuItem = arg0 >> 4;
        currentDetailsPageCategory = arg0 & 0xF;
        D_8010A6BF = 1;
        _exitToBattle = 0;
        func_800FDD78();
        vs_battle_getMenuItem(31)->unkE = selectedMenuItem & 0xFF;
        func_800FFA88(0);
    }

    handlerResult = detailsPageHandlers[currentDetailsPageCategory](selectedMenuItem);

    if (handlerResult != 0) {
        if (_exitToBattle != 0) {
            return -2;
        }
        D_8010A6BA = 1;
        D_8010A6BF = 0;
        D_8010A6BB = 1;
        D_8010A50C = 0;
        func_800FFA88(2);
    } else if (vs_mainmenu_ready() != 0) {
        D_801022D5 = D_801024B8 != 9;
        func_801013F8(1);
        func_800FDEBC();
    }
    return handlerResult;
}

static int _getWeaponStat(int stat, vs_battle_uiWeapon* weapon)
{
    switch (stat) {
    case 0:
        return -weapon->blade.category;
    case 1:
        return -weapon->blade.material;
    case 2:
        return weapon->range.unk0;
    case 3:
        return -weapon->damageType;
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
        if (stat >= 17) {
            return weapon->classAffinityCurrent.affinity[0][stat - 17];
        }
        return weapon->classAffinityCurrent.class[0][stat - 11];
    }
}

static void _sortWeaponsByStat(int stat)
{
    vs_battle_uiWeapon weapon;
    char sortedIndices[8];
    int sortedIndex;
    vs_battle_inventoryWeapon* weapons = vs_battle_inventory.weapons;
    char* indices = vs_main_inventoryIndices.weapons;

    vs_battle_rMemzero(sortedIndices, sizeof sortedIndices);
    sortedIndex = 0;

    while (1) {
        int i;
        int index;
        int maxValue = -INT_MAX - 1;

        for (i = 0; i < 8; ++i) {
            index = indices[i];
            if (index != 0) {
                int value;
                vs_battle_applyWeapon(&weapon, &weapons[index - 1]);
                value = _getWeaponStat(stat, &weapon);
                if (maxValue < value) {
                    maxValue = value;
                }
            }
        }

        if (maxValue == -INT_MAX - 1) {
            break;
        }

        for (i = 0; i < 8; ++i) {
            index = indices[i];
            if (index != 0) {
                vs_battle_applyWeapon(&weapon, &weapons[index - 1]);
                if (_getWeaponStat(stat, &weapon) == maxValue) {
                    sortedIndices[sortedIndex++] = index;
                    indices[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(indices, sortedIndices, sizeof sortedIndices);
}

static int _getShieldStat(int stat, vs_battle_uiShield* shield)
{
    switch (stat) {
    case 1:
        return -shield->base.material;
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
        if (stat < 33) {
            return shield->classAffinityCurrent.class[0][stat - 27];
        }
        if (stat >= 40) {
            return shield->types[stat - 39];
        }
        return shield->classAffinityCurrent.affinity[0][stat - 33];
    }
}

static void _sortShieldsByStat(int stat)
{
    vs_battle_uiShield shield;
    char sortedIndices[8];
    int sortedIndex;
    vs_battle_inventoryShield* shields = &vs_battle_inventory.shields[0];
    char* shieldIndices = vs_main_inventoryIndices.shields;

    vs_battle_rMemzero(sortedIndices, sizeof sortedIndices);
    sortedIndex = 0;

    while (1) {
        int i;
        int index;
        int maxValue = -INT_MAX - 1;

        for (i = 0; i < 8; ++i) {
            index = shieldIndices[i];
            if (index != 0) {
                int value;
                vs_battle_applyShield(&shield, &shields[index - 1]);
                value = _getShieldStat(stat, &shield);
                if (maxValue < value) {
                    maxValue = value;
                }
            }
        }

        if (maxValue == -INT_MAX - 1) {
            break;
        }

        for (i = 0; i < 8; ++i) {
            index = shieldIndices[i];
            if (index != 0) {
                vs_battle_applyShield(&shield, &shields[index - 1]);
                if (_getShieldStat(stat, &shield) == maxValue) {
                    sortedIndices[sortedIndex++] = index;
                    shieldIndices[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(shieldIndices, sortedIndices, 8);
}

static int _getMiscStat(int arg0, vs_battle_inventoryMisc* arg1)
{
    if (arg0 == 0) {
        return -arg1->id;
    }
    return arg1->count;
}

static void _sortMiscByStat(int stat)
{
    char sortedIndices[64];
    int sortedIndex;
    vs_battle_inventoryMisc* item = vs_battle_inventory.misc;
    char* indices = vs_main_inventoryIndices.misc;

    vs_battle_rMemzero(sortedIndices, sizeof sortedIndices);
    sortedIndex = 0;

    while (1) {
        int i;
        int index;
        int maxValue = -INT_MAX - 1;

        for (i = 0; i < 64; ++i) {
            index = indices[i];
            if (index != 0) {
                int value = _getMiscStat(stat, &item[index - 1]);
                if (maxValue < value) {
                    maxValue = value;
                }
            }
        }

        if (maxValue == -INT_MAX - 1) {
            break;
        }

        for (i = 0; i < 64; ++i) {
            index = indices[i];
            if (index != 0) {
                if (_getMiscStat(stat, &item[index - 1]) == maxValue) {
                    sortedIndices[sortedIndex++] = index;
                    indices[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(indices, &sortedIndices, sizeof sortedIndices);
}

static int _getEquipmentStat(int stat, vs_battle_uiEquipment* item)
{
    switch (stat) {
    case 0:
        return -item->category;
    case 1:
        return -item->material;
    case 2:
        return item->range.unk0;
    case 3:
        return -item->damageType;
    case 4:
        return item->currentDp;
    case 5:
        return item->maxDp;
    case 6:
        return item->currentPp;
    case 7:
        return item->maxPp;
    case 8:
        return item->strength;
    case 9:
        return item->intelligence;
    case 10:
        return item->agility;
    default:
        if (stat >= 27) {
            stat -= 16;
        }
        if (stat < 17) {
            return item->classes[stat - 11];
        }
        if (stat >= 24) {
            return item->types[stat - 23];
        }
        return item->affinities[stat - 17];
    }
}

void _copyEquipmentStats(vs_battle_uiEquipment* equipment, int itemCategory, int index)
{
    switch (itemCategory) {
    case itemCategoryBlade:
        vs_battle_copyInventoryBladeStats(equipment, &vs_battle_inventory.blades[index]);
        return;
    case itemCategoryGrip:
        vs_battle_copyInventoryGripStats(equipment, &vs_battle_inventory.grips[index]);
        return;
    case itemCategoryArmor:
        vs_battle_copyInventoryArmorStats(equipment, &vs_battle_inventory.armor[index]);
        return;
    case itemCategoryGem:
        vs_battle_copyInventoryGemStats(equipment, &vs_battle_inventory.gems[index]);
        return;
    }
}

static void _sortEquipmentByStat(int itemCategory, int stat)
{
    vs_battle_uiEquipment equipment;

    int sortedIndex = 0;
    int capacity = vs_mainMenu_inventoryItemCapacities[itemCategory];
    {
        char sortedIndices[capacity];
        char* indices = vs_mainMenu_inventoryIndices[itemCategory];
        vs_battle_rMemzero(sortedIndices, capacity);

        while (1) {
            int i;
            int index;
            int maxValue = -INT_MAX - 1;
            for (i = 0; i < capacity; ++i) {
                index = indices[i];
                if (index != 0) {
                    int value;
                    _copyEquipmentStats(&equipment, itemCategory, index - 1);
                    value = _getEquipmentStat(stat, &equipment);
                    if (maxValue < value) {
                        maxValue = value;
                    }
                }
            }

            if (maxValue == -INT_MAX - 1) {
                break;
            }

            for (i = 0; i < capacity; ++i) {
                index = indices[i];
                if (index != 0) {
                    _copyEquipmentStats(&equipment, itemCategory, index - 1);
                    if (_getEquipmentStat(stat, &equipment) == maxValue) {
                        sortedIndices[sortedIndex++] = index;
                        indices[i] = 0;
                    }
                }
            }
        }
        vs_battle_memcpy(indices, sortedIndices, capacity);
    }
}

static int _sortItems(int selectedCategory)
{
    static char bladeSortStats[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20, 21, 22, 23 };
    static char gripSortStats[] = { 0, 8, 9, 10, 24, 25, 26 };
    static char shieldSortStats[] = { 1, 4, 5, 6, 7, 8, 9, 10, 40, 41, 42, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39 };
    static char armorSortStats[] = { 0, 1, 4, 5, 8, 9, 10, 40, 41, 42, 27, 28, 29, 30, 31,
        32, 33, 34, 35, 36, 37, 38, 39 };
    static char gemSortStats[] = { 8, 9, 10, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
        38, 39 };
    static char miscSortStats[] = { 0, 56 };
    static char sortStatsCounts[] = { sizeof bladeSortStats, sizeof bladeSortStats,
        sizeof gripSortStats, sizeof shieldSortStats, sizeof armorSortStats,
        sizeof gemSortStats, sizeof miscSortStats };
    static char* equipmentSortStats[] = { bladeSortStats, bladeSortStats, gripSortStats,
        shieldSortStats, armorSortStats, gemSortStats, miscSortStats };

    static char state;
    static u_char itemCategory;

    char* statTextBuf[48];
    int statRowTypes[24];
    int i;

    if (selectedCategory != 0) {
        itemCategory = selectedCategory - 1;
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            char* stats = equipmentSortStats[itemCategory];
            for (i = 0; i < sortStatsCounts[itemCategory]; ++i) {
                statTextBuf[i * 2] = (char*)&vs_mainMenu_itemHelp
                    [vs_mainMenu_itemHelp[stats[i] * 2 + VS_ITEMHELP_BIN_INDEX_sortMenu]];
                statTextBuf[i * 2 + 1] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                        [stats[i] * 2 + VS_ITEMHELP_BIN_INDEX_sortMenuDesc]];
                statRowTypes[i] = 0;
            }
            vs_mainMenu_initSortUi(i, itemCategory + 45, statTextBuf, statRowTypes);
            state = 1;
        }
        break;
    case 1:
        vs_mainMenu_processItemActionMenu();
        i = vs_mainMenu_getSelectedItemAction();
        if ((i + 1) != 0) {
            if (i >= 0) {
                vs_battle_playMenuSelectSfx();
                switch (itemCategory) {
                case itemCategoryWeapon:
                    _sortWeaponsByStat(bladeSortStats[i]);
                    break;
                case itemCategoryShield:
                    _sortShieldsByStat(shieldSortStats[i]);
                    break;
                case itemCategoryMisc:
                    _sortMiscByStat(miscSortStats[i]);
                    break;
                default:
                    _sortEquipmentByStat(
                        itemCategory, equipmentSortStats[itemCategory][i]);
                    break;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i + 1;
        }
    }
    return 0;
}

static int _discardMenu(int arg0)
{
    enum state {
        init,
        discardOneInit,
        discardMultipleInit,
        discardOne,
        clearTemplate,
        determineDiscardAmount,
        discardMultipleConfirm,
        discardMultiple
    };

#pragma vsstring(start)
    static char countTemplate[] = "|>48|000/000\0";
#pragma vsstring(end)
    static char discardSteps[] = { 1, 10, 100 };
    static char D_8010A5C3 = 0;

    static char state;
    static char itemCategory;
    static char selectedItem;
    static char discardType;
    static u_char discardStep;
    static char discardCount;
    static char maxAmount;
    static char _[3] __attribute__((unused));

    char* discardOneText[4];
    int discardOneRowTypes[2];
    char* discardMultipleText[4];
    int discardMultipleRowTypes[2];
    int i;
    vs_battle_menuItem_t* menuItem;
    int a0;
    int a2;

    if (arg0 != 0) {
        discardType = (arg0 >> 0x10);
        itemCategory = (arg0 >> 8);
        selectedItem = arg0;
        func_800C8E04(1);
        vs_mainmenu_setInformationMessage(
            (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                    [discardType + VS_ITEMHELP_BIN_INDEX_discardConfirm]]);
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if ((D_800F5130 >> 0x1E) & 1) {
            if (vs_mainmenu_ready() != 0) {
                state = ((discardType & 1) + 1);
            }
        }
        break;
    case discardOneInit:
        for (i = 0; i < 2; ++i) {
            discardOneText[i * 2] = (char*)&vs_mainMenu_itemHelp
                [vs_mainMenu_itemHelp[i + VS_ITEMHELP_BIN_INDEX_confirmYes]];
            discardOneText[i * 2 + 1] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                    [discardType + VS_ITEMHELP_BIN_INDEX_discardConfirm]];
            discardOneRowTypes[i] = 0;
        }

        vs_mainMenu_initSortUi(2, 4, discardOneText, discardOneRowTypes);
        state = discardOne;
        break;
    case discardMultipleInit:
        maxAmount = vs_battle_inventory.misc[selectedItem - 1].count;
        i = vs_battle_toBCD(maxAmount);
        countTemplate[8] = i & 0xF;
        i = vs_battle_toBCD(i >> 4);

        countTemplate[7] = i & 0xF;
        countTemplate[6] = i >> 4;
        for (i = 2; i < 5; ++i) {
            countTemplate[i] = 0;
        }
        menuItem = vs_battle_setMenuItem(34, -126, 130, 0x7E, 0, countTemplate);
        menuItem->state = 5;
        menuItem->targetX = 0;
        discardStep = 0;
        discardCount = 0;
        state = clearTemplate;
        break;
    case discardOne:
        vs_mainMenu_processItemActionMenu();
        i = vs_mainMenu_getSelectedItemAction() + 1;
        if (i != 0) {
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0x1C);
                vs_mainMenu_initItem(itemCategory, selectedItem);
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i;
        }
        break;
    case clearTemplate:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        for (i = 2; i < 5; ++i) {
#pragma vsstring(start)
            countTemplate[i] = ' ';
#pragma vsstring(end)
        }

        vs_battle_setMenuItem(34, 0, 130, 0x7E, 0, countTemplate);
        state = determineDiscardAmount;
        // Fallthrough
    case determineDiscardAmount:
        if (vs_main_buttonsPressed.all & (PADRup | PADRright | PADRdown)) {
            i = vs_battle_toBCD(discardCount);
            countTemplate[4] = (i & 0xF);
            i = vs_battle_toBCD(i >> 4);
            countTemplate[3] = (i & 0xF);
            countTemplate[2] = (i >> 4);
            vs_battle_setMenuItem(34, 0, 130, 0x7E, 0, countTemplate);
            if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
                vs_battle_playMenuLeaveSfx();
                if ((vs_main_buttonsPressed.all & PADRup)) {
                    return -2;
                }
                return -1;
            }
            if (discardCount == 0) {
                vs_battle_playMenuLeaveSfx();
                return -1;
            }
            vs_battle_playMenuSelectSfx();
            state = discardMultipleConfirm;
            break;
        }

        i = 0;
        a0 = a2 = discardCount;
        if (vs_main_buttonRepeat & PADLup) {
            i = 1;
        }
        if (vs_main_buttonRepeat & PADLdown) {
            --i;
        }
        if (i == 1) {
            a0 = a2 + discardSteps[discardStep];
        } else if (i == -1) {
            a0 = a2 - discardSteps[discardStep];
        }
        if (a0 >= 0) {
            if (maxAmount >= a0) {
                discardCount = a0;
            }
        }
        i = 0;
        a0 = discardStep;
        if (vs_main_buttonRepeat & PADLright) {
            i = -1;
        }
        if (vs_main_buttonRepeat & PADLleft) {
            i += 1;
        }
        if (i == 1) {
            if ((a0 & 0xFF) == 2) {
                if (discardCount != maxAmount) {
                    discardCount = maxAmount;
                }
            } else {
                ++discardStep;
            }
        } else if (i == -1) {
            if (!(a0 & 0xFF)) {
                if (discardCount != 0) {
                    discardCount = 0;
                }
            } else {
                --discardStep;
            }
        }
        if ((a0 != discardStep) || (a2 != discardCount)) {
            vs_battle_playMenuChangeSfx();
        }
        func_800C7210(5);
        i = vs_battle_toBCD(discardCount);
        func_800C70F8(i & 0xF, 0x42, 0x82, D_1F800000[2] - 3);
        i = vs_battle_toBCD(i >> 4);
        func_800C70F8(i & 0xF, 0x3C, 0x82, D_1F800000[2] - 3);
        func_800C70F8(i >> 4, 0x36, 0x82, D_1F800000[2] - 3);
        D_8010A5C3 = func_800FFCDC(D_8010A5C3, (54 - (discardStep * 6)) | (114 << 0x10));
        break;
    case discardMultipleConfirm:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                discardMultipleText[i * 2] =
                    (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[i + 0x228]];
                discardMultipleText[i * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x2E49];
                discardMultipleRowTypes[i] = 0;
            }

            vs_mainMenu_initSortUi(2, 4, discardMultipleText, discardMultipleRowTypes);
            state = discardMultiple;
        }
        break;
    case discardMultiple:
        vs_mainMenu_processItemActionMenu();
        i = vs_mainMenu_getSelectedItemAction() + 1;
        if (i != 0) {
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0x1C);
                if (vs_battle_inventory.misc[selectedItem - 1].count == discardCount) {
                    vs_mainMenu_initItem(itemCategory, selectedItem);
                } else {
                    vs_battle_inventory.misc[selectedItem - 1].count =
                        vs_battle_inventory.misc[selectedItem - 1].count - discardCount;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i;
        }
        break;
    }
    return 0;
}

static void func_80104F98(int arg0)
{
    D_8010A6B9 = arg0;
    D_8010A6BA = arg0;
    D_8010A6BB = arg0;
}

static int _getParentItem(int itemCategory, int index)
{
    int parentIndex = 0;

    if (itemCategory == itemCategoryBlade) {
        parentIndex = vs_battle_inventory.blades[index].assembledWeaponIndex;
    }
    if (itemCategory == itemCategoryGrip) {
        parentIndex = vs_battle_inventory.grips[index].assembledWeaponIndex;
    }
    if (itemCategory == itemCategoryGem) {
        parentIndex = vs_battle_inventory.gems[index].setItemIndex;
        if (parentIndex & 0x80) {
            parentIndex = 0;
        }
    }
    return parentIndex;
}

static int _getParentItemIfGem(int itemCategory, int index)
{
    int parentIndex = 0;
    if (itemCategory == itemCategoryGem) {
        parentIndex = vs_battle_inventory.gems[index].setItemIndex;
        if (!(parentIndex & 0x80)) {
            parentIndex = 0;
        }
    }
    return parentIndex & 0x7F;
}

int func_80105088(u_int arg0, char** arg1, int* arg2, char* arg3)
{
    int temp_v0;
    int var_s3;
    int i;
    char* sp10 = vs_mainMenu_inventoryIndices[arg0];
    int sp14 = 0;

    for (i = 0; i < vs_mainMenu_inventoryItemCapacities[arg0]; ++i, arg3 += 0x60) {

        int temp_s1_2 = sp10[i];

        if (temp_s1_2 == 0) {
            break;
        }

        temp_s1_2 = sp10[i] - 1;
        var_s3 = 0;

        switch (arg0) {
        case 0:
            vs_mainMenu_initUiWeapon(
                &vs_battle_inventory.weapons[temp_s1_2], &arg1[i * 2], &arg2[i], arg3);
            if (vs_battle_inventory.weapons[temp_s1_2].isEquipped != 0) {
                var_s3 = 0xCA00;
            }
            break;
        case 1:
            vs_mainMenu_setBladeUi(
                &vs_battle_inventory.blades[temp_s1_2], &arg1[i * 2], &arg2[i], arg3);
            break;
        case 2:
            vs_mainMenu_setGripUi(
                &vs_battle_inventory.grips[temp_s1_2], &arg1[i * 2], &arg2[i], arg3);
            break;
        case 3:
            vs_mainMenu_initUiShield(
                &vs_battle_inventory.shields[temp_s1_2], &arg1[i * 2], &arg2[i], arg3);
            if (vs_battle_inventory.shields[temp_s1_2].isEquipped != 0) {
                var_s3 = 0xCA00;
            }
            break;
        case 4:
            vs_mainMenu_setAccessoryUi(
                &vs_battle_inventory.armor[temp_s1_2], &arg1[i * 2], &arg2[i], arg3);
            if (vs_battle_inventory.armor[temp_s1_2].bodyPart != 0) {
                var_s3 = 0xCA00;
            }
            break;
        case 5:
            vs_mainMenu_setGemUi(
                &vs_battle_inventory.gems[temp_s1_2], &arg1[i * 2], &arg2[i], arg3);
            break;
        case 6:
            vs_mainMenu_setItemUi(
                &vs_battle_inventory.misc[temp_s1_2], &arg1[i * 2], &arg2[i], arg3);
            break;
        }

        temp_v0 = _getParentItem(arg0, temp_s1_2);
        if (temp_v0 != 0) {
            var_s3 = 0xCA00;
            if (vs_battle_inventory.weapons[temp_v0 - 1].isEquipped == 0) {
                var_s3 = 0xCC00;
            }
        }

        temp_v0 = _getParentItemIfGem(arg0, temp_s1_2);
        if (temp_v0 != 0) {
            var_s3 = 0xCA00;
            if (vs_battle_inventory.shields[temp_v0 - 1].isEquipped == 0) {
                var_s3 = 0xCC00;
            }
        }
        arg2[i] |= var_s3;
        ++sp14;
    }
    return sp14;
}

void func_8010537C(int arg0)
{
    int i;
    vs_battle_menuItem_t* menuItem;

    while (D_801023D0 < 16) {
        func_80100A5C();
    }

    for (i = 20; i < 40; ++i) {
        menuItem = vs_battle_getMenuItem(i);
        if (menuItem->state == 2) {
            menuItem->state = 1;
            menuItem->initialX = (short)(u_short)menuItem->targetX;
        }
        menuItem->selected = (i ^ (D_800F4EE8.unk0[(arg0 + 0x1E) * 2] + 0x14)) == 0;
    }
}

int func_80105454(int arg0)
{
    static char D_8010A614[8];
    static char D_8010A61C;
    static char D_8010A61D;
    static char D_8010A61E;
    static char _ __attribute__((unused));
    static int D_8010A620;

    char* sp10[128];
    int sp210[64];
    char* sp310[128];
    int sp510[64];
    int temp_a1_2;
    int temp_s3_5;
    int temp_v0_6;
    int var_a1_2;
    int var_a1_3;
    int var_s0;
    int var_s1;
    int var_s1_2;
    int i;
    u_char var_s4;
    int var_v0;
    int var_v0_3;
    char* temp_s1;
    char* temp_s2;
    char* temp_v0_7;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        menuItem = vs_battle_getMenuItem(3);
        if (menuItem->initialX >= 0xB5) {
            if (menuItem->initialX >= 0xCD) {
                menuItem->initialX -= 0x18;
            }
            menuItem->state = 2;
            menuItem->targetX = 0xB4;
        }
        func_80104F98(1);
        D_8010A6BC = 0;
        D_8010A61E = arg0 & 1;
        if (D_8010A61E != 0) {
            if (vs_main_settings.cursorMemory == 0) {
                memset(&D_800F4EE8.unk3A, 0, sizeof D_800F4EE8.unk3A);
            }
        }
        D_8010A61C = 1;
        return 0;
    }

    var_s4 = (D_800F4EE8.unk3A.itemCategory - 1) & 7;
    temp_s2 = vs_mainMenu_inventoryIndices[var_s4];

    switch (D_8010A61C) {
    case 0:
    case 1:
        temp_s1 = vs_main_allocHeapR(0x1800U);
        D_801023E3 = 1;

        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }

        if (var_s4 == 7) {
            for (i = 0; i < 4; ++i) {
                sp10[i] = (char*)&_menuText[_menuText[i + VS_menuText_INDEX_equip]];
                sp210[i] = 1;
            }
            var_s0 = 2;
        } else {
            var_s0 = func_80105088(var_s4, sp10, sp210, temp_s1);
        }
        D_8010A61D = var_s0 == 0;
        if (D_8010A61D != 0) {
            vs_mainmenu_setInformationMessage((char*)&vs_mainMenu_itemHelp[0x33E3]);
        } else {
            i = vs_main_settings.cursorMemory;
            if (D_8010A61E != 0) {
                D_8010A61E = 0;
            } else {
                vs_main_settings.cursorMemory = 1;
            }
            temp_a1_2 = var_s4 + 0x1E;
            if (var_s4 == 7) {
                var_a1_2 = temp_a1_2 | 0x200;
            } else {
                var_a1_2 = temp_a1_2 | 0x19200;
            }
            vs_mainmenu_setMenuRows(var_s0, var_a1_2, sp10, sp210);
            if (D_8010A61C == 0) {
                func_8010537C(var_s4);
            }
            vs_main_settings.cursorMemory = i;
        }
        vs_main_freeHeapR(temp_s1);
        D_8010A61C = 2;
        break;
    case 2:
        D_8010A6BB = 1;
        if (D_8010A61D != 0) {
            if (vs_main_buttonsPressed.all & 0x10) {
                vs_battle_playMenuLeaveSfx();
                return -2;
            }
            if (vs_main_buttonsPressed.all & 0x40) {
                vs_battle_playMenuLeaveSfx();
                return -1;
            }
            if (vs_main_buttonsPressed.all & 0xA0) {
                vs_battle_playInvalidSfx();
            }
        } else {
            int s7;
            u_int temp_s5 = var_s4;
            var_s0 = temp_s5 < 6;
            D_8010A6BB = var_s0 + 1;
            D_8010A620 = vs_mainmenu_getSelectedRow() + 1;

            s7 = 1;
            if (D_8010A620 == 0) {
                if (vs_main_buttonsPressed.all & 0x80) {
                    if ((var_s0 != 0) && (vs_mainmenu_ready() != 0)) {
                        vs_battle_playMenuSelectSfx();
                        var_s1 = func_80100814();
                        vs_battle_getMenuItem(var_s1 >> 8)->itemState = 0;
                        _invokeDetailsPageHandler(temp_s5 | ((var_s1 + s7) * 0x10));
                        D_8010A6B9 = 0;
                        D_8010A61C = 7;
                        break;
                    }
                    vs_battle_playInvalidSfx();
                }
            } else {
                if ((D_8010A620 <= 0) || (temp_s5 == 7)) {
                    return D_8010A620;
                }

                temp_v0_7 = vs_main_allocHeapR(0x1800);
                var_s1 = func_80105088(temp_s5, sp310, sp510, temp_v0_7);
                sp510[D_8010A620 - 1] |= 8;
                i = vs_main_settings.cursorMemory;
                vs_main_settings.cursorMemory = 1;
                vs_mainmenu_setMenuRows(var_s1, (temp_s5 + 0x1E) | 0x19200, sp310, sp510);
                vs_main_settings.cursorMemory = i;
                func_8010537C(temp_s5);
                D_8010A6BB = 1;
                D_801023E3 = 0;
                vs_main_freeHeapR(temp_v0_7);
                D_8010A61C = 6;
                break;
            }
        }
        // Fallthrough
    case 3:
        i = vs_main_buttonsState & 0x8004;
        var_s0 = vs_main_buttonsState & 0x2008;
        temp_v0_6 = i != 0;

        if (var_s0 != 0) {
            var_s1 = temp_v0_6 ^ 1;
        } else {
            var_s1 = temp_v0_6 & 1;
        }

        if (var_s1 != 0) {
            var_a1_3 = 0x8004;
            if (i == 0x8004) {
                var_a1_3 = 0x8000;
            }
            if (vs_main_buttonRepeat & var_a1_3) {
                var_s4 = (var_s4 - 1) & 7;
            }

            var_a1_3 = 0x2008;
            if (var_s0 == 0x2008) {
                var_a1_3 = 0x2000;
            }

            var_v0_3 = vs_main_buttonRepeat & var_a1_3;
            if (var_v0_3 != 0) {
                var_s4 = (var_s4 + 1) & 7;
            }
            if (var_s4 != ((D_800F4EE8.unk3A.itemCategory - 1) & 7)) {
                vs_battle_playMenuChangeSfx();
                D_800F4EE8.unk3A.itemCategory = (var_s4 + 1) & 7;
                if (D_8010A61C == 2) {
                    if (D_8010A61D == 0) {
                        func_80100814();
                        vs_mainMenu_clearMenuExcept(3);
                    }
                    D_8010A61C = 3;
                }
            }
        }
        if ((D_8010A61C == 3) && (vs_mainmenu_ready() != 0)) {
            if ((vs_main_buttonsState & 0xA00C) && (var_s1 != 0)) {
                break;
            }
            D_8010A61C = 1;
            return func_80105454(0);
        }
        break;
    case 4:
        menuItem = vs_battle_getMenuItem(3);
        if (menuItem->initialX >= 0xB5) {
            if (menuItem->initialX >= 0xCD) {
                menuItem->initialX -= 0x18;
            }
            menuItem->state = 2;
            menuItem->targetX = 0xB4;
        }
        D_8010A61C = 5;
        /* fallthrough */
    case 5:
        if (vs_mainmenu_ready() != 0) {
            D_8010A61C = 1;
        }
        break;
    case 6:
        if (vs_main_buttonsPressed.all & 0x80) {
            vs_battle_playInvalidSfx();
        }
        i = vs_mainmenu_getSelectedRow() + 1;
        if (i != 0) {
            var_s0 = D_8010A620;
            if (var_s0 == i) {
                D_8010A61C = 8;
                break;
            }
            if (i > 0) {
                var_s1 = temp_s2[i - 1];
                var_a1_3 = temp_s2[var_s0 - 1];
                if ((var_s4 == 6)
                    && (vs_battle_inventory.misc[var_s1 - 1].id
                        == vs_battle_inventory.misc[var_a1_3 - 1].id)) {
                    vs_battle_inventory.misc[var_a1_3 - 1].count =
                        vs_battle_inventory.misc[var_a1_3 - 1].count
                        + vs_battle_inventory.misc[var_s1 - 1].count;
                    if (vs_battle_inventory.misc[var_a1_3 - 1].count > 100) {
                        vs_battle_inventory.misc[var_s1 - 1].count =
                            vs_battle_inventory.misc[var_a1_3 - 1].count - 100;
                        vs_battle_inventory.misc[var_a1_3 - 1].count = 100;
                    } else {
                        vs_mainMenu_initItem(6, var_a1_3);
                    }
                } else {
                    temp_s2[i - 1] = var_a1_3;
                    temp_s2[var_s0 - 1] = var_s1;
                }
                vs_mainMenu_clearMenuExcept(3);
                D_8010A61C = 4;
                break;
            }
            if (i != -1) {
                return -2;
            }
            D_8010A61C = 0;
        }
        break;
    case 7:
        i = _invokeDetailsPageHandler(0);

        if (i == 0) {
            break;
        }

        if (i == -2) {
            return -2;
        }

        D_8010A6B9 = 1;
        menuItem = vs_battle_getMenuItem(3);

        if (menuItem->initialX >= 0xB5) {
            if (menuItem->initialX >= 0xCD) {
                menuItem->initialX -= 0x18;
            }
            menuItem->state = 2;
            menuItem->targetX = 0xB4;
        }
        D_8010A61C = 1;
        break;
    case 8:
        var_s0 = 0;
        temp_s3_5 = temp_s2[D_8010A620 - 1] - 1;
        vs_battle_rMemzero(vs_battle_rowTypeBuf, 0x14);

        if (var_s4 == 6) {
            sp310[0] = (char*)&vs_mainMenu_itemHelp[0x351D];
            sp310[1] = (char*)&_menuText[VS_menuText_OFFSET_itemUseProhibited];
            *vs_battle_rowTypeBuf = 1;
            var_s0 = 1;
            D_8010A614[1] = 1;
        }

        if (((char)(var_s4 - 1) < 2U) || (var_s4 == 5)) {
            sp310[var_s0 * 2] = (char*)&vs_mainMenu_itemHelp[0x3527];
            sp310[var_s0 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x352C];
            if ((_getParentItem(var_s4, temp_s3_5) == 0)
                && (_getParentItemIfGem(var_s4, temp_s3_5) == 0)) {
                sp310[var_s0 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x35B2];
                vs_battle_rowTypeBuf[var_s0] = 1;
            }
            ++var_s0;
            D_8010A614[var_s0] = 2;
        }

        var_s1_2 = 0;
        sp310[var_s0 * 2] = (char*)&vs_mainMenu_itemHelp[0x354A];
        sp310[var_s0 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x354F];

        switch (var_s4) {
        case 0:
            var_s1_2 = vs_battle_inventory.weapons[temp_s3_5].isEquipped != 0;
            break;
        case 3:
            var_s1_2 = vs_battle_inventory.shields[temp_s3_5].isEquipped != 0;
            break;
        case 4:
            var_s1_2 = vs_battle_inventory.armor[temp_s3_5].bodyPart != 0;
            break;
        case 6:
            if (vs_battle_inventory.misc[temp_s3_5].id >= 0x1CAU) {
                var_s1_2 = 3;
            }
            break;
        }
        temp_a1_2 = _getParentItem(var_s4, temp_s3_5);
        if (temp_a1_2 != 0) {
            var_s1_2 = 1;
            if (vs_battle_inventory.weapons[temp_a1_2 - 1].isEquipped == 0) {
                var_s1_2 = 2;
            }
        }
        temp_a1_2 = _getParentItemIfGem(var_s4, temp_s3_5);
        if (temp_a1_2 != 0) {
            var_s1_2 = 1;
            if (vs_battle_inventory.shields[temp_a1_2 - 1].isEquipped == 0) {
                var_s1_2 = 2;
            }
        }

        if (var_s1_2 != 0) {
            sp310[var_s0 * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[var_s1_2 + 0x297]];
            var_s1_2 = 1;
        }

        vs_battle_rowTypeBuf[var_s0] = var_s1_2;
        ++var_s0;
        D_8010A614[var_s0] = 3;

        if (var_s4 == 6) {
            sp310[var_s0 * 2] = (char*)&vs_mainMenu_itemHelp[0x356D];
            sp310[var_s0 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x3574];
            if (vs_battle_inventory.misc[temp_s3_5].id >= 0x1CA) {
                sp310[var_s0 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x350E];
                vs_battle_rowTypeBuf[var_s0] = 1;
            }
            ++var_s0;
            D_8010A614[var_s0] = 4;
        }

        sp310[var_s0 * 2] = (char*)&vs_mainMenu_itemHelp[0x3586];
        sp310[var_s0 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x358A];

        ++var_s0;

        D_8010A614[var_s0] = 5;
        vs_mainMenu_initSortUi(var_s0, var_s4 + 0x26, sp310, vs_battle_rowTypeBuf);
        D_8010A61C = 9;
        break;
    case 9:
        var_s1 = func_800FF348();
        vs_mainMenu_printInformation(var_s1, D_801022C4);
        vs_mainMenu_processItemActionMenu();
        i = vs_mainMenu_getSelectedItemAction() + 1;
        var_v0 = 0;
        if (i != 0) {
            if (i > 0) {
                vs_battle_playMenuSelectSfx();
                func_800FA854(0x28);
                switch (D_8010A614[i]) {
                case 2:
                    func_800FFBC8();
                    vs_mainMenu_clearMenuExcept(3);
                    D_8010A61C = 0xA;
                    break;
                case 3:
                    var_s0 = temp_s2[D_8010A620 - 1] | (var_s4 << 8);
                    if ((var_s4 == 6)
                        && (vs_battle_inventory.misc[temp_s2[D_8010A620 - 1] - 1].count
                            >= 2U)) {
                        var_s0 |= 0x10000;
                    }
                    _discardMenu(var_s0);
                    D_8010A61C = 0xB;
                    break;
                case 4:
                    _discardMenu(temp_s2[D_8010A620 - 1] | (var_s4 << 8) | 0x20000);
                    D_8010A61C = 0xB;
                    break;
                case 5:
                    func_800FFBC8();
                    _sortItems(var_s4 + 1);
                    D_8010A61C = 0xC;
                    break;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
                func_800FA854(0x28);
                if (i == -2) {
                    vs_mainMenu_clearMenuExcept(3);
                    return -2;
                }
                func_800FFBC8();
                D_8010A61C = 0;
            }
        }
        break;
    case 10:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        i = _getParentItem(var_s4, temp_s2[D_8010A620 - 1] - 1);
        if (i == 0) {
            i = _getParentItemIfGem(var_s4, temp_s2[D_8010A620 - 1] - 1);
            var_s4 = 3;
        } else {
            var_s4 = 0;
        }
        D_800F4EE8.unk3A.itemCategory = (var_s4 + 1) & 7;
        (&D_800F4EE8.unk3A)->unk2[var_s4] = vs_mainMenu_findItem(var_s4, i - 1) - 1;
        D_8010A61C = 1;
        break;
    case 11:
        i = _discardMenu(0);
        if (i != 0) {
            func_800FFBC8();
            func_800FA854(0x28);
            vs_mainMenu_clearMenuExcept(3);
            if (i == -2) {
                return -2;
            }
            D_8010A61C = 5;
        }
        break;
    case 12:
        i = _sortItems(0);
        if (i != 0) {
            func_800FA854(0x28);
            vs_mainMenu_clearMenuExcept(3);
            if (i == -2) {
                return -2;
            }
            D_8010A61C = 5;
        }
        break;
    }
    return 0;
}

void func_80106274(int arg0)
{
    static int D_8010A5C4 = 0;
    static char D_8010A5C8 = 0;

    static int D_8010A624;
    static int _ __attribute__((unused));
    static vs_unk_gfx_t2 D_8010A62C;
    static vs_unk_gfx_t D_8010A64C;

    int temp_lo;
    int temp_lo_2;
    int temp_s1_2;
    int var_s2;
    int temp_s1;
    vs_unk_gfx_t* p = (vs_unk_gfx_t*)&D_1F800000[13];

    switch (arg0) {
    case 0:
        var_s2 = D_8010A508;
        switch (D_8010A50C) {
        case 0:
            if (var_s2 < 0xA) {
                var_s2 += 1;
                D_8010A508 = var_s2;
            }
            var_s2 = 0x80 - vs_battle_rowAnimationSteps[0xA - var_s2];
            break;
        case 1:
            if (var_s2 > 0) {
                var_s2 -= 1;
                D_8010A508 = var_s2;
            }
            var_s2 = vs_battle_rowAnimationSteps[var_s2];
            break;
        case 2:
            if (var_s2 < 0xA) {
                var_s2 += 1;
                D_8010A508 = var_s2;
            } else {
                D_8010A50C = 0;
            }
            var_s2 = vs_battle_rowAnimationSteps[0xA - var_s2] + 0x80;
            break;
        case 3:
            if (var_s2 > 0) {
                var_s2 -= 1;
                D_8010A508 = var_s2;
            }
            var_s2 = 0x260 - var_s2 * 0x30;
            break;
        }
        if (D_8010A5C8 != 0) {
            D_8010A5C8 = 0;
            return;
        }
        if (D_8010A5C4 != 0) {
            temp_s1 = ((u_short*)D_800F4538[1])[0x32B];
            p->unk10 = ((-rsin(0xB00) * var_s2) >> 8) * temp_s1;
            p->unk14.unk0 = -(((u_short*)D_800F4538[1])[0x31F] << 0xB);
            p->unk14.unk4 = ((rcos(0xB00) * var_s2) >> 8) * temp_s1;
            temp_s1_2 = temp_s1 * 4;
            temp_lo = rcos(0xB00) * temp_s1_2;
            p->unk0 = p->unk10 + temp_lo;
            p->unk4 = p->unk14.unk0;
            temp_lo_2 = rsin(0xB00) * temp_s1_2;
            p->unk14.unkC = 0;
            p->unk14.unk10 = 0;
            p->unk14.unk14 = 0;
            p->unk14.unk1C = 0x1000;
            p->unk8 = p->unk14.unk4 + temp_lo_2;
            func_8007ACB0();
            func_800F9EB8(&D_1F800000[5]);
            return;
        }
        return;
    case 1:
        if (D_8010A5C4 == 0) {
            D_8010A508 = 0;
            D_8010A50C = 2;
            D_8010A5C8 = arg0;
            D_8010A5C4 = arg0;
            D_8010A624 = vs_main_projectionDistance;
            vs_battle_setProjectionDistance(0x200);

            D_8010A62C = p[-1].unk14;
            D_8010A64C = *p;

            p->unk14.unkC = 0;
            p->unk14.unk10 = 0;
            p->unk14.unk14 = 0;
            p->unk14.unk1C = 0x1000;
            func_8007ACB0();
            func_80100414(0x7FE, 0x80);
            func_800F9A24(0);
            return;
        }
        break;
    case 2:
        if (D_8010A5C4 != 0) {
            func_800F9E0C();
            func_80100414(-4, 0x80);
            vs_battle_setProjectionDistance(D_8010A624);
            p[-1].unk14 = D_8010A62C;
            *p = D_8010A64C;
            D_8010A5C4 = 0;
        }
        break;
    }
}

int func_801066CC(int arg0)
{
    static char D_8010A680;
    static char D_8010A681;

    int var_s0;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        D_800F4EE8.unk3A.itemCategory = arg0;
        D_8010A6B0 = 0;
        D_8010A6B2 = 0;
        D_8010A680 = 0;
        return 0;
    }
    switch (D_8010A680) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_800FFB68(1);
            func_800FFA88(2);
            menuItem = vs_battle_setMenuItem(3, 0x140, 0x12, 0x7E, 8,
                (char*)&vs_battle_menuStrings[vs_battle_menuStrings[3]]);
            menuItem->state = 2;
            menuItem->targetX = 0xB4;
            menuItem->selected = 1;
            D_8010A680 = 1;
        }
        break;
    case 1:
        func_80104F98(0);
        D_8010A6BC = 0;
        D_8010A6BD = 0;
        D_8010A6BE = 0;
        D_8010A6BF = 0;
        if (vs_mainmenu_ready() != 0) {
            func_8008A4DC(0);
            D_8010A681 = D_800EB9AF;
            if (!D_8010A681) {
                func_800CB654(1);
                D_800EB9B0 = 0x200000;
            }
            func_80106274(1);
            func_80105454(1);
            D_8010A680 = 2;
        }
        break;
    case 2:
        if (func_80105454(0) != 0) {
            func_80104F98(0);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            func_8008A4DC(1);
            if (D_8010A681 == 0) {
                func_800CB654(0);
                D_800EB9B0 = 0;
            }
            func_80106274(2);
            D_8010A680 = 3;
            if (vs_main_settings.information == 0) {
                func_800FFBA8();
            }
        }
        break;
    case 3:
        func_800FFB68(0);
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            D_8010A6B0 = 1;
            D_8010A6B2 = 1;
            return 1;
        }
        break;
    }

    if (D_8010A6B9 != 0) {
        if (D_8010A6BC < 10) {
            ++D_8010A6BC;
        }
        var_s0 = vs_battle_rowAnimationSteps[0xA - D_8010A6BC];
    } else {
        if (D_8010A6BC != 0) {
            --D_8010A6BC;
        }
        var_s0 = (0xA - D_8010A6BC) << 5;
    }
    if ((D_8010A6BC != 0) && (D_8010A6BF == 0)) {
        int itemCategory = (D_800F4EE8.unk3A.itemCategory - 1) & 7;
        vs_battle_menuItem_t* menuItem =
            vs_battle_setMenuItem(0x1F, var_s0 + 0xB4, 0x22, 0x8C, 8,
                (char*)&_menuText[_menuText[itemCategory + VS_menuText_INDEX_weapons]]);
        menuItem->selected = 1;
        if (itemCategory != 7) {
            menuItem->unk12 = vs_mainMenu_inventoryItemCapacities[itemCategory];
            menuItem->unk10 = vs_mainMenu_getItemCount(itemCategory, NULL);
        }
    }
    func_80106274(0);
    if (D_8010A6BA != 0) {
        if (D_8010A6BD < 4) {
            ++D_8010A6BD;
        }
    } else if (D_8010A6BD != 0) {
        D_8010A6BD -= 1;
    }
    func_80102B14(D_8010A6BD, D_8010A6BF);
    if (D_8010A6BB != 0) {
        if (D_8010A6BE < 10) {
            ++D_8010A6BE;
        }
        var_s0 = vs_battle_rowAnimationSteps[0xA - D_8010A6BE];
    } else {
        if (D_8010A6BE != 0) {
            --D_8010A6BE;
        }
        var_s0 = (0xA - D_8010A6BE) << 5;
    }
    if (D_8010A6BE != 0) {
        vs_mainMenu_drawButtonUiBackground(0x10 - var_s0, 0x26, 0x58, 0xA);
        vs_mainmenu_drawButton(1, 8 - var_s0, 0x24, NULL);
        vs_battle_renderTextRawColor("STATUS", ((0x1C - var_s0) & 0xFFFF) | 0x260000,
            0x202020 << D_8010A6BB, NULL);
    }
    return 0;
}

void func_801080F0(void);

int func_80106B80(int arg0)
{
    static char D_8010A5C9 = 0;

    static char D_8010A682;
    static char D_8010A683;
    static char D_8010A684;
    static u_char D_8010A685;
    static char D_8010A686;
    static char _ __attribute__((unused));

    int i;
    int temp_v0_3;
    int temp_v0_4;
    vs_battle_inventoryShield* temp_a0;
    vs_battle_inventoryShield* shield;
    vs_battle_inventoryWeapon* temp_a2;
    vs_battle_inventoryWeapon* weapon;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        vs_battle_memcpy(D_8010A6A4, D_8010A6A0, 0x280);
        D_8010A6B2 = 0;
        D_8010A684 = D_8010A6B6;
        D_8010A685 = arg0 - 1;
        D_8010A686 = D_8010A6A0[D_8010A685].unk0;
        D_8010A6B4 = 0;
        D_8010A6B5 = 0;
        D_8010A683 = 0;
        D_8010A682 = 0;
        return 0;
    }

    i = D_8010A6A4[D_8010A685].unk1;

    switch (D_8010A682) {
    case 0:
        if (D_8010A6B3 != 6) {
            break;
        }
        vs_battle_rMemzero(D_8010A6A0, 0x280);
        D_8010A6A0->unk0 = D_8010A6A4[D_8010A685].unk0;
        D_8010A6A0->unk1 = i;
        D_8010A6A0->unk3 = 2;
        if (D_8010A686 != 0) {
            shield = &_inventory->shields[i];
            D_8010A6A0[1].unk0 = 3;
            D_8010A6A0[1].unk1 = i;
            D_8010A6A0[1].unk3 = 3;
            D_8010A6B6 = 2;

            for (i = 0; i < shield->base.gemSlots; ++i) {
                if (shield->gems[i] != 0) {
                    D_8010A6A0[D_8010A6B6].unk0 = 5;
                    D_8010A6A0[D_8010A6B6].unk1 = shield->gems[i] - 1;
                    D_8010A6A0[D_8010A6B6].unk3 = 5;
                    ++D_8010A6B6;
                }
            }
        } else {
            weapon = &_inventory->weapons[i];
            D_8010A6A0[1].unk0 = 1;
            D_8010A6A0[1].unk1 = weapon->blade - 1;
            D_8010A6A0[1].unk3 = 4;
            D_8010A6A0[2].unk0 = 2;
            D_8010A6A0[2].unk1 = weapon->grip - 1;
            D_8010A6A0[2].unk3 = 4;
            D_8010A6B6 = 3;

            for (i = 0; i < _inventory->grips[weapon->grip - 1].gemSlots; ++i) {
                if (weapon->gems[i] != 0) {
                    D_8010A6A0[D_8010A6B6].unk0 = 5;
                    D_8010A6A0[D_8010A6B6].unk1 = weapon->gems[i] - 1;
                    D_8010A6A0[D_8010A6B6].unk3 = 5;
                    ++D_8010A6B6;
                }
            }
        }
        D_8010A6B3 = 10;
        D_8010A6B2 = 1;
        D_8010A682 = 1;
        break;
    case 1:
        menuItem = vs_battle_setMenuItem(
            0x1E, 0x140, 0x92, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionYes]);
        menuItem->state = 2;
        menuItem->targetX = 0xC2;
        D_8010A682 = 2;
        break;
    case 2:
        menuItem = vs_battle_setMenuItem(
            0x1F, 0x140, 0xA2, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionNo]);
        menuItem->state = 2;
        menuItem->targetX = 0xC2;
        vs_battle_stringContext.strings[0] =
            D_8010A686 == 0 ? _inventory->weapons[i].name
                            : vs_mainMenu_itemNames[_inventory->shields[i].base.id];
        func_800C8E04(1);
        vs_mainmenu_setInformationMessage(
            (char*)&_menuText[VS_menuText_OFFSET_disassembleConfirm]);
        D_8010A682 = 3;
        break;
    case 3:
        D_8010A682 += vs_mainmenu_ready();
        break;
    case 4:
        vs_battle_getMenuItem(D_8010A683 + 0x1E)->selected = 1;
        vs_battle_getMenuItem(0x1F - D_8010A683)->selected = 0;
        if (vs_main_buttonsPressed.all & 0x60) {
            vs_mainMenu_menuItemLeaveRight(0x1E);
            vs_mainMenu_menuItemLeaveRight(0x1F);
            D_8010A6B2 = 0;
            if ((D_8010A683 != 0) || (vs_main_buttonsPressed.all & 0x40)) {
                vs_battle_playMenuLeaveSfx();
                D_8010A682 = 6;
            } else {
                vs_main_playSfxDefault(0x7E, 0x19);
                D_8010A682 = 5;
            }
            if (vs_main_settings.information == 0) {
                func_800FFBA8();
            }
            break;
        }
        if (vs_main_buttonRepeat & 0x5000) {
            vs_battle_playMenuChangeSfx();
            D_8010A683 = (1 - D_8010A683);
        }
        D_8010A5C9 = vs_battle_drawCursor(D_8010A5C9, D_8010A683 + 8);
        break;
    case 5:
        if (D_8010A6B3 != 6) {
            break;
        }

        vs_battle_rMemcpy(&D_8010A6A4[D_8010A684], &D_8010A6A0[1], (D_8010A6B6 - 1) * 4);

        if (D_8010A686 != 0) {
            temp_a0 = &_inventory->shields[i];
            for (i = 0; i < temp_a0->base.gemSlots; ++i) {
                temp_v0_3 = temp_a0->gems[i];
                if (temp_v0_3 != 0) {
                    temp_a0->gems[i] = 0;
                    _inventory->gems[temp_v0_3 - 1].setItemIndex = 0;
                }
            }
        } else {
            temp_a2 = &_inventory->weapons[i];
            _inventory->blades[temp_a2->blade - 1].assembledWeaponIndex = 0;
            _inventory->grips[temp_a2->grip - 1].assembledWeaponIndex = 0;

            for (i = 0; i < _inventory->grips[temp_a2->grip - 1].gemSlots; ++i) {
                temp_v0_4 = temp_a2->gems[i];
                if (temp_v0_4 != 0) {
                    temp_a2->gems[i] = 0;
                    _inventory->gems[temp_v0_4 - 1].setItemIndex = 0;
                }
            }
        }

        D_8010A684 = D_8010A6B6 + (D_8010A684 + 0xFE);
        for (i = D_8010A685; i < D_8010A684; ++i) {
            D_8010A6A4[i] = D_8010A6A4[i + 1];
        }
        // Fallthrough
    case 6:
        if (D_8010A6B3 == 6) {
            D_8010A6B6 = D_8010A684;
            vs_battle_memcpy(D_8010A6A0, D_8010A6A4, 0x280);
            func_801080F0();
            D_8010A6B3 = 10;
            D_8010A6B2 = 1;
            D_8010A682 = 7;
        }
        break;
    case 7:
        if (D_8010A6B3 != 0) {
            break;
        }
        return -1;
    }
    return 0;
}

int func_801073E0(int arg0)
{
    static char D_8010A5CA = 0;

    static u_short D_8010A688;
    static u_short D_8010A68A;
    static u_short D_8010A68C;
    static char D_8010A68E;
    static char D_8010A68F;
    static u_char D_8010A690;

    D_8010A6A0_t* temp_a3;
    int j;
    int i;
    int var_v0;
    vs_battle_inventoryMisc* item;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        vs_battle_memcpy(D_8010A6A4, D_8010A6A0, 0x280);
        vs_battle_memcpy(D_8010A6AC, _inventory, 0xF00);
        D_8010A6B2 = 0;
        D_8010A690 = D_8010A6B6;
        D_8010A68C = _inventory->misc[D_8010A6A0[arg0 - 1].unk1].id;
        D_8010A6B4 = 0;
        D_8010A6B5 = 0;
        D_8010A68F = 0;
        D_8010A68E = 0;
        return 0;
    }
    switch (D_8010A68E) {
    case 0:
        if (D_8010A6B3 == 6) {
            D_8010A68A = 0;
            item = vs_battle_inventory.misc;
            for (i = 0; i < 64; ++i, ++item) {
                if (item->id == D_8010A68C) {
                    int v0 = D_8010A68A + 100;
                    v0 -= item->count;
                    D_8010A68A = v0;
                }
            }

            D_8010A688 = 0;

            for (i = 0; i < D_8010A6B6; ++i) {
                if (D_8010A6A0[i].unk0 == 6) {
                    item = &_inventory->misc[D_8010A6A0[i].unk1];
                    if (item->id == D_8010A68C) {
                        D_8010A688 += item->count;
                        vs_battle_rMemzero(item, 4);
                        --D_8010A6B6;
                        for (j = i; j < D_8010A6B6; ++j) {
                            D_8010A6A0[j] = D_8010A6A0[j + 1];
                        }
                        --i;
                    }
                }
            }

            D_8010A6B6 = 0;

            while (D_8010A688 != 0) {
                for (i = 0; i < 64; ++i) {
                    if (_inventory->misc[i].id == 0) {
                        break;
                    }
                }

                if (i == 0x40) {
                    break;
                }

                temp_a3 = &D_8010A6A0[D_8010A6B6++];
                temp_a3->unk0 = 6;
                temp_a3->unk1 = i;
                temp_a3->unk2 = 0;
                _inventory->misc[i].id = D_8010A68C;
                temp_a3->unk3 = D_8010A68A != 0;
                if (temp_a3->unk3 != 0) {
                    if (D_8010A68A > 100) {
                        _inventory->misc[i].count = 100;
                        D_8010A688 -= 100;
                        D_8010A68A -= 100;
                    } else {
                        _inventory->misc[i].count = D_8010A68A;
                        D_8010A688 = D_8010A688 - D_8010A68A;
                        D_8010A68A = 0;
                    }
                } else if (D_8010A688 > 100) {
                    _inventory->misc[i].count = 100;
                    D_8010A688 -= 100;
                } else {
                    _inventory->misc[i].count = D_8010A688;
                    D_8010A688 = 0;
                }
            }
            D_8010A6B3 = 10;
            D_8010A6B2 = 1;
            D_8010A68E = 1;
        }
        break;
    case 1:
        menuItem = vs_battle_setMenuItem(
            0x1E, 0x140, 0x92, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionYes]);
        menuItem->state = 2;
        menuItem->targetX = 0xC2;
        D_8010A68E = 2;
        break;
    case 2:
        menuItem = vs_battle_setMenuItem(
            0x1F, 0x140, 0xA2, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionNo]);
        menuItem->state = 2;
        menuItem->targetX = 0xC2;
        vs_battle_stringContext.strings[0] = vs_mainMenu_itemNames[D_8010A68C];
        func_800C8E04(1);
        vs_mainmenu_setInformationMessage(
            (char*)&_menuText[VS_menuText_OFFSET_organizeConfirm]);
        D_8010A68E = 3;
        break;
    case 3:
        D_8010A68E += vs_mainmenu_ready();
        break;
    case 4:
        vs_battle_getMenuItem(D_8010A68F + 0x1E)->selected = 1;
        vs_battle_getMenuItem(0x1F - D_8010A68F)->selected = 0;
        if (vs_main_buttonsPressed.all & 0x60) {
            vs_mainMenu_menuItemLeaveRight(0x1E);
            vs_mainMenu_menuItemLeaveRight(0x1F);
            D_8010A6B2 = 0;
            if ((D_8010A68F != 0) || (vs_main_buttonsPressed.all & 0x40)) {
                vs_battle_playMenuLeaveSfx();
                D_8010A68E = 6;
            } else {
                vs_battle_playMenuSelectSfx();
                D_8010A68E = 5;
            }
            var_v0 = 0;
            if (vs_main_settings.information == 0) {
                func_800FFBA8();
            }
            break;
        }
        if (vs_main_buttonRepeat & 0x5000) {
            vs_battle_playMenuChangeSfx();
            D_8010A68F = (1 - D_8010A68F);
        }
        D_8010A5CA = vs_battle_drawCursor((int)D_8010A5CA, D_8010A68F + 8);
        break;
    case 5:
        if (D_8010A6B3 != 6) {
            break;
        }

        for (i = 0; i < D_8010A690; ++i) {
            if (D_8010A6A4[i].unk0 == 6) {
                item = &D_8010A6AC->misc[D_8010A6A4[i].unk1];
                if (item->id == D_8010A68C) {
                    vs_battle_rMemzero(item, 4);
                    --D_8010A690;
                    for (j = i; j < D_8010A690; ++j) {
                        D_8010A6A4[j] = D_8010A6A4[j + 1];
                    }
                    --i;
                }
            }
        }

        for (i = 0; i < D_8010A6B6; ++i) {
            for (j = 0; j < 64; ++j) {
                if (D_8010A6AC->misc[j].id == 0) {
                    break;
                }
            }
            if (j == 0x40) {
                break;
            }

            temp_a3 = &D_8010A6A4[D_8010A690++];
            temp_a3->unk0 = 6;
            temp_a3->unk1 = j;
            temp_a3->unk2 = 0;
            temp_a3->unk3 = D_8010A6A0[i].unk3;
            item = &D_8010A6AC->misc[j];
            item->id = D_8010A68C;
            item->count = _inventory->misc[D_8010A6A0[i].unk1].count;
        }
        // Fallthrough
    case 6:
        if (D_8010A6B3 == 6) {
            D_8010A6B6 = D_8010A690;
            vs_battle_memcpy(D_8010A6A0, D_8010A6A4, 0x280);
            vs_battle_memcpy(_inventory, D_8010A6AC, 0xF00);
            D_8010A6B3 = 0xA;
            D_8010A6B2 = 1;
            D_8010A68E = 7;
        }
        break;
    case 7:
        if (D_8010A6B3 != 0) {
            break;
        }
        return -1;
    }
    return 0;
}

int _copyBladeToInventory(vs_battle_inventoryBlade* source, int weapon)
{
    int index = 1;
    vs_battle_inventoryBlade* blade = _inventory->blades;

    while (blade->id != 0) {
        ++blade;
        ++index;
        if (index == 16) {
            return 0;
        }
    }
    vs_battle_copyAligned(blade, source, sizeof *blade);
    blade->assembledWeaponIndex = weapon;
    blade->index = index;
    return index;
}

int _copyGripToInventory(vs_battle_inventoryGrip* source, int weaponIndex)
{
    int index = 1;
    vs_battle_inventoryGrip* grip = _inventory->grips;

    while (grip->id != 0) {
        ++grip;
        ++index;
        if (index == 16) {
            return 0;
        }
    }
    vs_battle_copyAligned(grip, source, sizeof *grip);
    grip->assembledWeaponIndex = weaponIndex;
    grip->index = index;
    return index;
}

int _copyGemToInventory(vs_battle_inventoryGem* source, int item)
{
    int index = 1;
    vs_battle_inventoryGem* gem = _inventory->gems;

    while (gem->id != 0) {
        ++gem;
        ++index;
        if (index == 0x30) {
            return 0;
        }
    }
    vs_battle_copyAligned(gem, source, sizeof *gem);
    gem->setItemIndex = item;
    gem->index = index;
    return index;
}

int _copyWeaponToInventory(vs_battle_lootedWeapon* arg0)
{
    int i;
    vs_battle_inventoryWeapon* slot = _inventory->weapons;
    int index = 1;

    while (slot->blade != 0) {
        ++slot;
        if (++index == 8) {
            return 0;
        }
    }

    vs_battle_rMemzero(slot, sizeof *slot);
    slot->index = index;
    slot->blade = _copyBladeToInventory(&arg0->blade, index);
    slot->grip = _copyGripToInventory(&arg0->grip, index);

    for (i = 0; i < 3; i++) {
        if (arg0->gems[i].id != 0)
            slot->gems[i] = _copyGemToInventory(&arg0->gems[i], index);
    }

    vs_battle_rMemcpy(slot->name, arg0->unk94, sizeof slot->name);
    return index;
}

int _copyArmorToInventory(vs_battle_inventoryArmor* source)
{
    int index = 1;
    vs_battle_inventoryArmor* armor = _inventory->armor;

    while (armor->id != 0) {
        ++armor;
        ++index;
        if (index == 16) {
            return 0;
        }
    }
    vs_battle_copyAligned(armor, source, sizeof *armor);
    armor->index = index;
    return index;
}

int _copyShieldToInventory(vs_battle_lootedShield* arg0)
{
    int i;

    vs_battle_inventoryShield* shield = _inventory->shields;
    int index = 1;

    while (shield->base.id != 0) {
        ++shield;
        ++index;
        if (index == 8) {
            return 0;
        }
    }
    vs_battle_rMemzero(shield, sizeof *shield);
    vs_battle_copyAligned(&shield->base, &arg0->shield, sizeof shield->base);

    shield->base.bodyPart = index;

    for (i = 0; i < 3; ++i) {
        if (arg0->gems[i].id != 0) {
            shield->gems[i] = _copyGemToInventory(&arg0->gems[i], index | 0x80);
        }
    }
    return index;
}

int _copyMiscToInventory(vs_battle_lootedMisc* arg0)
{
    int index = 1;
    vs_battle_inventoryMisc* item = _inventory->misc;

    while (item->id != 0) {
        ++index;
        ++item;
        if (index == 64) {
            return 0;
        }
    }

    item->id = arg0->id;
    item->count = arg0->count;
    return index;
}

void func_801080F0(void)
{
    int i;
    int temp_v1;
    D_8010A6A0_t* var_s1 = D_8010A6A0;

    for (i = 0; i < D_8010A6B6; ++i, ++var_s1) {
        var_s1->unk3 =
            func_800FEB94(var_s1->unk0, &vs_battle_inventory, var_s1->unk1, _inventory)
            != 0;
    }

    i = D_8010A6B4 + D_8010A6B5;

    if (i >= D_8010A6B6) {
        i = D_8010A6B6 - 1;
        D_8010A6B5 = D_8010A6B6 - 8;
        D_8010A6B4 = 7;
    }
    if (D_8010A6B6 < 9) {
        D_8010A6B4 = i;
        D_8010A6B5 = 0;
        return;
    }
    temp_v1 = D_8010A6B6 - 8;
    if (temp_v1 < D_8010A6B5) {
        D_8010A6B5 = temp_v1;
        D_8010A6B4 = i - temp_v1;
    }
    if ((D_8010A6B4 == 7) && (i != (D_8010A6B6 - 1))) {
        D_8010A6B4 -= 1;
        D_8010A6B5 = D_8010A6B5 + 1;
    }
}

void func_8010822C(int arg0, int arg1)
{
    D_8010A6A0_t* temp_v1 = &D_8010A6A0[D_8010A6B6++];
    temp_v1->unk0 = arg0;
    temp_v1->unk1 = arg1 - 1;
    temp_v1->unk2 = 0;
}

static char* D_8010A5CC[] = { "WEAPON", "BLADE", "GRIP", "SHIELD", "ARMOR", "GEM",
    "MISC" };

int func_80108264(int arg0, D_8010A6A0_t* arg1)
{
    int i;
    vs_battle_inventoryShield* shield;
    vs_battle_inventoryWeapon* weapon;

    int temp_t0 = arg1->unk0;
    int var_a2 = 0;

    switch (arg0) {
    case 1:
    case 2:
        var_a2 += temp_t0 == 0;
        // Fallthrough
    case 0:
    case 3:
    case 4:
    case 6:
        var_a2 += temp_t0 == arg0;
        break;
    case 5:
        var_a2 += temp_t0 == 5;
        if (temp_t0 == 0) {
            weapon = &_inventory->weapons[arg1->unk1];

            for (i = 0; i < _inventory->grips[weapon->grip - 1].gemSlots; ++i) {
                var_a2 += weapon->gems[i] != 0;
            }
        }
        if (temp_t0 == 3) {
            shield = &_inventory->shields[arg1->unk1];

            for (i = 0; i < shield->base.gemSlots; ++i) {
                var_a2 += shield->gems[i] != 0;
            }
        }
        break;
    }
    return var_a2;
}

void func_8010837C(int arg0)
{
    int sp10;
    int temp_s0;
    int temp_s4;
    int var_a2;
    int var_fp;
    int var_s0;
    int var_s0_2;
    int i;
    int var_s2;
    int temp_s3;
    D_8010A6A0_t* var_s6;
    unsigned int new_var;
    char* c;
    int new_var2;

    var_s6 = NULL;
    var_fp = 1;
    if (D_8010A6B7 != 0) {
        var_s6 = (D_8010A6A0_t*)1;
        if (D_8010A6B7 & 0xF) {

            var_fp = 0;
            var_s6 = &D_8010A6A0[D_8010A6B5 + D_8010A6B7 - 1];
            for (i = 0; i < D_8010A6B6; ++i) {
                var_fp += D_8010A6A0[i].unk3;
            }
        }
    }
    vs_battle_renderTextRaw("GADGET BAG", (arg0 + 0xB0) | 0xC0000, NULL);

    sp10 = arg0 + 0x110;

    for (i = 0; i < 7; ++i) {
        var_s0 = 0x808080;
        temp_s3 = vs_mainMenu_inventoryItemCapacities[i];
        temp_s4 = vs_mainMenu_getItemCount(i, NULL);

        if (var_s6 != NULL) {
            var_s0_2 = 0;
            if ((var_s6 == (D_8010A6A0_t*)1) || (func_80108264(i, var_s6) != 0)) {
                var_s0_2 = 1;
            }
            var_s0 = 0x404040 << var_s0_2;
        }
        new_var2 = 0x180000;
        var_s2 = (new_var2 + i * 0xC0000);
        vs_battle_renderTextRawColor("/", sp10 | var_s2, var_s0, NULL);
        vs_battle_renderTextRawColor(D_8010A5CC[i], (arg0 + 0xC0) | var_s2, var_s0, NULL);
        vs_mainMenu_printIntColor(temp_s3, (arg0 + 0x128) | var_s2, var_s0, NULL);

        if (((u_int)var_s0 >> 0x17) != 0) {
            if ((temp_s4 * 2) < (int)temp_s3) {
                var_s0 = 0x804020;
            }
            if (((u_long)var_s6 >> 1) != 0) {
                if (temp_s3 < (func_80108264(i, var_s6) + temp_s4)) {
                    var_s0 = 0x204080;
                }
            }
        }
        vs_mainMenu_printIntColor(temp_s4, sp10 | var_s2, var_s0, NULL);
    }

    temp_s0 = arg0 + 0xB8;
    vs_mainMenu_drawButtonUiBackground(temp_s0, 0x70, 0x70, 0xA);
    vs_mainMenu_drawButtonUiBackground(temp_s0, 0x80, 0x40, 0xA);
    vs_battle_renderTextRawColor(
        "GET", (arg0 + 0xC4) | 0x700000, 0x404040 << D_8010A505, NULL);
    vs_mainmenu_drawButton(2, arg0 + 0xB0, 0x6E, NULL);

    c = "ALL";
    new_var = (arg0 + 0xFC) | 0x700000;
    if (var_fp != 0) {
        var_a2 = 0x404040 << (D_8010A505 & 1);
    } else {
        var_a2 = 0x404040;
    }

    vs_battle_renderTextRawColor(c, new_var, var_a2, NULL);
    vs_mainmenu_drawButton(1, arg0 + 0xE8, 0x6E, NULL);
    vs_battle_renderTextRawColor(
        "END", (arg0 + 0xC4) | 0x800000, 0x404040 << D_8010A505, NULL);
    vs_mainmenu_drawButton(3, arg0 + 0xB0, 0x7E, NULL);
}

static int _droppableUnderCurrentDifficulty(int arg0)
{
    return arg0 & (vs_main_stateFlags.difficulty + 1);
}

void _applyDropList(vs_battle_loot* arg0)
{
    int i;

    if (_droppableUnderCurrentDifficulty(arg0->weapon.difficultyFlags) != 0) {
        func_8010822C(0, _copyWeaponToInventory(&arg0->weapon));
    }

    if (_droppableUnderCurrentDifficulty(arg0->blade.difficultyFlags) != 0) {
        func_8010822C(1, _copyBladeToInventory(&arg0->blade.blade, 0));
    }

    if (_droppableUnderCurrentDifficulty(arg0->grip.difficultyFlags) != 0) {
        func_8010822C(2, _copyGripToInventory(&arg0->grip.grip, 0));
    }

    if (_droppableUnderCurrentDifficulty(arg0->shield.difficultyFlags) != 0) {
        func_8010822C(3, _copyShieldToInventory(&arg0->shield));
    }

    for (i = 0; i < 2; ++i) {
        if (_droppableUnderCurrentDifficulty(arg0->armor[i].difficultyFlags) != 0) {
            func_8010822C(4, _copyArmorToInventory(&arg0->armor[i].armor));
        }
    }

    if (_droppableUnderCurrentDifficulty(arg0->accessory.difficultyFlags) != 0) {
        func_8010822C(4, _copyArmorToInventory(&arg0->accessory.accessory));
    }

    if (_droppableUnderCurrentDifficulty(arg0->gem.difficultyFlags) != 0) {
        func_8010822C(5, _copyGemToInventory(&arg0->gem.gem, 0));
    }

    for (i = 0; i < 3; ++i) {
        if ((_droppableUnderCurrentDifficulty(arg0->misc[i].difficultyFlags) != 0)
            && (arg0->misc[i].id != 0) && (arg0->misc[i].count != 0)) {
            func_8010822C(6, _copyMiscToInventory(&arg0->misc[i]));
        }
    }
    func_801080F0();
}

void func_801088D4(vs_battle_lootListNode* arg0)
{
    vs_battle_rMemzero(_inventory, sizeof *_inventory);

    if (arg0 != NULL) {
        while (arg0 != NULL) {
            _applyDropList(&arg0->loot);
            arg0 = arg0->next;
        }
    } else {
        _applyDropList(D_800EB9C8);
    }
}

void func_80108938(int arg0)
{
    char sp18[0x100];
    int sp118;
    D_8010A6A0_t* var_fp;
    int i;
    int temp_s1;
    int temp_v1_3;
    vs_battle_inventoryWeapon* weapon;
    vs_battle_inventoryBlade* blade;
    vs_battle_inventoryBlade* blade2;
    vs_battle_inventoryGrip* grip;
    vs_battle_inventoryShield* shield;
    vs_battle_inventoryArmor* armor;
    vs_battle_inventoryGem* gem;
    vs_battle_inventoryMisc* misc;
    vs_battle_menuItem_t* menuItem;

    sp118 = D_8010A6B6;
    var_fp = &D_8010A6A0[D_8010A6B5];
    vs_battle_rMemzero(&sp18, 0x100);

    for (i = 0; i < 8; ++i) {
        menuItem = vs_battle_getMenuItem(i + 0x20);
        sp18[i + D_8010A504] = menuItem->animationState;
        menuItem->state = 0;
    }

    if (sp118 >= 9) {
        sp118 = 8;
    }

    for (i = 0; i < sp118;) {
        temp_s1 = var_fp->unk1;
        menuItem = vs_battle_getMenuItem(0x20 + i);

        switch (var_fp->unk0) {
        case 0:
            weapon = &_inventory->weapons[temp_s1];
            blade = &_inventory->blades[weapon->blade - 1];
            menuItem = vs_battle_setMenuItem(
                0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98, 0, weapon->name);
            menuItem->icon = blade->category;
            menuItem->material = blade->material;
            break;
        case 1:
            blade2 = &_inventory->blades[temp_s1];
            menuItem = vs_battle_setMenuItem(0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98,
                0, vs_mainMenu_itemNames[blade2->id]);
            menuItem->icon = blade2->category;
            menuItem->material = blade2->material;
            break;
        case 2:
            grip = &_inventory->grips[temp_s1];
            menuItem = vs_battle_setMenuItem(0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98,
                0, vs_mainMenu_itemNames[grip->id]);
            menuItem->icon = grip->category + 10;
            break;
        case 3:
            shield = &_inventory->shields[temp_s1];
            menuItem = vs_battle_setMenuItem(0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98,
                0, vs_mainMenu_itemNames[shield->base.id]);
            menuItem->icon = 0xF;
            menuItem->material = shield->base.material;
            break;
        case 4:
            armor = &_inventory->armor[temp_s1];
            menuItem = vs_battle_setMenuItem(0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98,
                0, vs_mainMenu_itemNames[armor->id]);
            menuItem->icon = armor->category + 0xE;
            menuItem->material = armor->material;
            break;
        case 5:
            gem = &_inventory->gems[temp_s1];
            menuItem = vs_battle_setMenuItem(0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98,
                0, vs_mainMenu_itemNames[gem->id]);
            menuItem->icon = 22;
            break;
        case 6:
            misc = &_inventory->misc[temp_s1];
            menuItem = vs_battle_setMenuItem(0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98,
                0, vs_mainMenu_itemNames[misc->id]);
            menuItem->unk10 = misc->count;
            menuItem->unkA = (misc->id < 0x1CA) ^ 1;
            break;
        }
        menuItem->animationState = sp18[i + D_8010A6B5];
        menuItem->unk7 = var_fp->unk3 == 0;

        if (var_fp->unk2 != 0) {
            menuItem->initialX -= var_fp->unk2 * 0x30;
            ++var_fp->unk2;
            if (var_fp->unk2 == 4) {
                menuItem->animationState = 0;
            }
        }
        if (i == 0) {
            if (D_8010A6B5 != 0) {
                menuItem->fadeEffect = 1;
            }
        }
        if ((i == 7) && (D_8010A6B5 != (D_8010A6B6 - 8))) {
            menuItem->fadeEffect = 2;
        }
        temp_v1_3 = var_fp->unk3;
        if (temp_v1_3 == 2) {
            menuItem->unk2 = 0x18;
        }
        if (temp_v1_3 >= 3) {
            menuItem->initialX += (temp_v1_3 - 3) * 7;
        }
        ++i;
        ++var_fp;
    }
    D_8010A504 = D_8010A6B5;
}

void func_80108E78(int arg0)
{
    char* menuText[2];
    int rowType;
    int temp_s3 = D_8010A6A0[arg0].unk1;

    vs_battle_memcpy(D_8010A6AC, &vs_battle_inventory, sizeof *D_8010A6AC);
    vs_battle_memcpy(&vs_battle_inventory, _inventory, sizeof vs_battle_inventory);

    switch (D_8010A6A0[arg0].unk0) {
    case 0:
        vs_mainMenu_initUiWeapon(&vs_battle_inventory.weapons[temp_s3], menuText,
            &rowType, vs_battle_stringBuf);
        break;
    case 1:
        vs_mainMenu_setBladeUi(&vs_battle_inventory.blades[temp_s3], menuText, &rowType,
            vs_battle_stringBuf);
        break;
    case 2:
        vs_mainMenu_setGripUi(
            &vs_battle_inventory.grips[temp_s3], menuText, &rowType, vs_battle_stringBuf);
        break;
    case 3:
        vs_mainMenu_initUiShield(&vs_battle_inventory.shields[temp_s3], menuText,
            &rowType, vs_battle_stringBuf);
        break;
    case 4:
        vs_mainMenu_setAccessoryUi(
            &vs_battle_inventory.armor[temp_s3], menuText, &rowType, vs_battle_stringBuf);
        break;
    case 5:
        vs_mainMenu_setGemUi(
            &vs_battle_inventory.gems[temp_s3], menuText, &rowType, vs_battle_stringBuf);
        break;
    case 6:
        vs_mainMenu_setItemUi(
            &vs_battle_inventory.misc[temp_s3], menuText, &rowType, vs_battle_stringBuf);
        break;
    }
    vs_mainmenu_setInformationMessage(menuText[1]);
    vs_battle_memcpy(&vs_battle_inventory, D_8010A6AC, sizeof vs_battle_inventory);
}

int func_801090A4(int arg0)
{
    static char D_8010A5E8 = 0;

    static char D_8010A691;
    static char D_8010A692;
    static char _ __attribute__((unused));
    static char* D_8010A694;

    int i;
    int var_v1;
    int temp_a1;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        D_8010A692 = 1;
        D_8010A691 = 0;
        if (D_8010A6B6 == 0) {
            D_8010A691 = 4;
            return 0;
        }
        if ((D_8010A6B8 == 0) && (D_800EB9C8 != NULL)) {
            D_8010A691 = 5;
            return 0;
        }

        for (i = 0; i < D_8010A6B6; ++i) {
            temp_a1 = D_8010A6A0[i].unk0;
            if (temp_a1 == 6) {
                if (_inventory->misc[D_8010A6A0[i].unk1].id >= 0x1CA) {
                    D_8010A694 =
                        vs_mainMenu_itemNames[_inventory->misc[D_8010A6A0[i].unk1].id];
                    D_8010A691 = temp_a1;
                }
            }
        }
        return 0;
    }
    switch (D_8010A691) {
    case 0:
        menuItem = vs_battle_setMenuItem(
            0x1E, 0x140, 0x92, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionYes]);
        menuItem->state = 2;
        menuItem->targetX = 0xC2;
        D_8010A691 = 1;
        break;
    case 1:
        menuItem = vs_battle_setMenuItem(
            0x1F, 0x140, 0xA2, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionNo]);
        menuItem->state = 2;
        menuItem->targetX = 0xC2;
        func_800C8E04(1);
        vs_mainmenu_setInformationMessage(
            D_8010A6B8 == 0 ? (char*)(&_menuText[VS_menuText_OFFSET_discardAllConfirm])
                            : (char*)(&_menuText[VS_menuText_OFFSET_itemsRemaining]));
        D_8010A691 = 2;
        break;
    case 2:
        D_8010A691 = (D_8010A691 + vs_mainmenu_ready());
        break;
    case 3:
        vs_battle_getMenuItem(D_8010A692 + 0x1E)->selected = 1;
        vs_battle_getMenuItem(0x1F - D_8010A692)->selected = 0;
        if (vs_main_buttonsPressed.all & 0x60) {
            vs_mainMenu_menuItemLeaveRight(0x1E);
            vs_mainMenu_menuItemLeaveRight(0x1F);
            if (vs_main_settings.information == 0) {
                func_800FFBA8();
            }
            if ((D_8010A692 == 0) && !(vs_main_buttonsPressed.all & 0x40)) {
                vs_main_playSfxDefault(0x7E, 0x1C);
                var_v1 = 1;
                if (D_8010A6B8 == 0) {
                    var_v1 = 2;
                }
                return var_v1;
            }
            vs_battle_playMenuLeaveSfx();
            return -1;
        }
        if (vs_main_buttonRepeat & 0x5000) {
            vs_battle_playMenuChangeSfx();
            D_8010A692 = (1 - D_8010A692);
        }
        D_8010A5E8 = vs_battle_drawCursor(D_8010A5E8, D_8010A692 + 8);
        break;
    case 4:
    case 5:
        return D_8010A691 - 3;
    case 6:
        vs_battle_stringContext.strings[0] = D_8010A694;
        func_800C8E04(1);
        vs_mainmenu_setInformationMessage(
            (char*)&_menuText[VS_menuText_OFFSET_invalidDiscard]);
        D_8010A691 = 7;
        /* fallthrough */
    case 7:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            vs_battle_playMenuLeaveSfx();
            return -1;
        }
        break;
    }
    return 0;
}

int func_80109444(D_8010A6A0_t* arg0)
{
    static char D_8010A5E9 = 0;

    static char D_8010A698;
    static char D_8010A699;
    static char D_8010A69A;
    static char D_8010A69B;

    vs_battle_menuItem_t* temp_v0;

    if (arg0 != NULL) {
        func_800FFBC8();
        D_8010A699 = arg0->unk0;
        D_8010A698 = 0;
        D_8010A69A = 0;
        D_8010A69B = 0;

        if (D_8010A699 == 0) {
            D_8010A69B = VS_menuText_INDEX_disassemble - 9;
        } else if (D_8010A699 == 3) {
            D_8010A69B = VS_menuText_INDEX_disassemble - 9;
        } else if ((D_8010A699 == 6) && (_inventory->misc[arg0->unk1].id < 0x1CA)) {
            D_8010A69B = VS_menuText_INDEX_organize - 10;
        } else {
            D_8010A69A = VS_menuText_INDEX_disassemble - 9;
        }

        if (D_8010A69B != 0) {
            temp_v0 = vs_battle_setMenuItem(0x1E, 0x140, 0x92, 0x7E, 0,
                (char*)&_menuText[_menuText[(D_8010A69B + 4) * 2]]);
            temp_v0->state = 2;
            temp_v0->targetX = 0xC2;
        }
        return 0;
    }

    switch (D_8010A698) {
    case 0:
        temp_v0 = vs_battle_setMenuItem(0x1F, 0x140, 0xA2, 0x7E, 0,
            (char*)&_menuText[VS_menuText_OFFSET_organizeInventory]);
        temp_v0->state = 2;
        temp_v0->targetX = 0xC2;
        D_8010A698 = 1;
        break;
    case 1:
        D_8010A698 += vs_mainmenu_ready();
        break;
    case 2:
        vs_battle_getMenuItem(D_8010A69A + 0x1E)->selected = 1;
        vs_battle_getMenuItem(0x1F - D_8010A69A)->selected = 0;
        if (vs_main_buttonsPressed.all & 0x60) {
            vs_mainMenu_menuItemLeaveRight(0x1E);
            vs_mainMenu_menuItemLeaveRight(0x1F);
            if (vs_main_buttonsPressed.all & 0x40) {
                vs_battle_playMenuLeaveSfx();
                return -1;
            }
            vs_battle_playMenuSelectSfx();
            if (D_8010A69A == 0) {
                D_8010A69A = D_8010A69B + 1;
            }
            return D_8010A69A;
        }
        if (D_8010A69B != 0) {
            if (vs_main_buttonRepeat & 0x5000) {
                vs_battle_playMenuChangeSfx();
                D_8010A69A = 1 - D_8010A69A;
            }
        }
        if (D_8010A69A != 0) {
            vs_mainmenu_setInformationMessage(
                (char*)&_menuText[VS_menuText_OFFSET_organizeInventoryInfo]);
        } else if (D_8010A69B == 1) {
            vs_mainmenu_setInformationMessage(
                (char*)&_menuText[VS_menuText_OFFSET_disassembleInfo]);
        } else {
            vs_mainmenu_setInformationMessage(
                (char*)&_menuText[VS_menuText_OFFSET_organizeInfo]);
        }
        D_8010A5E9 = vs_battle_drawCursor(D_8010A5E9, D_8010A69A + 8);
        break;
    }
    return 0;
}

void func_8010A24C(int arg0);

int func_80109750(int arg0)
{
    static char D_8010A5EA = 0;

    static char D_8010A69C;
    static char D_8010A69D;

    D_8010A6A0_t* temp_s1;
    int temp_a3;
    int temp_s2;
    int i;
    int var_v0_4;
    int temp_a0;

    if (arg0 != 0) {
        D_8010A6B4 = 0;
        D_8010A69C = 0;
        return 0;
    }
    switch (D_8010A69C) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_800FFBC8();
        D_8010A69C = 1;
        // Fallthrough
    case 1:
        D_8010A505 = 1;
        if (vs_main_buttonsPressed.all & 0x40) {
            vs_battle_playMenuLeaveSfx();
            D_8010A505 = 0;
            func_801090A4(1);
            D_8010A69C = 2;
            break;
        } else if (vs_main_buttonsPressed.all & 0x80) {
            temp_s2 = D_8010A6B8;
            for (i = 0; i < D_8010A6B6; ++i) {
                temp_s1 = &D_8010A6A0[i];
                if (func_800FEB94(temp_s1->unk0 | 0x10, &vs_battle_inventory,
                        temp_s1->unk1, _inventory)
                    != 0) {
                    if (temp_s1->unk0 == 6) {
                        temp_a0 = _inventory->misc[temp_s1->unk1].id;
                        if (temp_a0 >= 0x1CA) {
                            func_8010A24C(temp_a0);
                        }
                    }
                    temp_s1->unk2 = 1;
                    ++D_8010A6B8;
                }
            }
            if (temp_s2 != D_8010A6B8) {
                vs_main_playSfxDefault(0x7E, 0xD);
                D_8010A69C = 9;
                break;
            }
            vs_battle_playInvalidSfx();
        }
        temp_a3 = D_8010A6B4 + D_8010A6B5;
        temp_s1 = &D_8010A6A0[temp_a3];
        if (vs_main_buttonsPressed.all & 0x20) {
            if (temp_s1->unk3 == 0) {
                vs_battle_playMenuSelectSfx();
                D_8010A505 = 0;
                func_80109444(temp_s1);
                D_8010A69C = 3;
            } else {
                vs_main_playSfxDefault(0x7E, 0xD);
                if (temp_s1->unk0 == 6) {
                    i = _inventory->misc[temp_s1->unk1].id;
                    if (i >= 0x1CA) {
                        func_8010A24C(i);
                    }
                }
                func_800FEB94(temp_s1->unk0 | 0x10, &vs_battle_inventory, temp_s1->unk1,
                    _inventory);
                temp_s1->unk2 = 1;
                D_8010A69D = 3;
                ++D_8010A6B8;
                D_8010A69C = 9;
            }
        } else {
            i = temp_a3;
            if (vs_main_buttonRepeat & 0x1000) {
                if (D_8010A6B6 < 9) {
                    if (D_8010A6B4 == 0) {
                        D_8010A6B4 = D_8010A6B6 - 1;
                    } else {
                        --D_8010A6B4;
                    }
                } else {
                    if (D_8010A6B5 == 0) {
                        if (D_8010A6B4 == 0) {
                            if (vs_main_buttonsPressed.all & 0x1000) {
                                D_8010A6B4 = 7;
                                D_8010A6B5 = D_8010A6B6 - 8;
                            }
                        } else {
                            --D_8010A6B4;
                        }
                    } else {
                        if (D_8010A6B4 == 1) {
                            --D_8010A6B5;
                        } else {
                            --D_8010A6B4;
                        }
                    }
                }
            }
            if (vs_main_buttonRepeat & 0x4000) {
                if (D_8010A6B6 < 9) {
                    if (D_8010A6B4 == (D_8010A6B6 - 1)) {
                        D_8010A6B4 = 0;
                    } else {
                        ++D_8010A6B4;
                    }
                } else if (D_8010A6B5 == (D_8010A6B6 - 8)) {
                    if (D_8010A6B4 == 7) {
                        if (vs_main_buttonsPressed.all & 0x4000) {
                            D_8010A6B4 = 0;
                            D_8010A6B5 = 0;
                        }
                    } else {
                        ++D_8010A6B4;
                    }
                } else if (D_8010A6B4 == 6) {
                    ++D_8010A6B5;
                } else {
                    ++D_8010A6B4;
                }
            }
            if (i != (D_8010A6B4 + D_8010A6B5)) {
                vs_battle_playMenuChangeSfx();
            }
            func_80108E78(D_8010A6B4 + D_8010A6B5);
            D_8010A5EA =
                func_800FFCDC(D_8010A5EA, (((D_8010A6B4 * 0x10) + 0x2A) << 0x10) | 0xA);
        }
        break;
    case 2:
        i = func_801090A4(0);
        if (i != 0) {
            if (i < 0) {
                D_8010A69C = 8;
            } else {
                return i;
            }
        }
        break;
    case 3:
        i = func_80109444(NULL);
        if (i != 0) {
            if (i >= 0) {
                temp_s2 = D_8010A6B4 + D_8010A6B5;
                switch (i) {
                case 1:
                    func_801066CC(D_8010A6A0[temp_s2].unk0 + 1);
                    D_8010A69C = 4;
                    break;
                case 2:
                    func_80106B80(temp_s2 + 1);
                    D_8010A69C = 5;
                    break;
                case 3:
                    func_801073E0(temp_s2 + 1);
                    D_8010A69C = 6;
                    break;
                }
            } else {
                D_8010A69C = 0;
            }
        }
        break;
    case 4:
        var_v0_4 = func_801066CC(0);
        if (var_v0_4 != 0) {
            D_8010A69C = 8;
        }
        break;
    case 5:
        var_v0_4 = func_80106B80(0);
        if (var_v0_4 != 0) {
            D_8010A69C = 8;
        }
        break;
    case 6:
        var_v0_4 = func_801073E0(0);
        if (var_v0_4 != 0) {
            D_8010A69C = 8;
        }
        break;
    case 7:
        if (vs_main_buttonsPressed.all == 0) {
            break;
        }
    // Fallthrough
    case 8:
        if (D_8010A6B3 == 0) {
            D_8010A505 = 1;
            D_8010A69C = 0;
            func_801080F0();
        }
        break;
    case 9:
        if (D_8010A69D != 0) {
            D_8010A69D = (D_8010A69D - 1);
        } else {
            while (1) {
                for (i = 0; i < D_8010A6B6; ++i) {
                    if (D_8010A6A0[i].unk2 != 0) {
                        break;
                    }
                }

                if (i == D_8010A6B6) {
                    break;
                }

                --D_8010A6B6;
                for (; i < D_8010A6B6; ++i) {
                    D_8010A6A0[i] = D_8010A6A0[i + 1];
                }
            }
            func_801080F0();
            if (D_8010A6B6 == 0) {
                D_8010A505 = 0;
                func_801090A4(1);
                D_8010A69C = 2;
            } else {
                D_8010A69C = 0;
            }
        }
        break;
    }
    D_8010A6B7 = (D_8010A69C & 7) == 1 ? D_8010A6B4 + 1 : -0x80;
    return 0;
}

int func_80109E90(char* state)
{
    static char D_8010A69E;
    static char _ __attribute__((unused));

    int i;
    void* temp_v0;

    D_8010A6B7 = 0;

    switch (*state) {
    case 0:
        vs_battle_playSfx10();
        func_800FBD80(16);
        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }
        temp_v0 = vs_main_allocHeapR(0x2300);
        _inventory = temp_v0;
        D_8010A6AC = temp_v0 + 0xF00;
        D_8010A6A0 = temp_v0 + 0x1E00;
        D_8010A6A4 = temp_v0 + 0x2080;
        D_8010A6B8 = 0;
        D_8010A6B6 = 0;
        D_8010A6B5 = 0;
        D_8010A69E = 0;
        vs_mainMenu_loadItemNames(1);
        func_801088D4(D_800EB9C4);
        D_8010A505 = 0;
        D_8010A6B0 = 1;
        D_8010A6B1 = 10;
        D_8010A6B2 = 0;
        D_8010A6B3 = 10;
        *state = 1;
        break;
    case 1:
        if (vs_mainMenu_loadItemNames(0) != 0) {
            D_8010A6B2 = 1;
            if (D_8010A6B6 == 0) {
                func_800C8E04(1);
                vs_mainmenu_setInformationMessage(
                    (char*)&_menuText[VS_menuText_OFFSET_emptyChest]);
                *state = 4;
            } else {
                func_800FFBC8();
                *state = 2;
            }
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (D_8010A6B3 == 0) {
                func_80109750(1);
                *state = 3;
            case 3:
                i = func_80109750(0);
                if (i != 0) {
                    D_800F4E98.unk2 = i == 1;
                    *state = 5;
                }
            }
        }
        break;
    case 4:
        if ((D_800F5130 >> 0x1E) & 1) {
            if (vs_main_buttonsPressed.pad[0].low != 0) {
                *state = 5;
            }
        }
        break;
    case 5:
        D_8010A6B0 = 0;
        D_8010A6B2 = 0;
        if (func_800CD064(7) == 0) {
            if (vs_mainMenu_ensureItemNamesLoaded() != 0) {
                vs_main_freeHeapR(_inventory);
                if (D_800EB9C4 != 0) {
                    func_8008A6FC();
                }
                *state = 0;
                return 1;
            }
        }
        break;
    }
    if (D_8010A6B0 != 0) {
        if (D_8010A6B1 != 0) {
            --D_8010A6B1;
        }
        i = vs_battle_rowAnimationSteps[D_8010A6B1];
    } else {
        if (D_8010A6B1 < 10) {
            ++D_8010A6B1;
        }
        i = D_8010A6B1 << 5;
    }
    if (D_8010A6B1 < 10) {
        func_8010837C(i);
    }
    if (D_8010A6B2 != 0) {
        if (D_8010A6B3 != 0) {
            --D_8010A6B3;
        }
        i = vs_battle_rowAnimationSteps[D_8010A6B3];
    } else {
        if (D_8010A6B3 < 10) {
            ++D_8010A6B3;
        }
        i = D_8010A6B3 << 5;
    }
    if (D_8010A6B3 < 10) {
        func_80108938(i);
        if (D_8010A6B7 & 0xF) {
            vs_battle_getMenuItem(D_8010A6B7 + 0x1F)->selected = 1;
        }
    }
    return 0;
}

void func_8010A24C(int arg0)
{
    if (arg0 >= 0x1CA) {
        vs_battle_setStateFlag(arg0 + 0x1B6, 1);
    }
}
