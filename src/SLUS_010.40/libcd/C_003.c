#include "common.h"
#include <libcd.h>
#include <libapi.h>

extern int D_8003221C;
extern volatile u_char* D_80032524; /* CD-ROM index/status register (0x1F801800) */
extern volatile u_char* D_80032530; /* CD-ROM register 3 (0x1F801803) */

void DsDataCallback(void (*func)());
void* DsReadyCallback(void* func);

void StUnSetRing(void)
{
    EnterCriticalSection();
    if (D_8003221C == 1) {
        DsDataCallback(NULL);
        DsReadyCallback(NULL);
    } else {
        CdDataCallback(NULL);
        CdReadyCallback(NULL);
    }
    *D_80032524 = 0;
    *D_80032530 = 0;
    ExitCriticalSection();
}
