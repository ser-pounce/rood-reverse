#include "common.h"
#include "5BF94.h"
#include "573B8.h"
#include "146C.h"
#include "lbas.h"
#include "../SLUS_010.40/overlay.h"
#include "../MENU/MAINMENU.PRG/278.h"

typedef struct {
    signed char unk0;
    signed char unk1;
    short unk2;
    int unk4;
    int unk8;
    vs_main_CdQueueSlot* slot;
} D_800EB9B4_t;

extern int _menuLbas[];
extern signed char D_800EB9AD;
extern D_800EB9B4_t* D_800EB9B4;
extern u_int* D_800EB9D4;
extern char D_800F4E6A;
extern char D_800F4FDB;

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C4794);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C513C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C5164);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C518C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C51B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C5360);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C553C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C56C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C5798);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C58A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C58F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C64D0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C6540);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C6828);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C6850);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C685C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C6BF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C6C8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C7010);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C70F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C7210);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C7230);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C79D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C7BA4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C7EBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C809C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8430);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8550);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C86AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8778);

int func_800C8C50(int arg0)
{
    vs_main_CdFile file;
    int temp_s0;
    u_int var_v1;
    void* var_a1;
    D_800F51C0_t* s1 = &D_800F51C0;

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
        if (D_800F4E6A != 5) {
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
        if (D_800EB9D4 != 0) {
            vs_main_freeHeapR(D_800EB9D4);
            D_800EB9D4 = 0;
            func_800FA448();
        }
        return 1;
    }
    if (s1->unk4->state == 4) {
        vs_main_freeCdQueueSlot(s1->unk4);
        vs_main_wait();
        s1->unk3 = 0;
        if (D_800F4FDB != 0) {
            if (D_800F4E6A == 5) {
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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8E48);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8E5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8F44);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C8FAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9078);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C930C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C97BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C98C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9950);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C99DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9B38);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9CB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9E08);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9E5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9EB8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9F88);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9F98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800C9FE8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CA2DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CA97C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CA9C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CAB40);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CABE0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CACD0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CAEAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CAF40);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CAFB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB030);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB114);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB158);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB18C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB1C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB208);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB23C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB268);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB2B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB45C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB50C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB550);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB560);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB56C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB654);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB660);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CB66C);

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

void vs_battle_rMemcpy(char* dest, char const* src, int size)
{
    do {
        --size;
        dest[size] = src[size];
    } while (size != 0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCC54);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", vs_battle_encode);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCCB8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCD00);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCD40);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCDA8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCDF4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCE10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CCF08);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CD064);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CD0FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CD158);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CD3A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CD3E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CDCBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE174);

void func_800CE644(void) { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE64C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE67C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE714);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE83C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE8F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CE9B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CED60);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CEEBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CEF0C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CEF38);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CEF64);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CEF74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF060);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF0E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF1A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF218);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF3F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF458);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF478);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF484);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF48C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF49C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF514);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF55C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF614);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF694);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF70C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF7A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF830);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF8BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF920);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF92C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CF988);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFAAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFB68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFB80);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFBF8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFC48);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFC8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFCF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFD60);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFDD0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFE1C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFE40);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFE7C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFE98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800CFEF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D01E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D037C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0548);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D05F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0984);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D0B08);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1678);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D169C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1718);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1778);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D17A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1824);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1884);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D18B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1904);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1930);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D197C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1B18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1B80);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1DE4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1DFC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1E20);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1E2C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1E78);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1EF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D1FEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D206C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D21C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D236C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2518);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2560);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D268C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2698);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D278C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D27F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2888);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2904);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2970);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D29B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D29F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2A14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2A38);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D2ADC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D46DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4720);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D474C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4778);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D47C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D47C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D47F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D487C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D48A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D48E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4910);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4984);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D49A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4A94);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4AB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4AEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4B34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4B90);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4BD0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4C18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4D44);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4D64);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4D98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4DA8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4DB0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4E5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4E90);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4EC0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4F00);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D4FB4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5048);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5088);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5150);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5170);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5198);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D51D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5260);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5294);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D52A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D5550);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D64E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6508);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6538);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6554);

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

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6CCC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6CF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6D24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/5BF94", func_800D6E24);
