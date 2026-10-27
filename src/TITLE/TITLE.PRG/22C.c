#include "22C.h"
#include "titleData.h"
#include "../SLUS_010.40/saveData.h"
#include "../SLUS_010.40/main.h"
#include "../SLUS_010.40/sfx.h"
#include "../BATTLE/BATTLE.PRG/func_8006B57C_t.h"
#include "gpu.h"
#include "build/src/include/lbas.h"
#include "vs_string.h"
#include "build/assets/MENU/MCMAN.BIN.h"
#include <libapi.h>
#include <libds.h>
#include <libetc.h>
#include <libpress.h>
#include <libspu.h>
#include <strings.h>
#include <sys/file.h>

static void _playNewGameSfx(void)
{
    vs_main_playSfxDefault(0x7E, 1);
    vs_main_playSfxDefault(0x7E, 2);
    vs_main_playSfxDefault(0x7E, 3);
}

static void _playMenuChangeSfx(void) { vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE); }

static void _playMenuSelectSfx(void) { vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT); }

static void _playMenuLeaveSfx(void) { vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE); }

static char const* _memcardFilenameTemplate = "bu00:BASLUS-01040VAG0";

static u_int _keystreamBits(int value)
{
    static u_int _keystreamState = 0x19660D;
    u_int seed = _keystreamState;

    _keystreamState = seed * 0x19660D;
    return seed >> (32 - value);
}

#include "src/MENU/memcard.h"

static void _packageGameSaveData(int targetFile)
{
#pragma sjis(start)
    static const u_char _defaultFileTitle[] =
        "ＶＡＧＲＡＮＴ　ＳＴＯＲＹ　ＦＩＬＥ　１　　　００：００：００　";
#pragma sjis(end)

    long i;
    int j;
    int var_a0;
    u_char const* s0 = _defaultFileTitle;
    savedata_t* savedata = (savedata_t*)_spmcimg;
    savedata_t* savedata2 = savedata + 1;
    savedata_t* savedata3 = savedata;
    savedata_unk180_t* s5 = &savedata->unk180;

    vs_main_gametime.all = 0;
    vs_main_settings.menuFlags &= 0xFFDF;
    vs_main_stateFlags.puzzleMode = ~(*(u_int*)&vs_main_settings >> 3) & 1;
    memset(savedata, 0, sizeof *savedata);
    ((char*)&savedata->fileInfo.key)[0] = 0x53;
    ((char*)&savedata->fileInfo.key)[1] = 0x43;
    ((char*)&savedata->fileInfo.key)[2] = 0x11;
    ((char*)&savedata->fileInfo.key)[3] = 3;
    _rMemcpy(&savedata->fileInfo.unk4, s0, sizeof savedata->fileInfo.unk4);
    savedata->fileInfo.unk4.unk20[3] += (targetFile << 8);

    if (vs_main_gametime.t.h == 100) {
        savedata->fileInfo.unk4.unk20[6] = 0x5082;
    } else {
        savedata->fileInfo.unk4.unk20[7] += ((vs_main_gametime.t.h / 10) << 8);
        savedata->fileInfo.unk4.unk20[8] += ((vs_main_gametime.t.h % 10) << 8);
        savedata->fileInfo.unk4.unk20[10] += ((vs_main_gametime.t.m / 10) << 8);
        savedata->fileInfo.unk4.unk20[11] += ((vs_main_gametime.t.m % 10) << 8);
        savedata->fileInfo.unk4.unk20[13] += ((vs_main_gametime.t.s / 10) << 8);
        savedata->fileInfo.unk4.unk20[14] += ((vs_main_gametime.t.s % 10) << 8);
    }
    savedata3->fileInfo.unk4.unk20[15] = 0;
    _rMemcpy(savedata3->fileInfo.unk60, _mcData->unk400[targetFile],
        sizeof savedata->fileInfo.unk60);
    _rMemcpy(savedata3->unk80, _mcData->unk4E0[targetFile], sizeof savedata->unk80);

    if (vs_main_settings.slotState == 0) {
        vs_main_settings.slotState = _keystreamBits(0x20);
        if (vs_main_settings.slotState < 3) {
            vs_main_settings.slotState = 0x17385CA9;
        }
        memset(&savedata2->containerData, 0, sizeof savedata2->containerData);
    }

    vs_main_settings.key = _keystreamBits(0x20);
    s5->unk180.key = vs_main_settings.key;
    s5->unk180.base.slotState = vs_main_settings.slotState;
    vs_main_settings.saveFileGeneration = 0;

    for (i = 0; i < 5; ++i) {
        if (_saveFileInfo[i].unk4.base.slotState >= slotStateInUse) {
            if (vs_main_settings.saveFileGeneration
                < _saveFileInfo[i].unk4.base.generation) {
                vs_main_settings.saveFileGeneration =
                    _saveFileInfo[i].unk4.base.generation;
            }
        }
    }

    s5->unk180.base.generation = ++vs_main_settings.saveFileGeneration;

    if (vs_main_settings.cumulativeSaveCount < 9999) {
        ++vs_main_settings.cumulativeSaveCount;
    }

    vs_main_settings.currentGameSaveCount = 0;
    s5->unk180.base.unk8 = 0x20000107;
    s5->stats.gameTime.t = vs_main_gametime.t;
    s5->stats.currentHP = D_80060068.unk0.currentHP;
    s5->stats.maxHP = D_80060068.unk0.maxHP;
    s5->stats.cumulativeSaveCount = vs_main_settings.cumulativeSaveCount;
    s5->stats.currentGameSaveCount = vs_main_settings.currentGameSaveCount;
    s5->stats.saveLocation = 0x30;
    s5->stats.mapCompletion = 0;
    memset(&vs_main_inventory.misc, 0, sizeof vs_main_inventory.misc);
    memset(&vs_main_inventoryIndices.misc, 0, sizeof vs_main_inventoryIndices.misc);
    memset(&savedata2->containerData.misc, 0,
        sizeof savedata2->containerData.misc / 4); // Why / 4?
    s5->stats.clearCount = vs_main_stateFlags.clearCount;
    s5->stats.currentMP = D_80060068.unk0.currentMP;
    s5->stats.maxMP = D_80060068.unk0.maxMP;
    _rMemcpy(savedata->stateFlags, &vs_main_stateFlags, sizeof savedata->stateFlags);
    _rMemcpy(savedata->actionsLearned, vs_main_actionsLearned,
        sizeof savedata->actionsLearned);
    _rMemcpy(savedata->mapStatus, &vs_main_mapStatus, sizeof savedata->mapStatus);
    _rMemcpy(&savedata->settings, &vs_main_settings, sizeof savedata->settings);
    _rMemcpy(&savedata->unk6C8, &D_80060068, sizeof savedata->unk6C8);
    _rMemcpy(&savedata->inventory, &vs_main_inventory, sizeof savedata->inventory);
    _rMemcpy(&savedata->unk16C8, &vs_main_inventoryIndices, sizeof savedata->unk16C8);
    _rMemcpy(&savedata->unk1778, &D_80061068, sizeof savedata->unk1778);
    _rMemcpy(&savedata->scoreData, &vs_main_scoredata, sizeof savedata->scoreData);
    _rMemcpy(&savedata->containerData, &savedata2->containerData,
        sizeof savedata->containerData);
    savedata->unk1898 = D_80060064;
    _rMemcpy(savedata->unk189C, D_80061078, sizeof savedata->unk189C);
    _rMemcpy(&savedata->artsStatus, &vs_main_artsStatus, sizeof savedata->artsStatus);

    for (i = 0; i < 92; ++i) {
        var_a0 = 0;
        if (i != 1) {
            for (j = 0; j < 256; ++j) {
                var_a0 ^= _spmcimg[i * 0x100 + j];
            }
            s5->checksums[i] = var_a0;
        }
    }
    var_a0 = 0;
    for (j = 0; j < 256; ++j) {
        var_a0 ^= _spmcimg[j + 256];
    }
    s5->checksums[1] = var_a0;
    for (i = (long)&((savedata_t*)0)->unk180.unk180.base.slotState;
        i < (int)sizeof(savedata_t); ++i) {
        _spmcimg[i] += _keystreamBits(8);
    }
}

static char _loadSaveDataErrorOffset;
static char _1 __attribute__((unused));
static u_short _fileProgressTarget;
static u_short _filePreviousProgressCounter;
static u_short _fileProgressPosition;
static int _fileProgressCounter;

#include "src/MENU/memcardLoadSave.h"

#define MEMCARD_INIT_HOOK()
#define MEMCARD_SHUTDOWN_HOOK()
#include "src/MENU/memcardInit.h"

static fileMenuElements_t _fileMenuElements[10];
static char _2[8] __attribute__((unused));
static primBuf_t _primBuf;

#include "src/MENU/drawSprt.h"

#include "src/MENU/drawSaveInfoUI.h"

