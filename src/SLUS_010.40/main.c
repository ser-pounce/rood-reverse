#include "main.h"
#include "common.h"
#include "overlay.h"
#include "../TITLE/TITLE.PRG/22C.h"
#include "../BATTLE/BATTLE.PRG/battle.h"
#include "lbas.h"
#include <libapi.h>
#include <libds.h>
#include <libetc.h>
#include <libpad.h>
#include <libsnd.h>
#include <libspu.h>
#include <libgpu.h>
#include <rand.h>

typedef struct vs_main_HeapHeader {
    struct vs_main_HeapHeader* prev;
    struct vs_main_HeapHeader* next;
    u_int blockSz;
    int unkC;
} vs_main_HeapHeader;

typedef struct {
    u_char mode;
    u_char exId;
    u_char states;
    u_char rStickX;
    u_char rStickY;
    u_char lStickX;
    u_char lStickY;
    u_char lock;
    u_char actData[2];
    u_char connected;
} PortInfo;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
} LoadImage_t;

typedef struct {
    int unk0[2];
    u_short unk8;
    u_short unkA;
    u_char* unkC;
    int unk10[10];
} D_80050118_t;

typedef struct {
    int offset;
    u_int unk4;
    int unk8;
    union {
        struct {
            short unkC;
            u_char unkE;
            u_char unkF[1];
        } unkC_s;
        u_int unkC_i;
    } unkC_u;
    u_char unk10[2];
    u_int unk14[4];
    void* unk24[4];
    vs_main_CdQueueSlot* unk34[4];
    u_int unk44;
    u_char unk48[4];
    void* unk4C[3];
    vs_main_CdQueueSlot* unk58[3];
    void* unk64[3];
    int* unk70[3];
    int fileId;
    void* unk80;
    vs_main_CdQueueSlot* unk84;
} D_8005E038_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
} D_8005DC6C_t;

typedef struct {
    u_char unk0[6];
    short unk6[5];
    int unk10[6];
    D_8005DC6C_t unk28;
} D_8005DC80_t;

typedef struct {
    u_short unk0;
    u_short unk2;
    u_char unk4;
    u_char unk5;
    u_char unk6[5];
    char unkB[3];
    struct ColorInfo {
        u_char r;
        u_char g;
        u_char b;
        u_char a;
        u_char rindex;
        u_char gindex;
        u_char bindex;
    } unkE[256];
    u_short unk70E[254];
} D_80055D58_t2;

typedef struct {
    D_80055D58_t2 unk0[14];
    u_char unk7E8C[10];
    short unk7E96[3];
    int unk7E9C[5][6];
    D_8005DC6C_t unk7F14[5];
    D_8005DC80_t unk7F28[17];
} D_80055D58_t;

enum DiskState {

    diskIdle = 0,
    diskSeekReady = 1,
    diskReadReady = 2,
    diskReadError = 4,
    diskReadInit = 5,
    diskCommandFailed = 8
};

typedef struct {
    u_char state;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    u_int unk4;
    u_int sectorCount;
    int cdSector;
    int byteCount;
    void* vram;
    DslFILTER pcm;
    DslLOC cdLoc;
    int commandId;
    int unk24;
    int unk28;
    u_int unk2C;
    u_int sectorBufIndex;
    int unk34;
    u_int unk38;
    u_int unk3C;
    u_int unk40;
    int unk44;
} vs_main_disk_t;

typedef union {
    short s[0];
    int i;
} u_1632;

typedef struct {
    u_short unk0;
    u_short unk2;
    u_short unk4[4];
    u_short unkC[8];
} D_80060068_t2;

typedef struct {
    int unk0;
    short unk4[12];
    int unk1C;
    u_char unk20[8];
    D_80060068_t2 unk28[6];
    int unk7C[24];
} D_80060068_t;

typedef struct D_80061068_t {
    u_short unk0[6];
} D_80061068_t;

typedef struct {
    int lStickX;
    int lStickY;
    int rStickX;
    int rStickY;
} vs_main_stickPos;

typedef struct {
    char f;
    char s;
    char m;
    char h;
} Gametime_t;

void __main();
static void _sysInit();
static void _sysReinit();
static void _wait();
static void _padForceMode();
static void _padResetDefaults(int, u_char[34]);
static void _padConnect(int, u_char[34]);
static void _padSetActData(int arg0, int arg1, int arg2);
static int vs_main_diskGetState();
void func_80042CB0();
static void func_80043668();
static void _initCdQueue();
static void _diskReset();
static void _populateQueueSlot(vs_main_CdQueueSlot*, void*);
static void func_80044C74();
static int func_80045440(int arg0);
static void func_800455F4();
void func_80045754(int, int, int, int);
static void func_800461CC(int, u_int[], u_int, int, int);
static int func_800464FC(int, int, int);
static void func_80046678(int);
static void func_80046770(int);
static int func_800467A0();
static void _loadMenuSound();
void func_80046B3C(int, int, u_short*);
void func_80047910(int, int, D_8005DC6C_t*);
static void _asmNop();
static void nop10(int, int);
void func_8006A5C0();
static void _initRand();
static void vs_main_initHeap(vs_main_HeapHeader* node, u_int value);

typedef struct {
    u_char wLo;
    u_char wHi;
    u_char hLo;
    u_char hHi;
} ImgHeader;

extern ImgHeader _nowLoading_header;
extern u_long _nowLoading_data[];
extern u_char D_8004A504[24];
extern u_char _actParams[20];
extern int _soundLBAs[100];
extern int _musicLBAs[200];
extern int _seLBAs[100];
extern off_t _soundFileSizes[100];
extern off_t _musicFileSizes[200];
extern off_t _seFileSizes[100];
extern u_char _soundFileMap[200];
extern char _animOffset16[63][16];
extern char _animOffset8[63][8];
extern char _animOffset4[63][4];
extern char _animOffset2[63][2];

#define RANDARRSZ 97
extern int randArr[RANDARRSZ];
extern vs_main_HeapHeader* D_80050110;
extern D_80050118_t D_80050118[2];
extern PortInfo vs_main_portInfo[2];
extern vs_main_HeapHeader heapA;
extern vs_main_HeapHeader heapB;
extern int randIndex;
extern DslLOC cdReadLoc;
extern int D_800501CC;
extern int D_800501D0;
extern int D_800501D4;
extern int D_800501D8;
extern vs_main_CdQueueSlot vs_main_cdQueue[32];
extern u_1632 D_80050460;
extern int vs_main_startState;
extern int D_80050478[];
extern int sp2;
extern int _resetEnabled;
extern u_int D_80055C90[];
extern vs_main_disk_t vs_main_disk;
extern u_char vs_main_dsControlBuf[11];
extern D_80055D58_t D_80055D58;
extern int sp;
extern u_char _padBuffer[2][34];
extern int D_8005DBF4[5][6];
extern D_8005E038_t D_8005E038;
extern int D_8005E03C;
extern void* D_8005E08C;
extern int D_8005E0BC;
extern u_int _frameDuration;
extern int D_8005E214;
extern int D_8005E240;
extern int vs_gametime_tickspeed;
extern u_short loadImageSource[][256];
extern int D_8005FE70;
extern int D_8005FE74;
extern int D_8005FE78;
extern int D_8005FE7C;
extern int D_8005FE80;
extern int D_8005FE84;
extern u_char vs_main_skillsLearned[];
extern D_80060068_t D_80060068;
extern u_char D_8006002B;
extern D_80061068_t D_80061068;
extern Gametime_t vs_gametime;
extern MATRIX D_1F800014_mat;
extern int vs_main_buttonsReleased;
extern vs_main_stickPos vs_main_stickPosBuf;
extern int D_8005DFDC;
extern u_int vs_main_buttonsPreviousState;
extern int vs_main_buttonsPressed;
extern u_int vs_main_buttonsState;
extern u_char D_80060020[];

static void vs_main_loadBattlePrg()
{
    vs_main_CdFile cdFile;
    vs_main_CdQueueSlot* slot;

    cdFile.lba = VS_BATTLE_PRG_LBA;
    cdFile.size = VS_BATTLE_PRG_SIZE;
    slot = vs_main_getQueueSlot(&cdFile);
    _populateQueueSlot(slot, vs_overlay_slots[0]);

    while (slot->unk0[0] != 4) {
        vs_gametime_update(0);
    }

    func_80044B80(slot);

    cdFile.lba = VS_INITBTL_PRG_LBA;
    cdFile.size = VS_INITBTL_PRG_SIZE;
    slot = vs_main_getQueueSlot(&cdFile);
    _populateQueueSlot(slot, vs_overlay_slots[1]);

    while (slot->unk0[0] != 4) {
        vs_gametime_update(0);
    }

    func_80044B80(slot);
    _wait();
}

static void vs_main_loadTitlePrg()
{
    vs_main_CdFile cdFile;
    vs_main_CdQueueSlot* temp_v0;

    cdFile.lba = VS_TITLE_PRG_LBA;
    cdFile.size = VS_TITLE_PRG_SIZE;

    temp_v0 = vs_main_getQueueSlot(&cdFile);
    _populateQueueSlot(temp_v0, vs_overlay_slots[0]);

    while (temp_v0->unk0[0] != 4) {
        vs_gametime_update(0);
    }

    func_80044B80(temp_v0);
    _wait();
}

static void vs_main_loadEndingPrg()
{
    vs_main_CdFile cdFile;
    vs_main_CdQueueSlot* temp_v0;

    cdFile.lba = VS_ENDING_PRG_LBA;
    cdFile.size = VS_ENDING_PRG_SIZE;

    temp_v0 = vs_main_getQueueSlot(&cdFile);
    _populateQueueSlot(temp_v0, vs_overlay_slots[0]);

    while (temp_v0->unk0[0] != 4) {
        vs_gametime_update(0);
    }

    func_80044B80(temp_v0);
    _wait();
}

static void vs_main_initScreen(int w, int h, int arg2 __attribute__((unused)),
    __attribute__((unused)) int arg3, __attribute__((unused)) int arg4,
    __attribute__((unused)) int arg5)
{
    SetDefDispEnv(vs_main_dispEnv, 0, 0, w, h - 0x10);
    setRECT(&vs_main_dispEnv[0].screen, 0, 8, 0x100, 0xE0);
    PutDispEnv(vs_main_dispEnv);
}

#define IMG_W(header) (header.wLo + (header.wHi << 8))
#define IMG_H(header) (header.hLo + (header.hHi << 8))

static void _displayLoadingScreen()
{
    RECT rect;

    vs_main_initScreen(0x140, 0xF0, D_8005E248, 0, 0, 0);
    setRECT(&rect, 0, 0, 1024, 512);
    ClearImage2(&rect, 0, 0, 0);
    DrawSync(0);
    VSync(2);
    setRECT(&rect, (320 - IMG_W(_nowLoading_header)) / 2,
        (224 - IMG_H(_nowLoading_header)) / 2, IMG_W(_nowLoading_header),
        IMG_H(_nowLoading_header));
    LoadImage(&rect, (u_long*)&_nowLoading_header + 1);
    setRECT(&rect, ((320 - IMG_W(_nowLoading_header)) / 2) + 320,
        (224 - IMG_H(_nowLoading_header)) / 2, IMG_W(_nowLoading_header),
        IMG_H(_nowLoading_header));
    LoadImage(&rect, (u_long*)&_nowLoading_header + 1);
    DrawSync(0);
    SetDispMask(1);
}

static void vs_main_bufferLoadingScreen()
{
    RECT rect;

    if (vs_main_frameBuf != 0) {
        setRECT(&rect, (320 - IMG_W(_nowLoading_header)) / 2,
            (224 - IMG_H(_nowLoading_header)) / 2, IMG_W(_nowLoading_header),
            IMG_H(_nowLoading_header));
    } else {
        setRECT(&rect, (320 - IMG_W(_nowLoading_header)) / 2 + 320,
            (224 - IMG_H(_nowLoading_header)) / 2, IMG_W(_nowLoading_header),
            IMG_H(_nowLoading_header));
    }
    LoadImage(&rect, _nowLoading_data);
    DrawSync(0);
}

void vs_main_resetGame()
{
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    while (DsControlB(DslPause, NULL, NULL) == 0)
        ;
    DsFlush();
    _padSetActData(0, 0, 0);
    _padSetActData(0, 1, 0);
    _padConnect(0, _padBuffer[0]);
    _padConnect(0x10, _padBuffer[1]);
    vs_sound_Shutdown();
    SpuQuit();
    ResetGraph(3);
    VSync(0xA);
    vs_overlay_jumpToTitle(&sp2);
}

void vs_main_jumpToBattle()
{
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    _padSetActData(0, 0, 0);
    _padSetActData(0, 1, 0);
    _padConnect(0, _padBuffer[0]);
    _padConnect(0x10, _padBuffer[1]);
    ResetGraph(3);
    func_80012B78();
    func_80012B98();
    func_80012024();
    func_80012EBC();
    _displayLoadingScreen();
    vs_main_loadBattlePrg();
    vs_main_startState = 1;
    vs_overlay_jumpToBattle(&sp);
}

void vs_main_jumpToTitle()
{
    D_8005E240 = 0;
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    _padSetActData(0, 0, 0);
    _padSetActData(0, 1, 0);
    _padConnect(0, _padBuffer[0]);
    _padConnect(0x10, _padBuffer[1]);
    ResetGraph(3);
    func_80012B78();
    func_80012B98();
    func_80042CB0();
    vs_main_loadEndingPrg();
    func_8006A5C0();
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    _padSetActData(0, 0, 0);
    _padSetActData(0, 1, 0);
    _padConnect(0, _padBuffer[0]);
    _padConnect(0x10, _padBuffer[1]);
    vs_sound_Shutdown();
    SpuQuit();
    ResetGraph(3);
    D_8005E214 = 1;
    vs_overlay_jumpToTitle(&sp2);
}

int vs_gametime_update(int arg0)
{
    int vs = VSync(arg0);
    if (arg0 != 1) {
        _asmNop();
    }

    func_80044C74();

    if (vs_gametime.h >= 100) {
        return vs;
    }

    vs_gametime.f += vs_gametime_tickspeed;

    if (vs_gametime.f < 60) {
        return vs;
    }

    vs_gametime.f = 0;

    if (++vs_gametime.s < 60) {
        return vs;
    }

    vs_gametime.s = 0;

    if (++vs_gametime.m < 60) {
        return vs;
    }

    vs_gametime.m = 0;

    if (++vs_gametime.h >= 100) {
        vs_gametime.h = 100;
    }
    return vs;
}

static void gpuSyncVoidCallback() { }

static void vSyncVoidCallback() { }

static void nop0() { }

static void nop1() { }

static void _nop2() { }

static void _nop3() { }

static void _initRand()
{
    int i;

    srand(1);

    for (i = 0; i < RANDARRSZ; ++i) {
        randArr[i] = rand();
    }
    randIndex = RANDARRSZ - 1;
}

int vs_main_getRand(int arg0)
{
    int temp_s0;
    int var_a0;
    int var_v0;

    var_v0 = randArr[randIndex] * RANDARRSZ;

    if (var_v0 < 0) {
        var_v0 += 0x7FFF;
    }

    randIndex = var_v0 >> 0xF;

    temp_s0 = 0x7FFF - randArr[randIndex];
    randArr[randIndex] = rand();

    var_a0 = temp_s0 * arg0;

    if (var_a0 < 0) {
        var_a0 += 0x7FFF;
    }

    return var_a0 >> 0xF;
}

int vs_main_getRands(int arg0)
{
    return (vs_main_getRand(arg0) + vs_main_getRand(arg0) + vs_main_getRand(arg0)
               + vs_main_getRand(arg0) + vs_main_getRand(arg0) + vs_main_getRand(arg0)
               + vs_main_getRand(arg0) + vs_main_getRand(arg0) + vs_main_getRand(arg0)
               + vs_main_getRand(arg0) + vs_main_getRand(arg0) + vs_main_getRand(arg0))
        / 12;
}

