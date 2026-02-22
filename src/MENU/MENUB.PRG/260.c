#include "common.h"
#include "../MAINMENU.PRG/278.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../SLUS_010.40/main.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/30D14.h"
#include "../../BATTLE/BATTLE.PRG/4A0A8.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../assets/MENU/MENUB.PRG/menuText.h"
#include "vs_string.h"
#include <libetc.h>
#include <stddef.h>
#include <memory.h>

typedef struct {
    char unk0;
    u_char unk1;
    char unk2;
    char unk3;
} D_8010A6A0_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
} vs_unk_gfx_t2;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    vs_unk_gfx_t2 unk14;
} vs_unk_gfx_t;

int func_80105454(int);
int func_80106B80(int);
int func_801073E0(int);
void func_801080F0(void);
void func_80108938(int);
void func_8010A24C(int arg0);

extern u_long* D_1F800000[];

int func_80102A60(int arg0, int arg1)
{
    if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {
        int temp_s1 = arg1;
        arg0 = vs_mainMenu_getItemCount(arg0, NULL);
        if (vs_main_buttonRepeat & PADL1) {
            int new_var = arg1 - 1;
            arg1 = new_var + arg0;
        }
        if (vs_main_buttonRepeat & PADR1) {
            ++arg1;
        }
        if (arg1 >= arg0) {
            arg1 -= arg0;
        }
        if ((vs_main_buttonsPressed.all & (PADL1 | PADR1)) && (arg1 == temp_s1)) {
            func_800C02E0();
        }
    }
    return arg1;
}

void func_80102B14(int arg0, int arg1)
{
    int i;
    u_long* var_v1;
    vs_battle_menuItem_t* menuItem;

    int temp_s4 = (D_800F4EE8.unk3A.itemCategory - 1) & 7;

    if (arg0 == 4) {
        func_801013F8(0);
    }

    arg0 = (arg0 * 8) - 0x10;

    for (i = 0; i < 8; ++i) {
        int temp_s0 = (((i + 1) & 7) * 0x10) + 0x20;
        if (i == temp_s4 && arg1 == 1) {
            menuItem = vs_battle_getMenuItem(0x1F);
            if (temp_s0 >= (menuItem->initialX - 0xC)) {
                menuItem->icon = i + 0x18;
                continue;
            } else {
                var_v1 = func_800C0214(0x100010, temp_s0 | 0x100000);
            }
        } else {
            var_v1 =
                func_800C0224(0x80, temp_s0 | (arg0 << 0x10), 0x100010, D_1F800000[1]);
        }
        var_v1[4] = (0x78 + i * 0x10) | 0x8000 | (i == temp_s4 ? 0x37FD0000 : 0x37FE0000);
    }
}

void func_80102C50(int arg0)
{
    vs_battle_menuItem_t* temp_v0;

    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    temp_v0 = vs_battle_getMenuItem(0x1F);
    temp_v0->state = 3;
    temp_v0->targetX = 0x12;
    temp_v0 = vs_battle_getMenuItem(arg0);
    temp_v0->state = 2;
    temp_v0->targetX = 0x9B;
    temp_v0->selected = 1;
    temp_v0->unk3C = NULL;
}

void func_80102CBC(int arg0)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_getMenuItem(31);
    menuItem->state = 2;
    menuItem->targetX = 16;
    menuItem->w = 164;
    menuItem = vs_battle_getMenuItem(arg0);
    menuItem->state = 3;
    menuItem->targetX = 18;
}

static u_short _menuText[] = {
#include "../../assets/MENU/MENUB.PRG/menuText.vsString"
};

static char D_8010A504 = 0;
static char D_8010A505 = 0;
static int D_8010A508 = 0;
static int D_8010A50C = 0;

static D_8010A6A0_t* D_8010A6A0;
static D_8010A6A0_t* D_8010A6A4;
static vs_battle_inventory_t* _inventory;
static vs_battle_inventory_t* D_8010A6AC;
static char D_8010A6B0;
static u_char D_8010A6B1;
static char D_8010A6B2;
static u_char D_8010A6B3;
static char D_8010A6B4;
static u_char D_8010A6B5;
static u_char D_8010A6B6;
static char D_8010A6B7;
static char D_8010A6B8;
static char D_8010A6B9;
static char D_8010A6BA;
static char D_8010A6BB;

void func_80102D1C(int arg0, int arg1)
{
    D_8010A50C = 1;
    D_8010A6BA = 0;
    D_8010A6BB = 0;
    func_80102CBC(arg0);
    func_800FBBD4(arg1);
    vs_battle_renderEquipStats(1);
}

void func_80102D6C(int id, char** menuText, u_int rowType, int arg3)
{
    vs_battle_menuItem_t* temp_v0;

    vs_battle_playMenuChangeSfx();
    temp_v0 = vs_battle_setMenuItem(id, 0x9B, 0x12, 0xA5, 0, menuText[0]);
    temp_v0->selected = 1;
    temp_v0->icon = rowType >> 0x1A;
    temp_v0->material = (rowType >> 0x10) & 7;
    vs_mainmenu_setMessage(menuText[1]);
    vs_battle_getMenuItem(0x1F)->unkE = arg3 + 1;
}

int func_80102E08(int arg0, int arg1)
{
    D_800F4EE8.unk0[(arg0 + 0x1E) * 2] = 0;
    D_800F4EE8.unk0[(arg0 + 0x1E) * 2 + 1] = arg1;
    return vs_mainMenu_inventoryIndices[arg0][arg1];
}

static char D_8010A6BC;
static char D_8010A6BD;
static char D_8010A6BE;
static char D_8010A6BF;
static int D_8010A6C0;

void func_80102E54(int arg0)
{
    vs_battle_playMenuLeaveSfx();
    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
    func_800FA810(-1);
    func_800FBBD4(-1);
    vs_battle_renderEquipStats(2);
    D_8010A6BF = 2;
    D_8010A6C0 = vs_main_buttonsPressed.all & PADRup;
    if (arg0 != 0) {
        vs_mainMenu_drawDpPpbars(4);
    }
}

