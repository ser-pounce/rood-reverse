#include "common.h"
#include "22C.h"
#include "../SLUS_010.40/main.h"
#include "../SLUS_010.40/31724.h"
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
    short unk2;
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
int func_8006CABC(int);
int func_8006CE6C(int);
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

extern RECT D_800DC928;
extern u_char D_800DC930;

u_char const saveFilenameTemplate[] = "bu00:BASLUS-01040VAG0";

extern int D_8005DFDC;
extern int vs_main_buttonsPressed;
extern int vs_main_buttonsState;
extern int D_8005E24C;
extern int D_8005FEA0[][3];
extern u_char D_8005FFB8[];
extern u_char D_8005FFD8[];
extern D_80060020_t D_80060020;
extern u_char D_80060040[];
extern int D_80060064;
extern u_char D_80060068[];
extern u_char D_80060168[];
extern int D_80061074[4];
extern u_char D_80061078[];
extern u_char D_80061068[];
extern u_char D_80061598[];
extern D_80060020_t D_800619D8;
extern u_short eventSpecs[];
extern int D_800728C0[];
extern u_char* pMemcardFilenameTemplate;
extern int D_800728E8[];
extern u_int scrambleSeed;
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
extern u_int D_800DE948[][6];
extern long memcardEventDescriptors[8];
extern void* D_800DEAB8[];
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

int testMemcardEventsFrom(int id)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if (TestEvent(memcardEventDescriptors[i + id]) == 1) {
            return i;
        }
    }
    return i;
}

void resetMemcardEventsFrom(int id)
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
    u_char* gameCode;

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

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006947C);

int func_800696D0(int arg0)
{
    int blockCount;
    u_char* temp_s1;
    void* blocks;
    int* temp_s2;
    int* temp_s4;

    temp_s1 = D_800DEAB8[0];
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

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_80069EA8);

INCLUDE_RODATA("build/src/TITLE/TITLE.PRG/nonmatchings/22C", D_8006886C);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006A11C);

