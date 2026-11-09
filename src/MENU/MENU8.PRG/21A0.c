#include "common.h"
#include "21A0.h"
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/inventory.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/BATTLE/BATTLE.PRG/battleUi.h"
#include "src/BATTLE/BATTLE.PRG/uiEquipment.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "build/assets/MENU/MENU8.PRG/rename.h"
#include "gpu.h"
#include "scratch.h"
#include "vs_string.h"
#include <libetc.h>

static u_char weaponId;
static UNUSED char _1;
static char showRenameInterface;
static u_char animStep;
static UNUSED char _2[2];
static char* charTable;
static UNUSED char _3[8];
static char stringBufStatic[20];

// Purpose unclear.
static char D_80105DB0 = 0;

/**
 * Manages character insertion and deletion.
 */
static int insertDeleteHandler(int bufPos)
{
    int previousPos;
    int i;

    D_80105DB0 = 1;
    previousPos = bufPos;

    if (vs_main_buttonRepeat & PADRup) {

        vs_battle_playMenuChangeSfx();

        for (i = 19; bufPos < i; --i) {
            stringBufStatic[i] = stringBufStatic[i - 1];
        }

        stringBufStatic[bufPos] = vs_char_space;

    } else if (vs_main_buttonRepeat & PADRleft) {

        vs_battle_playMenuChangeSfx();

        for (i = bufPos; i < 19; ++i) {
            stringBufStatic[i] = stringBufStatic[i + 1];
        }

        stringBufStatic[19] = vs_char_space;

    } else if ((vs_main_buttonsState & (PADL1 | PADR1)) != (PADL1 | PADR1)) {

        if (vs_main_buttonRepeat & PADL1) {
            if (bufPos == 0) {
                if (vs_main_buttonsPressed.all & PADL1) {
                    bufPos = 19;
                }
            } else {
                --bufPos;
            }
        }

        if (vs_main_buttonRepeat & PADR1) {
            if (bufPos == 19) {
                if (vs_main_buttonsPressed.all & PADR1) {
                    bufPos = 0;
                }
            } else {
                ++bufPos;
            }
        }
    }

    if (bufPos != previousPos) {
        vs_battle_playMenuChangeSfx();
    }

    return bufPos;
}

/**
 * Copies the current name buffer, trimming spaces from the end.
 *
 * @return 1 if the final string is empty, 0 otherwise.
 */
static int copyNormalizedString(char* stringBuf)
{
    int pos;
    int i;

    for (pos = 0, i = 0; i < 20; ++pos, ++i) {
        if (stringBufStatic[i] == vs_char_terminator) {
            break;
        }
        stringBuf[pos] = stringBufStatic[i];
    }

    stringBuf[pos--] = vs_char_terminator;

    while (stringBuf[pos] == vs_char_space) {
        stringBuf[pos--] = vs_char_terminator;
        if (pos < 0) {
            return 1;
        }
    }

    pos += 2;

    while (pos < 24) {
        stringBuf[pos++] = vs_char_zero;
    }

    return 0;
}

static char nameNavIconAnim = 0;
static u_char selectedControllerAction = 0;
static u_short renderRenameMenuStrings[] = {
#include "build/assets/MENU/MENU8.PRG/rename.vsString"
};

/**
 * Renders all UI elements.
 *
 * @param xOffset Used during animation, 0 normally.
 */
