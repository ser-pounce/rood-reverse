#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../SLUS_010.40/sfx.h"
#include "../MAINMENU.PRG/278.h"
#include "../MAINMENU.PRG/413C.h"
#include "../MAINMENU.PRG/8170.h"
#include "../../BATTLE/BATTLE.PRG/146C.h"
#include "../../BATTLE/BATTLE.PRG/573B8.h"
#include "../../BATTLE/BATTLE.PRG/5BF94.h"
#include "gpu.h"
#include "mcman.h"
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
    u_short containerData[0x1C00];
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
    D_8005FEA0_t unk1784;
    int unk1898;
    char unk189C[0x520];
    char unk1DBC[0x24];
    containerData_t containerData;
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

void func_800C02E0();
void func_800C02E8();
void func_800C02F0();
void func_800C02F8();
signed char* func_800C8E48(int);
char func_800CCD40(char, int);
void func_800FA8E0(int);
int func_800FA9D0();

extern char const* _memcardFilenameTemplate;

extern saveFileInfo_t* _saveFileInfo;
extern fileMenuElements_t _fileMenuElements[10];
extern u_short _fileProgressTarget;
extern int _fileProgressCounter;
extern int _selectCursorXy;
extern char* _memoryCardMessage;
extern u_char _selectCursorColor;
extern char _fileMenuScreenFade;
extern long _memcardEventDescriptors[8];
extern int D_8010A2E4[];
extern int D_8010A30C[];
extern u_short _containerOffsets[];
extern struct DIRENTRY* _memcardFiles[15];
extern primBuf_t _primBuf;
extern char* _spmcimg;
extern u_short* _textTable;
extern u_short D_8010A930[];
extern u_int* D_8010AB10;
extern char _isSaving;
extern vs_main_CdQueueSlot* D_8010AB04;
extern savedata_t* _opMcImg;
extern struct DIRENTRY* _dirEntBuf;
extern u_short D_8010A9D0;
extern u_short D_8010A9D4;
extern char D_8010AA2A;
extern int D_8010ADA8;
extern char D_8010ADAC;
extern char D_8010ADAD;
extern mcdata_t* _mcData;
extern vs_main_settings_t D_8010AD80;
extern char D_80061599;
extern signed char D_8006163C;
extern u_short D_8010AB80[];
extern int D_8010ADA0;
extern int D_8010ADA4;
extern char D_8006163F;
extern char D_800F4F70;
extern short D_8010AB20[];
extern int D_8010AB60;
extern int D_8010AB64;
extern int D_8010AB68;
extern int D_8010AB6C;
extern int D_8010AB70;
extern int D_8010AB74;
extern u_int* D_1F800000[];

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
    extern char _filename0[32];

    memset(_filename0, 0, ' ');
    strcpy(_filename0, _memcardFilenameTemplate);
    _filename0[2] = port == 0 ? '0' : '1';
    _filename0[20] = fileNo + '0';
    return _filename0;
}

static char* _memcardMakeTempFilename(int port, int fileNo)
{
    extern char _filename1[32];

    memset(_filename1, 0, ' ');
    strcpy(_filename1, _memcardFilenameTemplate);
    _filename1[2] = port == 0 ? '0' : '1';
    _filename1[20] = fileNo + 'A' - 1;
    return _filename1;
}

static u_int _getNewestSaveFile()
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

static int _findCurrentSaveOnActiveMemcard()
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

