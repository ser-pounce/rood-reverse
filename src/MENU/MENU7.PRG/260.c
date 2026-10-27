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

static char _loadSaveDataErrorOffset;
static char _1[1] __attribute__((unused));
static u_short _fileProgressTarget;
static u_short _filePreviousProgressCounter;
static u_short _fileProgressPosition;
static int _fileProgressCounter;

#include "src/MENU/memcardLoadSave.h"

/**
 * Loads memorycard support data and installs card event handlers.
 *
 * Call with nonzero init to start initialization and with zero to poll;
 * returns one when ready and zero otherwise.
 */
static int _initMemcard(int init)
{
    enum state {
        none = 0,
        queueReady = 1,
        enqueued = 2,
    };

    static u_short _eventSpecs[] = { EvSpIOE, EvSpERROR, EvSpTIMOUT, EvSpNEW };
    static char _initMemcardState;
    static char _[3] __attribute__((unused));
    static vs_main_CdQueueSlot* _initMemcardCdQueueSlot;

    vs_main_CdFile cdFile;
    int i;
    u_int event;

    if (init != 0) {
        func_8007DFF0(0x1D, 3, 6);
        _spmcimg = vs_main_allocHeap(VS_SPMCIMG_BIN_SIZE);
        _mcData = (mcdata_t*)(_spmcimg + sizeof(savedata_t) * 3);
        _textTable = _mcData->textTable;
        _saveFileInfo = _mcData->saveFileInfo;
        _dirEntBuf = &_mcData->_dirEntBuf;
        cdFile.lba = VS_SPMCIMG_BIN_LBA;
        cdFile.size = VS_SPMCIMG_BIN_SIZE;
        _initMemcardCdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(_initMemcardCdQueueSlot, _spmcimg);
        _initMemcardState = none;
        return 0;
    }

    switch (_initMemcardState) {
    case none:
        if (_initMemcardCdQueueSlot->state == vs_main_CdQueueStateLoaded) {
            vs_main_freeCdQueueSlot(_initMemcardCdQueueSlot);
            _drawImage(vs_getXY(800, 256), _spmcimg, vs_getWH(224, 256));
            _initMemcardState = queueReady;
        }
        return 0;
    case queueReady:
        cdFile.lba = VS_MCDATA_BIN_LBA; // MCMAN.BIN must immediately follow MCDATA.BIN on
                                        // the disk
        cdFile.size = VS_MCDATA_BIN_SIZE + VS_MCMAN_BIN_SIZE;
        _initMemcardCdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(_initMemcardCdQueueSlot, _mcData);
        _initMemcardState = enqueued;
        break;
    case enqueued:
        break;
    default:
        return 0;
    }

    if (_initMemcardCdQueueSlot->state == vs_main_CdQueueStateLoaded) {
        vs_main_freeCdQueueSlot(_initMemcardCdQueueSlot);
        vs_main_enableReset(0);
        EnterCriticalSection();

        for (i = 0; i < 8; ++i) {
            event = SwCARD;
            if (i & 4) {
                event = HwCARD;
            }
            _memcardEventDescriptors[i] =
                OpenEvent(event, _eventSpecs[i & 3], EvMdNOINTR, 0);
        }

        ExitCriticalSection();

        for (i = 0; i < 8; ++i) {
            EnableEvent(_memcardEventDescriptors[i]);
        }
        return 1;
    }
    return 0;
}

/**
 * Disables and closes memorycard events and releases the support data.
 */
static void _shutdownMemcard(void)
{
    int i;

    for (i = 0; i < 8; ++i) {
        DisableEvent(_memcardEventDescriptors[i]);
    }

    EnterCriticalSection();

    for (i = 0; i < 8; ++i) {
        CloseEvent(_memcardEventDescriptors[i]);
    }

    ExitCriticalSection();
    vs_main_enableReset(1);
    vs_main_freeHeap(_spmcimg);
    func_8007E0A8(0x1D, 3, 6);
}

static fileMenuElements_t _fileMenuElements[10];
static char _2[8] __attribute__((unused));
static primBuf_t _primBuf;

#include "src/MENU/drawSprt.h"

static char _menuElementStops[] = { 0, 1, 2, 4, 8, 16, 32, 56, 80, 104, 128, 152, 176,
    200, 224, 248, 255, 255, 255, 255 };
static signed char _cursorFileOpSaturation[] = { 0, -56, -112, -104, -96, -88, -80, -72,
    -64, -56, -48, -40, -32, -24, -16, -8 };

enum vs_fileMenuUiIds_e {
    vs_uiids_colon = 0,
    vs_uiids_number = 1,
    vs_uiids_map = 2,
    vs_uiids_save = 3,
    vs_uiids_clear = 4,
    vs_uiids_time = 5,
    vs_uiids_percent = 6,
    vs_uiids_hp = 7,
    vs_uiids_mp = 8,
    vs_uiids_dot = 9,
};