int func_80102EC4(int arg0)
{
    static char D_8010A5EC;
    static char D_8010A5ED;
    static char D_8010A5EE;
    static u_char D_8010A5EF;
    static char D_8010A5F0;

    char* sp10[2];
    int sp18;
    int temp_v0_2;
    int i;

    if (arg0 != 0) {
        D_8010A5EE = arg0 >> 8;
        D_8010A5EF = arg0 - 1;
        func_80102C50(D_8010A5EE);
        D_8010A5F0 = 0;
        D_8010A5ED = 0;
        D_8010A5EC = 0;
        return 0;
    }
    switch (D_8010A5EC) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80102D1C(D_8010A5EE, 7);
            vs_mainMenu_setUiWeaponStats(D_800619D8.unk0[D_8010A5EF]);
            vs_mainMenu_drawDpPpbars(3);
            D_8010A5EC = 1;
        }
        break;
    case 1:
        if (D_8010A5ED < 10) {
            ++D_8010A5ED;
            if (D_8010A5ED < 6) {
                func_800FC510(D_8010A5ED, D_800619D8.unk0[D_8010A5EF], 1);
            }
            break;
        }
        D_8010A5EC = 2;
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80102E54(1);
            D_8010A5EC = 3;
            break;
        }
        temp_v0_2 = func_80102A60(0, D_8010A5EF);
        if (temp_v0_2 != D_8010A5EF) {
            D_8010A5EF = temp_v0_2;
            i = func_80102E08(0, temp_v0_2);
            vs_mainMenu_initUiWeapon(
                &vs_battle_inventory.weapons[i - 1], sp10, &sp18, vs_battle_stringBuf);
            vs_mainMenu_setUiWeaponStats(i);

            func_80102D6C(D_8010A5EE, sp10, sp18, temp_v0_2);
            for (i = 1; i < 6; ++i) {
                func_800FC510(i, D_800619D8.unk0[temp_v0_2], 0);
            }
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_8010310C(int arg0)
{
    static char D_8010A5F1;
    static char D_8010A5F2;
    static char D_8010A5F3;
    static char D_8010A5F4;

    char* sp10[2];
    int sp18;
    int temp_v0_2;
    int temp_v0_3;

    if (arg0 != 0) {
        D_8010A5F3 = arg0 >> 8;
        D_8010A5F4 = arg0 - 1;
        func_80102C50(D_8010A5F3);
        D_8010A5F2 = 10;
        D_8010A5F1 = 0;
        return 0;
    }

    switch (D_8010A5F1)
    case 0: {
        if (vs_mainmenu_ready() != 0) {
            func_80102D1C(D_8010A5F3, 3);
            vs_mainMenu_setUiBladeStats(D_800619D8.unk0[D_8010A5F4 + 8]);
            vs_mainMenu_drawDpPpbars(3);
            D_8010A5F1 = 1;
        }
        break;
    case 1:
        if (D_8010A5F2 != 0) {
            --D_8010A5F2;
        } else {
            D_8010A5F1 = 2;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80102E54(1);
            D_8010A5F1 = 3;
            break;
        }
        temp_v0_2 = func_80102A60(1, D_8010A5F4);
        if (temp_v0_2 != D_8010A5F4) {
            D_8010A5F4 = temp_v0_2;
            temp_v0_3 = func_80102E08(1, temp_v0_2);
            vs_mainMenu_setBladeUi(&vs_battle_inventory.blades[temp_v0_3 - 1], sp10,
                &sp18, vs_battle_stringBuf);
            vs_mainMenu_setUiBladeStats(temp_v0_3);
            func_80102D6C(D_8010A5F3, sp10, sp18, temp_v0_2);
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
        return 0;
}

int func_801032F8(int arg0)
{
    static char* D_8010A510 = "X     0";

    static char D_8010A5F5;
    static char D_8010A5F6;
    static char D_8010A5F7;
    static char D_8010A5F8;
    static char D_8010A5F9;

    char* sp10[2];
    int sp18;
    int temp_v0_2;
    int temp_v0_3;

    if (arg0 != 0) {
        D_8010A5F7 = arg0 >> 8;
        D_8010A5F8 = arg0 - 1;
        func_80102C50(D_8010A5F7);
        D_8010A5F9 = 0;
        D_8010A5F6 = 0U;
        D_8010A5F5 = 0U;
        return 0;
    }
    switch (D_8010A5F5) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80102D1C(D_8010A5F7, 4);
            vs_mainMenu_setUiGripStats(D_800619D8.unk0[D_8010A5F8 + 0x18]);
            D_8010A5F5 = 1U;
        }
        break;
    case 1:
        if (D_8010A5F6 < 0xAU) {
            D_8010A5F6 = (D_8010A5F6 + 1);
        } else {
            D_8010A5F5 = 2U;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80102E54(0);
            D_8010A5F5 = 3U;
        } else {
            temp_v0_2 = func_80102A60(2, D_8010A5F8);
            if (temp_v0_2 != D_8010A5F8) {
                D_8010A5F8 = temp_v0_2;
                temp_v0_3 = func_80102E08(2, temp_v0_2);
                vs_mainMenu_setGripUi(&vs_battle_inventory.grips[temp_v0_3 - 1], sp10,
                    &sp18, vs_battle_stringBuf);
                vs_mainMenu_setUiGripStats(temp_v0_3);
                func_80102D6C(D_8010A5F7, sp10, sp18, temp_v0_2);
            }
        }
        D_8010A510[6] =
            (vs_battle_inventory.grips[D_800619D8.unk0[D_8010A5F8 + 0x18] - 1].gemSlots
                + 0x30); // BUG: Write to const char
        vs_mainMenu_drawRowIcon(0x116, 0x100, 0x20);
        vs_battle_renderTextRaw(D_8010A510, 0x240118, NULL);
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_80103538(int arg0)
{
    static char D_8010A5FA;
    static char D_8010A5FB;
    static char D_8010A5FC;
    static u_char D_8010A5FD;
    static char D_8010A5FE;

    char* sp10[2];
    int sp18;
    int temp_v0_2;
    int i;

    if (arg0 != 0) {
        D_8010A5FC = arg0 >> 8;
        D_8010A5FD = arg0 - 1;
        func_80102C50(D_8010A5FC);
        D_8010A5FE = 0;
        D_8010A5FB = 0U;
        D_8010A5FA = 0U;
        return 0;
    }
    switch (D_8010A5FA) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80102D1C(D_8010A5FC, 7);
            func_800FD5A0(D_800619D8.unk28[D_8010A5FD]);
            vs_mainMenu_drawDpPpbars(3);
            D_8010A5FA = 1U;
        }
        break;
    case 1:
        if (D_8010A5FB < 0xAU) {
            ++D_8010A5FB;
            if (D_8010A5FB < 4) {
                func_800FC704(D_8010A5FB, D_800619D8.unk28[D_8010A5FD], 1);
            }
            break;
        }
        if (vs_mainmenu_ready() != 0) {
            D_8010A5FA = 2U;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80102E54(1);
            D_8010A5FA = 3U;
            break;
        }
        temp_v0_2 = func_80102A60(3, D_8010A5FD);
        if (temp_v0_2 != D_8010A5FD) {
            D_8010A5FD = temp_v0_2;
            i = func_80102E08(3, temp_v0_2);
            vs_mainMenu_initUiShield(
                &vs_battle_inventory.shields[i - 1], sp10, &sp18, vs_battle_stringBuf);
            func_800FD5A0(i);
            func_80102D6C(D_8010A5FC, sp10, sp18, temp_v0_2);

            for (i = 1; i < 4; ++i) {
                func_800FC704(i, D_800619D8.unk28[temp_v0_2], 0);
            }
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_80103794(int arg0)
{
    static char D_8010A5FF;
    static char D_8010A600;
    static char D_8010A601;
    static char D_8010A602;

    char* sp10[2];
    int sp18;
    int temp_v0_2;
    int temp_v0_3;

    if (arg0 != 0) {
        D_8010A601 = arg0 >> 8;
        D_8010A602 = arg0 - 1;
        func_80102C50(D_8010A601);
        D_8010A600 = 0xA;
        D_8010A5FF = 0;
        return 0;
    }
    switch (D_8010A5FF) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80102D1C(D_8010A601, 7);
            func_800FD700(D_800619D8.unk0[D_8010A602 + 0x30]);
            if (vs_battle_inventory.armor[D_800619D8.unk0[D_8010A602 + 0x30] - 1].category
                != 7) {
                vs_mainMenu_drawDpPpbars(1);
            }
            D_8010A5FF = 1;
        }
        break;
    case 1:
        if (D_8010A600 != 0) {
            --D_8010A600;
        } else {
            D_8010A5FF = 2;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80102E54(1);
            D_8010A5FF = 3;
            break;
        }
        temp_v0_2 = func_80102A60(4, D_8010A602);
        if (temp_v0_2 != D_8010A602) {
            D_8010A602 = temp_v0_2;
            temp_v0_3 = func_80102E08(4, temp_v0_2);
            vs_mainMenu_setAccessoryUi(&vs_battle_inventory.armor[temp_v0_3 - 1], sp10,
                &sp18, vs_battle_stringBuf);
            func_800FD700(temp_v0_3);
            func_80102D6C(D_8010A601, sp10, sp18, temp_v0_2);
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_801039BC(int arg0)
{
    static char D_8010A603;
    static char D_8010A604;
    static char D_8010A605;
    static char D_8010A606;

    char* sp10[2];
    int sp18;
    int temp_v0_2;
    int temp_v0_3;

    if (arg0 != 0) {
        D_8010A605 = arg0 >> 8;
        D_8010A606 = arg0 - 1;
        func_80102C50(D_8010A605);
        D_8010A604 = 10;
        D_8010A603 = 0U;
        return 0;
    }
    switch (D_8010A603) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80102D1C(D_8010A605, 3);
            func_800FD878(D_800619D8.unk0[D_8010A606 + 0x40]);
            D_8010A603 = 1;
        }
        break;
    case 1:
        if (D_8010A604 != 0) {
            --D_8010A604;
        } else {
            D_8010A603 = 2;
        }
        break;
    case 2:
        if (vs_main_buttonsPressed.all & 0x50) {
            func_80102E54(0);
            D_8010A603 = 3;
            D_8010A6C0 = vs_main_buttonsPressed.all & 0x10;
            break;
        }
        temp_v0_2 = func_80102A60(5, D_8010A606);
        if (temp_v0_2 != D_8010A606) {
            D_8010A606 = temp_v0_2;
            temp_v0_3 = func_80102E08(5, temp_v0_2);
            vs_mainMenu_setGemUi(&vs_battle_inventory.gems[temp_v0_3 - 1], sp10, &sp18,
                vs_battle_stringBuf);
            func_800FD878(temp_v0_3);
            func_80102D6C(D_8010A605, sp10, sp18, temp_v0_2);
        }
        break;
    case 3:
        return vs_mainmenu_ready();
    }
    return 0;
}

int func_80103BA8(int arg0)
{
    static int (*D_8010A514[])(int) = { func_80102EC4, func_8010310C, func_801032F8,
        func_80103538, func_80103794, func_801039BC };

    static u_char D_8010A607;

    int temp_v0;
    int var_s0 = 0;

    if (arg0 != 0) {
        var_s0 = arg0 >> 4;
        D_8010A607 = arg0 & 0xF;
        D_8010A6BF = 1;
        D_8010A6C0 = 0;
        func_800FDD78();
        vs_battle_getMenuItem(0x1F)->unkE = var_s0 & 0xFF;
        func_800FFA88(0);
    }

    temp_v0 = D_8010A514[D_8010A607](var_s0);

    if (temp_v0 != 0) {
        if (D_8010A6C0 != 0) {
            return -2;
        }
        D_8010A6BA = 1;
        D_8010A6BF = 0;
        D_8010A6BB = 1;
        D_8010A50C = 0;
        func_800FFA88(2);
    } else if (vs_mainmenu_ready() != 0) {
        D_801022D5 = D_801024B8 != 9;
        func_801013F8(1);
        func_800FDEBC();
    }
    return temp_v0;
}

int _getWeaponStat(int stat, vs_battle_uiWeapon* weapon)
{
    switch (stat) {
    case 0:
        return -weapon->blade.category;
    case 1:
        return -weapon->blade.material;
    case 2:
        return weapon->range.unk0;
    case 3:
        return -weapon->damageType;
    case 4:
        return weapon->currentDp;
    case 5:
        return weapon->maxDp;
    case 6:
        return weapon->currentPp;
    case 7:
        return weapon->maxPp;
    case 8:
        return weapon->currentStr;
    case 9:
        return weapon->currentInt;
    case 10:
        return weapon->currentAgility;
    default:
        if (stat >= 17) {
            return weapon->classAffinityCurrent.affinity[0][stat - 17];
        }
        return weapon->classAffinityCurrent.class[0][stat - 11];
    }
}

void func_80103DA0(int arg0)
{
    vs_battle_uiWeapon sp10;
    char sp1A8[8];
    int temp_v0;
    int i;
    int var_s3;
    int var_s4;
    int temp_s0;
    vs_battle_inventoryWeapon* new_var2 = vs_battle_inventory.weapons;
    char* new_var = D_800619D8.unk0;

    vs_battle_rMemzero(sp1A8, 8);
    var_s4 = 0;

    while (1) {
        var_s3 = 0x80000000;

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                vs_battle_applyWeapon(&sp10, &new_var2[temp_s0 - 1]);
                temp_v0 = _getWeaponStat(arg0, &sp10);
                if (var_s3 < temp_v0) {
                    var_s3 = temp_v0;
                }
            }
        }

        if (var_s3 == 0x80000000) {
            break;
        }

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                vs_battle_applyWeapon(&sp10, &new_var2[temp_s0 - 1]);
                if (_getWeaponStat(arg0, &sp10) == var_s3) {
                    sp1A8[var_s4++] = temp_s0;
                    new_var[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(new_var, sp1A8, sizeof sp1A8);
}

int _getShieldStat(int arg0, vs_battle_uiShield* shield)
{
    switch (arg0) {
    case 1:
        return -shield->base.material;
    case 4:
        return shield->currentPp;
    case 5:
        return shield->maxPp;
    case 6:
        return shield->currentDp;
    case 7:
        return shield->maxDp;
    case 8:
        return shield->currentStr;
    case 9:
        return shield->currentInt;
    case 10:
        return shield->currentAgility;
    default:
        if (arg0 < 33) {
            return shield->classAffinityCurrent.class[0][arg0 - 27];
        }
        if (arg0 >= 40) {
            return shield->types[arg0 - 39];
        }
        return shield->classAffinityCurrent.affinity[0][arg0 - 33];
    }
}

void func_80103FD8(int arg0)
{
    vs_battle_uiShield shield;
    char sp1A8[8];
    int temp_v0;
    int i;
    int var_s3;
    int var_s4;
    int temp_s0;
    vs_battle_inventoryShield* new_var2 = &vs_battle_inventory.shields[0];
    char* new_var = D_800619D8.unk28;

    vs_battle_rMemzero(sp1A8, sizeof sp1A8);
    var_s4 = 0;

    while (1) {
        var_s3 = 0x80000000;

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                vs_battle_applyShield(&shield, &new_var2[temp_s0 - 1]);
                temp_v0 = _getShieldStat(arg0, &shield);
                if (var_s3 < temp_v0) {
                    var_s3 = temp_v0;
                }
            }
        }

        if (var_s3 == 0x80000000) {
            break;
        }

        for (i = 0; i < 8; ++i) {
            temp_s0 = new_var[i];
            if (temp_s0 != 0) {
                vs_battle_applyShield(&shield, &new_var2[temp_s0 - 1]);
                if (_getShieldStat(arg0, &shield) == var_s3) {
                    sp1A8[var_s4++] = temp_s0;
                    new_var[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(new_var, sp1A8, 8);
}

int func_80104144(int arg0, vs_battle_inventoryMisc* arg1)
{
    if (arg0 == 0) {
        return -arg1->id;
    }
    return arg1->count;
}

void func_80104164(int arg0)
{
    char sp10[64];
    int temp_v0;
    int i;
    int var_s4;

    vs_battle_inventoryMisc* item = vs_battle_inventory.items;
    char* c = D_800619D8.unk70;

    vs_battle_rMemzero(sp10, sizeof sp10);
    var_s4 = 0;

    while (1) {
        int temp_s0;
        int var_s3 = 0x80000000;

        for (i = 0; i < 64; ++i) {
            temp_s0 = c[i];
            if (temp_s0 != 0) {
                temp_v0 = func_80104144(arg0, &item[temp_s0 - 1]);
                if (var_s3 < temp_v0) {
                    var_s3 = temp_v0;
                }
            }
        }

        if (var_s3 == 0x80000000) {
            break;
        }

        for (i = 0; i < 64; ++i) {
            temp_s0 = c[i];
            if (temp_s0 != 0) {
                if (func_80104144(arg0, &item[temp_s0 - 1]) == var_s3) {
                    sp10[var_s4++] = temp_s0;
                    c[i] = 0;
                }
            }
        }
    }
    vs_battle_memcpy(c, &sp10, sizeof sp10);
}

int _getEquipmentStat(int stat, vs_battle_uiEquipment* item)
{
    switch (stat) {
    case 0:
        return -item->category;
    case 1:
        return -item->material;
    case 2:
        return item->range.unk0;
    case 3:
        return -item->damageType;
    case 4:
        return item->currentDp;
    case 5:
        return item->maxDp;
    case 6:
        return item->currentPp;
    case 7:
        return item->maxPp;
    case 8:
        return item->strength;
    case 9:
        return item->intelligence;
    case 10:
        return item->agility;
    default:
        if (stat >= 27) {
            stat -= 16;
        }
        if (stat < 17) {
            return item->classes[stat - 11];
        }
        if (stat >= 24) {
            return item->types[stat - 23];
        }
        return item->affinities[stat - 17];
    }
}

void _copyEquipmentStats(vs_battle_uiEquipment* equipment, int itemCategory, int index)
{
    switch (itemCategory) {
    case 1:
        vs_battle_copyInventoryBladeStats(equipment, &vs_battle_inventory.blades[index]);
        return;
    case 2:
        vs_battle_copyInventoryGripStats(equipment, &vs_battle_inventory.grips[index]);
        return;
    case 4:
        vs_battle_copyInventoryArmorStats(equipment, &vs_battle_inventory.armor[index]);
        return;
    case 5:
        vs_battle_copyInventoryGemStats(equipment, &vs_battle_inventory.gems[index]);
        return;
    }
}

void func_80104474(int arg0, int arg1)
{
    vs_battle_uiEquipment sp10;
    int temp_v0;
    int i;
    int var_s3;
    int var_s5;
    char* temp_s6;
    int temp_s0;
    int temp_s4;

    var_s5 = 0;
    temp_s4 = vs_mainMenu_inventoryItemCapacities[arg0];
    {
        char spVLA[temp_s4];
        temp_s6 = vs_mainMenu_inventoryIndices[arg0];
        vs_battle_rMemzero(spVLA, temp_s4);

        while (1) {
            var_s3 = 0x80000000;
            for (i = 0; i < temp_s4; ++i) {
                temp_s0 = temp_s6[i];
                if (temp_s0 != 0) {
                    _copyEquipmentStats(&sp10, arg0, temp_s0 - 1);
                    temp_v0 = _getEquipmentStat(arg1, &sp10);
                    if (var_s3 < temp_v0) {
                        var_s3 = temp_v0;
                    }
                }
            }

            if (var_s3 == 0x80000000) {
                break;
            }

            for (i = 0; i < temp_s4; ++i) {
                temp_s0 = temp_s6[i];
                if (temp_s0 != 0) {
                    _copyEquipmentStats(&sp10, arg0, temp_s0 - 1);
                    if (_getEquipmentStat(arg1, &sp10) == var_s3) {
                        spVLA[var_s5++] = temp_s0;
                        temp_s6[i] = 0;
                    }
                }
            }
        }
        vs_battle_memcpy(temp_s6, spVLA, temp_s4);
    }
}

int func_80104608(int arg0)
{
    static char D_8010A52C[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23 };
    static char D_8010A544[] = { 0, 8, 9, 10, 24, 25, 26 };
    static char D_8010A54C[] = { 1, 4, 5, 6, 7, 8, 9, 10, 40, 41, 42, 27, 28, 29, 30, 31,
        32, 33, 34, 35, 36, 37, 38, 39 };
    static char D_8010A564[] = { 0, 1, 4, 5, 8, 9, 10, 40, 41, 42, 27, 28, 29, 30, 31, 32,
        33, 34, 35, 36, 37, 38, 39 };
    static char D_8010A57C[] = { 8, 9, 10, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
        39 };
    static char D_8010A58C[] = { 0, 56, 0, 0 };
    static char D_8010A590[] = { 24, 24, 7, 24, 23, 16, 2 };
    static char* D_8010A598[] = { D_8010A52C, D_8010A52C, D_8010A544, D_8010A54C,
        D_8010A564, D_8010A57C, D_8010A58C };

    static char D_8010A608;
    static u_char D_8010A609;

    char* sp10[48];
    int spD0[24];
    int i;

    if (arg0 != 0) {
        D_8010A609 = arg0 - 1;
        D_8010A608 = 0;
        return 0;
    }

    switch (D_8010A608) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            char* new_var = D_8010A598[D_8010A609];
            for (i = 0; i < D_8010A590[D_8010A609]; ++i) {
                sp10[i * 2] =
                    (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[new_var[i] * 2
                                                                      + 0x1B6]];
                sp10[i * 2 + 1] =
                    (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[new_var[i] * 2
                                                                      + 0x1B7]];
                spD0[i] = 0;
            }
            func_800FF0EC(i, D_8010A609 + 0x2D, sp10, spD0);
            D_8010A608 = 1;
        }
        break;
    case 1:
        func_800FF43C();
        i = func_800FF360();
        if ((i + 1) != 0) {
            if (i >= 0) {
                vs_battle_playMenuSelectSfx();
                switch (D_8010A609) {
                case 0:
                    func_80103DA0(D_8010A52C[i]);
                    break;
                case 3:
                    func_80103FD8(D_8010A54C[i]);
                    break;
                case 6:
                    func_80104164(D_8010A58C[i]);
                    break;
                default:
                    func_80104474(D_8010A609, D_8010A598[D_8010A609][i]);
                    break;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i + 1;
        }
    }
    return 0;
}

int func_80104860(int arg0)
{
    static char D_8010A5B4[] = { vs_char_spacing, 0x30, 0, 0, 0, vs_char_forwardSlash, 0,
        0, 0, vs_char_terminator };
    static char D_8010A5C0[] = { 1, 10, 100 };
    static char D_8010A5C3 = 0;

    static char D_8010A60A;
    static char D_8010A60B;
    static char D_8010A60C;
    static char D_8010A60D;
    static u_char D_8010A60E;
    static char D_8010A60F;
    static char D_8010A610;
    static char _[3] __attribute__((unused));

    char* sp18[4];
    int sp28[2];
    char* sp30[4];
    int sp40[2];
    int i;
    int temp_v1_4;
    vs_battle_menuItem_t* menuItem;
    int a0;
    int a2;

    if (arg0 != 0) {
        D_8010A60D = (arg0 >> 0x10);
        D_8010A60B = (arg0 >> 8);
        D_8010A60C = arg0;
        func_800C8E04(1);
        vs_mainmenu_setMessage(
            (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[D_8010A60D + 0x22A]]);
        D_8010A60A = 0;
        return 0;
    }
    switch (D_8010A60A) {
    case 0:
        if ((D_800F5130 >> 0x1E) & 1) {
            if (vs_mainmenu_ready() != 0) {
                D_8010A60A = ((D_8010A60D & 1) + 1);
            }
        }
        break;
    case 1:
        for (i = 0; i < 2; ++i) {
            sp18[i * 2] = (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[i + 0x228]];
            sp18[i * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[D_8010A60D + 0x22A]];
            sp28[i] = 0;
        }

        func_800FF0EC(2, 4, sp18, sp28);
        D_8010A60A = 3U;
        break;
    case 2:
        D_8010A610 = vs_battle_inventory.items[D_8010A60C - 1].count;
        i = vs_battle_toBCD(D_8010A610);
        D_8010A5B4[8] = (i & 0xF);
        i = vs_battle_toBCD(i >> 4);

        D_8010A5B4[7] = (i & 0xF);
        D_8010A5B4[6] = (i >> 4);
        for (i = 2; i < 5; ++i) {
            D_8010A5B4[i] = 0;
        }
        menuItem = vs_battle_setMenuItem(0x22, -0x7E, 0x82, 0x7E, 0, D_8010A5B4);
        menuItem->state = 5;
        menuItem->targetX = 0;
        D_8010A60E = 0;
        D_8010A60F = 0;
        D_8010A60A = 4;
        break;
    case 3:
        func_800FF43C();
        i = func_800FF360() + 1;
        if (i != 0) {
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0x1C);
                vs_mainMenu_initItem(D_8010A60B, D_8010A60C);
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i;
        }
        break;
    case 4:

        if (vs_mainmenu_ready() != 0) {
            for (i = 2; i < 5; ++i) {
                D_8010A5B4[i] = 0x8F;
            }

            vs_battle_setMenuItem(0x22, 0, 0x82, 0x7E, 0, D_8010A5B4);
            D_8010A60A = 5;
        case 5:
            if (vs_main_buttonsPressed.all & 0x70) {
                i = vs_battle_toBCD(D_8010A60F);
                D_8010A5B4[4] = (i & 0xF);
                i = vs_battle_toBCD(i >> 4);
                D_8010A5B4[3] = (i & 0xF);
                D_8010A5B4[2] = (i >> 4);
                vs_battle_setMenuItem(0x22, 0, 0x82, 0x7E, 0, D_8010A5B4);
                if (vs_main_buttonsPressed.all & 0x50) {
                    vs_battle_playMenuLeaveSfx();
                    if ((vs_main_buttonsPressed.all & 0x10)) {
                        return -2;
                    }
                    return -1;
                }
                if (D_8010A60F == 0) {
                    vs_battle_playMenuLeaveSfx();
                    return -1;
                }
                vs_battle_playMenuSelectSfx();
                D_8010A60A = 6;
                break;
            }

            i = 0;
            a0 = a2 = D_8010A60F;
            if (vs_main_buttonRepeat & 0x1000) {
                i = 1;
            }
            if (vs_main_buttonRepeat & 0x4000) {
                --i;
            }
            if (i == 1) {
                a0 = a2 + D_8010A5C0[D_8010A60E];
            } else if (i == -1) {
                a0 = a2 - D_8010A5C0[D_8010A60E];
            }
            if (a0 >= 0) {
                if (D_8010A610 >= a0) {
                    D_8010A60F = a0;
                }
            }
            i = 0;
            a0 = D_8010A60E;
            if (vs_main_buttonRepeat & 0x2000) {
                i = -1;
            }
            if (vs_main_buttonRepeat & 0x8000) {
                i += 1;
            }
            if (i == 1) {
                if ((a0 & 0xFF) == 2) {
                    if (D_8010A60F != D_8010A610) {
                        D_8010A60F = D_8010A610;
                    }
                } else {
                    ++D_8010A60E;
                }
            } else if (i == -1) {
                if (!(a0 & 0xFF)) {
                    if (D_8010A60F != 0) {
                        D_8010A60F = 0;
                    }
                } else {
                    --D_8010A60E;
                }
            }
            if ((a0 != D_8010A60E) || (a2 != D_8010A60F)) {
                vs_battle_playMenuChangeSfx();
            }
            func_800C7210(5);
            i = vs_battle_toBCD(D_8010A60F);
            func_800C70F8(i & 0xF, 0x42, 0x82, D_1F800000[2] - 3);
            i = vs_battle_toBCD(i >> 4);
            func_800C70F8(i & 0xF, 0x3C, 0x82, D_1F800000[2] - 3);
            func_800C70F8(i >> 4, 0x36, 0x82, D_1F800000[2] - 3);
            D_8010A5C3 = func_800FFCDC(D_8010A5C3, (0x36 - (D_8010A60E * 6)) | 0x720000);
        }
        break;
    case 6:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                sp30[i * 2] =
                    (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[i + 0x228]];
                sp30[i * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x2E49];
                sp40[i] = 0;
            }

            func_800FF0EC(2, 4, sp30, sp40);
            D_8010A60A = 7;
        }
        break;
    case 7:
        func_800FF43C();
        i = func_800FF360() + 1;
        if (i != 0) {
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0x1C);
                temp_v1_4 = vs_battle_inventory.items[D_8010A60C - 1].count;
                if (temp_v1_4 == D_8010A60F) {
                    vs_mainMenu_initItem(D_8010A60B, D_8010A60C);
                } else {
                    vs_battle_inventory.items[D_8010A60C - 1].count =
                        temp_v1_4 - D_8010A60F;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
            }
            return i;
        }
        break;
    }
    return 0;
}

void func_80104F98(int arg0)
{
    D_8010A6B9 = arg0;
    D_8010A6BA = arg0;
    D_8010A6BB = arg0;
}

int _getParentItem(int itemCategory, int index)
{
    int parentIndex = 0;

    if (itemCategory == 1) {
        parentIndex = vs_battle_inventory.blades[index].assembledWeaponIndex;
    }
    if (itemCategory == 2) {
        parentIndex = vs_battle_inventory.grips[index].assembledWeaponIndex;
    }
    if (itemCategory == 5) {
        parentIndex = vs_battle_inventory.gems[index].setItemIndex;
        if (parentIndex & 0x80) {
            parentIndex = 0;
        }
    }
    return parentIndex;
}

int func_80105044(int arg0, int arg1)
{
    int var_v1 = 0;
    if (arg0 == 5) {
        var_v1 = vs_battle_inventory.gems[arg1].setItemIndex;
        if (!(var_v1 & 0x80)) {
            var_v1 = 0;
        }
    }
    return var_v1 & 0x7F;
}

int func_80105088(u_int arg0, char** arg1, int* arg2, char* arg3)
{
    char* sp10;
    int sp14;
    int temp_s1_2;
    int temp_v0;
    int temp_v0_2;
    int var_s3;
    int i;
    vs_battle_inventoryWeapon* temp_s0;
    char* s5 = arg3;
    sp10 = vs_mainMenu_inventoryIndices[arg0];
    sp14 = 0;
    for (i = 0; i < vs_mainMenu_inventoryItemCapacities[arg0]; ++i, s5 += 0x60) {
        temp_s1_2 = sp10[i];
        if (temp_s1_2 == 0) {
            break;
        }

        temp_s1_2 = sp10[i] - 1;
        var_s3 = 0;

        switch (arg0) {
        case 0:
            temp_s0 = &vs_battle_inventory.weapons[temp_s1_2];
            vs_mainMenu_initUiWeapon(temp_s0, &arg1[i * 2], &arg2[i], s5);
            if (temp_s0->isEquipped != 0) {
                var_s3 = 0xCA00;
            }
            break;
        case 1:
            vs_mainMenu_setBladeUi(
                &vs_battle_inventory.blades[temp_s1_2], &arg1[i * 2], &arg2[i], s5);
            break;
        case 2:
            vs_mainMenu_setGripUi(
                &vs_battle_inventory.grips[temp_s1_2], &arg1[i * 2], &arg2[i], s5);
            break;
        case 3:
            vs_mainMenu_initUiShield(
                &vs_battle_inventory.shields[temp_s1_2], &arg1[i * 2], &arg2[i], s5);
            if (vs_battle_inventory.shields[temp_s1_2].isEquipped != 0) {
                var_s3 = 0xCA00;
            }
            break;
        case 4:
            vs_mainMenu_setAccessoryUi(
                &vs_battle_inventory.armor[temp_s1_2], &arg1[i * 2], &arg2[i], s5);
            if (vs_battle_inventory.armor[temp_s1_2].bodyPart != 0) {
                var_s3 = 0xCA00;
            }
            break;
        case 5:
            vs_mainMenu_setGemUi(
                &vs_battle_inventory.gems[temp_s1_2], &arg1[i * 2], &arg2[i], s5);
            break;
        case 6:
            vs_mainMenu_setItemUi(
                &vs_battle_inventory.items[temp_s1_2], &arg1[i * 2], &arg2[i], s5);
            /* fallthrough */
        default:
            break;
        }
        temp_v0 = _getParentItem(arg0, temp_s1_2);
        if (temp_v0 != 0) {
            var_s3 = 0xCA00;
            if (vs_battle_inventory.weapons[temp_v0 - 1].isEquipped == 0) {
                var_s3 = 0xCC00;
            }
        }
        temp_v0_2 = func_80105044(arg0, temp_s1_2);
        if (temp_v0_2 != 0) {
            var_s3 = 0xCA00;
            if (vs_battle_inventory.shields[temp_v0_2 - 1].isEquipped == 0) {
                var_s3 = 0xCC00;
            }
        }
        arg2[i] |= var_s3;
        ++sp14;
    }
    return sp14;
}

void func_8010537C(int arg0)
{
    int i;
    vs_battle_menuItem_t* menuItem;

    while (D_801023D0 < 16) {
        func_80100A5C();
    }

    for (i = 20; i < 40; ++i) {
        menuItem = vs_battle_getMenuItem(i);
        if (menuItem->state == 2) {
            menuItem->state = 1;
            menuItem->initialX = (short)(u_short)menuItem->targetX;
        }
        menuItem->selected = (i ^ (D_800F4EE8.unk0[(arg0 + 0x1E) * 2] + 0x14)) == 0;
    }
}

int func_80105454(int arg0)
{
    static char D_8010A614[8];
    static char D_8010A61C;
    static char D_8010A61D;
    static char D_8010A61E;
    static char _ __attribute__((unused));
    static int D_8010A620;

    char* sp10[128];
    int sp210[64];
    char* sp310[128];
    int sp510[64];
    int temp_a1_2;
    int temp_s3_5;
    int temp_v0_6;
    int var_a1_2;
    int var_a1_3;
    int var_s0;
    int var_s1;
    int var_s1_2;
    int i;
    u_char var_s4;
    int var_v0;
    int var_v0_3;
    char* temp_s1;
    char* temp_s2;
    char* temp_v0_7;
    u_int temp_s5;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        menuItem = vs_battle_getMenuItem(3);
        if (menuItem->initialX >= 0xB5) {
            if (menuItem->initialX >= 0xCD) {
                menuItem->initialX -= 0x18;
            }
            menuItem->state = 2;
            menuItem->targetX = 0xB4;
        }
        func_80104F98(1);
        D_8010A6BC = 0;
        D_8010A61E = arg0 & 1;
        if (D_8010A61E != 0) {
            if (vs_main_settings.cursorMemory == 0) {
                memset(&D_800F4EE8.unk3A, 0, sizeof D_800F4EE8.unk3A);
            }
        }
        D_8010A61C = 1;
        return 0;
    }

    var_s4 = (D_800F4EE8.unk3A.itemCategory - 1) & 7;
    temp_s2 = vs_mainMenu_inventoryIndices[var_s4];

    switch (D_8010A61C) {
    case 0:
    case 1:
        temp_s1 = vs_main_allocHeapR(0x1800U);
        D_801023E3 = 1;

        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }

        if (var_s4 == 7) {
            for (i = 0; i < 4; ++i) {
                sp10[i] = (char*)&_menuText[_menuText[i + VS_menuText_INDEX_equip]];
                sp210[i] = 1;
            }
            var_s0 = 2;
        } else {
            var_s0 = func_80105088(var_s4, sp10, sp210, temp_s1);
        }
        D_8010A61D = var_s0 == 0;
        if (D_8010A61D != 0) {
            vs_mainmenu_setMessage((char*)&vs_mainMenu_itemHelp[0x33E3]);
        } else {
            i = vs_main_settings.cursorMemory;
            if (D_8010A61E != 0) {
                D_8010A61E = 0;
            } else {
                vs_main_settings.cursorMemory = 1;
            }
            temp_a1_2 = var_s4 + 0x1E;
            if (var_s4 == 7) {
                var_a1_2 = temp_a1_2 | 0x200;
            } else {
                var_a1_2 = temp_a1_2 | 0x19200;
            }
            vs_mainmenu_setMenuRows(var_s0, var_a1_2, sp10, sp210);
            if (D_8010A61C == 0) {
                func_8010537C(var_s4);
            }
            vs_main_settings.cursorMemory = i;
        }
        vs_main_freeHeapR(temp_s1);
        D_8010A61C = 2;
        break;
    case 2:
        D_8010A6BB = 1;
        if (D_8010A61D != 0) {
            if (vs_main_buttonsPressed.all & 0x10) {
                vs_battle_playMenuLeaveSfx();
                return -2;
            }
            if (vs_main_buttonsPressed.all & 0x40) {
                vs_battle_playMenuLeaveSfx();
                return -1;
            }
            if (vs_main_buttonsPressed.all & 0xA0) {
                func_800C02E0();
            }
        } else {
            int s7;
            temp_s5 = var_s4;
            var_s0 = temp_s5 < 6;
            D_8010A6BB = var_s0 + 1;
            D_8010A620 = vs_mainmenu_getSelectedRow() + 1;

            s7 = 1;
            if (D_8010A620 == 0) {
                if (vs_main_buttonsPressed.all & 0x80) {
                    if ((var_s0 != 0) && (vs_mainmenu_ready() != 0)) {
                        vs_battle_playMenuSelectSfx();
                        var_s1 = func_80100814();
                        vs_battle_getMenuItem(var_s1 >> 8)->itemState = 0;
                        func_80103BA8(temp_s5 | ((var_s1 + s7) * 0x10));
                        D_8010A6B9 = 0;
                        D_8010A61C = 7;
                        break;
                    }
                    func_800C02E0();
                }
            } else {
                if ((D_8010A620 <= 0) || (temp_s5 == 7)) {
                    return D_8010A620;
                }

                temp_v0_7 = vs_main_allocHeapR(0x1800);
                var_s1 = func_80105088(temp_s5, sp310, sp510, temp_v0_7);
                sp510[D_8010A620 - 1] |= 8;
                i = vs_main_settings.cursorMemory;
                vs_main_settings.cursorMemory = 1;
                vs_mainmenu_setMenuRows(var_s1, (temp_s5 + 0x1E) | 0x19200, sp310, sp510);
                vs_main_settings.cursorMemory = i;
                func_8010537C(temp_s5);
                D_8010A6BB = 1;
                D_801023E3 = 0;
                vs_main_freeHeapR(temp_v0_7);
                D_8010A61C = 6;
                break;
            }
        }
        // Fallthrough
    case 3:
        i = vs_main_buttonsState & 0x8004;
        var_s0 = vs_main_buttonsState & 0x2008;
        temp_v0_6 = i != 0;

        if (var_s0 != 0) {
            var_s1 = temp_v0_6 ^ 1;
        } else {
            var_s1 = temp_v0_6 & 1;
        }

        if (var_s1 != 0) {
            var_a1_3 = 0x8004;
            if (i == 0x8004) {
                var_a1_3 = 0x8000;
            }
            if (vs_main_buttonRepeat & var_a1_3) {
                var_s4 = (var_s4 - 1) & 7;
            }

            var_a1_3 = 0x2008;
            if (var_s0 == 0x2008) {
                var_a1_3 = 0x2000;
            }

            var_v0_3 = vs_main_buttonRepeat & var_a1_3;
            if (var_v0_3 != 0) {
                var_s4 = (var_s4 + 1) & 7;
            }
            if (var_s4 != ((D_800F4EE8.unk3A.itemCategory - 1) & 7)) {
                vs_battle_playMenuChangeSfx();
                D_800F4EE8.unk3A.itemCategory = (var_s4 + 1) & 7;
                if (D_8010A61C == 2) {
                    if (D_8010A61D == 0) {
                        func_80100814();
                        vs_mainMenu_clearMenuExcept(3);
                    }
                    D_8010A61C = 3;
                }
            }
        }
        if ((D_8010A61C == 3) && (vs_mainmenu_ready() != 0)) {
            if ((vs_main_buttonsState & 0xA00C) && (var_s1 != 0)) {
                break;
            }
            D_8010A61C = 1;
            return func_80105454(0);
        }
        break;
    case 4:
        menuItem = vs_battle_getMenuItem(3);
        if (menuItem->initialX >= 0xB5) {
            if (menuItem->initialX >= 0xCD) {
                menuItem->initialX -= 0x18;
            }
            menuItem->state = 2;
            menuItem->targetX = 0xB4;
        }
        D_8010A61C = 5;
        /* fallthrough */
    case 5:
        if (vs_mainmenu_ready() != 0) {
            D_8010A61C = 1;
        }
        break;
    case 6:
        if (vs_main_buttonsPressed.all & 0x80) {
            func_800C02E0();
        }
        i = vs_mainmenu_getSelectedRow() + 1;
        if (i != 0) {
            var_s0 = D_8010A620;
            if (var_s0 == i) {
                D_8010A61C = 8;
                break;
            }
            if (i > 0) {
                var_s1 = temp_s2[i - 1];
                var_a1_3 = temp_s2[var_s0 - 1];
                if ((var_s4 == 6)
                    && (vs_battle_inventory.items[var_s1 - 1].id
                        == vs_battle_inventory.items[var_a1_3 - 1].id)) {
                    vs_battle_inventory.items[var_a1_3 - 1].count =
                        vs_battle_inventory.items[var_a1_3 - 1].count
                        + vs_battle_inventory.items[var_s1 - 1].count;
                    if (vs_battle_inventory.items[var_a1_3 - 1].count > 100) {
                        vs_battle_inventory.items[var_s1 - 1].count =
                            vs_battle_inventory.items[var_a1_3 - 1].count - 100;
                        vs_battle_inventory.items[var_a1_3 - 1].count = 100;
                    } else {
                        vs_mainMenu_initItem(6, var_a1_3);
                    }
                } else {
                    temp_s2[i - 1] = var_a1_3;
                    temp_s2[var_s0 - 1] = var_s1;
                }
                vs_mainMenu_clearMenuExcept(3);
                D_8010A61C = 4;
                break;
            }
            if (i != -1) {
                return -2;
            }
            D_8010A61C = 0;
        }
        break;
    case 7:
        i = func_80103BA8(0);

        if (i == 0) {
            break;
        }

        if (i == -2) {
            return -2;
        }

        D_8010A6B9 = 1;
        menuItem = vs_battle_getMenuItem(3);

        if (menuItem->initialX >= 0xB5) {
            if (menuItem->initialX >= 0xCD) {
                menuItem->initialX -= 0x18;
            }
            menuItem->state = 2;
            menuItem->targetX = 0xB4;
        }
        D_8010A61C = 1;
        break;
    case 8:
        var_s0 = 0;
        temp_s3_5 = temp_s2[D_8010A620 - 1] - 1;
        vs_battle_rMemzero(vs_battle_rowTypeBuf, 0x14);

        if (var_s4 == 6) {
            sp310[0] = (char*)&vs_mainMenu_itemHelp[0x351D];
            sp310[1] = (char*)&_menuText[VS_menuText_OFFSET_itemUseProhibited];
            *vs_battle_rowTypeBuf = 1;
            var_s0 = 1;
            D_8010A614[1] = 1;
        }

        if (((char)(var_s4 - 1) < 2U) || (var_s4 == 5)) {
            sp310[var_s0 * 2] = (char*)&vs_mainMenu_itemHelp[0x3527];
            sp310[var_s0 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x352C];
            if ((_getParentItem(var_s4, temp_s3_5) == 0)
                && (func_80105044(var_s4, temp_s3_5) == 0)) {
                sp310[var_s0 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x35B2];
                vs_battle_rowTypeBuf[var_s0] = 1;
            }
            ++var_s0;
            D_8010A614[var_s0] = 2;
        }

        var_s1_2 = 0;
        sp310[var_s0 * 2] = (char*)&vs_mainMenu_itemHelp[0x354A];
        sp310[var_s0 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x354F];

        switch (var_s4) {
        case 0:
            var_s1_2 = vs_battle_inventory.weapons[temp_s3_5].isEquipped != 0;
            break;
        case 3:
            var_s1_2 = vs_battle_inventory.shields[temp_s3_5].isEquipped != 0;
            break;
        case 4:
            var_s1_2 = vs_battle_inventory.armor[temp_s3_5].bodyPart != 0;
            break;
        case 6:
            if (vs_battle_inventory.items[temp_s3_5].id >= 0x1CAU) {
                var_s1_2 = 3;
            }
            break;
        }
        temp_a1_2 = _getParentItem(var_s4, temp_s3_5);
        if (temp_a1_2 != 0) {
            var_s1_2 = 1;
            if (vs_battle_inventory.weapons[temp_a1_2 - 1].isEquipped == 0) {
                var_s1_2 = 2;
            }
        }
        temp_a1_2 = func_80105044(var_s4, temp_s3_5);
        if (temp_a1_2 != 0) {
            var_s1_2 = 1;
            if (vs_battle_inventory.shields[temp_a1_2 - 1].isEquipped == 0) {
                var_s1_2 = 2;
            }
        }

        if (var_s1_2 != 0) {
            sp310[var_s0 * 2 + 1] =
                (char*)&vs_mainMenu_itemHelp[vs_mainMenu_itemHelp[var_s1_2 + 0x297]];
            var_s1_2 = 1;
        }

        vs_battle_rowTypeBuf[var_s0] = var_s1_2;
        ++var_s0;
        D_8010A614[var_s0] = 3;

        if (var_s4 == 6) {
            sp310[var_s0 * 2] = (char*)&vs_mainMenu_itemHelp[0x356D];
            sp310[var_s0 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x3574];
            if (vs_battle_inventory.items[temp_s3_5].id >= 0x1CA) {
                sp310[var_s0 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x350E];
                vs_battle_rowTypeBuf[var_s0] = 1;
            }
            ++var_s0;
            D_8010A614[var_s0] = 4;
        }

        sp310[var_s0 * 2] = (char*)&vs_mainMenu_itemHelp[0x3586];
        sp310[var_s0 * 2 + 1] = (char*)&vs_mainMenu_itemHelp[0x358A];

        ++var_s0;

        D_8010A614[var_s0] = 5;
        func_800FF0EC(var_s0, var_s4 + 0x26, sp310, vs_battle_rowTypeBuf);
        D_8010A61C = 9;
        break;
    case 9:
        var_s1 = func_800FF348();
        vs_mainMenu_printInformation(var_s1, D_801022C4);
        func_800FF43C();
        i = func_800FF360() + 1;
        var_v0 = 0;
        if (i != 0) {
            if (i > 0) {
                vs_battle_playMenuSelectSfx();
                func_800FA854(0x28);
                switch (D_8010A614[i]) {
                case 2:
                    func_800FFBC8();
                    vs_mainMenu_clearMenuExcept(3);
                    D_8010A61C = 0xA;
                    break;
                case 3:
                    var_s0 = temp_s2[D_8010A620 - 1] | (var_s4 << 8);
                    if ((var_s4 == 6)
                        && (vs_battle_inventory.items[temp_s2[D_8010A620 - 1] - 1].count
                            >= 2U)) {
                        var_s0 |= 0x10000;
                    }
                    func_80104860(var_s0);
                    D_8010A61C = 0xB;
                    break;
                case 4:
                    func_80104860(temp_s2[D_8010A620 - 1] | (var_s4 << 8) | 0x20000);
                    D_8010A61C = 0xB;
                    break;
                case 5:
                    func_800FFBC8();
                    func_80104608(var_s4 + 1);
                    D_8010A61C = 0xC;
                    break;
                }
            } else {
                vs_battle_playMenuLeaveSfx();
                func_800FA854(0x28);
                if (i == -2) {
                    vs_mainMenu_clearMenuExcept(3);
                    return -2;
                }
                func_800FFBC8();
                D_8010A61C = 0;
            }
        }
        break;
    case 10:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        i = _getParentItem(var_s4, temp_s2[D_8010A620 - 1] - 1);
        if (i == 0) {
            i = func_80105044(var_s4, temp_s2[D_8010A620 - 1] - 1);
            var_s4 = 3;
        } else {
            var_s4 = 0;
        }
        D_800F4EE8.unk3A.itemCategory = (var_s4 + 1) & 7;
        (&D_800F4EE8.unk3A)->unk2[var_s4] = vs_mainMenu_findItem(var_s4, i - 1) - 1;
        D_8010A61C = 1;
        break;
    case 11:
        i = func_80104860(0);
        if (i != 0) {
            func_800FFBC8();
            func_800FA854(0x28);
            vs_mainMenu_clearMenuExcept(3);
            if (i == -2) {
                return -2;
            }
            D_8010A61C = 5;
        }
        break;
    case 12:
        i = func_80104608(0);
        if (i != 0) {
            func_800FA854(0x28);
            vs_mainMenu_clearMenuExcept(3);
            if (i == -2) {
                return -2;
            }
            D_8010A61C = 5;
        }
        break;
    }
    return 0;
}

void func_80106274(int arg0)
{
    static int D_8010A5C4 = 0;
    static char D_8010A5C8 = 0;

    static int D_8010A624;
    static int _ __attribute__((unused));
    static vs_unk_gfx_t2 D_8010A62C;
    static vs_unk_gfx_t D_8010A64C;

    int temp_lo;
    int temp_lo_2;
    int temp_s1_2;
    int var_s2;
    int var_v0;
    int temp_s1;
    vs_unk_gfx_t* p = (vs_unk_gfx_t*)&D_1F800000[13];

    switch (arg0) {
    case 0:
        var_s2 = D_8010A508;
        switch (D_8010A50C) {
        case 0:
            if (var_s2 < 0xA) {
                var_s2 += 1;
                D_8010A508 = var_s2;
            }
            var_s2 = 0x80 - vs_battle_rowAnimationSteps[0xA - var_s2];
            break;
        case 1:
            if (var_s2 > 0) {
                var_s2 -= 1;
                D_8010A508 = var_s2;
            }
            var_s2 = vs_battle_rowAnimationSteps[var_s2];
            break;
        case 2:
            if (var_s2 < 0xA) {
                var_s2 += 1;
                D_8010A508 = var_s2;
            } else {
                D_8010A50C = 0;
            }
            var_s2 = vs_battle_rowAnimationSteps[0xA - var_s2] + 0x80;
            break;
        case 3:
            var_v0 = var_s2 * 2;
            if (var_s2 > 0) {
                var_s2 -= 1;
                D_8010A508 = var_s2;
                var_v0 = var_s2 * 2;
            }
            var_s2 = 0x260 - ((var_v0 + var_s2) * 0x10);
            break;
        }
        if (D_8010A5C8 != 0) {
            D_8010A5C8 = 0;
            return;
        }
        if (D_8010A5C4 != 0) {
            temp_s1 = ((u_short*)D_800F4538[1])[0x32B];
            p->unk10 = ((-rsin(0xB00) * var_s2) >> 8) * temp_s1;
            p->unk14.unk0 = -(((u_short*)D_800F4538[1])[0x31F] << 0xB);
            p->unk14.unk4 = ((rcos(0xB00) * var_s2) >> 8) * temp_s1;
            temp_s1_2 = temp_s1 * 4;
            temp_lo = rcos(0xB00) * temp_s1_2;
            p->unk0 = p->unk10 + temp_lo;
            p->unk4 = p->unk14.unk0;
            temp_lo_2 = rsin(0xB00) * temp_s1_2;
            p->unk14.unkC = 0;
            p->unk14.unk10 = 0;
            p->unk14.unk14 = 0;
            p->unk14.unk1C = 0x1000;
            p->unk8 = p->unk14.unk4 + temp_lo_2;
            func_8007ACB0();
            func_800F9EB8(&D_1F800000[5]);
            return;
        }
        return;
    case 1:
        if (D_8010A5C4 == 0) {
            D_8010A508 = 0;
            D_8010A50C = 2;
            D_8010A5C8 = arg0;
            D_8010A5C4 = arg0;
            D_8010A624 = vs_main_projectionDistance;
            func_8007CCF0(0x200);

            D_8010A62C = p[-1].unk14;
            D_8010A64C = *p;

            p->unk14.unkC = 0;
            p->unk14.unk10 = 0;
            p->unk14.unk14 = 0;
            p->unk14.unk1C = 0x1000;
            func_8007ACB0();
            func_80100414(0x7FE, 0x80);
            func_800F9A24(0);
            return;
        }
        break;
    case 2:
        if (D_8010A5C4 != 0) {
            func_800F9E0C();
            func_80100414(-4, 0x80);
            func_8007CCF0(D_8010A624);
            p[-1].unk14 = D_8010A62C;
            *p = D_8010A64C;
            D_8010A5C4 = 0;
        }
        break;
    }
}

int func_801066CC(int arg0)
{
    static char D_8010A680;
    static char D_8010A681;

    int var_s0;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        D_800F4EE8.unk3A.itemCategory = arg0;
        D_8010A6B0 = 0;
        D_8010A6B2 = 0;
        D_8010A680 = 0;
        return 0;
    }
    switch (D_8010A680) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_800FFB68(1);
            func_800FFA88(2);
            menuItem = vs_battle_setMenuItem(3, 0x140, 0x12, 0x7E, 8,
                (char*)&vs_battle_menuStrings[vs_battle_menuStrings[3]]);
            menuItem->state = 2;
            menuItem->targetX = 0xB4;
            menuItem->selected = 1;
            D_8010A680 = 1;
        }
        break;
    case 1:
        func_80104F98(0);
        D_8010A6BC = 0;
        D_8010A6BD = 0;
        D_8010A6BE = 0;
        D_8010A6BF = 0;
        if (vs_mainmenu_ready() != 0) {
            func_8008A4DC(0);
            D_8010A681 = D_800EB9AF;
            if (!D_8010A681) {
                func_800CB654(1);
                D_800EB9B0 = 0x200000;
            }
            func_80106274(1);
            func_80105454(1);
            D_8010A680 = 2;
        }
        break;
    case 2:
        if (func_80105454(0) != 0) {
            func_80104F98(0);
            vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
            func_8008A4DC(1);
            if (D_8010A681 == 0) {
                func_800CB654(0);
                D_800EB9B0 = 0;
            }
            func_80106274(2);
            D_8010A680 = 3;
            if (vs_main_settings.information == 0) {
                func_800FFBA8();
            }
        }
        break;
    case 3:
        func_800FFB68(0);
        func_800FFA88(0);
        if (vs_mainmenu_ready() != 0) {
            D_8010A6B0 = 1;
            D_8010A6B2 = 1;
            return 1;
        }
        break;
    }

    if (D_8010A6B9 != 0) {
        if (D_8010A6BC < 10) {
            ++D_8010A6BC;
        }
        var_s0 = vs_battle_rowAnimationSteps[0xA - D_8010A6BC];
    } else {
        if (D_8010A6BC != 0) {
            --D_8010A6BC;
        }
        var_s0 = (0xA - D_8010A6BC) << 5;
    }
    if ((D_8010A6BC != 0) && (D_8010A6BF == 0)) {
        int itemCategory = (D_800F4EE8.unk3A.itemCategory - 1) & 7;
        vs_battle_menuItem_t* menuItem =
            vs_battle_setMenuItem(0x1F, var_s0 + 0xB4, 0x22, 0x8C, 8,
                (char*)&_menuText[_menuText[itemCategory + VS_menuText_INDEX_weapons]]);
        menuItem->selected = 1;
        if (itemCategory != 7) {
            menuItem->unk12 = vs_mainMenu_inventoryItemCapacities[itemCategory];
            menuItem->unk10 = vs_mainMenu_getItemCount(itemCategory, NULL);
        }
    }
    func_80106274(0);
    if (D_8010A6BA != 0) {
        if (D_8010A6BD < 4) {
            ++D_8010A6BD;
        }
    } else if (D_8010A6BD != 0) {
        D_8010A6BD -= 1;
    }
    func_80102B14(D_8010A6BD, D_8010A6BF);
    if (D_8010A6BB != 0) {
        if (D_8010A6BE < 10) {
            ++D_8010A6BE;
        }
        var_s0 = vs_battle_rowAnimationSteps[0xA - D_8010A6BE];
    } else {
        if (D_8010A6BE != 0) {
            --D_8010A6BE;
        }
        var_s0 = (0xA - D_8010A6BE) << 5;
    }
    if (D_8010A6BE != 0) {
        vs_mainMenu_drawButtonUiBackground(0x10 - var_s0, 0x26, 0x58, 0xA);
        vs_mainmenu_drawButton(1, 8 - var_s0, 0x24, NULL);
        vs_battle_renderTextRawColor("STATUS", ((0x1C - var_s0) & 0xFFFF) | 0x260000,
            0x202020 << D_8010A6BB, NULL);
    }
    return 0;
}

