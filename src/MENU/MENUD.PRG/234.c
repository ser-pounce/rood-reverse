#include "common.h"
#include "234.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include <libetc.h>

typedef struct {
    char unk0[0x2318];
    u_short unk2318[1][0xE];
} func_80103D14_t;

void func_80102D80(int, int, vs_menu_containerData*);
int _getContainerItemId(int, int, vs_menu_containerData*);
int func_80103070(int, vs_menu_containerData*);
void func_801031A0(void);
void func_801032AC(int, vs_menu_containerData*, int, vs_menu_containerData*);
void func_801037D8(int, func_80102C94_t*);

extern u_long* D_1F800000[];

extern u_short D_80109944[];
extern int (*D_80109958[])(int);
extern char* D_80109A08[];
extern char* D_80109A10[];
extern u_char D_80109A48[];
extern char D_80109A7A;
extern signed char D_80109A7B;
extern signed char D_80109A7C;
extern signed char D_80109A7D;
extern char D_80109A81;
extern short D_80109A82;
extern int D_80109A84;
extern void* D_80109A88;

void func_80102A34(vs_battle_equippedWeapon* target, vs_battle_inventoryWeapon* source,
    vs_menu_containerData* container)
{
    int i;
    vs_battle_weaponIntermediate* weapon = vs_main_allocHeapR(sizeof *weapon);
    vs_main_bzero(weapon, sizeof *weapon);

    if (source != NULL) {
        weapon->unkF2 = source->unk0;
        if (source->blade != 0) {
            vs_battle_copyInventoryBladeStats(
                &weapon->blade, &container->blades[source->blade - 1]);
            weapon->material = container->blades[source->blade - 1].material;
        }

        if (source->grip != 0) {
            vs_battle_copyInventoryGripStats(
                &weapon->grip, &container->grips[source->grip - 1]);
        }

        for (i = 0; i < 3; ++i) {
            if (source->gems[i] != 0) {
                vs_battle_copyInventoryGemStats(
                    &weapon->gems[i], &container->gems[source->gems[i] - 1]);
            }
        }
    }

    for (i = 0; i < 24; ++i) {
        weapon->name[i] = source->name[i];
    }

    vs_battle_applyWeaponStats(target, weapon);
    vs_main_freeHeapR(weapon);
}

void func_80102BB0(vs_battle_equippedShield* target, vs_battle_inventoryShield* source,
    vs_menu_containerData* container)
{
    int i;
    vs_battle_shieldIntermediate* tempShield = vs_main_allocHeapR(sizeof *tempShield);
    vs_main_bzero(tempShield, sizeof *tempShield);

    if (source != NULL) {
        tempShield->unkC2 = source->unk0;
        vs_battle_copyInventoryArmorStats(&tempShield->unk0, &source->unk4);
        tempShield->material = source->unk4.material;

        for (i = 0; i < 3; ++i) {
            if (source->gems[i] != 0) {
                vs_battle_copyInventoryGemStats(
                    &tempShield->gems[i], &container->gems[(source->gems[i] & 0x7F) - 1]);
            }
        }
    }
    vs_battle_applyShieldStats(target, tempShield);
    vs_main_freeHeapR(tempShield);
}

static u_short* func_80102C94(int arg0, func_80102C94_t* arg1)
{
    int i;
    int var_a3;

    var_a3 = 0;
    for (i = 0; i < arg0; ++i) {
        var_a3 += D_80109944[i];
    }
    return arg1->unk3C00 + var_a3;
}

static int func_80102CD0(int arg0, int arg1, u_short* arg2)
{
    int i;

    for (i = 0; i < D_80109944[arg0]; ++i) {
        if (arg2[i] == (arg1 + 1)) {
            return i + 1;
        }
    }
    return 0;
}

static void func_80102D28(int arg0, int arg1, u_short* arg2)
{
    int i;

    for (i = 0; i < D_80109944[arg0]; ++i) {
        if (arg2[i] == 0) {
            arg2[i] = arg1 + 1;
            return;
        }
    }
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80102D80);

