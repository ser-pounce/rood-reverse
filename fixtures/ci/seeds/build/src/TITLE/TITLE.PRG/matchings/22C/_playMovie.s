nonmatching _playMovie, 0x8C

glabel _playMovie
    /* 6CC0 8006F4C0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6CC4 8006F4C4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6CC8 8006F4C8 21808000 */  addu       $s0, $a0, $zero
    /* 6CCC 8006F4CC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6CD0 8006F4D0 0E80113C */  lui        $s1, %hi(_dslMode)
    /* 6CD4 8006F4D4 80000224 */  addiu      $v0, $zero, 0x80
    /* 6CD8 8006F4D8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 6CDC 8006F4DC 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 6CE0 8006F4E0 1100A0A3 */  sb         $zero, 0x11($sp)
    /* 6CE4 8006F4E4 1200A0A3 */  sb         $zero, 0x12($sp)
    /* 6CE8 8006F4E8 1300A0A3 */  sb         $zero, 0x13($sp)
  .L8006F4EC:
    /* 6CEC 8006F4EC 02000424 */  addiu      $a0, $zero, 0x2
  .L8006F4F0:
    /* 6CF0 8006F4F0 21280002 */  addu       $a1, $s0, $zero
    /* 6CF4 8006F4F4 DF96000C */  jal        DsControl
    /* 6CF8 8006F4F8 21300000 */   addu      $a2, $zero, $zero
    /* 6CFC 8006F4FC FCFF4010 */  beqz       $v0, .L8006F4F0
    /* 6D00 8006F500 02000424 */   addiu     $a0, $zero, 0x2
    /* 6D04 8006F504 0E000424 */  addiu      $a0, $zero, 0xE
  .L8006F508:
    /* 6D08 8006F508 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6D0C 8006F50C DF96000C */  jal        DsControl
    /* 6D10 8006F510 21300000 */   addu      $a2, $zero, $zero
    /* 6D14 8006F514 FCFF4010 */  beqz       $v0, .L8006F508
    /* 6D18 8006F518 0E000424 */   addiu     $a0, $zero, 0xE
    /* 6D1C 8006F51C B17D000C */  jal        VSync
    /* 6D20 8006F520 03000424 */   addiu     $a0, $zero, 0x3
    /* 6D24 8006F524 80ED258E */  lw         $a1, %lo(_dslMode)($s1)
    /* 6D28 8006F528 5998000C */  jal        DsRead2
    /* 6D2C 8006F52C 21200002 */   addu      $a0, $s0, $zero
    /* 6D30 8006F530 EEFF4010 */  beqz       $v0, .L8006F4EC
    /* 6D34 8006F534 00000000 */   nop
    /* 6D38 8006F538 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6D3C 8006F53C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6D40 8006F540 1800B08F */  lw         $s0, 0x18($sp)
    /* 6D44 8006F544 0800E003 */  jr         $ra
    /* 6D48 8006F548 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _playMovie
