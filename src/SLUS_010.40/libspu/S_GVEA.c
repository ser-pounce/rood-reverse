#include "spu.h"

void SpuGetVoiceEnvelope(int vNum, short* envx)
{
    *envx = (&_spu_RXX->voice[vNum])->envx;
}
