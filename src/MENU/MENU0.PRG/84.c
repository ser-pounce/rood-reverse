#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../SLUS_010.40/main.h"

extern char D_8004B9F8[];
extern signed char D_80106918[];
extern signed char D_80106928[];

static void func_80102884(int arg0)
{
    int temp_v0;
    int var_s1;
    int var_s2;
    int var_a0;

    var_s2 = 0;

    if (arg0 < 0) {
        var_s2 = 1;
        arg0 = -arg0;
    }

    temp_v0 = vs_battle_getSkillFlags(0, arg0);
    vs_mainmenu_setAbilityCost(1, "MP", 8, (temp_v0 >> 1) & 1);
    var_s1 = 0xF;
    var_a0 = vs_main_skills[arg0].cost;
    D_80106918[15] = 0;

    if (var_s2 != 0) {
        var_s1 = 0xD;
        D_80106918[14] = 0x2D;
        D_80106918[13] = 0x5B;
    }

    do {
        var_a0 = vs_battle_toBCD(var_a0);
        D_80106918[--var_s1] = (var_a0 & 0xF) + 0x30;
        var_a0 >>= 4;
        if (var_s2 != 0) {
            D_80106918[--var_s1] = 0x5B;
        }
    } while (var_a0 != 0);

    D_80106918[--var_s1] = 0x23;
    vs_mainmenu_setAbilityCost(
        0, &D_80106918[var_s1], (var_s2 * 4) | 0x48, (temp_v0 >> 1) & 1);
}

static void func_801029B8(int arg0, int arg1)
{
    int temp_v0;
    int var_s0;

    vs_mainmenu_setAbilityCost(1, "MP", 8, arg1);
    temp_v0 = arg0;
    var_s0 = 0xF;
    D_80106928[15] = 0;

    do {
        temp_v0 = vs_battle_toBCD(temp_v0);
        D_80106928[--var_s0] = (temp_v0 & 0xF) + 0x30;
        temp_v0 >>= 4;
    } while (temp_v0 != 0);

    D_80106928[--var_s0] = 0x23;
    vs_mainmenu_setAbilityCost(0, &D_80106928[var_s0], 0x48, arg1);
}

static u_short D_80104A58[] = {
#include "../../build/assets/MENU/MENU0.PRG/base.vsString"
};
static u_short D_80105D94[] = {
#include "../../build/assets/MENU/MENU0.PRG/teleportation.vsString"
};

static int D_801067DC[] = { 0x0305001B, 0x0801000E, 0x04030199, 0x0C0C001C, 0x070C0028,
    0x040200CD, 0x0F070035, 0x08060093, 0x060000CE, 0x09080106, 0x09080111, 0x0C030098,
    0x090800E0, 0x060900C8, 0x050800CA, 0x050F00CC, 0x0109009B, 0x0A07007C, 0x000400CF,
    0x080800EC, 0x020400F1, 0x0705011D, 0x06080120, 0x04080139, 0x04080147, 0x0904014F,
    0x010300A2, 0x150C00A3, 0x030200D0, 0x060600D1, 0x1007008B, 0x010400AB, 0x05020055,
    0x07060063, 0x0A0400D2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000 };

static int func_80102A68(int arg0)
{
    static char D_8010689C[] = { 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00 };
    int temp_a1;
    int temp_v1;
    int i;
    int var_a1;
    int j;

    temp_a1 = func_8007C874();

    do {
        for (i = 0; i < 48; ++i) {
            if ((u_short)D_801067DC[i] == temp_a1) {
                break;
            }
        }
    } while (0);

    temp_v1 = i;
    if (arg0 < i) {
        i = arg0;
        arg0 = temp_v1;
    }

    var_a1 = 15;

    for (j = i; j < arg0; ++j) {
        var_a1 += D_8010689C[j];
    }
    return var_a1;
}

extern char D_800EBD70[];
extern char D_800EC270[];
extern u_int D_801068E8;
extern int D_801068EC;
extern int D_801068F0;
extern char D_80106938[];
extern u_char D_8010694A;
extern u_long* D_1F800000[];

