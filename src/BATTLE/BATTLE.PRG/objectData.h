#pragma once
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    u_int unk0_0 : 8;
    u_int unk0_8 : 8;
    u_int unk0_16 : 8;
    u_int unk0_24 : 8;
} vs_battle_objectData_flags;

typedef struct {
    u_char dataType;
    signed char index;
    short modelId;
    void* unk4;
    u_long dataAddr;
    vs_battle_objectData_flags unkC;
    u_char actorId;
    char unk11;
    u_char material;
    u_char variant;
} vs_battle_objectData;

extern char vs_battle_loadObjectDataState;

int vs_battle_getEmptyObjectDataSlot(void);
int vs_battle_populateDataSlot(vs_battle_objectData*);
int vs_battle_processObjectDataQueue(void);
