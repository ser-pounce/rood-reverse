#include "3264C.h"
#include "common.h"
#include "overlays.h"
#include "../BATTLE/BATTLE.PRG/battle.h"
#include "lbas.h"
#include <libapi.h>
#include <libds.h>
#include <libetc.h>
#include <libpad.h>
#include <libsnd.h>
#include <libspu.h>
#include <libgpu.h>
#include <rand.h>

typedef struct HeapHeader {
    struct HeapHeader* prev;
    struct HeapHeader* next;
    unsigned int blockSz;
    int unkC;
} HeapHeader;

typedef struct {
    unsigned char unk0;
    unsigned char exId;
    unsigned char unk2;
    unsigned char unk3;
    unsigned char unk4;
    unsigned char unk5;
    unsigned char unk6;
    unsigned char lock;
    unsigned char actData[2];
    unsigned char connected;
} PortInfo;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
} LoadImage_t;

typedef struct {
    int unk0[2];
    unsigned short unk8;
    unsigned short unkA;
    unsigned char* unkC;
    int unk10[10];
} D_80050118_t;

typedef struct {
    int offset;
    unsigned int unk4;
    int unk8;
    union {
        struct {
            short unkC;
            unsigned char unkE;
            unsigned char unkF[1];
        } unkC_s;
        unsigned int unkC_i;
    } unkC_u;
    unsigned char unk10[2];
    unsigned int unk14[4];
    void* unk24[4];
    vs_main_CdQueueSlot* unk34[4];
    unsigned int unk44;
    unsigned char unk48[4];
    void* unk4C[3];
    vs_main_CdQueueSlot* unk58[3];
    void* unk64[3];
    int* unk70[3];
    int fileId;
    void* unk80;
    vs_main_CdQueueSlot* unk84;
} D_8005E038_t;

typedef struct {
    unsigned char unk0;
    unsigned char unk1;
    unsigned char unk2;
    unsigned char unk3;
} D_8005DC6C_t;

typedef struct {
    unsigned char unk0[6];
    short unk6[5];
    int unk10[6];
    D_8005DC6C_t unk28;
} D_8005DC80_t;

typedef struct {
    unsigned short unk0;
    unsigned short unk2;
    unsigned char unk4;
    unsigned char unk5;
    unsigned char unk6[5];
    signed char unkB[3];
    unsigned char unkE[256][7];
    unsigned short unk70E[254];
} D_80055D58_t2;

typedef struct {
    D_80055D58_t2 unk0[14];
    unsigned char unk7E8C[10];
    short unk7E96[3];
    int unk7E9C[5][6];
    D_8005DC6C_t unk7F14[5];
    D_8005DC80_t unk7F28[17];
} D_80055D58_t;

typedef struct {
    unsigned char status;
    unsigned char unk1;
    unsigned char unk2;
    unsigned char unk3;
    unsigned int unk4;
    unsigned int unk8;
    int cdSector;
    int sectorCount;
    void* vram;
    DslFILTER pcm;
    DslLOC cdLoc;
    int commandId;
    int unk24;
    int unk28;
    unsigned int unk2C;
    unsigned int bufIndex;
    int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    int unk44;
} D_80055D10_t;

typedef union {
    short s[0];
    int i;
} u_1632;

typedef struct {
    unsigned short unk0;
    unsigned short unk2;
    unsigned short unk4[4];
    unsigned short unkC[8];
} D_80060068_t2;

typedef struct {
    int unk0;
    short unk4[12];
    int unk1C;
    unsigned char unk20[8];
    D_80060068_t2 unk28[6];
    int unk7C[24];
} D_80060068_t;

typedef struct D_80061068_t {
    unsigned short unk0[6];
} D_80061068_t;

void __main();
static void func_80042998();
static void func_80042A64();
static void do_wait();
static void padForceMode();
static void padResetDefaults(int, void*);
static void padConnect(int, void*);
static void padSetActData(int arg0, int arg1, int arg2);
static int getCdStatus();
void func_80042CB0();
static void func_80043668();
static void vs_main_initCdQueue();
static void func_80044A60();
static void vs_main_populateQueueSlot(vs_main_CdQueueSlot*, void*);
static void func_80044C74();
static int func_80045440(int arg0);
static void func_800455F4();
void func_80045754(int, int, int, int);
static void func_800461CC(int, unsigned int[], unsigned int, int, int);
static int func_800464FC(int, int, int);
static void func_80046678(int);
static void func_80046770(int);
static int func_800467A0();
void func_800468FC();
void func_80046B3C(int, int, unsigned short*);
void func_80047910(int, int, D_8005DC6C_t*);
static void func_8004908C();
static void nop9(int, int);
static void nop10(int, int);
void func_8006A5C0();
int titlePrgMain();
void execBattle();
static void initRand();
static void initHeap(HeapHeader* node, unsigned int value);

typedef struct {
    unsigned char wLo;
    unsigned char wHi;
    unsigned char hLo;
    unsigned char hHi;
} ImgHeader;

void* debug_stack_p = (void*)0x200000;
unsigned int debug_stack_sz = 0x4000;
unsigned char buildTimestamp[] = "Mar 28 00:09\0\0\0";

EMBED_RGBA16("build/assets/SLUS_010.40/nowLoading.rgba16.bin", nowLoading)

static unsigned char D_8004A504[]
    = { 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x07, 0x06, 0x00, 0x04, 0x01,
          0x00, 0x00, 0x01, 0x11, 0x08, 0x02, 0x06, 0xFF, 0x00, 0x00, 0x00 };

