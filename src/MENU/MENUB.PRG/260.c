#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include <libetc.h>
#include <stddef.h>

void func_800BEC14(short, int);
void func_80102CBC(int);
void func_8010837C(int);
void func_801086F4(int*);
void func_801088D4(func_801088D4_t*);
void func_80108938(int);
int func_80109750(int);

extern u_long* D_1F800000[];

extern char D_8010A2C4;
extern int D_8010A50C;
extern char D_8010A505;
extern char D_8010A69E;
extern char (*D_8010A6A0)[4];
extern void* D_8010A6A4;
extern vs_battle_inventory_t* _inventory;
extern void* D_8010A6AC;
extern char D_8010A6B0;
extern u_char D_8010A6B1;
extern char D_8010A6B2;
extern u_char D_8010A6B3;
extern char D_8010A6B4;
extern char D_8010A6B5;
extern u_char D_8010A6B6;
extern char D_8010A6B7;
extern char D_8010A6B8;
extern char D_8010A6B9;
extern char D_8010A6BA;
extern char D_8010A6BB;
extern char D_8010A6BF;
extern int D_8010A6C0;

int func_80102A60(int arg0, int arg1)
{
    if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {
        int temp_s1 = arg1;
        arg0 = vs_mainMenu_getItemCount(arg0, NULL);
        if (vs_main_buttonRepeat & PADL1) {
            int new_var = arg1 - 1;
            arg1 = new_var + arg0;
        }
        if (vs_main_buttonRepeat & PADR1) {
            ++arg1;
        }
        if (arg1 >= arg0) {
            arg1 -= arg0;
        }
        if ((vs_main_buttonsPressed.all & (PADL1 | PADR1)) && (arg1 == temp_s1)) {
            func_800C02E0();
        }
    }
    return arg1;
}

void func_80102B14(int arg0, int arg1)
{
    int i;
    u_long* var_v1;
    vs_battle_menuItem_t* menuItem;

    int temp_s4 = (D_800F4EE8.unk3A[0] - 1) & 7;

    if (arg0 == 4) {
        func_801013F8(0);
    }

    arg0 = (arg0 * 8) - 0x10;

    for (i = 0; i < 8; ++i) {
        int temp_s0 = (((i + 1) & 7) * 0x10) + 0x20;
        if (i == temp_s4 && arg1 == 1) {
            menuItem = vs_battle_getMenuItem(0x1F);
            if (temp_s0 >= (menuItem->initialX - 0xC)) {
                menuItem->icon = i + 0x18;
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

void func_80102C50(int arg0)
{
    vs_battle_menuItem_t* temp_v0;

    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    temp_v0 = vs_battle_getMenuItem(0x1F);
    temp_v0->state = 3;
    temp_v0->targetX = 0x12;
    temp_v0 = vs_battle_getMenuItem(arg0);
    temp_v0->state = 2;
    temp_v0->targetX = 0x9B;
    temp_v0->selected = 1;
    temp_v0->unk3C = NULL;
}

void func_80102CBC(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_getMenuItem(31);
    menuItem->state = 2;
    menuItem->targetX = 16;
    menuItem->w = 164;
    menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 3;
    menuItem->targetX = 18;
}

void func_80102D1C(int arg0, int arg1)
{
    D_8010A50C = 1;
    D_8010A6BA = 0;
    D_8010A6BB = 0;
    func_80102CBC(arg0);
    func_800FBBD4(arg1);
    vs_battle_renderEquipStats(1);
}

void func_80102D6C(int id, char** menuText, u_int rowType, int arg3)
{
    vs_battle_menuItem_t* temp_v0;

    vs_battle_playMenuChangeSfx();
    temp_v0 = vs_battle_setMenuItem(id, 0x9B, 0x12, 0xA5, 0, menuText[0]);
    temp_v0->selected = 1;
    temp_v0->icon = rowType >> 0x1A;
    temp_v0->material = (rowType >> 0x10) & 7;
    vs_mainmenu_setMessage(menuText[1]);
    vs_battle_getMenuItem(0x1F)->unkE = arg3 + 1;
}

int func_80102E08(int arg0, int arg1)
{
    D_800F4EE8.unk0[(arg0 + 0x1E) * 2] = 0;
    D_800F4EE8.unk0[(arg0 + 0x1E) * 2 + 1] = arg1;
    return vs_mainMenu_inventoryIndices[arg0][arg1];
}

void func_80102E54(int arg0)
{
    vs_battle_playMenuLeaveSfx();
    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    func_800FA810(-1);
    func_800FBBD4(-1);
    vs_battle_renderEquipStats(2);
    D_8010A6BF = 2;
    D_8010A6C0 = vs_main_buttonsPressed.all & PADRup;
    if (arg0 != 0) {
        vs_mainMenu_drawDpPpbars(4);
    }
}

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80102EC4);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_8010310C);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801032F8);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80103538);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80103794);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801039BC);

