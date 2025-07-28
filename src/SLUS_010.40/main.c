#include "main.h"
#include "common.h"
#include "overlay.h"
#include "../TITLE/TITLE.PRG/22C.h"
#include "../BATTLE/BATTLE.PRG/146C.h"
#include "../BATTLE/BATTLE.PRG/30D14.h"
#include "../ENDING/ENDING.PRG/D4.h"
#include "lbas.h"
#include <libapi.h>
#include <libds.h>
#include <libetc.h>
#include <libpad.h>
#include <libsnd.h>
#include <libspu.h>
#include <libgpu.h>
#include <rand.h>

typedef struct {
    char mode;
    char exId;
    char states;
    char rStickX;
    char rStickY;
    char lStickX;
    char lStickY;
    char lock;
    char actData[2];
    char connected;
} portInfo_t;

typedef struct {
    int unk0[2];
    u_short unk8;
    u_short unkA;
    char* unkC;
    int unk10[10];
} padAct_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
} D_8005DC6C_t;

typedef struct {
    char unk0[6];
    short unk6[5];
    int unk10[6];
    D_8005DC6C_t unk28;
} D_8005DC80_t;

typedef struct {
    u_short unk0;
    u_short unk2;
    char unk4;
    char unk5;
    char unk6[5];
    signed char unkB[3];
    struct ColorInfo {
        char r;
        char g;
        char b;
        char a;
        u_char rindex;
        u_char gindex;
        u_char bindex;
    } unkE[256];
    u_short unk70E[254];
} D_80055D58_t2;

typedef struct {
    D_80055D58_t2 unk0[14];
    char unk7E8C[10];
    short unk7E96[3];
    int unk7E9C[5][6];
    D_8005DC6C_t unk7F14[5];
    D_8005DC80_t unk7F28[17];
} D_80055D58_t;

enum diskState_e {

    diskIdle = 0,
    diskSeekReady = 1,
    diskReadReady = 2,
    diskReadError = 4,
    diskReadInit = 5,
    diskReadXaInit = 6,
    diskStreamXa = 7,
    diskCommandFailed = 8,
    diskStreamXaEnd = 9,
};

enum cdBufferModes_e {
    cdBufferModeNone = 0,
    cdBufferModeBuffered = 1,
    cdBufferModeManual = 2,
};

typedef struct {
    char state;
    char unk1;
    char unk2;
    char unk3;
    u_int unk4;
    u_int sectorCount;
    int cdSector;
    int byteCount;
    void* vram;
    DslFILTER pcm;
    DslLOC cdLoc;
    int commandId;
    int unk24;
    int unk28;
    enum cdBufferModes_e bufferMode;
    u_int sectorBufIndex;
    int unk34;
    u_int unk38;
    u_int unk3C;
    u_int ringBufIndex;
    int framesSinceLastRead;
} vs_main_disk_t;

typedef struct {
    int lStickX;
    int lStickY;
    int rStickX;
    int rStickY;
} vs_main_stickPos;

void __main();
static void _unlockPadModeSwitch();
static void _padResetDefaults(int, char[34]);
static void _padSetActData(int arg0, int arg1, int arg2);
static void _initCdQueue();
static void _diskReset();
static void _processCdQueue();
static int vs_main_processSoundQueue();
static void _loadMenuSound();
static void _asmNop();
static void nop10(int, int);

typedef struct {
    char wLo;
    char wHi;
    char hLo;
    char hHi;
} imgHeader_t;

extern imgHeader_t _nowLoading_header;
extern u_long _nowLoading_data[];

char D_8004A504[]
    = { 1, 0, 0, 0, 8, 0, 0, 0, 7, 6, 0, 4, 1, 0, 0, 1, 17, 8, 2, 6, 255, 0, 0, 0 };
char _actParams[] = { 0, 1, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0 };
int vs_main_titleScreenCount = 0;
int D_8004A52C = 0;
int _soundLBAs[] = { VS_WAVE0000_DAT_LBA, VS_WAVE0001_DAT_LBA, VS_WAVE0002_DAT_LBA,
    VS_WAVE0003_DAT_LBA, VS_WAVE0004_DAT_LBA, VS_WAVE0005_DAT_LBA, VS_WAVE0006_DAT_LBA,
    VS_WAVE0007_DAT_LBA, VS_WAVE0008_DAT_LBA, VS_WAVE0009_DAT_LBA, VS_WAVE0010_DAT_LBA,
    VS_WAVE0011_DAT_LBA, VS_WAVE0012_DAT_LBA, VS_WAVE0013_DAT_LBA, VS_WAVE0014_DAT_LBA,
    VS_WAVE0015_DAT_LBA, VS_WAVE0016_DAT_LBA, VS_WAVE0017_DAT_LBA, VS_WAVE0018_DAT_LBA,
    VS_WAVE0019_DAT_LBA, VS_WAVE0020_DAT_LBA, VS_WAVE0021_DAT_LBA, VS_WAVE0022_DAT_LBA,
    VS_WAVE0023_DAT_LBA, VS_WAVE0024_DAT_LBA, VS_WAVE0025_DAT_LBA, VS_WAVE0026_DAT_LBA,
    VS_WAVE0027_DAT_LBA, VS_WAVE0028_DAT_LBA, VS_WAVE0029_DAT_LBA, VS_WAVE0030_DAT_LBA,
    VS_WAVE0031_DAT_LBA, VS_WAVE0032_DAT_LBA, VS_WAVE0033_DAT_LBA, VS_WAVE0034_DAT_LBA,
    VS_WAVE0035_DAT_LBA, VS_WAVE0036_DAT_LBA, VS_WAVE0037_DAT_LBA, VS_WAVE0038_DAT_LBA,
    VS_WAVE0039_DAT_LBA, VS_WAVE0040_DAT_LBA, VS_WAVE0041_DAT_LBA, VS_WAVE0042_DAT_LBA,
    VS_WAVE0043_DAT_LBA, VS_WAVE0044_DAT_LBA, VS_WAVE0045_DAT_LBA, VS_WAVE0046_DAT_LBA,
    VS_WAVE0047_DAT_LBA, VS_WAVE0048_DAT_LBA, VS_WAVE0049_DAT_LBA, VS_WAVE0050_DAT_LBA,
    VS_WAVE0051_DAT_LBA, VS_WAVE0052_DAT_LBA, VS_WAVE0053_DAT_LBA, VS_WAVE0054_DAT_LBA,
    VS_WAVE0055_DAT_LBA, VS_WAVE0056_DAT_LBA, VS_WAVE0057_DAT_LBA, VS_WAVE0058_DAT_LBA,
    VS_WAVE0059_DAT_LBA, VS_WAVE0060_DAT_LBA, VS_WAVE0061_DAT_LBA, VS_WAVE0062_DAT_LBA,
    VS_WAVE0063_DAT_LBA, VS_WAVE0064_DAT_LBA, VS_WAVE0065_DAT_LBA, VS_WAVE0066_DAT_LBA,
    VS_WAVE0067_DAT_LBA, VS_WAVE0068_DAT_LBA, VS_WAVE0069_DAT_LBA, VS_WAVE0070_DAT_LBA,
    VS_WAVE0071_DAT_LBA, VS_WAVE0072_DAT_LBA, VS_WAVE0073_DAT_LBA, VS_WAVE0074_DAT_LBA,
    VS_WAVE0075_DAT_LBA, VS_WAVE0076_DAT_LBA, VS_WAVE0077_DAT_LBA, VS_WAVE0078_DAT_LBA,
    VS_WAVE0079_DAT_LBA, VS_WAVE0080_DAT_LBA, VS_WAVE0081_DAT_LBA, VS_WAVE0082_DAT_LBA,
    VS_WAVE0083_DAT_LBA, VS_WAVE0084_DAT_LBA, VS_WAVE0085_DAT_LBA, VS_WAVE0086_DAT_LBA,
    VS_WAVE0087_DAT_LBA, VS_WAVE0088_DAT_LBA, VS_WAVE0089_DAT_LBA, VS_WAVE0090_DAT_LBA,
    VS_WAVE0091_DAT_LBA, VS_WAVE0092_DAT_LBA, VS_WAVE0093_DAT_LBA, VS_WAVE0094_DAT_LBA,
    VS_WAVE0095_DAT_LBA, VS_WAVE0096_DAT_LBA, VS_WAVE0097_DAT_LBA, VS_WAVE0098_DAT_LBA,
    VS_WAVE0099_DAT_LBA };
int _musicLBAs[] = { VS_MUSIC000_DAT_LBA, VS_MUSIC001_DAT_LBA, VS_MUSIC002_DAT_LBA,
    VS_MUSIC003_DAT_LBA, VS_MUSIC004_DAT_LBA, VS_MUSIC005_DAT_LBA, VS_MUSIC006_DAT_LBA,
    VS_MUSIC007_DAT_LBA, VS_MUSIC008_DAT_LBA, VS_MUSIC009_DAT_LBA, VS_MUSIC010_DAT_LBA,
    VS_MUSIC011_DAT_LBA, VS_MUSIC012_DAT_LBA, VS_MUSIC013_DAT_LBA, VS_MUSIC014_DAT_LBA,
    VS_MUSIC015_DAT_LBA, VS_MUSIC016_DAT_LBA, VS_MUSIC017_DAT_LBA, VS_MUSIC018_DAT_LBA,
    VS_MUSIC019_DAT_LBA, VS_MUSIC020_DAT_LBA, VS_MUSIC021_DAT_LBA, VS_MUSIC022_DAT_LBA,
    VS_MUSIC023_DAT_LBA, VS_MUSIC024_DAT_LBA, VS_MUSIC025_DAT_LBA, VS_MUSIC026_DAT_LBA,
    VS_MUSIC027_DAT_LBA, VS_MUSIC028_DAT_LBA, VS_MUSIC029_DAT_LBA, VS_MUSIC030_DAT_LBA,
    VS_MUSIC031_DAT_LBA, VS_MUSIC032_DAT_LBA, VS_MUSIC033_DAT_LBA, VS_MUSIC034_DAT_LBA,
    VS_MUSIC035_DAT_LBA, VS_MUSIC036_DAT_LBA, VS_MUSIC037_DAT_LBA, VS_MUSIC038_DAT_LBA,
    VS_MUSIC039_DAT_LBA, VS_MUSIC040_DAT_LBA, VS_MUSIC041_DAT_LBA, VS_MUSIC042_DAT_LBA,
    VS_MUSIC043_DAT_LBA, VS_MUSIC044_DAT_LBA, VS_MUSIC045_DAT_LBA, VS_MUSIC046_DAT_LBA,
    VS_MUSIC047_DAT_LBA, VS_MUSIC048_DAT_LBA, VS_MUSIC049_DAT_LBA, VS_MUSIC050_DAT_LBA,
    VS_MUSIC051_DAT_LBA, VS_MUSIC052_DAT_LBA, VS_MUSIC053_DAT_LBA, VS_MUSIC054_DAT_LBA,
    VS_MUSIC055_DAT_LBA, VS_MUSIC056_DAT_LBA, VS_MUSIC057_DAT_LBA, VS_MUSIC058_DAT_LBA,
    VS_MUSIC059_DAT_LBA, VS_MUSIC060_DAT_LBA, VS_MUSIC061_DAT_LBA, VS_MUSIC062_DAT_LBA,
    VS_MUSIC063_DAT_LBA, VS_MUSIC064_DAT_LBA, VS_MUSIC065_DAT_LBA, VS_MUSIC066_DAT_LBA,
    VS_MUSIC067_DAT_LBA, VS_MUSIC068_DAT_LBA, VS_MUSIC069_DAT_LBA, VS_MUSIC070_DAT_LBA,
    VS_MUSIC071_DAT_LBA, VS_MUSIC072_DAT_LBA, VS_MUSIC073_DAT_LBA, VS_MUSIC074_DAT_LBA,
    VS_MUSIC075_DAT_LBA, VS_MUSIC076_DAT_LBA, VS_MUSIC077_DAT_LBA, VS_MUSIC078_DAT_LBA,
    VS_MUSIC079_DAT_LBA, VS_MUSIC080_DAT_LBA, VS_MUSIC081_DAT_LBA, VS_MUSIC082_DAT_LBA,
    VS_MUSIC083_DAT_LBA, VS_MUSIC084_DAT_LBA, VS_MUSIC085_DAT_LBA, VS_MUSIC086_DAT_LBA,
    VS_MUSIC087_DAT_LBA, VS_MUSIC088_DAT_LBA, VS_MUSIC089_DAT_LBA, VS_MUSIC090_DAT_LBA,
    VS_MUSIC091_DAT_LBA, VS_MUSIC092_DAT_LBA, VS_MUSIC093_DAT_LBA, VS_MUSIC094_DAT_LBA,
    VS_MUSIC095_DAT_LBA, VS_MUSIC096_DAT_LBA, VS_MUSIC097_DAT_LBA, VS_MUSIC098_DAT_LBA,
    VS_MUSIC099_DAT_LBA, VS_MUSIC100_DAT_LBA, VS_MUSIC101_DAT_LBA, VS_MUSIC100_DAT_LBA,
    VS_MUSIC100_DAT_LBA, VS_MUSIC100_DAT_LBA, VS_MUSIC100_DAT_LBA, VS_MUSIC100_DAT_LBA,
    VS_MUSIC100_DAT_LBA, VS_MUSIC100_DAT_LBA, VS_MUSIC100_DAT_LBA, VS_MUSIC110_DAT_LBA,
    VS_MUSIC111_DAT_LBA, VS_MUSIC112_DAT_LBA, VS_MUSIC113_DAT_LBA, VS_MUSIC114_DAT_LBA,
    VS_MUSIC115_DAT_LBA, VS_MUSIC116_DAT_LBA, VS_MUSIC117_DAT_LBA, VS_MUSIC118_DAT_LBA,
    VS_MUSIC119_DAT_LBA, VS_MUSIC120_DAT_LBA, VS_MUSIC121_DAT_LBA, VS_MUSIC122_DAT_LBA,
    VS_MUSIC123_DAT_LBA, VS_MUSIC124_DAT_LBA, VS_MUSIC125_DAT_LBA, VS_MUSIC126_DAT_LBA,
    VS_MUSIC127_DAT_LBA, VS_MUSIC128_DAT_LBA, VS_MUSIC129_DAT_LBA, VS_MUSIC130_DAT_LBA,
    VS_MUSIC131_DAT_LBA, VS_MUSIC132_DAT_LBA, VS_MUSIC133_DAT_LBA, VS_MUSIC134_DAT_LBA,
    VS_MUSIC135_DAT_LBA, VS_MUSIC136_DAT_LBA, VS_MUSIC137_DAT_LBA, VS_MUSIC138_DAT_LBA,
    VS_MUSIC139_DAT_LBA, VS_MUSIC140_DAT_LBA, VS_MUSIC141_DAT_LBA, VS_MUSIC142_DAT_LBA,
    VS_MUSIC143_DAT_LBA, VS_MUSIC144_DAT_LBA, VS_MUSIC145_DAT_LBA, VS_MUSIC146_DAT_LBA,
    VS_MUSIC147_DAT_LBA, VS_MUSIC148_DAT_LBA, VS_MUSIC149_DAT_LBA, VS_MUSIC150_DAT_LBA,
    VS_MUSIC151_DAT_LBA, VS_MUSIC152_DAT_LBA, VS_MUSIC153_DAT_LBA, VS_MUSIC154_DAT_LBA,
    VS_MUSIC155_DAT_LBA, VS_MUSIC156_DAT_LBA, VS_MUSIC157_DAT_LBA, VS_MUSIC158_DAT_LBA,
    VS_MUSIC159_DAT_LBA, VS_MUSIC160_DAT_LBA, VS_MUSIC161_DAT_LBA, VS_MUSIC162_DAT_LBA,
    VS_MUSIC163_DAT_LBA, VS_MUSIC164_DAT_LBA, VS_MUSIC165_DAT_LBA, VS_MUSIC166_DAT_LBA,
    VS_MUSIC167_DAT_LBA, VS_MUSIC168_DAT_LBA, VS_MUSIC169_DAT_LBA, VS_MUSIC170_DAT_LBA,
    VS_MUSIC171_DAT_LBA, VS_MUSIC172_DAT_LBA, VS_MUSIC173_DAT_LBA, VS_MUSIC174_DAT_LBA,
    VS_MUSIC175_DAT_LBA, VS_MUSIC176_DAT_LBA, VS_MUSIC177_DAT_LBA, VS_MUSIC178_DAT_LBA,
    VS_MUSIC179_DAT_LBA, VS_MUSIC180_DAT_LBA, VS_MUSIC181_DAT_LBA, VS_MUSIC182_DAT_LBA,
    VS_MUSIC183_DAT_LBA, VS_MUSIC184_DAT_LBA, VS_MUSIC185_DAT_LBA, VS_MUSIC186_DAT_LBA,
    VS_MUSIC187_DAT_LBA, VS_MUSIC188_DAT_LBA, VS_MUSIC189_DAT_LBA, VS_MUSIC190_DAT_LBA,
    VS_MUSIC191_DAT_LBA, VS_MUSIC192_DAT_LBA, VS_MUSIC193_DAT_LBA, VS_MUSIC194_DAT_LBA,
    VS_MUSIC195_DAT_LBA, VS_MUSIC196_DAT_LBA, VS_MUSIC197_DAT_LBA, VS_MUSIC198_DAT_LBA,
    VS_MUSIC199_DAT_LBA };
int _seLBAs[] = { VS_SEP00000_DAT_LBA, VS_SEP00001_DAT_LBA, VS_SEP00002_DAT_LBA,
    VS_SEP00003_DAT_LBA, VS_SEP00004_DAT_LBA, VS_SEP00005_DAT_LBA, VS_SEP00006_DAT_LBA,
    VS_SEP00007_DAT_LBA, VS_SEP00008_DAT_LBA, VS_SEP00009_DAT_LBA, VS_SEP00010_DAT_LBA,
    VS_SEP00011_DAT_LBA, VS_SEP00012_DAT_LBA, VS_SEP00013_DAT_LBA, VS_SEP00014_DAT_LBA,
    VS_SEP00015_DAT_LBA, VS_SEP00016_DAT_LBA, VS_SEP00017_DAT_LBA, VS_SEP00018_DAT_LBA,
    VS_SEP00019_DAT_LBA, VS_SEP00020_DAT_LBA, VS_SEP00021_DAT_LBA, VS_SEP00022_DAT_LBA,
    VS_SEP00023_DAT_LBA, VS_SEP00024_DAT_LBA, VS_SEP00025_DAT_LBA, VS_SEP00026_DAT_LBA,
    VS_SEP00027_DAT_LBA, VS_SEP00028_DAT_LBA, VS_SEP00029_DAT_LBA, VS_SEP00030_DAT_LBA,
    VS_SEP00031_DAT_LBA, VS_SEP00032_DAT_LBA, VS_SEP00033_DAT_LBA, VS_SEP00034_DAT_LBA,
    VS_SEP00035_DAT_LBA, VS_SEP00036_DAT_LBA, VS_SEP00037_DAT_LBA, VS_SEP00038_DAT_LBA,
    VS_SEP00039_DAT_LBA, VS_SEP00040_DAT_LBA, VS_SEP00041_DAT_LBA, VS_SEP00042_DAT_LBA,
    VS_SEP00043_DAT_LBA, VS_SEP00044_DAT_LBA, VS_SEP00045_DAT_LBA, VS_SEP00046_DAT_LBA,
    VS_SEP00047_DAT_LBA, VS_SEP00048_DAT_LBA, VS_SEP00049_DAT_LBA, VS_SEP00050_DAT_LBA,
    VS_SEP00051_DAT_LBA, VS_SEP00052_DAT_LBA, VS_SEP00053_DAT_LBA, VS_SEP00054_DAT_LBA,
    VS_SEP00055_DAT_LBA, VS_SEP00056_DAT_LBA, VS_SEP00057_DAT_LBA, VS_SEP00058_DAT_LBA,
    VS_SEP00059_DAT_LBA, VS_SEP00060_DAT_LBA, VS_SEP00061_DAT_LBA, VS_SEP00062_DAT_LBA,
    VS_SEP00063_DAT_LBA, VS_SEP00064_DAT_LBA, VS_SEP00065_DAT_LBA, VS_SEP00066_DAT_LBA,
    VS_SEP00067_DAT_LBA, VS_SEP00068_DAT_LBA, VS_SEP00069_DAT_LBA, VS_SEP00070_DAT_LBA,
    VS_SEP00071_DAT_LBA, VS_SEP00072_DAT_LBA, VS_SEP00073_DAT_LBA, VS_SEP00074_DAT_LBA,
    VS_SEP00075_DAT_LBA, VS_SEP00076_DAT_LBA, VS_SEP00077_DAT_LBA, VS_SEP00078_DAT_LBA,
    VS_SEP00079_DAT_LBA, VS_SEP00080_DAT_LBA, VS_SEP00081_DAT_LBA, VS_SEP00082_DAT_LBA,
    VS_SEP00083_DAT_LBA, VS_SEP00084_DAT_LBA, VS_SEP00085_DAT_LBA, VS_SEP00086_DAT_LBA,
    VS_SEP00087_DAT_LBA, VS_SEP00088_DAT_LBA, VS_SEP00089_DAT_LBA, VS_SEP00090_DAT_LBA,
    VS_SEP00091_DAT_LBA, VS_SEP00092_DAT_LBA, VS_SEP00093_DAT_LBA, VS_SEP00094_DAT_LBA,
    VS_SEP00095_DAT_LBA, VS_SEP00096_DAT_LBA, VS_SEP00097_DAT_LBA, VS_SEP00098_DAT_LBA,
    VS_SEP00099_DAT_LBA };
int _soundFileSizes[] = { VS_WAVE0000_DAT_SIZE, VS_WAVE0001_DAT_SIZE,
    VS_WAVE0002_DAT_SIZE, VS_WAVE0003_DAT_SIZE, VS_WAVE0004_DAT_SIZE,
    VS_WAVE0005_DAT_SIZE, VS_WAVE0006_DAT_SIZE, VS_WAVE0007_DAT_SIZE,
    VS_WAVE0008_DAT_SIZE, VS_WAVE0009_DAT_SIZE, VS_WAVE0010_DAT_SIZE,
    VS_WAVE0011_DAT_SIZE, VS_WAVE0012_DAT_SIZE, VS_WAVE0013_DAT_SIZE,
    VS_WAVE0014_DAT_SIZE, VS_WAVE0015_DAT_SIZE, VS_WAVE0016_DAT_SIZE,
    VS_WAVE0017_DAT_SIZE, VS_WAVE0018_DAT_SIZE, VS_WAVE0019_DAT_SIZE,
    VS_WAVE0020_DAT_SIZE, VS_WAVE0021_DAT_SIZE, VS_WAVE0022_DAT_SIZE,
    VS_WAVE0023_DAT_SIZE, VS_WAVE0024_DAT_SIZE, VS_WAVE0025_DAT_SIZE,
    VS_WAVE0026_DAT_SIZE, VS_WAVE0027_DAT_SIZE, VS_WAVE0028_DAT_SIZE,
    VS_WAVE0029_DAT_SIZE, VS_WAVE0030_DAT_SIZE, VS_WAVE0031_DAT_SIZE,
    VS_WAVE0032_DAT_SIZE, VS_WAVE0033_DAT_SIZE, VS_WAVE0034_DAT_SIZE,
    VS_WAVE0035_DAT_SIZE, VS_WAVE0036_DAT_SIZE, VS_WAVE0037_DAT_SIZE,
    VS_WAVE0038_DAT_SIZE, VS_WAVE0039_DAT_SIZE, VS_WAVE0040_DAT_SIZE,
    VS_WAVE0041_DAT_SIZE, VS_WAVE0042_DAT_SIZE, VS_WAVE0043_DAT_SIZE,
    VS_WAVE0044_DAT_SIZE, VS_WAVE0045_DAT_SIZE, VS_WAVE0046_DAT_SIZE,
    VS_WAVE0047_DAT_SIZE, VS_WAVE0048_DAT_SIZE, VS_WAVE0049_DAT_SIZE,
    VS_WAVE0050_DAT_SIZE, VS_WAVE0051_DAT_SIZE, VS_WAVE0052_DAT_SIZE,
    VS_WAVE0053_DAT_SIZE, VS_WAVE0054_DAT_SIZE, VS_WAVE0055_DAT_SIZE,
    VS_WAVE0056_DAT_SIZE, VS_WAVE0057_DAT_SIZE, VS_WAVE0058_DAT_SIZE,
    VS_WAVE0059_DAT_SIZE, VS_WAVE0060_DAT_SIZE, VS_WAVE0061_DAT_SIZE,
    VS_WAVE0062_DAT_SIZE, VS_WAVE0063_DAT_SIZE, VS_WAVE0064_DAT_SIZE,
    VS_WAVE0065_DAT_SIZE, VS_WAVE0066_DAT_SIZE, VS_WAVE0067_DAT_SIZE,
    VS_WAVE0068_DAT_SIZE, VS_WAVE0069_DAT_SIZE, VS_WAVE0070_DAT_SIZE,
    VS_WAVE0071_DAT_SIZE, VS_WAVE0072_DAT_SIZE, VS_WAVE0073_DAT_SIZE,
    VS_WAVE0074_DAT_SIZE, VS_WAVE0075_DAT_SIZE, VS_WAVE0076_DAT_SIZE,
    VS_WAVE0077_DAT_SIZE, VS_WAVE0078_DAT_SIZE, VS_WAVE0079_DAT_SIZE,
    VS_WAVE0080_DAT_SIZE, VS_WAVE0081_DAT_SIZE, VS_WAVE0082_DAT_SIZE,
    VS_WAVE0083_DAT_SIZE, VS_WAVE0084_DAT_SIZE, VS_WAVE0085_DAT_SIZE,
    VS_WAVE0086_DAT_SIZE, VS_WAVE0087_DAT_SIZE, VS_WAVE0088_DAT_SIZE,
    VS_WAVE0089_DAT_SIZE, VS_WAVE0090_DAT_SIZE, VS_WAVE0091_DAT_SIZE,
    VS_WAVE0092_DAT_SIZE, VS_WAVE0093_DAT_SIZE, VS_WAVE0094_DAT_SIZE,
    VS_WAVE0095_DAT_SIZE, VS_WAVE0096_DAT_SIZE, VS_WAVE0097_DAT_SIZE,
    VS_WAVE0098_DAT_SIZE, VS_WAVE0099_DAT_SIZE };
