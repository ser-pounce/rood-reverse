#pragma once
#include "common.h"
#include "inventory.h"
#include <sys/types.h>

typedef struct {
    u_char unk0_0 : 3;
    u_int puzzleModeOff : 1;
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
} vs_main_Settings;

typedef union {
    struct {
        signed char f;
        signed char s;
        signed char m;
        signed char h;
    } t;
    u_int all;
} vs_Gametime;

typedef struct {
    u_int time : 24;
    u_int round : 7;
    u_int difficulty : 1;
} vs_TrialScore;

typedef struct {
    int titles;
    u_short enemyKills[6];
    UNUSED int _0;
    u_short weaponAttacks[10];
    vs_TrialScore bossTimeTrialScores[8][3];
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
} vs_main_Scoredata;

typedef struct {
    short hp;
    short maxHp;
    short types[4];
    short affinities[8];
} vs_main_CharacterSnapshotLimb;

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
    vs_main_CharacterSnapshotLimb limbs[6];
    int weaponDrawn;
    int cameraPitch;
    int cameraDistance;
} vs_main_CharacterSnapshotStats;

typedef struct {
    vs_main_CharacterSnapshotStats stats;
    UNUSED int _[9];
} vs_main_CharacterSnapshot;

typedef struct {
    u_char artsLearned[12];
    struct {
        u_short weaponCategories[10];
        u_short battleAbilitiesUnlocked;
        u_short total;
    } kills;
} vs_main_ArtsStatus;

typedef struct {
    int roomFlags[16];
    int areaFlags[2];
} vs_main_MapStatus;

typedef struct {
    vs_main_InventoryWeapon weapons[8];
    vs_main_InventoryShield shields[8]; // 0x100
    vs_main_InventoryBlade blades[16]; // 0x280
    vs_main_InventoryGrip grips[16]; // 0x540
    vs_main_InventoryArmor armor[16]; // 0x640
    vs_main_InventoryGem gems[48]; // 0x8C0
    vs_main_InventoryMisc misc[64]; // 0xE00
} vs_main_Inventory;

typedef struct {
    char mode;
    char savedMode;
    u_short lifetime;
    vs_Gametime time;
} vs_main_BattleTimer;

// Avoids breaking .bss order
#ifndef VS_MAIN_INCLUDE
extern vs_main_BattleTimer vs_main_battleTimer;
extern int vs_gametime_tickspeed;
extern vs_main_Scoredata vs_main_scoredata;
extern char vs_main_actionsLearned[32];
extern vs_main_MapStatus vs_main_mapStatus;
extern vs_main_Settings vs_main_settings;
extern vs_main_ArtsStatus vs_main_artsStatus;
extern vs_main_CharacterSnapshot vs_main_characterSnapshot;
extern vs_main_Inventory vs_main_inventory;
extern vs_Gametime vs_main_gametime;
extern vs_main_InventoryIndices vs_main_inventoryIndices;
#endif

void vs_main_setCharacterRestorePending(void);
void vs_main_captureSaveState(void);
