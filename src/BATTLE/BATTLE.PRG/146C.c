#include "common.h"
#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#include "2842C.h"
#include "44F14.h"
#include "4A0A8.h"
#include "5BF94.h"
#include "6E644.h"
#include "../../SLUS_010.40/main.h"

typedef struct {
    int unk0;
    int unk4;
} func_8007820C_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    short unk2;
    short unk4;
    u_char unk6;
    u_char unk7;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
} func_8008418C_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    short unk18;
    short unk1A;
    short unk1C;
    short unk1E;
    int unk20;
    int unk24;
    int unk34[3];
    short unk40;
    u_char unk42;
    u_char unk43;
    int unk38[158];
    short unkAC;
    short unkAE;
    int unkB0[421];
    int unk948;
} D_800F1964_t;

typedef struct {
    int unk0[2];
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    u_short unk18;
    u_short unk1A;
    u_short unk1C;
    short unk1E;
    int unk20;
    short unk24;
    char unk26;
    char unk27;
    int unk28[5];
    D_800F1964_t* unk3C;
    int unk40;
    int unk44;
} D_800F1928_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} D_800F1A68_t;

typedef struct {
    short unk0[2];
} D_800F1A78_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    short unk2;
    int unk4[9];
    u_int unk28;
    u_int unk2C[8];
    u_int unk4C;
    int unk50[14];
    int unk88;
    int unk8C[8];
    int unkAC;
} D_800F1BF8_t;

typedef struct {
    int unk0[12];
    u_char unk30;
    u_char unk31;
    u_char unk32;
    u_char unk33;
    short unk34[17];
    short unk56;
} D_800F1C84_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
} func_80085718_t;

typedef struct {
    short unk0;
    short unk2;
} D_800F1C60_t;

void func_8006C350();
void func_8006C39C();
void func_8006C40C();
void func_80069DEC();
void func_8006A228(int, int);
void func_8006B7BC();
void func_8006DEFC(func_8007820C_t*, int, int);
void func_8006F53C();
void func_8006F5CC();
void func_8006F89C();
void func_8006FA20();
void func_80070278();
void func_80070F28(int);
void func_8007138C();
void func_80073718();
void func_800780A8(func_8007820C_t*);
void func_8007A850(int);
void func_8007A9DC(void*, void*, int);
void func_8007B29C(int, int, int, int, int, int);
void func_8007B63C();
void func_8007B470();
void func_8007B764();
void func_8007B7DC();
void func_8007BCCC();
void func_8007BF6C(int);
void func_8007BFF8(int);
void func_8007C4E0();
void func_8007C5C0();
void func_8007C81C(int, int);
void func_8007D360();
int func_8007F4B0(int);
int func_8007F518(u_char*);
void func_80081020(int, int);
short func_80081148(int, int, int, int, int, int);
void func_80086754(int, int);
void func_8008A6FC();
int func_8008AB80(int);
int func_8008ABB8(int);
void func_8008574C(int, D_800F1964_t*, int);
void func_8008B960(u_char, u_char, u_char);
void func_8008C49C(int, int);
void func_8008D5A0(int);
void func_80089D04();
void func_80088554();
void func_80089CE4();
int func_8008B4C8(u_char arg0);
void func_8008C40C();

extern int D_800E8498;
extern int D_800F185C;
extern int D_800F1860;
extern int D_800F1864;
extern int D_800F1868;
extern int D_800F186C;
extern int D_800F1880[];
extern int D_800F18A8;
extern int D_800F18B0;
extern int D_800F18F0;
extern u_char D_800F18F8;
extern int* D_800F1900;
extern int D_800F190C;
extern D_800F1928_t* D_800F1928[];
extern int D_800F1968;
extern int D_800F196C;
extern int D_800F19A0;
extern int D_800F19D4;
extern int* D_800F19FC;
extern int D_800F1A04;
extern int D_800F1A08;
extern int D_800F1A20;
extern short D_800F1A2C;
extern int D_800F1A30[];
extern int D_800F1A40;
extern u_int D_800F1A44;
extern u_int D_800F1A48;
extern D_800F1A68_t D_800F1A68;
extern D_800F1A78_t D_800F1A78;
extern int D_800F1A98;
extern int D_800F1AA4;
extern int D_800F1AA8;
extern int D_800F1ABC;
extern int D_800F1B98;
extern int D_800F1B9C;
extern u_short D_800F1BA4;
extern short* D_800F1BA8;
extern short D_800F1BB6;
extern u_char D_800F1BBE;
extern D_800F1BF8_t D_800F1BF8;
extern int* D_800F1C5C;
extern D_800F1C60_t* D_800F1C60;
extern int D_800F1C64;
extern int D_800F1C70;
extern int D_800F1C74;
extern D_800F1C84_t* D_800F1C84;
extern int* D_800F1CA4;
extern u_int D_800F1CA8;
extern int D_800F1CB8;
extern u_char D_800F1CD6;
extern short D_800F1CDC;
extern char D_800F1D28[0x40];
extern short D_800F1D6A;
extern short D_800F1D6C;
extern int D_800F1D78;
extern char D_800F1D6E;
extern short D_800F1DB8;
extern short D_800F1DBA;
extern short D_800F1DC4;
extern char D_800F1DC9;
extern u_char D_800F1DCA;
extern u_short* D_800F1DD4;

