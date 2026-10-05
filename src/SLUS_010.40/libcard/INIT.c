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

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcard/INIT", InitCARD);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcard/INIT", StartCARD);

long StopCARD(void)
{
    StopCARD2();
    _ExitCard();
    return 0;
}
