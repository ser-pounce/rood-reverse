#include "common.h"
#include <kernel.h>
#include <libspu.h>
#include <libapi.h>
#include <libetc.h>
#include <libcd.h>

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} D_80036770_t;

static int func_80013468(int*);
int func_80013588(void*, int);
void func_800135D8(void*, int, int, int);
void func_8001369C(void);
static void _soundInit(void);
static void func_80013AE8(u_int);
u_int func_80018C30(int);
long func_80019A58(void);
static void _shutdown(void);
static void _writeSpu(char* data, u_int len);

extern int _soundEvent;
extern char _soundFlush[64];
extern short D_800358FE;
extern CdlATV _cdlAtv;
extern D_80036770_t D_80036770;
extern int D_800377E0[3];
extern int* D_800377EC;
extern int* D_800377F8;
extern u_short (*D_800377F4)[];
extern char _spuMemInfo;
extern volatile int _isSpuTransfer;
extern int D_80039AF8[];
extern int D_80039AFC;

int vs_sound_init(void)
{
    _soundInit();
    return 0;
}

int vs_sound_shutdown(void)
{
    _shutdown();
    return 0;
}

int func_80011DEC(int* arg0)
{
    int v1 = func_80013468(arg0);

    arg0 += 4;

    if (v1 == 0) {
        D_800377EC = arg0;
        arg0 += 0x180;
        D_800377F4 = (u_short(*)[])arg0;
        arg0 += 0xC0;
        D_800377F8 = arg0;
    }
    return v1;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011E40);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011EBC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011F08);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011F24);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011F90);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011FB4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80011FDC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012004);

int func_80012024(void)
{
    D_800358FE = 0;
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012034);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012080);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800120B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800120E8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012110);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001215C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001217C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800121F0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012288);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800122C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800122F0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012358);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800123C8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", vs_sound_setMonoSound);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012440);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012468);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012490);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800124FC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012568);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800125A8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800125D4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012608);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001264C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012694);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800126C0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800126F4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012738);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012780);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800127AC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800127E0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012824);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001286C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800128A0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800128D8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012918);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012940);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012970);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800129A4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800129D0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012A04);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012A40);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012A6C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012AA0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012ADC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012B08);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012B3C);

void func_80012B78(void) { func_80018C30(240); }

void func_80012B98(void) { func_80018C30(241); }

void func_80012BB8(void* arg0, int arg1)
{
    while (func_80013588(arg0, arg1) == 1)
        ;
}

int vs_sound_spuTransferring(void) { return _isSpuTransfer; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012C14);

static int func_80012D9C(int* arg0, int* arg1, int* arg2, int arg3)
{
    u_int i;

    for (i = 0; i < 3; ++i) {
        if (D_800377E0[i] == arg0[1]) {
            D_800377E0[i] = 0;
        }
    }
    switch (arg3) {
    case 1:
        *arg1 = 0xA0;
        *arg2 = 0x13100;
        D_800377E0[1] = arg0[1];
        break;
    case 2:
        *arg1 = 0xC0;
        *arg2 = 0x1B100;
        D_800377E0[2] = arg0[1];
        break;
    default:
        *arg1 = 0x80;
        *arg2 = 0xB100;
        D_800377E0[0] = arg0[1];
        break;
    }
    return arg3;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012E50);

int func_80012EBC(void)
{
    D_80039AF8[1] &= ~0x10000;
    D_80036770.unk4 = 0;
    D_80036770.unk0 = 0;
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012EF0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012F10);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013188);

int func_800131DC(void* arg0, int arg1, int arg2)
{
    int sp10;
    int sp14;

    func_80012D9C((int*)arg0, &sp10, &sp14, arg1);
    func_800135D8(arg0, arg2, sp10, sp14);
    return 0;
}

int vs_sound_setCdVol(u_int arg0)
{
    if (D_80039AFC & 2) {
        _cdlAtv.val0 = _cdlAtv.val2 = _cdlAtv.val1 = _cdlAtv.val3 =
            (arg0 * 0xB570) >> 0x11;
    } else {
        _cdlAtv.val2 = arg0;
        _cdlAtv.val0 = arg0;
        _cdlAtv.val3 = 0;
        _cdlAtv.val1 = 0;
    }
    CdMix(&_cdlAtv);
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800132C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013328);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013348);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013378);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800133B0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800133E0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013418);

static int func_80013468(int* arg0) { return *arg0 + 0xB0BEB4BF; }

static void _spuWriteComplete(void)
{
    SpuSetTransferCallback(NULL);
    _isSpuTransfer = 0;
}

void spuSetTransferCallback(void)
{
    _isSpuTransfer = 1;
    SpuSetTransferCallback(_spuWriteComplete);
}

static void _writeSpu(char* data, u_int len)
{
    _isSpuTransfer = 1;
    SpuSetTransferCallback(_spuWriteComplete);
    SpuWrite(data, len);
}

static void _readSpu(char* data, u_int len)
{
    spuSetTransferCallback();
    SpuRead(data, len);
}

static void _waitTransferAvailable(void)
{
    if (_isSpuTransfer == 1) {
        do {

        } while (_isSpuTransfer == 1);
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013588);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800135D8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001369C);

static void _soundInit(void)
{
    int event;

    SpuStart();
    SpuInitMalloc(4, &_spuMemInfo);
    SpuSetTransferMode(SPU_TRANSFER_BY_DMA);
    SpuSetTransferStartAddr(0x1010);
    _writeSpu(_soundFlush, 64);
    _waitTransferAvailable();
    func_8001369C();
    SpuSetIRQ(SPU_OFF);
    SpuSetIRQCallback(NULL);
    while (SetRCnt(RCntCNT2, 0x44E8, RCntMdINTR) == 0)
        ;
    while (StartRCnt(RCntCNT2) == 0)
        ;
    do {
        event = OpenEvent(RCntCNT2, EvSpINT, EvMdINTR, func_80019A58);
        _soundEvent = event;
    } while (event == -1);
    while (EnableEvent(_soundEvent) == 0)
        ;
}

