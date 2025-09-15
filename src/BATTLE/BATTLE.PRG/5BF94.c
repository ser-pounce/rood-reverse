#include "common.h"
#include "5BF94.h"
#include "146C.h"
#include "2842C.h"
#include "573B8.h"
#include "6E644.h"
#include "lbas.h"
#include "vs_string.h"
#include "../SLUS_010.40/main.h"
#include "../SLUS_010.40/overlay.h"
#include "../MENU/MAINMENU.PRG/C48.h"
#include <memory.h>

typedef struct {
    signed char unk0;
    signed char unk1;
    short unk2;
    int unk4;
    int unk8;
    vs_main_CdQueueSlot* slot;
} D_800EB9B4_t;

typedef struct {
    short unk0;
    char unk2;
    char unk3;
    short unk4;
    short id;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    void* data;
    vs_main_CdQueueSlot* cdQueueSlot;
    int unk18[0xF7];
    int unk3F4;
} gim_t;

void func_800CA97C(void);
void func_800CE67C(void);
int func_800CF218(void);
void func_800CFEF0(void);
void func_800CFE98(void*, int);
void func_800D0D08(void);
void func_800D169C(int, int, int, int);
void func_800D17A8(int, int, int, int);
void func_800D268C(void);
void func_800D46DC(int, int);
u_char func_800D5170(void*);
int func_800D5198(void);
void func_800D6AEC(int, u_short);
extern int (*D_800EC3F4[])(void*);

extern int _menuLbas[];
extern char D_800EB9AC;
extern signed char D_800EB9AD;
extern char D_800EB9AE;
extern char D_800EB9AF;
extern D_800EB9B4_t* D_800EB9B4;
extern int D_800EB9B8;
extern gim_t* D_800EB9BC;
extern char D_800EB9CC;
extern char D_800EB9CD;
extern char D_800EB9CE;
extern int D_800EB9D0;
extern int D_800EB9D8;
extern u_int* D_800EB9D4;
extern char D_800EBC78;
extern char D_800EBD68[];
extern char D_800F522C;
extern char D_800F4CB8;
extern char D_800F4CB9;
extern int D_800F4CBC;
extern u_long D_800F4CD0;
extern char vs_battle_shortcutInvoked;
extern char D_800F4E70[16];
extern char D_800F4FDB;
extern char D_800F4E90;
extern int D_800F4ED4;
extern u_long* D_800F51B8;
extern char D_800F5310[];
extern int D_800F531C;
extern char D_800F54A8;
extern char D_800F5518;
extern int D_800F55E8;
extern int D_800F5600;
extern int D_800F5610;
extern int D_800F5618;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C4794);

void func_800C513C(int arg0)
{
    if (!(arg0 & 0xF0)) {
        func_8009FE74(arg0);
    }
}

void func_800C5164(int arg0)
{
    if (!(arg0 & 0xF0)) {
        func_8009FD5C(arg0);
    }
}

void func_800C518C(int arg0, int arg1)
{
    if (!(arg0 & 0xF0)) {
        func_800A07FC(arg0, arg1);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C51B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C5360);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C553C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C56C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C5798);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C58A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C58F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C64D0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C6540);

void vs_battle_renderTextRaw(char const* text, int xy, void* arg2)
{
    func_800C6540(text, xy, 0x808080, arg2);
}

void func_800C6850(char* arg0) { *arg0 = 0xE7; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C685C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C6BF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C6C8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C7010);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C70F8);

void func_800C7210(char arg0)
{
    D_800F4CB9 = 0;
    D_800F4CBC = 0x180;
    D_800F4CB8 = arg0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C7230);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C79D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C7BA4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C7EBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C809C);

extern u_int _gimLbas[];

