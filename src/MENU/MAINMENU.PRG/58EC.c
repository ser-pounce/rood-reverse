#include "common.h"
#include "58EC.h"
#include "C48.h"
#include "413C.h"
#include "../../SLUS_010.40/overlay.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "gpu.h"
#include <libetc.h>

extern u_long* D_1F800000[];

typedef struct {
    char text[14];
    char unk14;
    char x;
} textHeader_t;

extern textHeader_t _textHeaders[];

static char D_801022C4 = 0;
static u_short* D_801022C8 = NULL;
static int D_801022CC = 0;
static char D_801022D0 = 0;
static char D_801022D1 = 0;
static char D_801022D2 = 0;
static char D_801022D3 = 0;
static char vs_mainMenu_isLevelledSpell = 0;
static char D_801022D5 = 0;
static char D_801022D6 = 0;
int D_801022D8 = 0;
char D_801022DC = 0;
static short D_801022DE = -4;
static short D_801022E0 = 128;
static char D_801022E2 = 0;
static char D_801022E3 = 0;
static int D_801022E4 = 0;
static u_short D_801022E8[] = { vs_getUV(0, 0), vs_getUV(0, 64), vs_getUV(64, 64),
    vs_getUV(100, 64), vs_getUV(132, 64), vs_getUV(188, 64), vs_getUV(0, 74) };
static int D_801022F8[] = { vs_getXY(0, 0), vs_getXY(0x3E, 10), vs_getXY(0x24, 10),
    vs_getXY(0x1E, 10), vs_getXY(0x38, 10), vs_getXY(0x1E, 10), vs_getXY(0x20, 10),
    vs_getXY(0, 0) };
#pragma vsstring(start)
static char D_80102318[] =
    "|!0|000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\0\0";
#pragma vsstring(end)
static u_short D_8010237C[] = { vs_getUV(80, 96), vs_getUV(144, 96), vs_getUV(160, 96),
    vs_getUV(112, 96), vs_getUV(128, 96), vs_getUV(176, 96), vs_getUV(208, 96),
    vs_getUV(96, 96), vs_getUV(48, 112), vs_getUV(128, 112), vs_getUV(0, 112),
    vs_getUV(16, 112), vs_getUV(32, 112), vs_getUV(224, 96), vs_getUV(64, 112),
    vs_getUV(80, 112), vs_getUV(96, 112), vs_getUV(112, 112), vs_getUV(128, 112),
    vs_getUV(144, 112), vs_getUV(160, 112), vs_getUV(32, 96), vs_getUV(176, 112),
    vs_getUV(120, 128), vs_getUV(136, 128), vs_getUV(152, 128), vs_getUV(168, 128),
    vs_getUV(184, 128), vs_getUV(200, 128), vs_getUV(216, 128), vs_getUV(232, 128),
    vs_getUV(96, 128), vs_getUV(80, 128) };
static u_char D_801023BE = 8;
static RECT D_801023C0[] = { { 640, 256, 32, 240 }, { 768, 256, 32, 240 } };
char D_801023D0 = 0;
u_short* D_801023D4 = NULL;
static int _selectedRow = 0;
static u_char D_801023DC = 0;
static char D_801023DD = 0;
static char D_801023DE = 0;
static char D_801023DF = 0;
static u_short D_801023E0 = 0;
static char D_801023E2 = 0;
char D_801023E3 = 0;
static char D_801023E4 = 11;
static char const* D_801023E8[] = { "1", "L", "1", "R" };
static int D_801023F8[] = { vs_getXY(0xD8, 8), vs_getXY(0xD2, 8), vs_getXY(0x120, 8),
    vs_getXY(0x11A, 8) };
static char D_80102408 = 0;
static char D_80102409 = 0;
static u_short _ __attribute__((unused)) = 0xF800;
static int _1 __attribute__((unused)) = 0x38B1F8F8;

extern char D_801024A0;

void func_800FF0EC(int rowCount, int arg1, char** strings, int* rowTypes)
{
    int temp_v1_2;
    int i;
    int var_a2;

    i = 0;
    var_a2 = 0;
    D_801024A0 = rowCount >> 8;
    rowCount &= 0xFF;

    if (!D_801024A0) {
        if (rowCount < 7) {
            D_801024A0 = 0xA - rowCount;
        } else {
            D_801024A0 = 3;
        }
    }

    D_801022D0 = arg1;

    if (arg1 == 4) {
        i = 1;
    } else if ((vs_main_settings.cursorMemory != 0) && (arg1 != 3)) {
        i = D_800F4EE8.unk0[arg1 * 2];
        var_a2 = D_800F4EE8.unk0[arg1 * 2 + 1];
    }
    temp_v1_2 = rowCount - 7;
    if (temp_v1_2 < 0) {
        i += var_a2;
        var_a2 = 0;
        if (i >= rowCount) {
            i = 0;
        }
    } else if (temp_v1_2 < var_a2) {
        if ((i + var_a2) >= rowCount) {
            i = 0;
            var_a2 = 0;
        } else {
            i += var_a2 - temp_v1_2;
            var_a2 = temp_v1_2;
        }
    }

    if ((var_a2 > 0) && (i == 0)) {
        i = 1;
        --var_a2;
    }
    if (var_a2 < temp_v1_2) {
        if (i == 6) {
            i = 5;
            ++var_a2;
        }
    }
    D_801022CC = i;
    D_801022D2 = var_a2;
    D_801022D1 = rowCount;
    D_801022C4 = 0;
    D_801022C8 = vs_main_allocHeapR(rowCount << 7);

    for (i = 0; i < rowCount; ++i) {
        char* s;
        *((int*)(&(&D_801022C8[i * 0x40])[14])) = rowTypes[i];

        if (strings[i * 2] != NULL) {
            vs_battle_copyAligned(&D_801022C8[i * 0x40], strings[i * 2], 0x1A);
            D_801022C8[(i * 0x40) + 13] = 0xE7E7;
        } else {
            D_801022C8[i * 0x40] = 0xE7E7;
        }

        s = strings[i * 2 + 1];
        if (s != NULL) {
            D_801022C8[(i * 0x40) + 16] = 0xF8;
            vs_battle_copyAligned(&D_801022C8[(i * 0x40) + 17], s, 0x5C);
            D_801022C8[(i * 0x40) + 63] = 0xE7E7;
        } else {
            D_801022C8[(i * 0x40) + 16] = 0xE7E7;
        }
    }
}

