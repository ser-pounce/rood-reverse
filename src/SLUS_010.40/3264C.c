#include "3264C.h"
#include "common.h"
#include "overlays.h"
#include "../BATTLE/BATTLE.PRG/battle.h"
#include <libapi.h>
#include <libds.h>
#include <libetc.h>
#include <libpad.h>
#include <libsnd.h>
#include <libspu.h>
#include <libgpu.h>
#include <rand.h>

typedef struct HeapHeader {
    struct HeapHeader* prev;
    struct HeapHeader* next;
    unsigned int blockSz;
    int unkC;
} HeapHeader;

typedef struct {
    char unk0;
    char exId;
    char unk2;
    char unk3;
    char unk4;
    char unk5;
    char unk6;
    char lock;
    unsigned char actData[2];
    char connected;
} PortInfo;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
} LoadImage_t;

typedef struct {
    int unk0[2];
    unsigned short unk8;
    unsigned short unkA;
    unsigned char* unkC;
    int unk10[10];
} D_80050118_t;

typedef struct {
    int offset;
    unsigned int unk4;
    int unk8;
    union {
        struct {
            short unkC;
            char unkE;
            unsigned char unkF[1];
        } unkC_s;
        unsigned int unkC_i;
    } unkC_u;
    unsigned char unk10[2];
    unsigned int unk14[4];
    void* unk24[4];
    vs_main_cdQueue_t* unk34[4];
    unsigned int unk44;
    char unk48[4];
    void* unk4C[3];
    vs_main_cdQueue_t* unk58[3];
    void* unk64[3];
    int* unk70[3];
    int fileId;
    void* unk80;
    vs_main_cdQueue_t* unk84;
} D_8005E038_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
} D_8005DC6C_t;

typedef struct {
    char unk0[6];
    short unk6[5];
    int unk10[6];
    D_8005DC6C_t unk28;
} D_8005DC80_t;

typedef struct {
    struct {
        unsigned short unk0;
        unsigned short unk2;
        unsigned char unk4;
        unsigned char unk5;
        unsigned char unk6[8];
        unsigned char unkE[256][7];
        unsigned short unk70E[254];
    } unk0[14];
    char unk7E8C[10];
    short unk7E96[3];
    int unk7E9C[5][6];
    D_8005DC6C_t unk7F14[5];
    D_8005DC80_t unk7F28[17];
} D_80055D58_t;

typedef struct {
    char status;
    unsigned char unk1;
    char unk2;
    char unk3;
    unsigned int unk4;
    unsigned int unk8;
    int cdSector;
    int sectorCount;
    void* vram;
    DslFILTER pcm;
    DslLOC cdLoc;
    int commandId;
    int unk24;
    int unk28;
    unsigned int unk2C;
    unsigned int bufIndex;
    int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    int unk44;
} D_80055D10_t;

typedef union {
    short s[0];
    int i;
} u_1632;

typedef struct {
    unsigned short unk0;
    unsigned short unk2;
    unsigned short unk4[4];
    unsigned short unkC[8];
} D_80060068_t2;

typedef struct {
    int unk0;
    short unk4[12];
    int unk1C;
    char unk20[8];
    D_80060068_t2 unk28[6];
    int unk7C[24];
} D_80060068_t;

typedef struct D_80061068_t {
    unsigned short unk0[6];
} D_80061068_t;

void __main();
void displayLoadingScreen();
static void func_80042998();
static void func_80042A64();
static void do_wait();
static void padForceMode();
static void padResetDefaults(int, void*);
static void padConnect(int, void*);
static void padSetActData(int arg0, int arg1, int arg2);
static int getCdStatus();
void func_80042CB0();
static void func_80043668();
static void vs_main_initCdQueue();
static void func_80044A60();
static void func_80044BF4(vs_main_cdQueue_t*, void*);
static void func_80044C74();
static int func_80045440(int arg0);
static void func_800455F4();
void func_80045754(int, int, int, int);
static void func_800461CC(int, unsigned int[], unsigned int, int, int);
static int func_800464FC(int, int, int);
static void func_80046678(int);
static void func_80046770();
static int func_800467A0();
void func_800468FC();
void func_80046B3C(int, int, unsigned short*);
void func_80047910(int, int, D_8005DC6C_t*);
static void func_8004908C();
static void nop9(int, int);
static void nop10(int, int);
void func_8006A5C0();
int titlePrgMain();
void execBattle();
static void initRand();
static void initHeap(HeapHeader* node, unsigned int value);

extern unsigned char D_8004B1B0[];
extern int D_8004B9DC[];
#define RANDARRSZ 97
extern int randArr[RANDARRSZ];
extern HeapHeader* D_80050110;
extern D_80050118_t D_80050118[2];
extern PortInfo portInfo[2];
extern HeapHeader heapA;
extern HeapHeader heapB;
extern int randIndex;
extern DslLOC cdReadLoc;
extern int D_800501CC;
extern int D_800501D0;
extern int D_800501D4;
extern int D_800501D8;
extern vs_main_cdQueue_t vs_main_cdQueue[32];
extern u_1632 D_80050460;
extern int D_80050470;
extern int D_80050478[];
extern int sp2;
extern int D_80055C88;
extern int D_80055C90[];
extern D_80055D10_t D_80055D10;
extern unsigned char dsControlBuf[11];
extern D_80055D58_t D_80055D58;
extern int sp;
extern unsigned char padBuffer[2][34];
extern char D_8005DBE8;
extern int D_8005DBF4[5][6];
extern D_8005E038_t D_8005E038;
extern int D_8005E03C;
extern void* D_8005E08C;
extern int D_8005E0BC;
extern unsigned int frameDuration;
extern int D_8005E214;
extern int D_8005E240;
extern int D_8005E248;
extern int D_8005E24C;
extern unsigned short loadImageSource[][256];
extern int D_8005FE70;
extern int D_8005FE74;
extern int D_8005FE78;
extern int D_8005FE7C;
extern int D_8005FE80;
extern int D_8005FE84;
extern char D_8005FFB8[];
extern D_80060068_t D_80060068;
extern D_80061068_t D_80061068;
extern char D_80061074[4];
extern MATRIX D_1F800014_mat;

typedef struct {
    unsigned char wLo;
    unsigned char wHi;
    unsigned char hLo;
    unsigned char hHi;
} ImgHeader;