static void renderRenameMenu(int xOffset)
{
    static int backgroundHexCoords[] = { vs_getXY(216, 72), vs_getXY(142, 180),
        vs_getXY(112, 72), vs_getXY(112, 224), vs_getXY(216, 72), vs_getXY(216, 224),
        vs_getXY(142, 180), vs_getXY(112, 224), vs_getXY(216, 72), vs_getXY(290, 180),
        vs_getXY(216, 224), vs_getXY(320, 224), vs_getXY(216, 72), vs_getXY(320, 72),
        vs_getXY(290, 180), vs_getXY(320, 224) };

    static char namePlaceHolder[] = { vs_char_terminator, vs_char_terminator,
        vs_char_terminator, vs_char_terminator };
    static char controllerActionAnimationCounters[8] = { 0 };
    // Seemingly no purpose, perhaps an unimplemented animation
    static char D_80105EF4 = 0;

    u_int* sp18;
    int x;
    int y;
    int j;
    int i;
    char* commandString;
    u_long* prim;
    int counter;

    sp18 = (u_int*)vs_scratch.unk4 - 1;

    vs_mainmenu_renderButton(buttonIdCross, (-xOffset + 16), 50, 0);
    vs_mainmenu_renderButton(buttonIdSquare, (-xOffset + 16), 66, 0);
    vs_mainmenu_renderButton(buttonIdTriangle, (-xOffset + 16), 82, 0);
    prim = vs_battle_setSpriteDefault(
        vs_getWH(16, 16), ((-xOffset + 16) & 0xFFFF) | (34 << 16));
    prim[4] = vs_getUV0Clut(176, 112, 944, 223);

    prim += 6;

    controllerActionAnimationCounters[selectedControllerAction] = 8;
    selectedControllerAction = 0;

    for (i = 1; i < 5; ++i) {

        counter = controllerActionAnimationCounters[i];

        if (controllerActionAnimationCounters[i] != 0) {
            --controllerActionAnimationCounters[i];
        }

        x = vs_battle_uiGradientStop(8 - counter, 0, 128) | 0x50000000;
        y = vs_battle_uiGradientStop(counter, 0, 128);

        for (j = 0; j < 12; ++j) {
            int v1;

            prim[0] = (*sp18 & 0xFFFFFF) | 0x06000000;
            prim[1] = vs_getTpage(0, 0, 0, 0, 1);
            prim[2] = x;
            prim[3] = ((-xOffset) & 0xFFFF) | (j + 20 + i * 16) << 16;
            prim[4] = y;

            v1 = j - 96;

            prim[5] = ((-xOffset - v1) & 0xFFFF) | (j + 20 + i * 16) << 16;
            prim[6] = vs_getTpage(0, 0, 0, 0, 0);

            *sp18 = ((u_long)prim << 8) >> 8;

            prim += 7;
        }
    }

    vs_scratch.unk0 = prim;

    vs_battle_setFontStyle(4);

    for (i = 0; i < 4; ++i) {

        commandString =
            (char*)&renderRenameMenuStrings[renderRenameMenuStrings[VS_rename_INDEX_insert
                                                                    - i]];
        x = 40;

        while ((j = *commandString++) != vs_char_terminator) {
            vs_battle_printVariableWidthFontChar(
                j, x - xOffset, 84 - (i * 16), vs_scratch.unk4 - 0x14);

            x += 6;
        }
    }

    vs_battle_setMenuItem(29, xOffset + 156, 48, 164, 0, namePlaceHolder)->selected = 1;

    for (j = 0; j < 20; ++j) {
        counter = stringBufStatic[j];

        if (counter != vs_char_space) {

            int new_var3 = (j * 6 + 0xA2);

            vs_battle_printVariableWidthFontChar(
                counter, xOffset + new_var3, 0x30, vs_scratch.unk8 - 8);
        }
    }

    if (xOffset == 0) {
        u_long* a1;

        int color = vs_getRGB888(64, 64, 64);
        x = 0x37F9;

        if ((D_80105DB0 != 0) || (nameNavIconAnim != 11)) {

            color = vs_getRGB888(128, 128, 128);
            ++nameNavIconAnim;
            --x;

            if (nameNavIconAnim > 11) {
                nameNavIconAnim = 0;
            }
        }

        D_80105DB0 = 0;
        j = (nameNavIconAnim >> 2);

        vs_battle_renderTextRawColor("1", vs_getXY(152, 51), color, 0);
        vs_battle_renderTextRawColor("L", vs_getXY(146, 51), color, 0);
        vs_battle_setSpriteDefault(vs_getWH(16, 16), (136 - j) | (48 << 16))[4] =
            (x << 0x10) | vs_getUV(0, 48);
        vs_battle_renderTextRawColor("1", vs_getXY(292, 51), color, 0);
        vs_battle_renderTextRawColor("R", vs_getXY(286, 51), color, 0);
        vs_battle_setSpriteDefault(vs_getWH(16, 16), (j + 296) | (48 << 16))[4] =
            (x << 0x10) | vs_getUV(16, 48);

        a1 = vs_scratch.unk8;
        prim = vs_scratch.unk0;

        prim[0] = ((u_long)a1[0] & 0xFFFFFF) | 0x09000000;
        prim[1] = vs_getTpage(0, 0, 0, 0, 1);
        prim[2] = vs_getRGB0(primPolyG4, 0, 0, 0);
        prim[3] = vs_getRGB888(208, 0, 30);
        prim[4] = 0;
        prim[5] = vs_getRGB888(232, 0, 32);
        prim[6] = 0xC0A080;
        prim[7] = vs_getRGB888(232, 0, 46);
        prim[8] = 0;
        prim[9] = vs_getRGB888(0, 1, 30);

        ((u_long*)vs_scratch.unk8)[0] = ((u_long)prim << 8) >> 8;
        vs_scratch.unk0 = prim + 10;

        if (++D_80105EF4 >= 12) {
            D_80105EF4 = 0;
        }
    }

    commandString = (char*)(renderRenameMenuStrings + VS_rename_OFFSET_charTable);

    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 14; ++j) {

            int temp_s8 = (xOffset + 0x82);

            vs_battle_printVariableWidthFontChar(commandString[i * 15 + j],
                temp_s8 + j * 12, (i * 16) + 78, vs_scratch.unk8 - 8);
        }
    }

    for (j = 0; j < 16; j += 4) {
        prim = vs_scratch.unk0;

        prim[0] = (*sp18 & 0xFFFFFF) | 0x09000000;
        prim[1] = vs_getTpage(0, 0, 0, 0, 1);
        prim[2] = vs_getRGB0(primPolyG4, 0, 65, 107);
        prim[3] = xOffset + backgroundHexCoords[j];
        prim[4] = vs_getRGB888(0, 5, 51);
        prim[5] = xOffset + backgroundHexCoords[j + 1];
        prim[6] = vs_getRGB888(0, 5, 51);
        prim[7] = xOffset + backgroundHexCoords[j + 2];
        prim[8] = vs_getRGB888(0, 5, 51);
        prim[9] = xOffset + backgroundHexCoords[j + 3];

        *sp18 = ((u_long)prim << 8) >> 8;
        vs_scratch.unk0 = (u_long*)(prim + 10);
    }
}