static unsigned char actParams[] = { 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

static int soundLBAs[] = {
    VS_WAVE0000_DAT_LBA, VS_WAVE0001_DAT_LBA, VS_WAVE0002_DAT_LBA, VS_WAVE0003_DAT_LBA,
    VS_WAVE0004_DAT_LBA, VS_WAVE0005_DAT_LBA, VS_WAVE0006_DAT_LBA, VS_WAVE0007_DAT_LBA,
    VS_WAVE0008_DAT_LBA, VS_WAVE0009_DAT_LBA, VS_WAVE0010_DAT_LBA, VS_WAVE0011_DAT_LBA,
    VS_WAVE0012_DAT_LBA, VS_WAVE0013_DAT_LBA, VS_WAVE0014_DAT_LBA, VS_WAVE0015_DAT_LBA,
    VS_WAVE0016_DAT_LBA, VS_WAVE0017_DAT_LBA, VS_WAVE0018_DAT_LBA, VS_WAVE0019_DAT_LBA,
    VS_WAVE0020_DAT_LBA, VS_WAVE0021_DAT_LBA, VS_WAVE0022_DAT_LBA, VS_WAVE0023_DAT_LBA,
    VS_WAVE0024_DAT_LBA, VS_WAVE0025_DAT_LBA, VS_WAVE0026_DAT_LBA, VS_WAVE0027_DAT_LBA,
    VS_WAVE0028_DAT_LBA, VS_WAVE0029_DAT_LBA, VS_WAVE0030_DAT_LBA, VS_WAVE0031_DAT_LBA,
    VS_WAVE0032_DAT_LBA, VS_WAVE0033_DAT_LBA, VS_WAVE0034_DAT_LBA, VS_WAVE0035_DAT_LBA,
    VS_WAVE0036_DAT_LBA, VS_WAVE0037_DAT_LBA, VS_WAVE0038_DAT_LBA, VS_WAVE0039_DAT_LBA,
    VS_WAVE0040_DAT_LBA, VS_WAVE0041_DAT_LBA, VS_WAVE0042_DAT_LBA, VS_WAVE0043_DAT_LBA,
    VS_WAVE0044_DAT_LBA, VS_WAVE0045_DAT_LBA, VS_WAVE0046_DAT_LBA, VS_WAVE0047_DAT_LBA,
    VS_WAVE0048_DAT_LBA, VS_WAVE0049_DAT_LBA, VS_WAVE0050_DAT_LBA, VS_WAVE0051_DAT_LBA,
    VS_WAVE0052_DAT_LBA, VS_WAVE0053_DAT_LBA, VS_WAVE0054_DAT_LBA, VS_WAVE0055_DAT_LBA,
    VS_WAVE0056_DAT_LBA, VS_WAVE0057_DAT_LBA, VS_WAVE0058_DAT_LBA, VS_WAVE0059_DAT_LBA,
    VS_WAVE0060_DAT_LBA, VS_WAVE0061_DAT_LBA, VS_WAVE0062_DAT_LBA, VS_WAVE0063_DAT_LBA,
    VS_WAVE0064_DAT_LBA, VS_WAVE0065_DAT_LBA, VS_WAVE0066_DAT_LBA, VS_WAVE0067_DAT_LBA,
    VS_WAVE0068_DAT_LBA, VS_WAVE0069_DAT_LBA, VS_WAVE0070_DAT_LBA, VS_WAVE0071_DAT_LBA,
    VS_WAVE0072_DAT_LBA, VS_WAVE0073_DAT_LBA, VS_WAVE0074_DAT_LBA, VS_WAVE0075_DAT_LBA,
    VS_WAVE0076_DAT_LBA, VS_WAVE0077_DAT_LBA, VS_WAVE0078_DAT_LBA, VS_WAVE0079_DAT_LBA,
    VS_WAVE0080_DAT_LBA, VS_WAVE0081_DAT_LBA, VS_WAVE0082_DAT_LBA, VS_WAVE0083_DAT_LBA,
    VS_WAVE0084_DAT_LBA, VS_WAVE0085_DAT_LBA, VS_WAVE0086_DAT_LBA, VS_WAVE0087_DAT_LBA,
    VS_WAVE0088_DAT_LBA, VS_WAVE0089_DAT_LBA, VS_WAVE0090_DAT_LBA, VS_WAVE0091_DAT_LBA,
    VS_WAVE0092_DAT_LBA, VS_WAVE0093_DAT_LBA, VS_WAVE0094_DAT_LBA, VS_WAVE0095_DAT_LBA,
    VS_WAVE0096_DAT_LBA, VS_WAVE0097_DAT_LBA, VS_WAVE0098_DAT_LBA, VS_WAVE0099_DAT_LBA
    // VS_WAVE0200_DAT_LBA # Unused
};
static int musicLBAs[] = { VS_MUSIC000_DAT_LBA, VS_MUSIC001_DAT_LBA, VS_MUSIC002_DAT_LBA,
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
static int seLBAs[] = { VS_SEP00000_DAT_LBA, VS_SEP00001_DAT_LBA, VS_SEP00002_DAT_LBA,
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
static int soundFileSizes[] = { VS_WAVE0000_DAT_SIZE, VS_WAVE0001_DAT_SIZE,
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
static int musicFileSizes[] = { VS_MUSIC000_DAT_SIZE, VS_MUSIC001_DAT_SIZE,
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
static int seFileSizes[] = { VS_SEP00000_DAT_SIZE, VS_SEP00001_DAT_SIZE,
    VS_SEP00002_DAT_SIZE, VS_SEP00003_DAT_SIZE, VS_SEP00004_DAT_SIZE,
    VS_SEP00005_DAT_SIZE, VS_SEP00006_DAT_SIZE, VS_SEP00007_DAT_SIZE,
    VS_SEP00008_DAT_SIZE, VS_SEP00009_DAT_SIZE, VS_SEP00010_DAT_SIZE,
    VS_SEP00011_DAT_SIZE, VS_SEP00012_DAT_SIZE, VS_SEP00013_DAT_SIZE,
    VS_SEP00014_DAT_SIZE, VS_SEP00015_DAT_SIZE, VS_SEP00016_DAT_SIZE,
    VS_SEP00017_DAT_SIZE, VS_SEP00018_DAT_SIZE, VS_SEP00019_DAT_SIZE,
    VS_SEP00020_DAT_SIZE, VS_SEP00021_DAT_SIZE, VS_SEP00022_DAT_SIZE,
    VS_SEP00023_DAT_SIZE, VS_SEP00024_DAT_SIZE, VS_SEP00025_DAT_SIZE,
    VS_SEP00026_DAT_SIZE, VS_SEP00027_DAT_SIZE, VS_SEP00028_DAT_SIZE,
    VS_SEP00029_DAT_SIZE, VS_SEP00030_DAT_SIZE, VS_SEP00031_DAT_SIZE,
    VS_SEP00032_DAT_SIZE, VS_SEP00033_DAT_SIZE, VS_SEP00034_DAT_SIZE,
    VS_SEP00035_DAT_SIZE, VS_SEP00036_DAT_SIZE, VS_SEP00037_DAT_SIZE,
    VS_SEP00038_DAT_SIZE, VS_SEP00039_DAT_SIZE, VS_SEP00040_DAT_SIZE,
    VS_SEP00041_DAT_SIZE, VS_SEP00042_DAT_SIZE, VS_SEP00043_DAT_SIZE,
    VS_SEP00044_DAT_SIZE, VS_SEP00045_DAT_SIZE, VS_SEP00046_DAT_SIZE,
    VS_SEP00047_DAT_SIZE, VS_SEP00048_DAT_SIZE, VS_SEP00049_DAT_SIZE,
    VS_SEP00050_DAT_SIZE, VS_SEP00051_DAT_SIZE, VS_SEP00052_DAT_SIZE,
    VS_SEP00053_DAT_SIZE, VS_SEP00054_DAT_SIZE, VS_SEP00055_DAT_SIZE,
    VS_SEP00056_DAT_SIZE, VS_SEP00057_DAT_SIZE, VS_SEP00058_DAT_SIZE,
    VS_SEP00059_DAT_SIZE, VS_SEP00060_DAT_SIZE, VS_SEP00061_DAT_SIZE,
    VS_SEP00062_DAT_SIZE, VS_SEP00063_DAT_SIZE, VS_SEP00064_DAT_SIZE,
    VS_SEP00065_DAT_SIZE, VS_SEP00066_DAT_SIZE, VS_SEP00067_DAT_SIZE,
    VS_SEP00068_DAT_SIZE, VS_SEP00069_DAT_SIZE, VS_SEP00070_DAT_SIZE,
    VS_SEP00071_DAT_SIZE, VS_SEP00072_DAT_SIZE, VS_SEP00073_DAT_SIZE,
    VS_SEP00074_DAT_SIZE, VS_SEP00075_DAT_SIZE, VS_SEP00076_DAT_SIZE,
    VS_SEP00077_DAT_SIZE, VS_SEP00078_DAT_SIZE, VS_SEP00079_DAT_SIZE,
    VS_SEP00080_DAT_SIZE, VS_SEP00081_DAT_SIZE, VS_SEP00082_DAT_SIZE,
    VS_SEP00083_DAT_SIZE, VS_SEP00084_DAT_SIZE, VS_SEP00085_DAT_SIZE,
    VS_SEP00086_DAT_SIZE, VS_SEP00087_DAT_SIZE, VS_SEP00088_DAT_SIZE,
    VS_SEP00089_DAT_SIZE, VS_SEP00090_DAT_SIZE, VS_SEP00091_DAT_SIZE,
    VS_SEP00092_DAT_SIZE, VS_SEP00093_DAT_SIZE, VS_SEP00094_DAT_SIZE,
    VS_SEP00095_DAT_SIZE, VS_SEP00096_DAT_SIZE, VS_SEP00097_DAT_SIZE,
    VS_SEP00098_DAT_SIZE, VS_SEP00099_DAT_SIZE };
static unsigned char soundFileMap[] = { 0, 65, 66, 66, 68, 69, 67, 85, 68, 93, 69, 68, 0,
    69, 69, 0, 69, 69, 69, 69, 69, 68, 62, 61, 68, 68, 68, 68, 68, 57, 56, 72, 74, 77, 76,
    86, 87, 80, 88, 55, 70, 81, 70, 73, 75, 78, 89, 90, 79, 84, 10, 10, 10, 10, 11, 11,
    11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 18,
    18, 19, 19, 19, 19, 20, 20, 21, 21, 21, 21, 22, 22, 22, 22, 23, 23, 23, 23, 24, 24,
    25, 25, 25, 25, 0, 0, 0, 0, 0, 85, 0, 0, 91, 91, 91, 91, 91, 91, 91, 0, 60, 94, 98,
    95, 96, 97, 97, 82, 83, 0, 0, 59, 58, 72, 74, 77, 76, 86, 87, 80, 88, 0, 0, 0, 0, 0,
    0, 78, 89, 90, 79, 84, 0, 99, 99, 99, 99, 92, 64, 64, 64, 54, 53, 53, 53, 53, 53, 63,
    63, 63, 52, 51, 50, 52, 49, 47, 46, 45, 45, 45, 44, 44, 43, 42, 41, 40, 39, 38, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
extern signed char D_8004B278[63][16];
extern signed char D_8004B668[63][8];
extern signed char D_8004B860[63][4];
extern signed char D_8004B95C[63][2];
extern unsigned int D_8004B9DC[];
#define RANDARRSZ 97
extern int randArr[RANDARRSZ];
extern HeapHeader* D_80050110;
extern D_80050118_t D_80050118[2];
extern PortInfo portInfo[2];
extern HeapHeader heapA;
extern HeapHeader heapB;
extern int randIndex;
extern DslLOC cdReadLoc;
extern int D_800501CC;
extern int D_800501D0;
extern int D_800501D4;
extern int D_800501D8;
extern vs_main_CdQueueSlot vs_main_cdQueue[32];
extern u_1632 D_80050460;
extern int D_80050470;
extern int D_80050478[];
extern int sp2;
extern int D_80055C88;
extern unsigned int D_80055C90[];
extern D_80055D10_t D_80055D10;
extern unsigned char dsControlBuf[11];
extern D_80055D58_t D_80055D58;
extern int sp;
extern unsigned char padBuffer[2][34];
extern unsigned char D_8005DBE8;
extern int D_8005DBF4[5][6];
extern D_8005E038_t D_8005E038;
extern int D_8005E03C;
extern void* D_8005E08C;
extern int D_8005E0BC;
extern unsigned int frameDuration;
extern int D_8005E214;
extern int D_8005E240;
extern int D_8005E248;
extern int D_8005E24C;
extern unsigned short loadImageSource[][256];
extern int D_8005FE70;
extern int D_8005FE74;
extern int D_8005FE78;
extern int D_8005FE7C;
extern int D_8005FE80;
extern int D_8005FE84;
extern unsigned char D_8005FFB8[];
extern D_80060068_t D_80060068;
extern unsigned char D_8006002B;
extern D_80061068_t D_80061068;
extern signed char D_80061074[4];
extern MATRIX D_1F800014_mat;

static void vs_main_loadBattlePrg()
{
    vs_main_CdFile cdFile;
    vs_main_CdQueueSlot* slot;

    cdFile.lba = VS_BATTLE_PRG_LBA;
    cdFile.size = VS_BATTLE_PRG_SIZE;
    slot = vs_main_getQueueSlot(&cdFile);
    vs_main_populateQueueSlot(slot, vs_overlay_slots[0]);

    while (slot->unk0[0] != 4) {
        func_8004261C(0);
    }

    func_80044B80(slot);

    cdFile.lba = VS_INITBTL_PRG_LBA;
    cdFile.size = VS_INITBTL_PRG_SIZE;
    slot = vs_main_getQueueSlot(&cdFile);
    vs_main_populateQueueSlot(slot, vs_overlay_slots[1]);

    while (slot->unk0[0] != 4) {
        func_8004261C(0);
    }

    func_80044B80(slot);
    do_wait();
}

static void vs_main_loadTitlePrg()
{
    vs_main_CdFile cdFile;
    vs_main_CdQueueSlot* temp_v0;

    cdFile.lba = VS_TITLE_PRG_LBA;
    cdFile.size = VS_TITLE_PRG_SIZE;

    temp_v0 = vs_main_getQueueSlot(&cdFile);
    vs_main_populateQueueSlot(temp_v0, vs_overlay_slots[0]);

    while (temp_v0->unk0[0] != 4) {
        func_8004261C(0);
    }

    func_80044B80(temp_v0);
    do_wait();
}

static void vs_main_loadEndingPrg()
{
    vs_main_CdFile cdFile;
    vs_main_CdQueueSlot* temp_v0;

    cdFile.lba = VS_ENDING_PRG_LBA;
    cdFile.size = VS_ENDING_PRG_SIZE;

    temp_v0 = vs_main_getQueueSlot(&cdFile);
    vs_main_populateQueueSlot(temp_v0, vs_overlay_slots[0]);

    while (temp_v0->unk0[0] != 4) {
        func_8004261C(0);
    }

    func_80044B80(temp_v0);
    do_wait();
}

static void vs_main_initScreen(int w, int h, int arg2 __attribute__((unused)),
    __attribute__((unused)) int arg3, __attribute__((unused)) int arg4,
    __attribute__((unused)) int arg5)
{
    SetDefDispEnv(vs_main_dispEnv, 0, 0, w, h - 0x10);
    setRECT(&vs_main_dispEnv[0].screen, 0, 8, 0x100, 0xE0);
    PutDispEnv(vs_main_dispEnv);
}

#define IMG_W(header) (header.wLo + (header.wHi << 8))
#define IMG_H(header) (header.hLo + (header.hHi << 8))

static void vs_main_displayLoadingScreen()
{
    RECT rect;

    vs_main_initScreen(0x140, 0xF0, D_8005E248, 0, 0, 0);
    setRECT(&rect, 0, 0, 1024, 512);
    ClearImage2(&rect, 0, 0, 0);
    DrawSync(0);
    VSync(2);
    setRECT(&rect, (320 - IMG_W(nowLoading_header)) / 2,
        (224 - IMG_H(nowLoading_header)) / 2, IMG_W(nowLoading_header),
        IMG_H(nowLoading_header));
    LoadImage(&rect, (u_long*)&nowLoading_header + 1);
    setRECT(&rect, ((320 - IMG_W(nowLoading_header)) / 2) + 320,
        (224 - IMG_H(nowLoading_header)) / 2, IMG_W(nowLoading_header),
        IMG_H(nowLoading_header));
    LoadImage(&rect, (u_long*)&nowLoading_header + 1);
    DrawSync(0);
    SetDispMask(1);
}

static void bufferLoadingScreen()
{
    RECT rect;

    if (frameBuf != 0) {
        setRECT(&rect, (320 - IMG_W(nowLoading_header)) / 2,
            (224 - IMG_H(nowLoading_header)) / 2, IMG_W(nowLoading_header),
            IMG_H(nowLoading_header));
    } else {
        setRECT(&rect, (320 - IMG_W(nowLoading_header)) / 2 + 320,
            (224 - IMG_H(nowLoading_header)) / 2, IMG_W(nowLoading_header),
            IMG_H(nowLoading_header));
    }
    LoadImage(&rect, nowLoading_data);
    DrawSync(0);
}

static void resetGame()
{
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    while (DsControlB(DslPause, NULL, NULL) == 0)
        ;
    DsFlush();
    padSetActData(0, 0, 0);
    padSetActData(0, 1, 0);
    padConnect(0, padBuffer[0]);
    padConnect(0x10, padBuffer[1]);
    vs_sound_Shutdown();
    SpuQuit();
    ResetGraph(3);
    VSync(0xA);
    jumpToTitle(&sp2);
}

static void func_80042420()
{
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    padSetActData(0, 0, 0);
    padSetActData(0, 1, 0);
    padConnect(0, padBuffer[0]);
    padConnect(0x10, padBuffer[1]);
    ResetGraph(3);
    func_80012B78();
    func_80012B98();
    func_80012024();
    func_80012EBC();
    vs_main_displayLoadingScreen();
    vs_main_loadBattlePrg();
    D_80050470 = 1;
    jumpToBattle(&sp);
}

static void func_800424E4()
{
    D_8005E240 = 0;
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    padSetActData(0, 0, 0);
    padSetActData(0, 1, 0);
    padConnect(0, padBuffer);
    padConnect(0x10, padBuffer[1]);
    ResetGraph(3);
    func_80012B78();
    func_80012B98();
    func_80042CB0();
    vs_main_loadEndingPrg();
    func_8006A5C0();
    DrawSync(0);
    DrawSync(0);
    SetDispMask(0);
    padSetActData(0, 0, 0);
    padSetActData(0, 1, 0);
    padConnect(0, padBuffer);
    padConnect(0x10, padBuffer[1]);
    vs_sound_Shutdown();
    SpuQuit();
    ResetGraph(3);
    D_8005E214 = 1;
    jumpToTitle(&sp2);
}

int func_8004261C(int arg0)
{
    int vs = VSync(arg0);
    if (arg0 != 1) {
        func_8004908C();
    }

    func_80044C74();

    if (D_80061074[3] >= 100) {
        return vs;
    }

    D_80061074[0] += D_8005E24C;

    if (D_80061074[0] < 60) {
        return vs;
    }

    D_80061074[0] = 0;

    if (++D_80061074[1] < 60) {
        return vs;
    }

    D_80061074[1] = 0;

    if (++D_80061074[2] < 60) {
        return vs;
    }

    D_80061074[2] = 0;

    if (++D_80061074[3] >= 100) {
        D_80061074[3] = 100;
    }
    return vs;
}

static void gpuSyncVoidCallback() { }

static void vSyncVoidCallback() { }

static void nop0() { }

static void nop1() { }

static void nop2() { }

static void nop3() { }

static void initRand()
{
    int i;

    srand(1);

    for (i = 0; i < RANDARRSZ; ++i) {
        randArr[i] = rand();
    }
    randIndex = RANDARRSZ - 1;
}

static int getRand(int arg0)
{
    int temp_s0;
    int var_a0;
    int var_v0;

    var_v0 = randArr[randIndex] * RANDARRSZ;

    if (var_v0 < 0) {
        var_v0 += 0x7FFF;
    }

    randIndex = var_v0 >> 0xF;

    temp_s0 = 0x7FFF - randArr[randIndex];
    randArr[randIndex] = rand();

    var_a0 = temp_s0 * arg0;

    if (var_a0 < 0) {
        var_a0 += 0x7FFF;
    }

    return var_a0 >> 0xF;
}

static int getRands(int arg0)
{
    return (getRand(arg0) + getRand(arg0) + getRand(arg0) + getRand(arg0) + getRand(arg0)
               + getRand(arg0) + getRand(arg0) + getRand(arg0) + getRand(arg0)
               + getRand(arg0) + getRand(arg0) + getRand(arg0))
        / 12;
}

static void func_80042998()
{
    SetVideoMode(MODE_NTSC);
    SetDispMask(0);
    ResetCallback();
    ResetGraph(0);
    SetGraphDebug(0);
    InitCARD(0);
    StartCARD();
    _bu_init();
    PadInitDirect(padBuffer[0], padBuffer[1]);
    padResetDefaults(0, padBuffer[0]);
    padResetDefaults(0x10, padBuffer[1]);
    PadStartCom();
    padForceMode();
    func_80043668();
    SsUtReverbOff();
    DsInit();
    initRand();
    D_80055C88 = 1;
    D_8005E214 = 0;
}

static void func_80042A64()
{
    RECT rects[3];
    int i;

    rects[1] = (RECT) { 819, 819, 819, 0 };
    rects[2] = (RECT) { 0, 0, 1024, 512 };
    ResetCallback();
    ResetGraph(1);
    SetGraphDebug(0);
    ClearImage(&rects[2], 0, 0, 0);
    DrawSync(0);
    vs_main_displayLoadingScreen();
    SsUtReverbOn();
    InitGeom();
    DrawSyncCallback(gpuSyncVoidCallback);
    VSyncCallback(vSyncVoidCallback);
    initHeap((HeapHeader*)0x8010C000, 0xF2000U);
    vs_main_initCdQueue();
    func_80044A60();
    func_800468FC();
    func_80043668();
    D_8005E240 = 0;
    padForceMode();

    for (i = 31; i >= 0; --i) {
        D_80055C90[i] = 0;
    }
    D_80061074[3] = 0;
    D_80061074[2] = 0;
    D_80061074[1] = 0;
    D_80061074[0] = 0;
    D_80060068.unk0 = 0;
}

int execTitle()
{
    getSp(&sp);
    func_80042A64();
    vs_main_loadTitlePrg();
    D_80050470 = titlePrgMain();
    D_8005E214 = 0;
    vs_main_displayLoadingScreen();
    vs_main_loadBattlePrg();
    getSp(&sp);
    D_8005E240 = 1;
    execBattle();
    SetDispMask(0);
    func_800455F4();
    return 0;
}

void main_()
{
    __main();
    func_80042998();
    getSp(&sp2);
    execTitle();
}

static void do_wait() { wait(); }

void func_80042C94(int arg0) { D_80055C88 = arg0; }

void func_80042CA0() { D_80060068.unk0 = 1; }

void func_80069FC4(int, int);
void func_8008AB68();
void func_800A1108(int, unsigned char*);

void func_80042CB0()
{
    unsigned char sp10[16];
    int var_a1;
    int var_a3;
    int var_s1;
    int new_var;
    unsigned char var_a0;
    D_800F19FC_t2* temp_t0;
    D_80060068_t* temp_t5;
    int v0;
    int v0_2;
    int v1;
    int v1_2;

    D_80061068 = D_800F1AB0;
    func_800A1108(0, sp10);

    v0 = (sp10[0] & 0x1F) << 8;
    v1 = (sp10[2] & 0x1F) << 0xA;
    D_80061068.unk0[2] = (D_80061068.unk0[2] & 0xE0FF) | v0;
    D_80061068.unk0[3] = (D_80061068.unk0[3] & 0x83FF) | v1;
    v1_2 = sp10[1] << 0xD;
    v0_2 = (sp10[3] >> 6) << 0xD;
    D_80061068.unk0[1] = ((D_80061068.unk0[1] & 0x1FFF) | v1_2);
    new_var = D_800F18E8 & 0x3FF;
    D_80061068.unk0[2] = ((D_80061068.unk0[2] & 0x9FFF) | v0_2);
    D_80061068.unk0[3] = ((D_80061068.unk0[3] & 0xFC00) | new_var);
    for (var_s1 = 0; var_s1 < 32; ++var_s1) {
        var_a0 = 0;
        for (var_a3 = 0; var_a3 < 8; ++var_a3) {
            unsigned int* p = (D_8004B9DC + (((var_s1 * 8) + var_a3) * 13));
            var_a0 = (*(int*)&var_a0 * 2) | ((p[3] >> 0xF) & 1);
        }
        D_8005FFB8[var_s1] = var_a0;
    }
    temp_t0 = D_800F19FC->unk38;
    temp_t5 = &D_80060068;
    temp_t5->unk4[0] = temp_t0->unk0[12];
    temp_t5->unk4[1] = temp_t0->unk0[13];
    temp_t5->unk4[2] = temp_t0->unk0[14];
    temp_t5->unk4[3] = temp_t0->unk0[15];
    temp_t5->unk4[4] = temp_t0->unk0[17];
    temp_t5->unk4[5] = temp_t0->unk0[18];
    temp_t5->unk4[6] = temp_t0->unk0[19];
    temp_t5->unk4[7] = temp_t0->unk0[20];
    temp_t5->unk4[8] = temp_t0->unk0[21];
    temp_t5->unk4[9] = temp_t0->unk0[22];
    temp_t5->unk4[10] = temp_t0->unk0[16];
    temp_t5->unk4[11] = temp_t0->unk954;
    temp_t5->unk1C = temp_t0->unk948;

    for (var_a3 = 0; var_a3 < 8; ++var_a3) {
        temp_t5->unk20[var_a3] = temp_t0->unk94C[var_a3];
    }

    for (var_a3 = 0; var_a3 < 6; ++var_a3) {
        temp_t5->unk28[var_a3].unk0 = temp_t0->unk398[var_a3].unk0;
        temp_t5->unk28[var_a3].unk2 = temp_t0->unk398[var_a3].unk2;

        for (var_a1 = 0; var_a1 < 4; ++var_a1) {
            temp_t5->unk28[var_a3].unk4[var_a1] = temp_t0->unk398[var_a3].unk8[var_a1];
        }

        for (var_a1 = 0; var_a1 < 8; ++var_a1) {
            temp_t5->unk28[var_a3].unkC[var_a1] = temp_t0->unk398[var_a3].unk10[var_a1];
        }
    }

    temp_t5->unk7C[0] = D_800F19FC->unk0[8];
    temp_t5->unk7C[1] = D_800F19D0[5];
    temp_t5->unk7C[2] = D_800F19D0[8];

    for (var_s1 = 0; var_s1 < 16; ++var_s1) {
        func_80069FC4(var_s1, 0);
    }
    func_8008AB68();
}

static void padDisconnectAll()
{
    portInfo[0].connected = 0;
    portInfo[1].connected = 0;
}

static void padForceMode()
{
    padDisconnectAll();
    if (PadInfoMode(0, InfoModeCurExID, 0) != 0) {
        PadSetMainMode(0, 1, 2);
    }
}

static void padResetDefaults(int port, void* arg1 __attribute__((unused)))
{
    PortInfo* info;

    info = &portInfo[port >> 4];
    info->exId = PadInfoMode(port, InfoModeCurExID, 0);

    if (info->exId & 0xFF) {
        info->actData[0] = 0;
        info->actData[1] = 0;
        info->lock = 2;
        PadSetMainMode(port, PadInfoMode(port, InfoModeCurExOffs, 0), info->lock);
    } else {
        info->actData[0] = 0x40;
        info->actData[1] = 0;
    }
    PadSetAct(port, info->actData, 2);
    PadSetActAlign(port, actParams);
}

int func_800430F4(int arg0, unsigned char padBuf[34])
{
    PortInfo* temp_s0;
    unsigned char temp_v0;
    int var_s1;

    if (padBuf[0] != 0) {
        temp_s0 = &portInfo[arg0 >> 4];
        temp_s0->unk6 = -128;
        temp_s0->unk5 = -128;
        temp_s0->unk4 = -128;
        temp_s0->unk3 = -128;
        return 0;
    }
    temp_s0 = &portInfo[arg0 >> 4];
    temp_v0 = PadInfoMode(arg0, 1, 0);
    temp_s0->unk0 = temp_v0;
    switch (temp_v0) {
    case 1:
    case 2:
    case 3:
    case 6:
        var_s1 = 0;
        break;
    default:
        var_s1 = ~((padBuf[2] << 8) | padBuf[3]);
        break;
    }

    temp_s0->unk0 = PadInfoMode(arg0, 1, 0);
    if ((temp_s0->unk0 == 5) || (temp_s0->unk0 == 7)) {
        temp_s0->unk3 = padBuf[6];
        temp_s0->unk4 = padBuf[7];
        temp_s0->unk5 = padBuf[4];
        temp_s0->unk6 = padBuf[5];
    } else {
        temp_s0->unk6 = -128;
        temp_s0->unk5 = -128;
        temp_s0->unk4 = -128;
        temp_s0->unk3 = -128;
    }
    temp_s0->unk2 = var_s1;
    return var_s1;
}

static void padConnect(int port, void* arg1)
{
    int dummy[5] __attribute__((unused));
    int state;
    PortInfo* info;

    info = &portInfo[port >> 4];
    state = PadGetState(port);

    if (state == PadStateFindPad) {
        info->connected = 0;
    }
    if (info->connected == 0) {
        PadSetAct(port, info->actData, 2);
        if ((state == PadStateFindCTP1)
            || ((state == PadStateStable) && (PadSetActAlign(port, actParams) != 0))) {
            padResetDefaults(port, arg1);
            info->connected = 1;
        }
    }
}

static void padSetActData(int port, int pos, int val)
{
    if (pos != 0) {
        portInfo[port].actData[pos] = val;
    } else if (portInfo[port].exId != 0) {
        portInfo[port].actData[0] = val;
    } else {
        portInfo[port].actData[0] = 0x40;
    }
}

static unsigned char padGetActData(int port, int pos)
{
    return portInfo[port].actData[pos];
}

static int func_800433B4(unsigned char* arg0, unsigned int arg1, short arg2)
{
    int i;
    int ret = 0;

    if (arg1 == 0xFF) {
        for (i = 0; i < 2; ++i) {
            if (D_80050118[i].unk8 == 0) {
                ret = i + 1;
                break;
            }
        }
    } else if ((arg1 - 1) < 2) {
        ret = arg1;
    }

    if (ret != 0) {
        i = ret - 1;
        D_80050118[i].unkC = arg0;
        D_80050118[i].unk10[4] = 1;
        D_80050118[i].unk10[10] = *arg0;
        D_80050118[i].unk10[11] = 0;
        D_80050118[i].unk10[5] = 0;
        D_80050118[i].unk10[7] = 0;
        D_80050118[i].unk10[1] = 0;
        D_80050118[i].unk8 = 1;
        D_80050118[i].unkA = arg2;
        return ret;
    }
    return 0;
}

static int func_80043470(int arg0)
{
    int i = arg0 - 1;
    D_80050118[i].unk10[7] = 0;
    D_80050118[i].unk10[1] = 0;
    D_80050118[i].unkC = 0;
    D_80050118[i].unk8 = 0;

    return arg0;
}

static int func_800434A4(int arg0, int arg1)
{
    int i;

    if ((arg0 - 1u) < 2) {
        return func_80043470(arg0);
    }
    if (arg0 == 0) {
        i = 0;
        if (arg1 != 0) {
            for (; i < 2; ++i) {
                if (D_80050118[i].unkA == arg1) {
                    func_80043470(i + 1);
                }
            }
            return 1;
        }
        do {
            ++i;
            func_80043470(i);
        } while (i < 2);
        return 1;
    }
    return 0;
}

static int func_80043554(int arg0)
{
    int v0 = arg0 - 1;
    D_80050118[v0].unk8 = 0;
    return arg0;
}

static int func_8004357C(int arg0)
{
    int i;

    if ((arg0 - 1u) < 2) {
        return func_80043554(arg0);
    }

    if (arg0 == 0) {
        for (i = 0; i < 2;) {
            func_80043554(++i);
        }
        return 1;
    }
    return 0;
}

static int func_800435DC(int arg0)
{
    int v0 = arg0 - 1;
    D_80050118[v0].unk8 = 1;
    return arg0;
}

static int func_80043608(int arg0)
{
    int i;

    if ((arg0 - 1u) < 2) {
        return func_800435DC(arg0);
    }

    if (arg0 == 0) {
        for (i = 0; i < 2;) {
            func_800435DC(++i);
        }
        return 1;
    }
    return 0;
}

static void func_80043668()
{
    int i;

    padDisconnectAll();

    for (i = 0; i < 2; ++i) {
        D_80050118[i].unkC = 0;
        D_80050118[i].unk10[7] = 0;
        D_80050118[i].unk10[1] = 0;
        D_80050118[i].unk8 = 0;
    }
}

void func_800436B4()
{
    int temp_a0;
    int var_a2_2;
    int i;
    int j;
    int var_v0;
    unsigned char* temp_t1;
    int new_var;

    D_80050118[0].unk0[1] = 0;
    D_80050118[0].unk0[0] = 0;

    for (j = 0; j < 2; ++j) {
        if (D_80050118[j].unk8 == 0) {
            continue;
        }

        temp_t1 = D_80050118[j].unkC;

        if (temp_t1 != 0) {
            for (i = 0; i < 2; ++i) {
                int(*a1)[6] = (int(*)[6])D_80050118[j].unk10;
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

                D_80050118[0].unk0[i] += a1[i][1];
                if (D_80050118[0].unk0[i] > 0xFF00) {
                    D_80050118[0].unk0[i] = 0xFF00;
                } else if (D_80050118[0].unk0[i] < 0) {
                    D_80050118[0].unk0[i] = 0;
                }
            }
            D_80050118[j].unk8 = D_80050118[j].unk10[0] | D_80050118[j].unk10[6];
            if (D_80050118[j].unk8 == 0) {
                D_80050118[j].unkC = 0;
            }
        } else {
            D_80050118[j].unk8 = 0;
        }
    }

    if (D_8006002B != 0) {
        var_a2_2 = D_80050118[0].unk0[0];
        if (var_a2_2 < 0) {
            var_a2_2 += 0xFF;
        }
        padSetActData(0, 0, (var_a2_2 >> 8));
        var_v0 = D_80050118[0].unk0[1];
        if (var_v0 < 0) {
            var_v0 += 0xFF;
        }
        padSetActData(0, 1, (var_v0 >> 8));
    }
}

static void func_800438C8(int arg0)
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

extern int D_80055C78;
extern int D_8005DFC0[];
extern int D_8005DFDC;
extern unsigned int D_8005E1C0;
extern int D_8005E1D0;
extern unsigned int D_8005E238;
extern unsigned char D_80060020[];

int func_80043940()
{
    int dummy[2];
    int i;
    unsigned int a3;

    D_8005E238 = func_800430F4(0, padBuffer[0]) & 0xFFFF;
    D_8005E238 |= func_800430F4(16, padBuffer[1]) << 16;
    padConnect(0, padBuffer);
    padConnect(16, padBuffer[1]);

    if (portInfo->unk0 != 4) {
        if (portInfo->unk0 == 7) {
            D_8005DFC0[2] = portInfo->unk3;
            D_8005DFC0[3] = portInfo->unk4;
            D_8005DFC0[0] = portInfo->unk5;
            D_8005DFC0[1] = portInfo->unk6;

            if (portInfo->unk3 < 16) {
                D_8005E238 |= 0x8000;
            }
            if (portInfo->unk3 >= 241) {
                D_8005E238 |= 0x2000;
            }

            if (portInfo->unk4 < 16) {
                D_8005E238 |= 0x1000;
            }
            if (portInfo->unk4 >= 241) {
                D_8005E238 |= 0x4000;
            }

            if (portInfo->unk5 < 32) {
                D_8005E238 |= 0x400;
            }
            if (portInfo->unk5 >= 225) {
                D_8005E238 |= 0x400;
            }

            if (portInfo->unk6 < 32) {
                D_8005E238 |= 0x400;
            }
            if (portInfo->unk6 >= 225) {
                D_8005E238 |= 0x400;
            }
        } else {
            D_8005DFC0[1] = 0x80;
            D_8005DFC0[0] = 0x80;
            D_8005DFC0[3] = 0x80;
            D_8005DFC0[2] = 0x80;
        }
    } else {
        D_8005DFC0[1] = 0x80;
        D_8005DFC0[0] = 0x80;
        D_8005DFC0[3] = 0x80;
        D_8005DFC0[2] = 0x80;
    }

    D_8005E1D0 = ~D_8005E1C0 & D_8005E238;
    D_80055C78 = D_8005E1C0 & ~D_8005E238;
    D_8005E1C0 = D_8005E238;

    a3 = D_8005E238;
    for (i = 0; i < 32; ++i, a3 >>= 1) {
        if (a3 & 1) {
            D_80055C90[i] += D_8005E24C;
        } else {
            D_80055C90[i] = 0;
        }
    }

    D_8005DFDC = D_8005E1D0;

    for (i = 0; i < 32; ++i) {
        if ((D_80055C90[i] >= 20) && !((D_80055C90[i] - 20) & 3)) {
            D_8005DFDC |= 1 << i;
        }
    }

    if ((D_80055C88 != 0) && ((D_8005E1C0 & 0x90F) == 0x90F) && (D_8005E1D0 & 0x90F)) {
        D_80060020[10] = 0;
        D_80060020[11] = 1;
        resetGame();
    }

    return 1;
}

static void freeHeapR(void* block)
{
    HeapHeader* var_a1 = heapA.prev;
    HeapHeader* target = (HeapHeader*)block - 1;

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

void freeHeap(void* block)
{
    HeapHeader* var_a1 = heapA.next;
    HeapHeader* target = (HeapHeader*)block - 1;

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

static unsigned long* allocHeapR(unsigned int size)
{
    HeapHeader* var_a1;
    HeapHeader* var_a2;
    unsigned int blockSz;

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
            return (unsigned long*)(var_a1 + 1);
        }
        var_a2 = var_a1;
        if (var_a1 == &heapA) {
            return 0;
        }
        var_a1 = var_a1->prev;
    }
}

unsigned long* allocHeap(unsigned int size)
{
    unsigned int blockSz;
    HeapHeader* var_a1;
    HeapHeader* var_v1;

    var_v1 = &heapA;
    var_a1 = heapA.next;
    blockSz = ((size + 0xF) >> 4) + 1;

    while (1) {
        if (var_a1->blockSz >= blockSz) {
            if (var_a1->blockSz == blockSz) {
                var_v1->next = var_a1->next;
                var_a1->next->prev = var_a1->prev;
            } else {
                HeapHeader* temp_v1 = var_a1 + blockSz;
                temp_v1->blockSz = var_a1->blockSz - blockSz;
                temp_v1->prev = var_a1->prev;
                temp_v1->next = var_a1->next;
                temp_v1->prev->next = temp_v1;
                temp_v1->next->prev = temp_v1;
                var_a1->blockSz = blockSz;
            }
            return (unsigned long*)(var_a1 + 1);
        }
        var_v1 = var_a1;
        if (var_a1 == &heapA) {
            return 0;
        }
        var_a1 = var_a1->next;
    }
}

static void initHeap(HeapHeader* node, unsigned int value)
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

void diskReadCallback(unsigned char intr, unsigned char* result __attribute__((unused)),
    unsigned long* arg2 __attribute__((unused)))
{

    if ((intr == DslDiskError) || (intr == DslNoIntr) || (D_80055D10.status == 4)) {
        DsReadyCallback(0);
        DsEndReadySystem();
        D_80055D10.status = 4;
        return;
    }

    if (intr != DslDataReady) {
        return;
    }

    D_80055D10.status = 2;

    if (D_80055D10.unk2C == 0) {
        DsGetSector((unsigned char*)D_80055D10.vram + D_80055D10.bufIndex * 2048, 512);
    } else {
        DsGetSector(D_80050110 + D_80055D10.unk3C * 128, 512);
        if (++D_80055D10.unk3C >= 16) {
            D_80055D10.unk3C = 0;
        }
    }

    switch (D_80055D10.unk2C) {
    case 0:
        if (++D_80055D10.bufIndex >= D_80055D10.unk8) {
            D_80055D10.status = 0;
        }
        break;
    case 1:
        ++D_80055D10.unk38;
        ++D_80055D10.unk34;
        break;
    case 2:
        ++D_80055D10.unk38;
        if (++D_80055D10.unk40 >= 16) {
            D_80055D10.unk40 = 0;
        }
        break;
    default:
        break;
    }

    if (++D_80055D10.unk4 >= D_80055D10.unk8) {
        DsEndReadySystem();
    }
}

static void cdReadCb(unsigned char arg0, unsigned char* arg1 __attribute__((unused)))
{
    switch (arg0) {
    case 2:
        DsStartReadySystem(diskReadCallback, -1);
        return;
    case 5:
        break;
    default:
        break;
    case 6:
    case 0:
        return;
    }
    D_80055D10.status = 4;
}

static void cdSeekCb(unsigned char arg0, unsigned char* arg1 __attribute__((unused)))
{
    switch (arg0) {
    case 0:
        break;
    case 2:
        D_80055D10.status = 0;
        break;
    case 5:
        D_80055D10.status = 4;
        break;
    case 6:
        break;
    default:
        D_80055D10.status = 4;
        break;
    }
}

static void pcmReadReady(unsigned char intr, unsigned char arg1[])
{
    switch (intr) {
    case DslComplete:
        DsReadyCallback(NULL);
        D_80055D10.status = 0;
        break;
    case DslDataReady:
        if (!(arg1[4] & 0x80)) {
            D_800501CC = ((arg1[1] >> 4) * 0xA) + (arg1[1] & 0xF);
            D_800501D0 = arg1[3];
            D_800501D4 = arg1[4];
            D_800501D8 = (arg1[6] << 8) | arg1[7];
        }
        break;
    case DslDiskError:
        DsReadyCallback(NULL);
        D_80055D10.status = 8;
        break;
    }
}

static int getCdStatus() { return D_80055D10.status; }

static void func_80044320()
{
    if (D_80055D10.status == 4) {
        D_80055D10.status = 0;
    }
}

static int func_80044340(int sector, unsigned int bytes, void* vram)
{
    if (D_80055D10.status == 0) {
        D_80055D10.cdSector = sector;
        D_80055D10.sectorCount = bytes;
        D_80055D10.vram = vram;
        D_80055D10.unk40 = 0;
        D_80055D10.unk3C = 0;
        D_80055D10.bufIndex = 0;
        D_80055D10.unk34 = 0;
        D_80055D10.unk4 = 0;
        D_80055D10.unk3 = 0;
        D_80055D10.unk38 = 0;
        D_80055D10.unk8 = bytes >> 11;
        if (bytes & 0x7FF) {
            ++D_80055D10.unk8;
        }
        DsIntToPos(sector, &D_80055D10.cdLoc);
        D_80055D10.status = 5;
        return 1;
    }
    return 0;
}

static void func_800443CC()
{
    DslATV vol;
    int i;
    unsigned int seconds;

    switch (D_80055D10.status) {
    case 0:
    default:
        break;
    case 6:
        if (DsSystemStatus() == DslReady) {
            D_80055D10.unk1 = 0;
            D_80055D10.cdLoc.minute = 0;
            while (DsControlB(DslSetmode, dsControlBuf, NULL) == 0)
                ;
            VSync(3);
            vol.val2 = 0x80;
            vol.val0 = 0x80;
            vol.val3 = 0;
            vol.val1 = 0;
            DsMix(&vol);
            func_80012918(D_80055D10.sectorCount);
            func_80013230(0x7F);
            D_80055D10.pcm.file = 1;
            D_80055D10.pcm.chan = 0;
            DsControl(DslSetfilter, (unsigned char*)&D_80055D10.pcm, NULL);
            DsIntToPos(D_80055D10.cdSector, &D_80055D10.cdLoc);
            D_80055D10.commandId
                = DsPacket(DslModeRT | DslModeSF, &D_80055D10.cdLoc, DslReadS, NULL, -1);
            DsReadyCallback(pcmReadReady);
            D_80055D10.status = 7;
        }
        if (D_80055D10.commandId == 0) {
            DsReadyCallback(0);
            D_80055D10.status = 8;
            ++D_80055D10.unk3;
        }
        break;
    case 5: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            D_80055D10.unk4 = 0;
            D_80055D10.bufIndex = 0;
            if (D_80055D10.sectorCount != 0) {
                D_80055D10.status = 2;
                D_80055D10.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &D_80055D10.cdLoc, DslReadN, cdReadCb, -1);
            } else {
                D_80055D10.status = 1;
                D_80055D10.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &D_80055D10.cdLoc, DslSeekL, cdSeekCb, -1);
            }

            if (D_80055D10.commandId == 0) {
                D_80055D10.status = 4;
                ++D_80055D10.unk3;
            }
        }
        break;
    }
    case 8: {
        int status = DsSystemStatus();
        if (status == DslReady) {
            D_80055D10.unk4 = 0;
            ++D_80055D10.unk3;
            seconds = frameDuration / 60;
            if (seconds < 420) {
                DsIntToPos(D_80055D10.cdSector + (seconds * 75) + (frameDuration % 60),
                    &cdReadLoc);
                vol.val2 = 0x80;
                vol.val0 = 0x80;
                vol.val3 = 0;
                vol.val1 = 0;
                DsMix(&vol);
                func_80012918(0);
                func_80012940(0x3C, D_80055D10.sectorCount);
                D_80055D10.pcm.file = 1;
                D_80055D10.pcm.chan = 0;
                DsControl(DslSetfilter, (unsigned char*)&D_80055D10.pcm, NULL);
                D_80055D10.commandId
                    = DsPacket(DslModeRT | DslModeSF, &cdReadLoc, DslReadS, NULL, -1);
                DsReadyCallback(pcmReadReady);
                D_80055D10.status = 7;
            } else {
                D_80055D10.commandId = DsCommand(DslModeSF | DslModeDA, NULL, NULL, -1);
                D_80055D10.status = 0;
                DsReadyCallback(0);
            }
        }
        if (D_80055D10.commandId == 0) {
            D_80055D10.status = 8;
            ++D_80055D10.unk3;
        }
        break;
    }
    case 4: {
        int status = DsSystemStatus();
        if (status == 1) {
            D_80055D10.unk4 = 0;
            D_80055D10.bufIndex = 0;
            ++D_80055D10.unk3;

            if (D_80055D10.sectorCount != 0) {
                D_80055D10.status = 2;
                D_80055D10.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &D_80055D10.cdLoc, DslReadN, cdReadCb, -1);
            } else {
                D_80055D10.status = 1;
                D_80055D10.commandId = DsPacket(DslModeSpeed | DslModeSize1,
                    &D_80055D10.cdLoc, DslSeekL, cdSeekCb, -1);
            }

            if (D_80055D10.commandId == 0) {
                D_80055D10.status = 4;
                ++D_80055D10.unk3;
            }
        }
        break;
    }
    case 9:
        func_80012918(0);
        D_80055D10.commandId = DsCommand(DslPause, NULL, NULL, -1);
        if (D_80055D10.commandId > 0) {
            D_80055D10.status = 0;
        }
        DsReadyCallback(NULL);
        D_80055D10.unk1 = 0x80;
        D_80055D10.cdLoc.minute = 0x80;
        while (DsControlB(DslSetmode, dsControlBuf, NULL) == 0)
            ;
        VSync(3);
        break;
    }

    if (D_80055D10.unk2C != 0) {
        for (i = 0; i < 16; ++i) {
            if (D_80055D10.bufIndex >= D_80055D10.unk38) {
                return;
            }
            if (D_80055D10.unk2C == 1) {
                memcpy_impl(
                    ((unsigned char*)D_80055D10.vram + (D_80055D10.bufIndex * 2048)),
                    D_80050110 + (D_80055D10.unk40 * 128), 2048);

                ++D_80055D10.unk40;
                if (D_80055D10.unk40 >= 0x10) {
                    D_80055D10.unk40 = 0;
                }
                --D_80055D10.unk34;
                ++D_80055D10.bufIndex;
                if (D_80055D10.bufIndex >= D_80055D10.unk8) {
                    D_80055D10.status = 0;
                    freeHeapR(D_80050110);
                    D_80050110 = 0;
                }
            } else if (D_80055D10.unk2C == 2) {
                ++D_80055D10.bufIndex;
                if ((D_80055D10.bufIndex >= D_80055D10.unk8) && (func_80012C04() == 0)) {
                    D_80055D10.status = 0;
                    freeHeapR((HeapHeader*)D_80050110);
                    D_80050110 = 0;
                }
            }
        }
    }
}

static int func_8004493C(int arg0, int arg1, void* vram)
{
    int temp_v0;

    temp_v0 = func_80044340(arg0, arg1, vram);
    if (temp_v0 != 0) {
        int s4 = 1;
        int s3 = 2;

        while (1) {
            if (getCdStatus() == s4) {
                func_8004261C(0);
            } else if (getCdStatus() == s3) {
                func_8004261C(0);
            } else if (getCdStatus() == 3) {
                func_8004261C(0);
            } else if (getCdStatus() == 5) {
                func_8004261C(0);
            } else
                break;
        }
    }
    return temp_v0;
}

static int func_800449E8(int sector, int sectorCount)
{
    if (D_80055D10.status == 0) {
        D_80055D10.cdSector = sector;
        D_80055D10.sectorCount = sectorCount;
        D_80055D10.unk40 = 0;
        D_80055D10.unk3C = 0;
        D_80055D10.bufIndex = 0;
        D_80055D10.unk34 = 0;
        D_80055D10.unk4 = 0;
        D_80055D10.unk3 = 0;
        D_80055D10.unk38 = 0;
        D_80055D10.status = 6;
        return 1;
    }
    return 0;
}

static int func_80044A38()
{
    if (D_80055D10.status == 7) {
        D_80055D10.status = 9;
        return 1;
    }
    return 0;
}

static void func_80044A60()
{
    while (DsControlB(DslPause, NULL, NULL) == 0)
        ;
    DsFlush();
    D_80055D10.unk1 = 0x80;
    D_80055D10.cdLoc.minute = 0x80;
    D_80055D10.unk2 = 0;
    D_80055D10.status = 0;
    D_80055D10.unk2C = 0;
    D_80050110 = 0;
    while (DsControlB(DslSetmode, dsControlBuf, NULL) == 0)
        ;
    VSync(3);
}

static void vs_main_initCdQueue()
{
    int i;

    for (i = 0x1F; i >= 0; --i) {
        vs_main_cdQueue[i].unk0[0] = 0;
    }
    D_80050460.i = 0;
}

vs_main_CdQueueSlot* vs_main_getQueueSlot(vs_main_CdFile* arg0)
{
    int i;

    for (i = 0; i < 32; ++i) {
        if (vs_main_cdQueue[i].unk0[0] == 0) {
            vs_main_cdQueue[i].unk0[0] = 1;
            vs_main_cdQueue[i].cdFile = *arg0;
            return &vs_main_cdQueue[i];
        }
    }
    nop9(0xA2, 0);
}

void func_80044B80(vs_main_CdQueueSlot* arg0)
{
    if ((unsigned short)arg0->unk0[0] - 2u < 2) {
        nop9(0xA3, 0);
    }
    arg0->unk0[0] = 0;
}

void func_80044BC4(vs_main_CdQueueSlot* arg0, void* arg1)
{
    unsigned short temp_a1;

    arg0->unk0[0] = 3;
    arg0->vram = arg1;
    arg0->unkC = 0;
    temp_a1 = D_80050460.s[1];
    D_80050460.s[1] = (temp_a1 + 1);
    arg0->unk0[1] = temp_a1;
}

static void vs_main_populateQueueSlot(vs_main_CdQueueSlot* arg0, void* arg1)
{
    vs_main_CdQueueSlot* var_v1;
    int i;

    var_v1 = vs_main_cdQueue;

    for (i = 0; i < 32; ++i, ++var_v1) {
        if (var_v1->unk0[0] == 3) {
            ++var_v1->unk0[1];
        }
    }
    arg0->unk0[0] = 3;
    arg0->vram = arg1;
    arg0->unkC = 0;
    arg0->unk0[1] = 0;
    ++D_80050460.s[1];
}

static void nop4() { }

static void func_80044C74()
{
    int i;

    D_80055D10.unk44 += 1;

    if (D_80050460.i != 0) {
        vs_main_CdQueueSlot* slot = vs_main_cdQueue;
        i = getCdStatus();
        if (i == 0) {
            for (; i < 32; ++i, ++slot) {
                if (slot->unk0[0] == 3) {
                    if (slot->unk0[1] == 0) {
                        slot->unk0[0] = 2;
                        func_80044340(slot->cdFile.lba, slot->cdFile.size, slot->vram);
                        D_80055D10.unk44 = 0;
                        --D_80050460.s[1];
                        ++D_80050460.s[0];
                    } else {
                        --slot->unk0[1];
                    }
                } else if (slot->unk0[0] == 2) {
                    slot->unk0[0] = 4;
                    --D_80050460.s[0];
                }
            }
        }
    }
    func_800443CC();
}

static int func_80044D94() { return func_80011F90(); }

static void func_80044DB4() { func_80012004(); }

static void func_80044DD4() { func_80012468(); }

static int func_80044DF4(int arg0)
{
    unsigned int new_var;
    int var_a1;

    if (arg0 != 0) {
        if (D_8005E038.unk14[arg0 - 1] != 0xFFFF) {
            func_80011FDC(D_8005E038.unk14[arg0 - 1]);
            D_8005E038.unk14[arg0 - 1] = 0xFFFF;
        }
        if (D_8005E038.offset == arg0) {
            D_8005E038.offset = 0;
            D_8005E038.unkC_u.unkC_i = 0;
            D_8005E038.unk4 = 0xFFFF;
        }
        return 1;
    }
    func_80012B78();
    D_8005E038.offset = 0;
    D_8005E038.unkC_u.unkC_i = 0;
    D_8005E038.unk4 = 0xFFFF;

    new_var = 0xFFFF;
    for (var_a1 = 3; var_a1 >= 0; --var_a1) {
        D_8005E038.unk14[var_a1] = new_var;
    }
    return 1;
}

static int func_80044EC8(int arg0)
{
    unsigned int temp_v0;

    if (arg0 != 0) {
        if (D_8005E038.unk24[arg0 - 1] != 0) {
            D_8005E038.offset = arg0;
            temp_v0 = func_800120E8(
                D_8005E038.unkC_u.unkC_i = (unsigned int)D_8005E038.unk24[arg0 - 1]);
            if (temp_v0 != 0) {
                D_8005E038.unk14[arg0 - 1] = temp_v0;
                D_8005E038.unk4 = temp_v0;
            }
            D_8005E038.unk8 = D_8005E038.unk10[arg0 - 1];
        }
        return D_8005E03C;
    }
    return 0;
}

static int func_80044F60(int arg0, int arg1, unsigned int arg2)
{
    unsigned int temp_v0;

    if (arg0 != 0) {
        if (D_8005E038.unk24[arg0 - 1] != 0) {
            D_8005E038.offset = arg0;
            D_8005E038.unkC_u.unkC_i = (unsigned int)D_8005E038.unk24[arg0 - 1];
            temp_v0 = func_80012080(D_8005E038.unkC_u.unkC_i, arg2, arg1);
            if (temp_v0 != 0) {
                D_8005E038.unk14[arg0 - 1] = temp_v0;
                D_8005E038.unk4 = temp_v0;
            }
            D_8005E038.unk8 = D_8005E038.unk10[arg0 - 1];
        }
        return D_8005E03C;
    }
    return 0;
}

static int func_80045000(int arg0, int arg1, int arg2)
{
    unsigned int temp_v0;

    if (arg0 != 0) {
        if (D_8005E038.unk24[arg0 - 1] != 0) {
            D_8005E038.offset = arg0;
            D_8005E038.unkC_u.unkC_i = (unsigned int)D_8005E038.unk24[arg0 - 1];
            func_800128A0(0, arg2, arg1);
            temp_v0 = func_80011FB4(D_8005E038.unkC_u.unkC_i);
            if (temp_v0 != 0) {
                D_8005E038.unk14[arg0 - 1] = temp_v0;
                D_8005E038.unk4 = temp_v0;
                func_800128A0(0, arg2, arg1);
            }
            D_8005E038.unk8 = D_8005E038.unk10[arg0 - 1];
        }
        return D_8005E03C;
    }
    return 0;
}

static int func_800450D4() { return D_8005E038.offset; }

static unsigned char func_800450E4()
{
    if (D_8005E038.offset != 0) {
        return D_8005E038.unkC_u.unkC_s.unkF[D_8005E038.offset];
    }
    return 0;
}

static int func_80045110(int arg0, int arg1)
{
    vs_main_CdFile cdFile;

    if (arg0 > 0 && arg1 > 0) {
        int arg = arg1 - 1;

        if (arg1 < 5) {
            if (D_8005E038.unk10[arg] != arg0) {
                do {
                    if (D_8005E038.unk24[arg] != 0) {
                        nop10(0x8E, 0);
                        func_80045440(arg1);
                    }
                } while (0);

                cdFile.lba = musicLBAs[arg0];
                cdFile.size = musicFileSizes[arg0];

                if ((D_8005E038.unk34[arg] != 0)
                    && (D_8005E038.unk34[arg] != (vs_main_CdQueueSlot*)-1)) {
                    nop9(0x98, 0);
                }

                D_8005E038.unk34[arg] = vs_main_getQueueSlot(&cdFile);

                if (D_8005E038.unk24[arg] != 0) {
                    nop9(0x8E, 0);
                }
                D_8005E038.unk24[arg] = allocHeapR(cdFile.size);
                func_80044BC4(D_8005E038.unk34[arg], D_8005E038.unk24[arg]);
                D_8005E038.unk10[arg] = arg0;
            }
            return arg1;
        }
    }
    nop9(0x8E, 0);
    return 0;
}

static int func_80045270(int arg0)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if (D_8005E038.unk24[i] == 0) {
            return func_80045110(arg0, i + 1);
        }
    }
    return 0;
}

