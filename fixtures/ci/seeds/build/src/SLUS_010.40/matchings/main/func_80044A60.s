nonmatching func_80044A60, 0x84

glabel func_80044A60
    /* 35260 80044A60 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35264 80044A64 1400BFAF */  sw         $ra, 0x14($sp)
    /* 35268 80044A68 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3526C 80044A6C 09000424 */  addiu      $a0, $zero, 0x9
  .L80044A70:
    /* 35270 80044A70 21280000 */  addu       $a1, $zero, $zero
    /* 35274 80044A74 F996000C */  jal        DsControlB
    /* 35278 80044A78 2130A000 */   addu      $a2, $a1, $zero
    /* 3527C 80044A7C FCFF4010 */  beqz       $v0, .L80044A70
    /* 35280 80044A80 09000424 */   addiu     $a0, $zero, 0x9
    /* 35284 80044A84 E890000C */  jal        DsFlush
    /* 35288 80044A88 0580103C */   lui       $s0, %hi(_dsControlBuf)
    /* 3528C 80044A8C 0580043C */  lui        $a0, %hi(vs_main_disk)
    /* 35290 80044A90 105D8224 */  addiu      $v0, $a0, %lo(vs_main_disk)
    /* 35294 80044A94 80000324 */  addiu      $v1, $zero, 0x80
    /* 35298 80044A98 010043A0 */  sb         $v1, 0x1($v0)
    /* 3529C 80044A9C 1C0043A0 */  sb         $v1, 0x1C($v0)
    /* 352A0 80044AA0 020040A0 */  sb         $zero, 0x2($v0)
    /* 352A4 80044AA4 105D80A0 */  sb         $zero, %lo(vs_main_disk)($a0)
    /* 352A8 80044AA8 2C0040AC */  sw         $zero, 0x2C($v0)
    /* 352AC 80044AAC 0580023C */  lui        $v0, %hi(_cdReadBuffer)
    /* 352B0 80044AB0 100140AC */  sw         $zero, %lo(_cdReadBuffer)($v0)
    /* 352B4 80044AB4 0E000424 */  addiu      $a0, $zero, 0xE
  .L80044AB8:
    /* 352B8 80044AB8 2C5D0526 */  addiu      $a1, $s0, %lo(_dsControlBuf)
    /* 352BC 80044ABC F996000C */  jal        DsControlB
    /* 352C0 80044AC0 21300000 */   addu      $a2, $zero, $zero
    /* 352C4 80044AC4 FCFF4010 */  beqz       $v0, .L80044AB8
    /* 352C8 80044AC8 0E000424 */   addiu     $a0, $zero, 0xE
    /* 352CC 80044ACC B17D000C */  jal        VSync
    /* 352D0 80044AD0 03000424 */   addiu     $a0, $zero, 0x3
    /* 352D4 80044AD4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 352D8 80044AD8 1000B08F */  lw         $s0, 0x10($sp)
    /* 352DC 80044ADC 0800E003 */  jr         $ra
    /* 352E0 80044AE0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80044A60
