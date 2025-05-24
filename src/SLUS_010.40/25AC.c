#include "25AC.h"
#include "common.h"
#include <sys/types.h>
#include <libapi.h>
#include <libetc.h>
#include <libspu.h>
#include <libcd.h>

void func_8001286C(u_int, int);
void func_800135D8(void*, int, int, int);
int func_80013468(int*);
void spuWriteComplete();
void writeSpu(u_char*, u_int);
void vs_sound_WaitTransferAvailable();
int func_80013588(void*, int);
void func_8001369C();
static void vs_sound_DoShutdown();
void func_80013938();
void func_80013AE8(u_int);
void func_80014FBC(int*, int);
int func_8001503C(int*, int, int);
u_int func_80018C30(int);
long func_80019A58();
int func_8001CDD0();
void func_8001CEA8(u_int*, int, int);
void func_8001D3D4();

extern SpuTransferCallbackProc spuTransferCallback;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC[10];
    int unk34;
    int unk38[4];
    int unk48;
    int unk4C[5];
    short unk60;
    short unk62[6];
    u_short unk6E[4];
    u_short unk76[3];
    u_short unk7C;
    int unk7E[5];
    u_short unk94;
    u_short unk96[58];
    short unk10A;
} D_80036628_t;

typedef struct {
    u_int unk0;
    u_int unk4;
    u_int unk8;
    u_int unkC;
} D_800378C0_t;

typedef struct {
    int unk0[10];
    int unk28;
    int unk2C[0x39];
} D_80035910_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} D_80036770_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    u_int unk14;
    int unk18;
    u_int unk1C;
} func_80012C14_t;

typedef struct {
    u_char* unk0;
    short unk4[104];
} func_8001CD08_t;

int soundEvent = 0;
extern u_char D_8002F560[0x40];
extern int D_80033690;
extern short D_800358FE;
extern D_80035910_t D_80035910;
extern CdlATV cdlAtv;
extern int* D_800365D4;
extern D_80036628_t* D_80036628;
extern short D_80036630[][4];
extern D_80036770_t D_80036770;
extern short D_80036780;
extern short D_80036782;
extern int D_80037788;
extern u_char spuMemInfo;
extern int D_800377E0[3];
extern int* D_800377EC;
extern volatile int isSpuTransfer;
extern u_short (*D_800377F4)[];
extern int* D_800377F8;
extern D_80036628_t* D_80037820;
extern int D_80037844;
extern int D_80037890[];
extern D_800378C0_t D_800378C0;
extern short D_800378E2;
extern int D_80039AF8[];
extern int D_80039AFC;
extern u_int D_80039B08[];
extern int D_80039B14;
extern int D_80039BCC;
extern int D_80039AEC;
extern int D_80039AF0;

int func_80011DAC()
{
    func_80013938();
    return 0;
}