static void _sysInit()
{
    SetVideoMode(MODE_NTSC);
    SetDispMask(0);
    ResetCallback();
    ResetGraph(0);
    SetGraphDebug(0);
    InitCARD(0);
    StartCARD();
    _bu_init();
    PadInitDirect(_padBuffer[0], _padBuffer[1]);
    _padResetDefaults(0, _padBuffer[0]);
    _padResetDefaults(0x10, _padBuffer[1]);
    PadStartCom();
    _padForceMode();
    func_80043668();
    SsUtReverbOff();
    DsInit();
    _initRand();
    _resetEnabled = 1;
    D_8005E214 = 0;
}

static void _sysReinit()
{
    RECT rects[3];
    int i;

    rects[1] = (RECT) { 819, 819, 819, 0 };
    rects[2] = (RECT) { 0, 0, 1024, 512 };
    ResetCallback();
    ResetGraph(1);
    SetGraphDebug(0);
    ClearImage(&rects[2], 0, 0, 0);
    DrawSync(0);
    _displayLoadingScreen();
    SsUtReverbOn();
    InitGeom();
    DrawSyncCallback(gpuSyncVoidCallback);
    VSyncCallback(vSyncVoidCallback);
    vs_main_initHeap((vs_main_HeapHeader*)0x8010C000, 0xF2000);
    _initCdQueue();
    _diskReset();
    _loadMenuSound();
    func_80043668();
    D_8005E240 = 0;
    _padForceMode();

    for (i = 31; i >= 0; --i) {
        D_80055C90[i] = 0;
    }
    vs_gametime.h = 0;
    vs_gametime.m = 0;
    vs_gametime.s = 0;
    vs_gametime.f = 0;
    D_80060068.unk0 = 0;
}

int vs_main_execTitle()
{
    vs_overlay_getSp(&sp);
    _sysReinit();
    vs_main_loadTitlePrg();
    vs_main_startState = vs_title_exec();
    D_8005E214 = 0;
    _displayLoadingScreen();
    vs_main_loadBattlePrg();
    vs_overlay_getSp(&sp);
    D_8005E240 = 1;
    vs_battle_exec();
    SetDispMask(0);
    func_800455F4();
    return 0;
}

void vs_main_exec()
{
    __main();
    _sysInit();
    vs_overlay_getSp(&sp2);
    vs_main_execTitle();
}

static void _wait() { vs_overlay_wait(); }

void vs_main_enableReset(int arg0) { _resetEnabled = arg0; }

void func_80042CA0() { D_80060068.unk0 = 1; }

void func_80042CB0()
{
    unsigned char sp10[16];
    int var_a1;
    int var_a3;
    int var_s1;
    int var_t3;
    int new_var;
    int var_t4;
    char skillsLearned;
    D_800F19FC_t2* temp_t0;
    D_80060068_t* temp_t5;
    int v0;
    int v0_2;
    int v1;
    int v1_2;

    D_80061068 = D_800F1AB0;
    func_800A1108(0, sp10);

    v0 = (sp10[0] & 0x1F) << 8;
    v1 = (sp10[2] & 0x1F) << 0xA;
    D_80061068.unk0[2] = (D_80061068.unk0[2] & 0xE0FF) | v0;
    D_80061068.unk0[3] = (D_80061068.unk0[3] & 0x83FF) | v1;
    v1_2 = sp10[1] << 0xD;
    v0_2 = (sp10[3] >> 6) << 0xD;
    D_80061068.unk0[1] = ((D_80061068.unk0[1] & 0x1FFF) | v1_2);
    new_var = D_800F18E8 & 0x3FF;
    D_80061068.unk0[2] = ((D_80061068.unk0[2] & 0x9FFF) | v0_2);
    D_80061068.unk0[3] = ((D_80061068.unk0[3] & 0xFC00) | new_var);
    for (var_s1 = 0; var_s1 < 32; ++var_s1) {
        for (skillsLearned = 0, var_a3 = 0; var_a3 < 8; ++var_a3) {
            u_int new_var2 = D_8004B9DC[var_s1 * 8 + var_a3].flags;
            skillsLearned = (*(int*)&skillsLearned * 2) | ((new_var2 >> 0xF) & 1);
        }
        vs_main_skillsLearned[var_s1] = skillsLearned;
    }
    temp_t0 = D_800F19FC->unk38;
    temp_t5 = &D_80060068;
    temp_t5->unk4[0] = temp_t0->unk0[12];
    temp_t5->unk4[1] = temp_t0->unk0[13];
    temp_t5->unk4[2] = temp_t0->unk0[14];
    temp_t5->unk4[3] = temp_t0->unk0[15];
    temp_t5->unk4[4] = temp_t0->unk0[17];
    temp_t5->unk4[5] = temp_t0->unk0[18];
    temp_t5->unk4[6] = temp_t0->unk0[19];
    temp_t5->unk4[7] = temp_t0->unk0[20];
    temp_t5->unk4[8] = temp_t0->unk0[21];
    temp_t5->unk4[9] = temp_t0->unk0[22];
    temp_t5->unk4[10] = temp_t0->unk0[16];
    temp_t5->unk4[11] = temp_t0->unk954;
    temp_t5->unk1C = temp_t0->unk948;

    for (var_a3 = 0; var_a3 < 8; ++var_a3) {
        temp_t5->unk20[var_a3] = temp_t0->unk94C[var_a3];
    }

    var_t4 = 0;
    var_t3 = 0;

    for (var_a3 = 0; var_a3 < 6; ++var_a3) {
        temp_t5->unk28[var_a3].unk0 = temp_t0->unk398[var_a3].unk0;
        temp_t5->unk28[var_a3].unk2 = temp_t0->unk398[var_a3].unk2;

        for (var_a1 = 0; var_a1 < 4; ++var_a1) {
            temp_t5->unk28[var_a3].unk4[var_a1] = temp_t0->unk398[var_a3].unk8[var_a1];
        }

        for (var_a1 = 0; var_a1 < 8; ++var_a1) {
            temp_t5->unk28[var_a3].unkC[var_a1] = temp_t0->unk398[var_a3].unk10[var_a1];
        }
    }

    temp_t5->unk7C[0] = D_800F19FC->unk0[8];
    temp_t5->unk7C[1] = D_800F19D0[5];
    temp_t5->unk7C[2] = D_800F19D0[8];

    for (var_s1 = 0; var_s1 < 16; ++var_s1) {
        func_80069FC4(var_s1, 0);
    }
    func_8008AB68();
}

void vs_main_padDisconnectAll()
{
    vs_main_portInfo[0].connected = 0;
    vs_main_portInfo[1].connected = 0;
}

static void _padForceMode()
{
    vs_main_padDisconnectAll();
    if (PadInfoMode(0, InfoModeCurExID, 0) != 0) {
        PadSetMainMode(0, 1, 2);
    }
}

static void _padResetDefaults(int portID, u_char padBuf[34] __attribute__((unused)))
{
    PortInfo* port = &vs_main_portInfo[portID >> 4];
    port->exId = PadInfoMode(portID, InfoModeCurExID, 0);

    if (port->exId) {
        port->actData[0] = 0;
        port->actData[1] = 0;
        port->lock = 2;
        PadSetMainMode(portID, PadInfoMode(portID, InfoModeCurExOffs, 0), port->lock);
    } else {
        port->actData[0] = 0x40;
        port->actData[1] = 0;
    }
    PadSetAct(portID, port->actData, sizeof(port->actData));
    PadSetActAlign(portID, _actParams);
}

static int _updatePadState(int portID, u_char padBuf[34])
{
    PortInfo* port;
    u_char mode;
    int btnStates;

    if (padBuf[0] != 0) {
        port = &vs_main_portInfo[portID >> 4];
        port->lStickY = 128;
        port->lStickX = 128;
        port->rStickY = 128;
        port->rStickX = 128;
        return 0;
    }
    port = &vs_main_portInfo[portID >> 4];
    mode = PadInfoMode(portID, InfoModeCurID, 0);
    port->mode = mode;
    switch (mode) {
    case 1:
    case 2:
    case 3:
    case 6:
        btnStates = 0;
        break;
    default:
        btnStates = ~((padBuf[2] << 8) | padBuf[3]);
        break;
    }

    port->mode = PadInfoMode(portID, InfoModeCurID, 0);
    if ((port->mode == 5) || (port->mode == 7)) {
        port->rStickX = padBuf[6];
        port->rStickY = padBuf[7];
        port->lStickX = padBuf[4];
        port->lStickY = padBuf[5];
    } else {
        port->lStickY = 128;
        port->lStickX = 128;
        port->rStickY = 128;
        port->rStickX = 128;
    }
    port->states = btnStates;
    return btnStates;
}

static void _padConnect(int portID, u_char padBuf[34])
{
    int dummy[5] __attribute__((unused));

    PortInfo* port = &vs_main_portInfo[portID >> 4];
    int state = PadGetState(portID);

    if (state == PadStateFindPad) {
        port->connected = 0;
    }
    if (port->connected == 0) {
        PadSetAct(portID, port->actData, sizeof(port->actData));
        if ((state == PadStateFindCTP1)
            || ((state == PadStateStable) && (PadSetActAlign(portID, _actParams) != 0))) {
            _padResetDefaults(portID, padBuf);
            port->connected = 1;
        }
    }
}

static void _padSetActData(int port, int pos, int val)
{
    if (pos != 0) {
        vs_main_portInfo[port].actData[pos] = val;
    } else if (vs_main_portInfo[port].exId) {
        vs_main_portInfo[port].actData[0] = val;
    } else {
        vs_main_portInfo[port].actData[0] = 0x40;
    }
}

static u_char _padGetActData(int port, int pos)
{
    return vs_main_portInfo[port].actData[pos];
}

static int func_800433B4(u_char* arg0, u_int arg1, short arg2)
{
    int i;
    int ret = 0;

    if (arg1 == 0xFF) {
        for (i = 0; i < 2; ++i) {
            if (D_80050118[i].unk8 == 0) {
                ret = i + 1;
                break;
            }
        }
    } else if ((arg1 - 1) < 2) {
        ret = arg1;
    }

    if (ret != 0) {
        i = ret - 1;
        D_80050118[i].unkC = arg0;
        D_80050118[i].unk10[4] = 1;
        D_80050118[i].unk10[10] = *arg0;
        D_80050118[i].unk10[11] = 0;
        D_80050118[i].unk10[5] = 0;
        D_80050118[i].unk10[7] = 0;
        D_80050118[i].unk10[1] = 0;
        D_80050118[i].unk8 = 1;
        D_80050118[i].unkA = arg2;
        return ret;
    }
    return 0;
}

static int func_80043470(int arg0)
{
    int i = arg0 - 1;
    D_80050118[i].unk10[7] = 0;
    D_80050118[i].unk10[1] = 0;
    D_80050118[i].unkC = 0;
    D_80050118[i].unk8 = 0;

    return arg0;
}

static int func_800434A4(int arg0, int arg1)
{
    int i;

    if ((arg0 - 1u) < 2) {
        return func_80043470(arg0);
    }
    if (arg0 == 0) {
        i = 0;
        if (arg1 != 0) {
            for (; i < 2; ++i) {
                if (D_80050118[i].unkA == arg1) {
                    func_80043470(i + 1);
                }
            }
            return 1;
        }
        do {
            ++i;
            func_80043470(i);
        } while (i < 2);
        return 1;
    }
    return 0;
}

static int func_80043554(int arg0)
{
    int v0 = arg0 - 1;
    D_80050118[v0].unk8 = 0;
    return arg0;
}

static int func_8004357C(int arg0)
{
    int i;

    if ((arg0 - 1u) < 2) {
        return func_80043554(arg0);
    }

    if (arg0 == 0) {
        for (i = 0; i < 2;) {
            func_80043554(++i);
        }
        return 1;
    }
    return 0;
}

static int func_800435DC(int arg0)
{
    int v0 = arg0 - 1;
    D_80050118[v0].unk8 = 1;
    return arg0;
}

static int func_80043608(int arg0)
{
    int i;

    if ((arg0 - 1u) < 2) {
        return func_800435DC(arg0);
    }

    if (arg0 == 0) {
        for (i = 0; i < 2;) {
            func_800435DC(++i);
        }
        return 1;
    }
    return 0;
}

static void func_80043668()
{
    int i;

    vs_main_padDisconnectAll();

    for (i = 0; i < 2; ++i) {
        D_80050118[i].unkC = 0;
        D_80050118[i].unk10[7] = 0;
        D_80050118[i].unk10[1] = 0;
        D_80050118[i].unk8 = 0;
    }
}

static inline int _abs2(int arg) { return arg < 0 ? arg += 0xFF : arg; }

void func_800436B4()
{
    int temp_a0;
    int var_a2_2;
    int i;
    int j;
    int var_v0;
    u_char* temp_t1;
    int new_var;

    D_80050118[0].unk0[1] = 0;
    D_80050118[0].unk0[0] = 0;

    for (j = 0; j < 2; ++j) {
        if (D_80050118[j].unk8 == 0) {
            continue;
        }

        temp_t1 = D_80050118[j].unkC;

        if (temp_t1 != 0) {
            for (i = 0; i < 2; ++i) {
                int(*a1)[6] = (int(*)[6])D_80050118[j].unk10;
                if (a1[i][5] == 0) {
                    temp_a0 = a1[i][4];
                    a1[i][5] = temp_t1[temp_a0++];
                    a1[i][1] = a1[i][3] = temp_t1[temp_a0++] << 8;
                    if (a1[i][5] == 0) {
                        a1[i][1] = 0;
                        a1[i][0] = 0;
                    } else {
                        new_var = i != 0;
                        a1[i][3] = temp_t1[temp_a0 + 1] << 8;
                        if (new_var) {
                            a1[i][2] = ((a1[i][3] - a1[i][1]) / a1[i][5]);
                        } else {
                            a1[i][2] = 0;
                        }
                        a1[i][0] = 1;
                        a1[i][4] += 2;
                    }
                }
                if (a1[i][5] != 0) {
                    a1[i][1] += a1[i][2];
                    a1[i][5] -= 1;
                } else {
                    a1[i][1] = a1[i][3];
                }

                D_80050118[0].unk0[i] += a1[i][1];
                if (D_80050118[0].unk0[i] > 0xFF00) {
                    D_80050118[0].unk0[i] = 0xFF00;
                } else if (D_80050118[0].unk0[i] < 0) {
                    D_80050118[0].unk0[i] = 0;
                }
            }
            D_80050118[j].unk8 = D_80050118[j].unk10[0] | D_80050118[j].unk10[6];
            if (D_80050118[j].unk8 == 0) {
                D_80050118[j].unkC = 0;
            }
            continue;
        }
        D_80050118[j].unk8 = 0;
    }

    if (D_8006002B != 0) {
        _padSetActData(0, 0, _abs2(D_80050118[0].unk0[0]) >> 8);
        _padSetActData(0, 1, _abs2(D_80050118[0].unk0[1]) >> 8);
    }
}

void func_800438C8(int arg0)
{
    int new_var4;
    int new_var;
    int new_var3;
    int new_var2;

    if (arg0 < D_8004A504[0]) {
        new_var = 5;
        new_var3 = 4;
        new_var4 = 6;
        new_var2 = 7;
        func_800433B4(&D_8004A504[(&D_8004A504[arg0 * new_var3])[new_var3]
                          + ((&D_8004A504[arg0 * new_var3])[new_var] << 8)
                          + ((&D_8004A504[arg0 * new_var3])[new_var4] << 16)
                          + ((&D_8004A504[arg0 * new_var3])[new_var2] << 24)],
            0xFF, 0x80);
    }
}

