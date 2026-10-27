#pragma once

/* Memorycard save/load support shared by the title and menu overlays. The including
 * file defines _memcardFilenameTemplate first. */

#include "src/SLUS_010.40/saveData.h"

static long _memcardEventDescriptors[8];

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
static enum testMemcardEvents_e _testMemcardEvents(enum memcardEvents_e type)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if (TestEvent(_memcardEventDescriptors[i + type]) == 1) {
            return i;
        }
    }
    return i;
}

/**
 * Tests each event in the selected memorycard event group to clear its signal.
 */
static void _resetMemcardEvents(enum memcardEvents_e type)
{
    int i;

    for (i = 0; i < 4; ++i) {
        TestEvent(_memcardEventDescriptors[i + type]);
    }
}

/**
 * Uploads an image to VRAM and waits for the transfer to finish.
 */
static void _drawImage(int xy, void* buffer, int wh)
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
static void _readImage(int xy, void* buffer, int wh)
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
static void _rMemcpy(void* dst, void const* src, int count)
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
static char* _memcardMakeFilename(int port, int fileNo)
{
    static char filename[32];

    memset(filename, 0, ' ');
    strcpy(filename, _memcardFilenameTemplate);
    filename[2] = port == 0 ? '0' : '1';
    filename[20] = fileNo + '0';
    return filename;
}

/**
 * Builds the temporary save filename in a reusable static buffer.
 *
 * @param port Zero selects memorycard port 1; any other value selects port 2.
 */
static char* _memcardMakeTempFilename(int port, int fileNo)
{
    static char filename[32];

    memset(filename, 0, ' ');
    strcpy(filename, _memcardFilenameTemplate);
    filename[2] = port == 0 ? '0' : '1';
    filename[20] = fileNo + 'A' - 1;
    return filename;
}

static char* _spmcimg;
static mcdata_t* _mcData;
static u_short* _textTable;
static char _0[4] __attribute__((unused));
static struct DIRENTRY* _memcardFiles[15];
static struct DIRENTRY* _dirEntBuf;
/* Memorycard save helpers shared by the title and menu overlays. The including file
 * defines _memcardFilenameTemplate first. */

static saveFileInfo_t* _saveFileInfo;

/**
 * Finds the save slot with the greatest generation number.
 *
 * @return Zero-based slot index; returns zero when no active slot is found.
 */
