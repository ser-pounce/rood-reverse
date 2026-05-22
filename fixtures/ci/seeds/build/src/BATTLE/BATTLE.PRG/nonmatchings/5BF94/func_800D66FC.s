nonmatching func_800D66FC, 0xC8

glabel func_800D66FC
    /* 6DEFC 800D66FC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6DF00 800D6700 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6DF04 800D6704 21908000 */  addu       $s2, $a0, $zero
    /* 6DF08 800D6708 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6DF0C 800D670C 2198C000 */  addu       $s3, $a2, $zero
    /* 6DF10 800D6710 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6DF14 800D6714 0F80113C */  lui        $s1, %hi(D_800F5520)
    /* 6DF18 800D6718 20553126 */  addiu      $s1, $s1, %lo(D_800F5520)
    /* 6DF1C 800D671C 21202002 */  addu       $a0, $s1, $zero
    /* 6DF20 800D6720 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6DF24 800D6724 2000BFAF */  sw         $ra, 0x20($sp)
    /* 6DF28 800D6728 C646030C */  jal        func_800D1B18
    /* 6DF2C 800D672C 2180A000 */   addu      $s0, $a1, $zero
    /* 6DF30 800D6730 C646030C */  jal        func_800D1B18
    /* 6DF34 800D6734 40002426 */   addiu     $a0, $s1, 0x40
    /* 6DF38 800D6738 FF001032 */  andi       $s0, $s0, 0xFF
    /* 6DF3C 800D673C 40101000 */  sll        $v0, $s0, 1
    /* 6DF40 800D6740 21105000 */  addu       $v0, $v0, $s0
    /* 6DF44 800D6744 80100200 */  sll        $v0, $v0, 2
    /* 6DF48 800D6748 21105000 */  addu       $v0, $v0, $s0
    /* 6DF4C 800D674C 00110200 */  sll        $v0, $v0, 4
    /* 6DF50 800D6750 21904202 */  addu       $s2, $s2, $v0
    /* 6DF54 800D6754 6800428E */  lw         $v0, 0x68($s2)
    /* 6DF58 800D6758 00000000 */  nop
    /* 6DF5C 800D675C 00130200 */  sll        $v0, $v0, 12
    /* 6DF60 800D6760 500022AE */  sw         $v0, 0x50($s1)
    /* 6DF64 800D6764 6C00428E */  lw         $v0, 0x6C($s2)
    /* 6DF68 800D6768 00000000 */  nop
    /* 6DF6C 800D676C 00130200 */  sll        $v0, $v0, 12
    /* 6DF70 800D6770 540022AE */  sw         $v0, 0x54($s1)
    /* 6DF74 800D6774 7000428E */  lw         $v0, 0x70($s2)
    /* 6DF78 800D6778 0F80033C */  lui        $v1, %hi(D_800F54D0)
    /* 6DF7C 800D677C D05460A4 */  sh         $zero, %lo(D_800F54D0)($v1)
    /* 6DF80 800D6780 00130200 */  sll        $v0, $v0, 12
    /* 6DF84 800D6784 580022AE */  sw         $v0, 0x58($s1)
    /* 6DF88 800D6788 FF006232 */  andi       $v0, $s3, 0xFF
    /* 6DF8C 800D678C 02004014 */  bnez       $v0, .L800D6798
    /* 6DF90 800D6790 0F80033C */   lui       $v1, %hi(D_800F55A0)
    /* 6DF94 800D6794 01001324 */  addiu      $s3, $zero, 0x1
  .L800D6798:
    /* 6DF98 800D6798 FF006232 */  andi       $v0, $s3, 0xFF
    /* 6DF9C 800D679C 02000424 */  addiu      $a0, $zero, 0x2
    /* 6DFA0 800D67A0 8847030C */  jal        func_800D1E20
    /* 6DFA4 800D67A4 A05562A4 */   sh        $v0, %lo(D_800F55A0)($v1)
    /* 6DFA8 800D67A8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6DFAC 800D67AC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 6DFB0 800D67B0 1800B28F */  lw         $s2, 0x18($sp)
    /* 6DFB4 800D67B4 1400B18F */  lw         $s1, 0x14($sp)
    /* 6DFB8 800D67B8 1000B08F */  lw         $s0, 0x10($sp)
    /* 6DFBC 800D67BC 0800E003 */  jr         $ra
    /* 6DFC0 800D67C0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800D66FC