void* debug_stack_p = (void*)0x200000;
unsigned int debug_stack_sz = 0x4000;
char buildTimestamp[] = "Mar 28 00:09\0\0\0";

EMBED_RGBA16("build/assets/SLUS_010.40/nowLoading.rgba16.bin", nowLoading)

static unsigned char D_8004A504[]
    = { 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x07, 0x06, 0x00, 0x04, 0x01,
          0x00, 0x00, 0x01, 0x11, 0x08, 0x02, 0x06, 0xFF, 0x00, 0x00, 0x00 };

static unsigned char actParams[] = { 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

extern int fileLBAs[];
extern int fileSizes[];
extern int D_8004A9E0[];
extern int D_8004B020[];
extern int D_8004A6C0[];
extern int D_8004AD00[];

static void loadBattlePrg()
{
    CdFile cdFile;
    vs_main_cdQueue_t* temp_v0;

    cdFile.lba = 0x44C; // BATTLE.PRG
    cdFile.size = 0x8D800;
    temp_v0 = func_80044B10(&cdFile);
    func_80044BF4(temp_v0, overlaySlots[0]);

    while (temp_v0->unk0[0] != 4) {
        func_8004261C(0);
    }

    func_80044B80(temp_v0);

    cdFile.lba = 0x567; // INITBTL.PRG
    cdFile.size = 0x2000;
    temp_v0 = func_80044B10(&cdFile);
    func_80044BF4(temp_v0, overlaySlots[1]);

    while (temp_v0->unk0[0] != 4) {
        func_8004261C(0);
    }

    func_80044B80(temp_v0);
    do_wait();
}

static void loadTitlePrg()
{
    CdFile cdFile;
    vs_main_cdQueue_t* temp_v0;

    cdFile.lba = 0x3E800; // TITLE.PRG
    cdFile.size = 0x87800;

    temp_v0 = func_80044B10(&cdFile);
    func_80044BF4(temp_v0, overlaySlots[0]);

    while (temp_v0->unk0[0] != 4) {
        func_8004261C(0);
    }

    func_80044B80(temp_v0);
    do_wait();
}

static void loadEndingPrg()
{
    CdFile cdFile;
    vs_main_cdQueue_t* temp_v0;

    cdFile.lba = 0x41AC8; // ENDING.PRG
    cdFile.size = 0x74000;

    temp_v0 = func_80044B10(&cdFile);
    func_80044BF4(temp_v0, overlaySlots[0]);

    while (temp_v0->unk0[0] != 4) {
        func_8004261C(0);
    }

    func_80044B80(temp_v0);
    do_wait();
}

static void initScreen(int w, int h, int arg2 __attribute__((unused)),
    __attribute__((unused)) int arg3, __attribute__((unused)) int arg4,
    __attribute__((unused)) int arg5)
{
    SetDefDispEnv(dispEnv, 0, 0, w, h - 0x10);
    setRECT(&dispEnv[0].screen, 0, 8, 0x100, 0xE0);
    PutDispEnv(dispEnv);
}

#define IMG_W(header) (header.wLo + (header.wHi << 8))
#define IMG_H(header) (header.hLo + (header.hHi << 8))

void displayLoadingScreen()
{
    RECT rect;

    initScreen(0x140, 0xF0, D_8005E248, 0, 0, 0);
    setRECT(&rect, 0, 0, 1024, 512);
    ClearImage2(&rect, 0U, 0U, 0U);
    DrawSync(0);
    VSync(2);
    setRECT(&rect, (320 - IMG_W(nowLoading_header)) / 2,
        (224 - IMG_H(nowLoading_header)) / 2, IMG_W(nowLoading_header),
        IMG_H(nowLoading_header));
    LoadImage(&rect, (unsigned long*)&nowLoading_header + 1);
    setRECT(&rect, ((320 - IMG_W(nowLoading_header)) / 2) + 320,
        (224 - IMG_H(nowLoading_header)) / 2, IMG_W(nowLoading_header),
        IMG_H(nowLoading_header));
    LoadImage(&rect, (unsigned long*)&nowLoading_header + 1);
    DrawSync(0);
    SetDispMask(1);
}

static void bufferLoadingScreen()
{
    RECT rect;

    if (frameBuf != 0) {
        setRECT(&rect, (320 - IMG_W(nowLoading_header)) / 2,
            (224 - IMG_H(nowLoading_header)) / 2, IMG_W(nowLoading_header),
            IMG_H(nowLoading_header));
    } else {
        setRECT(&rect, (320 - IMG_W(nowLoading_header)) / 2 + 320,
            (224 - IMG_H(nowLoading_header)) / 2, IMG_W(nowLoading_header),
            IMG_H(nowLoading_header));
    }
    LoadImage(&rect, nowLoading_data);
    DrawSync(0);
}

static void resetGame()
{
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    while (DsControlB(DslPause, NULL, NULL) == 0)
        ;
    DsFlush();
    padSetActData(0, 0, 0);
    padSetActData(0, 1, 0);
    padConnect(0, padBuffer[0]);
    padConnect(0x10, padBuffer[1]);
    vs_sound_Shutdown();
    SpuQuit();
    ResetGraph(3);
    VSync(0xA);
    jumpToTitle(&sp2);
}

static void func_80042420()
{
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    padSetActData(0, 0, 0);
    padSetActData(0, 1, 0);
    padConnect(0, padBuffer[0]);
    padConnect(0x10, padBuffer[1]);
    ResetGraph(3);
    func_80012B78();
    func_80012B98();
    func_80012024();
    func_80012EBC();
    displayLoadingScreen();
    loadBattlePrg();
    D_80050470 = 1;
    jumpToBattle(&sp);
}

static void func_800424E4()
{
    D_8005E240 = 0;
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    padSetActData(0, 0, 0);
    padSetActData(0, 1, 0);
    padConnect(0, padBuffer);
    padConnect(0x10, padBuffer[1]);
    ResetGraph(3);
    func_80012B78();
    func_80012B98();
    func_80042CB0();
    loadEndingPrg();
    func_8006A5C0();
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    padSetActData(0, 0, 0);
    padSetActData(0, 1, 0);
    padConnect(0, padBuffer);
    padConnect(0x10, padBuffer[1]);
    vs_sound_Shutdown();
    SpuQuit();
    ResetGraph(3);
    D_8005E214 = 1;
    jumpToTitle(&sp2);
}

int func_8004261C(int arg0)
{
    char new_var4;
    char new_var3;
    int temp_s1;

    temp_s1 = VSync(arg0);
    if (arg0 != 1) {
        func_8004908C();
    }

    func_80044C74();
    new_var4 = D_80061074[3];

    if (((new_var4 << 24) >> 24) >= 100) {
        return temp_s1;
    }

    D_80061074[0] += D_8005E24C;
    new_var3 = D_80061074[0];

    if (((new_var3 << 24) >> 24) < 60) {
        return temp_s1;
    }

    D_80061074[0] = 0;

    if ((((++D_80061074[1]) << 24) >> 24) < 60) {
        return temp_s1;
    }

    D_80061074[1] = 0;

    if ((((++D_80061074[2]) << 24) >> 24) < 60) {
        return temp_s1;
    }

    D_80061074[2] = 0;

    if ((((++D_80061074[3]) << 24) >> 24) >= 100) {
        D_80061074[3] = 100;
    }
    return temp_s1;
}

static void gpuSyncVoidCallback() { }

static void vSyncVoidCallback() { }

static void nop0() { }

static void nop1() { }

static void nop2() { }

static void nop3() { }

static void initRand()
{
    int i;

    srand(1);

    for (i = 0; i < RANDARRSZ; ++i) {
        randArr[i] = rand();
    }
    randIndex = RANDARRSZ - 1;
}

static int getRand(int arg0)
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

static int getRands(int arg0)
{
    return (getRand(arg0) + getRand(arg0) + getRand(arg0) + getRand(arg0) + getRand(arg0)
               + getRand(arg0) + getRand(arg0) + getRand(arg0) + getRand(arg0)
               + getRand(arg0) + getRand(arg0) + getRand(arg0))
        / 12;
}

static void func_80042998()
{
    SetVideoMode(MODE_NTSC);
    SetDispMask(0);
    ResetCallback();
    ResetGraph(0);
    SetGraphDebug(0);
    InitCARD(0);
    StartCARD();
    _bu_init();
    PadInitDirect(padBuffer[0], padBuffer[1]);
    padResetDefaults(0, padBuffer[0]);
    padResetDefaults(0x10, padBuffer[1]);
    PadStartCom();
    padForceMode();
    func_80043668();
    SsUtReverbOff();
    DsInit();
    initRand();
    D_80055C88 = 1;
    D_8005E214 = 0;
}

static void func_80042A64()
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
    displayLoadingScreen();
    SsUtReverbOn();
    InitGeom();
    DrawSyncCallback(gpuSyncVoidCallback);
    VSyncCallback(vSyncVoidCallback);
    initHeap((HeapHeader*)0x8010C000, 0xF2000U);
    vs_main_initCdQueue();
    func_80044A60();
    func_800468FC();
    func_80043668();
    D_8005E240 = 0;
    padForceMode();

    for (i = 31; i >= 0; --i) {
        D_80055C90[i] = 0;
    }
    D_80061074[3] = 0;
    D_80061074[2] = 0;
    D_80061074[1] = 0;
    D_80061074[0] = 0;
    D_80060068.unk0 = 0;
}

