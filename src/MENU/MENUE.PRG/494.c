#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/sfx.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "gpu.h"
#include "lbaMacros.h"
#include "lbas.h"
#include "vs_string.h"
#include "insertTPage.h"
#include <libetc.h>
#include <stdio.h>
#include <libgpu.h>

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} _menuBgTransparencies_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
} _menuBgChunkWidths_t;

enum arrowType_e {
    arrowTypeUp,
    arrowTypeDown,
};

typedef struct {
    short enabled;
    u_short frameMask;
    short frameDuration;
    short repeat;
    short currentFrame;
    short timer;
    short isActive;
} AnimationState_t;

static char* _vsStrcpy(char* arg0, char* arg1);
static int _initMenuState(void);
static int _showMenu(void);
static void _drawSprite(short*);
static void _drawPaginationArrow(enum arrowType_e arrowType);
static void _drawContentLines(void);
static short _getAnimationState(AnimationState_t* arg0);
static int _topMenu(int arg0);
static void _copySprites(u_long const* arg0, int arg1);
static void _copyCluts(u_long* arg0, int arg1);
static int _getRoundedLineCount(void);
static void _copyNextPageText(void);
static void _drawContent(void);
static void _setPageBg(int arg0, int arg1, int arg2, int arg3, int arg4);
static void _fadeMenuUpper(void);
static void _fadeMenuLower(void);
static void _drawControlsBg(int x, int y, int w, int h);

static void func_80102C94(int arg0) __attribute__((unused));
void func_80102C94(int arg0)
{
    if (arg0 != 0) {
        func_800FFA88(2);
        D_801022D6 = 0;
        return;
    }
    func_800FFA88(0);
    D_801022D6 = 1;
}

static void _setMenuRows(int rowCount, int highlightedRow, char** strings)
{
    int rowTypes[rowCount];
    int i;
    char cursor;

    for (i = 0; i < rowCount; ++i) {
        rowTypes[i] = 0;
    }

    rowTypes[rowCount - 1] |= 4;

    if ((rowCount < 9) || (highlightedRow < 8)) {
        D_800F4EE8.unk0[4] = highlightedRow;
        D_800F4EE8.unk0[5] = 0;
    } else if (highlightedRow >= (rowCount - 8)) {
        D_800F4EE8.unk0[4] = highlightedRow - (rowCount - 9);
        D_800F4EE8.unk0[5] = rowCount - 9;
    } else {
        D_800F4EE8.unk0[4] = 4;
        D_800F4EE8.unk0[5] = highlightedRow - 4;
    }
    cursor = vs_main_settings.cursorMemory;
    vs_main_settings.cursorMemory = 1;
    vs_mainmenu_setMenuRows(rowCount, 0x102, strings, rowTypes);
    vs_main_settings.cursorMemory = cursor;
}

static int _getSelectedRow(void)
{
    int row;

    row = vs_mainmenu_getSelectedRow();
    if (row < -1) {
        func_800FA8E0(5);
        return row;
    }
    if (row >= 0) {
        func_800FA92C(D_800F4EE8.unk0[4], 1);
    }
    return row;
}

static void func_80102E48(char* text) __attribute__((unused));
void func_80102E48(char* text)
{
    vs_battle_menuItem_t* menuItem;

    menuItem = vs_battle_setMenuItem(10, 320, 34, 0x8C, 9, text);
    menuItem->state = 2;
    menuItem->x = 180;
    menuItem->selected = 1;
    menuItem->unkA = 1;
}

static void func_80102E9C(void) __attribute__((unused));
void func_80102E9C(void) { func_800FA8E0(8); }

static void _menuReady(void) { vs_mainmenu_ready(); }

static u_short _menuText[] = {
#include "../../assets/MENU/MENUE.PRG/menuText.vsString"
};

static u_short _0 __attribute__((unused)) = 0x0380;

