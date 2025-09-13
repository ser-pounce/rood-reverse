// #include "../../build/assets/MENU/MENU8.PRG/rename.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

extern char D_80105F10[24];
extern char D_80105F28;
extern char D_80105F29;
extern char D_80105F2A;
extern char D_80105F2B;
extern u_char D_80105F2C;
extern char D_80105F2D;
extern char D_80105F2E;
extern char D_80105F30;
extern u_char D_80105F31;
extern char* D_80105F34;
extern char D_80105F40[];
extern char D_80105F53;

extern char* D_8010229C;
extern char* D_800F5190;

void func_8006B338(void*);
void func_800C685C(D_800F4E8C_t*, char*);

static char D_80105DB0 = 0;

static int func_80103D88(int arg0)
{
    int temp_s1;
    int i;

    D_80105DB0 = 1;
    temp_s1 = arg0;

    if (vs_main_buttonRepeat & 0x10) {
        vs_battle_playMenuChangeSfx(vs_main_buttonRepeat);
        for (i = 19; arg0 < i; --i) {
            D_80105F40[i] = D_80105F40[i - 1];
        }
        D_80105F40[arg0] = 0x8F;
    } else if (vs_main_buttonRepeat & 0x80) {
        vs_battle_playMenuChangeSfx(vs_main_buttonRepeat);
        for (i = arg0; i < 19; ++i) {
            D_80105F40[i] = D_80105F40[i + 1];
        }
        D_80105F53 = 0x8F;
    } else if ((vs_main_buttonsState & 0xC) != 0xC) {
        if (vs_main_buttonRepeat & 4) {
            if (arg0 == 0) {
                if (vs_main_buttonsPressed.all & 4) {
                    arg0 = 19;
                }
            } else {
                --arg0;
            }
        }
        if (vs_main_buttonRepeat & 8) {
            if (arg0 == 0x13) {
                if (vs_main_buttonsPressed.all & 8) {
                    arg0 = 0;
                }
            } else {
                ++arg0;
            }
        }
    }
    if (arg0 != temp_s1) {
        vs_battle_playMenuChangeSfx();
    }
    return arg0;
}

static int func_80103F1C(char* arg0)
{
    int var_a1;
    int i;

    for (var_a1 = 0, i = 0; i < 20; ++var_a1, ++i) {
        if (D_80105F40[i] == 0xE7) {
            break;
        }
        arg0[var_a1] = D_80105F40[i];
    }

    arg0[var_a1--] = 0xE7;

    while (arg0[var_a1] == 0x8F) {
        arg0[var_a1--] = 0xE7;
        if (var_a1 < 0) {
            return 1;
        }
    }

    var_a1 += 2;

    while (var_a1 < 0x18) {
        arg0[var_a1++] = 0;
    }

    return 0;
}

static char D_80105DB1 = 0;
static u_char D_80105DB2 = 0;
static u_short D_80105DB4[] = {
#include "../../assets/MENU/MENU8.PRG/rename.vsString"
};

u_long* func_800C0214(int, int);
void func_800C70F8(int, int, int, u_long*);
void func_800C7210(char arg0);
int func_800C8FAC(int, int, int);

extern u_long* D_1F800000[];

