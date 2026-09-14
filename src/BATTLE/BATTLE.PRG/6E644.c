#include "common.h"
#include "5BF94.h"
#include "6E644.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/overlay.h"
#include "build/src/include/lbas.h"
#include <abs.h>

struct func_800D4910_t;

typedef struct {
    char unk0[0x38];
    int unk38;
    char unk3C[0xEE];
    u_char unk12A;
    char unk12B[0xD];
    u_short unk138;
} func_800D8260_t;

typedef struct {
    int unk0;
    u_short unk4;
} func_800E5A74_t;

typedef struct {
    char rangeX;
    char rangeY;
    char rangeZ;
    u_char shape : 3;
    u_char angle : 5;
} func_800E5568_t;

typedef struct {
    char unk0[0x38];
    func_800E5568_t unk38;
} func_800E5698_t2;

typedef struct {
    char unk0[0x5C];
    func_800E5698_t2* unk5C;
} func_800E5698_t;

typedef struct {
    u_short unk0_0 : 5;
    u_short unk0_5 : 5;
    u_short unk0_10 : 6;
} D_800F5910_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
} func_800DFA54_t;

typedef struct {
    int unk0;
    _loadFileContext loadContexts[8];
    u_short unk24[8];
    u_short unk34[8];
} D_800F5638_t;

typedef struct {
    short unk0;
    short unk1;
    short unk2;
    short unk3;
} func_8008D2C0_t;

typedef struct {
    signed char dx : 2;
    signed char unk0_2 : 2;
    signed char dz : 2;
    signed char unk0_6 : 2;
} D_800F16EC_t;

typedef struct {
    int unk0;
    u_int unk4;
} func_800E78F4_t2;

typedef struct {
    char unk0[0x430];
    func_800E78F4_t2* unk430;
    char unk434[0x3C];
    int unk470;
} func_800E78F4_t;

typedef struct {
    char unk0[0x18];
    u_short unk18;
} D_800F58BC_t;

void func_800D7A14(void*);
void func_800D7AC4(void*);
void func_800D7AEC(void*);
void func_800D8038(int);
void func_800D8054(int);
int func_8008D2C0(func_8008D2C0_t*);
short func_8008DC7C(int, int);
int func_800DBCB4(func_800E78F4_t*, func_800E78F4_t2*);

extern D_800F16EC_t D_800F16EC[8];
extern int D_800F5630;
extern D_800F5638_t D_800F5638;
extern u_int D_800F5680;
extern u_short _effBufSize;
extern vs_main_CdQueueSlot* D_800F568C;
extern u_int D_800F5690;
extern _loadFileContext D_800F5694;
extern u_long* D_800F56A0;
extern int D_800F56A4;
extern void (*D_800F56A8[])(struct func_800D4910_t*, int, int);
extern int D_800F5874;
extern u_short (*D_800F58B8)[32];
extern D_800F58BC_t* D_800F58BC;
extern D_800F5910_t* D_800F5910;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D6E44);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7814);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7890);

extern D_800F569C_t* D_800F5698;

void func_800D78B8(void) { D_800F5698 = D_800F569C; }

void func_800D78CC(void) { D_800F569C = D_800F5698; }

void func_800D78E0(u_char* arg0) { D_800F569C->unk8 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D78F0);

void func_800D7980(void* arg0) { D_800F569C->unkBC = arg0; }

void func_800D7990(func_800D0B30_t1* arg0)
{
    D_800F569C_t* s = D_800F569C;
    u_char* p;
    int i;

    s->unk8C = arg0;
    p = (u_char*)arg0 + arg0->unk2;
    for (i = 0; i < arg0->unk0; i++) {
        s->unkC[i] = p;
        p += arg0->unk4[i];
    }
}

void func_800D79E4(char* arg0) { D_800F569C->unk90 = arg0; }

void func_800D79F4(D_800F569C_t2* arg0) { D_800F569C->unkB4 = arg0; }

void func_800D7A04(void* arg0) { D_800F569C->unkB8 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7A14);

void func_800D7A74(u_short* arg0)
{
    D_800F569C->unkAC = *(int*)arg0;
    D_800F569C->unkB0 = arg0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7A90);

void func_800D7AB4(u_char* arg0) { D_800F569C->unkC0 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7AC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7AEC);

