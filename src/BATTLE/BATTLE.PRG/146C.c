#include "common.h"
#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#include "146C.h"
#include "2842C.h"
#include "30D14.h"
#include "38C1C.h"
#include "3A1A0.h"
#include "44F14.h"
#include "4A0A8.h"
#include "5BF94.h"
#include "6E644.h"
#include "../../SLUS_010.40/main.h"

typedef struct {
    u_short unk0;
    u_short unk2;
    u_short unk4;
    u_short unk6;
} func_8007820C_t;

typedef struct {
    u_char unk0;
    char unk1;
    short unk2;
    short unk4;
    char unk6;
    char unk7;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
} func_8008418C_t;

typedef struct {
    int unk0[12];
    char unk30;
    char unk31;
    char unk32;
    char unk33;
    short unk34;
    short unk36;
    short unk38;
    short unk3A;
    short unk3C;
    short unk3E;
    short unk40;
    short unk42;
    short unk44;
    short unk46;
    short unk48;
    short unk4A;
    short unk4C;
    short unk4E;
    short sceneId;
    short unk52;
    short unk54;
    short unk56;
} D_800F1C84_t;

typedef struct {
    u_char unk0;
    signed char unk1;
    signed char unk2;
    signed char unk3;
    short unk4;
    short unk6;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
    int unk14;
    int unk18;
    union {
        struct {
            u_int unk1C_0 : 2;
            u_char unk1C_2 : 2;
            u_char unk1C_4 : 2;
            u_char unk1C_6 : 2;
            u_char unk1D_0 : 2;
            u_char unk1D_2 : 2;
            u_char unk1D_4 : 2;
            u_char unk1D_6 : 2;
            u_char unk1E_0 : 2;
            u_char unk1E_2 : 2;
            u_char unk1E_4 : 2;
            u_char unk1E_6 : 2;
            u_char unk1F_0 : 2;
            u_char unk1F_2 : 2;
            u_char unk1F_4 : 4;
        } fields;
        int value;
    } unk1C;
    union {
        short s16[7][2];
        int s32[7];
    } unk20;
    short unk3C;
    short unk3E;
    int unk40;
} func_80085718_t;

typedef struct {
    short unk0;
    short unk2;
} D_800F1C60_t;

typedef struct {
    u_int unk0;
    int unk4;
    u_short unk8;
    char unkA;
    char unkB;
    int unkC[19];
    short unk58;
    short unk5A;
    int unk5C[511];
    char unk858[4][0x84C];
    char unk2988[0x280];
    short unk2C08;
    u_short unk2C0A;
    short unk2C0C;
} D_800F19CC_t;

typedef struct {
    char unk0;
    signed char unk1;
    char unk2;
    char unk3;
    short unk4;
    short unk6;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    short unk20;
    short unk22[13];
    short unk3C;
} func_800842AC_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    func_8006B57C_t blade;
    vs_battle_setGripForDrop_t grip;
    func_800FD17C_t gems[3];
    char unk94[0x18];
} _setWeaponForDropRand_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_setEquipmentForDrop_t shield;
    func_800FD17C_t gems[3];
} _setShieldForDropRand_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_setEquipmentForDrop_t accessory;
} _setAccessoryForDropRand_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_setEquipmentForDrop_t armor;
} _setArmorForDropRand_t;

typedef struct {
    _setWeaponForDropRand_t weapon;
    int unkB4[17];
    _setShieldForDropRand_t shield;
    _setArmorForDropRand_t armor;
    int unk1A4[11];
    _setAccessoryForDropRand_t accessory;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
} func_8006BE64_t2;

typedef struct {
    void** unk0;
    int unk4;
    func_8006BE64_t2 unk8;
} func_8006BE64_t;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    short currentHP;
    short maxHP;
    short currentMP;
    short maxMP;
    short totalStrength;
    short totalIntelligence;
    short totalAgility;
    short unk12[6];
    int unk20;
    int unk24;
} func_80069EF0_t;

int func_8006BDA0(func_8006BE64_t2*, vs_battle_actor2*);
int func_8006BDF0(func_8006BE64_t2*, void*);
void func_8006C350(void);
void func_8006C39C(void);
void func_8006C40C(void);
void func_80069DEC(int, int);
int func_8006A228(u_int, int);
void func_8006A8EC(void*, void*);
void vs_battle_setEquipmentForDrop(
    vs_battle_setEquipmentForDrop_t*, vs_battle_equipment* equipment);
void func_8006C004(vs_battle_actor*);
void func_8006C164(int);
void func_8006DEFC(func_8007820C_t*, int, int);
void func_8006F53C(void);
void func_8006F5CC(void);
void func_8006F89C(void);
void func_8006FA20(void);
void func_80070278(void);
void func_80070F28(int);
void func_8007138C(void);
void func_80073718(void);
void func_800780A8(func_8007820C_t*);
int func_80078828(int);
void func_8007A850(int);
void func_8007A9DC(void*, void*, int);
void func_8007B29C(int, int, int, int, int, int);
void func_8007B63C(void);
void func_8007B470(void);
void func_8007B764(void);
void func_8007B7DC(void);
void func_8007BCCC(void);
void func_8007BF6C(int);
void func_8007BFF8(int);
void func_8007C0AC(int, int);
void func_8007C4E0(void);
void func_8007C5C0(void);
void func_8007CD70(int*, int*, int, int);
int _getLocationId(int, int);
void func_8007D08C(int, int);
void func_8007D360(void);
int func_8007F4B0(int arg0, char* arg1);
int func_8007F518(u_char*);
void func_80080000(vs_skill_t*, func_80085718_t*, short);
int func_800801E0(vs_skill_t*, func_80085718_t*, short);
void func_800802C4(vs_skill_t*, vs_battle_actor2*, vs_battle_actor2*, short);
int func_800803A4(vs_skill_t*, vs_battle_actor2*, vs_battle_actor2*, short);
int func_80081020(int, func_80085718_t*);
int func_800810CC(int, func_80085718_t*);
short func_80081148(vs_skill_t*, func_80085718_t*, func_80085718_t*, int, int, int);
short func_800838EC(vs_skill_t*, func_80085718_t*, func_80085718_t*, int, int);
int func_8008574C(int, vs_battle_actor2*, int);
void func_80085008(func_80085718_t*);
void func_80085390(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4);
void func_80086754(int, vs_battle_actor2*);
void func_80088554(void);
int func_8008B4C8(char arg0);
void func_8008C40C(void);
void func_80089CE4(void);
void func_80089D04(void);
void func_8008A6FC(void);
int func_8008AB80(int);
int func_8008ABB8(int);
void func_8008B960(char, char, char);
void func_8008C49C(int, int);
void func_8008D5A0(int);
void func_80093B68(void);

extern u_char D_800E8200[];
extern void (*D_800E8378[])(vs_skill_t*, func_80085718_t*, func_80085718_t*, int, int);
extern short (*D_800E830C[])(vs_skill_t*, func_80085718_t*, func_80085718_t*, int, int);
extern int D_800E8498;
extern int D_800F185C;
extern int D_800F1860;
extern int D_800F1864;
extern int D_800F1868;
extern int D_800F186C;
extern int D_800F18A8;
extern int D_800F18B0;
extern int D_800F18F0;
extern char D_800F18F8;
extern void** D_800F1900;
extern int D_800F190C;
extern u_short D_800F1910[];
extern int D_800F1968;
extern int D_800F196C;
extern int D_800F19A0;
extern D_800F19CC_t* D_800F19CC;
extern int D_800F19D4;
extern int D_800F19EC;
extern int D_800F1A04;
extern int D_800F1A08;
extern int D_800F1A0C;
extern int D_800F1A20;
extern short D_800F1A2C;
extern int D_800F1A30[];
extern int D_800F1A40;
extern u_int D_800F1A44;
extern u_int D_800F1A48;
extern D_800F1A68_t D_800F1A68;
extern D_800F1A78_t D_800F1A78;
extern int D_800F1A98;
extern int D_800F1AA4;
extern int D_800F1AA8;
extern int D_800F1ABC;
extern int D_800F1B98;
extern int D_800F1B9C;
extern u_short D_800F1BA4;
extern short* D_800F1BA8;
extern short D_800F1BB6;
extern short D_800F1BBE;
extern D_800F1BF8_t D_800F1BF8;
extern int* D_800F1C5C;
extern D_800F1C60_t* D_800F1C60;
extern int D_800F1C64;
extern int D_800F1C70;
extern int D_800F1C74;
extern D_800F1C84_t* D_800F1C84;
extern u_short* D_800F1C98;
extern u_int (*D_800F1CA0)[46];
extern int* D_800F1CA4;
extern u_int D_800F1CA8;
extern int D_800F1CB8;
extern char D_800F1CD6;
extern short D_800F1CDC;
extern int D_800F1D28[16];
extern short D_800F1D6A;
extern short D_800F1D6C;
extern int D_800F1D78[20];
extern signed char D_800F1D6E;
extern vs_main_CdQueueSlot* D_800F1DAC;
extern vs_main_CdQueueSlot* D_800F1DB0;
extern short D_800F1DB8;
extern short D_800F1DBA;
extern short D_800F1DBE;
extern short D_800F1DC4;
extern char D_800F1DC8;
extern signed char D_800F1DC9;
extern char D_800F1DCA;
extern int* D_800F1DCC;
extern int* D_800F1DD0;
extern u_short* D_800F1DD4;

extern int D_1F800000[];
extern int D_1F800034[];

// invoked when using Grimoires, Casting Spells or using Break Arts (but not Battle
// Abilities or Items) invoked just before the skill takes effect
void func_80069C6C(int arg0)
{
    if (arg0 == 0) {
        if (*D_800F19CC->unk858[D_800F19CC->unk0 & 3] == 0) {
            return;
        }
        // TODO: Remove dead code
        switch (D_800F19CC->unk858[D_800F19CC->unk0 & 3][0] != 0) {
        case 0:
            return;
        }
        if ((D_800F19CC->unk2C0A == 0) && (func_80078828(0) != 0)) {
            D_800F19CC->unk2C0A = D_800F19CC->unk2C08 + (vs_gametime_tickspeed * 2);
        }
    }
}

void func_80069D14(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        vs_battle_actor* actor = vs_battle_actors[i];
        if ((actor != NULL) && (actor->unk8 == 0x80)
            && (vs_battle_actors[i]->unk9 == 0x18)) {
            actor->unk8 = 8;
        }
    }
}

void func_80069D78(void)
{
    func_8007A850(0);
    D_1F800000[4] = ((D_1F800000[4] & 0x7FFF) | (D_800F186C << 0x10));
}

void func_80069DBC(void)
{
    D_80060064 = 0;
    vs_main_bzero(D_80061078, sizeof D_80061078);
}

void func_80069DEC(int arg0, int arg1)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if ((D_80061078[i].unk2 == arg0) && (D_80061078[i].unk1 == arg1)) {
            vs_main_bzero(D_80061078[i].unk8, 0x140);
        }
    }
}