static int func_80102B08(u_int arg0)
{
    static char D_801068CC[] = {
        0x6A, 0x6E, 0x72, 0x76, 0x7A, 0x7E, 0x82
    };

    static char* D_801068D4[] = {
        "LV1", "LV2", "LV3", "LV4", "--"
    };

    char* menuStrings[36];
    int rowTypes[18];
    int rowCount;
    int i;

    if (arg0 != 0) {
        D_801068F0 = (arg0 ^ 2) < 1;
        func_800FA92C(0, 1);
        D_801068E8 = 0;
        return 0;
    }

    switch (D_801068E8) {
    case 0: {
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 18; ++i) {
            int skillId = D_800EBD70[i];
            if ((vs_main_skills[skillId].flags >> 0xF) & 1) {
                menuStrings[rowCount * 2] = (char*)&D_80104A58[D_80104A58[i + 0x3E]];
                menuStrings[rowCount * 2 + 1] = (char*)&D_80104A58[D_80104A58[i + 0xC]];
                rowTypes[rowCount] = 0;
                if (vs_battle_getSkillFlags(0, skillId) != 0) {
                    rowTypes[rowCount] |= 1;
                }
                D_80106938[rowCount] = skillId;
                ++rowCount;
            }
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 18; ++i) {
                rowTypes[i] |= 1;
            }
        }
        i = vs_main_settings.cursorMemory;
        if (D_801068F0 != 0) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(rowCount, 0x207, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        D_801068E8 = 1;
        break;
    }
    case 1:
        D_801068EC = vs_mainmenu_getSelectedRow() + 1;
        if (D_801068EC != 0) {
            D_801022D4 = 0;
            if ((vs_battle_shortcutInvoked != 0) && (D_801068EC == -1)) {
                D_801068EC = -2;
            }
            if (D_801068EC == -1) {
                func_800FA8E0(0);
                D_801068E8 = 2;
                break;
            }
            if (D_801068EC > 0) {
                D_801068EC = D_80106938[D_801068EC - 1];
                for (rowCount = 0; rowCount < 7; ++rowCount) {
                    if ((D_801068EC == D_801068CC[rowCount])
                        && ((vs_main_skills[D_801068EC + 1].flags >> 0xF) & 1)) {
                        func_800FA92C(D_800F4EE8.unk0[0xE], 2);
                        D_801022D4 = 1;
                        D_801068E8 = 3;
                    }
                }
                if (D_801068E8 == 3) {
                    break;
                }
            }
            func_800FA8E0(0x28);
            func_800FFBA8();
            func_800FFA88(0);
            D_801068E8 = 2;
        } else {
            i = D_80106938[func_801008B0()];
            for (rowCount = 0; rowCount < 7; ++rowCount) {
                if (i == D_801068CC[rowCount]) {
                    if ((vs_main_skills[i + 1].flags >> 0xF) & 1) {
                        i = -i;
                    }
                    break;
                }
            }
            func_80102884(i);
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_801068EC;
        }
        break;
    case 3: {
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        i = 2;
        if ((vs_main_skills[D_801068EC + 2].flags >> 0xF) & 1) {
            i = 3;
            if ((vs_main_skills[D_801068EC + 3].flags >> 0xF) & 1) {
                i = 4;
            }
        }
        D_800F4EE8.unk0[0xD] = i;
        if (D_800F4EE8.unk0[0xC] >= i) {
            D_800F4EE8.unk0[0xC] = i - 1;
        }
        D_8010694A = 0;
        D_801068E8 = 4;
        break;
    }
    case 4: {
        u_int* temp_s6;
        int var_s0_2;
        int var_s7_2;
        int* var_t3;

        i = D_800F4EE8.unk0[0xC];
        rowCount = D_800F4EE8.unk0[0xD];

        if (vs_main_buttonsPressed.all & 0x10) {
            vs_battle_playMenuLeaveSfx();
            D_801022D4 = 0;
            func_800FA8E0(0x28);
            func_800FFBA8();
            func_800FFA88(0);
            D_801068EC = -2;
            D_801068E8 = 2;
            break;
        }
        if (vs_main_buttonsPressed.all & 0x40) {
            vs_battle_playMenuLeaveSfx();
            for (i = 0x14; i < 0x1E; ++i) {
                func_800FA8A0(i);
            }
            D_801068E8 = 0;
            break;
        } else if (vs_main_buttonsPressed.all & 0x20) {
            if (vs_battle_getSkillFlags(0, D_801068EC + i) == 0) {
                vs_battle_playMenuSelectSfx();
                D_801022D4 = 0;
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
                D_801068E8 = 2;
                D_801068EC += i;
                break;
            } else {
                func_800C02E0();
            }
        }
        if (vs_main_buttonRepeat & 0x2000) {
            if (i < (rowCount - 1)) {
                ++i;
            }
        }
        if (vs_main_buttonRepeat & 0x8000) {
            if (i > 0) {
                --i;
            }
        }
        if (i != D_800F4EE8.unk0[0xC]) {
            vs_battle_playMenuChangeSfx();
            D_800F4EE8.unk0[0xC] = i;
        }

        func_80102884(D_801068EC + i);
        temp_s6 = (u_int*)D_1F800000[1] - 1;
        for (var_s0_2 = 0; var_s0_2 < 4; ++var_s0_2) {
            var_s7_2 = 0;
            if (i >= var_s0_2) {
                int v;
                vs_battle_renderTextRaw(
                    D_801068D4[var_s0_2], (0x63 + var_s0_2 * 0x20) | 0x670000, 0);
                var_t3 = func_800C0224(D_800EC270[D_8010694A],
                    (0x60 + var_s0_2 * 0x20) | 0x640000, 0x100020, temp_s6);
                var_t3[4] = 0x37FD70C0;

                v = D_8010694A;
                if (var_s0_2 == i) {
                    ++D_8010694A;
                    D_8010694A &= 0xF;
                } else {
                    D_8010694A = v & 0xF;
                }
            } else {
                if (var_s0_2 < rowCount) {
                    vs_battle_renderTextRaw(
                        D_801068D4[var_s0_2], (0x63 + var_s0_2 * 0x20) | 0x670000, 0);
                    var_t3 = func_800C0224(
                        0x40, (0x60 + var_s0_2 * 0x20) | 0x640000, 0x100020, temp_s6);
                    var_t3[4] = 0x37FE70C0;
                } else {
                    var_s7_2 = 1;
                    vs_battle_renderTextRaw(
                        D_801068D4[4], (0x66 + var_s0_2 * 0x20) | 0x670000, 0);
                    var_t3 = func_800C0224(
                        0, (0x60 + var_s0_2 * 0x20) | 0x640000, 0x100020, temp_s6);
                    var_t3[1] = 0x64602000;
                    var_t3[4] = 0x37FE70C0;
                }
            }
            var_t3[-3] = (u_short)var_t3[-3] | 0x37F50000;
            var_t3[-5] = var_t3[-5] | 0x02000000;
            var_t3[-8] = (u_short)var_t3[-8] | 0x37F50000;
            var_t3[-10] = var_t3[-10] | 0x02000000;
            if (var_s7_2 != 0) {
                var_t3[-12] = _get_mode(0, 0, 0x2C);
            } else {
                var_t3[-17] = _get_mode(0, 0, 0x2C);
                var_t3[-13] = (u_short)var_t3[-13] | 0x37F50000;
                var_t3[-15] = var_t3[-15] | 0x02000000;
            }
        }
        var_t3 = func_800C0224(0x80U, 0x640050, 0x100010, temp_s6);
        var_t3[4] = 0x37FD3050;
        var_t3 += 6;
        var_t3[0] = (*temp_s6 & 0xFFFFFF) | 0x09000000;
        var_t3[1] = 0x2C808080;
        var_t3[2] = 0x6400E0;
        var_t3[3] = 0x37FD305F;
        var_t3[4] = 0x6400F0;
        var_t3[5] = 0xC304F;
        var_t3[6] = 0x7400E0;
        var_t3[7] = 0x405F;
        var_t3[8] = 0x7400F0;
        var_t3[9] = 0x404F;
        *temp_s6 = ((u_int)var_t3 << 8) >> 8;
        D_1F800000[0] = (u_long*)var_t3 + 10;
        break;
    }
    }
    return 0;
}

