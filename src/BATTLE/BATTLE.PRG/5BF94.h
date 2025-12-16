#pragma once
#include "../../SLUS_010.40/main.h"
#include "146C.h"

enum vs_battle_warlockSpellIds_e {
    vs_battle_spell_solidShock = 0x61,
    vs_battle_spell_lightningBolt,
    vs_battle_spell_fireball,
    vs_battle_spell_vulcanLance,
    vs_battle_spell_aquaBlast,
    vs_battle_spell_spiritSurge,
    vs_battle_spell_darkChant,
    vs_battle_spell_exorcism,
    vs_battle_spell_banish,
    vs_battle_spell_explosion,
    vs_battle_spell_thunderburst = 0x6E,
    vs_battle_spell_flameSphere = 0x72,
    vs_battle_spell_gaeaStrike = 0x76,
    vs_battle_spell_avalanche = 0x7A,
    vs_battle_spell_radialSurge = 0x7E,
    vs_battle_spell_meteor = 0x82,
    vs_battle_spell_drainHeart = 0x5E,
    vs_battle_spell_drainMind = 0x5F
};

typedef struct {
    char state;
    char unk1;
    char unk2;
    char unk3;
    char unk4;
    char unk5;
    signed char selected;
    signed char unk7;
    char unk8;
    char flags;
    char unkA;
    char unkB;
    char unkC;
    char unkD;
    short unkE;
    short unk10;
    short unk12;
    short animSpeed;
    short y;
    short x;
    short unk1A;
    char text[32];
    int unk3A;
} vs_battle_menuItem_t;

typedef struct {
    char currentState;
    char returnState;
    char unk2;
    char unk3;
    vs_main_CdQueueSlot* unk4;
} vs_battle_menuState_t;

typedef struct {
    union {
        int unk0_0;
        char unk0_1[4];
    } unk0;
    short unk4[15];
    char unk22;
    char unk23;
    int unk24;
    int unk28;
    int unk2C;
} D_800F4FE0_t;

typedef struct {
    char unk0[0x34];
    char unk34[6];
    char unk3A[6];
    char unk40[0x44];
    char selectedEquipment;
    char unk85[0x6D];
} D_800F4EE8_t;

typedef struct {
    short unk0;
    short unk2;
    int executeAbility;
} D_800F4E98_t;

typedef struct {
    int integers[10];
    char* strings[10];
} vs_battle_stringContext_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8_0 : 1;
    int unk8_1 : 14;
    int unk8_15 : 1;
    int unk8_16 : 7;
    int unk8_23 : 1;
    int unk8_24 : 8;
    u_short unkC[722];
    char unk5B0_0 : 4;
    char unk5B0_4 : 1;
    char unk5B0_5 : 3;
    char unk5B1;
    char unk5B2;
    char unk5B3;
    char unk5B4;
    char unk5B5;
    char unk5B6;
    char unk5B7;
    char unk5B8;
    char unk5B9;
    char unk5BA;
    char unk5BB;
    char unk5BC[130];
    u_short unk63E;
    int unk640[5];
    u_short unk654;
    u_short unk656;
    int unk658[42];
    int unk704;
} D_800F453C_t;

typedef struct {
    short unk0;
    char unk2;
    char unk3;
    short unk4;
    short unk6;
    char unk8;
    char unk9;
    char unkA;
    char unkB;
    int unkC;
    short unk10;
    short unk12;
    union {
        char u8[2];
        u_short u16;
    } unk14;
    union {
        char u8[2];
        u_short u16;
    } unk16;
    short unk18;
    short unk1A;
    int unk1C[49];
    short unkE0;
    short unkE2;
    short unkE4;
} func_800CF0E8_t;

int func_800C4794(char*);
int func_800C58F8(void*);
void func_800C6540(char const*, int, int, u_long*);
char* vs_battle_printf(char*, char*);
void vs_battle_renderTextRaw(char const* text, int xy, void*);
void func_800C6BF0(int, void*);
void func_800C70F8(int, int, int, u_long*);
void func_800C7210(char arg0);
void func_800C8E04(int);
int func_800C8FAC(int, int, int);
vs_battle_menuItem_t* vs_battle_getMenuItem(int id);
vs_battle_menuItem_t* vs_battle_setMenuItem(
    int id, int animSpeed, int y, int arg3, int arg4, char* text);
void func_800C9078(vs_battle_menuItem_t*);
int func_800C930C(int);
void func_800C97BC(void);
int vs_battle_renderValue(int, int, int, u_long*);
void vs_battle_drawStatBar(int, int, u_long*, int);
int vs_battle_getStatusFlags(vs_battle_actor2*);
int vs_battle_getHitLocationStatus(void*);
void func_800CAB40(void);
int func_800CABE0(int);
int func_800CAEAC(int);
int vs_battle_abilitiesUnlocked(int);
void func_800CB23C(void);
void func_800CB660(int arg0);
short* func_800CB66C(void);
void func_800CB114(void);
void func_800CB158(void**);
int func_800CB45C(void);
void func_800CB50C(void);
void func_800CB550(void);
void func_800CB560(void);
void func_800CB654(int);
void vs_battle_rMemzero(void* arg0, int arg1);
void vs_battle_rMemcpy(void* dest, void const* src, int size);
int vs_battle_toBCD(int);
int vs_battle_drawCursor(int animStep, int position);
u_int vs_battle_encode(int value);
void func_800CCCB8(u_long*, int, int, int);
D_800F4FE0_t* func_800CCDF4(int arg0);
void func_800CCF08(int, int, int, int, int, int, int, int);
int func_800CD064(int);
void vs_battle_drawImage(int xy, void* buffer, int wh);
int func_800CEEBC(void);
void func_800CEF74(int);
void func_800CF0E8(func_800CF0E8_t*, int, int);
void func_800CF3F8(func_800CF0E8_t*, int);
int func_800CF48C(void);
void func_800CF7A8(int, int, int, int);
void func_800CF830(int, int);
void func_800CF920(void);

extern u_short vs_battle_menuStrings[];
extern char* vs_battle_hitlocations[];
extern u_short D_800EA868[];
extern char D_800EB9AE;
extern int D_800EB9B0;
extern vs_battle_menuItem_t* vs_battle_menuItems;
extern char vs_battle_rowAnimationSteps[];
extern int D_800EBBEC[];
extern char D_800EBBFC[];
extern char D_800EBC00[];
extern u_short D_800EBC14[];
extern u_int D_800EBC54[];
extern char vs_battle_animationIndices[];
extern char vs_battle_warlockSpellIds[];
extern char vs_battle_shamanSpellIds[];
extern char vs_battle_sorcererSpellIds[];
extern char vs_battle_enchanterSpellIds[];
extern char D_800EC270[];
extern char vs_battle_chainAbilityOffsets[];
extern char vs_battle_defenseAbilityOffsets[];
extern char vs_battle_shortcutInvoked;
extern D_800F453C_t* D_800F453C;
extern char D_800F4E6B;
extern void* D_800F4E84;
extern char D_800F4E88;
extern char* vs_battle_stringBuf;
extern char D_800F4E90;
extern D_800F4E98_t D_800F4E98;
extern int D_800F4EA0;
extern D_800F4EE8_t D_800F4EE8;
extern char D_800F4FDA;
extern char D_800F4FDB;
extern D_800F4FE0_t D_800F4FE0[];
extern u_int D_800F5130;
extern short D_800F514C;
extern vs_battle_stringContext_t vs_battle_stringContext;
extern vs_battle_menuState_t vs_battle_menuState;