extern int (*D_8010A514[])(int);
extern u_char D_8010A607;

int func_80103BA8(int arg0)
{
    int temp_v0;
    int var_s0 = 0;

    if (arg0 != 0) {
        var_s0 = arg0 >> 4;
        D_8010A607 = arg0 & 0xF;
        D_8010A6BF = 1;
        D_8010A6C0 = 0;
        func_800FDD78();
        vs_battle_getMenuItem(0x1F)->unkE = var_s0 & 0xFF;
        func_800FFA88(0);
    }

    temp_v0 = D_8010A514[D_8010A607](var_s0);

    if (temp_v0 != 0) {
        if (D_8010A6C0 != 0) {
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
    return temp_v0;
}

INCLUDE_RODATA("build/src/MENU/MENUB.PRG/nonmatchings/260", D_80102800);

int _getWeaponStat(int stat, vs_battle_uiWeapon* weapon)
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

void func_80103DA0(int arg0)
{
    vs_battle_uiWeapon sp10;
    char sp1A8[8];
    int temp_v0;
    int i;
    int var_s3;
    int var_s4;
    int temp_s0;
    vs_battle_inventoryWeapon* new_var2 = vs_battle_inventory.weapons;
    char* new_var = D_800619D8.unk0;

    vs_battle_rMemzero(sp1A8, 8);
    var_s4 = 0;

    while (1) {
        var_s3 = 0x80000000;

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                vs_battle_applyWeapon(&sp10, &new_var2[temp_s0 - 1]);
                temp_v0 = _getWeaponStat(arg0, &sp10);
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
                vs_battle_applyWeapon(&sp10, &new_var2[temp_s0 - 1]);
                if (_getWeaponStat(arg0, &sp10) == var_s3) {
                    sp1A8[var_s4++] = temp_s0;
                    new_var[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(new_var, sp1A8, sizeof sp1A8);
}

int _getShieldStat(int arg0, vs_battle_uiShield* shield)
{
    switch (arg0) {
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
        if (arg0 < 33) {
            return shield->classAffinityCurrent.class[0][arg0 - 27];
        }
        if (arg0 >= 40) {
            return shield->types[arg0 - 39];
        }
        return shield->classAffinityCurrent.affinity[0][arg0 - 33];
    }
}

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80103FD8);

int func_80104144(int arg0, vs_battle_inventoryMisc* arg1)
{
    if (arg0 == 0) {
        return -arg1->id;
    }
    return arg1->count;
}

void func_80104164(int arg0)
{
    char sp10[64];
    int temp_v0;
    int i;
    int var_s4;

    vs_battle_inventoryMisc* item = vs_battle_inventory.items;
    char* c = D_800619D8.unk70;

    vs_battle_rMemzero(sp10, sizeof sp10);
    var_s4 = 0;

    while (1) {
        int temp_s0;
        int var_s3 = 0x80000000;

        for (i = 0; i < 64; ++i) {
            temp_s0 = c[i];
            if (temp_s0 != 0) {
                temp_v0 = func_80104144(arg0, &item[temp_s0 - 1]);
                if (var_s3 < temp_v0) {
                    var_s3 = temp_v0;
                }
            }
        }

        if (var_s3 == 0x80000000) {
            break;
        }

        for (i = 0; i < 64; ++i) {
            temp_s0 = c[i];
            if (temp_s0 != 0) {
                if (func_80104144(arg0, &item[temp_s0 - 1]) == var_s3) {
                    sp10[var_s4++] = temp_s0;
                    c[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(c, &sp10, sizeof sp10);
}

int _getEquipmentStat(int stat, vs_battle_uiEquipment* item)
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
    case 1:
        vs_battle_copyInventoryBladeStats(equipment, &vs_battle_inventory.blades[index]);
        return;
    case 2:
        vs_battle_copyInventoryGripStats(equipment, &vs_battle_inventory.grips[index]);
        return;
    case 4:
        vs_battle_copyInventoryArmorStats(equipment, &vs_battle_inventory.armor[index]);
        return;
    case 5:
        vs_battle_copyInventoryGemStats(equipment, &vs_battle_inventory.gems[index]);
        return;
    }
}

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80104474);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80104608);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80104860);

void func_80104F98(int arg0)
{
    D_8010A6B9 = arg0;
    D_8010A6BA = arg0;
    D_8010A6BB = arg0;
}

int _getParentItem(int itemCategory, int index)
{
    int parentIndex = 0;

    if (itemCategory == 1) {
        parentIndex = vs_battle_inventory.blades[index].assembledWeaponIndex;
    }
    if (itemCategory == 2) {
        parentIndex = vs_battle_inventory.grips[index].assembledWeaponIndex;
    }
    if (itemCategory == 5) {
        parentIndex = vs_battle_inventory.gems[index].setItemIndex;
        if (parentIndex & 0x80) {
            parentIndex = 0;
        }
    }
    return parentIndex;
}

int func_80105044(int arg0, int arg1)
{
    int var_v1 = 0;
    if (arg0 == 5) {
        var_v1 = vs_battle_inventory.gems[arg1].setItemIndex;
        if (!(var_v1 & 0x80)) {
            var_v1 = 0;
        }
    }
    return var_v1 & 0x7F;
}

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80105088);

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

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80105454);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80106274);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801066CC);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80106B80);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801073E0);

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