int vs_sound_Shutdown()
{
    vs_sound_DoShutdown();
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

int func_80011E40()
{
    int var_v1;

    var_v1 = D_80037820->unk4 != 0;
    if (D_80036628 != NULL) {
        if (D_80036628->unk4 != 0) {
            var_v1 |= 2;
        }
    }
    if (D_80037788 != 0) {
        var_v1 |= 0x10;
    }
    if (D_80037890[0] != 0) {
        var_v1 |= 0x100;
    }
    if (D_80039B14 != 0) {
        var_v1 |= 0x10000;
    }
    return var_v1;
}

int func_80011EBC(u_int arg0)
{
    int var_a1;
    D_80036628_t* var_v1;

    var_v1 = D_80037820;
    var_a1 = 0;
    if ((var_v1->unk6E[0] == (u_int)arg0)
        || ((var_v1 = D_80036628, (var_v1 != 0)) && (var_v1->unk6E[0] == arg0))) {
        var_a1 = var_v1->unk62[0];
    }
    return var_a1;
}

int func_80011F08()
{
    return (u_short)D_80036770.unk0 | (u_short)D_80036770.unk4 << 0x10;
}

short func_80011F24(int arg0)
{
    int ret;

    ret = 0;
    if (arg0 & 1) {
        ret = D_80037820->unk62[3];
    }
    if (arg0 & 2) {
        if (ret < D_80036782) {
            ret = D_80036782;
        }
    }
    if (((arg0 & 4) != 0) && (ret < D_80036780)) {
        ret = D_80036780;
    }
    return ret;
}

int func_80011F90()
{
    int new_var;
    new_var = D_80037820->unk7C << 0x10;
    new_var++;
    new_var--;
    return new_var | (D_80037820->unk76[0] + 1);
}

u_int func_80011FB4(void* arg0)
{
    D_800378C0.unk0 = (int)arg0;
    return func_80018C30(16);
}

void func_80011FDC(u_int arg0)
{
    D_800378C0.unk0 = arg0;
    func_80018C30(17);
}

void func_80012004() { func_80018C30(64); }

int func_80012024()
{
    D_800358FE = 0;
    return 0;
}

u_int func_80012034(u_int arg0, int arg1)
{
    u_int temp_v0;

    D_800378C0.unk0 = arg0;
    temp_v0 = func_80018C30(25);
    func_8001286C(temp_v0, arg1);
    return temp_v0;
}

u_int func_80012080(void* arg0, u_int arg1, int arg2)
{
    D_800378C0.unk0 = (int)arg0;
    D_800378C0.unk4 = arg1;
    D_800378C0.unk8 = arg2 & 0x7F;
    return func_80018C30(26);
}

void func_800120B8(u_int arg0, u_int arg1)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1;
    func_80018C30(18);
}

u_int func_800120E8(void* arg0)
{
    D_800378C0.unk0 = (int)arg0;
    return func_80018C30(20);
}

int func_80012110(u_int arg0, u_int arg1)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1;
    func_80018C30(22);
    return (D_800378C0.unk4 << 16) + D_800378C0.unk0;
}

void func_8001215C() { func_80018C30(23); }

int func_8001217C(int arg0, int arg1, int arg2, int arg3)
{
    u_int i = arg0 & 0x3FF;
    int ret = D_800377EC[i];

    if (ret != -1) {
        D_800378C0.unk0 = i;
        D_800378C0.unk4 = arg1 & 0xFFFFFF;
        D_800378C0.unk8 = arg2 & 0xFF;
        D_800378C0.unkC = arg3 & 0x7F;
        func_80018C30(32);
    }
    return ret;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800121F0);

void func_80012288(int arg0, int arg1)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFFFFFF;
    func_80018C30(33);
}

void func_800122C4(int arg0)
{
    D_800378C0.unk0 = arg0 & 0x3FF;
    func_80018C30(48);
}

int func_800122F0()
{
    D_80035910_t* var_a1;
    int var_a0;
    int mask;
    int v = D_80037890[0];

    var_a0 = v == 0;
    if (var_a0 != 0) {
        return 0;
    }
    var_a1 = &D_80035910;
    var_a0 = 0;
    for (mask = 0x1000; mask & 0xFFFFFF; mask *= 2) {
        if (v & mask) {
            var_a0 |= var_a1->unk28;
        }
        ++var_a1;
    }
    return var_a0 & 0xFFFFFF;
}

int func_80012358(int arg0)
{
    D_80035910_t* var_a1;
    int var_v1;

    if (arg0 == 0 || D_80037890[0] == 0) {
        return 0;
    }
    var_a1 = &D_80035910;
    for (var_v1 = 0x1000; var_v1 & 0xFFFFFF; var_v1 *= 2) {
        do {
            if (D_80037890[0] & var_v1 && arg0 == var_a1->unk28) {
                return var_a1->unk2C[4];
            }
            var_a1 += 1;
        } while (0);
    }
    return 0;
}

u_int func_800123C8(int arg0)
{
    u_int var_a1;

    var_a1 = 0;
    if (arg0 < 0) {
        var_a1 = ((u_char*)arg0)[9] >> 7;
    } else if ((*D_800377F4)[arg0] & 0x8000) {
        var_a1 = 1;
    }
    return var_a1;
}

