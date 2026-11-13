#pragma once
#include "common.h"
#include "src/SLUS_010.40/main.h"
#include "src/SLUS_010.40/cd.h"
#include "src/SLUS_010.40/gameFlags.h"
#include "src/SLUS_010.40/gameState.h"
#include "src/SLUS_010.40/memory.h"
#include "src/SLUS_010.40/pad.h"
#include "src/SLUS_010.40/sound.h"
#include "src/SLUS_010.40/zoneState.h"
#include "src/BATTLE/BATTLE.PRG/battleUnk.h"
#include "src/BATTLE/BATTLE.PRG/mpd.h"

/* Memorycard save/load support and the file menu code shared by the title and menu
 * overlays. The including file defines memcardFilenameTemplate first, and the
 * following overlay specific hooks (several refer to locals of the function using them):
 *  - PACKAGE_SAVE_PREPARE, KEYSTREAM_BITS, PACKAGE_SAVE_CLEAR_CONTAINER,
 *    PACKAGE_SAVE_UPDATE_SAVE_COUNT, PACKAGE_SAVE_SET_LOCATION: save data packaging
 *  - MEMCARD_INIT_HOOK, MEMCARD_SHUTDOWN_HOOK: extra work when starting and stopping
 *    card support (default: nothing)
 *  - MEMCARD_MASKED_HANDLER_PAD: size of the alignment filler after the masked handler
 *    state, since the data that follows differs between overlays
 *  - FIND_SAVE_ACCESSING_HOOK: extra work when starting to access a card (default:
 *    nothing) */

#ifndef MEMCARD_INIT_HOOK
#define MEMCARD_INIT_HOOK()
#endif
#ifndef MEMCARD_SHUTDOWN_HOOK
#define MEMCARD_SHUTDOWN_HOOK()
#endif
#ifndef FIND_SAVE_ACCESSING_HOOK
#define FIND_SAVE_ACCESSING_HOOK(msg)
#endif
#include "src/SLUS_010.40/saveData.h"
#include "src/SLUS_010.40/sfx.h"
#include "build/assets/MENU/MCMAN.BIN.h"
#include "build/src/include/lbas.h"
#include "vs_string.h"
#include <libapi.h>
#include <libetc.h>
#include <string.h>

static long memcardEventDescriptors[8];

enum memcardEvents_e { memcardEventsSw, memcardEventsHw = 4 };

enum testMemcardEvents_e {
    memcardInternalEventIoEnd,
    memcardInternalEventError,
    memcardInternalEventTimeout,
    memcardInternalEventUnformatted,
    memcardInternalEventNone,
};

enum memcardEventHandler_e {
    memcardEventPending = 0,
    memcardEventIoEnd = 1,
    memcardEventTimeout = 2,
    memcardEventUnformatted = 3
};

/**
 * Returns the first signalled memorycard event of the requested type, or
 * memcardInternalEventNone when none of the four events is signalled.
 */
static enum testMemcardEvents_e testMemcardEvents(enum memcardEvents_e type)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if (TestEvent(memcardEventDescriptors[i + type]) == 1) {
            return i;
        }
    }
    return i;
}

/**
 * Tests each event in the selected memorycard event group to clear its signal.
 */
static void resetMemcardEvents(enum memcardEvents_e type)
{
    int i;

    for (i = 0; i < 4; ++i) {
        TestEvent(memcardEventDescriptors[i + type]);
    }
}

/**
 * Uploads an image to VRAM and waits for the transfer to finish.
 */
static void drawImage(int xy, void* buffer, int wh)
{
    RECT rect;

    *(int*)&rect.x = xy;
    *(int*)&rect.w = wh;
    LoadImage(&rect, buffer);
    DrawSync(0);
}

/**
 * Reads an image from VRAM into a buffer and waits for the transfer.
 */
static void readImage(int xy, void* buffer, int wh)
{
    RECT rect;

    *(int*)&rect.x = xy;
    *(int*)&rect.w = wh;
    StoreImage(&rect, buffer);
    DrawSync(0);
}

/**
 * Copies count bytes in reverse order.
 */
static void rMemcpy(void* dst, void const* src, int count)
{
    do {
        --count;
        ((char*)dst)[count] = ((char const*)src)[count];
    } while (count != 0);
}

/**
 * Builds the permanent save filename in a reusable static buffer.
 *
 * @param port Zero selects memorycard port 1; any other value selects port 2.
 */
static char* memcardMakeFilename(int port, int fileNo)
{
    static char filename[32];

    memset(filename, 0, ' ');
    strcpy(filename, memcardFilenameTemplate);
    filename[2] = port == 0 ? '0' : '1';
    filename[20] = fileNo + '0';
    return filename;
}

/**
 * Builds the temporary save filename in a reusable static buffer.
 *
 * @param port Zero selects memorycard port 1; any other value selects port 2.
 */
static char* memcardMakeTempFilename(int port, int fileNo)
{
    static char filename[32];

    memset(filename, 0, ' ');
    strcpy(filename, memcardFilenameTemplate);
    filename[2] = port == 0 ? '0' : '1';
    filename[20] = fileNo + 'A' - 1;
    return filename;
}

static char* mcImageBuf;
static vs_Mcdata* mcData;
static u_short* textTable;
static UNUSED char _0[4];
static struct DIRENTRY* memcardFiles[15];
static struct DIRENTRY* dirEntBuf;
/* Memorycard save helpers shared by the title and menu overlays. The including file
 * defines memcardFilenameTemplate first. */

static vs_SaveInfoFrame* saveSlotInfo;

/**
 * Finds the save slot with the greatest generation number.
 *
 * @return Zero-based slot index; returns zero when no active slot is found.
 */
static u_int getNewestSaveFile(void)
{
    u_int i;
    u_int maxCounter = 0;
    u_int fileIndex = 0;

    for (i = 0; i < 5; ++i) {
        if (saveSlotInfo[i].identity.base.slotState >= 3) {
            if (maxCounter < saveSlotInfo[i].identity.base.generation) {
                maxCounter = saveSlotInfo[i].identity.base.generation;
                fileIndex = i;
            }
        }
    }
    return fileIndex;
}

/**
 * Finds the active save by matching its identity and generation to settings.
 *
 * @return One-based file number, or zero when the active save is absent.
 */
static int findCurrentSaveOnActiveMemcard(void)
{
    int i;
    for (i = 0; i < 5; ++i) {
        if ((saveSlotInfo[i].identity.base.slotState >= slotStateInUse)
            && (saveSlotInfo[i].identity.base.slotState == vs_main_settings.slotState)
            && (saveSlotInfo[i].identity.key == vs_main_settings.key)
            && (saveSlotInfo[i].stats.cumulativeSaveCount
                == vs_main_settings.cumulativeSaveCount)
            && (saveSlotInfo[i].identity.base.generation
                == vs_main_settings.saveFileGeneration)) {
            return i + 1;
        }
    }
    return 0;
}

/**
 * Recognizes a save filename and decodes its permanent or temporary slot.
 *
 * @return 1-5 for permanent files, -1 to -5 for temporary files, or zero if
 * the name is not a save file.
 */
static int memcardFileNumberFromFilename(char* filename)
{
    int i;
    char const* gameCode = &memcardFilenameTemplate[5];

    for (i = 0; i < 15; ++i) {
        if (gameCode[i] != filename[i]) {
            return 0;
        }
    }

    i = filename[15] - 'A';

    if (i < 5u) {
        return -(filename[15] - 'A' + 1);
    }

    i = filename[15] - '1';

    if (i < 5u) {
        return filename[15] - '0';
    }

    return 0;
}

/**
 * Checksums the requested save-data sectors and validates the info sector.
 *
 * @return Nonzero if a sector checksum differs or the info-sector checksum is
 * nonzero; otherwise zero.
 */
static int verifySaveChecksums(vs_Savedata data[], int sectorCount)
{
    int checksum;
    int i;
    int j;
    char* p = (char*)data;

    for (i = 0; i < sectorCount; ++i) {
        checksum = 0;
        if (i != 1) {
            for (j = 0; j < 256; ++j) {
                checksum ^= p[j];
            }

            if (data->info.checksums[i] != checksum) {
                return 1;
            }
        }
        p += 256;
    }

    p = (char*)data + 0x100;
    checksum = 0;
    for (j = 0; j < 256; ++j) {
        checksum ^= p[j];
    }

    return checksum != 0;
}

/**
 * Decodes count bytes in place using the save format's key-driven byte stream.
 */
static void decode(u_int key, void* buf, int count)
{
    for (; count != 0; --count) {
        key *= 0x19660D;
        *((char*)buf++) -= key >> 24;
    }
}

