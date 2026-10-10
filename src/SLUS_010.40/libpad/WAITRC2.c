#include "common.h"
#include "WAITRC2.h"

#define RCNT2_COUNT (*(volatile u_short*)0x1F801120)
#define RCNT2_MODE (*(volatile u_short*)0x1F801124)
#define RCNT2_TARGET (*(volatile u_short*)0x1F801128)

extern u_int D_8003FEA0; /* counter value at setRC2wait */
extern u_int D_8003FEA4; /* wait length */

void setRC2wait(u_int wait)
{
    D_8003FEA4 = wait;
    D_8003FEA0 = RCNT2_COUNT;
}

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