int vs_menuE_exec(char* state)
{
    enum state { none, init = 3, initMenu, waitReady, showMenu, shutDown, exit };

    static int menuResult = 0;
    static char isInit = 0;
    static char D_8010522D = 0;
    static short _2 __attribute__((unused)) = 0x54;

    switch (*state) {
    case init:
        func_800FFB68(1);
        D_8010522D = 8;
        isInit = 0;
        *state = initMenu;
        break;
    case initMenu:
        if (isInit == 0) {
            isInit = _initMenuState();
        }
        if (D_8010522D != 0) {
            D_8010522D -= 1;
        } else if (isInit != 0) {
            func_8008A4DC(0);
            func_800CB654(1);
            D_800EB9B0 = 0x200000;
            *state = waitReady;
        }
        break;
    case waitReady:
        *state += vs_mainmenu_ready();
        break;
    case showMenu:
        menuResult = _showMenu();
        if (menuResult == 0) {
            break;
        }
        func_80100414(-4, 0x80);
        func_800CB654(0);
        D_800EB9B0 = 0;
        func_8008A4DC(1);
        func_800FFA88(0);
        func_800FA8E0(0x28);
        *state = shutDown;
        break;
    case shutDown:
        func_800FFB68(0);
        *state = exit;
        break;
    case exit:
        if (D_801022D8 != 0) {
            break;
        }
        if (menuResult == 2) {
            vs_battle_menuState.currentState = 10;
        }
        D_801022D6 = 0;
        *state = none;
        return 1;
    }
    return 0;
}

// Likely file split but...meh

static int _topMenu_state;
static int _selectedRow;
static vs_main_CdQueueSlot* _helpTextCdQueue;
static vs_main_CdQueueSlot* _helpAssetsCdQueue;
static int _showMenuState;
static int _scrollPosition;
static int _lineCount;
static int _pageArrowAnimState;
static int _helpPageLoadCounter;
static int* _helpText;
static u_long* _helpAssets;

static int _initMenuState(void)
{
    if (vs_main_settings.cursorMemory == 0) {
        vs_main_bzero(
            &vs_battle_manualDisplayState, sizeof(vs_battle_manualDisplayState));
    }
    func_8007DFF0(0x1D, 3, 5);
    _showMenuState = 0;
    _scrollPosition = 0;
    _lineCount = 0;
    _helpText = NULL;
    _helpAssets = NULL;
    return 1;
}

#include "../unused_vertices.h"

static vs_main_CdFile const _helpFileCdFiles[] = { mkHfoPair(HELP01), mkHfoPair(HELP02),
    mkHfoPair(HELP03), mkHfoPair(HELP04), mkHfoPair(HELP05), mkHfoPair(HELP06),
    mkHfoPair(HELP07), mkHfoPair(HELP08), mkHfoPair(HELP09), mkHfoPair(HELP10),
    mkHfoPair(HELP11), mkHfoPair(HELP12), mkHfoPair(HELP13), mkHfoPair(HELP14) };

static P_CODE const _colorStops0[] = { { 0, 0x20, 0x50, 0 }, { 0x19, 0x82, 0x6C, 0 },
    { 0x40, 0x30, 0x66, 0 }, { 0x40, 0x38, 0x20, 0 } };
static P_CODE const _colorStops1[] = { { 0, 0x5, 0x33, 0 }, { 0x1, 0x28, 0x26, 0 },
    { 0x8, 0x8, 0x20, 0 }, { 0x10, 0x10, 0x8, 0 } };

