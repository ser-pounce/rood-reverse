#include "common.h"
#include "64.h"
#include "src/SLUS_010.40/actions.h"
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/memory.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sfx.h"
#include "src/SLUS_010.40/sound.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/BATTLE/BATTLE.PRG/battleUi.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "build/assets/MENU/MENU2.PRG/battleAbilities.h"
#include "scratch.h"
#include "vs_string.h"
#include <libetc.h>

/**
 * Prints the HP cost of an Ability using action data.
 */
static void setRiskCost(int id)
{
    static char stringBuffer[16];

    int i;
    int cost;

    vs_mainmenu_setActionCost(1, "RISK", 8, 0);

    cost = vs_main_actions[id].cost;
    stringBuffer[15] = 0;

    i = 15;

    do {
        --i;
        cost = vs_battle_toBCD(cost);
        stringBuffer[i] = (cost & 0xF) + '0';
        cost >>= 4;
    } while (cost != 0);

    --i;
    stringBuffer[i] = '#';

    vs_mainmenu_setActionCost(0, &stringBuffer[i], 72, 0);
}

u_short battleAbilityStrings[] = {
#include "build/assets/MENU/MENU2.PRG/battleAbilities.vsString"
};
static u_short* abilityText = NULL;
static int highlightedAbility = 0;
static u_int abilityMenuState = 0;
static char selectedAbilityType = 0;
static char menuAbilityCount = 0;
static char firstAbility = 0;

static char unlockedChainAbilities[16];
static char unlockedDefenseAbilities[16];

enum abilityType { abilityTypeChain = 24, abilityTypeDefense };

/**
 * Initializes pagination, costs, and menu strings.
 * Peforms nothing if abilityText has already been initialized.
 *
 * @param menuText Pairs of string pointers for ability names and descriptions
 * @return 0 if nothing to perfom, 1 otherwise.
 */
static int initAbilityMenu(int abilityCount, int abilityType, u_short** menuText)
{
    int abilitiesOverflowCount;
    u_short* text;
    int i = 0;
    int j = 0;

    if (abilityText != NULL) {
        return 0;
    }

    selectedAbilityType = abilityType;

    if (vs_main_settings.cursorMemory != 0) {
        i = D_800F4EE8.cursorMemories[abilityType * 2];
        j = D_800F4EE8.cursorMemories[abilityType * 2 + 1];
    }

    abilitiesOverflowCount = abilityCount - 8;

    if (abilitiesOverflowCount < 0) {

        i += j;
        j = 0;

        if (i >= abilityCount) {
            i = 0;
        }
    } else {
        if (abilitiesOverflowCount < j) {
            if ((i + j) >= abilityCount) {
                i = 0;
                j = 0;
            } else {
                i += j - abilitiesOverflowCount;
                j = abilitiesOverflowCount;
            }
        }

        if ((j > 0) && (i == 0)) {
            i = 1;
            --j;
        }

        if (j < abilitiesOverflowCount) {
            if (i == 7) {
                i = 6;
                ++j;
            }
        }
    }

    highlightedAbility = i;
    firstAbility = j;

    if (abilityType == abilityTypeChain) {
        setRiskCost(unlockedChainAbilities[i + j]);
    } else {
        setRiskCost(unlockedDefenseAbilities[i + j]);
    }

    menuAbilityCount = abilityCount;
    abilityMenuState = 0;

    abilityText = vs_main_allocHeapR(abilityCount * 128);

    for (i = 0; i < abilityCount; ++i) {

        text = menuText[i * 2];

        if (text != NULL) {

            abilityText[i * 64] = vs_char_spacing | 16 << 8;

            for (j = 0; j < 14; ++j) {
                (i * 64 + j + abilityText)[1] = text[j];
            }

            abilityText[i * 64 + 15] = vs_char_terminator << 8 | vs_char_terminator;
        } else {
            abilityText[i * 64] = vs_char_terminator << 8 | vs_char_terminator;
        }

        text = menuText[i * 2 + 1];

        if (text != NULL) {
            abilityText[i * 64 + 16] = vs_char_chunkSize;
            for (j = 0; j < 46; ++j) {
                abilityText[i * 64 + j + 17] = text[j];
            }
            abilityText[i * 64 + 63] = vs_char_terminator << 8 | vs_char_terminator;
        } else {
            abilityText[i * 64 + 16] = vs_char_terminator << 8 | vs_char_terminator;
        }
    }

    return 1;
}

