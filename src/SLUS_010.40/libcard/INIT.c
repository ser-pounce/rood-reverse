#include "common.h"
#include <libapi.h>

extern int ReadInitPadFlag(void);
extern void VSync(int);
extern void InitCARD2(long val);
extern long StartCARD2(void);
extern long StopCARD2(void);
extern void _ExitCard(void);
extern void _copy_memcard_patch(void);
extern void _patch_card(void);
extern void _patch_card2(void);
extern void _patch_card_info(void);

void InitCARD(long val)
{
    int critical;

    ChangeClearPAD(0);
    VSync(0);
    critical = EnterCriticalSection();
    if (ReadInitPadFlag() == 0) {
        val = 0;
    }
    InitCARD2(val);
    _copy_memcard_patch();
    _patch_card();
    _patch_card2();
    _patch_card_info();
    if (critical == 1) {
        ExitCriticalSection();
    }
}

long StartCARD(void)
{
    int critical;

    critical = EnterCriticalSection();
    StartCARD2();
    ChangeClearPAD(0);
    if (critical == 1) {
        ExitCriticalSection();
    }
    return 0;
}

long StopCARD(void)
{
    StopCARD2();
    _ExitCard();
    return 0;
}