static int _showMenu(void)
{
    enum state {
        init,
        initMenu,
        getSelection,
        loadSubMenu,
        initSubMenu,
        showSubMenu,
        exitToMenu,
        exitToBattle,
    };

    char charBuf[60];
    int lastPage;
    int selectedRow;
    int currentPage;
    u_long** s0;
    int cdState;

    switch (_showMenuState) {
    case init:
        func_80100414(0x7FE, 0x80);
        ++_showMenuState;
        break;
    case initMenu:
        func_800FFBC8();
        _topMenu(1);
        ++_showMenuState;
        break;
    case getSelection:
        selectedRow = _topMenu(0);
        if (selectedRow == -1) {
            break;
        }
        if (selectedRow < 0) {
            if (selectedRow == -3) {
                _showMenuState = exitToBattle;
            } else {
                _showMenuState = exitToMenu;
            }
        } else {
            _showMenuState = loadSubMenu;
            if (_helpText != NULL) {
                vs_main_freeHeapR(_helpText);
            }
            if (_helpAssets != NULL) {
                vs_main_freeHeapR(_helpAssets);
            }

            _helpText = vs_main_allocHeapR(_helpFileCdFiles[selectedRow * 2 + 1].size);
            _helpAssets = vs_main_allocHeapR(_helpFileCdFiles[selectedRow * 2].size);
            _helpAssetsCdQueue =
                vs_main_allocateCdQueueSlot(&_helpFileCdFiles[selectedRow * 2]);
            vs_main_cdEnqueue(_helpAssetsCdQueue, _helpAssets);
            _helpTextCdQueue =
                vs_main_allocateCdQueueSlot(&_helpFileCdFiles[selectedRow * 2 + 1]);
            vs_main_cdEnqueue(_helpTextCdQueue, _helpText);
        }
        vs_battle_manualDisplayState.currentManual =
            D_800F4EE8.unk0[4] + D_800F4EE8.unk0[5];
        func_800FFBA8();
        break;
    case loadSubMenu:
        cdState = _helpAssetsCdQueue->state;
        if (cdState != vs_main_CdQueueStateLoaded) {
            break;
        }
        vs_main_freeCdQueueSlot(_helpAssetsCdQueue);
        _copySprites(_helpAssets + 2, _helpAssets[0]);
        _copyCluts(_helpAssets + ((_helpAssets[0] << 5) + 2), _helpAssets[1]);
        if (_helpAssets != NULL) {
            vs_main_freeHeapR(_helpAssets);
        }
        _helpAssets = NULL;
        _showMenuState = initSubMenu;
        break;
    case initSubMenu:
        if (_helpTextCdQueue->state != vs_main_CdQueueStateLoaded) {
            break;
        }
        vs_main_freeCdQueueSlot(_helpTextCdQueue);
        func_800CCF08(0, 0, 8, 0x34, 0x19, 0xA, 8, 0x34);
        _scrollPosition =
            vs_battle_manualDisplayState
                .scrollPositions[vs_battle_manualDisplayState.currentManual];
        _lineCount = _getRoundedLineCount();
        _showMenuState = showSubMenu;
        _helpPageLoadCounter = 0;
        break;
    case showSubMenu:
        currentPage = _scrollPosition / 10;
        lastPage = _lineCount / 10;
        if (vs_main_buttonsPressed.all & (PADRright | PADRdown)) {
            _showMenuState = initMenu;
        }
        if (vs_main_buttonsPressed.all & PADRup) {
            _showMenuState = 7;
        }
        if (vs_main_buttonsPressed.all & PADstart) {
            currentPage = 0;
            _scrollPosition = 0;
        } else if (vs_main_buttonsPreviousState & PADRleft) {
            if ((vs_main_buttonsPressed.all & PADLup) && (currentPage == 0)
                && (lastPage > 0)) {
                currentPage = lastPage;
                _scrollPosition = lastPage * 10;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            } else if ((vs_main_buttonsPressed.all & PADLdown)
                       && (currentPage == lastPage) && (lastPage > 0)) {
                currentPage = 0;
                _scrollPosition = 0;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            } else if ((vs_main_buttonRepeat & PADLup) && (currentPage > 0)) {
                --currentPage;
                _scrollPosition = currentPage * 10;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            } else if ((vs_main_buttonRepeat & PADLdown) && (currentPage < lastPage)) {
                ++currentPage;
                _scrollPosition = currentPage * 10;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            }
        } else {
            if ((vs_main_buttonsPressed.all & PADLup) && (_scrollPosition == 0)
                && (_lineCount > 0)) {
                _scrollPosition = _lineCount;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            } else if (vs_main_buttonsPressed.all & PADLdown
                       && (_scrollPosition == _lineCount) && (_scrollPosition > 0)) {
                _scrollPosition = 0;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            } else if ((vs_main_buttonRepeat & PADLup) && (_scrollPosition > 0)) {
                --_scrollPosition;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            } else if ((vs_main_buttonRepeat & PADLdown)
                       && (_scrollPosition < _lineCount)) {
                ++_scrollPosition;
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            }
        }
        s0 = (u_long**)getScratchAddr(0);
        vs_mainmenu_drawButton(1, 8, 16, s0[1] + 6);
        func_800C6540("TURN    PAGE", 0x12001C, 0x808080, s0[1] + 6);
        _drawControlsBg(0x10, 0x12, 0x60, 0xC);
        vs_mainmenu_drawButton(2, 8, 34, s0[1] + 6);
        func_800C6540("MENU", 0x24001C, 0x808080, s0[1] + 6);
        _drawControlsBg(0x10, 0x24, 0x40, 0xC);
        func_800C6540("PAGE", 0xC400D8, 0x808080, s0[1] + 7);
        sprintf(charBuf, "#%d/", currentPage + 1);
        func_800C6540(charBuf, 0xC40118, 0x808080, s0[1] + 7);
        sprintf(charBuf, "#%d", lastPage + 1);
        func_800C6540(charBuf, 0xC40130, 0x808080, s0[1] + 7);
        vs_battle_manualDisplayState
            .scrollPositions[vs_battle_manualDisplayState.currentManual] =
            _scrollPosition;
        if (_showMenuState != showSubMenu) {
            if (vs_main_buttonsPressed.all & PADRright) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            } else {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            }
            func_800CCDF4(0)->unk4[12] = 0;
            if (_helpText != NULL) {
                vs_main_freeHeapR(_helpText);
            }
            _helpText = NULL;
            break;
        }
        _setPageBg(8, 52, 310, 136, 0);
        _pageArrowAnimState = (_pageArrowAnimState + 1) & 0xF;
        if (_scrollPosition > 0) {
            _fadeMenuUpper();
        }
        if (_scrollPosition < _lineCount) {
            _fadeMenuLower();
        }
        if (_helpPageLoadCounter < 8) {
            ++_helpPageLoadCounter;
        } else {
            _drawContent();
        }
        _copyNextPageText();
        break;
    case exitToMenu:
        if (_helpText != NULL) {
            vs_main_freeHeapR(_helpText);
        }
        if (_helpAssets != NULL) {
            vs_main_freeHeapR(_helpAssets);
        }
        func_8007E0A8(0x1D, 3, 5);
        return 1;
    case exitToBattle:
        if (_helpText != NULL) {
            vs_main_freeHeapR(_helpText);
        }
        if (_helpAssets != NULL) {
            vs_main_freeHeapR(_helpAssets);
        }
        func_8007E0A8(0x1D, 3, 5);
        return 2;
    }
    return 0;
}

