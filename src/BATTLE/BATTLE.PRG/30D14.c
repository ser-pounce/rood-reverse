#include "common.h"
#include "146C.h"
#include "30D14.h"
#include "38C1C.h"
#include "3A1A0.h"
#include "44F14.h"
#include "6E644.h"
#include "../SLUS_010.40/main.h"
#include "../SLUS_010.40/32154.h"
#include "build/src/include/lbas.h"
#include <libgte.h>
#include <libetc.h>
#include <memory.h>

typedef struct {
    u_char unk0;
    signed char unk1;
    short unk2;
    int unk4;
    int unk8;
    int unkC;
    u_char unk10;
    u_char unk11;
    u_char unk12;
    u_char unk13;
} func_8009AC24_t;

typedef struct {
    u_char unk0[0x1FE0];
    u_short unk1FE0;
} D_800F2458_t;

typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char unk3;
    int unk4;
    int unk8;
} func_800A0024_t;

typedef struct {
    int unk0;
    short unk4;
    u_char unk6;
} D_800F4770_t;

typedef struct {
    u_short unk0;
    u_short unk2;
    u_short unk4;
    u_char unk6;
} D_800F46A8_t;

typedef struct {
    u_char unk0[0x30];
    int* unk30;
} func_8004644C_t;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} D_800E8FB4_t;

void func_8008C49C(int, int);
int func_8009998C(vs_battle_objectData*);
void func_80099E7C(void*, int, int, int, int);
void* func_8009A028(int* arg0, void* arg1, int arg2);
int _loadWep(vs_battle_objectData*);
int _parseWep(vs_battle_objectData*);
int _loadShp(vs_battle_objectData*);
int _parseShp(vs_battle_objectData*);
int func_8009BE5C(vs_battle_objectData*);
int _loadSeq(vs_battle_objectData*);
int _loadEtm(vs_battle_objectData*);
int func_8009E180(D_800F4538_t*, SVECTOR* arg1);
int func_8009E228(D_800F4538_t* arg0, SVECTOR* arg1);
void func_8009E700(int, int);
int func_8009F794(D_800F45E0_t* arg0);
void func_8009F9F4(int, D_800F4538_unk64*);
void func_8009FD38(D_800F4538_t* arg0);
int func_800A0104(int, int);
void func_800A11D8(int, int, MATRIX*, u_long*);
int func_800A141C(int arg0, int arg1, int* arg2, int arg3);
int func_800A152C(int, int, int);
void func_800A2C48(D_800F4538_t*);
void func_800A525C(D_800F4538_t*);
int func_800A6EE8(short*, int, int, int);
int func_800A91DC(int, int, int);
void func_800AB2AC(int);
void func_800AD494(D_800F4538_t*, int, int*);
void func_800AD62C(int, int*, int*, int);
int func_800AD714(D_800F4538_t*, D_800F4538_unkC54*, int);
void func_800AE6C0(D_800F4538_t*, int, int);
short func_800BEB00();
void func_800E6898(void*);
void func_800E68A0(D_800F45E0_t*);

extern u_short _shpLbaOffsets[];
extern u_char _shpFileSectorSizes[];
extern u_short _etmLbaOffsets[];
extern u_char _etmFileSectorSizes[];
extern u_char _wepFileSectorOffsets[];
extern u_short D_800E8D00[];
extern u_char _loadShpState;
extern u_char D_800E8F2C;
extern u_char _loadEtmState;
extern u_char D_800E8FA8[];
extern void* D_800E8FB4[];
extern char D_800E8FC0;
extern int D_800E8FC4;
extern u_char D_800E9090[];
extern u_char D_800E909C[];
extern u_char D_800E919C[];
extern void* _wepFileData;
extern int _wepFileLoaded;
extern vs_main_CdFile _wepFile;
extern vs_main_CdQueueSlot* _wepCdSlot;
extern void* _shpData;
extern int _shpAllocated;
extern vs_main_CdFile _shpFile;
extern vs_main_CdQueueSlot* _shpCdSlot;
extern u_short* _etmData;
extern vs_main_CdFile _etmFile;
extern vs_main_CdQueueSlot* _etmFileCdSlot;
extern u_char D_800F244F[];
extern u_char D_800F2450[];
extern D_800F2458_t D_800F2458;
extern VECTOR D_800F4438;
extern char D_800F4448[];
extern int D_800F457C;
extern int D_800F4580;
extern int D_800F45D8;
extern D_800F46A8_t D_800F46A8[];
extern D_800F4770_t D_800F4770[];

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_80099514);