/**
 * Draws the selected UI element at the desired position.
 */
static void _drawSaveInfoUI(int xy, enum vs_fileMenuUiIds_e id)
{
    static int _saveInfoUVClut[] = { vs_getUV0Clut(248, 8, 832, 223),
        vs_getUV0Clut(242, 0, 832, 223), vs_getUV0Clut(224, 120, 848, 223),
        vs_getUV0Clut(128, 56, 848, 223), vs_getUV0Clut(224, 112, 848, 223),
        vs_getUV0Clut(104, 56, 848, 223), vs_getUV0Clut(170, 76, 864, 223),
        vs_getUV0Clut(144, 0, 864, 223), vs_getUV0Clut(160, 0, 864, 223),
        vs_getUV0Clut(32, 9, 832, 223) };
    static int _saveInfoWh[] = { vs_getXY(3, 8), vs_getXY(13, 8), vs_getXY(17, 8),
        vs_getXY(22, 8), vs_getXY(26, 8), vs_getXY(19, 8), vs_getXY(10, 10),
        vs_getXY(16, 9), vs_getXY(18, 9), vs_getXY(5, 7) };
    _drawSprt(xy, _saveInfoUVClut[id], _saveInfoWh[id], 0xC);
}

#include "src/MENU/drawStats.h"

static int _selectCursorXy;
static char* _memoryCardMessage;
static char _isSaving;

#include "src/MENU/fileProcessingAnim.h"

static u_char _selectCursorColor;
static char _fileMenuScreenFade;

#include "src/MENU/fileMenuElement.h"

enum _findCurrentSave_e {
    findSaveTimeout = -2,
    findSaveNotFound = -1,
    findSavePending = 0
};

/**
 * Searches both cards asynchronously for the save matching current settings.
 *
 * A nonzero init restarts the search; subsequent calls return the current state.
 */
static int _findCurrentSave(int init)
{
    static char state;
    static char subState;

    int port;
    int currentSave;
    int event;
    int realPort;

    if (init != 0) {
        state = 0;
        subState = 0;
        return 0;
    }

    realPort = state >> 1;
    port = realPort + 1;

    if ((state & 1) == 0) {
        vs_mainmenu_setInformationMessage(
            (char*)(_textTable + _textTable[VS_MCMAN_BIN_INDEX_accessing0 - 1 + port]));
        _memoryCardMessage =
            (char*)(_textTable + _textTable[VS_MCMAN_BIN_INDEX_accessing0 - 1 + port]);
        _memcardEventHandler(realPort + 1);
        ++state;
    } else {
        event = _memcardEventHandler(0) & 3;

        if (event != memcardEventPending) {
            if (event == memcardEventIoEnd) {
                if (_initSaveFileInfo(realPort + 1) == 0) {
                    currentSave = _findCurrentSaveOnActiveMemcard();
                    if (currentSave != 0) {
                        return currentSave + (realPort * 16);
                    }
                }
            } else if (event == memcardEventTimeout) {
                if (state != 1) {
                    if (subState != 0) {
                        return findSaveTimeout;
                    }
                } else {
                    subState = state;
                }
            }
            ++state;
        }
    }
    return state != 4 ? findSavePending : findSaveNotFound;
}

enum _memcardEventMask_e {
    memcardEventMaskIgnoreNoEvent = 0x30,
    memcardEventMaskAll = 0x70
};

#define MEMCARD_MASKED_HANDLER_PAD 5
#include "src/MENU/fileMenu.h"

#include "src/MENU/drawFileMenuBg.h"

#define PROMPT_FORMAT_PAD 8
#include "src/MENU/promptConfirm.h"

#define PLAY_INVALID_SFX() vs_battle_playInvalidSfx()
#include "src/MENU/showSaveFilesMenu.h"

#include "src/MENU/selectSaveMemoryCard.h"

/**
 * Runs the save/container slot chooser and handles unsaved container data.
 *
 * A nonzero initState initializes the requested entry state; returns one when
 * a card-save flow completes, -1 when leaving without saving, or zero pending.
 */