/**
 * Reads and verifies the metadata for a one-based save file number.
 *
 * @param id Packs the memorycard port in the high bits and the file number
 * in the low bits.
 * @return Zero if valid metadata was read, or one if all read/validation
 * attempts failed.
 */
static int readSaveFileInfo(int id)
{
    vs_SaveInfoFrame saveInfo[4];
    int i;
    int port = id >> 12;

    id &= 7;

    for (i = 0; i < 3; ++i) {
        int bytesRead;
        int file = open(memcardMakeFilename(port, id), O_RDONLY);

        if (file == -1) {
            continue;
        }
        bytesRead = read(file, saveInfo, sizeof saveInfo);
        close(file);
        if (bytesRead != sizeof saveInfo) {
            continue;
        }
        decode(saveInfo[3].identity.key, &saveInfo[3].identity.base.slotState,
            sizeof saveInfo[3] - sizeof(int));
        if (verifySaveChecksums((vs_Savedata*)saveInfo, 2) == 0) {
            rMemcpy(&saveSlotInfo[id - 1], &saveInfo[3], sizeof saveInfo[3]);
            return 0;
        }
    }

    memset(&saveSlotInfo[id - 1], 0, sizeof saveSlotInfo[id - 1]);
    return 1;
}

/**
 * Checks whether a recognized memorycard save filename ends in id.
 */
static int memcardSaveIdExists(int id)
{
    int i;

    for (i = 0; i < 15; ++i) {
        char* filename = memcardFiles[i]->name;
        if ((filename != NULL) && (memcardFileNumberFromFilename(filename) != 0)
            && (filename[15] == id)) {
            return 1;
        }
    }
    return 0;
}

/**
 * Removes temporary files when the corresponding permanent file also exists.
 *
 * @return A bit per removed temporary slot, or 0x80 if an erase fails.
 */
static int deleteRedundantTempFiles(int port)
{
    int i;
    int ret = 0;

    for (i = 0; i < 5; ++i) {
        if ((memcardSaveIdExists(i + '1') != 0) && (memcardSaveIdExists(i + 'A') != 0)) {
            if (erase(memcardMakeTempFilename(port, i + 1)) == 0) {
                return 0x80;
            }
            ret |= 1 << i;
        }
    }
    return ret;
}

/**
 * Scans a card, validates save metadata, and marks available save slots.
 *
 * @return Nonzero if cleanup of redundant temporary files fails.
 */
static int initSaveFileInfo(int port)
{
    long fileNo;
    int i;
    int tempFilesDeleted;
    int slotsAvailable = 15;

    for (i = 14; i >= 0; --i) {
        memcardFiles[i] = NULL;
    }

    fileNo = (long)firstfile((port == 1) ? ("bu00:*") : ("bu10:*"), dirEntBuf);
    memcardFiles[0] = (void*)fileNo;

    for (i = 1; (i < 15) && fileNo; ++i) {
        fileNo = (long)nextfile(dirEntBuf + i);
        memcardFiles[i] = (void*)fileNo;
    }

    memset(saveSlotInfo, 0, sizeof *saveSlotInfo * 5);
    tempFilesDeleted = deleteRedundantTempFiles((port - 1) * 16);
    if (tempFilesDeleted & 0x80) {
        return 1;
    }
    for (i = 0; i < 15; ++i) {
        struct DIRENTRY* file = memcardFiles[i];

        if (file == NULL) {
            continue;
        }
        fileNo = memcardFileNumberFromFilename(file->name);
        if (fileNo != 0) {
            if (fileNo < 0) {
                fileNo = -fileNo;
                if ((tempFilesDeleted >> (fileNo - 1)) & 1) {
                    continue;
                }
                memset(&saveSlotInfo[fileNo - 1], 0, sizeof saveSlotInfo[fileNo - 1]);
                saveSlotInfo[fileNo - 1].identity.base.slotState = slotStateTemporary;
            } else if (readSaveFileInfo(((port - 1) << 16) | fileNo) != 0) {
                slotsAvailable += (file->size + 0x1FFF) >> 13;
            }
        }
        slotsAvailable -= (file->size + 0x1FFF) >> 13;
    }

    for (; slotsAvailable >= 3; slotsAvailable -= 3) {
        for (i = 0; i < 5; ++i) {
            if (saveSlotInfo[i].identity.base.slotState == slotStateUnavailable) {
                saveSlotInfo[i].identity.base.slotState = slotStateAvailable;
                break;
            }
        }
    }

    return 0;
}

/* Memorycard file creation and event state machine shared by the title and menu
 * overlays. */

/**
 * Creates an empty permanent save file, first erasing any existing file.
 *
 * @return Zero on success, or -1 if the file cannot be created.
 */
static int createSaveFile(int port, int id)
{
    long file;
    char* fileName = memcardMakeFilename((port - 1) * 16, id);

    erase(fileName);
    file = open(fileName, O_CREAT | (3 << 16));
    if (file != -1) {
        close(file);
        return 0;
    }
    return -1;
}

/**
 * Initializes or advances the stateful memorycard detect/load operation.
 *
 * A nonzero initPort starts polling that card (1 or 2); subsequent calls with
 * zero advance the state and report pending, completion, timeout, or unformatted state.
 */
static enum memcardEventHandler_e memcardEventHandler(int initPort)
{
    enum state {
        init = 0,
        ready = 1,
        unformatted = 2,
        confirmed = 3,
        loadReady = 4,
        loaded = 5,
    };

    static char state;
    static char port;
    static char initTimeout;
    static char timeout;
    static char eventType;

    int event;

    if (initPort != 0) {
        port = (initPort - 1) * 16;
        state = init;
        initTimeout = 0;
        return memcardEventPending;
    }
    switch (state) {
    case init:
        if (++initTimeout >= 4) {
            return memcardEventTimeout;
        }
        resetMemcardEvents(memcardEventsSw);
        if (_card_info(port) == 0) {
            break;
        }
        state = ready;
        timeout = 0;
        eventType = memcardEventsSw;
        // fallthrough
    case ready:
        switch (testMemcardEvents(memcardEventsSw)) {
        case memcardInternalEventIoEnd:
            state = loadReady;
            break;
        case memcardInternalEventError:
        case memcardInternalEventTimeout:
            state = init;
            break;
        case memcardInternalEventUnformatted:
            state = unformatted;
            break;
        case memcardInternalEventNone:
            if (timeout++ > 64) {
                state = init;
            }
            break;
        }
        break;
    case unformatted:
        resetMemcardEvents(memcardEventsHw);
        if (_card_clear(port) == 0) {
            break;
        }
        state = confirmed;
        timeout = 0;
        eventType = memcardEventsHw;
        // fallthrough
    case confirmed:
        do {
            event = testMemcardEvents(memcardEventsHw);
        } while (event == memcardInternalEventNone);
        if (event == memcardInternalEventIoEnd) {
            state = loadReady;
            break;
        }
        if (event < memcardInternalEventIoEnd) {
            break;
        }
        if (event >= memcardInternalEventNone) {
            break;
        }
        state = init;
        break;
    case loadReady:
        resetMemcardEvents(memcardEventsSw);
        if (_card_load(port) == 0) {
            break;
        }
        state = loaded;
        timeout = 0;
        // fallthrough
    case loaded:
        event = testMemcardEvents(memcardEventsSw);
        switch (event) {
        case memcardInternalEventIoEnd:
            return eventType + memcardEventIoEnd;
        case memcardInternalEventError:
        case memcardInternalEventTimeout:
            state = init;
            break;
        case memcardInternalEventUnformatted:
            return eventType + memcardEventUnformatted;
        case memcardInternalEventNone:
            if (timeout++ > 64) {
                state = init;
            }
            break;
        }
        break;
    }
    return memcardEventPending;
}

/**
 * Decodes and validates the loaded save, optionally applying it to game state.
 *
 * @return One for invalid data, zero when valid (and applied when write is
 * nonzero).
 */
