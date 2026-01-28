#include "common.h"
#include "../SLUS_010.40/sfx.h"
#include "../MAINMENU.PRG/C48.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "../../BATTLE/BATTLE.PRG/func_8006B57C_t.h"
#include "../../build/assets/MENU/MENU7.PRG/container.h"
#include "gpu.h"
#include "../../assets/MENU/MCMAN.BIN.h"
#include "vs_string.h"
#include "lbas.h"
#include <memory.h>
#include <libapi.h>
#include <sys/file.h>
#include <string.h>
#include <libetc.h>

enum slotState_e {
    slotStateUnavailable = 0,
    slotStateAvailable = 1,
    slotStateTemporary = 2,
    slotStateInUse = 3
};

enum testMemcardEvents_e {
    memcardInternalEventIoEnd,
    memcardInternalEventError,
    memcardInternalEventTimeout,
    memcardInternalEventUnformatted,
    memcardInternalEventNone,
};

enum memcardEvents_e { memcardEventsSw, memcardEventsHw = 4 };

enum memcardEventHandler_e {
    memcardEventPending = 0,
    memcardEventIoEnd = 1,
    memcardEventTimeout = 2,
    memcardEventUnformatted = 3
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
    int key;
    saveBase_t base;
} savedata_unk180_2_t;

typedef struct {
    savedata_unk180_2_t unk180;
    stats_t stats;
    char checksums[0x5C];
} savedata_unk180_t;

typedef struct {
    saveFileInfo_t fileInfo;
    char unk80[0x80];
    char unk100[0x80];
    savedata_unk180_t unk180;
    char stateFlags[0x440];
    char unk640[0x20];
    char mapStatus[0x48];
    vs_main_settings_t unk6A8;
    D_80060068_t unk6C8;
    char unk7C8[15][256];
    char unk16C8[0xB0];
    D_80061068_t unk1778;
    vs_main_scoredata_t unk1784;
    int unk1898;
    char unk189C[0x520];
    vs_main_artsStatus_t artsStatus;
    vs_menu_containerData containerData;
    char unk59E0[0x220];
} savedata_t;

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

typedef struct {
    u_long locationCluts[2][128];
    char unk400[7][32];
    char unk4E0[22][128];
    char unkFE0[0x20];
    u_short textTable[0x800];
    saveFileInfo_t saveFileInfo[5];
    struct DIRENTRY _dirEntBuf;
} mcdata_t;

char const* _memcardFilenameTemplate = "bu00:BASLUS-01040VAG0";

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

static void _resetMemcardEvents(int type)
{
    int i;

    for (i = 0; i < 4; ++i) {
        TestEvent(_memcardEventDescriptors[i + type]);
    }
}

static void _drawImage(int xy, void* arg1, int wh)
{
    RECT rect;

    *(int*)&rect.x = xy;
    *(int*)&rect.w = wh;
    LoadImage(&rect, arg1);
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
    static char _filename[32];

    memset(_filename, 0, ' ');
    strcpy(_filename, _memcardFilenameTemplate);
    _filename[2] = port == 0 ? '0' : '1';
    _filename[20] = fileNo + '0';
    return _filename;
}