int func_8006A49C(int arg0)
{
    vs_main_CdFile cdFile;
    int i;
    u_int event;

    if (arg0 != 0) {
        D_800DEAB8[0] = vs_main_allocHeap(0x1C000U);
        D_800DEABC = (u_int*)D_800DEAB8[0] + 0x4500;
        D_800DEAC0 = (u_short*)(D_800DEABC + 0x400);
        D_800DEB08 = (u_int(*)[0x20])(D_800DEABC + 0x800);
        dirEntBuf[0] = (struct DIRENTRY*)(D_800DEABC + 0x8A0);
        cdFile.lba = VS_SPMCIMG_BIN_LBA;
        cdFile.size = VS_SPMCIMG_BIN_SIZE;
        D_800DC8C8 = vs_main_getQueueSlot(&cdFile);
        func_80044BC4(D_800DC8C8, D_800DEAB8[0]);
        D_800DC8C4 = 0;
        return 0;
    }

    switch (D_800DC8C4) {
    case 0:
        if (D_800DC8C8->unk0[0] == 4) {
            func_80044B80(D_800DC8C8);
            drawImage(0x01000320, (u_long*)D_800DEAB8[0], 0x010000E0);
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
    vs_main_freeHeap(D_800DEAB8[0]);
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
        D_800DED6C = &D_800DEAC0[((u_short*)(&D_800DEAC0[temp_s0]))[21]];
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

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006C778);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006CABC);

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
        if (vs_main_buttonsPressed & 0x60) {
            D_800DED68 = 0;
            for (i = 3; i < 5; ++i) {
                D_800DEB18[i].unk0 = 4;
                D_800DEB18[i].unk8 = -0x7E;
            }
            if (vs_main_buttonsPressed & 0x20) {
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

    drawImage(0x300, D_800C2268, 0xE00040);
    drawImage(0x010001C0, D_800C2268 + 0x1C00, 0x01000040);
    drawImage(0x340, D_800AF368, 0xE00040);
    drawImage(0x380, D_800AF368 + 0x1C00, 0xE00040);
    drawImage(0x4203C0, D_800BD368, 0x9E0040);
    drawImage(0xE30300, D_800D1268, 0x10100);
    D_800DC928.x = 0x280;
    D_800DC928.y = 0x100;
    D_800DC928.w = 0x20;
    D_800DC928.h = 0xF0;
    ClearImage(&D_800DC928, 0U, 0U, 0U);
    DrawSync(0);
    D_800DC928.x = 0x300;
    D_800DC928.y = 0x100;
    D_800DC928.w = 0x20;
    D_800DC928.h = 0xF0;
    ClearImage(&D_800DC928, 0U, 0U, 0U);
    drawImage(0x010002A0, D_800D1268 + 0x80, 0xF00060);
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

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006EA70);

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

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_8006EDBC);

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

    rect.w = 0x140;
    rect.x = 0;
    rect.y = 0;
    rect.h = 0x200;
    ClearImage(&rect, 0, 0, 0);
    drawImage(0x400140, D_80072F0C, 0x10010);
    drawImage(0x140, D_80072F0C + 8, 0x300040);
    SetDefDispEnv(&disp, 0, 0x100, 0x140, 0xF0);
    SetDefDrawEnv(&draw, 0, 0, 0x140, 0xF0);
    disp.screen.y = 8;
    disp.screen.h = 0xE0;
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
        SetDefDispEnv(&disp, 0, (i & 1) << 8, 0x140, 0xF0);
        SetDefDrawEnv(&draw, 0, (1 - (i & 1)) << 8, 0x140, 0xF0);
        disp.screen.y = 8;
        disp.screen.h = 0xE0;
        VSync(0);
        PutDispEnv(&disp);
        PutDrawEnv(&draw);
    }

    drawImage(0xF00000, D_8007472C, 0xE0020);

    for (i = 0; i < 0x16C; ++i) {
        var_a3_2 = 0;
        if (i < 0x20) {
            var_a3_2 = (0x1F - i) * 4;
        } else if (i >= 0x14C) {
            var_a3_2 = (i - 0x14B) * 4;
        } else if ((u_short)vs_main_buttonsState != 0) {
            i = 0x14B;
        }
        func_8006A778(0x680060, 0x3F40F000, 0xD0080, var_a3_2 << 0x10);
        SetDefDispEnv(&disp, 0, (i & 1) << 8, 0x140, 0xF0);
        SetDefDrawEnv(&draw, 0, (1 - (i & 1)) << 8, 0x140, 0xF0);
        disp.screen.y = 8;
        disp.screen.h = 0xE0;
        VSync(0);
        vs_main_processPadState();
        PutDispEnv(&disp);
        PutDrawEnv(&draw);
    }
    SetDispMask(0);
}

void func_8006F81C()
{
    dslMode = 0x1E0;
    DsIntToPos(0x3EBE8, &introMovieLoc);
    D_800DEDE0 = vs_main_allocHeap(0x20000);
    D_800EFDE8 = vs_main_allocHeap(0x23000);
    D_800EFDEC = vs_main_allocHeap(0x23000);
    D_800EFDF0 = vs_main_allocHeap(0x2A00);
    D_800EFDF4 = vs_main_allocHeap(0x2A00);
    func_8006F0A0(&D_800DEDA8, 0, 0, 0, 0xE0);
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
    while (DsControlB(9U, 0, 0) == 0)
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

        if ((vs_main_buttonsPressed & 0x820)) {
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

u_long* func_8006FEC4(int arg0)
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

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_80070A88);

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", func_80070E64);

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
    func_800468BC(D_80060020.unkA & 0xFF);
    func_80013230(0x7F);
    memset(&D_800619D8, 0, 0xB0);
    D_80061598[1] = 1;
    D_80061598[284] = 1;
}

INCLUDE_ASM("build/src/TITLE/TITLE.PRG/nonmatchings/22C", vs_title_exec);

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
