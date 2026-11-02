#include "common.h"
#include "6E4CC.h"
#include "6E4CCShared.h"
#include "146C.h"
#include "4DEA8.h"
#include "battleUnk.h"
#include "src/SLUS_010.40/32154.h"
#include "src/SLUS_010.40/overlay.h"
#include "build/src/include/lbas.h"
#include <abs.h>
#include <rand.h>

void func_800DBF00(func_800E78F4_t* arg0)
{
    vs_battle_actorView_t* data = arg0->unk54;
    func_800E78F4_t* node;

    arg0->unk12F = 0;
    data->unkB_2 = 2;

    if (arg0 == D_800F58BC->unk20) {
        data->unkB_2 = 2;
        D_800F58BC->unk20 = D_800F58BC->unk20->unk1A0 != NULL ? D_800F58BC->unk20->unk1A0
                                                              : D_800F58BC->unk1C;
    }

    if (D_800F58BC->unk1C == arg0) {
        D_800F58BC->unk1C = arg0->unk1A0;
    } else {
        for (node = D_800F58BC->unk1C; node != NULL; node = node->unk1A0) {
            if (node->unk1A0 == arg0) {
                node->unk1A0 = arg0->unk1A0;
                return;
            }
        }
    }

    if (D_800F58BC->unk1C == NULL) {
        D_800F58BC->unk20 = NULL;
    }
}

void func_800DBFE4(func_800E78F4_t* arg0)
{
    if (arg0->unk8E != 0 && ++arg0->unk8E != 0) {
        int frame;

        if (arg0->unk8E < 8) {
            frame = 0;
        } else if (arg0->unk8E < 16) {
            frame = 1;
        } else if (arg0->unk8E < 24) {
            frame = 2;
        } else {
            frame = 3;
        }

        if (arg0->unk8E <= 120) {
            func_800D820C(arg0->unk88, frame + 1);
            return;
        }

        func_800E4C8C(arg0);
        func_800D82CC(arg0);
    }

    if (arg0->unk9A != 0) {
        if (--arg0->unk9A != 0) {
            func_800D820C(arg0->unk88, 4);
        } else {
            func_800D820C(arg0->unk88, 0);
        }
    }

    if (arg0->unk98 != 0) {
        --arg0->unk98;
    }
}

void func_800DC0D0(void)
{
    func_800E78F4_t* state;
    int changed = 0;

    if (D_800F58BC->unk1C == NULL) {
        return;
    }

    state = D_800F58BC->unk1C;

    do {
        vs_battle_actorView_t* data = state->unk54;

        if (state->unk1A4[0].unk0_6 != 2) {
            if (state->unk12F == 0) {
                state->unk130 = 1;
                data->unkB_2 = 1;
                changed = 1;
            } else if (state->unk12F == 16) {
                state->unk130 = -1;
                data->unkB_2 = 2;
                changed = 1;
            }

            state->unk12F += state->unk130;

            if (changed) {
                break;
            }
        }

        state = state->unk1A0;
    } while (state != NULL);
}
