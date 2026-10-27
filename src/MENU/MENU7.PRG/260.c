#include "260.h"
#include "src/SLUS_010.40/saveData.h"
#include "src/SLUS_010.40/sfx.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/BATTLE/BATTLE.PRG/func_8006B57C_t.h"
#include "src/MENU/MAINMENU.PRG/C48.h"
#include "src/MENU/MAINMENU.PRG/2D10.h"
#include "src/MENU/MAINMENU.PRG/58EC.h"
#include "build/assets/MENU/MENU7.PRG/container.h"
#include "build/assets/MENU/MCMAN.BIN.h"
#include "build/src/include/lbas.h"
#include "vs_string.h"
#include "gpu.h"
#include <memory.h>
#include <libapi.h>
#include <sys/file.h>
#include <string.h>
#include <libetc.h>

static char const* _memcardFilenameTemplate = "bu00:BASLUS-01040VAG0";

#include "src/MENU/memcard.h"

/**
 * Builds the save metadata and payload from current game state, then encodes
 * the protected save-data region.
 *
 * @param targetFile Zero-based target slot used in the displayed save metadata.
 */
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

    func_80042CB0();
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
        vs_main_settings.slotState = vs_battle_keystreamBits(0x20);
        if (vs_main_settings.slotState < 3) {
            vs_main_settings.slotState = 0x17385CA9;
        }
        if (!(D_800F4EA0 & 0x400)) {
            memset(&savedata2->containerData, 0, sizeof savedata2->containerData);
        }
    }

    vs_main_settings.key = vs_battle_keystreamBits(0x20);
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

    if (vs_main_settings.currentGameSaveCount < 9999) {
        ++vs_main_settings.currentGameSaveCount;
    }

    s5->unk180.base.unk8 = 0x20000107;
    s5->stats.gameTime.t = vs_main_gametime.t;
    s5->stats.currentHP = D_80060068.unk0.currentHP;
    s5->stats.maxHP = D_80060068.unk0.maxHP;
    s5->stats.cumulativeSaveCount = vs_main_settings.cumulativeSaveCount;
    s5->stats.currentGameSaveCount = vs_main_settings.currentGameSaveCount;
    s5->stats.saveLocation = D_800F4E6B;
    s5->stats.mapCompletion = vs_battle_getMapCompletion();
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
        _spmcimg[i] += vs_battle_keystreamBits(8);
    }
}

#define MEMCARD_INIT_HOOK() func_8007DFF0(0x1D, 3, 6)
#define MEMCARD_SHUTDOWN_HOOK() func_8007E0A8(0x1D, 3, 6)
#include "src/MENU/memcardLoadSave.h"

#include "src/MENU/drawUI.h"

#define FIND_SAVE_ACCESSING_HOOK(msg) vs_mainmenu_setInformationMessage(msg)
#define MEMCARD_MASKED_HANDLER_PAD 5
#include "src/MENU/fileMenu.h"

#define PROMPT_FORMAT_PAD 8
#include "src/MENU/promptConfirm.h"

#define PLAY_INVALID_SFX() vs_battle_playInvalidSfx()
#include "src/MENU/showSaveFilesMenu.h"

#include "src/MENU/selectSaveMemoryCard.h"

#define FILE_MENU_RESTORE_CURSOR() \
    if (vs_main_settings.cursorMemory != 0) { \
        selectedFile = D_800F4EE8.unk85[3] + 1; \
    }
#define FILE_MENU_STORE_CURSOR() D_800F4EE8.unk85[3] = selectedFile - 1
#define SAVE_MENU_CLEAR_INFO() vs_mainmenu_setInformationMessage((char*)&clear)
#include "src/MENU/showSaveMenu.h"

#include "src/MENU/showLoadFilesMenu.h"

#include "src/MENU/selectLoadMemoryCard.h"
#define LOAD_FILE_MENU_PAD 1
#include "src/MENU/loadFileMenu.h"

/**
 * Starts loading one of the built-in intro saves or polls its completion.
 *
 * Actions 1 and 2 select the two bundled saves; action zero polls and applies
 * the loaded data when ready.
 */
static int _loadIntroSaveFile(int action)
{
    static vs_main_CdQueueSlot* _opmcimgSlot;
    static savedata_t* _opMcImg;

    vs_main_CdFile file;
    void* new_var2;
    vs_Gametime_t gametime;
    int lba;
    vs_Gametime_t* new_var;

    switch (action) {
    case 0:
        new_var = &gametime;
        if (_opmcimgSlot->state == vs_main_CdQueueStateLoaded) {
            vs_main_freeCdQueueSlot(_opmcimgSlot);
            gametime.t = vs_main_gametime.t;
            _spmcimg = (char*)(_opMcImg - 1);
            _applyLoadedSaveFile(1);
            vs_main_gametime.t = gametime.t;
            new_var2 = _opMcImg;
            vs_main_freeHeapR(new_var2);
            return 1;
        }
        return 0;
    case 1: // First combat in courtyard
        lba = VS_OPMCIMG1_BIN_LBA;
        break;
    case 2: // D'tok
        lba = VS_OPMCIMG2_BIN_LBA;
        break;
    default:
        return 0;
    }

    file.lba = lba;
    file.size = VS_OPMCIMG1_BIN_SIZE;
    _opmcimgSlot = vs_main_allocateCdQueueSlot(&file);
    new_var2 = vs_main_allocHeapR(sizeof *_opMcImg);
    _opMcImg = new_var2;
    vs_main_cdEnqueue(_opmcimgSlot, _opMcImg);
    return 0;
}

