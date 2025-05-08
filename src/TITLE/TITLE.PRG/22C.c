#include "common.h"
#include "22C.h"
#include "../SLUS_010.40/main.h"
#include "../SLUS_010.40/31724.h"
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
    short unk2;
    u_int unk4;
    u_char unk8;
    u_char unk9;
    u_char unkA;
    u_char unkB;
    int unkC;
    int unk10;
    u_int unk14;
    u_short unk18;
    u_short unk1A;
    u_int unk1C;
} D_80060020_t;

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
    int unkC;
    int unk10;
    u_char unk14[32];
} D_800DEB18_t;

typedef struct {
    int unk0[10];
    int unk28;
} D_8005FEA0_t;

u_char* memcardFilenameFromTemplate(int, int);
int memcardFileNumberFromFilename(u_char*);
int func_8006913C(int);
int func_800691D4(int);
int func_8006947C(int);
int func_8006A49C(int);
void func_8006A778(int, int, int, int);
void func_8006BC78(u_char);
int func_8006C778(u_char);
int func_8006CABC(int);
int func_8006CE6C(int);
int func_8006E00C(int);
void playMovie(DslLOC*);
void func_8006F174();
int func_8006F2A0(D_800DEDA8_t*);
u_short* func_8006F328(D_800DEDA8_t* arg0);
void func_8006F54C();
void func_8006F954();
void _setMenuItemClut(int, int, int, int);
void func_800703CC();
void func_800705AC();
void func_8007093C();
void func_80071B14();
void func_80071CE0(int arg0);

u_char const saveFilenameTemplate[] = "bu00:BASLUS-01040VAG0";

u_char const* pMemcardFilenameTemplate = saveFilenameTemplate;
u_int scrambleSeed = 0x0019660D;
u_short eventSpecs[] = { EvSpIOE, EvSpERROR, EvSpTIMOUT, EvSpNEW };

extern int D_8005DFDC;
extern int vs_main_buttonsPressed;
extern int vs_main_buttonsState;
extern int D_8005E214;
extern int D_8005E24C;
extern int D_8005FEA0[][3];
extern u_char D_8005FFB8[];
extern u_char D_8005FFD8[];
extern D_80060020_t D_80060020;
extern u_char D_8006002A;
extern u_char D_8006002B;
extern u_char D_80060040[];
extern int D_80060064;
extern u_char D_80060068[];
extern u_char D_80060168[];
extern int D_80061074[4];
extern u_char D_80061078[];
extern u_char D_80061068[];
extern u_char D_80061598[];
extern D_80060020_t D_800619D8;
extern int D_800728C0[];
extern int D_800728E8[];
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
extern u_char memcardFilename[32];
extern u_char memcardFilenameAlpha[32];
extern u_char _memCardState;
extern u_char _memCardPort;
extern u_char D_800D9280[];
extern u_char D_800DC8AA;
extern u_char _memCardTimeout;
extern u_char D_800DC8AC;
extern u_char D_800DC8AD;
extern u_char D_800DC8AE;
extern u_char D_800DC8AF;
extern u_char D_800DC8B0;
extern u_char D_800DC8B1;
extern int D_800DC8B4;
extern u_char D_800DC8B8;
extern u_char _memcardFileno;
extern u_char _memcardPort;
extern u_char D_800DC8BB;
extern u_char D_800DC8BC;
extern u_char D_800DC8E0;
extern u_char D_800DC8E1;
extern u_char D_800DC8E2;
extern int _saveFileId;
extern RECT D_800DC938;
extern u_char D_800DC940;
extern u_char D_800DC941;
extern u_char D_800DEB0C;
extern u_short D_800DEB10;
extern u_short D_800DEB12;
extern u_char D_800DC8C4;
extern vs_main_CdQueueSlot* D_800DC8C8;
extern u_char D_800DC8CC[];
extern u_char D_800DC8CD;
extern u_char D_800DC8E8;
extern u_char D_800DC8E9;
extern int D_800DC8EC;
extern u_char D_800DC8F0;
extern u_char D_800DC8F1;
extern u_char D_800DC8F2;
extern u_char memcardPort;
extern RECT D_800DC928;
extern u_char D_800DC930;
extern u_char D_800DC931;
extern u_char D_800DC932;
extern u_int D_800DE948[][6];
extern long memcardEventDescriptors[8];
extern VS_TILE _titleScreenFade;
extern int D_800DEA88;
extern int D_800DEA8C;
extern u_char* D_800DEAB8;
extern u_int* D_800DEABC;
extern u_short* D_800DEAC0;
extern struct DIRENTRY* memcardFiles[15];
extern struct DIRENTRY* dirEntBuf[];
extern u_int (*D_800DEB08)[0x20];
extern u_short D_800DEB0E;
extern int D_800DEB14;
extern D_800DEB18_t D_800DEB18[10];
extern int D_800DED28[];
extern int D_800DED68;
extern u_short* D_800DED6C;
extern u_char D_800DED70;
extern u_char D_800DED71;
extern u_char D_800DED72;
extern u_char D_800DED76;
extern u_int menuDisplayedTime;
extern int D_800DED7C;
extern DslLOC introMovieLoc;
extern D_800DEDA8_t D_800DEDA8;
extern int dslMode;
extern void* D_800DEDE0;
extern u_short D_800DEDE8;
extern void* D_800EFDE8;
extern void* D_800EFDEC;
extern void* D_800EFDF0;
extern void* D_800EFDF4;
extern u_char D_800EFDF8[][8];

#define MAKEXY(x, y) (((x) << 16) | (y))
#define MAKEWH(w, h) MAKEXY(w, h)

void func_80068A2C()
{
    func_80045988(0x7E, 1);
    func_80045988(0x7E, 2);
    func_80045988(0x7E, 3);
}

void func_80068A68() { func_80045988(0x7E, 4); }

void func_80068A8C() { func_80045988(0x7E, 5); }

void func_80068AB0() { func_80045988(0x7E, 6); }

u_int scramble(int value)
{
    u_int seed;

    seed = scrambleSeed;
    scrambleSeed = seed * 0x19660D;
    return seed >> (32 - value);
}

int testMemcardEvents(int id)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if (TestEvent(memcardEventDescriptors[i + id]) == 1) {
            return i;
        }
    }
    return i;
}