int func_800FF348(void) { return D_801022CC + D_801022D2; }

int func_800FF360(void) { return D_801022C8 == NULL ? D_801022CC : -1; }

vs_battle_menuItem_t* func_800FF388(int arg0, int arg1)
{
    vs_battle_menuItem_t* temp_v0 =
        vs_battle_setMenuItem(arg0 + 0x20, arg1, ((arg0 + D_801024A0) * 0x10) + 0x12,
            0x7E, 0, (char*)&D_801022C8[(D_801022D2 + arg0) * 0x40]);
    int v = *((int*)&D_801022C8[(D_801022D2 + arg0) * 0x40 + 14]);
    temp_v0->unk7 = v & 1;
    if ((arg0 == 0) && (D_801022D2 != 0)) {
        temp_v0->unk5 = 1;
    }
    return temp_v0;
}

void func_800FF43C(void)
{
    int temp_s6;
    int var_a0;
    int i;
    int temp_s5;
    int var_s1;
    vs_battle_menuItem_t* menuItem;

    if (D_801022C4 < 0xA) {
        menuItem = func_800FF388(D_801022C4, -0xC2);
        menuItem->state = 5;
        menuItem->targetX = 0;
        ++D_801022C4;
        if (D_801022C4 == D_801022D1) {
            D_801022C4 = 0x10;
        }
        if (D_801022C4 == 7) {
            if ((D_801022C4 + D_801022D2) < D_801022D1) {
                menuItem->unk5 = 2;
            }
            D_801022C4 = 0x10;
        }
    } else {
        menuItem = vs_battle_getMenuItem(D_801022CC + 32);
        vs_mainmenu_setMessage(
            (char*)(D_801022C8 + (((D_801022CC + D_801022D2) << 6) + 16)));

        switch (D_801022C4) {
        case 16:
            if (vs_mainmenu_ready() != 0) {
                D_801022C4 = 0x11;
                return;
            }
            return;
        case 17:
            temp_s6 = D_801022CC + D_801022D2;
            temp_s5 = D_801022D2;
            if (vs_main_buttonsPressed.all & 0x10) {
                vs_main_freeHeapR(D_801022C8);
                D_801022C8 = NULL;
                D_800F4EE8.unk0[D_801022D0 * 2] = D_801022CC;
                D_800F4EE8.unk0[D_801022D0 * 2 + 1] = D_801022D2;
                D_801022CC = -3;
                return;
            }
            if (vs_main_buttonsPressed.all & 0x20) {
                if (menuItem->unk7 == 0) {
                    menuItem->selected = 1;
                    vs_main_freeHeapR(D_801022C8);
                    D_801022C8 = NULL;
                    D_800F4EE8.unk0[D_801022D0 * 2] = D_801022CC;
                    D_800F4EE8.unk0[D_801022D0 * 2 + 1] = D_801022D2;
                    D_801022CC = temp_s6;
                    return;
                }
                func_800C02E0();
            }
            menuItem->selected = 0;
            if (vs_main_buttonsPressed.all & 0x40) {
                vs_main_freeHeapR(D_801022C8);
                D_801022C8 = NULL;
                D_800F4EE8.unk0[D_801022D0 * 2] = D_801022CC;
                D_800F4EE8.unk0[D_801022D0 * 2 + 1] = D_801022D2;
                D_801022CC = -2;
                return;
            }
            if (vs_main_buttonRepeat & 0x1000) {
                if (D_801022D1 < 8) {
                    if (D_801022CC == 0) {
                        D_801022CC = D_801022D1 - 1;
                    } else {
                        --D_801022CC;
                    }
                } else if (D_801022D2 == 0) {
                    if (D_801022CC == 0) {
                        if (vs_main_buttonsPressed.all & 0x1000) {
                            D_801022CC = 6;
                            D_801022D2 = D_801022D1 - 7;
                        }
                    } else {
                        --D_801022CC;
                    }
                } else if (D_801022CC == 1) {
                    --D_801022D2;
                } else {
                    --D_801022CC;
                }
            }
            if (vs_main_buttonRepeat & 0x4000) {
                if (D_801022D1 < 8) {
                    if (D_801022CC == (D_801022D1 - 1)) {
                        D_801022CC = 0;
                    } else {
                        ++D_801022CC;
                    }
                } else if (D_801022D2 == (D_801022D1 - 7)) {
                    if (D_801022CC == 6) {
                        if (vs_main_buttonsPressed.all & 0x4000) {
                            D_801022CC = 0;
                            D_801022D2 = 0;
                        }
                    } else {
                        ++D_801022CC;
                    }
                } else if (D_801022CC == 5) {
                    D_801022D2 = D_801022D2 + 1;
                } else {
                    D_801022CC += 1;
                }
            }
            if (temp_s6 != (D_801022CC + D_801022D2)) {
                vs_battle_playMenuChangeSfx();

                if (D_801022D2 != temp_s5) {
                    char unksp10[D_801022D1];
                    for (i = 0; i < D_801022D1; ++i) {
                        unksp10[i] = 0;
                    }
                    var_s1 = D_801022D1;
                    if (var_s1 >= 8U) {
                        var_s1 = 7;
                    }
                    for (i = 0; i < var_s1; ++i) {
                        unksp10[i + temp_s5] = vs_battle_getMenuItem(i + 0x20)->unk4;
                    }

                    var_a0 = 0;
                    for (i = 0;;) {
                        menuItem = func_800FF388(i, 0);
                        menuItem->unk4 = unksp10[i + D_801022D2];
                        i += 1;

                        if (i == D_801022D1) {
                            break;
                        }

                        if (i == 7) {
                            if ((D_801022D2 + 7) < D_801022D1) {
                                menuItem->unk5 = 2;
                            }
                            break;
                        }
                    }
                }
            }
            menuItem = vs_battle_getMenuItem(D_801022CC + 0x20);
            menuItem->selected = 1;
            D_801022D3 = func_800FFCDC((u_int)D_801022D3, (menuItem->y - 8) << 0x10);
            break;
        }
    }
}