#include "src/MENU/drawStats.h"

static int _selectCursorXy;
static char* _memoryCardMessage;
static char _isSaving;

#include "src/MENU/fileProcessingAnim.h"

static u_char _selectCursorColor;
static char _fileMenuScreenFade;

#include "src/MENU/fileMenuElement.h"

#define FIND_SAVE_ACCESSING_HOOK(msg)
#define MEMCARD_MASKED_HANDLER_PAD 1
#include "src/MENU/fileMenu.h"

#include "src/MENU/drawFileMenuBg.h"

#include "src/MENU/showLoadFilesMenu.h"

#include "src/MENU/selectLoadMemoryCard.h"

#define FILE_MENU_RESTORE_CURSOR()
#define FILE_MENU_STORE_CURSOR()
#define LOAD_FILE_MENU_PAD 5
#include "src/MENU/loadFileMenu.h"

#define PROMPT_FORMAT_PAD 4
#include "src/MENU/promptConfirm.h"

#define PLAY_INVALID_SFX() vs_main_playSfxDefault(0x7E, VS_SFX_INVALID)
#include "src/MENU/showSaveFilesMenu.h"

#include "src/MENU/selectSaveMemoryCard.h"

#define SAVE_MENU_CLEAR_INFO()
#include "src/MENU/showSaveMenu.h"

static char _frameBuf;
static char _3 __attribute__((unused));

static void _initSaveScreen(void)
{
    DISPENV disp;
    DRAWENV draw;
    RECT rect;

    _frameBuf = 0;
    SetDefDispEnv(&disp, 320, 0, 320, 240);
    SetDefDrawEnv(&draw, 0, 0, 320, 240);
    disp.screen.y = 8;
    disp.screen.h = 224;
    PutDispEnv(&disp);
    PutDrawEnv(&draw);
    setRECT(&rect, 0, 0, 640, 240);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    SetDispMask(1);
}

static void _saveScreenSwapBuf(void)
{
    DISPENV disp;
    DRAWENV draw;
    int offset;

    _frameBuf = (1 - _frameBuf);
    offset = _frameBuf * 320;
    SetDefDispEnv(&disp, 320 - offset, 0, 320, 240);
    SetDefDrawEnv(&draw, offset, 0, 320, 240);
    disp.screen.y = 8;
    disp.screen.h = 224;
    PutDispEnv(&disp);
    PutDrawEnv(&draw);
}

typedef struct {
    char data[220][256 / 2];
    u_short clut[16][16];
} fontTable_t;

typedef struct {
    char page0[224][256 / 2];
    char page1[256][256 / 2];
} uiTable_t;

typedef struct {
    u_short clut[256];
    char data[240][192];
} menuBg_t;

extern fontTable_t _fontTable[];
extern u_long _debugFont[];
extern uiTable_t _uiTable;
extern menuBg_t _saveMenuBg_clut;

static int _gameLoadScreen(void)
{
    enum state {
        init = 0,
        loadMemcardMenu = 1,
        loadFileMenu = 2,
    };

    static RECT rect;
    static char state;

    int exit;

    _drawImage(vs_getXY(768, 0), &_uiTable.page0, vs_getWH(64, 224));
    _drawImage(vs_getXY(448, 256), &_uiTable.page1, vs_getWH(64, 256));
    _drawImage(vs_getXY(832, 0), &_fontTable[0], vs_getWH(64, 224));
    _drawImage(vs_getXY(896, 0), &_fontTable[1], vs_getWH(64, 224));
    _drawImage(vs_getXY(960, 66), _debugFont, vs_getWH(64, 158));
    _drawImage(vs_getXY(768, 227), &_saveMenuBg_clut.clut, vs_getWH(256, 1));
    setRECT(&rect, 640, 256, 32, 240);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    setRECT(&rect, 768, 256, 32, 240);
    ClearImage(&rect, 0, 0, 0);
    _drawImage(vs_getXY(672, 256), &_saveMenuBg_clut.data, vs_getWH(96, 240));
    _initSaveScreen();
    state = init;

    while (1) {
        vs_main_gametimeUpdate(2);
        _saveScreenSwapBuf();
        vs_main_processPadState();
        switch (state) {
        case init:
            if (state == 0) {
                _initMemcard(1);
                state = loadMemcardMenu;
            }
            break;
        case loadMemcardMenu:
            if (_initMemcard(0) != 0) {
                _initFileMenu();
                _loadFileMenu(2);
                state = loadFileMenu;
            }
            break;
        case loadFileMenu:
            exit = _loadFileMenu(0);
            if (exit != 0) {
                _shutdownMemcard();
                SetDispMask(0);
                return exit;
            }
            _drawFileMenuBg();
            _drawFileMenu(_frameBuf);
            break;
        }
    }
}

static int _saveFileExists(void)
{
    struct DIRENTRY dir;
    char filename[22];
    int memCardState;
    int i;
    int ret = 0;

    _initMemcard(1);

    do {
        vs_main_gametimeUpdate(2);
    } while (_initMemcard(0) == 0);

    for (i = 1; i <= 2; ++i) {
        _memcardEventHandler(i);
        do {
            memCardState = _memcardEventHandler(0) & 3;
            VSync(2);
        } while (memCardState == memcardEventPending);

        if (memCardState == memcardEventIoEnd) {
            _rMemcpy(filename, _memcardFilenameTemplate, sizeof filename);

            filename[2] = i + '/';
            filename[20] = '?';

            if (firstfile(filename, &dir) != NULL) {
                ret = 1;
                break;
            }
        }
    }
    _shutdownMemcard();
    return ret;
}

static int _saveScreenConfirmation(int init)
{
    enum state {
        initSlot1 = 0,
        initSlot2 = 1,
        waitForSlotAnimation = 2,
        handleInput = 3,
        returnSelectedOption = 4
    };

    static char state;
    static u_char confirm;
    static char _[5] __attribute__((unused));

    fileMenuElements_t* elem;
    int i;

    if (init != 0) {
        confirm = 1;
        state = initSlot1;
        return 0;
    }

    switch (state) {
    case initSlot1:
    case initSlot2:
        elem = _initFileMenuElement(state + 1, vs_getXY(320, state * 16 + 146),
            vs_getWH(126, 12),
            (char*)&_textTable[_textTable[state + VS_MCMAN_BIN_INDEX_yesOption]]);
        elem->state = fileMenuElementStateAnimateX;
        elem->targetPosition = 194;
        ++state;
        break;
    case waitForSlotAnimation:
        state += _fileMenuElementsActive();
        break;
    case handleInput:
        _fileMenuElements[confirm].selected = 1;
        _fileMenuElements[3 - confirm].selected = 0;
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
        }
        if (vs_main_buttonsPressed.all & PADRright) {
            state = returnSelectedOption;
        }
        if (state == returnSelectedOption) {
            if (confirm == 1) {
                _playMenuSelectSfx();
            } else {
                _playMenuLeaveSfx();
            }
            _selectCursorXy = 0;
            for (i = 1; i < 3; ++i) {
                _fileMenuElements[i].state = fileMenuElementStateAnimateX;
                _fileMenuElements[i].targetPosition = 320;
            }
            break;
        }
        if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
            _playMenuChangeSfx();
            confirm = 3 - confirm;
        }
        _selectCursorXy = vs_getXY(180, (confirm + 7) * 16 + 10);
        break;
    case returnSelectedOption:
        if (_fileMenuElementsActive() != 0) {
            return confirm;
        }
        break;
    }
    return 0;
}

static void _saveScreenExitScreen(void)
{
    _drawSprt(vs_getXY(256, 0), 0, vs_getWH(64, 224),
        getTPage(direct16Bit, semiTransparencySubtract, (1 - _frameBuf) * 320 + 256, 0));
    _drawSprt(0, 0, vs_getWH(256, 224),
        getTPage(direct16Bit, semiTransparencySubtract, (1 - _frameBuf) * 320, 0));
    DrawSync(0);
    _primBuf.tag = vs_getTag(_primBuf.prim.tile, primAddrNull);
    _primBuf.prim.tile.r0g0b0code = vs_getRGB0(primTileSemiTrans, 8, 8, 8);
    _primBuf.prim.tile.x0y0 = 0;
    _primBuf.prim.tile.wh = vs_getWH(320, 224);
    DrawPrim(&_primBuf);
}