void vs_battle_loadGim(int id, int arg1)
{
    vs_main_CdFile file;
    gim_t* var_s0;
    int i;

    if (D_800EB9BC == NULL) {
        var_s0 = vs_main_allocHeapR(sizeof(gim_t[3]));
        D_800EB9BC = var_s0;
        var_s0->data = vs_main_allocHeapR((char)_gimLbas[id] << 0xB);

        for (i = 0; i < 3; ++i) {
            var_s0->unk0 = 0;
            *(int*)&var_s0->unk0 = (((*(int*)&var_s0->unk0 | 2) & ~0x1C0) | 0x40);
            var_s0->unk2 = arg1;
            var_s0->unk3 = 0x80;
            var_s0->id = id;
            var_s0->unk8 = 0;
            var_s0->unkA = 0;
            var_s0->unkC = 0x1000;
            ++var_s0;
        }
        file.lba = _gimLbas[id] >> 8;
        file.size = (char)_gimLbas[id] << 0xB;
        D_800EB9BC->cdQueueSlot = vs_main_allocateCdQueueSlot(&file);
        vs_main_cdEnqueue(D_800EB9BC->cdQueueSlot, D_800EB9BC->data);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8550);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C86AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8778);

int func_800C8C50(int arg0)
{
    vs_main_CdFile file;
    int temp_s0;
    u_int var_v1;
    void* var_a1;
    vs_battle_menuState_t* s1 = &vs_battle_menuState;

    temp_s0 = arg0 & 0x1F;

    if (temp_s0 == 0x1F) {
        return 1;
    }

    if (temp_s0 == 0 && D_800EB9AD > 0) {
        return 1;
    }

    if (D_800EB9AD != temp_s0) {
        D_800EB9AD = temp_s0;
        s1->unk3 = 1;
        if (vs_battle_shortcutInvoked != 5) {
            var_v1 = _menuLbas[temp_s0];
        } else {
            var_v1 = VS_MAINMENU_PRG_LBA << 8 | VS_MAINMENU_PRG_SIZE >> 11;
        }
        file.lba = var_v1 >> 8;
        file.size = (var_v1 & 0xFF) << 11;
        s1->unk4 = vs_main_allocateCdQueueSlot(&file);
        if (temp_s0 == 0) {
            var_a1 = vs_overlay_slots[1];
        } else {
            var_a1 = vs_overlay_slots[2];
        }
        vs_main_cdEnqueue(s1->unk4, var_a1);
    }
    if (s1->unk3 == 0) {
        if (D_800EB9D4 != NULL) {
            vs_main_freeHeapR(D_800EB9D4);
            D_800EB9D4 = NULL;
            func_800FA448();
        }
        return 1;
    }
    if (s1->unk4->state == vs_main_CdQueueStateLoaded) {
        vs_main_freeCdQueueSlot(s1->unk4);
        vs_main_wait();
        s1->unk3 = 0;
        if (D_800F4FDB != 0) {
            if (vs_battle_shortcutInvoked == 5) {
                func_800FAEBC(1);
                return 0;
            }
            return 1;
        }
        if (temp_s0 == 0) {
            D_800EB9D4 = (u_int*)vs_main_allocHeapR(0xB400U);
            func_8010044C(D_800EB9D4);
        }
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8E04);

vs_battle_menuItem_t* vs_battle_getMenuItem(int id) { return vs_battle_menuItems + id; }

vs_battle_menuItem_t* vs_battle_setMenuItem(
    int id, int animSpeed, int y, int arg3, int arg4, char* text)
{
    vs_battle_menuItem_t* menuItem;
    vs_battle_menuItem_t* var_a0;
    int i;
    u_int c;

    menuItem = &vs_battle_menuItems[id];
    menuItem->state = 1;
    menuItem->unk1 = arg3;
    menuItem->unk2 = arg4;

    vs_battle_rMemzero(&menuItem->unk4, 0x3C);

    var_a0 = menuItem;
    menuItem->animSpeed = animSpeed;
    menuItem->y = y;

    for (i = 0; i < 31;) {
        c = *text++;
        if (c == vs_char_spacing) {
            var_a0->text[i++] = c;
            c = *text++;
        } else if (c == vs_char_terminator) {
            var_a0->text[i] = 0xFF;
            break;
        } else if (c >= vs_char_nonPrinting) {
            continue;
        }
        var_a0->text[i++] = c;
    }
    return menuItem;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8F44);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8FAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9078);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C930C);