void func_8001240C(int arg0)
{
    if (arg0 == 1) {
        func_80018C30(129);
    } else {
        func_80018C30(128);
    }
}

void func_80012440(u_int arg0)
{
    D_800378C0.unk0 = arg0;
    func_80018C30(144);
}

void func_80012468(u_int arg0)
{
    D_800378C0.unk0 = arg0;
    func_80018C30(146);
}

void func_80012490(u_int arg0)
{
    switch (arg0) {
    case 1:
        func_80018C30(155);
        break;
    case 2:
        func_80018C30(157);
        break;
    case 3:
        func_80018C30(159);
        break;
    default:
        func_80018C30(153);
        break;
    }
}

void func_800124FC(u_int arg0)
{
    switch (arg0) {
    case 1:
        func_80018C30(154);
        break;
    case 2:
        func_80018C30(156);
        break;
    case 3:
        func_80018C30(158);
        break;
    default:
        func_80018C30(152);
        break;
    }
}

int func_80012568(int arg0)
{
    if (arg0 != 0) {
        D_80039AF8[1] |= 0x10;
    } else {
        D_80039AF8[1] &= ~0x10;
    }
    return 0;
}

void func_800125A8(int arg0)
{
    D_800378C0.unk0 = arg0 & 0x7F;
    func_80018C30(168);
}

void func_800125D4(u_int arg0, int arg1)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0x7F;
    func_80018C30(169);
}

void func_80012608(u_int arg0, int arg1, int arg2)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFFFFFF;
    D_800378C0.unk8 = arg2 & 0x7F;
    func_80018C30(160);
}

void func_8001264C(int arg0, int arg1, int arg2, int arg3)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFFFFFF;
    D_800378C0.unk8 = arg2;
    D_800378C0.unkC = arg3 & 0x7F;
    func_80018C30(161);
}

void func_80012694(int arg0)
{
    D_800378C0.unk0 = arg0 & 0xFF;
    func_80018C30(170);
}

void func_800126C0(u_int arg0, int arg1)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFF;
    func_80018C30(171);
}

void func_800126F4(u_int arg0, int arg1, int arg2)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFFFFFF;
    D_800378C0.unk8 = arg2 & 0xFF;
    func_80018C30(162);
}

void func_80012738(int arg0, int arg1, int arg2, int arg3)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFFFFFF;
    D_800378C0.unk8 = arg2;
    D_800378C0.unkC = arg3 & 0xFF;
    func_80018C30(163);
}

void func_80012780(int arg0)
{
    D_800378C0.unk0 = arg0 & 0xFF;
    func_80018C30(172);
}

void func_800127AC(u_int arg0, int arg1)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFF;
    func_80018C30(173);
}

void func_800127E0(u_int arg0, int arg1, int arg2)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFFFFFF;
    D_800378C0.unk8 = arg2 & 0xFF;
    func_80018C30(164);
}

void func_80012824(int arg0, int arg1, int arg2, int arg3)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFFFFFF;
    D_800378C0.unk8 = arg2;
    D_800378C0.unkC = arg3 & 0xFF;
    func_80018C30(165);
}

void func_8001286C(u_int arg0, int arg1)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0x7F;
    func_80018C30(192);
}

void func_800128A0(u_int arg0, int arg1, int arg2)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1;
    D_800378C0.unk8 = arg2 & 0x7F;
    func_80018C30(193);
}

void func_800128D8(u_int arg0, u_int arg1, int arg2, int arg3)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1;
    D_800378C0.unk8 = arg2 & 0x7F;
    D_800378C0.unkC = arg3 & 0x7F;
    func_80018C30(194);
}

void func_80012918(int arg0)
{
    D_800378C0.unk0 = arg0;
    func_80018C30(200);
}

void func_80012940(int arg0, int arg1)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1;
    func_80018C30(201);
}

void func_80012970(u_int arg0, u_int arg1, u_int arg2)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1;
    D_800378C0.unk8 = arg2;
    func_80018C30(202);
}

void func_800129A4(int arg0)
{
    D_800378C0.unk0 = arg0 & 0xFF;
    func_80018C30(208);
}