static int func_800452C8(unsigned int arg0)
{
    if ((arg0 - 1) < 4) {
        if (D_8005E038.unk34[arg0 - 1] != 0) {
            if (D_8005E038.unk34[arg0 - 1]->unk0[0] == 4) {
                func_80044B80(D_8005E038.unk34[arg0 - 1]);
                D_8005E038.unk34[arg0 - 1] = 0;
                return 0;
            }
            if (D_8005E038.unk34[arg0 - 1]->unk0[0] == 6) {
                func_80044B80(D_8005E038.unk34[arg0 - 1]);
                D_8005E038.unk34[arg0 - 1] = (vs_main_CdQueueSlot*)-1;
                return -1;
            }
            return 1;
        }
    }
    return 0;
}

static int func_80045350()
{
    int i;
    int ret;

    ret = 0;
    i = 0;
    do {
        ret |= func_800452C8(++i);
    } while (i < 4);

    return ret;
}

static int func_8004539C(int arg0, int arg1)
{
    int temp_v0;

    temp_v0 = func_80045110(arg0, arg1);
    if (temp_v0 != 0) {
        while (func_800452C8(arg1) != 0) {
            func_8004261C(0);
        }
    }
    return temp_v0;
}

static int func_800453F4(int arg0)
{
    int ret;

    ret = func_80045270(arg0);
    if (ret != 0) {
        while (func_80045350() != 0) {
            func_8004261C(0);
        }
    }
    return ret;
}

