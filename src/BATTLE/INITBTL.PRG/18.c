#include "common.h"
#include "lbas.h"
#include "../../SLUS_010.40/main.h"
#include "../BATTLE.PRG/146C.h"
#include "../BATTLE.PRG/4A0A8.h"
#include "../BATTLE.PRG/573B8.h"

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

extern char D_800FAF7C[0x400];

void func_800CA9C0(void*);

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800F9818);

void _loadSystemDat()
{
    RECT rect;
    RECT* p_hdr;
    System_dat_h* buf;

    buf = (System_dat_h*)vs_main_allocHeapR(VS_SYSTEM_DAT_SIZE);
    vs_main_diskLoadFile(VS_SYSTEM_DAT_LBA, VS_SYSTEM_DAT_SIZE, buf);
    p_hdr = (RECT*)((char*)buf + buf->unk0);
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);
    p_hdr = (RECT*)((char*)buf + buf->unk4);
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);
    p_hdr = (RECT*)((char*)buf + buf->unk8);
    func_80048A64((u_short*)p_hdr + 2, 0xF, 0, p_hdr->x);
    p_hdr = (RECT*)((char*)buf + buf->unkC);
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);
    p_hdr = (RECT*)((char*)buf + buf->unk10);
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);
    p_hdr = (RECT*)((char*)buf + buf->unk14);
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);
    p_hdr = (RECT*)((char*)buf + buf->unk18);
    setRECT(&rect, 0x300, 0xF0, p_hdr->x, p_hdr->y);
    LoadImage(&rect, (u_long*)p_hdr + 1);
    DrawSync(0);
    func_800CA9C0((char*)buf + buf->unk1C);
    vs_main_freeHeapR(buf);
}

void func_800F9AB0() { }

void func_800F9AB8(void) {
    func_800995B0();
}

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800F9AD8);

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800F9CCC);

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800FA0EC);

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800FA35C);

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800FA6B8);

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800FA7B0);

void func_800FAAAC() {
    void* temp_v0;

    D_800F4C08 = 0;
    D_800F4BE2 = 0;
    D_800F4C30 = vs_main_allocHeap(0x1800);
    D_800F4C48 = vs_main_allocHeap(0x80);
    D_800F4C28 = vs_main_allocHeap(0x400);
    vs_main_memcpy(D_800F4C28, D_800FAF7C, 0x400);
}