void* func_80069E80(int arg0)
{
    int i;
    void* var_a3 = NULL;

    for (i = 0; i < 8; ++i) {
        if (D_80061078[D_80060064].unk8[i][0] == (arg0 + 1)) {
            var_a3 = &D_80061078[D_80060064].unk8[i];
        }
    }
    return var_a3;
}

void* func_80069EF0(int arg0)
{
    int i;
    void* var_a3;

    var_a3 = NULL;

    for (i = 0; i < 8; ++i) {
        if (D_80061078[D_80060064].unk8[i][0] == (arg0 + 1)) {
            var_a3 = &D_80061078[D_80060064].unk8[i];
            break;
        }
    }
    if (var_a3 == NULL) {
        i = D_80061078[D_80060064].unk4;
        var_a3 = &D_80061078[D_80060064].unk8[i];
        ++D_80061078[D_80060064].unk4;

        if (D_80061078[D_80060064].unk4 >= 8) {
            D_80061078[D_80060064].unk4 = 0;
        }
    }
    return var_a3;
}

void func_80069FC4(int arg0, int arg1)
{
    int sp10[4];
    int i;
    func_80069EF0_t* temp_v0;
    vs_battle_actor* temp_s0;
    vs_battle_actor2* temp_s1;

    temp_s0 = vs_battle_actors[arg0];

    if (temp_s0 != NULL) {
        if (temp_s0->unk27 != 0x80) {
            temp_s1 = temp_s0->unk3C;
            temp_v0 = func_80069EF0(temp_s0->unk27);
            temp_v0->unk0 = temp_s0->unk27 + 1;
            temp_v0->currentHP = temp_s1->currentHP;
            temp_v0->maxHP = temp_s1->maxHP;
            temp_v0->currentMP = temp_s1->currentMP;
            temp_v0->maxMP = temp_s1->maxMP;
            temp_v0->totalStrength = temp_s1->totalStrength;
            temp_v0->totalIntelligence = temp_s1->totalIntelligence;
            temp_v0->totalAgility = temp_s1->totalAgility;
            for (i = 0; i < 6; ++i) {
                temp_v0->unk12[i] = temp_s1->hitLocations[i].unk0;
            }

            temp_v0->unk20 = temp_s1->unk948;
            if (func_800A0BE0(arg0) & 0x01000000) {
                temp_v0->unk1 = arg1;
                temp_v0->currentHP = 1;
            } else {
                temp_v0->unk1 = arg1;
            }
            temp_v0->unk2 = func_800E6694(arg0);
            func_800A1108(arg0, sp10);
            func_800A36E0(arg0, temp_s1->unk30, sp10);
            temp_v0->unk24 = sp10[0];
        }
    }
}

int func_8006A11C(vs_battle_actor* arg0)
{
    int i;

    if ((arg0->unk1C & 7) && (arg0->unk4 != 0)) {

        for (i = 0; i < 16; ++i) {
            if ((vs_battle_actors[i] != NULL) && (vs_battle_actors[i]->unk0 == arg0)) {
                return 0;
            }
        }

        if (arg0->unk4 != 0) {
            arg0->unk0 = vs_battle_actors[0]->unk0;
            vs_battle_actors[0]->unk0 = arg0;
        } else {
            arg0->unk0 = NULL;
        }
        return 1;
    }
    return 0;
}

int func_8006A1C4(vs_battle_actor* arg0)
{
    int i;

    if (arg0->unk4 != 0) {
        for (i = 0; i < 16; ++i) {
            if (vs_battle_actors[i] != NULL && vs_battle_actors[i]->unk0 == arg0) {
                vs_battle_actors[i]->unk0 = arg0->unk0;
                arg0->unk0 = NULL;
                return 1;
            }
        }
    }
    return 0;
}

int func_8006A228(u_int arg0, int arg1)
{
    int i;
    vs_battle_actor* temp_s0;

    if (arg0 < 16) {
        temp_s0 = vs_battle_actors[arg0];
        if (temp_s0 != NULL) {
            func_80069FC4(arg0, arg1);
            if (temp_s0->unk1C == 0x10) {
                func_8009F530(arg0);
                func_80099D6C(arg0);
            } else {
                func_8009CFB0(arg0);
                if (temp_s0->unk40 == 2) {
                    func_8009CFB0(arg0 + 4);
                }
            }
            func_800E7454(temp_s0);
            for (i = 0; i < 16; ++i) {
                if (vs_battle_actors[i]->unk0 == temp_s0) {
                    vs_battle_actors[i]->unk0 = temp_s0->unk0;
                    break;
                }
            }
            vs_main_freeHeap(temp_s0);
            vs_battle_actors[arg0] = NULL;
        }
        return 1;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A334);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A65C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A8EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A9F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006AB44);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006AC74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006ACFC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006AE0C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006AEAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B02C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B110);

void func_8006B194(void* arg0, char* arg1)
{
    char* temp_v0 = vs_main_allocHeapR(0x34);
    vs_main_bzero(temp_v0, 0x34);
    if (arg1 != NULL) {
        temp_v0[0x31] = arg1[0x27];
        func_8006ACFC(temp_v0, arg1);
    }
    func_8006A8EC(arg0, temp_v0);
    vs_main_freeHeapR(temp_v0);
}

void func_8006B20C(void) { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B214);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B270);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B2D4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B338);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B460);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B4B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B524);

void vs_battle_setBladeForDrop(
    func_8006B57C_t* dropBlade, vs_battle_equipment* targetBlade)
{
    int i;
    func_8006B57C_t* a3;

    dropBlade->id = targetBlade->id;
    dropBlade->unk1 = targetBlade->unk2;
    dropBlade->wepId = targetBlade->wepId;
    dropBlade->category = targetBlade->category;
    dropBlade->currentDp = targetBlade->currentDp;
    dropBlade->maxDp = targetBlade->maxDp;
    dropBlade->currentPp = targetBlade->currentPp;
    dropBlade->maxPp = targetBlade->maxPp;
    dropBlade->strength = targetBlade->strength;
    dropBlade->intelligence = targetBlade->intelligence;
    dropBlade->agility = targetBlade->agility;
    dropBlade->cost = targetBlade->cost;
    dropBlade->unk10_0 = targetBlade->damageType & 3;
    dropBlade->unk10_2 = targetBlade->costType & 7;
    dropBlade->unk12 = targetBlade->unk14;
    dropBlade->range = targetBlade->range;

    a3 = dropBlade;

    for (i = 0; i < 6; ++i) {
        a3->classes[i] = targetBlade->classes[i];
    }

    for (i = 0; i < 7; ++i) {
        a3->affinities[i] = targetBlade->affinities[i];
    }
    dropBlade->material = targetBlade->material;
}

void vs_battle_setGripForDrop(
    vs_battle_setGripForDrop_t* dropGrip, vs_battle_equipment* targetGrip)
{
    int i;

    dropGrip->id = targetGrip->id;
    dropGrip->unk2 = targetGrip->unk2;
    dropGrip->category = targetGrip->category;
    dropGrip->gemSlots = targetGrip->gemSlots;
    dropGrip->strength = targetGrip->strength;
    dropGrip->intelligence = targetGrip->intelligence;
    dropGrip->agility = targetGrip->agility;

    for (i = 0; i < 4; ++i) {
        dropGrip->types[i] = targetGrip->types[i];
    }
}

void vs_battle_setGemForDrop(func_800FD17C_t* dropGem, vs_battle_equipment* targetGem)
{
    int i;

    dropGem->id = targetGem->id;
    dropGem->unk2 = targetGem->unk2;
    dropGem->gemEffects = targetGem->gemEffects;
    dropGem->strength = targetGem->strength;
    dropGem->intelligence = targetGem->intelligence;
    dropGem->agility = targetGem->agility;

    for (i = 0; i < 6; ++i) {
        dropGem->classes[i] = targetGem->classes[i];
    }

    for (i = 0; i < 7; ++i) {
        dropGem->affinities[i] = targetGem->affinities[i];
    }
}

void vs_battle_setEquipmentForDrop(
    vs_battle_setEquipmentForDrop_t* dropArmor, vs_battle_equipment* targetArmor)
{
    int i;
    vs_battle_setEquipmentForDrop_t* a3;

    dropArmor->id = targetArmor->id;
    dropArmor->unk1 = targetArmor->unk2;
    dropArmor->wepId = targetArmor->wepId;
    dropArmor->category = targetArmor->category;
    dropArmor->currentDp = targetArmor->currentDp;
    dropArmor->maxDp = targetArmor->maxDp;
    dropArmor->currentPp = targetArmor->currentPp;
    dropArmor->maxPp = targetArmor->maxPp;
    dropArmor->gemSlots = targetArmor->gemSlots;
    dropArmor->strength = targetArmor->strength;
    dropArmor->intelligence = targetArmor->intelligence;
    dropArmor->agility = targetArmor->agility;

    a3 = dropArmor;

    for (i = 0; i < 4; ++i) {
        a3->types[i] = targetArmor->types[i];
    }

    for (i = 0; i < 6; ++i) {
        a3->classes[i] = targetArmor->classes[i];
    }

    for (i = 0; i < 7; ++i) {
        a3->affinities[i] = targetArmor->affinities[i];
    }
    dropArmor->material = targetArmor->material;
}

void vs_battle_setWeaponForDrop(u_char* arg0, vs_battle_weaponInfo* arg1)
{
    int i;

    if (arg1->blade.id != 0) {
        arg1->blade.currentDp = arg1->currentDp;
        arg1->blade.currentPp = arg1->currentPp;
        vs_battle_setBladeForDrop(&D_80060168.unk254[arg0[1]], &arg1->blade);
        vs_battle_setGripForDrop(&D_80060168.unk530[arg0[2]], &arg1->grip);
        for (i = 0; i < 3; ++i) {
            if (arg1->gems[i].id != 0) {
                vs_battle_setGemForDrop(
                    &D_80060168.unk8A4[arg0[(unsigned int)(i + 4)]], &arg1->gems[i]);
            }
        }
        for (i = 0; i < 24; ++i) {
            arg0[(unsigned int)(i + 8)] = arg1->name[i];
        }
    }
}

void func_8006B9E0(u_char* arg0, vs_battle_shieldInfo* arg1)
{
    int i;

    if (arg1->shield.id != 0) {
        arg1->shield.currentDp = arg1->currentPp;
        arg1->shield.currentPp = arg1->currentDp;
        vs_battle_setEquipmentForDrop(
            (vs_battle_setEquipmentForDrop_t*)(arg0 + 4), &arg1->shield);
        for (i = 0; i < 3; ++i) {
            if (arg1->gems[i].id != 0) {
                vs_battle_setGemForDrop(
                    &D_80060168.unk8A4[arg0[(unsigned int)(i + 0x2C)]], &arg1->gems[i]);
            }
        }
    }
}

void vs_battle_setArmorForDrop(
    vs_battle_setEquipmentForDrop_t* arg0, vs_battle_armorInfo* arg1)
{
    if (arg1->armor.id != 0) {
        arg1->armor.currentDp = arg1->currentDp;
        vs_battle_setEquipmentForDrop(arg0, &arg1->armor);
    }
}