int _getContainerItemId(int type, int index, vs_menu_containerData* container)
{
    int ret = 0;

    switch (type) {
    case 0:
        ret = container->weapons[index].blade;
        break;
    case 1:
        ret = container->blades[index].id;
        break;
    case 2:
        ret = container->grips[index].id;
        break;
    case 3:
        ret = container->shields[index].unk4.id;
        break;
    case 4:
        ret = container->armor[index].id;
        break;
    case 5:
        ret = container->gems[index].id;
        break;
    case 6:
        ret = container->items[index].id;
        break;
    }
    return ret;
}

int func_80103070(int arg0, vs_menu_containerData* arg1)
{
    int i;
    int var_s1 = 0;

    for (i = 0; i < D_80109944[arg0]; ++i) {
        if (_getContainerItemId(arg0, i, arg1) != 0) {
            ++var_s1;
        }
    }
    return var_s1;
}

int func_80103110(int arg0, void* arg1)
{
    int i;

    for (i = 0; i < D_80109944[arg0]; ++i) {
        if (_getContainerItemId(arg0, i, arg1) == 0) {
            break;
        }
    }
    return i;
}

void func_801031A0(void)
{
    int i;
    int var_a2;
    vs_menu_containerData* temp_s2 = &D_8010245C->unk4BB0;

    vs_battle_memcpy(&temp_s2->items, D_80109A88 + 0x3800, sizeof temp_s2->items);

    for (var_a2 = D_8010245C->unkC3B0[0], i = 0; var_a2 != 0;
         ++i, var_a2 = D_8010245C->unkC3B0[i]) {
        if ((var_a2 >> 8) == 6) {
            func_801032AC(0x16, temp_s2, (var_a2 - 1) & 0xFF, &D_8010245C->unk87B0);
        }
    }
}

static void func_80103270(void)
{
    short* s0 = &D_80109A82;
    func_801031A0();
    D_80109A82 = func_80103070(6, &D_8010245C->unk4BB0);
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801032AC);

void func_801037D8(int arg0, func_80102C94_t* arg1)
{
    int i;
    int j;
    int var_a1;
    int temp_a1;
    int temp_s2;
    u_short* temp_s3;

    temp_s3 = func_80102C94(arg0, arg1);
    temp_s2 = D_80109944[arg0];

    for (i = 0; i < temp_s2; ++i) {
        temp_a1 = temp_s3[i];
        if ((temp_a1 != 0)
            && (_getContainerItemId(arg0, temp_a1 - 1, &arg1->unk0) == 0)) {
            temp_s3[i] = 0;
        }
    }

    i = 0;

    while (1) {
        if (temp_s3[i] != 0) {
            ++i;
            if (i == (temp_s2 - 1)) {
                break;
            }
        } else {
            var_a1 = i + 1;
            while (var_a1 < temp_s2) {
                if (temp_s3[var_a1] != 0) {
                    break;
                }
                ++var_a1;
            }

            if (var_a1 == temp_s2) {
                break;
            }

            for (j = var_a1; j < temp_s2; ++j) {
                temp_s3[(j + i) - var_a1] = temp_s3[j];
            }

            for (j = j + (i - var_a1); j < temp_s2; ++j) {
                temp_s3[j] = 0;
            }
        }
    }
    for (i = 0; i < temp_s2; ++i) {
        if ((_getContainerItemId(arg0, i, &arg1->unk0) != 0)
            && (func_80102CD0(arg0, i, temp_s3) == 0)) {
            func_80102D28(arg0, i, temp_s3);
        }
    }
}

void func_801039AC(void)
{
    int i;

    vs_battle_inventory_t* inventory = &vs_battle_inventory;
    func_80102C94_t* container = &D_8010245C->unk105B0;

    vs_battle_rMemzero(&container->unk0, sizeof container->unk0);
    vs_battle_rMemzero(
        &D_8010245C->unk105B0.unk3C00, sizeof D_8010245C->unk105B0.unk3C00);

    for (i = 0; i < 7; ++i) {
        int j;
        char* temp_s0 = D_801022A8[i];
        u_short* temp_a1 = func_80102C94(i, container);

        for (j = 0; j < D_801022A0[i]; ++j) {
            temp_a1[j] = temp_s0[j];
        }
    }

    vs_battle_memcpy(
        container->unk0.weapons, inventory->weapons, sizeof container->unk0.weapons / 4);
    vs_battle_memcpy(
        container->unk0.blades, inventory->blades, sizeof container->unk0.blades / 4);
    vs_battle_memcpy(
        container->unk0.grips, inventory->grips, sizeof container->unk0.grips / 4);
    vs_battle_memcpy(
        container->unk0.shields, inventory->shields, sizeof container->unk0.shields / 4);
    vs_battle_memcpy(
        container->unk0.armor, inventory->armor, sizeof container->unk0.armor / 4);
    vs_battle_memcpy(
        container->unk0.gems, inventory->gems, sizeof container->unk0.gems / 4);
    vs_battle_memcpy(
        container->unk0.items, inventory->items, sizeof container->unk0.items / 4);
}

