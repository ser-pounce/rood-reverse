#include "common.h"
#include "413C.h"
#include "C48.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../assets/MENU/ITEMHELP.BIN.h"
#include "lbas.h"
#include "gpu.h"
#include <libetc.h>

typedef struct {
    char text[14];
    char unk14;
    char x;
} textHeader_t;

extern char vs_mainMenu_isLevelledSpell;
extern int (*D_801022C8)[32];
extern int D_801022CC;
extern char D_801022D2;
extern char D_801022DC;
extern short D_801022DE;
extern short D_801022E0;
extern char D_801022E2;
extern char D_801022E3;
extern int D_801022E4;
extern u_short D_801022E8[];
extern int D_801022F8[];
extern char D_8010231A[];
extern u_short D_8010237C[];
extern u_short* D_801023D4;
extern char D_801023DC;
extern char D_801023DD;
extern char D_801023DF;
extern char D_801023DE;
extern short D_801023E0;
extern int _selectedRow;
extern char D_801023E4;
extern char* D_801023E8[];
extern int D_801023F8[];
extern char D_801024A0;
extern vs_main_CdQueueSlot* _itemNamesCdQueueSlot;
extern char _itemNamesLoading;
extern textHeader_t _textHeaders[];
extern u_long* D_1F800000[];

char* func_800FD93C(u_int arg0)
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

char* func_800FDB04(void)
{
    char* menuText[2];
    int rowType;

    vs_mainMenu_setBladeUi(
        &D_80102464[D_801024A1 - 1], menuText, &rowType, vs_battle_stringBuf);
    return menuText[1];
}

char* func_800FDB60(void)
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

char* func_800FDCD0(void)
{
    char* menuText[2];
    int rowType;

    vs_mainMenu_setAccessoryUi(
        &D_80102468[D_801024A1 - 1], menuText, &rowType, vs_battle_stringBuf);
    return menuText[1];
}

char* func_800FDD24(void)
{
    char* menuText[2];
    int rowType;

    vs_mainMenu_setGemUi(
        &D_80102458[D_801024A1 - 1], menuText, &rowType, vs_battle_stringBuf);
    return menuText[1];
}

void func_800FDD78(void) { D_801024B8 = 9; }

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

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDEBC);

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

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE3E0);

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

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FEB94);

void func_800FF0EC(int, int, char**, int*);
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF0EC);

int func_800FF348(void) { return D_801022CC + D_801022D2; }

int func_800FF360(void) { return D_801022C8 == NULL ? D_801022CC : -1; }

vs_battle_menuItem_t* func_800FF388(int arg0, int arg1)
{
    vs_battle_menuItem_t* temp_v0 =
        vs_battle_setMenuItem(arg0 + 0x20, arg1, ((arg0 + D_801024A0) * 0x10) + 0x12,
            0x7E, 0, (char*)D_801022C8[D_801022D2 + arg0]);
    int v;
    v = D_801022C8[D_801022D2 + arg0][7];
    temp_v0->unk7 = v & 1;
    if ((arg0 == 0) && (D_801022D2 != 0)) {
        temp_v0->unk5 = 1;
    }
    return temp_v0;
}

void func_800FF43C(void);
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF43C);

void vs_mainMenu_printInformation(int arg0, int arg1)
{
    if (arg1 >= 16) {
        if (vs_battle_rowTypeBuf[arg0] & 1) {
            if ((vs_main_settings.information == 0)
                && (vs_main_buttonsState & (PADLup | PADLdown))) {
                return;
            }
            func_800C8E04(1);
            D_800F514C = 0xB;
        } else if (vs_main_settings.information != 0) {
            func_800C8E04(2);
            D_800F514C = 0xB;
        } else {
            D_800F514C = 0;
        }
    }
}

void func_800FFA88(int arg0) { D_801022E3 = arg0; }

