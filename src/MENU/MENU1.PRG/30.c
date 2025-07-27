#include "common.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../../build/src/BATTLE/BATTLE.PRG/menuStrings.h"

int func_80102A4C(int);
int func_80102F68(int);

extern u_short _strings[];

static void _setArtCost(int art)
{
    extern char _digitBuffer[16];

    int flags;
    int i;
    int cost;

    flags = vs_battle_getSkillFlags(0, art);
    vs_mainmenu_setAbilityCost(1, "HP", 8, (flags >> 1) & 1);
    cost = vs_main_skills[art].cost;
    _digitBuffer[15] = 0;

    i = 15;
    do {
        --i;
        cost = vs_battle_toBCD(cost);
        _digitBuffer[i] = (cost & 0xF) + 0x30;
        cost >>= 4;
    } while (cost != 0);

    --i;
    _digitBuffer[i] = '#';
    vs_mainmenu_setAbilityCost(0, &_digitBuffer[i], 72, (flags >> 1) & 1);
}

void _drawPointsRemaining(int x, int weaponCategory, int artsLearned)
{
    char pointsBuf[16];
    int pos;
    int category;
    int points;
    int i;
    char* pointsStr;

    category = weaponCategory;
    category %= 10;

    i = vs_main_artsStatus.artsLearned[category];
    if (i != 4) {
        points = vs_main_artsStatus.kills[category];
        points = vs_main_artsPointsRequirements[category][i] - points;
        if (points < 0) {
            points = 0;
        }
        pos = (x + 206) | (((artsLearned * 16) + 50) << 16);
        pointsBuf[14] = 'T';
        pointsBuf[15] = 0;
        pointsBuf[13] = 'P';
        i = 12;
        do {
            points = vs_battle_toBCD(points);
            pointsBuf[i] = (points & 0xF) + '0';
            points = points >> 4;
            --i;
        } while (points != 0);
        pointsStr = pointsBuf + i;
        *pointsStr = '#';
        func_800C6828("NEXT", pos, 0);
        func_800C6828(pointsStr, pos + 96, 0);
    }
}

extern char D_800EBC7C[];
extern char D_801022D4;
extern int D_80104500;
extern int D_80104504;
extern int D_80104508;
extern int D_8010450C;
extern char D_8010452C;
extern u_char D_8010452D;
extern char D_8010452E;
extern char D_8010452F;
extern u_short D_8010453C[];

int func_80102A4C(int arg0)
{
    char* sp18[10];
    int sp40[5];
    int temp_s2;
    int i;
    int var_s3;
    vs_battle_menuItem_t* temp_v0;
    int mem;

    if (arg0 != 0) {
        int new_var = arg0 >> 4;
        arg0 &= 0xF;
        D_8010452C = 0;
        D_8010452D = 0xA;
        D_80104508 = new_var;
        D_8010450C = arg0;
        temp_v0 = vs_battle_setMenuItem(
            0xA, 0x140, 0x22, 0x7E, 8, (char*)&_strings[_strings[(arg0 - 1) * 3]]);
        temp_v0->state = 2;
        temp_v0->x = 0xB4;
        temp_v0->selected = 1;
        temp_v0->unk9 = arg0;
        D_80104500 = 0;
        return 0;
    }
    switch (D_80104500) {
    case 0:
        if ((D_800F4E6A != 0) || (vs_mainmenu_readyForInput() != 0)) {
            var_s3 = 0;
            for (i = 0; i < 4; ++i) {
                temp_s2 = 0xB8 + (D_8010450C - 1) * 4 + i;
                if ((vs_main_skills[temp_s2].flags >> 0xF) & 1) {
                    sp18[var_s3 * 2] = (char*)vs_main_skills[temp_s2].name;
                    sp18[var_s3 * 2 + 1]
                        = (char*)&_strings[_strings[32 + i + ((D_8010450C - 1) * 4)]];
                    sp40[var_s3] = 0;
                    if ((D_8010450C != D_800F19FC->unk25)
                        || (vs_battle_getSkillFlags(0, temp_s2) != 0)) {
                        sp40[var_s3] = 1;
                    }
                    D_8010453C[var_s3] = temp_s2;
                    ++var_s3;
                }
            }

            for (i = 0; i < 4; ++i) {
                if (D_800F4EA0 & 0x15F) {
                    sp40[i] |= 1;
                }
            }

            if (D_800F4E6A == 0) {
                sp18[var_s3 * 2] = (char*)&_strings[569];
                sp18[var_s3 * 2 + 1] = (char*)&_strings[569 + 5];
                sp40[var_s3] = 2;
                D_8010453C[var_s3] = 0xFFFF;
                ++var_s3;
            }
            mem = vs_main_settings.cursorMemory;
            if (D_80104508 != 0) {
                vs_main_settings.cursorMemory = 1;
                D_80104508 = 0;
            }
            func_801005E0(var_s3, (D_8010450C + 0xB) | 0x200, sp18, sp40);
            vs_main_settings.cursorMemory = mem;
            D_80104500 = 1;
            D_8010452E = var_s3;
            D_8010452F = var_s3;
        }
        break;
    case 1:
        if (D_8010452F != 0) {
            --D_8010452F;
        }
        D_8010452C = D_8010452F == 0;
        D_80104504 = func_801008C8() + 1;
        D_801022D4 = 0;
        if (D_80104504 != 0) {
            D_8010452C = 0;
            if (D_80104504 > 0) {
                D_80104504 = D_8010453C[D_80104504 - 1];
            } else if (D_800F4E6A != 0) {
                D_80104504 = -2;
            }
            if (D_80104504 == 0xFFFF) {
                func_800FA8E0(1);
            } else {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            }
            D_80104500 = 2;
        } else {
            i = D_8010453C[func_801008B0()];
            if (i != 0xFFFF) {
                _setArtCost(i);
            }
        }
        break;
    case 2:
        if (vs_mainmenu_readyForInput() != 0) {
            return D_80104504;
        }
        break;
    }

    if (D_8010452C != 0) {
        if (D_8010452D != 0) {
            --D_8010452D;
        }
    } else {
        D_8010452D = *(D_8010452D + D_800EBC7C);
    }
    _drawPointsRemaining(D_800EBBC8[D_8010452D], D_8010450C, D_8010452E);
    return 0;
}

