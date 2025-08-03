#include "../../assets/MENU/MENU2.PRG/battleAbilities.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "vs_string.h"
#include <libetc.h>

static void _setAbilityCost(int ability)
{
    static char _stringBuffer[16];

    int i;
    int cost;

    vs_mainmenu_setAbilityCost(1, "RISK", 8, 0);
    cost = vs_main_skills[ability].cost;
    _stringBuffer[15] = 0;

    i = 15;
    do {
        --i;
        cost = vs_battle_toBCD(cost);
        _stringBuffer[i] = (cost & 0xF) + '0';
        cost >>= 4;
    } while (cost != 0);

    --i;
    _stringBuffer[i] = '#';
    vs_mainmenu_setAbilityCost(0, &_stringBuffer[i], 72, 0);
}

u_short _battleAbilityStrings[] = {
#include "../../assets/MENU/MENU2.PRG/battleAbilities.vsString"
};
static u_short* D_80104EB4 = NULL;
static int _highlightedAbility = 0;
static u_int D_80104EBC = 0;
static char _selectedAbilityType = 0;
static char _abilityCount = 0;
static char _firstAbility = 0;

static char _unlockedChainAbilities[16];
static char _unlockedDefenseAbilities[16];

enum abilityType { abilityTypeChain = 24 };

