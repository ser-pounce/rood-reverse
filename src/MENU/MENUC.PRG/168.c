#include "common.h"
#include "168.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../assets/MENU/MENU12.BIN.h"
#include "vs_string.h"
#include <libetc.h>
#include <memory.h>

void func_8010B2B4(vs_battle_inventoryBlade*, vs_battle_inventoryBlade*,
    vs_battle_inventoryBlade*, void*);
int func_80104898(int);
int func_801057BC(int);
vs_battle_menuItem_t* func_801077DC(int, int);
void func_80107EBC(vs_battle_menuItem_t*, vs_battle_inventoryBlade*);
void func_8010B598(vs_battle_inventoryArmor*, vs_battle_inventoryArmor*,
    vs_battle_inventoryArmor*, void*);
void func_8010B80C(vs_battle_inventoryArmor*, vs_battle_inventoryArmor*,
    vs_battle_inventoryArmor*, void*);
int func_8010BA58(int);

extern void* _sydData;
extern int _sydLbas[];
extern int _sydSizes[];
extern vs_main_CdQueueSlot* _sydCdQueueSlot;
extern char _sydFileLoading;

extern char D_8010BB20;
extern char D_8010BB2E;
extern char D_8010BB56;
extern char D_8010BB57;
extern char D_8010BB74;
extern u_short _validGripFlags[];
extern char D_8010BBF4;
extern char D_8010BBF5;
extern char D_8010BBF6;
extern char D_8010BBF7;
extern char D_8010BBF8;
extern int D_8010BBFC;
extern char D_8010BB21;
extern char D_8010BB30[];
extern char D_8010BB75;
extern char D_8010BB76;
extern int (*D_8010BB78[])(int);
extern u_char _combiningItem;
extern char D_8010BC00;
extern char D_8010BC01;
extern char D_8010BC02;
extern int D_8010BC04;
extern char D_8010BC08;
extern char D_8010BC09;
extern char D_8010BC0A;
extern int D_8010BC0C;
extern char D_8010BC10;
extern char D_8010BC11;
extern int D_8010BC1C;
extern char D_8010BC20;
extern char D_8010BC21;
extern u_char D_8010BC22;
extern char D_8010BC23;
extern char D_8010BC24;
extern char D_8010BC28[4];
extern char D_8010BC2C[4];
extern u_char* D_8010BC30;
extern char D_8010BC34;
extern char D_8010BC35;
extern int D_8010BC38;
extern char D_8010BC3C;
extern char D_8010BC3D;
extern char D_8010BC3E;
extern char D_8010BC3F;
extern char D_8010BC41;
extern int D_8010BC44;
extern char D_8010BC48;
extern char D_8010BC49;
extern int D_8010BC4C;
extern char D_8010BC50;
extern int D_8010BC5C;
extern char D_8010BC60;
extern char D_8010BC61;
extern char D_8010BC62;
extern char D_8010BC63;
extern char D_8010BC64;
extern int D_8010BC68;
extern char D_8010BC6C;
extern char D_8010BC6D;
extern char D_8010BC6E;
extern char D_8010BC6F;
extern char D_8010BC70;
extern int D_8010BC74;
extern char D_8010BC78;
extern char D_8010BC79;
extern char D_8010BC7A;
extern char D_8010BC7B;
extern char D_8010BC7C;
extern char D_8010BC7D;
extern char D_8010BC7E;
extern char D_8010BC7F;
extern u_char _isLocationWorkshop;
extern u_int D_8010BC84[5];
extern u_short* D_8010BC98;
extern int D_8010BC9C;
extern char D_8010BCA0;
extern char D_8010BCA1;
extern char D_8010BCA2;
extern char D_8010BCA3;
extern char D_8010BCA4[];
extern vs_battle_inventoryBlade D_8010BCE4;
extern char D_8010BD10[2];
extern vs_battle_inventoryShield D_8010BD14;
extern char D_8010BD18;
extern u_char D_8010BD44[];
extern vs_battle_inventoryArmor D_8010BD54;
extern char D_8010BD7C[2];

extern u_long* D_1F800000[];

void func_80102968(int arg0, int arg1)
{
    func_800C6540("OK", (((arg0 * 0x10) + 0x20) << 0x10) | 0xAF,
        ((rsin(arg1 * 8) >> 5) + 0x40) * 0x10101, D_1F800000[1] - 3);
}

void func_801029D0(int arg0, int arg1)
{
    vs_battle_menuItem_t* temp_v0;

    int var_a2 = 0x12;
    if (arg0 != 0) {
        var_a2 = 0x22;
    }
    temp_v0 = vs_battle_setMenuItem(
        arg0, 0x140, var_a2, 0x8C, 8, (char*)&vs_mainMenu_menu12Text[arg1]);
    temp_v0->state = 2;
    temp_v0->x = 0xB4;
    temp_v0->selected = 1;
}

void func_80102A34(int arg0)
{
    u_int i;
    u_int var_t0;

    var_t0 = 0;
    if (arg0 < 5) {
        for (i = 0; i < 5; ++i) {
            if (var_t0 < D_8010BC84[i]) {
                var_t0 = D_8010BC84[i];
            }
        }

        D_8010BC84[arg0] = var_t0 + 1;
        return;
    }
    vs_battle_rMemzero(D_8010BC84, sizeof D_8010BC84);
}

int func_80102AB8(int arg0)
{
    int i;
    int var_a2 = 0;

    if (arg0 < 5) {
        D_8010BC84[arg0] = 0;
    } else {
        for (i = 0; i < 5; ++i) {
            if (D_8010BC84[var_a2] < D_8010BC84[i]) {
                var_a2 = i;
            }
        }

        if (D_8010BC84[var_a2] != 0) {
            D_8010BC84[var_a2] = 0;
            return var_a2 + 1;
        }
    }
    return 0;
}

void func_80102B50(int arg0, int arg1)
{
    vs_battle_menuItem_t* temp_v0 = vs_battle_setMenuItem(
        0x20, -0xA4, 0x12, 0xA4, 8, (char*)&vs_mainMenu_menu12Text[arg0]);
    temp_v0->state = 5;
    temp_v0->x = 0x10;
    temp_v0->selected = 1;
    temp_v0->flags = arg1;
    vs_mainMenu_resetStats();
    arg0 = 7;
    if (arg1 == 0x18) {
        vs_mainMenu_setRangeRisk(0, 0, 0, 1);
        arg0 = 3;
    }
    func_800FBBD4(arg0);
    arg0 = 3;
    if (arg1 == 0x1C) {
        arg0 = 1;
    }
    vs_mainMenu_drawDpPpbars(arg0);
    func_800FBEA4(1);
}

void func_80102C0C(int arg0, int arg1)
{
    if (arg0 != arg1) {
        vs_battle_copyAligned(
            &vs_battle_menuItems[arg1], &vs_battle_menuItems[arg0], 0x40);
        func_800FFB90(arg0);
    }
}

int func_80102C58(int arg0)
{
    int i;
    int var_s1;
    vs_battle_menuItem_t* temp_v0_2;

    var_s1 = 0;

    if (arg0 != 0) {
        func_800C8E04(1);
        D_8010BBF5 = 0;
        D_8010BBF4 = 0;
        return 0;
    }

    switch (D_8010BBF4) {
    case 0:
    case 1:
        temp_v0_2 = vs_battle_setMenuItem(D_8010BBF4 + 0x1D, 0x140,
            (D_8010BBF4 * 0x10) + 0x92, 0x7E, 0,
            (char*)&vs_mainMenu_menu12Text
                [vs_mainMenu_menu12Text[D_8010BBF4 + VS_MENU12_BIN_INDEX_optionYes]]);
        temp_v0_2->state = 2;
        temp_v0_2->x = 0xC2;
        D_8010BBF4 = (char)(D_8010BBF4 + 1);
        break;
    case 2:
        D_8010BBF4 += vs_mainmenu_ready();
        break;
    case 3:
        for (i = 0; i < 2; ++i) {
            vs_battle_getMenuItem(i + 0x1D)->selected = (i ^ D_8010BBF5) == 0;
        }
        if (vs_main_buttonsPressed.all & 0x10) {
            var_s1 = 3;
        } else if (vs_main_buttonsPressed.all & 0x40) {
            var_s1 = 2;
        } else if (vs_main_buttonsPressed.all & 0x20) {
            var_s1 = D_8010BBF5 + 1;
        } else {
            if (vs_main_buttonRepeat & 0x5000) {
                vs_battle_playMenuChangeSfx();
                D_8010BBF5 = 1 - D_8010BBF5;
            }
            D_8010BB20 = vs_battle_drawCursor(D_8010BB20, D_8010BBF5 + 8);
        }
        break;
    }

    if (var_s1 != 0) {
        if (var_s1 == 2) {
            vs_battle_playMenuLeaveSfx();
        }
        for (i = 0x1D; i < 0x1F; ++i) {
            func_800FA8A0(i);
        }
    }

    return var_s1;
}

int func_80102E40(int arg0)
{
    int i;
    int var_s2;
    u_short* var_v0_2;
    vs_battle_menuItem_t* temp_v0_2;

    var_s2 = 0;
    if (arg0 != 0) {
        func_800C8E04(1);
        D_8010BBF8 = arg0;
        D_8010BBF7 = 0;
        D_8010BBF6 = 0;
        return 0;
    }

    switch (D_8010BBF6) {
    case 0:
    case 1:
    case 2:
        var_v0_2 =
            &vs_mainMenu_menu12Text
                [vs_mainMenu_menu12Text[D_8010BBF6 + VS_MENU12_BIN_INDEX_optionYes]];
        if (D_8010BBF6 == D_8010BBF8) {
            var_v0_2 = vs_mainMenu_menu12Text + VS_MENU12_BIN_OFFSET_cancelCombine;
        }
        temp_v0_2 = vs_battle_setMenuItem(D_8010BBF6 + 0x1D, 0x140,
            (D_8010BBF6 * 0x10) + 0x82, 0x7E, 0, (char*)var_v0_2);
        temp_v0_2->state = 2;
        temp_v0_2->x = 0xC2;
        ++D_8010BBF6;
        break;
    case 3:
        D_8010BBF6 += vs_mainmenu_ready();
        break;
    case 4:
        for (i = 0; i < 3; ++i) {
            vs_battle_getMenuItem(i + 0x1D)->selected = (i ^ D_8010BBF7) == 0;
        }
        if (vs_main_buttonsPressed.all & 0x10) {
            var_s2 = 3;
        } else if (vs_main_buttonsPressed.all & 0x40) {
            var_s2 = 2;
        } else if (vs_main_buttonsPressed.all & 0x20) {
            var_s2 = D_8010BBF7 + 1;
        } else {
            i = D_8010BBF7;
            if (vs_main_buttonRepeat & 0x1000) {
                i += 2;
            }
            if (vs_main_buttonRepeat & 0x4000) {
                ++i;
            }
            if (i >= 3) {
                i -= 3;
            }
            if (i != D_8010BBF7) {
                vs_battle_playMenuChangeSfx();
                D_8010BBF7 = i;
            }
            D_8010BB21 = vs_battle_drawCursor(D_8010BB21, D_8010BBF7 + 7);
        }
        break;
    }

    if (var_s2 != 0) {
        if (var_s2 == 2) {
            vs_battle_playMenuLeaveSfx();
        }
        for (i = 0x1D; i < 0x20; ++i) {
            func_800FA8A0(i);
        }
    }
    return var_s2;
}

void _disassembleWeapon(int weaponIndex)
{
    int i;
    int index;
    vs_battle_inventoryWeapon* weapon = &vs_battle_inventory.weapons[weaponIndex];

    if (weapon->blade == 0) {
        return;
    }

    for (i = 0; i < vs_battle_inventory.grips[weapon->grip - 1].gemSlots; ++i) {
        index = weapon->gems[i];
        if (index != 0) {
            vs_battle_inventory.gems[index - 1].setItemIndex = 0;
            weapon->gems[i] = 0;
        }
    }

    vs_battle_inventory.grips[weapon->grip - 1].combinedWeaponIndex = 0;
    vs_battle_inventory.blades[weapon->blade - 1].combinedWeaponIndex = 0;
    index = weapon->index;

    vs_battle_rMemzero(weapon, sizeof *weapon);

    weapon->index = index;

    func_800FE8B0(0);
}

void _assembleWeapon(int bladeIndex, int gripIndex, int gemInfo)
{
    int i;
    int weaponIndex;
    int gemSlots;
    vs_battle_inventoryWeapon* weapon = &vs_battle_inventory.weapons[_combiningItem];
    vs_battle_inventoryBlade* blade = &vs_battle_inventory.blades[bladeIndex];
    vs_battle_inventoryGrip* grip = &vs_battle_inventory.grips[gripIndex];

    gemSlots = grip->gemSlots;

    _disassembleWeapon(_combiningItem);

    weapon->blade = bladeIndex + 1;
    weapon->grip = gripIndex + 1;

    for (i = 0; i < gemSlots; ++i) {
        weapon->gems[i] = gemInfo;
        gemInfo >>= 8;
    }

    weaponIndex = _combiningItem + 1;
    blade->combinedWeaponIndex = weaponIndex;
    grip->combinedWeaponIndex = weaponIndex;

    for (i = 0; i < gemSlots; ++i) {
        gemInfo = weapon->gems[i];
        if (gemInfo != 0) {
            vs_battle_inventory.gems[gemInfo - 1].setItemIndex = weaponIndex;
        }
    }

    memset(weapon->name, vs_char_terminator, sizeof weapon->name);
    func_800FE8B0(0);
}

void _unsetShieldGems(int index)
{
    int i;
    vs_battle_inventoryShield* shield = &vs_battle_inventory.shields[index];
    int slots = shield->base.gemSlots;

    for (i = 0; i < slots; ++i) {
        int gemIndex = shield->gems[i];
        if (gemIndex != 0) {
            vs_battle_inventory.gems[gemIndex - 1].setItemIndex = 0;
            shield->gems[i] = 0;
        }
    }
}

int _isValidGrip(vs_battle_inventoryBlade* blade, vs_battle_inventoryGrip* grip)
{
    if ((blade == NULL) || (grip == NULL)) {
        return 1;
    }
    return (1 << blade->category) & _validGripFlags[grip->category];
}

int func_80103380(int arg0)
{

    vs_battle_playMenuLeaveSfx();
    func_800FA8E0(0x28);
    func_800FA810(0);

    if (arg0 != 0) {
        func_800FBBD4(-1);
        func_800FBEA4(2);
        vs_mainMenu_drawDpPpbars(4);
    }

    func_800FFA88(2);

    return vs_main_buttonsPressed.all & PADRup ? -2 : -1;
}