extern int D_1F800000[];
extern int D_1F800034[];

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80069C6C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80069D14);

void func_80069D78()
{
    func_8007A850(0);
    D_1F800000[4] = ((D_1F800000[4] & 0x7FFF) | (D_800F186C << 0x10));
}

void func_80069DBC()
{
    D_80060064 = 0;
    vs_main_bzero(D_80061078, 0x520);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80069DEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80069E80);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80069EF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80069FC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A11C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A1C4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A228);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A334);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A65C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A8EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A9F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006AB44);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006AC74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006ACFC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006AE0C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006AEAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B02C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B110);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B194);

void func_8006B20C() { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B214);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B270);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B2D4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B338);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B460);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B4B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B524);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B57C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B6AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B728);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B7BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B8C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006B9E0);

void func_8006BAA8(int arg0 __attribute__((unused)), u_short* arg1)
{
    if (arg1[0] != 0) {
        arg1[4] = arg1[24];
        func_8006B7BC();
    }
}

void func_8006BADC(int arg0 __attribute__((unused)), u_short* arg1)
{
    if (*arg1 != 0) {
        func_8006B7BC();
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006BB0C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006BBEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006BCB0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006BD14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006BDA0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006BDF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006BE64);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C004);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C164);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C1CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C250);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C2A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C2FC);

void func_8006C350()
{
    int i;

    for (i = 1; i < 16; ++i) {
        func_8009E5C4(i);
    }
    func_80095B70(1);
    D_800F1968 = 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C39C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C40C);

void func_8006C478() { }

void func_8006C480(int arg0, int arg1) { func_800CF7A8(arg0, arg1, 0, 0); }

void func_8006C4A4() { func_800CF830(); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C4C4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C5AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C84C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006CA20);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006CB04);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006CD60);

void func_8006CDB8() { func_8009D854(); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006CDD8);

void func_8006CE50() { func_8008D5A0(0xB4); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006CE70);

void func_8006D028(int arg0)
{
    D_800F185C = arg0;
    func_8007B29C(0xE, 8, arg0, 0x10, 0, 0);
}

void func_8006D064()
{
    func_8007B29C(8, 4, D_800F185C, 0, 0, 0);
    D_800F185C = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006D0A4);

int func_8006D97C(int base, int a, int b)
{
    if (b < 0) {
        if (a >= b) {
            if (a != 0) {
                base += a;
            } else {
                base += b;
            }
        } else {
            base += b;
        }
    } else if ((b >= a) && (a != 0)) {
        base += a;
    } else {
        base += b;
    }
    return base;
}

int _add_min(int base, int a, int b)
{

    if (b < 0) {
        if (a < b) {
            base += b;
        } else {
            base += a;
        }
    } else if (b < a) {
        base += b;
    } else {
        base += a;
    }
    return base;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006D9FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006DB98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006DEFC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006DFE0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006E158);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006E640);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006E7F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006EBF8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006EC7C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006EF10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006EF5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F204);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F450);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F4B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F53C);

void func_8006F5CC()
{
    D_800F196C = 1;
    D_800F18F0 = 0;
    func_8006F53C();
}

void func_8006F5FC()
{
    D_800F196C = 0xC;
    D_800F18F0 = 0;
    func_8009E5C4(0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F630);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F760);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F848);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006F89C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006FA20);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006FB48);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006FBCC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006FCBC);

void func_8006FD0C() { D_800F18F0 = 9; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006FD1C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80070278);

void func_800704B0()
{
    D_800F18F0 = 6;
    func_800CF920();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800704D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007053C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007087C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800708EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80070B04);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80070CAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80070F28);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007138C);

