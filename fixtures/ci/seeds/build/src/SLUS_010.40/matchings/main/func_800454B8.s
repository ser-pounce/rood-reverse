nonmatching func_800454B8, 0x54

glabel func_800454B8
    /* 35CB8 800454B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35CBC 800454BC 0E008010 */  beqz       $a0, .L800454F8
    /* 35CC0 800454C0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 35CC4 800454C4 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 35CC8 800454C8 38E04224 */  addiu      $v0, $v0, %lo(vs_main_soundData)
    /* 35CCC 800454CC FFFF8324 */  addiu      $v1, $a0, -0x1
    /* 35CD0 800454D0 80180300 */  sll        $v1, $v1, 2
    /* 35CD4 800454D4 21186200 */  addu       $v1, $v1, $v0
    /* 35CD8 800454D8 1400648C */  lw         $a0, 0x14($v1)
    /* 35CDC 800454DC FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 35CE0 800454E0 06008210 */  beq        $a0, $v0, .L800454FC
    /* 35CE4 800454E4 21100000 */   addu      $v0, $zero, $zero
    /* 35CE8 800454E8 AF47000C */  jal        func_80011EBC
    /* 35CEC 800454EC 00000000 */   nop
    /* 35CF0 800454F0 3F150108 */  j          .L800454FC
    /* 35CF4 800454F4 00000000 */   nop
  .L800454F8:
    /* 35CF8 800454F8 21100000 */  addu       $v0, $zero, $zero
  .L800454FC:
    /* 35CFC 800454FC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 35D00 80045500 00000000 */  nop
    /* 35D04 80045504 0800E003 */  jr         $ra
    /* 35D08 80045508 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800454B8
