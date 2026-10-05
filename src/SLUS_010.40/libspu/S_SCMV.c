#include "common.h"
#include <libspu.h>

extern u_short* D_80030860; /* _spu_RXX */

void SpuSetCommonMasterVolume(short mvol_left, short mvol_right)
{
    D_80030860[0xC0] = mvol_left & 0x7FFF;
    D_80030860[0xC1] = mvol_right & 0x7FFF;
}