int vs_main_processPadState()
{
    int dummy[2];
    int i;
    u_int btnState;

    vs_main_buttonsState = _updatePadState(0, _padBuffer[0]) & 0xFFFF;
    vs_main_buttonsState |= _updatePadState(16, _padBuffer[1]) << 16;
    _padConnect(0, _padBuffer[0]);
    _padConnect(16, _padBuffer[1]);

    switch (vs_main_portInfo[0].mode) {
    case 4:
        vs_main_stickPosBuf.lStickY = 128;
        vs_main_stickPosBuf.lStickX = 128;
        vs_main_stickPosBuf.rStickY = 128;
        vs_main_stickPosBuf.rStickX = 128;
        break;
    case 7:
        vs_main_stickPosBuf.rStickX = vs_main_portInfo[0].rStickX;
        vs_main_stickPosBuf.rStickY = vs_main_portInfo[0].rStickY;
        vs_main_stickPosBuf.lStickX = vs_main_portInfo[0].lStickX;
        vs_main_stickPosBuf.lStickY = vs_main_portInfo[0].lStickY;

        if (vs_main_portInfo[0].rStickX < 16) {
            vs_main_buttonsState |= PADLleft;
        }
        if (vs_main_portInfo[0].rStickX >= 241) {
            vs_main_buttonsState |= PADLright;
        }

        if (vs_main_portInfo[0].rStickY < 16) {
            vs_main_buttonsState |= PADLup;
        }
        if (vs_main_portInfo[0].rStickY >= 241) {
            vs_main_buttonsState |= PADLdown;
        }

        if (vs_main_portInfo[0].lStickX < 32) {
            vs_main_buttonsState |= PADj;
        }
        if (vs_main_portInfo[0].lStickX >= 225) {
            vs_main_buttonsState |= PADj;
        }

        if (vs_main_portInfo[0].lStickY < 32) {
            vs_main_buttonsState |= PADj;
        }
        if (vs_main_portInfo[0].lStickY >= 225) {
            vs_main_buttonsState |= PADj;
        }
        break;
    default:
        vs_main_stickPosBuf.lStickY = 128;
        vs_main_stickPosBuf.lStickX = 128;
        vs_main_stickPosBuf.rStickY = 128;
        vs_main_stickPosBuf.rStickX = 128;
        break;
    }

    vs_main_buttonsPressed = ~vs_main_buttonsPreviousState & vs_main_buttonsState;
    vs_main_buttonsReleased = vs_main_buttonsPreviousState & ~vs_main_buttonsState;
    vs_main_buttonsPreviousState = vs_main_buttonsState;

    btnState = vs_main_buttonsState;
    for (i = 0; i < 32; ++i, btnState >>= 1) {
        if (btnState & 1) {
            D_80055C90[i] += vs_gametime_tickspeed;
        } else {
            D_80055C90[i] = 0;
        }
    }

    D_8005DFDC = vs_main_buttonsPressed;

    for (i = 0; i < 32; ++i) {
        if ((D_80055C90[i] >= 20) && !((D_80055C90[i] - 20) & 3)) {
            D_8005DFDC |= 1 << i;
        }
    }

#define RESET (PADstart | PADselect | PADR1 | PADR2 | PADL1 | PADL2)

    if ((_resetEnabled != 0) && ((vs_main_buttonsPreviousState & RESET) == RESET)
        && (vs_main_buttonsPressed & RESET)) {
        D_80060020[10] = 0;
        D_80060020[11] = 1;
        vs_main_resetGame();
    }

    return 1;
}

void vs_main_freeHeapR(void* block)
{
    vs_main_HeapHeader* var_a1 = heapA.prev;
    vs_main_HeapHeader* target = (vs_main_HeapHeader*)block - 1;

    for (; var_a1 >= target || target >= var_a1->next; var_a1 = var_a1->prev) {
        if (var_a1 >= var_a1->next && ((var_a1 < target) || (target < var_a1->next))) {
            break;
        }
    }

    if ((target + target->blockSz) == var_a1->next) {
        target->blockSz += var_a1->next->blockSz;
        target->next = var_a1->next->next;
        target->next->prev = target;
    } else {
        target->next = var_a1->next;
        target->next->prev = target;
    }

    if ((var_a1 + var_a1->blockSz) == target) {
        var_a1->blockSz += target->blockSz;
        var_a1->next = target->next;
        var_a1->next->prev = var_a1;
        return;
    }
    var_a1->next = target;
    target->prev = var_a1;
}

void vs_main_freeHeap(void* block)
{
    vs_main_HeapHeader* var_a1 = heapA.next;
    vs_main_HeapHeader* target = (vs_main_HeapHeader*)block - 1;

    for (; var_a1 >= target || target >= var_a1->next; var_a1 = var_a1->next) {
        if (var_a1 >= var_a1->next && ((var_a1 < target) || (target < var_a1->next))) {
            break;
        }
    }

    if ((target + target->blockSz) == var_a1->next) {
        target->blockSz += var_a1->next->blockSz;
        target->next = var_a1->next->next;
        target->next->prev = target;
    } else {
        target->next = var_a1->next;
        target->next->prev = target;
    }

    if ((var_a1 + var_a1->blockSz) == target) {
        var_a1->blockSz += target->blockSz;
        var_a1->next = target->next;
        var_a1->next->prev = var_a1;
        return;
    }
    var_a1->next = target;
    target->prev = var_a1;
}

u_long* vs_main_allocHeapR(u_int size)
{
    vs_main_HeapHeader* var_a1;
    vs_main_HeapHeader* var_a2;
    u_int blockSz;

    blockSz = ((size + 15) >> 4) + 1;
    var_a2 = &heapA;
    var_a1 = heapA.prev;

    while (1) {
        if (var_a1->blockSz >= blockSz) {
            if (var_a1->blockSz == blockSz) {
                var_a2->prev = var_a1->prev;
                var_a1->prev->next = var_a1->next;
            } else {
                var_a1->blockSz = var_a1->blockSz - blockSz;
                var_a1 += var_a1->blockSz;
                var_a1->blockSz = blockSz;
            }
            return (u_long*)(var_a1 + 1);
        }
        var_a2 = var_a1;
        if (var_a1 == &heapA) {
            return 0;
        }
        var_a1 = var_a1->prev;
    }
}

void* vs_main_allocHeap(u_int size)
{
    u_int blockSz;
    vs_main_HeapHeader* var_a1;
    vs_main_HeapHeader* var_v1;

    var_v1 = &heapA;
    var_a1 = heapA.next;
    blockSz = ((size + 0xF) >> 4) + 1;

    while (1) {
        if (var_a1->blockSz >= blockSz) {
            if (var_a1->blockSz == blockSz) {
                var_v1->next = var_a1->next;
                var_a1->next->prev = var_a1->prev;
            } else {
                vs_main_HeapHeader* temp_v1 = var_a1 + blockSz;
                temp_v1->blockSz = var_a1->blockSz - blockSz;
                temp_v1->prev = var_a1->prev;
                temp_v1->next = var_a1->next;
                temp_v1->prev->next = temp_v1;
                temp_v1->next->prev = temp_v1;
                var_a1->blockSz = blockSz;
            }
            return (u_long*)(var_a1 + 1);
        }
        var_v1 = var_a1;
        if (var_a1 == &heapA) {
            return 0;
        }
        var_a1 = var_a1->next;
    }
}

void vs_main_initHeap(vs_main_HeapHeader* node, u_int value)
{
    heapA.prev = node;
    heapA.next = node;
    heapA.blockSz = 0;
    node->prev = &heapA;
    node->next = &heapA;
    node->blockSz = value / 16 - 1;
    heapB.prev = &heapB;
    heapB.next = &heapB;
    heapB.blockSz = 0;
}

static void _diskReadCallback(u_char intr, u_char result[] __attribute__((unused)),
    u_long* arg2 __attribute__((unused)))
{

    if ((intr == DslDiskError) || (intr == DslNoIntr)
        || (vs_main_disk.state == diskReadError)) {
        DsReadyCallback(0);
        DsEndReadySystem();
        vs_main_disk.state = diskReadError;
        return;
    }

    if (intr != DslDataReady) {
        return;
    }

    vs_main_disk.state = diskReadReady;

    if (vs_main_disk.unk2C == 0) {
        DsGetSector((u_char*)vs_main_disk.vram + vs_main_disk.sectorBufIndex * 2048, 512);
    } else {
        DsGetSector(D_80050110 + vs_main_disk.unk3C * 128, 512);
        if (++vs_main_disk.unk3C >= 16) {
            vs_main_disk.unk3C = 0;
        }
    }

    switch (vs_main_disk.unk2C) {
    case 0:
        if (++vs_main_disk.sectorBufIndex >= vs_main_disk.sectorCount) {
            vs_main_disk.state = 0;
        }
        break;
    case 1:
        ++vs_main_disk.unk38;
        ++vs_main_disk.unk34;
        break;
    case 2:
        ++vs_main_disk.unk38;
        if (++vs_main_disk.unk40 >= 16) {
            vs_main_disk.unk40 = 0;
        }
        break;
    default:
        break;
    }

    if (++vs_main_disk.unk4 >= vs_main_disk.sectorCount) {
        DsEndReadySystem();
    }
}

static void vs_main_diskReadCommandCallback(
    u_char intr, u_char result[] __attribute__((unused)))
{
    switch (intr) {
    case DslComplete:
        DsStartReadySystem(_diskReadCallback, -1);
        return;
    case DslDiskError:
        break;
    default:
        break;
    case DslNoResult:
    case DslNoIntr:
        return;
    }
    vs_main_disk.state = diskReadError;
}

static void vs_main_diskSeekCommandCallback(
    u_char intr, u_char result[] __attribute__((unused)))
{
    switch (intr) {
    case DslNoIntr:
        break;
    case DslComplete:
        vs_main_disk.state = diskIdle;
        break;
    case DslDiskError:
        vs_main_disk.state = diskReadError;
        break;
    case DslNoResult:
        break;
    default:
        vs_main_disk.state = diskReadError;
        break;
    }
}

static void vs_main_diskPcmReadReady(u_char intr, u_char result[])
{
    switch (intr) {
    case DslComplete:
        DsReadyCallback(NULL);
        vs_main_disk.state = diskIdle;
        break;
    case DslDataReady:
        if (!(result[4] & 0x80)) {
            D_800501CC = ((result[1] >> 4) * 0xA) + (result[1] & 0xF);
            D_800501D0 = result[3];
            D_800501D4 = result[4];
            D_800501D8 = (result[6] << 8) | result[7];
        }
        break;
    case DslDiskError:
        DsReadyCallback(NULL);
        vs_main_disk.state = diskCommandFailed;
        break;
    }
}

static int vs_main_diskGetState() { return vs_main_disk.state; }

static void _diskResetErrorState()
{
    if (vs_main_disk.state == diskReadError) {
        vs_main_disk.state = diskIdle;
    }
}

static int vs_main_diskInitRead(int sector, u_int bytes, void* vram)
{
    if (vs_main_disk.state == diskIdle) {
        vs_main_disk.cdSector = sector;
        vs_main_disk.byteCount = bytes;
        vs_main_disk.vram = vram;
        vs_main_disk.unk40 = 0;
        vs_main_disk.unk3C = 0;
        vs_main_disk.sectorBufIndex = 0;
        vs_main_disk.unk34 = 0;
        vs_main_disk.unk4 = 0;
        vs_main_disk.unk3 = 0;
        vs_main_disk.unk38 = 0;
        vs_main_disk.sectorCount = bytes / 2048;
        if (bytes % 2048) {
            ++vs_main_disk.sectorCount;
        }
        DsIntToPos(sector, &vs_main_disk.cdLoc);
        vs_main_disk.state = diskReadInit;
        return 1;
    }
    return 0;
}

static void func_800443CC()
{
    DslATV vol;
    int i;
    u_int seconds;

    switch (vs_main_disk.state) {
    case diskIdle:
    default:
        break;
    case 6:
        if (DsSystemStatus() == DslReady) {
            vs_main_disk.unk1 = 0;
            vs_main_disk.cdLoc.minute = 0;
            while (DsControlB(DslSetmode, vs_main_dsControlBuf, NULL) == 0)
                ;
            VSync(3);
            vol.val2 = 0x80;
            vol.val0 = 0x80;
            vol.val3 = 0;
            vol.val1 = 0;
            DsMix(&vol);
            func_80012918(vs_main_disk.byteCount);
            func_80013230(0x7F);
            vs_main_disk.pcm.file = 1;
            vs_main_disk.pcm.chan = 0;
            DsControl(DslSetfilter, (u_char*)&vs_main_disk.pcm, NULL);
            DsIntToPos(vs_main_disk.cdSector, &vs_main_disk.cdLoc);
            vs_main_disk.commandId = DsPacket(
                DslModeRT | DslModeSF, &vs_main_disk.cdLoc, DslReadS, NULL, -1);
            DsReadyCallback(vs_main_diskPcmReadReady);
            vs_main_disk.state = 7;
        }
        if (vs_main_disk.commandId == 0) {
            DsReadyCallback(0);
            vs_main_disk.state = diskCommandFailed;
            ++vs_main_disk.unk3;
        }
        break;
    case diskReadInit: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            vs_main_disk.unk4 = 0;
            vs_main_disk.sectorBufIndex = 0;
            if (vs_main_disk.byteCount != 0) {
                vs_main_disk.state = diskReadReady;
                vs_main_disk.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &vs_main_disk.cdLoc, DslReadN, vs_main_diskReadCommandCallback, -1);
            } else {
                vs_main_disk.state = diskSeekReady;
                vs_main_disk.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &vs_main_disk.cdLoc, DslSeekL, vs_main_diskSeekCommandCallback, -1);
            }

            if (vs_main_disk.commandId == 0) {
                vs_main_disk.state = diskReadError;
                ++vs_main_disk.unk3;
            }
        }
        break;
    }
    case diskCommandFailed: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            vs_main_disk.unk4 = 0;
            ++vs_main_disk.unk3;
            seconds = _frameDuration / 60;
            if (seconds < 420) {
                DsIntToPos(vs_main_disk.cdSector + (seconds * 75) + (_frameDuration % 60),
                    &cdReadLoc);
                vol.val2 = 0x80;
                vol.val0 = 0x80;
                vol.val3 = 0;
                vol.val1 = 0;
                DsMix(&vol);
                func_80012918(0);
                func_80012940(0x3C, vs_main_disk.byteCount);
                vs_main_disk.pcm.file = 1;
                vs_main_disk.pcm.chan = 0;
                DsControl(DslSetfilter, (u_char*)&vs_main_disk.pcm, NULL);
                vs_main_disk.commandId
                    = DsPacket(DslModeRT | DslModeSF, &cdReadLoc, DslReadS, NULL, -1);
                DsReadyCallback(vs_main_diskPcmReadReady);
                vs_main_disk.state = 7;
            } else {
                vs_main_disk.commandId = DsCommand(DslModeSF | DslModeDA, NULL, NULL, -1);
                vs_main_disk.state = diskIdle;
                DsReadyCallback(0);
            }
        }
        if (vs_main_disk.commandId == 0) {
            vs_main_disk.state = diskCommandFailed;
            ++vs_main_disk.unk3;
        }
        break;
    }
    case diskReadError: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            vs_main_disk.unk4 = 0;
            vs_main_disk.sectorBufIndex = 0;
            ++vs_main_disk.unk3;

            if (vs_main_disk.byteCount != 0) {
                vs_main_disk.state = diskReadReady;
                vs_main_disk.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &vs_main_disk.cdLoc, DslReadN, vs_main_diskReadCommandCallback, -1);
            } else {
                vs_main_disk.state = diskSeekReady;
                vs_main_disk.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &vs_main_disk.cdLoc, DslSeekL, vs_main_diskSeekCommandCallback, -1);
            }

            if (vs_main_disk.commandId == 0) {
                vs_main_disk.state = diskReadError;
                ++vs_main_disk.unk3;
            }
        }
        break;
    }
    case 9:
        func_80012918(0);
        vs_main_disk.commandId = DsCommand(DslPause, NULL, NULL, -1);
        if (vs_main_disk.commandId > 0) {
            vs_main_disk.state = diskIdle;
        }
        DsReadyCallback(NULL);
        vs_main_disk.unk1 = 128;
        vs_main_disk.cdLoc.minute = 128;
        while (DsControlB(DslSetmode, vs_main_dsControlBuf, NULL) == 0)
            ;
        VSync(3);
        break;
    }

    if (vs_main_disk.unk2C != 0) {
        for (i = 0; i < 16; ++i) {
            if (vs_main_disk.sectorBufIndex >= vs_main_disk.unk38) {
                return;
            }
            if (vs_main_disk.unk2C == 1) {
                vs_main_memcpy(
                    ((u_char*)vs_main_disk.vram + (vs_main_disk.sectorBufIndex * 2048)),
                    D_80050110 + (vs_main_disk.unk40 * 128), 2048);

                ++vs_main_disk.unk40;
                if (vs_main_disk.unk40 >= 16) {
                    vs_main_disk.unk40 = 0;
                }
                --vs_main_disk.unk34;
                ++vs_main_disk.sectorBufIndex;
                if (vs_main_disk.sectorBufIndex >= vs_main_disk.sectorCount) {
                    vs_main_disk.state = diskIdle;
                    vs_main_freeHeapR(D_80050110);
                    D_80050110 = NULL;
                }
            } else if (vs_main_disk.unk2C == 2) {
                ++vs_main_disk.sectorBufIndex;
                if ((vs_main_disk.sectorBufIndex >= vs_main_disk.sectorCount)
                    && (func_80012C04() == 0)) {
                    vs_main_disk.state = diskIdle;
                    vs_main_freeHeapR(D_80050110);
                    D_80050110 = NULL;
                }
            }
        }
    }
}