static u_short _menuItemTextClut[][16] = {
    { vs_getRGB5551(0, 0, 0, 0), vs_getRGB5551(1, 1, 1, 1), vs_getRGB5551(1, 1, 3, 1),
        vs_getRGB5551(3, 1, 0, 1), vs_getRGB5551(1, 0, 6, 1), vs_getRGB5551(6, 1, 1, 1),
        vs_getRGB5551(11, 2, 0, 1), vs_getRGB5551(16, 5, 0, 1),
        vs_getRGB5551(19, 8, 0, 1), vs_getRGB5551(23, 10, 0, 1),
        vs_getRGB5551(24, 10, 0, 1), vs_getRGB5551(24, 11, 0, 1),
        vs_getRGB5551(26, 11, 0, 1), vs_getRGB5551(25, 11, 3, 1),
        vs_getRGB5551(27, 14, 0, 1), vs_getRGB5551(27, 13, 2, 1) },
    { vs_getRGB5551(0, 0, 0, 0), vs_getRGB5551(1, 1, 1, 1), vs_getRGB5551(1, 1, 3, 1),
        vs_getRGB5551(3, 1, 0, 1), vs_getRGB5551(1, 0, 6, 1), vs_getRGB5551(6, 1, 1, 1),
        vs_getRGB5551(11, 2, 0, 1), vs_getRGB5551(16, 5, 0, 1),
        vs_getRGB5551(19, 8, 0, 1), vs_getRGB5551(23, 10, 0, 1),
        vs_getRGB5551(24, 10, 0, 1), vs_getRGB5551(24, 11, 0, 1),
        vs_getRGB5551(26, 11, 0, 1), vs_getRGB5551(25, 11, 3, 1),
        vs_getRGB5551(27, 14, 0, 1), vs_getRGB5551(27, 13, 2, 1) },
    { vs_getRGB5551(0, 0, 0, 0), vs_getRGB5551(0, 0, 2, 1), vs_getRGB5551(0, 0, 4, 1),
        vs_getRGB5551(0, 0, 6, 1), vs_getRGB5551(0, 0, 8, 1), vs_getRGB5551(0, 0, 10, 1),
        vs_getRGB5551(0, 0, 12, 1), vs_getRGB5551(0, 0, 14, 1),
        vs_getRGB5551(0, 0, 15, 1), vs_getRGB5551(0, 0, 17, 1),
        vs_getRGB5551(0, 0, 20, 1), vs_getRGB5551(0, 0, 22, 1),
        vs_getRGB5551(0, 0, 24, 1), vs_getRGB5551(0, 0, 23, 1),
        vs_getRGB5551(0, 0, 29, 1), vs_getRGB5551(0, 0, 31, 1) },
    { vs_getRGB5551(0, 0, 0, 0), vs_getRGB5551(1, 1, 3, 1), vs_getRGB5551(2, 2, 7, 1),
        vs_getRGB5551(4, 3, 2, 1), vs_getRGB5551(5, 4, 7, 1), vs_getRGB5551(8, 6, 6, 1),
        vs_getRGB5551(13, 10, 9, 1), vs_getRGB5551(19, 14, 10, 1),
        vs_getRGB5551(23, 18, 12, 1), vs_getRGB5551(27, 21, 14, 1),
        vs_getRGB5551(29, 22, 15, 1), vs_getRGB5551(31, 23, 13, 1),
        vs_getRGB5551(31, 24, 16, 1), vs_getRGB5551(29, 25, 21, 1),
        vs_getRGB5551(31, 26, 18, 1), vs_getRGB5551(31, 27, 22, 1) }
};

/**
 * Loads the game-over screen assets asynchronously.
 *
 * A nonzero arg0 starts loading; zero polls until the assets are uploaded.
 */
static int _initGameOver(int arg0)
{

    static vs_main_CdQueueSlot* queueSlot;
    static u_int* gameOverBin;
    static int state;
    static char _[8] __attribute__((unused));

    vs_main_CdFile cdFile;

    if (arg0 != 0) {
        cdFile.lba = VS_GAMEOVER_BIN_LBA;
        cdFile.size = VS_GAMEOVER_BIN_SIZE;
        queueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        gameOverBin = vs_main_allocHeapR(VS_GAMEOVER_BIN_SIZE);
        vs_main_cdEnqueue(queueSlot, gameOverBin);
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        if (queueSlot->state == 4) {
            vs_main_freeCdQueueSlot(queueSlot);
            vs_battle_renderImage(vs_getXY(832, 256), gameOverBin, vs_getWH(24, 128));
            vs_battle_renderImage(vs_getXY(832, 384), _menuItemTextClut, vs_getWH(48, 1));
            state = 1;
        }
        return 0;
    case 1:
        vs_main_freeHeapR(gameOverBin);
        return 1;
    default:
        return 0;
    }
}