int func_80106B80(int arg0)
{
    static char D_8010A5C9 = 0;

    static char D_8010A682;
    static char D_8010A683;
    static char D_8010A684;
    static u_char D_8010A685;
    static char D_8010A686;
    static char _ __attribute__((unused));

    int i;
    int temp_v0_3;
    int temp_v0_4;
    vs_battle_inventoryShield* temp_a0;
    vs_battle_inventoryShield* shield;
    vs_battle_inventoryWeapon* temp_a2;
    vs_battle_inventoryWeapon* weapon;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        vs_battle_memcpy(D_8010A6A4, D_8010A6A0, 0x280);
        D_8010A6B2 = 0;
        D_8010A684 = D_8010A6B6;
        D_8010A685 = arg0 - 1;
        D_8010A686 = D_8010A6A0[D_8010A685].unk0;
        D_8010A6B4 = 0;
        D_8010A6B5 = 0;
        D_8010A683 = 0;
        D_8010A682 = 0;
        return 0;
    }

    i = D_8010A6A4[D_8010A685].unk1;

    switch (D_8010A682) {
    case 0:
        if (D_8010A6B3 != 6) {
            break;
        }
        vs_battle_rMemzero(D_8010A6A0, 0x280);
        D_8010A6A0->unk0 = D_8010A6A4[D_8010A685].unk0;
        D_8010A6A0->unk1 = i;
        D_8010A6A0->unk3 = 2;
        if (D_8010A686 != 0) {
            shield = &_inventory->shields[i];
            D_8010A6A0[1].unk0 = 3;
            D_8010A6A0[1].unk1 = i;
            D_8010A6A0[1].unk3 = 3;
            D_8010A6B6 = 2;

            for (i = 0; i < shield->base.gemSlots; ++i) {
                if (shield->gems[i] != 0) {
                    D_8010A6A0[D_8010A6B6].unk0 = 5;
                    D_8010A6A0[D_8010A6B6].unk1 = shield->gems[i] - 1;
                    D_8010A6A0[D_8010A6B6].unk3 = 5;
                    ++D_8010A6B6;
                }
            }
        } else {
            weapon = &_inventory->weapons[i];
            D_8010A6A0[1].unk0 = 1;
            D_8010A6A0[1].unk1 = weapon->blade - 1;
            D_8010A6A0[1].unk3 = 4;
            D_8010A6A0[2].unk0 = 2;
            D_8010A6A0[2].unk1 = weapon->grip - 1;
            D_8010A6A0[2].unk3 = 4;
            D_8010A6B6 = 3;

            for (i = 0; i < _inventory->grips[weapon->grip - 1].gemSlots; ++i) {
                if (weapon->gems[i] != 0) {
                    D_8010A6A0[D_8010A6B6].unk0 = 5;
                    D_8010A6A0[D_8010A6B6].unk1 = weapon->gems[i] - 1;
                    D_8010A6A0[D_8010A6B6].unk3 = 5;
                    ++D_8010A6B6;
                }
            }
        }
        D_8010A6B3 = 10;
        D_8010A6B2 = 1;
        D_8010A682 = 1;
        break;
    case 1:
        menuItem = vs_battle_setMenuItem(
            0x1E, 0x140, 0x92, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionYes]);
        menuItem->state = 2;
        menuItem->targetX = 0xC2;
        D_8010A682 = 2;
        break;
    case 2:
        menuItem = vs_battle_setMenuItem(
            0x1F, 0x140, 0xA2, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionNo]);
        menuItem->state = 2;
        menuItem->targetX = 0xC2;
        vs_battle_stringContext.strings[0] =
            D_8010A686 == 0 ? _inventory->weapons[i].name
                            : vs_mainMenu_itemNames[_inventory->shields[i].base.id];
        func_800C8E04(1);
        vs_mainmenu_setMessage((char*)&_menuText[VS_menuText_OFFSET_disassembleConfirm]);
        D_8010A682 = 3;
        break;
    case 3:
        D_8010A682 += vs_mainmenu_ready();
        break;
    case 4:
        vs_battle_getMenuItem(D_8010A683 + 0x1E)->selected = 1;
        vs_battle_getMenuItem(0x1F - D_8010A683)->selected = 0;
        if (vs_main_buttonsPressed.all & 0x60) {
            vs_mainMenu_menuItemLeaveRight(0x1E);
            vs_mainMenu_menuItemLeaveRight(0x1F);
            D_8010A6B2 = 0;
            if ((D_8010A683 != 0) || (vs_main_buttonsPressed.all & 0x40)) {
                vs_battle_playMenuLeaveSfx();
                D_8010A682 = 6;
            } else {
                vs_main_playSfxDefault(0x7E, 0x19);
                D_8010A682 = 5;
            }
            if (vs_main_settings.information == 0) {
                func_800FFBA8();
            }
            break;
        }
        if (vs_main_buttonRepeat & 0x5000) {
            vs_battle_playMenuChangeSfx();
            D_8010A683 = (1 - D_8010A683);
        }
        D_8010A5C9 = vs_battle_drawCursor(D_8010A5C9, D_8010A683 + 8);
        break;
    case 5:
        if (D_8010A6B3 != 6) {
            break;
        }

        vs_battle_rMemcpy(&D_8010A6A4[D_8010A684], &D_8010A6A0[1], (D_8010A6B6 - 1) * 4);

        if (D_8010A686 != 0) {
            temp_a0 = &_inventory->shields[i];
            for (i = 0; i < temp_a0->base.gemSlots; ++i) {
                temp_v0_3 = temp_a0->gems[i];
                if (temp_v0_3 != 0) {
                    temp_a0->gems[i] = 0;
                    _inventory->gems[temp_v0_3 - 1].setItemIndex = 0;
                }
            }
        } else {
            temp_a2 = &_inventory->weapons[i];
            _inventory->blades[temp_a2->blade - 1].assembledWeaponIndex = 0;
            _inventory->grips[temp_a2->grip - 1].assembledWeaponIndex = 0;

            for (i = 0; i < _inventory->grips[temp_a2->grip - 1].gemSlots; ++i) {
                temp_v0_4 = temp_a2->gems[i];
                if (temp_v0_4 != 0) {
                    temp_a2->gems[i] = 0;
                    _inventory->gems[temp_v0_4 - 1].setItemIndex = 0;
                }
            }
        }

        D_8010A684 = D_8010A6B6 + (D_8010A684 + 0xFE);
        for (i = D_8010A685; i < D_8010A684; ++i) {
            D_8010A6A4[i] = D_8010A6A4[i + 1];
        }
        // Fallthrough
    case 6:
        if (D_8010A6B3 == 6) {
            D_8010A6B6 = D_8010A684;
            vs_battle_memcpy(D_8010A6A0, D_8010A6A4, 0x280);
            func_801080F0();
            D_8010A6B3 = 10;
            D_8010A6B2 = 1;
            D_8010A682 = 7;
        }
        break;
    case 7:
        if (D_8010A6B3 != 0) {
            break;
        }
        return -1;
    }
    return 0;
}

