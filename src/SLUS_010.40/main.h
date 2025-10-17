#pragma once
#include "25AC.h"
#include "D_80061068_t.h"
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>

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

typedef struct {
    char id;
    char effect;
    int unk2_0 : 1;
    int type : 3;
    int target : 4;
    char cost;
    char rangeX;
    char rangeY;
    char rangeZ;
    int shape : 3;
    int angle : 5;
    int aoe;
    u_int flags; // 0xF = artUnlocked
    int unk10;
    struct {
        int effect : 7;
        int hitrateFlags : 6;
        int hitrateAdj : 3;
        int damage : 6;
        int mult : 5;
        int type : 2;
        int affinity : 3;
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
    char timingWeaponArmor;
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
    int unk0[10];
    int unk28[8][3];
    int unk88[35];
} D_8005FEA0_t;

typedef struct {
    u_short unk0;
    u_short unk2;
    u_short unk4[4];
    u_short unkC[8];
} D_80060068_t2;

typedef struct {
    struct {
        int unk0;
        short currentHP;
        short maxHP;
        short currentMP;
        short maxMP;
        short unkC;
        short unkE;
        short unk10;
        short unk12;
        short unk14;
        short unk16;
        short unk18;
        short flags;
        int unk1C;
        char unk20[8];
        D_80060068_t2 unk28[6];
        int unk7C;
        int unk80;
        int unk84;
    } unk0;
    int unkDC[9];
} D_80060068_t;

typedef struct {
    int unk0[28];
    int unk70[16];
} D_800619D8_t;

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
    char unkF[0x95];
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
    char unkB6[0x4F];
    char unk105;
    char unk106[0x16];
    char puzzleMode;
    char puzzleModeDisabled;
    char unk11E[0x38];
    char savePointStates[48];
    char unk186[0x2BA];
} vs_main_flags_t;

typedef struct {
    char artsLearned[12];
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
    char id;
    char unk1;
    char wepId;
    char category;
    u_short maxDp;
    u_short maxPp;
    u_short currentDp;
    u_short currentPp;
    char gemSlots;
    char strength;
    char intelligence;
    char agility;
    char types[4];
    char classes[8];
    char affinities[8];
    u_short material;
} func_8006B7BC_t;

extern soundData_t vs_main_soundData;
extern vs_skill_t vs_main_skills[256];
extern char D_8004EDDC[8][30];
extern int vs_main_frameBuf;
extern DRAWENV vs_main_drawEnv[2];
extern DISPENV vs_main_dispEnv[2];
extern int vs_main_titleScreenCount;
extern int D_8004A52C;
extern vs_main_CdFile vs_main_zndFiles[256];
extern char D_8004FCCC[];
extern u_short vs_main_artsPointsRequirements[][4];
extern u_short vs_main_battleAbilitiesPointsRequirements[];
extern u_short D_8005046A;
extern u_int D_80055C80[];
extern void* D_8005E0C0[];
extern int D_8005E0C8;
extern int D_8005E248;
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

extern D_8005FEA0_t D_8005FEA0;
extern char vs_main_skillsLearned[32];
extern char D_8005FFD8[0x48];
extern vs_main_settings_t vs_main_settings;
extern char vs_main_soundMono;
extern char vs_main_vibrationEnabled;
extern u_short D_80060022;
extern vs_main_artsStatus_t vs_main_artsStatus;
extern int D_80060064;
extern D_80060068_t D_80060068;
extern int D_80060148[][8];
extern int D_80060238[][12];
extern int D_80060780[][10];
extern char D_80060168[15][256];
extern D_80061068_t D_80061068;
extern vs_Gametime_t vs_main_gametime;
extern char D_80061078[0x520];
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
void vs_main_playSfxDefault(int, int);
void vs_main_stopMusic(void);
int vs_main_freeMusic(int arg0);
void func_800461CC(int, u_int[], u_int, int, int);
void vs_main_setMonoSound(int);
void func_80046C80(int, int, u_short*, int);
void func_800472D0(int arg0, D_8005DC6C_t* arg1);
void vs_main_loadSoundFile(int);
void func_800478E0(int, int, int, int, int);
void vs_main_bzero(void*, int);
void vs_main_memcpy(void* dest, void* src, u_int sz);
void vs_main_nop9(int, int);
void func_80048A64(u_short* img, u_int y, u_int x, u_int w);
void func_80048F8C(void);
int vs_main_diskLoadFile(int sector, int bytes, void* vram);
void vs_main_resetPadAct(void);
int vs_main_streamXa(int sector, int byteCount);
int vs_main_checkStreamXaEnd(void);
int func_8004552C(int id, int arg1, int arg2);
int func_800450E4(void);
void vs_main_wait(void);
void vs_main_initHeap(vs_main_HeapHeader* node, u_int value);
void vs_main_resetGame(void);
