nonmatching func_800D0C60, 0xA8

glabel func_800D0C60
    /* 68460 800D0C60 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 68464 800D0C64 2800B0AF */  sw         $s0, 0x28($sp)
    /* 68468 800D0C68 2180A000 */  addu       $s0, $a1, $zero
    /* 6846C 800D0C6C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 68470 800D0C70 34000292 */  lbu        $v0, 0x34($s0)
    /* 68474 800D0C74 00000000 */  nop
    /* 68478 800D0C78 1000422C */  sltiu      $v0, $v0, 0x10
    /* 6847C 800D0C7C 0B004010 */  beqz       $v0, .L800D0CAC
    /* 68480 800D0C80 78000626 */   addiu     $a2, $s0, 0x78
    /* 68484 800D0C84 34000492 */  lbu        $a0, 0x34($s0)
    /* 68488 800D0C88 35000592 */  lbu        $a1, 0x35($s0)
    /* 6848C 800D0C8C C885020C */  jal        func_800A1720
    /* 68490 800D0C90 2000A727 */   addiu     $a3, $sp, 0x20
    /* 68494 800D0C94 34000492 */  lbu        $a0, 0x34($s0)
    /* 68498 800D0C98 4284020C */  jal        func_800A1108
    /* 6849C 800D0C9C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 684A0 800D0CA0 1A00A297 */  lhu        $v0, 0x1A($sp)
    /* 684A4 800D0CA4 3E430308 */  j          .L800D0CF8
    /* 684A8 800D0CA8 BE0002A6 */   sh        $v0, 0xBE($s0)
  .L800D0CAC:
    /* 684AC 800D0CAC 34000692 */  lbu        $a2, 0x34($s0)
    /* 684B0 800D0CB0 00000000 */  nop
    /* 684B4 800D0CB4 1000C228 */  slti       $v0, $a2, 0x10
    /* 684B8 800D0CB8 0F004014 */  bnez       $v0, .L800D0CF8
    /* 684BC 800D0CBC 1200C228 */   slti      $v0, $a2, 0x12
    /* 684C0 800D0CC0 06004014 */  bnez       $v0, .L800D0CDC
    /* 684C4 800D0CC4 21280002 */   addu      $a1, $s0, $zero
    /* 684C8 800D0CC8 12000224 */  addiu      $v0, $zero, 0x12
    /* 684CC 800D0CCC 0800C210 */  beq        $a2, $v0, .L800D0CF0
    /* 684D0 800D0CD0 00000000 */   nop
    /* 684D4 800D0CD4 3E430308 */  j          .L800D0CF8
    /* 684D8 800D0CD8 00000000 */   nop
  .L800D0CDC:
    /* 684DC 800D0CDC 1000C638 */  xori       $a2, $a2, 0x10
    /* 684E0 800D0CE0 6142030C */  jal        func_800D0984
    /* 684E4 800D0CE4 2B300600 */   sltu      $a2, $zero, $a2
    /* 684E8 800D0CE8 3E430308 */  j          .L800D0CF8
    /* 684EC 800D0CEC 00000000 */   nop
  .L800D0CF0:
    /* 684F0 800D0CF0 C242030C */  jal        func_800D0B08
    /* 684F4 800D0CF4 78000426 */   addiu     $a0, $s0, 0x78
  .L800D0CF8:
    /* 684F8 800D0CF8 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 684FC 800D0CFC 2800B08F */  lw         $s0, 0x28($sp)
    /* 68500 800D0D00 0800E003 */  jr         $ra
    /* 68504 800D0D04 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800D0C60
