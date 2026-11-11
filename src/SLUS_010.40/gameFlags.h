#pragma once
#include <sys/types.h>

enum itemIdentifiers { bronzeKey = 458, chamomileSigil = 466 };

// Indices into vs_main_stateFlags, an alternative to accessing its members by name
enum stateFlagIds { scriptScratch = 0x10 };

typedef struct {
    char clearCount;
    char difficulty;
    char normalModeCleared;
    char unk3;
    char unk4;
    char unk5;
    char unk6;
    char unk7;
    char unk8;
    char unk9;
    char unkA;
    char unkB;
    char unkC;
    char unkD;
    char unkE;
    char unkF;
    char scriptScratch[16]; // reset when an event starts
    char unk20;
    char unk21[0x1F];
    char unk40;
    char unk41[0x5F];
    char puzzleTimerHundredths;
    char puzzleTimerSeconds;
    char puzzleTimerMins;
    char puzzleSetMaxTimer;
    char gameOver;
    char unkA5;
    char unkA6;
    char unkA7;
    char unkA8;
    char unkA9;
    char unkAA;
    char introState;
    char unkAC[9];
    char unkB5;
    char menuFSubmenu;
    char magicUsed;
    char battleAbilitiesUsed;
    char breakArtsUsed;
    char unkBA;
    char unkBB;
    char unkBC;
    char unkBD;
    char unkBE;
    char unkBF;
    char unkC0;
    char unkC1;
    char unkC2;
    char unkC3;
    u_char timeAttackBoss;
    u_char timeAttackMins;
    u_char timeAttackSecs;
    u_char timeAttackHundredths;
    char unkC8;
    char unkC9;
    char unkCA;
    char unkCB;
    char damascusGolemDefeated;
    char damascusCrabDefeated;
    char ravanaDefeated;
    char dragonZombieDefeated;
    char deathAndOgreZombieDefeated;
    char asuraDefeated;
    char unkD2[51];
    char doorEntered;
    char unk106[22];
    char puzzleMode;
    char puzzleModeDisabled;
    char unk11E[23];
    char mapPaling[32];
    char unk135;
    char savePointStates[48];
    char unk186[48];
    char unk1B6[393]; // Start of inventory flags?
    char unk33F[65];
    /* 0x380 */ char bronzeKeyObtained;
    /* 0x381 */ char ironKeyObtained;
    /* 0x382 */ char silverKeyObtained;
    /* 0x383 */ char goldKeyObtained;
    /* 0x384 */ char platinumKeyObtained;
    /* 0x385 */ char steelKeyObtained;
    /* 0x386 */ char crimsonKeyObtained;
    /* 0x387 */ char chestKeyObtained;
    /* 0x388 */ char chamomileSigilUsed;
    /* 0x389 */ char lilySigilUsed;
    /* 0x38A */ char tearoseSigilUsed;
    /* 0x38B */ char clematisSigilUsed;
    /* 0x38C */ char hyacinthSigilUsed;
    /* 0x38D */ char fernSigilUsed;
    /* 0x38E */ char asterSigilUsed;
    /* 0x38F */ char euleliaSigilUsed;
    /* 0x390 */ char melissaSigilUsed;
    /* 0x391 */ char callaSigilUsed;
    /* 0x392 */ char laurelSigilUsed;
    /* 0x393 */ char acaciaSigilUsed;
    /* 0x394 */ char palmSigilUsed;
    /* 0x395 */ char kalmiaSigilUsed;
    /* 0x396 */ char colombineSigilUsed;
    /* 0x397 */ char anemoneSigilUsed;
    /* 0x398 */ char verbenaSigilUsed;
    /* 0x399 */ char schirraSigilUsed;
    /* 0x39A */ char marigoldSigilUsed;
    /* 0x39B */ char azaleaSigilUsed;
    /* 0x39C */ char tigertailSigilUsed;
    /* 0x39D */ char stockSigilUsed;
    /* 0x39E */ char cattleyaSigilUsed;
    /* 0x39F */ char mandrakeSigilUsed;
    char unk3A8[32];
    char chestsOpened[64];
    char unk400[64];
} vs_Flags;

// Avoids breaking .bss order
#ifndef VS_MAIN_INCLUDE
extern vs_Flags vs_main_stateFlags;
#endif
