#include "common.h"
#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#include <rand.h>
#include "146C.h"
#include "2842C.h"
#include "2EA3C.h"
#include "30D14.h"
#include "38C1C.h"
#include "3A1A0.h"
#include "44F14.h"
#include "4A0A8.h"
#include "573B8.h"
#include "58578.h"
#include "5BF94.h"
#include "6E644.h"
#include "../../SLUS_010.40/main.h"
#include "../../SLUS_010.40/31724.h"
#include "../../SLUS_010.40/32154.h"
#include <abs.h>

typedef struct {
    u_char unk0;
    char unk1;
    short unk2;
    short unk4;
    char unk6;
    char unk7;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
} func_8008418C_t;

typedef struct {
    u_char unk0;
    signed char unk1;
    char unk2;
    signed char unk3;
    short unk4;
    short unk6;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    short unk10;
    short unk12;
    int unk14;
    int unk18;
    union {
        struct {
            u_int unk1C_0 : 2;
            u_char unk1C_2 : 2;
            u_char unk1C_4 : 2;
            u_char unk1C_6 : 2;
            u_char unk1D_0 : 2;
            u_char unk1D_2 : 2;
            u_char unk1D_4 : 2;
            u_char unk1D_6 : 2;
            u_char unk1E_0 : 2;
            u_char unk1E_2 : 2;
            u_char unk1E_4 : 2;
            u_char unk1E_6 : 2;
            u_char unk1F_0 : 2;
            u_char unk1F_2 : 2;
            u_char unk1F_4 : 4;
        } fields;
        int value;
    } unk1C;
    union {
        short s16[7][2];
        int s32[7];
    } unk20;
    short unk3C;
    short unk3E;
    int unk40;
} func_80085718_t;

typedef struct {
    u_char unk0;
    signed char unk1;
    char unk2;
    char unk3;
    short unk4;
    short unk6;
} func_8008631C_t2;

typedef struct {
    u_short unk0;
    char unk2;
    char unk3;
    u_char unk4;
    char unk5;
    short unk6;
    short unk8;
    short unkA;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    short unk48;
    short unk4A;
    union {
        func_8008631C_t2 unk;
        SVECTOR vec;
    } unk4C;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90[491];
    short unk83C; // These three are probably a vector
    short unk83E;
    short unk840;
    short unk842;
    SVECTOR unk844;
} func_8008631C_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
} D_800F19CC_t3;

typedef struct {
    int unk0;
    int unk4;
} D_800F19CC_t4;

typedef struct {
    char unk0;
    signed char unk1;
    char unk2;
    char unk3;
    char unk4;
    char unk5;
    char unk6;
    char unk7;
} func_8006C4C4_t2;

typedef struct {
    union {
        func_8006C4C4_t2 unk;
        SVECTOR vec;
    } unk0;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
} func_8006C4C4_t3;

typedef struct {
    u_short unk0;
    char unk2;
    char unk3;
    D_800F19CC_t3 unk4;
    int unk44;
    u_short unk48;
    u_short unk4A;
    func_8006C4C4_t3 unk4C[30];
    SVECTOR unk844;
} D_800F19CC_t2;

typedef struct {
    SVECTOR unk0;
    char unk8;
    char unk9;
    char unkA;
    char unkB;
    char unkC;
    char unkD;
    short unkE;
    int unk10;
    int unk14;
} D_800F19CC_t5;

typedef struct {
    u_int unk0;
    u_int unk4;
    func_8008631C_t unk8;
    D_800F19CC_t2 unk854[4];
    int unk2984;
    int unk2988;
    u_char unk298C;
    u_char unk298D;
    char unk298E;
    char unk298F;
    int unk2990;
    int unk2994;
    SVECTOR unk2998;
    int unk29A0;
    int unk29A4;
    short unk29A8;
    short unk29AA;
    short unk29AC;
    short unk29AE;
    int unk29B0;
    int unk29B4;
    int unk29B8;
    int unk29BC;
    D_800F19CC_t5 unk29C0[23];
    int unk2BE8;
    int unk2BEC;
    int unk2BF0;
    int unk2BF4;
    int unk2BF8;
    int unk2BFC;
    u_short unk2C00;
    char unk2C02;
    char unk2C03;
    char unk2C04;
    char unk2C05;
    char unk2C06;
    char unk2C07;
    short unk2C08;
    u_short unk2C0A;
    short unk2C0C;
    short unk2C0E;
} D_800F19CC_t;

typedef struct {
    char unk0;
    signed char unk1;
    char unk2;
    char unk3;
    short unk4;
    short unk6;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    short unk20;
    short unk22[13];
    short unk3C;
} func_800842AC_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_droppedBlade blade;
    vs_battle_droppedGrip grip;
    vs_battle_droppedGem gems[3];
    char unk94[0x18];
} _setWeaponForDropRand_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_droppedArmor shield;
    vs_battle_droppedGem gems[3];
} _setShieldForDropRand_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_droppedArmor accessory;
} _setAccessoryForDropRand_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    vs_battle_droppedArmor armor;
} _setArmorForDropRand_t;

typedef struct {
    _setWeaponForDropRand_t weapon;
    int unkAC[17];
    _setShieldForDropRand_t shield; // 0xF0
    _setArmorForDropRand_t armor; // 0x170
    int unk19C[11];
    _setAccessoryForDropRand_t accessory; // 0x1C8
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    func_8006BE64_t3 unk214[2];
    u_short unk21C;
    char unk21E;
    char unk21F;
} func_8006BE64_t2;

typedef struct {
    char unk0;
    char unk1;
    short unk2;
    short currentHP;
    short maxHP;
    short currentMP;
    short maxMP;
    short totalStrength;
    short totalIntelligence;
    short totalAgility;
    short unk12[6];
    int unk20;
    int unk24;
} func_80069EF0_t;

typedef struct {
    func_8008C1C8_t* unk0;
    func_8006EBF8_t unk4;
} D_800F1910_t;

typedef struct {
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    short unk4;
    short unk6;
} D_800F1BB0_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
} func_8006EBF8_t2;

typedef struct {
    u_char unk0;
    signed char unk1;
} func_8007F1A4_t;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
    short unk8;
    short unkA;
    char unkC;
    char unkD;
    char unkE;
    char unkF;
} D_800F1DD4_t;

typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
    int unk8;
    char unkC[3][4];
    int unk18;
    int unk1C;
    int unk20;
    char unk24[4];
} D_800E8594_t;

typedef struct {
    int unk0[4];
} func_80077DF0_t2;

typedef struct {
    int unk0[17];
    func_80077DF0_t2 unk44;
} func_80077DF0_t3;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    func_80077DF0_t2 unk10;
} func_80077DF0_t;

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
    int unk20[8];
    int unk40;
} func_80085A34_t;

typedef struct {
    vs_battle_equipment unk0;
    vs_battle_equipment unk30[3];
    char unkC0;
    char unkC1;
    short unkC2;
} func_8006B02C_t;

typedef struct {
    short unk0;
    char unk2;
    char unk3;
    short unk4;
    short unk6;
    char unk8;
    char unk9;
    char unkA;
    char unkB;
    int unkC;
    short unk10;
    short unk12;
    func_8006C4C4_t2 unk14;
    int unk18[50];
} func_8006C4C4_t;

typedef struct {
    int unk0;
    func_8008C1C8_t* unk4;
} D_800F1D28_t;

typedef struct {
    short unk0;
    short unk1;
    short unk2;
    short unk3;
} func_8008D2C0_t;

typedef struct {
    short unk0;
    short unk2;
    union {
        struct {
            u_int unk0_0 : 9;
            u_int unk0_9 : 5;
            u_int unk0_14 : 5;
            u_int unk0_19 : 13;
        } fields;
        int value;
    } unk4;
} D_800F18EC_t;

typedef struct D_800F1900_t {
    struct D_800F1900_t* unk0;
    int unk4;
    func_8006BE64_t2 unk8;
} D_800F1900_t;

typedef struct {
    int unk0;
    int unk4;
    short unk8;
    char unkA;
    char unkB;
    short unkC;
    short unkE;
    int unk10;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
} func_8006F630_t1;

typedef struct {
    u_short unk0;
    char unk2;
    char unk3;
} func_8006F630_t2;

typedef struct {
    u_char unk0_0 : 4;
    char unk0_4 : 4;
    char unk1;
    char unk2;
    char unk3;
    short unk4;
    short unk6;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
} func_8006F630_t3;

typedef struct {
    vs_battle_equipment equip;
    char material;
    char unk31;
    char unk32;
    char unk33;
} func_8006A9F0_t;

typedef struct {
    D_800F1904_t3 unk0;
    int unk2C;
    int unk30;
} D_800F1904_t;

typedef struct {
    D_800F1904_t unk0;
    D_800F1904_t3 unk34;
    int unk60;
    int unk64;
    int unk68;
    D_800F1904_t3 unk6C;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
} D_800F1904_t2;

typedef struct {
    u_short unk0;
    char unk2;
} D_800FAB18_t;

typedef struct {
    vs_battle_equipment unk0;
    vs_battle_equipment unk30;
    vs_battle_equipment unk60[3];
    char unkF0;
    char unkF1;
    short unkF2;
    char unkF4[24];
} vs_battle_droppedWeapon2;

typedef struct {
    int unk0;
    short unk4;
    u_short unk6;
} func_8006CE70_t;

void func_8006A334(vs_battle_weaponInfo*, vs_battle_equipment*);
void func_8006A65C(vs_battle_shieldInfo*, func_8006B02C_t*);
int func_8006BDA0(func_8006BE64_t2*, func_8006BE64_t3*);
int func_8006BDF0(func_8006BE64_t2*, func_8006BDF0_t*);
void func_8006DFE0(func_8006EBF8_t2*);
void func_8006C350(void);
void func_8006C39C(void);
void func_8006C40C(void);
void func_8006C5AC(int);
void func_80069DEC(int, int);
int func_8006A228(u_int, int);
void func_8006A8EC(vs_battle_accessoryInfo*, func_8006A9F0_t*);
void func_8006A9F0(vs_battle_armorInfo* arg0, func_8006A9F0_t* arg1);
void vs_battle_setEquipmentForDrop(
    vs_battle_droppedArmor*, vs_battle_equipment* equipment);
void func_8006B214(void);
void func_8006B2D4(void);
void func_8006C004(vs_battle_actor*);
void func_8006C164(int);
void func_8006D0A4(u_int*);
void func_8006D9FC(func_80077DF0_t*, func_80077DF0_t*);
int func_8006DB98(SVECTOR* arg0, int*, int*, int, int);
int func_8006DEFC(SVECTOR*, int, int);
void func_8006E158(void);
void func_8006EF5C(VECTOR*);
int func_8006F204(void);
void _setRoomSeen(void);
void func_8006F5CC(void);
void func_8006F89C(void);
void func_8006FA20(void);
void func_80070278(void);
void func_8007053C(void);
void func_80070F28(int);
void func_8007138C(void);
void func_80072BA8(int);
void func_80072EC4(int, u_short);
void func_800732AC(void);
void func_80073718(void);
void func_80073D30(func_8008C1C8_t*, func_8006EBF8_t*, int);
void func_80073E30(func_8008C1C8_t*, int);
void func_80076784(int, vs_battle_actor2*, void*, int);
int func_80074798(func_8006EBF8_t*, char*);
void func_80074B14(int arg0, char* arg1);
void func_80076D50(u_int, int, int, int, int);
void func_80077130(vs_battle_actor*, int, int, int, int);
vs_battle_actor_dat* func_80077240(int, int, int, int, int, int, int*, int);
void func_800773BC(vs_battle_actor*, int, int, int, int, int);
void func_800780A8(SVECTOR*);
int func_80078828(int);
int func_800792E4(int arg0, int arg1, int arg2);
int func_8007A850(D_800F1904_t3*);
void func_8007A9DC(VECTOR*, VECTOR*, VECTOR*);
void func_8007AACC(VECTOR* arg0);
void func_8007AC94(int arg0);
void func_8007B10C(int, int, int, short, short);
void func_8007B1B8(int, int, short, short, short);
void func_8007B29C(int arg0, int arg1, int arg2, short arg3, short arg4, short arg5);
void func_8007B410(void);
void func_8007B63C(void);
void func_8007B470(void);
void func_8007B508(void);
void func_8007B764(void);
void func_8007B7DC(int, int);
void func_8007BCCC(void);
int func_8007BD8C(int arg0);
void func_8007BF6C(int);
void func_8007BFF8(int);
void func_8007C0AC(int, int);
int func_8007C4E0(D_80061068_t*, int, int);
int func_8007C5C0(D_80061068_t*, int, int);
int func_8007C694(int, int, int, int, int);
void func_8007CCCC(int arg0);
void func_8007CD14(int arg0, int arg1);
void func_8007CD70(VECTOR* arg0, VECTOR* arg1, int arg2, int arg3);
int _getLocationId(int, int);
int func_8007D08C(int, int);
void func_8007D360(void);
void func_8007D41C(void);
void _calculateWeaponClassAffinity(vs_battle_actor2*);
int func_8007E454(int);
short func_8007E6A0(vs_skill_t*, vs_battle_actor2*, int);
int func_8007F230(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4);
int func_8007F434(void);
int func_8007F4B0(int arg0, u_char* arg1);
int func_8007F518(u_char*);
void func_80080000(vs_skill_t*, func_80085718_t*, short);
void func_800801E0(vs_skill_t*, func_80085718_t*, short);
void func_800802C4(vs_skill_t*, vs_battle_actor2*, vs_battle_actor2*, int);
void func_800803A4(vs_skill_t*, vs_battle_actor2*, vs_battle_actor2*, int);
void func_80080534(vs_skill_t*, vs_battle_equipment*, int, int, int);
void func_80080A9C(vs_skill_t* arg0, vs_battle_equipment*, int, int, int);
int func_80081020(int, func_80085718_t*);
int func_800810CC(int, func_80085718_t*);
short func_80081148(vs_skill_t*, func_80085718_t*, func_80085718_t*, int, int, int);
short func_800838EC(vs_skill_t*, func_80085718_t*, func_80085718_t*, int, int);
int func_8008574C(u_int, vs_battle_actor2*, int, int);
// Aliased at link time
int func_8008574C_alias(u_int, vs_battle_actor2*, int);
void func_80085008(func_80085718_t*);
void func_80085390(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4);
void func_80085B10(int, D_800F19CC_t2*, func_8008631C_t*, int);
void func_80086754(int, vs_battle_actor2*);
void func_800875C8(D_800F19CC_t3*);
void func_80088554(void);
void func_80088CA0(void);
int func_8008ABF0(int arg0);
void func_8008B320(void);
void func_8008B390(int arg0, int* arg1);
int func_8008B4C8(char arg0);
void func_8008C40C(void);
static void _loadZnd(int id);
void func_80089CE4(void);
void func_80089D04(void);
void func_80089D24(int arg0);
void func_8008A6FC(void);
int func_8008AB80(int);
int func_8008ABB8(int);
void func_8008B2E0(void* arg0, int arg1, int arg2, int arg3);
void func_8008B4BC(int arg0);
void _nop(int arg0);
func_8008B764_t* func_8008B764(u_int arg0, u_int arg1, int arg2);
void func_8008B8F8(char (*arg0)[12]);
void func_8008B960(int, int, int);
func_8008C1C8_t* func_8008BC04(int, int, int);
void func_8008BD74(func_8008C1C8_t*);
int func_8008BEBC(func_8008C1C8_t* arg0);
int func_8008BF48(func_8008C1C8_t*);
void func_8008C070(int arg0, func_8008C1C8_t* arg1);
int func_8008C1C8(func_8008C1C8_t* arg0);
void func_8008C2C0(char, char, char, int);
int func_8008C49C(int, int);
void func_8008C538(void);
void func_8008C6B4(int, int);
D_800F1910_t2* func_8008D438(int, int, int);
func_8008D710_t* func_8008D508(int arg0, int arg1, int arg2);
void func_8008D5A0(int);
void func_8008D594(int arg0);
void func_8008D5FC(func_8008C1C8_t* arg0);
void func_8008D658(func_8008C1C8_t*);
void func_8008D710(void);
void _setDoorEntered(int arg0);
int _getDoorId(int);
short func_8008DC7C(int arg0, int arg1);
void func_8008DEAC(D_800F1910_t2* arg0, int arg1);
func_8008D710_t* func_8008E370(int* arg0);
func_8008C1C8_t* func_8008E3B8(int* arg0);
void func_8008E480(int arg0);
void func_8008E4DC(int);
void func_8008E6DC(int);
void func_8008E8F8(void);
void func_8008E938(void);
int func_8008F234(void);
void func_8008FA14(D_800F1DD4_t*);
void func_80090A1C(D_800F1DD4_t*);
void func_80091378(void);
int* func_8009195C(int);
void func_8009291C(int);
void func_80092A18(void);
int func_80093764(int);
void func_80093824(int);
void func_80093A14(void);
void func_80093B04(void*);
void func_80093B68(void);
void func_80093FEC(int, int, int, int);
void func_800936F8(int);
void func_80093914(char);
void func_80095B7C(int, int);
void func_80096768(int, int, int);
void func_8009723C(void*, int);
void func_80098194(int);
void func_800983F8(void*);
void func_80098D6C(int, int, D_800F1BB0_t*, int);
void func_80099960(u_short*);
void func_8009D458(void);
void func_8009D6F4(void);
void func_8009D7E8(int, int);
void func_8009DF3C(int, int);
void func_8009E070(int, short*, int);
int func_8009E480(void);
u_int func_8009E4B0(char);
void func_8009EA14(int, SVECTOR*);
void func_8009F990(int, char*);
void func_8009FC60(int, int, int, int);

extern const short D_80068BEC[];
extern int D_80068C1C[];
extern char D_800E8184[];
extern char D_800E81E4[];
extern u_char D_800E8200[];
extern int (*D_800E8234[])(vs_skill_t*, func_80085718_t*, func_80085718_t*, int, int);
extern int (*D_800E8254[])(vs_skill_t*, char*);
extern void (*D_800E8378[])(vs_skill_t*, func_80085718_t*, func_80085718_t*, int, int);
extern short (*D_800E830C[])(vs_skill_t*, func_80085718_t*, func_80085718_t*, int, int);
extern int D_800E8498;
extern short D_800E849C[];
extern char D_800E84AC[][4];
extern D_800E8594_t D_800E8594;
extern char D_800E85A0[];
extern int D_800F1858;
extern int D_800F185C;
extern int D_800F1860;
extern int D_800F1864;
extern int D_800F1868;
extern int D_800F186C;
extern void* D_800F1884;
extern int D_800F18A8;
extern int D_800F18AC;
extern int D_800F18B0;
extern void* D_800F18E4;
extern u_int D_800F18F0;
extern char D_800F18F8;
extern int D_800F18FC;
extern D_800F1900_t* D_800F1900;
extern D_800F1904_t2* D_800F1904;
extern int D_800F190C;
extern D_800F1910_t D_800F1910;
extern vs_battle_actor* D_800F192C;
extern int D_800F1968;
extern int D_800F196C;
extern int D_800F19A0;
extern char D_800F19A8[];
extern int D_800F19C8;
extern D_800F19CC_t* D_800F19CC;
extern int D_800F1A00;
extern int D_800F1A04;
extern u_int D_800F1A08;
extern int D_800F1A0C;
extern short D_800F1A10[];
extern int D_800F1A20;
extern short D_800F1A28[];
extern short D_800F1A2C;
extern int D_800F1A30[];
extern int D_800F1A40;
extern u_int D_800F1A44;
extern u_int D_800F1A48;
extern D_800F1A68_t D_800F1A68;
extern D_800F1A78_t D_800F1A78;
extern int D_800F1A98;
extern char D_800F1A9C[];
extern int D_800F1AA4;
extern int D_800F1AA8;
extern void* D_800F1ABC;
extern int D_800F1B98;
extern int D_800F1B9C;
extern u_short D_800F1BA4;
extern D_800F1BB0_t D_800F1BB0;
extern short D_800F1BB6;
extern int D_800F1BB8;
extern short vs_battle_doorEntered;
extern D_800F1BF8_t D_800F1BF8;
extern u_short D_800F1CCA;
extern int D_800F1CC0;
extern char D_800F1CD6;
extern short D_800F1CDC;
extern D_800F1D28_t D_800F1D28[8];
extern short D_800F1D6A;
extern short D_800F1D6C;
extern int D_800F1D78[5];
extern char D_800F1DC7;
extern short D_800F1D68;
extern signed char D_800F1D6E;
extern char D_800F1D6F;
extern u_char D_800F1D70[];
extern short D_800F1D98[];
extern vs_main_CdQueueSlot* D_800F1DAC;
extern vs_main_CdQueueSlot* D_800F1DB0;
extern short D_800F1DB4;
extern short D_800F1DB6;
extern short D_800F1DB8;
extern short D_800F1DBA;
extern short D_800F1DBC;
extern short D_800F1DBE;
extern short D_800F1DC0;
extern short D_800F1DC2;
extern short D_800F1DC4;
extern char D_800F1DC6;
extern char D_800F1DC8;
extern signed char D_800F1DC9;
extern char D_800F1DCA;
extern char D_800F1DCB;
extern int* D_800F1DCC;
extern int* D_800F1DD0;
extern D_800F1DD4_t* D_800F1DD4;
extern short D_800F5160;

extern int D_1F800000[];
extern int D_1F800034[];
extern int D_1F800064[];

// invoked when using Grimoires, Casting Spells or using Break Arts (but not Battle
// Abilities or Items) invoked just before the skill takes effect
void func_80069C6C(int arg0)
{
    if (arg0 == 0) {
        D_800F19CC_t3* new_var2 = &D_800F19CC->unk854[D_800F19CC->unk0 & 3].unk4;
        if (new_var2->unk0 == 0) {
            return;
        }
        // TODO: Remove dead code
        switch (new_var2->unk0 != 0) {
        case 0:
            return;
        }
        if ((D_800F19CC->unk2C0A == 0) && (func_80078828(0) != 0)) {
            D_800F19CC->unk2C0A = D_800F19CC->unk2C08 + (vs_gametime_tickspeed * 2);
        }
    }
}

void func_80069D14(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        vs_battle_actor* actor = vs_battle_actors[i];
        if ((actor != NULL) && (actor->unk8 == 0x80)
            && (vs_battle_actors[i]->unk9 == 0x18)) {
            actor->unk8 = 8;
        }
    }
}

void func_80069D78(void)
{
    func_8007A850(NULL);
    D_1F800000[4] = ((D_1F800000[4] & 0x7FFF) | (D_800F186C << 0x10));
}

void func_80069DBC(void)
{
    D_80060064 = 0;
    vs_main_bzero(D_80061078, sizeof D_80061078);
}

void func_80069DEC(int arg0, int arg1)
{
    int i;

    for (i = 0; i < 4; ++i) {
        if ((D_80061078[i].unk2 == arg0) && (D_80061078[i].unk1 == arg1)) {
            vs_main_bzero(D_80061078[i].unk8, 0x140);
        }
    }
}

void* func_80069E80(int arg0)
{
    int i;
    void* var_a3 = NULL;

    for (i = 0; i < 8; ++i) {
        if (D_80061078[D_80060064].unk8[i][0] == (arg0 + 1)) {
            var_a3 = &D_80061078[D_80060064].unk8[i];
        }
    }
    return var_a3;
}

void* func_80069EF0(int arg0)
{
    int i;
    void* var_a3;

    var_a3 = NULL;

    for (i = 0; i < 8; ++i) {
        if (D_80061078[D_80060064].unk8[i][0] == (arg0 + 1)) {
            var_a3 = &D_80061078[D_80060064].unk8[i];
            break;
        }
    }
    if (var_a3 == NULL) {
        i = D_80061078[D_80060064].unk4;
        var_a3 = &D_80061078[D_80060064].unk8[i];
        ++D_80061078[D_80060064].unk4;

        if (D_80061078[D_80060064].unk4 >= 8) {
            D_80061078[D_80060064].unk4 = 0;
        }
    }
    return var_a3;
}

void func_80069FC4(int arg0, int arg1)
{
    func_8006EBF8_t sp10;
    int i;
    func_80069EF0_t* temp_v0;
    vs_battle_actor* temp_s0;
    vs_battle_actor2* temp_s1;

    temp_s0 = vs_battle_actors[arg0];

    if (temp_s0 != NULL) {
        if (temp_s0->unk27 != 0x80) {
            temp_s1 = temp_s0->unk3C;
            temp_v0 = func_80069EF0(temp_s0->unk27);
            temp_v0->unk0 = temp_s0->unk27 + 1;
            temp_v0->currentHP = temp_s1->currentHP;
            temp_v0->maxHP = temp_s1->maxHP;
            temp_v0->currentMP = temp_s1->currentMP;
            temp_v0->maxMP = temp_s1->maxMP;
            temp_v0->totalStrength = temp_s1->totalStrength;
            temp_v0->totalIntelligence = temp_s1->totalIntelligence;
            temp_v0->totalAgility = temp_s1->totalAgility;
            for (i = 0; i < 6; ++i) {
                temp_v0->unk12[i] = temp_s1->hitLocations[i].unk0;
            }

            temp_v0->unk20 = temp_s1->unk948;
            if (func_800A0BE0(arg0) & 0x01000000) {
                temp_v0->unk1 = arg1;
                temp_v0->currentHP = 1;
            } else {
                temp_v0->unk1 = arg1;
            }
            temp_v0->unk2 = func_800E6694(arg0);
            func_800A1108(arg0, &sp10);
            func_800A36E0(arg0, temp_s1->unk30, &sp10);
            temp_v0->unk24 = sp10.unk0.unk0.value;
        }
    }
}

int func_8006A11C(vs_battle_actor* arg0)
{
    int i;

    if ((arg0->unk1C & 7) && (arg0->unk4 != 0)) {

        for (i = 0; i < 16; ++i) {
            if ((vs_battle_actors[i] != NULL) && (vs_battle_actors[i]->unk0 == arg0)) {
                return 0;
            }
        }

        if (arg0->unk4 != 0) {
            arg0->unk0 = vs_battle_actors[0]->unk0;
            vs_battle_actors[0]->unk0 = arg0;
        } else {
            arg0->unk0 = NULL;
        }
        return 1;
    }
    return 0;
}

int func_8006A1C4(vs_battle_actor* arg0)
{
    int i;

    if (arg0->unk4 != 0) {
        for (i = 0; i < 16; ++i) {
            if (vs_battle_actors[i] != NULL && vs_battle_actors[i]->unk0 == arg0) {
                vs_battle_actors[i]->unk0 = arg0->unk0;
                arg0->unk0 = NULL;
                return 1;
            }
        }
    }
    return 0;
}

int func_8006A228(u_int arg0, int arg1)
{
    int i;
    vs_battle_actor* temp_s0;

    if (arg0 < 16) {
        temp_s0 = vs_battle_actors[arg0];
        if (temp_s0 != NULL) {
            func_80069FC4(arg0, arg1);
            if (temp_s0->unk1C == 0x10) {
                func_8009F530(arg0);
                func_80099D6C(arg0);
            } else {
                func_8009CFB0(arg0);
                if (temp_s0->unk40 == 2) {
                    func_8009CFB0(arg0 + 4);
                }
            }
            func_800E7454(temp_s0);
            for (i = 0; i < 16; ++i) {
                if (vs_battle_actors[i]->unk0 == temp_s0) {
                    vs_battle_actors[i]->unk0 = temp_s0->unk0;
                    break;
                }
            }
            vs_main_freeHeap(temp_s0);
            vs_battle_actors[arg0] = NULL;
        }
        return 1;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A334);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006A65C);

void func_8006A8EC(vs_battle_accessoryInfo* arg0, func_8006A9F0_t* arg1)
{
    int i;

    vs_main_memcpy(arg0, &arg1->equip, sizeof arg0->accessory);
    arg0->currentStr = arg1->equip.strength;
    arg0->currentInt = arg1->equip.intelligence;
    arg0->currentAgility = arg1->equip.agility;

    arg0->unk36 = arg1->material;
    arg0->unk37 = arg1->unk31;

    for (i = 0; i < 4; ++i) {
        arg0->types[i] = arg1->equip.types[i];
    }

    for (i = 0; i < 6; ++i) {
        arg0->classes[i] = arg1->equip.classes[i];
    }

    for (i = 0; i < 7; ++i) {
        arg0->affinities[i] = arg1->equip.affinities[i];
    }
}

void func_8006A9F0(vs_battle_armorInfo* arg0, func_8006A9F0_t* arg1)
{
    int i;

    vs_main_memcpy(&arg0->armor, &arg1->equip, sizeof arg0->armor);
    arg0->armor.material = arg1->material;
    arg0->currentDp = arg1->equip.currentDp;
    arg0->maxDp = arg1->equip.maxDp;
    arg0->currentStr = arg0->baseStr = arg1->equip.strength;
    arg0->currentInt = arg0->baseInt = arg1->equip.intelligence;
    arg0->currentAgility = arg0->baseAgility = arg1->equip.agility;
    arg0->unk9A = arg1->unk33;

    for (i = 0; i < 4; ++i) {
        arg0->types[i] = arg1->equip.types[i];
    }

    for (i = 0; i < 6; ++i) {
        signed char v = arg1->equip.classes[i];
        arg0->classAffinityCurrent.class[1][i] = v;
        arg0->classAffinityCurrent.class[0][i] = v;
        arg0->classAffinityBaseline.class[i] = v;
    }

    for (i = 0; i < 7; ++i) {
        signed char v = arg1->equip.affinities[i];
        arg0->unk88[i] = 0;
        arg0->classAffinityCurrent.affinity[1][i] = v;
        arg0->classAffinityCurrent.affinity[0][i] = v;
        arg0->classAffinityBaseline.affinity[i] = v;
    }
    arg0->unk98 = arg1->unk31;
    arg0->unk99 = arg1->unk32;
}

void func_8006AB44(vs_battle_equipment* arg0, vs_battle_droppedBlade* arg1)
{
    int i;
    vs_battle_droppedBlade* a3;

    arg0->id = arg1->id;
    arg0->subId = arg1->subId;
    arg0->wepId = arg1->wepId;
    arg0->category = arg1->category;
    arg0->currentDp = arg1->currentDp;
    arg0->maxDp = arg1->maxDp;
    arg0->currentPp = arg1->currentPp;
    arg0->maxPp = arg1->maxPp;
    arg0->strength = arg1->strength;
    arg0->intelligence = arg1->intelligence;
    arg0->agility = arg1->agility;
    arg0->cost = arg1->cost;
    arg0->damageType = arg1->damageType;
    arg0->costType = arg1->costType;
    arg0->unk14 = arg1->unk12;
    arg0->range = arg1->range;
    arg0->index = arg1->index;

    a3 = arg1;
    for (i = 0; i < 6; ++i) {
        arg0->classes[i] = a3->classes[i];
    }

    for (i = 0; i < 7; ++i) {
        arg0->affinities[i] = a3->affinities[i];
    }
    arg0->material = arg1->material;
}

void func_8006AC74(vs_battle_equipment* arg0, vs_battle_droppedGrip* arg1)
{
    int i;

    arg0->id = arg1->id;
    arg0->subId = arg1->subId;
    arg0->category = arg1->category;
    arg0->gemSlots = arg1->gemSlots;
    arg0->strength = arg1->strength;
    arg0->intelligence = arg1->intelligence;
    arg0->agility = arg1->agility;
    arg0->index = arg1->unkE;

    for (i = 0; i < 4; ++i) {
        arg0->types[i] = arg1->types[i];
    }
}

void func_8006ACFC(vs_battle_equipment* arg0, vs_battle_droppedArmor* arg1)
{
    int i;
    vs_battle_droppedArmor* a3;

    arg0->id = arg1->id;
    arg0->subId = arg1->subId;
    arg0->wepId = arg1->wepId;
    arg0->category = arg1->category;
    arg0->currentDp = arg1->currentDp;
    arg0->maxDp = arg1->maxDp;
    arg0->currentPp = arg1->currentPp;
    arg0->maxPp = arg1->maxPp;
    arg0->gemSlots = arg1->gemSlots;
    arg0->strength = arg1->strength;
    arg0->intelligence = arg1->intelligence;
    arg0->agility = arg1->agility;
    arg0->index = arg1->unk27;

    a3 = arg1;

    for (i = 0; i < 4; ++i) {
        arg0->types[i] = a3->types[i];
    }

    for (i = 0; i < 6; ++i) {
        arg0->classes[i] = a3->classes[i];
    }

    for (i = 0; i < 7; ++i) {
        arg0->affinities[i] = a3->affinities[i];
    }

    arg0->material = arg1->material;
}

void func_8006AE0C(vs_battle_equipment* arg0, vs_battle_droppedGem* arg1)
{
    int i;

    arg0->id = arg1->id;
    arg0->subId = arg1->unk2;
    arg0->gemEffects = arg1->gemEffects;
    arg0->strength = arg1->strength;
    arg0->intelligence = arg1->intelligence;
    arg0->agility = arg1->agility;
    arg0->index = arg1->unk1A;

    for (i = 0; i < 6; ++i) {
        arg0->classes[i] = arg1->classes[i];
    }

    for (i = 0; i < 7; ++i) {
        arg0->affinities[i] = arg1->affinities[i];
    }
}

void func_8006AEAC(vs_battle_weaponInfo* arg0, vs_battle_droppedWeapon* arg1)
{
    int i;
    vs_battle_droppedWeapon2* temp_v0;

    temp_v0 = vs_main_allocHeapR(sizeof *temp_v0);
    vs_main_bzero(temp_v0, sizeof *temp_v0);

    if (arg1 != NULL) {
        temp_v0->unkF2 = arg1->unk0;
        if (arg1->blade != 0) {
            func_8006AB44(&temp_v0->unk0, &D_80060168.unk254[arg1->blade]);
            temp_v0->unkF0 = D_80060168.unk280[arg1->blade - 1].material;
        }
        if (arg1->grip != 0) {
            func_8006AC74(&temp_v0->unk30, &D_80060168.unk530[arg1->grip]);
        }

        for (i = 0; i < 3; ++i) {
            if (arg1->gems[i] != 0) {
                func_8006AE0C(&temp_v0->unk60[i], &D_80060168.unk8A4[arg1->gems[i]]);
            }
        }

        for (i = 0; i < 24; ++i) {
            temp_v0->unkF4[i] = arg1->name[i];
        }
    }
    func_8006A334(arg0, &temp_v0->unk0);
    vs_main_freeHeapR(temp_v0);
}

void func_8006B02C(vs_battle_shieldInfo* arg0, vs_battle_droppedShield* arg1)
{
    func_8006B02C_t* temp_v0;
    int i;

    temp_v0 = vs_main_allocHeapR(sizeof *temp_v0);
    vs_main_bzero(temp_v0, sizeof *temp_v0);

    if (arg1 != NULL) {
        temp_v0->unkC2 = arg1->unk0;
        func_8006ACFC(&temp_v0->unk0, &arg1->unk4);
        temp_v0->unkC0 = arg1->unk4.material;
        for (i = 0; i < 3; ++i) {
            if (arg1->gems[i] != 0) {
                func_8006AE0C(
                    &temp_v0->unk30[i], &D_80060168.unk8A4[arg1->gems[i] & 0x7F]);
            }
        }
    }
    func_8006A65C(arg0, temp_v0);
    vs_main_freeHeapR(temp_v0);
}

void func_8006B110(vs_battle_armorInfo* arg0, vs_battle_droppedArmor* arg1)
{
    func_8006A9F0_t* temp_v0 = vs_main_allocHeapR(sizeof *temp_v0);
    vs_main_bzero(temp_v0, sizeof *temp_v0);
    if (arg1 != NULL) {
        temp_v0->unk33 = arg1->unk27;
        func_8006ACFC(&temp_v0->equip, arg1);
        temp_v0->material = arg1->material;
    }
    func_8006A9F0(arg0, temp_v0);
    vs_main_freeHeapR(temp_v0);
}

void func_8006B194(vs_battle_accessoryInfo* arg0, vs_battle_droppedArmor* arg1)
{
    func_8006A9F0_t* temp_v0 = vs_main_allocHeapR(sizeof *temp_v0);
    vs_main_bzero(temp_v0, sizeof *temp_v0);
    if (arg1 != NULL) {
        temp_v0->unk31 = arg1->unk27;
        func_8006ACFC(&temp_v0->equip, arg1);
    }
    func_8006A8EC(arg0, temp_v0);
    vs_main_freeHeapR(temp_v0);
}

void func_8006B20C(vs_battle_actor2* arg0 __attribute__((unused))) { }

void func_8006B214(void)
{
    vs_battle_actor2* temp_s0 = vs_battle_characterState->unk3C;
    if (temp_s0->unk948 & 0x100000) {
        func_80093FEC(temp_s0->flags.fields.unk3, 0, 0x100000, 1);
        func_80086754(0x100000, temp_s0);
    }
}

void func_8006B270(void)
{
    vs_battle_actor2* temp_s0 = vs_battle_characterState->unk3C;
    int temp_a2 = temp_s0->unk948 & 0x01E00000;
    if (temp_a2 != 0) {
        func_80093FEC(temp_s0->flags.fields.unk3, 0, temp_a2, 1);
        func_80086754(temp_s0->unk948 & 0x01E00000, temp_s0);
    }
}

