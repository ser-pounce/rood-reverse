nonmatching vs_main_gametimeUpdate, 0x100

glabel vs_main_gametimeUpdate
    /* 32E1C 8004261C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 32E20 80042620 1000B0AF */  sw         $s0, 0x10($sp)
    /* 32E24 80042624 21808000 */  addu       $s0, $a0, $zero
    /* 32E28 80042628 1800BFAF */  sw         $ra, 0x18($sp)
    /* 32E2C 8004262C B17D000C */  jal        VSync
    /* 32E30 80042630 1400B1AF */   sw        $s1, 0x14($sp)
    /* 32E34 80042634 21884000 */  addu       $s1, $v0, $zero
    /* 32E38 80042638 01000224 */  addiu      $v0, $zero, 0x1
    /* 32E3C 8004263C 03000212 */  beq        $s0, $v0, .L8004264C
    /* 32E40 80042640 00000000 */   nop
    /* 32E44 80042644 2324010C */  jal        _asmNop
    /* 32E48 80042648 00000000 */   nop
  .L8004264C:
    /* 32E4C 8004264C 1D13010C */  jal        _processCdQueue
    /* 32E50 80042650 00000000 */   nop
    /* 32E54 80042654 0680053C */  lui        $a1, %hi(vs_main_gametime)
    /* 32E58 80042658 7410A424 */  addiu      $a0, $a1, %lo(vs_main_gametime)
    /* 32E5C 8004265C 03008280 */  lb         $v0, 0x3($a0)
    /* 32E60 80042660 03008690 */  lbu        $a2, 0x3($a0)
    /* 32E64 80042664 64004228 */  slti       $v0, $v0, 0x64
    /* 32E68 80042668 26004010 */  beqz       $v0, .L80042704
    /* 32E6C 8004266C 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 32E70 80042670 7410A390 */  lbu        $v1, %lo(vs_main_gametime)($a1)
    /* 32E74 80042674 4CE24290 */  lbu        $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 32E78 80042678 00000000 */  nop
    /* 32E7C 8004267C 21186200 */  addu       $v1, $v1, $v0
    /* 32E80 80042680 7410A3A0 */  sb         $v1, %lo(vs_main_gametime)($a1)
    /* 32E84 80042684 001E0300 */  sll        $v1, $v1, 24
    /* 32E88 80042688 031E0300 */  sra        $v1, $v1, 24
    /* 32E8C 8004268C 3C006328 */  slti       $v1, $v1, 0x3C
    /* 32E90 80042690 1D006014 */  bnez       $v1, .L80042708
    /* 32E94 80042694 21102002 */   addu      $v0, $s1, $zero
    /* 32E98 80042698 01008290 */  lbu        $v0, 0x1($a0)
    /* 32E9C 8004269C 7410A0A0 */  sb         $zero, %lo(vs_main_gametime)($a1)
    /* 32EA0 800426A0 01004224 */  addiu      $v0, $v0, 0x1
    /* 32EA4 800426A4 010082A0 */  sb         $v0, 0x1($a0)
    /* 32EA8 800426A8 00160200 */  sll        $v0, $v0, 24
    /* 32EAC 800426AC 03160200 */  sra        $v0, $v0, 24
    /* 32EB0 800426B0 3C004228 */  slti       $v0, $v0, 0x3C
    /* 32EB4 800426B4 14004014 */  bnez       $v0, .L80042708
    /* 32EB8 800426B8 21102002 */   addu      $v0, $s1, $zero
    /* 32EBC 800426BC 02008290 */  lbu        $v0, 0x2($a0)
    /* 32EC0 800426C0 010080A0 */  sb         $zero, 0x1($a0)
    /* 32EC4 800426C4 01004224 */  addiu      $v0, $v0, 0x1
    /* 32EC8 800426C8 020082A0 */  sb         $v0, 0x2($a0)
    /* 32ECC 800426CC 00160200 */  sll        $v0, $v0, 24
    /* 32ED0 800426D0 03160200 */  sra        $v0, $v0, 24
    /* 32ED4 800426D4 3C004228 */  slti       $v0, $v0, 0x3C
    /* 32ED8 800426D8 0B004014 */  bnez       $v0, .L80042708
    /* 32EDC 800426DC 21102002 */   addu      $v0, $s1, $zero
    /* 32EE0 800426E0 0100C224 */  addiu      $v0, $a2, 0x1
    /* 32EE4 800426E4 030082A0 */  sb         $v0, 0x3($a0)
    /* 32EE8 800426E8 00160200 */  sll        $v0, $v0, 24
    /* 32EEC 800426EC 03160200 */  sra        $v0, $v0, 24
    /* 32EF0 800426F0 64004228 */  slti       $v0, $v0, 0x64
    /* 32EF4 800426F4 03004014 */  bnez       $v0, .L80042704
    /* 32EF8 800426F8 020080A0 */   sb        $zero, 0x2($a0)
    /* 32EFC 800426FC 64000224 */  addiu      $v0, $zero, 0x64
    /* 32F00 80042700 030082A0 */  sb         $v0, 0x3($a0)
  .L80042704:
    /* 32F04 80042704 21102002 */  addu       $v0, $s1, $zero
  .L80042708:
    /* 32F08 80042708 1800BF8F */  lw         $ra, 0x18($sp)
    /* 32F0C 8004270C 1400B18F */  lw         $s1, 0x14($sp)
    /* 32F10 80042710 1000B08F */  lw         $s0, 0x10($sp)
    /* 32F14 80042714 0800E003 */  jr         $ra
    /* 32F18 80042718 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_main_gametimeUpdate
