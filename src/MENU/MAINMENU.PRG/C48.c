#include "common.h"
#include "C48.h"
#include "413C.h"
#include "../SLUS_010.40/main.h"
#include "../MENUD.PRG/234.h"
#include "../BATTLE/BATTLE.PRG/146C.h"
#include "../BATTLE/BATTLE.PRG/2842C.h"
#include "../BATTLE/BATTLE.PRG/30D14.h"
#include "../BATTLE/BATTLE.PRG/44F14.h"
#include "../BATTLE/BATTLE.PRG/573B8.h"
#include "../BATTLE/BATTLE.PRG/5BF94.h"
#include "../BATTLE/BATTLE.PRG/func_8006B57C_t.h"
#include "../../assets/MENU/ITEMHELP.BIN.h"
#include "../../assets/MENU/ITEMNAME.BIN.h"
#include <libetc.h>
#include <limits.h>

int func_800FA238(int arg0, int arg1, int arg2);
void func_800FA3FC(int arg0);
void func_800FB3C8(int);

static short _weaponTitleSubmaxThresholds[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
    SHRT_MAX };

static short _weaponTitleMaxThresholds[] = { 50, 95, SHRT_MAX, 8192 }; // Last one junk?

extern int D_80102034;
extern int D_801020F4;
extern u_char D_801020F8;
extern short _currentDp;
extern short _maxDp;
extern short _currentPp;
extern short _maxPp;
extern char D_80102480[];
extern u_short D_80102488[];
extern char D_80102490[8];
extern u_short D_80102498[];
extern char D_801024A1;

void func_800FA448(void)
{
    vs_battle_actor2* temp_s1;
    int i;

    temp_s1 = vs_battle_characterState->unk3C;

    if (temp_s1->weapon.unk10D != 0) {
        vs_battle_copyEquippedWeaponStats(
            &vs_battle_inventory.weapons[temp_s1->weapon.unk10D - 1], &temp_s1->weapon);
    }

    if (temp_s1->shield.unkDA != 0) {
        vs_battle_copyEquippedShieldStats(
            &vs_battle_inventory.shields[temp_s1->shield.unkDA - 1], &temp_s1->shield);
    }

    for (i = 0; i < 6; ++i) {
        if (temp_s1->bodyParts[i].armor.unk9A != 0) {
            vs_battle_copyEquippedArmorStats(
                &vs_battle_inventory.armor[temp_s1->bodyParts[i].armor.unk9A - 1],
                &temp_s1->bodyParts[i].armor);
        }
    }

    if (temp_s1->accessory.unk37 != 0) {
        vs_battle_copyEquippedAccessoryStats(
            &vs_battle_inventory.armor[temp_s1->accessory.unk37 - 1],
            &temp_s1->accessory);
    }
}

void func_800FA568(void) { }

void func_800FA570(void)
{
    func_8009967C();
    func_800995B0();
}

