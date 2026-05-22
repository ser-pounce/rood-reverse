nonmatching _removeActor, 0x64

glabel _removeActor
    /* 19C4 8006A1C4 0400828C */  lw         $v0, 0x4($a0)
    /* 19C8 8006A1C8 00000000 */  nop
    /* 19CC 8006A1CC 14004010 */  beqz       $v0, .L8006A220
    /* 19D0 8006A1D0 21300000 */   addu      $a2, $zero, $zero
    /* 19D4 8006A1D4 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 19D8 8006A1D8 28194324 */  addiu      $v1, $v0, %lo(vs_battle_actors)
  .L8006A1DC:
    /* 19DC 8006A1DC 0000658C */  lw         $a1, 0x0($v1)
    /* 19E0 8006A1E0 00000000 */  nop
    /* 19E4 8006A1E4 0A00A010 */  beqz       $a1, .L8006A210
    /* 19E8 8006A1E8 00000000 */   nop
    /* 19EC 8006A1EC 0000A28C */  lw         $v0, 0x0($a1)
    /* 19F0 8006A1F0 00000000 */  nop
    /* 19F4 8006A1F4 07004414 */  bne        $v0, $a0, .L8006A214
    /* 19F8 8006A1F8 0100C624 */   addiu     $a2, $a2, 0x1
    /* 19FC 8006A1FC 0000838C */  lw         $v1, 0x0($a0)
    /* 1A00 8006A200 01000224 */  addiu      $v0, $zero, 0x1
    /* 1A04 8006A204 0000A3AC */  sw         $v1, 0x0($a1)
    /* 1A08 8006A208 0800E003 */  jr         $ra
    /* 1A0C 8006A20C 000080AC */   sw        $zero, 0x0($a0)
  .L8006A210:
    /* 1A10 8006A210 0100C624 */  addiu      $a2, $a2, 0x1
  .L8006A214:
    /* 1A14 8006A214 1000C228 */  slti       $v0, $a2, 0x10
    /* 1A18 8006A218 F0FF4014 */  bnez       $v0, .L8006A1DC
    /* 1A1C 8006A21C 04006324 */   addiu     $v1, $v1, 0x4
  .L8006A220:
    /* 1A20 8006A220 0800E003 */  jr         $ra
    /* 1A24 8006A224 21100000 */   addu      $v0, $zero, $zero
endlabel _removeActor
