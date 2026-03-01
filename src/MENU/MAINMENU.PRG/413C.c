#include "common.h"
#include "413C.h"
#include "C48.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../assets/MENU/ITEMHELP.BIN.h"
#include "lbas.h"
#include "gpu.h"
#include "vs_string.h"
#include <libetc.h>

extern u_long* D_1F800000[];

char* func_800FD93C(int arg0)
{
    char* menuText[2];
    int rowType;
    int gem;
    int weaponId;
    vs_battle_inventoryWeapon* weapon;

    menuText[1] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noGems];
    weaponId = D_801024A1;
    weapon = &D_80102470[weaponId - 1];

    switch (arg0) {
    case 0:
        vs_mainMenu_initUiWeapon(weapon, menuText, &rowType, vs_battle_stringBuf);
        break;
    case 1:
        vs_mainMenu_drawDpPpbars(0xB);
        vs_mainMenu_setBladeUi(
            &D_80102464[weapon->blade - 1], menuText, &rowType, vs_battle_stringBuf);
        vs_mainMenu_setUiBladeStats(weapon->blade);
        break;
    case 2:
        vs_mainMenu_drawDpPpbars(8);
        vs_mainMenu_setGripUi(
            &D_80102460[weapon->grip - 1], menuText, &rowType, vs_battle_stringBuf);
        vs_mainMenu_setUiGripStats(weapon->grip);
        break;
    case 3:
    case 4:
    case 5:
        vs_mainMenu_drawDpPpbars(8);
        gem = weapon->gems[arg0 - 3];
        if (gem != 0) {
            vs_mainMenu_setGemUi(
                &D_80102458[gem - 1], menuText, &rowType, vs_battle_stringBuf);
            func_800FD878(gem);
        } else {
            vs_mainMenu_resetStats();
        }
        break;
    }
    vs_mainMenu_equipmentSubtype = 1;
    D_801024A1 = weaponId;
    vs_battle_getMenuItem(arg0 + 0xA)->selected = 1;
    return menuText[1];
}

char* func_800FDB04(int arg0 __attribute__((unused)))
{
    char* menuText[2];
    int rowType;

    vs_mainMenu_setBladeUi(
        &D_80102464[D_801024A1 - 1], menuText, &rowType, vs_battle_stringBuf);
    return menuText[1];
}

char* func_800FDB60(int arg0 __attribute__((unused)))
{
    char* menuText[2];
    int rowType;

    vs_mainMenu_setGripUi(
        &D_80102460[D_801024A1 - 1], menuText, &rowType, vs_battle_stringBuf);
    return menuText[1];
}

char* func_800FDBAC(int arg0)
{
    char* menuText[2];
    int rowType;
    int gem;
    int temp_s2;
    vs_battle_inventoryShield* shield;

    menuText[1] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_noGems];
    shield = &D_8010246C[D_801024A1 - 1];
    temp_s2 = D_801024A1;

    if (arg0 == 0) {
        vs_mainMenu_initUiShield(shield, menuText, &rowType, vs_battle_stringBuf);
    } else if (arg0 >= 0) {
        if (arg0 < 4) {
            vs_mainMenu_drawDpPpbars(8);
            gem = shield->gems[arg0 - 1];
            if (gem != 0) {
                vs_mainMenu_setGemUi(
                    &D_80102458[gem - 1], menuText, &rowType, vs_battle_stringBuf);
                func_800FD878(gem);
            } else {
                vs_mainMenu_resetStats();
            }
        }
    }
    vs_mainMenu_equipmentSubtype = 8;
    D_801024A1 = temp_s2;
    vs_battle_getMenuItem(arg0 + 10)->selected = 1;
    return menuText[1];
}

char* func_800FDCD0(int arg0 __attribute__((unused)))
{
    char* menuText[2];
    int rowType;

    vs_mainMenu_setAccessoryUi(
        &D_80102468[D_801024A1 - 1], menuText, &rowType, vs_battle_stringBuf);
    return menuText[1];
}

char* func_800FDD24(int arg0 __attribute__((unused)))
{
    char* menuText[2];
    int rowType;

    vs_mainMenu_setGemUi(
        &D_80102458[D_801024A1 - 1], menuText, &rowType, vs_battle_stringBuf);
    return menuText[1];
}

void func_800FDD78(void) { D_801024B8 = 9; }