static int func_80045440(int arg0)
{
    func_80044DF4(arg0);

    if (D_8005E038.unk24[arg0 - 1] == 0) {
        return 0;
    }

    freeHeapR(D_8005E038.unk24[arg0 - 1]);
    D_8005E038.unk24[arg0 - 1] = 0;
    D_8005E038.unk10[arg0 - 1] = 0;
    return 1;
}

static int nop5() { return 0; }

static int func_800454B8(int arg0)
{
    if (arg0 != 0) {
        if (D_8005E038.unk14[arg0 - 1] != 0xFFFF) {
            return func_80011EBC(D_8005E038.unk14[arg0 - 1]);
        }
    }
    return 0;
}

static void func_8004550C(int arg0) { func_800454B8(arg0); }

static int func_8004552C(int arg0, int arg1, int arg2)
{
    if (D_8005E038.offset == arg0) {
        func_800128A0(D_8005E038.unk4, arg2, arg1);
        return 1;
    }
    return 0;
}

static int func_80045574(int arg0, int arg1, int arg2)
{
    if (D_8005E038.offset == arg0) {
        func_800129D0(arg2, arg1);
        return 1;
    }
    return 0;
}

static int func_800455AC(int arg0, int arg1, int arg2)
{
    if (D_8005E038.offset == arg0) {
        func_80012A6C(arg2, arg1);
        return 1;
    }
    return 0;
}

