nonmatching func_8007C28C, 0x90

glabel func_8007C28C
    /* 13A8C 8007C28C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13A90 8007C290 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 13A94 8007C294 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 13A98 8007C298 80200400 */  sll        $a0, $a0, 2
    /* 13A9C 8007C29C 21208200 */  addu       $a0, $a0, $v0
    /* 13AA0 8007C2A0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 13AA4 8007C2A4 0000848C */  lw         $a0, 0x0($a0)
    /* 13AA8 8007C2A8 00000000 */  nop
    /* 13AAC 8007C2AC 17008010 */  beqz       $a0, .L8007C30C
    /* 13AB0 8007C2B0 00000000 */   nop
    /* 13AB4 8007C2B4 3C00858C */  lw         $a1, 0x3C($a0)
    /* 13AB8 8007C2B8 00000000 */  nop
    /* 13ABC 8007C2BC 1300A010 */  beqz       $a1, .L8007C30C
    /* 13AC0 8007C2C0 21300000 */   addu      $a2, $zero, $zero
    /* 13AC4 8007C2C4 1A00A294 */  lhu        $v0, 0x1A($a1)
    /* 13AC8 8007C2C8 1E00A394 */  lhu        $v1, 0x1E($a1)
    /* 13ACC 8007C2CC 2120A000 */  addu       $a0, $a1, $zero
    /* 13AD0 8007C2D0 2000A0A4 */  sh         $zero, 0x20($a1)
    /* 13AD4 8007C2D4 5409A0A4 */  sh         $zero, 0x954($a1)
    /* 13AD8 8007C2D8 1800A2A4 */  sh         $v0, 0x18($a1)
    /* 13ADC 8007C2DC 1C00A3A4 */  sh         $v1, 0x1C($a1)
  .L8007C2E0:
    /* 13AE0 8007C2E0 9A038294 */  lhu        $v0, 0x39A($a0)
    /* 13AE4 8007C2E4 0100C624 */  addiu      $a2, $a2, 0x1
    /* 13AE8 8007C2E8 980382A4 */  sh         $v0, 0x398($a0)
    /* 13AEC 8007C2EC 0600C228 */  slti       $v0, $a2, 0x6
    /* 13AF0 8007C2F0 FBFF4014 */  bnez       $v0, .L8007C2E0
    /* 13AF4 8007C2F4 DC008424 */   addiu     $a0, $a0, 0xDC
    /* 13AF8 8007C2F8 FF7F043C */  lui        $a0, (0x7FFFFFFF >> 16)
    /* 13AFC 8007C2FC D519020C */  jal        func_80086754
    /* 13B00 8007C300 FFFF8434 */   ori       $a0, $a0, (0x7FFFFFFF & 0xFFFF)
    /* 13B04 8007C304 0F80023C */  lui        $v0, %hi(D_800F5160)
    /* 13B08 8007C308 605140A4 */  sh         $zero, %lo(D_800F5160)($v0)
  .L8007C30C:
    /* 13B0C 8007C30C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13B10 8007C310 00000000 */  nop
    /* 13B14 8007C314 0800E003 */  jr         $ra
    /* 13B18 8007C318 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007C28C