void func_801033FC(int count, char** text, int* rowTypes)
{
    int j;
    int i;
    u_short* temp_v1;
    vs_battle_menuItem_t* temp_v0;

    D_8010BCA1 = count;
    D_8010BCA2 = 0;
    D_8010BC9C = 0;
    D_8010BCA0 = 1;
    D_8010BC98 = vs_main_allocHeapR(count << 7);

    for (i = 0; i < count; ++i) {

        *((int*)(&(&D_8010BC98[i * 0x40])[14])) = rowTypes[i];

        temp_v1 = (u_short*)text[i * 2];

        if (temp_v1 != NULL) {
            for (j = 0; j < 13; ++j) {
                D_8010BC98[(i * 0x40) + j] = temp_v1[j];
            }
            D_8010BC98[(i * 0x40) + 13] = 0xE7E7;
        } else {
            D_8010BC98[i * 0x40] = 0xE7E7;
        }

        temp_v1 = (u_short*)text[i * 2 + 1];

        if (temp_v1 != NULL) {
            D_8010BC98[(i * 0x40) + 16] = 0xF8;
            for (j = 0; j < 46; ++j) {
                D_8010BC98[(i * 0x40) + j + 17] = temp_v1[j];
            }
            D_8010BC98[(i * 0x40) + 63] = 0xE7E7;
        } else {
            D_8010BC98[(i * 0x40) + 16] = 0xE7E7;
        }
    }

    j = rowTypes[0];
    temp_v0 = vs_battle_setMenuItem(0x14, 0x9B, 0x12, 0xA5, 0, (char*)D_8010BC98);
    temp_v0->unk7 = j & 1;
    temp_v0->flags = j >> 0x1A;
    temp_v0->unkC = (j >> 0x10) & 7;
    temp_v0->selected = 1;
    D_8010BCA3 = (j >> 0x13) & 0x7F;
}

int func_801035E0(void) { return D_8010BC98 == NULL ? D_8010BC9C : -1; }

void func_80103608(int arg0)
{
    int var_s0;
    int temp_s4;
    int temp_s2_2;
    int temp_s2_6;
    int i;
    int temp_s6;
    vs_battle_menuItem_t* temp_s2;

    if (D_8010BCA0 < 6) {
        if (D_8010BCA0 == D_8010BCA1) {
            D_8010BCA0 = 0x10;
        } else {
            temp_s2 = vs_battle_setMenuItem(D_8010BCA0 + 0x14, 0x140,
                (D_8010BCA0 * 0x10) + 0x12, 0x97, 0, (char*)&D_8010BC98[D_8010BCA0 * 64]);
            temp_s2->state = 2;
            temp_s2->x = 0xA9;
            var_s0 = *(int*)&D_8010BC98[D_8010BCA0 * 64 + 14];
            temp_s2->unk7 = var_s0 & 1;
            temp_s2->flags = (var_s0 >> 0x1A);
            temp_s2_2 = (var_s0 >> 9) & 0x7F;
            if (temp_s2_2 != 0) {
                temp_s2->unkD = temp_s2_2 - 0x64;
            }
            temp_s2->unkC = (var_s0 >> 0x10) & 7;
            ++D_8010BCA0;
            if (D_8010BCA0 == 6) {
                if (D_8010BCA1 >= 7U) {
                    temp_s2->unk5 = 2;
                }
                D_8010BCA0 = 0x10;
            }
        }
    } else {
        temp_s6 = D_8010BCA2;
        temp_s4 = D_8010BC9C + temp_s6;
        temp_s2 = vs_battle_getMenuItem(D_8010BC9C + 0x14);
        vs_mainmenu_setMessage((char*)&D_8010BC98[temp_s4 * 64 + 16]);
        switch (D_8010BCA0) {
        case 16:
            if (vs_mainmenu_ready() != 0) {
                D_8010BCA0 = 0x11;
                return;
            }
            return;
        case 17:
            if (vs_main_buttonsPressed.all & 0x10) {
                if (!(arg0 & 2)) {
                    vs_battle_playMenuLeaveSfx();
                }
                vs_main_freeHeapR(D_8010BC98);
                D_8010BC98 = NULL;
                D_8010BC9C = -3;
                return;
            }
            if (vs_main_buttonsPressed.all & 0x20) {
                if (temp_s2->unk7 != 0) {
                    func_800C02E0();
                } else {
                    vs_main_freeHeapR(D_8010BC98);
                    D_8010BC98 = NULL;
                    D_8010BC9C = temp_s4;
                    if (arg0 != 0) {
                        if (temp_s4 == 0) {
                            vs_main_playSfxDefault(0x7E, 0x22);
                        } else {
                            vs_main_playSfxDefault(0x7E, 0x21);
                        }
                    }
                    break;
                }
            }
            temp_s2->selected = 0;
            if (vs_main_buttonsPressed.all & 0x40) {
                vs_battle_playMenuLeaveSfx();
                vs_main_freeHeapR(D_8010BC98);
                D_8010BC98 = NULL;
                D_8010BC9C = -2;
                return;
            }
            if (vs_main_buttonRepeat & 0x1000) {
                if (D_8010BCA1 < 7U || D_8010BCA2 == 0) {
                    if (D_8010BC9C != 0) {
                        --D_8010BC9C;
                    }
                } else {
                    if (D_8010BC9C == 2) {
                        --D_8010BCA2;
                    } else {
                        --D_8010BC9C;
                    }
                }
            }
            if (vs_main_buttonRepeat & 0x4000) {
                if (D_8010BCA1 < 7) {
                    if (D_8010BC9C < (D_8010BCA1 - 1)) {
                        ++D_8010BC9C;
                    }
                } else {
                    if (D_8010BCA2 == (D_8010BCA1 - 6)) {
                        if (D_8010BC9C < 5) {
                            ++D_8010BC9C;
                        }
                    } else if (D_8010BC9C == 4) {
                        D_8010BCA2 = D_8010BCA2 + 1;
                    } else {
                        D_8010BC9C += 1;
                    }
                }
            }
            if (temp_s4 != (D_8010BC9C + D_8010BCA2)) {
                vs_battle_playMenuChangeSfx();
                if (D_8010BCA2 != temp_s6) {
                    char unksp18[D_8010BCA1];
                    for (i = 0; i < D_8010BCA1; ++i) {
                        unksp18[i] = 0;
                    }
                    var_s0 = D_8010BCA1;

                    if (var_s0 >= 7u) {
                        var_s0 = 6;
                    }

                    for (i = 1; i < var_s0; ++i) {
                        temp_s2 = vs_battle_getMenuItem(i + 0x14);
                        unksp18[i + temp_s6] = temp_s2->unk4;
                    }

                    for (i = 1;;) {
                        int v0;
                        temp_s2 = vs_battle_setMenuItem(i + 0x14, 0xA9, i * 0x10 + 0x12,
                            0x97, 0, (char*)&D_8010BC98[(i + D_8010BCA2) * 64]);
                        temp_s2->unk4 = *(unksp18 + (i + D_8010BCA2));
                        v0 = D_8010BCA2;
                        v0 = i + D_8010BCA2;
                        var_s0 = *(int*)&D_8010BC98[v0 * 64 + 14];
                        temp_s2->unk7 = var_s0 & 1;
                        temp_s2->flags = (var_s0 >> 0x1A);
                        temp_s2_6 = (var_s0 >> 9) & 0x7F;
                        if (temp_s2_6 != 0) {
                            temp_s2->unkD = temp_s2_6 - 0x64;
                        }
                        temp_s2->unkC = (var_s0 >> 0x10) & 7;
                        ++i;
                        if (i == D_8010BCA1) {
                            break;
                        }
                        if (i == 6) {
                            if ((D_8010BCA2 + 6) < D_8010BCA1) {
                                temp_s2->unk5 = 2;
                            }
                            break;
                        }
                    }
                    if (D_8010BCA2 != 0) {
                        vs_battle_getMenuItem(0x15)->unk5 = 1;
                    }
                }
                var_s0 = *(int*)&D_8010BC98[(D_8010BC9C + D_8010BCA2) * 64 + 14];
                D_8010BCA3 = (var_s0 >> 0x13) & 0x7F;
            }
            vs_battle_getMenuItem(D_8010BC9C + 0x14)->selected = 1;
            i = (((D_8010BC9C * 0x10) + 0xA) << 0x10) | 0x9B;
            if (D_8010BC9C == 0) {
                i -= 0xE;
            }
            D_8010BB2E = func_800FFCDC(D_8010BB2E, i);
            break;
        }
    }
}

void func_80103C20(int arg0, int arg1)
{
    int var_v1;

    vs_mainMenu_resetStats();
    vs_mainMenu_setRangeRisk(0, 0, 0, 1);
    vs_mainMenu_equipmentSubtype = 0;

    var_v1 = arg0 != 0;
    if (arg1 != 0) {
        var_v1 += 2;
    }

    switch (var_v1) {
    case 1:
        func_800FD404(arg0);
        break;
    case 2:
        func_800FD504(arg1);
        break;
    case 3:
        func_800FD270(_combiningItem + 1);
        break;
    }

    func_800FBB8C(7);
    vs_mainMenu_drawDpPpbars(0xB);
}

void func_80103CEC(int arg0)
{
    vs_battle_menuItem_t* menuItem;
    int s1 = arg0 >> 4;
    int s2 = (arg0 >> 10);
    int new_var = s1 & 0x3F;
    int new_var2 = s2 & 0x3F;
    arg0 &= 0xF;
    menuItem = vs_battle_setMenuItem(0x20, 0x10, 0x12, 0xA4, 8,
        (char*)(&vs_mainMenu_menu12Text
                    [vs_mainMenu_menu12Text[arg0 + VS_MENU12_BIN_INDEX_assemble]]));
    menuItem->flags = 0x18;
    menuItem->selected = 1;
    if (arg0 == 0) {
        func_80103C20(new_var, new_var2);
    }
}

void func_80103D8C(int arg0)
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = vs_battle_getMenuItem(arg0);
    temp_v0->state = 4;
    temp_v0->x = 0x9B;
    temp_v0->unk1A = 0x12;
}

int func_80103DC4(int arg0)
{
    vs_battle_inventoryGrip* sp10;
    int var_s4;
    int i;
    char* temp_s7;
    char** temp_fp;
    int temp_s0;
    vs_battle_inventoryBlade* var_s2;

    var_s2 = NULL;
    sp10 = NULL;

    if (arg0 != 0) {
        D_8010BC01 = arg0 & 0x7F;
        D_8010BC02 = (arg0 >> 8);
        func_80103D8C(0xB);
        D_8010BC00 = 0;
        return 0;
    }

    if (D_8010BC01 != 0) {
        var_s2 = &vs_battle_inventory.blades[D_8010BC01 - 1];
    }
    if (D_8010BC02 != 0) {
        sp10 = &vs_battle_inventory.grips[D_8010BC02 - 1];
    }

    switch (D_8010BC00) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            temp_s7 = vs_main_allocHeapR(0x72C);
            temp_fp = (char**)(temp_s7 + 0x6A4);
            if (var_s2 == NULL) {
                temp_fp[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_blades];
                temp_fp[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_bladesDesc];
                *D_800F4E84 = 1;
            } else {
                vs_mainMenu_setBladeUi(var_s2, temp_fp, D_800F4E84, temp_s7);
            }

            var_s4 = 1;
            *D_8010BCA4 = D_8010BC01;

            for (i = 0; i < 16; ++i) {
                char(*p)[40] = &D_800619D8.unk0;
                temp_s0 = (*p)[i + 8];
                if ((temp_s0 != 0) && (temp_s0 != D_8010BC01)) {
                    var_s2 = &vs_battle_inventory.blades[temp_s0 - 1];
                    if (var_s2->combinedWeaponIndex == 0) {
                        vs_mainMenu_setBladeUi(var_s2, temp_fp + var_s4 * 2,
                            &D_800F4E84[var_s4], temp_s7 + var_s4 * 0x60);
                        if (_isValidGrip(var_s2, sp10) == 0) {
                            temp_fp[var_s4 * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                                [VS_MENU12_BIN_OFFSET_invalidBlade];
                            D_800F4E84[var_s4] |= 1;
                        }
                        D_8010BCA4[var_s4] = temp_s0;
                        ++var_s4;
                    }
                }
            }

            func_801033FC(var_s4, temp_fp, D_800F4E84);
            vs_main_freeHeapR(temp_s7);
            D_8010BC00 = 1;
        }
        break;
    case 1:
        temp_s0 = D_8010BCA4[D_8010BCA2 + D_8010BC9C];
        if (temp_s0 != 0) {
            func_800FD404((int)temp_s0);
        } else {
            func_800FBB8C(3);
            vs_mainMenu_resetStats();
            vs_mainMenu_setRangeRisk(0, 0, 0, 1);
        }
        func_800FF9E4(D_8010BC9C + D_8010BCA2, (int)D_8010BCA0);
        func_80103608(2);
        D_8010BBFC = func_801035E0() + 1;
        if (D_8010BBFC != 0) {
            func_800FA8E0(0x28);
            if (D_8010BBFC == -2) {
                return -2;
            }
            if (D_8010BBFC > 0) {
                D_8010BBFC = (int)D_8010BCA4[D_8010BBFC - 1];
            }
            D_8010BC00 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BBFC;
        }
        break;
    }
    return 0;
}

int func_8010418C(int arg0)
{
    vs_battle_inventoryBlade* sp10;
    int temp_v0;
    int var_s4;
    int i;
    void* temp_s7;
    char** temp_fp;
    int temp_s0;
    vs_battle_inventoryGrip* temp_s2;

    temp_s2 = NULL;
    sp10 = NULL;

    if (arg0 != 0) {
        D_8010BC0A = arg0 & 0x7F;
        D_8010BC09 = arg0 >> 8;
        func_80103D8C(0xC);
        D_8010BC08 = 0;
        return 0;
    }
    if (D_8010BC09 != 0) {
        sp10 = &vs_battle_inventory.blades[D_8010BC09 - 1];
    }
    if (D_8010BC0A != 0) {
        temp_s2 = &vs_battle_inventory.grips[D_8010BC0A - 1];
    }

    switch (D_8010BC08) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            temp_s7 = vs_main_allocHeapR(0x72CU);
            temp_fp = temp_s7 + 0x6A4;
            if (temp_s2 == NULL) {
                temp_fp[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_grips];
                temp_fp[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_gripsDesc];
                *D_800F4E84 = 1;
            } else {
                vs_mainMenu_setGripUi(temp_s2, temp_fp, D_800F4E84, temp_s7);
            }

            var_s4 = 1;
            D_8010BCA4[0] = D_8010BC0A;

            for (i = 0; i < 16; ++i) {
                temp_s0 = D_800619D8.unk0[i + 0x18];
                if ((temp_s0 != 0) && (temp_s0 != D_8010BC0A)) {
                    temp_s2 = &vs_battle_inventory.grips[temp_s0 - 1];
                    if (temp_s2->combinedWeaponIndex == 0) {
                        vs_mainMenu_setGripUi(temp_s2, temp_fp + var_s4 * 2,
                            &D_800F4E84[var_s4], temp_s7 + var_s4 * 0x60);
                        if (_isValidGrip(sp10, temp_s2) == 0) {
                            temp_fp[var_s4 * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                                [VS_MENU12_BIN_OFFSET_invalidGrip];
                            D_800F4E84[var_s4] |= 1;
                        }
                        D_8010BCA4[var_s4] = temp_s0;
                        var_s4 += 1;
                    }
                }
            }

            func_801033FC(var_s4, temp_fp, D_800F4E84);
            vs_main_freeHeapR(temp_s7);
            D_8010BC08 = 1;
        }
        break;
    case 1:
        temp_s0 = D_8010BCA4[D_8010BCA2 + D_8010BC9C];
        vs_mainMenu_drawDpPpbars(8);
        if (temp_s0 != 0) {
            func_800FD504((int)temp_s0);
        } else {
            func_800FBB8C(4);
            vs_mainMenu_resetStats();
        }
        func_800FF9E4(D_8010BC9C + D_8010BCA2, D_8010BCA0);
        func_80103608(2);
        temp_v0 = func_801035E0() + 1;
        D_8010BC04 = temp_v0;
        if (temp_v0 != 0) {
            func_800FA8E0(0x28);
            if (D_8010BC04 == -2) {
                return -2;
            }
            if (D_8010BC04 > 0) {
                D_8010BC04 = D_8010BCA4[D_8010BC04 - 1];
            }
            D_8010BC08 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BC04;
        }
        break;
    }
    return 0;
}