int vs_main_diskLoadFile(int sector, int bytes, void* vram)
{
    int result = vs_main_diskInitRead(sector, bytes, vram);
    if (result != 0) {
        int seekReady = diskSeekReady;
        int readReady = diskReadReady;

        while (1) {
            if (vs_main_diskGetState() == seekReady) {
                vs_gametime_update(0);
            } else if (vs_main_diskGetState() == readReady) {
                vs_gametime_update(0);
            } else if (vs_main_diskGetState() == 3) {
                vs_gametime_update(0);
            } else if (vs_main_diskGetState() == diskReadInit) {
                vs_gametime_update(0);
            } else
                break;
        }
    }
    return result;
}

static int func_800449E8(int sector, int byteCount)
{
    if (vs_main_disk.state == diskIdle) {
        vs_main_disk.cdSector = sector;
        vs_main_disk.byteCount = byteCount;
        vs_main_disk.unk40 = 0;
        vs_main_disk.unk3C = 0;
        vs_main_disk.sectorBufIndex = 0;
        vs_main_disk.unk34 = 0;
        vs_main_disk.unk4 = 0;
        vs_main_disk.unk3 = 0;
        vs_main_disk.unk38 = 0;
        vs_main_disk.state = 6;
        return 1;
    }
    return 0;
}

static int func_80044A38()
{
    if (vs_main_disk.state == 7) {
        vs_main_disk.state = 9;
        return 1;
    }
    return 0;
}

static void _diskReset()
{
    while (DsControlB(DslPause, NULL, NULL) == 0)
        ;
    DsFlush();
    vs_main_disk.unk1 = 128;
    vs_main_disk.cdLoc.minute = 128;
    vs_main_disk.unk2 = 0;
    vs_main_disk.state = diskIdle;
    vs_main_disk.unk2C = 0;
    D_80050110 = NULL;
    while (DsControlB(DslSetmode, vs_main_dsControlBuf, NULL) == 0)
        ;
    VSync(3);
}

static void _initCdQueue()
{
    int i;

    for (i = 31; i >= 0; --i) {
        vs_main_cdQueue[i].unk0[0] = 0;
    }
    D_80050460.i = 0;
}

vs_main_CdQueueSlot* vs_main_getQueueSlot(vs_main_CdFile* file)
{
    int i;

    for (i = 0; i < 32; ++i) {
        if (vs_main_cdQueue[i].unk0[0] == 0) {
            vs_main_cdQueue[i].unk0[0] = 1;
            vs_main_cdQueue[i].cdFile = *file;
            return &vs_main_cdQueue[i];
        }
    }
    nop9(162, 0);
}

void func_80044B80(vs_main_CdQueueSlot* arg0)
{
    if ((u_short)arg0->unk0[0] - 2u < 2) {
        nop9(163, 0);
    }
    arg0->unk0[0] = 0;
}

void func_80044BC4(vs_main_CdQueueSlot* arg0, void* vram)
{
    u_short temp_a1;

    arg0->unk0[0] = 3;
    arg0->vram = vram;
    arg0->unkC = 0;
    temp_a1 = D_80050460.s[1];
    D_80050460.s[1] = (temp_a1 + 1);
    arg0->unk0[1] = temp_a1;
}

static void _populateQueueSlot(vs_main_CdQueueSlot* slot, void* vram)
{
    int i;
    vs_main_CdQueueSlot* queue = vs_main_cdQueue;

    for (i = 0; i < 32; ++i, ++queue) {
        if (queue->unk0[0] == 3) {
            ++queue->unk0[1];
        }
    }
    slot->unk0[0] = 3;
    slot->vram = vram;
    slot->unkC = 0;
    slot->unk0[1] = 0;
    ++D_80050460.s[1];
}

static void _nop4() { }

static void func_80044C74()
{
    int i;

    vs_main_disk.unk44 += 1;

    if (D_80050460.i != 0) {
        vs_main_CdQueueSlot* slot = vs_main_cdQueue;
        i = vs_main_diskGetState();
        if (i == diskIdle) {
            for (; i < 32; ++i, ++slot) {
                if (slot->unk0[0] == 3) {
                    if (slot->unk0[1] == 0) {
                        slot->unk0[0] = 2;
                        vs_main_diskInitRead(
                            slot->cdFile.lba, slot->cdFile.size, slot->vram);
                        vs_main_disk.unk44 = 0;
                        --D_80050460.s[1];
                        ++D_80050460.s[0];
                    } else {
                        --slot->unk0[1];
                    }
                } else if (slot->unk0[0] == 2) {
                    slot->unk0[0] = 4;
                    --D_80050460.s[0];
                }
            }
        }
    }
    func_800443CC();
}

static int func_80044D94() { return func_80011F90(); }

static void func_80044DB4() { func_80012004(); }

static void func_80044DD4() { func_80012468(); }

static int func_80044DF4(int arg0)
{
    u_int new_var;
    int var_a1;

    if (arg0 != 0) {
        if (D_8005E038.unk14[arg0 - 1] != 0xFFFF) {
            func_80011FDC(D_8005E038.unk14[arg0 - 1]);
            D_8005E038.unk14[arg0 - 1] = 0xFFFF;
        }
        if (D_8005E038.offset == arg0) {
            D_8005E038.offset = 0;
            D_8005E038.unkC_u.unkC_i = 0;
            D_8005E038.unk4 = 0xFFFF;
        }
        return 1;
    }
    func_80012B78();
    D_8005E038.offset = 0;
    D_8005E038.unkC_u.unkC_i = 0;
    D_8005E038.unk4 = 0xFFFF;

    new_var = 0xFFFF;
    for (var_a1 = 3; var_a1 >= 0; --var_a1) {
        D_8005E038.unk14[var_a1] = new_var;
    }
    return 1;
}

static int func_80044EC8(int arg0)
{
    u_int temp_v0;

    if (arg0 != 0) {
        if (D_8005E038.unk24[arg0 - 1] != 0) {
            D_8005E038.offset = arg0;
            temp_v0 = func_800120E8(
                D_8005E038.unkC_u.unkC_i = (u_int)D_8005E038.unk24[arg0 - 1]);
            if (temp_v0 != 0) {
                D_8005E038.unk14[arg0 - 1] = temp_v0;
                D_8005E038.unk4 = temp_v0;
            }
            D_8005E038.unk8 = D_8005E038.unk10[arg0 - 1];
        }
        return D_8005E03C;
    }
    return 0;
}

static int func_80044F60(int arg0, int arg1, u_int arg2)
{
    u_int temp_v0;

    if (arg0 != 0) {
        if (D_8005E038.unk24[arg0 - 1] != 0) {
            D_8005E038.offset = arg0;
            D_8005E038.unkC_u.unkC_i = (u_int)D_8005E038.unk24[arg0 - 1];
            temp_v0 = func_80012080(D_8005E038.unkC_u.unkC_i, arg2, arg1);
            if (temp_v0 != 0) {
                D_8005E038.unk14[arg0 - 1] = temp_v0;
                D_8005E038.unk4 = temp_v0;
            }
            D_8005E038.unk8 = D_8005E038.unk10[arg0 - 1];
        }
        return D_8005E03C;
    }
    return 0;
}

static int func_80045000(int arg0, int arg1, int arg2)
{
    u_int temp_v0;

    if (arg0 != 0) {
        if (D_8005E038.unk24[arg0 - 1] != 0) {
            D_8005E038.offset = arg0;
            D_8005E038.unkC_u.unkC_i = (u_int)D_8005E038.unk24[arg0 - 1];
            func_800128A0(0, arg2, arg1);
            temp_v0 = func_80011FB4(D_8005E038.unkC_u.unkC_i);
            if (temp_v0 != 0) {
                D_8005E038.unk14[arg0 - 1] = temp_v0;
                D_8005E038.unk4 = temp_v0;
                func_800128A0(0, arg2, arg1);
            }
            D_8005E038.unk8 = D_8005E038.unk10[arg0 - 1];
        }
        return D_8005E03C;
    }
    return 0;
}

static int func_800450D4() { return D_8005E038.offset; }

static u_char func_800450E4()
{
    if (D_8005E038.offset != 0) {
        return D_8005E038.unkC_u.unkC_s.unkF[D_8005E038.offset];
    }
    return 0;
}

static int func_80045110(int arg0, int arg1)
{
    vs_main_CdFile cdFile;

    if (arg0 > 0 && arg1 > 0) {
        int arg = arg1 - 1;

        if (arg1 < 5) {
            if (D_8005E038.unk10[arg] != arg0) {
                do {
                    if (D_8005E038.unk24[arg] != 0) {
                        nop10(142, 0);
                        func_80045440(arg1);
                    }
                } while (0);

                cdFile.lba = _musicLBAs[arg0];
                cdFile.size = _musicFileSizes[arg0];

                if ((D_8005E038.unk34[arg] != 0)
                    && (D_8005E038.unk34[arg] != (vs_main_CdQueueSlot*)-1)) {
                    nop9(0x98, 0);
                }

                D_8005E038.unk34[arg] = vs_main_getQueueSlot(&cdFile);

                if (D_8005E038.unk24[arg] != 0) {
                    nop9(0x8E, 0);
                }
                D_8005E038.unk24[arg] = vs_main_allocHeapR(cdFile.size);
                func_80044BC4(D_8005E038.unk34[arg], D_8005E038.unk24[arg]);
                D_8005E038.unk10[arg] = arg0;
            }
            return arg1;
        }
    }
    nop9(0x8E, 0);
    return 0;
}

static int func_80045270(int arg0)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if (D_8005E038.unk24[i] == 0) {
            return func_80045110(arg0, i + 1);
        }
    }
    return 0;
}

static int func_800452C8(u_int arg0)
{
    if ((arg0 - 1) < 4) {
        if (D_8005E038.unk34[arg0 - 1] != 0) {
            if (D_8005E038.unk34[arg0 - 1]->unk0[0] == 4) {
                func_80044B80(D_8005E038.unk34[arg0 - 1]);
                D_8005E038.unk34[arg0 - 1] = 0;
                return 0;
            }
            if (D_8005E038.unk34[arg0 - 1]->unk0[0] == 6) {
                func_80044B80(D_8005E038.unk34[arg0 - 1]);
                D_8005E038.unk34[arg0 - 1] = (vs_main_CdQueueSlot*)-1;
                return -1;
            }
            return 1;
        }
    }
    return 0;
}

static int func_80045350()
{
    int i;
    int ret;

    ret = 0;
    i = 0;
    do {
        ret |= func_800452C8(++i);
    } while (i < 4);

    return ret;
}

static int func_8004539C(int arg0, int arg1)
{
    int temp_v0;

    temp_v0 = func_80045110(arg0, arg1);
    if (temp_v0 != 0) {
        while (func_800452C8(arg1) != 0) {
            vs_gametime_update(0);
        }
    }
    return temp_v0;
}

static int func_800453F4(int arg0)
{
    int ret;

    ret = func_80045270(arg0);
    if (ret != 0) {
        while (func_80045350() != 0) {
            vs_gametime_update(0);
        }
    }
    return ret;
}

static int func_80045440(int arg0)
{
    func_80044DF4(arg0);

    if (D_8005E038.unk24[arg0 - 1] == 0) {
        return 0;
    }

    vs_main_freeHeapR(D_8005E038.unk24[arg0 - 1]);
    D_8005E038.unk24[arg0 - 1] = 0;
    D_8005E038.unk10[arg0 - 1] = 0;
    return 1;
}

static int nop5() { return 0; }

static int func_800454B8(int arg0)
{
    if (arg0 != 0) {
        if (D_8005E038.unk14[arg0 - 1] != 0xFFFF) {
            return func_80011EBC(D_8005E038.unk14[arg0 - 1]);
        }
    }
    return 0;
}

static void func_8004550C(int arg0) { func_800454B8(arg0); }

static int func_8004552C(int arg0, int arg1, int arg2)
{
    if (D_8005E038.offset == arg0) {
        func_800128A0(D_8005E038.unk4, arg2, arg1);
        return 1;
    }
    return 0;
}

static int func_80045574(int arg0, int arg1, int arg2)
{
    if (D_8005E038.offset == arg0) {
        func_800129D0(arg2, arg1);
        return 1;
    }
    return 0;
}

static int func_800455AC(int arg0, int arg1, int arg2)
{
    if (D_8005E038.offset == arg0) {
        func_80012A6C(arg2, arg1);
        return 1;
    }
    return 0;
}

static int nop6() { return 0; }

static int nop7() { return 0; }

static void func_800455F4()
{
    int offset = D_8005E038.offset;
    if (offset != 0) {
        func_80044DF4(offset);
        func_80045440(offset);
    }
}

static void func_80045630(u_short arg0)
{
    func_8001217C(arg0, D_8005FE70, 0x80, 0x7F);

    if (!((D_8005FE70 *= 2) & 1)) {
        D_8005FE70 = 1;
    }
}

static void func_80045684(int arg0, int arg1, int arg2, int arg3)
{
    if (arg1 == 0x200) {
        if (arg0 != func_80012358(0x200)) {
            func_8001217C(arg0, 0x200, arg2, arg3);
        }
    } else {
        func_8001217C(arg0, arg1, arg2, arg3);
    }
}

static void func_800456EC(int arg0, int arg1, int arg2, int arg3)
{
    if (arg1 == 0x200) {
        if (arg0 != func_80012358(0x200)) {
            func_800121F0(arg0, 0x200, arg2, arg3);
        }
    } else {
        func_800121F0(arg0, arg1, arg2, arg3);
    }
}