/**
 * Maps the selected ability to the desired joypad button
 */
static void mapAbility(int abilityType, int button, int abilityId)
{
    int i;

    if (abilityType == abilityTypeChain) {

        abilityId = unlockedChainAbilities[abilityId];

        if (vs_main_settings.mappedChainAbilities[button] == abilityId) {
            vs_battle_playMenuLeaveSfx();
            vs_main_settings.mappedChainAbilities[button] = 0;
            return;
        }

        vs_main_playSfxDefault(0x7E, VS_SFX_SET);

        for (i = 0; i < 3; ++i) {
            if (vs_main_settings.mappedChainAbilities[i] == abilityId) {
                vs_main_settings.mappedChainAbilities[i] = 0;
            }
        }

        vs_main_settings.mappedChainAbilities[button] = abilityId;

    } else {

        abilityId = unlockedDefenseAbilities[abilityId];

        if (vs_main_settings.mappedDefenseAbilities[button] == abilityId) {
            vs_battle_playMenuLeaveSfx();
            vs_main_settings.mappedDefenseAbilities[button] = 0;
            return;
        }

        vs_main_playSfxDefault(0x7E, VS_SFX_SET);

        for (i = 0; i < 3; ++i) {
            if (vs_main_settings.mappedDefenseAbilities[i] == abilityId) {
                vs_main_settings.mappedDefenseAbilities[i] = 0;
            }
        }

        vs_main_settings.mappedDefenseAbilities[button] = abilityId;
    }
}

/**
 * Displays and manages the Abilities menu.
 *
 * @return 1 if the user backed out, 0 otherwise
 */
