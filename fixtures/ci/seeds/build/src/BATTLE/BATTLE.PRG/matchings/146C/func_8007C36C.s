nonmatching func_8007C36C, 0x2C

glabel func_8007C36C
    /* 13B6C 8007C36C 02000224 */  addiu      $v0, $zero, 0x2
    /* 13B70 8007C370 03008210 */  beq        $a0, $v0, .L8007C380
    /* 13B74 8007C374 04000224 */   addiu     $v0, $zero, 0x4
    /* 13B78 8007C378 04008214 */  bne        $a0, $v0, .L8007C38C
    /* 13B7C 8007C37C 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
  .L8007C380:
    /* 13B80 8007C380 0680023C */  lui        $v0, %hi(vs_gametime_tickspeed)
    /* 13B84 8007C384 4CE244AC */  sw         $a0, %lo(vs_gametime_tickspeed)($v0)
    /* 13B88 8007C388 0680023C */  lui        $v0, %hi(vs_gametime_tickspeed)
  .L8007C38C:
    /* 13B8C 8007C38C 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 13B90 8007C390 0800E003 */  jr         $ra
    /* 13B94 8007C394 00000000 */   nop
endlabel func_8007C36C
