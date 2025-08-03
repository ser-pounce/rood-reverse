#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

int func_80102928(int, int, u_short**);
int func_80102CAC();

extern int D_1F800000[];

extern u_short D_80104690[];
extern u_short D_801046D4[];
extern u_short* D_80104EB4;
extern int D_80104EB8;
extern u_int D_80104EBC;
extern char D_80104EC0;
extern char D_80104EC1;
extern char D_80104EC2;
extern int D_80104EC4;
extern int D_80104EC8;
extern int D_80104ED0;
extern u_short D_80104ED8[];
extern char D_8010505A[];
extern char D_80105078[];
extern char D_801050C0;
extern u_char D_801050C1;
extern char D_801050D0[];
extern char D_801050E0[];
extern char D_801050F0;
extern char _stringBuffer[];

static void _setAbilityCost(int ability)
{
    int i;
    int cost;

    vs_mainmenu_setAbilityCost(1, "RISK", 8, 0);
    cost = vs_main_skills[ability].cost;
    _stringBuffer[15] = 0;

    i = 15;
    do {
        --i;
        cost = vs_battle_toBCD(cost);
        _stringBuffer[i] = (cost & 0xF) + 0x30;
        cost >>= 4;
    } while (cost != 0);

    --i;
    _stringBuffer[i] = '#';
    vs_mainmenu_setAbilityCost(0, &_stringBuffer[i], 0x48, 0);
}

int func_80102928(int arg0, int arg1, u_short** arg2)
{
    int temp_v1_2;
    int j;
    int i;
    u_short* var_v1;

    i = 0;
    j = 0;
    if (D_80104EB4 != 0) {
        return 0;
    }

    D_80104EC0 = arg1;

    if (D_80060021 != 0) {
        i = D_800F4EE8.unk0[arg1 * 2];
        j = D_800F4EE8.unk0[arg1 * 2 + 1];
    }

    temp_v1_2 = arg0 - 8;

    if (temp_v1_2 < 0) {
        i += j;
        j = 0;
        if (i >= arg0) {
            i = 0;
        }
    } else {
        if (temp_v1_2 < j) {
            if ((i + j) >= arg0) {
                i = 0;
                j = 0;
            } else {
                i += j - temp_v1_2;
                j = temp_v1_2;
            }
        }

        if ((j > 0) && (i == 0)) {
            i = 1;
            --j;
        }
        if (j < temp_v1_2) {
            if (i == 7) {
                i = 6;
                ++j;
            }
        }
    }

    D_80104EB8 = i;
    D_80104EC2 = j;

    if (arg1 == 0x18) {
        _setAbilityCost(D_801050D0[i + j]);
    } else {
        _setAbilityCost(D_801050E0[i + j]);
    }

    D_80104EC1 = arg0;
    D_80104EBC = 0;

    D_80104EB4 = vs_main_allocHeapR(arg0 << 7);

    for (i = 0; i < arg0; ++i) {
        var_v1 = (arg2 + i * 2)[0];
        if (var_v1 != 0) {
            D_80104EB4[i * 64] = 0x10FA;
            for (j = 0; j < 14; ++j) {
                (i * 64 + j + D_80104EB4)[1] = var_v1[j];
            }
            D_80104EB4[i * 64 + 15] = 0xE7E7;
        } else {
            D_80104EB4[i * 64] = 0xE7E7;
        }
        var_v1 = (arg2 + i * 2)[1];
        if (var_v1 != 0) {
            D_80104EB4[i * 64 + 16] = 0xF8;
            for (j = 0; j < 46; ++j) {
                (i * 64 + j + D_80104EB4)[17] = var_v1[j];
            }
            D_80104EB4[i * 64 + 63] = 0xE7E7;
        } else {
            D_80104EB4[i * 64 + 16] = 0xE7E7;
        }
    }
    return 1;
}