extern char D_800EBD84[];
extern int D_801068F4;
extern int D_801068F8;
extern int D_801068FC;
extern char D_80106950[];

static int _drawMagicList(int arg0)
{
    char* menuStrings[12];
    int rowTypes[6];
    int i;
    int rowCount;
    int skillId;

    if (arg0 != 0) {
        D_801068FC = (arg0 ^ 2) < 1U;
        func_800FA92C(1, 1);
        D_801068F4 = 0;
        return 0;
    }

    switch (D_801068F4) {
    case 0:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 6; ++i) {
            skillId = D_800EBD84[i];
            if ((vs_main_skills[skillId].flags >> 0xF) & 1) {
                menuStrings[rowCount * 2] = vs_main_skills[skillId].name;
                menuStrings[rowCount * 2 + 1] = (char*)&D_80104A58[D_80104A58[30 + i]];
                rowTypes[rowCount] = 0;
                if (vs_battle_getSkillFlags(0, skillId) != 0) {
                    rowTypes[rowCount] |= 1;
                }
                D_80106950[rowCount] = skillId;
                ++rowCount;
            }
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 6; ++i) {
                rowTypes[i] |= 1;
            }
        }

        i = vs_main_settings.cursorMemory;
        if (D_801068FC != 0) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(rowCount, 0x208, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        D_801068F4 = 1;
        break;
    case 1:
        D_801068F8 = vs_mainmenu_getSelectedRow() + 1;
        if (D_801068F8 != 0) {
            D_801022D4 = 0;
            if ((vs_battle_shortcutInvoked != 0) && (D_801068F8 == -1)) {
                D_801068F8 = -2;
            }
            if (D_801068F8 == -1) {
                func_800FA8E0(0);
            } else {
                if (D_801068F8 > 0) {
                    D_801068F8 = D_80106950[D_801068F8 - 1];
                }
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            }
            D_801068F4 = 2;
        } else {
            char* new_var = D_80106950;
            func_80102884(*(new_var + func_801008B0()));
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_801068F8;
        }
        break;
    }
    return 0;
}