static void _gameSaveScreen(void)
{
    enum state { init = 0, loading = 1, loaded = 2, confirmation = 3, exit = 4 };

    static RECT rect;
    static char state;
    static char fadeTimer;
    static char _[6] __attribute__((unused));

    int val;

    _drawImage(vs_getXY(768, 0), &_uiTable.page0, vs_getWH(64, 224));
    _drawImage(vs_getXY(448, 256), &_uiTable.page1, vs_getWH(64, 256));
    _drawImage(vs_getXY(832, 0), &_fontTable[0], vs_getWH(64, 224));
    _drawImage(vs_getXY(896, 0), &_fontTable[1], vs_getWH(64, 224));
    _drawImage(vs_getXY(960, 66), _debugFont, vs_getWH(64, 158));
    _drawImage(vs_getXY(768, 227), &_saveMenuBg_clut.clut, vs_getWH(256, 1));
    setRECT(&rect, 640, 256, 32, 240);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    setRECT(&rect, 768, 256, 32, 240);
    ClearImage(&rect, 0, 0, 0);
    _drawImage(vs_getXY(672, 256), &_saveMenuBg_clut.data, vs_getWH(96, 240));
    _initSaveScreen();

    state = init;

    while (1) {
        vs_main_gametimeUpdate(2);
        _saveScreenSwapBuf();
        vs_main_processPadState();
        _keystreamBits(0);

        switch (state) {
        case init:
            _initMemcard(1);
            state = loading;
            continue;
        case loading:
            if (_initMemcard(0) != 0) {
                _initFileMenu();
                _showSaveMenu(1);
                state = loaded;
            }
            continue;
        case loaded:
            val = _showSaveMenu(0);
            if (val != 0) {
                if (val < 0) {
                    _memoryCardMessage =
                        (char*)(_textTable + VS_MCMAN_BIN_OFFSET_savePrompt);
                    _saveScreenConfirmation(1);
                    state = confirmation;
                } else {
                    _shutdownMemcard();
                    _saveScreenExitScreen();
                    fadeTimer = 30;
                    state = exit;
                    continue;
                }
            }
            _drawFileMenuBg();
            _drawFileMenu(_frameBuf);
            continue;
        case confirmation:
            val = _saveScreenConfirmation(0);
            if (val != 0) {
                if (val != 1) {
                    _shutdownMemcard();
                    _saveScreenExitScreen();
                    fadeTimer = 30;
                    state = exit;
                    continue;
                }
                _showSaveMenu(1);
                state = loaded;
            }
            _drawFileMenuBg();
            _drawFileMenu(_frameBuf);
            continue;
        case exit:
            _saveScreenExitScreen();
            if (--fadeTimer == 0) {
                SetDispMask(0);
                return;
            }
            break;
        }
    }
}

typedef struct {
    u_long* encodedData[2];
    int encodedDataIndex;
    void* decodedData[2];
    int decodedDataIndex;
    RECT frameBufs[2];
    u_int frameBufIndex;
    RECT renderTarget;
    int frameComplete;
} MovieData_t;

static void _playMovie(DslLOC*);
static u_short* _getNextMovieFrame(MovieData_t* arg0);

static u_int _introMovieDisplayedAt;
static int _introMoviePlaying;
static int _dslMode;
static char _4[4] __attribute__((unused));
static DslLOC _introMovieLoc;
static char _5[28] __attribute__((unused));
static MovieData_t _movieData;
static u_long* _movieRingBuf;
static char _6[4] __attribute__((unused));
static DECDCTTAB _vlcTable;
static void* _encodedDataBuf0;
static void* _encodedDataBuf1;
static void* _decodedDataBuf0;
static void* _decodedDataBuf1;

static void _initMovieData(MovieData_t* arg0, short x0, short y0, short x1, int y1)
{
    arg0->frameBufs[0].x = x0;
    arg0->renderTarget.x = x0;
    arg0->frameBufs[0].y = y0;
    arg0->renderTarget.y = y0;
    arg0->encodedDataIndex = 0;
    arg0->decodedDataIndex = 0;
    arg0->frameBufs[1].x = x1;
    arg0->frameBufIndex = 0;
    arg0->renderTarget.w = 24;
    arg0->frameComplete = 0;
    arg0->encodedData[0] = _encodedDataBuf0;
    arg0->encodedData[1] = _encodedDataBuf1;
    arg0->decodedData[0] = _decodedDataBuf0;
    arg0->decodedData[1] = _decodedDataBuf1;
    arg0->frameBufs[1].y = y1;
}

static void _initMoviePlayback(DslLOC* loc, void (*dctoutCb)(void))
{
    DecDCTReset(0);
    DecDCToutCallback(dctoutCb);
    StSetRing(_movieRingBuf, 64);
    StSetStream(1, 1, -1, NULL, NULL);
    _playMovie(loc);
}

static void _decDCToutCallback(void)
{
    RECT rect;
    short rightEdge;
    int index;
    u_int dataSize;

    extern int StCdIntrFlag;
    if (StCdIntrFlag != 0) {
        StCdInterrupt();
        StCdIntrFlag = 0;
    }

    index = _movieData.decodedDataIndex;
    rect = _movieData.renderTarget;
    rightEdge = _movieData.renderTarget.x + _movieData.renderTarget.w;
    _movieData.decodedDataIndex = _movieData.decodedDataIndex == 0;
    _movieData.renderTarget.x = rightEdge;

    if (rightEdge < (_movieData.frameBufs[_movieData.frameBufIndex].x
                     + _movieData.frameBufs[_movieData.frameBufIndex].w)) {
        dataSize = _movieData.renderTarget.w * _movieData.renderTarget.h;
        DecDCTout(_movieData.decodedData[_movieData.decodedDataIndex],
            ((int)(dataSize + (dataSize >> 31))) >> 1);
    } else {
        _movieData.frameComplete = 1;
        _movieData.frameBufIndex = _movieData.frameBufIndex < 1;
        _movieData.renderTarget.x = _movieData.frameBufs[_movieData.frameBufIndex].x;
        _movieData.renderTarget.y = _movieData.frameBufs[_movieData.frameBufIndex].y;
    }
    LoadImage(&rect, _movieData.decodedData[index]);
}

static int _decodeNextMovieFrame(MovieData_t* movie)
{
    u_long* frameData;
    int i;

    i = 2000;

    while ((frameData = (u_long*)_getNextMovieFrame(movie)) == 0) {
        if (--i == 0) {
            return -1;
        }
    }

    movie->encodedDataIndex = movie->encodedDataIndex == 0;
    DecDCTvlc2(frameData, movie->encodedData[movie->encodedDataIndex], _vlcTable);
    StFreeRing(frameData);
    return 0;
}

static u_short* _getNextMovieFrame(MovieData_t* movie)
{
    RECT rect;
    void* addr;
    StHEADER* header;
    int i;
    u_int temp_v1;

    for (i = 2000; StGetNext((u_long**)&addr, (u_long**)&header) != 0;) {
        if (--i == 0) {
            return 0;
        }
    }

    if ((_movieWidth != header->width) || (_movieHeight != header->height)) {
        setRECT(&rect, 0, 0, 480, 448);
        ClearImage(&rect, 0, 0, 0);
        _movieWidth = header->width;
        _movieHeight = header->height;
    }
    temp_v1 = _movieWidth * 3;
    movie->frameBufs[1].w = (int)(temp_v1 + (temp_v1 >> 31)) >> 1;
    movie->frameBufs[0].w = (int)(temp_v1 + (temp_v1 >> 31)) >> 1;
    movie->frameBufs[1].h = _movieHeight;
    movie->frameBufs[0].h = _movieHeight;
    movie->renderTarget.h = _movieHeight;
    return addr;
}

static void _waitForFrame(MovieData_t* movie, int arg1 __attribute__((unused)))
{
    volatile int sp0[2];
    int* new_var;
    int i = movie->frameComplete;
    sp0[0] = 0x800000;

    while ((*(new_var = &i)) == 0) {
        if ((--sp0[0]) == 0) {
            movie->frameComplete = 1;
            movie->frameBufIndex = movie->frameBufIndex == 0;
            movie->renderTarget.x = movie->frameBufs[movie->frameBufIndex].x;
            movie->renderTarget.y = movie->frameBufs[movie->frameBufIndex].y;
        }
        i = movie->frameComplete;
    }

    movie->frameComplete = 0;
}

static void _playMovie(DslLOC* loc)
{
    u_char params[4];

    params[0] = DslModeSpeed;
    params[1] = 0;
    params[2] = 0;
    params[3] = 0;
    do {
        while (DsControl(DslSetloc, (u_char*)loc, NULL) == 0)
            ;
        while (DsControl(DslSetmode, params, NULL) == 0)
            ;
        VSync(3);
    } while (DsRead2(loc, _dslMode) == 0);
}

