nonmatching func_80093F24, 0xC8

glabel func_80093F24
    /* 2B724 80093F24 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2B728 80093F28 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2B72C 80093F2C 21808000 */  addu       $s0, $a0, $zero
    /* 2B730 80093F30 0F80033C */  lui        $v1, %hi(D_800F1BAC)
    /* 2B734 80093F34 0F80023C */  lui        $v0, %hi(D_800F227E)
    /* 2B738 80093F38 7E224284 */  lh         $v0, %lo(D_800F227E)($v0)
    /* 2B73C 80093F3C AC1B638C */  lw         $v1, %lo(D_800F1BAC)($v1)
    /* 2B740 80093F40 21200000 */  addu       $a0, $zero, $zero
    /* 2B744 80093F44 0B004018 */  blez       $v0, .L80093F74
    /* 2B748 80093F48 1400BFAF */   sw        $ra, 0x14($sp)
    /* 2B74C 80093F4C 05000624 */  addiu      $a2, $zero, 0x5
    /* 2B750 80093F50 21284000 */  addu       $a1, $v0, $zero
  .L80093F54:
    /* 2B754 80093F54 08006294 */  lhu        $v0, 0x8($v1)
    /* 2B758 80093F58 00000000 */  nop
    /* 2B75C 80093F5C 09004610 */  beq        $v0, $a2, .L80093F84
    /* 2B760 80093F60 00000000 */   nop
    /* 2B764 80093F64 01008424 */  addiu      $a0, $a0, 0x1
    /* 2B768 80093F68 2A108500 */  slt        $v0, $a0, $a1
    /* 2B76C 80093F6C F9FF4014 */  bnez       $v0, .L80093F54
    /* 2B770 80093F70 18006324 */   addiu     $v1, $v1, 0x18
  .L80093F74:
    /* 2B774 80093F74 07000016 */  bnez       $s0, .L80093F94
    /* 2B778 80093F78 21100000 */   addu      $v0, $zero, $zero
    /* 2B77C 80093F7C F74F0208 */  j          .L80093FDC
    /* 2B780 80093F80 00000000 */   nop
  .L80093F84:
    /* 2B784 80093F84 1159020C */  jal        func_80096444
    /* 2B788 80093F88 00000000 */   nop
    /* 2B78C 80093F8C DD4F0208 */  j          .L80093F74
    /* 2B790 80093F90 00000000 */   nop
  .L80093F94:
    /* 2B794 80093F94 B958020C */  jal        func_800962E4
    /* 2B798 80093F98 00000000 */   nop
    /* 2B79C 80093F9C 21184000 */  addu       $v1, $v0, $zero
    /* 2B7A0 80093FA0 05000224 */  addiu      $v0, $zero, 0x5
    /* 2B7A4 80093FA4 080062A0 */  sb         $v0, 0x8($v1)
    /* 2B7A8 80093FA8 FFFF0232 */  andi       $v0, $s0, 0xFFFF
    /* 2B7AC 80093FAC E803422C */  sltiu      $v0, $v0, 0x3E8
    /* 2B7B0 80093FB0 0B0060A0 */  sb         $zero, 0xB($v1)
    /* 2B7B4 80093FB4 090060A0 */  sb         $zero, 0x9($v1)
    /* 2B7B8 80093FB8 03004014 */  bnez       $v0, .L80093FC8
    /* 2B7BC 80093FBC 0C0070A4 */   sh        $s0, 0xC($v1)
    /* 2B7C0 80093FC0 E7030224 */  addiu      $v0, $zero, 0x3E7
    /* 2B7C4 80093FC4 0C0062A4 */  sh         $v0, 0xC($v1)
  .L80093FC8:
    /* 2B7C8 80093FC8 0F80043C */  lui        $a0, %hi(D_800F227E)
    /* 2B7CC 80093FCC 7E228394 */  lhu        $v1, %lo(D_800F227E)($a0)
    /* 2B7D0 80093FD0 21100000 */  addu       $v0, $zero, $zero
    /* 2B7D4 80093FD4 01006324 */  addiu      $v1, $v1, 0x1
    /* 2B7D8 80093FD8 7E2283A4 */  sh         $v1, %lo(D_800F227E)($a0)
  .L80093FDC:
    /* 2B7DC 80093FDC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2B7E0 80093FE0 1000B08F */  lw         $s0, 0x10($sp)
    /* 2B7E4 80093FE4 0800E003 */  jr         $ra
    /* 2B7E8 80093FE8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80093F24
