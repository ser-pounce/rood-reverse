nonmatching SoundVM_A8_ChannelVolume, 0x30

glabel SoundVM_A8_ChannelVolume
    /* BD98 8001B598 0000828C */  lw         $v0, 0x0($a0)
    /* BD9C 8001B59C F800838C */  lw         $v1, 0xF8($a0)
    /* BDA0 8001B5A0 00004580 */  lb         $a1, 0x0($v0)
    /* BDA4 8001B5A4 01004224 */  addiu      $v0, $v0, 0x1
    /* BDA8 8001B5A8 03006334 */  ori        $v1, $v1, 0x3
    /* BDAC 8001B5AC 000082AC */  sw         $v0, 0x0($a0)
    /* BDB0 8001B5B0 880080A4 */  sh         $zero, 0x88($a0)
    /* BDB4 8001B5B4 F80083AC */  sw         $v1, 0xF8($a0)
    /* BDB8 8001B5B8 8A0080A4 */  sh         $zero, 0x8A($a0)
    /* BDBC 8001B5BC C02D0500 */  sll        $a1, $a1, 23
    /* BDC0 8001B5C0 0800E003 */  jr         $ra
    /* BDC4 8001B5C4 480085AC */   sw        $a1, 0x48($a0)
endlabel SoundVM_A8_ChannelVolume