int vs_battle_getEmptyObjectDataSlot(void)
{
    int i;

    for (i = 0; i < 16; ++i) {
        if (vs_battle_objectDataSlots[i].unk0 == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", vs_battle_populateDataSlot);

int vs_battle_processObjectDataQueue(void)
{
    int i;
    int ret;
    vs_battle_objectData* slot = vs_battle_objectDataSlots;

    D_800F4580 = VSync(1);

    switch (slot->unk0) {
    case 0:
        return 0;
    case 1:
        ret = _loadShp(slot);
        break;
    case 3:
        ret = _loadWep(slot);
        break;
    case 7:
        ret = func_8009BE5C(slot);
        break;
    case 2:
        ret = _parseShp(slot);
        break;
    case 4:
        ret = _parseWep(slot);
        break;
    case 6:
        ret = func_8009998C(slot);
        break;
    case 8:
        ret = _loadSeq(slot);
        break;
    case 9:
        ret = _loadEtm(slot);
        break;
    default:
        return -1;
    }

    D_800F4580 = VSync(1) - D_800F4580;

    if (_loadShpState == 2) {
        if (D_800E8FC4 < D_800F4580) {
            D_800E8FC4 = D_800F4580;
            D_800F45D8 = slot->unk0;
            D_800F457C = _loadShpState;
        }
    }

    if (ret == -1) {
        return 1;
    }

    for (i = 1; i < 15; ++i) {
        vs_main_memcpy(&vs_battle_objectDataSlots[i - 1], &vs_battle_objectDataSlots[i],
            sizeof vs_battle_objectDataSlots[i]);
    }

    vs_battle_objectDataSlots[i - 1].unk0 = 0;

    return ret < 0 ? -1 : 1;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_80099854);

int func_80099900(func_8009AC24_t* arg0)
{
    int i;

    for (i = 0; i < 16; ++i) {
        if ((i != arg0->unk1)
            && ((D_800F45E0[i] != NULL)
                && (D_800F45E0[i]->unk6C[8].unk0_0 == arg0->unk10))) {
            arg0->unk8 = i;
            return 1;
        }
    }
    return 0;
}

void func_80099960(void* arg0) { vs_main_memcpy(&D_800F4448, arg0, 0xE0); }

int func_8009998C(vs_battle_objectData* arg0)
{
    D_800F45E0_t* temp_a0;
    int temp_s0;
    int j;
    int var_v0_2;
    D_800F4538_t2* var_s0;
    int i;
    D_800F45E0_t* s1;
    D_800E8FB4_t* temp_v1_2;

    if (D_800F45E0[arg0->unk1] != NULL) {
        return -3;
    }

    s1 = D_800F45E0[arg0->unk1] = arg0->unk4;

    if (s1 == NULL) {
        return -2;
    }

    memset(s1, 0, 0x178);

    for (i = 0; i < 16; ++i) {
        if ((i != arg0->unk1) && (D_800F45E0[i] != NULL)
            && (D_800F45E0[i]->unk6C[8].unk0_0 == arg0->actorId)) {
            arg0->dataAddr = i;
            var_v0_2 = 1;
            goto exit;
        }
    }
    var_v0_2 = 0;
exit:
    if (var_v0_2 != 0) {
        vs_main_memcpy(s1, D_800F45E0[arg0->dataAddr], 0x178);
    } else {
        temp_v1_2 = D_800E8FB4[D_800E919C[arg0->actorId]];
        *(int*)&s1->unk0 = temp_v1_2->unk0;
        s1->unk4 = temp_v1_2->unk4;
        temp_s0 = temp_v1_2->unk8;
        s1->unk68 = func_8009A028(NULL, temp_v1_2 + 1, temp_v1_2->unkC);

        if (s1->unk68 == NULL) {
            return -2;
        }

        temp_v1_2 = s1->unk68->unk3C;
        j = arg0->actorId;

        if (j >= 6) {
            j = 5;
        }

        func_80099E7C(temp_v1_2, temp_s0, 1, D_800E8FA8[j * 2], D_800E8FA8[j * 2 + 1]);
    }

    var_s0 = &s1->unk6C[6];

    s1->unkF = arg0->unk1;
    s1->unk6C[8].unk0_0 = arg0->actorId;

    vs_main_memcpy(var_s0, (s1->unk6C[8].unk0_0 << 5) + D_800F4448, sizeof *var_s0);
    vs_main_loadClut((void*)var_s0, 0xD, s1->unkF * 0x10, 0x10);

    s1->unk6C[8].unk3 = 0xFF;
    s1->unk12 = 0xFF;

    if (s1->unk6C[8].unk0_0 == 1) {
        s1->unk6C[8].unk1 = arg0->unk11;
    }

    s1->unk54 = 0x808080;
    s1->unk2C = 0x40;
    s1->unk2E = 0x40;
    s1->unk30 = 0x40;
    s1->unk1A = 0;
    s1->unk64.unk0 = 0;
    s1->unk8_0 = 1;
    s1->unk8_1 = 0;
    *(int*)&s1->unk5C = *(int*)&arg0->unkC;
    s1->unk5F = 0;
    s1->unk1C = (s1->unk5C << 7) + 0x40;
    s1->unk20 = (s1->unk5E << 7) + 0x40;
    s1->unk1E = func_800A6EE8(&s1->unk1C, 0, 0, 1) - (arg0->unk13 << 7);
    func_800A0104(arg0->unk1, arg0->material);
    func_800E6898(s1);
    s1->unk6C[8].unk0_4 = 0;

    if (s1->unk6C[8].unk0_0 >= 5) {

        for (j = 0; j < arg0->unk1; ++j) {
            temp_a0 = D_800F45E0[j];
            if ((temp_a0 != NULL) && (*(int*)&temp_a0->unk5C == *(int*)&s1->unk5C)
                && (temp_a0->unk1E == (s1->unk1E + 0x80))
                && (temp_a0->unk6C[8].unk0_0 >= 5)) {
                if (temp_a0->unk6C[8].unk0_0 != s1->unk6C[8].unk0_0) {
                    s1->unk6C[8].unk0_4 = 1;
                } else {
                    s1->unk6C[8].unk0_4 = 2;
                    s1->unk1E = s1->unk1E - 0x80;
                    func_800E6898(s1);
                }
                break;
            }
        }
    }
    return 0;
}

int func_80099D6C(int arg0)
{
    vs_battle_objectData sp10;
    D_800F45E0_t* temp_s0;
    int i;
    int found;

    if (arg0 >= 16) {
        return -1;
    }

    temp_s0 = D_800F45E0[arg0];

    if (temp_s0 == NULL) {
        return -1;
    }

    if (temp_s0->unk0 == 0) {
        return -1;
    }

    sp10.unk1 = arg0;
    sp10.actorId = temp_s0->unk6C[8].unk0_0;

    for (i = 0; i < 16; ++i) {
        vs_battle_objectData* a2 = &sp10;
        if ((i != a2->unk1) && (D_800F45E0[i] != NULL)
            && (D_800F45E0[i]->unk6C[8].unk0_0 == a2->actorId)) {
            a2->dataAddr = i;
            found = 1;
            goto exit;
        }
    }

    found = 0;

exit:
    if (!found) {
        vs_main_freeHeap(temp_s0->unk68);
    }

    func_800E68A0(temp_s0);
    D_800F45E0[arg0] = NULL;
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_80099E7C);

int func_80099FA8(func_8009AC24_t* arg0)
{
    int i;
    int temp_a3 = arg0->unk1;

    for (i = 0; i < 20; ++i) {
        if (i != temp_a3) {
            D_800F4588_t* temp_v1 = D_800F4588[i];
            if ((temp_v1 != NULL) && ((temp_v1->unk8_0) || (temp_a3 < 4))
                && (temp_v1->unkE == arg0->unk2)) {
                arg0->unk8 = i;
                return 1;
            }
        }
    }
    return 0;
}

void* func_8009A028(int* arg0, void* arg1, int arg2)
{
    if (arg0 == NULL) {
        arg0 = vs_main_allocHeap(arg2);
    }

    memcpy(arg0, arg1, arg2);

    arg0[12] += (u_long)arg0;
    arg0[13] += (u_long)arg0;
    arg0[14] += (u_long)arg0;
    arg0[15] += (u_long)arg0;

    return arg0;
}

int _loadWep(vs_battle_objectData* arg0)
{
    int wepData;
    int found;
    int wepFileSize;
    int i;

    if ((arg0->modelId == 0) || (arg0->modelId >= 0x80)) {
        return 0;
    }

    switch (_loadShpState) {
    case 0:
        for (i = 0; i < 20; ++i) {
            if ((i != arg0->unk1) && (D_800F4588[i] != NULL)
                && ((D_800F4588[i]->unk8_0) || (arg0->unk1 < 4))
                && (D_800F4588[i]->unkE == arg0->modelId)) {
                arg0->dataAddr = i;
                found = 1;
                goto exit;
            }
        }
        found = 0;
    exit:
        if (found != 0) {
            _wepFileLoaded = 0;
            break;
        }

        _wepFileLoaded = 1;
        // Fallthrough

    default:
        wepFileSize = _wepFileSectorOffsets[arg0->modelId];
        wepFileSize <<= 0xB;
        _wepFileData = vs_main_allocHeapR(wepFileSize);
        arg0->dataAddr = (u_long)_wepFileData;

        if (_wepFileData == NULL) {
            return -2;
        }

        _loadShpState = 1;
        _wepFile.lba = D_800E8D00[arg0->modelId] + VS_01_WEP_LBA;
        _wepFile.size = wepFileSize;
        _wepCdSlot = vs_main_allocateCdQueueSlot(&_wepFile);
        vs_main_cdEnqueue(_wepCdSlot, (void*)arg0->dataAddr);
        // Fallthrough

    case 1:
        if (_wepCdSlot->state != 4) {
            return -1;
        }
        vs_main_freeCdQueueSlot(_wepCdSlot);
        _loadShpState = 2;
        return -1;
    case 2:
        break;
    }

    wepData = _parseWep(arg0);

    if (wepData == -1) {
        return -1;
    }

    if (_wepFileLoaded != 0) {
        _wepFileLoaded = 0;
        vs_main_freeHeapR(_wepFileData);
    }

    _loadShpState = 0;
    return wepData;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", _parseWep);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009A98C);

int func_8009AA84(int arg0)
{
    vs_battle_objectData sp10;
    int i;
    D_800F4588_t* temp_s0 = D_800F4588[arg0];

    if ((temp_s0 == NULL) || (temp_s0->unk0 == 0)) {
        return -1;
    }

    if (temp_s0->unk8_0) {
        sp10.unk1 = arg0;
        sp10.modelId = temp_s0->unkE;

        if (arg0 >= 4) {
            int var_v0;
            vs_battle_objectData* a3 = &sp10;

            for (i = 0; i < 20; ++i) {
                if ((i != a3->unk1) && ((D_800F4588[i] != NULL))
                    && ((D_800F4588[i]->unk8_0) || (a3->unk1 < 4))
                    && (D_800F4588[i]->unkE == a3->modelId)) {
                    a3->dataAddr = i;
                    var_v0 = 1;
                    goto exit;
                }
            }

            var_v0 = 0;
        exit:
            if (var_v0 == 0) {
                vs_main_freeHeap(temp_s0->unk1C);
            }
        } else {
            vs_main_freeHeap(temp_s0->unk1C);
        }
    }

    --D_800F4770[temp_s0->unkF].unk6;

    if (temp_s0->unk8_5) {
        --D_800F4770[temp_s0->unkF + 1].unk6;
    }

    D_800F4588[arg0] = NULL;
    return 0;
}

int func_8009AC24(func_8009AC24_t* arg0)
{
    int i;

    for (i = 0; i < 17; ++i) {
        if ((i != arg0->unk1)
            && ((D_800F4538[i] != NULL) && (D_800F4538[i]->unk6E6 == arg0->unk2))) {
            arg0->unk8 = i;
            return 1;
        }
    }
    return 0;
}

int _loadShp(vs_battle_objectData* arg0)
{
    int shpData;
    int found;
    int i;
    int shpFileSize;

    switch (_loadShpState) {
    case 0:
        if (arg0->modelId == 0x7F) {
            _shpAllocated = 0;
            break;
        }

        for (i = 0; i < 17; ++i) {
            if ((i != arg0->unk1) && ((D_800F4538[i] != NULL))
                && (D_800F4538[i]->unk6E6 == arg0->modelId)) {
                arg0->dataAddr = i;
                found = 1;
                goto exit;
            }
        }
        found = 0;
    exit:
        if (found != 0) {
            _shpAllocated = 0;
            break;
        }
        _shpAllocated = 1;
        // Fallthrough

    default:
        shpFileSize = _shpFileSectorSizes[arg0->modelId];

        if (shpFileSize == 0) {
            arg0->modelId = 0;
            shpFileSize = _shpFileSectorSizes[0];
        }

        shpFileSize <<= 0xB;
        _shpData = vs_main_allocHeapR(shpFileSize);
        arg0->dataAddr = (u_long)_shpData;

        if (_shpData == NULL) {
            return -2;
        }

        _loadShpState = 1;
        _shpFile.lba = _shpLbaOffsets[arg0->modelId] + VS_00_SHP_LBA;
        _shpFile.size = shpFileSize;
        _shpCdSlot = vs_main_allocateCdQueueSlot(&_shpFile);

        vs_main_cdEnqueue(_shpCdSlot, (void*)arg0->dataAddr);
    case 1:
        if (_shpCdSlot->state != 4) {
            return -1;
        }

        vs_main_freeCdQueueSlot(_shpCdSlot);
        _loadShpState = 2;

        return -1;

    case 2:
        break;
    }

    shpData = _parseShp(arg0);

    if (shpData == -1) {
        return -1;
    }

    if (_shpAllocated != 0) {
        _shpAllocated = 0;
        vs_main_freeHeapR(_shpData);
    }

    _loadShpState = 0;
    return shpData;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", _parseShp);

int func_8009BD90(vs_battle_objectData* arg0)
{
    D_800F4538_t* temp_v1;
    int var_a2;
    int t1 = D_800F4538[arg0->unk1]->unk6E6;
    for (var_a2 = (arg0->unk1 >= 2) * 2; var_a2 < 17; ++var_a2) {
        if (var_a2 != arg0->unk1) {
            temp_v1 = D_800F4538[var_a2];
            if ((temp_v1 != NULL) && (temp_v1->unk6E6 == t1)) {
                if ((arg0->modelId == 0 && temp_v1->unk5D4 != 0)
                    || (arg0->modelId != 0 && temp_v1->unk5B1 == arg0->modelId)) {
                    arg0->dataAddr = var_a2;
                    return 1;
                }
            }
        }
    }
    return 0;
}

// https://decomp.me/scratch/wJjuU
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009BE5C);

void func_8009C378(func_8009C378_t* arg0, func_8009C378_t* arg1)
{
    vs_main_memcpy(arg0, arg1, 0x7800);
    arg0->unk0 -= (long)arg1;
    arg0->unk4 -= (long)arg1;
    arg0->unk0 += (long)arg0;
    arg0->unk4 += (long)arg0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", _loadSeq);

void func_8009CAEC(D_800F4538_t* arg0, int arg1);
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009CAEC);

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009CC20);

void func_800AB098(D_800F4538_t*, int, int);

int func_8009CE9C(u_int arg0)
{
    int i;

    if (arg0 - 1 >= 3) {
        return -1;
    }

    for (i = 0; i < 17; ++i) {
        D_800F4538_t* temp_s0 = D_800F4538[i];
        if ((temp_s0 != NULL) && *((u_char*)temp_s0 + D_800E8F2C + 0x183E) != 0xFF
            && (*((u_char*)temp_s0 + arg0 + 0x183D) == 0xFF)) {
            if (temp_s0->unk180D >= 2) {
                func_800AB098(temp_s0, 0, 0);
            }
            if (temp_s0->unk1811 >= 2) {
                func_800AB098(temp_s0, 1, 0);
            }
        }
    }
    D_800E8F2C = arg0 - 1;
    return 0;
}

int func_8009CFA0(void) { return D_800E8F2C + 1; }

int func_8009CFB0(int arg0)
{
    func_8009AC24_t sp10;
    D_800F4538_t* temp_s1;
    int i;

    if (arg0 >= 0x11) {
        return -1;
    }

    temp_s1 = D_800F4538[arg0];

    if (temp_s1 == NULL) {
        return -1;
    }

    if (temp_s1->unk6E6 != 0x7F) {
        func_8009AC24_t* a2;
        int var_v0;
        sp10.unk1 = arg0;
        sp10.unk2 = temp_s1->unk6E6;
        a2 = &sp10;

        for (i = 0; i < 17; ++i) {
            if ((i != a2->unk1) && ((D_800F4538[i] != NULL))
                && (D_800F4538[i]->unk6E6 == a2->unk2)) {
                a2->unk8 = i;
                var_v0 = 1;
                goto exit;
            }
        }

        if (i >= 17) {
            var_v0 = 0;
        }
    exit:
        if (var_v0 == 0) {
            func_8004644C(0x180, ((func_8004644C_t*)temp_s1->unk68)->unk30, 0);
            vs_main_freeHeap(temp_s1->unk68);
            vs_main_freeHeap(temp_s1->unk5D0);
        }

        if (temp_s1->unk5D4 != 0) {
            for (i = 0; i < 17; ++i) {
                if ((i != arg0) && ((D_800F4538[i] != NULL))
                    && (D_800F4538[i]->unk5D4 == temp_s1->unk5D4)) {
                    goto exit2;
                }
            }
            if (i >= 17) {
                vs_main_freeHeap(temp_s1->unk5D4);
            }
        }
    exit2:

        func_8009CC20(arg0, 0);

        if (arg0 < 10) {
            func_8009AA84(arg0 * 2);
            func_8009AA84(arg0 * 2 | 1);
        }

        if (temp_s1->unk5B0_5) {
            for (i = 0; i < (temp_s1->unk8_4 + 1); ++i) {
                --D_800F46A8[temp_s1->unk5BB + i].unk6;
            }

            if (temp_s1->unk5BB == 20) {
                func_8007E0A8(31, 1, 4);
            }
        }
    }
    D_800F4538[arg0] = NULL;
    return 0;
}

int func_8009D208(int arg0)
{
    if (D_800F244F[arg0] != 0) {
        func_800AB2AC(arg0 - 1);
        if (func_8007E0A8(D_800F244F[arg0], 1, 4) == 0) {
            return -3;
        }
        D_800F244F[arg0] = 0;
    }
    return 0;
}

int _loadEtm(vs_battle_objectData* arg0)
{
    RECT rect;
    int fileSize;
    int temp_a0;
    int h;

    switch (_loadEtmState) {
    default:
        _loadEtmState = 1;
        temp_a0 = _etmFileSectorSizes[arg0->modelId];
        if (temp_a0 == 0) {
            _loadEtmState = 0;
            return -2;
        } else {
            fileSize = temp_a0 << 0xB;
            _etmData = vs_main_allocHeapR(fileSize);
            if (_etmData == NULL) {
                return -2;
            }

            _etmFile.lba = _etmLbaOffsets[arg0->modelId] + VS_E001_ETM_LBA;
            _etmFile.size = fileSize;
            _etmFileCdSlot = vs_main_allocateCdQueueSlot(&_etmFile);
            vs_main_cdEnqueue(_etmFileCdSlot, _etmData);
        }
        // fallthrough
    case 1:
        if (_etmFileCdSlot->state != 4) {
            return -1;
        }

        vs_main_freeCdQueueSlot(_etmFileCdSlot);

        if (D_800F244F[arg0->unk1] != 0) {
            if (func_8007E0A8(D_800F244F[arg0->unk1], 1, 4) == 0) {
                return -3;
            }
            D_800F244F[arg0->unk1] = 0;
        }

        if (func_8007DFF0(arg0->unk11, 1U, 4) == 0) {
            return -2;
        }

        D_800F244F[arg0->unk1] = arg0->unk11;
        ++_etmData;
        h = *_etmData;
        ++_etmData;
        setRECT(&rect, (arg0->unk11 & 0xF) << 6, 256, 64, h);
        LoadImage(&rect, (void*)_etmData);
        _loadEtmState = 2;
        return -1;

    case 2:
        vs_main_freeHeapR(_etmData - 2);
        _loadEtmState = 0;
        return 0;
    }
}

void func_8009D458(void) { }

void func_8009D460(void) { }

void func_8009D468(int arg0, int arg1)
{
    D_800F4538_unk64 sp10;
    int var_a2;
    D_800F4538_unk1864* s0;
    D_800F4538_t* temp_s1 = D_800F4538[arg0];

    if (temp_s1 != NULL) {
        temp_s1->unk2C = 0x1000;
        temp_s1->unk2E = 0x1000;
        temp_s1->unk30 = 0x1000;
        temp_s1->unk17FC = -2;
        temp_s1->unk11 = 0;
        temp_s1->unk5C8 = 0;
        temp_s1->unk18 = 0;
        *(int*)&temp_s1->unk24 = 0;
        temp_s1->unk28 = 0;
        temp_s1->unk1A = 0;
        temp_s1->unk16 = 0;
        temp_s1->unk14 = 0;
        temp_s1->unkA_0 = 0;
        temp_s1->unk5AC_0 = 0;
        temp_s1->unkB_0 = 0;
        temp_s1->unkB_3 = 0;
        func_8009FD38(temp_s1);
        if (D_800F2450[D_800E8F2C] != 0) {
            func_800AB098(temp_s1, 0, 0);
            func_800AB098(temp_s1, 1, 0);
        }
        temp_s1->unk1800[2] = 0;
        temp_s1->unk180C_0 = 0;
        temp_s1->unk5AC_21 = 0;
        temp_s1->unk1810_0 = 0;
        temp_s1->unk5AC_22 = 0;
        func_800A07FC(arg0, NULL);
        if (temp_s1->unk17FD == 1) {
            temp_s1->unk17FD = 0;
        }
        temp_s1->unk9_7 = 1;
        sp10.unk0 = 0;
        func_8009F990(arg0, &sp10);
        temp_s1->unk5BE = 4;
        temp_s1->unk17FF = 0;
        temp_s1->unk64.unk0 = 0;
        temp_s1->unk1860 = 0;
        temp_s1->unkC_0 = 0;
        temp_s1->unkC_4 = 0;
        temp_s1->unkA_3 = 0;
        temp_s1->unk9_6 = 0;
        temp_s1->unk5AC_3 = 0;
        temp_s1->unk9_0 = 0;
        var_a2 = 0x62;
        if (arg0 == 0) {
            var_a2 = 1;
        }
        func_800A0204(arg0, var_a2, 0, 0);
        temp_s1->unk6E0 = 0;
        temp_s1->unk6EC = 0;
        temp_s1->unk6EE = 0;
        temp_s1->unk6EF = 0;
        temp_s1->unk1846 = 0;
        temp_s1->unk5AC_24 = 0;
        temp_s1->unk8_0 = 1;
        temp_s1->unk8_1 = 1;
        temp_s1->unk8_2 = 1;
        temp_s1->unk5AC_15 = 0;
        s0 = &temp_s1->unk1864;
        memset(s0, 0, sizeof *s0);
        s0->unkC = temp_s1->unk64E;
        s0->unkE = temp_s1->unk650;
        memset(&temp_s1->unk1848, 0, sizeof temp_s1->unk1848);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009D6F4);

void func_8009D7E8(int arg0, int arg1)
{
    D_800F4538_t* temp_a2 = D_800F4538[arg0];
    if (temp_a2 != NULL) {
        if (arg1 == 0) {
            temp_a2->unk5AC_21 = 0;
        } else {
            temp_a2->unk1800[2] = 0;
            temp_a2->unk5AC_21 = 1;
            temp_a2->unk1800[3] = arg1 * 2;
            temp_a2->unk5AC_22 = 0;
        }
    }
}

void func_8009D854(int arg0)
{
    if (D_800F4538[arg0] != NULL) {
        D_800F4538[arg0]->unk5AC_18 = 1;
    }
}

void func_8009D88C(int arg0)
{
    int i;
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 == NULL) {
        return;
    }

    for (i = 0; i < 2; ++i) {
        D_800F4588_t* temp_v1 = D_800F4588[(temp_a0->unkF * 2) + i];
        if ((temp_v1 != NULL) && (temp_v1->unkD != 0)) {
            if (temp_v1->unk8_4) {
                temp_v1->unk11 = 0x40;
                temp_v1->unk12 = 0x40;
            } else {
                temp_v1->unk11 = 0;
                temp_v1->unk12 = 0;
            }
            temp_v1->unk13 = 0;
        }
    }
}

void func_8009D934(int arg0, int arg1, int arg2)
{
    int var_s2;
    int temp_s1;

    D_800F4538_t* temp_s0 = D_800F4538[arg0];

    if (temp_s0 == NULL) {
        return;
    }

    if (arg2 == 2) {
        int i;
        temp_s0->unkA_7 = arg1;

        for (i = 0; i < 2; ++i) {
            D_800F4588_t* temp_v1 = D_800F4588[(arg0 * 2) + i];
            if (temp_v1 != NULL) {
                if (arg1 != 0) {
                    temp_v1->unk11 = 0x40;
                    temp_v1->unk12 = 0x40;
                    temp_v1->unk8_4 = 1;
                } else {
                    temp_v1->unk11 = 0;
                    temp_v1->unk12 = 0;
                    temp_v1->unk8_4 = 0;
                }
            }
        }
        return;
    }

    var_s2 = 5;

    if (arg2 != 0) {
        var_s2 = 16;
        temp_s1 = D_800E9090[temp_s0->unk5B1];
    } else {
        temp_s1 = D_800E909C[temp_s0->unk5B1];
    }

    if (func_800BEB00() == 4) {
        temp_s0->unkA_7 = arg1;
        func_800A0204(arg0, 1, 0, 16);
        return;
    }

    if (arg1 != temp_s0->unkA_7) {
        if (arg1 == 0) {

            if (temp_s0->unk6E6 == 0) {
                func_800AE6C0(temp_s0, temp_s1 + 1, 0);
            }

            func_800A0204(arg0, (arg2 * 2) + 10, 0, var_s2);

            temp_s0->unk5AC_20 = 1;
            temp_s0->unkA_7 = 0;

            func_800A01C8(arg0, 1, 16, 0);
        } else {

            if (temp_s0->unk6E6 == 0) {
                func_800AE6C0(temp_s0, (int)temp_s1, 0);
            }

            temp_s0->unkA_7 = arg1;

            func_800A0204(arg0, (arg2 * 2) + 9, 0, var_s2);

            temp_s0->unk5AC_20 = 1;

            func_800A01C8(arg0, 1, 16, 0);
        }
    }
}

void func_8009DBDC(int arg0, int arg1)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (temp_a0 != NULL) {
        func_800AE6C0(temp_a0, D_800E9090[temp_a0->unk5B1] + arg1, 0);
    }
}

void func_8009DC38(int arg0)
{
    D_800F4538_t* temp_s0 = D_800F4538[arg0];
    if (temp_s0 != NULL) {
        func_8009DC8C(arg0);
        temp_s0->unk1A = 0;
        temp_s0->unk18 = 0;
        *(int*)&temp_s0->unk34 = 0;
    }
}

void func_8009DC8C(int arg0)
{
    D_800F4538_t* temp_a3 = D_800F4538[arg0];

    if (temp_a3 == NULL) {
        return;
    }

    temp_a3->unk11 = 0;
    temp_a3->unkA_0 = 0;
    temp_a3->unk5AC_20 = 0;
    temp_a3->unkB_3 = 0;
    temp_a3->unkA_3 = 0;
    temp_a3->unk9_6 = 0;
}

void func_8009DD00(int arg0, SVECTOR* arg1, int arg2)
{
    int _[2];
    D_800F4538_t* temp_s0;
    int temp_v0;
    int var_a1;

    temp_s0 = D_800F4538[arg0];
    if (temp_s0 != NULL) {
        temp_s0->unk3E = func_8009E180(temp_s0, arg1);
        temp_s0->unk18 = 0xA;
        if (temp_s0->unk63C >= 0x81U) {
            temp_s0->unk18 = 0x14;
        }

        temp_v0 = func_8009E228(temp_s0, arg1);

        if (temp_v0 >= -0xE4) {
            var_a1 = 0x49;
            if (temp_v0 >= 0xAC) {
                var_a1 = 0x4A;
                if ((temp_v0 >= 0x301) && (arg2 == 0) && (temp_s0->unk6E6 == 0x28)) {
                    var_a1 = 0x4E;
                }
            }
        } else {
            var_a1 = 0x48;
        }

        func_800A0204(arg0, var_a1, 0, 6);
        func_8009FD38(temp_s0);
    }
}

void func_8009DDF4(int arg0, SVECTOR* arg1)
{
    int _[3] __attribute__((unused));
    D_800F4538_t* temp_s0 = D_800F4538[arg0];

    if (temp_s0->unkA_7
        && ((temp_s0->unkF == 0)
            || (!temp_s0->unkA_5 && ((temp_s0->unkA_0 != 2))
                && (temp_s0->unkA_0 != 3)))) {
        int var_s1;
        int var_a1;
        int temp_v0;

        if (temp_s0->unk63C < 0x80) {
            temp_s0->unk3E = func_8009E180(temp_s0, arg1);
            temp_s0->unk18 = 4;
            var_s1 = 8;
        } else {
            var_s1 = 4;
        }

        temp_v0 = func_8009E228(temp_s0, arg1);
        var_a1 = 0x4F;

        if (temp_v0 >= -0xE4) {
            var_a1 = 0x50;
            if (temp_v0 >= 0xAC) {
                var_a1 = 0x51;
            }
        }

        func_800A0204(arg0, var_a1, 0, var_s1);
        func_8009FD38(temp_s0);
    }

    if (temp_s0->unkF == 0) {
        if (temp_s0->unkA_0 != 3) {
            temp_s0->unkA_0 = 0;
        }
        temp_s0->unk11 = 0;
    }
}

void func_8009DF3C(int arg0, int arg1)
{
    int sp10[2];
    D_800F4538_t* temp_s2 = D_800F4538[arg0];

    int var_s0 = 0;
    int var_s1 = 0;

    if (temp_s2->unkF == 0) {
        return;
    }

    switch (arg1) {
    case 0:
        var_s0 = 6;
        break;
    case 1:
        var_s0 = 0xC6;
        break;
    case 2:
        var_s0 = 0xC8;
        break;
    case 3:
        var_s0 = temp_s2->unk5B8;
        if ((var_s0 != 0xC6) && (var_s0 != 0xC8)) {
            return;
        }
        ++var_s0;
        var_s1 = 8;
        func_800AD494(temp_s2, var_s0, sp10);
        if (sp10[0] == 0) {
            var_s0 = 6;
            var_s1 = 0x10;
        }
        break;
    }

    func_800A0204(arg0, var_s0, 0, var_s1);
    if (arg1 < 3) {
        vs_main_memcpy(&temp_s2->unk704, &temp_s2->unkC54, sizeof temp_s2->unk704);
    }
}

void func_8009E070(int arg0, SVECTOR* arg1, int arg2)
{
    int var_s1;
    D_800F4538_t* temp_s0 = D_800F4538[arg0];

    switch (arg2) {
    case 1:
    case 2:
    case 3:
    case 4:
        var_s1 = arg2 + 0x5F;
        break;
    case 5:
        var_s1 = 0x1E;
        break;
    case 6:
        var_s1 = 0x1C;
        if (temp_s0->unk5AC_3 << 3) {
            var_s1 = 1;
        }

        if ((temp_s0->unkA_0 == 3) || (temp_s0->unkA_3 == 2)) {
            return;
        }
        break;
    case 7:
        var_s1 = 0x1D;
        break;
    default:
        return;
    }

    temp_s0->unk3E = func_8009E180(temp_s0, arg1);
    temp_s0->unk18 = 0xA;
    temp_s0->unk1846 = 0;
    temp_s0->unk5AC_20 = 1;
    func_800A0204(arg0, var_s1, 0, 6);
    temp_s0->unk6E0 = 0;
}

int func_8009E180(D_800F4538_t* arg0, SVECTOR* arg1)
{
    int temp_a0;
    int temp_a1;
    int var_v1;
    int var_v0;

    if (arg1 == NULL) {
        return 0;
    }

    temp_a1 = arg1->vx - arg0->unk1C.vx;
    temp_a0 = arg1->vz - arg0->unk1C.vz;

    if ((temp_a1 == 0) && (temp_a0 == 0)) {
        var_v1 = arg0->unk26;
    } else {
        var_v1 = (0xC00 - ratan2(temp_a0, temp_a1)) & 0xFFF;
    }

    var_v1 -= arg0->unk26;

    if (var_v1 >= 0x801) {
        var_v0 = var_v1 - 0x1000;
    } else {
        var_v0 = var_v1;
        if (var_v1 < -0x800) {
            var_v0 = var_v1 + 0x1000;
        }
    }

    return var_v0;
}

int func_8009E228(D_800F4538_t* arg0, SVECTOR* arg1)
{
    SVECTOR sp10;
    int var_s0;
    int var_v1;

    if (arg1 == NULL) {
        return 0;
    }

    var_s0 = arg1->vx - arg0->unk1C.vx;
    var_s0 = var_s0 * var_s0;
    var_v1 = arg1->vz - arg0->unk1C.vz;

    if (var_s0 < 0) {
        var_s0 = -var_s0;
    }

    var_v1 = var_v1 * var_v1;

    if (var_v1 < 0) {
        var_v1 = -var_v1;
    }

    var_s0 = vs_gte_rsqrt(var_s0 + var_v1);
    func_800A1AF8(arg0->unkF, 0, &sp10, 0);
    return ratan2(arg1->vy - sp10.vy, var_s0);
}

// https://decomp.me/scratch/eQWuH
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009E2E0);

int func_8009E480(void)
{
    if (D_800F4538[0]->unk5B8 == 0x63) {
        return 1;
    }
    return D_800F4538[0]->unk5B8 == 0xC7;
}

int func_8009E4B0(int arg0)
{
    D_800F4538_t* temp_a1 = D_800F4538[arg0];

    if (temp_a1 == NULL) {
        if (D_800F45E0[arg0] == NULL) {
            return -1;
        }
        return 0;
    }

    if ((temp_a1->unk9_0 != 0) && (temp_a1->unk9_0 != 5) && (temp_a1->unk9_0 != 11)) {
        return 1;
    }

    if (!(temp_a1->unkC54.unk548 & 0x10000)) {
        int temp_a0 = temp_a1->unk5B8;
        if (temp_a0 >= 100) {
            temp_a0 -= 100;

            if ((temp_a0 - 9) < 4U) {
                return 1;
            }

            if (temp_a0 == 0x1C) {
                return 1;
            }

            if ((temp_a0 - 0x62) < 4U) {
                return 0;
            }
            if (temp_a0 >= 0x40) {
                return 1;
            }
            temp_a1 = D_800F4538[arg0];
            return 0;
        }

        if (temp_a0 == 0x1C) {
            return 1;
        }
        if (temp_a0 == 0x3B) {
            return 1;
        }
        if ((temp_a0 - 0x40) < 7U) {
            return 1;
        }
        if ((temp_a0 - 0x55) < 7U) {
            return 1;
        }
        if (temp_a0 == 0x5E) {
            return 1;
        }
    }
    return 0;
}

void func_8009E5C4(int arg0)
{
    if ((D_800F4538[arg0]->unk5B8 != 0x63) && (D_800F4538[arg0]->unk5B8 != 0xC7)) {
        func_8009E700(arg0, 1);
    }
}

void func_8009E614(int arg0) { func_8009E700(arg0, 6); }

void func_8009E634(D_800F4538_t* arg0)
{
    int temp_v1_2;
    int var_a0;
    int var_a2;
    int var_a3;

    var_a0 = 1;

    if (arg0->unkF == 0) {
        if ((arg0->unk5B8 - 0x4F) >= 4U) {
            if (((arg0->unk5B8 - 0x47) >= 4U) && (arg0->unk5B8 != 0x4C)) {
                return;
            }
        } else {
            var_a0 = 2;
        }

        temp_v1_2 = arg0->unk26 + 0x200;
        temp_v1_2 &= 0xFFF;
        temp_v1_2 /= 1024;

        var_a2 = 0;
        var_a3 = 0;

        if (temp_v1_2 < 2) {
            var_a0 = -var_a0;
        }

        if (temp_v1_2 & 1) {
            var_a2 = var_a0;
        } else {
            var_a3 = var_a0;
        }
        func_800E4C28(arg0->unk5C + var_a2, arg0->unk5E + var_a3, var_a2, var_a3);
    }
}

// https://decomp.me/scratch/ajofv
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009E700);

