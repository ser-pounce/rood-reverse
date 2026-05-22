nonmatching func_8002E368, 0x110

glabel func_8002E368
    /* 1EB68 8002E368 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1EB6C 8002E36C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1EB70 8002E370 21808000 */  addu       $s0, $a0, $zero
    /* 1EB74 8002E374 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1EB78 8002E378 3C00028E */  lw         $v0, 0x3C($s0)
    /* 1EB7C 8002E37C 00000000 */  nop
    /* 1EB80 8002E380 00004390 */  lbu        $v1, 0x0($v0)
    /* 1EB84 8002E384 F3000224 */  addiu      $v0, $zero, 0xF3
    /* 1EB88 8002E388 12006214 */  bne        $v1, $v0, .L8002E3D4
    /* 1EB8C 8002E38C 00000000 */   nop
    /* 1EB90 8002E390 E8000292 */  lbu        $v0, 0xE8($s0)
    /* 1EB94 8002E394 00000000 */  nop
    /* 1EB98 8002E398 24004010 */  beqz       $v0, .L8002E42C
    /* 1EB9C 8002E39C FF000224 */   addiu     $v0, $zero, 0xFF
    /* 1EBA0 8002E3A0 46000392 */  lbu        $v1, 0x46($s0)
    /* 1EBA4 8002E3A4 00000000 */  nop
    /* 1EBA8 8002E3A8 1F006210 */  beq        $v1, $v0, .L8002E428
    /* 1EBAC 8002E3AC 02000224 */   addiu     $v0, $zero, 0x2
    /* 1EBB0 8002E3B0 49000392 */  lbu        $v1, 0x49($s0)
    /* 1EBB4 8002E3B4 00000000 */  nop
    /* 1EBB8 8002E3B8 06006214 */  bne        $v1, $v0, .L8002E3D4
    /* 1EBBC 8002E3BC 00000000 */   nop
    /* 1EBC0 8002E3C0 0380023C */  lui        $v0, %hi(D_800335A0)
    /* 1EBC4 8002E3C4 A035428C */  lw         $v0, %lo(D_800335A0)($v0)
    /* 1EBC8 8002E3C8 00000000 */  nop
    /* 1EBCC 8002E3CC 09F84000 */  jalr       $v0
    /* 1EBD0 8002E3D0 21200002 */   addu      $a0, $s0, $zero
  .L8002E3D4:
    /* 1EBD4 8002E3D4 46000392 */  lbu        $v1, 0x46($s0)
    /* 1EBD8 8002E3D8 01000224 */  addiu      $v0, $zero, 0x1
    /* 1EBDC 8002E3DC 0D006210 */  beq        $v1, $v0, .L8002E414
    /* 1EBE0 8002E3E0 02006228 */   slti      $v0, $v1, 0x2
    /* 1EBE4 8002E3E4 05004010 */  beqz       $v0, .L8002E3FC
    /* 1EBE8 8002E3E8 FE000224 */   addiu     $v0, $zero, 0xFE
    /* 1EBEC 8002E3EC 1E006010 */  beqz       $v1, .L8002E468
    /* 1EBF0 8002E3F0 21100000 */   addu      $v0, $zero, $zero
    /* 1EBF4 8002E3F4 0FB90008 */  j          .L8002E43C
    /* 1EBF8 8002E3F8 00000000 */   nop
  .L8002E3FC:
    /* 1EBFC 8002E3FC 0A006210 */  beq        $v1, $v0, .L8002E428
    /* 1EC00 8002E400 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 1EC04 8002E404 18006210 */  beq        $v1, $v0, .L8002E468
    /* 1EC08 8002E408 21100000 */   addu      $v0, $zero, $zero
    /* 1EC0C 8002E40C 0FB90008 */  j          .L8002E43C
    /* 1EC10 8002E410 00000000 */   nop
  .L8002E414:
    /* 1EC14 8002E414 21200002 */  addu       $a0, $s0, $zero
    /* 1EC18 8002E418 7AB5000C */  jal        _padCmdParaMode
    /* 1EC1C 8002E41C 01000524 */   addiu     $a1, $zero, 0x1
    /* 1EC20 8002E420 1AB90008 */  j          .L8002E468
    /* 1EC24 8002E424 21100000 */   addu      $v0, $zero, $zero
  .L8002E428:
    /* 1EC28 8002E428 21200002 */  addu       $a0, $s0, $zero
  .L8002E42C:
    /* 1EC2C 8002E42C 7AB5000C */  jal        _padCmdParaMode
    /* 1EC30 8002E430 21280000 */   addu      $a1, $zero, $zero
    /* 1EC34 8002E434 1AB90008 */  j          .L8002E468
    /* 1EC38 8002E438 21100000 */   addu      $v0, $zero, $zero
  .L8002E43C:
    /* 1EC3C 8002E43C 1400028E */  lw         $v0, 0x14($s0)
    /* 1EC40 8002E440 00000000 */  nop
    /* 1EC44 8002E444 05004010 */  beqz       $v0, .L8002E45C
    /* 1EC48 8002E448 00000000 */   nop
    /* 1EC4C 8002E44C 09F84000 */  jalr       $v0
    /* 1EC50 8002E450 21200002 */   addu      $a0, $s0, $zero
    /* 1EC54 8002E454 1AB90008 */  j          .L8002E468
    /* 1EC58 8002E458 21100000 */   addu      $v0, $zero, $zero
  .L8002E45C:
    /* 1EC5C 8002E45C ACB2000C */  jal        _padSendAtLoadInfo
    /* 1EC60 8002E460 21200002 */   addu      $a0, $s0, $zero
    /* 1EC64 8002E464 21100000 */  addu       $v0, $zero, $zero
  .L8002E468:
    /* 1EC68 8002E468 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1EC6C 8002E46C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1EC70 8002E470 0800E003 */  jr         $ra
    /* 1EC74 8002E474 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002E368