int func_801073E0(int arg0)
{
    static char D_8010A5CA = 0;

    static u_short D_8010A688;
    static u_short D_8010A68A;
    static u_short D_8010A68C;
    static char D_8010A68E;
    static char D_8010A68F;
    static u_char D_8010A690;

    D_8010A6A0_t* temp_a3;
    int j;
    int i;
    int var_v0;
    vs_battle_inventoryMisc* item;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        vs_battle_memcpy(D_8010A6A4, D_8010A6A0, 0x280);
        vs_battle_memcpy(D_8010A6AC, _inventory, 0xF00);
        D_8010A6B2 = 0;
        D_8010A690 = D_8010A6B6;
        D_8010A68C = _inventory->items[D_8010A6A0[arg0 - 1].unk1].id;
        D_8010A6B4 = 0;
        D_8010A6B5 = 0;
        D_8010A68F = 0;
        D_8010A68E = 0;
        return 0;
    }
    switch (D_8010A68E) {
    case 0:
        if (D_8010A6B3 == 6) {
            D_8010A68A = 0;
            item = vs_battle_inventory.items;
            for (i = 0; i < 64; ++i, ++item) {
                if (item->id == D_8010A68C) {
                    int v0 = D_8010A68A + 100;
                    v0 -= item->count;
                    D_8010A68A = v0;
                }
            }

            D_8010A688 = 0;

            for (i = 0; i < D_8010A6B6; ++i) {
                if (D_8010A6A0[i].unk0 == 6) {
                    item = &_inventory->items[D_8010A6A0[i].unk1];
                    if (item->id == D_8010A68C) {
                        D_8010A688 += item->count;
                        vs_battle_rMemzero(item, 4);
                        --D_8010A6B6;
                        for (j = i; j < D_8010A6B6; ++j) {
                            D_8010A6A0[j] = D_8010A6A0[j + 1];
                        }
                        --i;
                    }
                }
            }

            D_8010A6B6 = 0;

            while (D_8010A688 != 0) {
                for (i = 0; i < 64; ++i) {
                    if (_inventory->items[i].id == 0) {
                        break;
                    }
                }

                if (i == 0x40) {
                    break;
                }

                temp_a3 = &D_8010A6A0[D_8010A6B6++];
                temp_a3->unk0 = 6;
                temp_a3->unk1 = i;
                temp_a3->unk2 = 0;
                _inventory->items[i].id = D_8010A68C;
                temp_a3->unk3 = D_8010A68A != 0;
                if (temp_a3->unk3 != 0) {
                    if (D_8010A68A > 100) {
                        _inventory->items[i].count = 100;
                        D_8010A688 -= 100;
                        D_8010A68A -= 100;
                    } else {
                        _inventory->items[i].count = D_8010A68A;
                        D_8010A688 = D_8010A688 - D_8010A68A;
                        D_8010A68A = 0;
                    }
                } else if (D_8010A688 > 100) {
                    _inventory->items[i].count = 100;
                    D_8010A688 -= 100;
                } else {
                    _inventory->items[i].count = D_8010A688;
                    D_8010A688 = 0;
                }
            }
            D_8010A6B3 = 10;
            D_8010A6B2 = 1;
            D_8010A68E = 1;
        }
        break;
    case 1:
        menuItem = vs_battle_setMenuItem(
            0x1E, 0x140, 0x92, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionYes]);
        menuItem->state = 2;
        menuItem->targetX = 0xC2;
        D_8010A68E = 2;
        break;
    case 2:
        menuItem = vs_battle_setMenuItem(
            0x1F, 0x140, 0xA2, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionNo]);
        menuItem->state = 2;
        menuItem->targetX = 0xC2;
        vs_battle_stringContext.strings[0] = vs_mainMenu_itemNames[D_8010A68C];
        func_800C8E04(1);
        vs_mainmenu_setMessage((char*)&_menuText[VS_menuText_OFFSET_organizeConfirm]);
        D_8010A68E = 3;
        break;
    case 3:
        D_8010A68E += vs_mainmenu_ready();
        break;
    case 4:
        vs_battle_getMenuItem(D_8010A68F + 0x1E)->selected = 1;
        vs_battle_getMenuItem(0x1F - D_8010A68F)->selected = 0;
        if (vs_main_buttonsPressed.all & 0x60) {
            vs_mainMenu_menuItemLeaveRight(0x1E);
            vs_mainMenu_menuItemLeaveRight(0x1F);
            D_8010A6B2 = 0;
            if ((D_8010A68F != 0) || (vs_main_buttonsPressed.all & 0x40)) {
                vs_battle_playMenuLeaveSfx();
                D_8010A68E = 6;
            } else {
                vs_battle_playMenuSelectSfx();
                D_8010A68E = 5;
            }
            var_v0 = 0;
            if (vs_main_settings.information == 0) {
                func_800FFBA8();
            }
            break;
        }
        if (vs_main_buttonRepeat & 0x5000) {
            vs_battle_playMenuChangeSfx();
            D_8010A68F = (1 - D_8010A68F);
        }
        D_8010A5CA = vs_battle_drawCursor((int)D_8010A5CA, D_8010A68F + 8);
        break;
    case 5:
        if (D_8010A6B3 != 6) {
            break;
        }

        for (i = 0; i < D_8010A690; ++i) {
            if (D_8010A6A4[i].unk0 == 6) {
                item = &D_8010A6AC->items[D_8010A6A4[i].unk1];
                if (item->id == D_8010A68C) {
                    vs_battle_rMemzero(item, 4);
                    --D_8010A690;
                    for (j = i; j < D_8010A690; ++j) {
                        D_8010A6A4[j] = D_8010A6A4[j + 1];
                    }
                    --i;
                }
            }
        }

        for (i = 0; i < D_8010A6B6; ++i) {
            for (j = 0; j < 64; ++j) {
                if (D_8010A6AC->items[j].id == 0) {
                    break;
                }
            }
            if (j == 0x40) {
                break;
            }

            temp_a3 = &D_8010A6A4[D_8010A690++];
            temp_a3->unk0 = 6;
            temp_a3->unk1 = j;
            temp_a3->unk2 = 0;
            temp_a3->unk3 = D_8010A6A0[i].unk3;
            item = &D_8010A6AC->items[j];
            item->id = D_8010A68C;
            item->count = _inventory->items[D_8010A6A0[i].unk1].count;
        }
        // Fallthrough
    case 6:
        if (D_8010A6B3 == 6) {
            D_8010A6B6 = D_8010A690;
            vs_battle_memcpy(D_8010A6A0, D_8010A6A4, 0x280);
            vs_battle_memcpy(_inventory, D_8010A6AC, 0xF00);
            D_8010A6B3 = 0xA;
            D_8010A6B2 = 1;
            D_8010A68E = 7;
        }
        break;
    case 7:
        if (D_8010A6B3 != 0) {
            break;
        }
        return -1;
    }
    return 0;
}

