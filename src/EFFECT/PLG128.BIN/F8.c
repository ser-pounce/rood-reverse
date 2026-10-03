#define TRAIL_SAMPLE_COUNT 5

#include "common.h"
#include "src/EFFECT/trails.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "vs_inline_c.h"
#include <inline_c.h>

typedef struct {
    u_char unk0[0x88];
    VECTOR unk88;
    VECTOR unk98;
    MATRIX unkA8;
} func_800FD9A4_t;

void func_800FE3D0(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FEB6C(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FED84(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FF248(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FF3C0(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);
void func_800FF54C(
    func_800FA098_arg0*, func_800FA098_arg1*, D_800F53B8_t*, func_800FA76C_arg3*);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800F98F8);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FA490);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FB400);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FC2BC);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FCE0C);

void func_800FD9A4(func_800FD9A4_t* arg0, func_800FA098_arg1* arg1)
{
    vs_battle_lookAt(&arg0->unk98, &arg0->unk88, &arg0->unkA8);
    arg0->unkA8.t[0] = arg1->unk0.vx;
    arg0->unkA8.t[1] = arg1->unk0.vy;
    arg0->unkA8.t[2] = arg1->unk0.vz;
}

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FDA04);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FDC80);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FDE78);

INCLUDE_ASM("build/src/EFFECT/PLG128.BIN/nonmatchings/F8", func_800FDEC4);

#define VS_TRAIL_ORIGIN_FUNCTION func_800FE3D0
#define VS_TRAIL_TARGET_FUNCTION func_800FEB6C
#define VS_TRAIL_CONTROL_FUNCTION func_800FED84
#define VS_TRAIL_INIT_FUNCTION func_800FF248
#define VS_TRAIL_UPDATE_FUNCTION func_800FF3C0
#define VS_TRAIL_RENDER_FUNCTION func_800FF54C
#define VS_TRAIL_DISPATCH_FUNCTION func_800FFFA8
#define VS_TRAIL_CORNER_STATE D_80100A10
#include "src/EFFECT/trails5.h"