void func_800129D0(int arg0, int arg1)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFF;
    func_80018C30(209);
}

void func_80012A04(u_int arg0, int arg1, int arg2)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFF;
    D_800378C0.unk8 = arg2 & 0xFF;
    func_80018C30(210);
}

void func_80012A40(int arg0)
{
    D_800378C0.unk0 = arg0 & 0xFF;
    func_80018C30(212);
}

int func_80012A6C(int arg0, int arg1)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFF;
    return func_80018C30(213);
}

void func_80012AA0(u_int arg0, int arg1, int arg2)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFF;
    D_800378C0.unk8 = arg2 & 0xFF;
    func_80018C30(214);
}

void func_80012ADC(int arg0)
{
    D_800378C0.unk0 = arg0 & 0xFF;
    func_80018C30(216);
}

void func_80012B08(u_int arg0, int arg1)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFF;
    func_80018C30(217);
}

void func_80012B3C(u_int arg0, int arg1, int arg2)
{
    D_800378C0.unk0 = arg0;
    D_800378C0.unk4 = arg1 & 0xFF;
    D_800378C0.unk8 = arg2 & 0xFF;
    func_80018C30(218);
}

void func_80012B78() { func_80018C30(240); }

void func_80012B98() { func_80018C30(241); }

void func_80012BB8(void* arg0, int arg1)
{
    while (func_80013588(arg0, arg1) == 1)
        ;
}

int func_80012C04() { return isSpuTransfer; }

int func_80012C14(func_80012C14_t* arg0, int* arg1, int* arg2)
{
    int var_a3;

    if (D_80037820->unk4 == 0) {
        D_80037820->unk0 &= ~0x60;
    }
    var_a3 = 0;
    if (arg0->unk1C >= 0x21 || arg0->unk14 > 0x20000) {
        D_80039AF8[1] &= ~0x10000;
        D_80036770.unk4 = 0;
        D_80036770.unk0 = 0;
    } else {
        if (D_80037820->unk0 & 0x20
            || (!(D_80037820->unk0 & 0x40) && (D_80039AFC & 0x10000))) {
            var_a3 = 1;
            D_80039AF8[1] &= ~0x10000;
        } else {
            D_80039AF8[1] |= 0x10000;
        }
    }
    if (var_a3 == 0) {
        *arg1 = 0x40;
        *arg2 = 0x35100;
        D_80036770.unk0 = arg0->unk4;
        if (D_80036770.unk4 == arg0->unk4) {
            D_80036770.unk4 = 0;
        }
    } else {
        *arg1 = 0x60;
        *arg2 = 0x55100;
        D_80036770.unk4 = arg0->unk4;
        if (D_80036770.unk0 == arg0->unk4) {
            D_80036770.unk0 = 0;
        }
    }
    return var_a3;
}

int func_80012D9C(int* arg0, int* arg1, int* arg2, int arg3)
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

int func_80012E50(int arg0)
{
    if (D_80036770.unk0 == arg0) {
        D_80039AF8[1] |= 0x10000;
    } else if (D_80036770.unk4 == arg0) {
        D_80039AF8[1] &= ~0x10000;
    }
    return D_80039AFC & 0x10000;
}

int func_80012EBC()
{
    D_80039AF8[1] &= ~0x10000;
    D_80036770.unk4 = 0;
    D_80036770.unk0 = 0;
    return 0;
}

int func_80012EF0()
{
    D_80039BCC = 0;
    *D_80039AF8 |= 1;
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80012F10);

int func_80013188(void* arg0, int arg1)
{
    int sp10;
    int sp14;
    int temp_s0;

    temp_s0 = func_80012C14((func_80012C14_t*)arg0, &sp10, &sp14);
    func_800135D8(arg0, arg1, sp10, sp14);
    return temp_s0;
}

int func_800131DC(void* arg0, int arg1, int arg2)
{
    int sp10;
    int sp14;

    func_80012D9C((int*)arg0, &sp10, &sp14, arg1);
    func_800135D8(arg0, arg2, sp10, sp14);
    return 0;
}

