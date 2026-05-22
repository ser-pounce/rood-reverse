nonmatching func_800235A4, 0x70

glabel func_800235A4
    /* 13DA4 800235A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13DA8 800235A8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 13DAC 800235AC 3E92000C */  jal        DS_system_status
    /* 13DB0 800235B0 21200000 */   addu      $a0, $zero, $zero
    /* 13DB4 800235B4 01000324 */  addiu      $v1, $zero, 0x1
    /* 13DB8 800235B8 12004314 */  bne        $v0, $v1, .L80023604
    /* 13DBC 800235BC 21100000 */   addu      $v0, $zero, $zero
    /* 13DC0 800235C0 0480033C */  lui        $v1, %hi(D_80039DB4)
    /* 13DC4 800235C4 B49D6324 */  addiu      $v1, $v1, %lo(D_80039DB4)
    /* 13DC8 800235C8 0000648C */  lw         $a0, 0x0($v1)
    /* 13DCC 800235CC 3CFF6324 */  addiu      $v1, $v1, -0xC4
    /* 13DD0 800235D0 40100400 */  sll        $v0, $a0, 1
    /* 13DD4 800235D4 21104400 */  addu       $v0, $v0, $a0
    /* 13DD8 800235D8 C0100200 */  sll        $v0, $v0, 3
    /* 13DDC 800235DC 21184300 */  addu       $v1, $v0, $v1
    /* 13DE0 800235E0 0000628C */  lw         $v0, 0x0($v1)
    /* 13DE4 800235E4 00000000 */  nop
    /* 13DE8 800235E8 06004010 */  beqz       $v0, .L80023604
    /* 13DEC 800235EC 21100000 */   addu      $v0, $zero, $zero
    /* 13DF0 800235F0 04006490 */  lbu        $a0, 0x4($v1)
    /* 13DF4 800235F4 0C00658C */  lw         $a1, 0xC($v1)
    /* 13DF8 800235F8 1392000C */  jal        DS_cw
    /* 13DFC 800235FC 00000000 */   nop
    /* 13E00 80023600 2B100200 */  sltu       $v0, $zero, $v0
  .L80023604:
    /* 13E04 80023604 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13E08 80023608 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 13E0C 8002360C 0800E003 */  jr         $ra
    /* 13E10 80023610 00000000 */   nop
endlabel func_800235A4