void func_800FFA94(void)
{
    int var_a1;
    u_long* temp_v0;
    int temp_s0;

    temp_s0 = D_801022E2;
    var_a1 = D_801022E4;
    if (temp_s0 != D_801022E3) {
        if (var_a1 == 0) {
            D_801022E2 = D_801022E3;
            return;
        }
        var_a1 -= 2;
    } else if (var_a1 < 0xC) {
        var_a1 += 2;
    }
    D_801022E4 = var_a1;
    if (temp_s0 != 0) {
        temp_v0 = vs_battle_setSprite(0x180,
            (0x138 - (D_801022F8[temp_s0] & 0xFF)) | ((D_801022E4 - 4) << 16),
            D_801022F8[temp_s0], D_1F800000[2]);
        temp_v0[1] = 0xE100002C;
        temp_v0[4] = D_801022E8[temp_s0] | 0x37F50000;
    }
}

void func_800FFB68(int arg0)
{
    if (arg0 != 0) {
        D_801022DE = -4;
        D_801022E0 = 0x80;
    }
    D_801022DC = arg0;
}

void vs_mainMenu_deactivateMenuItem(int arg0)
{
    vs_battle_menuItem_t* item = &vs_battle_menuItems[arg0];
    item->state = 0;
}

void func_800FFBA8(void) { func_800CD064(7); }

void func_800FFBC8(void)
{
    if (vs_main_settings.information != 0) {
        func_800C8E04(2);
        return;
    }
    func_800FFBA8();
}

void vs_mainmenu_setMessage(char* arg0)
{
    vs_battle_memcpy(&D_8010231A, arg0, 0x60);
    D_800F4FE0[7].unk0.unk0_0 = ((D_800F4FE0[7].unk0.unk0_0 & 0xC0FFFFFF) | 0x20000000);
    func_800C6BF0(7, D_8010231A - 2);
}

void vs_mainmenu_drawButton(int index, int x, int y, u_long* data)
{
    if (data == NULL) {
        data = D_1F800000[2];
    }
    func_800C0224(0x80, (x & 0xFFFF) | (y << 0x10), 0x100010, data)[4] =
        ((index & 3) * 0x10) | ((((index & 4) * 4) + 0x80) << 8) | 0x37FB0000;
}

int func_800FFCDC(u_int arg0, int arg1)
{
    int var_a0;
    int temp_s0;
    u_long* temp_a1;

    temp_s0 = arg0 >> (D_801022D5 * 8);
    temp_a1 = func_800C0224(D_800EC270[temp_s0], arg1, 0x100010, D_1F800000[2]);

    if (D_801022D5 == 0) {
        var_a0 = 0x37F83020;
    } else {
        var_a0 = 0x37FA3020;
    }
    temp_a1[4] = var_a0;
    D_801022D5 = 0;
    return (temp_s0 + 1) & 0xF;
}

int vs_mainMenu_printIntColor(int arg0, int arg1, int arg2, u_long* arg3)
{
    int sp10;
    int var_s0 = arg0;

    if (arg0 < 0) {
        var_s0 = -arg0;
    }

    do {
        var_s0 = vs_battle_toBCD(var_s0);
        sp10 = ((var_s0 & 0xF) << 8) | ('0' << 8) | '#';
        vs_battle_renderTextRawColor((char*)&sp10, arg1, arg2, arg3);
        var_s0 = var_s0 >> 4;
        arg1 -= 8;
    } while (var_s0 != 0);

    if (arg0 < 0) {
        sp10 = ('-' << 8) | '#';
        vs_battle_renderTextRawColor((char*)&sp10, arg1 + 1, arg2, arg3);
    }

    return arg1;
}

void func_800FFE20(int arg0, int arg1, int arg2, u_long* arg3)
{
    int var_a2;

    var_a2 = 0x808080;
    if (arg2 < arg0) {
        var_a2 = 0x804020;
    }
    if (arg0 < arg2) {
        var_a2 = 0x204080;
    }
    vs_mainMenu_printIntColor(arg0, arg1, var_a2, arg3);
}

