#include "common.h"
#include <libspu.h>

extern void _spu_FiDMA(void);
extern void _SpuDataCallback(void (*func)(void));
extern void EnterCriticalSection(void);
extern void ExitCriticalSection(void);
extern long OpenEvent(u_long desc, long spec, long mode, long (*func)());
extern long EnableEvent(long event);

extern long D_800307E8; /* _spu_EVdma */
extern int D_80030850; /* _spu_isCalled */

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/S_INI", _SpuInit);

void SpuStart(void)
{
    long event;

    if (D_80030850 == 0) {
        D_80030850 = 1;
        EnterCriticalSection();
        _SpuDataCallback(_spu_FiDMA);
        event = OpenEvent(0xF0000009, 0x20, 0x2000, NULL);
        D_800307E8 = event;
        EnableEvent(event);
        ExitCriticalSection();
    }
}