static u_int _getNewestSaveFile(void)
{
    u_int i;
    u_int maxCounter = 0;
    u_int fileIndex = 0;

    for (i = 0; i < 5; ++i) {
        if (_saveFileInfo[i].unk4.base.slotState >= 3) {
            if (maxCounter < _saveFileInfo[i].unk4.base.generation) {
                maxCounter = _saveFileInfo[i].unk4.base.generation;
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
static int _findCurrentSaveOnActiveMemcard(void)
{
    int i;
    for (i = 0; i < 5; ++i) {
        if ((_saveFileInfo[i].unk4.base.slotState >= slotStateInUse)
            && (_saveFileInfo[i].unk4.base.slotState == vs_main_settings.slotState)
            && (_saveFileInfo[i].key == vs_main_settings.key)
            && (_saveFileInfo[i].unk4.stats.cumulativeSaveCount
                == vs_main_settings.cumulativeSaveCount)
            && (_saveFileInfo[i].unk4.base.generation
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
static int _memcardFileNumberFromFilename(char* filename)
{
    int i;
    char const* gameCode = &_memcardFilenameTemplate[5];

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
static int _verifySaveChecksums(savedata_t data[], int sectorCount)
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

            if (data->unk180.checksums[i] != checksum) {
                return 1;
            }
        }
        p += 256;
    }

    p = data->unk100;
    checksum = 0;
    for (j = 0; j < 256; ++j) {
        checksum ^= p[j];
    }

    return checksum != 0;
}

/**
 * Decodes count bytes in place using the save format's key-driven byte stream.
 */
static void _decode(u_int key, void* buf, int count)
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
static int _readSaveFileInfo(int id)
{
    saveFileInfo_t saveInfo[4];
    int i;
    int port = id >> 12;

    id &= 7;

    for (i = 0; i < 3; ++i) {
        int bytesRead;
        int file = open(_memcardMakeFilename(port, id), O_RDONLY);

        if (file == -1) {
            continue;
        }
        bytesRead = read(file, saveInfo, sizeof saveInfo);
        close(file);
        if (bytesRead != sizeof saveInfo) {
            continue;
        }
        _decode(saveInfo[3].key, &saveInfo[3].unk4.base.slotState,
            sizeof saveInfo[3] - sizeof(int));
        if (_verifySaveChecksums((savedata_t*)saveInfo, 2) == 0) {
            _rMemcpy(&_saveFileInfo[id - 1], &saveInfo[3], sizeof saveInfo[3]);
            return 0;
        }
    }

    memset(&_saveFileInfo[id - 1], 0, sizeof _saveFileInfo[id - 1]);
    return 1;
}

/**
 * Checks whether a recognized memorycard save filename ends in id.
 */
static int _memcardSaveIdExists(int id)
{
    int i;

    for (i = 0; i < 15; ++i) {
        char* filename = _memcardFiles[i]->name;
        if ((filename != NULL) && (_memcardFileNumberFromFilename(filename) != 0)
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
static int _deleteRedundantTempFiles(int port)
{
    int i;
    int ret = 0;

    for (i = 0; i < 5; ++i) {
        if ((_memcardSaveIdExists(i + '1') != 0)
            && (_memcardSaveIdExists(i + 'A') != 0)) {
            if (erase(_memcardMakeTempFilename(port, i + 1)) == 0) {
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
static int _initSaveFileInfo(int port)
{
    long fileNo;
    int i;
    int tempFilesDeleted;
    int slotsAvailable = 15;

    for (i = 14; i >= 0; --i) {
        _memcardFiles[i] = NULL;
    }

    fileNo = (long)firstfile((port == 1) ? ("bu00:*") : ("bu10:*"), _dirEntBuf);
    _memcardFiles[0] = (void*)fileNo;

    for (i = 1; (i < 15) && fileNo; ++i) {
        fileNo = (long)nextfile(_dirEntBuf + i);
        _memcardFiles[i] = (void*)fileNo;
    }

    memset(_saveFileInfo, 0, sizeof *_saveFileInfo * 5);
    tempFilesDeleted = _deleteRedundantTempFiles((port - 1) * 16);
    if (tempFilesDeleted & 0x80) {
        return 1;
    }
    for (i = 0; i < 15; ++i) {
        struct DIRENTRY* file = _memcardFiles[i];

        if (file == NULL) {
            continue;
        }
        fileNo = _memcardFileNumberFromFilename(file->name);
        if (fileNo != 0) {
            if (fileNo < 0) {
                fileNo = -fileNo;
                if ((tempFilesDeleted >> (fileNo - 1)) & 1) {
                    continue;
                }
                memset(&_saveFileInfo[fileNo - 1], 0, sizeof _saveFileInfo[fileNo - 1]);
                _saveFileInfo[fileNo - 1].unk4.base.slotState = slotStateTemporary;
            } else if (_readSaveFileInfo(((port - 1) << 16) | fileNo) != 0) {
                slotsAvailable += (file->size + 0x1FFF) >> 13;
            }
        }
        slotsAvailable -= (file->size + 0x1FFF) >> 13;
    }

    for (; slotsAvailable >= 3; slotsAvailable -= 3) {
        for (i = 0; i < 5; ++i) {
            if (_saveFileInfo[i].unk4.base.slotState == slotStateUnavailable) {
                _saveFileInfo[i].unk4.base.slotState = slotStateAvailable;
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
static int _createSaveFile(int port, int id)
{
    long file;
    char* fileName = _memcardMakeFilename((port - 1) * 16, id);

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
static enum memcardEventHandler_e _memcardEventHandler(int initPort)
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
        _resetMemcardEvents(memcardEventsSw);
        if (_card_info(port) == 0) {
            break;
        }
        state = ready;
        timeout = 0;
        eventType = memcardEventsSw;
        // fallthrough
    case ready:
        switch (_testMemcardEvents(memcardEventsSw)) {
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
        _resetMemcardEvents(memcardEventsHw);
        if (_card_clear(port) == 0) {
            break;
        }
        state = confirmed;
        timeout = 0;
        eventType = memcardEventsHw;
        // fallthrough
    case confirmed:
        do {
            event = _testMemcardEvents(memcardEventsHw);
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
        _resetMemcardEvents(memcardEventsSw);
        if (_card_load(port) == 0) {
            break;
        }
        state = loaded;
        timeout = 0;
        // fallthrough
    case loaded:
        event = _testMemcardEvents(memcardEventsSw);
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
static int _applyLoadedSaveFile(int verifyOnly)
{
    int blockCount;
    savedata_t* spmcimg = (savedata_t*)_spmcimg;
    void* spmcimg2 = spmcimg + 1;
    savedata_t* s4 = spmcimg + 1;
    savedata_unk180_2_t* unk180 = &spmcimg[1].unk180.unk180;

    _decode(unk180->key, &unk180->base.slotState,
        sizeof(savedata_t) - (u_long) & ((savedata_t*)0)->unk180.unk180.base.slotState);

    blockCount = 92;
    if (verifyOnly != 0) {
        blockCount = 32;
    }

    if ((_verifySaveChecksums(spmcimg + 1, blockCount) != 0)
        || (unk180->base.unk8 != 0x20000107)) {
        do {
            return 1;
        } while (0);
    }

    if (verifyOnly == 0) {
        return 0;
    }

    _rMemcpy(&vs_main_stateFlags, spmcimg[1].stateFlags, sizeof vs_main_stateFlags);
    _rMemcpy(
        vs_main_actionsLearned, spmcimg[1].actionsLearned, sizeof vs_main_actionsLearned);
    _rMemcpy(&vs_main_mapStatus, spmcimg[1].mapStatus, sizeof vs_main_mapStatus);
    _rMemcpy(&vs_main_settings, &spmcimg[1].settings, sizeof vs_main_settings);
    _rMemcpy(&D_80060068, &spmcimg[1].unk6C8, sizeof D_80060068);
    _rMemcpy(&vs_main_inventory, &spmcimg[1].inventory, sizeof vs_main_inventory);
    _rMemcpy(
        &vs_main_inventoryIndices, &spmcimg[1].unk16C8, sizeof vs_main_inventoryIndices);
    _rMemcpy(&D_80061068, &spmcimg[1].unk1778, sizeof D_80061068);
    _rMemcpy(&vs_main_scoredata, &spmcimg[1].scoreData, sizeof vs_main_scoredata);
    D_80060064 = s4->unk1898;
    _rMemcpy(D_80061078, spmcimg[1].unk189C, sizeof D_80061078);
    spmcimg2 = &vs_main_artsStatus;
    _rMemcpy(&vs_main_artsStatus, &spmcimg[1].artsStatus, sizeof vs_main_artsStatus);
    vs_main_gametime.t = spmcimg[1].unk180.stats.gameTime.t;
    func_80042CA0();
    vs_main_setMonoSound(vs_main_settings.monoSound);
    return 0;
}