static int nop6() { return 0; }

static int nop7() { return 0; }

static void func_800455F4()
{
    int offset = D_8005E038.offset;
    if (offset != 0) {
        func_80044DF4(offset);
        func_80045440(offset);
    }
}

static void func_80045630(unsigned short arg0)
{
    func_8001217C(arg0, D_8005FE70, 0x80, 0x7F);

    if (!((D_8005FE70 *= 2) & 1)) {
        D_8005FE70 = 1;
    }
}

static void func_80045684(int arg0, int arg1, int arg2, int arg3)
{
    if (arg1 == 0x200) {
        if (arg0 != func_80012358(0x200)) {
            func_8001217C(arg0, 0x200, arg2, arg3);
        }
    } else {
        func_8001217C(arg0, arg1, arg2, arg3);
    }
}

static void func_800456EC(int arg0, int arg1, int arg2, int arg3)
{
    if (arg1 == 0x200) {
        if (arg0 != func_80012358(0x200)) {
            func_800121F0(arg0, 0x200, arg2, arg3);
        }
    } else {
        func_800121F0(arg0, arg1, arg2, arg3);
    }
}

void func_80045754(int arg0, int arg1, int arg2, int arg3)
{
    unsigned short var_s0;
    void* var_s0_2;

    switch (arg0) {
    case 0x7E:
    case 0xFE:
        var_s0 = arg1;
        if (func_800123C8(var_s0) != 0) {
            func_80045684(var_s0, D_8005FE74, arg2, arg3);
            D_8005FE74 *= 2;
            if (!(D_8005FE74 & 0x7E)) {
                D_8005FE74 = 2;
            }
        } else {
            func_80045684(var_s0, 0, arg2, arg3);
        }
        break;
    case 0x100:
    case 0x200:
        var_s0 = arg1;
        if (func_800123C8(var_s0) != 0) {
            func_80045684(var_s0, D_8005FE7C, arg2, arg3);
        } else {
            func_80045684(var_s0, 0, arg2, arg3);
        }

        break;
    case 0xFF000:
        var_s0_2 = D_8005E038.unk4C[D_8005E038.unk44 - 1];
        var_s0_2 = (unsigned char*)var_s0_2 + (arg1 + (int*)var_s0_2)[1];
        if (func_800123C8((int)var_s0_2) != 0) {
            func_800456EC((int)var_s0_2, D_8005FE80, arg2, arg3);
            D_8005FE80 *= 2;
            if (!(D_8005FE80 & arg0)) {
                D_8005FE80 = 0x1000;
            }
        } else {
            func_800456EC((int)var_s0_2, 0, arg2, arg3);
        }
        break;
    case 0xF00000:
        var_s0_2 = D_8005E08C;
        var_s0_2 = (unsigned char*)var_s0_2 + (arg1 + ((int*)D_8005E08C))[1];
        if (func_800123C8((int)var_s0_2) != 0) {
            func_800456EC((int)var_s0_2, D_8005FE84, arg2, arg3);
            D_8005FE84 *= 2;
            if (!(D_8005FE84 & arg0)) {
                D_8005FE84 = 0x100000;
            }
        } else {
            func_800456EC((int)var_s0_2, 0, arg2, arg3);
        }
        break;
    default:
        nop10(0x95, 0);
        break;
    }
}