static int _topMenu(int init)
{
    enum state { initRows, selectRow };

    char* strings[28];
    int i;

    if (init != 0) {
        _topMenu_state = initRows;
        _selectedRow = 0;
    }

    switch (_topMenu_state) {
    case initRows:
        for (i = 0; i < 14; ++i) {
            strings[i * 2] = (char*)&_menuText[_menuText[i]];
            strings[i * 2 + 1] = (char*)&_menuText[_menuText[14 + i]];
        }
        _setMenuRows(14, vs_battle_manualDisplayState.currentManual, strings);
        ++_topMenu_state;
        break;
    case selectRow:
        _selectedRow = _getSelectedRow();
        if (_selectedRow != -1) {
            return _selectedRow;
        }
        break;
    }
    return -1;
}

static void _copySprites(u_long const* buffer, int count)
{
    RECT rect;
    int i;

    i = 0;
    rect.w = 4;
    rect.h = 16;

    for (i = 0; i < count; ++i) {
        rect.x = (i % 48) * 4 + 832;
        rect.y = (i / 48) * 16 + 256;
        LoadImage2(&rect, (u_long*)buffer);
        buffer += 4 * 16 / 2;
    }
}

static void _copyCluts(u_long* buffer, int count)
{
    RECT rect;
    int i;

    rect.w = 16;
    rect.h = 1;

    for (i = 0; i < count; ++i) {
        rect.x = (i % 16) * 16 + 768;
        rect.y = i / 16 + 496;
        LoadImage2(&rect, buffer);
        buffer += 8;
    }
}

