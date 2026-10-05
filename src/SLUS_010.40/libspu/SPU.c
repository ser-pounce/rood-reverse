#include "common.h"

typedef struct {
    u_short unk0[0xD5];
    volatile u_short spucnt; /* 0x1AA */
} SpuRegs;

typedef union {
    u_short rxx[0x100];
    SpuRegs regs;
} SpuRXX;

extern SpuRXX* D_80030860; /* _spu_RXX: SPU register base */
extern u_long* D_80030870; /* DMA DPCR */
extern u_long* D_80030874; /* SPU delay/size config */
extern int D_80030888; /* _spu_mem_mode_plus: address shift */
extern u_short D_80030878; /* _spu_tsa: transfer start address */
extern int D_8003087C; /* _spu_transMode */
extern int D_80030884; /* _spu_mem_mode */
extern int D_8003088C; /* _spu_mem_mode_unit */
extern int D_80030890; /* _spu_mem_mode_unitM */
extern int _spu_t(int, ...);
extern void func_8001DCD4(u_char*, u_int);
extern int D_800308B0; /* _spu_dma_mode? (0: insert transfer wait) */
extern void (*D_80030898)(void); /* DMA completion callback */
extern void _spu_Fw1ts(void);
extern int DeliverEvent(u_long, u_long);
extern u_long* D_80030864; /* DMA4 MADR */
extern u_long* D_80030868; /* DMA4 BCR */
extern u_long* D_8003086C; /* DMA4 CHCR */
extern void func_8001E504(void);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libspu/SPU", D_80010154);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_init);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", func_8001DCD4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_FiDMA);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_Fr_);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_t);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_Fw);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_Fr);

void _spu_FsetRXX(int reg, u_int addr, int flag)
{
    if (flag == 0) {
        D_80030860->rxx[reg] = addr;
    } else {
        D_80030860->rxx[reg] = addr >> D_80030888;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_FsetRXXa);

u_int _spu_FgetRXXa(int reg, int flag)
{
    u_short addr = D_80030860->rxx[reg];

    if (flag == -1) {
        return addr;
    }
    return addr << D_80030888;
}

void _spu_FsetPCR(int flag)
{
    *D_80030870 &= ~0x70000;
    if (flag) {
        *D_80030870 |= 0x30000;
    } else {
        *D_80030870 |= 0x50000;
    }
}

void func_8001E4DC(void) { *D_80030874 = (*D_80030874 & 0xF0FFFFFF) | 0x20000000; }

void func_8001E504(void) { *D_80030874 = (*D_80030874 & 0xF0FFFFFF) | 0x22000000; }

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_Fw1ts);
