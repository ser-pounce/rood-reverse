#include "common.h"
#include <libspu.h>

extern long D_80030850; /* _spu_isCalled */
extern volatile SpuTransferCallbackProc D_80030898; /* _spu_transferCallback */
extern volatile SpuIRQCallbackProc D_8003089C; /* _spu_IRQCallback */
extern long D_800307E8; /* _spu_EVdma */
extern void _SpuDataCallback(void (*func)(void));
extern void EnterCriticalSection(void);
extern void ExitCriticalSection(void);
extern long CloseEvent(long event);
extern long DisableEvent(long event);

void SpuQuit(void)
{
    if (D_80030850 == 1) {
        D_80030850 = 0;
        EnterCriticalSection();
        D_80030898 = NULL;
        D_8003089C = NULL;
        _SpuDataCallback(NULL);
        CloseEvent(D_800307E8);
        DisableEvent(D_800307E8);
        ExitCriticalSection();
    }
}