static int _getRoundedLineCount(void)
{
    int remainder;
    int lineCount;

    lineCount = _helpText[4] & 0xFFFF;
    remainder = (_helpText[4] & 0xFFFF) % 10;
    if (remainder > 0) {
        lineCount += 10 - remainder;
    }
    lineCount -= 10;
    if (lineCount < 0) {
        lineCount = 0;
    }
    return lineCount;
}

static void _copyNextPageText(void)
{
    char buffer[1024];
    int i;
    int nextPage;
    u_short* offsets;
    char* pBuffer;

    buffer[0] = vs_char_chunkSize;
    buffer[1] = vs_char_noChunking;
    buffer[2] = vs_char_fontTable;
    buffer[3] = vs_char_fontTable0;
    buffer[4] = vs_char_newline;

    offsets = (ushort*)(_helpText + 4);
    nextPage = _scrollPosition + 10;
    pBuffer = buffer + 4;

    if ((u_short)_helpText[4] < nextPage) {
        nextPage = (u_short)_helpText[4];
    }

    for (i = _scrollPosition; i < nextPage; ++i) {
        pBuffer = _vsStrcpy(pBuffer, (char*)(offsets + offsets[i + 1]));
    }

    pBuffer[-1] = vs_char_terminator;
    func_800C6BF0(0, &buffer);
}

static char* _vsStrcpy(char* arg0, char* arg1)
{
    char c;

    for (c = *arg1; c != 0xE7; c = *arg1) {
        if (c >= 0xEC) {
            *arg0 = c;
            ++arg1;
            ++arg0;
        }
        *arg0++ = *arg1++;
    }
    *arg0 = 0xE8;
    return arg0 + 1;
}

static void _drawContent(void)
{
    RECT rect;
    DR_AREA* area;
    int i;
    int spriteOffset;
    u_short* spriteData;
    void** q;
    void** p = (void**)getScratchAddr(0);

    area = p[0];
    SetDrawArea(area, &vs_main_drawEnv[(vs_main_frameBuf + 1) & 1].clip);
    AddPrim(p[1], area++);
    p[0] = area;

    _drawContentLines();

    spriteOffset = _helpText[0];
    if (spriteOffset < 0) {
        spriteOffset += 3;
    }
    spriteData = (u_short*)_helpText + 8 + (spriteOffset >> 2) * 2;

    for (i = 0; i < spriteData[0]; ++i) {
        _drawSprite(&spriteData[spriteData[i + 1]]);
    }
    if (vs_main_drawEnv[(vs_main_frameBuf + 1) & 1].clip.x >= 320) {
        rect.x = 333;
    } else {
        rect.x = 13;
    }
    rect.w = 300;
    rect.y = 55;
    rect.h = 130;

    q = (void**)getScratchAddr(0);
    area = q[0];
    SetDrawArea(area, &rect);
    AddPrim(q[1], area++);
    q[0] = area;
}

static inline int _min(int arg0, int arg1)
{
    if (arg0 >= arg1) {
        return arg1;
    }
    return arg0;
}

static inline int _add_int(int arg0, int arg1) { return (arg0 + arg1); }