static int abilityMenu(void)
{
    enum state { init, waitReady = 16, abilityMenuCase };

    static int cursorAnimStep = 0;

    int selectedAbility;
    int i;
    int previousFirstAbility;
    int ability;
    vs_battle_menuItem_t* menuItem;
    u_long* scratch = vs_scratch.unk8 + 8;

    if (abilityMenuState < 10) {

        menuItem = vs_battle_setMenuItem(abilityMenuState + 20, 320,
            (abilityMenuState * 16) + 50, 0x7E, 0,
            (char*)&abilityText[(firstAbility + abilityMenuState) * 64]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 194;

        if ((abilityMenuState == init) && (firstAbility != 0)) {
            menuItem->isScrollable = 1;
        }

        if (++abilityMenuState == menuAbilityCount) {
            abilityMenuState = waitReady;
        }

        if (abilityMenuState == 8) {
            if ((firstAbility + 8u) < menuAbilityCount) {
                menuItem->isScrollable = 2;
            }

            abilityMenuState = waitReady;
        }

        return 0;
    }

    vs_battle_getMenuItem(highlightedAbility + 20);
    vs_mainmenu_setInformationMessage(
        (char*)(abilityText + (((highlightedAbility + firstAbility) << 6) + 16)));

    switch (abilityMenuState) {
    case waitReady:
        if (vs_mainmenu_ready() != 0) {
            abilityMenuState = abilityMenuCase;
        }
        break;

    case abilityMenuCase:
        vs_mainMenu_displayActionCost = 0;
        selectedAbility = highlightedAbility + firstAbility;
        previousFirstAbility = firstAbility;

        if (menuAbilityCount < 9) {
            for (i = 0; i < menuAbilityCount; ++i) {
                if (selectedAbilityType == abilityTypeChain) {

                    ability = unlockedChainAbilities[i];

                    if (vs_main_settings.mappedChainAbilities[0] == ability) {
                        vs_mainmenu_renderButton(
                            buttonIdCircle, 199, i * 16 + 48, scratch);
                    }

                    if (vs_main_settings.mappedChainAbilities[1] == ability) {
                        vs_mainmenu_renderButton(
                            buttonIdTriangle, 199, i * 16 + 48, scratch);
                    }

                    if (vs_main_settings.mappedChainAbilities[2] == ability) {
                        vs_mainmenu_renderButton(
                            buttonIdSquare, 199, i * 16 + 48, scratch);
                    }
                } else {

                    ability = unlockedDefenseAbilities[i];

                    if (vs_main_settings.mappedDefenseAbilities[0] == ability) {
                        vs_mainmenu_renderButton(
                            buttonIdCircle, 199, i * 16 + 48, scratch);
                    }

                    if (vs_main_settings.mappedDefenseAbilities[1] == ability) {
                        vs_mainmenu_renderButton(
                            buttonIdTriangle, 199, i * 16 + 48, scratch);
                    }

                    if (vs_main_settings.mappedDefenseAbilities[2] == ability) {
                        vs_mainmenu_renderButton(
                            buttonIdSquare, 199, i * 16 + 48, scratch);
                    }
                }
            }
        } else {
            for (i = 0; i < 8; ++i) {
                if (selectedAbilityType == abilityTypeChain) {

                    ability = unlockedChainAbilities[i + firstAbility];

                    if (vs_main_settings.mappedChainAbilities[0] == ability) {
                        vs_mainmenu_renderButton(
                            buttonIdCircle, 199, i * 16 + 48, scratch);
                    }

                    if (vs_main_settings.mappedChainAbilities[1] == ability) {
                        vs_mainmenu_renderButton(
                            buttonIdTriangle, 199, i * 16 + 48, scratch);
                    }

                    if (vs_main_settings.mappedChainAbilities[2] == ability) {
                        vs_mainmenu_renderButton(
                            buttonIdSquare, 199, i * 16 + 48, scratch);
                    }
                } else {

                    ability = unlockedDefenseAbilities[i + firstAbility];

                    if (vs_main_settings.mappedDefenseAbilities[0] == ability) {
                        vs_mainmenu_renderButton(
                            buttonIdCircle, 199, i * 16 + 48, scratch);
                    }

                    if (vs_main_settings.mappedDefenseAbilities[1] == ability) {
                        vs_mainmenu_renderButton(
                            buttonIdTriangle, 199, i * 16 + 48, scratch);
                    }

                    if (vs_main_settings.mappedDefenseAbilities[2] == ability) {
                        vs_mainmenu_renderButton(
                            buttonIdSquare, 199, i * 16 + 48, scratch);
                    }
                }
            }
        }

        if (vs_main_buttonsPressed.all & PADRright) {
            mapAbility(selectedAbilityType, 0, selectedAbility);
        } else if (vs_main_buttonsPressed.all & PADRup) {
            mapAbility(selectedAbilityType, 1, selectedAbility);
        } else if (vs_main_buttonsPressed.all & PADRleft) {
            mapAbility(selectedAbilityType, 2, selectedAbility);
        }

        vs_battle_getMenuItem(highlightedAbility + 20)->selected = 0;

        if (vs_main_buttonsPressed.all & PADRdown) {

            vs_battle_playMenuLeaveSfx();
            vs_main_freeHeapR(abilityText);

            abilityText = NULL;
            D_800F4EE8.cursorMemories[selectedAbilityType * 2] = highlightedAbility;
            D_800F4EE8.cursorMemories[selectedAbilityType * 2 + 1] = firstAbility;

            return 1;
        }

        if (vs_main_buttonRepeat & PADLup) {
            if (menuAbilityCount < 9) {
                if (highlightedAbility == 0) {
                    highlightedAbility = menuAbilityCount - 1;
                } else {
                    --highlightedAbility;
                }
            } else {
                if (firstAbility == 0) {
                    if (highlightedAbility == 0) {
                        if (vs_main_buttonsPressed.all & PADLup) {
                            highlightedAbility = 7;
                            firstAbility = menuAbilityCount - 8;
                        }
                    } else {
                        --highlightedAbility;
                    }
                } else {
                    if (highlightedAbility == 1) {
                        --firstAbility;
                    } else {
                        --highlightedAbility;
                    }
                }
            }
        }

        if (vs_main_buttonRepeat & PADLdown) {
            if (menuAbilityCount < 9) {
                if (highlightedAbility == (menuAbilityCount - 1)) {
                    highlightedAbility = 0;
                } else {
                    ++highlightedAbility;
                }
            } else {
                if (firstAbility == (menuAbilityCount - 8)) {
                    if (highlightedAbility == 7) {
                        if (vs_main_buttonsPressed.all & PADLdown) {
                            highlightedAbility = 0;
                            firstAbility = 0;
                        }
                    } else {
                        ++highlightedAbility;
                    }
                } else if (highlightedAbility == 6) {
                    ++firstAbility;
                } else {
                    ++highlightedAbility;
                }
            }
        }

        if (selectedAbility != (highlightedAbility + firstAbility)) {
            vs_battle_playMenuChangeSfx();
            if (firstAbility != previousFirstAbility) {
                char abilityBuf[menuAbilityCount];

                for (i = 0; i < menuAbilityCount; ++i) {
                    abilityBuf[i] = 0;
                }

                ability = menuAbilityCount;
                if (menuAbilityCount >= 9) {
                    ability = 8;
                }

                for (i = 0; i < ability; ++i) {
                    abilityBuf[i + previousFirstAbility] =
                        vs_battle_getMenuItem(i + 20)->gradientState;
                }

                for (i = 0;;) {
                    menuItem = vs_battle_setMenuItem(i + 20, 194, i * 16 + 50, 0x7E, 0,
                        (char*)(abilityText + ((firstAbility + i) << 6)));
                    menuItem->gradientState = abilityBuf[i + firstAbility];

                    if ((i == 0) && (firstAbility != 0)) {
                        menuItem->isScrollable = 1;
                    }

                    ++i;

                    if (i == menuAbilityCount) {
                        break;
                    } else if (i == 8) {
                        if ((firstAbility + 8) < menuAbilityCount) {
                            menuItem->isScrollable = 2;
                        }
                        break;
                    }
                }
            }
        }

        vs_battle_getMenuItem(highlightedAbility + 20)->selected = 1;
        cursorAnimStep = vs_battle_drawCursor(cursorAnimStep, highlightedAbility + 2);

        if (selectedAbilityType == abilityTypeChain) {
            setRiskCost(unlockedChainAbilities[highlightedAbility + firstAbility]);
        } else {
            setRiskCost(unlockedDefenseAbilities[highlightedAbility + firstAbility]);
        }

        break;
    }

    return 0;
}

/**
 * Initializes and manages the Chain Abilities menu.
 *
 * @param
 * @return 1 if the user backed out, 0 otherwise.
 */
static int chainAbilityMenu(int initialize)
{
    enum state { init, abilityMenuCase };

    static int state = 0;
    static UNUSED char _[4] = { 0 };

    u_short* menuStrings[28];
    int i;
    int count;

    if (initialize != 0) {
        vs_mainMenu_flyoutMenuRightAndHoistSelection(0, 1);

        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }

        count = 0;

        for (i = 0; i < 14; ++i) {

            int action = vs_battle_chainAbilityOffsets[i];

            if (vs_main_actions[action].unlocked) {
                menuStrings[count * 2] = (u_short*)vs_main_actions[action].name;
                menuStrings[count * 2 + 1] = &battleAbilityStrings[battleAbilityStrings
                        [VS_battleAbilities_INDEX_chainAbilityEffect0 + i]];
                unlockedChainAbilities[count] = action;
                ++count;
            }
        }

        initAbilityMenu(count, abilityTypeChain, menuStrings);

        state = abilityMenuCase;
        break;

    case abilityMenuCase:
        if (abilityMenu() != 0) {
            vs_mainMenu_clearMenuExcept(2);
            return 1;
        }
        break;
    }

    return 0;
}