/**
 * Interpolates the 16-entry 5-bit RGB palette between two menu item palettes.
 */
static void _setMenuItemClut(
    short* clut, int textBlendFactor, u_short* clut0, u_short* clut1)
{
    int r0;
    int r1;
    int g0;
    int g1;
    int b0;
    int b1;
    int rdiff;
    int gdiff;
    int bdiff;
    int i;

    clut[0] = 0;

    for (i = 1; i < 16; ++i) {
        r0 = clut0[i];
        r1 = clut1[i];
        g0 = r0 & 0x3E0;
        b0 = r0 & 0x7C00;
        r0 &= 0x1F;
        g1 = r1 & 0x3E0;
        b1 = r1 & 0x7C00;
        r1 &= 0x1F;
        rdiff = (r1 - r0) * textBlendFactor;
        gdiff = (g1 - g0) * textBlendFactor;
        bdiff = (b1 - b0) * textBlendFactor;
        clut[i] = ((((r0 * 16 + rdiff) & 0x1F0) | ((g0 * 16 + gdiff) & 0x3E00)
                       | ((b0 * 16 + bdiff) & 0x7C000))
                      >> 4)
                | 0x8000;
    }
}

/**
 * Animates the game over screen and returns the selected action after fading.
 *
 * A nonzero init resets the animation. The completed selection is one for
 * continue/load and two for return to title.
 */
static int _displayGameOverScreen(int init)
{
    static short clut[2][16];
    static int color1;
    static int color2;
    static int color3;
    static int blendFactor1;
    static int blendFactor2;
    static int selectedOption;
    static char _[8];

    u_long* prim;
    u_long* nextPrim = vs_scratch.unk8;

    if (init != 0) {
        color1 = 0;
        color2 = 0;
        color3 = 0;
        blendFactor1 = 0;
        blendFactor2 = 0;
        selectedOption = 0;
        return 0;
    }
    if (color1 < 0) {
        prim = vs_scratch.unk0;
        prim[0] = (*nextPrim & 0xFFFFFF) | 0x04000000;
        prim[1] = vs_getTpage(0, 0, direct16Bit, semiTransparencySubtract, ditheringOff);
        prim[3] = vs_getXY(0, 0);
        prim[4] = vs_getWH(320, 240);
        prim[2] = vs_getRGB0Raw(primTileSemiTrans, (color1 + 128) * 0x020202);
        *nextPrim = ((u_long)prim << 8) >> 8;
        vs_scratch.unk0 = prim + 5;
        color1 += 8;
        if (color1 == 0) {
            SetDispMask(0);
            return selectedOption + 1;
        }
        return 0;
    }
    if (color1 < 128) {
        color1 += 8;
    } else {
        if (vs_main_buttonsPressed.all & (PADstart | PADRright)) {
            vs_battle_playMenuSelectSfx();
            func_8004552C(1, 0, 60);
            color1 = -128;
            return 0;
        }
        if (vs_main_buttonsPressed.all & (PADselect | PADLup | PADLdown)) {
            vs_battle_playMenuChangeSfx();
            selectedOption = 1 - selectedOption;
        }
        if (selectedOption == 0) {
            if (blendFactor1 < 16) {
                color2 = blendFactor1 * 16;
                blendFactor1 += 4;
                if (blendFactor1 > 16) {
                    blendFactor1 = 16;
                }
            } else {
                if (color2 >= 144) {
                    color2 -= 16;
                } else {
                    color2 = 128;
                }
                if (color3 < 16) {
                    color3 = 0;
                } else {
                    color3 -= 16;
                }
            }
            if (blendFactor2 != 0) {
                --blendFactor2;
            }
        } else {
            if (blendFactor2 < 16) {
                color3 = blendFactor2 * 16;
                blendFactor2 += 4;
                if (blendFactor2 > 16) {
                    blendFactor2 = 16;
                }
            } else {
                if (color3 >= 144) {
                    color3 -= 16;
                } else {
                    color3 = 128;
                }
                if (color2 < 16) {
                    color2 = 0;
                } else {
                    color2 -= 16;
                }
            }
            if (blendFactor1 != 0) {
                --blendFactor1;
            }
        }
    }

    _setMenuItemClut(clut[0], blendFactor1, _menuItemTextClut[0], _menuItemTextClut[3]);
    _setMenuItemClut(clut[1], blendFactor2, _menuItemTextClut[0], _menuItemTextClut[3]);
    vs_battle_renderImage(vs_getXY(832, 384), &clut, vs_getWH(32, 1));

    prim = vs_battle_setSprite(color1, vs_getXY(112, 128), vs_getWH(96, 32), nextPrim);
    prim[1] = vs_getTpage(832, 256, clut4Bit, semiTransparencyHalf, ditheringOff);
    prim[4] = vs_getRGB0(primTile, 0, 0, 52);

    prim = vs_battle_setSprite(color1, vs_getXY(112, 160), vs_getWH(96, 32), nextPrim);
    prim[1] = vs_getTpage(832, 256, clut4Bit, semiTransparencyHalf, ditheringOff);
    prim[4] = vs_getRGB0(primTile, 0, 32, 53);

    prim =
        vs_battle_setSprite(color2 | 256, vs_getXY(112, 128), vs_getWH(96, 32), nextPrim);
    prim[1] = vs_getTpage(832, 256, clut4Bit, semiTransparencyHalf, ditheringOff);
    prim[4] = vs_getRGB0(primTile, 0, 64, 54);

    prim =
        vs_battle_setSprite(color3 | 256, vs_getXY(112, 160), vs_getWH(96, 32), nextPrim);
    prim[1] = vs_getTpage(832, 256, clut4Bit, semiTransparencyHalf, ditheringOff);
    prim[4] = vs_getRGB0(primTile, 0, 96, 54);

    return 0;
}