int _copyBladeToInventory(vs_battle_inventoryBlade* source, int weapon)
{
    int index = 1;
    vs_battle_inventoryBlade* blade = _inventory->blades;

    while (blade->id != 0) {
        ++blade;
        ++index;
        if (index == 16) {
            return 0;
        }
    }
    vs_battle_copyAligned(blade, source, sizeof *blade);
    blade->assembledWeaponIndex = weapon;
    blade->index = index;
    return index;
}

int _copyGripToInventory(vs_battle_inventoryGrip* source, int weaponIndex)
{
    int index = 1;
    vs_battle_inventoryGrip* grip = _inventory->grips;

    while (grip->id != 0) {
        ++grip;
        ++index;
        if (index == 16) {
            return 0;
        }
    }
    vs_battle_copyAligned(grip, source, sizeof *grip);
    grip->assembledWeaponIndex = weaponIndex;
    grip->index = index;
    return index;
}

int _copyGemToInventory(vs_battle_inventoryGem* source, int item)
{
    int index = 1;
    vs_battle_inventoryGem* gem = _inventory->gems;

    while (gem->id != 0) {
        ++gem;
        ++index;
        if (index == 0x30) {
            return 0;
        }
    }
    vs_battle_copyAligned(gem, source, sizeof *gem);
    gem->setItemIndex = item;
    gem->index = index;
    return index;
}