INCLUDE_RODATA("build/src/MENU/MENU7.PRG/nonmatchings/260", D_80102800);

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
    enum _memcardEventHandlerState {
        init = 0,
        ready = 1,
        unformatted = 2,
        confirmed = 3,
        loadReady = 4,
        loaded = 5,
    };

    extern char _memcardEventHandlerState;
    extern char _memcardEventHandlerPort;
    extern char _memcardEventHandlerInitTimeout;
    extern char _memcardEventHandlerTimeout;
    extern char _memcardEventHandlerEventType;

    int event;

    if (initPort != 0) {
        _memcardEventHandlerPort = (initPort - 1) * 16;
        _memcardEventHandlerState = init;
        _memcardEventHandlerInitTimeout = 0;
        return memcardEventPending;
    }
    switch (_memcardEventHandlerState) {
    case init:
        if (++_memcardEventHandlerInitTimeout >= 4) {
            return memcardEventTimeout;
        }
        _resetMemcardEvents(memcardEventsSw);
        if (_card_info(_memcardEventHandlerPort) == 0) {
            break;
        }
        _memcardEventHandlerState = ready;
        _memcardEventHandlerTimeout = 0;
        _memcardEventHandlerEventType = memcardEventsSw;
        // fallthrough
    case ready:
        switch (_testMemcardEvents(memcardEventsSw)) {
        case memcardInternalEventIoEnd:
            _memcardEventHandlerState = loadReady;
            break;
        case memcardInternalEventError:
        case memcardInternalEventTimeout:
            _memcardEventHandlerState = init;
            break;
        case memcardInternalEventUnformatted:
            _memcardEventHandlerState = unformatted;
            break;
        case memcardInternalEventNone:
            if (_memcardEventHandlerTimeout++ > 64) {
                _memcardEventHandlerState = init;
            }
            break;
        }
        break;
    case unformatted:
        _resetMemcardEvents(memcardEventsHw);
        if (_card_clear(_memcardEventHandlerPort) == 0) {
            break;
        }
        _memcardEventHandlerState = confirmed;
        _memcardEventHandlerTimeout = 0;
        _memcardEventHandlerEventType = memcardEventsHw;
        // fallthrough
    case confirmed:
        do {
            event = _testMemcardEvents(memcardEventsHw);
        } while (event == memcardInternalEventNone);
        if (event == memcardInternalEventIoEnd) {
            _memcardEventHandlerState = loadReady;
            break;
        }
        if (event < memcardInternalEventIoEnd)
            break;
        if (event >= memcardInternalEventNone)
            break;
        _memcardEventHandlerState = init;
        break;
    case loadReady:
        _resetMemcardEvents(memcardEventsSw);
        if (_card_load(_memcardEventHandlerPort) == 0) {
            break;
        }
        _memcardEventHandlerState = loaded;
        _memcardEventHandlerTimeout = 0;
        // fallthrough
    case loaded:
        event = _testMemcardEvents(memcardEventsSw);
        switch (event) {
        case memcardInternalEventIoEnd:
            return _memcardEventHandlerEventType + memcardEventIoEnd;
        case memcardInternalEventError:
        case memcardInternalEventTimeout:
            _memcardEventHandlerState = init;
            break;
        case memcardInternalEventUnformatted:
            return _memcardEventHandlerEventType + memcardEventUnformatted;
        case memcardInternalEventNone:
            if (_memcardEventHandlerTimeout++ > 64) {
                _memcardEventHandlerState = init;
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

    _rMemcpy(D_80061598, spmcimg[1].unk200, sizeof(D_80061598));
    _rMemcpy(vs_main_skillsLearned, spmcimg[1].unk640, sizeof(vs_main_skillsLearned));
    _rMemcpy(D_8005FFD8, spmcimg[1].unk660, sizeof(D_8005FFD8));
    _rMemcpy(&vs_main_settings, &spmcimg[1].unk6A8, sizeof(vs_main_settings));
    _rMemcpy(&D_80060068, &spmcimg[1].unk6C8, sizeof(D_80060068));
    _rMemcpy(D_80060168, spmcimg[1].unk7C8, sizeof(D_80060168));
    _rMemcpy(&D_800619D8, spmcimg[1].unk16C8, sizeof(D_800619D8));
    _rMemcpy(&D_80061068, &spmcimg[1].unk1778, sizeof(D_80061068));
    _rMemcpy(&D_8005FEA0, &spmcimg[1].unk1784, sizeof(D_8005FEA0));
    D_80060064 = s4->unk1898;
    _rMemcpy(D_80061078, spmcimg[1].unk189C, sizeof(D_80061078));
    spmcimg2 = D_80060040;
    _rMemcpy(D_80060040, spmcimg[1].unk1DBC, sizeof(D_80060040));
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
                vs_main_settings.saveFileGeneration
                    = _saveFileInfo[i].unk4.base.generation;
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
    s5->stats.mapCompletion = func_8008E5F0();
    s5->stats.clearCount = D_80061598[0];
    s5->stats.currentMP = D_80060068.unk0.currentMP;
    s5->stats.maxMP = D_80060068.unk0.maxMP;
    _rMemcpy(savedata->unk200, D_80061598, sizeof(savedata->unk200));
    _rMemcpy(savedata->unk640, vs_main_skillsLearned, sizeof(savedata->unk640));
    _rMemcpy(savedata->unk660, D_8005FFD8, sizeof(savedata->unk660));
    _rMemcpy(&savedata->unk6A8, &vs_main_settings, sizeof(savedata->unk6A8));
    _rMemcpy(&savedata->unk6C8, &D_80060068, sizeof(savedata->unk6C8));
    _rMemcpy(savedata->unk7C8, D_80060168, sizeof(savedata->unk7C8));
    _rMemcpy(savedata->unk16C8, &D_800619D8, sizeof(savedata->unk16C8));
    _rMemcpy(&savedata->unk1778, &D_80061068, sizeof(savedata->unk1778));
    _rMemcpy(&savedata->unk1784, &D_8005FEA0, sizeof(savedata->unk1784));
    _rMemcpy(&savedata->containerData, &savedata2->containerData,
        sizeof(savedata->containerData));
    savedata->unk1898 = D_80060064;
    _rMemcpy(savedata->unk189C, D_80061078, sizeof(savedata->unk189C));
    _rMemcpy(savedata->unk1DBC, D_80060040, sizeof(savedata->unk1DBC));

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

extern char _loadSaveDataErrorOffset;
extern u_short _filePreviousProgressCounter;
extern u_short _fileProgressPosition;

static int _loadSaveData(int portFileno)
{
    enum state { init = 0, reading = 1 };

    extern char _loadSaveDataState;
    extern char _loadSaveDataPort;
    extern char _loadSaveDataFile;
    extern char _loadSaveDataErrors;
    extern char _isTempSave;
    extern int _loadSaveDataFd;

    void* temp_s2 = (savedata_t*)_spmcimg + 1;

    if (portFileno != 0) {
        _loadSaveDataState = init;
        _loadSaveDataErrors = 0;
        _loadSaveDataErrorOffset = 0;
        _loadSaveDataPort = portFileno >> 0xC;
        _isTempSave = (portFileno >> 8) & 1;
        _loadSaveDataFile = portFileno & 0xF;
        _fileProgressPosition = 80;
        _filePreviousProgressCounter = 0;
        return 0;
    }

    switch (_loadSaveDataState) {
    case init: {
        int nBytes;
        char* filename;
        int new_var = 320;

        _fileProgressPosition += ((_fileProgressCounter - _filePreviousProgressCounter)
                                     * ((_loadSaveDataErrorOffset * 20)
                                         - (_fileProgressPosition - new_var)))
            / _fileProgressTarget;
        _loadSaveDataErrorOffset = _loadSaveDataErrors;
        _fileProgressTarget = 192 - (_isTempSave << 7);
        _filePreviousProgressCounter = _fileProgressCounter;

        memset(temp_s2, 0, sizeof(savedata_t));

        if (_loadSaveDataFile & 8) {
            filename = _memcardMakeTempFilename(_loadSaveDataPort, _loadSaveDataFile & 7);
        } else {
            filename = _memcardMakeFilename(_loadSaveDataPort, _loadSaveDataFile);
        }
        _loadSaveDataFd = open(filename, 0x8000 | 1);
        if (_loadSaveDataFd == -1) {
            ++_loadSaveDataErrors;
            break;
        }
        _resetMemcardEvents(memcardEventsSw);
        nBytes = sizeof(savedata_t);
        if (_isTempSave != 0) {
            nBytes = 0x2000;
        }
        if (read(_loadSaveDataFd, temp_s2, nBytes) == -1) {
            close(_loadSaveDataFd);
            ++_loadSaveDataErrors;
            break;
        }
        _loadSaveDataState = reading;
    }
        // fallthrough
    case reading: {
        int event = _testMemcardEvents(memcardEventsSw);
        if (event < memcardInternalEventNone) {
            close(_loadSaveDataFd);
            if (event == memcardInternalEventIoEnd) {
                return 1;
            }
            _loadSaveDataState = init;
            ++_loadSaveDataErrors;
        }
        break;
    }
    }
    return _loadSaveDataErrors == 3 ? -1 : 0;
}

static int _saveFile(int portFile)
{
    enum _saveFileState {
        init = 0,
        tempFileCreated = 1,
        readReady = 2,
        verifyPending = 3,
        fileVerified = 4
    };

    extern char _saveFileState;
    extern char _saveFileFile;
    extern char _saveFilePort;
    extern char _saveFileErrors;
    extern char _saveFileRenameErrors;
    extern int _saveFileFd;

    int temp_v1_2;
    int i;
    int temp_s3;

    if (portFile != 0) {
        _saveFileErrors = 0;
        _saveFileRenameErrors = 0;
        _loadSaveDataErrorOffset = 0;
        _saveFilePort = portFile >> 0xC;
        _saveFileFile = portFile & 7;
        _fileProgressPosition = 80;
        _filePreviousProgressCounter = 0;
        _saveFileState = _memcardSaveIdExists(_saveFileFile + 'A' - 1);
        return 0;
    }
    switch (_saveFileState) {
    case init:
        if (rename(_memcardMakeFilename(_saveFilePort, _saveFileFile),
                _memcardMakeTempFilename(_saveFilePort, _saveFileFile))
            != 0) {
            _saveFileErrors = 0;
            _saveFileRenameErrors = 0;
            _saveFileState = tempFileCreated;
        } else {
            ++_saveFileRenameErrors;
            _saveFileErrors = _saveFileRenameErrors >> 4;
        }
        break;
    case tempFileCreated:
        temp_v1_2 = ((_fileProgressCounter - _filePreviousProgressCounter)
                        * (320 - _fileProgressPosition))
            / _fileProgressTarget;
        _filePreviousProgressCounter = _fileProgressCounter;
        _fileProgressTarget = 384;
        _fileProgressPosition += temp_v1_2;
        _saveFileFd = open(
            _memcardMakeTempFilename(_saveFilePort, _saveFileFile), 0x8000 | 0x0002);
        ;
        if (_saveFileFd == -1) {
            ++_saveFileErrors;
            break;
        }
        _resetMemcardEvents(memcardEventsSw);
        if (write(_saveFileFd, _spmcimg, sizeof(savedata_t)) == -1) {
            close(_saveFileFd);
            ++_saveFileErrors;
            break;
        }
        _saveFileState = readReady;
        // fallthrough
    case readReady: {
        temp_s3 = _testMemcardEvents(memcardEventsSw);
        if (temp_s3 < memcardInternalEventNone) {
            close(_saveFileFd);
            if (temp_s3 == memcardInternalEventIoEnd) {
                _saveFileState = verifyPending;
                i = _fileProgressPosition;
                temp_s3 = _filePreviousProgressCounter;
                _loadSaveData((_saveFilePort << 12) | (_saveFileFile + 8));
                _fileProgressPosition = i;
                _filePreviousProgressCounter = temp_s3;
            } else {
                ++_saveFileErrors;
                _saveFileState = tempFileCreated;
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
        _saveFileState = fileVerified;
        break;
    case fileVerified:
        if (rename(_memcardMakeTempFilename(_saveFilePort, _saveFileFile),
                _memcardMakeFilename(_saveFilePort, _saveFileFile))
            == 0) {
            ++_saveFileRenameErrors;
            _saveFileErrors = (_saveFileRenameErrors >> 4);
            break;
        }
        return 1;
    }
    return _saveFileErrors == 3 ? -1 : 0;
}

static int _initMemcard(int init)
{
    enum state {
        none = 0,
        queueReady = 1,
        enqueued = 2,
    };

    extern u_short _eventSpecs[];
    extern vs_main_CdQueueSlot* _initMemcardCdQueueSlot;
    extern char _initMemcardState;

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
            _memcardEventDescriptors[i]
                = OpenEvent(event, _eventSpecs[i & 3], EvMdNOINTR, 0);
        }

        ExitCriticalSection();

        for (i = 0; i < 8; ++i) {
            EnableEvent(_memcardEventDescriptors[i]);
        }
        return 1;
    }
    return 0;
}

static void _shutdownMemcard()
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

static void _drawSprt(int xy, int uvClut, int wh, int tpage)
{
    DrawSync(0);
    _primBuf.tag = vs_getTag(_primBuf.prim.sprt, primAddrNull);
    _primBuf.prim.sprt.tpage = vs_getTpageRaw(tpage & 0x9FF);
    _primBuf.prim.sprt.r0g0b0code
        = vs_getRGB0Raw(primSprt, ((0x80 - (tpage >> 16)) * 0x010101));
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

static void _drawSaveInfoUI(int xy, enum vs_fileMenuUiIds_e id)
{
    _drawSprt(xy, D_8010A2E4[id], D_8010A30C[id], 0xC);
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
    extern char _digitDivisors[];

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
    rgb1 = ((((currentValueDigits * 255) + (red * currentValueFactor)) >> 6)
               | ((((currentValueDigits * 240)
                       + (((rgb0 >> 8) & 0xFF) * currentValueFactor))
                      >> 6)
                   << 8))
        | ((((2 * (currentValueDigits * 79)) + ((rgb0 >> 16) * currentValueFactor)) >> 6)
            << 16);

    DrawSync(0);
    _primBuf.tag = vs_getTag(_primBuf.prim.tilePoly, primAddrNull);
    _primBuf.prim.tilePoly.tile.tpage
        = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
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
    _primBuf.prim.tilePoly.polyG4.x3y3
        = xy + (currentValueDigits + _primBuf.prim.tilePoly.polyG4.x3y3);
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
        _primBuf.prim.polyG4_tpage.r0g0b0code
            = vs_getRGB0Raw(primPolyG4SemiTrans, gradientColor1);
        _primBuf.prim.polyG4_tpage.x0y0 = leftEdge | y;
        _primBuf.prim.polyG4_tpage.x1y1 = x | y;
        _primBuf.prim.polyG4_tpage.x2y2 = leftEdge | (y + vs_getXY(0, 32));
        _primBuf.prim.polyG4_tpage.tpage
            = vs_getTpage(0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
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
    _primBuf.prim.tile_tpage.tpage
        = vs_getTpage(0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
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

static void _initFileMenu()
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

static int _fileMenuElementsActive()
{
    int i;

    for (i = 0; i < 10 && _fileMenuElements[i].state < fileMenuElementStateAnimateX; ++i)
        ;
    return i == 10;
}

static int _printCharacter(u_int c, int x, int y, int clut)
{
    extern int glyphWidths[];

    if ((c >> 8) == 14) {
        return x + (char)c;
    }
    if (c != vs_char_space) {
        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.sprt, primAddrNull);
        _primBuf.prim.sprt.tpage
            = vs_getTpage(832, 0, clut4Bit, semiTransparencyFull, ditheringOff);
        _primBuf.prim.sprt.r0g0b0code = vs_getRGB0(primSprtSemtTrans, 128, 128, 128);
        _primBuf.prim.sprt.x0y0 = (u_short)x | y << 16;
        _primBuf.prim.sprt.wh = vs_getWH(12, 12);
        _primBuf.prim.sprt.u0v0clut
            = vs_getUV0Clut((c % 21) * 12, (c / 21) * 12, clut * 16 + 896, 222);
        DrawPrim(&_primBuf);
    }
    return x + glyphWidths[c];
}

void func_800FFC04(u_short*);
extern char _findCurrentSaveState;
extern char _findCurrentSaveSubState;

enum _findCurrentSave_e {
    findSaveTimeout = -2,
    findSaveNotFound = -1,
    findSavePending = 0
};

static int _findCurrentSave(int init)
{
    int port;
    int currentSave;
    int event;
    int realPort;

    if (init != 0) {
        _findCurrentSaveState = 0;
        _findCurrentSaveSubState = 0;
        return 0;
    }

    realPort = _findCurrentSaveState >> 1;
    port = realPort + 1;

    if ((_findCurrentSaveState & 1) == 0) {
        func_800FFC04(_textTable + _textTable[VS_MCMAN_INDEX_accessing0 - 1 + port]);
        _memoryCardMessage
            = (char*)(_textTable + _textTable[VS_MCMAN_INDEX_accessing0 - 1 + port]);
        _memcardEventHandler(realPort + 1);
        ++_findCurrentSaveState;
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
                if (_findCurrentSaveState != 1) {
                    if (_findCurrentSaveSubState != 0) {
                        return findSaveTimeout;
                    }
                } else {
                    _findCurrentSaveSubState = _findCurrentSaveState;
                }
            }
            ++_findCurrentSaveState;
        }
    }
    return _findCurrentSaveState != 4 ? findSavePending : findSaveNotFound;
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

static enum _memcardMaskedHandler_e _memcardMaskedHandler(int portMask)
{
    extern char _memcardMask;
    int event;

    if (portMask != 0) {
        _memcardEventHandler(portMask & 3);
        _memcardMask = (portMask >> 4);
        return memcardMaskedHandlerPending;
    }
    event = _memcardEventHandler(0);
    if (event != memcardEventPending) {
        switch (event & _memcardMask) {
        case memcardEventIoEnd:
            return memcardMaskedHandlerComplete;
        case memcardEventTimeout:
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_insertError);
            break;
        case memcardEventUnformatted:
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_noData);
            break;
        default:
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_removed);
            break;
        }
        return memcardMaskedHandlerError;
    }
    return memcardMaskedHandlerPending;
}

static void _printString(char* text, int x, int y, int clut)
{
    extern char arrowState;

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
        colourOut
            = (colourOut << 8) + ((component + (((colour2 >> 16) & 0xFF) * factor)) >> 3);
        colour2 <<= 8;
    }
    return colourOut;
}

static u_int _intepolateMenuItemBgColour(u_int outerFactor, u_int innerFactor)
{
    extern int colors1[];
    extern int colors2[];

    u_int color1;
    u_int color2;

    if (innerFactor < 9) {
        color1 = _interpolateRGB(
            vs_getRGB888(0, 65, 107), vs_getRGB888(25, 130, 108), innerFactor);
        color2 = _interpolateRGB(
            vs_getRGB888(0, 5, 51), vs_getRGB888(1, 40, 38), innerFactor);
    } else {
        color1 = colors1[((innerFactor >> 3) - 2)];
        color2 = colors2[((innerFactor >> 3) - 2)];
    }
    return _interpolateRGB(color1, color2, outerFactor);
}

extern char _menuElementStops[];
extern signed char _cursorFileOpSaturation[];

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
        _primBuf.prim.tilePoly.tile.tpage
            = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
        _primBuf.prim.tilePoly.tile.r0g0b0code = vs_getRGB0(primTile, 0, 0, 0);
        _primBuf.prim.tilePoly.tile.x0y0
            = ((element->x + 2) & 0xFFFF) | (element->y + 2) << 16;
        _primBuf.prim.tilePoly.tile.wh = element->w | (element->h << 0x10);
        _primBuf.prim.tilePoly.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4, var1);
        _primBuf.prim.tilePoly.polyG4.x0y0 = (u_short)element->x | y;
        _primBuf.prim.tilePoly.polyG4.r1g1b1 = var2;
        _primBuf.prim.tilePoly.polyG4.x1y1 = ((element->x + element->w) & 0xFFFF) | y;
        _primBuf.prim.tilePoly.polyG4.r2g2b2 = var1;
        _primBuf.prim.tilePoly.polyG4.x2y2
            = (u_short)element->x | ((element->y + element->h) << 0x10);
        _primBuf.prim.tilePoly.polyG4.r3g3b3 = var2;
        _primBuf.prim.tilePoly.polyG4.x3y3
            = ((element->x + element->w) & 0xFFFF) | ((element->y + element->h) << 0x10);
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
                _printString((char*)(_textTable + VS_MCMAN_OFFSET_inUse), element->x + 6,
                    element->y + 10, 3);
            } else if (slotState == slotStateAvailable) {
                if (_isSaving == 0) {
                    _printString((char*)(_textTable + VS_MCMAN_OFFSET_empty),
                        element->x + 6, element->y + 10, 3);
                } else {
                    _printString((char*)(_textTable + VS_MCMAN_OFFSET_new),
                        element->x + 6, element->y + 10, 0);
                }
            } else {
                y += 4 << 16;
                _printString((char*)&_textTable[_textTable[element->saveLocation
                                 + VS_MCMAN_INDEX_saveLocations]],
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
                    _fileProcessingAnim(_fileProgressPosition
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
        if (vs_main_buttonsPressed & PADRup) {
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
        _primBuf.prim.tile_tpage.tpage
            = vs_getTpage(0, 0, direct16Bit, semiTransparencySubtract, ditheringOff);
        _primBuf.prim.tile_tpage.x0y0 = vs_getXY(0, 0);
        _primBuf.prim.tile_tpage.wh = vs_getWH(320, 224);
        _primBuf.prim.tile_tpage.r0g0b0code = vs_getRGB0Raw(
            primTileSemiTrans, _fileMenuScreenFade * vs_getRGB888(8, 8, 8));
        DrawPrim(&_primBuf);
    }
}

static void _drawFileMenuBg()
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

    extern char _promptConfirmState;
    extern char _promptConfirmCancelled;

    fileMenuElements_t* temp_v0;
    int i;

    if (arg0 != 0) {
        _promptConfirmCancelled = 1;
        _promptConfirmState = initYes;
        return 0;
    }

    switch (_promptConfirmState) {
    case initYes:
    case initNo:
        temp_v0 = _initFileMenuElement(_promptConfirmState + 3,
            vs_getXY(-126 & 0xFFFF, _promptConfirmState * 16 + 18), vs_getWH(126, 12),
            (char*)&_textTable[_textTable[_promptConfirmState
                + VS_MCMAN_INDEX_yesIndent]]);
        temp_v0->state = 4;
        temp_v0->targetPosition = 0;
        ++_promptConfirmState;
        break;
    case waitForAnimation:
        _promptConfirmState += _fileMenuElementsActive();
        break;
    case handleInput:
        _fileMenuElements[_promptConfirmCancelled + 3].selected = 1;
        _fileMenuElements[4 - _promptConfirmCancelled].selected = 0;
        if (vs_main_buttonsPressed & (PADRdown | PADRright)) {
            _selectCursorXy = 0;
            for (i = 3; i < 5; ++i) {
                _fileMenuElements[i].state = 4;
                _fileMenuElements[i].targetPosition = -126;
            }
            if (vs_main_buttonsPressed & PADRright) {
                if (_promptConfirmCancelled == 0) {
                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                    return 1;
                }
            }
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            return -1;
        }
        if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            _promptConfirmCancelled = 1 - _promptConfirmCancelled;
        }
        _selectCursorXy = (_promptConfirmCancelled * 16 + 10) << 16;
        break;
    }
    return 0;
}

