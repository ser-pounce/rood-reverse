#include "common.h"
#include "../SLUS_010.40/main.h"
#include "../SLUS_010.40/32154.h"
#include "lbas.h"

typedef struct {
    int unk0;
    void* unk4;
    void* unk8;
    void* unkC;
    void* unk10;
} func_8006DF70_t;

typedef struct {
    int unk0;
    int unk4;
    short unk8;
    short unkA;
} D_800DBB88_t;

void func_8006B9B4(void);
void func_8006A0D8(void);
void _drawInteger(DRAWENV*);
void func_8006A888(void);
void func_8006A9C0(int*);
void func_8006AA6C(void);
void func_8006AB44(void (*)(void));
void func_8006B760(void);
void func_8006B884(void);
void func_8006B910(void);
void func_8006B9DC(void);
void func_8006BD78(void);

extern int D_8006E3FC;
extern int D_8007005C;
extern int D_8007709C;
extern int D_80088ABC;
extern int D_8009A4DC;
extern int D_800ABEFC;
extern int D_800BD91C;
extern int D_800CF33C;
extern int D_800D7F7C;
extern int D_800D837C;
extern int D_800D975C;
extern int D_800DB09C;
extern int D_800DB26C;
extern signed char D_800DB72C;
extern int _illustLbas[];
extern int _illustSizes[];
extern D_800DBB88_t D_800DBB88;
extern signed char D_800DC188;
extern signed char D_800DC189;
extern signed char D_800DC18A;
extern int D_800DC18C;
extern int D_800DC190;
extern int* D_800DC194;
extern short D_800DC198;
extern short D_800DC19C;
extern int D_800DC1A0;
extern int D_800DC1A4;
extern void* D_800DC1A8[];

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_800688D4);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80068938);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80068EBC);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069088);

int _inverseDistanceFromScreencenter(int arg0, int arg1)
{
    arg0 -= 0xA0;
    arg1 -= 0x70;
    return vs_gte_rsqrt(arg0 * arg0 + arg1 * arg1);
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069388);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069730);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069AEC);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069BC0);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_80069F9C);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006A0D8);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006A3BC);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006A438);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006A4D8);

void func_8006A5C0(void)
{
    vs_main_CdFile file;
    short i;
    vs_main_CdQueueSlot* slot;

    func_8006B884();
    SetGeomOffset(0xA0, 0x70);
    SetGeomScreen(0x200);
    _drawInteger(vs_main_drawEnv);
    _drawInteger(&vs_main_drawEnv[1]);
    vs_main_dispEnv[1].isinter = 0;
    vs_main_dispEnv[0].isinter = 0;
    func_8006A9C0(&D_8007005C);
    func_8006A9C0(&D_800CF33C);
    func_8006A9C0(&D_800D7F7C);
    func_8006A9C0(&D_800D975C);
    func_8006A9C0(&D_800D837C);
    func_8006A9C0(&D_800DB09C);
    func_8006A9C0(&D_800DB26C);
    func_8006A9C0(&D_8007709C);
    func_8006A9C0(&D_80088ABC);
    func_8006A9C0(&D_8009A4DC);
    func_8006A9C0(&D_800ABEFC);
    func_8006A9C0(&D_800BD91C);

    for (i = 5; i < 16; ++i) {
        file.lba = _illustLbas[i - 5];
        file.size = _illustSizes[i - 5];
        D_800DC1A8[i] = vs_main_allocHeapR(file.size);
        slot = vs_main_allocateCdQueueSlot(&file);
        vs_main_cdEnqueueUrgent(slot, D_800DC1A8[i]);

        do {
            vs_main_gametimeUpdate(0);
        } while (slot->state != 4);

        vs_main_freeCdQueueSlot(slot);
    }
    D_800DC19C = 0;
    D_800DC18A = 0;
    func_8006AA6C();
    func_8006AB44(&func_8006A0D8);
    DrawSync(0);
    SetDispMask(1);
    D_800DC194 = &D_8006E3FC;
    D_800DC198 = -0x80;
    D_800DC188 = 0;
    D_800DC190 = 0;
    D_800DC18C = 0;
    D_800DC189 = 1;
    func_8006B9B4();
    func_8006A888();
    vs_main_checkStreamXaEnd();
    SetDispMask(0);
    for (i = 5; i < 16; ++i) {
        vs_main_freeHeapR(D_800DC1A8[i]);
    }
    func_8006B9DC();
    func_8006B910();
    func_8006BD78();
}

void _drawInteger(DRAWENV* drawenv)
{
    drawenv->isbg = 1;
    drawenv->dtd = 0;
    drawenv->dfe = 0;
    drawenv->b0 = 0;
    drawenv->g0 = 0;
    drawenv->r0 = 0;
    drawenv->tpage = 0x20;
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006A888);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006A958);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006A9C0);

void func_8006AA6C(void)
{
    D_800DBB88_t* var_v1;
    short temp_v0;
    short i;

    var_v1 = &D_800DBB88;
    i = 0;
    do {
        var_v1->unk8 = 0;
        temp_v0 = i + 1;
        i = temp_v0;
        var_v1 += 4;
    } while (temp_v0 < 0x20);
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006AAA0);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006AB44);

D_800DBB88_t* func_8006ABBC(int arg0)
{
    if (D_800DBB88.unk8 == 0) {
        D_800DBB88.unk0 = arg0;
        D_800DBB88.unk8 = 1;
        D_800DBB88.unkA = 0;
        return &D_800DBB88;
    }
    return 0;
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006ABF0);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006AE54);

void func_8006AF44(int arg0, int arg1)
{
    D_800DB72C = 1;
    D_800DC1A0 = arg1;
    D_800DC1A4 = arg0;
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006AF64);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006B324);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006B450);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006B6A4);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006B760);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006B884);

void func_8006B910(void) { func_8006B760(); }

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006B930);

void func_8006B9B4(void)
{
    vs_main_streamXa(VS_ENDING_XA_LBA, 0x7FFF); // Partial playback?
}

void func_8006B9DC(void) { vs_main_checkStreamXaEnd(); }

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006B9FC);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006BD78);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006BE04);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C214);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C3CC);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C514);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C5C8);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C744);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006C9A8);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006CAF4);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006CD38);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006CD94);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006CF24);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006D358);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006DA18);

void func_8006DF70(u_int* arg0, func_8006DF70_t* arg1)
{

    ++arg0;
    arg1->unk0 = *arg0;
    ++arg0;
    if (arg1->unk0 & 8) {
        arg1->unk4 = arg0 + 1;
        arg1->unk8 = arg0 + 3;
        arg0 += *arg0 / 4;
    } else {
        arg1->unk4 = 0;
        arg1->unk8 = 0;
    }
    arg1->unkC = arg0 + 1;
    arg1->unk10 = arg0 + 3;
}

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006DFD0);

INCLUDE_RODATA("build/src/ENDING/ENDING.PRG/nonmatchings/D4", D_800688A4);

INCLUDE_RODATA("build/src/ENDING/ENDING.PRG/nonmatchings/D4", D_800688AC);

INCLUDE_ASM("build/src/ENDING/ENDING.PRG/nonmatchings/D4", func_8006E074);
