#pragma once
#include "25AC.h"
#include "D_80061068_t.h"
#include "../BATTLE/BATTLE.PRG/func_8006B57C_t.h"
#include <sys/types.h>
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

enum skills_e { vs_main_skills_daggerArt1 = 184 };

typedef union {
    u_short u16[2];
    u_int s32;
} vs_hitParams_t;

enum skillTypes {
    skillTypeSpell = 1,
    skillTypeAbility,
    skillTypeBreakArt,
    skillTypeItem = 5,
    skillTypeBaseAttack,
    skillTypeTrap
};

typedef struct {
    char id;
    char unk1;
    char unk2_0 : 1;
    char type : 3;
    u_char unk2_4 : 4;
    char cost;
    char rangeX;
    char rangeY;
    char rangeZ;
    int shape : 3;
    int angle : 5;
    int aoe;
    char flags_0;
    u_int flags_7 : 7;
    u_int unlocked : 1;
    u_int flags_16 : 16;
    int unk10;
    struct {
        u_int effect : 7;
        u_int prerequisites : 6;
        u_int hitRate : 3;
        u_int damageCalculator : 6;
        u_int damageFactor : 5;
        u_int type : 2;
        u_int affinity : 3;
    } hitParams[2];
    char name[24];
} vs_skill_t;

typedef struct {
    int currentMusicId;
    u_int unk4;
    int unk8;
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
    u_char unk0_4 : 1;
    u_char abilityTimingDisplay : 1;
    u_char weaponStatChange : 1;
    u_char armorStatChange : 1;
    char cursorMemory;
    short unk2;
    u_int slotState;
    char information;
    char simpleMap;
    char monoSound;
    char vibrationOn;
    char mappedChainAbilities[4];
    char mappedDefenseAbilities[4];
    u_int key;
    u_short saveCount;
    u_short unk1A;
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
    u_int unk0 : 24;
    u_int unk24 : 7;
    u_int unk31 : 1;
} vs_trialScore_t;

typedef struct {
    int flags;
    u_short enemyKills[6];
    int unk10;
    u_short weaponAttacks[10];
    union {
        u_int value;
        vs_trialScore_t time;
    } bossTimeTrialScores[8][3];
    u_short maxChain;
    u_short unk8A;
    u_int unk8C;
    u_int completionTimeMinutes;
    u_int mapCompletion;
    u_int unk98;
    int unk9C[26];
    u_int streakScore;
    u_int enemyKillStreak;
    char unk10C;
    char unk10D;
    char weaponKillStreakBladeCategory;
    char weaponKillStreak;
    u_short chainStreak;
    u_short bossHealCount;
} vs_main_scoredata_t;

typedef struct {
    u_short unk0;
    u_short unk2;
    u_short types[4];
    u_short affinities[8];
} D_80060068_t2;

typedef struct {
    int unk0;
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
    int unk1C;
    char unk20[8];
    D_80060068_t2 hitLocations[6];
    int unk7C;
    int unk80;
    int unk84;
} D_80060068_t3;

typedef struct {
    D_80060068_t3 unk0;
    int unkDC[9];
} D_80060068_t;

typedef struct {
    char clearCount;
    char unk1;
    char unk2;
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
    char unkF[17];
    char unk20;
    char unk21[0x1F];
    char unk40;
    char unk41[0x5F];
    char unkA0;
    char unkA1;
    char unkA2;
    char unkA3;
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
    char unkB6;
    char unkB7;
    char unkB8;
    char unkB9;
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
    u_char unkC4;
    char unkC5;
    char unkC6;
    char unkC7;
    char unkC8;
    char unkC9;
    char unkCA;
    char unkCB;
    char unkCC;
    char unkCD;
    char unkCE;
    char unkCF;
    char unkD0;
    char unkD1;
    char unkD2[51];
    char doorEntered;
    char unk106[22];
    char puzzleMode;
    char puzzleModeDisabled;
    char unk11E[23];
    char mapPaling[32];
    char unk341;
    char savePointStates[48];
    char unk186[0x1B9];
    char unk33F[68];
    char unk383;
    char unk384;
    char unk385;
    char unk386;
    char unk387;
    char unk388[56];
    char unk3C0[64];
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
    char unk0;
    char unk1;
    char unk2;
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
    vs_battle_inventoryWeapon weapons[8];
    vs_battle_inventoryShield shields[8]; // 0x100
    vs_battle_inventoryBlade blades[16]; // 0x280
    vs_battle_inventoryGrip grips[16]; // 0x540
    vs_battle_inventoryArmor armor[16]; // 0x640
    vs_battle_inventoryGem gems[48]; // 0x8C0
    vs_battle_inventoryMisc items[64]; // 0xE00
} vs_battle_inventory_t;

typedef struct {
    char unk0;
    char unk1;
    u_short unk2;
    u_int unk4;
    char unk8[8][0x28];
} D_80061078_t;

typedef struct {
    char unk0;
    char unk1;
    u_short unk2;
    signed char unk4;
    signed char unk5;
    signed char unk6;
    signed char unk7;
} D_80050468_t;

