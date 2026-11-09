#include "common.h"
#include "22C.h"
#include "titleData.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/25AC.h"
#include "src/SLUS_010.40/gameFlags.h"
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/graphics.h"
#include "src/SLUS_010.40/memory.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sfx.h"
#include "src/SLUS_010.40/sound.h"
#include "src/SLUS_010.40/zoneState.h"
#include <libpress.h>
#include <libspu.h>
#include <libds.h>

static void playNewGameSfx(void)
{
    vs_main_playSfxDefault(0x7E, 1);
    vs_main_playSfxDefault(0x7E, 2);
    vs_main_playSfxDefault(0x7E, 3);
}

static void playMenuChangeSfx(void) { vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE); }

static void playMenuSelectSfx(void) { vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT); }

static void playMenuLeaveSfx(void) { vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE); }

static char const* memcardFilenameTemplate = "bu00:BASLUS-01040VAG0";

static u_int keystreamBits(int value)
{
    static u_int keystreamState = 0x19660D;
    u_int seed = keystreamState;

    keystreamState = seed * 0x19660D;
    return seed >> (32 - value);
}

#define PACKAGE_SAVE_PREPARE() \
    vs_main_gametime.all = 0; \
    vs_main_settings.menuFlags &= 0xFFDF; \
    vs_main_stateFlags.puzzleMode = 1 - vs_main_settings.puzzleModeOff
#define KEYSTREAM_BITS(n) keystreamBits(n)
#define PACKAGE_SAVE_CLEAR_CONTAINER() \
    memset(&savedata2->containerData, 0, sizeof savedata2->containerData)
#define PACKAGE_SAVE_UPDATE_SAVE_COUNT() vs_main_settings.currentGameSaveCount = 0
#define PACKAGE_SAVE_SET_LOCATION() \
    s5->stats.saveLocation = 0x30; \
    s5->stats.mapCompletion = 0; \
    memset(&vs_main_inventory.misc, 0, sizeof vs_main_inventory.misc); \
    memset(&vs_main_inventoryIndices.misc, 0, sizeof vs_main_inventoryIndices.misc); \
    memset(&savedata2->containerData.misc, 0, \
        sizeof savedata2->containerData.misc / 4) /* Why / 4? */
#define MEMCARD_MASKED_HANDLER_PAD 1
#include "src/MENU/memcard.h"

#include "src/MENU/showLoadFilesMenu.h"

#include "src/MENU/selectLoadMemoryCard.h"

#define LOAD_FILE_MENU_PAD 5
#include "src/MENU/loadFileMenu.h"

#define PROMPT_FORMAT_PAD 4
#include "src/MENU/promptConfirm.h"

#define PLAY_INVALID_SFX() vs_main_playSfxDefault(0x7E, VS_SFX_INVALID)
#include "src/MENU/showSaveFilesMenu.h"

#include "src/MENU/selectSaveMemoryCard.h"

#include "src/MENU/showSaveMenu.h"

static char frameBuf;
static UNUSED char _3;

static void initSaveScreen(void)
{
    DISPENV disp;
    DRAWENV draw;
    RECT rect;

    frameBuf = 0;
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

static void saveScreenSwapBuf(void)
{
    DISPENV disp;
    DRAWENV draw;
    int offset;

    frameBuf = (1 - frameBuf);
    offset = frameBuf * 320;
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

extern fontTable_t fontTable[];
extern u_long debugFont[];
extern uiTable_t uiTable;
extern menuBg_t saveMenuBg_clut;

static int gameLoadScreen(void)
{
    enum state {
        init = 0,
        loadMemcardMenu = 1,
        loadFileMenuState = 2,
    };

    static RECT rect;
    static char state;

    int exit;

    drawImage(vs_getXY(768, 0), &uiTable.page0, vs_getWH(64, 224));
    drawImage(vs_getXY(448, 256), &uiTable.page1, vs_getWH(64, 256));
    drawImage(vs_getXY(832, 0), &fontTable[0], vs_getWH(64, 224));
    drawImage(vs_getXY(896, 0), &fontTable[1], vs_getWH(64, 224));
    drawImage(vs_getXY(960, 66), debugFont, vs_getWH(64, 158));
    drawImage(vs_getXY(768, 227), &saveMenuBg_clut.clut, vs_getWH(256, 1));
    setRECT(&rect, 640, 256, 32, 240);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    setRECT(&rect, 768, 256, 32, 240);
    ClearImage(&rect, 0, 0, 0);
    drawImage(vs_getXY(672, 256), &saveMenuBg_clut.data, vs_getWH(96, 240));
    initSaveScreen();
    state = init;

    while (1) {
        vs_main_gametimeUpdate(2);
        saveScreenSwapBuf();
        vs_main_processPadState();
        switch (state) {
        case init:
            if (state == 0) {
                initMemcard(1);
                state = loadMemcardMenu;
            }
            break;
        case loadMemcardMenu:
            if (initMemcard(0) != 0) {
                initFileMenu();
                loadFileMenu(2);
                state = loadFileMenuState;
            }
            break;
        case loadFileMenuState:
            exit = loadFileMenu(0);
            if (exit != 0) {
                shutdownMemcard();
                SetDispMask(0);
                return exit;
            }
            drawFileMenuBg();
            drawFileMenu(frameBuf);
            break;
        }
    }
}

static int saveFileExists(void)
{
    struct DIRENTRY dir;
    char filename[22];
    int memCardState;
    int i;
    int ret = 0;

    initMemcard(1);

    do {
        vs_main_gametimeUpdate(2);
    } while (initMemcard(0) == 0);

    for (i = 1; i <= 2; ++i) {
        memcardEventHandler(i);
        do {
            memCardState = memcardEventHandler(0) & 3;
            VSync(2);
        } while (memCardState == memcardEventPending);

        if (memCardState == memcardEventIoEnd) {
            rMemcpy(filename, memcardFilenameTemplate, sizeof filename);

            filename[2] = i + '/';
            filename[20] = '?';

            if (firstfile(filename, &dir) != NULL) {
                ret = 1;
                break;
            }
        }
    }
    shutdownMemcard();
    return ret;
}

static int saveScreenConfirmation(int init)
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
    static UNUSED char _[5];

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
        elem = initFileMenuElement(state + 1, vs_getXY(320, state * 16 + 146),
            vs_getWH(126, 12),
            (char*)&textTable[textTable[state + VS_MCMAN_BIN_INDEX_yesOption]]);
        elem->state = fileMenuElementStateAnimateX;
        elem->targetPosition = 194;
        ++state;
        break;
    case waitForSlotAnimation:
        state += fileMenuElementsActive();
        break;
    case handleInput:
        fileMenuElements[confirm].selected = 1;
        fileMenuElements[3 - confirm].selected = 0;
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
        }
        if (vs_main_buttonsPressed.all & PADRright) {
            state = returnSelectedOption;
        }
        if (state == returnSelectedOption) {
            if (confirm == 1) {
                playMenuSelectSfx();
            } else {
                playMenuLeaveSfx();
            }
            selectCursorXy = 0;
            for (i = 1; i < 3; ++i) {
                fileMenuElements[i].state = fileMenuElementStateAnimateX;
                fileMenuElements[i].targetPosition = 320;
            }
            break;
        }
        if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
            playMenuChangeSfx();
            confirm = 3 - confirm;
        }
        selectCursorXy = vs_getXY(180, (confirm + 7) * 16 + 10);
        break;
    case returnSelectedOption:
        if (fileMenuElementsActive() != 0) {
            return confirm;
        }
        break;
    }
    return 0;
}

