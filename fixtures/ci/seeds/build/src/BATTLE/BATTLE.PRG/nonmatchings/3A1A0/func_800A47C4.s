nonmatching func_800A47C4, 0x64

glabel func_800A47C4
    /* 3BFC4 800A47C4 21300000 */  addu       $a2, $zero, $zero
    /* 3BFC8 800A47C8 0F80023C */  lui        $v0, %hi(D_800F45E0)
    /* 3BFCC 800A47CC E0454524 */  addiu      $a1, $v0, %lo(D_800F45E0)
  .L800A47D0:
    /* 3BFD0 800A47D0 0000A38C */  lw         $v1, 0x0($a1)
    /* 3BFD4 800A47D4 00000000 */  nop
    /* 3BFD8 800A47D8 0C006010 */  beqz       $v1, .L800A480C
    /* 3BFDC 800A47DC 00000000 */   nop
    /* 3BFE0 800A47E0 0800648C */  lw         $a0, 0x8($v1)
    /* 3BFE4 800A47E4 00000000 */  nop
    /* 3BFE8 800A47E8 01008230 */  andi       $v0, $a0, 0x1
    /* 3BFEC 800A47EC 07004014 */  bnez       $v0, .L800A480C
    /* 3BFF0 800A47F0 000F8230 */   andi      $v0, $a0, 0xF00
    /* 3BFF4 800A47F4 05004014 */  bnez       $v0, .L800A480C
    /* 3BFF8 800A47F8 00000000 */   nop
    /* 3BFFC 800A47FC 1A006284 */  lh         $v0, 0x1A($v1)
    /* 3C000 800A4800 00000000 */  nop
    /* 3C004 800A4804 06004014 */  bnez       $v0, .L800A4820
    /* 3C008 800A4808 01000224 */   addiu     $v0, $zero, 0x1
  .L800A480C:
    /* 3C00C 800A480C 0100C624 */  addiu      $a2, $a2, 0x1
    /* 3C010 800A4810 1000C228 */  slti       $v0, $a2, 0x10
    /* 3C014 800A4814 EEFF4014 */  bnez       $v0, .L800A47D0
    /* 3C018 800A4818 0400A524 */   addiu     $a1, $a1, 0x4
    /* 3C01C 800A481C 21100000 */  addu       $v0, $zero, $zero
  .L800A4820:
    /* 3C020 800A4820 0800E003 */  jr         $ra
    /* 3C024 800A4824 00000000 */   nop
endlabel func_800A47C4