static int _getEquipmentMaxStats(void* item, u_int itemCategory)
{
    int i;
    int subMaxRank;
    int maxRank;
    int isAffinity = 0;
    int param = 0;
    int maxParam = 0;
    int subMaxParam = 0;

    switch (itemCategory) {
    case 0:
        for (i = 0; i < 6; ++i) {
            if (maxParam
                < ((vs_battle_uiWeapon*)(item))->classAffinityCurrent.class[1][i]) {
                subMaxParam = maxParam;
                maxParam =
                    ((vs_battle_uiWeapon*)(item))->classAffinityCurrent.class[1][i];
                param = i;
            } else if (subMaxParam < ((vs_battle_uiWeapon*)(item))
                                         ->classAffinityCurrent.class[1][i]) {
                subMaxParam =
                    ((vs_battle_uiWeapon*)(item))->classAffinityCurrent.class[1][i];
            }
        }

        for (i = 0; i < 7; ++i) {
            if (maxParam
                < ((vs_battle_uiWeapon*)(item))->classAffinityCurrent.affinity[1][i]) {
                subMaxParam = maxParam;
                maxParam =
                    ((vs_battle_uiWeapon*)(item))->classAffinityCurrent.affinity[1][i];
                param = i;
                isAffinity = 1;
            } else if (subMaxParam < ((vs_battle_uiWeapon*)(item))
                                         ->classAffinityCurrent.affinity[1][i]) {
                subMaxParam =
                    ((vs_battle_uiWeapon*)(item))->classAffinityCurrent.affinity[1][i];
            }
        }

        break;

    case 1:
        for (i = 0; i < 6; ++i) {
            if (maxParam
                < ((vs_battle_uiShield*)(item))->classAffinityCurrent.class[1][i]) {
                subMaxParam = maxParam;
                maxParam =
                    ((vs_battle_uiShield*)(item))->classAffinityCurrent.class[1][i];
                param = i;
            } else if (subMaxParam < ((vs_battle_uiShield*)(item))
                                         ->classAffinityCurrent.class[1][i]) {
                subMaxParam =
                    ((vs_battle_uiShield*)(item))->classAffinityCurrent.class[1][i];
            }
        }

        for (i = 0; i < 7; ++i) {
            if (maxParam
                < ((vs_battle_uiShield*)(item))->classAffinityCurrent.affinity[1][i]) {
                subMaxParam = maxParam;
                maxParam =
                    ((vs_battle_uiShield*)(item))->classAffinityCurrent.affinity[1][i];
                param = i;
                isAffinity = 1;
            } else if (subMaxParam < ((vs_battle_uiShield*)(item))
                                         ->classAffinityCurrent.affinity[1][i]) {
                subMaxParam =
                    ((vs_battle_uiShield*)(item))->classAffinityCurrent.affinity[1][i];
            }
        }

        break;

    case 2:
    default:
        for (i = 0; i < 6; ++i) {
            if (maxParam
                < ((vs_battle_uiArmor*)(item))->classAffinityCurrent.class[1][i]) {
                subMaxParam = maxParam;
                maxParam = ((vs_battle_uiArmor*)(item))->classAffinityCurrent.class[1][i];
                param = i;
            } else if (subMaxParam
                       < ((vs_battle_uiArmor*)(item))->classAffinityCurrent.class[1][i]) {
                subMaxParam =
                    ((vs_battle_uiArmor*)(item))->classAffinityCurrent.class[1][i];
            }
        }

        for (i = 0; i < 7; ++i) {
            if (maxParam
                < ((vs_battle_uiArmor*)(item))->classAffinityCurrent.affinity[1][i]) {
                subMaxParam = maxParam;
                maxParam =
                    ((vs_battle_uiArmor*)(item))->classAffinityCurrent.affinity[1][i];
                param = i;
                isAffinity = 1;
            } else if (subMaxParam < ((vs_battle_uiArmor*)(item))
                                         ->classAffinityCurrent.affinity[1][i]) {
                subMaxParam =
                    ((vs_battle_uiArmor*)(item))->classAffinityCurrent.affinity[1][i];
            }
        }

        break;
    }

    subMaxRank = 0;
    for (i = 0; i < 11; ++i) {
        if (subMaxParam < _weaponTitleSubmaxThresholds[i]) {
            subMaxRank = i;
            break;
        }
    }

    maxRank = 0;
    for (i = 0; i < 3; ++i) {
        if (maxParam < _weaponTitleMaxThresholds[i]) {
            maxRank = i;
            break;
        }
    }

    {
        int a = (isAffinity * 6) + param;
        int b = subMaxRank + (maxRank << 8);
        return b + (a << 16);
    }
}

void func_800FA810(int arg0)
{
    vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(arg0 + 32);
    if (menuItem->state != 0) {
        menuItem->state = 5;
        menuItem->targetX = -menuItem->w;
    }
}

void func_800FA854(int arg0)
{
    int i;

    for (i = 0; i < 8; ++i) {
        if (i != arg0) {
            func_800FA810(i);
        }
    }
}

void vs_mainMenu_menuItemLeaveRight(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_getMenuItem(arg0);
    if (menuItem->state != 0) {
        menuItem->state = 2;
        menuItem->targetX = 320;
    }
}

void vs_mainMenu_clearMenuExcept(enum vs_mainMenu_menuItemIds id)
{
    int i;

    for (i = 0; i < 32; ++i) {
        if (i != id) {
            vs_mainMenu_menuItemLeaveRight(i);
        }
    }
}

