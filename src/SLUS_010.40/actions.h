#pragma once
#include <sys/types.h>

enum actions_e { vs_main_actions_daggerArt1 = 184 };

enum actionTypes {
    actionTypeSpell = 1,
    actionTypeAbility,
    actionTypeBreakArt,
    actionTypeItem = 5,
    actionTypeBaseAttack,
    actionTypeTrap
};

enum enemyClasses { enemyClassUndead = 2 };

typedef struct {
    u_short unk0 : 4;
    u_short unk4 : 1;
    u_short unk5 : 1;
    u_short unk6 : 1;
    u_short unk7 : 1;
    u_short unk8 : 4;
    u_short unk12 : 1;
    u_short unk13 : 1;
    u_short unk14 : 2;
} vs_actionFlags_t;

typedef struct {
    u_char id;
    u_char unk1;
    u_char unk2_0 : 1;
    u_char type : 3;
    u_char unk2_4 : 4;
    u_char cost;
    u_char rangeX;
    u_char rangeY;
    u_char rangeZ;
    u_char shape : 3;
    u_char angle : 5;
    u_char aoe_0;
    u_char aoe_8;
    u_char aoe_16;
    u_char aoe_24;
    u_char flags_0;
    u_int flagsD_0 : 4;
    u_int flagsD_4 : 2;
    u_int flagsD_6 : 1;
    u_int unlocked : 1;
    vs_actionFlags_t flagsE;
    int unk10;
    struct {
        u_int effect : 7;
        u_int prerequisiteFunction : 6;
        u_int hitFunction : 3;
        u_int statCalculator : 6;
        u_int statFactor : 5;
        u_int type : 2;
        u_int affinity : 3;
    } hitParams[2];
    char name[24];
} vs_action_t;

extern vs_action_t vs_main_actions[256];
extern u_short vs_main_artsPointsRequirements[][4];
extern u_short vs_main_battleAbilitiesPointsRequirements[];