int execTitle()
{
    getSp(&sp);
    func_80042A64();
    loadTitlePrg();
    D_80050470 = titlePrgMain();
    D_8005E214 = 0;
    displayLoadingScreen();
    loadBattlePrg();
    getSp(&sp);
    D_8005E240 = 1;
    execBattle();
    SetDispMask(0);
    func_800455F4();
    return 0;
}

void main_()
{
    __main();
    func_80042998();
    getSp(&sp2);
    execTitle();
}

static void do_wait() { wait(); }

void func_80042C94(int arg0) { D_80055C88 = arg0; }

void func_80042CA0() { D_80060068.unk0 = 1; }

void func_80069FC4(int, int);
void func_8008AB68();
void func_800A1108(int, unsigned char*);

void func_80042CB0()
{
    unsigned char sp10[16];
    int var_a1;
    int var_a3;
    int var_s1;
    int var_t3;
    int new_var;
    int var_t4;
    char var_a0;
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
        var_a0 = 0;
        for (var_a3 = 0; var_a3 < 8; ++var_a3) {
            unsigned int* p = (D_8004B9DC + (((var_s1 * 8) + var_a3) * 13));
            var_a0 = (*(int*)&var_a0 * 2) | ((p[3] >> 0xF) & 1);
        }
        D_8005FFB8[var_s1] = var_a0;
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

static void padDisconnectAll()
{
    portInfo[0].connected = 0;
    portInfo[1].connected = 0;
}

static void padForceMode()
{
    padDisconnectAll();
    if (PadInfoMode(0, InfoModeCurExID, 0) != 0) {
        PadSetMainMode(0, 1, 2);
    }
}

static void padResetDefaults(int port, void* arg1 __attribute__((unused)))
{
    PortInfo* info;

    info = &portInfo[port >> 4];
    info->exId = PadInfoMode(port, InfoModeCurExID, 0);

    if (info->exId & 0xFF) {
        info->actData[0] = 0;
        info->actData[1] = 0;
        info->lock = 2;
        PadSetMainMode(port, PadInfoMode(port, InfoModeCurExOffs, 0), info->lock);
    } else {
        info->actData[0] = 0x40;
        info->actData[1] = 0;
    }
    PadSetAct(port, info->actData, 2);
    PadSetActAlign(port, actParams);
}

int func_800430F4(int arg0, char padBuf[34])
{
    PortInfo* temp_s0;
    char temp_v0;
    int var_s1;

    if (padBuf[0] != 0) {
        temp_s0 = &portInfo[arg0 >> 4];
        temp_s0->unk6 = -128;
        temp_s0->unk5 = -128;
        temp_s0->unk4 = -128;
        temp_s0->unk3 = -128;
        return 0;
    }
    temp_s0 = &portInfo[arg0 >> 4];
    temp_v0 = PadInfoMode(arg0, 1, 0);
    temp_s0->unk0 = temp_v0;
    switch (temp_v0) {
    case 1:
    case 2:
    case 3:
    case 6:
        var_s1 = 0;
        break;
    default:
        var_s1 = ~((padBuf[2] << 8) | padBuf[3]);
        break;
    }

    temp_s0->unk0 = PadInfoMode(arg0, 1, 0);
    if ((temp_s0->unk0 == 5) || (temp_s0->unk0 == 7)) {
        temp_s0->unk3 = padBuf[6];
        temp_s0->unk4 = padBuf[7];
        temp_s0->unk5 = padBuf[4];
        temp_s0->unk6 = padBuf[5];
    } else {
        temp_s0->unk6 = -128;
        temp_s0->unk5 = -128;
        temp_s0->unk4 = -128;
        temp_s0->unk3 = -128;
    }
    temp_s0->unk2 = var_s1;
    return var_s1;
}

static void padConnect(int port, void* arg1)
{
    int dummy[5] __attribute__((unused));
    int state;
    PortInfo* info;

    info = &portInfo[port >> 4];
    state = PadGetState(port);

    if (state == PadStateFindPad) {
        info->connected = 0;
    }
    if (info->connected == 0) {
        PadSetAct(port, info->actData, 2);
        if ((state == PadStateFindCTP1)
            || ((state == PadStateStable) && (PadSetActAlign(port, actParams) != 0))) {
            padResetDefaults(port, arg1);
            info->connected = 1;
        }
    }
}

static void padSetActData(int port, int pos, int val)
{
    if (pos != 0) {
        portInfo[port].actData[pos] = val;
    } else if (portInfo[port].exId != 0) {
        portInfo[port].actData[0] = val;
    } else {
        portInfo[port].actData[0] = 0x40;
    }
}

static unsigned char padGetActData(int port, int pos)
{
    return portInfo[port].actData[pos];
}

static int func_800433B4(unsigned char* arg0, unsigned int arg1, short arg2)
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

    padDisconnectAll();

    for (i = 0; i < 2; ++i) {
        D_80050118[i].unkC = 0;
        D_80050118[i].unk10[7] = 0;
        D_80050118[i].unk10[1] = 0;
        D_80050118[i].unk8 = 0;
    }
}

