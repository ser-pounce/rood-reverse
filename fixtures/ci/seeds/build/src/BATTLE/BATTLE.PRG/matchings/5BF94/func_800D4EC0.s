nonmatching func_800D4EC0, 0x40

glabel func_800D4EC0
    /* 6C6C0 800D4EC0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C6C4 800D4EC4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C6C8 800D4EC8 21808000 */  addu       $s0, $a0, $zero
    /* 6C6CC 800D4ECC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6C6D0 800D4ED0 4C0D048E */  lw         $a0, 0xD4C($s0)
    /* 6C6D4 800D4ED4 00000000 */  nop
    /* 6C6D8 800D4ED8 04008010 */  beqz       $a0, .L800D4EEC
    /* 6C6DC 800D4EDC 00000000 */   nop
    /* 6C6E0 800D4EE0 180F010C */  jal        vs_main_freeHeapR
    /* 6C6E4 800D4EE4 00000000 */   nop
    /* 6C6E8 800D4EE8 4C0D00AE */  sw         $zero, 0xD4C($s0)
  .L800D4EEC:
    /* 6C6EC 800D4EEC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6C6F0 800D4EF0 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C6F4 800D4EF4 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C6F8 800D4EF8 0800E003 */  jr         $ra
    /* 6C6FC 800D4EFC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D4EC0
