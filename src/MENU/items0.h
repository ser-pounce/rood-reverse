#include "src/SLUS_010.40/main.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "gpu.h"
#include <libetc.h>

extern void* D_1F800000[];

/**
 * Process L1/R1 input.
 *
 * @return The new page to display.
 */
static int _itemPaging(int items, int page)
{
    if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {

        int previousPage = page;

        items = vs_mainMenu_getItemCount(items, NULL);

        if (vs_main_buttonRepeat & PADL1) {
            page += items - 1;
        }

        if (vs_main_buttonRepeat & PADR1) {
            ++page;
        }

        if (page >= items) {
            page -= items;
        }

        if ((vs_main_buttonsPressed.all & (PADL1 | PADR1)) && (page == previousPage)) {
            vs_battle_playInvalidSfx();
        }
    }

    return page;
}

/**
 * Draws the item categories, optionally highlighting the selection.
 */
static void _renderItemCategory(int animationStep, int highlightSelected)
{
    int i;
    int selectedCategory = (D_800F4EE8.unk3A.currentItemCategory - 1) & 7;

    if (animationStep == 4) {
        func_801013F8(0);
    }

    animationStep = (animationStep * 8) - 16;

    for (i = 0; i < 8; ++i) {
        u_long* texPage;
        int x = (((i + 1) & 7) * 16) + 32;

        if (i == selectedCategory && highlightSelected == 1) {

            vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(31);

            if (x >= (menuItem->x - 12)) {
                menuItem->icon = i + 24;
                continue;
            }

            texPage = vs_battle_setSpriteDefault(vs_getWH(16, 16), x | (16 << 16));

        } else {
            texPage = vs_battle_setSpriteDefaultTexPage(
                128, x | (animationStep << 0x10), vs_getWH(16, 16), D_1F800000[1]);
        }

        texPage[4] = (120 + i * 16) | (128 << 8)
                   | (i == selectedCategory ? vs_getUV0Clut(0, 0, 976, 223)
                                            : vs_getUV0Clut(0, 0, 992, 223));
    }
}

/**
 * Hoists the item category and selected item to the top of the menu
 * during the start of the menu transition animation.
 */
static void _startMenuTransition(int id)
{
    vs_battle_menuItem_t* menuItem;

    vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);

    menuItem = vs_battle_getMenuItem(31);
    menuItem->state = menuItemTransition_toTop;
    menuItem->targetPosition0 = 18;

    menuItem = vs_battle_getMenuItem(id);
    menuItem->state = menuItemTransition_toLeft;
    menuItem->targetPosition0 = 155;
    menuItem->selected = 1;
    menuItem->subText = NULL;
}

/**
 * Outdents the category and hoists the selected row to the top.
 */
static void _continueMenuTransition(int id)
{
    vs_battle_menuItem_t* menuItem = vs_battle_getMenuItem(31);
    menuItem->state = menuItemTransition_toLeft;
    menuItem->targetPosition0 = 16;
    menuItem->w = 164;

    menuItem = vs_battle_getMenuItem(id);
    menuItem->state = menuItemTransition_toTop;
    menuItem->targetPosition0 = 18;
}