void vs_mainMenu_printInformation(int arg0, int arg1)
{
    if (arg1 >= 16) {
        if (vs_battle_rowTypeBuf[arg0] & 1) {
            if ((vs_main_settings.information == 0)
                && (vs_main_buttonsState & (PADLup | PADLdown))) {
                return;
            }
            func_800C8E04(1);
            D_800F514C = 0xB;
        } else if (vs_main_settings.information != 0) {
            func_800C8E04(2);
            D_800F514C = 0xB;
        } else {
            D_800F514C = 0;
        }
    }
}

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

void vs_mainMenu_deactivateMenuItem(int arg0)
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
    vs_battle_memcpy(&D_80102318[2], arg0, 0x60);
    D_800F4FE0[7].unk0.fields.unk3_0 = 32;
    func_800C6BF0(7, D_80102318);
}

void vs_mainmenu_drawButton(int index, int x, int y, u_long* data)
{
    if (data == NULL) {
        data = D_1F800000[2];
    }
    func_800C0224(0x80, (x & 0xFFFF) | (y << 0x10), 0x100010, data)[4] =
        ((index & 3) * 0x10) | ((((index & 4) * 4) + 0x80) << 8) | 0x37FB0000;
}

int func_800FFCDC(u_int arg0, int arg1)
{
    int var_a0;
    int temp_s0;
    u_long* temp_a1;

    temp_s0 = arg0 >> (D_801022D5 * 8);
    temp_a1 = func_800C0224(D_800EC270[temp_s0], arg1, 0x100010, D_1F800000[2]);

    if (D_801022D5 == 0) {
        var_a0 = 0x37F83020;
    } else {
        var_a0 = 0x37FA3020;
    }
    temp_a1[4] = var_a0;
    D_801022D5 = 0;
    return (temp_s0 + 1) & 0xF;
}

int vs_mainMenu_printIntColor(int arg0, int arg1, int arg2, u_long* arg3)
{
    int sp10;
    int var_s0 = arg0;

    if (arg0 < 0) {
        var_s0 = -arg0;
    }

    do {
        var_s0 = vs_battle_toBCD(var_s0);
        sp10 = ((var_s0 & 0xF) << 8) | ('0' << 8) | '#';
        vs_battle_renderTextRawColor((char*)&sp10, arg1, arg2, arg3);
        var_s0 = var_s0 >> 4;
        arg1 -= 8;
    } while (var_s0 != 0);

    if (arg0 < 0) {
        sp10 = ('-' << 8) | '#';
        vs_battle_renderTextRawColor((char*)&sp10, arg1 + 1, arg2, arg3);
    }

    return arg1;
}

int func_800FFE20(int arg0, int arg1, int arg2, u_long* arg3)
{
    int var_a2;

    var_a2 = 0x808080;
    if (arg2 < arg0) {
        var_a2 = 0x804020;
    }
    if (arg0 < arg2) {
        var_a2 = 0x204080;
    }
    return vs_mainMenu_printIntColor(arg0, arg1, var_a2, arg3);
}

void func_800FFE70(int arg0, int arg1, u_long* arg2)
{
    vs_mainMenu_printIntColor(arg0, arg1, 0x808080, arg2);
}

void func_800FFE98(int arg0, int arg1, int arg2, u_long* arg3)
{
    int i = 0;

    if (arg0 < 0) {
        arg1 += 0xF0000;
        arg2 += 0xF00;
    }

    do {
        ++i;
        func_800C0224((i * 8) | 0x100, arg1, 0x10010, arg3)[4] = arg2;
        arg1 += arg0 << 0x10;
        arg2 += arg0 << 8;
    } while (i < 16);
}

void func_800FFF38(int arg0, int arg1)
{
    u_long* temp_a1;
    int new_var2;

    temp_a1 = func_800C0214(0x70007, arg1);
    new_var2 = (((arg0 / 3) * 8) + 0xD8) | ((((arg0 % 3) * 8) + 0xC8) << 8);
    if (arg0 == 2) {
        temp_a1[4] = new_var2 | 0x37FA0000;
    } else {
        temp_a1[4] = new_var2 | 0x37F90000;
    }
}

void func_800FFFBC(int arg0, int arg1)
{
    func_800C0214(0x100010, arg1)[4] = (0x60 - (arg0 * 0x10)) | 0x37FD8000;
}

void vs_mainMenu_drawRowIcon(int arg0, int arg1, int arg2)
{
    int v1;
    int var_a0;
    u_long* temp_v0;

    var_a0 = arg0 >> 0x10;
    v1 = (arg0 >> 8) & 1;
    arg0 = (arg0 - 1) & 0xFF;

    if (var_a0 == 0) {
        temp_v0 = func_800C0224(
            0x40 << v1, (arg1 & 0xFFFF) | (arg2 << 0x10), 0x100010, D_1F800000[2] + 1);
        temp_v0[4] = D_8010237C[arg0] | 0x37FE0000;
        if (arg0 >= 0x17) {
            temp_v0[3] -= 12;
            temp_v0[4] = D_8010237C[arg0] | 0x37FD0000;
        }
    } else {
        if (var_a0 == 2) {
            var_a0 = -1;
        }
        func_800FFE98(var_a0, (arg1 & 0xFFFF) | (arg2 << 0x10),
            D_8010237C[arg0] | 0x37FE0000, D_1F800000[2] + 1);
    }
}

void vs_mainmenu_setAbilityCost(int index, char const* text, int x, int arg3)
{
    vs_mainMenu_isLevelledSpell = 1;
    vs_battle_rMemcpy(&_textHeaders[index], text, 14);
    _textHeaders[index].unk14 = arg3;
    _textHeaders[index].x = x;
}