void func_80045754(int arg0, int arg1, int arg2, int arg3)
{
    u_short var_s0;
    void* var_s0_2;

    switch (arg0) {
    case 0x7E:
    case 0xFE:
        var_s0 = arg1;
        if (func_800123C8(var_s0) != 0) {
            func_80045684(var_s0, D_8005FE74, arg2, arg3);
            D_8005FE74 *= 2;
            if (!(D_8005FE74 & 0x7E)) {
                D_8005FE74 = 2;
            }
        } else {
            func_80045684(var_s0, 0, arg2, arg3);
        }
        break;
    case 0x100:
    case 0x200:
        var_s0 = arg1;
        if (func_800123C8(var_s0) != 0) {
            func_80045684(var_s0, D_8005FE7C, arg2, arg3);
        } else {
            func_80045684(var_s0, 0, arg2, arg3);
        }

        break;
    case 0xFF000:
        var_s0_2 = D_8005E038.unk4C[D_8005E038.unk44 - 1];
        var_s0_2 = (u_char*)var_s0_2 + (arg1 + (int*)var_s0_2)[1];
        if (func_800123C8((int)var_s0_2) != 0) {
            func_800456EC((int)var_s0_2, D_8005FE80, arg2, arg3);
            D_8005FE80 *= 2;
            if (!(D_8005FE80 & arg0)) {
                D_8005FE80 = 0x1000;
            }
        } else {
            func_800456EC((int)var_s0_2, 0, arg2, arg3);
        }
        break;
    case 0xF00000:
        var_s0_2 = D_8005E08C;
        var_s0_2 = (u_char*)var_s0_2 + (arg1 + ((int*)D_8005E08C))[1];
        if (func_800123C8((int)var_s0_2) != 0) {
            func_800456EC((int)var_s0_2, D_8005FE84, arg2, arg3);
            D_8005FE84 *= 2;
            if (!(D_8005FE84 & arg0)) {
                D_8005FE84 = 0x100000;
            }
        } else {
            func_800456EC((int)var_s0_2, 0, arg2, arg3);
        }
        break;
    default:
        nop10(0x95, 0);
        break;
    }
}

void func_80045988(int arg0, int arg1) { func_80045754(arg0, arg1, 0x80, 0x7F); }

int func_800459AC(int coords, int z)
{
    int v0;
    int new_var2;
    int v1;

    v0 = coords;

    if (coords < 0) {
        v0 += 0xFFFF;
    }

    v0 = (v0 >> 16) << 16;
    coords = (short)(coords - v0) - 160;
    coords = (coords * 3) / 10;

    if (coords < -96) {
        coords = -96;
    }

    if (coords > 96) {
        coords = 96;
    }

    coords += 128;
    v1 = z - 768;

    if (v1 < 0) {
        v1 = 0;
    }

    if (v1 > 4095) {
        v1 = 4095;
    }

    v0 = v1;

    if (v1 < 0) {
        v0 = v1 + 31;
    }

    v0 >>= 5;
    v1 = 127;

    new_var2 = v1 - v0;
    return (coords << 16) + new_var2;
}

static void func_80045A58(int arg0, int arg1, int coords, int z)
{
    coords = func_800459AC(coords, z);
    z = coords & 0xFFFF;
    coords = coords >> 0x10;
    if (z > 0) {
        func_80045754(arg0, arg1, coords, z);
    }
}

static void func_80045AA8(int arg0, int arg1, SVECTOR* vec)
{
    int z;
    long coords;
    long value;
    long flag;

    SetRotMatrix(&D_1F800014_mat);
    SetTransMatrix(&D_1F800014_mat);
    z = RotTransPers(vec, &coords, &value, &flag);
    func_80045A58(arg0, arg1, coords, z);
}

static int func_80045B28(int arg0, int arg1)
{
    int temp_v1;

    switch (arg0) {
    case 0x1:
    case 0x7E:
    case 0xFE:
    case 0x100:
    case 0x200:
        temp_v1 = 0;
        break;
    case 0xFF000:
    case 0xF00000:
        temp_v1 = (int)D_8005E038.unk4C[D_8005E038.unk44 - 1];
        temp_v1 = (int)temp_v1 + (arg1 + (int*)temp_v1)[1];
        break;
    default:
        nop10(0x95, 0);
        temp_v1 = 0;
        break;
    }
    return temp_v1;
}

static void func_80045BFC(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    if (arg1 != 0) {
        temp_v0 = func_80045B28(arg0, arg1);

        if (temp_v0 != 0) {
            func_8001264C(temp_v0, 0, arg3 & 0xFF, arg2);
        } else {
            do {
                func_8001264C(arg1, 0, arg3 & 0xFF, arg2);
            } while (0);
        }
    } else {
        func_8001264C(0, arg0, arg3 & 0xFF, arg2);
    }
}

static void func_80045C74(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    if (arg1 != 0) {
        temp_v0 = func_80045B28(arg0, arg1);
        if (temp_v0 != 0) {
            func_80012824(temp_v0, 0, arg3 & 0xFF, arg2);
        } else {
            do {
                func_80012824(arg1, 0, arg3 & 0xFF, arg2);
            } while (0);
        }
    } else {
        func_80012824(0, arg0, arg3 & 0xFF, arg2);
    }
}

static void func_80045CEC(int arg0, int arg1, int arg2, int arg3)
{
    if (arg1 != 0) {
        arg0 = func_80045B28(arg0, arg1);
        if (arg0 != 0) {
            func_80012738(arg0, 0, arg3 & 0xFF, arg2);
        } else {
            do {
                func_80012738(arg1, 0, arg3 & 0xFF, arg2);
            } while (0);
        }
    } else {
        func_80012738(0, arg0, arg3 & 0xFF, arg2);
    }
}

static void func_80045D64(int arg0, int arg1)
{
    if (arg1 != 0) {
        arg0 = func_80045B28(arg0, arg1);

        if (arg0 != 0) {
            func_80012288(arg0, 0);
        } else {
            func_80012288(arg1, 0);
        }
    } else {
        func_80012288(0, arg0);
    }
}

static void func_80045DC0() { func_80012B98(); }

int func_80045DE0(int id, int slot)
{
    vs_main_CdFile cdFile;
    u_int new_var;

    if ((slot - 1u) < 3) {
        if (D_8005E038.unk4C[(slot - 1)] == 0) {
            new_var = slot - 1;
            cdFile.lba = _seLBAs[id];
            cdFile.size = _seFileSizes[id];

            if ((D_8005E038.unk58[new_var] != 0)
                && (D_8005E038.unk58[new_var] != (vs_main_CdQueueSlot*)-1)) {
                nop9(0x8F, 0);
            }

            D_8005E038.unk58[new_var] = vs_main_getQueueSlot(&cdFile);

            if (D_8005E038.unk4C[new_var] != 0) {
                nop9(0x90, 0);
            }

            D_8005E038.unk48[new_var] = id;
            D_8005E038.unk4C[new_var] = vs_main_allocHeapR(cdFile.size);
            func_80044BC4(D_8005E038.unk58[new_var], D_8005E038.unk4C[new_var]);

            return slot;
        }
    }
    return 0;
}

static int func_80045F0C(int arg0)
{
    int i;

    for (i = 0; i < 3; ++i) {
        if (D_8005E038.unk4C[i] == 0) {
            return func_80045DE0(arg0, i + 1);
        }
    }
    return 0;
}

static int func_80045F64(u_int arg0)
{
    if ((arg0 - 1) < 3) {
        if (D_8005E038.unk58[arg0 - 1] != 0) {
            if (D_8005E038.unk58[arg0 - 1]->unk0[0] == 4) {
                func_80044B80(D_8005E038.unk58[arg0 - 1]);
                D_8005E038.unk58[arg0 - 1] = 0;
                return 0;
            }
            if (D_8005E038.unk58[arg0 - 1]->unk0[0] == 6) {
                func_80044B80(D_8005E038.unk58[arg0 - 1]);
                D_8005E038.unk58[arg0 - 1] = (vs_main_CdQueueSlot*)-1;
                return -1;
            }
            return 1;
        }
    }
    return 0;
}

static int func_80045FEC()
{
    int i;
    int ret;

    ret = 0;
    i = 0;
    do {
        ret |= func_80045F64(++i);
    } while (i < 3);

    return ret;
}

static int func_80046038(int arg0)
{
    int ret;

    ret = func_80045F0C(arg0);
    if (ret != 0) {
        while (func_80045FEC() != 0) {
            vs_gametime_update(0);
        }
    }
    return ret;
}

static int func_80046084(int arg0)
{
    if ((arg0 - 1u < 3) && D_8005E038.unk4C[arg0 - 1] != 0) {
        D_8005E038.unk44 = arg0;
        return 1;
    }
    return 0;
}

static int func_800460C0(u_int arg0)
{
    if ((arg0 - 1) < 3) {
        if (D_8005E038.unk4C[arg0 - 1] != 0) {
            if (D_8005E038.unk44 == arg0) {
                D_8005E038.unk44 = 0;
            }
            func_80012288(-2, 0);
            func_80012288(0, 0xFF000);
            vs_main_freeHeapR(D_8005E038.unk4C[arg0 - 1]);
            D_8005E038.unk48[arg0 - 1] = 0;
            D_8005E038.unk4C[arg0 - 1] = 0;
            return 1;
        }
    }
    return 0;
}

static int func_80046168(u_int arg0)
{
    if (D_8005E038.unk14[16] == 0) {
        D_8005E038.unk14[16] = arg0;
        return 1;
    }
    return 0;
}

static int func_80046194()
{
    func_80012288(-2, 0);
    func_80012288(0, 0xF00000);
    D_8005E08C = NULL;
    return 1;
}

static void func_800461CC(int arg0, u_int arg1[], u_int arg2, int arg3, int arg4)
{
    int var_s0;
    void* temp_s1;

    temp_s1 = arg1;

    if (arg2 < arg1[0]) {
        temp_s1 = (u_char*)arg1 + (arg1 + arg2)[1];
        var_s0 = 0;

        if (arg0 == 0x180) {
            var_s0 = D_8005FE78;
            D_8005FE78 *= 2;
            if (!(D_8005FE78 & 0x180)) {
                D_8005FE78 = 0x80;
            }
        } else if (arg0 == 0x200) {
            var_s0 = D_8005FE7C;
            D_8005FE7C *= 2;
            if (!(D_8005FE7C & 0x200)) {
                D_8005FE7C = arg0;
            }
        } else if (arg0 == 0xF00000) {
            var_s0 = D_8005FE84;
            D_8005FE84 *= 2;
            if (!(D_8005FE84 & arg0)) {
                D_8005FE84 = 0x100000;
            }
        } else if (arg0 == 0x7E) {
        } else {
            nop10(0x95, 0);
        }
        func_800456EC((int)temp_s1, var_s0, arg3, arg4);
    }
}

static void func_800462E8(int arg0, u_int* arg1, u_int arg2)
{
    func_800461CC(arg0, arg1, arg2, 0x80, 0x7F);
}

static void func_80046310(int arg0, u_int arg1[], int arg2, int arg3, int arg4)
{
    int temp_t0;
    int var_v0;
    int var_v1;

    var_v1 = arg3;
    var_v0 = arg3;
    arg3 = var_v0 >> 0x10;

    if (var_v1 < 0) {
        var_v0 = var_v1 + 0xFFFF;
    }

    arg3 = var_v0 >> 0x10;
    var_v0 = arg3 << 0x10;
    arg3 = var_v1 - var_v0;

    if (arg3 < 0) {
        arg3 = 0;
    }

    if (arg3 >= 0x141) {
        arg3 = 0x140;
    }

    var_v0 = arg3 + ((u_int)arg3 >> 0x1F);
    var_v0 >>= 1;
    arg3 = var_v0 + 0x30;
    temp_t0 = arg4;

    if (temp_t0 < 0) {
        temp_t0 = 0;
    }

    if (temp_t0 >= 0x401) {
        temp_t0 = 0x400;
    }

    var_v1 = temp_t0;

    if (temp_t0 < 0) {
        var_v1 += 7;
    }

    temp_t0 = 0x7F - (var_v1 >> 3);

    if (temp_t0 > 0) {
        func_800461CC(arg0, arg1, arg2, arg3, temp_t0);
    }
}

static void func_800463BC(int arg0, u_int* arg1, int arg2, SVECTOR* vec)
{
    int z;
    long sxy;
    long value;
    long flag;

    SetRotMatrix(&D_1F800014_mat);
    SetTransMatrix(&D_1F800014_mat);
    z = RotTransPers(vec, &sxy, &value, &flag);
    func_80046310(arg0, arg1, arg2, sxy, z);
}

static void func_8004644C(int arg0, int* arg1, int arg2)
{
    int var_a1;
    u_char* var_a0 = (u_char*)arg1 + (arg1 + arg2)[1];

    if (arg2 != 0) {
        var_a1 = 0;
    } else {
        var_a0 = 0;
        var_a1 = arg0;
    }
    func_80012288((int)var_a0, var_a1);
}

static void func_80046494(int arg0, int* arg1, int arg2, int arg3, int arg4)
{
    int a0 = (int)((u_char*)arg1 + (arg2 + arg1)[1]);

    if (arg2 == 0) {
        func_8001264C(0, arg0, arg4 & 0xFF, arg3);
    } else {
        func_8001264C(a0, 0, arg4 & 0xFF, arg3);
    }
}

static void func_800464DC() { func_80013328(); }

static int func_800464FC(int arg0, int arg1, int arg2)
{
    if ((arg0 - 1u) < 3) {
        if (D_8005E038.unk64[arg0 - 1] != 0) {
            func_80013378(0, arg2);
            func_800132C4(D_8005E038.unk64[arg0 - 1], arg1, 1);
            return 1;
        }
    }
    return 0;
}

static void func_80046578(int arg0) { func_800464FC(arg0, 0x80, 0x7F); }

static int func_8004659C(int arg0)
{
    if ((arg0 - 1u) < 3) {
        if (D_8005E038.unk64[arg0 - 1] != 0) {
            func_80013328();
            vs_main_freeHeapR(D_8005E038.unk64[arg0 - 1]);
            D_8005E038.unk64[arg0 - 1] = 0;
            return 1;
        }
    }
    return 0;
}

static int func_80046608(u_int arg0)
{
    if (D_8005E038.unk14[22] == 0) {
        D_8005E038.unk14[22] = arg0;
        return 3;
    }
    return 0;
}

static int func_80046634()
{

    if (D_8005E038.unk14[22] != 0) {
        func_80013328();
        D_8005E038.unk14[22] = 0;
        return 1;
    }
    return 0;
}

static void func_80046678(int file)
{
    vs_main_CdFile cdFile;
    int new_var;
    int temp_v1;
    int var_a0;

    temp_v1 = func_80011F08();
    var_a0 = temp_v1 >> 0x10;
    new_var = temp_v1;

    if (temp_v1 < 0) {
        var_a0 = (temp_v1 + 0xFFFF) >> 0x10;
    }
    if (((new_var - (var_a0 << 0x10)) == file) || (var_a0 == file)) {
        return;
    }
    cdFile.lba = _soundLBAs[file];
    cdFile.size = _soundFileSizes[file];

    if (D_8005E0BC) {
        if (D_8005E0BC != (-1)) {
            nop9(0x93 & 0xFFu, 0);
        }
    }
    D_8005E038.unk84 = vs_main_getQueueSlot(&cdFile);
    if (D_8005E038.unk80 != 0) {
        nop9(0x94, 0);
    }
    new_var = 1;
    D_8005E038.unk80 = vs_main_allocHeapR(cdFile.size);
    D_8005E038.fileId = file;
    func_80044BC4(D_8005E038.unk84, D_8005E038.unk80);
}

static void func_80046770(int arg0) { func_80046678(_soundFileMap[arg0]); }