static int applyLoadedSaveFile(int apply)
{
    int blockCount;
    vs_Savedata* spmcimg = (vs_Savedata*)mcImageBuf;
    void* spmcimg2 = spmcimg + 1;
    vs_Savedata* s4 = spmcimg + 1;
    vs_SaveIdentity* identity = &spmcimg[1].info.identity;

    decode(identity->key, &identity->base.slotState,
        sizeof(vs_Savedata) - (u_long) & ((vs_Savedata*)0)->info.identity.base.slotState);

    blockCount = 92;
    if (apply != 0) {
        blockCount = 32;
    }

    if ((verifySaveChecksums(spmcimg + 1, blockCount) != 0)
        || (identity->base.version != SAVE_FORMAT_VERSION)) {
        do {
            return 1;
        } while (0);
    }

    if (apply == 0) {
        return 0;
    }

    rMemcpy(&vs_main_stateFlags, spmcimg[1].stateFlags, sizeof vs_main_stateFlags);
    rMemcpy(
        vs_main_actionsLearned, spmcimg[1].actionsLearned, sizeof vs_main_actionsLearned);
    rMemcpy(&vs_main_mapStatus, spmcimg[1].mapStatus, sizeof vs_main_mapStatus);
    rMemcpy(&vs_main_settings, &spmcimg[1].settings, sizeof vs_main_settings);
    rMemcpy(&vs_main_characterSnapshot, &spmcimg[1].character,
        sizeof vs_main_characterSnapshot);
    rMemcpy(&vs_main_inventory, &spmcimg[1].inventory, sizeof vs_main_inventory);
    rMemcpy(&vs_main_inventoryIndices, &spmcimg[1].inventoryIndices,
        sizeof vs_main_inventoryIndices);
    rMemcpy(&vs_main_spawnPoint, &spmcimg[1].spawnPoint, sizeof vs_main_spawnPoint);
    rMemcpy(&vs_main_scoredata, &spmcimg[1].scoreData, sizeof vs_main_scoredata);
    vs_main_zoneEnemyCacheIndex = s4->zoneEnemyCacheIndex;
    rMemcpy(
        vs_main_zoneEnemyCache, spmcimg[1].zoneEnemyCache, sizeof vs_main_zoneEnemyCache);
    spmcimg2 = &vs_main_artsStatus;
    rMemcpy(&vs_main_artsStatus, &spmcimg[1].artsStatus, sizeof vs_main_artsStatus);
    vs_main_gametime.t = spmcimg[1].info.stats.gameTime.t;
    vs_main_setCharacterRestorePending();
    vs_main_setMonoSound(vs_main_settings.monoSound);
    return 0;
}

/**
 * Builds the save metadata and payload from current game state, then encodes
 * the protected save-data region.
 *
 * @param targetFile Zero-based target slot used in the displayed save metadata.
 */
static void packageGameSaveData(int targetFile)
{
#pragma sjis(start)
    static const u_char defaultFileTitle[] =
        "ＶＡＧＲＡＮＴ　ＳＴＯＲＹ　ＦＩＬＥ　１　　　００：００：００　";
#pragma sjis(end)

    long i;
    int j;
    int var_a0;
    u_char const* s0 = defaultFileTitle;
    vs_Savedata* savedata = (vs_Savedata*)mcImageBuf;
    vs_Savedata* savedata2 = savedata + 1;
    vs_Savedata* savedata3 = savedata;
    vs_SaveInfoFrame* s5 = &savedata->info;

    PACKAGE_SAVE_PREPARE();
    memset(savedata, 0, sizeof *savedata);
    savedata->titleFrame.magic[0] = 'S';
    savedata->titleFrame.magic[1] = 'C';
    savedata->titleFrame.iconFlag = 0x11;
    savedata->titleFrame.blockCount = 3;
    rMemcpy(savedata->titleFrame.title, s0, sizeof savedata->titleFrame.title);
    savedata->titleFrame.title[19] += (targetFile << 8);

    if (vs_main_gametime.t.h == 100) {
        savedata->titleFrame.title[22] = 0x5082;
    } else {
        savedata->titleFrame.title[23] += ((vs_main_gametime.t.h / 10) << 8);
        savedata->titleFrame.title[24] += ((vs_main_gametime.t.h % 10) << 8);
        savedata->titleFrame.title[26] += ((vs_main_gametime.t.m / 10) << 8);
        savedata->titleFrame.title[27] += ((vs_main_gametime.t.m % 10) << 8);
        savedata->titleFrame.title[29] += ((vs_main_gametime.t.s / 10) << 8);
        savedata->titleFrame.title[30] += ((vs_main_gametime.t.s % 10) << 8);
    }
    savedata3->titleFrame.title[31] = 0;
    rMemcpy(savedata3->titleFrame.iconPalette, mcData->iconPalettes[targetFile],
        sizeof savedata->titleFrame.iconPalette);
    rMemcpy(savedata3->iconFrame0, mcData->iconBitmaps[targetFile],
        sizeof savedata->iconFrame0);

    if (vs_main_settings.slotState == 0) {
        vs_main_settings.slotState = KEYSTREAM_BITS(0x20);
        if (vs_main_settings.slotState < 3) {
            vs_main_settings.slotState = 0x17385CA9;
        }
        PACKAGE_SAVE_CLEAR_CONTAINER();
    }

    vs_main_settings.key = KEYSTREAM_BITS(0x20);
    s5->identity.key = vs_main_settings.key;
    s5->identity.base.slotState = vs_main_settings.slotState;
    vs_main_settings.saveFileGeneration = 0;

    for (i = 0; i < 5; ++i) {
        if (saveSlotInfo[i].identity.base.slotState >= slotStateInUse) {
            if (vs_main_settings.saveFileGeneration
                < saveSlotInfo[i].identity.base.generation) {
                vs_main_settings.saveFileGeneration =
                    saveSlotInfo[i].identity.base.generation;
            }
        }
    }
    s5->identity.base.generation = ++vs_main_settings.saveFileGeneration;

    if (vs_main_settings.cumulativeSaveCount < 9999) {
        ++vs_main_settings.cumulativeSaveCount;
    }

    PACKAGE_SAVE_UPDATE_SAVE_COUNT();

    s5->identity.base.version = SAVE_FORMAT_VERSION;
    s5->stats.gameTime.t = vs_main_gametime.t;
    s5->stats.currentHP = vs_main_characterSnapshot.stats.currentHP;
    s5->stats.maxHP = vs_main_characterSnapshot.stats.maxHP;
    s5->stats.cumulativeSaveCount = vs_main_settings.cumulativeSaveCount;
    s5->stats.currentGameSaveCount = vs_main_settings.currentGameSaveCount;
    PACKAGE_SAVE_SET_LOCATION();
    s5->stats.clearCount = vs_main_stateFlags.clearCount;
    s5->stats.currentMP = vs_main_characterSnapshot.stats.currentMP;
    s5->stats.maxMP = vs_main_characterSnapshot.stats.maxMP;
    rMemcpy(savedata->stateFlags, &vs_main_stateFlags, sizeof savedata->stateFlags);
    rMemcpy(savedata->actionsLearned, vs_main_actionsLearned,
        sizeof savedata->actionsLearned);
    rMemcpy(savedata->mapStatus, &vs_main_mapStatus, sizeof savedata->mapStatus);
    rMemcpy(&savedata->settings, &vs_main_settings, sizeof savedata->settings);
    rMemcpy(&savedata->character, &vs_main_characterSnapshot, sizeof savedata->character);
    rMemcpy(&savedata->inventory, &vs_main_inventory, sizeof savedata->inventory);
    rMemcpy(&savedata->inventoryIndices, &vs_main_inventoryIndices,
        sizeof savedata->inventoryIndices);
    rMemcpy(&savedata->spawnPoint, &vs_main_spawnPoint, sizeof savedata->spawnPoint);
    rMemcpy(&savedata->scoreData, &vs_main_scoredata, sizeof savedata->scoreData);
    rMemcpy(&savedata->containerData, &savedata2->containerData,
        sizeof savedata->containerData);
    savedata->zoneEnemyCacheIndex = vs_main_zoneEnemyCacheIndex;
    rMemcpy(savedata->zoneEnemyCache, vs_main_zoneEnemyCache,
        sizeof savedata->zoneEnemyCache);
    rMemcpy(&savedata->artsStatus, &vs_main_artsStatus, sizeof savedata->artsStatus);

    for (i = 0; i < 92; ++i) {
        var_a0 = 0;
        if (i != 1) {
            for (j = 0; j < 256; ++j) {
                var_a0 ^= mcImageBuf[i * 0x100 + j];
            }
            s5->checksums[i] = var_a0;
        }
    }
    var_a0 = 0;
    for (j = 0; j < 256; ++j) {
        var_a0 ^= mcImageBuf[j + 256];
    }
    s5->checksums[1] = var_a0;
    for (i = (long)&((vs_Savedata*)0)->info.identity.base.slotState;
        i < (int)sizeof(vs_Savedata); ++i) {
        mcImageBuf[i] += KEYSTREAM_BITS(8);
    }
}

static char loadSaveDataErrorOffset;
static UNUSED char _1[1];
static u_short fileProgressTarget;
static u_short filePreviousProgressCounter;
static u_short fileProgressPosition;
static int fileProgressCounter;

/**
 * Reads a permanent or temporary save.
 *
 * A nonzero portFileno selects the card, file and temporary-file mode; call
 * again with zero to poll the read.
 *
 * @return Zero while pending, one when the read completes, or -1 after errors.
 */
