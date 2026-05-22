nonmatching func_80042054, 0x68

glabel func_80042054
    /* 32854 80042054 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 32858 80042058 21388000 */  addu       $a3, $a0, $zero
    /* 3285C 8004205C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 32860 80042060 0680103C */  lui        $s0, %hi(vs_main_dispEnv)
    /* 32864 80042064 88E11026 */  addiu      $s0, $s0, %lo(vs_main_dispEnv)
    /* 32868 80042068 21200002 */  addu       $a0, $s0, $zero
    /* 3286C 8004206C F0FFA524 */  addiu      $a1, $a1, -0x10
    /* 32870 80042070 1000A5AF */  sw         $a1, 0x10($sp)
    /* 32874 80042074 21280000 */  addu       $a1, $zero, $zero
    /* 32878 80042078 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3287C 8004207C 0DAD000C */  jal        SetDefDispEnv
    /* 32880 80042080 2130A000 */   addu      $a2, $a1, $zero
    /* 32884 80042084 21200002 */  addu       $a0, $s0, $zero
    /* 32888 80042088 08008324 */  addiu      $v1, $a0, 0x8
    /* 3288C 8004208C 08000224 */  addiu      $v0, $zero, 0x8
    /* 32890 80042090 080080A4 */  sh         $zero, 0x8($a0)
    /* 32894 80042094 020062A4 */  sh         $v0, 0x2($v1)
    /* 32898 80042098 00010224 */  addiu      $v0, $zero, 0x100
    /* 3289C 8004209C 040062A4 */  sh         $v0, 0x4($v1)
    /* 328A0 800420A0 E0000224 */  addiu      $v0, $zero, 0xE0
    /* 328A4 800420A4 A0A3000C */  jal        PutDispEnv
    /* 328A8 800420A8 060062A4 */   sh        $v0, 0x6($v1)
    /* 328AC 800420AC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 328B0 800420B0 1800B08F */  lw         $s0, 0x18($sp)
    /* 328B4 800420B4 0800E003 */  jr         $ra
    /* 328B8 800420B8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80042054