static int _showSaveMenu(int initState)
{
    enum state {
        init = 0,
        saveExists = 1,
        loadSave = 2,
        initSlot1 = 3,
        initSlot2 = 4,
        waitForSlotAnimation = 5,
        handleInput = 6,
        selectCard = 7,
        returnNoSave = 8,
        containerWarn = 9,
        eraseContainerData = 10,
        discardChanges = 11,
    };

    static char state;
    static u_char selectedFile;
    static char _[3] __attribute__((unused));

    u_short clear = vs_char_terminator | (vs_char_terminator << 8);
    fileMenuElements_t* element;
    int currentSave;
    int val;

    if (initState != 0) {
        selectedFile = 1;
        _containerDataEmpty = 0;
        if (vs_main_settings.cursorMemory != 0) {
            selectedFile = D_800F4EE8.unk85[3] + 1;
        }
        _dataNotSaved = 0;
        _isSaving = 1;
        state = (initState - 1) * 3;
        element = _initFileMenuElement(0, vs_getXY(320, 34), vs_getWH(140, 12),
            (char*)(_textTable + VS_MCMAN_BIN_OFFSET_save));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 180;
        element->innertextBlendFactor = 8;
        element->selected = 1;
        _memoryCardMessage = 0;
        vs_mainmenu_setInformationMessage((char*)&clear);
        return 0;
    }

    switch (state) {
    case init:
        if (*(int*)&vs_main_settings & 0x10) {
            memset(&((savedata_t*)_spmcimg + 1)->containerData, 0,
                sizeof((savedata_t*)_spmcimg + 1)->containerData);
            state = initSlot1;
        } else if (_fileMenuElementsActive() != 0) {
            if (vs_main_settings.slotState != slotStateUnavailable) {
                _findCurrentSave(1);
                state = saveExists;
            } else {
                state = initSlot1;
            }
        }
        break;
    case saveExists:
        currentSave = _findCurrentSave(0);
        if (currentSave == findSavePending) {
            break;
        }
        if (currentSave < findSavePending) {
            _memoryCardMessage = (char*)(_textTable
                                         + (currentSave == findSaveTimeout
                                                 ? VS_MCMAN_BIN_OFFSET_insertError
                                                 : VS_MCMAN_BIN_OFFSET_emptyCard));
            state = containerWarn;
        } else {
            _loadSaveData((currentSave & 7) | ((currentSave & 16) << 12));
            state = loadSave;
        }
        break;
    case loadSave:
        val = _loadSaveData(0);
        if (val != 0) {
            if ((val <= 0) || (_applyLoadedSaveFile(0) != 0)) {
                state = containerWarn;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_emptyCard);
            } else {
                state = initSlot1;
            }
        }
        break;
    case initSlot1:
        if (_fileMenuElementsActive() != 0) {
            element = _initFileMenuElement(1, vs_getXY(320, 50), vs_getWH(126, 12),
                (char*)(_textTable + VS_MCMAN_BIN_OFFSET_slot1));
            element->state = fileMenuElementStateAnimateX;
            element->targetPosition = 194;
            state = initSlot2;
        }
        break;
    case initSlot2:
        element = _initFileMenuElement(2, vs_getXY(320, 66), vs_getWH(126, 12),
            (char*)(_textTable + VS_MCMAN_BIN_OFFSET_slot2));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 194;
        state = waitForSlotAnimation;
        break;
    case waitForSlotAnimation:
        if (_fileMenuElementsActive() != 0) {
            vs_mainmenu_setInformationMessage((char*)&clear);
            state = handleInput;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_selectSlot);
        }
        break;
    case handleInput:
        _fileMenuElements[selectedFile].selected = 1;
        _fileMenuElements[3 - selectedFile].selected = 0;
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            val = _dataNotSaved;
            _selectCursorXy = 0;
            if (val < 3) {
                do {
                    _fileMenuElements[val].state = fileMenuElementStateAnimateX;
                    _fileMenuElements[val].targetPosition = 320;
                    ++val;
                } while (val < 3);
            }
            if (_dataNotSaved != 0) {
                _memoryCardMessage =
                    (char*)(_textTable + VS_MCMAN_BIN_OFFSET_containerWarnDataLoss);
                _promptConfirm(1);
                state = discardChanges;
            } else {
                state = returnNoSave;
            }
        } else if (vs_main_buttonsPressed.all & PADRright) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            _selectSaveMemoryCard(selectedFile);
            _selectCursorXy = 0;
            state = selectCard;
        } else {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                selectedFile = 3 - selectedFile;
                D_800F4EE8.unk85[3] = selectedFile - 1;
            }
            _selectCursorXy = vs_getXY(180, (selectedFile + 1) * 16 + 10);
        }
        break;
    case selectCard:
        val = _selectSaveMemoryCard(0);
        if (val != 0) {
            if (val < 0) {
                state = initSlot1;
                break;
            }
            _initFileMenu();
            return 1;
        }
        break;
    case returnNoSave:
        if (_fileMenuElementsActive() != 0) {
            return -1;
        }
        break;
    case containerWarn:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            vs_mainmenu_setInformationMessage((char*)&clear);
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_containerWarn);
            _promptConfirm(1);
            state = eraseContainerData;
        }
        break;
    case eraseContainerData:
    case discardChanges:
        val = _promptConfirm(0);
        if (val != 0) {
            if (state == discardChanges) {
                if (val > 0) {
                    *(int*)&vs_main_settings = *(int*)&vs_main_settings | 0x10;
                }
                val = -val;
            }
            if (val < 0) {
                _fileMenuElements[0].state = fileMenuElementStateAnimateX;
                _fileMenuElements[0].targetPosition = 320;
                state = returnNoSave;
                break;
            }
            if (state == eraseContainerData) {
                _containerDataEmpty = 1;
                memset(&((savedata_t*)_spmcimg + 1)->containerData, 0,
                    sizeof((savedata_t*)_spmcimg + 1)->containerData);
            }
            state = initSlot1;
        }
        break;
    }
    return 0;
}