static int _loadfile(int lba, int size, void* buf)
{
    vs_main_CdFile cdFile;

    if (D_800F568C == NULL) {
        cdFile.lba = lba;
        cdFile.size = size;
        D_800F568C = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(D_800F568C, buf);
        return 1;
    }

    if (D_800F568C->state == vs_main_CdQueueStateLoaded) {
        vs_main_freeCdQueueSlot(D_800F568C);
        D_800F568C = NULL;
        return 0;
    }

    return 1;
}

int vs_battle_loadEffPurge(void)
{
    if (D_800F5684 == 0) {
        func_8007E180(2);
        D_800F5684 = 1;
    }

    return _loadfile(VS_EFFPURGE_BIN_LBA, VS_EFFPURGE_BIN_SIZE, vs_overlay_slots[3]);
}

void func_800D7BF8(void)
{
    int _[16];

    if (_effBuf == NULL) {
        _effBuf = vs_main_allocHeapR(_effBufSize);
    }

    _loadfile(_loadEffContext.lba + VS_E000_P_LBA, _loadEffContext.size, _effBuf);
}

void func_800D7C5C(void)
{
    int i;
    int bit;
    int flags;

    for (i = 0x18; i < 0x20; i++) {
        flags = D_800F5874;
        bit = 1 << i;
        if (flags & bit) {
            func_8007E0A8(i, 1, 2);
            D_800F5874 &= ~bit;
        }
    }
    if (_effBuf != NULL) {
        vs_main_freeHeapR(_effBuf);
        _effBuf = NULL;
    }
}

int func_800D7CFC(void)
{
    int _[16] __attribute__((unused));
    RECT sp50;
    int temp_s0;
    u_int temp_s1;
    int var_s0;
    void* temp_v0_3;

    if ((D_800F5680 == 0) && (D_800F5638.unk0 != 0)) {
        D_800F5630 = 0;
        func_800D8038(1);
    }

    temp_s1 = D_800F5680;

    switch (temp_s1) {
    case 1:
        if (D_800F56A0 == NULL) {
            // FBT sizes are all equal
            D_800F56A0 = vs_main_allocHeapR(VS_E000_0_FBT_SIZE);
        }

        var_s0 = _loadfile(D_800F5638.loadContexts[D_800F5630].lba + VS_E000_P_LBA,
            D_800F5638.loadContexts[D_800F5630].size, D_800F56A0);

        if (var_s0 == 0) {
            temp_v0_3 = (D_800F5630 * 2) + &D_800F5638;
            temp_s0 = D_800F5638.unk24[D_800F5630];

            if (D_800F5638.unk34[D_800F5630] == 0) {
                temp_s0 += 0x18;
                func_8007DFF0(temp_s0, 1, 2);
                D_800F5874 |= temp_s1 << temp_s0;
                sp50.x = (temp_s0 - (temp_s0 / 16 * 16)) << 6;
                sp50.y = temp_s0 / 16 << 8;
                sp50.w = 0x40;
                sp50.h = 0x100;
                LoadImage(&sp50, D_800F56A0);
            } else {
                sp50.x = 0x300;
                sp50.y = temp_s0 + 0xF0;
                sp50.w = 0x100;
                sp50.h = 5 - temp_s0;
                LoadImage(&sp50, D_800F56A0);
            }

            ++D_800F5630;

            if (D_800F5638.unk0 == D_800F5630) {
                func_800D8038(2);
            }

            var_s0 = 1;
        }
        break;

    case 2:
        if (D_800F56A0 != NULL) {
            vs_main_freeHeapR(D_800F56A0);
            D_800F56A0 = NULL;
        }
        /* fallthrough */

    case 0:
        var_s0 = 0;
        break;
    }
    return var_s0;
}

int func_800D7EF4(void)
{
    int _[16];
    int ret;
    u_int temp_s0 = D_800F5690;

    switch (temp_s0) {
    case 1:
        if (D_800F5684 == 0) {
            func_8007E180(2);
            D_800F5684 = temp_s0;
        }
        // Fallthrough

    case 2:
        ret = _loadfile(
            D_800F5694.lba + VS_E000_P_LBA, D_800F5694.size, vs_overlay_slots[3]);
        if (ret == 0) {
            func_800D8054(3);
        }
        break;
    case 0:
    case 3:
        ret = 0;
        break;
    }

    return ret;
}

