nonmatching func_8002EC88, 0x68

glabel func_8002EC88
    /* 1F488 8002EC88 0380023C */  lui        $v0, %hi(D_80033668)
    /* 1F48C 8002EC8C 6836428C */  lw         $v0, %lo(D_80033668)($v0)
    /* 1F490 8002EC90 F0FFBD27 */  addiu      $sp, $sp, -0x10
    /* 1F494 8002EC94 0A0040A4 */  sh         $zero, 0xA($v0)
    /* 1F498 8002EC98 0A000224 */  addiu      $v0, $zero, 0xA
    /* 1F49C 8002EC9C 0000A2AF */  sw         $v0, 0x0($sp)
    /* 1F4A0 8002ECA0 0000A28F */  lw         $v0, 0x0($sp)
    /* 1F4A4 8002ECA4 00000000 */  nop
    /* 1F4A8 8002ECA8 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1F4AC 8002ECAC 0000A2AF */  sw         $v0, 0x0($sp)
    /* 1F4B0 8002ECB0 0000A38F */  lw         $v1, 0x0($sp)
    /* 1F4B4 8002ECB4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1F4B8 8002ECB8 0A006210 */  beq        $v1, $v0, .L8002ECE4
    /* 1F4BC 8002ECBC 21100000 */   addu      $v0, $zero, $zero
    /* 1F4C0 8002ECC0 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L8002ECC4:
    /* 1F4C4 8002ECC4 0000A28F */  lw         $v0, 0x0($sp)
    /* 1F4C8 8002ECC8 00000000 */  nop
    /* 1F4CC 8002ECCC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1F4D0 8002ECD0 0000A2AF */  sw         $v0, 0x0($sp)
    /* 1F4D4 8002ECD4 0000A28F */  lw         $v0, 0x0($sp)
    /* 1F4D8 8002ECD8 00000000 */  nop
    /* 1F4DC 8002ECDC F9FF4314 */  bne        $v0, $v1, .L8002ECC4
    /* 1F4E0 8002ECE0 21100000 */   addu      $v0, $zero, $zero
  .L8002ECE4:
    /* 1F4E4 8002ECE4 1000BD27 */  addiu      $sp, $sp, 0x10
    /* 1F4E8 8002ECE8 0800E003 */  jr         $ra
    /* 1F4EC 8002ECEC 00000000 */   nop
endlabel func_8002EC88
