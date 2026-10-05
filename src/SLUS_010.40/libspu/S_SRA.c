#include "common.h"

/* SPU reverb work registers, 0x1F801DC0-0x1F801DFF */
typedef struct {
    u_short dAPF1;
    u_short dAPF2;
    u_short vIIR;
    u_short vCOMB1;
    u_short vCOMB2;
    u_short vCOMB3;
    u_short vCOMB4;
    u_short vWALL;
    u_short vAPF1;
    u_short vAPF2;
    u_short mLSAME;
    u_short mRSAME;
    u_short mLCOMB1;
    u_short mRCOMB1;
    u_short mLCOMB2;
    u_short mRCOMB2;
    u_short dLSAME;
    u_short dRSAME;
    u_short mLDIFF;
    u_short mRDIFF;
    u_short mLCOMB3;
    u_short mRCOMB3;
    u_short mLCOMB4;
    u_short mRCOMB4;
    u_short dLDIFF;
    u_short dRDIFF;
    u_short mLAPF1;
    u_short mRAPF1;
    u_short mLAPF2;
    u_short mRAPF2;
    u_short vLIN;
    u_short vRIN;
} SpuReverbRegs;

typedef struct {
    u_long mask; /* one bit per register, 0 = all */
    SpuReverbRegs regs;
} SpuReverbParam;

typedef struct {
    u_short unk0[0xE0];
    SpuReverbRegs rev; /* 0x1C0 */
} SpuRegs;

extern SpuRegs* D_80030860; /* _spu_RXX: SPU register base */

#define SET_REVERB_REG(bit, reg)                                                         \
    if (all || (mask & (1 << (bit)))) {                                                  \
        D_80030860->rev.reg = param->regs.reg;                                           \
    }

void _spu_setReverbAttr(SpuReverbParam* param)
{
    u_long mask = param->mask;
    int all = mask == 0;

    SET_REVERB_REG(0, dAPF1);
    SET_REVERB_REG(1, dAPF2);
    SET_REVERB_REG(2, vIIR);
    SET_REVERB_REG(3, vCOMB1);
    SET_REVERB_REG(4, vCOMB2);
    SET_REVERB_REG(5, vCOMB3);
    SET_REVERB_REG(6, vCOMB4);
    SET_REVERB_REG(7, vWALL);
    SET_REVERB_REG(8, vAPF1);
    SET_REVERB_REG(9, vAPF2);
    SET_REVERB_REG(10, mLSAME);
    SET_REVERB_REG(11, mRSAME);
    SET_REVERB_REG(12, mLCOMB1);
    SET_REVERB_REG(13, mRCOMB1);
    SET_REVERB_REG(14, mLCOMB2);
    SET_REVERB_REG(15, mRCOMB2);
    SET_REVERB_REG(16, dLSAME);
    SET_REVERB_REG(17, dRSAME);
    SET_REVERB_REG(18, mLDIFF);
    SET_REVERB_REG(19, mRDIFF);
    SET_REVERB_REG(20, mLCOMB3);
    SET_REVERB_REG(21, mRCOMB3);
    SET_REVERB_REG(22, mLCOMB4);
    SET_REVERB_REG(23, mRCOMB4);
    SET_REVERB_REG(24, dLDIFF);
    SET_REVERB_REG(25, dRDIFF);
    SET_REVERB_REG(26, mLAPF1);
    SET_REVERB_REG(27, mRAPF1);
    SET_REVERB_REG(28, mLAPF2);
    SET_REVERB_REG(29, mRAPF2);
    SET_REVERB_REG(30, vLIN);
    SET_REVERB_REG(31, vRIN);
}