void func_800FFE70(int arg0, int arg1, u_long* arg2)
{
    vs_mainMenu_printIntColor(arg0, arg1, 0x808080, arg2);
}

void func_800FFE98(int arg0, int arg1, int arg2, u_long* arg3)
{
    int i = 0;

    if (arg0 < 0) {
        arg1 += 0xF0000;
        arg2 += 0xF00;
    }

    do {
        ++i;
        func_800C0224((i * 8) | 0x100, arg1, 0x10010, arg3)[4] = arg2;
        arg1 += arg0 << 0x10;
        arg2 += arg0 << 8;
    } while (i < 16);
}

void func_800FFF38(int arg0, int arg1)
{
    u_long* temp_a1;
    int new_var2;

    temp_a1 = func_800C0214(0x70007, arg1);
    new_var2 = (((arg0 / 3) * 8) + 0xD8) | ((((arg0 % 3) * 8) + 0xC8) << 8);
    if (arg0 == 2) {
        temp_a1[4] = new_var2 | 0x37FA0000;
    } else {
        temp_a1[4] = new_var2 | 0x37F90000;
    }
}

void func_800FFFBC(int arg0, int arg1)
{
    func_800C0214(0x100010, arg1)[4] = (0x60 - (arg0 * 0x10)) | 0x37FD8000;
}

void vs_mainMenu_drawRowIcon(int arg0, int arg1, int arg2)
{
    int v1;
    int var_a0;
    u_long* temp_v0;

    var_a0 = arg0 >> 0x10;
    v1 = (arg0 >> 8) & 1;
    arg0 = (arg0 - 1) & 0xFF;

    if (var_a0 == 0) {
        temp_v0 = func_800C0224(
            0x40 << v1, (arg1 & 0xFFFF) | (arg2 << 0x10), 0x100010, D_1F800000[2] + 1);
        temp_v0[4] = D_8010237C[arg0] | 0x37FE0000;
        if (arg0 >= 0x17) {
            temp_v0[3] -= 12;
            temp_v0[4] = D_8010237C[arg0] | 0x37FD0000;
        }
    } else {
        if (var_a0 == 2) {
            var_a0 = -1;
        }
        func_800FFE98(var_a0, (arg1 & 0xFFFF) | (arg2 << 0x10),
            D_8010237C[arg0] | 0x37FE0000, D_1F800000[2] + 1);
    }
}

void vs_mainmenu_setAbilityCost(int index, char const* text, int x, int arg3)
{
    vs_mainMenu_isLevelledSpell = 1;
    vs_battle_rMemcpy(&_textHeaders[index], text, 14);
    _textHeaders[index].unk14 = arg3;
    _textHeaders[index].x = x;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100164);

void vs_mainMenu_drawButtonUiBackground(int arg0, int arg1, int arg2, int count)
{
    int i;
    u_long* var_t2 = D_1F800000[0];
    u_long* temp_v1 = D_1F800000[1] - 3;

    for (i = 0; i < count; ++i) {
        var_t2[0] = vs_getTag(u_long[6], temp_v1[0]);
        var_t2[1] = vs_getTpage(0, 0, 0, 0, ditheringOn);
        var_t2[2] = vs_getRGB0(primLineG2, 0x40, 0x38, 0x20);
        var_t2[3] = ((arg0 & 0xFFFF) | ((arg1 + i) << 0x10));
        var_t2[4] = vs_getRGB888(16, 16, 8);
        var_t2[5] = ((((arg0 + arg2) - i) & 0xFFFF) | ((arg1 + i) << 0x10));
        var_t2[6] = vs_getTpage(0, 0, 0, 0, ditheringOff);
        temp_v1[0] = (((u_long)var_t2 << 8) >> 8);
        var_t2 += 7;
    }
    D_1F800000[0] = var_t2;
}

