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
    void* unk0[2];
    int unk8;
    void* unkC[2];
    int unk14;
    RECT unk18[2];
    u_int frameBuf;
    RECT unk2C;
    int unk34;
} D_800DEDA8_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    u_char unk4;
    u_char unk5;
    u_char unk6;
    u_char unk7;
    short unk8;
    short unkA;
    short unkC[2];
    int unk10;
    u_char unk14[32];
} D_800DEB18_t;

typedef struct {
    int unk0[10];
    int unk28;
} D_8005FEA0_t;

void playMovie(DslLOC*);
u_short* func_8006F328(D_800DEDA8_t* arg0);
void func_80071B14();
void func_80071CE0(int arg0);

u_char const saveFilenameTemplate[] = "bu00:BASLUS-01040VAG0";

u_char const* _pMemcardFilenameTemplate = saveFilenameTemplate;
u_int _scrambleSeed = 0x0019660D;
u_short eventSpecs[] = { EvSpIOE, EvSpERROR, EvSpTIMOUT, EvSpNEW };

extern u_char D_80060068[];
extern u_char D_80061598[];
extern char D_8006169D;
extern D_80060020_t D_800619D8;
extern int D_800728C0[];
extern int D_800728E8[];
extern u_char D_80072910[];
extern int D_80072914[];
extern u_char D_80072EF8;
extern int D_80072EFC[];
extern int D_80072F04[];
extern u_long D_80072F0C[];
extern u_long D_8007472C[];
extern int D_80074AAC;
extern int D_80074AB0;
extern u_int D_80074AF4[];
extern u_int D_80076AD4[];
extern u_short _menuItemClut[][16];
extern u_char D_80074C24[];
extern u_char D_80075B24[];
extern u_short D_800AD1A8[];
extern u_long D_800AF368[];
extern u_long D_800BD368[];
extern u_long D_800C2268[];
extern u_long D_800D1268[];
extern u_char _memcardFilename[32];
extern u_char _memcardFilenameAlpha[32];
extern u_char _memCardState;
extern u_char _memCardPort;
extern u_char D_800D9280[];
extern u_char _memCardInitTmeout;
extern u_char _memCardTimeout;
extern u_char _memcardEvType;
extern u_char D_800DC8AD;
extern u_char D_800DC8AE;
extern u_char D_800DC8AF;
extern u_char D_800DC8B0;
extern u_char D_800DC8B1;
extern int _memCardFd;
extern u_char D_800DC8B8;
extern u_char _memcardFileno;
extern u_char _memcardPort;
extern u_char D_800DC8BB;
extern u_char D_800DC8BC;
extern u_char D_800DC8E0;
extern u_char D_800DC8E1;
extern u_char D_800DC8E2;
extern int _saveFileId;
extern u_char D_800DC923;
extern u_char D_800DC924;
extern RECT D_800DC938;
extern u_char D_800DC940;
extern u_char D_800DC941;
extern u_char D_800DEB0C;
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
extern u_char D_800DC8DA;
extern u_char D_800DC8DB;
extern u_char D_800DC8DC;
extern u_char D_800DC8DD;
extern u_char D_800DC8E8;
extern u_char D_800DC8E9;
extern int D_800DC8EC;
extern u_char D_800DC8F0;
extern u_char D_800DC8F1;
extern u_char D_800DC8F2;
extern u_char D_800DC8F8;
extern int D_800DC918;
extern u_char D_800DC91C;
extern u_char D_800DC91D;
extern u_char D_800DC91E;
extern u_char D_800DC91F;
extern u_char D_800DC920;
extern u_char memcardPort;
extern RECT D_800DC928;
extern u_char D_800DC930;
extern u_char D_800DC931;
extern u_char D_800DC932;
extern VS_SPRT D_800DE948[2];
extern long memcardEventDescriptors[8];
extern VS_TILE_TPAGE _titleScreenFade;
extern int D_800DEA88;
extern int D_800DEA8C;
extern u_char* _spmcimg;
extern u_int* _mcData;
extern u_short* D_800DEAC0;
extern struct DIRENTRY* memcardFiles[15];
extern struct DIRENTRY* dirEntBuf;
extern u_int (*D_800DEB08)[0x20];
extern u_short D_800DEB0E;
extern int D_800DEB14;
extern D_800DEB18_t D_800DEB18[10];
extern union {
    VS_SPRT sprt;
    VS_TILE_TPAGE tile_tpage;
    VS_TILE tile;
    VS_POLY_G4_TPAGE polyG4_tpage;
    VS_POLY_G4 polyG4;
    u_long raw[13];
} _primBuf;
extern int D_800DED68;
extern void* D_800DED6C;
extern u_char D_800DED70;
extern u_char D_800DED71;
extern u_char D_800DED72;
extern u_char D_800DED75;
extern u_char D_800DED76;
extern u_int _introMovieDisplayedAt;
extern int _introMoviePlaying;
extern DslLOC introMovieLoc;
extern D_800DEDA8_t D_800DEDA8;
extern int dslMode;
extern void* D_800DEDE0;
extern u_short D_800DEDE8;
extern void* D_800EFDE8;
extern void* D_800EFDEC;
extern void* D_800EFDF0;
extern void* D_800EFDF4;
extern u_char _menuItemState[][8];

#define SWEVENTS 0
#define HWEVENTS 4

#define MAKEXY(x, y) (((y) << 16) | (x))
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