void func_80103B20(void)
{
    int i;

    func_80102C94_t* temp_s2 = &D_8010245C->unk105B0;
    vs_battle_inventory_t* inventory = &vs_battle_inventory;

    for (i = 0; i < 7; ++i) {
        int j;
        int k;
        char* temp_s5 = D_801022A8[i];
        u_short* temp_s3 = func_80102C94(i, temp_s2);

        for (j = 0; j < 7; ++j) {
            func_801037D8(j, temp_s2);
        }

        for (k = 0; k < D_801022A0[i]; ++k) {
            temp_s5[k] = temp_s3[k];
        }
    }

    vs_battle_memcpy(
        inventory->weapons, temp_s2->unk0.weapons, sizeof inventory->weapons);
    vs_battle_memcpy(inventory->blades, temp_s2->unk0.blades, sizeof inventory->blades);
    vs_battle_memcpy(inventory->grips, temp_s2->unk0.grips, sizeof inventory->grips);
    vs_battle_memcpy(
        inventory->shields, temp_s2->unk0.shields, sizeof inventory->shields);
    vs_battle_memcpy(inventory->armor, temp_s2->unk0.armor, sizeof inventory->armor);
    vs_battle_memcpy(inventory->gems, temp_s2->unk0.gems, sizeof inventory->gems);
    vs_battle_memcpy(inventory->items, temp_s2->unk0.items, sizeof inventory->items);
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80103C9C);

static int func_80103D14(int arg0, int arg1, func_80103D14_t* arg2)
{
    u_short var_v1;

    var_v1 = 0;
    if (arg0 == 5) {
        var_v1 = arg2->unk2318[arg1][0];
        if (!(var_v1 & 0x80)) {
            var_v1 = 0;
        }
    }
    return var_v1 & 0x7F;
}

static void func_80103D50(signed char arg0)
{
    D_80109A7B = arg0;
    D_80109A7C = arg0;
    D_80109A7D = arg0;
}

int func_80103D6C(int arg0, int arg1)
{
    int temp_s1;
    int temp_a1;
    int temp_a0;

    if ((vs_main_buttonsState & 0xC) != 0xC) {
        temp_s1 = arg1;
        temp_a1 = func_80103070(arg0, &vs_menuD_containerData->unk0);
        temp_a0 = temp_a1;

        if (vs_main_buttonRepeat & 4) {
            int temp = arg1 - 1;
            arg1 = temp + temp_a1;
        }
        do {
            if (vs_main_buttonRepeat & 8) {
                arg1++;
            }
            if (arg1 >= temp_a0) {
                arg1 -= temp_a0;
            }
        } while (0);
        if ((vs_main_buttonsPressed.all & 0xC) && (arg1 == temp_s1)) {
            func_800C02E0();
        }
    }
    return arg1;
}

void func_80103E24(int arg0, int arg1)
{
    int temp_s0;
    int temp_s4;
    int i;
    u_long* var_v1;
    vs_battle_menuItem_t* temp_v0;

    temp_s4 = (D_800F4EE8.unk85[0x1B] - 1) & 7;

    if (arg0 == 4) {
        func_801013F8(0);
    }

    arg0 = (arg0 * 8) - 0x10;

    for (i = 0; i < 8; ++i) {
        temp_s0 = (((i + 1) & 7) * 0x10) + 0x20;
        if ((i == temp_s4) && (arg1 == 1)) {
            temp_v0 = vs_battle_getMenuItem(0x1F);
            if (temp_s0 >= (temp_v0->animSpeed - 0xC)) {
                temp_v0->flags = i + 0x18;
                continue;
            } else {
                var_v1 = func_800C0214(0x100010, temp_s0 | 0x100000);
            }
        } else {
            var_v1 = func_800C0224(
                0x80, temp_s0 | (arg0 << 0x10), 0x100010, D_1F800000[1] - 3);
        }

        var_v1[4] = (0x78 + i * 0x10) | 0x8000 | (i == temp_s4 ? 0x37FD0000 : 0x37FE0000);
    }
}

