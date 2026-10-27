#pragma once

/* Save data load and write routines shared by the title and menu overlays. */

/**
 * Reads a permanent or temporary save.
 *
 * A nonzero portFileno selects the card, file and temporary-file mode; call
 * again with zero to poll the read.
 *
 * @return Zero while pending, one when the read completes, or -1 after errors.
 */
static int _loadSaveData(int portFileno)
{
    enum state { init = 0, reading = 1 };

    static char state;
    static char port;
    static char file;
    static char isTempSave;
    static char errors;
    static short _ __attribute__((unused));
    static int fd;

    void* temp_s2 = (savedata_t*)_spmcimg + 1;

    if (portFileno != 0) {
        state = init;
        errors = 0;
        _loadSaveDataErrorOffset = 0;
        port = portFileno >> 0xC;
        isTempSave = (portFileno >> 8) & 1;
        file = portFileno & 0xF;
        _fileProgressPosition = 80;
        _filePreviousProgressCounter = 0;
        return 0;
    }

    switch (state) {
    case init: {
        int nBytes;
        char* filename;
        int new_var = 320;

        _fileProgressPosition +=
            ((_fileProgressCounter - _filePreviousProgressCounter)
                * ((_loadSaveDataErrorOffset * 20) - (_fileProgressPosition - new_var)))
            / _fileProgressTarget;
        _loadSaveDataErrorOffset = errors;
        _fileProgressTarget = 192 - (isTempSave << 7);
        _filePreviousProgressCounter = _fileProgressCounter;

        memset(temp_s2, 0, sizeof(savedata_t));

        if (file & 8) {
            filename = _memcardMakeTempFilename(port, file & 7);
        } else {
            filename = _memcardMakeFilename(port, file);
        }
        fd = open(filename, O_NOWAIT | O_RDONLY);
        if (fd == -1) {
            ++errors;
            break;
        }
        _resetMemcardEvents(memcardEventsSw);
        nBytes = sizeof(savedata_t);
        if (isTempSave != 0) {
            nBytes = 0x2000;
        }
        if (read(fd, temp_s2, nBytes) == -1) {
            close(fd);
            ++errors;
            break;
        }
        state = reading;
    }
        // fallthrough
    case reading: {
        int event = _testMemcardEvents(memcardEventsSw);
        if (event < memcardInternalEventNone) {
            close(fd);
            if (event == memcardInternalEventIoEnd) {
                return 1;
            }
            state = init;
            ++errors;
        }
        break;
    }
    }
    return errors == 3 ? -1 : 0;
}

/**
 * Saves and verifies a save file.
 *
 * A nonzero portFile selects the card and one-based destination file; call
 * again with zero to progress the write.
 *
 * @return Zero while pending, one on verified success, or -1 on failure.
 */
static int _saveFile(int portFile)
{
    enum state {
        init = 0,
        tempFileCreated = 1,
        readReady = 2,
        verifyPending = 3,
        fileVerified = 4
    };

    static char state;
    static char file;
    static char port;
    static char errors;
    static char renameErrors;
    static char _[3] __attribute__((unused));
    static int fd;

    int temp_v1_2;
    int i;
    int temp_s3;

    if (portFile != 0) {
        errors = 0;
        renameErrors = 0;
        _loadSaveDataErrorOffset = 0;
        port = portFile >> 0xC;
        file = portFile & 7;
        _fileProgressPosition = 80;
        _filePreviousProgressCounter = 0;
        state = _memcardSaveIdExists(file + 'A' - 1);
        return 0;
    }
    switch (state) {
    case init:
        if (rename(_memcardMakeFilename(port, file), _memcardMakeTempFilename(port, file))
            != 0) {
            errors = 0;
            renameErrors = 0;
            state = tempFileCreated;
        } else {
            ++renameErrors;
            errors = renameErrors >> 4;
        }
        break;
    case tempFileCreated:
        temp_v1_2 = ((_fileProgressCounter - _filePreviousProgressCounter)
                        * (320 - _fileProgressPosition))
                  / _fileProgressTarget;
        _filePreviousProgressCounter = _fileProgressCounter;
        _fileProgressTarget = 384;
        _fileProgressPosition += temp_v1_2;
        fd = open(_memcardMakeTempFilename(port, file), O_NOWAIT | O_WRONLY);
        ;
        if (fd == -1) {
            ++errors;
            break;
        }
        _resetMemcardEvents(memcardEventsSw);
        if (write(fd, _spmcimg, sizeof(savedata_t)) == -1) {
            close(fd);
            ++errors;
            break;
        }
        state = readReady;
        // fallthrough
    case readReady: {
        temp_s3 = _testMemcardEvents(memcardEventsSw);
        if (temp_s3 < memcardInternalEventNone) {
            close(fd);
            if (temp_s3 == memcardInternalEventIoEnd) {
                state = verifyPending;
                i = _fileProgressPosition;
                temp_s3 = _filePreviousProgressCounter;
                _loadSaveData((port << 12) | (file + 8));
                _fileProgressPosition = i;
                _filePreviousProgressCounter = temp_s3;
            } else {
                ++errors;
                state = tempFileCreated;
            }
        }
        break;
    }
    case verifyPending:
        temp_s3 = _loadSaveData(0);
        if (temp_s3 == 0) {
            break;
        }
        if (temp_s3 < 0) {
            return -1;
        }
        for (i = 0; i < (int)sizeof(savedata_t); ++i) {
            if (_spmcimg[i] != _spmcimg[sizeof(savedata_t) + i]) {
                break;
            }
        }
        if (i < (int)sizeof(savedata_t)) {
            return -1;
        }
        state = fileVerified;
        break;
    case fileVerified:
        if (rename(_memcardMakeTempFilename(port, file), _memcardMakeFilename(port, file))
            == 0) {
            ++renameErrors;
            errors = (renameErrors >> 4);
            break;
        }
        return 1;
    }
    return errors == 3 ? -1 : 0;
}
