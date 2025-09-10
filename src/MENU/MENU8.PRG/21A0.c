#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

extern char D_80105E20[];
extern char D_80105F2E;
extern char D_80105F30;
extern u_char D_80105F31;
extern char* D_80105F34;
extern char D_80105F40[];
extern char D_80105F53;

int func_80103D88(int arg0);
void func_8010493C(int arg0);
int func_80103F1C(char* arg0);
int func_8010475C(int arg0);
int func_801046F0(int arg0, int arg1, int arg2);
void func_80104650(int, int, int, int);

void func_8006B338(void*);
void func_800C685C(D_800F4E8C_t*, char*);
extern char* D_800F5190;
extern char* D_8010229C;
extern short D_80105DDA[];
extern char D_80105F10[];
extern char D_80105F28;
extern char D_80105F29;
extern char D_80105F2A;
extern char D_80105F2B;
extern u_char D_80105F2C;
extern char D_80105F2D;

int func_801049A0(int arg0)
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
            if (func_80103F1C(D_80105F10) != 0) {
                char* base = (char*) D_80060168;
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
        D_80105F34 = D_80105E20;
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