void func_80045988(int arg0, int arg1) { func_80045754(arg0, arg1, 0x80, 0x7F); }

int func_800459AC(int coords, int z)
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

static void func_80045A58(int arg0, int arg1, int coords, int z)
{
    coords = func_800459AC(coords, z);
    z = coords & 0xFFFF;
    coords = coords >> 0x10;
    if (z > 0) {
        func_80045754(arg0, arg1, coords, z);
    }
}

static void func_80045AA8(int arg0, int arg1, SVECTOR* vec)
{
    int z;
    long coords;
    long value;
    long flag;

    SetRotMatrix(&D_1F800014_mat);
    SetTransMatrix(&D_1F800014_mat);
    z = RotTransPers(vec, &coords, &value, &flag);
    func_80045A58(arg0, arg1, coords, z);
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
        temp_v1 = (int)D_8005E038.unk4C[D_8005E038.unk44 - 1];
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

int func_80045DE0(int id, int slot)
{
    vs_main_CdFile cdFile;
    unsigned int new_var;

    if ((slot - 1u) < 3) {
        if (D_8005E038.unk4C[(slot - 1)] == 0) {
            new_var = slot - 1;
            cdFile.lba = seLBAs[id];
            cdFile.size = seFileSizes[id];

            if ((D_8005E038.unk58[new_var] != 0)
                && (D_8005E038.unk58[new_var] != (vs_main_CdQueueSlot*)-1)) {
                nop9(0x8F, 0);
            }

            D_8005E038.unk58[new_var] = vs_main_getQueueSlot(&cdFile);

            if (D_8005E038.unk4C[new_var] != 0) {
                nop9(0x90, 0);
            }

            D_8005E038.unk48[new_var] = id;
            D_8005E038.unk4C[new_var] = allocHeapR(cdFile.size);
            func_80044BC4(D_8005E038.unk58[new_var], D_8005E038.unk4C[new_var]);

            return slot;
        }
    }
    return 0;
}

static int func_80045F0C(int arg0)
{
    int i;

    for (i = 0; i < 3; ++i) {
        if (D_8005E038.unk4C[i] == 0) {
            return func_80045DE0(arg0, i + 1);
        }
    }
    return 0;
}

static int func_80045F64(unsigned int arg0)
{
    if ((arg0 - 1) < 3) {
        if (D_8005E038.unk58[arg0 - 1] != 0) {
            if (D_8005E038.unk58[arg0 - 1]->unk0[0] == 4) {
                func_80044B80(D_8005E038.unk58[arg0 - 1]);
                D_8005E038.unk58[arg0 - 1] = 0;
                return 0;
            }
            if (D_8005E038.unk58[arg0 - 1]->unk0[0] == 6) {
                func_80044B80(D_8005E038.unk58[arg0 - 1]);
                D_8005E038.unk58[arg0 - 1] = (vs_main_CdQueueSlot*)-1;
                return -1;
            }
            return 1;
        }
    }
    return 0;
}

static int func_80045FEC()
{
    int i;
    int ret;

    ret = 0;
    i = 0;
    do {
        ret |= func_80045F64(++i);
    } while (i < 3);

    return ret;
}

static int func_80046038(int arg0)
{
    int ret;

    ret = func_80045F0C(arg0);
    if (ret != 0) {
        while (func_80045FEC() != 0) {
            func_8004261C(0);
        }
    }
    return ret;
}

static int func_80046084(int arg0)
{
    if ((arg0 - 1u < 3) && D_8005E038.unk4C[arg0 - 1] != 0) {
        D_8005E038.unk44 = arg0;
        return 1;
    }
    return 0;
}

static int func_800460C0(unsigned int arg0)
{
    if ((arg0 - 1) < 3) {
        if (D_8005E038.unk4C[arg0 - 1] != 0) {
            if (D_8005E038.unk44 == arg0) {
                D_8005E038.unk44 = 0;
            }
            func_80012288(-2, 0);
            func_80012288(0, 0xFF000);
            freeHeapR(D_8005E038.unk4C[arg0 - 1]);
            D_8005E038.unk48[arg0 - 1] = 0;
            D_8005E038.unk4C[arg0 - 1] = 0;
            return 1;
        }
    }
    return 0;
}

static int func_80046168(unsigned int arg0)
{
    if (D_8005E038.unk14[16] == 0) {
        D_8005E038.unk14[16] = arg0;
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

static void func_800461CC(
    int arg0, unsigned int arg1[], unsigned int arg2, int arg3, int arg4)
{
    int var_s0;
    void* temp_s1;

    temp_s1 = arg1;

    if (arg2 < arg1[0]) {
        temp_s1 = (unsigned char*)arg1 + (arg1 + arg2)[1];
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
        func_800456EC((int)temp_s1, var_s0, arg3, arg4);
    }
}

static void func_800462E8(int arg0, unsigned int* arg1, unsigned int arg2)
{
    func_800461CC(arg0, arg1, arg2, 0x80, 0x7F);
}

static void func_80046310(int arg0, unsigned int arg1[], int arg2, int arg3, int arg4)
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

    var_v0 = arg3 + ((unsigned int)arg3 >> 0x1F);
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

static void func_800463BC(int arg0, unsigned int* arg1, int arg2, SVECTOR* vec)
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
    unsigned char* var_a0 = (unsigned char*)arg1 + (arg1 + arg2)[1];

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
    int a0 = (int)((unsigned char*)arg1 + (arg2 + arg1)[1]);

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
        if (D_8005E038.unk64[arg0 - 1] != 0) {
            func_80013378(0, arg2);
            func_800132C4(D_8005E038.unk64[arg0 - 1], arg1, 1);
            return 1;
        }
    }
    return 0;
}

static void func_80046578(int arg0) { func_800464FC(arg0, 0x80, 0x7F); }

static int func_8004659C(int arg0)
{
    if ((arg0 - 1u) < 3) {
        if (D_8005E038.unk64[arg0 - 1] != 0) {
            func_80013328();
            freeHeapR(D_8005E038.unk64[arg0 - 1]);
            D_8005E038.unk64[arg0 - 1] = 0;
            return 1;
        }
    }
    return 0;
}

static int func_80046608(unsigned int arg0)
{
    if (D_8005E038.unk14[22] == 0) {
        D_8005E038.unk14[22] = arg0;
        return 3;
    }
    return 0;
}

static int func_80046634()
{

    if (D_8005E038.unk14[22] != 0) {
        func_80013328();
        D_8005E038.unk14[22] = 0;
        return 1;
    }
    return 0;
}

static void func_80046678(int file)
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
    cdFile.lba = soundLBAs[file];
    cdFile.size = soundFileSizes[file];

    if (D_8005E0BC) {
        if (D_8005E0BC != (-1)) {
            nop9(0x93 & 0xFFu, 0);
        }
    }
    D_8005E038.unk84 = vs_main_getQueueSlot(&cdFile);
    if (D_8005E038.unk80 != 0) {
        nop9(0x94, 0);
    }
    new_var = 1;
    D_8005E038.unk80 = allocHeapR(cdFile.size);
    D_8005E038.fileId = file;
    func_80044BC4(D_8005E038.unk84, D_8005E038.unk80);
}

