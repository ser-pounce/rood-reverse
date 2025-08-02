#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"

void func_80102928(int, int, char**);
int func_80102CAC();

extern u_short D_80104690[];
extern int D_80104EC8;
extern int D_80104ED0;
extern u_short D_80104ED8[];
extern char D_8010505A[];
extern char D_80105078[];
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

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80102928);

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

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_80102CAC);

int func_801034FC(int arg0)
{
    char* menuStrings[28];
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
            skill = D_800EBDBC[i];
            if ((vs_main_skills[skill].flags >> 0xF) & 1) {
                menuStrings[row * 2] = vs_main_skills[skill].name;
                menuStrings[row * 2 + 1] = (char*)&D_80104690[D_80104690[6 + i]];
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
    char* menuStrings[28];
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
            skill = D_800EBDCC[i];
            if ((vs_main_skills[skill].flags >> 0xF) & 1) {
                menuStrings[row * 2] = vs_main_skills[skill].name;
                menuStrings[row * 2 + 1] = (char*)&D_80104690[D_80104690[0x14 + i]];
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

INCLUDE_ASM("build/src/MENU/MENU2.PRG/nonmatchings/64", func_801038D4);

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
