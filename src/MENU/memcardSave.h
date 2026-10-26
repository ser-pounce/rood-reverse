#pragma once

/* Memorycard save helpers shared by the title and menu overlays. The including file
 * defines _memcardFilenameTemplate first. */

static saveFileInfo_t* _saveFileInfo;

/**
 * Finds the save slot with the greatest generation number.
 *
 * @return Zero-based slot index; returns zero when no active slot is found.
 */
static u_int _getNewestSaveFile(void)
{
    u_int i;
    u_int maxCounter = 0;
    u_int fileIndex = 0;

    for (i = 0; i < 5; ++i) {
        if (_saveFileInfo[i].unk4.base.slotState >= 3) {
            if (maxCounter < _saveFileInfo[i].unk4.base.generation) {
                maxCounter = _saveFileInfo[i].unk4.base.generation;
                fileIndex = i;
            }
        }
    }
    return fileIndex;
}

/**
 * Finds the active save by matching its identity and generation to settings.
 *
 * @return One-based file number, or zero when the active save is absent.
 */
static int _findCurrentSaveOnActiveMemcard(void)
{
    int i;
    for (i = 0; i < 5; ++i) {
        if ((_saveFileInfo[i].unk4.base.slotState >= slotStateInUse)
            && (_saveFileInfo[i].unk4.base.slotState == vs_main_settings.slotState)
            && (_saveFileInfo[i].key == vs_main_settings.key)
            && (_saveFileInfo[i].unk4.stats.cumulativeSaveCount
                == vs_main_settings.cumulativeSaveCount)
            && (_saveFileInfo[i].unk4.base.generation
                == vs_main_settings.saveFileGeneration)) {
            return i + 1;
        }
    }
    return 0;
}

/**
 * Recognizes a save filename and decodes its permanent or temporary slot.
 *
 * @return 1-5 for permanent files, -1 to -5 for temporary files, or zero if
 * the name is not a save file.
 */
static int _memcardFileNumberFromFilename(char* filename)
{
    int i;
    char const* gameCode = &_memcardFilenameTemplate[5];

    for (i = 0; i < 15; ++i) {
        if (gameCode[i] != filename[i]) {
            return 0;
        }
    }

    i = filename[15] - 'A';

    if (i < 5u) {
        return -(filename[15] - 'A' + 1);
    }

    i = filename[15] - '1';

    if (i < 5u) {
        return filename[15] - '0';
    }

    return 0;
}

/**
 * Checksums the requested save-data sectors and validates the info sector.
 *
 * @return Nonzero if a sector checksum differs or the info-sector checksum is
 * nonzero; otherwise zero.
 */
static int _verifySaveChecksums(savedata_t data[], int sectorCount)
{
    int checksum;
    int i;
    int j;
    char* p = (char*)data;

    for (i = 0; i < sectorCount; ++i) {
        checksum = 0;
        if (i != 1) {
            for (j = 0; j < 256; ++j) {
                checksum ^= p[j];
            }

            if (data->unk180.checksums[i] != checksum) {
                return 1;
            }
        }
        p += 256;
    }

    p = data->unk100;
    checksum = 0;
    for (j = 0; j < 256; ++j) {
        checksum ^= p[j];
    }

    return checksum != 0;
}

/**
 * Decodes count bytes in place using the save format's key-driven byte stream.
 */
static void _decode(u_int key, void* buf, int count)
{
    for (; count != 0; --count) {
        key *= 0x19660D;
        *((char*)buf++) -= key >> 24;
    }
}