int func_80104534(int arg0)
{
    int i;
    int temp_s0;
    vs_battle_inventoryGem* temp_s1;
    int var_s2;
    void* temp_s6;
    char** temp_s7;

    temp_s1 = NULL;

    if (arg0 != 0) {
        i = arg0 & 0x7;
        var_s2 = arg0 & 0xF8;
        D_8010BC11 = arg0 >> var_s2;
        func_80103D8C(i + 0xA);
        D_8010BC10 = 0;
        return 0;
    }

    if (D_8010BC11 != 0) {
        temp_s1 = &vs_battle_inventory.gems[D_8010BC11 - 1];
    }

    switch (D_8010BC10) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            temp_s6 = vs_main_allocHeapR(0x14AC);
            temp_s7 = temp_s6 + 0x1324;

            if (temp_s1 == NULL) {
                temp_s7[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_gems];
                temp_s7[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_gemsDesc];
                *D_800F4E84 = 1;
            } else {
                vs_mainMenu_setGemUi(temp_s1, temp_s7, D_800F4E84, temp_s6);
            }

            var_s2 = 1;
            D_8010BCA4[0] = D_8010BC11;

            for (i = 0; i < 48; ++i) {
                temp_s0 = D_800619D8.unk0[i + 0x40];
                if ((temp_s0 != 0) && (temp_s0 != D_8010BC11)) {
                    temp_s1 = &vs_battle_inventory.gems[temp_s0 - 1];
                    if (temp_s1->setItemIndex == 0) {
                        vs_mainMenu_setGemUi(temp_s1, temp_s7 + var_s2 * 2,
                            &D_800F4E84[var_s2], temp_s6 + var_s2 * 0x60);
                        D_8010BCA4[var_s2] = temp_s0;
                        var_s2 += 1;
                    }
                }
            }
            func_801033FC(var_s2, temp_s7, D_800F4E84);
            vs_main_freeHeapR(temp_s6);
            D_8010BC10 = 1;
        }
        break;
    case 1:
        temp_s0 = D_8010BCA4[D_8010BCA2 + D_8010BC9C];
        vs_mainMenu_drawDpPpbars(8);
        if (temp_s0 != 0) {
            func_800FD878(temp_s0);
        } else {
            func_800FBB8C(3);
            vs_mainMenu_resetStats();
        }
        func_800FF9E4(D_8010BC9C + D_8010BCA2, D_8010BCA0);
        func_80103608(2);
        D_8010BC0C = func_801035E0() + 1;
        if (D_8010BC0C != 0) {
            func_800FA8E0(0x28);
            if (D_8010BC0C == -2) {
                return -2;
            }
            if (D_8010BC0C > 0) {
                D_8010BC0C = D_8010BCA4[D_8010BC0C - 1];
            }
            D_8010BC10 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BC0C;
        }
        break;
    }
    return 0;
}

void func_80104868(void)
{
    _disassembleWeapon(_combiningItem);
    func_80103380(1);
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_80104898);

void func_80105618(int arg0 __attribute__((unused)), int arg1)
{
    vs_battle_menuItem_t* temp_v0 =
        vs_battle_setMenuItem(arg1 + 0xA, 0x140, (arg1 * 0x10) + 0x12, 0x97, 0,
            (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_gems]);
    temp_v0->state = 2;
    temp_v0->x = 0xA9;
    temp_v0->unkA = 1;
}

int func_80105674(char* arg0, int arg1)
{
    int i;
    int gem;
    u_char* var_t1;
    vs_battle_inventoryShield* temp_a0;
    vs_battle_inventoryWeapon* temp_t2;

    temp_t2 = &vs_battle_inventory.weapons[_combiningItem];
    temp_a0 = &vs_battle_inventory.shields[_combiningItem];

    if (arg1 != 0) {
        var_t1 = temp_a0->gems;
    } else {
        var_t1 = temp_t2->gems;
    }

    for (i = 0; i < 3; ++i) {
        gem = var_t1[i];
        if (gem != 0) {
            vs_battle_inventory.gems[gem - 1].setItemIndex = 0;
            var_t1[i] = 0;
        }
    }

    for (i = 0; i < 3; ++i) {
        gem = arg0[i];
        if (gem != 0) {
            vs_battle_inventory.gems[gem - 1].setItemIndex =
                _combiningItem + ((arg1 << 7) + 1);
            var_t1[i] = gem;
        }
    }
    if (arg1 != 0) {
        if (temp_a0->unk1 != 0) {
            vs_battle_equipShield(temp_a0);
        }
    } else if (temp_t2->unk3 != 0) {
        vs_battle_equipWeapon(temp_t2);
    }
    return func_80103380(1);
}

int func_801057BC(int arg0)
{
    char sp18[0x300];
    char* sp318[16];
    int sp358[8];
    int var_s2;
    int j;
    int i;
    int var_a2;
    int var_s0;
    vs_battle_inventoryShield* temp_s5;
    vs_battle_inventoryWeapon* temp_s7;
    vs_battle_menuItem_t* temp_v0_3;

    if (arg0 != 0) {
        func_800C8E04(1);
        D_8010BC24 = arg0 - 1;
        D_8010BC20 = 0;
        return 0;
    }
    switch (D_8010BC20) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_801029D0(0, (int)vs_mainMenu_menu12Text[D_8010BC24 + 0x20]);
            D_8010BC20 = 1;
        }
        break;
    case 1:
        if (vs_mainmenu_ready() == 0) {
            break;
        }

        i = 0;

        for (j = 0; j < 8; ++j) {
            char* new_var = sp18;
            var_s0 = 0;

            if (D_8010BC24 != 0) {
                var_s2 = D_800619D8.unk28[j];
                if (var_s2 != 0) {
                    temp_s5 = &vs_battle_inventory.shields[var_s2 - 1];
                    func_800FCE40(temp_s5, &sp318[i * 2], &sp358[i], sp18 + i * 0x60);
                    var_s0 = temp_s5->base.gemSlots;
                }
            } else {
                var_s2 = D_800619D8.unk0[j];
                if (var_s2 != 0) {
                    temp_s7 = &vs_battle_inventory.weapons[var_s2 - 1];
                    func_800FCA08(temp_s7, &sp318[i * 2], &sp358[i], sp18 + i * 0x60);
                    var_s0 = vs_battle_inventory.grips[temp_s7->grip - 1].gemSlots;
                }
            }

            if (var_s2 != 0) {
                vs_battle_stringContext.integers[0] = var_s0;
                vs_battle_printf(sp18 + i * 0x60,
                    (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                            [D_8010BC24 * 2 + (var_s0 == 0 ? 0x3B : 0x3A)]]);
                sp318[i * 2 + 1] = new_var + i * 0x60;
                sp358[i] |= var_s0 == 0;
                ++i;
                D_8010BCA4[i] = var_s2;
            }
        }

        vs_mainmenu_setMenuRows(i, (D_8010BC24 + 0x37) | 0x19100, sp318, sp358);
        D_8010BC20 = 2;
        break;
    case 2:
        D_8010BC1C = vs_mainmenu_getSelectedRow() + 1;
        if (D_8010BC1C != 0) {
            func_800FA8E0(0x28);
            if (D_8010BC1C < 0) {
                return D_8010BC1C;
            }
            temp_v0_3 = vs_battle_getMenuItem(0);
            temp_v0_3->state = 2;
            temp_v0_3->unk1 = 0xA4;
            temp_v0_3->x = 0x10;
            temp_v0_3 = vs_battle_getMenuItem(D_8010BC1C + 9);
            temp_v0_3->state = 4;
            temp_v0_3->x = 0x9B;
            temp_v0_3->unk1A = 0x12;
            D_8010BC20 = 3;
        }
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            vs_battle_menuItem_t* temp_v0_3 = vs_battle_getMenuItem(0);

            var_a2 = 0x18;
            if (D_8010BC24 != 0) {
                var_a2 = 0x1B;
            }
            temp_v0_3->flags = var_a2;

            func_80102C0C(0, 0x20);
            func_80102C0C(D_8010BC1C + 9, 0xA);

            var_s2 = D_8010BCA4[D_8010BC1C];
            _combiningItem = var_s2 - 1;

            if (D_8010BC24 != 0) {
                func_800FD5A0(var_s2);
                temp_s5 = &vs_battle_inventory.shields[var_s2 - 1];
                D_8010BC23 = temp_s5->base.gemSlots;
                D_8010BC30 = temp_s5->gems;
            } else {
                func_800FD270(var_s2);
                temp_s7 = &vs_battle_inventory.weapons[var_s2 - 1];
                D_8010BC23 = vs_battle_inventory.grips[temp_s7->grip - 1].gemSlots;
                D_8010BC30 = temp_s7->gems;
            }
            func_800FBBD4(7);
            vs_mainMenu_drawDpPpbars(3);
            func_800FBEA4(1);

            *(int*)D_8010BC28 = 0;
            for (var_s0 = 0; var_s0 < D_8010BC23; ++var_s0) {
                D_8010BC28[var_s0] = D_8010BC30[var_s0];
            }
            D_8010BC21 = 0;
            D_8010BC22 = 0;
            D_8010BC20 = 4;
            *(int*)D_8010BC2C = *(int*)D_8010BC28;
        }
        break;
    case 4:
        if (D_8010BC21 < 5) {
            ++D_8010BC21;
            if (D_8010BC24 != 0) {
                temp_v0_3 = func_800FC704(D_8010BC21, _combiningItem + 1, 1);
            } else {
                temp_v0_3 = func_800FC510(D_8010BC21, _combiningItem + 1, 1);
            }
            if (temp_v0_3 != NULL) {
                if (temp_v0_3->unk7 != 0) {
                    func_80105618(D_8010BC21 - ((1 - D_8010BC24) * 2), D_8010BC21);
                    break;
                }
            }
        } else {
            D_8010BC20 = 5;
        }
        break;
    case 5:
        if (vs_mainmenu_ready() != 0) {
            if (!(vs_main_buttonsPressed.all & 0x10)) {
                D_8010BB57 += 0x10;
                func_80102968(D_8010BC23 + ((1 - D_8010BC24) * 2), D_8010BB57);
                if (vs_main_buttonsPressed.all & 0x40) {
                    func_80105674(D_8010BC2C, (int)D_8010BC24);
                    D_8010BC20 = 0;
                } else if (vs_main_buttonsPressed.all & 0x800) {
                    int new_var2 = 0xB;
                    vs_battle_playMenuSelectSfx();
                    vs_battle_getMenuItem(
                        ((1 - D_8010BC24) * 2) + (D_8010BC22 + new_var2))
                        ->selected = 0;
                    D_8010BC20 = 7;
                    D_8010BC22 = D_8010BC23;
                } else {
                    var_s0 = D_8010BC22;
                    if (vs_main_buttonsPressed.all & 0x20) {
                        vs_battle_playMenuSelectSfx();
                        if (var_s0 == D_8010BC23) {
                            D_8010BC20 = 7;
                        } else {
                            int new_var3;
                            func_800FA8E0(0x28);
                            new_var3 = ((1 - D_8010BC24) * 2) + 1;
                            func_80104534((var_s0 + new_var3) | ((var_s0 + 1) * 8)
                                          | (*(int*)D_8010BC28 << 8));
                            D_8010BC20 = 6;
                        }
                    } else {
                        if (vs_main_buttonRepeat & 0x1000) {
                            if (var_s0 == 0) {
                                var_s0 = D_8010BC23;
                            } else {
                                --var_s0;
                            }
                        }
                        if (vs_main_buttonRepeat & 0x4000) {
                            if (var_s0 == D_8010BC23) {
                                var_s0 = 0;
                            } else {
                                ++var_s0;
                            }
                        }
                        if (var_s0 != D_8010BC22) {
                            vs_battle_playMenuChangeSfx();
                            D_8010BC22 = var_s0;
                        }

                        for (i = 0; i < D_8010BC23; ++i) {
                            vs_battle_getMenuItem(0xB + ((1 - D_8010BC24) * 2) + i)
                                ->selected = i == D_8010BC22;
                            D_800F4E84[i] = D_8010BC28[i] == 0;
                        }

                        D_800F4E84[i] = 1;
                        func_800FF9E4(var_s0, 0x10);
                        sp318[1] = (char*)(vs_mainMenu_menu12Text + 0x397);
                        if (var_s0 == D_8010BC23) {
                            sp318[1] = (char*)(vs_mainMenu_menu12Text + 0x39E);
                        } else {
                            i = *(var_s0 + D_8010BC28);
                            if (i != 0) {
                                vs_mainMenu_setGemUi(&vs_battle_inventory.gems[i - 1],
                                    sp318, sp358, &sp18);
                            }
                        }
                        vs_mainmenu_setMessage(sp318[1]);
                        i = 0x1A;
                        i = ((((1 - D_8010BC24) << 5) + ((var_s0 * 0x10) + i)) << 0x10)
                          | 0x9B;
                        if (var_s0 == D_8010BC23) {
                            i += 0xFFFC0000;
                        }
                        D_8010BB56 = func_800FFCDC(D_8010BB56, i);
                    }
                }
            } else {
                return func_80105674(D_8010BC2C, D_8010BC24);
            }
        } else {
            D_8010BB57 = 0;
        }
        break;
    case 6:
        var_s0 = func_80104534(0);
        if (var_s0 != 0) {
            if (var_s0 != -2) {
                var_s2 = _combiningItem + 1;
                temp_s7 = &vs_battle_inventory.weapons[var_s2 - 1];
                temp_s5 = &vs_battle_inventory.shields[var_s2 - 1];
                D_8010BC30 = D_8010BC24 != 0 ? temp_s5->gems : temp_s7->gems;
                if (var_s0 > 0) {
                    i = D_8010BC28[D_8010BC22];
                    if (var_s0 == i) {
                        vs_battle_inventory.gems[var_s0 - 1].setItemIndex = 0;
                        D_8010BC30[D_8010BC22] = 0;
                        D_8010BC28[D_8010BC22] = 0;
                    } else {
                        if (i != 0) {
                            vs_battle_inventory.gems[i - 1].setItemIndex = 0;
                        }
                        vs_battle_inventory.gems[var_s0 - 1].setItemIndex =
                            var_s2 + (D_8010BC24 << 7);
                        D_8010BC30[D_8010BC22] = var_s0;
                        D_8010BC28[D_8010BC22] = var_s0;
                        ++D_8010BC22;
                    }
                    if (D_8010BC24 != 0) {
                        if (temp_s5->unk1 != 0) {
                            vs_battle_equipShield(temp_s5);
                        }
                    } else if (temp_s7->unk3 != 0) {
                        vs_battle_equipWeapon(temp_s7);
                    }
                }
                func_800FBB8C(7);
                vs_mainMenu_drawDpPpbars(0xB);
                if (D_8010BC24 != 0) {
                    func_800FD5A0(var_s2);
                    func_800FCE40(temp_s5, sp318, sp358, sp18);
                } else {
                    func_800FD270(var_s2);
                    func_800FCA08(temp_s7, sp318, sp358, sp18);
                }
                temp_v0_3 = vs_battle_setMenuItem(0xA, 0x140, 0x12, 0x89, 0, sp318[0]);
                temp_v0_3->state = 2;
                temp_v0_3->x = 0x9B;
                temp_v0_3->selected = 1;
                i = sp358[0];
                temp_v0_3->flags = i >> 0x1A;
                temp_v0_3->unkC = (i >> 0x10) & 7;
                D_8010BC21 = 0;
                D_8010BC20 = 4;
            } else {
                return func_80105674(D_8010BC2C, D_8010BC24);
            }
        }
        break;
    case 7:
        func_800FBEA4(2);
        func_80102E40(3);
        vs_mainmenu_setMessage((char*)(vs_mainMenu_menu12Text + 0x42B));
        D_8010BC20 = 8;
        break;
    case 8:
        var_s0 = func_80102E40(0);
        if (var_s0 == 0) {
            break;
        }
        switch (var_s0) {
        case 1:
            vs_main_playSfxDefault(0x7E, 0x18);
            func_800FFBC8();
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            func_800FA8E0(0x28);
            func_800FA810(0);
            return 1;
        case 2:
            vs_battle_playMenuLeaveSfx();
            func_800FBEA4(1);
            D_8010BC20 = 5;
            break;
        case 3:
            return func_80105674(D_8010BC2C, D_8010BC24);
            break;
        }
        break;
    }
    return 0;
}

