#include "common.h"
#include "../../build/assets/MENU/MENU0.PRG/base.h"
#include "../../build/assets/MENU/MENU0.PRG/teleportation.h"
#include "../../build/assets/BATTLE/BATTLE.PRG/menuStrings.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../SLUS_010.40/main.h"
#include <libetc.h>

static signed char _MPCostTextBuffer[16];

static void _setMPCost(int id)
{
    int flags;
    int i;
    int cost;
    int var_s2 = 0;

    if (id < 0) {
        var_s2 = 1;
        id = -id;
    }

    flags = vs_battle_getSkillFlags(0, id);
    vs_mainmenu_setAbilityCost(1, "MP", 8, (flags >> 1) & 1);
    cost = vs_main_skills[id].cost;
    _MPCostTextBuffer[15] = NULL;

    i = 15;

    if (var_s2 != 0) {
        i = 13;
        _MPCostTextBuffer[14] = '-';
        _MPCostTextBuffer[13] = '[';
    }

    do {
        cost = vs_battle_toBCD(cost);
        _MPCostTextBuffer[--i] = (cost & 0xF) + '0';
        cost >>= 4;
        if (var_s2 != 0) {
            _MPCostTextBuffer[--i] = '[';
        }
    } while (cost != 0);

    _MPCostTextBuffer[--i] = '#';
    vs_mainmenu_setAbilityCost(
        0, &_MPCostTextBuffer[i], var_s2 * 4 + 72, (flags >> 1) & 1);
}

static char _MPCostDirectTextBuffer[16];

static void _setMPCostDirect(int costDecimal, int arg1)
{
    int cost;
    int i;

    vs_mainmenu_setAbilityCost(1, "MP", 8, arg1);
    cost = costDecimal;
    i = 15;
    _MPCostDirectTextBuffer[15] = 0;

    do {
        cost = vs_battle_toBCD(cost);
        _MPCostDirectTextBuffer[--i] = (cost & 0xF) + '0';
        cost >>= 4;
    } while (cost != 0);

    _MPCostDirectTextBuffer[--i] = '#';
    vs_mainmenu_setAbilityCost(0, &_MPCostDirectTextBuffer[i], 72, arg1);
}

static u_short _baseStrings[] = {
#include "../../build/assets/MENU/MENU0.PRG/base.vsString"
};
static u_short _teleportationStrings[] = {
#include "../../build/assets/MENU/MENU0.PRG/teleportation.vsString"
};

static int _savePointData[] = { 0x0305001B, 0x0801000E, 0x04030199, 0x0C0C001C,
    0x070C0028, 0x040200CD, 0x0F070035, 0x08060093, 0x060000CE, 0x09080106, 0x09080111,
    0x0C030098, 0x090800E0, 0x060900C8, 0x050800CA, 0x050F00CC, 0x0109009B, 0x0A07007C,
    0x000400CF, 0x080800EC, 0x020400F1, 0x0705011D, 0x06080120, 0x04080139, 0x04080147,
    0x0904014F, 0x010300A2, 0x150C00A3, 0x030200D0, 0x060600D1, 0x1007008B, 0x010400AB,
    0x05020055, 0x07060063, 0x0A0400D2, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000 };

