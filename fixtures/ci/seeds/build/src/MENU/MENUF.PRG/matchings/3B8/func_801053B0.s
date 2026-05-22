nonmatching func_801053B0, 0x5C

glabel func_801053B0
    /* 2BB0 801053B0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2BB4 801053B4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2BB8 801053B8 0200C104 */  bgez       $a2, .L801053C4
    /* 2BBC 801053BC 21188000 */   addu      $v1, $a0, $zero
    /* 2BC0 801053C0 21300000 */  addu       $a2, $zero, $zero
  .L801053C4:
    /* 2BC4 801053C4 4100C228 */  slti       $v0, $a2, 0x41
    /* 2BC8 801053C8 02004014 */  bnez       $v0, .L801053D4
    /* 2BCC 801053CC 00000000 */   nop
    /* 2BD0 801053D0 40000624 */  addiu      $a2, $zero, 0x40
  .L801053D4:
    /* 2BD4 801053D4 0900C018 */  blez       $a2, .L801053FC
    /* 2BD8 801053D8 1180073C */   lui       $a3, %hi(D_80109764)
    /* 2BDC 801053DC 1180023C */  lui        $v0, %hi(D_8010923A)
    /* 2BE0 801053E0 3A924490 */  lbu        $a0, %lo(D_8010923A)($v0)
    /* 2BE4 801053E4 6497E724 */  addiu      $a3, $a3, %lo(D_80109764)
    /* 2BE8 801053E8 0300E6A0 */  sb         $a2, 0x3($a3)
    /* 2BEC 801053EC 0C000624 */  addiu      $a2, $zero, 0xC
    /* 2BF0 801053F0 42200400 */  srl        $a0, $a0, 1
    /* 2BF4 801053F4 9319040C */  jal        func_8010664C
    /* 2BF8 801053F8 23206400 */   subu      $a0, $v1, $a0
  .L801053FC:
    /* 2BFC 801053FC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2C00 80105400 00000000 */  nop
    /* 2C04 80105404 0800E003 */  jr         $ra
    /* 2C08 80105408 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_801053B0