static void func_80103FD8(int arg0)
{
    static int D_80105EA8[] = { 0x004800D8, 0x00B4008E, 0x00480070, 0x00E00070, 0x004800D8,
        0x00E000D8, 0x00B4008E, 0x00E00070, 0x004800D8, 0x00B40122, 0x00E000D8, 0x00E00140,
        0x004800D8, 0x00480140, 0x00B40122, 0x00E00140 };

    static char D_80105EE8[] = { 0xE7, 0xE7, 0xE7, 0xE7 };
    static char D_80105EEC[8] = { 0 };
    static char D_80105EF4 = 0;

    extern short D_80105E20[];

    u_int* sp18;
    int temp_s4;
    int temp_t1;
    int j;
    int i;
    char* temp_s1;
    u_long* var_s1;
    int temp_s0_2;
    int temp_s3;

    sp18 = (u_int*)D_1F800000[1] - 1;
    func_800FFC68(3, (-arg0 + 0x10), 0x32, 0);
    func_800FFC68(1, (-arg0 + 0x10), 0x42, 0);
    func_800FFC68(0, (-arg0 + 0x10), 0x52, 0);
    var_s1 = func_800C0214(0x100010, ((-arg0 + 0x10) & 0xFFFF) | 0x220000);
    var_s1[4] = 0x37FB70B0;
    var_s1 += 6;
    D_80105EEC[D_80105DB2] = 8;
    D_80105DB2 = 0;

    for (i = 1; i < 5; ++i) {
        temp_s0_2 = D_80105EEC[i];
        if (D_80105EEC[i] != 0) {
            --D_80105EEC[i];
        }
        temp_s4 = func_800C8FAC(8 - temp_s0_2, 0, 0x80) | 0x50000000;
        temp_t1 = func_800C8FAC(temp_s0_2, 0, 0x80);

        for (j = 0; j < 12; ++j) {
            int v1;
            var_s1[0] = (*sp18 & 0xFFFFFF) | 0x06000000;
            var_s1[1] = 0xE1000200;
            var_s1[2] = temp_s4;
            var_s1[3] = ((-arg0) & 0xFFFF) | (j + 20 + i * 16) << 0x10;
            var_s1[4] = temp_t1;
            v1 = j - 0x60;
            var_s1[5] = ((-arg0 - v1) & 0xFFFF) | (j + 20 + i * 16) << 0x10;
            var_s1[6] = 0xE1000000;
            *sp18 = ((u_long)var_s1 << 8) >> 8;
            var_s1 += 7;
        }
    }

    D_1F800000[0] = var_s1;
    func_800C7210(4);
    for (i = 0; i < 4; ++i) {
        temp_s1 = (char*)&D_80105DB4[D_80105DB4[0xC - i]];
        temp_s4 = 0x28;
        while ((j = *temp_s1++) != 0xE7) {
            func_800C70F8(j, temp_s4 - arg0, 0x54 - (i * 0x10), D_1F800000[1] - 5);
            temp_s4 += 6;
        }
    }

    vs_battle_setMenuItem(0x1D, arg0 + 0x9C, 0x30, 0xA4, 0, D_80105EE8)->selected = 1;
    for (j = 0; j < 20; ++j) {
        temp_s0_2 = D_80105F40[j];
        if (temp_s0_2 != 0x8F) {
            int new_var3 = (j * 6 + 0xA2);
            func_800C70F8(temp_s0_2, arg0 + new_var3, 0x30, D_1F800000[2] - 2);
        }
    }
    if (arg0 == 0) {
        u_long* a1;
        temp_s3 = 0x404040;
        temp_s4 = 0x37F9;
        if ((D_80105DB0 != 0) || (D_80105DB1 != 0xB)) {
            temp_s3 = 0x808080;
            ++D_80105DB1;
            --temp_s4;
            if (D_80105DB1 >= 0xC) {
                D_80105DB1 = 0;
            }
        }
        D_80105DB0 = 0;
        j = (D_80105DB1 >> 2);
        func_800C6540("1", 0x330098, temp_s3, 0);
        func_800C6540("L", 0x330092, temp_s3, 0);
        func_800C0214(0x100010, (136 - j) | 0x300000)[4] = (temp_s4 << 0x10) | 0x3000;
        func_800C6540("1", 0x330124, temp_s3, 0);
        func_800C6540("R", 0x33011E, temp_s3, 0);
        func_800C0214(0x100010, (j + 0x128) | 0x300000)[4] = (temp_s4 << 0x10) | 0x3010;
        a1 = D_1F800000[2];
        var_s1 = D_1F800000[0];
        var_s1[0] = ((u_long)a1[0] & 0xFFFFFF) | 0x09000000;
        var_s1[1] = 0xE1000200;
        var_s1[2] = 0x38000000;
        var_s1[3] = 0x1E00D0;
        var_s1[4] = 0;
        var_s1[5] = 0x2000E8;
        var_s1[6] = 0xC0A080;
        var_s1[7] = 0x2E00E8;
        var_s1[8] = 0;
        var_s1[9] = 0x1E0100;
        D_1F800000[2][0] = ((u_long)var_s1 << 8) >> 8;
        D_1F800000[0] = var_s1 + 10;

        if (++D_80105EF4 >= 0xC) {
            D_80105EF4 = 0;
        }
    }

    temp_s1 = (char*)D_80105E20;
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 14; ++j) {
            int temp_s8 = (arg0 + 0x82);
            func_800C70F8(temp_s1[i * 0xF + j], temp_s8 + j * 0xC, (i * 0x10) + 0x4E,
                D_1F800000[2] - 2);
        }
    }

    for (j = 0; j < 16; j += 4) {
        var_s1 = D_1F800000[0];
        var_s1[0] = (*sp18 & 0xFFFFFF) | 0x09000000;
        var_s1[1] = 0xE1000200;
        var_s1[2] = 0x386B4100;
        var_s1[3] = arg0 + D_80105EA8[j];
        var_s1[4] = 0x330500;
        var_s1[5] = arg0 + D_80105EA8[j + 1];
        var_s1[6] = 0x330500;
        var_s1[7] = arg0 + D_80105EA8[j + 2];
        var_s1[8] = 0x330500;
        var_s1[9] = arg0 + D_80105EA8[j + 3];
        *sp18 = ((u_long)var_s1 << 8) >> 8;
        D_1F800000[0] = (u_long*)(var_s1 + 10);
    }
}

