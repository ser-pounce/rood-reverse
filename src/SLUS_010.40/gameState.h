#pragma once
#include "common.h"
#include "inventory.h"
#include <sys/types.h>

typedef struct {
    u_char unk0_0 : 4;
    u_char containerEmpty : 1;
    u_char abilityTimingDisplay : 1;
    u_char weaponStatChange : 1;
    u_char armorStatChange : 1;
    char cursorMemory;
    u_short menuFlags;
    u_int slotState;
    char information;
    char simpleMap;
    char monoSound;
    char vibrationOn;
    char mappedChainAbilities[4];
    char mappedDefenseAbilities[4];
    u_int key;
    u_short cumulativeSaveCount;
    u_short currentGameSaveCount;
    u_int saveFileGeneration;
} vs_main_settings_t;

typedef union {
    struct {
        signed char f;
        signed char s;
        signed char m;
        signed char h;
    } t;
    u_int all;
} vs_Gametime_t;

typedef struct {
    u_int time : 24;
    u_int round : 7;
    u_int difficulty : 1;
} vs_trialScore_t;

typedef struct {
    int titles;
    u_short enemyKills[6];
    UNUSED int _0;
    u_short weaponAttacks[10];
    vs_trialScore_t bossTimeTrialScores[8][3];
    u_short maxChain;
    UNUSED u_short _1;
    u_int clearCount;
    u_int completionTimeMinutes;
    u_int mapCompletion;
    u_int openedChestCount;
    int enemyKillFlags[26];
    u_int streakScore;
    u_int miscScore;
    char killStreakEnemyClass;
    char killStreakEnemyCount;
    char weaponKillStreakBladeCategory;
    char weaponKillStreak;
    u_short chainStreak;
    u_short healCount;
} vs_main_scoredata_t;

typedef struct {
    short hp;
    short maxHp;
    short types[4];
    short affinities[8];
} vs_main_characterSnapshotLimb_t;

typedef struct {
    int restorePending;
    short currentHP;
    short maxHP;
    short currentMP;
    short maxMP;
    u_short strength;
    u_short totalStrength;
    u_short intelligence;
    u_short totalIntelligence;
    u_short agility;
    u_short totalAgility;
    u_short risk;
    u_short actionDelay;
    int statuses;
    char statusTimers[8];
    vs_main_characterSnapshotLimb_t limbs[6];
    int weaponDrawn;
    int cameraPitch;
    int cameraDistance;
} vs_main_characterSnapshotStats_t;

typedef struct {
    vs_main_characterSnapshotStats_t stats;
    UNUSED int _[9];
} vs_main_characterSnapshot_t;

typedef struct {
    u_char artsLearned[12];
    struct {
        u_short weaponCategories[10];
        u_short battleAbilitiesUnlocked;
        u_short total;
    } kills;
} vs_main_artsStatus_t;

typedef struct {
    int roomFlags[16];
    int areaFlags[2];
} vs_main_mapStatus_t;

typedef struct {
    vs_main_inventoryWeapon weapons[8];
    vs_main_inventoryShield shields[8]; // 0x100
    vs_main_inventoryBlade blades[16]; // 0x280
    vs_main_inventoryGrip grips[16]; // 0x540
    vs_main_inventoryArmor armor[16]; // 0x640
    vs_main_inventoryGem gems[48]; // 0x8C0
    vs_main_inventoryMisc misc[64]; // 0xE00
} vs_main_inventory_t;

typedef struct {
    char mode;
    char savedMode;
    u_short lifetime;
    vs_Gametime_t time;
} vs_main_battleTimer_t;

// Avoids breaking .bss order
#ifndef VS_MAIN_INCLUDE
extern vs_main_battleTimer_t vs_main_battleTimer;
extern int vs_gametime_tickspeed;
extern vs_main_scoredata_t vs_main_scoredata;
extern char vs_main_actionsLearned[32];
extern vs_main_mapStatus_t vs_main_mapStatus;
extern vs_main_settings_t vs_main_settings;
extern vs_main_artsStatus_t vs_main_artsStatus;
extern vs_main_characterSnapshot_t vs_main_characterSnapshot;
extern vs_main_inventory_t vs_main_inventory;
extern vs_Gametime_t vs_main_gametime;
extern vs_main_inventoryIndices_t vs_main_inventoryIndices;
#endif

void vs_main_setCharacterRestorePending(void);
void vs_main_captureSaveState(void);
