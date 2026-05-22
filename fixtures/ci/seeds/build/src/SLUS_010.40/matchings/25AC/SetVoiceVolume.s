nonmatching SetVoiceVolume, 0x48

glabel SetVoiceVolume
    /* 4358 80013B58 0800E010 */  beqz       $a3, .L80013B7C
    /* 435C 80013B5C 1800A700 */   mult      $a1, $a3
    /* 4360 80013B60 12280000 */  mflo       $a1
    /* 4364 80013B64 00000000 */  nop
    /* 4368 80013B68 00000000 */  nop
    /* 436C 80013B6C 1800C700 */  mult       $a2, $a3
    /* 4370 80013B70 C2290500 */  srl        $a1, $a1, 7
    /* 4374 80013B74 12300000 */  mflo       $a2
    /* 4378 80013B78 C2310600 */  srl        $a2, $a2, 7
  .L80013B7C:
    /* 437C 80013B7C 801F033C */  lui        $v1, (0x1F801C00 >> 16)
    /* 4380 80013B80 001C6334 */  ori        $v1, $v1, (0x1F801C00 & 0xFFFF)
    /* 4384 80013B84 00110400 */  sll        $v0, $a0, 4
    /* 4388 80013B88 21104300 */  addu       $v0, $v0, $v1
    /* 438C 80013B8C FF7FA330 */  andi       $v1, $a1, 0x7FFF
    /* 4390 80013B90 000043A4 */  sh         $v1, 0x0($v0)
    /* 4394 80013B94 FF7FC330 */  andi       $v1, $a2, 0x7FFF
    /* 4398 80013B98 0800E003 */  jr         $ra
    /* 439C 80013B9C 020043A4 */   sh        $v1, 0x2($v0)
endlabel SetVoiceVolume