static int func_800467A0()
{
    int temp_v0;

    if (D_8005E038.unk84 != 0) {
        if (D_8005E038.unk84->unk0[0] == 7) {
            temp_v0 = func_80012C04();
            if (temp_v0 == 0) {
                func_80044B80(D_8005E038.unk84);
                D_8005E038.unk84 = 0;
                vs_main_freeHeapR(D_8005E038.unk80);
                D_8005E038.unk80 = 0;
                D_8005E038.fileId = 0;
                return 0;
            }
            if (temp_v0 == -1) {
                func_80044B80(D_8005E038.unk84);
                D_8005E038.unk84 = 0;
                vs_main_freeHeapR(D_8005E038.unk80);
                D_8005E038.unk80 = 0;
                D_8005E038.fileId = 0;
                return -1;
            }
            return 1;
        }
        if (D_8005E038.unk84->unk0[0] == 4) {
            D_8005E038.unk84->unk0[0] = 7;
            func_80013188(D_8005E038.unk80, 0);
            return 1;
        }
        if (D_8005E038.unk84->unk0[0] == 6) {
            func_80044B80(D_8005E038.unk84);
            D_8005E038.unk84 = 0;
            vs_main_freeHeapR(D_8005E038.unk80);
            D_8005E038.unk80 = 0;
            D_8005E038.fileId = 0;
            return -1;
        }
        return 1;
    }
    return 0;
}

static void func_8004687C(int arg0)
{
    func_80046770(arg0);

    while (func_800467A0() != 0) {
        vs_gametime_update(0);
    }
}

void func_800468BC(int arg0) { func_8001240C(arg0); }

static void func_800468DC() { func_80012918(0x7FFF); }

static void _loadMenuSound()
{
    void* temp_v0;

    func_80011DAC();
    func_80013230(0x7F);
    temp_v0 = vs_main_allocHeapR(VS_WAVE0000_DAT_SIZE);
    vs_main_diskLoadFile(VS_WAVE0000_DAT_LBA, VS_WAVE0000_DAT_SIZE, temp_v0);
    func_80012BB8(temp_v0, 1);
    vs_main_freeHeapR(temp_v0);
    temp_v0 = vs_main_allocHeapR(VS_WAVE0005_DAT_SIZE);
    vs_main_diskLoadFile(VS_WAVE0005_DAT_LBA, VS_WAVE0005_DAT_SIZE, temp_v0);
    func_80012BB8(temp_v0, 1);
    vs_main_freeHeapR(temp_v0);
    temp_v0 = vs_main_allocHeapR(VS_WAVE0200_DAT_SIZE);
    vs_main_diskLoadFile(VS_WAVE0200_DAT_LBA, VS_WAVE0200_DAT_SIZE, temp_v0);
    func_800131DC(temp_v0, 0, 1);
    vs_main_freeHeapR(temp_v0);
    vs_main_diskLoadFile(VS_EFFECT00_DAT_LBA, VS_EFFECT00_DAT_SIZE, &D_80050478);
    func_80011DEC(D_80050478);
    D_8005FE70 = 1;
    D_8005FE74 = 2;
    D_8005FE78 = 0x80;
    D_8005FE7C = 0x200;
    D_8005FE80 = 0x1000;
    D_8005FE84 = 0x100000;
}

static void func_80046A38()
{
    int i;

    D_8005E038.offset = 0;
    D_8005E038.unkC_u.unkC_i = 0;
    D_8005E038.unk8 = 0xFFFF;
    D_8005E038.unk4 = 0xFFFF;
    D_8005E038.unk44 = 0;

    for (i = 0; i < 4; ++i) {
        D_8005E038.unk10[i] = 0;
        D_8005E038.unk14[i] = 0xFFFF;
        D_8005E038.unk24[i] = 0;
        D_8005E038.unk34[i] = 0;
    }

    for (i = 0; i < 3; ++i) {
        D_8005E038.unk48[i] = 0;
        D_8005E038.unk4C[i] = 0;
        D_8005E038.unk58[i] = 0;
    }

    for (i = 0; i < 3; ++i) {
        D_8005E038.unk64[i] = 0;
        D_8005E038.unk70[i] = 0;
    }

    D_8005E038.fileId = 0;
    D_8005E038.unk80 = 0;
    D_8005E038.unk84 = 0;
    D_8005FE70 = 1;
    D_8005FE74 = 2;
    D_8005FE78 = 0x80;
    D_8005FE7C = 0x200;
    D_8005FE80 = 0x1000;
    D_8005FE84 = 0x100000;
}

void func_80046B3C(int arg0, int arg1, u_short* arg2)
{
    int i;
    u_short g;
    u_short b;
    u_short r;
    struct ColorInfo* p;

    for (i = 0; i < 256; ++i) {
        r = arg2[i] & 0x1F;
        g = (arg2[i] & 0x3E0) >> 5;
        b = (arg2[i] & 0x7C00) >> 10;

        p = D_80055D58.unk0[arg1].unkE;

        if (arg0 != 0) {
            p[i].rindex = (r - p[i].r) + 31;
            p[i].gindex = (g - p[i].g) + 31;
            p[i].bindex = (b - p[i].b) + 31;
        } else {
            p[i].r = r;
            p[i].g = g;
            p[i].b = b;
            loadImageSource[arg1][i] = r + (g << 5) + (b << 10) + (p[i].a << 15);
        }
    }

    if (arg0 != 0) {
        u_char* p = D_80055D58.unk0[arg1].unk6;
        p[0] = 1;
        p[1] = 0;
        p[2] = 0;
        p[3] = arg0;
    } else {
        D_80055D58.unk0[arg1].unk6[0] = 0;
    }
}

void func_80046C80(int arg0, int arg1, u_short* arg2, int arg3)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80046B3C(arg0, arg1, arg2 + (arg3 << 4));
        D_80055D58.unk0[0].unk0 = 1;
    }
}

static void func_80046CC8(int arg0, int arg1, u_short* arg2, int arg3)
{
    int i;

    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80046C80(arg0, arg1, arg2, arg3);

        for (i = 0; i < 0x100; ++i) {
            D_80055D58.unk0[arg1].unk70E[i] = arg2[i];
        }
    }
}

static void func_80046D58(int arg0)
{
    int i;

    if (D_80055D58.unk0[0].unk2 != 0) {
        for (i = 0; i < 256; ++i)
            D_80055D58.unk0[arg0].unk70E[i] = loadImageSource[arg0][i];
    }
}

static inline int inline_fn5(short arg0, short arg1, short arg2)
{
    return arg2 * 2 + (arg0 >> 5) * 3 + (arg1 >> 10);
}

void func_80046DC0(int arg0, int arg1, int arg2, int arg3, short arg4, short arg5)
{
    int i;
    int var_v0;
    short temp_t0;
    int var_t3;
    int var_t1;
    int var_a0;
    int tmp;
    int t4 = (u_short)arg4;
    int t5 = (u_short)arg5;
    struct ColorInfo* t2 = D_80055D58.unk0[arg2].unkE;

    for (i = 0; i < 256; ++i) {
        temp_t0 = D_80055D58.unk0[arg2].unk70E[i];
        if ((t2[i].r + t2[i].g + t2[i].b + t2[i].a) != 0) {
            switch (arg0) {
            case 1:
                tmp = 1;
                var_t3 = arg3 + (t2[i].r >> tmp);
                var_t1 = t4 + (t2[i].g >> tmp);
                var_a0 = t5 + (t2[i].b >> tmp);
                break;
            case 2:
                var_t3 = arg3 + ((t2[i].r * 2) + (t2[i].g * 3) + t2[i].b) / 6;
                var_t1 = t4 + ((t2[i].r * 2) + (t2[i].g * 3) + t2[i].b) / 6;
                var_a0 = t5 + ((t2[i].r * 2) + (t2[i].g * 3) + t2[i].b) / 6;
                break;
            case 3:
                var_t3 = arg3 + ((t2[i].r * 2) + (t2[i].g * 3) + t2[i].b) / 12;
                var_t1 = t4 + ((t2[i].r * 2) + (t2[i].g * 3) + t2[i].b) / 12;
                var_a0 = t5 + ((t2[i].r * 2) + (t2[i].g * 3) + t2[i].b) / 12;
                break;
            case 4:
            case 9:
                var_t3 = arg3 + (temp_t0 & 0x1F);
                var_t1 = t4 + ((temp_t0 & 0x3E0) >> 5);
                var_a0 = t5 + ((temp_t0 & 0x7C00) >> 0xA);
                break;
            case 5:
                tmp = 0x1F;
                var_t3 = arg3 + ((temp_t0 & tmp) >> 1);
                var_t1 = t4 + ((temp_t0 & 0x3E0) >> 6);
                var_a0 = t5 + ((temp_t0 & 0x7C00) >> 0xB);
                break;
            case 6:
                var_t3 = arg3
                    + inline_fn5(temp_t0 & 0x3E0, temp_t0 & 0x7C00, temp_t0 & 0x1F) / 6;
                var_t1 = t4
                    + inline_fn5(temp_t0 & 0x3E0, temp_t0 & 0x7C00, temp_t0 & 0x1F) / 6;
                var_a0 = t5
                    + inline_fn5(temp_t0 & 0x3E0, temp_t0 & 0x7C00, temp_t0 & 0x1F) / 6;
                break;
            case 7:
                var_t3 = arg3
                    + inline_fn5(temp_t0 & 0x3E0, temp_t0 & 0x7C00, temp_t0 & 0x1F) / 12;
                var_t1 = t4
                    + inline_fn5(temp_t0 & 0x3E0, temp_t0 & 0x7C00, temp_t0 & 0x1F) / 12;
                var_a0 = t5
                    + inline_fn5(temp_t0 & 0x3E0, temp_t0 & 0x7C00, temp_t0 & 0x1F) / 12;
                break;
            case 8:
            case 15:
                var_t3 = temp_t0 & 0x1F;
                var_t1 = (temp_t0 & 0x3E0) >> 5;
                var_a0 = (temp_t0 & 0x7C00) >> 0xA;
                break;
            case 11:
                D_80055D58.unk0[arg2].unk6[4] = 0;
                return;
            case 12:
                tmp = 0x1F;
                var_t3 = arg3 - (t2[i].r - tmp);
                var_t1 = t4 - (t2[i].g - tmp);
                var_a0 = t5 - (t2[i].b - tmp);
                break;
            case 13:
                var_v0 = (temp_t0 & 0x1F) * 3;
                if (var_v0 < 0) {
                    var_v0 += 3;
                }
                var_t3 = arg3 + (var_v0 >> 2);
                var_v0 = ((temp_t0 & 0x3E0) >> 5) * 3;
                if (var_v0 < 0) {
                    var_v0 += 3;
                }
                var_t1 = t4 + (var_v0 >> 2);
                var_v0 = ((temp_t0 & 0x7C00) >> 0xA) * 3;
                if (var_v0 < 0) {
                    var_v0 += 3;
                }
                var_a0 = t5 + (var_v0 >> 2);
                break;
            default:
                var_t3 = t2[i].r + arg3;
                var_t1 = t2[i].g + t4;
                var_a0 = t2[i].b + t5;
                break;
            }

            if ((short)var_t3 >= 0x20) {
                var_t3 = 0x1F;
            }
            if ((short)var_t1 >= 0x20) {
                var_t1 = 0x1F;
            }
            if ((short)var_a0 >= 0x20) {
                var_a0 = 0x1F;
            }
            if ((var_t3 << 0x10) <= 0) {
                var_t3 = 0;
            }
            if ((var_t1 << 0x10) <= 0) {
                var_t1 = 0;
            }
            if ((var_a0 << 0x10) <= 0) {
                var_a0 = 0;
            }
            if (((var_a0 | (var_t3 | var_t1)) << 0x10) == 0) {
                var_a0 = 1;
            }
            if (arg1 != 0) {
                t2[i].rindex = ((var_t3 - t2[i].r) + 0x1F);
                t2[i].gindex = ((var_t1 - t2[i].g) + 0x1F);
                t2[i].bindex = ((var_a0 - t2[i].b) + 0x1F);
            } else {
                t2[i].b = var_a0;
                t2[i].r = var_t3;
                t2[i].g = var_t1;
                loadImageSource[arg2][i]
                    = var_t3 + (var_t1 << 5) + (var_a0 << 0xA) + (t2[i].a << 0xF);
            }
        } else {
            t2[i].bindex = 0x1F;
            t2[i].gindex = 0x1F;
            t2[i].rindex = 0x1F;
        }
    }
    if (arg1 != 0) {
        u_char* p = D_80055D58.unk0[arg2].unk6;
        p[0] = 1;
        p[1] = 0;
        p[2] = 0;
        p[3] = arg1;
        p[4] = arg0;
        if (arg0 == 9) {
            p[5] = arg3;
            p[6] = t4;
            p[7] = t5;
        }
    } else {
        D_80055D58.unk0[arg2].unk6[0] = 0;
        D_80055D58.unk0[0].unk0 = 1;
    }
}

void func_80047280(int arg0, int arg1, int arg2, short arg3, int arg4, int arg5)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        do {
            func_80046DC0(arg0, arg1, arg2, arg3, arg4, arg5);
        } while (0);
    }
}

static inline int inline_fn(int arg0) { return arg0 << 0x10; }

void func_800472D0(int arg0, D_8005DC6C_t* arg1)
{
    int sp10[5];
    int new_var;
    int i;

    if (D_80055D58.unk0[0].unk2 != 0) {
        int(*temp_t6)[6] = D_80055D58.unk7E9C;
        for (i = 0; i < 5; ++i) {
            int temp_a1, temp_t1, temp_t2;
            temp_a1 = inline_fn(arg1[i].unk0);
            temp_t1 = inline_fn(arg1[i].unk1);
            temp_t2 = inline_fn(arg1[i].unk2);

            if (arg0 != 0) {
                temp_t6[i][3]
                    = ((int)(temp_a1 - (temp_t6[i][0] & 0xFFFF0000)) / (arg0 * 2));
                temp_t6[i][4]
                    = ((int)(temp_t1 - (temp_t6[i][1] & 0xFFFF0000)) / (arg0 * 2));
                temp_t6[i][5]
                    = ((int)(temp_t2 - (temp_t6[i][2] & 0xFFFF0000)) / (arg0 * 2));
            } else {
                temp_t6[i][0] = temp_a1;
                temp_t6[i][1] = temp_t1;
                temp_t6[i][2] = temp_t2;
            }
        }
        if (arg0 != 0) {
            D_80055D58.unk7E8C[4] = 1;
            D_80055D58.unk7E8C[5] = 0;
            D_80055D58.unk7E8C[6] = 0;
            D_80055D58.unk7E8C[7] = arg0;
            return;
        }
        D_80055D58.unk7E8C[4] = 0;

        for (i = 0; i < 5; ++i) {
            int temp_a1, var_v0, var_v1;
            var_v1 = temp_t6[i][0];

            if (var_v1 < 0) {
                var_v1 += 0xFFFF;
            }

            temp_a1 = (var_v1 >> 0x10);
            var_v0 = temp_t6[i][1];

            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }

            new_var = temp_a1 + ((var_v0 >> 0x10) << 8);
            var_v1 = temp_t6[i][2];

            if (var_v1 < 0) {
                var_v1 += 0xFFFF;
            }
            sp10[i] = new_var + ((var_v1 >> 0x10) << 0x10);
        }
        func_8008EB30(sp10);
    }
}

void func_80047464(int arg0, D_8005DC6C_t* arg1)
{
    int i;

    if (D_80055D58.unk0[0].unk2 != 0) {
        func_800472D0(arg0, arg1);
        for (i = 0; i < 5; ++i) {
            D_80055D58.unk7F14[i] = arg1[i];
        }
    }
}

