#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/2EA3C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../SLUS_010.40/32154.h"
#include "lbas.h"
#include "gpu.h"

void func_80105B18(void*, int);
void func_801060E0(void*, int);
int func_80106570(void*);

extern u_long* D_1F800000[];

extern vs_main_CdFile D_80102B00[];
extern int D_801083F8;
extern u_short D_801083FC[];
extern vs_main_CdQueueSlot* D_80108D24;
extern u_short* D_80108D28;
extern int D_80108D2C;
extern int D_80108D60;
extern int D_80108D64;
extern int D_80108D68;
extern int D_80108D6C;
extern int D_80108D70;
extern int D_80108D74;
extern int D_80108D7C;
extern int D_80108D80;
extern int D_80108D88;
extern int D_80108D8C;
extern int D_80108D90;
extern int D_80108D94;
extern int D_80108D98;
extern short D_80108D9C;
extern short D_80108D9E;
extern short D_80108DA4[];
extern short D_80108DAC[];
extern vs_main_CdQueueSlot* D_80108DBC;
extern int D_80108E44;

void func_80102CD8(int arg0)
{
    if (arg0 != 0) {
        func_800FFA88(2);
        D_801022D6 = 0;
        return;
    }
    func_800FFA88(0);
    D_801022D6 = 1;
}

void func_80102D1C(int arg0, int arg1, int arg2, u_long* arg3)
{
    u_long* var_a3;

    var_a3 = arg3;
    if (var_a3 == 0) {
        var_a3 = D_1F800000[2];
    }
    func_800C0224(0x80, arg1, 0x100010, var_a3)->unk10 = ((arg0 + 4) * 0x10) | 0x37FD8000;
    D_1F800000[0][-4] = (int)(arg2 | 0x64000000);
}

void func_80102D90(int arg0, int arg1, char** arg2)
{
    int sp10[arg0];
    int var_v1;
    int temp_a1;
    int temp_s1;

    if (D_801083F8 == -1) {
        D_801083F8 = arg1;
    }

    for (var_v1 = 0; var_v1 < arg0; ++var_v1) {
        sp10[var_v1] = 0;
    }

    if (!(arg1 & 0x80)) {
        if (D_801083F8 < arg0) {
            sp10[D_801083F8] |= 4;
        }
    }

    temp_a1 = arg1 & 0x7F;

    if ((arg0 < 9) || (temp_a1 < 8)) {
        D_800F4EE8.unk0[0] = temp_a1;
        D_800F4EE8.unk0[1] = 0;
    } else if (temp_a1 >= (arg0 - 8)) {
        D_800F4EE8.unk0[0] = temp_a1 - (arg0 - 9);
        D_800F4EE8.unk0[1] = arg0 - 9;
    } else {
        D_800F4EE8.unk0[0] = 4;
        D_800F4EE8.unk0[1] = temp_a1 - 4;
    }
    temp_s1 = vs_main_settings.cursorMemory;
    vs_main_settings.cursorMemory = 1;
    vs_mainmenu_setMenuRows(arg0, 0x100, arg2, sp10);
    vs_main_settings.cursorMemory = temp_s1;
}

int func_80102ED8(void)
{
    int temp_v0;

    temp_v0 = vs_mainmenu_getSelectedRow();
    if (temp_v0 < -1) {
        func_800FA8E0(5);
        return temp_v0;
    }
    if (temp_v0 >= 0) {
        func_800FA92C(D_800F4EE8.unk0[0], 1);
    }
    return temp_v0;
}

void func_80102F30(char* text, char arg1)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_setMenuItem(10, 320, 34, 0x8C, 8, text);
    menuItem->state = 2;
    menuItem->x = 0xB4;
    menuItem->selected = 1;
    menuItem->unkA = arg1;
}

void func_80102F8C(void) { func_800FA8E0(5); }

void func_80102FAC(void) { vs_mainmenu_ready(); }

int func_80102FCC(int arg0)
{
    vs_main_CdFile cdFile;

    if (arg0 != 0) {
        cdFile.lba = VS_MAPBG_BIN_LBA;
        cdFile.size = VS_MAPBG_BIN_SIZE;
        D_80108D24 = vs_main_allocateCdQueueSlot(&cdFile);
        D_80108D28 = vs_main_allocHeapR(VS_MAPBG_BIN_SIZE);
        vs_main_cdEnqueue(D_80108D24, D_80108D28);
        D_80108D2C = 0;
        return 0;
    }
    switch (D_80108D2C) {
    case 0:
        if (D_80108D24->state == 4) {
            vs_main_freeCdQueueSlot(D_80108D24);
            func_80048A64(D_80108D28, 3, 0, 0x100);
            vs_battle_drawImage(
                vs_getXY(640, 256), D_80108D28 + 0x100, vs_getWH(160, 240));
            func_80100414(-4, 0x80);
            D_80108D2C = 1;
        }
        return 0;
    case 1:
        vs_main_freeHeapR(D_80108D28);
        return 1;
    default:
        return 0;
    }
}

INCLUDE_ASM("build/src/MENU/MENU5.PRG/nonmatchings/4D8", func_801030F4);

int func_80103418(void)
{
    int a1;

    vs_main_stateFlags.unk135[0] = 1;
    if (D_800F1BC0 == 0) {
        if (D_8005FFD8.unk4 & 0x800000) {
            D_8005FFD8.unk4 |= 0x400000;
        }
        D_80108D8C = 0;
        D_80108D94 = 0;
        vs_main_bzero(&D_80108DA4, 8);
        vs_main_bzero(&D_80108DAC, 8);
        D_80108DA4[0] = 0x238;
        D_80108D64 = 0;
        D_80108DA4[2] = D_80108DA4[1] = 0x800 - *(u_short*)0x1F800058;
        D_80108D80 = func_8008D400();
        if (D_80108D80 >= 0x20) {
            D_80108D80 = 0;
        }
        a1 = vs_main_stateFlags.unk135[D_80108D80];
        D_80108D90 = D_80108D80;
        D_80108D60 = 0;
        D_80108D68 = 0x80;
        D_80108D6C = 0;
        D_80108D70 = -0x180;
        D_80108D74 = 0;
        D_80108E44 = 1;
        D_80108D7C = 0x300;
        D_80108D9C = 5;
        D_80108D9E = 0;
        D_80108D88 = a1;
        D_800F1BC0 = vs_main_allocHeapR(D_80102B00[D_80108D80].size);
        D_80108DBC = vs_main_allocateCdQueueSlot(&D_80102B00[D_80108D80]);
        vs_main_cdEnqueue(D_80108DBC, D_800F1BC0);
        return 0;
    }

    if (D_80108DBC->state != 4) {
        return 0;
    }

    vs_main_freeCdQueueSlot(D_80108DBC);
    D_80108D98 = func_80098F4C(D_800F1BC0);
    func_8008B4D8(D_800F1BC0);
    func_801060E0(D_800F1BC0, 4);
    D_80108D64 = func_80106570(D_800F1BC0);
    func_80105B18(D_800F1BC0, D_80108D64);
    func_80041954(0x300, D_8005E248);
    SetFarColor(0, 0, 0);
    func_80102F30((char*)&D_801083FC[D_801083FC[D_80108D80]], 1);
    return 1;
}

INCLUDE_RODATA("build/src/MENU/MENU5.PRG/nonmatchings/4D8", D_80102820);

INCLUDE_RODATA("build/src/MENU/MENU5.PRG/nonmatchings/4D8", D_80102B00);

INCLUDE_RODATA("build/src/MENU/MENU5.PRG/nonmatchings/4D8", D_80102C00);