void vs_battle_setAccesoryForDrop(
    vs_battle_setEquipmentForDrop_t* arg0, vs_battle_accessoryInfo* accessory)
{
    if (accessory->accessory.id != 0) {
        vs_battle_setEquipmentForDrop(arg0, &accessory->accessory);
    }
}

int _setWeaponForDropRand(_setWeaponForDropRand_t* arg0, vs_battle_weaponInfo* arg1)
{
    int i;

    if (vs_main_getRand(0xFF) < arg1->unk10C) {
        vs_battle_setBladeForDrop(&arg0->blade, &arg1->blade);
        vs_battle_setGripForDrop(&arg0->grip, &arg1->grip);
        for (i = 0; i < 3; ++i) {
            if (arg1->gems[i].id != 0) {
                vs_battle_setGemForDrop(&arg0->gems[i], &arg1->gems[i]);
            }
        }
        vs_main_memcpy(arg0->unk94, arg1, sizeof arg0->unk94);
        arg0->unk0 = 3;
        return 1;
    }
    return 0;
}

int _setShieldForDropRand(_setShieldForDropRand_t* arg0, vs_battle_shieldInfo* arg1)
{
    int i;

    if (vs_main_getRand(0xFF) < arg1->unkD9) {
        vs_battle_setEquipmentForDrop(&arg0->shield, &arg1->shield);
        for (i = 0; i < 3; ++i) {
            if (arg1->gems[i].id != 0) {
                vs_battle_setGemForDrop(&arg0->gems[i], &arg1->gems[i]);
            }
        }
        arg0->unk0 = 3;
        return 1;
    }
    return 0;
}

int _setAccessoryForDropRand(
    _setAccessoryForDropRand_t* arg0, vs_battle_accessoryInfo* arg1)
{
    if (vs_main_getRand(0xFF) < arg1->unk36) {
        vs_battle_setEquipmentForDrop(&arg0->accessory, &arg1->accessory);
        arg0->unk0 = 3;
        return 1;
    }
    return 0;
}

int _setArmorForDropRand(_setArmorForDropRand_t* arg0, vs_battle_armorInfo* arg1)
{
    int i;

    if (vs_main_getRand(0xFF) < arg1->unk98) {
        for (i = 0; i < 2; ++i) {
            if (arg0[i].armor.id == 0) {
                vs_battle_setEquipmentForDrop(&arg0[i].armor, &arg1->armor);
                arg0[i].unk0 = 3;
                return 1;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006BDA0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006BDF0);

void func_8006BE64(vs_battle_actor* arg0)
{
    int var_a0;
    int i;
    void** temp_a0;
    func_8006BE64_t* temp_v0;
    void** var_v1;
    vs_battle_actor2* temp_s2;

    temp_s2 = arg0->unk3C;
    temp_v0 = vs_main_allocHeapR(sizeof(func_8006BE64_t));
    if (temp_v0 != NULL) {
        vs_main_bzero(temp_v0, sizeof(func_8006BE64_t));
        temp_v0->unk4 |= _setWeaponForDropRand(&temp_v0->unk8.weapon, &temp_s2->weapon);
        temp_v0->unk4 |= _setShieldForDropRand(&temp_v0->unk8.shield, &temp_s2->shield);
        temp_v0->unk4 |=
            _setAccessoryForDropRand(&temp_v0->unk8.accessory, &temp_s2->accessory);
        for (i = 0; i < 6; ++i) {
            if (temp_s2->hitLocations[i].armor.armor.id != 0) {
                temp_v0->unk4 |= _setArmorForDropRand(
                    &temp_v0->unk8.armor, &temp_s2->hitLocations[i].armor);
            }
        }
        temp_v0->unk4 |= func_8006BDA0(&temp_v0->unk8, temp_s2 + 1);
        temp_v0->unk4 |= func_8006BDF0(&temp_v0->unk8, &(temp_s2 + 1)->name[4]);
        if (temp_v0->unk4 != 0) {
            var_v1 = D_800F1900;
            var_a0 = 1;
            while (var_v1 != NULL) {
                if (var_v1[1] == (void*)arg0->unk4) {
                    var_a0 = 0;
                }
                var_v1 = (void**)var_v1[0];
            }
            if (var_a0 != 0) {
                int new_var = arg0->unk4;
                temp_a0 = D_800F1900;
                D_800F1900 = (void**)temp_v0;
                temp_v0->unk4 = new_var;
                temp_v0->unk0 = temp_a0;
                return;
            }
        }
        vs_main_freeHeapR(temp_v0);
    }
}

void func_8006C004(vs_battle_actor* arg0)
{
    u_int temp_t1;
    vs_battle_actor2* new_var2;

    temp_t1 = arg0->unk1A;
    if (arg0->unk3C != NULL) {
        if (arg0->unk1C == 4) {
            new_var2 = arg0->unk3C;
            if (vs_main_scoredata.enemyKills[new_var2->unk37 & 7] <= 0xFFFE) {
                ++vs_main_scoredata.enemyKills[new_var2->unk37 & 7];
            }
            if (vs_main_scoredata.unk10C != (arg0->unk3C->unk37 & 7)) {
                vs_main_scoredata.unk10C = arg0->unk3C->unk37 & 7;
                vs_main_scoredata.unk10D = 0;
            } else if (vs_main_scoredata.unk10D < 100) {
                vs_main_scoredata.unk10D = vs_main_scoredata.unk10D + 1;
            }
            vs_main_scoredata.streakScore +=
                new_var2->maxHP + ((new_var2->maxHP * vs_main_scoredata.unk10D) / 2)
                + ((new_var2->maxHP * vs_main_scoredata.weaponKillStreak) / 2)
                + ((new_var2->maxHP * vs_main_scoredata.chainStreak) / 2);
            if (vs_main_scoredata.streakScore > 999999999) {
                vs_main_scoredata.streakScore = 999999999;
            }
        }
    }
    if (temp_t1 < 0x100) {
        vs_main_scoredata.unk9C[temp_t1 >> 5] |= 1 << (temp_t1 & 0x1F);
    }
}

void func_8006C164(int arg0)
{
    vs_battle_actor2* new_var = vs_battle_characterState->unk3C;
    if (D_800F19CC->unk8 < 0x28) {
        if (vs_main_scoredata.weaponKillStreakBladeCategory
            != new_var->weapon.blade.category) {
            vs_main_scoredata.weaponKillStreakBladeCategory =
                new_var->weapon.blade.category;
            vs_main_scoredata.weaponKillStreak = 0;
            return;
        }
        if (vs_main_scoredata.weaponKillStreak < 0x64) {
            ++vs_main_scoredata.weaponKillStreak;
        }
    }
}

void func_8006C1CC(int arg0, int arg1, int arg2)
{
    vs_battle_actor* temp_s0 = vs_battle_actors[arg1];
    if ((temp_s0->unk27 != 0x80) && (temp_s0->unk28 == 0)) {
        if ((arg2 != 0) && (arg0 == 0)) {
            func_8006C004(temp_s0);
            func_8006C164(0);
        }
        func_8006BE64(temp_s0);
        temp_s0->unk28 = 1;
    }
}

void func_8006C250(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        int temp_v0 = func_800A0BE0(i);
        if (!(temp_v0 & 4)) {
            func_800A087C(i, temp_v0 | 4);
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C2A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C2FC);

void func_8006C350(void)
{
    int i;

    for (i = 1; i < 16; ++i) {
        func_8009E5C4(i);
    }
    func_80095B70(1);
    D_800F1968 = 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C39C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C40C);

void func_8006C478(void) { }

void func_8006C480(int arg0, int arg1) { func_800CF7A8(arg0, arg1, 0, 0); }

void func_8006C4A4(int arg0, int arg1) { func_800CF830(arg0, arg1); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C4C4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C5AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C84C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006CA20);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006CB04);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006CD60);

void func_8006CDB8(void) { func_8009D854(); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006CDD8);

void func_8006CE50(void) { func_8008D5A0(0xB4); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006CE70);

void func_8006D028(int arg0)
{
    D_800F185C = arg0;
    func_8007B29C(0xE, 8, arg0, 0x10, 0, 0);
}

void func_8006D064(void)
{
    func_8007B29C(8, 4, D_800F185C, 0, 0, 0);
    D_800F185C = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006D0A4);

int func_8006D97C(int base, int a, int b)
{
    if (b < 0) {
        if (a >= b) {
            if (a != 0) {
                base += a;
            } else {
                base += b;
            }
        } else {
            base += b;
        }
    } else if ((b >= a) && (a != 0)) {
        base += a;
    } else {
        base += b;
    }
    return base;
}

int _add_min(int base, int a, int b)
{

    if (b < 0) {
        if (a < b) {
            base += b;
        } else {
            base += a;
        }
    } else if (b < a) {
        base += b;
    } else {
        base += a;
    }
    return base;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006D9FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006DB98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006DEFC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006DFE0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006E158);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006E640);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006E7F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006EBF8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006EC7C);

void func_8006EF10(void)
{
    if (D_800F19EC >= 0) {
        if (D_800F19EC < 2) {
            D_800F19CC->unk2C0C = 0x600;
            return;
        }
        if (D_800F19EC < 4) {
            D_800F19CC->unk2C0C = 0x900;
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006EF5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F204);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F450);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F4B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F53C);

void func_8006F5CC(void)
{
    D_800F196C = 1;
    D_800F18F0 = 0;
    func_8006F53C();
}

void func_8006F5FC(void)
{
    D_800F196C = 0xC;
    D_800F18F0 = 0;
    func_8009E5C4(0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F630);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F760);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F848);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F89C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006FA20);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006FB48);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006FBCC);

void func_8006FCBC(void)
{
    char* temp_s0;

    D_800F18F0 = 0xA;
    temp_s0 = (char*)&D_800F19CC->unk5C[0x1FE];
    func_8006C4A4(temp_s0[4], func_800A152C(temp_s0[4], 0xF0, 0));
}

void func_8006FD0C(void) { D_800F18F0 = 9; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006FD1C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80070278);

void func_800704B0(void)
{
    D_800F18F0 = 6;
    func_800CF920();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800704D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007053C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007087C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800708EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80070B04);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80070CAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80070F28);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007138C);

void func_800719DC(void) { func_80070F28(0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800719FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80071F68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80072734);

void func_80072B9C(void) { D_800F18F0 = 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80072BA8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80072EC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800730BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800732AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800733F8);

void func_80073484(void)
{
    func_8006F5CC();
    vs_gametime_tickspeed = 2;
    func_800CB654(0);
    func_8008B4C8(1);
}

void func_800734C0(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        func_8009E5C4(i);
    }
    func_8007C0AC(0, 2);
    D_800F196C = 10;
}

void func_8007350C(void) { func_8006F5CC(); }

void func_8007352C(void)
{
    D_800F196C = 6;
    func_8006C39C();
}

