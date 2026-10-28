#pragma once
#include "6E644.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    short unk0[6];
    short unkC[2];
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
    u_char unk14;
    u_char unk15;
    u_char unk16[4];
} pFileBlock9;

typedef struct {
    u_short flags;
    u_char unk2;
    u_char unk3;
    u_char unk4;
    u_char curve;
    u_char unk6;
    u_char unk7;
    u_short unk8;
    u_short mode;
    u_short unkC;
    u_short limit : 8;
    u_short radius : 4;
    u_short radiusJitter : 4;
    u_short unk10;
    u_short shape12;
    short unk14[6];
    short unk20[6];
    short unk2C[6];
} func_800D0B30_t;

typedef struct {
    u_short count;
    u_short dataOffset;
    u_char curveSizes[0];
} pFileCurveBlock;

typedef struct {
    u_short unk0;
    u_short dataIndex;
} pFileTextureInfo;

typedef struct {
    int unk0;
    short unk4;
    u_char unk6;
    u_char unk7;
    short unk8;
    short unkA;
    short unkC;
    u_short unkE;
    int unk10;
    short unk14;
    u_char textureIndex;
    u_char unk17;
    u_char* unk18;
    pFileTextureInfo* textureInfo;
} func_800D6CF_t;

typedef struct {
    u_long tag;
    LINE_F2 line;
    u_long drawMode;
} func_800CFAAC_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    u_int flags : 26;
    u_int transparencyCurve : 6;
    u_char unk8;
    u_char unk9;
    u_char unkA;
    u_char unkB;
    u_char unkC;
    u_char unkD;
    u_char unkE;
    u_char unkF;
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
    u_char unk14;
    u_char unk15;
    u_char unk16;
    u_char unk17;
    short unk18[6];
    short unk24[6];
    short unk30[2];
    short unk34[8][6];
    short unk94[5][4];
    short unkBC[2];
    short unkC0[2];
    u_char rCurve;
    u_char gCurve;
    u_char bCurve;
    u_char unkC7;
    u_char unkC8;
    u_char unkC9;
    u_char unkCA;
    u_char unkCB;
} func_800FA098_arg0;

typedef struct {
    VECTOR unk0;
    VECTOR unk10;
    int unk20;
    u_int flags;
    u_short unk28;
    u_short unk2A;
    SVECTOR unk2C;
    VECTOR unk34;
    VECTOR unk44;
    u_char unk54[0x10];
    MATRIX unk64;
    u_char unk84[0x14];
    VECTOR unk98;
    VECTOR unkA8;
    VECTOR unkB8;
    VECTOR unkC8;
    VECTOR unkD8;
    VECTOR unkE8;
    SVECTOR unkF8;
    SVECTOR unk100;
    SVECTOR unk108;
    SVECTOR unk110;
    int unk118[2];
    int unk120;
    int unk124[2];
    int unk12C[2];
    int unk134[2];
    SVECTOR unk13C;
    SVECTOR unk144;
    int unk14C[2];
    u_char unk154[4];
    u_char unk158[0x10];
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    u_char unk180;
    int unk184;
    int unk188;
} func_800FA098_arg1;

typedef struct {
    int count;
    func_800FA098_arg0 unk4[0];
} pFileBlock5;

typedef struct {
    int count;
    u_short offsets[0];
} pFileBlock3;

typedef struct {
    short clut;
    short tpage;
    u_char u;
    u_char v;
    u_char w;
    u_char h;
    short x0;
    short y0;
    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
} pFileTexture;

typedef struct {
    int unk0;
    int unk4;
    pFileBlock5* block5Data;
    u_char* curves[32];
    pFileCurveBlock* curveBlock;
    char* block8Data;
    int block1TableCount;
    pFileTextureInfo* textureInfoTable[4];
    pFileTexture* textures;
    int block2Count;
    u_short* block2Data;
    pFileBlock9* block9Data;
    func_800D0B30_t* block10Data;
    pFileBlock3* block3Data;
    u_char* block11Data;
    void* block12Data;
    void* block13Data;
    int unkCC;
    actionEffectRequest* unkD0;
} D_800F569C_t;

typedef struct {
    int vx;
    int vy;
    int vz;
} func_800D52A4_t2;

typedef struct {
    short mass;
    short gravityScale;
    func_800D52A4_t2 position;
    func_800D52A4_t2 velocity;
    func_800D52A4_t2 force;
    func_800D52A4_t2 acceleration;
} func_800D52A4_t;

