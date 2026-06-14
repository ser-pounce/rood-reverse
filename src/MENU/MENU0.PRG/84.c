#include "84.h"
#include "src/SLUS_010.40/main.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "build/assets/MENU/MENU0.PRG/magic.h"
#include "build/assets/MENU/MENU0.PRG/teleportation.h"
#include "gpu.h"
#include <libetc.h>

static signed char _MPCostTextBuffer[16];

/**
 * Prints the MP cost of a spell using skill data.
 * @param id Skill ID. Value can be negated to indicate a variable cost spell.
 */
static void _setMPCost(int id)
{
    int flags;
    int i;
    int cost;
    int variableCost = 0;

    if (id < 0) {
        variableCost = 1;
        id = -id;
    }

    flags = vs_battle_getSkillFlags(0, id);
    vs_mainmenu_setAbilityCost(1, "MP", 8, (flags >> 1) & 1);

    cost = vs_main_skills[id].cost;
    _MPCostTextBuffer[15] = NULL;

    i = 15;

    if (variableCost != 0) {
        i = 13;
        _MPCostTextBuffer[14] = '-';
        _MPCostTextBuffer[13] = '[';
    }

    do {
        cost = vs_battle_toBCD(cost);
        _MPCostTextBuffer[--i] = (cost & 0xF) + '0';
        cost >>= 4;
        if (variableCost != 0) {
            _MPCostTextBuffer[--i] = '[';
        }
    } while (cost != 0);

    _MPCostTextBuffer[--i] = '#';

    vs_mainmenu_setAbilityCost(
        0, &_MPCostTextBuffer[i], variableCost * 4 + 72, (flags >> 1) & 1);
}

static char _MPCostDirectTextBuffer[16];

/**
 * Prints the MP cost of a spell.
 */
void _setMPCostDirect(int costDecimal, int disabled)
{
    int cost;
    int i;

    vs_mainmenu_setAbilityCost(1, "MP", 8, disabled);

    cost = costDecimal;
    i = 15;
    _MPCostDirectTextBuffer[15] = 0;

    do {
        cost = vs_battle_toBCD(cost);
        _MPCostDirectTextBuffer[--i] = (cost & 0xF) + '0';
        cost >>= 4;
    } while (cost != 0);

    _MPCostDirectTextBuffer[--i] = '#';

    vs_mainmenu_setAbilityCost(0, &_MPCostDirectTextBuffer[i], 72, disabled);
}

u_short _magicStrings[] = {
#include "build/assets/MENU/MENU0.PRG/magic.vsString"
};
u_short _teleportationStrings[] = {
#include "build/assets/MENU/MENU0.PRG/teleportation.vsString"
};

/**
 * Encapsulates teleport target information.
 * Bits 0-9: Room ID
 * Bits 10-16: unused
 * Bits 16-21:
 * Bits 21-24: unused
 * Bits 24-29:
 * Bits 29-32: unused
 */
int _savePointData[] = { 0x0305001B, 0x0801000E, 0x04030199, 0x0C0C001C, 0x070C0028,
    0x040200CD, 0x0F070035, 0x08060093, 0x060000CE, 0x09080106, 0x09080111, 0x0C030098,
    0x090800E0, 0x060900C8, 0x050800CA, 0x050F00CC, 0x0109009B, 0x0A07007C, 0x000400CF,
    0x080800EC, 0x020400F1, 0x0705011D, 0x06080120, 0x04080139, 0x04080147, 0x0904014F,
    0x010300A2, 0x150C00A3, 0x030200D0, 0x060600D1, 0x1007008B, 0x010400AB, 0x05020055,
    0x07060063, 0x0A0400D2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000 };

/**
 * Calculates MP cost of teleporting to a save point
 *
 * @param targetSavePointId
 * @return cost
 */