static void _shutdown(void)
{
    if (_isSpuTransfer == 1) {
        _writeSpu(_soundFlush, 64);
        _waitTransferAvailable();
    }
    while (StopRCnt(RCntCNT2) == 0)
        ;
    UnDeliverEvent(RCntCNT2, EvSpINT);
    while (DisableEvent(_soundEvent) == 0)
        ;
    while (CloseEvent(_soundEvent) == 0)
        ;
    func_80013AE8(0xFFFFFF);
    SpuQuit();
}

static void func_80013ACC(u_int arg0)
{
    *(short*)getScratchAddr(0x762) = arg0;
    *((short*)getScratchAddr(0x762) + 1) = arg0 >> 16;
}

static void func_80013AE8(u_int arg0)
{
    *(short*)getScratchAddr(0x763) = arg0;
    *((short*)getScratchAddr(0x763) + 1) = arg0 >> 16;
}

static void func_80013B04(u_int arg0)
{
    *(short*)getScratchAddr(0x766) = arg0;
    *((short*)getScratchAddr(0x766) + 1) = (arg0 >> 0x10);
}

static void func_80013B20(u_int arg0)
{
    *(short*)getScratchAddr(0x765) = arg0;
    *((short*)getScratchAddr(0x765) + 1) = (arg0 >> 0x10);
}

static void func_80013B3C(u_int arg0)
{
    *(short*)getScratchAddr(0x764) = arg0;
    *((short*)getScratchAddr(0x764) + 1) = (arg0 >> 0x10);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013B58);

static void func_80013BA0(int arg0, short arg1)
{
    ((short(*)[8])getScratchAddr(0x701))[arg0][0] = arg1;
}

static void func_80013BB8(int arg0, u_int arg1)
{
    ((short(*)[8])((short*)getScratchAddr(0x701) + 1))[arg0][0] = (arg1 >> 3);
}

static void func_80013BD4(int arg0, u_int arg1)
{
    ((short(*)[8])((short*)getScratchAddr(0x703) + 1))[arg0][0] = (arg1 >> 3);
}

static void func_80013BF0(int arg0, short arg1)
{
    ((short(*)[8])getScratchAddr(0x702))[arg0][0] = arg1;
}

static void func_80013C08(int arg0, short arg1)
{
    ((short(*)[8])((short*)getScratchAddr(0x702) + 1))[arg0][0] = arg1;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013C20);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013C50);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013C78);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013CA0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013CD4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013D04);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013DB0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013ECC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001436C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800147CC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80014C58);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80014D08);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80014D70);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80014FBC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001503C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015080);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800151C0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015210);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015220);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015764);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800157C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015970);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015AFC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015B54);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015BAC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015C9C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015D38);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80015D84);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800160F0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800161C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001653C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800166E8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80016744);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800168F8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80016964);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800169AC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80016A00);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80016DA8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80016DF8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80016E74);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80016F0C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80016FF4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800171C8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017208);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017254);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800172D4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001733C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001746C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017498);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001754C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001766C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017764);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017798);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017800);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017870);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017958);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017AD8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017B54);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017C1C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017CFC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017E74);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017EEC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80017FB0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018090);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018218);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018270);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001833C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018358);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800183C0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018434);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018450);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800184B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001852C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800185A0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018608);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800186E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018744);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800187A4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800187E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800187F8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800188E8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018984);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018AA0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018B34);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018B84);

void func_80018BD8(void) { }

void _setReverbMode(int mode)
{
    long curMode;

    SpuGetReverbModeType(&curMode);
    if (curMode != mode) {
        SpuSetReverb(SPU_OFF);
        SpuSetReverbModeType(mode | SPU_REV_MODE_CLEAR_WA);
        SpuSetReverb(SPU_ON);
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018C30);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019134);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019154);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800191D4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001924C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019614);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019704);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800199C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019A58);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019FC4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001A1F4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001A22C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001A258);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001A4BC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001A64C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001A8D8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B060);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B094);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B0CC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B138);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B20C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B248);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B294);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B334);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B37C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B424);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B450);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B4A8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B4E0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B4EC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B514);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B598);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B5C8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B654);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B6E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B6F8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B70C);

static void func_8001B72C(void) { }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B734);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B778);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B804);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B838);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B8C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B8E0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B8F8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B910);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B9B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BA24);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BAB8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BB00);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BB24);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BB50);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BB98);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BBD0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BBD8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BC38);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BC9C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BD94);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BDF4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BE60);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BE84);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BF34);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BF58);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BFC8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BFEC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C058);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C078);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C0E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C108);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C168);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C1D0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C244);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C2AC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C30C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C36C);

void func_8001C378(void) { }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C380);

void func_8001C39C(void) { }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C3A4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C440);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C484);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C4B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C4E8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C52C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C56C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C5B0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C628);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C66C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C68C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C69C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C6EC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C780);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C7EC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C868);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C8BC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C8E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C92C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C964);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C97C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C9B4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C9F0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CA2C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CA70);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CAA0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CAE4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CB14);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CB7C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CB90);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CBA4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CBB8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CBCC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CC84);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CC98);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CCC8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CCE8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CD08);

void func_8001CD24(short* arg0) { arg0[105] = 0; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CD2C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", IRQCallbackProc);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CDD0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CE60);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CEA8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D0E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D2A0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", spuTransferCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D3D4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D438);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D584);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D5B4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D5E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D614);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D644);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D698);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D6B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D728);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D7A8);
