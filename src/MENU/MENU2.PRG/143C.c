#include "143C.h"
#include "64.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "build/assets/MENU/MENU2.PRG/battleAbilities.h"
#include "build/assets/MENU/MENU2.PRG/battleAbilitiesMenu.h"
#include <memory.h>

static u_short _battleAbilityMenuStrings[] = {
#include "build/assets/MENU/MENU2.PRG/battleAbilitiesMenu.vsString"
};

/**
 * Displays the unlock message.
 *
 * @param init 1 = Display message, 0 = check if information message has been closed.
 * @return
 * - init != 0: 1 if all arts for the current weapon are already unlocked, or if the
 * requirements are not met for the next art, 0 otherwise.
 *
 * - init == 0: 1 if the information message was closed due to user action or
 * timeout, 0 othwerwise.
 */
static int _breakArtUnlocked(int init)
{
    static char messageTimeout;
    static char _[15] __attribute__((unused));

    if (init != 0) {
        int skillId;
        int weaponCategory = vs_battle_characterState->equippedWeaponCategory;
        int weaponCategoryMod = weaponCategory;
        u_char(*new_var)[12] = &vs_main_artsStatus.artsLearned;
        weaponCategoryMod %= 10;
        skillId = (*new_var)[weaponCategoryMod];

        if (skillId == 4) {
            return 1;
        }

        if (vs_main_artsStatus.kills.weaponCategories[weaponCategoryMod]
            < vs_main_artsPointsRequirements[weaponCategoryMod][skillId]) {
            return 1;
        }

        vs_battle_initInformationTextBox(3);

        vs_main_artsStatus.artsLearned[weaponCategoryMod] = skillId + 1;
        skillId = 184 + ((weaponCategory - 1) * 4) + skillId;
        vs_battle_stringContext.strings[0] =
            (char*)&_battleAbilityMenuStrings[_battleAbilityMenuStrings[weaponCategory]];
        vs_battle_stringContext.strings[1] = vs_main_skills[skillId].name;

        vs_mainmenu_setInformationMessage((char*)&_battleAbilityMenuStrings
                [VS_battleAbilitiesMenu_OFFSET_breakArtUnlock]);

        vs_main_skills[skillId].unlocked = 1;
        messageTimeout = 120;

    } else if (vs_battle_textBoxes[7].unk0.done) {
        if ((messageTimeout == 0) || (vs_main_buttonsPressed.pad[0].low != 0)) {
            return 1;
        }
        --messageTimeout;
    }

    return 0;
}

static char _unlockableChainAbilities[] = { 0x18, 0x19, 0x22, 0x25, 0x23, 0x1E, 0x1A,
    0x1B, 0x20, 0x1D, 0x1F };
static char _unlockableDefenseAbilities[] = { 0x2F, 0x30, 0x31, 0x32, 0x29, 0x2A, 0x33,
    0x34, 0x2C, 0x2D, 0x35 };

/**
 * Returns a pointer to the specified ability's description.
 */
static char* _getAbilityDescription(int abilityId)
{
    static char abilityDescLookup[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, VS_battleAbilities_INDEX_chainAbilityEffect2,
        VS_battleAbilities_INDEX_chainAbilityEffect3,
        VS_battleAbilities_INDEX_chainAbilityEffect4,
        VS_battleAbilities_INDEX_chainAbilityEffect5, 0,
        VS_battleAbilities_INDEX_chainAbilityEffect7,
        VS_battleAbilities_INDEX_chainAbilityEffect8,
        VS_battleAbilities_INDEX_chainAbilityEffect9,
        VS_battleAbilities_INDEX_chainAbilityEffect10, 0,
        VS_battleAbilities_INDEX_chainAbilityEffect11,
        VS_battleAbilities_INDEX_chainAbilityEffect12, 0,
        VS_battleAbilities_INDEX_chainAbilityEffect13, 0, 0, 0,
        VS_battleAbilities_INDEX_defenseAbilityEffect1,
        VS_battleAbilities_INDEX_defenseAbilityEffect2, 0,
        VS_battleAbilities_INDEX_defenseAbilityEffect4,
        VS_battleAbilities_INDEX_defenseAbilityEffect5, 0,
        VS_battleAbilities_INDEX_defenseAbilityEffect7,
        VS_battleAbilities_INDEX_defenseAbilityEffect8,
        VS_battleAbilities_INDEX_defenseAbilityEffect9,
        VS_battleAbilities_INDEX_defenseAbilityEffect10,
        VS_battleAbilities_INDEX_defenseAbilityEffect11,
        VS_battleAbilities_INDEX_defenseAbilityEffect12,
        VS_battleAbilities_INDEX_defenseAbilityEffect13 };

    u_char index = abilityDescLookup[abilityId];

    if (abilityDescLookup[abilityId] == 0) {
        return (char*)&_battleAbilityMenuStrings[VS_battleAbilitiesMenu_OFFSET_unknown1];
    }

    return (char*)&_battleAbilityStrings[_battleAbilityStrings[index]];
}

