#include "22C.h"
#include "../SLUS_010.40/main.h"
#include "../SLUS_010.40/sfx.h"
#include "gpu.h"
#include "lbas.h"
#include "vs_string.h"
#include "../../assets/MENU/MCMAN.BIN.h"
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

static u_int _encode(int value)
{
    static u_int _encodeSeed = 0x19660D;
    u_int seed = _encodeSeed;

    _encodeSeed = seed * 0x19660D;
    return seed >> (32 - value);
}

static long _memcardEventDescriptors[8];

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

static void _resetMemcardEvents(enum memcardEvents_e type)
{
    int i;

    for (i = 0; i < 4; ++i) {
        TestEvent(_memcardEventDescriptors[i + type]);
    }
}

static void _drawImage(int xy, void* buffer, int wh)
{
    RECT rect;

    *(int*)&rect.x = xy;
    *(int*)&rect.w = wh;
    LoadImage(&rect, buffer);
    DrawSync(0);
}

static void _readImage(int xy, void* buffer, int wh)
{
    RECT rect;

    *(int*)&rect.x = xy;
    *(int*)&rect.w = wh;
    StoreImage(&rect, buffer);
    DrawSync(0);
}

static void _rMemcpy(void* dst, void const* src, int count)
{
    do {
        --count;
        ((char*)dst)[count] = ((char const*)src)[count];
    } while (count != 0);
}

static char* _memcardMakeFilename(int port, int fileNo)
{
    static char filename[32];

    memset(filename, 0, ' ');
    strcpy(filename, _memcardFilenameTemplate);
    filename[2] = port == 0 ? '0' : '1';
    filename[20] = fileNo + '0';
    return filename;
}

static char* _memcardMakeTempFilename(int port, int fileNo)
{
    static char filename[32];

    memset(filename, 0, ' ');
    strcpy(filename, _memcardFilenameTemplate);
    filename[2] = port == 0 ? '0' : '1';
    filename[20] = fileNo + 'A' - 1;
    return filename;
}

enum slotState_e {
    slotStateUnavailable = 0,
    slotStateAvailable = 1,
    slotStateTemporary = 2,
    slotStateInUse = 3
};

typedef struct {
    enum slotState_e slotState;
    u_int generation;
    int unk8;
} saveBase_t;

typedef struct {
    vs_Gametime_t gameTime;
    u_short saveCount;
    u_short unk12;
    u_short currentHP;
    u_short maxHP;
    char saveLocation;
    char clearCount;
    char mapCompletion;
    char unk1B;
    u_short currentMP;
    u_short maxMP;
} stats_t;

typedef struct {
    saveBase_t base;
    stats_t stats;
    u_short unk20[16];
} saveFileSubInfo_t;

typedef struct {
    u_int key;
    saveFileSubInfo_t unk4;
    char unk44[0x1C];
    char unk60[0x20];
} saveFileInfo_t;

typedef struct {
    u_long locationCluts[2][128];
    char unk400[7][32];
    char unk4E0[22][128];
    char unkFE0[0x20];
    u_short textTable[0x800];
    saveFileInfo_t saveFileInfo[5];
    struct DIRENTRY _dirEntBuf;
} mcdata_t;

static char* _spmcimg;
static mcdata_t* _mcData;
static u_short* _textTable;
static char _0[4] __attribute__((unused));
static struct DIRENTRY* _memcardFiles[15];
static struct DIRENTRY* _dirEntBuf;
static saveFileInfo_t* _saveFileInfo;

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

static int _findCurrentSaveOnActiveMemcard(void)
{
    int i;
    for (i = 0; i < 5; ++i) {
        if ((_saveFileInfo[i].unk4.base.slotState >= slotStateInUse)
            && (_saveFileInfo[i].unk4.base.slotState == vs_main_settings.slotState)
            && (_saveFileInfo[i].key == vs_main_settings.key)
            && (_saveFileInfo[i].unk4.stats.saveCount == vs_main_settings.saveCount)
            && (_saveFileInfo[i].unk4.base.generation
                == vs_main_settings.saveFileGeneration)) {
            return i + 1;
        }
    }
    return 0;
}

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

typedef struct {
    int key;
    saveBase_t base;
} savedata_unk180_2_t;

typedef struct {
    savedata_unk180_2_t unk180;
    stats_t stats;
    char checksums[0x5C];
} savedata_unk180_t;

typedef struct {
    char containerData[0x3800];
    char unk3800[0x100];
    char unk3900[0x300];
} containerData_t;

typedef struct {
    saveFileInfo_t fileInfo;
    char unk80[0x80];
    char unk100[0x80];
    savedata_unk180_t unk180;
    char unk200[0x440];
    char unk640[0x20];
    char unk660[0x48];
    vs_main_settings_t unk6A8;
    D_80060068_t unk6C8;
    char unk7C8[15][256];
    char unk16C8[0xB0];
    D_80061068_t unk1778;
    vs_main_scoredata_t unk1784;
    int unk1898;
    char unk189C[0x520];
    vs_main_artsStatus_t artsStatus;
    containerData_t containerData;
    char unk59E0[0x220];
} savedata_t;

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

static void _decode(u_int key, void* buf, int count)
{
    for (; count != 0; --count) {
        key *= 0x19660D;
        *((char*)buf++) -= key >> 24;
    }
}

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
        bytesRead = read(file, saveInfo, sizeof(saveInfo));
        close(file);
        if (bytesRead != sizeof(saveInfo)) {
            continue;
        }
        _decode(saveInfo[3].key, &saveInfo[3].unk4.base.slotState,
            sizeof(saveFileInfo_t) - sizeof(int));
        if (_verifySaveChecksums((savedata_t*)saveInfo, 2) == 0) {
            _rMemcpy(&_saveFileInfo[id - 1], &saveInfo[3], sizeof(saveInfo[3]));
            return 0;
        }
    }

    memset(&_saveFileInfo[id - 1], 0, sizeof(_saveFileInfo[id - 1]));
    return 1;
}

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

    memset(_saveFileInfo, 0, sizeof(saveFileInfo_t) * 5);
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
                memset(&_saveFileInfo[fileNo - 1], 0, sizeof(saveFileInfo_t));
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
        if (event < memcardInternalEventIoEnd)
            break;
        if (event >= memcardInternalEventNone)
            break;
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

    _rMemcpy(&vs_main_stateFlags, spmcimg[1].unk200, sizeof(vs_main_stateFlags));
    _rMemcpy(vs_main_skillsLearned, spmcimg[1].unk640, sizeof(vs_main_skillsLearned));
    _rMemcpy(&D_8005FFD8, spmcimg[1].unk660, sizeof(D_8005FFD8));
    _rMemcpy(&vs_main_settings, &spmcimg[1].unk6A8, sizeof(vs_main_settings));
    _rMemcpy(&D_80060068, &spmcimg[1].unk6C8, sizeof(D_80060068));
    _rMemcpy(D_80060168, spmcimg[1].unk7C8, sizeof(D_80060168));
    _rMemcpy(&D_800619D8, spmcimg[1].unk16C8, sizeof(D_800619D8));
    _rMemcpy(&D_80061068, &spmcimg[1].unk1778, sizeof(D_80061068));
    _rMemcpy(&vs_main_scoredata, &spmcimg[1].unk1784, sizeof(vs_main_scoredata));
    D_80060064 = s4->unk1898;
    _rMemcpy(D_80061078, spmcimg[1].unk189C, sizeof(D_80061078));
    spmcimg2 = &vs_main_artsStatus;
    _rMemcpy(&vs_main_artsStatus, &spmcimg[1].artsStatus, sizeof(vs_main_artsStatus));
    vs_main_gametime.t = spmcimg[1].unk180.stats.gameTime.t;
    func_80042CA0();
    vs_main_setMonoSound(vs_main_settings.monoSound);
    return 0;
}

static void _packageGameSaveData(int targetFile)
{
    static const u_short D_8006886C[] = { 0x7582, 0x6082, 0x6682, 0x7182, 0x6082, 0x6D82,
        0x7382, 0x4081, 0x7282, 0x7382, 0x6E82, 0x7182, 0x7882, 0x4081, 0x6582, 0x6882,
        0x6B82, 0x6482, 0x4081, 0x5082, 0x4081, 0x4081, 0x4081, 0x4F82, 0x4F82, 0x4681,
        0x4F82, 0x4F82, 0x4681, 0x4F82, 0x4F82, 0x4081 };

    long i;
    int j;
    int var_a0;
    u_short const* s0 = D_8006886C;
    savedata_t* savedata = (savedata_t*)_spmcimg;
    savedata_t* savedata2 = savedata + 1;
    savedata_t* savedata3 = savedata;
    savedata_unk180_t* s5 = &savedata->unk180;

    vs_main_gametime.all = 0;
    vs_main_settings.unk2 &= 0xFFDF;
    vs_main_stateFlags.puzzleMode = ~(*(u_int*)&vs_main_settings >> 3) & 1;
    memset(savedata, 0, sizeof(*savedata));
    ((char*)&savedata->fileInfo.key)[0] = 0x53;
    ((char*)&savedata->fileInfo.key)[1] = 0x43;
    ((char*)&savedata->fileInfo.key)[2] = 0x11;
    ((char*)&savedata->fileInfo.key)[3] = 3;
    _rMemcpy(&savedata->fileInfo.unk4, s0, sizeof(savedata->fileInfo.unk4));
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
        sizeof(savedata->fileInfo.unk60));
    _rMemcpy(savedata3->unk80, _mcData->unk4E0[targetFile], sizeof(savedata->unk80));

    if (vs_main_settings.slotState == 0) {
        vs_main_settings.slotState = _encode(0x20);
        if (vs_main_settings.slotState < 3) {
            vs_main_settings.slotState = 0x17385CA9;
        }
        memset(&savedata2->containerData, 0, sizeof(savedata2->containerData));
    }

    vs_main_settings.key = _encode(0x20);
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
    if (vs_main_settings.saveCount < 9999) {
        ++vs_main_settings.saveCount;
    }

    vs_main_settings.unk1A = 0;
    s5->unk180.base.unk8 = 0x20000107;
    s5->stats.gameTime.t = vs_main_gametime.t;
    s5->stats.currentHP = D_80060068.unk0.currentHP;
    s5->stats.maxHP = D_80060068.unk0.maxHP;
    s5->stats.saveCount = vs_main_settings.saveCount;
    s5->stats.unk12 = vs_main_settings.unk1A;
    s5->stats.saveLocation = 0x30;
    s5->stats.mapCompletion = 0;
    memset(D_80060168[14], 0, sizeof(D_80060168[14]));
    memset(&D_800619D8.unk70, 0, sizeof(D_800619D8.unk70));
    memset(savedata2->containerData.unk3800, 0, sizeof(savedata2->containerData.unk3800));
    s5->stats.clearCount = vs_main_stateFlags.clearCount;
    s5->stats.currentMP = D_80060068.unk0.currentMP;
    s5->stats.maxMP = D_80060068.unk0.maxMP;
    _rMemcpy(savedata->unk200, &vs_main_stateFlags, sizeof(savedata->unk200));
    _rMemcpy(savedata->unk640, vs_main_skillsLearned, sizeof(savedata->unk640));
    _rMemcpy(savedata->unk660, &D_8005FFD8, sizeof(savedata->unk660));
    _rMemcpy(&savedata->unk6A8, &vs_main_settings, sizeof(savedata->unk6A8));
    _rMemcpy(&savedata->unk6C8, &D_80060068, sizeof(savedata->unk6C8));
    _rMemcpy(savedata->unk7C8, D_80060168, sizeof(savedata->unk7C8));
    _rMemcpy(savedata->unk16C8, &D_800619D8, sizeof(savedata->unk16C8));
    _rMemcpy(&savedata->unk1778, &D_80061068, sizeof(savedata->unk1778));
    _rMemcpy(&savedata->unk1784, &vs_main_scoredata, sizeof(savedata->unk1784));
    _rMemcpy(&savedata->containerData, &savedata2->containerData,
        sizeof(savedata->containerData));
    savedata->unk1898 = D_80060064;
    _rMemcpy(savedata->unk189C, D_80061078, sizeof(savedata->unk189C));
    _rMemcpy(&savedata->artsStatus, &vs_main_artsStatus, sizeof(savedata->artsStatus));

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
        _spmcimg[i] += _encode(8);
    }
}

