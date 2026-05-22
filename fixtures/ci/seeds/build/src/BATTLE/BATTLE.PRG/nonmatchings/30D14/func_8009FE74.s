nonmatching func_8009FE74, 0x94

glabel func_8009FE74
    /* 37674 8009FE74 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 37678 8009FE78 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 3767C 8009FE7C 80200400 */  sll        $a0, $a0, 2
    /* 37680 8009FE80 21108200 */  addu       $v0, $a0, $v0
    /* 37684 8009FE84 0000428C */  lw         $v0, 0x0($v0)
    /* 37688 8009FE88 00000000 */  nop
    /* 3768C 8009FE8C 0A004014 */  bnez       $v0, .L8009FEB8
    /* 37690 8009FE90 00000000 */   nop
    /* 37694 8009FE94 0F80023C */  lui        $v0, %hi(D_800F45E0)
    /* 37698 8009FE98 E0454224 */  addiu      $v0, $v0, %lo(D_800F45E0)
    /* 3769C 8009FE9C 21108200 */  addu       $v0, $a0, $v0
    /* 376A0 8009FEA0 0000428C */  lw         $v0, 0x0($v0)
    /* 376A4 8009FEA4 00000000 */  nop
    /* 376A8 8009FEA8 04004014 */  bnez       $v0, .L8009FEBC
    /* 376AC 8009FEAC 64004424 */   addiu     $a0, $v0, 0x64
    /* 376B0 8009FEB0 C07F0208 */  j          .L8009FF00
    /* 376B4 8009FEB4 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8009FEB8:
    /* 376B8 8009FEB8 64004424 */  addiu      $a0, $v0, 0x64
  .L8009FEBC:
    /* 376BC 8009FEBC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 376C0 8009FEC0 0300A214 */  bne        $a1, $v0, .L8009FED0
    /* 376C4 8009FEC4 0800A22C */   sltiu     $v0, $a1, 0x8
    /* 376C8 8009FEC8 BF7F0208 */  j          .L8009FEFC
    /* 376CC 8009FECC 000080A0 */   sb        $zero, 0x0($a0)
  .L8009FED0:
    /* 376D0 8009FED0 03004014 */  bnez       $v0, .L8009FEE0
    /* 376D4 8009FED4 07000224 */   addiu     $v0, $zero, 0x7
    /* 376D8 8009FED8 C07F0208 */  j          .L8009FF00
    /* 376DC 8009FEDC FEFF0224 */   addiu     $v0, $zero, -0x2
  .L8009FEE0:
    /* 376E0 8009FEE0 23104500 */  subu       $v0, $v0, $a1
    /* 376E4 8009FEE4 01000324 */  addiu      $v1, $zero, 0x1
    /* 376E8 8009FEE8 04184300 */  sllv       $v1, $v1, $v0
    /* 376EC 8009FEEC 00008290 */  lbu        $v0, 0x0($a0)
    /* 376F0 8009FEF0 FF006338 */  xori       $v1, $v1, 0xFF
    /* 376F4 8009FEF4 24104300 */  and        $v0, $v0, $v1
    /* 376F8 8009FEF8 000082A0 */  sb         $v0, 0x0($a0)
  .L8009FEFC:
    /* 376FC 8009FEFC 21100000 */  addu       $v0, $zero, $zero
  .L8009FF00:
    /* 37700 8009FF00 0800E003 */  jr         $ra
    /* 37704 8009FF04 00000000 */   nop
endlabel func_8009FE74
