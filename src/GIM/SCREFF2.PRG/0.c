#include "common.h"
#include "0.h"
#include "src/SLUS_010.40/31724.h"
#include "src/BATTLE/BATTLE.PRG/146C.h"
#include "src/BATTLE/BATTLE.PRG/573B8.h"
#include <libgte.h>

void func_800F9800(int arg0)
{
    D_800EB9B4->unk2 = arg0;
    if (D_800EB9B4->unk1 == 0) {
        if (arg0 != 0) {
            D_800EB9B4->unk1 = 1U;
            func_8007DFF0(0x1B, 5, 6);
        }
    } else if (arg0 == 0) {
        D_800EB9B4->unk1 = 0U;
        func_8007E0A8(0x1B, 5, 6);
    }
}

void func_800F986C(void)
{
    int temp_v0;
    int var_s0;
    int x;
    int var_s2;
    int y;
    u_long* temp_s4;
    u_long* var_t2;

    temp_s4 = vs_scratch.unk4;

    for (y = 192; y >= 0; y -= 32) {
        for (var_s2 = 0x100; var_s2 >= 0; var_s2 -= 64) {
            for (x = 0x40; x >= 0; x -= 0x20) {
                int s5;
                if (x == 0x40) {
                    var_t2 = vs_battle_setSprite(
                        0x160, (var_s2 + 2) | ((y + 30) << 16), 0x40000 | 0x40, temp_s4);
                    var_s0 = (y + 0x1C) << 8;
                } else {
                    var_t2 = vs_battle_setSprite(
                        0x160, (var_s2 + x + 0x1E) | ((y + 2) << 16), 0x1C0004, temp_s4);
                    var_s0 = (x + 0x1C) | (y << 8);
                }

                s5 = (((var_s2 + 0x2C0) & 0x3FF) >> 6) | 0x170;

                var_t2[1] = s5 | 0xE1000200;
                var_t2[4] = var_s0;
            }
        }
    }

    for (y = 192; y >= 0; y -= 32) {
        for (x = 0x120; x >= 0; x -= 32) {
            for (var_s0 = 0; var_s0 < 3; ++var_s0) {
                switch (var_s0) {
                case 0:
                    var_t2 = vs_battle_setSprite(
                        0x160, (x + 2) | ((y + 2) << 16), 0x1C001C, temp_s4);
                    break;
                case 1:
                    var_t2 = vs_battle_setSprite(
                        0x160, ((x - 2) & 0xFFFF) | ((y - 2) << 16), 0x200020, temp_s4);
                    break;
                case 2:
                    var_t2 =
                        vs_battle_setSprite(0x60, x | (y << 0x10), 0x200020, temp_s4);
                    break;
                }

                temp_v0 = (((x & 0x1C0) + 0x2C0) & 0x3FF) >> 6;

                if (var_s0 == 0) {
                    temp_v0 |= 0x170;
                    var_t2[1] = temp_v0 | 0xE1000200;
                } else {
                    temp_v0 |= 0x110;
                    var_t2[1] = temp_v0 | 0xE1000200;
                }

                var_t2[4] = (x & 0x20) | (y << 8);
            }
        }
    }

    var_s0 = D_800EB9B4->unk2 - 3;
    var_t2 = vs_scratch.unk0;
    var_t2[0] = ((temp_s4[var_s0] & 0xFFFFFF) | 0x07000000);
    var_t2[1] = 0xE30402C0;
    var_t2[2] = 0xE4077FFF;
    var_t2[3] = 0xE50802C0;
    var_t2[4] = 0x60000000;
    var_t2[5] = 0;
    var_t2[6] = 0xE00140;
    var_t2[7] = 0xE6000001;
    temp_s4[var_s0] = ((u_long)var_t2 << 8) >> 8;
    var_t2 += 8;

    x = vs_main_frameBuf == 0 ? 0x140 : 0;

    var_t2[0] = ((*temp_s4 & 0xFFFFFF) | 0x04000000);
    var_t2[1] = x | 0xE3000000;
    var_t2[2] = (x + 0x13F) | 0xE4037C00;
    var_t2[3] = x | 0xE5000000;
    var_t2[4] = 0xE6000000;

    *temp_s4 = ((u_long)var_t2 << 8) >> 8;
    vs_scratch.unk0 = var_t2 + 5;
}

void func_800F9BC0(short arg0, short arg1)
{
    D_800EB9B4->unk4 = arg0;
    D_800EB9B4->unk6 = arg1;
}