void func_800FA92C(int arg0, int arg1)
{
    vs_battle_menuItem_t* menuItem;
    int i;

    for (i = arg1 * 10; i < 30; ++i) {
        vs_mainMenu_menuItemLeaveRight(i);
    }

    menuItem = vs_battle_getMenuItem(arg0 + (arg1 * 10));
    menuItem->state = 4;
    menuItem->targetX = 180;
    menuItem->unk1A = (arg1 * 16) + 18;
    if (menuItem->unk2 == 0) {
        menuItem->unk2 = 1;
    }
}

int vs_mainmenu_ready(void)
{
    vs_battle_menuItem_t* menuItem;
    int i;

    menuItem = vs_battle_getMenuItem(0);

    for (i = 0; i < 40; ++i) {
        if (menuItem->state > 1) {
            return 0;
        }
        ++menuItem;
    }
    return 1;
}

int func_800FAA20(void)
{
    int temp_s0 = ++D_80102034;
    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    return temp_s0 == 5;
}

int func_800FAA5C(int arg0)
{
    if (arg0 & 0x40) {
        vs_battle_menuState.currentState = 0;
        func_800C930C(1);
        return 0;
    }
    if (D_800F4FDB == 0) {
        func_8007E0A8(0x1A, 3, 6);
    }
    vs_battle_menuState.currentState = 0x7F;
    return 1;
}

// https://decomp.me/scratch/b42Kb
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FAAC8);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FAEBC);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", D_800F9814);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", func_800FB3C8);

int func_800FBB64(int arg0)
{
    do {
        arg0 = (arg0 + 1) & 3;
    } while (!((D_80102544 >> arg0) & 1));
    return arg0;
}

void func_800FBB8C(int arg0)
{
    D_80102544 = arg0;
    if (!((arg0 >> D_801024B9) & 1)) {
        D_801024B9 = func_800FBB64(D_801024B9);
    }
}

void func_800FBBD4(int arg0)
{
    int var_s1;
    int var_s0;

    var_s1 = 1;
    if (arg0 != 0) {
        if (arg0 > 0) {
            D_801024B9 = 3;
            func_800FBB8C(arg0);
        }
        D_801020F4 = arg0;
        D_801020F8 = 10;
        return;
    }
    var_s0 = D_801024B9;
    if (D_801020F4 > 0) {
        var_s1 = -vs_battle_rowAnimationSteps[D_801020F8];
        if (D_801020F8 != 0) {
            --D_801020F8;
        } else if (vs_main_buttonsPressed.all & PADRleft) {
            var_s0 = func_800FBB64(var_s0);
            if (var_s0 != D_801024B9) {
                vs_main_playSfxDefault(0x7E, 14);
            } else {
                func_800C02E0();
            }
        }
    } else {
        if (D_801020F8 != 0) {
            --D_801020F8;
            var_s1 = (D_801020F8 - 10) * 24;
        }
    }
    if (var_s1 <= 0) {
        func_800FB3C8(var_s1);
    }
    D_801024B9 = var_s0;
}

void vs_mainMenu_setRangeRisk(int arg0, int arg1, int arg2, int arg3)
{
    D_80102480[0] = arg0;
    D_80102480[1] = arg1;
    D_80102480[2] = arg2;
    D_80102480[3] = arg3;
}

void vs_mainMenu_setStrIntAgi(int strength, int intelligence, int agility, int arg3)
{
    vs_mainMenu_strIntAgi[0].strength = strength;
    vs_mainMenu_strIntAgi[0].intelligence = intelligence;
    vs_mainMenu_strIntAgi[0].agility = agility;
    vs_mainMenu_strIntAgi[0].unk6 = arg3;
    vs_mainMenu_setRangeRisk(0, 0, 0, 0);
    vs_battle_memcpy(&vs_mainMenu_strIntAgi[1], &vs_mainMenu_strIntAgi[0],
        sizeof vs_mainMenu_strIntAgi[0]);
}