void func_80073554(void)
{
    D_800F196C = 1;
    func_8006C40C();
}

void func_8007357C(void)
{
    D_800F196C = 5;
    D_800F18F0 = 1;
    func_800CB660((vs_battle_characterState->unk20 & 1) | 2);
    func_8006C39C();
}

void func_800735CC(short* arg0)
{
    func_800CB114();
    *arg0 = 0;
    func_8006C40C();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800735F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80073718);

void func_80073870(void)
{
    func_800BEC30();
    func_80073718();
}

void func_80073898(void)
{
    if ((func_800BEB10() << 16) != 0) {
        D_800F196C = 3;
        D_800F18F0 = 1;
        return;
    }
    func_80073870();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800738E4);

void func_80073AA4(void)
{
    D_800F196C = 0xB;
    func_8006C350();
}

void func_80073ACC(void)
{
    func_800CB50C();
    func_8006C40C();
    func_8006F5CC();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80073AFC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80073D30);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80073E30);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80073F7C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074050);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074120);

void func_8007418C(void)
{
    func_8007820C_t sp10;

    sp10.unk0 = D_800F1910[4];
    sp10.unk2 = D_800F1910[5];
    sp10.unk4 = D_800F1910[6];
    func_8006DEFC(&sp10, 0, 0x28);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800741D4);

int func_8007424C(void)
{
    int ret = 0;
    if (func_800A0BE0(0) & 0x08000000) {
        ret = func_800CB45C() == 0;
    }
    return ret;
}

int func_80074294(void) { return D_800F1868 & 3; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800742A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074314);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074374);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800743E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800744B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074580);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800745EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074744);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074798);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074860);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800748B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074950);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074A20);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074B14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074BAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800751B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800753F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80075554);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800760CC);

int func_8007629C(u_int* otag)
{
    int ret;
    u_int temp_a0;

    vs_main_frameBuf = vs_main_frameBuf == 0;
    vs_main_getRand(0);
    SetGeomOffset(160, 112);
    DrawSync(0);
    ret = vs_main_gametimeUpdate(vs_gametime_tickspeed);
    if (D_8004A52C != 0) {
        while (1) {
            vs_main_gametimeUpdate(2);
            vs_main_buttonsState = (u_short)vs_main_updatePadState(0, *vs_main_padBuffer);
            vs_main_buttonsState |= vs_main_updatePadState(16, vs_main_padBuffer[1])
                                 << 16;
            vs_main_padConnect(0, vs_main_padBuffer[0]);
            vs_main_padConnect(16, vs_main_padBuffer[1]);
            vs_main_buttonsPressed.all =
                ~vs_main_buttonsPreviousState & vs_main_buttonsState;
            temp_a0 = vs_main_buttonsPressed.all >> 16;
            vs_main_buttonsReleased =
                vs_main_buttonsPreviousState & ~vs_main_buttonsState;
            vs_main_buttonsPreviousState = vs_main_buttonsState;
            if (temp_a0 & 0x800) {
                D_8004A52C ^= 1;
            }
            if ((temp_a0 & 0x100) || (D_8004A52C == 0)) {
                break;
            }
        }
    }
    PutDispEnv(&vs_main_dispEnv[vs_main_frameBuf]);
    PutDrawEnv(&vs_main_drawEnv[vs_main_frameBuf]);
    func_80048F8C();
    DrawOTag((u_long*)otag);
    FntFlush(-1);
    return ret;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007647C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800765B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80076784);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80076D50);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80076F24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077078);

void func_800770FC(int arg0 __attribute__((unused)), int arg1)
{
    func_8007C8F8_t sp10;

    sp10.unk0 = 7;
    sp10.unk1 = arg1;
    sp10.unk2 = 0;
    sp10.unk10 = 0;
    func_800995E8(&sp10);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077130);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800771E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077240);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800773BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800774FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800775C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077DF0);

void func_80077EC4(void)
{
    int* temp_s0;

    func_8007CD70(D_1F800034, D_1F800034 + 4, -1, -1);
    temp_s0 = D_1F800034 - 13;
    temp_s0[25] = 0x1000;
    temp_s0[23] = 0;
    temp_s0[22] = 0;
    temp_s0[21] = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077F14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077F70);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800780A8);

void func_8007820C(int arg0)
{
    func_8007820C_t sp10;

    func_800780A8(&sp10);
    if (arg0 != 0) {
        func_8006DEFC(&sp10, 1, 0x28);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80078248);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800782E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80078364);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800784AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80078748);

void func_800787F0(void)
{
    if (!(D_800F1868 & 2)) {
        func_80070278();
        func_800CEF74(0);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80078828);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80078AB4);

void func_80079030(void) { func_8007138C(); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80079050);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800790BC);

int func_800792E4(int arg0, int arg1, int arg2)
{
    int ret = 0;
    if (vs_battle_actors[arg1] != NULL) {
        if (vs_battle_actors[arg1]->unk3C->currentHP == 0) {
            func_8006C1CC(arg0, arg1, arg2);
            if (arg1 == 0) {
                func_8009722C();
                func_800BEC58(0x40, 0, 0, 0);
                func_80073898();
                ret = 1;
            } else if (vs_battle_actors[arg1]->unk26 == 0) {
                func_8006A228(arg1, 1);
            }
        } else {
            func_8009E5C4(arg1);
        }
    }
    return ret;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800793C0);

void func_800797BC(void)
{
    func_800C97BC();
    if (*func_800CB66C() != 1) {
        func_8006C40C();
        func_800CB114();
        func_8006F89C();
    }
}