int func_801063E4(int arg0)
{
    char* text[4];
    int rowTypes[4];
    int i;

    if (arg0 != 0) {
        D_8010BC35 = 1;
        func_800FA92C(1, 1);
        D_8010BC34 = 0;
        return 0;
    }

    switch (D_8010BC34) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 4; ++i) {
                text[i] = (char*)&vs_mainMenu_menu12Text
                    [vs_mainMenu_menu12Text[VS_MENU12_BIN_INDEX_weapons + i]];
                rowTypes[i] = 0;
            }
            if (func_800FEA6C(0, 0) == 0) {
                rowTypes[0] = 1;
                text[1] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_noItems];
            }
            if (func_800FEA6C(3, 0) == 0) {
                rowTypes[1] = 1;
                text[3] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_noItems];
            }
            i = vs_main_settings.cursorMemory;
            if (D_8010BC35 == 0) {
                vs_main_settings.cursorMemory = 1;
            }
            D_8010BC35 = 0U;
            vs_mainmenu_setMenuRows(2, 0x236, text, rowTypes);
            vs_main_settings.cursorMemory = i;
            D_8010BC34 = 1U;
        }
        break;
    case 1:
        i = vs_mainmenu_getSelectedRow() + 1;
        if (i != 0) {
            if (i < 0) {
                func_800FA8E0(0);
                return i;
            }
            func_800FA8E0(0x28);
            func_801057BC(i);
            D_8010BC34 = 2;
        }
        break;
    case 2:
        i = func_801057BC(0);
        if (i != 0) {
            if (i != -1) {
                return i;
            }
            D_8010BC34 = 3U;
        }
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            func_800FFBC8();
            func_801029D0(0, 0x57);
            func_801029D0(0xB, 0x7B);
            D_8010BC34 = 0U;
        }
        break;
    }
    return 0;
}

int func_80106610(int arg0)
{
    char* sp10[16];
    int sp50[8];
    int temp_v0_6;
    int var_s7;
    int i;
    int j;
    int var_s1;
    int var_s0;
    vs_battle_inventoryShield* temp_s0;
    vs_battle_menuItem_t* temp_v0_2;

    if (arg0 != 0) {
        func_800C8E04(1);
        D_8010BC3E = (char)(arg0 - 1);
        D_8010BC3C = 0;
        return 0;
    }
    switch (D_8010BC3C) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_801029D0(0, (int)vs_mainMenu_menu12Text[D_8010BC3E + 0x29]);
            D_8010BC3C = 1;
        }
        break;
    case 1:
        if (vs_mainmenu_ready() != 0) {
            var_s7 = 0;
            for (i = 0; i < 8; i++) {
                if (D_8010BC3E != 0) {
                    var_s1 = D_800619D8.unk28[i];
                    if (var_s1 != 0) {
                        temp_s0 = &vs_battle_inventory.shields[var_s1 - 1];
                        func_800FCE40(temp_s0, &sp10[var_s7 * 2], &sp50[var_s7],
                            vs_battle_stringBuf);
                        sp10[var_s7 * 2 + 1] = (char*)(vs_mainMenu_menu12Text + 0x201);
                        for (j = 0; j < temp_s0->base.gemSlots; ++j) {
                            if (temp_s0->gems[j] != 0) {
                                break;
                            }
                        }
                        if (j == temp_s0->base.gemSlots) {
                            sp10[var_s7 * 2 + 1] =
                                (char*)(vs_mainMenu_menu12Text + 0x1E0);
                            sp50[var_s7] |= 1;
                        }
                        ++var_s7;
                        D_8010BCA4[var_s7] = var_s1;
                    }
                } else {
                    var_s1 = D_800619D8.unk0[i];
                    if (var_s1 != 0) {
                        func_800FCA08(&vs_battle_inventory.weapons[var_s1 - 1],
                            &sp10[var_s7 * 2], &sp50[var_s7], vs_battle_stringBuf);
                        sp10[var_s7 * 2 + 1] = (char*)(vs_mainMenu_menu12Text + 0x1F1);
                        ++var_s7;
                        D_8010BCA4[var_s7] = var_s1;
                    }
                }
            }
            vs_mainmenu_setMenuRows(var_s7, (D_8010BC3E + 0x3A) | 0x19100, sp10, sp50);
            D_8010BC3C = 2;
        }
        break;
    case 2:
        D_8010BC38 = vs_mainmenu_getSelectedRow() + 1;
        if (D_8010BC38 != 0) {
            func_800FA8E0(0x28);
            if (D_8010BC38 < 0) {
                return D_8010BC38;
            }
            temp_v0_2 = vs_battle_getMenuItem(0);
            temp_v0_2->state = 2;
            temp_v0_2->unk1 = 0xA4;
            temp_v0_2->x = 0x10;
            temp_v0_2 = vs_battle_getMenuItem(D_8010BC38 + 9);
            temp_v0_2->state = 4;
            temp_v0_2->x = 0x9B;
            temp_v0_2->unk1A = 0x12;
            D_8010BC3C = 3;
        }
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            vs_battle_getMenuItem(0)->flags = D_8010BC3E != 0 ? 0x1B : 0x18;
            func_80102C0C(0, 0x20);
            func_80102C0C(D_8010BC38 + 9, 0xA);
            var_s1 = D_8010BCA4[D_8010BC38];
            _combiningItem = var_s1 - 1;
            if (D_8010BC3E != 0) {
                func_800FD5A0(var_s1);
            } else {
                func_800FD270(var_s1);
            }
            func_800FBBD4(7);
            vs_mainMenu_drawDpPpbars(3);
            D_8010BC3D = 0U;
            D_8010BC3C = 4;
        }
        break;
    case 4:
        if (D_8010BC3D < 5) {
            ++D_8010BC3D;
            if (D_8010BC3E != 0) {
                func_800FC704(D_8010BC3D, _combiningItem + 1, 1);
            } else {
                func_800FC510(D_8010BC3D, _combiningItem + 1, 1);
            }
            break;
        }
        if (D_8010BC3E != 0) {
            var_s0 = vs_battle_inventory.shields[_combiningItem].unk1;
        } else {
            var_s0 = vs_battle_inventory.weapons[_combiningItem].unk3;
        }
        func_80102C58(1);
        vs_mainmenu_setMessage(
            (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text[D_8010BC3E * 4 + 0x27
                                                                  + (var_s0 != 0)]]);
        D_8010BC3C = var_s0 + 5;
        break;
    case 5:
    case 6:
        temp_v0_6 = func_80102C58(0);
        if (temp_v0_6 != 0) {
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            func_800FA8E0(0x28);
            func_800FA810(0);

            switch (temp_v0_6) {
            case 1:
                vs_main_playSfxDefault(0x7E, 0x19);
                if (D_8010BC3E != 0) {
                    _unsetShieldGems(_combiningItem);
                } else {
                    _disassembleWeapon(_combiningItem);
                }
                if (D_8010BC3C == 5) {
                    return -1;
                }
                if (D_8010BC3E != 0) {
                    func_800FE3A0();
                } else {
                    func_800FE360();
                }
                D_8010BC3C = 7;
                break;
            case 2:
                D_8010BC3C = 0;
                break;
            case 3:
                return func_80103380(0);
            }
        }
        break;
    case 7:
        if (func_8010BA58(D_8010BC3E) == 0) {
            return -1;
        }
        break;
    }
    return 0;
}

int func_80106C64(int arg0)
{
    char* text[4];
    int rowTypes[2];
    int temp_s0;
    int temp_v0;
    int var_a0;
    int i;

    if (arg0 != 0) {
        D_8010BC41 = 1;
        func_800FA92C(2, 1);
        D_8010BC3F = 0;
        return 0;
    }
    switch (D_8010BC3F) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 2; ++i) {
                text[i * 2] = (char*)&vs_mainMenu_menu12Text
                    [vs_mainMenu_menu12Text[i * 2 + VS_MENU12_BIN_INDEX_weapons]];
                text[i * 2 + 1] = (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                        [i + VS_MENU12_BIN_INDEX_disassembleWeaponDesc]];

                var_a0 = 0;
                if (i != 0) {
                    var_a0 = 3;
                }

                temp_v0 = func_800FEA6C(var_a0, 0);
                rowTypes[i] = (temp_v0 << 9) + 0x400000;

                if (temp_v0 == 0) {
                    text[i * 2 + 1] =
                        (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_noItems];
                    rowTypes[i] |= 1;
                }
            }
            temp_s0 = vs_main_settings.cursorMemory;
            if (D_8010BC41 == 0) {
                vs_main_settings.cursorMemory = 1;
            }
            D_8010BC41 = 0;
            vs_mainmenu_setMenuRows(2, 0x239, text, rowTypes);
            vs_main_settings.cursorMemory = temp_s0;
            D_8010BC3F = 1;
        }
        break;
    case 1:
        temp_s0 = vs_mainmenu_getSelectedRow() + 1;
        if (temp_s0 != 0) {
            if (temp_s0 < 0) {
                func_800FA8E0(0);
                return temp_s0;
            }
            func_800FA8E0(0x28);
            func_80106610(temp_s0);
            D_8010BC3F = 2;
        }
        break;
    case 2:
        temp_s0 = func_80106610(0);
        if (temp_s0 != 0) {
            if (temp_s0 != -1) {
                return temp_s0;
            }
            D_8010BC3F = 3;
        }
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            func_800FFBC8();
            func_801029D0(0, 0x57);
            func_801029D0(0xC, 0x93);
            D_8010BC3F = 0;
        }
        break;
    }
    return 0;
}

int func_80106ECC(int arg0)
{
    char* sp10[16];
    int sp50[8];
    int i;
    int var_s2;
    int temp_s0;
    vs_battle_menuItem_t* temp_v0_2;

    if (arg0 != 0) {
        func_800C8E04(1);
        vs_mainmenu_setMessage((char*)&vs_mainMenu_menu12Text[0x1C8]);
        func_800FA8E0(0x28);
        D_8010BC48 = 0;
        return 0;
    }
    switch (D_8010BC48) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_801029D0(0, 0xB8);
            D_8010BC48 = 1;
        }
        break;
    case 1:
        if (vs_mainmenu_ready() != 0) {
            var_s2 = 0;
            for (i = 0; i < 8; ++i) {
                temp_s0 = D_800619D8.unk0[i];
                if (temp_s0 != 0) {
                    func_800FCA08(&vs_battle_inventory.weapons[temp_s0 - 1],
                        &sp10[var_s2 * 2], &sp50[var_s2], vs_battle_stringBuf);
                    sp10[(var_s2 * 2) + 1] = (char*)&vs_mainMenu_menu12Text[0x1C8];
                    ++var_s2;
                    D_8010BCA4[var_s2] = temp_s0;
                }
            }
            vs_mainmenu_setMenuRows(var_s2, 0x1913C, sp10, sp50);
            D_8010BC48 = 2;
        }
        break;
    case 2:
        D_8010BC44 = vs_mainmenu_getSelectedRow() + 1;
        if (D_8010BC44 != 0) {
            func_800FA8E0(0x28);
            if (D_8010BC44 < 0) {
                return D_8010BC44;
            }
            temp_v0_2 = vs_battle_getMenuItem(0);
            temp_v0_2->state = 2;
            temp_v0_2->unk1 = 0xA4;
            temp_v0_2->x = 0x10;
            temp_v0_2 = vs_battle_getMenuItem(D_8010BC44 + 9);
            temp_v0_2->state = 4;
            temp_v0_2->x = 0x9B;
            temp_v0_2->unk1A = 0x12;
            D_8010BC48 = 3;
        }
        break;
    case 3:
        if (vs_mainmenu_ready() != 0) {
            vs_battle_getMenuItem(0)->flags = 0x18;
            func_80102C0C(0, 0x20);
            func_80102C0C(D_8010BC44 + 9, 0xA);
            temp_s0 = D_8010BCA4[D_8010BC44];
            _combiningItem = temp_s0 - 1;
            func_800FD270(temp_s0);
            func_800FBBD4(7);
            vs_mainMenu_drawDpPpbars(3);
            D_8010BC49 = 0;
            D_8010BC48 = 4;
        }
        break;
    case 4:
        if (D_8010BC49 < 5) {
            D_8010BC49 = (D_8010BC49 + 1);
            func_800FC510(D_8010BC49, _combiningItem + 1, 1);
            return 0;
        }
        func_80102C58(1);
        vs_mainmenu_setMessage((char*)&vs_mainMenu_menu12Text[0x1D6]);
        D_8010BC48 = 5;
        break;
    case 5:
        i = func_80102C58(0);
        if (i != 0) {
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            switch (i) {
            case 1:
                vs_battle_playMenuSelectSfx();
                func_800FA8E0(0xA);
                vs_battle_getMenuItem(0xA)->unk2 = i;
                D_8010BC48 = 6;
                break;
            case 2:
                func_800FA8E0(0x28);
                func_800FA810(0);
                D_8010BC48 = 0;
                break;
            case 3:
                return func_80103380(0);
            }
        }
        break;
    case 6:
        if (vs_mainmenu_ready() != 0) {
            D_801022D5 = 0;
            vs_battle_stringBuf[0] = 1;
            vs_battle_stringBuf[1] = _combiningItem;
            func_800FFA88(2);
            return 1;
        }
        break;
    }
    return 0;
}

