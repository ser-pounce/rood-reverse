nonmatching func_8004659C, 0x6C

glabel func_8004659C
    /* 36D9C 8004659C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 36DA0 800465A0 FFFF8324 */  addiu      $v1, $a0, -0x1
    /* 36DA4 800465A4 0300622C */  sltiu      $v0, $v1, 0x3
    /* 36DA8 800465A8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 36DAC 800465AC 11004010 */  beqz       $v0, .L800465F4
    /* 36DB0 800465B0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 36DB4 800465B4 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 36DB8 800465B8 38E04224 */  addiu      $v0, $v0, %lo(vs_main_soundData)
    /* 36DBC 800465BC 80180300 */  sll        $v1, $v1, 2
    /* 36DC0 800465C0 21806200 */  addu       $s0, $v1, $v0
    /* 36DC4 800465C4 6400028E */  lw         $v0, 0x64($s0)
    /* 36DC8 800465C8 00000000 */  nop
    /* 36DCC 800465CC 0A004010 */  beqz       $v0, .L800465F8
    /* 36DD0 800465D0 21100000 */   addu      $v0, $zero, $zero
    /* 36DD4 800465D4 CA4C000C */  jal        func_80013328
    /* 36DD8 800465D8 00000000 */   nop
    /* 36DDC 800465DC 6400048E */  lw         $a0, 0x64($s0)
    /* 36DE0 800465E0 180F010C */  jal        vs_main_freeHeapR
    /* 36DE4 800465E4 00000000 */   nop
    /* 36DE8 800465E8 01000224 */  addiu      $v0, $zero, 0x1
    /* 36DEC 800465EC 7E190108 */  j          .L800465F8
    /* 36DF0 800465F0 640000AE */   sw        $zero, 0x64($s0)
  .L800465F4:
    /* 36DF4 800465F4 21100000 */  addu       $v0, $zero, $zero
  .L800465F8:
    /* 36DF8 800465F8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 36DFC 800465FC 1000B08F */  lw         $s0, 0x10($sp)
    /* 36E00 80046600 0800E003 */  jr         $ra
    /* 36E04 80046604 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004659C
