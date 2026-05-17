#include "common.h"
#include "build/src/include/lbas.h"
#include "../../SLUS_010.40/main.h"
#include "../BATTLE.PRG/146C.h"
#include "../BATTLE.PRG/2842C.h"
#include "../BATTLE.PRG/30D14.h"
#include "../BATTLE.PRG/4A0A8.h"
#include "../BATTLE.PRG/573B8.h"
#include "../BATTLE.PRG/5BF94.h"
#include "../BATTLE.PRG/6E644.h"
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
void _initScriptFunctionTable(void);
void func_800F9CCC(void);
void func_800FA7B0(void);

static vs_battle_charInitData D_800FAB18 = {
#include "build/assets/BATTLE/INITBTL.PRG/charInit.h"
};

extern int D_800F1874;
extern int D_800F18F4;
extern int D_800F190C;
extern int D_800F1968;
extern int D_800F196C;
extern DR_STP D_800F1970[];
extern DR_STP D_800F1988[];
extern void* D_800F19CC;

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
            vs_main_skills[i].unlocked = 1;
        } else {
            vs_main_skills[i].unlocked = 0;
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
    vs_main_loadClut((u_short*)p_hdr + 2, 0xF, 0, p_hdr->x);

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

int func_800F9AB8(void) { return vs_battle_getEmptyModelDataSlot(); }

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
    temp_s0->strength = s1->strength;
    temp_s0->totalStrength = s1->totalStrength;
    temp_s0->intelligence = s1->intelligence;
    temp_s0->totalIntelligence = s1->totalIntelligence;
    temp_s0->agility = s1->agility;
    temp_s0->totalAgility = s1->totalAgility;
    temp_s0->risk = s1->risk;
    temp_s0->unk954 = s1->flags;

    func_80086FA8(s1->unk1C, temp_s0);

    for (i = 0; i < 8; ++i) {
        temp_s0->unk94C[i] = s1->unk20[i];
    }

    for (i = 0; i < 6; ++i) {
        temp_s0->bodyParts[i].hp = s1->bodyParts[i].hp;
        temp_s0->bodyParts[i].maxHp = s1->bodyParts[i].maxHp;

        for (j = 0; j < 4; ++j) {
            temp_s0->bodyParts[i].types[j] = s1->bodyParts[i].types[j];
        }

        for (j = 0; j < 8; ++j) {
            temp_s0->bodyParts[i].affinities[j] = s1->bodyParts[i].affinities[j];
        }
    }

    vs_battle_characterState->unk20 = s1->unk7C;

    if (s1->unk7C & 1) {
        func_8009D934(0, 1, 2);
        func_800CB660(1);
    }

    D_80060068.unk0.unk0 = 0;
    vs_battle_cameraCurrentSpherical.delta.pitch = s1->unk80;
    vs_battle_cameraCurrentSpherical.initialDistance = s1->unk84;
}

