/* Shared particle allocation and update lifecycle; include after particleSetup.h. */

int VS_PARTICLE_DISPATCH_FUNCTION(func_800D4910_t* arg0, u_int arg1, int arg2)
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
#ifdef VS_PARTICLE_UNTEXTURED
        /* This variant uses only the state prefix, without texture animation. */
        temp_s1 = vs_main_allocHeapR(0x10);
#else
        temp_s1 = vs_main_allocHeapR(0x30);
#endif
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
#ifndef VS_PARTICLE_UNTEXTURED
        func_800D6CCC((int*)(&temp_s1->unk10));
        func_800D6CF0(&temp_s1->unk10, temp_s2->unk1, temp_s2->unk0);
#endif
        break;

    case 2:
        temp_s2 = &D_800F569C->block5Data->unk4[temp_s1->unk1];
#ifdef VS_PARTICLE_UNTEXTURED
        a2->flags = temp_s2->flags & 0x3FFFFFF;
#else
        a2->flags = temp_s2->flags;
#endif
        temp_s1->unk2 = func_800CFE1C(
            temp_s2->unkC0, vs_battle_sampleCurve(temp_s2->unk16, temp_s1->unkC));

        if (temp_s1->unk2 >= 9) {
            temp_s1->unk2 = 8;
        }

        if (temp_s1->unk8 <= 0) {
            VS_PARTICLE_ORIGIN_FUNCTION(temp_s2, a2, temp_s0, temp_s1);
            VS_PARTICLE_TARGET_FUNCTION(temp_s2, a2, temp_s0, temp_s1);
            temp_s1->unk8 = temp_s2->unk34[5][2];
        }

        temp_s1->unk8 = (temp_s1->unk8 - 1);

        VS_PARTICLE_CONTROL_FUNCTION(temp_s2, a2, temp_s0, temp_s1);
        VS_PARTICLE_RENDER_FUNCTION(temp_s2, a2, temp_s0, temp_s1);

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

#undef VS_PARTICLE_ORIGIN_FUNCTION
#undef VS_PARTICLE_TARGET_FUNCTION
#undef VS_PARTICLE_CONTROL_FUNCTION
#undef VS_PARTICLE_RENDER_FUNCTION
#undef VS_PARTICLE_DISPATCH_FUNCTION
#undef VS_PARTICLE_CORNER_STATE

#undef VS_PARTICLE_UNTEXTURED
