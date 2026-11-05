#pragma once
#include "common.h"
#include "25AC.h"
#include "inventory.h"
#include <sys/types.h>
#include <libds.h>
#include <libgte.h>
#include <libgpu.h>

typedef struct {
    char mode;
    char exId;
    char states;
    char rStickX;
    char rStickY;
    char lStickX;
    char lStickY;
    char lock;
    char actData[2];
    char connected;
} portInfo_t;

typedef struct {
    int lba;
    int size;
} vs_main_CdFile;

enum vs_main_CdQueueState {
    vs_main_CdQueueStateFree = 0,
    vs_main_CdQueueStateAllocated = 1,
    vs_main_CdQueueStateReading = 2,
    vs_main_CdQueueStateEnqueued = 3,
    vs_main_CdQueueStateLoaded = 4,
    vs_main_CdQueueStateError = 6,
    vs_main_CdQueueStateDispatched = 7,
};

typedef struct {
    short state;
    short priority;
    vs_main_CdFile cdFile;
    int unkC;
    void* vram;
} vs_main_CdQueueSlot;

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

typedef struct {
    u_int status;
    u_short duration;
    u_short tickInterval;
    u_int replacesMask;
    u_int blockedByMask;
} vs_main_statusEffectParams_t;

typedef struct {
    int currentMusicSlot;
    u_int unk4;
    u_int unk8;
    void* currentMusicData;
    char musicIds[4];
    u_int unk14[4];
    void* musicData[4];
    vs_main_CdQueueSlot* musicQueueSlot[4];
    u_int currentSfxId;
    char sfxIds[4];
    void* sfxData[3];
    vs_main_CdQueueSlot* sfxQueueSlot[3];
    void* unk64[3];
    int* unk70[3];
    int soundFileId;
    void* soundData;
    vs_main_CdQueueSlot* soundQueueSlot;
} soundData_t;

typedef struct vs_main_HeapHeader {
    struct vs_main_HeapHeader* prev;
    struct vs_main_HeapHeader* next;
    u_int blockSz;
    int unkC;
} vs_main_HeapHeader;

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
    u_short hp;
    u_short maxHp;
    u_short types[4];
    u_short affinities[8];
} vs_main_characterSnapshotLimb_t;

typedef struct {
    int restorePending;
    short currentHP;
    short maxHP;
    short currentMP;
    short maxMP;
    short strength;
    short totalStrength;
    short intelligence;
    short totalIntelligence;
    short agility;
    short totalAgility;
    short risk;
    u_short flags;
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

enum itemIdentifiers { bronzeKey = 458, chamomileSigil = 466 };

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
    char textBoxSelection;
    char unk11;
    char unk12;
    char unk13;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    char unk18;
    char unk19;
    char unk1A;
    char unk1B;
    char unk1C;
    char unk1D;
    char unk1E;
    char unk1F;
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
} vs_main_flags_t;

typedef struct {
    u_char artsLearned[12];
    struct {
        u_short weaponCategories[10];
        u_short battleAbilitiesUnlocked;
        u_short total;
    } kills;
} vs_main_artsStatus_t;

typedef struct {
    char r;
    char g;
    char b;
    char unk3;
} D_8005DC6C_t;

typedef struct {
    int lStickX;
    int lStickY;
    int rStickX;
    int rStickY;
} vs_main_stickPos;

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
    u_char index;
    u_char hidden;
    short actorState;
    short currentHP;
    short maxHP;
    short currentMP;
    short maxMP;
    short strength;
    short intelligence;
    short agility;
    short limbHP[6];
    UNUSED short _;
    int statuses;
    u_char x;
    u_char direction;
    u_char z;
    u_char height;
} vs_main_savedEnemyState_t;

typedef struct {
    char lru;
    char zndId;
    u_short mapId;
    u_int nextSlot;
    vs_main_savedEnemyState_t state[8];
} vs_main_zoneEnemyCache_t;

typedef struct {
    char mode;
    char savedMode;
    u_short lifetime;
    vs_Gametime_t time;
} vs_main_battleTimer_t;

typedef struct {
    u_short unk0_0 : 5;
    u_short unk0_5 : 5;
    u_short unk0_10 : 3;
    u_short unk0_13 : 3;
} _mpdRoomDoorSection2;

typedef struct {
    u_char zndId;
    u_char mpdId;
    _mpdRoomDoorSection2 unk2;
    u_short unk4_0 : 8;
    u_short x : 5;
    u_short facing : 2;
    u_short unk4_15 : 1;
    u_short unk6_0 : 10;
    u_short z : 5;
    u_short unk6_15 : 1;
    u_char unk8;
    u_char unk9;
    u_char unkA;
    u_char unkB;
} _mpdRoomDoorSection_t;

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

