#include "common.h"
#include "234.h"
#include "../../SLUS_010.40/main.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../assets/MENU/ITEMHELP.BIN.h"
#include "vs_string.h"
#include <libetc.h>
#include <memory.h>
#include <libetc.h>
#include <limits.h>

enum copyContainerFlags { copyContainerFlagsCopy = 0x10 };
static int _copyContainerItem(int, vs_menu_containerData*, int, vs_menu_containerData*);
int func_80106C64(int, char**, int*, char*);

extern u_long* D_1F800000[];

extern u_short D_8010952C[];
extern char D_8010957C[];
extern u_short _containerItemCapacities[];
extern char* D_80109954;
extern int (*D_80109958[])(int);
extern char D_80109970[];
extern char D_80109990[];
extern char D_801099D0[];
extern char D_801099D4[];
extern char* D_801099DC[];
extern char _discardAmountFormat[];
extern char _discardBulkSteps[];
extern char D_80109A07;
extern char* D_80109A08[];
extern char* D_80109A10[];
extern char D_80109A2C;
extern char D_80109A2D;
extern char D_80109A2E;
extern char D_80109A30;
extern char D_80109A31;
extern char D_80109A32;
extern u_char _selectedWeapon;
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
extern char D_80109A3E;
extern char D_80109A3F;
extern char D_80109A40;
extern u_char D_80109A41;
extern char D_80109A42;
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
extern char _discardItemCategory;
extern u_char _discardIndex;
extern char _discardType;
extern u_char _discardBulkStep;
extern char _discardAmount;
extern char _discardMaxAmount;
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
extern vs_menu_container* D_80109A88;

void vs_menuD_initUiWeapon(vs_battle_uiWeapon* target, vs_battle_inventoryWeapon* source,
    vs_menu_containerData* container)
{
    int i;
    vs_battle_weaponIntermediate* temp = vs_main_allocHeapR(sizeof *temp);
    vs_main_bzero(temp, sizeof *temp);

    if (source != NULL) {
        temp->index = source->index;
        if (source->blade != 0) {
            vs_battle_copyInventoryBladeStats(
                &temp->blade, &container->blades[source->blade - 1]);
            temp->material = container->blades[source->blade - 1].material;
        }

        if (source->grip != 0) {
            vs_battle_copyInventoryGripStats(
                &temp->grip, &container->grips[source->grip - 1]);
        }

        for (i = 0; i < 3; ++i) {
            if (source->gems[i] != 0) {
                vs_battle_copyInventoryGemStats(
                    &temp->gems[i], &container->gems[source->gems[i] - 1]);
            }
        }
    }

    for (i = 0; i < 24; ++i) {
        temp->name[i] = source->name[i];
    }

    vs_battle_applyWeaponStats(target, temp);
    vs_main_freeHeapR(temp);
}

void vs_menuD_initUiShield(vs_battle_uiShield* target, vs_battle_inventoryShield* source,
    vs_menu_containerData* container)
{
    int i;
    vs_battle_shieldIntermediate* temp = vs_main_allocHeapR(sizeof *temp);
    vs_main_bzero(temp, sizeof *temp);

    if (source != NULL) {
        temp->unkC2 = source->index;
        vs_battle_copyInventoryArmorStats(&temp->base, &source->base);
        temp->material = source->base.material;

        for (i = 0; i < 3; ++i) {
            if (source->gems[i] != 0) {
                vs_battle_copyInventoryGemStats(
                    &temp->gems[i], &container->gems[(source->gems[i] & 0x7F) - 1]);
            }
        }
    }
    vs_battle_applyShieldStats(target, temp);
    vs_main_freeHeapR(temp);
}

static u_short* _getContainerIndicesOffset(int itemCategory, vs_menu_container* container)
{
    int i;
    int offset;

    offset = 0;
    for (i = 0; i < itemCategory; ++i) {
        offset += _containerItemCapacities[i];
    }
    return (u_short*)&container->indices + offset;
}

static int _getContainerItemIndex(int itemCategory, int index, u_short* indices)
{
    int i;

    for (i = 0; i < _containerItemCapacities[itemCategory]; ++i) {
        if (indices[i] == (index + 1)) {
            return i + 1;
        }
    }
    return 0;
}

static void _setContainerItemIndex(int itemCategory, int index, u_short* indices)
{
    int i;

    for (i = 0; i < _containerItemCapacities[itemCategory]; ++i) {
        if (indices[i] == 0) {
            indices[i] = index + 1;
            return;
        }
    }
}

static void _initContainerObject(
    int itemCategory, int index, vs_menu_containerData* container)
{
    int i;

    switch (itemCategory) {
    case itemCategoryWeapon: {
        vs_battle_inventoryWeapon* weapon = &container->weapons[index];

        _initContainerObject(1, weapon->blade - 1, container);
        _initContainerObject(2, weapon->grip - 1, container);

        for (i = 0; i < 3; ++i) {
            int gem = weapon->gems[i];
            if (gem != 0) {
                _initContainerObject(itemCategoryGem, gem - 1, container);
            }
        }

        vs_battle_rMemzero(weapon, sizeof *weapon);
        weapon->index = index + 1;
        break;
    }
    case itemCategoryBlade: {
        vs_battle_inventoryBlade* blade = &container->blades[index];
        vs_battle_rMemzero(blade, sizeof *blade);
        blade->index = index + 1;
        break;
    }
    case itemCategoryGrip: {
        vs_battle_inventoryGrip* grip = &container->grips[index];
        vs_battle_rMemzero(grip, sizeof *grip);
        grip->index = index + 1;
        break;
    }
    case itemCategoryShield: {
        vs_battle_inventoryShield* shield = &container->shields[index];

        for (i = 0; i < 3; ++i) {
            int gem = shield->gems[i];
            if (gem != 0) {
                _initContainerObject(itemCategoryGem, gem - 1, container);
            }
        }

        vs_battle_rMemzero(shield, sizeof *shield);
        shield->index = index + 1;
        break;
    }
    case itemCategoryArmor: {
        vs_battle_inventoryArmor* armor = &container->armor[index];
        vs_battle_rMemzero(armor, sizeof *armor);
        armor->index = index + 1;
        break;
    }
    case itemCategoryGem: {
        vs_battle_inventoryGem* gem = &container->gems[index];
        vs_battle_rMemzero(gem, sizeof *gem);
        gem->index = index + 1;
        break;
    }
    case itemCategoryItem: {
        vs_battle_inventoryMisc* item = &container->misc[index];
        vs_battle_rMemzero(item, sizeof *item);
        item->index = index + 1;
        break;
    }
    }
}

static int _getContainerItemId(int type, int index, vs_menu_containerData* container)
{
    int ret = 0;

    switch (type) {
    case itemCategoryWeapon:
        ret = container->weapons[index].blade;
        break;
    case itemCategoryBlade:
        ret = container->blades[index].id;
        break;
    case itemCategoryGrip:
        ret = container->grips[index].id;
        break;
    case itemCategoryShield:
        ret = container->shields[index].base.id;
        break;
    case itemCategoryArmor:
        ret = container->armor[index].id;
        break;
    case itemCategoryGem:
        ret = container->gems[index].id;
        break;
    case itemCategoryItem:
        ret = container->misc[index].id;
        break;
    }
    return ret;
}

static int _countContainerItems(int itemCategory, vs_menu_containerData* container)
{
    int i;
    int count = 0;

    for (i = 0; i < _containerItemCapacities[itemCategory]; ++i) {
        if (_getContainerItemId(itemCategory, i, container) != 0) {
            ++count;
        }
    }
    return count;
}

static int _getEmptyContainerSlot(int itemCategory, vs_menu_containerData* container)
{
    int i;

    for (i = 0; i < _containerItemCapacities[itemCategory]; ++i) {
        if (_getContainerItemId(itemCategory, i, container) == 0) {
            break;
        }
    }
    return i;
}

