nonmatching func_80083CB8, 0x50

glabel func_80083CB8
    /* 1B4B8 80083CB8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B4BC 80083CBC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B4C0 80083CC0 2180C000 */  addu       $s0, $a2, $zero
    /* 1B4C4 80083CC4 0C000424 */  addiu      $a0, $zero, 0xC
    /* 1B4C8 80083CC8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B4CC 80083CCC 0804020C */  jal        func_80081020
    /* 1B4D0 80083CD0 21280002 */   addu      $a1, $s0, $zero
    /* 1B4D4 80083CD4 08004010 */  beqz       $v0, .L80083CF8
    /* 1B4D8 80083CD8 00000000 */   nop
    /* 1B4DC 80083CDC FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B4E0 80083CE0 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B4E4 80083CE4 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B4E8 80083CE8 24186200 */  and        $v1, $v1, $v0
    /* 1B4EC 80083CEC 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 1B4F0 80083CF0 25186200 */  or         $v1, $v1, $v0
    /* 1B4F4 80083CF4 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083CF8:
    /* 1B4F8 80083CF8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B4FC 80083CFC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B500 80083D00 0800E003 */  jr         $ra
    /* 1B504 80083D04 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083CB8