static void saveScreenExitScreen(void)
{
    drawSprt(vs_getXY(256, 0), 0, vs_getWH(64, 224),
        getTPage(direct16Bit, semiTransparencySubtract, (1 - frameBuf) * 320 + 256, 0));
    drawSprt(0, 0, vs_getWH(256, 224),
        getTPage(direct16Bit, semiTransparencySubtract, (1 - frameBuf) * 320, 0));
    DrawSync(0);
    primBufStatic.tag = vs_getTag(primBufStatic.prim.tile, primAddrNull);
    primBufStatic.prim.tile.r0g0b0code = vs_getRGB0(primTileSemiTrans, 8, 8, 8);
    primBufStatic.prim.tile.x0y0 = 0;
    primBufStatic.prim.tile.wh = vs_getWH(320, 224);
    DrawPrim(&primBufStatic);
}

static void gameSaveScreen(void)
{
    enum state { init = 0, loading = 1, loaded = 2, confirmation = 3, exit = 4 };

    static RECT rect;
    static char state;
    static char fadeTimer;
    static UNUSED char _[6];

    int val;

    drawImage(vs_getXY(768, 0), &uiTable.page0, vs_getWH(64, 224));
    drawImage(vs_getXY(448, 256), &uiTable.page1, vs_getWH(64, 256));
    drawImage(vs_getXY(832, 0), &fontTable[0], vs_getWH(64, 224));
    drawImage(vs_getXY(896, 0), &fontTable[1], vs_getWH(64, 224));
    drawImage(vs_getXY(960, 66), debugFont, vs_getWH(64, 158));
    drawImage(vs_getXY(768, 227), &saveMenuBg_clut.clut, vs_getWH(256, 1));
    setRECT(&rect, 640, 256, 32, 240);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    setRECT(&rect, 768, 256, 32, 240);
    ClearImage(&rect, 0, 0, 0);
    drawImage(vs_getXY(672, 256), &saveMenuBg_clut.data, vs_getWH(96, 240));
    initSaveScreen();

    state = init;

    while (1) {
        vs_main_gametimeUpdate(2);
        saveScreenSwapBuf();
        vs_main_processPadState();
        keystreamBits(0);

        switch (state) {
        case init:
            initMemcard(1);
            state = loading;
            continue;
        case loading:
            if (initMemcard(0) != 0) {
                initFileMenu();
                showSaveMenu(1);
                state = loaded;
            }
            continue;
        case loaded:
            val = showSaveMenu(0);
            if (val != 0) {
                if (val < 0) {
                    memoryCardMessage =
                        (char*)(textTable + VS_MCMAN_BIN_OFFSET_savePrompt);
                    saveScreenConfirmation(1);
                    state = confirmation;
                } else {
                    shutdownMemcard();
                    saveScreenExitScreen();
                    fadeTimer = 30;
                    state = exit;
                    continue;
                }
            }
            drawFileMenuBg();
            drawFileMenu(frameBuf);
            continue;
        case confirmation:
            val = saveScreenConfirmation(0);
            if (val != 0) {
                if (val != 1) {
                    shutdownMemcard();
                    saveScreenExitScreen();
                    fadeTimer = 30;
                    state = exit;
                    continue;
                }
                showSaveMenu(1);
                state = loaded;
            }
            drawFileMenuBg();
            drawFileMenu(frameBuf);
            continue;
        case exit:
            saveScreenExitScreen();
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

static void playMovie(DslLOC*);
static u_short* getNextMovieFrame(MovieData_t* arg0);

static u_int introMovieDisplayedAt;
static int introMoviePlaying;
static int dslMode;
static UNUSED char _4[4];
static DslLOC introMovieLoc;
static UNUSED char _5[28];
static MovieData_t movieData;
static u_long* movieRingBuf;
static UNUSED char _6[4];
static DECDCTTAB vlcTable;
static void* encodedDataBuf0;
static void* encodedDataBuf1;
static void* decodedDataBuf0;
static void* decodedDataBuf1;

static void initMovieData(MovieData_t* arg0, short x0, short y0, short x1, int y1)
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
    arg0->encodedData[0] = encodedDataBuf0;
    arg0->encodedData[1] = encodedDataBuf1;
    arg0->decodedData[0] = decodedDataBuf0;
    arg0->decodedData[1] = decodedDataBuf1;
    arg0->frameBufs[1].y = y1;
}

static void initMoviePlayback(DslLOC* loc, void (*dctoutCb)(void))
{
    DecDCTReset(0);
    DecDCToutCallback(dctoutCb);
    StSetRing(movieRingBuf, 64);
    StSetStream(1, 1, -1, NULL, NULL);
    playMovie(loc);
}

static void decDCToutCallback(void)
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

    index = movieData.decodedDataIndex;
    rect = movieData.renderTarget;
    rightEdge = movieData.renderTarget.x + movieData.renderTarget.w;
    movieData.decodedDataIndex = movieData.decodedDataIndex == 0;
    movieData.renderTarget.x = rightEdge;

    if (rightEdge < (movieData.frameBufs[movieData.frameBufIndex].x
                     + movieData.frameBufs[movieData.frameBufIndex].w)) {
        dataSize = movieData.renderTarget.w * movieData.renderTarget.h;
        DecDCTout(movieData.decodedData[movieData.decodedDataIndex],
            ((int)(dataSize + (dataSize >> 31))) >> 1);
    } else {
        movieData.frameComplete = 1;
        movieData.frameBufIndex = movieData.frameBufIndex < 1;
        movieData.renderTarget.x = movieData.frameBufs[movieData.frameBufIndex].x;
        movieData.renderTarget.y = movieData.frameBufs[movieData.frameBufIndex].y;
    }
    LoadImage(&rect, movieData.decodedData[index]);
}

static int decodeNextMovieFrame(MovieData_t* movie)
{
    u_long* frameData;
    int i;

    i = 2000;

    while ((frameData = (u_long*)getNextMovieFrame(movie)) == 0) {
        if (--i == 0) {
            return -1;
        }
    }

    movie->encodedDataIndex = movie->encodedDataIndex == 0;
    DecDCTvlc2(frameData, movie->encodedData[movie->encodedDataIndex], vlcTable);
    StFreeRing(frameData);
    return 0;
}

static u_short* getNextMovieFrame(MovieData_t* movie)
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

    if ((movieWidth != header->width) || (movieHeight != header->height)) {
        setRECT(&rect, 0, 0, 480, 448);
        ClearImage(&rect, 0, 0, 0);
        movieWidth = header->width;
        movieHeight = header->height;
    }
    temp_v1 = movieWidth * 3;
    movie->frameBufs[1].w = (int)(temp_v1 + (temp_v1 >> 31)) >> 1;
    movie->frameBufs[0].w = (int)(temp_v1 + (temp_v1 >> 31)) >> 1;
    movie->frameBufs[1].h = movieHeight;
    movie->frameBufs[0].h = movieHeight;
    movie->renderTarget.h = movieHeight;
    return addr;
}