int func_80013230(u_int arg0)
{
    if (D_80039AFC & 2) {
        cdlAtv.val0 = cdlAtv.val2 = cdlAtv.val1 = cdlAtv.val3 = (arg0 * 0xB570) >> 0x11;
    } else {
        cdlAtv.val2 = arg0;
        cdlAtv.val0 = arg0;
        cdlAtv.val3 = 0;
        cdlAtv.val1 = 0;
    }
    CdMix(&cdlAtv);
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800132C4);

void func_80013328() { func_80018C30(226); }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013348);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013378);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800133B0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800133E0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013418);

int func_80013468(int* arg0) { return *arg0 + 0xB0BEB4BF; }

void spuWriteComplete()
{
    SpuSetTransferCallback(NULL);
    isSpuTransfer = 0;
}

void spuSetTransferCallback()
{
    isSpuTransfer = 1;
    SpuSetTransferCallback(spuWriteComplete);
}

void writeSpu(u_char* data, u_int len)
{
    isSpuTransfer = 1;
    SpuSetTransferCallback(spuWriteComplete);
    SpuWrite(data, len);
}

void readSpu(u_char* data, u_int len)
{
    spuSetTransferCallback();
    SpuRead(data, len);
}

void vs_sound_WaitTransferAvailable()
{
    if (isSpuTransfer == 1) {
        do {

        } while (isSpuTransfer == 1);
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013588);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800135D8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001369C);

void func_80013938()
{
    int temp_v0;

    SpuStart();
    SpuInitMalloc(4, &spuMemInfo);
    SpuSetTransferMode(SPU_TRANSFER_BY_DMA);
    SpuSetTransferStartAddr(0x1010);
    writeSpu(D_8002F560, 64);
    vs_sound_WaitTransferAvailable();
    func_8001369C();
    SpuSetIRQ(SPU_OFF);
    SpuSetIRQCallback(NULL);
    while (SetRCnt(RCntCNT2, 0x44E8, RCntMdINTR) == 0)
        ;
    while (StartRCnt(RCntCNT2) == 0)
        ;
    do {
        temp_v0 = OpenEvent(RCntCNT2, EvSpINT, EvMdINTR, func_80019A58);
        soundEvent = temp_v0;
    } while (temp_v0 == -1);
    while (EnableEvent(soundEvent) == 0)
        ;
}

void vs_sound_DoShutdown()
{
    if (isSpuTransfer == 1) {
        writeSpu(D_8002F560, 0x40);
        vs_sound_WaitTransferAvailable();
    }
    while (StopRCnt(RCntCNT2) == 0)
        ;
    UnDeliverEvent(RCntCNT2, EvSpINT);
    while (DisableEvent(soundEvent) == 0)
        ;
    while (CloseEvent(soundEvent) == 0)
        ;
    func_80013AE8(0xFFFFFF);
    SpuQuit();
}

void func_80013ACC(u_int arg0)
{
    *(short*)getScratchAddr(0x762) = arg0;
    *((short*)getScratchAddr(0x762) + 1) = arg0 >> 16;
}

void func_80013AE8(u_int arg0)
{
    *(short*)getScratchAddr(0x763) = arg0;
    *((short*)getScratchAddr(0x763) + 1) = arg0 >> 16;
}

void func_80013B04(u_int arg0)
{
    *(short*)getScratchAddr(0x766) = arg0;
    *((short*)getScratchAddr(0x766) + 1) = (arg0 >> 0x10);
}

void func_80013B20(u_int arg0)
{
    *(short*)getScratchAddr(0x765) = arg0;
    *((short*)getScratchAddr(0x765) + 1) = (arg0 >> 0x10);
}

void func_80013B3C(u_int arg0)
{
    *(short*)getScratchAddr(0x764) = arg0;
    *((short*)getScratchAddr(0x764) + 1) = (arg0 >> 0x10);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80013B58);

void func_80013BA0(int arg0, short arg1)
{
    ((short(*)[8])getScratchAddr(0x701))[arg0][0] = arg1;
}

void func_80013BB8(int arg0, u_int arg1)
{
    ((short(*)[8])((short*)getScratchAddr(0x701) + 1))[arg0][0] = (arg1 >> 3);
}