void func_8006B2D4(void)
{
    vs_battle_actor2* temp_s0 = vs_battle_characterState->unk3C;
    int temp_a2 = temp_s0->unk948 & 0x1E000000;
    if (temp_a2 != 0) {
        func_80093FEC(temp_s0->flags.fields.unk3, 0, temp_a2, 1);
        func_80086754(temp_s0->unk948 & 0x1E000000, temp_s0);
    }
}

void func_8006B338(vs_battle_droppedWeapon* arg0)
{
    vs_battle_actor2* temp_a0;

    func_8006AEAC(&vs_battle_characterState->unk3C->weapon, arg0);
    func_8006B20C(vs_battle_characterState->unk3C);
    if (arg0 == NULL) {
        vs_battle_characterState->equippedWeaponType = 0xA;
    } else {
        vs_battle_characterState->equippedWeaponType =
            D_80060168.unk280[arg0->blade - 1].category;
    }
    temp_a0 = vs_battle_characterState->unk3C;
    temp_a0->unk38 = temp_a0->weapon.range + temp_a0->unk37_3;
    temp_a0->unk39 = temp_a0->weapon.unk125 + temp_a0->unk37_3;
    temp_a0->unk3A = temp_a0->weapon.unk126 + temp_a0->unk37_3;
    temp_a0->unk3B_3 = temp_a0->weapon.unk127_3;
    temp_a0->unk3B_0 = 1;
    func_8006B214();
    func_8006B270();
}

void func_8006B460(vs_battle_droppedShield* arg0)
{
    func_8006B02C(&vs_battle_characterState->unk3C->shield, arg0);
    func_8006B20C(vs_battle_characterState->unk3C);
    func_8006B214();
    func_8006B2D4();
}

void func_8006B4B8(int arg0, vs_battle_droppedArmor* arg1)
{
    func_8006B110(&vs_battle_characterState->unk3C->hitLocations[arg0].armor, arg1);
    func_8006B20C(vs_battle_characterState->unk3C);
    func_8006B214();
    func_8006B2D4();
}

void func_8006B524(vs_battle_droppedArmor* arg0)
{
    func_8006B194(&vs_battle_characterState->unk3C->accessory, arg0);
    func_8006B20C(vs_battle_characterState->unk3C);
    func_8006B214();
    func_8006B2D4();
}

void vs_battle_setBladeForDrop(
    vs_battle_droppedBlade* dropBlade, vs_battle_equipment* targetBlade)
{
    int i;
    vs_battle_droppedBlade* a3;

    dropBlade->id = targetBlade->id;
    dropBlade->subId = targetBlade->subId;
    dropBlade->wepId = targetBlade->wepId;
    dropBlade->category = targetBlade->category;
    dropBlade->currentDp = targetBlade->currentDp;
    dropBlade->maxDp = targetBlade->maxDp;
    dropBlade->currentPp = targetBlade->currentPp;
    dropBlade->maxPp = targetBlade->maxPp;
    dropBlade->strength = targetBlade->strength;
    dropBlade->intelligence = targetBlade->intelligence;
    dropBlade->agility = targetBlade->agility;
    dropBlade->cost = targetBlade->cost;
    dropBlade->damageType = targetBlade->damageType & 3;
    dropBlade->costType = targetBlade->costType & 7;
    dropBlade->unk12 = targetBlade->unk14;
    dropBlade->range = targetBlade->range;

    a3 = dropBlade;

    for (i = 0; i < 6; ++i) {
        a3->classes[i] = targetBlade->classes[i];
    }

    for (i = 0; i < 7; ++i) {
        a3->affinities[i] = targetBlade->affinities[i];
    }
    dropBlade->material = targetBlade->material;
}

void vs_battle_setGripForDrop(
    vs_battle_droppedGrip* dropGrip, vs_battle_equipment* targetGrip)
{
    int i;

    dropGrip->id = targetGrip->id;
    dropGrip->subId = targetGrip->subId;
    dropGrip->category = targetGrip->category;
    dropGrip->gemSlots = targetGrip->gemSlots;
    dropGrip->strength = targetGrip->strength;
    dropGrip->intelligence = targetGrip->intelligence;
    dropGrip->agility = targetGrip->agility;

    for (i = 0; i < 4; ++i) {
        dropGrip->types[i] = targetGrip->types[i];
    }
}

void vs_battle_setGemForDrop(
    vs_battle_droppedGem* dropGem, vs_battle_equipment* targetGem)
{
    int i;

    dropGem->id = targetGem->id;
    dropGem->unk2 = targetGem->subId;
    dropGem->gemEffects = targetGem->gemEffects;
    dropGem->strength = targetGem->strength;
    dropGem->intelligence = targetGem->intelligence;
    dropGem->agility = targetGem->agility;

    for (i = 0; i < 6; ++i) {
        dropGem->classes[i] = targetGem->classes[i];
    }

    for (i = 0; i < 7; ++i) {
        dropGem->affinities[i] = targetGem->affinities[i];
    }
}

void vs_battle_setEquipmentForDrop(
    vs_battle_droppedArmor* dropArmor, vs_battle_equipment* targetArmor)
{
    int i;
    vs_battle_droppedArmor* a3;

    dropArmor->id = targetArmor->id;
    dropArmor->subId = targetArmor->subId;
    dropArmor->wepId = targetArmor->wepId;
    dropArmor->category = targetArmor->category;
    dropArmor->currentDp = targetArmor->currentDp;
    dropArmor->maxDp = targetArmor->maxDp;
    dropArmor->currentPp = targetArmor->currentPp;
    dropArmor->maxPp = targetArmor->maxPp;
    dropArmor->gemSlots = targetArmor->gemSlots;
    dropArmor->strength = targetArmor->strength;
    dropArmor->intelligence = targetArmor->intelligence;
    dropArmor->agility = targetArmor->agility;

    a3 = dropArmor;

    for (i = 0; i < 4; ++i) {
        a3->types[i] = targetArmor->types[i];
    }

    for (i = 0; i < 6; ++i) {
        a3->classes[i] = targetArmor->classes[i];
    }

    for (i = 0; i < 7; ++i) {
        a3->affinities[i] = targetArmor->affinities[i];
    }
    dropArmor->material = targetArmor->material;
}

void vs_battle_setWeaponForDrop(
    vs_battle_droppedWeapon* drop, vs_battle_weaponInfo* weapon)
{
    int i;
    if (weapon->blade.id != 0) {
        weapon->blade.currentDp = weapon->currentDp;
        weapon->blade.currentPp = weapon->currentPp;
        vs_battle_setBladeForDrop(&D_80060168.unk254[drop->blade], &weapon->blade);
        vs_battle_setGripForDrop(&D_80060168.unk530[drop->grip], &weapon->grip);
        for (i = 0; i < 3; ++i) {
            if (weapon->gems[i].id != 0) {
                vs_battle_setGemForDrop(
                    &D_80060168.unk8A4[drop->gems[i]], &weapon->gems[i]);
            }
        }

        for (i = 0; i < 24; ++i) {
            drop->name[i] = weapon->name[i];
        }
    }
}

void func_8006B9E0(u_char* arg0, vs_battle_shieldInfo* arg1)
{
    int i;

    if (arg1->shield.id != 0) {
        arg1->shield.currentDp = arg1->currentPp;
        arg1->shield.currentPp = arg1->currentDp;
        vs_battle_setEquipmentForDrop((vs_battle_droppedArmor*)(arg0 + 4), &arg1->shield);
        for (i = 0; i < 3; ++i) {
            if (arg1->gems[i].id != 0) {
                vs_battle_setGemForDrop(
                    &D_80060168.unk8A4[arg0[(unsigned int)(i + 0x2C)]], &arg1->gems[i]);
            }
        }
    }
}

void vs_battle_setArmorForDrop(vs_battle_droppedArmor* arg0, vs_battle_armorInfo* arg1)
{
    if (arg1->armor.id != 0) {
        arg1->armor.currentDp = arg1->currentDp;
        vs_battle_setEquipmentForDrop(arg0, &arg1->armor);
    }
}

void vs_battle_setAccesoryForDrop(
    vs_battle_droppedArmor* arg0, vs_battle_accessoryInfo* accessory)
{
    if (accessory->accessory.id != 0) {
        vs_battle_setEquipmentForDrop(arg0, &accessory->accessory);
    }
}

int _setWeaponForDropRand(_setWeaponForDropRand_t* arg0, vs_battle_weaponInfo* arg1)
{
    int i;

    if (vs_main_getRand(0xFF) < arg1->unk10C) {
        vs_battle_setBladeForDrop(&arg0->blade, &arg1->blade);
        vs_battle_setGripForDrop(&arg0->grip, &arg1->grip);
        for (i = 0; i < 3; ++i) {
            if (arg1->gems[i].id != 0) {
                vs_battle_setGemForDrop(&arg0->gems[i], &arg1->gems[i]);
            }
        }
        vs_main_memcpy(arg0->unk94, arg1, sizeof arg0->unk94);
        arg0->unk0 = 3;
        return 1;
    }
    return 0;
}

int _setShieldForDropRand(_setShieldForDropRand_t* arg0, vs_battle_shieldInfo* arg1)
{
    int i;

    if (vs_main_getRand(0xFF) < arg1->unkD9) {
        vs_battle_setEquipmentForDrop(&arg0->shield, &arg1->shield);
        for (i = 0; i < 3; ++i) {
            if (arg1->gems[i].id != 0) {
                vs_battle_setGemForDrop(&arg0->gems[i], &arg1->gems[i]);
            }
        }
        arg0->unk0 = 3;
        return 1;
    }
    return 0;
}

int _setAccessoryForDropRand(
    _setAccessoryForDropRand_t* arg0, vs_battle_accessoryInfo* arg1)
{
    if (vs_main_getRand(0xFF) < arg1->unk36) {
        vs_battle_setEquipmentForDrop(&arg0->accessory, &arg1->accessory);
        arg0->unk0 = 3;
        return 1;
    }
    return 0;
}

int _setArmorForDropRand(_setArmorForDropRand_t* arg0, vs_battle_armorInfo* arg1)
{
    int i;

    if (vs_main_getRand(0xFF) < arg1->unk98) {
        for (i = 0; i < 2; ++i) {
            if (arg0[i].armor.id == 0) {
                vs_battle_setEquipmentForDrop(&arg0[i].armor, &arg1->armor);
                arg0[i].unk0 = 3;
                return 1;
            }
        }
    }
    return 0;
}

int func_8006BDA0(func_8006BE64_t2* arg0, func_8006BE64_t3* arg1)
{
    int ret;
    int i;

    ret = 0;

    for (i = 0; i < 2; ++i) {
        arg0->unk214[i].unk0 = arg1[i].unk0;
        if (arg0->unk214[i].unk0) {
            ret = 1;
            arg0->unk214[i].unk3 = arg1[i].unk2;
            arg0->unk214[i].unk2 = 3;
        }
    }

    return ret;
}

int func_8006BDF0(func_8006BE64_t2* arg0, func_8006BDF0_t* arg1)
{
    arg0->unk21C = arg1->unk0;
    if (arg0->unk21C) {
        if (vs_main_getRand(0xFF) < arg1->unk2) {
            arg0->unk21F = 1;
            arg0->unk21E = 3;
            return 1;
        }
    }
    return 0;
}

void func_8006BE64(vs_battle_actor* arg0)
{
    int var_a0;
    int i;
    D_800F1900_t* temp_a0;
    D_800F1900_t* temp_v0;
    D_800F1900_t* var_v1;
    vs_battle_actor2* temp_s2;

    temp_s2 = arg0->unk3C;
    temp_v0 = vs_main_allocHeapR(sizeof(D_800F1900_t));
    if (temp_v0 != NULL) {
        vs_main_bzero(temp_v0, sizeof(D_800F1900_t));
        temp_v0->unk4 |= _setWeaponForDropRand(&temp_v0->unk8.weapon, &temp_s2->weapon);
        temp_v0->unk4 |= _setShieldForDropRand(&temp_v0->unk8.shield, &temp_s2->shield);
        temp_v0->unk4 |=
            _setAccessoryForDropRand(&temp_v0->unk8.accessory, &temp_s2->accessory);
        for (i = 0; i < 6; ++i) {
            if (temp_s2->hitLocations[i].armor.armor.id != 0) {
                temp_v0->unk4 |= _setArmorForDropRand(
                    &temp_v0->unk8.armor, &temp_s2->hitLocations[i].armor);
            }
        }
        temp_v0->unk4 |= func_8006BDA0(&temp_v0->unk8, &temp_s2->unk958);
        temp_v0->unk4 |= func_8006BDF0(&temp_v0->unk8, &temp_s2->unk960);
        if (temp_v0->unk4 != 0) {
            var_v1 = D_800F1900;
            var_a0 = 1;
            while (var_v1 != NULL) {
                if (var_v1->unk4 == arg0->unk4) {
                    var_a0 = 0;
                }
                var_v1 = var_v1->unk0;
            }
            if (var_a0 != 0) {
                int new_var = arg0->unk4;
                temp_a0 = D_800F1900;
                D_800F1900 = temp_v0;
                temp_v0->unk4 = new_var;
                temp_v0->unk0 = temp_a0;
                return;
            }
        }
        vs_main_freeHeapR(temp_v0);
    }
}

void func_8006C004(vs_battle_actor* arg0)
{
    u_int temp_t1;
    vs_battle_actor2* new_var2;

    temp_t1 = arg0->unk1A;
    if (arg0->unk3C != NULL) {
        if (arg0->unk1C == 4) {
            new_var2 = arg0->unk3C;
            if (vs_main_scoredata.enemyKills[new_var2->unk37_0] <= 0xFFFE) {
                ++vs_main_scoredata.enemyKills[new_var2->unk37_0];
            }
            if (vs_main_scoredata.unk10C != (arg0->unk3C->unk37_0)) {
                vs_main_scoredata.unk10C = arg0->unk3C->unk37_0;
                vs_main_scoredata.unk10D = 0;
            } else if (vs_main_scoredata.unk10D < 100) {
                vs_main_scoredata.unk10D = vs_main_scoredata.unk10D + 1;
            }
            vs_main_scoredata.streakScore +=
                new_var2->maxHP + ((new_var2->maxHP * vs_main_scoredata.unk10D) / 2)
                + ((new_var2->maxHP * vs_main_scoredata.weaponKillStreak) / 2)
                + ((new_var2->maxHP * vs_main_scoredata.chainStreak) / 2);
            if (vs_main_scoredata.streakScore > 999999999) {
                vs_main_scoredata.streakScore = 999999999;
            }
        }
    }
    if (temp_t1 < 0x100) {
        vs_main_scoredata.unk9C[temp_t1 >> 5] |= 1 << (temp_t1 & 0x1F);
    }
}

void func_8006C164(int arg0)
{
    vs_battle_actor2* new_var = vs_battle_characterState->unk3C;
    if (D_800F19CC->unk8.unk0 < 0x28) {
        if (vs_main_scoredata.weaponKillStreakBladeCategory
            != new_var->weapon.blade.category) {
            vs_main_scoredata.weaponKillStreakBladeCategory =
                new_var->weapon.blade.category;
            vs_main_scoredata.weaponKillStreak = 0;
            return;
        }
        if (vs_main_scoredata.weaponKillStreak < 0x64) {
            ++vs_main_scoredata.weaponKillStreak;
        }
    }
}

void func_8006C1CC(int arg0, int arg1, int arg2)
{
    vs_battle_actor* temp_s0 = vs_battle_actors[arg1];
    if ((temp_s0->unk27 != 0x80) && (temp_s0->unk28 == 0)) {
        if ((arg2 != 0) && (arg0 == 0)) {
            func_8006C004(temp_s0);
            func_8006C164(0);
        }
        func_8006BE64(temp_s0);
        temp_s0->unk28 = 1;
    }
}

void func_8006C250(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        int temp_v0 = func_800A0BE0(i);
        if (!(temp_v0 & 4)) {
            func_800A087C(i, temp_v0 | 4);
        }
    }
}

void func_8006C2A0(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        int temp_v0 = func_800A0BE0(i);
        if (temp_v0 & 4) {
            func_800A087C(i, temp_v0 & ~4);
        }
    }
}

void func_8006C2FC(void)
{
    int i;

    for (i = 1; i < 16; ++i) {
        func_8009E5C4(i);
    }

    func_8008B4C8(0);
    func_80095B70(1);
    D_800F1968 = 1;
}

void func_8006C350(void)
{
    int i;

    for (i = 1; i < 16; ++i) {
        func_8009E5C4(i);
    }
    func_80095B70(1);
    D_800F1968 = 1;
}

void func_8006C39C(void)
{
    func_8007B10C(0xD, 4, -4, -4, 0);
    func_80048FEC(0);
    func_8006C2A0();
    func_8008B4BC(1);
    func_8008D594(1);
    func_8008B4C8(0);
    func_8008E480(1);
    func_80095B70(1);
    D_800F1968 = 1;
}

void func_8006C40C(void)
{
    func_80048FEC(1);
    func_8007B1B8(8, 4, 0, 0, 0);
    func_8006C250();
    func_8008B4BC(0);
    func_8008D594(0);
    func_8008B4C8(1);
    func_8008E480(0);
    func_80095B70(0);
    D_800F1968 = 0;
}

void func_8006C478(void) { }

void func_8006C480(int arg0, int arg1) { func_800CF7A8(arg0, arg1, 0, 0); }

void func_8006C4A4(int arg0, int arg1) { func_800CF830(arg0, arg1); }

void func_8006C4C4(int arg0, func_8006C4C4_t3* arg1, int arg2)
{
    func_8006C4C4_t sp10;
    D_800F19CC_t2* temp_s0 = &D_800F19CC->unk854[D_800F19CC->unk0 & 3];

    sp10.unk0 = arg0;
    sp10.unk2 = 1;
    sp10.unk3 = 0;
    sp10.unk4 = 4;
    sp10.unk8 = temp_s0->unk4.unk0;
    sp10.unkA = 0;
    if (arg1->unk40 == 0) {
        sp10.unk10 = 4;
        sp10.unk14.unk0 = arg1->unk0.unk.unk0;
        sp10.unk14.unk1 = arg2;
        sp10.unk14.unk2 = func_800A152C(arg1->unk0.unk.unk0, arg1->unk0.unk.unk1, 2);
    } else {
        sp10.unk10 = 5;
        sp10.unk14 = arg1->unk0.unk;
    }
    sp10.unk12 = temp_s0->unk2;
    func_800CF3F8((func_800CF0E8_t*)&sp10, 0);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006C5AC);

int func_8006C84C(int arg0)
{
    D_800F19CC_t2* temp_s0;
    int i;

    temp_s0 = &D_800F19CC->unk854[D_800F19CC->unk0 & 3];
    for (i = 0; i < temp_s0->unk4A; ++i) {
        if (temp_s0->unk4C[i].unk40 == 0) {
            if (temp_s0->unk0 < 0x28) {
                if (((vs_main_skills[temp_s0->unk0].hitParams[0].unk0_7)) == 3) {
                    func_8006C4C4(temp_s0->unk0, &temp_s0->unk4C[i],
                        temp_s0->unk4C[i].unk0.unk.unk3);
                } else {
                    switch (temp_s0->unk4C[i].unk0.unk.unk3) {
                    case 0:
                    case 2:
                    case 5:
                        if (temp_s0->unk0 < 0x16) {
                            func_8006C4C4(
                                1, &temp_s0->unk4C[i], temp_s0->unk4C[i].unk0.unk.unk3);
                        } else {
                            func_8006C4C4(temp_s0->unk0, &temp_s0->unk4C[i],
                                temp_s0->unk4C[i].unk0.unk.unk3);
                        }
                        break;
                    case 1:
                        func_8006C4C4(
                            0x27, &temp_s0->unk4C[i], temp_s0->unk4C[i].unk0.unk.unk3);
                        break;
                    case 3:
                    case 4:
                    case 6:
                        func_8006C4C4(
                            0x26, &temp_s0->unk4C[i], temp_s0->unk4C[i].unk0.unk.unk3);
                        break;
                    }
                }
            } else {
                func_8006C4C4(
                    temp_s0->unk0, &temp_s0->unk4C[i], temp_s0->unk4C[i].unk0.unk.unk3);
            }
        } else {
            func_8006C4C4(0x26, &temp_s0->unk4C[i], 0);
        }
        func_8006C5AC(arg0);
    }
    return 1;
}