void func_800F9CCC(void)
{
    int i;
    int bladeIndex;
    int shieldIndex;
    int j;
    int shieldWepId;
    int bladeWepId;
    int bladeMaterial;
    int shieldMaterial;

    vs_battle_modelData_flags sp20;

    sp20.unk0_0 = 4;
    sp20.unk0_16 = 2;
    sp20.unk0_8 = 0;
    sp20.unk0_24 = 128;

    bladeWepId = 0;
    bladeIndex = 0;

    for (i = 0; i < 8; ++i) {
        if (vs_battle_inventory.weapons[i].isEquipped != 0) {
            bladeIndex = i + 1;
            bladeWepId =
                vs_battle_inventory.blades[vs_battle_inventory.weapons[i].blade - 1]
                    .wepId;
            bladeMaterial =
                vs_battle_inventory.blades[vs_battle_inventory.weapons[i].blade - 1]
                    .material;
        }
    }

    shieldWepId = 0;
    shieldIndex = 0;

    for (i = 0; i < 8; ++i) {
        if (vs_battle_inventory.shields[i].isEquipped != 0) {
            shieldIndex = i + 1;
            shieldWepId = vs_battle_inventory.shields[i].base.wepId;
            shieldMaterial = vs_battle_inventory.shields[i].base.material;
        }
    }

    vs_battle_characterState = func_800774FC(
        0, 0, bladeWepId, bladeMaterial, shieldWepId, shieldMaterial, &sp20, 0);

    func_80076F24(0, &D_800FAB18, 0x10, 0, 0x80, 0);
    if (bladeIndex != 0) {
        vs_battle_applyWeapon(&vs_battle_characterState->unk3C->weapon,
            &vs_battle_inventory.weapons[bladeIndex - 1]);
    } else {
        vs_battle_applyWeapon(&vs_battle_characterState->unk3C->weapon, NULL);
    }

    vs_battle_characterState->unk3C->currentRange =
        vs_battle_characterState->unk3C->weapon.range.range
        + vs_battle_characterState->unk3C->reach;
    vs_battle_characterState->unk3C->unk39 =
        vs_battle_characterState->unk3C->weapon.range.unk1
        + vs_battle_characterState->unk3C->reach;
    vs_battle_characterState->unk3C->unk3A =
        vs_battle_characterState->unk3C->weapon.range.unk2
        + vs_battle_characterState->unk3C->reach;
    vs_battle_characterState->unk3C->currentAttackShapeAngle =
        vs_battle_characterState->unk3C->weapon.range.attackShapeAngle;
    vs_battle_characterState->unk3C->unk3B_0 = 1;

    if (shieldIndex != 0) {
        vs_battle_applyShield(&vs_battle_characterState->unk3C->shield,
            &vs_battle_inventory.shields[shieldIndex - 1]);
    } else {
        vs_battle_applyShield(&vs_battle_characterState->unk3C->shield, NULL);
    }

    for (i = 0; i < 6; ++i) {
        vs_battle_applyArmor(&vs_battle_characterState->unk3C->bodyParts[i].armor, NULL);

        for (j = 0; j < 16; ++j) {
            if (vs_battle_inventory.armor[j].bodyPart == i + 1) {
                vs_battle_applyArmor(&vs_battle_characterState->unk3C->bodyParts[i].armor,
                    &vs_battle_inventory.armor[j]);
            }
        }
    }

    vs_battle_applyAccessory(&vs_battle_characterState->unk3C->accessory, NULL);

    for (i = 0; i < 16; ++i) {
        if (vs_battle_inventory.armor[i].bodyPart == 7) {
            vs_battle_applyAccessory(&vs_battle_characterState->unk3C->accessory,
                &vs_battle_inventory.armor[i]);
        }
    }

    vs_battle_nop0(vs_battle_characterState->unk3C);

    if (D_80060068.unk0.unk0 != 0) {
        func_800F9AD8();
    }

    func_800F9AB0();

    while (func_800F9AB8() != 0) {
        func_8009967C();
        vs_main_gametimeUpdate(0);
    }
}

static void _initTransitionState(void)
{
    RECT sp18;
    memset(&sp18, 0, sizeof sp18);

    SetPolyF4(&vs_battle_screenTransitionPolyF4[0]);
    setRGB0(&vs_battle_screenTransitionPolyF4[0], 0, 0, 0);
    setXY4(&vs_battle_screenTransitionPolyF4[0], 0, 0, 320, 0, 0, 240, 320, 240);
    SetSemiTrans(&vs_battle_screenTransitionPolyF4[0], 1);
    vs_battle_screenTransitionPolyF4[1] = vs_battle_screenTransitionPolyF4[0];

    SetPolyF4(&vs_battle_screenTransitionWipePolyF4[0].covered);
    setRGB0(&vs_battle_screenTransitionWipePolyF4[0].covered, 0, 0, 0);
    SetSemiTrans(vs_battle_screenTransitionWipePolyF4, 0);
    setRGB0(&vs_battle_screenTransitionWipePolyF4[0].covered, 0, 0, 1);
    vs_battle_screenTransitionWipePolyF4[0].edge =
        vs_battle_screenTransitionWipePolyF4[0].covered;
    vs_battle_screenTransitionWipePolyF4[1] = vs_battle_screenTransitionWipePolyF4[0];

    SetPolyG4(&vs_battle_screenTransitionEdgePolyG4[0]);
    setRGB0(&vs_battle_screenTransitionEdgePolyG4[0], 255, 255, 255);
    setRGB2(&vs_battle_screenTransitionEdgePolyG4[0], 255, 255, 255);
    setRGB1(&vs_battle_screenTransitionEdgePolyG4[0], 0, 0, 0);
    setRGB3(&vs_battle_screenTransitionEdgePolyG4[0], 0, 0, 0);
    setXY4(&vs_battle_screenTransitionEdgePolyG4[0], 0, 0, 320, 0, 0, 240, 320, 240);
    SetSemiTrans(vs_battle_screenTransitionEdgePolyG4, 1);
    vs_battle_screenTransitionEdgePolyG4[1] = vs_battle_screenTransitionEdgePolyG4[0];

    SetDrawMode(vs_battle_screenTransitionDrMode, 0, 1, getTPage(0, 2, 0, 0), &sp18);
    vs_battle_screenTransitionDrMode[1] = vs_battle_screenTransitionDrMode[0];

    vs_battle_screenTransitionAlpha = 255;
}