/* This doesn't seem to be used for anything useful so it could be a bug in
 the original data definition and therefore correct to leave
 as extern and undefined here. Defining it causes aliasing issues when subalign = 4 */
extern char D_8010214A;

int func_800FDD88(int arg0)
{
    int var_a0 = 0;
    int subType = vs_mainMenu_equipmentSubtype;

    switch (arg0) {
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
        var_a0 = D_801024B9 != 2;
        break;
    case 8:
        var_a0 = D_801024B9 == 1;
        break;
    case 9:
        var_a0 = 1;
        // Fallthrough
    case 10:
    case 11:
    case 12:
        if ((subType & 8) && (D_801024A1 != 0)) {
            var_a0 = (arg0 - 10) < D_8010246C[D_801024A1 - 1].base.gemSlots;
            break;
        }
        // Fallthrough
    case 13:
    case 14:
        if ((subType & 1) && (D_801024A1 != 0)) {
            var_a0 =
                (arg0 - 12) < D_80102460[D_80102470[D_801024A1 - 1].grip - 1].gemSlots;
        }
        break;
    case 15:
        var_a0 = D_8010214A;
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
char vs_mainMenu_equipmentDetailNavigationMap[][4] = { { 0, 2, 1, 10 }, { 1, 2, 1, 0 },
    { 1, 3, 2, 11 }, { 2, 4, 3, 12 }, { 3, 5, 4, 13 }, { 4, 6, 5, 14 }, { 5, 7, 6, 16 },
    { 6, 8, 7, 17 }, { 7, 8, 8, 18 }, { 9, 10, 0, 9 }, { 9, 11, 0, 10 },
    { 10, 12, 2, 11 }, { 11, 13, 3, 12 }, { 12, 14, 4, 13 }, { 13, 15, 5, 14 },
    { 14, 16, 5, 15 }, { 15, 17, 6, 16 }, { 16, 18, 7, 17 }, { 17, 19, 8, 18 },
    { 18, 20, 8, 19 }, { 19, 20, 8, 20 } };

static int D_801021A0[] = { vs_getXY(66, 28), vs_getXY(-4, 28), vs_getXY(0, 50),
    vs_getXY(0, 66), vs_getXY(0, 82), vs_getXY(0, 98), vs_getXY(0, 114), vs_getXY(0, 130),
    vs_getXY(0, 146) };

static int vs_mainMenu_mainCursorXY[] = { vs_getXY(141, 10), vs_getXY(148, 26),
    vs_getXY(148, 42), vs_getXY(155, 58), vs_getXY(155, 74), vs_getXY(155, 90),
    vs_getXY(180, 24), vs_getXY(192, 126), vs_getXY(192, 136), vs_getXY(152, 146),
    vs_getXY(152, 156), vs_getXY(152, 166) };

static char* (*D_801021F4[])(int) = { func_800FD93C, func_800FDB04, func_800FDB60,
    func_800FDBAC, func_800FDCD0, func_800FDCD0, func_800FDD24 };

static char D_80102210 = 0;
static char D_80102211 = 0;
char D_80102214[] = { 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xF3, 0xF4, 0xF5,
    0xF6, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEF, 0xEE, 0xF0, 0xF2, 0xF7, 0xF8, 0xF9,
    0xFA, 0xFB, 0xFC, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xF1, 0x00, 0xFE, 0xFD, 0xFB, 0xF4,
    0xFE, 0xFB, 0xF6, 0xF3, 0xF3, 0xFC, 0xFD, 0xFF, 0xFB, 0xF5, 0xFE, 0xFD, 0xFF, 0xFD,
    0xFD, 0xFF, 0xFD, 0xFE, 0xFE, 0xFF, 0xFE, 0xFC, 0xFF, 0xFD, 0x61, 0x62, 0x63, 0x64,
    0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x00, 0x00, 0x00, 0x6E, 0x00, 0x00, 0x00, 0x72,
    0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x7A, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00,
    0x00, 0x82, 0x00, 0x00, 0x00, 0x5E, 0x5F, 0x60, 0x57, 0x58, 0x5A, 0x5B, 0x4D, 0x3C,
    0x36, 0x3D, 0x37, 0x3E, 0x38, 0x3F, 0x39, 0x4B, 0x4C, 0x52, 0x53, 0x55, 0x4F, 0x50,
    0x5C, 0x5D, 0x3A, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x00, 0x00 };

void func_800FDEBC(void)
{
    int i;
    int var_s3;
    char* var_s4;
    u_int var_s2;

    var_s2 = D_801024B8;
    var_s3 = 0;
    i = var_s2;

    if (vs_main_buttonRepeat & PADLup) {
        var_s3 = 1;
    } else if (vs_main_buttonRepeat & PADLdown) {
        var_s3 = 2;
    } else if (vs_main_buttonRepeat & PADLleft) {
        var_s3 = 3;
    } else if (vs_main_buttonRepeat & PADLright) {
        var_s3 = 4;
    }

    if (var_s3 != 0) {
        D_801024B8 = vs_mainMenu_equipmentDetailNavigationMap[var_s2][var_s3 - 1];
    }

    while (func_800FDD88(D_801024B8) == 0) {
        if (var_s2 == D_801024B8) {
            if ((var_s2 - 2) < 0xE) {
                do {
                    --D_801024B8;
                } while (func_800FDD88(D_801024B8) == 0);
            } else {
                do {
                    ++D_801024B8;
                } while (func_800FDD88(D_801024B8) == 0);
            }
            break;
        } else {
            var_s2 = D_801024B8;
            D_801024B8 = vs_mainMenu_equipmentDetailNavigationMap[var_s2][var_s3 - 1];
        }
    }
    if (D_80102211 == D_801024A1) {
        if (i != D_801024B8) {
            vs_battle_playMenuChangeSfx();
        }
    } else {
        D_80102211 = D_801024A1;
    }
    for (i = 11; i < 16; ++i) {
        vs_battle_getMenuItem(i)->selected = 0;
    }
    if (vs_mainMenu_equipmentSubtype & 1) {
        vs_mainMenu_drawDpPpbars(0xB);
        vs_mainMenu_setUiWeaponStats((int)D_801024A1);
    }
    if (vs_mainMenu_equipmentSubtype & 8) {
        vs_mainMenu_drawDpPpbars(0xB);
        func_800FD5A0((int)D_801024A1);
    }
    if (vs_mainMenu_equipmentSubtype & 0x10) {
        vs_mainMenu_drawDpPpbars(9);
    }
    if (vs_mainMenu_equipmentSubtype & 0x20) {
        vs_mainMenu_drawDpPpbars(8);
    }
    if (D_801024B8 < 2) {
        var_s4 = (char*)&vs_mainMenu_itemHelp
            [vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_INDEX_phantomPointsDesc - D_801024B8]];
    } else if (D_801024B8 < 9) {
        switch (D_801024B9) {
        case 0:
            var_s4 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                    [D_801024B8 + VS_ITEMHELP_BIN_INDEX_damagePointsDesc]];
            break;
        case 1:
            var_s4 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                    [D_801024B8 + VS_ITEMHELP_BIN_INDEX_dragonClassDesc]];
            break;
        case 2:
            var_s4 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                    [D_801024B8 + VS_ITEMHELP_BIN_INDEX_lightAffinityDesc]];
            break;
        }
    } else {

        if (D_801024B8 < 0xF) {
            for (i = 0; i < 7; ++i) {
                if ((vs_mainMenu_equipmentSubtype >> i) & 1) {
                    var_s4 = D_801021F4[i](D_801024B8 - 9);
                }
            }
        } else if (D_801024B8 == 0xF) {
            var_s4 = (char*)(vs_mainMenu_itemHelp + VS_ITEMHELP_BIN_OFFSET_line657);
        } else {
            var_s4 = (char*)&vs_mainMenu_itemHelp
                [vs_mainMenu_itemHelp[D_801024B8 + VS_ITEMHELP_BIN_INDEX_humanClassDesc]];
            if (D_801024B8 >= 0x12) {
                if (vs_mainMenu_equipmentSubtype & 7) {
                    var_s4 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                            [D_801024B8 + VS_ITEMHELP_BIN_INDEX_line640]];
                }
                if (vs_mainMenu_equipmentSubtype & 0x18) {
                    var_s4 = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                            [D_801024B8 + VS_ITEMHELP_BIN_INDEX_polearmGrip]];
                }
            }
        }
    }
    vs_mainmenu_setMessage(var_s4);
    i = D_801021A0[D_801024B8];
    if (D_801024B8 == 0xF) {
        i += D_8010214A << 0x14;
    }
    if (vs_mainMenu_equipmentSubtype & 8) {
        if ((D_801024B8 - 10) < 2U) {
            i += 7;
        }
    }
    D_80102210 = func_800FFCDC(D_80102210, i);
    D_8010214A = 0;
}

