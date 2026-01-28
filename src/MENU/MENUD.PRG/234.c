#include "common.h"
#include "234.h"
#include "../../SLUS_010.40/main.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include <libetc.h>
#include <memory.h>

void _initContainerObject(int, int, vs_menu_containerData*);
int _getContainerItemId(int, int, vs_menu_containerData*);
int func_80103070(int, vs_menu_containerData*);
void func_801031A0(void);
int func_801032AC(int, vs_menu_containerData*, int, vs_menu_containerData*);
void func_801037D8(int, func_80102C94_t*);
int func_80104114(int, int);
int func_80106C64(int, char**, int*, void*);

extern u_long* D_1F800000[];

extern u_short D_8010952C[];
extern char D_8010957C[];
extern u_short D_80109944[];
extern char* D_80109954;
extern int (*D_80109958[])(int);
extern char D_80109970[];
extern char D_80109990[];
extern char D_801099D0[];
extern char D_801099D4[];
extern char* D_801099DC[];
extern char D_801099F8[];
extern char D_80109A04[];
extern char D_80109A07;
extern char* D_80109A08[];
extern char* D_80109A10[];
extern char D_80109A2C;
extern char D_80109A2D;
extern char D_80109A2E;
extern char D_80109A30;
extern char D_80109A31;
extern char D_80109A32;
extern u_char D_80109A33;
extern char D_80109A34;
extern char D_80109A35;
extern char D_80109A36;
extern char D_80109A37;
extern u_char D_80109A38;
extern char D_80109A39;
extern char D_80109A3A;
extern char D_80109A3B;
extern u_char D_80109A3C;
extern char D_80109A3D;
extern char D_80109A43;
extern char D_80109A44;
extern char D_80109A45;
extern u_char D_80109A46;
extern u_char D_80109A47;
extern u_char D_80109A48;
extern u_char D_80109A49;
extern u_char D_80109A4A;
extern u_char D_80109A4B;
extern char D_80109A4C;
extern u_char D_80109A4D;
extern char D_80109A4E;
extern char D_80109A4F;
extern u_char D_80109A50;
extern char D_80109A51;
extern u_char D_80109A52;
extern char D_80109A53;
extern char D_80109A54;
extern int D_80109A58;
extern char D_80109A5C;
extern char D_80109A60[];
extern char D_80109A61;
extern char D_80109A68;
extern char D_80109A69;
extern char D_80109A6A;
extern int D_80109A6C;
extern char D_80109A70;
extern u_char D_80109A7A;
extern char D_80109A7B;
extern char D_80109A7C;
extern char D_80109A7D;
extern char D_80109A7E;
extern char D_80109A81;
extern u_short D_80109A82;
extern int D_80109A84;
extern func_80102C94_t* D_80109A88;

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
    return arg1->indices.weapons + var_a3;
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

void _initContainerObject(int type, int index, vs_menu_containerData* container)
{
    int i;

    switch (type) {
    case 0: {
        vs_battle_inventoryWeapon* weapon = &container->weapons[index];

        _initContainerObject(1, weapon->blade - 1, container);
        _initContainerObject(2, weapon->grip - 1, container);

        for (i = 0; i < 3; ++i) {
            int g = weapon->gems[i];
            if (g != 0) {
                _initContainerObject(5, g - 1, container);
            }
        }

        vs_battle_rMemzero(weapon, sizeof *weapon);
        weapon->unk0 = index + 1;
        break;
    }
    case 1: {
        vs_battle_inventoryBlade* blade = &container->blades[index];
        vs_battle_rMemzero(blade, sizeof *blade);
        blade->index = index + 1;
        break;
    }
    case 2: {
        vs_battle_inventoryGrip* grip = &container->grips[index];
        vs_battle_rMemzero(grip, sizeof *grip);
        grip->unkE = index + 1;
        break;
    }
    case 3: {
        vs_battle_inventoryShield* shield = &container->shields[index];

        for (i = 0; i < 3; ++i) {
            int g = shield->gems[i];
            if (g != 0) {
                _initContainerObject(5, g - 1, container);
            }
        }

        vs_battle_rMemzero(shield, sizeof *shield);
        shield->unk0 = index + 1;
        break;
    }
    case 4: {
        vs_battle_inventoryArmor* armor = &container->armor[index];
        vs_battle_rMemzero(armor, sizeof *armor);
        armor->index = index + 1;
        break;
    }
    case 5: {
        vs_battle_inventoryGem* gem = &container->gems[index];
        vs_battle_rMemzero(gem, sizeof *gem);
        gem->unk1A = index + 1;
        break;
    }
    case 6: {
        vs_battle_inventoryItem* item = &container->items[index];
        vs_battle_rMemzero(item, sizeof *item);
        item->unk3 = index + 1;
        break;
    }
    }
}

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

    vs_battle_memcpy(&temp_s2->items, D_80109A88->data.items, sizeof temp_s2->items);

    for (var_a2 = D_8010245C->unkC3B0[0], i = 0; var_a2 != 0;
         ++i, var_a2 = D_8010245C->unkC3B0[i]) {
        if ((var_a2 >> 8) == 6) {
            func_801032AC(0x16, temp_s2, (var_a2 - 1) & 0xFF, &D_8010245C->unk87B0);
        }
    }
}

static void func_80103270(void)
{
    func_801031A0();
    D_80109A82 = func_80103070(6, &D_8010245C->unk4BB0);
}

