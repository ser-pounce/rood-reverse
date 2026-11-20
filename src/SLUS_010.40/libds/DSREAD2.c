#include "common.h"
#include <libds.h>

extern int D_80039C80;
void data_ready_callback(void);
void func_80026238(void);

int DsRead2(DslLOC* pos, int mode)
{
    void* oldData;
    DslCB oldReady;
    int ret;

    if (mode & DslModeStream) {
        if (mode & DslModeSize1) {
            D_80039C80 = 0;
        } else {
            D_80039C80 = 1;
        }
        oldData = DsDataCallback(data_ready_callback);
        oldReady = DsReadyCallback((DslCB)func_80026238);
        ret = DsPacket(mode, pos, DslReadS, NULL, -1);
        if (ret == 0) {
            DsDataCallback(oldData);
            DsReadyCallback(oldReady);
            return 0;
        }
        return ret;
    }
    return DsPacket(mode, pos, DslReadS, NULL, -1);
}

void func_80026238(void) { StCdInterrupt(); }
