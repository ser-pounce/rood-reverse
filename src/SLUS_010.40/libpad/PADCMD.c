#include "pad.h"

void func_8002D608(padPort*);
void func_8002D61C(padPort*, int);
void func_8002D63C(padPort*, int);
void func_8002D65C(padPort*, int);
void func_8002D67C(padPort*);

extern void (*D_800335A0)(padPort*);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", _padSetAct);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", _padSetCmd);

void _padSendAtLoadInfo(padPort* port)
{
    switch (port->unk46) {
    case 2:
        func_8002D608(port);
        break;

    case 3:
        func_8002D61C(port, port->unkE4);
        break;

    case 4:
        func_8002D65C(port, port->unk47);
        break;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", _padRecvAtLoadInfo);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", _padGetActSize);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", _padLoadActInfo);

void func_8002CEB0(padPort* port)
{
    switch (port->unk46) {
    case 2:
        func_8002D61C(port, port->unk47);
        break;

    case 3:
        func_8002D63C(port, port->unk47);
        break;

    case 4:
        if (port->unk48 == 0) {
            func_8002D65C(port, port->unk47);
        } else {
            func_8002D67C(port);
        }
        break;
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", func_8002CF58);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", _padSetActAlign);

void func_8002D3B8(padPort* arg0)
{
    arg0->unk2C = arg0->unk20;
    arg0->unk37 = 0x4D;
    arg0->unk36 = 6;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", func_8002D3D4);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", _padSetMainMode);

void func_8002D534(padPort* port)
{
    int mode = port->unk46;

    switch (mode) {
    case 2:
        port->unk37 = 0x44;
        port->unk2C = port->unk51;
        port->unk36 = mode;
        break;

    case 3:
        port->unk37 = 0x4D;
        port->unk2C = port->unk5D;
        port->unk36 = 6;
        break;
    }
}

int func_8002D588(padPort* port)
{
    if (port->unk53) {
        if (port->unk46 == 2) {
            return 1;
        }

        port->unk46 = 0xFE;
    } else {
        D_800335A0(port);
    }

    return 0;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", _padCmdParaMode);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", func_8002D608);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", func_8002D61C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", func_8002D63C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", func_8002D65C);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libpad/PADCMD", func_8002D67C);