void func_80100164(void)
{
    int temp_s2;
    int temp_t1;
    int var_s1;
    u_long* temp_s5;
    u_long* temp_v1_2;

    temp_s5 = D_1F800000[1] - 1;

    if (vs_mainMenu_isLevelledSpell != 0) {
        if (D_801023BE != 0) {
            --D_801023BE;
        }
    } else {
        if (D_801023BE < 5) {
            D_801023BE = 5;
        } else if (D_801023BE < 8) {
            ++D_801023BE;
        }
    }

    if (D_801023BE < 8) {
        temp_s2 = -vs_battle_rowAnimationSteps[D_801023BE];

        for (var_s1 = 0; var_s1 < 2; ++var_s1) {
            vs_battle_renderTextRawColor(_textHeaders[var_s1].text,
                ((temp_s2 + _textHeaders[var_s1].x) & 0xFFFF) | 0xA00000,
                0x808080 >> _textHeaders[var_s1].unk14, NULL);
        }

        temp_t1 = temp_s2 & 0xFFFF;
        temp_v1_2 = D_1F800000[0];
        temp_v1_2[0] = (*temp_s5 & 0xFFFFFF) | 0x0A000000;
        temp_v1_2[1] = 0xE1000200;
        temp_v1_2[2] = 0x38200808;
        temp_v1_2[3] = temp_t1 | 0xA00000;
        temp_v1_2[4] = 0x663040;
        temp_v1_2[5] = (temp_s2 + 0x50) | 0xA00000;
        temp_v1_2[6] = 0x200808;
        temp_v1_2[7] = temp_t1 | 0xAB0000;
        temp_v1_2[8] = 0x663040;
        temp_v1_2[9] = (temp_s2 + 0x50) | 0xAB0000;
        temp_v1_2[10] = 0xE1000000;
        *temp_s5 = ((u_long)temp_v1_2 << 8) >> 8;
        D_1F800000[0] = temp_v1_2 + 11;
        func_800CCCB8(temp_s5, 0x60000000, temp_t1 | 0xA20000, 0xB0052);
    }
}

void vs_mainMenu_drawButtonUiBackground(int arg0, int arg1, int arg2, int count)
{
    int i;
    u_long* var_t2 = D_1F800000[0];
    u_long* temp_v1 = D_1F800000[1] - 3;

    for (i = 0; i < count; ++i) {
        var_t2[0] = vs_getTag(u_long[6], temp_v1[0]);
        var_t2[1] = vs_getTpage(0, 0, 0, 0, ditheringOn);
        var_t2[2] = vs_getRGB0(primLineG2, 0x40, 0x38, 0x20);
        var_t2[3] = ((arg0 & 0xFFFF) | ((arg1 + i) << 0x10));
        var_t2[4] = vs_getRGB888(16, 16, 8);
        var_t2[5] = ((((arg0 + arg2) - i) & 0xFFFF) | ((arg1 + i) << 0x10));
        var_t2[6] = vs_getTpage(0, 0, 0, 0, ditheringOff);
        temp_v1[0] = (((u_long)var_t2 << 8) >> 8);
        var_t2 += 7;
    }
    D_1F800000[0] = var_t2;
}

void func_80100414(int arg0, int arg1)
{
    if (arg0 > 0) {
        D_800F4E90 |= 2;
    } else {
        D_800F4E90 &= 1;
    }
    D_801022DE = arg0;
    D_801022E0 = arg1;
}

void func_8010044C(u_int* arg0)
{
    int var_a2;
    int i;
    u_int var_v1;
    u_int temp_a0;
    u_int* temp_t1;
    void* temp_s1;

    temp_s1 = vs_overlay_slots[2];
    temp_t1 = temp_s1 + 0x200;

    for (i = 0, var_a2 = 0; i < 0x1780;) {
        temp_a0 = temp_t1[i++];
        for (var_v1 = temp_a0 & 0xFFFF; var_v1 != 0; --var_v1) {
            arg0[var_a2++] = 0;
        }

        for (var_v1 = temp_a0 >> 0x10; var_v1 != 0; --var_v1) {
            arg0[var_a2++] = temp_t1[i++];
        }
    }

    func_8007DFF0(0x1A, 3, 6);
    ClearImage(&D_801023C0[0], 0, 0, 0);
    ClearImage(&D_801023C0[1], 0, 0, 0);

    if (((vs_battle_menuState.currentState & 0x3F) == 7) && (D_800F4EA0 & 0x200)
        && (vs_main_stateFlags.gameOver == 1)) {
        vs_battle_drawImage(0x01FF0280, temp_s1, 0x10100);
    } else {
        func_80048A64((u_short*)temp_s1, 3, 0, 0x100);
    }

    vs_battle_drawImage(0x010002A0, arg0, 0xF00060);
    func_80100414(-4, 0x80);
}

void vs_mainmenu_setMenuRows(int rowCount, int arg1, char** strings, int* rowTypes)
{
    int temp_v1_2;
    int i;
    int var_v0;
    int temp_a0;
    u_int var_a0;
    int var_a2;

    i = 0;
    var_a2 = 0;
    temp_a0 = arg1 & 0xFF;
    D_801023DF = (arg1 >> 0xC);
    D_801023DC = temp_a0;
    arg1 = (arg1 >> 8) & 0xF;

    if (vs_main_settings.cursorMemory != 0) {
        i = D_800F4EE8.unk0[temp_a0 * 2];
        var_a2 = D_800F4EE8.unk0[temp_a0 * 2 + 1];
    }

    temp_v1_2 = 0xA;
    temp_v1_2 = rowCount - temp_v1_2 + arg1;

    if (temp_v1_2 < 0) {
        i += var_a2;
        var_a2 = 0;
        if (i >= rowCount) {
            i = 0;
        }
    } else {
        if (temp_v1_2 < var_a2) {
            if ((i + var_a2) >= rowCount) {
                i = 0;
                var_a2 = 0;
            } else {
                i += var_a2 - temp_v1_2;
                var_a2 = temp_v1_2;
            }
        }

        var_v0 = var_a2 < temp_v1_2;

        if ((var_a2 > 0) && (i == 0)) {
            i = 1;
            var_a2 -= 1;
            var_v0 = var_a2 < temp_v1_2;
        }

        if (var_v0 != 0) {
            var_a0 = rowCount << 7;
            if (i == (9 - arg1)) {
                i -= 1;
                var_a2 += 1;
                ;
            }
        }
    }

    _selectedRow = i;

    D_801023DE = var_a2;
    D_801023E0 = rowCount;
    D_801023DD = arg1;
    D_801023D0 = 0;
    D_801023D4 = vs_main_allocHeapR(rowCount << 7);

    for (i = 0; i < rowCount; ++i) {
        char* s;
        *((int*)(&(&D_801023D4[i * 0x40])[14])) = rowTypes[i];

        if (strings[i * 2] != NULL) {
            vs_battle_copyAligned(&D_801023D4[i * 0x40], strings[i * 2], 0x1A);
            D_801023D4[(i * 0x40) + 13] = 0xE7E7;
        } else {
            D_801023D4[i * 0x40] = 0xE7E7;
        }

        s = strings[i * 2 + 1];
        if (s != NULL) {
            D_801023D4[(i * 0x40) + 16] = 0xF8;
            vs_battle_copyAligned(&D_801023D4[(i * 0x40) + 17], s, 0x5C);
            D_801023D4[(i * 0x40) + 63] = 0xE7E7;
        } else {
            D_801023D4[(i * 0x40) + 16] = 0xE7E7;
        }
    }
}