int func_80102F68(int arg0)
{
    extern int D_80104510;
    extern int D_80104514;

    char* sp18[10][2];
    int sp68[10];
    int j;
    int i;
    vs_battle_menuItem_t* temp_v0;

    if (arg0 != 0) {
        temp_v0
            = vs_battle_setMenuItem(0xA, 0x140, 0x22, 0x7E, 8, (char*)(_strings + 569));
        temp_v0->state = 2;
        temp_v0->x = 0xB4;
        temp_v0->selected = 1;
        D_80104510 = 0;
        return 0;
    }

    switch (D_80104510) {
    case 0:
        if (vs_mainmenu_readyForInput() != 0) {
            for (i = 0; i < 10; ++i) {
                int v = 1;
                sp18[i][0] = (char*)&_strings[_strings[i * 3]];
                sp18[i][v] = (char*)&_strings[_strings[(i * 3) + 1]];
                sp68[i] = 0x04000000 * (i + 1);
                for (j = 0; j < 4; ++j) {
                    if ((vs_main_skills[((i * 4) + 0xB8) + j].flags >> 0xF) & 1) {
                        break;
                    }
                }
                if (j == 4) {
                    int v = 1;
                    sp18[i][v] = (char*)&_strings[_strings[(i * 3) + 2]];
                    sp68[i] |= 1;
                } else if (i == (D_800F19FC->unk25 - 1)) {
                    sp68[i] |= 4;
                }
            }
            func_801005E0(10, 0x216, (char**)sp18, sp68);
            D_80104510 = 1;
        }
        break;
    case 1:
        D_80104514 = func_801008C8() + 1;
        if (D_80104514 != 0) {
            if (D_80104514 == -2) {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            } else {
                func_800FA8E0(1);
            }
            D_80104510 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_readyForInput() != 0) {
            return D_80104514;
        }
        break;
    }
    return 0;
}

void func_801031FC()
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = vs_battle_setMenuItem(1, 0x140, 0x12, 0x8C, 8,
        (char*)&vs_battle_menuStrings
            [vs_battle_menuStrings[VS_menuStrings_INDEX_breakArts]]);
    temp_v0->state = 2;
    temp_v0->x = 180;
    temp_v0->selected = 1;
    func_800FFA88(2);
    func_800FFBC8();
}

int vs_menu1_exec(char* state)
{
    enum state { init = 3 };

    extern int D_80104518;

    int temp_v0;
    int var_a0;
    char temp_a1;

    switch (*state) {
    case init:
        if (vs_mainmenu_readyForInput() == 0) {
            break;
        }
        func_800FFBC8();
        D_80104518 = D_800F19FC->unk25;
        // Fallthrough
    case 4:
        var_a0 = D_80104518;
        func_80102A4C(var_a0);
        *state = 6;
        break;
    case 5:
        func_801031FC();
        var_a0 = D_80104518 | 0x10;
        func_80102A4C(var_a0);
        *state = 6;
        break;
    case 6:
        temp_v0 = func_80102A4C(0);
        if (temp_v0 == 0) {
            break;
        }
        if (temp_v0 > 0) {
            if (temp_v0 == 0xFFFF) {
                *state = 7;
                func_80102F68(1);
            } else {
                D_800F4E9C = temp_v0;
                D_800F51C2 = 5;
                *state = 9;
            }
        } else if (temp_v0 != -2) {
            *state = 8;
        } else {
            *state = 10;
        }
        break;
    case 7:
        temp_v0 = func_80102F68(0);
        if (temp_v0 == 0) {
            break;
        }
        if (temp_v0 == -2) {
            *state = 10;
        } else {
            if (temp_v0 > 0) {
                D_80104518 = temp_v0;
            }
            *state = 4;
        }
        break;
    case 8:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_readyForInput() != 0) {
            *state = 0;
            return 1;
        }
        break;
    case 9:
        if (vs_mainmenu_readyForInput() != 0) {
            D_800F4E9A = 6;
            temp_a1 = D_800F51C0.unk0;
            D_800F51C0.unk0 = 2;
            D_800F51C0.unk1 = temp_a1;
            *state = 0;
            return 1;
        }
        break;
    case 10:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_readyForInput() != 0) {
            D_800F51C0.unk0 = 2;
            *state = 0;
            return 1;
        }
        break;
    }
    return 0;
}