void func_800C97BC()
{
    vs_battle_menuItem_t* var_s2;
    int temp_s1;
    int temp_v0;
    int i;
    int var_s0;

    var_s2 = vs_battle_menuItems;
    var_s0 = vs_battle_menuState.currentState;

    if (var_s0 == 0x7F) {
        D_800F4E98.unk0 = 2;
        vs_battle_menuState.currentState = 0x3F;
    }

    temp_s1 = var_s0 & 0x3F;

    if (temp_s1 != 0x3F) {
        if (func_800C8C50(0) != 0) {
            if (vs_battle_shortcutInvoked == 5) {
                func_800FAEBC(0);
                return;
            }
            func_800FAAC8(var_s0);
            return;
        }
        if (temp_s1 == 0) {
            temp_v0 = func_800C930C(0);
            if (temp_v0 != 0) {
                var_s0 = 0x1F;
                if (temp_v0 > 0) {
                    var_s0 = temp_v0 | 0x40;
                }
                vs_battle_menuState.currentState = var_s0;
            }
        }
        if ((var_s0 >= 0x1F) || (temp_s1 == 0)) {
            for (i = 0; i < 10; ++i) {
                func_800C9078(var_s2);
                ++var_s2;
            }
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C98C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9950);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C99DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9B38);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9CB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9E08);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9E5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9EB8);

void func_800C9F88(void) { D_800EBC78 = 1; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9F98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9FE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CA2DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CA97C);

void func_800CA9C0(void* arg0)
{
    D_800EB9AC = 0;
    D_800EB9AD = 0;
    D_800EB9AE = 0;
    D_800EB9B0 = 0;
    D_800F4ED4 = 0;
    D_800EB9B4 = 0;
    D_800EB9B8 = 0;
    D_800EB9BC = 0;
    vs_battle_menuItems = 0;
    D_800EB9CE = 0;
    D_800F4E90 = 0;
    D_800EB9AF = 0;
    D_800EB9CC = 0;
    D_800EB9CD = 0;
    D_800EB9D0 = 0xFFFFFF;
    D_800EB9D4 = 0;
    D_800EB9D8 = 0;
    func_800CA97C();
    vs_battle_rMemzero(&vs_battle_menuState, 8);
    vs_battle_menuState.currentState = 0x3F;
    vs_battle_rMemzero(&D_800F4E98, sizeof(D_800F4E98));
    vs_battle_rMemzero(&D_800F4FE0[0], sizeof(D_800F4FE0[0]));
    vs_battle_rMemzero(D_800F4E70, sizeof(D_800F4E70));
    D_800F4EE8 = (D_800F4EE8_t) { { 0 } };
    D_800F51B8 = &D_800F4CD0;
    vs_battle_drawImage(0x340, arg0, 0xE00040);
    vs_battle_drawImage(0x380, arg0 + 0x7000, 0xE00040);
    vs_battle_drawImage(0x4203C0, arg0 + 0xE000, 0x9E0040);
    DrawSync(0);
    ClearOTag(D_800F51B8, 0x22);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CAB40);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CABE0);

int func_800CACD0(int arg0, int arg1)
{
    int i;
    u_short var_a1;
    int var_a0;
    void* temp_v0;

    if (vs_battle_menuState.currentState == 0x3F) {
        vs_battle_shortcutInvoked = 0;
        D_800F4FDB = 0;
        D_800F4EA0 = func_800CABE0(arg1);
        D_800F4E98.unk2 = 0;
        vs_battle_menuState.currentState = arg0;
        D_800F4E98.unk0 = 1;
        if (arg1 == 0) {
            vs_battle_playSfx10();
        }
        if (vs_battle_menuItems == 0) {
            D_800EB9AD = -1;
            func_8007E180(6);
            temp_v0 = vs_main_allocHeapR(0xB24);
            var_a1 = D_80060022;
            D_800F4E8C = temp_v0 + 0xA00;
            vs_battle_menuItems = temp_v0;
            D_800F4E84 = temp_v0 + 0xA60;
            for (i = 0; i < 3; ++i) {
                for (var_a0 = D_800EBD68[i * 2]; var_a0 < D_800EBD68[i * 2 + 1];
                     ++var_a0) {
                    if ((vs_main_skills[var_a0].flags >> 0xF) & 1) {
                        var_a1 |= 1 << i;
                        break;
                    }
                }
            }

            if (vs_main_stateFlags.unkB5 != 0) {
                var_a1 |= 1;
            }
            if (vs_main_stateFlags.introState >= 3) {
                var_a1 |= 0x120;
            }
            D_80060022 = var_a1;
            func_800C930C(2);
        }
        return 1;
    }
    func_800C02E0();
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CAEAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CAF40);

