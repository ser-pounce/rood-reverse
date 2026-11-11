#pragma once
#include <sys/types.h>
#include <libgte.h>
#include "tilePosition.h"

typedef struct {
    u_char dataType;
    signed char index;
    short modelId;
    void* unk4;
    u_long dataAddr;
    vs_battle_tilePosition unkC;
    u_char actorId;
    char unk11;
    u_char material;
    u_char variant;
} vs_ObjectData;

extern char vs_battle_loadObjectDataState;

int vs_battle_getEmptyObjectDataSlot(void);
int vs_battle_populateDataSlot(vs_ObjectData*);
int vs_battle_processObjectDataQueue(void);
