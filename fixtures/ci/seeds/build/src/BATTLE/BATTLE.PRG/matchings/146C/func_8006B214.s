nonmatching func_8006B214, 0x5C

glabel func_8006B214
    /* 2A14 8006B214 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 2A18 8006B218 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 2A1C 8006B21C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A20 8006B220 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2A24 8006B224 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A28 8006B228 3C00508C */  lw         $s0, 0x3C($v0)
    /* 2A2C 8006B22C 00000000 */  nop
    /* 2A30 8006B230 4809028E */  lw         $v0, 0x948($s0)
    /* 2A34 8006B234 1000033C */  lui        $v1, (0x100000 >> 16)
    /* 2A38 8006B238 24104300 */  and        $v0, $v0, $v1
    /* 2A3C 8006B23C 08004010 */  beqz       $v0, .L8006B260
    /* 2A40 8006B240 21306000 */   addu      $a2, $v1, $zero
    /* 2A44 8006B244 57090492 */  lbu        $a0, 0x957($s0)
    /* 2A48 8006B248 21280000 */  addu       $a1, $zero, $zero
    /* 2A4C 8006B24C FB4F020C */  jal        func_80093FEC
    /* 2A50 8006B250 01000724 */   addiu     $a3, $zero, 0x1
    /* 2A54 8006B254 1000043C */  lui        $a0, (0x100000 >> 16)
    /* 2A58 8006B258 D519020C */  jal        func_80086754
    /* 2A5C 8006B25C 21280002 */   addu      $a1, $s0, $zero
  .L8006B260:
    /* 2A60 8006B260 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2A64 8006B264 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A68 8006B268 0800E003 */  jr         $ra
    /* 2A6C 8006B26C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006B214
