nonmatching func_8008D438, 0xD0

glabel func_8008D438
    /* 24C38 8008D438 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 24C3C 8008D43C F81B4224 */  addiu      $v0, $v0, %lo(vs_battle_roomData)
    /* 24C40 8008D440 8400478C */  lw         $a3, 0x84($v0)
    /* 24C44 8008D444 00000000 */  nop
    /* 24C48 8008D448 2C00E010 */  beqz       $a3, .L8008D4FC
    /* 24C4C 8008D44C 2140E000 */   addu      $t0, $a3, $zero
    /* 24C50 8008D450 2400438C */  lw         $v1, 0x24($v0)
    /* 24C54 8008D454 AAAA023C */  lui        $v0, (0xAAAAAAAB >> 16)
    /* 24C58 8008D458 ABAA4234 */  ori        $v0, $v0, (0xAAAAAAAB & 0xFFFF)
    /* 24C5C 8008D45C 19006200 */  multu      $v1, $v0
    /* 24C60 8008D460 10580000 */  mfhi       $t3
    /* 24C64 8008D464 C2480B00 */  srl        $t1, $t3, 3
    /* 24C68 8008D468 24002011 */  beqz       $t1, .L8008D4FC
    /* 24C6C 8008D46C 21380000 */   addu      $a3, $zero, $zero
    /* 24C70 8008D470 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 24C74 8008D474 98154A24 */  addiu      $t2, $v0, %lo(vs_main_stateFlags)
    /* 24C78 8008D478 06000325 */  addiu      $v1, $t0, 0x6
  .L8008D47C:
    /* 24C7C 8008D47C 00000285 */  lh         $v0, 0x0($t0)
    /* 24C80 8008D480 00000000 */  nop
    /* 24C84 8008D484 18004414 */  bne        $v0, $a0, .L8008D4E8
    /* 24C88 8008D488 00000000 */   nop
    /* 24C8C 8008D48C FCFF6284 */  lh         $v0, -0x4($v1)
    /* 24C90 8008D490 00000000 */  nop
    /* 24C94 8008D494 14004514 */  bne        $v0, $a1, .L8008D4E8
    /* 24C98 8008D498 00000000 */   nop
    /* 24C9C 8008D49C FEFF6284 */  lh         $v0, -0x2($v1)
    /* 24CA0 8008D4A0 00000000 */  nop
    /* 24CA4 8008D4A4 10004614 */  bne        $v0, $a2, .L8008D4E8
    /* 24CA8 8008D4A8 00000000 */   nop
    /* 24CAC 8008D4AC 20004291 */  lbu        $v0, 0x20($t2)
    /* 24CB0 8008D4B0 00000000 */  nop
    /* 24CB4 8008D4B4 05004014 */  bnez       $v0, .L8008D4CC
    /* 24CB8 8008D4B8 00000000 */   nop
    /* 24CBC 8008D4BC 40004291 */  lbu        $v0, 0x40($t2)
    /* 24CC0 8008D4C0 00000000 */  nop
    /* 24CC4 8008D4C4 06004010 */  beqz       $v0, .L8008D4E0
    /* 24CC8 8008D4C8 00000000 */   nop
  .L8008D4CC:
    /* 24CCC 8008D4CC 00006384 */  lh         $v1, 0x0($v1)
    /* 24CD0 8008D4D0 00000000 */  nop
    /* 24CD4 8008D4D4 10006328 */  slti       $v1, $v1, 0x10
    /* 24CD8 8008D4D8 09006014 */  bnez       $v1, .L8008D500
    /* 24CDC 8008D4DC 21100000 */   addu      $v0, $zero, $zero
  .L8008D4E0:
    /* 24CE0 8008D4E0 0800E003 */  jr         $ra
    /* 24CE4 8008D4E4 21100001 */   addu      $v0, $t0, $zero
  .L8008D4E8:
    /* 24CE8 8008D4E8 0100E724 */  addiu      $a3, $a3, 0x1
    /* 24CEC 8008D4EC 0C006324 */  addiu      $v1, $v1, 0xC
    /* 24CF0 8008D4F0 2A10E900 */  slt        $v0, $a3, $t1
    /* 24CF4 8008D4F4 E1FF4014 */  bnez       $v0, .L8008D47C
    /* 24CF8 8008D4F8 0C000825 */   addiu     $t0, $t0, 0xC
  .L8008D4FC:
    /* 24CFC 8008D4FC 21100000 */  addu       $v0, $zero, $zero
  .L8008D500:
    /* 24D00 8008D500 0800E003 */  jr         $ra
    /* 24D04 8008D504 00000000 */   nop
endlabel func_8008D438
