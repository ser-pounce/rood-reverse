#pragma once
#include "common.h"
#include <sys/types.h>

typedef struct {
    u_int status;
    u_short duration;
    u_short tickInterval;
    u_int replacesMask;
    u_int blockedByMask;
} vs_StatusEffectParams;

typedef struct {
    signed char phys;
    signed char wind;
    signed char fire;
    signed char earth;
    signed char water;
    signed char light;
    signed char dark;
    UNUSED signed char _;
} MaterialModifiersAffinities;

typedef struct {
    signed char human;
    signed char beast;
    signed char undead;
    signed char phantom;
    signed char dragon;
    signed char evil;
    MaterialModifiersAffinities attackAffinities;
    MaterialModifiersAffinities defenseAffinities;
    u_short maxDp;
    short strength;
    short intelligence;
    short agility;
} MaterialModifiers;

extern MaterialModifiers vs_main_materialModifiers[8];
extern vs_StatusEffectParams vs_main_statusEffectParams[];