int _copyWeaponToInventory(vs_battle_setWeaponForDropRand* arg0)
{
    int i;
    vs_battle_inventoryWeapon* slot = _inventory->weapons;
    int index = 1;

    while (slot->blade != 0) {
        ++slot;
        if (++index == 8) {
            return 0;
        }
    }

    vs_battle_rMemzero(slot, sizeof *slot);
    slot->index = index;
    slot->blade = _copyBladeToInventory(&arg0->blade, index);
    slot->grip = _copyGripToInventory(&arg0->grip, index);

    for (i = 0; i < 3; i++) {
        if (arg0->gems[i].id != 0)
            slot->gems[i] = _copyGemToInventory(&arg0->gems[i], index);
    }

    vs_battle_rMemcpy(slot->name, arg0->unk94, sizeof slot->name);
    return index;
}

int _copyArmorToInventory(vs_battle_inventoryArmor* source)
{
    int index = 1;
    vs_battle_inventoryArmor* armor = _inventory->armor;

    while (armor->id != 0) {
        ++armor;
        ++index;
        if (index == 16) {
            return 0;
        }
    }
    vs_battle_copyAligned(armor, source, sizeof *armor);
    armor->index = index;
    return index;
}

int _copyShieldToInventory(vs_battle_shieldForDropRand* arg0)
{
    int i;

    vs_battle_inventoryShield* shield = _inventory->shields;
    int index = 1;

    while (shield->base.id != 0) {
        ++shield;
        ++index;
        if (index == 8) {
            return 0;
        }
    }
    vs_battle_rMemzero(shield, sizeof *shield);
    vs_battle_copyAligned(&shield->base, &arg0->shield, sizeof shield->base);

    shield->base.bodyPart = index;

    for (i = 0; i < 3; ++i) {
        if (arg0->gems[i].id != 0) {
            shield->gems[i] = _copyGemToInventory(&arg0->gems[i], index | 0x80);
        }
    }
    return index;
}

int _copyMiscToInventory(vs_battle_inventoryMisc* arg0)
{
    int index = 1;
    vs_battle_inventoryMisc* item = _inventory->items;

    while (item->id != 0) {
        ++index;
        ++item;
        if (index == 64) {
            return 0;
        }
    }

    item->id = arg0->id;
    item->count = arg0->index;
    return index;
}

void func_801080F0(void)
{
    int i;
    int temp_v1;
    D_8010A6A0_t* var_s1 = D_8010A6A0;

    for (i = 0; i < D_8010A6B6; ++i, ++var_s1) {
        var_s1->unk3 =
            func_800FEB94(var_s1->unk0, &vs_battle_inventory, var_s1->unk1, _inventory)
            != 0;
    }

    i = D_8010A6B4 + D_8010A6B5;

    if (i >= D_8010A6B6) {
        i = D_8010A6B6 - 1;
        D_8010A6B5 = D_8010A6B6 - 8;
        D_8010A6B4 = 7;
    }
    if (D_8010A6B6 < 9) {
        D_8010A6B4 = i;
        D_8010A6B5 = 0;
        return;
    }
    temp_v1 = D_8010A6B6 - 8;
    if (temp_v1 < D_8010A6B5) {
        D_8010A6B5 = temp_v1;
        D_8010A6B4 = i - temp_v1;
    }
    if ((D_8010A6B4 == 7) && (i != (D_8010A6B6 - 1))) {
        D_8010A6B4 -= 1;
        D_8010A6B5 = D_8010A6B5 + 1;
    }
}

void func_8010822C(int arg0, int arg1)
{
    D_8010A6A0_t* temp_v1 = &D_8010A6A0[D_8010A6B6++];
    temp_v1->unk0 = arg0;
    temp_v1->unk1 = arg1 - 1;
    temp_v1->unk2 = 0;
}

static char* D_8010A5CC[] = { "WEAPON", "BLADE", "GRIP", "SHIELD", "ARMOR", "GEM",
    "MISC" };

int func_80108264(int arg0, D_8010A6A0_t* arg1)
{
    int i;
    vs_battle_inventoryShield* shield;
    vs_battle_inventoryWeapon* weapon;

    int temp_t0 = arg1->unk0;
    int var_a2 = 0;

    switch (arg0) {
    case 1:
    case 2:
        var_a2 += temp_t0 == 0;
        // Fallthrough
    case 0:
    case 3:
    case 4:
    case 6:
        var_a2 += temp_t0 == arg0;
        break;
    case 5:
        var_a2 += temp_t0 == 5;
        if (temp_t0 == 0) {
            weapon = &_inventory->weapons[arg1->unk1];

            for (i = 0; i < _inventory->grips[weapon->grip - 1].gemSlots; ++i) {
                var_a2 += weapon->gems[i] != 0;
            }
        }
        if (temp_t0 == 3) {
            shield = &_inventory->shields[arg1->unk1];

            for (i = 0; i < shield->base.gemSlots; ++i) {
                var_a2 += shield->gems[i] != 0;
            }
        }
        break;
    }
    return var_a2;
}