/**
 * Initializes and manages the Defense Abilities menu.
 *
 * @param
 * @return 1 if the user backed out, 0 otherwise.
 */
static int defenseAbilityMenu(int arg0)
{
    enum state { init, abilityMenuCase };

    static int state = 0;
    static UNUSED char _[4] = { 0 };

    u_short* menuStrings[28];
    int i;
    int row;

    if (arg0 != 0) {
        vs_mainMenu_flyoutMenuRightAndHoistSelection(1, 1);

        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }

        row = 0;

        for (i = 0; i < 14; ++i) {
            int action = vs_battle_defenseAbilityOffsets[i];
            if (vs_main_actions[action].unlocked) {
                menuStrings[row * 2] = (u_short*)vs_main_actions[action].name;
                menuStrings[row * 2 + 1] = &battleAbilityStrings[battleAbilityStrings
                        [VS_battleAbilities_INDEX_defenseAbilityEffect0 + i]];
                unlockedDefenseAbilities[row] = action;
                ++row;
            }
        }

        initAbilityMenu(row, abilityTypeDefense, menuStrings);

        state = abilityMenuCase;
        break;

    case abilityMenuCase:
        if (abilityMenu() != 0) {
            vs_mainMenu_clearMenuExcept(2);
            return 1;
        }

        break;
    }

    return 0;
}

/**
 * Prints kills needed to unlock the next Ability
 *
 * @param row Effectively the count of already unlocked abilities
 */