static char* _memcardMakeTempFilename(int port, int fileNo)
{
    static char _filename[32];

    memset(_filename, 0, ' ');
    strcpy(_filename, _memcardFilenameTemplate);
    _filename[2] = port == 0 ? '0' : '1';
    _filename[20] = fileNo + 'A' - 1;
    return _filename;
}

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
        if ((filename != 0) && (_memcardFileNumberFromFilename(filename) != 0)
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
        _memcardFiles[i] = 0;
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

        if (file == 0) {
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

    _rMemcpy(&vs_main_stateFlags, spmcimg[1].stateFlags, sizeof(vs_main_stateFlags));
    _rMemcpy(vs_main_skillsLearned, spmcimg[1].unk640, sizeof(vs_main_skillsLearned));
    _rMemcpy(&vs_main_mapStatus, spmcimg[1].mapStatus, sizeof(vs_main_mapStatus));
    _rMemcpy(&vs_main_settings, &spmcimg[1].unk6A8, sizeof(vs_main_settings));
    _rMemcpy(&D_80060068, &spmcimg[1].unk6C8, sizeof(D_80060068));
    _rMemcpy(&vs_battle_inventory, spmcimg[1].unk7C8, sizeof(vs_battle_inventory));
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
    static const u_short D_8010286C[] = { 0x7582, 0x6082, 0x6682, 0x7182, 0x6082, 0x6D82,
        0x7382, 0x4081, 0x7282, 0x7382, 0x6E82, 0x7182, 0x7882, 0x4081, 0x6582, 0x6882,
        0x6B82, 0x6482, 0x4081, 0x5082, 0x4081, 0x4081, 0x4081, 0x4F82, 0x4F82, 0x4681,
        0x4F82, 0x4F82, 0x4681, 0x4F82, 0x4F82, 0x4081 };

    long i;
    int j;
    int var_a0;
    u_short const* s0 = D_8010286C;
    savedata_t* savedata = (savedata_t*)_spmcimg;
    savedata_t* savedata2 = savedata + 1;
    savedata_t* savedata3 = savedata;
    savedata_unk180_t* s5 = &savedata->unk180;

    func_80042CB0();
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
        vs_main_settings.slotState = vs_battle_encode(0x20);
        if (vs_main_settings.slotState < 3) {
            vs_main_settings.slotState = 0x17385CA9;
        }
        if (!(D_800F4EA0 & 0x400)) {
            memset(&savedata2->containerData, 0, sizeof(savedata2->containerData));
        }
    }

    vs_main_settings.key = vs_battle_encode(0x20);
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
    if (vs_main_settings.unk1A < 9999) {
        ++vs_main_settings.unk1A;
    }

    s5->unk180.base.unk8 = 0x20000107;
    s5->stats.gameTime.t = vs_main_gametime.t;
    s5->stats.currentHP = D_80060068.unk0.currentHP;
    s5->stats.maxHP = D_80060068.unk0.maxHP;
    s5->stats.saveCount = vs_main_settings.saveCount;
    s5->stats.unk12 = vs_main_settings.unk1A;
    s5->stats.saveLocation = D_800F4E6B;
    s5->stats.mapCompletion = vs_battle_getMapCompletion();
    s5->stats.clearCount = vs_main_stateFlags.clearCount;
    s5->stats.currentMP = D_80060068.unk0.currentMP;
    s5->stats.maxMP = D_80060068.unk0.maxMP;
    _rMemcpy(savedata->stateFlags, &vs_main_stateFlags, sizeof(savedata->stateFlags));
    _rMemcpy(savedata->unk640, vs_main_skillsLearned, sizeof(savedata->unk640));
    _rMemcpy(savedata->mapStatus, &vs_main_mapStatus, sizeof(savedata->mapStatus));
    _rMemcpy(&savedata->unk6A8, &vs_main_settings, sizeof(savedata->unk6A8));
    _rMemcpy(&savedata->unk6C8, &D_80060068, sizeof(savedata->unk6C8));
    _rMemcpy(savedata->unk7C8, &vs_battle_inventory, sizeof(savedata->unk7C8));
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
        _spmcimg[i] += vs_battle_encode(8);
    }
}

static char _loadSaveDataErrorOffset;
static char _1[1] __attribute__((unused));
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
    static char _[2] __attribute__((unused));
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
        fd = open(filename, 0x8000 | 1);
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
        fd = open(_memcardMakeTempFilename(port, file), 0x8000 | 0x0002);
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

