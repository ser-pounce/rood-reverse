nonmatching _printString, 0x12C

glabel _printString
    /* 2B64 8006B364 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2B68 8006B368 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2B6C 8006B36C 21808000 */  addu       $s0, $a0, $zero
    /* 2B70 8006B370 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2B74 8006B374 2188C000 */  addu       $s1, $a2, $zero
    /* 2B78 8006B378 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2B7C 8006B37C 2198E000 */  addu       $s3, $a3, $zero
    /* 2B80 8006B380 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2B84 8006B384 21A0A000 */  addu       $s4, $a1, $zero
    /* 2B88 8006B388 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2B8C 8006B38C 0780123C */  lui        $s2, %hi(_arrowCharState)
    /* 2B90 8006B390 2400BFAF */  sw         $ra, 0x24($sp)
  .L8006B394:
    /* 2B94 8006B394 00000492 */  lbu        $a0, 0x0($s0)
    /* 2B98 8006B398 00000000 */  nop
    /* 2B9C 8006B39C EC00822C */  sltiu      $v0, $a0, 0xEC
    /* 2BA0 8006B3A0 28004010 */  beqz       $v0, .L8006B444
    /* 2BA4 8006B3A4 01001026 */   addiu     $s0, $s0, 0x1
    /* 2BA8 8006B3A8 E500822C */  sltiu      $v0, $a0, 0xE5
    /* 2BAC 8006B3AC 03004010 */  beqz       $v0, .L8006B3BC
    /* 2BB0 8006B3B0 21302002 */   addu      $a2, $s1, $zero
    /* 2BB4 8006B3B4 06AD0108 */  j          .L8006B418
    /* 2BB8 8006B3B8 21386002 */   addu      $a3, $s3, $zero
  .L8006B3BC:
    /* 2BBC 8006B3BC E6000224 */  addiu      $v0, $zero, 0xE6
    /* 2BC0 8006B3C0 19008214 */  bne        $a0, $v0, .L8006B428
    /* 2BC4 8006B3C4 E7000224 */   addiu     $v0, $zero, 0xE7
    /* 2BC8 8006B3C8 AA2A023C */  lui        $v0, (0x2AAAAAAB >> 16)
    /* 2BCC 8006B3CC F82E4892 */  lbu        $t0, %lo(_arrowCharState)($s2)
    /* 2BD0 8006B3D0 ABAA4234 */  ori        $v0, $v0, (0x2AAAAAAB & 0xFFFF)
    /* 2BD4 8006B3D4 01000825 */  addiu      $t0, $t0, 0x1
    /* 2BD8 8006B3D8 18000201 */  mult       $t0, $v0
    /* 2BDC 8006B3DC 21302002 */  addu       $a2, $s1, $zero
    /* 2BE0 8006B3E0 21386002 */  addu       $a3, $s3, $zero
    /* 2BE4 8006B3E4 C3170800 */  sra        $v0, $t0, 31
    /* 2BE8 8006B3E8 10480000 */  mfhi       $t1
    /* 2BEC 8006B3EC 43180900 */  sra        $v1, $t1, 1
    /* 2BF0 8006B3F0 23186200 */  subu       $v1, $v1, $v0
    /* 2BF4 8006B3F4 40100300 */  sll        $v0, $v1, 1
    /* 2BF8 8006B3F8 21104300 */  addu       $v0, $v0, $v1
    /* 2BFC 8006B3FC 80100200 */  sll        $v0, $v0, 2
    /* 2C00 8006B400 23400201 */  subu       $t0, $t0, $v0
    /* 2C04 8006B404 FF000431 */  andi       $a0, $t0, 0xFF
    /* 2C08 8006B408 82200400 */  srl        $a0, $a0, 2
    /* 2C0C 8006B40C BC000224 */  addiu      $v0, $zero, 0xBC
    /* 2C10 8006B410 23204400 */  subu       $a0, $v0, $a0
    /* 2C14 8006B414 F82E48A2 */  sb         $t0, %lo(_arrowCharState)($s2)
  .L8006B418:
    /* 2C18 8006B418 FEAB010C */  jal        _printCharacter
    /* 2C1C 8006B41C 00000000 */   nop
    /* 2C20 8006B420 E5AC0108 */  j          .L8006B394
    /* 2C24 8006B424 21284000 */   addu      $a1, $v0, $zero
  .L8006B428:
    /* 2C28 8006B428 11008210 */  beq        $a0, $v0, .L8006B470
    /* 2C2C 8006B42C E8000224 */   addiu     $v0, $zero, 0xE8
    /* 2C30 8006B430 D8FF8214 */  bne        $a0, $v0, .L8006B394
    /* 2C34 8006B434 00000000 */   nop
    /* 2C38 8006B438 0D003126 */  addiu      $s1, $s1, 0xD
    /* 2C3C 8006B43C E5AC0108 */  j          .L8006B394
    /* 2C40 8006B440 21288002 */   addu      $a1, $s4, $zero
  .L8006B444:
    /* 2C44 8006B444 00000392 */  lbu        $v1, 0x0($s0)
    /* 2C48 8006B448 FA000224 */  addiu      $v0, $zero, 0xFA
    /* 2C4C 8006B44C D1FF8214 */  bne        $a0, $v0, .L8006B394
    /* 2C50 8006B450 01001026 */   addiu     $s0, $s0, 0x1
    /* 2C54 8006B454 F000622C */  sltiu      $v0, $v1, 0xF0
    /* 2C58 8006B458 03004014 */  bnez       $v0, .L8006B468
    /* 2C5C 8006B45C 00FFA224 */   addiu     $v0, $a1, -0x100
    /* 2C60 8006B460 E5AC0108 */  j          .L8006B394
    /* 2C64 8006B464 21284300 */   addu      $a1, $v0, $v1
  .L8006B468:
    /* 2C68 8006B468 E5AC0108 */  j          .L8006B394
    /* 2C6C 8006B46C 2128A300 */   addu      $a1, $a1, $v1
  .L8006B470:
    /* 2C70 8006B470 2400BF8F */  lw         $ra, 0x24($sp)
    /* 2C74 8006B474 2000B48F */  lw         $s4, 0x20($sp)
    /* 2C78 8006B478 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2C7C 8006B47C 1800B28F */  lw         $s2, 0x18($sp)
    /* 2C80 8006B480 1400B18F */  lw         $s1, 0x14($sp)
    /* 2C84 8006B484 1000B08F */  lw         $s0, 0x10($sp)
    /* 2C88 8006B488 0800E003 */  jr         $ra
    /* 2C8C 8006B48C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _printString