static int _promptOverwrite(int arg0)
{
    extern int _promptOverwriteConfirmed;
    extern char _promptOverwriteInitialized;
    extern char _promptOverwriteState;

    int temp_v0;

    if (arg0 != 0) {
        _promptOverwriteInitialized = 1;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_overwritePrompt);
        _promptConfirm(1);
        _promptOverwriteState = 0;
        return 0;
    }
    switch (_promptOverwriteState) {
    case 0:
        temp_v0 = _promptConfirm(0);
        _promptOverwriteConfirmed = temp_v0;
        if (temp_v0 != 0) {
            _promptOverwriteState = 1;
        }
        break;
    case 1:
        if (_fileMenuElementsActive() != 0) {
            return _promptOverwriteConfirmed;
        }
        break;
    }
    return 0;
}

static int _promptFormat(int initPort)
{
    enum _promptFormatState {
        promptConfirm = 0,
        initEvents = 1,
        handleEvents = 2,
        format = 3
    };

    extern char _promptFormatState;
    extern char _promptFormatPort;

    int val;

    if (initPort != 0) {
        _promptFormatPort = initPort;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_formatPrompt);
        _promptConfirm(1);
        _promptFormatState = promptConfirm;
        return 0;
    }

    switch (_promptFormatState) {
    case promptConfirm:
        val = _promptConfirm(0);

        if (val != 0) {
            if (val < 0) {
                _memoryCardMessage
                    = (char*)(_textTable + VS_MCMAN_OFFSET_formatCancelled);
                return -1;
            }

            _promptFormatState = initEvents;
        }
        return 0;
    case initEvents:
        if (_fileMenuElementsActive() != 0) {
            _memcardEventHandler(_promptFormatPort);
            _promptFormatState = handleEvents;
        }
        return 0;
    case handleEvents:
        val = _memcardEventHandler(0);

        if (val != 0) {
            if (val == memcardEventUnformatted) {
                _promptFormatState = format;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_formatting);
            } else {
                if (val == memcardEventTimeout) {
                    _memoryCardMessage
                        = (char*)(_textTable + VS_MCMAN_OFFSET_insertError);
                } else {
                    _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_removed);
                }
                return -1;
            }
        }
        return 0;
    case format:
        if (_card_format((_promptFormatPort - 1) * 16) == 0) {
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_formatFailed);
            return -1;
        }
        return 1;
    default:
        return 0;
    }
}

extern char _dataNotSaved;
extern char _containerDataEmpty;
extern char _backupMainSetting;