static int loadSaveData(int portFileno)
{
    enum state { init = 0, reading = 1 };

    static char state;
    static char port;
    static char file;
    static char isTempSave;
    static char errors;
    static UNUSED short _;
    static int fd;

    void* temp_s2 = (vs_Savedata*)mcImageBuf + 1;

    if (portFileno != 0) {
        state = init;
        errors = 0;
        loadSaveDataErrorOffset = 0;
        port = portFileno >> 0xC;
        isTempSave = (portFileno >> 8) & 1;
        file = portFileno & 0xF;
        fileProgressPosition = 80;
        filePreviousProgressCounter = 0;
        return 0;
    }

    switch (state) {
    case init: {
        int nBytes;
        char* filename;
        int new_var = 320;

        fileProgressPosition +=
            ((fileProgressCounter - filePreviousProgressCounter)
                * ((loadSaveDataErrorOffset * 20) - (fileProgressPosition - new_var)))
            / fileProgressTarget;
        loadSaveDataErrorOffset = errors;
        fileProgressTarget = 192 - (isTempSave << 7);
        filePreviousProgressCounter = fileProgressCounter;

        memset(temp_s2, 0, sizeof(vs_Savedata));

        if (file & 8) {
            filename = memcardMakeTempFilename(port, file & 7);
        } else {
            filename = memcardMakeFilename(port, file);
        }
        fd = open(filename, O_NOWAIT | O_RDONLY);
        if (fd == -1) {
            ++errors;
            break;
        }
        resetMemcardEvents(memcardEventsSw);
        nBytes = sizeof(vs_Savedata);
        if (isTempSave != 0) {
            nBytes = 0x2000;
        }
        if (read(fd, temp_s2, nBytes) == -1) {
            close(fd);
            ++errors;
            break;
        }
        state = reading;
    }
        // fallthrough
    case reading: {
        int event = testMemcardEvents(memcardEventsSw);
        if (event < memcardInternalEventNone) {
            close(fd);
            if (event == memcardInternalEventIoEnd) {
                return 1;
            }
            state = init;
            ++errors;
        }
        break;
    }
    }
    return errors == 3 ? -1 : 0;
}

/**
 * Saves and verifies a save file.
 *
 * A nonzero portFile selects the card and one-based destination file; call
 * again with zero to progress the write.
 *
 * @return Zero while pending, one on verified success, or -1 on failure.
 */
static int saveFile(int portFile)
{
    enum state {
        init = 0,
        tempFileCreated = 1,
        readReady = 2,
        verifyPending = 3,
        fileVerified = 4
    };

    static char state;
    static char file;
    static char port;
    static char errors;
    static char renameErrors;
    static UNUSED char _[3];
    static int fd;

    int temp_v1_2;
    int i;
    int temp_s3;

    if (portFile != 0) {
        errors = 0;
        renameErrors = 0;
        loadSaveDataErrorOffset = 0;
        port = portFile >> 0xC;
        file = portFile & 7;
        fileProgressPosition = 80;
        filePreviousProgressCounter = 0;
        state = memcardSaveIdExists(file + 'A' - 1);
        return 0;
    }
    switch (state) {
    case init:
        if (rename(memcardMakeFilename(port, file), memcardMakeTempFilename(port, file))
            != 0) {
            errors = 0;
            renameErrors = 0;
            state = tempFileCreated;
        } else {
            ++renameErrors;
            errors = renameErrors >> 4;
        }
        break;
    case tempFileCreated:
        temp_v1_2 = ((fileProgressCounter - filePreviousProgressCounter)
                        * (320 - fileProgressPosition))
                  / fileProgressTarget;
        filePreviousProgressCounter = fileProgressCounter;
        fileProgressTarget = 384;
        fileProgressPosition += temp_v1_2;
        fd = open(memcardMakeTempFilename(port, file), O_NOWAIT | O_WRONLY);
        ;
        if (fd == -1) {
            ++errors;
            break;
        }
        resetMemcardEvents(memcardEventsSw);
        if (write(fd, mcImageBuf, sizeof(vs_Savedata)) == -1) {
            close(fd);
            ++errors;
            break;
        }
        state = readReady;
        // fallthrough
    case readReady: {
        temp_s3 = testMemcardEvents(memcardEventsSw);
        if (temp_s3 < memcardInternalEventNone) {
            close(fd);
            if (temp_s3 == memcardInternalEventIoEnd) {
                state = verifyPending;
                i = fileProgressPosition;
                temp_s3 = filePreviousProgressCounter;
                loadSaveData((port << 12) | (file + 8));
                fileProgressPosition = i;
                filePreviousProgressCounter = temp_s3;
            } else {
                ++errors;
                state = tempFileCreated;
            }
        }
        break;
    }
    case verifyPending:
        temp_s3 = loadSaveData(0);
        if (temp_s3 == 0) {
            break;
        }
        if (temp_s3 < 0) {
            return -1;
        }
        for (i = 0; i < (int)sizeof(vs_Savedata); ++i) {
            if (mcImageBuf[i] != mcImageBuf[sizeof(vs_Savedata) + i]) {
                break;
            }
        }
        if (i < (int)sizeof(vs_Savedata)) {
            return -1;
        }
        state = fileVerified;
        break;
    case fileVerified:
        if (rename(memcardMakeTempFilename(port, file), memcardMakeFilename(port, file))
            == 0) {
            ++renameErrors;
            errors = (renameErrors >> 4);
            break;
        }
        return 1;
    }
    return errors == 3 ? -1 : 0;
}

/**
 * Loads memorycard support data and installs card event handlers.
 *
 * Call with nonzero init to start initialization and with zero to poll;
 * returns one when ready and zero otherwise.
 */
static int initMemcard(int init)
{
    enum state {
        none = 0,
        queueReady = 1,
        enqueued = 2,
    };

    static u_short eventSpecs[] = { EvSpIOE, EvSpERROR, EvSpTIMOUT, EvSpNEW };
    static char initMemcardState;
    static UNUSED char _[3];
    static vs_CdQueueSlot* initMemcardCdQueueSlot;

    vs_CdFile cdFile;
    int i;
    u_int event;

    if (init != 0) {
        MEMCARD_INIT_HOOK();
        mcImageBuf = vs_main_allocHeap(VS_SPMCIMG_BIN_SIZE);
        mcData = (vs_Mcdata*)(mcImageBuf + sizeof(vs_Savedata) * 3);
        // Laid out in order after vs_Mcdata: MCMAN text table, slot info, DIRENTRY
        textTable = (u_short*)(mcData + 1);
        saveSlotInfo = (vs_SaveInfoFrame*)(textTable + 0x800);
        dirEntBuf = (struct DIRENTRY*)(saveSlotInfo + 5);
        cdFile.lba = VS_SPMCIMG_BIN_LBA;
        cdFile.size = VS_SPMCIMG_BIN_SIZE;
        initMemcardCdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(initMemcardCdQueueSlot, mcImageBuf);
        initMemcardState = none;
        return 0;
    }

    switch (initMemcardState) {
    case none:
        if (initMemcardCdQueueSlot->state == CdQueueStateLoaded) {
            vs_main_freeCdQueueSlot(initMemcardCdQueueSlot);
            drawImage(vs_getXY(800, 256), mcImageBuf, vs_getWH(224, 256));
            initMemcardState = queueReady;
        }
        return 0;
    case queueReady:
        cdFile.lba = VS_MCDATA_BIN_LBA; // MCMAN.BIN must immediately follow MCDATA.BIN on
                                        // the disk
        cdFile.size = VS_MCDATA_BIN_SIZE + VS_MCMAN_BIN_SIZE;
        initMemcardCdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(initMemcardCdQueueSlot, mcData);
        initMemcardState = enqueued;
        break;
    case enqueued:
        break;
    default:
        return 0;
    }

    if (initMemcardCdQueueSlot->state == CdQueueStateLoaded) {
        vs_main_freeCdQueueSlot(initMemcardCdQueueSlot);
        vs_main_enableReset(0);
        EnterCriticalSection();

        for (i = 0; i < 8; ++i) {
            event = SwCARD;
            if (i & 4) {
                event = HwCARD;
            }
            memcardEventDescriptors[i] =
                OpenEvent(event, eventSpecs[i & 3], EvMdNOINTR, 0);
        }

        ExitCriticalSection();

        for (i = 0; i < 8; ++i) {
            EnableEvent(memcardEventDescriptors[i]);
        }
        return 1;
    }
    return 0;
}

/**
 * Disables and closes memorycard events and releases the support data.
 */