int func_801072FC(int arg0)
{
    int ppCost;
    int i;
    int new_var;

    if (arg0 != 0) {
        func_800FA92C(4, 1);
        D_8010BC50 = 0;
        return 0;
    }

    switch (D_8010BC50) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            func_80102C58(1);
            vs_mainmenu_setMessage(
                (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_repairConfirm]);
            D_8010BC50 = 1;
        }
        break;
    case 1:
        i = func_80102C58(0);
        if (i != 0) {
            D_8010BC4C = -1;
            if (i == 1) {
                vs_main_playSfxDefault(0x7E, 0xD);
                D_8010BC50 = 2;
            } else {
                if (i == 3) {
                    vs_battle_playMenuLeaveSfx();
                    return -2;
                }
                func_800FFBC8();
                func_800FA8A0(0xE);
                D_8010BC50 = 4;
            }
        }
        break;
    case 2:
        func_800C8E04(3);
        vs_mainmenu_setMessage(
            (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_repairComplete]);

        for (i = 0; i < 16; ++i) {
            new_var = D_800619D8.unk0[i + 8];
            if (new_var != 0) {
                vs_battle_inventoryBlade* blade =
                    &vs_battle_inventory.blades[new_var - 1];

                ppCost = blade->maxDp - blade->currentDp;
                ppCost = blade->currentPp - (ppCost / 100);
                blade->currentDp = blade->maxDp;

                if (ppCost >= 0) {
                    blade->currentPp = ppCost;
                } else {
                    blade->currentPp = 0;
                }
            }
        }

        for (i = 0; i < 8; ++i) {
            new_var = D_800619D8.unk0[i];
            if (new_var != 0) {
                vs_battle_inventoryWeapon* weapon =
                    &vs_battle_inventory.weapons[new_var - 1];
                if (weapon->unk3 != 0) {
                    vs_battle_equipWeapon(weapon);
                }
            }
        }

        for (i = 0; i < 8; ++i) {
            new_var = D_800619D8.unk28[i];
            if (new_var != 0) {
                vs_battle_inventoryShield* shield =
                    &vs_battle_inventory.shields[new_var - 1];

                ppCost = shield->base.maxDp - shield->base.currentDp;
                ppCost = shield->base.currentPp - (ppCost / 100);
                shield->base.currentDp = shield->base.maxDp;

                if (ppCost >= 0) {
                    shield->base.currentPp = ppCost;
                } else {
                    shield->base.currentPp = 0;
                }

                if (shield->unk1 != 0) {
                    vs_battle_equipShield(shield);
                }
            }
        }

        for (i = 0; i < 16; ++i) {
            new_var = D_800619D8.unk28[i + 8];
            if (new_var != 0) {
                vs_battle_inventoryArmor* armor = &vs_battle_inventory.armor[new_var - 1];
                if (armor->category != 7) {

                    ppCost = armor->maxDp - armor->currentDp;
                    ppCost = armor->currentPp - (ppCost / 100);
                    armor->currentDp = armor->maxDp;

                    if (ppCost >= 0) {
                        armor->currentPp = ppCost;
                    } else {
                        armor->currentPp = 0;
                    }
                    if (armor->bodyPart != 0) {
                        vs_battle_equipArmor(armor->bodyPart - 1, armor);
                    }
                }
            }
        }

        D_8010BC50 = 3;
        break;
    case 3:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            vs_battle_playMenuLeaveSfx();
            func_800FA8A0(0xE);
            if (vs_main_buttonsPressed.all & PADRup) {
                return -2;
            }
            func_800FFBC8();
            D_8010BC50 = 4;
        }
        break;
    case 4:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BC4C;
        }
        break;
    }
    return 0;
}

int vs_menuC_loadSyd(int id)
{
    vs_main_CdFile cdFile;

    if (id != 0) {
        --id;
        _sydData = vs_main_allocHeapR(_sydSizes[id]);
        cdFile.lba = _sydLbas[id];
        cdFile.size = _sydSizes[id];
        _sydCdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(_sydCdQueueSlot, _sydData);
        _sydFileLoading = 1;
        return 0;
    }
    if (_sydFileLoading == 0) {
        return 1;
    }

    if (_sydCdQueueSlot->state == 4) {
        vs_main_freeCdQueueSlot(_sydCdQueueSlot);
        _sydFileLoading = 0;
        return 1;
    }
    return 0;
}

// https://decomp.me/scratch/3biiU
INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_801077DC);

vs_battle_menuItem_t* func_8010785C(int arg0, int arg1)
{
    vs_battle_menuItem_t* temp_v0;

    temp_v0 = func_801077DC(arg0, arg1);
    temp_v0->state = 2;
    temp_v0->x = 0x9B;
    temp_v0->animSpeed = 0x140;

    return temp_v0;
}

void func_80107894(int arg0)
{
    int i;
    int var_s3;
    u_int temp_v1;
    int temp_s2;
    vs_battle_inventoryBlade* var_s0;

    i = D_8010BD10[0];
    temp_s2 = D_8010BD10[1];

    var_s3 = i != 0;
    if (temp_s2 != 0) {
        var_s3 += 2;
    }

    switch (var_s3) {
    case 0:
        vs_battle_rMemzero(&D_8010BCE4, 0x2C);
        break;
    case 1:
    case 2:
        vs_battle_copyAligned(
            &D_8010BCE4, &vs_battle_inventory.blades[i + temp_s2 - 1], 0x2C);
        break;
    case 3:
        vs_battle_rMemzero(&D_8010BCE4, 0x2C);
        func_8010B2B4(&vs_battle_inventory.blades[i - 1],
            &vs_battle_inventory.blades[temp_s2 - 1], &D_8010BCE4, _sydData);
        break;
    }

    var_s0 = &D_8010BCE4;
    var_s0->combinedWeaponIndex = 0;

    vs_mainMenu_resetStats();
    vs_mainMenu_setRangeRisk(0, 0, 0, 1);

    temp_v1 = arg0 - 1;

    if (temp_v1 >= 2) {
        if (D_8010BCE4.id != 0) {
            for (i = 0; i < 16; ++i) {
                vs_mainMenu_equipmentStats[i] = var_s0->classes[i & 7];
                vs_mainMenu_equipmentStats[16 + i] = var_s0->affinities[i & 7];
            }
            vs_mainMenu_setDpPp(
                var_s0->currentDp, var_s0->maxDp, var_s0->currentPp, var_s0->maxPp);
            vs_mainMenu_setStrIntAgi(
                var_s0->strength, var_s0->intelligence, var_s0->agility, 1);
            vs_mainMenu_setRangeRisk(var_s0->range.unk0, var_s0->cost, 0, 1);
            vs_mainMenu_equipmentSubtype = 2;
        }
    } else if (var_s3 & arg0) {
        func_800FD404(D_8010BD10[temp_v1]);
    }
}

int func_80107AD4(int arg0)
{
    int var_s4;
    int i;
    char* temp_s7;
    char** temp_fp;
    int temp_a0;
    int temp_s0;
    vs_battle_inventoryBlade* var_s2 = NULL;

    if (arg0 != 0) {
        D_8010BC61 = arg0;
        func_80103D8C(arg0 + 0xA);
        D_8010BC60 = 0;
        return 0;
    }

    temp_s0 = D_8010BD10[D_8010BC61 - 1];
    if (temp_s0 != 0) {
        var_s2 = &vs_battle_inventory.blades[temp_s0 - 1];
    }

    switch (D_8010BC60) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            temp_s7 = vs_main_allocHeapR(0x72C);
            temp_fp = (char**)(temp_s7 + 0x6A4);
            if (var_s2 == NULL) {
                temp_fp[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_blade];
                temp_fp[1] = (char*)&vs_mainMenu_menu12Text
                    [VS_MENU12_BIN_OFFSET_selectBladeToCombine];
                *D_800F4E84 = 1;
            } else {
                vs_mainMenu_setBladeUi(var_s2, temp_fp, D_800F4E84, temp_s7);
            }

            *D_8010BCA4 = temp_s0;
            var_s4 = 1;

            for (i = 0; i < 16; ++i) {
                temp_s0 = D_800619D8.unk0[i + 8];
                if ((temp_s0 != 0) && (temp_s0 != D_8010BD10[0])
                    && (temp_s0 != D_8010BD10[1])) {
                    int new_var = temp_s0;
                    var_s2 = &vs_battle_inventory.blades[temp_s0 - 1];
                    vs_mainMenu_setBladeUi(var_s2, temp_fp + var_s4 * 2,
                        &D_800F4E84[var_s4], temp_s7 + var_s4 * 0x60);
                    if (!((D_8010BB30[_isLocationWorkshop] >> var_s2->material) & 1)) {
                        temp_fp[var_s4 * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                            [VS_MENU12_BIN_OFFSET_invalidBladeMaterial];
                        D_800F4E84[var_s4] |= 1;
                    }

                    temp_a0 = var_s2->combinedWeaponIndex;

                    if (temp_a0 != 0) {
                        D_800F4E84[var_s4] =
                            D_800F4E84[var_s4]
                            | (vs_battle_inventory.weapons[temp_a0 - 1].unk3 == 0
                                    ? 0xCC00
                                    : 0xCA00);
                    }
                    D_8010BCA4[var_s4] = new_var;
                    ++var_s4;
                }
            }

            func_801033FC(var_s4, temp_fp, D_800F4E84);
            vs_main_freeHeapR(temp_s7);
            D_8010BC60 = 1;
        }
        break;
    case 1:
        temp_s0 = D_8010BCA4[D_8010BCA2 + D_8010BC9C];
        if (temp_s0 != 0) {
            func_800FD404(temp_s0);
        } else {
            vs_mainMenu_resetStats();
            vs_mainMenu_setRangeRisk(0, 0, 0, 1);
        }
        func_800FF9E4(D_8010BC9C + D_8010BCA2, D_8010BCA0);
        func_80103608(2);
        D_8010BC5C = func_801035E0() + 1;
        if (D_8010BC5C != 0) {
            func_800FA8E0(0x28);
            if (D_8010BC5C == -2) {
                return -2;
            }
            if (D_8010BC5C > 0) {
                D_8010BC5C = D_8010BCA4[D_8010BC5C - 1];
            }
            D_8010BC60 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BC5C;
        }
        break;
    }
    return 0;
}

void func_80107EBC(vs_battle_menuItem_t* arg0, vs_battle_inventoryBlade* arg1)
{
    int temp_v1;

    arg0->flags = arg1->category;
    arg0->unkC = arg1->material;
    temp_v1 = arg1->combinedWeaponIndex;
    if (temp_v1 != 0) {
        int var_v1 = 1;
        if (vs_battle_inventory.weapons[temp_v1 - 1].unk3 == 0) {
            var_v1 = 2;
        }
        arg0->unkD = var_v1;
    }
}