static void func_80102B5C(int arg0, int arg1, int arg2)
{
    int i;

    if (arg0 == 0x18) {
        arg2 = D_801050D0[arg2];
        if (vs_main_settings.unkC[arg1] == arg2) {
            vs_battle_playMenuLeaveSfx();
            vs_main_settings.unkC[arg1] = 0;
            return;
        }
        vs_main_playSfxDefault(0x7E, 0x23);
        for (i = 0; i < 3; ++i) {
            if (vs_main_settings.unkC[i] == arg2) {
                vs_main_settings.unkC[i] = 0;
            }
        }
        vs_main_settings.unkC[arg1] = arg2;
    } else {
        arg2 = D_801050E0[arg2];
        if (vs_main_settings.unk10[arg1] == arg2) {
            vs_battle_playMenuLeaveSfx();
            vs_main_settings.unk10[arg1] = 0;
            return;
        }
        vs_main_playSfxDefault(0x7E, 0x23);
        for (i = 0; i < 3; ++i) {
            if (vs_main_settings.unk10[i] == arg2) {
                vs_main_settings.unk10[i] = 0;
            }
        }
        vs_main_settings.unk10[arg1] = arg2;
    }
}

int func_80102CAC()
{
    int temp_s3;
    int temp_s6;
    int var_s1;
    int temp_s7;
    int var_s0;
    int var_v0;
    vs_battle_menuItem_t* temp_v0;

    temp_s3 = D_1F800000[2] + 8;

    if (D_80104EBC < 0xA) {
        temp_v0
            = vs_battle_setMenuItem(D_80104EBC + 0x14, 0x140, (D_80104EBC * 0x10) + 0x32,
                0x7E, 0, (char*)(D_80104EB4 + ((D_80104EC2 + D_80104EBC) << 6)));
        temp_v0->state = 2;
        temp_v0->x = 0xC2;
        if ((D_80104EBC == 0) && (D_80104EC2 != 0)) {
            temp_v0->unk5 = 1;
        }
        if (++D_80104EBC == D_80104EC1) {
            D_80104EBC = 0x10;
        }
        if (D_80104EBC == 8) {
            if ((D_80104EC2 + 8u) < D_80104EC1) {
                temp_v0->unk5 = 2;
            }
            D_80104EBC = 0x10;
        }
        return 0;
    }

    vs_battle_getMenuItem(D_80104EB8 + 0x14);
    vs_mainmenu_setMessage(
        (char*)(D_80104EB4 + (((D_80104EB8 + D_80104EC2) << 6) + 0x10)));

    switch (D_80104EBC) {
    case 16:
        if (vs_mainmenu_ready() != 0) {
            D_80104EBC = 0x11;
        }
        break;
    case 17:
        D_801022D4 = 0;
        temp_s6 = D_80104EB8 + D_80104EC2;
        temp_s7 = D_80104EC2;
        if (D_80104EC1 < 9) {
            for (var_s1 = 0; var_s1 < D_80104EC1; ++var_s1) {
                if (D_80104EC0 == 0x18) {
                    var_s0 = D_801050D0[var_s1];
                    if (vs_main_settings.unkC[0] == var_s0) {
                        func_800FFC68(2, 0xC7, var_s1 * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.unkC[1] == var_s0) {
                        func_800FFC68(0, 0xC7, var_s1 * 0x10 + 0x30, temp_s3);
                    }
                    var_v0 = vs_main_settings.unkC[2];
                } else {
                    var_s0 = D_801050E0[var_s1];
                    if (vs_main_settings.unk10[0] == var_s0) {
                        func_800FFC68(2, 0xC7, var_s1 * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.unk10[1] == var_s0) {
                        func_800FFC68(0, 0xC7, var_s1 * 0x10 + 0x30, temp_s3);
                    }
                    var_v0 = vs_main_settings.unk10[2];
                }
                if (var_v0 == var_s0) {
                    func_800FFC68(1, 0xC7, var_s1 * 0x10 + 0x30, temp_s3);
                }
            }
        } else {
            for (var_s1 = 0; var_s1 < 8; ++var_s1) {
                if (D_80104EC0 == 0x18) {
                    var_s0 = D_801050D0[var_s1 + D_80104EC2];
                    if (vs_main_settings.unkC[0] == var_s0) {
                        func_800FFC68(2, 0xC7, var_s1 * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.unkC[1] == var_s0) {
                        func_800FFC68(0, 0xC7, var_s1 * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.unkC[2] == var_s0) {
                        func_800FFC68(1, 0xC7, var_s1 * 0x10 + 0x30, temp_s3);
                    }
                } else {
                    var_s0 = D_801050E0[var_s1 + D_80104EC2];
                    if (vs_main_settings.unk10[0] == var_s0) {
                        func_800FFC68(2, 0xC7, var_s1 * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.unk10[1] == var_s0) {
                        func_800FFC68(0, 0xC7, var_s1 * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.unk10[2] == var_s0) {
                        func_800FFC68(1, 0xC7, var_s1 * 0x10 + 0x30, temp_s3);
                    }
                }
            }
        }
        if (vs_main_buttonsPressed & 0x20) {
            func_80102B5C(D_80104EC0, 0, temp_s6);
        } else if (vs_main_buttonsPressed & 0x10) {
            func_80102B5C(D_80104EC0, 1, temp_s6);
        } else if (vs_main_buttonsPressed & 0x80) {
            func_80102B5C(D_80104EC0, 2, temp_s6);
        }
        vs_battle_getMenuItem(D_80104EB8 + 0x14)->selected = 0;
        if (vs_main_buttonsPressed & 0x40) {
            vs_battle_playMenuLeaveSfx();
            vs_main_freeHeapR(D_80104EB4);
            D_80104EB4 = 0;
            D_800F4EE8.unk0[D_80104EC0 * 2] = D_80104EB8;
            D_800F4EE8.unk0[D_80104EC0 * 2 + 1] = D_80104EC2;
            return 1;
        }

        if (vs_main_buttonRepeat & 0x1000) {
            if (D_80104EC1 < 9) {
                if (D_80104EB8 == 0) {
                    D_80104EB8 = D_80104EC1 - 1;
                } else {
                    --D_80104EB8;
                }
            } else {
                if (D_80104EC2 == 0) {
                    if (D_80104EB8 == 0) {
                        if (vs_main_buttonsPressed & 0x1000) {
                            D_80104EB8 = 7;
                            D_80104EC2 = D_80104EC1 - 8;
                        }
                    } else {
                        --D_80104EB8;
                    }
                } else {
                    if (D_80104EB8 == 1) {
                        --D_80104EC2;
                    } else {
                        --D_80104EB8;
                    }
                }
            }
        }
        if (vs_main_buttonRepeat & 0x4000) {
            if (D_80104EC1 < 9) {
                if (D_80104EB8 == (D_80104EC1 - 1)) {
                    D_80104EB8 = 0;
                } else {
                    ++D_80104EB8;
                }
            } else {
                if (D_80104EC2 == (D_80104EC1 - 8)) {
                    if (D_80104EB8 == 7) {
                        if (vs_main_buttonsPressed & 0x4000) {
                            D_80104EB8 = 0;
                            D_80104EC2 = 0;
                        }
                    } else {
                        ++D_80104EB8;
                    }
                } else if (D_80104EB8 == 6) {
                    ++D_80104EC2;
                } else {
                    ++D_80104EB8;
                }
            }
        }
        if (temp_s6 != (D_80104EB8 + D_80104EC2)) {
            vs_battle_playMenuChangeSfx();
            if (D_80104EC2 != temp_s7) {
                char sp18[D_80104EC1];

                for (var_s1 = 0; var_s1 < D_80104EC1; ++var_s1) {
                    sp18[var_s1] = 0;
                }

                var_s0 = D_80104EC1;
                if (D_80104EC1 >= 9) {
                    var_s0 = 8;
                }

                for (var_s1 = 0; var_s1 < var_s0; ++var_s1) {
                    temp_v0 = vs_battle_getMenuItem(var_s1 + 0x14);
                    sp18[var_s1 + temp_s7] = temp_v0->unk4;
                }

                for (var_s1 = 0;;) {
                    temp_v0
                        = vs_battle_setMenuItem(var_s1 + 0x14, 0xC2, 0x32 + var_s1 * 0x10,
                            0x7E, 0, (char*)(D_80104EB4 + ((D_80104EC2 + var_s1) << 6)));
                    temp_v0->unk4 = sp18[var_s1 + D_80104EC2];
                    if ((var_s1 == 0) && (D_80104EC2 != 0)) {
                        temp_v0->unk5 = 1;
                    }
                    ++var_s1;
                    if (var_s1 == D_80104EC1) {
                        break;
                    } else if (var_s1 == 8) {
                        if ((D_80104EC2 + 8) < D_80104EC1) {
                            temp_v0->unk5 = 2;
                        }
                        break;
                    }
                }
            }
        }
        vs_battle_getMenuItem(D_80104EB8 + 0x14)->selected = 1;
        D_80104EC4 = vs_battle_drawCursor(D_80104EC4, D_80104EB8 + 2);
        if (D_80104EC0 == 0x18) {
            _setAbilityCost(D_801050D0[D_80104EB8 + D_80104EC2]);
        } else {
            _setAbilityCost(D_801050E0[D_80104EB8 + D_80104EC2]);
        }
        break;
    }
    return 0;
}

int func_801034FC(int arg0)
{
    u_short* menuStrings[28];
    int i;
    int row;
    int skill;

    if (arg0 != 0) {
        func_800FA92C(0, 1);
        D_80104EC8 = 0;
        return 0;
    }

    switch (D_80104EC8) {
    case 0:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }
        row = 0;
        for (i = 0; i < 14; ++i) {
            skill = vs_battle_chainAbilityOffsets[i];
            if ((vs_main_skills[skill].flags >> 0xF) & 1) {
                menuStrings[row * 2] = (u_short*)vs_main_skills[skill].name;
                menuStrings[row * 2 + 1] = &D_80104690[D_80104690[6 + i]];
                D_801050D0[row] = skill;
                ++row;
            }
        }
        func_80102928(row, 0x18, menuStrings);
        D_80104EC8 = 1;
        break;
    case 1:
        if (func_80102CAC() != 0) {
            func_800FA8E0(2);
            return 1;
        }
        break;
    }
    return 0;
}

static int func_80103670(int arg0)
{
    u_short* menuStrings[28];
    int i;
    int row;
    int skill;

    if (arg0 != 0) {
        func_800FA92C(1, 1);
        D_80104ED0 = 0;
        return 0;
    }

    switch (D_80104ED0) {
    case 0:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }
        row = 0;
        for (i = 0; i < 14; ++i) {
            skill = vs_battle_defenseAbilityOffsets[i];
            if ((vs_main_skills[skill].flags >> 0xF) & 1) {
                menuStrings[row * 2] = (u_short*)vs_main_skills[skill].name;
                menuStrings[row * 2 + 1] = &D_80104690[D_80104690[0x14 + i]];
                D_801050E0[row] = skill;
                ++row;
            }
        }
        func_80102928(row, 0x19, menuStrings);
        D_80104ED0 = 1;
        break;
    case 1:
        if (func_80102CAC() != 0) {
            func_800FA8E0(2);
            return 1;
        }
        break;
    }
    return 0;
}

static void _drawPointsRemaining(int arg0)
{
    char pointsBuf[16];
    int pos;
    char* pointsStr;

    int points = vs_main_artsStatus.kills.total;
    int i = vs_main_artsStatus.kills.battleAbilitiesUnlocked;

    if (i == 22) {
        return;
    }

    points = vs_main_battleAbilitiesPointsRequirements[i] - points;
    if (points < 0) {
        points = 0;
    }

    pos = (arg0 + 0xCE) | 0x420000;

    pointsBuf[14] = 'T';
    pointsBuf[15] = 0;
    pointsBuf[13] = 'P';

    i = 12;
    do {
        points = vs_battle_toBCD(points);
        *(pointsBuf + i) = (points & 0xF) + 48;
        points >>= 4;
        i -= 1;
    } while (points != 0);

    pointsStr = pointsBuf + i;
    *pointsStr = '#';
    vs_battle_renderTextRaw("NEXT", pos, 0);
    vs_battle_renderTextRaw(pointsStr, pos + 0x60, 0);
}

int func_801038D4(char* arg0)
{
    char* sp18[4];
    int sp28[2];
    int temp_s0;
    int temp_s0_3;

    switch (*arg0) {
    case 3:
        D_801050C0 = 0;
        D_801050C1 = 0xA;
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        func_800FFBC8();

        if (vs_battle_shortcutInvoked != 0) {
            temp_s0 = vs_battle_shortcutInvoked - 7;
            vs_battle_setMenuItem(vs_battle_shortcutInvoked + 3, 0x140, 0x22, 0x8C, 8,
                (char*)&D_80104690[*((temp_s0 * 3) + D_80104690)])
                ->selected
                = 1;
            if (temp_s0 == 0) {
                *arg0 = 6;
                func_801034FC(1);
            } else {
                *arg0 = 7;
                func_80103670(1);
            }
            break;
        }
    // Fallthrough
    case 4:
        if (vs_mainmenu_ready() != 0) {
            sp18[0] = (char*)D_801046D4;
            sp18[1] = (char*)&D_801046D4[8];
            sp28[0] = 0;
            sp28[1] = 0;
            if (vs_battle_abilitiesUnlocked(0) == 0) {
                sp18[0] = (char*)((long)sp18[0] | 1);
                sp18[1] = (char*)&D_801046D4[0x35];
            }
            sp18[2] = (char*)&D_801046D4[0x4D];
            sp18[3] = (char*)&D_801046D4[0x56];
            if (vs_battle_abilitiesUnlocked(1) == 0) {
                sp28[1] |= 1;
                sp18[3] = (char*)&D_801046D4[0x84];
            }
            temp_s0_3 = vs_main_settings.cursorMemory;
            if (*arg0 != 3) {
                vs_main_settings.cursorMemory = 1;
            }
            vs_mainmenu_setMenuRows(2, 0x117, (char**)sp18, sp28);
            vs_main_settings.cursorMemory = temp_s0_3;
            *arg0 = 5;
        }
        break;
    case 5:
        D_801050C0 = 1;
        temp_s0_3 = vs_mainmenu_getSelectedRow() + 1;
        if (temp_s0_3 != 0) {
            D_801050C0 = 0;
            if (temp_s0_3 == 1) {
                *arg0 = 6;
                func_801034FC(1);
                break;
            }
            if (temp_s0_3 == 2) {
                *arg0 = 7;
                func_80103670(1);
                break;
            }
            func_800FA8E0(0x28);
            if (temp_s0_3 != -2) {
                *arg0 = 8;
            } else {
                *arg0 = 9;
            }
        }
        break;
    case 6:
        if (func_801034FC(0) != 0) {
            if (vs_battle_shortcutInvoked != 0) {
                func_800FA8E0(0x28);
                *arg0 = 9;
            } else {
                *arg0 = 4;
            }
        }
        break;
    case 7:
        if (func_80103670(0) != 0) {
            if (vs_battle_shortcutInvoked != 0) {
                func_800FA8E0(0x28);
                *arg0 = 9;
            } else {
                *arg0 = 4;
            }
        }
        break;
    case 8:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            *arg0 = 0;
            return 1;
        }
        break;
    case 9:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuState.currentState = 3;
            *arg0 = 0;
            return 1;
        }
        break;
    }

    if (D_801050C0 != 0) {
        _drawPointsRemaining(vs_battle_rowAnimationSteps[D_801050C1]);
        if (D_801050C1 != 0) {
            --D_801050C1;
        }
    } else {
        if (D_801050C1 < 10) {
            ++D_801050C1;
            _drawPointsRemaining((D_801050C1 & 0xFF) << 5);
        }
    }
    return 0;
}

int func_80103C3C(int arg0)
{
    int weaponTypeMod;
    int skillId;
    int weaponType;
    char(*new_var)[12];

    if (arg0 != 0) {

        weaponType = vs_battle_characterState->equippedWeaponType;
        weaponTypeMod = weaponType;
        new_var = &vs_main_artsStatus.artsLearned;
        weaponTypeMod %= 10;
        skillId = (*new_var)[weaponTypeMod];

        if (skillId == 4) {
            return 1;
        }

        if (vs_main_artsStatus.kills.weaponCategories[weaponTypeMod]
            < vs_main_artsPointsRequirements[weaponTypeMod][skillId]) {
            return 1;
        }

        func_800C8E04(3);
        vs_main_artsStatus.artsLearned[weaponTypeMod] = skillId + 1;
        skillId = 0xB8 + ((weaponType - 1) * 4) + skillId;
        D_800F5168[10] = (char*)&D_80104ED8[D_80104ED8[weaponType]];
        D_800F5168[11] = vs_main_skills[skillId].name;
        vs_mainmenu_setMessage((char*)&D_80104ED8[0x12]);
        vs_main_skills[skillId].flags |= 0x8000;
        D_801050F0 = 0x78;

    } else if ((D_800F5130 >> 0x1E) & 1) {
        if ((D_801050F0 == 0) || ((char)vs_main_buttonsPressed != 0)) {
            return 1;
        }
        --D_801050F0;
    }
    return 0;
}

char* func_80103DD8(int arg0)
{
    u_char temp_v1;

    temp_v1 = D_80105078[arg0];
    if (D_80105078[arg0] == 0) {
        return D_8010505A;
    }
    return (char*)&D_80104690[D_80104690[temp_v1]];
}