void func_800719DC() { func_80070F28(0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800719FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80071F68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80072734);

void func_80072B9C() { D_800F18F0 = 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80072BA8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80072EC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800730BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800732AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800733F8);

void func_80073484()
{
    func_8006F5CC();
    vs_gametime_tickspeed = 2;
    func_800CB654(0);
    func_8008B4C8(1);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800734C0);

void func_8007350C() { func_8006F5CC(); }

void func_8007352C()
{
    D_800F196C = 6;
    func_8006C39C();
}

void func_80073554()
{
    D_800F196C = 1;
    func_8006C40C();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007357C);

void func_800735CC(short* arg0)
{
    func_800CB114();
    *arg0 = 0;
    func_8006C40C();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800735F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80073718);

void func_80073870()
{
    func_800BEC30();
    func_80073718();
}

void func_80073898()
{
    if ((func_800BEB10() << 16) != 0) {
        D_800F196C = 3;
        D_800F18F0 = 1;
        return;
    }
    func_80073870();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800738E4);

void func_80073AA4()
{
    D_800F196C = 0xB;
    func_8006C350();
}

void func_80073ACC()
{
    func_800CB50C();
    func_8006C40C();
    func_8006F5CC();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80073AFC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80073D30);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80073E30);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80073F7C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074050);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074120);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007418C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800741D4);

int func_8007424C()
{
    int ret = 0;
    if (func_800A0BE0(0) & 0x08000000) {
        ret = func_800CB45C() == 0;
    }
    return ret;
}

int func_80074294() { return D_800F1868 & 3; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800742A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074314);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074374);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800743E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800744B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074580);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800745EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074744);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074798);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074860);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800748B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074950);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074A20);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074B14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074BAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800751B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800753F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80075554);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800760CC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007629C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007647C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800765B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80076784);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80076D50);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80076F24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077078);

void func_800770FC(int arg0 __attribute__((unused)), int arg1)
{
    func_8007C8F8_t sp10;

    sp10.unk0 = 7;
    sp10.unk1 = arg1;
    sp10.unk2 = 0;
    sp10.unk10 = 0;
    func_800995E8(&sp10);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077130);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800771E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077240);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800773BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800774FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800775C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077DF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077EC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077F14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80077F70);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800780A8);

void func_8007820C(int arg0)
{
    func_8007820C_t sp10;

    func_800780A8(&sp10);
    if (arg0 != 0) {
        func_8006DEFC(&sp10, 1, 0x28);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80078248);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800782E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80078364);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800784AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80078748);

void func_800787F0()
{
    if (!(D_800F1868 & 2)) {
        func_80070278();
        func_800CEF74(0);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80078828);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80078AB4);

void func_80079030() { func_8007138C(); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80079050);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800790BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800792E4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800793C0);

void func_800797BC()
{
    func_800C97BC();
    if (*func_800CB66C() != 1) {
        func_8006C40C();
        func_800CB114();
        func_8006F89C();
    }
}