static void _drawSprite(short* data)
{
    short posX;
    short posY;
    short width;
    short height;
    short tileMode;
    short clutPacked;
    int spriteW;
    int spriteH;
    int tileStride;
    int spriteX;
    int spriteY;
    int j;
    int i;
    SPRT* sprite;
    u_long** scratch;
    short tPage;

    if ((*data == 0) || ((_getAnimationState((AnimationState_t*)data) << 0x10) == 0)) {
        data += 8;
        posX = *data++;
        posY = *data++;
        width = *data++;
        height = *data++;
        ++data;
        tileMode = *data++;
        clutPacked = *data++;

        clutPacked = ((((clutPacked % 16) << 4) + 0x300) >> 4)
                   | (((clutPacked / 16) + 0x1F0) << 6);

        tileStride = 8;
        if (tileMode == 16) {
            tileStride = 16;
        }

        for (i = 0; i < height; i += 16) {
            spriteH = _min(height - i, 16);

            for (j = 0; j < width; ++data, j += tileStride) {
                int spriteU0;
                int spriteV0;

                spriteW = _min(width - j, tileStride);
                spriteX = 0x0D;
                spriteX = posX + (j + spriteX);
                spriteY = _add_int(posY, i + 0x37);
                spriteY -= _scrollPosition * 0xD;

                if ((spriteY < 0x27) || (0xB9 <= spriteY)) {
                    continue;
                }

                sprite = *((void**)0x1F800000);
                setSprt(sprite);
                setShadeTex(sprite, 1);
                sprite->clut = clutPacked;
                setXY0(sprite, spriteX, spriteY);

                spriteU0 = (*data / 16);
                tPage = spriteU0;
                tPage = tPage % 3 + 0x1D;

                if (tileMode == 16) {
                    sprite->u0 = ((*data - (spriteU0 << 4)) << 16) >> 12;
                } else {
                    tPage |= 0x80;
                    sprite->u0 = ((*data - (spriteU0 << 4)) << 16) >> 13;
                }

                spriteV0 = (*data / 48);
                sprite->v0 = (spriteV0 << 4);
                setWH(sprite, spriteW, spriteH);

                scratch = (void*)getScratchAddr(0);
                AddPrim(scratch[1], sprite++);
                scratch[0] = (void*)sprite;
                _insertTPage(0, tPage);
            }
        }
    }
}

static void _setPageBg(int x, int y, int w, int h, int color)
{
    POLY_G4* poly;
    u_long** p;

    poly = *(POLY_G4**)getScratchAddr(0);
    setPolyG4(poly);
    setXY4(poly, x, y, (x + w) - 1, y, x, (y + h) - 1, (x + w) - 1, (y + h) - 1);
    setRGB0(poly, _colorStops0[color].r0, _colorStops0[color].g0, _colorStops0[color].b0);
    setRGB1(poly, _colorStops1[color].r0, _colorStops1[color].g0, _colorStops1[color].b0);
    setRGB2(poly, _colorStops0[color].r0, _colorStops0[color].g0, _colorStops0[color].b0);
    setRGB3(poly, _colorStops1[color].r0, _colorStops1[color].g0, _colorStops1[color].b0);

    p = (u_long**)getScratchAddr(0);
    AddPrim(p[1] + 7, poly++);
    p[0] = (u_long*)poly;
    _insertTPage(7, getTPage(0, 3, 0, 0));
}

static _menuBgChunkWidths_t const _menuBgChunkWidths = { 128, 128, 64 };

static _menuBgTransparencies_t const _menuBgTransparencies[] = { { 128, 115, 121, 88 },
    { 76, 64, 53, 42 }, { 33, 24, 17, 11 }, { 6, 3, 1, 0 } };