static void func_80046770(int arg0) { func_80046678(soundFileMap[arg0]); }

static int func_800467A0()
{
    int temp_v0;

    if (D_8005E038.unk84 != 0) {
        if (D_8005E038.unk84->unk0[0] == 7) {
            temp_v0 = func_80012C04();
            if (temp_v0 == 0) {
                func_80044B80(D_8005E038.unk84);
                D_8005E038.unk84 = 0;
                freeHeapR(D_8005E038.unk80);
                D_8005E038.unk80 = 0;
                D_8005E038.fileId = 0;
                return 0;
            }
            if (temp_v0 == -1) {
                func_80044B80(D_8005E038.unk84);
                D_8005E038.unk84 = 0;
                freeHeapR(D_8005E038.unk80);
                D_8005E038.unk80 = 0;
                D_8005E038.fileId = 0;
                return -1;
            }
            return 1;
        }
        if (D_8005E038.unk84->unk0[0] == 4) {
            D_8005E038.unk84->unk0[0] = 7;
            func_80013188(D_8005E038.unk80, 0);
            return 1;
        }
        if (D_8005E038.unk84->unk0[0] == 6) {
            func_80044B80(D_8005E038.unk84);
            D_8005E038.unk84 = 0;
            freeHeapR(D_8005E038.unk80);
            D_8005E038.unk80 = 0;
            D_8005E038.fileId = 0;
            return -1;
        }
        return 1;
    }
    return 0;
}

static void func_8004687C(int arg0)
{
    func_80046770(arg0);

    while (func_800467A0() != 0) {
        func_8004261C(0);
    }
}

void func_800468BC(int arg0) { func_8001240C(arg0); }

static void func_800468DC() { func_80012918(0x7FFF); }

void func_800468FC()
{
    void* temp_v0;

    func_80011DAC();
    func_80013230(0x7F);
    temp_v0 = allocHeapR(0x8800);
    func_8004493C(0xF618, 0x8800, temp_v0);
    func_80012BB8(temp_v0, 1);
    freeHeapR(temp_v0);
    temp_v0 = allocHeapR(0x12000);
    func_8004493C(0xF62D, 0x12000, temp_v0);
    func_80012BB8(temp_v0, 1);
    freeHeapR(temp_v0);
    temp_v0 = allocHeapR(0x18800);
    func_8004493C(0x10C65, 0x18800, temp_v0);
    func_800131DC(temp_v0, 0, 1);
    freeHeapR(temp_v0);
    func_8004493C(0x128E0, 0x5800, &D_80050478);
    func_80011DEC(D_80050478);
    D_8005FE70 = 1;
    D_8005FE74 = 2;
    D_8005FE78 = 0x80;
    D_8005FE7C = 0x200;
    D_8005FE80 = 0x1000;
    D_8005FE84 = 0x100000;
}

static void func_80046A38()
{
    int i;

    D_8005E038.offset = 0;
    D_8005E038.unkC_u.unkC_i = 0;
    D_8005E038.unk8 = 0xFFFF;
    D_8005E038.unk4 = 0xFFFF;
    D_8005E038.unk44 = 0;

    for (i = 0; i < 4; ++i) {
        D_8005E038.unk10[i] = 0;
        D_8005E038.unk14[i] = 0xFFFF;
        D_8005E038.unk24[i] = 0;
        D_8005E038.unk34[i] = 0;
    }

    for (i = 0; i < 3; ++i) {
        D_8005E038.unk48[i] = 0;
        D_8005E038.unk4C[i] = 0;
        D_8005E038.unk58[i] = 0;
    }

    for (i = 0; i < 3; ++i) {
        D_8005E038.unk64[i] = 0;
        D_8005E038.unk70[i] = 0;
    }

    D_8005E038.fileId = 0;
    D_8005E038.unk80 = 0;
    D_8005E038.unk84 = 0;
    D_8005FE70 = 1;
    D_8005FE74 = 2;
    D_8005FE78 = 0x80;
    D_8005FE7C = 0x200;
    D_8005FE80 = 0x1000;
    D_8005FE84 = 0x100000;
}

