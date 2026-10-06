#include "spu.h"

extern int ResetCallback(void);
extern void _spu_init(int mode);
extern void _spu_FsetRXX(int reg, u_int addr, int flag);
extern void _spu_FiDMA(void);
extern void _SpuDataCallback(void (*func)(void));
extern void EnterCriticalSection(void);
extern void ExitCriticalSection(void);
extern long OpenEvent(u_long desc, long spec, long mode, long (*func)());
extern long EnableEvent(long event);

extern long D_800307E8; /* _spu_EVdma */
extern int D_800307EC; /* _spu_keystat */
extern int D_800307F0; /* _spu_trans_mode */
extern int D_800307F4; /* _spu_rev_flag */
extern int D_800307F8; /* _spu_rev_reserve_wa */
extern int D_800307FC; /* _spu_rev_offsetaddr */
extern int D_80030814; /* _spu_RQvoice */
extern int D_80030818; /* _spu_RQmask */
extern u_short D_8003081C[24]; /* _spu_voice_centerNote */
extern int D_8003084C; /* _spu_env */
extern int D_80030850; /* _spu_isCalled */
extern int D_8003087C; /* _spu_transMode */
extern int D_80030CD0[]; /* _spu_rev_startaddr */

void _SpuInit(int mode)
{
    int i;

    ResetCallback();
    _spu_init(mode);
    if (mode == 0) {
        for (i = 0; i < 24; i++) {
            D_8003081C[i] = 0xC000;
        }
    }
    SpuStart();
    D_800307F4 = 0;
    D_800307F8 = 0;
    _spu_rev_attr.mode = 0;
    _spu_rev_attr.depth.left = 0;
    _spu_rev_attr.depth.right = 0;
    _spu_rev_attr.delay = 0;
    _spu_rev_attr.feedback = 0;
    D_800307FC = D_80030CD0[0];
    _spu_FsetRXX(0xD1, D_800307FC, 0);
    _spu_AllocBlockNum = 0;
    _spu_AllocLastNum = 0;
    _spu_memList = NULL;
    D_800307F0 = 0;
    D_8003087C = 0;
    D_800307EC = 0;
    D_80030818 = 0;
    D_80030814 = 0;
    D_8003084C = 0;
}

void SpuStart(void)
{
    long event;

    if (D_80030850 == 0) {
        D_80030850 = 1;
        EnterCriticalSection();
        _SpuDataCallback(_spu_FiDMA);
        event = OpenEvent(0xF0000009, 0x20, 0x2000, NULL);
        D_800307E8 = event;
        EnableEvent(event);
        ExitCriticalSection();
    }
}