// https://decomp.me/scratch/SBG7f
INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/3264C", func_800436B4);

static void func_800438C8(int arg0)
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

// https://decomp.me/scratch/egK9S
INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/3264C", func_80043940);

static void freeHeapR(void* block)
{
    HeapHeader* var_a1 = heapA.prev;
    HeapHeader* target = (HeapHeader*)block - 1;

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

void freeHeap(void* block)
{
    HeapHeader* var_a1 = heapA.next;
    HeapHeader* target = (HeapHeader*)block - 1;

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

static unsigned long* allocHeapR(unsigned int size)
{
    HeapHeader* var_a1;
    HeapHeader* var_a2;
    unsigned int blockSz;

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
            return (unsigned long*)(var_a1 + 1);
        }
        var_a2 = var_a1;
        if (var_a1 == &heapA) {
            return 0;
        }
        var_a1 = var_a1->prev;
    }
}

unsigned long* allocHeap(unsigned int size)
{
    unsigned int blockSz;
    HeapHeader* var_a1;
    HeapHeader* var_v1;

    var_v1 = &heapA;
    var_a1 = heapA.next;
    blockSz = ((size + 0xF) >> 4) + 1;

    while (1) {
        if (var_a1->blockSz >= blockSz) {
            if (var_a1->blockSz == blockSz) {
                var_v1->next = var_a1->next;
                var_a1->next->prev = var_a1->prev;
            } else {
                HeapHeader* temp_v1 = var_a1 + blockSz;
                temp_v1->blockSz = var_a1->blockSz - blockSz;
                temp_v1->prev = var_a1->prev;
                temp_v1->next = var_a1->next;
                temp_v1->prev->next = temp_v1;
                temp_v1->next->prev = temp_v1;
                var_a1->blockSz = blockSz;
            }
            return (unsigned long*)(var_a1 + 1);
        }
        var_v1 = var_a1;
        if (var_a1 == &heapA) {
            return 0;
        }
        var_a1 = var_a1->next;
    }
}

static void initHeap(HeapHeader* node, unsigned int value)
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

void diskReadCallback(unsigned char intr, unsigned char* result __attribute__((unused)),
    unsigned long* arg2 __attribute__((unused)))
{

    if ((intr == DslDiskError) || (intr == DslNoIntr) || (D_80055D10.status == 4)) {
        DsReadyCallback(0);
        DsEndReadySystem();
        D_80055D10.status = 4;
        return;
    }

    if (intr != DslDataReady) {
        return;
    }

    D_80055D10.status = 2;

    if (D_80055D10.unk2C == 0) {
        DsGetSector((char*)D_80055D10.vram + D_80055D10.bufIndex * 2048, 512);
    } else {
        DsGetSector(D_80050110 + D_80055D10.unk3C * 128, 512);
        if (++D_80055D10.unk3C >= 16) {
            D_80055D10.unk3C = 0;
        }
    }

    switch (D_80055D10.unk2C) {
    case 0:
        if (++D_80055D10.bufIndex >= D_80055D10.unk8) {
            D_80055D10.status = 0;
        }
        break;
    case 1:
        ++D_80055D10.unk38;
        ++D_80055D10.unk34;
        break;
    case 2:
        ++D_80055D10.unk38;
        if (++D_80055D10.unk40 >= 16) {
            D_80055D10.unk40 = 0;
        }
        break;
    default:
        break;
    }

    if (++D_80055D10.unk4 >= D_80055D10.unk8) {
        DsEndReadySystem();
    }
}

static void cdReadCb(unsigned char arg0, unsigned char* arg1 __attribute__((unused)))
{
    switch (arg0) {
    case 2:
        DsStartReadySystem(diskReadCallback, -1);
        return;
    case 5:
        break;
    default:
        break;
    case 6:
    case 0:
        return;
    }
    D_80055D10.status = 4;
}

static void cdSeekCb(unsigned char arg0, unsigned char* arg1 __attribute__((unused)))
{
    switch (arg0) {
    case 0:
        break;
    case 2:
        D_80055D10.status = 0;
        break;
    case 5:
        D_80055D10.status = 4;
        break;
    case 6:
        break;
    default:
        D_80055D10.status = 4;
        break;
    }
}

