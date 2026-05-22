nonmatching func_800CA97C, 0x44

glabel func_800CA97C
    /* 6217C 800CA97C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 62180 800CA980 0F80023C */  lui        $v0, %hi(D_800EB9B4)
    /* 62184 800CA984 1000B0AF */  sw         $s0, 0x10($sp)
    /* 62188 800CA988 0F80103C */  lui        $s0, %hi(D_800F4ED8)
    /* 6218C 800CA98C D84E1026 */  addiu      $s0, $s0, %lo(D_800F4ED8)
    /* 62190 800CA990 21200002 */  addu       $a0, $s0, $zero
    /* 62194 800CA994 21280000 */  addu       $a1, $zero, $zero
    /* 62198 800CA998 10000624 */  addiu      $a2, $zero, 0x10
    /* 6219C 800CA99C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 621A0 800CA9A0 AD9B000C */  jal        memset
    /* 621A4 800CA9A4 B4B940AC */   sw        $zero, %lo(D_800EB9B4)($v0)
    /* 621A8 800CA9A8 00100224 */  addiu      $v0, $zero, 0x1000
    /* 621AC 800CA9AC 040002A6 */  sh         $v0, 0x4($s0)
    /* 621B0 800CA9B0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 621B4 800CA9B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 621B8 800CA9B8 0800E003 */  jr         $ra
    /* 621BC 800CA9BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CA97C