/**
 * Draws the cursor box at the specified location.
 */
static void highlightSelection(int x, int y, int w, int h)
{
    u_long* temp_t0;
    u_long* temp_t4;

    temp_t4 = vs_scratch.unk8;
    temp_t0 = vs_scratch.unk0;

    temp_t0[0] = (*temp_t4 & 0xFFFFFF) | 0x09000000;
    temp_t0[1] = vs_getTpage(0, 0, 0, semiTransparencyFull, ditheringOn);
    temp_t0[2] = vs_getRGB0(primPolyG4SemiTrans, 128, 160, 192);
    temp_t0[3] = (x | (y << 16));
    temp_t0[4] = 0;
    temp_t0[5] = (x + w) | (y << 16);
    temp_t0[6] = 0;
    temp_t0[7] = x | ((y + h) << 16);
    temp_t0[8] = vs_getRGB888(128, 160, 192);
    temp_t0[9] = (x + w) | ((y + h) << 16);

    *temp_t4 = ((u_long)temp_t0 << 8) >> 8;
    vs_scratch.unk0 = temp_t0 + 10;
}

/**
 * Highlights the currently selected character.
 *
 * @return The new cursor animation state.
 */
static int highlightCharSelection(int cursorState, int column, int row)
{
    int x;
    int y;

    x = column * 12;
    y = row * 16;

    highlightSelection(x + 128, y + 76, 10, 18);

    return vs_mainMenu_renderCursor(cursorState, (x + 112) | ((y + 66) << 16));
}

/**
 * Manages input during the confirmation screen.
 *
 * @return Positive row if selected, 0 otherwise.
 */