static void pcmReadReady(unsigned char intr, unsigned char arg1[])
{
    switch (intr) {
    case DslComplete:
        DsReadyCallback(NULL);
        D_80055D10.status = 0;
        break;
    case DslDataReady:
        if (!(arg1[4] & 0x80)) {
            D_800501CC = ((arg1[1] >> 4) * 0xA) + (arg1[1] & 0xF);
            D_800501D0 = arg1[3];
            D_800501D4 = arg1[4];
            D_800501D8 = (arg1[6] << 8) | arg1[7];
        }
        break;
    case DslDiskError:
        DsReadyCallback(NULL);
        D_80055D10.status = 8;
        break;
    }
}

static int getCdStatus() { return D_80055D10.status; }

static void func_80044320()
{
    if (D_80055D10.status == 4) {
        D_80055D10.status = 0;
    }
}

static int func_80044340(int sector, unsigned int bytes, void* vram)
{
    if (D_80055D10.status == 0) {
        D_80055D10.cdSector = sector;
        D_80055D10.sectorCount = bytes;
        D_80055D10.vram = vram;
        D_80055D10.unk40 = 0;
        D_80055D10.unk3C = 0;
        D_80055D10.bufIndex = 0;
        D_80055D10.unk34 = 0;
        D_80055D10.unk4 = 0;
        D_80055D10.unk3 = 0;
        D_80055D10.unk38 = 0;
        D_80055D10.unk8 = bytes >> 11;
        if (bytes & 0x7FF) {
            ++D_80055D10.unk8;
        }
        DsIntToPos(sector, &D_80055D10.cdLoc);
        D_80055D10.status = 5;
        return 1;
    }
    return 0;
}

static void func_800443CC()
{
    DslATV vol;
    int i;
    unsigned int seconds;

    switch (D_80055D10.status) {
    case 0:
    default:
        break;
    case 6:
        if (DsSystemStatus() == DslReady) {
            D_80055D10.unk1 = 0;
            D_80055D10.cdLoc.minute = 0;
            while (DsControlB(DslSetmode, dsControlBuf, NULL) == 0)
                ;
            VSync(3);
            vol.val2 = 0x80;
            vol.val0 = 0x80;
            vol.val3 = 0;
            vol.val1 = 0;
            DsMix(&vol);
            func_80012918(D_80055D10.sectorCount);
            func_80013230(0x7F);
            D_80055D10.pcm.file = 1;
            D_80055D10.pcm.chan = 0;
            DsControl(DslSetfilter, (u_char*)&D_80055D10.pcm, NULL);
            DsIntToPos(D_80055D10.cdSector, &D_80055D10.cdLoc);
            D_80055D10.commandId
                = DsPacket(DslModeRT | DslModeSF, &D_80055D10.cdLoc, DslReadS, NULL, -1);
            DsReadyCallback(pcmReadReady);
            D_80055D10.status = 7;
        }
        if (D_80055D10.commandId == 0) {
            DsReadyCallback(0);
            D_80055D10.status = 8;
            ++D_80055D10.unk3;
        }
        break;
    case 5: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            D_80055D10.unk4 = 0;
            D_80055D10.bufIndex = 0;
            if (D_80055D10.sectorCount != 0) {
                D_80055D10.status = 2;
                D_80055D10.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &D_80055D10.cdLoc, DslReadN, cdReadCb, -1);
            } else {
                D_80055D10.status = 1;
                D_80055D10.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &D_80055D10.cdLoc, DslSeekL, cdSeekCb, -1);
            }

            if (D_80055D10.commandId == 0) {
                D_80055D10.status = 4;
                ++D_80055D10.unk3;
            }
        }
        break;
    }
    case 8: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            D_80055D10.unk4 = 0;
            ++D_80055D10.unk3;
            seconds = frameDuration / 60;
            if (seconds < 420) {
                DsIntToPos(D_80055D10.cdSector + (seconds * 75) + (frameDuration % 60),
                    &cdReadLoc);
                vol.val2 = 0x80;
                vol.val0 = 0x80;
                vol.val3 = 0;
                vol.val1 = 0;
                DsMix(&vol);
                func_80012918(0);
                func_80012940(0x3C, D_80055D10.sectorCount);
                D_80055D10.pcm.file = 1;
                D_80055D10.pcm.chan = 0;
                DsControl(DslSetfilter, (u_char*)&D_80055D10.pcm, NULL);
                D_80055D10.commandId
                    = DsPacket(DslModeRT | DslModeSF, &cdReadLoc, DslReadS, NULL, -1);
                DsReadyCallback(pcmReadReady);
                D_80055D10.status = 7;
            } else {
                D_80055D10.commandId = DsCommand(DslModeSF | DslModeDA, NULL, NULL, -1);
                D_80055D10.status = 0;
                DsReadyCallback(0);
            }
        }
        if (D_80055D10.commandId == 0) {
            D_80055D10.status = 8;
            ++D_80055D10.unk3;
        }
        break;
    }
    case 4: {
        int status = DsSystemStatus();
        if (status == 1) {
            D_80055D10.unk4 = 0;
            D_80055D10.bufIndex = 0;
            ++D_80055D10.unk3;

            if (D_80055D10.sectorCount != 0) {
                D_80055D10.status = 2;
                D_80055D10.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &D_80055D10.cdLoc, DslReadN, cdReadCb, -1);
            } else {
                D_80055D10.status = 1;
                D_80055D10.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &D_80055D10.cdLoc, DslSeekL, cdSeekCb, -1);
            }

            if (D_80055D10.commandId == 0) {
                D_80055D10.status = 4;
                ++D_80055D10.unk3;
            }
        }
        break;
    }
    case 9:
        func_80012918(0);
        D_80055D10.commandId = DsCommand(DslPause, NULL, NULL, -1);
        if (D_80055D10.commandId > 0) {
            D_80055D10.status = 0;
        }
        DsReadyCallback(NULL);
        D_80055D10.unk1 = 0x80;
        D_80055D10.cdLoc.minute = 0x80;
        while (DsControlB(DslSetmode, dsControlBuf, NULL) == 0)
            ;
        VSync(3);
        break;
    }

    if (D_80055D10.unk2C != 0) {
        for (i = 0; i < 16; ++i) {
            if (D_80055D10.bufIndex >= D_80055D10.unk38) {
                return;
            }
            if (D_80055D10.unk2C == 1) {
                memcpy_impl(((char*)D_80055D10.vram + (D_80055D10.bufIndex * 2048)),
                    D_80050110 + (D_80055D10.unk40 * 128), 2048);

                ++D_80055D10.unk40;
                if (D_80055D10.unk40 >= 0x10) {
                    D_80055D10.unk40 = 0;
                }
                --D_80055D10.unk34;
                ++D_80055D10.bufIndex;
                if (D_80055D10.bufIndex >= D_80055D10.unk8) {
                    D_80055D10.status = 0;
                    freeHeapR(D_80050110);
                    D_80050110 = 0;
                }
            } else if (D_80055D10.unk2C == 2) {
                ++D_80055D10.bufIndex;
                if ((D_80055D10.bufIndex >= D_80055D10.unk8) && (func_80012C04() == 0)) {
                    D_80055D10.status = 0;
                    freeHeapR((HeapHeader*)D_80050110);
                    D_80050110 = 0;
                }
            }
        }
    }
}

