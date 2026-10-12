/* libcd bios.c 1.86. CD_sync, CD_ready, CD_init and CD_datasync follow
 * tgg12321/BushidoBladeDecompile src/main/psxsdk/libcd/bios.c
 * (commit be8fb3d5679f40dd3e92beb177734565cd5b0de6; no license declared) and
 * Xeeynamo/sotn-decomp src/main/psxsdk/libcd/bios.c
 * (commit ddfe818338828624899aaa9caf34cc2851786527; SPDX MIT).
 */
#include "BIOS_internal.h"

static inline void set_alarm(char* name)
{
    D_80039C68.time = VSync(-1) + 0x3C0;
    D_80039C68.count = 0;
    D_80039C68.name = name;
}

static inline int get_alarm(void)
{
    if (D_80039C68.time < VSync(-1) || D_80039C68.count++ > 0x3C0000) {
        std_out_puts(D_800103D0);
        printf(D_800103E0, D_80039C68.name, D_80032220[D_80032219],
            D_800322A0[D_800324D8.sync], D_800322A0[D_800324D8.ready]);
        CD_flush();
        return -1;
    }
    return 0;
}

static inline void callback(void)
{
    int status;
    u_char saved;

    saved = *D_800324C0 & 3;
    while (1) {
        status = func_800209C4();
        if (status == 0) {
            break;
        }
        if ((status & 4) && D_80032200 != 0) {
            D_80032200(D_800324D8.ready, D_80039C58);
        }
        if ((status & 2) && D_800321FC != 0) {
            D_800321FC(D_800324D8.sync, D_80039C50);
        }
    }
    *D_800324C0 = saved;
}

int CD_sync(int mode, u_char* result)
{
    int sync;

    set_alarm("CD_sync");
    while (1) {
        if (get_alarm()) {
            return -1;
        }
        if (CheckCallback()) {
            callback();
        }
        sync = D_800324D8.sync;
        if (sync == CdlComplete || sync == CdlDiskError) {
            D_800324D8.sync = CdlComplete;
            CD_memcpy(result, D_80039C50, 8);
            return sync;
        }
        if (mode != 0) {
            return 0;
        }
    }
}

int CD_ready(int mode, u_char* result)
{
    int c;
    int ready;

    set_alarm("CD_ready");
    while (1) {
        if (get_alarm()) {
            return -1;
        }
        if (CheckCallback()) {
            callback();
        }
        c = D_800324D8.unk2;
        if (c != 0) {
            D_800324D8.unk2 = 0;
            CD_memcpy(result, D_80039C60, 8);
            return c;
        }
        ready = D_800324D8.ready;
        if (ready != 0) {
            D_800324D8.ready = 0;
            CD_memcpy(result, D_80039C58, 8);
            return ready;
        }
        if (mode != 0) {
            return 0;
        }
    }
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS_2", CD_cw);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS_2", CD_vol);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS_2", CD_flush);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS_2", CD_initvol);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS_2", CD_initintr);

int CD_init(void)
{
    u_char v0;

    std_out_puts("CD_init:");
    printf("addr=%08x\n", D_800324DC);
    D_80032219 = 0;
    D_80032218 = 0;
    D_80032200 = 0;
    D_800321FC = 0;
    D_8003220C = 0;
    D_80032208 = 0;
    ResetCallback();
    InterruptCallback(2, func_80022054);
    *D_800324C0 = 1;
    v0 = *D_800324CC & 7;
    if (v0 != 0) {
        do {
            *D_800324C0 = 1;
            *D_800324CC = 7;
            *D_800324C8 = 7;
            v0 = *D_800324CC & 7;
        } while (v0 != 0);
    }
    D_800324D8.ready = D_800324D8.unk2 = 0;
    D_800324D8.sync = CdlComplete;
    *D_800324C0 = 0;
    *D_800324CC = 0;
    *D_800324D0 = 0x1325;
    CD_cw(CdlNop, 0, 0, 0);
    if (D_80032208 & CdlStatShellOpen) {
        CD_cw(CdlNop, 0, 0, 0);
    }
    if (CD_cw(0x0A, 0, 0, 0) != 0) {
        return -1;
    }
    if (CD_cw(CdlDemute, 0, 0, 0) != 0) {
        return -1;
    }
    if (CD_sync(0, 0) != CdlComplete) {
        return -1;
    }
    return 0;
}

int CD_datasync(int mode)
{
    int ret;

    set_alarm("CD_datasync");
    while (1) {
        if (get_alarm()) {
            ret = -1;
            break;
        }
        if (!(*D_80032504 & 0x1000000)) {
            ret = 0;
            break;
        }
        if (mode != 0) {
            ret = 1;
            break;
        }
    }
    return ret;
}

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS_2", CD_getsector);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS_2", CD_getsector2);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS_2", CD_set_test_parmnum);

INCLUDE_ASM("build/src/SLUS_010.40/nonmatchings/libcd/BIOS_2", func_80022054);
