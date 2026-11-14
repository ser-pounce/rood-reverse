#include "common.h"
#include <libcd.h>
#include <stdio.h>

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/C_011", StCdInterrupt);

void func_80022E80(u_long* dst, u_long* src, u_int count)
{
    u_int i = 0;

    if (count != 0) {
        do {
            *dst++ = *src++;
        } while (++i < count);
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/C_011", func_80022EAC);

static inline int ENCODE_BCD(int n) { return ((n / 10) << 4) + (n % 10); }

CdlLOC* CdIntToPos(int i, CdlLOC* p)
{

    i += 150;
    p->sector = ENCODE_BCD(i % 75);
    p->second = ENCODE_BCD(i / 75 % 60);
    p->minute = ENCODE_BCD(i / 75 / 60);
    return p;
}

int CdPosToInt(CdlLOC* p)
{
    char temp_v1 = p->minute;
    char temp_a2 = p->second;
    char temp_a1 = p->sector;
    return (((((((temp_v1 >> 4) * 0xA) + (temp_v1 & 0xF)) * 0x3C)
                 + (((temp_a2 >> 4) * 0xA) + (temp_a2 & 0xF)))
                * 0x4B)
               + (((temp_a1 >> 4) * 0xA) + (temp_a1 & 0xF)))
         - 0x96;
}