static void _displayPublisherAndDeveloper()
{
    extern char publisher_clut[];
    extern char developer[];

    DISPENV disp;
    DRAWENV draw;
    RECT rect;
    int var_a3;
    int var_a3_2;
    int i;

    setRECT(&rect, 0, 0, 320, 512);
    ClearImage(&rect, 0, 0, 0);
    _drawImage(vs_getXY(320, 64), publisher_clut, vs_getWH(16, 1));
    _drawImage(vs_getXY(320, 0), publisher_clut + 32, vs_getWH(256 / 4, 48));
    SetDefDispEnv(&disp, 0, 256, 320, 240);
    SetDefDrawEnv(&draw, 0, 0, 320, 240);
    disp.screen.y = 8;
    disp.screen.h = 224;
    PutDispEnv(&disp);
    PutDrawEnv(&draw);
    DrawSync(0);
    VSync(0);
    SetDispMask(1);

    for (i = 0; i < 364; ++i) {
        var_a3 = 0;
        if (i < 32) {
            var_a3 = (31 - i) * 4;
        }
        if (i > 331) {
            var_a3 = (i - 331) * 4;
        }
        _drawSprt(vs_getXY(32, 88), vs_getUV0Clut(0, 0, 320, 64), vs_getWH(256, 48),
            (var_a3 << 16) | (320 / 64));
        SetDefDispEnv(&disp, 0, (i & 1) * 256, 320, 240);
        SetDefDrawEnv(&draw, 0, (1 - (i & 1)) * 256, 320, 240);
        disp.screen.y = 8;
        disp.screen.h = 224;
        VSync(0);
        PutDispEnv(&disp);
        PutDrawEnv(&draw);
    }

    _drawImage(vs_getXY(0, 240), developer, vs_getWH(128 / 4, 14));

    for (i = 0; i < 364; ++i) {
        var_a3_2 = 0;
        if (i < 32) {
            var_a3_2 = (31 - i) * 4;
        } else if (i > 331) {
            var_a3_2 = (i - 331) * 4;
        } else if ((vs_main_buttonsState & 0xFFFF) != 0) {
            i = 331;
        }
        _drawSprt(vs_getXY(96, 104), vs_getUV0Clut(0, 240, 0, 253), vs_getWH(128, 13),
            var_a3_2 << 16);
        SetDefDispEnv(&disp, 0, (i & 1) * 256, 320, 240);
        SetDefDrawEnv(&draw, 0, (1 - (i & 1)) * 256, 320, 240);
        disp.screen.y = 8;
        disp.screen.h = 224;
        VSync(0);
        vs_main_processPadState();
        PutDispEnv(&disp);
        PutDrawEnv(&draw);
    }
    SetDispMask(0);
}

static void _initIntroMovie(void)
{
    _dslMode = DslModeStream2 | DslModeSpeed | DslModeRT;
    DsIntToPos(VS_TITLE_STR_LBA, &_introMovieLoc);
    _movieRingBuf = vs_main_allocHeap(0x20000);
    _encodedDataBuf0 = vs_main_allocHeap(0x23000);
    _encodedDataBuf1 = vs_main_allocHeap(0x23000);
    _decodedDataBuf0 = vs_main_allocHeap(0x2A00);
    _decodedDataBuf1 = vs_main_allocHeap(0x2A00);
    _initMovieData(&_movieData, 0, 0, 0, 224);
    _initMoviePlayback(&_introMovieLoc, _decDCToutCallback);
    DecDCTvlcBuild(_vlcTable);

    while (_decodeNextMovieFrame(&_movieData) == -1) {
        DslLOC loc = _introMovieLoc;
        _playMovie(&loc);
    }
    _introMoviePlaying = 1;
    _introMovieDisplayedAt = VSync(-1);
}

static void _stopIntroMovie(void)
{
    SpuSetCommonMasterVolume(0, 0);
    _introMoviePlaying = 0;
    DecDCToutCallback(0);
    StUnSetRing();
    while (DsControlB(DslPause, 0, 0) == 0)
        ;
    vs_main_freeHeap(_decodedDataBuf1);
    vs_main_freeHeap(_decodedDataBuf0);
    vs_main_freeHeap(_encodedDataBuf1);
    vs_main_freeHeap(_encodedDataBuf0);
    vs_main_freeHeap(_movieRingBuf);
    SpuSetCommonMasterVolume(0x3FFF, 0x3FFF);
}

static void _stopMovieIfComplete(void)
{
    if ((_introMoviePlaying != 0) && ((VSync(-1) - _introMovieDisplayedAt) >= 4401)) {
        _stopIntroMovie();
    }
}

static int _playIntroMovie(void)
{
    DslLOC loc;
    DISPENV disp;
    int var_s2;
    u_int dataSize;

    var_s2 = 0;

    while (1) {
        DecDCTin(_movieData.encodedData[_movieData.encodedDataIndex], 3);
        dataSize = _movieData.renderTarget.w * _movieData.renderTarget.h;
        DecDCTout(_movieData.decodedData[_movieData.decodedDataIndex],
            (int)(dataSize + (dataSize >> 0x1F)) >> 1);

        while (_decodeNextMovieFrame(&_movieData) == -1) {
            if ((u_int)(StGetBackloc(&loc) - 1) >= 0x44CU) {
                loc = _introMovieLoc;
            }
            _playMovie(&loc);
        }

        _waitForFrame(&_movieData, 0);
        VSync(0);
        vs_main_processPadState();

        if ((VSync(-1) - _introMovieDisplayedAt) >= 0x8F5) {
            return 0;
        }

        SetDefDispEnv(&disp, 0, _movieData.frameBufIndex == 0 ? 224 : 0, 480, 224);
        disp.screen.h = 224;
        disp.screen.y = 8;
        disp.isrgb24 = 1;
        disp.disp.w = (disp.disp.w * 2) / 3;
        PutDispEnv(&disp);

        if (++var_s2 != 1) {
            SetDispMask(1);
        }

        if ((vs_main_buttonsPressed.all & (PADRright | PADstart))) {
            return 1;
        }
    }
    return 0;
}

enum menuItemState_e {
    menuItemStateStatic = 0,
    menuItemStateUpper = 1,
    menuItemStateLower = 2,
    menuItemStateSubmenu = 3
};

typedef struct {
    char enabled;
    char state;
    char textSaturation;
    char outlineSaturation;
    char textPos;
    char targetPos;
    char outlinePos;
    char textBlendFactor;
} menuItemState_t;

static menuItemState_t _menuItemStates[10];

static void _setMenuItemFadeIn(int menuItem, char pos)
{
    _menuItemStates[menuItem].enabled = 1;
    _menuItemStates[menuItem].state = menuItemStateStatic;
    _menuItemStates[menuItem].textSaturation = 0;
    _menuItemStates[menuItem].outlineSaturation = 0;
    _menuItemStates[menuItem].textPos = pos;
    _menuItemStates[menuItem].targetPos = pos;
    _menuItemStates[menuItem].outlinePos = pos;
    _menuItemStates[menuItem].textBlendFactor = 0;
}

static void _copyTitleBgData(void)
{
    RECT rect;
    int j;
    u_int pixelCounts;
    u_int i;
    u_long* data;
    u_long* p;

    i = 0;
    data = vs_main_allocHeap(544 * (512 + 64) * sizeof(u_short));
    p = data;

#ifndef MENUBGSZ
#define MENUBGSZ 222932 * sizeof int
#endif

    for (; i < MENUBGSZ / sizeof(int);) {
        extern u_int _titleScreenBg[];

        pixelCounts = _titleScreenBg[i++];
        for (j = pixelCounts & 0xFFFF; j != 0; --j) {
            *p++ = 0;
        }

        for (j = pixelCounts >> 16; j != 0; --j) {
            *p++ = _titleScreenBg[i++];
        }
    }
    DrawSync(0);
    setRECT(&rect, 480, 0, 544, 512);
    LoadImage(&rect, data);
    DrawSync(0);
    setRECT(&rect, 0, 448, 544, 64);
    LoadImage(&rect, data + 0x22000); // Outlines and menu BG
    DrawSync(0);

    for (i = 0; i < 8; ++i) {
        setRECT(&rect, 480, i + 384, 16, 1);
        LoadImage(&rect, (u_long*)_menuItemTextClut);
        DrawSync(0);
    }
    setRECT(&rect, 480, 394, 16, 1);
    LoadImage(&rect, (u_long*)_menuItemOutlineClut);
    DrawSync(0);
    vs_main_freeHeap(data);
}

static void _initTitleScreen(void)
{
    DISPENV dispenv;
    DRAWENV drawenv;

    SetDefDispEnv(&dispenv, 512, 16, 512, 480);
    dispenv.screen.y = 8;
    dispenv.screen.h = 224;
    dispenv.isinter = 1;
    SetDefDrawEnv(&drawenv, 512, 0, 512, 480);
    while (VSync(1) < 248)
        ;
    PutDispEnv(&dispenv);
    PutDrawEnv(&drawenv);
    VSync(0);
}

