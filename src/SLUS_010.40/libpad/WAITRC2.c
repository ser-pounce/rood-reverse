#include "common.h"

#define RCNT2_COUNT (*(volatile u_short*)0x1F801120)
#define RCNT2_MODE (*(volatile u_short*)0x1F801124)
#define RCNT2_TARGET (*(volatile u_short*)0x1F801128)

extern u_int D_8003FEA0; /* counter value at setRC2wait */
extern u_int D_8003FEA4; /* wait length */

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/WAITRC2", setRC2wait);

int chkRC2wait(void)
{
    u_int now = RCNT2_COUNT;

    if (now < D_8003FEA0) {
        if (RCNT2_TARGET != 0) {
            now += RCNT2_TARGET;
        } else {
            now += 0x10000;
        }
    }
    if (RCNT2_MODE & 0x200) {
        return (now - D_8003FEA0) >= D_8003FEA4;
    }
    return ((now - D_8003FEA0) >> 3) >= D_8003FEA4;
}