static u_int _scramble(int value)
{
    u_int seed = _scrambleSeed;
    _scrambleSeed = seed * 0x19660D;
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

static void _rMemcpy(u_char* dst, u_char const* src, int count)
{
    do {
        --count;
        dst[count] = src[count];
    } while (count != 0);
}

static u_char* _memcardFilenameFromTemplate(int port, int fileNo)
{
    memset(_memcardFilename, 0, ' ');
    strcpy(_memcardFilename, _pMemcardFilenameTemplate);
    _memcardFilename[2] = port == 0 ? '0' : '1';
    _memcardFilename[20] = fileNo + '0';
    return _memcardFilename;
}

static u_char* _memcardFilenameFromTemplateAlpha(int port, int fileNo)
{
    memset(_memcardFilenameAlpha, 0, ' ');
    strcpy(_memcardFilenameAlpha, _pMemcardFilenameTemplate);
    _memcardFilenameAlpha[2] = port == 0 ? '0' : '1';
    _memcardFilenameAlpha[20] = (fileNo + '@');
    return _memcardFilenameAlpha;
}

static u_int func_80068D54()
{
    u_int i;
    u_int var_a2;
    u_int var_a3;

    var_a2 = 0;
    var_a3 = 0;
    for (i = 0; i < 5; ++i) {
        if (D_800DEB08[i][1] >= 3) {
            if (var_a2 < D_800DEB08[i][2]) {
                var_a2 = D_800DEB08[i][2];
                var_a3 = i;
            }
        }
    }
    return var_a3;
}

static int func_80068DB4()
{
    int i;
    for (i = 0; i < 5; ++i) {
        if ((D_800DEB08[i][1] >= 3) && (D_800DEB08[i][1] == D_80060020.unk4)
            && (D_800DEB08[i][0] == D_80060020.unk14)
            && ((u_short)D_800DEB08[i][5] == D_80060020.unk18)
            && (D_800DEB08[i][2] == D_80060020.unk1C)) {
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

static int _verifySaveChecksums(u_char blocks[][0x100], int blockCount)
{
    int checksum;
    int i;
    int j;
    u_char* block;

    block = blocks[0];

    for (i = 0; i < blockCount; ++i) {
        checksum = 0;
        if (i != 1) {
            for (j = 0; j < 256; ++j) {
                checksum ^= block[j];
            }
            if (((u_char*)blocks + i)[0x1A4] != checksum) {
                return 1;
            }
        }
        block += 256;
    }

    block = blocks[1];
    checksum = 0;

    for (j = 0; j < 256; ++j) {
        checksum ^= block[j];
    }
    return checksum != 0;
}

void _descramble(u_int seed, u_char* buf, int count)
{
    for (; count != 0; --count) {
        seed *= 0x19660D;
        *buf++ -= seed >> 24;
    }
}

int _readSaveData(int id)
{
    u_char buf[2][256];
    int bytesRead;
    int port;
    int file;
    int i;

    port = id >> 12;
    id &= 7;

    for (i = 0; i < 3; ++i) {
        file = open(_memcardFilenameFromTemplate(port, id), O_RDONLY);
        if (file != -1) {
            bytesRead = read(file, buf, sizeof(buf));
            close(file);
            if (bytesRead == 512) {
                _descramble(*((int*)&buf[1][128]), &buf[1][132], 124);
                if (_verifySaveChecksums(buf, 2) == 0) {
                    _rMemcpy((u_char*)D_800DEB08[id - 1], &buf[1][128], 128);
                    return 0;
                }
            }
        }
    }
    memset(D_800DEB08[id - 1], 0, 128);
    return 1;
}

int memcardSaveIdExists(int id)
{
    int i;

    for (i = 0; i < 15; ++i) {
        u_char* filename = memcardFiles[i]->name;
        if ((filename != NULL) && (_memcardFileNumberFromFilename(filename) != 0)) {
            if (filename[15] == id) {
                return 1;
            }
        }
    }
    return 0;
}

int deleteUnusedSaves(int port)
{
    int i;
    int ret;

    ret = 0;
    for (i = 0; i < 5; ++i) {
        if ((memcardSaveIdExists(i + '1') != 0) && (memcardSaveIdExists(i + 'A') != 0)) {
            if (erase(_memcardFilenameFromTemplateAlpha(port, i + 1)) == 0) {
                return 0x80;
            }
            ret |= 1 << i;
        }
    }
    return ret;
}

int func_800691D4(int port)
{
    int temp_v0;
    int fileNo;
    int i;
    int var_s4;
    struct DIRENTRY* var_s2;
    u_int* var_v1;

    var_s4 = 15;
    for (i = 14; i >= 0; --i) {
        memcardFiles[i] = 0;
    }

    fileNo = (int)firstfile((port == 1) ? ("bu00:*") : ("bu10:*"), dirEntBuf);
    memcardFiles[0] = (void*)fileNo;

    for (i = 1; (i < 15) && fileNo; ++i) {
        fileNo = (int)nextfile(dirEntBuf + i);
        memcardFiles[i] = (void*)fileNo;
    }

    memset(D_800DEB08, 0, 0x280);
    temp_v0 = deleteUnusedSaves((port - 1) * 16);
    if (temp_v0 & 0x80) {
        return 1;
    }
    for (i = 0; i < 15; ++i) {
        var_s2 = memcardFiles[i];
        if (var_s2 != 0) {
            fileNo = _memcardFileNumberFromFilename((char*)var_s2->name);
            if (fileNo != 0) {
                if (fileNo < 0) {
                    fileNo = -fileNo;
                    if ((temp_v0 >> (fileNo - 1)) & 1) {
                        continue;
                    }
                    memset(D_800DEB08[fileNo - 1], 0, 0x80);
                    D_800DEB08[fileNo - 1][1] = 2;
                } else if (_readSaveData(((port - 1) << 16) | fileNo) != 0) {
                    var_s4 += (var_s2->size + 0x1FFF) >> 0xD;
                }
            }
            var_s4 -= (var_s2->size + 0x1FFF) >> 0xD;
        }
    }

    var_v1 = D_800DEB08[0];
    for (; var_s4 >= 3; var_s4 -= 3) {
        for (i = 0; i < 5; ++i) {
            if (D_800DEB08[i][1] == 0) {
                D_800DEB08[i][1] = 1;
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

    fileName = _memcardFilenameFromTemplate((port - 1) * 16, id);
    erase(fileName);
    file = open(fileName, 0x30000 | O_CREAT);
    if (file != -1) {
        close(file);
        return 0;
    }
    return -1;
}

enum _memCardStates {
    _memCardInit = 0,
    _memCardReady = 1,
    _memCardNew = 2,
    _memCardConfirmed = 3,
    _memCardLoadReady = 4,
    _memCardLoaded = 5,
};

enum _memCardEventState {
    _memCardEventIoEnd = 0,
    _memCardEventError = 1,
    _memCardEventTimeout = 2,
    _memCardEventNew = 3,
    _memCardEventNone = 4,
};

int _memCardHandler(int arg0)
{
    int event;

    if (arg0 != 0) {
        _memCardPort = (arg0 - 1) * 16;
        _memCardState = _memCardInit;
        _memCardInitTmeout = 0;
        return 0;
    }
    switch (_memCardState) {
    case _memCardInit:
        if (++_memCardInitTmeout >= 4) {
            return 2;
        }
        _resetMemcardEvents(SWEVENTS);
        if (_card_info(_memCardPort) == 0) {
            break;
        }
        _memCardState = _memCardReady;
        _memCardTimeout = 0;
        _memcardEvType = SWEVENTS;
        // fallthrough
    case _memCardReady:
        switch (_testMemcardEvents(SWEVENTS)) {
        case _memCardEventIoEnd:
            _memCardState = _memCardLoadReady;
            break;
        case _memCardEventError:
        case _memCardEventTimeout:
            _memCardState = _memCardInit;
            break;
        case _memCardEventNew:
            _memCardState = _memCardNew;
            break;
        case _memCardEventNone:
            if (_memCardTimeout++ > 64) {
                _memCardState = _memCardInit;
            }
            break;
        }
        break;
    case _memCardNew:
        _resetMemcardEvents(HWEVENTS);
        if (_card_clear(_memCardPort) == 0) {
            break;
        }
        _memCardState = _memCardConfirmed;
        _memCardTimeout = 0;
        _memcardEvType = HWEVENTS;
        // fallthrough
    case _memCardConfirmed:
        do {
            event = _testMemcardEvents(HWEVENTS);
        } while (event == _memCardEventNone);
        if (event == _memCardEventIoEnd) {
            _memCardState = _memCardLoadReady;
            break;
        }
        if (event < _memCardEventIoEnd)
            break;
        if (event >= _memCardEventNone)
            break;
        _memCardState = _memCardInit;
        break;
    case _memCardLoadReady:
        _resetMemcardEvents(SWEVENTS);
        if (_card_load(_memCardPort) == 0) {
            break;
        }
        _memCardState = _memCardLoaded;
        _memCardTimeout = 0;
        // fallthrough
    case _memCardLoaded:
        event = _testMemcardEvents(SWEVENTS);
        switch (event) {
        case _memCardEventIoEnd:
            return _memcardEvType + 1;
        case _memCardEventError:
        case _memCardEventTimeout:
            _memCardState = _memCardInit;
            break;
        case _memCardEventNew:
            return _memcardEvType + 3;
        case _memCardEventNone:
            if (_memCardTimeout++ > 64) {
                _memCardState = _memCardInit;
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
    u_char* spmcimg;
    void* blocks;
    int* temp_s2;
    int* temp_s4;

    spmcimg = _spmcimg;
    blocks = spmcimg + 0x5C00;
    temp_s4 = blocks;
    temp_s2 = (int*)spmcimg + 0x1760;

    _descramble(*temp_s2, spmcimg + 0x5D84, 0x5A7C);

    blockCount = 92;
    if (arg0 != 0) {
        blockCount = 32;
    }

    if ((_verifySaveChecksums(blocks, blockCount) != 0) || (temp_s2[3] != 0x20000107)) {
        do {
            return 1;
        } while (0);
    }

    if (arg0 == 0) {
        return 0;
    }

    _rMemcpy(D_80061598, spmcimg + 0x5E00, 0x440);
    _rMemcpy(vs_main_skillsLearned, spmcimg + 0x6240, 0x20);
    _rMemcpy(D_8005FFD8, spmcimg + 0x6260, 0x48);
    _rMemcpy(&D_80060020.unk0, spmcimg + 0x62A8, 0x20);
    _rMemcpy(D_80060068, spmcimg + 0x62C8, 0x100);
    _rMemcpy(D_80060168, spmcimg + 0x63C8, 0xF00);
    _rMemcpy(&D_800619D8.unk0, spmcimg + 0x72C8, 0xB0);
    _rMemcpy((u_char*)&D_80061068, spmcimg + 0x7378, 0xC);
    _rMemcpy((u_char*)D_8005FEA0, spmcimg + 0x7384, 0x114);
    D_80060064 = temp_s4[0x626];
    _rMemcpy(D_80061078, spmcimg + 0x749C, 0x520);
    blocks = D_80060040;
    _rMemcpy(D_80060040, spmcimg + 0x79BC, 0x24);
    __builtin_memcpy(&vs_main_gametime, spmcimg + 0x5D90, sizeof(vs_main_gametime));
    func_80042CA0();
    func_800468BC(D_80060020.unkA);
    return 0;
}

void func_80069888(int);
INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_80069888);

int func_80069EA8(int arg0)
{
    int ev;
    int nBytes;
    u_char* filename;
    void* temp_s2;
    int new_var;

    temp_s2 = _spmcimg + 0x5C00;
    if (arg0 != 0) {
        D_800DC8AD = 0;
        D_800DC8B1 = 0;
        D_800DEB0C = 0;
        D_800DC8AE = arg0 >> 0xC;
        D_800DC8B0 = (arg0 >> 8) & 1;
        D_800DC8AF = arg0 & 0xF;
        D_800DEB12 = 0x50;
        D_800DEB10 = 0;
        return 0;
    }

    switch (D_800DC8AD) {
    case 0:
        new_var = 0x140;
        D_800DEB12 += ((D_800DEB14 - D_800DEB10)
                          * ((D_800DEB0C * 0x14) - (D_800DEB12 - new_var)))
            / D_800DEB0E;
        D_800DEB0C = D_800DC8B1;
        D_800DEB0E = 0xC0 - (D_800DC8B0 << 7);
        D_800DEB10 = D_800DEB14;

        memset(temp_s2, 0, 0x5C00);

        if (D_800DC8AF & 8) {
            filename = _memcardFilenameFromTemplateAlpha(D_800DC8AE, D_800DC8AF & 7);
        } else {
            filename = _memcardFilenameFromTemplate(D_800DC8AE, D_800DC8AF);
        }
        _memCardFd = open((char*)filename, O_NOWAIT | O_RDONLY);
        if (_memCardFd == -1) {
            ++D_800DC8B1;
            break;
        }
        _resetMemcardEvents(SWEVENTS);
        nBytes = 0x5C00;
        if (D_800DC8B0 != 0) {
            nBytes = 0x2000;
        }
        if (read(_memCardFd, temp_s2, nBytes) == -1) {
            close(_memCardFd);
            ++D_800DC8B1;
            break;
        }
        D_800DC8AD = 1;
        // fallthrough
    case 1:
        ev = _testMemcardEvents(SWEVENTS);
        if (ev < _memCardEventNone) {
            close(_memCardFd);
            if (ev == _memCardEventIoEnd) {
                return 1;
            }
            D_800DC8AD = 0;
            ++D_800DC8B1;
        }
        break;
    }
    return D_800DC8B1 == 3 ? -1 : 0;
}

INCLUDE_RODATA("build/src/TITLE/TITLE.PRG/nonmatchings/22C", D_8006886C);

int func_8006A11C(int arg0)
{
    int temp_v1_2;
    int temp_s2;
    int temp_s3;

    if (arg0 != 0) {
        D_800DC8BB = 0;
        D_800DC8BC = 0;
        D_800DEB0C = 0;
        _memcardPort = arg0 >> 0xC;
        _memcardFileno = arg0 & 7;
        D_800DEB12 = 0x50;
        D_800DEB10 = 0;
        D_800DC8B8 = memcardSaveIdExists(_memcardFileno + 0x40);
        return 0;
    }
    switch (D_800DC8B8) {
    case 0:
        if (rename((char*)_memcardFilenameFromTemplate(_memcardPort, _memcardFileno),
                (char*)_memcardFilenameFromTemplateAlpha(_memcardPort, _memcardFileno))
            != 0) {
            D_800DC8BB = 0;
            D_800DC8BC = 0;
            D_800DC8B8 = 1;
        } else {
            ++D_800DC8BC;
            D_800DC8BB = D_800DC8BC >> 4;
        }
        break;
    case 1:
        temp_v1_2 = ((D_800DEB14 - D_800DEB10) * (0x140 - D_800DEB12)) / D_800DEB0E;
        D_800DEB10 = D_800DEB14;
        D_800DEB0E = 0x180;
        D_800DEB12 += temp_v1_2;
        _saveFileId
            = open((char*)_memcardFilenameFromTemplateAlpha(_memcardPort, _memcardFileno),
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
        D_800DC8B8 = 2;
        // fallthrough
    case 2: {
        temp_s3 = _testMemcardEvents(SWEVENTS);
        if (temp_s3 < _memCardEventNone) {
            close(_saveFileId);
            if (temp_s3 == _memCardEventIoEnd) {
                D_800DC8B8 = 3;
                temp_s2 = D_800DEB12;
                temp_s3 = D_800DEB10;
                func_80069EA8((_memcardPort << 0xC) | (_memcardFileno + 8));
                D_800DEB12 = temp_s2;
                D_800DEB10 = temp_s3;
            } else {
                ++D_800DC8BB;
                D_800DC8B8 = 1;
            }
        }
        break;
    }
    case 3:
        temp_s3 = func_80069EA8(0);
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
        D_800DC8B8 = 4;
        break;
    case 4:
        if (rename((char*)_memcardFilenameFromTemplateAlpha(_memcardPort, _memcardFileno),
                (char*)_memcardFilenameFromTemplate(_memcardPort, _memcardFileno))
            == 0) {
            ++D_800DC8BC;
            D_800DC8BB = (D_800DC8BC >> 4);
            break;
        }
        return 1;
    }
    return D_800DC8BB == 3 ? -1 : 0;
}

enum diskState {
    diskStateInit = 0,
    diskStateQueueReady = 1,
    diskStateQueueEnqueued = 2,
};

static int _loadMemcardMenu(int arg0)
{
    vs_main_CdFile cdFile;
    int i;
    u_int event;

    if (arg0 != 0) {
        _spmcimg = (u_char*)vs_main_allocHeap(VS_SPMCIMG_BIN_SIZE);
        _mcData = (u_int*)_spmcimg + 0x4500;
        D_800DEAC0 = (u_short*)(_mcData + 0x400);
        D_800DEB08 = (u_int(*)[32])(_mcData + 0x800);
        dirEntBuf = (struct DIRENTRY*)(_mcData + 0x8A0);
        cdFile.lba = VS_SPMCIMG_BIN_LBA;
        cdFile.size = VS_SPMCIMG_BIN_SIZE;
        _mcDataLoad = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(_mcDataLoad, _spmcimg);
        _diskState = 0;
        return 0;
    }

    switch (_diskState) {
    case diskStateInit:
        if (_mcDataLoad->state == vs_main_CdQueueStateLoaded) {
            vs_main_freeCdQueueSlot(_mcDataLoad);
            _drawImage(MAKEXY(800, 256), (u_long*)_spmcimg, MAKEWH(224, 256));
            _diskState = diskStateQueueReady;
        }
        return 0;
    case diskStateQueueReady:
        cdFile.lba = VS_MCDATA_BIN_LBA; // MCMAN.BIN must immediately follow MCDATA.BIN on
                                        // the disk
        cdFile.size = VS_MCDATA_BIN_SIZE + VS_MCMAN_BIN_SIZE;
        _mcDataLoad = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(_mcDataLoad, _mcData);
        _diskState = diskStateQueueEnqueued;
        break;
    case diskStateQueueEnqueued:
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

void func_8006A6E0()
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
    vs_setTag(&_primBuf.sprt, primAddrNull);
    vs_setTpageRaw(&_primBuf.sprt, tpage & 0x9FF);
    vs_setRGB0Raw(&_primBuf.sprt, primSprt, ((0x80 - (tpage >> 16)) * 0x10101));
    _primBuf.sprt.x0y0 = xy;
    _primBuf.sprt.u0v0clut = uvClut;
    _primBuf.sprt.wh = wh;
    DrawPrim(&_primBuf);
}

void func_8006A81C(int arg0, int arg1)
{
    _drawSprt(arg0, D_800728C0[arg1], D_800728E8[arg1], 0xC);
}

void func_8006A860(int arg0, u_int arg1, u_int arg2)
{
    do {
        _drawSprt(arg0, ((arg1 / arg2) * 6) | 0x37F40000, 0xA0006, 0xC);
        arg1 = arg1 % arg2;
        arg2 /= 0xA;
        arg0 += 5;
    } while (arg2 != 0);
}

int countDigits(int val)
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
    u_int temp_s0;
    u_int var_s1;
    u_int var_s4;
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

    var_s4 = ((207 << 16) | (224 << 8)) | 45;
    if (arg1 != 0) {
        var_s4 = ((159 << 16) | (120 << 8)) | 220;
    }

    new_var3 = (var_s4 & 0xFF);
    temp_a1 = 0x40 - var_s1;
    temp_s0 = ((((var_s1 * 0xFF) + (new_var3 * temp_a1)) >> 6)
                  | ((((var_s1 * 0xF0) + (((var_s4 >> 8) & 0xFF) * temp_a1)) >> 6) << 8))
        | ((((2 * (79 * var_s1)) + ((var_s4 >> 16) * temp_a1)) >> 6) << 16);

    DrawSync(0);
    _primBuf.raw[0] = 0x0C000000;
    _primBuf.raw[1] = vs_getTpage(0, 0, clut4Bit, semiTransparencyHalf, ditheringOn);
    _primBuf.raw[2] = vs_getRGB0(primTile, 0, 40, 64);
    new_var = vs_getWH(66, 5);
    new_var2 = (var_s1 + 0x90000);
    _primBuf.raw[3] = arg0++ + 0x80000;
    _primBuf.raw[4] = vs_getWH(66, 5);
    _primBuf.raw[5] = vs_getRGB0Raw(primPolyG4, temp_s0);
    _primBuf.raw[6] = arg0 + 0x90000;
    _primBuf.raw[7] = var_s4;
    _primBuf.raw[8] = arg0 + new_var2;
    _primBuf.raw[9] = temp_s0;
    _primBuf.raw[10] = arg0 + 0xC0000;
    _primBuf.raw[11] = var_s4;
    _primBuf.raw[12] = 0xC0000;
    _primBuf.raw[12] = arg0 + (var_s1 + _primBuf.raw[12]);
    DrawPrim(_primBuf.raw);

    var_s1 = countDigits(arg2);
    temp_s4 = countDigits(arg3);
    func_8006A81C(arg0 - 1, arg1 + 7);
    new_var = var_s1 * 6;
    var_s2 = (arg0 - (new_var - (new_var4 = 0x37))) - (temp_s4 * 5);
    var_s1_2 = D_80072910[var_s1];
    do {
        _drawSprt(var_s2 + 0xFFFF0000, (((arg2 / var_s1_2) << 3) + 0x40) | 0x37F40000,
            0xC0007, 0xC);
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
    int var_s2;
    u_char* new_var __attribute__((unused));
    int var_s4;
    u_int var_s3;
    u_int var_s5;

    var_s3 = arg0 - 0x30;
    new_var = &D_800DED70;

    if (var_s3 < 0x40U) {
        var_s3 = 0x40;
    }

    var_s4 = 0;
    var_s2 = 0xFFE0;

    if (D_800DED70 != 0) {
        var_s2 = 0x7F00FF;
    }

    for (var_s5 = 0; var_s5 < 2; ++var_s5) {
        DrawSync(0);
        vs_setTag(&_primBuf.polyG4_tpage, primAddrNull);
        vs_setRGB0Raw(&_primBuf.polyG4_tpage, primPolyG4SemiTrans, var_s4);
        _primBuf.polyG4_tpage.x0y0 = var_s3 | arg1;
        _primBuf.polyG4_tpage.x1y1 = arg0 | arg1;
        _primBuf.polyG4_tpage.x2y2 = var_s3 | (arg1 + 0x200000);
        vs_setTpage(
            &_primBuf.polyG4_tpage, 0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
        _primBuf.polyG4_tpage.r1g1b1 = var_s2;
        _primBuf.polyG4_tpage.r2g2b2 = var_s4;
        _primBuf.polyG4_tpage.r3g3b3 = var_s2;
        _primBuf.polyG4_tpage.x3y3 = arg0 | (arg1 + 0x200000);
        DrawPrim(&_primBuf.polyG4_tpage);
        var_s3 = arg0;
        arg0 += 0x10;
        var_s4 = var_s2;
        var_s2 = 0;
    }
}

void func_8006ACD8(int arg0, int y)
{
    int yOfst;
    int colour0;
    u_int i;
    int colour1 = 0;

    if (D_800DED70 != 0) {
        colour0 = arg0 + (arg0 << 15);
    } else {
        colour0 = (arg0 - (arg0 >> 3)) + (arg0 << 8);
    }

    DrawSync(0);
    vs_setTag(&_primBuf.tile_tpage, primAddrNull);
    vs_setTpage(&_primBuf.tile_tpage, 0, 0, clut4Bit, semiTransparencyFull, ditheringOn);
    vs_setRGB0Raw(&_primBuf.tile_tpage, primTileSemiTrans, colour0);
    _primBuf.tile_tpage.x0y0 = y | 64;
    _primBuf.tile_tpage.wh = vs_getWH(256, 32);
    DrawPrim(&_primBuf.tile_tpage);

    for (i = 0; i < 2; ++i) {
        DrawSync(0);
        vs_setTag(&_primBuf.polyG4, primAddrNull);
        yOfst = y + vs_getXY(0, -8);
        vs_setRGB0Raw(&_primBuf.polyG4, primPolyG4SemiTrans, colour1);
        _primBuf.polyG4.x0y0 = yOfst | 64;
        _primBuf.polyG4.r1g1b1 = colour1;
        _primBuf.polyG4.x1y1 = yOfst | 320;
        _primBuf.polyG4.r2g2b2 = colour0;
        _primBuf.polyG4.x2y2 = y | 64;
        _primBuf.polyG4.r3g3b3 = colour0;
        _primBuf.polyG4.x3y3 = y | 320;
        DrawPrim(&_primBuf.raw);
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
    memset(D_800DEB18, 0, sizeof(D_800DEB18));
}

D_800DEB18_t* func_8006AE70(int arg0, int arg1, int arg2, u_char* arg3)
{
    D_800DEB18_t* temp_s3;
    int i;
    u_int var_v1;

    temp_s3 = &D_800DEB18[arg0];
    memset(temp_s3, 0, sizeof(*temp_s3));
    temp_s3->unk0 = 1;
    temp_s3->unk1 = 0xFF;
    *(int*)temp_s3->unkC = arg1;
    temp_s3->unk10 = arg2;

    if (arg3 != 0) {
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

void func_8006AF78(int arg0) { memset(&D_800DEB18[arg0], 0, sizeof(D_800DEB18_t)); }

int func_8006AFBC()
{
    int i;

    for (i = 0; i < 10 && D_800DEB18[i].unk0 < 2; ++i)
        ;
    return (i ^ 0xA) == 0;
}

int func_8006AFF8(u_int arg0, int x, int y, int arg3)
{
    if ((arg0 >> 8) == 14) {
        return x + (u_char)arg0;
    }
    if (arg0 != 0x8F) {
        DrawSync(0);
        vs_setTag(&_primBuf.sprt, primAddrNull);
        vs_setTpage(&_primBuf.sprt, 832, 0, clut4Bit, semiTransparencyFull, ditheringOff);
        vs_setRGB0(&_primBuf.sprt, primSprtSemtTrans, 128, 128, 128);
        _primBuf.sprt.x0y0 = vs_getYX(y, x);
        _primBuf.sprt.wh = vs_getWH(12, 12);
        _primBuf.sprt.u0v0clut
            = vs_getUV0Clut((arg0 % 21) * 12, (arg0 / 21) * 12, arg3 * 16 + 896, 222);
        DrawPrim(&_primBuf.raw);
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
                if (func_800691D4(temp_s0) == 0) {
                    temp_v0 = func_80068DB4();
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

void func_8006B4EC(int arg0, u_int arg1)
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
    func_8006B490(a0, a1, arg0);
}

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006B5A0);

void func_8006BC78(u_char);
INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006BC78);

void func_8006C114()
{
    _drawSprt(0x100, 0x38F00000, 0xB00040, 0x9C);
    _drawSprt(0, 0x38F00000, 0xB00100, 0x9A);
}

int func_8006C15C(int arg0)
{
    D_800DEB18_t* temp_v0_2;
    int temp_s0;
    int i;

    if (arg0 != 0) {
        D_800DC8D9 = arg0;
        D_800DC8DB = func_80068D54();
        D_800DC8DA = 0;
        if (D_800DC8DB == 4) {
            D_800DC8DA = 2;
            D_800DC8DB = 2;
        } else if (D_800DC8DB != 0) {
            D_800DC8DA = D_800DC8DB - 1;
            D_800DC8DB = 1;
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
            temp_v0_2->unk1 = i;
            temp_v0_2->unk5 = D_800DEB08[i][1] < 3;
            temp_v0_2->unk6 = D_800DEB08[i][7];
        }
        D_800DC8D8 = 1;
        D_800DED6C = D_800DEAC0 + 0x13B;
        // fallthrough
    case 1:
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, 6);
            for (i = 5; i < 10; ++i) {
                func_8006AF78(i);
            }
            D_800DED68 = 0;
            return -1;
        }
        for (i = 0; i < 5; ++i) {
            D_800DEB18[i + 5].unkC[1] = (((i - D_800DC8DA) * 0x28) + 0x48);
            D_800DEB18[i + 5].unk4 = 0;
        }
        temp_s0 = D_800DC8DB + D_800DC8DA;
        if (vs_main_buttonsPressed & PADRright) {
            if (D_800DEB08[temp_s0][1] >= 3) {
                vs_main_playSfxDefault(0x7E, 5);
                D_800DEB18[temp_s0 + 5].unk4 = 1;
                D_800DED68 = 0;
                func_8006B288(D_800DC8D9 + 0x70);
                D_800DC8D8 = 2;
                break;
            }
            vs_main_playSfxDefault(0x7E, 7);
        }
        if (vs_main_buttonRepeat & 0x1000) {
            if (D_800DC8DB == 0) {
                if (D_800DC8DA != 0) {
                    --D_800DC8DA;
                }
            } else {
                --D_800DC8DB;
            }
        }
        if (vs_main_buttonRepeat & 0x4000) {
            if (D_800DC8DB == 2) {
                if (D_800DC8DA < 2) {
                    ++D_800DC8DA;
                }
            } else {
                ++D_800DC8DB;
            }
        }
        if (temp_s0 != (D_800DC8DB + D_800DC8DA)) {
            vs_main_playSfxDefault(0x7E, 4);
        }
        D_800DED68 = (((D_800DC8DB * 0x28) + 0x3E) << 0x10) | 0x18;
        D_800DEB18[temp_s0 + 5].unk4 = 1;
        break;
    case 2:
        temp_s0 = func_8006B288(0);
        if (temp_s0 != 0) {
            if (temp_s0 >= 0) {
                int new_var;
                func_80069EA8(((D_800DC8DB + D_800DC8DA) + 1)
                    | (new_var = ((D_800DC8D9 - 1) << 0x10) | 0x100));
                D_800DC8D8 = 3;
                D_800DED6C = D_800DEAC0 + 0x193;
            } else {
                D_800DC8D8 = 4;
            }
        }
        break;
    case 3:
        temp_s0 = func_80069EA8(0);
        ++D_800DEB14;
        if (temp_s0 != 0) {
            D_800DEB14 = 0;
            do {
                D_800DC8DC = 0;
                if (temp_s0 < 0) {
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
                vs_main_playSfxDefault(0x7E, 6);
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
    D_800DEB18_t* temp_v0;
    int i;

    if (arg0 != 0) {
        D_800DC8E2 = arg0 - 1;
        D_800DC8E1 = 1;
        D_800DED70 = 0;
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
        D_800DEB18[D_800DC8E1].unk4 = 1;
        D_800DEB18[3 - D_800DC8E1].unk4 = 0;
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, 6);
            D_800DED68 = 0;
            for (i = 0; i < 3; ++i) {
                D_800DEB18[i].unk0 = 2;
                D_800DEB18[i].unk8 = 0x140;
            }
            D_800DC8E0 = 6;
        } else if (vs_main_buttonsPressed & PADRright) {
            vs_main_playSfxDefault(0x7E, 5);
            func_8006C778(D_800DC8E1);
            D_800DED68 = 0;
            D_800DC8E0 = 5;
        } else {
            if (vs_main_buttonRepeat & 0x5000) {
                vs_main_playSfxDefault(0x7E, 4);
                D_800DC8E1 = 3 - D_800DC8E1;
            }
            D_800DED68 = ((((D_800DC8E1 + 1) * 16) + 10) << 16) | 0xB4;
        }
        break;
    case 5:
        temp_v0 = (D_800DEB18_t*)func_8006C778(0);
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
    D_800DEB18_t* temp_v0;
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
        D_800DEB18[D_800DC8E9 + 3].unk4 = 1;
        D_800DEB18[4 - D_800DC8E9].unk4 = 0;
        if (vs_main_buttonsPressed & (PADRdown | PADRright)) {
            D_800DED68 = 0;
            for (i = 3; i < 5; ++i) {
                D_800DEB18[i].unk0 = 4;
                D_800DEB18[i].unk8 = -0x7E;
            }
            if (vs_main_buttonsPressed & PADRright) {
                if ((&D_800DC8E8)[1] == 0) {
                    vs_main_playSfxDefault(0x7E, 5);
                    return 1;
                }
            }
            vs_main_playSfxDefault(0x7E, 6);
            return -1;
        }
        if (vs_main_buttonRepeat & 0x5000) {
            vs_main_playSfxDefault(0x7E, 4);
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
        memcardPort = port;
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
            _memCardHandler((int)memcardPort);
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
        if (_card_format((memcardPort - 1) * 0x10) == 0) {
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
    D_800DEB18_t* temp_v0_2;
    int temp_s0;
    int temp_s2;
    int var_a1;
    int i;

    if (arg0 != 0) {
        D_800DC91D = arg0;
        D_800DC91F = func_80068DB4();
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
            temp_v0_2->unk1 = i;
            temp_v0_2->unk5 = D_800DEB08[i][1] == 0;
            temp_v0_2->unk6 = D_800DEB08[i][7];
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
                D_800DEB18[i + 5].unkC[1] = (((i - D_800DC91E) * 0x28) + 0x48);
                D_800DEB18[i + 5].unk4 = 0;
            }
            temp_s0 = D_800DC91F + D_800DC91E;
            if (vs_main_buttonsPressed & PADRright) {
                if (D_800DEB08[temp_s0][1] != 0) {
                    vs_main_playSfxDefault(0x7E, 5);
                    D_800DEB18[temp_s0 + 5].unk4 = 1;
                    D_800DED68 = 0;
                    func_8006B288(D_800DC91D + 0x70);
                    D_800DC91C = 2;
                    break;
                } else {
                    vs_main_playSfxDefault(0x7E, 7);
                }
            }
            if (vs_main_buttonRepeat & 0x1000) {
                if (D_800DC91F == 0) {
                    if (D_800DC91E != 0) {
                        --D_800DC91E;
                    }
                } else {
                    --D_800DC91F;
                }
            }
            if (vs_main_buttonRepeat & 0x4000) {
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
            D_800DEB18[temp_s0 + 5].unk4 = 1;
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
                if (D_800DEB08[temp_s0][1] == 1) {
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
                D_800DED73 |= (func_80068DB4() == (D_800DC91F + D_800DC91E + 1));
                D_800DC91C = 5;
            } else {
                D_800DC91C = 7;
            }
        }
        break;
    case 5:
        temp_s0 = D_800DC91F + D_800DC91E;
        D_800DED6C = D_800DEAC0 + 0x17B;
        _rMemcpy(&D_800DC8F8, &D_80060020.unk0, 0x20);
        _rMemcpy(_spmcimg + 0xB800, _spmcimg + 0x5C00, 0x5C00);
        if (D_800DED74 != 0) {
            D_800DED75 = (*(u_int*)&D_80060020 >> 4) & 1;
            *(int*)&D_80060020 |= 0x10;
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
            temp_s2 = D_800DC91F + D_800DC91E;
            if (temp_s0 < 0) {
                if (D_800DED74 != 0) {
                    u_char v = D_800DED75 & 1;
                    *(int*)&D_80060020 = (*(int*)&D_80060020 & ~0x10) | (v * 0x10);
                }
                memset(D_800DEB08[temp_s2], 0, 0x80);
                D_800DEB08[temp_s2][1] = 2;
                D_800DEB18[temp_s2 + 5].unk6 = 0;
                _rMemcpy(_spmcimg + 0x5C00, _spmcimg + 0xB800, 0x5C00);
                D_800DEB14 = 0;
                _rMemcpy(&D_80060020.unk0, &D_800DC8F8, 0x20);
                D_800DED6C = D_800DEAC0 + 0x102;
            } else {
                D_800DED73 = 0;
                D_800DEB14 = -0x10;
                _rMemcpy((u_char*)D_800DEB08[temp_s2], _spmcimg + 0x180, 0x80);
                _descramble(
                    D_800DEB08[temp_s2][0], (u_char*)&D_800DEB08[temp_s2][1], 0x7C);
                D_800DEB18[temp_s2 + 5].unk6 = D_800DEB08[temp_s2][7];
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
    D_800DEB18_t* temp_v0;
    int temp_v0_2;
    int var_a0;

    if (arg0 != 0) {
        D_800DC924 = 1;
        D_800DED74 = 0;
        D_800DED73 = 0;
        D_800DED70 = 1;
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
        if (*(int*)&D_80060020 & 0x10) {
            memset(_spmcimg + 0x79E0, 0, 0x3C00);
            D_800DC923 = 3;
        } else if (func_8006AFBC() != 0) {
            if (D_80060020.unk4 != 0) {
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
            func_80069EA8((temp_v0_2 & 7) | ((temp_v0_2 & 0x10) << 0xC));
            D_800DC923 = 2;
        }
        break;
    case 2:
        var_a0 = func_80069EA8(0);
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
        D_800DEB18[D_800DC924].unk4 = 1;
        D_800DEB18[3 - D_800DC924].unk4 = 0;
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, 6);
            var_a0 = D_800DED73;
            D_800DED68 = 0;
            if (var_a0 < 3) {
                do {
                    D_800DEB18[var_a0].unk0 = 2;
                    D_800DEB18[var_a0].unk8 = 0x140;
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
            vs_main_playSfxDefault(0x7E, 5);
            func_8006DC14(D_800DC924);
            D_800DED68 = 0;
            D_800DC923 = 7;
        } else {
            if (vs_main_buttonRepeat & 0x5000) {
                vs_main_playSfxDefault(0x7E, 4);
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
                    *(int*)&D_80060020 = *(int*)&D_80060020 | 0x10;
                }
                var_a0 = -var_a0;
            }
            if (var_a0 < 0) {
                D_800DEB18->unk0 = 2;
                D_800DEB18->unk8 = 0x140;
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

void func_8006E5D0()
{
    DISPENV disp;
    DRAWENV draw;
    RECT rect;

    D_800DED76 = 0;
    SetDefDispEnv(&disp, 0x140, 0, 0x140, 0xF0);
    SetDefDrawEnv(&draw, 0, 0, 0x140, 0xF0);
    disp.screen.y = 8;
    disp.screen.h = 0xE0;
    PutDispEnv(&disp);
    PutDrawEnv(&draw);
    rect.x = 0;
    rect.y = 0;
    rect.w = 0x280;
    rect.h = 0xF0;
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    SetDispMask(1);
}

void func_8006E68C()
{
    DISPENV disp;
    DRAWENV draw;
    int temp_s0;

    D_800DED76 = (1 - D_800DED76);
    temp_s0 = (D_800DED76 & 0xFF) * 0x140;
    SetDefDispEnv(&disp, 0x140 - temp_s0, 0, 0x140, 0xF0);
    SetDefDrawEnv(&draw, temp_s0, 0, 0x140, 0xF0);
    disp.screen.y = 8;
    disp.screen.h = 0xE0;
    PutDispEnv(&disp);
    PutDrawEnv(&draw);
}

int func_8006E738()
{
    int temp_v0;

    _drawImage(MAKEXY(768, 0), D_800C2268, MAKEWH(64, 224));
    _drawImage(MAKEXY(448, 256), D_800C2268 + 0x1C00, MAKEWH(64, 256));
    _drawImage(MAKEXY(832, 0), D_800AF368, MAKEWH(64, 224));
    _drawImage(MAKEXY(896, 0), D_800AF368 + 0x1C00, MAKEWH(64, 224));
    _drawImage(MAKEXY(960, 66), D_800BD368, MAKEWH(64, 158));
    _drawImage(MAKEXY(768, 227), D_800D1268, MAKEWH(256, 1));
    setRECT(&D_800DC928, 640, 256, 32, 240);
    ClearImage(&D_800DC928, 0, 0, 0);
    DrawSync(0);
    setRECT(&D_800DC928, 768, 256, 32, 240);
    ClearImage(&D_800DC928, 0U, 0U, 0U);
    _drawImage(MAKEXY(672, 256), D_800D1268 + 0x80, MAKEWH(96, 240));
    func_8006E5D0();
    D_800DC930 = 0;

    while (1) {
        vs_main_gametimeUpdate(2);
        func_8006E68C();
        vs_main_processPadState();
        switch (D_800DC930) {
        case 0:
            if (D_800DC930 == 0) {
                _loadMemcardMenu(1);
                D_800DC930 = 1;
            }
            break;
        case 1:
            if (_loadMemcardMenu(0) != 0) {
                func_8006AE10();
                func_8006CABC(2);
                D_800DC930 = 2;
            }
            break;
        case 2:
            temp_v0 = func_8006CABC(0);
            if (temp_v0 != 0) {
                func_8006A6E0();
                SetDispMask(0);
                return temp_v0;
            }
            func_8006C114();
            func_8006BC78(D_800DED76);
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
    func_8006A6E0();
    return ret;
}

int func_8006EA70(int arg0)
{
    D_800DEB18_t* temp_v0;
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
        D_800DEB18[D_800DC932].unk4 = 1;
        D_800DEB18[3 - D_800DC932].unk4 = 0;
        if (vs_main_buttonsPressed & PADRdown) {
            vs_main_playSfxDefault(0x7E, 7);
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
                D_800DEB18[i].unk0 = 2;
                D_800DEB18[i].unk8 = 0x140;
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

void func_8006ECF4()
{
    _drawSprt(vs_getXY(256, 0), 0, vs_getWH(64, 224),
        getTPage(direct16Bit, semiTransparencySubtract, (1 - D_800DED76) * 320 + 256, 0));
    _drawSprt(0, 0, vs_getWH(256, 224),
        getTPage(direct16Bit, semiTransparencySubtract, (1 - D_800DED76) * 320, 0));
    DrawSync(0);
    vs_setTag(&_primBuf.tile, primAddrNull);
    vs_setRGB0(&_primBuf.tile, primTileSemiTrans, 8, 8, 8);
    _primBuf.tile.x0y0 = 0;
    _primBuf.tile.wh = vs_getWH(320, 224);
    DrawPrim(&_primBuf.tile);
}

void _displaySaveScreen()
{
    int temp_v0;

    _drawImage(MAKEXY(768, 0), D_800C2268, MAKEWH(64, 224));
    _drawImage(MAKEXY(448, 256), D_800C2268 + 0x1C00, MAKEWH(64, 256));
    _drawImage(MAKEXY(832, 0), D_800AF368, MAKEWH(64, 224));
    _drawImage(MAKEXY(896, 0), D_800AF368 + 0x1C00, MAKEWH(64, 224));
    _drawImage(MAKEXY(960, 66), D_800BD368, MAKEWH(64, 158));
    _drawImage(MAKEXY(768, 227), D_800D1268, MAKEWH(256, 1));
    setRECT(&D_800DC938, 640, 256, 32, 240);
    ClearImage(&D_800DC938, 0, 0, 0);
    DrawSync(0);
    setRECT(&D_800DC938, 768, 256, 32, 240);
    ClearImage(&D_800DC938, 0, 0, 0);
    _drawImage(MAKEXY(672, 256), D_800D1268 + 0x80, MAKEWH(96, 240));
    func_8006E5D0();

    D_800DC940 = 0;

    while (1) {
        vs_main_gametimeUpdate(2);
        func_8006E68C();
        vs_main_processPadState();
        _scramble(0);

        switch (D_800DC940) {
        case 0:
            _loadMemcardMenu(1);
            D_800DC940 = 1;
            continue;
        case 1:
            if (_loadMemcardMenu(0) != 0) {
                func_8006AE10();
                func_8006E00C(1);
                D_800DC940 = 2;
            }
            continue;
        case 2:
            temp_v0 = func_8006E00C(0);
            if (temp_v0 != 0) {
                if (temp_v0 < 0) {
                    D_800DED6C = D_800DEAC0 + 0x335;
                    func_8006EA70(1);
                    D_800DC940 = 3;
                } else {
                    func_8006A6E0();
                    func_8006ECF4();
                    D_800DC941 = 30;
                    D_800DC940 = 4;
                    continue;
                }
            }
            func_8006C114();
            func_8006BC78(D_800DED76);
            continue;
        case 3:
            temp_v0 = func_8006EA70(0);
            if (temp_v0 != 0) {
                if (temp_v0 != 1) {
                    func_8006A6E0();
                    func_8006ECF4();
                    D_800DC941 = 30;
                    D_800DC940 = 4;
                    continue;
                }
                func_8006E00C(1);
                D_800DC940 = 2;
            }
            func_8006C114();
            func_8006BC78(D_800DED76);
            continue;
        case 4:
            func_8006ECF4();
            if (--D_800DC941 == 0) {
                SetDispMask(0);
                return;
            }
            break;
        }
    }
}

void func_8006F0A0(D_800DEDA8_t* arg0, short arg1, short arg2, short arg3, int arg4)
{
    arg0->unk18[0].x = arg1;
    arg0->unk2C.x = arg1;
    arg0->unk18[0].y = arg2;
    arg0->unk2C.y = arg2;
    arg0->unk8 = 0;
    arg0->unk14 = 0;
    arg0->unk18[1].x = arg3;
    arg0->frameBuf = 0;
    arg0->unk2C.w = 0x18;
    arg0->unk34 = 0;
    arg0->unk0[0] = D_800EFDE8;
    arg0->unk0[1] = D_800EFDEC;
    arg0->unkC[0] = D_800EFDF0;
    arg0->unkC[1] = D_800EFDF4;
    arg0->unk18[1].y = arg4;
}

void func_8006F108(DslLOC* arg0, void (*arg1)())
{
    DecDCTReset(0);
    DecDCToutCallback(arg1);
    StSetRing((u_long*)D_800DEDE0, 0x40);
    StSetStream(1, 1, -1, 0, 0);
    playMovie(arg0);
}

void func_8006F174()
{
    RECT rect;
    short temp_v1;
    int temp_t0;
    u_int temp_lo;

    extern int StCdIntrFlag;
    if (StCdIntrFlag != 0) {
        StCdInterrupt();
        StCdIntrFlag = 0;
    }

    temp_t0 = D_800DEDA8.unk14;
    rect = D_800DEDA8.unk2C;
    temp_v1 = D_800DEDA8.unk2C.x + D_800DEDA8.unk2C.w;
    D_800DEDA8.unk14 = D_800DEDA8.unk14 == 0;
    D_800DEDA8.unk2C.x = temp_v1;

    if (temp_v1 < (D_800DEDA8.unk18[D_800DEDA8.frameBuf].x
            + D_800DEDA8.unk18[D_800DEDA8.frameBuf].w)) {
        temp_lo = D_800DEDA8.unk2C.w * D_800DEDA8.unk2C.h;
        DecDCTout(
            D_800DEDA8.unkC[D_800DEDA8.unk14], ((int)(temp_lo + (temp_lo >> 0x1F))) >> 1);
    } else {
        D_800DEDA8.unk34 = 1;
        D_800DEDA8.frameBuf = D_800DEDA8.frameBuf < 1;
        D_800DEDA8.unk2C.x = D_800DEDA8.unk18[D_800DEDA8.frameBuf].x;
        D_800DEDA8.unk2C.y = D_800DEDA8.unk18[D_800DEDA8.frameBuf].y;
    }
    LoadImage(&rect, D_800DEDA8.unkC[temp_t0]);
}

int func_8006F2A0(D_800DEDA8_t* arg0)
{
    u_long* temp_v0;
    int i;

    i = 0x7D0;

    while ((temp_v0 = (u_long*)func_8006F328(arg0)) == 0) {
        if (--i == 0) {
            return -1;
        }
    }

    arg0->unk8 = arg0->unk8 == 0;
    DecDCTvlc2(temp_v0, arg0->unk0[arg0->unk8], &D_800DEDE8);
    StFreeRing(temp_v0);
    return 0;
}

u_short* func_8006F328(D_800DEDA8_t* arg0)
{
    RECT rect;
    u_short* sp18;
    u_short* sp1C;
    int i;
    u_int temp_v1;

    for (i = 0x7D0; StGetNext((u_long**)&sp18, (u_long**)&sp1C) != 0;) {
        if (--i == 0) {
            return 0;
        }
    }

    if ((D_80074AAC != sp1C[8]) || (D_80074AB0 != sp1C[9])) {
        rect.w = 0x1E0;
        rect.x = 0;
        rect.y = 0;
        rect.h = 0x1C0;
        ClearImage(&rect, 0, 0, 0);
        D_80074AAC = sp1C[8];
        D_80074AB0 = sp1C[9];
    }
    temp_v1 = D_80074AAC * 3;
    arg0->unk18[1].w = (int)(temp_v1 + (temp_v1 >> 0x1F)) >> 1;
    arg0->unk18[0].w = (int)(temp_v1 + (temp_v1 >> 0x1F)) >> 1;
    arg0->unk18[1].h = D_80074AB0;
    arg0->unk18[0].h = D_80074AB0;
    arg0->unk2C.h = D_80074AB0;
    return sp18;
}

void func_8006F42C(D_800DEDA8_t* arg0, int arg1 __attribute__((unused)))
{
    volatile int sp0[2];
    int* new_var;
    int i = arg0->unk34;
    sp0[0] = 0x800000;

    while ((*(new_var = &i)) == 0) {
        if ((--sp0[0]) == 0) {
            arg0->unk34 = 1;
            arg0->frameBuf = arg0->frameBuf == 0;
            arg0->unk2C.x = arg0->unk18[arg0->frameBuf].x;
            arg0->unk2C.y = arg0->unk18[arg0->frameBuf].y;
        }
        i = arg0->unk34;
    }

    arg0->unk34 = 0;
}

void playMovie(DslLOC* arg0)
{
    u_char params[4];

    params[0] = DslModeSpeed;
    params[1] = 0;
    params[2] = 0;
    params[3] = 0;
    do {
        while (DsControl(DslSetloc, (u_char*)arg0, 0) == 0)
            ;
        while (DsControl(DslSetmode, params, 0) == 0)
            ;
        VSync(3);
    } while (DsRead2(arg0, dslMode) == 0);
}

void func_8006F54C()
{
    DISPENV disp;
    DRAWENV draw;
    RECT rect;
    int var_a3;
    int var_a3_2;
    int i;

    rect.w = 320;
    rect.x = 0;
    rect.y = 0;
    rect.h = 512;
    ClearImage(&rect, 0, 0, 0);
    _drawImage(MAKEXY(320, 64), D_80072F0C, MAKEWH(16, 1));
    _drawImage(MAKEXY(320, 0), D_80072F0C + 8, MAKEWH(64, 48));
    SetDefDispEnv(&disp, 0, 256, 320, 240);
    SetDefDrawEnv(&draw, 0, 0, 320, 240);
    disp.screen.y = 8;
    disp.screen.h = 224;
    PutDispEnv(&disp);
    PutDrawEnv(&draw);
    DrawSync(0);
    VSync(0);
    SetDispMask(1);

    for (i = 0; i < 0x16C; ++i) {
        var_a3 = 0;
        if (i < 0x20) {
            var_a3 = (0x1F - i) * 4;
        }
        if (i >= 0x14C) {
            var_a3 = (i - 0x14B) * 4;
        }
        _drawSprt(0x580020, 0x10140000, 0x300100, (var_a3 << 0x10) | 5);
        SetDefDispEnv(&disp, 0, (i & 1) * 256, 320, 240);
        SetDefDrawEnv(&draw, 0, (1 - (i & 1)) * 256, 320, 240);
        disp.screen.y = 8;
        disp.screen.h = 224;
        VSync(0);
        PutDispEnv(&disp);
        PutDrawEnv(&draw);
    }

    _drawImage(MAKEXY(0, 240), D_8007472C, MAKEWH(32, 14));

    for (i = 0; i < 0x16C; ++i) {
        var_a3_2 = 0;
        if (i < 0x20) {
            var_a3_2 = (0x1F - i) * 4;
        } else if (i >= 0x14C) {
            var_a3_2 = (i - 0x14B) * 4;
        } else if ((vs_main_buttonsState & 0xFFFF) != 0) {
            i = 0x14B;
        }
        _drawSprt(0x680060, 0x3F40F000, 0xD0080, var_a3_2 << 0x10);
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

void func_8006F81C()
{
    dslMode = DslModeStream2 | DslModeSpeed | DslModeRT;
    DsIntToPos(VS_TITLE_STR_LBA, &introMovieLoc);
    D_800DEDE0 = vs_main_allocHeap(0x20000);
    D_800EFDE8 = vs_main_allocHeap(0x23000);
    D_800EFDEC = vs_main_allocHeap(0x23000);
    D_800EFDF0 = vs_main_allocHeap(0x2A00);
    D_800EFDF4 = vs_main_allocHeap(0x2A00);
    func_8006F0A0(&D_800DEDA8, 0, 0, 0, 224);
    func_8006F108(&introMovieLoc, func_8006F174);
    DecDCTvlcBuild(&D_800DEDE8);

    while (func_8006F2A0(&D_800DEDA8) == -1) {
        DslLOC loc = introMovieLoc;
        playMovie(&loc);
    }
    _introMoviePlaying = 1;
    _introMovieDisplayedAt = VSync(-1);
}

void func_8006F954()
{
    SpuSetCommonMasterVolume(0, 0);
    _introMoviePlaying = 0;
    DecDCToutCallback(0);
    StUnSetRing();
    while (DsControlB(DslPause, 0, 0) == 0)
        ;
    vs_main_freeHeap(D_800EFDF4);
    vs_main_freeHeap(D_800EFDF0);
    vs_main_freeHeap(D_800EFDEC);
    vs_main_freeHeap(D_800EFDE8);
    vs_main_freeHeap(D_800DEDE0);
    SpuSetCommonMasterVolume(0x3FFF, 0x3FFF);
}

void func_8006FA04()
{
    if ((_introMoviePlaying != 0) && ((VSync(-1) - _introMovieDisplayedAt) >= 0x1131u)) {
        func_8006F954();
    }
}

int func_8006FA54()
{
    DslLOC loc;
    DISPENV disp;
    int var_s2;
    u_int temp_lo;

    var_s2 = 0;

    while (1) {
        DecDCTin((u_long*)D_800DEDA8.unk0[D_800DEDA8.unk8], 3);
        temp_lo = D_800DEDA8.unk2C.w * D_800DEDA8.unk2C.h;
        DecDCTout(
            D_800DEDA8.unkC[D_800DEDA8.unk14], (int)(temp_lo + (temp_lo >> 0x1F)) >> 1);

        while (func_8006F2A0(&D_800DEDA8) == -1) {
            if ((u_int)(StGetBackloc(&loc) - 1) >= 0x44CU) {
                loc = introMovieLoc;
            }
            playMovie(&loc);
        }

        func_8006F42C(&D_800DEDA8, 0);
        VSync(0);
        vs_main_processPadState();

        if ((VSync(-1) - _introMovieDisplayedAt) >= 0x8F5) {
            return 0;
        }

        SetDefDispEnv(&disp, 0, D_800DEDA8.frameBuf == 0 ? 224 : 0, 480, 224);
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

static void func_8006FC34(int hasSave, u_char arg1)
{
    _menuItemState[hasSave][0] = 1;
    _menuItemState[hasSave][1] = 0;
    _menuItemState[hasSave][2] = 0;
    _menuItemState[hasSave][3] = 0;
    _menuItemState[hasSave][4] = arg1;
    _menuItemState[hasSave][5] = arg1;
    _menuItemState[hasSave][6] = arg1;
    _menuItemState[hasSave][7] = 0;
}

void func_8006FC6C()
{
    RECT rect;
    int j;
    u_int new_var;
    u_int i;
    u_long* temp_v0;
    u_long* p;

    i = 0;
    temp_v0 = vs_main_allocHeap(0x99000);
    p = temp_v0;
    for (; i < 0xD9B5;) {
        new_var = D_80076AD4[i++];
        for (j = new_var & 0xFFFF; j != 0; --j) {
            *p++ = 0;
        }

        for (j = new_var >> 0x10; j != 0; --j) {
            *p++ = D_80076AD4[i++];
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

void func_8006FE30()
{
    DISPENV dispenv;
    DRAWENV drawenv;

    SetDefDispEnv(&dispenv, 0x200, 0x10, 0x200, 0x1E0);
    dispenv.screen.y = 8;
    dispenv.screen.h = 0xE0;
    dispenv.isinter = 1;
    SetDefDrawEnv(&drawenv, 0x200, 0, 0x200, 0x1E0);
    while (VSync(1) < 0xF8)
        ;
    PutDispEnv(&dispenv);
    PutDrawEnv(&drawenv);
    VSync(0);
}

void* func_8006FEC4(int hasSave)
{
    RECT rect;
    u_long* temp_s4;
    int i;
    u_char(*var_v0)[8];
    u_long* temp_s0;

    i = 9;
    var_v0 = _menuItemState;
    var_v0 += i;
    for (; i >= 0; --i) {
        **var_v0-- = 0;
    }

    func_8006FC34(hasSave, 0x40);
    func_8006FC34((hasSave + 1) & 3, 0x60);
    func_8006FC34((hasSave + 3) & 3, 0x20);
    temp_s4 = vs_main_allocHeap(0x22380);
    temp_s0 = temp_s4 + 0x2800;
    setRECT(&rect, 0xC0, 0x1C0, 0xA0, 0x40);
    StoreImage(&rect, temp_s0);
    DrawSync(0);
    temp_s0 += 0x1400;
    setRECT(&rect, 0x160, 0x1C0, 0xA0, 0x40);
    StoreImage(&rect, temp_s0);
    DrawSync(0);
    setRECT(&rect, 0x2A6, 0x178, 0xB4, 0x18);
    StoreImage(&rect, temp_s0 + 0x3C00);
    DrawSync(0);
    return temp_s4;
}

void _freeHeap(void* arg0) { vs_main_freeHeap(arg0); }

void _drawMenuBg(u_short* bgData, int alpha)
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
        rdiff = (r0 - r1) * alpha;
        gdiff = (g0 - g1) * alpha;
        bdiff = (b0 - b1) * alpha;
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

void _drawCopyright(u_short* arg0, int alpha)
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
        r0 = D_800AD1A8[i];
        g0 = r0 & 0x3E0;
        b0 = r0 & 0x7C00;
        g1 = r1 & 0x3E0;
        b1 = r1 & 0x7C00;
        r1 &= 0x1F;
        r0 &= 0x1F;
        rdiff = (r1 - r0) * alpha;
        gdiff = (g1 - g0) * alpha;
        bdiff = (b1 - b0) * alpha;
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

void _setMenuItemClut(int index, int alpha, int clut0, int clut1)
{
    RECT rect;
    short sp18[16];
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

    sp18[0] = 0;

    for (i = 1; i < 16; ++i) {
        r0 = _menuItemClut[clut0][i];
        r1 = _menuItemClut[clut1][i];
        g0 = r0 & 0x3E0;
        b0 = r0 & 0x7C00;
        r0 &= 0x1F;
        g1 = r1 & 0x3E0;
        b1 = r1 & 0x7C00;
        r1 &= 0x1F;
        rdiff = (r1 - r0) * alpha;
        gdiff = (g1 - g0) * alpha;
        bdiff = (b1 - b0) * alpha;
        sp18[i] = 0x1F0;
        sp18[i] = ((((r0 * 16 + rdiff) & 0x1F0) | ((g0 * 16 + gdiff) & 0x3E00)
                       | ((b0 * 16 + bdiff) & 0x7C000))
                      >> 4)
            | 0x8000;
    }
    setRECT(&rect, 480, index + 384, 16, 1);
    LoadImage(&rect, (u_long*)&sp18);
    DrawSync(0);
}

void func_800703CC()
{
    int i;
    int var_a0;
    int s1;

    i = 0;

    for (i = 0; i < 10; ++i) {
        if (_menuItemState[i][0] != 0) {
            var_a0 = _menuItemState[i][2] + 8;

            if (var_a0 >= 0x81) {
                var_a0 = 0x80;
            }

            _menuItemState[i][2] = var_a0;

            switch (_menuItemState[i][1]) {
            case 0:
                if (var_a0 == 0x80) {
                    if (_menuItemState[i][4] == 0x40) {

                        _menuItemState[i][6] = _menuItemState[i][4];
                        s1 = _menuItemState[i][7];

                        if (s1 < 16) {
                            _menuItemState[i][3] = s1 * 0x10;
                            s1 = s1 + 4;

                            if (s1 >= 17) {
                                s1 = 0x10;
                            }

                            _menuItemState[i][7] = s1;
                        }
                    }
                }
                break;
            case 1:
                _menuItemState[i][4] -= 4;
                if (_menuItemState[i][4] == _menuItemState[i][5]) {
                    _menuItemState[i][1] = 0;
                }
                break;
            case 2:
                _menuItemState[i][4] += 4;
                if (_menuItemState[i][4] == _menuItemState[i][5]) {
                    _menuItemState[i][1] = 0;
                }
                break;
            }

            s1 = _menuItemState[i][7];

            if (_menuItemState[i][1] < 3U) {
                _setMenuItemClut(i, s1, 0, 1);
            }
            if ((s1 != 0) && (_menuItemState[i][4] != 0x40)) {
                _menuItemState[i][7] = s1 - 1;
            }

            if (_menuItemState[i][3] != 0) {
                if (_menuItemState[i][6] != _menuItemState[i][4]) {
                    _menuItemState[i][3] = _menuItemState[i][3] - 0x10;

                    if (_menuItemState[i][6] < _menuItemState[i][4]) {
                        _menuItemState[i][6] = _menuItemState[i][6] + 2;
                    } else {
                        _menuItemState[i][6] = _menuItemState[i][6] - 2;
                    }
                } else if ((_menuItemState[i][7] == 0x10)
                    && (_menuItemState[i][3] >= 0x81U)) {
                    _menuItemState[i][3] = _menuItemState[i][3] - 0x10;
                }
            }
        }
    }
}

void func_800705AC();
INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_800705AC);

void func_8007093C()
{
    int i;
    VS_SPRT* sprt;

    func_800703CC();
    for (i = 0; i < 2; ++i) {
        sprt = &D_800DE948[0];
        vs_setTpage(sprt, 192, 256, direct16Bit, semiTransparencyHalf, ditheringOff);
        vs_setTag(sprt, primAddrEnd);
        vs_setRGB0(sprt, primSprt, 128, 128, 128);
        sprt->x0y0 = vs_getXY(176, 256);
        vs_setUV0Clut(sprt, 0, 192, 0, 0);
        sprt->wh = vs_getWH(160, 64);
        DrawPrim(sprt);
        ++sprt;
        vs_setTpage(sprt, 320, 256, direct16Bit, semiTransparencyHalf, ditheringOff);
        vs_setTag(sprt, primAddrEnd);
        vs_setRGB0(sprt, primSprt, 128, 128, 128);
        sprt->x0y0 = vs_getXY(176, 320);
        vs_setUV0Clut(sprt, 32, 192, 0, 0);
        sprt->wh = vs_getWH(160, 64);
        DrawPrim(sprt);
        func_800705AC();
        if (i == 0) {
            DrawSync(0);
            VSync(0);
            func_800436B4();
        } else {
            func_8006FA04();
        }
    }
}

void func_80070A58()
{
    func_8007093C();
    VSync(0);
    vs_main_processPadState();
}

void func_80070A88()
{
    int i;
    int var_s4;

    _menuItemState[1][1] = 1;
    _menuItemState[3][1] = 2;
    _menuItemState[3][5] = 0x80;
    _menuItemState[1][5] = 0;
    _menuItemState[2][1] = 3;
    var_s4 = D_8006002B + 5;
    func_8006FC34(6, 0x40U);
    func_8006FC34(5, 0x60U);
    _menuItemState[5][1] = 3;
    _menuItemState[6][1] = 3;
    _setMenuItemClut(5, 0, 0, 0);
    _setMenuItemClut(6, 0, 0, 0);
    for (i = 1; i < 9; ++i) {
        _setMenuItemClut(2, i * 2, 1, 3);
        _menuItemState[2][4] -= 4;
        func_80070A58();
    }
    _menuItemState[0][1] = 0;
    _menuItemState[1][1] = 0;
    _menuItemState[3][1] = 0;
    for (i = 1; i < 9; ++i) {
        func_80070A58();
    }

    for (i = 0; i < 8; ++i) {
        _setMenuItemClut(var_s4, i * 2, 0, 1);
        _menuItemState[var_s4][3] = i < 4 ? i << 6 : _menuItemState[var_s4][3] - 16;
        func_80070A58();
    }
    while (1) {
        func_80070A58();
        if (vs_main_buttonsState & (PADstart | PADRright)) {
            _playMenuSelectSfx();
            D_80060020.unkB = var_s4 - 5;
            if (var_s4 == 6) {
                func_800438C8(0);
            }
            break;
        } else if (vs_main_buttonsState & PADRdown) {
            _playMenuLeaveSfx();
            break;
        } else {
            if (vs_main_buttonsPressed & (PADLup | PADLdown | PADselect)) {
                var_s4 = 11 - var_s4;
                _playMenuChangeSfx();

                for (i = 1; i < 8; ++i) {
                    _setMenuItemClut(var_s4, i * 2, 0, 1);
                    _setMenuItemClut(11 - var_s4, i * 2, 1, 0);
                    _menuItemState[var_s4][3]
                        = i < 4 ? i << 6 : _menuItemState[var_s4][3] - 16;
                    _menuItemState[11 - var_s4][3] -= 16;
                    if (i == 7) {
                        break;
                    }
                    func_80070A58();
                }
            }
        }
    }
    func_8006FC34(1, 0);
    func_8006FC34(3, 0x80);
    _menuItemState[1][1] = 2;
    _menuItemState[1][5] = 32;
    _menuItemState[3][1] = 1;
    _menuItemState[3][5] = 0x60;
    for (i = 1; i < 9; ++i) {
        _setMenuItemClut(2, i * 2, 3, 1);
        _menuItemState[2][4] += 4;
        if (_menuItemState[5][2] < 24) {
            _menuItemState[5][2] = 0;
        } else {
            _menuItemState[5][2] -= 24;
        }
        if (_menuItemState[6][2] < 24) {
            _menuItemState[6][2] = 0;
        } else {
            _menuItemState[6][2] -= 24;
        }
        if (_menuItemState[5][3] != 0) {
            _menuItemState[5][3] -= 16;
        }
        if (_menuItemState[6][3] != 0) {
            _menuItemState[6][3] -= 16;
        }
        func_80070A58();
    }
    _menuItemState[5][0] = 0;
    _menuItemState[6][0] = 0;
    _menuItemState[2][6] = 0x40;
    _menuItemState[2][3] = 0x40;
    func_80070A58(2);
    _menuItemState[2][3] = 0x80;
    func_80070A58();
    _menuItemState[2][3] = 0xC0;
    func_8007093C();
    _menuItemState[2][7] = 0x10;
    _menuItemState[2][1] = 0;
}

void func_80070E64()
{
    int i;
    int var_s3;

    _menuItemState[2][1] = 1;
    _menuItemState[0][1] = 2;
    _menuItemState[0][5] = 0x80;
    _menuItemState[2][5] = 0;
    _menuItemState[3][1] = 3;
    var_s3 = 7 - (D_8006002A * 3);
    func_8006FC34(7, 0x40U);
    func_8006FC34(4, 0x60U);
    _menuItemState[4][1] = 3;
    _menuItemState[7][1] = 3;
    _setMenuItemClut(4, 0, 0, 0);
    _setMenuItemClut(7, 0, 0, 0);
    for (i = 1; i < 9; ++i) {
        _setMenuItemClut(3, i * 2, 1, 3);
        _menuItemState[3][4] -= 4;
        func_80070A58();
    }
    _menuItemState[0][1] = 0;
    _menuItemState[1][1] = 0;
    _menuItemState[2][1] = 0;
    for (i = 1; i < 9; ++i) {
        func_80070A58();
    }
    for (i = 0; i < 8; ++i) {
        _setMenuItemClut(var_s3, i * 2, 0, 1);
        _menuItemState[var_s3][3] = i < 4 ? i << 6 : _menuItemState[var_s3][3] - 16;
        func_80070A58();
    }
    while (1) {
        func_80070A58();
        if (vs_main_buttonsState & (PADstart | PADRright)) {
            _playMenuSelectSfx();
            var_s3 = (var_s3 + 1) & 1;
            D_80060020.unkA = var_s3;
            func_800468BC(var_s3);
            vs_sound_setCdVol(0x7F);
            break;
        } else if (vs_main_buttonsState & PADRdown) {
            _playMenuLeaveSfx();
            break;
        } else {
            if (vs_main_buttonsPressed & (PADLup | PADLdown | PADselect)) {
                var_s3 = 0xB - var_s3;
                _playMenuChangeSfx();
                for (i = 1; i < 8; ++i) {
                    _setMenuItemClut(var_s3, i * 2, 0, 1);
                    _setMenuItemClut(0xB - var_s3, i * 2, 1, 0);
                    _menuItemState[var_s3][3]
                        = i < 4 ? i << 6 : _menuItemState[var_s3][3] - 0x10;
                    _menuItemState[0xB - var_s3][3] -= 0x10;
                    if (i == 7) {
                        break;
                    }
                    func_80070A58();
                }
            }
        }
    }
    func_8006FC34(2, 0U);
    func_8006FC34(0, 0x80U);
    _menuItemState[2][1] = 2;
    _menuItemState[2][5] = 0x20;
    _menuItemState[0][1] = 1;
    _menuItemState[0][5] = 0x60;
    for (i = 1; i < 9; ++i) {
        _setMenuItemClut(3, i * 2, 3, 1);
        _menuItemState[3][4] += 4;
        if (_menuItemState[4][2] < 24) {
            _menuItemState[4][2] = 0;
        } else {
            _menuItemState[4][2] -= 24;
        }
        if (_menuItemState[7][2] < 24) {
            _menuItemState[7][2] = 0;
        } else {
            _menuItemState[7][2] -= 24;
        }
        if (_menuItemState[4][3] != 0) {
            _menuItemState[4][3] -= 16;
        }
        if (_menuItemState[7][3] != 0) {
            _menuItemState[7][3] -= 16;
        }
        func_80070A58();
    }
    _menuItemState[4][0] = 0;
    _menuItemState[7][0] = 0;
    _menuItemState[3][6] = 0x40;
    _menuItemState[3][3] = 0x40;
    func_80070A58(3);
    _menuItemState[3][3] = 0x80;
    func_80070A58();
    _menuItemState[3][3] = 0xC0;
    func_8007093C();
    _menuItemState[3][7] = 0x10;
    _menuItemState[3][1] = 0;
}

int _nop1() { return 0; }

void func_80071254()
{
    int var_s2;
    int var_s4;

    var_s4 = D_80060020.unkB;
    var_s2 = D_80060020.unkA;
    memset(&D_80060020, 0, 0x20);
    D_80060020.unk2 = 0x2D8;
    D_80060020.unk8 = 1;
    D_80060020.unk9 = 3;
    *((int*)&D_80060020) |= 0x30;
    D_80060020.unk1 = 1;
    if (vs_main_titleScreenCount == 0) {
        func_8006F54C();
        var_s4 = 1;
        var_s2 = 0;
    }
    D_80060020.unkA = var_s2 != 0;
    D_80060020.unkB = (var_s4 != 0);
    func_800468BC(D_80060020.unkA);
    vs_sound_setCdVol(0x7F);
    memset(&D_800619D8, 0, 0xB0);
    D_80061598[1] = 1;
    D_80061598[284] = 1;
}

int vs_title_exec()
{
    RECT rect;
    int i;
    int hasSave;
    int var_s3;
    void* temp_s1;

    if (vs_main_saveBeforeTitle != 0) {
        vs_main_saveBeforeTitle = 0;
        vs_main_titleScreenCount = 0;
        _displaySaveScreen();
    }
    func_80071B14();
    func_80071254();
    _introMoviePlaying = 0;
    ++vs_main_titleScreenCount;
    hasSave = _saveFileExists();

    do {
        for (i = 7; i >= 0; --i) {
            _menuItemState[i][0] = 0;
        }

        func_8006FC6C();
        func_8006F81C();
        func_8006FA54();
        func_8006FE30();
        SetDispMask(1);
        temp_s1 = func_8006FEC4(hasSave);
        for (i = 32; i >= 0; i -= 2) {
            _drawCopyright(temp_s1, i);
        }
        VSync(0);
        setRECT(&rect, 688, 256, 160, 128);
        StoreImage(&rect, temp_s1);
        DrawSync(0);
        VSync(0);
        for (i = 32; i >= 0; i -= 4) {
            _drawMenuBg(temp_s1, i);
            func_8007093C();
        }
        _freeHeap(temp_s1);
        for (i = 0; i < 8; ++i) {
            func_80070A58();
        }

        vs_main_padDisconnectAll();
        D_800DEA8C = VSync(-1);
        D_800DEA88 = VSync(-1);

        while (1) {
            VSync(0);
            vs_main_processPadState();
            if (_introMoviePlaying != 0) {
                D_800DEA8C = VSync(-1);
            }
            if ((vs_main_buttonsState & 0xFFFF) != 0) {
                D_800DEA88 = VSync(-1);
            }
            if (((VSync(-1) - D_800DEA88) >= 1001) && ((VSync(-1) - D_800DEA8C) >= 101)) {
                var_s3 = -1;
                break;
            }
            if (vs_main_buttonsState & (PADRright | PADstart)) {
                switch (hasSave) {
                case 0:
                    var_s3 = _nop1();
                    break;
                case 1:
                    var_s3 = 1;
                    break;
                case 2:
                    _playMenuSelectSfx();
                    func_80070A88();
                    break;
                case 3:
                    _playMenuSelectSfx();
                    func_80070E64();
                    break;
                }

                if ((hasSave < 2) && (var_s3 >= 0)) {
                    break;
                }
                D_800DEA88 = VSync(-1);
            }
            i = 0;
            if (vs_main_buttonsState & (PADLup | PADLleft)) {
                --i;
            }
            if (vs_main_buttonsState & (PADselect | PADLright | PADLdown)) {
                ++i;
            }
            if (i != 0) {
                hasSave = (hasSave + i) & 3;
                _playMenuChangeSfx();
                if (i == 1) {
                    func_8006FC34((hasSave + 1) & 3, 0x80);
                    for (i = 0; i < 4; ++i) {
                        _menuItemState[i][1] = 1;
                        _menuItemState[i][5] = _menuItemState[i][4] - 32;
                    }
                } else {
                    func_8006FC34((hasSave - 1) & 3, 0);
                    for (i = 0; i < 4; ++i) {
                        _menuItemState[i][1] = 2;
                        _menuItemState[i][5] = _menuItemState[i][4] + 32;
                    }
                }
                for (i = 0; i < 10; ++i) {
                    func_80070A58();
                }
            }
            func_8007093C();
        }
        if (var_s3 >= 0) {
            if (_introMoviePlaying != 0) {
                func_8006F954();
            }
            if (var_s3 == 1) {
                _playMenuSelectSfx();
            } else {
                _playNewGameSfx();
                func_80071CE0(var_s3);
            }
        }

        if (var_s3 == -1) {
            var_s3 = 4 - (vs_main_titleScreenCount & 1);
            func_80071CE0(var_s3);
        }
        for (i = 0x40; i > 0; --i) {
            VSync(0);
            vs_main_processPadState();
            vs_setTag(&_titleScreenFade, primAddrEnd);
            vs_setTpage(&_titleScreenFade, 320, 0, direct16Bit, semiTransparencySubtract,
                ditheringOff);
            vs_setRGB0(&_titleScreenFade, primTileSemiTrans, 8, 8, 8);
            _titleScreenFade.x0y0 = vs_getXY(0, 0);
            _titleScreenFade.wh = vs_getWH(640, 480);
            DrawPrim(&_titleScreenFade);
            func_800436B4();
        }
        VSync(0);
        SetDispMask(0);
        if (var_s3 == 1) {
            var_s3 = func_8006E738();
            if (var_s3 == 1) {
                func_80071CE0(1);
            }
        }
    } while (var_s3 < 0);
    return var_s3;
}

void func_8007183C(int w, int h, int screen, int r, int g, int b)
{
    RECT rect = (RECT) { 0, 0, 1024, 512 };
    SetDispMask(0);
    SetGeomOffset(w / 2, h / 2);
    SetGeomScreen(screen);
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

int drawPrims(u_long* ot)
{
    int dummy[2] __attribute__((unused));
    int temp_s1;

    vs_main_frameBuf = vs_main_frameBuf == 0;
    DrawSync(0);
    temp_s1 = vs_main_gametimeUpdate(0);
    PutDispEnv(vs_main_frameBuf + vs_main_dispEnv);
    PutDrawEnv(vs_main_frameBuf + vs_main_drawEnv);
    DrawOTag(ot);
    return temp_s1;
}

void func_80071B14()
{
    int i;
    int a1;
    u_char* v0;

    func_8007183C(0x280, 0xF0, 0x200, 0, 0, 0);
    i = 0x43F;
    v0 = D_80061598 + i;
    do {
        *v0-- = 0;
    } while (--i >= 0);

    vs_main_memcpy(vs_main_skillsLearned, D_80075B24, 0x20);
    vs_main_bzero(D_8005FFD8, 0x48);
    vs_main_bzero(&vs_main_gametime, sizeof(vs_main_gametime));
    vs_main_bzero(D_8005FEA0, 0x114);
    D_80060064 = 0;
    vs_main_bzero(D_80061078, 0x520);
    vs_main_bzero(D_80060040, 0x24);

    for (i = 0; i < 8; ++i) {
        for (a1 = 0; a1 < 3; ++a1) {
            ((D_8005FEA0_t*)&D_8005FEA0[i][a1])->unk28 &= 0xFF000000;
            ((D_8005FEA0_t*)&D_8005FEA0[i][a1])->unk28 |= 0x800000;
            ((D_8005FEA0_t*)&D_8005FEA0[i][a1])->unk28 &= 0x80FFFFFF;
            ((D_8005FEA0_t*)&D_8005FEA0[i][a1])->unk28 &= 0x7FFFFFFF;
        }
    }

    for (i = 0; i < 1; ++i) {
        vs_main_bzero(&D_80060068[i * 0x100], 0x50);
    }

    vs_main_bzero(&D_80061068, 0xC);
    vs_main_memcpy(D_80060168, D_80074C24, 0xF00);

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