void func_800474DC(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int sp10[5];
    int temp_v0;
    int var_a1;
    int var_t0;
    int var_t1;
    int i;
    int(*p)[6] = D_80055D58.unk7E9C;

    for (i = 0; i < 5; ++i) {
        switch (arg0) {
        case 1:
            var_t1 = (p[i][0] / 2) + (arg2 << 0x10);
            var_t0 = p[i][1] / 2 + (arg3 << 0x10);
            var_a1 = (p[i][2] / 2) + (arg4 << 0x10);
            break;
        case 2:
            var_t1 = ((p[i][0] * 2) + (p[i][1] * 3) + p[i][2]) / 6 + (arg2 << 0x10);
            var_t0 = ((p[i][0] * 2) + (p[i][1] * 3) + p[i][2]) / 6 + (arg3 << 0x10);
            var_a1 = ((p[i][0] * 2) + (p[i][1] * 3) + p[i][2]) / 6 + (arg4 << 0x10);
            break;
        case 3:
            temp_v0 = ((p[i][0] * 2) + (p[i][1] * 3) + p[i][2]) / 12;
            var_t1 = temp_v0 + (arg2 << 0x10);
            var_t0 = temp_v0 + (arg3 << 0x10);
            var_a1 = temp_v0 + (arg4 << 0x10);
            break;
        case 4:
        case 9:
            var_t1 = (D_80055D58.unk7F14[i].unk0 + arg2) << 0x10;
            var_t0 = (D_80055D58.unk7F14[i].unk1 + arg3) << 0x10;
            var_a1 = (D_80055D58.unk7F14[i].unk2 + arg4) << 0x10;
            break;
        case 5:
            var_t1 = (D_80055D58.unk7F14[i].unk0 << 0xF) + (arg2 << 0x10);
            var_t0 = (D_80055D58.unk7F14[i].unk1 << 0xF) + (arg3 << 0x10);
            var_a1 = (D_80055D58.unk7F14[i].unk2 << 0xF) + (arg4 << 0x10);
            break;
        case 6: {
            int v1 = D_80055D58.unk7F14[i].unk1;
            int a0 = D_80055D58.unk7F14[i].unk2;
            int v0 = D_80055D58.unk7F14[i].unk0;
            var_a1 = v1 << 0x10;
            a0 <<= 0x10;
            v0 <<= 0x11;
            v1 <<= 0x11;
            v0 += v1 + var_a1;
            v0 += a0;
            var_t1 = v0 / 6 + (arg2 << 0x10);
            var_t0 = v0 / 6 + (arg3 << 0x10);
            var_a1 = v0 / 6 + (arg4 << 0x10);
        } break;
        case 7: {
            int v1 = D_80055D58.unk7F14[i].unk1;
            int a0 = D_80055D58.unk7F14[i].unk2;
            int v0 = D_80055D58.unk7F14[i].unk0;
            var_a1 = v1 << 0x10;
            a0 <<= 0x10;
            v0 <<= 0x11;
            v1 <<= 0x11;
            v0 += v1 + var_a1;
            v0 += a0;
            var_t1 = v0 / 12 + (arg2 << 0x10);
            var_t0 = v0 / 12 + (arg3 << 0x10);
            var_a1 = v0 / 12 + (arg4 << 0x10);
        } break;
        case 8:
            var_t1 = D_80055D58.unk7F14[i].unk0 << 0x10;
            var_t0 = D_80055D58.unk7F14[i].unk1 << 0x10;
            var_a1 = D_80055D58.unk7F14[i].unk2 << 0x10;
            break;
        case 11:
            D_80055D58.unk7E8C[8] = 0;
            return;
        case 0:
        default:
            var_t1 = p[i][0] + (arg2 << 0x10);
            var_t0 = p[i][1] + (arg3 << 0x10);
            var_a1 = p[i][2] + (arg4 << 0x10);
            break;
        }

        var_t1 &= 0xFFFF0000;
        var_t0 &= 0xFFFF0000;
        var_a1 &= 0xFFFF0000;

        if (var_t1 > 0xFF0000) {
            var_t1 = 0xFF0000;
        }
        if (var_t0 > 0xFF0000) {
            var_t0 = 0xFF0000;
        }
        if (var_a1 > 0xFF0000) {
            var_a1 = 0xFF0000;
        }
        if (var_t1 < 0) {
            var_t1 = 0;
        }
        if (var_t0 < 0) {
            var_t0 = 0;
        }
        if (var_a1 < 0) {
            var_a1 = 0;
        }
        if (arg1 != 0) {
            p[i][3] = (int)(var_t1 - (p[i][0] & 0xFFFF0000)) / (arg1 * 2);
            p[i][4] = (int)(var_t0 - (p[i][1] & 0xFFFF0000)) / (arg1 * 2);
            p[i][5] = (int)(var_a1 - (p[i][2] & 0xFFFF0000)) / (arg1 * 2);
        } else {
            p[i][0] = var_t1;
            p[i][1] = var_t0;
            p[i][2] = var_a1;
        }
    }

    if (arg1 != 0) {
        D_80055D58.unk7E8C[4] = 1;
        D_80055D58.unk7E8C[5] = 0;
        D_80055D58.unk7E8C[6] = 0;
        D_80055D58.unk7E8C[7] = arg1;
        D_80055D58.unk7E8C[8] = arg0;
        if (arg0 == 9) {
            D_80055D58.unk7E96[0] = arg2;
            D_80055D58.unk7E96[1] = arg3;
            D_80055D58.unk7E96[2] = arg4;
        }
    } else {
        D_80055D58.unk7E8C[4] = 0;
        for (i = 0; i < 5; ++i) {
            int temp_a1, var_v0, new_var;
            temp_v0 = p[i][0];

            if (temp_v0 < 0) {
                temp_v0 += 0xFFFF;
            }

            temp_a1 = (temp_v0 >> 0x10);
            var_v0 = p[i][1];

            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }

            new_var = temp_a1 + ((var_v0 >> 0x10) << 8);
            temp_v0 = p[i][2];

            if (temp_v0 < 0) {
                temp_v0 += 0xFFFF;
            }
            sp10[i] = new_var + ((temp_v0 >> 0x10) << 0x10);
        }
        func_8008EB30(sp10);
    }
}

void func_800478E0(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_800474DC(arg0, arg1, arg2, arg3, arg4);
    }
}

static inline int inline_fn2(int arg0)
{
    if (arg0 < 0) {
        arg0 += 0xFFFF;
    }
    return (arg0 >> 0x10) - 0x40;
}

void func_80047910(int arg0, int arg1, D_8005DC6C_t* arg2)
{
    u_char sp10[4];
    D_8005DC80_t* temp_t0;
    int temp_a1;
    int temp_t1;
    int temp_t2;
    int v0;
    int* temp_a3;

    if (D_80055D58.unk0[0].unk2 == 0) {
        return;
    }

    temp_t0 = &D_80055D58.unk7F28[arg1];
    temp_a3 = D_80055D58.unk7F28[arg1].unk10;
    temp_a1 = inline_fn(arg2->unk0);
    temp_t1 = inline_fn(arg2->unk1);
    temp_t2 = inline_fn(arg2->unk2);

    if (arg0 != 0) {
        temp_a3[3] = ((int)(temp_a1 - (temp_a3[0] & 0xFFFF0000)) / (arg0 * 2));
        temp_a3[4] = ((int)(temp_t1 - (temp_a3[1] & 0xFFFF0000)) / (arg0 * 2));
        temp_a3[5] = ((int)(temp_t2 - (temp_a3[2] & 0xFFFF0000)) / (arg0 * 2));
    } else {
        temp_a3[0] = temp_a1;
        temp_a3[1] = temp_t1;
        temp_a3[2] = temp_t2;
    }
    if (arg0 != 0) {
        temp_t0->unk0[0] = 1;
        temp_t0->unk0[1] = 0;
        temp_t0->unk0[2] = 0;
        temp_t0->unk0[3] = arg0;
        return;
    }
    temp_t0->unk0[0] = 0;

    v0 = temp_a3[0];
    if (v0 < 0) {
        v0 += 0xFFFF;
    }
    sp10[0] = (v0 >> 0x10) - 0x40;

    v0 = temp_a3[1];
    if (v0 < 0) {
        v0 += 0xFFFF;
    }
    sp10[1] = (v0 >> 0x10) - 0x40;

    sp10[2] = inline_fn2(temp_a3[2]);
    sp10[3] = 0;

    if (arg1 != 0) {
        func_800A0768(arg1 - 1, sp10);
    } else {
        func_8008B430(sp10, temp_t0->unk6[3] >> 2);
    }
}

static void func_80047AB4(int arg0, int arg1, D_8005DC6C_t* arg2)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80047910(arg0, arg1, arg2);
        D_80055D58.unk7F28[arg1].unk28 = *arg2;
    }
}

void func_80047B30(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    u_char sp10[4];
    short var_t4;
    int var_a1;
    int var_a2;
    int var_t0;
    int var_v0;
    int var_v1;
    D_8005DC80_t* t1 = &D_80055D58.unk7F28[arg2];
    int* t2 = t1->unk10;

    var_t4 = 0;
    switch (arg0) {
    case 1:
        var_a1 = (t2[0] / 2) + (arg3 << 16);
        var_t0 = (t2[1] / 2) + (arg4 << 16);
        var_a2 = (t2[2] / 2) + (arg5 << 16);
        break;
    case 2:
        var_t4 = 0x4000;
        var_a1 = ((t2[0] * 2) + (t2[1] * 3) + t2[2]) / 6 + (arg3 << 0x10);
        var_t0 = ((t2[0] * 2) + (t2[1] * 3) + t2[2]) / 6 + (arg4 << 0x10);
        var_a2 = ((t2[0] * 2) + (t2[1] * 3) + t2[2]) / 6 + (arg5 << 0x10);
        break;
    case 3:
        var_t4 = 0x4000;
        var_v1 = ((t2[0] * 2) + (t2[1] * 3) + t2[2]) / 12;
        var_a1 = var_v1 + (arg3 << 0x10);
        var_t0 = var_v1 + (arg4 << 0x10);
        var_a2 = var_v1 + (arg5 << 0x10);
        break;
    case 4:
    case 9:
        var_a1 = (t1->unk28.unk0 + arg3) << 0x10;
        var_t0 = (t1->unk28.unk1 + arg4) << 0x10;
        var_a2 = (t1->unk28.unk2 + arg5) << 0x10;
        break;
    case 5:
        var_t4 = 0x4000;
        var_a1 = (t1->unk28.unk0 << 0xF) + (arg3 << 0x10);
        var_t0 = (t1->unk28.unk1 << 0xF) + (arg4 << 0x10);
        var_a2 = (t1->unk28.unk2 << 0xF) + (arg5 << 0x10);
        break;
    case 6:
        var_t4 = 0x4000;
        {
            int v1 = t1->unk28.unk1;
            int a0 = t1->unk28.unk2;
            int v0 = t1->unk28.unk0;
            var_a2 = v1 << 0x10;
            a0 <<= 0x10;
            v0 <<= 0x11;
            v1 <<= 0x11;
            v0 += v1 + var_a2;
            v0 += a0;
            var_a1 = v0 / 6 + (arg3 << 0x10);
            var_t0 = v0 / 6 + (arg4 << 0x10);
            var_a2 = v0 / 6 + (arg5 << 0x10);
        }
        break;
    case 7:
        var_t4 = 0x4000;
        {
            int v1 = t1->unk28.unk1;
            int a0 = t1->unk28.unk2;
            int v0 = t1->unk28.unk0;
            var_a2 = v1 << 0x10;
            a0 <<= 0x10;
            v0 <<= 0x11;
            v1 <<= 0x11;
            v0 += v1 + var_a2;
            v0 += a0;
            var_a1 = v0 / 12 + (arg3 << 0x10);
            var_t0 = v0 / 12 + (arg4 << 0x10);
            var_a2 = v0 / 12 + (arg5 << 0x10);
        }
        break;
    case 8:
    case 15:
        var_a1 = t1->unk28.unk0 << 0x10;
        var_t0 = t1->unk28.unk1 << 0x10;
        var_a2 = t1->unk28.unk2 << 0x10;
        break;
    case 11:
        t1->unk0[4] = 0;
        return;
    default:
        var_a1 = t2[0] + (arg3 << 0x10);
        var_t0 = t2[1] + (arg4 << 0x10);
        var_a2 = t2[2] + (arg5 << 0x10);
        break;
    }
    var_a1 = var_a1 & 0xFFFF0000;
    var_t0 = var_t0 & 0xFFFF0000;
    var_a2 = var_a2 & 0xFFFF0000;

    if (var_a1 > 0x800000) {
        var_a1 = 0x800000;
    }
    if (var_t0 > 0x800000) {
        var_t0 = 0x800000;
    }
    if (var_a2 > 0x800000) {
        var_a2 = 0x800000;
    }
    if (var_a1 < 0) {
        var_a1 = 0;
    }
    if (var_t0 < 0) {
        var_t0 = 0;
    }
    if (var_a2 < 0) {
        var_a2 = 0;
    }
    if (arg1 != 0) {
        t2[3] = ((int)(var_a1 - (t2[0] & 0xFFFF0000)) / (arg1 * 2));
        t2[4] = ((int)(var_t0 - (t2[1] & 0xFFFF0000)) / (arg1 * 2));
        t2[5] = ((int)(var_a2 - (t2[2] & 0xFFFF0000)) / (arg1 * 2));
        t1->unk6[4] = ((var_t4 - t1->unk6[3]) / (arg1 * 2));
    } else {
        t2[0] = var_a1;
        t2[1] = var_t0;
        t2[2] = var_a2;
        t1->unk6[3] = var_t4;
    }
    var_v0 = 1;
    if (arg1 != 0) {
        t1->unk0[0] = 1;
        t1->unk0[1] = 0;
        t1->unk0[2] = 0;
        t1->unk0[3] = arg1;
        t1->unk0[4] = arg0;
        if (arg0 == 9) {
            t1->unk6[0] = arg3;
            t1->unk6[1] = arg4;
            t1->unk6[2] = arg5;
        }
    } else {
        t1->unk0[0] = 0;
        var_v0 = t2[0] >> 0x10;
        if (t2[0] < 0) {
            var_v1 = t2[0] + 0xFFFF;
            var_v0 = var_v1 >> 0x10;
        }
        sp10[0] = var_v0 - 0x40;
        var_v0 = t2[1] >> 0x10;
        if (t2[1] < 0) {
            var_v1 = t2[1] + 0xFFFF;
            var_v0 = var_v1 >> 0x10;
        }
        sp10[1] = var_v0 - 0x40;
        var_v0 = t2[2] >> 0x10;
        if (t2[2] < 0) {
            var_v1 = t2[2] + 0xFFFF;
            var_v0 = var_v1 >> 0x10;
        }
        sp10[2] = var_v0 - 0x40;
        sp10[3] = 0;
        if (arg2 != 0) {
            func_800A0768(arg2 - 1, sp10);
        } else {
            func_8008B430(sp10, ((u_short)t1->unk6[3] << 0x10) >> 0x12);
        }
    }
}

static void func_80047FC0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80047B30(arg0, arg1, arg2, arg3, arg4, arg5);
    }
}