void func_80103F64(int arg0)
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
    menuItem->unk7 = 0;
}

void func_80103FD4(int arg0)
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

static void func_80104034(int arg0, int arg1)
{
    D_80109A7C = 0;
    D_80109A7D = 0;
    func_80103FD4(arg0);
    func_800FBBD4(arg1);
    func_800FBEA4(1);
}

void func_80104078(int arg0, char** arg1, u_int arg2, int arg3)
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

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104114);

void func_80104170(int arg0)
{
    vs_battle_playMenuLeaveSfx();
    func_800FA8E0(0x28);
    func_800FA810(-1);
    func_800FBBD4(-1);
    func_800FBEA4(2);
    D_80109A81 = 2;
    D_80109A84 = vs_main_buttonsPressed.all & PADRup;
    if (arg0 != 0) {
        vs_mainMenu_drawDpPpbars(4);
    }
}

void func_801041E0(
    vs_menu_containerData* arg0, char** arg1, int* arg2, char* arg3, int arg4)
{
    vs_battle_equippedWeapon sp10;

    func_80102A34(&sp10, &arg0->weapons[arg4], arg0);
    vs_mainMenu_setWeaponStrings(&sp10, arg1, arg2, arg3);
    *arg1 = arg0->weapons[arg4].name;
}

void func_8010425C(
    vs_menu_containerData* arg0, char** arg1, int* arg2, char* arg3, int arg4)
{
    vs_battle_equippedShield sp10;

    func_80102BB0(&sp10, &arg0->shields[arg4], arg0);
    vs_mainMenu_setShieldStrings(&sp10, arg1, arg2, arg3);
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801042D0);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104534);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104728);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_8010496C);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104BDC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80104E14);

int func_80105008(int arg0)
{
    int temp_v0;
    int var_s0 = 0;

    if (arg0 != 0) {
        var_s0 = arg0 >> 4;
        D_80109A48[3] = arg0 & 0xF;
        D_80109A81 = 1;
        D_80109A84 = 0;
        func_800FDD78();
        vs_battle_getMenuItem(0x1F)->unkE = var_s0 & 0xFF;
        func_800FFA88(0);
    }

    temp_v0 = D_80109958[D_80109A48[3]](var_s0);

    if (temp_v0 != 0) {
        if (D_80109A84 != 0) {
            return -2;
        }
        D_80109A7C = 1;
        D_80109A81 = 0;
        D_80109A7D = 1;
        func_800FFA88(2);
    } else if (vs_mainmenu_ready() != 0) {
        D_801022D5 = D_801024B8 != 9;
        func_801013F8(1);
        func_800FDEBC();
    }
    return temp_v0;
}

INCLUDE_RODATA("build/src/MENU/MENUD.PRG/nonmatchings/234", D_8010285C);

int _getWeaponStat(int type, vs_battle_equippedWeapon* weapon)
{
    switch (type) {
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
        if (type >= 17) {
            return weapon->classAffinityCurrent.affinity[0][type - 17];
        }
        return weapon->classAffinityCurrent.class[0][type - 11];
    }
}