extern char D_800EBD8C[];
extern char D_80106958[];
extern int D_80106900;
extern int D_80106904;
extern int D_80106908;

static int func_801037A8(int arg0)
{
    char* menuStrings[36];
    int rowTypes[18];
    int i;
    int rowCount;
    int skillId;

    if (arg0 != 0) {
        D_80106908 = (arg0 ^ 2) < 1U;
        func_800FA92C(2, 1);
        D_80106900 = 0;
        return 0;
    }

    switch (D_80106900) {
    case 0:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 18; ++i) {
            skillId = D_800EBD8C[i];
            if ((vs_main_skills[skillId].flags >> 0xF) & 1) {
                menuStrings[rowCount * 2] = vs_main_skills[skillId].name;
                menuStrings[rowCount * 2 + 1] = (char*)&D_80104A58[D_80104A58[36 + i]];
                rowTypes[rowCount] = 0;
                if (vs_battle_getSkillFlags(0, skillId) != 0) {
                    rowTypes[rowCount] |= 1;
                }
                D_80106958[rowCount] = skillId;
                ++rowCount;
            }
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 18; ++i) {
                rowTypes[i] |= 1;
            }
        }

        i = vs_main_settings.cursorMemory;
        if (D_80106908 != 0) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(rowCount, 0x209, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        D_80106900 = 1;
        break;
    case 1:
        D_80106904 = vs_mainmenu_getSelectedRow() + 1;
        if (D_80106904 != 0) {
            D_801022D4 = 0;
            if ((vs_battle_shortcutInvoked != 0) && (D_80106904 == -1)) {
                D_80106904 = -2;
            }
            if (D_80106904 == -1) {
                func_800FA8E0(0);
            } else {
                if (D_80106904 > 0) {
                    D_80106904 = D_80106958[D_80106904 - 1];
                }
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            }
            D_80106900 = 2;
        } else {
            char* new_var = D_80106958;
            func_80102884(*(new_var + func_801008B0()));
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80106904;
        }
        break;
    }
    return 0;
}

extern char D_800EBDA0[];
extern int D_8010690C;
extern int D_80106910;
extern int D_80106914;
extern char D_80106970[];

