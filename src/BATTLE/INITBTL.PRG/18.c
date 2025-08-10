#include "common.h"
#include "lbas.h"
#include "../../SLUS_010.40/main.h"
#include "../BATTLE.PRG/146C.h"
#include "../BATTLE.PRG/4A0A8.h"
#include "../BATTLE.PRG/573B8.h"
#include <memory.h>

typedef struct {
    size_t unk0;
    size_t unk4;
    size_t unk8;
    size_t unkC;
    size_t unk10;
    size_t unk14;
    size_t unk18;
    size_t unk1C;
} System_dat_h;

void func_800CA9C0(void*);

extern signed char D_800FAF7C[0x400];

void func_800F9818()
{
    int i;
    int var_v0;

    for (i = 0; i < 256; ++i) {
        var_v0 = i;
        if (i < 0) {
            var_v0 = i + 7;
        }
        if (vs_main_skillsLearned[var_v0 >> 3] & (0x80 >> (i - ((var_v0 >> 3) * 8)))) {
            vs_main_skills[i].flags |= 0x8000;
        } else {
            vs_main_skills[i].flags &= 0xFFFF7FFF;
        }
    }
}

void _loadSystemDat()
{
    RECT rect;
    RECT* p_hdr;
    System_dat_h* buf;

    buf = (System_dat_h*)vs_main_allocHeapR(VS_SYSTEM_DAT_SIZE);
    vs_main_diskLoadFile(VS_SYSTEM_DAT_LBA, VS_SYSTEM_DAT_SIZE, buf);
    p_hdr = (RECT*)((signed char*)buf + buf->unk0);
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);
    p_hdr = (RECT*)((signed char*)buf + buf->unk4);
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);
    p_hdr = (RECT*)((signed char*)buf + buf->unk8);
    func_80048A64((u_short*)p_hdr + 2, 0xF, 0, p_hdr->x);
    p_hdr = (RECT*)((signed char*)buf + buf->unkC);
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);
    p_hdr = (RECT*)((signed char*)buf + buf->unk10);
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);
    p_hdr = (RECT*)((signed char*)buf + buf->unk14);
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);
    p_hdr = (RECT*)((signed char*)buf + buf->unk18);
    setRECT(&rect, 0x300, 0xF0, p_hdr->x, p_hdr->y);
    LoadImage(&rect, (u_long*)p_hdr + 1);
    DrawSync(0);
    func_800CA9C0((signed char*)buf + buf->unk1C);
    vs_main_freeHeapR(buf);
}

void func_800F9AB0() { }

void func_800F9AB8() { func_800995B0(); }

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800F9AD8);

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800F9CCC);

// https://decomp.me/scratch/b3iic
INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800FA0EC);

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800FA35C);

void func_800FA6B8()
{
    vs_main_bzero(D_800F1CE0, 0x20);
    vs_main_bzero(&D_800F1BF8, sizeof(D_800F1BF8));
    vs_main_bzero(D_800F1CC8, 0xC);
    vs_main_bzero(D_800F1BF0, 8);
    vs_main_bzero(&vs_battle_manualDisplayState, sizeof(vs_battle_manualDisplayState));
    D_800F1BA8 = vs_main_allocHeap(0x800);
    D_800F1BAC = vs_main_allocHeap(0x300);
    D_800F1CBC = vs_main_allocHeap(0x80);
    D_800F1BBE = -1;
    D_800F1BA4 = 0;
    D_800F1BB6 = 0;
    D_800F1CD8 = 0;
    D_800F1BC0 = 0;
    D_800F1CD6 = 1;
    D_800F1CD4 = 8;
    func_8008E88C();
    func_8008B6B4();
    func_8008EB30(D_800F1CE0);
}

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800FA7B0);

void func_800FAAAC()
{
    D_800F4C08 = 0;
    D_800F4BE2 = 0;
    D_800F4C30 = vs_main_allocHeap(0x1800);
    D_800F4C48 = vs_main_allocHeap(0x80);
    D_800F4C28 = vs_main_allocHeap(0x400);
    vs_main_memcpy(D_800F4C28, D_800FAF7C, 0x400);
}