#include "src/MENU/showLoadFilesMenu.h"

#include "src/MENU/selectLoadMemoryCard.h"

/**
 * Runs the initial slot chooser and asynchronous load flow for game over/data
 * menus.
 *
 * A nonzero initFadeout initializes the menu; returns one when a save is
 * selected, -1 when cancelled, or zero while active.
 */
static int _loadFileMenu(int initFadeout)
{
    enum state {
        init = 0,
        displaySlot1 = 1,
        displaySlot2 = 2,
        waitForSlotAnimation = 3,
        handleInput = 4,
        slotSelected = 5,
        exit = 6,
        fadeAndReturnSelected = 7,
        fadeAndReturnNotSelected = 8,
    };

    static char state;
    static u_char selectedFile;
    static char fadeout;
    static char _[1] __attribute__((unused));

    fileMenuElements_t* element;
    int i;

    if (initFadeout != 0) {
        fadeout = initFadeout - 1;
        selectedFile = 1;

        if (vs_main_settings.cursorMemory != 0) {
            selectedFile = D_800F4EE8.unk85[3] + 1;
        }
        _isSaving = 0;
        state = init;
        return 0;
    }
    switch (state) {
    case init:
        element = _initFileMenuElement(0, vs_getXY(320, 34), vs_getWH(140, 12),
            (char*)(_textTable + VS_MCMAN_BIN_OFFSET_load));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 180;
        element->selected = 1;
        element->innertextBlendFactor = 8;
        state = displaySlot1;
        break;
    case displaySlot1:
        if (_fileMenuElementsActive() != 0) {
            element = _initFileMenuElement(1, vs_getXY(320, 50), vs_getWH(126, 12),
                (char*)(_textTable + VS_MCMAN_BIN_OFFSET_slot1));
            element->state = fileMenuElementStateAnimateX;
            element->targetPosition = 194;
            state = displaySlot2;
        }
        break;
    case displaySlot2:
        element = _initFileMenuElement(2, vs_getXY(320, 66), vs_getWH(126, 12),
            (char*)(_textTable + VS_MCMAN_BIN_OFFSET_slot2));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 194;
        state = waitForSlotAnimation;
        break;
    case waitForSlotAnimation:
        if (_fileMenuElementsActive() != 0) {
            state = handleInput;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_selectSlot);
        }
        break;
    case handleInput:
        _fileMenuElements[selectedFile].selected = 1;
        _fileMenuElements[3 - selectedFile].selected = 0;
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            _selectCursorXy = 0;
            for (i = 0; i < 3; ++i) {
                _fileMenuElements[i].state = fileMenuElementStateAnimateX;
                _fileMenuElements[i].targetPosition = 320;
            }
            state = exit;
        } else if (vs_main_buttonsPressed.all & PADRright) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            _selectLoadMemoryCard(selectedFile);
            _selectCursorXy = 0;
            state = slotSelected;
        } else {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                selectedFile = 3 - selectedFile;
                D_800F4EE8.unk85[3] = selectedFile - 1;
            }
            _selectCursorXy = ((((selectedFile + 1) * 16) + 10) << 16) | 180;
        }
        break;
    case slotSelected:
        element = (fileMenuElements_t*)_selectLoadMemoryCard(0);
        if (element != 0) {
            if ((long)element < 0) {
                state = displaySlot1;
            } else {
                state = fadeAndReturnSelected;
            }
        }
        break;
    case exit:
        if (_fileMenuElementsActive() != 0) {
            if (fadeout == 0) {
                return -1;
            }
            state = fadeAndReturnNotSelected;
        }
        break;
    case fadeAndReturnSelected:
        if (++_fileMenuScreenFade > 30) {
            return 1;
        }
        break;
    case fadeAndReturnNotSelected:
        if (++_fileMenuScreenFade < 31) {
            break;
        }
        return -1;
    }
    return 0;
}

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