void vs_mainMenu_unequipAllWeapons(void)
{
    int i;

    vs_battle_equipWeapon(NULL);

    for (i = 0; i < 8; ++i) {
        vs_battle_inventory.weapons[i].isEquipped = 0;
    }
}

void vs_mainMenu_unequipShield(void)
{
    int i;

    vs_battle_equipShield(NULL);

    for (i = 0; i < 8; ++i) {
        vs_battle_inventory.shields[i].isEquipped = 0;
    }
}

void vs_mainMenu_initItem(int arg0, int arg1)
{
    int i;

    switch (arg0) {
    case 0: {
        vs_battle_inventoryWeapon* weapon = &vs_battle_inventory.weapons[arg1 - 1];

        vs_mainMenu_initItem(1, weapon->blade);
        vs_mainMenu_initItem(2, weapon->grip);

        for (i = 0; i < 3; ++i) {
            int gem = weapon->gems[i];
            if (gem != 0) {
                vs_mainMenu_initItem(5, gem);
            }
        }

        vs_battle_rMemzero(weapon, sizeof *weapon);
        weapon->index = arg1;
        break;
    }
    case 1: {
        vs_battle_inventoryBlade* blade = &vs_battle_inventory.blades[arg1 - 1];
        vs_battle_rMemzero(blade, sizeof *blade);
        blade->index = arg1;
        break;
    }
    case 2: {
        vs_battle_inventoryGrip* grip = &vs_battle_inventory.grips[arg1 - 1];
        vs_battle_rMemzero(grip, sizeof *grip);
        grip->index = arg1;
        break;
    }
    case 3: {
        vs_battle_inventoryShield* shield = &vs_battle_inventory.shields[arg1 - 1];
        for (i = 0; i < 3; ++i) {
            int gem = shield->gems[i];
            if (gem != 0) {
                vs_mainMenu_initItem(5, gem);
            }
        }
        vs_battle_rMemzero(shield, sizeof *shield);
        shield->index = arg1;
        break;
    }
    case 4: {
        vs_battle_inventoryArmor* armor = &vs_battle_inventory.armor[arg1 - 1];
        vs_battle_rMemzero(armor, sizeof *armor);
        armor->index = arg1;
        break;
    }
    case 5: {
        vs_battle_inventoryGem* gem = &vs_battle_inventory.gems[arg1 - 1];
        vs_battle_rMemzero(gem, sizeof *gem);
        gem->index = arg1;
        break;
    }
    case 6: {
        vs_battle_inventoryMisc* misc = &vs_battle_inventory.items[arg1 - 1];
        vs_battle_rMemzero(misc, sizeof *misc);
        misc->index = arg1;
        break;
    }
    }
}