static int _showSaveFilesMenu(int initPort)
{
    enum _showSaveFilesMenuState {
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

    extern vs_main_settings_t _showSaveFilesMenuSettingsBackup;
    extern int _showSaveFilesMenuSaveSuccessful;
    extern char _showSaveFilesMenuState;
    extern char _showSaveFilesMenuPort;
    extern char _showSaveFilesMenuPage;
    extern char _showSaveFilesMenuFileSlot;
    extern char _showSaveFilesMenuLeaveTimer;

    fileMenuElements_t* element;
    int val;
    int saveId;
    int i;

    if (initPort != 0) {
        _showSaveFilesMenuPort = initPort;
        _showSaveFilesMenuFileSlot = _findCurrentSaveOnActiveMemcard();
        if (_showSaveFilesMenuFileSlot) {
            --_showSaveFilesMenuFileSlot;
        }
        _showSaveFilesMenuPage = 0;
        if (_showSaveFilesMenuFileSlot == 4) {
            _showSaveFilesMenuPage = 2;
            _showSaveFilesMenuFileSlot = 2;
        } else if (_showSaveFilesMenuFileSlot != 0) {
            _showSaveFilesMenuPage = _showSaveFilesMenuFileSlot - 1;
            _showSaveFilesMenuFileSlot = 1;
        }
        _showSaveFilesMenuSaveSuccessful = -1;
        _showSaveFilesMenuLeaveTimer = 0;
        _showSaveFilesMenuState = init;
        return 0;
    }
    switch (_showSaveFilesMenuState) {
    case init:
        for (i = 0; i < 5; ++i) {
            element = _initFileMenuElement(
                i + 5, vs_getXY(64, i * 40 + 72), vs_getWH(256, 32), 0);
            element->slotId = i;
            element->slotUnavailable
                = _saveFileInfo[i].unk4.base.slotState == slotStateUnavailable;
            element->saveLocation = _saveFileInfo[i].unk4.stats.saveLocation;
        }
        _showSaveFilesMenuState = handleInput;
        /* fallthrough */
    case handleInput:
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_selectFile);
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            _selectCursorXy = 0;
            _showSaveFilesMenuState = leave;
        } else {
            for (i = 0; i < 5; ++i) {
                _fileMenuElements[i + 5].y = ((i - _showSaveFilesMenuPage) * 40) + 72;
                _fileMenuElements[i + 5].selected = 0;
            }
            val = _showSaveFilesMenuFileSlot + _showSaveFilesMenuPage;
            if (vs_main_buttonsPressed & PADRright) {
                if (_saveFileInfo[val].unk4.base.slotState != slotStateUnavailable) {
                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                    _fileMenuElements[val + 5].selected = 1;
                    _selectCursorXy = 0;
                    _memcardMaskedHandler(_showSaveFilesMenuPort + memcardEventMaskAll);
                    _showSaveFilesMenuState = slotSelected;
                    break;
                } else {
                    func_800C02E0();
                }
            }
            if (vs_main_buttonRepeat & PADLup) {
                if (_showSaveFilesMenuFileSlot == 0) {
                    if (_showSaveFilesMenuPage != 0) {
                        --_showSaveFilesMenuPage;
                    }
                } else {
                    --_showSaveFilesMenuFileSlot;
                }
            }
            if (vs_main_buttonRepeat & PADLdown) {
                if (_showSaveFilesMenuFileSlot == 2) {
                    if (_showSaveFilesMenuPage < 2) {
                        ++_showSaveFilesMenuPage;
                    }
                } else {
                    ++_showSaveFilesMenuFileSlot;
                }
            }
            if (val != (_showSaveFilesMenuFileSlot + _showSaveFilesMenuPage)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            }
            _selectCursorXy = vs_getXY(24, _showSaveFilesMenuFileSlot * 40 + 62);
            _fileMenuElements[val + 5].selected = 1;
        }
        break;
    case slotSelected:
        val = _memcardMaskedHandler(0);
        if (val != memcardMaskedHandlerPending) {
            if (_memoryCardMessage == (char*)(_textTable + VS_MCMAN_OFFSET_noData)) {
                _promptFormat(_showSaveFilesMenuPort);
                _showSaveFilesMenuState = format;
            } else if (val > memcardMaskedHandlerError) {
                val = _showSaveFilesMenuFileSlot + _showSaveFilesMenuPage;
                if (_saveFileInfo[val].unk4.base.slotState == slotStateAvailable) {
                    if (_createSaveFile(_showSaveFilesMenuPort, val + 1) != 0) {
                        _showSaveFilesMenuState = leaveWithTimer;
                        _memoryCardMessage
                            = (char*)(_textTable + VS_MCMAN_OFFSET_saveFailed);
                    } else {
                        _showSaveFilesMenuState = save;
                    }
                } else {
                    _promptOverwrite(1);
                    _showSaveFilesMenuState = overwritePrompt;
                }
            } else {
                _showSaveFilesMenuState = leaveWithTimer;
            }
        }
        break;
    case overwritePrompt:
        val = _promptOverwrite(0);
        if (val != 0) {
            if (val == 1) {
                _memcardMaskedHandler(_showSaveFilesMenuPort + memcardEventMaskAll);
                _showSaveFilesMenuState = initOverwrite;
            } else {
                _showSaveFilesMenuState = handleInput;
            }
        }
        break;
    case initOverwrite:
        val = _memcardMaskedHandler(0);
        if (val != memcardMaskedHandlerPending) {
            if (val > memcardMaskedHandlerError) {
                _dataNotSaved |= (_findCurrentSaveOnActiveMemcard()
                    == (_showSaveFilesMenuFileSlot + _showSaveFilesMenuPage + 1));
                _showSaveFilesMenuState = save;
            } else {
                _showSaveFilesMenuState = leaveWithTimer;
            }
        }
        break;
    case save:
        val = _showSaveFilesMenuFileSlot + _showSaveFilesMenuPage;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_saving);
        _rMemcpy(&_showSaveFilesMenuSettingsBackup, &vs_main_settings,
            sizeof(_showSaveFilesMenuSettingsBackup));
        _rMemcpy(
            (savedata_t*)_spmcimg + 2, (savedata_t*)_spmcimg + 1, sizeof(savedata_t));
        if (_containerDataEmpty != 0) {
            _backupMainSetting = (*(u_int*)&vs_main_settings >> 4) & 1;
            *(int*)&vs_main_settings |= 0x10;
        }
        _packageGameSaveData(val);
        _saveFile((val + 1) | ((_showSaveFilesMenuPort - 1) << 0x10));
        _showSaveFilesMenuState = validate;
        break;
    case validate:
        val = _saveFile(0);
        ++_fileProgressCounter;
        if (val != 0) {
            D_8006169D = 0;
            saveId = _showSaveFilesMenuFileSlot + _showSaveFilesMenuPage;
            if (val < 0) {
                if (_containerDataEmpty != 0) {
                    char v = _backupMainSetting & 1;
                    *(int*)&vs_main_settings
                        = (*(int*)&vs_main_settings & ~0x10) | (v * 0x10);
                }
                memset(&_saveFileInfo[saveId], 0, sizeof(saveFileInfo_t));
                _saveFileInfo[saveId].unk4.base.slotState = slotStateTemporary;
                _fileMenuElements[saveId + 5].saveLocation = 0;
                _rMemcpy((savedata_t*)_spmcimg + 1, (savedata_t*)_spmcimg + 2,
                    sizeof(savedata_t));
                _fileProgressCounter = 0;
                _rMemcpy(&vs_main_settings, &_showSaveFilesMenuSettingsBackup,
                    sizeof(vs_main_settings));
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_saveFailed);
            } else {
                _dataNotSaved = 0;
                _fileProgressCounter = -16;
                _rMemcpy(&_saveFileInfo[saveId], _spmcimg + sizeof(saveFileInfo_t) * 3,
                    sizeof(saveFileInfo_t));
                _decode(_saveFileInfo[saveId].key,
                    &_saveFileInfo[saveId].unk4.base.slotState,
                    sizeof(saveFileInfo_t) - sizeof(int));
                _fileMenuElements[saveId + 5].saveLocation
                    = _saveFileInfo[saveId].unk4.stats.saveLocation;
                vs_main_playSfxDefault(0x7E, VS_SFX_FILEOPCOMPLETE);
                _showSaveFilesMenuSaveSuccessful = 1;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_saved);
            }
            _showSaveFilesMenuState = leaveWithTimer;
        }
        break;
    case leaveWithTimer:
        if (_showSaveFilesMenuSaveSuccessful == 1) {
            ++_showSaveFilesMenuLeaveTimer;
        }
        if ((char)vs_main_buttonsPressed == 0) {
            if (_showSaveFilesMenuLeaveTimer != 150) {
                break;
            }
        }
        vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
        _showSaveFilesMenuState = leave;
        break;
    case leave:
        if (_fileProgressCounter == 0) {
            for (i = 5; i < 10; ++i) {
                _clearFileMenuElement(i);
            }
            return _showSaveFilesMenuSaveSuccessful;
        }
        break;
    case format:
        val = _promptFormat(0);
        if (val != 0) {
            if (val < 0) {
                _showSaveFilesMenuState = leaveError;
            } else if (_createSaveFile(_showSaveFilesMenuPort,
                           _showSaveFilesMenuPage + _showSaveFilesMenuFileSlot + 1)
                != 0) {
                _showSaveFilesMenuState = leaveWithTimer;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_saveFailed);
            } else {
                _showSaveFilesMenuState = save;
            }
        }
        break;
    case leaveError:
        if ((char)vs_main_buttonsPressed != 0) {
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
    enum _selectSaveMemoryCardState {
        init = 0,
        waitForUnselectedAnimation = 1,
        waitForAnimation = 2,
        handleEvents = 3,
        animateLeave = 4,
        leave = 5,
        initSaveMenu = 6,
        showSaveMenu = 7
    };

    extern char _selectSaveMemoryCardState;
    extern u_char _selectSaveMemoryCardPort;

    int i, j;

    if (initPort != 0) {
        _selectSaveMemoryCardPort = initPort;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_checking);
        _selectSaveMemoryCardState = init;
        return 0;
    }

    switch (_selectSaveMemoryCardState) {
    case init:
        _fileMenuElements[_selectSaveMemoryCardPort].state = fileMenuElementStateAnimateX;
        _fileMenuElements[_selectSaveMemoryCardPort].targetPosition = 180;
        _fileMenuElements[_selectSaveMemoryCardPort].innertextBlendFactor = 1;
        _fileMenuElements[3 - _selectSaveMemoryCardPort].state
            = fileMenuElementStateAnimateX;
        _fileMenuElements[3 - _selectSaveMemoryCardPort].targetPosition = 320;
        _selectSaveMemoryCardState = waitForUnselectedAnimation;
        break;
    case waitForUnselectedAnimation:
        if (_fileMenuElementsActive() == 0) {
            break;
        }
        if (_selectSaveMemoryCardPort == 2) {
            _fileMenuElements[2].state = fileMenuElementStateAnimateY;
            _fileMenuElements[2].targetPosition = 50;
        }
        _selectSaveMemoryCardState = waitForAnimation;
        break;
    case waitForAnimation:
        if (_fileMenuElementsActive() != 0) {
            _memcardEventHandler(_selectSaveMemoryCardPort);
            _selectSaveMemoryCardState = handleEvents;
        }
        break;
    case handleEvents:
        i = _memcardEventHandler(0) & 3;
        if (i == 0) {
            break;
        }
        switch (i) {
        case memcardEventIoEnd:
            _selectSaveMemoryCardState = initSaveMenu;
            break;
        case memcardEventTimeout:
            _selectSaveMemoryCardState = animateLeave;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_insertError);
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
            _showSaveFilesMenu(_selectSaveMemoryCardPort);
            _selectSaveMemoryCardState = showSaveMenu;
            break;
        }
        break;
    case animateLeave:
        if ((char)vs_main_buttonsPressed == 0) {
            break;
        }
        vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
        for (i = 1; i < 3; ++i) {
            _fileMenuElements[i].state = fileMenuElementStateAnimateX;
            _fileMenuElements[i].targetPosition = 320;
        }
        _selectSaveMemoryCardState = leave;
        break;
    case leave:
        if (_fileMenuElementsActive() != 0) {
            return -1;
        }
        break;
    case initSaveMenu:
        if (_initSaveFileInfo(_selectSaveMemoryCardPort) != 0) {
            _selectSaveMemoryCardState = animateLeave;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_loadfailed);
            break;
        }
        for (i = 0; i < 5; ++i) {
            if (_saveFileInfo[i].unk4.base.slotState != slotStateUnavailable) {
                break;
            }
        }
        if (i == 5) {
            _selectSaveMemoryCardState = animateLeave;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_cardFull);
            break;
        }
        _showSaveFilesMenu(_selectSaveMemoryCardPort);
        _selectSaveMemoryCardState = showSaveMenu;
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
            _selectSaveMemoryCardState = leave;
            break;
        }
        return 1;
    }
    return 0;
}

