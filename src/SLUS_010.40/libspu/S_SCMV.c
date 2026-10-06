#include "spu.h"

void SpuSetCommonMasterVolume(short mvol_left, short mvol_right)
{
    _spu_RXX->mvolL = mvol_left & 0x7FFF;
    _spu_RXX->mvolR = mvol_right & 0x7FFF;
}
