nonmatching func_800935B8, 0x40

glabel func_800935B8
    /* 2ADB8 800935B8 2118A000 */  addu       $v1, $a1, $zero
    /* 2ADBC 800935BC 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0xB0)
    /* 2ADC0 800935C0 A81C458C */  lw         $a1, %lo(vs_battle_roomData + 0xB0)($v0)
    /* 2ADC4 800935C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2ADC8 800935C8 0700A010 */  beqz       $a1, .L800935E8
    /* 2ADCC 800935CC 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2ADD0 800935D0 06006694 */  lhu        $a2, 0x6($v1)
    /* 2ADD4 800935D4 1319010C */  jal        func_8004644C
    /* 2ADD8 800935D8 00020424 */   addiu     $a0, $zero, 0x200
    /* 2ADDC 800935DC 0F80033C */  lui        $v1, %hi(D_800F2258)
    /* 2ADE0 800935E0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2ADE4 800935E4 582262A4 */  sh         $v0, %lo(D_800F2258)($v1)
  .L800935E8:
    /* 2ADE8 800935E8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2ADEC 800935EC 21100000 */  addu       $v0, $zero, $zero
    /* 2ADF0 800935F0 0800E003 */  jr         $ra
    /* 2ADF4 800935F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800935B8