/**
 * Drives the game over screen, allowing a save load, intro restart, or return
 * to the title screen.
 */
int vs_menu7_gameOver(u_char* state)
{
    enum state {
        init,
        loadAssets,
        displayGameOver,
        initFileMenu,
        displayFileMenu,
        selectFile,
        restartIntro,
        returnToTitle
    };

    static u_short clutBuf[256];
    static vs_main_settings_t settingsBackup;
    static int resetDelay;
    static int _difficulty;

    RECT rect;
    int option;

    switch (*state) {
    case init:
        func_8007E0A8(0x1F, 1, 6);
        func_8008A4DC(0);
        settingsBackup = vs_main_settings;
        _difficulty = vs_main_stateFlags.difficulty;
        _initGameOver(1);
        *state = loadAssets;
        break;
    case loadAssets:
        if (_initGameOver(0) == 0) {
            break;
        }
        *state = displayGameOver;
        _displayGameOverScreen(1);
        // Fallthrough
    case displayGameOver:
        option = _displayGameOverScreen(0);
        if (option == 0) {
            break;
        }
        resetDelay = 16;
        if (option != 2) {
            option = vs_main_stateFlags.introState;
            if (((option - 1) < 2U) && (vs_main_stateFlags.clearCount == 0)) {
                _loadIntroSaveFile(option);
                *state = restartIntro;
            } else {
                *state = initFileMenu;
            }
        } else {
            *state = returnToTitle;
        }
        break;
    case initFileMenu:
        _initMemcard(1);
        _initFileMenu();
        setRECT(&rect, 640, 511, 256, 1);
        StoreImage(&rect, (u_long*)clutBuf);
        DrawSync(0);
        vs_main_loadClut(clutBuf, 3, 0, 256);
        *state = displayFileMenu;
        break;
    case displayFileMenu:
        if (_initMemcard(0) != 0) {
            _loadFileMenu(2);
            *state = selectFile;
            _drawFileMenuBg();
            _drawFileMenu(vs_main_frameBuf);
        }
        break;
    case selectFile:
        SetDispMask(1);
        option = _loadFileMenu(0);
        if (option != 0) {
            _shutdownMemcard();
            SetDispMask(0);
            if (option < 0) {
                resetDelay = 1;
                *state = returnToTitle;
                break;
            }
            vs_main_freeMusic(1);
            vs_main_stateFlags.gameOver = 0;
            vs_main_jumpToBattle();
        } else {
            _drawFileMenuBg();
            _drawFileMenu(vs_main_frameBuf);
        }
        break;
    case restartIntro:
        if (_loadIntroSaveFile(0) != 0) {
            vs_main_settings = settingsBackup;
            vs_main_stateFlags.difficulty = _difficulty;
            vs_main_freeMusic(1);
            vs_main_setMonoSound(vs_main_settings.monoSound);
            vs_main_stateFlags.gameOver = 0;
            vs_main_jumpToBattle();
        }
        break;
    case returnToTitle:
        if (resetDelay != 0) {
            --resetDelay;
        } else {
            vs_main_freeMusic(1);
            vs_main_resetGame();
        }
        break;
    }
    vs_main_stateFlags.gameOver = 1;
    return 0;
}

static u_short _containerStrings[] = {
#include "build/assets/MENU/MENU7.PRG/container.vsString"
};

/**
 * Initializes or advances the container menu's animated Yes/No prompt.
 *
 * initParams selects the initial option in bit 0 and whether the menu button
 * may cancel in bit 2; polling returns 1 for Yes, -1 for No, or zero pending.
 */