static void func_801031A0(void)
{
    int i;
    int var_a2;
    vs_menu_containerData* container = &vs_menu_inventoryStorage->unk4BB0;

    vs_battle_memcpy(&container->misc, D_80109A88->data.misc, sizeof container->misc);

    for (var_a2 = vs_menu_inventoryStorage->itemsToTransfer[0], i = 0; var_a2 != 0;
         ++i, var_a2 = vs_menu_inventoryStorage->itemsToTransfer[i]) {
        if ((var_a2 >> 8) == itemCategoryItem) {
            _copyContainerItem(copyContainerFlagsCopy | itemCategoryItem, container,
                (var_a2 - 1) & 0xFF, &vs_menu_inventoryStorage->unk87B0);
        }
    }
}

static void func_80103270(void)
{
    func_801031A0();
    D_80109A82 =
        _countContainerItems(itemCategoryItem, &vs_menu_inventoryStorage->unk4BB0);
}

static int _copyContainerItem(int itemCategory, vs_menu_containerData* targetContainer,
    int sourceSlot, vs_menu_containerData* sourceContainer)
{
    int copyFlag;
    int targetSlot;
    int parentIndex;
    int itemCount;
    int i;
    int subItemCount;
    int index;

    parentIndex = itemCategory >> 8;
    copyFlag = (itemCategory >> 4) & 1;
    itemCategory = itemCategory & 0xF;
    index = 0;
    itemCount = _countContainerItems(itemCategory, targetContainer);
    targetSlot = _getEmptyContainerSlot(itemCategory, targetContainer);

    switch (itemCategory) {
    case itemCategoryWeapon: {
        vs_battle_inventoryWeapon* source = &sourceContainer->weapons[sourceSlot];
        vs_battle_inventoryWeapon* target = &targetContainer->weapons[targetSlot];

        if (((itemCount != 32)
                && (_countContainerItems(itemCategoryBlade, targetContainer) != 64))
            && (_countContainerItems(itemCategoryGrip, targetContainer) != 64)) {

            subItemCount = 0;

            for (i = 0; i < 3; ++i) {
                if (source->gems[i] != 0) {
                    ++subItemCount;
                }
            }

            if ((_countContainerItems(itemCategoryGem, targetContainer) + subItemCount)
                > 192) {
                break;
            }

            index = targetSlot + 1;

            if (copyFlag != 0) {
                vs_battle_rMemzero(target, sizeof *target);
                target->index = index;
                target->blade = _copyContainerItem(
                    (index << 8) | copyContainerFlagsCopy | itemCategoryBlade,
                    targetContainer, source->blade - 1, sourceContainer);
                target->grip = _copyContainerItem(
                    (index << 8) | copyContainerFlagsCopy | itemCategoryGrip,
                    targetContainer, source->grip - 1, sourceContainer);
                for (i = 0; i < 3; ++i) {
                    if (source->gems[i] != 0) {
                        target->gems[i] = _copyContainerItem(
                            (index << 8) | copyContainerFlagsCopy | itemCategoryGem,
                            targetContainer, source->gems[i] - 1, sourceContainer);
                    }
                }
                vs_battle_rMemcpy(target->name, source->name, sizeof target->name);
            }
        }
        break;
    }
    case itemCategoryBlade: {
        vs_battle_inventoryBlade* source = &sourceContainer->blades[sourceSlot];
        vs_battle_inventoryBlade* target = &targetContainer->blades[targetSlot];

        if (itemCount == 64) {
            break;
        }

        index = targetSlot + 1;

        if (copyFlag != 0) {
            vs_battle_copyAligned(target, source, sizeof *target);
            target->index = index;
            target->assembledWeaponIndex = parentIndex;
        }
        break;
    }
    case itemCategoryGrip: {
        vs_battle_inventoryGrip* source = &sourceContainer->grips[sourceSlot];
        vs_battle_inventoryGrip* target = &targetContainer->grips[targetSlot];

        if (itemCount == 64) {
            break;
        }

        index = targetSlot + 1;

        if (copyFlag != 0) {
            vs_battle_copyAligned(target, source, sizeof *target);
            target->index = index;
            target->assembledWeaponIndex = parentIndex;
        }
        break;
    }
    case itemCategoryShield: {
        vs_battle_inventoryShield* source = &sourceContainer->shields[sourceSlot];
        vs_battle_inventoryShield* target = &targetContainer->shields[targetSlot];

        if (itemCount == 32) {
            break;
        }

        subItemCount = 0;

        for (i = 0; i < 3; ++i) {
            if (source->gems[i] != 0) {
                ++subItemCount;
            }
        }

        if ((_countContainerItems(itemCategoryGem, targetContainer) + subItemCount)
            > 192) {
            break;
        }

        index = targetSlot + 1;

        if (copyFlag != 0) {
            vs_battle_rMemzero(target, sizeof *target);
            vs_battle_copyAligned(&target->base, &source->base, sizeof target->base);
            target->index = index;
            for (i = 0; i < 3; ++i) {
                if (source->gems[i] != 0) {
                    target->gems[i] =
                        _copyContainerItem(((index | gemTargetShield) << 8)
                                               | copyContainerFlagsCopy | itemCategoryGem,
                            targetContainer, source->gems[i] - 1, sourceContainer);
                }
            }
        }
        break;
    }
    case itemCategoryArmor: {
        vs_battle_inventoryArmor* source = &sourceContainer->armor[sourceSlot];
        vs_battle_inventoryArmor* target = &targetContainer->armor[targetSlot];

        if (itemCount == 64) {
            break;
        }

        index = targetSlot + 1;

        if (copyFlag != 0) {
            vs_battle_copyAligned(target, source, sizeof *target);
            target->index = index;
        }
        break;
    }
    case itemCategoryGem: {
        vs_battle_inventoryGem* source = &sourceContainer->gems[sourceSlot];
        vs_battle_inventoryGem* target = &targetContainer->gems[targetSlot];

        if (itemCount == 192) {
            break;
        }

        index = targetSlot + 1;

        if (copyFlag != 0) {
            vs_battle_copyAligned(target, source, sizeof *target);
            target->index = index;
            target->setItemIndex = parentIndex;
        }
        break;
    }
    case itemCategoryItem: {
        vs_battle_inventoryMisc* target = targetContainer->misc;
        vs_battle_inventoryMisc* source = &sourceContainer->misc[sourceSlot];

        subItemCount = source->count;

        for (i = 0; i < 256; ++i) {
            if (target[i].id == source->id) {
                if (copyFlag != 0) {
                    if ((100 - target[i].count) >= subItemCount) {
                        target[i].count = target[i].count + subItemCount;
                        subItemCount = 0;
                    } else {
                        int v0 = subItemCount - 100;
                        subItemCount = v0 + target[i].count;
                        target[i].count = 100;
                    }
                } else {
                    int v0 = subItemCount - 100;
                    subItemCount = v0 + target[i].count;
                    if (subItemCount < 0) {
                        subItemCount = 0;
                    }
                }
            }
        }

        if (subItemCount == 0) {
            index = 1;
            break;
        }
        if (itemCount == 256) {
            break;
        }

        index = targetSlot + 1;

        if (copyFlag != 0) {
            target[targetSlot].id = source->id;
            target[targetSlot].count = subItemCount;
        }
        break;
    }
    }
    return index;
}