void func_8007980C()
{
    if (!(D_800F1868 & 3)) {
        func_8006FA20();
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007983C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", vs_battle_exec);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007A850);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007A9DC);

void func_8007AACC(int arg0) { func_8007A9DC(D_1F800034, &D_1F800034[4], arg0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007AAF8);

void func_8007ABEC(int* arg0)
{
    arg0[0] = D_1F800000[13];
    arg0[1] = D_1F800000[14];
    arg0[2] = D_1F800000[15];
}

void func_8007AC18(int* arg0)
{
    D_1F800000[13] = arg0[0];
    D_1F800000[14] = arg0[1];
    D_1F800000[15] = arg0[2];
}

void func_8007AC40(int* arg0)
{
    arg0[0] = D_1F800000[17];
    arg0[1] = D_1F800000[18];
    arg0[2] = D_1F800000[19];
}

void func_8007AC6C(int* arg0)
{
    D_1F800000[17] = arg0[0];
    D_1F800000[18] = arg0[1];
    D_1F800000[19] = arg0[2];
}

__asm__("glabel func_8007AC94;"
        ".set push;"
        ".set at=$v0;"
        ".set reorder;"
        "sw $a0,0x1F80005C;"
        "jr $ra;"
        ".set pop;");

int func_8007ACA0() { return *getScratchAddr(0x17) & 0xFFF; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007ACB0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007AFA8);

void func_8007B0FC() { }

void func_8007B104() { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B10C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B1B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B29C);

void func_8007B344(int arg0, int arg1, short arg2, short arg3, short arg4)
{
    func_800478E0(arg0, arg1, arg2, arg3, arg4);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B378);

void func_8007B3D0(int arg0, int arg1, u_short* arg2, int arg3)
{
    func_80046C80(arg0, arg1 + 4, arg2, arg3);
}

void func_8007B3F0() { func_800472D0(); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B410);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B470);

void func_8007B4C4()
{
    D_800F18F0 = 2;
    func_8007B470();
    if (D_800F1864 != 0) {
        func_8009E5C4(0);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B508);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B63C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B764);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B7DC);

void func_8007B834()
{
    func_800C97BC();
    if (*func_800CB66C() != 1) {
        func_8007B470();
        func_800CB114();
        func_8007B764();
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B884);

void func_8007B908()
{
    if (!(D_800F1868 & 3)) {
        func_8007B63C();
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B938);

void func_8007B9A0()
{
    D_800F1860 = 0;
    D_800F1864 = 0;
    func_8007B7DC();
}

void func_8007B9CC()
{
    D_800F1860 = 0;
    D_800F1864 = 1;
    func_8007B764();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007B9FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BA98);

void func_8007BBB8() { func_80069DEC(); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BBD8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BCCC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BD3C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BD8C);

int func_8007BDD8(int arg0)
{
    func_8008C40C();
    return D_800F186C = ~arg0 & 1;
}

int func_8007BE10(int arg0) { return D_800F18B0 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BE20);

void func_8007BEC4() { func_800CEF74(); }

void func_8007BEE4() { func_800CF48C(); }

void func_8007BF04() { }

int func_8007BF0C() { return func_800CEEBC() != 0; }

void func_8007BF2C() { func_8008AB80(0); }

void func_8007BF4C() { func_8008ABB8(0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BF6C);

void func_8007BFC0()
{
    int i;

    for (i = 0; i < 16; ++i) {
        func_8007BF6C(i);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007BFF8);

void func_8007C050()
{
    int i;

    for (i = 0; i < 16; ++i) {
        func_8007BFF8(i);
    }
}

int func_8007C088(int arg0) { return D_800F1928[arg0]->unk20 & 1; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C0AC);

void func_8007C1D8(int arg0, int arg1)
{
    if (D_800F1928[arg0] != 0) {
        if (arg1 != 0) {
            D_800F1928[arg0]->unk1C = 4;
            return;
        }
        D_800F1928[arg0]->unk1C = 8;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C218);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C28C);

void func_8007C31C() { func_80086754(0, D_800F19FC[15]); }

void func_8007C348(int arg0, int arg1) { func_8009F314(arg0, 0, arg1); }

int func_8007C36C(int arg0)
{
    if ((arg0 == 2) || (arg0 == 4)) {
        vs_gametime_tickspeed = arg0;
    }
    return vs_gametime_tickspeed;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C398);

void func_8007C404() { func_80089CE4(); }

void func_8007C424() { func_80089D04(); }

void func_8007C444(int arg0, int arg1, int arg2)
{
    D_800F1A98 = arg0;
    D_800F1AA8 = arg1;
    D_800F1AA4 = arg2;
}

void func_8007C460(int arg0) { D_800F1AA4 = arg0; }

void func_8007C46C(int arg0, int arg1, int arg2)
{
    if ((D_800F1A48 - 1) >= 2) {
        D_800F1A48 = 5;
        D_800F1A98 = arg0;
        D_800F1AA8 = arg1;
        D_800F1AA4 = arg2;
    }
}

void func_8007C4AC(int arg0, int arg1, int arg2)
{
    D_800F1A48 = 7;
    D_800F1A98 = arg0;
    D_800F1AA8 = arg1;
    D_800F1AA4 = arg2;
}

void func_8007C4D4() { D_800F19A0 = 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C4E0);

void func_8007C580()
{
    u_char sp10[16];

    func_8007C4E0();
    func_800A1108(0, sp10);
    func_8008B960(sp10[0], sp10[2], sp10[1]);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C5C0);

void func_8007C654()
{
    u_char sp10[16];

    func_8007C5C0();
    func_800A1108(0, sp10);
    func_8008B960(sp10[0], sp10[2], sp10[1]);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C694);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C81C);

void func_8007C874() { func_8007C81C(D_800F1880[0], D_800F1880[13]); }

void func_8007C8A4(int arg0)
{
    if ((D_800F1928[arg0] != 0) && (arg0 < 16)) {
        func_800AE4FC(D_800F1928[arg0]->unk44);
    }
}

int func_8007C8F0() { return 0; }

int func_8007C8F8(short arg0)
{
    func_8007C8F8_t sp10;

    sp10.unk2 = arg0;
    sp10.unk0 = 1;
    sp10.unk1 = 0;
    return func_800995E8(&sp10) + 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007C928);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007CA20);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007CAA4);

void func_8007CB84(int arg0, int arg1)
{
    func_8007C8F8_t sp10;

    sp10.unk0 = 7;
    sp10.unk1 = arg0;
    sp10.unk2 = arg1;
    sp10.unk10 = 1;
    func_800995E8(&sp10);
}

void func_8007CBBC(int arg0) { func_8009CC20(arg0, 1); }

void func_8007CBDC(int arg0, int arg1, int arg2)
{
    func_8007C8F8_t sp10;

    sp10.unk0 = 7;
    sp10.unk1 = arg0;
    sp10.unk2 = arg1;
    sp10.unk10 = 2;
    sp10.unk11 = arg2;
    func_800995E8((func_8007C8F8_t*)&sp10);
}

void func_8007CC18(int arg0, int arg1, int arg2)
{
    func_8007C8F8_t sp10;

    sp10.unk1 = arg0;
    sp10.unk0 = 9;
    sp10.unk2 = arg1;
    sp10.unk11 = arg2;
    func_800995E8(&sp10);
}

void func_8007CC4C() { func_8009D208(); }

void func_8007CC6C() { func_8009CE9C(); }

void func_8007CC8C() { func_8009CFA0(); }

void func_8007CCAC() { func_800995B0(); }

void func_8007CCCC(int arg0)
{
    D_8005E0C8 = arg0;
    func_80098160();
}

void func_8007CCF0(int arg0)
{
    D_8005E248 = arg0;
    SetGeomScreen(arg0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007CD14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007CD70);

void func_8007CE74(int arg0)
{
    if ((arg0 == -0x300) || (arg0 == -0x80)) {
        D_800F19D4 = arg0;
        return;
    }
    D_800F19D4 = -0x180;
}

void func_8007CEA0() { func_8009E5C4(); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007CEC0);

u_int func_8007CF18(int arg0)
{
    u_int i;

    for (i = 0; i < 16; ++i) {
        if ((D_800F1928[i] != 0) && (D_800F1928[i]->unk18 == arg0)) {
            return i;
        }
    }
    return 1;
}

D_800F1928_t* func_8007CF64(int arg0) { return D_800F1928[arg0]; }

u_int func_8007CF80(int arg0)
{
    u_int i;
    u_int var_a2;

    var_a2 = 0;
    for (i = 0; i < 16; ++i) {
        if ((D_800F1928[i] != 0) && (D_800F1928[i]->unk1C == arg0)) {
            ++var_a2;
        }
    }
    return var_a2;
}

u_char func_8007CFCC(int arg0)
{
    if (D_800F1928[arg0] != 0) {
        return D_800F1928[arg0]->unk26;
    }
    return 0;
}

void func_8007CFF8(int arg0, short* arg1)
{
    func_800A0A1C(arg0, 2);
    func_800E527C(arg0, arg1[0], arg1[2]);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D03C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D08C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D15C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D1A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D260);

u_int func_8007D2B4(u_int arg0)
{
    if ((arg0 - 1) < 0xFF) {
        return (D_8004B9DC[arg0].flags1 >> 0xF) & 1;
    }
    return 0;
}

void func_8007D2FC(u_int arg0)
{
    if ((arg0 - 1) < 0xFF) {
        D_8004B9DC[arg0].flags1 |= 0x8000;
    }
}

void func_8007D340(int arg0) { func_8006A228(arg0, 0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D360);

void func_8007D3F8()
{
    D_800F1ABC = 0;
    func_8007D360();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D41C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D734);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007DD50);

void func_8007DDAC(int arg0) { D_800F1A2C = arg0; }

void func_8007DDB8(int* arg0)
{
    D_800F1A30[0] = arg0[0];
    D_800F1A30[1] = arg0[1];
}

void func_8007DDD4(D_800F1A78_t* arg0) { D_800F1A78 = *arg0; }

void func_8007DDF8(D_800F1A68_t* arg0) { D_800F1A68 = *arg0; }

void func_8007DE2C(int arg0) { D_800F1B9C = arg0; }

void func_8007DE38(int arg0) { D_800F1A20 = arg0; }

void func_8007DE44(u_int arg0)
{
    if (arg0 < 0x800) {
        D_800F1A44 = arg0;
    }
}

void func_8007DE5C(int arg0) { D_800F1A40 = arg0; }

int func_8007DE68() { return D_800F1B98; }

short func_8007DE78() { return D_800F1A2C; }

void func_8007DE88(int* arg0)
{
    arg0[0] = *D_800F1A30;
    arg0[1] = *D_800F1A30;
    arg0[2] = 0;
}

void func_8007DEA8(D_800F1A78_t* arg0) { *arg0 = D_800F1A78; }

void func_8007DECC(D_800F1A68_t* arg0) { *arg0 = D_800F1A68; }

int func_8007DF00() { return D_800F1B9C; }

int func_8007DF10() { return D_800F1A20; }

int func_8007DF20() { return D_800F1A44; }

int func_8007DF30() { return D_800F1A40; }

void func_8007DF40() { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007DF48);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007DF98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007DFF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E0A8);

int func_8007E180(int arg0)
{
    if (D_800F18F8 == 0) {
        D_800F18F8 = arg0;
        return 1;
    }
    nop9(0x66, 0);
    return 0;
}

int func_8007E1C0(int arg0)
{
    if (D_800F18F8 == arg0) {
        D_800F18F8 = 0;
        return 1;
    }
    nop9(0x67, 0);
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E200);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E2AC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E380);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E454);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E5E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E6A0);