static int func_80103AEC(int arg0)
{
    char* menuStrings[16];
    int rowTypes[8];
    int i;
    int rowCount;
    int skillId;

    if (arg0 != 0) {
        D_80106914 = (arg0 ^ 2) < 1U;
        func_800FA92C(3, 1);
        D_8010690C = 0;
        return 0;
    }

    switch (D_8010690C) {
    case 0:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 8; ++i) {
            skillId = D_800EBDA0[i];
            if ((vs_main_skills[skillId].flags >> 0xF) & 1) {
                menuStrings[rowCount * 2] = vs_main_skills[skillId].name;
                menuStrings[rowCount * 2 + 1] = (char*)&D_80104A58[D_80104A58[54 + i]];
                rowTypes[rowCount] = 0;
                if (vs_battle_getSkillFlags(0, skillId) != 0) {
                    rowTypes[rowCount] |= 1;
                }
                D_80106970[rowCount] = skillId;
                ++rowCount;
            }
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 8; ++i) {
                rowTypes[i] |= 1;
            }
        }

        i = vs_main_settings.cursorMemory;
        if (D_80106914 != 0) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(rowCount, 0x20A, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        D_8010690C = 1;
        break;
    case 1:
        D_80106910 = vs_mainmenu_getSelectedRow() + 1;
        if (D_80106910 != 0) {
            D_801022D4 = 0;
            if ((vs_battle_shortcutInvoked != 0) && (D_80106910 == -1)) {
                D_80106910 = -2;
            }
            if (D_80106910 == -1) {
                func_800FA8E0(0);
            } else {
                if (D_80106910 > 0) {
                    D_80106910 = D_80106970[D_80106910 - 1];
                }
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            }
            D_8010690C = 2;
        } else {
            char* new_var = D_80106970;
            func_80102884(*(new_var + func_801008B0()));
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_80106910;
        }
        break;
    }
    return 0;
}

extern u_char D_80106978[];
extern u_short D_801069A8[];
extern int D_80106A08;
extern int D_80106A0C;
extern char D_80106A10;

static int func_80103E30(int arg0)
{
    char* menuStrings[96];
    int rowTypes[48];
    int sp250;
    int i;
    int rowCount;
    int temp_s2_2;

    if (arg0 != 0) {
        func_800FA92C(4, 1);
        D_80106A10 = 0;
        D_80106A0C = vs_battle_characterState->unk3C->unk0[0xE];
        return 0;
    }
    switch (D_80106A10) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 48; ++i) {
            temp_s2_2 = vs_main_stateFlags.unk156[i];
            if (temp_s2_2 == 0) {
                continue;
            }
            menuStrings[2 * rowCount] = (char*)(&D_80105D94[D_80105D94[(i * 2) + 3]]);
            menuStrings[(rowCount * 2) + 1]
                = (char*)(&D_80105D94[D_80105D94[(i * 2) + 4]]);
            D_801069A8[rowCount] = func_80102A68(i);
            rowTypes[rowCount] = (temp_s2_2 == 2) | (D_80106A0C < D_801069A8[rowCount]);
            if (D_801069A8[rowCount] == 0xF) {
                rowTypes[rowCount] |= 4;
                sp250 = rowCount;
            }
            if (temp_s2_2 == 2) {
                menuStrings[(rowCount * 2) + 1] = (char*)(D_80105D94 + 144);
            }
            D_80106978[rowCount] = i;
            ++rowCount;
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 48; ++i) {
                rowTypes[i] |= 1;
            }
        }
        if ((rowCount < 9) || (sp250 < 8)) {
            D_800F4EE8.unk0[0x16] = sp250;
            D_800F4EE8.unk0[0x17] = 0;
        } else if (sp250 >= (rowCount - 7)) {
            D_800F4EE8.unk0[0x16] = sp250 - (rowCount - 8);
            D_800F4EE8.unk0[0x17] = rowCount - 8;
        } else {
            D_800F4EE8.unk0[0x16] = 3;
            D_800F4EE8.unk0[0x17] = sp250 - 3;
        }
        temp_s2_2 = vs_main_settings.cursorMemory;
        vs_main_settings.cursorMemory = 1;
        vs_mainmenu_setMenuRows(rowCount, 0x20B, menuStrings, rowTypes);
        D_80106A10 = 1;
        vs_main_settings.cursorMemory = temp_s2_2;
        break;

    case 1:
        D_80106A08 = vs_mainmenu_getSelectedRow() + 1;
        if (D_80106A08 != 0) {
            D_801022D4 = 0;
            if (D_80106A08 == (-1)) {
                func_800FA8E0(0);
            } else {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            }
            D_80106A10 = 2;
        } else {
            i = D_801069A8[func_801008B0()];
            func_801029B8(i, D_80106A0C < i);
        }
        break;

    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (D_80106A08 > 0) {
                int v1;
                int v0;
                int a0;
                int a2 = D_80106978[D_80106A08 - 1];
                i = D_801067DC[a2] + 1;
                v1 = i & 0x1FF;
                arg0 = ~0x3E00;
                v0 = (rowCount & ~0x1FF) | v1;
                v1 = (i >> 7) & 0x3E00;
                v0 &= arg0;
                v0 |= v1;
                a0 = (i >> 0x18) & 0x1F;
                a0 <<= 0xE;
                v1 = D_801069A8[D_80106A08 - 1] << 0x13;
                v0 &= 0x3FFF;
                return v0 | a0 | v1;
            }
            return D_80106A08;
        }
        break;
    }
    return 0;
}