static void func_80104650(int arg0, int arg1, int arg2, int arg3)
{
    u_long* temp_t0;
    u_long* temp_t4;

    temp_t4 = D_1F800000[2];
    temp_t0 = D_1F800000[0];
    temp_t0[0] = (*temp_t4 & 0xFFFFFF) | 0x09000000;
    temp_t0[1] = 0xE1000220;
    temp_t0[2] = 0x3AC0A080;
    temp_t0[3] = (arg0 | (arg1 << 0x10));
    temp_t0[4] = 0;
    temp_t0[5] = ((arg0 + arg2) | (arg1 << 0x10));
    temp_t0[6] = 0;
    temp_t0[7] = (arg0 | ((arg1 + arg3) << 0x10));
    temp_t0[8] = 0xC0A080;
    temp_t0[9] = ((arg0 + arg2) | ((arg1 + arg3) << 0x10));
    *temp_t4 = ((u_long)temp_t0 << 8) >> 8;
    D_1F800000[0] = temp_t0 + 10;
}

static int func_801046F0(int arg0, int arg1, int arg2)
{
    int temp_s1;
    int temp_s2;

    temp_s1 = arg1 * 12;
    temp_s2 = arg2 * 16;
    func_80104650(temp_s1 + 0x80, temp_s2 + 0x4C, 0xA, 0x12);
    return func_800FFCDC(arg0, (temp_s1 + 0x70) | ((temp_s2 + 0x42) << 0x10));
}

static int func_8010475C(int arg0)
{
    static char D_80105EF5 = 0;
    static int _[] = { 0x01002AFA, 0x00E79CF1 }; // Junk string?
    
    extern char D_80105F00;
    extern char D_80105F01;
    int i;

    if (arg0 != 0) {
        D_80105F01 = 0;
        D_80105F00 = 0;
    }

    switch (D_80105F00) {
    case 0:
    case 1:
    case 2: {
        vs_battle_menuItem_t* menuItem
            = vs_battle_setMenuItem(D_80105F00 + 0x14, 0x140, (D_80105F00 * 0x10) + 0x80,
                0x7E, 0, (char*)&D_80105DB4[D_80105DB4[D_80105F00 + 6]]);
        menuItem->state = 2;
        menuItem->x = 0xC2;
        ++D_80105F00;
        break;
    }
    case 3:
        D_80105F00 += vs_mainmenu_ready();
        break;
    case 4:
        for (i = 0; i < 3; ++i) {
            vs_battle_getMenuItem(i + 0x14)->selected = (D_80105F01 ^ i) == 0;
        }

        if (vs_main_buttonsPressed.all & 0x60) {
            for (i = 0; i < 3; ++i) {
                func_800FA8A0(i + 0x14);
            }
            if (vs_main_buttonsPressed.all & 0x40) {
                D_80105F01 = 1;
            }
            return D_80105F01 + 1;
        }
        i = D_80105F01;
        if (vs_main_buttonRepeat & 0x1000) {
            i += 2;
        }
        if (vs_main_buttonRepeat & 0x4000) {
            ++i;
        }
        if (i >= 3) {
            i -= 3;
        }
        if (i != D_80105F01) {
            vs_battle_playMenuChangeSfx();
            D_80105F01 = i;
        }
        D_80105EF5 = vs_battle_drawCursor(D_80105EF5, i + 7);
        break;
    }
    return 0;
}

