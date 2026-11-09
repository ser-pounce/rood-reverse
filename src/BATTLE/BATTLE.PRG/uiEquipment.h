#pragma once
#include "src/SLUS_010.40/inventory.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    /* 0x00 */ short class[2][8];
    /* 0x20 */ short affinity[2][8];
    /* 0x40 */
} vs_battle_ClassAffinityCurrent;

typedef struct {
    /* 0x00 */ short class[8];
    /* 0x10 */ u_short affinity[8];
    /* 0x20 */
} vs_battle_ClassAffinityBaseline;

typedef struct {
    /* 0x00 */ u_short id;
    /* 0x02 */ signed char subId;
    /* 0x03 */ signed char wepId;
    /* 0x04 */ char category;
    /* 0x05 */ signed char strength;
    /* 0x06 */ signed char intelligence;
    /* 0x07 */ signed char agility;
    /* 0x08 */ u_short currentDp;
    /* 0x0A */ u_short maxDp;
    /* 0x0C */ u_short currentPp;
    /* 0x0E */ u_short maxPp;
    /* 0x10 */ char damageType;
    /* 0x11 */ char costType;
    /* 0x12 */ char cost;
    /* 0x13 */ char material;
    /* 0x14 */ char unk14;
    /* 0x15 */ char gemSlots;
    /* 0x16 */ char gemEffects;
    /* 0x17 */ char index;
    /* 0x18 */ vs_battle_Range range;
    /* 0x1C */ signed char types[4];
    /* 0x20 */ signed char classes[8];
    /* 0x28 */ signed char affinities[8];
    /* 0x30 */
} vs_battle_UiEquipment;

typedef struct {
    /* 0x000 */ char name[24];
    /* 0x018 */ vs_battle_UiEquipment blade;
    /* 0x048 */ vs_battle_UiEquipment grip;
    /* 0x078 */ vs_battle_UiEquipment gems[3];
    /* 0x108 */ char wepId;
    /* 0x109 */ char damageTypeValue;
    /* 0x10A */ char risk;
    /* 0x10B */ char unk10B;
    /* 0x10C */ char dropRate;
    /* 0x10D */ u_char index;
    /* 0x10E */ u_char damageType;
    /* 0x10F */ u_char actionType;
    /* 0x110 */ u_short currentPp;
    /* 0x112 */ u_short maxPp;
    /* 0x114 */ u_short currentDp;
    /* 0x116 */ u_short maxDp;
    /* 0x118 */ short currentStr;
    /* 0x11A */ u_short baseStr;
    /* 0x11C */ short currentInt;
    /* 0x11E */ u_short baseInt;
    /* 0x120 */ short currentAgility;
    /* 0x122 */ u_short baseAgility;
    /* 0x124 */ vs_battle_Range range;
    /* 0x128 */ vs_battle_ClassAffinityCurrent classAffinityCurrent;
    /* 0x168 */ short unk168[8];
    /* 0x178 */ vs_battle_ClassAffinityBaseline classAffinityBaseline;
    /* 0x198 */
} vs_battle_UiWeapon;

typedef struct {
    /* 0x000 */ int unk0[6];
    /* 0x018 */ vs_battle_UiEquipment base;
    /* 0x048 */ vs_battle_UiEquipment gems[3];
    /* 0x0D8 */ char wepId;
    /* 0x0D9 */ char dropRate;
    /* 0x0DA */ u_char index;
    /* 0x0DB */ char unkDB;
    /* 0x0DC */ u_short currentPp;
    /* 0x0DE */ u_short maxPp;
    /* 0x0E0 */ u_short currentDp;
    /* 0x0E2 */ u_short maxDp;
    /* 0x0E4 */ short currentStr;
    /* 0x0E6 */ u_short baseStr;
    /* 0x0E8 */ short currentInt;
    /* 0x0EA */ u_short baseInt;
    /* 0x0EC */ short currentAgility;
    /* 0x0EE */ u_short baseAgility;
    /* 0x0F0 */ char types[4];
    /* 0x0F4 */ vs_battle_ClassAffinityCurrent classAffinityCurrent;
    /* 0x134 */ short unk134[8];
    /* 0x144 */ vs_battle_ClassAffinityBaseline classAffinityBaseline;
    /* 0x164 */
} vs_battle_UiShield;

typedef struct {
    /* 0x00 */ vs_battle_UiEquipment armor;
    /* 0x30 */ u_short currentDp;
    /* 0x32 */ u_short maxDp;
    /* 0x34 */ short currentStr;
    /* 0x36 */ u_short baseStr;
    /* 0x38 */ short currentInt;
    /* 0x3A */ u_short baseInt;
    /* 0x3C */ short currentAgility;
    /* 0x3E */ u_short baseAgility;
    /* 0x40 */ u_short types[4];
    /* 0x48 */ vs_battle_ClassAffinityCurrent classAffinityCurrent;
    /* 0x88 */ short unk88[8];
    /* 0x98 */ char dropRate;
    /* 0x99 */ char unk99;
    /* 0x9A */ u_char index;
    /* 0x9B */ u_char unk9B;
    /* 0x9C */ vs_battle_ClassAffinityBaseline classAffinityBaseline;
    /* 0xBC */
} vs_battle_UiArmor;