void resetMemcardEvents(int id)
{
    int i;

    for (i = 0; i < 4; ++i) {
        TestEvent(memcardEventDescriptors[i + id]);
    }
}

void drawImage(int xy, u_long* p, int wh)
{
    RECT rect;

    *(int*)&rect.x = xy;
    *(int*)&rect.w = wh;
    LoadImage(&rect, p);
    DrawSync(0);
}

void readImage(int xy, u_long* p, int wh)
{
    RECT rect;

    *(int*)&rect.x = xy;
    *(int*)&rect.w = wh;
    StoreImage(&rect, p);
    DrawSync(0);
}

void rMemcpy(u_char* arg0, u_char* arg1, int arg2)
{
    do {
        --arg2;
        arg0[arg2] = arg1[arg2];
    } while (arg2 != 0);
}

u_char* memcardFilenameFromTemplate(int port, int fileNo)
{
    memset(memcardFilename, 0, ' ');
    strcpy(memcardFilename, pMemcardFilenameTemplate);
    memcardFilename[2] = port == 0 ? '0' : '1';
    memcardFilename[20] = fileNo + '0';
    return memcardFilename;
}

u_char* memcardFilenameFromTemplateAlpha(int port, int fileNo)
{
    memset(memcardFilenameAlpha, 0, ' ');
    strcpy(memcardFilenameAlpha, pMemcardFilenameTemplate);
    memcardFilenameAlpha[2] = port == 0 ? '0' : '1';
    memcardFilenameAlpha[20] = (fileNo + '@');
    return memcardFilenameAlpha;
}

u_int func_80068D54()
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

int func_80068DB4()
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

int memcardFileNumberFromFilename(u_char* filename)
{
    int i;
    u_char const* gameCode;

    gameCode = &pMemcardFilenameTemplate[5];

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

int verifySaveChecksums(u_char blocks[][0x100], int blockCount)
{
    int var_a2;
    int i, j;
    u_char* block;

    block = blocks[0];

    for (i = 0; i < blockCount; ++i) {
        var_a2 = 0;
        if (i != 1) {
            for (j = 0; j < 0x100; ++j) {
                var_a2 ^= block[j];
            }
            if (((u_char*)blocks + i)[0x1A4] != var_a2) {
                return 1;
            }
        }
        block += 0x100;
    }

    block = blocks[1];
    var_a2 = 0;

    for (j = 0; j < 0x100; ++j) {
        var_a2 ^= block[j];
    }
    return var_a2 != 0;
}

void descramble(u_int seed, u_char* buf, int count)
{
    for (; count != 0; --count) {
        seed *= 0x19660D;
        *buf++ -= seed >> 24;
    }
}

int func_80068F94(int id)
{
    u_char buf[2][0x100];
    int bytesRead;
    int port;
    int file;
    int i;

    port = id >> 0xC;
    id &= 7;

    for (i = 0; i < 3; ++i) {
        file = open(memcardFilenameFromTemplate(port, id), O_RDONLY);
        if (file != -1) {
            bytesRead = read(file, buf, 0x200);
            close(file);
            if (bytesRead == 0x200) {
                descramble(*((int*)&buf + 96), &buf[1][132], 124);
                if (verifySaveChecksums(buf, 2) == 0) {
                    rMemcpy((u_char*)D_800DEB08[id - 1], &buf[1][0x80], 0x80);
                    return 0;
                }
            }
        }
    }
    memset(D_800DEB08[id - 1], 0, 0x80);
    return 1;
}

int memcardSaveIdExists(int id)
{
    int i;

    for (i = 0; i < 15; ++i) {
        u_char* filename = memcardFiles[i]->name;
        if ((filename != NULL) && (memcardFileNumberFromFilename(filename) != 0)) {
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
            if (erase(memcardFilenameFromTemplateAlpha(port, i + 1)) == 0) {
                return 0x80;
            }
            ret |= 1 << i;
        }
    }
    return ret;
}

// https://decomp.me/scratch/yelA8
INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_800691D4);