static int _initAbilityMenu(int abilityCount, int type, u_short** arg2)
{
    int temp_v1_2;
    u_short* param;
    int i = 0;
    int j = 0;

    if (D_80104EB4 != 0) {
        return 0;
    }

    _selectedAbilityType = type;

    if (D_80060021 != 0) {
        i = D_800F4EE8.unk0[type * 2];
        j = D_800F4EE8.unk0[type * 2 + 1];
    }

    temp_v1_2 = abilityCount - 8;

    if (temp_v1_2 < 0) {
        i += j;
        j = 0;
        if (i >= abilityCount) {
            i = 0;
        }
    } else {
        if (temp_v1_2 < j) {
            if ((i + j) >= abilityCount) {
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

    _highlightedAbility = i;
    _firstAbility = j;

    if (type == abilityTypeChain) {
        _setAbilityCost(_unlockedChainAbilities[i + j]);
    } else {
        _setAbilityCost(_unlockedDefenseAbilities[i + j]);
    }

    _abilityCount = abilityCount;
    D_80104EBC = 0;

    D_80104EB4 = vs_main_allocHeapR(abilityCount << 7);

    for (i = 0; i < abilityCount; ++i) {
        param = arg2[i * 2];
        if (param != 0) {
            D_80104EB4[i * 64] = vs_char_spacing | 16 << 8;
            for (j = 0; j < 14; ++j) {
                (i * 64 + j + D_80104EB4)[1] = param[j];
            }
            D_80104EB4[i * 64 + 15] = vs_char_terminator << 8 | vs_char_terminator;
        } else {
            D_80104EB4[i * 64] = vs_char_terminator << 8 | vs_char_terminator;
        }
        param = arg2[i * 2 + 1];
        if (param != 0) {
            D_80104EB4[i * 64 + 16] = vs_char_chunkSize;
            for (j = 0; j < 46; ++j) {
                D_80104EB4[i * 64 + j + 17] = param[j];
            }
            D_80104EB4[i * 64 + 63] = vs_char_terminator << 8 | vs_char_terminator;
        } else {
            D_80104EB4[i * 64 + 16] = vs_char_terminator << 8 | vs_char_terminator;
        }
    }
    return 1;
}

static void _mapAbility(int type, int key, int ability)
{
    int i;

    if (type == abilityTypeChain) {
        ability = _unlockedChainAbilities[ability];
        if (vs_main_settings.mappedChainAbilities[key] == ability) {
            vs_battle_playMenuLeaveSfx();
            vs_main_settings.mappedChainAbilities[key] = 0;
            return;
        }
        vs_main_playSfxDefault(0x7E, 0x23);
        for (i = 0; i < 3; ++i) {
            if (vs_main_settings.mappedChainAbilities[i] == ability) {
                vs_main_settings.mappedChainAbilities[i] = 0;
            }
        }
        vs_main_settings.mappedChainAbilities[key] = ability;
    } else {
        ability = _unlockedDefenseAbilities[ability];
        if (vs_main_settings.mappedDefenseAbilities[key] == ability) {
            vs_battle_playMenuLeaveSfx();
            vs_main_settings.mappedDefenseAbilities[key] = 0;
            return;
        }
        vs_main_playSfxDefault(0x7E, 0x23);
        for (i = 0; i < 3; ++i) {
            if (vs_main_settings.mappedDefenseAbilities[i] == ability) {
                vs_main_settings.mappedDefenseAbilities[i] = 0;
            }
        }
        vs_main_settings.mappedDefenseAbilities[key] = ability;
    }
}

static int _abilityMenu()
{
    extern int D_1F800000[];
    static int _cursorAnimStep = 0;

    int temp_s3;
    int selectedAbility;
    int i;
    int temp_s7;
    int ability;
    vs_battle_menuItem_t* menuItem;

    temp_s3 = D_1F800000[2] + 8;

    if (D_80104EBC < 10) {
        menuItem = vs_battle_setMenuItem(D_80104EBC + 20, 320, (D_80104EBC * 16) + 50,
            0x7E, 0, (char*)(D_80104EB4 + ((_firstAbility + D_80104EBC) << 6)));
        menuItem->state = 2;
        menuItem->x = 194;
        if ((D_80104EBC == 0) && (_firstAbility != 0)) {
            menuItem->unk5 = 1;
        }
        if (++D_80104EBC == _abilityCount) {
            D_80104EBC = 16;
        }
        if (D_80104EBC == 8) {
            if ((_firstAbility + 8u) < _abilityCount) {
                menuItem->unk5 = 2;
            }
            D_80104EBC = 16;
        }
        return 0;
    }

    vs_battle_getMenuItem(_highlightedAbility + 20);
    vs_mainmenu_setMessage(
        (char*)(D_80104EB4 + (((_highlightedAbility + _firstAbility) << 6) + 16)));

    switch (D_80104EBC) {
    case 16:
        if (vs_mainmenu_ready() != 0) {
            D_80104EBC = 17;
        }
        break;
    case 17:
        D_801022D4 = 0;
        selectedAbility = _highlightedAbility + _firstAbility;
        temp_s7 = _firstAbility;
        if (_abilityCount < 9) {
            for (i = 0; i < _abilityCount; ++i) {
                if (_selectedAbilityType == abilityTypeChain) {
                    ability = _unlockedChainAbilities[i];
                    if (vs_main_settings.mappedChainAbilities[0] == ability) {
                        func_800FFC68(2, 0xC7, i * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.mappedChainAbilities[1] == ability) {
                        func_800FFC68(0, 0xC7, i * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.mappedChainAbilities[2] == ability) {
                        func_800FFC68(1, 0xC7, i * 0x10 + 0x30, temp_s3);
                    }
                } else {
                    ability = _unlockedDefenseAbilities[i];
                    if (vs_main_settings.mappedDefenseAbilities[0] == ability) {
                        func_800FFC68(2, 0xC7, i * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.mappedDefenseAbilities[1] == ability) {
                        func_800FFC68(0, 0xC7, i * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.mappedDefenseAbilities[2] == ability) {
                        func_800FFC68(1, 0xC7, i * 0x10 + 0x30, temp_s3);
                    }
                }
            }
        } else {
            for (i = 0; i < 8; ++i) {
                if (_selectedAbilityType == abilityTypeChain) {
                    ability = _unlockedChainAbilities[i + _firstAbility];
                    if (vs_main_settings.mappedChainAbilities[0] == ability) {
                        func_800FFC68(2, 0xC7, i * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.mappedChainAbilities[1] == ability) {
                        func_800FFC68(0, 0xC7, i * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.mappedChainAbilities[2] == ability) {
                        func_800FFC68(1, 0xC7, i * 0x10 + 0x30, temp_s3);
                    }
                } else {
                    ability = _unlockedDefenseAbilities[i + _firstAbility];
                    if (vs_main_settings.mappedDefenseAbilities[0] == ability) {
                        func_800FFC68(2, 0xC7, i * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.mappedDefenseAbilities[1] == ability) {
                        func_800FFC68(0, 0xC7, i * 0x10 + 0x30, temp_s3);
                    }
                    if (vs_main_settings.mappedDefenseAbilities[2] == ability) {
                        func_800FFC68(1, 0xC7, i * 0x10 + 0x30, temp_s3);
                    }
                }
            }
        }

        if (vs_main_buttonsPressed & PADRright) {
            _mapAbility(_selectedAbilityType, 0, selectedAbility);
        } else if (vs_main_buttonsPressed & PADRup) {
            _mapAbility(_selectedAbilityType, 1, selectedAbility);
        } else if (vs_main_buttonsPressed & PADRleft) {
            _mapAbility(_selectedAbilityType, 2, selectedAbility);
        }

        vs_battle_getMenuItem(_highlightedAbility + 20)->selected = 0;

        if (vs_main_buttonsPressed & PADRdown) {
            vs_battle_playMenuLeaveSfx();
            vs_main_freeHeapR(D_80104EB4);
            D_80104EB4 = NULL;
            D_800F4EE8.unk0[_selectedAbilityType * 2] = _highlightedAbility;
            D_800F4EE8.unk0[_selectedAbilityType * 2 + 1] = _firstAbility;
            return 1;
        }

        if (vs_main_buttonRepeat & PADLup) {
            if (_abilityCount < 9) {
                if (_highlightedAbility == 0) {
                    _highlightedAbility = _abilityCount - 1;
                } else {
                    --_highlightedAbility;
                }
            } else {
                if (_firstAbility == 0) {
                    if (_highlightedAbility == 0) {
                        if (vs_main_buttonsPressed & PADLup) {
                            _highlightedAbility = 7;
                            _firstAbility = _abilityCount - 8;
                        }
                    } else {
                        --_highlightedAbility;
                    }
                } else {
                    if (_highlightedAbility == 1) {
                        --_firstAbility;
                    } else {
                        --_highlightedAbility;
                    }
                }
            }
        }
        if (vs_main_buttonRepeat & PADLdown) {
            if (_abilityCount < 9) {
                if (_highlightedAbility == (_abilityCount - 1)) {
                    _highlightedAbility = 0;
                } else {
                    ++_highlightedAbility;
                }
            } else {
                if (_firstAbility == (_abilityCount - 8)) {
                    if (_highlightedAbility == 7) {
                        if (vs_main_buttonsPressed & PADLdown) {
                            _highlightedAbility = 0;
                            _firstAbility = 0;
                        }
                    } else {
                        ++_highlightedAbility;
                    }
                } else if (_highlightedAbility == 6) {
                    ++_firstAbility;
                } else {
                    ++_highlightedAbility;
                }
            }
        }
        if (selectedAbility != (_highlightedAbility + _firstAbility)) {
            vs_battle_playMenuChangeSfx();
            if (_firstAbility != temp_s7) {
                char sp18[_abilityCount];

                for (i = 0; i < _abilityCount; ++i) {
                    sp18[i] = 0;
                }

                ability = _abilityCount;
                if (_abilityCount >= 9) {
                    ability = 8;
                }

                for (i = 0; i < ability; ++i) {
                    sp18[i + temp_s7] = vs_battle_getMenuItem(i + 20)->unk4;
                }

                for (i = 0;;) {
                    menuItem = vs_battle_setMenuItem(i + 20, 194, i * 16 + 50, 0x7E, 0,
                        (char*)(D_80104EB4 + ((_firstAbility + i) << 6)));
                    menuItem->unk4 = sp18[i + _firstAbility];
                    if ((i == 0) && (_firstAbility != 0)) {
                        menuItem->unk5 = 1;
                    }
                    ++i;
                    if (i == _abilityCount) {
                        break;
                    } else if (i == 8) {
                        if ((_firstAbility + 8) < _abilityCount) {
                            menuItem->unk5 = 2;
                        }
                        break;
                    }
                }
            }
        }

        vs_battle_getMenuItem(_highlightedAbility + 20)->selected = 1;
        _cursorAnimStep = vs_battle_drawCursor(_cursorAnimStep, _highlightedAbility + 2);

        if (_selectedAbilityType == abilityTypeChain) {
            _setAbilityCost(_unlockedChainAbilities[_highlightedAbility + _firstAbility]);
        } else {
            _setAbilityCost(
                _unlockedDefenseAbilities[_highlightedAbility + _firstAbility]);
        }
        break;
    }
    return 0;
}

static int _chainAbilityMenu(int arg0)
{
    static int state = 0;
    static char _[4] __attribute__((unused)) = { 0 };

    u_short* menuStrings[28];
    int i;
    int count;
    int skill;

    if (arg0 != 0) {
        func_800FA92C(0, 1);
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }
        count = 0;
        for (i = 0; i < 14; ++i) {
            skill = vs_battle_chainAbilityOffsets[i];
            if ((vs_main_skills[skill].flags >> 0xF) & 1) {
                menuStrings[count * 2] = (u_short*)vs_main_skills[skill].name;
                menuStrings[count * 2 + 1] = &_battleAbilityStrings[_battleAbilityStrings
                        [VS_battleAbilities_INDEX_chainAbilityEffect0 + i]];
                _unlockedChainAbilities[count] = skill;
                ++count;
            }
        }
        _initAbilityMenu(count, abilityTypeChain, menuStrings);
        state = 1;
        break;
    case 1:
        if (_abilityMenu() != 0) {
            func_800FA8E0(2);
            return 1;
        }
        break;
    }
    return 0;
}

static int _defenseAbilityMenu(int arg0)
{
    static int state = 0;
    static char _[4] __attribute__((unused)) = { 0 };

    u_short* menuStrings[28];
    int i;
    int row;
    int skill;

    if (arg0 != 0) {
        func_800FA92C(1, 1);
        state = 0;
        return 0;
    }

    switch (state) {
    case 0:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }
        row = 0;
        for (i = 0; i < 14; ++i) {
            skill = vs_battle_defenseAbilityOffsets[i];
            if ((vs_main_skills[skill].flags >> 0xF) & 1) {
                menuStrings[row * 2] = (u_short*)vs_main_skills[skill].name;
                menuStrings[row * 2 + 1] = &_battleAbilityStrings[_battleAbilityStrings
                        [VS_battleAbilities_INDEX_defenseAbilityEffect0 + i]];
                _unlockedDefenseAbilities[row] = skill;
                ++row;
            }
        }
        _initAbilityMenu(row, 0x19, menuStrings);
        state = 1;
        break;
    case 1:
        if (_abilityMenu() != 0) {
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

    pos = (arg0 + 206) | 0x420000;

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

static int func_801038D4(char* state)
{
    enum state {
        none,
        init = 3,
        selectTypeInit,
        selectType,
        chain,
        defense,
        exitToMainMenu,
        exitToBattle
    };

    static char menuAnimating;
    static u_char pointsAnimStep;
    static char _[14] __attribute__((unused));

    char* menuStrings[4];
    int rowTypes[2];
    int temp_s0;
    int val;

    switch (*state) {
    case init:
        menuAnimating = 0;
        pointsAnimStep = 10;
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        func_800FFBC8();

        if (vs_battle_shortcutInvoked != 0) {
            int type = vs_battle_shortcutInvoked - 7;
            vs_battle_setMenuItem(vs_battle_shortcutInvoked + 3, 0x140, 0x22, 0x8C, 8,
                (char*)&_battleAbilityStrings[_battleAbilityStrings[type * 3]])
                ->selected
                = 1;
            if (type == 0) {
                *state = chain;
                _chainAbilityMenu(1);
            } else {
                *state = defense;
                _defenseAbilityMenu(1);
            }
            break;
        }
    // Fallthrough
    case selectTypeInit:
        if (vs_mainmenu_ready() != 0) {
            menuStrings[0]
                = (char*)&_battleAbilityStrings[VS_battleAbilities_OFFSET_chainAbilities];
            menuStrings[1] = (char*)&_battleAbilityStrings
                [VS_battleAbilities_OFFSET_chainAbilitiesDesc];
            rowTypes[0] = 0;
            rowTypes[1] = 0;
            if (vs_battle_abilitiesUnlocked(0) == 0) {
                // BUG: Should be rowTypes, but flow doesn't seem to be used anyway
                menuStrings[0] = (char*)((long)menuStrings[0] | 1);
                menuStrings[1] = (char*)&_battleAbilityStrings
                    [VS_battleAbilities_OFFSET_noChainAbilities];
            }
            menuStrings[2] = (char*)&_battleAbilityStrings
                [VS_battleAbilities_OFFSET_defenseAbilities];
            menuStrings[3] = (char*)&_battleAbilityStrings
                [VS_battleAbilities_OFFSET_defenseAbilitiesDesc];
            if (vs_battle_abilitiesUnlocked(1) == 0) {
                rowTypes[1] |= 1;
                menuStrings[3] = (char*)&_battleAbilityStrings
                    [VS_battleAbilities_OFFSET_noDefenseAbilities];
            }
            val = vs_main_settings.cursorMemory;
            if (*state != 3) {
                vs_main_settings.cursorMemory = 1;
            }
            vs_mainmenu_setMenuRows(2, 0x117, (char**)menuStrings, rowTypes);
            vs_main_settings.cursorMemory = val;
            *state = selectType;
        }
        break;
    case selectType:
        menuAnimating = 1;
        val = vs_mainmenu_getSelectedRow() + 1;
        if (val != 0) {
            menuAnimating = 0;
            if (val == 1) {
                *state = chain;
                _chainAbilityMenu(1);
                break;
            }
            if (val == 2) {
                *state = defense;
                _defenseAbilityMenu(1);
                break;
            }
            func_800FA8E0(0x28);
            if (val != -2) {
                *state = exitToMainMenu;
            } else {
                *state = exitToBattle;
            }
        }
        break;
    case chain:
        if (_chainAbilityMenu(0) != 0) {
            if (vs_battle_shortcutInvoked != 0) {
                func_800FA8E0(0x28);
                *state = exitToBattle;
            } else {
                *state = selectTypeInit;
            }
        }
        break;
    case defense:
        if (_defenseAbilityMenu(0) != 0) {
            if (vs_battle_shortcutInvoked != 0) {
                func_800FA8E0(0x28);
                *state = exitToBattle;
            } else {
                *state = selectTypeInit;
            }
        }
        break;
    case exitToMainMenu:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            *state = none;
            return 1;
        }
        break;
    case exitToBattle:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuState.currentState = 3;
            *state = none;
            return 1;
        }
        break;
    }

    if (menuAnimating != 0) {
        _drawPointsRemaining(vs_battle_rowAnimationSteps[pointsAnimStep]);
        if (pointsAnimStep != 0) {
            --pointsAnimStep;
        }
    } else {
        if (pointsAnimStep < 10) {
            ++pointsAnimStep;
            _drawPointsRemaining(pointsAnimStep << 5);
        }
    }
    return 0;
}