static void _defragmentContainerItems(int itemCategory, vs_menu_container* container)
{
    int i;
    int j;
    int var_a1;
    int source;
    int capacity;
    u_short* indexOffset;

    indexOffset = _getContainerIndicesOffset(itemCategory, container);
    capacity = _containerItemCapacities[itemCategory];

    for (i = 0; i < capacity; ++i) {
        source = indexOffset[i];
        if ((source != 0)
            && (_getContainerItemId(itemCategory, source - 1, &container->data) == 0)) {
            indexOffset[i] = 0;
        }
    }

    i = 0;

    while (1) {
        if (indexOffset[i] != 0) {
            ++i;
            if (i == (capacity - 1)) {
                break;
            }
        } else {
            for (var_a1 = i + 1; var_a1 < capacity; ++var_a1) {
                if (indexOffset[var_a1] != 0) {
                    break;
                }
            }

            if (var_a1 == capacity) {
                break;
            }

            for (j = var_a1; j < capacity; ++j) {
                indexOffset[(j + i) - var_a1] = indexOffset[j];
            }

            for (j = j + (i - var_a1); j < capacity; ++j) {
                indexOffset[j] = 0;
            }
        }
    }

    for (i = 0; i < capacity; ++i) {
        if ((_getContainerItemId(itemCategory, i, &container->data) != 0)
            && (_getContainerItemIndex(itemCategory, i, indexOffset) == 0)) {
            _setContainerItemIndex(itemCategory, i, indexOffset);
        }
    }
}

static void _copyInventoryToContainer(void)
{
    int i;

    vs_battle_inventory_t* inventory = &vs_battle_inventory;
    vs_menu_container* container = &vs_menu_inventoryStorage->unk105B0;

    vs_battle_rMemzero(&container->data, sizeof container->data);
    vs_battle_rMemzero(&vs_menu_inventoryStorage->unk105B0.indices,
        sizeof vs_menu_inventoryStorage->unk105B0.indices);

    for (i = 0; i < 7; ++i) {
        int j;
        char* sourceIndex = vs_mainMenu_inventoryIndices[i];
        u_short* targetIndex = _getContainerIndicesOffset(i, container);

        for (j = 0; j < vs_mainMenu_inventoryItemCapacities[i]; ++j) {
            targetIndex[j] = sourceIndex[j];
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
        container->data.misc, inventory->items, sizeof container->data.misc / 4);
}

static void _copyContainerToInventory(void)
{
    int i;

    vs_menu_container* container = &vs_menu_inventoryStorage->unk105B0;
    vs_battle_inventory_t* inventory = &vs_battle_inventory;

    for (i = 0; i < 7; ++i) {
        int j;
        int k;
        char* targetIndex = vs_mainMenu_inventoryIndices[i];
        u_short* sourceIndex = _getContainerIndicesOffset(i, container);

        for (j = 0; j < 7; ++j) {
            _defragmentContainerItems(j, container);
        }

        for (k = 0; k < vs_mainMenu_inventoryItemCapacities[i]; ++k) {
            targetIndex[k] = sourceIndex[k];
        }
    }

    vs_battle_memcpy(
        inventory->weapons, container->data.weapons, sizeof inventory->weapons);
    vs_battle_memcpy(inventory->blades, container->data.blades, sizeof inventory->blades);
    vs_battle_memcpy(inventory->grips, container->data.grips, sizeof inventory->grips);
    vs_battle_memcpy(
        inventory->shields, container->data.shields, sizeof inventory->shields);
    vs_battle_memcpy(inventory->armor, container->data.armor, sizeof inventory->armor);
    vs_battle_memcpy(inventory->gems, container->data.gems, sizeof inventory->gems);
    vs_battle_memcpy(inventory->items, container->data.misc, sizeof inventory->items);
}

static int _getParentItemIndex(
    int itemCategory, int index, vs_menu_containerData* container)
{
    int parentIndex = 0;

    if (itemCategory == itemCategoryBlade) {
        parentIndex = container->blades[index].assembledWeaponIndex;
    }
    if (itemCategory == itemCategoryGrip) {
        parentIndex = container->grips[index].assembledWeaponIndex;
    }
    if (itemCategory == itemCategoryGem) {
        parentIndex = container->gems[index].setItemIndex;
        if (parentIndex & gemTargetShield) {
            parentIndex = 0;
        }
    }
    return parentIndex;
}

static int _getSetShieldIndex(
    int itemCategory, int index, vs_menu_containerData* container)
{
    int parentIndex = 0;

    if (itemCategory == itemCategoryGem) {
        parentIndex = container->gems[index].setItemIndex;
        if (!(container->gems[index].setItemIndex & gemTargetShield)) {
            parentIndex = 0;
        }
    }
    return parentIndex & 0x7F;
}

static void func_80103D50(char arg0)
{
    D_80109A7B = arg0;
    D_80109A7C = arg0;
    D_80109A7D = arg0;
}

static int _pollItemNavigation(int itemCategory, int currentSelection)
{
    int previousSelection;
    int count;
    int temp_a0;

    if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {

        previousSelection = currentSelection;
        count = _countContainerItems(itemCategory, &vs_menuD_containerData->data);
        temp_a0 = count;

        if (vs_main_buttonRepeat & PADL1) {
            int temp = currentSelection - 1;
            currentSelection = temp + count;
        }

        do {
            if (vs_main_buttonRepeat & PADR1) {
                ++currentSelection;
            }
            if (currentSelection >= temp_a0) {
                currentSelection -= temp_a0;
            }
        } while (0);

        if ((vs_main_buttonsPressed.all & (PADL1 | PADR1))
            && (currentSelection == previousSelection)) {
            func_800C02E0();
        }
    }
    return currentSelection;
}

void func_80103E24(int arg0, int arg1)
{
    int i;
    u_long* var_v1;
    vs_battle_menuItem_t* temp_v0;

    int temp_s4 = (D_800F4EE8.unk85[0x1B] - 1) & 7;

    if (arg0 == 4) {
        func_801013F8(0);
    }

    arg0 = (arg0 * 8) - 16;

    for (i = 0; i < 8; ++i) {

        int temp_s0 = (((i + 1) & 7) * 0x10) + 0x20;

        if ((i == temp_s4) && (arg1 == 1)) {
            temp_v0 = vs_battle_getMenuItem(0x1F);
            if (temp_s0 >= (temp_v0->initialX - 0xC)) {
                temp_v0->icon = i + 0x18;
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

    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

    menuItem = vs_battle_getMenuItem(0x1F);
    menuItem->state = 3;
    menuItem->targetX = 0x12;

    menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 2;
    menuItem->targetX = 0x9B;
    menuItem->selected = 1;
    menuItem->unk3C = 0;
    menuItem->unk7 = 0;
}

void func_80103FD4(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_getMenuItem(0x1F);
    menuItem->state = 2;
    menuItem->targetX = 0x10;
    menuItem->w = 0xA4;

    menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 3;
    menuItem->targetX = 0x12;
}

static void func_80104034(int arg0, int arg1)
{
    D_80109A7C = 0;
    D_80109A7D = 0;
    func_80103FD4(arg0);
    func_800FBBD4(arg1);
    vs_battle_renderEquipStats(1);
}

void func_80104078(int arg0, char** arg1, u_int arg2, int arg3)
{
    vs_battle_menuItem_t* menuItem;

    vs_battle_playMenuChangeSfx();
    menuItem = vs_battle_setMenuItem(arg0, 0x9B, 0x12, 0xA5, 0, arg1[0]);
    menuItem->selected = 1;
    menuItem->icon = (arg2 >> 0x1A);
    menuItem->material = (arg2 >> 0x10) & 7;
    vs_mainmenu_setMessage(arg1[1]);
    vs_battle_getMenuItem(0x1F)->unkE = arg3 + 1;
}

int func_80104114(int arg0, int arg1)
{
    D_800F4EE8.unk0[(arg0 + 0x51) * 2] = 0;
    D_800F4EE8.unk0[(arg0 + 0x51) * 2 + 1] = arg1;
    return _getContainerIndicesOffset(arg0, vs_menuD_containerData)[arg1];
}

void func_80104170(int arg0)
{
    vs_battle_playMenuLeaveSfx();
    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    func_800FA810(-1);
    func_800FBBD4(-1);
    vs_battle_renderEquipStats(2);
    D_80109A81 = 2;
    D_80109A84 = vs_main_buttonsPressed.all & PADRup;
    if (arg0 != 0) {
        vs_mainMenu_drawDpPpbars(4);
    }
}

static void _setWeaponUi(vs_menu_containerData* container, char** rowStrings,
    int* rowTypes, char* buf, int index)
{
    vs_battle_uiWeapon weapon;

    vs_menuD_initUiWeapon(&weapon, &container->weapons[index], container);
    vs_mainMenu_setWeaponUi(&weapon, rowStrings, rowTypes, buf);
    rowStrings[0] = container->weapons[index].name;
}

static void _setShieldUi(vs_menu_containerData* container, char** rowStrings,
    int* rowTypes, char* buf, int index)
{
    vs_battle_uiShield shield;

    vs_menuD_initUiShield(&shield, &container->shields[index], container);
    vs_mainMenu_setShieldUi(&shield, rowStrings, rowTypes, buf);
}

int _weaponNavigation(int weaponIndex)
{
    enum state { init, animate, handleInput, exit };

    char* text[2];
    int rowId;
    int selectedWeapon;
    int i;

    if (weaponIndex != 0) {
        D_80109A32 = weaponIndex >> 8;
        _selectedWeapon = weaponIndex - 1;
        func_80103F64(D_80109A32);
        D_80109A34 = 0;
        D_80109A31 = 0;
        D_80109A30 = 0;
        return 0;
    }

    switch (D_80109A30) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            func_80104034(D_80109A32, 7);
            vs_mainMenu_setUiWeaponStats(
                vs_menuD_containerData->indices.weapons[_selectedWeapon]);
            vs_mainMenu_drawDpPpbars(3);
            D_80109A30 = animate;
        }
        break;
    case animate:
        if (D_80109A31 < 10) {
            ++D_80109A31;
            if (D_80109A31 < 6) {
                func_800FC510(D_80109A31,
                    vs_menuD_containerData->indices.weapons[_selectedWeapon], 1);
            }
            break;
        }
        D_80109A30 = handleInput;
        break;
    case handleInput:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            func_80104170(1);
            D_80109A30 = exit;
        } else {
            selectedWeapon = _pollItemNavigation(0, _selectedWeapon);
            if (selectedWeapon != _selectedWeapon) {
                _selectedWeapon = selectedWeapon;
                i = func_80104114(0, selectedWeapon);
                _setWeaponUi(&vs_menuD_containerData->data, text, &rowId,
                    vs_battle_stringBuf, i - 1);
                vs_mainMenu_setUiWeaponStats(i);

                func_80104078(D_80109A32, text, rowId, selectedWeapon);
                for (i = 1; i < 6; ++i) {
                    func_800FC510(
                        i, vs_menuD_containerData->indices.weapons[selectedWeapon], 0);
                }
            }
        }
        break;
    case exit:
        return vs_mainmenu_ready();
    }
    return 0;
}

int _bladeNavigation(int bladeIndex)
{
    enum state { init, animate, handleInput, exit };

    char* text[2];
    int sp18;
    int selectedBlade;
    int temp_v0_3;

    if (bladeIndex != 0) {
        D_80109A37 = bladeIndex >> 8;
        D_80109A38 = bladeIndex - 1;
        func_80103F64(D_80109A37);
        D_80109A36 = 10;
        D_80109A35 = 0;
        return 0;
    }

    switch (D_80109A35) {
    case init:
        if (vs_mainmenu_ready() != 0) {
            func_80104034(D_80109A37, 3);
            func_800FD404(vs_menuD_containerData->indices.blades[D_80109A38]);
            vs_mainMenu_drawDpPpbars(3);
            D_80109A35 = animate;
        }
        break;
    case animate:
        if (D_80109A36 != 0) {
            --D_80109A36;
        } else {
            D_80109A35 = handleInput;
        }
        break;
    case handleInput:
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            func_80104170(1);
            D_80109A35 = exit;
        } else {
            selectedBlade = _pollItemNavigation(1, D_80109A38);
            if (selectedBlade != D_80109A38) {
                D_80109A38 = selectedBlade;
                temp_v0_3 = func_80104114(1, selectedBlade);
                vs_mainMenu_setBladeUi(
                    &vs_menuD_containerData->data.blades[temp_v0_3 - 1], text, &sp18,
                    vs_battle_stringBuf);
                func_800FD404(temp_v0_3);
                func_80104078(D_80109A37, text, sp18, selectedBlade);
            }
        }
        break;
    case exit:
        return vs_mainmenu_ready();
    }
    return 0;
}