static char _loadSaveDataErrorOffset;
static char _1 __attribute__((unused));
static u_short _fileProgressTarget;
static u_short _filePreviousProgressCounter;
static u_short _fileProgressPosition;
static int _fileProgressCounter;

static int _loadSaveData(int portFileno)
{
    enum state { init = 0, reading = 1 };

    static char state;
    static char port;
    static char file;
    static char isTempSave;
    static char errors;
    static short _ __attribute__((unused));
    static int fd;

    void* temp_s2 = (savedata_t*)_spmcimg + 1;

    if (portFileno != 0) {
        state = init;
        errors = 0;
        _loadSaveDataErrorOffset = 0;
        port = portFileno >> 0xC;
        isTempSave = (portFileno >> 8) & 1;
        file = portFileno & 0xF;
        _fileProgressPosition = 80;
        _filePreviousProgressCounter = 0;
        return 0;
    }

    switch (state) {
    case init: {
        int nBytes;
        char* filename;
        int new_var = 320;

        _fileProgressPosition +=
            ((_fileProgressCounter - _filePreviousProgressCounter)
                * ((_loadSaveDataErrorOffset * 20) - (_fileProgressPosition - new_var)))
            / _fileProgressTarget;
        _loadSaveDataErrorOffset = errors;
        _fileProgressTarget = 192 - (isTempSave << 7);
        _filePreviousProgressCounter = _fileProgressCounter;

        memset(temp_s2, 0, sizeof(savedata_t));

        if (file & 8) {
            filename = _memcardMakeTempFilename(port, file & 7);
        } else {
            filename = _memcardMakeFilename(port, file);
        }
        fd = open(filename, O_NOWAIT | O_RDONLY);
        if (fd == -1) {
            ++errors;
            break;
        }
        _resetMemcardEvents(memcardEventsSw);
        nBytes = sizeof(savedata_t);
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
        int event = _testMemcardEvents(memcardEventsSw);
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

static int _saveFile(int portFile)
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
    static char _[3] __attribute__((unused));
    static int fd;

    int temp_v1_2;
    int i;
    int temp_s3;

    if (portFile != 0) {
        errors = 0;
        renameErrors = 0;
        _loadSaveDataErrorOffset = 0;
        port = portFile >> 0xC;
        file = portFile & 7;
        _fileProgressPosition = 80;
        _filePreviousProgressCounter = 0;
        state = _memcardSaveIdExists(file + 'A' - 1);
        return 0;
    }
    switch (state) {
    case init:
        if (rename(_memcardMakeFilename(port, file), _memcardMakeTempFilename(port, file))
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
        temp_v1_2 = ((_fileProgressCounter - _filePreviousProgressCounter)
                        * (320 - _fileProgressPosition))
                  / _fileProgressTarget;
        _filePreviousProgressCounter = _fileProgressCounter;
        _fileProgressTarget = 384;
        _fileProgressPosition += temp_v1_2;
        fd = open(_memcardMakeTempFilename(port, file), O_NOWAIT | O_WRONLY);
        ;
        if (fd == -1) {
            ++errors;
            break;
        }
        _resetMemcardEvents(memcardEventsSw);
        if (write(fd, _spmcimg, sizeof(savedata_t)) == -1) {
            close(fd);
            ++errors;
            break;
        }
        state = readReady;
        // fallthrough
    case readReady: {
        temp_s3 = _testMemcardEvents(memcardEventsSw);
        if (temp_s3 < memcardInternalEventNone) {
            close(fd);
            if (temp_s3 == memcardInternalEventIoEnd) {
                state = verifyPending;
                i = _fileProgressPosition;
                temp_s3 = _filePreviousProgressCounter;
                _loadSaveData((port << 12) | (file + 8));
                _fileProgressPosition = i;
                _filePreviousProgressCounter = temp_s3;
            } else {
                ++errors;
                state = tempFileCreated;
            }
        }
        break;
    }
    case verifyPending:
        temp_s3 = _loadSaveData(0);
        if (temp_s3 == 0) {
            break;
        }
        if (temp_s3 < 0) {
            return -1;
        }
        for (i = 0; i < (int)sizeof(savedata_t); ++i) {
            if (_spmcimg[i] != _spmcimg[sizeof(savedata_t) + i]) {
                break;
            }
        }
        if (i < (int)sizeof(savedata_t)) {
            return -1;
        }
        state = fileVerified;
        break;
    case fileVerified:
        if (rename(_memcardMakeTempFilename(port, file), _memcardMakeFilename(port, file))
            == 0) {
            ++renameErrors;
            errors = (renameErrors >> 4);
            break;
        }
        return 1;
    }
    return errors == 3 ? -1 : 0;
}

static int _initMemcard(int init)
{
    enum state {
        none = 0,
        queueReady = 1,
        enqueued = 2,
    };

    static u_short _eventSpecs[] = { EvSpIOE, EvSpERROR, EvSpTIMOUT, EvSpNEW };
    static char state;
    static char _[3] __attribute__((unused));
    static vs_main_CdQueueSlot* cdQueueSlot;

    vs_main_CdFile cdFile;
    int i;
    u_int event;

    if (init != 0) {
        _spmcimg = vs_main_allocHeap(VS_SPMCIMG_BIN_SIZE);
        _mcData = (mcdata_t*)(_spmcimg + sizeof(savedata_t) * 3);
        _textTable = _mcData->textTable;
        _saveFileInfo = _mcData->saveFileInfo;
        _dirEntBuf = &_mcData->_dirEntBuf;
        cdFile.lba = VS_SPMCIMG_BIN_LBA;
        cdFile.size = VS_SPMCIMG_BIN_SIZE;
        cdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(cdQueueSlot, _spmcimg);
        state = none;
        return 0;
    }

    switch (state) {
    case none:
        if (cdQueueSlot->state == vs_main_CdQueueStateLoaded) {
            vs_main_freeCdQueueSlot(cdQueueSlot);
            _drawImage(vs_getXY(800, 256), _spmcimg, vs_getWH(224, 256));
            state = queueReady;
        }
        return 0;
    case queueReady:
        cdFile.lba = VS_MCDATA_BIN_LBA; // MCMAN.BIN must immediately follow MCDATA.BIN on
                                        // the disk
        cdFile.size = VS_MCDATA_BIN_SIZE + VS_MCMAN_BIN_SIZE;
        cdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(cdQueueSlot, _mcData);
        state = enqueued;
        break;
    case enqueued:
        break;
    default:
        return 0;
    }

    if (cdQueueSlot->state == vs_main_CdQueueStateLoaded) {
        vs_main_freeCdQueueSlot(cdQueueSlot);
        vs_main_enableReset(0);
        EnterCriticalSection();

        for (i = 0; i < 8; ++i) {
            event = SwCARD;
            if (i & 4) {
                event = HwCARD;
            }
            _memcardEventDescriptors[i] =
                OpenEvent(event, _eventSpecs[i & 3], EvMdNOINTR, NULL);
        }

        ExitCriticalSection();

        for (i = 0; i < 8; ++i) {
            EnableEvent(_memcardEventDescriptors[i]);
        }
        return 1;
    }
    return 0;
}

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
}

enum fileMenuElementState_e {
    fileMenuElementStateInactive = 0,
    fileMenuElementStateStatic = 1,
    fileMenuElementStateAnimateX = 2,
    fileMenuElementStateAnimateY = 3,
    fileMenuElementStateAnimateNegX = 4
};

typedef struct {
    char state;
    char slotId;
    char outertextBlendFactor;
    char innertextBlendFactor;
    char selected;
    char slotUnavailable;
    char saveLocation;
    char unk7;
    short targetPosition;
    short unkA;
    short x;
    short y;
    short w;
    short h;
    char text[32];
} fileMenuElements_t;

typedef struct {
    u_long tag;
    union {
        VS_SPRT sprt;
        VS_TILE_TPAGE tile_tpage;
        VS_TILE tile;
        VS_POLY_G4_TPAGE polyG4_tpage;
        VS_POLY_G4 polyG4;
        struct {
            VS_TILE_TPAGE tile;
            VS_POLY_G4 polyG4;
        } tilePoly;
        u_long raw[15];
    } prim;
} primBuf_t;

static fileMenuElements_t _fileMenuElements[10];
static char _2[8] __attribute__((unused));
static primBuf_t _primBuf;

static void _drawSprt(int xy, int uvClut, int wh, int tpage)
{
    DrawSync(0);
    _primBuf.tag = vs_getTag(_primBuf.prim.sprt, primAddrNull);
    _primBuf.prim.sprt.tpage = vs_getTpageRaw(tpage & 0x9FF);
    _primBuf.prim.sprt.r0g0b0code =
        vs_getRGB0Raw(primSprt, ((0x80 - (tpage >> 16)) * 0x010101));
    _primBuf.prim.sprt.x0y0 = xy;
    _primBuf.prim.sprt.u0v0clut = uvClut;
    _primBuf.prim.sprt.wh = wh;
    DrawPrim(&_primBuf);
}

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

static char _menuElementStops[] = { 0, 1, 2, 4, 8, 16, 32, 56, 80, 104, 128, 152, 176,
    200, 224, 248, 255, 255, 255, 255 };
static signed char _cursorFileOpSaturation[] = { 0, -56, -112, -104, -96, -88, -80, -72,
    -64, -56, -48, -40, -32, -24, -16, -8 };

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

    _drawSprt(xy, _saveInfoUVClut[id], _saveInfoWh[id],
        getTPage(clut4Bit, semiTransparencyHalf, 768, 0));
}

static void _drawInteger(int xy, u_int value, u_int placeDivisor)
{
    do {
        _drawSprt(xy, vs_getUV0Clut(((value / placeDivisor) * 6), 0, 832, 223),
            vs_getWH(6, 10), getTPage(0, 0, 768, 0));
        value = value % placeDivisor;
        placeDivisor /= 10;
        xy += 5;
    } while (placeDivisor != 0);
}

static int _countDigits(int val)
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

static void _drawHPMP(int xy, enum statType_e stat, u_int currentValue, u_int maxValue)
{
    static char _digitDivisors[] = { 0, 1, 10, 100 };
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
    _primBuf.tag = vs_getTag(_primBuf.prim.tilePoly, primAddrNull);
    _primBuf.prim.tilePoly.tile.tpage =
        vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
    _primBuf.prim.tilePoly.tile.r0g0b0code = vs_getRGB0(primTile, 0, 40, 64);
    wh = vs_getWH(66, 5);
    x1y1 = (currentValueDigits + vs_getXY(0, 9));
    _primBuf.prim.tilePoly.tile.x0y0 = xy++ + vs_getXY(0, 8);
    _primBuf.prim.tilePoly.tile.wh = wh;
    _primBuf.prim.tilePoly.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4, rgb1);
    _primBuf.prim.tilePoly.polyG4.x0y0 = xy + vs_getXY(0, 9);
    _primBuf.prim.tilePoly.polyG4.r1g1b1 = rgb0;
    _primBuf.prim.tilePoly.polyG4.x1y1 = xy + x1y1;
    _primBuf.prim.tilePoly.polyG4.r2g2b2 = rgb1;
    _primBuf.prim.tilePoly.polyG4.x2y2 = xy + vs_getXY(0, 12);
    _primBuf.prim.tilePoly.polyG4.r3g3b3 = rgb0;
    _primBuf.prim.tilePoly.polyG4.x3y3 = vs_getXY(0, 12);
    _primBuf.prim.tilePoly.polyG4.x3y3 =
        xy + (currentValueDigits + _primBuf.prim.tilePoly.polyG4.x3y3);
    DrawPrim(&_primBuf);

    currentValueDigits = _countDigits(currentValue);
    maxValueDigits = _countDigits(maxValue);
    _drawSaveInfoUI(xy - 1, stat + vs_uiids_hp);
    wh = currentValueDigits * 6;
    new_var4 = 55;
    xy = (xy - (wh - new_var4)) - (maxValueDigits * 5);
    placeDivisor = _digitDivisors[currentValueDigits];
    do {
        _drawSprt(xy - vs_getXY(0, 1),
            (((currentValue / placeDivisor) << 3) + 64) | (getClut(832, 223) << 16),
            vs_getWH(7, 12), getTPage(0, 0, 768, 0));
        currentValue = currentValue % placeDivisor;
        placeDivisor /= 10;
        xy += 6;
    } while (placeDivisor != 0);
    _drawSaveInfoUI(xy + 1, vs_uiids_dot);
    _drawInteger(xy + 6, maxValue, _digitDivisors[maxValueDigits]);
}

