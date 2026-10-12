#include "common.h"
#include <stdarg.h>

typedef struct {
    u_short volL;
    u_short volR;
    u_short pitch;
    u_short addr;
    u_short adsr1;
    u_short adsr2;
    u_short envx;
    u_short loopAddr;
} SpuVoiceRegs;

typedef struct {
    u_short unk0[0xD5];
    u_short spucnt; /* 0x1AA */
} SpuRegs;

typedef union {
    u_short rxx[0x100];
    SpuVoiceRegs voice[24];
    SpuRegs regs;
} SpuRXX;

extern volatile SpuRXX* _spu_RXX; /* SPU register base */
extern u_long* D_80030870; /* DMA DPCR */
extern u_long* D_80030874; /* SPU delay/size config */
extern int _spu_mem_mode_plus; /* address shift */
extern u_short _spu_tsa; /* transfer start address */
extern int D_8003087C; /* _spu_transMode */
extern int D_80030880;
extern int D_80030884; /* _spu_mem_mode */
extern int D_8003088C; /* _spu_mem_mode_unit */
extern int D_80030890; /* _spu_mem_mode_unitM */
extern int D_80030894; /* _spu_inTransfer */
extern volatile u_short D_80039BE8[10]; /* _spu_RQ: register request queue */
extern u_char D_800308A0[]; /* 16 zero bytes written to SPU RAM 0x1000 */
extern long _spu_t(long, ...);
extern void func_8001DCD4(u_char*, u_int);
extern int D_800308B0; /* _spu_dma_mode? (0: insert transfer wait) */
extern void (*volatile _spu_transferCallback)(void); /* DMA completion callback */
extern void _spu_Fw1ts(void);
extern int DeliverEvent(u_long, u_long);
extern volatile u_long* D_80030864; /* DMA4 MADR */
extern volatile u_long* D_80030868; /* DMA4 BCR */
extern volatile u_long* D_8003086C; /* DMA4 CHCR */
extern void func_8001E504(void);
extern void func_8001E4DC(void);
extern long D_800308B4; /* transfer address */
extern long D_800308B8; /* transfer block count */
extern void (*volatile D_8003089C)(void); /* _spu_IRQCallback */
extern int printf(const char* fmt, ...);
extern char D_80010154[]; /* "SPU:T/O [%s]\n" */

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libspu/SPU", D_80010154);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_init);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", func_8001DCD4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_FiDMA);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_Fr_);

long _spu_t(long mode, ...)
{
    va_list args;
    u_int i;
    u_short ck;
    u_long count;
    u_long dma;

    va_start(args, mode);
    switch (mode) {
    case 2:
        count = va_arg(args, u_long);
        _spu_tsa = count >> _spu_mem_mode_plus;
        _spu_RXX->rxx[0xD3] = _spu_tsa;
        break;
    case 1:
        D_800308B0 = 0;
        i = 0;
        while (_spu_RXX->rxx[0xD3] != _spu_tsa) {
            if (++i > 0xF00) {
                return -2;
            }
        }
        _spu_RXX->rxx[0xD5] = (_spu_RXX->rxx[0xD5] & ~0x30) | 0x20;
        break;
    case 0:
        D_800308B0 = 1;
        i = 0;
        while (_spu_RXX->rxx[0xD3] != _spu_tsa) {
            if (++i > 0xF00) {
                return -2;
            }
        }
        _spu_RXX->rxx[0xD5] = (_spu_RXX->rxx[0xD5] & ~0x30) | 0x30;
        break;
    case 3:
        if (D_800308B0 == 1) {
            ck = 0x30;
        } else {
            ck = 0x20;
        }
        i = 0;
        while ((_spu_RXX->rxx[0xD5] & 0x30) != ck) {
            if (++i > 0xF00) {
                return -2;
            }
        }
        if (D_800308B0 == 1) {
            func_8001E504();
        } else {
            func_8001E4DC();
        }
        count = va_arg(args, u_long);
        D_800308B4 = count;
        count = va_arg(args, u_long);
        D_800308B8 = count / 64;
        D_800308B8 += (count % 64) ? 1 : 0;
        *D_80030864 = D_800308B4;
        *D_80030868 = (D_800308B8 << 16) | 0x10;
        if (D_800308B0 == 1) {
            dma = 0x1000200;
        } else {
            dma = 0x1000201;
        }
        *D_8003086C = dma;
        break;
    }
    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_Fw);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_Fr);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_FsetRXX);

long _spu_FsetRXXa(long reg, u_long addr)
{
    long r = reg;
    u_short v;

    if (D_80030884 != 0 && addr % D_8003088C != 0) {
        addr += D_8003088C;
        addr &= ~D_80030890;
    }
    v = addr >> _spu_mem_mode_plus;
    switch (r) {
    case -1:
        return v & 0xFFFF;
    case -2:
        return addr;
    default:
        _spu_RXX->rxx[r] = v;
        return addr;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_FgetRXXa);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_FsetPCR);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", func_8001E4DC);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", func_8001E504);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_Fw1ts);
