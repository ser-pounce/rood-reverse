#include "common.h"
#include "22C.h"
#include "../SLUS_010.40/main.h"
#include "../SLUS_010.40/31724.h"
#include "../SLUS_010.40/sfx.h"
#include "gpu.h"
#include "lbas.h"
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

typedef struct {
    u_char unk0;
    u_char slotId;
    u_char unk2;
    u_char unk3;
    u_char unk4;
    u_char slotUnused;
    u_char unk6;
    u_char unk7;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
    u_char unk14[32];
} _saveSlotMenuEntries_t;

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
    slotStateUnused = 0,
    slotStateAvailable = 1,
    slotStateTemp = 2,
};

typedef struct {
    int key;
    enum slotState_t slotState;
    int unk8;
    int unkC;
    char unk10;
    char unk11;
    char unk12;
    char unk13;
    u_short unk14;
    u_short unk16;
    u_short unk18;
    u_short unk1A;
    u_char unk1C;
    u_char unk1D;
    u_char unk1E;
    u_char unk1F;
    u_short unk20;
    u_short unk22;
    int unk24[23];
} _saveFileInfo_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    u_short unk4[32];
    u_char unk44[0x1C];
    u_char unk60[0x20];
    u_char unk80[0x80];
    u_char unk100[0x80];
    struct savedata_unk180_t {
        int unk180[4];
        vs_Gametime_t gameTime;
        u_short unk194;
        u_short unk196;
        u_short unk198;
        u_short unk19A;
        u_char unk19C;
        u_char unk19D;
        u_char unk19E;
        u_char unk19F;
        u_short unk1A0;
        u_short unk1A2;
        u_char unk1A4[0x5C];
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
    u_long unk0[2][128];
    u_char unk400[7][32];
    u_char unk4E0[22][128];
    u_char unkFE0[0x20];
    u_short unk1000[0x800];
    _saveFileInfo_t unk2000[5];
    struct DIRENTRY unk2280;
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
extern char D_800728B0[];
extern int D_800728C0[];
extern int D_800728E8[];
extern u_char D_80072910[];
extern int D_80072914[];
extern u_char D_80072EF8;
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
extern u_char D_800DC8E0;
extern u_char D_800DC8E1;
extern u_char D_800DC8E2;
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
extern u_char D_800DED73;
extern u_char D_800DED74;
extern u_char _diskState;
extern vs_main_CdQueueSlot* _mcDataLoad;
extern u_char D_800DC8CC[];
extern u_char D_800DC8CD;
extern vs_Gametime_t D_800DC8D0;
extern int D_800DC8D4;
extern u_char D_800DC8D8;
extern u_char D_800DC8D9;
extern u_char _slotsPage;
extern u_char _selectedSlot;
extern u_char D_800DC8DC;
extern u_char D_800DC8DD;
extern u_char D_800DC8E8;
extern u_char D_800DC8E9;
extern int D_800DC8EC;
extern u_char D_800DC8F0;
extern u_char D_800DC8F1;
extern u_char D_800DC8F2;
extern vs_main_settings_t _settingsBackup;
extern int D_800DC918;
extern u_char D_800DC91C;
extern u_char D_800DC91D;
extern u_char D_800DC91E;
extern u_char D_800DC91F;
extern u_char D_800DC920;
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
extern u_short* D_800DEAC0;
extern struct DIRENTRY* _memcardFiles[15];
extern struct DIRENTRY* dirEntBuf;
extern _saveFileInfo_t* _saveFileInfo;
extern u_short D_800DEB0E;
extern int D_800DEB14;
extern _saveSlotMenuEntries_t _saveSlotMenuEntries[10];
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
extern int D_800DED68;
extern void* D_800DED6C;
extern u_char _isSaving;
extern u_char D_800DED71;
extern u_char D_800DED72;
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

enum memCardEventState {
    memCardEventIoEnd = 0,
    memCardEventError = 1,
    memCardEventTimeout = 2,
    memCardEventNew = 3,
    memCardEventNone = 4,
};

#define SWEVENTS 0
#define HWEVENTS 4

#define MAKEXY(x, y) (((y) << 16) + (x))
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

static int _testMemcardEvents(int type)
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

static void _rMemcpy(u_char* dst, void const* src, int count)
{
    do {
        --count;
        dst[count] = ((char const*)src)[count];
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

static u_int func_80068D54()
{
    u_int i;
    u_int var_a2;
    u_int fileIndex;

    var_a2 = 0;
    fileIndex = 0;
    for (i = 0; i < 5; ++i) {
        if (_saveFileInfo[i].slotState >= 3) {
            if (var_a2 < _saveFileInfo[i].unk8) {
                var_a2 = _saveFileInfo[i].unk8;
                fileIndex = i;
            }
        }
    }
    return fileIndex;
}

static int _getCurrentGameSave()
{
    int i;
    for (i = 0; i < 5; ++i) {
        if ((_saveFileInfo[i].slotState >= 3)
            && (_saveFileInfo[i].slotState == vs_main_settings.slotState)
            && (_saveFileInfo[i].key == vs_main_settings.key)
            && (_saveFileInfo[i].unk14 == vs_main_settings.unk18)
            && (_saveFileInfo[i].unk8 == vs_main_settings.unk1C)) {
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

static int _verifySaveChecksums(u_char data[], int sectorCount)
{
    int checksum;
    int i;
    int j;
    u_char* p = data;

    for (i = 0; i < sectorCount; ++i) {
        checksum = 0;
        if (i != 1) {
            for (j = 0; j < 256; ++j) {
                checksum ^= p[j];
            }

            if (data[(u_int)(420 + i)] != checksum) {
                return 1;
            }
        }
        p += 256;
    }

    p = &data[256];
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
        _decode(saveInfo[3].key, (u_char*)&saveInfo[3].slotState,
            sizeof(_saveFileInfo_t) - sizeof(int));
        if (_verifySaveChecksums((u_char*)saveInfo, 2) == 0) {
            _rMemcpy(
                (u_char*)(&_saveFileInfo[id - 1]), &saveInfo[3], sizeof(saveInfo[3]));
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
                _saveFileInfo[fileNo - 1].slotState = slotStateTemp;
            } else if (_readSaveFileInfo(((port - 1) << 16) | fileNo) != 0) {
                slotsAvailable += (file->size + 0x1FFF) >> 13;
            }
        }
        slotsAvailable -= (file->size + 0x1FFF) >> 13;
    }

    for (; slotsAvailable >= 3; slotsAvailable -= 3) {
        for (i = 0; i < 5; ++i) {
            if (_saveFileInfo[i].slotState == slotStateUnused) {
                _saveFileInfo[i].slotState = slotStateAvailable;
                break;
            }
        }
    }

    return 0;
}

int createSaveFile(int port, int id)
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

int _memCardHandler(int arg0)
{
    enum memCardStates {
        init = 0,
        ready = 1,
        new = 2,
        confirmed = 3,
        loadReady = 4,
        loaded = 5,
    };

    int event;

    if (arg0 != 0) {
        _memcardPort = (arg0 - 1) * 16;
        _memCardState = init;
        _memCardInitTmeout = 0;
        return 0;
    }
    switch (_memCardState) {
    case init:
        if (++_memCardInitTmeout >= 4) {
            return 2;
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
        case memCardEventIoEnd:
            _memCardState = loadReady;
            break;
        case memCardEventError:
        case memCardEventTimeout:
            _memCardState = init;
            break;
        case memCardEventNew:
            _memCardState = new;
            break;
        case memCardEventNone:
            if (_memCardTimeout++ > 64) {
                _memCardState = init;
            }
            break;
        }
        break;
    case new:
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
        } while (event == memCardEventNone);
        if (event == memCardEventIoEnd) {
            _memCardState = loadReady;
            break;
        }
        if (event < memCardEventIoEnd)
            break;
        if (event >= memCardEventNone)
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
        case memCardEventIoEnd:
            return _memcardEvType + 1;
        case memCardEventError:
        case memCardEventTimeout:
            _memCardState = init;
            break;
        case memCardEventNew:
            return _memcardEvType + 3;
        case memCardEventNone:
            if (_memCardTimeout++ > 64) {
                _memCardState = init;
            }
            break;
        }
        break;
    }
    return 0;
}

int func_800696D0(int arg0)
{
    int blockCount;
    savedata_t* spmcimg;
    void* spmcimg2;
    int* s4;
    int* unk180;

    spmcimg = (savedata_t*)_spmcimg;
    spmcimg2 = spmcimg + 1;
    s4 = (int*)(spmcimg + 1);
    unk180 = spmcimg[1].unk180.unk180;

    _decode(unk180[0], (u_char*)(&unk180[1]), 0x5A7C);

    blockCount = 92;
    if (arg0 != 0) {
        blockCount = 32;
    }

    if ((_verifySaveChecksums((u_char*)(spmcimg + 1), blockCount) != 0)
        || (unk180[3] != 0x20000107)) {
        do {
            return 1;
        } while (0);
    }

    if (arg0 == 0) {
        return 0;
    }

    _rMemcpy(D_80061598, spmcimg[1].unk200, sizeof(D_80061598));
    _rMemcpy(vs_main_skillsLearned, spmcimg[1].unk640, sizeof(vs_main_skillsLearned));
    _rMemcpy(D_8005FFD8, spmcimg[1].unk660, sizeof(D_8005FFD8));
    _rMemcpy((u_char*)(&vs_main_settings), &spmcimg[1].unk6A8, sizeof(vs_main_settings));
    _rMemcpy((u_char*)(&D_80060068), &spmcimg[1].unk6C8, sizeof(D_80060068));
    _rMemcpy((u_char*)D_80060168, spmcimg[1].unk7C8, sizeof(D_80060168));
    _rMemcpy((u_char*)(&D_800619D8), spmcimg[1].unk16C8, sizeof(D_800619D8));
    _rMemcpy((u_char*)(&D_80061068), &spmcimg[1].unk1778, sizeof(D_80061068));
    _rMemcpy((u_char*)(&D_8005FEA0), &spmcimg[1].unk1784, sizeof(D_8005FEA0));
    D_80060064 = s4[0x626];
    _rMemcpy(D_80061078, spmcimg[1].unk189C, sizeof(D_80061078));
    spmcimg2 = D_80060040;
    _rMemcpy(D_80060040, spmcimg[1].unk1DBC, sizeof(D_80060040));
    vs_main_gametime = spmcimg[1].unk180.gameTime;
    func_80042CA0();
    vs_main_setMonoSound(vs_main_settings.monoSound);
    return 0;
}

// 
void func_80069888(int);
INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_80069888);

static int _loadSaveData(int portFileno)
{

    enum loadSaveDataState { init = 0, reading = 1 };

    int ev;
    int nBytes;
    u_char* filename;
    void* temp_s2;
    int new_var;

    temp_s2 = _spmcimg + 0x5C00;
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
                          * ((_loadSaveDataErrorOffset * 0x14) - (D_800DEB12 - new_var)))
            / D_800DEB0E;
        _loadSaveDataErrorOffset = _loadSaveDataErrors;
        D_800DEB0E = 0xC0 - (_isTempSave << 7);
        D_800DEB10 = D_800DEB14;

        memset(temp_s2, 0, 0x5C00);

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
        nBytes = 0x5C00;
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
        if (ev < memCardEventNone) {
            close(_memCardFd);
            if (ev == memCardEventIoEnd) {
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
    int temp_s2;
    int temp_s3;

    if (arg0 != 0) {
        D_800DC8BB = 0;
        D_800DC8BC = 0;
        _loadSaveDataErrorOffset = 0;
        _memcardManagerPort = arg0 >> 0xC;
        _memcardFileno = arg0 & 7;
        D_800DEB12 = 0x50;
        D_800DEB10 = 0;
        _memcardSaveState = memcardSaveIdExists(_memcardFileno + 0x40);
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
        temp_v1_2 = ((D_800DEB14 - D_800DEB10) * (0x140 - D_800DEB12)) / D_800DEB0E;
        D_800DEB10 = D_800DEB14;
        D_800DEB0E = 0x180;
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
        if (write(_saveFileId, _spmcimg, 0x5C00) == -1) {
            close(_saveFileId);
            ++D_800DC8BB;
            break;
        }
        _memcardSaveState = readReady;
        // fallthrough
    case readReady: {
        temp_s3 = _testMemcardEvents(SWEVENTS);
        if (temp_s3 < memCardEventNone) {
            close(_saveFileId);
            if (temp_s3 == memCardEventIoEnd) {
                _memcardSaveState = verifyPending;
                temp_s2 = D_800DEB12;
                temp_s3 = D_800DEB10;
                _loadSaveData((_memcardManagerPort << 0xC) | (_memcardFileno + 8));
                D_800DEB12 = temp_s2;
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
        for (temp_s2 = 0; temp_s2 < 0x5C00; ++temp_s2) {
            if (_spmcimg[temp_s2] != _spmcimg[temp_s2 + 0x5C00]) {
                break;
            }
        }
        if (temp_s2 < 0x5C00) {
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
        D_800DEAC0 = _mcData->unk1000;
        _saveFileInfo = _mcData->unk2000;
        dirEntBuf = &_mcData->unk2280;
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

void _drawSprt(int xy, int uvClut, int wh, int tpage)
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

void func_8006A81C(int xy, int id) { _drawSprt(xy, D_800728C0[id], D_800728E8[id], 0xC); }

void func_8006A860(int arg0, u_int arg1, u_int arg2)
{
    do {
        _drawSprt(arg0, vs_getUV0Clut(((arg1 / arg2) * 6), 0, 832, 223), MAKEWH(6, 10),
            getTPage(0, 0, 768, 0));
        arg1 = arg1 % arg2;
        arg2 /= 10;
        arg0 += 5;
    } while (arg2 != 0);
}

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

void func_8006A928(int arg0, int arg1, int arg2, u_int arg3)
{
    int temp_a1;
    int temp_s4;
    int var_s2;
    u_int rgb1;
    u_int var_s1;
    u_int rgb0;
    int new_var;
    u_int var_s1_2;
    int new_var2;
    int new_var3;
    int new_var4;

    if (arg3 != 0) {
        var_s1 = (((arg2 * 64) + arg3) - 1) / arg3;
    } else {
        var_s1 = 0;
    }

    rgb0 = ((207 << 16) | (224 << 8)) | 45;
    if (arg1 != 0) {
        rgb0 = ((159 << 16) | (120 << 8)) | 220;
    }

    new_var3 = (rgb0 & 0xFF);
    temp_a1 = 0x40 - var_s1;
    rgb1 = ((((var_s1 * 0xFF) + (new_var3 * temp_a1)) >> 6)
               | ((((var_s1 * 0xF0) + (((rgb0 >> 8) & 0xFF) * temp_a1)) >> 6) << 8))
        | ((((2 * (79 * var_s1)) + ((rgb0 >> 16) * temp_a1)) >> 6) << 16);

    DrawSync(0);
    _primBuf.tag = vs_getTag(_primBuf.prim.tilePoly, primAddrNull);
    _primBuf.prim.tilePoly.tile.tpage
        = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
    _primBuf.prim.tilePoly.tile.r0g0b0code = vs_getRGB0(primTile, 0, 40, 64);
    new_var = MAKEWH(66, 5);
    new_var2 = (var_s1 + MAKEXY(0, 9));
    _primBuf.prim.tilePoly.tile.x0y0 = arg0++ + MAKEXY(0, 8);
    _primBuf.prim.tilePoly.tile.wh = MAKEWH(66, 5);
    _primBuf.prim.tilePoly.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4, rgb1);
    _primBuf.prim.tilePoly.polyG4.x0y0 = arg0 + MAKEXY(0, 9);
    _primBuf.prim.tilePoly.polyG4.r1g1b1 = rgb0;
    _primBuf.prim.tilePoly.polyG4.x1y1 = arg0 + new_var2;
    _primBuf.prim.tilePoly.polyG4.r2g2b2 = rgb1;
    _primBuf.prim.tilePoly.polyG4.x2y2 = arg0 + MAKEXY(0, 12);
    _primBuf.prim.tilePoly.polyG4.r3g3b3 = rgb0;
    _primBuf.prim.tilePoly.polyG4.x3y3 = MAKEXY(0, 12);
    _primBuf.prim.tilePoly.polyG4.x3y3
        = arg0 + (var_s1 + _primBuf.prim.tilePoly.polyG4.x3y3);
    DrawPrim(&_primBuf);

    var_s1 = countDigits(arg2);
    temp_s4 = countDigits(arg3);
    func_8006A81C(arg0 - 1, arg1 + 7);
    new_var = var_s1 * 6;
    var_s2 = (arg0 - (new_var - (new_var4 = 0x37))) - (temp_s4 * 5);
    var_s1_2 = D_80072910[var_s1];
    do {
        _drawSprt(var_s2 - MAKEXY(0, 1),
            (((arg2 / var_s1_2) << 3) + 64) | (getClut(832, 223) << 16), MAKEWH(7, 12),
            getTPage(0, 0, 768, 0));
        arg2 = arg2 % var_s1_2;
        var_s1_2 /= 10;
        do {
            var_s2 += 6;
        } while (0);
    } while (var_s1_2 != 0);
    func_8006A81C(var_s2 + 1, 9);
    func_8006A860(var_s2 + 6, arg3, D_80072910[temp_s4]);
}

void _loadFileAnim(u_int arg0, int arg1)
{
    u_char* new_var __attribute__((unused));
    int gradientColor1;
    int gradientColor2;
    u_int var_s3;
    u_int i;

    var_s3 = arg0 - 48;
    new_var = &_isSaving;

    if (var_s3 < 64) {
        var_s3 = 64;
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
        _primBuf.prim.polyG4_tpage.x0y0 = var_s3 | arg1;
        _primBuf.prim.polyG4_tpage.x1y1 = arg0 | arg1;
        _primBuf.prim.polyG4_tpage.x2y2 = var_s3 | MAKEXY(arg1, 32);
        _primBuf.prim.polyG4_tpage.tpage
            = vs_getTpage(0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
        _primBuf.prim.polyG4_tpage.r1g1b1 = gradientColor2;
        _primBuf.prim.polyG4_tpage.r2g2b2 = gradientColor1;
        _primBuf.prim.polyG4_tpage.r3g3b3 = gradientColor2;
        _primBuf.prim.polyG4_tpage.x3y3 = arg0 | MAKEXY(arg1, 32);
        DrawPrim(&_primBuf);
        var_s3 = arg0;
        arg0 += 16;
        gradientColor1 = gradientColor2;
        gradientColor2 = 0;
    }
}

void func_8006ACD8(int arg0, int y)
{
    int yOfst;
    int colour0;
    u_int i;
    int colour1 = 0;

    if (_isSaving != 0) {
        colour0 = arg0 + (arg0 << 15);
    } else {
        colour0 = (arg0 - (arg0 >> 3)) + (arg0 << 8);
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
    D_800DED6C = 0;
    D_800DED71 = 0;
    D_800DED68 = 0;
    D_800DEB14 = 0;
    D_800DED72 = 0;
    D_800DEB0E = 0x180;
    memset(_saveSlotMenuEntries, 0, sizeof(_saveSlotMenuEntries));
}

_saveSlotMenuEntries_t* func_8006AE70(int arg0, int arg1, int arg2, u_char* arg3)
{
    _saveSlotMenuEntries_t* temp_s3;
    int i;
    u_int var_v1;

    temp_s3 = &_saveSlotMenuEntries[arg0];
    memset(temp_s3, 0, sizeof(*temp_s3));
    temp_s3->unk0 = 1;
    temp_s3->slotId = -1;
    *(int*)&temp_s3->unkC = arg1;
    *(int*)&temp_s3->unk10 = arg2;

    if (arg3 != NULL) {
        for (i = 0; i < 32;) {
            var_v1 = *arg3++;
            if (var_v1 == 0xFAu) {
                temp_s3->unk14[i++] = var_v1;
                do {
                    var_v1 = *(arg3++);
                } while (0);
            } else {
                if (var_v1 == 0xE7u) {
                    temp_s3->unk14[i] = 0xFF;
                    return temp_s3;
                }
                if (var_v1 >= 0xE5u) {
                    continue;
                }
            }
            temp_s3->unk14[i++] = var_v1;
        }
    } else {
        temp_s3->unk14[0] = 0xFF;
    }
    return temp_s3;
}

void func_8006AF78(int arg0)
{
    memset(&_saveSlotMenuEntries[arg0], 0, sizeof(_saveSlotMenuEntries_t));
}

int func_8006AFBC()
{
    int i;

    for (i = 0; i < 10 && _saveSlotMenuEntries[i].unk0 < 2; ++i)
        ;
    return i == 10;
}

int func_8006AFF8(u_int arg0, int x, int y, int arg3)
{
    if ((arg0 >> 8) == 14) {
        return x + (u_char)arg0;
    }
    if (arg0 != 0x8F) {
        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.sprt, primAddrNull);
        _primBuf.prim.sprt.tpage
            = vs_getTpage(832, 0, clut4Bit, semiTransparencyFull, ditheringOff);
        _primBuf.prim.sprt.r0g0b0code = vs_getRGB0(primSprtSemtTrans, 128, 128, 128);
        _primBuf.prim.sprt.x0y0 = vs_getYX(y, x);
        _primBuf.prim.sprt.wh = vs_getWH(12, 12);
        _primBuf.prim.sprt.u0v0clut
            = vs_getUV0Clut((arg0 % 21) * 12, (arg0 / 21) * 12, arg3 * 16 + 896, 222);
        DrawPrim(&_primBuf);
    }
    return x + D_80072914[arg0];
}

int func_8006B138(int arg0)
{
    int temp_s0;
    int temp_v0;
    int temp_v1;
    int var_a0;
    u_int temp_s1;

    if (arg0 != 0) {
        D_800DC8CC[0] = 0;
        D_800DC8CD = 0;
        return 0;
    }

    temp_s1 = D_800DC8CC[0] >> 1;
    temp_s0 = (D_800DC8CC[0] >> 1) + 1;

    if ((D_800DC8CC[0] & 1) == 0) {
        D_800DED6C = D_800DEAC0 + (D_800DEAC0 + temp_s0)[21];
        _memCardHandler(temp_s0);
        ++D_800DC8CC[0];
    } else {
        temp_v1 = _memCardHandler(0) & 3;

        if (temp_v1 != 0) {
            if (temp_v1 == 1) {
                if (_initSaveFileInfo(temp_s0) == 0) {
                    temp_v0 = _getCurrentGameSave();
                    var_a0 = temp_v0 != 0;
                    if (var_a0) {
                        return temp_v0 + (temp_s1 * 0x10);
                    }
                }
            } else if (temp_v1 == 2) {
                if (D_800DC8CC[0] != 1) {
                    if (D_800DC8CD != 0) {
                        return -2;
                    }
                } else {
                    D_800DC8CD = D_800DC8CC[0];
                }
            }
            ++D_800DC8CC[0];
        }
    }
    var_a0 = 0;
    if (D_800DC8CC[0] == 4) {
        var_a0 = -1;
    }
    return var_a0;
}

int func_8006B288(int arg0)
{
    int temp_v0;

    if (arg0 != 0) {
        _memCardHandler(arg0 & 3);
        D_800DC8CC[2] = (arg0 >> 4);
        return 0;
    }
    temp_v0 = _memCardHandler(0);
    if (temp_v0 != 0) {
        switch (temp_v0 & D_800DC8CC[2]) {
        case 1:
            return 1;
        case 2:
            D_800DED6C = D_800DEAC0 + 0xE3;
            break;
        case 3:
            D_800DED6C = D_800DEAC0 + 0x2E2;
            break;
        default:
            D_800DED6C = D_800DEAC0 + 0x1DE;
            break;
        }
        return -1;
    }
    return 0;
}

void func_8006B364(u_char* arg0, int arg1, int arg2, int arg3)
{
    int var_a1;
    u_char temp_t0;
    int new_var;
    u_int temp_v1;
    u_int var_a0;

    new_var = arg1;
    var_a1 = new_var;

    while (1) {
        var_a0 = *arg0++;
        if (var_a0 < 0xEC) {
            if (var_a0 < 0xE5) {
                var_a1 = func_8006AFF8(var_a0, var_a1, arg2, arg3);
            } else if (var_a0 == 0xE6) {
                temp_t0 = (D_80072EF8 + 1) % 12;
                var_a0 = temp_t0;
                var_a0 = 0xBC - ((var_a0 & 0xFF) >> 2);
                D_80072EF8 = temp_t0;
                var_a1 = func_8006AFF8(var_a0, var_a1, arg2, arg3);
            } else if (var_a0 != 0xE7) {
                if (var_a0 == 0xE8) {
                    arg2 += 0xD;
                    var_a1 = new_var;
                }
            } else {
                break;
            }
        } else {
            temp_v1 = *arg0++;
            if (var_a0 == 0xFA) {
                if (temp_v1 >= 0xF0) {
                    var_a1 += -0x100 + temp_v1;
                } else {
                    var_a1 += temp_v1;
                }
            }
        }
    }
}

u_int func_8006B490(u_int arg0, u_int arg1, u_int arg2)
{
    int temp_a3;
    u_int i;
    u_int var_v1;

    var_v1 = 0;
    for (i = 0; i < 3; ++i) {
        temp_a3 = ((arg0 >> 0x10) & 0xFF) * (8 - arg2);
        arg0 <<= 8;
        var_v1 = (var_v1 << 8) + ((temp_a3 + (((arg1 >> 0x10) & 0xFF) * arg2)) >> 3);
        arg1 <<= 8;
    }
    return var_v1;
}

u_int func_8006B4EC(int arg0, u_int arg1)
{
    u_int a0;
    u_int a1;

    if (arg1 < 9) {
        a0 = func_8006B490(0x6B4100, 0x6C8219, arg1);
        a1 = func_8006B490(0x330500, 0x262801, arg1);
    } else {
        a0 = D_80072EFC[((arg1 >> 3) - 2)];
        a1 = D_80072F04[((arg1 >> 3) - 2)];
    }
    return func_8006B490(a0, a1, arg0);
}

void func_8006B5A0(_saveSlotMenuEntries_t* arg0)
{
    u_long clut[130];
    _saveFileInfo_t* saveInfo;
    int xy;
    int uvClut;
    int var_a3;
    int var_s1;
    int y;
    u_int color1;
    int color2;
    u_int temp_v1;
    u_long* var_a1_2;
    int new_var;

    if (arg0->unk4 != 0) {
        arg0->unk2 = 8;
    } else if (arg0->unk2 != 0) {
        --arg0->unk2;
    }
    if (arg0->slotUnused != 0) {
        arg0->unk2 = 0;
    }
    if ((arg0->slotId >= 5) || ((arg0->unkE - 0x48) < 0x51U)) {
        y = arg0->unk3;
        color1 = func_8006B4EC(8 - arg0->unk2, y);
        color2 = func_8006B4EC(arg0->unk2, y);
        if (y & 7) {
            arg0->unk3 = y + 1;
        }
        y = arg0->unkE << 16;

        DrawSync(0);
        _primBuf.tag = vs_getTag(_primBuf.prim.tilePoly, primAddrNull);
        _primBuf.prim.tilePoly.tile.tpage
            = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
        _primBuf.prim.tilePoly.tile.r0g0b0code = vs_getRGB0(primTile, 0, 0, 0);
        _primBuf.prim.tilePoly.tile.x0y0 = vs_getYX(arg0->unkE + 2, arg0->unkC + 2);
        _primBuf.prim.tilePoly.tile.wh = arg0->unk10 | (arg0->unk12 << 0x10);
        _primBuf.prim.tilePoly.polyG4.r0g0b0code = vs_getRGB0Raw(primPolyG4, color1);
        _primBuf.prim.tilePoly.polyG4.x0y0 = (u_short)arg0->unkC | y;
        _primBuf.prim.tilePoly.polyG4.r1g1b1 = color2;
        _primBuf.prim.tilePoly.polyG4.x1y1 = ((arg0->unkC + arg0->unk10) & 0xFFFF) | y;
        _primBuf.prim.tilePoly.polyG4.r2g2b2 = color1;
        _primBuf.prim.tilePoly.polyG4.x2y2
            = (u_short)arg0->unkC | ((arg0->unkE + arg0->unk12) << 0x10);
        _primBuf.prim.tilePoly.polyG4.r3g3b3 = color2;
        _primBuf.prim.tilePoly.polyG4.x3y3 = ((arg0->unkC + arg0->unk10) & 0xFFFF)
            | ((arg0->unkE + arg0->unk12) << 0x10);
        DrawPrim(&_primBuf);

        uvClut = arg0->unkC + 6;
        for (color1 = 0; (int)color1 < 32; ++color1) {
            color2 = arg0->unk14[color1];
            if (color2 == 0xFA) {
                uvClut += arg0->unk14[++color1];
            } else if (color2 != 0xFF) {
                uvClut = func_8006AFF8(color2, uvClut, arg0->unkE, 0);
            } else {
                break;
            }
        }
        color2 = arg0->slotId;
        if (color2 < 5) {
            _readImage(MAKEXY(768, 227), clut, MAKEWH(256, 1));
            saveInfo = &_saveFileInfo[color2];
            var_s1 = arg0->unk6 - 1;
            color1 = saveInfo->slotState;
            if (saveInfo->slotState < 3) {
                if (saveInfo->slotState == 0) {
                    var_s1 = -2;
                } else if (saveInfo->slotState == 2) {
                    var_s1 = -4;
                } else if (_isSaving != 0) {
                    var_s1 = -1;
                } else {
                    var_s1 = -5;
                }
            } else if (var_s1 >= 48) {
                var_s1 = -3;
            }
            if (var_s1 >= 32u) {
                var_a1_2 = &_mcData->unk0[1][0];
            } else {
                var_a1_2 = &_mcData->unk0[0][0];
            }
            _drawImage(MAKEXY(768, 227), var_a1_2, MAKEWH(256, 1));
            if (var_s1 < 0) {
                uvClut = (~var_s1 << 13) | vs_getUV0Clut(64, 0, 768, 227);
                xy = (arg0->unkC - 64) | y;
                _drawSprt(xy, uvClut, MAKEWH(64, 32), ((8 - arg0->unk2) << 0x13) | 0x9C);
            } else {
                int v0;
                uvClut = ((var_s1 & 8) * 8) | ((var_s1 & 7) << 0xD)
                    | vs_getUV0Clut(0, 0, 768, 227);
                xy = (arg0->unkC - 0x40) | y;
                new_var = (((var_s1 & 0x30) * 4) + 0x340) & 0x3FF;
                v0 = new_var >> 6;
                var_a3 = (((8 - arg0->unk2) << 0x13) | 0x90);
                _drawSprt(xy, uvClut, MAKEWH(64, 32), v0 | var_a3);
            }
            _drawImage(MAKEXY(768, 227), clut, MAKEWH(256, 1));
            func_8006A81C((arg0->unkC - 0x16) | y, 1);
            func_8006A860((arg0->unkC - 9) | y, color2 + 1, 0xAU);
            temp_v1 = saveInfo->slotState;
            if (temp_v1 == 0) {
                func_8006B364(
                    (u_char*)D_800DEAC0 + 0x372, arg0->unkC + 6, arg0->unkE + 0xA, 3);
            } else if (temp_v1 == 1) {
                if (_isSaving == 0) {
                    func_8006B364(
                        (u_char*)D_800DEAC0 + 0x38A, arg0->unkC + 6, arg0->unkE + 0xA, 3);
                } else {
                    func_8006B364(
                        (u_char*)D_800DEAC0 + 0x3A0, arg0->unkC + 6, arg0->unkE + 0xA, 0);
                }
            } else {
                y = y + 0x40000;
                func_8006B364((u_char*)&D_800DEAC0[(&D_800DEAC0[arg0->unk6])[41]],
                    arg0->unkC + 6, arg0->unkE + 4, 0);
                func_8006A81C(y | 0xAC, 2);
                func_8006A81C(y | 0xBD, 0);
                color1 = saveInfo->unk1E;

                if (color1 == 0x64) {
                    func_8006A860(y | 0xC0, 0x64U, 0x64);
                    func_8006A81C((y + 0xFFFF0000) | 0xCF, 6);
                } else {
                    func_8006A860(y | 0xC0, color1, 0xA);
                    func_8006A81C((y + 0xFFFF0000) | 0xCA, 6);
                }
                func_8006A81C(y | 0xD9, 3);
                func_8006A81C(y | 0xEF, 0);
                func_8006A860(y | 0xF2, (u_int)saveInfo->unk14, 0x3E8U);
                func_8006A81C(y | 0x10B, 4);
                func_8006A81C(y | 0x125, 0);
                func_8006A860(y | 0x128, (u_int)saveInfo->unk1D, 0xAU);
                y = y + 0xD0000;
                if (saveInfo->unk1D != 0) {
                    _drawSprt(y | 0x45, 0x37F910F0, 0x100010, 0xC);
                }
                func_8006A81C(y | 0xF0, 5);
                color1 = saveInfo->unk13;
                if (color1 == 0x64) {
                    func_8006A860(y | 0x107, color1, 0x64);
                } else {
                    func_8006A860(y | 0x10C, color1, 10);
                }
                func_8006A81C(y | 0x117, 0);
                func_8006A860(y | 0x11A, (u_int)saveInfo->unk12, 0xAU);
                func_8006A81C(y | 0x125, 0);
                func_8006A860(y | 0x128, (u_int)saveInfo->unk11, 0xAU);
                func_8006A928(y | 0x58, 0, (int)saveInfo->unk18, (u_int)saveInfo->unk1A);
                func_8006A928(y | 0x9E, 1, (int)saveInfo->unk20, (u_int)saveInfo->unk22);
                y = y + 0xFFEF0000;
            }
            if ((arg0->unk4 != 0) && (D_800DEB14 != 0)) {
                if (D_800DEB14 < 0) {
                    int v0 = D_800DEB14++;
                    char* p = D_800728B0 + v0;
                    func_8006ACD8(-p[17], y);
                } else {
                    int new_var3 = 0x140;
                    _loadFileAnim(D_800DEB12
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

static void _drawSaveMenu(int arg0)
{
    int dummy[2];
    _saveSlotMenuEntries_t* var_s1;
    int j;
    int i;
    u_int var_s7;
    int temp_t0;
    int new_var;

    var_s1 = _saveSlotMenuEntries;
    var_s7 = 0;
    if (arg0 != 0) {
        var_s7 = 320;
    }
    _drawSprt(MAKEXY(256, 176), vs_getUV0Clut(0, 176, 768, 227), MAKEWH(64, 64), 0x9C);
    _drawSprt(MAKEXY(0, 176), vs_getUV0Clut(0, 176, 768, 227), MAKEWH(256, 64), 0x9A);

    for (i = 0; i < 10; ++i, ++var_s1) {
        temp_t0 = var_s1->unk0;
        if (temp_t0 == 2) {
            if ((var_s1->unkC) < var_s1->unk8) {
                var_s1->unkC += 32u;
                if (var_s1->unkC >= var_s1->unk8) {
                    var_s1->unkC = var_s1->unk8;
                    var_s1->unk0 = 1;
                }
            } else {

                for (j = 1; j < 16; ++j) {
                    if ((var_s1->unk8 + D_8007289C[j]) >= var_s1->unkC) {
                        break;
                    }
                }
                var_s1->unkC = var_s1->unk8 + D_8007289C[j - 1];
                if (var_s1->unk10 < (0x140 - var_s1->unkC)) {
                    var_s1->unk10 = (0x140 - var_s1->unkC);
                }
                if (var_s1->unkC == var_s1->unk8) {
                    var_s1->unk0 = 1;
                }
            }
        }
        if (temp_t0 == 3) {
            if (var_s1->unkE > var_s1->unk8) {
                for (j = 1; j < 16; ++j) {
                    if ((var_s1->unk8 + D_8007289C[j]) >= var_s1->unkE) {
                        break;
                    }
                }
                var_s1->unkE = (var_s1->unk8 + D_8007289C[j - 1]);
            }
            if (var_s1->unkE == var_s1->unk8) {
                var_s1->unk0 = 1;
            }
        }
        if (temp_t0 == 4) {
            if (var_s1->unkC < var_s1->unk8) {
                for (j = 1; j < 16; ++j) {
                    if (var_s1->unkC >= (-D_8007289C[j])) {
                        break;
                    }
                }
                var_s1->unkC = -D_8007289C[j - 1];
                if (var_s1->unkC == 0) {
                    var_s1->unk0 = 1;
                }
            } else {
                var_s1->unkC = var_s1->unkC - 0x20;
                if (var_s1->unk8 >= var_s1->unkC) {
                    var_s1->unkC = var_s1->unk8;
                    var_s1->unk0 = 1;
                }
            }
        }
        if (temp_t0 != 0) {
            func_8006B5A0(var_s1);
        }
    }

    for (i = 1; i < 4; ++i) {
        new_var = 0x100;
        _drawSprt(MAKEXY(0, 0xBB - i), (0xBB - i) << 8, MAKEWH(256, 1),
            (var_s7 >> 6) | (((4 - i) << 0x15) | new_var));
        _drawSprt(MAKEXY(256, 0xBB - i), (0xBB - i) << 8, MAKEWH(64, 1),
            (((int)(var_s7 + new_var)) >> 6) | (((4 - i) << 0x15) | new_var));
    }
    _drawSprt(MAKEXY(10, 181), 0x37F59140, MAKEWH(33, 7), 0xC);
    DrawSync(0);
    _primBuf.tag = 0x03000000;
    _primBuf.prim.sprt.tpage = 0x60000000;
    _primBuf.prim.sprt.r0g0b0code = 0xBB0000;
    _primBuf.prim.sprt.x0y0 = 0x340140;
    DrawPrim(&_primBuf);
    if (D_800DED68 != 0) {
        _drawSprt(D_800DED68, 0x37F83020, MAKEWH(16, 16),
            (D_800728B0[D_800DED71] << 0x10) | 0xC);
        D_800DED71 = (D_800DED71 + 1) & 0xF;
        if (vs_main_buttonsPressed & 0x10) {
            vs_main_playSfxDefault(0x7E, 7);
        }
    } else {
        D_800DED71 = 0;
    }
    if (D_800DED6C != 0) {
        func_8006B364((u_char*)D_800DED6C, 0x10, 0xC0, 0);
    }
    if (D_800DED72 != 0) {
        DrawSync(0);
        _primBuf.tag = 0x04000000;
        _primBuf.prim.sprt.tpage = 0xE1000140;
        _primBuf.prim.sprt.x0y0 = 0;
        _primBuf.prim.sprt.u0v0clut = 0xE00140;
        _primBuf.prim.sprt.r0g0b0code = (D_800DED72 * 0x80808) | 0x62000000;
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

int func_8006C15C(int arg0)
{
    _saveSlotMenuEntries_t* temp_v0_2;
    int currentSlot;
    int i;

    if (arg0 != 0) {
        D_800DC8D9 = arg0;
        _selectedSlot = func_80068D54();
        _slotsPage = 0;
        if (_selectedSlot == 4) {
            _slotsPage = 2;
            _selectedSlot = 2;
        } else if (_selectedSlot != 0) {
            _slotsPage = _selectedSlot - 1;
            _selectedSlot = 1;
        }
        D_800DC8D4 = -1;
        D_800DC8DD = 0;
        D_800DC8D8 = 0;
        return 0;
    }
    switch (D_800DC8D8) {
    case 0:
        for (i = 0; i < 5; ++i) {
            temp_v0_2
                = func_8006AE70(i + 5, (0x480000 + i * 0x280000) | 0x40, 0x200100, 0);
            temp_v0_2->slotId = i;
            temp_v0_2->slotUnused = _saveFileInfo[i].slotState < 3;
            temp_v0_2->unk6 = _saveFileInfo[i].unk1C;
        }
        D_800DC8D8 = 1;
        D_800DED6C = D_800DEAC0 + 0x13B;
        // fallthrough
    case 1:
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            for (i = 5; i < 10; ++i) {
                func_8006AF78(i);
            }
            D_800DED68 = 0;
            return -1;
        }
        for (i = 0; i < 5; ++i) {
            _saveSlotMenuEntries[i + 5].unkE = (((i - _slotsPage) * 0x28) + 0x48);
            _saveSlotMenuEntries[i + 5].unk4 = 0;
        }
        currentSlot = _selectedSlot + _slotsPage;
        if (vs_main_buttonsPressed & PADRright) {
            if (_saveFileInfo[currentSlot].slotState >= 3) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                _saveSlotMenuEntries[currentSlot + 5].unk4 = 1;
                D_800DED68 = 0;
                func_8006B288(D_800DC8D9 + 0x70);
                D_800DC8D8 = 2;
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
        D_800DED68 = (((_selectedSlot * 0x28) + 0x3E) << 0x10) | 0x18;
        _saveSlotMenuEntries[currentSlot + 5].unk4 = 1;
        break;
    case 2:
        currentSlot = func_8006B288(0);
        if (currentSlot != 0) {
            if (currentSlot >= 0) {
                int new_var;
                _loadSaveData(((_selectedSlot + _slotsPage) + 1)
                    | (new_var = ((D_800DC8D9 - 1) << 16) | 256));
                D_800DC8D8 = 3;
                D_800DED6C = D_800DEAC0 + 0x193;
            } else {
                D_800DC8D8 = 4;
            }
        }
        break;
    case 3:
        currentSlot = _loadSaveData(0);
        ++D_800DEB14;
        if (currentSlot != 0) {
            D_800DEB14 = 0;
            do {
                D_800DC8DC = 0;
                if (currentSlot < 0) {
                    D_800DED6C = D_800DEAC0 + 0x11E;
                    break;
                }
                switch (func_800696D0(1)) {
                case 0:
                    D_800DEB14 = -16;
                    vs_main_playSfxDefault(0x7E, 8);
                    D_800DC8DC = 16;
                    D_800DC8D4 = 1;
                    D_800DED6C = D_800DEAC0 + 0x1B2;
                    break;
                case 1:
                    D_800DED6C = D_800DEAC0 + 0x155;
                    break;
                }
            } while (0);

            D_800DC8D0 = vs_main_gametime;
            D_800DC8D8 = 4;
        }
        break;
    case 4:
        if (D_800DC8DC != 0) {
            --D_800DC8DC;
        }
        if (D_800DC8D4 == 1) {
            ++D_800DC8DD;
        }
        if (((u_char)vs_main_buttonsPressed != 0) || (D_800DC8DD == 0x96)) {
            if (D_800DC8D4 < 0) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            }
            D_800DC8D8 = 5;
        }
        break;
    case 5:
        if (D_800DC8DC != 0) {
            --D_800DC8DC;
            break;
        }
        if (D_800DC8D4 == 1) {
            vs_main_gametime = D_800DC8D0;
        } else {
            for (i = 5; i < 10; ++i) {
                func_8006AF78(i);
            }
        }
        return D_800DC8D4;
    }
    return 0;
}

// https://decomp.me/scratch/KxBXc
int func_8006C778(int);
INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006C778);

int func_8006CABC(int arg0)
{
    _saveSlotMenuEntries_t* temp_v0;
    int i;

    if (arg0 != 0) {
        D_800DC8E2 = arg0 - 1;
        D_800DC8E1 = 1;
        _isSaving = 0;
        D_800DC8E0 = 0;
        return 0;
    }
    switch (D_800DC8E0) {
    case 0:
        temp_v0 = func_8006AE70(0, 0x220140, 0xC008C, (u_char*)(D_800DEAC0 + 0x94));
        temp_v0->unk0 = 2;
        temp_v0->unk8 = 0xB4;
        temp_v0->unk4 = 1;
        temp_v0->unk3 = 8;
        D_800DC8E0 = 1;
        break;
    case 1:
        if (func_8006AFBC() != 0) {
            temp_v0 = func_8006AE70(1, 0x320140, 0xC007E, (u_char*)(D_800DEAC0 + 0xA2));
            temp_v0->unk0 = 2;
            temp_v0->unk8 = 0xC2;
            D_800DC8E0 = 2;
        }
        break;
    case 2:
        temp_v0 = func_8006AE70(2, 0x420140, 0xC007E, (u_char*)(D_800DEAC0 + 0xAC));
        temp_v0->unk0 = 2;
        temp_v0->unk8 = 0xC2;
        D_800DC8E0 = 3;
        break;
    case 3:
        if (func_8006AFBC() != 0) {
            D_800DC8E0 = 4;
            D_800DED6C = D_800DEAC0 + 0xB6;
        }
        break;
    case 4:
        _saveSlotMenuEntries[D_800DC8E1].unk4 = 1;
        _saveSlotMenuEntries[3 - D_800DC8E1].unk4 = 0;
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            D_800DED68 = 0;
            for (i = 0; i < 3; ++i) {
                _saveSlotMenuEntries[i].unk0 = 2;
                _saveSlotMenuEntries[i].unk8 = 0x140;
            }
            D_800DC8E0 = 6;
        } else if (vs_main_buttonsPressed & PADRright) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            func_8006C778(D_800DC8E1);
            D_800DED68 = 0;
            D_800DC8E0 = 5;
        } else {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                D_800DC8E1 = 3 - D_800DC8E1;
            }
            D_800DED68 = ((((D_800DC8E1 + 1) * 16) + 10) << 16) | 0xB4;
        }
        break;
    case 5:
        temp_v0 = (_saveSlotMenuEntries_t*)func_8006C778(0);
        if (temp_v0 != 0) {
            if ((int)temp_v0 < 0) {
                D_800DC8E0 = 1;
            } else {
                D_800DC8E0 = 7;
            }
        }
        break;
    case 6:
        if (func_8006AFBC() != 0) {
            if (D_800DC8E2 == 0) {
                return -1;
            }
            D_800DC8E0 = 8;
        }
        break;
    case 7:
        if (++D_800DED72 >= 0x1F) {
            return 1;
        }
        break;
    case 8:
        if (++D_800DED72 < 0x1F) {
            break;
        }
        return -1;
    }
    return 0;
}

int func_8006CE6C(int arg0)
{
    _saveSlotMenuEntries_t* temp_v0;
    int i;

    if (arg0 != 0) {
        D_800DC8E9 = 1;
        D_800DC8E8 = 0;
        return 0;
    }

    switch (D_800DC8E8) {
    case 0:
    case 1:
        temp_v0 = func_8006AE70(D_800DC8E8 + 3,
            (((D_800DC8E8 * 0x10) + 0x12) << 0x10) | 0xFF82, 0xC007E,
            (u_char*)&D_800DEAC0[(&D_800DEAC0[D_800DC8E8])[0x24]]);
        temp_v0->unk0 = 4;
        temp_v0->unk8 = 0;
        ++D_800DC8E8;
        break;
    case 2:
        D_800DC8E8 += func_8006AFBC();
        break;
    case 3:
        _saveSlotMenuEntries[D_800DC8E9 + 3].unk4 = 1;
        _saveSlotMenuEntries[4 - D_800DC8E9].unk4 = 0;
        if (vs_main_buttonsPressed & (PADRdown | PADRright)) {
            D_800DED68 = 0;
            for (i = 3; i < 5; ++i) {
                _saveSlotMenuEntries[i].unk0 = 4;
                _saveSlotMenuEntries[i].unk8 = -0x7E;
            }
            if (vs_main_buttonsPressed & PADRright) {
                if ((&D_800DC8E8)[1] == 0) {
                    vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
                    return 1;
                }
            }
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            return -1;
        }
        if (vs_main_buttonRepeat & 0x5000) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
            D_800DC8E9 = 1 - D_800DC8E9;
        }
        D_800DED68 = ((D_800DC8E9 * 0x10) + 0xA) << 0x10;
        break;
    }
    return 0;
}

int func_8006D084(int arg0)
{
    if (arg0 != 0) {
        D_800DC8F1 = 1;
        D_800DED6C = D_800DEAC0 + 0x2D8;
        func_8006CE6C(1);
        D_800DC8F0 = 0;
        return 0;
    }
    switch (D_800DC8F0) {
    case 0:
        D_800DC8EC = func_8006CE6C(0);
        if (D_800DC8EC != 0) {
            D_800DC8F0 = 1;
        }
        return 0;
    case 1:
        if (func_8006AFBC() != 0) {
            return D_800DC8EC;
        }
        return 0;
    default:
        return 0;
    }
}

int func_8006D140(int port)
{
    int temp_v0;
    int temp_s0;

    if (port != 0) {
        _memcardStatePort = port;
        D_800DED6C = D_800DEAC0 + 0x254;
        func_8006CE6C(1);
        D_800DC8F2 = 0;
        return 0;
    }

    temp_s0 = D_800DC8F2;

    switch (temp_s0) {
    case 0:
        temp_v0 = func_8006CE6C(0);

        if (temp_v0 != 0) {
            if (temp_v0 < 0) {
                D_800DED6C = D_800DEAC0 + 0x2AE;
                return -1;
            }

            D_800DC8F2 = 1;
        }
        return 0;
    case 1:
        if (func_8006AFBC() != 0) {
            _memCardHandler((int)_memcardStatePort);
            D_800DC8F2 = 2;
        }
        return 0;
    case 2:
        temp_v0 = _memCardHandler(0);

        if (temp_v0 != 0) {
            if (temp_v0 == 3) {
                D_800DC8F2 = (u_char)temp_v0;
                D_800DED6C = D_800DEAC0 + 0x274;
            } else {
                if (temp_v0 == temp_s0) {
                    D_800DED6C = D_800DEAC0 + 0xE3;
                } else {
                    D_800DED6C = D_800DEAC0 + 0x1DE;
                }
                return -1;
            }
        }
        return 0;
    case 3:
        if (_card_format((_memcardStatePort - 1) * 0x10) == 0) {
            D_800DED6C = D_800DEAC0 + 0x2A0;
            return -1;
        }
        return 1;
    default:
        return 0;
    }
}

int func_8006D2F8(int arg0)
{
    _saveSlotMenuEntries_t* temp_v0_2;
    int temp_s0;
    int saveId;
    int var_a1;
    int i;

    if (arg0 != 0) {
        D_800DC91D = arg0;
        D_800DC91F = _getCurrentGameSave();
        if (D_800DC91F) {
            --D_800DC91F;
        }
        D_800DC91E = 0;
        if (D_800DC91F == 4) {
            D_800DC91E = 2;
            D_800DC91F = 2;
        } else if (D_800DC91F != 0) {
            D_800DC91E = D_800DC91F - 1;
            D_800DC91F = 1;
        }
        D_800DC918 = -1;
        D_800DC920 = 0;
        D_800DC91C = 0;
        return 0;
    }
    switch (D_800DC91C) {
    case 0:
        for (i = 0; i < 5; ++i) {
            temp_v0_2
                = func_8006AE70(i + 5, (i * 0x280000 + 0x480000) | 0x40, 0x200100, 0);
            temp_v0_2->slotId = i;
            temp_v0_2->slotUnused = _saveFileInfo[i].slotState == slotStateUnused;
            temp_v0_2->unk6 = _saveFileInfo[i].unk1C;
        }
        D_800DC91C = 1;
        /* fallthrough */
    case 1:
        D_800DED6C = D_800DEAC0 + 0x13B;
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, 6);
            D_800DED68 = 0;
            D_800DC91C = 8;
        } else {
            var_a1 = 0x104;
            for (i = 0; i < 5; ++i) {
                _saveSlotMenuEntries[i + 5].unkE = (((i - D_800DC91E) * 0x28) + 0x48);
                _saveSlotMenuEntries[i + 5].unk4 = 0;
            }
            temp_s0 = D_800DC91F + D_800DC91E;
            if (vs_main_buttonsPressed & PADRright) {
                if (_saveFileInfo[temp_s0].slotState != slotStateUnused) {
                    vs_main_playSfxDefault(0x7E, 5);
                    _saveSlotMenuEntries[temp_s0 + 5].unk4 = 1;
                    D_800DED68 = 0;
                    func_8006B288(D_800DC91D + 0x70);
                    D_800DC91C = 2;
                    break;
                } else {
                    vs_main_playSfxDefault(0x7E, VS_SFX_INVALID);
                }
            }
            if (vs_main_buttonRepeat & PADLup) {
                if (D_800DC91F == 0) {
                    if (D_800DC91E != 0) {
                        --D_800DC91E;
                    }
                } else {
                    --D_800DC91F;
                }
            }
            if (vs_main_buttonRepeat & PADLdown) {
                if (D_800DC91F == 2) {
                    if (D_800DC91E < 2) {
                        ++D_800DC91E;
                    }
                } else {
                    ++D_800DC91F;
                }
            }
            if (temp_s0 != (D_800DC91F + D_800DC91E)) {
                vs_main_playSfxDefault(0x7E, 4);
            }
            D_800DED68 = (((D_800DC91F * 0x28) + 0x3E) << 0x10) | 0x18;
            _saveSlotMenuEntries[temp_s0 + 5].unk4 = 1;
        }
        break;
    case 2:
        temp_s0 = func_8006B288(0);
        if (temp_s0 != 0) {
            if (D_800DED6C == (D_800DEAC0 + 0x2E2)) {
                func_8006D140(D_800DC91D);
                D_800DC91C = 9;
            } else if (temp_s0 >= 0) {
                temp_s0 = D_800DC91F + D_800DC91E;
                if (_saveFileInfo[temp_s0].slotState == slotStateAvailable) {
                    if (createSaveFile(D_800DC91D, temp_s0 + 1) != 0) {
                        D_800DC91C = 7;
                        D_800DED6C = D_800DEAC0 + 0x102;
                    } else {
                        D_800DC91C = 5;
                    }
                } else {
                    func_8006D084(1);
                    D_800DC91C = 3;
                }
            } else {
                D_800DC91C = 7;
            }
        }
        break;
    case 3:
        temp_s0 = func_8006D084(0);
        if (temp_s0 != 0) {
            if (temp_s0 == 1) {
                func_8006B288(D_800DC91D + 0x70);
                D_800DC91C = 4;
            } else {
                D_800DC91C = 1;
            }
        }
        break;
    case 4:
        temp_s0 = func_8006B288(0);
        if (temp_s0 != 0) {
            if (temp_s0 >= 0) {
                D_800DED73 |= (_getCurrentGameSave() == (D_800DC91F + D_800DC91E + 1));
                D_800DC91C = 5;
            } else {
                D_800DC91C = 7;
            }
        }
        break;
    case 5:
        temp_s0 = D_800DC91F + D_800DC91E;
        D_800DED6C = D_800DEAC0 + 0x17B;
        _rMemcpy((u_char*)&_settingsBackup, (u_char*)&vs_main_settings,
            sizeof(_settingsBackup));
        _rMemcpy(_spmcimg + 0xB800, _spmcimg + 0x5C00, 0x5C00);
        if (D_800DED74 != 0) {
            D_800DED75 = (*(u_int*)&vs_main_settings.timingWeaponArmor >> 4) & 1;
            *(int*)&vs_main_settings |= 0x10;
        }
        func_80069888(temp_s0);
        func_8006A11C((temp_s0 + 1) | ((D_800DC91D - 1) << 0x10));
        D_800DC91C = 6;
        break;
    case 6:
        temp_s0 = func_8006A11C(0);
        D_800DEB14 += 1;
        if (temp_s0 != 0) {
            D_8006169D = 0;
            saveId = D_800DC91F + D_800DC91E;
            if (temp_s0 < 0) {
                if (D_800DED74 != 0) {
                    u_char v = D_800DED75 & 1;
                    *(int*)&vs_main_settings
                        = (*(int*)&vs_main_settings & ~0x10) | (v * 0x10);
                }
                memset(&_saveFileInfo[saveId], 0, sizeof(_saveFileInfo_t));
                _saveFileInfo[saveId].slotState = slotStateTemp;
                _saveSlotMenuEntries[saveId + 5].unk6 = 0;
                _rMemcpy(_spmcimg + 0x5C00, _spmcimg + 0xB800, 0x5C00);
                D_800DEB14 = 0;
                _rMemcpy((u_char*)&vs_main_settings, (u_char*)&_settingsBackup,
                    sizeof(vs_main_settings));
                D_800DED6C = D_800DEAC0 + 0x102;
            } else {
                D_800DED73 = 0;
                D_800DEB14 = -0x10;
                _rMemcpy((u_char*)&_saveFileInfo[saveId],
                    _spmcimg + sizeof(_saveFileInfo_t) * 3, sizeof(_saveFileInfo_t));
                _decode(_saveFileInfo[saveId].key,
                    (u_char*)&_saveFileInfo[saveId].slotState,
                    sizeof(_saveFileInfo_t) - sizeof(int));
                _saveSlotMenuEntries[saveId + 5].unk6 = _saveFileInfo[saveId].unk1C;
                vs_main_playSfxDefault(0x7E, 8);
                D_800DC918 = 1;
                D_800DED6C = D_800DEAC0 + 0x1AC;
            }
            D_800DC91C = 7;
        }
        break;
    case 7:
        if (D_800DC918 == 1) {
            ++D_800DC920;
        }
        if ((u_char)vs_main_buttonsPressed == 0) {
            if (D_800DC920 != 0x96) {
                break;
            }
        }
        vs_main_playSfxDefault(0x7E, 6);
        D_800DC91C = 8;
        break;
    case 8:
        if (D_800DEB14 == 0) {
            for (i = 5; i < 10; ++i) {
                func_8006AF78(i);
            }
            return D_800DC918;
        }
        break;
    case 9:
        temp_s0 = func_8006D140(0);
        if (temp_s0 != 0) {
            if (temp_s0 < 0) {
                D_800DC91C = 10;
            } else if (createSaveFile(D_800DC91D, D_800DC91E + D_800DC91F + 1) != 0) {
                D_800DC91C = 7;
                D_800DED6C = D_800DEAC0 + 0x102;
            } else {
                D_800DC91C = 5;
            }
        }
        break;
    case 10:
        if ((u_char)vs_main_buttonsPressed != 0) {
            vs_main_playSfxDefault(0x7E, 6);
            for (i = 5; i < 10; ++i) {
                func_8006AF78(i);
            }
            return -1;
        }
        break;
    }
    return 0;
}

// https://decomp.me/scratch/QD0zT
int func_8006DC14(int);
INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006DC14);

int func_8006E00C(int arg0)
{
    _saveSlotMenuEntries_t* temp_v0;
    int temp_v0_2;
    int var_a0;

    if (arg0 != 0) {
        D_800DC924 = 1;
        D_800DED74 = 0;
        D_800DED73 = 0;
        _isSaving = 1;
        D_800DC923 = (arg0 - 1) * 3;
        temp_v0 = func_8006AE70(0, 0x220140, 0xC008C, (u_char*)(D_800DEAC0 + 0x89));
        temp_v0->unk0 = 2;
        temp_v0->unk8 = 180;
        temp_v0->unk3 = 8;
        temp_v0->unk4 = 1;
        D_800DED6C = 0;
        return 0;
    }

    switch (D_800DC923) {
    case 0:
        if (*(int*)&vs_main_settings & 0x10) {
            memset(_spmcimg + 0x79E0, 0, 0x3C00);
            D_800DC923 = 3;
        } else if (func_8006AFBC() != 0) {
            if (vs_main_settings.slotState != slotStateUnused) {
                func_8006B138(1);
                D_800DC923 = 1;
            } else {
                D_800DC923 = 3;
            }
        }
        break;
    case 1:
        temp_v0_2 = func_8006B138(0);
        if (temp_v0_2 == 0) {
            break;
        }
        if (temp_v0_2 < 0) {
            D_800DED6C = D_800DEAC0 + (temp_v0_2 == -2 ? 0xE3 : 0xF7);
            D_800DC923 = 9;
        } else {
            _loadSaveData((temp_v0_2 & 7) | ((temp_v0_2 & 16) << 0xC));
            D_800DC923 = 2;
        }
        break;
    case 2:
        var_a0 = _loadSaveData(0);
        if (var_a0 != 0) {
            if ((var_a0 <= 0) || (func_800696D0(0) != 0)) {
                D_800DC923 = 9;
                D_800DED6C = D_800DEAC0 + 247;
            } else {
                D_800DC923 = 3;
            }
        }
        break;
    case 3:
        if (func_8006AFBC() != 0) {
            temp_v0 = func_8006AE70(1, 0x320140, 0xC007E, (u_char*)(D_800DEAC0 + 0xA2));
            temp_v0->unk0 = 2;
            temp_v0->unk8 = 194;
            D_800DC923 = 4;
        }
        break;
    case 4:
        temp_v0 = func_8006AE70(2, 0x420140, 0xC007E, (u_char*)(D_800DEAC0 + 0xAC));
        temp_v0->unk0 = 2;
        temp_v0->unk8 = 194;
        D_800DC923 = 5;
        break;
    case 5:
        if (func_8006AFBC() != 0) {
            D_800DC923 = 6;
            D_800DED6C = D_800DEAC0 + 0xB6;
        }
        break;
    case 6:
        _saveSlotMenuEntries[D_800DC924].unk4 = 1;
        _saveSlotMenuEntries[3 - D_800DC924].unk4 = 0;
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENULEAVE);
            var_a0 = D_800DED73;
            D_800DED68 = 0;
            if (var_a0 < 3) {
                do {
                    _saveSlotMenuEntries[var_a0].unk0 = 2;
                    _saveSlotMenuEntries[var_a0].unk8 = 0x140;
                    ++var_a0;
                } while (var_a0 < 3);
            }
            if (D_800DED73 != 0) {
                D_800DED6C = D_800DEAC0 + 0x311;
                func_8006CE6C(1);
                D_800DC923 = 11;
            } else {
                D_800DC923 = 8;
            }
        } else if (vs_main_buttonsPressed & PADRright) {
            vs_main_playSfxDefault(0x7E, VS_SFX_MENUSELECT);
            func_8006DC14(D_800DC924);
            D_800DED68 = 0;
            D_800DC923 = 7;
        } else {
            if (vs_main_buttonRepeat & (PADLup | PADLdown)) {
                vs_main_playSfxDefault(0x7E, VS_SFX_MENUCHANGE);
                D_800DC924 = 3 - D_800DC924;
            }
            D_800DED68 = ((((D_800DC924 + 1) * 16) + 10) << 16) | 0xB4;
        }
        break;
    case 7:
        var_a0 = func_8006DC14(0);
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
        if (func_8006AFBC() != 0) {
            return -1;
        }
        break;
    case 9:
        if ((u_char)vs_main_buttonsPressed != 0) {
            D_800DED6C = D_800DEAC0 + 0x234;
            func_8006CE6C(1);
            D_800DC923 = 10;
        }
        break;
    case 10:
    case 11:
        var_a0 = func_8006CE6C(0);
        if (var_a0 != 0) {
            if (D_800DC923 == 11) {
                if (var_a0 > 0) {
                    *(int*)&vs_main_settings = *(int*)&vs_main_settings | 0x10;
                }
                var_a0 = -var_a0;
            }
            if (var_a0 < 0) {
                _saveSlotMenuEntries->unk0 = 2;
                _saveSlotMenuEntries->unk8 = 0x140;
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
                func_8006CABC(2);
                _loadScreenMemcardState = 2;
            }
            break;
        case 2:
            temp_v0 = func_8006CABC(0);
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
        _memCardHandler(i);
        do {
            memCardState = _memCardHandler(0) & 3;
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
    _saveSlotMenuEntries_t* temp_v0;
    int i;

    if (arg0 != 0) {
        D_800DC932 = 1;
        D_800DC931 = 0;
        return 0;
    }

    switch (D_800DC931) {
    case 0:
    case 1:
        temp_v0 = func_8006AE70(D_800DC931 + 1,
            (((D_800DC931 * 0x10) + 0x92) << 0x10) | 0x140, 0xC007E,
            (u_char*)&D_800DEAC0[(D_800DEAC0 + D_800DC931)[0x1A]]);
        temp_v0->unk0 = 2;
        temp_v0->unk8 = 0xC2;
        ++D_800DC931;
        break;
    case 2:
        D_800DC931 += func_8006AFBC();
        break;
    case 3:
        _saveSlotMenuEntries[D_800DC932].unk4 = 1;
        _saveSlotMenuEntries[3 - D_800DC932].unk4 = 0;
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
            D_800DED68 = 0;
            for (i = 1; i < 3; ++i) {
                _saveSlotMenuEntries[i].unk0 = 2;
                _saveSlotMenuEntries[i].unk8 = 0x140;
            }
            break;
        }
        if (vs_main_buttonRepeat & 0x5000) {
            _playMenuChangeSfx();
            D_800DC932 = 3 - D_800DC932;
        }
        D_800DED68 = ((((D_800DC932 + 7) * 16) + 10) << 16) | 0xB4;
        break;
    case 4:
        if (func_8006AFBC() != 0) {
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
                    D_800DED6C = D_800DEAC0 + 0x335;
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
