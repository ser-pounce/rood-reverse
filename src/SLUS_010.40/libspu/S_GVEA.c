#include "common.h"
#include <libspu.h>

typedef struct {
    u_short volL;
    u_short volR;
    u_short pitch;
    u_short addr;
    u_short adsr1;
    u_short adsr2;
    u_short envx;
    u_short loopAddr;
} SpuVoiceRegs;

extern SpuVoiceRegs* D_80030860; /* _spu_RXX */

void SpuGetVoiceEnvelope(int vNum, short* envx) { *envx = D_80030860[vNum].envx; }