void func_800D7FB4(int arg0, int arg1)
{
    _loadEffContext.lba = arg0;
    _loadEffContext.size = arg1;
}

void func_800D7FC8(int arg0, int arg1, int arg2)
{
    D_800F5694.lba = arg0;
    D_800F5694.size = arg1;
    D_800F56A4 = arg2;
}

void func_800D7FE4(void (*arg0)(struct func_800D4910_t*, int, int), int arg1)
{
    D_800F56A8[arg1] = arg0;
}

void func_800D7FFC(int arg0) { D_800F5638.unk0 = arg0; }

void func_800D8008(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    D_800F5638.loadContexts[arg4].lba = arg0;
    D_800F5638.loadContexts[arg4].size = arg1;
    D_800F5638.unk24[arg4] = arg2;
    D_800F5638.unk34[arg4] = arg3;
}

void func_800D8038(int arg0) { D_800F5680 = arg0; }

u_int func_800D8044(void) { return D_800F5680; }

void func_800D8054(int arg0) { D_800F5690 = arg0; }

void func_800D8060(void* arg0)
{
    while (1) {
        int temp_s1 = *(int*)arg0;

        switch (temp_s1 & 0xFFFF0000) {
        case 0:
            return;

        case 0x10000:
            func_800D7A14(arg0 + 4);
            break;

        case 0x20000:
            func_800D7A74(arg0 + 4);
            break;

        case 0x30000:
            func_800D7980(arg0 + 4);
            break;

        case 0x40000:
            func_800D7990(arg0 + 4);
            break;

        case 0x50000:
            func_800D78E0(arg0 + 4);
            break;

        case 0x80000:
            func_800D79E4(arg0 + 4);
            break;

        case 0x90000:
            func_800D79F4(arg0 + 4);
            break;

        case 0xA0000:
            func_800D7A04(arg0 + 4);
            break;

        case 0xB0000:
            func_800D7AB4(arg0 + 4);
            break;

        case 0xC0000:
            func_800D7AC4(arg0 + 4);
            break;

        case 0xD0000:
            func_800D7AEC(arg0 + 4);
            break;
        }

        arg0 += temp_s1 & 0xFFFF;
    }
}

int vs_battle_getMainMenuLba(void) { return VS_MAINMENU_PRG_LBA; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D820C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D821C);

void func_800D8260(func_800D8260_t* arg0, int arg1, int arg2)
{
    arg0->unk138 = arg1;
    arg0->unk12A = arg2;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D826C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D8280);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D82A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D82CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D836C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D8400);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D85D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D87E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D954C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D96C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D98E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D9DD8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D9E18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DA1D4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DA4BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DAC80);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DAD9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB0BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB370);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB4AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB5B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB5B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB5DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB5FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB61C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB74C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB7B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB820);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB8AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DB93C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBB2C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBC60);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBCB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBCEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBD80);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBF00);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DBFE4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC19C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC210);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC284);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC2E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC30C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC344);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC3CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC3E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC424);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC484);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC48C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC4F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC574);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC638);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC784);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC810);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DC888);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DCAA0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DCBD8);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069B68);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069BBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DCC94);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DD604);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DD918);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DE030);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DE3E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DEB10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DEC88);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DEEA4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DEEFC);

void func_800DF9A8(func_800DFA54_t* arg0, func_800DFA54_t* arg1)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (D_800F5910[i * 2].unk0_0 == arg0->unk0
            && D_800F5910[i * 2].unk0_5 == arg0->unk2) {
            if (i & 1) {
                i--;
            } else {
                i++;
            }
            arg1->unk0 = D_800F5910[i * 2 + 1].unk0_0;
            arg1->unk2 = D_800F5910[i * 2 + 1].unk0_5;
            arg1->unk1 = i >> 1;
            return;
        }
    }
    *(int*)arg1 = *(int*)arg0;
}

void func_800DFA54(int arg0, int arg1, int arg2, func_800DFA54_t* arg3)
{
    int i;

    arg1 >>= 19;
    arg2 >>= 19;
    for (i = arg0 * 2; i < arg0 * 2 + 2; i++) {
        if (arg1 == D_800F5910[i * 2 + 1].unk0_0
            && arg2 == D_800F5910[i * 2 + 1].unk0_5) {
            goto found;
        }
    }
    i = arg0 * 2;
found:
    arg3->unk0 = D_800F5910[i * 2].unk0_0;
    arg3->unk2 = D_800F5910[i * 2].unk0_5;
}