static void* _initMenu(int menuItem)
{
    RECT rect;
    u_long* p;
    u_long* offset;
    int i;

    for (i = 9; i >= 0; --i) {
        _menuItemStates[i].enabled = 0;
    }

    _setMenuItemFadeIn(menuItem, 64);
    _setMenuItemFadeIn((menuItem + 1) & 3, 96);
    _setMenuItemFadeIn((menuItem + 3) & 3, 32);
    p = vs_main_allocHeap(0x22380);
    offset = p + 160 * 64;
    setRECT(&rect, 192, 448, 160, 64);
    StoreImage(&rect, offset);
    DrawSync(0);
    offset += 160 * 64 / sizeof(u_short);
    setRECT(&rect, 352, 448, 160, 64);
    StoreImage(&rect, offset);
    DrawSync(0);
    setRECT(&rect, 678, 376, 180, 24);
    StoreImage(&rect, offset + 160 * 64 * 3 / sizeof(u_short));
    DrawSync(0);
    return p;
}

static void _freeHeap(void* arg0) { vs_main_freeHeap(arg0); }

static void _fadeInMenu(u_short* bgData, int textBlendFactor)
{
    RECT rect;
    int g0;
    int b0;
    int bdiff;
    int rdiff;
    int r0;
    int gdiff;
    int i;
    u_short* src;
    u_short* dst;
    int r1, g1, b1;

    i = 0;
    src = bgData + (160 * 64 * 2);
    dst = src + (160 * 64 * 2);

    for (i = 0; i < (160 * 64 * 2); ++i) {
        r0 = bgData[i];
        r1 = src[i];
        g0 = r0 & 0x3E0;
        b0 = r0 & 0x7C00;
        r0 &= 0x1F;
        g1 = r1 & 0x3E0;
        b1 = r1 & 0x7C00;
        r1 &= 0x1F;
        rdiff = (r0 - r1) * textBlendFactor;
        gdiff = (g0 - g1) * textBlendFactor;
        bdiff = (b0 - b1) * textBlendFactor;
        dst[i] = ((u_int)((((r1 << 5) + rdiff) & 0x3E0) | (((g1 << 5) + gdiff) & 0x7C00)
                          | (((b1 << 5) + bdiff) & 0xF8000))
                     >> 5)
               | 0x8000;
    }
    setRECT(&rect, 192, 448, 160, 64);
    LoadImage(&rect, (u_long*)dst);
    DrawSync(0);
    setRECT(&rect, 352, 448, 160, 64);
    LoadImage(&rect, (u_long*)dst + 0x1400);
    DrawSync(0);
    VSync(4);
    vs_main_processPadState();
}

static void _fadeInMenuCopyright(u_short* arg0, int textBlendFactor)
{
    RECT rect;
    int i;
    int g0;
    int b0;
    int bdiff;
    int rdiff;
    int gdiff;
    int r1;
    int r0;
    int g1, b1;
    u_short* src;
    u_short* dst;

    src = arg0 + 0xF000;
    dst = src + (180 * 24);

    for (i = 0; i < (180 * 24); ++i) {
        extern u_short _menuCopyright[];

        r1 = src[i];
        r0 = _menuCopyright[i];
        g0 = r0 & 0x3E0;
        b0 = r0 & 0x7C00;
        g1 = r1 & 0x3E0;
        b1 = r1 & 0x7C00;
        r1 &= 0x1F;
        r0 &= 0x1F;
        rdiff = (r1 - r0) * textBlendFactor;
        gdiff = (g1 - g0) * textBlendFactor;
        bdiff = (b1 - b0) * textBlendFactor;
        dst[i] = ((u_int)((((r0 << 5) + rdiff) & 0x3E0) | (((g0 << 5) + gdiff) & 0x7C00)
                          | (((b0 << 5) + bdiff) & 0xF8000))
                  >> 5);
    }
    VSync(2);
    vs_main_processPadState();
    setRECT(&rect, 678, 376, 180, 24);
    LoadImage(&rect, (u_long*)dst);
    DrawSync(0);
}

static void _setMenuItemClut(int menuItem, int textBlendFactor, int clut0, int clut1)
{
    RECT rect;
    short clut[16];
    int i;
    int r0;
    int g0;
    int b0;
    int r1;
    int g1;
    int b1;
    int rdiff;
    int gdiff;
    int bdiff;

    clut[0] = 0;

    for (i = 1; i < 16; ++i) {
        r0 = _menuItemTextClut[clut0][i];
        r1 = _menuItemTextClut[clut1][i];
        g0 = r0 & 0x3E0;
        b0 = r0 & 0x7C00;
        r0 &= 0x1F;
        g1 = r1 & 0x3E0;
        b1 = r1 & 0x7C00;
        r1 &= 0x1F;
        rdiff = (r1 - r0) * textBlendFactor;
        gdiff = (g1 - g0) * textBlendFactor;
        bdiff = (b1 - b0) * textBlendFactor;
        clut[i] = 0x1F0;
        clut[i] = ((((r0 * 16 + rdiff) & 0x1F0) | ((g0 * 16 + gdiff) & 0x3E00)
                       | ((b0 * 16 + bdiff) & 0x7C000))
                      >> 4)
                | 0x8000;
    }
    setRECT(&rect, 480, menuItem + 384, 16, 1);
    LoadImage(&rect, (u_long*)&clut);
    DrawSync(0);
}

static void _setTitleMenuState(void)
{
    int i;
    int saturation;
    int textBlendFactor;

    i = 0;

    for (i = 0; i < 10; ++i) {
        if (_menuItemStates[i].enabled == 0) {
            continue;
        }
        saturation = _menuItemStates[i].textSaturation + 8;

        if (saturation > 128) {
            saturation = 128;
        }

        _menuItemStates[i].textSaturation = saturation;

        switch (_menuItemStates[i].state) {
        case menuItemStateStatic:
            if (saturation != 128 || _menuItemStates[i].textPos != 64) {
                break;
            }
            _menuItemStates[i].outlinePos = _menuItemStates[i].textPos;
            textBlendFactor = _menuItemStates[i].textBlendFactor;
            if (textBlendFactor < 16) {
                _menuItemStates[i].outlineSaturation = textBlendFactor * 16;
                textBlendFactor += 4;
                if (textBlendFactor > 16) {
                    textBlendFactor = 16;
                }
                _menuItemStates[i].textBlendFactor = textBlendFactor;
            }
            break;
        case menuItemStateUpper:
            _menuItemStates[i].textPos -= 4;
            if (_menuItemStates[i].textPos == _menuItemStates[i].targetPos) {
                _menuItemStates[i].state = menuItemStateStatic;
            }
            break;
        case menuItemStateLower:
            _menuItemStates[i].textPos += 4;
            if (_menuItemStates[i].textPos == _menuItemStates[i].targetPos) {
                _menuItemStates[i].state = menuItemStateStatic;
            }
            break;
        }

        textBlendFactor = _menuItemStates[i].textBlendFactor;

        if (_menuItemStates[i].state < menuItemStateSubmenu) {
            _setMenuItemClut(i, textBlendFactor, 0, 1);
        }
        if ((textBlendFactor != 0) && (_menuItemStates[i].textPos != 64)) {
            _menuItemStates[i].textBlendFactor = textBlendFactor - 1;
        }

        if (_menuItemStates[i].outlineSaturation != 0) {
            if (_menuItemStates[i].outlinePos != _menuItemStates[i].textPos) {
                _menuItemStates[i].outlineSaturation -= 16;

                if (_menuItemStates[i].outlinePos < _menuItemStates[i].textPos) {
                    _menuItemStates[i].outlinePos += 2;
                } else {
                    _menuItemStates[i].outlinePos -= 2;
                }
            } else if ((_menuItemStates[i].textBlendFactor == 16)
                       && (_menuItemStates[i].outlineSaturation > 128)) {
                _menuItemStates[i].outlineSaturation -= 16;
            }
        }
    }
}

typedef struct {
    u_long tag;
    VS_SPRT sprt;
} menuItemPrim_t;