void func_8006CA20(int arg0)
{
    int temp_v1;
    D_800F19CC_t2* temp_s0;

    if (arg0 < 0x10) {
        temp_s0 = &D_800F19CC->unk854[D_800F19CC->unk0 & 3];
        if ((temp_s0->unk4.unk0 == arg0) && (temp_s0->unk44 == 0)) {
            temp_v1 = temp_s0->unk4.unk3;
            switch (temp_v1) {
            case 2:
            case 3:
            case 4:
                break;
            case 0:
            case 1:
                func_8009EA14(arg0, &temp_s0->unk844);
                break;
            case 5:
                if (arg0 == 0) {
                    func_8009E070(0, NULL, 6);
                }
                break;
            }
            func_800875C8(&temp_s0->unk4);
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006CB04);

void func_8006CD60(u_int* arg0, int arg1, int arg2)
{
    func_800461CC(0x7E, arg0, vs_main_getRand(3) + 8, arg1, arg2);
}

void func_8006CDB8(void) { func_8009D854(); }

void func_8006CDD8(short* arg0)
{
    D_800F1910_t2* temp_v0;
    int var_a0;
    int var_a1;

    var_a0 = arg0[0];
    if (var_a0 < 0) {
        var_a0 += 0x7F;
    }
    var_a0 >>= 7;
    var_a1 = arg0[2];
    if (var_a1 < 0) {
        var_a1 += 0x7F;
    }
    var_a1 >>= 7;
    temp_v0 = func_8008D438(var_a0, var_a1, 0);
    if (temp_v0 != NULL) {
        func_8008DEAC(temp_v0, 1);
        func_800E68EC(temp_v0->unk0, temp_v0->unk2);
    }
}

void func_8006CE50(void) { func_8008D5A0(0xB4); }

void func_8006CE70(func_8006CE70_t* arg0)
{
    int sp10;
    func_8008C1C8_t* temp_v0;
    func_8008D710_t* temp_v0_2;
    int new_var2 = 4;
    int new_var3 = 2;

    switch (arg0->unk6 & 0x1F0) {
    case 0x10:
        temp_v0 = func_8008E3B8(&sp10);
        if ((temp_v0[arg0->unk6 & 0xF].unk0.unk8.u8[0] < new_var2)
            && (temp_v0[arg0->unk6 & 0xF].unk0.unk8.u8[0] >= new_var3)
            && (func_8007F434() != 0)) {
            temp_v0[arg0->unk6 & 0xF].unk0.unk8.u8[0] = 0;
            vs_main_playSfxDefault(0x7E, 0x3F);
            vs_main_playSfxDefault(0x7E, 0x40);
        } else {
            func_80093B04(arg0);
        }
        break;
    case 0x20:
    case 0x100:
        temp_v0_2 = func_8008E370(&sp10);
        if ((temp_v0_2[arg0->unk6 & 0xF].unkC < new_var2)
            && (temp_v0_2[arg0->unk6 & 0xF].unkC >= 2)
            && !func_800BEBF4(temp_v0_2[arg0->unk6 & 0xF].unk10 + 0x3C0)
            && (func_8007F434() != 0)) {
            temp_v0_2[arg0->unk6 & 0xF].unkC = 0;
            vs_main_playSfxDefault(0x7E, 0x3F);
            vs_main_playSfxDefault(0x7E, 0x40);
        } else {
            func_80093B04(arg0);
        }
        break;
    }
}

void func_8006D028(int arg0)
{
    D_800F185C = arg0;
    func_8007B29C(0xE, 8, arg0, 0x10, 0, 0);
}

void func_8006D064(void)
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

void func_8006D9FC(func_80077DF0_t* arg0, func_80077DF0_t* arg1)
{
    int _[2] __attribute__((unused));
    int temp_a1;
    int temp_a3;
    int temp_v1_2;
    int v;

    temp_a3 = (D_800F19D0.unk0.vz * ONE) / 2304;
    temp_a1 = (D_800F1880.unk40 << 0x13) + temp_a3 * 360;
    temp_v1_2 = (D_800F1880.unk44 << 0x13) - temp_a3 * 360;

    if (temp_v1_2 < temp_a1) {
        arg1->unk0 = (temp_a1 + temp_v1_2) >> 1;
    } else {
        if (arg0->unk0 < temp_a1) {
            arg1->unk0 = temp_a1;
        } else if (temp_v1_2 < arg0->unk0) {
            arg1->unk0 = temp_v1_2;
        } else {
            arg1->unk0 = arg0->unk0;
        }
    }

    temp_a1 = (D_800F1880.unk42 << 0x13) + temp_a3 * 360;
    temp_v1_2 = (D_800F1880.unk46 << 0x13) - temp_a3 * 360;

    if (temp_v1_2 < temp_a1) {
        arg1->unk8 = (temp_a1 + temp_v1_2) >> 1;
    } else {
        if (arg0->unk8 < temp_a1) {
            arg1->unk8 = temp_a1;
        } else if (temp_v1_2 < arg0->unk8) {
            arg1->unk8 = temp_v1_2;
        } else {
            arg1->unk8 = arg0->unk8;
        }
    }

    arg1->unk0 &= ~0xFFF;
    arg1->unk8 &= ~0xFFF;

    temp_a1 = arg0->unk4 - D_1F800000[18];

    v = 0xFFFA0000;
    if ((temp_a1 > 0x60000) || (temp_a1 < v)) {
        arg1->unk4 = arg0->unk4;
    } else {
        arg1->unk4 = D_1F800000[18];
    }
    if (arg1->unk4 > 0) {
        arg1->unk4 = 0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006DB98);

int func_8006DEFC(SVECTOR* arg0, int arg1, int arg2)
{
    int sp18[4];
    int sp28[3];

    if (func_8006DB98(arg0, sp28, sp18, arg1, arg2) != 0) {
        D_1F800000[17] = func_8006D97C(D_1F800000[17], sp28[0], sp18[0]);
        D_1F800000[19] = func_8006D97C(D_1F800000[19], sp28[2], sp18[2]);
        D_1F800000[18] = func_8006D97C(D_1F800000[18], sp28[1], sp18[1]);
    } else {
        D_1F800000[17] = _add_min(D_1F800000[17], sp28[0], sp18[0]);
        D_1F800000[19] = _add_min(D_1F800000[19], sp28[2], sp18[2]);
        D_1F800000[18] = _add_min(D_1F800000[18], sp28[1], sp18[1]);
    }
    if (D_1F800000[18] > 0) {
        D_1F800000[18] = 0;
    }
    return D_800F19D0.unk28;
}

void func_8006DFE0(func_8006EBF8_t2* arg0)
{
    func_80077DF0_t sp10;
    int new_var;

    func_8006D9FC((func_80077DF0_t*)arg0, &sp10);
    sp10.unk10.unk0[0] = sp10.unk0 - D_1F800000[17];
    sp10.unk10.unk0[2] = sp10.unk8 - D_1F800000[19];
    sp10.unk10.unk0[1] = sp10.unk4 - D_1F800000[18];

    if (sp10.unk10.unk0[0] > 0x12000) {
        D_1F800000[17] += 0x12000;
    } else {
        new_var = 0xFFFEE000;
        if (sp10.unk10.unk0[0] < new_var) {
            D_1F800000[17] -= 0x12000;
        } else {
            D_1F800000[17] = sp10.unk0;
        }
    }
    if (sp10.unk10.unk0[2] > 0x12000) {
        D_1F800000[19] += 0x12000;
    } else {
        new_var = 0xFFFEE000;
        if (sp10.unk10.unk0[2] < new_var) {
            D_1F800000[19] -= 0x12000;
        } else {
            D_1F800000[19] = sp10.unk8;
        }
    }
    if (sp10.unk10.unk0[1] < 0) {
        new_var = 0xFFFA0000;
        if (sp10.unk10.unk0[1] < new_var) {
            D_1F800000[18] += 0x60000 + sp10.unk10.unk0[1];
        }
    } else if (sp10.unk10.unk0[1] > 0x60000) {
        D_1F800000[18] -= 0x60000 - sp10.unk10.unk0[1];
    }
    if (D_1F800000[18] > 0) {
        D_1F800000[18] = 0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006E158);

void func_8006E640(int arg0)
{
    func_8006EBF8_t sp10;
    SVECTOR sp20;
    int _[2] __attribute__((unused));

    func_800A1108(arg0, &sp10);
    sp20.vx = sp10.unk0.unk4;
    sp20.vz = sp10.unk0.unk8;
    sp20.vy = sp10.unk0.unk6 - 0x5A;
    func_80074B14(arg0, &sp10.unk0.unk0.fields.unk0);
    switch (D_800F18F0) {
    case 1:
    case 3:
        func_8006E158();
        if ((D_800F19CC->unk298D != 0xFF) && (D_800F19CC->unk2C00 != 0)) {
            sp20.vx = D_800F19CC->unk29C0[D_800F19CC->unk298D].unk0.vx;
            sp20.vy = D_800F19CC->unk29C0[D_800F19CC->unk298D].unk0.vy;
            sp20.vz = D_800F19CC->unk29C0[D_800F19CC->unk298D].unk0.vz;
        }
        func_8006DEFC(&sp20, 0, 0x28);
        break;
    case 2:
        func_8006E158();
        sp20.vx = D_800F19CC->unk2998.vx;
        sp20.vy = D_800F19CC->unk2998.vy;
        sp20.vz = D_800F19CC->unk2998.vz;
        if (func_800C4734() == 1) {
            func_8006DEFC(&sp20, 0, 8);
            return;
        }
        func_8006DEFC(&sp20, 0, 0x28);
        break;
    case 11:
        func_8006E158();
        func_8006DEFC(&sp20, 1, 0x28);
        break;
    case 4:
        func_8006E158();
        break;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006E7F0);

int func_8006EBF8(void)
{
    int v;
    func_8006EBF8_t sp10;
    func_8006EBF8_t2 sp20;

    if (D_800F1968 == 0) {
        func_800A4D8C();
    }
    func_800A1108(0, &sp10);

    sp20.unk0 = sp10.unk0.unk4 << 0xC;
    sp20.unk4 = (sp10.unk0.unk6 << 0xC) + 0xFFFA6000;
    sp20.unk8 = sp10.unk0.unk8 << 0xC;
    func_8006DFE0(&sp20);
    func_8007AACC(&D_800F19D0.unk0);
    return v;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006EC7C);

void func_8006EF10(void)
{
    if (D_800F19D0.unk10.pad >= 0) {
        if (D_800F19D0.unk10.pad < 2) {
            D_800F19CC->unk2C0C = 0x600;
            return;
        }
        if (D_800F19D0.unk10.pad < 4) {
            D_800F19CC->unk2C0C = 0x900;
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006EF5C);

int func_8006F204(void)
{
    int temp_a0;
    int temp_v0;
    int temp_v1;
    int new_var;
    int _[4] __attribute__((unused));

    temp_v0 = D_1F800000[14];
    new_var = temp_v0 & (~0xFFF);
    temp_a0 = D_800F1904->unkA8 & ~0xFFF;
    temp_v1 = (temp_v0 + (D_800F1904->unkC8 * D_800F1904->unkF0)) & ~0xFFF;

    if (((new_var >= temp_a0) && (temp_a0 >= temp_v1))
        || ((temp_a0 >= new_var) && (temp_v1 >= temp_a0))) {

        D_1F800000[13] = D_800F1904->unkA4;
        D_1F800000[15] = D_800F1904->unkAC;
        D_1F800000[14] = D_800F1904->unkA8;
        D_1F800000[17] = D_800F1904->unkB4;
        D_1F800000[19] = D_800F1904->unkBC;
        D_1F800000[18] = D_800F1904->unkB8;

        D_800F19D0 = D_800F1904->unk6C;

        D_1F800000[25] = D_800F1904->unkA0;

        func_8007CCCC(D_800F1904->unk98);
        func_8007CCF0(D_800F1904->unk9C);
        return 1;
    }
    D_1F800000[13] += ((D_800F1904->unkC4 * D_800F1904->unkF0));
    D_1F800000[15] += ((D_800F1904->unkCC * D_800F1904->unkF0));
    D_1F800000[14] += ((D_800F1904->unkC8 * D_800F1904->unkF0));
    D_1F800000[17] += (D_800F1904->unkD4);
    D_1F800000[19] += (D_800F1904->unkDC);
    D_1F800000[18] += (D_800F1904->unkD8);
    D_1F800000[25] += (D_800F1904->unkE4);

    func_8007CCCC(D_8005E0C8 + D_800F1904->unkE8);
    func_8007CCF0(vs_main_projectionDistance + D_800F1904->unkEC);

    return 0;
}

void func_8006F450(func_800CF0E8_t* arg0)
{
    func_800CF0E8_t sp10;

    sp10.unk0 = 0x24;
    sp10.unk2 = 1;
    sp10.unk4 = 4;
    sp10.unk3 = 0;
    sp10.unk8.u8[0] = 0;
    sp10.unk10 = 5;
    sp10.unk14.u16 = arg0->unk0;
    sp10.unk18 = arg0->unk4;
    sp10.unk16.u16 = 0;
    func_800CF3F8(&sp10, 0);
}

void func_8006F4B0(func_8006EBF8_t3* arg0)
{
    func_800CF0E8_t sp10;

    sp10.unk0 = 0x21;
    sp10.unk2 = 1;
    sp10.unk4 = 4;
    sp10.unk3 = 0;
    sp10.unk8.u8[0] = 0;
    sp10.unk10 = 5;
    sp10.unk14.u16 = (arg0->unk0.fields.unk0 << 7) + 0x40;
    sp10.unk18 = (arg0->unk0.fields.unk2 << 7) + 0x40;
    sp10.unk16.u16 = arg0->unk6;
    if (!(D_800F1868 & 2)) {
        func_800CF3F8(&sp10, 0);
    }
}

void _setRoomSeen(void)
{
    u_int scene;
    u_int room;

    if (D_800F19A0 == 0) {
        return;
    }

    scene = vs_battle_getCurrentSceneId();
    vs_main_mapStatus.areaFlags[scene >> 5] |= 1 << (scene & 0x1F);
    room = vs_battle_getCurrentRoomId();
    D_800F19A0 = 0;
    vs_main_mapStatus.roomFlags[room >> 5] |= 1 << (room & 0x1F);
}

void func_8006F5CC(void)
{
    D_800F196C = 1;
    D_800F18F0 = 0;
    _setRoomSeen();
}

void func_8006F5FC(void)
{
    D_800F196C = 0xC;
    D_800F18F0 = 0;
    func_8009E5C4(0);
}

void func_8006F630(func_8006F630_t1* arg0, func_8006F630_t2* arg1, func_8006F630_t3* arg2)
{
    int temp_v1;
    u_short var_v0;

    temp_v1 = vs_main_skills[arg1->unk0].hitParams[0].unk0;

    switch (temp_v1) {
    case 0x3A:
    case 0x3E:
        var_v0 = arg2->unk4;
        arg0->unkB = temp_v1;
        arg0->unkC = var_v0;
        break;
    case 0x3B:
        var_v0 = arg2->unk6;
        arg0->unkB = temp_v1;
        arg0->unkC = var_v0;
        break;
    case 0x3F:
        var_v0 = arg2->unk6;
        arg0->unkB = temp_v1;
        arg0->unkC = var_v0;
        break;
    default:
        arg0->unkB = temp_v1;
        break;
    }

    arg0->unkE = arg2->unk2;
    arg0->unk10 = arg2->unk14 & 0x1FFFFFE0;
    arg0->unk14 = vs_main_skills[arg1->unk0].unk2_4;
    arg0->unk15 = arg1->unk3;
    arg0->unk16 = arg1->unk2;
    arg0->unk17 = vs_battle_actors[arg2->unk0_0]->unk3C->unk37_0;
}

int func_8006F760(void)
{
    int temp_a2;
    int var_a0;
    int var_t0;
    u_int temp_v1;

    var_t0 = 0;
    temp_a2 = (vs_battle_characterState->equippedWeaponType % 10) & 0xFF;
    temp_v1 = vs_main_artsStatus.artsLearned[temp_a2];
    var_a0 = 0;

    if (temp_v1 < 4) {
        var_a0 = (vs_main_artsStatus.kills.weaponCategories[temp_a2]
                     < vs_main_artsPointsRequirements[temp_a2][temp_v1])
               ^ 1;
    }
    if (var_a0 == 0) {
        if (vs_main_artsStatus.kills.battleAbilitiesUnlocked < 0x16) {
            if (vs_main_artsStatus.kills.total
                >= vs_main_battleAbilitiesPointsRequirements
                    [vs_main_artsStatus.kills.battleAbilitiesUnlocked]) {
                var_t0 = 1;
            }
        }
    }
    return (var_a0 << 0x10) | var_t0;
}

void func_8006F848(void)
{
    func_800CF0E8_t sp10;

    sp10.unk0 = 0x14;
    sp10.unk2 = 1;
    sp10.unk4 = 5;
    sp10.unk10 = 4;
    sp10.unk3 = 0;
    sp10.unk14.u8[0] = 0;
    sp10.unk16.u8[0] = 0xFD;
    func_800CF3F8(&sp10, 0);
}

void func_8006F89C(void)
{
    switch (D_800F18FC) {
    case 0:
        func_8006F5FC();
        break;
    case 2:
        if (func_8006F760() != 0) {
            D_800F18F0 = 0xD;
            func_8009E070(0, NULL, 6);
            func_8006F848();
            func_8008D594(1);
        } else if ((D_800F19CC->unk8.unk0 != 0)
                   && !(vs_main_skills[D_800F19CC->unk8.unk0].flags_15)
                   && (D_800F19CC->unk8.unk44 == 0) && (D_800F19CC->unk2C07 == 0)
                   && (D_800F19CC->unk8.unk4 == 0)) {
            D_800F18F0 = 0xD;
            func_8009E070(0, NULL, 6);
            func_8006F848();
            func_8008D594(1);
        } else {
            func_8006F5FC();
        }
        break;
    default:
        if ((D_800F19CC->unk8.unk0 != 0)
            && !(vs_main_skills[D_800F19CC->unk8.unk0].flags_15)
            && (D_800F19CC->unk8.unk44 == 0) && (D_800F19CC->unk2C07 == 0)
            && (D_800F19CC->unk8.unk4 == 0)) {
            D_800F18F0 = 0xD;
            func_8009E070(0, NULL, 6);
            func_8006F848();
            func_8008D594(1);
        } else {
            func_8006F5FC();
        }
        break;
    }
}

void func_800CB208(u_int, int);

void func_8006FA20(void)
{
    u_int temp_v0_2;

    if ((D_800F19CC->unk8.unk0 != 0)
        && !((vs_main_skills[D_800F19CC->unk8.unk0].flags_15))
        && (D_800F19CC->unk8.unk44 == 0) && (D_800F19CC->unk2C07 == 0)
        && (D_800F19CC->unk8.unk4 == 0)) {
        D_800F18F0 = 0xE;
        func_8006C39C();
        func_800CB2B8(0xC, (int)D_800F19CC->unk8.unk0, 1);
        vs_main_skills[D_800F19CC->unk8.unk0].flags_15 = 1;
        return;
    }
    temp_v0_2 = func_8006F760();
    D_800F18F0 = 0xE;
    func_8006C39C();
    func_800CB208(temp_v0_2 >> 0x10, temp_v0_2 & 0xFFFF);
}

void func_8006FB48(void)
{
    if (func_800BEBF4(0xAB) > 2) {
        if (D_800F1900 != NULL) {
            func_800CB158(D_800F1900);
            D_800F196C = 2;
            D_800F18F0 = 0xC;
            func_8006C39C();
        } else {
            func_8006F89C();
        }
        return;
    }
    func_8006F5FC();
}

void func_8006FBCC(int arg0)
{
    int i;

    for (i = 0; i < 16; ++i) {
        if ((i != D_800F19CC->unk8.unk4) && !(func_800A0BE0(i) & 0x01000000)
            && (func_800A0BE0(i) & 1)) {
            func_8009E5C4(i);
        }
    }
    func_8007B10C(8, 4, 0, 0, 0);
    func_8006C250();
    func_80048FEC(1);
    func_8008B4BC(0);
    func_80095B70(0);
    D_800F18FC = arg0;
    vs_gametime_tickspeed = 2;
    D_800F18F0 = 0xB;
}

void func_8006FCBC(void)
{
    D_800F19CC_t2* temp_s0;

    D_800F18F0 = 0xA;
    temp_s0 = &D_800F19CC->unk854[0];
    func_8006C4A4(temp_s0->unk4.unk0, func_800A152C(temp_s0->unk4.unk0, 0xF0, 0));
}

void func_8006FD0C(void) { D_800F18F0 = 9; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8006FD1C);

void func_80070278(void)
{
    D_800F19CC_t2* temp_s0;
    int temp_a3;

    D_800F19CC->unk2C0A = 0;
    D_800F19CC->unk2C08 = 0;
    temp_s0 = &D_800F19CC->unk854[D_800F19CC->unk0 & 3];

    if (((u_int)(temp_s0->unk0 - 0x16) < 0x20) && (temp_s0->unk44 == 0)
        && (temp_s0->unk4.unk0 == 0)) {
        func_800BEC14(0xB8, 1);
    }

    temp_a3 = D_800F19CC->unk0;

    if (temp_a3 == 0) {
        if (!(vs_main_skills[temp_s0->unk0].unk2_0)) {
            func_8009DD00(temp_s0->unk4.unk0, &D_800F19CC->unk8.unk844, temp_s0->unk48);
            D_800F19CC->unk2C0A = func_8009F8DC(temp_s0->unk4.unk0) * 2;
        } else {
            if (temp_s0->unk0 >= 0x8D) {
                if (temp_s0->unk0 < 0xB8) {
                    func_8009F298(temp_s0->unk4.unk0, &D_800F19CC->unk8.unk844, 1);
                } else if (temp_s0->unk0 < 0xE0) {
                    func_8009EFEC(temp_s0->unk4.unk0, &D_800F19CC->unk8.unk844, 1);
                } else {
                    func_8009E2E0(temp_s0->unk4.unk0, &D_800F19CC->unk8.unk844, 1);
                }
            } else {
                func_8009E2E0(temp_s0->unk4.unk0, &D_800F19CC->unk8.unk844, 1);
            }
            D_800F19CC->unk2C0A = 0;
            vs_gametime_tickspeed = 4;
        }
    } else {
        if (temp_s0->unk0 < 0x28) {
            func_8009EC9C(temp_s0->unk4.unk0, &D_800F19CC->unk8.unk844,
                vs_main_settings.mappedChainAbilities[D_800F19CC->unk2C03 - 1] - 0x16,
                temp_a3);
        } else {
            func_8009EE9C(temp_s0->unk4.unk0, &D_800F19CC->unk8.unk844, 0);
        }
        D_800F19CC->unk2C0A = func_8009F8DC(temp_s0->unk4.unk0) * 2;
    }

    func_80045D64(0x7E, 0x34);
    func_80045D64(0x7E, 0x35);
    func_80045D64(0x7E, 0x36);
    func_800CB50C();

    D_800F19CC->unk2C03 = 0;
    D_800F18F0 = 7;
}

void func_800704B0(void)
{
    D_800F18F0 = 6;
    func_800CF920();
}

void func_800704D8(void)
{
    D_800F196C = 5;
    D_800F19CC->unk8.unk0 = 0;
    D_800F18F0 = 1;
    func_800CB660((vs_battle_characterState->unk20 & 1) | 2);
    func_800CAB40();
    func_8006C39C();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007053C);

void func_8007087C(D_800F19CC_t* arg0)
{
    func_8006EBF8_t sp10;

    func_800A1108((char)arg0->unk4, &sp10);
    arg0->unk8.unk83C = (sp10.unk0.unk4 + rsin(sp10.unk0.unkA + 0x800));
    arg0->unk8.unk840 = (sp10.unk0.unk8 + rcos(sp10.unk0.unkA + 0x800));
    arg0->unk8.unk83E = sp10.unk0.unk6;
}

void func_800708EC(void)
{
    char temp_v1;

    D_800F19CC->unk8.unk4A = 1;
    temp_v1 = D_800F19CC->unk29C0[D_800F19CC->unk298C].unk9;
    if (temp_v1 < 16) {
        D_800F19CC->unk8.unk8C = 0;
        D_800F19CC->unk8.unk4C.unk.unk0 = D_800F19CC->unk29C0[D_800F19CC->unk298C].unk9;
        D_800F19CC->unk8.unk4C.unk.unk1 = D_800F19CC->unk29C0[D_800F19CC->unk298C].unkA;
        if (D_800F19CC->unk8.unk4C.unk.unk1 == -1) {
            D_800F19CC->unk8.unk4C.unk.unk1 =
                vs_battle_actors[D_800F19CC->unk8.unk4C.unk.unk0]->unk3C->unk36;
        }
    } else {
        D_800F19CC->unk8.unk8C = temp_v1 & 0x10 ? 4 : 1;
        D_800F19CC->unk8.unk4C.vec = D_800F19CC->unk29C0[D_800F19CC->unk298C].unk0;
        D_800F19CC->unk8.unk4C.vec.pad = D_800F19CC->unk29C0[D_800F19CC->unk298C].unk9;
    }
    if (D_800F19CC->unk8.unk44 == 0) {
        if (D_800F19CC->unk29C0[D_800F19CC->unk298C].unk9 == D_800F19CC->unk8.unk4) {
            func_8007087C((D_800F19CC_t*)&D_800F19CC->unk8);
            return;
        }
        D_800F19CC->unk8.unk844 = D_800F19CC->unk29C0[D_800F19CC->unk298C].unk0;
        return;
    }
    D_800F19CC->unk8.unk844 = D_800F19CC->unk29C0[D_800F19CC->unk298C].unk0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80070B04);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80070CAC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80070F28);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007138C);

void func_800719DC(void) { func_80070F28(0); }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800719FC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80071F68);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80072734);

void func_80072B9C(void) { D_800F18F0 = 0; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80072BA8);

void func_80072EC4(int arg0, u_short arg1)
{
    int i;
    u_int temp_v0;
    vs_battle_actor* temp_a0;

    D_800F196C = 2;
    vs_main_bzero(&D_800F19CC->unk8, 0x84C);
    D_800F19CC->unk8.unk44 = 0;
    D_800F19CC->unk8.unk4 = arg0;
    D_800F19CC->unk8.unk0 = arg1;
    func_8006EF10();
    func_80088CA0();
    if (arg0 != 0) {
        D_800F19CC->unk2984 = 0;
    } else {
        D_800F19CC->unk2984 = 1;
    }
    D_800F19CC->unk298C = D_800F19CC->unk298D = -1;
    temp_a0 = vs_battle_actors[arg0];
    D_800F19CC->unk29C0[0].unk9 = temp_a0->unk10.u8[0];
    D_800F19CC->unk29C0[0].unkA = temp_a0->unk10.u8[2];
    D_800F19CC->unk8.unk4A = 0;
    D_800F19CC->unk298E = 0;
    D_800F19CC->unk4 = 0;
    func_8009E5C4(D_800F19CC->unk8.unk4);

    if (D_800F19CC->unk2984 != 0) {
        func_800C031C();
        func_8007B10C(0xD, 4, -4, -4, 0);
    }

    func_8006C250();

    for (i = 0; i < 16; ++i) {
        if (i != D_800F19CC->unk8.unk4) {
            temp_v0 = func_800A0BE0(i);
            if (temp_v0 & 4) {
                func_800A087C(i, temp_v0 & ~4);
            }
        }
    }

    if (arg0 == 0) {
        func_8008B4C8(0);
    }
    func_8008B4BC(1);
    func_8008D594(1);
    if (D_800F19CC->unk2984 != 0) {
        func_80095B70(1);
    }
    func_80072BA8(D_800F19CC->unk8.unk0);
    func_80048FEC(0);
}

void func_800730BC(void)
{
    VECTOR sp10;
    func_8006EBF8_t sp20;
    int i;
    void* p;

    if (D_800F1904 == NULL) {
        D_800F1904 = vs_main_allocHeapR(sizeof *D_800F1904);
    }
    if (D_800F196C != 7) {

        p = D_1F800000;
        D_800F1904->unk0 = *(D_800F1904_t*)(p + 0x34);

        D_800F1904->unk34 = D_800F19D0;
        D_800F1904->unk60 = D_8005E0C8;
        D_800F1904->unk64 = vs_main_projectionDistance;
        D_800F1904->unk68 = D_1F800000[25];
    }
    D_800F1904->unk98 = 4;
    D_800F1904->unk9C = 0xE0;
    D_800F1904->unkA0 = 0x2000;
    func_800A1108(0, &sp20);

    setVector(&D_800F1904->unk6C.unk0, sp20.unk0.unkA, 0, D_800F19D0.unk0.vz);
    setVector(
        &sp10, sp20.unk0.unk4 * ONE, (sp20.unk0.unk6 - 0xB4) * ONE, sp20.unk0.unk8 * ONE);

    func_8006EF5C(&sp10);

    D_800F196C = 7;
    D_800F18F0 = 0;

    func_800CB654(1);

    for (i = 0; i < 16; ++i) {
        func_8009E5C4(i);
    }

    func_8008B4C8(0);
    func_8008D594(1);
    func_80095B70(1);
    func_800A0870(1);
}

void func_800732AC(void)
{

    D_800F1904_t* p = (void*)D_1F800000;
    p[1] = D_800F1904->unk0;

    D_800F19D0 = D_800F1904->unk34;

    D_800F19D0.unk10.vy = D_800F19D0.unk0.vx;
    func_8007CCCC(D_800F1904->unk60);
    func_8007CCF0(D_800F1904->unk64);
    if (D_800F1904 != NULL) {
        vs_main_freeHeapR(D_800F1904);
        D_800F1904 = NULL;
    }
    func_800CB654(0);
    func_8008B4C8(1);
    func_8008D594(0);
    func_80095B70(0);
    func_800A0870(0);
    func_8006F5CC();
}

void func_800733F8(int arg0)
{
    func_800CF0E8_t sp10;

    sp10.unk0 = arg0;
    D_800F196C = 4;
    sp10.unk2 = 1;
    sp10.unk3 = 0;
    sp10.unk4 = 4;
    sp10.unk8.u8[0] = 0;
    sp10.unk8.u8[1] = 0;
    sp10.unkA.u8[0] = 0;
    sp10.unk10 = 4;
    sp10.unk14.u8[0] = 0;
    sp10.unk14.u8[1] = 0;
    sp10.unk16.u8[0] = 0;
    sp10.unkE4 = 0;
    sp10.unkE2 = 0;
    sp10.unkE0 = 0;
    func_800CF0E8(&sp10, 0, 0);
    vs_gametime_tickspeed = 4;
    func_800CB654(1);
    func_8008B4C8(0);
}

void func_80073484(void)
{
    func_8006F5CC();
    vs_gametime_tickspeed = 2;
    func_800CB654(0);
    func_8008B4C8(1);
}

void func_800734C0(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        func_8009E5C4(i);
    }
    func_8007C0AC(0, 2);
    D_800F196C = 10;
}

void func_8007350C(void) { func_8006F5CC(); }

void func_8007352C(void)
{
    D_800F196C = 6;
    func_8006C39C();
}

void func_80073554(void)
{
    D_800F196C = 1;
    func_8006C40C();
}

void func_8007357C(void)
{
    D_800F196C = 5;
    D_800F18F0 = 1;
    func_800CB660((vs_battle_characterState->unk20 & 1) | 2);
    func_8006C39C();
}

void func_800735CC(D_800F18EC_t* arg0)
{
    func_800CB114();
    arg0->unk0 = 0;
    func_8006C40C();
}

void func_800735F8(D_800F18EC_t* arg0)
{
    func_8006EBF8_t sp18;

    func_8008B4C8(1);
    func_800CB660(vs_battle_characterState->unk20 & 1);

    switch (arg0->unk2) {
    case 5:
        break;
    case 6:
    case 7:
    case 8:
        func_80072EC4(0, arg0->unk4.value);
        return;
    case 10:
        func_800A1108(0, &sp18);
        func_8006F4B0(&sp18.unk0);
        func_800BEC14(0xB7, 1);
        func_8007C694(arg0->unk4.fields.unk0_0, arg0->unk4.fields.unk0_9,
            arg0->unk4.fields.unk0_14, 0, 8);
        if (vs_battle_characterState->unk3C->currentMP >= arg0->unk4.fields.unk0_19) {
            vs_battle_characterState->unk3C->currentMP -= arg0->unk4.fields.unk0_19;
        }
        func_8009E070(0, NULL, 7);
        break;
    }
    func_8006F5CC();
    func_800735CC(arg0);
}

void func_80073718(void)
{
    int i;

    D_800F196C = 3;
    D_800F18F0 = 2;
    func_800BEC14(0xAC, vs_battle_characterState->unk20 & 1);
    func_800BEC14(0xAF, (D_800F19D0.unk10.vy / 512) & 7);
    if (D_800F19D0.unk20 == 0x600) {
        func_800BEC14(0xB0, 0);
    } else {
        func_800BEC14(0xB0, 1);
    }

    for (i = 0; i < 16; ++i) {
        if (vs_battle_actors[i] != NULL) {
            func_8009FC60(i, -2, 0, -1);
            switch (vs_battle_actors[i]->unk8) {
            case 0x10:
                break;
            case 0x20:
                break;
            case 0x40:
                vs_battle_actors[i]->unk8 = 0x10;
                break;
            default:
                if (vs_battle_actors[i]->unk8 == 0x80) {
                    func_800E6700(i);
                }
                vs_battle_actors[i]->unk8 = 0;
                break;
            }
        }
    }

    func_80095B70(1);
    D_800F1858 = 0;
    func_8008D594(1);
}

void func_80073870(void)
{
    func_800BEC30();
    func_80073718();
}

void func_80073898(void)
{
    if ((func_800BEB10() << 16) != 0) {
        D_800F196C = 3;
        D_800F18F0 = 1;
        return;
    }
    func_80073870();
}

void func_800738E4(void)
{
    char sp10[4];
    int i;

    func_8008D594(0);
    func_80095B70(0);
    D_800F186C = 0;

    for (i = 0; i < 16; ++i) {
        if ((vs_battle_actors[i] != NULL) && (vs_battle_actors[i]->unk8 == 0x10)) {
            vs_battle_actors[i]->unk8 = 0x40;
        }
    }

    func_800DEC88(NULL);
    func_800DC638();
    if ((func_800BEC58(0xA, 0, NULL, 0) == 1)
        || ((D_80050468.unk0 != 0) && (func_800BEC58(0x10, 0, NULL, 0) == 1))) {
        func_80073870();
        return;
    }

    sp10[0] = 0;
    func_8009F990(-1, sp10);

    for (i = 0; i < 16; ++i) {
        func_8009D7E8(i, 0);
        func_800A07FC(i, 0);
    }

    func_80093A14();
    func_8007CD14(0x1000, 1);
    func_8007AC94(0);
    func_8007BD8C(0);
    if (vs_main_soundData.unk4 == 0xFFFF) {
        if (D_800F18AC != 0) {
            func_80045000(D_800F18AC, 0x7F, 0);
        }
    } else if ((D_800F18AC != 0)
               && (vs_main_soundData.unk4 == vs_main_soundData.unk14[D_800F18AC - 1])) {
        func_8004552C(D_800F18AC, 0x7F, 0x3C);
    }
    func_8006F5CC();
}

void func_80073AA4(void)
{
    D_800F196C = 0xB;
    func_8006C350();
}

void func_80073ACC(void)
{
    func_800CB50C();
    func_8006C40C();
    func_8006F5CC();
}

int func_80073AFC(func_8008C1C8_t* arg0)
{
    short sp10[4];
    int var_s1;
    int var_s2;

    if (arg0->unkE == 0) {
        if (arg0->unk12 == 0) {
            int v = 7;
            sp10[0] = (arg0->unk0.unk0 << v) + 0x40;
            sp10[2] = (arg0->unk0.unk2 << v) + 0x40;
            var_s1 = 0;
            switch (arg0->unk0.unk8.u8[0]) {
            case 0:
                var_s1 = 1;
                break;
            case 1:
            case 3:
                if (func_8007E454(arg0->unkC) != 0) {
                    if (arg0->unkC >= 0x1D2) {
                        func_800BEC14(arg0->unkC + 0x1B6, 2);
                        func_800CCB9C(arg0->unkC);
                    }
                    arg0->unk0.unk8.u8[0] = 0;
                    var_s1 = 2;
                } else if (func_800BEBF4(arg0->unkC + 0x1B6)) {
                    arg0->unk0.unk8.u8[0] = 0;
                    var_s1 = 3;
                }
                break;
            }
            if (var_s1 != 0) {
                if (var_s1 == 2) {
                    var_s2 = 7;
                    if (arg0->unkC >= 0x1D2) {
                        var_s2 = 9;
                    }
                    func_800CB2B8(var_s2, arg0->unkC, 1);
                }
                func_8009E070(0, sp10, 5);
                func_8008BEBC(arg0);
                return 0;
            }
            if (arg0->unk0.unk8.u8[0] != 0) {
                switch (arg0->unk0.unk8.u8[0]) {
                case 1:
                    var_s2 = 6;
                    if (arg0->unkC >= 0x1D2) {
                        var_s2 = 8;
                    }
                    break;
                case 2:
                    var_s2 = 5;
                    break;
                case 3:
                    var_s2 = 0xA;
                    break;
                }
                func_800CB2B8(var_s2, arg0->unkC, 1);
            }

            vs_main_playSfxDefault(0x7E, 0x65);
            vs_main_playSfxDefault(0x7E, 0x66);
            func_8009E5C4(0);
            return 0;
        }
    }
    return 1;
}

void func_80073D30(func_8008C1C8_t* arg0, func_8006EBF8_t* arg1, int arg2)
{
    func_800CF0E8_t sp10;

    D_800F19CC->unk8.unk44 = 3;
    D_800F19CC->unk8.unk4A = 1;
    D_800F19CC->unk8.unk8C = 0;
    D_800F19CC->unk8.unk4C.unk.unk0 = arg2;
    D_800F19CC->unk8.unk4C.unk.unk1 = vs_battle_actors[arg2]->unk3C->unk36;
    D_800F19CC->unk4 = 1;
    D_800F19CC->unk0 = 0;
    D_800F19CC->unk29A8 = arg1->unk0.unk4;
    D_800F19CC->unk29AA = arg1->unk0.unk6;
    D_800F19CC->unk29AC = arg1->unk0.unk8;
    func_80085B10(arg0->unk0.unk6 + 6, &D_800F19CC->unk854[0], &D_800F19CC->unk8, 1);
    sp10.unk0 = arg0->unk0.unk6 + 6;
    sp10.unk4 = 5;
    sp10.unk10 = 4;
    sp10.unk2 = 1;
    sp10.unk3 = 0;
    sp10.unk14.u8[0] = arg2;
    sp10.unk16.u8[0] = 0xFD;
    func_800CF3F8(&sp10, 0);
}

void func_80073E30(func_8008C1C8_t* arg0, int arg1)
{
    short sp10[4];
    int var_s1;
    int shift = 7;

    sp10[0] = (arg0->unk0.unk0 << shift) + 0x40;
    sp10[2] = (arg0->unk0.unk2 << shift) + 0x40;
    var_s1 = 0;

    switch (arg0->unkC) {
    case 0:
        var_s1 = 1;
        break;
    case 1:
    case 3:
        if (!func_800BEBF4(arg0->unkE + 0x1B6)) {
            if (func_8007E454(arg0->unkE) == 0) {
                break;
            }
            func_800BEC14(arg0->unkE + 0x1B6, 1);
            if (arg0->unkE >= 0x1D2) {
                func_800CCB9C(arg0->unkE);
            }
        }
        arg0->unkC = 0;
        func_800CB2B8(4, arg0->unkE, 1);
        var_s1 = 1;
        break;
    }
    if (var_s1 != 0) {
        func_8009E070(0, sp10, 2);
        func_8008D5FC(arg0);
        return;
    }
    func_8009E070(0, sp10, 3);
}

void func_80073F7C(func_8008C1C8_t* arg0, func_8006EBF8_t3* arg1, int arg2)
{
    int i;

    D_800F196C = 8;
    D_800F18F0 = 1;
    func_8006EF10();
    D_800F1910.unk0 = arg0;
    D_800F1910.unk4.unk0 = *arg1;
    D_800F1910.unk4.unkC = arg2;
    for (i = 0; i < 16; ++i) {
        func_8009E5C4(i);
    }
    if (vs_main_settings.information != 0) {
        func_800CB2B8(0xB, arg0->unk0.unk6 + 6, 1);
    }
    D_800F19CC->unk4 = 0;
    D_800F19CC->unk8.unk0 = 0;
}

void func_80074050(func_8008C1C8_t* arg0, int arg1)
{
    short sp10[4];
    int i;
    int var_v0;

    D_800F196C = 9;
    D_800F18F0 = 1;
    func_8006EF10();
    D_800F1910.unk0 = arg0;
    func_800A1108(arg1, &D_800F1910.unk4);
    D_800F1910.unk4.unkC = arg1;

    for (i = 0; i < 16; ++i) {
        func_8009E5C4(i);
    }

    var_v0 = arg0->unk0.unk0;
    sp10[0] = (var_v0 << 7) + 0x40;
    var_v0 = arg0->unk0.unk2;
    sp10[2] = (var_v0 << 7) + 0x40;
    func_8009E070(0, sp10, 1);
    D_800F19CC->unk4 = 0;
    D_800F19CC->unk8.unk0 = 0;
}

int func_80074120(void)
{
    SVECTOR sp10;

    sp10.vx = (u_short)D_800F1910.unk4.unk0.unk4;
    sp10.vy = (u_short)D_800F1910.unk4.unk0.unk6;
    sp10.vz = (u_short)D_800F1910.unk4.unk0.unk8;

    if ((func_8006DEFC(&sp10, 0, 0x28) == 0)
        && (((func_800A0BE0(0) & 0x08000000) != 0))) {
        return 0;
    }
    return 1;
}

void func_8007418C(void)
{
    SVECTOR sp10;

    sp10.vx = (u_short)D_800F1910.unk4.unk0.unk4;
    sp10.vy = (u_short)D_800F1910.unk4.unk0.unk6;
    sp10.vz = (u_short)D_800F1910.unk4.unk0.unk8;
    func_8006DEFC(&sp10, 0, 0x28);
}

void func_800741D4(void)
{
    D_800F18F0 = 2;
    if (D_800F196C == 8) {
        vs_gametime_tickspeed = 4;
        func_80073D30(D_800F1910.unk0, &D_800F1910.unk4, D_800F1910.unk4.unkC);
        return;
    }
    func_80073E30(D_800F1910.unk0, D_800F1910.unk4.unkC);
}

int func_8007424C(void)
{
    int ret = 0;
    if (func_800A0BE0(0) & 0x08000000) {
        ret = func_800CB45C() == 0;
    }
    return ret;
}

int func_80074294(void) { return D_800F1868 & 3; }

void func_800742A4(void)
{
    short sp10[4];
    int v;

    D_800F18F0 = 4;
    vs_gametime_tickspeed = 2;
    v = 7;
    sp10[0] = (D_800F1910.unk0->unk0.unk0 << v) + 0x40;
    sp10[2] = (D_800F1910.unk0->unk0.unk2 << v) + 0x40;
    func_8009E070(0, sp10, 4);
    func_800CB50C();
}

void func_80074314(void)
{
    D_800F18F0 = 4;
    vs_gametime_tickspeed = 2;
    func_800CB50C();
    func_8008DEAC(&D_800F1910.unk0->unk0, 1);
    func_800E68EC(D_800F1910.unk0->unk0.unk0, D_800F1910.unk0->unk0.unk2);
}

int func_80074374(void)
{
    SVECTOR sp10;
    short sp18[6];
    int temp_s0;

    func_800A1108(0, (func_8006EBF8_t*)sp18);
    sp10.vx = sp18[2];
    sp10.vz = sp18[4];
    sp10.vy = sp18[3] - 0x5A;
    temp_s0 = func_8006DEFC(&sp10, 1, 0x28);

    if (func_8009E480() != 0) {
        return 0;
    }
    return temp_s0;
}

void func_800743E0(int arg0, int arg1)
{
    int temp_v1 = D_800F1910.unk0->unkC;
    D_800F18F0 = 3;
    if (temp_v1 != 0) {
        switch (temp_v1) {
        case 1:
            arg1 = 2;
            break;
        case 2:
            arg1 = 1;
            break;
        case 3:
            arg1 = 3;
            break;
        }
        func_800CB2B8(arg1, D_800F1910.unk0->unkE, 1);
        func_8006C2FC();
    } else {
        short temp_v1_2 = D_800F1910.unk0->unk10;
        if (temp_v1_2 < 0x40) {
            func_800CB18C(D_800F1910.unk0 + 1);
        } else {
            func_800CB1C0(temp_v1_2 - 0x40);
        }
        func_8006C39C();
    }
}

int func_800744B8(void)
{
    D_800F4E98_t* temp_v0;

    if (D_800F1910.unk0->unkC != 0) {
        if (func_800CB45C() != 0) {
            return 1;
        }
        func_8006C40C();
        return 0;
    }
    func_800C97BC();
    temp_v0 = func_800CB66C();
    if (temp_v0->unk0 == 1) {
        return 1;
    }
    if (temp_v0->unk2 != 0) {
        func_800BEC14((D_800F1910.unk0->unk10 + 0x3C0), 1);
    } else {
        func_8008D5FC(D_800F1910.unk0);
    }
    func_800CB114();
    func_8006C40C();
    return 0;
}

void func_80074580(void)
{
    if (vs_main_projectionDistance < 0x110) {
        func_800A087C(0, func_800A0BE0(0) & ~2);
    }
    if (func_8006F204() != 0) {
        D_800F18F0 = 1;
        D_800F186C = 1;
        D_800F19C8 = 1;
        func_8008C40C();
    }
}

void func_800745EC(void)
{
    func_8006EBF8_t sp10;

    if (vs_main_buttonsPressed.all & 0xC40) {
        D_800F18F0 = 2;
        D_800F186C = 0;
        D_800F19C8 = 0;
        func_800A1108(0, &sp10);
        func_80074B14(0, &sp10.unk0.unk0.fields.unk0);
        func_8007A850(&D_800F1904->unk6C);
        if ((D_800F1904->unk6C.unk0.vx
                - (D_800F1904->unk6C.unk0.vx - (D_800F1904->unk6C.unk0.vx % 512)))
            >= 0x101) {
            D_800F1904->unk6C.unk0.vx = (D_800F1904->unk6C.unk0.vx & ~0x1FF) + 0x200;
        } else {
            D_800F1904->unk6C.unk0.vx = D_800F1904->unk6C.unk0.vx & ~0x1FF;
        }

        D_800F1904->unk34.unk10.vx = 0;
        D_800F1904->unk34.unk0.vx = D_800F1904->unk6C.unk0.vx;

        D_800F1904->unk6C = D_800F1904->unk34;

        D_800F1904->unk98 = D_800F1904->unk60;
        D_800F1904->unk9C = D_800F1904->unk64;
        D_800F1904->unkA0 = D_800F1904->unk68;
        func_8007A9DC(&D_800F1904->unk0.unk0.unk0, &D_800F1904->unk0.unk0.unk10,
            &D_800F1904->unk6C.unk0);
        func_8006EF5C(&D_800F1904->unk0.unk0.unk0);
    }
}

void func_80074744(void)
{
    if (vs_main_projectionDistance >= 273) {
        func_800A087C(0, func_800A0BE0(0) | 2);
    }
    if (func_8006F204() != 0) {
        func_800732AC();
    }
}

int func_80074798(func_8006EBF8_t* arg0, char* arg1)
{
    int var_v1 = (arg0->unk0.unkA + 0x200) & 0xFFF;
    if (var_v1 < 0) {
        var_v1 += 0x3FF;
    }
    arg1[0] = arg0->unk0.unk0.fields.unk0;
    arg1[2] = arg0->unk0.unk0.fields.unk2;
    arg1[1] = arg0->unk0.unk0.fields.unk1;

    var_v1 = var_v1 >> 0xA;
    switch (var_v1) {
    case 0:
        --arg1[2];
        break;
    case 1:
        --arg1[0];
        break;
    case 2:
        ++arg1[2];
        break;
    default:
        ++arg1[0];
        break;
    }
    return var_v1;
}

int func_80074860(int arg0)
{
    func_8006EBF8_t sp10;
    char sp20[4];

    func_800A1108(arg0, &sp10);
    func_80074798(&sp10, sp20);
    return func_800BEC58(4, 0, sp20, 1) == 1;
}

func_8008C1C8_t* func_800748B8(int arg0)
{
    func_8006EBF8_t sp10;
    char sp20[4];
    func_8008C1C8_t* temp_s1;
    char* s0 = sp20;

    func_800A1108(arg0, &sp10);
    func_80074798(&sp10, sp20);
    temp_s1 = func_8008BC04(s0[0], s0[2], s0[1]);
    if (((((func_8008DC7C((s0[0] << 7) | 0x40, (s0[2] << 7) | 0x40) << 0x11) >> 0x11)
             - sp10.unk0.unk6)
            + 0x3F)
        >= 0x7FU) {
        temp_s1 = NULL;
    }
    return temp_s1;
}

func_8008D710_t* func_80074950(int arg0)
{
    func_8006EBF8_t sp10;
    char sp20[4];
    func_8008D710_t* temp_v0;
    int temp_s2;
    char* s1 = sp20;

    func_800A1108(arg0, &sp10);
    temp_s2 = func_80074798(&sp10, sp20);
    temp_v0 = func_8008D508(s1[0], s1[2], s1[1]);

    if ((temp_v0 != NULL) && (temp_v0->unk12 == temp_s2)) {
        if (!func_800BEBF4((temp_v0->unk10 + 0x3C0))) {
            int v = ((func_8008DC7C((s1[0] << 7) | 0x40, (s1[2] << 7) | 0x40) << 0x11)
                        >> 0x11)
                  + 0x60;
            if (sp10.unk0.unk6 == v) {
                return temp_v0;
            }
        }
    }
    return NULL;
}

int func_80074A20(int arg0)
{
    int ret;

    func_800E6700(arg0);
    ret = 0;

    if (vs_battle_actors[arg0] != NULL) {
        vs_battle_actors[arg0]->unk8 = 0;
        if (vs_battle_actors[arg0]->unk3C->currentHP == 0) {
            func_80095B7C(arg0, 0);
            vs_battle_actors[arg0]->unk8 = 0x20;
            if (vs_battle_actors[arg0]->unk26 == 0) {
                func_8009F314(arg0, &D_800F19CC->unk29A8, 1);
                func_800A09D8(arg0, 1);
                if ((vs_battle_actors[arg0]->unk27 != 0x80) || (arg0 == 0)) {
                    ret = 1;
                }
            }
        }
    }
    return ret;
}

void func_80074B14(int arg0, char* arg1)
{
    u_int temp_v0;
    int var_a2;
    char var_a0;
    char var_a1;

    temp_v0 = func_800A0BE0(arg0) & 0x70000;
    var_a0 = 0;
    if (temp_v0 != 0) {
        var_a1 = 0;
        var_a2 = temp_v0 >> 0x10;
    } else {
        var_a0 = arg1[0];
        var_a1 = arg1[2];
        var_a2 = arg1[1];
    }
    if (func_8008B764(var_a0, var_a1, var_a2)->unk0_18 & 1) {
        func_8008C2C0(arg1[0], arg1[2], arg1[1], D_800F19D0.unk20 == 0x900);
        return;
    }
    func_8008C40C();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80074BAC);

int func_800751B8(int arg0, func_8006EBF8_t3* arg1)
{
    D_800F1910_t2* temp_v0_2;
    func_8008B764_t* temp_s4;
    int temp_s3;
    u_int temp_a2;
    u_int temp_v0;
    vs_battle_actor* temp_s0;
    func_8006EBF8_t3* s2 = arg1;
    int _[4] __attribute__((unused));

    temp_v0 = func_800A0BE0(arg0);
    temp_a2 = temp_v0 & 0x70000;
    temp_s3 = (temp_v0 >> 0xE);
    temp_s3 &= 1;

    if (temp_a2 != 0) {
        temp_s4 = func_8008B764(0, 0, temp_a2 >> 0x10);
    } else {
        temp_s4 = func_8008B764(
            arg1->unk0.fields.unk0, arg1->unk0.fields.unk2, arg1->unk0.fields.unk1);
    }

    if (D_800F1A48 == 0) {
        if (!(temp_v0 & 0x01000000)) {
            temp_s0 = vs_battle_actors[arg0];

            if (((s2->unk0.value & 0xFFFFFF) != (temp_s0->unk2C.s32 & 0xFFFFFF))
                || (temp_s3 != temp_s0->unk2C.u8[3]) || (temp_v0 & 0x70000)) {
                if (D_800F196C != 3) {
                    if (temp_s4->unk0_16) {
                        if (!(temp_v0 & 0x16704000)) {
                            temp_v0_2 = func_8008D438(s2->unk0.fields.unk0,
                                s2->unk0.fields.unk2, s2->unk0.fields.unk1);
                            if ((temp_v0_2 != NULL) && (temp_v0_2->unk6 != 0x10)) {
                                func_80073F7C((func_8008C1C8_t*)temp_v0_2, arg1, arg0);
                                temp_s0->unk2C.s32 = s2->unk0.value;
                                temp_s0->unk2C.u8[3] = temp_s3;
                                return 3;
                            }
                        }
                    }
                }
                if (!(temp_v0 & 0x504000)) {
                    temp_s0->unk2C.s32 = s2->unk0.value;
                }
                temp_s0->unk2C.u8[3] = temp_s3;
            }
            if ((temp_s4->unk0_17)) {
                if (arg1->unk6 >= 0x11) {
                    vs_battle_actors[arg0]->unk3C->currentHP = 0;
                    func_800792E4(0, arg0, 0);
                    if (func_800BEC58(0xC, 0, NULL, 0) == 1) {
                        return 1;
                    }
                    return 2;
                }
            }
        }
    }
    return 0;
}

void func_800753F8(vs_battle_actor* arg0, SVECTOR* arg1)
{
    if (arg0->unkC < 0) {
        if (arg0->unkC >= -0x7FFF) {
            arg1->vx = arg0->unkC / ONE;
            arg0->unkC = 0;
        } else {
            arg1->vx = -8;
            arg0->unkC += 0x8000;
        }
    } else if (arg0->unkC <= 0x7FFF) {
        arg1->vx = arg0->unkC / ONE;
        arg0->unkC = 0;
    } else {
        arg1->vx = 8;
        arg0->unkC -= 0x8000;
    }

    if (arg0->unk10.s32 < 0) {
        if (arg0->unk10.s32 >= -0x7FFF) {
            arg1->vz = arg0->unk10.s32 / ONE;
            arg0->unk10.s32 = 0;
        } else {
            arg1->vz = -8;
            arg0->unk10.s32 += 0x8000;
        }
    } else if (arg0->unk10.s32 <= 0x7FFF) {
        arg1->vz = arg0->unk10.s32 / ONE;
        arg0->unk10.s32 = 0;
    } else {
        arg1->vz = 8;
        arg0->unk10.s32 -= 0x8000;
    }

    if (arg0->unk14 < 0) {
        if (arg0->unk14 >= -0x7FFF) {
            arg1->vy = arg0->unk14 / ONE;
            arg0->unk14 = 0;
        } else {
            arg1->vy = -8;
            arg0->unk14 += 0x8000;
        }
    } else if (arg0->unk14 <= 0x7FFF) {
        arg1->vy = arg0->unk14 / ONE;
        arg0->unk14 = 0;
    } else {
        arg1->vy = 8;
        arg0->unk14 -= 0x8000;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80075554);

void func_800760CC(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    u_int temp_s3;

    temp_s3 = arg1 - 16;
    SetGeomOffset(arg0 / 2, ((int)(temp_s3 + (temp_s3 >> 0x1F)) >> 1) + 0x10);
    SetGeomScreen(arg2);
    SetDefDrawEnv(vs_main_drawEnv, 0, 0, arg0, temp_s3);
    SetDefDispEnv(vs_main_dispEnv, arg0, 0, arg0, temp_s3);
    SetDefDrawEnv(&vs_main_drawEnv[1], arg0, 0, arg0, temp_s3);
    SetDefDispEnv(&vs_main_dispEnv[1], 0, 0, arg0, temp_s3);
    setRECT(&vs_main_dispEnv[0].screen, 0, 8, 256, 224);
    setRECT(&vs_main_dispEnv[1].screen, 0, 8, 256, 224);
    D_8005DFD4 = 0;
    D_8005DFD8 = 0;
    D_8005DFD6 = arg0;
    D_8005DFDA = temp_s3;
    vs_main_drawEnv[1].dtd = 1;
    vs_main_drawEnv[0].dtd = 1;
    vs_main_drawEnv[1].dfe = 0;
    vs_main_drawEnv[0].dfe = 0;
    vs_main_drawEnv[1].isbg = 0;
    vs_main_drawEnv[0].isbg = 0;
    setRGB0(&vs_main_drawEnv[0], arg3, arg4, arg5);
    setRGB0(&vs_main_drawEnv[1], arg3, arg4, arg5);
    PutDispEnv(&vs_main_dispEnv[vs_main_frameBuf]);
    PutDrawEnv(&vs_main_drawEnv[vs_main_frameBuf]);
}

int func_8007629C(u_long* otag)
{
    int ret;
    u_int temp_a0;

    vs_main_frameBuf = vs_main_frameBuf == 0;
    vs_main_getRand(0);
    SetGeomOffset(160, 112);
    DrawSync(0);
    ret = vs_main_gametimeUpdate(vs_gametime_tickspeed);
    if (D_8004A52C != 0) {
        while (1) {
            vs_main_gametimeUpdate(2);
            vs_main_buttonsState = (u_short)vs_main_updatePadState(0, *vs_main_padBuffer);
            vs_main_buttonsState |= vs_main_updatePadState(16, vs_main_padBuffer[1])
                                 << 16;
            vs_main_padConnect(0, vs_main_padBuffer[0]);
            vs_main_padConnect(16, vs_main_padBuffer[1]);
            vs_main_buttonsPressed.all =
                ~vs_main_buttonsPreviousState & vs_main_buttonsState;
            temp_a0 = vs_main_buttonsPressed.all >> 16;
            vs_main_buttonsReleased =
                vs_main_buttonsPreviousState & ~vs_main_buttonsState;
            vs_main_buttonsPreviousState = vs_main_buttonsState;
            if (temp_a0 & 0x800) {
                D_8004A52C ^= 1;
            }
            if ((temp_a0 & 0x100) || (D_8004A52C == 0)) {
                break;
            }
        }
    }
    PutDispEnv(&vs_main_dispEnv[vs_main_frameBuf]);
    PutDrawEnv(&vs_main_drawEnv[vs_main_frameBuf]);
    func_80048F8C();
    DrawOTag(otag);
    FntFlush(-1);
    return ret;
}

void func_8007647C(int arg0, int arg1)
{
    int temp_a1;
    int i;
    vs_battle_actor* temp_s1;
    vs_battle_actor2* temp_s0;

    temp_s1 = vs_battle_actors[arg0];
    temp_s0 = temp_s1->unk3C;
    vs_main_bzero(temp_s0, 0x964);
    temp_s0->maxHP = 1;
    temp_s0->currentHP = 1;

    for (i = 0; i < 24; ++i) {
        temp_s1->unk3C->name[i] =
            D_8004FDD0[i]; // Cube // Ashley Riot? But also reads 4 bytes over...
    }

    temp_a1 = arg1 & 0xFF;
    switch (temp_a1) {
    case 1:
        temp_s0->flags.fields.unk2_0 = 1;
        func_80095B7C(arg0, 8);
        break;
    case 2:
        /* fallthrough */
    case 4:
        temp_s0->flags.fields.unk2_0 = 0;
        break;
    default:
        temp_s0->flags.fields.unk2_0 = 1;
    }
    temp_s1->unk27 = 0x80;
    temp_s1->unk29 = 0;
    temp_s1->unk28 = 0;
    temp_s0->flags.fields.unk3 = 0x80;
}

typedef struct {
    vs_battle_actor unk0;
    vs_battle_actor2 unk50;
    vs_battle_actor3 unk9B4;
} vs_battle_actor_dat2;

typedef union {
    char u8[4];
    int s32;
} func_800765B0_t;

vs_battle_actor* func_800765B0(int arg0, int arg1, func_800765B0_t* arg2, int arg3)
{
    func_8007C8F8_t sp10;
    int i;
    int var_v1_2;
    vs_battle_actor_dat2* temp_v0;

    if (arg0 == 0xFF) {
        for (i = 2; i < 16; ++i) {
            if (vs_battle_actors[i] == NULL) {
                arg0 = i;
                break;
            }
        }
        if (i >= 0x10) {
            vs_main_nop10(0x86, 0);
            return NULL;
        }
    }

    if (vs_battle_actors[arg0] == NULL) {
        temp_v0 = vs_main_allocHeap(sizeof *temp_v0);
        vs_main_bzero(temp_v0, 0x9B4);
        temp_v0->unk0.unk3C = &temp_v0->unk50;
        temp_v0->unk0.unk44 = &temp_v0->unk9B4;
        temp_v0->unk0.unk18 = 0xFE;
        temp_v0->unk0.unk1C = 0x10;
        temp_v0->unk0.unk40 = 0;
        temp_v0->unk0.unk4 = arg0;
        temp_v0->unk0.unk0 = NULL;
        temp_v0->unk0.unk26 = 0;
        sp10.unk0 = 6;
        sp10.unk1 = (char)arg0;
        sp10.unkC.s32 = arg2->s32;
        sp10.unkC.u8[1] &= 1;
        var_v1_2 = arg1;
        sp10.unk4 = temp_v0->unk0.unk44;
        sp10.unk10 = arg1;
        if (arg1 < 0) {
            var_v1_2 = arg1 + 0xFF;
        }
        sp10.unk11 = var_v1_2 >> 8;
        sp10.unk12 = arg3;
        sp10.unk13 = arg2->u8[1] >> 4;
        func_800995E8(&sp10);
        while (func_800995B0() != 0) {
            func_8009967C();
            vs_main_gametimeUpdate(0);
        }
        vs_battle_actors[arg0] = &temp_v0->unk0;
        func_8007647C(arg0, arg1);
        func_800E6178(&temp_v0->unk0, -1);
        func_800A087C(arg0, 0x1846);
        return &temp_v0->unk0;
    }
    return NULL;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80076784);

void func_80076D50(u_int arg0, int arg1, int arg2, int arg3, int arg4)
{
    vs_battle_actor* temp_s1;
    vs_battle_actor2* temp_s0;

    temp_s1 = vs_battle_actors[arg0];
    temp_s0 = temp_s1->unk3C;
    temp_s1->unk4 = arg0;
    temp_s1->unk18 = arg1;
    temp_s1->unk1A = 0;
    temp_s1->unk2A = arg2;
    temp_s1->unk2B = arg3;
    temp_s1->unk20 = 0;

    switch (arg0) {
    case 0:
        temp_s1->unk1C = 1;
        break;
    case 1:
        temp_s1->unk1C = 2;
        break;
    default:
        switch (arg4 & 3) {
        case 1:
            temp_s1->unk1C = 4;
            temp_s1->unk20 |= 1;
            func_8009D934(arg0, 1, 0);
            break;
        case 0:
            temp_s1->unk1C = 2;
            break;
        case 2:
        case 3:
            temp_s1->unk1C = 8;
            break;
        }
    }

    temp_s1->unk24 = arg4 & 0x1C;
    temp_s1->unk2C.u8[3] = 0;
    temp_s1->unk2C.u8[2] = 0;
    temp_s1->unk2C.u8[1] = 0;
    temp_s1->unk2C.u8[0] = 0;
    temp_s1->unk1E = 0;
    temp_s1->unk8 = 0;
    temp_s0->maxHP = 100;
    temp_s0->currentHP = 100;
    temp_s0->maxMP = 100;
    temp_s0->currentMP = 100;
    temp_s0->risk = 0;
    temp_s0->flags.fields.unk0 = 0;

    if (arg1 == 41) {
        temp_s0->unk30 = 16;
        temp_s0->unk32 = 32;
    } else if (arg1 == 48) {
        temp_s0->unk30 = 2;
        temp_s0->unk32 = 8;
    } else {
        temp_s0->unk30 = 2;
        temp_s0->unk32 = 4;
    }

    temp_s0->unk31 = 9;
    temp_s0->unk33 = 18;
    temp_s0->weapon.unk10B = 20;
    temp_s0->weapon.range = 5;
    temp_s0->weapon.unk125 = 4;
    temp_s0->weapon.unk126 = 5;
    temp_s0->flags.fields.unk2_0 = 0;
    temp_s0->weapon.unk127_3 = 0;
    temp_s1->unk27 = 128;
    temp_s1->unk29 = 0;
    temp_s1->unk28 = 0;
    temp_s0->flags.fields.unk3 = 128;
}

void func_80076F24(int arg0, D_800FAB18_t* arg1, int arg2, int arg3, int arg4, int arg5)
{
    int temp_v1;
    vs_battle_actor* temp_s0;
    vs_battle_actor2* temp_s4;

    temp_s0 = vs_battle_actors[arg0];
    temp_s0->unk4 = arg0;
    temp_s4 = temp_s0->unk3C;
    temp_s0->unk18 = arg1->unk2;
    temp_s0->unk1A = arg1->unk0;
    temp_s0->unk2A = arg2;
    temp_s0->unk2B = arg3;
    temp_s0->unk20 = 0;

    switch (arg0) {
    case 0:
        temp_s0->unk1C = 1;
        break;
    case 1:
        temp_v1 = 2;
        temp_s0->unk1C = temp_v1;
        break;
    default:
        switch (arg4 & 3) {
        case 1:
            temp_s0->unk1C = 4;
            temp_s0->unk20 |= 1;
            func_8009D934(arg0, 1, 0);
            break;
        case 2:
        case 3:
            temp_s0->unk1C = 8;
            break;
        case 0:
            temp_s0->unk1C = 2;
            break;
        }
    }

    if (arg4 & 0x80) {
        temp_s0->unk26 = 1;
    } else {
        temp_s0->unk26 = 0;
    }

    temp_s0->unk24 = arg4 & 0x1C;
    temp_s0->unk8 = 0;
    temp_s0->unk2C.u8[3] = 0;
    temp_s0->unk2C.u8[2] = 0;
    temp_s0->unk2C.u8[1] = 0;
    temp_s0->unk2C.u8[0] = 0;
    func_80076784(arg0, temp_s4, arg1, arg5);
}

int func_80077078(vs_battle_actor* arg0, int arg1, int arg2, int* arg3, int arg4)
{
    func_8007C8F8_t sp10;

    sp10.unk0 = 1;
    sp10.unk1 = arg1;
    sp10.unk2 = arg2;
    sp10.unkC.s32 = *arg3;
    sp10.unk4 = arg0->unk44;
    if (arg4 & 0x80) {
        sp10.unk10 = (arg4 & 0xF00) >> 8;
        sp10.unk11 = (arg4 & 0xF000) >> 0xC;
    } else {
        sp10.unk10 = 0xFF;
    }
    sp10.unk13 = 0;
    sp10.unk12 = 2;
    return func_800995E8(&sp10);
}

void func_800770FC(vs_battle_actor* arg0 __attribute__((unused)), int arg1)
{
    func_8007C8F8_t sp10;

    sp10.unk0 = 7;
    sp10.unk1 = arg1;
    sp10.unk2 = 0;
    sp10.unk10 = 0;
    func_800995E8(&sp10);
}

void func_80077130(vs_battle_actor* arg0, int arg1, int arg2, int arg3, int arg4)
{
    func_8007C8F8_t sp10;

    if (arg2 != 0xFF) {
        int temp_s0 = (arg1 * 2) + arg3;
        func_8009AA84(temp_s0);
        if (arg2 != 0) {
            sp10.unk0 = 3;
            sp10.unk1 = temp_s0;
            sp10.unk2 = arg2;
            sp10.unk4 = arg0->unk48[arg3];
            sp10.unk10 = arg1;
            if (arg3 == 0) {
                sp10.unk11 = 0xF0;
            } else {
                sp10.unk11 = 0xF1;
            }
            sp10.unk12 = arg4;
            func_800995E8(&sp10);
        }
    }
}

void func_800771E0(char* arg0, int arg1, int arg2, int arg3)
{
    func_8007C8F8_t sp10;

    if (((arg2 != 0) || (arg1 >= 2)) && ((arg1 < 2) || ((arg3 & 3) == 1))) {
        sp10.unk0 = 7;
        sp10.unk1 = arg1;
        sp10.unk2 = arg0[37];
        sp10.unk10 = 0;
        func_800995E8(&sp10);
    }
}

vs_battle_actor_dat* func_80077240(
    int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int* arg6, int arg7)
{
    int i;
    vs_battle_actor_dat* temp_v0;
    int _[6] __attribute__((unused));

    if (vs_battle_actors[arg0] != NULL) {
        return NULL;
    }
    if (arg0 < 0xA) {
        temp_v0 = vs_main_allocHeap(sizeof *temp_v0);
        vs_main_bzero(temp_v0, 0x9B4);
        i = 0xA;
        temp_v0->unk0.unk3C = &temp_v0->unk50;
        temp_v0->unk0.unk40 = 1;
        temp_v0->unk0.unk44 = &temp_v0->unk9B4;
        temp_v0->unk0.unk48[0] = &temp_v0->unk22B4[0];
        temp_v0->unk0.unk48[1] = &temp_v0->unk22B4[1];

        if (arg2 != 0) {
            for (i = 1; i < 11; ++i) {
                if (D_800E81E4[i] >= arg2) {
                    break;
                }
            }
        }
        temp_v0->unk0.equippedWeaponType = i;
        func_80077078(&temp_v0->unk0, arg0, arg1, arg6, arg7);
        if (arg1 != 0x7F) {
            func_800770FC(&temp_v0->unk0, arg0);
            func_80077130(&temp_v0->unk0, arg0, arg2, 0, arg3);
            func_80077130(&temp_v0->unk0, arg0, arg4, 1, arg5);
            func_800771E0(
                (char*)&temp_v0->unk0, arg0, temp_v0->unk0.equippedWeaponType, arg7);
        }
        return temp_v0;
    }
    return NULL;
}

void func_800773BC(
    vs_battle_actor* arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    func_800A0204(arg1, 0, 0, 0);
    func_800A087C(arg1, 0x1847);
    vs_battle_actors[arg1] = arg0;
    func_80076D50(arg1, arg2, arg3, arg4, arg5);
    func_800A0AFC(arg1, 0x9000, 0x12000);
    func_8009DF3C(arg1, 0);
    if (arg0->unk1C & 7) {
        if (arg1 != 0) {
            arg0->unk0 = vs_battle_actors[0]->unk0;
            vs_battle_actors[0]->unk0 = arg0;
        } else {
            arg0->unk0 = NULL;
        }
    }
    if (arg0->unk20 & 1) {
        func_800A087C(arg1, 0x1846);
    } else {
        func_800A087C(arg1, 0x46);
    }
    arg0->unk38 = 0;
    func_800E6178(arg0, -1);
}

vs_battle_actor* func_800774FC(
    int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int* arg6, int arg7)
{
    vs_battle_actor* temp_v0;

    temp_v0 =
        (vs_battle_actor*)func_80077240(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    if (temp_v0 != NULL) {
        while (func_800995B0() != 0) {
            func_8009967C();
            vs_main_gametimeUpdate(0);
        }
        func_800773BC(temp_v0, arg0, arg1, arg2, arg4, arg7);
        return temp_v0;
    }
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800775C0);

int func_80077DF0(void)
{
    func_80077DF0_t sp10;
    func_8006EBF8_t sp30;

    func_800A1108(0, &sp30);
    sp10.unk0 = sp30.unk0.unk4 * ONE;
    sp10.unk4 = sp30.unk0.unk6 * ONE + 0xFFFA6000;
    sp10.unk8 = sp30.unk0.unk8 * ONE;
    if (sp10.unk4 > 0) {
        sp10.unk4 = 0;
    }
    func_8006D9FC(&sp10, &sp10);
    sp10.unk10 = ((func_80077DF0_t3*)D_1F800000)->unk44;

    if ((sp10.unk0 == (sp10.unk10.unk0[0] & ~0xFFF))
        && (sp10.unk8 == (sp10.unk10.unk0[2] & ~0xFFF))
        && (sp10.unk4 == (sp10.unk10.unk0[1] & ~0xFFF))) {
        return 1;
    }
    return 0;
}

void func_80077EC4(void)
{
    int* temp_s0;

    func_8007CD70((VECTOR*)D_1F800034, (VECTOR*)(D_1F800034 + 4), -1, -1);
    temp_s0 = D_1F800034 - 13;
    temp_s0[25] = 0x1000;
    temp_s0[23] = 0;
    temp_s0[22] = 0;
    temp_s0[21] = 0;
}

void func_80077F14(int arg0, int arg1, SVECTOR* arg2)
{
    int var_v0;

    if (arg1 == -1) {
        var_v0 = 0;
    } else {
        var_v0 = func_800A152C(arg0, arg1, 2);
    }
    func_800A1AF8(arg0, var_v0, arg2, 0);
}

void func_80077F70(void)
{
    SVECTOR sp10;
    SVECTOR sp18;
    D_800F19CC_t2* temp_s0;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v1;

    temp_s0 = &D_800F19CC->unk854[D_800F19CC->unk0];
    func_800A1AF8(temp_s0->unk4.unk0, 0, &sp10, 0);
    if (temp_s0->unk4A != 0) {
        if (temp_s0->unk4C[0].unk40 == 0) {
            func_80077F14(
                temp_s0->unk4C[0].unk0.unk.unk0, temp_s0->unk4C[0].unk0.unk.unk1, &sp18);
        } else {
            sp18 = temp_s0->unk4C[0].unk0.vec;
        }
    } else {
        func_800A1AF8(temp_s0->unk4.unk0, 0, &sp18, 0);
    }
    temp_v0 = sp18.vx - sp10.vx;
    temp_v0_2 = sp18.vz - sp10.vz;
    temp_v0_3 = vs_gte_rsqrt((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2));
    temp_v1 = sp18.vy - sp10.vy;
    vs_gte_rsqrt((temp_v1 * temp_v1) + (temp_v0_3 * temp_v0_3));
}

void func_800780A8(SVECTOR* arg0)
{
    SVECTOR sp10;
    SVECTOR sp18;
    D_800F19CC_t2* temp_s0;

    temp_s0 = &D_800F19CC->unk854[D_800F19CC->unk0];
    func_800A1AF8(temp_s0->unk4.unk0, 0, &sp10, 0);
    if (temp_s0->unk4A != 0) {
        if (temp_s0->unk4C[0].unk40 == 0) {
            func_80077F14(
                temp_s0->unk4C[0].unk0.unk.unk0, temp_s0->unk4C[0].unk0.unk.unk1, &sp18);
        } else {
            sp18 = temp_s0->unk4C[0].unk0.vec;
        }
    } else {
        sp18 = temp_s0->unk844;
    }
    arg0->vx = sp10.vx + (sp18.vx - sp10.vx) / 2;
    arg0->vz = sp10.vz + (sp18.vz - sp10.vz) / 2;
    arg0->vy = sp10.vy + (sp18.vy - sp10.vy) / 2;
}

void func_8007820C(int arg0)
{
    SVECTOR sp10;

    func_800780A8(&sp10);
    if (arg0 != 0) {
        func_8006DEFC(&sp10, 1, 0x28);
    }
}

void func_80078248(void)
{
    if (D_800F19CC->unk2984 != 0) {
        if (D_800F19CC->unk8.unk4 != 0) {
            if (++D_800F19CC->unk298E >= 0x1F) {
                func_80070F28(1);
            }
        } else if (func_800C58F8(&D_800F19CC->unk298D) != 0) {
            D_800F19CC->unk298C = D_800F19CC->unk298D;
            func_80070F28(1);
        }
    } else {
        func_80070F28(1);
    }
}

void func_800782E4(void)
{
    if (D_800F19CC->unk2984 != 0) {
        if (D_800F19CC->unk8.unk4 != 0) {
            u_int v = ++D_800F19CC->unk298E;
            if (v < 0x1F) {
                return;
            }
        } else if (func_800C4794(&D_800F19CC->unk2998) == 0) {
            return;
        }
    }
    func_8007053C();
}

void func_80078364(void)
{
    if (D_800F19CC->unk2984 != 0) {
        if (D_800F19CC->unk8.unk4 != 0) {
            if (++D_800F19CC->unk298E >= 0x1F) {
                D_800F19CC->unk298C = 0;
                func_80070F28(2);
            }
        } else if (func_800C58F8(&D_800F19CC->unk298D) != 0) {
            D_800F19CC->unk298C = D_800F19CC->unk298D;
            if (D_800F19CC->unk298C == 0xFF) {
                if (D_800E8184[vs_main_skills[D_800F19CC->unk8.unk0].unk2_4] != 0) {
                    func_80072BA8(D_800F19CC->unk8.unk0);
                    return;
                }
                func_800C16DC();
                func_800C06E0();
                func_800C0738();
                func_800C05B4();
                func_800704D8();
                return;
            }
            func_80070F28(2);
        }
    } else {
        D_800F19CC->unk298C = 0;
        func_80070F28(2);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800784AC);

void func_80078748(void)
{
    D_800F19CC_t2* temp_s0 = &D_800F19CC->unk854[D_800F19CC->unk0 & 3];
    if ((func_800CB45C() == 0)
        && ((func_800A0BE0(temp_s0->unk4.unk0) & 0x08000100) == 0x08000100)
        && (func_800995B0() == 0) && (func_800CEEBC() != 0)) {
        func_800704B0();
    }
}

void func_800787F0(void)
{
    if (!(D_800F1868 & 2)) {
        func_80070278();
        func_800CEF74(0);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80078828);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80078AB4);

void func_80079030(void) { func_8007138C(); }

void func_80079050(void)
{
    if (func_800DEC88(&D_800F19CC->unk854[D_800F19CC->unk0 & 3]) == 0) {
        func_80069D14();
        func_8006FCBC();
    }
}

void func_800790BC(void)
{
    D_800F19CC_t2* var_s3;
    int j;
    int i;
    int var_s4;

    var_s4 = 1;

    for (i = 0; i < D_800F19CC->unk4; ++i) {

        var_s3 = &D_800F19CC->unk854[i % 4];

        for (j = 0; j < var_s3->unk4A; ++j) {
            if ((var_s3->unk4C[j].unk40 == 0)
                && ((func_8009E4B0(var_s3->unk4C[j].unk0.unk.unk0) + 1) > 1)) {
                var_s4 = 0;
            }
        }
    }

    if (var_s4 != 0) {

        var_s4 = 1;

        for (i = 0; i < D_800F19CC->unk4; ++i) {

            var_s3 = &D_800F19CC->unk854[i % 4];

            if (var_s3->unk44 == 0) {
                func_80074A20(var_s3->unk4.unk0);
            }

            for (j = 0; j < var_s3->unk4A; ++j) {
                if ((var_s3->unk4C[j].unk40 == 0)
                    && (func_80074A20(var_s3->unk4C[j].unk0.unk.unk0) != 0)) {
                    var_s4 = 2;
                }
            }
        }

        if (var_s3->unk4.unk0 != 0) {
            var_s4 = 0;
        }

        func_8006FBCC(var_s4);
    }
}

int func_800792E4(int arg0, int arg1, int arg2)
{
    int ret = 0;
    if (vs_battle_actors[arg1] != NULL) {
        if (vs_battle_actors[arg1]->unk3C->currentHP == 0) {
            func_8006C1CC(arg0, arg1, arg2);
            if (arg1 == 0) {
                func_8009722C();
                func_800BEC58(0x40, 0, NULL, 0);
                func_80073898();
                ret = 1;
            } else if (vs_battle_actors[arg1]->unk26 == 0) {
                func_8006A228(arg1, 1);
            }
        } else {
            func_8009E5C4(arg1);
        }
    }
    return ret;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800793C0);

void func_800797BC(void)
{
    func_800C97BC();
    if (func_800CB66C()->unk0 != 1) {
        func_8006C40C();
        func_800CB114();
        func_8006F89C();
    }
}

void func_8007980C(void)
{
    if (!(D_800F1868 & 3)) {
        func_8006FA20();
    }
}

void func_8007983C(void)
{
    func_800C97BC();
    if ((func_800CB66C()->unk0 != 1) && (func_800CB45C() == 0)) {
        func_8006C40C();
        func_800CB114();
        func_800CB50C();
        func_8006F89C();
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", vs_battle_exec);

int func_8007A850(D_800F1904_t3* arg0)
{
    VECTOR sp10;
    VECTOR sp20;
    int temp_s0;
    int temp_v0_2;
    int temp_v1;

    sp10.vx = (D_1F800000[13] - D_1F800000[17]) / ONE;
    sp10.vz = (D_1F800000[15] - D_1F800000[19]) / ONE;
    sp10.vy = (D_1F800000[14] - D_1F800000[18]) / ONE;

    VectorNormal(&sp10, &sp20);
    temp_s0 = ratan2(sp20.vx, sp20.vz);
    temp_v1 = temp_s0 + 0x1000;
    temp_s0 = temp_v1 / ONE;
    temp_s0 = temp_v1 - (temp_s0 * ONE);
    D_1F800000[22] = temp_s0;
    temp_v0_2 = ratan2(
        sp20.vy, SquareRoot12((sp20.vx * sp20.vx) / ONE + (sp20.vz * sp20.vz) / ONE));
    D_1F800000[21] = temp_v0_2;
    if (arg0 != NULL) {
        arg0->unk0.vx = temp_s0;
        arg0->unk0.vy = temp_v0_2;
        if (sp10.vx != 0) {
            arg0->unk0.vz = (sp10.vx * ONE) / sp20.vx;
        } else if (sp10.vz != 0) {
            arg0->unk0.vz = (sp10.vz * ONE) / sp20.vz;
        } else {
            arg0->unk0.vz = 0x400;
        }
    }
    return temp_s0;
}

void func_8007A9DC(VECTOR* arg0, VECTOR* arg1, VECTOR* arg2)
{
    int temp_s0;

    arg0->vx = rsin(arg2->vx);
    arg0->vz = rcos(arg2->vx);
    temp_s0 = rsin(arg2->vy);
    arg0->vy = (temp_s0 * ONE) / rcos(arg2->vy);
    VectorNormal(arg0, arg0);
    arg0->vx = (arg0->vx * arg2->vz) + arg1->vx;
    arg0->vz = (arg0->vz * arg2->vz) + arg1->vz;
    arg0->vy = (arg0->vy * arg2->vz) + arg1->vy;
}

void func_8007AACC(VECTOR* arg0)
{
    func_8007A9DC((VECTOR*)D_1F800034, (VECTOR*)&D_1F800034[4], arg0);
}

void func_8007AAF8(int* arg0)
{
    D_1F800000[17] = -rsin(arg0[0]);
    D_1F800000[19] = -rcos(arg0[0]);
    D_1F800000[18] = (-rsin(arg0[1]) * 0x1000) / rcos(arg0[1]);
    VectorNormal((VECTOR*)(D_1F800000 + 0x11), (VECTOR*)(D_1F800000 + 0x11));
    D_1F800000[17] = (D_1F800000[17] * arg0[2]) + D_1F800000[13];
    D_1F800000[19] = (D_1F800000[19] * arg0[2]) + D_1F800000[15];
    D_1F800000[18] = (D_1F800000[18] * arg0[2]) + D_1F800000[14];
}

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

void func_8007AC94(int arg0) { D_1F800000[23] = arg0; }

int func_8007ACA0(void) { return *getScratchAddr(0x17) & 0xFFF; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007ACB0);

void _lookAt(VECTOR* from, VECTOR* to, MATRIX* mat)
{
    static const VECTOR D_800689F8 = { 0, -ONE, 0 };
    VECTOR sp10;
    VECTOR sp20;
    VECTOR sp30;
    VECTOR sp40 = D_800689F8;
    int _[2] __attribute__((unused));

    sp10.vx = to->vx - from->vx;
    sp10.vy = to->vy - from->vy;
    sp10.vz = to->vz - from->vz;
    VectorNormal(&sp10, &sp30);
    OuterProduct0(&sp30, &sp40, &sp20);
    VectorNormal(&sp20, &sp20);
    OuterProduct0(&sp20, &sp30, &sp40);
    VectorNormal(&sp40, &sp40);
    mat->m[0][0] = sp20.vx;
    mat->m[1][0] = sp20.vy;
    mat->m[2][0] = sp20.vz;
    mat->m[0][1] = sp40.vx;
    mat->m[1][1] = sp40.vy;
    mat->m[2][1] = sp40.vz;
    mat->m[0][2] = sp30.vx;
    mat->m[1][2] = sp30.vy;
    mat->m[2][2] = sp30.vz;
}

void func_8007B0FC(void) { }

void func_8007B104(void) { }

void func_8007B10C(int arg0, int arg1, int arg2, short arg3, short arg4)
{
    func_80047280(arg0, arg1, 0, arg2, arg3, arg4);
    func_80047280(arg0, arg1, 1, arg2, arg3, arg4);
    func_80047280(arg0, arg1, 2, arg2, arg3, arg4);
}

void func_8007B1B8(int arg0, int arg1, short arg2, short arg3, short arg4)
{
    func_80047280(arg0, arg1, 0, arg2, arg3, arg4);
    func_80047280(arg0, arg1, 1, arg2, arg3, arg4);
    func_80047280(arg0, arg1, 2, arg2, arg3, arg4);
    func_80047FC0(arg0, arg1, 0, arg2, arg3, arg4);
    func_80047280(arg0, arg1, 0xD, arg2, arg3, arg4);
}

void func_8007B29C(int arg0, int arg1, int arg2, short arg3, short arg4, short arg5)
{
    if (arg2 < 9) {
        func_80047280(arg0, arg1, arg2 + 4, arg3, arg4, arg5);
        func_80047FC0(arg0, arg1, arg2 + 1, arg3, arg4, arg5);
    }
}

void func_8007B344(int arg0, int arg1, short arg2, short arg3, short arg4)
{
    func_800478E0(arg0, arg1, arg2, arg3, arg4);
}

void func_8007B378(int arg0, u_short* arg1, int arg2)
{
    func_80046C80(arg0, 0, arg1);
    func_80046C80(arg0, 1, arg1 + 0x100);
    func_80046C80(arg0, 2, arg1 + 0x200);
}

void func_8007B3D0(int arg0, int arg1, u_short* arg2, int arg3)
{
    func_80046C80(arg0, arg1 + 4, arg2, arg3);
}

void func_8007B3F0(int arg0, D_8005DC6C_t* arg1) { func_800472D0(arg0, arg1); }

void func_8007B410(void)
{
    func_8007B10C(0xD, 4, -4, -4, 0);
    func_80048FEC(0);
    func_8006C2A0();
    func_8008B4BC(1);
    func_8008B4C8(0);
    func_8008E480(1);
    D_800F1968 = 1;
}

void func_8007B470(void)
{
    func_80048FEC(1);
    func_8007B1B8(8, 4, 0, 0, 0);
    func_8006C250();
    func_8008B4BC(0);
    func_8008E480(0);
    D_800F1968 = 0;
}

void func_8007B4C4(void)
{
    D_800F18F0 = 2;
    func_8007B470();
    if (D_800F1864 != 0) {
        func_8009E5C4(0);
    }
}

void func_8007B508(void)
{
    if (!(func_800BEBF4(0xB6)) || ((func_800BEBF4(0xB6)) == 2)
        || ((func_800BEBF4(0xB6)) == 3)) {
        if (func_8006F760() != 0) {
            D_800F18F0 = 5;
            if (D_800F1864 != 0) {
                func_8009E070(0, NULL, 6);
                func_8006F848();
            }
            func_8008D594(1);
            return;
        }
    }
    if ((D_800F19CC->unk8.unk0 != 0)
        && !((vs_main_skills[D_800F19CC->unk8.unk0].flags_15))
        && (D_800F19CC->unk8.unk44 == 0) && (D_800F19CC->unk2C07 == 0)
        && (D_800F19CC->unk8.unk4 == 0)) {
        D_800F18F0 = 5;
        if (D_800F1864 != 0) {
            func_8009E070(0, NULL, 6);
            func_8006F848();
        }
        func_8008D594(1);
        return;
    }
    func_8007B4C4();
}

void func_8007B63C(void)
{
    u_int temp_v0_2;

    if ((D_800F19CC->unk8.unk0 != 0)
        && !((vs_main_skills[D_800F19CC->unk8.unk0].flags_15))
        && (D_800F19CC->unk8.unk44 == 0) && (D_800F19CC->unk2C07 == 0)
        && (D_800F19CC->unk8.unk4 == 0)) {
        D_800F18F0 = 6;
        func_8007B410();
        func_800CB2B8(0xC, D_800F19CC->unk8.unk0, 1);
        vs_main_skills[D_800F19CC->unk8.unk0].flags_15 = 1;
        return;
    }
    temp_v0_2 = func_8006F760();
    D_800F18F0 = 6;
    func_8007B410();
    func_800CB208(temp_v0_2 >> 0x10, temp_v0_2 & 0xFFFF);
}

void func_8007B764(void)
{
    if ((func_800BEBF4(0xAB) & 0xFF) >= 3) {
        if (D_800F1900 != NULL) {
            func_800CB158(D_800F1900);
            D_800F18F0 = 4;
            func_8007B410();
            return;
        }
        func_8007B508();
        return;
    }
    func_8007B4C4();
}

void func_8007B7DC(int arg0, int arg1)
{
    if (func_800BEBF4(0xAB) >= 3) {
        func_800CB23C();
        D_800F18F0 = 3;
        func_8007B410();
        return;
    }
    func_8007B764();
}

void func_8007B834(void)
{
    func_800C97BC();
    if (func_800CB66C()->unk0 != 1) {
        func_8007B470();
        func_800CB114();
        func_8007B764();
    }
}

void func_8007B884(void)
{
    func_800C97BC();
    if (func_800CB66C()->unk0 != 1) {
        if (D_800F1864 != 0) {
            func_8007B470();
        }
        func_800CB114();
        if (D_800F1860 != 0) {
            func_8007B4C4();
        } else {
            func_8007B508();
        }
    }
}

void func_8007B908(void)
{
    if (!(D_800F1868 & 3)) {
        func_8007B63C();
    }
}

void func_8007B938(void)
{
    func_800C97BC();
    if ((func_800CB66C()->unk0 != 1) && (func_800CB45C() == 0)) {
        func_8007B470();
        func_800CB114();
        func_800CB50C();
        func_8007B508();
    }
}

void func_8007B9A0(int arg0, int arg1)
{
    D_800F1860 = 0;
    D_800F1864 = 0;
    func_8007B7DC(arg0, arg1);
}

void func_8007B9CC(void)
{
    D_800F1860 = 0;
    D_800F1864 = 1;
    func_8007B764();
}

int func_8007B9FC(void)
{
    switch (D_800F18F0) {
    case 3:
        func_8007B834();
        return 1;
    case 4:
        func_8007B884();
        return 1;
    case 5:
        func_8007B908();
        return 1;
    case 6:
        func_8007B938();
        return 1;
    default:
        return 0;
    }
}

void func_8007BA98(int arg0, int arg1, int arg2, int arg3)
{
    D_800F1900_t* temp_a0;
    D_800F1900_t* temp_v0;

    temp_v0 = vs_main_allocHeapR(sizeof *temp_v0);
    if (temp_v0 != NULL) {
        vs_main_bzero(temp_v0, sizeof *temp_v0);
        temp_v0->unk8.unk214[0].unk0 = arg0;
        if (arg0 & 0xFFFF) {
            temp_v0->unk8.unk214[0].unk3 = arg1;
            temp_v0->unk8.unk214[0].unk2 = 3;
            temp_v0->unk4 = (int)(temp_v0->unk4 | 1);
        }
        temp_v0->unk8.unk214[1].unk0 = arg2;
        if (arg2 & 0xFFFF) {
            temp_v0->unk8.unk214[1].unk3 = arg3;
            temp_v0->unk8.unk214[1].unk2 = 3;
            temp_v0->unk4 = (int)(temp_v0->unk4 | 1);
        }
        if (temp_v0->unk4 != 0) {
            temp_a0 = D_800F1900;
            temp_v0->unk4 = 0xFF;
            D_800F1900 = temp_v0;
            temp_v0->unk0 = temp_a0;
        } else {
            vs_main_freeHeapR(temp_v0);
        }
    }
    if (D_800F1900 != NULL) {
        D_800F1860 = 1;
        func_800CB158(D_800F1900);
        D_800F18F0 = 4;
        func_8007B410();
        return;
    }
    func_8007B4C4();
}

void func_8007BBB8(int arg0, int arg1) { func_80069DEC(arg0, arg1); }

void func_8007BBD8(int arg0, int arg1, int arg2)
{
    int temp_a0;
    int temp_v1;
    int var_v0;
    int new_var;
    int new_var2;

    D_80050468.unk0 = arg0;
    D_80050468.unk2 = arg1;
    D_80050468.unk7 = 0U;
    D_80050468.unk6 = 0U;
    D_80050468.unk5 = 0U;
    D_80050468.unk4 = 0U;

    if (arg0 != 1) {
        new_var2 = arg2 < 0;
        var_v0 = arg2;
        if (new_var2) {
            var_v0 = 0xFF;
            var_v0 = arg2 + var_v0;
        }
        new_var = 8;
        temp_v1 = var_v0 >> new_var;
        D_80050468.unk4 = (arg2 - (temp_v1 << new_var));

        var_v0 = temp_v1;
        if (temp_v1 < 0) {
            var_v0 = temp_v1 + 0xFF;
        }
        temp_a0 = var_v0 >> new_var;
        D_80050468.unk5 = (temp_v1 - (temp_a0 << new_var));

        var_v0 = temp_a0;
        if (temp_a0 < 0) {
            var_v0 = temp_a0 + 0xFF;
        }
        temp_v1 = var_v0 >> new_var;
        D_80050468.unk6 = (temp_a0 - (temp_v1 << new_var));

        var_v0 = temp_v1;
        if (temp_v1 < 0) {
            var_v0 = temp_v1 + 0xFF;
        }
        D_80050468.unk7 = temp_v1 - ((var_v0 >> new_var) << (temp_a0 = new_var));
    }

    func_800BEC14(0xA0, D_80050468.unk4);
    func_800BEC14(0xA1, D_80050468.unk5);
    func_800BEC14(0xA2, D_80050468.unk6);
    func_800BEC14(0xA3, D_80050468.unk7);
    func_800CB550();
}

void func_8007BCCC(void)
{
    D_80050468.unk0 = 0;
    D_80050468.unk7 = 0;
    D_80050468.unk6 = 0;
    D_80050468.unk5 = 0;
    D_80050468.unk4 = 0;
    func_800BEC14(0xA0, 0);
    func_800BEC14(0xA1, D_80050468.unk5);
    func_800BEC14(0xA2, D_80050468.unk6);
    func_800BEC14(0xA3, D_80050468.unk7);
    func_800CB560();
}

void func_8007BD3C(int arg0)
{
    if (arg0 != 0) {
        int temp_v1 = D_80050468.unk0;
        D_80050468.unk0 = 0;
        D_80050468.unk1 = temp_v1;
        func_800CB560();
        return;
    }
    D_80050468.unk0 = D_80050468.unk1;
    func_800CB550();
}

int func_8007BD8C(int arg0)
{
    if (arg0 != 0) {
        func_800CB654(1);
        func_8008B4C8(0);
    } else {
        func_800CB654(0);
        func_8008B4C8(1);
    }
    return arg0;
}

int func_8007BDD8(int arg0)
{
    func_8008C40C();
    return D_800F186C = ~arg0 & 1;
}

int func_8007BE10(int arg0) { return D_800F18B0 = arg0; }

void func_8007BE20(int arg0, int arg1)
{
    func_800CF0E8_t sp10;
    int i;

    int var_a2 = 0;
    vs_battle_actor** var_a3 = vs_battle_actors;

    sp10.unk2 = 1;
    sp10.unk4 = 5;
    sp10.unk0 = arg0;
    sp10.unk3 = 0;
    sp10.unkC = 0;
    sp10.unkA.s16 = 0;
    sp10.unk8.s16 = 0;
    sp10.unk10 = 4;
    sp10.unk14.u8[0] = arg1;
    sp10.unk16.u8[0] = 0;

    for (i = 0; i < 16; ++i) {
        if ((var_a3[i] != NULL) && (i != arg1)) {
            sp10.unkD0[var_a2] = i;
            ++var_a2;
        }
    }

    sp10.unk3 = var_a2;
    func_800CF0E8(&sp10, 0, 0);
}

void func_8007BEC4(int arg0) { func_800CEF74(arg0); }

void func_8007BEE4(void) { func_800CF48C(); }

void func_8007BF04(void) { }

int func_8007BF0C(void) { return func_800CEEBC() != 0; }

void func_8007BF2C(void) { func_8008AB80(0); }

void func_8007BF4C(void) { func_8008ABB8(0); }

void func_8007BF6C(int arg0)
{
    if (vs_battle_actors[arg0] != NULL) {
        func_800A087C(arg0, func_800A0BE0(arg0) | 1);
    }
}

void func_8007BFC0(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        func_8007BF6C(i);
    }
}

void func_8007BFF8(int arg0)
{
    if (vs_battle_actors[arg0] != NULL) {
        func_800A087C(arg0, func_800A0BE0(arg0) & ~1);
    }
}

void func_8007C050(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        func_8007BFF8(i);
    }
}

int func_8007C088(int arg0) { return vs_battle_actors[arg0]->unk20 & 1; }

void func_8007C0AC(int arg0, int arg1)
{
    if (arg1 == 2) {
        vs_battle_actors[arg0]->unk20 ^= 1;

        if (vs_battle_actors[arg0]->unk20 & 1) {
            func_8009D934(arg0, 1, 0);
        } else {
            func_8009D934(arg0, 0, 0);
        }
    } else if (arg0 != 0) {
        if ((vs_battle_actors[arg0]->unk1C == 4)
            || (vs_battle_actors[arg0]->unk1C == 8)) {
            if (arg1 != 0) {
                vs_battle_actors[arg0]->unk1C = 4;
            } else {
                vs_battle_actors[arg0]->unk1C = 8;
            }
        }
    } else {
        (*vs_battle_actors)->unk20 &= ~1;
        (*vs_battle_actors)->unk20 |= arg1;
        func_8009D934(0, arg1, 1);
    }
    if (arg0 == 0) {
        func_800CB660(vs_battle_characterState->unk20 & 1);
    }
}

void func_8007C1D8(int arg0, int arg1)
{
    if (vs_battle_actors[arg0] != 0) {
        if (arg1 != 0) {
            vs_battle_actors[arg0]->unk1C = 4;
            return;
        }
        vs_battle_actors[arg0]->unk1C = 8;
    }
}

int func_8007C218(int arg0)
{
    int var_v1;
    vs_battle_actor2* temp_a0 = vs_battle_actors[arg0]->unk3C;

    if (temp_a0 != NULL) {
        if (temp_a0->currentHP > 0) {
            var_v1 = (temp_a0->currentHP * 0x64) / temp_a0->maxHP;
            if (var_v1 == 0) {
                var_v1 = 1;
            }
            return var_v1;
        }
    }
    return 0;
}

void func_8007C28C(int arg0)
{
    int i;
    vs_battle_actor2* temp_a1;

    if (vs_battle_actors[arg0] != NULL) {
        temp_a1 = vs_battle_actors[arg0]->unk3C;

        if (temp_a1 != NULL) {
            temp_a1->risk = 0;
            temp_a1->flags.fields.unk0 = 0;
            temp_a1->currentHP = temp_a1->maxHP;
            temp_a1->currentMP = temp_a1->maxMP;
            for (i = 0; i < 6; ++i) {
                temp_a1->hitLocations[i].unk0 = temp_a1->hitLocations[i].unk2;
            }
            func_80086754(0x7FFFFFFF, temp_a1);
            D_800F5160 = 0;
        }
    }
}

void func_8007C31C(void) { func_80086754(0, vs_battle_characterState->unk3C); }

void func_8007C348(int arg0, int arg1) { func_8009F314(arg0, NULL, arg1); }

int func_8007C36C(int arg0)
{
    if ((arg0 == 2) || (arg0 == 4)) {
        vs_gametime_tickspeed = arg0;
    }
    return vs_gametime_tickspeed;
}

int func_8007C398(void)
{
    switch (D_800F1A48) {
    case 1:
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 3;
    case 5:
        return 4;
    case 6:
        return 5;
    case 7:
        return 6;
    case 0:
    default:
        return 0;
    }
}

void func_8007C404(void) { func_80089CE4(); }

void func_8007C424(void) { func_80089D04(); }

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

void func_8007C4D4(void) { D_800F19A0 = 0; }

int func_8007C4E0(D_80061068_t* arg0, int arg1, int arg2)
{
    D_800F1AB0 = *arg0;
    D_800F1A48 = 1;
    D_800F1A98 = arg1;
    D_800F1AA8 = arg2;
    D_800F1AB0.zndId = D_800F1880.zndId;
    func_80089D24(arg0->unk1);
    func_8009E5C4(0);
    func_800A0A1C(0, 1);
    func_8008B8F8(NULL);

    return 1;
}

void func_8007C580(D_80061068_t* arg0, int arg1, int arg2)
{
    func_8006EBF8_t sp10;

    func_8007C4E0(arg0, arg1, arg2);
    func_800A1108(0, &sp10);
    func_8008B960(sp10.unk0.unk0.fields.unk0, sp10.unk0.unk0.fields.unk2,
        sp10.unk0.unk0.fields.unk1);
}

int func_8007C5C0(D_80061068_t* arg0, int arg1, int arg2)
{
    D_800F1AB0 = *arg0;
    D_800F1A48 = 2;
    D_800F1A98 = arg1;
    D_800F1AA8 = arg2;
    _loadZnd(arg0->zndId);
    func_8009E5C4(0);
    func_800A0A1C(0, 1);
    func_8008B8F8(NULL);
    return 1;
}

void func_8007C654(D_80061068_t* arg0, int arg1, int arg2)
{
    func_8006EBF8_t sp10;

    func_8007C5C0(arg0, arg1, arg2);
    func_800A1108(0, &sp10);
    func_8008B960(sp10.unk0.unk0.fields.unk0, sp10.unk0.unk0.fields.unk2,
        sp10.unk0.unk0.fields.unk1);
}

int func_8007C694(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    func_8006EBF8_t sp10;
    int temp_v1_2;
    int var_a0;
    int temp_s1;
    int temp_s2;

    temp_s1 = vs_main_locationZoneMapIds[arg0 * 2];
    temp_s2 = vs_main_locationZoneMapIds[arg0 * 2 + 1];

    D_800F1AB0.unk4_8 = arg1;
    D_800F1AB0.unk6_10 = arg2;
    D_800F1AB0.unk2_13 = 0;

    func_800A1108(0, &sp10);

    temp_v1_2 = sp10.unk0.unkA + 0x200;
    var_a0 = temp_v1_2 - ((temp_v1_2 / ONE) * ONE);
    if (var_a0 < 0) {
        var_a0 += 0x3FF;
    }

    D_800F1A48 = 1;
    D_800F1A98 = arg3;
    D_800F1AA8 = arg4;
    D_800F1AB0.unk4_13 = var_a0 >> 10;
    D_800F1AB0.unk6_15 = 0;

    if (temp_s1 != D_800F1AB0.zndId) {
        D_800F1A48 = 2;
        _loadZnd(temp_s1);
    } else if (temp_s2 != D_800F1AB0.unk1) {
        D_800F1A48 = 1;
        func_80089D24(temp_s2);
    }

    D_800F1AB0.zndId = temp_s1;
    D_800F1AB0.unk1 = temp_s2;
    func_8006C250();
    func_800A0A1C(0, 1);
    func_8008B8F8(NULL);

    return 1;
}

int _getLocationId(int zoneId, int mapId)
{
    int i;

    for (i = 0; i < 512; ++i) {
        if (zoneId == vs_main_locationZoneMapIds[i * 2]
            && mapId == vs_main_locationZoneMapIds[i * 2 + 1]) {
            return i;
        }
    }
    return 0;
}

int vs_battle_getCurrentRoomId(void)
{
    return _getLocationId(D_800F1880.zndId, D_800F1880.mapId);
}

void func_8007C8A4(int arg0)
{
    if ((vs_battle_actors[arg0] != 0) && (arg0 < 16)) {
        func_800AE4FC(vs_battle_actors[arg0]->unk44);
    }
}

int func_8007C8F0(void) { return 0; }

int func_8007C8F8(short arg0)
{
    func_8007C8F8_t sp10;

    sp10.unk2 = arg0;
    sp10.unk0 = 1;
    sp10.unk1 = 0;
    return func_800995E8(&sp10) + 1;
}

int func_8007C928(u_int arg0, int arg1, int* arg2)
{
    int _[6] __attribute__((unused));
    vs_battle_actor_dat* temp_v0;
    vs_battle_actor** temp_s1;
    int s0;

    if (arg0 < 16) {
        if (vs_battle_actors[arg0] == NULL) {
            temp_s1 = &vs_battle_actors[arg0];
            temp_v0 = vs_main_allocHeap(sizeof *temp_v0);
            *temp_s1 = &temp_v0->unk0;
            temp_v0->unk0.unk3C = &temp_v0->unk50;
            temp_v0->unk0.unk40 = 1;
            temp_v0->unk0.unk44 = &temp_v0->unk9B4;
            temp_v0->unk0.unk48[0] = &temp_v0->unk22B4[0];
            temp_v0->unk0.unk48[1] = &temp_v0->unk22B4[1];
            func_80076D50(arg0, arg1, 0, 0, 6);
            s0 = func_80077078(&temp_v0->unk0, arg0, arg1, arg2, 0);
            func_800E6178(*temp_s1, -1);
            return s0 + 1;
        }
    }
    return 0;
}

void func_8007CA20(int arg0, int arg1, int arg2)
{
    vs_battle_actor* temp_s0;

    temp_s0 = vs_battle_actors[arg0];
    if (temp_s0 != NULL) {
        func_80077130(temp_s0, arg0, arg1, 0, 0);
        func_80077130(temp_s0, arg0, arg2, 1, 0);
    }
}

void func_8007CAA4(int arg0)
{
    vs_battle_actor* temp_s1;
    vs_battle_actor2* temp_s0;

    temp_s1 = vs_battle_actors[arg0];
    if (temp_s1 != NULL) {
        temp_s0 = temp_s1->unk3C;
        if (temp_s0 != NULL) {
            if (temp_s0->weapon.blade.id != 0) {
                func_80077130(temp_s1, arg0, temp_s0->weapon.unk108, 0,
                    temp_s0->weapon.blade.material);

            } else {
                func_80077130(temp_s1, arg0, 0, 0, 0);
            }
            if (temp_s0->shield.shield.id != 0) {
                func_80077130(temp_s1, arg0, temp_s0->shield.unkD8, 1,
                    temp_s0->shield.shield.material);
            } else {
                func_80077130(temp_s1, arg0, 0, 0, 0);
            }
        }
    }
}

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

void func_8007CC4C(void) { func_8009D208(); }

void func_8007CC6C(void) { func_8009CE9C(); }

void func_8007CC8C(void) { func_8009CFA0(); }

void func_8007CCAC(void) { func_800995B0(); }

void func_8007CCCC(int arg0)
{
    D_8005E0C8 = arg0;
    func_80098160();
}

void func_8007CCF0(int arg0)
{
    vs_main_projectionDistance = arg0;
    SetGeomScreen(arg0);
}

void func_8007CD14(int arg0, int arg1)
{
    D_1F800000[25] = arg0;

    if (arg1 == 0) {
        if (arg0 < 0) {
            arg0 += 7;
        }
        arg0 >>= 3;
        if (arg0 >= 0x801) {
            arg0 = 0x800;
        } else if (arg0 < 0) {
            arg0 = 0;
        }
        func_80098194(arg0);
    }
}

void func_8007CD70(VECTOR* arg0, VECTOR* arg1, int arg2, int arg3)
{
    func_8006EBF8_t sp10;
    int temp_v0;
    int var_v0;

    if (arg2 != -1) {
        var_v0 = arg2;
        temp_v0 = D_800F19D0.unk0.vx;
        if (arg2 < 0) {
            var_v0 = arg2 + 7;
        }
        D_800F19D0.unk10.vy = (arg2 - ((var_v0 >> 3) * 8)) << 9;
        D_800F19D0.unk0.vx = (arg2 - ((var_v0 >> 3) * 8)) << 9;
    }
    if (arg3 == 1) {
        D_800F19D0.unk20 = 0x600;
        D_800F19D0.unk0.vz = 0x600;
        D_800F19D0.unk10.pad = 0;
    } else if (arg3 == 2) {
        D_800F19D0.unk20 = 0x900;
        D_800F19D0.unk0.vz = 0x900;
        D_800F19D0.unk10.pad = arg3;
    }
    func_800A1108(0, &sp10);
    arg1->vx = sp10.unk0.unk4 << 0xC;
    arg1->vy = (sp10.unk0.unk6 << 0xC) + 0xFFFA6000;
    arg1->vz = sp10.unk0.unk8 << 0xC;
    func_8006D9FC((func_80077DF0_t*)arg1, (func_80077DF0_t*)arg1);
    func_8007A9DC(arg0, arg1, &D_800F19D0.unk0);
}

void func_8007CE74(int arg0)
{
    if ((arg0 == -0x300) || (arg0 == -0x80)) {
        D_800F19D0.unk0.vy = arg0;
        return;
    }
    D_800F19D0.unk0.vy = -0x180;
}

void func_8007CEA0(int arg0) { func_8009E5C4(arg0); }

void func_8007CEC0(void)
{
    int i;
    for (i = 0; i < 16; ++i) {
        if (vs_battle_actors[i] != NULL) {
            func_8007CEA0(i);
        }
    }
}

u_int func_8007CF18(int arg0)
{
    u_int i;

    for (i = 0; i < 16; ++i) {
        if ((vs_battle_actors[i] != 0) && (vs_battle_actors[i]->unk18 == arg0)) {
            return i;
        }
    }
    return 1;
}

vs_battle_actor* func_8007CF64(int arg0) { return vs_battle_actors[arg0]; }

u_int func_8007CF80(int arg0)
{
    u_int i;
    u_int var_a2;

    var_a2 = 0;
    for (i = 0; i < 16; ++i) {
        if ((vs_battle_actors[i] != 0) && (vs_battle_actors[i]->unk1C == arg0)) {
            ++var_a2;
        }
    }
    return var_a2;
}

char func_8007CFCC(int arg0)
{
    if (vs_battle_actors[arg0] != 0) {
        return vs_battle_actors[arg0]->unk26;
    }
    return 0;
}

void func_8007CFF8(int arg0, short* arg1)
{
    func_800A0A1C(arg0, 2);
    func_800E527C(arg0, arg1[0], arg1[2]);
}

int func_8007D03C(int arg0)
{
    int temp_v0 = func_800E5154();
    if (temp_v0 == 0) {
        func_800A0A1C(arg0, func_800A0A74(arg0) & ~2);
        return 1;
    }
    return temp_v0 == 2;
}

int func_8007D08C(int arg0, int arg1)
{
    if (arg1 != 0) {
        if (vs_battle_actors[arg0] != NULL) {
            if (vs_battle_actors[arg0]->unk8 == 0x20) {
                vs_battle_actors[arg0]->unk8 = 0;
                vs_battle_actors[arg0]->unk1C &= 0x7FFF;
            }
        }
    } else {
        if (vs_battle_actors[arg0] != NULL) {
            vs_battle_actors[arg0]->unk8 = 0x20;
            vs_battle_actors[arg0]->unk1C |= 0x8000;
            func_80095B7C(arg0, 0);
            func_80095B7C(arg0, 0x40);
        }
    }
    return arg1;
}

int func_8007D15C(int arg0)
{
    int i;

    for (i = 1; i < 16; ++i) {
        func_8007D08C(i, arg0);
    }
    return arg0;
}

void func_8007D1A8(int arg0, int arg1)
{
    int temp_s0;
    vs_battle_actor* temp_a0 = vs_battle_actors[arg0];
    if (temp_a0 != NULL) {
        if (arg1 != 0) {
            temp_s0 = func_8006A1C4(temp_a0);
            func_800A09D8(arg0, arg1);
            if (temp_s0 != 0) {
                func_800E7608(arg0);
                func_800DEC88(NULL);
            }
        } else {
            temp_s0 = func_8006A11C(temp_a0);
            func_800A09D8(arg0, 0);
            if (temp_s0 != 0) {
                func_800E5998();
                func_800DEC88(NULL);
            }
        }
    }
}

void func_8007D260(int arg0)
{
    vs_battle_actor* temp_a1 = vs_battle_actors[arg0];
    if ((temp_a1 != NULL) && (temp_a1->unk8 != 0x20)) {
        temp_a1->unk8 = 0;
    }
    func_8009DC38(arg0);
}

u_int func_8007D2B4(u_int arg0)
{
    if ((arg0 - 1) < 0xFF) {
        return vs_main_skills[arg0].flags_15;
    }
    return 0;
}

void func_8007D2FC(u_int arg0)
{
    if ((arg0 - 1) < 0xFF) {
        vs_main_skills[arg0].flags_15 = 1;
    }
}

void func_8007D340(int arg0) { func_8006A228(arg0, 0); }

void func_8007D360(void)
{
    D_800F1B98 = 0;
    D_800F1B9C = 0;
    D_800F1A20 = 0;
    D_800F1A28[0] = 0;
    D_800F1A28[1] = 0;
    D_800F1A28[2] = 0;
    D_800F1A30[0] = 0x1000;
    D_800F1A30[1] = 0x1000;
    D_800F1A30[2] = 0;
    D_800F1A78.unk0 = 0x80;
    D_800F1A78.unk1 = 0x80;
    D_800F1A78.unk2 = 0x80;
    D_800F1A9C[0] = 0x80;
    D_800F1A9C[1] = 0x80;
    D_800F1A9C[2] = 0x80;
    D_800F1A68.unk0 = 0;
    D_800F1A68.unk4 = 0;
    D_800F1A68.unk8 = 0;
    D_800F1A44 = 0;
    D_800F1A40 = 0;
}

void func_8007D3F8(void)
{
    D_800F1ABC = NULL;
    func_8007D360();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D41C);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007D734);

void func_8007DD50(int arg0)
{
    if (arg0 != 0) {
        D_800F1B98 = 1;
        if (D_800F1ABC == NULL) {
            D_800F1ABC = vs_main_allocHeapR(0x2D0);
            func_8007D41C();
        }
    } else {
        D_800F1B98 = 3;
    }
}

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

int func_8007DE68(void) { return D_800F1B98; }

short func_8007DE78(void) { return D_800F1A2C; }

void func_8007DE88(int* arg0)
{
    arg0[0] = *D_800F1A30;
    arg0[1] = *D_800F1A30;
    arg0[2] = 0;
}

void func_8007DEA8(D_800F1A78_t* arg0) { *arg0 = D_800F1A78; }

void func_8007DECC(D_800F1A68_t* arg0) { *arg0 = D_800F1A68; }

int func_8007DF00(void) { return D_800F1B9C; }

int func_8007DF10(void) { return D_800F1A20; }

int func_8007DF20(void) { return D_800F1A44; }

int func_8007DF30(void) { return D_800F1A40; }

void func_8007DF40(void) { }

void func_8007DF48(void)
{
    int i;

    for (i = 0; i < 0x20; ++i) {
        D_800F19A8[i] = 0;
    }

    for (i = 0; i < 0x19; ++i) {
        D_800F19A8[i] = 0xFF;
    }

    D_800F18F8 = 0;
}

void func_8007DF98(void)
{
    int i;

    for (i = 0; i < 32; ++i) {
        if (D_800F19A8[i] == 0xFE) {
            D_800F19A8[i] = 0;
        }
        if (D_800F19A8[i] == 0xFD) {
            D_800F19A8[i] = -2;
        }
    }
}

int func_8007DFF0(u_int arg0, u_int arg1, int arg2)
{
    if (arg0 >= 0x19) {
        int var_a3 = 0;
        if ((arg0 + arg1) < 0x21) {
            u_int i;
            for (i = 0; i < arg1; ++i) {
                if (D_800F19A8[arg0 + i] != 0) {
                    var_a3 = 1;
                }
            }
            if (var_a3 == 0) {
                for (i = 0; i < arg1; ++i) {
                    D_800F19A8[arg0 + i] = (char)arg2;
                }
                return arg0;
            }
        }
    }
    vs_main_nop9(0x64, 0);
    return 0;
}

int func_8007E0A8(u_int arg0, u_int arg1, int arg2)
{
    u_int var_s0;
    u_int i;

    var_s0 = 0;
    if ((arg0 >= 0x19) && ((arg0 + arg1) < 0x21)) {

        for (i = 0; i < arg1; ++i) {
            if (D_800F19A8[arg0 + i] != arg2) {
                var_s0 = 1;
            }
        }
        if (var_s0 != 0) {
            vs_main_nop9(0x65, 0);
        } else {
            if (var_s0 < arg1) {
                for (i = 0; i < arg1; ++i) {
                    D_800F19A8[arg0 + i] = -3;
                }
            }
        }
        return !var_s0;
    }
    vs_main_nop9(0x65, 0);
    return 0;
}

int func_8007E180(int arg0)
{
    if (D_800F18F8 == 0) {
        D_800F18F8 = arg0;
        return 1;
    }
    vs_main_nop9(0x66, 0);
    return 0;
}

int func_8007E1C0(int arg0)
{
    if (D_800F18F8 == arg0) {
        D_800F18F8 = 0;
        return 1;
    }
    vs_main_nop9(0x67, 0);
    return 0;
}

void _calculateArmorClassAffinity(vs_battle_actor2* arg0, int arg1)
{
    int i;

    for (i = 0; i < 6; ++i) {
        u_short v = arg0->hitLocations[arg1].armor.armor.classes[i];
        arg0->hitLocations[arg1].armor.classAffinityCurrent.class[1][i] = v;
        arg0->hitLocations[arg1].armor.classAffinityCurrent.class[0][i] = v;
    }

    for (i = 0; i < 7; ++i) {
        u_short v = arg0->hitLocations[arg1].armor.armor.affinities[i];
        arg0->hitLocations[arg1].armor.classAffinityCurrent.affinity[1][i] = v;
        arg0->hitLocations[arg1].armor.classAffinityCurrent.affinity[0][i] =
            v + arg0->hitLocations[arg1].armor.unk88[i];
    }
}

void _calculateShieldClassAffinity(vs_battle_actor2* arg0)
{
    short temp_v0_2;
    int i;

    for (i = 0; i < 6; ++i) {
        temp_v0_2 = arg0->shield.shield.classes[i] + arg0->shield.gems[0].classes[i]
                  + arg0->shield.gems[1].classes[i] + arg0->shield.gems[2].classes[i];
        arg0->shield.classAffinityCurrent.class[1][i] = temp_v0_2;
        arg0->shield.classAffinityCurrent.class[0][i] = temp_v0_2;
    }

    for (i = 0; i < 7; ++i) {
        temp_v0_2 = arg0->shield.shield.affinities[i] + arg0->shield.gems[0].affinities[i]
                  + arg0->shield.gems[1].affinities[i]
                  + arg0->shield.gems[2].affinities[i];
        arg0->shield.classAffinityCurrent.affinity[1][i] = temp_v0_2;
        arg0->shield.classAffinityCurrent.affinity[0][i] =
            temp_v0_2 + arg0->shield.unk134[i];
    }
}

void _calculateWeaponClassAffinity(vs_battle_actor2* arg0)
{
    short temp_v0_2;
    int i;

    for (i = 0; i < 6; ++i) {
        temp_v0_2 = arg0->weapon.blade.classes[i] + arg0->weapon.gems[0].classes[i]
                  + arg0->weapon.gems[1].classes[i] + arg0->weapon.gems[2].classes[i];
        arg0->weapon.classAffinityCurrent.class[1][i] = temp_v0_2;
        arg0->weapon.classAffinityCurrent.class[0][i] = temp_v0_2;
    }

    for (i = 0; i < 7; ++i) {
        temp_v0_2 = arg0->weapon.blade.affinities[i] + arg0->weapon.gems[0].affinities[i]
                  + arg0->weapon.gems[1].affinities[i]
                  + arg0->weapon.gems[2].affinities[i];
        arg0->weapon.classAffinityCurrent.affinity[1][i] = temp_v0_2;
        arg0->weapon.classAffinityCurrent.affinity[0][i] =
            temp_v0_2 + arg0->weapon.unk168[i];
    }
}

extern u_int D_800E8214[];

int func_8007E454(int arg0)
{
    int var_a2;
    int i;

    if (arg0 != 0) {
        for (i = 0; i < 8; ++i) {
            if (arg0 < D_800E8214[i]) {
                break;
            }
        }

        var_a2 = 0;

        if (i < 8) {
            switch (i) {
            case 0:
                for (i = 0; i < 16; ++i) {
                    if (D_80060168.unk280[i].id == arg0) {
                        var_a2 = 1;
                        break;
                    }
                }
                break;
            case 1:
                for (i = 0; i < 16; ++i) {
                    if (D_80060168.unk540[i].id == arg0) {
                        var_a2 = 1;
                        break;
                    }
                }
                break;
            case 2:
                for (i = 0; i < 16; ++i) {
                    if (D_80060168.unk640[i].id == arg0) {
                        var_a2 = 1;
                        break;
                    }
                }
                break;
            case 4:
                for (i = 0; i < 48; ++i) {
                    if (D_80060168.unk8C0[i].id == arg0) {
                        var_a2 = 1;
                        break;
                    }
                }
                break;
            case 5:
            case 6:
            case 7:
                for (i = 0; i < 64; ++i) {
                    if ((D_80060168.unkE00[i].unk0 == arg0)
                        && (D_80060168.unkE00[i].unk2 != 0)) {
                        var_a2 = D_80060168.unkE00[i].unk2;
                        break;
                    }
                }
                break;
            }
        }
        return var_a2;
    }
    return 1;
}

short func_8007E5E0(vs_skill_t* arg0, vs_battle_actor2* arg1)
{
    int var_a0;
    int ret;
    int i;

    var_a0 = 0;
    ret = 0;
    if (vs_battle_actors[arg1->flags.fields.unk3]->unk20 & 1) {
        if (arg0->unk2_1 == 1) {
            var_a0 = 0;
            for (i = 0; i < 3; ++i) {
                if (arg1->weapon.gems[i].gemEffects == 2) {
                    var_a0 = 1;
                }
            }

        } else {
            var_a0 = 0;
            for (i = 0; i < 3; ++i) {
                if (arg1->weapon.gems[i].gemEffects == 1) {
                    var_a0 = 1;
                }
            }
        }
        if (var_a0 != 0) {
            ret = 0x14;
        }
    }
    return ret;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8007E6A0);

int func_8007E974(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
}

int func_8007E97C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    return D_800F1A04 != 0 ? 100 : 255;
}

int func_8007E99C(vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2,
    int arg3, int arg4 __attribute__((unused)))
{
    int var_s0;

    var_s0 = 100;
    if ((arg1 != NULL) && (arg1->unk40 == 0)) {
        var_s0 = func_8007E5E0(arg0, vs_battle_actors[arg1->unk0]->unk3C) + 100;
    }
    if (arg2 != NULL) {
        if (arg2->unk40 == 0) {
            var_s0 -= func_8007E6A0(arg0, vs_battle_actors[arg2->unk0]->unk3C, arg3);
        }
    }
    return var_s0;
}

int func_8007EA74(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    int var_a1;
    int var_s0;
    int var_t0;
    int i;
    vs_battle_actor2* temp_s1;
    vs_battle_actor2* temp_s2;
    int target = arg2->unk1;

    temp_s2 = vs_battle_actors[arg1->unk0]->unk3C;
    temp_s1 = vs_battle_actors[arg2->unk0]->unk3C;
    var_a1 = temp_s2->agility + temp_s2->accessory.currentAgility;
    var_t0 = temp_s1->agility + temp_s1->accessory.currentAgility;

    for (i = 0; i < 6; ++i) {
        var_a1 += temp_s2->hitLocations[i].armor.currentAgility;
        var_t0 += temp_s1->hitLocations[i].armor.currentAgility;
    }

    if (vs_battle_actors[temp_s2->flags.fields.unk3]->unk20 & 1) {
        var_a1 += temp_s2->weapon.currentAgility + temp_s2->shield.currentAgility;
    }

    if (vs_battle_actors[temp_s1->flags.fields.unk3]->unk20 & 1) {
        var_t0 += temp_s1->weapon.currentAgility + temp_s1->shield.currentAgility;
    }

    var_a1 = (var_a1 * (100 - temp_s2->risk)) / 100;
    var_t0 = var_t0 + temp_s1->hitLocations[target].unk4;
    var_t0 = var_t0 * (100 - temp_s1->risk) / 100;
    var_s0 = var_a1 - var_t0;
    var_s0 += 100;

    if (arg4 != 0) {
        int v0 = vs_main_getRandSmoothed(0xB);
        int v1 = var_s0 - 5;
        var_s0 = v1 + v0;
    }

    var_s0 += func_8007E5E0(arg0, temp_s2);
    var_s0 -= func_8007E6A0(arg0, temp_s1, arg3);

    if (var_s0 < 0) {
        var_s0 = 0;
    } else if (var_s0 == 0xFF) {
        var_s0 = 0xFE;
    }

    return var_s0;
}

int func_8007ECA8(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    int var_a1;
    int var_s0;
    int var_t0;
    int i;
    vs_battle_actor2* temp_s1;
    vs_battle_actor2* temp_s2;
    int target = arg2->unk1;

    temp_s2 = vs_battle_actors[arg1->unk0]->unk3C;
    temp_s1 = vs_battle_actors[arg2->unk0]->unk3C;
    var_a1 = temp_s2->intelligence + temp_s2->accessory.currentInt;
    var_t0 = temp_s1->intelligence + temp_s1->accessory.currentInt;

    for (i = 0; i < 6; ++i) {
        var_a1 += temp_s2->hitLocations[i].armor.currentInt;
        var_t0 += temp_s1->hitLocations[i].armor.currentInt;
    }

    if (vs_battle_actors[temp_s2->flags.fields.unk3]->unk20 & 1) {
        var_a1 += temp_s2->weapon.currentInt + temp_s2->shield.currentInt;
    }

    if (vs_battle_actors[temp_s1->flags.fields.unk3]->unk20 & 1) {
        var_t0 += temp_s1->weapon.currentInt + temp_s1->shield.currentInt;
    }

    var_a1 = (var_a1 * (100 - temp_s2->risk)) / 100;
    var_t0 = var_t0 + temp_s1->hitLocations[target].unk4;
    var_t0 = (var_t0 * (100 - temp_s1->risk) / 100);
    var_t0 = var_t0 * temp_s1->currentHP / temp_s1->maxHP;
    var_s0 = var_a1 - var_t0;

    if (arg4 != 0) {
        int v0 = vs_main_getRandSmoothed(0xB);
        int v1 = var_s0 - 5;
        var_s0 = v1 + v0;
    }

    var_s0 += func_8007E5E0(arg0, temp_s2);
    var_s0 -= func_8007E6A0(arg0, temp_s1, arg3);

    if (var_s0 < 0) {
        var_s0 = 0;
    } else if (var_s0 == 0xFF) {
        var_s0 = 0xFE;
    }

    return var_s0;
}

int func_8007EEFC(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    int var_a1;
    int var_s0;
    int var_t0;
    int i;
    int v;
    vs_battle_actor2* temp_s1;
    vs_battle_actor2* temp_s2;
    int target = arg2->unk1;

    temp_s2 = vs_battle_actors[arg1->unk0]->unk3C;
    temp_s1 = vs_battle_actors[arg2->unk0]->unk3C;
    var_a1 = temp_s2->agility + temp_s2->accessory.currentAgility;
    var_t0 = temp_s1->agility + temp_s1->accessory.currentAgility;

    for (i = 0; i < 6; ++i) {
        var_a1 += temp_s2->hitLocations[i].armor.currentAgility;
        var_t0 += temp_s1->hitLocations[i].armor.currentAgility;
    }

    if (vs_battle_actors[temp_s2->flags.fields.unk3]->unk20 & 1) {
        var_a1 += temp_s2->weapon.currentAgility + temp_s2->shield.currentAgility;
    }

    if (vs_battle_actors[temp_s1->flags.fields.unk3]->unk20 & 1) {
        var_t0 += temp_s1->weapon.currentAgility + temp_s1->shield.currentAgility;
    }

    var_a1 = (var_a1 * (100 - temp_s2->risk)) / 100;
    var_t0 = var_t0 + temp_s1->hitLocations[target].unk4;
    var_t0 = var_t0 * (100 - temp_s1->risk) / 100;
    var_s0 = var_a1 - var_t0;
    v = var_s0 + 130;
    var_s0 = v - arg0->unk3;

    if (arg4 != 0) {
        int v0 = vs_main_getRandSmoothed(0xB);
        int v1 = var_s0 - 5;
        var_s0 = v1 + v0;
    }

    var_s0 += func_8007E5E0(arg0, temp_s2);
    var_s0 -= func_8007E6A0(arg0, temp_s1, arg3);

    if (var_s0 < 0) {
        var_s0 = 0;
    } else if (var_s0 == 0xFF) {
        var_s0 = 0xFE;
    }

    return var_s0;
}

int _getSpellHitRate(vs_skill_t* arg0 __attribute__((unused)), func_80085718_t* arg1,
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    int temp_v0 = (vs_battle_actors[arg1->unk0]->unk3C->risk + 150) * 100;
    int var_v1 = temp_v0 >> 8;
    if (temp_v0 < 0) {
        var_v1 = (temp_v0 + 255) >> 8;
    }
    if (var_v1 == 255) {
        var_v1 = 254;
    }
    return var_v1;
}

int func_8007F1A4(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int var_v0;

    var_v0 =
        ((255 - vs_battle_actors[arg2->unk0]->unk3C->hitLocations[arg2->unk1].unk7) * 100)
        / 255;
    if (var_v0 == 255) {
        var_v0 = 254;
    }
    return var_v0;
}

int func_8007F230(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    int temp_v1;
    int var_s0;

    if ((arg2->unk40 == 0)
        && (vs_battle_actors[arg2->unk0]->unk3C->flags.fields.unk3 == 0x80)) {
        var_s0 = 100;
    } else {
        var_s0 = D_800E8234[arg0->hitParams[arg3].unk0_E](arg0, arg1, arg2, arg3, arg4);
        if ((arg0->unk2_1 == 1) && (vs_battle_actors[arg2->unk0]->unk3C->unk948 < 0)) {
            var_s0 = 0;
        }
    }
    if (D_800F1A00 == 0) {
        var_s0 = 0xFF;
    }
    if (var_s0 != 0xFF) {
        if (arg2->unk40 == 0) {
            if (vs_battle_actors[arg2->unk0]->unk3C->unk948 & 4) {
                var_s0 *= 2;
            }
        }
        if (var_s0 > 100) {
            var_s0 = 100;
        }
    }
    if ((arg3 == 0) || (arg2->unk2 == 0xFF)) {
        arg2->unk2 = var_s0;
    }
    temp_v1 = vs_main_getRand(100);
    if (var_s0 != 0xFF) {
        if ((arg1->unk40 == 0) && (arg1->unk0 == 0)) {
            var_s0 += 10;
        }
        return temp_v1 < var_s0;
    }
    return 0;
}

int func_8007F434(void)
{
    int temp_v0 = (vs_battle_characterState->unk3C->risk + 150) * 100;
    int var_s0 = temp_v0 >> 8;
    if (temp_v0 < 0) {
        var_s0 = (temp_v0 + 255) >> 8;
    }
    if (var_s0 > 100) {
        var_s0 = 100;
    }
    return vs_main_getRand(100) < (var_s0 + 20);
}

int func_8007F4B0(int arg0, u_char* arg1)
{
    int* temp_a0 = D_8004EECC[arg0];
    vs_battle_actor2* temp_a1 = vs_battle_actors[*arg1]->unk3C;

    if ((!(temp_a0[0] & temp_a1->unk944)) && (!(temp_a0[3] & temp_a1->unk948))) {
        return 0;
    }
    return 1;
}

int func_8007F518(u_char* arg0) { return vs_battle_actors[*arg0]->unk3C->unk37_0; }

int func_8007F548(
    vs_skill_t* arg0 __attribute__((unused)), char* arg1 __attribute__((unused)))
{
    return 0;
}

int func_8007F550(
    vs_skill_t* arg0 __attribute__((unused)), char* arg1 __attribute__((unused)))
{
    return 1;
}

int func_8007F558(
    vs_skill_t* arg0 __attribute__((unused)), char* arg1 __attribute__((unused)))
{
    return 1;
}

int func_8007F560(
    vs_skill_t* arg0 __attribute__((unused)), char* arg1 __attribute__((unused)))
{
    return 1;
}

int func_8007F568(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F518(arg1) == 2;
}

int func_8007F58C(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F518(arg1) != 2;
}

int func_8007F5B0(
    vs_skill_t* arg0 __attribute__((unused)), char* arg1 __attribute__((unused)))
{
    return 0;
}

int func_8007F5B8(
    vs_skill_t* arg0 __attribute__((unused)), char* arg1 __attribute__((unused)))
{
    return 0;
}

int func_8007F5C0(
    vs_skill_t* arg0 __attribute__((unused)), char* arg1 __attribute__((unused)))
{
    return 0;
}

int func_8007F5C8(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(5, arg1) == 0;
}

int func_8007F5E8(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(7, arg1) == 0;
}

int func_8007F608(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(9, arg1) == 0;
}

int func_8007F628(vs_skill_t* arg0, u_char* arg1)
{
    int i;
    int var_a1;
    vs_battle_actor2* temp_a2;

    if (func_8007F4B0(0x13, arg1) != 0) {
        return 0;
    }
    var_a1 = 0;
    temp_a2 = vs_battle_actors[*arg1]->unk3C;

    for (i = 0; i < 6; ++i) {
        if (temp_a2->hitLocations[i].armor.armor.id != 0) {
            var_a1 = 1;
        }
    }

    if (temp_a2->shield.shield.id != 0) {
        var_a1 = 1;
    }
    if (temp_a2->weapon.blade.id != 0) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        i = 1;
        return 1;
    }
    return 0;
}

int func_8007F6D8(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(4, arg1) == 0;
}

int func_8007F6F8(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(6, arg1) == 0;
}

int func_8007F718(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(8, arg1) == 0;
}

int func_8007F738(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(0xA, arg1) == 0;
}

int func_8007F758(vs_skill_t* arg0, u_char* arg1)
{
    int i;
    int var_a1;
    vs_battle_actor2* temp_a2;

    if (func_8007F4B0(0x14, arg1) != 0) {
        return 0;
    }
    var_a1 = 0;
    temp_a2 = vs_battle_actors[*arg1]->unk3C;

    for (i = 0; i < 6; ++i) {
        if (temp_a2->hitLocations[i].armor.armor.id != 0) {
            var_a1 = 1;
        }
    }

    if (temp_a2->shield.shield.id != 0) {
        var_a1 = 1;
    }
    if (temp_a2->weapon.blade.id != 0) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        i = 1;
        return 1;
    }
    return 0;
}

int func_8007F808(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(0xB, arg1) == 0;
}

int func_8007F828(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(0xC, arg1) == 0;
}

int func_8007F848(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(0x12, arg1) == 0;
}

int func_8007F868(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(0x11, arg1) == 0;
}

int func_8007F888(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(0xD, arg1) == 0;
}

int func_8007F8A8(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(0xE, arg1) == 0;
}

int func_8007F8C8(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(0xF, arg1) == 0;
}

int func_8007F8E8(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(0x10, arg1) == 0;
}

int func_8007F908(vs_skill_t* arg0 __attribute__((unused)), u_char* arg1)
{
    if ((func_8007F4B0(0x15, arg1) == 0)
        && (vs_battle_actors[*arg1]->unk3C->weapon.blade.id != 0)) {
        return 1;
    }
    return 0;
}

int func_8007F96C(vs_skill_t* arg0 __attribute__((unused)), u_char* arg1)
{
    if ((func_8007F4B0(0x16, arg1) == 0)
        && (vs_battle_actors[*arg1]->unk3C->weapon.blade.id != 0)) {
        return 1;
    }
    return 0;
}

int func_8007F9D0(vs_skill_t* arg0 __attribute__((unused)), u_char* arg1)
{
    if ((func_8007F4B0(0x17, arg1) == 0)
        && (vs_battle_actors[*arg1]->unk3C->weapon.blade.id != 0)) {
        return 1;
    }
    return 0;
}

int func_8007FA34(int arg0 __attribute__((unused)), u_char* arg1)
{
    if ((func_8007F4B0(0x18, arg1) == 0)
        && (vs_battle_actors[*arg1]->unk3C->weapon.blade.id != 0)) {
        return 1;
    }
    return 0;
}

int func_8007FA98(vs_skill_t* arg0 __attribute__((unused)), u_char* arg1)
{
    if (func_8007F4B0(0x19, arg1) == 0) {
        int i;
        int var_a1 = 0;
        vs_battle_actor2* temp_a2 = vs_battle_actors[*arg1]->unk3C;

        for (i = 0; i < 6; ++i) {
            if (temp_a2->hitLocations[i].armor.armor.id != 0) {
                var_a1 = 1;
            }
        }

        if (temp_a2->shield.shield.id != 0) {
            var_a1 = 1;
        }
        if (var_a1 != 0) {
            return 1;
        }
    }
    return 0;
}

int func_8007FB34(vs_skill_t* arg0 __attribute__((unused)), u_char* arg1)
{
    if (func_8007F4B0(0x1A, arg1) == 0) {
        int i;
        int var_a1 = 0;
        vs_battle_actor2* temp_a2 = vs_battle_actors[*arg1]->unk3C;

        for (i = 0; i < 6; ++i) {
            if (temp_a2->hitLocations[i].armor.armor.id != 0) {
                var_a1 = 1;
            }
        }

        if (temp_a2->shield.shield.id != 0) {
            var_a1 = 1;
        }
        if (var_a1 != 0) {
            return 1;
        }
    }
    return 0;
}

int func_8007FBD0(vs_skill_t* arg0 __attribute__((unused)), u_char* arg1)
{
    if (func_8007F4B0(0x1B, arg1) == 0) {
        int i;
        int var_a1 = 0;
        vs_battle_actor2* temp_a2 = vs_battle_actors[*arg1]->unk3C;

        for (i = 0; i < 6; ++i) {
            if (temp_a2->hitLocations[i].armor.armor.id != 0) {
                var_a1 = 1;
            }
        }

        if (temp_a2->shield.shield.id != 0) {
            var_a1 = 1;
        }
        if (var_a1 != 0) {
            return 1;
        }
    }
    return 0;
}

int func_8007FC6C(vs_skill_t* arg0 __attribute__((unused)), u_char* arg1)
{
    if (func_8007F4B0(0x1C, arg1) == 0) {
        int i;
        int var_a1 = 0;
        vs_battle_actor2* temp_a2 = vs_battle_actors[*arg1]->unk3C;

        for (i = 0; i < 6; ++i) {
            if (temp_a2->hitLocations[i].armor.armor.id != 0) {
                var_a1 = 1;
            }
        }

        if (temp_a2->shield.shield.id != 0) {
            var_a1 = 1;
        }
        if (var_a1 != 0) {
            return 1;
        }
    }
    return 0;
}

int func_8007FD08(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    return func_8007F4B0(0x1D, arg1) == 0;
}

int func_8007FD28(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    if ((func_8007F4B0(0x1E, arg1) == 0) && ((func_8007F518(arg1) == 2))) {
        return 1;
    }
    return 0;
}

int func_8007FD74(vs_skill_t* arg0 __attribute__((unused)), char* arg1)
{
    if ((func_8007F4B0(0x1E, arg1) == 0) && (func_8007F518(arg1)) != 2) {
        return 1;
    }
    return 0;
}

void func_8007FDC0(vs_skill_t* arg0 __attribute__((unused)), char* arg1) { }

void func_8007FDC8(vs_skill_t* arg0 __attribute__((unused)), char* arg1) { }

void func_8007FDD0(vs_skill_t* arg0 __attribute__((unused)), char* arg1) { }

int func_8007FDD8(vs_skill_t* arg0, char* arg1, int arg2)
{
    if (arg2 != 0) {
        if ((arg0->hitParams[arg2].unk0_7 == 1) && (arg1[3] == 4)) {
            return 0;
        }
    }
    return D_800E8254[arg0->hitParams[arg2].unk0_7](arg0, arg1);
}

short func_8007FE5C(
    vs_skill_t* arg0, short arg1, vs_battle_actor2* arg2, vs_battle_actor2* arg3)
{
    int var_a0;
    int var_t0;
    int i;

    var_t0 = 100;

    if (arg0->unk2_1 == 1) {
        var_a0 = 0;

        for (i = 0; i < 3; ++i) {
            if (arg2->weapon.gems[i].gemEffects == 4) {
                var_a0 = 1;
            }
        }

        if (var_a0 != 0) {
            var_t0 += 5;
        }

        var_a0 = 0;

        for (i = 0; i < 3; ++i) {
            if (arg3->shield.gems[i].gemEffects == 8) {
                var_a0 = 1;
            }
        }

    } else {

        var_a0 = 0;

        for (i = 0; i < 3; ++i) {
            if (arg2->weapon.gems[i].gemEffects == 3) {
                var_a0 = 1;
            }
        }

        if (var_a0 != 0) {
            var_t0 += 5;
        }

        var_a0 = 0;

        for (i = 0; i < 3; ++i) {
            if (arg3->shield.gems[i].gemEffects == 7) {
                var_a0 = 1;
            }
        }
    }
    if (var_a0 != 0) {
        var_t0 -= 5;
    }
    return (arg1 * var_t0) / 100;
}

short func_8007FF8C(int arg0, short arg1, char* arg2)
{
    int i;
    int var_t0 = 100;
    int var_a3 = 0;

    for (i = 0; i < 3; ++i) {
        if (arg2[i * 0x30 + 0xCA] == 9) {
            var_a3 = 1;
        }
    }

    if (var_a3 != 0) {
        var_t0 += 5;
    }
    return (arg1 * var_t0) / 100;
}

void func_80080000(vs_skill_t* arg0, func_80085718_t* arg1, short arg2)
{
    int i;
    int var_t0;
    vs_battle_actor2* temp_t2;

    for (i = 0; i < 6; ++i) {
        D_800F1A10[i] = 0;
    }

    temp_t2 = vs_battle_actors[arg1->unk0]->unk3C;

    switch (arg0->unk2_4) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        var_t0 = 0;

        for (i = 0; i < 6; ++i) {
            if (temp_t2->hitLocations[i].unk2 != 0) {
                ++var_t0;
            }
        }

        for (i = 0; i < 6; ++i) {
            if (temp_t2->hitLocations[i].unk2 != 0) {
                D_800F1A10[i] = arg2 / var_t0;
                arg1->unk20.s16[i][0] = arg1->unk20.s16[i][0] + D_800F1A10[i];
            }
        }
        break;
    case 5:
    case 7:
    case 14:
        for (i = 0; i < 6; ++i) {
            D_800F1A10[i] = (arg2 * temp_t2->unk920[arg1->unk1][i]) / 100;
            arg1->unk20.s16[i][0] += D_800F1A10[i];
        }
        break;
    case 6:
    case 8:
    case 11:
    case 12:
        D_800F1A10[arg1->unk1] = arg2;
        arg1->unk20.s16[arg1->unk1][0] += arg2;
        break;
    }
}