void func_8009EA14(int arg0, SVECTOR* arg1)
{
    SVECTOR sp10;
    D_800F4538_t* temp_s1;
    int temp_a0;
    int temp_a1;
    int var_s0;
    int temp_v1;
    int temp_v1_2;
    int var_s4;
    int var_v1;
    int var_v1_2;
    u_int var_v0;

    // var_s4 = saved_reg_s4;

    temp_s1 = D_800F4538[arg0];

    if (temp_s1 != NULL) {

        var_s0 = 0x5B;

        if (!(temp_s1->unk5AC_3 << 3)) {
            if (arg0 == 0) {

                var_v1 = 0;

                if (arg1 != NULL) {

                    var_s0 = arg1->vx - temp_s1->unk1C.vx;
                    var_s0 *= var_s0;
                    temp_v1 = arg1->vz - temp_s1->unk1C.vz;

                    if (var_s0 < 0) {
                        var_s0 = -var_s0;
                    }

                    var_v1_2 = temp_v1 * temp_v1;

                    if (var_v1_2 < 0) {
                        var_v1_2 = -var_v1_2;
                    }

                    var_s0 = vs_gte_rsqrt(var_s0 + var_v1_2);
                    func_800A1AF8(temp_s1->unkF, 0, &sp10, 0);
                    var_v1 = ratan2(arg1->vy - sp10.vy, var_s0);
                }

                var_s0 = 0x45;

                if (var_v1 >= -0xE4) {
                    var_s0 = 0x44;
                    if (var_v1 < 0xAC) {
                        goto block_11;
                    }
                }
            } else {
            block_11:
                temp_v1_2 = 0;

                if (arg1 != NULL) {

                    temp_a1 = arg1->vx - temp_s1->unk1C.vx;
                    temp_a0 = arg1->vz - temp_s1->unk1C.vz;

                    if ((temp_a1 == 0) && (temp_a0 == 0)) {
                        temp_v1_2 = temp_s1->unk26;
                    } else {
                        temp_v1_2 = (0xC00 - ratan2(temp_a0, temp_a1)) & 0xFFF;
                    }

                    temp_v1_2 = temp_v1_2 - temp_s1->unk26;

                    if (temp_v1_2 > 0x800) {
                        temp_v1_2 = temp_v1_2 - 0x1000;
                    } else {
                        if (temp_v1_2 < -0x800) {
                            temp_v1_2 = temp_v1_2 + 0x1000;
                        }
                    }
                }

                var_v0 = temp_v1_2 + 0x200;
                var_s0 = 0x40;

                if (var_v0 >= 0x801) {
                    var_s0 = 0x42;
                }
            }
        }

        if (temp_s1->unkA_3 == 2) {
            if (temp_s1->unkC_0) {
                func_8008C49C(temp_s1->unkC_0 - 2, -1);
                temp_s1->unkC_0 = 0;
            }
            var_s0 = 0x3B;
        } else {
            if (temp_s1->unkB_0 == 3) {
                func_800A2C48(temp_s1);
            }
            temp_s1->unk18 = 0;
            if (temp_s1->unkF == 0) {
                temp_s1->unk11 = 0;
                temp_s1->unkA_3 = 0;
                temp_s1->unk9_6 = 0;
                temp_s1->unkA_0 = 0;
                var_s4 = 0;
            } else {
                var_s4 = 8;
            }
        }
        func_800A525C(temp_s1);
        temp_s1->unk6E3 = 0xFF;
        func_800A0204(arg0, var_s0, 0, var_s4);
        func_8009FD38(temp_s1);
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009EC9C);

void func_8009EE9C(int arg0, SVECTOR* arg1, int arg2)
{
    int _[3] __attribute__((unused));
    D_800F4538_t* temp_s0 = D_800F4538[arg0];

    if (temp_s0->unkA_7
        && ((temp_s0->unkF == 0)
            || (!temp_s0->unkA_5 && (temp_s0->unkA_0 != 2) && (temp_s0->unkA_0 != 3)))) {
        int temp_v0;
        int var_a1;
        int var_s1;

        if (temp_s0->unk63C < 0x80) {
            temp_s0->unk3E = func_8009E180(temp_s0, arg1);
            temp_s0->unk18 = 4;
            var_s1 = 8;
        } else {
            var_s1 = 4;
        }

        temp_v0 = func_8009E228(temp_s0, arg1);
        var_a1 = 0x4F;

        if (temp_v0 >= -0xE4) {
            var_a1 = 0x50;
            if (temp_v0 >= 0xAC) {
                var_a1 = 0x51;
            }
        }

        func_800A0204(arg0, var_a1, 0, var_s1);
        func_8009FD38(temp_s0);
    }

    if (temp_s0->unkF == 0) {
        if (temp_s0->unkA_0 != 3) {
            temp_s0->unkA_0 = 0;
        }
        temp_s0->unk11 = 0;
    }

    func_8006C84C(arg0);
}

// https://decomp.me/scratch/kQp6H
INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009EFEC);