void func_80100414(int arg0, int arg1)
{
    if (arg0 > 0) {
        D_800F4E90 |= 2;
    } else {
        D_800F4E90 &= 1;
    }
    D_801022DE = arg0;
    D_801022E0 = arg1;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_8010044C);

void vs_mainmenu_setMenuRows(int rowCount, int arg1, char** strings, int* rowTypes)
{
    int temp_v1_2;
    int i;
    int var_v0;
    int temp_a0;
    u_int var_a0;
    int var_a2;

    i = 0;
    var_a2 = 0;
    temp_a0 = arg1 & 0xFF;
    D_801023DF = (arg1 >> 0xC);
    D_801023DC = temp_a0;
    arg1 = (arg1 >> 8) & 0xF;

    if (vs_main_settings.cursorMemory != 0) {
        i = D_800F4EE8.unk0[temp_a0 * 2];
        var_a2 = D_800F4EE8.unk0[temp_a0 * 2 + 1];
    }

    temp_v1_2 = 0xA;
    temp_v1_2 = rowCount - temp_v1_2 + arg1;

    if (temp_v1_2 < 0) {
        i += var_a2;
        var_a2 = 0;
        if (i >= rowCount) {
            i = 0;
        }
    } else {
        if (temp_v1_2 < var_a2) {
            if ((i + var_a2) >= rowCount) {
                i = 0;
                var_a2 = 0;
            } else {
                i += var_a2 - temp_v1_2;
                var_a2 = temp_v1_2;
            }
        }

        var_v0 = var_a2 < temp_v1_2;

        if ((var_a2 > 0) && (i == 0)) {
            i = 1;
            var_a2 -= 1;
            var_v0 = var_a2 < temp_v1_2;
        }

        if (var_v0 != 0) {
            var_a0 = rowCount << 7;
            if (i == (9 - arg1)) {
                i -= 1;
                var_a2 += 1;
                ;
            }
        }
    }

    _selectedRow = i;

    D_801023DE = var_a2;
    D_801023E0 = rowCount;
    D_801023DD = arg1;
    D_801023D0 = 0;
    D_801023D4 = vs_main_allocHeapR(rowCount << 7);

    for (i = 0; i < rowCount; ++i) {
        char* s;
        *((int*)(&(&D_801023D4[i * 0x40])[14])) = rowTypes[i];

        if (strings[i * 2] != NULL) {
            vs_battle_copyAligned(&D_801023D4[i * 0x40], strings[i * 2], 0x1A);
            D_801023D4[(i * 0x40) + 13] = 0xE7E7;
        } else {
            D_801023D4[i * 0x40] = 0xE7E7;
        }

        s = strings[i * 2 + 1];
        if (s != NULL) {
            D_801023D4[(i * 0x40) + 16] = 0xF8;
            vs_battle_copyAligned(&D_801023D4[(i * 0x40) + 17], s, 0x5C);
            D_801023D4[(i * 0x40) + 63] = 0xE7E7;
        } else {
            D_801023D4[(i * 0x40) + 16] = 0xE7E7;
        }
    }
}

int func_80100814(void)
{
    vs_main_freeHeapR(D_801023D4);
    D_801023D4 = NULL;
    D_800F4EE8.unk0[D_801023DC * 2] = _selectedRow;
    D_800F4EE8.unk0[D_801023DC * 2 + 1] = D_801023DE;
    return (_selectedRow + D_801023DE) | ((_selectedRow + (D_801023DD * 10)) << 8);
}

int func_801008B0(void) { return _selectedRow + D_801023DE; }

int vs_mainmenu_getSelectedRow(void) { return D_801023D4 != NULL ? -1 : _selectedRow; }