static int func_8004493C(int arg0, int arg1, void* vram)
{
    int temp_v0;

    temp_v0 = func_80044340(arg0, arg1, vram);
    if (temp_v0 != 0) {
        int s4 = 1;
        int s3 = 2;

        while (1) {
            if (getCdStatus() == s4) {
                func_8004261C(0);
            } else if (getCdStatus() == s3) {
                func_8004261C(0);
            } else if (getCdStatus() == 3) {
                func_8004261C(0);
            } else if (getCdStatus() == 5) {
                func_8004261C(0);
            } else
                break;
        }
    }
    return temp_v0;
}

static int func_800449E8(int sector, int sectorCount)
{
    if (D_80055D10.status == 0) {
        D_80055D10.cdSector = sector;
        D_80055D10.sectorCount = sectorCount;
        D_80055D10.unk40 = 0;
        D_80055D10.unk3C = 0;
        D_80055D10.bufIndex = 0;
        D_80055D10.unk34 = 0;
        D_80055D10.unk4 = 0;
        D_80055D10.unk3 = 0;
        D_80055D10.unk38 = 0;
        D_80055D10.status = 6;
        return 1;
    }
    return 0;
}

static int func_80044A38()
{
    if (D_80055D10.status == 7) {
        D_80055D10.status = 9;
        return 1;
    }
    return 0;
}

static void func_80044A60()
{
    while (DsControlB(DslPause, NULL, NULL) == 0)
        ;
    DsFlush();
    D_80055D10.unk1 = 0x80;
    D_80055D10.cdLoc.minute = 0x80;
    D_80055D10.unk2 = 0;
    D_80055D10.status = 0;
    D_80055D10.unk2C = 0;
    D_80050110 = 0;
    while (DsControlB(DslSetmode, dsControlBuf, NULL) == 0)
        ;
    VSync(3);
}

static void vs_main_initCdQueue()
{
    int i;

    for (i = 0x1F; i >= 0; --i) {
        vs_main_cdQueue[i].unk0[0] = 0;
    }
    D_80050460.i = 0;
}

vs_main_cdQueue_t* func_80044B10(CdFile* arg0)
{
    int i;

    for (i = 0; i < 32; ++i) {
        if (vs_main_cdQueue[i].unk0[0] == 0) {
            vs_main_cdQueue[i].unk0[0] = 1;
            vs_main_cdQueue[i].cdFile = *arg0;
            return &vs_main_cdQueue[i];
        }
    }
    nop9(0xA2, 0);
}

void func_80044B80(vs_main_cdQueue_t* arg0)
{
    if ((unsigned short)arg0->unk0[0] - 2u < 2) {
        nop9(0xA3, 0);
    }
    arg0->unk0[0] = 0;
}

void func_80044BC4(vs_main_cdQueue_t* arg0, void* arg1)
{
    unsigned short temp_a1;

    arg0->unk0[0] = 3;
    arg0->vram = arg1;
    arg0->unkC = 0;
    temp_a1 = D_80050460.s[1];
    D_80050460.s[1] = (temp_a1 + 1);
    arg0->unk0[1] = temp_a1;
}

static void func_80044BF4(vs_main_cdQueue_t* arg0, void* arg1)
{
    vs_main_cdQueue_t* var_v1;
    int i;

    var_v1 = vs_main_cdQueue;

    for (i = 0; i < 32; ++i, ++var_v1) {
        if (var_v1->unk0[0] == 3) {
            ++var_v1->unk0[1];
        }
    }
    arg0->unk0[0] = 3;
    arg0->vram = arg1;
    arg0->unkC = 0;
    arg0->unk0[1] = 0;
    ++D_80050460.s[1];
}

static void nop4() { }