static void _fadeMenuUpper(void)
{
    int widths[4];
    int transparency[16];
    _menuBgTransparencies_t const* var_v0;
    _menuBgTransparencies_t* var_v1;
    int i;
    int j;
    POLY_FT4* poly;
    TILE* tile;

    *(_menuBgChunkWidths_t*)widths = _menuBgChunkWidths;

    var_v1 = (_menuBgTransparencies_t*)transparency;
    var_v0 = _menuBgTransparencies;

    do {
        *var_v1++ = *var_v0++;
    } while (var_v0 != (_menuBgTransparencies + 4));

    _drawPaginationArrow(arrowTypeUp);
    poly = *(void**)getScratchAddr(0);

    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 3; ++j) {
            setPolyFT4(poly);
            setXY4(poly, j << 7, i + 52, widths[j] + (j << 7), i + 52, j << 7, i + 53,
                widths[j] + (j << 7), i + 53);
            setUV4(poly, 0, i + 52, widths[j], i + 52, 0, i + 53, widths[j], i + 53);
            setClut(poly, 768, 227);
            poly->tpage = (j + 32) | 128 | (640 >> 6) | (256 >> 4);
            setSemiTrans(poly, 1);
            setRGB0(poly, transparency[i], transparency[i], transparency[i]);
            AddPrim(*(u_long**)getScratchAddr(1) - 7, poly++);
        }
    }

    tile = (TILE*)poly;
    for (i = 0; i < 16; ++i) {
        setTile(&tile[i]);
        setSemiTrans(&tile[i], 1);
        setXY0(&tile[i], 0, i + 52);
        setWH(&tile[i], 320, 1);
        setRGB0(&tile[i], transparency[i], transparency[i], transparency[i]);
        AddPrim(*(u_long**)getScratchAddr(1) - 7, &tile[i]);
    }

    *(void**)getScratchAddr(0) = (void*)poly + 16 * sizeof(TILE);
    _insertTPage(-7, getTPage(0, 2, 0, 0));
}

static void _fadeMenuLower(void)
{
    int widths[4];
    int transparency[16];
    _menuBgTransparencies_t const* var_v0;
    _menuBgTransparencies_t* var_v1;
    int i;
    int j;
    POLY_FT4* poly;
    TILE* tile;

    *(_menuBgChunkWidths_t*)widths = _menuBgChunkWidths;

    var_v1 = (_menuBgTransparencies_t*)transparency;
    var_v0 = _menuBgTransparencies;

    do {
        *var_v1++ = *var_v0++;
    } while (var_v0 != (_menuBgTransparencies + 4));

    _drawPaginationArrow(arrowTypeDown);

    poly = *(void**)getScratchAddr(0);

    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 3; ++j) {
            setPolyFT4(poly);
            setXY4(poly, j << 7, 187 - i, widths[j] + (j << 7), 187 - i, j << 7, 188 - i,
                widths[j] + (j << 7), 188 - i);
            setUV4(poly, 0, -69 - i, widths[j], -69 - i, 0, -68 - i, widths[j], -68 - i);
            setClut(poly, 768, 227);
            poly->tpage = (j + 32) | 128 | (640 >> 6) | (256 >> 4);
            setSemiTrans(poly, 1);
            setRGB0(poly, transparency[i], transparency[i], transparency[i]);
            AddPrim(*(u_long**)getScratchAddr(1) - 7, poly++);
        }
    }

    tile = (TILE*)poly;

    for (i = 0; i < 16; ++i) {
        setTile(&tile[i]);
        setSemiTrans(&tile[i], 1);
        setXY0(&tile[i], 0, 0xBB - i);
        setWH(&tile[i], 320, 1);
        setRGB0(&tile[i], transparency[i], transparency[i], transparency[i]);
        AddPrim(*(u_long**)getScratchAddr(1) - 7, &tile[i]);
    }

    *(void**)getScratchAddr(0) = (void*)poly + 16 * sizeof(TILE);
    _insertTPage(-7, getTPage(0, 2, 0, 0));
}