typedef struct {
    /* 0x00 */ short hp;
    /* 0x02 */ short maxHp;
    /* 0x04 */ signed char agilityDefenseBonus;
    /* 0x05 */ char unk5;
    /* 0x06 */ u_char nameIndex;
    /* 0x07 */ char chainEvasion;
    /* 0x08 */ short types[4];
    /* 0x10 */ short affinities[8];
    /* 0x20 */ vs_battle_UiArmor armor;
    /* 0xDC */
} vs_battle_UiEquipment_limb;

typedef struct {
    /* 0x00 */ vs_battle_UiEquipment accessory;
    /* 0x30 */ short currentStr;
    /* 0x32 */ short currentInt;
    /* 0x34 */ short currentAgility;
    /* 0x36 */ char dropRate;
    /* 0x37 */ u_char index;
    /* 0x38 */ u_short types[4];
    /* 0x40 */ u_short classes[8];
    /* 0x50 */ u_short affinities[8];
    /* 0x60 */
} vs_battle_UiAccessory;

typedef struct {
    u_short id;
    char count;
    char unk3;
} vs_battle_UiMisc;

typedef struct {
    u_short id;
    char dropRate;
    char unk3;
} vs_battle_UiMiscRand;

typedef struct {
    vs_battle_UiEquipment blade;
    vs_battle_UiEquipment grip;
    vs_battle_UiEquipment gems[3];
    char material;
    char dropRate;
    short index;
    char name[24]; /* vs_string */
} vs_battle_WeaponIntermediate;

typedef struct {
    vs_battle_UiEquipment base;
    vs_battle_UiEquipment gems[3];
    char material;
    char dropRate;
    short index;
} vs_battle_ShieldIntermediate;

typedef struct {
    vs_battle_UiEquipment equip;
    char material;
    char dropRate;
    char unk32;
    char index;
} ArmorIntermediate;

typedef struct {
    vs_battle_UiEquipment equip;
    char dropRate;
    char index;
    char unk32;
    char unk33;
} AccessoryIntermediate;

void vs_battle_copyInventoryBladeStats(vs_battle_UiEquipment*, vs_main_InventoryBlade*);
void vs_battle_copyInventoryGripStats(vs_battle_UiEquipment*, vs_main_InventoryGrip*);
void vs_battle_copyInventoryArmorStats(vs_battle_UiEquipment*, vs_main_InventoryArmor*);
void vs_battle_copyInventoryGemStats(vs_battle_UiEquipment*, vs_main_InventoryGem*);
void vs_battle_applyWeapon(vs_battle_UiWeapon*, vs_main_InventoryWeapon*);
void vs_battle_applyShield(vs_battle_UiShield*, vs_main_InventoryShield*);
void vs_battle_applyArmor(vs_battle_UiArmor*, vs_main_InventoryArmor*);
void vs_battle_applyAccessory(vs_battle_UiAccessory* arg0, vs_main_InventoryArmor* arg1);
void vs_battle_equipWeapon(vs_main_InventoryWeapon*);
void vs_battle_equipShield(vs_main_InventoryShield* shield);
void vs_battle_equipArmor(int part, vs_main_InventoryArmor* armor);
void vs_battle_equipAccessory(vs_main_InventoryArmor* accessory);
void vs_battle_applyShieldStats(vs_battle_UiShield*, vs_battle_ShieldIntermediate*);
void vs_battle_applyWeaponStats(vs_battle_UiWeapon*, vs_battle_WeaponIntermediate*);
void vs_battle_copyUiBladeStats(
    vs_main_InventoryBlade* dropBlade, vs_battle_UiEquipment* targetBlade);
void vs_battle_copyUiGripStats(vs_main_InventoryGrip*, vs_battle_UiEquipment*);
void vs_battle_copyUiGemStats(vs_main_InventoryGem*, vs_battle_UiEquipment*);
void vs_battle_copyUiWeaponStats(vs_main_InventoryWeapon* arg0, vs_battle_UiWeapon* arg1);
void vs_battle_copyUiShieldStats(vs_main_InventoryShield*, vs_battle_UiShield*);
void vs_battle_copyUiArmorStats(vs_main_InventoryArmor*, vs_battle_UiArmor*);
void vs_battle_copyUiAccessoryStats(vs_main_InventoryArmor*, vs_battle_UiAccessory*);