static void shutdownMemcard(void)
{
    int i;

    for (i = 0; i < 8; ++i) {
        DisableEvent(memcardEventDescriptors[i]);
    }

    EnterCriticalSection();

    for (i = 0; i < 8; ++i) {
        CloseEvent(memcardEventDescriptors[i]);
    }

    ExitCriticalSection();
    vs_main_enableReset(1);
    vs_main_freeHeap(mcImageBuf);
    MEMCARD_SHUTDOWN_HOOK();
}

static vs_FileMenuElements fileMenuElements[10];
static UNUSED char _2[8];
static vs_PrimBuf sharedPrimBuf;

/**
 * Draws a textured sprite using packed coordinates, UV/CLUT, size and tpage.
 */
static void drawSprt(int xy, int uvClut, int wh, int tpage)
{
    DrawSync(0);
    sharedPrimBuf.tag = vs_getTag(sharedPrimBuf.prim.sprt, primAddrNull);
    sharedPrimBuf.prim.sprt.tpage = vs_getTpageRaw(tpage & 0x9FF);
    sharedPrimBuf.prim.sprt.r0g0b0code =
        vs_getRGB0Raw(primSprt, ((0x80 - (tpage >> 16)) * 0x010101));
    sharedPrimBuf.prim.sprt.x0y0 = xy;
    sharedPrimBuf.prim.sprt.u0v0clut = uvClut;
    sharedPrimBuf.prim.sprt.wh = wh;
    DrawPrim(&sharedPrimBuf);
}

static char menuElementStops[] = { 0, 1, 2, 4, 8, 16, 32, 56, 80, 104, 128, 152, 176, 200,
    224, 248, 255, 255, 255, 255 };
static signed char cursorFileOpSaturation[] = { 0, -56, -112, -104, -96, -88, -80, -72,
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
static void drawSaveInfoUI(int xy, enum vs_fileMenuUiIds_e id)
{
    static int saveInfoUVClut[] = { vs_getUV0Clut(248, 8, 832, 223),
        vs_getUV0Clut(242, 0, 832, 223), vs_getUV0Clut(224, 120, 848, 223),
        vs_getUV0Clut(128, 56, 848, 223), vs_getUV0Clut(224, 112, 848, 223),
        vs_getUV0Clut(104, 56, 848, 223), vs_getUV0Clut(170, 76, 864, 223),
        vs_getUV0Clut(144, 0, 864, 223), vs_getUV0Clut(160, 0, 864, 223),
        vs_getUV0Clut(32, 9, 832, 223) };
    static int saveInfoWh[] = { vs_getXY(3, 8), vs_getXY(13, 8), vs_getXY(17, 8),
        vs_getXY(22, 8), vs_getXY(26, 8), vs_getXY(19, 8), vs_getXY(10, 10),
        vs_getXY(16, 9), vs_getXY(18, 9), vs_getXY(5, 7) };
    drawSprt(xy, saveInfoUVClut[id], saveInfoWh[id], 0xC);
}

/**
 * Draws value starting at its requested decimal place and advancing right.
 */
static void drawInteger(int xy, u_int value, u_int placeDivisor)
{
    do {
        drawSprt(xy, vs_getUV0Clut(((value / placeDivisor) * 6), 0, 832, 223),
            vs_getWH(6, 10), getTPage(0, 0, 768, 0));
        value = value % placeDivisor;
        placeDivisor /= 10;
        xy += 5;
    } while (placeDivisor != 0);
}

/**
 * Returns the number of decimal digits in a nonnegative integer.
 */
static int countDigits(int val)
{
    int i;

    i = 0;
    do {
        val /= 10;
        ++i;
    } while (val != 0);
    return i;
}

enum statType_e { statTypeHP = 0, statTypeMP = 1 };

/**
 * Draws the HP or MP label, current/max values, and proportional status bar.
 */
static void drawHPMP(int xy, enum statType_e stat, u_int currentValue, u_int maxValue)
{
    static char digitDivisors[] = { 0, 1, 10, 100 };

    int currentValueFactor;
    int maxValueDigits;
    u_int rgb1;
    u_int currentValueDigits;
    u_int rgb0;
    int wh;
    u_int placeDivisor;
    int x1y1;
    int red;
    int new_var4;

    if (maxValue != 0) {
        currentValueDigits = (((currentValue * 64) + maxValue) - 1) / maxValue;
    } else {
        currentValueDigits = 0;
    }

    rgb0 = ((207 << 16) | (224 << 8)) | 45;
    if (stat != statTypeHP) {
        rgb0 = ((159 << 16) | (120 << 8)) | 220;
    }

    red = (rgb0 & 0xFF);
    currentValueFactor = 64 - currentValueDigits;
    rgb1 =
        ((((currentValueDigits * 255) + (red * currentValueFactor)) >> 6)
            | ((((currentValueDigits * 240) + (((rgb0 >> 8) & 0xFF) * currentValueFactor))
                   >> 6)
                << 8))
        | ((((2 * (currentValueDigits * 79)) + ((rgb0 >> 16) * currentValueFactor)) >> 6)
            << 16);

    DrawSync(0);
    sharedPrimBuf.tag = vs_getTag(sharedPrimBuf.prim.tilePoly, primAddrNull);
    sharedPrimBuf.prim.tilePoly.tile.tpage =
        vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
    sharedPrimBuf.prim.tilePoly.tile.r0g0b0code = vs_getRGB0(primTile, 0, 40, 64);
    wh = vs_getWH(66, 5);
    x1y1 = (currentValueDigits + vs_getXY(0, 9));
    sharedPrimBuf.prim.tilePoly.tile.x0y0 = xy++ + vs_getXY(0, 8);
    sharedPrimBuf.prim.tilePoly.tile.wh = wh;
    sharedPrimBuf.prim.tilePoly.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4, rgb1);
    sharedPrimBuf.prim.tilePoly.polyG4.x0y0 = xy + vs_getXY(0, 9);
    sharedPrimBuf.prim.tilePoly.polyG4.r1g1b1 = rgb0;
    sharedPrimBuf.prim.tilePoly.polyG4.x1y1 = xy + x1y1;
    sharedPrimBuf.prim.tilePoly.polyG4.r2g2b2 = rgb1;
    sharedPrimBuf.prim.tilePoly.polyG4.x2y2 = xy + vs_getXY(0, 12);
    sharedPrimBuf.prim.tilePoly.polyG4.r3g3b3 = rgb0;
    sharedPrimBuf.prim.tilePoly.polyG4.x3y3 = vs_getXY(0, 12);
    sharedPrimBuf.prim.tilePoly.polyG4.x3y3 =
        xy + (currentValueDigits + sharedPrimBuf.prim.tilePoly.polyG4.x3y3);
    DrawPrim(&sharedPrimBuf);

    currentValueDigits = countDigits(currentValue);
    maxValueDigits = countDigits(maxValue);
    drawSaveInfoUI(xy - 1, stat + vs_uiids_hp);
    wh = currentValueDigits * 6;
    new_var4 = 55;
    xy = (xy - (wh - new_var4)) - (maxValueDigits * 5);
    placeDivisor = digitDivisors[currentValueDigits];
    do {
        drawSprt(xy - vs_getXY(0, 1),
            (((currentValue / placeDivisor) << 3) + 64) | (getClut(832, 223) << 16),
            vs_getWH(7, 12), getTPage(0, 0, 768, 0));
        currentValue = currentValue % placeDivisor;
        placeDivisor /= 10;
        xy += 6;
    } while (placeDivisor != 0);
    drawSaveInfoUI(xy + 1, vs_uiids_dot);
    drawInteger(xy + 6, maxValue, digitDivisors[maxValueDigits]);
}

static int selectCursorXy;
static char* memoryCardMessage;
static char isSaving;

/**
 * Draws the save / load progress bar.
 */
