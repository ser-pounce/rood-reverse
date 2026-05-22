nonmatching func_800CF70C, 0x9C

glabel func_800CF70C
    /* 66F0C 800CF70C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 66F10 800CF710 1400B1AF */  sw         $s1, 0x14($sp)
    /* 66F14 800CF714 21888000 */  addu       $s1, $a0, $zero
    /* 66F18 800CF718 1000B0AF */  sw         $s0, 0x10($sp)
    /* 66F1C 800CF71C 2180A000 */  addu       $s0, $a1, $zero
    /* 66F20 800CF720 1800BFAF */  sw         $ra, 0x18($sp)
    /* 66F24 800CF724 0800048E */  lw         $a0, 0x8($s0)
    /* 66F28 800CF728 00000000 */  nop
    /* 66F2C 800CF72C 03008010 */  beqz       $a0, .L800CF73C
    /* 66F30 800CF730 00000000 */   nop
    /* 66F34 800CF734 180F010C */  jal        vs_main_freeHeapR
    /* 66F38 800CF738 00000000 */   nop
  .L800CF73C:
    /* 66F3C 800CF73C 500D228E */  lw         $v0, 0xD50($s1)
    /* 66F40 800CF740 00000000 */  nop
    /* 66F44 800CF744 04005014 */  bne        $v0, $s0, .L800CF758
    /* 66F48 800CF748 21184000 */   addu      $v1, $v0, $zero
    /* 66F4C 800CF74C 0000028E */  lw         $v0, 0x0($s0)
    /* 66F50 800CF750 E33D0308 */  j          .L800CF78C
    /* 66F54 800CF754 500D22AE */   sw        $v0, 0xD50($s1)
  .L800CF758:
    /* 66F58 800CF758 0000628C */  lw         $v0, 0x0($v1)
    /* 66F5C 800CF75C 00000000 */  nop
    /* 66F60 800CF760 07005010 */  beq        $v0, $s0, .L800CF780
    /* 66F64 800CF764 00000000 */   nop
  .L800CF768:
    /* 66F68 800CF768 0000638C */  lw         $v1, 0x0($v1)
    /* 66F6C 800CF76C 00000000 */  nop
    /* 66F70 800CF770 0000628C */  lw         $v0, 0x0($v1)
    /* 66F74 800CF774 00000000 */  nop
    /* 66F78 800CF778 FBFF5014 */  bne        $v0, $s0, .L800CF768
    /* 66F7C 800CF77C 00000000 */   nop
  .L800CF780:
    /* 66F80 800CF780 0000028E */  lw         $v0, 0x0($s0)
    /* 66F84 800CF784 00000000 */  nop
    /* 66F88 800CF788 000062AC */  sw         $v0, 0x0($v1)
  .L800CF78C:
    /* 66F8C 800CF78C 180F010C */  jal        vs_main_freeHeapR
    /* 66F90 800CF790 21200002 */   addu      $a0, $s0, $zero
    /* 66F94 800CF794 1800BF8F */  lw         $ra, 0x18($sp)
    /* 66F98 800CF798 1400B18F */  lw         $s1, 0x14($sp)
    /* 66F9C 800CF79C 1000B08F */  lw         $s0, 0x10($sp)
    /* 66FA0 800CF7A0 0800E003 */  jr         $ra
    /* 66FA4 800CF7A4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CF70C