static void func_80104254()
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = vs_battle_setMenuItem(
        0, 320, 18, 0x8C, 8, (char*)&vs_battle_menuStrings[vs_battle_menuStrings[0]]);
    temp_v0->state = 2;
    temp_v0->x = 180;
    temp_v0->selected = 1;
    func_800FFA88(2);
    func_800FFBC8();
}

extern char D_8006164D;
extern char D_80104AF8;
extern char D_80104B64;
extern char D_80104BEC;
extern char D_80104C8E;
extern char D_80105E5A[];
extern char D_80105E68[];
extern char D_80105EB4[];

int vs_menu0_exec(char* arg0)
{
    char* menuStrings[10];
    int rowTypes[5];
    int selectedRow;
    int j;
    int i;

    switch (*arg0) {
    case 3:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_800FFBC8();
        i = vs_battle_shortcutInvoked;
        if (i != 0) {
            vs_battle_setMenuItem(
                i + 9, 0x140, 0x22, 0x8C, 8, (char*)&D_80104A58[D_80104A58[(i * 3) - 3]])
                ->selected
                = 1;
            switch (i) {
            case 1:
                *arg0 = 7;
                func_80102B08(1);
                break;
            case 2:
                *arg0 = 9;
                _drawMagicList(1);
                break;
            case 3:
                *arg0 = 0xB;
                func_801037A8(1);
                break;
            case 4:
                *arg0 = 0xD;
                func_80103AEC(1);
                break;
            }
            break;
        }
        // Fallthrough
    case 4:
        for (i = 0; i < 4; ++i) {
            menuStrings[i * 2] = (char*)&D_80104A58[D_80104A58[i * 3]];
            menuStrings[i * 2 + 1] = (char*)&D_80104A58[D_80104A58[i * 3 + 1]];
            rowTypes[i] = 0;
            if (func_800CAEAC(i) == 0) {
                rowTypes[i] |= 1;
                menuStrings[i * 2 + 1] = (char*)&D_80104A58[D_80104A58[i * 3 + 2]];
            }
        }

        if (vs_main_stateFlags.unkB5 != 0) {
            for (j = 0; j < 0x30; ++j) {
                if (vs_main_stateFlags.unk156[j] != 0) {
                    break;
                }
            }

            menuStrings[i * 2] = D_80105E5A; // TELEPORTATION

            menuStrings[i * 2 + 1]
                = (func_8008A4FC() != 0) && (vs_main_stateFlags.unkB5 == 2)
                ? D_80105E5A + 0x5A
                : // The spirit paling prevents teleportation.
                D_80105E5A + 0xE; // Teleport to any Circle of Magic.

            if ((func_8008A4FC() != 0) && (vs_main_stateFlags.unkB5 == 2)) {
                menuStrings[i * 2 + 1]
                    = D_80105E5A + 0x5A; // The spirit paling prevents teleportation.
            }

            rowTypes[i++] = ((j == 0x30) || (vs_main_stateFlags.unkB5 == 2)
                || (func_8008A4FC() == 0));
        }

        j = vs_main_settings.cursorMemory;
        if (*arg0 != 3) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(i, 0x105, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = j;
        *arg0 = 5;
        break;
    case 5:
        selectedRow = vs_mainmenu_getSelectedRow();
        i = selectedRow + 1;
        if (i != 0) {
            if (i > 0) {
                switch (selectedRow) {
                case 0:
                    *arg0 = 7;
                    func_80102B08(1);
                    break;
                case 1:
                    *arg0 = 9;
                    _drawMagicList(1);
                    break;
                case 2:
                    *arg0 = 11;
                    func_801037A8(1);
                    break;
                case 3:
                    *arg0 = 13;
                    func_80103AEC(1);
                    break;
                case 4:
                    *arg0 = 14;
                    func_80103E30(1);
                    break;
                }
            } else {
                if (i == -2) {
                    func_800FA8E0(0x28);
                    *arg0 = 0x11;
                } else {
                    func_800FA8E0(0x28);
                    *arg0 = 0xF;
                }
            }
        }
        break;
    case 6:
        func_80104254();
        vs_battle_setMenuItem(0xA, 0x140, 0x22, 0x7E, 8, &D_80104AF8)->selected = 1;
        func_80102B08(2);
        *arg0 = 7;
        break;
    case 7:
        i = func_80102B08(0);
        if (i != 0) {
            if (i > 0) {
                D_800F4E98.executeAbility = i;
                vs_battle_executeAbilityType = 6;
                *arg0 = 0x10;
            } else {
                if (i == -2) {
                    *arg0 = 0x11;
                } else {
                    *arg0 = 4;
                }
            }
        }
        break;
    case 8:
        func_80104254();
        vs_battle_setMenuItem(0xB, 0x140, 0x22, 0x7E, 8, &D_80104B64)->selected = 1;
        _drawMagicList(2);
        *arg0 = 9;
        break;
    case 9:
        i = _drawMagicList(0);
        if (i != 0) {
            if (i > 0) {
                D_800F4E98.executeAbility = i;
                vs_battle_executeAbilityType = 8;
                *arg0 = 0x10;
            } else {
                if (i == -2) {
                    *arg0 = 0x11;
                } else {
                    *arg0 = 4;
                }
            }
        }
        break;
    case 10:
        func_80104254();
        vs_battle_setMenuItem(0xC, 0x140, 0x22, 0x7E, 8, &D_80104BEC)->selected = 1;
        func_801037A8(2);
        *arg0 = 0xB;
        break;
    case 11:
        i = func_801037A8(0);
        if (i != 0) {
            if (i > 0) {
                D_800F4E98.executeAbility = i;
                vs_battle_executeAbilityType = 10;
                *arg0 = 0x10;
            } else {
                if (i == -2) {
                    *arg0 = 0x11;
                } else {
                    *arg0 = 4;
                }
            }
        }
        break;
    case 12:
        func_80104254();
        vs_battle_setMenuItem(0xD, 0x140, 0x22, 0x7E, 8, &D_80104C8E)->selected = 1;
        func_80103AEC(2);
        *arg0 = 0xD;
        break;
    case 13:
        i = func_80103AEC(0);
        if (i != 0) {
            if (i > 0) {
                D_800F4E98.executeAbility = i;
                vs_battle_executeAbilityType = 12;
                *arg0 = 0x10;
            } else {
                if (i == -2) {
                    *arg0 = 0x11;
                } else {
                    *arg0 = 4;
                }
            }
        }
        break;
    case 14:
        i = func_80103E30(0);
        if (i != 0) {
            if (i > 0) {
                D_800F4E98.unk2 = 0xA;
                D_800F4E98.executeAbility = i - 1;
                *arg0 = 17;
            } else {
                if (i == -2) {
                    *arg0 = 17;
                } else {
                    *arg0 = 4;
                }
            }
        }
        break;
    case 15:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            *arg0 = 0;
            return 1;
        }
        break;
    case 16:
        if (vs_mainmenu_ready() != 0) {
            D_800F4E98.unk2 = 7;
            vs_battle_menuState.returnState = vs_battle_menuState.currentState;
            vs_battle_menuState.currentState = 1;
            *arg0 = 0;
            return 1;
        }
        break;
    case 17:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuState.currentState = 1;
            *arg0 = 0;
            return 1;
        }
        break;
    }
    return 0;
}