/**
 * Manages and displays the ability unlocked notification.
 *
 * @return - initialize != 0: 1 if all abilities have been unlocked,
 * or the requirements for the next ability have not yet been met.
 *
 * - initialize == 0: 1 if the notification has been displayed
 * and closed, 0 otherwise.
 */
static int _battleAbilityUnlocked(int initialize)
{
    enum state {
        init,
        bothRemaining,
        chainOnly,
        defenseOnly,
        unlockChainAbility,
        unlockDefenseAbility,
        showMessage,
        reinit
    };

    static u_char remainingChainAbilities[16];
    static u_char remainingDefenseAbilities[11];
    static u_char remainingChainAbilityCount;
    static u_char remainingDefenseAbilityCount;
    static char state;
    static char timeout;
    static char menuNotEntered;

    char* menuStrings[4];
    int rowTypes[2];
    char* chainAbilityMenuStrings[22];
    int chainAbilityRowTypes[11];
    char* defenseAbilityMenuStrings[22];
    int defenseAbilityRowTypes[11];
    int rowCount;
    int row;
    int i;
    int abilityState;
    vs_battle_menuItem_t* menuItem;
    int skill;

    if (initialize != 0) {

        i = vs_main_artsStatus.kills.battleAbilitiesUnlocked;

        if ((i == 22)
            || (vs_main_artsStatus.kills.total
                < vs_main_battleAbilitiesPointsRequirements[i])) {
            return 1;
        }

        ++vs_main_artsStatus.kills.battleAbilitiesUnlocked;

        memset(D_800F4EE8.unk34, 0, sizeof D_800F4EE8.unk34);

        remainingChainAbilityCount = 0;

        for (i = 0; i < 11; ++i) {
            int ability = _unlockableChainAbilities[i];
            if (!vs_main_skills[ability].unlocked) {
                remainingChainAbilities[remainingChainAbilityCount++] = ability;
            }
        }

        remainingDefenseAbilityCount = 0;

        for (i = 0; i < 11; ++i) {
            int ability = _unlockableDefenseAbilities[i];
            if (!vs_main_skills[ability].unlocked) {
                remainingDefenseAbilities[remainingDefenseAbilityCount++] = ability;
            }
        }

        menuNotEntered = 3;
        timeout = 120;
        state = init;

        return 0;
    }

    switch (state) {
    case init:
        abilityState = remainingChainAbilityCount != 0;

        if (remainingDefenseAbilityCount != 0) {
            abilityState += 2;
        }

        switch (abilityState) {

            enum abilityState_e {
                abilitiesNone,
                abilitiesChainOnly,
                abilitiesDefenseOnly,
                abilitiesBoth
            };

        case abilitiesNone:
            vs_mainmenu_setInformationMessage((char*)&_battleAbilityMenuStrings
                    [VS_battleAbilitiesMenu_OFFSET_allAbilitiesUnlocked]);
            state = showMessage;
            break;

        case abilitiesChainOnly:
            menuItem = vs_battle_setMenuItem(0, 320, 18, 140, 8,
                (char*)&_battleAbilityMenuStrings
                    [VS_battleAbilitiesMenu_OFFSET_chainAbilities]);
            menuItem->state = 2;
            menuItem->targetX = 180;
            menuItem->selected = 1;
            state = chainOnly;
            break;

        case abilitiesDefenseOnly:
            menuItem = vs_battle_setMenuItem(1, 320, 18, 140, 8,
                (char*)&_battleAbilityMenuStrings
                    [VS_battleAbilitiesMenu_OFFSET_defenseAbilities]);
            menuItem->state = 2;
            menuItem->targetX = 180;
            menuItem->selected = 1;
            state = defenseOnly;
            break;

        case abilitiesBoth:
            i = vs_main_settings.cursorMemory;
            menuStrings[0] = (char*)&_battleAbilityMenuStrings
                [VS_battleAbilitiesMenu_OFFSET_chainAbilities];
            menuStrings[1] =
                (char*)(&_battleAbilityMenuStrings[VS_battleAbilitiesMenu_OFFSET_select]);
            menuStrings[2] =
                (char*)(&_battleAbilityMenuStrings
                            [VS_battleAbilitiesMenu_OFFSET_defenseAbilities]);
            menuStrings[3] = menuStrings[1];
            rowTypes[0] = 0;
            rowTypes[1] = 0;
            vs_main_settings.cursorMemory = 1;

            vs_mainmenu_setMenuRows(2, menuRowInfo(10, 1, 0), menuStrings, rowTypes);

            state = bothRemaining;
            vs_main_settings.cursorMemory = i;

            break;
        }
        break;

    case bothRemaining:
        i = vs_mainmenu_getSelectedRow() + 1;

        if (i != menuSelectionConfirm) {
            if (i < 0) {
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                state = reinit;
            } else {
                vs_mainMenu_flyoutMenuRightAndHoistSelection(i - 1, 0);
                state += i;
            }
        }

        break;

    case chainOnly:
        if (vs_mainmenu_ready() != 0) {

            for (i = 0; i < remainingChainAbilityCount; ++i) {
                chainAbilityMenuStrings[i * 2] =
                    vs_main_skills[remainingChainAbilities[i]].name;
                chainAbilityMenuStrings[i * 2 + 1] =
                    _getAbilityDescription(remainingChainAbilities[i]);
                chainAbilityRowTypes[i] = 0;
            }

            rowCount = 4;

            if (remainingChainAbilityCount == 1) {
                rowCount = 1;
            } else if (remainingChainAbilityCount < 5) {
                rowCount = remainingChainAbilityCount - 1;
            }

            i = vs_main_settings.cursorMemory;

            if (menuNotEntered & 1) {
                --menuNotEntered;
                vs_main_settings.cursorMemory = 1;
            }

            vs_mainmenu_setMenuRows(rowCount, menuRowInfo(11, 1, 1),
                chainAbilityMenuStrings, chainAbilityRowTypes);

            vs_main_settings.cursorMemory = i;
            state = unlockChainAbility;
        }
        break;

    case defenseOnly:
        if (vs_mainmenu_ready() != 0) {

            for (i = 0; i < remainingDefenseAbilityCount; ++i) {
                defenseAbilityMenuStrings[i * 2] =
                    vs_main_skills[remainingDefenseAbilities[i]].name;
                defenseAbilityMenuStrings[i * 2 + 1] =
                    _getAbilityDescription(remainingDefenseAbilities[i]);
                defenseAbilityRowTypes[i] = 0;
            }

            rowCount = 4;

            if (remainingDefenseAbilityCount == 1) {
                rowCount = 1;
            } else if (remainingDefenseAbilityCount < 5) {
                rowCount = remainingDefenseAbilityCount - 1;
            }

            i = vs_main_settings.cursorMemory;

            if (menuNotEntered & 2) {
                menuNotEntered -= 2;
                vs_main_settings.cursorMemory = 1;
            }

            vs_mainmenu_setMenuRows(rowCount, menuRowInfo(12, 1, 1),
                defenseAbilityMenuStrings, defenseAbilityRowTypes);

            vs_main_settings.cursorMemory = i;
            state = unlockDefenseAbility;
        }
        break;

    case unlockChainAbility:
        row = vs_mainmenu_getSelectedRow();
        skill = row + 1;

        if (skill != 0) {

            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

            if (skill < 0) {
                state = reinit;
                break;
            }

            vs_battle_initInformationTextBox(3);

            skill = remainingChainAbilities[row];
            vs_battle_stringContext.strings[1] = vs_main_skills[skill].name;

            vs_mainmenu_setInformationMessage((char*)&_battleAbilityMenuStrings
                    [VS_battleAbilitiesMenu_OFFSET_battleAbilityUnlock]);

            vs_main_skills[skill].unlocked = 1;
            state = showMessage;
        }
        break;

    case unlockDefenseAbility:
        row = vs_mainmenu_getSelectedRow();
        skill = row + 1;

        if (skill != 0) {

            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

            if (skill < 0) {
                state = reinit;
                break;
            }

            vs_battle_initInformationTextBox(3);

            skill = remainingDefenseAbilities[row];
            vs_battle_stringContext.strings[1] = vs_main_skills[skill].name;

            vs_mainmenu_setInformationMessage((char*)&_battleAbilityMenuStrings
                    [VS_battleAbilitiesMenu_OFFSET_battleAbilityUnlock]);

            vs_main_skills[skill].unlocked = 1;
            state = showMessage;
        }
        break;

    case showMessage:
        if (vs_battle_textBoxes[7].unk0.done) {
            if ((timeout == 0) || (vs_main_buttonsPressed.pad[0].low != 0)) {
                return 1;
            }
            --timeout;
        }
        break;

    case reinit:
        if (vs_mainmenu_ready() != 0) {
            state = init;
        }
        break;
    }

    return 0;
}

/**
 * Module entrypoint.
 *
 * @return 1 if the unlock message has been displayed and closed, 0 otherwise.
 */
int vs_menu2_skillUnlock(char* state)
{
    enum state { init, breakArtInit, breakArtUnlock, abilityInit, abilityUnlock, exit };

    switch (*state) {
    case init:
        vs_mainMenu_initTextBox();
        // Fallthrough
    case breakArtInit:
        *state = abilityInit;

        if ((vs_battle_unlockedBreakArt != 0) && (_breakArtUnlocked(1) == 0)) {
            *state = breakArtUnlock;
        }

        break;

    case breakArtUnlock:
        if (_breakArtUnlocked(0) != 0) {
            *state = breakArtInit;
        }
        break;

    case abilityInit:
        *state = exit;

        if ((vs_battle_unlockedBattleAbility != 0) && (_battleAbilityUnlocked(1) == 0)) {
            *state = abilityUnlock;
        }

        break;

    case abilityUnlock:
        if (_battleAbilityUnlocked(0) != 0) {
            *state = abilityInit;
        }

        break;

    case exit:
        if (vs_battle_dismissTextBox(7) == 0) {
            *state = init;
            return 1;
        }
        break;
    }

    return 0;
}
