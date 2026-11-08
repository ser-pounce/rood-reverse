#pragma once

typedef struct {
    int lba;
    int size;
} vs_main_CdFile;

enum vs_main_CdQueueState {
    vs_main_CdQueueStateFree = 0,
    vs_main_CdQueueStateAllocated = 1,
    vs_main_CdQueueStateReading = 2,
    vs_main_CdQueueStateEnqueued = 3,
    vs_main_CdQueueStateLoaded = 4,
    vs_main_CdQueueStateError = 6,
    vs_main_CdQueueStateDispatched = 7,
};

typedef struct {
    short state;
    short priority;
    vs_main_CdFile cdFile;
    UNUSED int unused;
    void* vram;
} vs_main_CdQueueSlot;

vs_main_CdQueueSlot* vs_main_allocateCdQueueSlot(vs_main_CdFile const* file);
void vs_main_freeCdQueueSlot(vs_main_CdQueueSlot* slot);
void vs_main_cdEnqueue(vs_main_CdQueueSlot* slot, void* vram);
void vs_main_cdEnqueuePriority(vs_main_CdQueueSlot* slot, void* vram);
int vs_main_diskLoadFile(int sector, int bytes, void* vram);
int vs_main_streamXa(int sector, int cdVolume);
int vs_main_checkStreamXaEnd(void);