void func_8009F298(int arg0, SVECTOR* arg1, int arg2)
{
    int sp10;

    func_8009EFEC(arg0, arg1, arg2);
    if (arg2 == 1) {
        func_800AD494(D_800F4538[arg0], 0xFE, &sp10);
        if (sp10 != 0) {
            func_800A01C8((int)arg0, 0xFE, 8, 0);
        }
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_8009F314);

void func_8009F530(int arg0)
{
    D_800F4538_t* temp_v0_2;
    int temp_s4;
    int temp_v0;
    int i;
    D_800F45E0_t* temp_s0 = D_800F45E0[arg0];

    temp_s0->unk6C[8].unk0_3 = 1;
    temp_s4 = func_800A91DC(temp_s0->unk5C, temp_s0->unk5E, 0);
    temp_v0 = func_8009F794(temp_s0);

    if (temp_v0 != -1) {
        D_800F45E0_t* temp_s1 = D_800F45E0[temp_v0];
        temp_s1->unk36 = 0;
        temp_s1->unk1A = 0xFC;
        func_800E68A0(temp_s1);

        if (temp_s1->unk6C[8].unk0_4 == 2) {
            func_800E68A0(temp_s1);
        }

        for (i = 0; i < 16; ++i) {
            temp_s0 = D_800F45E0[i];
            if ((temp_s0 != NULL) && (temp_s0 != temp_s1) && !(temp_s0->unk8_0)) {
                temp_s0->unk6C[8].unk3 = 0xFF;
                if ((temp_s0->unk1A == 0) && !(temp_s0->unk6C[8].unk0_3)
                    && (temp_s0->unk12 == 0xFF) && (temp_s0->unk5C == temp_s1->unk5C)
                    && (temp_s0->unk5D == temp_s1->unk5D)
                    && (temp_s0->unk5E == temp_s1->unk5E)
                    && (temp_s0->unk1E <= temp_s1->unk1E)) {
                    temp_s0->unk6C[8].unk3 = temp_v0;
                }
            }
        }
    }

    i = 0;

    while ((temp_v0_2 = func_800A3C00(D_800F45E0[temp_s4], i))) {

        if ((temp_v0_2->unkA_0) != 3) {
            *(int*)&temp_v0_2->unk34 = 0;
            temp_v0_2->unk38 = 0;
            temp_v0_2->unkA_0 = 3;
            if (temp_v0_2->unkF != 0) {
                temp_v0_2->unk181A = 1;
                temp_v0_2->unk1814 = temp_v0_2->unk5C;
                temp_v0_2->unk1818 = temp_v0_2->unk5E;
            }
            temp_v0_2->unk11 = 4;
        }

        i = temp_v0_2->unkF + 1;
        temp_v0_2->unkA_3 = 0;
        temp_v0_2->unk9_6 = 0;
        temp_v0_2->unk5AC_28 = 0;

        if (i == 1) {
            i = 2;
        }
    }
}

int func_8009F794(D_800F45E0_t* arg0)
{
    D_800F45E0_t* temp_v1;
    int temp_v1_2;
    int var_a3;
    int i;
    int var_t0;
    int t1;

    var_a3 = -0x7530;
    var_t0 = -1;
    t1 = *(int*)&arg0->unk5C;

    for (i = 0; i < 16; ++i) {
        temp_v1 = D_800F45E0[i];
        if ((temp_v1 != NULL) && !(temp_v1->unk8_0) && (temp_v1->unk1A == 0)
            && !(temp_v1->unk6C[8].unk0_3) && (temp_v1->unk12 == 0xFF)
            && (t1 == *(int*)&temp_v1->unk5C)) {
            temp_v1_2 = temp_v1->unk1E;
            if ((arg0->unk1E >= temp_v1_2) && (var_a3 < temp_v1_2)) {
                var_a3 = temp_v1_2;
                var_t0 = i;
            }
        }
    }
    return var_t0;
}

int func_8009F858(int arg0)
{
    D_800F45E0_t* temp_a0 = D_800F45E0[arg0];

    if (temp_a0 == NULL) {
        return -1;
    }

    if (temp_a0->unk6C[8].unk0_0 != 1) {
        return -1;
    }

    return temp_a0->unk6C[8].unk1;
}

void func_8009F898(int arg0, int arg1, int arg2)
{
    D_800F4588_t* temp_a0 = D_800F4588[arg0 * 2];

    if (temp_a0 != NULL) {
        temp_a0->unk5C0 = arg2;
        temp_a0->unk8_6 = arg1;
    }
}

int func_8009F8DC(int arg0)
{
    int temp_s2;
    int temp_v0;
    int temp_s1;
    D_800F4538_unkC54* s0 = &D_800F4538[arg0]->unkC54;

    temp_s1 = s0->unk542;
    temp_s2 = s0->unk544;
    temp_v0 = func_800AD714(D_800F4538[arg0], s0, 3);
    s0->unk542 = temp_s1;
    s0->unk544 = temp_s2;
    return temp_v0;
}

void func_8009F940(int arg0, int arg1, D_800F4538_unk58_2* arg2, D_800F4538_unk58_2* arg3)
{
    D_800F4538_t* temp_t0 = D_800F4538[arg0];

    if (temp_t0 != NULL) {
        temp_t0->unk17FD = arg1;
        if (arg1 != 0) {
            *(int*)&temp_t0->unk6F4 = *(int*)arg2;
            temp_t0->unk6F8 = *arg3;
        }
    }
}

void func_8009F990(int arg0, D_800F4538_unk64* arg1)
{
    int i;

    if (arg0 == -1) {
        for (i = 0; i < 17; ++i) {
            func_8009F9F4(i, arg1);
        }
    } else {
        func_8009F9F4(arg0, arg1);
    }
}

void func_8009F9F4(int arg0, D_800F4538_unk64* arg1)
{
    int temp_a2;
    D_800F4538_t* temp_s0 = D_800F4538[arg0];

    if (temp_s0 == NULL) {
        return;
    }

    temp_a2 = arg1->unk0;

    if (temp_a2 == 0) {
        temp_s0->unk17E4.unk1 = 0;
        temp_s0->unk17E4.unk2 = 0;
    } else if (temp_a2 == 1) {
        if (arg1->unk3 == 0) {
            temp_s0->unk17E4 = *arg1;
        } else {
            int sp10;
            int sp14;
            int temp_v1;

            temp_s0->unk17E8 = *arg1;
            temp_s0->unk17E4.unk3 = arg1->unk3;
            temp_v1 = temp_s0->unk17E4.unk0;

            if (temp_v1 == 0) {
                func_800AD62C(arg0, &sp10, &sp14, arg0);
                temp_s0->unk17E4.unk1 = sp10;
                temp_s0->unk17E4.unk2 = sp14;
            } else if (temp_v1 == temp_a2) {
                func_800AD62C(arg0, &sp10, &sp14, arg0);
                if (temp_s0->unk17E4.unk1 == 0) {
                    temp_s0->unk17E4.unk1 = sp10;
                }
                if (temp_s0->unk17E4.unk2 == 0) {
                    temp_s0->unk17E4.unk2 = sp14;
                }
            } else if (temp_v1 == 2) {
                temp_s0->unk17E4.unk1 = 0x80;
                temp_s0->unk17E4.unk2 = temp_a2;
            }
            if (arg1->unk1 == 0) {
                temp_s0->unk17E4.unk1 = 0;
            }
            if (arg1->unk2 == 0) {
                temp_s0->unk17E4.unk2 = 0;
            }
        }
    }
    temp_s0->unk17E4.unk0 = arg1->unk0;
}

void func_8009FB64(VECTOR* arg0)
{
    int i;

    D_800F4438 = *arg0;

    for (i = 0; i < 17; ++i) {
        if (D_800F4538[i] != NULL) {
            D_800F4538[i]->unk183C = D_800F2458.unk1FE0;
        }
    }
}

int func_8009FBD8(int arg0, int arg1)
{
    int _[2] __attribute__((unused));
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 == NULL) {
        return -1;
    }

    if (arg1 == -1) {
        temp_a0->unk6E5 = 0xD;
    } else {
        temp_a0->unk6E5 = arg1;
    }

    return 0;
}