void func_8010837C(int arg0)
{
    int sp10;
    int temp_s0;
    int temp_s4;
    int var_a2;
    int var_fp;
    int var_s0;
    int var_s0_2;
    int i;
    int var_s2;
    int temp_s3;
    D_8010A6A0_t* var_s6;
    unsigned int new_var;
    char* c;
    int new_var2;

    var_s6 = NULL;
    var_fp = 1;
    if (D_8010A6B7 != 0) {
        var_s6 = (D_8010A6A0_t*)1;
        if (D_8010A6B7 & 0xF) {

            var_fp = 0;
            var_s6 = &D_8010A6A0[D_8010A6B5 + D_8010A6B7 - 1];
            for (i = 0; i < D_8010A6B6; ++i) {
                var_fp += D_8010A6A0[i].unk3;
            }
        }
    }
    vs_battle_renderTextRaw("GADGET BAG", (arg0 + 0xB0) | 0xC0000, NULL);

    sp10 = arg0 + 0x110;

    for (i = 0; i < 7; ++i) {
        var_s0 = 0x808080;
        temp_s3 = vs_mainMenu_inventoryItemCapacities[i];
        temp_s4 = vs_mainMenu_getItemCount(i, NULL);

        if (var_s6 != NULL) {
            var_s0_2 = 0;
            if ((var_s6 == (D_8010A6A0_t*)1) || (func_80108264(i, var_s6) != 0)) {
                var_s0_2 = 1;
            }
            var_s0 = 0x404040 << var_s0_2;
        }
        new_var2 = 0x180000;
        var_s2 = (new_var2 + i * 0xC0000);
        vs_battle_renderTextRawColor("/", sp10 | var_s2, var_s0, NULL);
        vs_battle_renderTextRawColor(D_8010A5CC[i], (arg0 + 0xC0) | var_s2, var_s0, NULL);
        vs_mainMenu_printIntColor(temp_s3, (arg0 + 0x128) | var_s2, var_s0, NULL);

        if (((u_int)var_s0 >> 0x17) != 0) {
            if ((temp_s4 * 2) < (int)temp_s3) {
                var_s0 = 0x804020;
            }
            if (((u_long)var_s6 >> 1) != 0) {
                if (temp_s3 < (func_80108264(i, var_s6) + temp_s4)) {
                    var_s0 = 0x204080;
                }
            }
        }
        vs_mainMenu_printIntColor(temp_s4, sp10 | var_s2, var_s0, NULL);
    }

    temp_s0 = arg0 + 0xB8;
    vs_mainMenu_drawButtonUiBackground(temp_s0, 0x70, 0x70, 0xA);
    vs_mainMenu_drawButtonUiBackground(temp_s0, 0x80, 0x40, 0xA);
    vs_battle_renderTextRawColor(
        "GET", (arg0 + 0xC4) | 0x700000, 0x404040 << D_8010A505, NULL);
    vs_mainmenu_drawButton(2, arg0 + 0xB0, 0x6E, NULL);

    c = "ALL";
    new_var = (arg0 + 0xFC) | 0x700000;
    if (var_fp != 0) {
        var_a2 = 0x404040 << (D_8010A505 & 1);
    } else {
        var_a2 = 0x404040;
    }

    vs_battle_renderTextRawColor(c, new_var, var_a2, NULL);
    vs_mainmenu_drawButton(1, arg0 + 0xE8, 0x6E, NULL);
    vs_battle_renderTextRawColor(
        "END", (arg0 + 0xC4) | 0x800000, 0x404040 << D_8010A505, NULL);
    vs_mainmenu_drawButton(3, arg0 + 0xB0, 0x7E, NULL);
}

int func_801086DC(int arg0) { return arg0 & (vs_main_stateFlags.unk1 + 1); }

void _applyDropList(func_8006BE64_t2* arg0)
{
    int i;

    if (func_801086DC(arg0->weapon.unk0) != 0) {
        func_8010822C(0, _copyWeaponToInventory(&arg0->weapon));
    }

    if (func_801086DC(arg0->unkB0.unk0) != 0) {
        func_8010822C(1, _copyBladeToInventory(&arg0->unkB0.blade, 0));
    }

    if (func_801086DC(arg0->unkE0.unk0) != 0) {
        func_8010822C(2, _copyGripToInventory(&arg0->unkE0.grip, 0));
    }

    if (func_801086DC(arg0->shield.unk0) != 0) {
        func_8010822C(3, _copyShieldToInventory(&arg0->shield));
    }

    for (i = 0; i < 2; ++i) {
        if (func_801086DC(arg0->armor[i].unk0) != 0) {
            func_8010822C(4, _copyArmorToInventory(&arg0->armor[i].armor));
        }
    }

    if (func_801086DC(arg0->accessory.unk0) != 0) {
        func_8010822C(4, _copyArmorToInventory(&arg0->accessory.accessory));
    }

    if (func_801086DC(arg0->gem.unk0) != 0) {
        func_8010822C(5, _copyGemToInventory(&arg0->gem.gem, 0));
    }

    for (i = 0; i < 3; ++i) {
        if ((func_801086DC(arg0->misc[i].count) != 0) && (arg0->misc[i].id != 0)
            && (arg0->misc[i].index != 0)) {
            func_8010822C(6, _copyMiscToInventory(&arg0->misc[i]));
        }
    }
    func_801080F0();
}

void func_801088D4(func_801088D4_t* arg0)
{
    vs_battle_rMemzero(_inventory, sizeof *_inventory);

    if (arg0 != 0) {
        while (arg0 != 0) {
            _applyDropList(&arg0->unk8);
            arg0 = arg0->next;
        }
    } else {
        _applyDropList(D_800EB9C8);
    }
}

void func_80108938(int arg0)
{
    char sp18[0x100];
    int sp118;
    D_8010A6A0_t* var_fp;
    int i;
    int temp_s1;
    int temp_v1_3;
    vs_battle_inventoryWeapon* weapon;
    vs_battle_inventoryBlade* blade;
    vs_battle_inventoryBlade* blade2;
    vs_battle_inventoryGrip* grip;
    vs_battle_inventoryShield* shield;
    vs_battle_inventoryArmor* armor;
    vs_battle_inventoryGem* gem;
    vs_battle_inventoryMisc* misc;
    vs_battle_menuItem_t* menuItem;

    sp118 = D_8010A6B6;
    var_fp = &D_8010A6A0[D_8010A6B5];
    vs_battle_rMemzero(&sp18, 0x100);

    for (i = 0; i < 8; ++i) {
        menuItem = vs_battle_getMenuItem(i + 0x20);
        sp18[i + D_8010A504] = menuItem->unk4;
        menuItem->state = 0;
    }

    if (sp118 >= 9) {
        sp118 = 8;
    }

    for (i = 0; i < sp118;) {
        temp_s1 = var_fp->unk1;
        menuItem = vs_battle_getMenuItem(0x20 + i);

        switch (var_fp->unk0) {
        case 0:
            weapon = &_inventory->weapons[temp_s1];
            blade = &_inventory->blades[weapon->blade - 1];
            menuItem = vs_battle_setMenuItem(
                0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98, 0, weapon->name);
            menuItem->icon = blade->category;
            menuItem->material = blade->material;
            break;
        case 1:
            blade2 = &_inventory->blades[temp_s1];
            menuItem = vs_battle_setMenuItem(0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98,
                0, vs_mainMenu_itemNames[blade2->id]);
            menuItem->icon = blade2->category;
            menuItem->material = blade2->material;
            break;
        case 2:
            grip = &_inventory->grips[temp_s1];
            menuItem = vs_battle_setMenuItem(0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98,
                0, vs_mainMenu_itemNames[grip->id]);
            menuItem->icon = grip->category + 10;
            break;
        case 3:
            shield = &_inventory->shields[temp_s1];
            menuItem = vs_battle_setMenuItem(0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98,
                0, vs_mainMenu_itemNames[shield->base.id]);
            menuItem->icon = 0xF;
            menuItem->material = shield->base.material;
            break;
        case 4:
            armor = &_inventory->armor[temp_s1];
            menuItem = vs_battle_setMenuItem(0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98,
                0, vs_mainMenu_itemNames[armor->id]);
            menuItem->icon = armor->category + 0xE;
            menuItem->material = armor->material;
            break;
        case 5:
            gem = &_inventory->gems[temp_s1];
            menuItem = vs_battle_setMenuItem(0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98,
                0, vs_mainMenu_itemNames[gem->id]);
            menuItem->icon = 22;
            break;
        case 6:
            misc = &_inventory->items[temp_s1];
            menuItem = vs_battle_setMenuItem(0x20 + i, 0x18 - arg0, 0x32 + i * 0x10, 0x98,
                0, vs_mainMenu_itemNames[misc->id]);
            menuItem->unk10 = misc->count;
            menuItem->unkA = (misc->id < 0x1CA) ^ 1;
            break;
        }
        menuItem->unk4 = sp18[i + D_8010A6B5];
        menuItem->unk7 = var_fp->unk3 == 0;

        if (var_fp->unk2 != 0) {
            menuItem->initialX -= var_fp->unk2 * 0x30;
            ++var_fp->unk2;
            if (var_fp->unk2 == 4) {
                menuItem->unk4 = 0;
            }
        }
        if (i == 0) {
            if (D_8010A6B5 != 0) {
                menuItem->unk5 = 1;
            }
        }
        if ((i == 7) && (D_8010A6B5 != (D_8010A6B6 - 8))) {
            menuItem->unk5 = 2;
        }
        temp_v1_3 = var_fp->unk3;
        if (temp_v1_3 == 2) {
            menuItem->unk2 = 0x18;
        }
        if (temp_v1_3 >= 3) {
            menuItem->initialX += (temp_v1_3 - 3) * 7;
        }
        ++i;
        ++var_fp;
    }
    D_8010A504 = D_8010A6B5;
}

void func_80108E78(int arg0)
{
    char* menuText[2];
    int rowType;
    int temp_s3 = D_8010A6A0[arg0].unk1;

    vs_battle_memcpy(D_8010A6AC, &vs_battle_inventory, sizeof *D_8010A6AC);
    vs_battle_memcpy(&vs_battle_inventory, _inventory, sizeof vs_battle_inventory);

    switch (D_8010A6A0[arg0].unk0) {
    case 0:
        vs_mainMenu_initUiWeapon(&vs_battle_inventory.weapons[temp_s3], menuText,
            &rowType, vs_battle_stringBuf);
        break;
    case 1:
        vs_mainMenu_setBladeUi(&vs_battle_inventory.blades[temp_s3], menuText, &rowType,
            vs_battle_stringBuf);
        break;
    case 2:
        vs_mainMenu_setGripUi(
            &vs_battle_inventory.grips[temp_s3], menuText, &rowType, vs_battle_stringBuf);
        break;
    case 3:
        vs_mainMenu_initUiShield(&vs_battle_inventory.shields[temp_s3], menuText,
            &rowType, vs_battle_stringBuf);
        break;
    case 4:
        vs_mainMenu_setAccessoryUi(
            &vs_battle_inventory.armor[temp_s3], menuText, &rowType, vs_battle_stringBuf);
        break;
    case 5:
        vs_mainMenu_setGemUi(
            &vs_battle_inventory.gems[temp_s3], menuText, &rowType, vs_battle_stringBuf);
        break;
    case 6:
        vs_mainMenu_setItemUi(
            &vs_battle_inventory.items[temp_s3], menuText, &rowType, vs_battle_stringBuf);
        break;
    }
    vs_mainmenu_setMessage(menuText[1]);
    vs_battle_memcpy(&vs_battle_inventory, D_8010A6AC, sizeof vs_battle_inventory);
}

int func_801090A4(int arg0)
{
    static char D_8010A5E8 = 0;

    static char D_8010A691;
    static char D_8010A692;
    static char _ __attribute__((unused));
    static char* D_8010A694;

    int i;
    int var_v1;
    int temp_a1;
    vs_battle_menuItem_t* menuItem;

    if (arg0 != 0) {
        D_8010A692 = 1;
        D_8010A691 = 0;
        if (D_8010A6B6 == 0) {
            D_8010A691 = 4;
            return 0;
        }
        if ((D_8010A6B8 == 0) && (D_800EB9C8 != NULL)) {
            D_8010A691 = 5;
            return 0;
        }

        for (i = 0; i < D_8010A6B6; ++i) {
            temp_a1 = D_8010A6A0[i].unk0;
            if (temp_a1 == 6) {
                if (_inventory->items[D_8010A6A0[i].unk1].id >= 0x1CA) {
                    D_8010A694 =
                        vs_mainMenu_itemNames[_inventory->items[D_8010A6A0[i].unk1].id];
                    D_8010A691 = temp_a1;
                }
            }
        }
        return 0;
    }
    switch (D_8010A691) {
    case 0:
        menuItem = vs_battle_setMenuItem(
            0x1E, 0x140, 0x92, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionYes]);
        menuItem->state = 2;
        menuItem->targetX = 0xC2;
        D_8010A691 = 1;
        break;
    case 1:
        menuItem = vs_battle_setMenuItem(
            0x1F, 0x140, 0xA2, 0x7E, 0, (char*)&_menuText[VS_menuText_OFFSET_optionNo]);
        menuItem->state = 2;
        menuItem->targetX = 0xC2;
        func_800C8E04(1);
        vs_mainmenu_setMessage(
            D_8010A6B8 == 0 ? (char*)(&_menuText[VS_menuText_OFFSET_discardAllConfirm])
                            : (char*)(&_menuText[VS_menuText_OFFSET_itemsRemaining]));
        D_8010A691 = 2;
        break;
    case 2:
        D_8010A691 = (D_8010A691 + vs_mainmenu_ready());
        break;
    case 3:
        vs_battle_getMenuItem(D_8010A692 + 0x1E)->selected = 1;
        vs_battle_getMenuItem(0x1F - D_8010A692)->selected = 0;
        if (vs_main_buttonsPressed.all & 0x60) {
            vs_mainMenu_menuItemLeaveRight(0x1E);
            vs_mainMenu_menuItemLeaveRight(0x1F);
            if (vs_main_settings.information == 0) {
                func_800FFBA8();
            }
            if ((D_8010A692 == 0) && !(vs_main_buttonsPressed.all & 0x40)) {
                vs_main_playSfxDefault(0x7E, 0x1C);
                var_v1 = 1;
                if (D_8010A6B8 == 0) {
                    var_v1 = 2;
                }
                return var_v1;
            }
            vs_battle_playMenuLeaveSfx();
            return -1;
        }
        if (vs_main_buttonRepeat & 0x5000) {
            vs_battle_playMenuChangeSfx();
            D_8010A692 = (1 - D_8010A692);
        }
        D_8010A5E8 = vs_battle_drawCursor(D_8010A5E8, D_8010A692 + 8);
        break;
    case 4:
    case 5:
        return D_8010A691 - 3;
    case 6:
        vs_battle_stringContext.strings[0] = D_8010A694;
        func_800C8E04(1);
        vs_mainmenu_setMessage((char*)&_menuText[VS_menuText_OFFSET_invalidDiscard]);
        D_8010A691 = 7;
        /* fallthrough */
    case 7:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            vs_battle_playMenuLeaveSfx();
            return -1;
        }
        break;
    }
    return 0;
}