void func_8007980C(void)
{
    if (!(D_800F1868 & 3)) {
        func_8006FA20();
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007983C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", vs_battle_exec);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007A850);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007A9DC);

void func_8007AACC(int arg0) { func_8007A9DC(D_1F800034, &D_1F800034[4], arg0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007AAF8);

void func_8007ABEC(int* arg0)
{
    arg0[0] = D_1F800000[13];
    arg0[1] = D_1F800000[14];
    arg0[2] = D_1F800000[15];
}

void func_8007AC18(int* arg0)
{
    D_1F800000[13] = arg0[0];
    D_1F800000[14] = arg0[1];
    D_1F800000[15] = arg0[2];
}

void func_8007AC40(int* arg0)
{
    arg0[0] = D_1F800000[17];
    arg0[1] = D_1F800000[18];
    arg0[2] = D_1F800000[19];
}

void func_8007AC6C(int* arg0)
{
    D_1F800000[17] = arg0[0];
    D_1F800000[18] = arg0[1];
    D_1F800000[19] = arg0[2];
}

void func_8007AC94(int arg0) { D_1F800000[23] = arg0; }

int func_8007ACA0(void) { return *getScratchAddr(0x17) & 0xFFF; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007ACB0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007AFA8);

void func_8007B0FC(void) { }

void func_8007B104(void) { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B10C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B1B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B29C);

void func_8007B344(int arg0, int arg1, short arg2, short arg3, short arg4)
{
    func_800478E0(arg0, arg1, arg2, arg3, arg4);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B378);

void func_8007B3D0(int arg0, int arg1, u_short* arg2, int arg3)
{
    func_80046C80(arg0, arg1 + 4, arg2, arg3);
}

void func_8007B3F0(int arg0, D_8005DC6C_t* arg1) { func_800472D0(arg0, arg1); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B410);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B470);

void func_8007B4C4(void)
{
    D_800F18F0 = 2;
    func_8007B470();
    if (D_800F1864 != 0) {
        func_8009E5C4(0);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B508);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B63C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B764);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B7DC);

void func_8007B834(void)
{
    func_800C97BC();
    if (*func_800CB66C() != 1) {
        func_8007B470();
        func_800CB114();
        func_8007B764();
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B884);

void func_8007B908(void)
{
    if (!(D_800F1868 & 3)) {
        func_8007B63C();
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B938);

void func_8007B9A0(void)
{
    D_800F1860 = 0;
    D_800F1864 = 0;
    func_8007B7DC();
}

void func_8007B9CC(void)
{
    D_800F1860 = 0;
    D_800F1864 = 1;
    func_8007B764();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B9FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BA98);

void func_8007BBB8(int arg0, int arg1) { func_80069DEC(arg0, arg1); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BBD8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BCCC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BD3C);

int func_8007BD8C(int arg0)
{
    if (arg0 != 0) {
        func_800CB654(1);
        func_8008B4C8(0);
    } else {
        func_800CB654(0);
        func_8008B4C8(1);
    }
    return arg0;
}

int func_8007BDD8(int arg0)
{
    func_8008C40C();
    return D_800F186C = ~arg0 & 1;
}

int func_8007BE10(int arg0) { return D_800F18B0 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BE20);

void func_8007BEC4(int arg0) { func_800CEF74(arg0); }

void func_8007BEE4(void) { func_800CF48C(); }

void func_8007BF04(void) { }

int func_8007BF0C(void) { return func_800CEEBC() != 0; }

void func_8007BF2C(void) { func_8008AB80(0); }

void func_8007BF4C(void) { func_8008ABB8(0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BF6C);

void func_8007BFC0(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        func_8007BF6C(i);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BFF8);

void func_8007C050(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        func_8007BFF8(i);
    }
}

int func_8007C088(int arg0) { return vs_battle_actors[arg0]->unk20 & 1; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C0AC);

void func_8007C1D8(int arg0, int arg1)
{
    if (vs_battle_actors[arg0] != 0) {
        if (arg1 != 0) {
            vs_battle_actors[arg0]->unk1C = 4;
            return;
        }
        vs_battle_actors[arg0]->unk1C = 8;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C218);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C28C);

void func_8007C31C(void) { func_80086754(0, vs_battle_characterState->unk3C); }

void func_8007C348(int arg0, int arg1) { func_8009F314(arg0, 0, arg1); }

int func_8007C36C(int arg0)
{
    if ((arg0 == 2) || (arg0 == 4)) {
        vs_gametime_tickspeed = arg0;
    }
    return vs_gametime_tickspeed;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C398);

void func_8007C404(void) { func_80089CE4(); }

void func_8007C424(void) { func_80089D04(); }

void func_8007C444(int arg0, int arg1, int arg2)
{
    D_800F1A98 = arg0;
    D_800F1AA8 = arg1;
    D_800F1AA4 = arg2;
}

void func_8007C460(int arg0) { D_800F1AA4 = arg0; }

void func_8007C46C(int arg0, int arg1, int arg2)
{
    if ((D_800F1A48 - 1) >= 2) {
        D_800F1A48 = 5;
        D_800F1A98 = arg0;
        D_800F1AA8 = arg1;
        D_800F1AA4 = arg2;
    }
}

void func_8007C4AC(int arg0, int arg1, int arg2)
{
    D_800F1A48 = 7;
    D_800F1A98 = arg0;
    D_800F1AA8 = arg1;
    D_800F1AA4 = arg2;
}

void func_8007C4D4(void) { D_800F19A0 = 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C4E0);

void func_8007C580(void)
{
    char sp10[16];

    func_8007C4E0();
    func_800A1108(0, (int*)sp10);
    func_8008B960(sp10[0], sp10[2], sp10[1]);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C5C0);

void func_8007C654(void)
{
    char sp10[16];

    func_8007C5C0();
    func_800A1108(0, (int*)sp10);
    func_8008B960(sp10[0], sp10[2], sp10[1]);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C694);

int _getLocationId(int zoneId, int mapId)
{
    int i;

    for (i = 0; i < 512; ++i) {
        if (zoneId == vs_main_locationZoneMapIds[i * 2]
            && mapId == vs_main_locationZoneMapIds[i * 2 + 1]) {
            return i;
        }
    }
    return 0;
}

int vs_battle_getCurrentLocationId(void)
{
    return _getLocationId(D_800F1880.zoneId, D_800F1880.mapId);
}

void func_8007C8A4(int arg0)
{
    if ((vs_battle_actors[arg0] != 0) && (arg0 < 16)) {
        func_800AE4FC(vs_battle_actors[arg0]->unk44);
    }
}

int func_8007C8F0(void) { return 0; }

int func_8007C8F8(short arg0)
{
    func_8007C8F8_t sp10;

    sp10.unk2 = arg0;
    sp10.unk0 = 1;
    sp10.unk1 = 0;
    return func_800995E8(&sp10) + 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C928);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007CA20);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007CAA4);

void func_8007CB84(int arg0, int arg1)
{
    func_8007C8F8_t sp10;

    sp10.unk0 = 7;
    sp10.unk1 = arg0;
    sp10.unk2 = arg1;
    sp10.unk10 = 1;
    func_800995E8(&sp10);
}

void func_8007CBBC(int arg0) { func_8009CC20(arg0, 1); }

void func_8007CBDC(int arg0, int arg1, int arg2)
{
    func_8007C8F8_t sp10;

    sp10.unk0 = 7;
    sp10.unk1 = arg0;
    sp10.unk2 = arg1;
    sp10.unk10 = 2;
    sp10.unk11 = arg2;
    func_800995E8((func_8007C8F8_t*)&sp10);
}

void func_8007CC18(int arg0, int arg1, int arg2)
{
    func_8007C8F8_t sp10;

    sp10.unk1 = arg0;
    sp10.unk0 = 9;
    sp10.unk2 = arg1;
    sp10.unk11 = arg2;
    func_800995E8(&sp10);
}

void func_8007CC4C(void) { func_8009D208(); }

void func_8007CC6C(void) { func_8009CE9C(); }

void func_8007CC8C(void) { func_8009CFA0(); }

void func_8007CCAC(void) { func_800995B0(); }

void func_8007CCCC(int arg0)
{
    D_8005E0C8 = arg0;
    func_80098160();
}

void func_8007CCF0(int arg0)
{
    vs_main_projectionDistance = arg0;
    SetGeomScreen(arg0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007CD14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007CD70);

void func_8007CE74(int arg0)
{
    if ((arg0 == -0x300) || (arg0 == -0x80)) {
        D_800F19D4 = arg0;
        return;
    }
    D_800F19D4 = -0x180;
}

void func_8007CEA0(int arg0) { func_8009E5C4(arg0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007CEC0);

u_int func_8007CF18(int arg0)
{
    u_int i;

    for (i = 0; i < 16; ++i) {
        if ((vs_battle_actors[i] != 0) && (vs_battle_actors[i]->unk18 == arg0)) {
            return i;
        }
    }
    return 1;
}

vs_battle_actor* func_8007CF64(int arg0) { return vs_battle_actors[arg0]; }

u_int func_8007CF80(int arg0)
{
    u_int i;
    u_int var_a2;

    var_a2 = 0;
    for (i = 0; i < 16; ++i) {
        if ((vs_battle_actors[i] != 0) && (vs_battle_actors[i]->unk1C == arg0)) {
            ++var_a2;
        }
    }
    return var_a2;
}

char func_8007CFCC(int arg0)
{
    if (vs_battle_actors[arg0] != 0) {
        return vs_battle_actors[arg0]->unk26;
    }
    return 0;
}

void func_8007CFF8(int arg0, short* arg1)
{
    func_800A0A1C(arg0, 2);
    func_800E527C(arg0, arg1[0], arg1[2]);
}

int func_8007D03C(int arg0) 
{
    int temp_v0 = func_800E5154();
    if (temp_v0 == 0) {
        func_800A0A1C(arg0, func_800A0A74(arg0) & ~2);
        return 1;
    }
    return temp_v0 == 2;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D08C);

int func_8007D15C(int arg0)
{
    int i;

    for (i = 1; i < 16; ++i) {
        func_8007D08C(i, arg0);
    }
    return arg0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D1A8);

void func_8007D260(int arg0)
{
    vs_battle_actor* temp_a1 = vs_battle_actors[arg0];
    if ((temp_a1 != NULL) && (temp_a1->unk8 != 0x20)) {
        temp_a1->unk8 = 0;
    }
    func_8009DC38(arg0);
}

u_int func_8007D2B4(u_int arg0)
{
    if ((arg0 - 1) < 0xFF) {
        return (vs_main_skills[arg0].flags >> 0xF) & 1;
    }
    return 0;
}

void func_8007D2FC(u_int arg0)
{
    if ((arg0 - 1) < 0xFF) {
        vs_main_skills[arg0].flags |= 0x8000;
    }
}

void func_8007D340(int arg0) { func_8006A228(arg0, 0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D360);

void func_8007D3F8(void)
{
    D_800F1ABC = 0;
    func_8007D360();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D41C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D734);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007DD50);

void func_8007DDAC(int arg0) { D_800F1A2C = arg0; }

void func_8007DDB8(int* arg0)
{
    D_800F1A30[0] = arg0[0];
    D_800F1A30[1] = arg0[1];
}

void func_8007DDD4(D_800F1A78_t* arg0) { D_800F1A78 = *arg0; }

void func_8007DDF8(D_800F1A68_t* arg0) { D_800F1A68 = *arg0; }

void func_8007DE2C(int arg0) { D_800F1B9C = arg0; }

void func_8007DE38(int arg0) { D_800F1A20 = arg0; }

void func_8007DE44(u_int arg0)
{
    if (arg0 < 0x800) {
        D_800F1A44 = arg0;
    }
}

void func_8007DE5C(int arg0) { D_800F1A40 = arg0; }

int func_8007DE68(void) { return D_800F1B98; }

short func_8007DE78(void) { return D_800F1A2C; }

void func_8007DE88(int* arg0)
{
    arg0[0] = *D_800F1A30;
    arg0[1] = *D_800F1A30;
    arg0[2] = 0;
}

void func_8007DEA8(D_800F1A78_t* arg0) { *arg0 = D_800F1A78; }

void func_8007DECC(D_800F1A68_t* arg0) { *arg0 = D_800F1A68; }

int func_8007DF00(void) { return D_800F1B9C; }

int func_8007DF10(void) { return D_800F1A20; }

int func_8007DF20(void) { return D_800F1A44; }

int func_8007DF30(void) { return D_800F1A40; }

void func_8007DF40(void) { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007DF48);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007DF98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007DFF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E0A8);

int func_8007E180(int arg0)
{
    if (D_800F18F8 == 0) {
        D_800F18F8 = arg0;
        return 1;
    }
    vs_main_nop9(0x66, 0);
    return 0;
}

int func_8007E1C0(int arg0)
{
    if (D_800F18F8 == arg0) {
        D_800F18F8 = 0;
        return 1;
    }
    vs_main_nop9(0x67, 0);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E200);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E2AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E380);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E454);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E5E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E6A0);

void func_8007E974(void) { }

int func_8007E97C(void) { return D_800F1A04 != 0 ? 0x64 : 0xFF; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E99C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007EA74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007ECA8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007EEFC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F138);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F1A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F230);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F434);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F4B0);

int func_8007F518(u_char* arg0) { return vs_battle_actors[*arg0]->unk3C->unk37 & 7; }

int func_8007F548(void) { return 0; }

int func_8007F550(void) { return 1; }

int func_8007F558(void) { return 1; }

int func_8007F560(void) { return 1; }

int func_8007F568(int arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F518(arg1) == 2;
}

int func_8007F58C(int arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F518(arg1) != 2;
}

int func_8007F5B0(void) { return 0; }

int func_8007F5B8(void) { return 0; }

int func_8007F5C0(void) { return 0; }

int func_8007F5C8(int arg0, char* arg1) { return func_8007F4B0(5, arg1) == 0; }

int func_8007F5E8(int arg0, char* arg1) { return func_8007F4B0(7, arg1) == 0; }

int func_8007F608(int arg0, char* arg1) { return func_8007F4B0(9, arg1) == 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F628);

int func_8007F6D8(int arg0, char* arg1) { return func_8007F4B0(4, arg1) == 0; }

int func_8007F6F8(int arg0, char* arg1) { return func_8007F4B0(6, arg1) == 0; }

int func_8007F718(int arg0, char* arg1) { return func_8007F4B0(8, arg1) == 0; }

int func_8007F738(int arg0, char* arg1) { return func_8007F4B0(0xA, arg1) == 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F758);

int func_8007F808(int arg0, char* arg1) { return func_8007F4B0(0xB, arg1) == 0; }

int func_8007F828(int arg0, char* arg1) { return func_8007F4B0(0xC, arg1) == 0; }

int func_8007F848(int arg0, char* arg1) { return func_8007F4B0(0x12, arg1) == 0; }

int func_8007F868(int arg0, char* arg1) { return func_8007F4B0(0x11, arg1) == 0; }

int func_8007F888(int arg0, char* arg1) { return func_8007F4B0(0xD, arg1) == 0; }

int func_8007F8A8(int arg0, char* arg1) { return func_8007F4B0(0xE, arg1) == 0; }

int func_8007F8C8(int arg0, char* arg1) { return func_8007F4B0(0xF, arg1) == 0; }

int func_8007F8E8(int arg0, char* arg1) { return func_8007F4B0(0x10, arg1) == 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F908);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F96C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F9D0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FA34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FA98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FB34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FBD0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FC6C);

int func_8007FD08(int arg0, char* arg1) { return func_8007F4B0(0x1D, arg1) == 0; }

int func_8007FD28(int arg0 __attribute__((unused)), char* arg1)
{
    if ((func_8007F4B0(0x1E, arg1) == 0) && ((func_8007F518(arg1) == 2))) {
        return 1;
    }
    return 0;
}

int func_8007FD74(int arg0 __attribute__((unused)), char* arg1)
{
    if ((func_8007F4B0(0x1E, arg1) == 0) && (func_8007F518(arg1)) != 2) {
        return 1;
    }
    return 0;
}

void func_8007FDC0(void) { }

void func_8007FDC8(void) { }

void func_8007FDD0(void) { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FDD8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FE5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FF8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80080000);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008010C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800801A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800801E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800802C4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800803A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80080534);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800807E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80080A9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80080C9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80080F78);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80081020);