static void _drawPaginationArrow(enum arrowType_e arrowType)
{
    int y;
    POLY_FT4* poly;
    u_long** p;

    if (arrowType != arrowTypeUp) {
        if (_pageArrowAnimState < 9) {
            y = (_pageArrowAnimState >> 1) + 184;
        } else {
            y = -(_pageArrowAnimState >> 2) + 190;
        }
    } else {
        if (_pageArrowAnimState < 9) {
            int v0 = 40;
            y = v0 - (_pageArrowAnimState >> 1);
        } else {
            y = (_pageArrowAnimState >> 2) + 34;
        }
    }

    poly = (POLY_FT4*)*getScratchAddr(0);
    setPolyFT4(poly);
    setShadeTex(poly, 1);
    setXY4(poly, 152, y, 168, y, 152, y + 16, 168, y + 16);
    setUV4(poly, arrowType * 16, 48, arrowType * 16 + 16, 48, arrowType * 16, 64,
        arrowType * 16 + 16, 64);
    setTPage(poly, clut4Bit, semiTransparencyHalf, 768, 0);

    if (vs_main_buttonsPreviousState & PADRleft) {
        setClut(poly, 896, 223);
    } else {
        setClut(poly, 912, 223);
    }
    p = (u_long**)getScratchAddr(0);
    AddPrim(p[1] - 7, poly++);
    p[0] = (void*)poly;
}

static void _drawContentLines(void)
{
    short animationState;
    short i;
    short* linesData;
    int linesOffset;
    int spriteOffset;
    LINE_F2* line;
    short linesCount;
    char* c;

    if (_helpText[2] <= 0) {
        return;
    }

    line = *(LINE_F2**)getScratchAddr(0);

    spriteOffset = _helpText[0];
    if (spriteOffset < 0) {
        spriteOffset += 3;
    }
    spriteOffset >>= 2;

    linesOffset = _helpText[1];
    if (linesOffset < 0) {
        linesOffset += 3;
    }

    linesOffset = spriteOffset + (linesOffset >> 2);
    linesData = (short*)&(_helpText)[linesOffset + 4];

    linesCount = *linesData++;

    for (i = 0; i < linesCount; ++i) {
        animationState = 0;
        if (*linesData != 0) {
            animationState = _getAnimationState((AnimationState_t*)linesData);
        }
        linesData += 8;
        setLineF2(line);
        line->x0 = *linesData++ + 13;
        line->y0 = *linesData++ + 55 - _scrollPosition * 13;
        line->x1 = *linesData++ + 13;
        line->y1 = *linesData++ + 55 - _scrollPosition * 13;
        c = (char*)linesData;
        setRGB0(line, c[0], c[1], c[2]);
        linesData += 2;
        if ((line->y0 < 55) && ((line->y1 >= 55) == 0)) {
            continue;
        }
        if (((line->y0 < 186) || (line->y1 < 186)) && ((animationState << 16) == 0)) {
            AddPrim(*(void**)getScratchAddr(1), line++);
        }
    }
    *(void**)getScratchAddr(0) = line;
}

static short _getAnimationState(AnimationState_t* state)
{
    short nextState;

    if (state->currentFrame >= 16) {
        return state->isActive;
    }

    nextState = state->frameMask >> state->currentFrame;
    nextState = nextState & 1;

    if ((++state->timer) >= state->frameDuration) {
        state->timer = 0;
        if ((++state->currentFrame) >= 16) {
            if (state->repeat != 0) {
                state->currentFrame = 0;
            }
        }
    }
    return state->isActive = nextState ^ 1;
}

static void _drawControlsBg(int x, int y, int w, int h)
{
    int i;
    int j;
    LINE_G2* line;
    POLY_F4* poly;
    u_long** p;

    line = (LINE_G2*)*getScratchAddr(0);
    for (i = y, j = w; i < (y + h) - 1; ++i, --j) {
        setLineG2(line);
        setXY2(line, x, i, (x + j) - 1, i);
        setRGB0(line, 64, 56, 32);
        setRGB1(line, 16, 16, 8);
        AddPrim(*(u_long**)getScratchAddr(1) + 7, line++);
    }
    x += 2;
    y += 2;
    poly = (POLY_F4*)line;
    setPolyF4(poly);
    setXY4(poly, x, y, (x + w) - 1, y, x, (y + h) - 1, (x + w) - h, (y + h) - 1);
    setRGB0(poly, 0, 0, 0);

    p = (u_long**)getScratchAddr(0);
    AddPrim(p[1] + 7, poly);
    p[0] = (u_long*)(poly + 1);
}
