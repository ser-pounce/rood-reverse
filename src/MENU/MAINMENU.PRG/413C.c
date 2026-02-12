#include "common.h"
#include "413C.h"
#include "C48.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "lbas.h"

typedef struct {
    char text[14];
    char unk14;
    char x;
} textHeader_t;

extern char vs_mainMenu_isLevelledSpell;
extern char D_801022DC;
extern short D_801022DE;
extern short D_801022E0;
extern char D_801022E2;
extern char D_801022E3;
extern int D_801022E4;
extern u_short D_801022E8[];
extern int D_801022F8[];
extern char D_8010231A[];
extern void* D_801023D4;
extern char D_801023DC;
extern char D_801023DD;
extern int _selectedRow;
extern char D_801023DE;
extern vs_main_CdQueueSlot* _itemNamesCdQueueSlot;
extern char _itemNamesLoading;
extern textHeader_t _textHeaders[];
extern u_long* D_1F800000[];

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FD93C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDB04);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDB60);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDBAC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDCD0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDD24);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDD78);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDD88);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDEBC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE360);

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

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE694);

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

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FEB08);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FEB94);

void func_800FF0EC(int, int, char**, int*);
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF0EC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF348);

int func_800FF360(void);
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF360);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF388);

void func_800FF43C(void);
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF43C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF9E4);

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

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFCDC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFD64);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFE20);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFE70);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFE98);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFF38);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFFBC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100004);

void vs_mainmenu_setAbilityCost(int index, char const* text, int x, int arg3)
{
    vs_mainMenu_isLevelledSpell = 1;
    vs_battle_rMemcpy(&_textHeaders[index], text, 14);
    _textHeaders[index].unk14 = arg3;
    _textHeaders[index].x = x;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100164);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100344);

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

// https://decomp.me/scratch/Oo0p8
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", vs_mainmenu_setMenuRows);

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

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_801008F0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100A5C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80101118);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80101268);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_801013F8);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_8010154C);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", D_800F99F8);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", D_800F9A04);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", D_800F9A08);