int func_80109444(D_8010A6A0_t* arg0)
{
    static char D_8010A5E9 = 0;

    static char D_8010A698;
    static char D_8010A699;
    static char D_8010A69A;
    static char D_8010A69B;

    vs_battle_menuItem_t* temp_v0;

    if (arg0 != NULL) {
        func_800FFBC8();
        D_8010A699 = arg0->unk0;
        D_8010A698 = 0;
        D_8010A69A = 0;
        D_8010A69B = 0;

        if (D_8010A699 == 0) {
            D_8010A69B = VS_menuText_INDEX_disassemble - 9;
        } else if (D_8010A699 == 3) {
            D_8010A69B = VS_menuText_INDEX_disassemble - 9;
        } else if ((D_8010A699 == 6) && (_inventory->items[arg0->unk1].id < 0x1CA)) {
            D_8010A69B = VS_menuText_INDEX_organize - 10;
        } else {
            D_8010A69A = VS_menuText_INDEX_disassemble - 9;
        }

        if (D_8010A69B != 0) {
            temp_v0 = vs_battle_setMenuItem(0x1E, 0x140, 0x92, 0x7E, 0,
                (char*)&_menuText[_menuText[(D_8010A69B + 4) * 2]]);
            temp_v0->state = 2;
            temp_v0->targetX = 0xC2;
        }
        return 0;
    }

    switch (D_8010A698) {
    case 0:
        temp_v0 = vs_battle_setMenuItem(0x1F, 0x140, 0xA2, 0x7E, 0,
            (char*)&_menuText[VS_menuText_OFFSET_organizeInventory]);
        temp_v0->state = 2;
        temp_v0->targetX = 0xC2;
        D_8010A698 = 1;
        break;
    case 1:
        D_8010A698 += vs_mainmenu_ready();
        break;
    case 2:
        vs_battle_getMenuItem(D_8010A69A + 0x1E)->selected = 1;
        vs_battle_getMenuItem(0x1F - D_8010A69A)->selected = 0;
        if (vs_main_buttonsPressed.all & 0x60) {
            vs_mainMenu_menuItemLeaveRight(0x1E);
            vs_mainMenu_menuItemLeaveRight(0x1F);
            if (vs_main_buttonsPressed.all & 0x40) {
                vs_battle_playMenuLeaveSfx();
                return -1;
            }
            vs_battle_playMenuSelectSfx();
            if (D_8010A69A == 0) {
                D_8010A69A = D_8010A69B + 1;
            }
            return D_8010A69A;
        }
        if (D_8010A69B != 0) {
            if (vs_main_buttonRepeat & 0x5000) {
                vs_battle_playMenuChangeSfx();
                D_8010A69A = 1 - D_8010A69A;
            }
        }
        if (D_8010A69A != 0) {
            vs_mainmenu_setMessage(
                (char*)&_menuText[VS_menuText_OFFSET_organizeInventoryInfo]);
        } else if (D_8010A69B == 1) {
            vs_mainmenu_setMessage((char*)&_menuText[VS_menuText_OFFSET_disassembleInfo]);
        } else {
            vs_mainmenu_setMessage((char*)&_menuText[VS_menuText_OFFSET_organizeInfo]);
        }
        D_8010A5E9 = vs_battle_drawCursor(D_8010A5E9, D_8010A69A + 8);
        break;
    }
    return 0;
}

int func_80109750(int arg0)
{
    static char D_8010A5EA = 0;

    static char D_8010A69C;
    static char D_8010A69D;

    D_8010A6A0_t* temp_s1;
    int temp_a3;
    int temp_s2;
    int i;
    int var_v0_4;
    int temp_a0;

    if (arg0 != 0) {
        D_8010A6B4 = 0;
        D_8010A69C = 0;
        return 0;
    }
    switch (D_8010A69C) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_800FFBC8();
        D_8010A69C = 1;
        // Fallthrough
    case 1:
        D_8010A505 = 1;
        if (vs_main_buttonsPressed.all & 0x40) {
            vs_battle_playMenuLeaveSfx();
            D_8010A505 = 0;
            func_801090A4(1);
            D_8010A69C = 2;
            break;
        } else if (vs_main_buttonsPressed.all & 0x80) {
            temp_s2 = D_8010A6B8;
            for (i = 0; i < D_8010A6B6; ++i) {
                temp_s1 = &D_8010A6A0[i];
                if (func_800FEB94(temp_s1->unk0 | 0x10, &vs_battle_inventory,
                        temp_s1->unk1, _inventory)
                    != 0) {
                    if (temp_s1->unk0 == 6) {
                        temp_a0 = _inventory->items[temp_s1->unk1].id;
                        if (temp_a0 >= 0x1CA) {
                            func_8010A24C(temp_a0);
                        }
                    }
                    temp_s1->unk2 = 1;
                    ++D_8010A6B8;
                }
            }
            if (temp_s2 != D_8010A6B8) {
                vs_main_playSfxDefault(0x7E, 0xD);
                D_8010A69C = 9;
                break;
            }
            func_800C02E0();
        }
        temp_a3 = D_8010A6B4 + D_8010A6B5;
        temp_s1 = &D_8010A6A0[temp_a3];
        if (vs_main_buttonsPressed.all & 0x20) {
            if (temp_s1->unk3 == 0) {
                vs_battle_playMenuSelectSfx();
                D_8010A505 = 0;
                func_80109444(temp_s1);
                D_8010A69C = 3;
            } else {
                vs_main_playSfxDefault(0x7E, 0xD);
                if (temp_s1->unk0 == 6) {
                    i = _inventory->items[temp_s1->unk1].id;
                    if (i >= 0x1CA) {
                        func_8010A24C(i);
                    }
                }
                func_800FEB94(temp_s1->unk0 | 0x10, &vs_battle_inventory, temp_s1->unk1,
                    _inventory);
                temp_s1->unk2 = 1;
                D_8010A69D = 3;
                ++D_8010A6B8;
                D_8010A69C = 9;
            }
        } else {
            i = temp_a3;
            if (vs_main_buttonRepeat & 0x1000) {
                if (D_8010A6B6 < 9) {
                    if (D_8010A6B4 == 0) {
                        D_8010A6B4 = D_8010A6B6 - 1;
                    } else {
                        --D_8010A6B4;
                    }
                } else {
                    if (D_8010A6B5 == 0) {
                        if (D_8010A6B4 == 0) {
                            if (vs_main_buttonsPressed.all & 0x1000) {
                                D_8010A6B4 = 7;
                                D_8010A6B5 = D_8010A6B6 - 8;
                            }
                        } else {
                            --D_8010A6B4;
                        }
                    } else {
                        if (D_8010A6B4 == 1) {
                            --D_8010A6B5;
                        } else {
                            --D_8010A6B4;
                        }
                    }
                }
            }
            if (vs_main_buttonRepeat & 0x4000) {
                if (D_8010A6B6 < 9) {
                    if (D_8010A6B4 == (D_8010A6B6 - 1)) {
                        D_8010A6B4 = 0;
                    } else {
                        ++D_8010A6B4;
                    }
                } else if (D_8010A6B5 == (D_8010A6B6 - 8)) {
                    if (D_8010A6B4 == 7) {
                        if (vs_main_buttonsPressed.all & 0x4000) {
                            D_8010A6B4 = 0;
                            D_8010A6B5 = 0;
                        }
                    } else {
                        ++D_8010A6B4;
                    }
                } else if (D_8010A6B4 == 6) {
                    ++D_8010A6B5;
                } else {
                    ++D_8010A6B4;
                }
            }
            if (i != (D_8010A6B4 + D_8010A6B5)) {
                vs_battle_playMenuChangeSfx();
            }
            func_80108E78(D_8010A6B4 + D_8010A6B5);
            D_8010A5EA =
                func_800FFCDC(D_8010A5EA, (((D_8010A6B4 * 0x10) + 0x2A) << 0x10) | 0xA);
        }
        break;
    case 2:
        i = func_801090A4(0);
        if (i != 0) {
            if (i < 0) {
                D_8010A69C = 8;
            } else {
                return i;
            }
        }
        break;
    case 3:
        i = func_80109444(NULL);
        if (i != 0) {
            if (i >= 0) {
                temp_s2 = D_8010A6B4 + D_8010A6B5;
                switch (i) {
                case 1:
                    func_801066CC(D_8010A6A0[temp_s2].unk0 + 1);
                    D_8010A69C = 4;
                    break;
                case 2:
                    func_80106B80(temp_s2 + 1);
                    D_8010A69C = 5;
                    break;
                case 3:
                    func_801073E0(temp_s2 + 1);
                    D_8010A69C = 6;
                    break;
                }
            } else {
                D_8010A69C = 0;
            }
        }
        break;
    case 4:
        var_v0_4 = func_801066CC(0);
        if (var_v0_4 != 0) {
            D_8010A69C = 8;
        }
        break;
    case 5:
        var_v0_4 = func_80106B80(0);
        if (var_v0_4 != 0) {
            D_8010A69C = 8;
        }
        break;
    case 6:
        var_v0_4 = func_801073E0(0);
        if (var_v0_4 != 0) {
            D_8010A69C = 8;
        }
        break;
    case 7:
        if (vs_main_buttonsPressed.all == 0) {
            break;
        }
    // Fallthrough
    case 8:
        if (D_8010A6B3 == 0) {
            D_8010A505 = 1;
            D_8010A69C = 0;
            func_801080F0();
        }
        break;
    case 9:
        if (D_8010A69D != 0) {
            D_8010A69D = (D_8010A69D - 1);
        } else {
            while (1) {
                for (i = 0; i < D_8010A6B6; ++i) {
                    if (D_8010A6A0[i].unk2 != 0) {
                        break;
                    }
                }

                if (i == D_8010A6B6) {
                    break;
                }

                --D_8010A6B6;
                for (; i < D_8010A6B6; ++i) {
                    D_8010A6A0[i] = D_8010A6A0[i + 1];
                }
            }
            func_801080F0();
            if (D_8010A6B6 == 0) {
                D_8010A505 = 0;
                func_801090A4(1);
                D_8010A69C = 2;
            } else {
                D_8010A69C = 0;
            }
        }
        break;
    }
    D_8010A6B7 = (D_8010A69C & 7) == 1 ? D_8010A6B4 + 1 : -0x80;
    return 0;
}

int func_80109E90(char* state)
{
    static char D_8010A69E;
    static char _ __attribute__((unused));

    int i;
    void* temp_v0;

    D_8010A6B7 = 0;

    switch (*state) {
    case 0:
        vs_battle_playSfx10();
        func_800FBD80(16);
        for (i = 0; i < 7; ++i) {
            vs_mainMenu_rebuildInventory(i);
        }
        temp_v0 = vs_main_allocHeapR(0x2300);
        _inventory = temp_v0;
        D_8010A6AC = temp_v0 + 0xF00;
        D_8010A6A0 = temp_v0 + 0x1E00;
        D_8010A6A4 = temp_v0 + 0x2080;
        D_8010A6B8 = 0;
        D_8010A6B6 = 0;
        D_8010A6B5 = 0;
        D_8010A69E = 0;
        vs_mainMenu_loadItemNames(1);
        func_801088D4(D_800EB9C4);
        D_8010A505 = 0;
        D_8010A6B0 = 1;
        D_8010A6B1 = 10;
        D_8010A6B2 = 0;
        D_8010A6B3 = 10;
        *state = 1;
        break;
    case 1:
        if (vs_mainMenu_loadItemNames(0) != 0) {
            D_8010A6B2 = 1;
            if (D_8010A6B6 == 0) {
                func_800C8E04(1);
                vs_mainmenu_setMessage((char*)&_menuText[VS_menuText_OFFSET_emptyChest]);
                *state = 4;
            } else {
                func_800FFBC8();
                *state = 2;
            }
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (D_8010A6B3 == 0) {
                func_80109750(1);
                *state = 3;
            case 3:
                i = func_80109750(0);
                if (i != 0) {
                    D_800F4E98.unk2 = i == 1;
                    *state = 5;
                }
            }
        }
        break;
    case 4:
        if ((D_800F5130 >> 0x1E) & 1) {
            if (vs_main_buttonsPressed.pad[0].low != 0) {
                *state = 5;
            }
        }
        break;
    case 5:
        D_8010A6B0 = 0;
        D_8010A6B2 = 0;
        if (func_800CD064(7) == 0) {
            if (vs_mainMenu_ensureItemNamesLoaded() != 0) {
                vs_main_freeHeapR(_inventory);
                if (D_800EB9C4 != 0) {
                    func_8008A6FC();
                }
                *state = 0;
                return 1;
            }
        }
        break;
    }
    if (D_8010A6B0 != 0) {
        if (D_8010A6B1 != 0) {
            --D_8010A6B1;
        }
        i = vs_battle_rowAnimationSteps[D_8010A6B1];
    } else {
        if (D_8010A6B1 < 10) {
            ++D_8010A6B1;
        }
        i = D_8010A6B1 << 5;
    }
    if (D_8010A6B1 < 10) {
        func_8010837C(i);
    }
    if (D_8010A6B2 != 0) {
        if (D_8010A6B3 != 0) {
            --D_8010A6B3;
        }
        i = vs_battle_rowAnimationSteps[D_8010A6B3];
    } else {
        if (D_8010A6B3 < 10) {
            ++D_8010A6B3;
        }
        i = D_8010A6B3 << 5;
    }
    if (D_8010A6B3 < 10) {
        func_80108938(i);
        if (D_8010A6B7 & 0xF) {
            vs_battle_getMenuItem(D_8010A6B7 + 0x1F)->selected = 1;
        }
    }
    return 0;
}

void func_8010A24C(int arg0)
{
    if (arg0 >= 0x1CA) {
        func_800BEC14(arg0 + 0x1B6, 1);
    }
}