static void fileProcessingAnim(int x, int y)
{
    UNUSED char* new_var;
    int gradientColor1;
    int gradientColor2;
    u_int leftEdge;
    u_int i;

    leftEdge = x - 48;
    new_var = &isSaving;

    if (leftEdge < 64) {
        leftEdge = 64;
    }

    gradientColor1 = 0;
    gradientColor2 = vs_getRGB888(224, 255, 0);

    if (isSaving != 0) {
        gradientColor2 = vs_getRGB888(255, 0, 127);
    }

    for (i = 0; i < 2; ++i) {
        DrawSync(0);
        sharedPrimBuf.tag = vs_getTag(sharedPrimBuf.prim.polyG4_tpage, primAddrNull);
        sharedPrimBuf.prim.polyG4_tpage.r0g0b0code =
            vs_getRGB0Raw(primPolyG4SemiTrans, gradientColor1);
        sharedPrimBuf.prim.polyG4_tpage.x0y0 = leftEdge | y;
        sharedPrimBuf.prim.polyG4_tpage.x1y1 = x | y;
        sharedPrimBuf.prim.polyG4_tpage.x2y2 = leftEdge | (y + vs_getXY(0, 32));
        sharedPrimBuf.prim.polyG4_tpage.tpage =
            vs_getTpage(0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
        sharedPrimBuf.prim.polyG4_tpage.r1g1b1 = gradientColor2;
        sharedPrimBuf.prim.polyG4_tpage.r2g2b2 = gradientColor1;
        sharedPrimBuf.prim.polyG4_tpage.r3g3b3 = gradientColor2;
        sharedPrimBuf.prim.polyG4_tpage.x3y3 = x | (y + vs_getXY(0, 32));
        DrawPrim(&sharedPrimBuf);
        leftEdge = x;
        x += 16;
        gradientColor1 = gradientColor2;
        gradientColor2 = 0;
    }
}

/**
 * Draws the completion flash for a file operation.
 */
static void fileProcessingCompleteAnim(int colour, int y)
{
    int yOfst;
    int colour0;
    u_int i;
    int colour1 = 0;

    if (isSaving != 0) {
        colour0 = colour + (colour << 15);
    } else {
        colour0 = (colour - (colour >> 3)) + (colour << 8);
    }

    DrawSync(0);
    sharedPrimBuf.tag = vs_getTag(sharedPrimBuf.prim.tile_tpage, primAddrNull);
    sharedPrimBuf.prim.tile_tpage.tpage =
        vs_getTpage(0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
    sharedPrimBuf.prim.tile_tpage.r0g0b0code = vs_getRGB0Raw(primTileSemiTrans, colour0);
    sharedPrimBuf.prim.tile_tpage.x0y0 = y | 64;
    sharedPrimBuf.prim.tile_tpage.wh = vs_getWH(256, 32);
    DrawPrim(&sharedPrimBuf);

    for (i = 0; i < 2; ++i) {
        DrawSync(0);
        sharedPrimBuf.tag = vs_getTag(sharedPrimBuf.prim.polyG4, primAddrNull);
        yOfst = y + vs_getXY(0, -8);
        sharedPrimBuf.prim.polyG4.r0g0b0code =
            vs_getRGB0Raw(primPolyG4SemiTrans, colour1);
        sharedPrimBuf.prim.polyG4.x0y0 = yOfst | 64;
        sharedPrimBuf.prim.polyG4.r1g1b1 = colour1;
        sharedPrimBuf.prim.polyG4.x1y1 = yOfst | 320;
        sharedPrimBuf.prim.polyG4.r2g2b2 = colour0;
        sharedPrimBuf.prim.polyG4.x2y2 = y | 64;
        sharedPrimBuf.prim.polyG4.r3g3b3 = colour0;
        sharedPrimBuf.prim.polyG4.x3y3 = y | 320;
        DrawPrim(&sharedPrimBuf);
        y += vs_getXY(0, 40);
        colour1 = colour0;
        colour0 = 0;
    }
}

static u_char selectCursorColor;
static char fileMenuScreenFade;

/**
 * Resets menu elements, progress, fade, cursor and message state.
 */
static void initFileMenu(void)
{
    memoryCardMessage = NULL;
    selectCursorColor = 0;
    selectCursorXy = 0;
    fileProgressCounter = 0;
    fileMenuScreenFade = 0;
    fileProgressTarget = 384;
    memset(fileMenuElements, 0, sizeof fileMenuElements);
}

/**
 * Initializes an element and performs some text preprocessing.
 *
 * @return The initialized element in the shared file-menu element array.
 */
static vs_FileMenuElements* initFileMenuElement(int id, int xy, int wh, char* text)
{
    vs_FileMenuElements* element;
    int i;
    u_int c;

    element = &fileMenuElements[id];
    memset(element, 0, sizeof *element);
    element->state = 1;
    element->slotId = -1;
    *(int*)&element->x = xy;
    *(int*)&element->w = wh;

    if (text != NULL) {
        for (i = 0; i < 32;) {
            c = *text++;
            if (c == vs_char_spacing) {
                element->text[i++] = c;
                do {
                    c = *(text++);
                } while (0);
            } else {
                if (c == vs_char_terminator) {
                    element->text[i] = vs_char_printString;
                    return element;
                }
                if (c >= vs_char_nonPrinting) {
                    continue;
                }
            }
            element->text[i++] = c;
        }
    } else {
        element->text[0] = vs_char_printString;
    }
    return element;
}

/**
 * Clears one element in menu element array.
 */
static void clearFileMenuElement(int id)
{
    memset(&fileMenuElements[id], 0, sizeof fileMenuElements[id]);
}

/**
 * Reports whether all file-menu elements have finished their animations.
 */
static int fileMenuElementsActive(void)
{
    int i;

    for (i = 0; i < 10 && fileMenuElements[i].state < fileMenuElementStateAnimateX; ++i)
        ;
    return i == 10;
}

/**
 * Draws a glyph (or applies a spacing control) and returns the next x position.
 */
static int printCharacter(u_int c, int x, int y, int clut)
{
    static int glyphWidths[] = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 12, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 12, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 8, 5, 7, 8, 7, 7, 7, 6, 6, 6, 7, 7, 7, 9,
        7, 7, 7, 7, 6, 7, 7, 6, 8, 7, 8, 8, 9, 8, 8, 4, 7, 5, 7, 7, 6, 8, 7, 7, 7, 6, 8,
        6, 8, 8, 7, 6, 7, 6, 8, 8, 7, 7, 8, 7, 5, 6, 7, 6, 7, 7, 7, 8, 12, 7, 7, 7, 7, 7,
        7, 7, 7, 7, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 12, 7, 7, 7, 7, 7, 8, 8, 8, 8,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 6, 12, 12, 12, 12,
        12, 12, 8, 12, 6, 5, 4, 12, 12, 12, 12, 4, 6, 6, 12, 12, 6, 6, 3, 3, 3, 4, 6, 12,
        6, 6, 6, 12, 5, 6, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12 };

    if ((c >> 8) == 14) {
        return x + (char)c;
    }
    if (c != vs_char_space) {
        DrawSync(0);
        sharedPrimBuf.tag = vs_getTag(sharedPrimBuf.prim.sprt, primAddrNull);
        sharedPrimBuf.prim.sprt.tpage =
            vs_getTpage(832, 0, clut4Bit, semiTransparencyFull, ditheringOff);
        sharedPrimBuf.prim.sprt.r0g0b0code = vs_getRGB0(primSprtSemtTrans, 128, 128, 128);
        sharedPrimBuf.prim.sprt.x0y0 = (u_short)x | y << 16;
        sharedPrimBuf.prim.sprt.wh = vs_getWH(12, 12);
        sharedPrimBuf.prim.sprt.u0v0clut =
            vs_getUV0Clut((c % 21) * 12, (c / 21) * 12, clut * 16 + 896, 222);
        DrawPrim(&sharedPrimBuf);
    }
    return x + glyphWidths[c];
}

enum findCurrentSave_e {
    findSaveTimeout = -2,
    findSaveNotFound = -1,
    findSavePending = 0
};

/**
 * Searches both cards asynchronously for the save matching current settings.
 *
 * A nonzero init restarts the search; subsequent calls return the current state.
 */
static int findCurrentSave(int init)
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
        FIND_SAVE_ACCESSING_HOOK(
            (char*)(textTable + textTable[VS_MCMAN_BIN_INDEX_accessing0 - 1 + port]));
        memoryCardMessage =
            (char*)(textTable + textTable[VS_MCMAN_BIN_INDEX_accessing0 - 1 + port]);
        memcardEventHandler(realPort + 1);
        ++state;
    } else {
        event = memcardEventHandler(0) & 3;

        if (event != memcardEventPending) {
            if (event == memcardEventIoEnd) {
                if (initSaveFileInfo(realPort + 1) == 0) {
                    currentSave = findCurrentSaveOnActiveMemcard();
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

enum memcardEventMask_e {
    memcardEventMaskIgnoreNoEvent = 0x30,
    memcardEventMaskAll = 0x70
};

enum memcardMaskedHandler_e {
    memcardMaskedHandlerError = -1,
    memcardMaskedHandlerPending = 0,
    memcardMaskedHandlerComplete = 1
};

/**
 * Starts or polls a card operation, mapping its result through a stored mask.
 *
 * A nonzero portMask starts polling; zero advances the operation.
 */
static enum memcardMaskedHandler_e memcardMaskedHandler(int portMask)
{
    static char mask;
    static UNUSED char _[MEMCARD_MASKED_HANDLER_PAD];

    int event;

    if (portMask != 0) {
        memcardEventHandler(portMask & 3);
        mask = (portMask >> 4);
        return memcardMaskedHandlerPending;
    }
    event = memcardEventHandler(0);
    if (event != memcardEventPending) {
        switch (event & mask) {
        case memcardEventIoEnd:
            return memcardMaskedHandlerComplete;
        case memcardEventTimeout:
            memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_insertError);
            break;
        case memcardEventUnformatted:
            memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_noData);
            break;
        default:
            memoryCardMessage = (char*)(textTable + VS_MCMAN_BIN_OFFSET_removed);
            break;
        }
        return memcardMaskedHandlerError;
    }
    return memcardMaskedHandlerPending;
}

/**
 * Prints a vs-encoded string.
 */
static void printString(char* text, int x, int y, int clut)
{
    static char arrowState = 0;

    char tempArrowState;
    u_int c;
    int startX = x;
    int nextX = x;

    while (1) {
        c = *text++;
        if (c < vs_char_control) {
            if (c < vs_char_nonPrinting) {
                nextX = printCharacter(c, nextX, y, clut);
            } else if (c == vs_char_confirm) {
                tempArrowState = (arrowState + 1) % 12;
                c = vs_char_arrow - (tempArrowState >> 2);
                arrowState = tempArrowState;
                nextX = printCharacter(c, nextX, y, clut);
            } else if (c != vs_char_terminator) {
                if (c == vs_char_newline) {
                    y += 13;
                    nextX = startX;
                }
            } else {
                break;
            }
        } else {
            u_int control = *text++;
            if (c == vs_char_spacing) {
                if (control >= 0xF0) {
                    nextX -= 256 - control;
                } else {
                    nextX += control;
                }
            }
        }
    }
}

/**
 * Linearly blends RGB channels; factor ranges from zero to eight.
 */
static u_int interpolateRGB(u_int colour1, u_int colour2, u_int factor)
{
    int component;
    u_int i;
    u_int colourOut;

    colourOut = 0;
    for (i = 0; i < 3; ++i) {
        component = ((colour1 >> 16) & 0xFF) * (8 - factor);
        colour1 <<= 8;
        colourOut =
            (colourOut << 8) + ((component + (((colour2 >> 16) & 0xFF) * factor)) >> 3);
        colour2 <<= 8;
    }
    return colourOut;
}

/**
 * Selects and blends the background colours for the two animation factors.
 */
static u_int intepolateMenuItemBgColour(u_int outerFactor, u_int innerFactor)
{
    static int colors1[] = { vs_getRGB888(0x40, 0x30, 0x66),
        vs_getRGB888(0x40, 0x38, 0x20) };
    static int colors2[] = {
        vs_getRGB888(0x08, 0x08, 0x20),
        vs_getRGB888(0x10, 0x10, 0x08),
    };

    u_int color1;
    u_int color2;

    if (innerFactor < 9) {
        color1 = interpolateRGB(
            vs_getRGB888(0, 65, 107), vs_getRGB888(25, 130, 108), innerFactor);
        color2 =
            interpolateRGB(vs_getRGB888(0, 5, 51), vs_getRGB888(1, 40, 38), innerFactor);
    } else {
        color1 = colors1[((innerFactor >> 3) - 2)];
        color2 = colors2[((innerFactor >> 3) - 2)];
    }
    return interpolateRGB(color1, color2, outerFactor);
}

/**
 * Draws a menu element and updates its animation state.
 */
static void drawFileMenuElement(vs_FileMenuElements* element)
{
    u_long clut[130];
    vs_SaveInfoFrame* saveInfo;
    int xy;
    int var_a3;
    int location;
    int x;
    int y;
    int var1;
    int var2;
    int uvClut;
    int slotState;
    u_short* locationClut;
    int new_var;

    if (element->selected != 0) {
        element->outertextBlendFactor = 8;
    } else if (element->outertextBlendFactor != 0) {
        --element->outertextBlendFactor;
    }
    if (element->slotUnavailable != 0) {
        element->outertextBlendFactor = 0;
    }
    if ((element->slotId >= 5) || ((element->y - 72) < 0x51U)) {
        y = element->innertextBlendFactor;
        var1 = intepolateMenuItemBgColour(8 - element->outertextBlendFactor, y);
        var2 = intepolateMenuItemBgColour(element->outertextBlendFactor, y);
        if (y & 7) {
            element->innertextBlendFactor = y + 1;
        }
        y = element->y << 16;

        DrawSync(0);
        sharedPrimBuf.tag = vs_getTag(sharedPrimBuf.prim.tilePoly, primAddrNull);
        sharedPrimBuf.prim.tilePoly.tile.tpage =
            vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
        sharedPrimBuf.prim.tilePoly.tile.r0g0b0code = vs_getRGB0(primTile, 0, 0, 0);
        sharedPrimBuf.prim.tilePoly.tile.x0y0 =
            ((element->x + 2) & 0xFFFF) | (element->y + 2) << 16;
        sharedPrimBuf.prim.tilePoly.tile.wh = element->w | (element->h << 0x10);
        sharedPrimBuf.prim.tilePoly.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4, var1);
        sharedPrimBuf.prim.tilePoly.polyG4.x0y0 = (u_short)element->x | y;
        sharedPrimBuf.prim.tilePoly.polyG4.r1g1b1 = var2;
        sharedPrimBuf.prim.tilePoly.polyG4.x1y1 =
            ((element->x + element->w) & 0xFFFF) | y;
        sharedPrimBuf.prim.tilePoly.polyG4.r2g2b2 = var1;
        sharedPrimBuf.prim.tilePoly.polyG4.x2y2 =
            (u_short)element->x | ((element->y + element->h) << 0x10);
        sharedPrimBuf.prim.tilePoly.polyG4.r3g3b3 = var2;
        sharedPrimBuf.prim.tilePoly.polyG4.x3y3 =
            ((element->x + element->w) & 0xFFFF) | ((element->y + element->h) << 0x10);
        DrawPrim(&sharedPrimBuf);

        x = element->x + 6;
        for (var1 = 0; var1 < 32; ++var1) {
            var2 = element->text[var1];
            if (var2 == vs_char_spacing) {
                x += element->text[++var1];
            } else if (var2 != 0xFF) {
                x = printCharacter(var2, x, element->y, 0);
            } else {
                break;
            }
        }
        var2 = element->slotId;
        if (var2 < 5) {
            readImage(vs_getXY(768, 227), clut, vs_getWH(256, 1));
            saveInfo = &saveSlotInfo[var2];
            location = element->saveLocation - 1;
            var1 = saveInfo->identity.base.slotState;
            if (saveInfo->identity.base.slotState < 3) {
                if (saveInfo->identity.base.slotState == 0) {
                    location = -2;
                } else if (saveInfo->identity.base.slotState == 2) {
                    location = -4;
                } else if (isSaving != 0) {
                    location = -1;
                } else {
                    location = -5;
                }
            } else if (location >= 48) {
                location = -3;
            }
            if (location >= 32u) {
                locationClut = mcData->locationCluts[1];
            } else {
                locationClut = mcData->locationCluts[0];
            }
            drawImage(vs_getXY(768, 227), locationClut, vs_getWH(256, 1));
            if (location < 0) {
                uvClut = (~location << 13) | vs_getUV0Clut(64, 0, 768, 227);
                xy = (element->x - 64) | y;
                drawSprt(xy, uvClut, vs_getWH(64, 32),
                    ((8 - element->outertextBlendFactor) << 19) | 0x9C);
            } else {
                int v0;
                uvClut = ((location & 8) * 8) | ((location & 7) << 0xD)
                       | vs_getUV0Clut(0, 0, 768, 227);
                xy = (element->x - 64) | y;
                new_var = (((location & 0x30) * 4) + 832) & 0x3FF;
                v0 = new_var >> 6;
                var_a3 = (((8 - element->outertextBlendFactor) << 19) | 0x90);
                drawSprt(xy, uvClut, vs_getWH(64, 32), v0 | var_a3);
            }
            drawImage(vs_getXY(768, 227), clut, vs_getWH(256, 1));
            drawSaveInfoUI((element->x - 22) | y, vs_uiids_number);
            drawInteger((element->x - 9) | y, var2 + 1, 0xAU);
            slotState = saveInfo->identity.base.slotState;
            if (slotState == slotStateUnavailable) {
                printString((char*)(textTable + VS_MCMAN_BIN_OFFSET_inUse),
                    element->x + 6, element->y + 10, 3);
            } else if (slotState == slotStateAvailable) {
                if (isSaving == 0) {
                    printString((char*)(textTable + VS_MCMAN_BIN_OFFSET_empty),
                        element->x + 6, element->y + 10, 3);
                } else {
                    printString((char*)(textTable + VS_MCMAN_BIN_OFFSET_new),
                        element->x + 6, element->y + 10, 0);
                }
            } else {
                y += 4 << 16;
                printString(
                    (char*)&textTable[textTable[element->saveLocation
                                                + VS_MCMAN_BIN_INDEX_saveLocations]],
                    element->x + 6, element->y + 4, 0);
                drawSaveInfoUI(y | 172, vs_uiids_map);
                drawSaveInfoUI(y | 189, vs_uiids_colon);
                var1 = saveInfo->stats.mapCompletion;

                if (var1 == 100) {
                    drawInteger(y | 192, 100, 100);
                    drawSaveInfoUI((y + 0xFFFF0000) | 207, vs_uiids_percent);
                } else {
                    drawInteger(y | 192, var1, 10);
                    drawSaveInfoUI((y + 0xFFFF0000) | 202, vs_uiids_percent);
                }
                drawSaveInfoUI(y | 217, vs_uiids_save);
                drawSaveInfoUI(y | 239, vs_uiids_colon);
                drawInteger(y | 242, saveInfo->stats.cumulativeSaveCount, 1000);
                drawSaveInfoUI(y | 267, vs_uiids_clear);
                drawSaveInfoUI(y | 293, vs_uiids_colon);
                drawInteger(y | 296, saveInfo->stats.clearCount, 10);
                y += 13 << 16;
                if (saveInfo->stats.clearCount != 0) {
                    drawSprt(y | 69, vs_getUV0Clut(240, 16, 912, 223), vs_getWH(16, 16),
                        getTPage(clut4Bit, semiTransparencyHalf, 768, 0));
                }
                drawSaveInfoUI(y | 240, vs_uiids_time);
                var1 = saveInfo->stats.gameTime.t.h;
                if (var1 == 100) {
                    drawInteger(y | 263, var1, 100);
                } else {
                    drawInteger(y | 268, var1, 10);
                }
                drawSaveInfoUI(y | 279, vs_uiids_colon);
                drawInteger(y | 282, saveInfo->stats.gameTime.t.m, 10);
                drawSaveInfoUI(y | 293, vs_uiids_colon);
                drawInteger(y | 296, saveInfo->stats.gameTime.t.s, 10);
                drawHPMP(
                    y | 88, statTypeHP, saveInfo->stats.currentHP, saveInfo->stats.maxHP);
                drawHPMP(y | 158, statTypeMP, saveInfo->stats.currentMP,
                    saveInfo->stats.maxMP);
                y -= 17 << 16;
            }
            if ((element->selected != 0) && (fileProgressCounter != 0)) {
                if (fileProgressCounter < 0) {
                    signed char* p = (cursorFileOpSaturation + fileProgressCounter++);
                    fileProcessingCompleteAnim(-p[17], y);
                } else {
                    int new_var3 = 0x140;
                    fileProcessingAnim(
                        fileProgressPosition
                            + (((fileProgressCounter - filePreviousProgressCounter)
                                   * ((loadSaveDataErrorOffset * 0x14)
                                       - (fileProgressPosition - new_var3)))
                                / fileProgressTarget),
                        y);
                }
            }
        }
    }
}

/**
 * Draws the menu elements, message area, cursor and fade.
 */
static void drawFileMenu(int framebuf)
{
    int _[2];
    vs_FileMenuElements* element;
    int j;
    int i;
    u_int x;
    int state;
    int new_var;

    element = fileMenuElements;
    x = 0;
    if (framebuf != 0) {
        x = 320;
    }
    drawSprt(vs_getXY(256, 176), vs_getUV0Clut(0, 176, 768, 227), vs_getWH(64, 64),
        getTPage(clut8Bit, semiTransparencyHalf, 768, 256));
    drawSprt(vs_getXY(0, 176), vs_getUV0Clut(0, 176, 768, 227), vs_getWH(256, 64),
        getTPage(clut8Bit, semiTransparencyHalf, 640, 256));

    for (i = 0; i < 10; ++i, ++element) {
        state = element->state;
        if (state == fileMenuElementStateAnimateX) {
            if (element->x < element->targetPosition) {
                element->x += 32;
                if (element->x >= element->targetPosition) {
                    element->x = element->targetPosition;
                    element->state = fileMenuElementStateStatic;
                }
            } else {

                for (j = 1; j < 16; ++j) {
                    if ((element->targetPosition + menuElementStops[j]) >= element->x) {
                        break;
                    }
                }
                element->x = element->targetPosition + menuElementStops[j - 1];
                if (element->w < (320 - element->x)) {
                    element->w = 320 - element->x;
                }
                if (element->x == element->targetPosition) {
                    element->state = fileMenuElementStateStatic;
                }
            }
        }
        if (state == fileMenuElementStateAnimateY) {
            if (element->y > element->targetPosition) {
                for (j = 1; j < 16; ++j) {
                    if ((element->targetPosition + menuElementStops[j]) >= element->y) {
                        break;
                    }
                }
                element->y = (element->targetPosition + menuElementStops[j - 1]);
            }
            if (element->y == element->targetPosition) {
                element->state = fileMenuElementStateStatic;
            }
        }
        if (state == fileMenuElementStateAnimateNegX) {
            if (element->x < element->targetPosition) {
                for (j = 1; j < 16; ++j) {
                    if (element->x >= -menuElementStops[j]) {
                        break;
                    }
                }
                element->x = -menuElementStops[j - 1];
                if (element->x == 0) {
                    element->state = fileMenuElementStateStatic;
                }
            } else {
                element->x = element->x - 32;
                if (element->targetPosition >= element->x) {
                    element->x = element->targetPosition;
                    element->state = fileMenuElementStateStatic;
                }
            }
        }
        if (state != fileMenuElementStateInactive) {
            drawFileMenuElement(element);
        }
    }

    for (i = 1; i < 4; ++i) {
        new_var = 256;
        drawSprt(vs_getXY(0, 187 - i), (187 - i) << 8, vs_getWH(256, 1),
            (x >> 6) | (((4 - i) << 21) | new_var));
        drawSprt(vs_getXY(256, 187 - i), (187 - i) << 8, vs_getWH(64, 1),
            (((int)(x + new_var)) >> 6) | (((4 - i) << 21) | new_var));
    }
    drawSprt(vs_getXY(10, 181), vs_getUV0Clut(64, 145, 848, 223), vs_getWH(33, 7),
        getTPage(clut4Bit, semiTransparencyHalf, 768, 0)); // "Caution"
    DrawSync(0);
    sharedPrimBuf.tag = vs_getTag(sharedPrimBuf.prim.tile, primAddrNull);
    sharedPrimBuf.prim.tile.r0g0b0code = vs_getRGB0(primTile, 0, 0, 0);
    sharedPrimBuf.prim.tile.x0y0 = vs_getXY(0, 187);
    sharedPrimBuf.prim.tile.wh = vs_getWH(320, 52);
    DrawPrim(&sharedPrimBuf); // Message dialog background
    if (selectCursorXy != 0) {
        drawSprt(selectCursorXy, vs_getUV0Clut(32, 48, 896, 223), vs_getWH(16, 16),
            (cursorFileOpSaturation[selectCursorColor] << 16)
                | getTPage(clut4Bit, semiTransparencyHalf, 768, 0));
        selectCursorColor = (selectCursorColor + 1) & 0xF;
        if (vs_main_buttonsPressed.all & PADRup) {
            vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
        }
    } else {
        selectCursorColor = 0;
    }
    if (memoryCardMessage != NULL) {
        printString(memoryCardMessage, 16, 192, 0);
    }
    if (fileMenuScreenFade != 0) {
        DrawSync(0);
        sharedPrimBuf.tag = vs_getTag(sharedPrimBuf.prim.tile_tpage, primAddrNull);
        sharedPrimBuf.prim.tile_tpage.tpage =
            vs_getTpage(0, 0, direct16Bit, semiTransparencySubtract, ditheringOff);
        sharedPrimBuf.prim.tile_tpage.x0y0 = vs_getXY(0, 0);
        sharedPrimBuf.prim.tile_tpage.wh = vs_getWH(320, 224);
        sharedPrimBuf.prim.tile_tpage.r0g0b0code =
            vs_getRGB0Raw(primTileSemiTrans, fileMenuScreenFade * vs_getRGB888(8, 8, 8));
        DrawPrim(&sharedPrimBuf);
    }
}

/**
 * Draws the static background texture for the file menu.
 */
static void drawFileMenuBg(void)
{
    drawSprt(vs_getXY(256, 0), vs_getUV0Clut(0, 0, 768, 227), vs_getWH(64, 176),
        getTPage(clut8Bit, semiTransparencyHalf, 768, 256));
    drawSprt(vs_getXY(0, 0), vs_getUV0Clut(0, 0, 768, 227), vs_getWH(256, 176),
        getTPage(clut8Bit, semiTransparencyHalf, 640, 256));
}
