nonmatching func_8007D260, 0x54

glabel func_8007D260
    /* 14A60 8007D260 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14A64 8007D264 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 14A68 8007D268 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 14A6C 8007D26C 80100400 */  sll        $v0, $a0, 2
    /* 14A70 8007D270 21104300 */  addu       $v0, $v0, $v1
    /* 14A74 8007D274 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14A78 8007D278 0000458C */  lw         $a1, 0x0($v0)
    /* 14A7C 8007D27C 00000000 */  nop
    /* 14A80 8007D280 0600A010 */  beqz       $a1, .L8007D29C
    /* 14A84 8007D284 20000224 */   addiu     $v0, $zero, 0x20
    /* 14A88 8007D288 0800A390 */  lbu        $v1, 0x8($a1)
    /* 14A8C 8007D28C 00000000 */  nop
    /* 14A90 8007D290 02006210 */  beq        $v1, $v0, .L8007D29C
    /* 14A94 8007D294 00000000 */   nop
    /* 14A98 8007D298 0800A0A0 */  sb         $zero, 0x8($a1)
  .L8007D29C:
    /* 14A9C 8007D29C 0E77020C */  jal        func_8009DC38
    /* 14AA0 8007D2A0 00000000 */   nop
    /* 14AA4 8007D2A4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14AA8 8007D2A8 00000000 */  nop
    /* 14AAC 8007D2AC 0800E003 */  jr         $ra
    /* 14AB0 8007D2B0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007D260