extern vs_main_CdQueueSlot* _itemNamesCdQueueSlot;
extern char _itemNamesLoading;

char (*vs_mainMenu_itemNames)[24] = NULL;

int vs_mainMenu_loadItemNames(int arg0)
{
    vs_main_CdFile cdFile;

    if (arg0 != 0) {
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

int vs_mainMenu_ensureItemNamesLoaded(void)
{
    if (vs_mainMenu_itemNames == NULL) {
        return 1;
    }
    if (vs_mainMenu_loadItemNames(0) != 0) {
        vs_main_freeHeapR(vs_mainMenu_itemNames);
        vs_mainMenu_itemNames = NULL;
        return 1;
    }
    return 0;
}

static int _getItemId(int category, int index, vs_battle_inventory_t* inventory)
{
    int id = 0;

    if (inventory == NULL) {
        inventory = &vs_battle_inventory;
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
        id = inventory->items[index].id;
        break;
    }
    return id;
}

char vs_mainMenu_inventoryItemCapacities[] = { 8, 16, 16, 8, 16, 48, 64, 2 };

char* vs_mainMenu_inventoryIndices[] = { D_800619D8.unk0, D_800619D8.unk8,
    D_800619D8.unk18, D_800619D8.unk28, D_800619D8.unk30, D_800619D8.unk40,
    D_800619D8.unk70 };

int vs_mainMenu_findItem(int category, int id)
{
    int i;

    char* index = vs_mainMenu_inventoryIndices[category];
    char capacity = vs_mainMenu_inventoryItemCapacities[category];

    for (i = 0; i < capacity; ++i) {
        if (index[i] == (id + 1)) {
            return i + 1;
        }
    }
    return 0;
}

static void _setItemIndex(int itemCategory, int id)
{
    int i;
    char* index = vs_mainMenu_inventoryIndices[itemCategory];

    for (i = 0; i < vs_mainMenu_inventoryItemCapacities[itemCategory]; ++i) {
        if (index[i] == 0) {
            index[i] = id + 1;
            return;
        }
    }
}

void vs_mainMenu_rebuildInventory(int category)
{
    int i;
    char* indices = vs_mainMenu_inventoryIndices[category];
    int capacity = vs_mainMenu_inventoryItemCapacities[category];

    for (i = 0; i < capacity; ++i) {
        int index = indices[i];
        if ((index != 0) && (_getItemId(category, index - 1, NULL) == 0)) {
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
        if ((_getItemId(category, i, NULL) != 0)
            && (vs_mainMenu_findItem(category, i) == 0)) {
            _setItemIndex(category, i);
        }
    }
}

int vs_mainMenu_getItemCount(int category, vs_battle_inventory_t* inventory)
{
    int i;
    int count = 0;

    for (i = 0; i < vs_mainMenu_inventoryItemCapacities[category]; ++i) {
        if (_getItemId(category, i, inventory) != 0) {
            count += 1;
        }
    }
    return count;
}

int vs_mainMenu_getFirstItem(int itemCategory, vs_battle_inventory_t* inventory)
{
    int i;

    for (i = 0; i < vs_mainMenu_inventoryItemCapacities[itemCategory]; ++i) {
        if (_getItemId(itemCategory, i, inventory) == 0) {
            break;
        }
    }
    return i;
}

int func_800FEB94(
    int arg0, vs_battle_inventory_t* arg1, int arg2, vs_battle_inventory_t* arg3)
{
    vs_battle_inventoryMisc* temp_a0;
    int temp_fp;
    int temp_s2;
    int temp_s3;
    int temp_s7;
    int i;
    int var_s1;
    int var_s5;
    int var_s1_3;

    temp_s3 = arg0 >> 8;
    temp_fp = (arg0 >> 4) & 1;
    arg0 = arg0 & 0xF;
    var_s5 = 0;
    temp_s7 = vs_mainMenu_getItemCount(arg0, arg1);
    temp_s2 = vs_mainMenu_getFirstItem(arg0, arg1);

    switch (arg0) {
    case 0: {
        vs_battle_inventoryWeapon* temp_s4 = &arg3->weapons[arg2];
        vs_battle_inventoryWeapon* temp_s3_2 = &arg1->weapons[temp_s2];

        if ((temp_s7 != 8) && (vs_mainMenu_getItemCount(1, arg1) != 0x10)) {
            if (vs_mainMenu_getItemCount(2, arg1) != 0x10) {
                var_s1 = 0;
                for (i = 0; i < 3; ++i) {
                    if (temp_s4->gems[i] != 0) {
                        ++var_s1;
                    }
                }

                if ((vs_mainMenu_getItemCount(5, arg1) + var_s1) < 0x31) {
                    var_s5 = temp_s2 + 1;
                    if (temp_fp != 0) {
                        vs_battle_rMemzero(temp_s3_2, 0x20);
                        temp_s3_2->index = var_s5;
                        temp_s3_2->blade = func_800FEB94(
                            (var_s5 << 8) | 0x11, arg1, temp_s4->blade - 1, arg3);
                        temp_s3_2->grip = func_800FEB94(
                            (var_s5 << 8) | 0x12, arg1, temp_s4->grip - 1, arg3);

                        for (i = 0; i < 3; ++i) {
                            if (temp_s4->gems[i] != 0) {
                                temp_s3_2->gems[i] = func_800FEB94((var_s5 << 8) | 0x15,
                                    arg1, temp_s4->gems[i] - 1, arg3);
                            }
                        }
                        vs_battle_rMemcpy(temp_s3_2->name, temp_s4->name, 0x18);
                    }
                }
            }
        }
        break;
    }
    case 1: {
        vs_battle_inventoryBlade* source = &arg3->blades[arg2];
        vs_battle_inventoryBlade* target = &arg1->blades[temp_s2];
        if (temp_s7 != 0x10) {
            var_s5 = temp_s2 + 1;
            if (temp_fp != 0) {
                vs_battle_copyAligned(target, source, sizeof *target);
                target->index = var_s5;
                target->assembledWeaponIndex = temp_s3;
            }
        }
        break;
    }
    case 2: {
        vs_battle_inventoryGrip* source = &arg3->grips[arg2];
        vs_battle_inventoryGrip* target = &arg1->grips[temp_s2];
        if (temp_s7 != 0x10) {
            var_s5 = temp_s2 + 1;
            if (temp_fp != 0) {
                vs_battle_copyAligned(target, source, sizeof *target);
                target->index = var_s5;
                target->assembledWeaponIndex = temp_s3;
            }
        }
        break;
    }
    case 3: {
        vs_battle_inventoryShield* target = &arg3->shields[arg2];
        vs_battle_inventoryShield* source = &arg1->shields[temp_s2];
        if (temp_s7 != 8) {
            var_s1 = 0;
            for (i = 0; i < 3; ++i) {
                if (target->gems[i] != 0) {
                    ++var_s1;
                }
            }
            if ((vs_mainMenu_getItemCount(5, arg1) + var_s1) < 49) {
                var_s5 = temp_s2 + 1;
                if (temp_fp != 0) {
                    vs_battle_rMemzero(source, 0x30);
                    vs_battle_copyAligned(
                        &source->base, &target->base, sizeof source->base);
                    source->index = var_s5;
                    for (i = 0; i < 3; ++i) {
                        if (target->gems[i] != 0) {
                            source->gems[i] = func_800FEB94(((var_s5 | 0x80) << 8) | 0x15,
                                arg1, target->gems[i] - 1, arg3);
                        }
                    }
                }
            }
        }
        break;
    }
    case 4: {
        vs_battle_inventoryArmor* source = &arg3->armor[arg2];
        vs_battle_inventoryArmor* target = &arg1->armor[temp_s2];
        if (temp_s7 != 16) {
            var_s5 = temp_s2 + 1;
            if (temp_fp != 0) {
                vs_battle_copyAligned(target, source, sizeof *target);
                target->index = var_s5;
            }
        }
        break;
    }
    case 5: {
        vs_battle_inventoryGem* source = &arg3->gems[arg2];
        vs_battle_inventoryGem* target = &arg1->gems[temp_s2];
        if (temp_s7 != 0x30) {
            var_s5 = temp_s2 + 1;
            if (temp_fp != 0) {
                vs_battle_copyAligned(target, source, sizeof *target);
                target->index = var_s5;
                target->setItemIndex = temp_s3;
            }
        }
        break;
    }
    case 6: {
        vs_battle_inventoryMisc* source = &arg3->items[arg2];
        vs_battle_inventoryMisc* target = arg1->items;
        var_s1_3 = source->count;
        vs_mainMenu_rebuildInventory(6);

        for (i = 0; i < 0x40; ++i) {
            int slot = D_800619D8.unk70[i];
            if (slot == 0) {
                continue;
            }
            temp_a0 = &target[slot - 1];

            if (temp_a0->id != source->id)
                continue;

            if (temp_fp != 0) {
                int space_left = 100 - temp_a0->count;
                if (space_left >= var_s1_3) {
                    temp_a0->count += var_s1_3;
                    var_s1_3 = 0;
                } else {
                    var_s1_3 = var_s1_3 + (temp_a0->count - 100);
                    temp_a0->count = 100;
                }
            } else {
                var_s1_3 = var_s1_3 - (100 - temp_a0->count);
                if (var_s1_3 < 0) {
                    var_s1_3 = 0;
                }
            }
        }

        if (var_s1_3 == 0) {
            var_s5 = 1;
            break;
        }

        if (temp_s7 != 0x40) {
            var_s5 = temp_s2 + 1;
            if (temp_fp != 0) {
                target[temp_s2].id = source->id;
                target[temp_s2].count = var_s1_3;
            }
        }
        break;
    }
    }
    return var_s5;
}