static int _selectCursorXy;
static char* _memoryCardMessage;
static char _isSaving;

static void _fileProcessingAnim(int x, int y)
{
    char* new_var __attribute__((unused));
    int gradientColor1;
    int gradientColor2;
    u_int leftEdge;
    u_int i;

    leftEdge = x - 48;
    new_var = &_isSaving;

    if (leftEdge < 64) {
        leftEdge = 64;
    }

    gradientColor1 = 0;
    gradientColor2 = vs_getRGB888(224, 255, 0);

    if (_isSaving != 0) {
        gradientColor2 = vs_getRGB888(255, 0, 127);
    }

    for (i = 0; i < 2; ++i) {
        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.polyG4_tpage, primAddrNull);
        _primBuf.prim.polyG4_tpage.r0g0b0code =
            vs_getRGB0Raw(primPolyG4SemiTrans, gradientColor1);
        _primBuf.prim.polyG4_tpage.x0y0 = leftEdge | y;
        _primBuf.prim.polyG4_tpage.x1y1 = x | y;
        _primBuf.prim.polyG4_tpage.x2y2 = leftEdge | (y + vs_getXY(0, 32));
        _primBuf.prim.polyG4_tpage.tpage =
            vs_getTpage(0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
        _primBuf.prim.polyG4_tpage.r1g1b1 = gradientColor2;
        _primBuf.prim.polyG4_tpage.r2g2b2 = gradientColor1;
        _primBuf.prim.polyG4_tpage.r3g3b3 = gradientColor2;
        _primBuf.prim.polyG4_tpage.x3y3 = x | (y + vs_getXY(0, 32));
        DrawPrim(&_primBuf);
        leftEdge = x;
        x += 16;
        gradientColor1 = gradientColor2;
        gradientColor2 = 0;
    }
}

static void _fileProcessingCompleteAnim(int colour, int y)
{
    int yOfst;
    int colour0;
    u_int i;
    int colour1 = 0;

    if (_isSaving != 0) {
        colour0 = colour + (colour << 15);
    } else {
        colour0 = (colour - (colour >> 3)) + (colour << 8);
    }

    DrawSync(0);
    _primBuf.tag = vs_getTag(_primBuf.prim.tile_tpage, primAddrNull);
    _primBuf.prim.tile_tpage.tpage =
        vs_getTpage(0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
    _primBuf.prim.tile_tpage.r0g0b0code = vs_getRGB0Raw(primTileSemiTrans, colour0);
    _primBuf.prim.tile_tpage.x0y0 = y | 64;
    _primBuf.prim.tile_tpage.wh = vs_getWH(256, 32);
    DrawPrim(&_primBuf);

    for (i = 0; i < 2; ++i) {
        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.polyG4, primAddrNull);
        yOfst = y + vs_getXY(0, -8);
        _primBuf.prim.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4SemiTrans, colour1);
        _primBuf.prim.polyG4.x0y0 = yOfst | 64;
        _primBuf.prim.polyG4.r1g1b1 = colour1;
        _primBuf.prim.polyG4.x1y1 = yOfst | 320;
        _primBuf.prim.polyG4.r2g2b2 = colour0;
        _primBuf.prim.polyG4.x2y2 = y | 64;
        _primBuf.prim.polyG4.r3g3b3 = colour0;
        _primBuf.prim.polyG4.x3y3 = y | 320;
        DrawPrim(&_primBuf);
        y += vs_getXY(0, 40);
        colour1 = colour0;
        colour0 = 0;
    }
}

static u_char _selectCursorColor;
static char _fileMenuScreenFade;

static void _initFileMenu(void)
{
    _memoryCardMessage = NULL;
    _selectCursorColor = 0;
    _selectCursorXy = 0;
    _fileProgressCounter = 0;
    _fileMenuScreenFade = 0;
    _fileProgressTarget = 384;
    memset(_fileMenuElements, 0, sizeof(_fileMenuElements));
}

static fileMenuElements_t* _initFileMenuElement(int id, int xy, int wh, char* text)
{
    fileMenuElements_t* element;
    int i;
    u_int c;

    element = &_fileMenuElements[id];
    memset(element, 0, sizeof(*element));
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
                    element->text[i] = 0xFF;
                    return element;
                }
                if (c >= vs_char_nonPrinting) {
                    continue;
                }
            }
            element->text[i++] = c;
        }
    } else {
        element->text[0] = 0xFF;
    }
    return element;
}

static void _clearFileMenuElement(int id)
{
    memset(&_fileMenuElements[id], 0, sizeof(fileMenuElements_t));
}

static int _fileMenuElementsActive(void)
{
    int i;

    for (i = 0; i < 10 && _fileMenuElements[i].state < fileMenuElementStateAnimateX; ++i)
        ;
    return i == 10;
}

static int _printCharacter(u_int c, int x, int y, int clut)
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
        _primBuf.tag = vs_getTag(_primBuf.prim.sprt, primAddrNull);
        _primBuf.prim.sprt.tpage =
            vs_getTpage(832, 0, clut4Bit, semiTransparencyFull, ditheringOff);
        _primBuf.prim.sprt.r0g0b0code = vs_getRGB0(primSprtSemtTrans, 128, 128, 128);
        _primBuf.prim.sprt.x0y0 = (u_short)x | y << 16;
        _primBuf.prim.sprt.wh = vs_getWH(12, 12);
        _primBuf.prim.sprt.u0v0clut =
            vs_getUV0Clut((c % 21) * 12, (c / 21) * 12, clut * 16 + 896, 222);
        DrawPrim(&_primBuf);
    }
    return x + glyphWidths[c];
}

enum _findCurrentSave_e {
    findSaveTimeout = -2,
    findSaveNotFound = -1,
    findSavePending = 0
};

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

enum _memcardMaskedHandler_e {
    memcardMaskedHandlerError = -1,
    memcardMaskedHandlerPending = 0,
    memcardMaskedHandlerComplete = 1
};

static int _memcardMaskedHandler(int portMask)
{
    static char mask;
    static char _ __attribute__((unused));

    int event;

    if (portMask != 0) {
        _memcardEventHandler(portMask & 3);
        mask = (portMask >> 4);
        return 0;
    }
    event = _memcardEventHandler(0);
    if (event != memcardEventPending) {
        switch (event & mask) {
        case memcardEventIoEnd:
            return 1;
        case memcardEventTimeout:
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_insertError);
            break;
        case memcardEventUnformatted:
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_noData);
            break;
        default:
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_removed);
            break;
        }
        return -1;
    }
    return 0;
}

static void _printString(char* text, int x, int y, int clut)
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
                nextX = _printCharacter(c, nextX, y, clut);
            } else if (c == vs_char_confirm) {
                tempArrowState = (arrowState + 1) % 12;
                c = vs_char_arrow - (tempArrowState >> 2);
                arrowState = tempArrowState;
                nextX = _printCharacter(c, nextX, y, clut);
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

static u_int _interpolateRGB(u_int colour1, u_int colour2, u_int factor)
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

static u_int _intepolateMenuItemBgColour(u_int outerFactor, u_int innerFactor)
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
        color1 = _interpolateRGB(
            vs_getRGB888(0, 65, 107), vs_getRGB888(25, 130, 108), innerFactor);
        color2 =
            _interpolateRGB(vs_getRGB888(0, 5, 51), vs_getRGB888(1, 40, 38), innerFactor);
    } else {
        color1 = colors1[((innerFactor >> 3) - 2)];
        color2 = colors2[((innerFactor >> 3) - 2)];
    }
    return _interpolateRGB(color1, color2, outerFactor);
}