static int _showSaveMenu(int initState)
{
    enum _showSaveMenuState {
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

    extern char _showSaveMenuState;
    extern u_char _showSaveMenuSelectedFile;

    u_short sp10 = 0xE7E7;
    fileMenuElements_t* element;
    int currentSave;
    int val;

    if (initState != 0) {
        _showSaveMenuSelectedFile = 1;
        _containerDataEmpty = 0;
        if (D_80060021 != 0) {
            _showSaveMenuSelectedFile = D_800F4F70 + 1;
        }
        _dataNotSaved = 0;
        _isSaving = 1;
        _showSaveMenuState = (initState - 1) * 3;
        element = _initFileMenuElement(0, vs_getXY(320, 34), vs_getWH(140, 12),
            (char*)(_textTable + VS_MCMAN_OFFSET_save));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 180;
        element->innertextBlendFactor = 8;
        element->selected = 1;
        _memoryCardMessage = 0;
        func_800FFC04(&sp10);
        return 0;
    }

    switch (_showSaveMenuState) {
    case init:
        if (*(int*)&vs_main_settings & 0x10) {
            memset(&((savedata_t*)_spmcimg + 1)->containerData, 0,
                sizeof(((savedata_t*)_spmcimg + 1)->containerData));
            _showSaveMenuState = initSlot1;
        } else if (_fileMenuElementsActive() != 0) {
            if (vs_main_settings.slotState != slotStateUnavailable) {
                _findCurrentSave(1);
                _showSaveMenuState = saveExists;
            } else {
                _showSaveMenuState = initSlot1;
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
                + (currentSave == findSaveTimeout ? VS_MCMAN_OFFSET_insertError
                                                  : VS_MCMAN_OFFSET_emptyCard));
            _showSaveMenuState = containerWarn;
        } else {
            _loadSaveData((currentSave & 7) | ((currentSave & 16) << 12));
            _showSaveMenuState = loadSave;
        }
        break;
    case loadSave:
        val = _loadSaveData(0);
        if (val != 0) {
            if ((val <= 0) || (_applyLoadedSaveFile(0) != 0)) {
                _showSaveMenuState = containerWarn;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_emptyCard);
            } else {
                _showSaveMenuState = initSlot1;
            }
        }
        break;
    case initSlot1:
        if (_fileMenuElementsActive() != 0) {
            element = _initFileMenuElement(1, vs_getXY(320, 50), vs_getWH(126, 12),
                (char*)(_textTable + VS_MCMAN_OFFSET_slot1));
            element->state = fileMenuElementStateAnimateX;
            element->targetPosition = 194;
            _showSaveMenuState = initSlot2;
        }
        break;
    case initSlot2:
        element = _initFileMenuElement(2, vs_getXY(320, 66), vs_getWH(126, 12),
            (char*)(_textTable + VS_MCMAN_OFFSET_slot2));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 194;
        _showSaveMenuState = waitForSlotAnimation;
        break;
    case waitForSlotAnimation:
        if (_fileMenuElementsActive() != 0) {
            func_800FFC04(&sp10);
            _showSaveMenuState = handleInput;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_selectSlot);
        }
        break;
    case handleInput:
        _fileMenuElements[_showSaveMenuSelectedFile].selected = 1;
        _fileMenuElements[3 - _showSaveMenuSelectedFile].selected = 0;
        if (vs_main_buttonsPressed & PADRdown) {
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
                _memoryCardMessage
                    = (char*)(_textTable + VS_MCMAN_OFFSET_containerWarnDataLoss);
                _promptConfirm(1);
                _showSaveMenuState = discardChanges;
            } else {
                _showSaveMenuState = returnNoSave;
            }
        } else if (vs_main_buttonsPressed & PADRright) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            _selectSaveMemoryCard(_showSaveMenuSelectedFile);
            _selectCursorXy = 0;
            _showSaveMenuState = selectCard;
        } else {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                _showSaveMenuSelectedFile = 3 - _showSaveMenuSelectedFile;
                D_800F4F70 = _showSaveMenuSelectedFile - 1;
            }
            _selectCursorXy = vs_getXY(180, (_showSaveMenuSelectedFile + 1) * 16 + 10);
        }
        break;
    case selectCard:
        val = _selectSaveMemoryCard(0);
        if (val != 0) {
            if (val < 0) {
                _showSaveMenuState = initSlot1;
                break;
            }
            _initFileMenu(val);
            return 1;
        }
        break;
    case returnNoSave:
        if (_fileMenuElementsActive() != 0) {
            return -1;
        }
        break;
    case containerWarn:
        if ((char)vs_main_buttonsPressed != 0) {
            func_800FFC04(&sp10);
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_containerWarn);
            _promptConfirm(1);
            _showSaveMenuState = eraseContainerData;
        }
        break;
    case eraseContainerData:
    case discardChanges:
        val = _promptConfirm(0);
        if (val != 0) {
            if (_showSaveMenuState == discardChanges) {
                if (val > 0) {
                    *(int*)&vs_main_settings = *(int*)&vs_main_settings | 0x10;
                }
                val = -val;
            }
            if (val < 0) {
                _fileMenuElements[0].state = fileMenuElementStateAnimateX;
                _fileMenuElements[0].targetPosition = 320;
                _showSaveMenuState = returnNoSave;
                break;
            }
            if (_showSaveMenuState == eraseContainerData) {
                _containerDataEmpty = 1;
                memset(&((savedata_t*)_spmcimg + 1)->containerData, 0,
                    sizeof(((savedata_t*)_spmcimg + 1)->containerData));
            }
            _showSaveMenuState = initSlot1;
        }
        break;
    }
    return 0;
}

static int _showLoadFilesMenu(int initPort)
{
    enum _showLoadFilesMenuState {
        init = 0,
        handleInput = 1,
        startLoad = 2,
        applyLoad = 3,
        loaded = 4,
        exiting = 5
    };

    extern vs_Gametime_t _showLoadFilesMenuBackupTime;
    extern int _showLoadFilesMenuFileLoaded;
    extern char _showLoadFilesMenuState;
    extern char _showLoadFilesMenuPort;
    extern char _showLoadFilesMenuPage;
    extern char _showLoadFilesMenuSelectedSlot;
    extern char _showLoadFilesMenuLeaveTimer;
    extern char _showLoadFilesMenuCompleteTimer;

    fileMenuElements_t* element;
    int currentSlot;
    int i;

    if (initPort != 0) {
        _showLoadFilesMenuPort = initPort;
        _showLoadFilesMenuSelectedSlot = _getNewestSaveFile();
        _showLoadFilesMenuPage = 0;
        if (_showLoadFilesMenuSelectedSlot == 4) {
            _showLoadFilesMenuPage = 2;
            _showLoadFilesMenuSelectedSlot = 2;
        } else if (_showLoadFilesMenuSelectedSlot != 0) {
            _showLoadFilesMenuPage = _showLoadFilesMenuSelectedSlot - 1;
            _showLoadFilesMenuSelectedSlot = 1;
        }
        _showLoadFilesMenuFileLoaded = -1;
        _showLoadFilesMenuCompleteTimer = 0;
        _showLoadFilesMenuState = init;
        return 0;
    }
    switch (_showLoadFilesMenuState) {
    case init:
        for (i = 0; i < 5; ++i) {
            element = _initFileMenuElement(
                i + 5, ((72 + i * 40) << 16) | 64, vs_getWH(256, 32), 0);
            element->slotId = i;
            element->slotUnavailable
                = _saveFileInfo[i].unk4.base.slotState < slotStateInUse;
            element->saveLocation = _saveFileInfo[i].unk4.stats.saveLocation;
        }
        _showLoadFilesMenuState = handleInput;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_selectFile);
        // fallthrough
    case handleInput:
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            for (i = 5; i < 10; ++i) {
                _clearFileMenuElement(i);
            }
            _selectCursorXy = 0;
            return -1;
        }
        for (i = 0; i < 5; ++i) {
            _fileMenuElements[i + 5].y = (((i - _showLoadFilesMenuPage) * 40) + 72);
            _fileMenuElements[i + 5].selected = 0;
        }

        currentSlot = _showLoadFilesMenuSelectedSlot + _showLoadFilesMenuPage;

        if (vs_main_buttonsPressed & PADRright) {
            if (_saveFileInfo[currentSlot].unk4.base.slotState >= slotStateInUse) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                _fileMenuElements[currentSlot + 5].selected = 1;
                _selectCursorXy = 0;
                _memcardMaskedHandler(_showLoadFilesMenuPort + memcardEventMaskAll);
                _showLoadFilesMenuState = startLoad;
                break;
            }
            vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
        }
        if (vs_main_buttonRepeat & PADLup) {
            if (_showLoadFilesMenuSelectedSlot == 0) {
                if (_showLoadFilesMenuPage != 0) {
                    --_showLoadFilesMenuPage;
                }
            } else {
                --_showLoadFilesMenuSelectedSlot;
            }
        }
        if (vs_main_buttonRepeat & PADLdown) {
            if (_showLoadFilesMenuSelectedSlot == 2) {
                if (_showLoadFilesMenuPage < 2) {
                    ++_showLoadFilesMenuPage;
                }
            } else {
                ++_showLoadFilesMenuSelectedSlot;
            }
        }
        if (currentSlot != (_showLoadFilesMenuSelectedSlot + _showLoadFilesMenuPage)) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
        }
        _selectCursorXy = ((_showLoadFilesMenuSelectedSlot * 40 + 62) << 16) | 24;
        _fileMenuElements[currentSlot + 5].selected = 1;
        break;
    case startLoad:
        currentSlot = _memcardMaskedHandler(0);
        if (currentSlot != memcardMaskedHandlerPending) {
            if (currentSlot >= memcardMaskedHandlerPending) {
                int new_var;
                _loadSaveData(
                    ((_showLoadFilesMenuSelectedSlot + _showLoadFilesMenuPage) + 1)
                    | (new_var = ((_showLoadFilesMenuPort - 1) << 16) | 256));
                _showLoadFilesMenuState = applyLoad;
                _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_loading);
            } else {
                _showLoadFilesMenuState = loaded;
            }
        }
        break;
    case applyLoad:
        currentSlot = _loadSaveData(0);
        ++_fileProgressCounter;
        if (currentSlot != 0) {
            _fileProgressCounter = 0;
            do {
                _showLoadFilesMenuLeaveTimer = 0;
                if (currentSlot < 0) {
                    _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_loadfailed);
                    break;
                }
                switch (_applyLoadedSaveFile(1)) {
                case 0:
                    _fileProgressCounter = -16;
                    vs_main_playSfxDefault(0x7E, VS_SFX_FILEOPCOMPLETE);
                    _showLoadFilesMenuLeaveTimer = 16;
                    _showLoadFilesMenuFileLoaded = 1;
                    _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_loaded);
                    break;
                case 1:
                    _memoryCardMessage
                        = (char*)(_textTable + VS_MCMAN_OFFSET_fileCorruptDescription);
                    break;
                }
            } while (0);

            _showLoadFilesMenuBackupTime.t = vs_main_gametime.t;
            _showLoadFilesMenuState = loaded;
        }
        break;
    case loaded:
        if (_showLoadFilesMenuLeaveTimer != 0) {
            --_showLoadFilesMenuLeaveTimer;
        }
        if (_showLoadFilesMenuFileLoaded == 1) {
            ++_showLoadFilesMenuCompleteTimer;
        }
        if (((char)vs_main_buttonsPressed != 0)
            || (_showLoadFilesMenuCompleteTimer == 150)) {
            if (_showLoadFilesMenuFileLoaded < 0) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            }
            _showLoadFilesMenuState = exiting;
        }
        break;
    case exiting:
        if (_showLoadFilesMenuLeaveTimer != 0) {
            --_showLoadFilesMenuLeaveTimer;
            break;
        }
        if (_showLoadFilesMenuFileLoaded == 1) {
            vs_main_gametime.t = _showLoadFilesMenuBackupTime.t;
        } else {
            for (i = 5; i < 10; ++i) {
                _clearFileMenuElement(i);
            }
        }
        return _showLoadFilesMenuFileLoaded;
    }
    return 0;
}

