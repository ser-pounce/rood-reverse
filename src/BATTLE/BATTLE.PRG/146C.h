#pragma once
#include "actor.h"
#include "charInit.h"
#include "hitEntity.h"
#include "objectData.h"
#include "src/SLUS_010.40/main.h"
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>

typedef struct {
    SVECTOR unk0;
    union {
        char u8[2];
        u_short u16;
    } unk8;
    u_char unkA;
    u_char unkB;
    u_short unkC;
    u_char unkE;
    u_char displayTextLen;
    short unk10;
    short unk12;
    signed char displayText[4];
} D_800F1BAC_t;

void func_80069C6C(int);
void func_8006CD60(u_int*, int, int);
void func_8006CDB8(int);
void func_8006CA20(int, SVECTOR*);
void func_8006CB04(int, SVECTOR*);
void func_8006C480(int, int);
void func_8006C4A4(int, int);
int func_8006C84C(int);
void func_8006CDD8(SVECTOR*);
void func_8006CE50(void);
void func_8006CE70(SVECTOR*);
void func_800760CC(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
void func_80076F24(
    int id, vs_battle_charInitData* arg1, int arg2, int arg3, int arg4, int arg5);
vs_battle_actor* func_800774FC(int arg0, int arg1, int bladeWepId, int bladeMaterial,
    int shieldWepId, int shieldMaterial, vs_battle_objectData_flags* arg6, int arg7);
void func_80077EC4(void);
int func_8007BD8C(int);
void func_8007A824(void* prim);
void func_8007B0FC(void);
void func_8007B104(void);
void func_8007B1B8(int, int, short, short, short);
void func_8007B29C(int, int, int, short, short, short);
void func_8007B344(int, int, short, short, short);
void func_8007B9A0(void);
void func_8007B9CC(void);
int func_8007B9FC(void);
void func_8007BA98(int, int, int, int);
void func_8007BBB8(int, int);
void func_8007BBD8(int, int, int);
void func_8007C4D4(void);
int func_8007C8F8(int);
void func_8007CE74(int);
void func_8007CEC0(void);
int func_8007CF80(int);
void func_8007BCCC(void);
void func_8007BD3C(int);
int func_8007BDD8(int);
int func_8007BE10(int);
void func_8007BE20(int, int);
void func_8007BEC4(int);
int func_8007BEE4(void);
void func_8007BF04(void);
int func_8007BF0C(void);
void func_8007BF2C(void);
void func_8007BF4C(void);
void func_8007BFC0(void);
void func_8007C050(void);
void func_8007C0AC(int, int);
int func_8007C218(int);
void func_8007C28C(int);
void func_8007C31C(void);
void func_8007C348(int, int);
int func_8007C398(void);
void func_8007C404(void);
void func_8007C424(void);
void func_8007C444(int, int, int);
void func_8007C460(int);
void func_8007C46C(int, int, int);
void func_8007C4AC(int, int, int);
void func_8007C580(_mpdRoomDoorSection_t*, int, int);
void func_8007C654(_mpdRoomDoorSection_t*, int, int);
void func_8007C8A4(int, int);
int func_8007C928(u_int arg0, int arg1, vs_battle_objectData_flags* arg2);
void func_8007CA20(int, int, int);
void func_8007CAA4(int);
void func_8007CB84(int, int wepId);
void func_8007CBBC(int);
void func_8007CBDC(int, int, int);
void vs_battle_loadEtm(int, int, int);
void func_8007CC4C(int);
void func_8007CC6C(int);
int func_8007CCAC(void);
int func_8007CF18(int);
int func_8007CFCC(int);
void func_8007CFF8(int, SVECTOR*);
int func_8007D03C(int);
int func_8007D08C(int, int);
int func_8007D15C(int);
void func_8007D1A8(int, int);
int vs_battle_isActionUnlocked(u_int);
void vs_battle_setActionUnlocked(u_int);
void func_8007D260(int arg0);
void func_8007D340(int);
void func_8007D3F8(void);
void func_8007DE88(VECTOR* arg0);
void func_8007DEA8(CVECTOR* arg0);
void func_8007DECC(VECTOR* arg0);
void func_8007DF48(void);
int func_8007E180(int arg0);
int func_8007E1C0(int arg0);
int vs_battle_itemIdIsInInventory(int);
int func_8008631C(int arg0, int arg1, int targetActor, int targetLimb, void* arg4);
int func_800863A4(int arg0, int arg1, int targetActor, int arg3, SVECTOR* arg4,
    SVECTOR* arg5, D_800F19CC_t2* arg6);
int func_80089104(void);
void func_8008B6B4(void);
int func_8008B808(int, int, int, int);
void vs_battle_setDoorEntered2(int arg0);
void func_8008C40C(void);
int func_8008C49C(int arg0, int arg1);
int func_8008D2C0(SVECTOR arg0[]);
void func_8008D594(int);
void func_8008D5A0(int);
short func_8008DA24(int arg0, int arg1);
short func_8008DC7C(int arg0, int arg1);
short func_8008DD0C(int arg0, int arg1);
int func_8008DDA8(int arg0, int arg1);
void func_8008E224(int, int);
int func_8008E470(void);
void func_8008E88C(void);
void func_8008EAE4(int, int);
void func_8008EAF8(int);
void func_8008EB04(int* arg0, int* arg1);
int func_8008EFCC(int);
int func_8008F0FC(void);
int func_8008F234(void);
int _getCollisionMapDimensions(int arg0 __attribute__((unused)));
void func_8008F29C(int arg0, int arg1);
void func_8008F30C(int arg0, int arg1);
void func_8008F440(void);
void func_8008F9A4(int arg0, int arg1);
void func_8008FAC8(void);
void func_8008FDC4(void);
void func_80090434(void);
void func_80090B28(void);
extern u_short D_800F1BA4;
extern u_short* D_800F1BA8;
extern D_800F1BAC_t (*D_800F1BAC)[32];
extern short D_800F1BB6;
extern DVECTOR* D_800F1CBC;
extern _mpdRoomDoorSection_t D_800F1CC8;
extern short D_800F1CD4;
extern char D_800F1CD6;
extern VECTOR D_800F1CE0[2];
extern void* D_800F4930;
extern DR_STP D_800F1970[];
extern DR_STP D_800F1988[];
