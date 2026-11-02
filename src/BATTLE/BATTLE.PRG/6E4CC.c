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

void func_800D6CCC(int* arg0)
{
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[4] = 0;
    arg0[5] = 0;
    arg0[6] = 0;
    arg0[7] = 0;
}

void func_800D6CF0(func_800D6CF_t* arg0, int textureIndex, int arg2)
{
    arg0->textureIndex = textureIndex;
    arg0->unk18 = (u_char*)D_800F569C->block2Data + D_800F569C->block2Data[arg2 + 2];
    arg0->unkE = 0;
    arg0->unk6 = 0;
}

void func_800D6D24(func_800D6CF_t* arg0)
{
    if (arg0->unk6 != 0) {
        arg0->unk6 -= 2;
        if (arg0->unk6 != 0) {
            return;
        }
    }

    while (1) {
        int w = *(int*)(arg0->unk18 + arg0->unkE);

        switch (w & 0xF0000000) {
        case 0:
            arg0->textureInfo =
                D_800F569C->textureInfoTable[arg0->textureIndex] + (w & 0xFFFF);
            *(short*)&arg0->unk6 = (w >> 16) & 0x3FFF;
            arg0->unkE += 4;
            return;
        case 0x10000000:
            arg0->unk8 = (w << 18) >> 18;
            arg0->unkA = (w << 4) >> 18;
            arg0->unkE += 4;
            break;
        case 0x20000000:
            arg0->unkE = 0;
            break;
        case 0x30000000:
            return;
        }
    }
}

void func_800D6E24(func_800D2904_t* node, void* arg1) { func_800D6E44(node); }
