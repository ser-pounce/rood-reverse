nonmatching Sound_RestoreChannelVolumeFromMasterFade, 0x10

glabel Sound_RestoreChannelVolumeFromMasterFade
    /* 5A10 80015210 0380023C */  lui        $v0, %hi(D_80037844)
    /* 5A14 80015214 4478428C */  lw         $v0, %lo(D_80037844)($v0)
    /* 5A18 80015218 0800E003 */  jr         $ra
    /* 5A1C 8001521C 600082AC */   sw        $v0, 0x60($a0)
endlabel Sound_RestoreChannelVolumeFromMasterFade