void func_8007E974() { }

int func_8007E97C() { return D_800F1A04 != 0 ? 0x64 : 0xFF; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E99C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007EA74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007ECA8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007EEFC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F138);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F1A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F230);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F434);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F4B0);

int func_8007F518(u_char* arg0) { return D_800F1928[*arg0]->unk3C->unk43 & 7; }

int func_8007F548() { return 0; }

int func_8007F550() { return 1; }

int func_8007F558() { return 1; }

int func_8007F560() { return 1; }

int func_8007F568(int arg0 __attribute__((unused)), u_char* arg1)
{
    return func_8007F518(arg1) == 2;
}

int func_8007F58C(int arg0 __attribute__((unused)), u_char* arg1)
{
    return func_8007F518(arg1) != 2;
}

int func_8007F5B0() { return 0; }

int func_8007F5B8() { return 0; }

int func_8007F5C0() { return 0; }

int func_8007F5C8() { return func_8007F4B0(5) == 0; }

int func_8007F5E8() { return func_8007F4B0(7) == 0; }

int func_8007F608() { return func_8007F4B0(9) == 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F628);

int func_8007F6D8() { return func_8007F4B0(4) == 0; }

int func_8007F6F8() { return func_8007F4B0(6) == 0; }

int func_8007F718() { return func_8007F4B0(8) == 0; }