static void _drawTitleMenuItems(void)
{
    static menuItemPrim_t primBuf[341];
    static char _[8] __attribute__((unused));

    int textUv;
    int j;
    menuItemState_t* menuState;
    int x;
    int wh;
    int i;
    menuItemPrim_t* prim;
    int saturation;

    prim = primBuf;

    for (i = 9; i >= 0; --i) {
        if ((_menuItemStates[i].enabled == 0)
            || (_menuItemStates[i].outlineSaturation == 0)) {
            continue;
        }
        prim->tag = vs_getTag(prim->sprt, primAddrEnd);
        prim->sprt.tpage = outlineTpages[i];
        prim->sprt.r0g0b0code = vs_getRGB0Raw(primSprtSemtTrans,
            _menuItemStates[i].outlineSaturation * vs_getRGB888(1, 1, 1));
        if (_menuItemStates[i].state == menuItemStateSubmenu) {
            prim->sprt.x0y0 =
                (outlineXys[i] + (_menuItemStates[i].outlinePos << 16)) + 64;
        } else {
            prim->sprt.x0y0 =
                outlineXys[i] + _menuItemStates[i].outlinePos * vs_getXY(1, 1);
        }
        prim->sprt.u0v0clut = outlineUvs[i];
        prim->sprt.wh = outlineWhs[i];
        DrawPrim(prim);
        ++prim;
    }

    for (i = 9; i >= 0; --i) {
        menuState = _menuItemStates;
        if (menuState[i].enabled == 0) {
            continue;
        }
        saturation = menuState[i].textSaturation;
        x = 192;
        if (menuState[i].state != 3) {
            x = menuState[i].textPos + 128;
        }

        textUv = textUvs[i];
        wh = 128;
        if (x < 176) {
            textUv += 176 - x;
            wh = x - 48;
            x = 176;
        }
        if ((x + wh) > 336) {
            wh = 336 - x;
        }
        wh |= vs_getWH(0, 1);

        for (j = 0; j < 32; ++j) {
            int new_var = j + menuState[i].textPos;
            prim->tag = vs_getTag(prim->sprt, primAddrEnd);
            prim->sprt.tpage = textTpages[i];

            switch ((new_var >> 5) & 3) {
            case 0:
                prim->tag = primAddrEnd;
                break;
            case 1:
                prim->sprt.r0g0b0code = vs_getRGB0Raw(primSprtSemtTrans,
                    ((saturation * (new_var - 32)) >> 5) * vs_getRGB888(1, 1, 1));
                break;
            case 2:
                if (saturation == 128) {
                    prim->sprt.r0g0b0code = vs_getRGB0(primSprt, 128, 128, 128);
                } else {
                    prim->sprt.r0g0b0code = vs_getRGB0Raw(
                        primSprtSemtTrans, saturation * vs_getRGB888(1, 1, 1));
                }
                break;
            case 3:
                prim->sprt.r0g0b0code = vs_getRGB0Raw(primSprtSemtTrans,
                    (((saturation * (127 - new_var)) >> 5) * vs_getRGB888(1, 1, 1)));
                break;
            }

            if (menuState[i].state == 3) {
                if (saturation == 128) {
                    prim->sprt.r0g0b0code = vs_getRGB0(primSprt, 128, 128, 128);
                } else {
                    prim->sprt.r0g0b0code = vs_getRGB0Raw(
                        primSprtSemtTrans, saturation * vs_getRGB888(1, 1, 1));
                }
            }
            prim->sprt.x0y0 = x | ((new_var + 240) << 16);
            prim->sprt.u0v0clut = textUv + (j << 8);
            prim->sprt.wh = wh;
            DrawPrim(prim);
            ++prim;
        }
    }
}

static void _drawTitleMenu(void)
{
    static menuItemPrim_t sprtBuf[10];
    static char _[16] __attribute__((unused));

    int i;
    menuItemPrim_t* sprt;

    _setTitleMenuState();
    for (i = 0; i < 2; ++i) {
        sprt = sprtBuf;
        sprt->sprt.tpage =
            vs_getTpage(192, 256, direct16Bit, semiTransparencyHalf, ditheringOff);
        sprt->tag = vs_getTag(sprt->sprt, primAddrEnd);
        sprt->sprt.r0g0b0code = vs_getRGB0(primSprt, 128, 128, 128);
        sprt->sprt.x0y0 = vs_getXY(176, 256);
        sprt->sprt.u0v0clut = vs_getUV0Clut(0, 192, 0, 0);
        sprt->sprt.wh = vs_getWH(160, 64);
        DrawPrim(sprt);
        ++sprt;
        sprt->sprt.tpage =
            vs_getTpage(320, 256, direct16Bit, semiTransparencyHalf, ditheringOff);
        sprt->tag = vs_getTag(sprt->sprt, primAddrEnd);
        sprt->sprt.r0g0b0code = vs_getRGB0(primSprt, 128, 128, 128);
        sprt->sprt.x0y0 = vs_getXY(176, 320);
        sprt->sprt.u0v0clut = vs_getUV0Clut(32, 192, 0, 0);
        sprt->sprt.wh = vs_getWH(160, 64);
        DrawPrim(sprt);
        _drawTitleMenuItems();
        if (i == 0) {
            DrawSync(0);
            VSync(0);
            vs_main_setVibrateParams();
        } else {
            _stopMovieIfComplete();
        }
    }
}

static void _drawAndSyncTitleMenu(void)
{
    _drawTitleMenu();
    VSync(0);
    vs_main_processPadState();
}

enum menuItems {
    menuItemTimeout = -1,
    menuItemNewGame = 0,
    menuItemContinue = 1,
    menuItemVibration = 2,
    menuItemSound = 3,
    menuItemSoundMono = 4,
    menuItemVibrationOff = 5,
    menuItemVibrationOn = 6,
    menuItemSoundStereo = 7
};

static void _menuVibrationSettings(void)
{
    int i;
    int vibrationSetting;

    _menuItemStates[menuItemContinue].state = menuItemStateUpper;
    _menuItemStates[menuItemSound].state = menuItemStateLower;
    _menuItemStates[menuItemSound].targetPos = 128;
    _menuItemStates[menuItemContinue].targetPos = 0;
    _menuItemStates[menuItemVibration].state = menuItemStateSubmenu;
    vibrationSetting = vs_main_settings.vibrationOn + menuItemVibrationOff;
    _setMenuItemFadeIn(menuItemVibrationOn, 64);
    _setMenuItemFadeIn(menuItemVibrationOff, 96);
    _menuItemStates[menuItemVibrationOff].state = menuItemStateSubmenu;
    _menuItemStates[menuItemVibrationOn].state = menuItemStateSubmenu;
    _setMenuItemClut(menuItemVibrationOff, 0, 0, 0);
    _setMenuItemClut(menuItemVibrationOn, 0, 0, 0);
    for (i = 1; i < 9; ++i) {
        _setMenuItemClut(menuItemVibration, i * 2, 1, 3);
        _menuItemStates[menuItemVibration].textPos -= 4;
        _drawAndSyncTitleMenu();
    }
    _menuItemStates[menuItemNewGame].state = menuItemStateStatic;
    _menuItemStates[menuItemContinue].state = menuItemStateStatic;
    _menuItemStates[menuItemSound].state = menuItemStateStatic;
    for (i = 1; i < 9; ++i) {
        _drawAndSyncTitleMenu();
    }

    for (i = 0; i < 8; ++i) {
        _setMenuItemClut(vibrationSetting, i * 2, 0, 1);
        _menuItemStates[vibrationSetting].outlineSaturation =
            i < 4 ? i * 64 : _menuItemStates[vibrationSetting].outlineSaturation - 16;
        _drawAndSyncTitleMenu();
    }
    while (1) {
        _drawAndSyncTitleMenu();
        if (vs_main_buttonsState & (PADstart | PADRright)) {
            _playMenuSelectSfx();
            vs_main_settings.vibrationOn = vibrationSetting - 5;
            if (vibrationSetting == menuItemVibrationOn) {
                vs_main_vibrationOnEffect(0);
            }
            break;
        } else if (vs_main_buttonsState & PADRdown) {
            _playMenuLeaveSfx();
            break;
        } else {
            if (vs_main_buttonsPressed.all & (PADLup | PADLdown | PADselect)) {
                vibrationSetting = 11 - vibrationSetting;
                _playMenuChangeSfx();

                for (i = 1; i < 8; ++i) {
                    _setMenuItemClut(vibrationSetting, i * 2, 0, 1);
                    _setMenuItemClut(11 - vibrationSetting, i * 2, 1, 0);
                    _menuItemStates[vibrationSetting].outlineSaturation =
                        i < 4 ? i * 64
                              : _menuItemStates[vibrationSetting].outlineSaturation - 16;
                    _menuItemStates[11 - vibrationSetting].outlineSaturation -= 16;
                    if (i == 7) {
                        break;
                    }
                    _drawAndSyncTitleMenu();
                }
            }
        }
    }
    _setMenuItemFadeIn(menuItemContinue, 0);
    _setMenuItemFadeIn(menuItemSound, 128);
    _menuItemStates[menuItemContinue].state = menuItemStateLower;
    _menuItemStates[menuItemContinue].targetPos = 32;
    _menuItemStates[menuItemSound].state = menuItemStateUpper;
    _menuItemStates[menuItemSound].targetPos = 96;
    for (i = 1; i < 9; ++i) {
        _setMenuItemClut(2, i * 2, 3, 1);
        _menuItemStates[2].textPos += 4;
        if (_menuItemStates[menuItemVibrationOff].textSaturation < 24) {
            _menuItemStates[menuItemVibrationOff].textSaturation = 0;
        } else {
            _menuItemStates[menuItemVibrationOff].textSaturation -= 24;
        }
        if (_menuItemStates[menuItemVibrationOn].textSaturation < 24) {
            _menuItemStates[menuItemVibrationOn].textSaturation = 0;
        } else {
            _menuItemStates[menuItemVibrationOn].textSaturation -= 24;
        }
        if (_menuItemStates[menuItemVibrationOff].outlineSaturation != 0) {
            _menuItemStates[menuItemVibrationOff].outlineSaturation -= 16;
        }
        if (_menuItemStates[menuItemVibrationOn].outlineSaturation != 0) {
            _menuItemStates[menuItemVibrationOn].outlineSaturation -= 16;
        }
        _drawAndSyncTitleMenu();
    }
    _menuItemStates[menuItemVibrationOff].enabled = 0;
    _menuItemStates[menuItemVibrationOn].enabled = 0;
    _menuItemStates[menuItemVibration].outlinePos = 64;
    _menuItemStates[menuItemVibration].outlineSaturation = 64;
    _drawAndSyncTitleMenu();
    _menuItemStates[menuItemVibration].outlineSaturation = 128;
    _drawAndSyncTitleMenu();
    _menuItemStates[menuItemVibration].outlineSaturation = 192;
    _drawTitleMenu();
    _menuItemStates[menuItemVibration].textBlendFactor = 16;
    _menuItemStates[menuItemVibration].state = menuItemStateStatic;
}