static int confirmationScreen(int init)
{
    static char cursorState = 0;
    static UNUSED int _0[] = { 0x01002AFA, 0x00E79CF1 }; // Junk string?

    static char state;
    static char selectedRow;
    static UNUSED char _1[14];

    int i;

    if (init != 0) {
        selectedRow = 0;
        state = 0;
    }

    switch (state) {
    case 0:
    case 1:
    case 2: {
        vs_battle_menuItem_t* menuItem =
            vs_battle_setMenuItem(state + 20, 320, (state * 16) + 128, 0x7E, 0,
                (char*)&renderRenameMenuStrings
                    [renderRenameMenuStrings[state + VS_rename_INDEX_optionYes]]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 194;
        ++state;
        break;
    }

    case 3:
        state += vs_mainmenu_ready();
        break;

    case 4:
        for (i = 0; i < 3; ++i) {
            vs_battle_getMenuItem(i + 20)->selected = (selectedRow ^ i) == 0;
        }

        if (vs_main_buttonsPressed.all & (PADRright | PADRdown)) {

            for (i = 0; i < 3; ++i) {
                vs_mainMenu_menuItemFlyoutRight(i + 20);
            }

            if (vs_main_buttonsPressed.all & PADRdown) {
                selectedRow = 1;
            }

            return selectedRow + 1;
        }

        i = selectedRow;

        if (vs_main_buttonRepeat & PADLup) {
            i += 2;
        }

        if (vs_main_buttonRepeat & PADLdown) {
            ++i;
        }

        if (i >= 3) {
            i -= 3;
        }

        if (i != selectedRow) {
            vs_battle_playMenuChangeSfx();
            selectedRow = i;
        }

        cursorState = vs_battle_drawCursor(cursorState, i + 7);
        break;
    }
    return 0;
}

/**
 * Used both when selecting the controller buttons with the cursor,
 * and when selecting the row on the confirmation screen.
 */
static void updateMenuSelection(int row)
{
    int i;

    if (row < 4) {
        selectedControllerAction = row + 1;
    }

    for (i = 4; i < 9; ++i) {
        vs_battle_getMenuItem(i + 29)->selected = i == row;
    }
}

/**
 * Input handling for the rename screen.
 *
 * @return 1 if the rename is complete or cancelled, 0 otherwise.
 */
static int renameMenuInput(int initialize)
{
    enum state {
        init,
        state1,
        state2,
        leaveRenameScreen,
        initConfirmationScreen,
        confirmationScreenState,
        returnToRenameScreen
    };

    static char nameBuffer[24];
    static char state;
    static char cursorAnimState;
    static char charTableColumn;
    static char charTableRow;
    static u_char currentPos;
    static UNUSED char D_80105F2D;
    int selectedRow;
    int var_a1;
    int var_s1;
    vs_main_inventoryWeapon* weapon;

    if (initialize != 0) {
        charTableColumn = 0;
        charTableRow = 0;
        currentPos = 0;
        D_80105F2D = 0;
        cursorAnimState = 8;
        state = init;

        return 0;
    }

    switch (state) {
    case init:
        // cursorAnimState miused as a delay
        if (cursorAnimState != 0) {
            --cursorAnimState;
        } else {
            state = 2;
        }
        break;

    case 1:
        currentPos = insertDeleteHandler(currentPos);

        if (vs_main_buttonsPressed.all & PADstart) {
            vs_battle_playMenuSelectSfx();
            updateMenuSelection(255);

            state = leaveRenameScreen;
            break;
        }

        if (vs_main_buttonRepeat & (1 << 6)) {
            vs_battle_playMenuChangeSfx();

            if (currentPos != 0) {

                --currentPos;

                for (var_s1 = currentPos; var_s1 < 19; ++var_s1) {
                    stringBufStatic[var_s1] = stringBufStatic[var_s1 + 1];
                }

                stringBufStatic[19] = 0x8F;
            }
        }

        var_s1 = charTableRow;

        if (vs_main_buttonsPressed.all & (1 << 13)) {

            vs_battle_playMenuChangeSfx();
            updateMenuSelection(255);

            if (var_s1 == 3) {
                var_s1 = 1;
            } else {
                var_s1 = 0;
            }

            charTableRow = var_s1;
            state = 2;

            break;
        }

        if (vs_main_buttonsPressed.all & (1 << 5)) {

            switch (var_s1) {
            case 0:
                vs_battle_playMenuSelectSfx();
                updateMenuSelection(255);
                state = 3;
                break;

            case 1:
                if (currentPos != 0) {

                    --currentPos;

                    for (var_a1 = currentPos; var_a1 < 19; ++var_a1) {
                        stringBufStatic[var_a1] = stringBufStatic[var_a1 + 1];
                    }

                    stringBufStatic[19] = vs_char_space;
                }

                break;

            case 2:
                for (var_a1 = currentPos; var_a1 < 0x13; ++var_a1) {
                    stringBufStatic[var_a1] = stringBufStatic[var_a1 + 1];
                }

                stringBufStatic[19] = vs_char_space;
                break;

            case 3:
                for (var_a1 = 0x13; currentPos < var_a1; --var_a1) {
                    stringBufStatic[var_a1] = stringBufStatic[var_a1 - 1];
                }

                stringBufStatic[currentPos] = vs_char_space;
                break;
            }

            if (state != 1) {
                break;
            }

            vs_battle_playMenuChangeSfx();
        }

        if (vs_main_buttonRepeat & (1 << 12)) {
            if (var_s1 == 0) {
                if (vs_main_buttonsPressed.all & (1 << 12)) {
                    var_s1 = 3;
                }
            } else {
                --var_s1;
            }
        }

        if (vs_main_buttonRepeat & (1 << 14)) {
            if (var_s1 == 3) {
                if (vs_main_buttonsPressed.all & (1 << 14)) {
                    var_s1 = 0;
                }
            } else {
                ++var_s1;
            }
        }

        if (var_s1 != charTableRow) {
            vs_battle_playMenuChangeSfx();
            charTableRow = var_s1;
        }

        updateMenuSelection(var_s1);

        cursorAnimState =
            vs_mainMenu_renderCursor(cursorAnimState, ((var_s1 * 16) + 28) << 16);
        break;

    case 2:
        currentPos = insertDeleteHandler(currentPos);

        if (vs_main_buttonsPressed.all & (1 << 11)) {
            vs_battle_playMenuSelectSfx();
            state = 3;
            break;
        }

        if (vs_main_buttonsPressed.all & (1 << 5)) {

            vs_battle_playMenuChangeSfx();

            var_s1 = charTable[charTableColumn + (charTableRow * 15)];
            stringBufStatic[currentPos] = var_s1;

            if (currentPos < 19) {
                ++currentPos;
            }
        }

        if (vs_main_buttonRepeat & (1 << 6)) {

            vs_battle_playMenuChangeSfx();

            if (currentPos != 0) {
                --currentPos;
                for (var_s1 = currentPos; var_s1 < 19; ++var_s1) {
                    stringBufStatic[var_s1] = stringBufStatic[var_s1 + 1];
                }

                stringBufStatic[19] = vs_char_space;
            }
        }

        var_a1 = charTableColumn + (charTableRow * 14);

        if (vs_main_buttonRepeat & (1 << 12)) {
            if (charTableRow != 0) {
                --charTableRow;
            } else if (vs_main_buttonsPressed.all & (1 << 12)) {
                charTableRow = 8;
            }
        }

        if (vs_main_buttonRepeat & (1 << 14)) {
            if (charTableRow == 8) {
                if (vs_main_buttonsPressed.all & (1 << 14)) {
                    charTableRow = state != 2;
                }
            } else {
                ++charTableRow;
            }
        }

        if (vs_main_buttonRepeat & (1 << 15)) {
            if (charTableColumn == 0) {
                if (vs_main_buttonsPressed.all & (1 << 15)) {

                    vs_battle_playMenuChangeSfx();

                    if (charTableRow == 0) {
                        charTableRow = 2;
                    } else {
                        charTableRow = 3;
                    }

                    state = 1;
                    break;
                }
            } else {
                --charTableColumn;
            }
        }

        if (vs_main_buttonRepeat & (1 << 13)) {
            if (charTableColumn == 13) {
                if (vs_main_buttonsPressed.all & (1 << 13)) {
                    charTableColumn = 0;
                }
            } else {
                ++charTableColumn;
            }
        }

        if (var_a1 != (charTableColumn + (charTableRow * 14))) {
            vs_battle_playMenuChangeSfx();
        }

        break;

    case leaveRenameScreen:
        updateMenuSelection(0);

        showRenameInterface = 0;
        state = initConfirmationScreen;
        break;

    case initConfirmationScreen:
        if (animStep != 10) {
            break;
        }

        if (copyNormalizedString(nameBuffer) != 0) {
            vs_battle_rMemcpy(nameBuffer,
                vs_mainMenu_itemNames
                    + vs_main_inventory
                        .blades[vs_main_inventory.weapons[weaponId].blade - 1]
                        .id,
                0x18);
        }

        vs_battle_initInformationTextBox(1);

        vs_battle_stringContext.strings[0] = nameBuffer;

        vs_battle_printf(vs_battle_stringBuf,
            (char*)(renderRenameMenuStrings + VS_rename_OFFSET_confirmPrompt));

        vs_mainmenu_setInformationMessage(vs_battle_stringBuf);
        confirmationScreen(1);

        state = confirmationScreenState;
        break;

    case confirmationScreenState:
        selectedRow = confirmationScreen(0);

        if (selectedRow == 0) {
            break;
        }

        vs_battle_dismissTextBox(7);

        if (selectedRow == 2) {
            vs_battle_playMenuLeaveSfx();
            showRenameInterface = 1;
            state = returnToRenameScreen;
            break;
        }

        weapon = &vs_main_inventory.weapons[weaponId];

        if (selectedRow == 1) {
            vs_main_playSfxDefault(0x7E, 0xD);
            vs_battle_rMemcpy(weapon->name, nameBuffer, sizeof nameBuffer);

            if (weapon->isEquipped != 0) {
                vs_battle_equipWeapon(weapon);
            }
        } else {
            vs_battle_playMenuLeaveSfx();

            if (weapon->name[0] == vs_char_terminator) {
                vs_battle_rMemcpy(weapon->name,
                    vs_mainMenu_itemNames
                        + vs_main_inventory.blades[weapon->blade - 1].id,
                    sizeof weapon->name);
            }
        }

        return 1;

    case returnToRenameScreen:
        if (animStep == 0) {
            charTableColumn = 0;
            charTableRow = 0;
            state = 2;
        }
        break;
    }

    if (state == 2) {
        cursorAnimState =
            highlightCharSelection(cursorAnimState, charTableColumn, charTableRow);
    }

    if (((state - 1)) < 2U) {
        highlightSelection((currentPos * 6) + 161, 48, 8, 12);
    }

    return 0;
}

/**
 * Module entrypoint.
 *
 * @return Always 0, no handling for terminating main menu.
 */
int vs_menu8_execRename(char* state)
{
    int i;
    int currentState;
    char* var_v1;
    char* var_v0;
    int v1;

    currentState = *state;

    switch (*state) {
    case 0:
        weaponId = vs_battle_stringBuf[1];
        charTable = (char*)(renderRenameMenuStrings + VS_rename_OFFSET_charTable);

        vs_mainMenu_dismissInformationBox();

        v1 = vs_char_space;
        i = 19;
        var_v0 = &stringBufStatic[i];

        for (; i >= 0; --i) {
            *var_v0-- = v1;
        }

        if (vs_battle_stringBuf[0] == 1) {
            var_v1 = vs_main_inventory.weapons[weaponId].name;
            for (i = 0; i < 20; ++i) {
                int c = *var_v1++;
                if (c == vs_char_terminator) {
                    break;
                } else if (c == vs_char_space) {
                    continue;
                } else if (c == vs_char_spacing) {
                    ++var_v1;
                } else {
                    stringBufStatic[i] = c;
                }
            }
        }

        showRenameInterface = 0;
        animStep = 10;
        *state = 1;
        break;

    case 1:
        renameMenuInput(1);

        showRenameInterface = 1;
        *state = 2;
        break;

    case 2:
        if (renameMenuInput(0) != 0) {
            vs_mainMenu_menuItemFlyoutRight(0xA);
            vs_mainMenu_menuItemFlyoutLeft(0);
            vs_mainMenu_initInformationBox();

            *state = 3;
        }
        break;

    case 3:
        if (animStep == 10) {
            *state = 0;
            vs_battle_menuState.currentMenu = 13;
        }

        break;
    }

    if (showRenameInterface != 0) {
        if (animStep != 0) {
            --animStep;
        }
        renderRenameMenu(vs_battle_rowAnimationSteps[animStep]);
    } else if (animStep < 10) {
        ++animStep;
        renderRenameMenu(animStep << 5);
    }

    return 0;
}