int func_8007F738() { return func_8007F4B0(0xA) == 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F758);

int func_8007F808() { return func_8007F4B0(0xB) == 0; }

int func_8007F828() { return func_8007F4B0(0xC) == 0; }

int func_8007F848() { return func_8007F4B0(0x12) == 0; }

int func_8007F868() { return func_8007F4B0(0x11) == 0; }

int func_8007F888() { return func_8007F4B0(0xD) == 0; }

int func_8007F8A8() { return func_8007F4B0(0xE) == 0; }

int func_8007F8C8() { return func_8007F4B0(0xF) == 0; }

int func_8007F8E8() { return func_8007F4B0(0x10) == 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F908);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F96C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007F9D0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FA34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FA98);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FB34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FBD0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FC6C);

int func_8007FD08() { return func_8007F4B0(0x1D) == 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FD28);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FD74);

void func_8007FDC0() { }

void func_8007FDC8() { }

void func_8007FDD0() { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FDD8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FE5C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007FF8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80080000);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008010C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800801A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800801E0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800802C4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800803A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80080534);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800807E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80080A9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80080C9C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80080F78);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80081020);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800810CC);

void func_80081130() { }

short func_80081138() { return D_800F1A08; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80081148);

short func_800819D0(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    return func_80081148(arg0, arg1, arg2, arg3, arg4, 0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800819FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80082144);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800821B0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80082234);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800822A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008231C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80082360);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008241C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800824D8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008255C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800829B8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80082FF4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083430);

short func_800834A4(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), u_char* arg2)
{
    return D_800F1928[*arg2]->unk3C->unk1A - D_800F1928[*arg2]->unk3C->unk18;
}

short func_800834E4(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), u_char* arg2)
{
    return D_800F1928[*arg2]->unk3C->unk1E - D_800F1928[*arg2]->unk3C->unk1C;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083524);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083590);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008364C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083708);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008379C);

short func_8008381C(int arg0 __attribute__((unused)), u_char* arg1)
{
    return D_800F1928[*arg1]->unk3C->unkAC;
}

short func_8008384C(u_int* arg0, int arg1 __attribute__((unused)),
    int arg2 __attribute__((unused)), int arg3)
{
    arg0 += arg3;
    return (D_800F1A08 * ((arg0[5] >> 0x16) & 0x1F)) / 10;
}

short func_8008388C(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    return func_80081148(arg0, arg1, arg2, arg3, arg4, 1);
}

short func_800838BC(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), u_char* arg2)
{
    return D_800F1928[*arg2]->unk3C->unk20;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800838EC);

void func_80083990() { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083998);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800839E8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083A38);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083A88);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083AD8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083B28);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083B78);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083BC8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083C18);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083C68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083CB8);

void func_80083D08(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), int arg2)
{
    func_80081020(0x12, arg2);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083D2C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083D7C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083DEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083E3C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083E8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80083EDC);

void func_80083F2C(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), int arg2)
{
    func_80081020(0x15, arg2);
}

void func_80083F50(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), int arg2)
{
    func_80081020(0x16, arg2);
}

void func_80083F74(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), int arg2)
{
    func_80081020(0x17, arg2);
}

void func_80083F98(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), int arg2)
{
    func_80081020(0x18, arg2);
}

void func_80083FBC(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), int arg2)
{
    func_80081020(0x19, arg2);
}

void func_80083FE0(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), int arg2)
{
    func_80081020(0x1A, arg2);
}

