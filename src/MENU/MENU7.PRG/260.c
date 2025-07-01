#include "common.h"
#include "../../src/SLUS_010.40/main.h"
#include <libgte.h>
#include <libgpu.h>
#include <memory.h>
#include <libapi.h>
#include <sys/file.h>
#include <string.h>

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

extern char const* _memcardFilenameTemplate;

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
extern struct DIRENTRY* _memcardFiles[15];

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

static int func_80102D14()
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
    char unk55E0[0x100];
    char unk56E0[0x300];
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

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80102EF4);

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

int _deleteRedundantTempFiles(int port)
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

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80103134);

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

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801033DC);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80103630);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801037E8);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80103DD0);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80104044);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801043C4);

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80104618);

static void func_801046C0(int, int, int, int);
INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_801046C0);

static void func_80104764(int arg0, int id)
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

INCLUDE_ASM("build/src/MENU/MENU7.PRG/nonmatchings/260", func_80104DB8);

static void func_80104EC0(int arg0)
{
    memset(&_fileMenuElements[arg0], 0, sizeof(_fileMenuElements[arg0]));
}

static int func_80104F04()
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

static u_int func_801053FC(u_int arg0, u_int arg1, int arg2)
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

static void func_80106080()
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

static int func_8010928C(int arg0, int arg1)
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
