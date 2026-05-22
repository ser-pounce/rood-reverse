nonmatching SoundVM_D6_EnablePitchVolumeSidechain, 0x14

glabel SoundVM_D6_EnablePitchVolumeSidechain
    /* D3A4 8001CBA4 3400828C */  lw         $v0, 0x34($a0)
    /* D3A8 8001CBA8 00000000 */  nop
    /* D3AC 8001CBAC 20004234 */  ori        $v0, $v0, 0x20
    /* D3B0 8001CBB0 0800E003 */  jr         $ra
    /* D3B4 8001CBB4 340082AC */   sw        $v0, 0x34($a0)
endlabel SoundVM_D6_EnablePitchVolumeSidechain