void func_80084004(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), int arg2)
{
    func_80081020(0x1B, arg2);
}

void func_80084028(
    int arg0 __attribute__((unused)), int arg1 __attribute__((unused)), int arg2)
{
    func_80081020(0x1C, arg2);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008404C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008409C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800840EC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008413C);

void func_8008418C(int arg0 __attribute__((unused)), int arg1 __attribute__((unused)),
    func_8008418C_t* arg2)
{
    arg2->unk18 |= (D_800F1928[arg2->unk0]->unk3C->unk948 & 0x1FFE1FE0);
    ;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800841C8);

void func_80084228(int arg0 __attribute__((unused)), int* arg1)
{
    arg1[7] = ((arg1[7] & 0xF3FFFFFF) | 0x08000000);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084248);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800842AC);

void func_800842F0(int arg0 __attribute__((unused)), int* arg1)
{
    arg1[7] = ((arg1[7] & 0xF3FFFFFF) | 0x08000000);
}

void func_80084310(int arg0 __attribute__((unused)), int arg1 __attribute__((unused)),
    int arg2 __attribute__((unused)), int arg3 __attribute__((unused)), int arg4)
{
    if (arg4 != 0) {
        func_800BEC14(0x40, 1);
    }
}

void func_80084340(int arg0 __attribute__((unused)), int arg1 __attribute__((unused)),
    int arg2 __attribute__((unused)), int arg3 __attribute__((unused)), int arg4)
{
    if (arg4 != 0) {
        func_800BEC14(0x20, 1);
    }
}

void func_80084370(int arg0 __attribute__((unused)), int* arg1)
{
    arg1[7] = ((arg1[7] & 0xF3FFFFFF) | 0x08000000);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084390);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084440);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800844F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084570);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800845F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084670);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800846F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084770);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800847F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084870);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008490C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084958);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800849A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800849F0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084A3C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084A8C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084AD8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084B24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084B70);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084CAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084D44);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084DA8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084E28);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084EA0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084EEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084F40);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80084F94);

void func_80084FF0() { }

void func_80084FF8() { }

void func_80085000() { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80085008);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80085390);

void func_800856F8(void* arg0) { vs_main_bzero(arg0, 0x84C); }

void func_80085718(func_80085718_t* arg0)
{
    vs_main_bzero(arg0, 0x44);
    arg0->unk3 = 6;
    arg0->unk1C = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008574C);

void func_80085978(int arg0, int arg1)
{
    func_8008574C(arg0, D_800F1928[arg1]->unk3C, 0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800859B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80085A34);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80085B10);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008631C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800863A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80086754);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80086EA4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80086EF4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80086FA8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80087578);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800875C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80087EF4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800882F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088554);

void func_80088B6C() { func_80088554(); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088B8C);

void func_80088CA0() { D_800E8498 = 0; }

void func_80088CAC()
{
    if (D_8005046A == 2) {
        func_8007BCCC();
    }
    func_80069DBC();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088CE4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088D40);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088E08);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088EF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089098);

int func_80089104() { return D_800F18A8; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089114);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089888);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089A00);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089C5C);

void func_80089CE4() { SetDispMask(1); }

void func_80089D04() { SetDispMask(0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089D24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089DC0);

void func_8008A364()
{
    int i;

    for (i = 2; i < 16; ++i) {
        func_8006A228(i, 0);
    }
}

// https://decomp.me/scratch/w2WqI
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008A3A0);

void func_8008A4DC(int arg0)
{
    if (arg0 != 0) {
        D_800F190C = 1;
    } else {
        D_800F190C = 0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008A4FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008A5D0);

void func_8008A6FC()
{
    int* temp_s0;
    int* var_a0;

    var_a0 = D_800F1900;
    while (var_a0 != 0) {
        temp_s0 = (int*)*var_a0;
        vs_main_freeHeapR(var_a0);
        var_a0 = temp_s0;
    }
    D_800F1900 = 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008A744);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008A908);

void func_8008AB68() { D_8006169D = D_800F1BBE + 1; }

int func_8008AB80(int arg0)
{
    if ((D_800F1BF8.unk0 == 1) && (D_800F1BF8.unk2 == arg0)) {
        D_800F1BF8.unk1 = D_800F1BF8.unk0;
        return 1;
    }
    return 0;
}

int func_8008ABB8(int arg0)
{
    if ((D_800F1BF8.unk0 == 1) && (D_800F1BF8.unk2 == arg0)) {
        D_800F1BF8.unk1 = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008ABF0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008AC78);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B1FC);

void func_8008B28C()
{
    if (D_800F1BA4 == 0) {
        D_800F1CDC += vs_gametime_tickspeed;
    }
}