static void _drawFileMenuElement(fileMenuElements_t* element)
{
    u_long clut[130];
    saveFileInfo_t* saveInfo;
    int xy;
    int var_a3;
    int location;
    int x;
    int y;
    int var1;
    int var2;
    int uvClut;
    int slotState;
    u_long* locationClut;
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
        var1 = _intepolateMenuItemBgColour(8 - element->outertextBlendFactor, y);
        var2 = _intepolateMenuItemBgColour(element->outertextBlendFactor, y);
        if (y & 7) {
            element->innertextBlendFactor = y + 1;
        }
        y = element->y << 16;

        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.tilePoly, primAddrNull);
        _primBuf.prim.tilePoly.tile.tpage =
            vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
        _primBuf.prim.tilePoly.tile.r0g0b0code = vs_getRGB0(primTile, 0, 0, 0);
        _primBuf.prim.tilePoly.tile.x0y0 =
            ((element->x + 2) & 0xFFFF) | (element->y + 2) << 16;
        _primBuf.prim.tilePoly.tile.wh = element->w | (element->h << 0x10);
        _primBuf.prim.tilePoly.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4, var1);
        _primBuf.prim.tilePoly.polyG4.x0y0 = (u_short)element->x | y;
        _primBuf.prim.tilePoly.polyG4.r1g1b1 = var2;
        _primBuf.prim.tilePoly.polyG4.x1y1 = ((element->x + element->w) & 0xFFFF) | y;
        _primBuf.prim.tilePoly.polyG4.r2g2b2 = var1;
        _primBuf.prim.tilePoly.polyG4.x2y2 =
            (u_short)element->x | ((element->y + element->h) << 0x10);
        _primBuf.prim.tilePoly.polyG4.r3g3b3 = var2;
        _primBuf.prim.tilePoly.polyG4.x3y3 =
            ((element->x + element->w) & 0xFFFF) | ((element->y + element->h) << 0x10);
        DrawPrim(&_primBuf);

        x = element->x + 6;
        for (var1 = 0; var1 < 32; ++var1) {
            var2 = element->text[var1];
            if (var2 == vs_char_spacing) {
                x += element->text[++var1];
            } else if (var2 != 0xFF) {
                x = _printCharacter(var2, x, element->y, 0);
            } else {
                break;
            }
        }
        var2 = element->slotId;
        if (var2 < 5) {
            _readImage(vs_getXY(768, 227), clut, vs_getWH(256, 1));
            saveInfo = &_saveFileInfo[var2];
            location = element->saveLocation - 1;
            var1 = saveInfo->unk4.base.slotState;
            if (saveInfo->unk4.base.slotState < 3) {
                if (saveInfo->unk4.base.slotState == 0) {
                    location = -2;
                } else if (saveInfo->unk4.base.slotState == 2) {
                    location = -4;
                } else if (_isSaving != 0) {
                    location = -1;
                } else {
                    location = -5;
                }
            } else if (location >= 48) {
                location = -3;
            }
            if (location >= 32u) {
                locationClut = _mcData->locationCluts[1];
            } else {
                locationClut = _mcData->locationCluts[0];
            }
            _drawImage(vs_getXY(768, 227), locationClut, vs_getWH(256, 1));
            if (location < 0) {
                uvClut = (~location << 13) | vs_getUV0Clut(64, 0, 768, 227);
                xy = (element->x - 64) | y;
                _drawSprt(xy, uvClut, vs_getWH(64, 32),
                    ((8 - element->outertextBlendFactor) << 19) | 0x9C);
            } else {
                int v0;
                uvClut = ((location & 8) * 8) | ((location & 7) << 0xD)
                       | vs_getUV0Clut(0, 0, 768, 227);
                xy = (element->x - 64) | y;
                new_var = (((location & 0x30) * 4) + 832) & 0x3FF;
                v0 = new_var >> 6;
                var_a3 = (((8 - element->outertextBlendFactor) << 19) | 0x90);
                _drawSprt(xy, uvClut, vs_getWH(64, 32), v0 | var_a3);
            }
            _drawImage(vs_getXY(768, 227), clut, vs_getWH(256, 1));
            _drawSaveInfoUI((element->x - 22) | y, vs_uiids_number);
            _drawInteger((element->x - 9) | y, var2 + 1, 0xAU);
            slotState = saveInfo->unk4.base.slotState;
            if (slotState == slotStateUnavailable) {
                _printString((char*)(_textTable + VS_MCMAN_BIN_OFFSET_inUse),
                    element->x + 6, element->y + 10, 3);
            } else if (slotState == slotStateAvailable) {
                if (_isSaving == 0) {
                    _printString((char*)(_textTable + VS_MCMAN_BIN_OFFSET_empty),
                        element->x + 6, element->y + 10, 3);
                } else {
                    _printString((char*)(_textTable + VS_MCMAN_BIN_OFFSET_new),
                        element->x + 6, element->y + 10, 0);
                }
            } else {
                y += 4 << 16;
                _printString(
                    (char*)&_textTable[_textTable[element->saveLocation
                                                  + VS_MCMAN_BIN_INDEX_saveLocations]],
                    element->x + 6, element->y + 4, 0);
                _drawSaveInfoUI(y | 172, vs_uiids_map);
                _drawSaveInfoUI(y | 189, vs_uiids_colon);
                var1 = saveInfo->unk4.stats.mapCompletion;

                if (var1 == 100) {
                    _drawInteger(y | 192, 100, 100);
                    _drawSaveInfoUI((y + 0xFFFF0000) | 207, vs_uiids_percent);
                } else {
                    _drawInteger(y | 192, var1, 10);
                    _drawSaveInfoUI((y + 0xFFFF0000) | 202, vs_uiids_percent);
                }
                _drawSaveInfoUI(y | 217, vs_uiids_save);
                _drawSaveInfoUI(y | 239, vs_uiids_colon);
                _drawInteger(y | 242, saveInfo->unk4.stats.saveCount, 1000);
                _drawSaveInfoUI(y | 267, vs_uiids_clear);
                _drawSaveInfoUI(y | 293, vs_uiids_colon);
                _drawInteger(y | 296, saveInfo->unk4.stats.clearCount, 10);
                y += 13 << 16;
                if (saveInfo->unk4.stats.clearCount != 0) {
                    _drawSprt(y | 69, vs_getUV0Clut(240, 16, 912, 223), vs_getWH(16, 16),
                        getTPage(clut4Bit, semiTransparencyHalf, 768, 0));
                }
                _drawSaveInfoUI(y | 240, vs_uiids_time);
                var1 = saveInfo->unk4.stats.gameTime.t.h;
                if (var1 == 100) {
                    _drawInteger(y | 263, var1, 100);
                } else {
                    _drawInteger(y | 268, var1, 10);
                }
                _drawSaveInfoUI(y | 279, vs_uiids_colon);
                _drawInteger(y | 282, saveInfo->unk4.stats.gameTime.t.m, 10);
                _drawSaveInfoUI(y | 293, vs_uiids_colon);
                _drawInteger(y | 296, saveInfo->unk4.stats.gameTime.t.s, 10);
                _drawHPMP(y | 88, statTypeHP, saveInfo->unk4.stats.currentHP,
                    saveInfo->unk4.stats.maxHP);
                _drawHPMP(y | 158, statTypeMP, saveInfo->unk4.stats.currentMP,
                    saveInfo->unk4.stats.maxMP);
                y -= 17 << 16;
            }
            if ((element->selected != 0) && (_fileProgressCounter != 0)) {
                if (_fileProgressCounter < 0) {
                    signed char* p = (_cursorFileOpSaturation + _fileProgressCounter++);
                    _fileProcessingCompleteAnim(-p[17], y);
                } else {
                    int new_var3 = 0x140;
                    _fileProcessingAnim(
                        _fileProgressPosition
                            + (((_fileProgressCounter - _filePreviousProgressCounter)
                                   * ((_loadSaveDataErrorOffset * 0x14)
                                       - (_fileProgressPosition - new_var3)))
                                / _fileProgressTarget),
                        y);
                }
            }
        }
    }
}

static void _drawFileMenu(int framebuf)
{
    int _[2];
    fileMenuElements_t* element;
    int j;
    int i;
    u_int x;
    int state;
    int new_var;

    element = _fileMenuElements;
    x = 0;
    if (framebuf != 0) {
        x = 320;
    }
    _drawSprt(vs_getXY(256, 176), vs_getUV0Clut(0, 176, 768, 227), vs_getWH(64, 64),
        getTPage(clut8Bit, semiTransparencyHalf, 768, 256));
    _drawSprt(vs_getXY(0, 176), vs_getUV0Clut(0, 176, 768, 227), vs_getWH(256, 64),
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
                    if ((element->targetPosition + _menuElementStops[j]) >= element->x) {
                        break;
                    }
                }
                element->x = element->targetPosition + _menuElementStops[j - 1];
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
                    if ((element->targetPosition + _menuElementStops[j]) >= element->y) {
                        break;
                    }
                }
                element->y = (element->targetPosition + _menuElementStops[j - 1]);
            }
            if (element->y == element->targetPosition) {
                element->state = fileMenuElementStateStatic;
            }
        }
        if (state == fileMenuElementStateAnimateNegX) {
            if (element->x < element->targetPosition) {
                for (j = 1; j < 16; ++j) {
                    if (element->x >= -_menuElementStops[j]) {
                        break;
                    }
                }
                element->x = -_menuElementStops[j - 1];
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
            _drawFileMenuElement(element);
        }
    }

    for (i = 1; i < 4; ++i) {
        new_var = 256;
        _drawSprt(vs_getXY(0, 187 - i), (187 - i) << 8, vs_getWH(256, 1),
            (x >> 6) | (((4 - i) << 21) | new_var));
        _drawSprt(vs_getXY(256, 187 - i), (187 - i) << 8, vs_getWH(64, 1),
            (((int)(x + new_var)) >> 6) | (((4 - i) << 21) | new_var));
    }
    _drawSprt(vs_getXY(10, 181), vs_getUV0Clut(64, 145, 848, 223), vs_getWH(33, 7),
        getTPage(clut4Bit, semiTransparencyHalf, 768, 0)); // "Caution"
    DrawSync(0);
    _primBuf.tag = vs_getTag(_primBuf.prim.tile, primAddrNull);
    _primBuf.prim.tile.r0g0b0code = vs_getRGB0(primTile, 0, 0, 0);
    _primBuf.prim.tile.x0y0 = vs_getXY(0, 187);
    _primBuf.prim.tile.wh = vs_getWH(320, 52);
    DrawPrim(&_primBuf); // Message dialog background
    if (_selectCursorXy != 0) {
        _drawSprt(_selectCursorXy, vs_getUV0Clut(32, 48, 896, 223), vs_getWH(16, 16),
            (_cursorFileOpSaturation[_selectCursorColor] << 16)
                | getTPage(clut4Bit, semiTransparencyHalf, 768, 0));
        _selectCursorColor = (_selectCursorColor + 1) & 0xF;
        if (vs_main_buttonsPressed.all & PADRup) {
            vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
        }
    } else {
        _selectCursorColor = 0;
    }
    if (_memoryCardMessage != NULL) {
        _printString(_memoryCardMessage, 16, 192, 0);
    }
    if (_fileMenuScreenFade != 0) {
        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.tile_tpage, primAddrNull);
        _primBuf.prim.tile_tpage.tpage =
            vs_getTpage(0, 0, direct16Bit, semiTransparencySubtract, ditheringOff);
        _primBuf.prim.tile_tpage.x0y0 = vs_getXY(0, 0);
        _primBuf.prim.tile_tpage.wh = vs_getWH(320, 224);
        _primBuf.prim.tile_tpage.r0g0b0code =
            vs_getRGB0Raw(primTileSemiTrans, _fileMenuScreenFade * vs_getRGB888(8, 8, 8));
        DrawPrim(&_primBuf);
    }
}

static void _drawFileMenuBg(void)
{
    _drawSprt(vs_getXY(256, 0), vs_getUV0Clut(0, 0, 768, 227), vs_getWH(64, 176),
        getTPage(clut8Bit, semiTransparencyHalf, 768, 256));
    _drawSprt(vs_getXY(0, 0), vs_getUV0Clut(0, 0, 768, 227), vs_getWH(256, 176),
        getTPage(clut8Bit, semiTransparencyHalf, 640, 256));
}