static void _menuSoundSettings(void)
{
    int i;
    int soundSetting;

    _menuItemStates[menuItemVibration].state = menuItemStateUpper;
    _menuItemStates[menuItemNewGame].state = menuItemStateLower;
    _menuItemStates[menuItemNewGame].targetPos = 128;
    _menuItemStates[menuItemVibration].targetPos = 0;
    _menuItemStates[menuItemSound].state = menuItemStateSubmenu;
    soundSetting = menuItemSoundStereo - (vs_main_settings.monoSound * 3);
    _setMenuItemFadeIn(menuItemSoundStereo, 64);
    _setMenuItemFadeIn(menuItemSoundMono, 96);
    _menuItemStates[menuItemSoundMono].state = menuItemStateSubmenu;
    _menuItemStates[menuItemSoundStereo].state = menuItemStateSubmenu;
    _setMenuItemClut(menuItemSoundMono, 0, 0, 0);
    _setMenuItemClut(menuItemSoundStereo, 0, 0, 0);
    for (i = 1; i < 9; ++i) {
        _setMenuItemClut(menuItemSound, i * 2, 1, 3);
        _menuItemStates[menuItemSound].textPos -= 4;
        _drawAndSyncTitleMenu();
    }
    _menuItemStates[menuItemNewGame].state = menuItemStateStatic;
    _menuItemStates[menuItemContinue].state = menuItemStateStatic;
    _menuItemStates[menuItemVibration].state = menuItemStateStatic;
    for (i = 1; i < 9; ++i) {
        _drawAndSyncTitleMenu();
    }
    for (i = 0; i < 8; ++i) {
        _setMenuItemClut(soundSetting, i * 2, 0, 1);
        _menuItemStates[soundSetting].outlineSaturation =
            i < 4 ? i << 6 : _menuItemStates[soundSetting].outlineSaturation - 16;
        _drawAndSyncTitleMenu();
    }
    while (1) {
        _drawAndSyncTitleMenu();
        if (vs_main_buttonsState & (PADstart | PADRright)) {
            _playMenuSelectSfx();
            soundSetting = (soundSetting + 1) & 1;
            vs_main_settings.monoSound = soundSetting;
            vs_main_setMonoSound(soundSetting);
            vs_sound_setCdVol(0x7F);
            break;
        } else if (vs_main_buttonsState & PADRdown) {
            _playMenuLeaveSfx();
            break;
        } else {
            if (vs_main_buttonsPressed.all & (PADLup | PADLdown | PADselect)) {
                soundSetting = 11 - soundSetting;
                _playMenuChangeSfx();
                for (i = 1; i < 8; ++i) {
                    _setMenuItemClut(soundSetting, i * 2, 0, 1);
                    _setMenuItemClut(11 - soundSetting, i * 2, 1, 0);
                    _menuItemStates[soundSetting].outlineSaturation =
                        i < 4 ? i << 6
                              : _menuItemStates[soundSetting].outlineSaturation - 16;
                    _menuItemStates[11 - soundSetting].outlineSaturation -= 16;
                    if (i == 7) {
                        break;
                    }
                    _drawAndSyncTitleMenu();
                }
            }
        }
    }
    _setMenuItemFadeIn(menuItemVibration, 0);
    _setMenuItemFadeIn(menuItemNewGame, 128);
    _menuItemStates[menuItemVibration].state = menuItemStateLower;
    _menuItemStates[menuItemVibration].targetPos = 32;
    _menuItemStates[menuItemNewGame].state = menuItemStateUpper;
    _menuItemStates[menuItemNewGame].targetPos = 96;
    for (i = 1; i < 9; ++i) {
        _setMenuItemClut(menuItemSound, i * 2, 3, 1);
        _menuItemStates[menuItemSound].textPos += 4;
        if (_menuItemStates[menuItemSoundMono].textSaturation < 24) {
            _menuItemStates[menuItemSoundMono].textSaturation = 0;
        } else {
            _menuItemStates[menuItemSoundMono].textSaturation -= 24;
        }
        if (_menuItemStates[menuItemSoundStereo].textSaturation < 24) {
            _menuItemStates[menuItemSoundStereo].textSaturation = 0;
        } else {
            _menuItemStates[menuItemSoundStereo].textSaturation -= 24;
        }
        if (_menuItemStates[menuItemSoundMono].outlineSaturation != 0) {
            _menuItemStates[menuItemSoundMono].outlineSaturation -= 16;
        }
        if (_menuItemStates[menuItemSoundStereo].outlineSaturation != 0) {
            _menuItemStates[menuItemSoundStereo].outlineSaturation -= 16;
        }
        _drawAndSyncTitleMenu();
    }
    _menuItemStates[menuItemSoundMono].enabled = 0;
    _menuItemStates[menuItemSoundStereo].enabled = 0;
    _menuItemStates[menuItemSound].outlinePos = 64;
    _menuItemStates[menuItemSound].outlineSaturation = 64;
    _drawAndSyncTitleMenu();
    _menuItemStates[menuItemSound].outlineSaturation = 128;
    _drawAndSyncTitleMenu();
    _menuItemStates[menuItemSound].outlineSaturation = 192;
    _drawTitleMenu();
    _menuItemStates[menuItemSound].textBlendFactor = 16;
    _menuItemStates[menuItemSound].state = menuItemStateStatic;
}

static void _initGameData(void);
static void _setTitleExitFlags(int arg0);

static int _nop(void) { return 0; }

static void _initEnvironment(void)
{
    int monoSound;
    int vibrationOn;

    vibrationOn = vs_main_settings.vibrationOn;
    monoSound = vs_main_settings.monoSound;
    memset(&vs_main_settings, 0, sizeof vs_main_settings);
    vs_main_settings.menuFlags = 0x2D8;
    vs_main_settings.information = 1;
    vs_main_settings.simpleMap = 3;
    vs_main_settings.containerEmpty = 1;
    vs_main_settings.abilityTimingDisplay = 1;
    vs_main_settings.cursorMemory = 1;
    if (vs_main_titleScreenCount == 0) {
        _displayPublisherAndDeveloper();
        vibrationOn = 1;
        monoSound = 0;
    }
    vs_main_settings.monoSound = monoSound != 0;
    vs_main_settings.vibrationOn = vibrationOn != 0;
    vs_main_setMonoSound(vs_main_settings.monoSound);
    vs_sound_setCdVol(0x7F);
    memset(&vs_main_inventoryIndices, 0, sizeof vs_main_inventoryIndices);
    vs_main_stateFlags.difficulty = 1;
    vs_main_stateFlags.puzzleMode = 1;
}

