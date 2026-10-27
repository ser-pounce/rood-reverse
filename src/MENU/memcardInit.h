#pragma once

/* Memory card support loading shared by the title and menu overlays. The including
 * file defines MEMCARD_INIT_HOOK and MEMCARD_SHUTDOWN_HOOK, extra overlay specific work
 * done when starting and stopping. */

/**
 * Loads memorycard support data and installs card event handlers.
 *
 * Call with nonzero init to start initialization and with zero to poll;
 * returns one when ready and zero otherwise.
 */
static int _initMemcard(int init)
{
    enum state {
        none = 0,
        queueReady = 1,
        enqueued = 2,
    };

    static u_short _eventSpecs[] = { EvSpIOE, EvSpERROR, EvSpTIMOUT, EvSpNEW };
    static char _initMemcardState;
    static char _[3] __attribute__((unused));
    static vs_main_CdQueueSlot* _initMemcardCdQueueSlot;

    vs_main_CdFile cdFile;
    int i;
    u_int event;

    if (init != 0) {
        MEMCARD_INIT_HOOK();
        _spmcimg = vs_main_allocHeap(VS_SPMCIMG_BIN_SIZE);
        _mcData = (mcdata_t*)(_spmcimg + sizeof(savedata_t) * 3);
        _textTable = _mcData->textTable;
        _saveFileInfo = _mcData->saveFileInfo;
        _dirEntBuf = &_mcData->_dirEntBuf;
        cdFile.lba = VS_SPMCIMG_BIN_LBA;
        cdFile.size = VS_SPMCIMG_BIN_SIZE;
        _initMemcardCdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(_initMemcardCdQueueSlot, _spmcimg);
        _initMemcardState = none;
        return 0;
    }

    switch (_initMemcardState) {
    case none:
        if (_initMemcardCdQueueSlot->state == vs_main_CdQueueStateLoaded) {
            vs_main_freeCdQueueSlot(_initMemcardCdQueueSlot);
            _drawImage(vs_getXY(800, 256), _spmcimg, vs_getWH(224, 256));
            _initMemcardState = queueReady;
        }
        return 0;
    case queueReady:
        cdFile.lba = VS_MCDATA_BIN_LBA; // MCMAN.BIN must immediately follow MCDATA.BIN on
                                        // the disk
        cdFile.size = VS_MCDATA_BIN_SIZE + VS_MCMAN_BIN_SIZE;
        _initMemcardCdQueueSlot = vs_main_allocateCdQueueSlot(&cdFile);
        vs_main_cdEnqueue(_initMemcardCdQueueSlot, _mcData);
        _initMemcardState = enqueued;
        break;
    case enqueued:
        break;
    default:
        return 0;
    }

    if (_initMemcardCdQueueSlot->state == vs_main_CdQueueStateLoaded) {
        vs_main_freeCdQueueSlot(_initMemcardCdQueueSlot);
        vs_main_enableReset(0);
        EnterCriticalSection();

        for (i = 0; i < 8; ++i) {
            event = SwCARD;
            if (i & 4) {
                event = HwCARD;
            }
            _memcardEventDescriptors[i] =
                OpenEvent(event, _eventSpecs[i & 3], EvMdNOINTR, 0);
        }

        ExitCriticalSection();

        for (i = 0; i < 8; ++i) {
            EnableEvent(_memcardEventDescriptors[i]);
        }
        return 1;
    }
    return 0;
}

/**
 * Disables and closes memorycard events and releases the support data.
 */
static void _shutdownMemcard(void)
{
    int i;

    for (i = 0; i < 8; ++i) {
        DisableEvent(_memcardEventDescriptors[i]);
    }

    EnterCriticalSection();

    for (i = 0; i < 8; ++i) {
        CloseEvent(_memcardEventDescriptors[i]);
    }

    ExitCriticalSection();
    vs_main_enableReset(1);
    vs_main_freeHeap(_spmcimg);
    MEMCARD_SHUTDOWN_HOOK();
}
