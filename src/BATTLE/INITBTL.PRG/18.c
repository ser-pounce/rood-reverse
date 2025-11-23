#include "common.h"
#include "lbas.h"
#include "../../SLUS_010.40/main.h"
#include "../BATTLE.PRG/146C.h"
#include "../BATTLE.PRG/30D14.h"
#include "../BATTLE.PRG/4A0A8.h"
#include "../BATTLE.PRG/573B8.h"
#include "../BATTLE.PRG/5BF94.h"
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
void func_800FA6B8(void);
void func_800FAAAC(void);

extern signed char D_800FAF7C[0x400];

void func_800F9818(void)
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

void _loadSystemDat(void)
{
    RECT rect;
    RECT* p_hdr;
    System_dat_h* buf;

    buf = (System_dat_h*)vs_main_allocHeapR(VS_SYSTEM_DAT_SIZE);
    vs_main_diskLoadFile(VS_SYSTEM_DAT_LBA, VS_SYSTEM_DAT_SIZE, buf);

    p_hdr = (void*)buf + buf->unk0;
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);

    p_hdr = (void*)buf + buf->unk4;
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);

    p_hdr = (void*)buf + buf->unk8;
    func_80048A64((u_short*)p_hdr + 2, 0xF, 0, p_hdr->x);

    p_hdr = (RECT*)((signed char*)buf + buf->unkC);
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);

    p_hdr = (void*)buf + buf->unk10;
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);

    p_hdr = (void*)buf + buf->unk14;
    setRECT(&rect, p_hdr->x, p_hdr->y, p_hdr->w, p_hdr->h);
    LoadImage(&rect, (u_long*)p_hdr + 2);
    DrawSync(0);

    p_hdr = (void*)buf + buf->unk18;
    setRECT(&rect, 0x300, 0xF0, p_hdr->x, p_hdr->y);
    LoadImage(&rect, (u_long*)p_hdr + 1);
    DrawSync(0);

    func_800CA9C0((void*)buf + buf->unk1C);
    vs_main_freeHeapR(buf);
}

void func_800F9AB0(void) { }

void func_800F9AB8(void) { func_800995B0(); }

void func_800CB660(int);

void func_800F9AD8(void)
{
    int j;
    int i;
    vs_battle_actor2* temp_s0 = vs_battle_characterState->unk3C;
    D_80060068_t3* s1 = &D_80060068.unk0;

    temp_s0->currentHP = s1->currentHP;
    temp_s0->maxHP = s1->maxHP;
    temp_s0->currentMP = s1->currentMP;
    temp_s0->maxMP = s1->maxMP;
    temp_s0->unk22 = s1->unkC;
    temp_s0->unk24 = s1->unkE;
    temp_s0->unk26 = s1->unk10;
    temp_s0->unk28 = s1->unk12;
    temp_s0->unk2A = s1->unk14;
    temp_s0->unk2C = s1->unk16;
    temp_s0->risk = s1->risk;
    *(short*)&temp_s0->flags = s1->flags;

    func_80086FA8(s1->unk1C, temp_s0);

    for (i = 0; i < 8; ++i) {
        temp_s0->unk94C[i] = s1->unk20[i];
    }

    for (i = 0; i < 6; ++i) {
        temp_s0->hitLocations[i].unk0 = s1->hitLocations[i].unk0;
        temp_s0->hitLocations[i].unk2 = s1->hitLocations[i].unk2;

        for (j = 0; j < 4; ++j) {
            temp_s0->hitLocations[i].types[j] = s1->hitLocations[i].types[j];
        }

        for (j = 0; j < 8; ++j) {
            temp_s0->hitLocations[i].affinities[j] = s1->hitLocations[i].affinities[j];
        }
    }

    vs_battle_characterState->unk20 = s1->unk7C;

    if (s1->unk7C & 1) {
        func_8009D934(0, 1, 2, i);
        func_800CB660(1);
    }

    D_80060068.unk0.unk0 = 0;
    D_800F19D0[5] = s1->unk80;
    D_800F19D0[8] = s1->unk84;
}

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800F9CCC);

// https://decomp.me/scratch/b3iic
INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800FA0EC);

// https://decomp.me/scratch/zPzit
INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800FA35C);

void func_800FA6B8(void)
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
    vs_battle_sceneBuffer = NULL;
    D_800F1CD6 = 1;
    D_800F1CD4 = 8;
    func_8008E88C();
    func_8008B6B4();
    func_8008EB30(D_800F1CE0);
}

INCLUDE_ASM("build/src/BATTLE/INITBTL.PRG/nonmatchings/18", func_800FA7B0);

void func_800FAAAC(void)
{
    D_800F4C08 = 0;
    D_800F4BE2 = 0;
    D_800F4C30 = vs_main_allocHeap(0x1800);
    D_800F4C48 = vs_main_allocHeap(0x80);
    D_800F4C28 = vs_main_allocHeap(0x400);
    vs_main_memcpy(D_800F4C28, D_800FAF7C, 0x400);
}
