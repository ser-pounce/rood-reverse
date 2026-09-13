#include "common.h"
#include "6E644.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/overlay.h"
#include "build/src/include/lbas.h"

struct func_800D4910_t;

typedef struct {
    char unk0[0x12A];
    u_char unk12A;
    char unk12B[0xD];
    u_short unk138;
} func_800D8260_t;

typedef struct {
    int unk0;
    u_short unk4;
} func_800E5A74_t;

typedef struct {
    int unk0;
    _loadFileContext loadContexts[8];
    u_short unk24[8];
    u_short unk34[8];
} D_800F5638_t;

void func_800D8038(int);
void func_800D8054(int);

extern int D_800F5630;
extern D_800F5638_t D_800F5638;
extern u_int D_800F5680;
extern u_short _effBufSize;
extern vs_main_CdQueueSlot* D_800F568C;
extern u_int D_800F5690;
extern _loadFileContext D_800F5694;
extern u_long* D_800F56A0;
extern int D_800F56A4;
extern int (*D_800F56A8[])(struct func_800D4910_t*, int, int);
extern int D_800F5874;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D6E44);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7814);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7890);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D78B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D78CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D78E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D78F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7980);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7990);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D79E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D79F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7A04);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7A14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7A74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7A90);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7AB4);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D7C5C);

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

void func_800D7FE4(int (*arg0)(struct func_800D4910_t*, int, int), int arg1)
{
    D_800F56A8[arg1] = arg0;
}

void func_800D7FFC(int arg0) { D_800F5638.unk0 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D8008);

void func_800D8038(int arg0) { D_800F5680 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D8044);

void func_800D8054(int arg0) { D_800F5690 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800D8060);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DF9A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DFA54);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800DFAF8);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E4CE8);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5568);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5600);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5698);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5710);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5998);

void func_800E5A74(int* arg0, func_800E5A74_t* arg1)
{
    *arg0 = ((arg1->unk4 & 0xFFE) << 20) | (*arg0 & 0x1FFFFF);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5A9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5EC0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E5FDC);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E78F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7960);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", func_800E7F8C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C18);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C1C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/6E644", D_80069C3C);
