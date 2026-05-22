nonmatching func_80105790, 0x8C

glabel func_80105790
    /* 2F90 80105790 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2F94 80105794 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 2F98 80105798 21888000 */  addu       $s1, $a0, $zero
    /* 2F9C 8010579C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 2FA0 801057A0 2190A000 */  addu       $s2, $a1, $zero
    /* 2FA4 801057A4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 2FA8 801057A8 2180C000 */  addu       $s0, $a2, $zero
    /* 2FAC 801057AC 02000106 */  bgez       $s0, .L801057B8
    /* 2FB0 801057B0 2400BFAF */   sw        $ra, 0x24($sp)
    /* 2FB4 801057B4 21800000 */  addu       $s0, $zero, $zero
  .L801057B8:
    /* 2FB8 801057B8 4100022A */  slti       $v0, $s0, 0x41
    /* 2FBC 801057BC 02004014 */  bnez       $v0, .L801057C8
    /* 2FC0 801057C0 00000000 */   nop
    /* 2FC4 801057C4 40001024 */  addiu      $s0, $zero, 0x40
  .L801057C8:
    /* 2FC8 801057C8 0E00001A */  blez       $s0, .L80105804
    /* 2FCC 801057CC 21284002 */   addu      $a1, $s2, $zero
    /* 2FD0 801057D0 21202002 */  addu       $a0, $s1, $zero
    /* 2FD4 801057D4 48000624 */  addiu      $a2, $zero, 0x48
    /* 2FD8 801057D8 0D17040C */  jal        func_80105C34
    /* 2FDC 801057DC 21380002 */   addu      $a3, $s0, $zero
    /* 2FE0 801057E0 02004526 */  addiu      $a1, $s2, 0x2
    /* 2FE4 801057E4 1180023C */  lui        $v0, %hi(D_801098A8)
    /* 2FE8 801057E8 A898478C */  lw         $a3, %lo(D_801098A8)($v0)
    /* 2FEC 801057EC 1180023C */  lui        $v0, %hi(D_8010941A)
    /* 2FF0 801057F0 1A944490 */  lbu        $a0, %lo(D_8010941A)($v0)
    /* 2FF4 801057F4 21300002 */  addu       $a2, $s0, $zero
    /* 2FF8 801057F8 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2FFC 801057FC DB17040C */  jal        func_80105F6C
    /* 3000 80105800 21202402 */   addu      $a0, $s1, $a0
  .L80105804:
    /* 3004 80105804 2400BF8F */  lw         $ra, 0x24($sp)
    /* 3008 80105808 2000B28F */  lw         $s2, 0x20($sp)
    /* 300C 8010580C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 3010 80105810 1800B08F */  lw         $s0, 0x18($sp)
    /* 3014 80105814 0800E003 */  jr         $ra
    /* 3018 80105818 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80105790