static long _selectLoadMemoryCard(int initPort)
{
    enum _selectLoadMemoryCardState {
        init = 0,
        waitForUnselectedAnimation = 1,
        pollEventsInit = 2,
        pollEvents = 3,
        leave = 4,
        returnNotSelected = 5,
        pollSuccess = 6,
        selectFile = 7
    };

    extern char _selectLoadMemoryCardState;
    extern u_char _selectLoadMemoryCardPort;

    int i;

    if (initPort != 0) {
        _selectLoadMemoryCardPort = initPort;
        _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_checking);
        _selectLoadMemoryCardState = init;
        return 0;
    }
    switch (_selectLoadMemoryCardState) {
    case init:
        _fileMenuElements[_selectLoadMemoryCardPort].state = fileMenuElementStateAnimateX;
        _fileMenuElements[_selectLoadMemoryCardPort].targetPosition = 180;
        _fileMenuElements[_selectLoadMemoryCardPort].innertextBlendFactor = 1;
        _fileMenuElements[3 - _selectLoadMemoryCardPort].state
            = fileMenuElementStateAnimateX;
        _fileMenuElements[3 - _selectLoadMemoryCardPort].targetPosition = 320;
        _selectLoadMemoryCardState = waitForUnselectedAnimation;
        break;

    case waitForUnselectedAnimation:
        if (_fileMenuElementsActive() == 0) {
            break;
        }
        if (_selectLoadMemoryCardPort == 2) {
            _fileMenuElements[2].state = fileMenuElementStateAnimateY;
            _fileMenuElements[2].targetPosition = 50;
        }
        _selectLoadMemoryCardState = pollEventsInit;
        break;

    case pollEventsInit:
        if (_fileMenuElementsActive() == 0) {
            break;
        }
        _memcardMaskedHandler(_selectLoadMemoryCardPort + memcardEventMaskIgnoreNoEvent);
        _selectLoadMemoryCardState = pollEvents;
        break;

    case pollEvents:
        i = _memcardMaskedHandler(0);
        if (i != memcardMaskedHandlerPending) {
            _selectLoadMemoryCardState = i + leave + 1;
        }
        break;

    case leave:
        if (((char)vs_main_buttonsPressed) == 0) {
            break;
        }
        vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
        for (i = 1; i < 3; ++i) {
            _fileMenuElements[i].state = fileMenuElementStateAnimateX;
            _fileMenuElements[i].targetPosition = 320;
        }
        _selectLoadMemoryCardState = returnNotSelected;
        break;

    case returnNotSelected:
        if (_fileMenuElementsActive() != 0) {
            return -1;
        }
        break;

    case pollSuccess:
        if (_initSaveFileInfo(_selectLoadMemoryCardPort) != 0) {
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_loadfailed);
            _selectLoadMemoryCardState = leave;
            break;
        }
        for (i = 0; i < 5; ++i) {
            if (_saveFileInfo[i].unk4.base.slotState > slotStateAvailable) {
                break;
            }
        }

        if (i == 5) {
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_noData);
            _selectLoadMemoryCardState = leave;
        } else {
            _showLoadFilesMenu(_selectLoadMemoryCardPort);
            _selectLoadMemoryCardState = 7;
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
            _selectLoadMemoryCardState = returnNotSelected;
            break;
        }
        return 1;
    }
    return 0;
}