void func_80013BD4(int arg0, u_int arg1)
{
    ((short(*)[8])((short*)getScratchAddr(0x703) + 1))[arg0][0] = (arg1 >> 3);
}

void func_80013BF0(int arg0, short arg1)
{
    ((short(*)[8])getScratchAddr(0x702))[arg0][0] = arg1;
}

void func_80013C08(int arg0, short arg1)
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

void func_80015080(int arg0)
{
    short(*var_s1)[4];
    u_int i;
    int var_s2;
    int* new_var;
    int new_var2;

    var_s2 = (D_80037820->unk4 & D_80037820->unkC[0]) | arg0;
    if (D_80036628 != 0) {
        var_s2 |= D_80036628->unk4 & D_80036628->unkC[0];
    }

    new_var = (int*)D_80036630;
    var_s1 = (short(*)[])(new_var + 1);

    for (i = 0; i < 24; ++i) {
        int v0 = (var_s2 & (1 << i));
        new_var2 = 0x7FFF;
        if (v0 == 0) {
            SpuGetVoiceEnvelope(i, var_s1[i]);
            if (var_s1[i][0] == 0) {
                func_80014FBC(&D_80033690, i);
            } else {
                if (D_80037820->unk8 != 0) {
                    if (func_8001503C(&D_80033690, D_80037820->unk8, i) != 0) {
                        var_s1[i][0] = new_var2;
                    }
                    if ((D_80036628 != 0)
                        && (func_8001503C(D_800365D4, D_80036628->unk8, i) != 0)) {
                        var_s1[i][0] = new_var2;
                    }
                }
            }
        } else {
            var_s1[i][0] = 0x7FFF;
        }
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800151C0);

void func_80015210(int* arg0) { arg0[24] = D_80037844; }

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

void func_8001833C(char* arg0)
{
    int c = *arg0;
    D_80036782 = 0;
    D_80039AF0 = c << 0x10;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018358);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800183C0);

void func_80018434(char* arg0)
{
    int c = *arg0;
    D_80036780 = 0;
    D_80039AEC = c << 16;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018450);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800184B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001852C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800185A0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018608);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800186E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018744);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800187A4);

void func_800187E4(u_short* arg0) { D_80037820->unk6E[1] = *arg0; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800187F8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800188E8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018984);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018AA0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018B34);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80018B84);

void func_80018BD8() { }

void setReverbMode(int mode)
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

void func_80019134()
{
    int v0 = D_800378E2;
    short* p = (short*)getScratchAddr(0x76C);
    *p++ = v0;
    *p = v0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019154);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800191D4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001924C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019614);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019704);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_800199C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019A58);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_80019FC4);

int func_8001A1F4(int arg0, u_int arg1)
{
    if ((arg1 - 0x80) < 0x20) {
        if (arg0 & 2) {
            return arg1 + 0x20;
        }
        if (arg0 & 4) {
            return arg1 + 0x40;
        }
    }
    return arg1;
}

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

void func_8001B4E0(int arg0[]) { arg0[0] = arg0[5]; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B4EC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B514);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B598);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B5C8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B654);

void func_8001B6E4(D_80036628_t* arg0) { arg0->unk34 |= 0x40; }

void func_8001B6F8(D_80036628_t* arg0) { arg0->unk34 &= ~0x40; }

void func_8001B70C(u_char** arg0)
{
    u_char* temp_v1;

    do {
        temp_v1 = *arg0;
        D_80037820->unk34 = *temp_v1;
        *arg0 = temp_v1 + 1;
    } while (0);
}

void func_8001B72C() { }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B734);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B778);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B804);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B838);

void func_8001B8C4(func_8001CD08_t* arg0) { arg0->unk4[72] = *arg0->unk0++; }

void func_8001B8E0(D_80036628_t* arg0) { arg0->unk94 = ((arg0->unk94 + 1) & 0xF); }

void func_8001B8F8(D_80036628_t* arg0) { arg0->unk94 = ((arg0->unk94 - 1) & 0xF); }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B910);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001B9B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BA24);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BAB8);

