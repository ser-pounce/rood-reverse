nonmatching func_800D6A18, 0xD4

glabel func_800D6A18
    /* 6E218 800D6A18 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6E21C 800D6A1C 2000B0AF */  sw         $s0, 0x20($sp)
    /* 6E220 800D6A20 2180A000 */  addu       $s0, $a1, $zero
    /* 6E224 800D6A24 2400B1AF */  sw         $s1, 0x24($sp)
    /* 6E228 800D6A28 2800BFAF */  sw         $ra, 0x28($sp)
    /* 6E22C 800D6A2C 06000286 */  lh         $v0, 0x6($s0)
    /* 6E230 800D6A30 0000058E */  lw         $a1, 0x0($s0)
    /* 6E234 800D6A34 4C0D838C */  lw         $v1, 0xD4C($a0)
    /* 6E238 800D6A38 C0100200 */  sll        $v0, $v0, 3
    /* 6E23C 800D6A3C 21104500 */  addu       $v0, $v0, $a1
    /* 6E240 800D6A40 00004294 */  lhu        $v0, 0x0($v0)
    /* 6E244 800D6A44 02006484 */  lh         $a0, 0x2($v1)
    /* 6E248 800D6A48 FF014330 */  andi       $v1, $v0, 0x1FF
    /* 6E24C 800D6A4C 2A108300 */  slt        $v0, $a0, $v1
    /* 6E250 800D6A50 20004014 */  bnez       $v0, .L800D6AD4
    /* 6E254 800D6A54 01001124 */   addiu     $s1, $zero, 0x1
    /* 6E258 800D6A58 14006414 */  bne        $v1, $a0, .L800D6AAC
    /* 6E25C 800D6A5C 00000000 */   nop
    /* 6E260 800D6A60 0400A78C */  lw         $a3, 0x4($a1)
    /* 6E264 800D6A64 00000000 */  nop
    /* 6E268 800D6A68 42140700 */  srl        $v0, $a3, 17
    /* 6E26C 800D6A6C 7F004230 */  andi       $v0, $v0, 0x7F
    /* 6E270 800D6A70 0F00E430 */  andi       $a0, $a3, 0xF
    /* 6E274 800D6A74 42320700 */  srl        $a2, $a3, 9
    /* 6E278 800D6A78 1000A2AF */  sw         $v0, 0x10($sp)
    /* 6E27C 800D6A7C 0700A290 */  lbu        $v0, 0x7($a1)
    /* 6E280 800D6A80 7F00C630 */  andi       $a2, $a2, 0x7F
    /* 6E284 800D6A84 01004230 */  andi       $v0, $v0, 0x1
    /* 6E288 800D6A88 1400A2AF */  sw         $v0, 0x14($sp)
    /* 6E28C 800D6A8C 0400A28C */  lw         $v0, 0x4($a1)
    /* 6E290 800D6A90 02290700 */  srl        $a1, $a3, 4
    /* 6E294 800D6A94 023C0700 */  srl        $a3, $a3, 16
    /* 6E298 800D6A98 1F00A530 */  andi       $a1, $a1, 0x1F
    /* 6E29C 800D6A9C 0100E730 */  andi       $a3, $a3, 0x1
    /* 6E2A0 800D6AA0 42160200 */  srl        $v0, $v0, 25
    /* 6E2A4 800D6AA4 BC47030C */  jal        func_800D1EF0
    /* 6E2A8 800D6AA8 1800A2AF */   sw        $v0, 0x18($sp)
  .L800D6AAC:
    /* 6E2AC 800D6AAC 0A000296 */  lhu        $v0, 0xA($s0)
    /* 6E2B0 800D6AB0 00000000 */  nop
    /* 6E2B4 800D6AB4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 6E2B8 800D6AB8 0A0002A6 */  sh         $v0, 0xA($s0)
    /* 6E2BC 800D6ABC 00140200 */  sll        $v0, $v0, 16
    /* 6E2C0 800D6AC0 05004014 */  bnez       $v0, .L800D6AD8
    /* 6E2C4 800D6AC4 21102002 */   addu      $v0, $s1, $zero
    /* 6E2C8 800D6AC8 E055030C */  jal        func_800D5780
    /* 6E2CC 800D6ACC 21200002 */   addu      $a0, $s0, $zero
    /* 6E2D0 800D6AD0 21884000 */  addu       $s1, $v0, $zero
  .L800D6AD4:
    /* 6E2D4 800D6AD4 21102002 */  addu       $v0, $s1, $zero
  .L800D6AD8:
    /* 6E2D8 800D6AD8 2800BF8F */  lw         $ra, 0x28($sp)
    /* 6E2DC 800D6ADC 2400B18F */  lw         $s1, 0x24($sp)
    /* 6E2E0 800D6AE0 2000B08F */  lw         $s0, 0x20($sp)
    /* 6E2E4 800D6AE4 0800E003 */  jr         $ra
    /* 6E2E8 800D6AE8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800D6A18
