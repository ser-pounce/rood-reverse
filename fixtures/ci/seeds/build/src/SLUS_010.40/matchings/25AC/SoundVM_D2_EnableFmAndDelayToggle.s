nonmatching SoundVM_D2_EnableFmAndDelayToggle, 0x44

glabel SoundVM_D2_EnableFmAndDelayToggle
    /* D2A0 8001CAA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D2A4 8001CAA4 1000BFAF */  sw         $ra, 0x10($sp)
    /* D2A8 8001CAA8 0000828C */  lw         $v0, 0x0($a0)
    /* D2AC 8001CAAC 00000000 */  nop
    /* D2B0 8001CAB0 00004390 */  lbu        $v1, 0x0($v0)
    /* D2B4 8001CAB4 01004224 */  addiu      $v0, $v0, 0x1
    /* D2B8 8001CAB8 03006010 */  beqz       $v1, .L8001CAC8
    /* D2BC 8001CABC 000082AC */   sw        $v0, 0x0($a0)
    /* D2C0 8001CAC0 B3720008 */  j          .L8001CACC
    /* D2C4 8001CAC4 01006224 */   addiu     $v0, $v1, 0x1
  .L8001CAC8:
    /* D2C8 8001CAC8 01010224 */  addiu      $v0, $zero, 0x101
  .L8001CACC:
    /* D2CC 8001CACC 7470000C */  jal        SoundVM_C6_EnableFmVoices
    /* D2D0 8001CAD0 CE0082A4 */   sh        $v0, 0xCE($a0)
    /* D2D4 8001CAD4 1000BF8F */  lw         $ra, 0x10($sp)
    /* D2D8 8001CAD8 00000000 */  nop
    /* D2DC 8001CADC 0800E003 */  jr         $ra
    /* D2E0 8001CAE0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SoundVM_D2_EnableFmAndDelayToggle