static void waitForFrame(MovieData_t* movie, UNUSED int arg1)
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

static void playMovie(DslLOC* loc)
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
    } while (DsRead2(loc, dslMode) == 0);
}

static void displayPublisherAndDeveloper()
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
    drawImage(vs_getXY(320, 64), publisher_clut, vs_getWH(16, 1));
    drawImage(vs_getXY(320, 0), publisher_clut + 32, vs_getWH(256 / 4, 48));
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
        drawSprt(vs_getXY(32, 88), vs_getUV0Clut(0, 0, 320, 64), vs_getWH(256, 48),
            (var_a3 << 16) | (320 / 64));
        SetDefDispEnv(&disp, 0, (i & 1) * 256, 320, 240);
        SetDefDrawEnv(&draw, 0, (1 - (i & 1)) * 256, 320, 240);
        disp.screen.y = 8;
        disp.screen.h = 224;
        VSync(0);
        PutDispEnv(&disp);
        PutDrawEnv(&draw);
    }

    drawImage(vs_getXY(0, 240), developer, vs_getWH(128 / 4, 14));

    for (i = 0; i < 364; ++i) {
        var_a3_2 = 0;
        if (i < 32) {
            var_a3_2 = (31 - i) * 4;
        } else if (i > 331) {
            var_a3_2 = (i - 331) * 4;
        } else if ((vs_main_buttonsState & 0xFFFF) != 0) {
            i = 331;
        }
        drawSprt(vs_getXY(96, 104), vs_getUV0Clut(0, 240, 0, 253), vs_getWH(128, 13),
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

static void initIntroMovie(void)
{
    dslMode = DslModeStream2 | DslModeSpeed | DslModeRT;
    DsIntToPos(VS_TITLE_STR_LBA, &introMovieLoc);
    movieRingBuf = vs_main_allocHeap(0x20000);
    encodedDataBuf0 = vs_main_allocHeap(0x23000);
    encodedDataBuf1 = vs_main_allocHeap(0x23000);
    decodedDataBuf0 = vs_main_allocHeap(0x2A00);
    decodedDataBuf1 = vs_main_allocHeap(0x2A00);
    initMovieData(&movieData, 0, 0, 0, 224);
    initMoviePlayback(&introMovieLoc, decDCToutCallback);
    DecDCTvlcBuild(vlcTable);

    while (decodeNextMovieFrame(&movieData) == -1) {
        DslLOC loc = introMovieLoc;
        playMovie(&loc);
    }
    introMoviePlaying = 1;
    introMovieDisplayedAt = VSync(-1);
}

static void stopIntroMovie(void)
{
    SpuSetCommonMasterVolume(0, 0);
    introMoviePlaying = 0;
    DecDCToutCallback(0);
    StUnSetRing();
    while (DsControlB(DslPause, 0, 0) == 0)
        ;
    vs_main_freeHeap(decodedDataBuf1);
    vs_main_freeHeap(decodedDataBuf0);
    vs_main_freeHeap(encodedDataBuf1);
    vs_main_freeHeap(encodedDataBuf0);
    vs_main_freeHeap(movieRingBuf);
    SpuSetCommonMasterVolume(0x3FFF, 0x3FFF);
}

static void stopMovieIfComplete(void)
{
    if ((introMoviePlaying != 0) && ((VSync(-1) - introMovieDisplayedAt) >= 4401)) {
        stopIntroMovie();
    }
}

static int playIntroMovie(void)
{
    DslLOC loc;
    DISPENV disp;
    int var_s2;
    u_int dataSize;

    var_s2 = 0;

    while (1) {
        DecDCTin(movieData.encodedData[movieData.encodedDataIndex], 3);
        dataSize = movieData.renderTarget.w * movieData.renderTarget.h;
        DecDCTout(movieData.decodedData[movieData.decodedDataIndex],
            (int)(dataSize + (dataSize >> 0x1F)) >> 1);

        while (decodeNextMovieFrame(&movieData) == -1) {
            if ((u_int)(StGetBackloc(&loc) - 1) >= 0x44CU) {
                loc = introMovieLoc;
            }
            playMovie(&loc);
        }

        waitForFrame(&movieData, 0);
        VSync(0);
        vs_main_processPadState();

        if ((VSync(-1) - introMovieDisplayedAt) >= 0x8F5) {
            return 0;
        }

        SetDefDispEnv(&disp, 0, movieData.frameBufIndex == 0 ? 224 : 0, 480, 224);
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

static menuItemState_t menuItemStates[10];

static void setMenuItemFadeIn(int menuItem, char pos)
{
    menuItemStates[menuItem].enabled = 1;
    menuItemStates[menuItem].state = menuItemStateStatic;
    menuItemStates[menuItem].textSaturation = 0;
    menuItemStates[menuItem].outlineSaturation = 0;
    menuItemStates[menuItem].textPos = pos;
    menuItemStates[menuItem].targetPos = pos;
    menuItemStates[menuItem].outlinePos = pos;
    menuItemStates[menuItem].textBlendFactor = 0;
}

static void copyTitleBgData(void)
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
        extern u_int titleScreenBg[];

        pixelCounts = titleScreenBg[i++];
        for (j = pixelCounts & 0xFFFF; j != 0; --j) {
            *p++ = 0;
        }

        for (j = pixelCounts >> 16; j != 0; --j) {
            *p++ = titleScreenBg[i++];
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
        LoadImage(&rect, (u_long*)menuItemTextClut);
        DrawSync(0);
    }
    setRECT(&rect, 480, 394, 16, 1);
    LoadImage(&rect, (u_long*)menuItemOutlineClut);
    DrawSync(0);
    vs_main_freeHeap(data);
}

static void initTitleScreen(void)
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

static void* initMenu(int menuItem)
{
    RECT rect;
    u_long* p;
    u_long* offset;
    int i;

    for (i = 9; i >= 0; --i) {
        menuItemStates[i].enabled = 0;
    }

    setMenuItemFadeIn(menuItem, 64);
    setMenuItemFadeIn((menuItem + 1) & 3, 96);
    setMenuItemFadeIn((menuItem + 3) & 3, 32);
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

static void freeHeap(void* arg0) { vs_main_freeHeap(arg0); }

static void fadeInMenu(u_short* bgData, int textBlendFactor)
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

static void fadeInMenuCopyright(u_short* arg0, int textBlendFactor)
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
        extern u_short menuCopyright[];

        r1 = src[i];
        r0 = menuCopyright[i];
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

static void setMenuItemClut(int menuItem, int textBlendFactor, int clut0, int clut1)
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
        r0 = menuItemTextClut[clut0][i];
        r1 = menuItemTextClut[clut1][i];
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

static void setTitleMenuState(void)
{
    int i;
    int saturation;
    int textBlendFactor;

    i = 0;

    for (i = 0; i < 10; ++i) {
        if (menuItemStates[i].enabled == 0) {
            continue;
        }
        saturation = menuItemStates[i].textSaturation + 8;

        if (saturation > 128) {
            saturation = 128;
        }

        menuItemStates[i].textSaturation = saturation;

        switch (menuItemStates[i].state) {
        case menuItemStateStatic:
            if (saturation != 128 || menuItemStates[i].textPos != 64) {
                break;
            }
            menuItemStates[i].outlinePos = menuItemStates[i].textPos;
            textBlendFactor = menuItemStates[i].textBlendFactor;
            if (textBlendFactor < 16) {
                menuItemStates[i].outlineSaturation = textBlendFactor * 16;
                textBlendFactor += 4;
                if (textBlendFactor > 16) {
                    textBlendFactor = 16;
                }
                menuItemStates[i].textBlendFactor = textBlendFactor;
            }
            break;
        case menuItemStateUpper:
            menuItemStates[i].textPos -= 4;
            if (menuItemStates[i].textPos == menuItemStates[i].targetPos) {
                menuItemStates[i].state = menuItemStateStatic;
            }
            break;
        case menuItemStateLower:
            menuItemStates[i].textPos += 4;
            if (menuItemStates[i].textPos == menuItemStates[i].targetPos) {
                menuItemStates[i].state = menuItemStateStatic;
            }
            break;
        }

        textBlendFactor = menuItemStates[i].textBlendFactor;

        if (menuItemStates[i].state < menuItemStateSubmenu) {
            setMenuItemClut(i, textBlendFactor, 0, 1);
        }
        if ((textBlendFactor != 0) && (menuItemStates[i].textPos != 64)) {
            menuItemStates[i].textBlendFactor = textBlendFactor - 1;
        }

        if (menuItemStates[i].outlineSaturation != 0) {
            if (menuItemStates[i].outlinePos != menuItemStates[i].textPos) {
                menuItemStates[i].outlineSaturation -= 16;

                if (menuItemStates[i].outlinePos < menuItemStates[i].textPos) {
                    menuItemStates[i].outlinePos += 2;
                } else {
                    menuItemStates[i].outlinePos -= 2;
                }
            } else if ((menuItemStates[i].textBlendFactor == 16)
                       && (menuItemStates[i].outlineSaturation > 128)) {
                menuItemStates[i].outlineSaturation -= 16;
            }
        }
    }
}

typedef struct {
    u_long tag;
    VS_SPRT sprt;
} menuItemPrim_t;

static void drawTitleMenuItems(void)
{
    static menuItemPrim_t primBuf[341];
    static UNUSED char _[8];

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
        if ((menuItemStates[i].enabled == 0)
            || (menuItemStates[i].outlineSaturation == 0)) {
            continue;
        }
        prim->tag = vs_getTag(prim->sprt, primAddrEnd);
        prim->sprt.tpage = outlineTpages[i];
        prim->sprt.r0g0b0code = vs_getRGB0Raw(primSprtSemtTrans,
            menuItemStates[i].outlineSaturation * vs_getRGB888(1, 1, 1));
        if (menuItemStates[i].state == menuItemStateSubmenu) {
            prim->sprt.x0y0 = (outlineXys[i] + (menuItemStates[i].outlinePos << 16)) + 64;
        } else {
            prim->sprt.x0y0 =
                outlineXys[i] + menuItemStates[i].outlinePos * vs_getXY(1, 1);
        }
        prim->sprt.u0v0clut = outlineUvs[i];
        prim->sprt.wh = outlineWhs[i];
        DrawPrim(prim);
        ++prim;
    }

    for (i = 9; i >= 0; --i) {
        menuState = menuItemStates;
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

static void drawTitleMenu(void)
{
    static menuItemPrim_t sprtBuf[10];
    static UNUSED char _[16];

    int i;
    menuItemPrim_t* sprt;

    setTitleMenuState();
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
        drawTitleMenuItems();
        if (i == 0) {
            DrawSync(0);
            VSync(0);
            vs_main_setVibrateParams();
        } else {
            stopMovieIfComplete();
        }
    }
}

static void drawAndSyncTitleMenu(void)
{
    drawTitleMenu();
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

static void menuVibrationSettings(void)
{
    int i;
    int vibrationSetting;

    menuItemStates[menuItemContinue].state = menuItemStateUpper;
    menuItemStates[menuItemSound].state = menuItemStateLower;
    menuItemStates[menuItemSound].targetPos = 128;
    menuItemStates[menuItemContinue].targetPos = 0;
    menuItemStates[menuItemVibration].state = menuItemStateSubmenu;
    vibrationSetting = vs_main_settings.vibrationOn + menuItemVibrationOff;
    setMenuItemFadeIn(menuItemVibrationOn, 64);
    setMenuItemFadeIn(menuItemVibrationOff, 96);
    menuItemStates[menuItemVibrationOff].state = menuItemStateSubmenu;
    menuItemStates[menuItemVibrationOn].state = menuItemStateSubmenu;
    setMenuItemClut(menuItemVibrationOff, 0, 0, 0);
    setMenuItemClut(menuItemVibrationOn, 0, 0, 0);
    for (i = 1; i < 9; ++i) {
        setMenuItemClut(menuItemVibration, i * 2, 1, 3);
        menuItemStates[menuItemVibration].textPos -= 4;
        drawAndSyncTitleMenu();
    }
    menuItemStates[menuItemNewGame].state = menuItemStateStatic;
    menuItemStates[menuItemContinue].state = menuItemStateStatic;
    menuItemStates[menuItemSound].state = menuItemStateStatic;
    for (i = 1; i < 9; ++i) {
        drawAndSyncTitleMenu();
    }

    for (i = 0; i < 8; ++i) {
        setMenuItemClut(vibrationSetting, i * 2, 0, 1);
        menuItemStates[vibrationSetting].outlineSaturation =
            i < 4 ? i * 64 : menuItemStates[vibrationSetting].outlineSaturation - 16;
        drawAndSyncTitleMenu();
    }
    while (1) {
        drawAndSyncTitleMenu();
        if (vs_main_buttonsState & (PADstart | PADRright)) {
            playMenuSelectSfx();
            vs_main_settings.vibrationOn = vibrationSetting - 5;
            if (vibrationSetting == menuItemVibrationOn) {
                vs_main_vibrationOnEffect(0);
            }
            break;
        } else if (vs_main_buttonsState & PADRdown) {
            playMenuLeaveSfx();
            break;
        } else {
            if (vs_main_buttonsPressed.all & (PADLup | PADLdown | PADselect)) {
                vibrationSetting = 11 - vibrationSetting;
                playMenuChangeSfx();

                for (i = 1; i < 8; ++i) {
                    setMenuItemClut(vibrationSetting, i * 2, 0, 1);
                    setMenuItemClut(11 - vibrationSetting, i * 2, 1, 0);
                    menuItemStates[vibrationSetting].outlineSaturation =
                        i < 4 ? i * 64
                              : menuItemStates[vibrationSetting].outlineSaturation - 16;
                    menuItemStates[11 - vibrationSetting].outlineSaturation -= 16;
                    if (i == 7) {
                        break;
                    }
                    drawAndSyncTitleMenu();
                }
            }
        }
    }
    setMenuItemFadeIn(menuItemContinue, 0);
    setMenuItemFadeIn(menuItemSound, 128);
    menuItemStates[menuItemContinue].state = menuItemStateLower;
    menuItemStates[menuItemContinue].targetPos = 32;
    menuItemStates[menuItemSound].state = menuItemStateUpper;
    menuItemStates[menuItemSound].targetPos = 96;
    for (i = 1; i < 9; ++i) {
        setMenuItemClut(2, i * 2, 3, 1);
        menuItemStates[2].textPos += 4;
        if (menuItemStates[menuItemVibrationOff].textSaturation < 24) {
            menuItemStates[menuItemVibrationOff].textSaturation = 0;
        } else {
            menuItemStates[menuItemVibrationOff].textSaturation -= 24;
        }
        if (menuItemStates[menuItemVibrationOn].textSaturation < 24) {
            menuItemStates[menuItemVibrationOn].textSaturation = 0;
        } else {
            menuItemStates[menuItemVibrationOn].textSaturation -= 24;
        }
        if (menuItemStates[menuItemVibrationOff].outlineSaturation != 0) {
            menuItemStates[menuItemVibrationOff].outlineSaturation -= 16;
        }
        if (menuItemStates[menuItemVibrationOn].outlineSaturation != 0) {
            menuItemStates[menuItemVibrationOn].outlineSaturation -= 16;
        }
        drawAndSyncTitleMenu();
    }
    menuItemStates[menuItemVibrationOff].enabled = 0;
    menuItemStates[menuItemVibrationOn].enabled = 0;
    menuItemStates[menuItemVibration].outlinePos = 64;
    menuItemStates[menuItemVibration].outlineSaturation = 64;
    drawAndSyncTitleMenu();
    menuItemStates[menuItemVibration].outlineSaturation = 128;
    drawAndSyncTitleMenu();
    menuItemStates[menuItemVibration].outlineSaturation = 192;
    drawTitleMenu();
    menuItemStates[menuItemVibration].textBlendFactor = 16;
    menuItemStates[menuItemVibration].state = menuItemStateStatic;
}

static void menuSoundSettings(void)
{
    int i;
    int soundSetting;

    menuItemStates[menuItemVibration].state = menuItemStateUpper;
    menuItemStates[menuItemNewGame].state = menuItemStateLower;
    menuItemStates[menuItemNewGame].targetPos = 128;
    menuItemStates[menuItemVibration].targetPos = 0;
    menuItemStates[menuItemSound].state = menuItemStateSubmenu;
    soundSetting = menuItemSoundStereo - (vs_main_settings.monoSound * 3);
    setMenuItemFadeIn(menuItemSoundStereo, 64);
    setMenuItemFadeIn(menuItemSoundMono, 96);
    menuItemStates[menuItemSoundMono].state = menuItemStateSubmenu;
    menuItemStates[menuItemSoundStereo].state = menuItemStateSubmenu;
    setMenuItemClut(menuItemSoundMono, 0, 0, 0);
    setMenuItemClut(menuItemSoundStereo, 0, 0, 0);
    for (i = 1; i < 9; ++i) {
        setMenuItemClut(menuItemSound, i * 2, 1, 3);
        menuItemStates[menuItemSound].textPos -= 4;
        drawAndSyncTitleMenu();
    }
    menuItemStates[menuItemNewGame].state = menuItemStateStatic;
    menuItemStates[menuItemContinue].state = menuItemStateStatic;
    menuItemStates[menuItemVibration].state = menuItemStateStatic;
    for (i = 1; i < 9; ++i) {
        drawAndSyncTitleMenu();
    }
    for (i = 0; i < 8; ++i) {
        setMenuItemClut(soundSetting, i * 2, 0, 1);
        menuItemStates[soundSetting].outlineSaturation =
            i < 4 ? i << 6 : menuItemStates[soundSetting].outlineSaturation - 16;
        drawAndSyncTitleMenu();
    }
    while (1) {
        drawAndSyncTitleMenu();
        if (vs_main_buttonsState & (PADstart | PADRright)) {
            playMenuSelectSfx();
            soundSetting = (soundSetting + 1) & 1;
            vs_main_settings.monoSound = soundSetting;
            vs_main_setMonoSound(soundSetting);
            Sound_SetCdMixVolume(0x7F);
            break;
        } else if (vs_main_buttonsState & PADRdown) {
            playMenuLeaveSfx();
            break;
        } else {
            if (vs_main_buttonsPressed.all & (PADLup | PADLdown | PADselect)) {
                soundSetting = 11 - soundSetting;
                playMenuChangeSfx();
                for (i = 1; i < 8; ++i) {
                    setMenuItemClut(soundSetting, i * 2, 0, 1);
                    setMenuItemClut(11 - soundSetting, i * 2, 1, 0);
                    menuItemStates[soundSetting].outlineSaturation =
                        i < 4 ? i << 6
                              : menuItemStates[soundSetting].outlineSaturation - 16;
                    menuItemStates[11 - soundSetting].outlineSaturation -= 16;
                    if (i == 7) {
                        break;
                    }
                    drawAndSyncTitleMenu();
                }
            }
        }
    }
    setMenuItemFadeIn(menuItemVibration, 0);
    setMenuItemFadeIn(menuItemNewGame, 128);
    menuItemStates[menuItemVibration].state = menuItemStateLower;
    menuItemStates[menuItemVibration].targetPos = 32;
    menuItemStates[menuItemNewGame].state = menuItemStateUpper;
    menuItemStates[menuItemNewGame].targetPos = 96;
    for (i = 1; i < 9; ++i) {
        setMenuItemClut(menuItemSound, i * 2, 3, 1);
        menuItemStates[menuItemSound].textPos += 4;
        if (menuItemStates[menuItemSoundMono].textSaturation < 24) {
            menuItemStates[menuItemSoundMono].textSaturation = 0;
        } else {
            menuItemStates[menuItemSoundMono].textSaturation -= 24;
        }
        if (menuItemStates[menuItemSoundStereo].textSaturation < 24) {
            menuItemStates[menuItemSoundStereo].textSaturation = 0;
        } else {
            menuItemStates[menuItemSoundStereo].textSaturation -= 24;
        }
        if (menuItemStates[menuItemSoundMono].outlineSaturation != 0) {
            menuItemStates[menuItemSoundMono].outlineSaturation -= 16;
        }
        if (menuItemStates[menuItemSoundStereo].outlineSaturation != 0) {
            menuItemStates[menuItemSoundStereo].outlineSaturation -= 16;
        }
        drawAndSyncTitleMenu();
    }
    menuItemStates[menuItemSoundMono].enabled = 0;
    menuItemStates[menuItemSoundStereo].enabled = 0;
    menuItemStates[menuItemSound].outlinePos = 64;
    menuItemStates[menuItemSound].outlineSaturation = 64;
    drawAndSyncTitleMenu();
    menuItemStates[menuItemSound].outlineSaturation = 128;
    drawAndSyncTitleMenu();
    menuItemStates[menuItemSound].outlineSaturation = 192;
    drawTitleMenu();
    menuItemStates[menuItemSound].textBlendFactor = 16;
    menuItemStates[menuItemSound].state = menuItemStateStatic;
}

static void initGameData(void);
static void setTitleExitFlags(int arg0);

static int noop(void) { return 0; }

static void initEnvironment(void)
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
        displayPublisherAndDeveloper();
        vibrationOn = 1;
        monoSound = 0;
    }
    vs_main_settings.monoSound = monoSound != 0;
    vs_main_settings.vibrationOn = vibrationOn != 0;
    vs_main_setMonoSound(vs_main_settings.monoSound);
    Sound_SetCdMixVolume(0x7F);
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
    static UNUSED char _[8];

    RECT rect;
    int i;
    int menuItem;
    int selectedOption;
    void* menuData;

    if (vs_main_saveGameClearData != 0) {
        vs_main_saveGameClearData = 0;
        vs_main_titleScreenCount = 0;
        gameSaveScreen();
    }
    initGameData();
    initEnvironment();
    introMoviePlaying = 0;
    ++vs_main_titleScreenCount;
    menuItem = saveFileExists();

    do {
        for (i = 7; i >= 0; --i) {
            menuItemStates[i].enabled = 0;
        }

        copyTitleBgData();
        initIntroMovie();
        playIntroMovie();
        initTitleScreen();
        SetDispMask(1);
        menuData = initMenu(menuItem);
        for (i = 32; i >= 0; i -= 2) {
            fadeInMenuCopyright(menuData, i);
        }
        VSync(0);
        setRECT(&rect, 688, 256, 160, 128);
        StoreImage(&rect, menuData);
        DrawSync(0);
        VSync(0);
        for (i = 32; i >= 0; i -= 4) {
            fadeInMenu(menuData, i);
            drawTitleMenu();
        }
        freeHeap(menuData);
        for (i = 0; i < 8; ++i) {
            drawAndSyncTitleMenu();
        }

        vs_main_padDisconnectAll();
        introMovieLastPlayed = VSync(-1);
        buttonsLastPressed = VSync(-1);

        while (1) {
            VSync(0);
            vs_main_processPadState();
            if (introMoviePlaying != 0) {
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
                    selectedOption = noop();
                    break;
                case menuItemContinue:
                    selectedOption = menuItemContinue;
                    break;
                case menuItemVibration:
                    playMenuSelectSfx();
                    menuVibrationSettings();
                    break;
                case menuItemSound:
                    playMenuSelectSfx();
                    menuSoundSettings();
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
                playMenuChangeSfx();
                if (i == 1) {
                    setMenuItemFadeIn((menuItem + 1) & 3, 0x80);
                    for (i = 0; i < 4; ++i) {
                        menuItemStates[i].state = menuItemStateUpper;
                        menuItemStates[i].targetPos = menuItemStates[i].textPos - 32;
                    }
                } else {
                    setMenuItemFadeIn((menuItem - 1) & 3, 0);
                    for (i = 0; i < 4; ++i) {
                        menuItemStates[i].state = menuItemStateLower;
                        menuItemStates[i].targetPos = menuItemStates[i].textPos + 32;
                    }
                }
                for (i = 0; i < 10; ++i) {
                    drawAndSyncTitleMenu();
                }
            }
            drawTitleMenu();
        }
        if (selectedOption >= menuItemNewGame) {
            if (introMoviePlaying != 0) {
                stopIntroMovie();
            }
            if (selectedOption == menuItemContinue) {
                playMenuSelectSfx();
            } else {
                playNewGameSfx();
                setTitleExitFlags(selectedOption);
            }
        }

        if (selectedOption == menuItemTimeout) {
            selectedOption = 4 - (vs_main_titleScreenCount & 1);
            setTitleExitFlags(selectedOption);
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
            selectedOption = gameLoadScreen();
            if (selectedOption == menuItemContinue) {
                setTitleExitFlags(menuItemContinue);
            }
        }
    } while (selectedOption < menuItemNewGame);
    return selectedOption;
}

static void initScreen(int w, int h, int distance, int r, int g, int b)
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

static int renderScreen(u_long* ot)
{
    UNUSED int _[2];
    int vsync;

    vs_main_frameBuf = vs_main_frameBuf == 0;
    DrawSync(0);
    vsync = vs_main_gametimeUpdate(0);
    PutDispEnv(vs_main_frameBuf + vs_main_dispEnv);
    PutDrawEnv(vs_main_frameBuf + vs_main_drawEnv);
    DrawOTag(ot);
    return vsync;
}

static void initGameData(void)
{
    int i;
    int j;
    char* v0;

    initScreen(640, 240, 512, 0, 0, 0);
    i = 0x43F;
    v0 = ((char*)&vs_main_stateFlags) + i;
    do {
        *v0-- = 0;
    } while (--i >= 0);

    vs_main_memcpy(vs_main_actionsLearned, actionsLearned, sizeof actionsLearned);
    vs_main_bzero(&vs_main_mapStatus, sizeof vs_main_mapStatus);
    vs_main_bzero(&vs_main_gametime, sizeof vs_main_gametime);
    vs_main_bzero(&vs_main_scoredata, sizeof vs_main_scoredata);
    vs_main_zoneEnemyCacheIndex = 0;
    vs_main_bzero(vs_main_zoneEnemyCache, sizeof vs_main_zoneEnemyCache);
    vs_main_bzero(&vs_main_artsStatus, sizeof vs_main_artsStatus);

    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 3; ++j) {
            vs_main_scoredata.bossTimeTrialScores[i][j].time = -8388608; // int24_min
            vs_main_scoredata.bossTimeTrialScores[i][j].round = 0;
            vs_main_scoredata.bossTimeTrialScores[i][j].difficulty = 0;
        }
    }

    for (i = 0; i < 1; ++i) {
        vs_main_bzero(
            (char*)&vs_main_characterSnapshot + i * sizeof vs_main_characterSnapshot,
            0x50);
    }

    vs_main_bzero(&vs_main_spawnPoint, sizeof vs_main_spawnPoint);
    vs_main_memcpy(&vs_main_inventory, D_80074C24, sizeof vs_main_inventory);

    vs_gametime_tickspeed = 2;
    vs_main_spawnPoint.x = 4;
    vs_main_spawnPoint.z = 2;
    vs_main_spawnPoint.targetTile.arrivalSurface = 0;
    vs_main_spawnPoint.facing = 2;
}

static void setTitleExitFlags(int cause)
{
    switch (cause) {
    case 0: // New Game
        vs_main_stateFlags.unkC = 0;
        vs_main_stateFlags.unkD = 0;
        vs_main_spawnPoint.zndId = 1;
        vs_main_spawnPoint.mpdId = 0;
        return;
    case 3: // Timeout cutscene1
        vs_main_stateFlags.unkC = 0;
        vs_main_stateFlags.unkD = 1;
        vs_main_stateFlags.unkE = 1;
        vs_main_spawnPoint.zndId = 20;
        vs_main_spawnPoint.mpdId = 0;
        return;
    case 4: // Timeout cutscene2
        vs_main_stateFlags.unkC = 0;
        vs_main_stateFlags.unkD = 1;
        vs_main_stateFlags.unkE = 1;
        vs_main_spawnPoint.zndId = 2;
        vs_main_spawnPoint.mpdId = 1;
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