void func_800FBD80(int arg0)
{
    vs_battle_actor2* temp_t0 = vs_battle_actors[arg0 & 0xF]->unk3C;
    D_80102488[3] = arg0 & 0xF;
    D_80102498[0] = temp_t0->accessory.currentStr;
    D_80102498[1] = temp_t0->accessory.currentInt;
    D_80102498[2] = temp_t0->accessory.currentAgility;
    D_80102488[0] = temp_t0->strength;
    D_80102488[1] = temp_t0->intelligence;
    D_80102488[2] = temp_t0->agility;
    D_80102488[4] = temp_t0->totalStrength;
    D_80102488[5] = temp_t0->totalIntelligence;
    vs_mainMenu_equipmentSubtype = 0;
    D_80102488[6] = temp_t0->totalAgility;

    if (arg0 < 16) {
        int i;
        for (i = 0; i < 3; ++i) {
            D_80102488[i] -= D_80102488[4 + i];
        }
        vs_mainMenu_setStrIntAgi(temp_t0->totalStrength, temp_t0->totalIntelligence,
            temp_t0->totalAgility, temp_t0->flags.fields.unk2_1 | (arg0 == 0));
        vs_battle_rMemzero(&D_80102490, 8);
    }
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", vs_battle_renderEquipStats);

void vs_mainMenu_setDpPp(int currentDp, int maxDp, int currentPp, int maxPp)
{
    _currentPp = currentPp;
    _maxPp = maxPp;
    _currentDp = (currentDp + 99) / 100;
    _maxDp = (maxDp + 99) / 100;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/C48", vs_mainMenu_drawDpPpbars);

vs_battle_menuItem_t* func_800FC510(int arg0, int arg1, int arg2)
{
    char* menuText[2];
    int rowType;
    int initialX;
    int var_s0;
    int gem;

    vs_battle_menuItem_t* menuItem = NULL;
    vs_battle_inventoryWeapon* weapon = &D_80102470[arg1 - 1];
    int grip = weapon->grip;
    int gemSlots = D_80102460[grip - 1].gemSlots;
    int var_s1 = 158;

    if (arg0 == 1) {
        vs_mainMenu_setBladeUi(
            &D_80102464[weapon->blade - 1], menuText, &rowType, vs_battle_stringBuf);
    } else if (arg0 == 2) {
        vs_mainMenu_setGripUi(
            &D_80102460[grip - 1], menuText, &rowType, vs_battle_stringBuf);
    } else {
        var_s1 = arg0 - 3;
        if (var_s1 < gemSlots) {
            menuText[1] = NULL;
            rowType = 0x58000000;
            menuText[0] = (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_none];
            gem = weapon->gems[var_s1];
            if (gem != 0) {
                vs_mainMenu_setGemUi(
                    &D_80102458[gem - 1], menuText, &rowType, vs_battle_stringBuf);
            }
            var_s1 = 151;
        } else {
            var_s1 = 0;
        }
    }

    var_s0 = arg0 + 10;
    vs_mainMenu_deactivateMenuItem(var_s0);

    if (var_s1 != 0) {
        initialX = 320 - var_s1;
        menuItem = vs_battle_setMenuItem(
            var_s0, initialX, (arg0 * 16) + 18, var_s1, 0, menuText[0]);
        menuItem->unk7 = menuText[1] == NULL;
        if (arg2 & 1) {
            menuItem->initialX = 320;
            menuItem->state = 2;
            menuItem->targetX = initialX;
        }
        menuItem->icon = (u_int)rowType >> 0x1A;
        menuItem->material = ((u_int)rowType >> 16) & 7;
    }

    return menuItem;
}

vs_battle_menuItem_t* func_800FC704(int arg0, int arg1, int arg2)
{
    char* sp18[2];
    int rowType;
    vs_battle_inventoryShield* shield;
    int var_s0;
    char temp_v1;
    vs_battle_menuItem_t* menuItem;

    menuItem = NULL;
    var_s0 = arg0 - 1;
    shield = &D_8010246C[arg1 - 1];

    if (var_s0 < shield->base.gemSlots) {
        sp18[1] = 0;
        rowType = 0x58000000;
        sp18[0] = (char*)&vs_mainMenu_itemHelp[0x0340B];
        temp_v1 = shield->gems[var_s0];
        if (temp_v1 != 0) {
            vs_mainMenu_setGemUi(
                &D_80102458[temp_v1 - 1], (char**)&sp18, &rowType, vs_battle_stringBuf);
        }
        var_s0 = 151;
    } else {
        var_s0 = 0;
    }

    vs_mainMenu_deactivateMenuItem(arg0 + 10);

    if (var_s0 != 0) {
        menuItem = vs_battle_setMenuItem(
            arg0 + 10, 0x140 - var_s0, (arg0 * 16) + 18, var_s0, 0, (char*)sp18[0]);
        menuItem->unk7 = sp18[1] == 0;
        if (arg2 & 1) {
            menuItem->initialX = 320;
            menuItem->state = 2;
            menuItem->targetX = 320 - var_s0;
        }
        menuItem->icon = 0x16;
    }
    return menuItem;
}

void vs_mainMenu_setWeaponUi(
    vs_battle_uiWeapon* weapon, char** text, int* rowTypes, char* buf)
{
    int maxStatRank;

    vs_battle_uiEquipment* blade = &weapon->blade;
    int stats = _getEquipmentMaxStats(weapon, 0);

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
    text[1] = buf;
    rowTypes[0] = (blade->category << 0x1A) + (blade->material << 0x10);
}

void vs_mainMenu_initUiWeapon(
    vs_battle_inventoryWeapon* source, char** text, int* rowTypes, char* buf)
{
    vs_battle_uiWeapon target;

    if (D_80102470 == vs_battle_inventory.weapons) {
        vs_battle_applyWeapon(&target, source);
    } else {
        vs_menuD_initUiWeapon(&target, source, &vs_menuD_containerData->data);
    }
    vs_mainMenu_setWeaponUi(&target, text, rowTypes, buf);
    text[0] = source->name;
}

void vs_mainMenu_setBladeUi(
    vs_battle_inventoryBlade* blade, char** text, int* rowType, char* buf)
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
    text[0] = vs_mainMenu_itemNames[blade->id + VS_ITEMNAME_BIN_INDEX_item0];
    text[1] = buf;
    rowType[0] = (blade->category << 0x1A) + (blade->material << 0x10);
}

void vs_mainMenu_setGripUi(
    vs_battle_inventoryGrip* grip, char** arg1, int* arg2, char* buf)
{
    u_short* id;
    vs_battle_stringContext.strings[5] = (char*)&vs_mainMenu_itemHelp
        [vs_mainMenu_itemHelp[grip->category - 1 + VS_ITEMHELP_BIN_INDEX_shortGrip]];
    id = &grip->id;
    vs_battle_printf(vs_battle_printf(buf,
                         (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[*id - 6]]),
        (char*)&vs_mainMenu_itemHelp[VS_ITEMHELP_BIN_OFFSET_gripTemplate]);
    arg1[0] = vs_mainMenu_itemNames[grip->id + VS_ITEMNAME_BIN_INDEX_item0];
    arg1[1] = buf;
    arg2[0] = (grip->category + 0xA) << 0x1A;
}

void vs_mainMenu_setShieldUi(
    vs_battle_uiShield* shield, char** text, int* rowTypes, char* buf)
{
    int maxStatRank;

    vs_battle_uiEquipment* shieldBase = &shield->base;
    int stats = _getEquipmentMaxStats(shield, 1);

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

    text[0] = vs_mainMenu_itemNames[shieldBase->id + VS_ITEMNAME_BIN_INDEX_item0];
    text[1] = buf;
    rowTypes[0] = (shieldBase->material << 0x10) + 0x3C000000;
}

void vs_mainMenu_initUiShield(
    vs_battle_inventoryShield* shield, char** text, int* rowTypes, char* buf)
{
    vs_battle_uiShield uiShield;

    if (D_8010246C == vs_battle_inventory.shields) {
        vs_battle_applyShield(&uiShield, shield);
    } else {
        vs_menuD_initUiShield(&uiShield, shield, &vs_menuD_containerData->data);
    }
    vs_mainMenu_setShieldUi(&uiShield, text, rowTypes, buf);
}

void vs_mainMenu_setArmorUi(
    vs_battle_uiArmor* armor, char** text, int* rowTypes, char* buf)
{
    int stats;
    int maxStatRank;
    vs_battle_uiEquipment* armorBase = &armor->armor;

    text[0] = vs_mainMenu_itemNames[armorBase->id];
    rowTypes[0] = ((armorBase->category + 0xE) << 0x1A) + (armorBase->material << 0x10);

    if (armorBase->category == 7) {
        text[1] = (char*)&vs_mainMenu_itemHelp
            [vs_mainMenu_itemHelp[armorBase->id + VS_ITEMHELP_BIN_INDEX_line387]];
        return;
    }

    stats = _getEquipmentMaxStats(armor, 2);

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
    text[1] = (char*)buf;
}

void vs_mainMenu_setAccessoryUi(
    vs_battle_inventoryArmor* arg0, char** arg1, int* arg2, char* arg3)
{
    vs_battle_uiArmor sp10;

    vs_battle_applyArmor(&sp10, arg0);
    vs_mainMenu_setArmorUi(&sp10, arg1, arg2, arg3);
}

void vs_mainMenu_setGemUi(
    vs_battle_inventoryGem* arg0, char** arg1, int* arg2, void* arg3)
{
    vs_battle_memcpy(
        arg3, vs_mainMenu_itemHelp + (arg0->id + vs_mainMenu_itemHelp)[-140], 96);
    arg1[0] = vs_mainMenu_itemNames[arg0->id];
    arg1[1] = arg3;
    *arg2 = 0x58000000;
}

void vs_mainMenu_setItemUi(
    vs_battle_inventoryMisc* arg0, char** arg1, int* arg2, void* arg3)
{
    vs_battle_memcpy(
        arg3, vs_mainMenu_itemHelp + (arg0->id + vs_mainMenu_itemHelp)[-140], 96);
    arg1[0] = vs_mainMenu_itemNames[arg0->id];
    arg1[1] = arg3;
    *arg2 = arg0->count << 9;
}

void vs_mainMenu_resetStats(void)
{
    vs_battle_rMemzero(vs_mainMenu_equipmentStats, sizeof vs_mainMenu_equipmentStats);
    vs_mainMenu_setDpPp(0, 0, 0, 0);
    vs_mainMenu_setStrIntAgi(0, 0, 0, 1);
}

void vs_mainMenu_setUiWeaponStats(int index)
{
    vs_battle_uiWeapon uiWeapon;
    vs_battle_uiWeapon* weapon = &uiWeapon;

    vs_mainMenu_resetStats();
    vs_mainMenu_setRangeRisk(0, 0, 0, 1);

    if (index != 0) {
        int i;
        if (D_80102470[index - 1].isEquipped != 0) {
            weapon = &vs_battle_characterState->unk3C->weapon;
        } else if (D_80102470 == vs_battle_inventory.weapons) {
            vs_battle_applyWeapon(weapon, &D_80102470[index - 1]);
        } else {
            vs_menuD_initUiWeapon(
                weapon, &D_80102470[index - 1], &vs_menuD_containerData->data);
        }
        vs_battle_memcpy(vs_mainMenu_equipmentStats, &weapon->classAffinityCurrent, 0x40);

        for (i = 0; i < 4; ++i) {
            vs_mainMenu_equipmentStats[32 + i] = weapon->grip.types[i];
        }

        D_80102508 = weapon->damageType;
        do {
        } while (0);
        vs_mainMenu_setDpPp(
            weapon->currentDp, weapon->maxDp, weapon->currentPp, weapon->maxPp);
        vs_mainMenu_setStrIntAgi(
            weapon->currentStr, weapon->currentInt, weapon->currentAgility, 1);
        vs_mainMenu_setRangeRisk(weapon->range.unk0, weapon->risk, 0, 1);
        vs_mainMenu_strIntAgi[1].strength = weapon->baseStr;
        vs_mainMenu_strIntAgi[1].intelligence = weapon->baseInt;
        vs_mainMenu_strIntAgi[1].agility = weapon->baseAgility;
    }
    vs_mainMenu_equipmentSubtype = 1;
    D_801024A1 = index;
    func_800FBB8C(7);
}

void vs_mainMenu_setUiBladeStats(int index)
{
    int i;
    vs_battle_inventoryBlade* blade = &D_80102464[index - 1];

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i] = blade->classes[i & 7];
        vs_mainMenu_equipmentStats[16 + i] = blade->affinities[i & 7];
    }
    vs_mainMenu_setDpPp(blade->currentDp, blade->maxDp, blade->currentPp, blade->maxPp);
    vs_mainMenu_setStrIntAgi(blade->strength, blade->intelligence, blade->agility, 1);
    vs_mainMenu_setRangeRisk(blade->range.unk0, blade->cost, 0, 1);
    vs_mainMenu_equipmentSubtype = 2;
    D_801024A1 = index;
    func_800FBB8C(3);
}