void _drawHPMP(int xy, enum statType_e stat, u_int currentValue, u_int maxValue)
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
    _memoryCardMessage = 0;
    _selectCursorColor = 0;
    _selectCursorXy = 0;
    _fileProgressCounter = 0;
    _fileMenuScreenFade = 0;
    _fileProgressTarget = 0x180;
    memset(&_fileMenuElements, 0, sizeof(_fileMenuElements));
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

    if (text != 0) {
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
    memset(&_fileMenuElements[id], 0, sizeof(_fileMenuElements[id]));
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
        vs_mainmenu_setMessage(
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

enum maskedHandler_e {
    memcardMaskedHandlerError = -1,
    memcardMaskedHandlerPending = 0,
    memcardMaskedHandlerComplete = 1
};

static enum maskedHandler_e maskedHandler(int portMask)
{
    static char mask;
    static char _[5] __attribute__((unused));

    int event;

    if (portMask != 0) {
        _memcardEventHandler(portMask & 3);
        mask = (portMask >> 4);
        return memcardMaskedHandlerPending;
    }
    event = _memcardEventHandler(0);
    if (event != memcardEventPending) {
        switch (event & mask) {
        case memcardEventIoEnd:
            return memcardMaskedHandlerComplete;
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
        return memcardMaskedHandlerError;
    }
    return memcardMaskedHandlerPending;
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
    if (_memoryCardMessage != 0) {
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

static int _promptOverwrite(int arg0)
{
    static int confirmed;
    static char state;
    static char initialized;

    int temp_v0;

    if (arg0 != 0) {
        initialized = 1;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_BIN_OFFSET_overwritePrompt);
        _promptConfirm(1);
        state = 0;
        return 0;
    }
    switch (state) {
    case 0:
        temp_v0 = _promptConfirm(0);
        confirmed = temp_v0;
        if (temp_v0 != 0) {
            state = 1;
        }
        break;
    case 1:
        if (_fileMenuElementsActive() != 0) {
            return confirmed;
        }
        break;
    }
    return 0;
}

static int _promptFormat(int initPort)
{
    enum state { promptConfirm = 0, initEvents = 1, handleEvents = 2, format = 3 };

    static char state;
    static char port;
    static char _[8] __attribute__((unused));

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
    static char slot;
    static char leaveTimer;

    fileMenuElements_t* element;
    int val;
    int saveId;
    int i;

    if (initPort != 0) {
        port = initPort;
        slot = _findCurrentSaveOnActiveMemcard();
        if (slot) {
            --slot;
        }
        page = 0;
        if (slot == 4) {
            page = 2;
            slot = 2;
        } else if (slot != 0) {
            page = slot - 1;
            slot = 1;
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
            val = slot + page;
            if (vs_main_buttonsPressed.all & PADRright) {
                if (_saveFileInfo[val].unk4.base.slotState != slotStateUnavailable) {
                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                    _fileMenuElements[val + 5].selected = 1;
                    _selectCursorXy = 0;
                    maskedHandler(port + memcardEventMaskAll);
                    state = slotSelected;
                    break;
                } else {
                    func_800C02E0();
                }
            }
            if (vs_main_buttonRepeat & PADLup) {
                if (slot == 0) {
                    if (page != 0) {
                        --page;
                    }
                } else {
                    --slot;
                }
            }
            if (vs_main_buttonRepeat & PADLdown) {
                if (slot == 2) {
                    if (page < 2) {
                        ++page;
                    }
                } else {
                    ++slot;
                }
            }
            if (val != (slot + page)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            }
            _selectCursorXy = vs_getXY(24, slot * 40 + 62);
            _fileMenuElements[val + 5].selected = 1;
        }
        break;
    case slotSelected:
        val = maskedHandler(0);
        if (val != memcardMaskedHandlerPending) {
            if (_memoryCardMessage == (char*)(_textTable + VS_MCMAN_BIN_OFFSET_noData)) {
                _promptFormat(port);
                state = format;
            } else if (val > memcardMaskedHandlerError) {
                val = slot + page;
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
                maskedHandler(port + memcardEventMaskAll);
                state = initOverwrite;
            } else {
                state = handleInput;
            }
        }
        break;
    case initOverwrite:
        val = maskedHandler(0);
        if (val != memcardMaskedHandlerPending) {
            if (val > memcardMaskedHandlerError) {
                _dataNotSaved |= (_findCurrentSaveOnActiveMemcard() == (slot + page + 1));
                state = save;
            } else {
                state = leaveWithTimer;
            }
        }
        break;
    case save:
        val = slot + page;
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
            vs_main_stateFlags.doorEntered = 0;
            saveId = slot + page;
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
            } else if (_createSaveFile(port, page + slot + 1) != 0) {
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
                _memcardFiles[i] = 0;
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
        vs_mainmenu_setMessage((char*)&clear);
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
            vs_mainmenu_setMessage((char*)&clear);
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
            vs_mainmenu_setMessage((char*)&clear);
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
    static char slot;
    static char leaveTimer;
    static char completeTimer;

    fileMenuElements_t* element;
    int currentSlot;
    int i;

    if (initPort != 0) {
        port = initPort;
        slot = _getNewestSaveFile();
        page = 0;
        if (slot == 4) {
            page = 2;
            slot = 2;
        } else if (slot != 0) {
            page = slot - 1;
            slot = 1;
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

        currentSlot = slot + page;

        if (vs_main_buttonsPressed.all & PADRright) {
            if (_saveFileInfo[currentSlot].unk4.base.slotState >= slotStateInUse) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                _fileMenuElements[currentSlot + 5].selected = 1;
                _selectCursorXy = 0;
                maskedHandler(port + memcardEventMaskAll);
                state = startLoad;
                break;
            }
            vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
        }
        if (vs_main_buttonRepeat & PADLup) {
            if (slot == 0) {
                if (page != 0) {
                    --page;
                }
            } else {
                --slot;
            }
        }
        if (vs_main_buttonRepeat & PADLdown) {
            if (slot == 2) {
                if (page < 2) {
                    ++page;
                }
            } else {
                ++slot;
            }
        }
        if (currentSlot != (slot + page)) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
        }
        _selectCursorXy = ((slot * 40 + 62) << 16) | 24;
        _fileMenuElements[currentSlot + 5].selected = 1;
        break;
    case startLoad:
        currentSlot = maskedHandler(0);
        if (currentSlot != memcardMaskedHandlerPending) {
            if (currentSlot >= memcardMaskedHandlerPending) {
                int new_var;
                _loadSaveData(((slot + page) + 1) | (new_var = ((port - 1) << 16) | 256));
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
        maskedHandler(port + memcardEventMaskIgnoreNoEvent);
        state = pollEvents;
        break;

    case pollEvents:
        i = maskedHandler(0);
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
    new_var2 = vs_main_allocHeapR(sizeof(*_opMcImg));
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
            vs_battle_drawImage(vs_getXY(832, 256), gameOverBin, vs_getWH(24, 128));
            vs_battle_drawImage(vs_getXY(832, 384), _menuItemTextClut, vs_getWH(48, 1));
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

static int _displayGameOverScreen(int init)
{
    extern u_long* D_1F800000[];
    static short clut[2][16];
    static int color1;
    static int color2;
    static int color3;
    static int blendFactor1;
    static int blendFactor2;
    static int selectedOption;
    static char _[8];

    u_long* prim;
    u_long* nextPrim = D_1F800000[2];

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
        prim = D_1F800000[0];
        prim[0] = (*nextPrim & 0xFFFFFF) | 0x04000000;
        prim[1] = vs_getTpage(0, 0, direct16Bit, semiTransparencySubtract, ditheringOff);
        prim[3] = vs_getXY(0, 0);
        prim[4] = vs_getWH(0x140, 0xF0);
        prim[2] = vs_getRGB0Raw(primTileSemiTrans, (color1 + 128) * 0x020202);
        *nextPrim = ((u_long)prim << 8) >> 8;
        D_1F800000[0] = prim + 5;
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
    vs_battle_drawImage(vs_getXY(832, 384), &clut, vs_getWH(32, 1));

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

int vs_menu7_gameOver(char* state)
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

    static u_short D_8010AB80[256];
    static vs_main_settings_t settingsBackup;
    static int resetDelay;
    static int D_8010ADA4;

    RECT rect;
    int option;

    switch (*state) {
    case init:
        func_8007E0A8(0x1F, 1, 6);
        func_8008A4DC(0);
        settingsBackup = vs_main_settings;
        D_8010ADA4 = vs_main_stateFlags.unk1;
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
        StoreImage(&rect, (u_long*)D_8010AB80);
        DrawSync(0);
        func_80048A64(D_8010AB80, 3, 0, 256);
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
            vs_main_stateFlags.unk1 = D_8010ADA4;
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
#include "../../assets/MENU/MENU7.PRG/container.vsString"
};

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
        menuItem->x = 194;
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
        menuItem->x = 194;
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
                func_800C02E0();
            }
        }
        if (buttons & (PADRup | PADRright | PADRdown)) {
            if ((selectedOption != 0) || (buttons & (PADRup | PADRdown))) {
                vs_battle_playMenuLeaveSfx();
                func_800FA8E0(40);
                selectedOption = -1;
            } else {
                vs_battle_playMenuSelectSfx();
                func_800FA8E0(0);
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
            vs_battle_inventoryWeapon* weapon = &target->weapons[i];
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
            vs_battle_inventoryBlade* blade = &target->blades[i];
            vs_battle_copyAligned(blade, &source->blades[sourceIndex - 1], sizeof *blade);
            blade->index = i + 1;
            if (blade->unk2A != 0) {
                blade->unk2A = targetIndices->weapons[blade->unk2A - 1];
            }
        }
    }

    for (i = 0; i < 64; ++i) {
        sourceIndex = toCopy->grips[i];
        if (sourceIndex != 0) {
            vs_battle_inventoryGrip* grip = &target->grips[i];
            vs_battle_copyAligned(grip, &source->grips[sourceIndex - 1], sizeof *grip);
            grip->index = i + 1;
            if (grip->unkC != 0) {
                grip->unkC = targetIndices->weapons[grip->unkC - 1];
            }
        }
    }

    for (i = 0; i < 32; ++i) {
        sourceIndex = toCopy->shields[i];
        if (sourceIndex != 0) {
            vs_battle_inventoryShield* shield = &target->shields[i];
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
            vs_battle_inventoryArmor* armor = &target->armor[i];
            vs_battle_copyAligned(armor, &source->armor[sourceIndex - 1], sizeof *armor);
            armor->index = i + 1;
        }
    }

    for (i = 0; i < 192; ++i) {
        sourceIndex = toCopy->gems[i];
        if (sourceIndex != 0) {
            vs_battle_inventoryGem* gem = &target->gems[i];
            vs_battle_copyAligned(gem, &source->gems[sourceIndex - 1], sizeof *gem);
            gem->index = i + 1;
            if (gem->unk18 != 0) {
                if (gem->unk18 & 0x80) {
                    gem->unk18 =
                        targetIndices->shields[(gem->unk18 & 0xFFFF) - 0x81] | 0x80;
                } else {
                    gem->unk18 = targetIndices->weapons[gem->unk18 - 1];
                }
            }
        }
    }

    for (i = 0; i < 256; ++i) {
        sourceIndex = toCopy->items[i];
        if (sourceIndex != 0) {
            vs_battle_inventoryItem* item = &target->items[i];
            vs_battle_rMemcpy(item, &source->items[sourceIndex - 1], sizeof *item);
            item->index = i + 1;
        }
    }

    vs_main_freeHeapR(targetIndices);
}

int vs_menu7_saveContainerMenu(char* state)
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
        D_80102578 = ((*(u_int*)&vs_main_settings) >> 4) & 1;
        D_8010245C = vs_main_allocHeapR(sizeof(*D_8010245C));
        vs_battle_rMemzero(D_8010245C, sizeof(*D_8010245C));
        func_800FBD80(16);
        func_800C8E04(1);
        _promptYesNo(5);
        vs_mainmenu_setMessage(
            (char*)&_containerStrings[VS_container_OFFSET_checkContainer]);
        *state = 1;
        break;
    case 1:
        option = _promptYesNo(0);
        if (option != 0) {
            if (option >= 0) {
                vs_battle_menuItem_t* menuItem;
                _initMemcard(1);
                func_800FFB68(1);
                func_800FFA88(2);
                menuItem = vs_battle_setMenuItem(0, 0x140, 0x12, 0x7E, 8,
                    (char*)&_containerStrings[VS_container_OFFSET_container]);
                menuItem->state = 2;
                menuItem->x = 180;
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
            func_80100414(0x7FE, 0x80);
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
                vs_mainmenu_setMessage((char*)message);
                *state = 4;
            } else {
                _loadSaveData((option & 7) | ((option & 0x10) << 0xC));
                *state = 6;
            }
        }
        break;
    case 4:
        if (vs_main_buttonsPressed.pad[0].low != 0) {
            vs_mainmenu_setMessage(
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
            vs_mainmenu_setMessage((char*)message);
            *state = 4;
        }
        break;
    case 7:
        vs_battle_memcpy(
            D_8010245C->unk0, &vs_battle_inventory, sizeof(D_8010245C->unk0));
        vs_battle_memcpy(&D_8010245C->unkF00, &D_800619D8, sizeof(D_8010245C->unkF00));
        vs_battle_memcpy(
            &D_8010245C->unkFB0, (_spmcimg + 0x79E0), sizeof(D_8010245C->unkFB0));
        _shutdownMemcard();
        *state = 8;
        vs_battle_menuState.returnState = vs_battle_menuState.currentState;
        vs_battle_menuState.currentState = 14;
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
                func_800C8E04(1);
                if (option == 1) {
                    _promptYesNo(1);
                    vs_mainmenu_setMessage(
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
            &D_8010245C->unkC430.data, &D_8010245C->unkC430.indices);
        _showSaveMenu(2);
        *state = 11;
        break;
    case 11:
        option = _showSaveMenu(0);
        if (option != 0) {
            if ((_dataNotSaved == 0) && (option < 0)) {
                func_800C8E04(1);
                _promptYesNo(1);
                vs_mainmenu_setMessage(
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
    case 13: {
        char v0 = (*(int*)&vs_main_settings);
        char v1 = D_80102578 & 1;
        *(int*)&vs_main_settings = (*(int*)&vs_main_settings & ~0x10) | (v1 * 0x10);
        vs_battle_memcpy(
            &vs_battle_inventory, D_8010245C->unk0, sizeof(D_8010245C->unk0));
        vs_battle_memcpy(&D_800619D8, &D_8010245C->unkF00, sizeof(D_8010245C->unkF00));
    }
        /* fallthrough */
    case 14:
        func_8008A4DC(1);
        func_800CB654(0);
        D_800EB9B0 = 0;
        func_800FA8E0(0x28);
        func_80100414(-4, 0x80);
        *state = 15;
        break;
    case 15:
        func_800FFA88(0);
        func_800FFBA8();
        func_800FFB68(0);
        if (vs_mainmenu_ready() != 0) {
            _shutdownMemcard();
            *state = 16;
        }
        break;
    case 16:
        if ((func_800CD064(7) == 0) && (D_801022D8 == 0)) {
            vs_main_freeHeapR(D_8010245C);
            *state = init;
            return 1;
        }
        break;
    }
    return 0;
}

static void _drawPlayTime(void)
{
    extern u_long* D_1F800000[];
    static char* _playTime = "00:00:00:00";

    char time[4];
    int digits;
    int i;

    *(int*)&time = vs_main_gametime.all;
    if (time[3] >= 100) {
        *(int*)&time = 0;
        time[3] = 0;
        vs_battle_renderTextRaw("1", 0xC800D8, D_1F800000[1] - 5);
    } else {
        time[0] = ((((time[0] << 14) + vs_battle_encode(15)) * 5u) >> 14) / 3;
    }
    for (i = 0; i < 4; ++i) {
        digits = vs_battle_toBCD(time[i]);
        // BUG: invalid write to .rodata
        _playTime[9 - i * 3] = (digits >> 4) + 48;
        _playTime[10 - i * 3] = (digits & 0xF) + 48;
    }
    vs_battle_renderTextRaw(_playTime, 0xC800E0, D_1F800000[1] - 5);
    vs_battle_renderTextRaw("PLAY    TIME", 0xBC00E0, D_1F800000[1] - 5);
}

int vs_menu7_dataMenu(char* state)
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
                func_800FA8E0(6);
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
                func_800FA8E0(0x28);
                if (row == -2) {
                    *state = 12;
                } else {
                    *state = 11;
                }
            }
        } else {
            if (((D_800F4E6B != 0) && (vs_main_stateFlags.unkA7 != 0))
                && (func_801008B0() == 0)) {
                func_800C8E04(1);
                D_800F514C = 11;
            } else {
                D_800F514C = 0;
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
        func_800FFA88(0);
        func_800FFBA8();
        func_800FFB68(0);
        *state = 13;
        break;

    case 12:
        func_800FFA88(0);
        func_800FFBA8();
        func_800FFB68(0);
        *state = 14;
        break;

    case 13:
    case 14:
        if (D_801022D8 != 0) {
            break;
        }
        _shutdownMemcard();
        if (*state == 14) {
            vs_battle_menuState.currentState = 7;
        }
        *state = none;
        return 1;
    }

    return 0;
}