void func_80047FFC()
{
    int sp18[5];
    int i;
    int var_v0;
    int new_var;
    int new_var2;
    int var_v1;
    int(*t1)[6];

    if (D_80055D58.unk7E8C[4] == 0) {
        return;
    }

    t1 = D_80055D58.unk7E9C;

    for (i = 0; i < 5; ++i) {
        t1[i][0] += t1[i][3];
        t1[i][1] += t1[i][4];
        t1[i][2] += t1[i][5];
    }

    for (i = 0; i < 5; ++i) {
        var_v1 = t1[i][0];
        if (var_v1 < 0) {
            var_v1 += 0xFFFF;
        }
        var_v0 = t1[i][1];
        new_var2 = var_v1 >> 16;
        if (var_v0 < 0) {
            var_v0 += 0xFFFF;
        }
        var_v1 = t1[i][2];
        new_var = new_var2 + ((var_v0 >> 16) << 8);
        if (var_v1 < 0) {
            var_v1 += 0xFFFF;
        }
        sp18[i] = new_var + ((var_v1 >> 16) << 16);
    }
    func_8008EB30(sp18);
    D_80055D58.unk7E8C[5] += 1;
    if (D_80055D58.unk7E8C[5] >= (D_80055D58.unk7E8C[7] * 2)) {
        if (D_80055D58.unk7E8C[8] == 9) {
            func_800474DC(4, D_80055D58.unk7E8C[7], D_80055D58.unk7E96[0] / 2,
                D_80055D58.unk7E96[1] / 2, D_80055D58.unk7E96[2] / 2);
            D_80055D58.unk7E8C[8] = 10;
            return;
        }
        if (D_80055D58.unk7E8C[8] == 10) {
            func_800474DC(9, D_80055D58.unk7E8C[7], D_80055D58.unk7E96[0],
                D_80055D58.unk7E96[1], D_80055D58.unk7E96[2]);
            D_80055D58.unk7E8C[8] = 9;
            return;
        }
        D_80055D58.unk7E8C[4] = 0;
    }
}

void func_800481C0()
{
    u_char sp18[4];
    int i;
    int var_v0;
    D_8005DC80_t* p = D_80055D58.unk7F28;

    for (i = 0; i < 17; ++i) {
        int* a2 = p[i].unk10;
        if (p[i].unk0[0] != 0) {
            a2[0] += a2[3];
            a2[1] += a2[4];
            a2[2] += a2[5];

            var_v0 = a2[0];
            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }
            sp18[0] = (var_v0 >> 16) - 0x40;
            var_v0 = a2[1];
            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }
            sp18[1] = (var_v0 >> 16) - 0x40;
            var_v0 = a2[2];
            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }
            sp18[2] = (var_v0 >> 16) - 0x40;
            sp18[3] = 0;

            if (i != 0) {
                func_800A0768(i - 1, sp18);
            } else {
                p[0].unk6[3] += p[0].unk6[4];
                func_8008B430(sp18, p[0].unk6[3] >> 2);
            }
            ++p[i].unk0[1];
            if (p[i].unk0[1] >= (p[i].unk0[3] * 2)) {
                if (p[i].unk0[4] == 9) {
                    func_80047FC0(4, p[i].unk0[3], i, p[i].unk6[0] / 2, p[i].unk6[1] / 2,
                        p[i].unk6[2] / 2);
                    p[i].unk0[4] = 10;
                } else if (p[i].unk0[4] == 10) {
                    func_80047B30(
                        9, p[i].unk0[3], i, p[i].unk6[0], p[i].unk6[1], p[i].unk6[2]);
                    p[i].unk0[4] = 9;
                } else if (p[i].unk0[4] == 14) {
                    func_80047B30(15, p[i].unk0[3], i, 0, 0, 0);
                    p[i].unk0[4] = 15;
                } else {
                    p[i].unk0[0] = 0;
                }
            }
        }
    }
}

void func_800483FC()
{
    int i;
    int j;
    u_int var_t5;
    u_short g;
    u_short r;
    u_short b;
    struct ColorInfo* index;
    int c;

    for (i = 0; i < 14; ++i) {
        if (D_80055D58.unk0[i].unk6[0] == 0) {
            continue;
        }
        if (++D_80055D58.unk0[i].unk6[2] >= (D_80055D58.unk0[i].unk6[3] / 8)) {

            D_80055D58.unk0[i].unk6[2] = 0;

            if (D_80055D58.unk0[i].unk6[3] >= 8) {
                var_t5 = 1;
                c = D_80055D58.unk0[i].unk6[1];
                index = D_80055D58.unk0[i].unkE;
                for (j = 0; j < 256; ++j) {
                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }
                    r = index[j].r + _animOffset16[index[j].rindex][c];
                    g = index[j].g + _animOffset16[index[j].gindex][c];
                    b = index[j].b + _animOffset16[index[j].bindex][c];
                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }
                    index[j].g = g;
                    index[j].b = b;
                    index[j].r = r;
                    loadImageSource[i][j] = r + (g << 5) + (b << 10) + (index[j].a << 15);
                }
            } else if (D_80055D58.unk0[i].unk6[3] >= 4) {
                var_t5 = 2;
                c = D_80055D58.unk0[i].unk6[1];
                index = D_80055D58.unk0[i].unkE;
                for (j = 0; j < 256; ++j) {
                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }
                    r = index[j].r + _animOffset8[index[j].rindex][c];
                    g = index[j].g + _animOffset8[index[j].gindex][c];
                    b = index[j].b + _animOffset8[index[j].bindex][c];
                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }
                    index[j].r = r;
                    index[j].g = g;
                    index[j].b = b;
                    loadImageSource[i][j] = r + (g << 5) + (b << 10) + (index[j].a << 15);
                }
            } else if (D_80055D58.unk0[i].unk6[3] >= 2) {
                var_t5 = 4;
                c = D_80055D58.unk0[i].unk6[1];
                index = D_80055D58.unk0[i].unkE;
                for (j = 0; j < 256; ++j) {
                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }
                    r = index[j].r + _animOffset4[index[j].rindex][c];
                    g = index[j].g + _animOffset4[index[j].gindex][c];
                    b = index[j].b + _animOffset4[index[j].bindex][c];
                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }
                    index[j].r = r;
                    index[j].g = g;
                    index[j].b = b;
                    loadImageSource[i][j] = r + (g << 5) + (b << 10) + (index[j].a << 15);
                }
            } else {
                var_t5 = 8;
                c = D_80055D58.unk0[i].unk6[1];
                index = D_80055D58.unk0[i].unkE;
                for (j = 0; j < 256; ++j) {
                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }
                    r = index[j].r + _animOffset2[index[j].rindex][c];
                    g = index[j].g + _animOffset2[index[j].gindex][c];
                    b = index[j].b + _animOffset2[index[j].bindex][c];
                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }
                    index[j].r = r;
                    index[j].g = g;
                    index[j].b = b;
                    loadImageSource[i][j] = r + (g << 5) + (b << 10) + (index[j].a << 15);
                }
            }
            if (++D_80055D58.unk0[i].unk6[1] >= (16 / var_t5)) {
                if (D_80055D58.unk0[i].unk6[4] == 9) {
                    func_80046DC0(4, D_80055D58.unk0[i].unk6[3], i,
                        D_80055D58.unk0[i].unkB[0] / 2, D_80055D58.unk0[i].unkB[1] / 2,
                        D_80055D58.unk0[i].unkB[2] / 2);
                    D_80055D58.unk0[i].unk6[4] = 10;
                } else if (D_80055D58.unk0[i].unk6[4] == 10) {
                    func_80046DC0(9, D_80055D58.unk0[i].unk6[3], i,
                        D_80055D58.unk0[i].unkB[0], D_80055D58.unk0[i].unkB[1],
                        D_80055D58.unk0[i].unkB[2]);
                    D_80055D58.unk0[i].unk6[4] = 9;
                } else if (D_80055D58.unk0[i].unk6[4] == 14) {
                    func_80046DC0(15, D_80055D58.unk0[i].unk6[3], i, 0, 0, 0);
                    D_80055D58.unk0[i].unk6[4] = 15;
                } else {
                    D_80055D58.unk0[i].unk6[0] = 0;
                }
            }
        }
        D_80055D58.unk0[0].unk0 = 1;
    }
}

static void func_80048A3C(int arg0) { D_80055D58.unk0[arg0].unk6[0] = 0; }

void func_80048A64(u_short* img, u_int y, u_int x, u_int w)
{
    RECT rect;
    u_short px;
    u_int i;
    struct ColorInfo* dst;

    if (y >= 14) {
        setRECT(&rect, x + 768, y + 224, w, 1);
        LoadImage(&rect, (u_long*)img);
        return;
    }

    if (D_80055D58.unk0[y].unk5 == 0) {
        D_80055D58.unk0[y].unk6[0] = 0;
        for (i = 0; i < w; ++i) {
            px = img[i];
            dst = &D_80055D58.unk0[y].unkE[x + i];
            loadImageSource[y][x + i] = px;
            D_80055D58.unk0[y].unk70E[x + i] = px;
            dst->r = (px & 0x1F);
            dst->g = ((px & 0x3E0) >> 5);
            dst->b = ((px & 0x7C00) >> 10);
            dst->a = ((px & 0x8000) >> 15);
        }
        D_80055D58.unk0[0].unk0 = 1;
    }
}

void func_80048B8C(
    int arg0, u_short* arg1, int arg2, short arg3, short arg4, short arg5, int arg6)
{
    int i;
    int new_var;
    int new_var2;
    int new_var3;
    short r;
    short g;
    short b;
    short a;
    u_short t4;

    for (i = 0; i < 0x100; ++i) {
        a = arg1[i];
        if (a != 0) {
            switch (arg0) {
            case 5:
                t4 = 0x1F;
                r = arg3 + ((((u_char)a) & t4) >> 1);
                g = arg4 + ((a & 0x3E0) >> 6);
                b = arg5 + ((a & 0x7C00) >> 11);
                break;

            case 6:
                new_var = a & 0x1F;
                new_var2 = (a & 0x3E0) >> 5;
                new_var3 = (a & 0x7C00) >> 10;
                r = arg3 + ((new_var * 2) + (new_var2 * 3) + new_var3) / 6;
                g = arg4 + ((new_var * 2) + (new_var2 * 3) + new_var3) / 6;
                b = arg5 + ((new_var * 2) + (new_var2 * 3) + new_var3) / 6;
                break;

            case 7:
                new_var = a & 0x1F;
                new_var2 = (a & 0x3E0) >> 5;
                new_var3 = (a & 0x7C00) >> 10;
                r = arg3 + ((new_var * 2) + (new_var2 * 3) + new_var3) / 12;
                g = arg4 + ((new_var * 2) + (new_var2 * 3) + new_var3) / 12;
                b = arg5 + ((new_var * 2) + (new_var2 * 3) + new_var3) / 12;
                break;

            case 0:
            default:
                r = arg3 + (a & 0x1F);
                g = arg4 + ((a & 0x3E0) >> 5);
                b = arg5 + ((a & 0x7C00) >> 10);
                break;
            }

        } else {
            r = a & 0x1F;
            t4 = (a & 0x3E0);
            g = t4 >> 5;
            b = (a & 0x7C00) >> 10;
        }
        t4 = a;
        t4 = t4 >> 15;
        if (r >= 32) {
            r = 31;
        }
        if (g >= 32) {
            g = 31;
        }
        if (b >= 32) {
            b = 31;
        }
        if ((r << 16) < 1) {
            r = 0;
        }
        if ((g << 16) <= 0) {
            g = 0;
        }
        if ((b << 16) <= 0) {
            b = 0;
        }
        if ((((r | g | b) << 16) == 0) && (a & 0x7FFF)) {
            b = 1;
        }
        if (arg6 != 0) {
            loadImageSource[arg2][i] = r + (g << 5) + (b << 10) + (t4 << 15);
            if (D_80055D58.unk0[arg2].unk6[0] == 0) {
                struct ColorInfo* t5 = &D_80055D58.unk0[arg2].unkE[i];
                t5->r = r;
                t5->g = g;
                t5->b = b;
                t5->a = t4;
            }
        }
        D_80055D58.unk0[arg2].unk70E[i] = r + (g << 5) + (b << 10) + (t4 << 15);
    }

    D_80055D58.unk0[0].unk0 = 1;
}

void func_80048E68(
    u_short* arg0, int arg1, u_short arg2, u_short arg3, u_short arg4, int arg5)
{
    func_80048B8C(8, arg0, arg1, arg2, arg3, arg4, arg5);
}

void func_80048EC4()
{
    int i;
    int var_v0;
    u_int* var_v1;
    int(*p)[6] = D_80055D58.unk7E9C;

    var_v1 = func_8008EB24();
    for (i = 0; i < 5; ++i) {
        D_80055D58.unk7F14[i].unk0 = var_v1[i];
        var_v0 = var_v1[i] & 0xFF00;
        if (var_v0 < 0) {
            var_v0 += 0xFF;
        }
        D_80055D58.unk7F14[i].unk1 = (var_v0 >> 8);
        var_v0 = var_v1[i] & 0xFF0000;
        if (var_v0 < 0) {
            var_v0 += 0xFFFF;
        }
        D_80055D58.unk7F14[i].unk2 = (var_v0 >> 16);
        p[i][0] = ((var_v1[i] & 0xFF) << 16);
        p[i][1] = ((var_v1[i] & 0xFF00) << 8);
        p[i][2] = (var_v1[i] & 0xFF0000);
    }
}

static void func_80048F8C()
{
    RECT rect;

    if (D_80055D58.unk0[0].unk0 != 0) {
        setRECT(&rect, 768, 224, 256, 14);
        LoadImage(&rect, (u_long*)loadImageSource[0]);
        D_80055D58.unk0[0].unk0 = 0;
    }
}

static void func_80048FEC(short arg0) { D_80055D58.unk0[0].unk2 = arg0; }

void func_80048FF8()
{
    int i;

    D_80055D58.unk0[0].unk0 = 0;
    D_80055D58.unk0[0].unk2 = 1;
    for (i = 0; i < 14; ++i) {
        D_80055D58.unk0[i].unk5 = 0;
        D_80055D58.unk0[i].unk6[0] = 0;
        D_80055D58.unk0[i].unk6[4] = 0;
    }

    D_80055D58.unk7E8C[4] = 0;
    D_80055D58.unk7E8C[8] = 0;

    for (i = 0; i < 17; ++i) {
        D_80055D58.unk7F28[i].unk0[0] = 0;
        D_80055D58.unk7F28[i].unk0[4] = 0;
        D_80055D58.unk7F28[i].unk6[3] = 0;
        *((int*)&D_80055D58.unk7F28[i].unk28) = 0x404040;
        D_80055D58.unk7F28[i].unk10[2] = 0x400000;
        D_80055D58.unk7F28[i].unk10[1] = 0x400000;
        D_80055D58.unk7F28[i].unk10[0] = 0x400000;
    }
}

static void _asmNop() { __asm__(".nop;"); }

void nop9(int arg0 __attribute__((unused)), int arg1 __attribute__((unused))) { }

static void nop10(int arg0 __attribute__((unused)), int arg1 __attribute__((unused))) { }

static void nop11() { }

void vs_main_memcpy(void* dest, void* src, u_int sz)
{
    __asm__("srl $t0, %2, 4;"
            "beqz $t0, 1f;"
            "and $t5, %2, 12;"
            "0:"
            "lw $t1, 0(%1);"
            "lw $t2, 4(%1);"
            "lw $t3, 8(%1);"
            "lw $t4, 12(%1);"
            "addu $t0, -1;"
            "sw $t1, 0(%0);"
            "sw $t2, 4(%0);"
            "sw $t3, 8(%0);"
            "sw $t4, 12(%0);"
            "addu %1, 16;"
            "bnez $t0, 0b;"
            "addu %0, 16;"
            "beqz $t5, 2f;"
            "1:"
            "lw $t1, 0(%1);"
            "addu $t5, -4;"
            "sw $t1, 0(%0);"
            "addu %1, 4;"
            "bnez $t5, 1b;"
            "addu %0, 4;"
            "2:" ::"r"(dest),
        "r"(src), "r"(sz));
}

void vs_main_bzero(void* dest, int sz)
{
    __asm__("and $t0, %1, 0xFFFC;"
            "beqz $t0, 1f;"
            "0:"
            "sw $0, 0(%0);"
            "addu $t0, -4;"
            "bnez $t0, 0b;"
            "addu %0, 4;"
            "1:" ::"r"(dest),
        "r"(sz));
}

static void nop12() { }