int func_80107F14(int arg0)
{
    char* sp18[2];
    int sp20;
    int temp_s0;
    int var_s1;
    int temp_v0_2;
    int i;
    u_short* var_a0_2;
    int i_2;
    vs_battle_inventoryBlade* temp_s3;
    vs_battle_inventoryBlade* var_a0;
    vs_battle_menuItem_t* temp_v0;

    if (arg0 != 0) {
        func_80102A34(5);
        *(u_short*)&D_8010BD10 = 0;
        func_80107894(0);
        D_8010BC63 = 1;
        D_8010BC62 = 0U;
        return 0;
    }

    var_s1 = 0;
    if (D_8010BD10[0] != 0) {
        var_s1 = D_8010BD10[1] > 0;
    }

    D_8010BC64 += 0x10;
    if (D_8010BC62 != 2) {
        D_8010BC64 = 0;
    }

    switch (D_8010BC62) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_80102B50(0x487, 0x18);
        // Fallthrough
    case 1:
        var_s1 = D_8010BCE4.id;
        temp_v0 = func_8010785C(0, var_s1);
        if (var_s1 != 0) {
            func_80107EBC(temp_v0, &D_8010BCE4);
        }

        for (i = 0; i < 2; ++i) {
            int new_var;
            var_s1 = D_8010BD10[i];
            if (var_s1 != 0) {
                temp_s3 = &vs_battle_inventory.blades[var_s1 - 1];
            }
            temp_v0 = vs_battle_setMenuItem(i + 0xB, 0x14E, 0x22 + i * 0x10, 0x97, 0,
                (char*)(var_s1 == 0 ? vs_mainMenu_menu12Text + (new_var = 0x436)
                                    : (u_short*)vs_mainMenu_itemNames[temp_s3->id]));
            temp_v0->state = 2;
            temp_v0->x = 0xA9;
            if (var_s1 == 0) {
                temp_v0->unkA = 1;
            } else {
                func_80107EBC(temp_v0, temp_s3);
            }
        }
        D_8010BC62 = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (!(vs_main_buttonsPressed.all & 0x10)) {
                if (var_s1 != 0) {
                    func_80102968(2, D_8010BC64);
                }
                if (vs_main_buttonsPressed.all & 0x40) {
                    temp_v0_2 = func_80102AB8(5);
                    if (temp_v0_2 != 0) {
                        vs_battle_playMenuLeaveSfx();
                        D_8010BC63 = temp_v0_2;
                        D_8010BD10[temp_v0_2 - 1] = 0;
                        func_80107894(temp_v0_2);
                        temp_v0 = vs_battle_setMenuItem(temp_v0_2 + 0xA, 0xA9,
                            (temp_v0_2 * 0x10) + 0x12, 0x97, 0,
                            (char*)(vs_mainMenu_menu12Text + 0x436));
                        temp_v0->selected = 1;
                        temp_v0->unkA = 1;
                        var_s1 = D_8010BCE4.id;
                        temp_v0 = func_801077DC(0, var_s1);
                        if (var_s1 != 0) {
                            func_80107EBC(temp_v0, &D_8010BCE4);
                        }
                        break;
                    }
                    return func_80103380(1);
                }
                if (vs_main_buttonsPressed.all & 0x800) {
                    if (var_s1 != 0) {
                        vs_battle_playMenuSelectSfx();
                        vs_battle_getMenuItem(D_8010BC63 + 0xA)->selected = 0;
                        D_8010BC63 = 3;
                        D_8010BC62 = 4;
                        func_80107894(3);
                        return 0;
                    }
                }
                i_2 = D_8010BC63;
                if (vs_main_buttonsPressed.all & 0x20) {
                    if (i_2 == 0) {
                        func_800C02E0();
                    } else {
                        vs_battle_playMenuSelectSfx();
                        if (i_2 == 3) {
                            D_8010BC62 = 4;
                        } else {
                            func_800FA8E0(0x28);
                            func_80107AD4(i_2);
                            D_8010BC62 = 3;
                        }
                        break;
                    }
                }
                if (vs_main_buttonRepeat & 0x1000) {
                    if (i_2 == 0) {
                        i_2 = var_s1 + 2;
                    } else {
                        --i_2;
                    }
                }
                if (vs_main_buttonRepeat & 0x4000) {
                    if (i_2 == (var_s1 + 2)) {
                        i_2 = 0;
                    } else {
                        ++i_2;
                    }
                }

                if (i_2 != D_8010BC63) {
                    vs_battle_playMenuChangeSfx();
                    D_8010BC63 = i_2;
                    func_80107894(i_2 & 0xFF);
                }
                D_800F4E84[0] = D_8010BCE4.id < 1U;

                for (var_s1 = 1; var_s1 < 3; ++var_s1) {
                    vs_battle_getMenuItem(var_s1 + 0xA)->selected =
                        (var_s1 ^ D_8010BC63) == 0;
                    D_800F4E84[var_s1] = D_8010BD10[var_s1 - 1] == 0;
                }

                D_800F4E84[3] = 1;
                func_800FF9E4(i_2, 0x10);
                sp18[1] = (char*)(vs_mainMenu_menu12Text + 0x459);
                switch (i_2) {
                case 0:
                    var_a0 = &D_8010BCE4;
                    if (D_8010BCE4.id != 0) {
                        vs_mainMenu_setBladeUi(var_a0, sp18, &sp20, vs_battle_stringBuf);
                    }
                    break;
                case 1:
                case 2:
                    var_s1 = D_8010BD10[i_2 - 1];
                    if (var_s1 != 0) {
                        var_a0 = &vs_battle_inventory.blades[var_s1 - 1];
                        vs_mainMenu_setBladeUi(var_a0, sp18, &sp20, vs_battle_stringBuf);
                    }
                    break;
                case 3:
                    sp18[1] = (char*)(vs_mainMenu_menu12Text + 0x39E);
                    break;
                }
                vs_mainmenu_setMessage(sp18[1]);
                var_s1 = (((i_2 * 0x10) + 0xA) << 0x10) | 0x9B;
                if (i_2 == 0) {
                    var_s1 -= 0xE;
                }
                if (i_2 == 3) {
                    var_s1 += 0xFFFC0000;
                }
                D_8010BB74 = func_800FFCDC(D_8010BB74, var_s1);
                break;
            }
            return func_80103380(1);
        }
        D_8010BC64 = 0;
        break;
    case 3:
        temp_s0 = func_80107AD4(0);
        if (temp_s0 != 0) {
            if (temp_s0 != -2) {
                if (temp_s0 > 0) {
                    var_s1 = D_8010BC63 - 1;
                    if (temp_s0 == D_8010BD10[D_8010BC63 - 1]) {
                        D_8010BD10[D_8010BC63 - 1] = 0;
                        func_80102AB8(var_s1);
                    } else {
                        D_8010BD10[D_8010BC63 - 1] = temp_s0;
                        func_80102A34(var_s1);
                        D_8010BC63 = (D_8010BC63 + 1);
                        if (var_s1 == 1) {
                            if (D_8010BD10[0] == 0) {
                                D_8010BC63 = var_s1;
                            }
                        }
                    }
                    func_80107894(D_8010BC63);
                }
                D_8010BC62 = 1;
                break;
            }
            return func_80103380(1);
        }
        break;
    case 4:
        func_800FBEA4(2);
        func_80102E40(2);
        var_s1 = 0;

        for (i = 0; i < 2; ++i) {
            var_s1 |= vs_battle_inventory.blades[D_8010BD10[i] - 1].combinedWeaponIndex;
        }
        if (var_s1 == 0) {
            var_a0_2 = vs_mainMenu_menu12Text + 0x42B;
        } else {
            var_a0_2 = vs_mainMenu_menu12Text + 0x4A7;
        }
        vs_mainmenu_setMessage((char*)var_a0_2);
        D_8010BC62 = 5;
        break;
    case 5:
        temp_v0_2 = func_80102E40(0);

        if (temp_v0_2 == 0) {
            break;
        }

        switch (temp_v0_2) {
        case 1:
            vs_main_playSfxDefault(0x7E, 0x18);
            func_800FFBC8();
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            func_800FA8E0(0x28);
            func_800FA810(0);

            for (i = 0; i < 2; ++i) {
                temp_s3 = &vs_battle_inventory.blades[D_8010BD10[i] - 1];
                var_s1 = temp_s3->combinedWeaponIndex;
                if (var_s1 != 0) {
                    if (vs_battle_inventory.weapons[var_s1 - 1].unk3 != 0) {
                        func_800FE360();
                        D_8010BC62 = 6;
                    }
                    _disassembleWeapon(var_s1 - 1);
                }
                func_800FE3E0(1, D_8010BD10[i]);
            }

            temp_s0 = D_8010BD10[0];
            temp_s3 = &vs_battle_inventory.blades[temp_s0 - 1];
            vs_battle_copyAligned(temp_s3, &D_8010BCE4, 0x2C);
            temp_s3->index = temp_s0;
            func_800FE8B0(1);
            return D_8010BC62 != 6;
        case 2:
            vs_battle_playMenuLeaveSfx();
            func_800FBEA4(1);
            D_8010BC62 = temp_v0_2;
            break;
        case 3:
            return func_80103380(1);
        }
        break;
    case 6:
        if (func_8010BA58(0) == 0) {
            return -1;
        }
        break;
    }
    return 0;
}

void func_801087E4(vs_battle_inventoryShield* shield)
{
    int i;
    vs_battle_inventoryArmor* base = &shield->base;

    vs_mainMenu_resetStats();

    for (i = 0; i < 16; ++i) {
        vs_mainMenu_equipmentStats[i] = base->classes[i & 7];
        vs_mainMenu_equipmentStats[16 + i] = base->affinities[i & 7];
    }

    for (i = 0; i < 4; ++i) {
        vs_mainMenu_equipmentStats[32 + i] = base->types[i];
    }

    vs_mainMenu_setDpPp(base->currentDp, base->maxDp, 0, 0);
    vs_mainMenu_setStrIntAgi(base->strength, base->intelligence, base->agility, 1);
    vs_mainMenu_strIntAgi[1].strength = base->strength;
    vs_mainMenu_strIntAgi[1].intelligence = base->intelligence;
    vs_mainMenu_strIntAgi[1].agility = base->agility;
    vs_mainMenu_equipmentSubtype = 8;
}

void func_80108908(int arg0)
{
    int var_s2;
    u_int temp_v1;
    int temp_s1;
    int temp_s3;
    vs_battle_inventoryShield* var_s0;

    temp_s1 = D_8010BD44[0];
    temp_s3 = D_8010BD44[1];

    var_s2 = temp_s1 > 0;

    if (temp_s3 != 0) {
        var_s2 += 2;
    }

    switch (var_s2) {
    case 0:
        vs_battle_rMemzero(&D_8010BD14, sizeof D_8010BD14);
        break;
    case 1:
    case 2:
        vs_battle_copyAligned(&D_8010BD14,
            &vs_battle_inventory.shields[temp_s1 + temp_s3 - 1], sizeof D_8010BD14);
        break;
    case 3:
        vs_battle_rMemzero(&D_8010BD14, sizeof D_8010BD14);
        func_8010B598(&vs_battle_inventory.shields[temp_s1 - 1].base,
            &vs_battle_inventory.shields[temp_s3 - 1].base, &D_8010BD14.base, _sydData);
        break;
    }

    var_s0 = &D_8010BD14;
    var_s0->unk1 = 0;

    vs_mainMenu_resetStats();

    temp_v1 = arg0 - 1;

    if (temp_v1 > 1) {
        if (var_s0->base.id != 0) {
            func_801087E4(var_s0);
        }
    } else if (var_s2 & arg0) {
        func_801087E4(&vs_battle_inventory.shields[D_8010BD44[temp_v1] - 1]);
    }
}

void func_80108A9C(vs_battle_inventoryShield* arg0, char** arg1, int* arg2, char* arg3)
{
    int temp_s1;

    temp_s1 = *(int*)arg0->gems;
    *(int*)arg0->gems = 0;
    func_800FCE40(arg0, arg1, arg2, arg3);
    *(int*)arg0->gems = temp_s1;
}

int func_80108AD4(int arg0)
{
    char** sp10;
    int var_s4;
    int i;
    char* temp_v0;
    int temp_s0;
    vs_battle_inventoryShield* var_s2;

    var_s2 = NULL;
    if (arg0 != 0) {
        D_8010BC6D = arg0;
        func_80103D8C(arg0 + 0xA);
        D_8010BC6C = 0;
        return 0;
    }

    temp_s0 = D_8010BD44[D_8010BC6D - 1];
    if (temp_s0 != 0) {
        var_s2 = &vs_battle_inventory.shields[temp_s0 - 1];
    }

    switch (D_8010BC6C) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            temp_v0 = vs_main_allocHeapR(0x3CC);
            sp10 = (char**)(temp_v0 + 0x384);
            if (var_s2 == NULL) {
                sp10[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_shield];
                sp10[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_selectShield];
                *D_800F4E84 = 1;
            } else {
                func_80108A9C(var_s2, sp10, D_800F4E84, temp_v0);
            }

            *D_8010BCA4 = temp_s0;
            var_s4 = 1;

            for (i = 0; i < 8; ++i) {
                temp_s0 = D_800619D8.unk0[i + 0x28];
                if ((temp_s0 != 0) && (temp_s0 != D_8010BD44[0])
                    && (temp_s0 != D_8010BD44[1])) {
                    var_s2 = &vs_battle_inventory.shields[temp_s0 - 1];
                    func_80108A9C(var_s2, sp10 + var_s4 * 2, &D_800F4E84[var_s4],
                        temp_v0 + var_s4 * 0x60);
                    if (!((D_8010BB30[_isLocationWorkshop] >> var_s2->base.material)
                            & 1)) {
                        sp10[var_s4 * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                            [VS_MENU12_BIN_OFFSET_invalidShieldMaterial];
                        D_800F4E84[var_s4] |= 1;
                    }
                    if (var_s2->unk1 != 0) {
                        D_800F4E84[var_s4] |= 0xCA00;
                    }
                    D_8010BCA4[var_s4] = temp_s0;
                    ++var_s4;
                }
            }

            func_801033FC(var_s4, sp10, D_800F4E84);
            vs_main_freeHeapR(temp_v0);
            D_8010BC6C = 1;
        }
        break;
    case 1:
        temp_s0 = D_8010BCA4[D_8010BCA2 + D_8010BC9C];
        if (temp_s0 != 0) {
            func_801087E4(&vs_battle_inventory.shields[temp_s0 - 1]);
        } else {
            vs_mainMenu_resetStats();
        }
        func_800FF9E4(D_8010BC9C + D_8010BCA2, D_8010BCA0);
        func_80103608(2);
        D_8010BC68 = func_801035E0() + 1;
        if (D_8010BC68 != 0) {
            func_800FA8E0(0x28);
            if (D_8010BC68 == -2) {
                return -2;
            }
            if (D_8010BC68 > 0) {
                D_8010BC68 = D_8010BCA4[D_8010BC68 - 1];
            }
            D_8010BC6C = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BC68;
        }
        break;
    }
    return 0;
}

void func_80108E9C(vs_battle_menuItem_t* arg0, vs_battle_inventoryShield* arg1)
{
    arg0->flags = 0xF;
    arg0->unkC = arg1->base.material;
    arg0->unkD = arg1->unk1 != 0;
}