vs_battle_menuItem_t* func_801008F0(int arg0, int arg1)
{
    int temp_a1;
    int temp_v1;
    vs_battle_menuItem_t* temp_v0 = vs_battle_setMenuItem(arg0 + (D_801023DD * 0xA), arg1,
        ((arg0 + D_801023DD) * 0x10) + 0x12, D_801023DF + 0x7E, 0,
        (char*)&D_801023D4[(D_801023DE + arg0) * 0x40]);

    temp_a1 = *((int*)(&(&D_801023D4[(D_801023DE + arg0) * 0x40])[14]));
    temp_v0->unk7 = temp_a1 & 1;
    temp_v0->unk2 = temp_v0->unk2 + ((temp_a1 & 2) * 0xC);
    temp_v1 = (temp_a1 >> 3) & 1;
    temp_v0->unkB = temp_v1;
    temp_v0->unkA = temp_v1 | ((temp_a1 >> 2) & 1);
    temp_v0->icon = (temp_a1 >> 0x1A);
    if ((arg0 == 0) && (D_801023DE != 0)) {
        temp_v0->unk5 = 1;
    }
    arg0 = (temp_a1 >> 9) & 0x7F;
    if (arg0 < 0x65) {
        temp_v0->unk10 = arg0;
    } else if (arg0 < 0x67) {
        temp_v0->itemState = arg0 - 0x64;
    } else {
        temp_v0->unk3C = vs_battle_hitlocations[arg0 - 0x67];
    }
    temp_v0->material = (temp_a1 >> 0x10) & 7;
    temp_v0->unk12 = (temp_a1 >> 0x13) & 0x7F;
    return temp_v0;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100A5C);

void func_80101118(int arg0)
{
    int var_a0;
    int temp_s4;
    int var_s3;
    u_long* temp_s2;
    u_long* temp_v0;

    var_s3 = 0;
    temp_s2 = D_1F800000[1] + D_801022DE;

    if (vs_main_frameBuf == 0) {
        var_s3 = 0x140;
    }

    arg0 *= 8;
    temp_s4 = arg0 == 0x80;

    if (temp_s4 != 0) {
        arg0 = D_801022E0;
        var_a0 = arg0;
    } else {
        arg0 = arg0 | 0x100;
        var_a0 = arg0;
    }
    temp_v0 = vs_battle_setSprite(var_a0, 0x100, 0xF00040, temp_s2);
    temp_v0[1] = 0xE10000BC;
    temp_v0[4] = 0x38F00000;

    temp_v0 = vs_battle_setSprite(arg0, 0, 0xF00100, temp_s2);
    temp_v0[1] = 0xE10000BA;
    temp_v0[4] = 0x38F00000;

    if (temp_s4 == 0) {
        int new_var = 0x120;
        arg0 = 0x180 - arg0;
        vs_battle_setSprite(arg0, 0, 0xF00100, temp_s2)[1] =
            (((u_int)var_s3 >> 6) | new_var | 0xE1000000);
        vs_battle_setSprite(arg0, 0x100, 0xF00040, temp_s2)[1] =
            (((var_s3 + 0x100) >> 6) | new_var | 0xE1000000);
    }
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80101268);

void func_801013F8(int arg0)
{
    int i;
    int color;
    int var_s4;
    u_int temp_s5;

    var_s4 = 0x37F90000;
    color = 0x404040;

    if ((D_801023E3 != 0) || (D_801023E4 != 0xB)) {
        var_s4 = 0x37F80000;
        ++D_801023E4;
        color = 0x808080;
        if (D_801023E4 >= 12) {
            D_801023E4 = 0;
        }
    }

    temp_s5 = D_801023E4 >> 2;

    if (arg0 != 0) {
        for (i = 0; i < 4; ++i) {
            vs_battle_renderTextRawColor(D_801023E8[i], D_801023F8[i], color, NULL);
        }
        i = 0x500C8;
    } else {
        i = 0x100010;
    }
    func_800C0214(0x100010, i - temp_s5)[4] = var_s4 | 0x3000;

    i = 0x1100A2;
    if (arg0 != 0) {
        i = 0x60124;
    }
    func_800C0214(0x100010, i + temp_s5)[4] = var_s4 | 0x3010;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_8010154C);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", D_800F99F8);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", D_800F9A04);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", D_800F9A08);
