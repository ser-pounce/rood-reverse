nonmatching func_80107090, 0x90

glabel func_80107090
    /* 4890 80107090 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4894 80107094 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4898 80107098 21880000 */  addu       $s1, $zero, $zero
    /* 489C 8010709C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 48A0 801070A0 02001424 */  addiu      $s4, $zero, 0x2
    /* 48A4 801070A4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 48A8 801070A8 40011324 */  addiu      $s3, $zero, 0x140
    /* 48AC 801070AC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 48B0 801070B0 FF001224 */  addiu      $s2, $zero, 0xFF
    /* 48B4 801070B4 1180023C */  lui        $v0, %hi(_gazetteRows)
    /* 48B8 801070B8 30A24224 */  addiu      $v0, $v0, %lo(_gazetteRows)
    /* 48BC 801070BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 48C0 801070C0 02005024 */  addiu      $s0, $v0, 0x2
    /* 48C4 801070C4 2400BFAF */  sw         $ra, 0x24($sp)
  .L801070C8:
    /* 48C8 801070C8 00000292 */  lbu        $v0, 0x0($s0)
    /* 48CC 801070CC 00000000 */  nop
    /* 48D0 801070D0 06004014 */  bnez       $v0, .L801070EC
    /* 48D4 801070D4 00000000 */   nop
    /* 48D8 801070D8 9223030C */  jal        vs_battle_getMenuItem
    /* 48DC 801070DC 21202002 */   addu      $a0, $s1, $zero
    /* 48E0 801070E0 000054A0 */  sb         $s4, 0x0($v0)
    /* 48E4 801070E4 3C1C0408 */  j          .L801070F0
    /* 48E8 801070E8 180053A4 */   sh        $s3, 0x18($v0)
  .L801070EC:
    /* 48EC 801070EC 000012A2 */  sb         $s2, 0x0($s0)
  .L801070F0:
    /* 48F0 801070F0 01003126 */  addiu      $s1, $s1, 0x1
    /* 48F4 801070F4 0800222A */  slti       $v0, $s1, 0x8
    /* 48F8 801070F8 F3FF4014 */  bnez       $v0, .L801070C8
    /* 48FC 801070FC 10001026 */   addiu     $s0, $s0, 0x10
    /* 4900 80107100 2400BF8F */  lw         $ra, 0x24($sp)
    /* 4904 80107104 2000B48F */  lw         $s4, 0x20($sp)
    /* 4908 80107108 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 490C 8010710C 1800B28F */  lw         $s2, 0x18($sp)
    /* 4910 80107110 1400B18F */  lw         $s1, 0x14($sp)
    /* 4914 80107114 1000B08F */  lw         $s0, 0x10($sp)
    /* 4918 80107118 0800E003 */  jr         $ra
    /* 491C 8010711C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80107090
