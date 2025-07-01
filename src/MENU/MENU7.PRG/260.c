#include "common.h"
#include "../../src/SLUS_010.40/main.h"
#include <libgte.h>
#include <libgpu.h>
#include <memory.h>
#include <libapi.h>
#include <sys/file.h>

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

extern saveFileInfo_t* _saveFileInfo;
extern fileMenuElements_t _fileMenuElements[10];
extern short _fileProgressTarget;
extern int _fileProgressCounter;
extern int _selectCursorXy;
extern char* _memoryCardMessage;
extern char _selectCursorColor;
extern char _fileMenuScreenFade;
extern long _memcardEventDescriptors[8];
extern int D_8010A2E4[];
extern int D_8010A30C[];
extern u_short D_8010AA2C[];

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80102A60);

void _resetMemcardEvents(int type) {
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

char* _memcardMakeFilename(int, int);
INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", _memcardMakeFilename);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80102C38);

u_int _getNewestSaveFile()
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

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80102D14);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80102DAC);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80102E28);

static void _decode(u_int key, void* buf, int count)
{
    for (; count != 0; --count) {
        key *= 0x19660D;
        *((char*)buf++) -= key >> 24;
    }
}

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80102EF4);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_8010300C);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_8010309C);

INCLUDE_RODATA("build/src/MENU/MENU7.PRG/nonmatchings/260", D_80102800);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80103134);

int _createSaveFile(int port, int id) {
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

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801033DC);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80103630);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801037E8);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80103DD0);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80104044);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801043C4);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80104618);

void func_801046C0(int, int, int, int);
INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801046C0);

void func_80104764(int arg0, int id)
{
    func_801046C0(arg0, D_8010A2E4[id], D_8010A30C[id], 0xC);
}

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801047A8);

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

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80104870);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80104B00);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80104C20);


void _initFileMenu() {
    _memoryCardMessage = 0;
    _selectCursorColor = 0;
    _selectCursorXy = 0;
    _fileProgressCounter = 0;
    _fileMenuScreenFade = 0;
    _fileProgressTarget = 0x180;
    memset(&_fileMenuElements, 0, sizeof(_fileMenuElements));
}

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80104DB8);

void func_80104EC0(int arg0) { memset(&_fileMenuElements[arg0], 0, sizeof(_fileMenuElements[arg0])); }

int func_80104F04()
{
    int i;

    for (i = 0; i < 10 && _fileMenuElements[i].state < fileMenuElementStateAnimateX; ++i)
        ;
    return i == 10;
}

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80104F40);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80105080);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801051F4);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801052D0);

u_int func_801053FC(u_int arg0, u_int arg1, int arg2)
{
    int temp_a3;
    u_int i;
    u_int ret;

    ret = 0;
    for (i = 0; i < 3; ++i) {
        temp_a3 = ((arg0 >> 16) & 0xFF) * (8 - arg2);
        arg0 <<= 8;
        ret = (ret << 8) + ((temp_a3 + (((arg1 >> 16) & 0xFF) * arg2)) >> 3);
        arg1 <<= 8;
    }
    return ret;
}

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80105458);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_8010550C);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80105BE4);

void func_80106080()
{
    func_801046C0(0x100, 0x38F00000, 0xB00040, 0x9C);
    func_801046C0(0, 0x38F00000, 0xB00100, 0x9A);
}

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801060C8);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801062E0);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_8010639C);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80106554);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80106E70);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80107268);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_8010787C);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80107E98);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801081DC);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801085B0);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801086DC);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801087F0);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801088B4);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80108CE8);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_8010903C);

int func_8010928C(int arg0, int arg1)
{
    int i;
    int var_a3;

    i = 0;
    var_a3 = 0;

    if (arg0 > 0) {
        do {
            var_a3 += D_8010AA2C[i++];
        } while (i < arg0);
    }
    return arg1 + (var_a3 * 2);
}

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801092C4);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80109778);

INCLUDE_RODATA("build/src/MENU/MENU7.PRG/nonmatchings/260", D_80102A0C);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80109D64);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80109EB8);
