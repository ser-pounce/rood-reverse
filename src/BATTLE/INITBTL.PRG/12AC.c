#include "common.h"
#include "../../SLUS_010.40/main.h"
#include "../BATTLE.PRG/4A0A8.h"
#include "../BATTLE.PRG/573B8.h"

extern signed char D_800FAF7C[0x400];

void _initScriptFunctionTable(void)
{
    D_800F4C08 = 0;
    D_800F4BE2 = 0;
    D_800F4C30 = vs_main_allocHeap(0x1800);
    D_800F4C48 = vs_main_allocHeap(0x80);
    D_800F4C28 = vs_main_allocHeap(0x400);
    vs_main_memcpy(D_800F4C28, D_800FAF7C, 0x400);
}