static void setNextAbilityUnlockPointsRemaining(int row)
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

    pos = (row + 206) | (66 << 16);

    pointsBuf[14] = 'T';
    pointsBuf[15] = 0;
    pointsBuf[13] = 'P';

    i = 12;
    do {
        points = vs_battle_toBCD(points);
        *(pointsBuf + i) = (points & 0xF) + 48;
        points >>= 4;
        --i;
    } while (points != 0);

    pointsStr = pointsBuf + i;
    *pointsStr = '#';

    vs_battle_renderTextRaw("NEXT", pos, 0);
    vs_battle_renderTextRaw(pointsStr, pos + 0x60, 0);
}

/**
 * Module entrypoint.
 *
 * @return Returns 1 if menu is exiting for any reason, 0 otherwise
 */
int vs_menu2_exec(u_char* state)
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
    static UNUSED char _[14];

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

        vs_mainMenu_initInformationBox();

        if (vs_battle_shortcutInvoked != 0) {

            int type = vs_battle_shortcutInvoked - 7;

            vs_battle_setMenuItem(vs_battle_shortcutInvoked + 3, 0x140, 0x22, 0x8C, 8,
                (char*)&battleAbilityStrings[battleAbilityStrings[type * 3]])
                ->selected = 1;

            if (type == 0) {
                *state = chain;
                chainAbilityMenu(1);
            } else {
                *state = defense;
                defenseAbilityMenu(1);
            }

            break;
        }
        // Fallthrough

    case selectTypeInit:
        if (vs_mainmenu_ready() != 0) {

            menuStrings[0] =
                (char*)&battleAbilityStrings[VS_battleAbilities_OFFSET_chainAbilities];
            menuStrings[1] = (char*)&battleAbilityStrings
                [VS_battleAbilities_OFFSET_chainAbilitiesDesc];
            rowTypes[0] = 0;
            rowTypes[1] = 0;

            if (vs_battle_chainAbilitiesUnlocked(0) == 0) {
                // BUG: Should be rowTypes, but flow doesn't seem to be used anyway
                menuStrings[0] = (char*)((long)menuStrings[0] | 1);
                menuStrings[1] = (char*)&battleAbilityStrings
                    [VS_battleAbilities_OFFSET_noChainAbilities];
            }

            menuStrings[2] =
                (char*)&battleAbilityStrings[VS_battleAbilities_OFFSET_defenseAbilities];
            menuStrings[3] = (char*)&battleAbilityStrings
                [VS_battleAbilities_OFFSET_defenseAbilitiesDesc];

            if (vs_battle_chainAbilitiesUnlocked(1) == 0) {
                rowTypes[1] |= 1;
                menuStrings[3] = (char*)&battleAbilityStrings
                    [VS_battleAbilities_OFFSET_noDefenseAbilities];
            }

            val = vs_main_settings.cursorMemory;

            if (*state != 3) {
                vs_main_settings.cursorMemory = 1;
            }

            vs_mainmenu_setMenuRows(2, menuRowInfo(7, 1, 1), menuStrings, rowTypes);

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
                chainAbilityMenu(1);
                break;
            }

            if (val == 2) {
                *state = defense;
                defenseAbilityMenu(1);
                break;
            }

            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

            if (val != -2) {
                *state = exitToMainMenu;
            } else {
                *state = exitToBattle;
            }
        }
        break;

    case chain:
        if (chainAbilityMenu(0) != 0) {
            if (vs_battle_shortcutInvoked != 0) {

                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

                *state = exitToBattle;
            } else {
                *state = selectTypeInit;
            }
        }
        break;

    case defense:
        if (defenseAbilityMenu(0) != 0) {
            if (vs_battle_shortcutInvoked != 0) {

                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

                *state = exitToBattle;
            } else {
                *state = selectTypeInit;
            }
        }
        break;

    case exitToMainMenu:
        vs_mainMenu_dismissInformationBox();
        vs_mainMenu_setMenuCommand(menuActionNone);

        if (vs_mainmenu_ready() != 0) {
            *state = none;
            return 1;
        }

        break;

    case exitToBattle:
        vs_mainMenu_dismissInformationBox();
        vs_mainMenu_setMenuCommand(menuActionNone);

        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuState.currentMenu = 3;
            *state = none;
            return 1;
        }

        break;
    }

    if (menuAnimating != 0) {
        setNextAbilityUnlockPointsRemaining(vs_battle_rowAnimationSteps[pointsAnimStep]);

        if (pointsAnimStep != 0) {
            --pointsAnimStep;
        }
    } else {
        if (pointsAnimStep < 10) {

            ++pointsAnimStep;

            setNextAbilityUnlockPointsRemaining(pointsAnimStep << 5);
        }
    }

    return 0;
}
