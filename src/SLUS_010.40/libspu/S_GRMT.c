#include "common.h"
#include <libspu.h>

extern long D_80030804; /* _spu_rev_attr.mode */

void SpuGetReverbModeType(long* mode) { *mode = D_80030804; }