typedef struct func_800D2904_t {
    struct func_800D2904_t* previous;
    struct func_800D2904_t* next;
    func_800D52A4_t motion;
    func_800D6CF_t unk3C;
    char unk5C[4];
    u_char unk60;
    char unk61;
    short unk62[3];
    short lifetime;
    char unk6A[2];
    u_char endEvent;
    u_char tickEvent;
    char unk6E[2];
    int unk70;
    u_char unk74[3];
    u_char unk77;
} func_800D2904_t;

typedef struct {
    short rotation[3];
    u_short flags;
    int unk8;
    short unkC;
    short frame;
    int unk10[3];
    VECTOR position;
    int unk2C[2];
    u_char actor;
    u_char bone;
    u_char targetActor;
    u_char targetBone;
    MATRIX world;
    MATRIX view;
    MATRIX attachment;
    MATRIX facing;
    SVECTOR saved;
    SVECTOR control0;
    SVECTOR control1;
} func_800D0548_arg1;

typedef struct {
    u_short unk0_0 : 8;
    u_short unk0_8 : 8;
} func_800D5780_t2;

typedef struct {
    /* 0x0 */ u_long* unk0;
    /* 0x4 */ func_800D5780_t2 unk4;
    /* 0x6 */ short unk6;
    /* 0x8 */ short unk8;
    /* 0xA */ short unkA;
    /* 0xC */ int unkC;
} func_800D5780_t;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    int unk4;
    func_800D5780_t unk8[0];
} D_800F53B8_t4;

typedef struct {
    actionEffectTarget unk0;
    actionEffectTarget unkC;
    actionEffectTarget unk18;
    actionEffectTarget unk24;
    D_800F53B8_t4* unk30;
    func_800D4910_t* unk34;
    short unk38;
    short unk3A;
    int unk3C;
} D_800F53B8_t3;

typedef struct D_800F53B8_t {
    struct D_800F53B8_t* next;
    struct D_800F53B8_t* previous;
    char unk8;
    char unk9;
    u_short unkA;
    char* unkC;
    char unk10[4];
    u_int unk14_0 : 8;
    u_int unk14_8 : 3;
    u_int unk14_11 : 5;
    u_int unk14_16 : 16;
    func_800D2904_t* unk18;
    func_800D0548_arg1 unk1C[16];
    D_800F53B8_t3 unkD1C;
} D_800F53B8_t;

void vs_battle_addVecToSvec(VECTOR* arg0, SVECTOR* arg1, VECTOR* arg2);
void vs_battle_lerp2DVector(short* src, int t, int* vec);
void vs_battle_lerpSvector(short* src, int t, SVECTOR* vec);
void vs_battle_lerpVector(short* src, int t, VECTOR* vec);
int vs_battle_randUniformInt(int, int);
void func_800CFAAC(func_800CFAAC_t* arg0);
int func_800CFE1C(short* arg0, int arg1);
void func_800D6D24(func_800D6CF_t* arg0);
/**
 * Samples a curve from the currently loaded .P file.
 *
 * @param curveId Curve to sample (1-indexed).
 * @param distance Point to sample, will wrap around if too long.
 * @return Sampled value; 0 if `curveId` is not a valid index.
 */
int vs_battle_sampleCurve(int curveId, int distance);
/**
 * Evaluates a point on a spline segment between p1 and p2.
 *
 * The curve passes through p1 at t = 0 and p2 at t = ONE;
 *
 * @param p0  Control point before segment.
 * @param p1  Segment start point.
 * @param p2  Segment end point.
 * @param p3  Control point afater segment.
 * @param t   Interpolation value ([0, ONE] ?).
 * @param out Output vector.
 */
void vs_battle_splineInterpolate(
    SVECTOR* p0, SVECTOR* p1, SVECTOR* p2, SVECTOR* p3, int t, SVECTOR* out);
void vs_battle_svecToVec(SVECTOR* arg0, VECTOR* arg1);
void vs_battle_vecToSvec(VECTOR* arg0, SVECTOR* arg1);
void func_800D2ADC(D_800F53B8_t*, int, int, int, func_800D2904_t*);
void func_800D6CCC(int* arg0);
void func_800D6CF0(func_800D6CF_t* arg0, int textureIndex, int arg2);

typedef struct {
    VECTOR position;
    VECTOR lookAt;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int roll;
    int nearClip;
    int projectionDistance;
    int farClip;
} D_800F54D8_t;

void func_800D1B18(D_800F54D8_t*);
void func_800D1E20(int);
extern D_800F569C_t* D_800F569C;
extern D_800F569C_t D_800F56C8;
extern SVECTOR D_800F5310[];
extern D_800F53B8_t* D_800F53BC;
extern short D_800F54D0;
extern D_800F54D8_t D_800F5520[2];
extern short D_800F55A0;
