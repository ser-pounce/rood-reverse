#include "common.h"
#include "src/SLUS_010.40/32154.h"
#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/BATTLE/BATTLE.PRG/6E644.h"
#include "vs_inline_c.h"
#include <rand.h>
#include <inline_c.h>

#define VS_PARTICLE_ORIGIN_FUNCTION func_800F9910
#define VS_PARTICLE_TARGET_FUNCTION func_800FA098
#define VS_PARTICLE_CONTROL_FUNCTION func_800FA2B0
#define VS_PARTICLE_CORNER_STATE D_800FB5B4
#include "src/EFFECT/particleSetup.h"

#define VS_PARTICLE_RENDER_FUNCTION func_800FA760
#include "src/EFFECT/particleRender.h"

int func_800FB320(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    func_800FA098_arg0* temp_s2;
    int var_a0;
    short var_v0;
    func_800FA098_arg1* a2 = (func_800FA098_arg1*)0x1F8001D0;
    func_800FA098_arg3* temp_s1 = arg0->unk8;
    D_800F53B8_t* temp_s0 = D_800F53BC;
    int s3 = 1;

    switch (arg1) {
    case 1:
        temp_s1 = vs_main_allocHeapR(0x30);
        arg0->unk8 = temp_s1;
        temp_s1->unk1 = arg2 >> 8;
        temp_s1->unk0 = arg2;
        temp_s1->unkC = 0;
        temp_s1->unk8 = 0;
        temp_s2 = &D_800F569C->block5Data->unk4[temp_s1->unk1];

        var_v0 = temp_s2->unkC0[1];
        if (temp_s2->unkC0[1] < temp_s2->unkC0[0]) {
            var_v0 = temp_s2->unkC0[0];
        }

        var_a0 = var_v0;

        if (var_a0 >= 9) {
            var_a0 = 8;
        }

        temp_s1->unk4 = vs_main_allocHeapR(var_a0 << 5);
        func_800D6CCC((int*)(&temp_s1->unk10));
        func_800D6CF0(&temp_s1->unk10, temp_s2->unk1, temp_s2->unk0);
        break;

    case 2:
        temp_s2 = &D_800F569C->block5Data->unk4[temp_s1->unk1];
        a2->flags = temp_s2->flags;
        temp_s1->unk2 = func_800CFE1C(
            temp_s2->unkC0, vs_battle_sampleCurve(temp_s2->unk16, temp_s1->unkC));

        if (temp_s1->unk2 >= 9) {
            temp_s1->unk2 = 8;
        }

        if (temp_s1->unk8 <= 0) {
            func_800F9910(temp_s2, a2, temp_s0, temp_s1);
            func_800FA098(temp_s2, a2, temp_s0, temp_s1);
            temp_s1->unk8 = temp_s2->unk34[5][2];
        }

        temp_s1->unk8 = (temp_s1->unk8 - 1);

        func_800FA2B0(temp_s2, a2, temp_s0, temp_s1);
        func_800FA760(temp_s2, a2, temp_s0, temp_s1);

        ++temp_s1->unkC;

        if (temp_s1->unk0 != 0) {
            --temp_s1->unk0;
            if (!temp_s1->unk0) {
                vs_main_freeHeapR(temp_s1->unk4);
                s3 = 0;
            }
        }
        break;

    case 3:
        temp_s1->unk0 = 1;
        break;

    case 4:
        vs_main_freeHeapR(temp_s1->unk4);
        s3 = 0;
        break;
    }

    return s3;
}