static void func_8010493C(int arg0)
{
    int i;

    if (arg0 < 4) {
        D_80105DB2 = arg0 + 1;
    }

    for (i = 4; i < 9; ++i) {
        vs_battle_getMenuItem(i + 29)->selected = i == arg0;
    }
}

static int func_801049A0(int arg0)
{
    int temp_a1;
    int temp_v0_10;
    int var_a1;
    int var_s1;
    char* temp_s0;
    char* temp_s2;

    if (arg0 != 0) {
        D_80105F2A = 0;
        D_80105F2B = 0;
        D_80105F2C = 0;
        D_80105F2D = 0;
        D_80105F29 = 8;
        D_80105F28 = 0;
        return 0;
    }

    switch (D_80105F28) {
    case 0:
        if (D_80105F29 != 0) {
            --D_80105F29;
        } else {
            D_80105F28 = 2;
        }
        break;
    case 1:
        D_80105F2C = func_80103D88(D_80105F2C);
        if (vs_main_buttonsPressed.all & 0x800) {
            vs_battle_playMenuSelectSfx();
            func_8010493C(0xFF);
            D_80105F28 = 3;
            break;
        }

        if (vs_main_buttonRepeat & 0x40) {
            vs_battle_playMenuChangeSfx();
            if (D_80105F2C != 0) {
                --D_80105F2C;
                for (var_s1 = D_80105F2C; var_s1 < 0x13; ++var_s1) {
                    D_80105F40[var_s1] = D_80105F40[var_s1 + 1];
                }
                D_80105F53 = 0x8F;
            }
        }
        var_s1 = D_80105F2B;
        if (vs_main_buttonsPressed.all & 0x2000) {
            vs_battle_playMenuChangeSfx();
            func_8010493C(0xFF);
            if (var_s1 == 3) {
                var_s1 = 1;
            } else {
                var_s1 = 0;
            }
            D_80105F2B = var_s1;
            D_80105F28 = 2;
            break;
        }
        if (vs_main_buttonsPressed.all & 0x20) {
            switch (var_s1) {
            case 0:
                vs_battle_playMenuSelectSfx();
                func_8010493C(0xFF);
                D_80105F28 = 3;
                break;
            case 1:
                if (D_80105F2C != 0) {
                    --D_80105F2C;
                    for (var_a1 = D_80105F2C; var_a1 < 0x13; ++var_a1) {
                        D_80105F40[var_a1] = D_80105F40[var_a1 + 1];
                    }
                    D_80105F53 = 0x8F;
                }
                break;
            case 2:
                for (var_a1 = D_80105F2C; var_a1 < 0x13; ++var_a1) {
                    D_80105F40[var_a1] = D_80105F40[var_a1 + 1];
                }
                D_80105F53 = 0x8F;
                break;
            case 3:
                for (var_a1 = 0x13; D_80105F2C < var_a1; --var_a1) {
                    D_80105F40[var_a1] = D_80105F40[var_a1 - 1];
                }
                D_80105F40[D_80105F2C] = 0x8F;
                break;
            }
            if (D_80105F28 != 1) {
                break;
            }
            vs_battle_playMenuChangeSfx();
        }
        if (vs_main_buttonRepeat & 0x1000) {
            if (var_s1 == 0) {
                if (vs_main_buttonsPressed.all & 0x1000) {
                    var_s1 = 3;
                }
            } else {
                var_s1 -= 1;
            }
        }
        if (vs_main_buttonRepeat & 0x4000) {
            if (var_s1 == 3) {
                if (vs_main_buttonsPressed.all & 0x4000) {
                    var_s1 = 0;
                }
            } else {
                ++var_s1;
            }
        }
        if (var_s1 != D_80105F2B) {
            vs_battle_playMenuChangeSfx();
            D_80105F2B = var_s1;
        }
        func_8010493C(var_s1);
        D_80105F29 = func_800FFCDC((int)D_80105F29, ((var_s1 * 0x10) + 0x1C) << 0x10);
        break;
    case 2:
        D_80105F2C = func_80103D88(D_80105F2C);
        if (vs_main_buttonsPressed.all & 0x800) {
            vs_battle_playMenuSelectSfx();
            D_80105F28 = 3;
            break;
        }
        if (vs_main_buttonsPressed.all & 0x20) {
            vs_battle_playMenuChangeSfx();
            var_s1 = D_80105F34[D_80105F2A + (D_80105F2B * 0xF)];
            D_80105F40[D_80105F2C] = var_s1;
            if (D_80105F2C < 0x13) {
                ++D_80105F2C;
            }
        }
        if (vs_main_buttonRepeat & 0x40) {
            vs_battle_playMenuChangeSfx();
            if (D_80105F2C != 0) {
                --D_80105F2C;
                for (var_s1 = D_80105F2C; var_s1 < 0x13; ++var_s1) {
                    D_80105F40[var_s1] = D_80105F40[var_s1 + 1];
                }
                D_80105F53 = 0x8F;
            }
        }

        var_a1 = D_80105F2A + (D_80105F2B * 0xE);

        if (vs_main_buttonRepeat & 0x1000) {
            if (D_80105F2B != 0) {
                --D_80105F2B;
            } else if (vs_main_buttonsPressed.all & 0x1000) {
                D_80105F2B = 8;
            }
        }
        if (vs_main_buttonRepeat & 0x4000) {
            if (D_80105F2B == 8) {
                if (vs_main_buttonsPressed.all & 0x4000) {
                    D_80105F2B = D_80105F28 != 2;
                }
            } else {
                ++D_80105F2B;
            }
        }
        if (vs_main_buttonRepeat & 0x8000) {
            if (D_80105F2A == 0) {
                if (vs_main_buttonsPressed.all & 0x8000) {
                    vs_battle_playMenuChangeSfx();
                    if (D_80105F2B == 0) {
                        D_80105F2B = 2;
                    } else {
                        D_80105F2B = 3;
                    }
                    D_80105F28 = 1;
                    break;
                }
            } else {
                --D_80105F2A;
            }
        }
        if (vs_main_buttonRepeat & 0x2000) {
            if (D_80105F2A == 0xD) {
                if (vs_main_buttonsPressed.all & 0x2000) {
                    D_80105F2A = 0;
                }
            } else {
                ++D_80105F2A;
            }
        }
        if (var_a1 != (D_80105F2A + (D_80105F2B * 0xE))) {
            vs_battle_playMenuChangeSfx();
        }
        break;
    case 3:
        func_8010493C(0);
        D_80105F30 = 0;
        D_80105F28 = 4;
        break;
    case 4:
        if (D_80105F31 == 0xA) {
            extern short D_80105DDA[];
            if (func_80103F1C(D_80105F10) != 0) {
                char* base = (char*)D_80060168;
                char idx_byte = base[D_80105F2E * 32 + 1];
                int idx = idx_byte - 1;
                char table_val = base[idx * 44 + 0x280];
                vs_battle_rMemcpy(D_80105F10, D_8010229C + (table_val * 0x18), 0x18);
            }
            func_800C8E04(1);
            D_800F5190 = D_80105F10;
            func_800C685C(D_800F4E8C, (char*)D_80105DDA);
            vs_mainmenu_setMessage(&D_800F4E8C->unk0);
            func_8010475C(1);
            D_80105F28 = 5;
        }
        break;
    case 5:
        temp_v0_10 = func_8010475C(0);
        if (temp_v0_10 != 0) {
            func_800CD064(7);
            if (temp_v0_10 == 2) {
                vs_battle_playMenuLeaveSfx();
                D_80105F30 = 1;
                D_80105F28 = 6;
                break;
            }
            temp_s2 = (char*)D_80060168;
            temp_s0 = temp_s2 + (D_80105F2E * 32);
            if (temp_v0_10 == 1) {
                vs_main_playSfxDefault(0x7E, 0xD);
                vs_battle_rMemcpy(temp_s0 + 8, &D_80105F10, 0x18);
                if (temp_s0[3] != 0) {
                    func_8006B338(temp_s0);
                }
                return 1;
            }
            vs_battle_playMenuLeaveSfx();
            if (temp_s0[8] == 0xE7) {
                char idx_byte = temp_s0[1];
                int idx = idx_byte - 1;
                char table_val = temp_s2[idx * 44 + 0x280];
                vs_battle_rMemcpy(temp_s0 + 8, D_8010229C + (table_val * 0x18), 0x18);
            }
            return 1;
        }
        break;
    case 6:
        if (D_80105F31 == 0) {
            D_80105F2A = 0;
            D_80105F2B = 0;
            D_80105F28 = 2;
            break;
        }
        break;
    }
    if (D_80105F28 == 2) {
        D_80105F29 = func_801046F0(D_80105F29, D_80105F2A, D_80105F2B);
    }
    if ((u_int)(D_80105F28 - 1) < 2U) {
        func_80104650((D_80105F2C * 6) + 0xA1, 0x30, 8, 0xC);
    }
    return 0;
}