int vs_title_exec(void)
{
    static struct {
        u_long tag;
        VS_TILE_TPAGE tile;
        char _[44];
    } fileBuf;
    static int buttonsLastPressed;
    static int introMovieLastPlayed;
    static char _[8] __attribute__((unused));

    RECT rect;
    int i;
    int menuItem;
    int selectedOption;
    void* menuData;

    if (vs_main_saveGameClearData != 0) {
        vs_main_saveGameClearData = 0;
        vs_main_titleScreenCount = 0;
        _gameSaveScreen();
    }
    _initGameData();
    _initEnvironment();
    _introMoviePlaying = 0;
    ++vs_main_titleScreenCount;
    menuItem = _saveFileExists();

    do {
        for (i = 7; i >= 0; --i) {
            _menuItemStates[i].enabled = 0;
        }

        _copyTitleBgData();
        _initIntroMovie();
        _playIntroMovie();
        _initTitleScreen();
        SetDispMask(1);
        menuData = _initMenu(menuItem);
        for (i = 32; i >= 0; i -= 2) {
            _fadeInMenuCopyright(menuData, i);
        }
        VSync(0);
        setRECT(&rect, 688, 256, 160, 128);
        StoreImage(&rect, menuData);
        DrawSync(0);
        VSync(0);
        for (i = 32; i >= 0; i -= 4) {
            _fadeInMenu(menuData, i);
            _drawTitleMenu();
        }
        _freeHeap(menuData);
        for (i = 0; i < 8; ++i) {
            _drawAndSyncTitleMenu();
        }

        vs_main_padDisconnectAll();
        introMovieLastPlayed = VSync(-1);
        buttonsLastPressed = VSync(-1);

        while (1) {
            VSync(0);
            vs_main_processPadState();
            if (_introMoviePlaying != 0) {
                introMovieLastPlayed = VSync(-1);
            }
            if ((vs_main_buttonsState & 0xFFFF) != 0) {
                buttonsLastPressed = VSync(-1);
            }
            if (((VSync(-1) - buttonsLastPressed) > 1000)
                && ((VSync(-1) - introMovieLastPlayed) > 100)) {
                selectedOption = menuItemTimeout;
                break;
            }
            if (vs_main_buttonsState & (PADRright | PADstart)) {
                switch (menuItem) {
                case menuItemNewGame:
                    selectedOption = _nop();
                    break;
                case menuItemContinue:
                    selectedOption = menuItemContinue;
                    break;
                case menuItemVibration:
                    _playMenuSelectSfx();
                    _menuVibrationSettings();
                    break;
                case menuItemSound:
                    _playMenuSelectSfx();
                    _menuSoundSettings();
                    break;
                }

                if ((menuItem < menuItemVibration)
                    && (selectedOption >= menuItemNewGame)) {
                    break;
                }
                buttonsLastPressed = VSync(-1);
            }
            i = 0;
            if (vs_main_buttonsState & (PADLup | PADLleft)) {
                --i;
            }
            if (vs_main_buttonsState & (PADselect | PADLright | PADLdown)) {
                ++i;
            }
            if (i != 0) {
                menuItem = (menuItem + i) & 3;
                _playMenuChangeSfx();
                if (i == 1) {
                    _setMenuItemFadeIn((menuItem + 1) & 3, 0x80);
                    for (i = 0; i < 4; ++i) {
                        _menuItemStates[i].state = menuItemStateUpper;
                        _menuItemStates[i].targetPos = _menuItemStates[i].textPos - 32;
                    }
                } else {
                    _setMenuItemFadeIn((menuItem - 1) & 3, 0);
                    for (i = 0; i < 4; ++i) {
                        _menuItemStates[i].state = menuItemStateLower;
                        _menuItemStates[i].targetPos = _menuItemStates[i].textPos + 32;
                    }
                }
                for (i = 0; i < 10; ++i) {
                    _drawAndSyncTitleMenu();
                }
            }
            _drawTitleMenu();
        }
        if (selectedOption >= menuItemNewGame) {
            if (_introMoviePlaying != 0) {
                _stopIntroMovie();
            }
            if (selectedOption == menuItemContinue) {
                _playMenuSelectSfx();
            } else {
                _playNewGameSfx();
                _setTitleExitFlags(selectedOption);
            }
        }

        if (selectedOption == menuItemTimeout) {
            selectedOption = 4 - (vs_main_titleScreenCount & 1);
            _setTitleExitFlags(selectedOption);
        }
        for (i = 64; i > 0; --i) {
            VSync(0);
            vs_main_processPadState();
            fileBuf.tag = vs_getTag(fileBuf.tile, primAddrEnd);
            fileBuf.tile.tpage =
                vs_getTpage(320, 0, direct16Bit, semiTransparencySubtract, ditheringOff);
            fileBuf.tile.r0g0b0code = vs_getRGB0(primTileSemiTrans, 8, 8, 8);
            fileBuf.tile.x0y0 = vs_getXY(0, 0);
            fileBuf.tile.wh = vs_getWH(640, 480);
            DrawPrim(&fileBuf);
            vs_main_setVibrateParams();
        }
        VSync(0);
        SetDispMask(0);
        if (selectedOption == menuItemContinue) {
            selectedOption = _gameLoadScreen();
            if (selectedOption == menuItemContinue) {
                _setTitleExitFlags(menuItemContinue);
            }
        }
    } while (selectedOption < menuItemNewGame);
    return selectedOption;
}

static void _initScreen(int w, int h, int distance, int r, int g, int b)
{
    RECT rect = (RECT) { 0, 0, 1024, 512 };
    SetDispMask(0);
    SetGeomOffset(w / 2, h / 2);
    SetGeomScreen(distance);
    SetDefDrawEnv(vs_main_drawEnv, 0, 0, w, h - 16);
    SetDefDispEnv(vs_main_dispEnv, w, 0, w, h - 16);
    SetDefDrawEnv(vs_main_drawEnv + 1, w, 0, w, h - 16);
    SetDefDispEnv(vs_main_dispEnv + 1, 0, 0, w, h - 16);
    setRECT(&vs_main_dispEnv[0].screen, 0, 8, 256, 224);
    setRECT(&vs_main_dispEnv[1].screen, 0, 8, 256, 224);
    vs_main_drawEnv[1].dtd = 0;
    vs_main_drawEnv[0].dtd = 0;
    vs_main_drawEnv[1].isbg = 1;
    vs_main_drawEnv[0].isbg = 1;
    setRGB0(&vs_main_drawEnv[0], r, g, b);
    setRGB0(&vs_main_drawEnv[1], r, g, b);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    FntLoad(960, 0);
    SetDumpFnt(FntOpen(40, 16, 512, 256, 0, 512));
    PutDispEnv(&vs_main_dispEnv[vs_main_frameBuf]);
    PutDrawEnv(&vs_main_drawEnv[vs_main_frameBuf]);
}

static int _renderScreen(u_long* ot)
{
    int _[2] __attribute__((unused));
    int vsync;

    vs_main_frameBuf = vs_main_frameBuf == 0;
    DrawSync(0);
    vsync = vs_main_gametimeUpdate(0);
    PutDispEnv(vs_main_frameBuf + vs_main_dispEnv);
    PutDrawEnv(vs_main_frameBuf + vs_main_drawEnv);
    DrawOTag(ot);
    return vsync;
}

static void _initGameData(void)
{
    int i;
    int j;
    char* v0;

    _initScreen(640, 240, 512, 0, 0, 0);
    i = 0x43F;
    v0 = ((char*)&vs_main_stateFlags) + i;
    do {
        *v0-- = 0;
    } while (--i >= 0);

    vs_main_memcpy(vs_main_actionsLearned, actionsLearned, sizeof actionsLearned);
    vs_main_bzero(&vs_main_mapStatus, sizeof vs_main_mapStatus);
    vs_main_bzero(&vs_main_gametime, sizeof vs_main_gametime);
    vs_main_bzero(&vs_main_scoredata, sizeof vs_main_scoredata);
    D_80060064 = 0;
    vs_main_bzero(D_80061078, sizeof D_80061078);
    vs_main_bzero(&vs_main_artsStatus, sizeof vs_main_artsStatus);

    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 3; ++j) {
            vs_main_scoredata.bossTimeTrialScores[i][j].time = -8388608; // int24_min
            vs_main_scoredata.bossTimeTrialScores[i][j].round = 0;
            vs_main_scoredata.bossTimeTrialScores[i][j].difficulty = 0;
        }
    }

    for (i = 0; i < 1; ++i) {
        vs_main_bzero((char*)&D_80060068 + i * sizeof D_80060068, 0x50);
    }

    vs_main_bzero(&D_80061068, sizeof D_80061068);
    vs_main_memcpy(&vs_main_inventory, D_80074C24, sizeof vs_main_inventory);

    vs_gametime_tickspeed = 2;
    D_80061068.unk4_8 = 4;
    D_80061068.unk6_10 = 2;
    D_80061068.unk2.unk0_13 = 0;
    D_80061068.unk4_13 = 2;
}

static void _setTitleExitFlags(int cause)
{
    switch (cause) {
    case 0: // New Game
        vs_main_stateFlags.unkC = 0;
        vs_main_stateFlags.unkD = 0;
        D_80061068.zndId = 1;
        D_80061068.mpdId = 0;
        return;
    case 3: // Timeout cutscene1
        vs_main_stateFlags.unkC = 0;
        vs_main_stateFlags.unkD = 1;
        vs_main_stateFlags.unkE = 1;
        D_80061068.zndId = 20;
        D_80061068.mpdId = 0;
        return;
    case 4: // Timeout cutscene2
        vs_main_stateFlags.unkC = 0;
        vs_main_stateFlags.unkD = 1;
        vs_main_stateFlags.unkE = 1;
        D_80061068.zndId = 2;
        D_80061068.mpdId = 1;
        return;
    case 1: // Continue
        vs_main_stateFlags.unkC = 0;
        vs_main_stateFlags.unkD = 0;
        return;
    default:
        vs_main_stateFlags.unkC = 0;
        vs_main_stateFlags.unkD = 0;
        return;
    }
}