int func_8009FC20(int arg0, int* arg1)
{
    int _[2] __attribute__((unused));
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 == NULL) {
        return -1;
    }

    *arg1 = temp_a0->unk6E5;

    return 0;
}

int func_8009FC60(int arg0, int arg1, SVECTOR* arg2, int arg3)
{
    int _[2] __attribute__((unused));
    D_800F4538_t* temp_s0 = D_800F4538[arg0];

    if (temp_s0 == NULL) {
        return -1;
    }

    if (func_800A152C(arg0, 2, 3) < 0) {
        return -2;
    }

    temp_s0->unk17FC = arg1;
    if (arg2 == NULL) {
        temp_s0->unk17F4.vx = temp_s0->unk16;
        temp_s0->unk17F4.vy = temp_s0->unk14;
    } else {
        temp_s0->unk17F4 = *arg2;
    }
    if (arg3 == -1) {
        func_8009FD38(temp_s0);
    } else {
        temp_s0->unk17F4.pad = arg3;
    }
    return 0;
}

void func_8009FD38(D_800F4538_t* arg0)
{
    arg0->unk17F4.pad = 30;
    if (arg0->unk63C > 128) {
        arg0->unk17F4.pad = 20;
    }
}

int func_8009FD5C(int arg0, int arg1, int arg2)
{
    int _[2] __attribute__((unused));
    D_800F45E0_t* temp_t0;
    D_800F4538_unk64* var_s0;
    D_800F4538_t* temp_a3 = D_800F4538[arg0];

    if (temp_a3 != NULL) {
        var_s0 = &temp_a3->unk64;
    } else {
        temp_t0 = D_800F45E0[arg0];
        if (temp_t0 == NULL) {
            return -1;
        }
        var_s0 = &temp_t0->unk64;
    }

    if (var_s0->unk0 == 0) {
        var_s0->unk1 = 0;
        var_s0->unk2 = (var_s0->unk2 & 0xFC) | (arg1 & 1);
        if (temp_a3 != NULL) {
            vs_main_loadClut((u_short*)temp_a3->unk1424, temp_a3->unkF + 0x16, 0, 0xA0);
        } else {
            vs_main_loadClut(
                (u_short*)&temp_t0->unk6C[6], 0x1F, temp_t0->unkF * 0x10, 0x10);
        }
    }

    if (arg2 == -1) {
        var_s0->unk0 = 0xFF;
    } else {
        if (arg2 >= 8u) {
            return -2;
        }
        var_s0->unk0 |= 1 << (7 - arg2);
    }
    return 0;
}