void func_80103FD8(int);
int func_801049A0(int);
extern char D_80060170[];

int func_80105314(char* arg0)
{
    extern short D_80105E20[];
    int i;
    int temp_a0;
    int temp_s0;
    char* var_v1;
    char* var_v0;
    int v1;

    temp_s0 = *arg0;
    switch (temp_s0) {
    case 0:
        D_80105F2E = D_800F4E8C->unk1;
        D_80105F34 = (char*)D_80105E20;
        func_800FFBA8();
        v1 = 0x8F;
        i = 19;
        var_v0 = &D_80105F40[i];
        for (; i >= 0; --i) {
            *var_v0-- = v1;
        }
        if (D_800F4E8C->unk0 == 1) {
            var_v1 = (D_80105F2E << 5) + D_80060170;
            for (i = 0; i < 20; ++i) {
                temp_a0 = *var_v1++;
                if (temp_a0 == 0xE7) {
                    break;
                } else if (temp_a0 == 0x8F) {
                    continue;
                } else if (temp_a0 == 0xFA) {
                    var_v1 += 1;
                } else {
                    D_80105F40[i] = temp_a0;
                }
            }
        }
        D_80105F30 = 0;
        D_80105F31 = 10;
        *arg0 = 1;
        break;
    case 1:
        func_801049A0(1);
        D_80105F30 = temp_s0;
        *arg0 = 2;
        break;
    case 2:
        if (func_801049A0(0) != 0) {
            func_800FA8A0(0xA);
            func_800FA810(0);
            func_800FFBC8();
            *arg0 = 3;
        }
        break;
    case 3:
        if (D_80105F31 == 0xA) {
            *arg0 = 0;
            vs_battle_menuState.currentState = 0xD;
        }
        break;
    }
    if (D_80105F30 != 0) {
        if (D_80105F31 != 0) {
            --D_80105F31;
        }
        func_80103FD8(vs_battle_rowAnimationSteps[D_80105F31]);
    } else if (D_80105F31 < 10) {
        ++D_80105F31;
        func_80103FD8(D_80105F31 << 5);
    }
    return 0;
}