void vs_mainMenu_setUiGripStats(int arg0)
{
    int i;
    vs_battle_inventoryGrip* grip = &D_80102460[arg0 - 1];

    for (i = 0; i < 4; ++i) {
        vs_mainMenu_equipmentStats[i + 0x20] = grip->types[i];
    }
    vs_mainMenu_setStrIntAgi(grip->strength, grip->intelligence, grip->agility, 1);
    vs_mainMenu_equipmentSubtype = 4;
    D_801024A1 = arg0;
    func_800FBB8C(4);
}

void func_800FD5A0(int index)
{
    vs_battle_uiShield uiShield;
    int i;
    vs_battle_uiShield* shield = &uiShield;

    vs_mainMenu_resetStats();
    if (index != 0) {
        if (D_8010246C[index - 1].isEquipped != 0) {
            shield = &vs_battle_characterState->unk3C->shield;
        } else if (D_8010246C == vs_battle_inventory.shields) {
            vs_battle_applyShield(shield, &D_8010246C[index - 1]);
        } else {
            vs_menuD_initUiShield(
                shield, &D_8010246C[index - 1], &vs_menuD_containerData->data);
        }
        vs_battle_memcpy(vs_mainMenu_equipmentStats, &shield->classAffinityCurrent, 0x40);

        for (i = 0; i < 4; ++i) {
            vs_mainMenu_equipmentStats[32 + i] = shield->types[i];
        }

        vs_mainMenu_setDpPp(
            shield->currentPp, shield->maxPp, shield->currentDp, shield->maxDp);
        vs_mainMenu_setStrIntAgi(
            shield->currentStr, shield->currentInt, shield->currentAgility, 1);
        vs_mainMenu_strIntAgi[1].strength = shield->baseStr;
        vs_mainMenu_strIntAgi[1].intelligence = shield->baseInt;
        vs_mainMenu_strIntAgi[1].agility = shield->baseAgility;
    }
    vs_mainMenu_equipmentSubtype = 8;
    D_801024A1 = index;
    func_800FBB8C(7);
}