int func_8009FE74(int arg0, int arg1)
{
    D_800F4538_t* temp_v0 = D_800F4538[arg0];
    u_char* a0;

    if (temp_v0 == NULL) {
        if (D_800F45E0[arg0] == NULL) {
            return -1;
        }
        a0 = (u_char*)D_800F45E0[arg0] + 0x64;
    } else {
        a0 = (u_char*)temp_v0 + 0x64;
    }

    if (arg1 == -1) {
        *a0 = 0;
    } else {
        int v1;
        if (arg1 > 7u) {
            return -2;
        }
        v1 = ((1 << (7 - arg1)) ^ 0xFF);
        *a0 &= v1;
    }
    return 0;
}

void func_8009FF08(int arg0, int arg1, int arg2, int arg3)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (arg1 != -1) {
        if (temp_a0->unk12 != 0xFF) {
            if (D_800F4538[temp_a0->unk12] != NULL) {
                --D_800F4538[temp_a0->unk12]->unk5AC_4;
            }
        }
        temp_a0->unk12 = arg1;
        temp_a0->unk13 = arg2;
    }
    *(int*)&temp_a0->unk1C.vx = 0;
    *(int*)&temp_a0->unk1C.vz = 0;
    temp_a0->unk1A = 0;
    *(int*)&temp_a0->unk24 = 0;
    temp_a0->unk28 = 0;
    temp_a0->unk18 = 0;
    temp_a0->unk9_5 = 1;
}