int func_800DFAF8(int arg0, u_int arg1, int arg2)
{
    func_8008D2C0_t sp10[4];
    func_8008D2C0_t* m;
    D_800F5910_t* e;
    int i;
    int j;

    func_8008D2C0(sp10);
    for (i = 0; i < 8; i++) {
        e = &D_800F5910[i * 2];
        j = i >> 1;
        if (arg2 == 0) {
            e++;
        }
        if ((u_char)arg1 == e->unk0_0 && (u_char)(arg1 >> 16) == e->unk0_5) {
            m = &sp10[j];
            if (D_800F5910[i * 2 + 1].unk0_0 == m->unk0 >> 7
                && D_800F5910[i * 2 + 1].unk0_5 == m->unk2 >> 7) {
                return i;
            }
        }
    }
    return -1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DFBCC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E02B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E0678);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E0850);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E0918);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E1238);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E1388);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E153C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E1850);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E1908);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E1BB8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E24EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E2B2C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E2CCC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E2F5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E3600);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E3BC8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E3CDC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E3D5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E3DDC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4180);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4288);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E42D4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E42E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E42EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4308);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4318);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4320);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4358);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E437C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4478);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E44E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E45B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E45D4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E45F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4604);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4624);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4660);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4690);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4764);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E47E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E48A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E48F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4904);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E49D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4B10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4B18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4B2C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4B70);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4BB8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4BD8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4BE0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4C1C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4C28);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4C64);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4C8C);

void func_800E4CE8(func_800D8260_t* arg0) { arg0->unk38 = -1; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4CF4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4DF8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4F14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4FB0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4FE0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E50A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E511C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5154);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5158);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E51C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5240);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E527C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5308);

int func_800E5568(func_800E5568_t* arg0)
{
    int (*fn)(int);
    int mask;
    int r;
    int v;

    mask = 1 << arg0->shape;
    if (mask & 0x16) {
        r = arg0->rangeZ;
        fn = rcos;
    } else if (mask & 0x8) {
        r = arg0->rangeY;
        fn = rcos;
    } else {
        r = arg0->rangeY;
        fn = rsin;
    }
    v = fn(arg0->angle << 7);
    return ((r << 5) * ABS(v)) >> 12;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5600);

int func_800E5698(func_800E5698_t* arg0, int actionId)
{
    vs_action_t* action = &vs_main_actions[actionId];
    func_800E5568_t* range;
    u_int v;

    if (action->rangeX == 0xFF) {
        range = &arg0->unk5C->unk38;
    } else {
        range = (func_800E5568_t*)&action->rangeX;
    }
    v = func_800E5568(range);
    if (v > 0x20) {
        v -= 0x20;
    }
    return v * v;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5710);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5998);

void func_800E5A74(int* arg0, func_800E5A74_t* arg1)
{
    *arg0 = ((arg1->unk4 & 0xFFE) << 20) | (*arg0 & 0x1FFFFF);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5A9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5EC0);

int func_800E5FDC(int arg0, int arg1)
{
    int i;
    u_int x;
    u_int z;

    for (i = 0; i < 4; i++) {
        x = arg0 + D_800F16EC[i * 2].dx;
        z = arg1 + D_800F16EC[i * 2].dz;
        if (x < 32 && z < 32 && !(D_800F58B8[z][x] & 0x70)) {
            return func_8008DC7C(x << 7 | 0x40, z << 7 | 0x40) >> 6;
        }
    }
    return -1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6098);

void func_800E6F9C(void);

void func_800E6158(void) { func_800E6F9C(); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6178);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E65DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6694);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6700);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6764);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E678C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6828);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E685C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6898);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E68A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E68EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6974);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6A6C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6B24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6B4C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6BA0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6C34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6EAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6EB0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6F1C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E6F9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E71DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E72D0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7370);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7454);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E75EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7608);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7660);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7698);

int func_800E78F4(func_800E78F4_t* arg0)
{
    int r = 0;
    int a;
    int b;

    if (arg0->unk470 != 0 && func_800DBCB4(arg0, arg0->unk430)) {
        a = (u_short)(arg0->unk430->unk4 >> 13);
        b = D_800F58BC->unk18;
        r = a < b;
    }
    return r;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7960);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7F8C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C18);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C1C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C3C);
