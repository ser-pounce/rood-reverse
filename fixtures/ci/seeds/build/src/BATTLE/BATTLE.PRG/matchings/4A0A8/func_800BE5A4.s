nonmatching func_800BE5A4, 0x84

glabel func_800BE5A4
    /* 55DA4 800BE5A4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 55DA8 800BE5A8 0F80023C */  lui        $v0, %hi(D_800F4BA4)
    /* 55DAC 800BE5AC 00240400 */  sll        $a0, $a0, 16
    /* 55DB0 800BE5B0 031C0400 */  sra        $v1, $a0, 16
    /* 55DB4 800BE5B4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 55DB8 800BE5B8 A44B508C */  lw         $s0, %lo(D_800F4BA4)($v0)
    /* 55DBC 800BE5BC 02000224 */  addiu      $v0, $zero, 0x2
    /* 55DC0 800BE5C0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 55DC4 800BE5C4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 55DC8 800BE5C8 0D006214 */  bne        $v1, $v0, .L800BE600
    /* 55DCC 800BE5CC B4001126 */   addiu     $s1, $s0, 0xB4
    /* 55DD0 800BE5D0 4FF9020C */  jal        func_800BE53C
    /* 55DD4 800BE5D4 21200002 */   addu      $a0, $s0, $zero
    /* 55DD8 800BE5D8 4FF9020C */  jal        func_800BE53C
    /* 55DDC 800BE5DC 21202002 */   addu      $a0, $s1, $zero
    /* 55DE0 800BE5E0 05000292 */  lbu        $v0, 0x5($s0)
    /* 55DE4 800BE5E4 05002392 */  lbu        $v1, 0x5($s1)
    /* 55DE8 800BE5E8 00000000 */  nop
    /* 55DEC 800BE5EC 21104300 */  addu       $v0, $v0, $v1
    /* 55DF0 800BE5F0 43100200 */  sra        $v0, $v0, 1
    /* 55DF4 800BE5F4 050022A2 */  sb         $v0, 0x5($s1)
    /* 55DF8 800BE5F8 85F90208 */  j          .L800BE614
    /* 55DFC 800BE5FC 050002A2 */   sb        $v0, 0x5($s0)
  .L800BE600:
    /* 55E00 800BE600 02006010 */  beqz       $v1, .L800BE60C
    /* 55E04 800BE604 21200002 */   addu      $a0, $s0, $zero
    /* 55E08 800BE608 21202002 */  addu       $a0, $s1, $zero
  .L800BE60C:
    /* 55E0C 800BE60C 4FF9020C */  jal        func_800BE53C
    /* 55E10 800BE610 00000000 */   nop
  .L800BE614:
    /* 55E14 800BE614 1800BF8F */  lw         $ra, 0x18($sp)
    /* 55E18 800BE618 1400B18F */  lw         $s1, 0x14($sp)
    /* 55E1C 800BE61C 1000B08F */  lw         $s0, 0x10($sp)
    /* 55E20 800BE620 0800E003 */  jr         $ra
    /* 55E24 800BE624 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800BE5A4