void func_800801E0(vs_skill_t* arg0, func_80085718_t* arg1, short arg2)
{
    int temp_lo;
    int i;
    int var_t0;
    vs_battle_actor2* temp_t1;

    var_t0 = 0;
    temp_t1 = vs_battle_actors[arg1->unk0]->unk3C;

    for (i = 0; i < 6; ++i) {
        if (temp_t1->hitLocations[i].unk2 != 0) {
            var_t0 += temp_t1->hitLocations[i].unk2 - temp_t1->hitLocations[i].unk0;
        }
    }

    if (var_t0 != 0) {
        for (i = 0; i < 6; ++i) {
            if (temp_t1->hitLocations[i].unk2 != 0) {
                temp_lo =
                    (arg2
                        * (temp_t1->hitLocations[i].unk2 - temp_t1->hitLocations[i].unk0))
                    / var_t0;
                D_800F1A10[i] = temp_lo;
                arg1->unk20.s16[i][0] =
                    arg1->unk20.s16[i][0] + ((temp_lo << 0x10) >> 0xF);
            }
        }
    }
}

void func_800802C4(
    vs_skill_t* arg0, vs_battle_actor2* arg1, vs_battle_actor2* arg2, int arg3)
{
    int i;

    if (arg0->unk2_1 != 1) {
        if (arg1->weapon.currentDp >= arg3) {
            arg1->weapon.currentDp -= arg3;
        } else {
            arg1->weapon.currentDp = 0;
        }
    }
    if (vs_battle_actors[arg2->flags.fields.unk3]->unk20 & 1) {
        if (arg2->shield.currentPp >= arg3) {
            arg2->shield.currentPp -= arg3;
        } else {
            arg2->shield.currentPp = 0;
        }
    }

    for (i = 0; i < 6; ++i) {
        if (D_800F1A10[i] != 0) {
            if (arg2->hitLocations[i].armor.currentDp >= D_800F1A10[i]) {
                arg2->hitLocations[i].armor.currentDp -= D_800F1A10[i];
            } else {
                arg2->hitLocations[i].armor.currentDp = 0;
            }
        }
    }
}

