#include "common.h"
#include "413C.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

typedef struct {
    char text[14];
    char unk14;
    char x;
} textHeader_t;

extern char vs_mainMenu_isLevelledSpell;
extern char D_801022DC;
extern short D_801022DE;
extern short D_801022E0;
extern char D_801022E2;
extern char D_801022E3;
extern int D_801022E4;
extern u_short D_801022E8[];
extern int D_801022F8[];
extern char D_8010231A[];
extern int D_801023D4;
extern int _selectedRow;
extern char D_801023DE;
extern textHeader_t _textHeaders[];
extern u_long* D_1F800000[];

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FD93C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDB04);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDB60);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDBAC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDCD0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDD24);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDD78);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDD88);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FDEBC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE360);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE3A0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE3E0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE5CC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE694);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE6EC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE7E0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE848);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FE8B0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FEA6C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FEB08);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FEB94);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF0EC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF348);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF360);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF388);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF43C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FF9E4);

void func_800FFA88(int arg0) { D_801022E3 = arg0; }

void func_800FFA94(void)
{
    int var_a1;
    u_long* temp_v0;
    int temp_s0;

    temp_s0 = D_801022E2;
    var_a1 = D_801022E4;
    if (temp_s0 != D_801022E3) {
        if (var_a1 == 0) {
            D_801022E2 = D_801022E3;
            return;
        }
        var_a1 -= 2;
    } else if (var_a1 < 0xC) {
        var_a1 += 2;
    }
    D_801022E4 = var_a1;
    if (temp_s0 != 0) {
        temp_v0 = vs_battle_setSprite(0x180,
            (0x138 - (D_801022F8[temp_s0] & 0xFF)) | ((D_801022E4 - 4) << 16),
            D_801022F8[temp_s0], D_1F800000[2]);
        temp_v0[1] = 0xE100002C;
        temp_v0[4] = D_801022E8[temp_s0] | 0x37F50000;
    }
}

void func_800FFB68(int arg0)
{
    if (arg0 != 0) {
        D_801022DE = -4;
        D_801022E0 = 0x80;
    }
    D_801022DC = arg0;
}

void func_800FFB90(int arg0)
{
    vs_battle_menuItem_t* item = &vs_battle_menuItems[arg0];
    item->state = 0;
}

void func_800FFBA8(void) { func_800CD064(7); }

void func_800FFBC8(void)
{
    if (vs_main_settings.information != 0) {
        func_800C8E04(2);
        return;
    }
    func_800FFBA8();
}

void vs_mainmenu_setMessage(char* arg0)
{
    vs_battle_memcpy(&D_8010231A, arg0, 0x60);
    D_800F4FE0[7].unk0 = ((D_800F4FE0[7].unk0 & 0xC0FFFFFF) | 0x20000000);
    func_800C6BF0(7, D_8010231A - 2);
}

void vs_mainmenu_drawButton(int index, int x, int y, u_long* data)
{
    if (data == NULL) {
        data = D_1F800000[2];
    }
    func_800C0224(0x80, (x & 0xFFFF) | (y << 0x10), 0x100010, data)[4]
        = ((index & 3) * 0x10) | ((((index & 4) * 4) + 0x80) << 8) | 0x37FB0000;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFCDC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFD64);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFE20);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFE70);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFE98);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFF38);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_800FFFBC);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100004);

void vs_mainmenu_setAbilityCost(int index, char const* text, int x, int arg3)
{
    vs_mainMenu_isLevelledSpell = 1;
    vs_battle_rMemcpy(&_textHeaders[index], text, 14);
    _textHeaders[index].unk14 = arg3;
    _textHeaders[index].x = x;
}

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100164);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100344);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100414);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_8010044C);

// https://decomp.me/scratch/Oo0p8
INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", vs_mainmenu_setMenuRows);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100814);

int func_801008B0(void) { return _selectedRow + D_801023DE; }

int vs_mainmenu_getSelectedRow(void) { return D_801023D4 != 0 ? -1 : _selectedRow; }

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_801008F0);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80100A5C);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80101118);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_80101268);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_801013F8);

INCLUDE_ASM("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", func_8010154C);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", D_800F99F8);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", D_800F9A04);

INCLUDE_RODATA("build/src/MENU/MAINMENU.PRG/nonmatchings/413C", D_800F9A08);