static int _loadFileMenu(int initFadeout)
{
    enum _loadFileMenuState {
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

    extern char _loadFileMenuState;
    extern u_char _loadFileMenuSelectedFile;
    extern char _loadFileMenuFadeout;

    fileMenuElements_t* element;
    int i;

    if (initFadeout != 0) {
        _loadFileMenuFadeout = initFadeout - 1;
        _loadFileMenuSelectedFile = 1;

        if (D_80060021 != 0) {
            _loadFileMenuSelectedFile = D_800F4F70 + 1;
        }
        _isSaving = 0;
        _loadFileMenuState = init;
        return 0;
    }
    switch (_loadFileMenuState) {
    case init:
        element = _initFileMenuElement(0, vs_getXY(320, 34), vs_getWH(140, 12),
            (char*)(_textTable + VS_MCMAN_OFFSET_load));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 180;
        element->selected = 1;
        element->innertextBlendFactor = 8;
        _loadFileMenuState = displaySlot1;
        break;
    case displaySlot1:
        if (_fileMenuElementsActive() != 0) {
            element = _initFileMenuElement(1, vs_getXY(320, 50), vs_getWH(126, 12),
                (char*)(_textTable + VS_MCMAN_OFFSET_slot1));
            element->state = fileMenuElementStateAnimateX;
            element->targetPosition = 194;
            _loadFileMenuState = displaySlot2;
        }
        break;
    case displaySlot2:
        element = _initFileMenuElement(2, vs_getXY(320, 66), vs_getWH(126, 12),
            (char*)(_textTable + VS_MCMAN_OFFSET_slot2));
        element->state = fileMenuElementStateAnimateX;
        element->targetPosition = 194;
        _loadFileMenuState = waitForSlotAnimation;
        break;
    case waitForSlotAnimation:
        if (_fileMenuElementsActive() != 0) {
            _loadFileMenuState = handleInput;
            _memoryCardMessage = (char*)(_textTable + VS_MCMAN_OFFSET_selectSlot);
        }
        break;
    case handleInput:
        _fileMenuElements[_loadFileMenuSelectedFile].selected = 1;
        _fileMenuElements[3 - _loadFileMenuSelectedFile].selected = 0;
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            _selectCursorXy = 0;
            for (i = 0; i < 3; ++i) {
                _fileMenuElements[i].state = fileMenuElementStateAnimateX;
                _fileMenuElements[i].targetPosition = 320;
            }
            _loadFileMenuState = exit;
        } else if (vs_main_buttonsPressed & PADRright) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            _selectLoadMemoryCard(_loadFileMenuSelectedFile);
            _selectCursorXy = 0;
            _loadFileMenuState = slotSelected;
        } else {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                _loadFileMenuSelectedFile = 3 - _loadFileMenuSelectedFile;
                D_800F4F70 = _loadFileMenuSelectedFile - 1;
            }
            _selectCursorXy = ((((_loadFileMenuSelectedFile + 1) * 16) + 10) << 16) | 180;
        }
        break;
    case slotSelected:
        element = (fileMenuElements_t*)_selectLoadMemoryCard(0);
        if (element != 0) {
            if ((long)element < 0) {
                _loadFileMenuState = displaySlot1;
            } else {
                _loadFileMenuState = fadeAndReturnSelected;
            }
        }
        break;
    case exit:
        if (_fileMenuElementsActive() != 0) {
            if (_loadFileMenuFadeout == 0) {
                return -1;
            }
            _loadFileMenuState = fadeAndReturnNotSelected;
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

static int func_801085B0(int arg0)
{
    vs_main_CdFile file;
    void* new_var2;
    vs_Gametime_t sp18;
    int lba;
    vs_Gametime_t* new_var;

    switch (arg0) {
    case 0:
        new_var = &sp18;
        if (D_8010AB04->state == 4) {
            vs_main_freeCdQueueSlot(D_8010AB04);
            sp18.t = vs_main_gametime.t;
            _spmcimg = (char*)(_opMcImg - 1);
            _applyLoadedSaveFile(1);
            vs_main_gametime.t = sp18.t;
            new_var2 = _opMcImg;
            vs_main_freeHeapR(new_var2);
            return 1;
        }
        return 0;
    case 1:
        lba = VS_OPMCIMG1_BIN_LBA;
        break;
    case 2:
        lba = VS_OPMCIMG2_BIN_LBA;
        break;
    default:
        return 0;
    }

    file.lba = lba;
    file.size = VS_OPMCIMG1_BIN_SIZE;
    D_8010AB04 = vs_main_allocateCdQueueSlot(&file);
    new_var2 = vs_main_allocHeapR(sizeof(*_opMcImg));
    _opMcImg = new_var2;
    vs_main_cdEnqueue(D_8010AB04, _opMcImg);
    return 0;
}

static int _initGameOver(int arg0)
{

    extern vs_main_CdQueueSlot* _initGameOverQueueSlot;
    extern int _initGameOverState;

    vs_main_CdFile cdFile;

    if (arg0 != 0) {
        cdFile.lba = VS_GAMEOVER_BIN_LBA;
        cdFile.size = VS_GAMEOVER_BIN_SIZE;
        _initGameOverQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        D_8010AB10 = vs_main_allocHeapR(VS_GAMEOVER_BIN_SIZE);
        vs_main_cdEnqueue(_initGameOverQueueSlot, D_8010AB10);
        _initGameOverState = 0;
        return 0;
    }
    switch (_initGameOverState) {
    case 0:
        if (_initGameOverQueueSlot->state == 4) {
            vs_main_freeCdQueueSlot(_initGameOverQueueSlot);
            func_800CCDA8(0x01000340, D_8010AB10, 0x800018);
            func_800CCDA8(0x01800340, D_8010A930, 0x10030);
            _initGameOverState = 1;
        }
        return 0;
    case 1:
        vs_main_freeHeapR(D_8010AB10);
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

int func_801088B4(int arg0)
{
    u_int* temp_s4;
    u_int* temp_t0;

    temp_s4 = D_1F800000[2];

    if (arg0 != 0) {
        D_8010AB60 = 0;
        D_8010AB64 = 0;
        D_8010AB68 = 0;
        D_8010AB6C = 0;
        D_8010AB70 = 0;
        D_8010AB74 = 0;
        return 0;
    }
    if (D_8010AB60 < 0) {
        temp_t0 = D_1F800000[0];
        temp_t0[0] = (*temp_s4 & 0xFFFFFF) | 0x04000000;
        temp_t0[1] = 0xE1000140;
        temp_t0[3] = 0;
        temp_t0[4] = 0xF00140;
        temp_t0[2] = (((D_8010AB60 + 0x80) * 0x20202) | 0x62000000);
        *temp_s4 = ((u_long)temp_t0 << 8) >> 8;
        D_1F800000[0] = temp_t0 + 5;
        D_8010AB60 += 8;
        if (D_8010AB60 == 0) {
            SetDispMask(0);
            return D_8010AB74 + 1;
        }
        return 0;
    }
    if (D_8010AB60 < 0x80) {
        D_8010AB60 += 8;
    } else {
        if (vs_main_buttonsPressed & 0x820) {
            func_800C02F0();
            func_8004552C(1, 0, 0x3C);
            D_8010AB60 = -0x80;
            return 0;
        }
        if (vs_main_buttonsPressed & 0x5100) {
            func_800C02F8();
            D_8010AB74 = 1 - D_8010AB74;
        }
        if (D_8010AB74 == 0) {
            if (D_8010AB6C < 0x10) {
                D_8010AB64 = D_8010AB6C * 0x10;
                D_8010AB6C += 4;
                if (D_8010AB6C >= 0x11) {
                    D_8010AB6C = 0x10;
                }
            } else {
                if (D_8010AB64 >= 0x90) {
                    D_8010AB64 -= 0x10;
                } else {
                    D_8010AB64 = 0x80;
                }
                if (D_8010AB68 < 0x10) {
                    D_8010AB68 = 0;
                } else {
                    D_8010AB68 -= 0x10;
                }
            }
            if (D_8010AB70 != 0) {
                D_8010AB70 -= 1;
            }
        } else {
            if (D_8010AB70 < 0x10) {
                D_8010AB68 = D_8010AB70 * 0x10;
                D_8010AB70 += 4;
                if (D_8010AB70 >= 0x11) {
                    D_8010AB70 = 0x10;
                }
            } else {
                if (D_8010AB68 >= 0x90) {
                    D_8010AB68 -= 0x10;
                } else {
                    D_8010AB68 = 0x80;
                }
                if (D_8010AB64 < 0x10) {
                    D_8010AB64 = 0;
                } else {
                    D_8010AB64 -= 0x10;
                }
            }
            if (D_8010AB6C != 0) {
                D_8010AB6C -= 1;
            }
        }
    }

    _setMenuItemClut(D_8010AB20, D_8010AB6C, D_8010A930, D_8010A930 + 0x30);
    _setMenuItemClut(D_8010AB20 + 0x10, D_8010AB70, D_8010A930, D_8010A930 + 0x30);
    func_800CCDA8(0x01800340, &D_8010AB20, 0x10020);
    temp_t0 = func_800C0230(D_8010AB60, 0x800070, 0x200060, temp_s4);
    temp_t0[1] = 0xE100001D;
    temp_t0[4] = 0x60340000;
    temp_t0 = func_800C0230(D_8010AB60, 0xA00070, 0x200060, temp_s4);
    temp_t0[1] = 0xE100001D;
    temp_t0[4] = 0x60352000;
    temp_t0 = func_800C0230(D_8010AB64 | 0x100, 0x800070, 0x200060, temp_s4);
    temp_t0[1] = 0xE100001D;
    temp_t0[4] = 0x60364000;
    temp_t0 = func_800C0230(D_8010AB68 | 0x100, 0xA00070, 0x200060, temp_s4);
    temp_t0[1] = 0xE100001D;
    temp_t0[4] = 0x60366000;
    return 0;
}

int func_80108CE8(char* arg0)
{
    RECT rect;
    int temp_v0;

    switch (*arg0) {
    case 0:
        func_8007E0A8(0x1F, 1, 6);
        func_8008A4DC(0);
        D_8010AD80 = vs_main_settings;
        D_8010ADA4 = D_80061599;
        _initGameOver(1);
        *arg0 = 1;
        break;
    case 1:
        if (_initGameOver(0) == 0) {
            break;
        }
        *arg0 = 2;
        func_801088B4(1);
        // Fallthrough
    case 2:
        temp_v0 = func_801088B4(0);
        if (temp_v0 == 0) {
            break;
        }
        D_8010ADA0 = 0x10;
        if (temp_v0 != 2) {
            temp_v0 = D_80061598[0xAB];
            if (((temp_v0 - 1) < 2U) && (D_80061598[0] == 0)) {
                func_801085B0(temp_v0);
                *arg0 = 6;
            } else {
                *arg0 = 3;
            }
        } else {
            *arg0 = 7;
        }
        break;
    case 3:
        _initMemcard(1);
        _initFileMenu();
        setRECT(&rect, 0x280, 0x1FF, 0x100, 1);
        StoreImage(&rect, (u_long*)D_8010AB80);
        DrawSync(0);
        func_80048A64(D_8010AB80, 3U, 0U, 0x100U);
        *arg0 = 4;
        break;
    case 4:
        if (_initMemcard(0) != 0) {
            _loadFileMenu(2);
            *arg0 = 5;
            _drawFileMenuBg();
            _drawFileMenu(vs_main_frameBuf);
        }
        break;
    case 5:
        SetDispMask(1);
        temp_v0 = _loadFileMenu(0);
        if (temp_v0 != 0) {
            _shutdownMemcard();
            SetDispMask(0);
            if (temp_v0 < 0) {
                D_8010ADA0 = 1;
                *arg0 = 7;
                break;
            }
            vs_main_freeMusic(1);
            D_8006163C = 0;
            vs_main_jumpToBattle();
        } else {
            _drawFileMenuBg();
            _drawFileMenu(vs_main_frameBuf);
        }
        break;
    case 6:
        if (func_801085B0(0) != 0) {
            vs_main_settings = D_8010AD80;
            D_80061598[1] = D_8010ADA4;
            vs_main_freeMusic(1);
            vs_main_setMonoSound(vs_main_settings.monoSound);
            D_80061598[0xA4] = 0;
            vs_main_jumpToBattle();
        }
        break;
    case 7:
        if (D_8010ADA0 != 0) {
            D_8010ADA0 -= 1;
        } else {
            vs_main_freeMusic(1);
            vs_main_resetGame();
        }
        break;
    }
    D_8006163C = 1;
    return 0;
}

int func_8010903C(int arg0)
{
    func_800C8E5C_t* temp_v0;
    u_int var_s0;

    if (arg0 != 0) {
        temp_v0 = func_800C8E5C(0x1E, 0x140, 0x92, 0x7E, 0, &D_8010A9D0);
        temp_v0->unk0 = 2;
        temp_v0->unk18 = 0xC2;
        D_8010ADAC = 0;
        D_8010ADA8 = (arg0 - 1) & 1;
        D_8010ADAD = (char)(arg0 >> 2);
        return 0;
    }
    switch (D_8010ADAC) {
    case 0:
        temp_v0 = func_800C8E5C(0x1F, 0x140, 0xA2, 0x7E, 0, &D_8010A9D4);
        temp_v0->unk0 = 2;
        temp_v0->unk18 = 0xC2;
        D_8010ADAC = 1;
        break;
    case 1:
        D_8010ADAC += func_800FA9D0();
        break;
    case 2:
        func_800C8E48(D_8010ADA8 + 0x1E)[6] = 1;
        func_800C8E48(0x1F - D_8010ADA8)[6] = 0;
        var_s0 = vs_main_buttonsPressed;
        if (D_8010ADAD == 0) {
            if (var_s0 & 0x10) {
                var_s0 -= 16;
                func_800C02E0();
            }
        }
        if (var_s0 & 0x70) {
            if ((D_8010ADA8 != 0) || (var_s0 & 0x50)) {
                func_800C02E8();
                func_800FA8E0(0x28);
                D_8010ADA8 = -1;
            } else {
                func_800C02F0();
                func_800FA8E0(0);
                D_8010ADA8 = 1;
            }
            D_8010ADAC = 3;
        } else {
            D_8010AA2A = func_800CCD40(D_8010AA2A, D_8010ADA8 + 8);
            if (vs_main_buttonRepeat & 0x5000) {
                func_800C02F8();
                D_8010ADA8 = 1 - D_8010ADA8;
            }
        }
        break;
    case 3:
        if (func_800FA9D0() != 0) {
            return D_8010ADA8;
        }
        break;
    }
    return 0;
}

static u_short* _getContainerOffset(int section, containerData_t* arg1)
{
    int i;
    int offset;

    i = 0;
    offset = 0;

    if (section > 0) {
        do {
            offset += _containerOffsets[i++];
        } while (i < section);
    }
    return arg1->containerData + offset;
}

void func_801092C4(containerData_t* arg0, int arg1, containerData_t* arg2);
INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801092C4);

extern char D_80102578;
extern u_short D_8010A9BA;
extern u_short D_8010A9D8;
extern u_short D_8010A9E2;

int func_80109778(char* arg0)
{
    func_800C8E5C_t* temp_v0_3;
    int temp_s0;
    u_short* var_a0;
    char temp_a0;
    int var_v0;

    switch (*arg0) {
    case 0:
        vs_battle_playSfx10();
        D_80102578 = ((*(u_int*)&vs_main_settings) >> 4) & 1;
        D_8010245C = vs_main_allocHeapR(0x14730);
        vs_battle_rMemzero(D_8010245C, 0x14730);
        func_800FBD80(0x10);
        func_800C8E04(1);
        func_8010903C(5);
        func_800FFC04(&D_8010A9BA);
        *arg0 = 1;
        break;
    case 1:
        temp_s0 = func_8010903C(0);
        if (temp_s0 != 0) {
            if (temp_s0 >= 0) {
                _initMemcard(1);
                func_800FFB68(1);
                func_800FFA88(2);
                temp_v0_3 = func_800C8E5C(0, 0x140, 0x12, 0x7E, 8, &D_8010A9D8);
                temp_v0_3->unk0 = 2;
                temp_v0_3->unk18 = 0xB4;
                temp_v0_3->unk6 = 1;
                *arg0 = 2;
            } else {
                *arg0 = 16;
            }
        }
        break;
    case 2:
        if ((func_800FA9D0() != 0) && (_initMemcard(0) != 0)) {
            func_8008A4DC(0);
            func_800CB654(1);
            D_800EB9B0 = 0x200000;
            func_80100414(0x7FE, 0x80);
            _initFileMenu();
            if ((*(u_int*)&vs_main_settings) & 0x10) {
                vs_battle_rMemzero(_spmcimg + 0x79E0, 0x3C00);
                *arg0 = 7;
            } else {
                _findCurrentSave(1);
                *arg0 = 3;
            }
        }
        break;
    case 3:
        temp_s0 = _findCurrentSave(0);
        if (temp_s0 != 0) {
            if (temp_s0 < 0) {
                if (temp_s0 == -2) {
                    var_a0 = _textTable + 0xE3;
                } else {
                    var_a0 = _textTable + 0xF7;
                }
                func_800FFC04(var_a0);
                *arg0 = 4;
            } else {
                _loadSaveData((temp_s0 & 7) | ((temp_s0 & 0x10) << 0xC));
                *arg0 = 6;
            }
        }
        break;
    case 4:
        if ((char)vs_main_buttonsPressed != 0) {
            func_800FFC04(_textTable + 0x234);
            func_8010903C(2);
            *arg0 = 5;
        }
        break;
    case 5:
        temp_s0 = func_8010903C(0);
        if (temp_s0 != 0) {
            if (temp_s0 < 0) {
                *arg0 = 0xE;
            } else {
                (*(u_int*)&vs_main_settings) |= 0x10;
                vs_battle_rMemzero(_spmcimg + 0x79E0, 0x3C00);
                *arg0 = 7;
            }
        }
        break;
    case 6:
        temp_s0 = _loadSaveData(0);
        if (temp_s0 != 0) {
            if ((temp_s0 > 0) && (_applyLoadedSaveFile(0) == 0)) {
                *arg0 = 7;
                break;
            }
            var_a0 = _textTable + 0xF7;
            func_800FFC04(var_a0);
            *arg0 = 4;
        }
        break;
    case 7:
        vs_battle_memcpy(D_8010245C, (short*)D_80060168, 0xF00);
        vs_battle_memcpy(D_8010245C + 0xF00, (short*)&D_800619D8, 0xB0);
        vs_battle_memcpy(D_8010245C + 0xFB0, (short*)(_spmcimg + 0x79E0), 0x3C00);
        _shutdownMemcard();
        *arg0 = 8;
        temp_a0 = D_800F51C0[0];
        D_800F51C0[0] = 0xE;
        D_800F51C0[1] = temp_a0;
        break;
    case 8:
        if (func_800FA9D0() != 0) {
            _initMemcard(1);
            *arg0 = 9;
        }
        break;
    case 9:
        if (_initMemcard(0) != 0) {
            temp_s0 = D_800F51C0[1];
            if (temp_s0 != 0) {
                func_800C8E04(1);
                if (temp_s0 == 1) {
                    func_8010903C(1);
                    func_800FFC04(&D_8010A9E2);
                    *arg0 = 0xC;
                } else {
                    *arg0 = 0xA;
                }
            } else {
                *arg0 = 0xD;
            }
        }
        break;
    case 10:
        func_801092C4((containerData_t*)(_spmcimg + 0x79E0), (int)(D_8010245C + 0xC430),
            D_8010245C + 0x10030);
        _showSaveMenu(2);
        *arg0 = 0xB;
        break;
    case 11:
        temp_s0 = _showSaveMenu(0);
        if (temp_s0 != 0) {
            if ((_dataNotSaved == 0) && (temp_s0 < 0)) {
                func_800C8E04(1);
                func_8010903C(1);
                func_800FFC04(&D_8010A9E2);
                *arg0 = 0xC;
            } else {
                *arg0 = 0xE;
            }
        }
        _drawFileMenu(vs_main_frameBuf);
        break;
    case 12:
        temp_s0 = func_8010903C(0);
        if (temp_s0 != 0) {
            if (temp_s0 == 1) {
                *arg0 = 0xA;
                break;
            }
            *arg0 = 0xD;
        }
        break;
    case 13: {
        char v0 = (*(int*)&vs_main_settings);
        char v1 = D_80102578 & 1;
        *(int*)&vs_main_settings = (*(int*)&vs_main_settings & ~0x10) | (v1 * 0x10);
        vs_battle_memcpy((short*)D_80060168, (short*)D_8010245C, 0xF00);
        vs_battle_memcpy((short*)&D_800619D8, D_8010245C + 0xF00, 0xB0);
    }
        /* fallthrough */
    case 14:
        func_8008A4DC(1);
        func_800CB654(0);
        D_800EB9B0 = 0;
        func_800FA8E0(0x28);
        func_80100414(-4, 0x80);
        *arg0 = 0xF;
        break;
    case 15:
        func_800FFA88(0);
        func_800FFBA8();
        func_800FFB68(0);
        if (func_800FA9D0() != 0) {
            _shutdownMemcard();
            *arg0 = 0x10;
        }
        break;
    case 16:
        if ((func_800CD064(7) == 0) && (D_801022D8 == 0)) {
            vs_main_freeHeapR(D_8010245C);
            *arg0 = 0;
            return 1;
        }
        break;
    }
    return 0;
}

INCLUDE_RODATA("build/src/MENU/MENU7.PRG/nonmatchings/260", D_80102A0C);

extern char* D_8010AA3C;

void func_80109D64()
{
    char time[4];
    int temp_v0;
    int i;

    *(int*)&time = vs_main_gametime.all;
    if (time[3] >= 100) {
        *(int*)&time = 0;
        time[3] = 0;
        func_800C6828("1", 0xC800D8, D_1F800000[1] - 5);
    } else {
        time[0] = ((((time[0] << 14) + vs_battle_encode(15)) * 5u) >> 14) / 3;
    }
    for (i = 0; i < 4; ++i) {
        temp_v0 = func_800CCC54(time[i]);
        D_8010AA3C[9 - i * 3] = (temp_v0 >> 4) + 0x30;
        D_8010AA3C[10 - i * 3] = (temp_v0 & 0xF) + 0x30;
    }
    func_800C6828(D_8010AA3C, 0xC800E0, D_1F800000[1] - 5);
    func_800C6828("PLAY    TIME", 0xBC00E0, D_1F800000[1] - 5);
}

int func_80109EB8(char* arg0)
{
    u_short* sp10[2][2];
    int sp20[2];
    RECT rect;
    int temp_s0;
    int new_var;

    if (*arg0 < 0xB) {
        func_80109D64();
    }

    switch (*arg0) {
    case 3:
        _initMemcard(1);
        *arg0 = 4;
        break;
    case 4:
        if ((func_800FA9D0() == 0) || (_initMemcard(0) == 0)) {
            break;
        }
        // Fallthrough
    case 5:
        new_var = 1;
        for (temp_s0 = 0; temp_s0 < 2; ++temp_s0) {
            sp10[temp_s0][0] = &_textTable[*(u_short*)((u_int*)_textTable + temp_s0)];
            sp10[temp_s0][new_var] = _textTable + 0x344;
            sp20[temp_s0] = 0;
        }
        D_800F4E6B = func_8008A4FC();
        if (!(D_800F4E6B & 0xFF) || (D_8006163F != 0)) {
            sp20[0] |= 1;
        }
        temp_s0 = vs_main_settings.cursorMemory;
        if (*arg0 != 4) {
            vs_main_settings.cursorMemory = 1;
        }
        func_801005E0(2, 0x143, (u_short**)sp10, sp20);
        vs_main_settings.cursorMemory = temp_s0;
        func_8008A4DC(0);
        *arg0 = 6;
        break;
    case 6:
        temp_s0 = func_801008C8() + 1;
        if (temp_s0 != 0) {
            if (temp_s0 > 0) {
                func_800FA8E0(6);
                _initFileMenu();
                switch (temp_s0) {
                case 1:
                    *arg0 = 7;
                    break;
                case 2:
                    *arg0 = 9;
                    break;
                }
            } else {
                func_8008A4DC(1);
                func_800FA8E0(0x28);
                if (temp_s0 == -2) {
                    *arg0 = 0xC;
                } else {
                    *arg0 = 0xB;
                }
            }
        } else {
            if ((D_800F4E6B != 0) && (D_8006163F != 0) && (func_801008B0() == 0)) {
                func_800C8E04(1);
                D_800F514C = 0xB;
            } else {
                D_800F514C = 0;
            }
        }
        break;
    case 7:
        if (func_800FA9D0() != 0) {
            _showSaveMenu(1);
            *arg0 = 8;
        }
        break;
    case 8:
        if (_showSaveMenu(0) != 0) {
            *arg0 = 5;
        }
        _drawFileMenu(vs_main_frameBuf);
        break;
    case 9:
        if (func_800FA9D0() != 0) {
            _loadFileMenu(1);
            *arg0 = 0xA;
        }
        break;
    case 10:
        temp_s0 = _loadFileMenu(0);
        if (temp_s0 != 0) {
            if (temp_s0 < 0) {
                *arg0 = 5;
                break;
            }
            setRECT(&rect, 0, 0, 0x280, 0xF0);
            DrawSync(0);
            ClearImage(&rect, 0, 0, 0);
            _shutdownMemcard();
            *arg0 = 0;
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
        *arg0 = 0xD;
        break;
    case 12:
        func_800FFA88(0);
        func_800FFBA8();
        func_800FFB68(0);
        *arg0 = 0xE;
        break;
    case 13:
    case 14:
        if (D_801022D8 != 0) {
            break;
        }
        _shutdownMemcard();
        if (*arg0 == 0xE) {
            D_800F51C0[0] = 7;
        }
        *arg0 = 0;
        return 1;
    }
    return 0;
}
