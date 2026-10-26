#pragma once

/* Temporary save file cleanup shared by the title and menu overlays. */

/**
 * Removes temporary files when the corresponding permanent file also exists.
 *
 * @return A bit per removed temporary slot, or 0x80 if an erase fails.
 */
static int _deleteRedundantTempFiles(int port)
{
    int i;
    int ret = 0;

    for (i = 0; i < 5; ++i) {
        if ((_memcardSaveIdExists(i + '1') != 0)
            && (_memcardSaveIdExists(i + 'A') != 0)) {
            if (erase(_memcardMakeTempFilename(port, i + 1)) == 0) {
                return 0x80;
            }
            ret |= 1 << i;
        }
    }
    return ret;
}