static int _showLoadFilesMenu(int initPort)
{
    enum state {
        init = 0,
        handleInput = 1,
        startLoad = 2,
        applyLoad = 3,
        loaded = 4,
        exiting = 5
    };

    static vs_Gametime_t backupTime;
    static int fileLoaded;
    static char state;
    static char port;
    static char page;
    static char selectedSlot;
    static char leaveTimer;
    static char completeTimer;

    fileMenuElements_t* element;
    int currentSlot;
    int i;

    if (initPort != 0) {
        port = initPort;
        selectedSlot = _getNewestSaveFile();
        page = 0;
        if (selectedSlot == 4) {
            page = 2;
            selectedSlot = 2;
        } else if (selectedSlot != 0) {
            page = selectedSlot - 1;
            selectedSlot = 1;
        }
        fileLoaded = -1;
        completeTimer = 0;
        state = init;
        return 0;
    }
    switch (state) {
    case init:
        for (i = 0; i < 5; ++i) {
            element = _initFileMenuElement(
                i + 5, ((72 + i * 40) << 16) | 64, vs_getWH(256, 32), 0);
            element->slotId = i;
            element->slotUnavailable =
                _saveFileInfo[i].unk4.base.slotState < slotStateInUse;
            element->saveLocation = _saveFileInfo[i].unk4.stats.saveLocation;
        }
        state = handleInput;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_selectFile);
        // fallthrough
    case handleInput:
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            for (i = 5; i < 10; ++i) {
                _clearFileMenuElement(i);
            }
            _selectCursorXy = 0;
            return -1;
        }
        for (i = 0; i < 5; ++i) {
            _fileMenuElements[i + 5].y = (((i - page) * 40) + 72);
            _fileMenuElements[i + 5].selected = 0;
        }

        currentSlot = selectedSlot + page;

        if (vs_main_buttonsPressed.all & PADRright) {
            if (_saveFileInfo[currentSlot].unk4.base.slotState >= slotStateInUse) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                _fileMenuElements[currentSlot + 5].selected = 1;
                _selectCursorXy = 0;
                _memcardMaskedHandler(port + memcardEventMaskAll);
                state = startLoad;
                break;
            }
            vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
        }
        if (vs_main_buttonRepeat & PADLup) {
            if (selectedSlot == 0) {
                if (page != 0) {
                    --page;
                }
            } else {
                --selectedSlot;
            }
        }
        if (vs_main_buttonRepeat & PADLdown) {
            if (selectedSlot == 2) {
                if (page < 2) {
                    ++page;
                }
            } else {
                ++selectedSlot;
            }
        }
        if (currentSlot != (selectedSlot + page)) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
        }
        _selectCursorXy = ((selectedSlot * 40 + 62) << 16) | 24;
        _fileMenuElements[currentSlot + 5].selected = 1;
        break;
    case startLoad:
        currentSlot = _memcardMaskedHandler(0);
        if (currentSlot != memcardMaskedHandlerPending) {
            if (currentSlot >= memcardMaskedHandlerPending) {
                int new_var;
                _loadSaveData(
                    ((selectedSlot + page) + 1) | (new_var = ((port - 1) << 16) | 256));
                state = applyLoad;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_loading);
            } else {
                state = loaded;
            }
        }
        break;
    case applyLoad:
        currentSlot = _loadSaveData(0);
        ++_fileProgressCounter;
        if (currentSlot != 0) {
            _fileProgressCounter = 0;
            do {
                leaveTimer = 0;
                if (currentSlot < 0) {
                    _memoryCardMessage =
                        (char*)(_textTable + VS_MCMAN_BIN_OFFSET_loadfailed);
                    break;
                }
                switch (_applyLoadedSaveFile(1)) {
                case 0:
                    _fileProgressCounter = -16;
                    vs_main_playSfxDefault(0x7E, VS_SFX_FILEOPCOMPLETE);
                    leaveTimer = 16;
                    fileLoaded = 1;
                    _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_loaded);
                    break;
                case 1:
                    _memoryCardMessage =
                        (char*)(_textTable + VS_MCMAN_BIN_OFFSET_fileCorruptDescription);
                    break;
                }
            } while (0);

            backupTime.t = vs_main_gametime.t;
            state = loaded;
        }
        break;
    case loaded:
        if (leaveTimer != 0) {
            --leaveTimer;
        }
        if (fileLoaded == 1) {
            ++completeTimer;
        }
        if ((vs_main_buttonsPressed.pad[0].low != 0) || (completeTimer == 150)) {
            if (fileLoaded < 0) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            }
            state = exiting;
        }
        break;
    case exiting:
        if (leaveTimer != 0) {
            --leaveTimer;
            break;
        }
        if (fileLoaded == 1) {
            vs_main_gametime.t = backupTime.t;
        } else {
            for (i = 5; i < 10; ++i) {
                _clearFileMenuElement(i);
            }
        }
        return fileLoaded;
    }
    return 0;
}

static long _selectLoadMemoryCard(int initPort)
{
    enum state {
        init = 0,
        waitForUnselectedAnimation = 1,
        pollEventsInit = 2,
        pollEvents = 3,
        leave = 4,
        returnNotSelected = 5,
        pollSuccess = 6,
        selectFile = 7
    };

    static char state;
    static u_char port;

    int i;

    if (initPort != 0) {
        port = initPort;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_checking);
        state = init;
        return 0;
    }
    switch (state) {
    case init:
        _fileMenuElements[port].state = fileMenuElementStateAnimateX;
        _fileMenuElements[port].targetPosition = 180;
        _fileMenuElements[port].innertextBlendFactor = 1;
        _fileMenuElements[3 - port].state = fileMenuElementStateAnimateX;
        _fileMenuElements[3 - port].targetPosition = 320;
        state = waitForUnselectedAnimation;
        break;

    case waitForUnselectedAnimation:
        if (_fileMenuElementsActive() == 0) {
            break;
        }
        if (port == 2) {
            _fileMenuElements[2].state = fileMenuElementStateAnimateY;
            _fileMenuElements[2].targetPosition = 50;
        }
        state = pollEventsInit;
        break;

    case pollEventsInit:
        if (_fileMenuElementsActive() == 0) {
            break;
        }
        _memcardMaskedHandler(port + memcardEventMaskIgnoreNoEvent);
        state = pollEvents;
        break;

    case pollEvents:
        i = _memcardMaskedHandler(0);
        if (i != memcardMaskedHandlerPending) {
            state = i + leave + 1;
        }
        break;

    case leave:
        if ((vs_main_buttonsPressed.pad[0].low) == 0) {
            break;
        }
        vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
        for (i = 1; i < 3; ++i) {
            _fileMenuElements[i].state = fileMenuElementStateAnimateX;
            _fileMenuElements[i].targetPosition = 320;
        }
        state = returnNotSelected;
        break;

    case returnNotSelected:
        if (_fileMenuElementsActive() != 0) {
            return -1;
        }
        break;

    case pollSuccess:
        if (_initSaveFileInfo(port) != 0) {
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_loadfailed);
            state = leave;
            break;
        }
        for (i = 0; i < 5; ++i) {
            if (_saveFileInfo[i].unk4.base.slotState > slotStateAvailable) {
                break;
            }
        }

        if (i == 5) {
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_noData);
            state = leave;
        } else {
            _showLoadFilesMenu(port);
            state = 7;
        }
        break;

    case selectFile:
        i = _showLoadFilesMenu(0);
        if (i == 0) {
            break;
        }
        if (i < 0) {
            for (i = 1; i < 3; ++i) {
                _fileMenuElements[i].state = fileMenuElementStateAnimateX;
                _fileMenuElements[i].targetPosition = 320;
            }
            state = returnNotSelected;
            break;
        }
        return 1;
    }
    return 0;
}

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
    static char _[5] __attribute__((unused));

    fileMenuElements_t* element;
    int i;

    if (initFadeout != 0) {
        fadeout = initFadeout - 1;
        selectedFile = 1;
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

static int _promptConfirm(int arg0)
{
    enum state {
        initYes = 0,
        initNo = 1,
        waitForAnimation = 2,
        handleInput = 3,
    };

    static char state;
    static char cancelled;
    static char _[2] __attribute__((unused));

    fileMenuElements_t* temp_v0;
    int i;

    if (arg0 != 0) {
        cancelled = 1;
        state = initYes;
        return 0;
    }

    switch (state) {
    case initYes:
    case initNo:
        temp_v0 = _initFileMenuElement(state + 3,
            vs_getXY(-126 & 0xFFFF, state * 16 + 18), vs_getWH(126, 12),
            (char*)&_textTable[_textTable[state + VS_MCMAN_BIN_INDEX_yesIndent]]);
        temp_v0->state = 4;
        temp_v0->targetPosition = 0;
        ++state;
        break;
    case waitForAnimation:
        state += _fileMenuElementsActive();
        break;
    case handleInput:
        _fileMenuElements[cancelled + 3].selected = 1;
        _fileMenuElements[4 - cancelled].selected = 0;
        if (vs_main_buttonsPressed.all & (PADRdown | PADRright)) {
            _selectCursorXy = 0;
            for (i = 3; i < 5; ++i) {
                _fileMenuElements[i].state = 4;
                _fileMenuElements[i].targetPosition = -126;
            }
            if (vs_main_buttonsPressed.all & PADRright) {
                if (cancelled == 0) {
                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                    return 1;
                }
            }
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            return -1;
        }
        if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            cancelled = 1 - cancelled;
        }
        _selectCursorXy = (cancelled * 16 + 10) << 16;
        break;
    }
    return 0;
}

static int _promptOverwrite(int init)
{
    static int confirmed;
    static char state;
    static char initialized;

    if (init != 0) {
        initialized = 1;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_overwritePrompt);
        _promptConfirm(1);
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        confirmed = _promptConfirm(0);
        if (confirmed != 0) {
            state = 1;
        }
        return 0;
    case 1:
        if (_fileMenuElementsActive() != 0) {
            return confirmed;
        }
        return 0;
    default:
        return 0;
    }
}

static int _promptFormat(int initPort)
{
    enum state { promptConfirm = 0, initEvents = 1, handleEvents = 2, format = 3 };

    static char state;
    static char port;
    static int _ __attribute__((unused));

    int val;

    if (initPort != 0) {
        port = initPort;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_formatPrompt);
        _promptConfirm(1);
        state = promptConfirm;
        return 0;
    }

    switch (state) {
    case promptConfirm:
        val = _promptConfirm(0);

        if (val != 0) {
            if (val < 0) {
                _memoryCardMessage =
                    (char*)(_textTable + VS_MCMAN_BIN_OFFSET_formatCancelled);
                return -1;
            }

            state = initEvents;
        }
        return 0;
    case initEvents:
        if (_fileMenuElementsActive() != 0) {
            _memcardEventHandler(port);
            state = handleEvents;
        }
        return 0;
    case handleEvents:
        val = _memcardEventHandler(0);

        if (val != 0) {
            if (val == memcardEventUnformatted) {
                state = format;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_formatting);
            } else {
                if (val == memcardEventTimeout) {
                    _memoryCardMessage =
                        (char*)(_textTable + VS_MCMAN_BIN_OFFSET_insertError);
                } else {
                    _memoryCardMessage =
                        (char*)(_textTable + VS_MCMAN_BIN_OFFSET_removed);
                }
                return -1;
            }
        }
        return 0;
    case format:
        if (_card_format((port - 1) * 16) == 0) {
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_formatFailed);
            return -1;
        }
        return 1;
    default:
        return 0;
    }
}