int vs_battle_abilitiesUnlocked(int defense)
{
    int i;
    vs_skill_t* v0;

    for (i = 0; i < 14; ++i) {
        v0 = vs_main_skills;
        if ((v0[defense == 0 ? vs_battle_chainAbilityOffsets[i]
                             : vs_battle_defenseAbilityOffsets[i]]
                    .flags
                >> 0xF)
            & 1) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB030);

void func_800CB114()
{
    if (vs_battle_menuItems != 0) {
        func_8007E1C0(6);
        vs_main_freeHeapR(vs_battle_menuItems);
        vs_battle_menuItems = 0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB158);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB18C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB1C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB208);

void func_800CB23C()
{
    func_800CACD0(0xF, 2);
    D_800F4FDB = 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB268);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB2B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB45C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB50C);

void func_800CB550(void) { D_800F4E90 = 1; }

void func_800CB560(void) { D_800F4E90 = 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB56C);

void func_800CB654(int arg0) { D_800EB9AF = arg0; }

void func_800CB660(int arg0) { D_800EB9CC = arg0; }

short* func_800CB66C(void) { return &D_800F4E98.unk0; }

void _loadScreff2(int arg0)
{
    vs_main_CdFile file;
    D_800EB9B4_t* p = D_800EB9B4;
    void* const* new_var;

    if (arg0 != 0) {
        p->unk0 = 1;
        file.lba = VS_SCREFF2_PRG_LBA;
        file.size = VS_SCREFF2_PRG_SIZE;
        p->slot = vs_main_allocateCdQueueSlot(&file);
        new_var = &vs_overlay_slots[1];
        vs_main_cdEnqueue(p->slot, *new_var);
        return;
    }

    if (p->slot->state == 4) {
        vs_main_freeCdQueueSlot(p->slot);
        p->unk0 = 0;
        vs_main_wait();
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB708);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB79C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB7DC);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", D_80069998);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB83C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CBBCC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CC128);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CC204);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CC580);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CC5C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CC600);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCA90);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCB9C);

void vs_battle_rMemzero(void* arg0, int arg1)
{
    int* var_v0;

    var_v0 = arg0 + arg1;
    do {
        *(int*)--var_v0 = 0;
    } while (arg0 != var_v0);
}

void vs_battle_rMemcpy(void* dest, void const* src, int size)
{
    do {
        --size;
        ((char*)dest)[size] = ((char const*)src)[size];
    } while (size != 0);
}

int vs_battle_toBCD(int arg0) { return (arg0 % 10) | ((arg0 / 10) * 16); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", vs_battle_encode);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCCB8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCD00);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", vs_battle_drawCursor);

void vs_battle_drawImage(int xy, void* buffer, int wh)
{
    extern int D_800EC280;
    extern RECT D_800F51D0[];
    RECT* rect;

    rect = D_800EC280 + D_800F51D0;
    D_800EC280 = (D_800EC280 + 1) & 7;
    *(int*)&rect->x = xy;
    *(int*)&rect->w = wh;
    LoadImage(rect, buffer);
}

D_800F4FE0_t* func_800CCDF4(int arg0) { return D_800F4FE0 + arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCE10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCF08);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CD064);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CD0FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CD158);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CD3A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CD3E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CDCBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE174);

void func_800CE644(int i __attribute__((unused))) { }

void func_800CE64C()
{
    func_800CE67C();
    func_800D7814();
    func_800D268C();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE67C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE714);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE83C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE8F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE9B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CED60);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CEEBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CEF0C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CEF38);

int func_800CEF64(void) { return D_800F54A8 != 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CEF74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF060);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF0E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF1A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF218);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF3F8);

char func_800CF458(void) { return func_800CF218(); }

void func_800CF478(int arg0) { D_800F531C = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF484);

int func_800CF48C(void) { return D_800F531C; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF49C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF514);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF55C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF614);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF694);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF70C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF7A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF830);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF8BC);

void func_800CF920(void) { D_800F522C = 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF92C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF988);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFAAC);

int func_800CFB68(int arg0, int arg1, int arg2)
{
    return (((arg1 - arg0) * arg2) >> 7) + arg0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFB80);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFBF8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFC48);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFC8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFCF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFD60);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFDD0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFE1C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFE40);

