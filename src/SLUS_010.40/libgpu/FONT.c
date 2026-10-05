#include "common.h"
#include <libgte.h>
#include <libgpu.h>
#include <memory.h>

typedef struct {
    TILE tile; /* 0x00: background */
    DR_MODE mode; /* 0x10 */
    int maxchars; /* 0x1C */
    SPRT_8* sprt; /* 0x20 */
    char* text; /* 0x24 */
    int count; /* 0x28 */
    int noclip; /* 0x2C */
} FntStream;

extern FntStream D_80032864[8];
extern u_long D_800329EC[]; /* font clut + 4-bit texture */
extern int D_800329E4; /* number of opened streams */
extern int D_800333EC; /* characters allocated */
extern char D_80039EA0[0x400];
extern SPRT_8 D_8003A2A0[0x400];
extern u_short D_8003E2A0; /* font tpage */
extern u_short D_8003E2A2; /* font clut */
extern int D_800329E8; /* stream printed by the GPU debug printf */
extern int (*D_80033440)(); /* GPU debug printf */

void SetDumpFnt(int id)
{
    if (id >= 0 && id <= D_800329E4) {
        D_800329E8 = id;
        D_80033440 = FntPrint;
    }
}

void FntLoad(int tx, int ty)
{
    D_8003E2A2 = LoadClut2(D_800329EC, tx, ty + 0x80);
    D_8003E2A0 = LoadTPage(D_800329EC + 0x80, 0, 0, tx, ty, 0x80, 0x20);
    D_800329E4 = 0;
    memset(D_80032864, 0, sizeof(D_80032864));
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/FONT", FntOpen);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/FONT", FntFlush);

INCLUDE_RODATA("build/src/SLUS_010.40/nonmatchings/libgpu/FONT", D_800107C4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libgpu/FONT", FntPrint);