int func_8009FFA8(int arg0, int arg1)
{
    int _[2] __attribute__((unused));

    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    int temp_v1 = temp_a0->unk12;

    if (temp_v1 == 0xFF) {
        return -2;
    }

    if ((temp_v1 > 16) || (D_800F4538[temp_v1]->unk0 == 0)) {
        return -1;
    }

    temp_a0->unk9_5 = 0;
    // BUG: no return value, in practice it isn't read by the only caller.
}

int func_800A0024(int arg0, func_800A0024_t* arg1)
{
    D_800F45E0_t* temp_s0;
    int var_v0_2;

    // BUG: Check performed on garbage
    if (temp_s0 == 0) {
        return -1;
    }

    temp_s0 = D_800F45E0[arg0];

    if (temp_s0->unk12 != 0xFF) {
        return -1;
    }

    if ((temp_s0->unk6C[8].unk0_3)) {
        return -1;
    }

    if (temp_s0->unk1A != 0) {
        return -1;
    }

    *(int*)&arg1->unk0 = *(int*)&temp_s0->unk5C;
    arg1->unk3 = temp_s0->unk6C[8].unk2;
    var_v0_2 = func_800A6EE8(&temp_s0->unk1C, 0, 0, 0) - temp_s0->unk1E;
    if (var_v0_2 < 0) {
        var_v0_2 += 0x7F;
    }
    arg1->unk1 = var_v0_2 >> 7;
    arg1->unk4 = *(int*)&temp_s0->unk1C;
    arg1->unk8 = *(int*)&temp_s0->unk20;
    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_800A0104);

int func_800A01C8(int arg0, int arg1, int arg2, int arg3)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 == NULL) {
        return -1;
    }

    temp_a0->unk6E0 = arg1;
    temp_a0->unk6E1 = arg2;
    temp_a0->unk6E2 = arg3;

    return 0;
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_800A0204);

int func_800A0618(int arg0, int arg1, int arg2, int arg3)
{
    D_800F4538_t* temp_s0;

    int v0 = func_800A0204(arg0, arg1, 0, arg2);

    if (v0 < 0) {
        return v0;
    }

    if (arg3 == 0) {
        return 0;
    }

    arg3 -= vs_gametime_tickspeed / 2;
    temp_s0 = D_800F4538[arg0];

    if (arg3 > 0) {
        temp_s0->unk5B2 = arg3;
        func_800AFA28(temp_s0, &temp_s0->unkC54, 1);
    }

    temp_s0->unk5B2 = 1;

    return 0;
}