enum cdBufferModes_e {
    cdBufferModeNone = 0,
    cdBufferModeBuffered = 1,
    cdBufferModeManual = 2,
};

typedef struct {
    char state;
    char unk1;
    char unk2;
    char unk3;
    u_int unk4;
    u_int sectorCount;
    int cdSector;
    union {
        int byteCount; // data reads
        int cdVolume; // XA streams: target CD volume
    } request;
    void* vram;
    DslFILTER pcm;
    DslLOC cdLoc;
    int commandId;
    int unk24;
    int unk28;
    enum cdBufferModes_e bufferMode;
    u_int sectorBufIndex;
    int unk34;
    u_int unk38;
    u_int unk3C;
    u_int ringBufIndex;
    int framesSinceLastRead;
} vs_main_disk_t;

typedef union {
    u_int all;
    struct {
        char low;
        char hi;
    } pad[2];
} vs_main_buttonsPressed_t;

// .data
extern int vs_main_titleScreenCount;
extern int vs_main_debugPause;
extern vs_action_t vs_main_actions[256];
extern material_modifiers_t vs_main_materialModifiers[8];
extern vs_main_statusEffectParams_t vs_main_statusEffectParams[];
/**
 * 512 pairs of zone and map IDs.
 */
extern u_char vs_main_locationZoneMapIds[];
extern vs_main_CdFile vs_main_zndFiles[256];
extern u_char vs_main_zndMusicMap[];
extern u_short vs_main_unkStrings[];
extern u_short vs_main_artsPointsRequirements[][4];
extern u_short vs_main_battleAbilitiesPointsRequirements[];

//.bss

// Avoids breaking .bss order
#ifndef VS_MAIN_INCLUDE
extern portInfo_t vs_main_portInfo[2];
extern u_char vs_main_actorExtraShp[256];
extern vs_main_battleTimer_t vs_main_battleTimer;
extern int vs_main_startState;
extern int vs_main_buttonsReleased;
extern void* D_80055C80[2];
extern vs_main_disk_t vs_main_disk;
extern vs_main_stickPos vs_main_stickPosBuf;
extern short D_8005DFD4;
extern short vs_main_screenWidth;
extern short D_8005DFD8;
extern u_short vs_main_screenHeight;
extern int vs_main_buttonRepeat;
extern char vs_main_padBuffer[2][34];
extern soundData_t vs_main_soundData;
extern void* D_8005E0C0[2];
extern int vs_main_nearClip;
extern DRAWENV vs_main_drawEnv[2];
extern DISPENV vs_main_dispEnv[2];
extern int vs_main_buttonsPreviousState;
extern int D_8005E1C4;
extern vs_main_buttonsPressed_t vs_main_buttonsPressed;
extern int D_8005E1D4;
extern u_int vs_main_frameDuration;
extern int vs_main_frameBuf;
extern int vs_main_saveGameClearData;
extern int vs_main_buttonsState;
extern MATRIX D_8005E218;
extern int D_8005E244;
extern int vs_main_projectionDistance;
extern int vs_gametime_tickspeed;
extern vs_main_scoredata_t vs_main_scoredata;
extern char vs_main_actionsLearned[32];
extern vs_main_mapStatus_t vs_main_mapStatus;
extern vs_main_settings_t vs_main_settings;
extern vs_main_artsStatus_t vs_main_artsStatus;
extern int vs_main_zoneEnemyCacheIndex;
extern vs_main_characterSnapshot_t vs_main_characterSnapshot;
extern vs_main_inventory_t vs_main_inventory;
extern _mpdRoomDoorSection_t vs_main_spawnPoint;
extern vs_Gametime_t vs_main_gametime;
extern vs_main_zoneEnemyCache_t vs_main_zoneEnemyCache[4];
extern vs_main_flags_t vs_main_stateFlags;
extern vs_main_inventoryIndices_t vs_main_inventoryIndices;
#endif