static int _promptYesNo(int initParams)
{
    enum state { init, animWait, handleInput, returnSelection };

    static char cursorAnimation = 0;
    static int selectedOption;
    static char state;
    static char cancelWithMenuButton;
    static char _[34] __attribute__((unused));

    vs_battle_menuItem_t* menuItem;
    u_int buttons;

    if (initParams != 0) {
        menuItem = vs_battle_setMenuItem(0x1E, 320, 146, 0x7E, 0,
            (char*)&_containerStrings[VS_container_OFFSET_yesOption]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 194;
        state = init;
        selectedOption = (initParams - 1) & 1;
        cancelWithMenuButton = initParams >> 2;
        return 0;
    }
    switch (state) {
    case init:
        menuItem = vs_battle_setMenuItem(0x1F, 320, 162, 0x7E, 0,
            (char*)&_containerStrings[VS_container_OFFSET_noOption]);
        menuItem->state = 2;
        menuItem->targetPosition0 = 194;
        state = animWait;
        break;
    case animWait:
        state += vs_mainmenu_ready();
        break;
    case handleInput:
        vs_battle_getMenuItem(30 + selectedOption)->selected = 1;
        vs_battle_getMenuItem(31 - selectedOption)->selected = 0;
        buttons = vs_main_buttonsPressed.all;
        if (cancelWithMenuButton == 0) {
            if (buttons & PADRup) {
                buttons -= PADRup;
                vs_battle_playInvalidSfx();
            }
        }
        if (buttons & (PADRup | PADRright | PADRdown)) {
            if ((selectedOption != 0) || (buttons & (PADRup | PADRdown))) {
                vs_battle_playMenuLeaveSfx();
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                selectedOption = -1;
            } else {
                vs_battle_playMenuSelectSfx();
                vs_mainMenu_clearMenuExcept(0);
                selectedOption = 1;
            }
            state = returnSelection;
        } else {
            cursorAnimation = vs_battle_drawCursor(cursorAnimation, selectedOption + 8);
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_battle_playMenuChangeSfx();
                selectedOption = 1 - selectedOption;
            }
        }
        break;
    case returnSelection:
        if (vs_mainmenu_ready() != 0) {
            return selectedOption;
        }
        break;
    }
    return 0;
}

static u_short _containerItemCapacities[] = { 32, 64, 64, 32, 64, 192, 256, 2 };

/**
 * Returns a pointer to the start of a container index section.
 */
static void* _getContainerIndexOffset(int section, vs_menu_containerIndices* indices)
{
    int i = 0;
    int offset = 0;

    if (section > 0) {
        do {
            offset += _containerItemCapacities[i++];
        } while (i < section);
    }
    return (u_short*)indices + offset;
}

/**
 * Copies selected container inventory entries and remaps their cross-item
 * references into the target's compacted indices.
 */
void _copyContainer(vs_menu_containerData* target, vs_menu_containerData* source,
    vs_menu_containerIndices* toCopy)
{
    int i;
    int j;
    vs_menu_containerIndices* targetIndices;
    int sourceIndex;

    targetIndices = vs_main_allocHeapR(sizeof *targetIndices);
    vs_battle_rMemzero(targetIndices, sizeof *targetIndices);
    vs_battle_rMemzero(target, sizeof *target);

    for (i = 0; i < 7; ++i) {
        u_short* sourceOffset = _getContainerIndexOffset(i, toCopy);
        u_short* targetOffset = _getContainerIndexOffset(i, targetIndices);
        for (j = 0; j < _containerItemCapacities[i]; ++j) {
            if (sourceOffset[j] != 0) {
                targetOffset[sourceOffset[j] - 1] = j + 1;
            }
        }
    }

    for (i = 0; i < 32; ++i) {
        sourceIndex = toCopy->weapons[i];
        if (sourceIndex != 0) {
            vs_main_inventoryWeapon* weapon = &target->weapons[i];
            vs_battle_copyAligned(
                weapon, &source->weapons[sourceIndex - 1], sizeof *weapon);
            weapon->index = i + 1;
            weapon->blade = targetIndices->blades[weapon->blade - 1];
            weapon->grip = targetIndices->grips[weapon->grip - 1];

            for (j = 0; j < 4; ++j) {
                if (weapon->gems[j] != 0) {
                    weapon->gems[j] = targetIndices->gems[weapon->gems[j] - 1];
                }
            }
        }
    }

    for (i = 0; i < 64; ++i) {
        sourceIndex = toCopy->blades[i];
        if (sourceIndex != 0) {
            vs_main_inventoryBlade* blade = &target->blades[i];
            vs_battle_copyAligned(blade, &source->blades[sourceIndex - 1], sizeof *blade);
            blade->index = i + 1;
            if (blade->assembledWeaponIndex != 0) {
                blade->assembledWeaponIndex =
                    targetIndices->weapons[blade->assembledWeaponIndex - 1];
            }
        }
    }

    for (i = 0; i < 64; ++i) {
        sourceIndex = toCopy->grips[i];
        if (sourceIndex != 0) {
            vs_main_inventoryGrip* grip = &target->grips[i];
            vs_battle_copyAligned(grip, &source->grips[sourceIndex - 1], sizeof *grip);
            grip->index = i + 1;
            if (grip->assembledWeaponIndex != 0) {
                grip->assembledWeaponIndex =
                    targetIndices->weapons[grip->assembledWeaponIndex - 1];
            }
        }
    }

    for (i = 0; i < 32; ++i) {
        sourceIndex = toCopy->shields[i];
        if (sourceIndex != 0) {
            vs_main_inventoryShield* shield = &target->shields[i];
            vs_battle_copyAligned(
                shield, &source->shields[sourceIndex - 1], sizeof *shield);
            shield->index = i + 1;
            for (j = 0; j < 4; ++j) {
                if (shield->gems[j] != 0) {
                    shield->gems[j] = targetIndices->gems[shield->gems[j] - 1];
                }
            }
        }
    }

    for (i = 0; i < 64; ++i) {
        sourceIndex = toCopy->armor[i];
        if (sourceIndex != 0) {
            vs_main_inventoryArmor* armor = &target->armor[i];
            vs_battle_copyAligned(armor, &source->armor[sourceIndex - 1], sizeof *armor);
            armor->index = i + 1;
        }
    }

    for (i = 0; i < 192; ++i) {
        sourceIndex = toCopy->gems[i];
        if (sourceIndex != 0) {
            vs_main_inventoryGem* gem = &target->gems[i];
            vs_battle_copyAligned(gem, &source->gems[sourceIndex - 1], sizeof *gem);
            gem->index = i + 1;
            if (gem->setItemIndex != 0) {
                if (gem->setItemIndex & 0x80) {
                    gem->setItemIndex =
                        targetIndices->shields[(gem->setItemIndex & 0xFFFF) - 0x81]
                        | 0x80;
                } else {
                    gem->setItemIndex = targetIndices->weapons[gem->setItemIndex - 1];
                }
            }
        }
    }

    for (i = 0; i < 256; ++i) {
        sourceIndex = toCopy->misc[i];
        if (sourceIndex != 0) {
            vs_main_inventoryMisc* item = &target->misc[i];
            vs_battle_rMemcpy(item, &source->misc[sourceIndex - 1], sizeof *item);
            item->index = i + 1;
        }
    }

    vs_main_freeHeapR(targetIndices);
}