void func_800A06B8(D_800F4538_t* arg0, int arg1)
{
    D_800F4538_unk1864* a2 = &arg0->unk1864;
    a2->unk5 = 0;
    if (arg1 == 0) {
        a2->unkC = arg0->unk64E;
        a2->unkE = arg0->unk650;
        a2->unk8 = 0;
    } else {
        a2->unk10 = arg0->unk64E - a2->unkC;
        a2->unk12 = arg0->unk650 - a2->unkE;
        a2->unkA = -a2->unk8;
    }
    a2->unk4 = arg1;
    a2->unk5 = arg1;
}

int func_800A071C(int arg0, D_800F4538_unk58_2* arg1)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 != NULL) {
        arg1->unk0 = temp_a0->unk6F2;
        arg1->unk1 = temp_a0->unk6F1;
        arg1->unk2 = temp_a0->unk6F0;
        return 0;
    }
    return -1;
}

int func_800A0768(int arg0, D_800F4538_unk58_2* arg1)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 != NULL) {
        temp_a0->unk6F2 = arg1->unk0;
        temp_a0->unk6F1 = arg1->unk1;
        temp_a0->unk6F0 = arg1->unk2;
        return 0;
    }
    return -1;
}

int func_800A07B4(int arg0, D_800F4538_unk58_2* arg1)
{
    if (D_800F4538[arg0] == NULL) {
        return -1;
    }

    *arg1 = D_800F4538[arg0]->unk58;
    return 0;
}

int func_800A07FC(int arg0, D_800F4538_unk58_2* arg1)
{
    D_800F4538_t* temp_a2 = D_800F4538[arg0];

    if (temp_a2 == NULL) {
        return -1;
    }

    if (arg1 == NULL) {
        temp_a2->unk5AC_8 = 0;
    } else {
        temp_a2->unk5AC_8 = 1;
        temp_a2->unk58 = *arg1;
    }

    return 0;
}

void func_800A0870(int arg0) { D_800E8FC0 = arg0; }

void func_800A087C(int actorId, int arg1)
{
    D_800F4538_t* temp_t0 = D_800F4538[actorId];

    if (temp_t0 == NULL) {
        D_800F45E0_t* temp_a0 = D_800F45E0[actorId];
        if (temp_a0 != NULL) {
            temp_a0->unk8_0 = (arg1 & 1) ^ 1;
            temp_a0->unk8_1 = arg1 >> 1;
        }
    } else {
        D_800F4588_t* temp_a2;
        int new_var;

        temp_t0->unk8_0 = (arg1 & 1) ^ 1;
        temp_t0->unk8_1 = arg1 >> 1;
        temp_t0->unk8_2 = arg1 >> 2;
        temp_t0->unk9_7 = arg1 >> 6;

        temp_a2 = D_800F4588[actorId * 2];
        new_var = (arg1 >> 11) & 1;
        if (temp_a2 != NULL) {
            temp_a2->unk8_4 = new_var;
        }

        temp_a2 = D_800F4588[actorId * 2 + 1];
        new_var = (arg1 >> 12) & 1;
        if (temp_a2 != NULL) {
            temp_a2->unk8_4 = new_var;
        }

        if (temp_t0->unk17FD >= 2) {
            func_800A087C(temp_t0->unk17FD, arg1);
        }
    }
}

void func_800A09D8(int arg0, int arg1)
{
    if (D_800F4538[arg0] != NULL) {
        D_800F4538[arg0]->unk5AC_24 = arg1;
    }
}

void func_800A0A1C(int arg0, int arg1)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (D_800F4538[arg0] != NULL) {
        temp_a0->unk5AC_9 = arg1;
        temp_a0->unk5AC_11 = arg1 >> 1;
    }
}

int func_800A0A74(int arg0)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (temp_a0 != NULL) {
        int var_v1 = temp_a0->unk5AC_9;
        if ((temp_a0->unk5AC_11 << 11)) {
            var_v1 |= 2;
        }
        return var_v1;
    }
}

void func_800A0ABC(int arg0)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (temp_a0 != NULL) {
        temp_a0->unk1840 = 0;
        temp_a0->unk1846 = 0;
        temp_a0->unk5AC_15 = 0;
    }
}

void func_800A0AFC(int arg0, int arg1, int arg2)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (temp_a0 != NULL) {
        temp_a0->unk5BA = arg1 / ONE;
        temp_a0->unk5B9 = arg2 / ONE;
        if (arg1 >= arg2) {
            temp_a0->unk5B9 = 0xFF;
        }
    }
}

void func_800A0B5C(int arg0, int arg1, int arg2)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];

    if (temp_a0 == NULL) {
        return;
    }

    if (arg1 < 0) {
        arg1 = 1;
    }
    temp_a0->unk5C2 = arg1;

    if (arg2 < 0) {
        arg2 = 1;
    }
    temp_a0->unk5C0 = arg2;
}

void func_800A0BA0(int arg0, int* arg1, int* arg2)
{
    D_800F4538_t* temp_a0 = D_800F4538[arg0];
    if (temp_a0 != 0) {
        *arg1 = temp_a0->unk5C2;
        *arg2 = temp_a0->unk5C0;
    }
}

INCLUDE_ASM("build/src/BATTLE/BATTLE.PRG/nonmatchings/30D14", func_800A0BE0);

int func_800A1108(int arg0, void* arg1)
{
    D_800F4538_t* var_v1 = D_800F4538[arg0];

    if (var_v1 == NULL) {
        var_v1 = (D_800F4538_t*)D_800F45E0[arg0];
        if (var_v1 == NULL) {
            return -1;
        }
    }

    ((int*)arg1)[0] = *(int*)&var_v1->unk5C;
    ((int*)arg1)[1] = *(int*)&var_v1->unk1C.vx;
    ((int*)arg1)[2] = *(int*)&var_v1->unk1C.vz;
    ((u_short*)arg1)[5] = var_v1->unk26;
    return 0;
}

int func_800A1178(int arg0, int arg1, MATRIX* arg2, u_long* arg3)
{
    int temp_v0 = func_800A152C(arg0, arg1, 0);
    if (temp_v0 < 0) {
        return temp_v0;
    }
    func_800A11D8(arg0, temp_v0, arg2, arg3);
    return 0;
}

void func_800A11D8(int arg0, int arg1, MATRIX* arg2, u_long* arg3)
{
    D_800F4538_t* var_t0 = D_800F4538[arg0];
    void** p;

    if (var_t0 == NULL) {
        var_t0 = (D_800F4538_t*)D_800F45E0[arg0];
        if (var_t0 == NULL) {
            return;
        }
    }
    *arg2 = var_t0->unk6C[arg1];
    p = (void**)&(var_t0->unk68 + arg1)[4];
    *arg3 = *(u_long*)p;
}

int func_800A1280(int arg0, int arg1, SVECTOR* arg2, int arg3)
{
    long sp10;
    long sp14;
    long sp18;
    int var_v0;
    int v1;

    if (arg1 == 0xFB) {
        short* new_var;
        unsigned int new_var2;
        D_800F4538_t* temp_a1 = D_800F4538[arg0];

        if (temp_a1 == NULL) {
            D_800F45E0_t* temp_v1 = D_800F45E0[arg0];
            if (temp_v1 == NULL) {
                return -1;
            }
            arg2->vx = temp_v1->unk1C;
            arg2->vz = temp_v1->unk20;
            arg2->vy = temp_v1->unk1E - 0xC0;
        } else {
            if (temp_a1->unkB_0) {
                return -1;
            }
            arg2->vx = temp_a1->unk1C.vx;
            arg2->vz = temp_a1->unk1C.vz;
            arg2->vy = temp_a1->unk1C.vy - temp_a1->unk646;
        }

        SetRotMatrix((MATRIX*)0x1F800014);
        SetTransMatrix((MATRIX*)0x1F800014);
        arg2->vz = RotTransPers(arg2, &sp10, &sp14, &sp18);
        arg2->vx = sp10;
        new_var = &((short*)(&sp10))[1];
        new_var2 = *new_var;
        arg2->vy = new_var2;

        return 0;
    }

    var_v0 = func_800A152C(arg0, arg1, 0);
    sp14 = var_v0;

    if (var_v0 < 0) {
        return var_v0;
    }

    v1 = func_800A141C(arg0, var_v0, (int*)arg2, arg3);
    sp14 = v1;
    if (v1 < 0) {
        return v1;
    }
    return 0;
}

int func_800A13EC(int arg0, int arg1, int* arg2, int arg3)
{
    int var_v0 = func_800A141C(arg0, arg1, arg2, arg3);
    if (var_v0 < 0) {
        return var_v0;
    }
    return 0;
}