void func_801051F8(int arg0)
{
    vs_battle_equippedWeapon sp10;
    u_short sp1A8[0x20];
    vs_battle_inventoryWeapon* temp_s6;
    int temp_v0;
    int i;
    int var_s4;
    int var_s5;
    int temp_s0;
    u_short* temp_s7;

    temp_s6 = vs_menuD_containerData->unk0.weapons;
    temp_s7 = func_80102C94(0, vs_menuD_containerData);
    vs_battle_rMemzero(sp1A8, 0x40);
    var_s5 = 0;

    while (1) {
        var_s4 = 0x80000000;
        for (i = 0; i < 32; ++i) {
            temp_s0 = temp_s7[i];
            if (temp_s0 != 0) {
                func_80102A34(
                    &sp10, &temp_s6[temp_s0 - 1], &vs_menuD_containerData->unk0);
                temp_v0 = _getWeaponStat(arg0, &sp10);
                if (var_s4 < temp_v0) {
                    var_s4 = temp_v0;
                }
            }
        }

        if (var_s4 == 0x80000000) {
            break;
        }

        for (i = 0; i < 32; ++i) {
            temp_s0 = temp_s7[i];
            if (temp_s0 != 0) {
                func_80102A34(
                    &sp10, &temp_s6[temp_s0 - 1], &vs_menuD_containerData->unk0);
                if (_getWeaponStat(arg0, &sp10) == var_s4) {
                    sp1A8[var_s5++] = temp_s0;
                    temp_s7[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(temp_s7, &sp1A8, sizeof sp1A8);
}

int _getShieldStat(int arg0, vs_battle_equippedShield* shield)
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

void func_80105454(int arg0)
{
    vs_battle_equippedShield sp10;
    u_short sp178[0x20];
    int temp_v0;
    int i;
    int var_s3;
    int temp_s0;

    vs_battle_inventoryShield* temp_s5 = vs_menuD_containerData->unk0.shields;
    u_short* temp_s6 = func_80102C94(3, vs_menuD_containerData);
    int var_s4 = 0;

    vs_battle_rMemzero(&sp178, sizeof sp178);

    while (1) {
        var_s3 = 0x80000000;

        for (i = 0; i < 32; ++i) {
            temp_s0 = temp_s6[i];
            if (temp_s0 != 0) {
                func_80102BB0(
                    &sp10, &temp_s5[temp_s0 - 1], &vs_menuD_containerData->unk0);
                temp_v0 = _getShieldStat(arg0, &sp10);
                if (var_s3 < temp_v0) {
                    var_s3 = temp_v0;
                }
            }
        }

        if (var_s3 == 0x80000000) {
            break;
        }

        for (i = 0; i < 32; ++i) {
            temp_s0 = temp_s6[i];
            if (temp_s0 != 0) {
                func_80102BB0(
                    &sp10, &temp_s5[temp_s0 - 1], &vs_menuD_containerData->unk0);
                if (_getShieldStat(arg0, &sp10) == var_s3) {
                    sp178[var_s4++] = temp_s0;
                    temp_s6[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(temp_s6, &sp178, sizeof sp178);
}

static int func_801055D0(int arg0, vs_battle_inventoryItem* item)
{
    if (arg0 == 0) {
        return -item->id;
    }
    return item->unk2;
}

void func_801055F0(int arg0)
{
    u_short sp10[0x100];
    int temp_v0;
    int i;
    int var_s4;
    int var_s5;
    int temp_s0;
    u_short* temp_s7;
    vs_battle_inventoryItem* item;

    item = vs_menuD_containerData->unk0.items;
    temp_s7 = func_80102C94(6, vs_menuD_containerData);
    vs_battle_rMemzero(&sp10, sizeof sp10);
    var_s5 = 0;

    while (1) {
        var_s4 = 0x80000000;

        for (i = 0; i < 256; ++i) {
            temp_s0 = temp_s7[i];
            if (temp_s0 != 0) {
                temp_v0 = func_801055D0(arg0, &item[temp_s0 - 1]);
                if (var_s4 < temp_v0) {
                    var_s4 = temp_v0;
                }
            }
        }

        if (var_s4 == 0x80000000) {
            break;
        }

        for (i = 0; i < 256; ++i) {
            temp_s0 = temp_s7[i];
            if ((temp_s0 != 0) && (func_801055D0(arg0, &item[temp_s0 - 1]) == var_s4)) {
                sp10[var_s5++] = temp_s0;
                temp_s7[i] = 0;
            }
        }
    }
    vs_battle_memcpy(temp_s7, &sp10, sizeof sp10);
}

int _getItemStat(int stat, vs_battle_equippedItem* item)
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

void func_80105844(vs_battle_equippedItem* item, int type, int index)
{
    switch (type) {
    case 1:
        vs_battle_copyInventoryBladeStats(
            item, &vs_menuD_containerData->unk0.blades[index]);
        return;
    case 2:
        vs_battle_copyInventoryGripStats(
            item, &vs_menuD_containerData->unk0.grips[index]);
        return;
    case 4:
        vs_battle_copyInventoryArmorStats(
            item, &vs_menuD_containerData->unk0.armor[index]);
        return;
    case 5:
        vs_battle_copyInventoryGemStats(item, &vs_menuD_containerData->unk0.gems[index]);
        return;
    }
}

void func_8010592C(int arg0, int arg1)
{
    vs_battle_equippedItem sp10;
    int temp_v0;
    int i;
    int var_s4;
    int var_s6;
    int temp_s0;
    int temp_s5;
    u_short* temp_s7;

    var_s6 = 0;
    temp_s5 = D_80109944[arg0];

    {
        u_short sp40[temp_s5];
        temp_s7 = func_80102C94(arg0, vs_menuD_containerData);
        vs_battle_rMemzero(sp40, temp_s5 * 2);

        while (1) {
            var_s4 = 0x80000000;

            for (i = 0; i < temp_s5; ++i) {
                temp_s0 = temp_s7[i];
                if (temp_s0 != 0) {
                    func_80105844(&sp10, arg0, temp_s0 - 1);
                    temp_v0 = _getItemStat(arg1, &sp10);
                    if (var_s4 < temp_v0) {
                        var_s4 = temp_v0;
                    }
                }
            }

            if (var_s4 == 0x80000000) {
                break;
            }

            for (i = 0; i < temp_s5; ++i) {
                temp_s0 = temp_s7[i];
                if (temp_s0 != 0) {
                    func_80105844(&sp10, arg0, temp_s0 - 1);
                    if (_getItemStat(arg1, &sp10) == var_s4) {
                        sp40[var_s6++] = temp_s0;
                        temp_s7[i] = 0;
                    }
                }
            }
        }
        vs_battle_memcpy(temp_s7, sp40, temp_s5 * 2);
    }
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105ACC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80105D24);

INCLUDE_RODATA("build/src/MENU/MENUD.PRG/nonmatchings/234", D_80102910);

void func_80106464(int arg0, int arg1, int arg2)
{
    int var_s2;
    int temp_s0;

    var_s2 = 0x808080;
    func_800FFD64(arg0, arg1, 0x808080, 0);
    temp_s0 = arg1 - 0x20;
    func_800C6540("/", temp_s0, 0x808080, NULL);
    if ((arg2 * 2) < arg0) {
        var_s2 = 0x804020;
    }
    func_800FFD64(arg2, temp_s0, var_s2, 0);
}

void func_80106504(void)
{
    int i;
    int var_s1_2;

    for (i = 0; i < 2; ++i) {
        vs_battle_renderTextRaw(D_80109A08[i], (0x3A + i * 0x80) | 0x580000, NULL);
    }

    for (i = 0; i < 7; ++i, var_s1_2 += 0xC) {
        func_80106464(D_801022A0[i], ((0x64 + 0xC * i) << 16) | 0x70,
            func_80103070(i, &D_8010245C->unk105B0.unk0));
        vs_battle_renderTextRaw(D_80109A10[i], ((0x64 + 0xC * i) << 16) | 0xA0, NULL);
        func_80106464(D_80109944[i], ((0x64 + 0xC * i) << 16) | 0xF8,
            func_80103070(i, &D_8010245C->unkC430));
    }
}

int _getWeaponGemCount(int arg0)
{
    int i;
    vs_battle_inventoryWeapon* weapon = &vs_menuD_containerData->unk0.weapons[arg0];
    int count = 0;

    for (i = 0; i < vs_menuD_containerData->unk0.grips[weapon->grip - 1].gemSlots; ++i) {
        count += weapon->gems[i] != 0;
    }
    return count;
}

int _getShieldGemCount(int arg0)
{
    int i;
    vs_battle_inventoryShield* shield = &vs_menuD_containerData->unk0.shields[arg0];
    int count = 0;

    for (i = 0; i < shield->unk4.gemSlots; ++i) {
        count += shield->gems[i] != 0;
    }
    return count;
}

int func_801066DC(int arg0, int arg1)
{
    int temp_s0 = func_80103070(arg0, D_80109A88);
    int temp_s1 = arg1 + (temp_s0 + func_80103070(arg0, &D_8010245C->unk87B0));

    if (D_80109A7A != 0) {
        return D_80109944[arg0] < temp_s1;
    }
    return D_801022A0[arg0] < temp_s1;
}

int func_80106784(int arg0, int arg1)
{
    int i;

    for (i = 0; i < 64; ++i) {
        if (D_8010245C->unkC3B0[i] == 0) {
            break;
        }
    }

    if (arg0 == 0) {
        i += 2 + _getWeaponGemCount(arg1);
    }

    if (arg0 == 3) {
        i += _getShieldGemCount(arg1);
    }

    if (i >= 64) {
        return 1;
    }

    if (func_801066DC(arg0, 1) != 0) {
        return 2;
    }

    if (arg0 == 0) {
        if (func_801066DC(1, 1) != 0)
            return 2;
        if (func_801066DC(2, 1) != 0)
            return 2;
        if (func_801066DC(5, _getWeaponGemCount(arg1)) != 0)
            return 2;
    }

    if (arg0 == 3 && func_801066DC(5, _getShieldGemCount(arg1)) != 0) {
        return 2;
    }

    return 0;
}

void func_801068BC(int arg0)
{
    int temp_s0_2;
    int temp_s2;
    int temp_s0;

    temp_s0 = D_8010245C->unkC3B0[arg0];
    temp_s2 = temp_s0 >> 8;
    temp_s0_2 = (temp_s0 - 1) & 0xFF;
    func_801032AC(
        temp_s2 | 0x10, &vs_menuD_containerData->unk0, temp_s0_2, &D_8010245C->unk87B0);
    func_80102D80(temp_s2, temp_s0_2, &D_8010245C->unk87B0);
}

void func_80106948(int arg0, int arg1)
{
    func_801032AC(arg0 | 0x10, &D_8010245C->unk87B0, arg1, &vs_menuD_containerData->unk0);
    func_80102D80(arg0, arg1, &vs_menuD_containerData->unk0);
}

static int func_801069B0(int arg0, int arg1)
{
    int i;

    for (i = 0; i < 64; ++i) {
        if (D_8010245C->unkC3B0[i] == ((arg0 << 8) | (arg1 + 1))) {
            return i + 1;
        }
    }
    return 0;
}

static void func_80106A04(int arg0, int arg1)
{
    int i;
    u_short* var_v1;

    i = 0;
    var_v1 = (u_short*)D_8010245C + 0x61D8;
    for (i = 0; i < 64; ++i) {
        if (var_v1[i] == 0) {
            var_v1[i] = ((arg0 << 8) | (arg1 + 1));
            return;
        }
    }
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106A50);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106C64);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801071D8);

extern u_short D_8010952C[];
extern int D_80109A58;
extern char D_80109A5C;

int func_801072B0(int arg0)
{
    char* sp10[4];
    int sp20[2];
    int i;
    int temp_s0;

    if (arg0 != 0) {
        func_800C8E04(1);
        D_80109A7D = 5;
        D_801023E3 = 0;
        D_80109A58 = 0;
        D_80109A5C = 0;
        return 0;
    }

    temp_s0 = D_80109A5C;

    switch (temp_s0) {
    case 0:
        for (i = 0; i < 2; ++i) {
            sp10[i * 2] = (char*)&D_8010952C[D_8010952C[8 + i]];
            sp10[i * 2 + 1] = (char*)&D_8010952C[D_8010952C[D_80109A7A + 10]];
            sp20[i] = 0;
        }

        func_800FF0EC(2, 3, sp10, sp20);
        D_80109A5C = 1;
        break;
    case 1:
        func_800FF43C();
        D_80109A58 = func_800FF360() + 1;

        if (D_80109A58 != 0) {
            func_800FA810(0);
            func_800FA810(1);
            if (D_80109A58 == temp_s0) {
                vs_battle_playMenuSelectSfx();
                func_800FA8E0(0);
                func_80103D50(0);
            } else {
                vs_battle_playMenuLeaveSfx();
                if (D_80109A58 == 2) {
                    D_80109A58 = -1;
                }
            }
            D_80109A5C = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80109A58;
        }
    }
    return 0;
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80107490);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_801089BC);

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80108C6C);