static int _getTeleportCost(int targetSavePointId)
{
    int i;
    int j;
    int cost;
    int closestSavePointId;
    int closestSavePoint = vs_battle_getClosestSavePoint();

    do {
        for (i = 0; i < 48; ++i) {
            if ((_savePointData[i] & 0xFFFF) == closestSavePoint) {
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
        static char savePointCosts[]
            = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0 };
        cost += savePointCosts[j];
    }
    return cost;
}

static char _availableWarlockSpells[18];
static u_char D_8010694A;
static char _0[5];

static int _warlockMagicMenu(u_int initCursorMemory)
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

    if (initCursorMemory) {
        shortcutInvoked = (initCursorMemory ^ 2) < 1;
        func_800FA92C(0, 1);
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
            if ((vs_main_skills[skillId].flags >> 0xF) & 1) {
                menuStrings[rowCount * 2]
                    = (char*)&_baseStrings[_baseStrings[i + VS_base_INDEX_warlockSpells]];
                menuStrings[rowCount * 2 + 1] = (char*)&_baseStrings[_baseStrings[i
                    + VS_base_INDEX_warlockSpellDescs]];
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
                func_800FA8E0(0);
                state = returnIfReady;
                break;
            }
            if (selectedRow > 0) {
                selectedRow = _availableWarlockSpells[selectedRow - 1];
                for (rowCount = 0; rowCount < 7; ++rowCount) {
                    if ((selectedRow == levelledSpells[rowCount])
                        && ((vs_main_skills[selectedRow + 1].flags >> 0xF) & 1)) {
                        func_800FA92C(D_800F4EE8.unk0[0xE], 2);
                        vs_mainMenu_isLevelledSpell = 1;
                        state = levelledSpell;
                    }
                }
                if (state == levelledSpell) {
                    break;
                }
            }
            func_800FA8E0(0x28);
            func_800FFBA8();
            func_800FFA88(0);
            state = returnIfReady;
        } else {
            i = _availableWarlockSpells[func_801008B0()];
            for (rowCount = 0; rowCount < 7; ++rowCount) {
                if (i == levelledSpells[rowCount]) {
                    if ((vs_main_skills[i + 1].flags >> 0xF) & 1) {
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
        if ((vs_main_skills[selectedRow + 2].flags >> 0xF) & 1) {
            i = 3;
            if ((vs_main_skills[selectedRow + 3].flags >> 0xF) & 1) {
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
        u_int* temp_s6;
        int level;
        int var_s7_2;
        int* var_t3;

        i = D_800F4EE8.unk0[0xC];
        rowCount = D_800F4EE8.unk0[0xD];

        if (vs_main_buttonsPressed.all & PADRup) {
            vs_battle_playMenuLeaveSfx();
            vs_mainMenu_isLevelledSpell = 0;
            func_800FA8E0(0x28);
            func_800FFBA8();
            func_800FFA88(0);
            selectedRow = -2;
            state = returnIfReady;
            break;
        }
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_battle_playMenuLeaveSfx();
            for (i = 20; i < 30; ++i) {
                func_800FA8A0(i);
            }
            state = init;
            break;
        } else if (vs_main_buttonsPressed.all & PADRright) {
            if (vs_battle_getSkillFlags(0, selectedRow + i) == 0) {
                vs_battle_playMenuSelectSfx();
                vs_mainMenu_isLevelledSpell = 0;
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
                state = returnIfReady;
                selectedRow += i;
                break;
            } else {
                func_800C02E0();
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

        temp_s6 = (u_int*)D_1F800000[1] - 1;

        for (level = 0; level < 4; ++level) {
            var_s7_2 = 0;
            if (i >= level) {
                int v;
                vs_battle_renderTextRaw(
                    spellLevels[level], (0x63 + level * 0x20) | 0x670000, 0);
                var_t3 = func_800C0224(D_800EC270[D_8010694A],
                    (0x60 + level * 0x20) | 0x640000, 0x100020, temp_s6);
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
                    spellLevels[level], (0x63 + level * 0x20) | 0x670000, 0);
                var_t3 = func_800C0224(
                    0x40, (0x60 + level * 0x20) | 0x640000, 0x100020, temp_s6);
                var_t3[4] = 0x37FE70C0;
            } else {
                var_s7_2 = 1;
                vs_battle_renderTextRaw(
                    spellLevels[4], (0x66 + level * 0x20) | 0x670000, 0);
                var_t3 = func_800C0224(
                    0, (0x60 + level * 0x20) | 0x640000, 0x100020, temp_s6);
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
        var_t3 = func_800C0224(0x80, 0x640050, 0x100010, temp_s6);
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

static int _shamanMagicMenu(u_int initCursorMemory)
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

    if (initCursorMemory != 0) {
        shortcutInvoked = (initCursorMemory ^ 2) < 1;
        func_800FA92C(1, 1);
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
            if (!((vs_main_skills[skillId].flags >> 0xF) & 1)) {
                continue;
            }
            menuStrings[rowCount * 2] = vs_main_skills[skillId].name;
            menuStrings[rowCount * 2 + 1]
                = (char*)&_baseStrings[_baseStrings[i + VS_base_INDEX_shamanSpellDescs]];
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
                func_800FA8E0(0);
            } else {
                if (selectedRow > 0) {
                    selectedRow = _availableShamanSpells[selectedRow - 1];
                }
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            }
            state = returnIfReady;
        } else {
            _setMPCost(_availableShamanSpells[func_801008B0()]);
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

static char _availableSorcereSpells[18];
static char _3[6];

static int _sorcererMagicMenu(u_int initCursorMemory)
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

    if (initCursorMemory != 0) {
        shortcutInvoked = (initCursorMemory ^ 2) < 1;
        func_800FA92C(2, 1);
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
            if (!((vs_main_skills[skillId].flags >> 0xF) & 1)) {
                continue;
            }
            menuStrings[rowCount * 2] = vs_main_skills[skillId].name;
            menuStrings[rowCount * 2 + 1] = (char*)&_baseStrings[_baseStrings[i
                + VS_base_INDEX_sorcererSpellDescs]];
            rowTypes[rowCount] = 0;
            if (vs_battle_getSkillFlags(0, skillId) != 0) {
                rowTypes[rowCount] |= 1;
            }
            _availableSorcereSpells[rowCount] = skillId;
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
                func_800FA8E0(0);
            } else {
                if (selectedRow > 0) {
                    selectedRow = _availableSorcereSpells[selectedRow - 1];
                }
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            }
            state = returnIfready;
        } else {
            _setMPCost(_availableSorcereSpells[func_801008B0()]);
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

static int _enchanterMagicMenu(u_int initCursorMemory)
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

    if (initCursorMemory != 0) {
        shortcutInvoked = (initCursorMemory ^ 2) < 1;
        func_800FA92C(3, 1);
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
            if (!((vs_main_skills[skillId].flags >> 0xF) & 1)) {
                continue;
            }
            menuStrings[rowCount * 2] = vs_main_skills[skillId].name;
            menuStrings[rowCount * 2 + 1] = (char*)&_baseStrings[_baseStrings[i
                + VS_base_INDEX_enchanterSpellDescs]];
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
                func_800FA8E0(0);
            } else {
                if (selectedRow > 0) {
                    selectedRow = _availableEnchanterSpells[selectedRow - 1];
                }
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            }
            state = returnIfready;
        } else {
            _setMPCost(_availableEnchanterSpells[func_801008B0()]);
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

static u_char _availableSavePoints[48];
static u_short _teleportCosts[48];
static int _selectedRow;
static int _currentMp;
static char _state;

static int _teleportMenu(int init)
{
    enum state { initTeleport, handleInput, returnIfReady };

    char* menuStrings[96];
    int rowTypes[48];
    int nearestSavePoint;
    int i;
    int rowCount;
    int savePointState;

    if (init != 0) {
        func_800FA92C(4, 1);
        _state = initTeleport;
        _currentMp = vs_battle_characterState->unk3C->currentMp;
        return 0;
    }
    switch (_state) {
    case initTeleport:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        rowCount = 0;
        for (i = 0; i < 48; ++i) {
            savePointState = vs_main_stateFlags.savePointStates[i];
            if (savePointState == 0) {
                continue;
            }
            menuStrings[2 * rowCount]
                = (char*)(&_teleportationStrings[_teleportationStrings[i * 2
                    + VS_teleportation_INDEX_locations]]);
            menuStrings[(rowCount * 2) + 1]
                = (char*)(&_teleportationStrings[_teleportationStrings[i * 2
                    + VS_teleportation_INDEX_locations + 1]]);
            _teleportCosts[rowCount] = _getTeleportCost(i);
            rowTypes[rowCount]
                = (savePointState == 2) | (_currentMp < _teleportCosts[rowCount]);
            if (_teleportCosts[rowCount] == 15) {
                rowTypes[rowCount] |= 4;
                nearestSavePoint = rowCount;
            }
            if (savePointState == 2) {
                menuStrings[(rowCount * 2) + 1] = (char*)(_teleportationStrings
                    + VS_teleportation_OFFSET_teleportationDisabled);
            }
            _availableSavePoints[rowCount] = i;
            ++rowCount;
        }

        if (D_800F4EA0 & 0xB7) {
            for (i = 0; i < 48; ++i) {
                rowTypes[i] |= 1;
            }
        }
        if ((rowCount < 9) || (nearestSavePoint < 8)) {
            D_800F4EE8.unk0[0x16] = nearestSavePoint;
            D_800F4EE8.unk0[0x17] = 0;
        } else if (nearestSavePoint >= (rowCount - 7)) {
            D_800F4EE8.unk0[0x16] = nearestSavePoint - (rowCount - 8);
            D_800F4EE8.unk0[0x17] = rowCount - 8;
        } else {
            D_800F4EE8.unk0[0x16] = 3;
            D_800F4EE8.unk0[0x17] = nearestSavePoint - 3;
        }
        savePointState = vs_main_settings.cursorMemory;
        vs_main_settings.cursorMemory = 1;
        vs_mainmenu_setMenuRows(rowCount, 0x20B, menuStrings, rowTypes);
        _state = handleInput;
        vs_main_settings.cursorMemory = savePointState;
        break;

    case handleInput:
        _selectedRow = vs_mainmenu_getSelectedRow() + 1;
        if (_selectedRow != 0) {
            vs_mainMenu_isLevelledSpell = 0;
            if (_selectedRow == (-1)) {
                func_800FA8E0(0);
            } else {
                func_800FA8E0(0x28);
                func_800FFBA8();
                func_800FFA88(0);
            }
            _state = returnIfReady;
        } else {
            i = _teleportCosts[func_801008B0()];
            _setMPCostDirect(i, _currentMp < i);
        }
        break;

    case returnIfReady:
        if (vs_mainmenu_ready() != 0) {
            if (_selectedRow > 0) {
                int v1;
                int v0;
                int a0;
                int a2 = _availableSavePoints[_selectedRow - 1];
                i = _savePointData[a2] + 1;
                v1 = i & 0x1FF;
                init = ~0x3E00;
                v0 = (rowCount & ~0x1FF) | v1;
                v1 = (i >> 7) & 0x3E00;
                v0 &= init;
                v0 |= v1;
                a0 = (i >> 0x18) & 0x1F;
                a0 <<= 0xE;
                v1 = _teleportCosts[_selectedRow - 1] << 0x13;
                v0 &= 0x3FFF;
                return v0 | a0 | v1;
            }
            return _selectedRow;
        }
        break;
    }
    return 0;
}

static void _drawMagicMenuHeader()
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_setMenuItem(0, 320, 18, 0x8C, 8,
        (char*)&vs_battle_menuStrings[vs_battle_menuStrings[VS_menuStrings_INDEX_magic]]);
    menuItem->state = 2;
    menuItem->x = 180;
    menuItem->selected = 1;
    func_800FFA88(2);
    func_800FFBC8();
}

int vs_menu0_exec(char* state)
{
    enum state {
        none,
        handleShortcut = 3,
        initSubmenu,
        handleSubmenu,
        initWarlockMenu,
        handleWarlockSelection,
        initShamanMenu,
        handleShamanSelection,
        initSorcererMenu,
        handleSorcererSelection,
        initEnchanterMenu,
        handleEnchanterSelection,
        handleTeleportSelection,
        exitToMainMenu,
        executeArt,
        exit
    };
    char* menuStrings[10];
    int rowTypes[5];
    int selectedRow;
    int j;
    int i;

    switch (*state) {
    case handleShortcut:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_800FFBC8();
        i = vs_battle_shortcutInvoked;
        if (i != 0) {
            enum shortcutMagicMenu { warlock = 1, shaman, sorcerer, enchanter };
            vs_battle_setMenuItem(i + 9, 0x140, 0x22, 0x8C, 8,
                (char*)&_baseStrings[_baseStrings[(i * 3) - 3]])
                ->selected
                = 1;
            switch (i) {
            case warlock:
                *state = handleWarlockSelection;
                _warlockMagicMenu(1);
                break;
            case shaman:
                *state = handleShamanSelection;
                _shamanMagicMenu(1);
                break;
            case sorcerer:
                *state = handleSorcererSelection;
                _sorcererMagicMenu(1);
                break;
            case enchanter:
                *state = handleEnchanterSelection;
                _enchanterMagicMenu(1);
                break;
            }
            break;
        }
        // Fallthrough
    case initSubmenu:
        for (i = 0; i < 4; ++i) {
            menuStrings[i * 2]
                = (char*)&_baseStrings[_baseStrings[i * 3 + VS_base_INDEX_warlock]];
            menuStrings[i * 2 + 1]
                = (char*)&_baseStrings[_baseStrings[i * 3 + VS_base_INDEX_warlockDesc]];
            rowTypes[i] = 0;
            if (func_800CAEAC(i) == 0) {
                rowTypes[i] |= 1;
                menuStrings[i * 2 + 1] = (char*)&_baseStrings[_baseStrings[i * 3
                    + VS_base_INDEX_warlockLocked]];
            }
        }

        if (vs_main_stateFlags.unkB5 != 0) {
            for (j = 0; j < 48; ++j) {
                if (vs_main_stateFlags.savePointStates[j] != 0) {
                    break;
                }
            }

            menuStrings[i * 2]
                = (char*)(_teleportationStrings + VS_teleportation_OFFSET_teleportation);

            menuStrings[i * 2 + 1]
                = (func_8008A4FC() != 0) && (vs_main_stateFlags.unkB5 == 2)
                ? (char*)(_teleportationStrings
                      + VS_teleportation_OFFSET_teleportationDisabled)
                : (char*)(_teleportationStrings
                      + VS_teleportation_OFFSET_teleportationDesc);

            if ((func_8008A4FC() != 0) && (vs_main_stateFlags.unkB5 == 2)) {
                menuStrings[i * 2 + 1] = (char*)(_teleportationStrings
                    + VS_teleportation_OFFSET_teleportationDisabled);
            }

            rowTypes[i++] = ((j == 48) || (vs_main_stateFlags.unkB5 == 2)
                || (func_8008A4FC() == 0));
        }

        j = vs_main_settings.cursorMemory;
        if (*state != handleShortcut) {
            vs_main_settings.cursorMemory = 1;
        }
        vs_mainmenu_setMenuRows(i, 0x105, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = j;
        *state = handleSubmenu;
        break;
    case handleSubmenu:
        selectedRow = vs_mainmenu_getSelectedRow();
        i = selectedRow + 1;
        if (i == 0) {
            break;
        }
        if (i > 0) {
            enum magicSubMenu { warlock, shaman, sorcerer, enchanter, teleport };
            switch (selectedRow) {
            case warlock:
                *state = handleWarlockSelection;
                _warlockMagicMenu(1);
                break;
            case shaman:
                *state = handleShamanSelection;
                _shamanMagicMenu(1);
                break;
            case sorcerer:
                *state = handleSorcererSelection;
                _sorcererMagicMenu(1);
                break;
            case enchanter:
                *state = handleEnchanterSelection;
                _enchanterMagicMenu(1);
                break;
            case teleport:
                *state = handleTeleportSelection;
                _teleportMenu(1);
                break;
            }
        } else {
            if (i == -2) {
                func_800FA8E0(0x28);
                *state = exit;
            } else {
                func_800FA8E0(0x28);
                *state = exitToMainMenu;
            }
        }
        break;
    case initWarlockMenu:
        _drawMagicMenuHeader();
        vs_battle_setMenuItem(
            0xA, 0x140, 0x22, 0x7E, 8, (char*)(_baseStrings + VS_base_OFFSET_warlock))
            ->selected
            = 1;
        _warlockMagicMenu(2);
        *state = handleWarlockSelection;
        break;
    case handleWarlockSelection:
        i = _warlockMagicMenu(0);
        if (i == 0) {
            break;
        }
        if (i > 0) {
            D_800F4E98.executeAbility = i;
            vs_battle_executeAbilityType = 6;
            *state = executeArt;
        } else {
            if (i == -2) {
                *state = exit;
            } else {
                *state = initSubmenu;
            }
        }
        break;
    case initShamanMenu:
        _drawMagicMenuHeader();
        vs_battle_setMenuItem(
            11, 320, 34, 0x7E, 8, (char*)(_baseStrings + VS_base_OFFSET_shaman))
            ->selected
            = 1;
        _shamanMagicMenu(2);
        *state = handleShamanSelection;
        break;
    case handleShamanSelection:
        i = _shamanMagicMenu(0);
        if (i == 0) {
            break;
        }
        if (i > 0) {
            D_800F4E98.executeAbility = i;
            vs_battle_executeAbilityType = 8;
            *state = executeArt;
        } else {
            if (i == -2) {
                *state = exit;
            } else {
                *state = initSubmenu;
            }
        }
        break;
    case initSorcererMenu:
        _drawMagicMenuHeader();
        vs_battle_setMenuItem(
            12, 320, 34, 0x7E, 8, (char*)(_baseStrings + VS_base_OFFSET_sorcerer))
            ->selected
            = 1;
        _sorcererMagicMenu(2);
        *state = handleSorcererSelection;
        break;
    case handleSorcererSelection:
        i = _sorcererMagicMenu(0);
        if (i == 0) {
            break;
        }
        if (i > 0) {
            D_800F4E98.executeAbility = i;
            vs_battle_executeAbilityType = 10;
            *state = executeArt;
        } else {
            if (i == -2) {
                *state = exit;
            } else {
                *state = initSubmenu;
            }
        }
        break;
    case initEnchanterMenu:
        _drawMagicMenuHeader();
        vs_battle_setMenuItem(
            13, 320, 34, 0x7E, 8, (char*)(_baseStrings + VS_base_OFFSET_enchanter))
            ->selected
            = 1;
        _enchanterMagicMenu(2);
        *state = handleEnchanterSelection;
        break;
    case handleEnchanterSelection:
        i = _enchanterMagicMenu(0);
        if (i == 0) {
            break;
        }
        if (i > 0) {
            D_800F4E98.executeAbility = i;
            vs_battle_executeAbilityType = 12;
            *state = executeArt;
        } else {
            if (i == -2) {
                *state = exit;
            } else {
                *state = initSubmenu;
            }
        }
        break;
    case handleTeleportSelection:
        i = _teleportMenu(0);
        if (i == 0) {
            break;
        }
        if (i > 0) {
            D_800F4E98.unk2 = 0xA;
            D_800F4E98.executeAbility = i - 1;
            *state = exit;
        } else {
            if (i == -2) {
                *state = exit;
            } else {
                *state = initSubmenu;
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
    case executeArt:
        if (vs_mainmenu_ready() != 0) {
            D_800F4E98.unk2 = 7;
            vs_battle_menuState.returnState = vs_battle_menuState.currentState;
            vs_battle_menuState.currentState = 1;
            *state = none;
            return 1;
        }
        break;
    case exit:
        func_800FFBA8();
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuState.currentState = 1;
            *state = none;
            return 1;
        }
        break;
    }
    return 0;
}
