#include "common.h"

#define VS_PARTICLE_ORIGIN_FUNCTION func_800F9AD0
#define VS_PARTICLE_TARGET_FUNCTION func_800FA258
#define VS_PARTICLE_CONTROL_FUNCTION func_800FA470
#define VS_PARTICLE_RENDER_FUNCTION func_800FA920
#define VS_PARTICLE_DISPATCH_FUNCTION func_800FB4E0
#define VS_PARTICLE_CORNER_STATE D_800FF9B4
#include "src/EFFECT/particleSetup.h"

#include "src/EFFECT/particleRender.h"

#include "src/EFFECT/particleDispatch.h"

#define VS_TRAIL_ORIGIN_FUNCTION func_800FB774
#define VS_TRAIL_TARGET_FUNCTION func_800FBF10
#define VS_TRAIL_CONTROL_FUNCTION func_800FC128
#define VS_TRAIL_INIT_FUNCTION func_800FC600
#define VS_TRAIL_UPDATE_FUNCTION func_800FC778
#define VS_TRAIL_RENDER_FUNCTION func_800FC904
#define VS_TRAIL_DISPATCH_FUNCTION func_800FD354
#define VS_TRAIL_CORNER_STATE D_800FF9B8
/* This overlay has both a nine-sample and a five-sample trail. trails.h is only
 * included once, so the nine-sample copy gets its own type names here and the
 * five-sample types are written out below. */
#define _trail vs_trail9
#define func_800FA76C_arg3 vs_trail9State
#define vs_trailPrim vs_trail9Prim
#include "src/EFFECT/trails9.h"
#undef _trail
#undef func_800FA76C_arg3
#undef vs_trailPrim
#undef TRAIL_SAMPLE_COUNT

typedef struct {
    SVECTOR splinePoints[4];
    u_char stepCount;
    u_char splineSampleCount;
    u_char trailCollapseCounter;
    u_char currentSplineSample;
    SVECTOR splineSamples[5];
    int splineProgress;
    int speed;
    int unk;
} _trail;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char trailcount;
    u_char unk3;
    _trail* trails;
    int curveSampleDistance;
    func_800D6CF_t unkC;
    u_char sampledTransparencyCurve[0];
} func_800FA76C_arg3;

#define VS_TRAIL_ORIGIN_FUNCTION func_800FD894
#define VS_TRAIL_TARGET_FUNCTION func_800FE030
#define VS_TRAIL_CONTROL_FUNCTION func_800FE248
#define VS_TRAIL_INIT_FUNCTION func_800FE70C
#define VS_TRAIL_UPDATE_FUNCTION func_800FE884
#define VS_TRAIL_RENDER_FUNCTION func_800FEA10
#define VS_TRAIL_DISPATCH_FUNCTION func_800FF46C
#define VS_TRAIL_CORNER_STATE D_800FF9BC
#include "src/EFFECT/trails5.h"