/**
 * Runs the container check/save flow and updates the active game container.
 */
int vs_menu7_saveContainerMenu(u_char* state)
{
    enum state {
        init,
    };

    int option;
    u_short* message;
    int var_v0;

    switch (*state) {
    case init:
        vs_battle_playSfx10();
        vs_mainMenu_containerEmptyBackup = vs_main_settings.containerEmpty;
        vs_menu_inventoryStorage = vs_main_allocHeapR(sizeof *vs_menu_inventoryStorage);
        vs_battle_rMemzero(vs_menu_inventoryStorage, sizeof *vs_menu_inventoryStorage);
        vs_mainMenu_populateBaseStats(16);
        vs_battle_initInformationTextBox(1);
        _promptYesNo(5);
        vs_mainmenu_setInformationMessage(
            (char*)&_containerStrings[VS_container_OFFSET_checkContainer]);
        *state = 1;
        break;
    case 1:
        option = _promptYesNo(0);
        if (option != 0) {
            if (option >= 0) {
                vs_battle_menuItem_t* menuItem;
                _initMemcard(1);
                vs_mainMenu_toggleBackgroundFade(1);
                vs_mainMenu_setMenuCommand(menuActionMenu);
                menuItem = vs_battle_setMenuItem(0, 0x140, 0x12, 0x7E, 8,
                    (char*)&_containerStrings[VS_container_OFFSET_container]);
                menuItem->state = 2;
                menuItem->targetPosition0 = 180;
                menuItem->selected = 1;
                *state = 2;
            } else {
                *state = 16;
            }
        }
        break;
    case 2:
        if ((vs_mainmenu_ready() != 0) && (_initMemcard(0) != 0)) {
            func_8008A4DC(0);
            func_800CB654(1);
            D_800EB9B0 = 0x200000;
            vs_mainMenu_setBackgroundRenderPriority(2046, 128);
            _initFileMenu();
            if ((*(u_int*)&vs_main_settings) & 0x10) {
                vs_battle_rMemzero(_spmcimg + 0x79E0, 0x3C00);
                *state = 7;
            } else {
                _findCurrentSave(1);
                *state = 3;
            }
        }
        break;
    case 3:
        option = _findCurrentSave(0);
        if (option != 0) {
            if (option < 0) {
                if (option == -2) {
                    message = _textTable + VS_MCMAN_BIN_OFFSET_insertError;
                } else {
                    message = _textTable + VS_MCMAN_BIN_OFFSET_emptyCard;
                }
                vs_mainmenu_setInformationMessage((char*)message);
                *state = 4;
            } else {
                _loadSaveData((option & 7) | ((option & 0x10) << 0xC));
                *state = 6;
            }
        }
        break;
    case 4:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            vs_mainmenu_setInformationMessage(
                (char*)(_textTable + VS_MCMAN_BIN_OFFSET_containerWarn));
            _promptYesNo(2);
            *state = 5;
        }
        break;
    case 5:
        option = _promptYesNo(0);
        if (option != 0) {
            if (option < 0) {
                *state = 14;
            } else {
                (*(u_int*)&vs_main_settings) |= 0x10;
                vs_battle_rMemzero(_spmcimg + 0x79E0, 0x3C00);
                *state = 7;
            }
        }
        break;
    case 6:
        option = _loadSaveData(0);
        if (option != 0) {
            if ((option > 0) && (_applyLoadedSaveFile(0) == 0)) {
                *state = 7;
                break;
            }
            message = _textTable + VS_MCMAN_BIN_OFFSET_emptyCard;
            vs_mainmenu_setInformationMessage((char*)message);
            *state = 4;
        }
        break;
    case 7:
        vs_battle_memcpy(vs_menu_inventoryStorage->unk0, &vs_main_inventory,
            sizeof vs_menu_inventoryStorage->unk0);
        vs_battle_memcpy(&vs_menu_inventoryStorage->unkF00, &vs_main_inventoryIndices,
            sizeof vs_menu_inventoryStorage->unkF00);
        vs_battle_memcpy(&vs_menu_inventoryStorage->unkFB0, (_spmcimg + 0x79E0),
            sizeof vs_menu_inventoryStorage->unkFB0);
        _shutdownMemcard();
        *state = 8;
        vs_battle_menuState.returnState = vs_battle_menuState.currentMenu;
        vs_battle_menuState.currentMenu = 14;
        break;
    case 8:
        if (vs_mainmenu_ready() != 0) {
            _initMemcard(1);
            *state = 9;
        }
        break;
    case 9:
        if (_initMemcard(0) != 0) {
            option = vs_battle_menuState.returnState;
            if (option != 0) {
                vs_battle_initInformationTextBox(1);
                if (option == 1) {
                    _promptYesNo(1);
                    vs_mainmenu_setInformationMessage(
                        (char*)&_containerStrings[VS_container_OFFSET_cancelWarning]);
                    *state = 12;
                } else {
                    *state = 10;
                }
            } else {
                *state = 13;
            }
        }
        break;
    case 10:
        _copyContainer((vs_menu_containerData*)(_spmcimg + 0x79E0),
            &vs_menu_inventoryStorage->unkC430.data,
            &vs_menu_inventoryStorage->unkC430.indices);
        _showSaveMenu(2);
        *state = 11;
        break;
    case 11:
        option = _showSaveMenu(0);
        if (option != 0) {
            if ((_dataNotSaved == 0) && (option < 0)) {
                vs_battle_initInformationTextBox(1);
                _promptYesNo(1);
                vs_mainmenu_setInformationMessage(
                    (char*)&_containerStrings[VS_container_OFFSET_cancelWarning]);
                *state = 12;
            } else {
                *state = 14;
            }
        }
        _drawFileMenu(vs_main_frameBuf);
        break;
    case 12:
        option = _promptYesNo(0);
        if (option != 0) {
            if (option == 1) {
                *state = 10;
                break;
            }
            *state = 13;
        }
        break;
    case 13:
        vs_main_settings.containerEmpty = vs_mainMenu_containerEmptyBackup;
        vs_battle_memcpy(&vs_main_inventory, vs_menu_inventoryStorage->unk0,
            sizeof vs_menu_inventoryStorage->unk0);
        vs_battle_memcpy(&vs_main_inventoryIndices, &vs_menu_inventoryStorage->unkF00,
            sizeof vs_menu_inventoryStorage->unkF00);
        /* fallthrough */
    case 14:
        func_8008A4DC(1);
        func_800CB654(0);
        D_800EB9B0 = 0;
        vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
        vs_mainMenu_setBackgroundRenderPriority(-4, 0x80);
        *state = 15;
        break;
    case 15:
        vs_mainMenu_setMenuCommand(menuActionNone);
        vs_mainMenu_dismissInformationBox();
        vs_mainMenu_toggleBackgroundFade(0);
        if (vs_mainmenu_ready() != 0) {
            _shutdownMemcard();
            *state = 16;
        }
        break;
    case 16:
        if ((vs_battle_dismissTextBox(7) == 0) && (vs_mainMenu_backgroundFadeStep == 0)) {
            vs_main_freeHeapR(vs_menu_inventoryStorage);
            *state = init;
            return 1;
        }
        break;
    }
    return 0;
}

