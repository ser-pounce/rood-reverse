#pragma once

/* Save data packaging shared by the title and menu overlays. The including file defines
 * the following overlay specific steps, which refer to the locals of the function:
 * PACKAGE_SAVE_PREPARE, KEYSTREAM_BITS, PACKAGE_SAVE_CLEAR_CONTAINER,
 * PACKAGE_SAVE_UPDATE_SAVE_COUNT and PACKAGE_SAVE_SET_LOCATION. */

/**
 * Builds the save metadata and payload from current game state, then encodes
 * the protected save-data region.
 *
 * @param targetFile Zero-based target slot used in the displayed save metadata.
 */
static void _packageGameSaveData(int targetFile)
{
#pragma sjis(start)
    static const u_char _defaultFileTitle[] =
        "ＶＡＧＲＡＮＴ　ＳＴＯＲＹ　ＦＩＬＥ　１　　　００：００：００　";
#pragma sjis(end)

    long i;
    int j;
    int var_a0;
    u_char const* s0 = _defaultFileTitle;
    savedata_t* savedata = (savedata_t*)_spmcimg;
    savedata_t* savedata2 = savedata + 1;
    savedata_t* savedata3 = savedata;
    savedata_unk180_t* s5 = &savedata->unk180;

    PACKAGE_SAVE_PREPARE();
    memset(savedata, 0, sizeof *savedata);
    ((char*)&savedata->fileInfo.key)[0] = 0x53;
    ((char*)&savedata->fileInfo.key)[1] = 0x43;
    ((char*)&savedata->fileInfo.key)[2] = 0x11;
    ((char*)&savedata->fileInfo.key)[3] = 3;
    _rMemcpy(&savedata->fileInfo.unk4, s0, sizeof savedata->fileInfo.unk4);
    savedata->fileInfo.unk4.unk20[3] += (targetFile << 8);

    if (vs_main_gametime.t.h == 100) {
        savedata->fileInfo.unk4.unk20[6] = 0x5082;
    } else {
        savedata->fileInfo.unk4.unk20[7] += ((vs_main_gametime.t.h / 10) << 8);
        savedata->fileInfo.unk4.unk20[8] += ((vs_main_gametime.t.h % 10) << 8);
        savedata->fileInfo.unk4.unk20[10] += ((vs_main_gametime.t.m / 10) << 8);
        savedata->fileInfo.unk4.unk20[11] += ((vs_main_gametime.t.m % 10) << 8);
        savedata->fileInfo.unk4.unk20[13] += ((vs_main_gametime.t.s / 10) << 8);
        savedata->fileInfo.unk4.unk20[14] += ((vs_main_gametime.t.s % 10) << 8);
    }
    savedata3->fileInfo.unk4.unk20[15] = 0;
    _rMemcpy(savedata3->fileInfo.unk60, _mcData->unk400[targetFile],
        sizeof savedata->fileInfo.unk60);
    _rMemcpy(savedata3->unk80, _mcData->unk4E0[targetFile], sizeof savedata->unk80);

    if (vs_main_settings.slotState == 0) {
        vs_main_settings.slotState = KEYSTREAM_BITS(0x20);
        if (vs_main_settings.slotState < 3) {
            vs_main_settings.slotState = 0x17385CA9;
        }
        PACKAGE_SAVE_CLEAR_CONTAINER();
    }

    vs_main_settings.key = KEYSTREAM_BITS(0x20);
    s5->unk180.key = vs_main_settings.key;
    s5->unk180.base.slotState = vs_main_settings.slotState;
    vs_main_settings.saveFileGeneration = 0;

    for (i = 0; i < 5; ++i) {
        if (_saveFileInfo[i].unk4.base.slotState >= slotStateInUse) {
            if (vs_main_settings.saveFileGeneration
                < _saveFileInfo[i].unk4.base.generation) {
                vs_main_settings.saveFileGeneration =
                    _saveFileInfo[i].unk4.base.generation;
            }
        }
    }
    s5->unk180.base.generation = ++vs_main_settings.saveFileGeneration;

    if (vs_main_settings.cumulativeSaveCount < 9999) {
        ++vs_main_settings.cumulativeSaveCount;
    }

    PACKAGE_SAVE_UPDATE_SAVE_COUNT();

    s5->unk180.base.unk8 = 0x20000107;
    s5->stats.gameTime.t = vs_main_gametime.t;
    s5->stats.currentHP = D_80060068.unk0.currentHP;
    s5->stats.maxHP = D_80060068.unk0.maxHP;
    s5->stats.cumulativeSaveCount = vs_main_settings.cumulativeSaveCount;
    s5->stats.currentGameSaveCount = vs_main_settings.currentGameSaveCount;
    PACKAGE_SAVE_SET_LOCATION();
    s5->stats.clearCount = vs_main_stateFlags.clearCount;
    s5->stats.currentMP = D_80060068.unk0.currentMP;
    s5->stats.maxMP = D_80060068.unk0.maxMP;
    _rMemcpy(savedata->stateFlags, &vs_main_stateFlags, sizeof savedata->stateFlags);
    _rMemcpy(savedata->actionsLearned, vs_main_actionsLearned,
        sizeof savedata->actionsLearned);
    _rMemcpy(savedata->mapStatus, &vs_main_mapStatus, sizeof savedata->mapStatus);
    _rMemcpy(&savedata->settings, &vs_main_settings, sizeof savedata->settings);
    _rMemcpy(&savedata->unk6C8, &D_80060068, sizeof savedata->unk6C8);
    _rMemcpy(&savedata->inventory, &vs_main_inventory, sizeof savedata->inventory);
    _rMemcpy(&savedata->unk16C8, &vs_main_inventoryIndices, sizeof savedata->unk16C8);
    _rMemcpy(&savedata->unk1778, &D_80061068, sizeof savedata->unk1778);
    _rMemcpy(&savedata->scoreData, &vs_main_scoredata, sizeof savedata->scoreData);
    _rMemcpy(&savedata->containerData, &savedata2->containerData,
        sizeof savedata->containerData);
    savedata->unk1898 = D_80060064;
    _rMemcpy(savedata->unk189C, D_80061078, sizeof savedata->unk189C);
    _rMemcpy(&savedata->artsStatus, &vs_main_artsStatus, sizeof savedata->artsStatus);

    for (i = 0; i < 92; ++i) {
        var_a0 = 0;
        if (i != 1) {
            for (j = 0; j < 256; ++j) {
                var_a0 ^= _spmcimg[i * 0x100 + j];
            }
            s5->checksums[i] = var_a0;
        }
    }
    var_a0 = 0;
    for (j = 0; j < 256; ++j) {
        var_a0 ^= _spmcimg[j + 256];
    }
    s5->checksums[1] = var_a0;
    for (i = (long)&((savedata_t*)0)->unk180.unk180.base.slotState;
        i < (int)sizeof(savedata_t); ++i) {
        _spmcimg[i] += KEYSTREAM_BITS(8);
    }
}