int _copyWeaponToInventory(vs_battle_setWeaponForDropRand* arg0)
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

int _copyShieldToInventory(vs_battle_shieldForDropRand* arg0)
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

int _copyMiscToInventory(vs_battle_inventoryMisc* arg0)
{
    int index = 1;
    vs_battle_inventoryMisc* item = _inventory->items;

    while (item->id != 0) {
        ++index;
        ++item;
        if (index == 64) {
            return 0;
        }
    }

    item->id = arg0->id;
    item->count = arg0->index;
    return index;
}

void func_801080F0(void)
{
    int i;
    int temp_v1;
    char(*var_s1)[4] = D_8010A6A0;

    for (i = 0; i < D_8010A6B6; ++i, ++var_s1) {
        (*var_s1)[3] =
            (func_800FEB94((*var_s1)[0], &vs_battle_inventory, (*var_s1)[1], _inventory)
                != 0);
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
    char* temp_v1 = D_8010A6A0[D_8010A6B6++];
    temp_v1[0] = arg0;
    temp_v1[1] = arg1 - 1;
    temp_v1[2] = 0;
}

INCLUDE_RODATA("build/src/MENU/MENUB.PRG/nonmatchings/260", D_80102950);

int func_80108264(int arg0, u_char* arg1)
{
    int i;
    vs_battle_inventoryShield* shield;
    vs_battle_inventoryWeapon* weapon;

    int temp_t0 = arg1[0];
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
            weapon = &_inventory->weapons[arg1[1]];

            for (i = 0; i < _inventory->grips[weapon->grip - 1].gemSlots; ++i) {
                var_a2 += weapon->gems[i] != 0;
            }
        }
        if (temp_t0 == 3) {
            shield = &_inventory->shields[arg1[1]];

            for (i = 0; i < shield->base.gemSlots; ++i) {
                var_a2 += shield->gems[i] != 0;
            }
        }
        break;
    }
    return var_a2;
}

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_8010837C);

int func_801086DC(int arg0) { return arg0 & (vs_main_stateFlags.unk1 + 1); }

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801086F4);

void func_801088D4(func_801088D4_t* arg0)
{
    vs_battle_rMemzero(_inventory, sizeof *_inventory);

    if (arg0 != 0) {
        while (arg0 != 0) {
            func_801086F4(&arg0->unk8);
            arg0 = arg0->next;
        }
    } else {
        func_801086F4(D_800EB9C8);
    }
}

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80108938);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80108E78);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_801090A4);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80109444);

INCLUDE_ASM("build/src/MENU/MENUB.PRG/nonmatchings/260", func_80109750);

int func_80109E90(char* state)
{
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
                vs_mainmenu_setMessage(&D_8010A2C4);
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
        func_800BEC14(arg0 + 0x1B6, 1);
    }
}