int func_80108EC4(int arg0)
{
    char* sp18[2];
    int sp20;
    int temp_s0_3;
    int var_a0;
    int var_s1;
    int i;
    u_short* var_a0_2;
    int temp_s1;
    int temp_s2;
    int temp_v1_2;
    vs_battle_inventoryShield* temp_s0;
    vs_battle_inventoryShield* var_s0;
    vs_battle_menuItem_t* temp_v0;

    if (arg0 != 0) {
        func_80102A34(5);
        *(u_short*)D_8010BD44 = 0;
        func_80108908(0);
        D_8010BC6F = 1;
        D_8010BC6E = 0;
        return 0;
    }

    var_s1 = 0;

    if (D_8010BD44[0] != 0) {
        var_s1 = D_8010BD44[1] > 0;
    }

    D_8010BC70 += 0x10;
    if (D_8010BC6E != 2) {
        D_8010BC70 = 0;
    }

    switch (D_8010BC6E) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_80102B50(0x48F, 0x1B);
        // Fallthrough
    case 1:
        temp_s1 = D_8010BD14.base.id;
        temp_v0 = func_8010785C(1, temp_s1);
        if (temp_s1 != 0) {
            func_80108E9C(temp_v0, &D_8010BD14);
        }

        for (i = 0; i < 2; ++i) {
            int new_var;
            temp_s1 = D_8010BD44[i];
            if (temp_s1 != 0) {
                var_s0 = &vs_battle_inventory.shields[temp_s1 - 1];
            }
            temp_v0 = vs_battle_setMenuItem(i + 0xB, 0x14E, 0x22 + i * 0x10, 0x97, 0,
                (char*)(temp_s1 == 0 ? vs_mainMenu_menu12Text + (new_var = 0x439)
                                     : (u_short*)vs_mainMenu_itemNames[var_s0->base.id]));
            temp_v0->state = 2;
            temp_v0->x = 0xA9;
            if (temp_s1 == 0) {
                temp_v0->unkA = 1;
            } else {
                func_80108E9C(temp_v0, var_s0);
            }
        }

        D_8010BC6E = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (!(vs_main_buttonsPressed.all & 0x10)) {
                if (var_s1 != 0) {
                    func_80102968(2, D_8010BC70);
                }
                if (vs_main_buttonsPressed.all & 0x40) {
                    temp_s2 = func_80102AB8(5);
                    if (temp_s2 != 0) {
                        vs_battle_playMenuLeaveSfx();
                        D_8010BC6F = temp_s2;
                        D_8010BD44[temp_s2 - 1] = 0;
                        func_80108908(temp_s2);
                        temp_v0 = vs_battle_setMenuItem(temp_s2 + 0xA, 0xA9,
                            (temp_s2 * 0x10) + 0x12, 0x97, 0,
                            (char*)(vs_mainMenu_menu12Text + 0x439));
                        temp_v0->selected = 1;
                        temp_v0->unkA = 1;
                        var_s1 = D_8010BD14.base.id;
                        temp_v0 = func_801077DC(1, var_s1);
                        if (var_s1 != 0) {
                            func_80108E9C(temp_v0, &D_8010BD14);
                            return 0;
                        }
                        break;
                    }
                    return func_80103380(1);
                }
                if (vs_main_buttonsPressed.all & 0x800) {
                    if (var_s1 != 0) {
                        vs_battle_playMenuSelectSfx();
                        vs_battle_getMenuItem(D_8010BC6F + 0xA)->selected = 0;
                        D_8010BC6F = 3U;
                        D_8010BC6E = 4U;
                        func_80108908(3);
                        return 0;
                    }
                }
                temp_s2 = D_8010BC6F;
                if (vs_main_buttonsPressed.all & 0x20) {
                    if (temp_s2 == 0) {
                        func_800C02E0();
                    } else {
                        vs_battle_playMenuSelectSfx();
                        if (temp_s2 == 3) {
                            D_8010BC6E = 4;
                        } else {
                            func_800FA8E0(0x28);
                            func_80108AD4(temp_s2);
                            D_8010BC6E = 3;
                        }
                        break;
                    }
                }

                if (vs_main_buttonRepeat & 0x1000) {
                    if (temp_s2 == 0) {
                        temp_s2 = var_s1 + 2;
                    } else {
                        --temp_s2;
                    }
                }

                if (vs_main_buttonRepeat & 0x4000) {
                    if (temp_s2 == (var_s1 + 2)) {
                        temp_s2 = 0;
                    } else {
                        ++temp_s2;
                    }
                }

                if (temp_s2 != D_8010BC6F) {
                    vs_battle_playMenuChangeSfx();
                    D_8010BC6F = temp_s2;
                    func_80108908(D_8010BC6F);
                }
                D_800F4E84[0] = D_8010BD18 < 1;

                for (var_s1 = 1; var_s1 < 3; ++var_s1) {
                    vs_battle_getMenuItem(var_s1 + 0xA)->selected =
                        (var_s1 ^ D_8010BC6F) == 0;
                    D_800F4E84[var_s1] = D_8010BD44[var_s1 - 1] == 0;
                }

                D_800F4E84[3] = 1;
                func_800FF9E4(temp_s2, 0x10);
                sp18[1] = (char*)(vs_mainMenu_menu12Text + 0x461);
                switch (temp_s2) {
                case 0:
                    if (D_8010BD14.base.id != 0) {
                        func_80108A9C(&D_8010BD14, sp18, &sp20, vs_battle_stringBuf);
                    }
                    break;
                case 1:
                case 2:
                    var_s1 = D_8010BD44[temp_s2 - 1];
                    if (var_s1 != 0) {
                        temp_s0 = &vs_battle_inventory.shields[var_s1 - 1];
                        var_s1 = *(int*)temp_s0->gems;
                        *(int*)temp_s0->gems = 0;
                        func_80108A9C(temp_s0, sp18, &sp20, vs_battle_stringBuf);
                        *(int*)temp_s0->gems = var_s1;
                    }
                    break;
                case 3:
                    sp18[1] = (char*)(vs_mainMenu_menu12Text + 0x39E);
                    break;
                }
                vs_mainmenu_setMessage((char*)sp18[1]);
                var_s1 = (((temp_s2 * 0x10) + 0xA) << 0x10) | 0x9B;
                if (temp_s2 == 0) {
                    var_s1 -= 0xE;
                }
                if (temp_s2 == 3) {
                    var_s1 += 0xFFFC0000;
                }
                D_8010BB75 = func_800FFCDC(D_8010BB75, var_s1);
                break;
            }
            return func_80103380(1);
        }
        D_8010BC70 = 0;
        break;
    case 3:
        temp_s2 = func_80108AD4(0);
        if (temp_s2 != 0) {
            if (temp_s2 != -2) {
                if (temp_s2 > 0) {
                    var_s1 = D_8010BC6F - 1;
                    if (temp_s2 == D_8010BD44[D_8010BC6F - 1]) {
                        D_8010BD44[D_8010BC6F - 1] = 0;
                        func_80102AB8(var_s1);
                    } else {
                        D_8010BD44[D_8010BC6F - 1] = temp_s2;
                        func_80102A34(var_s1);
                        D_8010BC6F = (D_8010BC6F + 1);
                        if (var_s1 == 1) {
                            if (D_8010BD44[0] == 0) {
                                D_8010BC6F = var_s1;
                            }
                        }
                    }
                    func_80108908(D_8010BC6F);
                }
                D_8010BC6E = 1;
                break;
            }
            return func_80103380(1);
        }
        break;
    case 4:
        func_800FBEA4(2);
        func_80102E40(2);
        var_s1 = 0;

        for (i = 0; i < 2; ++i) {

            var_s0 = &vs_battle_inventory.shields[D_8010BD44[i] - 1];
            temp_v1_2 = var_s0->base.gemSlots;
            var_s1 |= var_s0->unk1;

            for (var_a0 = 0; var_a0 < temp_v1_2; ++var_a0) {
                var_s1 |= var_s0->gems[var_a0];
            }
        }

        if (var_s1 == 0) {
            var_a0_2 = vs_mainMenu_menu12Text + 0x42B;
        } else {
            var_a0_2 = vs_mainMenu_menu12Text + 0x4A7;
        }
        vs_mainmenu_setMessage((char*)var_a0_2);
        D_8010BC6E = 5;
        break;
    case 5:
        temp_s2 = func_80102E40(0);

        if (temp_s2 == 0) {
            break;
        }

        switch (temp_s2) {
        case 1:
            vs_main_playSfxDefault(0x7E, 0x18);

            func_800FFBC8();
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            func_800FA8E0(0x28);
            func_800FA810(0);

            for (i = 0; i < 2; ++i) {
                temp_s1 = D_8010BD44[i];
                temp_s0_3 = temp_s1 - 1;
                if (vs_battle_inventory.shields[temp_s0_3].unk1 != 0) {
                    func_800FE3A0();
                    D_8010BC6E = 6;
                }
                _unsetShieldGems(temp_s0_3);
                func_800FE3E0(3, temp_s1);
            }

            temp_s2 = D_8010BD44[0];
            temp_s0 = &vs_battle_inventory.shields[temp_s2 - 1];
            vs_battle_copyAligned(temp_s0, &D_8010BD14, 0x30);
            temp_s0->index = temp_s2;
            func_800FE8B0(3);
            return D_8010BC6E != 6;
        case 2:
            vs_battle_playMenuLeaveSfx();
            func_800FBEA4(1);
            D_8010BC6E = temp_s2;
            break;
        case 3:
            return func_80103380(1);
        }
        break;
    case 6:
        if (func_8010BA58(1) == 0) {
            return -1;
        }
        break;
    }
    return 0;
}

void func_80109790(int arg0)
{
    int var_a0;
    int i;
    int var_s2;
    u_int temp_v1;
    int temp_s3;
    vs_battle_inventoryArmor* var_s0;

    i = D_8010BD7C[0];
    temp_s3 = D_8010BD7C[1];

    var_s2 = i != 0;
    if (temp_s3 != 0) {
        var_s2 += 2;
    }

    switch (var_s2) {
    case 0:
        vs_battle_rMemzero(&D_8010BD54, 0x28);
        break;
    case 1:
    case 2:
        vs_battle_copyAligned(
            &D_8010BD54, &vs_battle_inventory.armor[i + temp_s3 - 1], 0x28);
        break;
    case 3:
        vs_battle_rMemzero(&D_8010BD54, 0x28);
        func_8010B80C(&vs_battle_inventory.armor[i - 1],
            &vs_battle_inventory.armor[temp_s3 - 1], &D_8010BD54, _sydData);
        break;
    }

    var_s0 = &D_8010BD54;
    var_s0->bodyPart = 0;

    vs_mainMenu_resetStats();

    temp_v1 = arg0 - 1;

    if (temp_v1 >= 2) {
        if (D_8010BD54.id != 0) {
            for (i = 0; i < 16; ++i) {
                vs_mainMenu_equipmentStats[i] = var_s0->classes[i & 7];
                vs_mainMenu_equipmentStats[16 + i] = var_s0->affinities[i & 7];
            }

            for (i = 0; i < 4; ++i) {
                vs_mainMenu_equipmentStats[32 + i] = var_s0->types[i];
                var_a0 += 2;
            }
            vs_mainMenu_setDpPp(var_s0->currentDp, var_s0->maxDp, 0, 0);
            vs_mainMenu_setStrIntAgi(
                var_s0->strength, var_s0->intelligence, var_s0->agility, 1);
            vs_mainMenu_equipmentSubtype = 0x10;
            vs_mainMenu_strIntAgi[1].strength = var_s0->strength;
            vs_mainMenu_strIntAgi[1].intelligence = var_s0->intelligence;
            vs_mainMenu_strIntAgi[1].agility = var_s0->agility;
        }
    } else if (var_s2 & arg0) {
        func_800FD700(D_8010BD7C[temp_v1]);
    }
}

int func_801099FC(int arg0)
{
    char** sp10;
    int var_s4;
    int i;
    char* temp_v0;
    int temp_s0;
    int s0_2;
    vs_battle_inventoryArmor* var_s2;

    var_s2 = NULL;
    if (arg0 != 0) {
        D_8010BC79 = arg0;
        func_80103D8C(arg0 + 0xA);
        D_8010BC78 = 0;
        return 0;
    }

    temp_s0 = D_8010BD7C[D_8010BC79 - 1];
    if (temp_s0 != 0) {
        var_s2 = &vs_battle_inventory.armor[temp_s0 - 1];
    }

    switch (D_8010BC78) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            s0_2 = temp_s0;
            temp_v0 = vs_main_allocHeapR(0x72CU);
            sp10 = (char**)(temp_v0 + 0x6A4);
            if (var_s2 == NULL) {
                sp10[0] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_armor];
                sp10[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_selectArmor];
                *D_800F4E84 = 1;
            } else {
                vs_mainMenu_setAccessoryUi(var_s2, sp10, D_800F4E84, temp_v0);
            }

            *D_8010BCA4 = s0_2;
            var_s4 = 1;

            for (i = 0; i < 16; ++i) {
                temp_s0 = D_800619D8.unk0[i + 0x30];
                if ((temp_s0 != 0) && (temp_s0 != D_8010BD7C[0])
                    && (temp_s0 != D_8010BD7C[1])) {
                    var_s2 = &vs_battle_inventory.armor[temp_s0 - 1];
                    if (var_s2->category != 7) {
                        vs_mainMenu_setAccessoryUi(var_s2, sp10 + var_s4 * 2,
                            &D_800F4E84[var_s4], temp_v0 + var_s4 * 0x60);
                        if (!((D_8010BB30[_isLocationWorkshop] >> var_s2->material)
                                & 1)) {
                            sp10[var_s4 * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                                [VS_MENU12_BIN_OFFSET_invalidArmorMaterial];
                            D_800F4E84[var_s4] |= 1;
                        }
                        if (var_s2->bodyPart != 0) {
                            D_800F4E84[var_s4] |= 0xCA00;
                        }
                        D_8010BCA4[var_s4] = temp_s0;
                        ++var_s4;
                    }
                }
            }
            func_801033FC(var_s4, sp10, D_800F4E84);
            vs_main_freeHeapR(temp_v0);
            D_8010BC78 = 1;
        }
        break;
    case 1:
        temp_s0 = D_8010BCA4[D_8010BCA2 + D_8010BC9C];
        if (temp_s0 != 0) {
            func_800FD700(temp_s0);
        } else {
            vs_mainMenu_resetStats();
        }
        func_800FF9E4(D_8010BC9C + D_8010BCA2, D_8010BCA0);
        func_80103608(2);
        D_8010BC74 = func_801035E0() + 1;
        if (D_8010BC74 != 0) {
            func_800FA8E0(0x28);
            if (D_8010BC74 == -2) {
                return -2;
            }
            if (D_8010BC74 > 0) {
                D_8010BC74 = D_8010BCA4[D_8010BC74 - 1];
            }
            D_8010BC78 = 2;
        }
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            return D_8010BC74;
        }
        break;
    }
    return 0;
}

void func_80109DBC(vs_battle_menuItem_t* arg0, vs_battle_inventoryArmor* arg1)
{
    arg0->flags = arg1->category + 0xE;
    arg0->unkC = arg1->material;
    arg0->unkD = arg1->bodyPart != 0;
}