int func_801032AC(
    int arg0, vs_menu_containerData* arg1, int arg2, vs_menu_containerData* arg3)
{
    int temp_fp;
    int temp_s2;
    int temp_s3;
    int temp_s7;
    int i;
    int var_s1;
    int var_s1_2;
    int var_s5;
    vs_battle_inventoryArmor* temp_s0_4;
    vs_battle_inventoryArmor* new_var3;
    vs_battle_inventoryBlade* temp_s0_2;
    vs_battle_inventoryBlade* new_var;
    vs_battle_inventoryGem* temp_s0_5;
    vs_battle_inventoryGem* new_var4;
    vs_battle_inventoryGrip* temp_s0_3;
    vs_battle_inventoryGrip* new_var2;
    vs_battle_inventoryItem* temp_a0;
    vs_battle_inventoryItem* temp_a1;
    vs_battle_inventoryShield* temp_s3_3;
    vs_battle_inventoryShield* temp_s4_2;
    vs_battle_inventoryWeapon* temp_s3_2;
    vs_battle_inventoryWeapon* temp_s4;

    temp_s3 = arg0 >> 8;
    temp_fp = (arg0 >> 4) & 1;
    arg0 = arg0 & 0xF;
    var_s5 = 0;
    temp_s7 = func_80103070(arg0, arg1);
    temp_s2 = func_80103110(arg0, arg1);

    switch (arg0) {
    case 0:
        temp_s4 = &arg3->weapons[arg2];
        temp_s3_2 = &arg1->weapons[temp_s2];

        if (((temp_s7 != 0x20) && (func_80103070(1, arg1) != 0x40))
            && (func_80103070(2, arg1) != 0x40)) {

            var_s1 = 0;

            for (i = 0; i < 3; ++i) {
                if (temp_s4->gems[i] != 0) {
                    ++var_s1;
                }
            }

            if ((func_80103070(5, arg1) + var_s1) >= 0xC1) {
                break;
            }

            var_s5 = temp_s2 + 1;

            if (temp_fp != 0) {
                vs_battle_rMemzero(temp_s3_2, 0x20);
                temp_s3_2->unk0 = var_s5;
                temp_s3_2->blade =
                    func_801032AC((var_s5 << 8) | 0x11, arg1, temp_s4->blade - 1, arg3);
                temp_s3_2->grip =
                    func_801032AC((var_s5 << 8) | 0x12, arg1, temp_s4->grip - 1, arg3);
                for (i = 0; i < 3; ++i) {
                    if (temp_s4->gems[i] != 0) {
                        temp_s3_2->gems[i] = func_801032AC(
                            (var_s5 << 8) | 0x15, arg1, temp_s4->gems[i] - 1, arg3);
                    }
                }
                vs_battle_rMemcpy(temp_s3_2->name, temp_s4->name, 0x18);
            }
        }
        break;
    case 1:
        new_var = &arg3->blades[arg2];
        temp_s0_2 = &arg1->blades[temp_s2];
        if (temp_s7 == 0x40) {
            break;
        }
        var_s5 = temp_s2 + 1;
        if (temp_fp != 0) {
            vs_battle_copyAligned(temp_s0_2, new_var, 0x2C);
            temp_s0_2->index = var_s5;
            temp_s0_2->unk2A = temp_s3;
        }
        break;
    case 2:
        new_var2 = &arg3->grips[arg2];
        temp_s0_3 = &arg1->grips[temp_s2];

        if (temp_s7 == 0x40) {
            break;
        }

        var_s5 = temp_s2 + 1;

        if (temp_fp != 0) {
            vs_battle_copyAligned(temp_s0_3, new_var2, 0x10);
            temp_s0_3->unkE = var_s5;
            temp_s0_3->unkC = temp_s3;
        }
        break;
    case 3:
        temp_s4_2 = &arg3->shields[arg2];
        temp_s3_3 = &arg1->shields[temp_s2];

        if (temp_s7 == 0x20) {
            break;
        }

        var_s1_2 = 0;

        for (i = 0; i < 3; ++i) {
            if (temp_s4_2->gems[i] != 0) {
                ++var_s1_2;
            }
        }

        if ((func_80103070(5, arg1) + var_s1_2) >= 0xC1) {
            break;
        }

        var_s5 = temp_s2 + 1;

        if (temp_fp != 0) {
            vs_battle_rMemzero(temp_s3_3, 0x30);
            vs_battle_copyAligned(&temp_s3_3->unk4, &temp_s4_2->unk4, 0x28);
            temp_s3_3->unk0 = var_s5;
            for (i = 0; i < 3; ++i) {
                if (temp_s4_2->gems[i] != 0) {
                    temp_s3_3->gems[i] = func_801032AC(((var_s5 | 0x80) << 8) | 0x15,
                        arg1, temp_s4_2->gems[i] - 1, arg3);
                }
            }
        }
        break;
    case 4:
        new_var3 = &arg3->armor[arg2];
        temp_s0_4 = &arg1->armor[temp_s2];
        if (temp_s7 == 0x40) {
            break;
        }
        var_s5 = temp_s2 + 1;
        if (temp_fp != 0) {
            vs_battle_copyAligned(temp_s0_4, new_var3, 0x28);
            temp_s0_4->index = var_s5;
        }
        break;
    case 5:
        new_var4 = &arg3->gems[arg2];
        temp_s0_5 = &arg1->gems[temp_s2];
        if (temp_s7 == 0xC0) {
            break;
        }
        var_s5 = temp_s2 + 1;
        if (temp_fp != 0) {
            vs_battle_copyAligned(temp_s0_5, new_var4, 0x1C);
            temp_s0_5->unk1A = var_s5;
            temp_s0_5->unk18 = temp_s3;
        }
        break;
    case 6:
        temp_a0 = arg1->items;
        temp_a1 = &arg3->items[arg2];
        var_s1 = temp_a1->unk2;

        for (i = 0; i < 256; ++i) {
            if (temp_a0[i].id == temp_a1->id) {
                if (temp_fp != 0) {
                    if ((0x64 - temp_a0[i].unk2) >= var_s1) {
                        temp_a0[i].unk2 = temp_a0[i].unk2 + var_s1;
                        var_s1 = 0;
                    } else {
                        int v0 = var_s1 - 0x64;
                        var_s1 = v0 + temp_a0[i].unk2;
                        temp_a0[i].unk2 = 0x64;
                    }
                } else {
                    int v0 = var_s1 - 0x64;
                    var_s1 = v0 + temp_a0[i].unk2;
                    if (var_s1 < 0) {
                        var_s1 = 0;
                    }
                }
            }
        }

        if (var_s1 == 0) {
            var_s5 = 1;
            break;
        }
        if (temp_s7 == 0x100) {
            break;
        }
        var_s5 = temp_s2 + 1;
        if (temp_fp != 0) {
            temp_a0[temp_s2].id = temp_a1->id;
            temp_a0[temp_s2].unk2 = var_s1;
        }
        break;
    }
    return var_s5;
}

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
            && (_getContainerItemId(arg0, temp_a1 - 1, &arg1->data) == 0)) {
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
            for (var_a1 = i + 1; var_a1 < temp_s2; ++var_a1) {
                if (temp_s3[var_a1] != 0) {
                    break;
                }
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
        if ((_getContainerItemId(arg0, i, &arg1->data) != 0)
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

    vs_battle_rMemzero(&container->data, sizeof container->data);
    vs_battle_rMemzero(
        &D_8010245C->unk105B0.indices, sizeof D_8010245C->unk105B0.indices);

    for (i = 0; i < 7; ++i) {
        int j;
        char* temp_s0 = D_801022A8[i];
        u_short* temp_a1 = func_80102C94(i, container);

        for (j = 0; j < D_801022A0[i]; ++j) {
            temp_a1[j] = temp_s0[j];
        }
    }

    vs_battle_memcpy(
        container->data.weapons, inventory->weapons, sizeof container->data.weapons / 4);
    vs_battle_memcpy(
        container->data.blades, inventory->blades, sizeof container->data.blades / 4);
    vs_battle_memcpy(
        container->data.grips, inventory->grips, sizeof container->data.grips / 4);
    vs_battle_memcpy(
        container->data.shields, inventory->shields, sizeof container->data.shields / 4);
    vs_battle_memcpy(
        container->data.armor, inventory->armor, sizeof container->data.armor / 4);
    vs_battle_memcpy(
        container->data.gems, inventory->gems, sizeof container->data.gems / 4);
    vs_battle_memcpy(
        container->data.items, inventory->items, sizeof container->data.items / 4);
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
        inventory->weapons, temp_s2->data.weapons, sizeof inventory->weapons);
    vs_battle_memcpy(inventory->blades, temp_s2->data.blades, sizeof inventory->blades);
    vs_battle_memcpy(inventory->grips, temp_s2->data.grips, sizeof inventory->grips);
    vs_battle_memcpy(
        inventory->shields, temp_s2->data.shields, sizeof inventory->shields);
    vs_battle_memcpy(inventory->armor, temp_s2->data.armor, sizeof inventory->armor);
    vs_battle_memcpy(inventory->gems, temp_s2->data.gems, sizeof inventory->gems);
    vs_battle_memcpy(inventory->items, temp_s2->data.items, sizeof inventory->items);
}

int func_80103C9C(int arg0, int arg1, vs_menu_containerData* arg2)
{
    int var_v1 = 0;
    if (arg0 == 1) {
        var_v1 = arg2->blades[arg1].unk2A;
    }
    if (arg0 == 2) {
        var_v1 = arg2->grips[arg1].unkC;
    }
    if (arg0 == 5) {
        var_v1 = arg2->gems[arg1].unk18;
        if (var_v1 & 0x80) {
            var_v1 = 0;
        }
    }
    return var_v1;
}

static int func_80103D14(int arg0, int arg1, vs_menu_containerData* arg2)
{
    u_short ret = 0;
    if (arg0 == 5) {
        ret = arg2->gems[arg1].unk18;
        if (!(arg2->gems[arg1].unk18 & 0x80)) {
            ret = 0;
        }
    }
    return ret & 0x7F;
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
        temp_a1 = func_80103070(arg0, &vs_menuD_containerData->data);
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

int func_80104114(int arg0, int arg1)
{
    D_800F4EE8.unk0[(arg0 + 0x51) * 2] = 0;
    D_800F4EE8.unk0[(arg0 + 0x51) * 2 + 1] = arg1;
    return func_80102C94(arg0, vs_menuD_containerData)[arg1];
}

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

int func_801042D0(int arg0)
{
    char* sp18[2];
    int sp20;
    int temp_v0_2;
    int i;

    if (arg0 != 0) {
        D_80109A32 = arg0 >> 8;
        D_80109A33 = arg0 - 1;
        func_80103F64(D_80109A32);
        D_80109A34 = 0;
        D_80109A31 = 0;
        D_80109A30 = 0;
        return 0;
    }

    switch (D_80109A30) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80104034(D_80109A32, 7);
            func_800FD270(vs_menuD_containerData->indices.weapons[D_80109A33]);
            vs_mainMenu_drawDpPpbars(3);
            D_80109A30 = 1;
        }
        break;
    case 1:
        if (D_80109A31 < 10) {
            ++D_80109A31;
            if (D_80109A31 < 6) {
                func_800FC510(
                    D_80109A31, vs_menuD_containerData->indices.weapons[D_80109A33], 1);
            }
            break;
        }
        D_80109A30 = 2;
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80104170(1);
            D_80109A30 = 3;
        } else {
            temp_v0_2 = func_80103D6C(0, D_80109A33);
            if (temp_v0_2 != D_80109A33) {
                D_80109A33 = temp_v0_2;
                i = func_80104114(0, temp_v0_2);
                func_801041E0(&vs_menuD_containerData->data, sp18, &sp20,
                    vs_battle_stringBuf, i - 1);
                func_800FD270(i);

                func_80104078(D_80109A32, sp18, sp20, temp_v0_2);
                for (i = 1; i < 6; ++i) {
                    func_800FC510(
                        i, vs_menuD_containerData->indices.weapons[temp_v0_2], 0);
                }
            }
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_80104534(int arg0)
{
    func_800FD0E0_t sp10;
    int sp18;
    int temp_v0_2;
    int temp_v0_3;

    if (arg0 != 0) {
        D_80109A37 = arg0 >> 8;
        D_80109A38 = arg0 - 1;
        func_80103F64(D_80109A37);
        D_80109A36 = 10;
        D_80109A35 = 0;
        return 0;
    }

    switch (D_80109A35) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80104034(D_80109A37, 3);
            func_800FD404(vs_menuD_containerData->indices.blades[D_80109A38]);
            vs_mainMenu_drawDpPpbars(3);
            D_80109A35 = 1;
        }
        break;
    case 1:
        if (D_80109A36 != 0) {
            --D_80109A36;
        } else {
            D_80109A35 = 2;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80104170(1);
            D_80109A35 = 3;
        } else {
            temp_v0_2 = func_80103D6C(1, D_80109A38);
            if (temp_v0_2 != D_80109A38) {
                D_80109A38 = temp_v0_2;
                temp_v0_3 = func_80104114(1, temp_v0_2);
                func_800FCAA4(&vs_menuD_containerData->data.blades[temp_v0_3 - 1], &sp10,
                    &sp18, vs_battle_stringBuf);
                func_800FD404(temp_v0_3);
                func_80104078(D_80109A37, &sp10.unk0, sp18, temp_v0_2);
            }
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_80104728(int arg0)
{
    func_800FD0E0_t sp10;
    int sp18;
    int temp_v0_2;
    int temp_v0_3;

    if (arg0 != 0) {
        D_80109A3B = arg0 >> 8;
        D_80109A3C = arg0 - 1;
        func_80103F64(D_80109A3B);
        D_80109A3D = 0;
        D_80109A3A = 0;
        D_80109A39 = 0;
        return 0;
    }
    switch (D_80109A39) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80104034(D_80109A3B, 4);
            func_800FD504(vs_menuD_containerData->indices.grips[D_80109A3C]);
            D_80109A39 = 1U;
        }
        break;
    case 1:
        if (D_80109A3A < 0xAU) {
            D_80109A3A = (D_80109A3A + 1);
        } else {
            D_80109A39 = 2U;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80104170(0);
            D_80109A39 = 3U;
        } else {
            temp_v0_2 = func_80103D6C(2, D_80109A3C);
            if (temp_v0_2 != D_80109A3C) {
                D_80109A3C = temp_v0_2;
                temp_v0_3 = func_80104114(2, temp_v0_2);
                func_800FCC0C(&vs_menuD_containerData->data.grips[temp_v0_3 - 1], &sp10,
                    &sp18, vs_battle_stringBuf);
                func_800FD504(temp_v0_3);
                func_80104078(D_80109A3B, &sp10.unk0, sp18, temp_v0_2);
            }
        }
        D_80109954[6] = (vs_menuD_containerData->data
                             .grips[vs_menuD_containerData->indices.grips[D_80109A3C] - 1]
                             .gemSlots
                         + 0x30);
        func_80100004(0x116, 0x100, 0x20);
        vs_battle_renderTextRaw(D_80109954, 0x240118, NULL);
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

void func_800FC704(int, int, int);
void func_800FD5A0(int);
extern char D_80109A3E;
extern char D_80109A3F;
extern char D_80109A40;
extern u_char D_80109A41;
extern char D_80109A42;

int func_8010496C(int arg0)
{
    char* sp18[2];
    int sp20;
    int temp_v0_2;
    int i;

    if (arg0 != 0) {
        D_80109A40 = arg0 >> 8;
        D_80109A41 = arg0 - 1;
        func_80103F64(D_80109A40);
        D_80109A42 = 0;
        D_80109A3F = 0;
        D_80109A3E = 0;
        return 0;
    }

    switch (D_80109A3E) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80104034(D_80109A40, 7);
            func_800FD5A0(vs_menuD_containerData->indices.shields[D_80109A41]);
            vs_mainMenu_drawDpPpbars(3);
            D_80109A3E = 1;
        }
        break;
    case 1:
        if (D_80109A3F < 10) {
            ++D_80109A3F;
            if (D_80109A3F < 4) {
                func_800FC704(
                    D_80109A3F, vs_menuD_containerData->indices.shields[D_80109A41], 1);
            }
            break;
        }
        if (vs_mainmenu_ready() != 0) {
            D_80109A3E = 2;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80104170(1);
            D_80109A3E = 3;
        } else {
            temp_v0_2 = func_80103D6C(3, D_80109A41);
            if (temp_v0_2 != D_80109A41) {
                D_80109A41 = temp_v0_2;
                i = func_80104114(3, temp_v0_2);
                func_8010425C(&vs_menuD_containerData->data, sp18, &sp20,
                    vs_battle_stringBuf, i - 1);
                func_800FD5A0(i);
                func_80104078(D_80109A40, sp18, sp20, temp_v0_2);
                for (i = 1; i < 4; ++i) {
                    func_800FC704(
                        i, vs_menuD_containerData->indices.shields[temp_v0_2], 0);
                }
                return 0;
            }
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_80104BDC(int arg0)
{
    char* sp10[2];
    int sp18;
    int temp_v0_2;
    int temp_v0_3;

    if (arg0 != 0) {
        D_80109A45 = arg0 >> 8;
        D_80109A46 = (arg0 - 1);
        func_80103F64(D_80109A45);
        D_80109A44 = 10;
        D_80109A43 = 0;
        return 0;
    }

    switch (D_80109A43) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80104034(D_80109A45, 7);
            func_800FD700(vs_menuD_containerData->indices.armor[D_80109A46]);
            if (vs_battle_inventory
                    .armor[vs_menuD_containerData->indices.armor[D_80109A46] - 1]
                    .category
                != 7) {
                vs_mainMenu_drawDpPpbars(1);
            }
            D_80109A43 = 1;
        }
        break;
    case 1:
        if (D_80109A44 != 0) {
            D_80109A44 = (D_80109A44 - 1);
        } else {
            D_80109A43 = 2;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80104170(1);
            D_80109A43 = 3;
        } else {
            temp_v0_2 = func_80103D6C(4, D_80109A46);
            if (temp_v0_2 != D_80109A46) {
                D_80109A46 = temp_v0_2;
                temp_v0_3 = func_80104114(4, temp_v0_2);
                vs_mainMenu_setAccessoryStrings(
                    &vs_menuD_containerData->data.armor[temp_v0_3 - 1], sp10, &sp18,
                    vs_battle_stringBuf);
                func_800FD700(temp_v0_3);
                func_80104078(D_80109A45, sp10, sp18, temp_v0_2);
            }
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_80104E14(int arg0)
{
    func_800FD0E0_t sp10;
    int sp18;
    int temp_v0_2;
    int temp_v0_3;

    if (arg0 != 0) {
        D_80109A49 = arg0 >> 8;
        D_80109A4A = arg0 - 1;
        func_80103F64(D_80109A49);
        D_80109A48 = 10;
        D_80109A47 = 0;
        return 0;
    }

    switch (D_80109A47) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80104034(D_80109A49, 3);
            func_800FD878(vs_menuD_containerData->indices.gems[D_80109A4A]);
            D_80109A47 = 1;
        }
        break;
    case 1:
        if (D_80109A48 != 0) {
            D_80109A48 -= 1;
        } else {
            D_80109A47 = 2;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80104170(0);
            D_80109A47 = 3U;
            D_80109A84 = vs_main_buttonsPressed.all & 0x10;
        } else {
            temp_v0_2 = func_80103D6C(5, D_80109A4A);
            if (temp_v0_2 != D_80109A4A) {
                D_80109A4A = temp_v0_2;
                temp_v0_3 = func_80104114(5, temp_v0_2);
                func_800FD0E0(&vs_menuD_containerData->data.gems[temp_v0_3 - 1], &sp10,
                    &sp18, vs_battle_stringBuf);
                func_800FD878(temp_v0_3);
                func_80104078(D_80109A49, &sp10.unk0, sp18, temp_v0_2);
            }
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_80105008(int arg0)
{
    int temp_v0;
    int var_s0 = 0;

    if (arg0 != 0) {
        var_s0 = arg0 >> 4;
        D_80109A4B = arg0 & 0xF;
        D_80109A81 = 1;
        D_80109A84 = 0;
        func_800FDD78();
        vs_battle_getMenuItem(0x1F)->unkE = var_s0 & 0xFF;
        func_800FFA88(0);
    }

    temp_v0 = D_80109958[D_80109A4B](var_s0);

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

    temp_s6 = vs_menuD_containerData->data.weapons;
    temp_s7 = func_80102C94(0, vs_menuD_containerData);
    vs_battle_rMemzero(sp1A8, 0x40);
    var_s5 = 0;

    while (1) {
        var_s4 = 0x80000000;
        for (i = 0; i < 32; ++i) {
            temp_s0 = temp_s7[i];
            if (temp_s0 != 0) {
                func_80102A34(
                    &sp10, &temp_s6[temp_s0 - 1], &vs_menuD_containerData->data);
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
                    &sp10, &temp_s6[temp_s0 - 1], &vs_menuD_containerData->data);
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

    vs_battle_inventoryShield* temp_s5 = vs_menuD_containerData->data.shields;
    u_short* temp_s6 = func_80102C94(3, vs_menuD_containerData);
    int var_s4 = 0;

    vs_battle_rMemzero(&sp178, sizeof sp178);

    while (1) {
        var_s3 = 0x80000000;

        for (i = 0; i < 32; ++i) {
            temp_s0 = temp_s6[i];
            if (temp_s0 != 0) {
                func_80102BB0(
                    &sp10, &temp_s5[temp_s0 - 1], &vs_menuD_containerData->data);
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
                    &sp10, &temp_s5[temp_s0 - 1], &vs_menuD_containerData->data);
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

    item = vs_menuD_containerData->data.items;
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
            item, &vs_menuD_containerData->data.blades[index]);
        return;
    case 2:
        vs_battle_copyInventoryGripStats(
            item, &vs_menuD_containerData->data.grips[index]);
        return;
    case 4:
        vs_battle_copyInventoryArmorStats(
            item, &vs_menuD_containerData->data.armor[index]);
        return;
    case 5:
        vs_battle_copyInventoryGemStats(item, &vs_menuD_containerData->data.gems[index]);
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

int func_80105ACC(int arg0)
{
    char* sp10[48];
    int spD0[24];
    int i;
    char* new_var;

    if (arg0 != 0) {
        D_80109A4D = arg0 - 1;
        D_80109A4C = 0;
        return 0;
    }
    switch (D_80109A4C) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            new_var = D_801099DC[D_80109A4D];

            for (i = 0; i < D_801099D4[D_80109A4D]; ++i) {
                sp10[i * 2] =
                    (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[*(new_var + i) * 2
                                                                      + 438]];
                sp10[i * 2 + 1] =
                    (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[*(new_var + i) * 2
                                                                      + 439]];
                spD0[i] = 0;
            }
            func_800FF0EC(i, D_80109A4D + 0x60, sp10, spD0);
            D_80109A4C = 1;
        }
        break;
    case 1:
        func_800FF43C();
        i = func_800FF360();
        if ((i + 1) != 0) {
            if (i >= 0) {
                vs_battle_playMenuSelectSfx();
                switch (D_80109A4D) {
                case 0:
                    func_801051F8(D_80109970[i]);
                    break;
                case 3:
                    func_80105454(D_80109990[i]);
                    break;
                case 6:
                    func_801055F0(D_801099D0[i]);
                    break;
                default:
                    func_8010592C(D_80109A4D, D_801099DC[D_80109A4D][i]);
                    break;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i + 1;
        }
        break;
    }
    return 0;
}

int func_80105D24(int arg0)
{
    char* sp18[4];
    int sp28[2];
    char* sp30[4];
    int sp40[2];
    int i;
    int temp_v0_7;
    int temp_v0_8;
    int var_v0;
    int a2;
    vs_battle_menuItem_t* temp_v0_4;
    int a0;

    if (arg0 != 0) {
        D_80109A51 = arg0 >> 0x10;
        D_80109A4F = (arg0 >> 0xC) & 0xF;
        D_80109A50 = arg0 - 1;
        func_800C8E04(1);
        vs_mainmenu_setMessage(
            (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[D_80109A51 + 554]]);
        D_80109A4E = 0;
        return 0;
    }
    switch (D_80109A4E) {
    case 0:
        var_v0 = 0;
        if ((D_800F5130 >> 0x1E) & 1) {
            if (vs_mainmenu_ready() != 0) {
                D_80109A4E = ((D_80109A51 & 1) + 1);
            }
        }
        break;
    case 1:
        for (i = 0; i < 2; ++i) {
            sp18[i * 2] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[552 + i]];
            sp18[i * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[D_80109A51 + 554]];
            sp28[i] = 0;
        }

        func_800FF0EC(2, 4, sp18, sp28);
        D_80109A4E = 3;
        break;
    case 2:
        D_80109A54 = vs_menuD_containerData->data.items[D_80109A50].unk2;
        i = vs_battle_toBCD(D_80109A54);
        D_801099F8[8] = i & 0xF;
        i = vs_battle_toBCD(i >> 4);

        D_801099F8[7] = i & 0xF;
        D_801099F8[6] = i >> 4;

        for (i = 2; i < 5; ++i) {
            D_801099F8[i] = 0;
        }

        temp_v0_4 = vs_battle_setMenuItem(0x22, -0x7E, 0x82, 0x7E, 0, D_801099F8);
        temp_v0_4->state = 5;
        temp_v0_4->x = 0;
        D_80109A52 = 0;
        D_80109A53 = 0;
        D_80109A4E = 4;
        break;
    case 3:
        func_800FF43C();
        i = func_800FF360() + 1;
        if (i != 0) {
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0x1C);
                _initContainerObject(
                    (int)D_80109A4F, (int)D_80109A50, &vs_menuD_containerData->data);
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i;
        }
        break;
    case 4:
        if (vs_mainmenu_ready() != 0) {
            for (i = 2; i < 5; ++i) {
                D_801099F8[i] = 0x8F;
            }
            vs_battle_setMenuItem(0x22, 0, 0x82, 0x7E, 0, D_801099F8);
            D_80109A4E = 5U;
        case 5:
            if (vs_main_buttonsPressed.all & 0x70) {
                i = vs_battle_toBCD((int)D_80109A53);
                D_801099F8[4] = i & 0xF;
                i = vs_battle_toBCD(i >> 4);
                D_801099F8[3] = i & 0xF;
                D_801099F8[2] = i >> 4;
                vs_battle_setMenuItem(0x22, 0, 0x82, 0x7E, 0, D_801099F8);
                if (vs_main_buttonsPressed.all & 0x50) {
                    vs_battle_playMenuLeaveSfx();
                    if ((vs_main_buttonsPressed.all & 0x10)) {
                        return -2;
                    }
                    return -1;
                }
                if (D_80109A53 == 0) {
                    vs_battle_playMenuLeaveSfx();
                    return -1;
                }
                vs_battle_playMenuSelectSfx();
                D_80109A4E = 6;
                break;
            }

            i = 0;
            a0 = a2 = D_80109A53;
            if (vs_main_buttonRepeat & 0x1000) {
                i = 1;
            }
            if (vs_main_buttonRepeat & 0x4000) {
                --i;
            }
            if (i == 1) {
                a0 = D_80109A53 + D_80109A04[D_80109A52];
            } else if (i == -1) {
                a0 = D_80109A53 - D_80109A04[D_80109A52];
            }
            if (a0 >= 0) {
                if (D_80109A54 >= a0) {
                    D_80109A53 = a0;
                }
            }
            i = 0;
            a0 = D_80109A52;
            if (vs_main_buttonRepeat & 0x2000) {
                i = -1;
            }
            if (vs_main_buttonRepeat & 0x8000) {
                ++i;
            }
            if (i == 1) {
                if ((a0 & 0xFF) == 2) {
                    if (D_80109A53 != D_80109A54) {
                        D_80109A53 = D_80109A54;
                    }
                } else {
                    D_80109A52 = a0 + 1;
                }
            } else if (i == -1) {
                if (!(a0 & 0xFF)) {
                    if (D_80109A53 != 0) {
                        D_80109A53 = 0;
                    }
                } else {
                    D_80109A52 = a0 - 1;
                }
            }
            if ((a0 != D_80109A52) || (a2 != D_80109A53)) {
                vs_battle_playMenuChangeSfx();
            }
            func_800C7210(5);
            temp_v0_7 = vs_battle_toBCD(D_80109A53);
            func_800C70F8(temp_v0_7 & 0xF, 0x42, 0x82, D_1F800000[2] - 3);
            temp_v0_8 = vs_battle_toBCD(temp_v0_7 >> 4);
            func_800C70F8(temp_v0_8 & 0xF, 0x3C, 0x82, D_1F800000[2] - 3);
            func_800C70F8(temp_v0_8 >> 4, 0x36, 0x82, D_1F800000[2] - 3);
            D_80109A07 = func_800FFCDC(D_80109A07, (0x36 - (D_80109A52 * 6)) | 0x720000);
        }
        break;
    case 6:

        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                sp30[i * 2] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[552 + i]];
                sp30[i * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x2E49];
                sp40[i] = 0;
            }

            func_800FF0EC(2, 4, sp30, sp40);
            D_80109A4E = 7;
        }
        break;
    case 7:
        func_800FF43C();
        i = func_800FF360() + 1;
        if (i != 0) {
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0x1C);
                if (vs_menuD_containerData->data.items[D_80109A50].unk2 == D_80109A53) {
                    _initContainerObject(
                        D_80109A4F, D_80109A50, &vs_menuD_containerData->data);
                } else {
                    vs_menuD_containerData->data.items[D_80109A50].unk2 -= D_80109A53;
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
            func_80103070(i, &D_8010245C->unk105B0.data));
        vs_battle_renderTextRaw(D_80109A10[i], ((0x64 + 0xC * i) << 16) | 0xA0, NULL);
        func_80106464(D_80109944[i], ((0x64 + 0xC * i) << 16) | 0xF8,
            func_80103070(i, &D_8010245C->unkC430.data));
    }
}

int _getWeaponGemCount(int arg0)
{
    int i;
    vs_battle_inventoryWeapon* weapon = &vs_menuD_containerData->data.weapons[arg0];
    int count = 0;

    for (i = 0; i < vs_menuD_containerData->data.grips[weapon->grip - 1].gemSlots; ++i) {
        count += weapon->gems[i] != 0;
    }
    return count;
}

int _getShieldGemCount(int arg0)
{
    int i;
    vs_battle_inventoryShield* shield = &vs_menuD_containerData->data.shields[arg0];
    int count = 0;

    for (i = 0; i < shield->unk4.gemSlots; ++i) {
        count += shield->gems[i] != 0;
    }
    return count;
}

int func_801066DC(int arg0, int arg1)
{
    int temp_s0 = func_80103070(arg0, &D_80109A88->data);
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
        temp_s2 | 0x10, &vs_menuD_containerData->data, temp_s0_2, &D_8010245C->unk87B0);
    _initContainerObject(temp_s2, temp_s0_2, &D_8010245C->unk87B0);
}

void func_80106948(int arg0, int arg1)
{
    func_801032AC(arg0 | 0x10, &D_8010245C->unk87B0, arg1, &vs_menuD_containerData->data);
    _initContainerObject(arg0, arg1, &vs_menuD_containerData->data);
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

void func_80106A50(void)
{
    int j;
    int var_a1;
    int i;
    int k;
    u_short* temp_s2 = D_8010245C->unkC3B0;

    for (i = 0; i < 64; ++i) {
        int temp_a1 = temp_s2[i];
        if ((temp_a1 != 0)
            && (_getContainerItemId(
                    (temp_a1 >> 8), (temp_a1 - 1) & 0xFF, &D_8010245C->unk87B0)
                == 0)) {
            temp_s2[i] = 0;
        }
    }

    i = 0;

    while (1) {
        if (temp_s2[i] != 0) {
            ++i;
            if (i == 0x3F) {
                break;
            }
        } else {
            for (var_a1 = i + 1; var_a1 < 0x40; ++var_a1) {
                if (temp_s2[var_a1] != 0) {
                    break;
                }
            }

            if (var_a1 == 0x40) {
                break;
            }

            for (j = var_a1; j < 0x40; ++j) {
                temp_s2[j + i - var_a1] = temp_s2[j];
            }

            for (j = j + (i - var_a1); j < 64; ++j) {
                temp_s2[j] = 0;
            }
        }
    }

    for (k = 0; k < 7; ++k) {
        for (i = 0; i < D_80109944[k]; ++i) {
            if ((_getContainerItemId(k, i, &D_8010245C->unk87B0) != 0)
                && (func_801069B0(k, i) == 0)) {
                func_80106A04(k, i);
            }
        }
    }
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80106C64);

void func_801071D8(int arg0)
{
    int temp_v0_2;
    int i;

    while (D_801023D0 < 16) {
        func_80100A5C();
    }

    for (i = 20; i < 40; ++i) {
        vs_battle_menuItem_t* temp_v0 = vs_battle_getMenuItem(i);
        if (temp_v0->state == 2) {
            temp_v0->state = 1;
            temp_v0->animSpeed = temp_v0->x;
        }
        temp_v0_2 = i ^ (D_800F4EE8.unk0[(arg0 + 81) * 2] + 20);
        temp_v0->selected = temp_v0_2 == 0;
    }
}

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

int func_80107490(int arg0)
{
    u_short* sp10[8];
    int temp_a0;
    int temp_s0;
    int temp_s2;
    int temp_s3;
    int temp_v0_17;
    int temp_v0_18;
    int temp_v0_8;
    int var_a1;
    int var_a2;
    int var_s4;
    int var_v0_3;
    int* temp_s1_3;
    int* temp_s1_4;
    int* temp_s6;
    char** temp_s0_2;
    char** temp_s3_7;
    char** temp_s5;
    u_short* temp_s1;
    void* temp_v0_19;
    void* temp_v0_7;
    vs_battle_menuItem_t* temp_v0_11;

loop_1:
    if (arg0 != 0) {
        D_80109A6A = 1;
        func_80103D50(1);
        D_80109A7E = 0;
        if (vs_main_settings.cursorMemory == 0) {
            memset(D_800F4EE8.unkA0, 0, sizeof D_800F4EE8.unkA0);
        }
        vs_battle_rMemzero(&D_8010245C->unk87B0, sizeof D_8010245C->unk87B0);
        vs_battle_rMemzero(D_8010245C->unkC3B0, sizeof D_8010245C->unkC3B0);
        D_80109A7A = arg0 - 1;
        if (D_80109A7A) {
            vs_menuD_containerData = &D_8010245C->unk105B0;
            D_80109A88 = &D_8010245C->unkC430;
        } else {
            vs_menuD_containerData = &D_8010245C->unkC430;
            D_80109A88 = &D_8010245C->unk105B0;
        }
        D_80109A68 = 1;
        return 0;
    }
    var_s4 = (D_800F4EE8.unkA0[0] - 1) & 7;
    temp_s1 = func_80102C94(var_s4, vs_menuD_containerData);

    switch (D_80109A68) { /* switch 1 */
    case 0:
        func_800FFBC8();
        /* fallthrough */
    case 1:
        temp_s1 = vs_main_allocHeapR(0x6C00U);
        temp_s6 = (void*)temp_s1 + 0x6000;
        temp_s5 = (void*)temp_s1 + 0x6400;
        D_801023E3 = 1;

        for (temp_s3 = 0; temp_s3 < 7; ++temp_s3) {
            func_801037D8(temp_s3, vs_menuD_containerData);
        }

        func_80106A50();
        temp_s2 = func_80106C64(var_s4, temp_s5, temp_s6, temp_s1);
        D_80109A69 = temp_s2 == 0;
        if (D_80109A69 != 0) {
            vs_mainmenu_setMessage((
                char*)&D_8010952C[D_8010952C[D_80109A7A + 27 + ((var_s4 == 7) ? 2 : 0)]]);
        } else {
            temp_s3 = vs_main_settings.cursorMemory;
            if (D_80109A6A == 0) {
                vs_main_settings.cursorMemory = 1;
            }
            D_80109A6A = 0;
            vs_mainmenu_setMenuRows(temp_s2, (var_s4 + 0x51) | 0x19200, temp_s5, temp_s6);
            if (D_80109A68 == 0) {
                func_801071D8(var_s4);
            }
            vs_main_settings.cursorMemory = temp_s3;
        }
        vs_main_freeHeapR(temp_s1);
        D_80109A68 = 2;
        break;
    case 2:
        D_80109A7D = 1;
        if (D_80109A69 != 0) {
            if (vs_main_buttonsPressed.all & 0x10) {
                vs_battle_playMenuLeaveSfx();
                return -2;
            }
            if (vs_main_buttonsPressed.all & 0x40) {
                vs_battle_playMenuLeaveSfx();
                if (D_8010245C->unkC3B0[0] == 0) {
                    return -1;
                }
                if (var_s4 == 7) {
                    func_801072B0(1);
                    D_80109A68 = 0xF;
                } else {
                    D_800F4EE8.unkA0[0] = 0;
                    func_800FA8E0(0);
                    D_80109A68 = 0xD;
                }
                break;
            }
            if (vs_main_buttonsPressed.all & 0xA0) {
                func_800C02E0();
            }
        } else {
            int s6 = 1;
            temp_s0 = var_s4 < 6;
            D_80109A7D = temp_s0 + 1;
            D_80109A6C = vs_mainmenu_getSelectedRow() + 1;
            if (D_80109A6C == 0) {
                if (vs_main_buttonsPressed.all & 0x80) {
                    if ((temp_s0 != 0) && (vs_mainmenu_ready() != 0)) {
                        vs_battle_playMenuSelectSfx();
                        temp_s0 = func_80100814();
                        vs_battle_getMenuItem(temp_s0 >> 8)->unkD = 0;
                        func_80105008(var_s4 | ((temp_s0 + s6) * 0x10));
                        D_80109A7B = 0;
                        D_80109A68 = 7;
                        break;
                    }
                    func_800C02E0();
                }
            } else if (D_80109A6C > 0) {
                if (var_s4 == 7) {
                    func_801068BC(D_80109A6C - 1);
                    func_80103270();
                    func_800FA8E0(0);
                    D_80109A68 = 4;
                } else {
                    temp_v0_7 = vs_main_allocHeapR(0x6C00U);
                    temp_s0_2 = temp_v0_7 + 0x6400;
                    temp_s1_3 = temp_v0_7 + 0x6000;
                    temp_s0 = func_80106C64(var_s4, temp_s0_2, temp_s1_3, temp_v0_7);
                    temp_s1_3[D_80109A6C - 1] |= 8;
                    temp_s3 = vs_main_settings.cursorMemory;
                    vs_main_settings.cursorMemory = 1;
                    vs_mainmenu_setMenuRows(
                        temp_s0, (var_s4 + 0x51) | 0x19200, temp_s0_2, temp_s1_3);
                    vs_main_settings.cursorMemory = temp_s3;
                    func_801071D8(var_s4);
                    D_80109A7D = 1;
                    D_801023E3 = 0;
                    vs_main_freeHeapR(temp_v0_7);
                    D_80109A68 = 6;
                }
            } else if (D_80109A6C == -2) {
                return -2;
            } else {
                if (D_8010245C->unkC3B0[0] == 0) {
                    func_800FA8E0(0);
                    return -1;
                }
                if (var_s4 != 7) {
                    D_800F4EE8.unkA0[0] = 0;
                    func_800FA8E0(0);
                    D_80109A68 = 0xD;
                } else {
                    func_801072B0(1);
                    D_80109A68 = 0xF;
                }
                break;
            }
        }
        // fallthrough
    case 3:
        temp_s3 = vs_main_buttonsState & 0x8004;
        temp_s2 = vs_main_buttonsState & 0x2008;
        temp_v0_8 = (temp_s3 != 0);
        if (temp_s2 != 0) {
            temp_s0 = temp_v0_8 ^ 1;
        } else {
            temp_s0 = temp_v0_8 & 1;
        }
        if (temp_s0 != 0) {
            var_a2 = 0x8004;
            if (temp_s3 == 0x8004) {
                var_a2 = 0x8000;
            }
            if (vs_main_buttonRepeat & var_a2) {
                var_s4 = (var_s4 - 1) & 7;
            }
            var_a2 = 0x2008;
            if (temp_s2 == 0x2008) {
                var_a2 = 0x2000;
            }
            var_v0_3 = vs_main_buttonRepeat & var_a2;
            if (var_v0_3 != 0) {
                var_s4 = (var_s4 + 1) & 7;
            }
            if (var_s4 != ((D_800F4EE8.unkA0[0] - 1) & 7)) {
                vs_battle_playMenuChangeSfx();
                D_800F4EE8.unkA0[0] = (var_s4 + 1) & 7;
                if (D_80109A68 == 2) {
                    if (D_80109A69 == 0) {
                        func_80100814();
                        func_800FA8E0(0);
                    }
                    D_80109A68 = 3;
                }
            }
        }
        if (D_80109A68 == 3) {
            if (vs_mainmenu_ready() != 0) {
                if (vs_main_buttonsState & 0xA00C) {
                    if (temp_s0 != 0) {
                        break;
                    }
                }
                D_80109A68 = 1;
                arg0 = 0;
                goto loop_1;
            }
        }
        break;
    case 4:
        if (vs_mainmenu_ready() != 0) {
            D_80109A68 = 1;
        }
        break;
    case 5:
        if (vs_mainmenu_ready() != 0) {
            D_80109A68 = 0;
        }
        break;
    case 6:
        if (vs_main_buttonsPressed.all & 0x80) {
            func_800C02E0();
        }
        temp_s3 = vs_mainmenu_getSelectedRow() + 1;
        if (temp_s3 != 0) {
            temp_s2 = D_80109A6C;
            if (temp_s2 == temp_s3) {
                D_80109A68 = 8;
                break;
            }
            if (temp_s3 > 0) {
                temp_s0 = temp_s1[temp_s3 - 1];
                var_a2 = temp_s1[temp_s2 - 1];
                if ((var_s4 == 6)
                    && (vs_menuD_containerData->data.items[temp_s0 - 1].id
                        == vs_menuD_containerData->data.items[var_a2 - 1].id)) {
                    vs_menuD_containerData->data.items[var_a2 - 1].unk2 +=
                        vs_menuD_containerData->data.items[temp_s0 - 1].unk2;
                    if (vs_menuD_containerData->data.items[var_a2 - 1].unk2 > 0x64) {
                        vs_menuD_containerData->data.items[temp_s0 - 1].unk2 =
                            vs_menuD_containerData->data.items[var_a2 - 1].unk2 - 0x64;
                        vs_menuD_containerData->data.items[var_a2 - 1].unk2 = 0x64;
                    } else {
                        _initContainerObject(
                            6, temp_s0 - 1, &vs_menuD_containerData->data);
                    }
                } else {
                    temp_s1[temp_s3 - 1] = var_a2;
                    temp_s1[temp_s2 - 1] = temp_s0;
                }
                func_800FA8E0(0);
                D_80109A68 = 4;
                break;
            }
            if (temp_s3 != -1) {
                return -2;
            }
            D_80109A68 = 0;
        }
        break;
    case 7:
        temp_s3 = func_80105008(0);
        if (temp_s3 != 0) {
            if (temp_s3 == -2) {
                return -2;
            }
            D_80109A7B = 1;
            temp_v0_11 = vs_battle_getMenuItem(0);
            if (temp_v0_11->animSpeed >= 0xB5) {
                if (temp_v0_11->animSpeed >= 0xCD) {
                    temp_v0_11->animSpeed = (u_short)temp_v0_11->animSpeed - 0x18;
                }
                temp_v0_11->state = 2;
                temp_v0_11->x = 0xB4;
            }
            D_80109A68 = 1;
        }
        break;
    case 8:
        D_80109A7D = 0;
        temp_s3 = temp_s1[D_80109A6C - 1] - 1;
        vs_battle_rMemzero(D_800F4E84, 0x10);
        temp_s0 = 0;
        temp_s2 = 0x33;
        switch (var_s4) {
        case 0:
            temp_s0 = vs_menuD_containerData->data.weapons[temp_s3].unk3;
            temp_s2 = 0x4A;
            break;
        case 3:
            temp_s0 = vs_menuD_containerData->data.shields[temp_s3].unk1;
            temp_s2 = 0x4A;
            break;
        case 4:
            temp_s0 = vs_menuD_containerData->data.armor[temp_s3].unk26;
            temp_s2 = 0x4A;
            break;
        case 6:
            temp_s0 = (vs_menuD_containerData->data.items[temp_s3].id < 0x1CA) ^ 1;
            break;
        }

        var_a2 = func_80103C9C(var_s4, temp_s3, &vs_menuD_containerData->data);
        var_a1 = 8;

        if (var_a2 != 0) {
            temp_s0 = 1;
            temp_s2 =
                D_8010952C[vs_menuD_containerData->data.weapons[var_a2 - 1].unk3 == 0
                               ? 5
                               : 4];
        }

        var_a2 = func_80103D14(var_s4, temp_s3, &vs_menuD_containerData->data);
        var_a1 = 8;

        if (var_a2 != 0) {
            temp_s0 = 1;
            temp_s2 =
                D_8010952C[vs_menuD_containerData->data.shields[var_a2 - 1].unk1 == 0
                               ? 5
                               : 4];
        }

        var_a2 = temp_s0;

        if (temp_s0 != 0) {
            sp10[1] = &D_8010952C[temp_s2];
        } else if (var_s4 == 6) {
            int temp_s0 = 0;

            for (temp_s2 = 0; temp_s2 < 7; ++temp_s2) {
                temp_s0 += func_80103070(temp_s2, &D_8010245C->unk87B0);
            }

            func_801031A0();
            var_a2 = func_801032AC(
                6, &D_8010245C->unk4BB0, temp_s3, &vs_menuD_containerData->data);
            if ((D_80109A7A == 0) && (var_a2 > 0x40)) {
                var_a2 = 0;
            }
            temp_s2 = 0xAB;
            if (var_a2 != 0) {
                if (temp_s0 == 0x40) {
                    int i;
                    int temp_a0 = vs_menuD_containerData->data.items[temp_s3].unk2;
                    for (i = 0; i < 256; ++i) {
                        if (D_8010245C->unk87B0.items[i].id
                            == vs_menuD_containerData->data.items[temp_s3].id) {
                            temp_a0 += D_8010245C->unk87B0.items[i].unk2 - 0x64;
                        }
                    }
                    var_a2 = temp_a0 < 1;
                    temp_s2 = 0x82;
                }
            }
            var_a2 = var_a2 == 0;
            sp10[1] = &D_8010952C[temp_s2];
        } else {
            var_a2 = func_80106784(var_s4, temp_s3);
            sp10[1] = &D_8010952C[D_8010952C[var_a2 + 5]];
        }

        sp10[0] = &D_8010952C[D_8010952C[D_80109A7A * 2 + 0x1F]];

        if (var_a2 != 0) {
            D_800F4E84[0] = 1;
        } else {
            sp10[1] = &D_8010952C[D_8010952C[D_80109A7A * 2 + 0x20]];
        }
        D_80109A61 = 1;
        temp_s2 = 1;
        if (((u_int)(var_s4 - 1) < 2) || ((var_s4 == 5))) {
            sp10[2] = vs_mainMenu_itemHelp + 0x3527;
            sp10[3] = vs_mainMenu_itemHelp + 0x352C;
            if ((func_80103C9C(var_s4, temp_s3, &vs_menuD_containerData->data) == 0)
                && (func_80103D14(var_s4, temp_s3, &vs_menuD_containerData->data) == 0)) {
                sp10[3] = vs_mainMenu_itemHelp + 0x35B2;
                D_800F4E84[1] = 1;
            }
            ++temp_s2;
            D_80109A60[temp_s2] = 2;
        }
        temp_s0 = 0;
        sp10[temp_s2 * 2] = vs_mainMenu_itemHelp + 0x354A;
        sp10[temp_s2 * 2 + 1] = vs_mainMenu_itemHelp + 0x354F;
        switch (var_s4) {
        case 0:
            temp_s0 = vs_menuD_containerData->data.weapons[temp_s3].unk3 != 0;
            break;
        case 3:
            temp_s0 = vs_menuD_containerData->data.shields[temp_s3].unk1 != 0;
            break;
        case 4:
            temp_s0 = vs_menuD_containerData->data.armor[temp_s3].unk26 != 0;
            break;
        case 6:
            if (vs_menuD_containerData->data.items[temp_s3].id >= 0x1CA) {
                temp_s0 = 3;
            }
            break;
        }
        var_a2 = func_80103C9C(var_s4, temp_s3, &vs_menuD_containerData->data);
        if (var_a2 != 0) {
            temp_s0 = 1;
            if (vs_menuD_containerData->data.weapons[var_a2 - 1].unk3 == 0) {
                temp_s0 = 2;
            }
        }
        var_a2 = func_80103D14(var_s4, temp_s3, &vs_menuD_containerData->data);
        if (var_a2 != 0) {
            temp_s0 = 1;
            if (vs_menuD_containerData->data.shields[var_a2 - 1].unk1 == 0) {
                temp_s0 = 2;
            }
        }
        if (temp_s0 != 0) {
            sp10[temp_s2 * 2 + 1] =
                &vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[temp_s0 + 663]];
            temp_s0 = 1;
        }
        D_800F4E84[temp_s2++] = temp_s0;
        D_80109A60[temp_s2] = 3;
        if (var_s4 == 6) {
            sp10[temp_s2 * 2] = vs_mainMenu_itemHelp + 0x356D;
            sp10[temp_s2 * 2 + 1] = vs_mainMenu_itemHelp + 0x3574;
            if (vs_menuD_containerData->data.items[temp_s3].id >= 0x1CA) {
                sp10[temp_s2 * 2 + 1] = vs_mainMenu_itemHelp + 0x350E;
                D_800F4E84[temp_s2] = 1;
            }
            ++temp_s2;
            D_80109A60[temp_s2] = 4;
        }

        sp10[temp_s2 * 2] = vs_mainMenu_itemHelp + 0x3586;
        sp10[temp_s2 * 2 + 1] = vs_mainMenu_itemHelp + 0x358A;
        ++temp_s2;
        D_80109A60[temp_s2] = 5;
        func_800FF0EC(temp_s2, var_s4 + 0x59, (char**)&sp10, (int*)D_800F4E84);
        D_80109A68 = 9;
        break;
    case 9:
        func_800FF9E4(func_800FF348(), D_801022C4);
        func_800FF43C();
        temp_s3 = func_800FF360() + 1;
        if (temp_s3 != 0) {
            func_800FA854(0x28);
            if (temp_s3 > 0) {
                vs_battle_playMenuSelectSfx();
                switch (D_80109A60[temp_s3]) {
                case 1:
                    func_800FFBC8();
                    func_80106948(var_s4,
                        func_80102C94(var_s4, vs_menuD_containerData)[D_80109A6C - 1]
                            - 1);
                    func_800FA8E0(0);
                    D_80109A68 = 4;
                    break;
                case 2:
                    func_800FFBC8();
                    func_800FA8E0(0);
                    D_80109A68 = 10;
                    break;
                case 3:
                    temp_s2 = temp_s1[D_80109A6C - 1] | (var_s4 << 0xC);
                    if ((var_s4 == 6)
                        && (vs_menuD_containerData->data
                                .items[temp_s1[D_80109A6C - 1] - 1]
                                .unk2
                            >= 2)) {
                        temp_s2 |= 0x10000;
                    }
                    func_80105D24(temp_s2);
                    D_80109A68 = 0xB;
                    break;
                case 4:
                    func_80105D24(temp_s1[D_80109A6C - 1] | (var_s4 << 0xC) | 0x20000);
                    D_80109A68 = 0xB;
                    break;
                case 5:
                    func_800FFBC8();
                    func_80105ACC(var_s4 + 1);
                    D_80109A68 = 0xC;
                    break;
                }
                break;
            }
            vs_battle_playMenuLeaveSfx();
            if (temp_s3 == -2) {
                func_800FFBA8();
                return -2;
            }
            D_80109A68 = 0;
        }
        break;
    case 10:
        if (vs_mainmenu_ready() != 0) {
            temp_s3 = func_80103C9C(
                var_s4, temp_s1[D_80109A6C - 1] - 1, &vs_menuD_containerData->data);
            if (temp_s3 != 0) {
                var_s4 = 0;
            } else {
                temp_s3 = func_80103D14(
                    var_s4, temp_s1[D_80109A6C - 1] - 1, &vs_menuD_containerData->data);
                var_s4 = 3;
            }
            temp_s2 = func_80103070(var_s4, &vs_menuD_containerData->data);
            temp_v0_17 = func_80102CD0(
                var_s4, temp_s3 - 1, func_80102C94(var_s4, vs_menuD_containerData));
            temp_s3 = temp_v0_17 - 1;
            if ((temp_s2 < 9) || (temp_s3 < 8)) {
                temp_s2 = 0;
            } else {
                temp_a0 = (temp_s2 - 8);
                if (temp_a0 < temp_s3) {
                    temp_s2 = temp_a0;
                    temp_s3 -= temp_s2;
                } else {
                    temp_s2 = temp_v0_17 - 2;
                    temp_s3 = 1;
                }
            }
            D_800F4EE8.unkA0[0] = (var_s4 + 1) & 7;
            temp_v0_18 = (var_s4 + 0x51) * 2;
            D_800F4EE8.unk0[temp_v0_18] = temp_s3;
            D_800F4EE8.unk0[temp_v0_18 + 1] = temp_s2;
            D_80109A68 = 1;
        }
        break;
    case 11:
        temp_s3 = func_80105D24(0);
        if (temp_s3 != 0) {
            func_800FFBC8();
            func_800FA854(0x28);
            func_800FA8E0(0);
            if (temp_s3 == -2) {
                return -2;
            }
            D_80109A68 = 4;
        }
        break;
    case 12:
        temp_s3 = func_80105ACC(0);
        if (temp_s3 != 0) {
            func_800FA854(0x28);
            func_800FA8E0(0);
            if (temp_s3 == -2) {
                return -2;
            }
            D_80109A68 = 4;
        }
        break;
    case 13:
        if (vs_mainmenu_ready() != 0) {
            temp_v0_19 = vs_main_allocHeapR(0x6C00U);
            temp_s3_7 = temp_v0_19 + 0x6400;
            temp_s1_4 = temp_v0_19 + 0x6000;
            temp_s2 = func_80106C64(7, temp_s3_7, temp_s1_4, temp_v0_19);
            D_80109A69 = temp_s2 == 0;
            if (D_80109A69 != 0) {
                vs_mainmenu_setMessage((char*)&D_8010952C[D_8010952C[D_80109A7A + 0x1D]]);
            } else {
                vs_mainmenu_setMenuRows(
                    temp_s2, (var_s4 + 0x51) | 0x19200, temp_s3_7, temp_s1_4);
            }
            vs_main_freeHeapR(temp_v0_19);
            D_80109A68 = 0xE;
        }
        break;
    case 14:
        if (vs_mainmenu_ready() != 0) {
            func_80100814();
            func_801072B0(1);
            D_80109A68 = 0xF;
        }
        break;
    case 15:
        temp_s3 = func_801072B0(0);
        if (temp_s3 != 0) {
            func_800FFBC8();
            if (temp_s3 < 0) {
                if (temp_s3 == -2) {
                    return -2;
                } else {
                    D_80109A68 = 5;
                    break;
                }
            } else {
                // Pointless check and duplicated loops
                if (D_80109A7A != 0) {
                    while ((temp_s2 = D_8010245C->unkC3B0[0])) {
                        func_801032AC((temp_s2 >> 8) | 0x10, &D_80109A88->data,
                            (temp_s2 - 1) & 0xFF, &D_8010245C->unk87B0);
                        _initContainerObject(
                            (temp_s2 >> 8), (temp_s2 - 1) & 0xFF, &D_8010245C->unk87B0);
                        func_80106A50();
                    }
                } else {
                    while ((temp_s2 = D_8010245C->unkC3B0[0])) {
                        func_801032AC((temp_s2 >> 8) | 0x10, &D_80109A88->data,
                            (temp_s2 - 1) & 0xFF, &D_8010245C->unk87B0);
                        _initContainerObject(
                            (temp_s2 >> 8), (temp_s2 - 1) & 0xFF, &D_8010245C->unk87B0);
                        func_80106A50();
                    }
                }
                for (temp_s3 = 0; temp_s3 < 7; ++temp_s3) {
                    func_801037D8(temp_s3, D_80109A88);
                }
                func_800FA8E0(0);
                D_80109A68 = 17;
            }
        }
        break;
    case 17:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_801089BC(int arg0)
{
    int i;
    int var_s1;
    vs_battle_menuItem_t* temp_v0_2;
    int v;
    char* a0;

    if (arg0 != 0) {
        if (D_80109A2E != 0) {
            D_80109A2E = 0;
            if (vs_main_settings.cursorMemory == 0) {
                D_800F4EE8.unk9E = 0;
            }
        }
        D_80109A2C = 0;
        D_80109A70 = 0;
        return 0;
    }

    switch (D_80109A70) {
    case 0:
    case 1:
        temp_v0_2 =
            vs_battle_setMenuItem(D_80109A70 + 0xA, 0x140, (D_80109A70 * 0x10) + 0x22,
                0x7E, 0, (char*)&D_8010952C[D_8010952C[D_80109A70 * 2 + 12]]);
        temp_v0_2->state = 2;
        temp_v0_2->x = 0xC2;
        ++D_80109A70;
        break;
    case 2:
        D_80109A70 += vs_mainmenu_ready();
        break;
    case 3:
        var_s1 = D_800F4EE8.unk9E;

        for (i = 0; i < 2; ++i) {
            vs_battle_getMenuItem(i + 0xA)->selected = i == var_s1;
        }
        if (vs_main_buttonsPressed.all & 0x10) {
            vs_battle_playMenuLeaveSfx();
            func_800FA8E0(0x28);
            return -2;
        }
        if (vs_main_buttonsPressed.all & 0x40) {
            vs_battle_playMenuLeaveSfx();
            return -1;
        }
        if (vs_main_buttonsPressed.all & 0x20) {
            vs_battle_playMenuSelectSfx();
            return var_s1 + 1;
        }
        D_80109A2C += 16;
        func_800C6540("OK", 0x4200C8, ((rsin((D_80109A2C) * 8) >> 5) + 0x40) * 0x10101,
            D_1F800000[1] - 3);
        v = 0x1A;
        D_80109A2D = func_800FFCDC(
            D_80109A2D, (((var_s1 * 0x10) - (((var_s1 * 2) & 4) - v)) << 0x10) | 0xB4);
        if (vs_main_buttonRepeat & 0x1000) {
            var_s1 += 2;
        }
        if (vs_main_buttonRepeat & 0x4000) {
            ++var_s1;
        }
        if (var_s1 >= 3) {
            var_s1 -= 3;
        }
        if (var_s1 != ((u_short*)&D_800F4EE8)[0x4F]) {
            vs_battle_playMenuChangeSfx();
            ((u_short*)&D_800F4EE8)[0x4F] = var_s1;
        }
        if (var_s1 != 2) {
            a0 = (char*)&D_8010952C[D_8010952C[var_s1 * 2 + 13]];
        } else {
            a0 = D_8010957C;
        }
        vs_mainmenu_setMessage(a0);
        break;
    }
    func_80106504();
    return 0;
}

INCLUDE_ASM("build/src/MENU/MENUD.PRG/nonmatchings/234", func_80108C6C);