extern portInfo_t _portInfo[2];
extern soundData_t vs_main_soundData;
extern vs_skill_t vs_main_skills[256];
extern int D_8004A52C;
extern char D_8004EDDC[8][30];
extern int vs_main_frameBuf;
extern DRAWENV vs_main_drawEnv[2];
extern DISPENV vs_main_dispEnv[2];
extern int vs_main_titleScreenCount;
extern vs_main_CdFile vs_main_zndFiles[256];
extern char vs_main_locationZoneMapIds[];
extern int D_8004EECC[][4];
extern char D_8004FCCC[];
extern char D_8004FDD0[];
extern u_short vs_main_artsPointsRequirements[][4];
extern u_short vs_main_battleAbilitiesPointsRequirements[];
extern D_80050468_t D_80050468;
extern void* D_80055C80[];
extern short D_8005DFD4;
extern short D_8005DFD6;
extern short D_8005DFD8;
extern short D_8005DFDA;
extern u_int D_8005E040;
extern void* D_8005E0C0[];
extern int D_8005E0C8;
extern int vs_main_projectionDistance;
extern int vs_gametime_tickspeed;
extern char vs_main_padBuffer[2][34];
extern union {
    u_int all;
    struct {
        char low;
        char hi;
    } pad[2];
} vs_main_buttonsPressed;
extern int vs_main_buttonsPreviousState;
extern int vs_main_buttonRepeat;
extern int vs_main_buttonsReleased;
extern int vs_main_buttonsState;
extern int vs_main_saveGameClearData;

extern vs_main_scoredata_t vs_main_scoredata;
extern char vs_main_skillsLearned[32];
extern vs_main_mapStatus_t vs_main_mapStatus;
extern vs_main_settings_t vs_main_settings;
extern char vs_main_soundMono;
extern char vs_main_vibrationEnabled;
extern int vs_main_startState;
extern u_short D_80060022;
extern vs_main_artsStatus_t vs_main_artsStatus;
extern int D_80060064;
extern D_80060068_t D_80060068;
extern vs_battle_inventory_t vs_battle_inventory;
extern D_80061068_t D_80061068;
extern vs_Gametime_t vs_main_gametime;
extern D_80061078_t D_80061078[4];
extern vs_main_flags_t vs_main_stateFlags;
extern D_800619D8_t D_800619D8;
extern vs_main_stickPos vs_main_stickPosBuf;

int vs_main_gametimeUpdate(int vsync);
void vs_main_jumpToBattle(void);
void vs_main_showEndingAndReturnToTitle(void);
int vs_main_getRand(int);
int vs_main_getRandSmoothed(int);
int vs_main_execTitle(void);
void vs_main_exec(void);
void vs_main_enableReset(int);
void func_80041C68(MATRIX*, MATRIX*);
void func_80042CA0(void);
void func_80042CB0(void);
void vs_main_padDisconnectAll(void);
int vs_main_updatePadState(int, char[34]);
void vs_main_padConnect(int, char[34]);
void vs_main_setVibrateParams(void);
void func_800438C8(int);
int vs_main_processPadState(void);
void vs_main_freeHeapR(void*);
void vs_main_freeHeap(void*);
void* vs_main_allocHeapR(u_int);
void* vs_main_allocHeap(u_int);
vs_main_CdQueueSlot* vs_main_allocateCdQueueSlot(vs_main_CdFile const*);
void vs_main_freeCdQueueSlot(vs_main_CdQueueSlot*);
void vs_main_cdEnqueue(vs_main_CdQueueSlot* slot, void* vram);
void vs_main_cdEnqueueUrgent(vs_main_CdQueueSlot* slot, void* vram);
int vs_main_loadMusicSlot(int id, int targetSlot);
int vs_main_clearMusicLoadQueue(void);
int vs_main_loadAndWaitMusicSlot(int id, int targetSlot);
void vs_main_loadAndWaitSoundSlot(int id);
void vs_main_playSfxDefault(int, int);
void vs_main_stopMusic(void);
int vs_main_freeMusic(int arg0);
void vs_main_resetSound(void);
int func_80045000(int id, int arg1, int arg2);
void vs_main_panSfx(int arg0, int arg1, SVECTOR* vec);
void func_80045BFC(int arg0, int arg1, int arg2, int arg3);
void func_80045C74(int arg0, int arg1, int arg2, int arg3);
void func_800461CC(int, u_int[], u_int, int, int);
void func_800462E8(int arg0, int* arg1, u_int arg2);
void func_8004644C(int arg0, int* arg1, int arg2);
void func_80046494(int arg0, int* arg1, int arg2, int arg3, int arg4);
void vs_main_setMonoSound(int);
// BUG: Function seems to be called with 3 and 4 parameters
// but always reads 4th
void func_80046C80();
void func_80047280(int, int, int, short, int, int);
void func_800472D0(int arg0, D_8005DC6C_t* arg1);
void vs_main_loadSoundFile(int);
void func_800478E0(int, int, int, int, int);
void func_80047FC0(int, int, int, int, int, int);
void vs_main_bzero(void*, int);
void vs_main_memcpy(void* dest, void* src, u_int sz);
void vs_main_nop9(int, int);
void vs_main_nop10(int, int);
void func_80048A64(u_short const* img, u_int y, u_int x, u_int w);
void func_80048F8C(void);
void func_80048FEC(short arg0);
void func_80048FF8(void);
int vs_main_diskLoadFile(int sector, int bytes, void* vram);
void vs_main_resetPadAct(void);
int vs_main_streamXa(int sector, int byteCount);
int vs_main_checkStreamXaEnd(void);
int func_8004552C(int id, int arg1, int arg2);
int func_800450E4(void);
void func_80045D64(int arg0, int arg1);
void vs_main_wait(void);
void vs_main_initHeap(vs_main_HeapHeader* node, u_int value);
void vs_main_resetGame(void);