int func_80100814(void)
{
    vs_main_freeHeapR(D_801023D4);
    D_801023D4 = NULL;
    D_800F4EE8.unk0[D_801023DC * 2] = _selectedRow;
    D_800F4EE8.unk0[D_801023DC * 2 + 1] = D_801023DE;
    return (_selectedRow + D_801023DE) | ((_selectedRow + (D_801023DD * 10)) << 8);
}

int func_801008B0(void) { return _selectedRow + D_801023DE; }

int vs_mainmenu_getSelectedRow(void) { return D_801023D4 != NULL ? -1 : _selectedRow; }

vs_battle_menuItem_t* func_801008F0(int arg0, int arg1)
{
    int temp_a1;
    int temp_v1;
    vs_battle_menuItem_t* temp_v0 = vs_battle_setMenuItem(arg0 + (D_801023DD * 0xA), arg1,
        ((arg0 + D_801023DD) * 0x10) + 0x12, D_801023DF + 0x7E, 0,
        (char*)&D_801023D4[(D_801023DE + arg0) * 0x40]);

    temp_a1 = *((int*)(&(&D_801023D4[(D_801023DE + arg0) * 0x40])[14]));
    temp_v0->unk7 = temp_a1 & 1;
    temp_v0->unk2 = temp_v0->unk2 + ((temp_a1 & 2) * 0xC);
    temp_v1 = (temp_a1 >> 3) & 1;
    temp_v0->unkB = temp_v1;
    temp_v0->unkA = temp_v1 | ((temp_a1 >> 2) & 1);
    temp_v0->icon = (temp_a1 >> 0x1A);
    if ((arg0 == 0) && (D_801023DE != 0)) {
        temp_v0->unk5 = 1;
    }
    arg0 = (temp_a1 >> 9) & 0x7F;
    if (arg0 < 0x65) {
        temp_v0->unk10 = arg0;
    } else if (arg0 < 0x67) {
        temp_v0->itemState = arg0 - 0x64;
    } else {
        temp_v0->unk3C = vs_battle_hitlocations[arg0 - 0x67];
    }
    temp_v0->material = (temp_a1 >> 0x10) & 7;
    temp_v0->unk12 = (temp_a1 >> 0x13) & 0x7F;
    return temp_v0;
}