/**
 * Renders the current play time in the data menu.
 */
static void _drawPlayTime(void)
{
    static char* _playTime = "00:00:00:00";

    char time[4];
    int digits;
    int i;

    __builtin_memcpy(time, &vs_main_gametime, sizeof time);
    if (time[3] >= 100) {
        *(int*)&time = 0;
        time[3] = 0;
        vs_battle_renderTextRaw("1", 0xC800D8, vs_scratch.unk4 - 0x14);
    } else {
        time[0] = ((((time[0] << 14) + vs_battle_keystreamBits(15)) * 5u) >> 14) / 3;
    }
    for (i = 0; i < 4; ++i) {
        digits = vs_battle_toBCD(time[i]);
        // BUG: invalid write to .rodata
        _playTime[9 - i * 3] = (digits >> 4) + 48;
        _playTime[10 - i * 3] = (digits & 0xF) + 48;
    }
    vs_battle_renderTextRaw(_playTime, 0xC800E0, vs_scratch.unk4 - 0x14);
    vs_battle_renderTextRaw("PLAY    TIME", 0xBC00E0, vs_scratch.unk4 - 0x14);
}

/**
 * Drives the save/load data menu, including memorycard initialization and
 * transitions back to gameplay.
 */
int vs_menu7_dataMenu(u_char* state)
{
    enum state {
        none = 0,
        init = 3,
        loadWait,
        initSaveMenu = 7,
        showSaveMenu,
        initLoadMenu,
        handleInput
    };

    char* menuStrings[4];
    int rowTypes[2];
    RECT rect;
    int row;

    if (*state < 11) {
        _drawPlayTime();
    }

    switch (*state) {
    case init:
        _initMemcard(1);
        *state = loadWait;
        break;

    case loadWait:
        if ((vs_mainmenu_ready() == 0) || (_initMemcard(0) == 0)) {
            break;
        }
    // Fallthrough
    case 5:
        for (row = 0; row < 2; ++row) {
            menuStrings[row * 2] = (char*)(&_textTable[_textTable[row * 2]]);
            menuStrings[row * 2 + 1] =
                (char*)(&_textTable[VS_MCMAN_BIN_OFFSET_saveDisabled]);
            rowTypes[row] = 0;
        }

        D_800F4E6B = func_8008A4FC();
        if (!D_800F4E6B || (vs_main_stateFlags.unkA7 != 0)) {
            rowTypes[0] |= 1;
        }
        row = vs_main_settings.cursorMemory;
        if ((*state) != loadWait) {
            vs_main_settings.cursorMemory = 1;
        }

        vs_mainmenu_setMenuRows(2, 0x143, menuStrings, rowTypes);
        vs_main_settings.cursorMemory = row;
        func_8008A4DC(0);
        *state = 6;
        break;

    case 6:
        row = vs_mainmenu_getSelectedRow() + 1;
        if (row != 0) {
            if (row > 0) {
                vs_mainMenu_clearMenuExcept(6);
                _initFileMenu();
                switch (row) {
                case 1:
                    *state = initSaveMenu;
                    break;

                case 2:
                    *state = initLoadMenu;
                    break;
                }

            } else {
                func_8008A4DC(1);
                vs_mainMenu_clearMenuExcept(vs_mainMenu_menuItemIds_none);
                if (row == -2) {
                    *state = 12;
                } else {
                    *state = 11;
                }
            }
        } else {
            if (((D_800F4E6B != 0) && (vs_main_stateFlags.unkA7 != 0))
                && (vs_mainMenu_getConfirmedRow() == 0)) {
                vs_battle_initInformationTextBox(1);
                vs_battle_textBoxes[7].state = 11;
            } else {
                vs_battle_textBoxes[7].state = 0;
            }
        }
        break;

    case initSaveMenu:
        if (vs_mainmenu_ready() != 0) {
            _showSaveMenu(1);
            *state = showSaveMenu;
        }
        break;

    case showSaveMenu:
        if (_showSaveMenu(0) != 0) {
            *state = 5;
        }
        _drawFileMenu(vs_main_frameBuf);
        break;

    case initLoadMenu:
        if (vs_mainmenu_ready() != 0) {
            _loadFileMenu(1);
            *state = handleInput;
        }
        break;

    case handleInput:
        row = _loadFileMenu(0);
        if (row != 0) {
            if (row < 0) {
                *state = 5;
                break;
            }
            setRECT(&rect, 0, 0, 640, 240);
            DrawSync(0);
            ClearImage(&rect, 0, 0, 0);
            _shutdownMemcard();
            *state = 0;
            DrawSync(0);
            vs_main_jumpToBattle();
            break;
        }
        _drawFileMenu(vs_main_frameBuf);
        break;

    case 11:
        vs_mainMenu_setMenuCommand(menuActionNone);
        vs_mainMenu_dismissInformationBox();
        vs_mainMenu_toggleBackgroundFade(0);
        *state = 13;
        break;

    case 12:
        vs_mainMenu_setMenuCommand(menuActionNone);
        vs_mainMenu_dismissInformationBox();
        vs_mainMenu_toggleBackgroundFade(0);
        *state = 14;
        break;

    case 13:
    case 14:
        if (vs_mainMenu_backgroundFadeStep != 0) {
            break;
        }
        _shutdownMemcard();
        if (*state == 14) {
            vs_battle_menuState.currentMenu = 7;
        }
        *state = none;
        return 1;
    }

    return 0;
}
