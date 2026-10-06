#include "pad.h"

extern padPort D_8003FCC0[];

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADPORTD", PadInitDirect);

void func_8002DE24(padPort* port)
{
    int i;
    u_char* slot;

    if (port->unk49) {
        slot = port->unk5D;
        port->unk49 = 0;
        port->unk46 = 0;
        port->unkE6 = 0;
        port->unk14 = 0;
        port->unk18 = 0;
        port->unkE3 = 0;
        port->unkE4 = 0;
        port->unkE6 = 0;
        port->unkE9 = 0;
        port->unkEA = 0;
        port->unk0 = 0;
        port->unk4 = NULL;
        port->unk8 = 0;

        for (i = 0; i < 6; ++i) {
            *slot++ = 0xFF;
        }
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADPORTD", func_8002DE8C);

void func_8002DF80(padPort* port)
{
    port->unk38 = port->unk37;
    port->unk37 = 0;
}

int func_8002DF90(padPort* port)
{
    int i = port->unk45 - 3;

    switch (port->unk37) {
    case 0:
        if ((i < 6) && (port->unk57[i] == 0)) {
            return 0;
        }
        return i < port->unk34 ? port->unk28[i] : 0;

    case 0x4D:
        return i < port->unk36 ? port->unk2C[i] : 0xFF;

    default:
        return i < port->unk36 ? port->unk2C[i] : 0;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADPORTD", func_8002E04C);

int func_8002E2C8(padPort* port)
{
    int i;

    for (i = 0; i < 2; ++i) {
        if (port == &D_8003FCC0[i]) {
            return (i + 1) * 16;
        }
    }

    return 0xFF;
}

padPort* func_8002E300(int port) { return port & 0xF0 ? &D_8003FCC0[1] : D_8003FCC0; }