void func_80100A5C(void)
{
    int temp_s6;
    int temp_v1;
    int i;
    int var_s1;
    int temp_s5;
    vs_battle_menuItem_t* menuItem;

    if (D_801023E0 == 0) {
        if (D_801023D4 != NULL) {
            vs_main_freeHeapR(D_801023D4);
            D_801023D4 = NULL;
        }
        _selectedRow = -2;
        return;
    }
    if (D_801023D0 < 0xAU) {
        menuItem = func_801008F0(D_801023D0, 0x140);
        menuItem->state = 2;
        ++D_801023D0;
        menuItem->targetX = 0xC2 - D_801023DF;
        if (D_801023D0 == D_801023E0) {
            D_801023D0 = 0x10;
        }
        if (D_801023D0 == (0xA - D_801023DD)) {
            if ((D_801023D0 + D_801023DE) < D_801023E0) {
                menuItem->unk5 = 2;
            }
            D_801023D0 = 0x10;
        }
    } else {

        menuItem = vs_battle_getMenuItem(_selectedRow + (D_801023DD * 10));
        vs_mainmenu_setMessage(
            (char*)(D_801023D4 + (((_selectedRow + D_801023DE) << 6) + 16)));

        switch (D_801023D0) {
        case 16:
            if (vs_mainmenu_ready() != 0) {
                D_801023D0 = 0x11;
                return;
            }
            return;
        case 17:
            temp_s6 = _selectedRow + D_801023DE;
            temp_s5 = D_801023DE;
            if (vs_main_buttonsPressed.all & 0x10) {
                vs_battle_playMenuLeaveSfx();
                vs_main_freeHeapR(D_801023D4);
                D_801023D4 = NULL;
                D_800F4EE8.unk0[D_801023DC * 2] = _selectedRow;
                D_800F4EE8.unk0[D_801023DC * 2 + 1] = D_801023DE;
                _selectedRow = -3;
                return;
            }
            if (vs_main_buttonsPressed.all & 0x20) {
                if (menuItem->unk7 == 0) {
                    menuItem->selected = 1;
                    vs_battle_playMenuSelectSfx();
                    vs_main_freeHeapR(D_801023D4);
                    D_801023D4 = NULL;
                    D_800F4EE8.unk0[D_801023DC * 2] = _selectedRow;
                    D_800F4EE8.unk0[D_801023DC * 2 + 1] = D_801023DE;
                    _selectedRow = temp_s6;
                    return;
                }
                func_800C02E0();
            }
            menuItem->selected = 0;
            if (vs_main_buttonsPressed.all & 0x40) {
                vs_battle_playMenuLeaveSfx();
                vs_main_freeHeapR(D_801023D4);
                D_801023D4 = NULL;
                D_800F4EE8.unk0[D_801023DC * 2] = _selectedRow;
                D_800F4EE8.unk0[D_801023DC * 2 + 1] = D_801023DE;
                _selectedRow = -2;
                return;
            }
            if (vs_main_buttonRepeat & 0x1000) {
                if (D_801023E0 <= (10 - D_801023DD)) {
                    if (_selectedRow == 0) {
                        _selectedRow = D_801023E0 - 1;
                    } else {
                        --_selectedRow;
                    }
                } else if (D_801023DE == 0) {
                    if (_selectedRow == 0) {
                        if (vs_main_buttonsPressed.all & 0x1000) {
                            _selectedRow = 9 - D_801023DD;
                            D_801023DE = D_801023DD + (D_801023E0 + 0xF6);
                        }
                    } else {
                        --_selectedRow;
                    }
                } else if (_selectedRow == 1) {
                    --D_801023DE;
                } else {
                    --_selectedRow;
                }
            }
            if (vs_main_buttonRepeat & 0x4000) {
                if (D_801023E0 <= (10 - D_801023DD)) {
                    if (_selectedRow == (D_801023E0 - 1)) {
                        _selectedRow = 0;
                    } else {
                        ++_selectedRow;
                    }
                } else if (D_801023DE == (D_801023E0 + (D_801023DD - 10))) {
                    if (_selectedRow == (9 - D_801023DD)) {
                        if (vs_main_buttonsPressed.all & 0x4000) {
                            _selectedRow = 0;
                            D_801023DE = 0;
                        }
                    } else {
                        ++_selectedRow;
                    }
                } else if (_selectedRow == (8 - D_801023DD)) {
                    ++D_801023DE;
                } else {
                    ++_selectedRow;
                }
            }
            if (temp_s6 != (_selectedRow + D_801023DE)) {
                vs_battle_playMenuChangeSfx();

                if (D_801023DE != temp_s5) {
                    char unksp10[D_801023E0];
                    for (i = 0; i < D_801023E0; ++i) {
                        unksp10[i] = 0;
                    }
                    var_s1 = D_801023E0;
                    temp_v1 = 10 - D_801023DD;
                    if (temp_v1 < var_s1) {
                        var_s1 = temp_v1;
                    }

                    for (i = 0; i < var_s1; ++i) {
                        unksp10[i + temp_s5] =
                            vs_battle_getMenuItem(i + (D_801023DD * 10))->unk4;
                    }
                    for (i = 0;;) {
                        menuItem = func_801008F0(i, 0xC2 - D_801023DF);
                        menuItem->unk4 = unksp10[i + D_801023DE];
                        i += 1;

                        if (i == D_801023E0) {
                            break;
                        }
                        if (i == (10 - D_801023DD)) {
                            if ((i + D_801023DE) < D_801023E0) {
                                menuItem->unk5 = 2;
                            }
                            break;
                        }
                    }
                }
            }
            vs_battle_getMenuItem(_selectedRow + (D_801023DD * 0xA))->selected = 1;
            D_801023E2 = func_800FFCDC((u_int)D_801023E2,
                (0xB4 - D_801023DF)
                    | ((((_selectedRow + D_801023DD) * 0x10) + 0xA) << 0x10));
            break;
        }
    }
}

void func_80101118(int arg0)
{
    int var_a0;
    int temp_s4;
    int var_s3;
    u_long* temp_s2;
    u_long* temp_v0;

    var_s3 = 0;
    temp_s2 = D_1F800000[1] + D_801022DE;

    if (vs_main_frameBuf == 0) {
        var_s3 = 0x140;
    }

    arg0 *= 8;
    temp_s4 = arg0 == 0x80;

    if (temp_s4 != 0) {
        arg0 = D_801022E0;
        var_a0 = arg0;
    } else {
        arg0 = arg0 | 0x100;
        var_a0 = arg0;
    }
    temp_v0 = vs_battle_setSprite(var_a0, 0x100, 0xF00040, temp_s2);
    temp_v0[1] = 0xE10000BC;
    temp_v0[4] = 0x38F00000;

    temp_v0 = vs_battle_setSprite(arg0, 0, 0xF00100, temp_s2);
    temp_v0[1] = 0xE10000BA;
    temp_v0[4] = 0x38F00000;

    if (temp_s4 == 0) {
        int new_var = 0x120;
        arg0 = 0x180 - arg0;
        vs_battle_setSprite(arg0, 0, 0xF00100, temp_s2)[1] =
            (((u_int)var_s3 >> 6) | new_var | 0xE1000000);
        vs_battle_setSprite(arg0, 0x100, 0xF00040, temp_s2)[1] =
            (((var_s3 + 0x100) >> 6) | new_var | 0xE1000000);
    }
}

int func_80101268(u_int arg0, int arg1, vs_battle_menuItem_t* arg2, u_long* arg3)
{
    int i;
    int var_s2;
    u_long* temp_v0_2;
    int new_var;

    int s7 = arg0 >> 0x1F;
    arg0 &= 0xFFFF;
    new_var = 0xE5;

    if ((arg0 < new_var) && (arg0 == 0x8F)) {
        do {
            do {
                return arg1 + 6;
            } while (0);
        } while (0);
    }

    i = arg2->unkA * 0x10;

    if (arg2->unkA == 0) {
        i = arg2->unk7 * 0x30;
    }

    var_s2 = (((arg0 & 0x1FF) % 21) * 0xC) | (((arg0 & 0x1FF) / 21) * 0xC00)
           | (((((i + 0x380) >> 4) & 0x3F) | 0x3780) << 0x10);

    for (i = 0; i < 12; ++i) {

        temp_v0_2 = vs_battle_setSprite(s7 == 0 ? (i * 8) + 0x108 : 0x160 - (i * 8),
            (arg1 & 0xFFFF) | ((arg2->y + i) << 0x10), 0x1000C, arg3);
        temp_v0_2[4] = var_s2;
        temp_v0_2[1] = 0xE100002D;
        var_s2 += 0x100;
    }

    return arg1 + D_800EB810[arg0];
}

