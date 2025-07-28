#include "30.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../../build/src/BATTLE/BATTLE.PRG/menuStrings.h"
#include "../../../build/src/MENU/MENU1.PRG/strings.h"

static void _setArtCost(int art)
{
    static char _digitBuffer[16];

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

static void _drawPointsRemaining(int x, int weaponCategory, int artsLearned)
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
        vs_battle_renderTextRaw("NEXT", pos, NULL);
        vs_battle_renderTextRaw(pointsStr, pos + 96, NULL);
    }
}

u_short _strings[] = {
#include "../../assets/MENU/MENU1.PRG/strings.dat"
};

enum _drawArtsListOpt { opt_forceCursorMemory = 0x10 };

static int _drawArtsList(int typeCursorMem)
{
    enum state { init };

    static int state = 0;
    static int D_80104504 = 0;
    static int forceCursorMemory = 0;
    static int weaponType = 0;
    static char D_8010452C;
    static u_char D_8010452D;
    static char artsLearned;
    static char D_8010452F;
    static char _[12];
    static u_short skills[4];

    int i;

    if (typeCursorMem != 0) {
        vs_battle_menuItem_t* menuItem;
        D_8010452C = 0;
        D_8010452D = 10;
        forceCursorMemory = typeCursorMem >> 4;
        typeCursorMem &= 0xF;
        weaponType = typeCursorMem;
        menuItem = vs_battle_setMenuItem(
            10, 320, 34, 0x7E, 8, (char*)&_strings[_strings[(weaponType - 1) * 3]]);
        menuItem->state = 2;
        menuItem->x = 180;
        menuItem->selected = 1;
        menuItem->weaponType = typeCursorMem;
        state = init;
        return 0;
    }
    switch (state) {
    case init: {
        char* menuStrings[10];
        int sp40[5];
        int artCount;
        int cursorMemory;

        if ((D_800F4E6A == 0) && (vs_mainmenu_readyForInput() == 0)) {
            break;
        }
        artCount = 0;
        for (i = 0; i < 4; ++i) {
            int skillId = vs_main_skills_daggerArt1 + (weaponType - 1) * 4 + i;
            if ((vs_main_skills[skillId].flags >> 0xF) & 1) {
                menuStrings[artCount * 2] = (char*)vs_main_skills[skillId].name;
                menuStrings[artCount * 2 + 1]
                    = (char*)&_strings[_strings[VS_strings_INDEX_daggerArt1 + i
                        + ((weaponType - 1) * 4)]];
                sp40[artCount] = 0;
                if ((weaponType != vs_battle_characterState->equippedWeaponType)
                    || (vs_battle_getSkillFlags(0, skillId) != 0)) {
                    sp40[artCount] = 1;
                }
                skills[artCount] = skillId;
                ++artCount;
            }
        }

        for (i = 0; i < 4; ++i) {
            if (D_800F4EA0 & 0x15F) {
                sp40[i] |= 1;
            }
        }

        if (D_800F4E6A == 0) {
            menuStrings[artCount * 2] = (char*)&_strings[VS_strings_OFFSET_viewArts];
            menuStrings[artCount * 2 + 1]
                = (char*)&_strings[VS_strings_OFFSET_viewArtsDesc];
            sp40[artCount] = 2;
            skills[artCount] = 0xFFFF;
            ++artCount;
        }
        cursorMemory = vs_main_settings.cursorMemory;
        if (forceCursorMemory != 0) {
            vs_main_settings.cursorMemory = 1;
            forceCursorMemory = 0;
        }
        func_801005E0(artCount, (weaponType + 11) | 0x200, menuStrings, sp40);
        vs_main_settings.cursorMemory = cursorMemory;
        state = 1;
        artsLearned = artCount;
        D_8010452F = artCount;
        break;
    }
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
                D_80104504 = skills[D_80104504 - 1];
            } else if (D_800F4E6A != 0) {
                D_80104504 = -2;
            }
            if (D_80104504 == 0xFFFF) {
                func_800FA8E0(1);
            } else {
                func_800FA8E0(40);
                func_800FFBA8();
                func_800FFA88(0);
            }
            state = 2;
        } else {
            i = skills[func_801008B0()];
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
        D_8010452D = D_800EBC7C[D_8010452D];
    }
    _drawPointsRemaining(D_800EBBC8[D_8010452D], weaponType, artsLearned);
    return 0;
}

static int _drawWeaponTypeList(int init)
{
    enum state { initialize };

    static int state = 0;
    static int D_80104514 = 0;

    char* menuStrings[10][2];
    int sp68[10];
    int j;
    int i;

    if (init != 0) {
        vs_battle_menuItem_t* menuItem
            = vs_battle_setMenuItem(10, 320, 34, 0x7E, 8, (char*)(_strings + VS_strings_OFFSET_viewArts));
        menuItem->state = 2;
        menuItem->x = 180;
        menuItem->selected = 1;
        state = initialize;
        return 0;
    }

    switch (state) {
    case initialize:
        if (vs_mainmenu_readyForInput() == 0) {
            break;
        }
        for (i = 0; i < 10; ++i) {
            int v = 1;
            menuStrings[i][0] = (char*)&_strings[_strings[i * 3]];
            menuStrings[i][v] = (char*)&_strings[_strings[(i * 3) + 1]];
            sp68[i] = 0x04000000 * (i + 1);
            for (j = 0; j < 4; ++j) {
                if ((vs_main_skills[((i * 4) + 0xB8) + j].flags >> 0xF) & 1) {
                    break;
                }
            }
            if (j == 4) {
                int v = 1;
                menuStrings[i][v] = (char*)&_strings[_strings[(i * 3) + 2]];
                sp68[i] |= 1;
            } else if (i == (vs_battle_characterState->equippedWeaponType - 1)) {
                sp68[i] |= 4;
            }
        }
        func_801005E0(10, 0x216, (char**)menuStrings, sp68);
        state = 1;
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
            state = 2;
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

static void _setMenuTitle()
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = vs_battle_setMenuItem(1, 320, 18, 0x8C, 8,
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
    enum state { 
        init = 3,
        artsInit, 
    };

    static int weaponType = 0;

    int temp_v0;
    char temp_a1;

    switch (*state) {
    case init:
        if (vs_mainmenu_readyForInput() == 0) {
            break;
        }
        func_800FFBC8();
        weaponType = vs_battle_characterState->equippedWeaponType;
        // Fallthrough
    case artsInit:
        _drawArtsList(weaponType);
        *state = 6;
        break;
    case 5:
        _setMenuTitle();
        _drawArtsList(weaponType | opt_forceCursorMemory);
        *state = 6;
        break;
    case 6:
        temp_v0 = _drawArtsList(0);
        if (temp_v0 == 0) {
            break;
        }
        if (temp_v0 > 0) {
            if (temp_v0 == 0xFFFF) {
                *state = 7;
                _drawWeaponTypeList(1);
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
        temp_v0 = _drawWeaponTypeList(0);
        if (temp_v0 == 0) {
            break;
        }
        if (temp_v0 == -2) {
            *state = 10;
        } else {
            if (temp_v0 > 0) {
                weaponType = temp_v0;
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