int _musicFileSizes[] = { VS_MUSIC000_DAT_SIZE, VS_MUSIC001_DAT_SIZE,
    VS_MUSIC002_DAT_SIZE, VS_MUSIC003_DAT_SIZE, VS_MUSIC004_DAT_SIZE,
    VS_MUSIC005_DAT_SIZE, VS_MUSIC006_DAT_SIZE, VS_MUSIC007_DAT_SIZE,
    VS_MUSIC008_DAT_SIZE, VS_MUSIC009_DAT_SIZE, VS_MUSIC010_DAT_SIZE,
    VS_MUSIC011_DAT_SIZE, VS_MUSIC012_DAT_SIZE, VS_MUSIC013_DAT_SIZE,
    VS_MUSIC014_DAT_SIZE, VS_MUSIC015_DAT_SIZE, VS_MUSIC016_DAT_SIZE,
    VS_MUSIC017_DAT_SIZE, VS_MUSIC018_DAT_SIZE, VS_MUSIC019_DAT_SIZE,
    VS_MUSIC020_DAT_SIZE, VS_MUSIC021_DAT_SIZE, VS_MUSIC022_DAT_SIZE,
    VS_MUSIC023_DAT_SIZE, VS_MUSIC024_DAT_SIZE, VS_MUSIC025_DAT_SIZE,
    VS_MUSIC026_DAT_SIZE, VS_MUSIC027_DAT_SIZE, VS_MUSIC028_DAT_SIZE,
    VS_MUSIC029_DAT_SIZE, VS_MUSIC030_DAT_SIZE, VS_MUSIC031_DAT_SIZE,
    VS_MUSIC032_DAT_SIZE, VS_MUSIC033_DAT_SIZE, VS_MUSIC034_DAT_SIZE,
    VS_MUSIC035_DAT_SIZE, VS_MUSIC036_DAT_SIZE, VS_MUSIC037_DAT_SIZE,
    VS_MUSIC038_DAT_SIZE, VS_MUSIC039_DAT_SIZE, VS_MUSIC040_DAT_SIZE,
    VS_MUSIC041_DAT_SIZE, VS_MUSIC042_DAT_SIZE, VS_MUSIC043_DAT_SIZE,
    VS_MUSIC044_DAT_SIZE, VS_MUSIC045_DAT_SIZE, VS_MUSIC046_DAT_SIZE,
    VS_MUSIC047_DAT_SIZE, VS_MUSIC048_DAT_SIZE, VS_MUSIC049_DAT_SIZE,
    VS_MUSIC050_DAT_SIZE, VS_MUSIC051_DAT_SIZE, VS_MUSIC052_DAT_SIZE,
    VS_MUSIC053_DAT_SIZE, VS_MUSIC054_DAT_SIZE, VS_MUSIC055_DAT_SIZE,
    VS_MUSIC056_DAT_SIZE, VS_MUSIC057_DAT_SIZE, VS_MUSIC058_DAT_SIZE,
    VS_MUSIC059_DAT_SIZE, VS_MUSIC060_DAT_SIZE, VS_MUSIC061_DAT_SIZE,
    VS_MUSIC062_DAT_SIZE, VS_MUSIC063_DAT_SIZE, VS_MUSIC064_DAT_SIZE,
    VS_MUSIC065_DAT_SIZE, VS_MUSIC066_DAT_SIZE, VS_MUSIC067_DAT_SIZE,
    VS_MUSIC068_DAT_SIZE, VS_MUSIC069_DAT_SIZE, VS_MUSIC070_DAT_SIZE,
    VS_MUSIC071_DAT_SIZE, VS_MUSIC072_DAT_SIZE, VS_MUSIC073_DAT_SIZE,
    VS_MUSIC074_DAT_SIZE, VS_MUSIC075_DAT_SIZE, VS_MUSIC076_DAT_SIZE,
    VS_MUSIC077_DAT_SIZE, VS_MUSIC078_DAT_SIZE, VS_MUSIC079_DAT_SIZE,
    VS_MUSIC080_DAT_SIZE, VS_MUSIC081_DAT_SIZE, VS_MUSIC082_DAT_SIZE,
    VS_MUSIC083_DAT_SIZE, VS_MUSIC084_DAT_SIZE, VS_MUSIC085_DAT_SIZE,
    VS_MUSIC086_DAT_SIZE, VS_MUSIC087_DAT_SIZE, VS_MUSIC088_DAT_SIZE,
    VS_MUSIC089_DAT_SIZE, VS_MUSIC090_DAT_SIZE, VS_MUSIC091_DAT_SIZE,
    VS_MUSIC092_DAT_SIZE, VS_MUSIC093_DAT_SIZE, VS_MUSIC094_DAT_SIZE,
    VS_MUSIC095_DAT_SIZE, VS_MUSIC096_DAT_SIZE, VS_MUSIC097_DAT_SIZE,
    VS_MUSIC098_DAT_SIZE, VS_MUSIC099_DAT_SIZE, VS_MUSIC100_DAT_SIZE,
    VS_MUSIC101_DAT_SIZE, VS_MUSIC100_DAT_SIZE, VS_MUSIC100_DAT_SIZE,
    VS_MUSIC100_DAT_SIZE, VS_MUSIC100_DAT_SIZE, VS_MUSIC100_DAT_SIZE,
    VS_MUSIC100_DAT_SIZE, VS_MUSIC100_DAT_SIZE, VS_MUSIC100_DAT_SIZE,
    VS_MUSIC110_DAT_SIZE, VS_MUSIC111_DAT_SIZE, VS_MUSIC112_DAT_SIZE,
    VS_MUSIC113_DAT_SIZE, VS_MUSIC114_DAT_SIZE, VS_MUSIC115_DAT_SIZE,
    VS_MUSIC116_DAT_SIZE, VS_MUSIC117_DAT_SIZE, VS_MUSIC118_DAT_SIZE,
    VS_MUSIC119_DAT_SIZE, VS_MUSIC120_DAT_SIZE, VS_MUSIC121_DAT_SIZE,
    VS_MUSIC122_DAT_SIZE, VS_MUSIC123_DAT_SIZE, VS_MUSIC124_DAT_SIZE,
    VS_MUSIC125_DAT_SIZE, VS_MUSIC126_DAT_SIZE, VS_MUSIC127_DAT_SIZE,
    VS_MUSIC128_DAT_SIZE, VS_MUSIC129_DAT_SIZE, VS_MUSIC130_DAT_SIZE,
    VS_MUSIC131_DAT_SIZE, VS_MUSIC132_DAT_SIZE, VS_MUSIC133_DAT_SIZE,
    VS_MUSIC134_DAT_SIZE, VS_MUSIC135_DAT_SIZE, VS_MUSIC136_DAT_SIZE,
    VS_MUSIC137_DAT_SIZE, VS_MUSIC138_DAT_SIZE, VS_MUSIC139_DAT_SIZE,
    VS_MUSIC140_DAT_SIZE, VS_MUSIC141_DAT_SIZE, VS_MUSIC142_DAT_SIZE,
    VS_MUSIC143_DAT_SIZE, VS_MUSIC144_DAT_SIZE, VS_MUSIC145_DAT_SIZE,
    VS_MUSIC146_DAT_SIZE, VS_MUSIC147_DAT_SIZE, VS_MUSIC148_DAT_SIZE,
    VS_MUSIC149_DAT_SIZE, VS_MUSIC150_DAT_SIZE, VS_MUSIC151_DAT_SIZE,
    VS_MUSIC152_DAT_SIZE, VS_MUSIC153_DAT_SIZE, VS_MUSIC154_DAT_SIZE,
    VS_MUSIC155_DAT_SIZE, VS_MUSIC156_DAT_SIZE, VS_MUSIC157_DAT_SIZE,
    VS_MUSIC158_DAT_SIZE, VS_MUSIC159_DAT_SIZE, VS_MUSIC160_DAT_SIZE,
    VS_MUSIC161_DAT_SIZE, VS_MUSIC162_DAT_SIZE, VS_MUSIC163_DAT_SIZE,
    VS_MUSIC164_DAT_SIZE, VS_MUSIC165_DAT_SIZE, VS_MUSIC166_DAT_SIZE,
    VS_MUSIC167_DAT_SIZE, VS_MUSIC168_DAT_SIZE, VS_MUSIC169_DAT_SIZE,
    VS_MUSIC170_DAT_SIZE, VS_MUSIC171_DAT_SIZE, VS_MUSIC172_DAT_SIZE,
    VS_MUSIC173_DAT_SIZE, VS_MUSIC174_DAT_SIZE, VS_MUSIC175_DAT_SIZE,
    VS_MUSIC176_DAT_SIZE, VS_MUSIC177_DAT_SIZE, VS_MUSIC178_DAT_SIZE,
    VS_MUSIC179_DAT_SIZE, VS_MUSIC180_DAT_SIZE, VS_MUSIC181_DAT_SIZE,
    VS_MUSIC182_DAT_SIZE, VS_MUSIC183_DAT_SIZE, VS_MUSIC184_DAT_SIZE,
    VS_MUSIC185_DAT_SIZE, VS_MUSIC186_DAT_SIZE, VS_MUSIC187_DAT_SIZE,
    VS_MUSIC188_DAT_SIZE, VS_MUSIC189_DAT_SIZE, VS_MUSIC190_DAT_SIZE,
    VS_MUSIC191_DAT_SIZE, VS_MUSIC192_DAT_SIZE, VS_MUSIC193_DAT_SIZE,
    VS_MUSIC194_DAT_SIZE, VS_MUSIC195_DAT_SIZE, VS_MUSIC196_DAT_SIZE,
    VS_MUSIC197_DAT_SIZE, VS_MUSIC198_DAT_SIZE, VS_MUSIC199_DAT_SIZE };
int _seFileSizes[] = { VS_SEP00000_DAT_SIZE, VS_SEP00001_DAT_SIZE, VS_SEP00002_DAT_SIZE,
    VS_SEP00003_DAT_SIZE, VS_SEP00004_DAT_SIZE, VS_SEP00005_DAT_SIZE,
    VS_SEP00006_DAT_SIZE, VS_SEP00007_DAT_SIZE, VS_SEP00008_DAT_SIZE,
    VS_SEP00009_DAT_SIZE, VS_SEP00010_DAT_SIZE, VS_SEP00011_DAT_SIZE,
    VS_SEP00012_DAT_SIZE, VS_SEP00013_DAT_SIZE, VS_SEP00014_DAT_SIZE,
    VS_SEP00015_DAT_SIZE, VS_SEP00016_DAT_SIZE, VS_SEP00017_DAT_SIZE,
    VS_SEP00018_DAT_SIZE, VS_SEP00019_DAT_SIZE, VS_SEP00020_DAT_SIZE,
    VS_SEP00021_DAT_SIZE, VS_SEP00022_DAT_SIZE, VS_SEP00023_DAT_SIZE,
    VS_SEP00024_DAT_SIZE, VS_SEP00025_DAT_SIZE, VS_SEP00026_DAT_SIZE,
    VS_SEP00027_DAT_SIZE, VS_SEP00028_DAT_SIZE, VS_SEP00029_DAT_SIZE,
    VS_SEP00030_DAT_SIZE, VS_SEP00031_DAT_SIZE, VS_SEP00032_DAT_SIZE,
    VS_SEP00033_DAT_SIZE, VS_SEP00034_DAT_SIZE, VS_SEP00035_DAT_SIZE,
    VS_SEP00036_DAT_SIZE, VS_SEP00037_DAT_SIZE, VS_SEP00038_DAT_SIZE,
    VS_SEP00039_DAT_SIZE, VS_SEP00040_DAT_SIZE, VS_SEP00041_DAT_SIZE,
    VS_SEP00042_DAT_SIZE, VS_SEP00043_DAT_SIZE, VS_SEP00044_DAT_SIZE,
    VS_SEP00045_DAT_SIZE, VS_SEP00046_DAT_SIZE, VS_SEP00047_DAT_SIZE,
    VS_SEP00048_DAT_SIZE, VS_SEP00049_DAT_SIZE, VS_SEP00050_DAT_SIZE,
    VS_SEP00051_DAT_SIZE, VS_SEP00052_DAT_SIZE, VS_SEP00053_DAT_SIZE,
    VS_SEP00054_DAT_SIZE, VS_SEP00055_DAT_SIZE, VS_SEP00056_DAT_SIZE,
    VS_SEP00057_DAT_SIZE, VS_SEP00058_DAT_SIZE, VS_SEP00059_DAT_SIZE,
    VS_SEP00060_DAT_SIZE, VS_SEP00061_DAT_SIZE, VS_SEP00062_DAT_SIZE,
    VS_SEP00063_DAT_SIZE, VS_SEP00064_DAT_SIZE, VS_SEP00065_DAT_SIZE,
    VS_SEP00066_DAT_SIZE, VS_SEP00067_DAT_SIZE, VS_SEP00068_DAT_SIZE,
    VS_SEP00069_DAT_SIZE, VS_SEP00070_DAT_SIZE, VS_SEP00071_DAT_SIZE,
    VS_SEP00072_DAT_SIZE, VS_SEP00073_DAT_SIZE, VS_SEP00074_DAT_SIZE,
    VS_SEP00075_DAT_SIZE, VS_SEP00076_DAT_SIZE, VS_SEP00077_DAT_SIZE,
    VS_SEP00078_DAT_SIZE, VS_SEP00079_DAT_SIZE, VS_SEP00080_DAT_SIZE,
    VS_SEP00081_DAT_SIZE, VS_SEP00082_DAT_SIZE, VS_SEP00083_DAT_SIZE,
    VS_SEP00084_DAT_SIZE, VS_SEP00085_DAT_SIZE, VS_SEP00086_DAT_SIZE,
    VS_SEP00087_DAT_SIZE, VS_SEP00088_DAT_SIZE, VS_SEP00089_DAT_SIZE,
    VS_SEP00090_DAT_SIZE, VS_SEP00091_DAT_SIZE, VS_SEP00092_DAT_SIZE,
    VS_SEP00093_DAT_SIZE, VS_SEP00094_DAT_SIZE, VS_SEP00095_DAT_SIZE,
    VS_SEP00096_DAT_SIZE, VS_SEP00097_DAT_SIZE, VS_SEP00098_DAT_SIZE,
    VS_SEP00099_DAT_SIZE };
char _soundFileMap[] = { 0, 65, 66, 66, 68, 69, 67, 85, 68, 93, 69, 68, 0, 69, 69, 0, 69,
    69, 69, 69, 69, 68, 62, 61, 68, 68, 68, 68, 68, 57, 56, 72, 74, 77, 76, 86, 87, 80,
    88, 55, 70, 81, 70, 73, 75, 78, 89, 90, 79, 84, 10, 10, 10, 10, 11, 11, 11, 11, 12,
    12, 12, 12, 13, 13, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 18, 18, 19, 19,
    19, 19, 20, 20, 21, 21, 21, 21, 22, 22, 22, 22, 23, 23, 23, 23, 24, 24, 25, 25, 25,
    25, 0, 0, 0, 0, 0, 85, 0, 0, 91, 91, 91, 91, 91, 91, 91, 0, 60, 94, 98, 95, 96, 97,
    97, 82, 83, 0, 0, 59, 58, 72, 74, 77, 76, 86, 87, 80, 88, 0, 0, 0, 0, 0, 0, 78, 89,
    90, 79, 84, 0, 99, 99, 99, 99, 92, 64, 64, 64, 54, 53, 53, 53, 53, 53, 63, 63, 63, 52,
    51, 50, 52, 49, 47, 46, 45, 45, 45, 44, 44, 43, 42, 41, 40, 39, 38, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0 };