int func_800810CC(int arg0, func_80085718_t* arg1)
{
    int ret = 0;
    int* new_var = D_8004EECC[arg0];
    if (vs_battle_actors[arg1->unk0]->unk3C->flags.u8[3] != 0x80) {
        ret = new_var[0] & vs_battle_actors[arg1->unk0]->unk3C->unk948;
        arg1->unk18 |= ret;
    }
    return ret;
}

void func_80081130(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
}

short func_80081138(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    return D_800F1A08;
}

short func_80081148(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)), int arg5);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80081148);

short func_800819D0(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    return func_80081148(arg0, arg1, arg2, arg3, arg4, 0);
}

short func_800819FC(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)));
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800819FC);

short func_80082144(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    int v = (D_800F19CC->unk58 + D_800F19CC->unk5A) * arg0->hitParams[arg3].unk0_16;
    return (v / 10) + (D_800F19CC->unk0 - 1);
}

short func_800821B0(vs_skill_t* arg0, func_80085718_t* arg1,
    func_80085718_t* arg2 __attribute__((unused)), int arg3,
    int arg4 __attribute__((unused)))
{
    vs_battle_actor2* temp_v0 = vs_battle_actors[arg1->unk0]->unk3C;
    int v = (temp_v0->maxHP - temp_v0->currentHP) * arg0->hitParams[arg3].unk0_16;
    return (v / 10) + (D_800F19CC->unk0 - 1);
}

short func_80082234(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3,
    int arg4 __attribute__((unused)))
{
    int v = (D_800F19CC->unk58 + D_800F19CC->unk5A) * arg0->hitParams[arg3].unk0_16;
    return (v / 10) + (D_800F19CC->unk0 - 1);
}

short func_800822A0(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3,
    int arg4 __attribute__((unused)))
{
    int v =
        vs_battle_actors[arg2->unk0]->unk3C->currentHP * arg0->hitParams[arg3].unk0_16;
    return (v / 100) + (D_800F19CC->unk0 - 1);
}

short func_8008231C(vs_skill_t* arg0 __attribute__((unused)), func_80085718_t* arg1,
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    return vs_battle_actors[arg1->unk0]->unk3C->weapon.currentPp
         + ((u_short)D_800F19CC->unk0 - 1);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80082360);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008241C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800824D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008255C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800829B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80082FF4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083430);

short func_800834A4(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), u_char* arg2)
{
    return vs_battle_actors[*arg2]->unk3C->maxHP
         - vs_battle_actors[*arg2]->unk3C->currentHP;
}

short func_800834E4(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), u_char* arg2)
{
    return vs_battle_actors[*arg2]->unk3C->maxMP
         - vs_battle_actors[*arg2]->unk3C->currentMP;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083524);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083590);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008364C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083708);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008379C);

short vs_battle_getEquippedShieldDp(int arg0 __attribute__((unused)), u_char* arg1)
{
    return vs_battle_actors[*arg1]->unk3C->shield.currentDp;
}

short func_8008384C(u_int* arg0, int arg1 __attribute__((unused)),
    int arg2 __attribute__((unused)), int arg3)
{
    arg0 += arg3;
    return (D_800F1A08 * ((arg0[5] >> 0x16) & 0x1F)) / 10;
}

short func_8008388C(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    return func_80081148(arg0, arg1, arg2, arg3, arg4, 1);
}

short _getRisk(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), u_char* arg2)
{
    return vs_battle_actors[*arg2]->unk3C->risk;
}

short func_800838EC(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short var_v0;

    if ((arg2->unk40 == 0)
        && (vs_battle_actors[arg2->unk0]->unk3C->flags.u8[3] == 0x80)) {
        var_v0 = 999;
    } else {
        var_v0 = D_800E830C[arg0->hitParams[arg3].unk0_10](arg0, arg1, arg2, arg3, arg4);
    }
    D_800F1A08 = var_v0;
    return var_v0;
}

int func_80083990(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
}