void func_800CFE7C(int* arg0)
{
    arg0[4] = 0x1000;
    arg0[2] = 0x1000;
    arg0[0] = 0x1000;
    arg0[3] = 0;
    arg0[1] = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFE98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFEF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D01E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D037C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0548);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D05F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0984);

void func_800D0B08(int arg0) { func_800CFE98(D_800F5310, arg0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0B30);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0C60);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0D08);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1104);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D118C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D11F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D12D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D135C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1390);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D155C);

int func_800D1678(int arg0, int arg1, int arg2)
{
    int var_v0;

    var_v0 = (arg1 - arg0) * arg2;
    if (var_v0 < 0) {
        var_v0 += 0x1FFF;
    }
    return arg0 + (var_v0 >> 0xD);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D169C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1718);

void func_800D1778(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    func_800D169C(arg0, arg1, (arg3 << 0xD) / arg2, arg4);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D17A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1824);

void func_800D1884(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    func_800D17A8(arg0, arg1, (arg3 << 0xD) / arg2, arg4);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D18B4);

void func_800D1904(int arg0, int arg1, int arg2, int arg3)
{
    func_800D1678(arg0, arg1, (arg3 << 0xD) / arg2);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1930);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D197C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1B18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1B80);

void func_800D1DE4(int arg0) { D_800F5518 |= arg0; }

void func_800D1DFC(int arg0)
{
    if (arg0 != 0) {
        D_800F5518 &= ~arg0;
        return;
    }
    D_800F5518 = 0;
}

void func_800D1E20(int arg0) { D_800F55E8 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1E2C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1E78);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1EF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1FEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D206C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D21C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D236C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2518);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2560);

void func_800D268C(void) { D_800F5600 = 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2698);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D278C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D27F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2888);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2904);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2970);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D29B0);

void func_800D29F0(short* arg0, int* arg1)
{
    arg1[0] = arg0[0];
    arg1[1] = arg0[1];
    arg1[2] = arg0[2];
}

void func_800D2A14(u_short* arg0, u_short* arg1)
{
    arg1[0] = arg0[0];
    arg1[1] = arg0[2];
    arg1[2] = arg0[4];
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2A38);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2ADC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D46DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4720);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D474C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4778);

int func_800D47C0(void) { return 2; }

int func_800D47C8(void* arg0)
{
    D_800F5610 = func_800D5170(arg0);
    return 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D47F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D487C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D48A4);

int func_800D48E4(int arg0)
{
    func_800D46DC(D_800F522C == 0, arg0);
    return 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4910);

int func_800D4984()
{
    func_800D0D08();
    return 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D49A4);

int func_800D4A94()
{
    func_800CFEF0();
    return 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4AB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4AEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4B34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4B90);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4BD0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4C18);

int func_800D4D44()
{
    func_800D78F0();
    return 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4D64);

int func_800D4D98()
{
    D_800F522C = 0;
    return 1;
}

int func_800D4DA8(void) { return 1; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4DB0);

int func_800D4E5C(int arg0)
{
    func_800D6AEC(arg0, func_800D5198());
    return 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4E90);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4EC0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4F00);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4FB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5048);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5088);

void func_800D5150(void) { func_800CE644(0x1E); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5170);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5198);

int func_800D51D8(void* arg0)
{
    int temp_v0;

    do {
        temp_v0 = D_800EC3F4[func_800D5170(arg0)](arg0);
        if (temp_v0 == 2) {
            return 0;
        }
    } while (temp_v0 == 1);
    return 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5260);

void func_800D5294(int* arg0) { D_800F5618 = *arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D52A4);

void* func_800D5550(u_short* arg0, int arg1)
{
    u_short* v = arg0 + arg1;
    return (char*)arg0 + v[2];
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5564);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D55A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5700);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5738);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5780);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D57FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5904);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5A98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5D74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5E00);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5F8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6048);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D61AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6298);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6310);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6388);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D63D0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6418);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6448);

void func_800D64E4(void) { func_800CF830(0, 0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6508);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6538);

void func_800D6554(void) { func_8006CE50(); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6574);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D65A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D65D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6628);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D66CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D66FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D67C4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6860);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6894);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6A18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6AEC);

void func_800D6CCC(int* arg0)
{
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[4] = 0;
    arg0[5] = 0;
    arg0[6] = 0;
    arg0[7] = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6CF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6D24);

void func_800D6E24(void) { func_800D6E44(); }
