#include "common.h"
#include "22C.h"
#include "../SLUS_010.40/main.h"
#include "../SLUS_010.40/31724.h"
#include "../SLUS_010.40/sfx.h"
#include "gpu.h"
#include "lbas.h"
#include "vs_string.h"
#include "mcman.h"
#include <libapi.h>
#include <libds.h>
#include <libetc.h>
#include <libpress.h>
#include <libspu.h>
#include <memory.h>
#include <strings.h>
#include <sys/file.h>

typedef struct {
    void* encodedData[2];
    int encodedDataIndex;
    void* decodedData[2];
    int decodedDataIndex;
    RECT frameBufs[2];
    u_int frameBufIndex;
    RECT renderTarget;
    int frameComplete;
} MovieData_t;

enum _fileMenuElementState_e {
    fileMenuElementStateAnimateX = 2,
    fileMenuElementStateAnimateY = 3,
};

typedef struct {
    u_char state;
    u_char slotId;
    u_char outerBlendFactor;
    u_char innerBlendFactor;
    u_char selected;
    u_char slotUnavailable;
    u_char saveLocation;
    u_char unk7;
    short targetPosition;
    short unkA;
    short x;
    short y;
    short w;
    short h;
    u_char text[32];
} _fileMenuElements_t;

enum menuItemState_t {
    menuItemStateStatic = 0,
    menuItemStateUpper = 1,
    menuItemStateLower = 2,
    menuItemStateSubmenu = 3
};

typedef struct {
    u_char enabled;
    u_char state;
    u_char saturation;
    u_char unk3;
    u_char pos;
    u_char targetPos;
    u_char unk6;
    u_char blendFactor;
} menuItemState_t;

typedef struct {
    u_char data[220][256 / 2];
    u_short clut[16][16];
} fontTable_t;

typedef struct {
    u_char page0[224][256 / 2];
    u_char page1[256][256 / 2];
} uiTable_t;

typedef struct {
    u_char data[158][256 / 2];
    u_short clut[16][16];
} _debugFont_t;

typedef struct {
    u_short clut[256];
    u_char data[240][192];
} menuBg_t;

typedef struct {
    u_long tag;
    VS_SPRT sprt;
} tagsprt_t;

enum slotState_t {
    slotStateUnavailable = 0,
    slotStateAvailable = 1,
    slotStateTemporary = 2,
    slotStateInUse = 3
};

typedef struct {
    enum slotState_t slotState;
    int generation;
    int unk8;
    char unkC;
    char seconds;
    char minutes;
    char hours;
    u_short saveCount;
    u_short unk12;
    u_short currentHP;
    u_short maxHP;
    u_char saveLocation;
    u_char clearCount;
    u_char mapCompletion;
    u_char unk1B;
    u_short currentMP;
    u_short maxMP;
    u_short unk20[16];
} _saveFileSubInfo_t;

typedef struct {
    int key;
    _saveFileSubInfo_t unk4;
    u_char unk44[0x1C];
    u_char unk60[0x20];
} _saveFileInfo_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    _saveFileSubInfo_t unk4;
    u_char unk44[0x1C];
    u_char unk60[0x20];
    u_char unk80[0x80];
    u_char unk100[0x80];
    struct savedata_unk180_t {
        struct savedata_unk180_2_t {
            int key;
            int slotState;
            int unk188;
            int unk18C;
        } unk180;
        vs_Gametime_t gameTime;
        u_short saveCount;
        u_short unk196;
        u_short unk198;
        u_short unk19A;
        u_char unk19C;
        u_char unk19D;
        u_char unk19E;
        u_char unk19F;
        u_short unk1A0;
        u_short unk1A2;
        u_char checksums[0x5C];
    } unk180;
    u_char unk200[0x440];
    u_char unk640[0x20];
    u_char unk660[0x48];
    vs_main_settings_t unk6A8;
    D_80060068_t unk6C8;
    u_char unk7C8[0xF00];
    u_char unk16C8[0xB0];
    D_80061068_t unk1778;
    D_8005FEA0_t unk1784;
    int unk1898;
    u_char unk189C[0x520];
    u_char unk1DBC[0x24];
    struct {
        u_char unk1DE0[0x3800];
        u_char unk55E0[0x100];
        u_char unk56E0[0x300];
    } unk1DE0;
    u_char unk59E0[0x220];
} savedata_t;

typedef struct {
    u_long tag;
    VS_SPRT sprt;
} menuItemPrim_t;

typedef struct {
    u_long locationCluts[2][128];
    u_char unk400[7][32];
    u_char unk4E0[22][128];
    u_char unkFE0[0x20];
    u_short textTable[0x800];
    _saveFileInfo_t saveFileInfo[5];
    struct DIRENTRY direntBuf;
} mcdata_t;

static void _playMovie(DslLOC*);
static u_short* _getNextMovieFrame(MovieData_t* arg0);
static void _initTitle();
void func_80071CE0(int arg0);

u_char const saveFilenameTemplate[] = "bu00:BASLUS-01040VAG0";

u_char const* _pMemcardFilenameTemplate = saveFilenameTemplate;
u_int _encodeSeed = 0x0019660D;
u_short eventSpecs[] = { EvSpIOE, EvSpERROR, EvSpTIMOUT, EvSpNEW };

extern u_char D_8007289C[];
extern char _selectCursorColors[];
extern int _saveInfoUVClut[];
extern int _saveInfoWh[];
extern u_char _digitsDivisors[];
extern int _fontCharacterWidths[];
extern u_char _arrowCharState;
extern int D_80072EFC[];
extern int D_80072F04[];
extern struct {
    u_short clut[16];
    u_long data[0x600];
} _publisher;
extern u_long _developer[];
extern int _movieWidth;
extern int _movieHeight;
extern u_int D_80074AF4[];
extern u_int _menuBg[];
extern u_short _menuItemClut[][16];
extern int _menuItemCluts2[10];
extern int _menuItemTpages2[10];
extern int _menuItemCluts1[10];
extern int _menuItemTpages1[10];
extern int _menuItemWh[10];
extern int _menuItemXy[10];
extern u_char D_80074C24[];
extern u_char D_80075B24[32];
extern u_short _menuCopyright[];
extern fontTable_t _fontTable[2];
extern u_long _debugFont[];
extern uiTable_t _uiTable;
extern menuBg_t _saveMenuBg;
extern u_char _memcardFilename[32];
extern u_char _memcardTempFilename[32];
extern u_char _memCardState;
extern u_char _memcardPort;
extern u_char _memCardInitTmeout;
extern u_char _memCardTimeout;
extern u_char _memcardEvType;
extern u_char _loadSaveDataState;
extern u_char _readCardPort;
extern u_char _readFileNo;
extern u_char _isTempSave;
extern u_char _loadSaveDataErrors;
extern int _memCardFd;
extern u_char _memcardSaveState;
extern u_char _memcardFileno;
extern u_char _memcardManagerPort;
extern u_char D_800DC8BB;
extern u_char D_800DC8BC;
extern u_char _showLoadMenuState;
extern u_char _showLoadMenuSelectedSlot;
extern u_char _showLoadMenuFadeout;
extern int _saveFileId;
extern u_char D_800DC923;
extern u_char D_800DC924;
extern RECT D_800DC938;
extern menuItemPrim_t _menuItemPrims[10];
extern u_char _saveScreenState;
extern u_char _saveScreenFadeTimer;
extern u_char _loadSaveDataErrorOffset;
extern u_short D_800DEB10;
extern u_short D_800DEB12;
extern u_char _overwritingFile;
extern u_char D_800DED74;
extern u_char _diskState;
extern vs_main_CdQueueSlot* _mcDataLoad;
extern u_char _findCurrentSaveState;
extern u_char _findCurrentSaveSubState;
extern u_char _memcardEventMask;
extern vs_Gametime_t D_800DC8D0;
extern int _fileLoaded;
extern u_char _fileToLoadState;
extern u_char D_800DC8D9;
extern u_char _slotsPage;
extern u_char _selectedSlot;
extern u_char D_800DC8DC;
extern u_char _selectLoadMemoryCardState;
extern u_char _selectedMemoryCard;
extern u_char _fileLoadCompleteTimer;
extern u_char _promptConfirmState;
extern u_char _promptConfirmNoSelected;
extern int _promptOverwriteSelectedOption;
extern u_char _promptOverwriteState;
extern u_char _overwritePromptInitialized;
extern u_char _promptFormatState;
extern vs_main_settings_t _settingsBackup;
extern int _saveSuccessful;
extern u_char _saveMenuState;
extern u_char _saveMenuPort;
extern u_char _saveMenuSelectedPage;
extern u_char _saveMenuSelectedSlot;
extern u_char _saveMenuLeaveTimer;
extern u_char _memcardStatePort;
extern RECT _gameLoadRect;
extern u_char _loadScreenMemcardState;
extern u_char D_800DC931;
extern u_char D_800DC932;
extern tagsprt_t D_800DE948[2];
extern long memcardEventDescriptors[8];
extern struct {
    u_long tag;
    VS_TILE_TPAGE tile;
} _titleScreenFade;
extern int _buttonsLastPressed;
extern int _introMovieLastPlayed;
extern u_char* _spmcimg;
extern mcdata_t* _mcData;
extern u_short* _textTable;
extern struct DIRENTRY* _memcardFiles[15];
extern struct DIRENTRY* dirEntBuf;
extern _saveFileInfo_t* _saveFileInfo;
extern u_short D_800DEB0E;
extern int D_800DEB14;
extern _fileMenuElements_t _fileMenuElements[10];
extern struct {
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
        u_long raw[13];
    } prim;
} _primBuf;
extern int _selectCursorXy;
extern u_char* _selectSaveMemoryCardMessage;
extern u_char _isSaving;
extern u_char _selectCursorColor;
extern u_char _fileMenuScreenFade;
extern u_char D_800DED75;
extern u_char _frameBuf;
extern u_int _introMovieDisplayedAt;
extern int _introMoviePlaying;
extern DslLOC introMovieLoc;
extern MovieData_t _movieData;
extern int _dslMode;
extern u_long* _movieRingBuf;
extern u_short _vlcTable;
extern void* _encodedDataBuf0;
extern void* _encodedDataBuf1;
extern void* _decodedDataBuf0;
extern void* _decodedDataBuf1;
extern menuItemState_t _menuItemStates[10];
extern u_char _selectSaveMemoryCardState;
extern u_char _selectSaveMemoryCardPort;

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

enum _testMemcardEvents_t {
    memcardInternalEventIoEnd = 0,
    memcardInternalEventError = 1,
    memcardInternalEventTimeout = 2,
    memcardInternalEventUnformatted = 3,
    memcardInternalEventNone = 4,
};

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

#define SWEVENTS 0
#define HWEVENTS 4

#define MAKEXY(x, y) (((y) << 16) | ((x) & 0xFFFF))
#define MAKEWH(w, h) MAKEXY(w, h)

static void _playNewGameSfx()
{
    vs_main_playSfxDefault(0x7E, 1);
    vs_main_playSfxDefault(0x7E, 2);
    vs_main_playSfxDefault(0x7E, 3);
}

static void _playMenuChangeSfx() { vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE); }

static void _playMenuSelectSfx() { vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT); }

static void _playMenuLeaveSfx() { vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE); }

static u_int _encode(int value)
{
    u_int seed = _encodeSeed;
    _encodeSeed = seed * 0x19660D;
    return seed >> (32 - value);
}

static enum _testMemcardEvents_t _testMemcardEvents(int type)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if (TestEvent(memcardEventDescriptors[i + type]) == 1) {
            return i;
        }
    }
    return i;
}

static void _resetMemcardEvents(int type)
{
    int i;

    for (i = 0; i < 4; ++i) {
        TestEvent(memcardEventDescriptors[i + type]);
    }
}

static void _drawImage(int xy, u_long* p, int wh)
{
    RECT rect;

    *(int*)&rect.x = xy;
    *(int*)&rect.w = wh;
    LoadImage(&rect, p);
    DrawSync(0);
}

static void _readImage(int xy, u_long* p, int wh)
{
    RECT rect;

    *(int*)&rect.x = xy;
    *(int*)&rect.w = wh;
    StoreImage(&rect, p);
    DrawSync(0);
}

static void _rMemcpy(void* dst, void const* src, int count)
{
    do {
        --count;
        ((u_char*)dst)[count] = ((u_char const*)src)[count];
    } while (count != 0);
}

static u_char* _memcardMakeFilename(int port, int fileNo)
{
    memset(_memcardFilename, 0, ' ');
    strcpy(_memcardFilename, _pMemcardFilenameTemplate);
    _memcardFilename[2] = port == 0 ? '0' : '1';
    _memcardFilename[20] = fileNo + '0';
    return _memcardFilename;
}

static u_char* _memcardMakeTempFilename(int port, int fileNo)
{
    memset(_memcardTempFilename, 0, ' ');
    strcpy(_memcardTempFilename, _pMemcardFilenameTemplate);
    _memcardTempFilename[2] = port == 0 ? '0' : '1';
    _memcardTempFilename[20] = (fileNo + '@');
    return _memcardTempFilename;
}