int func_80109DEC(int arg0)
{
    char* sp18[2];
    int sp20;
    int temp_v0_2;
    int temp_s0;
    int temp_v0_6;
    int i;
    int var_s1;
    u_short* var_a0_2;
    int i_2;
    vs_battle_inventoryArmor* var_s3;
    vs_battle_menuItem_t* temp_a0;
    vs_battle_menuItem_t* temp_v0;

    if (arg0 != 0) {
        func_80102A34(5);
        *(u_short*)D_8010BD7C = 0;
        func_80109790(0);
        D_8010BC7B = 1;
        D_8010BC7A = 0;
        return 0;
    }

    var_s1 = 0;
    if (D_8010BD7C[0] != 0) {
        var_s1 = D_8010BD7C[1] > 0;
    }

    D_8010BC7C += 0x10;

    if (D_8010BC7A != 2) {
        D_8010BC7C = 0;
    }

    switch (D_8010BC7A) {
    case 0:
        if (vs_mainmenu_ready() == 0) {
            break;
        }
        func_80102B50(0x497, 0x1C);
        // Fallthrough
    case 1:
        var_s1 = D_8010BD54.id;
        temp_a0 = func_8010785C(2, var_s1);
        if (var_s1 != 0) {
            func_80109DBC(temp_a0, &D_8010BD54);
        }

        for (i = 0; i < 2; ++i) {
            int new_var;
            var_s1 = D_8010BD7C[i];
            if (var_s1 != 0) {
                var_s3 = &vs_battle_inventory.armor[var_s1 - 1];
            }
            temp_v0 = vs_battle_setMenuItem(i + 0xB, 0x14E, 0x22 + i * 0x10, 0x97, 0,
                (char*)(var_s1 == 0 ? vs_mainMenu_menu12Text + (new_var = 0x43D)
                                    : (u_short*)vs_mainMenu_itemNames[var_s3->id]));
            temp_v0->state = 2;
            temp_v0->x = 0xA9;

            if (var_s1 == 0) {
                temp_v0->unkA = 1;
            } else {
                func_80109DBC(temp_v0, var_s3);
            }
        }

        D_8010BC7A = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            if (!(vs_main_buttonsPressed.all & 0x10)) {
                if (var_s1 != 0) {
                    func_80102968(2, D_8010BC7C);
                }
                if (vs_main_buttonsPressed.all & 0x40) {
                    temp_v0_2 = func_80102AB8(5);
                    if (temp_v0_2 != 0) {
                        vs_battle_playMenuLeaveSfx();
                        D_8010BC7B = temp_v0_2;
                        D_8010BD7C[temp_v0_2 - 1] = 0;
                        func_80109790(temp_v0_2);
                        temp_v0 = vs_battle_setMenuItem(temp_v0_2 + 0xA, 0xA9,
                            (temp_v0_2 * 0x10) + 0x12, 0x97, 0,
                            (char*)(vs_mainMenu_menu12Text + 0x43D));
                        temp_v0->selected = 1;
                        temp_v0->unkA = 1;
                        var_s1 = D_8010BD54.id;
                        temp_a0 = func_801077DC(2, var_s1);
                        if (var_s1 != 0) {
                            func_80109DBC(temp_a0, &D_8010BD54);
                        }
                        break;
                    }
                    return func_80103380(1);
                }
                if (vs_main_buttonsPressed.all & 0x800) {
                    if (var_s1 != 0) {
                        vs_battle_playMenuSelectSfx();
                        vs_battle_getMenuItem(D_8010BC7B + 0xA)->selected = 0;
                        D_8010BC7B = 3;
                        D_8010BC7A = 4;
                        func_80109790(3);
                        return 0;
                    }
                }
                i_2 = D_8010BC7B;
                if (vs_main_buttonsPressed.all & 0x20) {
                    if (i_2 == 0) {
                        func_800C02E0();
                    } else {
                        vs_battle_playMenuSelectSfx();
                        if (i_2 == 3) {
                            D_8010BC7A = 4;
                        } else {
                            func_800FA8E0(0x28);
                            func_801099FC(i_2);
                            D_8010BC7A = 3;
                        }
                        break;
                    }
                }
                if (vs_main_buttonRepeat & 0x1000) {
                    if (i_2 == 0) {
                        i_2 = var_s1 + 2;
                    } else {
                        --i_2;
                    }
                }
                if (vs_main_buttonRepeat & 0x4000) {
                    if (i_2 == (var_s1 + 2)) {
                        i_2 = 0;
                    } else {
                        ++i_2;
                    }
                }

                if (i_2 != D_8010BC7B) {
                    vs_battle_playMenuChangeSfx();
                    D_8010BC7B = i_2;
                    func_80109790(D_8010BC7B);
                }
                D_800F4E84[0] = D_8010BD54.id < 1;

                for (var_s1 = 1; var_s1 < 3; ++var_s1) {
                    vs_battle_getMenuItem(var_s1 + 0xA)->selected =
                        (var_s1 ^ D_8010BC7B) == 0;
                    D_800F4E84[var_s1] = D_8010BD7C[var_s1 - 1] == 0;
                }

                D_800F4E84[3] = 1;
                func_800FF9E4(i_2, 0x10);
                sp18[1] = (char*)(vs_mainMenu_menu12Text + 0x46A);
                switch (i_2) {
                case 0:
                    if (D_8010BD54.id != 0) {
                        vs_mainMenu_setAccessoryUi(
                            &D_8010BD54, sp18, &sp20, vs_battle_stringBuf);
                    }
                    break;
                case 1:
                case 2:
                    var_s1 = D_8010BD7C[i_2 - 1];
                    if (var_s1 != 0) {
                        vs_mainMenu_setAccessoryUi(&vs_battle_inventory.armor[var_s1 - 1],
                            sp18, &sp20, vs_battle_stringBuf);
                    }
                    break;
                case 3:
                    sp18[1] = (char*)(vs_mainMenu_menu12Text + 0x39E);
                    break;
                }
                vs_mainmenu_setMessage((char*)sp18[1]);
                var_s1 = (((i_2 * 0x10) + 0xA) << 0x10) | 0x9B;
                if (i_2 == 0) {
                    var_s1 -= 0xE;
                }
                if (i_2 == 3) {
                    var_s1 += 0xFFFC0000;
                }
                D_8010BB76 = func_800FFCDC(D_8010BB76, var_s1);
                break;
            }
            return func_80103380(1);
        }
        D_8010BC7C = 0;
        break;
    case 3:
        temp_s0 = func_801099FC(0);
        if (temp_s0 != 0) {
            if (temp_s0 != -2) {
                if (temp_s0 > 0) {
                    var_s1 = D_8010BC7B - 1;
                    if (temp_s0 == D_8010BD7C[D_8010BC7B - 1]) {
                        D_8010BD7C[D_8010BC7B - 1] = 0;
                        func_80102AB8(var_s1);
                    } else {
                        D_8010BD7C[D_8010BC7B - 1] = temp_s0;
                        func_80102A34(var_s1);
                        D_8010BC7B = (D_8010BC7B + 1);
                        if (var_s1 == 1) {
                            if (D_8010BD7C[0] == 0) {
                                D_8010BC7B = var_s1;
                            }
                        }
                    }
                    func_80109790(D_8010BC7B);
                }
                D_8010BC7A = 1;
                break;
            }
            return func_80103380(1);
        }
        break;
    case 4:
        func_800FBEA4(2);
        func_80102E40(2);
        var_s1 = 0;

        for (i = 0; i < 2; ++i) {
            var_s1 |= vs_battle_inventory.armor[D_8010BD7C[i] - 1].bodyPart;
        }
        if (var_s1 == 0) {
            var_a0_2 = vs_mainMenu_menu12Text + 0x42B;
        } else {
            var_a0_2 = vs_mainMenu_menu12Text + 0x4A7;
        }
        vs_mainmenu_setMessage((char*)var_a0_2);
        D_8010BC7A = 5;
        break;
    case 5:
        temp_v0_6 = func_80102E40(0);

        if (temp_v0_6 == 0) {
            break;
        }

        switch (temp_v0_6) {
        case 1:
            vs_main_playSfxDefault(0x7E, 0x18);

            func_800FFBC8();
            func_800FBBD4(-1);
            vs_mainMenu_drawDpPpbars(4);
            func_800FA8E0(0x28);
            func_800FA810(0);
            for (i = 0; i < 2; ++i) {
                var_s3 = &vs_battle_inventory.armor[D_8010BD7C[i] - 1];
                var_s1 = var_s3->bodyPart;
                if (var_s1 != 0) {
                    vs_battle_equipArmor(var_s1 - 1, NULL);
                    var_s3->bodyPart = 0;
                }
                func_800FE3E0(4, D_8010BD7C[i]);
            }
            temp_s0 = D_8010BD7C[0];
            var_s3 = &vs_battle_inventory.armor[temp_s0 - 1];
            vs_battle_copyAligned(var_s3, &D_8010BD54, 0x28);
            var_s3->index = temp_s0;
            func_800FE8B0(4);
            return 1;
        case 2:
            vs_battle_playMenuLeaveSfx();
            func_800FBEA4(1);
            D_8010BC7A = temp_v0_6;
            break;
        case 3:
            return func_80103380(1);
        }
        break;
    }
    return 0;
}

int func_8010A63C(int arg0)
{
    int i;
    vs_battle_inventoryArmor* var_a1 = vs_battle_inventory.armor;
    int var_a2 = 0;

    if (arg0 == 2) {
        for (i = 0; i < 16; ++i, ++var_a1) {
            int var_v1 = 0;
            if (var_a1->id != 0) {
                var_v1 = (var_a1->category ^ 7) > 0;
            }
            var_a2 += var_v1;
        }
    } else {
        var_a2 = func_800FEA6C((arg0 * 2) | 1, 0);
    }
    return var_a2;
}

int func_8010A6BC(int arg0)
{
    char* text[6];
    int temp_a2;
    int temp_v0;
    int i;
    int temp_s1;

    if (arg0 != 0) {
        D_8010BC7E = 1;
        func_800FA92C(5, 1);
        D_8010BC7D = 0U;
        return 0;
    }

    switch (D_8010BC7D) {
    case 0:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 3; ++i) {
                temp_a2 = func_8010A63C(i);
                text[i * 2] = (char*)&vs_mainMenu_menu12Text
                    [vs_mainMenu_menu12Text[i + VS_MENU12_BIN_INDEX_blade]];
                text[i * 2 + 1] =
                    temp_a2 < 2 ? (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                                          [VS_MENU12_BIN_INDEX_noItems - (temp_a2 * 4)]]
                                : (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text
                                          [i + VS_MENU12_BIN_INDEX_combineBlades]];
                D_800F4E84[i] = temp_a2 < 2;
            }

            temp_s1 = vs_main_settings.cursorMemory;
            if (D_8010BC7E == 0) {
                vs_main_settings.cursorMemory = 1;
            }
            D_8010BC7E = 0;
            vs_mainmenu_setMenuRows(3, 0x23D, text, D_800F4E84);
            vs_main_settings.cursorMemory = temp_s1;
            D_8010BC7D = 1;
        }
        break;
    case 1:
        func_800FF9E4(func_801008B0(), D_801023D0);
        temp_v0 = vs_mainmenu_getSelectedRow();
        i = temp_v0 + 1;
        if (i != 0) {
            if (i < 0) {
                func_800FA8E0(0);
                return i;
            }
            func_800FA8E0(0x28);
            D_8010BB78[temp_v0](1);
            vs_menuC_loadSyd(i);
            D_8010BC7D = temp_v0 + 2;
        }
        break;
    case 2:
    case 3:
    case 4:
        if (vs_menuC_loadSyd(0) != 0) {
            i = D_8010BB78[D_8010BC7D - 2](0);
            if (i != 0) {
                vs_main_freeHeapR(_sydData);
                _sydData = NULL;
                if (i == -1) {
                    D_8010BC7D = 5;
                    break;
                }
                return i;
            }
        }
        break;
    case 5:
        if (vs_mainmenu_ready() != 0) {
            func_800FFBC8();
            func_801029D0(0, 0x57);
            func_801029D0(0xF, 0xED);
            D_8010BC7D = 0U;
        }
        break;
    }
    return 0;
}

int func_8010A978(char* state)
{
    char* sp10[12];
    int i;
    int temp_v0_5;
    vs_battle_menuItem_t* temp_v0;

    switch (*state) {
    case 0:
        D_8010BC7F = 1;
        // fallthrough
    case 1:

        for (i = 0; i < 7; ++i) {
            func_800FE8B0(i);
        }
        func_80100414(0x7FE, 0x80);
        temp_v0 = vs_battle_getMenuItem(0);
        if ((temp_v0->state != 1) || (temp_v0->animSpeed != 0xB4)) {
            func_801029D0(0, 0x57);
        }
        *state = 2;
        break;
    case 2:
        if (vs_mainmenu_ready() != 0) {
            for (i = 0; i < 6; ++i) {
                sp10[i * 2] =
                    (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text[i * 2 + 1]];
                sp10[i * 2 + 1] =
                    (char*)&vs_mainMenu_menu12Text[vs_mainMenu_menu12Text[i * 2 + 2]];
                D_800F4E84[i] = 0;
            }

            i = func_800FEA6C(0, 0);
            if (i == 8) {
                sp10[1] =
                    (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_weaponsFull];
                D_800F4E84[0] = 1;
            }
            if (i == 0) {
                sp10[7] = (char*)&vs_mainMenu_menu12Text[VS_MENU12_BIN_OFFSET_noWeapons];
                D_800F4E84[3] = 1;
            }
            _isLocationWorkshop = vs_battle_isLocationWorkshop();
            if (!_isLocationWorkshop) {
                for (i = 3; i != 0;) {
                    if (++i == 6) {
                        i = 0;
                    }
                    sp10[i * 2 + 1] = (char*)&vs_mainMenu_menu12Text
                        [VS_MENU12_BIN_OFFSET_notInWorkshop];
                    D_800F4E84[i] = 1;
                }
            }
            i = vs_main_settings.cursorMemory;
            if (D_8010BC7F == 0) {
                vs_main_settings.cursorMemory = 1;
            }
            D_8010BC7F = 0;
            vs_mainmenu_setMenuRows(6, 0x135, sp10, D_800F4E84);
            vs_main_settings.cursorMemory = i;
            *state = 3;
        }
        break;
    case 3:
        func_800FF9E4(func_801008B0(), D_801023D0);
        temp_v0_5 = vs_mainmenu_getSelectedRow();
        i = temp_v0_5 + 1;
        if (i != 0) {
            if (i < 0) {
                func_800FA8E0(0x28);
                if (i == -2) {
                    D_800F514C = 0;
                    *state = 0xB;
                } else {
                    vs_battle_menuState.currentState = vs_battle_menuState.returnState;
                    vs_battle_menuState.returnState = 0;
                    D_800F4EA0 &= ~0x200;
                    *state = 0;
                }
            } else {
                switch (temp_v0_5) {
                case 0:
                    func_80104898(1);
                    *state = 4;
                    break;
                case 1:
                    func_801063E4(1);
                    *state = 5;
                    break;
                case 2:
                    func_80106C64(1);
                    *state = 6;
                    break;
                case 3:
                    func_80106ECC(1);
                    *state = 7;
                    break;
                case 4:
                    func_801072FC(1);
                    *state = 8;
                    break;
                case 5:
                    func_8010A6BC(1);
                    *state = 9;
                    break;
                }
            }
        }
        break;
    case 4:
        i = func_80104898(0);
        if (i != 0) {
            if (i != -2) {
                *state = 0xA;
                if (i == 1) {
                    vs_battle_menuState.currentState = 8;
                    func_800FFBA8();
                } else {
                    func_800FFBC8();
                }
            } else {
                *state = 0xB;
            }
        }
        break;
    case 5:
        i = func_801063E4(0);
        if (i != 0) {
            if (i == -2) {
                *state = 0xB;
            } else {
                *state = 0xA;
            }
        }
        break;
    case 6:
        i = func_80106C64(0);
        if (i != 0) {
            if (i == -2) {
                *state = 0xB;
            } else {
                *state = 0xA;
            }
        }
        break;
    case 7:
        i = func_80106ECC(0);
        if (i != 0) {
            if (i != -2) {
                *state = 0xA;
                if (i == 1) {
                    vs_battle_menuState.currentState = 8;
                }
            } else {
                *state = 0xB;
            }
        }
        break;
    case 8:
        i = func_801072FC(0);
        if (i != 0) {
            if (i == -2) {
                *state = 0xB;
            } else {
                *state = 0xA;
            }
        }
        break;
    case 9:
        i = func_8010A6BC(0);
        if (i != 0) {
            if (i == -2) {
                *state = 0xB;
            } else {
                *state = 0xA;
            }
        }
        break;
    case 10:
        func_800FFBC8();
        if (vs_mainmenu_ready() != 0) {
            *state = 1;
        }
        break;
    case 11:
        vs_battle_menuState.currentState = vs_battle_menuState.returnState;
        vs_battle_menuState.returnState = 1;
        D_800F4EA0 &= ~0x200;
        *state = 0;
        break;
    }
    return 0;
}

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010AE38);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010B150);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010B2B4);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010B598);

INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010B80C);

// Potentially 2.7.2
// https://decomp.me/scratch/yg4QQ
INCLUDE_ASM("build/src/MENU/MENUC.PRG/nonmatchings/168", func_8010BA58);