void func_800803A4(
    vs_skill_t* arg0, vs_battle_actor2* arg1, vs_battle_actor2* arg2, int arg3)
{
    int var_t0;
    int var_t1;
    int i;

    var_t1 = 100;

    if (arg0->unk2_1 != 1) {
        var_t0 = 0;

        for (i = 0; i < 3; ++i) {
            if (arg1->weapon.gems[i].gemEffects == 9) {
                var_t0 = 1;
            }
        }

        if (var_t0 != 0) {
            var_t1 += 5;
        }

        var_t1 = (((arg3 / 10) * var_t1) / 100);
        if (arg1->weapon.currentPp + var_t1 < arg1->weapon.maxPp) {
            arg1->weapon.currentPp = arg1->weapon.currentPp + var_t1;
        } else {
            arg1->weapon.currentPp = arg1->weapon.maxPp;
        }
    }

    var_t1 = 100;

    if (vs_battle_actors[arg2->flags.fields.unk3]->unk20 & 1) {
        var_t0 = 0;
        for (i = 0; i < 3; ++i) {
            if (arg2->shield.gems[i].gemEffects == 9) {
                var_t0 = 1;
            }
        }
        if (var_t0 != 0) {
            var_t1 -= 5;
        }

        var_t1 = (((arg3 / 10) * var_t1) / 100);
        if (arg2->shield.currentDp + var_t1 < arg2->shield.maxDp != 0) {
            arg2->shield.currentDp = arg2->shield.currentDp + var_t1;
        } else {
            arg2->shield.currentDp = arg2->shield.maxDp;
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80080534);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800807E8);

void func_80080A9C(
    vs_skill_t* arg0, vs_battle_equipment* arg1, int arg2, int arg3, int arg4)
{
    int var_s1;
    int var_s2;
    int a2 = arg2;

    switch (arg2) {
    case 0:
        var_s1 = 1;
        var_s2 = 2;
        break;
    case 1:
        var_s1 = 2;
        var_s2 = 3;
        break;
    case 2:
        var_s1 = 3;
        var_s2 = 4;
        break;
    case 3:
        var_s1 = 4;
        var_s2 = 5;
        break;
    case 4:
        var_s1 = 5;
        var_s2 = 0;
        break;
    case 5:
        var_s1 = 0;
        var_s2 = 1;
        break;
    }

    if (arg1->classes[a2] < 100) {
        int temp_a2 = vs_main_getRand(256);
        if ((70 - (arg1->classes[a2] + 100) / 4) >= temp_a2) {
            ++arg1->classes[a2];
            if (arg4 == 0) {
                func_80096768(arg3, a2, 1);
            }
            if (arg1->classes[var_s1] >= -99) {
                int temp_a2 = vs_main_getRand(256);
                if (((arg1->classes[var_s1] + 100) / 4 + 20) >= temp_a2) {
                    --arg1->classes[var_s1];
                    if (arg4 == 0) {
                        func_80096768(arg3, var_s1, 0x80000001);
                    }
                }
            }
            if (arg1->classes[var_s2] >= -99) {
                int temp_a2 = vs_main_getRand(256);
                if (((arg1->classes[var_s2] + 100) / 4 + 20) >= temp_a2) {
                    --arg1->classes[var_s2];
                    if (arg4 == 0) {
                        func_80096768(arg3, var_s2, 0x80000001);
                    }
                }
            }
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80080C9C);

void func_80080F78(vs_skill_t* arg0, vs_battle_actor2* arg1, int arg2, int arg3)
{
    if (arg0->unk2_1 != 1) {
        vs_battle_equipment* temp_s1 = &arg1->weapon.blade;
        if (arg1->weapon.blade.id != 0) {
            if (arg2 != 0) {
                func_80080A9C(arg0, temp_s1, arg2 - 1, 0xF0, arg1->flags.fields.unk3);
            }
            if (arg3 != 0) {
                func_80080534(arg0, temp_s1, arg3 - 1, 0xF0, arg1->flags.fields.unk3);
            }
        }
        _calculateWeaponClassAffinity(arg1);
    }
}

int func_80081020(int arg0, func_80085718_t* arg1)
{
    int temp_t0;
    int var_a3;
    int var_t1;
    int* temp_a1;
    vs_battle_actor2* temp_a2;

    var_a3 = 0;
    var_t1 = 0;
    temp_a1 = D_8004EECC[arg0];
    temp_a2 = vs_battle_actors[arg1->unk0]->unk3C;

    if (temp_a2->flags.fields.unk3 != 0x80) {
        temp_t0 = temp_a2->unk948;
        if (!(temp_t0 & temp_a1[3])) {
            var_t1 = temp_a1[0] & ~temp_a2->unk944 & (~temp_t0 | temp_a1[2]);
            arg1->unk14 |= var_t1;
            var_a3 = temp_a1[2] & temp_a2->unk948;
            arg1->unk18 |= var_a3;
        }
    }
    return var_t1 | var_a3;
}

int func_800810CC(int arg0, func_80085718_t* arg1)
{
    int ret = 0;
    int* new_var = D_8004EECC[arg0];
    if (vs_battle_actors[arg1->unk0]->unk3C->flags.fields.unk3 != 0x80) {
        ret = new_var[0] & vs_battle_actors[arg1->unk0]->unk3C->unk948;
        arg1->unk18 |= ret;
    }
    return ret;
}

void func_80081130(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
}

short func_80081138(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    return D_800F1A08;
}

short func_80081148(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)), int arg5);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80081148);

