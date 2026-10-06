#include "common.h"

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

extern volatile SpuRXX* D_80030860; /* _spu_RXX: SPU register base */
extern u_long* D_80030870; /* DMA DPCR */
extern u_long* D_80030874; /* SPU delay/size config */
extern int D_80030888; /* _spu_mem_mode_plus: address shift */
extern u_short D_80030878; /* _spu_tsa: transfer start address */
extern int D_8003087C; /* _spu_transMode */
extern int D_80030880;
extern int D_80030884; /* _spu_mem_mode */
extern int D_8003088C; /* _spu_mem_mode_unit */
extern int D_80030890; /* _spu_mem_mode_unitM */
extern int D_80030894; /* _spu_inTransfer */
extern volatile u_short D_80039BE8[10]; /* _spu_RQ: register request queue */
extern u_char D_800308A0[]; /* 16 zero bytes written to SPU RAM 0x1000 */
extern int _spu_t(int, ...);
extern void func_8001DCD4(u_char*, u_int);
extern int D_800308B0; /* _spu_dma_mode? (0: insert transfer wait) */
extern void (*volatile D_80030898)(void); /* DMA completion callback */
extern void _spu_Fw1ts(void);
extern int DeliverEvent(u_long, u_long);
extern volatile u_long* D_80030864; /* DMA4 MADR */
extern volatile u_long* D_80030868; /* DMA4 BCR */
extern volatile u_long* D_8003086C; /* DMA4 CHCR */
extern void func_8001E504(void);
extern void (*volatile D_8003089C)(void); /* _spu_IRQCallback */
extern int printf(const char* fmt, ...);
extern char D_80010154[]; /* "SPU:T/O [%s]\n" */

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libspu/SPU", D_80010154);

int _spu_init(int mode)
{
    int i;
    u_int count;

    *D_80030870 |= 0xB0000;
    D_8003087C = 0;
    D_80030880 = 0;
    D_80030878 = 0;
    D_80030860->rxx[0xC0] = 0;
    D_80030860->rxx[0xC1] = 0;
    D_80030860->regs.spucnt = 0;
    _spu_Fw1ts();
    D_80030860->rxx[0xC0] = 0;
    D_80030860->rxx[0xC1] = 0;
    count = 0;
    while (D_80030860->rxx[0xD7] & 0x7FF) {
        if (++count > 0xF00) {
            printf(D_80010154, "wait (reset)");
            break;
        }
    }
    D_80030884 = 2;
    D_80030888 = 3;
    D_8003088C = 8;
    D_80030890 = 7;
    D_80030860->rxx[0xD6] = 4;
    D_80030860->rxx[0xC2] = 0;
    D_80030860->rxx[0xC3] = 0;
    D_80030860->rxx[0xC6] = 0xFFFF;
    D_80030860->rxx[0xC7] = 0xFFFF;
    D_80030860->rxx[0xCC] = 0;
    D_80030860->rxx[0xCD] = 0;
    for (i = 0; i < 10; i++) {
        D_80039BE8[i] = 0;
    }
    if (mode == 0) {
        D_80030878 = 0x200;
        D_80030860->rxx[0xC8] = 0;
        D_80030860->rxx[0xC9] = 0;
        D_80030860->rxx[0xCA] = 0;
        D_80030860->rxx[0xCB] = 0;
        D_80030860->rxx[0xD8] = 0;
        D_80030860->rxx[0xD9] = 0;
        D_80030860->rxx[0xDA] = 0;
        D_80030860->rxx[0xDB] = 0;
        func_8001DCD4(D_800308A0, 0x10);
        for (i = 0; i < 24; i++) {
            D_80030860->voice[i].volL = 0;
            D_80030860->voice[i].volR = 0;
            D_80030860->voice[i].pitch = 0x3FFF;
            D_80030860->voice[i].addr = 0x200;
            D_80030860->voice[i].adsr1 = 0;
            D_80030860->voice[i].adsr2 = 0;
        }
        D_80030860->rxx[0xC4] = 0xFFFF;
        D_80030860->rxx[0xC5] = 0xFF;
        _spu_Fw1ts();
        _spu_Fw1ts();
        _spu_Fw1ts();
        _spu_Fw1ts();
        D_80030860->rxx[0xC6] = 0xFFFF;
        D_80030860->rxx[0xC7] = 0xFF;
        _spu_Fw1ts();
        _spu_Fw1ts();
        _spu_Fw1ts();
        _spu_Fw1ts();
    }
    D_80030894 = 1;
    D_80030860->regs.spucnt = 0xC000;
    D_80030898 = NULL;
    D_8003089C = NULL;
    return 0;
}

void func_8001DCD4(u_char* addr, u_int size)
{
    int n;
    int i;
    u_int count;
    u_short status;
    u_short cnt;
    u_short* p;

    status = D_80030860->rxx[0xD7] & 0x7FF;
    D_80030860->rxx[0xD3] = D_80030878;
    p = (u_short*)addr;
    _spu_Fw1ts();
    while (size != 0) {
        n = size > 0x40 ? 0x40 : size;
        i = 0;
        if (n > 0) {
            do {
                D_80030860->rxx[0xD4] = *p++;
                i += 2;
            } while (i < n);
        }
        cnt = D_80030860->regs.spucnt;
        D_80030860->regs.spucnt = (cnt & ~0x30) | 0x10;
        _spu_Fw1ts();
        count = 0;
        while (D_80030860->rxx[0xD7] & 0x400) {
            if (++count > 0xF00) {
                printf(D_80010154, "wait (wrdy H -> L)");
                break;
            }
        }
        _spu_Fw1ts();
        size -= n;
        _spu_Fw1ts();
    }
    cnt = D_80030860->regs.spucnt;
    D_80030860->regs.spucnt = cnt & ~0x30;
    count = 0;
    while ((D_80030860->rxx[0xD7] & 0x7FF) != status) {
        if (++count > 0xF00) {
            printf(D_80010154, "wait (dmaf clear/W)");
            break;
        }
    }
}

void _spu_FiDMA(void)
{
    u_int i;

    if (D_800308B0 == 0) {
        _spu_Fw1ts();
    }
    D_80030860->regs.spucnt &= ~0x30;
    i = 0;
    while (D_80030860->regs.spucnt & 0x30) {
        if (++i > 0xF00) {
            break;
        }
    }
    if (D_80030898) {
        D_80030898();
    } else {
        DeliverEvent(0xF0000009, 0x20);
    }
}

void _spu_Fr_(u_char* addr, u_short spuAddr, int blocks)
{
    D_80030860->rxx[0xD3] = spuAddr;
    _spu_Fw1ts();
    D_80030860->regs.spucnt |= 0x30;
    _spu_Fw1ts();
    func_8001E504();
    *D_80030864 = (u_long)addr;
    *D_80030868 = (blocks << 16) | 0x10;
    D_800308B0 = 1;
    *D_8003086C = 0x01000200;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libspu/SPU", _spu_t);

u_int _spu_Fw(u_char* addr, u_int size)
{
    if (D_8003087C == 0) {
        _spu_t(2, D_80030878 << D_80030888);
        _spu_t(1);
        _spu_t(3, addr, size);
    } else {
        func_8001DCD4(addr, size);
    }
    return size;
}

u_int _spu_Fr(u_char* addr, u_int size)
{
    _spu_t(2, D_80030878 << D_80030888);
    _spu_t(0);
    _spu_t(3, addr, size);
    return size;
}

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

void _spu_Fw1ts(void)
{
    volatile int i;
    volatile int wait = 13;

    for (i = 0; i < 60; i += 1) {
        wait *= 13;
    }
}