void func_8001BB00(func_8001CD08_t* arg0) { arg0->unk4[111] = (char)*arg0->unk0++; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BB24);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BB50);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BB98);

void func_8001BBD0(short arg0[]) { arg0[77] = 0; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BBD8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BC38);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BC9C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BD94);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BDF4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BE60);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BE84);

void func_8001BF34(func_8001CD08_t* arg0)
{
    arg0->unk4[91] = (*arg0->unk0++ & 0x7F) << 8;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BF58);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BFC8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001BFEC);

void func_8001C058(func_8001CD08_t* arg0) { arg0->unk4[97] = *arg0->unk0++ << 7; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C078);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C0E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C108);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C168);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C1D0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C244);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C2AC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C30C);

void func_8001C36C(short arg0[]) { arg0[78] = 1; }

void func_8001C378() { }

void func_8001C380(u_short* arg0)
{
    if (arg0[50] != 0) {
        arg0[78] = 4;
    }
}

void func_8001C39C() { }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C3A4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C440);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C484);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C4B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C4E8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C52C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C56C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C5B0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C628);

void func_8001C66C(u_char** arg0)
{
    u_char* temp_v1;

    do {
        temp_v1 = *arg0;
        D_80037820->unk48 = *temp_v1;
        *arg0 = temp_v1 + 1;
    } while (0);
}

void func_8001C68C() { D_80037820->unk48 = 0; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C69C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C6EC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C780);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C7EC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C868);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C8BC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C8E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C92C);

void func_8001C964(D_80036628_t* arg0)
{
    arg0->unk10A = 0;
    arg0->unk34 = (arg0->unk34 & ~8);
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C97C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C9B4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001C9F0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CA2C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CA70);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CAA0);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CAE4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CB14);

void func_8001CB7C(D_80036628_t* arg0) { arg0->unk34 |= 0x10; }

void func_8001CB90(D_80036628_t* arg0) { arg0->unk34 &= ~0x10; }

void func_8001CBA4(D_80036628_t* arg0) { arg0->unk34 |= 0x20; }

void func_8001CBB8(D_80036628_t* arg0) { arg0->unk34 &= ~0x20; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CBCC);

void func_8001CC84(D_80036628_t* arg0) { arg0->unk34 |= 0x100000; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CC98);

void func_8001CCC8(int arg0 __attribute__((unused)), int arg1)
{
    D_80037820->unk8 |= arg1;
}

void func_8001CCE8(int arg0, int arg1) { D_80037820->unk8 &= ~arg1; }

void func_8001CD08(func_8001CD08_t* arg0) { arg0->unk4[103] = *arg0->unk0++; }

void func_8001CD24(short arg0[]) { arg0[105] = 0; }

void func_8001B138();

void func_8001CD2C() { func_8001B138(); }