static void func_80044C74()
{
    int i;

    D_80055D10.unk44 += 1;

    if (D_80050460.i != 0) {
        vs_main_cdQueue_t* slot = vs_main_cdQueue;
        i = getCdStatus();
        if (i == 0) {
            for (; i < 32; ++i, ++slot) {
                if (slot->unk0[0] == 3) {
                    if (slot->unk0[1] == 0) {
                        slot->unk0[0] = 2;
                        func_80044340(slot->cdFile.lba, slot->cdFile.size, slot->vram);
                        D_80055D10.unk44 = 0;
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
    unsigned int new_var;
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
    unsigned int temp_v0;

    if (arg0 != 0) {
        if (D_8005E038.unk24[arg0 - 1] != 0) {
            D_8005E038.offset = arg0;
            temp_v0 = func_800120E8(
                D_8005E038.unkC_u.unkC_i = (unsigned int)D_8005E038.unk24[arg0 - 1]);
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

static int func_80044F60(int arg0, int arg1, unsigned int arg2)
{
    unsigned int temp_v0;

    if (arg0 != 0) {
        if (D_8005E038.unk24[arg0 - 1] != 0) {
            D_8005E038.offset = arg0;
            D_8005E038.unkC_u.unkC_i = (unsigned int)D_8005E038.unk24[arg0 - 1];
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
    unsigned int temp_v0;

    if (arg0 != 0) {
        if (D_8005E038.unk24[arg0 - 1] != 0) {
            D_8005E038.offset = arg0;
            D_8005E038.unkC_u.unkC_i = (unsigned int)D_8005E038.unk24[arg0 - 1];
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

static unsigned char func_800450E4()
{
    if (D_8005E038.offset != 0) {
        return D_8005E038.unkC_u.unkC_s.unkF[D_8005E038.offset];
    }
    return 0;
}

static int func_80045110(int arg0, int arg1)
{
    CdFile cdFile;

    if (arg0 > 0 && arg1 > 0) {
        int arg = arg1 - 1;

        if (arg1 < 5) {
            if (D_8005E038.unk10[arg] != arg0) {
                do {
                    if (D_8005E038.unk24[arg] != 0) {
                        nop10(0x8E, 0);
                        func_80045440(arg1);
                    }
                } while (0);

                cdFile.lba = D_8004A6C0[arg0];
                cdFile.size = D_8004AD00[arg0];

                if ((D_8005E038.unk34[arg] != 0)
                    && (D_8005E038.unk34[arg] != (vs_main_cdQueue_t*)-1)) {
                    nop9(0x98, 0);
                }

                D_8005E038.unk34[arg] = func_80044B10(&cdFile);

                if (D_8005E038.unk24[arg] != 0) {
                    nop9(0x8E, 0);
                }
                D_8005E038.unk24[arg] = allocHeapR(cdFile.size);
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

static int func_800452C8(unsigned int arg0)
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
                D_8005E038.unk34[arg0 - 1] = (vs_main_cdQueue_t*)-1;
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
            func_8004261C(0);
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
            func_8004261C(0);
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

    freeHeapR(D_8005E038.unk24[arg0 - 1]);
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

static void func_80045630(unsigned short arg0)
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
    unsigned short var_s0;
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
        var_s0_2 = (char*)var_s0_2 + (arg1 + (int*)var_s0_2)[1];
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
        var_s0_2 = (char*)var_s0_2 + (arg1 + ((int*)D_8005E08C))[1];
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
    CdFile cdFile;
    unsigned int new_var;

    if ((slot - 1u) < 3) {
        if (D_8005E038.unk4C[(slot - 1)] == 0) {
            new_var = slot - 1;
            cdFile.lba = D_8004A9E0[id];
            cdFile.size = D_8004B020[id];

            if ((D_8005E038.unk58[new_var] != 0)
                && (D_8005E038.unk58[new_var] != (vs_main_cdQueue_t*)-1)) {
                nop9(0x8F, 0);
            }

            D_8005E038.unk58[new_var] = func_80044B10(&cdFile);

            if (D_8005E038.unk4C[new_var] != 0) {
                nop9(0x90, 0);
            }

            D_8005E038.unk48[new_var] = id;
            D_8005E038.unk4C[new_var] = allocHeapR(cdFile.size);
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

static int func_80045F64(unsigned int arg0)
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
                D_8005E038.unk58[arg0 - 1] = (vs_main_cdQueue_t*)-1;
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
            func_8004261C(0);
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

static int func_800460C0(unsigned int arg0)
{
    if ((arg0 - 1) < 3) {
        if (D_8005E038.unk4C[arg0 - 1] != 0) {
            if (D_8005E038.unk44 == arg0) {
                D_8005E038.unk44 = 0;
            }
            func_80012288(-2, 0);
            func_80012288(0, 0xFF000);
            freeHeapR(D_8005E038.unk4C[arg0 - 1]);
            D_8005E038.unk48[arg0 - 1] = 0;
            D_8005E038.unk4C[arg0 - 1] = 0;
            return 1;
        }
    }
    return 0;
}

static int func_80046168(unsigned int arg0)
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

static void func_800461CC(
    int arg0, unsigned int arg1[], unsigned int arg2, int arg3, int arg4)
{
    int var_s0;
    void* temp_s1;

    temp_s1 = arg1;

    if (arg2 < arg1[0]) {
        temp_s1 = (char*)arg1 + (arg1 + arg2)[1];
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

static void func_800462E8(int arg0, unsigned int* arg1, unsigned int arg2)
{
    func_800461CC(arg0, arg1, arg2, 0x80, 0x7F);
}

static void func_80046310(int arg0, unsigned int arg1[], int arg2, int arg3, int arg4)
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

    var_v0 = arg3 + ((unsigned int)arg3 >> 0x1F);
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

static void func_800463BC(int arg0, unsigned int* arg1, int arg2, SVECTOR* vec)
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
    char* var_a0 = (char*)arg1 + (arg1 + arg2)[1];

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
    int a0 = (int)((char*)arg1 + (arg2 + arg1)[1]);

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
            freeHeapR(D_8005E038.unk64[arg0 - 1]);
            D_8005E038.unk64[arg0 - 1] = 0;
            return 1;
        }
    }
    return 0;
}

static int func_80046608(unsigned int arg0)
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
    CdFile cdFile;
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
    cdFile.lba = fileLBAs[file];
    cdFile.size = fileSizes[file];

    if (D_8005E0BC) {
        if (D_8005E0BC != (-1)) {
            nop9(0x93 & 0xFFu, 0);
        }
    }
    D_8005E038.unk84 = func_80044B10(&cdFile);
    if (D_8005E038.unk80 != 0) {
        nop9(0x94, 0);
    }
    new_var = 1;
    D_8005E038.unk80 = allocHeapR(cdFile.size);
    D_8005E038.fileId = file;
    func_80044BC4(D_8005E038.unk84, D_8005E038.unk80);
}

static void func_80046770(int arg0) { func_80046678(D_8004B1B0[arg0]); }

static int func_800467A0()
{
    int temp_v0;

    if (D_8005E038.unk84 != 0) {
        if (D_8005E038.unk84->unk0[0] == 7) {
            temp_v0 = func_80012C04();
            if (temp_v0 == 0) {
                func_80044B80(D_8005E038.unk84);
                D_8005E038.unk84 = 0;
                freeHeapR(D_8005E038.unk80);
                D_8005E038.unk80 = 0;
                D_8005E038.fileId = 0;
                return 0;
            }
            if (temp_v0 == -1) {
                func_80044B80(D_8005E038.unk84);
                D_8005E038.unk84 = 0;
                freeHeapR(D_8005E038.unk80);
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
            freeHeapR(D_8005E038.unk80);
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
        func_8004261C(0);
    }
}

void func_800468BC(int arg0) { func_8001240C(arg0); }

static void func_800468DC() { func_80012918(0x7FFF); }

void func_800468FC()
{
    void* temp_v0;

    func_80011DAC();
    func_80013230(0x7F);
    temp_v0 = allocHeapR(0x8800);
    func_8004493C(0xF618, 0x8800, temp_v0);
    func_80012BB8(temp_v0, 1);
    freeHeapR(temp_v0);
    temp_v0 = allocHeapR(0x12000);
    func_8004493C(0xF62D, 0x12000, temp_v0);
    func_80012BB8(temp_v0, 1);
    freeHeapR(temp_v0);
    temp_v0 = allocHeapR(0x18800);
    func_8004493C(0x10C65, 0x18800, temp_v0);
    func_800131DC(temp_v0, 0, 1);
    freeHeapR(temp_v0);
    func_8004493C(0x128E0, 0x5800, &D_80050478);
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

void func_80046B3C(int arg0, int arg1, unsigned short* arg2)
{
    int i;
    unsigned short g;
    unsigned short b;
    unsigned short r;
    unsigned char(*p)[7];

    for (i = 0; i < 256; ++i) {
        r = arg2[i] & 0x1F;
        g = (arg2[i] & 0x3E0) >> 5;
        b = (arg2[i] & 0x7C00) >> 10;

        p = D_80055D58.unk0[arg1].unkE;

        if (arg0 != 0) {
            p[i][4] = (r - p[i][0]) + 31;
            p[i][5] = (g - p[i][1]) + 31;
            p[i][6] = (b - p[i][2]) + 31;
        } else {
            p[i][0] = r;
            p[i][1] = g;
            p[i][2] = b;
            loadImageSource[arg1][i] = r + (g << 5) + (b << 10) + (p[i][3] << 15);
        }
    }

    if (arg0 != 0) {
        unsigned char* p = D_80055D58.unk0[arg1].unk6;
        p[0] = 1;
        p[1] = 0;
        p[2] = 0;
        p[3] = arg0;
    } else {
        D_80055D58.unk0[arg1].unk6[0] = 0;
    }
}

static void func_80046C80(int arg0, int arg1, unsigned short* arg2, int arg3)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80046B3C(arg0, arg1, arg2 + (arg3 << 4));
        D_80055D58.unk0[0].unk0 = 1;
    }
}

static void func_80046CC8(int arg0, int arg1, unsigned short* arg2, int arg3)
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

void func_80046DC0(int, int, int, short, short, short);
INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/3264C", func_80046DC0);

static void func_80047280(
    int arg0, int arg1, int arg2, short arg3, short arg4, short arg5)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80046DC0(arg0, arg1, arg2, arg3, arg4, arg5);
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
        D_8005DBE8 = 0;

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

// https://decomp.me/scratch/NnorQ
void func_800474DC(int, int, int, int, int);
INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/3264C", func_800474DC);

static void func_800478E0(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_800474DC(arg0, arg1, arg2, arg3, arg4);
    }
}

// https://decomp.me/scratch/q7o6c
INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/3264C", func_80047910);

static void func_80047AB4(int arg0, int arg1, D_8005DC6C_t* arg2)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80047910(arg0, arg1, arg2);
        D_80055D58.unk7F28[arg1].unk28 = *arg2;
    }
}

void func_80047B30(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    char sp10[4];
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
        t2[3] = ((int) (var_a1 - (t2[0] & 0xFFFF0000)) / (arg1 * 2));
        t2[4] = ((int) (var_t0 - (t2[1] & 0xFFFF0000)) / (arg1 * 2));
        t2[5] = ((int) (var_a2 - (t2[2] & 0xFFFF0000)) / (arg1 * 2));
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
            func_8008B430(sp10, ((unsigned short) t1->unk6[3] << 0x10) >> 0x12);
        }
    }
}

static void func_80047FC0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80047B30(arg0, arg1, arg2, arg3, arg4, arg5);
    }
}

// https://decomp.me/scratch/c07RD
INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/3264C", func_80047FFC);

// https://decomp.me/scratch/PakFK
INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/3264C", func_800481C0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/3264C", func_800483FC);

static void func_80048A3C(int arg0) { D_80055D58.unk0[arg0].unk6[0] = 0; }

void func_80048A64(unsigned short* arg0, unsigned int arg1, int arg2, unsigned int arg3)
{
    RECT sp10;
    unsigned short temp_a0_2;
    unsigned int i;
    unsigned char* temp_v1_3;

    if (arg1 >= 14) {
        setRECT(&sp10, arg2 + 0x300, arg1 + 0xE0, arg3, 1);
        LoadImage(&sp10, (unsigned long*)arg0);
        return;
    }

    if (D_80055D58.unk0[arg1].unk5 == 0) {
        D_80055D58.unk0[arg1].unk6[0] = 0;
        for (i = 0; i < arg3; ++i) {
            temp_a0_2 = arg0[i];
            temp_v1_3 = D_80055D58.unk0[arg1].unkE[arg2 + i];
            loadImageSource[arg1][arg2 + i] = temp_a0_2;
            D_80055D58.unk0[arg1].unk70E[arg2 + i] = temp_a0_2;
            temp_v1_3[0] = (temp_a0_2 & 0x1F);
            temp_v1_3[1] = ((temp_a0_2 & 0x3E0) >> 5);
            temp_v1_3[2] = ((temp_a0_2 & 0x7C00) >> 0xA);
            temp_v1_3[3] = ((temp_a0_2 & 0x8000) >> 0xF);
        }
        D_80055D58.unk0[0].unk0 = 1;
    }
}

// https://decomp.me/scratch/86lQJ
void func_80048B8C(int, unsigned short*, int, short, int, int, int);
INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/3264C", func_80048B8C);

static void func_80048E68(
    unsigned short* arg0, int arg1, short arg2, short arg3, short arg4, int arg5)
{
    func_80048B8C(8, arg0, arg1, arg2, arg3, arg4, arg5);
}

void func_80048EC4()
{
    int i;
    int var_v0;
    unsigned int* var_v1;
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

static void func_8004908C() { __asm__(".nop;"); }

static void nop9(int arg0 __attribute__((unused)), int arg1 __attribute__((unused))) { }

static void nop10(int arg0 __attribute__((unused)), int arg1 __attribute__((unused))) { }

static void nop11() { }

void memcpy_impl(void* dest, void* src, unsigned int sz)
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

void bzero_impl(void* dest, int sz)
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
