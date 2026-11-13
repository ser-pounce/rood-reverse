#pragma once
#include "common.h"
#include <sys/types.h>

typedef struct {
    int lba;
    u_int size;
} vs_CdFile;

enum CdQueueState {
    CdQueueStateFree = 0,
    CdQueueStateAllocated = 1,
    CdQueueStateReading = 2,
    CdQueueStateEnqueued = 3,
    CdQueueStateLoaded = 4,
    CdQueueStateError = 6,
    CdQueueStateDispatched = 7,
};

typedef struct {
    short state;
    short priority;
    vs_CdFile cdFile;
    UNUSED int unused;
    void* vram;
} vs_CdQueueSlot;

vs_CdQueueSlot* vs_main_allocateCdQueueSlot(vs_CdFile const* file);
void vs_main_freeCdQueueSlot(vs_CdQueueSlot* slot);
void vs_main_cdEnqueue(vs_CdQueueSlot* slot, void* vram);
void vs_main_cdEnqueuePriority(vs_CdQueueSlot* slot, void* vram);
int vs_main_diskLoadFile(int sector, u_int bytes, void* vram);
int vs_main_streamXa(int sector, int cdVolume);
int vs_main_checkStreamXaEnd(void);