void func_8008B2C0(int arg0)
{
    if (D_800F1BF8.unk0 != 0) {
        D_800F1BF8.unk1 = arg0;
    }
}

void func_8008B2E0(void* arg0, int arg1, int arg2, int arg3)
{
    vs_main_memcpy(D_800F1BA8 + (((arg1 * 256) + arg2)), arg0, arg3 * 2);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B320);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B390);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B430);

void func_8008B4B0() { D_800F1BB6 = 0; }

void func_8008B4BC(int arg0) { D_800F1BA4 = arg0; }

int func_8008B4C8(u_char arg0) { return D_800F1CD6 = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B4D8);

void func_8008B588() { }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B590);

void func_8008B6B4()
{
    D_800F1D6A = 0;
    D_800F1D6C = 0;
    vs_main_bzero(&D_800F1D28, 0x40);
}

int func_8008B6EC() { return D_800F1C64; }

int func_8008B6FC() { return D_800F1C70; }

int func_8008B70C()
{
    if (D_800F1C60 != 0) {
        return (D_800F1C60->unk2 << 0x14) | ((u_short)(D_800F1C60->unk0 * 0x10));
    }
    return 0;
}

int func_8008B744()
{
    if (D_800F1CB8 != 0) {
        return D_800F1CB8;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B764);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B808);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B8F8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B960);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008BAC8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008BC04);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008BD74);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008BEBC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008BF48);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C070);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C0C0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C1C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C2C0);

void func_8008C40C()
{
    int temp_a1;
    int i;
    int* var_a0;

    var_a0 = D_800F1C5C + 1;
    if (D_800F1C5C != 0) {
        temp_a1 = D_800F1C5C[0];
        for (i = 0; i < temp_a1; ++i) {
            *var_a0 &= ~0x1000;
            var_a0 += 16;
        }
    }
}

void func_8008C458(int arg0) { func_80098B38(arg0, 0); }

int func_8008C478(int arg0)
{
    if (D_800F1C74 != 0) {
        return D_800F1C74 + (arg0 * 8);
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C49C);

void func_8008C518(int arg0) { func_8008C49C(arg0, -1); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C538);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C6B4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C8A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008CEB0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D2C0);

u_char func_8008D3D0() { return D_800F1C84->unk30; }

u_char func_8008D3E8() { return D_800F1C84->unk31; }

short func_8008D400() { return D_800F1C84->unk34[0xE]; }

int func_8008D418() { return (D_800F1C84->unk34[0xF] << 0x10) | D_800F1C84->unk34[0x10]; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D438);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D508);

void func_8008D594(int arg0) { D_800F1D6E = arg0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D5A0);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D5FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D658);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D710);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D820);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D880);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008D948);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DA24);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DC7C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DD0C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DDA8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DEAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DF14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E19C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E224);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E2D4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E320);

int func_8008E370(int* arg0)
{
    if (D_800F1BF8.unkAC != 0) {
        *arg0 = D_800F1BF8.unk2C[8] / 564;
        return D_800F1BF8.unkAC;
    }
    *arg0 = 0;
    return 0;
}

int func_8008E3B8(int* arg0)
{
    if (D_800F1BF8.unk88 != 0) {
        *arg0 = D_800F1BF8.unk28 / 20;
        return D_800F1BF8.unk88;
    }
    *arg0 = 0;
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E400);

int func_8008E470() { return D_800F1CA8 < 1; }

void func_8008E480(int arg0)
{
    func_800938AC();
    func_800918E8(arg0);
}

short func_8008E4AC() { return D_800F1C84->unk56; }

u_char func_8008E4C4() { return D_800F1C84->unk32; }

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", D_80068BEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E4DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E5F0);

void func_8008E6A8(void* arg0)
{
    if (D_800F1CA4 != 0) {
        vs_main_memcpy(D_800F1CA4 + 5, arg0, 0x220);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E6DC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E7BC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E88C);

void func_8008E8F8()
{
    if (D_800F1DD4 != 0) {
        vs_main_freeHeap(D_800F1DD4);
    }
    D_800F1DD4 = vs_main_allocHeap(0x800);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008E938);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008EA90);

void func_8008EAE4(short arg0, short arg1)
{
    D_800F1DB8 = arg0;
    D_800F1DBA = arg1;
}

void func_8008EAF8(int arg0) { D_800F1DC9 = arg0; }

void func_8008EB04(int* arg0, int* arg1)
{
    *arg0 = D_800F1DCA;
    *arg1 = D_800F1DC4;
}

int* func_8008EB24() { return &D_800F1D78; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008EB30);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008EC48);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008EFCC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008F0FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008F234);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008F29C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008F30C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008F440);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008F9A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008FA14);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008FAC8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008FDC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80090434);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80090A1C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80090B28);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", D_80068C1C);

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", D_80068EB4);