static char _dataNotSaved;
static char _containerDataEmpty;
static char _backupMainSetting;

static int _showSaveFilesMenu(int initPort)
{
    enum state {
        init = 0,
        handleInput = 1,
        slotSelected = 2,
        overwritePrompt = 3,
        initOverwrite = 4,
        save = 5,
        validate = 6,
        leaveWithTimer = 7,
        leave = 8,
        format = 9,
        leaveError = 10
    };

    static vs_main_settings_t settingsBackup;
    static int saveSuccessful;
    static char state;
    static char port;
    static char page;
    static char fileSlot;
    static char leaveTimer;

    fileMenuElements_t* element;
    int val;
    int saveId;
    int i;

    if (initPort != 0) {
        port = initPort;
        fileSlot = _findCurrentSaveOnActiveMemcard();
        if (fileSlot) {
            --fileSlot;
        }
        page = 0;
        if (fileSlot == 4) {
            page = 2;
            fileSlot = 2;
        } else if (fileSlot != 0) {
            page = fileSlot - 1;
            fileSlot = 1;
        }
        saveSuccessful = -1;
        leaveTimer = 0;
        state = init;
        return 0;
    }
    switch (state) {
    case init:
        for (i = 0; i < 5; ++i) {
            element = _initFileMenuElement(
                i + 5, vs_getXY(64, i * 40 + 72), vs_getWH(256, 32), 0);
            element->slotId = i;
            element->slotUnavailable =
                _saveFileInfo[i].unk4.base.slotState == slotStateUnavailable;
            element->saveLocation = _saveFileInfo[i].unk4.stats.saveLocation;
        }
        state = handleInput;
        /* fallthrough */
    case handleInput:
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_selectFile);
        if (vs_main_buttonsPressed.all & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            _selectCursorXy = 0;
            state = leave;
        } else {
            for (i = 0; i < 5; ++i) {
                _fileMenuElements[i + 5].y = ((i - page) * 40) + 72;
                _fileMenuElements[i + 5].selected = 0;
            }
            val = fileSlot + page;
            if (vs_main_buttonsPressed.all & PADRright) {
                if (_saveFileInfo[val].unk4.base.slotState != slotStateUnavailable) {
                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                    _fileMenuElements[val + 5].selected = 1;
                    _selectCursorXy = 0;
                    _memcardMaskedHandler(port + memcardEventMaskAll);
                    state = slotSelected;
                    break;
                } else {
                    vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
                }
            }
            if (vs_main_buttonRepeat & PADLup) {
                if (fileSlot == 0) {
                    if (page != 0) {
                        --page;
                    }
                } else {
                    --fileSlot;
                }
            }
            if (vs_main_buttonRepeat & PADLdown) {
                if (fileSlot == 2) {
                    if (page < 2) {
                        ++page;
                    }
                } else {
                    ++fileSlot;
                }
            }
            if (val != (fileSlot + page)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            }
            _selectCursorXy = vs_getXY(24, fileSlot * 40 + 62);
            _fileMenuElements[val + 5].selected = 1;
        }
        break;
    case slotSelected:
        val = _memcardMaskedHandler(0);
        if (val != memcardMaskedHandlerPending) {
            if (_memoryCardMessage == (char*)(_textTable + VS_MCMAN_BIN_OFFSET_noData)) {
                _promptFormat(port);
                state = format;
            } else if (val > memcardMaskedHandlerError) {
                val = fileSlot + page;
                if (_saveFileInfo[val].unk4.base.slotState == slotStateAvailable) {
                    if (_createSaveFile(port, val + 1) != 0) {
                        state = leaveWithTimer;
                        _memoryCardMessage =
                            (char*)(_textTable + VS_MCMAN_BIN_OFFSET_saveFailed);
                    } else {
                        state = save;
                    }
                } else {
                    _promptOverwrite(1);
                    state = overwritePrompt;
                }
            } else {
                state = leaveWithTimer;
            }
        }
        break;
    case overwritePrompt:
        val = _promptOverwrite(0);
        if (val != 0) {
            if (val == 1) {
                _memcardMaskedHandler(port + memcardEventMaskAll);
                state = initOverwrite;
            } else {
                state = handleInput;
            }
        }
        break;
    case initOverwrite:
        val = _memcardMaskedHandler(0);
        if (val != memcardMaskedHandlerPending) {
            if (val > memcardMaskedHandlerError) {
                _dataNotSaved |=
                    (_findCurrentSaveOnActiveMemcard() == (fileSlot + page + 1));
                state = save;
            } else {
                state = leaveWithTimer;
            }
        }
        break;
    case save:
        val = fileSlot + page;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_saving);
        _rMemcpy(&settingsBackup, &vs_main_settings, sizeof(settingsBackup));
        _rMemcpy(
            (savedata_t*)_spmcimg + 2, (savedata_t*)_spmcimg + 1, sizeof(savedata_t));
        if (_containerDataEmpty != 0) {
            _backupMainSetting = (*(u_int*)&vs_main_settings >> 4) & 1;
            *(int*)&vs_main_settings |= 0x10;
        }
        _packageGameSaveData(val);
        _saveFile((val + 1) | ((port - 1) << 0x10));
        state = validate;
        break;
    case validate:
        val = _saveFile(0);
        ++_fileProgressCounter;
        if (val != 0) {
            vs_main_stateFlags.unk105 = 0;
            saveId = fileSlot + page;
            if (val < 0) {
                if (_containerDataEmpty != 0) {
                    char v = _backupMainSetting & 1;
                    *(int*)&vs_main_settings =
                        (*(int*)&vs_main_settings & ~0x10) | (v * 0x10);
                }
                memset(&_saveFileInfo[saveId], 0, sizeof(saveFileInfo_t));
                _saveFileInfo[saveId].unk4.base.slotState = slotStateTemporary;
                _fileMenuElements[saveId + 5].saveLocation = 0;
                _rMemcpy((savedata_t*)_spmcimg + 1, (savedata_t*)_spmcimg + 2,
                    sizeof(savedata_t));
                _fileProgressCounter = 0;
                _rMemcpy(&vs_main_settings, &settingsBackup, sizeof(vs_main_settings));
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_saveFailed);
            } else {
                _dataNotSaved = 0;
                _fileProgressCounter = -16;
                _rMemcpy(&_saveFileInfo[saveId], _spmcimg + sizeof(saveFileInfo_t) * 3,
                    sizeof(saveFileInfo_t));
                _decode(_saveFileInfo[saveId].key,
                    &_saveFileInfo[saveId].unk4.base.slotState,
                    sizeof(saveFileInfo_t) - sizeof(int));
                _fileMenuElements[saveId + 5].saveLocation =
                    _saveFileInfo[saveId].unk4.stats.saveLocation;
                vs_main_playSfxDefault(0x7E, VS_SFX_FILEOPCOMPLETE);
                saveSuccessful = 1;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_saved);
            }
            state = leaveWithTimer;
        }
        break;
    case leaveWithTimer:
        if (saveSuccessful == 1) {
            ++leaveTimer;
        }
        if (vs_main_buttonsPressed.pad[0].low == 0) {
            if (leaveTimer != 150) {
                break;
            }
        }
        vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
        state = leave;
        break;
    case leave:
        if (_fileProgressCounter == 0) {
            for (i = 5; i < 10; ++i) {
                _clearFileMenuElement(i);
            }
            return saveSuccessful;
        }
        break;
    case format:
        val = _promptFormat(0);
        if (val != 0) {
            if (val < 0) {
                state = leaveError;
            } else if (_createSaveFile(port, page + fileSlot + 1) != 0) {
                state = leaveWithTimer;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_saveFailed);
            } else {
                state = save;
            }
        }
        break;
    case leaveError:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            for (i = 5; i < 10; ++i) {
                _clearFileMenuElement(i);
            }
            return -1;
        }
        break;
    }
    return 0;
}