void func_80046B3C(int arg0, int arg1, unsigned short* arg2)
{
    int i;
    unsigned short g;
    unsigned short b;
    unsigned short r;
    unsigned char(*p)[7];

    for (i = 0; i < 256; ++i) {
        r = arg2[i] & 0x1F;
        g = (arg2[i] & 0x3E0) >> 5;
        b = (arg2[i] & 0x7C00) >> 10;

        p = D_80055D58.unk0[arg1].unkE;

        if (arg0 != 0) {
            p[i][4] = (r - p[i][0]) + 31;
            p[i][5] = (g - p[i][1]) + 31;
            p[i][6] = (b - p[i][2]) + 31;
        } else {
            p[i][0] = r;
            p[i][1] = g;
            p[i][2] = b;
            loadImageSource[arg1][i] = r + (g << 5) + (b << 10) + (p[i][3] << 15);
        }
    }

    if (arg0 != 0) {
        unsigned char* p = D_80055D58.unk0[arg1].unk6;
        p[0] = 1;
        p[1] = 0;
        p[2] = 0;
        p[3] = arg0;
    } else {
        D_80055D58.unk0[arg1].unk6[0] = 0;
    }
}

static void func_80046C80(int arg0, int arg1, unsigned short* arg2, int arg3)
{
    if (D_80055D58.unk0[0].unk2 != 0) {
        func_80046B3C(arg0, arg1, arg2 + (arg3 << 4));
        D_80055D58.unk0[0].unk0 = 1;
    }
}

static void func_80046CC8(int arg0, int arg1, unsigned short* arg2, int arg3)
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
    int t4 = (unsigned short)arg4;
    int t5 = (unsigned short)arg5;
    unsigned char(*t2)[7] = D_80055D58.unk0[arg2].unkE;

    for (i = 0; i < 256; ++i) {
        temp_t0 = D_80055D58.unk0[arg2].unk70E[i];
        if ((t2[i][0] + t2[i][1] + t2[i][2] + t2[i][3]) != 0) {
            switch (arg0) {
            case 1:
                tmp = 1;
                var_t3 = arg3 + (t2[i][0] >> tmp);
                var_t1 = t4 + (t2[i][1] >> tmp);
                var_a0 = t5 + (t2[i][2] >> tmp);
                break;
            case 2:
                var_t3 = arg3 + ((t2[i][0] * 2) + (t2[i][1] * 3) + t2[i][2]) / 6;
                var_t1 = t4 + ((t2[i][0] * 2) + (t2[i][1] * 3) + t2[i][2]) / 6;
                var_a0 = t5 + ((t2[i][0] * 2) + (t2[i][1] * 3) + t2[i][2]) / 6;
                break;
            case 3:
                var_t3 = arg3 + ((t2[i][0] * 2) + (t2[i][1] * 3) + t2[i][2]) / 12;
                var_t1 = t4 + ((t2[i][0] * 2) + (t2[i][1] * 3) + t2[i][2]) / 12;
                var_a0 = t5 + ((t2[i][0] * 2) + (t2[i][1] * 3) + t2[i][2]) / 12;
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
                var_t3 = arg3 - (t2[i][0] - tmp);
                var_t1 = t4 - (t2[i][1] - tmp);
                var_a0 = t5 - (t2[i][2] - tmp);
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
                var_t3 = t2[i][0] + arg3;
                var_t1 = t2[i][1] + t4;
                var_a0 = t2[i][2] + t5;
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
                t2[i][4] = ((var_t3 - t2[i][0]) + 0x1F);
                t2[i][5] = ((var_t1 - t2[i][1]) + 0x1F);
                t2[i][6] = ((var_a0 - t2[i][2]) + 0x1F);
            } else {
                t2[i][2] = var_a0;
                t2[i][0] = var_t3;
                t2[i][1] = var_t1;
                loadImageSource[arg2][i]
                    = var_t3 + (var_t1 << 5) + (var_a0 << 0xA) + (t2[i][3] << 0xF);
            }
        } else {
            t2[i][6] = 0x1F;
            t2[i][5] = 0x1F;
            t2[i][4] = 0x1F;
        }
    }
    if (arg1 != 0) {
        unsigned char* p = D_80055D58.unk0[arg2].unk6;
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
        D_8005DBE8 = 0;

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
        D_8005DBE8 = 0;
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

static void func_800478E0(int arg0, int arg1, int arg2, int arg3, int arg4)
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
    unsigned char sp10[4];
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
        func_8008B430(sp10, ((unsigned short)temp_t0->unk6[3] << 16) >> 18);
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
    unsigned char sp10[4];
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
            func_8008B430(sp10, ((unsigned short)t1->unk6[3] << 0x10) >> 0x12);
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
    unsigned char sp18[4];
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
    unsigned int var_t5;
    unsigned short temp_a3;
    unsigned short temp_t2;
    unsigned short var_a1;
    unsigned char(*e)[7];
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
                e = D_80055D58.unk0[i].unkE;
                for (j = 0; j < 256; ++j) {
                    if ((e[j][0] + e[j][1] + e[j][2]) == 0) {
                        continue;
                    }
                    temp_t2 = e[j][0] + D_8004B278[e[j][4]][c];
                    temp_a3 = e[j][1] + D_8004B278[e[j][5]][c];
                    var_a1 = e[j][2] + D_8004B278[e[j][6]][c];
                    if (((var_a1 | (temp_t2 | temp_a3)) << 16) == 0) {
                        var_a1 = 1;
                    }
                    e[j][1] = temp_a3;
                    e[j][2] = var_a1;
                    e[j][0] = temp_t2;
                    loadImageSource[i][j]
                        = temp_t2 + (temp_a3 << 5) + (var_a1 << 10) + (e[j][3] << 15);
                }
            } else if (D_80055D58.unk0[i].unk6[3] >= 4) {
                var_t5 = 2;
                c = D_80055D58.unk0[i].unk6[1];
                e = D_80055D58.unk0[i].unkE;
                for (j = 0; j < 256; ++j) {
                    if ((e[j][0] + e[j][1] + e[j][2]) == 0) {
                        continue;
                    }
                    temp_t2 = e[j][0] + D_8004B668[e[j][4]][c];
                    temp_a3 = e[j][1] + D_8004B668[e[j][5]][c];
                    var_a1 = e[j][2] + D_8004B668[e[j][6]][c];
                    if (((var_a1 | (temp_t2 | temp_a3)) << 16) == 0) {
                        var_a1 = 1;
                    }
                    e[j][0] = temp_t2;
                    e[j][1] = temp_a3;
                    e[j][2] = var_a1;
                    loadImageSource[i][j]
                        = temp_t2 + (temp_a3 << 5) + (var_a1 << 10) + (e[j][3] << 15);
                }
            } else if (D_80055D58.unk0[i].unk6[3] >= 2) {
                var_t5 = 4;
                c = D_80055D58.unk0[i].unk6[1];
                e = D_80055D58.unk0[i].unkE;
                for (j = 0; j < 256; ++j) {
                    if ((e[j][0] + e[j][1] + e[j][2]) == 0) {
                        continue;
                    }
                    temp_t2 = e[j][0] + D_8004B860[e[j][4]][c];
                    temp_a3 = e[j][1] + D_8004B860[e[j][5]][c];
                    var_a1 = e[j][2] + D_8004B860[e[j][6]][c];
                    if (((var_a1 | (temp_t2 | temp_a3)) << 16) == 0) {
                        var_a1 = 1;
                    }
                    e[j][0] = temp_t2;
                    e[j][1] = temp_a3;
                    e[j][2] = var_a1;
                    loadImageSource[i][j]
                        = temp_t2 + (temp_a3 << 5) + (var_a1 << 10) + (e[j][3] << 15);
                }
            } else {
                var_t5 = 8;
                c = D_80055D58.unk0[i].unk6[1];
                e = D_80055D58.unk0[i].unkE;
                for (j = 0; j < 256; ++j) {
                    if ((e[j][0] + e[j][1] + e[j][2]) == 0) {
                        continue;
                    }
                    temp_t2 = e[j][0] + D_8004B95C[e[j][4]][c];
                    temp_a3 = e[j][1] + D_8004B95C[e[j][5]][c];
                    var_a1 = e[j][2] + D_8004B95C[e[j][6]][c];
                    if (((var_a1 | (temp_t2 | temp_a3)) << 16) == 0) {
                        var_a1 = 1;
                    }
                    e[j][0] = temp_t2;
                    e[j][1] = temp_a3;
                    e[j][2] = var_a1;
                    loadImageSource[i][j]
                        = temp_t2 + (temp_a3 << 5) + (var_a1 << 10) + (e[j][3] << 15);
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

void func_80048A64(unsigned short* arg0, unsigned int arg1, int arg2, unsigned int arg3)
{
    RECT sp10;
    unsigned short temp_a0_2;
    unsigned int i;
    unsigned char* temp_v1_3;

    if (arg1 >= 14) {
        setRECT(&sp10, arg2 + 0x300, arg1 + 0xE0, arg3, 1);
        LoadImage(&sp10, (unsigned long*)arg0);
        return;
    }

    if (D_80055D58.unk0[arg1].unk5 == 0) {
        D_80055D58.unk0[arg1].unk6[0] = 0;
        for (i = 0; i < arg3; ++i) {
            temp_a0_2 = arg0[i];
            temp_v1_3 = D_80055D58.unk0[arg1].unkE[arg2 + i];
            loadImageSource[arg1][arg2 + i] = temp_a0_2;
            D_80055D58.unk0[arg1].unk70E[arg2 + i] = temp_a0_2;
            temp_v1_3[0] = (temp_a0_2 & 0x1F);
            temp_v1_3[1] = ((temp_a0_2 & 0x3E0) >> 5);
            temp_v1_3[2] = ((temp_a0_2 & 0x7C00) >> 0xA);
            temp_v1_3[3] = ((temp_a0_2 & 0x8000) >> 0xF);
        }
        D_80055D58.unk0[0].unk0 = 1;
    }
}

void func_80048B8C(int arg0, unsigned short* arg1, int arg2, short arg3, short arg4,
    short arg5, int arg6)
{
    int i;
    short r;
    int new_var;
    int new_var2;
    int new_var3;
    short g;
    short b;
    short a;
    unsigned short t4;

    for (i = 0; i < 0x100; ++i) {
        a = arg1[i];
        if (a != 0) {
            switch (arg0) {
            case 5:
                t4 = 0x1F;
                r = arg3 + ((((unsigned char)a) & t4) >> 1);
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
        t4 = t4 >> 0xF;
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
                unsigned char* t5 = D_80055D58.unk0[arg2].unkE[i];
                t5[0] = r;
                t5[1] = g;
                t5[2] = b;
                t5[3] = t4;
            }
        }
        D_80055D58.unk0[arg2].unk70E[i] = r + (g << 5) + (b << 10) + (t4 << 15);
    }

    D_80055D58.unk0[0].unk0 = 1;
}

void func_80048E68(unsigned short* arg0, int arg1, unsigned short arg2,
    unsigned short arg3, unsigned short arg4, int arg5)
{
    func_80048B8C(8, arg0, arg1, arg2, arg3, arg4, arg5);
}

void func_80048EC4()
{
    int i;
    int var_v0;
    unsigned int* var_v1;
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

static void func_80048F8C()
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

static void func_8004908C() { __asm__(".nop;"); }

static void nop9(int arg0 __attribute__((unused)), int arg1 __attribute__((unused))) { }

static void nop10(int arg0 __attribute__((unused)), int arg1 __attribute__((unused))) { }

static void nop11() { }

void memcpy_impl(void* dest, void* src, unsigned int sz)
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

void bzero_impl(void* dest, int sz)
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