static u_int _getNewestSaveFile()
{
    u_int i;
    u_int maxCounter = 0;
    u_int fileIndex = 0;

    for (i = 0; i < 5; ++i) {
        if (_saveFileInfo[i].unk4.slotState >= 3) {
            if (maxCounter < _saveFileInfo[i].unk4.generation) {
                maxCounter = _saveFileInfo[i].unk4.generation;
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
        if ((_saveFileInfo[i].unk4.slotState >= slotStateInUse)
            && (_saveFileInfo[i].unk4.slotState == vs_main_settings.slotState)
            && (_saveFileInfo[i].key == vs_main_settings.key)
            && (_saveFileInfo[i].unk4.saveCount == vs_main_settings.saveCount)
            && (_saveFileInfo[i].unk4.generation
                == vs_main_settings.saveFileGeneration)) {
            return i + 1;
        }
    }
    return 0;
}

static int _memcardFileNumberFromFilename(u_char* filename)
{
    int i;
    u_char const* gameCode;

    gameCode = &_pMemcardFilenameTemplate[5];

    for (i = 0; i < 15; ++i) {
        if (gameCode[i] != filename[i]) {
            return 0;
        }
    }

    i = filename[15] - 'A';

    if ((u_int)i < 5u) {
        return -(filename[15] + -'@');
    }

    i = filename[15] - '1';

    if ((u_int)i < 5u) {
        return filename[15] - '0';
    }

    return 0;
}

static int _verifySaveChecksums(savedata_t data[], int sectorCount)
{
    int checksum;
    int i;
    int j;
    u_char* p = (u_char*)data;

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

static void _decode(u_int key, u_char* buf, int count)
{
    for (; count != 0; --count) {
        key *= 0x19660D;
        *buf++ -= key >> 24;
    }
}

static int _readSaveFileInfo(int id)
{
    _saveFileInfo_t saveInfo[4];
    int bytesRead;
    int port;
    int file;
    int i;

    port = id >> 12;
    id &= 7;

    for (i = 0; i < 3; ++i) {
        file = open(_memcardMakeFilename(port, id), O_RDONLY);
        if (file == -1) {
            continue;
        }
        bytesRead = read(file, saveInfo, sizeof(saveInfo));
        close(file);
        if (bytesRead != sizeof(saveInfo)) {
            continue;
        }
        _decode(saveInfo[3].key, (u_char*)&saveInfo[3].unk4.slotState,
            sizeof(_saveFileInfo_t) - sizeof(int));
        if (_verifySaveChecksums((savedata_t*)saveInfo, 2) == 0) {
            _rMemcpy(&_saveFileInfo[id - 1], &saveInfo[3], sizeof(saveInfo[3]));
            return 0;
        }
    }

    memset(&_saveFileInfo[id - 1], 0, sizeof(_saveFileInfo[id - 1]));
    return 1;
}

static int memcardSaveIdExists(int id)
{
    int i;

    for (i = 0; i < 15; ++i) {
        u_char* filename = _memcardFiles[i]->name;
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
    int ret;

    ret = 0;
    for (i = 0; i < 5; ++i) {
        if ((memcardSaveIdExists(i + '1') != 0) && (memcardSaveIdExists(i + 'A') != 0)) {
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
    int tempFilesDeleted;
    int fileNo;
    int i;
    int slotsAvailable;
    struct DIRENTRY* file;

    slotsAvailable = 15;
    for (i = 14; i >= 0; --i) {
        _memcardFiles[i] = NULL;
    }

    fileNo = (int)firstfile((port == 1) ? ("bu00:*") : ("bu10:*"), dirEntBuf);
    _memcardFiles[0] = (void*)fileNo;

    for (i = 1; (i < 15) && fileNo; ++i) {
        fileNo = (int)nextfile(dirEntBuf + i);
        _memcardFiles[i] = (void*)fileNo;
    }

    memset(_saveFileInfo, 0, sizeof(_saveFileInfo_t) * 5);
    tempFilesDeleted = _deleteRedundantTempFiles((port - 1) * 16);
    if (tempFilesDeleted & 0x80) {
        return 1;
    }
    for (i = 0; i < 15; ++i) {
        file = _memcardFiles[i];
        if (file == NULL) {
            continue;
        }
        fileNo = _memcardFileNumberFromFilename((char*)file->name);
        if (fileNo != 0) {
            if (fileNo < 0) {
                fileNo = -fileNo;
                if ((tempFilesDeleted >> (fileNo - 1)) & 1) {
                    continue;
                }
                memset(&_saveFileInfo[fileNo - 1], 0, sizeof(_saveFileInfo_t));
                _saveFileInfo[fileNo - 1].unk4.slotState = slotStateTemporary;
            } else if (_readSaveFileInfo(((port - 1) << 16) | fileNo) != 0) {
                slotsAvailable += (file->size + 0x1FFF) >> 13;
            }
        }
        slotsAvailable -= (file->size + 0x1FFF) >> 13;
    }

    for (; slotsAvailable >= 3; slotsAvailable -= 3) {
        for (i = 0; i < 5; ++i) {
            if (_saveFileInfo[i].unk4.slotState == slotStateUnavailable) {
                _saveFileInfo[i].unk4.slotState = slotStateAvailable;
                break;
            }
        }
    }

    return 0;
}

static int _createSaveFile(int port, int id)
{
    u_char* fileName;
    long file;

    fileName = _memcardMakeFilename((port - 1) * 16, id);
    erase(fileName);
    file = open(fileName, O_CREAT | (3 << 16));
    if (file != -1) {
        close(file);
        return 0;
    }
    return -1;
}

enum memcardEventHandler_t {
    memcardEventPending = 0,
    memcardEventIoEnd = 1,
    memcardEventTimeout = 2,
    memcardEventUnformatted = 3
};

static enum memcardEventHandler_t _memcardEventHandler(int port)
{
    enum states {
        init = 0,
        ready = 1,
        unformatted = 2,
        confirmed = 3,
        loadReady = 4,
        loaded = 5,
    };

    int event;

    if (port != 0) {
        _memcardPort = (port - 1) * 16;
        _memCardState = init;
        _memCardInitTmeout = 0;
        return memcardEventPending;
    }
    switch (_memCardState) {
    case init:
        if (++_memCardInitTmeout >= 4) {
            return memcardEventTimeout;
        }
        _resetMemcardEvents(SWEVENTS);
        if (_card_info(_memcardPort) == 0) {
            break;
        }
        _memCardState = ready;
        _memCardTimeout = 0;
        _memcardEvType = SWEVENTS;
        // fallthrough
    case ready:
        switch (_testMemcardEvents(SWEVENTS)) {
        case memcardInternalEventIoEnd:
            _memCardState = loadReady;
            break;
        case memcardInternalEventError:
        case memcardInternalEventTimeout:
            _memCardState = init;
            break;
        case memcardInternalEventUnformatted:
            _memCardState = unformatted;
            break;
        case memcardInternalEventNone:
            if (_memCardTimeout++ > 64) {
                _memCardState = init;
            }
            break;
        }
        break;
    case unformatted:
        _resetMemcardEvents(HWEVENTS);
        if (_card_clear(_memcardPort) == 0) {
            break;
        }
        _memCardState = confirmed;
        _memCardTimeout = 0;
        _memcardEvType = HWEVENTS;
        // fallthrough
    case confirmed:
        do {
            event = _testMemcardEvents(HWEVENTS);
        } while (event == memcardInternalEventNone);
        if (event == memcardInternalEventIoEnd) {
            _memCardState = loadReady;
            break;
        }
        if (event < memcardInternalEventIoEnd)
            break;
        if (event >= memcardInternalEventNone)
            break;
        _memCardState = init;
        break;
    case loadReady:
        _resetMemcardEvents(SWEVENTS);
        if (_card_load(_memcardPort) == 0) {
            break;
        }
        _memCardState = loaded;
        _memCardTimeout = 0;
        // fallthrough
    case loaded:
        event = _testMemcardEvents(SWEVENTS);
        switch (event) {
        case memcardInternalEventIoEnd:
            return _memcardEvType + memcardEventIoEnd;
        case memcardInternalEventError:
        case memcardInternalEventTimeout:
            _memCardState = init;
            break;
        case memcardInternalEventUnformatted:
            return _memcardEvType + memcardEventUnformatted;
        case memcardInternalEventNone:
            if (_memCardTimeout++ > 64) {
                _memCardState = init;
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
    savedata_t* spmcimg;
    void* spmcimg2;
    savedata_t* s4;
    struct savedata_unk180_2_t* unk180;

    spmcimg = (savedata_t*)_spmcimg;
    spmcimg2 = spmcimg + 1;
    s4 = spmcimg + 1;
    unk180 = &spmcimg[1].unk180.unk180;

    _decode(unk180->key, (u_char*)(&unk180->slotState),
        sizeof(savedata_t) - (u_long) & ((savedata_t*)0)->unk180.unk180.slotState);

    blockCount = 92;
    if (verifyOnly != 0) {
        blockCount = 32;
    }

    if ((_verifySaveChecksums(spmcimg + 1, blockCount) != 0)
        || (unk180->unk18C != 0x20000107)) {
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
    vs_main_gametime.t = spmcimg[1].unk180.gameTime.t;
    func_80042CA0();
    vs_main_setMonoSound(vs_main_settings.monoSound);
    return 0;
}

static const u_short D_8006886C[] = { 0x7582, 0x6082, 0x6682, 0x7182, 0x6082, 0x6D82,
    0x7382, 0x4081, 0x7282, 0x7382, 0x6E82, 0x7182, 0x7882, 0x4081, 0x6582, 0x6882,
    0x6B82, 0x6482, 0x4081, 0x5082, 0x4081, 0x4081, 0x4081, 0x4F82, 0x4F82, 0x4681,
    0x4F82, 0x4F82, 0x4681, 0x4F82, 0x4F82, 0x4081 };

void func_80069888(int arg0)
{
    int i;
    int j;
    int var_a0;
    savedata_t* savedata;
    savedata_t* savedata2;
    savedata_t* savedata3;
    struct savedata_unk180_t* s5;
    u_short const* s0 = D_8006886C;

    savedata = (savedata_t*)_spmcimg;
    savedata2 = savedata + 1;
    savedata3 = savedata;
    s5 = &savedata->unk180;

    vs_main_gametime.all = 0;
    vs_main_settings.unk2 &= 0xFFDF;
    vs_main_puzzleMode = ~(*(u_int*)&vs_main_settings >> 3) & 1;
    memset(savedata, 0, sizeof(*savedata));
    savedata->unk0 = 0x53;
    savedata->unk1 = 0x43;
    savedata->unk2 = 0x11;
    savedata->unk3 = 3;
    _rMemcpy(&savedata->unk4, s0, sizeof(savedata->unk4));
    savedata->unk4.unk20[3] += (arg0 << 8);

    if (vs_main_gametime.t.h == 100) {
        savedata->unk4.unk20[6] = 0x5082;
    } else {
        savedata->unk4.unk20[7] += ((vs_main_gametime.t.h / 10) << 8);
        savedata->unk4.unk20[8] += ((vs_main_gametime.t.h % 10) << 8);
        savedata->unk4.unk20[10] += ((vs_main_gametime.t.m / 10) << 8);
        savedata->unk4.unk20[11] += ((vs_main_gametime.t.m % 10) << 8);
        savedata->unk4.unk20[13] += ((vs_main_gametime.t.s / 10) << 8);
        savedata->unk4.unk20[14] += ((vs_main_gametime.t.s % 10) << 8);
    }
    savedata3->unk4.unk20[15] = 0;
    _rMemcpy(savedata3->unk60, _mcData->unk400[arg0], sizeof(savedata->unk60));
    _rMemcpy(savedata3->unk80, _mcData->unk4E0[arg0], sizeof(savedata->unk80));

    if (vs_main_settings.slotState == 0) {
        vs_main_settings.slotState = _encode(0x20);
        if (vs_main_settings.slotState < 3) {
            vs_main_settings.slotState = 0x17385CA9;
        }
        memset(&savedata2->unk1DE0, 0, sizeof(savedata2->unk1DE0));
    }

    vs_main_settings.key = _encode(0x20);
    s5->unk180.key = vs_main_settings.key;
    s5->unk180.slotState = vs_main_settings.slotState;
    vs_main_settings.saveFileGeneration = 0;

    for (i = 0; i < 5; ++i) {
        if (_saveFileInfo[i].unk4.slotState >= slotStateInUse) {
            if (vs_main_settings.saveFileGeneration < _saveFileInfo[i].unk4.generation) {
                vs_main_settings.saveFileGeneration = _saveFileInfo[i].unk4.generation;
            }
        }
    }
    s5->unk180.unk188 = ++vs_main_settings.saveFileGeneration;
    if (vs_main_settings.saveCount < 9999) {
        ++vs_main_settings.saveCount;
    }

    vs_main_settings.unk1A = 0;
    s5->unk180.unk18C = 0x20000107;
    s5->gameTime.t = vs_main_gametime.t;
    s5->unk198 = D_80060068.unk0.unk4[0];
    s5->unk19A = D_80060068.unk0.unk4[1];
    s5->saveCount = vs_main_settings.saveCount;
    s5->unk196 = vs_main_settings.unk1A;
    s5->unk19C = 0x30;
    s5->unk19E = 0;
    memset(D_80060168[14], 0, sizeof(D_80060168[14]));
    memset(&D_800619D8.unk70, 0, sizeof(D_800619D8.unk70));
    memset(savedata2->unk1DE0.unk55E0, 0, sizeof(savedata2->unk1DE0.unk55E0));
    s5->unk19D = D_80061598[0];
    s5->unk1A0 = D_80060068.unk0.unk4[2];
    s5->unk1A2 = D_80060068.unk0.unk4[3];
    _rMemcpy(savedata->unk200, D_80061598, sizeof(savedata->unk200));
    _rMemcpy(savedata->unk640, vs_main_skillsLearned, sizeof(savedata->unk640));
    _rMemcpy(savedata->unk660, D_8005FFD8, sizeof(savedata->unk660));
    _rMemcpy(&savedata->unk6A8, &vs_main_settings, sizeof(savedata->unk6A8));
    _rMemcpy(&savedata->unk6C8, &D_80060068, sizeof(savedata->unk6C8));
    _rMemcpy(savedata->unk7C8, D_80060168, sizeof(savedata->unk7C8));
    _rMemcpy(savedata->unk16C8, &D_800619D8, sizeof(savedata->unk16C8));
    _rMemcpy(&savedata->unk1778, &D_80061068, sizeof(savedata->unk1778));
    _rMemcpy(&savedata->unk1784, &D_8005FEA0, sizeof(savedata->unk1784));
    _rMemcpy(&savedata->unk1DE0, &savedata2->unk1DE0, sizeof(savedata->unk1DE0));
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
    for (i = (int)&((savedata_t*)0)->unk180.unk180.slotState; i < (int)sizeof(savedata_t);
         ++i) {
        _spmcimg[i] += _encode(8);
    }
}

static int _loadSaveData(int portFileno)
{
    enum loadSaveDataState { init = 0, reading = 1 };

    int ev;
    int nBytes;
    u_char* filename;
    void* temp_s2;
    int new_var;

    temp_s2 = (savedata_t*)_spmcimg + 1;
    if (portFileno != 0) {
        _loadSaveDataState = init;
        _loadSaveDataErrors = 0;
        _loadSaveDataErrorOffset = 0;
        _readCardPort = portFileno >> 0xC;
        _isTempSave = (portFileno >> 8) & 1;
        _readFileNo = portFileno & 0xF;
        D_800DEB12 = 80;
        D_800DEB10 = 0;
        return 0;
    }

    switch (_loadSaveDataState) {
    case init:
        new_var = 320;
        D_800DEB12 += ((D_800DEB14 - D_800DEB10)
                          * ((_loadSaveDataErrorOffset * 20) - (D_800DEB12 - new_var)))
            / D_800DEB0E;
        _loadSaveDataErrorOffset = _loadSaveDataErrors;
        D_800DEB0E = 192 - (_isTempSave << 7);
        D_800DEB10 = D_800DEB14;

        memset(temp_s2, 0, sizeof(savedata_t));

        if (_readFileNo & 8) {
            filename = _memcardMakeTempFilename(_readCardPort, _readFileNo & 7);
        } else {
            filename = _memcardMakeFilename(_readCardPort, _readFileNo);
        }
        _memCardFd = open((char*)filename, O_NOWAIT | O_RDONLY);
        if (_memCardFd == -1) {
            ++_loadSaveDataErrors;
            break;
        }
        _resetMemcardEvents(SWEVENTS);
        nBytes = sizeof(savedata_t);
        if (_isTempSave != 0) {
            nBytes = 0x2000;
        }
        if (read(_memCardFd, temp_s2, nBytes) == -1) {
            close(_memCardFd);
            ++_loadSaveDataErrors;
            break;
        }
        _loadSaveDataState = reading;
        // fallthrough
    case reading:
        ev = _testMemcardEvents(SWEVENTS);
        if (ev < memcardInternalEventNone) {
            close(_memCardFd);
            if (ev == memcardInternalEventIoEnd) {
                return 1;
            }
            _loadSaveDataState = init;
            ++_loadSaveDataErrors;
        }
        break;
    }
    return _loadSaveDataErrors == 3 ? -1 : 0;
}

int func_8006A11C(int arg0)
{
    enum memcardSaveState {
        init = 0,
        tempFileCreated = 1,
        readReady = 2,
        verifyPending = 3,
        fileVerified = 4
    };

    int temp_v1_2;
    int i;
    int temp_s3;

    if (arg0 != 0) {
        D_800DC8BB = 0;
        D_800DC8BC = 0;
        _loadSaveDataErrorOffset = 0;
        _memcardManagerPort = arg0 >> 0xC;
        _memcardFileno = arg0 & 7;
        D_800DEB12 = 80;
        D_800DEB10 = 0;
        _memcardSaveState = memcardSaveIdExists(_memcardFileno + 'A' - 1);
        return 0;
    }
    switch (_memcardSaveState) {
    case init:
        if (rename((char*)_memcardMakeFilename(_memcardManagerPort, _memcardFileno),
                (char*)_memcardMakeTempFilename(_memcardManagerPort, _memcardFileno))
            != 0) {
            D_800DC8BB = 0;
            D_800DC8BC = 0;
            _memcardSaveState = tempFileCreated;
        } else {
            ++D_800DC8BC;
            D_800DC8BB = D_800DC8BC >> 4;
        }
        break;
    case tempFileCreated:
        temp_v1_2 = ((D_800DEB14 - D_800DEB10) * (320 - D_800DEB12)) / D_800DEB0E;
        D_800DEB10 = D_800DEB14;
        D_800DEB0E = 384;
        D_800DEB12 += temp_v1_2;
        _saveFileId
            = open((char*)_memcardMakeTempFilename(_memcardManagerPort, _memcardFileno),
                O_NOWAIT | O_WRONLY);
        ;
        if (_saveFileId == -1) {
            ++D_800DC8BB;
            break;
        }
        _resetMemcardEvents(SWEVENTS);
        if (write(_saveFileId, _spmcimg, sizeof(savedata_t)) == -1) {
            close(_saveFileId);
            ++D_800DC8BB;
            break;
        }
        _memcardSaveState = readReady;
        // fallthrough
    case readReady: {
        temp_s3 = _testMemcardEvents(SWEVENTS);
        if (temp_s3 < memcardInternalEventNone) {
            close(_saveFileId);
            if (temp_s3 == memcardInternalEventIoEnd) {
                _memcardSaveState = verifyPending;
                i = D_800DEB12;
                temp_s3 = D_800DEB10;
                _loadSaveData((_memcardManagerPort << 12) | (_memcardFileno + 8));
                D_800DEB12 = i;
                D_800DEB10 = temp_s3;
            } else {
                ++D_800DC8BB;
                _memcardSaveState = tempFileCreated;
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
        _memcardSaveState = fileVerified;
        break;
    case fileVerified:
        if (rename((char*)_memcardMakeTempFilename(_memcardManagerPort, _memcardFileno),
                (char*)_memcardMakeFilename(_memcardManagerPort, _memcardFileno))
            == 0) {
            ++D_800DC8BC;
            D_800DC8BB = (D_800DC8BC >> 4);
            break;
        }
        return 1;
    }
    return D_800DC8BB == 3 ? -1 : 0;
}

static int _loadMemcardMenu(int init)
{

    enum diskState {
        none = 0,
        queueReady = 1,
        enqueued = 2,
    };

    vs_main_CdFile cdFile;
    int i;
    u_int event;

    if (init != 0) {
        _spmcimg = (u_char*)vs_main_allocHeap(VS_SPMCIMG_BIN_SIZE);
        _mcData = (mcdata_t*)(_spmcimg + sizeof(savedata_t) * 3);
        _textTable = _mcData->textTable;
        _saveFileInfo = _mcData->saveFileInfo;
        dirEntBuf = &_mcData->direntBuf;
        cdFile.lba = VS_SPMCIMG_BIN_LBA;
        cdFile.size = VS_SPMCIMG_BIN_SIZE;
        _mcDataLoad = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(_mcDataLoad, _spmcimg);
        _diskState = none;
        return 0;
    }

    switch (_diskState) {
    case none:
        if (_mcDataLoad->state == vs_main_CdQueueStateLoaded) {
            vs_main_freeCdQueueSlot(_mcDataLoad);
            _drawImage(MAKEXY(800, 256), (u_long*)_spmcimg, MAKEWH(224, 256));
            _diskState = queueReady;
        }
        return 0;
    case queueReady:
        cdFile.lba = VS_MCDATA_BIN_LBA; // MCMAN.BIN must immediately follow MCDATA.BIN on
                                        // the disk
        cdFile.size = VS_MCDATA_BIN_SIZE + VS_MCMAN_BIN_SIZE;
        _mcDataLoad = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(_mcDataLoad, _mcData);
        _diskState = enqueued;
        break;
    case enqueued:
        break;
    default:
        return 0;
    }

    if (_mcDataLoad->state == vs_main_CdQueueStateLoaded) {
        vs_main_freeCdQueueSlot(_mcDataLoad);
        vs_main_enableReset(0);
        EnterCriticalSection();

        for (i = 0; i < 8; ++i) {
            event = SwCARD;
            if (i & 4) {
                event = HwCARD;
            }
            memcardEventDescriptors[i]
                = OpenEvent(event, eventSpecs[i & 3], EvMdNOINTR, NULL);
        }

        ExitCriticalSection();

        for (i = 0; i < 8; ++i) {
            EnableEvent(memcardEventDescriptors[i]);
        }
        return 1;
    }
    return 0;
}

static void _shutdownMemcard()
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
    vs_main_freeHeap(_spmcimg);
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

static void _drawSaveInfoUI(int xy, enum vs_fileMenuUiIds_e id)
{
    _drawSprt(xy, _saveInfoUVClut[id], _saveInfoWh[id],
        getTPage(clut4Bit, semiTransparencyHalf, 768, 0));
}

static void _drawInteger(int xy, u_int value, u_int placeDivisor)
{
    do {
        _drawSprt(xy, vs_getUV0Clut(((value / placeDivisor) * 6), 0, 832, 223),
            MAKEWH(6, 10), getTPage(0, 0, 768, 0));
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
    wh = MAKEWH(66, 5);
    x1y1 = (currentValueDigits + MAKEXY(0, 9));
    _primBuf.prim.tilePoly.tile.x0y0 = xy++ + MAKEXY(0, 8);
    _primBuf.prim.tilePoly.tile.wh = wh;
    _primBuf.prim.tilePoly.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4, rgb1);
    _primBuf.prim.tilePoly.polyG4.x0y0 = xy + MAKEXY(0, 9);
    _primBuf.prim.tilePoly.polyG4.r1g1b1 = rgb0;
    _primBuf.prim.tilePoly.polyG4.x1y1 = xy + x1y1;
    _primBuf.prim.tilePoly.polyG4.r2g2b2 = rgb1;
    _primBuf.prim.tilePoly.polyG4.x2y2 = xy + MAKEXY(0, 12);
    _primBuf.prim.tilePoly.polyG4.r3g3b3 = rgb0;
    _primBuf.prim.tilePoly.polyG4.x3y3 = MAKEXY(0, 12);
    _primBuf.prim.tilePoly.polyG4.x3y3
        = xy + (currentValueDigits + _primBuf.prim.tilePoly.polyG4.x3y3);
    DrawPrim(&_primBuf);

    currentValueDigits = _countDigits(currentValue);
    maxValueDigits = _countDigits(maxValue);
    _drawSaveInfoUI(xy - 1, stat + vs_uiids_hp);
    wh = currentValueDigits * 6;
    new_var4 = 55;
    xy = (xy - (wh - new_var4)) - (maxValueDigits * 5);
    placeDivisor = _digitsDivisors[currentValueDigits];
    do {
        _drawSprt(xy - MAKEXY(0, 1),
            (((currentValue / placeDivisor) << 3) + 64) | (getClut(832, 223) << 16),
            MAKEWH(7, 12), getTPage(0, 0, 768, 0));
        currentValue = currentValue % placeDivisor;
        placeDivisor /= 10;
        xy += 6;
    } while (placeDivisor != 0);
    _drawSaveInfoUI(xy + 1, vs_uiids_dot);
    _drawInteger(xy + 6, maxValue, _digitsDivisors[maxValueDigits]);
}

static void _fileProcessingAnim(int x, int y)
{
    u_char* new_var __attribute__((unused));
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
        _primBuf.prim.polyG4_tpage.x2y2 = leftEdge | (y + MAKEXY(0, 32));
        _primBuf.prim.polyG4_tpage.tpage
            = vs_getTpage(0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
        _primBuf.prim.polyG4_tpage.r1g1b1 = gradientColor2;
        _primBuf.prim.polyG4_tpage.r2g2b2 = gradientColor1;
        _primBuf.prim.polyG4_tpage.r3g3b3 = gradientColor2;
        _primBuf.prim.polyG4_tpage.x3y3 = x | (y + MAKEXY(0, 32));
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

void func_8006AE10()
{
    _selectSaveMemoryCardMessage = NULL;
    _selectCursorColor = 0;
    _selectCursorXy = 0;
    D_800DEB14 = 0;
    _fileMenuScreenFade = 0;
    D_800DEB0E = 384;
    memset(_fileMenuElements, 0, sizeof(_fileMenuElements));
}

static _fileMenuElements_t* _initFileMenuElement(int id, int xy, int wh, u_char* text)
{
    _fileMenuElements_t* entry;
    int i;
    u_int c;

    entry = &_fileMenuElements[id];
    memset(entry, 0, sizeof(*entry));
    entry->state = 1;
    entry->slotId = -1;
    *(int*)&entry->x = xy;
    *(int*)&entry->w = wh;

    if (text != NULL) {
        for (i = 0; i < 32;) {
            c = *text++;
            if (c == vs_char_spacing) {
                entry->text[i++] = c;
                do {
                    c = *(text++);
                } while (0);
            } else {
                if (c == vs_char_terminator) {
                    entry->text[i] = 0xFF;
                    return entry;
                }
                if (c >= vs_char_nonPrinting) {
                    continue;
                }
            }
            entry->text[i++] = c;
        }
    } else {
        entry->text[0] = 0xFF;
    }
    return entry;
}

static void _clearFileMenuEntry(int id)
{
    memset(&_fileMenuElements[id], 0, sizeof(_fileMenuElements_t));
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
    if ((c >> 8) == 14) {
        return x + (u_char)c;
    }
    if (c != vs_char_space) {
        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.sprt, primAddrNull);
        _primBuf.prim.sprt.tpage
            = vs_getTpage(832, 0, clut4Bit, semiTransparencyFull, ditheringOff);
        _primBuf.prim.sprt.r0g0b0code = vs_getRGB0(primSprtSemtTrans, 128, 128, 128);
        _primBuf.prim.sprt.x0y0 = vs_getYX(y, x);
        _primBuf.prim.sprt.wh = vs_getWH(12, 12);
        _primBuf.prim.sprt.u0v0clut
            = vs_getUV0Clut((c % 21) * 12, (c / 21) * 12, clut * 16 + 896, 222);
        DrawPrim(&_primBuf);
    }
    return x + _fontCharacterWidths[c];
}

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
        _selectSaveMemoryCardMessage
            = (u_char*)(_textTable + _textTable[VS_MCMAN_INDEX_accessing0 - 1 + port]);
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

static int _memcardMaskedHandler(int portMask)
{
    int memcardEvent;

    if (portMask != 0) {
        _memcardEventHandler(portMask & 3);
        _memcardEventMask = (portMask >> 4);
        return 0;
    }
    memcardEvent = _memcardEventHandler(0);
    if (memcardEvent != memcardEventPending) {
        switch (memcardEvent & _memcardEventMask) {
        case memcardEventIoEnd:
            return 1;
        case memcardEventTimeout:
            _selectSaveMemoryCardMessage
                = (u_char*)(_textTable + VS_MCMAN_OFFSET_insertError);
            break;
        case memcardEventUnformatted:
            _selectSaveMemoryCardMessage = (u_char*)(_textTable + VS_MCMAN_OFFSET_noData);
            break;
        default:
            _selectSaveMemoryCardMessage
                = (u_char*)(_textTable + VS_MCMAN_OFFSET_removed);
            break;
        }
        return -1;
    }
    return 0;
}

static void _printString(u_char* text, int x, int y, int clut)
{
    u_char arrowState;
    u_int c;
    int startX = x;
    int nextX = x;

    while (1) {
        c = *text++;
        if (c < vs_char_control) {
            if (c < vs_char_nonPrinting) {
                nextX = _printCharacter(c, nextX, y, clut);
            } else if (c == vs_char_confirm) {
                arrowState = (_arrowCharState + 1) % 12;
                c = vs_char_arrow - (arrowState >> 2);
                _arrowCharState = arrowState;
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
    u_int color1;
    u_int color2;

    if (innerFactor < 9) {
        color1 = _interpolateRGB(
            vs_getRGB888(0, 65, 107), vs_getRGB888(25, 130, 108), innerFactor);
        color2 = _interpolateRGB(
            vs_getRGB888(0, 5, 51), vs_getRGB888(1, 40, 38), innerFactor);
    } else {
        color1 = D_80072EFC[((innerFactor >> 3) - 2)];
        color2 = D_80072F04[((innerFactor >> 3) - 2)];
    }
    return _interpolateRGB(color1, color2, outerFactor);
}

static void _drawFileMenuEntry(_fileMenuElements_t* menuEntry)
{
    u_long clut[130];
    _saveFileInfo_t* saveInfo;
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

    if (menuEntry->selected != 0) {
        menuEntry->outerBlendFactor = 8;
    } else if (menuEntry->outerBlendFactor != 0) {
        --menuEntry->outerBlendFactor;
    }
    if (menuEntry->slotUnavailable != 0) {
        menuEntry->outerBlendFactor = 0;
    }
    if ((menuEntry->slotId >= 5) || ((menuEntry->y - 72) < 0x51U)) {
        y = menuEntry->innerBlendFactor;
        var1 = _intepolateMenuItemBgColour(8 - menuEntry->outerBlendFactor, y);
        var2 = _intepolateMenuItemBgColour(menuEntry->outerBlendFactor, y);
        if (y & 7) {
            menuEntry->innerBlendFactor = y + 1;
        }
        y = menuEntry->y << 16;

        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.tilePoly, primAddrNull);
        _primBuf.prim.tilePoly.tile.tpage
            = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
        _primBuf.prim.tilePoly.tile.r0g0b0code = vs_getRGB0(primTile, 0, 0, 0);
        _primBuf.prim.tilePoly.tile.x0y0 = vs_getYX(menuEntry->y + 2, menuEntry->x + 2);
        _primBuf.prim.tilePoly.tile.wh = menuEntry->w | (menuEntry->h << 0x10);
        _primBuf.prim.tilePoly.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4, var1);
        _primBuf.prim.tilePoly.polyG4.x0y0 = (u_short)menuEntry->x | y;
        _primBuf.prim.tilePoly.polyG4.r1g1b1 = var2;
        _primBuf.prim.tilePoly.polyG4.x1y1 = ((menuEntry->x + menuEntry->w) & 0xFFFF) | y;
        _primBuf.prim.tilePoly.polyG4.r2g2b2 = var1;
        _primBuf.prim.tilePoly.polyG4.x2y2
            = (u_short)menuEntry->x | ((menuEntry->y + menuEntry->h) << 0x10);
        _primBuf.prim.tilePoly.polyG4.r3g3b3 = var2;
        _primBuf.prim.tilePoly.polyG4.x3y3 = ((menuEntry->x + menuEntry->w) & 0xFFFF)
            | ((menuEntry->y + menuEntry->h) << 0x10);
        DrawPrim(&_primBuf);

        x = menuEntry->x + 6;
        for (var1 = 0; var1 < 32; ++var1) {
            var2 = menuEntry->text[var1];
            if (var2 == vs_char_spacing) {
                x += menuEntry->text[++var1];
            } else if (var2 != 0xFF) {
                x = _printCharacter(var2, x, menuEntry->y, 0);
            } else {
                break;
            }
        }
        var2 = menuEntry->slotId;
        if (var2 < 5) {
            _readImage(MAKEXY(768, 227), clut, MAKEWH(256, 1));
            saveInfo = &_saveFileInfo[var2];
            location = menuEntry->saveLocation - 1;
            var1 = saveInfo->unk4.slotState;
            if (saveInfo->unk4.slotState < 3) {
                if (saveInfo->unk4.slotState == 0) {
                    location = -2;
                } else if (saveInfo->unk4.slotState == 2) {
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
            _drawImage(MAKEXY(768, 227), locationClut, MAKEWH(256, 1));
            if (location < 0) {
                uvClut = (~location << 13) | vs_getUV0Clut(64, 0, 768, 227);
                xy = (menuEntry->x - 64) | y;
                _drawSprt(xy, uvClut, MAKEWH(64, 32),
                    ((8 - menuEntry->outerBlendFactor) << 19) | 0x9C);
            } else {
                int v0;
                uvClut = ((location & 8) * 8) | ((location & 7) << 0xD)
                    | vs_getUV0Clut(0, 0, 768, 227);
                xy = (menuEntry->x - 64) | y;
                new_var = (((location & 0x30) * 4) + 832) & 0x3FF;
                v0 = new_var >> 6;
                var_a3 = (((8 - menuEntry->outerBlendFactor) << 19) | 0x90);
                _drawSprt(xy, uvClut, MAKEWH(64, 32), v0 | var_a3);
            }
            _drawImage(MAKEXY(768, 227), clut, MAKEWH(256, 1));
            _drawSaveInfoUI((menuEntry->x - 22) | y, vs_uiids_number);
            _drawInteger((menuEntry->x - 9) | y, var2 + 1, 0xAU);
            slotState = saveInfo->unk4.slotState;
            if (slotState == slotStateUnavailable) {
                _printString((u_char*)(_textTable + VS_MCMAN_OFFSET_inUse),
                    menuEntry->x + 6, menuEntry->y + 10, 3);
            } else if (slotState == slotStateAvailable) {
                if (_isSaving == 0) {
                    _printString((u_char*)(_textTable + VS_MCMAN_OFFSET_empty),
                        menuEntry->x + 6, menuEntry->y + 10, 3);
                } else {
                    _printString((u_char*)(_textTable + VS_MCMAN_OFFSET_new),
                        menuEntry->x + 6, menuEntry->y + 10, 0);
                }
            } else {
                y += 4 << 16;
                _printString((u_char*)&_textTable[_textTable[menuEntry->saveLocation
                                 + VS_MCMAN_INDEX_saveLocations]],
                    menuEntry->x + 6, menuEntry->y + 4, 0);
                _drawSaveInfoUI(y | 172, vs_uiids_map);
                _drawSaveInfoUI(y | 189, vs_uiids_colon);
                var1 = saveInfo->unk4.mapCompletion;

                if (var1 == 100) {
                    _drawInteger(y | 192, 100, 100);
                    _drawSaveInfoUI((y + 0xFFFF0000) | 207, vs_uiids_percent);
                } else {
                    _drawInteger(y | 192, var1, 10);
                    _drawSaveInfoUI((y + 0xFFFF0000) | 202, vs_uiids_percent);
                }
                _drawSaveInfoUI(y | 217, vs_uiids_save);
                _drawSaveInfoUI(y | 239, vs_uiids_colon);
                _drawInteger(y | 242, saveInfo->unk4.saveCount, 1000);
                _drawSaveInfoUI(y | 267, vs_uiids_clear);
                _drawSaveInfoUI(y | 293, vs_uiids_colon);
                _drawInteger(y | 296, saveInfo->unk4.clearCount, 10);
                y += 13 << 16;
                if (saveInfo->unk4.clearCount != 0) {
                    _drawSprt(y | 69, vs_getUV0Clut(240, 16, 912, 223), MAKEWH(16, 16),
                        getTPage(clut4Bit, semiTransparencyHalf, 768, 0));
                }
                _drawSaveInfoUI(y | 240, vs_uiids_time);
                var1 = saveInfo->unk4.hours;
                if (var1 == 100) {
                    _drawInteger(y | 263, var1, 100);
                } else {
                    _drawInteger(y | 268, var1, 10);
                }
                _drawSaveInfoUI(y | 279, vs_uiids_colon);
                _drawInteger(y | 282, saveInfo->unk4.minutes, 10);
                _drawSaveInfoUI(y | 293, vs_uiids_colon);
                _drawInteger(y | 296, saveInfo->unk4.seconds, 10);
                _drawHPMP(
                    y | 88, statTypeHP, saveInfo->unk4.currentHP, saveInfo->unk4.maxHP);
                _drawHPMP(
                    y | 158, statTypeMP, saveInfo->unk4.currentMP, saveInfo->unk4.maxMP);
                y -= 17 << 16;
            }
            if ((menuEntry->selected != 0) && (D_800DEB14 != 0)) {
                if (D_800DEB14 < 0) {
                    int v0 = D_800DEB14++;
                    char* p = _selectCursorColors + v0;
                    _fileProcessingCompleteAnim(-p[17], y);
                } else {
                    int new_var3 = 0x140;
                    _fileProcessingAnim(D_800DEB12
                            + (((D_800DEB14 - D_800DEB10)
                                   * ((_loadSaveDataErrorOffset * 0x14)
                                       - (D_800DEB12 - new_var3)))
                                / D_800DEB0E),
                        y);
                }
            }
        }
    }
}

static void _drawSaveMenu(int framebuf)
{
    int dummy[2];
    _fileMenuElements_t* entry;
    int j;
    int i;
    u_int x;
    int state;
    int new_var;

    entry = _fileMenuElements;
    x = 0;
    if (framebuf != 0) {
        x = 320;
    }
    _drawSprt(MAKEXY(256, 176), vs_getUV0Clut(0, 176, 768, 227), MAKEWH(64, 64),
        getTPage(clut8Bit, semiTransparencyHalf, 768, 256));
    _drawSprt(MAKEXY(0, 176), vs_getUV0Clut(0, 176, 768, 227), MAKEWH(256, 64),
        getTPage(clut8Bit, semiTransparencyHalf, 640, 256));

    for (i = 0; i < 10; ++i, ++entry) {
        state = entry->state;
        if (state == 2) {
            if (entry->x < entry->targetPosition) {
                entry->x += 32u;
                if (entry->x >= entry->targetPosition) {
                    entry->x = entry->targetPosition;
                    entry->state = 1;
                }
            } else {

                for (j = 1; j < 16; ++j) {
                    if ((entry->targetPosition + D_8007289C[j]) >= entry->x) {
                        break;
                    }
                }
                entry->x = entry->targetPosition + D_8007289C[j - 1];
                if (entry->w < (0x140 - entry->x)) {
                    entry->w = (0x140 - entry->x);
                }
                if (entry->x == entry->targetPosition) {
                    entry->state = 1;
                }
            }
        }
        if (state == 3) {
            if (entry->y > entry->targetPosition) {
                for (j = 1; j < 16; ++j) {
                    if ((entry->targetPosition + D_8007289C[j]) >= entry->y) {
                        break;
                    }
                }
                entry->y = (entry->targetPosition + D_8007289C[j - 1]);
            }
            if (entry->y == entry->targetPosition) {
                entry->state = 1;
            }
        }
        if (state == 4) {
            if (entry->x < entry->targetPosition) {
                for (j = 1; j < 16; ++j) {
                    if (entry->x >= (-D_8007289C[j])) {
                        break;
                    }
                }
                entry->x = -D_8007289C[j - 1];
                if (entry->x == 0) {
                    entry->state = 1;
                }
            } else {
                entry->x = entry->x - 32;
                if (entry->targetPosition >= entry->x) {
                    entry->x = entry->targetPosition;
                    entry->state = 1;
                }
            }
        }
        if (state != 0) {
            _drawFileMenuEntry(entry);
        }
    }

    for (i = 1; i < 4; ++i) {
        new_var = 256;
        _drawSprt(MAKEXY(0, 187 - i), (187 - i) << 8, MAKEWH(256, 1),
            (x >> 6) | (((4 - i) << 21) | new_var));
        _drawSprt(MAKEXY(256, 187 - i), (187 - i) << 8, MAKEWH(64, 1),
            (((int)(x + new_var)) >> 6) | (((4 - i) << 21) | new_var));
    }
    _drawSprt(MAKEXY(10, 181), vs_getUV0Clut(64, 145, 848, 223), MAKEWH(33, 7),
        getTPage(clut4Bit, semiTransparencyHalf, 768, 0)); // "Caution"
    DrawSync(0);
    _primBuf.tag = vs_getTag(_primBuf.prim.tile, primAddrNull);
    _primBuf.prim.tile.r0g0b0code = vs_getRGB0(primTile, 0, 0, 0);
    _primBuf.prim.tile.x0y0 = vs_getXY(0, 187);
    _primBuf.prim.tile.wh = vs_getWH(320, 52);
    DrawPrim(&_primBuf); // Message dialog background
    if (_selectCursorXy != 0) {
        _drawSprt(_selectCursorXy, vs_getUV0Clut(32, 48, 896, 223), MAKEWH(16, 16),
            (_selectCursorColors[_selectCursorColor] << 16)
                | getTPage(clut4Bit, semiTransparencyHalf, 768, 0));
        _selectCursorColor = (_selectCursorColor + 1) & 0xF;
        if (vs_main_buttonsPressed & PADRup) {
            vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
        }
    } else {
        _selectCursorColor = 0;
    }
    if (_selectSaveMemoryCardMessage != NULL) {
        _printString(_selectSaveMemoryCardMessage, 16, 192, 0);
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

static void _drawSaveMenuBg()
{
    _drawSprt(MAKEXY(256, 0), vs_getUV0Clut(0, 0, 768, 227), MAKEWH(64, 176),
        getTPage(clut8Bit, semiTransparencyHalf, 768, 256));
    _drawSprt(MAKEXY(0, 0), vs_getUV0Clut(0, 0, 768, 227), MAKEWH(256, 176),
        getTPage(clut8Bit, semiTransparencyHalf, 640, 256));
}

static int _selectFileToLoad(int arg0)
{
    enum state {
        init = 0,
        handleInput = 1,
        startLoad = 2,
        applyLoad = 3,
        loaded = 4,
        exiting = 5
    };

    _fileMenuElements_t* entry;
    int currentSlot;
    int i;

    if (arg0 != 0) {
        D_800DC8D9 = arg0;
        _selectedSlot = _getNewestSaveFile();
        _slotsPage = 0;
        if (_selectedSlot == 4) {
            _slotsPage = 2;
            _selectedSlot = 2;
        } else if (_selectedSlot != 0) {
            _slotsPage = _selectedSlot - 1;
            _selectedSlot = 1;
        }
        _fileLoaded = -1;
        _fileLoadCompleteTimer = 0;
        _fileToLoadState = init;
        return 0;
    }
    switch (_fileToLoadState) {
    case init:
        for (i = 0; i < 5; ++i) {
            entry = _initFileMenuElement(
                i + 5, ((72 + i * 40) << 16) | 64, MAKEWH(256, 32), 0);
            entry->slotId = i;
            entry->slotUnavailable = _saveFileInfo[i].unk4.slotState < slotStateInUse;
            entry->saveLocation = _saveFileInfo[i].unk4.saveLocation;
        }
        _fileToLoadState = handleInput;
        _selectSaveMemoryCardMessage = (u_char*)(_textTable + VS_MCMAN_OFFSET_selectFile);
        // fallthrough
    case handleInput:
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            for (i = 5; i < 10; ++i) {
                _clearFileMenuEntry(i);
            }
            _selectCursorXy = 0;
            return -1;
        }
        for (i = 0; i < 5; ++i) {
            _fileMenuElements[i + 5].y = (((i - _slotsPage) * 40) + 72);
            _fileMenuElements[i + 5].selected = 0;
        }

        currentSlot = _selectedSlot + _slotsPage;

        if (vs_main_buttonsPressed & PADRright) {
            if (_saveFileInfo[currentSlot].unk4.slotState >= slotStateInUse) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                _fileMenuElements[currentSlot + 5].selected = 1;
                _selectCursorXy = 0;
                _memcardMaskedHandler(D_800DC8D9 + memcardEventMaskAll);
                _fileToLoadState = startLoad;
                break;
            }
            vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
        }
        if (vs_main_buttonRepeat & PADLup) {
            if (_selectedSlot == 0) {
                if (_slotsPage != 0) {
                    --_slotsPage;
                }
            } else {
                --_selectedSlot;
            }
        }
        if (vs_main_buttonRepeat & PADLdown) {
            if (_selectedSlot == 2) {
                if (_slotsPage < 2) {
                    ++_slotsPage;
                }
            } else {
                ++_selectedSlot;
            }
        }
        if (currentSlot != (_selectedSlot + _slotsPage)) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
        }
        _selectCursorXy = ((_selectedSlot * 40 + 62) << 16) | 24;
        _fileMenuElements[currentSlot + 5].selected = 1;
        break;
    case startLoad:
        currentSlot = _memcardMaskedHandler(0);
        if (currentSlot != memcardMaskedHandlerPending) {
            if (currentSlot >= memcardMaskedHandlerPending) {
                int new_var;
                _loadSaveData(((_selectedSlot + _slotsPage) + 1)
                    | (new_var = ((D_800DC8D9 - 1) << 16) | 256));
                _fileToLoadState = applyLoad;
                _selectSaveMemoryCardMessage
                    = (u_char*)(_textTable + VS_MCMAN_OFFSET_loading);
            } else {
                _fileToLoadState = loaded;
            }
        }
        break;
    case applyLoad:
        currentSlot = _loadSaveData(0);
        ++D_800DEB14;
        if (currentSlot != 0) {
            D_800DEB14 = 0;
            do {
                D_800DC8DC = 0;
                if (currentSlot < 0) {
                    _selectSaveMemoryCardMessage
                        = (u_char*)(_textTable + VS_MCMAN_OFFSET_loadfailed);
                    break;
                }
                switch (_applyLoadedSaveFile(1)) {
                case 0:
                    D_800DEB14 = -16;
                    vs_main_playSfxDefault(0x7E, VS_SFX_FILEOPCOMPLETE);
                    D_800DC8DC = 16;
                    _fileLoaded = 1;
                    _selectSaveMemoryCardMessage
                        = (u_char*)(_textTable + VS_MCMAN_OFFSET_loaded);
                    break;
                case 1:
                    _selectSaveMemoryCardMessage
                        = (u_char*)(_textTable + VS_MCMAN_OFFSET_fileCorruptDescription);
                    break;
                }
            } while (0);

            D_800DC8D0.t = vs_main_gametime.t;
            _fileToLoadState = loaded;
        }
        break;
    case loaded:
        if (D_800DC8DC != 0) {
            --D_800DC8DC;
        }
        if (_fileLoaded == 1) {
            ++_fileLoadCompleteTimer;
        }
        if (((u_char)vs_main_buttonsPressed != 0) || (_fileLoadCompleteTimer == 150)) {
            if (_fileLoaded < 0) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            }
            _fileToLoadState = exiting;
        }
        break;
    case exiting:
        if (D_800DC8DC != 0) {
            --D_800DC8DC;
            break;
        }
        if (_fileLoaded == 1) {
            vs_main_gametime.t = D_800DC8D0.t;
        } else {
            for (i = 5; i < 10; ++i) {
                _clearFileMenuEntry(i);
            }
        }
        return _fileLoaded;
    }
    return 0;
}

static int _selectLoadMemoryCard(int port)
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

    int i;

    if (port != 0) {
        _selectedMemoryCard = port;
        _selectSaveMemoryCardMessage = (u_char*)(_textTable + VS_MCMAN_OFFSET_checking);
        _selectLoadMemoryCardState = init;
        return 0;
    }
    switch (_selectLoadMemoryCardState) {
    case init:
        _fileMenuElements[_selectedMemoryCard].state = fileMenuElementStateAnimateX;
        _fileMenuElements[_selectedMemoryCard].targetPosition = 180;
        _fileMenuElements[_selectedMemoryCard].innerBlendFactor = 1;
        _fileMenuElements[3 - _selectedMemoryCard].state = fileMenuElementStateAnimateX;
        _fileMenuElements[3 - _selectedMemoryCard].targetPosition = 320;
        _selectLoadMemoryCardState = waitForUnselectedAnimation;
        break;

    case waitForUnselectedAnimation:
        if (_fileMenuElementsActive() == 0) {
            break;
        }
        if (_selectedMemoryCard == 2) {
            _fileMenuElements[2].state = fileMenuElementStateAnimateY;
            _fileMenuElements[2].targetPosition = 50;
        }
        _selectLoadMemoryCardState = pollEventsInit;
        break;

    case pollEventsInit:
        if (_fileMenuElementsActive() == 0) {
            break;
        }
        _memcardMaskedHandler(_selectedMemoryCard + memcardEventMaskIgnoreNoEvent);
        _selectLoadMemoryCardState = pollEvents;
        break;

    case pollEvents:
        i = _memcardMaskedHandler(0);
        if (i != memcardMaskedHandlerPending) {
            _selectLoadMemoryCardState = i + leave + 1;
        }
        break;

    case leave:
        if (((u_char)vs_main_buttonsPressed) == 0) {
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
        if (_initSaveFileInfo(_selectedMemoryCard) != 0) {
            _selectSaveMemoryCardMessage
                = (u_char*)(_textTable + VS_MCMAN_OFFSET_loadfailed);
            _selectLoadMemoryCardState = leave;
            break;
        }
        for (i = 0; i < 5; ++i) {
            if (_saveFileInfo[i].unk4.slotState > slotStateAvailable) {
                break;
            }
        }

        if (i == 5) {
            _selectSaveMemoryCardMessage = (u_char*)(_textTable + VS_MCMAN_OFFSET_noData);
            _selectLoadMemoryCardState = leave;
        } else {
            _selectFileToLoad(_selectedMemoryCard);
            _selectLoadMemoryCardState = 7;
        }
        break;

    case selectFile:
        i = _selectFileToLoad(0);
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

static int _showLoadMenu(int fadeout)
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

    _fileMenuElements_t* entry;
    int i;

    if (fadeout != 0) {
        _showLoadMenuFadeout = fadeout - 1;
        _showLoadMenuSelectedSlot = 1;
        _isSaving = 0;
        _showLoadMenuState = init;
        return 0;
    }
    switch (_showLoadMenuState) {
    case init:
        entry = _initFileMenuElement(0, MAKEXY(320, 34), MAKEWH(140, 12),
            (u_char*)(_textTable + VS_MCMAN_OFFSET_load));
        entry->state = fileMenuElementStateAnimateX;
        entry->targetPosition = 180;
        entry->selected = 1;
        entry->innerBlendFactor = 8;
        _showLoadMenuState = displaySlot1;
        break;
    case displaySlot1:
        if (_fileMenuElementsActive() != 0) {
            entry = _initFileMenuElement(1, MAKEXY(320, 50), MAKEWH(126, 12),
                (u_char*)(_textTable + VS_MCMAN_OFFSET_slot1));
            entry->state = fileMenuElementStateAnimateX;
            entry->targetPosition = 194;
            _showLoadMenuState = displaySlot2;
        }
        break;
    case displaySlot2:
        entry = _initFileMenuElement(2, MAKEXY(320, 66), MAKEWH(126, 12),
            (u_char*)(_textTable + VS_MCMAN_OFFSET_slot2));
        entry->state = fileMenuElementStateAnimateX;
        entry->targetPosition = 194;
        _showLoadMenuState = waitForSlotAnimation;
        break;
    case waitForSlotAnimation:
        if (_fileMenuElementsActive() != 0) {
            _showLoadMenuState = handleInput;
            _selectSaveMemoryCardMessage
                = (u_char*)(_textTable + VS_MCMAN_OFFSET_selectSlot);
        }
        break;
    case handleInput:
        _fileMenuElements[_showLoadMenuSelectedSlot].selected = 1;
        _fileMenuElements[3 - _showLoadMenuSelectedSlot].selected = 0;
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            _selectCursorXy = 0;
            for (i = 0; i < 3; ++i) {
                _fileMenuElements[i].state = fileMenuElementStateAnimateX;
                _fileMenuElements[i].targetPosition = 320;
            }
            _showLoadMenuState = exit;
        } else if (vs_main_buttonsPressed & PADRright) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            _selectLoadMemoryCard(_showLoadMenuSelectedSlot);
            _selectCursorXy = 0;
            _showLoadMenuState = slotSelected;
        } else {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                _showLoadMenuSelectedSlot = 3 - _showLoadMenuSelectedSlot;
            }
            _selectCursorXy = ((((_showLoadMenuSelectedSlot + 1) * 16) + 10) << 16) | 180;
        }
        break;
    case slotSelected:
        entry = (_fileMenuElements_t*)_selectLoadMemoryCard(0);
        if (entry != 0) {
            if ((int)entry < 0) {
                _showLoadMenuState = displaySlot1;
            } else {
                _showLoadMenuState = fadeAndReturnSelected;
            }
        }
        break;
    case exit:
        if (_fileMenuElementsActive() != 0) {
            if (_showLoadMenuFadeout == 0) {
                return -1;
            }
            _showLoadMenuState = fadeAndReturnNotSelected;
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

    _fileMenuElements_t* temp_v0;
    int i;

    if (arg0 != 0) {
        _promptConfirmNoSelected = 1;
        _promptConfirmState = initYes;
        return 0;
    }

    switch (_promptConfirmState) {
    case initYes:
    case initNo:
        temp_v0 = _initFileMenuElement(_promptConfirmState + 3,
            MAKEXY(-126, _promptConfirmState * 16 + 18), MAKEWH(126, 12),
            (u_char*)&_textTable[_textTable[_promptConfirmState
                + VS_MCMAN_INDEX_yesIndent]]);
        temp_v0->state = 4;
        temp_v0->targetPosition = 0;
        ++_promptConfirmState;
        break;
    case waitForAnimation:
        _promptConfirmState += _fileMenuElementsActive();
        break;
    case handleInput:
        _fileMenuElements[_promptConfirmNoSelected + 3].selected = 1;
        _fileMenuElements[4 - _promptConfirmNoSelected].selected = 0;
        if (vs_main_buttonsPressed & (PADRdown | PADRright)) {
            _selectCursorXy = 0;
            for (i = 3; i < 5; ++i) {
                _fileMenuElements[i].state = 4;
                _fileMenuElements[i].targetPosition = -126;
            }
            if (vs_main_buttonsPressed & PADRright) {
                if (_promptConfirmNoSelected == 0) {
                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                    return 1;
                }
            }
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            return -1;
        }
        if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            _promptConfirmNoSelected = 1 - _promptConfirmNoSelected;
        }
        _selectCursorXy = (_promptConfirmNoSelected * 16 + 10) << 16;
        break;
    }
    return 0;
}

static int _promptOverwrite(int init)
{
    if (init != 0) {
        _overwritePromptInitialized = 1;
        _selectSaveMemoryCardMessage
            = (u_char*)(_textTable + VS_MCMAN_OFFSET_overwritePrompt);
        _promptConfirm(1);
        _promptOverwriteState = 0;
        return 0;
    }
    switch (_promptOverwriteState) {
    case 0:
        _promptOverwriteSelectedOption = _promptConfirm(0);
        if (_promptOverwriteSelectedOption != 0) {
            _promptOverwriteState = 1;
        }
        return 0;
    case 1:
        if (_fileMenuElementsActive() != 0) {
            return _promptOverwriteSelectedOption;
        }
        return 0;
    default:
        return 0;
    }
}

static int _promptFormat(int port)
{
    enum state { promptConfirm = 0, initEvents = 1, handleEvents = 2, format = 3 };

    int val;
    int state;

    if (port != 0) {
        _memcardStatePort = port;
        _selectSaveMemoryCardMessage
            = (u_char*)(_textTable + VS_MCMAN_OFFSET_formatPrompt);
        _promptConfirm(1);
        _promptFormatState = promptConfirm;
        return 0;
    }

    state = _promptFormatState;

    switch (state) {
    case promptConfirm:
        val = _promptConfirm(0);

        if (val != 0) {
            if (val < 0) {
                _selectSaveMemoryCardMessage
                    = (u_char*)(_textTable + VS_MCMAN_OFFSET_formatCancelled);
                return -1;
            }

            _promptFormatState = initEvents;
        }
        return 0;
    case initEvents:
        if (_fileMenuElementsActive() != 0) {
            _memcardEventHandler(_memcardStatePort);
            _promptFormatState = handleEvents;
        }
        return 0;
    case handleEvents:
        val = _memcardEventHandler(0);

        if (val != 0) {
            if (val == memcardEventUnformatted) {
                _promptFormatState = format;
                _selectSaveMemoryCardMessage
                    = (u_char*)(_textTable + VS_MCMAN_OFFSET_formatting);
            } else {
                if (val == memcardEventTimeout) {
                    _selectSaveMemoryCardMessage
                        = (u_char*)(_textTable + VS_MCMAN_OFFSET_insertError);
                } else {
                    _selectSaveMemoryCardMessage
                        = (u_char*)(_textTable + VS_MCMAN_OFFSET_removed);
                }
                return -1;
            }
        }
        return 0;
    case format:
        if (_card_format((_memcardStatePort - 1) * 16) == 0) {
            _selectSaveMemoryCardMessage
                = (u_char*)(_textTable + VS_MCMAN_OFFSET_formatFailed);
            return -1;
        }
        return 1;
    default:
        return 0;
    }
}

static int _showSaveMenu(int port)
{
    enum state {
        init = 0,
        handleInput = 1,
        slotSelected = 2,
        overwritePrompt = 3,
        initOverwrite = 4,
        save = 5,
        validate = 6,
        leaveTimer = 7,
        leave = 8,
        format = 9,
        leaveError = 10
    };

    _fileMenuElements_t* element;
    int val;
    int saveId;
    int i;

    if (port != 0) {
        _saveMenuPort = port;
        _saveMenuSelectedSlot = _findCurrentSaveOnActiveMemcard();
        if (_saveMenuSelectedSlot) {
            --_saveMenuSelectedSlot;
        }
        _saveMenuSelectedPage = 0;
        if (_saveMenuSelectedSlot == 4) {
            _saveMenuSelectedPage = 2;
            _saveMenuSelectedSlot = 2;
        } else if (_saveMenuSelectedSlot != 0) {
            _saveMenuSelectedPage = _saveMenuSelectedSlot - 1;
            _saveMenuSelectedSlot = 1;
        }
        _saveSuccessful = -1;
        _saveMenuLeaveTimer = 0;
        _saveMenuState = init;
        return 0;
    }
    switch (_saveMenuState) {
    case init:
        for (i = 0; i < 5; ++i) {
            element = _initFileMenuElement(
                i + 5, MAKEXY(64, i * 40 + 72), MAKEWH(256, 32), 0);
            element->slotId = i;
            element->slotUnavailable
                = _saveFileInfo[i].unk4.slotState == slotStateUnavailable;
            element->saveLocation = _saveFileInfo[i].unk4.saveLocation;
        }
        _saveMenuState = handleInput;
        /* fallthrough */
    case handleInput:
        _selectSaveMemoryCardMessage = (u_char*)(_textTable + VS_MCMAN_OFFSET_selectFile);
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            _selectCursorXy = 0;
            _saveMenuState = leave;
        } else {
            for (i = 0; i < 5; ++i) {
                _fileMenuElements[i + 5].y = ((i - _saveMenuSelectedPage) * 40) + 72;
                _fileMenuElements[i + 5].selected = 0;
            }
            val = _saveMenuSelectedSlot + _saveMenuSelectedPage;
            if (vs_main_buttonsPressed & PADRright) {
                if (_saveFileInfo[val].unk4.slotState != slotStateUnavailable) {
                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                    _fileMenuElements[val + 5].selected = 1;
                    _selectCursorXy = 0;
                    _memcardMaskedHandler(_saveMenuPort + memcardEventMaskAll);
                    _saveMenuState = slotSelected;
                    break;
                } else {
                    vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
                }
            }
            if (vs_main_buttonRepeat & PADLup) {
                if (_saveMenuSelectedSlot == 0) {
                    if (_saveMenuSelectedPage != 0) {
                        --_saveMenuSelectedPage;
                    }
                } else {
                    --_saveMenuSelectedSlot;
                }
            }
            if (vs_main_buttonRepeat & PADLdown) {
                if (_saveMenuSelectedSlot == 2) {
                    if (_saveMenuSelectedPage < 2) {
                        ++_saveMenuSelectedPage;
                    }
                } else {
                    ++_saveMenuSelectedSlot;
                }
            }
            if (val != (_saveMenuSelectedSlot + _saveMenuSelectedPage)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            }
            _selectCursorXy = MAKEXY(24, _saveMenuSelectedSlot * 40 + 62);
            _fileMenuElements[val + 5].selected = 1;
        }
        break;
    case slotSelected:
        val = _memcardMaskedHandler(0);
        if (val != memcardMaskedHandlerPending) {
            if (_selectSaveMemoryCardMessage
                == (u_char*)(_textTable + VS_MCMAN_OFFSET_noData)) {
                _promptFormat(_saveMenuPort);
                _saveMenuState = format;
            } else if (val > memcardMaskedHandlerError) {
                val = _saveMenuSelectedSlot + _saveMenuSelectedPage;
                if (_saveFileInfo[val].unk4.slotState == slotStateAvailable) {
                    if (_createSaveFile(_saveMenuPort, val + 1) != 0) {
                        _saveMenuState = leaveTimer;
                        _selectSaveMemoryCardMessage
                            = (u_char*)(_textTable + VS_MCMAN_OFFSET_saveFailed);
                    } else {
                        _saveMenuState = save;
                    }
                } else {
                    _promptOverwrite(1);
                    _saveMenuState = overwritePrompt;
                }
            } else {
                _saveMenuState = leaveTimer;
            }
        }
        break;
    case overwritePrompt:
        val = _promptOverwrite(0);
        if (val != 0) {
            if (val == 1) {
                _memcardMaskedHandler(_saveMenuPort + memcardEventMaskAll);
                _saveMenuState = initOverwrite;
            } else {
                _saveMenuState = handleInput;
            }
        }
        break;
    case initOverwrite:
        val = _memcardMaskedHandler(0);
        if (val != memcardMaskedHandlerPending) {
            if (val > memcardMaskedHandlerError) {
                _overwritingFile |= (_findCurrentSaveOnActiveMemcard()
                    == (_saveMenuSelectedSlot + _saveMenuSelectedPage + 1));
                _saveMenuState = save;
            } else {
                _saveMenuState = leaveTimer;
            }
        }
        break;
    case save:
        val = _saveMenuSelectedSlot + _saveMenuSelectedPage;
        _selectSaveMemoryCardMessage = (u_char*)(_textTable + VS_MCMAN_OFFSET_saving);
        _rMemcpy(&_settingsBackup, &vs_main_settings, sizeof(_settingsBackup));
        _rMemcpy(
            (savedata_t*)_spmcimg + 2, (savedata_t*)_spmcimg + 1, sizeof(savedata_t));
        if (D_800DED74 != 0) {
            D_800DED75 = (*(u_int*)&vs_main_settings.timingWeaponArmor >> 4) & 1;
            *(int*)&vs_main_settings |= 0x10;
        }
        func_80069888(val);
        func_8006A11C((val + 1) | ((_saveMenuPort - 1) << 0x10));
        _saveMenuState = validate;
        break;
    case validate:
        val = func_8006A11C(0);
        ++D_800DEB14;
        if (val != 0) {
            D_8006169D = 0;
            saveId = _saveMenuSelectedSlot + _saveMenuSelectedPage;
            if (val < 0) {
                if (D_800DED74 != 0) {
                    u_char v = D_800DED75 & 1;
                    *(int*)&vs_main_settings
                        = (*(int*)&vs_main_settings & ~0x10) | (v * 0x10);
                }
                memset(&_saveFileInfo[saveId], 0, sizeof(_saveFileInfo_t));
                _saveFileInfo[saveId].unk4.slotState = slotStateTemporary;
                _fileMenuElements[saveId + 5].saveLocation = 0;
                _rMemcpy((savedata_t*)_spmcimg + 1, (savedata_t*)_spmcimg + 2,
                    sizeof(savedata_t));
                D_800DEB14 = 0;
                _rMemcpy(&vs_main_settings, &_settingsBackup, sizeof(vs_main_settings));
                _selectSaveMemoryCardMessage
                    = (u_char*)(_textTable + VS_MCMAN_OFFSET_saveFailed);
            } else {
                _overwritingFile = 0;
                D_800DEB14 = -16;
                _rMemcpy(&_saveFileInfo[saveId], _spmcimg + sizeof(_saveFileInfo_t) * 3,
                    sizeof(_saveFileInfo_t));
                _decode(_saveFileInfo[saveId].key,
                    (u_char*)&_saveFileInfo[saveId].unk4.slotState,
                    sizeof(_saveFileInfo_t) - sizeof(int));
                _fileMenuElements[saveId + 5].saveLocation
                    = _saveFileInfo[saveId].unk4.saveLocation;
                vs_main_playSfxDefault(0x7E, VS_SFX_FILEOPCOMPLETE);
                _saveSuccessful = 1;
                _selectSaveMemoryCardMessage
                    = (u_char*)(_textTable + VS_MCMAN_OFFSET_saved);
            }
            _saveMenuState = leaveTimer;
        }
        break;
    case leaveTimer:
        if (_saveSuccessful == 1) {
            ++_saveMenuLeaveTimer;
        }
        if ((u_char)vs_main_buttonsPressed == 0) {
            if (_saveMenuLeaveTimer != 150) {
                break;
            }
        }
        vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
        _saveMenuState = leave;
        break;
    case leave:
        if (D_800DEB14 == 0) {
            for (i = 5; i < 10; ++i) {
                _clearFileMenuEntry(i);
            }
            return _saveSuccessful;
        }
        break;
    case format:
        val = _promptFormat(0);
        if (val != 0) {
            if (val < 0) {
                _saveMenuState = leaveError;
            } else if (_createSaveFile(_saveMenuPort,
                           _saveMenuSelectedPage + _saveMenuSelectedSlot + 1)
                != 0) {
                _saveMenuState = leaveTimer;
                _selectSaveMemoryCardMessage
                    = (u_char*)(_textTable + VS_MCMAN_OFFSET_saveFailed);
            } else {
                _saveMenuState = save;
            }
        }
        break;
    case leaveError:
        if ((u_char)vs_main_buttonsPressed != 0) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            for (i = 5; i < 10; ++i) {
                _clearFileMenuEntry(i);
            }
            return -1;
        }
        break;
    }
    return 0;
}

static int _selectSaveMemoryCard(int port)
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

    int i, j;

    if (port != 0) {
        _selectSaveMemoryCardPort = port;
        _selectSaveMemoryCardMessage = (u_char*)(_textTable + VS_MCMAN_OFFSET_checking);
        _selectSaveMemoryCardState = init;
        return 0;
    }

    switch (_selectSaveMemoryCardState) {
    case init:
        _fileMenuElements[_selectSaveMemoryCardPort].state = fileMenuElementStateAnimateX;
        _fileMenuElements[_selectSaveMemoryCardPort].targetPosition = 180;
        _fileMenuElements[_selectSaveMemoryCardPort].innerBlendFactor = 1;
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
            _selectSaveMemoryCardMessage
                = (u_char*)(_textTable + VS_MCMAN_OFFSET_insertError);
            break;
        case memcardEventUnformatted:
            memset(_saveFileInfo, 0, sizeof(*_saveFileInfo) * 5);
            for (i = 14; i >= 0; --i) {
                _memcardFiles[i] = NULL;
            }
            j = slotStateAvailable;
            for (i = 4; i >= 0; --i) {
                _saveFileInfo[i].unk4.slotState = j;
            }
            _showSaveMenu(_selectSaveMemoryCardPort);
            _selectSaveMemoryCardState = showSaveMenu;
            break;
        }
        break;
    case animateLeave:
        if ((u_char)vs_main_buttonsPressed == 0) {
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
            _selectSaveMemoryCardMessage
                = (u_char*)(_textTable + VS_MCMAN_OFFSET_loadfailed);
            break;
        }
        for (i = 0; i < 5; ++i) {
            if (_saveFileInfo[i].unk4.slotState != slotStateUnavailable) {
                break;
            }
        }
        if (i == 5) {
            _selectSaveMemoryCardState = animateLeave;
            _selectSaveMemoryCardMessage
                = (u_char*)(_textTable + VS_MCMAN_OFFSET_cardFull);
            break;
        }
        _showSaveMenu(_selectSaveMemoryCardPort);
        _selectSaveMemoryCardState = showSaveMenu;
        break;
    case showSaveMenu:
        i = _showSaveMenu(0);
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

int func_8006E00C(int arg0)
{
    _fileMenuElements_t* temp_v0;
    int temp_v0_2;
    int var_a0;

    if (arg0 != 0) {
        D_800DC924 = 1;
        D_800DED74 = 0;
        _overwritingFile = 0;
        _isSaving = 1;
        D_800DC923 = (arg0 - 1) * 3;
        temp_v0 = _initFileMenuElement(
            0, 0x220140, 0xC008C, (u_char*)(_textTable + VS_MCMAN_OFFSET_save));
        temp_v0->state = 2;
        temp_v0->targetPosition = 180;
        temp_v0->innerBlendFactor = 8;
        temp_v0->selected = 1;
        _selectSaveMemoryCardMessage = NULL;
        return 0;
    }

    switch (D_800DC923) {
    case 0:
        if (*(int*)&vs_main_settings & 0x10) {
            memset(_spmcimg + 0x79E0, 0, 0x3C00);
            D_800DC923 = 3;
        } else if (_fileMenuElementsActive() != 0) {
            if (vs_main_settings.slotState != slotStateUnavailable) {
                _findCurrentSave(1);
                D_800DC923 = 1;
            } else {
                D_800DC923 = 3;
            }
        }
        break;
    case 1:
        temp_v0_2 = _findCurrentSave(0);
        if (temp_v0_2 == 0) {
            break;
        }
        if (temp_v0_2 < 0) {
            _selectSaveMemoryCardMessage = (u_char*)(_textTable
                + (temp_v0_2 == -2 ? VS_MCMAN_OFFSET_insertError
                                   : VS_MCMAN_OFFSET_emptyCard));
            D_800DC923 = 9;
        } else {
            _loadSaveData((temp_v0_2 & 7) | ((temp_v0_2 & 16) << 0xC));
            D_800DC923 = 2;
        }
        break;
    case 2:
        var_a0 = _loadSaveData(0);
        if (var_a0 != 0) {
            if ((var_a0 <= 0) || (_applyLoadedSaveFile(0) != 0)) {
                D_800DC923 = 9;
                _selectSaveMemoryCardMessage
                    = (u_char*)(_textTable + VS_MCMAN_OFFSET_emptyCard);
            } else {
                D_800DC923 = 3;
            }
        }
        break;
    case 3:
        if (_fileMenuElementsActive() != 0) {
            temp_v0 = _initFileMenuElement(
                1, 0x320140, 0xC007E, (u_char*)(_textTable + VS_MCMAN_OFFSET_slot1));
            temp_v0->state = 2;
            temp_v0->targetPosition = 194;
            D_800DC923 = 4;
        }
        break;
    case 4:
        temp_v0 = _initFileMenuElement(
            2, 0x420140, 0xC007E, (u_char*)(_textTable + VS_MCMAN_OFFSET_slot2));
        temp_v0->state = 2;
        temp_v0->targetPosition = 194;
        D_800DC923 = 5;
        break;
    case 5:
        if (_fileMenuElementsActive() != 0) {
            D_800DC923 = 6;
            _selectSaveMemoryCardMessage
                = (u_char*)(_textTable + VS_MCMAN_OFFSET_selectSlot);
        }
        break;
    case 6:
        _fileMenuElements[D_800DC924].selected = 1;
        _fileMenuElements[3 - D_800DC924].selected = 0;
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            var_a0 = _overwritingFile;
            _selectCursorXy = 0;
            if (var_a0 < 3) {
                do {
                    _fileMenuElements[var_a0].state = 2;
                    _fileMenuElements[var_a0].targetPosition = 0x140;
                    ++var_a0;
                } while (var_a0 < 3);
            }
            if (_overwritingFile != 0) {
                _selectSaveMemoryCardMessage
                    = (u_char*)(_textTable + VS_MCMAN_OFFSET_containerFileCorrupt);
                _promptConfirm(1);
                D_800DC923 = 11;
            } else {
                D_800DC923 = 8;
            }
        } else if (vs_main_buttonsPressed & PADRright) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            _selectSaveMemoryCard(D_800DC924);
            _selectCursorXy = 0;
            D_800DC923 = 7;
        } else {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                D_800DC924 = 3 - D_800DC924;
            }
            _selectCursorXy = ((((D_800DC924 + 1) * 16) + 10) << 16) | 0xB4;
        }
        break;
    case 7:
        var_a0 = _selectSaveMemoryCard(0);
        if (var_a0 != 0) {
            if (var_a0 < 0) {
                D_800DC923 = 3;
                break;
            }
            func_8006AE10(var_a0);
            return 1;
        }
        break;
    case 8:
        if (_fileMenuElementsActive() != 0) {
            return -1;
        }
        break;
    case 9:
        if ((u_char)vs_main_buttonsPressed != 0) {
            _selectSaveMemoryCardMessage
                = (u_char*)(_textTable + VS_MCMAN_OFFSET_overwriteContainerWarn);
            _promptConfirm(1);
            D_800DC923 = 10;
        }
        break;
    case 10:
    case 11:
        var_a0 = _promptConfirm(0);
        if (var_a0 != 0) {
            if (D_800DC923 == 11) {
                if (var_a0 > 0) {
                    *(int*)&vs_main_settings = *(int*)&vs_main_settings | 0x10;
                }
                var_a0 = -var_a0;
            }
            if (var_a0 < 0) {
                _fileMenuElements->state = 2;
                _fileMenuElements->targetPosition = 0x140;
                D_800DC923 = 8;
                break;
            }
            if (D_800DC923 == 10) {
                D_800DED74 = 1;
                memset(_spmcimg + 0x79E0, 0, 0x3C00);
            }
            D_800DC923 = 3;
        }
        break;
    }
    return 0;
}

static void _initSaveScreen()
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

static void _saveScreenSwapBuf()
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

static int _displayGameLoadScreen()
{
    int temp_v0;

    _drawImage(MAKEXY(768, 0), (u_long*)&_uiTable.page0, MAKEWH(64, 224));
    _drawImage(MAKEXY(448, 256), (u_long*)&_uiTable.page1, MAKEWH(64, 256));
    _drawImage(MAKEXY(832, 0), (u_long*)&_fontTable[0], MAKEWH(64, 224));
    _drawImage(MAKEXY(896, 0), (u_long*)&_fontTable[1], MAKEWH(64, 224));
    _drawImage(MAKEXY(960, 66), _debugFont, MAKEWH(64, 158));
    _drawImage(MAKEXY(768, 227), (u_long*)&_saveMenuBg.clut, MAKEWH(256, 1));
    setRECT(&_gameLoadRect, 640, 256, 32, 240);
    ClearImage(&_gameLoadRect, 0, 0, 0);
    DrawSync(0);
    setRECT(&_gameLoadRect, 768, 256, 32, 240);
    ClearImage(&_gameLoadRect, 0, 0, 0);
    _drawImage(MAKEXY(672, 256), (u_long*)&_saveMenuBg.data, MAKEWH(96, 240));
    _initSaveScreen();
    _loadScreenMemcardState = 0;

    while (1) {
        vs_main_gametimeUpdate(2);
        _saveScreenSwapBuf();
        vs_main_processPadState();
        switch (_loadScreenMemcardState) {
        case 0:
            if (_loadScreenMemcardState == 0) {
                _loadMemcardMenu(1);
                _loadScreenMemcardState = 1;
            }
            break;
        case 1:
            if (_loadMemcardMenu(0) != 0) {
                func_8006AE10();
                _showLoadMenu(2);
                _loadScreenMemcardState = 2;
            }
            break;
        case 2:
            temp_v0 = _showLoadMenu(0);
            if (temp_v0 != 0) {
                _shutdownMemcard();
                SetDispMask(0);
                return temp_v0;
            }
            _drawSaveMenuBg();
            _drawSaveMenu(_frameBuf);
            break;
        }
    }
}

static int _saveFileExists()
{
    struct DIRENTRY dir;
    u_char filename[22];
    int memCardState;
    int i;
    int ret = 0;

    _loadMemcardMenu(1);

    do {
        vs_main_gametimeUpdate(2);
    } while (_loadMemcardMenu(0) == 0);

    for (i = 1; i <= 2; ++i) {
        _memcardEventHandler(i);
        do {
            memCardState = _memcardEventHandler(0) & 3;
            VSync(2);
        } while (memCardState == 0);

        if (memCardState == 1) {
            _rMemcpy(filename, _pMemcardFilenameTemplate, sizeof(filename));

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

int func_8006EA70(int arg0)
{
    _fileMenuElements_t* temp_v0;
    int i;

    if (arg0 != 0) {
        D_800DC932 = 1;
        D_800DC931 = 0;
        return 0;
    }

    switch (D_800DC931) {
    case 0:
    case 1:
        temp_v0 = _initFileMenuElement(D_800DC931 + 1,
            (((D_800DC931 * 0x10) + 0x92) << 0x10) | 0x140, 0xC007E,
            (u_char*)&_textTable[_textTable[D_800DC931 + VS_MCMAN_INDEX_yesOption]]);
        temp_v0->state = 2;
        temp_v0->targetPosition = 0xC2;
        ++D_800DC931;
        break;
    case 2:
        D_800DC931 += _fileMenuElementsActive();
        break;
    case 3:
        _fileMenuElements[D_800DC932].selected = 1;
        _fileMenuElements[3 - D_800DC932].selected = 0;
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
        }
        if (vs_main_buttonsPressed & PADRright) {
            D_800DC931 = 4;
        }
        if (D_800DC931 == 4) {
            if (D_800DC932 == 1) {
                _playMenuSelectSfx();
            } else {
                _playMenuLeaveSfx();
            }
            _selectCursorXy = 0;
            for (i = 1; i < 3; ++i) {
                _fileMenuElements[i].state = 2;
                _fileMenuElements[i].targetPosition = 0x140;
            }
            break;
        }
        if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
            _playMenuChangeSfx();
            D_800DC932 = 3 - D_800DC932;
        }
        _selectCursorXy = ((((D_800DC932 + 7) * 16) + 10) << 16) | 0xB4;
        break;
    case 4:
        if (_fileMenuElementsActive() != 0) {
            return D_800DC932;
        }
        break;
    default:
        break;
    }
    return 0;
}

static void _saveScreenExitScreen()
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

enum saveScreenState {
    saveScreenStateInit = 0,
    saveScreenStateLoading = 1,
    saveScreenStateLoaded = 2,
    saveScreenStateExiting = 4,
};

static void _displayGameSaveScreen()
{
    int temp_v0;

    _drawImage(MAKEXY(768, 0), (u_long*)&_uiTable.page0, MAKEWH(64, 224));
    _drawImage(MAKEXY(448, 256), (u_long*)&_uiTable.page1, MAKEWH(64, 256));
    _drawImage(MAKEXY(832, 0), (u_long*)&_fontTable[0], MAKEWH(64, 224));
    _drawImage(MAKEXY(896, 0), (u_long*)&_fontTable[1], MAKEWH(64, 224));
    _drawImage(MAKEXY(960, 66), _debugFont, MAKEWH(64, 158));
    _drawImage(MAKEXY(768, 227), (u_long*)&_saveMenuBg.clut, MAKEWH(256, 1));
    setRECT(&D_800DC938, 640, 256, 32, 240);
    ClearImage(&D_800DC938, 0, 0, 0);
    DrawSync(0);
    setRECT(&D_800DC938, 768, 256, 32, 240);
    ClearImage(&D_800DC938, 0, 0, 0);
    _drawImage(MAKEXY(672, 256), (u_long*)&_saveMenuBg.data, MAKEWH(96, 240));
    _initSaveScreen();

    _saveScreenState = saveScreenStateInit;

    while (1) {
        vs_main_gametimeUpdate(2);
        _saveScreenSwapBuf();
        vs_main_processPadState();
        _encode(0);

        switch (_saveScreenState) {
        case saveScreenStateInit:
            _loadMemcardMenu(1);
            _saveScreenState = saveScreenStateLoading;
            continue;
        case saveScreenStateLoading:
            if (_loadMemcardMenu(0) != 0) {
                func_8006AE10();
                func_8006E00C(1);
                _saveScreenState = saveScreenStateLoaded;
            }
            continue;
        case saveScreenStateLoaded:
            temp_v0 = func_8006E00C(0);
            if (temp_v0 != 0) {
                if (temp_v0 < 0) {
                    _selectSaveMemoryCardMessage
                        = (u_char*)(_textTable + VS_MCMAN_OFFSET_savePrompt);
                    func_8006EA70(1);
                    _saveScreenState = 3;
                } else {
                    _shutdownMemcard();
                    _saveScreenExitScreen();
                    _saveScreenFadeTimer = 30;
                    _saveScreenState = saveScreenStateExiting;
                    continue;
                }
            }
            _drawSaveMenuBg();
            _drawSaveMenu(_frameBuf);
            continue;
        case 3:
            temp_v0 = func_8006EA70(0);
            if (temp_v0 != 0) {
                if (temp_v0 != 1) {
                    _shutdownMemcard();
                    _saveScreenExitScreen();
                    _saveScreenFadeTimer = 30;
                    _saveScreenState = saveScreenStateExiting;
                    continue;
                }
                func_8006E00C(1);
                _saveScreenState = saveScreenStateLoaded;
            }
            _drawSaveMenuBg();
            _drawSaveMenu(_frameBuf);
            continue;
        case saveScreenStateExiting:
            _saveScreenExitScreen();
            if (--_saveScreenFadeTimer == 0) {
                SetDispMask(0);
                return;
            }
            break;
        }
    }
}

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

static void _initMoviePlayback(DslLOC* loc, void (*dctoutCb)())
{
    DecDCTReset(0);
    DecDCToutCallback(dctoutCb);
    StSetRing((u_long*)_movieRingBuf, 64);
    StSetStream(1, 1, -1, NULL, NULL);
    _playMovie(loc);
}

static void _decDCToutCallback()
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

static int _decodeNextMovieFrame(MovieData_t* arg0)
{
    u_long* frameData;
    int i;

    i = 2000;

    while ((frameData = (u_long*)_getNextMovieFrame(arg0)) == 0) {
        if (--i == 0) {
            return -1;
        }
    }

    arg0->encodedDataIndex = arg0->encodedDataIndex == 0;
    DecDCTvlc2(frameData, arg0->encodedData[arg0->encodedDataIndex], &_vlcTable);
    StFreeRing(frameData);
    return 0;
}

static u_short* _getNextMovieFrame(MovieData_t* arg0)
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
    arg0->frameBufs[1].w = (int)(temp_v1 + (temp_v1 >> 31)) >> 1;
    arg0->frameBufs[0].w = (int)(temp_v1 + (temp_v1 >> 31)) >> 1;
    arg0->frameBufs[1].h = _movieHeight;
    arg0->frameBufs[0].h = _movieHeight;
    arg0->renderTarget.h = _movieHeight;
    return addr;
}

void func_8006F42C(MovieData_t* arg0, int arg1 __attribute__((unused)))
{
    volatile int sp0[2];
    int* new_var;
    int i = arg0->frameComplete;
    sp0[0] = 0x800000;

    while ((*(new_var = &i)) == 0) {
        if ((--sp0[0]) == 0) {
            arg0->frameComplete = 1;
            arg0->frameBufIndex = arg0->frameBufIndex == 0;
            arg0->renderTarget.x = arg0->frameBufs[arg0->frameBufIndex].x;
            arg0->renderTarget.y = arg0->frameBufs[arg0->frameBufIndex].y;
        }
        i = arg0->frameComplete;
    }

    arg0->frameComplete = 0;
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
    _drawImage(MAKEXY(320, 64), (u_long*)_publisher.clut, MAKEWH(16, 1));
    _drawImage(MAKEXY(320, 0), _publisher.data, MAKEWH(256 / 4, 48));
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
        _drawSprt(MAKEXY(32, 88), vs_getUV0Clut(0, 0, 320, 64), MAKEWH(256, 48),
            (var_a3 << 16) | (320 / 64));
        SetDefDispEnv(&disp, 0, (i & 1) * 256, 320, 240);
        SetDefDrawEnv(&draw, 0, (1 - (i & 1)) * 256, 320, 240);
        disp.screen.y = 8;
        disp.screen.h = 224;
        VSync(0);
        PutDispEnv(&disp);
        PutDrawEnv(&draw);
    }

    _drawImage(MAKEXY(0, 240), _developer, MAKEWH(128 / 4, 14));

    for (i = 0; i < 364; ++i) {
        var_a3_2 = 0;
        if (i < 32) {
            var_a3_2 = (31 - i) * 4;
        } else if (i > 331) {
            var_a3_2 = (i - 331) * 4;
        } else if ((vs_main_buttonsState & 0xFFFF) != 0) {
            i = 331;
        }
        _drawSprt(MAKEXY(96, 104), vs_getUV0Clut(0, 240, 0, 253), MAKEWH(128, 13),
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

static void _initIntroMovie()
{
    _dslMode = DslModeStream2 | DslModeSpeed | DslModeRT;
    DsIntToPos(VS_TITLE_STR_LBA, &introMovieLoc);
    _movieRingBuf = vs_main_allocHeap(0x20000);
    _encodedDataBuf0 = vs_main_allocHeap(0x23000);
    _encodedDataBuf1 = vs_main_allocHeap(0x23000);
    _decodedDataBuf0 = vs_main_allocHeap(0x2A00);
    _decodedDataBuf1 = vs_main_allocHeap(0x2A00);
    _initMovieData(&_movieData, 0, 0, 0, 224);
    _initMoviePlayback(&introMovieLoc, _decDCToutCallback);
    DecDCTvlcBuild(&_vlcTable);

    while (_decodeNextMovieFrame(&_movieData) == -1) {
        DslLOC loc = introMovieLoc;
        _playMovie(&loc);
    }
    _introMoviePlaying = 1;
    _introMovieDisplayedAt = VSync(-1);
}

static void _stopIntroMovie()
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

static void _stopMovieIfComplete()
{
    if ((_introMoviePlaying != 0) && ((VSync(-1) - _introMovieDisplayedAt) >= 4401)) {
        _stopIntroMovie();
    }
}

static int _playIntroMovie()
{
    DslLOC loc;
    DISPENV disp;
    int var_s2;
    u_int dataSize;

    var_s2 = 0;

    while (1) {
        DecDCTin((u_long*)_movieData.encodedData[_movieData.encodedDataIndex], 3);
        dataSize = _movieData.renderTarget.w * _movieData.renderTarget.h;
        DecDCTout(_movieData.decodedData[_movieData.decodedDataIndex],
            (int)(dataSize + (dataSize >> 0x1F)) >> 1);

        while (_decodeNextMovieFrame(&_movieData) == -1) {
            if ((u_int)(StGetBackloc(&loc) - 1) >= 0x44CU) {
                loc = introMovieLoc;
            }
            _playMovie(&loc);
        }

        func_8006F42C(&_movieData, 0);
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

        if ((vs_main_buttonsPressed & (PADRright | PADstart))) {
            return 1;
        }
    }
    return 0;
}

static void _setMenuItemFadeIn(int menuItem, u_char pos)
{
    _menuItemStates[menuItem].enabled = 1;
    _menuItemStates[menuItem].state = menuItemStateStatic;
    _menuItemStates[menuItem].saturation = 0;
    _menuItemStates[menuItem].unk3 = 0;
    _menuItemStates[menuItem].pos = pos;
    _menuItemStates[menuItem].targetPos = pos;
    _menuItemStates[menuItem].unk6 = pos;
    _menuItemStates[menuItem].blendFactor = 0;
}

static void _unpackMenuBg()
{
    RECT rect;
    int j;
    u_int new_var;
    u_int i;
    u_long* temp_v0;
    u_long* p;

    i = 0;
    temp_v0 = vs_main_allocHeap(544 * (512 + 64) * sizeof(u_short));
    p = temp_v0;

#ifndef MENUBGSZ
#define MENUBGSZ 222932 * sizeof(int)
#endif

    for (; i < MENUBGSZ / sizeof(int);) {
        new_var = _menuBg[i++];
        for (j = new_var & 0xFFFF; j != 0; --j) {
            *p++ = 0;
        }

        for (j = new_var >> 16; j != 0; --j) {
            *p++ = _menuBg[i++];
        }
    }
    DrawSync(0);
    setRECT(&rect, 480, 0, 544, 512);
    LoadImage(&rect, temp_v0);
    DrawSync(0);
    setRECT(&rect, 0, 448, 544, 64);
    LoadImage(&rect, temp_v0 + 0x22000);
    DrawSync(0);

    for (i = 0; i < 8; ++i) {
        setRECT(&rect, 480, i + 384, 16, 1);
        LoadImage(&rect, (u_long*)_menuItemClut);
        DrawSync(0);
    }
    setRECT(&rect, 480, 394, 16, 1);
    LoadImage(&rect, (u_long*)D_80074AF4);
    DrawSync(0);
    vs_main_freeHeap(temp_v0);
}

static void _blankScreen()
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

void* _initMenu(int menuItem)
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

void _freeHeap(void* arg0) { vs_main_freeHeap(arg0); }

void _fadeInMenu(u_short* bgData, int blendFactor)
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
        rdiff = (r0 - r1) * blendFactor;
        gdiff = (g0 - g1) * blendFactor;
        bdiff = (b0 - b1) * blendFactor;
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

void _fadeInMenuCopyright(u_short* arg0, int blendFactor)
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
        r1 = src[i];
        r0 = _menuCopyright[i];
        g0 = r0 & 0x3E0;
        b0 = r0 & 0x7C00;
        g1 = r1 & 0x3E0;
        b1 = r1 & 0x7C00;
        r1 &= 0x1F;
        r0 &= 0x1F;
        rdiff = (r1 - r0) * blendFactor;
        gdiff = (g1 - g0) * blendFactor;
        bdiff = (b1 - b0) * blendFactor;
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

void _setMenuItemClut(int menuItem, int blendFactor, int clut0, int clut1)
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
        r0 = _menuItemClut[clut0][i];
        r1 = _menuItemClut[clut1][i];
        g0 = r0 & 0x3E0;
        b0 = r0 & 0x7C00;
        r0 &= 0x1F;
        g1 = r1 & 0x3E0;
        b1 = r1 & 0x7C00;
        r1 &= 0x1F;
        rdiff = (r1 - r0) * blendFactor;
        gdiff = (g1 - g0) * blendFactor;
        bdiff = (b1 - b0) * blendFactor;
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

static void func_800703CC()
{
    int i;
    int var_a0;
    int blendFactor;

    i = 0;

    for (i = 0; i < 10; ++i) {
        if (_menuItemStates[i].enabled != 0) {
            var_a0 = _menuItemStates[i].saturation + 8;

            if (var_a0 > 128) {
                var_a0 = 128;
            }

            _menuItemStates[i].saturation = var_a0;

            switch (_menuItemStates[i].state) {
            case menuItemStateStatic:
                if (var_a0 == 128 && _menuItemStates[i].pos == 64) {
                    _menuItemStates[i].unk6 = _menuItemStates[i].pos;

                    blendFactor = _menuItemStates[i].blendFactor;
                    if (blendFactor < 16) {
                        _menuItemStates[i].unk3 = blendFactor * 16;
                        blendFactor += 4;
                        if (blendFactor > 16) {
                            blendFactor = 16;
                        }
                        _menuItemStates[i].blendFactor = blendFactor;
                    }
                }
                break;
            case menuItemStateUpper:
                _menuItemStates[i].pos -= 4;
                if (_menuItemStates[i].pos == _menuItemStates[i].targetPos) {
                    _menuItemStates[i].state = menuItemStateStatic;
                }
                break;
            case menuItemStateLower:
                _menuItemStates[i].pos += 4;
                if (_menuItemStates[i].pos == _menuItemStates[i].targetPos) {
                    _menuItemStates[i].state = menuItemStateStatic;
                }
                break;
            }

            blendFactor = _menuItemStates[i].blendFactor;

            if (_menuItemStates[i].state < menuItemStateSubmenu) {
                _setMenuItemClut(i, blendFactor, 0, 1);
            }
            if ((blendFactor != 0) && (_menuItemStates[i].pos != 64)) {
                _menuItemStates[i].blendFactor = blendFactor - 1;
            }

            if (_menuItemStates[i].unk3 != 0) {
                if (_menuItemStates[i].unk6 != _menuItemStates[i].pos) {
                    _menuItemStates[i].unk3 -= 16;

                    if (_menuItemStates[i].unk6 < _menuItemStates[i].pos) {
                        _menuItemStates[i].unk6 += 2;
                    } else {
                        _menuItemStates[i].unk6 -= 2;
                    }
                } else if ((_menuItemStates[i].blendFactor == 16)
                    && (_menuItemStates[i].unk3 > 128)) {
                    _menuItemStates[i].unk3 -= 16;
                }
            }
        }
    }
}

static void _drawMenuItems()
{
    int cluts2;
    int j;
    menuItemState_t* menuState;
    int x;
    int wh;
    int i;
    menuItemPrim_t* prim;
    int saturation;

    prim = _menuItemPrims;

    for (i = 9; i >= 0; --i) {
        if ((_menuItemStates[i].enabled == 0) || (_menuItemStates[i].unk3 == 0)) {
            continue;
        }
        prim->tag = vs_getTag(prim->sprt, primAddrEnd);
        prim->sprt.tpage = _menuItemTpages1[i];
        prim->sprt.r0g0b0code = vs_getRGB0Raw(
            primSprtSemtTrans, _menuItemStates[i].unk3 * vs_getRGB888(1, 1, 1));
        if (_menuItemStates[i].state == 3) {
            prim->sprt.x0y0 = (_menuItemXy[i] + (_menuItemStates[i].unk6 << 16)) + 64;
        } else {
            prim->sprt.x0y0 = _menuItemXy[i] + _menuItemStates[i].unk6 * vs_getXY(1, 1);
        }
        prim->sprt.u0v0clut = _menuItemCluts1[i];
        prim->sprt.wh = _menuItemWh[i];
        DrawPrim(prim);
        ++prim;
    }

    for (i = 9; i >= 0; --i) {
        menuState = _menuItemStates;
        if (menuState[i].enabled == 0) {
            continue;
        }
        saturation = menuState[i].saturation;
        x = 192;
        if (menuState[i].state != 3) {
            x = menuState[i].pos + 128;
        }

        cluts2 = _menuItemCluts2[i];
        wh = 128;
        if (x < 176) {
            cluts2 += 176 - x;
            wh = x - 48;
            x = 176;
        }
        if ((x + wh) > 336) {
            wh = 336 - x;
        }
        wh |= vs_getWH(0, 1);

        for (j = 0; j < 32; ++j) {

            int new_var = j + menuState[i].pos;
            prim->tag = vs_getTag(prim->sprt, primAddrEnd);
            prim->sprt.tpage = _menuItemTpages2[i];

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
            prim->sprt.u0v0clut = cluts2 + (j << 8);
            prim->sprt.wh = wh;
            DrawPrim(prim);
            ++prim;
        }
    }
}

void func_8007093C()
{
    int i;
    tagsprt_t* sprt;

    func_800703CC();
    for (i = 0; i < 2; ++i) {
        sprt = &D_800DE948[0];
        sprt->sprt.tpage
            = vs_getTpage(192, 256, direct16Bit, semiTransparencyHalf, ditheringOff);
        sprt->tag = vs_getTag(sprt->sprt, primAddrEnd);
        sprt->sprt.r0g0b0code = vs_getRGB0(primSprt, 128, 128, 128);
        sprt->sprt.x0y0 = vs_getXY(176, 256);
        sprt->sprt.u0v0clut = vs_getUV0Clut(0, 192, 0, 0);
        sprt->sprt.wh = vs_getWH(160, 64);
        DrawPrim(sprt);
        ++sprt;
        sprt->sprt.tpage
            = vs_getTpage(320, 256, direct16Bit, semiTransparencyHalf, ditheringOff);
        sprt->tag = vs_getTag(sprt->sprt, primAddrEnd);
        sprt->sprt.r0g0b0code = vs_getRGB0(primSprt, 128, 128, 128);
        sprt->sprt.x0y0 = vs_getXY(176, 320);
        sprt->sprt.u0v0clut = vs_getUV0Clut(32, 192, 0, 0);
        sprt->sprt.wh = vs_getWH(160, 64);
        DrawPrim(sprt);
        _drawMenuItems();
        if (i == 0) {
            DrawSync(0);
            VSync(0);
            func_800436B4();
        } else {
            _stopMovieIfComplete();
        }
    }
}

void func_80070A58()
{
    func_8007093C();
    VSync(0);
    vs_main_processPadState();
}

static void _menuVibrationSettings()
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
        _menuItemStates[menuItemVibration].pos -= 4;
        func_80070A58();
    }
    _menuItemStates[menuItemNewGame].state = menuItemStateStatic;
    _menuItemStates[menuItemContinue].state = menuItemStateStatic;
    _menuItemStates[menuItemSound].state = menuItemStateStatic;
    for (i = 1; i < 9; ++i) {
        func_80070A58();
    }

    for (i = 0; i < 8; ++i) {
        _setMenuItemClut(vibrationSetting, i * 2, 0, 1);
        _menuItemStates[vibrationSetting].unk3
            = i < 4 ? i * 64 : _menuItemStates[vibrationSetting].unk3 - 16;
        func_80070A58();
    }
    while (1) {
        func_80070A58();
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
            if (vs_main_buttonsPressed & (PADLup | PADLdown | PADselect)) {
                vibrationSetting = 11 - vibrationSetting;
                _playMenuChangeSfx();

                for (i = 1; i < 8; ++i) {
                    _setMenuItemClut(vibrationSetting, i * 2, 0, 1);
                    _setMenuItemClut(11 - vibrationSetting, i * 2, 1, 0);
                    _menuItemStates[vibrationSetting].unk3
                        = i < 4 ? i * 64 : _menuItemStates[vibrationSetting].unk3 - 16;
                    _menuItemStates[11 - vibrationSetting].unk3 -= 16;
                    if (i == 7) {
                        break;
                    }
                    func_80070A58();
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
        _menuItemStates[2].pos += 4;
        if (_menuItemStates[menuItemVibrationOff].saturation < 24) {
            _menuItemStates[menuItemVibrationOff].saturation = 0;
        } else {
            _menuItemStates[menuItemVibrationOff].saturation -= 24;
        }
        if (_menuItemStates[menuItemVibrationOn].saturation < 24) {
            _menuItemStates[menuItemVibrationOn].saturation = 0;
        } else {
            _menuItemStates[menuItemVibrationOn].saturation -= 24;
        }
        if (_menuItemStates[menuItemVibrationOff].unk3 != 0) {
            _menuItemStates[menuItemVibrationOff].unk3 -= 16;
        }
        if (_menuItemStates[menuItemVibrationOn].unk3 != 0) {
            _menuItemStates[menuItemVibrationOn].unk3 -= 16;
        }
        func_80070A58();
    }
    _menuItemStates[5].enabled = 0;
    _menuItemStates[6].enabled = 0;
    _menuItemStates[menuItemVibration].unk6 = 0x40;
    _menuItemStates[menuItemVibration].unk3 = 0x40;
    func_80070A58();
    _menuItemStates[menuItemVibration].unk3 = 0x80;
    func_80070A58();
    _menuItemStates[menuItemVibration].unk3 = 0xC0;
    func_8007093C();
    _menuItemStates[menuItemVibration].blendFactor = 16;
    _menuItemStates[menuItemVibration].state = menuItemStateStatic;
}

static void _menuSoundSettings()
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
        _menuItemStates[menuItemSound].pos -= 4;
        func_80070A58();
    }
    _menuItemStates[menuItemNewGame].state = menuItemStateStatic;
    _menuItemStates[menuItemContinue].state = menuItemStateStatic;
    _menuItemStates[menuItemVibration].state = menuItemStateStatic;
    for (i = 1; i < 9; ++i) {
        func_80070A58();
    }
    for (i = 0; i < 8; ++i) {
        _setMenuItemClut(soundSetting, i * 2, 0, 1);
        _menuItemStates[soundSetting].unk3
            = i < 4 ? i << 6 : _menuItemStates[soundSetting].unk3 - 16;
        func_80070A58();
    }
    while (1) {
        func_80070A58();
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
            if (vs_main_buttonsPressed & (PADLup | PADLdown | PADselect)) {
                soundSetting = 11 - soundSetting;
                _playMenuChangeSfx();
                for (i = 1; i < 8; ++i) {
                    _setMenuItemClut(soundSetting, i * 2, 0, 1);
                    _setMenuItemClut(11 - soundSetting, i * 2, 1, 0);
                    _menuItemStates[soundSetting].unk3
                        = i < 4 ? i << 6 : _menuItemStates[soundSetting].unk3 - 16;
                    _menuItemStates[11 - soundSetting].unk3 -= 16;
                    if (i == 7) {
                        break;
                    }
                    func_80070A58();
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
        _menuItemStates[menuItemSound].pos += 4;
        if (_menuItemStates[menuItemSoundMono].saturation < 24) {
            _menuItemStates[menuItemSoundMono].saturation = 0;
        } else {
            _menuItemStates[menuItemSoundMono].saturation -= 24;
        }
        if (_menuItemStates[menuItemSoundStereo].saturation < 24) {
            _menuItemStates[menuItemSoundStereo].saturation = 0;
        } else {
            _menuItemStates[menuItemSoundStereo].saturation -= 24;
        }
        if (_menuItemStates[menuItemSoundMono].unk3 != 0) {
            _menuItemStates[menuItemSoundMono].unk3 -= 16;
        }
        if (_menuItemStates[menuItemSoundStereo].unk3 != 0) {
            _menuItemStates[menuItemSoundStereo].unk3 -= 16;
        }
        func_80070A58();
    }
    _menuItemStates[menuItemSoundMono].enabled = 0;
    _menuItemStates[menuItemSoundStereo].enabled = 0;
    _menuItemStates[menuItemSound].unk6 = 64;
    _menuItemStates[menuItemSound].unk3 = 64;
    func_80070A58();
    _menuItemStates[menuItemSound].unk3 = 128;
    func_80070A58();
    _menuItemStates[menuItemSound].unk3 = 192;
    func_8007093C();
    _menuItemStates[menuItemSound].blendFactor = 16;
    _menuItemStates[menuItemSound].state = menuItemStateStatic;
}

int _nop1() { return 0; }

void _initSettings()
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
    D_80061598[1] = 1;
    D_80061598[284] = 1;
}

int vs_title_exec()
{
    RECT rect;
    int i;
    int menuItem;
    int selectedOption;
    void* menuData;

    if (vs_main_saveBeforeTitle != 0) {
        vs_main_saveBeforeTitle = 0;
        vs_main_titleScreenCount = 0;
        _displayGameSaveScreen();
    }
    _initTitle();
    _initSettings();
    _introMoviePlaying = 0;
    ++vs_main_titleScreenCount;
    menuItem = _saveFileExists();

    do {
        for (i = 7; i >= 0; --i) {
            _menuItemStates[i].enabled = 0;
        }

        _unpackMenuBg();
        _initIntroMovie();
        _playIntroMovie();
        _blankScreen();
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
            func_8007093C();
        }
        _freeHeap(menuData);
        for (i = 0; i < 8; ++i) {
            func_80070A58();
        }

        vs_main_padDisconnectAll();
        _introMovieLastPlayed = VSync(-1);
        _buttonsLastPressed = VSync(-1);

        while (1) {
            VSync(0);
            vs_main_processPadState();
            if (_introMoviePlaying != 0) {
                _introMovieLastPlayed = VSync(-1);
            }
            if ((vs_main_buttonsState & 0xFFFF) != 0) {
                _buttonsLastPressed = VSync(-1);
            }
            if (((VSync(-1) - _buttonsLastPressed) > 1000)
                && ((VSync(-1) - _introMovieLastPlayed) > 100)) {
                selectedOption = menuItemTimeout;
                break;
            }
            if (vs_main_buttonsState & (PADRright | PADstart)) {
                switch (menuItem) {
                case menuItemNewGame:
                    selectedOption = _nop1();
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
                _buttonsLastPressed = VSync(-1);
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
                        _menuItemStates[i].targetPos = _menuItemStates[i].pos - 32;
                    }
                } else {
                    _setMenuItemFadeIn((menuItem - 1) & 3, 0);
                    for (i = 0; i < 4; ++i) {
                        _menuItemStates[i].state = menuItemStateLower;
                        _menuItemStates[i].targetPos = _menuItemStates[i].pos + 32;
                    }
                }
                for (i = 0; i < 10; ++i) {
                    func_80070A58();
                }
            }
            func_8007093C();
        }
        if (selectedOption >= menuItemNewGame) {
            if (_introMoviePlaying != 0) {
                _stopIntroMovie();
            }
            if (selectedOption == menuItemContinue) {
                _playMenuSelectSfx();
            } else {
                _playNewGameSfx();
                func_80071CE0(selectedOption);
            }
        }

        if (selectedOption == menuItemTimeout) {
            selectedOption = 4 - (vs_main_titleScreenCount & 1);
            func_80071CE0(selectedOption);
        }
        for (i = 64; i > 0; --i) {
            VSync(0);
            vs_main_processPadState();
            _titleScreenFade.tag = vs_getTag(_titleScreenFade.tile, primAddrEnd);
            _titleScreenFade.tile.tpage = vs_getTpage(
                320, 0, direct16Bit, semiTransparencySubtract, ditheringOff);
            _titleScreenFade.tile.r0g0b0code = vs_getRGB0(primTileSemiTrans, 8, 8, 8);
            _titleScreenFade.tile.x0y0 = vs_getXY(0, 0);
            _titleScreenFade.tile.wh = vs_getWH(640, 480);
            DrawPrim(&_titleScreenFade);
            func_800436B4();
        }
        VSync(0);
        SetDispMask(0);
        if (selectedOption == menuItemContinue) {
            selectedOption = _displayGameLoadScreen();
            if (selectedOption == menuItemContinue) {
                func_80071CE0(menuItemContinue);
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
    int dummy[2] __attribute__((unused));
    int vsync;

    vs_main_frameBuf = vs_main_frameBuf == 0;
    DrawSync(0);
    vsync = vs_main_gametimeUpdate(0);
    PutDispEnv(vs_main_frameBuf + vs_main_dispEnv);
    PutDrawEnv(vs_main_frameBuf + vs_main_drawEnv);
    DrawOTag(ot);
    return vsync;
}

static void _initTitle()
{
    int i;
    int j;
    u_char* v0;

    _initScreen(640, 240, 512, 0, 0, 0);
    i = 0x43F;
    v0 = D_80061598 + i;
    do {
        *v0-- = 0;
    } while (--i >= 0);

    vs_main_memcpy(vs_main_skillsLearned, D_80075B24, sizeof(D_80075B24));
    vs_main_bzero(D_8005FFD8, sizeof(D_8005FFD8));
    vs_main_bzero(&vs_main_gametime, sizeof(vs_main_gametime));
    vs_main_bzero(&D_8005FEA0, sizeof(D_8005FEA0));
    D_80060064 = 0;
    vs_main_bzero(D_80061078, sizeof(D_80061078));
    vs_main_bzero(D_80060040, sizeof(D_80060040));

    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 3; ++j) {
            D_8005FEA0.unk28[i][j] &= 0xFF000000;
            D_8005FEA0.unk28[i][j] |= 0x800000;
            D_8005FEA0.unk28[i][j] &= 0x80FFFFFF;
            D_8005FEA0.unk28[i][j] &= 0x7FFFFFFF;
        }
    }

    for (i = 0; i < 1; ++i) {
        vs_main_bzero((u_char*)&D_80060068 + i * sizeof(D_80060068), 0x50);
    }

    vs_main_bzero(&D_80061068, sizeof(D_80061068));
    vs_main_memcpy(D_80060168, D_80074C24, sizeof(D_80060168));

    vs_gametime_tickspeed = 2;
    D_80061068.unk4 = (D_80061068.unk4 & 0xE0FF) | 0x400;
    D_80061068.unk6 = (D_80061068.unk6 & 0x83FF) | 0x800;
    D_80061068.unk2 = D_80061068.unk2 & 0x1FFF;
    D_80061068.unk4 = (D_80061068.unk4 & 0x9FFF) | 0x4000;
}

void func_80071CE0(int arg0)
{
    switch (arg0) {
    case 0:
        D_80061598[0xC] = 0;
        D_80061598[0xD] = 0;
        D_80061068.unk0 = 1;
        D_80061068.unk1 = 0;
        return;
    case 3:
        D_80061598[0xC] = 0;
        D_80061598[0xD] = 1;
        D_80061598[0xE] = 1;
        D_80061068.unk0 = 0x14;
        D_80061068.unk1 = 0;
        return;
    case 4:
        D_80061598[0xC] = 0;
        D_80061598[0xD] = 1;
        D_80061598[0xE] = 1;
        D_80061068.unk0 = 2;
        D_80061068.unk1 = 1;
        return;
    case 1:
        D_80061598[0xC] = 0;
        D_80061598[0xD] = 0;
        return;
    default:
        D_80061598[0xC] = 0;
        D_80061598[0xD] = 0;
        return;
    }
}
