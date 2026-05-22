nonmatching func_800455AC, 0x38

glabel func_800455AC
    /* 35DAC 800455AC 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 35DB0 800455B0 38E0428C */  lw         $v0, %lo(vs_main_soundData)($v0)
    /* 35DB4 800455B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35DB8 800455B8 03004410 */  beq        $v0, $a0, .L800455C8
    /* 35DBC 800455BC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 35DC0 800455C0 75150108 */  j          .L800455D4
    /* 35DC4 800455C4 21100000 */   addu      $v0, $zero, $zero
  .L800455C8:
    /* 35DC8 800455C8 9B4A000C */  jal        func_80012A6C
    /* 35DCC 800455CC 2120C000 */   addu      $a0, $a2, $zero
    /* 35DD0 800455D0 01000224 */  addiu      $v0, $zero, 0x1
  .L800455D4:
    /* 35DD4 800455D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 35DD8 800455D8 00000000 */  nop
    /* 35DDC 800455DC 0800E003 */  jr         $ra
    /* 35DE0 800455E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800455AC
