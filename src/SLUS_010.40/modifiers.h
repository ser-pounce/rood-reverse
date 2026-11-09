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
    signed char phys;
    signed char wind;
    signed char fire;
    signed char earth;
    signed char water;
    signed char light;
    signed char dark;
    UNUSED signed char _;
} material_modifiers_affinities_t;

typedef struct {
    signed char human;
    signed char beast;
    signed char undead;
    signed char phantom;
    signed char dragon;
    signed char evil;
    material_modifiers_affinities_t attackAffinities;
    material_modifiers_affinities_t defenseAffinities;
    u_short maxDp;
    short strength;
    short intelligence;
    short agility;
} material_modifiers_t;

extern material_modifiers_t vs_main_materialModifiers[8];
extern vs_main_statusEffectParams_t vs_main_statusEffectParams[];