// TODO: Change return type, these only match with int and undefined return
int func_80083998(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(5, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_800839E8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(7, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083A38(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(9, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083A88(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(19, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083AD8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(4, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083B28(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(6, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80083B78(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(8, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80083BC8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(10, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80083C18(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(20, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80083C68(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(11, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80083CB8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(12, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083D08(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    func_80081020(0x12, arg2);
}

int func_80083D2C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(17, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80083D7C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4)
{
    func_80081020(0x1D, arg2);
    if (arg4 != 0) {
        vs_battle_actors[arg2->unk0]->unk3C->flags.u32 |= 0x20000;
    }
}

int func_80083DEC(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(13, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083E3C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(14, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083E8C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(15, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083EDC(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(16, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083F2C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x15, arg2);
}

int func_80083F50(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x16, arg2);
}

int func_80083F74(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x17, arg2);
}

int func_80083F98(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x18, arg2);
}

int func_80083FBC(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x19, arg2);
}

int func_80083FE0(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x1A, arg2);
}

int func_80084004(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x1B, arg2);
}

int func_80084028(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x1C, arg2);
}

int func_8008404C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_800810CC(0xD, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_8008409C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_800810CC(0xE, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_800840EC(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_800810CC(0x10, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_8008413C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_800810CC(0xF, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_8008418C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    arg2->unk18 |= (vs_battle_actors[arg2->unk0]->unk3C->unk948 & 0x1FFE1FE0);
}

int func_800841C8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v1 = vs_battle_actors[arg2->unk0]->unk3C->unk948 & 0xE000;
    arg2->unk18 = arg2->unk18 | temp_v1;
    if (temp_v1 != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80084228(vs_skill_t* arg0 __attribute__((unused)), func_80085718_t* arg1,
    func_80085718_t* arg2, int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    arg1->unk1C.fields.unk1F_2 = 2;
}

int func_80084248(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_800810CC(0x1E, arg2);
    arg2->unk4 = vs_battle_actors[arg2->unk0]->unk3C->currentHP;
    arg2->unk1C.fields.unk1C_0 = 1;
}

int func_800842AC(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    arg2->unk3C = arg2->unk4 * 2;
    arg2->unk20.s16[arg2->unk1][1] = arg2->unk4 * 2;
    arg2->unk1C.fields.unk1E_6 = 1;
}

int func_800842F0(vs_skill_t* arg0 __attribute__((unused)), func_80085718_t* arg1,
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    arg1->unk1C.fields.unk1F_2 = 2;
}

int func_80084310(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4)
{
    if (arg4 != 0) {
        func_800BEC14(0x40, 1);
    }
}

int func_80084340(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4)
{
    if (arg4 != 0) {
        func_800BEC14(0x20, 1);
    }
}

int func_80084370(vs_skill_t* arg0 __attribute__((unused)), func_80085718_t* arg1,
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    arg1->unk1C.fields.unk1F_2 = 2;
}

int func_80084390(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (vs_main_skills[D_800F19CC->unk8].unk2_1 == 1u) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_80084440(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (vs_main_skills[D_800F19CC->unk8].unk2_1 != 1u) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_800844F0(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unkA == 0) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_80084570(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unkA == 1) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_800845F0(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unkA == 2) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_80084670(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unkA == 3) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_800846F0(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unkA == 4) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_80084770(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unkA == 5) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_800847F0(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unkA == 6) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_80084870(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    int temp_v1 = D_800F19CC->unkC[7] & 3;
    if ((temp_v1 == 1) || ((temp_v1 == 3))) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_8008490C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unkA += temp_v0;
    arg2->unk1C.fields.unk1C_6 = 2;
}

int func_80084958(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unkC += temp_v0;
    arg2->unk1C.fields.unk1D_0 = 2;
}

int func_800849A4(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unkE += temp_v0;
    arg2->unk1C.fields.unk1D_2 = 2;
}

int func_800849F0(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unk10 += temp_v0;
    arg2->unk1C.fields.unk1D_4 = 2;
}

int func_80084A3C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unk12 += temp_v0;
    arg2->unk1C.fields.unk1D_6 = 2;
}

int func_80084A8C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unkA += temp_v0;
    arg2->unk1C.fields.unk1C_6 = 1;
}

int func_80084AD8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unkC += temp_v0;
    arg2->unk1C.fields.unk1D_0 = 1;
}

int func_80084B24(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unkE += temp_v0;
    arg2->unk1C.fields.unk1D_2 = 1;
}

int func_80084B70(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short temp_v0;
    vs_battle_actor2* temp_s4 = vs_battle_actors[arg1->unk0]->unk3C;
    vs_battle_actor2* temp_s2 = vs_battle_actors[arg2->unk0]->unk3C;
    D_800F1A0C = 0;
    temp_v0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    arg2->unk4 += temp_v0;

    if (D_800F1A0C != 0) {
        arg2->unk1C.fields.unk1C_0 = 3;
    } else {
        arg2->unk1C.fields.unk1C_0 = 1;
    }

    if (arg2->unk40 == 0) {
        func_80080000(arg0, arg2, temp_v0);
        if (temp_s2->flags.u8[3] != 0x80) {
            arg2->unk18 |= temp_s2->unk948 & 0x8000;
        }
        if (arg4 != 0) {
            func_800802C4(arg0, temp_s4, temp_s2, temp_v0);
            func_800803A4(arg0, temp_s4, temp_s2, temp_v0);
        }
    }
}

int func_80084CAC(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    vs_battle_actor2* temp_s0 = vs_battle_actors[arg2->unk0]->unk3C;
    short var_a0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    if (temp_s0->currentMP < var_a0) {
        var_a0 = temp_s0->currentMP;
        D_800F1A08 = temp_s0->currentMP;
    }
    arg2->unk6 += var_a0;
    arg2->unk1C.fields.unk1C_2 = 1;
}

int func_80084D44(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    u_short new_var;

    if (vs_battle_actors[arg2->unk0]->unk3C->weapon.blade.id != 0) {
        new_var = vs_battle_actors[arg2->unk0]->unk3C->weapon.currentPp;
        arg2->unk20.s16[6][1] += new_var;
        arg2->unk1C.fields.unk1E_4 = 1;
    }
}

int func_80084DA8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    vs_battle_actor2* temp_a1 = vs_battle_actors[arg2->unk0]->unk3C;
    if (((D_800F19CC->unkC[7] & 3) == 1) || ((D_800F19CC->unkC[7] & 3) == 3)) {
        if (temp_a1->shield.shield.id != 0) {
            short var_v0 = temp_a1->shield.currentDp;
            arg2->unk3E += var_v0;
            arg2->unk1C.fields.unk1F_0 = 1;
        }
    }
}

int func_80084E28(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short temp_v0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    arg2->unk4 += temp_v0;
    arg2->unk1C.fields.unk1C_0 = 2;
    if (arg2->unk40 == 0) {
        func_800801E0(arg0, arg2, temp_v0);
    }
}

int func_80084EA0(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short temp_v0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    arg2->unk6 = arg2->unk6 + temp_v0;
    arg2->unk1C.fields.unk1C_2 = 2;
}

int func_80084EEC(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short temp_v0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    arg2->unk20.s16[6][1] += temp_v0;
    arg2->unk1C.fields.unk1E_4 = 2;
}

int func_80084F40(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short temp_v0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    arg2->unk20.s16[6][0] += temp_v0;
    arg2->unk1C.fields.unk1E_2 = 2;
}

int func_80084F94(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short temp_v0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    int var_v0 = temp_v0 << 0x10;
    if (var_v0 != 0) {
        arg2->unk8 += temp_v0;
        arg2->unk1C.fields.unk1C_4 = 2;
    }
}

int func_80084FF0(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
}

int func_80084FF8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
}

int func_80085000(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
}

void func_80085008(func_80085718_t* arg0)
{
    int i;
    int var_v1;
    short var_a1;
    u_short var_a2;
    vs_battle_actor2* temp_s3;

    temp_s3 = vs_battle_actors[arg0->unk0]->unk3C;
    switch (arg0->unk1C.fields.unk1C_0) {
    case 2:
        var_a2 =
            temp_s3->hitLocations[temp_s3->unk34].unk0 + arg0->unk20.s32[temp_s3->unk34];
        var_a1 =
            temp_s3->hitLocations[temp_s3->unk35].unk0 + arg0->unk20.s32[temp_s3->unk35];
        break;
    case 3:
    case 1:
        var_a2 =
            temp_s3->hitLocations[temp_s3->unk34].unk0 - arg0->unk20.s32[temp_s3->unk34];
        var_a1 =
            temp_s3->hitLocations[temp_s3->unk35].unk0 - arg0->unk20.s32[temp_s3->unk35];
        break;
    default:
        var_a2 = temp_s3->hitLocations[temp_s3->unk34].unk0;
        var_a1 = temp_s3->hitLocations[temp_s3->unk35].unk0;
        break;
    }
    if (!(temp_s3->unk948 & 0x10)) {
        if ((temp_s3->unk34 | temp_s3->unk35) != 0) {
            var_v1 = 0;
            if (temp_s3->unk34 != 0) {
                var_v1 = (var_a2 << 0x10) > 0x10000;
            }
            if ((temp_s3->unk35 != 0) && (var_a1 >= 2)) {
                var_v1 = 1;
            }
            if (var_v1 == 0) {
                func_80081020(4, arg0);
            }
        }
    } else {
        if ((temp_s3->unk34 | temp_s3->unk35) != 0) {
            var_v1 = 0;
            if (temp_s3->unk34 != 0) {
                var_v1 = (var_a2 << 0x10) > 0x10000;
            }
            if ((temp_s3->unk35 != 0) && (var_a1 >= 2)) {
                var_v1 = 1;
            }
            if (var_v1 != 0) {
                func_800810CC(4, arg0);
            }
        }
    }
    if (arg0->unk0 == 0) {
        for (i = 0; i < 4; ++i) {
            switch (arg0->unk1C.fields.unk1C_0) {
            case 2:
                var_a2 = temp_s3->hitLocations[i].unk0 + arg0->unk20.s32[i];
                break;
            case 3:
            case 1:
                var_a2 = temp_s3->hitLocations[i].unk0 - arg0->unk20.s32[i];
                break;
            default:
                var_a2 = temp_s3->hitLocations[i].unk0;
                break;
            }
            if (!(temp_s3->unk948 & D_8004EECC[D_800E8200[i]][0])) {
                var_v1 = var_a2 << 0x10;
                var_v1 = 0x10000 < var_v1;
                if (!var_v1) {
                    func_80081020(D_800E8200[i], arg0);
                }
            } else {
                var_v1 = (var_a2 << 0x10) > 0x10000;
                if (var_v1) {
                    func_800810CC(D_800E8200[i], arg0);
                }
            }
        }
    }
}

void func_80085390(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    u_int temp_a1_2;
    int temp_s0;

    if ((arg2->unk40 == 0)
        && (vs_battle_actors[arg2->unk0]->unk3C->flags.u8[3] == 0x80)) {
        arg2->unk4 += 999;
        arg2->unk1C.fields.unk1C_0 = 1;
    } else if (arg0->unk2_1 == 1) {
        if ((arg2->unk40 == 0)
            && (vs_battle_actors[arg2->unk0]->unk3C->unk948 & 0x80040000)) {
            D_800F1A08 = 0;
        } else {
            D_800E8378[arg0->hitParams[arg4].unk0](arg0, arg1, arg2, arg4, arg3);
        }
        if (arg2->unk40 == 0) {
            if (vs_battle_actors[arg2->unk0]->unk3C->flags.u8[3] != 0x80) {
                arg2->unk18 |= vs_battle_actors[arg2->unk0]->unk3C->unk948 & 0x61000;
            }
        }
    } else {
        D_800E8378[arg0->hitParams[arg4].unk0](arg0, arg1, arg2, arg4, arg3);
    }
    if ((arg3 != 0) && (arg1->unk40 == 0) && (arg1->unk0 == 0) && (arg2->unk40 == 0)
        && (vs_battle_actors[arg2->unk0]->unk3C->flags.u8[3] != 0x80)
        && (arg0->unk2_1 == 2 || arg0->unk2_1 == 3 || arg0->unk2_1 == 6)
        && (vs_battle_actors[arg2->unk0]->unk3C->currentHP <= arg2->unk4)
        && (arg2->unk0 != 0) && (vs_battle_actors[arg2->unk0]->unk29 == 0)) {
        vs_battle_actors[arg2->unk0]->unk29 = 1;
        temp_a1_2 = vs_battle_characterState->equippedWeaponType;
        temp_a1_2 %= 10;
        temp_s0 = temp_a1_2 & 0xFF;
        if ((func_800BEBF4(0x82, temp_a1_2) >= 0xA)
            && (vs_main_artsStatus.artsLearned[temp_a1_2 & 0xFF] < 4)
            && (vs_main_artsStatus.kills.weaponCategories[temp_a1_2 & 0xFF]
                < vs_main_artsPointsRequirements[temp_s0][vs_main_artsStatus
                                                              .artsLearned[temp_s0]])) {
            ++vs_main_artsStatus.kills.weaponCategories[temp_s0];
        }
    }
}

void func_800856F8(void* arg0) { vs_main_bzero(arg0, 0x84C); }

void func_80085718(func_80085718_t* arg0)
{
    vs_main_bzero(arg0, sizeof *arg0);
    arg0->unk3 = 6;
    arg0->unk1C.value = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008574C);

void func_80085978(int arg0, int arg1)
{
    func_8008574C(arg0, vs_battle_actors[arg1]->unk3C, 0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800859B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80085A34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80085B10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008631C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800863A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80086754);

void func_80086EA4(vs_battle_actor2* arg0, int arg1, int arg2, int arg3)
{
    if (arg0->weapon.blade.id != 0) {
        arg0->weapon.classAffinityCurrent.affinity[0][arg1] += arg3;
        arg0->weapon.classAffinityCurrent.affinity[0][arg2] -= arg3;
        arg0->weapon.unk168[arg1] = arg3;
        arg0->weapon.unk168[arg2] = -arg3;
    }
}

void func_80086EF4(vs_battle_actor2* arg0, int arg1, int arg2, int arg3)
{
    int i;

    if (arg0->shield.shield.id != 0) {
        arg0->shield.classAffinityCurrent.affinity[0][arg1] += arg3;
        arg0->shield.classAffinityCurrent.affinity[0][arg2] -= arg3;
        arg0->shield.unk134[arg1] = arg3;
        arg0->shield.unk134[arg2] = -arg3;
    }

    for (i = 0; i < 6; ++i) {
        if (arg0->hitLocations[i].armor.armor.id != 0) {
            arg0->hitLocations[i].armor.classAffinityCurrent.affinity[0][arg1] += arg3;
            arg0->hitLocations[i].armor.classAffinityCurrent.affinity[0][arg2] -= arg3;
            arg0->hitLocations[i].armor.unk88[arg1] = arg3;
            arg0->hitLocations[i].armor.unk88[arg2] = -arg3;
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80086FA8);

void func_80087578(int arg0)
{
    if ((vs_battle_actors[arg0]->unk27 != 0x80) || (arg0 == 0)) {
        func_80093B68();
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800875C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80087EF4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800882F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088554);

void func_80088B6C(void) { func_80088554(); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088B8C);

void func_80088CA0(void) { D_800E8498 = 0; }

void func_80088CAC(void)
{
    if (D_8005046A == 2) {
        func_8007BCCC();
    }
    func_80069DBC();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088CE4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088D40);

static void _loadZnd(int id)
{
    vs_main_CdFile sp10;
    int temp_s0;

    sp10.lba = vs_main_zndFiles[id].lba;
    sp10.size = vs_main_zndFiles[id].size;
    if (D_800F1880.unk20 != 0) {
        vs_main_nop9(0x87, 0);
    }
    D_800F1880.unk20 = vs_main_allocateCdQueueSlot(&sp10);
    if (D_800F1880.unk24 != 0) {
        vs_main_nop9(0x88, 0);
    }
    D_800F1880.unk24 = vs_main_allocHeapR(sp10.size);
    vs_main_cdEnqueueUrgent(D_800F1880.unk20, D_800F1880.unk24);
    if (D_800F1880.unk30 != 0) {
        temp_s0 = D_8004FCCC[id];
        if (func_800450E4() != temp_s0) {
            func_8004552C(vs_main_soundData.currentMusicId, 0, 0x78);
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088EF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089098);

int func_80089104(void) { return D_800F18A8; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089114);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089888);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089A00);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089C5C);

void func_80089CE4(void) { SetDispMask(1); }

void func_80089D04(void) { SetDispMask(0); }

void func_80089D24(int arg0)
{
    vs_main_CdFile file;

    file.lba = D_800F1880.unk4[arg0].lba;
    file.size = D_800F1880.unk4[arg0].size;

    if (D_800F1880.unk58 != 0) {
        vs_main_nop9(0x89, 0);
    }
    D_800F1880.unk58 = vs_main_allocateCdQueueSlot(&file);
    if (D_800F1880.unk5C != 0) {
        vs_main_nop9(0x8A, 0);
    }
    D_800F1880.unk5C = vs_main_allocHeapR(file.size);
    vs_main_cdEnqueueUrgent(D_800F1880.unk58, D_800F1880.unk5C);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089DC0);

void func_8008A364(void)
{
    int i;

    for (i = 2; i < 16; ++i) {
        func_8006A228(i, 0);
    }
}

// https://decomp.me/scratch/w2WqI
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008A3A0);

void func_8008A4DC(int arg0)
{
    if (arg0 != 0) {
        D_800F190C = 1;
    } else {
        D_800F190C = 0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008A4FC);

int vs_battle_getSkillFlags(int arg0, int id)
{
    vs_battle_actor2* temp_s1;
    int ret;
    vs_skill_t* skill = &vs_main_skills[id];

    temp_s1 = vs_battle_actors[arg0]->unk3C;
    ret = temp_s1->flags.u16[0] != 0;

    if (!(func_8008574C(id, temp_s1, 0) & 0xFF000000)) {
        ret |= 2;
    }

    if (arg0 == 0) {
        if (!(skill->flags & 0x8000)) {
            ret |= 4;
        }
    }
    if (id < 141) {
        if (temp_s1->unk948 & 0x1000) {
            ret |= 4;
        }
    } else if (id < 224) {
        if (vs_battle_actors[arg0]->unk20 == 0) {
            ret |= 4;
        }
        if (temp_s1->unk948 & 0x2000) {
            ret |= 4;
        }
    }
    return ret;
}

void func_8008A6FC(void)
{
    void** var_a0 = D_800F1900;

    while (var_a0 != 0) {
        void* temp_s0 = *var_a0;
        vs_main_freeHeapR(var_a0);
        var_a0 = temp_s0;
    }
    D_800F1900 = NULL;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008A744);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008A908);

void func_8008AB68(void) { vs_main_stateFlags.unk105 = D_800F1BBE + 1; }

int func_8008AB80(int arg0)
{
    if ((D_800F1BF8.unk0 == 1) && (D_800F1BF8.unk2 == arg0)) {
        D_800F1BF8.unk1 = D_800F1BF8.unk0;
        return 1;
    }
    return 0;
}

int func_8008ABB8(int arg0)
{
    if ((D_800F1BF8.unk0 == 1) && (D_800F1BF8.unk2 == arg0)) {
        D_800F1BF8.unk1 = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008ABF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008AC78);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B1FC);

void func_8008B28C(void)
{
    if (D_800F1BA4 == 0) {
        D_800F1CDC += vs_gametime_tickspeed;
    }
}

void func_8008B2C0(int arg0)
{
    if (D_800F1BF8.unk0 != 0) {
        D_800F1BF8.unk1 = arg0;
    }
}

void func_8008B2E0(void* arg0, int arg1, int arg2, int arg3)
{
    vs_main_memcpy(D_800F1BA8 + (((arg1 * 256) + arg2)), arg0, arg3 * 2);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B320);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B390);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B430);

void func_8008B4B0(void) { D_800F1BB6 = 0; }

void func_8008B4BC(int arg0) { D_800F1BA4 = arg0; }

int func_8008B4C8(char arg0) { return D_800F1CD6 = arg0; }

void vs_battle_setRoomsUnk0(vs_battle_scene* scene)
{
    int i;
    vs_battle_room* room = scene->rooms;
    int roomCount = scene->roomCount;

    for (i = 0; i < roomCount; ++i, ++room) {
        int locationId = _getLocationId(room->zoneId, room->mapId - 1);
        if (locationId > 0) {
            room->visited =
                vs_main_mapStatus.roomFlags[locationId >> 5] & (1 << (locationId & 0x1F));
        } else {
            room->visited = 0;
        }
    }
}

void func_8008B588(void) { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B590);

void func_8008B6B4(void)
{
    D_800F1D6A = 0;
    D_800F1D6C = 0;
    vs_main_bzero(&D_800F1D28, 0x40);
}

int func_8008B6EC(void) { return D_800F1C64; }

int func_8008B6FC(void) { return D_800F1C70; }

int func_8008B70C(void)
{
    if (D_800F1C60 != 0) {
        return (D_800F1C60->unk2 << 0x14) | ((u_short)(D_800F1C60->unk0 * 0x10));
    }
    return 0;
}

int func_8008B744(void)
{
    if (D_800F1CB8 != 0) {
        return D_800F1CB8;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B764);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B808);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B8F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B960);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008BAC8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008BC04);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008BD74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008BEBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008BF48);

void func_8008C070(int arg0, int arg1)
{
    int i;
    int* var_v1;

    ++D_800F1D6A;

    for (i = 0, var_v1 = D_800F1D28; i < 8; ++i) {
        if (var_v1[0] == 0) {
            var_v1[0] = arg0;
            var_v1[1] = arg1;
            return;
        }
        var_v1 += 2;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C0C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C1C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C2C0);

void func_8008C40C(void)
{
    int temp_a1;
    int i;
    int* var_a0;

    var_a0 = D_800F1C5C + 1;
    if (D_800F1C5C != 0) {
        temp_a1 = D_800F1C5C[0];
        for (i = 0; i < temp_a1; ++i) {
            *var_a0 &= ~0x1000;
            var_a0 += 16;
        }
    }
}

void func_8008C458(int arg0) { func_80098B38(arg0, 0); }

int func_8008C478(int arg0)
{
    if (D_800F1C74 != 0) {
        return D_800F1C74 + (arg0 * 8);
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C49C);

void func_8008C518(int arg0) { func_8008C49C(arg0, -1); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C538);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C6B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C8A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008CEB0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D2C0);

char func_8008D3D0(void) { return D_800F1C84->unk30; }

char func_8008D3E8(void) { return D_800F1C84->unk31; }

int vs_battle_getCurrentSceneId(void) { return D_800F1C84->sceneId; }

int func_8008D418(void) { return (D_800F1C84->unk52 << 0x10) | D_800F1C84->unk54; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D438);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D508);

void func_8008D594(int arg0) { D_800F1D6E = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D5A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D5FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D658);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D710);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D820);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D880);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D948);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DA24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DC7C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DD0C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DDA8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DEAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DF14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E19C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E224);

void* func_8008E2D4(int arg0)
{
    u_int* temp_v1;
    u_int temp_v0;

    temp_v1 = (u_int*)D_800F1CA0;

    if (D_800F1CA0 != NULL) {
        temp_v1 = D_800F1CA0[arg0];
        temp_v0 = ((temp_v1[0] >> 0x17) & 0x30) + 8;
        return (char*)temp_v1 + temp_v0;
    }
    return NULL;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E320);

int func_8008E370(int* arg0)
{
    if (D_800F1BF8.unkAC != 0) {
        *arg0 = D_800F1BF8.unk2C[8] / 564;
        return D_800F1BF8.unkAC;
    }
    *arg0 = 0;
    return 0;
}

int func_8008E3B8(int* arg0)
{
    if (D_800F1BF8.unk88 != 0) {
        *arg0 = D_800F1BF8.unk28 / 20;
        return D_800F1BF8.unk88;
    }
    *arg0 = 0;
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E400);

int func_8008E470(void) { return D_800F1CA8 < 1; }

void func_8008E480(int arg0)
{
    func_800938AC();
    func_800918E8(arg0);
}

short func_8008E4AC(void) { return D_800F1C84->unk56; }

char func_8008E4C4(void) { return D_800F1C84->unk32; }

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", D_80068BEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E4DC);

int vs_battle_getMapCompletion(void)
{
    int i;
    int j;
    int value;

    if (vs_main_mapStatus.roomFlags[1] & 0x800000) {
        vs_main_mapStatus.roomFlags[1] |= 0x400000;
    }
    value = 0;
    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 32; ++j) {
            int v = 1;
            if (vs_main_mapStatus.roomFlags[i] & vs_battle_mapCompletionFlags[i]
                & (v << j)) {
                ++value;
            }
        }
    }
    return (value * 100) / 361;
}

void func_8008E6A8(void* arg0)
{
    if (D_800F1CA4 != 0) {
        vs_main_memcpy(D_800F1CA4 + 5, arg0, 0x220);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E6DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E7BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E88C);

void func_8008E8F8(void)
{
    if (D_800F1DD4 != 0) {
        vs_main_freeHeap(D_800F1DD4);
    }
    D_800F1DD4 = vs_main_allocHeap(0x800);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E938);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008EA90);

void func_8008EAE4(short arg0, short arg1)
{
    D_800F1DB8 = arg0;
    D_800F1DBA = arg1;
}

void func_8008EAF8(int arg0) { D_800F1DC9 = arg0; }

void func_8008EB04(int* arg0, int* arg1)
{
    *arg0 = D_800F1DCA;
    *arg1 = D_800F1DC4;
}

int* func_8008EB24(void) { return D_800F1D78; }

// https://decomp.me/scratch/ck2kr
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008EB30);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008EC48);

int func_8008EFCC(int arg0)
{
    u_short* temp_s0;
    int new_var;
    vs_main_CdFile* temp_s2;
    vs_main_CdFile* temp_s3;
    int var_a0;
    int var_s0;

    temp_s0 = D_800F1C98;
    D_800F1DC8 = arg0;
    if (temp_s0 != 0) {
        D_800F1DBE = *temp_s0;
        if (func_8007DFF0(D_800F1DC8, D_800F1DBE, 5) != 0) {
            new_var = 0x800;
            temp_s2 = (vs_main_CdFile*)(temp_s0 + 0x20);
            temp_s3 = (vs_main_CdFile*)(temp_s0 + 0x42);
            var_a0 = temp_s2->size;
            var_s0 = temp_s3->size;
            if ((var_a0 & 0x7FF) != 0) {
                var_a0 = (var_a0 + new_var) - (var_a0 & 0x7FF);
            }
            if ((var_s0 & 0x7FF) != 0) {
                var_s0 = (var_s0 + new_var) - (var_s0 & 0x7FF);
            }
            D_800F1DD0 = vs_main_allocHeapR(var_a0);
            D_800F1DCC = vs_main_allocHeapR(var_s0);
            if ((D_800F1DD0 == 0) || (D_800F1DCC == 0)) {
                return 0;
            }
            D_800F1DAC = vs_main_allocateCdQueueSlot(temp_s2);
            D_800F1DB0 = vs_main_allocateCdQueueSlot(temp_s3);
            vs_main_cdEnqueue(D_800F1DAC, D_800F1DD0);
            vs_main_cdEnqueue(D_800F1DB0, D_800F1DCC);
            return 1;
        }
    }
    D_800F1DAC = 0;
    D_800F1DB0 = 0;
    return 0;
}

int func_8008F0FC(void)
{
    if ((D_800F1DAC != NULL) && (D_800F1DAC->state == 4)) {
        func_80103530_t sp10;

        *D_800F1DD0 = 0x10;
        func_8008D820(D_800F1DD0, &sp10);
        if (sp10.unk10 != NULL) {
            sp10.unkC->x = (sp10.unkC->x & 0x3F) + ((D_800F1DC8 & 0xF) << 6);
            sp10.unkC->y = (char)sp10.unkC->y + ((D_800F1DC8 & 0x10) * 0x10);
            LoadImage(sp10.unkC, sp10.unk10);
        }
        if (sp10.unk8 != NULL) {
            func_80048A64((void*)sp10.unk8, 0xE, 0, 0x100);
        }
        vs_main_freeCdQueueSlot(D_800F1DAC);
        D_800F1DAC = NULL;
        return 0;
    }

    if ((D_800F1DB0 != NULL) && (D_800F1DB0->state == 4)) {
        vs_main_freeHeapR(D_800F1DD0);
        D_800F1DD0 = NULL;
        vs_main_freeCdQueueSlot(D_800F1DB0);
        D_800F1DB0 = NULL;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008F234);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008F29C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008F30C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008F440);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008F9A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008FA14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008FAC8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008FDC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80090434);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80090A1C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80090B28);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", D_80068C1C);