void func_801013F8(int arg0)
{
    int i;
    int color;
    int var_s4;
    u_int temp_s5;

    var_s4 = 0x37F90000;
    color = 0x404040;

    if ((D_801023E3 != 0) || (D_801023E4 != 0xB)) {
        var_s4 = 0x37F80000;
        ++D_801023E4;
        color = 0x808080;
        if (D_801023E4 >= 12) {
            D_801023E4 = 0;
        }
    }

    temp_s5 = D_801023E4 >> 2;

    if (arg0 != 0) {
        for (i = 0; i < 4; ++i) {
            vs_battle_renderTextRawColor(D_801023E8[i], D_801023F8[i], color, NULL);
        }
        i = 0x500C8;
    } else {
        i = 0x100010;
    }
    func_800C0214(0x100010, i - temp_s5)[4] = var_s4 | 0x3000;

    i = 0x1100A2;
    if (arg0 != 0) {
        i = 0x60124;
    }
    func_800C0214(0x100010, i + temp_s5)[4] = var_s4 | 0x3010;
}

void func_8010154C(vs_battle_menuItem_t* arg0)
{
    int sp10;
    u_int sp14;
    int sp18;
    int sp1C;
    int temp_v1;
    int temp_fp;
    int temp_v1_2;
    int i;
    u_long* var_s2;
    int var_s3;
    u_int var_s5;
    int temp_a0;
    u_int temp_v0_3;
    u_long* temp_s7;

    char* ptr = &arg0->text[0];
    sp14 = 0;

    if (vs_main_frameBuf == 0) {
        sp14 = 0x140;
    }

    var_s5 = *(int*)&arg0->initialX;
    temp_s7 = D_1F800000[2] + 2;
    sp10 = arg0->w;
    sp18 = arg0->unk4;
    temp_fp = arg0->unk5 - 1;
    sp1C = arg0->unk2;

    if (vs_main_frameBuf != D_80102408) {
        ++D_80102409;
        D_80102408 = vs_main_frameBuf;
        if (D_80102409 >= 0xC) {
            D_80102409 = 0;
        }
    }

    var_s3 = D_80102409 >> 2;
    var_s3 = temp_fp == 0 ? var_s3 - 5 : 1 - var_s3;

    if (arg0->initialX == 0) {
        for (i = 32; i < 40; ++i) {
            if (vs_battle_getMenuItem(i)->state >= 2) {
                break;
            }
        }
        if (i == 0x28) {
            var_s2 = temp_s7 - 2;
            func_800C0224(0x80, ((arg0->y + var_s3) << 0x10) | 0x7E, 0x100010,
                var_s2)[4] = ((temp_fp * 0x10) | 0x37F93000);
        }
    } else {
        for (i = 0; i < 32; ++i) {
            if (vs_battle_getMenuItem(i)->state >= 2) {
                break;
            }
        }
        if (i == 0x20) {
            func_800C0224(0x80,
                ((arg0->initialX - 0xE) & 0xFFFF) | ((arg0->y + var_s3) << 0x10),
                0x100010, temp_s7 - 2)[4] = (int)((temp_fp * 0x10) | 0x37F93000);
        }
    }

    temp_v1 = arg0->initialX;

    i = temp_v1 + 6;
    if (arg0->icon != 0) {
        i = temp_v1 + 0x16;
    }

    while ((var_s3 = *ptr++) != 0xFF) {
        if (var_s3 == 0xFA) {
            i += *ptr++;
        } else {
            i = func_80101268(var_s3 | (temp_fp << 0x1F), i, arg0, temp_s7);
        }
    }

    if (sp10 != 0) {
        var_s2 = D_1F800000[0];

        for (i = 0; i < 12; ++i) {
            if (temp_fp == 0) {
                var_s3 = i * 8 + 0x20;
            } else {
                var_s3 = 0x78 - i * 8;
            }
            var_s2[0] = (*temp_s7 & 0xFFFFFF) | 0x06000000;
            var_s2[1] = 0xE1000220;
            var_s2[2] = (func_800C8FAC(8 - sp18, sp1C, var_s3) | 0x52000000);
            var_s2[3] = var_s5;
            var_s2[4] = func_800C8FAC(sp18, sp1C, var_s3);
            var_s2[5] = ((var_s5 + sp10 - 1) & 0xFFFF) | ((var_s5 >> 0x10) << 0x10);
            var_s2[6] = 0xE1000020;
            temp_v0_3 = (u_long)var_s2 << 8;
            var_s2 += 7;
            *temp_s7 = temp_v0_3 >> 8;
            var_s5 += 0x10000;
        }

        D_1F800000[0] = var_s2;

        if (temp_fp == 0) {
            func_800CCCB8(temp_s7, 0x60000000,
                ((var_s5 + 2) & 0xFFFF) | ((var_s5 >> 0x10) << 0x10), sp10 | 0x20000);
        }

        if (sp18 != 0) {
            arg0->unk4 = sp18 - 1;
        }

        var_s5 = var_s5 + 0xFFF40000;

        sp10 |= 0x10000;
        var_s3 = ((arg0->initialX < 0x80) ^ 1) << 7;

        for (i = 0; i < 12; ++i) {
            var_s2 = vs_battle_setSprite(
                temp_fp == 0 ? 0x78 - i * 8 : i * 8 + 0x20, var_s5, sp10, temp_s7);
            temp_v1_2 = (var_s5 - var_s3);
            temp_a0 = var_s5 >> 0x10;
            var_s5 += 0x10000;
            var_s2[1] = ((sp14 + var_s3) >> 6) | 0xE1000120;
            var_s2[4] = temp_v1_2 & 0xFF;
            var_s2[4] = var_s2[4] | (temp_a0 << 8);
        }
    }
}

extern char const D_800F9A04[];
extern char const D_800F9A08[];