void func_800FA35C(void)
{
    int _0[2];
    RECT rect;
    VECTOR vector;
    int _1[6];
    int i;

    rect = (RECT) { 0, 0, 0x400, 0x200 };
    vector = (VECTOR) { 0x71C, 0x71C, 0x71C };

    DrawSync(0);
    DrawSync(0);
    vs_main_resetSound();
    vs_main_initHeap((vs_main_HeapHeader*)0x8010C000, 0xF2000);
    D_8005E0C0[1] = 0;
    D_8005E0C0[0] = NULL;
    D_80055C80[0] = vs_main_allocHeap(0x2088);
    D_80055C80[1] = vs_main_allocHeap(0x2088);
    SetDrawStp(&D_800F1970[0], 0);
    SetDrawStp(&D_800F1970[1], 0);
    SetDrawStp(&D_800F1988[0], 1);
    SetDrawStp(&D_800F1988[1], 1);
    vs_main_clutInit();
    _initTransitionState();
    func_8007D3F8();
    _initScriptFunctionTable();
    func_800CE64C();
    func_800FA6B8();
    func_800FA7B0();
    func_8007DF48();
    _loadSystemDat();
    func_800E6EAC();
    vs_main_resetPadAct();
    func_800F9818();
    _zoneContext.unk68 = 0;
    _zoneContext.unk38 = 0;
    _zoneContext.mapId = 0;
    _zoneContext.zndId = 0;
    _zoneContext.unk18 = 0;
    _zoneContext.mpdCdFile = NULL;
    _zoneContext.zndCdFile = NULL;
    _zoneContext.mpdData = NULL;
    _zoneContext.zndData = NULL;
    _zoneContext.musicSlot = 0;
    _zoneContext.musicId = 0;
    _zoneContext.unk30 = 1;
    _zoneContext.unk14 = 0;
    D_800F1AB0 = D_80061068;
    vs_battle_screenTransitionEffect = 0;
    vs_battle_screenTransitionStep = 4;
    vs_battle_screenTransitionSpeed = 8;
    vs_battle_screenTransitionWipeAngle = 0xC00;
    D_800F1968 = 0;
    _lootListHead = NULL;
    D_800F1874 = 0;
    D_800F196C = 0;
    vs_gametime_tickspeed = 2;
    vs_main_projectionDistance = 0x200;
    vs_main_nearClip = 0x40;
    D_80050468.unk0 = 0;
    D_80050468.unk7 = 0;
    D_80050468.unk6 = 0;
    D_80050468.unk5 = 0;
    D_80050468.unk4 = 0;
    _zoneContext.unk68 = D_80061068.unk6_0 & 0x3FF;
    vs_battle_cameraTransition = NULL;
    func_80077EC4();
    _camera.t2.farClip = 0x1000;
    vs_battle_cameraCurrentSpherical.delta.pitch = 0x800;
    vs_battle_cameraCurrentSpherical.values.yaw = 0x800;
    vs_battle_cameraCurrentSpherical.values.pitch = -0x180;
    vs_battle_cameraCurrentSpherical.initialDistance = 0x600;
    vs_battle_cameraCurrentSpherical.values.distance = 0x600;
    vs_battle_cameraCurrentSpherical.delta.yaw = 0;
    vs_battle_cameraCurrentSpherical.delta.distance = 0;
    vs_battle_cameraCurrentSpherical.delta.mode = 1;
    vs_battle_cameraCurrentSpherical.unk24 = 0;

    func_8009FB64(&vector);

    for (i = 0; i < 16; ++i) {
        vs_battle_actors[i] = NULL;
    }

    func_800F9CCC();
    D_800F19CC = vs_main_allocHeapR(0x2C10);
    vs_main_bzero(D_800F19CC, 0x2C10);
    D_800F190C = 1;
    D_800F18F4 = 0;
    func_800760CC(0x140, 0xF0, vs_main_projectionDistance, 0, 0, 0);
}

void func_800FA6B8(void)
{
    vs_main_bzero(D_800F1CE0, 0x20);
    vs_main_bzero(&vs_battle_roomData, sizeof(vs_battle_roomData));
    vs_main_bzero(&D_800F1CC8, sizeof D_800F1CC8);
    vs_main_bzero(&vs_battle_menu9CursorMemory, sizeof vs_battle_menu9CursorMemory);
    vs_main_bzero(&vs_battle_manualDisplayState, sizeof(vs_battle_manualDisplayState));
    D_800F1BA8 = vs_main_allocHeap(0x800);
    D_800F1BAC = vs_main_allocHeap(sizeof *D_800F1BAC);
    D_800F1CBC = vs_main_allocHeap(0x80);
    vs_battle_doorEntered = -1;
    D_800F1BA4 = 0;
    D_800F1BB6 = 0;
    _submenuState = 0;
    vs_battle_sceneBuffer = NULL;
    D_800F1CD6 = 1;
    D_800F1CD4 = 8;
    func_8008E88C();
    func_8008B6B4();
    func_8008EB30(D_800F1CE0);
}