void IRQCallbackProc()
{
    u_int temp_a2;

    if (D_80039B08[3] != 0) {
        SpuSetIRQ(SPU_OFF);
        SpuSetIRQCallback(NULL);
        func_80013AE8(D_80039B08[3]);
        temp_a2 = D_80039B08[3];
        D_80039B08[3] = 0;
        D_80037890[8] &= ~temp_a2;
        D_80039AF8[2] |= 0x100;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001CDD0);

void func_8001CE60()
{
    void* temp_s0 = (void*)D_80039B08[0] + 0x800;
    SpuSetTransferStartAddr(0x2100);
    SpuSetTransferCallback((void*)&spuTransferCallback);
    SpuWrite(temp_s0, 0x800);
}

void func_8001CEA8(u_int* arg0, int arg1, int arg2)
{
    int temp_v0;
    u_int var_a1;
    u_int* new_var;

    temp_v0 = func_8001CDD0();
    if (temp_v0 == -1) {
        return;
    }
    D_80039B08[19] = arg1;
    SpuSetIRQ(0);
    SpuSetIRQCallback(0);
    new_var = arg0;
    D_80039B08[0] = (int)(arg0 + 16);

    D_80039B08[5] = arg0[4];
    D_80039B08[6] = arg0[8];
    D_80039B08[4] = temp_v0;
    D_80039B08[3] = (1 << temp_v0) | (1 << (temp_v0 + 1));
    func_80013AE8(D_80039B08[3]);

    D_80039B08[2] = arg0[6];
    D_80039B08[22] = (u_short)arg0[7];
    D_80039B08[4] = temp_v0;
    D_80039B08[3] = (1 << temp_v0) | (1 << (temp_v0 + 1));
    func_80013AE8(D_80039B08[3]);

    SpuSetTransferMode(0);
    SpuSetTransferStartAddr(0x1100);
    isSpuTransfer = 1;

    D_80039B08[1] = D_80039B08[2] & 2 ? D_80039B08[0] + arg0[5] : 0;

    if (D_80039B08[2] & 1) {
        D_80039B08[7] = D_80039B08[2] & 2 ? D_80039B08[5] - (new_var[5] >> 1) : 0;
        SpuSetTransferCallback(func_8001D3D4);
        var_a1 = 0x2000;
    } else {
        D_80039B08[7] = D_80039B08[2] & 2 ? D_80039B08[5] - new_var[5] : 0;
        SpuSetTransferCallback(func_8001CE60);
        var_a1 = 0x800;
    }
    SpuWrite((u_char*)D_80039B08[0], var_a1);
    if (arg2 != 0) {
        D_80037890[8] |= D_80039B08[3];
    } else {
        D_80037890[8] &= ~D_80039B08[3];
    }
    D_80037890[9] &= ~D_80039B14;
    D_80037890[7] &= ~D_80039B14;
    D_80039AF8[2] |= 0x100;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D0E4);

void func_8001D2A0(int arg0, int arg1, void (*callback)())
{
    int var_s2 = arg1;
    if (D_80039B08[3] != 0) {
        SpuSetTransferCallback(NULL);
        isSpuTransfer = 0;
        if (D_80039B08[5] >= 0x1001) {
            D_80039B08[5] -= 0x1000;
            D_80039B08[0] += arg0;
            SpuSetIRQCallback(callback);
        } else {
            SpuSetIRQCallback(IRQCallbackProc);
            var_s2 = 0x1030;
            D_80039B08[5] = 0;
        }
        SpuSetIRQAddr(var_s2 + 8);
        func_80013ACC(D_80039B14);
        SpuSetIRQ(SPU_ON);
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", spuTransferCallback);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D3D4);

void func_8001D438(u_int arg0, u_int arg1, u_int arg2, void (*arg3)())
{
    u_int var_s1;
    u_int var_s4;

    var_s4 = arg1;
    if ((D_80039B08[3] != 0) && (D_80039B08[5] != 0)) {
        SpuSetTransferStartAddr(arg0);
        var_s1 = arg0;
        spuSetTransferCallback();
        SpuWrite((void*)D_80039B08[0], arg2);
        SpuSetIRQ(0);
        if (D_80039B08[5] >= 0x801) {
            SpuSetIRQCallback(arg3);
            D_80039B08[5] -= 0x800;
            D_80039B08[0] += arg2;
        } else if (D_80039B08[1] != 0) {
            SpuSetIRQCallback(arg3);
            D_80039B08[0] = D_80039B08[1];
            D_80039B08[5] = D_80039B08[7];
        } else {
            SpuSetIRQCallback(IRQCallbackProc);
            var_s4 = 0x1030;
            var_s1 = 0x1030;
            D_80039B08[5] = 0;
        }
        func_80013BD4(D_80039B08[4], var_s1);
        func_80013BD4(D_80039B08[4] + 1, var_s4);
        SpuSetIRQAddr(var_s1 + 8);
        SpuSetIRQ(1);
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D584);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D5B4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D5E4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D614);

void func_8001D644(int* arg0)
{
    IRQCallbackProc();
    func_8001CEA8((u_int*)arg0[0], arg0[1], arg0[2]);
    *D_80037890 &= ~D_80039B14;
}

void func_8001D698() { IRQCallbackProc(); }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D6B8);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D728);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/25AC", func_8001D7A8);