int _getTeleportCost(int targetSavePointId)
{
    int i;
    int j;
    int cost;
    int closestSavePointId;
    int roomId = vs_battle_getCurrentRoomId();

    do {
        for (i = 0; i < 48; ++i) {
            if ((_savePointData[i] & 0xFFFF) == roomId) {
                break;
            }
        }
    } while (0);

    closestSavePointId = i;
    if (targetSavePointId < i) {
        i = targetSavePointId;
        targetSavePointId = closestSavePointId;
    }

    cost = 15;

    for (j = i; j < targetSavePointId; ++j) {
        static char savePointCosts[] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 0 };
        cost += savePointCosts[j];
    }

    return cost;
}

static char _availableWarlockSpells[18];
static u_char D_8010694A;
static char _0[5] __attribute__((unused));

/**
 * Displays and manages Warlock magic menu.
 *
 * @param initShortcutInvoked
 * - 1 = initialize for main menu
 * - 2 = initialize for shortcut
 * - 0 = Process menu
 * @return The selected row, negative if user cancelled, 0 otherwise.
 */
int _warlockMagicMenu(u_int initShortcutInvoked)
{
    enum state { init, handleInput, returnIfReady, levelledSpell };

    extern u_long* D_1F800000[];

    static char levelledSpells[] = { vs_battle_spell_explosion,
        vs_battle_spell_thunderburst, vs_battle_spell_flameSphere,
        vs_battle_spell_gaeaStrike, vs_battle_spell_avalanche,
        vs_battle_spell_radialSurge, vs_battle_spell_meteor };
    static char* spellLevels[] = { "LV1", "LV2", "LV3", "LV4", "--" };

    static u_int state;
    static int selectedRow;
    static int shortcutInvoked;

    int rowCount;
    int i;

    if (initShortcutInvoked) {
        shortcutInvoked = (initShortcutInvoked ^ 2) < 1;
        vs_mainMenu_flyoutMenuRightAndHoistSelection(0, 1);
        state = init;
        return 0;
    }

    switch (state) {
    case init: {
        char* menuStrings[36];
        int rowTypes[18];

        if (!vs_battle_shortcutInvoked && !vs_mainmenu_ready()) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 18; ++i) {
            int skillId = vs_battle_warlockSpellIds[i];
            if (vs_main_skills[skillId].unlocked) {
                menuStrings[rowCount * 2] =
                    (char*)&_magicStrings[_magicStrings[i
                                                        + VS_magic_INDEX_warlockSpells]];
                menuStrings[rowCount * 2 + 1] = (char*)&_magicStrings
                    [_magicStrings[i + VS_magic_INDEX_warlockSpellDescs]];
                rowTypes[rowCount] = 0;
                if (vs_battle_getSkillFlags(0, skillId) != 0) {
                    rowTypes[rowCount] |= 1;
                }
                _availableWarlockSpells[rowCount] = skillId;
                ++rowCount;
            }
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 18; ++i) {
                rowTypes[i] |= 1;
            }
        }
        i = vs_main_settings.cursorMemory;
        if (shortcutInvoked != 0) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(rowCount, 0x207, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        state = handleInput;
        break;
    }
    case handleInput:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            vs_mainMenu_isLevelledSpell = 0;
            if (vs_battle_shortcutInvoked && (selectedRow == -1)) {
                selectedRow = -2;
            }
            if (selectedRow == -1) {
                vs_mainMenu_clearMenuExcept(0);
                state = returnIfReady;
                break;
            }
            if (selectedRow > 0) {
                selectedRow = _availableWarlockSpells[selectedRow - 1];
                for (rowCount = 0; rowCount < 7; ++rowCount) {
                    if ((selectedRow == levelledSpells[rowCount])
                        && (vs_main_skills[selectedRow + 1].unlocked)) {
                        vs_mainMenu_flyoutMenuRightAndHoistSelection(
                            D_800F4EE8.unk0[0xE], 2);
                        vs_mainMenu_isLevelledSpell = 1;
                        state = levelledSpell;
                    }
                }
                if (state == levelledSpell) {
                    break;
                }
            }
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            vs_mainMenu_dismissTextBox();
            vs_mainMenu_setNextMenuAction(menuActionNone);
            state = returnIfReady;
        } else {
            i = _availableWarlockSpells[vs_mainMenu_getConfirmedRow()];
            for (rowCount = 0; rowCount < 7; ++rowCount) {
                if (i == levelledSpells[rowCount]) {
                    if (vs_main_skills[i + 1].unlocked) {
                        i = -i;
                    }
                    break;
                }
            }
            _setMPCost(i);
        }
        break;
    case returnIfReady:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    case levelledSpell:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        i = 2;
        if (vs_main_skills[selectedRow + 2].unlocked) {
            i = 3;
            if (vs_main_skills[selectedRow + 3].unlocked) {
                i = 4;
            }
        }
        D_800F4EE8.unk0[0xD] = i;
        if (D_800F4EE8.unk0[0xC] >= i) {
            D_800F4EE8.unk0[0xC] = i - 1;
        }
        D_8010694A = 0;
        state = 4;
        break;
    case 4: {
        u_long* temp_s6;
        int level;
        int var_s7_2;
        u_long* var_t3;

        i = D_800F4EE8.unk0[0xC];
        rowCount = D_800F4EE8.unk0[0xD];

        if (vs_main_buttonsPressed.all & PADRup) {
            vs_battle_playMenuLeaveSfx();
            vs_mainMenu_isLevelledSpell = 0;
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            vs_mainMenu_dismissTextBox();
            vs_mainMenu_setNextMenuAction(menuActionNone);
            selectedRow = -2;
            state = returnIfReady;
            break;
        }
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_battle_playMenuLeaveSfx();
            for (i = 20; i < 30; ++i) {
                vs_mainMenu_menuItemFlyoutRight(i);
            }
            state = init;
            break;
        } else if (vs_main_buttonsPressed.all & PADRright) {
            if (vs_battle_getSkillFlags(0, selectedRow + i) == 0) {
                vs_battle_playMenuSelectSfx();
                vs_mainMenu_isLevelledSpell = 0;
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissTextBox();
                vs_mainMenu_setNextMenuAction(menuActionNone);
                state = returnIfReady;
                selectedRow += i;
                break;
            } else {
                vs_battle_playInvalidSfx();
            }
        }
        if (vs_main_buttonRepeat & PADLright) {
            if (i < (rowCount - 1)) {
                ++i;
            }
        }
        if (vs_main_buttonRepeat & PADLleft) {
            if (i > 0) {
                --i;
            }
        }
        if (i != D_800F4EE8.unk0[0xC]) {
            vs_battle_playMenuChangeSfx();
            D_800F4EE8.unk0[0xC] = i;
        }

        _setMPCost(selectedRow + i);

        temp_s6 = D_1F800000[1] - 1;

        for (level = 0; level < 4; ++level) {

            var_s7_2 = 0;

            if (i >= level) {
                int v;
                vs_battle_renderTextRaw(
                    spellLevels[level], (99 + level * 32) | vs_getXY(0, 103), NULL);
                var_t3 = vs_battle_setSpriteDefaultTexPage(D_800EC270[D_8010694A],
                    (96 + level * 32) | vs_getXY(0, 100), vs_getWH(32, 16), temp_s6);
                var_t3[4] = 0x37FD70C0;

                v = D_8010694A;
                if (level == i) {
                    ++D_8010694A;
                    D_8010694A &= 0xF;
                } else {
                    D_8010694A = v & 0xF;
                }
            } else if (level < rowCount) {
                vs_battle_renderTextRaw(
                    spellLevels[level], (0x63 + level * 0x20) | 0x670000, NULL);
                var_t3 = vs_battle_setSpriteDefaultTexPage(0x40,
                    (96 + level * 32) | vs_getXY(0, 100), vs_getWH(32, 16), temp_s6);
                var_t3[4] = 0x37FE70C0;
            } else {
                var_s7_2 = 1;
                vs_battle_renderTextRaw(
                    spellLevels[4], (0x66 + level * 0x20) | 0x670000, NULL);
                var_t3 = vs_battle_setSpriteDefaultTexPage(
                    0, (96 + level * 32) | vs_getXY(0, 100), vs_getWH(32, 16), temp_s6);
                var_t3[1] = 0x64602000;
                var_t3[4] = 0x37FE70C0;
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
        var_t3 = vs_battle_setSpriteDefaultTexPage(
            128, vs_getXY(80, 100), vs_getWH(16, 16), temp_s6);
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

static char _availableShamanSpells[6];
static char _1[2];

/**
 * Displays and manages Shaman magic menu.
 *
 * @param initShortcutInvoked
 * - 1 = initialize for main menu
 * - 2 = initialize for shortcut
 * - 0 = Process menu
 * @return The selected row, -1 if user cancelled, 0 otherwise
 */
int _shamanMagicMenu(u_int initShortcutInvoked)
{
    enum state { init, handleInput, returnIfReady };

    static int state;
    static int selectedRow;
    static int shortcutInvoked;

    char* menuStrings[12];
    int rowTypes[6];
    int i;
    int rowCount;
    int skillId;

    if (initShortcutInvoked != 0) {
        shortcutInvoked = (initShortcutInvoked ^ 2) < 1;
        vs_mainMenu_flyoutMenuRightAndHoistSelection(1, 1);
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }

        rowCount = 0;
        for (i = 0; i < 6; ++i) {
            skillId = vs_battle_shamanSpellIds[i];
            if (!vs_main_skills[skillId].unlocked) {
                continue;
            }
            menuStrings[rowCount * 2] = vs_main_skills[skillId].name;
            menuStrings[rowCount * 2 + 1] =
                (char*)&_magicStrings[_magicStrings[i + VS_magic_INDEX_shamanSpellDescs]];
            rowTypes[rowCount] = 0;
            if (vs_battle_getSkillFlags(0, skillId) != 0) {
                rowTypes[rowCount] |= 1;
            }
            _availableShamanSpells[rowCount] = skillId;
            ++rowCount;
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 6; ++i) {
                rowTypes[i] |= 1;
            }
        }

        i = vs_main_settings.cursorMemory;
        if (shortcutInvoked != 0) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(rowCount, 0x208, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        state = handleInput;
        break;
    case handleInput:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            vs_mainMenu_isLevelledSpell = 0;
            if ((vs_battle_shortcutInvoked != 0) && (selectedRow == -1)) {
                selectedRow = -2;
            }
            if (selectedRow == -1) {
                vs_mainMenu_clearMenuExcept(0);
            } else {
                if (selectedRow > 0) {
                    selectedRow = _availableShamanSpells[selectedRow - 1];
                }
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissTextBox();
                vs_mainMenu_setNextMenuAction(menuActionNone);
            }
            state = returnIfReady;
        } else {
            _setMPCost(_availableShamanSpells[vs_mainMenu_getConfirmedRow()]);
        }
        break;
    case returnIfReady:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

static char _availableSorcererSpells[18];
static char _3[6];

/**
 * Displays and manages Sorcerer magic menu.
 *
 * @param initShortcutInvoked
 * - 1 = initialize for main menu
 * - 2 = initialize for shortcut
 * - 0 = Process menu
 * @return The selected row, -1 if user cancelled, 0 otherwise
 */
int _sorcererMagicMenu(u_int initShortcutInvoked)
{
    enum state { init, handleInput, returnIfready };

    static int state;
    static int selectedRow;
    static int shortcutInvoked;

    char* menuStrings[36];
    int rowTypes[18];
    int i;
    int rowCount;
    int skillId;

    if (initShortcutInvoked != 0) {
        shortcutInvoked = (initShortcutInvoked ^ 2) < 1;
        vs_mainMenu_flyoutMenuRightAndHoistSelection(2, 1);
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if (!vs_battle_shortcutInvoked && !vs_mainmenu_ready()) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 18; ++i) {
            skillId = vs_battle_sorcererSpellIds[i];
            if (!vs_main_skills[skillId].unlocked) {
                continue;
            }
            menuStrings[rowCount * 2] = vs_main_skills[skillId].name;
            menuStrings[rowCount * 2 + 1] =
                (char*)&_magicStrings[_magicStrings[i
                                                    + VS_magic_INDEX_sorcererSpellDescs]];
            rowTypes[rowCount] = 0;
            if (vs_battle_getSkillFlags(0, skillId) != 0) {
                rowTypes[rowCount] |= 1;
            }
            _availableSorcererSpells[rowCount] = skillId;
            ++rowCount;
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 18; ++i) {
                rowTypes[i] |= 1;
            }
        }

        i = vs_main_settings.cursorMemory;
        if (shortcutInvoked != 0) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(rowCount, 0x209, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        state = handleInput;
        break;
    case handleInput:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            vs_mainMenu_isLevelledSpell = 0;
            if (vs_battle_shortcutInvoked && (selectedRow == -1)) {
                selectedRow = -2;
            }
            if (selectedRow == -1) {
                vs_mainMenu_clearMenuExcept(0);
            } else {
                if (selectedRow > 0) {
                    selectedRow = _availableSorcererSpells[selectedRow - 1];
                }
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissTextBox();
                vs_mainMenu_setNextMenuAction(menuActionNone);
            }
            state = returnIfready;
        } else {
            _setMPCost(_availableSorcererSpells[vs_mainMenu_getConfirmedRow()]);
        }
        break;
    case returnIfready:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

static char _availableEnchanterSpells[8];

/**
 * Displays and manages Enchanter magic menu.
 *
 * @param initShortcutInvoked
 * - 1 = initialize for main menu
 * - 2 = initialize for shortcut
 * - 0 = Process menu
 * @return The selected row, -1 if user cancelled, 0 otherwise
 */
int _enchanterMagicMenu(u_int initShortcutInvoked)
{
    enum state { init, handleInput, returnIfready };
    static int state;
    static int selectedRow;
    static int shortcutInvoked;

    char* menuStrings[16];
    int rowTypes[8];
    int i;
    int rowCount;
    int skillId;

    if (initShortcutInvoked != 0) {
        shortcutInvoked = (initShortcutInvoked ^ 2) < 1;
        vs_mainMenu_flyoutMenuRightAndHoistSelection(3, 1);
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        if ((vs_battle_shortcutInvoked == 0) && (vs_mainmenu_ready() == 0)) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 8; ++i) {
            skillId = vs_battle_enchanterSpellIds[i];
            if (!vs_main_skills[skillId].unlocked) {
                continue;
            }
            menuStrings[rowCount * 2] = vs_main_skills[skillId].name;
            menuStrings[rowCount * 2 + 1] = (char*)&_magicStrings
                [_magicStrings[i + VS_magic_INDEX_enchanterSpellDescs]];
            rowTypes[rowCount] = 0;
            if (vs_battle_getSkillFlags(0, skillId) != 0) {
                rowTypes[rowCount] |= 1;
            }
            _availableEnchanterSpells[rowCount] = skillId;
            ++rowCount;
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 8; ++i) {
                rowTypes[i] |= 1;
            }
        }

        i = vs_main_settings.cursorMemory;
        if (shortcutInvoked != 0) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(rowCount, 0x20A, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = i;
        state = handleInput;
        break;
    case handleInput:
        selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (selectedRow != 0) {
            vs_mainMenu_isLevelledSpell = 0;
            if ((vs_battle_shortcutInvoked != 0) && (selectedRow == -1)) {
                selectedRow = -2;
            }
            if (selectedRow == -1) {
                vs_mainMenu_clearMenuExcept(0);
            } else {
                if (selectedRow > 0) {
                    selectedRow = _availableEnchanterSpells[selectedRow - 1];
                }
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                vs_mainMenu_dismissTextBox();
                vs_mainMenu_setNextMenuAction(menuActionNone);
            }
            state = returnIfready;
        } else {
            _setMPCost(_availableEnchanterSpells[vs_mainMenu_getConfirmedRow()]);
        }
        break;
    case returnIfready:
        if (vs_mainmenu_ready() != 0) {
            return selectedRow;
        }
        break;
    }
    return 0;
}

static const int _ = 0 __attribute__((unused));