short func_800819D0(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    return func_80081148(arg0, arg1, arg2, arg3, arg4, 0);
}

short func_800819FC(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)));
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800819FC);

short func_80082144(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    int v = (D_800F19CC->unk8.unk4C.unk.unk4 + D_800F19CC->unk8.unk4C.unk.unk6)
          * arg0->hitParams[arg3].damage;
    return (v / 10) + (D_800F19CC->unk0 - 1);
}

short func_800821B0(vs_skill_t* arg0, func_80085718_t* arg1,
    func_80085718_t* arg2 __attribute__((unused)), int arg3,
    int arg4 __attribute__((unused)))
{
    vs_battle_actor2* temp_v0 = vs_battle_actors[arg1->unk0]->unk3C;
    int v = (temp_v0->maxHP - temp_v0->currentHP) * arg0->hitParams[arg3].damage;
    return (v / 10) + (D_800F19CC->unk0 - 1);
}

short func_80082234(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3,
    int arg4 __attribute__((unused)))
{
    int v = (D_800F19CC->unk8.unk4C.unk.unk4 + D_800F19CC->unk8.unk4C.unk.unk6)
          * arg0->hitParams[arg3].damage;
    return (v / 10) + (D_800F19CC->unk0 - 1);
}

short func_800822A0(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3,
    int arg4 __attribute__((unused)))
{
    int v = vs_battle_actors[arg2->unk0]->unk3C->currentHP * arg0->hitParams[arg3].damage;
    return (v / 100) + (D_800F19CC->unk0 - 1);
}

short func_8008231C(vs_skill_t* arg0 __attribute__((unused)), func_80085718_t* arg1,
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    return vs_battle_actors[arg1->unk0]->unk3C->weapon.currentPp
         + ((u_short)D_800F19CC->unk0 - 1);
}

short func_80082360(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3,
    int arg4 __attribute__((unused)))
{
    short var_a2 = 0;
    if (((vs_main_skills[D_800F19CC->unk8.unk0].unk2_1)) == 1) {
        if (((D_800F19CC->unk8.unk20 & 3) == 1) || ((D_800F19CC->unk8.unk20 & 3) == 3)) {
            var_a2 = ((D_800F19CC->unk8.unk8 + D_800F19CC->unk8.unkA)
                         * arg0->hitParams[arg3].damage)
                   / 10;
        }
    }
    return var_a2;
}

short func_8008241C(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3,
    int arg4 __attribute__((unused)))
{
    short var_a2 = 0;
    if (((vs_main_skills[D_800F19CC->unk8.unk0].unk2_1)) != 1) {
        if (((D_800F19CC->unk8.unk20 & 3) == 1) || ((D_800F19CC->unk8.unk20 & 3) == 3)) {
            var_a2 = ((D_800F19CC->unk8.unk8 + D_800F19CC->unk8.unkA)
                         * arg0->hitParams[arg3].damage)
                   / 10;
        }
    }
    return var_a2;
}

short func_800824D8(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    vs_battle_actor2* temp_v0 = vs_battle_actors[arg1->unk0]->unk3C;
    return (temp_v0->maxMP - temp_v0->currentMP) * arg0->hitParams[arg3].damage / 10
         + (D_800F19CC->unk0 - 1);
}

short func_8008255C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)));
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008255C);

short func_800829B8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)));
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800829B8);

short func_80082FF4(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)));
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80082FF4);

short func_80083430(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3, int arg4)
{
    short temp_s0;
    short temp_v0;

    temp_s0 = arg0->hitParams[arg3].damage * 5;
    if (arg4 != 0) {
        temp_v0 = vs_main_getRandSmoothed(0xB) - 5;
    } else {
        temp_v0 = 0;
    }
    temp_s0 = temp_s0 + temp_v0;

    if (temp_s0 < 0) {
        temp_s0 = 0;
    }
    return temp_s0;
}

short func_800834A4(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    return vs_battle_actors[arg2->unk0]->unk3C->maxHP
         - vs_battle_actors[arg2->unk0]->unk3C->currentHP;
}

short func_800834E4(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    return vs_battle_actors[arg2->unk0]->unk3C->maxMP
         - vs_battle_actors[arg2->unk0]->unk3C->currentMP;
}

short func_80083524(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3,
    int arg4 __attribute__((unused)))
{
    return (((D_800F19CC->unk8.unk4C.unk.unk4 + D_800F19CC->unk8.unk4C.unk.unk6)
                * arg0->hitParams[arg3].damage)
               / 10)
         + (D_800F19CC->unk0 - 1);
}

short func_80083590(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3,
    int arg4 __attribute__((unused)))
{
    short var_a2 = 0;
    if (vs_main_skills[D_800F19CC->unk8.unk0].unk2_1 == 1) {
        if (((D_800F19CC->unk8.unk20 & 3) == vs_main_skills[D_800F19CC->unk8.unk0].unk2_1)
            || ((D_800F19CC->unk8.unk20 & 3) == 3)) {
            var_a2 = ((D_800F19CC->unk8.unk8 + D_800F19CC->unk8.unkA)
                         * arg0->hitParams[arg3].damage)
                   / 10;
        }
    }
    return var_a2;
}

short func_8008364C(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3,
    int arg4 __attribute__((unused)))
{
    short var_a2 = 0;
    if (((vs_main_skills[D_800F19CC->unk8.unk0].unk2_1)) != 1) {
        if (((D_800F19CC->unk8.unk20 & 3) == 1) || ((D_800F19CC->unk8.unk20 & 3) == 3)) {
            var_a2 = ((D_800F19CC->unk8.unk8 + D_800F19CC->unk8.unkA)
                         * arg0->hitParams[arg3].damage)
                   / 10;
        }
    }
    return var_a2;
}

short func_80083708(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short var_v0;

    if (vs_main_skills[D_800F19CC->unk8.unk0].unk2_1 == 1) {
        var_v0 =
            (vs_main_skills[D_800F19CC->unk8.unk0].unk3 * arg0->hitParams[arg3].damage)
            / 10;
    } else {
        var_v0 = 0;
    }
    return var_v0;
}

short func_8008379C(vs_skill_t* arg0, func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3,
    int arg4 __attribute__((unused)))
{
    short var_a2 = 0;
    if (((D_800F19CC->unk8.unk20 & 3) == 1) || ((D_800F19CC->unk8.unk20 & 3) == 3)) {
        var_a2 = ((D_800F19CC->unk8.unk8 + D_800F19CC->unk8.unkA)
                     * arg0->hitParams[arg3].damage)
               / 10;
    }
    return var_a2;
}

short vs_battle_getEquippedShieldDp(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1, func_80085718_t* arg2 __attribute__((unused)),
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    return vs_battle_actors[arg1->unk0]->unk3C->shield.currentDp;
}

short func_8008384C(vs_skill_t* arg0 __attribute__((unused)), func_80085718_t* arg1,
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    return (D_800F1A08 * arg0->hitParams[arg3].damage) / 10;
}

short func_8008388C(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    return func_80081148(arg0, arg1, arg2, arg3, arg4, 1);
}

short _getRisk(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    return vs_battle_actors[arg2->unk0]->unk3C->risk;
}

short func_800838EC(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short var_v0;

    if ((arg2->unk40 == 0)
        && (vs_battle_actors[arg2->unk0]->unk3C->flags.fields.unk3 == 0x80)) {
        var_v0 = 999;
    } else {
        var_v0 = D_800E830C[arg0->hitParams[arg3].unk0_10](arg0, arg1, arg2, arg3, arg4);
    }
    D_800F1A08 = var_v0;
    return var_v0;
}

int func_80083990(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
}