int _gripNavigation(int arg0)
{
    char* sp10[2];
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
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            func_80104170(0);
            D_80109A39 = 3U;
        } else {
            temp_v0_2 = _pollItemNavigation(2, D_80109A3C);
            if (temp_v0_2 != D_80109A3C) {
                D_80109A3C = temp_v0_2;
                temp_v0_3 = func_80104114(2, temp_v0_2);
                vs_mainMenu_setGripUi(&vs_menuD_containerData->data.grips[temp_v0_3 - 1],
                    sp10, &sp18, vs_battle_stringBuf);
                func_800FD504(temp_v0_3);
                func_80104078(D_80109A3B, sp10, sp18, temp_v0_2);
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

int _shieldNavigation(int arg0)
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
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            func_80104170(1);
            D_80109A3E = 3;
        } else {
            temp_v0_2 = _pollItemNavigation(3, D_80109A41);
            if (temp_v0_2 != D_80109A41) {
                D_80109A41 = temp_v0_2;
                i = func_80104114(3, temp_v0_2);
                _setShieldUi(&vs_menuD_containerData->data, sp18, &sp20,
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

int _armorNavigation(int arg0)
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
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            func_80104170(1);
            D_80109A43 = 3;
        } else {
            temp_v0_2 = _pollItemNavigation(4, D_80109A46);
            if (temp_v0_2 != D_80109A46) {
                D_80109A46 = temp_v0_2;
                temp_v0_3 = func_80104114(4, temp_v0_2);
                vs_mainMenu_setAccessoryUi(
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

int _gemNavigation(int arg0)
{
    char* sp10[2];
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
        if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
            func_80104170(0);
            D_80109A47 = 3;
            D_80109A84 = vs_main_buttonsPressed.all & 0x10;
        } else {
            temp_v0_2 = _pollItemNavigation(5, D_80109A4A);
            if (temp_v0_2 != D_80109A4A) {
                D_80109A4A = temp_v0_2;
                temp_v0_3 = func_80104114(5, temp_v0_2);
                vs_mainMenu_setGemUi(&vs_menuD_containerData->data.gems[temp_v0_3 - 1],
                    sp10, &sp18, vs_battle_stringBuf);
                func_800FD878(temp_v0_3);
                func_80104078(D_80109A49, sp10, sp18, temp_v0_2);
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

int _getWeaponStat(int type, vs_battle_uiWeapon* weapon)
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

static void _sortWeaponsByStat(int stat)
{
    vs_battle_uiWeapon target;
    u_short sortedIndices[32];
    int i;
    int maxStatValue;
    int sortedIndex;
    int sourceIndex;

    vs_battle_inventoryWeapon* sourceWeapons = vs_menuD_containerData->data.weapons;
    u_short* targetIndices =
        _getContainerIndicesOffset(itemCategoryWeapon, vs_menuD_containerData);
    vs_battle_rMemzero(sortedIndices, sizeof sortedIndices);
    sortedIndex = 0;

    while (1) {
        maxStatValue = -INT_MAX - 1;

        for (i = 0; i < 32; ++i) {
            int statValue;
            sourceIndex = targetIndices[i];
            if (sourceIndex == 0) {
                continue;
            }
            vs_menuD_initUiWeapon(
                &target, &sourceWeapons[sourceIndex - 1], &vs_menuD_containerData->data);
            statValue = _getWeaponStat(stat, &target);
            if (maxStatValue < statValue) {
                maxStatValue = statValue;
            }
        }

        if (maxStatValue == (-INT_MAX - 1)) {
            break;
        }

        for (i = 0; i < 32; ++i) {
            sourceIndex = targetIndices[i];
            if (sourceIndex == 0) {
                continue;
            }
            vs_menuD_initUiWeapon(
                &target, &sourceWeapons[sourceIndex - 1], &vs_menuD_containerData->data);
            if (_getWeaponStat(stat, &target) == maxStatValue) {
                sortedIndices[sortedIndex++] = sourceIndex;
                targetIndices[i] = 0;
            }
        }
    }
    vs_battle_memcpy(targetIndices, &sortedIndices, sizeof sortedIndices);
}

static int _getShieldStat(int arg0, vs_battle_uiShield* shield)
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

static void _sortShieldsByStat(int arg0)
{
    vs_battle_uiShield sp10;
    u_short sp178[0x20];
    int temp_v0;
    int i;
    int var_s3;
    int temp_s0;

    vs_battle_inventoryShield* temp_s5 = vs_menuD_containerData->data.shields;
    u_short* temp_s6 = _getContainerIndicesOffset(3, vs_menuD_containerData);
    int var_s4 = 0;

    vs_battle_rMemzero(&sp178, sizeof sp178);

    while (1) {
        var_s3 = 0x80000000;

        for (i = 0; i < 32; ++i) {
            temp_s0 = temp_s6[i];
            if (temp_s0 != 0) {
                vs_menuD_initUiShield(
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
                vs_menuD_initUiShield(
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

static int _getItemStat(int arg0, vs_battle_inventoryMisc* item)
{
    if (arg0 == 0) {
        return -item->id;
    }
    return item->count;
}

static void _sortItemsByStat(int arg0)
{
    u_short sp10[0x100];
    int temp_v0;
    int i;
    int var_s4;
    int var_s5;
    int temp_s0;
    u_short* temp_s7;
    vs_battle_inventoryMisc* item;

    item = vs_menuD_containerData->data.misc;
    temp_s7 = _getContainerIndicesOffset(6, vs_menuD_containerData);
    vs_battle_rMemzero(&sp10, sizeof sp10);
    var_s5 = 0;

    while (1) {
        var_s4 = 0x80000000;

        for (i = 0; i < 256; ++i) {
            temp_s0 = temp_s7[i];
            if (temp_s0 != 0) {
                temp_v0 = _getItemStat(arg0, &item[temp_s0 - 1]);
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
            if ((temp_s0 != 0) && (_getItemStat(arg0, &item[temp_s0 - 1]) == var_s4)) {
                sp10[var_s5++] = temp_s0;
                temp_s7[i] = 0;
            }
        }
    }
    vs_battle_memcpy(temp_s7, &sp10, sizeof sp10);
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

static void _copyEquipmentStats(vs_battle_uiEquipment* item, int type, int index)
{
    switch (type) {
    case itemCategoryBlade:
        vs_battle_copyInventoryBladeStats(
            item, &vs_menuD_containerData->data.blades[index]);
        return;
    case itemCategoryGrip:
        vs_battle_copyInventoryGripStats(
            item, &vs_menuD_containerData->data.grips[index]);
        return;
    case itemCategoryArmor:
        vs_battle_copyInventoryArmorStats(
            item, &vs_menuD_containerData->data.armor[index]);
        return;
    case itemCategoryGem:
        vs_battle_copyInventoryGemStats(item, &vs_menuD_containerData->data.gems[index]);
        return;
    }
}

static void _sortEquipmentByStat(int arg0, int arg1)
{
    vs_battle_uiEquipment sp10;
    int temp_v0;
    int i;
    int var_s4;
    int var_s6;
    int temp_s0;
    int temp_s5;
    u_short* temp_s7;

    var_s6 = 0;
    temp_s5 = _containerItemCapacities[arg0];

    {
        u_short sp40[temp_s5];
        temp_s7 = _getContainerIndicesOffset(arg0, vs_menuD_containerData);
        vs_battle_rMemzero(sp40, temp_s5 * 2);

        while (1) {
            var_s4 = 0x80000000;

            for (i = 0; i < temp_s5; ++i) {
                temp_s0 = temp_s7[i];
                if (temp_s0 != 0) {
                    _copyEquipmentStats(&sp10, arg0, temp_s0 - 1);
                    temp_v0 = _getEquipmentStat(arg1, &sp10);
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
                    _copyEquipmentStats(&sp10, arg0, temp_s0 - 1);
                    if (_getEquipmentStat(arg1, &sp10) == var_s4) {
                        sp40[var_s6++] = temp_s0;
                        temp_s7[i] = 0;
                    }
                }
            }
        }
        vs_battle_memcpy(temp_s7, sp40, temp_s5 * 2);
    }
}

static int _displaySortMenu(int arg0)
{
    enum state { init, display };

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
    case init:
        if (vs_mainmenu_ready() != 0) {
            new_var = D_801099DC[D_80109A4D];

            for (i = 0; i < D_801099D4[D_80109A4D]; ++i) {
                sp10[i * 2] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                        [new_var[i] * 2 + VS_ITEMHELP_BIN_INDEX_sortMenu]];
                sp10[i * 2 + 1] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                        [new_var[i] * 2 + VS_ITEMHELP_BIN_INDEX_sortMenuDesc]];
                spD0[i] = 0;
            }
            func_800FF0EC(i, D_80109A4D + 0x60, sp10, spD0);
            D_80109A4C = display;
        }
        break;
    case display:
        func_800FF43C();
        i = func_800FF360();
        if ((i + 1) != 0) {
            if (i >= 0) {
                vs_battle_playMenuSelectSfx();
                switch (D_80109A4D) {
                case 0:
                    _sortWeaponsByStat(D_80109970[i]);
                    break;
                case 3:
                    _sortShieldsByStat(D_80109990[i]);
                    break;
                case 6:
                    _sortItemsByStat(D_801099D0[i]);
                    break;
                default:
                    _sortEquipmentByStat(D_80109A4D, D_801099DC[D_80109A4D][i]);
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

int _displayDiscardMenu(int arg0)
{
    enum state {
        init,
        discardOne,
        discardMultiple,
        execDiscardOne,
        clearFormat,
        determineDiscardAmount,
        discardMultipleConfirm,
        execDiscardMultiple
    };

    char* discardOneText[4];
    int discardOneRowTypes[2];
    char* discardMultipleText[4];
    int discardMultipleRowTypes[2];
    int i;
    int temp_v0_7;
    int temp_v0_8;
    int var_v0;
    int a2;
    vs_battle_menuItem_t* menuItem;
    int a0;

    if (arg0 != 0) {
        _discardType = arg0 >> 0x10;
        _discardItemCategory = (arg0 >> 0xC) & 0xF;
        _discardIndex = arg0 - 1;
        func_800C8E04(1);
        vs_mainmenu_setMessage((char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                [_discardType + VS_ITEMHELP_BIN_INDEX_discardConfirm]]);
        D_80109A4E = 0;
        return 0;
    }
    switch (D_80109A4E) {
    case init:
        var_v0 = 0;
        if ((D_800F5130 >> 0x1E) & 1) {
            if (vs_mainmenu_ready() != 0) {
                D_80109A4E = ((_discardType & 1) + 1);
            }
        }
        break;
    case discardOne:
        for (i = 0; i < 2; ++i) {
            discardOneText[i * 2] = (char*)&vs_mainMenu_itemHelp
                [vs_mainMenu_itemHelp[i + VS_ITEMHELP_BIN_INDEX_confirmYes]];
            discardOneText[i * 2 + 1] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp
                    [_discardType + VS_ITEMHELP_BIN_INDEX_discardConfirm]];
            discardOneRowTypes[i] = 0;
        }

        func_800FF0EC(2, 4, discardOneText, discardOneRowTypes);
        D_80109A4E = execDiscardOne;
        break;
    case discardMultiple:
        _discardMaxAmount = vs_menuD_containerData->data.misc[_discardIndex].count;
        i = vs_battle_toBCD(_discardMaxAmount);
        _discardAmountFormat[8] = i & 0xF;
        i = vs_battle_toBCD(i >> 4);

        _discardAmountFormat[7] = i & 0xF;
        _discardAmountFormat[6] = i >> 4;

        for (i = 2; i < 5; ++i) {
            _discardAmountFormat[i] = 0;
        }

        menuItem =
            vs_battle_setMenuItem(0x22, -0x7E, 0x82, 0x7E, 0, _discardAmountFormat);
        menuItem->state = 5;
        menuItem->targetX = 0;
        _discardBulkStep = 0;
        _discardAmount = 0;
        D_80109A4E = clearFormat;
        break;
    case execDiscardOne:
        func_800FF43C();
        i = func_800FF360() + 1;
        if (i != 0) {
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0x1C);
                _initContainerObject(
                    _discardItemCategory, _discardIndex, &vs_menuD_containerData->data);
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i;
        }
        break;
    case clearFormat:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        for (i = 2; i < 5; ++i) {
            _discardAmountFormat[i] = vs_char_space;
        }
        vs_battle_setMenuItem(0x22, 0, 0x82, 0x7E, 0, _discardAmountFormat);
        D_80109A4E = determineDiscardAmount;
        // Fallthrough
    case determineDiscardAmount:
        if (vs_main_buttonsPressed.all & (PADRup | PADRright | PADRdown)) {
            i = vs_battle_toBCD(_discardAmount);
            _discardAmountFormat[4] = i & 0xF;
            i = vs_battle_toBCD(i >> 4);
            _discardAmountFormat[3] = i & 0xF;
            _discardAmountFormat[2] = i >> 4;
            vs_battle_setMenuItem(0x22, 0, 0x82, 0x7E, 0, _discardAmountFormat);
            if (vs_main_buttonsPressed.all & (PADRup | PADRdown)) {
                vs_battle_playMenuLeaveSfx();
                if ((vs_main_buttonsPressed.all & PADRup)) {
                    return -2;
                }
                return -1;
            }
            if (_discardAmount == 0) {
                vs_battle_playMenuLeaveSfx();
                return -1;
            }
            vs_battle_playMenuSelectSfx();
            D_80109A4E = discardMultipleConfirm;
            break;
        }

        i = 0;
        a0 = a2 = _discardAmount;
        if (vs_main_buttonRepeat & PADLup) {
            i = 1;
        }
        if (vs_main_buttonRepeat & PADLdown) {
            --i;
        }
        if (i == 1) {
            a0 = _discardAmount + _discardBulkSteps[_discardBulkStep];
        } else if (i == -1) {
            a0 = _discardAmount - _discardBulkSteps[_discardBulkStep];
        }
        if (a0 >= 0) {
            if (_discardMaxAmount >= a0) {
                _discardAmount = a0;
            }
        }
        i = 0;
        a0 = _discardBulkStep;
        if (vs_main_buttonRepeat & PADLright) {
            i = -1;
        }
        if (vs_main_buttonRepeat & PADLleft) {
            ++i;
        }
        if (i == 1) {
            if ((a0 & 0xFF) == 2) {
                if (_discardAmount != _discardMaxAmount) {
                    _discardAmount = _discardMaxAmount;
                }
            } else {
                _discardBulkStep = a0 + 1;
            }
        } else if (i == -1) {
            if (!(a0 & 0xFF)) {
                if (_discardAmount != 0) {
                    _discardAmount = 0;
                }
            } else {
                _discardBulkStep = a0 - 1;
            }
        }
        if ((a0 != _discardBulkStep) || (a2 != _discardAmount)) {
            vs_battle_playMenuChangeSfx();
        }
        func_800C7210(5);
        temp_v0_7 = vs_battle_toBCD(_discardAmount);
        func_800C70F8(temp_v0_7 & 0xF, 0x42, 0x82, D_1F800000[2] - 3);
        temp_v0_8 = vs_battle_toBCD(temp_v0_7 >> 4);
        func_800C70F8(temp_v0_8 & 0xF, 0x3C, 0x82, D_1F800000[2] - 3);
        func_800C70F8(temp_v0_8 >> 4, 0x36, 0x82, D_1F800000[2] - 3);
        D_80109A07 =
            func_800FFCDC(D_80109A07, (0x36 - (_discardBulkStep * 6)) | 0x720000);
        break;
    case discardMultipleConfirm:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                discardMultipleText[i * 2] = (char*)&vs_mainMenu_itemHelp
                    [vs_mainMenu_itemHelp[i + VS_ITEMHELP_BIN_INDEX_confirmYes]];
                discardMultipleText[i * 2 + 1] =
                    (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_discardConfirm];
                discardMultipleRowTypes[i] = 0;
            }

            func_800FF0EC(2, 4, discardMultipleText, discardMultipleRowTypes);
            D_80109A4E = execDiscardMultiple;
        }
        break;
    case execDiscardMultiple:
        func_800FF43C();
        i = func_800FF360() + 1;
        if (i != 0) {
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0x1C);
                if (vs_menuD_containerData->data.misc[_discardIndex].count
                    == _discardAmount) {
                    _initContainerObject(_discardItemCategory, _discardIndex,
                        &vs_menuD_containerData->data);
                } else {
                    vs_menuD_containerData->data.misc[_discardIndex].count -=
                        _discardAmount;
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
    vs_battle_renderTextRawColor("/", temp_s0, 0x808080, NULL);
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
        func_80106464(vs_mainMenu_inventoryItemCapacities[i],
            ((0x64 + 0xC * i) << 16) | 0x70,
            _countContainerItems(i, &vs_menu_inventoryStorage->unk105B0.data));
        vs_battle_renderTextRaw(D_80109A10[i], ((0x64 + 0xC * i) << 16) | 0xA0, NULL);
        func_80106464(_containerItemCapacities[i], ((0x64 + 0xC * i) << 16) | 0xF8,
            _countContainerItems(i, &vs_menu_inventoryStorage->unkC430.data));
    }
}

int _getWeaponsubItemCount(int arg0)
{
    int i;
    vs_battle_inventoryWeapon* temp = &vs_menuD_containerData->data.weapons[arg0];
    int count = 0;

    for (i = 0; i < vs_menuD_containerData->data.grips[temp->grip - 1].gemSlots; ++i) {
        count += temp->gems[i] != 0;
    }
    return count;
}

int _getShieldsubItemCount(int arg0)
{
    int i;
    vs_battle_inventoryShield* shield = &vs_menuD_containerData->data.shields[arg0];
    int count = 0;

    for (i = 0; i < shield->base.gemSlots; ++i) {
        count += shield->gems[i] != 0;
    }
    return count;
}

int func_801066DC(int arg0, int arg1)
{
    int temp_s0 = _countContainerItems(arg0, &D_80109A88->data);
    int temp_s1 =
        arg1 + (temp_s0 + _countContainerItems(arg0, &vs_menu_inventoryStorage->unk87B0));

    if (D_80109A7A != 0) {
        return _containerItemCapacities[arg0] < temp_s1;
    }
    return vs_mainMenu_inventoryItemCapacities[arg0] < temp_s1;
}

int func_80106784(int arg0, int arg1)
{
    int i;

    for (i = 0; i < 64; ++i) {
        if (vs_menu_inventoryStorage->itemsToTransfer[i] == 0) {
            break;
        }
    }

    if (arg0 == 0) {
        i += 2 + _getWeaponsubItemCount(arg1);
    }

    if (arg0 == 3) {
        i += _getShieldsubItemCount(arg1);
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
        if (func_801066DC(5, _getWeaponsubItemCount(arg1)) != 0)
            return 2;
    }

    if (arg0 == 3 && func_801066DC(5, _getShieldsubItemCount(arg1)) != 0) {
        return 2;
    }

    return 0;
}

void func_801068BC(int arg0)
{
    int temp_s0_2;
    int temp_s2;
    int temp_s0;

    temp_s0 = vs_menu_inventoryStorage->itemsToTransfer[arg0];
    temp_s2 = temp_s0 >> 8;
    temp_s0_2 = (temp_s0 - 1) & 0xFF;
    _copyContainerItem(temp_s2 | 0x10, &vs_menuD_containerData->data, temp_s0_2,
        &vs_menu_inventoryStorage->unk87B0);
    _initContainerObject(temp_s2, temp_s0_2, &vs_menu_inventoryStorage->unk87B0);
}

void func_80106948(int arg0, int arg1)
{
    _copyContainerItem(arg0 | 0x10, &vs_menu_inventoryStorage->unk87B0, arg1,
        &vs_menuD_containerData->data);
    _initContainerObject(arg0, arg1, &vs_menuD_containerData->data);
}

static int func_801069B0(int arg0, int arg1)
{
    int i;

    for (i = 0; i < 64; ++i) {
        if (vs_menu_inventoryStorage->itemsToTransfer[i] == ((arg0 << 8) | (arg1 + 1))) {
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
    var_v1 = (u_short*)vs_menu_inventoryStorage + 0x61D8;
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
    u_short* temp_s2 = vs_menu_inventoryStorage->itemsToTransfer;

    for (i = 0; i < 64; ++i) {
        int source = temp_s2[i];
        if ((source != 0)
            && (_getContainerItemId((source >> 8), (source - 1) & 0xFF,
                    &vs_menu_inventoryStorage->unk87B0)
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
        for (i = 0; i < _containerItemCapacities[k]; ++i) {
            if ((_getContainerItemId(k, i, &vs_menu_inventoryStorage->unk87B0) != 0)
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
            temp_v0->initialX = temp_v0->targetX;
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
                vs_mainMenu_clearMenuExcept(0);
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
        vs_battle_rMemzero(
            &vs_menu_inventoryStorage->unk87B0, sizeof vs_menu_inventoryStorage->unk87B0);
        vs_battle_rMemzero(vs_menu_inventoryStorage->itemsToTransfer,
            sizeof vs_menu_inventoryStorage->itemsToTransfer);
        D_80109A7A = arg0 - 1;
        if (D_80109A7A) {
            vs_menuD_containerData = &vs_menu_inventoryStorage->unk105B0;
            D_80109A88 = &vs_menu_inventoryStorage->unkC430;
        } else {
            vs_menuD_containerData = &vs_menu_inventoryStorage->unkC430;
            D_80109A88 = &vs_menu_inventoryStorage->unk105B0;
        }
        D_80109A68 = 1;
        return 0;
    }
    var_s4 = (D_800F4EE8.unkA0[0] - 1) & 7;
    temp_s1 = _getContainerIndicesOffset(var_s4, vs_menuD_containerData);

    switch (D_80109A68) { /* switch 1 */
    case 0:
        func_800FFBC8();
        /* fallthrough */
    case 1:
        temp_s1 = vs_main_allocHeapR(0x6C00);
        temp_s6 = (void*)temp_s1 + 0x6000;
        temp_s5 = (void*)temp_s1 + 0x6400;
        D_801023E3 = 1;

        for (temp_s3 = 0; temp_s3 < 7; ++temp_s3) {
            _defragmentContainerItems(temp_s3, vs_menuD_containerData);
        }

        func_80106A50();
        temp_s2 = func_80106C64(var_s4, temp_s5, temp_s6, (char*)temp_s1);
        D_80109A69 = temp_s2 == 0;
        if (D_80109A69 != 0) {
            vs_mainmenu_setMessage(
                (char*)&D_8010952C[D_8010952C[D_80109A7A + 27 + (var_s4 == 7) * 2]]);
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
                if (vs_menu_inventoryStorage->itemsToTransfer[0] == 0) {
                    return -1;
                }
                if (var_s4 == 7) {
                    func_801072B0(1);
                    D_80109A68 = 0xF;
                } else {
                    D_800F4EE8.unkA0[0] = 0;
                    vs_mainMenu_clearMenuExcept(0);
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
                        vs_battle_getMenuItem(temp_s0 >> 8)->itemState = 0;
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
                    vs_mainMenu_clearMenuExcept(0);
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
                if (vs_menu_inventoryStorage->itemsToTransfer[0] == 0) {
                    vs_mainMenu_clearMenuExcept(0);
                    return -1;
                }
                if (var_s4 != 7) {
                    D_800F4EE8.unkA0[0] = 0;
                    vs_mainMenu_clearMenuExcept(0);
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
                        vs_mainMenu_clearMenuExcept(0);
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
                    && (vs_menuD_containerData->data.misc[temp_s0 - 1].id
                        == vs_menuD_containerData->data.misc[var_a2 - 1].id)) {
                    vs_menuD_containerData->data.misc[var_a2 - 1].count +=
                        vs_menuD_containerData->data.misc[temp_s0 - 1].count;
                    if (vs_menuD_containerData->data.misc[var_a2 - 1].count > 0x64) {
                        vs_menuD_containerData->data.misc[temp_s0 - 1].count =
                            vs_menuD_containerData->data.misc[var_a2 - 1].count - 0x64;
                        vs_menuD_containerData->data.misc[var_a2 - 1].count = 0x64;
                    } else {
                        _initContainerObject(
                            6, temp_s0 - 1, &vs_menuD_containerData->data);
                    }
                } else {
                    temp_s1[temp_s3 - 1] = var_a2;
                    temp_s1[temp_s2 - 1] = temp_s0;
                }
                vs_mainMenu_clearMenuExcept(0);
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
            if (temp_v0_11->initialX >= 0xB5) {
                if (temp_v0_11->initialX >= 0xCD) {
                    temp_v0_11->initialX = (u_short)temp_v0_11->initialX - 0x18;
                }
                temp_v0_11->state = 2;
                temp_v0_11->targetX = 0xB4;
            }
            D_80109A68 = 1;
        }
        break;
    case 8:
        D_80109A7D = 0;
        temp_s3 = temp_s1[D_80109A6C - 1] - 1;
        vs_battle_rMemzero(vs_battle_rowTypeBuf, 0x10);
        temp_s0 = 0;
        temp_s2 = 0x33;
        switch (var_s4) {
        case 0:
            temp_s0 = vs_menuD_containerData->data.weapons[temp_s3].isEquipped;
            temp_s2 = 0x4A;
            break;
        case 3:
            temp_s0 = vs_menuD_containerData->data.shields[temp_s3].isEquipped;
            temp_s2 = 0x4A;
            break;
        case 4:
            temp_s0 = vs_menuD_containerData->data.armor[temp_s3].bodyPart;
            temp_s2 = 0x4A;
            break;
        case 6:
            temp_s0 = (vs_menuD_containerData->data.misc[temp_s3].id < 0x1CA) ^ 1;
            break;
        }

        var_a2 = _getParentItemIndex(var_s4, temp_s3, &vs_menuD_containerData->data);
        var_a1 = 8;

        if (var_a2 != 0) {
            temp_s0 = 1;
            temp_s2 =
                D_8010952C[vs_menuD_containerData->data.weapons[var_a2 - 1].isEquipped
                                   == 0
                               ? 5
                               : 4];
        }

        var_a2 = _getSetShieldIndex(var_s4, temp_s3, &vs_menuD_containerData->data);
        var_a1 = 8;

        if (var_a2 != 0) {
            temp_s0 = 1;
            temp_s2 =
                D_8010952C[vs_menuD_containerData->data.shields[var_a2 - 1].isEquipped
                                   == 0
                               ? 5
                               : 4];
        }

        var_a2 = temp_s0;

        if (temp_s0 != 0) {
            sp10[1] = &D_8010952C[temp_s2];
        } else if (var_s4 == 6) {
            int temp_s0 = 0;

            for (temp_s2 = 0; temp_s2 < 7; ++temp_s2) {
                temp_s0 +=
                    _countContainerItems(temp_s2, &vs_menu_inventoryStorage->unk87B0);
            }

            func_801031A0();
            var_a2 = _copyContainerItem(6, &vs_menu_inventoryStorage->unk4BB0, temp_s3,
                &vs_menuD_containerData->data);
            if ((D_80109A7A == 0) && (var_a2 > 0x40)) {
                var_a2 = 0;
            }
            temp_s2 = 0xAB;
            if (var_a2 != 0) {
                if (temp_s0 == 0x40) {
                    int i;
                    int temp_a0 = vs_menuD_containerData->data.misc[temp_s3].count;
                    for (i = 0; i < 256; ++i) {
                        if (vs_menu_inventoryStorage->unk87B0.misc[i].id
                            == vs_menuD_containerData->data.misc[temp_s3].id) {
                            temp_a0 +=
                                vs_menu_inventoryStorage->unk87B0.misc[i].count - 0x64;
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
            vs_battle_rowTypeBuf[0] = 1;
        } else {
            sp10[1] = &D_8010952C[D_8010952C[D_80109A7A * 2 + 0x20]];
        }
        D_80109A61 = 1;
        temp_s2 = 1;
        if (((u_int)(var_s4 - 1) < 2) || ((var_s4 == 5))) {
            sp10[2] = vs_mainMenu_itemHelp + 0x3527;
            sp10[3] = vs_mainMenu_itemHelp + 0x352C;
            if ((_getParentItemIndex(var_s4, temp_s3, &vs_menuD_containerData->data) == 0)
                && (_getSetShieldIndex(var_s4, temp_s3, &vs_menuD_containerData->data)
                    == 0)) {
                sp10[3] = vs_mainMenu_itemHelp + 0x35B2;
                vs_battle_rowTypeBuf[1] = 1;
            }
            ++temp_s2;
            D_80109A60[temp_s2] = 2;
        }
        temp_s0 = 0;
        sp10[temp_s2 * 2] = vs_mainMenu_itemHelp + 0x354A;
        sp10[temp_s2 * 2 + 1] = vs_mainMenu_itemHelp + 0x354F;
        switch (var_s4) {
        case 0:
            temp_s0 = vs_menuD_containerData->data.weapons[temp_s3].isEquipped != 0;
            break;
        case 3:
            temp_s0 = vs_menuD_containerData->data.shields[temp_s3].isEquipped != 0;
            break;
        case 4:
            temp_s0 = vs_menuD_containerData->data.armor[temp_s3].bodyPart != 0;
            break;
        case 6:
            if (vs_menuD_containerData->data.misc[temp_s3].id >= 0x1CA) {
                temp_s0 = 3;
            }
            break;
        }
        var_a2 = _getParentItemIndex(var_s4, temp_s3, &vs_menuD_containerData->data);
        if (var_a2 != 0) {
            temp_s0 = 1;
            if (vs_menuD_containerData->data.weapons[var_a2 - 1].isEquipped == 0) {
                temp_s0 = 2;
            }
        }
        var_a2 = _getSetShieldIndex(var_s4, temp_s3, &vs_menuD_containerData->data);
        if (var_a2 != 0) {
            temp_s0 = 1;
            if (vs_menuD_containerData->data.shields[var_a2 - 1].isEquipped == 0) {
                temp_s0 = 2;
            }
        }
        if (temp_s0 != 0) {
            sp10[temp_s2 * 2 + 1] =
                &vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[temp_s0 + 663]];
            temp_s0 = 1;
        }
        vs_battle_rowTypeBuf[temp_s2++] = temp_s0;
        D_80109A60[temp_s2] = 3;
        if (var_s4 == 6) {
            sp10[temp_s2 * 2] = vs_mainMenu_itemHelp + 0x356D;
            sp10[temp_s2 * 2 + 1] = vs_mainMenu_itemHelp + 0x3574;
            if (vs_menuD_containerData->data.misc[temp_s3].id >= 0x1CA) {
                sp10[temp_s2 * 2 + 1] = vs_mainMenu_itemHelp + 0x350E;
                vs_battle_rowTypeBuf[temp_s2] = 1;
            }
            ++temp_s2;
            D_80109A60[temp_s2] = 4;
        }

        sp10[temp_s2 * 2] = vs_mainMenu_itemHelp + 0x3586;
        sp10[temp_s2 * 2 + 1] = vs_mainMenu_itemHelp + 0x358A;
        ++temp_s2;
        D_80109A60[temp_s2] = 5;
        func_800FF0EC(temp_s2, var_s4 + 0x59, (char**)&sp10, (int*)vs_battle_rowTypeBuf);
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
                    func_80106948(var_s4, _getContainerIndicesOffset(var_s4,
                                              vs_menuD_containerData)[D_80109A6C - 1]
                                              - 1);
                    vs_mainMenu_clearMenuExcept(0);
                    D_80109A68 = 4;
                    break;
                case 2:
                    func_800FFBC8();
                    vs_mainMenu_clearMenuExcept(0);
                    D_80109A68 = 10;
                    break;
                case 3:
                    temp_s2 = temp_s1[D_80109A6C - 1] | (var_s4 << 0xC);
                    if ((var_s4 == 6)
                        && (vs_menuD_containerData->data.misc[temp_s1[D_80109A6C - 1] - 1]
                                .count
                            >= 2)) {
                        temp_s2 |= 0x10000;
                    }
                    _displayDiscardMenu(temp_s2);
                    D_80109A68 = 0xB;
                    break;
                case 4:
                    _displayDiscardMenu(
                        temp_s1[D_80109A6C - 1] | (var_s4 << 0xC) | 0x20000);
                    D_80109A68 = 0xB;
                    break;
                case 5:
                    func_800FFBC8();
                    _displaySortMenu(var_s4 + 1);
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
            temp_s3 = _getParentItemIndex(
                var_s4, temp_s1[D_80109A6C - 1] - 1, &vs_menuD_containerData->data);
            if (temp_s3 != 0) {
                var_s4 = 0;
            } else {
                temp_s3 = _getSetShieldIndex(
                    var_s4, temp_s1[D_80109A6C - 1] - 1, &vs_menuD_containerData->data);
                var_s4 = 3;
            }
            temp_s2 = _countContainerItems(var_s4, &vs_menuD_containerData->data);
            temp_v0_17 = _getContainerItemIndex(var_s4, temp_s3 - 1,
                _getContainerIndicesOffset(var_s4, vs_menuD_containerData));
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
        temp_s3 = _displayDiscardMenu(0);
        if (temp_s3 != 0) {
            func_800FFBC8();
            func_800FA854(0x28);
            vs_mainMenu_clearMenuExcept(0);
            if (temp_s3 == -2) {
                return -2;
            }
            D_80109A68 = 4;
        }
        break;
    case 12:
        temp_s3 = _displaySortMenu(0);
        if (temp_s3 != 0) {
            func_800FA854(0x28);
            vs_mainMenu_clearMenuExcept(0);
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
                    while ((temp_s2 = vs_menu_inventoryStorage->itemsToTransfer[0])) {
                        _copyContainerItem((temp_s2 >> 8) | 0x10, &D_80109A88->data,
                            (temp_s2 - 1) & 0xFF, &vs_menu_inventoryStorage->unk87B0);
                        _initContainerObject((temp_s2 >> 8), (temp_s2 - 1) & 0xFF,
                            &vs_menu_inventoryStorage->unk87B0);
                        func_80106A50();
                    }
                } else {
                    while ((temp_s2 = vs_menu_inventoryStorage->itemsToTransfer[0])) {
                        _copyContainerItem((temp_s2 >> 8) | 0x10, &D_80109A88->data,
                            (temp_s2 - 1) & 0xFF, &vs_menu_inventoryStorage->unk87B0);
                        _initContainerObject((temp_s2 >> 8), (temp_s2 - 1) & 0xFF,
                            &vs_menu_inventoryStorage->unk87B0);
                        func_80106A50();
                    }
                }
                for (temp_s3 = 0; temp_s3 < 7; ++temp_s3) {
                    _defragmentContainerItems(temp_s3, D_80109A88);
                }
                vs_mainMenu_clearMenuExcept(0);
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
        temp_v0_2->targetX = 0xC2;
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
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
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
        vs_battle_renderTextRawColor("OK", 0x4200C8,
            ((rsin((D_80109A2C) * 8) >> 5) + 0x40) * 0x10101, D_1F800000[1] - 3);
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