static int _selectSaveMemoryCard(int initPort)
{
    enum state {
        init = 0,
        waitForUnselectedAnimation = 1,
        waitForAnimation = 2,
        handleEvents = 3,
        animateLeave = 4,
        leave = 5,
        initSaveMenu = 6,
        showSaveMenu = 7
    };

    static char state;
    static u_char port;

    int i, j;

    if (initPort != 0) {
        port = initPort;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_checking);
        state = init;
        return 0;
    }

    switch (state) {
    case init:
        _fileMenuElements[port].state = fileMenuElementStateAnimateX;
        _fileMenuElements[port].targetPosition = 180;
        _fileMenuElements[port].innertextBlendFactor = 1;
        _fileMenuElements[3 - port].state = fileMenuElementStateAnimateX;
        _fileMenuElements[3 - port].targetPosition = 320;
        state = waitForUnselectedAnimation;
        break;
    case waitForUnselectedAnimation:
        if (_fileMenuElementsActive() == 0) {
            break;
        }
        if (port == 2) {
            _fileMenuElements[2].state = fileMenuElementStateAnimateY;
            _fileMenuElements[2].targetPosition = 50;
        }
        state = waitForAnimation;
        break;
    case waitForAnimation:
        if (_fileMenuElementsActive() != 0) {
            _memcardEventHandler(port);
            state = handleEvents;
        }
        break;
    case handleEvents:
        i = _memcardEventHandler(0) & 3;
        if (i == 0) {
            break;
        }
        switch (i) {
        case memcardEventIoEnd:
            state = initSaveMenu;
            break;
        case memcardEventTimeout:
            state = animateLeave;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_insertError);
            break;
        case memcardEventUnformatted:
            memset(_saveFileInfo, 0, sizeof(*_saveFileInfo) * 5);
            for (i = 14; i >= 0; --i) {
                _memcardFiles[i] = NULL;
            }
            j = slotStateAvailable;
            for (i = 4; i >= 0; --i) {
                _saveFileInfo[i].unk4.base.slotState = j;
            }
            _showSaveFilesMenu(port);
            state = showSaveMenu;
            break;
        }
        break;
    case animateLeave:
        if (vs_main_buttonsPressed.pad[0].low == 0) {
            break;
        }
        vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
        for (i = 1; i < 3; ++i) {
            _fileMenuElements[i].state = fileMenuElementStateAnimateX;
            _fileMenuElements[i].targetPosition = 320;
        }
        state = leave;
        break;
    case leave:
        if (_fileMenuElementsActive() != 0) {
            return -1;
        }
        break;
    case initSaveMenu:
        if (_initSaveFileInfo(port) != 0) {
            state = animateLeave;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_loadfailed);
            break;
        }
        for (i = 0; i < 5; ++i) {
            if (_saveFileInfo[i].unk4.base.slotState != slotStateUnavailable) {
                break;
            }
        }
        if (i == 5) {
            state = animateLeave;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_cardFull);
            break;
        }
        _showSaveFilesMenu(port);
        state = showSaveMenu;
        break;
    case showSaveMenu:
        i = _showSaveFilesMenu(0);
        if (i == 0) {
            break;
        }
        if (i < 0) {
            for (i = 1; i < 3; ++i) {
                _fileMenuElements[i].state = fileMenuElementStateAnimateX;
                _fileMenuElements[i].targetPosition = 320;
            }
            state = leave;
            break;
        }
        return 1;
    }
    return 0;
}

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

    fileMenuElements_t* element;
    int currentSave;
    int val;

    if (initState != 0) {
        selectedFile = 1;
        _containerDataEmpty = 0;
        _dataNotSaved = 0;
        _isSaving = 1;
        state = (initState - 1) * 3;
        element = _initFileMenuElement(0, vs_getXY(320, 34), vs_getWH(140, 12),
            (char*)(_textTable + VS_MCMAN_BIN_OFFSET_save));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 180;
        element->innertextBlendFactor = 8;
        element->selected = 1;
        _memoryCardMessage = NULL;
        return 0;
    }

    switch (state) {
    case init:
        if (*(int*)&vs_main_settings & 0x10) {
            memset(&((savedata_t*)_spmcimg + 1)->containerData, 0,
                sizeof(((savedata_t*)_spmcimg + 1)->containerData));
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
                    sizeof(((savedata_t*)_spmcimg + 1)->containerData));
            }
            state = initSlot1;
        }
        break;
    }
    return 0;
}

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
extern menuBg_t _saveMenuBg;

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
    _drawImage(vs_getXY(768, 227), &_saveMenuBg.clut, vs_getWH(256, 1));
    setRECT(&rect, 640, 256, 32, 240);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    setRECT(&rect, 768, 256, 32, 240);
    ClearImage(&rect, 0, 0, 0);
    _drawImage(vs_getXY(672, 256), &_saveMenuBg.data, vs_getWH(96, 240));
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
            _rMemcpy(filename, _memcardFilenameTemplate, sizeof(filename));

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
    _drawImage(vs_getXY(768, 227), &_saveMenuBg.clut, vs_getWH(256, 1));
    setRECT(&rect, 640, 256, 32, 240);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    setRECT(&rect, 768, 256, 32, 240);
    ClearImage(&rect, 0, 0, 0);
    _drawImage(vs_getXY(672, 256), &_saveMenuBg.data, vs_getWH(96, 240));
    _initSaveScreen();

    state = init;

    while (1) {
        vs_main_gametimeUpdate(2);
        _saveScreenSwapBuf();
        vs_main_processPadState();
        _encode(0);

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

static short publisherClut[] = { vs_getRGB5551(0, 0, 0, 0), vs_getRGB5551(2, 2, 2, 1),
    vs_getRGB5551(4, 4, 4, 1), vs_getRGB5551(6, 6, 6, 1), vs_getRGB5551(8, 8, 8, 1),
    vs_getRGB5551(10, 10, 10, 1), vs_getRGB5551(12, 12, 12, 1),
    vs_getRGB5551(16, 16, 16, 1), vs_getRGB5551(17, 17, 17, 1),
    vs_getRGB5551(19, 19, 19, 1), vs_getRGB5551(21, 21, 21, 1),
    vs_getRGB5551(23, 23, 23, 1), vs_getRGB5551(25, 25, 25, 1),
    vs_getRGB5551(27, 27, 27, 1), vs_getRGB5551(29, 29, 29, 1),
    vs_getRGB5551(31, 31, 31, 1) };

static char publisher[] = {
#include "../../assets/TITLE/TITLE.PRG/publisher.rgb4.img.bin.dat"
};

static char developer[] = {
#include "../../assets/TITLE/TITLE.PRG/developer.rgb4.img.bin.dat"
};

static short developerClut[][16] = {
    { vs_getRGB5551(0, 0, 0, 1), vs_getRGB5551(2, 2, 2, 0), vs_getRGB5551(3, 3, 3, 0),
        vs_getRGB5551(5, 5, 6, 0), vs_getRGB5551(21, 1, 3, 0), vs_getRGB5551(9, 9, 9, 0),
        vs_getRGB5551(21, 8, 8, 0), vs_getRGB5551(12, 12, 12, 0),
        vs_getRGB5551(14, 14, 14, 0), vs_getRGB5551(17, 17, 17, 0),
        vs_getRGB5551(20, 20, 20, 0), vs_getRGB5551(22, 22, 22, 0),
        vs_getRGB5551(24, 24, 24, 0), vs_getRGB5551(26, 26, 26, 0),
        vs_getRGB5551(29, 29, 29, 0), vs_getRGB5551(31, 31, 31, 0) },
    { vs_getRGB5551(0, 0, 0, 1), vs_getRGB5551(2, 2, 2, 0), vs_getRGB5551(3, 3, 3, 0),
        vs_getRGB5551(5, 5, 6, 0), vs_getRGB5551(21, 1, 3, 0), vs_getRGB5551(9, 9, 9, 0),
        vs_getRGB5551(21, 8, 8, 0), vs_getRGB5551(12, 12, 12, 0),
        vs_getRGB5551(14, 14, 14, 0), vs_getRGB5551(17, 17, 17, 0),
        vs_getRGB5551(20, 20, 20, 0), vs_getRGB5551(22, 22, 22, 0),
        vs_getRGB5551(24, 24, 24, 0), vs_getRGB5551(26, 26, 26, 0),
        vs_getRGB5551(29, 29, 29, 0), vs_getRGB5551(31, 31, 31, 0) }
};

static u_short* _getNextMovieFrame(MovieData_t* movie)
{
    static int _movieWidth = 0;
    static int _movieHeight = 0;

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

    DISPENV disp;
    DRAWENV draw;
    RECT rect;
    int var_a3;
    int var_a3_2;
    int i;

    setRECT(&rect, 0, 0, 320, 512);
    ClearImage(&rect, 0, 0, 0);
    _drawImage(vs_getXY(320, 64), publisherClut, vs_getWH(16, 1));
    _drawImage(vs_getXY(320, 0), &publisherClut + 1, vs_getWH(256 / 4, 48));
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

static u_short _menuItemTextClut[][16] = {
    { vs_getRGB5551(0, 0, 0, 0), vs_getRGB5551(0, 0, 2, 1), vs_getRGB5551(2, 0, 3, 1),
        vs_getRGB5551(3, 0, 4, 1), vs_getRGB5551(6, 0, 0, 1), vs_getRGB5551(9, 1, 0, 1),
        vs_getRGB5551(11, 2, 0, 1), vs_getRGB5551(13, 3, 0, 1),
        vs_getRGB5551(14, 2, 0, 1), vs_getRGB5551(15, 3, 0, 1),
        vs_getRGB5551(16, 4, 0, 1), vs_getRGB5551(16, 3, 0, 1),
        vs_getRGB5551(16, 4, 0, 1), vs_getRGB5551(17, 5, 0, 1),
        vs_getRGB5551(18, 7, 0, 1), vs_getRGB5551(19, 8, 0, 1) },
    { vs_getRGB5551(0, 0, 0, 0), vs_getRGB5551(0, 0, 2, 1), vs_getRGB5551(5, 3, 5, 1),
        vs_getRGB5551(7, 5, 7, 1), vs_getRGB5551(11, 8, 7, 1),
        vs_getRGB5551(16, 12, 9, 1), vs_getRGB5551(20, 15, 10, 1),
        vs_getRGB5551(24, 18, 11, 1), vs_getRGB5551(28, 19, 11, 1),
        vs_getRGB5551(31, 21, 10, 1), vs_getRGB5551(27, 22, 15, 1),
        vs_getRGB5551(31, 22, 12, 1), vs_getRGB5551(31, 23, 13, 1),
        vs_getRGB5551(31, 25, 16, 1), vs_getRGB5551(31, 27, 18, 1),
        vs_getRGB5551(31, 28, 19, 1) }
};
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
    static u_short _menuItemOutlineClut[][16] = {
        { vs_getRGB5551(0, 0, 0, 0), vs_getRGB5551(0, 0, 1, 1), vs_getRGB5551(0, 0, 4, 1),
            vs_getRGB5551(0, 0, 5, 1), vs_getRGB5551(0, 0, 8, 1),
            vs_getRGB5551(0, 0, 10, 1), vs_getRGB5551(0, 0, 12, 1),
            vs_getRGB5551(0, 0, 14, 1), vs_getRGB5551(0, 0, 15, 1),
            vs_getRGB5551(0, 0, 18, 1), vs_getRGB5551(0, 0, 20, 1),
            vs_getRGB5551(0, 0, 22, 1), vs_getRGB5551(0, 0, 24, 1),
            vs_getRGB5551(0, 0, 26, 1), vs_getRGB5551(1, 1, 29, 1),
            vs_getRGB5551(2, 3, 31, 1) },

        { vs_getRGB5551(0, 0, 0, 0), vs_getRGB5551(0, 0, 3, 1), vs_getRGB5551(0, 0, 3, 1),
            vs_getRGB5551(4, 2, 0, 1), vs_getRGB5551(3, 0, 7, 1),
            vs_getRGB5551(7, 3, 3, 1), vs_getRGB5551(12, 7, 4, 1),
            vs_getRGB5551(19, 12, 1, 1), vs_getRGB5551(24, 17, 1, 1),
            vs_getRGB5551(28, 20, 1, 1), vs_getRGB5551(30, 20, 1, 1),
            vs_getRGB5551(31, 22, 0, 1), vs_getRGB5551(31, 22, 2, 1),
            vs_getRGB5551(26, 20, 10, 1), vs_getRGB5551(31, 25, 4, 1),
            vs_getRGB5551(28, 23, 10, 1) }
    };

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
#define MENUBGSZ 222932 * sizeof(int)
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

static void _drawTitleMenuItems(void)
{
    typedef struct {
        u_long tag;
        VS_SPRT sprt;
    } menuItemPrim_t;

    static int textUvs[] = { vs_getUV0Clut(128, 224, 480, 384),
        vs_getUV0Clut(0, 224, 480, 385), vs_getUV0Clut(128, 224, 480, 386),
        vs_getUV0Clut(0, 224, 480, 387), vs_getUV0Clut(0, 224, 480, 388),
        vs_getUV0Clut(0, 224, 480, 389), vs_getUV0Clut(128, 224, 480, 390),
        vs_getUV0Clut(128, 224, 480, 391), vs_getUV0Clut(128, 224, 480, 392),
        vs_getUV0Clut(0, 224, 480, 393) };
    static int textTpages[] = { vs_getTpage(512, 256, clut4Bit, semiTransparencyFull,
                                    ditheringOff),
        vs_getTpage(576, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(576, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(640, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(768, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(704, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(640, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(704, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(768, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(832, 256, clut4Bit, semiTransparencyFull, ditheringOff) };
    static int outlineUvs[] = { vs_getUV0Clut(0, 192, 480, 394),
        vs_getUV0Clut(0, 192, 480, 394), vs_getUV0Clut(0, 192, 480, 394),
        vs_getUV0Clut(128, 0, 480, 394), vs_getUV0Clut(144, 192, 480, 394),
        vs_getUV0Clut(160, 192, 480, 394), vs_getUV0Clut(160, 192, 480, 394),
        vs_getUV0Clut(128, 64, 480, 394), vs_getUV0Clut(128, 0, 480, 394),
        vs_getUV0Clut(128, 64, 480, 394) };
    static int outlineTpages[] = { vs_getTpage(0, 256, clut4Bit, semiTransparencyFull,
                                       ditheringOff),
        vs_getTpage(64, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(128, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(448, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(0, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(64, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(128, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(448, 256, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(448, 0, clut4Bit, semiTransparencyFull, ditheringOff),
        vs_getTpage(448, 0, clut4Bit, semiTransparencyFull, ditheringOff) };
    static int outlineWhs[] = { vs_getWH(144, 64), vs_getWH(160, 64), vs_getWH(160, 64),
        vs_getWH(128, 64), vs_getWH(112, 64), vs_getWH(96, 64), vs_getWH(96, 64),
        vs_getWH(128, 64), vs_getWH(128, 64), vs_getWH(128, 64) };
    static int outlineXys[] = { vs_getXY(120, 224), vs_getXY(112, 224),
        vs_getXY(112, 224), vs_getXY(128, 224), vs_getXY(136, 224), vs_getXY(144, 224),
        vs_getXY(144, 224), vs_getXY(128, 224), vs_getXY(128, 224), vs_getXY(128, 224) };

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
    typedef struct {
        u_long tag;
        VS_SPRT sprt;
    } tagsprt_t;

    static tagsprt_t sprtBuf[10];
    static char _[16] __attribute__((unused));

    int i;
    tagsprt_t* sprt;

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
    vibrationSetting = vs_main_vibrationEnabled + menuItemVibrationOff;
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
                func_800438C8(0);
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
    soundSetting = menuItemSoundStereo - (vs_main_soundMono * 3);
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
    memset(&vs_main_settings, 0, sizeof(vs_main_settings));
    vs_main_settings.unk2 = 0x2D8;
    vs_main_settings.information = 1;
    vs_main_settings.simpleMap = 3;
    *((int*)&vs_main_settings.timingWeaponArmor) |= 0x30;
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
    memset(&D_800619D8, 0, sizeof(D_800619D8));
    vs_main_stateFlags.unk1 = 1;
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
    static int D_80074C24[15][64] = {
        { 0x01010101, 0x00000000, 0x2731240F, 0x322A3124, 0x000000E7, 0x00000000,
            0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x2B373231, 0xFA2A312C,
            0x0000E706, 0x00000000, 0x00000000, 0x00000000, 0x00000003, 0x00000000,
            0x2B373231, 0xFA2A312C, 0x0000E706, 0x00000000, 0x00000000, 0x00000000,
            0x00000004, 0x00000000, 0x2B373231, 0xFA2A312C, 0x0000E706, 0x00000000,
            0x00000000, 0x00000000, 0x00000005, 0x00000000, 0x2B373231, 0xFA2A312C,
            0x0000E706, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000,
            0x2B373231, 0xFA2A312C, 0x0000E706, 0x00000000, 0x00000000, 0x00000000,
            0x00000007, 0x00000000, 0x2B373231, 0xFA2A312C, 0x0000E706, 0x00000000,
            0x00000000, 0x00000000, 0x00000008, 0x00000000, 0x2B373231, 0xFA2A312C,
            0x0000E706, 0x00000000, 0x00000000, 0x00000000 },
        { 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x01000000, 0x00000000,
            0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000000, 0x00000000,
            0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x03000000, 0x00000000,
            0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x04000000, 0x00000000,
            0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x05000000, 0x00000000,
            0x00000006, 0x00000000, 0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x06000000, 0x00000000, 0x00000007, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x07000000, 0x00000000, 0x00000008, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x08000000, 0x00000000, 0x02100E0E, 0x00883138, 0x00003138, 0x01FD0109,
            0x0000000A, 0x01030203, 0xFFFEFFFF, 0x0508FBFF, 0xFD050508, 0x000202FD,
            0x01010003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000 },
        { 0x03000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x04000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x05000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x06000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x07000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000, 0x09000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x0A000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x0B000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0C000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0D000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x0E000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0F000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x10000000, 0x01010060, 0xFF000100,
            0x01040000, 0x00010001, 0x00000000, 0x00000000, 0x00000000, 0x00020000,
            0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x00000000, 0x00000000,
            0x00000000, 0x00040000, 0x00000000, 0x00000000, 0x00000000, 0x00050000,
            0x00000000, 0x00000000, 0x00000000, 0x00060000, 0x00000000, 0x00000000,
            0x00000000, 0x00070000, 0x00000000, 0x00000000, 0x00000000, 0x00080000,
            0x00000000, 0x00000000, 0x00000000, 0x00090000, 0x00000000, 0x00000000,
            0x00000000, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x000B0000,
            0x00000000, 0x00000000, 0x00000000, 0x000C0000 },
        { 0x00000000, 0x00000000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000,
            0x00000000, 0x000E0000, 0x00000000, 0x00000000, 0x00000000, 0x000F0000,
            0x00000000, 0x00000000, 0x00000000, 0x00100000, 0x050041BF, 0x00000D16,
            0x00000D16, 0x000D0100, 0x00000100, 0x00000000, 0xFB020000, 0xFF050502,
            0x00FBFBFF, 0x01010002, 0x050041BF, 0x00000D16, 0x00000D16, 0x000D0100,
            0x00000100, 0x00000000, 0xFB020000, 0xFF050502, 0x00FBFBFF, 0x02020002,
            0x0200118F, 0x00000ED8, 0x00000ED8, 0x00080100, 0x00000000, 0x00000000,
            0xFB020000, 0xFF050502, 0x00FBFBFF, 0x03030002, 0x0300219F, 0x0000157C,
            0x0000157C, 0x000A0500, 0x00010100, 0x00000000, 0xFB020000, 0xFF050502,
            0x00FBFBFF, 0x04040002, 0x040031AF, 0x00000FD2, 0x00000FD2, 0x000C0100,
            0x00000000, 0x00000000, 0xFB020000, 0xFF050502 },
        { 0x00FBFBFF, 0x05050002, 0x070061DF, 0x00000000, 0x00000000, 0x00010000,
            0x00000000, 0xFB050000, 0x000005FB, 0x00000005, 0x00FB0500, 0x06070000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x07000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x09000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x0A000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x0B000000, 0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x0C000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0D000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x0E000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x0F000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x10000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00020000, 0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00040000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00050000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00060000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00070000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00080000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00090000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000A0000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x000B0000, 0x00000000, 0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000, 0x00000000, 0x000C0000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000D0000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000E0000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x000F0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00100000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00110000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00120000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00130000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00140000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000, 0x00150000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00160000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00170000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00180000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00190000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x001A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x001B0000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x001C0000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x001D0000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000 },
        { 0x00000000, 0x001E0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x001F0000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00200000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00210000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00220000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00230000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00240000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00250000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00260000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000 },
        { 0x00270000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00280000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00290000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x002A0000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002B0000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002C0000,
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x002D0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x002E0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x002F0000, 0x00000000, 0x00000000, 0x00000000,
            0x00000000, 0x00000000, 0x00000000, 0x00300000 },
        { 0x010A0143, 0x020A014B, 0x03050153, 0x04050154, 0x05050155, 0x06000000,
            0x07000000, 0x08000000, 0x09000000, 0x0A000000, 0x0B000000, 0x0C000000,
            0x0D000000, 0x0E000000, 0x0F000000, 0x10000000, 0x11000000, 0x12000000,
            0x13000000, 0x14000000, 0x15000000, 0x16000000, 0x17000000, 0x18000000,
            0x19000000, 0x1A000000, 0x1B000000, 0x1C000000, 0x1D000000, 0x1E000000,
            0x1F000000, 0x20000000, 0x21000000, 0x22000000, 0x23000000, 0x24000000,
            0x25000000, 0x26000000, 0x27000000, 0x28000000, 0x29000000, 0x2A000000,
            0x2B000000, 0x2C000000, 0x2D000000, 0x2E000000, 0x2F000000, 0x30000000,
            0x31000000, 0x32000000, 0x33000000, 0x34000000, 0x35000000, 0x36000000,
            0x37000000, 0x38000000, 0x39000000, 0x3A000000, 0x3B000000, 0x3C000000,
            0x3D000000, 0x3E000000, 0x3F000000, 0x40000000 }
    };
    static int _skillsLearned[8] = { 0x0074FE7F, 0x00000000, 0x00000000, 0x00000000,
        0xFFFDFD03, 0x007EFEFD, 0x00000000, 0xFFFFFFFF };

    int i;
    int j;
    char* v0;

    _initScreen(640, 240, 512, 0, 0, 0);
    i = 0x43F;
    v0 = ((char*)&vs_main_stateFlags) + i;
    do {
        *v0-- = 0;
    } while (--i >= 0);

    vs_main_memcpy(vs_main_skillsLearned, _skillsLearned, sizeof(_skillsLearned));
    vs_main_bzero(&D_8005FFD8, sizeof(D_8005FFD8));
    vs_main_bzero(&vs_main_gametime, sizeof(vs_main_gametime));
    vs_main_bzero(&vs_main_scoredata, sizeof(vs_main_scoredata));
    D_80060064 = 0;
    vs_main_bzero(D_80061078, sizeof(D_80061078));
    vs_main_bzero(&vs_main_artsStatus, sizeof(vs_main_artsStatus));

    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 3; ++j) {
            vs_main_scoredata.bossTimeTrialScores[i][j] &= 0xFF000000;
            vs_main_scoredata.bossTimeTrialScores[i][j] |= 0x800000;
            vs_main_scoredata.bossTimeTrialScores[i][j] &= 0x80FFFFFF;
            vs_main_scoredata.bossTimeTrialScores[i][j] &= 0x7FFFFFFF;
        }
    }

    for (i = 0; i < 1; ++i) {
        vs_main_bzero((char*)&D_80060068 + i * sizeof(D_80060068), 0x50);
    }

    vs_main_bzero(&D_80061068, sizeof(D_80061068));
    vs_main_memcpy(D_80060168, D_80074C24, sizeof(D_80060168));

    vs_gametime_tickspeed = 2;
    D_80061068.unk4 = (D_80061068.unk4 & 0xE0FF) | 0x400;
    D_80061068.unk6 = (D_80061068.unk6 & 0x83FF) | 0x800;
    D_80061068.unk2 = D_80061068.unk2 & 0x1FFF;
    D_80061068.unk4 = (D_80061068.unk4 & 0x9FFF) | 0x4000;
}

static void _setTitleExitFlags(int cause)
{
    switch (cause) {
    case 0: // New Game
        vs_main_stateFlags.unkC = 0;
        vs_main_stateFlags.unkD = 0;
        D_80061068.unk0 = 1;
        D_80061068.unk1 = 0;
        return;
    case 3: // Timeout cutscene1
        vs_main_stateFlags.unkC = 0;
        vs_main_stateFlags.unkD = 1;
        vs_main_stateFlags.unkE = 1;
        D_80061068.unk0 = 0x14;
        D_80061068.unk1 = 0;
        return;
    case 4: // Timeout cutscene2
        vs_main_stateFlags.unkC = 0;
        vs_main_stateFlags.unkD = 1;
        vs_main_stateFlags.unkE = 1;
        D_80061068.unk0 = 2;
        D_80061068.unk1 = 1;
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
