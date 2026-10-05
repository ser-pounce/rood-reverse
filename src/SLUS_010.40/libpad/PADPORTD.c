#include "common.h"

typedef struct {
    u_char unk0[2];
    u_char unk2;
    u_char unk3;
    u_char unk4;
} padPort_act;

typedef struct padPort {
    int unk0;
    padPort_act* unk4;
    int unk8;
    struct padPort* unkC;
    struct padPort* unk10;
    int unk14;
    int unk18;
    char unk1C[0xC];
    u_char* unk28;
    u_char* unk2C;
    u_char* unk30;
    u_char unk34;
    u_char unk35;
    u_char unk36;
    u_char unk37;
    u_char unk38;
    char unk39[3];
    u_char* unk3C;
    u_char* unk40;
    char unk44;
    u_char unk45;
    u_char unk46;
    char unk47[2];
    u_char unk49;
    char unk4A[0xD];
    u_char unk57[6];
    u_char unk5D[6];
    char unk63[0x80];
    u_char unkE3;
    u_char unkE4;
    char unkE5;
    u_short unkE6;
    u_char unkE8;
    u_char unkE9;
    u_char unkEA;
    char unkEB[5];
} padPort;

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