void func_800FD700(int index)
{
    vs_battle_uiArmor uiArmor;
    int i;
    vs_battle_uiArmor* armor = &uiArmor;
    int var_s2 = 0;

    vs_mainMenu_resetStats();
    if (index != 0) {
        u_int temp_a0 = D_80102468[index - 1].bodyPart - 1;
        if (temp_a0 < 5) {
            armor = &vs_battle_characterState->unk3C->bodyParts[temp_a0].armor;
        } else {
            vs_battle_applyArmor(armor, &D_80102468[index - 1]);
        }
        var_s2 = armor->armor.category == 7;
        vs_battle_memcpy(vs_mainMenu_equipmentStats, &armor->classAffinityCurrent, 0x40);

        for (i = 0; i < 4; ++i) {
            vs_mainMenu_equipmentStats[32 + i] = armor->types[i];
        }

        vs_mainMenu_setDpPp(armor->currentDp, armor->maxDp, 0, 0);
        vs_mainMenu_setStrIntAgi(
            armor->currentStr, armor->currentInt, armor->currentAgility, var_s2 + 1);
        vs_mainMenu_strIntAgi[1].strength = armor->baseStr;
        vs_mainMenu_strIntAgi[1].intelligence = armor->baseInt;
        vs_mainMenu_strIntAgi[1].agility = armor->baseAgility;
    }
    if (var_s2 != 0) {
        vs_mainMenu_equipmentSubtype = 0x20;
    } else {
        vs_mainMenu_equipmentSubtype = 0x10;
    }
    D_801024A1 = index;
    func_800FBB8C(7);
}

void func_800FD878(int arg0)
{
    int i;
    vs_battle_inventoryGem* temp_a2 = &D_80102458[arg0 - 1];

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i] = temp_a2->classes[i & 7];
        vs_mainMenu_equipmentStats[i + 0x10] = temp_a2->affinities[i & 7];
    }

    vs_mainMenu_setStrIntAgi(
        temp_a2->strength, temp_a2->intelligence, temp_a2->agility, 1);
    vs_mainMenu_equipmentSubtype = 0x40;
    D_801024A1 = arg0;
    func_800FBB8C(3);
}