int vs_main_gametimeUpdate(int vsync);
void vs_main_jumpToBattle(void);
void vs_main_showEndingAndReturnToTitle(void);
int vs_main_getRand(int);
int vs_main_getRandSmoothed(int);
int vs_main_execTitle(void);
void vs_main_exec(void);
void vs_main_enableReset(int);
void vs_main_setCharacterRestorePending(void);
void vs_main_captureSaveState(void);
int vs_main_setVibrationBank(char* arg0, u_int arg1, int arg2);
int vs_main_stopVibration(u_int arg0, int arg1);
void vs_main_padDisconnectAll(void);
int vs_main_updatePadState(int, char[34]);
void vs_main_padConnect(int, char[34]);
void vs_main_setVibrateParams(void);
void vs_main_vibrationOnEffect(int);
int vs_main_processPadState(void);
void vs_main_freeHeapR(void*);
void vs_main_freeHeap(void*);
void* vs_main_allocHeapR(u_int);
void* vs_main_allocHeap(u_int);
vs_main_CdQueueSlot* vs_main_allocateCdQueueSlot(vs_main_CdFile const*);
void vs_main_freeCdQueueSlot(vs_main_CdQueueSlot*);
void vs_main_cdEnqueue(vs_main_CdQueueSlot* slot, void* vram);
void vs_main_cdEnqueuePriority(vs_main_CdQueueSlot* slot, void* vram);
int vs_main_loadMusicSlot(int id, int targetSlot);
int vs_main_clearMusicLoadQueue(void);
int vs_main_loadAndWaitMusicSlot(int id, int targetSlot);
void vs_main_loadAndWaitSoundSlot(int id);
void vs_main_playSfx(int arg0, long id, int arg2, int arg3);
void vs_main_playSfxDefault(int, int);
void vs_main_stopMusic(void);
int vs_main_freeMusic(int arg0);
void vs_main_resetSound(void);
void vs_main_pushMusicState(void);
int vs_main_getMusicPosition(void);
void vs_main_setMusicJumpThreshold(int);
int vs_main_stopMusicSlot(int);
int vs_main_queueMusicSlot(int);
int vs_main_playMusicSlotFadeIn(int, int, u_int);
int vs_main_playMusicSlot(int id, int arg1, int arg2);
int vs_main_getMusicSlotVolume(int);
int vs_main_fadeMusicTempo(int, int, int);
int vs_main_fadeMusicPitch(int, int, int);
int vs_main_getMusicSlotVolume2(int);
void vs_main_stopAllSfx(void);
void vs_main_panSfx(int arg0, int arg1, SVECTOR* vec);
int vs_main_computeSfxPan(int coords, int z);
void vs_main_fadeSfxVolume(int arg0, int arg1, int arg2, char arg3);
void vs_main_fadeSfxPitch(int arg0, int arg1, int arg2, char arg3);
void vs_main_fadeSfxPan(int, int, int, char);
int vs_main_setSfxSlot3Data(u_int);
int vs_main_clearSfxSlot3(void);
void vs_main_playBankSfx(int, u_int[], u_int, int, int);
void vs_main_playBankSfxDefault(int arg0, int* arg1, u_int arg2);
void vs_main_evictBankSfx(int arg0, int* arg1, int arg2);
void vs_main_fadeBankSfxVolume(int arg0, int* arg1, int arg2, int arg3, int arg4);
void vs_main_startCutsceneStreamDefault(int arg0);
void vs_main_setMonoSound(int);
int vs_main_setCutsceneStreamSlot3(u_int arg0);
int vs_main_clearCutsceneStreamSlot3(void);
// Parameters left undeclared due to misuse in unused func_8007B378
void vs_main_loadClutTransition(
    /*int duration, int slot, u_short* sourceClut, int clutOffset*/);
void vs_main_transformClutSlot(int, int, int, short, int, int);
void vs_main_fadeBgColors(int arg0, D_8005DC6C_t* arg1);
void vs_main_loadSoundFile(int);
void vs_main_transformBgColors(int, int, int, int, int);
void func_80047FC0(int, int, int, int, int, int);
void vs_main_updateBgColors(void);
void vs_main_updateClutSlots(void);
void func_800481C0(void);
void vs_main_bzero(void*, int);
void vs_main_memcpy(void* dest, void* src, u_int sz);
void vs_main_nop9(int, int);
void vs_main_nop10(int, int);
void vs_main_loadClut(u_short const* img, u_int slot, u_int colorOffset, u_int count);
void vs_main_loadBgColors(void);
void vs_main_commitClut(void);
void vs_main_setClutState(int arg0);
void vs_main_clutInit(void);
int vs_main_diskLoadFile(int sector, int bytes, void* vram);
void vs_main_resetPadAct(void);
int vs_main_streamXa(int sector, int cdVolume);
int vs_main_checkStreamXaEnd(void);
int vs_main_fadeMusicVolume(int id, int arg1, int arg2);
int vs_main_getCurrentMusicId(void);
void vs_main_evictSfx(int arg0, int arg1);
void vs_main_wait(void);
void vs_main_initHeap(vs_main_HeapHeader* node, u_int value);
void vs_main_resetGame(void);
int vs_main_processSoundQueue(void);
int vs_main_setCurrentSfx(int id);
int vs_main_freeSfx(u_int);
int vs_main_freeSfxQueueSlot(u_int slot);
int vs_main_clearMusicLoadSlot(u_int);
int vs_main_loadSfxSlot(int, u_int);