int createSaveFile(int port, int id)
{
    u_char* fileName;
    long file;

    fileName = memcardFilenameFromTemplate((port - 1) * 0x10, id);
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

#define SWEVENTS 0
#define HWEVENTS 4

int func_8006947C(int arg0)
{
    int event;

    if (arg0 != 0) {
        _memCardPort = (arg0 - 1) * 16;
        _memCardState = _memCardInit;
        D_800DC8AA = 0;
        return 0;
    }
    switch (_memCardState) {
    case _memCardInit:
        if (++D_800DC8AA >= 4) {
            return 2;
        }
        resetMemcardEvents(SWEVENTS);
        if (_card_info(_memCardPort) == 0) {
            break;
        }
        _memCardState = _memCardReady;
        _memCardTimeout = 0;
        D_800DC8AC = 0;
        // fallthrough
    case _memCardReady:
        switch (testMemcardEvents(SWEVENTS)) {
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
        resetMemcardEvents(HWEVENTS);
        if (_card_clear(_memCardPort) == 0) {
            break;
        }
        _memCardState = _memCardConfirmed;
        _memCardTimeout = 0;
        D_800DC8AC = 4;
        // fallthrough
    case _memCardConfirmed:
        do {
            event = testMemcardEvents(HWEVENTS);
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
        resetMemcardEvents(SWEVENTS);
        if (_card_load(_memCardPort) == 0) {
            break;
        }
        _memCardState = _memCardLoaded;
        _memCardTimeout = 0;
        // fallthrough
    case _memCardLoaded:
        event = testMemcardEvents(SWEVENTS);
        switch (event) {
        case _memCardEventIoEnd:
            return D_800DC8AC + 1;
        case _memCardEventError:
        case _memCardEventTimeout:
            _memCardState = _memCardInit;
            break;
        case _memCardEventNew:
            return D_800DC8AC + 3;
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
    u_char* temp_s1;
    void* blocks;
    int* temp_s2;
    int* temp_s4;

    temp_s1 = D_800DEAB8;
    blocks = temp_s1 + 0x5C00;
    temp_s4 = blocks;
    temp_s2 = (int*)temp_s1 + 0x1760;

    descramble(*temp_s2, temp_s1 + 0x5D84, 0x5A7C);

    blockCount = 0x5C;
    if (arg0 != 0) {
        blockCount = 0x20;
    }

    if ((verifySaveChecksums(blocks, blockCount) != 0) || (temp_s2[3] != 0x20000107)) {
        do {
            return 1;
        } while (0);
    }

    if (arg0 == 0) {
        return 0;
    }

    rMemcpy(D_80061598, temp_s1 + 0x5E00, 0x440);
    rMemcpy(D_8005FFB8, temp_s1 + 0x6240, 0x20);
    rMemcpy(D_8005FFD8, temp_s1 + 0x6260, 0x48);
    rMemcpy(&D_80060020.unk0, temp_s1 + 0x62A8, 0x20);
    rMemcpy(D_80060068, temp_s1 + 0x62C8, 0x100);
    rMemcpy(D_80060168, temp_s1 + 0x63C8, 0xF00);
    rMemcpy(&D_800619D8.unk0, temp_s1 + 0x72C8, 0xB0);
    rMemcpy(D_80061068, temp_s1 + 0x7378, 0xC);
    rMemcpy((u_char*)D_8005FEA0, temp_s1 + 0x7384, 0x114);
    D_80060064 = temp_s4[0x626];
    rMemcpy(D_80061078, temp_s1 + 0x749C, 0x520);
    blocks = D_80060040;
    rMemcpy(D_80060040, temp_s1 + 0x79BC, 0x24);
    __builtin_memcpy(&D_80061074, temp_s1 + 0x5D90, 4);
    func_80042CA0();
    func_800468BC(D_80060020.unkA);
    return 0;
}

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_80069888);

int func_80069EA8(int arg0)
{
    int temp_v0_3;
    int var_a2;
    u_char* var_a0;
    void* temp_s2;
    int new_var;

    temp_s2 = D_800DEAB8 + 0x5C00;
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
            var_a0 = memcardFilenameFromTemplateAlpha(D_800DC8AE, D_800DC8AF & 7);
        } else {
            var_a0 = memcardFilenameFromTemplate(D_800DC8AE, D_800DC8AF);
        }
        D_800DC8B4 = open((char*)var_a0, 0x8001);
        if (D_800DC8B4 == -1) {
            D_800DC8B1 += 1;
            break;
        }
        resetMemcardEvents(SWEVENTS);
        var_a2 = 0x5C00;
        if (D_800DC8B0 != 0) {
            var_a2 = 0x2000;
        }
        if (read(D_800DC8B4, temp_s2, var_a2) == -1) {
            close(D_800DC8B4);
            D_800DC8B1 += 1;
            break;
        }
        D_800DC8AD = 1;
        // fallthrough
    case 1:
        temp_v0_3 = testMemcardEvents(SWEVENTS);
        if (temp_v0_3 < _memCardEventNone) {
            close(D_800DC8B4);
            if (temp_v0_3 == 0) {
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
        if (rename((char*)memcardFilenameFromTemplate(_memcardPort, _memcardFileno),
                (char*)memcardFilenameFromTemplateAlpha(_memcardPort, _memcardFileno))
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
            = open((char*)memcardFilenameFromTemplateAlpha(_memcardPort, _memcardFileno),
                0x8002);
        ;
        if (_saveFileId == -1) {
            ++D_800DC8BB;
            break;
        }
        resetMemcardEvents(SWEVENTS);
        if (write(_saveFileId, D_800DEAB8, 0x5C00) == -1) {
            close(_saveFileId);
            ++D_800DC8BB;
            break;
        }
        D_800DC8B8 = 2;
        // fallthrough
    case 2: {
        temp_s3 = testMemcardEvents(SWEVENTS);
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
            if (D_800DEAB8[temp_s2] != D_800DEAB8[temp_s2 + 0x5C00]) {
                break;
            }
        }
        if (temp_s2 < 0x5C00) {
            return -1;
        }
        D_800DC8B8 = 4;
        break;
    case 4:
        if (rename((char*)memcardFilenameFromTemplateAlpha(_memcardPort, _memcardFileno),
                (char*)memcardFilenameFromTemplate(_memcardPort, _memcardFileno))
            == 0) {
            ++D_800DC8BC;
            D_800DC8BB = (D_800DC8BC >> 4);
            break;
        }
        return 1;
    }
    return D_800DC8BB == 3 ? -1 : 0;
}

int func_8006A49C(int arg0)
{
    vs_main_CdFile cdFile;
    int i;
    u_int event;

    if (arg0 != 0) {
        D_800DEAB8 = (u_char*)vs_main_allocHeap(0x1C000U);
        D_800DEABC = (u_int*)D_800DEAB8 + 0x4500;
        D_800DEAC0 = (u_short*)(D_800DEABC + 0x400);
        D_800DEB08 = (u_int(*)[0x20])(D_800DEABC + 0x800);
        dirEntBuf[0] = (struct DIRENTRY*)(D_800DEABC + 0x8A0);
        cdFile.lba = VS_SPMCIMG_BIN_LBA;
        cdFile.size = VS_SPMCIMG_BIN_SIZE;
        D_800DC8C8 = vs_main_getQueueSlot(&cdFile);
        func_80044BC4(D_800DC8C8, D_800DEAB8);
        D_800DC8C4 = 0;
        return 0;
    }

    switch (D_800DC8C4) {
    case 0:
        if (D_800DC8C8->unk0[0] == 4) {
            func_80044B80(D_800DC8C8);
            drawImage(MAKEXY(256, 800), (u_long*)D_800DEAB8, MAKEWH(256, 224));
            D_800DC8C4 = 1;
        }
        return 0;
    case 1:
        cdFile.lba = VS_MCDATA_BIN_LBA; // MCMAN.BIN must immediately follow MCDATA.BIN on
                                        // the disk
        cdFile.size = VS_MCDATA_BIN_SIZE + VS_MCMAN_BIN_SIZE;
        D_800DC8C8 = vs_main_getQueueSlot(&cdFile);
        func_80044BC4(D_800DC8C8, D_800DEABC);
        D_800DC8C4 = 2;
        break;
    case 2:
        break;
    default:
        return 0;
    }

    if (D_800DC8C8->unk0[0] == 4) {
        func_80044B80(D_800DC8C8);
        func_80042C94(0);
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
    func_80042C94(1);
    vs_main_freeHeap(D_800DEAB8);
}

void func_8006A778(int arg0, int arg1, int arg2, int arg3)
{
    DrawSync(0);
    D_800DED28[0] = 0x05000000;
    D_800DED28[1] = ((arg3 & 0x9FF) | 0xE1000000);
    D_800DED28[2] = (((0x80 - (arg3 >> 0x10)) * 0x10101) | 0x64000000);
    D_800DED28[3] = arg0;
    D_800DED28[4] = arg1;
    D_800DED28[5] = arg2;
    DrawPrim(&D_800DED28);
}

void func_8006A81C(int arg0, int arg1)
{
    func_8006A778(arg0, D_800728C0[arg1], D_800728E8[arg1], 0xC);
}

void func_8006A860(int arg0, u_int arg1, u_int arg2)
{
    do {
        func_8006A778(arg0, ((arg1 / arg2) * 6) | 0x37F40000, 0xA0006, 0xC);
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

// https://decomp.me/scratch/AgXZ0
INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006A928);

void func_8006ABB8(u_int arg0, int arg1)
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
        D_800DED28[0] = 0x09000000;
        D_800DED28[2] = (var_s4 | 0x3A000000);
        D_800DED28[3] = (var_s3 | arg1);
        D_800DED28[5] = (arg0 | arg1);
        D_800DED28[7] = (var_s3 | (arg1 + 0x200000));
        D_800DED28[1] = 0xE1000220;
        D_800DED28[4] = var_s2;
        D_800DED28[6] = var_s4;
        D_800DED28[8] = var_s2;
        D_800DED28[9] = (arg0 | (arg1 + 0x200000));
        DrawPrim(D_800DED28);
        var_s3 = arg0;
        arg0 += 0x10;
        var_s4 = var_s2;
        var_s2 = 0;
    }
}

void func_8006ACD8(int arg0, int arg1)
{
    int temp_v1;
    int var_s2;
    int var_s3;
    int var_s5;
    u_int var_s4;

    var_s3 = arg1;
    var_s5 = 0;

    if (D_800DED70 != 0) {
        var_s2 = arg0 + (arg0 << 15);
    } else {
        var_s2 = (arg0 - (arg0 >> 3)) + (arg0 << 8);
    }

    DrawSync(0);
    D_800DED28[0] = 0x04000000;
    D_800DED28[1] = 0xE1000220;
    D_800DED28[2] = (var_s2 | 0x62000000);
    D_800DED28[3] = (var_s3 | 0x40);
    D_800DED28[4] = 0x200100;
    DrawPrim(D_800DED28);

    for (var_s4 = 0; var_s4 < 2; ++var_s4) {
        DrawSync(0);
        D_800DED28[0] = 0x08000000;
        temp_v1 = var_s3 + 0xFFF80000;
        D_800DED28[1] = (var_s5 | 0x3A000000);
        D_800DED28[2] = (temp_v1 | 0x40);
        D_800DED28[3] = var_s5;
        D_800DED28[4] = (temp_v1 | 0x140);
        D_800DED28[5] = var_s2;
        D_800DED28[6] = (var_s3 | 0x40);
        D_800DED28[7] = var_s2;
        D_800DED28[8] = (var_s3 | 0x140);
        DrawPrim(D_800DED28);
        var_s3 += 0x280000;
        var_s5 = var_s2;
        var_s2 = 0;
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
    memset(D_800DEB18, 0, 0x208);
}

D_800DEB18_t* func_8006AE70(int arg0, int arg1, int arg2, u_char* arg3)
{
    D_800DEB18_t* temp_s3;
    int i;
    u_int var_v1;

    temp_s3 = &D_800DEB18[arg0];
    memset(temp_s3, 0, 0x34);
    temp_s3->unk0 = 1;
    temp_s3->unk1 = 0xFF;
    temp_s3->unkC = arg1;
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

int func_8006AFF8(u_int arg0, int arg1, int arg2, int arg3)
{
    if ((arg0 >> 8) == 0xE) {
        return arg1 + (arg0 & 0xFF);
    }
    if (arg0 != 0x8F) {
        DrawSync(0);
        D_800DED28[0] = 0x05000000;
        D_800DED28[1] = 0xE100002D;
        D_800DED28[2] = 0x66808080;
        D_800DED28[3] = (arg1 & 0xFFFF) | (arg2 << 0x10);
        D_800DED28[5] = 0xC000C;
        D_800DED28[4] = ((arg0 - ((arg0 / 21) * 0x15)) * 0xC) | ((arg0 / 21) * 0xC00)
            | ((((((arg3 * 0x10) + 0x380) >> 4) & 0x3F) | 0x3780) << 0x10);
        DrawPrim(D_800DED28);
    }
    return arg1 + D_80072914[arg0];
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
        func_8006947C(temp_s0);
        ++D_800DC8CC[0];
    } else {
        temp_v1 = func_8006947C(0) & 3;

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
        func_8006947C(arg0 & 3);
        D_800DC8CC[2] = (arg0 >> 4);
        return 0;
    }
    temp_v0 = func_8006947C(0);
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

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006BC78);

void func_8006C114()
{
    func_8006A778(0x100, 0x38F00000, 0xB00040, 0x9C);
    func_8006A778(0, 0x38F00000, 0xB00100, 0x9A);
}

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006C15C);

// https://decomp.me/scratch/KxBXc
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
        if (vs_main_buttonsPressed & 0x40) {
            func_80045988(0x7E, 6);
            D_800DED68 = 0;
            for (i = 0; i < 3; ++i) {
                D_800DEB18[i].unk0 = 2;
                D_800DEB18[i].unk8 = 0x140;
            }
            D_800DC8E0 = 6;
        } else if (vs_main_buttonsPressed & 0x20) {
            func_80045988(0x7E, 5);
            func_8006C778(D_800DC8E1);
            D_800DED68 = 0;
            D_800DC8E0 = 5;
        } else {
            if (D_8005DFDC & 0x5000) {
                func_80045988(0x7E, 4);
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
                    func_80045988(0x7E, 5);
                    return 1;
                }
            }
            func_80045988(0x7E, 6);
            return -1;
        }
        if (D_8005DFDC & 0x5000) {
            func_80045988(0x7E, 4);
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
            func_8006947C((int)memcardPort);
            D_800DC8F2 = 2;
        }
        return 0;
    case 2:
        temp_v0 = func_8006947C(0);

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

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006D2F8);

// https://decomp.me/scratch/QD0zT
INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006DC14);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006E00C);

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

    drawImage(MAKEXY(0, 768), D_800C2268, MAKEWH(224, 64));
    drawImage(MAKEXY(256, 448), D_800C2268 + 0x1C00, MAKEWH(256, 64));
    drawImage(MAKEXY(0, 832), D_800AF368, MAKEWH(224, 64));
    drawImage(MAKEXY(0, 896), D_800AF368 + 0x1C00, MAKEWH(224, 64));
    drawImage(MAKEXY(66, 960), D_800BD368, MAKEWH(158, 64));
    drawImage(MAKEXY(227, 768), D_800D1268, MAKEWH(1, 256));
    setRECT(&D_800DC928, 640, 256, 32, 240);
    ClearImage(&D_800DC928, 0, 0, 0);
    DrawSync(0);
    setRECT(&D_800DC928, 768, 256, 32, 240);
    ClearImage(&D_800DC928, 0U, 0U, 0U);
    drawImage(MAKEXY(256, 672), D_800D1268 + 0x80, MAKEWH(240, 96));
    func_8006E5D0();
    D_800DC930 = 0;

    while (1) {
        func_8004261C(2);
        func_8006E68C();
        vs_main_processPadState();
        switch (D_800DC930) {
        case 0:
            if (D_800DC930 == 0) {
                func_8006A49C(1);
                D_800DC930 = 1;
            }
            break;
        case 1:
            if (func_8006A49C(0) != 0) {
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

int func_8006E988()
{
    struct DIRENTRY dir;
    u_char sp38[0x16];
    int temp_s0;
    int i;
    int ret = 0;

    func_8006A49C(1);

    do {
        func_8004261C(2);
    } while (func_8006A49C(0) == 0);

    for (i = 1; i < 3; ++i) {
        func_8006947C(i);
        do {
            temp_s0 = func_8006947C(0) & 3;
            VSync(2);
        } while (temp_s0 == 0);

        if (temp_s0 == 1) {
            rMemcpy((u_char*)sp38, (u_char*)pMemcardFilenameTemplate, 0x16);

            sp38[2] = i + '/';
            sp38[20] = '?';

            if (firstfile(sp38, &dir) != 0) {
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
            func_80045988(0x7E, 7);
        }
        if (vs_main_buttonsPressed & PADRright) {
            D_800DC931 = 4;
        }
        if (D_800DC931 == 4) {
            if (D_800DC932 == 1) {
                func_80068A8C();
            } else {
                func_80068AB0();
            }
            D_800DED68 = 0;
            for (i = 1; i < 3; ++i) {
                D_800DEB18[i].unk0 = 2;
                D_800DEB18[i].unk8 = 0x140;
            }
            break;
        }
        if (D_8005DFDC & 0x5000) {
            func_80068A68();
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
    func_8006A778(0x100, 0, 0xE00040,
        (((((1 - D_800DED76) * 0x140) + 0x100) & 0x3FF) >> 6) | 0x140);
    func_8006A778(0, 0, 0xE00100, (((1 - D_800DED76) * 5) & 0xF) | 0x140);
    DrawSync(0);
    D_800DED28[0] = 0x03000000;
    D_800DED28[1] = 0x62080808;
    D_800DED28[2] = 0;
    D_800DED28[3] = 0xE00140;
    DrawPrim(D_800DED28);
}

void func_8006EDBC()
{
    int temp_v0;

    drawImage(MAKEXY(0, 768), D_800C2268, MAKEWH(224, 64));
    drawImage(MAKEXY(256, 448), D_800C2268 + 0x1C00, MAKEWH(256, 64));
    drawImage(MAKEXY(0, 832), D_800AF368, MAKEWH(224, 64));
    drawImage(MAKEXY(0, 896), D_800AF368 + 0x1C00, MAKEWH(224, 64));
    drawImage(MAKEXY(66, 960), D_800BD368, MAKEWH(158, 64));
    drawImage(MAKEXY(227, 768), D_800D1268, MAKEWH(1, 256));
    setRECT(&D_800DC938, 640, 256, 32, 240);
    ClearImage(&D_800DC938, 0, 0, 0);
    DrawSync(0);
    setRECT(&D_800DC938, 768, 256, 32, 240);
    ClearImage(&D_800DC938, 0, 0, 0);
    drawImage(MAKEXY(256, 672), D_800D1268 + 0x80, MAKEWH(240, 96));
    func_8006E5D0();

    D_800DC940 = 0;

    while (1) {
        func_8004261C(2);
        func_8006E68C();
        vs_main_processPadState();
        scramble(0);

        switch (D_800DC940) {
        case 0:
            func_8006A49C(1);
            D_800DC940 = 1;
            continue;
        case 1:
            if (func_8006A49C(0) != 0) {
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
    drawImage(MAKEXY(64, 320), D_80072F0C, MAKEWH(1, 16));
    drawImage(MAKEXY(0, 320), D_80072F0C + 8, MAKEWH(48, 64));
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
        func_8006A778(0x580020, 0x10140000, 0x300100, (var_a3 << 0x10) | 5);
        SetDefDispEnv(&disp, 0, (i & 1) * 256, 320, 240);
        SetDefDrawEnv(&draw, 0, (1 - (i & 1)) * 256, 320, 240);
        disp.screen.y = 8;
        disp.screen.h = 224;
        VSync(0);
        PutDispEnv(&disp);
        PutDrawEnv(&draw);
    }

    drawImage(MAKEXY(240, 0), D_8007472C, MAKEWH(14, 32));

    for (i = 0; i < 0x16C; ++i) {
        var_a3_2 = 0;
        if (i < 0x20) {
            var_a3_2 = (0x1F - i) * 4;
        } else if (i >= 0x14C) {
            var_a3_2 = (i - 0x14B) * 4;
        } else if ((vs_main_buttonsState & 0xFFFF) != 0) {
            i = 0x14B;
        }
        func_8006A778(0x680060, 0x3F40F000, 0xD0080, var_a3_2 << 0x10);
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
    D_800DED7C = 1;
    menuDisplayedTime = VSync(-1);
}

void func_8006F954()
{
    SpuSetCommonMasterVolume(0, 0);
    D_800DED7C = 0;
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
    if ((D_800DED7C != 0) && ((VSync(-1) - menuDisplayedTime) >= 0x1131u)) {
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

        if ((VSync(-1) - menuDisplayedTime) >= 0x8F5) {
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

void func_8006FC34(int arg0, u_char arg1)
{
    D_800EFDF8[arg0][0] = 1;
    D_800EFDF8[arg0][1] = 0;
    D_800EFDF8[arg0][2] = 0;
    D_800EFDF8[arg0][3] = 0;
    D_800EFDF8[arg0][4] = arg1;
    D_800EFDF8[arg0][5] = arg1;
    D_800EFDF8[arg0][6] = arg1;
    D_800EFDF8[arg0][7] = 0;
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

void* func_8006FEC4(int arg0)
{
    RECT rect;
    u_long* temp_s4;
    int i;
    u_char(*var_v0)[8];
    u_long* temp_a1;
    u_long* temp_s0;

    i = 9;
    var_v0 = D_800EFDF8;
    var_v0 += 9;

    for (; i >= 0; --i) {
        var_v0[0][0] = 0;
        --var_v0;
    }

    func_8006FC34(arg0, 0x40);
    func_8006FC34((arg0 + 1) & 3, 0x60);
    func_8006FC34((arg0 + 3) & 3, 0x20);
    temp_s4 = vs_main_allocHeap(0x22380);
    temp_s0 = temp_s4 + 0x2800;
    temp_a1 = temp_s0;
    setRECT(&rect, 0xC0, 0x1C0, 0xA0, 0x40);
    StoreImage(&rect, temp_a1);
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
        if (D_800EFDF8[i][0] != 0) {
            var_a0 = D_800EFDF8[i][2] + 8;

            if (var_a0 >= 0x81) {
                var_a0 = 0x80;
            }

            D_800EFDF8[i][2] = var_a0;

            switch (D_800EFDF8[i][1]) {
            case 0:
                if (var_a0 == 0x80) {
                    if (D_800EFDF8[i][4] == 0x40) {

                        D_800EFDF8[i][6] = D_800EFDF8[i][4];
                        s1 = D_800EFDF8[i][7];

                        if (s1 < 16) {
                            D_800EFDF8[i][3] = s1 * 0x10;
                            s1 = s1 + 4;

                            if (s1 >= 17) {
                                s1 = 0x10;
                            }

                            D_800EFDF8[i][7] = s1;
                        }
                    }
                }
                break;
            case 1:
                D_800EFDF8[i][4] -= 4;
                if (D_800EFDF8[i][4] == D_800EFDF8[i][5]) {
                    D_800EFDF8[i][1] = 0;
                }
                break;
            case 2:
                D_800EFDF8[i][4] += 4;
                if (D_800EFDF8[i][4] == D_800EFDF8[i][5]) {
                    D_800EFDF8[i][1] = 0;
                }
                break;
            }

            s1 = D_800EFDF8[i][7];

            if (D_800EFDF8[i][1] < 3U) {
                _setMenuItemClut(i, s1, 0, 1);
            }
            if ((s1 != 0) && (D_800EFDF8[i][4] != 0x40)) {
                D_800EFDF8[i][7] = s1 - 1;
            }

            if (D_800EFDF8[i][3] != 0) {
                if (D_800EFDF8[i][6] != D_800EFDF8[i][4]) {
                    D_800EFDF8[i][3] = D_800EFDF8[i][3] - 0x10;

                    if (D_800EFDF8[i][6] < D_800EFDF8[i][4]) {
                        D_800EFDF8[i][6] = D_800EFDF8[i][6] + 2;
                    } else {
                        D_800EFDF8[i][6] = D_800EFDF8[i][6] - 2;
                    }
                } else if ((D_800EFDF8[i][7] == 0x10) && (D_800EFDF8[i][3] >= 0x81U)) {
                    D_800EFDF8[i][3] = D_800EFDF8[i][3] - 0x10;
                }
            }
        }
    }
}

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_800705AC);

void func_8007093C()
{
    int i;
    u_int(*temp_s0)[6];

    func_800703CC();
    for (i = 0; i < 2; ++i) {
        temp_s0 = &D_800DE948[0];
        (*temp_s0)[1] = 0xE1000113;
        (*temp_s0)[0] = 0x05FFFFFF;
        (*temp_s0)[2] = 0x64808080;
        (*temp_s0)[3] = 0x010000B0;
        (*temp_s0)[4] = 0xC000;
        (*temp_s0)[5] = 0x4000A0;
        DrawPrim(&D_800DE948);
        ++temp_s0;
        (*temp_s0)[1] = 0xE1000115;
        (*temp_s0)[0] = 0x05FFFFFF;
        (*temp_s0)[2] = 0x64808080;
        (*temp_s0)[3] = 0x014000B0;
        (*temp_s0)[4] = 0xC020;
        (*temp_s0)[5] = 0x4000A0;
        DrawPrim(temp_s0);
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

    D_800EFDF8[1][1] = 1;
    D_800EFDF8[3][1] = 2;
    D_800EFDF8[3][5] = 0x80;
    D_800EFDF8[1][5] = 0;
    D_800EFDF8[2][1] = 3;
    var_s4 = D_8006002B + 5;
    func_8006FC34(6, 0x40U);
    func_8006FC34(5, 0x60U);
    D_800EFDF8[5][1] = 3;
    D_800EFDF8[6][1] = 3;
    _setMenuItemClut(5, 0, 0, 0);
    _setMenuItemClut(6, 0, 0, 0);
    for (i = 1; i < 9; ++i) {
        _setMenuItemClut(2, i * 2, 1, 3);
        D_800EFDF8[2][4] -= 4;
        func_80070A58();
    }
    D_800EFDF8[0][1] = 0;
    D_800EFDF8[1][1] = 0;
    D_800EFDF8[3][1] = 0;
    for (i = 1; i < 9; ++i) {
        func_80070A58();
    }

    for (i = 0; i < 8; ++i) {
        _setMenuItemClut(var_s4, i * 2, 0, 1);
        D_800EFDF8[var_s4][3] = i < 4 ? i << 6 : D_800EFDF8[var_s4][3] - 16;
        func_80070A58();
    }
    while (1) {
        func_80070A58();
        if (vs_main_buttonsState & (PADstart | PADRright)) {
            func_80068A8C();
            D_80060020.unkB = var_s4 - 5;
            if (var_s4 == 6) {
                func_800438C8(0);
            }
            break;
        } else if (vs_main_buttonsState & PADRdown) {
            func_80068AB0();
            break;
        } else {
            if (vs_main_buttonsPressed & (PADLup | PADLdown | PADselect)) {
                var_s4 = 11 - var_s4;
                func_80068A68();

                for (i = 1; i < 8; ++i) {
                    _setMenuItemClut(var_s4, i * 2, 0, 1);
                    _setMenuItemClut(11 - var_s4, i * 2, 1, 0);
                    D_800EFDF8[var_s4][3] = i < 4 ? i << 6 : D_800EFDF8[var_s4][3] - 16;
                    D_800EFDF8[11 - var_s4][3] -= 16;
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
    D_800EFDF8[1][1] = 2;
    D_800EFDF8[1][5] = 32;
    D_800EFDF8[3][1] = 1;
    D_800EFDF8[3][5] = 0x60;
    for (i = 1; i < 9; ++i) {
        _setMenuItemClut(2, i * 2, 3, 1);
        D_800EFDF8[2][4] += 4;
        if (D_800EFDF8[5][2] < 24) {
            D_800EFDF8[5][2] = 0;
        } else {
            D_800EFDF8[5][2] -= 24;
        }
        if (D_800EFDF8[6][2] < 24) {
            D_800EFDF8[6][2] = 0;
        } else {
            D_800EFDF8[6][2] -= 24;
        }
        if (D_800EFDF8[5][3] != 0) {
            D_800EFDF8[5][3] -= 16;
        }
        if (D_800EFDF8[6][3] != 0) {
            D_800EFDF8[6][3] -= 16;
        }
        func_80070A58();
    }
    D_800EFDF8[5][0] = 0;
    D_800EFDF8[6][0] = 0;
    D_800EFDF8[2][6] = 0x40;
    D_800EFDF8[2][3] = 0x40;
    func_80070A58(2);
    D_800EFDF8[2][3] = 0x80;
    func_80070A58();
    D_800EFDF8[2][3] = 0xC0;
    func_8007093C();
    D_800EFDF8[2][7] = 0x10;
    D_800EFDF8[2][1] = 0;
}

void func_80070E64()
{
    int i;
    int var_s3;

    D_800EFDF8[2][1] = 1;
    D_800EFDF8[0][1] = 2;
    D_800EFDF8[0][5] = 0x80;
    D_800EFDF8[2][5] = 0;
    D_800EFDF8[3][1] = 3;
    var_s3 = 7 - (D_8006002A * 3);
    func_8006FC34(7, 0x40U);
    func_8006FC34(4, 0x60U);
    D_800EFDF8[4][1] = 3;
    D_800EFDF8[7][1] = 3;
    _setMenuItemClut(4, 0, 0, 0);
    _setMenuItemClut(7, 0, 0, 0);
    for (i = 1; i < 9; ++i) {
        _setMenuItemClut(3, i * 2, 1, 3);
        D_800EFDF8[3][4] -= 4;
        func_80070A58();
    }
    D_800EFDF8[0][1] = 0;
    D_800EFDF8[1][1] = 0;
    D_800EFDF8[2][1] = 0;
    for (i = 1; i < 9; ++i) {
        func_80070A58();
    }
    for (i = 0; i < 8; ++i) {
        _setMenuItemClut(var_s3, i * 2, 0, 1);
        D_800EFDF8[var_s3][3] = i < 4 ? i << 6 : D_800EFDF8[var_s3][3] - 16;
        func_80070A58();
    }
    while (1) {
        func_80070A58();
        if (vs_main_buttonsState & (PADstart | PADRright)) {
            func_80068A8C();
            var_s3 = (var_s3 + 1) & 1;
            D_80060020.unkA = var_s3;
            func_800468BC(var_s3);
            func_80013230(0x7F);
            break;
        } else if (vs_main_buttonsState & PADRdown) {
            func_80068AB0();
            break;
        } else {
            if (vs_main_buttonsPressed & (PADLup | PADLdown | PADselect)) {
                var_s3 = 0xB - var_s3;
                func_80068A68();
                for (i = 1; i < 8; ++i) {
                    _setMenuItemClut(var_s3, i * 2, 0, 1);
                    _setMenuItemClut(0xB - var_s3, i * 2, 1, 0);
                    D_800EFDF8[var_s3][3] = i < 4 ? i << 6 : D_800EFDF8[var_s3][3] - 0x10;
                    D_800EFDF8[0xB - var_s3][3] -= 0x10;
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
    D_800EFDF8[2][1] = 2;
    D_800EFDF8[2][5] = 0x20;
    D_800EFDF8[0][1] = 1;
    D_800EFDF8[0][5] = 0x60;
    for (i = 1; i < 9; ++i) {
        _setMenuItemClut(3, i * 2, 3, 1);
        D_800EFDF8[3][4] += 4;
        if (D_800EFDF8[4][2] < 24) {
            D_800EFDF8[4][2] = 0;
        } else {
            D_800EFDF8[4][2] -= 24;
        }
        if (D_800EFDF8[7][2] < 24) {
            D_800EFDF8[7][2] = 0;
        } else {
            D_800EFDF8[7][2] -= 24;
        }
        if (D_800EFDF8[4][3] != 0) {
            D_800EFDF8[4][3] -= 16;
        }
        if (D_800EFDF8[7][3] != 0) {
            D_800EFDF8[7][3] -= 16;
        }
        func_80070A58();
    }
    D_800EFDF8[4][0] = 0;
    D_800EFDF8[7][0] = 0;
    D_800EFDF8[3][6] = 0x40;
    D_800EFDF8[3][3] = 0x40;
    func_80070A58(3);
    D_800EFDF8[3][3] = 0x80;
    func_80070A58();
    D_800EFDF8[3][3] = 0xC0;
    func_8007093C();
    D_800EFDF8[3][7] = 0x10;
    D_800EFDF8[3][1] = 0;
}

int nop1() { return 0; }

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
    if (D_8004A528 == 0) {
        func_8006F54C();
        var_s4 = 1;
        var_s2 = 0;
    }
    D_80060020.unkA = var_s2 != 0;
    D_80060020.unkB = (var_s4 != 0);
    func_800468BC(D_80060020.unkA);
    func_80013230(0x7F);
    memset(&D_800619D8, 0, 0xB0);
    D_80061598[1] = 1;
    D_80061598[284] = 1;
}

int vs_title_exec()
{
    RECT rect;
    int i;
    int i_5;
    int i_7;
    int var_s2;
    int var_s3;
    void* temp_s1;

    if (D_8005E214 != 0) {
        D_8005E214 = 0;
        D_8004A528 = 0;
        func_8006EDBC();
    }
    func_80071B14();
    func_80071254();
    D_800DED7C = 0;
    ++D_8004A528;
    var_s2 = func_8006E988();

    do {
        for (i = 7; i >= 0; --i) {
            D_800EFDF8[i][0] = 0;
        }

        func_8006FC6C();
        func_8006F81C();
        func_8006FA54();
        func_8006FE30();
        SetDispMask(1);
        temp_s1 = func_8006FEC4(var_s2);
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
            if (D_800DED7C != 0) {
                D_800DEA8C = VSync(-1);
            }
            if ((vs_main_buttonsState & 0xFFFF) != 0) {
                D_800DEA88 = VSync(-1);
            }
            if (((VSync(-1) - D_800DEA88) >= 0x3E9)
                && ((VSync(-1) - D_800DEA8C) >= 0x65)) {
                var_s3 = -1;
                break;
            }
            if (vs_main_buttonsState & (PADRright | PADstart)) {
                switch (var_s2) {
                case 0:
                    var_s3 = nop1();
                    break;
                case 1:
                    var_s3 = 1;
                    break;
                case 2:
                    func_80068A8C();
                    func_80070A88();
                    break;
                case 3:
                    func_80068A8C();
                    func_80070E64();
                    break;
                }

                if ((var_s2 < 2) && (var_s3 >= 0)) {
                    break;
                }
                D_800DEA88 = VSync(-1);
            }
            i_5 = 0;
            if (vs_main_buttonsState & (PADLup | PADLleft)) {
                --i_5;
            }
            if (vs_main_buttonsState & (PADselect | PADLright | PADLdown)) {
                ++i_5;
            }
            if (i_5 != 0) {
                var_s2 = (var_s2 + i_5) & 3;
                func_80068A68();
                if (i_5 == 1) {
                    func_8006FC34((var_s2 + 1) & 3, 0x80);
                    for (i = 0; i < 4; ++i) {
                        D_800EFDF8[i][1] = 1;
                        D_800EFDF8[i][5] = D_800EFDF8[i][4] - 32;
                    }
                } else {
                    func_8006FC34((var_s2 - 1) & 3, 0);
                    for (i = 0; i < 4; ++i) {
                        D_800EFDF8[i][1] = 2;
                        D_800EFDF8[i][5] = D_800EFDF8[i][4] + 32;
                    }
                }
                for (i_7 = 0; i_7 < 10; ++i_7) {
                    func_80070A58();
                }
            }
            func_8007093C();
        }
        if (var_s3 >= 0) {
            if (D_800DED7C != 0) {
                func_8006F954();
            }
            if (var_s3 == 1) {
                func_80068A8C();
            } else {
                func_80068A2C();
                func_80071CE0(var_s3);
            }
        }

        if (var_s3 == -1) {
            var_s3 = 4 - (D_8004A528 & 1);
            func_80071CE0(var_s3);
        }
        for (i = 0x40; i > 0; --i) {
            VSync(0);
            vs_main_processPadState();
            vs_setTag(&_titleScreenFade, primAddrEnd);
            vs_setTpage(&_titleScreenFade, 320, 0, direct16Bit, semiTransparencySubtract);
            vs_setRGB0(&_titleScreenFade, primTileSemiTrans, 8, 8, 8);
            vs_setXY0(&_titleScreenFade, 0, 0);
            vs_setWH(&_titleScreenFade, 640, 480);
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
        i = 7;
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
    temp_s1 = func_8004261C(0);
    PutDispEnv(vs_main_frameBuf + vs_main_dispEnv);
    PutDrawEnv(vs_main_frameBuf + vs_main_drawEnv);
    DrawOTag(ot);
    return temp_s1;
}

void func_80071B14()
{
    int i;
    int a1;
    u_short* s0;
    u_char* v0;

    func_8007183C(0x280, 0xF0, 0x200, 0, 0, 0);
    i = 0x43F;
    v0 = D_80061598 + i;
    do {
        *v0-- = 0;
    } while (--i >= 0);

    memcpy_impl(D_8005FFB8, D_80075B24, 0x20);
    bzero_impl(D_8005FFD8, 0x48);
    bzero_impl(D_80061074, 4);
    bzero_impl(D_8005FEA0, 0x114);
    D_80060064 = 0;
    bzero_impl(D_80061078, 0x520);
    bzero_impl(D_80060040, 0x24);

    for (i = 0; i < 8; ++i) {
        for (a1 = 0; a1 < 3; ++a1) {
            ((D_8005FEA0_t*)&D_8005FEA0[i][a1])->unk28 &= 0xFF000000;
            ((D_8005FEA0_t*)&D_8005FEA0[i][a1])->unk28 |= 0x800000;
            ((D_8005FEA0_t*)&D_8005FEA0[i][a1])->unk28 &= 0x80FFFFFF;
            ((D_8005FEA0_t*)&D_8005FEA0[i][a1])->unk28 &= 0x7FFFFFFF;
        }
    }

    for (i = 0; i <= 0; ++i) {
        bzero_impl(&D_80060068[i * 0x100], 0x50);
    }

    bzero_impl(D_80061068, 0xC);
    memcpy_impl(D_80060168, D_80074C24, 0xF00);

    s0 = (u_short*)D_80061068;
    D_8005E24C = 2;
    s0[2] = (s0[2] & 0xE0FF) | 0x400;
    s0[3] = ((s0[3] & 0x83FF) | 0x800);
    s0[1] = (s0[1] & 0x1FFF);
    s0[2] = ((s0[2] & 0x9FFF) | 0x4000);
}

void func_80071CE0(int arg0)
{
    switch (arg0) {
    case 0:
        D_80061598[0xC] = 0;
        D_80061598[0xD] = 0;
        D_80061068[0x0] = 1;
        D_80061068[0x1] = 0;
        return;
    case 3:
        D_80061598[0xC] = 0;
        D_80061598[0xD] = 1;
        D_80061598[0xE] = 1;
        D_80061068[0x0] = 0x14;
        D_80061068[0x1] = 0;
        return;
    case 4:
        D_80061598[0xC] = 0;
        D_80061598[0xD] = 1;
        D_80061598[0xE] = 1;
        D_80061068[0x0] = 2;
        D_80061068[0x1] = 1;
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
