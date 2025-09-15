#pragma once
#include "../SLUS_010.40/main.h"

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
    char weaponType;
    char unkA;
    char unkB;
    char unkC;
    char unkD;
    short unkE;
    int unk10;
    short animSpeed;
    short y;
    short x;
    short unk1A;
    char text[36];
} vs_battle_menuItem_t;

typedef struct {
    char currentState;
    char returnState;
    char unk2;
    char unk3;
    vs_main_CdQueueSlot* unk4;
} vs_battle_menuState_t;

typedef struct {
    int unk0;
    short unk4[22];
} D_800F4FE0_t;

typedef struct {
    char unk0[0xF2];
} D_800F4EE8_t;

typedef struct {
    short unk0;
    short unk2;
    int executeAbility;
} D_800F4E98_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2[0x58];
} D_800F4E8C_t;

void func_800C6540(char const*, int, int, u_long*);
void func_800C685C(D_800F4E8C_t*, char*);
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
int func_800CABE0(int);
int func_800CAEAC(int);
int vs_battle_abilitiesUnlocked(int);
short* func_800CB66C(void);
void func_800CB114(void);
int func_800CB45C(void);
void func_800CB50C(void);
void func_800CB654(int);
void vs_battle_rMemzero(void* arg0, int arg1);
void vs_battle_rMemcpy(void* dest, void const* src, int size);
int vs_battle_toBCD(int);
int vs_battle_drawCursor(int animStep, int position);
u_int vs_battle_encode(int value);
D_800F4FE0_t* func_800CCDF4(int arg0);
void func_800CCF08(int, int, int, int, int, int, int, int);
int func_800CD064(int);
void vs_battle_drawImage(int xy, void* buffer, int wh);
int func_800CEEBC(void);
void func_800CEF74(int);
int func_800CF48C(void);
void func_800CF7A8(int, int, int, int);
void func_800CF830(int, int);
void func_800CF920(void);

extern u_short vs_battle_menuStrings[];
extern int D_800EB9B0;
extern vs_battle_menuItem_t* vs_battle_menuItems;
extern char vs_battle_rowAnimationSteps[];
extern char D_800EBC7C[];
extern char vs_battle_warlockSpellIds[];
extern char vs_battle_shamanSpellIds[];
extern char vs_battle_sorcererSpellIds[];
extern char vs_battle_enchanterSpellIds[];
extern char D_800EC270[];
extern char vs_battle_chainAbilityOffsets[];
extern char vs_battle_defenseAbilityOffsets[];
extern char vs_battle_shortcutInvoked;
extern char D_800F4E6B;
extern void* D_800F4E84;
extern char D_800F4E88;
extern D_800F4E8C_t* D_800F4E8C;
extern D_800F4E98_t D_800F4E98;
extern int D_800F4EA0;
extern D_800F4EE8_t D_800F4EE8;
extern char D_800F4F1C[6];
extern char D_800F4F70;
extern char D_800F4FDB;
extern char D_800F4FDA;
extern D_800F4FE0_t D_800F4FE0[];
extern u_int D_800F5130;
extern short D_800F514C;
extern char* vs_battle_stringContext[];
extern char (*D_800F5190)[24];
extern vs_battle_menuState_t vs_battle_menuState;
