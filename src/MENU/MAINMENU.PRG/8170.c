#include "common.h"
#include "8170.h"
#include "C48.h"
#include "413C.h"
#include "../BATTLE/BATTLE.PRG/5BF94.h"

extern u_long* D_1F800000[];

extern char const D_800F9A04[];
extern char const D_800F9A08[];

void func_80101970(void)
{
    int target;
    int origin;
    int temp_a1;
    int temp_s0;
    int j;
    int i;
    int var_v1;
    u_long* temp_s3;
    vs_battle_menuItem_t* menuItem = vs_battle_menuItems;

    for (i = 0; i < 40; ++i, ++menuItem) {
        j = menuItem->state;

        if (j == 0) {
            continue;
        }

        switch (j) {
        case 1:
            break;
        case 2:
            origin = menuItem->initialX;
            target = menuItem->targetX;
            if (origin < target) {
                origin += 32;
                if (target < origin) {
                    origin = target;
                }
            } else {
                if (target < origin) {
                    for (j = 1; j < 16; ++j) {
                        if ((target + vs_battle_rowAnimationSteps[j]) >= origin) {
                            break;
                        }
                    }
                    origin = target + vs_battle_rowAnimationSteps[j - 1];
                    if (target >= 155) {
                        if (menuItem->w < (320 - origin)) {
                            menuItem->w = 64 - origin;
                            if ((320 - origin) > 165) {
                                menuItem->w = 165;
                            }
                        }
                    }
                }
            }
            menuItem->initialX = origin;
            if (origin == target) {
                menuItem->state = 1;
            }
            break;
        case 3:
            origin = menuItem->y;
            target = menuItem->targetX;
            if (origin < target) {
                for (j = 1; j < 16; ++j) {
                    if (origin >= (target - vs_battle_rowAnimationSteps[j])) {
                        break;
                    }
                }
                origin = target - vs_battle_rowAnimationSteps[j - 1];
            } else {
                if (target < origin) {
                    for (j = 1; j < 16; ++j) {
                        if ((target + vs_battle_rowAnimationSteps[j]) >= origin) {
                            break;
                        }
                    }
                    origin = target + vs_battle_rowAnimationSteps[j - 1];
                }
            }
            menuItem->y = origin;
            if (origin == target) {
                menuItem->state = 1;
            }
            break;
        case 4:
            origin = menuItem->initialX;
            target = menuItem->targetX;
            if (origin != target) {
                for (j = 1; j < 16; ++j) {
                    if ((target + vs_battle_rowAnimationSteps[j]) >= origin) {
                        break;
                    }
                }
                menuItem->initialX = vs_battle_rowAnimationSteps[j - 1] + target;
                if (menuItem->w < (320 - menuItem->initialX)) {
                    menuItem->w = (64 - menuItem->initialX);
                }
            } else {
                origin = menuItem->y;
                target = menuItem->unk1A;
                if (origin != target) {
                    for (j = 1; j < 16; ++j) {
                        if ((target + vs_battle_rowAnimationSteps[j]) >= origin) {
                            break;
                        }
                    }
                    menuItem->y = vs_battle_rowAnimationSteps[j - 1] + target;
                }
                if (menuItem->y == target) {
                    menuItem->state = 1;
                }
            }
            break;
        case 5:
            origin = menuItem->initialX;
            target = menuItem->targetX;
            if (target < origin) {
                origin -= 32;
                if (origin < target) {
                    origin = target;
                }
                if (-menuItem->w >= origin) {
                    menuItem->state = 0;
                }
            } else {
                if (origin < target) {
                    for (j = 1; j < 16; ++j) {
                        if (origin >= (target - vs_battle_rowAnimationSteps[j])) {
                            break;
                        }
                    }
                    origin = target - vs_battle_rowAnimationSteps[j - 1];
                }
            }
            menuItem->initialX = origin;
            if (origin == target) {
                if (origin < 0) {
                    menuItem->state = 0;
                } else {
                    menuItem->state = 1;
                }
            }
            break;
        }
        if (D_801022D6 == 0) {
            j = menuItem->unk12;
            temp_s3 = D_1F800000[2] + 2;
            if (j != 0) {
                if (menuItem->w == 126) {
                    var_v1 = menuItem->initialX + 116;
                    origin = var_v1 | ((menuItem->y + 1) << 0x10);
                } else {
                    var_v1 = (((menuItem->initialX * 19) >> 4) + 96) & 0xFFFF;
                    origin = var_v1 | ((menuItem->y + 1) << 0x10);
                }
                func_800FFE70(j, origin, temp_s3);
                temp_s0 = origin - 30;
                vs_battle_renderTextRaw(D_800F9A04, temp_s0, temp_s3);
                func_800FFE70(menuItem->unk10, temp_s0, temp_s3);
                if ((menuItem->y == 18) && (menuItem->initialX < 96)) {
                    func_800FFE70(menuItem->unkE, origin + 32, temp_s3);
                    vs_battle_renderTextRaw(D_800F9A08, origin, temp_s3);
                }
            } else {
                j = menuItem->unk10;
                if (j != 0) {
                    vs_battle_renderValue(0,
                        ((menuItem->initialX + menuItem->w) - 16)
                            | ((menuItem->y + 3) << 0x10),
                        j, temp_s3);
                }
            }
            if (menuItem->initialX < 320) {
                if (menuItem->unk5 != 0) {
                    func_8010154C(menuItem);
                } else {
                    func_800C9078(menuItem);
                }
                j = menuItem->itemState;
                if (j != 0) {
                    func_800FFFBC(
                        j - 1, (menuItem->initialX - 24) | ((menuItem->y - 3) << 0x10));
                }
            }
            j = menuItem->unk8;
            if (j != 0) {
                vs_mainmenu_drawButton(
                    j - 1, menuItem->initialX + 5, menuItem->y - 2, NULL);
            }
            j = menuItem->icon;
            if (j != 0) {
                vs_mainMenu_drawRowIcon(
                    (menuItem->unk5 << 0x10) | (menuItem->selected << 8) | j,
                    menuItem->initialX, menuItem->y - 2);
            }
            j = menuItem->material;
            if (j != 0) {
                func_800FFF38(
                    j - 1, (menuItem->initialX + 13) | ((menuItem->y - 3) << 0x10));
            }
        }
    }
}

void func_80101F38(void)
{
    int var_s0;

    var_s0 = D_801022D8;
    if (D_801023D4 != NULL) {
        func_80100A5C();
    }
    if (D_801022DC != 0) {
        var_s0 = var_s0 + 2;
        if (var_s0 >= 17) {
            var_s0 = 16;
        }
    } else {
        var_s0 = var_s0 - 2;
        if (var_s0 < 0) {
            var_s0 = 0;
        }
    }
    D_801022D8 = var_s0;
    if (var_s0 != 0) {
        func_80101118(var_s0);
    }
    if (vs_battle_shortcutInvoked == 0) {
        func_800FFA94();
    }
    if (vs_battle_menuItems != 0) {
        func_80101970();
    }
    func_80100164();
    vs_mainMenu_drawClassAffinityType(0);
    vs_battle_renderEquipStats(0);
    vs_mainMenu_drawDpPpbars(0);
}
