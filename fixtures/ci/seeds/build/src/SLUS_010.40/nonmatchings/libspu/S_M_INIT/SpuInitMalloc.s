nonmatching SpuInitMalloc, 0x54

glabel SpuInitMalloc
    /* EE84 8001E684 21108000 */  addu       $v0, $a0, $zero
    /* EE88 8001E688 0300401C */  bgtz       $v0, .L8001E698
    /* EE8C 8001E68C 0040033C */   lui       $v1, (0x40001010 >> 16)
    /* EE90 8001E690 B4790008 */  j          .L8001E6D0
    /* EE94 8001E694 21100000 */   addu      $v0, $zero, $zero
  .L8001E698:
    /* EE98 8001E698 0380043C */  lui        $a0, %hi(D_80030888)
    /* EE9C 8001E69C 8808848C */  lw         $a0, %lo(D_80030888)($a0)
    /* EEA0 8001E6A0 10106334 */  ori        $v1, $v1, (0x40001010 & 0xFFFF)
    /* EEA4 8001E6A4 0000A3AC */  sw         $v1, 0x0($a1)
    /* EEA8 8001E6A8 0100033C */  lui        $v1, (0x10000 >> 16)
    /* EEAC 8001E6AC 0380013C */  lui        $at, %hi(D_800308C8)
    /* EEB0 8001E6B0 C80825AC */  sw         $a1, %lo(D_800308C8)($at)
    /* EEB4 8001E6B4 0380013C */  lui        $at, %hi(D_800308C4)
    /* EEB8 8001E6B8 C40820AC */  sw         $zero, %lo(D_800308C4)($at)
    /* EEBC 8001E6BC 0380013C */  lui        $at, %hi(D_800308C0)
    /* EEC0 8001E6C0 C00822AC */  sw         $v0, %lo(D_800308C0)($at)
    /* EEC4 8001E6C4 04188300 */  sllv       $v1, $v1, $a0
    /* EEC8 8001E6C8 F0EF6324 */  addiu      $v1, $v1, -0x1010
    /* EECC 8001E6CC 0400A3AC */  sw         $v1, 0x4($a1)
  .L8001E6D0:
    /* EED0 8001E6D0 0800E003 */  jr         $ra
    /* EED4 8001E6D4 00000000 */   nop
endlabel SpuInitMalloc
    /* EED8 8001E6D8 00000000 */  nop
    /* EEDC 8001E6DC 00000000 */  nop
    /* EEE0 8001E6E0 00000000 */  nop
