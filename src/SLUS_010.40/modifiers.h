#pragma once
#include "common.h"
#include <sys/types.h>

typedef struct {
    u_int status;
    u_short duration;
    u_short tickInterval;
    u_int replacesMask;
    u_int blockedByMask;
} vs_main_statusEffectParams_t;

typedef struct {
    u_char phys;
    u_char wind;
    u_char fire;
    u_char earth;
    u_char water;
    u_char light;
    u_char dark;
    UNUSED u_char _;
} material_modifiers_affinities_t;

typedef struct {
    u_char human;
    u_char beast;
    u_char undead;
    u_char phantom;
    u_char dragon;
    u_char evil;
    material_modifiers_affinities_t attackAffinities;
    material_modifiers_affinities_t defenseAffinities;
    u_short maxDp;
    short strength;
    short intelligence;
    short agility;
} material_modifiers_t;

extern material_modifiers_t vs_main_materialModifiers[8];
extern vs_main_statusEffectParams_t vs_main_statusEffectParams[];
