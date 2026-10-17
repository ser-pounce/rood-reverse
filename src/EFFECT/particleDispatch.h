/* Shared textured particle effect entry point. Include after particleSetup.h and
 * particleRender.h; the overlay supplies the entry points. */

#include "src/BATTLE/BATTLE.PRG/5BF94.h"
#include "src/SLUS_010.40/main.h"

int VS_PARTICLE_DISPATCH_FUNCTION(func_800D4910_t* arg0, u_int arg1, int arg2)
{
    func_800FA098_arg0* effect;
    int count;
    short largest;
    func_800FA098_arg1* scratch = (func_800FA098_arg1*)0x1F8001D0;
    func_800FA098_arg3* state = arg0->unk8;
    D_800F53B8_t* battle = D_800F53BC;
    int alive = 1;

    switch (arg1) {
    case 1:
        state = vs_main_allocHeapR(sizeof *state);
        arg0->unk8 = state;
        state->unk1 = arg2 >> 8;
        state->unk0 = arg2;
        state->unkC = 0;
        state->unk8 = 0;
        effect = &D_800F569C->block5Data->unk4[state->unk1];
        largest =
            effect->unkC0[1] < effect->unkC0[0] ? effect->unkC0[0] : effect->unkC0[1];
        count = largest;

        if (count > 8) {
            count = 8;
        }

        state->unk4 = vs_main_allocHeapR(count * 32);
        func_800D6CCC((int*)&state->unk10);
        func_800D6CF0(&state->unk10, effect->unk1, effect->unk0);
        break;

    case 2:
        effect = &D_800F569C->block5Data->unk4[state->unk1];
        scratch->flags = effect->flags;
        state->unk2 = func_800CFE1C(
            effect->unkC0, vs_battle_sampleCurve(effect->unk16, state->unkC));

        if (state->unk2 > 8) {
            state->unk2 = 8;
        }

        if (state->unk8 <= 0) {
            VS_PARTICLE_ORIGIN_FUNCTION(effect, scratch, battle, state);
            VS_PARTICLE_TARGET_FUNCTION(effect, scratch, battle, state);
            state->unk8 = effect->unk34[5][2];
        }

        --state->unk8;
        VS_PARTICLE_CONTROL_FUNCTION(effect, scratch, battle, state);
        VS_PARTICLE_RENDER_FUNCTION(effect, scratch, battle, state);
        ++state->unkC;

        if (state->unk0 != 0) {
            --state->unk0;

            if (state->unk0 == 0) {
                vs_main_freeHeapR(state->unk4);
                alive = 0;
            }
        }
        break;

    case 3:
        state->unk0 = 1;
        break;

    case 4:
        vs_main_freeHeapR(state->unk4);
        alive = 0;
        break;
    }

    return alive;
}

#undef VS_PARTICLE_ORIGIN_FUNCTION
#undef VS_PARTICLE_TARGET_FUNCTION
#undef VS_PARTICLE_CONTROL_FUNCTION
#undef VS_PARTICLE_RENDER_FUNCTION
#undef VS_PARTICLE_DISPATCH_FUNCTION
#undef VS_PARTICLE_CORNER_STATE