void func_80101970(void)
{
    int target;
    int origin;
    int temp_a1;
    int temp_s0;
    int j;
    int i;
    int var_v1;
    u_long* temp_s3;
    vs_battle_menuItem_t* menuItem = vs_battle_menuItems;

    for (i = 0; i < 40; ++i, ++menuItem) {
        j = menuItem->state;

        if (j == 0) {
            continue;
        }

        switch (j) {
        case 1:
            break;
        case 2:
            origin = menuItem->initialX;
            target = menuItem->targetX;
            if (origin < target) {
                origin += 32;
                if (target < origin) {
                    origin = target;
                }
            } else {
                if (target < origin) {
                    for (j = 1; j < 16; ++j) {
                        if ((target + vs_battle_rowAnimationSteps[j]) >= origin) {
                            break;
                        }
                    }
                    origin = target + vs_battle_rowAnimationSteps[j - 1];
                    if (target >= 155) {
                        if (menuItem->w < (320 - origin)) {
                            menuItem->w = 64 - origin;
                            if ((320 - origin) > 165) {
                                menuItem->w = 165;
                            }
                        }
                    }
                }
            }
            menuItem->initialX = origin;
            if (origin == target) {
                menuItem->state = 1;
            }
            break;
        case 3:
            origin = menuItem->y;
            target = menuItem->targetX;
            if (origin < target) {
                for (j = 1; j < 16; ++j) {
                    if (origin >= (target - vs_battle_rowAnimationSteps[j])) {
                        break;
                    }
                }
                origin = target - vs_battle_rowAnimationSteps[j - 1];
            } else {
                if (target < origin) {
                    for (j = 1; j < 16; ++j) {
                        if ((target + vs_battle_rowAnimationSteps[j]) >= origin) {
                            break;
                        }
                    }
                    origin = target + vs_battle_rowAnimationSteps[j - 1];
                }
            }
            menuItem->y = origin;
            if (origin == target) {
                menuItem->state = 1;
            }
            break;
        case 4:
            origin = menuItem->initialX;
            target = menuItem->targetX;
            if (origin != target) {
                for (j = 1; j < 16; ++j) {
                    if ((target + vs_battle_rowAnimationSteps[j]) >= origin) {
                        break;
                    }
                }
                menuItem->initialX = vs_battle_rowAnimationSteps[j - 1] + target;
                if (menuItem->w < (320 - menuItem->initialX)) {
                    menuItem->w = (64 - menuItem->initialX);
                }
            } else {
                origin = menuItem->y;
                target = menuItem->unk1A;
                if (origin != target) {
                    for (j = 1; j < 16; ++j) {
                        if ((target + vs_battle_rowAnimationSteps[j]) >= origin) {
                            break;
                        }
                    }
                    menuItem->y = vs_battle_rowAnimationSteps[j - 1] + target;
                }
                if (menuItem->y == target) {
                    menuItem->state = 1;
                }
            }
            break;
        case 5:
            origin = menuItem->initialX;
            target = menuItem->targetX;
            if (target < origin) {
                origin -= 32;
                if (origin < target) {
                    origin = target;
                }
                if (-menuItem->w >= origin) {
                    menuItem->state = 0;
                }
            } else {
                if (origin < target) {
                    for (j = 1; j < 16; ++j) {
                        if (origin >= (target - vs_battle_rowAnimationSteps[j])) {
                            break;
                        }
                    }
                    origin = target - vs_battle_rowAnimationSteps[j - 1];
                }
            }
            menuItem->initialX = origin;
            if (origin == target) {
                if (origin < 0) {
                    menuItem->state = 0;
                } else {
                    menuItem->state = 1;
                }
            }
            break;
        }
        if (D_801022D6 == 0) {
            j = menuItem->unk12;
            temp_s3 = D_1F800000[2] + 2;
            if (j != 0) {
                if (menuItem->w == 126) {
                    var_v1 = menuItem->initialX + 116;
                    origin = var_v1 | ((menuItem->y + 1) << 0x10);
                } else {
                    var_v1 = (((menuItem->initialX * 19) >> 4) + 96) & 0xFFFF;
                    origin = var_v1 | ((menuItem->y + 1) << 0x10);
                }
                func_800FFE70(j, origin, temp_s3);
                temp_s0 = origin - 30;
                vs_battle_renderTextRaw("/", temp_s0, temp_s3);
                func_800FFE70(menuItem->unk10, temp_s0, temp_s3);
                if ((menuItem->y == 18) && (menuItem->initialX < 96)) {
                    func_800FFE70(menuItem->unkE, origin + 32, temp_s3);
                    vs_battle_renderTextRaw("-", origin, temp_s3);
                }
            } else {
                j = menuItem->unk10;
                if (j != 0) {
                    vs_battle_renderValue(0,
                        ((menuItem->initialX + menuItem->w) - 16)
                            | ((menuItem->y + 3) << 0x10),
                        j, temp_s3);
                }
            }
            if (menuItem->initialX < 320) {
                if (menuItem->unk5 != 0) {
                    func_8010154C(menuItem);
                } else {
                    func_800C9078(menuItem);
                }
                j = menuItem->itemState;
                if (j != 0) {
                    func_800FFFBC(
                        j - 1, (menuItem->initialX - 24) | ((menuItem->y - 3) << 0x10));
                }
            }
            j = menuItem->unk8;
            if (j != 0) {
                vs_mainmenu_drawButton(
                    j - 1, menuItem->initialX + 5, menuItem->y - 2, NULL);
            }
            j = menuItem->icon;
            if (j != 0) {
                vs_mainMenu_drawRowIcon(
                    (menuItem->unk5 << 0x10) | (menuItem->selected << 8) | j,
                    menuItem->initialX, menuItem->y - 2);
            }
            j = menuItem->material;
            if (j != 0) {
                func_800FFF38(
                    j - 1, (menuItem->initialX + 13) | ((menuItem->y - 3) << 0x10));
            }
        }
    }
}

void func_80101F38(void)
{
    int var_s0;

    var_s0 = D_801022D8;
    if (D_801023D4 != NULL) {
        func_80100A5C();
    }
    if (D_801022DC != 0) {
        var_s0 = var_s0 + 2;
        if (var_s0 >= 17) {
            var_s0 = 16;
        }
    } else {
        var_s0 = var_s0 - 2;
        if (var_s0 < 0) {
            var_s0 = 0;
        }
    }
    D_801022D8 = var_s0;
    if (var_s0 != 0) {
        func_80101118(var_s0);
    }
    if (vs_battle_shortcutInvoked == 0) {
        func_800FFA94();
    }
    if (vs_battle_menuItems != 0) {
        func_80101970();
    }
    func_80100164();
    vs_mainMenu_drawClassAffinityType(0);
    vs_mainMenu_renderEquipStats(0);
    vs_mainMenu_drawDpPpbars(0);
}