// TODO: Change return type, these only match with int and undefined return
int func_80083998(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(5, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_800839E8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(7, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083A38(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(9, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083A88(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(19, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083AD8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(4, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083B28(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(6, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80083B78(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(8, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80083BC8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(10, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80083C18(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(20, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80083C68(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(11, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80083CB8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(12, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083D08(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    func_80081020(0x12, arg2);
}

int func_80083D2C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(17, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80083D7C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4)
{
    func_80081020(0x1D, arg2);
    if (arg4 != 0) {
        vs_battle_actors[arg2->unk0]->unk3C->flags.u32 |= 0x20000;
    }
}

int func_80083DEC(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(13, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083E3C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(14, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083E8C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(15, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083EDC(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_80081020(16, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 1;
    }
}

int func_80083F2C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x15, arg2);
}

int func_80083F50(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x16, arg2);
}

int func_80083F74(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x17, arg2);
}

int func_80083F98(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x18, arg2);
}

int func_80083FBC(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x19, arg2);
}

int func_80083FE0(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x1A, arg2);
}

int func_80084004(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x1B, arg2);
}

int func_80084028(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_80081020(0x1C, arg2);
}

int func_8008404C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_800810CC(0xD, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_8008409C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_800810CC(0xE, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_800840EC(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_800810CC(0x10, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_8008413C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    if (func_800810CC(0xF, arg2) != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_8008418C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    arg2->unk18 |= (vs_battle_actors[arg2->unk0]->unk3C->unk948 & 0x1FFE1FE0);
}

int func_800841C8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v1 = vs_battle_actors[arg2->unk0]->unk3C->unk948 & 0xE000;
    arg2->unk18 = arg2->unk18 | temp_v1;
    if (temp_v1 != 0) {
        arg2->unk1C.fields.unk1E_0 = 2;
    }
}

int func_80084228(vs_skill_t* arg0 __attribute__((unused)), func_80085718_t* arg1,
    func_80085718_t* arg2, int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    arg1->unk1C.fields.unk1F_2 = 2;
}

int func_80084248(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    func_800810CC(0x1E, arg2);
    arg2->unk4 = vs_battle_actors[arg2->unk0]->unk3C->currentHP;
    arg2->unk1C.fields.unk1C_0 = 1;
}

int func_800842AC(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    arg2->unk3C = arg2->unk4 * 2;
    arg2->unk20.s16[arg2->unk1][1] = arg2->unk4 * 2;
    arg2->unk1C.fields.unk1E_6 = 1;
}

int func_800842F0(vs_skill_t* arg0 __attribute__((unused)), func_80085718_t* arg1,
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    arg1->unk1C.fields.unk1F_2 = 2;
}

int func_80084310(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4)
{
    if (arg4 != 0) {
        func_800BEC14(0x40, 1);
    }
}

int func_80084340(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4)
{
    if (arg4 != 0) {
        func_800BEC14(0x20, 1);
    }
}

int func_80084370(vs_skill_t* arg0 __attribute__((unused)), func_80085718_t* arg1,
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
    arg1->unk1C.fields.unk1F_2 = 2;
}

int func_80084390(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (vs_main_skills[D_800F19CC->unk8.unk0].unk2_1 == 1u) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_80084440(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (vs_main_skills[D_800F19CC->unk8.unk0].unk2_1 != 1u) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_800844F0(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unk8.unk2 == 0) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_80084570(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unk8.unk2 == 1) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_800845F0(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unk8.unk2 == 2) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_80084670(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unk8.unk2 == 3) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_800846F0(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unk8.unk2 == 4) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_80084770(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unk8.unk2 == 5) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_800847F0(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    if (D_800F19CC->unk8.unk2 == 6) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_80084870(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    int temp_v1 = D_800F19CC->unk8.unk20 & 3;
    if ((temp_v1 == 1) || ((temp_v1 == 3))) {
        short temp_a2 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
        arg2->unk4 += temp_a2;
        arg2->unk1C.fields.unk1C_0 = 2;
        func_800801E0(arg0, arg2, temp_a2);
    }
}

int func_8008490C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unkA += temp_v0;
    arg2->unk1C.fields.unk1C_6 = 2;
}

int func_80084958(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unkC += temp_v0;
    arg2->unk1C.fields.unk1D_0 = 2;
}

int func_800849A4(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unkE += temp_v0;
    arg2->unk1C.fields.unk1D_2 = 2;
}

int func_800849F0(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unk10 += temp_v0;
    arg2->unk1C.fields.unk1D_4 = 2;
}

int func_80084A3C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unk12 += temp_v0;
    arg2->unk1C.fields.unk1D_6 = 2;
}

int func_80084A8C(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unkA += temp_v0;
    arg2->unk1C.fields.unk1C_6 = 1;
}

int func_80084AD8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unkC += temp_v0;
    arg2->unk1C.fields.unk1D_0 = 1;
}

int func_80084B24(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    int temp_v0 = vs_main_getRand(4) + 1;
    arg2->unkE += temp_v0;
    arg2->unk1C.fields.unk1D_2 = 1;
}

int func_80084B70(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short temp_v0;
    vs_battle_actor2* temp_s4 = vs_battle_actors[arg1->unk0]->unk3C;
    vs_battle_actor2* temp_s2 = vs_battle_actors[arg2->unk0]->unk3C;
    D_800F1A0C = 0;
    temp_v0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    arg2->unk4 += temp_v0;

    if (D_800F1A0C != 0) {
        arg2->unk1C.fields.unk1C_0 = 3;
    } else {
        arg2->unk1C.fields.unk1C_0 = 1;
    }

    if (arg2->unk40 == 0) {
        func_80080000(arg0, arg2, temp_v0);
        if (temp_s2->flags.fields.unk3 != 0x80) {
            arg2->unk18 |= temp_s2->unk948 & 0x8000;
        }
        if (arg4 != 0) {
            func_800802C4(arg0, temp_s4, temp_s2, temp_v0);
            func_800803A4(arg0, temp_s4, temp_s2, temp_v0);
        }
    }
}

int func_80084CAC(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    vs_battle_actor2* temp_s0 = vs_battle_actors[arg2->unk0]->unk3C;
    short var_a0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    if (temp_s0->currentMP < var_a0) {
        var_a0 = temp_s0->currentMP;
        D_800F1A08 = temp_s0->currentMP;
    }
    arg2->unk6 += var_a0;
    arg2->unk1C.fields.unk1C_2 = 1;
}

int func_80084D44(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    u_short new_var;

    if (vs_battle_actors[arg2->unk0]->unk3C->weapon.blade.id != 0) {
        new_var = vs_battle_actors[arg2->unk0]->unk3C->weapon.currentPp;
        arg2->unk20.s16[6][1] += new_var;
        arg2->unk1C.fields.unk1E_4 = 1;
    }
}

int func_80084DA8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)), func_80085718_t* arg2,
    int arg3 __attribute__((unused)), int arg4 __attribute__((unused)))
{
    vs_battle_actor2* temp_a1 = vs_battle_actors[arg2->unk0]->unk3C;
    if (((D_800F19CC->unk8.unk20 & 3) == 1) || ((D_800F19CC->unk8.unk20 & 3) == 3)) {
        if (temp_a1->shield.shield.id != 0) {
            short var_v0 = temp_a1->shield.currentDp;
            arg2->unk3E += var_v0;
            arg2->unk1C.fields.unk1F_0 = 1;
        }
    }
}

int func_80084E28(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short temp_v0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    arg2->unk4 += temp_v0;
    arg2->unk1C.fields.unk1C_0 = 2;
    if (arg2->unk40 == 0) {
        func_800801E0(arg0, arg2, temp_v0);
    }
}

int func_80084EA0(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short temp_v0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    arg2->unk6 = arg2->unk6 + temp_v0;
    arg2->unk1C.fields.unk1C_2 = 2;
}

int func_80084EEC(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short temp_v0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    arg2->unk20.s16[6][1] += temp_v0;
    arg2->unk1C.fields.unk1E_4 = 2;
}

int func_80084F40(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short temp_v0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    arg2->unk20.s16[6][0] += temp_v0;
    arg2->unk1C.fields.unk1E_2 = 2;
}

int func_80084F94(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    short temp_v0 = func_800838EC(arg0, arg1, arg2, arg3, arg4);
    int var_v0 = temp_v0 << 0x10;
    if (var_v0 != 0) {
        arg2->unk8 += temp_v0;
        arg2->unk1C.fields.unk1C_4 = 2;
    }
}

int func_80084FF0(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
}

int func_80084FF8(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
}

int func_80085000(vs_skill_t* arg0 __attribute__((unused)),
    func_80085718_t* arg1 __attribute__((unused)),
    func_80085718_t* arg2 __attribute__((unused)), int arg3 __attribute__((unused)),
    int arg4 __attribute__((unused)))
{
}

void func_80085008(func_80085718_t* arg0)
{
    int i;
    int var_v1;
    short var_a1;
    u_short var_a2;
    vs_battle_actor2* temp_s3;

    temp_s3 = vs_battle_actors[arg0->unk0]->unk3C;
    switch (arg0->unk1C.fields.unk1C_0) {
    case 2:
        var_a2 =
            temp_s3->hitLocations[temp_s3->unk34].unk0 + arg0->unk20.s32[temp_s3->unk34];
        var_a1 =
            temp_s3->hitLocations[temp_s3->unk35].unk0 + arg0->unk20.s32[temp_s3->unk35];
        break;
    case 3:
    case 1:
        var_a2 =
            temp_s3->hitLocations[temp_s3->unk34].unk0 - arg0->unk20.s32[temp_s3->unk34];
        var_a1 =
            temp_s3->hitLocations[temp_s3->unk35].unk0 - arg0->unk20.s32[temp_s3->unk35];
        break;
    default:
        var_a2 = temp_s3->hitLocations[temp_s3->unk34].unk0;
        var_a1 = temp_s3->hitLocations[temp_s3->unk35].unk0;
        break;
    }
    if (!(temp_s3->unk948 & 0x10)) {
        if ((temp_s3->unk34 | temp_s3->unk35) != 0) {
            var_v1 = 0;
            if (temp_s3->unk34 != 0) {
                var_v1 = (var_a2 << 0x10) > 0x10000;
            }
            if ((temp_s3->unk35 != 0) && (var_a1 >= 2)) {
                var_v1 = 1;
            }
            if (var_v1 == 0) {
                func_80081020(4, arg0);
            }
        }
    } else {
        if ((temp_s3->unk34 | temp_s3->unk35) != 0) {
            var_v1 = 0;
            if (temp_s3->unk34 != 0) {
                var_v1 = (var_a2 << 0x10) > 0x10000;
            }
            if ((temp_s3->unk35 != 0) && (var_a1 >= 2)) {
                var_v1 = 1;
            }
            if (var_v1 != 0) {
                func_800810CC(4, arg0);
            }
        }
    }
    if (arg0->unk0 == 0) {
        for (i = 0; i < 4; ++i) {
            switch (arg0->unk1C.fields.unk1C_0) {
            case 2:
                var_a2 = temp_s3->hitLocations[i].unk0 + arg0->unk20.s32[i];
                break;
            case 3:
            case 1:
                var_a2 = temp_s3->hitLocations[i].unk0 - arg0->unk20.s32[i];
                break;
            default:
                var_a2 = temp_s3->hitLocations[i].unk0;
                break;
            }
            if (!(temp_s3->unk948 & D_8004EECC[D_800E8200[i]][0])) {
                var_v1 = var_a2 << 0x10;
                var_v1 = 0x10000 < var_v1;
                if (!var_v1) {
                    func_80081020(D_800E8200[i], arg0);
                }
            } else {
                var_v1 = (var_a2 << 0x10) > 0x10000;
                if (var_v1) {
                    func_800810CC(D_800E8200[i], arg0);
                }
            }
        }
    }
}

void func_80085390(
    vs_skill_t* arg0, func_80085718_t* arg1, func_80085718_t* arg2, int arg3, int arg4)
{
    u_int temp_a1_2;
    int temp_s0;

    if ((arg2->unk40 == 0)
        && (vs_battle_actors[arg2->unk0]->unk3C->flags.fields.unk3 == 0x80)) {
        arg2->unk4 += 999;
        arg2->unk1C.fields.unk1C_0 = 1;
    } else if (arg0->unk2_1 == 1) {
        if ((arg2->unk40 == 0)
            && (vs_battle_actors[arg2->unk0]->unk3C->unk948 & 0x80040000)) {
            D_800F1A08 = 0;
        } else {
            D_800E8378[arg0->hitParams[arg4].unk0](arg0, arg1, arg2, arg4, arg3);
        }
        if (arg2->unk40 == 0) {
            if (vs_battle_actors[arg2->unk0]->unk3C->flags.fields.unk3 != 0x80) {
                arg2->unk18 |= vs_battle_actors[arg2->unk0]->unk3C->unk948 & 0x61000;
            }
        }
    } else {
        D_800E8378[arg0->hitParams[arg4].unk0](arg0, arg1, arg2, arg4, arg3);
    }
    if ((arg3 != 0) && (arg1->unk40 == 0) && (arg1->unk0 == 0) && (arg2->unk40 == 0)
        && (vs_battle_actors[arg2->unk0]->unk3C->flags.fields.unk3 != 0x80)
        && (arg0->unk2_1 == 2 || arg0->unk2_1 == 3 || arg0->unk2_1 == 6)
        && (vs_battle_actors[arg2->unk0]->unk3C->currentHP <= arg2->unk4)
        && (arg2->unk0 != 0) && (vs_battle_actors[arg2->unk0]->unk29 == 0)) {
        vs_battle_actors[arg2->unk0]->unk29 = 1;
        temp_a1_2 = vs_battle_characterState->equippedWeaponType;
        temp_a1_2 %= 10;
        temp_s0 = temp_a1_2 & 0xFF;
        if ((func_800BEBF4(0x82) >= 0xA)
            && (vs_main_artsStatus.artsLearned[temp_a1_2 & 0xFF] < 4)
            && (vs_main_artsStatus.kills.weaponCategories[temp_a1_2 & 0xFF]
                < vs_main_artsPointsRequirements[temp_s0][vs_main_artsStatus
                                                              .artsLearned[temp_s0]])) {
            ++vs_main_artsStatus.kills.weaponCategories[temp_s0];
        }
    }
}

void func_800856F8(void* arg0) { vs_main_bzero(arg0, 0x84C); }

void func_80085718(func_80085718_t* arg0)
{
    vs_main_bzero(arg0, sizeof *arg0);
    arg0->unk3 = 6;
    arg0->unk1C.value = 0;
}

// Mostly invoked as func_8008574C_alias without arg3
int func_8008574C(u_int arg0, vs_battle_actor2* arg1, int arg2, int arg3)
{
    int var_v1;
    int var_t0;
    int var_t1;
    vs_skill_t* temp_v0;

    temp_v0 = &vs_main_skills[arg0];
    var_t1 = temp_v0->unk3;
    var_t0 = temp_v0->unk2_1;

    switch (var_t0) {
    case 1:
        arg3 = arg1->currentMP;
        break;
    case 2:
        arg3 = 100 - arg1->risk;
        break;
    case 3:
        arg3 = arg1->currentHP;
        ++var_t1;
        break;
    case 4:
        arg3 = arg1->weapon.currentPp;
        break;
    case 6:
        var_t1 = arg1->weapon.risk;
        switch (arg1->weapon.unk10F) {
        case 1:
            arg3 = arg1->currentMP;
            break;
        case 2:
            arg3 = 100 - arg1->risk;
            break;
        case 3:
            arg3 = arg1->currentHP;
            ++var_t1;
            break;
        case 4:
            arg3 = arg1->weapon.currentPp;
            break;
        }
        var_t0 = arg1->weapon.unk10F;
        break;
    default:
        arg3 = 0;
        break;
    }

    if (var_t0 == 2) {
        if (D_800F19CC->unk4 >= 0xA) {
            if ((arg0 - 0x16) < 0x12) {
                var_t1 += (D_800F19CC->unk4 * D_800F19CC->unk4) / 10;
            }
        }
    }
    if (arg3 >= var_t1) {
        if (var_t0 == 3) {
            --var_t1;
        }
        arg3 -= var_t1;
        var_v1 = 1;
    } else {
        if (var_t0 == 2) {
            arg3 = 0;
            var_v1 = 1;
        } else {
            var_v1 = 0;
        }
    }

    if (arg2 != 0) {
        switch (var_t0) {
        case 1:
            arg1->currentMP = arg3;
            break;
        case 2:
            arg1->risk = 100 - arg3;
            break;
        case 3:
            arg1->currentHP = arg3;
            break;
        case 4:
            arg1->weapon.currentPp = (u_short)arg3;
            break;
        }
    }
    return (var_v1 << 0x18) + (var_t0 << 0x10) + var_t1;
}

void func_80085978(int arg0, int arg1)
{
    func_8008574C_alias(arg0, vs_battle_actors[arg1]->unk3C, 0);
}

void func_800859B4(u_int arg0, vs_battle_actor2* arg1, int arg2)
{
    vs_skill_t* new_var = &vs_main_skills[arg0];

    if ((arg2 != 0) && ((arg0 - 0x16) >= 0x20)) {
        if (new_var->flags_0 == 0xFF) {
            arg1->flags.fields.unk0 += (arg1->weapon.unk10B + arg1->flags.fields.unk2_2)
                                    << 8;
        } else {
            int new_var2 = new_var->flags_0 + arg1->flags.fields.unk2_2;
            arg1->flags.fields.unk0 += new_var2 << 8;
        }
    }
}

void func_80085A34(func_80085A34_t* arg0)
{
    int i;
    u_int var_a1;

    if (arg0->unk40 == 0) {
        if (arg0->unk2 == 0xFF) {
            arg0->unk2 = 0;
        }
        if (arg0->unk3 == 6) {
            var_a1 = arg0->unk1C;
            if (var_a1 != 0) {
                for (i = 0; i < 9; var_a1 >>= 2, ++i) {
                    switch (var_a1 & 3) {
                    case 2:
                        arg0->unk3 = 5;
                        return;
                    case 1:
                        arg0->unk3 = 0;
                        return;
                    case 3:
                        arg0->unk3 = 1;
                        return;
                    }
                }
            } else if ((arg0->unk14 | arg0->unk18) == 0) {
                arg0->unk3 = 4;
                arg0->unk2 = 0;
            }
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80085B10);

int func_8008631C(int arg0, int arg1, int arg2, int arg3, void* arg4)
{
    func_8008631C_t sp10;

    sp10.unk4C.unk.unk0 = arg2;
    sp10.unk0 = arg0;
    sp10.unk44 = 0;
    sp10.unk4 = arg1;
    sp10.unk4A = 1;
    sp10.unk8C = 0;
    sp10.unk4C.unk.unk1 = arg3;
    func_80085B10(arg0, arg4, &sp10, 0);
    return func_8008574C_alias(arg0, vs_battle_actors[arg1]->unk3C, 0) & 0xFF000000;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800863A4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80086754);

void func_80086EA4(vs_battle_actor2* arg0, int arg1, int arg2, int arg3)
{
    if (arg0->weapon.blade.id != 0) {
        arg0->weapon.classAffinityCurrent.affinity[0][arg1] += arg3;
        arg0->weapon.classAffinityCurrent.affinity[0][arg2] -= arg3;
        arg0->weapon.unk168[arg1] = arg3;
        arg0->weapon.unk168[arg2] = -arg3;
    }
}

void func_80086EF4(vs_battle_actor2* arg0, int arg1, int arg2, int arg3)
{
    int i;

    if (arg0->shield.shield.id != 0) {
        arg0->shield.classAffinityCurrent.affinity[0][arg1] += arg3;
        arg0->shield.classAffinityCurrent.affinity[0][arg2] -= arg3;
        arg0->shield.unk134[arg1] = arg3;
        arg0->shield.unk134[arg2] = -arg3;
    }

    for (i = 0; i < 6; ++i) {
        if (arg0->hitLocations[i].armor.armor.id != 0) {
            arg0->hitLocations[i].armor.classAffinityCurrent.affinity[0][arg1] += arg3;
            arg0->hitLocations[i].armor.classAffinityCurrent.affinity[0][arg2] -= arg3;
            arg0->hitLocations[i].armor.unk88[arg1] = arg3;
            arg0->hitLocations[i].armor.unk88[arg2] = -arg3;
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80086FA8);

void func_80087578(int arg0)
{
    if ((vs_battle_actors[arg0]->unk27 != 0x80) || (arg0 == 0)) {
        func_80093B68();
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800875C8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80087EF4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_800882F4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088554);

void func_80088B6C(void) { func_80088554(); }

void func_80088B8C(void)
{
    if ((D_800F196C == 2) && (D_800F18F0 < 4) && (D_800F18F0 != 0)) {
        if ((D_800E8498 == 0)
            && (((vs_battle_actors[D_800F19CC->unk8.unk4]->unk3C->unk948 & 8) != 0))
            && (D_800F19CC->unk8.unk44 == 0)) {
            if (D_800F19CC->unk8.unk4 == 0) {
                if (vs_battle_characterState->unk3C->risk < 100) {
                    ++vs_battle_characterState->unk3C->risk;
                }
            }
        }
        D_800E8498 = (D_800E8498 + vs_gametime_tickspeed) % 30;
    }
}

void func_80088CA0(void) { D_800E8498 = 0; }

void func_80088CAC(void)
{
    if (D_80050468.unk2 == 2) {
        func_8007BCCC();
    }
    func_80069DBC();
}

void _allocHeap(void* arg0, int size)
{
    if (size == 0) {
        vs_main_nop9(0x8B, 0);
    }
    D_800F1884 = vs_main_allocHeap(size);
    vs_main_memcpy(D_800F1884, arg0, size);
}

void func_80088D40(int* arg0, int arg1 __attribute__((unused)))
{
    int temp_a0 = *arg0;
    D_800F1880.unk8 = temp_a0;
    if (temp_a0 != 0) {
        D_800F1880.unk10 = vs_main_allocHeap(temp_a0 * 8);
        vs_main_memcpy(D_800F1880.unk10, arg0 + 1, D_800F1880.unk8 * 8);
        D_800F1880.unkC = vs_main_allocHeap(D_800F1880.unk8 * 0x464);
        vs_main_memcpy(
            D_800F1880.unkC, arg0 + ((D_800F1880.unk8 * 2) + 1), D_800F1880.unk8 * 0x464);
        return;
    }
    D_800F1880.unk10 = NULL;
    D_800F1880.unkC = NULL;
}

static void _loadZnd(int id)
{
    vs_main_CdFile sp10;
    int temp_s0;

    sp10.lba = vs_main_zndFiles[id].lba;
    sp10.size = vs_main_zndFiles[id].size;
    if (D_800F1880.unk20 != 0) {
        vs_main_nop9(0x87, 0);
    }
    D_800F1880.unk20 = vs_main_allocateCdQueueSlot(&sp10);
    if (D_800F1880.unk24 != 0) {
        vs_main_nop9(0x88, 0);
    }
    D_800F1880.unk24 = vs_main_allocHeapR(sp10.size);
    vs_main_cdEnqueueUrgent(D_800F1880.unk20, D_800F1880.unk24);
    if (D_800F1880.unk30 != 0) {
        temp_s0 = D_8004FCCC[id];
        if (func_800450E4() != temp_s0) {
            func_8004552C(vs_main_soundData.currentMusicId, 0, 0x78);
        }
    }
}

// https://decomp.me/scratch/Wau7O
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80088EF0);

void func_80089098(void)
{
    func_800BEBEC();
    _nop(0);
    if (D_800F1880.unkC != 0) {
        vs_main_freeHeap(D_800F1880.unkC);
    }
    if (D_800F1880.unk10 != 0) {
        vs_main_freeHeap(D_800F1880.unk10);
    }
    vs_main_freeHeap(D_800F1880.unk4);
}

int func_80089104(void) { return D_800F18A8; }

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089114);

void func_80089888(void)
{
    SVECTOR sp10;
    func_8006EBF8_t sp18;
    func_80089888_t sp28;

    func_8009D458();
    sp28.unk0_0 = D_800F1AB0.unk4_8;
    sp28.unk0_16 = D_800F1AB0.unk6_10;
    sp28.unk0_8 = D_800F1AB0.unk2_13;
    sp28.unk0_24 = D_800F1AB0.unk4_13 * 64;
    func_800A30A0(0, &sp28, -0x800, 2);

    if (D_800F1AB0.unk4_15) {
        switch (D_800F1AB0.unk4_13) {
        case 0:
            sp10.vx = 0x40;
            sp10.vz = 0;
            sp10.vy = 0;
            break;
        case 1:
            sp10.vx = 0;
            sp10.vz = 0x40;
            sp10.vy = 0;
            break;
        case 2:
            sp10.vx = 0x40;
            sp10.vz = 0;
            sp10.vy = 0;
            break;
        case 3:
            sp10.vx = 0;
            sp10.vz = 0x40;
            sp10.vy = 0;
            break;
        default:
            sp10.vy = 0;
            break;
        }
        func_800A9D24(0, &sp10, 0);
    }
    func_800A1108(0, &sp18);
    func_8009E5C4(0);
    func_800A4828(0, &D_1F800000[5]);
    func_800A0A1C(0, 0);
    func_800E6158();
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089A00);

void func_80089C5C(void* arg0, u_int arg1)
{
    if (arg1 != 0) {
        D_800F1880.unk64 = vs_main_allocHeap(arg1);
        vs_main_memcpy(D_800F1880.unk64, arg0, arg1);
        D_800F1880.unk60 = arg1 / 40;
        return;
    }
    D_800F1880.unk64 = NULL;
    D_800F1880.unk60 = NULL;
}

void func_80089CE4(void) { SetDispMask(1); }

void func_80089D04(void) { SetDispMask(0); }

void func_80089D24(int arg0)
{
    vs_main_CdFile file;

    file.lba = D_800F1880.unk4[arg0].lba;
    file.size = D_800F1880.unk4[arg0].size;

    if (D_800F1880.unk58 != 0) {
        vs_main_nop9(0x89, 0);
    }
    D_800F1880.unk58 = vs_main_allocateCdQueueSlot(&file);
    if (D_800F1880.unk5C != 0) {
        vs_main_nop9(0x8A, 0);
    }
    D_800F1880.unk5C = vs_main_allocHeapR(file.size);
    vs_main_cdEnqueueUrgent(D_800F1880.unk58, D_800F1880.unk5C);
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80089DC0);

void func_8008A364(void)
{
    int i;

    for (i = 2; i < 16; ++i) {
        func_8006A228(i, 0);
    }
}

void func_8008A3A0(void)
{
    int i;

    for (i = 0; i < 2; ++i) {
        D_1F800000[1] = (int)D_80055C80[vs_main_frameBuf] + 0x10;
        ClearOTagR((void*)D_1F800000[1], 0x800);
        func_8007DF40();
        func_8006D0A4((void*)D_1F800000[1]);
        func_8007629C((void*)D_1F800000[1] + 0x1FFC);
    }

    DrawSync(0);
    vs_main_gametimeUpdate(0);
    func_800BEB34();
    _setRoomSeen();
    func_8008ABF0(0);
    if (D_800F18E4 != NULL) {
        vs_main_freeHeap(D_800F18E4);
    }
    if (D_800F192C != NULL) {
        func_800E7454(D_800F192C);
    }
    func_8008A364();
    func_800E6F1C();
    func_80095B7C(0, 0);
    func_8009D6F4();
    func_8008A6FC();
    vs_main_freeHeap(D_8005E0C0[1]);
    vs_main_freeHeap(D_8005E0C0[0]);
}

void func_8008A4DC(int arg0)
{
    if (arg0 != 0) {
        D_800F190C = 1;
    } else {
        D_800F190C = 0;
    }
}

int func_8008A4FC(void)
{
    func_8006EBF8_t sp10;
    D_800F1910_t2* temp_v0;
    u_int temp_a2;
    u_int temp_v0_2;
    u_int var_a2;
    char var_a0;
    char var_a1;
    func_8006EBF8_t_fields* s0;

    func_800A1108(0, &sp10);
    temp_v0_2 = func_800A0BE0(0);
    temp_a2 = temp_v0_2 & 0x70000;
    s0 = &sp10.unk0.unk0.fields;
    if (temp_a2 != 0) {
        var_a0 = 0;
        var_a1 = 0;
        var_a2 = temp_a2 >> 0x10;
    } else {
        var_a0 = s0->unk0;
        var_a1 = s0->unk2;
        var_a2 = s0->unk1;
    }
    if (func_8008B764(var_a0, var_a1, var_a2)->unk0_16 & 1) {
        if (!(temp_v0_2 & 0x504000)) {
            temp_v0 = func_8008D438(s0->unk0, s0->unk2, s0->unk1);
            if (temp_v0 != NULL) {
                if (temp_v0->unk6 == 0x10) {
                    return temp_v0->unkA;
                }
            }
        }
    }
    return 0;
}

int vs_battle_getSkillFlags(int arg0, int id)
{
    vs_battle_actor2* temp_s1;
    int ret;
    vs_skill_t* skill = &vs_main_skills[id];

    temp_s1 = vs_battle_actors[arg0]->unk3C;
    ret = temp_s1->flags.fields.unk0 != 0;

    if (!(func_8008574C_alias(id, temp_s1, 0) & 0xFF000000)) {
        ret |= 2;
    }

    if (arg0 == 0) {
        if (!((skill->flags_15 << 15) & 0x8000)) {
            ret |= 4;
        }
    }
    if (id < 141) {
        if (temp_s1->unk948 & 0x1000) {
            ret |= 4;
        }
    } else if (id < 224) {
        if (vs_battle_actors[arg0]->unk20 == 0) {
            ret |= 4;
        }
        if (temp_s1->unk948 & 0x2000) {
            ret |= 4;
        }
    }
    return ret;
}

void func_8008A6FC(void)
{
    D_800F1900_t* var_a0 = D_800F1900;

    while (var_a0 != 0) {
        D_800F1900_t* temp_s0 = var_a0->unk0;
        vs_main_freeHeapR(var_a0);
        var_a0 = temp_s0;
    }
    D_800F1900 = NULL;
}

// https://decomp.me/scratch/tkgPf
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008A744);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008A908);

void vs_battle_setDoorEntered(void)
{
    vs_main_stateFlags.doorEntered = vs_battle_doorEntered + 1;
}

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

int func_8008ABF0(int arg0)
{
    if (D_800F1BF8.unk0 == 1) {
        if (D_800F1BF8.unk2 == arg0) {
            func_8008F234();
            func_80091378();
            func_80092A18();
            if (D_800F1BF8.unk64 != 0) {
                vs_main_freeHeap((void*)D_800F1BF8.unk64);
            }
            vs_main_bzero(&D_800F1BF8, 0xC4);
            return 1;
        }
    }
    return 0;
}

// https://decomp.me/scratch/jsBf0
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008AC78);

void func_8008B1FC(void* arg0)
{
    SetRotMatrix((MATRIX*)0x1F800014);
    SetTransMatrix((MATRIX*)0x1F800014);
    func_800983F8(arg0);
    D_800F1CC0 = *(int*)0x1F800000;
    func_8009723C(arg0, D_800F19C8);
    D_800F1BB8 = *(int*)0x1F800000;
    if (D_800F1BB0.unk6 != 0) {
        func_80098D6C(D_800F1CC0, D_800F1BB8, &D_800F1BB0, 0);
    }
}

void func_8008B28C(void)
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

void func_8008B320(void)
{
    func_80048A64(D_800F1BA8, 0, 0, 0x100);
    func_80048A64(D_800F1BA8 + 0x100, 1, 0, 0x100);
    func_80048A64(D_800F1BA8 + 0x200, 2, 0, 0x100);
    func_80099960(D_800F1BA8 + 0x300);
}

void func_8008B390(int arg0, int* arg1)
{
    int i;

    int* var_a1 = arg1;
    int temp_t3 = *arg1;
    var_a1 = arg1 + 1;

    for (i = 0; i < temp_t3; ++i) {
        void* temp_v1 = arg1 + ((var_a1[7] >> 2));
        int temp_t0 = *(int*)temp_v1;
        int temp_t2;
        int j;

        temp_v1 += 4;
        temp_t2 = *(int*)temp_v1;
        temp_v1 += 4;

        for (j = 0; j < temp_t0; ++j, temp_v1 += 0x20) {
            *((short*)(temp_v1 + 0x1E)) += arg0;
        }

        for (j = 0; j < temp_t2; ++j, temp_v1 += 0x28) {
            *((short*)(temp_v1 + 0x1E)) += arg0;
        }
        var_a1 += 0x10;
    }
}

void func_8008B430(char* arg0, int arg1)
{
    if ((arg0[0] == 0) && (arg0[1] == 0) && (arg0[2] == 0) && (arg1 == 0)) {
        D_800F1BB6 = 0;
        return;
    }
    D_800F1BB0.unk6 = 1;
    D_800F1BB0.unk4 = arg1;
    D_800F1BB0.unk0 = arg0[0];
    D_800F1BB0.unk1 = arg0[1];
    D_800F1BB0.unk2 = arg0[2];
}

void func_8008B4B0(void) { D_800F1BB6 = 0; }

void func_8008B4BC(int arg0) { D_800F1BA4 = arg0; }

int func_8008B4C8(char arg0) { return D_800F1CD6 = arg0; }

void vs_battle_setRoomsUnk0(vs_battle_scene* scene)
{
    int i;
    vs_battle_room* room = scene->rooms;
    int roomCount = scene->roomCount;

    for (i = 0; i < roomCount; ++i, ++room) {
        int locationId = _getLocationId(room->zoneId, room->mapId - 1);
        if (locationId > 0) {
            room->visited =
                vs_main_mapStatus.roomFlags[locationId >> 5] & (1 << (locationId & 0x1F));
        } else {
            room->visited = 0;
        }
    }
}

void _nop(int arg0 __attribute__((unused))) { }

void func_8008B590(MATRIX* arg0, int arg1)
{
    int temp_s0 = rsin(arg1);
    int temp_v0 = rcos(arg1);
    int a2 = -temp_s0;

    arg0->m[0][0] = temp_v0;
    arg0->m[0][1] = 0;
    arg0->m[0][2] = temp_s0;

    arg0->m[1][0] = ((a2 * -3138) / ONE);
    arg0->m[1][1] = 2633;
    arg0->m[1][2] = (-(temp_v0 * 3138) / ONE);

    arg0->m[2][0] = ((a2 * 2633) / ONE);
    arg0->m[2][1] = 3138;
    arg0->m[2][2] = ((temp_v0 * 2633) / ONE);
}

void func_8008B6B4(void)
{
    D_800F1D6A = 0;
    D_800F1D6C = 0;
    vs_main_bzero(D_800F1D28, sizeof D_800F1D28);
}

func_8008B764_t* func_8008B6EC(void) { return D_800F1BF8.unk6C; }

int func_8008B6FC(void) { return D_800F1BF8.unk78; }

int func_8008B70C(void)
{
    if (D_800F1BF8.unk68 != 0) {
        return (D_800F1BF8.unk68->unk2 << 0x14)
             | ((u_short)(D_800F1BF8.unk68->unk0 * 0x10));
    }
    return 0;
}

int func_8008B744(void)
{
    if (D_800F1BF8.unkC0 != 0) {
        return D_800F1BF8.unkC0;
    }
    return 0;
}

func_8008B764_t* func_8008B764(u_int arg0, u_int arg1, int arg2)
{
    if (D_800F1BF8.unk6C != NULL) {
        if (arg2 >= 2) {
            if (D_800F1BF8.unkA8 != NULL) {
                return &D_800F1BF8.unkA8[arg2 - 2].unkB4;
            }
            return NULL;
        }
        if ((arg0 < D_800F1BF8.unk68->unk0) && (arg1 < D_800F1BF8.unk68->unk2)) {
            return &D_800F1BF8.unk6C[arg1 * D_800F1BF8.unk68->unk0 + arg0];
        }
    }
    return NULL;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008B808);

void func_8008B8F8(char (*arg0)[12])
{
    if (arg0 != NULL) {
        int doorId;
        vs_main_memcpy(&D_800F1CC8, arg0, sizeof D_800F1CC8);
        doorId = _getDoorId((*arg0)[8]);
        vs_battle_doorEntered = doorId;
    } else {
        vs_main_bzero(&D_800F1CC8, sizeof D_800F1CC8);
        vs_battle_doorEntered = -1;
    }
}

void func_8008B960(int arg0, int arg1, int arg2)
{
    int temp_t4;
    int j;
    func_8008B960_t* var_s0;
    int i;

    if (D_800F1BF8.unk70 != 0) {
        temp_t4 = D_800F1BF8.unk10 / 12;
        var_s0 = D_800F1BF8.unk70;
        for (i = 0; i < temp_t4; ++i, ++var_s0) {
            if ((arg2 >= 2) && ((&var_s0->unk2)->unk0_10 == arg2)) {
                break;
            }
            if ((&var_s0->unk2)->unk0_10 == arg2) {
                for (j = 0; j < 9; ++j) {
                    int new_var = 1;
                    if (((&var_s0->unk2)->unk0_0
                            == ((arg0 - new_var) + (j - ((j / 3) * 3))))
                        && ((&var_s0->unk2)->unk0_5 == ((arg1 - new_var) + (j / 3)))) {
                        break;
                    }
                }
                if (j != 9) {
                    break;
                }
            }
        }
        if (i == temp_t4) {
            var_s0 = NULL;
        }
    } else {
        var_s0 = NULL;
    }
    if (var_s0 != NULL) {
        vs_main_memcpy(&D_800F1CC8, var_s0, sizeof D_800F1CC8);
        temp_t4 = _getDoorId(var_s0->unk8);
        vs_battle_doorEntered = temp_t4;
    } else {
        vs_main_bzero(&D_800F1CC8, sizeof D_800F1CC8);
        vs_battle_doorEntered = -1;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008BAC8);

func_8008C1C8_t* func_8008BC04(int arg0, int arg1, int arg2)
{
    int temp_t2;
    func_8008C1C8_t* var_t0;
    int i;

    if (D_800F1BF8.unk88 != 0) {
        temp_t2 = D_800F1BF8.unk28 / 20;
        var_t0 = D_800F1BF8.unk88;
        if (var_t0->unk0.unk8.u8[2] != 0) {
            for (i = 0; i < temp_t2; ++i, ++var_t0) {
                if ((var_t0->unk0.unk0 == arg0) && (var_t0->unk0.unk2 == arg1)
                    && (var_t0->unk0.unk4 == arg2)) {
                    return var_t0;
                }
                switch (var_t0->unk0.unk6 - 4) {
                case 0:
                    if ((var_t0->unk0.unk0 == arg0) && ((var_t0->unk0.unk2 - 1) == arg1)
                        && (var_t0->unk0.unk4 == arg2)) {
                        return var_t0;
                    }
                    break;
                case 1:
                    if (((var_t0->unk0.unk0 + 1) == arg0) && (var_t0->unk0.unk2 == arg1)
                        && (var_t0->unk0.unk4 == arg2)) {
                        return var_t0;
                    }
                    break;
                case 2:
                    if ((var_t0->unk0.unk0 == arg0) && ((var_t0->unk0.unk2 + 1) == arg1)
                        && (var_t0->unk0.unk4 == arg2)) {
                        return var_t0;
                    }
                    break;
                case 3:
                    if (((var_t0->unk0.unk0 - 1) == arg0) && (var_t0->unk0.unk2 == arg1)
                        && (var_t0->unk0.unk4 == arg2)) {
                        return var_t0;
                    }
                    break;
                }
            }
        }
    }
    return NULL;
}

void func_8008BD74(func_8008C1C8_t* arg0)
{
    func_8008B764_t* var_a0;

    var_a0 = func_8008B764(arg0->unk0.unk0, arg0->unk0.unk2, arg0->unk0.unk4);
    if (var_a0 != NULL) {
        var_a0->unk0_10 ^= 5;
    }
    var_a0 = NULL;
    switch (arg0->unk0.unk6 - 4) {
    case 0:
        var_a0 = func_8008B764(arg0->unk0.unk0, arg0->unk0.unk2 - 1, arg0->unk0.unk4);
        break;
    case 1:
        var_a0 = func_8008B764(arg0->unk0.unk0 + 1, arg0->unk0.unk2, arg0->unk0.unk4);
        break;
    case 2:
        var_a0 = func_8008B764(arg0->unk0.unk0, arg0->unk0.unk2 + 1, arg0->unk0.unk4);
        break;
    case 3:
        var_a0 = func_8008B764(arg0->unk0.unk0 - 1, arg0->unk0.unk2, arg0->unk0.unk4);
        break;
    }
    if ((arg0->unk0.unk6 >= 4) && (var_a0 != NULL)) {
        var_a0->unk0_10 ^= 5;
    }
}

int func_8008BEBC(func_8008C1C8_t* arg0)
{
    if (arg0->unk12 == 0) {
        u_int temp_a0 = (u_short)arg0->unkC;
        arg0->unk12 = 1;
        if ((temp_a0 - 0x1CA) < 7) {
            func_8008E6DC((short)temp_a0 - 0x1CA);
        }
        if (arg0->unkE == 0) {
            arg0->unk13 = 8;
            func_8008C070(3, arg0);
            return 1;
        }
        func_8008BF48(arg0);
        return 1;
    }
    return 0;
}

int func_8008BF48(func_8008C1C8_t* arg0)
{
    func_8008C1C8_t* temp_s0;

    if (arg0->unkE == 0) {
        vs_main_playSfxDefault(0x7E, 0x1D);
        vs_main_playSfxDefault(0x7E, 0x1E);
    } else {
        vs_main_playSfxDefault(0x7E, 0x16);
        vs_main_playSfxDefault(0x7E, 0x17);
    }
    func_8009291C(arg0->unk0.unk8.u8[1]);
    if (arg0->unkE != 0) {
        func_8008BD74(arg0);
    }
    if (arg0->unk10 != -1) {
        temp_s0 = D_800F1BF8.unk88;
        if (temp_s0[arg0->unk10].unk0.unkA != 0) {
            func_8009291C(temp_s0[arg0->unk10].unk0.unk8.u8[1]);
            if (temp_s0[arg0->unk10].unkE != 0) {
                func_8008BD74(&temp_s0[arg0->unk10]);
            }
            temp_s0[arg0->unk10].unk12 = 1;
        }
    }
    func_8008C070(1, arg0);
    return 1;
}

void func_8008C070(int arg0, func_8008C1C8_t* arg1)
{
    int i;

    ++D_800F1D6A;

    for (i = 0; i < 8; ++i) {
        if (D_800F1D28[i].unk0 == 0) {
            D_800F1D28[i].unk0 = arg0;
            D_800F1D28[i].unk4 = arg1;
            return;
        }
    }
}

void func_8008C0C0(void)
{
    func_8008C1C8_t* temp_a0;
    int i;

    if (D_800F1D6A <= 0) {
        return;
    }

    for (i = 0; i < 8; ++i) {
        if (D_800F1D28[i].unk0 == 1) {
            if (func_8008C1C8(D_800F1D28[i].unk4) != 0) {
                D_800F1D28[i].unk0 = 0;
                D_800F1D28[i].unk4 = NULL;
                --D_800F1D6A;
            }
        } else if (D_800F1D28[i].unk0 == 2) {
            temp_a0 = D_800F1D28[i].unk4;
            if ((--temp_a0->unk0.unkA << 0x18) <= 0) {
                func_8008D658(temp_a0);
                D_800F1D28[i].unk0 = 0;
                D_800F1D28[i].unk4 = NULL;
                --D_800F1D6A;
            }
        } else if (D_800F1D28[i].unk0 == 3) {
            temp_a0 = D_800F1D28[i].unk4;
            if (!(--temp_a0->unk13)) {
                func_8008BF48(temp_a0);
                D_800F1D28[i].unk0 = 0;
                D_800F1D28[i].unk4 = NULL;
                --D_800F1D6A;
            }
        }
    }
}

int func_8008C1C8(func_8008C1C8_t* arg0)
{
    if (func_80093764(arg0->unk0.unk8.u8[1]) != 0) {
        return 0;
    }
    if (arg0->unkE == 0) {
        func_8008BD74(arg0);
    }
    arg0->unk12 = 0;
    arg0->unkE = arg0->unkE == 0;
    if (arg0->unk10 != -1) {
        func_8008C1C8_t* p = D_800F1BF8.unk88;
        if (p[arg0->unk10].unk0.unkA != 0) {
            if (p[arg0->unk10].unkE == 0) {
                func_8008BD74(&p[arg0->unk10]);
            }
            p[arg0->unk10].unkE = p[arg0->unk10].unkE == 0;
            p[arg0->unk10].unk12 = 0;
        }
    }
    return 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C2C0);

void func_8008C40C(void)
{
    int temp_a1;
    int i;
    int* var_a0;

    var_a0 = D_800F1BF8.unk64 + 1;
    if (D_800F1BF8.unk64 != 0) {
        temp_a1 = D_800F1BF8.unk64[0];
        for (i = 0; i < temp_a1; ++i) {
            *var_a0 &= ~0x1000;
            var_a0 += 16;
        }
    }
}

void func_8008C458(int arg0) { func_80098B38(arg0, 0); }

int func_8008C478(int arg0)
{
    if (D_800F1BF8.unk7C != 0) {
        return D_800F1BF8.unk7C + (arg0 * 8);
    }
    return 0;
}

int func_8008C49C(int arg0, int arg1)
{
    if (D_800F1BF8.unkA8 != NULL) {
        D_800F1BF8.unkA8[arg0].unk4_1 = arg1;
        if ((arg1 >= 0) && (D_800F1D68 == 0)) {
            D_800F1D70[arg0] = 0;
        }
        return 1;
    }
    return 0;
}

void func_8008C518(int arg0) { func_8008C49C(arg0, -1); }

void func_8008C538(void)
{
    D_800F1CA0_t* var_s2;
    int temp_s3;
    int i;
    int* temp_v0;
    u_int temp_a0;

    D_800F1D6E = 0;
    D_800F1D68 = 0;
    D_800F1D6F = 0;

    for (i = 0; i < 4; ++i) {
        D_800F1D70[i] = 7;
    }

    if (D_800F1BF8.unkA8 != NULL) {
        temp_s3 = D_800F1BF8.unk48 / 184;
        var_s2 = D_800F1BF8.unkA8;
        for (i = 0; i < temp_s3; ++i, ++var_s2) {
            temp_v0 = func_8009195C(var_s2->unk0_0);
            if (temp_v0 != NULL) {
                if (var_s2->unk0_9) {
                    temp_v0[0] |= 0x100;
                }

                temp_v0[1] = var_s2->unkA8 / ONE;
                temp_v0[2] = -(var_s2->unkAC / ONE);
                temp_v0[3] = var_s2->unkB0 / ONE;
            }
        }
    }

    temp_a0 = D_800F1CCA >> 0xD;
    if (temp_a0 >= 2) {
        func_8008C6B4(temp_a0 - 2, -1);
    }
}

void func_8008C6B4(int arg0, int arg1)
{
    D_800F1CA0_t* temp_s0;
    int* temp_v0_5;

    if (D_800F1BF8.unkA8 != NULL) {
        temp_s0 = &D_800F1BF8.unkA8[arg0];
        if (arg1 == -1) {
            arg1 = temp_s0->unk4_8;
        }
        if (arg1 >= 0) {
            temp_s0->unk0_9 = 0;
            temp_s0->unk4_1 = 0;
            temp_s0->unk0_27 = arg1;
            temp_s0->unk0_14 = arg1;
            temp_s0->unk0_29 = arg1;
            temp_s0->unk4_16 = 0;
            temp_s0->unk4_0 = 0;

            temp_s0->unkA8 = temp_s0->unk8[temp_s0->unk0_27].vx;
            temp_s0->unkAC = temp_s0->unk8[temp_s0->unk0_27].vy;
            temp_s0->unkB0 = temp_s0->unk8[temp_s0->unk0_27].vz;

            if (((temp_s0->unk0_14)) == ((temp_s0->unk0_10))) {
                temp_s0->unk0_26 = 0;
                --temp_s0->unk0_27;
            } else {
                temp_s0->unk0_26 = 1;
                ++temp_s0->unk0_27;
            }
            temp_v0_5 = func_8009195C(temp_s0->unk0_0);
            if (temp_v0_5 != NULL) {
                temp_v0_5[1] = temp_s0->unkA8 / ONE;
                temp_v0_5[2] = -(temp_s0->unkAC / ONE);
                temp_v0_5[3] = temp_s0->unkB0 / ONE;
            }
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008C8A8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008CEB0);

int func_8008D2C0(func_8008D2C0_t arg0[])
{
    D_800F1CA0_t* var_t0;
    int i;
    int var_t1;
    int temp_t3;

    func_8008D2C0_t* a0 = arg0;

    do {
        if (D_800F1BF8.unkA8 != NULL) {
            var_t0 = D_800F1BF8.unkA8;
            temp_t3 = D_800F1BF8.unk48 / 184;
            var_t1 = 0;

            for (i = 0; i < temp_t3; ++i, ++var_t0) {
                if (!((var_t0->unk0_9))) {
                    do {
                        int v;
                        a0->unk0 = var_t0->unkA8 / ONE;
                        v = var_t0->unkAC / ONE;
                        a0->unk1 = (D_80068BEC[D_800F1D70[i]] - v);
                        a0->unk2 = (var_t0->unkB0 / ONE);
                        a0->unk3 = i;
                    } while (0);
                    ++a0;
                    ++var_t1;
                }
            }
            return var_t1;
        }
    } while (0);
    return 0;
}

char func_8008D3D0(void) { return D_800F1BF8.unk8C->unk30; }

char func_8008D3E8(void) { return D_800F1BF8.unk8C->unk31; }

int vs_battle_getCurrentSceneId(void) { return D_800F1BF8.unk8C->sceneId; }

int func_8008D418(void)
{
    return (D_800F1BF8.unk8C->unk52 << 0x10) | D_800F1BF8.unk8C->unk54;
}

D_800F1910_t2* func_8008D438(int arg0, int arg1, int arg2)
{
    if (D_800F1BF8.unk84 != NULL) {
        D_800F1910_t2* var_t0 = D_800F1BF8.unk84;
        int temp_t1 = D_800F1BF8.unk24 / 12;
        int i;
        for (i = 0; i < temp_t1; ++i, ++var_t0) {
            if ((var_t0->unk0 == arg0) && (var_t0->unk2 == arg1)
                && (var_t0->unk4 == arg2)) {
                if (((vs_main_stateFlags.unk20 != 0) || (vs_main_stateFlags.unk40 != 0))
                    && (var_t0->unk6 < 16)) {
                    return NULL;
                } else {
                    return var_t0;
                }
            }
        }
    }
    return NULL;
}

func_8008D710_t* func_8008D508(int arg0, int arg1, int arg2)
{
    int temp_t1;
    func_8008D710_t* var_a3;
    int i;

    var_a3 = D_800F1BF8.unkAC;
    do {
        if (var_a3 != NULL) {
            temp_t1 = D_800F1BF8.unk4C / 564;
            for (i = 0; i < temp_t1; ++i, ++var_a3) {
                if ((var_a3->unk0 == arg0) && (var_a3->unk2 == arg1)) {
                    if (var_a3->unk4 == arg2) {
                        return var_a3;
                    }
                }
            }
        }
    } while (0);
    return NULL;
}

void func_8008D594(int arg0) { D_800F1D6E = arg0; }

void func_8008D5A0(int arg0)
{

    if ((D_800F1BF8.unk48 / 184) != 0) {
        if (arg0 != 0) {
            func_8008E4DC(1);
        } else {
            func_8008E4DC(0);
        }
        D_800F1D68 = arg0;
    }
}

void func_8008D5FC(func_8008C1C8_t* arg0)
{
    if (arg0->unk0.unkB == 0) {
        arg0->unk0.unkB = 1;
        if (arg0->unk0.unk8.s16 == 0) {
            arg0->unk0.unkA = 0x14;
            func_8008C070(2, arg0);
            return;
        }
        func_8008D658(arg0);
    }
}

void func_8008D658(func_8008C1C8_t* arg0)
{
    func_8008B764_t* temp_v0;

    if (arg0->unk0.unk8.s16 == 0) {
        vs_main_playSfxDefault(0x7E, 0x3B);
        vs_main_playSfxDefault(0x7E, 0x3C);
    } else {
        vs_main_playSfxDefault(0x7E, 0x3D);
        vs_main_playSfxDefault(0x7E, 0x3E);
    }
    func_8009291C(arg0->unk0.unk6);
    arg0->unk0.unkB = 0;
    arg0->unk0.unk8.s16 = arg0->unk0.unk8.s16 == 0;
    temp_v0 = func_8008B764(arg0->unk0.unk0, arg0->unk0.unk2, arg0->unk0.unk4);
    if (temp_v0 != NULL) {
        temp_v0->unk0_10 = arg0->unk0.unk8.s16 * 5;
    }
}

void func_8008D710(void)
{
    func_8008B764_t* temp_s0;
    func_8008D710_t* var_s3;
    int temp_s4;
    int i;

    if (D_800F1BF8.unkAC != NULL) {

        var_s3 = D_800F1BF8.unkAC;
        temp_s4 = D_800F1BF8.unk4C / 564;

        for (i = 0; i < temp_s4; ++i, ++var_s3) {
            temp_s0 = func_8008B764(
                (u_int)var_s3->unk0, (u_int)var_s3->unk2, (int)var_s3->unk4);
            if (func_800BEBF4((short)(var_s3->unk10 + 0x3C0))) {
                var_s3->unk8 = 1;
                func_80093824(var_s3->unk6);
                if (temp_s0 != NULL) {
                    temp_s0->unk0_10 = 5;
                }
            } else {
                var_s3->unk8 = 0;
                if (temp_s0 != NULL) {
                    temp_s0->unk0_10 = 0;
                }
            }
        }
    }
}

void func_8008D820(u_int* arg0, func_80103530_t* arg1)
{
    ++arg0;
    arg1->unk0 = arg0[0];
    ++arg0;

    if (arg1->unk0 & 8) {
        arg1->unk4 = (RECT*)(arg0 + 1);
        arg1->unk8 = (u_long*)arg0 + 3;
        arg0 += arg0[0] >> 2;
    } else {
        arg1->unk4 = NULL;
        arg1->unk8 = NULL;
    }

    arg1->unkC = (RECT*)(arg0 + 1);
    arg1->unk10 = (u_short*)arg0 + 6;
}

int _getDoorId(int door)
{
    int* temp_v1;

    if (D_800F1BF8.unk9C != NULL) {
        temp_v1 = (int*)D_800F1BF8.unk9C + (D_800F1BF8.unk9C->roomCount * 3 + 1);
        temp_v1 = temp_v1 + ((*temp_v1 * 2) + 1);
        temp_v1 = temp_v1 + ((*temp_v1) + 1);
        temp_v1 = temp_v1 + ((*temp_v1) + 1);
        temp_v1 = temp_v1 + ((*temp_v1) + 1);
        temp_v1 = temp_v1 + ((*temp_v1) + 1);
        if ((door < *temp_v1++) && (door >= 0)) {
            temp_v1 += door;
            return ((char*)temp_v1)[1];
        }
    }
    return -1;
}

void _setDoorEntered(int arg0)
{
    int temp_a3;
    int i;

    vs_battle_doorEntered = arg0;

    if (D_800F1BF8.unk9C != NULL) {
        int* temp_v1 = (int*)D_800F1BF8.unk9C;
        temp_v1 += D_800F1BF8.unk9C->roomCount * 3 + 1;
        temp_v1 = temp_v1 + ((*temp_v1 * 2) + 1);
        temp_v1 = temp_v1 + ((*temp_v1) + 1);
        temp_v1 = temp_v1 + ((*temp_v1) + 1);
        temp_v1 = temp_v1 + ((*temp_v1) + 1);
        temp_v1 = temp_v1 + ((*temp_v1) + 1);
        temp_a3 = *temp_v1++;

        for (i = 0; i < temp_a3; ++i) {
            if (i == arg0) {
                ((char*)temp_v1)[2] |= 0x10;
            }
            ++temp_v1;
        }
    }
}

short func_8008DA24(int arg0, int arg1)
{
    D_800F1C60_t* temp_s4;
    int temp_fp;
    int temp_s0_2;
    int temp_s0_3;
    int temp_s7;
    int temp_v0;
    int temp_v0_2;
    int var_s0;
    int var_s1;
    int var_s3;
    int var_s5;
    int var_v0;
    int var_v0_3;
    int v;
    int temp_s6 = 0x8000;

    if (D_800F1BF8.unk68 != NULL) {
        temp_s7 = arg0;
        temp_s7 = temp_s7 & 0x1F;
        arg0 >>= 5;
        temp_fp = arg1 & 0x1F;
        arg1 >>= 5;
        temp_s4 = D_800F1BF8.unk68;

        if (((arg0 >> 2) >= (u_int)temp_s4->unk0)
            || ((arg1 >> 2) >= (u_int)temp_s4->unk2)) {
            return -0x8000;
        }

        temp_s6 = func_80099514(arg0, arg1, 0);
        var_s5 = (temp_s4->unk4 - ((temp_s6 & 0x7F) * 2)) * 8;

        var_s3 = temp_s7 < 0x10 ? arg0 - 1 : arg0 + 1;
        var_s1 = arg1 - 1;

        if (temp_fp >= 0x10) {
            var_s1 = arg1 + 1;
        }

        if ((var_s3 >> 2) < (u_int)temp_s4->unk0) {
            var_s3 = (temp_s4->unk4 - ((func_80099514(var_s3, arg1, 0) & 0x7F) * 2)) * 8;
            var_v0 = var_s3 - var_s5;
            if (ABS(var_v0) >= 0x40) {
                var_s3 = var_s5;
            }
        } else {
            var_s3 = var_s5;
        }

        if ((var_s1 >> 2) < (u_int)temp_s4->unk2) {
            var_s1 = (temp_s4->unk4 - ((func_80099514(arg0, var_s1, 0) & 0x7F) * 2)) * 8;
            var_v0 = var_s1 - var_s5;
            if (ABS(var_v0) >= 0x40) {
                var_s1 = var_s5;
            }
        } else {
            var_s1 = var_s5;
        }

        var_s0 = temp_s7 - 0x10;
        v = ABS(var_s0);
        var_v0_3 = temp_fp - 0x10;

        temp_s0_2 = v | (ABS(var_v0_3) << 0x10);
        temp_s0_3 = NormalClip(0, 0x20, temp_s0_2);
        temp_v0 = NormalClip(0, temp_s0_2, 0x200000);

        temp_v0_2 = 0x400 - temp_v0;
        temp_v0_2 -= temp_s0_3;

        if (temp_v0_2 >= 0) {
            temp_v0_2 = (var_s1 * temp_s0_3) + (var_s3 * temp_v0) + (var_s5 * temp_v0_2);
            var_s5 = temp_v0_2 / 1024;
        }
        temp_s6 = (var_s5 & 0x7FFF) | ((temp_s6 & 0x80) << 8);
    }
    return temp_s6;
}

short func_8008DC7C(int arg0, int arg1)
{
    D_800F1C60_t* temp_s0;
    int var_a2;

    temp_s0 = D_800F1BF8.unk68;
    var_a2 = 0x8000;
    if ((temp_s0 != NULL) && ((u_int)(arg0 >> 7) < temp_s0->unk0)
        && ((u_int)(arg1 >> 7) < temp_s0->unk2)) {
        var_a2 = func_80099514(arg0 >> 5, arg1 >> 5, 0);
        var_a2 = (((temp_s0->unk4 - ((var_a2 & 0x7F) * 2)) * 8) & 0x7FFF)
               | ((var_a2 & 0x80) << 8);
    }
    return var_a2;
}

short func_8008DD0C(int arg0, int arg1)
{
    D_800F1C60_t* temp_s0;
    int var_a2;
    int temp_v1;
    int new_var;

    temp_s0 = D_800F1BF8.unk68;
    var_a2 = 0;
    new_var = 8;
    if ((D_800F1BF8.unk68 != NULL) && ((arg0 >> 7) < (u_int)temp_s0->unk0)
        && ((arg1 >> 7) < (u_int)temp_s0->unk2)) {
        var_a2 = func_80099514(arg0 >> 5, arg1 >> 5, 1);
        temp_v1 = (temp_s0->unk4 - ((var_a2 & 0x7F) * 2)) * new_var;
        if (temp_v1 > 0) {
            var_a2 = 0xF810;
        } else {
            var_a2 = (temp_v1 & 0x7FFF) | ((var_a2 & 0x80) << new_var);
        }
    }
    return var_a2;
}

int func_8008DDA8(int arg0, int arg1)
{
    int sp10 = 0x80008000;
    short* new_var = (short*)&sp10;

    D_800F1C60_t* temp_s2 = D_800F1BF8.unk68;

    if ((temp_s2 != NULL) && ((u_int)(arg0 >> 7) < temp_s2->unk0)) {
        if ((u_int)(arg1 >> 7) < temp_s2->unk2) {
            int temp_v1;
            int temp_a3 = func_80099514(arg0 >> 5, arg1 >> 5, 0);
            temp_a3 = (((temp_s2->unk4 - ((temp_a3 & 0x7F) * 2)) * 8) & 0x7FFF)
                    | ((temp_a3 & 0x80) << 8);
            new_var[0] = temp_a3;
            temp_a3 = func_80099514(arg0 >> 5, arg1 >> 5, 1);
            temp_v1 = temp_s2->unk4 - (temp_a3 & 0x7F) * 2;
            temp_v1 *= 8;
            if (temp_v1 > 0) {
                temp_a3 = 0xF810;
            } else {
                temp_v1 &= 0x7FFF;
                temp_a3 = temp_v1 | ((temp_a3 & 0x80) << 8);
            }
            new_var[1] = temp_a3;
        }
    }
    return sp10;
}

void func_8008DEAC(D_800F1910_t2* arg0, int arg1)
{
    if (arg0 == NULL) {
        D_800F1910_t2* var_a2 = D_800F1BF8.unk84;
        if (var_a2 != NULL) {
            int i;
            int temp_a3 = D_800F1BF8.unk24 / 12;
            for (i = 0; i < temp_a3; ++i) {
                var_a2->unkA = arg1;
                ++var_a2;
            }
        }
    } else {
        arg0->unkA = arg1;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008DF14);

void func_8008E19C(int arg0, int arg1, int arg2, int arg3)
{
    int i;
    char(*var_t0)[4];
    void* p;

    D_800E8594.unk0 = arg0 + 0x80;
    D_800E8594.unk4 = arg1 + 0x80;
    D_800E8594.unk2 = arg2;

    var_t0 = D_800E8594.unkC;
    for (i = 0; i < 3;) {
        ++i;
        (*var_t0)[0] = arg3;
        (*var_t0)[1] = arg3;
        (*var_t0)[2] = arg3;
        ++var_t0;
    }
    var_t0 += 3;

    (*var_t0)[0] = arg3;
    (*var_t0)[1] = arg3;
    (*var_t0)[2] = arg3;
    p = D_800E85A0;
    func_8009723C(p - 0x58, D_800F19C8);
}

void func_8008E224(int arg0, int arg1)
{
    int* temp_v0;
    D_800F1CA0_t* temp_s0 = D_800F1BF8.unkA8;

    if (temp_s0 != NULL) {
        temp_s0 = &D_800F1BF8.unkA8[arg0];
        temp_s0->unk0_9 = arg1 - 1;
        temp_v0 = func_8009195C(temp_s0->unk0_0);
        if (temp_v0 != NULL) {
            if (!temp_s0->unk0_9) {
                *temp_v0 &= ~0x100;
            } else {
                *temp_v0 |= 0x100;
            }
        }
    }
}

void* func_8008E2D4(int arg0)
{
    D_800F1CA0_t* temp_v1 = D_800F1BF8.unkA8;

    if (D_800F1BF8.unkA8 != NULL) {
        temp_v1 = &D_800F1BF8.unkA8[arg0];
        return ((char*)temp_v1) + 8 + temp_v1->unk0_27 * 16;
    }
    return NULL;
}

u_int func_8008E320(int arg0)
{
    D_800F1CA0_t* temp_v1 = D_800F1BF8.unkA8;
    if (D_800F1BF8.unkA8 != NULL) {
        temp_v1 = &D_800F1BF8.unkA8[arg0];
        if (temp_v1->unk4_0 == 1) {
            return temp_v1->unk4_16;
        }
    }
    return -1;
}

func_8008D710_t* func_8008E370(int* arg0)
{
    if (D_800F1BF8.unkAC != 0) {
        *arg0 = D_800F1BF8.unk4C / 564;
        return D_800F1BF8.unkAC;
    }
    *arg0 = 0;
    return NULL;
}

func_8008C1C8_t* func_8008E3B8(int* arg0)
{
    if (D_800F1BF8.unk88 != 0) {
        *arg0 = D_800F1BF8.unk28 / 20;
        return D_800F1BF8.unk88;
    }
    *arg0 = 0;
    return 0;
}

D_800F1910_t2* func_8008E400(int* arg0)
{
    if ((vs_main_stateFlags.unkF[0x11] != 0) || (vs_main_stateFlags.unkF[0x31] != 0)) {
        *arg0 = 0;
        return NULL;
    }
    if (D_800F1BF8.unk84 != NULL) {
        *arg0 = D_800F1BF8.unk24 / 12;
        return D_800F1BF8.unk84;
    }
    *arg0 = 0;
    return NULL;
}

int func_8008E470(void) { return D_800F1BF8.unkB0 < 1; }

void func_8008E480(int arg0)
{
    func_800938AC();
    func_800918E8(arg0);
}

short func_8008E4AC(void) { return D_800F1BF8.unk8C->unk56; }

char func_8008E4C4(void) { return D_800F1BF8.unk8C->unk32; }

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", D_80068BEC);

void func_8008E4DC(int arg0)
{
    static u_short const D_80068BFC[0x10] = {
        0x10,
        1,
        0x865,
        0xC66,
        0x869,
        0xCA9,
        0x88D,
        0x10AD,
        0xCB1,
        0x14D1,
        0xCD5,
        0x14F5,
        0xCF9,
        0x113A,
        0x199B,
        0x21FC,
    };

    D_800F1CA0_t* var_s0;
    int temp_s2;
    int i;

    if (D_800F1D6F != arg0) {
        if (arg0 != 0) {
            func_80048A64(D_80068BFC, 2, 0x30, 0x10);
        } else {
            func_80048A64(D_800F1BA8 + 0x230, 2, 0x30, 0x10);
        }

        var_s0 = D_800F1BF8.unkA8;
        temp_s2 = D_800F1BF8.unk48 / 184;

        for (i = 0; i < temp_s2; ++i) {
            if (var_s0->unk0_12) {
                func_80093914(var_s0->unk0_0);
            }
            ++var_s0;
        }
        if (D_800F1BF8.unk8C != NULL) {
            if (D_800F1BF8.unk8C->unk2C >= 0) {
                func_800936F8(D_800F1BF8.unk8C->unk2C);
            }
        }
        D_800F1D6F = !D_800F1D6F;
    }
}

int vs_battle_getMapCompletion(void)
{
    int i;
    int j;
    int value;

    if (vs_main_mapStatus.roomFlags[1] & 0x800000) {
        vs_main_mapStatus.roomFlags[1] |= 0x400000;
    }
    value = 0;
    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 32; ++j) {
            int v = 1;
            if (vs_main_mapStatus.roomFlags[i] & vs_battle_mapCompletionFlags[i]
                & (v << j)) {
                ++value;
            }
        }
    }
    return (value * 100) / 361;
}

void func_8008E6A8(int (*arg0)[136])
{
    if (D_800F1BF8.unkAC != NULL) {
        vs_main_memcpy(&D_800F1BF8.unkAC->unk14, arg0, sizeof D_800F1BF8.unkAC->unk14);
    }
}

static inline char get_D_800E84AC(int arg0, int arg1) { return D_800E84AC[arg0][arg1]; }

void func_8008E6DC(int arg0)
{
    int mapId;
    int zoneId;
    int i;
    vs_battle_room* room;

    room = D_800F1BF8.unk9C->rooms;
    zoneId = room->zoneId;
    mapId = room->mapId;

    for (i = D_800E849C[arg0]; i < D_800E849C[arg0 + 1]; ++i) {
        if (((get_D_800E84AC(i, 0) == zoneId) && (get_D_800E84AC(i, 1) == mapId))
            || ((get_D_800E84AC(i, 2) == zoneId) && (get_D_800E84AC(i, 3) == mapId))) {
            vs_main_stateFlags.unk186[i] = 1;
            return;
        }
    }
}

int func_8008E7BC(int arg0, int arg1, u_int arg2)
{
    int i;
    for (i = D_800E849C[arg2]; i < D_800E849C[arg2 + 1]; ++i) {
        if (((get_D_800E84AC(i, 0) == arg0) && (get_D_800E84AC(i, 1) == arg1))
            || ((get_D_800E84AC(i, 2) == arg0) && (get_D_800E84AC(i, 3) == arg1))) {
            return vs_main_stateFlags.unk186[i];
        }
    }
    return 0;
}

void func_8008E88C(void)
{
    D_800F1DAC = NULL;
    D_800F1DB0 = NULL;
    D_800F1DCC = NULL;
    D_800F1DD0 = NULL;
    D_800F1DD4 = NULL;
    D_800F1DC9 = 0;
    D_800F1DBC = -2;
    D_800F1DCA = 0;
    D_800F1DCB = 1;
    func_8008E938();
}

void func_8008E8F8(void)
{
    if (D_800F1DD4 != NULL) {
        vs_main_freeHeap(D_800F1DD4);
    }
    D_800F1DD4 = vs_main_allocHeap(0x800);
}

void func_8008E938(void)
{
    D_800F1C84_t* temp_s0;
    int i;

    D_800F1DB4 = 0;
    D_800F1DB6 = 0;
    D_800F1DB8 = 0x1000;
    D_800F1DBA = 0x1000;

    if (D_800F1BF8.unk8C != NULL) {

        temp_s0 = D_800F1BF8.unk8C;

        for (i = 1; i < 5; ++i) {
            if (temp_s0->unk0[0] != temp_s0->unk0[i]) {
                break;
            }
        }
        if ((i == 5) && (temp_s0->unk0[0] & 0xFFFFFF)) {
            D_800F1DC6 = 1;
        } else {
            D_800F1DC6 = 0;
            func_8008EB30(temp_s0->unk0);
        }
        if ((temp_s0->unk48[0].s32 == 0) && (temp_s0->unk48[1].s32 == 0)) {
            D_800F1C60_t* s = D_800F1BF8.unk68;
            if (s != NULL) {
                temp_s0->unk48[1].s16[0] = s->unk0 * 4;
                temp_s0->unk48[1].s16[1] = s->unk2 * 4;
            } else {
                temp_s0->unk48[1].s16[0] = 0x20;
                temp_s0->unk48[1].s16[1] = 0x20;
            }
        }
        temp_s0->unk48[0].s16[0] *= 128;
        temp_s0->unk48[0].s16[1] *= 128;
        temp_s0->unk48[1].s16[0] *= 128;
        temp_s0->unk48[1].s16[1] *= 128;
        temp_s0->unk48[1].s16[0] -= temp_s0->unk48[0].s16[0];
        temp_s0->unk48[1].s16[1] -= temp_s0->unk48[0].s16[1];
    }
}

int func_80090C2C(int);

int func_8008EA90(int arg0)
{
    D_800F1C84_t* new_var2 = D_800F1BF8.unk8C;

    if (new_var2 != 0) {
        D_800F1C84_t* new_var4 = new_var2;
        new_var2 = D_800F1BF8.unk8C;
        if ((arg0 == 0) || (new_var4->unk34 != 1)) {
            func_80090C2C(new_var4->unk34);
        } else {
            func_80090C2C(0);
        }
        return 1;
    }
    return 0;
}

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

int* func_8008EB24(void) { return D_800F1D78; }

void func_8008EB30(int* arg0)
{
    int i;
    int* var_a0;

    vs_main_memcpy(D_800F1D78, arg0, sizeof D_800F1D78);

    var_a0 = D_80068C1C;

    var_a0 += 2;
    var_a0[0] = (*arg0++ & 0xFFFFFF) | 0x30000000;
    ++var_a0;

    for (i = 0; i < 8; ++i) {
        var_a0 += 2;
        var_a0[0] = (*arg0 & 0xFFFFFF) | 0x30000000;
        ++var_a0;
    }

    ++arg0;

    for (i = 0; i < 16; ++i) {
        var_a0 += 2;
        var_a0[0] = (*arg0 & 0xFFFFFF) | 0x30000000;
        ++var_a0;
    }

    ++arg0;

    for (i = 0; i < 8; ++i) {
        var_a0 += 2;
        var_a0[0] = (*arg0 & 0xFFFFFF) | 0x30000000;
        ++var_a0;
    }

    var_a0[2] = (arg0[1] & 0xFFFFFF) | 0x30000000;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008EC48);

int func_8008EFCC(int arg0)
{
    u_short* temp_s0;
    int new_var;
    vs_main_CdFile* temp_s2;
    vs_main_CdFile* temp_s3;
    int var_a0;
    int var_s0;

    temp_s0 = D_800F1BF8.unkA0;
    D_800F1DC8 = arg0;
    if (temp_s0 != 0) {
        D_800F1DBE = *temp_s0;
        if (func_8007DFF0(D_800F1DC8, D_800F1DBE, 5) != 0) {
            new_var = 0x800;
            temp_s2 = (vs_main_CdFile*)(temp_s0 + 0x20);
            temp_s3 = (vs_main_CdFile*)(temp_s0 + 0x42);
            var_a0 = temp_s2->size;
            var_s0 = temp_s3->size;
            if ((var_a0 & 0x7FF) != 0) {
                var_a0 = (var_a0 + new_var) - (var_a0 & 0x7FF);
            }
            if ((var_s0 & 0x7FF) != 0) {
                var_s0 = (var_s0 + new_var) - (var_s0 & 0x7FF);
            }
            D_800F1DD0 = vs_main_allocHeapR(var_a0);
            D_800F1DCC = vs_main_allocHeapR(var_s0);
            if ((D_800F1DD0 == 0) || (D_800F1DCC == 0)) {
                return 0;
            }
            D_800F1DAC = vs_main_allocateCdQueueSlot(temp_s2);
            D_800F1DB0 = vs_main_allocateCdQueueSlot(temp_s3);
            vs_main_cdEnqueue(D_800F1DAC, D_800F1DD0);
            vs_main_cdEnqueue(D_800F1DB0, D_800F1DCC);
            return 1;
        }
    }
    D_800F1DAC = 0;
    D_800F1DB0 = 0;
    return 0;
}

int func_8008F0FC(void)
{
    if ((D_800F1DAC != NULL) && (D_800F1DAC->state == 4)) {
        func_80103530_t sp10;

        *D_800F1DD0 = 0x10;
        func_8008D820(D_800F1DD0, &sp10);
        if (sp10.unk10 != NULL) {
            sp10.unkC->x = (sp10.unkC->x & 0x3F) + ((D_800F1DC8 & 0xF) << 6);
            sp10.unkC->y = (char)sp10.unkC->y + ((D_800F1DC8 & 0x10) * 0x10);
            LoadImage(sp10.unkC, (u_long*)sp10.unk10);
        }
        if (sp10.unk8 != NULL) {
            func_80048A64((void*)sp10.unk8, 0xE, 0, 0x100);
        }
        vs_main_freeCdQueueSlot(D_800F1DAC);
        D_800F1DAC = NULL;
        return 0;
    }

    if ((D_800F1DB0 != NULL) && (D_800F1DB0->state == 4)) {
        vs_main_freeHeapR(D_800F1DD0);
        D_800F1DD0 = NULL;
        vs_main_freeCdQueueSlot(D_800F1DB0);
        D_800F1DB0 = NULL;
        return 1;
    }
    return 0;
}

int func_8008F234(void)
{
    D_800F1DC9 = 0;
    if (D_800F1DCC != NULL) {
        D_800F1DC9 = 0;
        func_8007E0A8(D_800F1DC8, D_800F1DBE, 5);
        vs_main_freeHeapR(D_800F1DCC);
        D_800F1DCC = NULL;
        return 1;
    }
    return 0;
}

void func_8008F29C(int arg0, int arg1)
{
    int i;
    D_800F1DD4_t* var_s1 = D_800F1DD4;
    D_800F1DCA = arg1;
    D_800F1DC2 = arg0;
    D_800F1DC0 = arg0;

    for (i = 0; i < arg0; ++i) {
        func_80090A1C(var_s1);
        ++var_s1;
    }
}

void func_8008F30C(int arg0, int arg1)
{
    D_800F1DD4_t* var_s1;
    int i;

    var_s1 = D_800F1DD4;
    D_800F1DC7 = 0;
    D_800F1DCA = arg1;
    D_800F1DC2 = arg0;
    D_800F1DC0 = arg0;

    for (i = 0; i < arg0; ++i, ++var_s1) {
        var_s1->unkF = rand() & 0x7F;
        var_s1->unk0 = rand() % 320;
        var_s1->unk2 = rand() % 240;
        var_s1->unk4 = rand() % 256;
        var_s1->unk8 = -1;
        var_s1->unkA = -1;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008F440);

void func_8008F9A4(int arg0, int arg1)
{
    int i;
    D_800F1DD4_t* var_s1 = D_800F1DD4;
    D_800F1DCA = arg1;
    D_800F1DC2 = arg0;
    D_800F1DC0 = arg0;

    for (i = 0; i < arg0; ++i) {
        func_8008FA14(var_s1);
        ++var_s1;
    }
}

void func_8008FA14(D_800F1DD4_t* arg0)
{
    D_800F1C84_t* temp_s0 = D_800F1BF8.unk8C;

    arg0->unk0 = temp_s0->unk48[0].s16[0] + (rand() % temp_s0->unk48[1].s16[0]);
    arg0->unk4 = temp_s0->unk48[0].s16[1] + (rand() % temp_s0->unk48[1].s16[1]);
    arg0->unk2 = (rand() % 512) + 0x200;
    arg0->unkC = 0;
    arg0->unkF = (rand() & 0xF) + 8;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008FAC8);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_8008FDC4);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", func_80090434);

void func_80090A1C(D_800F1DD4_t* arg0)
{
    D_800F1C84_t* temp_s0;

    temp_s0 = D_800F1BF8.unk8C;
    if (temp_s0 != NULL) {
        arg0->unk0 = temp_s0->unk48[0].s16[0] + (rand() % temp_s0->unk48[1].s16[0]);
        arg0->unk4 = temp_s0->unk48[0].s16[1] + (rand() % temp_s0->unk48[1].s16[1]);
    } else {
        arg0->unk0 = rand() % 4096;
        arg0->unk4 = rand() % 4096;
    }
    arg0->unk2 = (rand() % 512) - 2560;
    arg0->unkE = 2;
    arg0->unkC = 0;
    arg0->unkD = 0;
    arg0->unkF = rand() & 0x7F;
}

void func_80090B28(void)
{
    int temp_v1;
    int var_s0;
    int var_v0;

    var_s0 = rsin(D_800F1D98[5]);
    temp_v1 = rcos(D_800F1D98[4]);
    var_s0 *= D_800F1D98[6];
    if (var_s0 < 0) {
        var_s0 += 0xFFF;
    }
    var_v0 = (var_s0 >> 0xC) * temp_v1;
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }
    D_800F1D98[0] = (var_v0 >> 0xC);
    var_s0 = rcos(D_800F1D98[5]);
    temp_v1 = rcos(D_800F1D98[4]);
    var_s0 = -var_s0;
    var_s0 *= D_800F1D98[6];
    if (var_s0 < 0) {
        var_s0 += 0xFFF;
    }
    var_v0 = (var_s0 >> 0xC) * temp_v1;
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }
    D_800F1D98[2] = (var_v0 >> 0xC);
    var_v0 = rsin(D_800F1D98[4]) * D_800F1D98[6];
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }
    D_800F1D98[1] = (var_v0 >> 0xC);
}

INCLUDE_RODATA("build/src/BATTLE/BATTLE.PRG/nonmatchings/146C", D_80068C1C);
