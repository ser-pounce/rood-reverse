#include "common.h"

extern unsigned char D_80075CC4[];

void DecDCTvlcBuild(unsigned short* arg0)
{
    int i;
    int j;
    int var_a1;
    unsigned char* var_a2;
    unsigned char* var_a3;

    i = 0;
    var_a3 = D_80075CC4;
    var_a2 = (unsigned char*)arg0;
    do {
        int var_v0 = *var_a3;
        var_a3 += 1;
        var_a1 = var_v0 & 0xFF;

        if (var_a1 < 0xF0u) {
            if (i != 0) {
                for (; var_a1 >= 0; --var_a1) {
                    *var_a2 = *(var_a2 - i);
                    var_a2 += 1;
                }
            } else
                for (; var_a1 >= 0; --var_a1) {
                    *var_a2 = *var_a3++;
                    var_a2 += 1;
                }
        } else {
            i = 0;
            if (var_a1 != 0xF0) {
                var_v0 = (var_a1 << 8) | *var_a3++;
                i = var_v0 + 0xFFFF0F01;
            }
        }
    } while (i != 0xF00);

    for (j = 4; j <= 0x87FF; ++j) {
        arg0[j] = (arg0[j] ^ arg0[j - 4]);
    }
}