signed char _animOffset16[][16] = {
    { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 255 },
    { 254, 254, 254, 254, 254, 254, 254, 254, 255, 254, 254, 254, 254, 254, 254, 255 },
    { 254, 254, 254, 254, 254, 255, 254, 254, 254, 254, 255, 254, 254, 254, 254, 255 },
    { 254, 254, 254, 254, 255, 254, 254, 254, 255, 254, 254, 254, 255, 254, 254, 255 },
    { 254, 254, 254, 255, 254, 254, 255, 254, 254, 255, 254, 254, 255, 254, 254, 255 },
    { 254, 254, 255, 254, 254, 255, 254, 254, 255, 254, 255, 254, 254, 255, 254, 255 },
    { 254, 254, 255, 254, 255, 254, 255, 254, 254, 255, 254, 255, 254, 255, 254, 255 },
    { 254, 254, 255, 254, 255, 254, 255, 254, 255, 254, 255, 254, 255, 254, 255, 255 },
    { 254, 255, 254, 255, 254, 255, 254, 255, 255, 254, 255, 254, 255, 254, 255, 255 },
    { 254, 255, 254, 255, 255, 254, 255, 254, 255, 255, 254, 255, 255, 254, 255, 255 },
    { 254, 255, 255, 254, 255, 255, 254, 255, 255, 254, 255, 255, 254, 255, 255, 255 },
    { 254, 255, 255, 254, 255, 255, 255, 254, 255, 255, 255, 254, 255, 255, 255, 255 },
    { 254, 255, 255, 255, 255, 254, 255, 255, 255, 255, 254, 255, 255, 255, 255, 255 },
    { 254, 255, 255, 255, 255, 255, 255, 254, 255, 255, 255, 255, 255, 255, 255, 255 },
    { 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 },
    { 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0 },
    { 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0 },
    { 255, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255, 255, 255, 255, 255, 0 },
    { 255, 255, 255, 255, 255, 0, 255, 255, 255, 255, 0, 255, 255, 255, 255, 0 },
    { 255, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 0 },
    { 255, 255, 255, 0, 255, 255, 0, 255, 255, 0, 255, 255, 0, 255, 255, 0 },
    { 255, 255, 0, 255, 255, 0, 255, 255, 0, 255, 0, 255, 255, 0, 255, 0 },
    { 255, 255, 0, 255, 0, 255, 0, 255, 255, 0, 255, 0, 255, 0, 255, 0 },
    { 255, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 0 },
    { 255, 0, 255, 0, 255, 0, 255, 0, 0, 255, 0, 255, 0, 255, 0, 0 },
    { 255, 0, 255, 0, 0, 255, 0, 255, 0, 0, 255, 0, 0, 255, 0, 0 },
    { 255, 0, 0, 255, 0, 0, 255, 0, 0, 255, 0, 0, 255, 0, 0, 0 },
    { 255, 0, 0, 255, 0, 0, 0, 255, 0, 0, 0, 255, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 255, 0, 0, 0, 0, 255, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
    { 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 },
    { 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1 },
    { 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1 },
    { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
    { 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1 },
    { 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
    { 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
    { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 },
    { 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2 },
    { 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2 },
    { 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2 },
    { 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2 },
    { 1, 1, 2, 1, 1, 2, 1, 2, 1, 1, 2, 1, 1, 2, 1, 2 },
    { 1, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2 },
    { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2 },
    { 1, 2, 1, 2, 1, 2, 1, 2, 2, 1, 2, 1, 2, 1, 2, 2 },
    { 1, 2, 1, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2 },
    { 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2 },
    { 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2 },
    { 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2 },
    { 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2 },
    { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }
};
signed char _animOffset8[][8] = { { 252, 252, 252, 252, 252, 252, 252, 253 },
    { 252, 252, 252, 252, 253, 252, 252, 253 },
    { 252, 252, 253, 252, 252, 253, 252, 253 },
    { 252, 252, 253, 252, 253, 252, 253, 253 },
    { 252, 253, 252, 253, 253, 252, 253, 253 },
    { 252, 253, 253, 252, 253, 253, 253, 253 },
    { 252, 253, 253, 253, 253, 253, 253, 253 },
    { 252, 253, 253, 253, 253, 253, 253, 254 },
    { 253, 253, 253, 253, 253, 253, 253, 254 },
    { 253, 253, 253, 253, 254, 253, 253, 254 },
    { 253, 253, 254, 253, 253, 254, 253, 254 },
    { 253, 253, 254, 253, 254, 253, 254, 254 },
    { 253, 254, 253, 254, 254, 253, 254, 254 },
    { 253, 254, 254, 253, 254, 254, 254, 254 },
    { 253, 254, 254, 254, 254, 254, 254, 254 },
    { 253, 254, 254, 254, 254, 254, 254, 255 },
    { 254, 254, 254, 254, 254, 254, 254, 255 },
    { 254, 254, 254, 254, 255, 254, 254, 255 },
    { 254, 254, 255, 254, 254, 255, 254, 255 },
    { 254, 254, 255, 254, 255, 254, 255, 255 },
    { 254, 255, 254, 255, 255, 254, 255, 255 },
    { 254, 255, 255, 254, 255, 255, 255, 255 },
    { 254, 255, 255, 255, 255, 255, 255, 255 }, { 254, 255, 255, 255, 255, 255, 255, 0 },
    { 255, 255, 255, 255, 255, 255, 255, 0 }, { 255, 255, 255, 255, 0, 255, 255, 0 },
    { 255, 255, 0, 255, 255, 0, 255, 0 }, { 255, 255, 0, 255, 0, 255, 0, 0 },
    { 255, 0, 255, 0, 0, 255, 0, 0 }, { 255, 0, 0, 255, 0, 0, 0, 0 },
    { 255, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0, 0, 0, 1, 0, 0, 0, 1 }, { 0, 0, 1, 0, 0, 1, 0, 1 }, { 0, 1, 0, 1, 0, 1, 0, 1 },
    { 0, 1, 0, 1, 1, 0, 1, 1 }, { 0, 1, 1, 1, 0, 1, 1, 1 }, { 0, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 2 }, { 1, 1, 1, 2, 1, 1, 1, 2 },
    { 1, 1, 2, 1, 1, 2, 1, 2 }, { 1, 2, 1, 2, 1, 2, 1, 2 }, { 1, 2, 1, 2, 2, 1, 2, 2 },
    { 1, 2, 2, 2, 1, 2, 2, 2 }, { 1, 2, 2, 2, 2, 2, 2, 2 }, { 2, 2, 2, 2, 2, 2, 2, 2 },
    { 2, 2, 2, 2, 2, 2, 2, 3 }, { 2, 2, 2, 3, 2, 2, 2, 3 }, { 2, 2, 3, 2, 2, 3, 2, 3 },
    { 2, 3, 2, 3, 2, 3, 2, 3 }, { 2, 3, 2, 3, 3, 2, 3, 3 }, { 2, 3, 3, 3, 2, 3, 3, 3 },
    { 2, 3, 3, 3, 3, 3, 3, 3 }, { 3, 3, 3, 3, 3, 3, 3, 3 }, { 3, 3, 3, 3, 3, 3, 3, 4 },
    { 3, 3, 3, 4, 3, 3, 3, 4 }, { 3, 3, 4, 3, 3, 4, 3, 4 }, { 3, 4, 3, 4, 3, 4, 3, 4 },
    { 3, 4, 3, 4, 4, 3, 4, 4 }, { 3, 4, 4, 4, 3, 4, 4, 4 }, { 3, 4, 4, 4, 4, 4, 4, 4 } };
signed char _animOffset4[][4] = { { 248, 248, 248, 249 }, { 248, 248, 249, 249 },
    { 248, 249, 249, 249 }, { 248, 249, 249, 250 }, { 249, 249, 249, 250 },
    { 249, 249, 250, 250 }, { 249, 250, 250, 250 }, { 249, 250, 250, 251 },
    { 250, 250, 250, 251 }, { 250, 250, 251, 251 }, { 250, 251, 251, 251 },
    { 250, 251, 251, 252 }, { 251, 251, 251, 252 }, { 251, 251, 252, 252 },
    { 251, 252, 252, 252 }, { 251, 252, 252, 253 }, { 252, 252, 252, 253 },
    { 252, 252, 253, 253 }, { 252, 253, 253, 253 }, { 252, 253, 253, 254 },
    { 253, 253, 253, 254 }, { 253, 253, 254, 254 }, { 253, 254, 254, 254 },
    { 253, 254, 254, 255 }, { 254, 254, 254, 255 }, { 254, 254, 255, 255 },
    { 254, 255, 255, 255 }, { 254, 255, 255, 0 }, { 255, 255, 255, 0 },
    { 255, 255, 0, 0 }, { 255, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 1 }, { 0, 1, 0, 1 },
    { 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 2 }, { 1, 2, 1, 2 }, { 1, 2, 2, 2 },
    { 2, 2, 2, 2 }, { 2, 2, 2, 3 }, { 2, 3, 2, 3 }, { 2, 3, 3, 3 }, { 3, 3, 3, 3 },
    { 3, 3, 3, 4 }, { 3, 4, 3, 4 }, { 3, 4, 4, 4 }, { 4, 4, 4, 4 }, { 4, 4, 4, 5 },
    { 4, 5, 4, 5 }, { 4, 5, 5, 5 }, { 5, 5, 5, 5 }, { 5, 5, 5, 6 }, { 5, 6, 5, 6 },
    { 5, 6, 6, 6 }, { 6, 6, 6, 6 }, { 6, 6, 6, 7 }, { 6, 7, 6, 7 }, { 6, 7, 7, 7 },
    { 7, 7, 7, 7 }, { 7, 7, 7, 8 }, { 7, 8, 7, 8 }, { 7, 8, 8, 8 } };
signed char _animOffset2[][2] = { { 240, 241 }, { 240, 242 }, { 241, 242 }, { 241, 243 },
    { 242, 243 }, { 242, 244 }, { 243, 244 }, { 243, 245 }, { 244, 245 }, { 244, 246 },
    { 245, 246 }, { 245, 247 }, { 246, 247 }, { 246, 248 }, { 247, 248 }, { 247, 249 },
    { 248, 249 }, { 248, 250 }, { 249, 250 }, { 249, 251 }, { 250, 251 }, { 250, 252 },
    { 251, 252 }, { 251, 253 }, { 252, 253 }, { 252, 254 }, { 253, 254 }, { 253, 255 },
    { 254, 255 }, { 254, 0 }, { 255, 0 }, { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 },
    { 2, 2 }, { 2, 3 }, { 3, 3 }, { 3, 4 }, { 4, 4 }, { 4, 5 }, { 5, 5 }, { 5, 6 },
    { 6, 6 }, { 6, 7 }, { 7, 7 }, { 7, 8 }, { 8, 8 }, { 8, 9 }, { 9, 9 }, { 9, 10 },
    { 10, 10 }, { 10, 11 }, { 11, 11 }, { 11, 12 }, { 12, 12 }, { 12, 13 }, { 13, 13 },
    { 13, 14 }, { 14, 14 }, { 14, 15 }, { 15, 15 }, { 15, 16 } };

#pragma vsstring(start)
vs_skill_t vs_main_skills[] = { { .id = 0,
                                    .effect = 0,
                                    .unk2_0 = 0,
                                    .type = 0,
                                    .target = 0,
                                    .cost = 0,
                                    .rangeX = 0,
                                    .rangeY = 0,
                                    .rangeZ = 0,
                                    .shape = 0,
                                    .angle = 0,
                                    .aoe = 0,
                                    .flags = 0,
                                    .unk10 = 0,
                                    .hitParams = { { .effect = 0,
                                                       .hitrateFlags = 0,
                                                       .hitrateAdj = 0,
                                                       .damage = 0,
                                                       .mult = 0,
                                                       .type = 0,
                                                       .affinity = 0 },
                                        { .effect = 0,
                                            .hitrateFlags = 0,
                                            .hitrateAdj = 0,
                                            .damage = 0,
                                            .mult = 0,
                                            .type = 0,
                                            .affinity = 0 } },
                                    .name = "untitled\000000000000000000" },
    { .id = 1,
        .effect = 1,
        .unk2_0 = 0,
        .type = 6,
        .target = 14,
        .cost = 255,
        .rangeX = 255,
        .rangeY = 255,
        .rangeZ = 255,
        .shape = 1,
        .angle = 31,
        .aoe = 0,
        .flags = 2152780031u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Normal\000d\000000000000000000" },
    { .id = 2,
        .effect = 1,
        .unk2_0 = 0,
        .type = 5,
        .target = 7,
        .cost = 0,
        .rangeX = 255,
        .rangeY = 255,
        .rangeZ = 255,
        .shape = 1,
        .angle = 31,
        .aoe = 1536,
        .flags = 2689646847u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 2,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Pincer\000d\000000000000000000" },
    { .id = 3,
        .effect = 1,
        .unk2_0 = 0,
        .type = 5,
        .target = 7,
        .cost = 0,
        .rangeX = 255,
        .rangeY = 255,
        .rangeZ = 255,
        .shape = 1,
        .angle = 31,
        .aoe = 1536,
        .flags = 2689646847u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Bite\000r\000d\000000000000000000" },
    { .id = 4,
        .effect = 1,
        .unk2_0 = 0,
        .type = 5,
        .target = 7,
        .cost = 0,
        .rangeX = 255,
        .rangeY = 255,
        .rangeZ = 255,
        .shape = 1,
        .angle = 31,
        .aoe = 2048,
        .flags = 2689646847u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 2,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Bite\000r\000d\000000000000000000" },
    { .id = 5,
        .effect = 1,
        .unk2_0 = 0,
        .type = 5,
        .target = 7,
        .cost = 0,
        .rangeX = 255,
        .rangeY = 255,
        .rangeZ = 255,
        .shape = 1,
        .angle = 31,
        .aoe = 2048,
        .flags = 2684403967u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 2,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Bite\000r\000d\000000000000000000" },
    { .id = 6,
        .effect = 6,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415951872u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 12,
                           .mult = 5,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Death|>6|Vapor\00000000000000" },
    { .id = 7,
        .effect = 7,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415951872u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 12,
                           .mult = 5,
                           .type = 1,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Eruption\000por\00000000000000" },
    { .id = 8,
        .effect = 8,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415951872u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 12,
                           .mult = 5,
                           .type = 1,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Freeze\000n\000por\00000000000000" },
    { .id = 9,
        .effect = 9,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415951872u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 12,
                           .mult = 5,
                           .type = 1,
                           .affinity = 2 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Gust\000e\000n\000por\00000000000000" },
    { .id = 10,
        .effect = 10,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415951872u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 12,
                           .mult = 5,
                           .type = 1,
                           .affinity = 4 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Terra|>6|Thrust\0000000000000" },
    { .id = 11,
        .effect = 11,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415951872u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 12,
                           .mult = 5,
                           .type = 1,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Holy|>6|Light\000t\0000000000000" },
    { .id = 12,
        .effect = 12,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415951872u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 12,
                           .mult = 5,
                           .type = 1,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Diabolos\000ht\000t\0000000000000" },
    { .id = 13,
        .effect = 13,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415951872u,
        .unk10 = 0,
        .hitParams = { { .effect = 16,
                           .hitrateFlags = 23,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Poison|>6|Panel\0000000000000" },
    { .id = 14,
        .effect = 14,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415951872u,
        .unk10 = 0,
        .hitParams = { { .effect = 15,
                           .hitrateFlags = 22,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Paralysis|>6|Panel\0000000000" },
    { .id = 15,
        .effect = 0,
        .unk2_0 = 0,
        .type = 0,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268435456,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000|>6|Panel\0000000000" },
    { .id = 16,
        .effect = 0,
        .unk2_0 = 0,
        .type = 0,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268435456,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000|>6|Panel\0000000000" },
    { .id = 17,
        .effect = 17,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415951872u,
        .unk10 = 0,
        .hitParams = { { .effect = 18,
                           .hitrateFlags = 25,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Curse|>6|Panel\000nel\0000000000" },
    { .id = 18,
        .effect = 18,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 1476427776u,
        .unk10 = 0,
        .hitParams = { { .effect = 62,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 14,
                           .mult = 5,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 66,
                .hitrateFlags = 2,
                .hitrateAdj = 2,
                .damage = 26,
                .mult = 0,
                .type = 0,
                .affinity = 6 } },
        .name = "Heal|>6|Panel\000\000nel\0000000000" },
    { .id = 19,
        .effect = 19,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 1375764480u,
        .unk10 = 0,
        .hitParams = { { .effect = 32,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 29,
                .hitrateFlags = 2,
                .hitrateAdj = 2,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Cure|>6|Panel\000\000nel\0000000000" },
    { .id = 20,
        .effect = 20,
        .unk2_0 = 0,
        .type = 0,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268435456,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000el\000\000nel\0000000000" },
    { .id = 21,
        .effect = 21,
        .unk2_0 = 0,
        .type = 7,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268468224,
        .unk10 = 0,
        .hitParams = { { .effect = 38,
                           .hitrateFlags = 6,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Trap|>6|Clear\000\000nel\0000000000" },
    { .id = 22,
        .effect = 22,
        .unk2_0 = 0,
        .type = 2,
        .target = 14,
        .cost = 1,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 7,
                           .damage = 4,
                           .mult = 7,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Heavy|>6|Shot\000\000nel\0000000000" },
    { .id = 23,
        .effect = 23,
        .unk2_0 = 0,
        .type = 2,
        .target = 14,
        .cost = 2,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268435456,
        .unk10 = 0,
        .hitParams = { { .effect = 62,
                           .hitrateFlags = 3,
                           .hitrateAdj = 7,
                           .damage = 18,
                           .mult = 3,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Gain|>6|Life\000\000\000nel\0000000000" },
    { .id = 24,
        .effect = 24,
        .unk2_0 = 0,
        .type = 2,
        .target = 14,
        .cost = 1,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 59,
                           .hitrateFlags = 2,
                           .hitrateAdj = 7,
                           .damage = 4,
                           .mult = 3,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Mind|>6|Assault\000el\0000000000" },
    { .id = 25,
        .effect = 25,
        .unk2_0 = 0,
        .type = 2,
        .target = 14,
        .cost = 2,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268435456,
        .unk10 = 0,
        .hitParams = { { .effect = 63,
                           .hitrateFlags = 3,
                           .hitrateAdj = 7,
                           .damage = 18,
                           .mult = 3,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Gain|>6|Magic\000t\000el\0000000000" },
    { .id = 26,
        .effect = 26,
        .unk2_0 = 0,
        .type = 2,
        .target = 14,
        .cost = 1,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 7,
                           .damage = 5,
                           .mult = 1,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Raging|>6|Ache\000\000el\0000000000" },
    { .id = 27,
        .effect = 27,
        .unk2_0 = 0,
        .type = 2,
        .target = 14,
        .cost = 1,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 59,
                           .hitrateFlags = 2,
                           .hitrateAdj = 7,
                           .damage = 11,
                           .mult = 2,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Mind|>6|Ache\000e\000\000el\0000000000" },
    { .id = 28,
        .effect = 28,
        .unk2_0 = 0,
        .type = 2,
        .target = 14,
        .cost = 2,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 7,
                           .damage = 4,
                           .mult = 4,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 65,
                .hitrateFlags = 3,
                .hitrateAdj = 2,
                .damage = 18,
                .mult = 20,
                .type = 0,
                .affinity = 0 } },
        .name = "Temper\000che\000e\000\000el\0000000000" },
    { .id = 29,
        .effect = 29,
        .unk2_0 = 0,
        .type = 2,
        .target = 14,
        .cost = 2,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 7,
                           .damage = 6,
                           .mult = 10,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 58,
                .hitrateFlags = 3,
                .hitrateAdj = 2,
                .damage = 6,
                .mult = 3,
                .type = 0,
                .affinity = 0 } },
        .name = "Crimson|>6|Pain\000el\0000000000" },
    { .id = 30,
        .effect = 30,
        .unk2_0 = 0,
        .type = 2,
        .target = 14,
        .cost = 1,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 7,
                           .damage = 4,
                           .mult = 1,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 64,
                .hitrateFlags = 3,
                .hitrateAdj = 2,
                .damage = 4,
                .mult = 10,
                .type = 0,
                .affinity = 0 } },
        .name = "Instill\0006Pain\000el\0000000000" },
    { .id = 31,
        .effect = 31,
        .unk2_0 = 0,
        .type = 2,
        .target = 14,
        .cost = 3,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 7,
                           .damage = 8,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 60,
                .hitrateFlags = 3,
                .hitrateAdj = 2,
                .damage = 1,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Phantom|>6|Pain\000el\0000000000" },
    { .id = 32,
        .effect = 32,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 3,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 15,
                           .hitrateFlags = 22,
                           .hitrateAdj = 7,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Paralysis|>6|Pulse\0000000000" },
    { .id = 33,
        .effect = 0,
        .unk2_0 = 0,
        .type = 0,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268435456,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000|>6|Pulse\0000000000" },
    { .id = 34,
        .effect = 34,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 3,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 17,
                           .hitrateFlags = 24,
                           .hitrateAdj = 7,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Numbing|>6|Claw\000se\0000000000" },
    { .id = 35,
        .effect = 35,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 3,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 11,
                           .hitrateFlags = 19,
                           .hitrateAdj = 7,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Dulling|>6|Impact\000\0000000000" },
    { .id = 36,
        .effect = 0,
        .unk2_0 = 0,
        .type = 0,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268435456,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000Impact\000\0000000000" },
    { .id = 37,
        .effect = 37,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 3,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 16,
                           .hitrateFlags = 23,
                           .hitrateAdj = 7,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Snake|>6|Venom\000ct\000\0000000000" },
    { .id = 38,
        .effect = 0,
        .unk2_0 = 0,
        .type = 0,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268435456,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000nom\000ct\000\0000000000" },
    { .id = 39,
        .effect = 0,
        .unk2_0 = 0,
        .type = 0,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268435456,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000nom\000ct\000\0000000000" },
    { .id = 40,
        .effect = 40,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 1,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 1375735808u,
        .unk10 = 0,
        .hitParams = { { .effect = 27,
                           .hitrateFlags = 3,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 30,
                .hitrateFlags = 3,
                .hitrateAdj = 2,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Ward\000led\000nom\000ct\000\0000000000" },
    { .id = 41,
        .effect = 41,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 6,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 63,
                           .hitrateFlags = 3,
                           .hitrateAdj = 2,
                           .damage = 21,
                           .mult = 5,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Siphon|>6|Soul\000ct\000\0000000000" },
    { .id = 42,
        .effect = 42,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 2,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 9,
                           .mult = 4,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Reflect|>6|Magic\000\000\0000000000" },
    { .id = 43,
        .effect = 43,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 2,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 10,
                           .mult = 4,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Reflect|>6|Damage\000\0000000000" },
    { .id = 44,
        .effect = 44,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 4,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 40,
                           .hitrateFlags = 3,
                           .hitrateAdj = 2,
                           .damage = 19,
                           .mult = 2,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Absorb|>6|Magic\000e\000\0000000000" },
    { .id = 45,
        .effect = 45,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 4,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 41,
                           .hitrateFlags = 3,
                           .hitrateAdj = 2,
                           .damage = 20,
                           .mult = 2,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Absorb|>6|Damage\000\000\0000000000" },
    { .id = 46,
        .effect = 46,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 4,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 42,
                           .hitrateFlags = 3,
                           .hitrateAdj = 2,
                           .damage = 22,
                           .mult = 5,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Impact|>6|Guard\000\000\000\0000000000" },
    { .id = 47,
        .effect = 47,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 4,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 43,
                           .hitrateFlags = 3,
                           .hitrateAdj = 2,
                           .damage = 22,
                           .mult = 5,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Windbreak\000ard\000\000\000\0000000000" },
    { .id = 48,
        .effect = 48,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 4,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 44,
                           .hitrateFlags = 3,
                           .hitrateAdj = 2,
                           .damage = 22,
                           .mult = 5,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Fireproof\000ard\000\000\000\0000000000" },
    { .id = 49,
        .effect = 49,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 4,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 45,
                           .hitrateFlags = 3,
                           .hitrateAdj = 2,
                           .damage = 22,
                           .mult = 5,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Terra|>6|Ward\000d\000\000\000\0000000000" },
    { .id = 50,
        .effect = 50,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 4,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 46,
                           .hitrateFlags = 3,
                           .hitrateAdj = 2,
                           .damage = 22,
                           .mult = 5,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Aqua|>6|Ward\000\000d\000\000\000\0000000000" },
    { .id = 51,
        .effect = 51,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 4,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 47,
                           .hitrateFlags = 3,
                           .hitrateAdj = 2,
                           .damage = 22,
                           .mult = 5,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Shadow|>6|Guard\000\000\000\0000000000" },
    { .id = 52,
        .effect = 52,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 4,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 48,
                           .hitrateFlags = 3,
                           .hitrateAdj = 2,
                           .damage = 22,
                           .mult = 5,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Demonscale\000rd\000\000\000\0000000000" },
    { .id = 53,
        .effect = 53,
        .unk2_0 = 0,
        .type = 2,
        .target = 0,
        .cost = 6,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 49,
                           .hitrateFlags = 3,
                           .hitrateAdj = 2,
                           .damage = 23,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 61,
                .hitrateFlags = 3,
                .hitrateAdj = 2,
                .damage = 1,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Phantom|>6|Shield\000\0000000000" },
    { .id = 54,
        .effect = 1,
        .unk2_0 = 1,
        .type = 1,
        .target = 3,
        .cost = 7,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 1,
                           .hitrateFlags = 9,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Degenerate\000ield\000\0000000000" },
    { .id = 55,
        .effect = 2,
        .unk2_0 = 1,
        .type = 1,
        .target = 3,
        .cost = 7,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 2,
                           .hitrateFlags = 10,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Psychodrain\000eld\000\0000000000" },
    { .id = 56,
        .effect = 3,
        .unk2_0 = 1,
        .type = 1,
        .target = 3,
        .cost = 7,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 3,
                           .hitrateFlags = 11,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Leadbones\000n\000eld\000\0000000000" },
    { .id = 57,
        .effect = 4,
        .unk2_0 = 1,
        .type = 1,
        .target = 3,
        .cost = 7,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 4,
                           .hitrateFlags = 12,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Tarnish\000s\000n\000eld\000\0000000000" },
    { .id = 58,
        .effect = 5,
        .unk2_0 = 1,
        .type = 1,
        .target = 3,
        .cost = 5,
        .rangeX = 8,
        .rangeY = 20,
        .rangeZ = 8,
        .shape = 3,
        .angle = 24,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 14,
                           .hitrateFlags = 34,
                           .hitrateAdj = 6,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Analyze\000s\000n\000eld\000\0000000000" },
    { .id = 59,
        .effect = 6,
        .unk2_0 = 1,
        .type = 0,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000\000n\000eld\000\0000000000" },
    { .id = 60,
        .effect = 7,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 12,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1358958592u,
        .unk10 = 0,
        .hitParams = { { .effect = 6,
                           .hitrateFlags = 14,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Herakles\000\000n\000eld\000\0000000000" },
    { .id = 61,
        .effect = 8,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 12,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1358958592u,
        .unk10 = 0,
        .hitParams = { { .effect = 7,
                           .hitrateFlags = 15,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Enlighten\000n\000eld\000\0000000000" },
    { .id = 62,
        .effect = 9,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 12,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1358958592u,
        .unk10 = 0,
        .hitParams = { { .effect = 8,
                           .hitrateFlags = 16,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Invigorate\000\000eld\000\0000000000" },
    { .id = 63,
        .effect = 10,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 15,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1358958592u,
        .unk10 = 0,
        .hitParams = { { .effect = 9,
                           .hitrateFlags = 17,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Prostasia\000\000\000eld\000\0000000000" },
    { .id = 64,
        .effect = 11,
        .unk2_0 = 1,
        .type = 0,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268435456,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000\000\000\000eld\000\0000000000" },
    { .id = 65,
        .effect = 43,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 5,
        .rangeX = 32,
        .rangeY = 20,
        .rangeZ = 32,
        .shape = 2,
        .angle = 0,
        .aoe = 0,
        .flags = 1358958592u,
        .unk10 = 0,
        .hitParams = { { .effect = 62,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 13,
                           .mult = 5,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 58,
                .hitrateFlags = 4,
                .hitrateAdj = 5,
                .damage = 3,
                .mult = 0,
                .type = 0,
                .affinity = 6 } },
        .name = "Heal\000led\000\000\000\000eld\000\0000000000" },
    { .id = 66,
        .effect = 15,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 10,
        .rangeX = 7,
        .rangeY = 4,
        .rangeZ = 7,
        .shape = 2,
        .angle = 0,
        .aoe = 0,
        .flags = 270536704,
        .unk10 = 0,
        .hitParams = { { .effect = 19,
                           .hitrateFlags = 26,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 2 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Luft|>6|Fusion\000ld\000\0000000000" },
    { .id = 67,
        .effect = 14,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 10,
        .rangeX = 7,
        .rangeY = 4,
        .rangeZ = 7,
        .shape = 2,
        .angle = 0,
        .aoe = 0,
        .flags = 270536704,
        .unk10 = 0,
        .hitParams = { { .effect = 20,
                           .hitrateFlags = 27,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Spark|>6|Fusion\000d\000\0000000000" },
    { .id = 68,
        .effect = 13,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 10,
        .rangeX = 7,
        .rangeY = 4,
        .rangeZ = 7,
        .shape = 2,
        .angle = 0,
        .aoe = 0,
        .flags = 270536704,
        .unk10 = 0,
        .hitParams = { { .effect = 21,
                           .hitrateFlags = 28,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 4 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Soil|>6|Fusion\000\000d\000\0000000000" },
    { .id = 69,
        .effect = 16,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 10,
        .rangeX = 7,
        .rangeY = 4,
        .rangeZ = 7,
        .shape = 2,
        .angle = 0,
        .aoe = 0,
        .flags = 270536704,
        .unk10 = 0,
        .hitParams = { { .effect = 22,
                           .hitrateFlags = 29,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Frost|>6|Fusion\000d\000\0000000000" },
    { .id = 70,
        .effect = 19,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 9,
        .rangeX = 7,
        .rangeY = 4,
        .rangeZ = 7,
        .shape = 2,
        .angle = 0,
        .aoe = 0,
        .flags = 270536704,
        .unk10 = 0,
        .hitParams = { { .effect = 23,
                           .hitrateFlags = 30,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 2 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Aero|>6|Guard\000n\000d\000\0000000000" },
    { .id = 71,
        .effect = 18,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 9,
        .rangeX = 7,
        .rangeY = 4,
        .rangeZ = 7,
        .shape = 2,
        .angle = 0,
        .aoe = 0,
        .flags = 270536704,
        .unk10 = 0,
        .hitParams = { { .effect = 24,
                           .hitrateFlags = 31,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Pyro|>6|Guard\000n\000d\000\0000000000" },
    { .id = 72,
        .effect = 17,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 9,
        .rangeX = 7,
        .rangeY = 4,
        .rangeZ = 7,
        .shape = 2,
        .angle = 0,
        .aoe = 0,
        .flags = 270536704,
        .unk10 = 0,
        .hitParams = { { .effect = 25,
                           .hitrateFlags = 32,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 4 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Terra|>6|Guard\000\000d\000\0000000000" },
    { .id = 73,
        .effect = 20,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 9,
        .rangeX = 7,
        .rangeY = 4,
        .rangeZ = 7,
        .shape = 2,
        .angle = 0,
        .aoe = 0,
        .flags = 270536704,
        .unk10 = 0,
        .hitParams = { { .effect = 26,
                           .hitrateFlags = 33,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Aqua|>6|Guard\000\000\000d\000\0000000000" },
    { .id = 74,
        .effect = 50,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 28,
        .rangeX = 18,
        .rangeY = 15,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2151694336u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 4,
                           .type = 1,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Dark|>6|Chant\000\000\000d\000\0000000000" },
    { .id = 75,
        .effect = 22,
        .unk2_0 = 1,
        .type = 1,
        .target = 3,
        .cost = 7,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 11,
                           .hitrateFlags = 19,
                           .hitrateAdj = 5,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Silence\000ant\000\000\000d\000\0000000000" },
    { .id = 76,
        .effect = 23,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 21,
        .rangeX = 7,
        .rangeY = 7,
        .rangeZ = 7,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 12,
                           .hitrateFlags = 20,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Magic|>6|Ward\000\000\000d\000\0000000000" },
    { .id = 77,
        .effect = 24,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 20,
        .rangeX = 7,
        .rangeY = 7,
        .rangeZ = 7,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1358958592u,
        .unk10 = 0,
        .hitParams = { { .effect = 13,
                           .hitrateFlags = 21,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Surging|>6|Balm\000d\000\0000000000" },
    { .id = 78,
        .effect = 45,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 15,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2151694336u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 4,
                           .type = 1,
                           .affinity = 2 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Lightning|>6|Bolt\000\0000000000" },
    { .id = 79,
        .effect = 26,
        .unk2_0 = 1,
        .type = 1,
        .target = 9,
        .cost = 3,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 268447744,
        .unk10 = 0,
        .hitParams = { { .effect = 36,
                           .hitrateFlags = 7,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Fixate\000ng|>6|Bolt\000\0000000000" },
    { .id = 80,
        .effect = 27,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 10,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 31,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Dispel\000ng|>6|Bolt\000\0000000000" },
    { .id = 81,
        .effect = 46,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 15,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2151694336u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 4,
                           .type = 1,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Fireball\000|>6|Bolt\000\0000000000" },
    { .id = 82,
        .effect = 29,
        .unk2_0 = 1,
        .type = 1,
        .target = 3,
        .cost = 7,
        .rangeX = 12,
        .rangeY = 9,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 15,
                           .hitrateFlags = 22,
                           .hitrateAdj = 5,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Stun|>6|Cloud\000olt\000\0000000000" },
    { .id = 83,
        .effect = 30,
        .unk2_0 = 1,
        .type = 1,
        .target = 3,
        .cost = 11,
        .rangeX = 12,
        .rangeY = 9,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 16,
                           .hitrateFlags = 23,
                           .hitrateAdj = 5,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Poison|>6|Mist\000lt\000\0000000000" },
    { .id = 84,
        .effect = 47,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 15,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2151694336u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 4,
                           .type = 1,
                           .affinity = 4 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Vulcan|>6|Lance\000t\000\0000000000" },
    { .id = 85,
        .effect = 32,
        .unk2_0 = 1,
        .type = 1,
        .target = 3,
        .cost = 17,
        .rangeX = 11,
        .rangeY = 8,
        .rangeZ = 11,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 18,
                           .hitrateFlags = 25,
                           .hitrateAdj = 5,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Curse\000|>6|Lance\000t\000\0000000000" },
    { .id = 86,
        .effect = 48,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 15,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2151694336u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 4,
                           .type = 1,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Aqua|>6|Blast\000e\000t\000\0000000000" },
    { .id = 87,
        .effect = 34,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 3,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1375735808u,
        .unk10 = 0,
        .hitParams = { { .effect = 27,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Restoration\000e\000t\000\0000000000" },
    { .id = 88,
        .effect = 35,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 3,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1375735808u,
        .unk10 = 0,
        .hitParams = { { .effect = 28,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Antidote\000on\000e\000t\000\0000000000" },
    { .id = 89,
        .effect = 36,
        .unk2_0 = 1,
        .type = 0,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268435456,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000on\000e\000t\000\0000000000" },
    { .id = 90,
        .effect = 37,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 17,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1375735808u,
        .unk10 = 0,
        .hitParams = { { .effect = 29,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Blessing\000on\000e\000t\000\0000000000" },
    { .id = 91,
        .effect = 38,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 15,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1375735808u,
        .unk10 = 0,
        .hitParams = { { .effect = 32,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Clearance\000n\000e\000t\000\0000000000" },
    { .id = 92,
        .effect = 39,
        .unk2_0 = 1,
        .type = 1,
        .target = 10,
        .cost = 3,
        .rangeX = 7,
        .rangeY = 8,
        .rangeZ = 5,
        .shape = 3,
        .angle = 24,
        .aoe = 0,
        .flags = 268439552,
        .unk10 = 0,
        .hitParams = { { .effect = 39,
                           .hitrateFlags = 8,
                           .hitrateAdj = 6,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Unlock\000ce\000n\000e\000t\000\0000000000" },
    { .id = 93,
        .effect = 40,
        .unk2_0 = 1,
        .type = 1,
        .target = 13,
        .cost = 6,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 268447744,
        .unk10 = 0,
        .hitParams = { { .effect = 33,
                           .hitrateFlags = 6,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Eureka\000ce\000n\000e\000t\000\0000000000" },
    { .id = 94,
        .effect = 41,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 12,
        .rangeX = 20,
        .rangeY = 20,
        .rangeZ = 20,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 5,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 62,
                .hitrateFlags = 3,
                .hitrateAdj = 1,
                .damage = 1,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Drain|>6|Heart\000\000t\000\0000000000" },
    { .id = 95,
        .effect = 42,
        .unk2_0 = 1,
        .type = 1,
        .target = 3,
        .cost = 2,
        .rangeX = 14,
        .rangeY = 14,
        .rangeZ = 14,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 59,
                           .hitrateFlags = 36,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 63,
                .hitrateFlags = 3,
                .hitrateAdj = 1,
                .damage = 1,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Drain|>6|Mind\000\000\000t\000\0000000000" },
    { .id = 96,
        .effect = 43,
        .unk2_0 = 1,
        .type = 1,
        .target = 1,
        .cost = 5,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1476399104u,
        .unk10 = 0,
        .hitParams = { { .effect = 62,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 13,
                           .mult = 5,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 58,
                .hitrateFlags = 4,
                .hitrateAdj = 5,
                .damage = 3,
                .mult = 0,
                .type = 0,
                .affinity = 6 } },
        .name = "Heal\000|>6|Mind\000\000\000t\000\0000000000" },
    { .id = 97,
        .effect = 44,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 15,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 4,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Solid|>6|Shock\000\000t\000\0000000000" },
    { .id = 98,
        .effect = 45,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 15,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 4,
                           .type = 1,
                           .affinity = 2 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Lightning|>6|Bolt\000\0000000000" },
    { .id = 99,
        .effect = 46,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 15,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 4,
                           .type = 1,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Fireball\000|>6|Bolt\000\0000000000" },
    { .id = 100,
        .effect = 47,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 15,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 4,
                           .type = 1,
                           .affinity = 4 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Vulcan|>6|Lance\000t\000\0000000000" },
    { .id = 101,
        .effect = 48,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 15,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 4,
                           .type = 1,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Aqua|>6|Blast\000e\000t\000\0000000000" },
    { .id = 102,
        .effect = 49,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 28,
        .rangeX = 18,
        .rangeY = 15,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 4,
                           .type = 1,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Spirit|>6|Surge\000t\000\0000000000" },
    { .id = 103,
        .effect = 50,
        .unk2_0 = 1,
        .type = 1,
        .target = 7,
        .cost = 28,
        .rangeX = 18,
        .rangeY = 15,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 4,
                           .type = 1,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Dark|>6|Chant\000e\000t\000\0000000000" },
    { .id = 104,
        .effect = 51,
        .unk2_0 = 1,
        .type = 1,
        .target = 4,
        .cost = 22,
        .rangeX = 14,
        .rangeY = 6,
        .rangeZ = 14,
        .shape = 2,
        .angle = 0,
        .aoe = 33818116,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 34,
                           .hitrateFlags = 35,
                           .hitrateAdj = 4,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Exorcism\000nt\000e\000t\000\0000000000" },
    { .id = 105,
        .effect = 52,
        .unk2_0 = 1,
        .type = 1,
        .target = 4,
        .cost = 25,
        .rangeX = 14,
        .rangeY = 6,
        .rangeZ = 14,
        .shape = 2,
        .angle = 0,
        .aoe = 33818116,
        .flags = 2415923200u,
        .unk10 = 0,
        .hitParams = { { .effect = 34,
                           .hitrateFlags = 36,
                           .hitrateAdj = 4,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Banish\000m\000nt\000e\000t\000\0000000000" },
    { .id = 106,
        .effect = 53,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 36,
        .rangeX = 15,
        .rangeY = 15,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 16908802,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Explosion|>6|Lv.1\000t\000\0000000000" },
    { .id = 107,
        .effect = 54,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 44,
        .rangeX = 14,
        .rangeY = 14,
        .rangeZ = 14,
        .shape = 1,
        .angle = 0,
        .aoe = 17040388,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Explosion|>6|Lv.2\000t\000\0000000000" },
    { .id = 108,
        .effect = 55,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 52,
        .rangeX = 13,
        .rangeY = 13,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 17171974,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Explosion|>6|Lv.3\000t\000\0000000000" },
    { .id = 109,
        .effect = 56,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 60,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 17303560,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 1,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Explosion|>6|Lv.4\000t\000\0000000000" },
    { .id = 110,
        .effect = 57,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 36,
        .rangeX = 15,
        .rangeY = 15,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 16908802,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 2 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Thunderburst|>6|Lv.1\0000000000" },
    { .id = 111,
        .effect = 58,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 44,
        .rangeX = 14,
        .rangeY = 14,
        .rangeZ = 14,
        .shape = 1,
        .angle = 0,
        .aoe = 17040388,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 2 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Thunderburst|>6|Lv.2\0000000000" },
    { .id = 112,
        .effect = 59,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 52,
        .rangeX = 13,
        .rangeY = 13,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 17171974,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 2 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Thunderburst|>6|Lv.3\0000000000" },
    { .id = 113,
        .effect = 60,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 60,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 17303560,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 1,
                           .type = 0,
                           .affinity = 2 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Thunderburst|>6|Lv.4\0000000000" },
    { .id = 114,
        .effect = 61,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 36,
        .rangeX = 15,
        .rangeY = 15,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 16908802,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Flame|>6|Sphere|>6|Lv.1\000000000" },
    { .id = 115,
        .effect = 62,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 44,
        .rangeX = 14,
        .rangeY = 14,
        .rangeZ = 14,
        .shape = 1,
        .angle = 0,
        .aoe = 17040388,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Flame|>6|Sphere|>6|Lv.2\000000000" },
    { .id = 116,
        .effect = 63,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 52,
        .rangeX = 13,
        .rangeY = 13,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 17171974,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Flame|>6|Sphere|>6|Lv.3\000000000" },
    { .id = 117,
        .effect = 64,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 60,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 17303560,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 1,
                           .type = 0,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Flame|>6|Sphere|>6|Lv.4\000000000" },
    { .id = 118,
        .effect = 65,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 36,
        .rangeX = 14,
        .rangeY = 8,
        .rangeZ = 14,
        .shape = 2,
        .angle = 0,
        .aoe = 33686274,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 4 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Gaea|>6|Strike|>6|Lv.1\000\000000000" },
    { .id = 119,
        .effect = 66,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 44,
        .rangeX = 13,
        .rangeY = 7,
        .rangeZ = 13,
        .shape = 2,
        .angle = 0,
        .aoe = 33817604,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 4 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Gaea|>6|Strike|>6|Lv.2\000\000000000" },
    { .id = 120,
        .effect = 67,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 52,
        .rangeX = 12,
        .rangeY = 6,
        .rangeZ = 12,
        .shape = 2,
        .angle = 0,
        .aoe = 33948934,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 4 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Gaea|>6|Strike|>6|Lv.3\000\000000000" },
    { .id = 121,
        .effect = 68,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 60,
        .rangeX = 11,
        .rangeY = 5,
        .rangeZ = 11,
        .shape = 2,
        .angle = 0,
        .aoe = 34080264,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 1,
                           .type = 0,
                           .affinity = 4 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Gaea|>6|Strike|>6|Lv.4\000\000000000" },
    { .id = 122,
        .effect = 69,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 36,
        .rangeX = 15,
        .rangeY = 15,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 16908802,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Avalanche|>6|Lv.1\000Lv.4\000\000000000" },
    { .id = 123,
        .effect = 70,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 44,
        .rangeX = 14,
        .rangeY = 14,
        .rangeZ = 14,
        .shape = 1,
        .angle = 0,
        .aoe = 17040388,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Avalanche|>6|Lv.2\000Lv.4\000\000000000" },
    { .id = 124,
        .effect = 71,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 52,
        .rangeX = 13,
        .rangeY = 13,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 17171974,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Avalanche|>6|Lv.3\000Lv.4\000\000000000" },
    { .id = 125,
        .effect = 72,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 60,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 17303560,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 1,
                           .type = 0,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Avalanche|>6|Lv.4\000Lv.4\000\000000000" },
    { .id = 126,
        .effect = 73,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 38,
        .rangeX = 15,
        .rangeY = 15,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 16908802,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Radial|>6|Surge|>6|Lv.1\000000000" },
    { .id = 127,
        .effect = 74,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 46,
        .rangeX = 14,
        .rangeY = 14,
        .rangeZ = 14,
        .shape = 1,
        .angle = 0,
        .aoe = 17040388,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Radial|>6|Surge|>6|Lv.2\000000000" },
    { .id = 128,
        .effect = 75,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 54,
        .rangeX = 13,
        .rangeY = 13,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 17171974,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Radial|>6|Surge|>6|Lv.3\000000000" },
    { .id = 129,
        .effect = 76,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 62,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 17303560,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 1,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Radial|>6|Surge|>6|Lv.4\000000000" },
    { .id = 130,
        .effect = 77,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 38,
        .rangeX = 15,
        .rangeY = 15,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 16908802,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Meteor|>6|Lv.1\000ge|>6|Lv.4\000000000" },
    { .id = 131,
        .effect = 78,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 46,
        .rangeX = 14,
        .rangeY = 14,
        .rangeZ = 14,
        .shape = 1,
        .angle = 0,
        .aoe = 17040388,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Meteor|>6|Lv.2\000ge|>6|Lv.4\000000000" },
    { .id = 132,
        .effect = 79,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 54,
        .rangeX = 13,
        .rangeY = 13,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 17171974,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Meteor|>6|Lv.3\000ge|>6|Lv.4\000000000" },
    { .id = 133,
        .effect = 80,
        .unk2_0 = 1,
        .type = 1,
        .target = 6,
        .cost = 62,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 17303560,
        .flags = 2424307712u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 1,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Meteor|>6|Lv.4\000ge|>6|Lv.4\000000000" },
    { .id = 134,
        .effect = 81,
        .unk2_0 = 1,
        .type = 1,
        .target = 12,
        .cost = 35,
        .rangeX = 1,
        .rangeY = 24,
        .rangeZ = 1,
        .shape = 3,
        .angle = 0,
        .aoe = 0,
        .flags = 2415960066u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Tornado\000Lv.4\000ge|>6|Lv.4\000000000" },
    { .id = 135,
        .effect = 82,
        .unk2_0 = 1,
        .type = 1,
        .target = 12,
        .cost = 35,
        .rangeX = 1,
        .rangeY = 24,
        .rangeZ = 1,
        .shape = 3,
        .angle = 0,
        .aoe = 0,
        .flags = 2415960066u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 2 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Thunderbolt\000e|>6|Lv.4\000000000" },
    { .id = 136,
        .effect = 83,
        .unk2_0 = 1,
        .type = 1,
        .target = 12,
        .cost = 35,
        .rangeX = 1,
        .rangeY = 24,
        .rangeZ = 1,
        .shape = 3,
        .angle = 0,
        .aoe = 0,
        .flags = 2415960066u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Fire|>6|Storm\000e|>6|Lv.4\000000000" },
    { .id = 137,
        .effect = 84,
        .unk2_0 = 1,
        .type = 1,
        .target = 12,
        .cost = 35,
        .rangeX = 1,
        .rangeY = 24,
        .rangeZ = 1,
        .shape = 3,
        .angle = 0,
        .aoe = 0,
        .flags = 2415960066u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 4 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Gravity\000orm\000e|>6|Lv.4\000000000" },
    { .id = 138,
        .effect = 85,
        .unk2_0 = 1,
        .type = 1,
        .target = 12,
        .cost = 35,
        .rangeX = 1,
        .rangeY = 24,
        .rangeZ = 1,
        .shape = 3,
        .angle = 0,
        .aoe = 0,
        .flags = 2415960066u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 0,
                           .type = 0,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Acid|>6|Flow\000\000e|>6|Lv.4\000000000" },
    { .id = 139,
        .effect = 86,
        .unk2_0 = 1,
        .type = 1,
        .target = 12,
        .cost = 65,
        .rangeX = 1,
        .rangeY = 26,
        .rangeZ = 1,
        .shape = 3,
        .angle = 0,
        .aoe = 3072,
        .flags = 2952830978u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 2,
                           .type = 0,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Judgment\000w\000\000e|>6|Lv.4\000000000" },
    { .id = 140,
        .effect = 87,
        .unk2_0 = 1,
        .type = 1,
        .target = 12,
        .cost = 65,
        .rangeX = 1,
        .rangeY = 34,
        .rangeZ = 1,
        .shape = 3,
        .angle = 0,
        .aoe = 6400,
        .flags = 2952830978u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 5,
                           .hitrateAdj = 5,
                           .damage = 3,
                           .mult = 2,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Apocalypse\000\000e|>6|Lv.4\000000000" },
    { .id = 141,
        .effect = 88,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 2,
        .rangeX = 12,
        .rangeY = 12,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2421194753u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 3,
                           .affinity = 7 },
            { .effect = 15,
                .hitrateFlags = 15,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Stun|>6|Blast\000e|>6|Lv.4\000000000" },
    { .id = 142,
        .effect = 89,
        .unk2_0 = 1,
        .type = 0,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 269484032,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000st\000e|>6|Lv.4\000000000" },
    { .id = 143,
        .effect = 90,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 5,
        .rangeX = 14,
        .rangeY = 14,
        .rangeZ = 14,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2417008641u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 5,
                           .type = 1,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Tidal|>6|Rush\000e|>6|Lv.4\000000000" },
    { .id = 144,
        .effect = 91,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 2,
        .rangeX = 14,
        .rangeY = 14,
        .rangeZ = 14,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2417000448u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 2,
                           .type = 3,
                           .affinity = 7 },
            { .effect = 18,
                .hitrateFlags = 25,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Blasphemous|>6|Howl\000000000" },
    { .id = 145,
        .effect = 92,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 5,
        .rangeX = 20,
        .rangeY = 18,
        .rangeZ = 20,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2417008640u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 5,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Tail|>6|Attack\000Howl\000000000" },
    { .id = 146,
        .effect = 93,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 5,
        .rangeX = 20,
        .rangeY = 18,
        .rangeZ = 20,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2417008640u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 5,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Tail|>6|Attack\000Howl\000000000" },
    { .id = 147,
        .effect = 94,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 3,
        .rangeX = 1,
        .rangeY = 14,
        .rangeZ = 1,
        .shape = 3,
        .angle = 0,
        .aoe = 1536,
        .flags = 2417000450u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Fire|>6|Breath\000Howl\000000000" },
    { .id = 148,
        .effect = 95,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 3,
        .rangeX = 4,
        .rangeY = 28,
        .rangeZ = 4,
        .shape = 3,
        .angle = 0,
        .aoe = 3584,
        .flags = 2953871361u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 3 },
            { .effect = 35,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Fire|>6|Breath\000Howl\000000000" },
    { .id = 149,
        .effect = 96,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 3,
        .rangeX = 9,
        .rangeY = 36,
        .rangeZ = 9,
        .shape = 3,
        .angle = 0,
        .aoe = 4608,
        .flags = 2953879553u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 4 },
            { .effect = 35,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Acid|>6|Breath\000Howl\000000000" },
    { .id = 150,
        .effect = 97,
        .unk2_0 = 1,
        .type = 5,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 269484032,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000ath\000Howl\000000000" },
    { .id = 151,
        .effect = 98,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 2,
        .rangeX = 1,
        .rangeY = 10,
        .rangeZ = 1,
        .shape = 3,
        .angle = 0,
        .aoe = 1536,
        .flags = 2953871362u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 1,
                           .type = 1,
                           .affinity = 4 },
            { .effect = 35,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Acid|>6|Breath\000Howl\000000000" },
    { .id = 152,
        .effect = 99,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 3,
        .rangeX = 9,
        .rangeY = 36,
        .rangeZ = 9,
        .shape = 3,
        .angle = 0,
        .aoe = 4608,
        .flags = 2953879553u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 7 },
            { .effect = 35,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Rot|>6|Breath\000\000Howl\000000000" },
    { .id = 153,
        .effect = 100,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 1,
        .rangeX = 13,
        .rangeY = 13,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2152775680u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 3,
                           .type = 1,
                           .affinity = 2 },
            { .effect = 15,
                .hitrateFlags = 22,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Caeser's|>6|Thrust\000\000000000" },
    { .id = 154,
        .effect = 101,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 3,
        .rangeX = 9,
        .rangeY = 36,
        .rangeZ = 9,
        .shape = 3,
        .angle = 0,
        .aoe = 4608,
        .flags = 2953879553u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Thermal|>6|Breath\000\000\000000000" },
    { .id = 155,
        .effect = 102,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 3,
        .rangeX = 9,
        .rangeY = 36,
        .rangeZ = 9,
        .shape = 3,
        .angle = 0,
        .aoe = 4608,
        .flags = 2953879553u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 2 },
            { .effect = 35,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Thunder|>6|Breath\000\000\000000000" },
    { .id = 156,
        .effect = 103,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 1,
        .rangeX = 13,
        .rangeY = 13,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2152775680u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 3,
                           .type = 2,
                           .affinity = 3 },
            { .effect = 59,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 3,
                .mult = 5,
                .type = 0,
                .affinity = 0 } },
        .name = "Heaven's|>6|Tear\000\000\000\000000000" },
    { .id = 157,
        .effect = 104,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 3,
        .rangeX = 9,
        .rangeY = 36,
        .rangeZ = 9,
        .shape = 3,
        .angle = 0,
        .aoe = 4608,
        .flags = 2953879553u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 3 },
            { .effect = 35,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Searing|>6|Breath\000\000\000000000" },
    { .id = 158,
        .effect = 105,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 1,
        .rangeX = 13,
        .rangeY = 13,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2152775680u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 3,
                           .type = 1,
                           .affinity = 4 },
            { .effect = 17,
                .hitrateFlags = 24,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Tyrant's|>6|Mace\000\000\000\000000000" },
    { .id = 159,
        .effect = 106,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 3,
        .rangeX = 9,
        .rangeY = 36,
        .rangeZ = 9,
        .shape = 3,
        .angle = 0,
        .aoe = 4608,
        .flags = 2953879553u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 5 },
            { .effect = 35,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Frost|>6|Breath\000\000\000\000\000000000" },
    { .id = 160,
        .effect = 107,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 1,
        .rangeX = 13,
        .rangeY = 13,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2152775680u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 3,
                           .type = 3,
                           .affinity = 5 },
            { .effect = 16,
                .hitrateFlags = 23,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Raven|>6|Eye\000th\000\000\000\000\000000000" },
    { .id = 161,
        .effect = 108,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 3,
        .rangeX = 9,
        .rangeY = 36,
        .rangeZ = 9,
        .shape = 3,
        .angle = 0,
        .aoe = 4608,
        .flags = 2953879553u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 6 },
            { .effect = 59,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 3,
                .mult = 5,
                .type = 0,
                .affinity = 0 } },
        .name = "Divine|>6|Breath\000\000\000\000000000" },
    { .id = 162,
        .effect = 109,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 3,
        .rangeX = 9,
        .rangeY = 36,
        .rangeZ = 9,
        .shape = 3,
        .angle = 0,
        .aoe = 4608,
        .flags = 2953879553u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 7 },
            { .effect = 16,
                .hitrateFlags = 23,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Poison|>6|Breath\000\000\000\000000000" },
    { .id = 163,
        .effect = 110,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 2,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 3,
        .angle = 0,
        .aoe = 0,
        .flags = 2421194753u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 3,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Mind|>6|Blast\000th\000\000\000\000000000" },
    { .id = 164,
        .effect = 111,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 2,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 3,
        .angle = 0,
        .aoe = 0,
        .flags = 2421194753u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 3,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Mind|>6|Blast\000th\000\000\000\000000000" },
    { .id = 165,
        .effect = 112,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 4,
        .rangeX = 9,
        .rangeY = 9,
        .rangeZ = 9,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2148581377u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 2,
                           .type = 3,
                           .affinity = 1 },
            { .effect = 17,
                .hitrateFlags = 24,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Numbing|>6|Hook\000\000\000\000\000000000" },
    { .id = 166,
        .effect = 113,
        .unk2_0 = 1,
        .type = 5,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 269484032,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000Hook\000\000\000\000\000000000" },
    { .id = 167,
        .effect = 114,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 4,
        .rangeX = 9,
        .rangeY = 9,
        .rangeZ = 9,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2148581376u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 2,
                           .type = 2,
                           .affinity = 1 },
            { .effect = 17,
                .hitrateFlags = 24,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Numbing|>6|Needle\000\000\000000000" },
    { .id = 168,
        .effect = 115,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 4,
        .rangeX = 9,
        .rangeY = 9,
        .rangeZ = 9,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2148581377u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 2,
                           .affinity = 1 },
            { .effect = 62,
                .hitrateFlags = 3,
                .hitrateAdj = 1,
                .damage = 1,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Bloodsuck\000eedle\000\000\000000000" },
    { .id = 169,
        .effect = 116,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 2,
        .rangeX = 8,
        .rangeY = 8,
        .rangeZ = 8,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2152775681u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 5,
                           .type = 1,
                           .affinity = 7 },
            { .effect = 35,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Acid|>6|Sneeze\000le\000\000\000000000" },
    { .id = 170,
        .effect = 117,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 2,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2148581377u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 3,
                           .type = 3,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Spiral|>6|Shell\000e\000\000\000000000" },
    { .id = 171,
        .effect = 118,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 5,
        .rangeX = 24,
        .rangeY = 10,
        .rangeZ = 24,
        .shape = 2,
        .angle = 0,
        .aoe = 3584,
        .flags = 2685444097u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 3,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Granite|>6|Punch\000\000\000\000000000" },
    { .id = 172,
        .effect = 119,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 2,
        .rangeX = 14,
        .rangeY = 14,
        .rangeZ = 14,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2148581376u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 2,
                           .type = 3,
                           .affinity = 1 },
            { .effect = 62,
                .hitrateFlags = 3,
                .hitrateAdj = 1,
                .damage = 1,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Devitalize\000nch\000\000\000\000000000" },
    { .id = 173,
        .effect = 120,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 3,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2417000449u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 2,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Poltergeist\000ch\000\000\000\000000000" },
    { .id = 174,
        .effect = 121,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 3,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2417000449u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 0,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Reaper's|>6|Scythe\000\000000000" },
    { .id = 175,
        .effect = 122,
        .unk2_0 = 1,
        .type = 5,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 269484032,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\0006Scythe\000\000000000" },
    { .id = 176,
        .effect = 123,
        .unk2_0 = 1,
        .type = 5,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 269484032,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\0006Scythe\000\000000000" },
    { .id = 177,
        .effect = 124,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 5,
        .rangeX = 10,
        .rangeY = 15,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2148581378u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Giga|>6|Rush\000cythe\000\000000000" },
    { .id = 178,
        .effect = 125,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 3,
        .rangeX = 8,
        .rangeY = 28,
        .rangeZ = 16,
        .shape = 3,
        .angle = 0,
        .aoe = 4096,
        .flags = 2685444097u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 5 },
            { .effect = 35,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Aqua|>6|Bubble\000the\000\000000000" },
    { .id = 179,
        .effect = 126,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 2,
        .rangeX = 9,
        .rangeY = 10,
        .rangeZ = 9,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2152775681u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 1,
                           .type = 1,
                           .affinity = 4 },
            { .effect = 16,
                .hitrateFlags = 23,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Poison|>6|Sneeze\000e\000\000000000" },
    { .id = 180,
        .effect = 127,
        .unk2_0 = 1,
        .type = 2,
        .target = 7,
        .cost = 2,
        .rangeX = 9,
        .rangeY = 10,
        .rangeZ = 9,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2152775681u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 1,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Acrid|>6|Ooze\000ze\000e\000\000000000" },
    { .id = 181,
        .effect = 128,
        .unk2_0 = 1,
        .type = 2,
        .target = 8,
        .cost = 15,
        .rangeX = 16,
        .rangeY = 16,
        .rangeZ = 16,
        .shape = 1,
        .angle = 0,
        .aoe = 17171974,
        .flags = 1594916865u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 1,
                           .type = 1,
                           .affinity = 7 },
            { .effect = 58,
                .hitrateFlags = 2,
                .hitrateAdj = 3,
                .damage = 2,
                .mult = 0,
                .type = 3,
                .affinity = 6 } },
        .name = "Bloody|>6|Sin\000ze\000e\000\000000000" },
    { .id = 182,
        .effect = 129,
        .unk2_0 = 1,
        .type = 2,
        .target = 12,
        .cost = 5,
        .rangeX = 1,
        .rangeY = 24,
        .rangeZ = 1,
        .shape = 3,
        .angle = 0,
        .aoe = 0,
        .flags = 2417000449u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 2,
                           .mult = 0,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Last|>6|Ascension\000\000\000000000" },
    { .id = 183,
        .effect = 130,
        .unk2_0 = 1,
        .type = 5,
        .target = 0,
        .cost = 0,
        .rangeX = 0,
        .rangeY = 0,
        .rangeZ = 0,
        .shape = 0,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 0,
                           .hitrateFlags = 0,
                           .hitrateAdj = 0,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "untitled\000ension\000\000\000000000" },
    { .id = 184,
        .effect = 131,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 25,
        .rangeX = 20,
        .rangeY = 19,
        .rangeZ = 20,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 1,
                           .type = 1,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Whistle|>6|Sting\000\000\000\000000000" },
    { .id = 185,
        .effect = 132,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 40,
        .rangeX = 17,
        .rangeY = 16,
        .rangeZ = 17,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 1,
                           .affinity = 7 },
            { .effect = 15,
                .hitrateFlags = 22,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Shadoweave\000ing\000\000\000\000000000" },
    { .id = 186,
        .effect = 133,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 55,
        .rangeX = 14,
        .rangeY = 13,
        .rangeZ = 14,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 3,
                           .affinity = 0 },
            { .effect = 58,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 25,
                .mult = 0,
                .type = 3,
                .affinity = 0 } },
        .name = "Double|>6|Fang\000g\000\000\000\000000000" },
    { .id = 187,
        .effect = 134,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 75,
        .rangeX = 11,
        .rangeY = 10,
        .rangeZ = 11,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415927296u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 3,
                           .type = 3,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Wyrm|>6|Scorn\000\000g\000\000\000\000000000" },
    { .id = 188,
        .effect = 135,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 25,
        .rangeX = 19,
        .rangeY = 18,
        .rangeZ = 19,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 1,
                           .type = 3,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Rending|>6|Gale\000\000\000\000\000000000" },
    { .id = 189,
        .effect = 136,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 40,
        .rangeX = 16,
        .rangeY = 15,
        .rangeZ = 16,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 2,
                           .affinity = 0 },
            { .effect = 16,
                .hitrateFlags = 23,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Vile|>6|Scar\000le\000\000\000\000\000000000" },
    { .id = 190,
        .effect = 137,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 55,
        .rangeX = 13,
        .rangeY = 12,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 2,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Cherry|>6|Ronde\000\000\000\000\000000000" },
    { .id = 191,
        .effect = 138,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 75,
        .rangeX = 10,
        .rangeY = 9,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415927296u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 3,
                           .type = 2,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Papillon|>6|Reel\000\000\000\000000000" },
    { .id = 192,
        .effect = 139,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 17,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 1,
                           .type = 3,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Sunder\000n|>6|Reel\000\000\000\000000000" },
    { .id = 193,
        .effect = 140,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 40,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 2,
                           .affinity = 2 },
            { .effect = 15,
                .hitrateFlags = 22,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Thunderwave\000el\000\000\000\000000000" },
    { .id = 194,
        .effect = 141,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 55,
        .rangeX = 12,
        .rangeY = 11,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 2,
                           .affinity = 0 },
            { .effect = 58,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 25,
                .mult = 0,
                .type = 2,
                .affinity = 0 } },
        .name = "Swallow|>6|Slash\000\000\000\000000000" },
    { .id = 195,
        .effect = 142,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 75,
        .rangeX = 9,
        .rangeY = 8,
        .rangeZ = 9,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415927296u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 3,
                           .type = 2,
                           .affinity = 6 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Advent|>6|Sign\000h\000\000\000\000000000" },
    { .id = 196,
        .effect = 143,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 25,
        .rangeX = 19,
        .rangeY = 18,
        .rangeZ = 19,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 1,
                           .type = 1,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Mistral|>6|Edge\000\000\000\000\000000000" },
    { .id = 197,
        .effect = 144,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 40,
        .rangeX = 16,
        .rangeY = 15,
        .rangeZ = 16,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 1,
                           .affinity = 2 },
            { .effect = 17,
                .hitrateFlags = 24,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Glacial|>6|Gale\000\000\000\000\000000000" },
    { .id = 198,
        .effect = 145,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 55,
        .rangeX = 13,
        .rangeY = 12,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 2,
                           .affinity = 0 },
            { .effect = 59,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 3,
                .mult = 5,
                .type = 0,
                .affinity = 0 } },
        .name = "Killer|>6|Mantis\000\000\000\000000000" },
    { .id = 199,
        .effect = 146,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 75,
        .rangeX = 10,
        .rangeY = 9,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415927296u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 3,
                           .type = 1,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Black|>6|Nebula\000\000\000\000\000000000" },
    { .id = 200,
        .effect = 147,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 17,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 1,
                           .type = 1,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Bear|>6|Claw\000la\000\000\000\000\000000000" },
    { .id = 201,
        .effect = 148,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 40,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 1,
                           .affinity = 0 },
            { .effect = 18,
                .hitrateFlags = 25,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Accursed|>6|Umbra\000\000\000000000" },
    { .id = 202,
        .effect = 149,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 55,
        .rangeX = 12,
        .rangeY = 11,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 1,
                           .affinity = 0 },
            { .effect = 35,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Iron|>6|Ripper\000ra\000\000\000000000" },
    { .id = 203,
        .effect = 150,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 75,
        .rangeX = 9,
        .rangeY = 8,
        .rangeZ = 9,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415927296u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 3,
                           .type = 2,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Emetic|>6|Bomb\000ra\000\000\000000000" },
    { .id = 204,
        .effect = 151,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 25,
        .rangeX = 19,
        .rangeY = 18,
        .rangeZ = 19,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 1,
                           .type = 1,
                           .affinity = 3 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Sirocco\000Bomb\000ra\000\000\000000000" },
    { .id = 205,
        .effect = 152,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 40,
        .rangeX = 16,
        .rangeY = 15,
        .rangeZ = 16,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 3,
                           .affinity = 0 },
            { .effect = 66,
                .hitrateFlags = 3,
                .hitrateAdj = 1,
                .damage = 24,
                .mult = 5,
                .type = 0,
                .affinity = 0 } },
        .name = "Riskbreak\000mb\000ra\000\000\000000000" },
    { .id = 206,
        .effect = 153,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 55,
        .rangeX = 13,
        .rangeY = 12,
        .rangeZ = 13,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 1,
                           .affinity = 4 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Gravis|>6|Aether\000\000\000\000000000" },
    { .id = 207,
        .effect = 154,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 75,
        .rangeX = 10,
        .rangeY = 9,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415927296u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 3,
                           .type = 1,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Trinity|>6|Pulse\000\000\000\000000000" },
    { .id = 208,
        .effect = 155,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 17,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 1,
                           .type = 1,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Bonecrusher\000se\000\000\000\000000000" },
    { .id = 209,
        .effect = 156,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 40,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 1,
                           .affinity = 2 },
            { .effect = 17,
                .hitrateFlags = 24,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Quickshock\000\000se\000\000\000\000000000" },
    { .id = 210,
        .effect = 157,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 55,
        .rangeX = 12,
        .rangeY = 11,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 1,
                           .affinity = 0 },
            { .effect = 58,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 25,
                .mult = 0,
                .type = 1,
                .affinity = 3 } },
        .name = "Ignis|>6|Wheel\000e\000\000\000\000000000" },
    { .id = 211,
        .effect = 158,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 75,
        .rangeX = 9,
        .rangeY = 8,
        .rangeZ = 9,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415927296u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 3,
                           .type = 1,
                           .affinity = 6 },
            { .effect = 58,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 25,
                .mult = 0,
                .type = 1,
                .affinity = 7 } },
        .name = "Hex|>6|Flux\000el\000e\000\000\000\000000000" },
    { .id = 212,
        .effect = 159,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 25,
        .rangeX = 18,
        .rangeY = 17,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 1,
                           .type = 3,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Ruination\000el\000e\000\000\000\000000000" },
    { .id = 213,
        .effect = 160,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 40,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 3,
                           .affinity = 2 },
            { .effect = 4,
                .hitrateFlags = 12,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Scythe|>6|Wind\000e\000\000\000\000000000" },
    { .id = 214,
        .effect = 161,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 55,
        .rangeX = 12,
        .rangeY = 11,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 3,
                           .affinity = 0 },
            { .effect = 35,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Giga|>6|Tempest\000\000\000\000\000000000" },
    { .id = 215,
        .effect = 162,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 75,
        .rangeX = 9,
        .rangeY = 8,
        .rangeZ = 9,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415927296u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 3,
                           .type = 3,
                           .affinity = 5 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Spiral|>6|Scourge\000\000\000000000" },
    { .id = 216,
        .effect = 163,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 25,
        .rangeX = 17,
        .rangeY = 16,
        .rangeZ = 17,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 1,
                           .type = 3,
                           .affinity = 7 },
            { .effect = 58,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 25,
                .mult = 0,
                .type = 3,
                .affinity = 3 } },
        .name = "Brimstone|>6|Hail\000\000\000000000" },
    { .id = 217,
        .effect = 164,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 40,
        .rangeX = 14,
        .rangeY = 13,
        .rangeZ = 14,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 3,
                           .affinity = 6 },
            { .effect = 58,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 25,
                .mult = 0,
                .type = 3,
                .affinity = 2 } },
        .name = "Heaven's|>6|Scorn\000\000\000000000" },
    { .id = 218,
        .effect = 165,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 55,
        .rangeX = 11,
        .rangeY = 10,
        .rangeZ = 11,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 3,
                           .affinity = 7 },
            { .effect = 58,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 25,
                .mult = 0,
                .type = 3,
                .affinity = 4 } },
        .name = "Death|>6|Wail\000orn\000\000\000000000" },
    { .id = 219,
        .effect = 166,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 75,
        .rangeX = 8,
        .rangeY = 7,
        .rangeZ = 8,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147508224u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 3,
                           .type = 3,
                           .affinity = 6 },
            { .effect = 58,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 25,
                .mult = 0,
                .type = 3,
                .affinity = 5 } },
        .name = "Sanctus|>6|Flare\000\000\000\000000000" },
    { .id = 220,
        .effect = 167,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 25,
        .rangeX = 21,
        .rangeY = 20,
        .rangeZ = 21,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 2,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Lotus|>6|Palm\000re\000\000\000\000000000" },
    { .id = 221,
        .effect = 168,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 40,
        .rangeX = 18,
        .rangeY = 17,
        .rangeZ = 18,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2147500032u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 3,
                           .type = 1,
                           .affinity = 1 },
            { .effect = 17,
                .hitrateFlags = 24,
                .hitrateAdj = 3,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Vertigo\000alm\000re\000\000\000\000000000" },
    { .id = 222,
        .effect = 169,
        .unk2_0 = 1,
        .type = 3,
        .target = 7,
        .cost = 55,
        .rangeX = 15,
        .rangeY = 14,
        .rangeZ = 15,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415919104u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 3,
                           .type = 1,
                           .affinity = 6 },
            { .effect = 58,
                .hitrateFlags = 1,
                .hitrateAdj = 1,
                .damage = 25,
                .mult = 0,
                .type = 1,
                .affinity = 6 } },
        .name = "Vermillion|>6|Aura\000\000000000" },
    { .id = 223,
        .effect = 170,
        .unk2_0 = 1,
        .type = 3,
        .target = 3,
        .cost = 75,
        .rangeX = 12,
        .rangeY = 11,
        .rangeZ = 12,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415927296u,
        .unk10 = 0,
        .hitParams = { { .effect = 58,
                           .hitrateFlags = 2,
                           .hitrateAdj = 3,
                           .damage = 25,
                           .mult = 5,
                           .type = 1,
                           .affinity = 7 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Retribution\000Aura\000\000000000" },
    { .id = 224,
        .effect = 171,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1476431872u,
        .unk10 = 0,
        .hitParams = { { .effect = 62,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 15,
                           .mult = 10,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Recover|>6|50|>6|HP\000\000\000000000" },
    { .id = 225,
        .effect = 172,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1476431872u,
        .unk10 = 0,
        .hitParams = { { .effect = 62,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 15,
                           .mult = 20,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Recover|>6|100|>6|HP\000\000000000" },
    { .id = 226,
        .effect = 173,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1476431872u,
        .unk10 = 0,
        .hitParams = { { .effect = 62,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 15,
                           .mult = 30,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Recover|>6|150|>6|HP\000\000000000" },
    { .id = 227,
        .effect = 174,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1476431872u,
        .unk10 = 0,
        .hitParams = { { .effect = 62,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 16,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "HP|>6|Full\000150|>6|HP\000\000000000" },
    { .id = 228,
        .effect = 175,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1409323008u,
        .unk10 = 0,
        .hitParams = { { .effect = 63,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 15,
                           .mult = 5,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Recharge|>6|25|>6|MP\000\000000000" },
    { .id = 229,
        .effect = 176,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1409323008u,
        .unk10 = 0,
        .hitParams = { { .effect = 63,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 15,
                           .mult = 10,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Recharge|>6|50|>6|MP\000\000000000" },
    { .id = 230,
        .effect = 177,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1409323008u,
        .unk10 = 0,
        .hitParams = { { .effect = 63,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 15,
                           .mult = 20,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Recharge|>6|100|>6|MP\000000000" },
    { .id = 231,
        .effect = 178,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1409323008u,
        .unk10 = 0,
        .hitParams = { { .effect = 63,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 17,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "MP|>6|Full\0006100|>6|MP\000000000" },
    { .id = 232,
        .effect = 179,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1543540736u,
        .unk10 = 0,
        .hitParams = { { .effect = 62,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 15,
                           .mult = 20,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 63,
                .hitrateFlags = 2,
                .hitrateAdj = 2,
                .damage = 15,
                .mult = 20,
                .type = 0,
                .affinity = 6 } },
        .name = "HP|>6|&|>6|MP|>6|Recover|>6|100\000" },
    { .id = 233,
        .effect = 180,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1543540736u,
        .unk10 = 0,
        .hitParams = { { .effect = 62,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 16,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 63,
                .hitrateFlags = 2,
                .hitrateAdj = 2,
                .damage = 17,
                .mult = 0,
                .type = 0,
                .affinity = 6 } },
        .name = "HP|>6|&|>6|MP|>6|Full\000er|>6|100\000" },
    { .id = 234,
        .effect = 181,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1493209088u,
        .unk10 = 0,
        .hitParams = { { .effect = 62,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 15,
                           .mult = 5,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 66,
                .hitrateFlags = 2,
                .hitrateAdj = 2,
                .damage = 15,
                .mult = 5,
                .type = 0,
                .affinity = 0 } },
        .name = "HP|>6|&|>6|RISK|>6|25\000er|>6|100\000" },
    { .id = 235,
        .effect = 182,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1493209088u,
        .unk10 = 0,
        .hitParams = { { .effect = 62,
                           .hitrateFlags = 5,
                           .hitrateAdj = 2,
                           .damage = 15,
                           .mult = 10,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 66,
                .hitrateFlags = 2,
                .hitrateAdj = 2,
                .damage = 15,
                .mult = 10,
                .type = 0,
                .affinity = 0 } },
        .name = "HP|>6|&|>6|RISK|>6|50\000er|>6|100\000" },
    { .id = 236,
        .effect = 183,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1375768576u,
        .unk10 = 0,
        .hitParams = { { .effect = 27,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Cure|>6|Paralysis\000er|>6|100\000" },
    { .id = 237,
        .effect = 184,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1375768576u,
        .unk10 = 0,
        .hitParams = { { .effect = 28,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Cure|>6|Poison\000is\000er|>6|100\000" },
    { .id = 238,
        .effect = 185,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1375768576u,
        .unk10 = 0,
        .hitParams = { { .effect = 29,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Cure|>6|Curse\000\000is\000er|>6|100\000" },
    { .id = 239,
        .effect = 186,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1375768576u,
        .unk10 = 0,
        .hitParams = { { .effect = 30,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Cure|>6|Numbness\000\000er|>6|100\000" },
    { .id = 240,
        .effect = 187,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1375768576u,
        .unk10 = 0,
        .hitParams = { { .effect = 32,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Cureall\000mbness\000\000er|>6|100\000" },
    { .id = 241,
        .effect = 188,
        .unk2_0 = 1,
        .type = 5,
        .target = 13,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 268480512,
        .unk10 = 0,
        .hitParams = { { .effect = 33,
                           .hitrateFlags = 6,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Mark|>6|Trap\000ess\000\000er|>6|100\000" },
    { .id = 242,
        .effect = 189,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1361088512u,
        .unk10 = 0,
        .hitParams = { { .effect = 31,
                           .hitrateFlags = 2,
                           .hitrateAdj = 5,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 0 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Magic|>6|Cancel\000\000\000er|>6|100\000" },
    { .id = 243,
        .effect = 190,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1361088512u,
        .unk10 = 0,
        .hitParams = { { .effect = 66,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 15,
                           .mult = 5,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "RISK|>6|-25\000cel\000\000\000er|>6|100\000" },
    { .id = 244,
        .effect = 191,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1361088512u,
        .unk10 = 0,
        .hitParams = { { .effect = 66,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 15,
                           .mult = 10,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "RISK|>6|-50\000cel\000\000\000er|>6|100\000" },
    { .id = 245,
        .effect = 192,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1361088512u,
        .unk10 = 0,
        .hitParams = { { .effect = 66,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 15,
                           .mult = 15,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "RISK|>6|-75\000cel\000\000\000er|>6|100\000" },
    { .id = 246,
        .effect = 193,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1361088512u,
        .unk10 = 0,
        .hitParams = { { .effect = 66,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 26,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "No|>6|RISK\000\000cel\000\000\000er|>6|100\000" },
    { .id = 247,
        .effect = 194,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1358991360u,
        .unk10 = 0,
        .hitParams = { { .effect = 10,
                           .hitrateFlags = 18,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "Quicken\000\000\000cel\000\000\000er|>6|100\000" },
    { .id = 248,
        .effect = 195,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1358991360u,
        .unk10 = 0,
        .hitParams = { { .effect = 50,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "STR-up\000\000\000\000cel\000\000\000er|>6|100\000" },
    { .id = 249,
        .effect = 196,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1358991360u,
        .unk10 = 0,
        .hitParams = { { .effect = 51,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "INT-up\000\000\000\000cel\000\000\000er|>6|100\000" },
    { .id = 250,
        .effect = 197,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1358991360u,
        .unk10 = 0,
        .hitParams = { { .effect = 52,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "AGL-up\000\000\000\000cel\000\000\000er|>6|100\000" },
    { .id = 251,
        .effect = 198,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1358991360u,
        .unk10 = 0,
        .hitParams = { { .effect = 53,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "HP-up\000\000\000\000\000cel\000\000\000er|>6|100\000" },
    { .id = 252,
        .effect = 199,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 1358991360u,
        .unk10 = 0,
        .hitParams = { { .effect = 54,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "MP-up\000\000\000\000\000cel\000\000\000er|>6|100\000" },
    { .id = 253,
        .effect = 200,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2432733184u,
        .unk10 = 0,
        .hitParams = { { .effect = 55,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "STR-down\000\000cel\000\000\000er|>6|100\000" },
    { .id = 254,
        .effect = 201,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415955968u,
        .unk10 = 0,
        .hitParams = { { .effect = 56,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "INT-down\000\000cel\000\000\000er|>6|100\000" },
    { .id = 255,
        .effect = 202,
        .unk2_0 = 1,
        .type = 5,
        .target = 1,
        .cost = 0,
        .rangeX = 10,
        .rangeY = 10,
        .rangeZ = 10,
        .shape = 1,
        .angle = 0,
        .aoe = 0,
        .flags = 2415955968u,
        .unk10 = 0,
        .hitParams = { { .effect = 57,
                           .hitrateFlags = 2,
                           .hitrateAdj = 2,
                           .damage = 0,
                           .mult = 0,
                           .type = 0,
                           .affinity = 1 },
            { .effect = 0,
                .hitrateFlags = 0,
                .hitrateAdj = 0,
                .damage = 0,
                .mult = 0,
                .type = 0,
                .affinity = 0 } },
        .name = "AGL-down\000\000cel\000\000\000er|>6|100\000" } };
#pragma vsstring(end)

char D_8004EDDC[][30] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 4, 6, 248, 248, 6, 4, 4, 0, 4, 250, 8, 8, 250, 252, 252, 0, 172,
        13, 1, 0, 6, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 2, 251, 251, 1, 1, 5, 5, 0, 2, 5, 5, 255, 255, 251, 251, 0, 208,
        7, 0, 0, 5, 0, 0, 0 },
    { 255, 255, 254, 255, 255, 251, 8, 5, 5, 253, 253, 2, 2, 0, 8, 251, 251, 3, 3, 254,
        254, 0, 136, 19, 2, 0, 1, 0, 254, 255 },
    { 1, 1, 254, 1, 1, 0, 10, 0, 4, 4, 0, 1, 1, 0, 10, 0, 252, 252, 0, 255, 255, 0, 100,
        25, 4, 0, 1, 0, 254, 255 },
    { 5, 5, 1, 0, 5, 5, 14, 253, 253, 5, 5, 5, 5, 0, 14, 3, 3, 251, 251, 251, 251, 0, 88,
        27, 6, 0, 2, 0, 255, 255 },
    { 0, 0, 20, 15, 0, 5, 5, 5, 5, 5, 5, 20, 251, 0, 5, 251, 251, 251, 251, 251, 20, 0,
        160, 15, 3, 0, 1, 0, 255, 255 },
    { 10, 10, 254, 0, 10, 10, 20, 5, 5, 5, 5, 246, 10, 0, 20, 251, 251, 251, 251, 20, 236,
        0, 64, 31, 8, 0, 3, 0, 255, 255 } };

int D_8004EECC[]
    = { 1, 0, 4096, 0, 2, 0, 0, 0, 4, 0, 0, 0, 8, 0, 0, 0, 16, 0, 2048, 0, 32 };

extern int randArr[97];
extern vs_main_HeapHeader* _cdReadBuffer;
extern padAct_t _padAct[2];
extern portInfo_t _portInfo[2];
extern vs_main_HeapHeader heapA;
extern vs_main_HeapHeader heapB;
extern int randIndex;
extern DslLOC cdReadLoc;
extern int D_800501CC;
extern int D_800501D0;
extern int D_800501D4;
extern int D_800501D8;
extern vs_main_CdQueueSlot _cdQueue[32];
extern struct {
    short processing;
    short queued;
} _cdQueueCount;
extern int vs_main_startState;
extern int _sfxData[VS_EFFECT00_DAT_SIZE];
extern int sp2;
extern int _resetEnabled;
extern u_int _buttonHeldFrameCount[];
extern vs_main_disk_t vs_main_disk;
extern char _dsControlBuf[11];
extern D_80055D58_t D_80055D58;
extern int sp;
extern int D_8005DBF4[5][6];
extern int D_8005E03C;
extern void* D_8005E08C;
extern int D_8005E0BC;
extern u_int _frameDuration;
extern int vs_main_saveGameClearData;
extern int _inGame;
extern u_short loadImageSource[][256];
extern int D_8005FE70;
extern int D_8005FE74;
extern int D_8005FE78;
extern int D_8005FE7C;
extern int D_8005FE80;
extern int D_8005FE84;
extern char vs_main_vibrationEnabled;
extern MATRIX D_1F800014_mat;
extern int vs_main_buttonsReleased;
extern vs_main_stickPos vs_main_stickPosBuf;

static void _loadBattlePrg()
{
    vs_main_CdFile cdFile;
    vs_main_CdQueueSlot* slot;

    cdFile.lba = VS_BATTLE_PRG_LBA;
    cdFile.size = VS_BATTLE_PRG_SIZE;
    slot = vs_main_allocateCdQueueSlot(&cdFile);
    vs_main_cdEnqueueUrgent(slot, vs_overlay_slots[0]);

    while (slot->state != vs_main_CdQueueStateLoaded) {
        vs_main_gametimeUpdate(0);
    }

    vs_main_freeCdQueueSlot(slot);

    cdFile.lba = VS_INITBTL_PRG_LBA;
    cdFile.size = VS_INITBTL_PRG_SIZE;
    slot = vs_main_allocateCdQueueSlot(&cdFile);
    vs_main_cdEnqueueUrgent(slot, vs_overlay_slots[1]);

    while (slot->state != vs_main_CdQueueStateLoaded) {
        vs_main_gametimeUpdate(0);
    }

    vs_main_freeCdQueueSlot(slot);
    vs_main_wait();
}

static void _loadTitlePrg()
{
    vs_main_CdFile cdFile;
    vs_main_CdQueueSlot* slot;

    cdFile.lba = VS_TITLE_PRG_LBA;
    cdFile.size = VS_TITLE_PRG_SIZE;

    slot = vs_main_allocateCdQueueSlot(&cdFile);
    vs_main_cdEnqueueUrgent(slot, vs_overlay_slots[0]);

    while (slot->state != vs_main_CdQueueStateLoaded) {
        vs_main_gametimeUpdate(0);
    }

    vs_main_freeCdQueueSlot(slot);
    vs_main_wait();
}

static void _loadEndingPrg()
{
    vs_main_CdFile cdFile;
    vs_main_CdQueueSlot* slot;

    cdFile.lba = VS_ENDING_PRG_LBA;
    cdFile.size = VS_ENDING_PRG_SIZE;

    slot = vs_main_allocateCdQueueSlot(&cdFile);
    vs_main_cdEnqueueUrgent(slot, vs_overlay_slots[0]);

    while (slot->state != vs_main_CdQueueStateLoaded) {
        vs_main_gametimeUpdate(0);
    }

    vs_main_freeCdQueueSlot(slot);
    vs_main_wait();
}

static void _initScreen(int w, int h, int arg2 __attribute__((unused)),
    __attribute__((unused)) int arg3, __attribute__((unused)) int arg4,
    __attribute__((unused)) int arg5)
{
    SetDefDispEnv(vs_main_dispEnv, 0, 0, w, h - 16);
    setRECT(&vs_main_dispEnv[0].screen, 0, 8, 256, 224);
    PutDispEnv(vs_main_dispEnv);
}

#define IMG_W(header) (header.wLo + (header.wHi << 8))
#define IMG_H(header) (header.hLo + (header.hHi << 8))

static void _displayLoadingScreen()
{
    RECT rect;

    _initScreen(0x140, 0xF0, D_8005E248, 0, 0, 0);
    setRECT(&rect, 0, 0, 1024, 512);
    ClearImage2(&rect, 0, 0, 0);
    DrawSync(0);
    VSync(2);
    setRECT(&rect, (320 - IMG_W(_nowLoading_header)) / 2,
        (224 - IMG_H(_nowLoading_header)) / 2, IMG_W(_nowLoading_header),
        IMG_H(_nowLoading_header));
    LoadImage(&rect, (u_long*)&_nowLoading_header + 1);
    setRECT(&rect, ((320 - IMG_W(_nowLoading_header)) / 2) + 320,
        (224 - IMG_H(_nowLoading_header)) / 2, IMG_W(_nowLoading_header),
        IMG_H(_nowLoading_header));
    LoadImage(&rect, (u_long*)&_nowLoading_header + 1);
    DrawSync(0);
    SetDispMask(1);
}

static void _bufferLoadingScreen()
{
    RECT rect;

    if (vs_main_frameBuf != 0) {
        setRECT(&rect, (320 - IMG_W(_nowLoading_header)) / 2,
            (224 - IMG_H(_nowLoading_header)) / 2, IMG_W(_nowLoading_header),
            IMG_H(_nowLoading_header));
    } else {
        setRECT(&rect, (320 - IMG_W(_nowLoading_header)) / 2 + 320,
            (224 - IMG_H(_nowLoading_header)) / 2, IMG_W(_nowLoading_header),
            IMG_H(_nowLoading_header));
    }
    LoadImage(&rect, _nowLoading_data);
    DrawSync(0);
}

void vs_main_resetGame()
{
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    while (DsControlB(DslPause, NULL, NULL) == 0)
        ;
    DsFlush();
    _padSetActData(0, 0, 0);
    _padSetActData(0, 1, 0);
    vs_main_padConnect(0, vs_main_padBuffer[0]);
    vs_main_padConnect(0x10, vs_main_padBuffer[1]);
    vs_sound_shutdown();
    SpuQuit();
    ResetGraph(3);
    VSync(10);
    vs_overlay_jumpToTitle(&sp2);
}

void vs_main_jumpToBattle()
{
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    _padSetActData(0, 0, 0);
    _padSetActData(0, 1, 0);
    vs_main_padConnect(0, vs_main_padBuffer[0]);
    vs_main_padConnect(0x10, vs_main_padBuffer[1]);
    ResetGraph(3);
    func_80012B78();
    func_80012B98();
    func_80012024();
    func_80012EBC();
    _displayLoadingScreen();
    _loadBattlePrg();
    vs_main_startState = 1;
    vs_overlay_jumpToBattle(&sp);
}

void vs_main_showEndingAndReturnToTitle()
{
    _inGame = 0;
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    _padSetActData(0, 0, 0);
    _padSetActData(0, 1, 0);
    vs_main_padConnect(0, vs_main_padBuffer[0]);
    vs_main_padConnect(0x10, vs_main_padBuffer[1]);
    ResetGraph(3);
    func_80012B78();
    func_80012B98();
    func_80042CB0();
    _loadEndingPrg();
    func_8006A5C0();
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    _padSetActData(0, 0, 0);
    _padSetActData(0, 1, 0);
    vs_main_padConnect(0, vs_main_padBuffer[0]);
    vs_main_padConnect(0x10, vs_main_padBuffer[1]);
    vs_sound_shutdown();
    SpuQuit();
    ResetGraph(3);
    vs_main_saveGameClearData = 1;
    vs_overlay_jumpToTitle(&sp2);
}

int vs_main_gametimeUpdate(int vsync)
{
    int vs = VSync(vsync);
    if (vsync != 1) {
        _asmNop();
    }

    _processCdQueue();

    if (vs_main_gametime.t.h >= 100) {
        return vs;
    }

    vs_main_gametime.t.f += vs_gametime_tickspeed;

    if (vs_main_gametime.t.f < 60) {
        return vs;
    }

    vs_main_gametime.t.f = 0;

    if (++vs_main_gametime.t.s < 60) {
        return vs;
    }

    vs_main_gametime.t.s = 0;

    if (++vs_main_gametime.t.m < 60) {
        return vs;
    }

    vs_main_gametime.t.m = 0;

    if (++vs_main_gametime.t.h >= 100) {
        vs_main_gametime.t.h = 100;
    }
    return vs;
}

static void _gpuSyncVoidCallback() { }

static void _vSyncVoidCallback() { }

static void _nop0() { }

static void _nop1() { }

static void _nop2() { }

static void _nop3() { }

static void _initRand()
{
    int i;

    srand(1);

    for (i = 0; i < (int)(sizeof(randArr) / sizeof(randArr[0])); ++i) {
        randArr[i] = rand();
    }
    randIndex = (sizeof(randArr) / sizeof(randArr[0])) - 1;
}

int vs_main_getRand(int max)
{
    int temp_s0;
    int var_a0;
    int var_v0;

    var_v0 = randArr[randIndex] * (sizeof(randArr) / sizeof(randArr[0]));

    if (var_v0 < 0) {
        var_v0 += 0x7FFF;
    }

    randIndex = var_v0 >> 0xF;

    temp_s0 = 0x7FFF - randArr[randIndex];
    randArr[randIndex] = rand();

    var_a0 = temp_s0 * max;

    if (var_a0 < 0) {
        var_a0 += 0x7FFF;
    }

    return var_a0 >> 0xF;
}

int vs_main_getRandSmoothed(int arg0)
{
    return (vs_main_getRand(arg0) + vs_main_getRand(arg0) + vs_main_getRand(arg0)
               + vs_main_getRand(arg0) + vs_main_getRand(arg0) + vs_main_getRand(arg0)
               + vs_main_getRand(arg0) + vs_main_getRand(arg0) + vs_main_getRand(arg0)
               + vs_main_getRand(arg0) + vs_main_getRand(arg0) + vs_main_getRand(arg0))
        / 12;
}

static void _sysInit()
{
    SetVideoMode(MODE_NTSC);
    SetDispMask(0);
    ResetCallback();
    ResetGraph(0);
    SetGraphDebug(0);
    InitCARD(0);
    StartCARD();
    _bu_init();
    PadInitDirect(vs_main_padBuffer[0], vs_main_padBuffer[1]);
    _padResetDefaults(0, vs_main_padBuffer[0]);
    _padResetDefaults(0x10, vs_main_padBuffer[1]);
    PadStartCom();
    _unlockPadModeSwitch();
    vs_main_resetPadAct();
    SsUtReverbOff();
    DsInit();
    _initRand();
    _resetEnabled = 1;
    vs_main_saveGameClearData = 0;
}

static void _sysReinit()
{
    int i;
    RECT rect0 __attribute__((unused));
    RECT rect1 __attribute__((unused)) = { .x = 819, .y = 819, .w = 819, .h = 0 };
    RECT rect2 = { .x = 0, .y = 0, .w = 1024, .h = 512 };

    ResetCallback();
    ResetGraph(1);
    SetGraphDebug(0);
    ClearImage(&rect2, 0, 0, 0);
    DrawSync(0);
    _displayLoadingScreen();
    SsUtReverbOn();
    InitGeom();
    DrawSyncCallback(_gpuSyncVoidCallback);
    VSyncCallback(_vSyncVoidCallback);
    vs_main_initHeap((vs_main_HeapHeader*)0x8010C000, 0xF2000);
    _initCdQueue();
    _diskReset();
    _loadMenuSound();
    vs_main_resetPadAct();
    _inGame = 0;
    _unlockPadModeSwitch();

    for (i = 31; i >= 0; --i) {
        _buttonHeldFrameCount[i] = 0;
    }
    vs_main_gametime.t.h = 0;
    vs_main_gametime.t.m = 0;
    vs_main_gametime.t.s = 0;
    vs_main_gametime.t.f = 0;
    D_80060068.unk0.unk0 = 0;
}

int vs_main_execTitle()
{
    vs_overlay_getSp(&sp);
    _sysReinit();
    _loadTitlePrg();
    vs_main_startState = vs_title_exec();
    vs_main_saveGameClearData = 0;
    _displayLoadingScreen();
    _loadBattlePrg();
    vs_overlay_getSp(&sp);
    _inGame = 1;
    vs_battle_exec();
    SetDispMask(0);
    vs_main_stopMusic();
    return 0;
}

void vs_main_exec()
{
    __main();
    _sysInit();
    vs_overlay_getSp(&sp2);
    vs_main_execTitle();
}

void vs_main_wait() { vs_overlay_wait(); }

void vs_main_enableReset(int enable) { _resetEnabled = enable; }

void func_80042CA0() { D_80060068.unk0.unk0 = 1; }

void func_80042CB0()
{
    char sp10[16];
    int j;
    int i;
    int var_s1;
    int var_t3;
    int new_var;
    int var_t4;
    signed char skillsLearned;
    vs_battle_equipment_t2* temp_t0;
    D_80060068_t* temp_t5;
    int v0;
    int v0_2;
    int v1;
    int v1_2;

    D_80061068 = D_800F1AB0;
    func_800A1108(0, sp10);

    v0 = (sp10[0] & 0x1F) << 8;
    v1 = (sp10[2] & 0x1F) << 0xA;
    D_80061068.unk4 = (D_80061068.unk4 & 0xE0FF) | v0;
    D_80061068.unk6 = (D_80061068.unk6 & 0x83FF) | v1;
    v1_2 = sp10[1] << 0xD;
    v0_2 = (sp10[3] >> 6) << 0xD;
    D_80061068.unk2 = ((D_80061068.unk2 & 0x1FFF) | v1_2);
    new_var = D_800F18E8 & 0x3FF;
    D_80061068.unk4 = ((D_80061068.unk4 & 0x9FFF) | v0_2);
    D_80061068.unk6 = ((D_80061068.unk6 & 0xFC00) | new_var);
    for (var_s1 = 0; var_s1 < 32; ++var_s1) {
        for (skillsLearned = 0, i = 0; i < 8; ++i) {
            u_int new_var2 = vs_main_skills[var_s1 * 8 + i].flags;
            skillsLearned = (*(int*)&skillsLearned * 2) | ((new_var2 >> 0xF) & 1);
        }
        vs_main_skillsLearned[var_s1] = skillsLearned;
    }
    temp_t0 = vs_battle_characterState->unk3C;
    temp_t5 = &D_80060068;
    temp_t5->unk0.currentHP = temp_t0->unk0[12];
    temp_t5->unk0.maxHP = temp_t0->unk0[13];
    temp_t5->unk0.currentMP = temp_t0->unk0[14];
    temp_t5->unk0.maxMP = temp_t0->unk0[15];
    temp_t5->unk0.unkC = temp_t0->unk0[17];
    temp_t5->unk0.unkE = temp_t0->unk0[18];
    temp_t5->unk0.unk10 = temp_t0->unk0[19];
    temp_t5->unk0.unk12 = temp_t0->unk0[20];
    temp_t5->unk0.unk14 = temp_t0->unk0[21];
    temp_t5->unk0.unk16 = temp_t0->unk0[22];
    temp_t5->unk0.unk18 = temp_t0->unk0[16];
    temp_t5->unk0.unk1A = temp_t0->unk954;
    temp_t5->unk0.unk1C = temp_t0->unk948;

    for (i = 0; i < 8; ++i) {
        temp_t5->unk0.unk20[i] = temp_t0->unk94C[i];
    }

    var_t4 = 0;
    var_t3 = 0;

    for (i = 0; i < 6; ++i) {
        temp_t5->unk0.unk28[i].unk0 = temp_t0->unk398[i].unk0;
        temp_t5->unk0.unk28[i].unk2 = temp_t0->unk398[i].unk2;

        for (j = 0; j < 4; ++j) {
            temp_t5->unk0.unk28[i].unk4[j] = temp_t0->unk398[i].unk8[j];
        }

        for (j = 0; j < 8; ++j) {
            temp_t5->unk0.unk28[i].unkC[j] = temp_t0->unk398[i].unk10[j];
        }
    }

    temp_t5->unk0.unk7C = vs_battle_characterState->unk0[8];
    temp_t5->unk0.unk80 = D_800F19D0[5];
    temp_t5->unk0.unk84 = D_800F19D0[8];

    for (var_s1 = 0; var_s1 < 16; ++var_s1) {
        func_80069FC4(var_s1, 0);
    }
    func_8008AB68();
}

void vs_main_padDisconnectAll()
{
    _portInfo[0].connected = 0;
    _portInfo[1].connected = 0;
}

static void _unlockPadModeSwitch()
{
    vs_main_padDisconnectAll();
    if (PadInfoMode(0, InfoModeCurExID, 0) != 0) {
        PadSetMainMode(0, 1, 2);
    }
}

static void _padResetDefaults(int portID, char padBuf[34] __attribute__((unused)))
{
    portInfo_t* port = &_portInfo[portID >> 4];
    port->exId = PadInfoMode(portID, InfoModeCurExID, 0);

    if (port->exId) {
        port->actData[0] = 0;
        port->actData[1] = 0;
        port->lock = 2;
        PadSetMainMode(portID, PadInfoMode(portID, InfoModeCurExOffs, 0), port->lock);
    } else {
        port->actData[0] = 0x40;
        port->actData[1] = 0;
    }
    PadSetAct(portID, port->actData, sizeof(port->actData));
    PadSetActAlign(portID, _actParams);
}

int vs_main_updatePadState(int portID, char padBuf[34])
{
    portInfo_t* port;
    char mode;
    int btnStates;

    if (padBuf[0] != 0) {
        port = &_portInfo[portID >> 4];
        port->lStickY = 128;
        port->lStickX = 128;
        port->rStickY = 128;
        port->rStickX = 128;
        return 0;
    }
    port = &_portInfo[portID >> 4];
    mode = PadInfoMode(portID, InfoModeCurID, 0);
    port->mode = mode;
    switch (mode) {
    case 1:
    case 2:
    case 3:
    case 6:
        btnStates = 0;
        break;
    default:
        btnStates = ~((padBuf[2] << 8) | padBuf[3]);
        break;
    }

    port->mode = PadInfoMode(portID, InfoModeCurID, 0);
    if ((port->mode == 5) || (port->mode == 7)) {
        port->rStickX = padBuf[6];
        port->rStickY = padBuf[7];
        port->lStickX = padBuf[4];
        port->lStickY = padBuf[5];
    } else {
        port->lStickY = 128;
        port->lStickX = 128;
        port->rStickY = 128;
        port->rStickX = 128;
    }
    port->states = btnStates;
    return btnStates;
}

void vs_main_padConnect(int portID, char padBuf[34])
{
    int dummy[5] __attribute__((unused));

    portInfo_t* port = &_portInfo[portID >> 4];
    int state = PadGetState(portID);

    if (state == PadStateFindPad) {
        port->connected = 0;
    }
    if (port->connected == 0) {
        PadSetAct(portID, port->actData, sizeof(port->actData));
        if ((state == PadStateFindCTP1)
            || ((state == PadStateStable) && (PadSetActAlign(portID, _actParams) != 0))) {
            _padResetDefaults(portID, padBuf);
            port->connected = 1;
        }
    }
}

static void _padSetActData(int port, int pos, int val)
{
    if (pos != 0) {
        _portInfo[port].actData[pos] = val;
    } else if (_portInfo[port].exId) {
        _portInfo[port].actData[0] = val;
    } else {
        _portInfo[port].actData[0] = 0x40;
    }
}

static char _padGetActData(int port, int pos) { return _portInfo[port].actData[pos]; }

static int func_800433B4(char* arg0, u_int arg1, short arg2)
{
    int i;
    int ret = 0;

    if (arg1 == 0xFF) {
        for (i = 0; i < 2; ++i) {
            if (_padAct[i].unk8 == 0) {
                ret = i + 1;
                break;
            }
        }
    } else if ((arg1 - 1) < 2) {
        ret = arg1;
    }

    if (ret != 0) {
        i = ret - 1;
        _padAct[i].unkC = arg0;
        _padAct[i].unk10[4] = 1;
        _padAct[i].unk10[10] = *arg0;
        _padAct[i].unk10[11] = 0;
        _padAct[i].unk10[5] = 0;
        _padAct[i].unk10[7] = 0;
        _padAct[i].unk10[1] = 0;
        _padAct[i].unk8 = 1;
        _padAct[i].unkA = arg2;
        return ret;
    }
    return 0;
}

static int func_80043470(int arg0)
{
    int i = arg0 - 1;
    _padAct[i].unk10[7] = 0;
    _padAct[i].unk10[1] = 0;
    _padAct[i].unkC = 0;
    _padAct[i].unk8 = 0;

    return arg0;
}

static int func_800434A4(unsigned int arg0, int arg1)
{
    int i;
    if (arg0 - 1 < 2) {
        return func_80043470(arg0);
    }
    if (arg0 != 0) {
        return 0;
    }
    if (arg1 != 0) {
        for (i = 0; i < 2; ++i) {
            if (_padAct[i].unkA == arg1) {
                func_80043470(i + 1);
            }
        }
    } else {
        for (i = 0; i < 2;) {
            func_80043470(++i);
        }
    }
    return 1;
}

static int func_80043554(int arg0)
{
    int v0 = arg0 - 1;
    _padAct[v0].unk8 = 0;
    return arg0;
}

static int func_8004357C(int arg0)
{
    int i;

    if ((arg0 - 1u) < 2) {
        return func_80043554(arg0);
    }

    if (arg0 != 0) {
        return 0;
    }

    for (i = 0; i < 2;) {
        func_80043554(++i);
    }

    return 1;
}

static int func_800435DC(int arg0)
{
    int v0 = arg0 - 1;
    _padAct[v0].unk8 = 1;
    return arg0;
}

static int func_80043608(int arg0)
{
    int i;

    if ((arg0 - 1u) < 2) {
        return func_800435DC(arg0);
    }

    if (arg0 != 0) {
        return 0;
    }

    for (i = 0; i < 2;) {
        func_800435DC(++i);
    }

    return 1;
}

void vs_main_resetPadAct()
{
    int i;

    vs_main_padDisconnectAll();

    for (i = 0; i < 2; ++i) {
        _padAct[i].unkC = NULL;
        _padAct[i].unk10[7] = 0;
        _padAct[i].unk10[1] = 0;
        _padAct[i].unk8 = 0;
    }
}

static inline int _abs2(int arg) { return arg < 0 ? arg += 0xFF : arg; }

void vs_main_setVibrateParams()
{
    int temp_a0;
    int var_a2_2;
    int i;
    int j;
    int var_v0;
    char* temp_t1;
    int new_var;

    _padAct[0].unk0[1] = 0;
    _padAct[0].unk0[0] = 0;

    for (j = 0; j < 2; ++j) {
        if (_padAct[j].unk8 == 0) {
            continue;
        }

        temp_t1 = _padAct[j].unkC;

        if (temp_t1 != 0) {
            for (i = 0; i < 2; ++i) {
                int(*a1)[6] = (int(*)[6])_padAct[j].unk10;
                if (a1[i][5] == 0) {
                    temp_a0 = a1[i][4];
                    a1[i][5] = temp_t1[temp_a0++];
                    a1[i][1] = a1[i][3] = temp_t1[temp_a0++] << 8;
                    if (a1[i][5] == 0) {
                        a1[i][1] = 0;
                        a1[i][0] = 0;
                    } else {
                        new_var = i != 0;
                        a1[i][3] = temp_t1[temp_a0 + 1] << 8;
                        if (new_var) {
                            a1[i][2] = ((a1[i][3] - a1[i][1]) / a1[i][5]);
                        } else {
                            a1[i][2] = 0;
                        }
                        a1[i][0] = 1;
                        a1[i][4] += 2;
                    }
                }
                if (a1[i][5] != 0) {
                    a1[i][1] += a1[i][2];
                    a1[i][5] -= 1;
                } else {
                    a1[i][1] = a1[i][3];
                }

                _padAct[0].unk0[i] += a1[i][1];
                if (_padAct[0].unk0[i] > 0xFF00) {
                    _padAct[0].unk0[i] = 0xFF00;
                } else if (_padAct[0].unk0[i] < 0) {
                    _padAct[0].unk0[i] = 0;
                }
            }
            _padAct[j].unk8 = _padAct[j].unk10[0] | _padAct[j].unk10[6];
            if (_padAct[j].unk8 == 0) {
                _padAct[j].unkC = 0;
            }
            continue;
        }
        _padAct[j].unk8 = 0;
    }

    if (vs_main_vibrationEnabled != 0) {
        _padSetActData(0, 0, _abs2(_padAct[0].unk0[0]) >> 8);
        _padSetActData(0, 1, _abs2(_padAct[0].unk0[1]) >> 8);
    }
}

void func_800438C8(int arg0)
{
    int new_var4;
    int new_var;
    int new_var3;
    int new_var2;

    if (arg0 < D_8004A504[0]) {
        new_var = 5;
        new_var3 = 4;
        new_var4 = 6;
        new_var2 = 7;
        func_800433B4(&D_8004A504[(&D_8004A504[arg0 * new_var3])[new_var3]
                          + ((&D_8004A504[arg0 * new_var3])[new_var] << 8)
                          + ((&D_8004A504[arg0 * new_var3])[new_var4] << 16)
                          + ((&D_8004A504[arg0 * new_var3])[new_var2] << 24)],
            0xFF, 0x80);
    }
}

int vs_main_processPadState()
{
    int dummy[2] __attribute__((unused));
    int i;
    u_int btnState;

    vs_main_buttonsState = vs_main_updatePadState(0, vs_main_padBuffer[0]) & 0xFFFF;
    vs_main_buttonsState |= vs_main_updatePadState(16, vs_main_padBuffer[1]) << 16;
    vs_main_padConnect(0, vs_main_padBuffer[0]);
    vs_main_padConnect(16, vs_main_padBuffer[1]);

    switch (_portInfo[0].mode) {
    case 4:
        vs_main_stickPosBuf.lStickY = 128;
        vs_main_stickPosBuf.lStickX = 128;
        vs_main_stickPosBuf.rStickY = 128;
        vs_main_stickPosBuf.rStickX = 128;
        break;
    case 7:
        vs_main_stickPosBuf.rStickX = _portInfo[0].rStickX;
        vs_main_stickPosBuf.rStickY = _portInfo[0].rStickY;
        vs_main_stickPosBuf.lStickX = _portInfo[0].lStickX;
        vs_main_stickPosBuf.lStickY = _portInfo[0].lStickY;

        if (_portInfo[0].rStickX < 16) {
            vs_main_buttonsState |= PADLleft;
        }
        if (_portInfo[0].rStickX >= 241) {
            vs_main_buttonsState |= PADLright;
        }

        if (_portInfo[0].rStickY < 16) {
            vs_main_buttonsState |= PADLup;
        }
        if (_portInfo[0].rStickY >= 241) {
            vs_main_buttonsState |= PADLdown;
        }

        if (_portInfo[0].lStickX < 32) {
            vs_main_buttonsState |= PADj;
        }
        if (_portInfo[0].lStickX >= 225) {
            vs_main_buttonsState |= PADj;
        }

        if (_portInfo[0].lStickY < 32) {
            vs_main_buttonsState |= PADj;
        }
        if (_portInfo[0].lStickY >= 225) {
            vs_main_buttonsState |= PADj;
        }
        break;
    default:
        vs_main_stickPosBuf.lStickY = 128;
        vs_main_stickPosBuf.lStickX = 128;
        vs_main_stickPosBuf.rStickY = 128;
        vs_main_stickPosBuf.rStickX = 128;
        break;
    }

    vs_main_buttonsPressed = ~vs_main_buttonsPreviousState & vs_main_buttonsState;
    vs_main_buttonsReleased = vs_main_buttonsPreviousState & ~vs_main_buttonsState;
    vs_main_buttonsPreviousState = vs_main_buttonsState;

    btnState = vs_main_buttonsState;
    for (i = 0; i < 32; ++i, btnState >>= 1) {
        if (btnState & 1) {
            _buttonHeldFrameCount[i] += vs_gametime_tickspeed;
        } else {
            _buttonHeldFrameCount[i] = 0;
        }
    }

    vs_main_buttonRepeat = vs_main_buttonsPressed;

    for (i = 0; i < 32; ++i) {
        if ((_buttonHeldFrameCount[i] >= 20) && !((_buttonHeldFrameCount[i] - 20) & 3)) {
            vs_main_buttonRepeat |= 1 << i;
        }
    }

#define VS_RESET (PADstart | PADselect | PADR1 | PADR2 | PADL1 | PADL2)

    if ((_resetEnabled != 0) && ((vs_main_buttonsPreviousState & VS_RESET) == VS_RESET)
        && (vs_main_buttonsPressed & VS_RESET)) {
        vs_main_settings.monoSound = 0;
        vs_main_settings.vibrationOn = 1;
        vs_main_resetGame();
    }

#undef VS_RESET

    return 1;
}

void vs_main_freeHeapR(void* block)
{
    vs_main_HeapHeader* var_a1 = heapA.prev;
    vs_main_HeapHeader* target = (vs_main_HeapHeader*)block - 1;

    for (; var_a1 >= target || target >= var_a1->next; var_a1 = var_a1->prev) {
        if (var_a1 >= var_a1->next && ((var_a1 < target) || (target < var_a1->next))) {
            break;
        }
    }

    if ((target + target->blockSz) == var_a1->next) {
        target->blockSz += var_a1->next->blockSz;
        target->next = var_a1->next->next;
        target->next->prev = target;
    } else {
        target->next = var_a1->next;
        target->next->prev = target;
    }

    if ((var_a1 + var_a1->blockSz) == target) {
        var_a1->blockSz += target->blockSz;
        var_a1->next = target->next;
        var_a1->next->prev = var_a1;
        return;
    }
    var_a1->next = target;
    target->prev = var_a1;
}

void vs_main_freeHeap(void* block)
{
    vs_main_HeapHeader* var_a1 = heapA.next;
    vs_main_HeapHeader* target = (vs_main_HeapHeader*)block - 1;

    for (; var_a1 >= target || target >= var_a1->next; var_a1 = var_a1->next) {
        if (var_a1 >= var_a1->next && ((var_a1 < target) || (target < var_a1->next))) {
            break;
        }
    }

    if ((target + target->blockSz) == var_a1->next) {
        target->blockSz += var_a1->next->blockSz;
        target->next = var_a1->next->next;
        target->next->prev = target;
    } else {
        target->next = var_a1->next;
        target->next->prev = target;
    }

    if ((var_a1 + var_a1->blockSz) == target) {
        var_a1->blockSz += target->blockSz;
        var_a1->next = target->next;
        var_a1->next->prev = var_a1;
        return;
    }
    var_a1->next = target;
    target->prev = var_a1;
}

void* vs_main_allocHeapR(u_int size)
{
    vs_main_HeapHeader* var_a1;
    vs_main_HeapHeader* var_a2;
    u_int blockSz;

    blockSz = ((size + 15) >> 4) + 1;
    var_a2 = &heapA;
    var_a1 = heapA.prev;

    while (1) {
        if (var_a1->blockSz >= blockSz) {
            if (var_a1->blockSz == blockSz) {
                var_a2->prev = var_a1->prev;
                var_a1->prev->next = var_a1->next;
            } else {
                var_a1->blockSz = var_a1->blockSz - blockSz;
                var_a1 += var_a1->blockSz;
                var_a1->blockSz = blockSz;
            }
            return (u_long*)(var_a1 + 1);
        }
        var_a2 = var_a1;
        if (var_a1 == &heapA) {
            return 0;
        }
        var_a1 = var_a1->prev;
    }
}

void* vs_main_allocHeap(u_int size)
{
    u_int blockSz;
    vs_main_HeapHeader* var_a1;
    vs_main_HeapHeader* var_v1;

    var_v1 = &heapA;
    var_a1 = heapA.next;
    blockSz = ((size + 0xF) >> 4) + 1;

    while (1) {
        if (var_a1->blockSz >= blockSz) {
            if (var_a1->blockSz == blockSz) {
                var_v1->next = var_a1->next;
                var_a1->next->prev = var_a1->prev;
            } else {
                vs_main_HeapHeader* temp_v1 = var_a1 + blockSz;
                temp_v1->blockSz = var_a1->blockSz - blockSz;
                temp_v1->prev = var_a1->prev;
                temp_v1->next = var_a1->next;
                temp_v1->prev->next = temp_v1;
                temp_v1->next->prev = temp_v1;
                var_a1->blockSz = blockSz;
            }
            return (u_long*)(var_a1 + 1);
        }
        var_v1 = var_a1;
        if (var_a1 == &heapA) {
            return 0;
        }
        var_a1 = var_a1->next;
    }
}

void vs_main_initHeap(vs_main_HeapHeader* node, u_int value)
{
    heapA.prev = node;
    heapA.next = node;
    heapA.blockSz = 0;
    node->prev = &heapA;
    node->next = &heapA;
    node->blockSz = value / 16 - 1;
    heapB.prev = &heapB;
    heapB.next = &heapB;
    heapB.blockSz = 0;
}

static void _diskReadCallback(u_char intr, u_char result[] __attribute__((unused)),
    u_long* arg2 __attribute__((unused)))
{

    if ((intr == DslDiskError) || (intr == DslNoIntr)
        || (vs_main_disk.state == diskReadError)) {
        DsReadyCallback(0);
        DsEndReadySystem();
        vs_main_disk.state = diskReadError;
        return;
    }

    if (intr != DslDataReady) {
        return;
    }

    vs_main_disk.state = diskReadReady;

    if (vs_main_disk.bufferMode == cdBufferModeNone) {
        DsGetSector(vs_main_disk.vram + vs_main_disk.sectorBufIndex * 2048, 512);
    } else {
        DsGetSector(_cdReadBuffer + vs_main_disk.unk3C * 128, 512);
        if (++vs_main_disk.unk3C >= 16) {
            vs_main_disk.unk3C = 0;
        }
    }

    switch (vs_main_disk.bufferMode) {
    case cdBufferModeNone:
        if (++vs_main_disk.sectorBufIndex >= vs_main_disk.sectorCount) {
            vs_main_disk.state = diskIdle;
        }
        break;
    case cdBufferModeBuffered:
        ++vs_main_disk.unk38;
        ++vs_main_disk.unk34;
        break;
    case cdBufferModeManual:
        ++vs_main_disk.unk38;
        if (++vs_main_disk.ringBufIndex >= 16) {
            vs_main_disk.ringBufIndex = 0;
        }
        break;
    default:
        break;
    }

    if (++vs_main_disk.unk4 >= vs_main_disk.sectorCount) {
        DsEndReadySystem();
    }
}

static void _diskReadCommandCallback(u_char intr, u_char result[] __attribute__((unused)))
{
    switch (intr) {
    case DslComplete:
        DsStartReadySystem(_diskReadCallback, -1);
        return;
    case DslDiskError:
        break;
    default:
        break;
    case DslNoResult:
    case DslNoIntr:
        return;
    }
    vs_main_disk.state = diskReadError;
}

static void _diskSeekCommandCallback(u_char intr, u_char result[] __attribute__((unused)))
{
    switch (intr) {
    case DslNoIntr:
        break;
    case DslComplete:
        vs_main_disk.state = diskIdle;
        break;
    case DslDiskError:
        vs_main_disk.state = diskReadError;
        break;
    case DslNoResult:
        break;
    default:
        vs_main_disk.state = diskReadError;
        break;
    }
}

static void _diskPcmReadReady(u_char intr, u_char result[])
{
    switch (intr) {
    case DslComplete:
        DsReadyCallback(NULL);
        vs_main_disk.state = diskIdle;
        break;
    case DslDataReady:
        if (!(result[4] & 0x80)) {
            D_800501CC = ((result[1] >> 4) * 0xA) + (result[1] & 0xF);
            D_800501D0 = result[3];
            D_800501D4 = result[4];
            D_800501D8 = (result[6] << 8) | result[7];
        }
        break;
    case DslDiskError:
        DsReadyCallback(NULL);
        vs_main_disk.state = diskCommandFailed;
        break;
    }
}

static int _diskGetState() { return vs_main_disk.state; }

static void _diskClearError()
{
    if (vs_main_disk.state == diskReadError) {
        vs_main_disk.state = diskIdle;
    }
}

static int _diskInitRead(int sector, u_int bytes, void* vram)
{
    if (vs_main_disk.state == diskIdle) {
        vs_main_disk.cdSector = sector;
        vs_main_disk.byteCount = bytes;
        vs_main_disk.vram = vram;
        vs_main_disk.ringBufIndex = 0;
        vs_main_disk.unk3C = 0;
        vs_main_disk.sectorBufIndex = 0;
        vs_main_disk.unk34 = 0;
        vs_main_disk.unk4 = 0;
        vs_main_disk.unk3 = 0;
        vs_main_disk.unk38 = 0;
        vs_main_disk.sectorCount = bytes / 2048;
        if (bytes % 2048) {
            ++vs_main_disk.sectorCount;
        }
        DsIntToPos(sector, &vs_main_disk.cdLoc);
        vs_main_disk.state = diskReadInit;
        return 1;
    }
    return 0;
}

static void func_800443CC()
{
    DslATV vol;
    int i;
    u_int seconds;

    switch (vs_main_disk.state) {
    case diskIdle:
    default:
        break;
    case diskReadXaInit:
        if (DsSystemStatus() == DslReady) {
            vs_main_disk.unk1 = 0;
            vs_main_disk.cdLoc.minute = 0;
            while (DsControlB(DslSetmode, _dsControlBuf, NULL) == 0)
                ;
            VSync(3);
            vol.val2 = 0x80;
            vol.val0 = 0x80;
            vol.val3 = 0;
            vol.val1 = 0;
            DsMix(&vol);
            func_80012918(vs_main_disk.byteCount);
            vs_sound_setCdVol(0x7F);
            vs_main_disk.pcm.file = 1;
            vs_main_disk.pcm.chan = 0;
            DsControl(DslSetfilter, (char*)&vs_main_disk.pcm, NULL);
            DsIntToPos(vs_main_disk.cdSector, &vs_main_disk.cdLoc);
            vs_main_disk.commandId = DsPacket(
                DslModeRT | DslModeSF, &vs_main_disk.cdLoc, DslReadS, NULL, -1);
            DsReadyCallback(_diskPcmReadReady);
            vs_main_disk.state = diskStreamXa;
        }
        if (vs_main_disk.commandId == 0) {
            DsReadyCallback(0);
            vs_main_disk.state = diskCommandFailed;
            ++vs_main_disk.unk3;
        }
        break;
    case diskReadInit: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            vs_main_disk.unk4 = 0;
            vs_main_disk.sectorBufIndex = 0;
            if (vs_main_disk.byteCount != 0) {
                vs_main_disk.state = diskReadReady;
                vs_main_disk.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &vs_main_disk.cdLoc, DslReadN, _diskReadCommandCallback, -1);
            } else {
                vs_main_disk.state = diskSeekReady;
                vs_main_disk.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &vs_main_disk.cdLoc, DslSeekL, _diskSeekCommandCallback, -1);
            }

            if (vs_main_disk.commandId == 0) {
                vs_main_disk.state = diskReadError;
                ++vs_main_disk.unk3;
            }
        }
        break;
    }
    case diskCommandFailed: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            vs_main_disk.unk4 = 0;
            ++vs_main_disk.unk3;
            seconds = _frameDuration / 60;
            if (seconds < 420) {
                DsIntToPos(vs_main_disk.cdSector + (seconds * 75) + (_frameDuration % 60),
                    &cdReadLoc);
                vol.val2 = 0x80;
                vol.val0 = 0x80;
                vol.val3 = 0;
                vol.val1 = 0;
                DsMix(&vol);
                func_80012918(0);
                func_80012940(0x3C, vs_main_disk.byteCount);
                vs_main_disk.pcm.file = 1;
                vs_main_disk.pcm.chan = 0;
                DsControl(DslSetfilter, (char*)&vs_main_disk.pcm, NULL);
                vs_main_disk.commandId
                    = DsPacket(DslModeRT | DslModeSF, &cdReadLoc, DslReadS, NULL, -1);
                DsReadyCallback(_diskPcmReadReady);
                vs_main_disk.state = diskStreamXa;
            } else {
                vs_main_disk.commandId = DsCommand(DslModeSF | DslModeDA, NULL, NULL, -1);
                vs_main_disk.state = diskIdle;
                DsReadyCallback(0);
            }
        }
        if (vs_main_disk.commandId == 0) {
            vs_main_disk.state = diskCommandFailed;
            ++vs_main_disk.unk3;
        }
        break;
    }
    case diskReadError: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            vs_main_disk.unk4 = 0;
            vs_main_disk.sectorBufIndex = 0;
            ++vs_main_disk.unk3;

            if (vs_main_disk.byteCount != 0) {
                vs_main_disk.state = diskReadReady;
                vs_main_disk.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &vs_main_disk.cdLoc, DslReadN, _diskReadCommandCallback, -1);
            } else {
                vs_main_disk.state = diskSeekReady;
                vs_main_disk.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &vs_main_disk.cdLoc, DslSeekL, _diskSeekCommandCallback, -1);
            }

            if (vs_main_disk.commandId == 0) {
                vs_main_disk.state = diskReadError;
                ++vs_main_disk.unk3;
            }
        }
        break;
    }
    case diskStreamXaEnd:
        func_80012918(0);
        vs_main_disk.commandId = DsCommand(DslPause, NULL, NULL, -1);
        if (vs_main_disk.commandId > 0) {
            vs_main_disk.state = diskIdle;
        }
        DsReadyCallback(NULL);
        vs_main_disk.unk1 = 128;
        vs_main_disk.cdLoc.minute = 128;
        while (DsControlB(DslSetmode, _dsControlBuf, NULL) == 0)
            ;
        VSync(3);
        break;
    }

    if (vs_main_disk.bufferMode != cdBufferModeNone) {
        for (i = 0; i < 16; ++i) {
            if (vs_main_disk.sectorBufIndex >= vs_main_disk.unk38) {
                return;
            }
            if (vs_main_disk.bufferMode == cdBufferModeBuffered) {
                vs_main_memcpy(
                    ((char*)vs_main_disk.vram + (vs_main_disk.sectorBufIndex * 2048)),
                    _cdReadBuffer + (vs_main_disk.ringBufIndex * 128), 2048);

                ++vs_main_disk.ringBufIndex;
                if (vs_main_disk.ringBufIndex >= 16) {
                    vs_main_disk.ringBufIndex = 0;
                }
                --vs_main_disk.unk34;
                ++vs_main_disk.sectorBufIndex;
                if (vs_main_disk.sectorBufIndex >= vs_main_disk.sectorCount) {
                    vs_main_disk.state = diskIdle;
                    vs_main_freeHeapR(_cdReadBuffer);
                    _cdReadBuffer = NULL;
                }
            } else if (vs_main_disk.bufferMode == cdBufferModeManual) {
                ++vs_main_disk.sectorBufIndex;
                if ((vs_main_disk.sectorBufIndex >= vs_main_disk.sectorCount)
                    && (vs_sound_spuTransferring() == 0)) {
                    vs_main_disk.state = diskIdle;
                    vs_main_freeHeapR(_cdReadBuffer);
                    _cdReadBuffer = NULL;
                }
            }
        }
    }
}

int vs_main_diskLoadFile(int sector, int bytes, void* vram)
{
    int result = _diskInitRead(sector, bytes, vram);
    if (result != 0) {
        int seekReady = diskSeekReady;
        int readReady = diskReadReady;

        while (1) {
            if (_diskGetState() == seekReady) {
                vs_main_gametimeUpdate(0);
            } else if (_diskGetState() == readReady) {
                vs_main_gametimeUpdate(0);
            } else if (_diskGetState() == 3) {
                vs_main_gametimeUpdate(0);
            } else if (_diskGetState() == diskReadInit) {
                vs_main_gametimeUpdate(0);
            } else
                break;
        }
    }
    return result;
}

int vs_main_streamXa(int sector, int byteCount)
{
    if (vs_main_disk.state == diskIdle) {
        vs_main_disk.cdSector = sector;
        vs_main_disk.byteCount = byteCount;
        vs_main_disk.ringBufIndex = 0;
        vs_main_disk.unk3C = 0;
        vs_main_disk.sectorBufIndex = 0;
        vs_main_disk.unk34 = 0;
        vs_main_disk.unk4 = 0;
        vs_main_disk.unk3 = 0;
        vs_main_disk.unk38 = 0;
        vs_main_disk.state = diskReadXaInit;
        return 1;
    }
    return 0;
}

int vs_main_checkStreamXaEnd()
{
    if (vs_main_disk.state == diskStreamXa) {
        vs_main_disk.state = diskStreamXaEnd;
        return 1;
    }
    return 0;
}

static void _diskReset()
{
    while (DsControlB(DslPause, NULL, NULL) == 0)
        ;
    DsFlush();
    vs_main_disk.unk1 = 128;
    vs_main_disk.cdLoc.minute = 128;
    vs_main_disk.unk2 = 0;
    vs_main_disk.state = diskIdle;
    vs_main_disk.bufferMode = cdBufferModeNone;
    _cdReadBuffer = NULL;
    while (DsControlB(DslSetmode, _dsControlBuf, NULL) == 0)
        ;
    VSync(3);
}

static void _initCdQueue()
{
    int i;

    for (i = 31; i >= 0; --i) {
        _cdQueue[i].state = vs_main_CdQueueStateFree;
    }
    *(int*)&_cdQueueCount = 0;
}

vs_main_CdQueueSlot* vs_main_allocateCdQueueSlot(vs_main_CdFile* file)
{
    int i;

    for (i = 0; i < 32; ++i) {
        if (_cdQueue[i].state == vs_main_CdQueueStateFree) {
            _cdQueue[i].state = vs_main_CdQueueStateAllocated;
            _cdQueue[i].cdFile = *file;
            return &_cdQueue[i];
        }
    }
    vs_main_nop9(162, 0);
}

void vs_main_freeCdQueueSlot(vs_main_CdQueueSlot* slot)
{
    u_short state = slot->state - 2;
    if (state < vs_main_CdQueueStateLoaded - 2) {
        vs_main_nop9(163, 0);
    }
    slot->state = vs_main_CdQueueStateFree;
}

void vs_main_cdEnqueue(vs_main_CdQueueSlot* slot, void* vram)
{
    slot->state = vs_main_CdQueueStateEnqueued;
    slot->vram = vram;
    slot->unkC = 0;
    slot->priority = _cdQueueCount.queued++;
}

void vs_main_cdEnqueueUrgent(vs_main_CdQueueSlot* slot, void* vram)
{
    int i;
    vs_main_CdQueueSlot* queue = _cdQueue;

    for (i = 0; i < 32; ++i, ++queue) {
        if (queue->state == vs_main_CdQueueStateEnqueued) {
            ++queue->priority;
        }
    }
    slot->state = vs_main_CdQueueStateEnqueued;
    slot->vram = vram;
    slot->unkC = 0;
    slot->priority = 0;
    ++_cdQueueCount.queued;
}

static void _nop4() { }

static void _processCdQueue()
{
    ++vs_main_disk.framesSinceLastRead;

    if (*(int*)&_cdQueueCount != 0) {
        vs_main_CdQueueSlot* slot = _cdQueue;
        int i = _diskGetState();
        if (i == diskIdle) {
            for (i = 0; i < 32; ++i, ++slot) {
                if (slot->state == vs_main_CdQueueStateEnqueued) {
                    if (slot->priority == 0) {
                        slot->state = vs_main_CdQueueStateReading;
                        _diskInitRead(slot->cdFile.lba, slot->cdFile.size, slot->vram);
                        vs_main_disk.framesSinceLastRead = 0;
                        --_cdQueueCount.queued;
                        ++_cdQueueCount.processing;
                    } else {
                        --slot->priority;
                    }
                } else if (slot->state == vs_main_CdQueueStateReading) {
                    slot->state = vs_main_CdQueueStateLoaded;
                    --_cdQueueCount.processing;
                }
            }
        }
    }
    func_800443CC();
}

static int func_80044D94() { return func_80011F90(); }

static void func_80044DB4() { func_80012004(); }

static void func_80044DD4() { func_80012468(); }

static int func_80044DF4(int id)
{
    u_int new_var;
    int var_a1;

    if (id != 0) {
        if (vs_main_soundData.unk14[id - 1] != 0xFFFF) {
            func_80011FDC(vs_main_soundData.unk14[id - 1]);
            vs_main_soundData.unk14[id - 1] = 0xFFFF;
        }
        if (vs_main_soundData.currentMusicId == id) {
            vs_main_soundData.currentMusicId = 0;
            vs_main_soundData.currentMusicData = NULL;
            vs_main_soundData.unk4 = 0xFFFF;
        }
        return 1;
    }
    func_80012B78();
    vs_main_soundData.currentMusicId = 0;
    vs_main_soundData.currentMusicData = NULL;
    vs_main_soundData.unk4 = 0xFFFF;

    new_var = 0xFFFF;
    for (var_a1 = 3; var_a1 >= 0; --var_a1) {
        vs_main_soundData.unk14[var_a1] = new_var;
    }
    return 1;
}

static int func_80044EC8(int id)
{
    u_int temp_v0;

    if (id != 0) {
        if (vs_main_soundData.musicData[id - 1] != 0) {
            vs_main_soundData.currentMusicId = id;
            vs_main_soundData.currentMusicData = vs_main_soundData.musicData[id - 1];
            temp_v0 = func_800120E8(vs_main_soundData.currentMusicData);
            if (temp_v0 != 0) {
                vs_main_soundData.unk14[id - 1] = temp_v0;
                vs_main_soundData.unk4 = temp_v0;
            }
            vs_main_soundData.unk8 = vs_main_soundData.musicIds[id - 1];
        }
        return D_8005E03C;
    }
    return 0;
}

static int func_80044F60(int id, int arg1, u_int arg2)
{
    u_int temp_v0;

    if (id != 0) {
        if (vs_main_soundData.musicData[id - 1] != 0) {
            vs_main_soundData.currentMusicId = id;
            vs_main_soundData.currentMusicData = vs_main_soundData.musicData[id - 1];
            temp_v0 = func_80012080(vs_main_soundData.currentMusicData, arg2, arg1);
            if (temp_v0 != 0) {
                vs_main_soundData.unk14[id - 1] = temp_v0;
                vs_main_soundData.unk4 = temp_v0;
            }
            vs_main_soundData.unk8 = vs_main_soundData.musicIds[id - 1];
        }
        return D_8005E03C;
    }
    return 0;
}

static int func_80045000(int id, int arg1, int arg2)
{
    u_int temp_v0;

    if (id != 0) {
        if (vs_main_soundData.musicData[id - 1] != 0) {
            vs_main_soundData.currentMusicId = id;
            vs_main_soundData.currentMusicData = vs_main_soundData.musicData[id - 1];
            func_800128A0(0, arg2, arg1);
            temp_v0 = func_80011FB4(vs_main_soundData.currentMusicData);
            if (temp_v0 != 0) {
                vs_main_soundData.unk14[id - 1] = temp_v0;
                vs_main_soundData.unk4 = temp_v0;
                func_800128A0(0, arg2, arg1);
            }
            vs_main_soundData.unk8 = vs_main_soundData.musicIds[id - 1];
        }
        return D_8005E03C;
    }
    return 0;
}

static int vs_main_getCurrentMusicId() { return vs_main_soundData.currentMusicId; }

int func_800450E4()
{
    if (vs_main_soundData.currentMusicId != 0) {
        return vs_main_soundData.musicIds[vs_main_soundData.currentMusicId - 1];
    }
    return 0;
}

int vs_main_loadMusicSlot(int id, int targetSlot)
{
    vs_main_CdFile cdFile;

    if (id > 0 && targetSlot > 0) {
        int slot = targetSlot - 1;

        if (targetSlot < 5) {
            if (vs_main_soundData.musicIds[slot] != id) {
                do {
                    if (vs_main_soundData.musicData[slot] != 0) {
                        nop10(142, 0);
                        vs_main_freeMusic(targetSlot);
                    }
                } while (0);

                cdFile.lba = _musicLBAs[id];
                cdFile.size = _musicFileSizes[id];

                if ((vs_main_soundData.musicQueueSlot[slot] != 0)
                    && (vs_main_soundData.musicQueueSlot[slot]
                        != (vs_main_CdQueueSlot*)-1)) {
                    vs_main_nop9(0x98, 0);
                }

                vs_main_soundData.musicQueueSlot[slot]
                    = vs_main_allocateCdQueueSlot(&cdFile);

                if (vs_main_soundData.musicData[slot] != 0) {
                    vs_main_nop9(0x8E, 0);
                }
                vs_main_soundData.musicData[slot] = vs_main_allocHeapR(cdFile.size);
                vs_main_cdEnqueue(vs_main_soundData.musicQueueSlot[slot],
                    vs_main_soundData.musicData[slot]);
                vs_main_soundData.musicIds[slot] = id;
            }
            return targetSlot;
        }
    }
    vs_main_nop9(0x8E, 0);
    return 0;
}

static int _loadMusicIntoFreeSlot(int id)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if (vs_main_soundData.musicData[i] == 0) {
            return vs_main_loadMusicSlot(id, i + 1);
        }
    }
    return 0;
}

static int vs_main_clearMusicLoadSlot(u_int slot)
{
    if ((slot - 1) < 4) {
        if (vs_main_soundData.musicQueueSlot[slot - 1] != 0) {
            if (vs_main_soundData.musicQueueSlot[slot - 1]->state
                == vs_main_CdQueueStateLoaded) {
                vs_main_freeCdQueueSlot(vs_main_soundData.musicQueueSlot[slot - 1]);
                vs_main_soundData.musicQueueSlot[slot - 1] = NULL;
                return 0;
            }
            if (vs_main_soundData.musicQueueSlot[slot - 1]->state
                == vs_main_CdQueueStateError) {
                vs_main_freeCdQueueSlot(vs_main_soundData.musicQueueSlot[slot - 1]);
                vs_main_soundData.musicQueueSlot[slot - 1] = (vs_main_CdQueueSlot*)-1;
                return -1;
            }
            return 1;
        }
    }
    return 0;
}

static int vs_main_clearMusicLoadQueue()
{
    int i;
    int ret;

    ret = 0;
    i = 0;
    do {
        ret |= vs_main_clearMusicLoadSlot(++i);
    } while (i < 4);

    return ret;
}

static int vs_main_loadAndWaitMusicSlot(int id, int targetSlot)
{
    int ret;

    ret = vs_main_loadMusicSlot(id, targetSlot);
    if (ret != 0) {
        while (vs_main_clearMusicLoadSlot(targetSlot) != 0) {
            vs_main_gametimeUpdate(0);
        }
    }
    return ret;
}

static int _loadMusicIntoFreeSlotAndClearQueue(int id)
{
    int ret;

    ret = _loadMusicIntoFreeSlot(id);
    if (ret != 0) {
        while (vs_main_clearMusicLoadQueue() != 0) {
            vs_main_gametimeUpdate(0);
        }
    }
    return ret;
}

int vs_main_freeMusic(int slotId)
{
    func_80044DF4(slotId);

    if (vs_main_soundData.musicData[slotId - 1] == 0) {
        return 0;
    }

    vs_main_freeHeapR(vs_main_soundData.musicData[slotId - 1]);
    vs_main_soundData.musicData[slotId - 1] = 0;
    vs_main_soundData.musicIds[slotId - 1] = 0;
    return 1;
}

static int nop5() { return 0; }

static int func_800454B8(int arg0)
{
    if (arg0 != 0) {
        if (vs_main_soundData.unk14[arg0 - 1] != 0xFFFF) {
            return func_80011EBC(vs_main_soundData.unk14[arg0 - 1]);
        }
    }
    return 0;
}

static void func_8004550C(int arg0) { func_800454B8(arg0); }

int func_8004552C(int id, int arg1, int arg2)
{
    if (vs_main_soundData.currentMusicId == id) {
        func_800128A0(vs_main_soundData.unk4, arg2, arg1);
        return 1;
    }
    return 0;
}

static int func_80045574(int id, int arg1, int arg2)
{
    if (vs_main_soundData.currentMusicId == id) {
        func_800129D0(arg2, arg1);
        return 1;
    }
    return 0;
}

static int func_800455AC(int id, int arg1, int arg2)
{
    if (vs_main_soundData.currentMusicId == id) {
        func_80012A6C(arg2, arg1);
        return 1;
    }
    return 0;
}

static int nop6() { return 0; }

static int nop7() { return 0; }

void vs_main_stopMusic()
{
    int id = vs_main_soundData.currentMusicId;
    if (id != 0) {
        func_80044DF4(id);
        vs_main_freeMusic(id);
    }
}

static void func_80045630(int arg0)
{
    func_8001217C((void*)(arg0 & 0xFFFF), D_8005FE70, 0x80, 0x7F);

    if (!((D_8005FE70 *= 2) & 1)) {
        D_8005FE70 = 1;
    }
}

static void func_80045684(void* arg0, int arg1, int arg2, int arg3)
{
    if (arg1 == 0x200) {
        if (arg0 != func_80012358(0x200)) {
            func_8001217C(arg0, 0x200, arg2, arg3);
        }
    } else {
        func_8001217C(arg0, arg1, arg2, arg3);
    }
}

static void func_800456EC(void* arg0, int arg1, int arg2, int arg3)
{
    if (arg1 == 0x200) {
        if (arg0 != func_80012358(0x200)) {
            func_800121F0(arg0, 0x200, arg2, arg3);
        }
    } else {
        func_800121F0(arg0, arg1, arg2, arg3);
    }
}

void vs_main_playSfx(int arg0, int arg1, int arg2, int arg3)
{
    void* var_s0_2;

    switch (arg0) {
    case 0x7E:
    case 0xFE:
        if (func_800123C8((void*)(arg1 & 0xFFFF)) != 0) {
            func_80045684((void*)(arg1 & 0xFFFF), D_8005FE74, arg2, arg3);
            D_8005FE74 *= 2;
            if (!(D_8005FE74 & 0x7E)) {
                D_8005FE74 = 2;
            }
        } else {
            func_80045684((void*)(arg1 & 0xFFFF), 0, arg2, arg3);
        }
        break;
    case 0x100:
    case 0x200:
        if (func_800123C8((void*)(arg1 & 0xFFFF)) != 0) {
            func_80045684((void*)(arg1 & 0xFFFF), D_8005FE7C, arg2, arg3);
        } else {
            func_80045684((void*)(arg1 & 0xFFFF), 0, arg2, arg3);
        }

        break;
    case 0xFF000:
        var_s0_2 = vs_main_soundData.sfxData[vs_main_soundData.currentSfxId - 1];
        var_s0_2 = (char*)var_s0_2 + (arg1 + (int*)var_s0_2)[1];
        if (func_800123C8(var_s0_2) != 0) {
            func_800456EC(var_s0_2, D_8005FE80, arg2, arg3);
            D_8005FE80 *= 2;
            if (!(D_8005FE80 & arg0)) {
                D_8005FE80 = 0x1000;
            }
        } else {
            func_800456EC(var_s0_2, 0, arg2, arg3);
        }
        break;
    case 0xF00000:
        var_s0_2 = D_8005E08C;
        var_s0_2 = (char*)D_8005E08C + (arg1 + ((int*)D_8005E08C))[1];
        if (func_800123C8(var_s0_2) != 0) {
            func_800456EC(var_s0_2, D_8005FE84, arg2, arg3);
            D_8005FE84 *= 2;
            if (!(D_8005FE84 & arg0)) {
                D_8005FE84 = 0x100000;
            }
        } else {
            func_800456EC(var_s0_2, 0, arg2, arg3);
        }
        break;
    default:
        nop10(0x95, 0);
        break;
    }
}

void vs_main_playSfxDefault(int arg0, int arg1)
{
    vs_main_playSfx(arg0, arg1, 0x80, 0x7F);
}

int vs_main_computeSfxPan(int coords, int z)
{
    int v0;
    int new_var2;
    int v1;

    v0 = coords;

    if (coords < 0) {
        v0 += 0xFFFF;
    }

    v0 = (v0 >> 16) << 16;
    coords = (short)(coords - v0) - 160;
    coords = (coords * 3) / 10;

    if (coords < -96) {
        coords = -96;
    }

    if (coords > 96) {
        coords = 96;
    }

    coords += 128;
    v1 = z - 768;

    if (v1 < 0) {
        v1 = 0;
    }

    if (v1 > 4095) {
        v1 = 4095;
    }

    v0 = v1;

    if (v1 < 0) {
        v0 = v1 + 31;
    }

    v0 >>= 5;
    v1 = 127;

    new_var2 = v1 - v0;
    return (coords << 16) + new_var2;
}

static void _do_panSfx(int arg0, int arg1, int coords, int z)
{
    coords = vs_main_computeSfxPan(coords, z);
    z = coords & 0xFFFF;
    coords = coords >> 0x10;
    if (z > 0) {
        vs_main_playSfx(arg0, arg1, coords, z);
    }
}

void vs_main_panSfx(int arg0, int arg1, SVECTOR* vec)
{
    int z;
    long coords;
    long value;
    long flag;

    SetRotMatrix(&D_1F800014_mat);
    SetTransMatrix(&D_1F800014_mat);
    z = RotTransPers(vec, &coords, &value, &flag);
    _do_panSfx(arg0, arg1, coords, z);
}

static int func_80045B28(int arg0, int arg1)
{
    int temp_v1;

    switch (arg0) {
    case 0x1:
    case 0x7E:
    case 0xFE:
    case 0x100:
    case 0x200:
        temp_v1 = 0;
        break;
    case 0xFF000:
    case 0xF00000:
        temp_v1 = (int)vs_main_soundData.sfxData[vs_main_soundData.currentSfxId - 1];
        temp_v1 = (int)temp_v1 + (arg1 + (int*)temp_v1)[1];
        break;
    default:
        nop10(0x95, 0);
        temp_v1 = 0;
        break;
    }
    return temp_v1;
}

static void func_80045BFC(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    if (arg1 != 0) {
        temp_v0 = func_80045B28(arg0, arg1);

        if (temp_v0 != 0) {
            func_8001264C(temp_v0, 0, arg3 & 0xFF, arg2);
        } else {
            do {
                func_8001264C(arg1, 0, arg3 & 0xFF, arg2);
            } while (0);
        }
    } else {
        func_8001264C(0, arg0, arg3 & 0xFF, arg2);
    }
}

static void func_80045C74(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    if (arg1 != 0) {
        temp_v0 = func_80045B28(arg0, arg1);
        if (temp_v0 != 0) {
            func_80012824(temp_v0, 0, arg3 & 0xFF, arg2);
        } else {
            do {
                func_80012824(arg1, 0, arg3 & 0xFF, arg2);
            } while (0);
        }
    } else {
        func_80012824(0, arg0, arg3 & 0xFF, arg2);
    }
}

static void func_80045CEC(int arg0, int arg1, int arg2, int arg3)
{
    if (arg1 != 0) {
        arg0 = func_80045B28(arg0, arg1);
        if (arg0 != 0) {
            func_80012738(arg0, 0, arg3 & 0xFF, arg2);
        } else {
            do {
                func_80012738(arg1, 0, arg3 & 0xFF, arg2);
            } while (0);
        }
    } else {
        func_80012738(0, arg0, arg3 & 0xFF, arg2);
    }
}

static void func_80045D64(int arg0, int arg1)
{
    if (arg1 != 0) {
        arg0 = func_80045B28(arg0, arg1);

        if (arg0 != 0) {
            func_80012288(arg0, 0);
        } else {
            func_80012288(arg1, 0);
        }
    } else {
        func_80012288(0, arg0);
    }
}

static void func_80045DC0() { func_80012B98(); }

int vs_main_loadSfxSlot(int id, u_int slot)
{
    vs_main_CdFile cdFile;

    if (slot - 1 < 3) {
        if (vs_main_soundData.sfxData[slot - 1] == NULL) {
            u_int index = slot - 1;
            cdFile.lba = _seLBAs[id];
            cdFile.size = _seFileSizes[id];

            if ((vs_main_soundData.sfxQueueSlot[index] != NULL)
                && (vs_main_soundData.sfxQueueSlot[index] != (vs_main_CdQueueSlot*)-1)) {
                vs_main_nop9(0x8F, 0);
            }

            vs_main_soundData.sfxQueueSlot[index] = vs_main_allocateCdQueueSlot(&cdFile);

            if (vs_main_soundData.sfxData[index] != NULL) {
                vs_main_nop9(0x90, 0);
            }

            vs_main_soundData.sfxIds[index] = id;
            vs_main_soundData.sfxData[index] = vs_main_allocHeapR(cdFile.size);
            vs_main_cdEnqueue(
                vs_main_soundData.sfxQueueSlot[index], vs_main_soundData.sfxData[index]);

            return slot;
        }
    }
    return 0;
}

static int _loadSfx(int id)
{
    int i;

    for (i = 0; i < 3; ++i) {
        if (vs_main_soundData.sfxData[i] == 0) {
            return vs_main_loadSfxSlot(id, i + 1);
        }
    }
    return 0;
}

int vs_main_freeSfxQueueSlot(u_int slot)
{
    if ((slot - 1) < 3) {
        if (vs_main_soundData.sfxQueueSlot[slot - 1] != NULL) {
            if (vs_main_soundData.sfxQueueSlot[slot - 1]->state
                == vs_main_CdQueueStateLoaded) {
                vs_main_freeCdQueueSlot(vs_main_soundData.sfxQueueSlot[slot - 1]);
                vs_main_soundData.sfxQueueSlot[slot - 1] = NULL;
                return 0;
            }
            if (vs_main_soundData.sfxQueueSlot[slot - 1]->state
                == vs_main_CdQueueStateError) {
                vs_main_freeCdQueueSlot(vs_main_soundData.sfxQueueSlot[slot - 1]);
                vs_main_soundData.sfxQueueSlot[slot - 1] = (vs_main_CdQueueSlot*)-1;
                return -1;
            }
            return 1;
        }
    }
    return 0;
}

static int _freeSfxSlots()
{
    int i;
    int ret = 0;
    for (i = 0; i < 3; ++i) {
        ret |= vs_main_freeSfxQueueSlot(i + 1);
    }
    return ret;
}

static int _loadAndFreeSfx(int id)
{
    int slot;

    slot = _loadSfx(id);
    if (slot != 0) {
        while (_freeSfxSlots() != 0) {
            vs_main_gametimeUpdate(0);
        }
    }
    return slot;
}

int vs_main_setCurrentSfx(int id)
{
    if ((id - 1u < 3) && vs_main_soundData.sfxData[id - 1] != 0) {
        vs_main_soundData.currentSfxId = id;
        return 1;
    }
    return 0;
}

int vs_main_freeSfx(u_int id)
{
    if ((id - 1) < 3) {
        if (vs_main_soundData.sfxData[id - 1] != 0) {
            if (vs_main_soundData.currentSfxId == id) {
                vs_main_soundData.currentSfxId = 0;
            }
            func_80012288(-2, 0);
            func_80012288(0, 0xFF000);
            vs_main_freeHeapR(vs_main_soundData.sfxData[id - 1]);
            vs_main_soundData.sfxIds[id - 1] = 0;
            vs_main_soundData.sfxData[id - 1] = 0;
            return 1;
        }
    }
    return 0;
}

static int func_80046168(u_int arg0)
{
    if (vs_main_soundData.unk14[16] == 0) {
        vs_main_soundData.unk14[16] = arg0;
        return 1;
    }
    return 0;
}

static int func_80046194()
{
    func_80012288(-2, 0);
    func_80012288(0, 0xF00000);
    D_8005E08C = NULL;
    return 1;
}

void func_800461CC(int arg0, u_int arg1[], u_int arg2, int arg3, int arg4)
{
    int var_s0;
    void* temp_s1;

    temp_s1 = arg1;

    if (arg2 < arg1[0]) {
        temp_s1 = (char*)arg1 + (arg1 + arg2)[1];
        var_s0 = 0;

        if (arg0 == 0x180) {
            var_s0 = D_8005FE78;
            D_8005FE78 *= 2;
            if (!(D_8005FE78 & 0x180)) {
                D_8005FE78 = 0x80;
            }
        } else if (arg0 == 0x200) {
            var_s0 = D_8005FE7C;
            D_8005FE7C *= 2;
            if (!(D_8005FE7C & 0x200)) {
                D_8005FE7C = arg0;
            }
        } else if (arg0 == 0xF00000) {
            var_s0 = D_8005FE84;
            D_8005FE84 *= 2;
            if (!(D_8005FE84 & arg0)) {
                D_8005FE84 = 0x100000;
            }
        } else if (arg0 == 0x7E) {
        } else {
            nop10(0x95, 0);
        }
        func_800456EC(temp_s1, var_s0, arg3, arg4);
    }
}

static void func_800462E8(int arg0, u_int* arg1, u_int arg2)
{
    func_800461CC(arg0, arg1, arg2, 0x80, 0x7F);
}

static void func_80046310(int arg0, u_int arg1[], int arg2, int arg3, int arg4)
{
    int temp_t0;
    int var_v0;
    int var_v1;

    var_v1 = arg3;
    var_v0 = arg3;
    arg3 = var_v0 >> 0x10;

    if (var_v1 < 0) {
        var_v0 = var_v1 + 0xFFFF;
    }

    arg3 = var_v0 >> 0x10;
    var_v0 = arg3 << 0x10;
    arg3 = var_v1 - var_v0;

    if (arg3 < 0) {
        arg3 = 0;
    }

    if (arg3 >= 0x141) {
        arg3 = 0x140;
    }

    var_v0 = arg3 + ((u_int)arg3 >> 0x1F);
    var_v0 >>= 1;
    arg3 = var_v0 + 0x30;
    temp_t0 = arg4;

    if (temp_t0 < 0) {
        temp_t0 = 0;
    }

    if (temp_t0 >= 0x401) {
        temp_t0 = 0x400;
    }

    var_v1 = temp_t0;

    if (temp_t0 < 0) {
        var_v1 += 7;
    }

    temp_t0 = 0x7F - (var_v1 >> 3);

    if (temp_t0 > 0) {
        func_800461CC(arg0, arg1, arg2, arg3, temp_t0);
    }
}

static void func_800463BC(int arg0, u_int* arg1, int arg2, SVECTOR* vec)
{
    int z;
    long sxy;
    long value;
    long flag;

    SetRotMatrix(&D_1F800014_mat);
    SetTransMatrix(&D_1F800014_mat);
    z = RotTransPers(vec, &sxy, &value, &flag);
    func_80046310(arg0, arg1, arg2, sxy, z);
}

static void func_8004644C(int arg0, int* arg1, int arg2)
{
    int var_a1;
    char* var_a0 = (char*)arg1 + (arg1 + arg2)[1];

    if (arg2 != 0) {
        var_a1 = 0;
    } else {
        var_a0 = 0;
        var_a1 = arg0;
    }
    func_80012288((int)var_a0, var_a1);
}

static void func_80046494(int arg0, int* arg1, int arg2, int arg3, int arg4)
{
    int a0 = (int)((char*)arg1 + (arg2 + arg1)[1]);

    if (arg2 == 0) {
        func_8001264C(0, arg0, arg4 & 0xFF, arg3);
    } else {
        func_8001264C(a0, 0, arg4 & 0xFF, arg3);
    }
}

static void func_800464DC() { func_80013328(); }

static int func_800464FC(int arg0, int arg1, int arg2)
{
    if ((arg0 - 1u) < 3) {
        if (vs_main_soundData.unk64[arg0 - 1] != 0) {
            func_80013378(0, arg2);
            func_800132C4(vs_main_soundData.unk64[arg0 - 1], arg1, 1);
            return 1;
        }
    }
    return 0;
}

static void func_80046578(int arg0) { func_800464FC(arg0, 0x80, 0x7F); }

static int func_8004659C(int arg0)
{
    if ((arg0 - 1u) < 3) {
        if (vs_main_soundData.unk64[arg0 - 1] != 0) {
            func_80013328();
            vs_main_freeHeapR(vs_main_soundData.unk64[arg0 - 1]);
            vs_main_soundData.unk64[arg0 - 1] = 0;
            return 1;
        }
    }
    return 0;
}

static int func_80046608(u_int arg0)
{
    if (vs_main_soundData.unk14[22] == 0) {
        vs_main_soundData.unk14[22] = arg0;
        return 3;
    }
    return 0;
}

static int func_80046634()
{

    if (vs_main_soundData.unk14[22] != 0) {
        func_80013328();
        vs_main_soundData.unk14[22] = 0;
        return 1;
    }
    return 0;
}

static void _loadSoundFile(int file)
{
    vs_main_CdFile cdFile;
    int new_var;
    int temp_v1;
    int var_a0;

    temp_v1 = func_80011F08();
    var_a0 = temp_v1 >> 0x10;
    new_var = temp_v1;

    if (temp_v1 < 0) {
        var_a0 = (temp_v1 + 0xFFFF) >> 0x10;
    }
    if (((new_var - (var_a0 << 0x10)) == file) || (var_a0 == file)) {
        return;
    }
    cdFile.lba = _soundLBAs[file];
    cdFile.size = _soundFileSizes[file];

    if (D_8005E0BC) {
        if (D_8005E0BC != (-1)) {
            vs_main_nop9(0x93 & 0xFFu, 0);
        }
    }
    vs_main_soundData.soundQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
    if (vs_main_soundData.soundData != 0) {
        vs_main_nop9(0x94, 0);
    }
    new_var = 1;
    vs_main_soundData.soundData = vs_main_allocHeapR(cdFile.size);
    vs_main_soundData.soundFileId = file;
    vs_main_cdEnqueue(vs_main_soundData.soundQueueSlot, vs_main_soundData.soundData);
}

void vs_main_loadSoundFile(int id) { _loadSoundFile(_soundFileMap[id]); }

int vs_main_processSoundQueue()
{
    int temp_v0;

    if (vs_main_soundData.soundQueueSlot != NULL) {
        if (vs_main_soundData.soundQueueSlot->state == vs_main_CdQueueStateDispatched) {
            temp_v0 = vs_sound_spuTransferring();
            if (temp_v0 == 0) {
                vs_main_freeCdQueueSlot(vs_main_soundData.soundQueueSlot);
                vs_main_soundData.soundQueueSlot = NULL;
                vs_main_freeHeapR(vs_main_soundData.soundData);
                vs_main_soundData.soundData = NULL;
                vs_main_soundData.soundFileId = 0;
                return 0;
            }
            if (temp_v0 == -1) {
                vs_main_freeCdQueueSlot(vs_main_soundData.soundQueueSlot);
                vs_main_soundData.soundQueueSlot = NULL;
                vs_main_freeHeapR(vs_main_soundData.soundData);
                vs_main_soundData.soundData = NULL;
                vs_main_soundData.soundFileId = 0;
                return -1;
            }
            return 1;
        }
        if (vs_main_soundData.soundQueueSlot->state == vs_main_CdQueueStateLoaded) {
            vs_main_soundData.soundQueueSlot->state = vs_main_CdQueueStateDispatched;
            func_80013188(vs_main_soundData.soundData, 0);
            return 1;
        }
        if (vs_main_soundData.soundQueueSlot->state == vs_main_CdQueueStateError) {
            vs_main_freeCdQueueSlot(vs_main_soundData.soundQueueSlot);
            vs_main_soundData.soundQueueSlot = NULL;
            vs_main_freeHeapR(vs_main_soundData.soundData);
            vs_main_soundData.soundData = NULL;
            vs_main_soundData.soundFileId = 0;
            return -1;
        }
        return 1;
    }
    return 0;
}

void vs_main_loadAndWaitSoundSlot(int id)
{
    vs_main_loadSoundFile(id);

    while (vs_main_processSoundQueue() != 0) {
        vs_main_gametimeUpdate(0);
    }
}

void vs_main_setMonoSound(int set) { vs_sound_setMonoSound(set); }

static void func_800468DC() { func_80012918(0x7FFF); }

static void _loadMenuSound()
{
    void* buf;

    vs_sound_init();
    vs_sound_setCdVol(0x7F);
    buf = vs_main_allocHeapR(VS_WAVE0000_DAT_SIZE);
    vs_main_diskLoadFile(VS_WAVE0000_DAT_LBA, VS_WAVE0000_DAT_SIZE, buf);
    func_80012BB8(buf, 1);
    vs_main_freeHeapR(buf);
    buf = vs_main_allocHeapR(VS_WAVE0005_DAT_SIZE);
    vs_main_diskLoadFile(VS_WAVE0005_DAT_LBA, VS_WAVE0005_DAT_SIZE, buf);
    func_80012BB8(buf, 1);
    vs_main_freeHeapR(buf);
    buf = vs_main_allocHeapR(VS_WAVE0200_DAT_SIZE);
    vs_main_diskLoadFile(VS_WAVE0200_DAT_LBA, VS_WAVE0200_DAT_SIZE, buf);
    func_800131DC(buf, 0, 1);
    vs_main_freeHeapR(buf);
    vs_main_diskLoadFile(VS_EFFECT00_DAT_LBA, VS_EFFECT00_DAT_SIZE, &_sfxData);
    func_80011DEC(_sfxData);
    D_8005FE70 = 1;
    D_8005FE74 = 2;
    D_8005FE78 = 0x80;
    D_8005FE7C = 0x200;
    D_8005FE80 = 0x1000;
    D_8005FE84 = 0x100000;
}

void vs_main_resetSound()
{
    int i;

    vs_main_soundData.currentMusicId = 0;
    vs_main_soundData.currentMusicData = NULL;
    vs_main_soundData.unk8 = 0xFFFF;
    vs_main_soundData.unk4 = 0xFFFF;
    vs_main_soundData.currentSfxId = 0;

    for (i = 0; i < 4; ++i) {
        vs_main_soundData.musicIds[i] = 0;
        vs_main_soundData.unk14[i] = 0xFFFF;
        vs_main_soundData.musicData[i] = NULL;
        vs_main_soundData.musicQueueSlot[i] = NULL;
    }

    for (i = 0; i < 3; ++i) {
        vs_main_soundData.sfxIds[i] = 0;
        vs_main_soundData.sfxData[i] = NULL;
        vs_main_soundData.sfxQueueSlot[i] = NULL;
    }

    for (i = 0; i < 3; ++i) {
        vs_main_soundData.unk64[i] = NULL;
        vs_main_soundData.unk70[i] = NULL;
    }

    vs_main_soundData.soundFileId = 0;
    vs_main_soundData.soundData = NULL;
    vs_main_soundData.soundQueueSlot = NULL;
    D_8005FE70 = 1;
    D_8005FE74 = 2;
    D_8005FE78 = 0x80;
    D_8005FE7C = 0x200;
    D_8005FE80 = 0x1000;
    D_8005FE84 = 0x100000;
}

static void func_80046B3C(int arg0, int arg1, u_short* arg2)
{
    int i;
    u_short g;
    u_short b;
    u_short r;
    struct ColorInfo* p;

    for (i = 0; i < 256; ++i) {
        r = arg2[i] & 0x1F;
        g = (arg2[i] & 0x3E0) >> 5;
        b = (arg2[i] & 0x7C00) >> 10;

        p = D_80055D58.unk0[arg1].unkE;

        if (arg0 != 0) {
            p[i].rindex = (r - p[i].r) + 31;
            p[i].gindex = (g - p[i].g) + 31;
            p[i].bindex = (b - p[i].b) + 31;
        } else {
            p[i].r = r;
            p[i].g = g;
            p[i].b = b;
            loadImageSource[arg1][i] = r + (g << 5) + (b << 10) + (p[i].a << 15);
        }
    }

    if (arg0 != 0) {
        char* p = D_80055D58.unk0[arg1].unk6;
        p[0] = 1;
        p[1] = 0;
        p[2] = 0;
        p[3] = arg0;
    } else {
        D_80055D58.unk0[arg1].unk6[0] = 0;
    }
}

void func_80046C80(int arg0, int arg1, u_short* arg2, int arg3)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80046B3C(arg0, arg1, arg2 + (arg3 << 4));
        D_80055D58.unk0[0].unk0 = 1;
    }
}

static void func_80046CC8(int arg0, int arg1, u_short* arg2, int arg3)
{
    int i;

    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80046C80(arg0, arg1, arg2, arg3);

        for (i = 0; i < 0x100; ++i) {
            D_80055D58.unk0[arg1].unk70E[i] = arg2[i];
        }
    }
}

static void func_80046D58(int arg0)
{
    int i;

    if (D_80055D58.unk0[0].unk2 != 0) {
        for (i = 0; i < 256; ++i)
            D_80055D58.unk0[arg0].unk70E[i] = loadImageSource[arg0][i];
    }
}

static inline int inline_fn5(short arg0, short arg1, short arg2)
{
    return arg2 * 2 + (arg0 >> 5) * 3 + (arg1 >> 10);
}

void func_80046DC0(int arg0, int arg1, int arg2, int arg3, short arg4, short arg5)
{
    int i;
    int var_v0;
    short temp_t0;
    int var_t3;
    int var_t1;
    int var_a0;
    int tmp;
    int t4 = (u_short)arg4;
    int t5 = (u_short)arg5;
    struct ColorInfo* t2 = D_80055D58.unk0[arg2].unkE;

    for (i = 0; i < 256; ++i) {
        temp_t0 = D_80055D58.unk0[arg2].unk70E[i];
        if ((t2[i].r + t2[i].g + t2[i].b + t2[i].a) != 0) {
            switch (arg0) {
            case 1:
                tmp = 1;
                var_t3 = arg3 + (t2[i].r >> tmp);
                var_t1 = t4 + (t2[i].g >> tmp);
                var_a0 = t5 + (t2[i].b >> tmp);
                break;
            case 2:
                var_t3 = arg3 + ((t2[i].r * 2) + (t2[i].g * 3) + t2[i].b) / 6;
                var_t1 = t4 + ((t2[i].r * 2) + (t2[i].g * 3) + t2[i].b) / 6;
                var_a0 = t5 + ((t2[i].r * 2) + (t2[i].g * 3) + t2[i].b) / 6;
                break;
            case 3:
                var_t3 = arg3 + ((t2[i].r * 2) + (t2[i].g * 3) + t2[i].b) / 12;
                var_t1 = t4 + ((t2[i].r * 2) + (t2[i].g * 3) + t2[i].b) / 12;
                var_a0 = t5 + ((t2[i].r * 2) + (t2[i].g * 3) + t2[i].b) / 12;
                break;
            case 4:
            case 9:
                var_t3 = arg3 + (temp_t0 & 0x1F);
                var_t1 = t4 + ((temp_t0 & 0x3E0) >> 5);
                var_a0 = t5 + ((temp_t0 & 0x7C00) >> 0xA);
                break;
            case 5:
                tmp = 0x1F;
                var_t3 = arg3 + ((temp_t0 & tmp) >> 1);
                var_t1 = t4 + ((temp_t0 & 0x3E0) >> 6);
                var_a0 = t5 + ((temp_t0 & 0x7C00) >> 0xB);
                break;
            case 6:
                var_t3 = arg3
                    + inline_fn5(temp_t0 & 0x3E0, temp_t0 & 0x7C00, temp_t0 & 0x1F) / 6;
                var_t1 = t4
                    + inline_fn5(temp_t0 & 0x3E0, temp_t0 & 0x7C00, temp_t0 & 0x1F) / 6;
                var_a0 = t5
                    + inline_fn5(temp_t0 & 0x3E0, temp_t0 & 0x7C00, temp_t0 & 0x1F) / 6;
                break;
            case 7:
                var_t3 = arg3
                    + inline_fn5(temp_t0 & 0x3E0, temp_t0 & 0x7C00, temp_t0 & 0x1F) / 12;
                var_t1 = t4
                    + inline_fn5(temp_t0 & 0x3E0, temp_t0 & 0x7C00, temp_t0 & 0x1F) / 12;
                var_a0 = t5
                    + inline_fn5(temp_t0 & 0x3E0, temp_t0 & 0x7C00, temp_t0 & 0x1F) / 12;
                break;
            case 8:
            case 15:
                var_t3 = temp_t0 & 0x1F;
                var_t1 = (temp_t0 & 0x3E0) >> 5;
                var_a0 = (temp_t0 & 0x7C00) >> 0xA;
                break;
            case 11:
                D_80055D58.unk0[arg2].unk6[4] = 0;
                return;
            case 12:
                tmp = 0x1F;
                var_t3 = arg3 - (t2[i].r - tmp);
                var_t1 = t4 - (t2[i].g - tmp);
                var_a0 = t5 - (t2[i].b - tmp);
                break;
            case 13:
                var_v0 = (temp_t0 & 0x1F) * 3;
                if (var_v0 < 0) {
                    var_v0 += 3;
                }
                var_t3 = arg3 + (var_v0 >> 2);
                var_v0 = ((temp_t0 & 0x3E0) >> 5) * 3;
                if (var_v0 < 0) {
                    var_v0 += 3;
                }
                var_t1 = t4 + (var_v0 >> 2);
                var_v0 = ((temp_t0 & 0x7C00) >> 0xA) * 3;
                if (var_v0 < 0) {
                    var_v0 += 3;
                }
                var_a0 = t5 + (var_v0 >> 2);
                break;
            default:
                var_t3 = t2[i].r + arg3;
                var_t1 = t2[i].g + t4;
                var_a0 = t2[i].b + t5;
                break;
            }

            if ((short)var_t3 >= 0x20) {
                var_t3 = 0x1F;
            }
            if ((short)var_t1 >= 0x20) {
                var_t1 = 0x1F;
            }
            if ((short)var_a0 >= 0x20) {
                var_a0 = 0x1F;
            }
            if ((var_t3 << 0x10) <= 0) {
                var_t3 = 0;
            }
            if ((var_t1 << 0x10) <= 0) {
                var_t1 = 0;
            }
            if ((var_a0 << 0x10) <= 0) {
                var_a0 = 0;
            }
            if (((var_a0 | (var_t3 | var_t1)) << 0x10) == 0) {
                var_a0 = 1;
            }
            if (arg1 != 0) {
                t2[i].rindex = ((var_t3 - t2[i].r) + 0x1F);
                t2[i].gindex = ((var_t1 - t2[i].g) + 0x1F);
                t2[i].bindex = ((var_a0 - t2[i].b) + 0x1F);
            } else {
                t2[i].b = var_a0;
                t2[i].r = var_t3;
                t2[i].g = var_t1;
                loadImageSource[arg2][i]
                    = var_t3 + (var_t1 << 5) + (var_a0 << 0xA) + (t2[i].a << 0xF);
            }
        } else {
            t2[i].bindex = 0x1F;
            t2[i].gindex = 0x1F;
            t2[i].rindex = 0x1F;
        }
    }
    if (arg1 != 0) {
        char* p = D_80055D58.unk0[arg2].unk6;
        p[0] = 1;
        p[1] = 0;
        p[2] = 0;
        p[3] = arg1;
        p[4] = arg0;
        if (arg0 == 9) {
            p[5] = arg3;
            p[6] = t4;
            p[7] = t5;
        }
    } else {
        D_80055D58.unk0[arg2].unk6[0] = 0;
        D_80055D58.unk0[0].unk0 = 1;
    }
}

void func_80047280(int arg0, int arg1, int arg2, short arg3, int arg4, int arg5)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        do {
            func_80046DC0(arg0, arg1, arg2, arg3, arg4, arg5);
        } while (0);
    }
}

static inline int inline_fn(int arg0) { return arg0 << 0x10; }

void func_800472D0(int arg0, D_8005DC6C_t* arg1)
{
    int sp10[5];
    int new_var;
    int i;

    if (D_80055D58.unk0[0].unk2 != 0) {
        int(*temp_t6)[6] = D_80055D58.unk7E9C;
        for (i = 0; i < 5; ++i) {
            int temp_a1, temp_t1, temp_t2;
            temp_a1 = inline_fn(arg1[i].unk0);
            temp_t1 = inline_fn(arg1[i].unk1);
            temp_t2 = inline_fn(arg1[i].unk2);

            if (arg0 != 0) {
                temp_t6[i][3]
                    = ((int)(temp_a1 - (temp_t6[i][0] & 0xFFFF0000)) / (arg0 * 2));
                temp_t6[i][4]
                    = ((int)(temp_t1 - (temp_t6[i][1] & 0xFFFF0000)) / (arg0 * 2));
                temp_t6[i][5]
                    = ((int)(temp_t2 - (temp_t6[i][2] & 0xFFFF0000)) / (arg0 * 2));
            } else {
                temp_t6[i][0] = temp_a1;
                temp_t6[i][1] = temp_t1;
                temp_t6[i][2] = temp_t2;
            }
        }
        if (arg0 != 0) {
            D_80055D58.unk7E8C[4] = 1;
            D_80055D58.unk7E8C[5] = 0;
            D_80055D58.unk7E8C[6] = 0;
            D_80055D58.unk7E8C[7] = arg0;
            return;
        }
        D_80055D58.unk7E8C[4] = 0;

        for (i = 0; i < 5; ++i) {
            int temp_a1, var_v0, var_v1;
            var_v1 = temp_t6[i][0];

            if (var_v1 < 0) {
                var_v1 += 0xFFFF;
            }

            temp_a1 = (var_v1 >> 0x10);
            var_v0 = temp_t6[i][1];

            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }

            new_var = temp_a1 + ((var_v0 >> 0x10) << 8);
            var_v1 = temp_t6[i][2];

            if (var_v1 < 0) {
                var_v1 += 0xFFFF;
            }
            sp10[i] = new_var + ((var_v1 >> 0x10) << 0x10);
        }
        func_8008EB30(sp10);
    }
}

void func_80047464(int arg0, D_8005DC6C_t* arg1)
{
    int i;

    if (D_80055D58.unk0[0].unk2 != 0) {
        func_800472D0(arg0, arg1);
        for (i = 0; i < 5; ++i) {
            D_80055D58.unk7F14[i] = arg1[i];
        }
    }
}

void func_800474DC(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int sp10[5];
    int temp_v0;
    int var_a1;
    int var_t0;
    int var_t1;
    int i;
    int(*p)[6] = D_80055D58.unk7E9C;

    for (i = 0; i < 5; ++i) {
        switch (arg0) {
        case 1:
            var_t1 = (p[i][0] / 2) + (arg2 << 0x10);
            var_t0 = p[i][1] / 2 + (arg3 << 0x10);
            var_a1 = (p[i][2] / 2) + (arg4 << 0x10);
            break;
        case 2:
            var_t1 = ((p[i][0] * 2) + (p[i][1] * 3) + p[i][2]) / 6 + (arg2 << 0x10);
            var_t0 = ((p[i][0] * 2) + (p[i][1] * 3) + p[i][2]) / 6 + (arg3 << 0x10);
            var_a1 = ((p[i][0] * 2) + (p[i][1] * 3) + p[i][2]) / 6 + (arg4 << 0x10);
            break;
        case 3:
            temp_v0 = ((p[i][0] * 2) + (p[i][1] * 3) + p[i][2]) / 12;
            var_t1 = temp_v0 + (arg2 << 0x10);
            var_t0 = temp_v0 + (arg3 << 0x10);
            var_a1 = temp_v0 + (arg4 << 0x10);
            break;
        case 4:
        case 9:
            var_t1 = (D_80055D58.unk7F14[i].unk0 + arg2) << 0x10;
            var_t0 = (D_80055D58.unk7F14[i].unk1 + arg3) << 0x10;
            var_a1 = (D_80055D58.unk7F14[i].unk2 + arg4) << 0x10;
            break;
        case 5:
            var_t1 = (D_80055D58.unk7F14[i].unk0 << 0xF) + (arg2 << 0x10);
            var_t0 = (D_80055D58.unk7F14[i].unk1 << 0xF) + (arg3 << 0x10);
            var_a1 = (D_80055D58.unk7F14[i].unk2 << 0xF) + (arg4 << 0x10);
            break;
        case 6: {
            int v1 = D_80055D58.unk7F14[i].unk1;
            int a0 = D_80055D58.unk7F14[i].unk2;
            int v0 = D_80055D58.unk7F14[i].unk0;
            var_a1 = v1 << 0x10;
            a0 <<= 0x10;
            v0 <<= 0x11;
            v1 <<= 0x11;
            v0 += v1 + var_a1;
            v0 += a0;
            var_t1 = v0 / 6 + (arg2 << 0x10);
            var_t0 = v0 / 6 + (arg3 << 0x10);
            var_a1 = v0 / 6 + (arg4 << 0x10);
        } break;
        case 7: {
            int v1 = D_80055D58.unk7F14[i].unk1;
            int a0 = D_80055D58.unk7F14[i].unk2;
            int v0 = D_80055D58.unk7F14[i].unk0;
            var_a1 = v1 << 0x10;
            a0 <<= 0x10;
            v0 <<= 0x11;
            v1 <<= 0x11;
            v0 += v1 + var_a1;
            v0 += a0;
            var_t1 = v0 / 12 + (arg2 << 0x10);
            var_t0 = v0 / 12 + (arg3 << 0x10);
            var_a1 = v0 / 12 + (arg4 << 0x10);
        } break;
        case 8:
            var_t1 = D_80055D58.unk7F14[i].unk0 << 0x10;
            var_t0 = D_80055D58.unk7F14[i].unk1 << 0x10;
            var_a1 = D_80055D58.unk7F14[i].unk2 << 0x10;
            break;
        case 11:
            D_80055D58.unk7E8C[8] = 0;
            return;
        case 0:
        default:
            var_t1 = p[i][0] + (arg2 << 0x10);
            var_t0 = p[i][1] + (arg3 << 0x10);
            var_a1 = p[i][2] + (arg4 << 0x10);
            break;
        }

        var_t1 &= 0xFFFF0000;
        var_t0 &= 0xFFFF0000;
        var_a1 &= 0xFFFF0000;

        if (var_t1 > 0xFF0000) {
            var_t1 = 0xFF0000;
        }
        if (var_t0 > 0xFF0000) {
            var_t0 = 0xFF0000;
        }
        if (var_a1 > 0xFF0000) {
            var_a1 = 0xFF0000;
        }
        if (var_t1 < 0) {
            var_t1 = 0;
        }
        if (var_t0 < 0) {
            var_t0 = 0;
        }
        if (var_a1 < 0) {
            var_a1 = 0;
        }
        if (arg1 != 0) {
            p[i][3] = (int)(var_t1 - (p[i][0] & 0xFFFF0000)) / (arg1 * 2);
            p[i][4] = (int)(var_t0 - (p[i][1] & 0xFFFF0000)) / (arg1 * 2);
            p[i][5] = (int)(var_a1 - (p[i][2] & 0xFFFF0000)) / (arg1 * 2);
        } else {
            p[i][0] = var_t1;
            p[i][1] = var_t0;
            p[i][2] = var_a1;
        }
    }

    if (arg1 != 0) {
        D_80055D58.unk7E8C[4] = 1;
        D_80055D58.unk7E8C[5] = 0;
        D_80055D58.unk7E8C[6] = 0;
        D_80055D58.unk7E8C[7] = arg1;
        D_80055D58.unk7E8C[8] = arg0;
        if (arg0 == 9) {
            D_80055D58.unk7E96[0] = arg2;
            D_80055D58.unk7E96[1] = arg3;
            D_80055D58.unk7E96[2] = arg4;
        }
    } else {
        D_80055D58.unk7E8C[4] = 0;
        for (i = 0; i < 5; ++i) {
            int temp_a1, var_v0, new_var;
            temp_v0 = p[i][0];

            if (temp_v0 < 0) {
                temp_v0 += 0xFFFF;
            }

            temp_a1 = (temp_v0 >> 0x10);
            var_v0 = p[i][1];

            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }

            new_var = temp_a1 + ((var_v0 >> 0x10) << 8);
            temp_v0 = p[i][2];

            if (temp_v0 < 0) {
                temp_v0 += 0xFFFF;
            }
            sp10[i] = new_var + ((temp_v0 >> 0x10) << 0x10);
        }
        func_8008EB30(sp10);
    }
}

void func_800478E0(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_800474DC(arg0, arg1, arg2, arg3, arg4);
    }
}

static inline int inline_fn2(int arg0)
{
    if (arg0 < 0) {
        arg0 += 0xFFFF;
    }
    return (arg0 >> 0x10) - 0x40;
}

void func_80047910(int arg0, int arg1, D_8005DC6C_t* arg2)
{
    char sp10[4];
    D_8005DC80_t* temp_t0;
    int temp_a1;
    int temp_t1;
    int temp_t2;
    int v0;
    int* temp_a3;

    if (D_80055D58.unk0[0].unk2 == 0) {
        return;
    }

    temp_t0 = &D_80055D58.unk7F28[arg1];
    temp_a3 = D_80055D58.unk7F28[arg1].unk10;
    temp_a1 = inline_fn(arg2->unk0);
    temp_t1 = inline_fn(arg2->unk1);
    temp_t2 = inline_fn(arg2->unk2);

    if (arg0 != 0) {
        temp_a3[3] = ((int)(temp_a1 - (temp_a3[0] & 0xFFFF0000)) / (arg0 * 2));
        temp_a3[4] = ((int)(temp_t1 - (temp_a3[1] & 0xFFFF0000)) / (arg0 * 2));
        temp_a3[5] = ((int)(temp_t2 - (temp_a3[2] & 0xFFFF0000)) / (arg0 * 2));
    } else {
        temp_a3[0] = temp_a1;
        temp_a3[1] = temp_t1;
        temp_a3[2] = temp_t2;
    }
    if (arg0 != 0) {
        temp_t0->unk0[0] = 1;
        temp_t0->unk0[1] = 0;
        temp_t0->unk0[2] = 0;
        temp_t0->unk0[3] = arg0;
        return;
    }
    temp_t0->unk0[0] = 0;

    v0 = temp_a3[0];
    if (v0 < 0) {
        v0 += 0xFFFF;
    }
    sp10[0] = (v0 >> 0x10) - 0x40;

    v0 = temp_a3[1];
    if (v0 < 0) {
        v0 += 0xFFFF;
    }
    sp10[1] = (v0 >> 0x10) - 0x40;

    sp10[2] = inline_fn2(temp_a3[2]);
    sp10[3] = 0;

    if (arg1 != 0) {
        func_800A0768(arg1 - 1, sp10);
    } else {
        func_8008B430(sp10, temp_t0->unk6[3] >> 2);
    }
}

static void func_80047AB4(int arg0, int arg1, D_8005DC6C_t* arg2)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80047910(arg0, arg1, arg2);
        D_80055D58.unk7F28[arg1].unk28 = *arg2;
    }
}

void func_80047B30(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    char sp10[4];
    short var_t4;
    int var_a1;
    int var_a2;
    int var_t0;
    int var_v0;
    int var_v1;
    D_8005DC80_t* t1 = &D_80055D58.unk7F28[arg2];
    int* t2 = t1->unk10;

    var_t4 = 0;
    switch (arg0) {
    case 1:
        var_a1 = (t2[0] / 2) + (arg3 << 16);
        var_t0 = (t2[1] / 2) + (arg4 << 16);
        var_a2 = (t2[2] / 2) + (arg5 << 16);
        break;
    case 2:
        var_t4 = 0x4000;
        var_a1 = ((t2[0] * 2) + (t2[1] * 3) + t2[2]) / 6 + (arg3 << 0x10);
        var_t0 = ((t2[0] * 2) + (t2[1] * 3) + t2[2]) / 6 + (arg4 << 0x10);
        var_a2 = ((t2[0] * 2) + (t2[1] * 3) + t2[2]) / 6 + (arg5 << 0x10);
        break;
    case 3:
        var_t4 = 0x4000;
        var_v1 = ((t2[0] * 2) + (t2[1] * 3) + t2[2]) / 12;
        var_a1 = var_v1 + (arg3 << 0x10);
        var_t0 = var_v1 + (arg4 << 0x10);
        var_a2 = var_v1 + (arg5 << 0x10);
        break;
    case 4:
    case 9:
        var_a1 = (t1->unk28.unk0 + arg3) << 0x10;
        var_t0 = (t1->unk28.unk1 + arg4) << 0x10;
        var_a2 = (t1->unk28.unk2 + arg5) << 0x10;
        break;
    case 5:
        var_t4 = 0x4000;
        var_a1 = (t1->unk28.unk0 << 0xF) + (arg3 << 0x10);
        var_t0 = (t1->unk28.unk1 << 0xF) + (arg4 << 0x10);
        var_a2 = (t1->unk28.unk2 << 0xF) + (arg5 << 0x10);
        break;
    case 6:
        var_t4 = 0x4000;
        {
            int v1 = t1->unk28.unk1;
            int a0 = t1->unk28.unk2;
            int v0 = t1->unk28.unk0;
            var_a2 = v1 << 0x10;
            a0 <<= 0x10;
            v0 <<= 0x11;
            v1 <<= 0x11;
            v0 += v1 + var_a2;
            v0 += a0;
            var_a1 = v0 / 6 + (arg3 << 0x10);
            var_t0 = v0 / 6 + (arg4 << 0x10);
            var_a2 = v0 / 6 + (arg5 << 0x10);
        }
        break;
    case 7:
        var_t4 = 0x4000;
        {
            int v1 = t1->unk28.unk1;
            int a0 = t1->unk28.unk2;
            int v0 = t1->unk28.unk0;
            var_a2 = v1 << 0x10;
            a0 <<= 0x10;
            v0 <<= 0x11;
            v1 <<= 0x11;
            v0 += v1 + var_a2;
            v0 += a0;
            var_a1 = v0 / 12 + (arg3 << 0x10);
            var_t0 = v0 / 12 + (arg4 << 0x10);
            var_a2 = v0 / 12 + (arg5 << 0x10);
        }
        break;
    case 8:
    case 15:
        var_a1 = t1->unk28.unk0 << 0x10;
        var_t0 = t1->unk28.unk1 << 0x10;
        var_a2 = t1->unk28.unk2 << 0x10;
        break;
    case 11:
        t1->unk0[4] = 0;
        return;
    default:
        var_a1 = t2[0] + (arg3 << 0x10);
        var_t0 = t2[1] + (arg4 << 0x10);
        var_a2 = t2[2] + (arg5 << 0x10);
        break;
    }
    var_a1 = var_a1 & 0xFFFF0000;
    var_t0 = var_t0 & 0xFFFF0000;
    var_a2 = var_a2 & 0xFFFF0000;

    if (var_a1 > 0x800000) {
        var_a1 = 0x800000;
    }
    if (var_t0 > 0x800000) {
        var_t0 = 0x800000;
    }
    if (var_a2 > 0x800000) {
        var_a2 = 0x800000;
    }
    if (var_a1 < 0) {
        var_a1 = 0;
    }
    if (var_t0 < 0) {
        var_t0 = 0;
    }
    if (var_a2 < 0) {
        var_a2 = 0;
    }
    if (arg1 != 0) {
        t2[3] = ((int)(var_a1 - (t2[0] & 0xFFFF0000)) / (arg1 * 2));
        t2[4] = ((int)(var_t0 - (t2[1] & 0xFFFF0000)) / (arg1 * 2));
        t2[5] = ((int)(var_a2 - (t2[2] & 0xFFFF0000)) / (arg1 * 2));
        t1->unk6[4] = ((var_t4 - t1->unk6[3]) / (arg1 * 2));
    } else {
        t2[0] = var_a1;
        t2[1] = var_t0;
        t2[2] = var_a2;
        t1->unk6[3] = var_t4;
    }
    var_v0 = 1;
    if (arg1 != 0) {
        t1->unk0[0] = 1;
        t1->unk0[1] = 0;
        t1->unk0[2] = 0;
        t1->unk0[3] = arg1;
        t1->unk0[4] = arg0;
        if (arg0 == 9) {
            t1->unk6[0] = arg3;
            t1->unk6[1] = arg4;
            t1->unk6[2] = arg5;
        }
    } else {
        t1->unk0[0] = 0;
        var_v0 = t2[0] >> 0x10;
        if (t2[0] < 0) {
            var_v1 = t2[0] + 0xFFFF;
            var_v0 = var_v1 >> 0x10;
        }
        sp10[0] = var_v0 - 0x40;
        var_v0 = t2[1] >> 0x10;
        if (t2[1] < 0) {
            var_v1 = t2[1] + 0xFFFF;
            var_v0 = var_v1 >> 0x10;
        }
        sp10[1] = var_v0 - 0x40;
        var_v0 = t2[2] >> 0x10;
        if (t2[2] < 0) {
            var_v1 = t2[2] + 0xFFFF;
            var_v0 = var_v1 >> 0x10;
        }
        sp10[2] = var_v0 - 0x40;
        sp10[3] = 0;
        if (arg2 != 0) {
            func_800A0768(arg2 - 1, sp10);
        } else {
            func_8008B430(sp10, ((u_short)t1->unk6[3] << 0x10) >> 0x12);
        }
    }
}

static void func_80047FC0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80047B30(arg0, arg1, arg2, arg3, arg4, arg5);
    }
}

void func_80047FFC()
{
    int sp18[5];
    int i;
    int var_v0;
    int new_var;
    int new_var2;
    int var_v1;
    int(*t1)[6];

    if (D_80055D58.unk7E8C[4] == 0) {
        return;
    }

    t1 = D_80055D58.unk7E9C;

    for (i = 0; i < 5; ++i) {
        t1[i][0] += t1[i][3];
        t1[i][1] += t1[i][4];
        t1[i][2] += t1[i][5];
    }

    for (i = 0; i < 5; ++i) {
        var_v1 = t1[i][0];
        if (var_v1 < 0) {
            var_v1 += 0xFFFF;
        }
        var_v0 = t1[i][1];
        new_var2 = var_v1 >> 16;
        if (var_v0 < 0) {
            var_v0 += 0xFFFF;
        }
        var_v1 = t1[i][2];
        new_var = new_var2 + ((var_v0 >> 16) << 8);
        if (var_v1 < 0) {
            var_v1 += 0xFFFF;
        }
        sp18[i] = new_var + ((var_v1 >> 16) << 16);
    }
    func_8008EB30(sp18);
    D_80055D58.unk7E8C[5] += 1;
    if (D_80055D58.unk7E8C[5] >= (D_80055D58.unk7E8C[7] * 2)) {
        if (D_80055D58.unk7E8C[8] == 9) {
            func_800474DC(4, D_80055D58.unk7E8C[7], D_80055D58.unk7E96[0] / 2,
                D_80055D58.unk7E96[1] / 2, D_80055D58.unk7E96[2] / 2);
            D_80055D58.unk7E8C[8] = 10;
            return;
        }
        if (D_80055D58.unk7E8C[8] == 10) {
            func_800474DC(9, D_80055D58.unk7E8C[7], D_80055D58.unk7E96[0],
                D_80055D58.unk7E96[1], D_80055D58.unk7E96[2]);
            D_80055D58.unk7E8C[8] = 9;
            return;
        }
        D_80055D58.unk7E8C[4] = 0;
    }
}

void func_800481C0()
{
    char sp18[4];
    int i;
    int var_v0;
    D_8005DC80_t* p = D_80055D58.unk7F28;

    for (i = 0; i < 17; ++i) {
        int* a2 = p[i].unk10;
        if (p[i].unk0[0] != 0) {
            a2[0] += a2[3];
            a2[1] += a2[4];
            a2[2] += a2[5];

            var_v0 = a2[0];
            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }
            sp18[0] = (var_v0 >> 16) - 0x40;
            var_v0 = a2[1];
            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }
            sp18[1] = (var_v0 >> 16) - 0x40;
            var_v0 = a2[2];
            if (var_v0 < 0) {
                var_v0 += 0xFFFF;
            }
            sp18[2] = (var_v0 >> 16) - 0x40;
            sp18[3] = 0;

            if (i != 0) {
                func_800A0768(i - 1, sp18);
            } else {
                p[0].unk6[3] += p[0].unk6[4];
                func_8008B430(sp18, p[0].unk6[3] >> 2);
            }
            ++p[i].unk0[1];
            if (p[i].unk0[1] >= (p[i].unk0[3] * 2)) {
                if (p[i].unk0[4] == 9) {
                    func_80047FC0(4, p[i].unk0[3], i, p[i].unk6[0] / 2, p[i].unk6[1] / 2,
                        p[i].unk6[2] / 2);
                    p[i].unk0[4] = 10;
                } else if (p[i].unk0[4] == 10) {
                    func_80047B30(
                        9, p[i].unk0[3], i, p[i].unk6[0], p[i].unk6[1], p[i].unk6[2]);
                    p[i].unk0[4] = 9;
                } else if (p[i].unk0[4] == 14) {
                    func_80047B30(15, p[i].unk0[3], i, 0, 0, 0);
                    p[i].unk0[4] = 15;
                } else {
                    p[i].unk0[0] = 0;
                }
            }
        }
    }
}

void func_800483FC()
{
    int i;
    int j;
    u_int var_t5;
    u_short g;
    u_short r;
    u_short b;
    struct ColorInfo* index;
    int c;

    for (i = 0; i < 14; ++i) {
        if (D_80055D58.unk0[i].unk6[0] == 0) {
            continue;
        }
        if (++D_80055D58.unk0[i].unk6[2] >= (D_80055D58.unk0[i].unk6[3] / 8)) {

            D_80055D58.unk0[i].unk6[2] = 0;

            if (D_80055D58.unk0[i].unk6[3] >= 8) {
                var_t5 = 1;
                c = D_80055D58.unk0[i].unk6[1];
                index = D_80055D58.unk0[i].unkE;
                for (j = 0; j < 256; ++j) {
                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }
                    r = index[j].r + _animOffset16[index[j].rindex][c];
                    g = index[j].g + _animOffset16[index[j].gindex][c];
                    b = index[j].b + _animOffset16[index[j].bindex][c];
                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }
                    index[j].g = g;
                    index[j].b = b;
                    index[j].r = r;
                    loadImageSource[i][j] = r + (g << 5) + (b << 10) + (index[j].a << 15);
                }
            } else if (D_80055D58.unk0[i].unk6[3] >= 4) {
                var_t5 = 2;
                c = D_80055D58.unk0[i].unk6[1];
                index = D_80055D58.unk0[i].unkE;
                for (j = 0; j < 256; ++j) {
                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }
                    r = index[j].r + _animOffset8[index[j].rindex][c];
                    g = index[j].g + _animOffset8[index[j].gindex][c];
                    b = index[j].b + _animOffset8[index[j].bindex][c];
                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }
                    index[j].r = r;
                    index[j].g = g;
                    index[j].b = b;
                    loadImageSource[i][j] = r + (g << 5) + (b << 10) + (index[j].a << 15);
                }
            } else if (D_80055D58.unk0[i].unk6[3] >= 2) {
                var_t5 = 4;
                c = D_80055D58.unk0[i].unk6[1];
                index = D_80055D58.unk0[i].unkE;
                for (j = 0; j < 256; ++j) {
                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }
                    r = index[j].r + _animOffset4[index[j].rindex][c];
                    g = index[j].g + _animOffset4[index[j].gindex][c];
                    b = index[j].b + _animOffset4[index[j].bindex][c];
                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }
                    index[j].r = r;
                    index[j].g = g;
                    index[j].b = b;
                    loadImageSource[i][j] = r + (g << 5) + (b << 10) + (index[j].a << 15);
                }
            } else {
                var_t5 = 8;
                c = D_80055D58.unk0[i].unk6[1];
                index = D_80055D58.unk0[i].unkE;
                for (j = 0; j < 256; ++j) {
                    if ((index[j].r + index[j].g + index[j].b) == 0) {
                        continue;
                    }
                    r = index[j].r + _animOffset2[index[j].rindex][c];
                    g = index[j].g + _animOffset2[index[j].gindex][c];
                    b = index[j].b + _animOffset2[index[j].bindex][c];
                    if (((b | (r | g)) << 16) == 0) {
                        b = 1;
                    }
                    index[j].r = r;
                    index[j].g = g;
                    index[j].b = b;
                    loadImageSource[i][j] = r + (g << 5) + (b << 10) + (index[j].a << 15);
                }
            }
            if (++D_80055D58.unk0[i].unk6[1] >= (16 / var_t5)) {
                if (D_80055D58.unk0[i].unk6[4] == 9) {
                    func_80046DC0(4, D_80055D58.unk0[i].unk6[3], i,
                        D_80055D58.unk0[i].unkB[0] / 2, D_80055D58.unk0[i].unkB[1] / 2,
                        D_80055D58.unk0[i].unkB[2] / 2);
                    D_80055D58.unk0[i].unk6[4] = 10;
                } else if (D_80055D58.unk0[i].unk6[4] == 10) {
                    func_80046DC0(9, D_80055D58.unk0[i].unk6[3], i,
                        D_80055D58.unk0[i].unkB[0], D_80055D58.unk0[i].unkB[1],
                        D_80055D58.unk0[i].unkB[2]);
                    D_80055D58.unk0[i].unk6[4] = 9;
                } else if (D_80055D58.unk0[i].unk6[4] == 14) {
                    func_80046DC0(15, D_80055D58.unk0[i].unk6[3], i, 0, 0, 0);
                    D_80055D58.unk0[i].unk6[4] = 15;
                } else {
                    D_80055D58.unk0[i].unk6[0] = 0;
                }
            }
        }
        D_80055D58.unk0[0].unk0 = 1;
    }
}

static void func_80048A3C(int arg0) { D_80055D58.unk0[arg0].unk6[0] = 0; }

void func_80048A64(u_short* img, u_int y, u_int x, u_int w)
{
    RECT rect;
    u_short px;
    u_int i;
    struct ColorInfo* dst;

    if (y >= 14) {
        setRECT(&rect, x + 768, y + 224, w, 1);
        LoadImage(&rect, (u_long*)img);
        return;
    }

    if (D_80055D58.unk0[y].unk5 == 0) {
        D_80055D58.unk0[y].unk6[0] = 0;
        for (i = 0; i < w; ++i) {
            px = img[i];
            dst = &D_80055D58.unk0[y].unkE[x + i];
            loadImageSource[y][x + i] = px;
            D_80055D58.unk0[y].unk70E[x + i] = px;
            dst->r = (px & 0x1F);
            dst->g = ((px & 0x3E0) >> 5);
            dst->b = ((px & 0x7C00) >> 10);
            dst->a = ((px & 0x8000) >> 15);
        }
        D_80055D58.unk0[0].unk0 = 1;
    }
}

void func_80048B8C(
    int arg0, u_short* arg1, int arg2, short arg3, short arg4, short arg5, int arg6)
{
    int i;
    int new_var;
    int new_var2;
    int new_var3;
    short r;
    short g;
    short b;
    short a;
    u_short t4;

    for (i = 0; i < 0x100; ++i) {
        a = arg1[i];
        if (a != 0) {
            switch (arg0) {
            case 5:
                t4 = 0x1F;
                r = arg3 + ((((char)a) & t4) >> 1);
                g = arg4 + ((a & 0x3E0) >> 6);
                b = arg5 + ((a & 0x7C00) >> 11);
                break;

            case 6:
                new_var = a & 0x1F;
                new_var2 = (a & 0x3E0) >> 5;
                new_var3 = (a & 0x7C00) >> 10;
                r = arg3 + ((new_var * 2) + (new_var2 * 3) + new_var3) / 6;
                g = arg4 + ((new_var * 2) + (new_var2 * 3) + new_var3) / 6;
                b = arg5 + ((new_var * 2) + (new_var2 * 3) + new_var3) / 6;
                break;

            case 7:
                new_var = a & 0x1F;
                new_var2 = (a & 0x3E0) >> 5;
                new_var3 = (a & 0x7C00) >> 10;
                r = arg3 + ((new_var * 2) + (new_var2 * 3) + new_var3) / 12;
                g = arg4 + ((new_var * 2) + (new_var2 * 3) + new_var3) / 12;
                b = arg5 + ((new_var * 2) + (new_var2 * 3) + new_var3) / 12;
                break;

            case 0:
            default:
                r = arg3 + (a & 0x1F);
                g = arg4 + ((a & 0x3E0) >> 5);
                b = arg5 + ((a & 0x7C00) >> 10);
                break;
            }

        } else {
            r = a & 0x1F;
            t4 = (a & 0x3E0);
            g = t4 >> 5;
            b = (a & 0x7C00) >> 10;
        }
        t4 = a;
        t4 = t4 >> 15;
        if (r >= 32) {
            r = 31;
        }
        if (g >= 32) {
            g = 31;
        }
        if (b >= 32) {
            b = 31;
        }
        if ((r << 16) < 1) {
            r = 0;
        }
        if ((g << 16) <= 0) {
            g = 0;
        }
        if ((b << 16) <= 0) {
            b = 0;
        }
        if ((((r | g | b) << 16) == 0) && (a & 0x7FFF)) {
            b = 1;
        }
        if (arg6 != 0) {
            loadImageSource[arg2][i] = r + (g << 5) + (b << 10) + (t4 << 15);
            if (D_80055D58.unk0[arg2].unk6[0] == 0) {
                struct ColorInfo* t5 = &D_80055D58.unk0[arg2].unkE[i];
                t5->r = r;
                t5->g = g;
                t5->b = b;
                t5->a = t4;
            }
        }
        D_80055D58.unk0[arg2].unk70E[i] = r + (g << 5) + (b << 10) + (t4 << 15);
    }

    D_80055D58.unk0[0].unk0 = 1;
}

void func_80048E68(
    u_short* arg0, int arg1, u_short arg2, u_short arg3, u_short arg4, int arg5)
{
    func_80048B8C(8, arg0, arg1, arg2, arg3, arg4, arg5);
}

void func_80048EC4()
{
    int i;
    int var_v0;
    u_int* var_v1;
    int(*p)[6] = D_80055D58.unk7E9C;

    var_v1 = func_8008EB24();
    for (i = 0; i < 5; ++i) {
        D_80055D58.unk7F14[i].unk0 = var_v1[i];
        var_v0 = var_v1[i] & 0xFF00;
        if (var_v0 < 0) {
            var_v0 += 0xFF;
        }
        D_80055D58.unk7F14[i].unk1 = (var_v0 >> 8);
        var_v0 = var_v1[i] & 0xFF0000;
        if (var_v0 < 0) {
            var_v0 += 0xFFFF;
        }
        D_80055D58.unk7F14[i].unk2 = (var_v0 >> 16);
        p[i][0] = ((var_v1[i] & 0xFF) << 16);
        p[i][1] = ((var_v1[i] & 0xFF00) << 8);
        p[i][2] = (var_v1[i] & 0xFF0000);
    }
}

void func_80048F8C()
{
    RECT rect;

    if (D_80055D58.unk0[0].unk0 != 0) {
        setRECT(&rect, 768, 224, 256, 14);
        LoadImage(&rect, (u_long*)loadImageSource[0]);
        D_80055D58.unk0[0].unk0 = 0;
    }
}

static void func_80048FEC(short arg0) { D_80055D58.unk0[0].unk2 = arg0; }

void func_80048FF8()
{
    int i;

    D_80055D58.unk0[0].unk0 = 0;
    D_80055D58.unk0[0].unk2 = 1;
    for (i = 0; i < 14; ++i) {
        D_80055D58.unk0[i].unk5 = 0;
        D_80055D58.unk0[i].unk6[0] = 0;
        D_80055D58.unk0[i].unk6[4] = 0;
    }

    D_80055D58.unk7E8C[4] = 0;
    D_80055D58.unk7E8C[8] = 0;

    for (i = 0; i < 17; ++i) {
        D_80055D58.unk7F28[i].unk0[0] = 0;
        D_80055D58.unk7F28[i].unk0[4] = 0;
        D_80055D58.unk7F28[i].unk6[3] = 0;
        *((int*)&D_80055D58.unk7F28[i].unk28) = 0x404040;
        D_80055D58.unk7F28[i].unk10[2] = 0x400000;
        D_80055D58.unk7F28[i].unk10[1] = 0x400000;
        D_80055D58.unk7F28[i].unk10[0] = 0x400000;
    }
}

static void _asmNop() { __asm__(".nop;"); }

void vs_main_nop9(int arg0 __attribute__((unused)), int arg1 __attribute__((unused))) { }

static void nop10(int arg0 __attribute__((unused)), int arg1 __attribute__((unused))) { }

static void nop11() { }

void vs_main_memcpy(void* dest, void* src, u_int sz)
{
    __asm__("srl $t0, %2, 4;"
            "beqz $t0, 1f;"
            "and $t5, %2, 12;"
            "0:"
            "lw $t1, 0(%1);"
            "lw $t2, 4(%1);"
            "lw $t3, 8(%1);"
            "lw $t4, 12(%1);"
            "addu $t0, -1;"
            "sw $t1, 0(%0);"
            "sw $t2, 4(%0);"
            "sw $t3, 8(%0);"
            "sw $t4, 12(%0);"
            "addu %1, 16;"
            "bnez $t0, 0b;"
            "addu %0, 16;"
            "beqz $t5, 2f;"
            "1:"
            "lw $t1, 0(%1);"
            "addu $t5, -4;"
            "sw $t1, 0(%0);"
            "addu %1, 4;"
            "bnez $t5, 1b;"
            "addu %0, 4;"
            "2:" ::"r"(dest),
        "r"(src), "r"(sz));
}

void vs_main_bzero(void* dest, int sz)
{
    __asm__("and $t0, %1, 0xFFFC;"
            "beqz $t0, 1f;"
            "0:"
            "sw $0, 0(%0);"
            "addu $t0, -4;"
            "bnez $t0, 0b;"
            "addu %0, 4;"
            "1:" ::"r"(dest),
        "r"(sz));
}

static void nop12() { }
