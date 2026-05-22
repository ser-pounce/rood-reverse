nonmatching func_800773BC, 0x140

glabel func_800773BC
    /* EBBC 800773BC C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* EBC0 800773C0 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* EBC4 800773C4 21A88000 */  addu       $s5, $a0, $zero
    /* EBC8 800773C8 2800B4AF */  sw         $s4, 0x28($sp)
    /* EBCC 800773CC 21A0A000 */  addu       $s4, $a1, $zero
    /* EBD0 800773D0 1800B0AF */  sw         $s0, 0x18($sp)
    /* EBD4 800773D4 2180C000 */  addu       $s0, $a2, $zero
    /* EBD8 800773D8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* EBDC 800773DC 2188E000 */  addu       $s1, $a3, $zero
    /* EBE0 800773E0 21208002 */  addu       $a0, $s4, $zero
    /* EBE4 800773E4 21280000 */  addu       $a1, $zero, $zero
    /* EBE8 800773E8 2000B2AF */  sw         $s2, 0x20($sp)
    /* EBEC 800773EC 4800B28F */  lw         $s2, 0x48($sp)
    /* EBF0 800773F0 2130A000 */  addu       $a2, $a1, $zero
    /* EBF4 800773F4 2400B3AF */  sw         $s3, 0x24($sp)
    /* EBF8 800773F8 4C00B38F */  lw         $s3, 0x4C($sp)
    /* EBFC 800773FC 3000BFAF */  sw         $ra, 0x30($sp)
    /* EC00 80077400 8180020C */  jal        func_800A0204
    /* EC04 80077404 2138A000 */   addu      $a3, $a1, $zero
    /* EC08 80077408 21208002 */  addu       $a0, $s4, $zero
    /* EC0C 8007740C 1F82020C */  jal        func_800A087C
    /* EC10 80077410 47180524 */   addiu     $a1, $zero, 0x1847
    /* EC14 80077414 21208002 */  addu       $a0, $s4, $zero
    /* EC18 80077418 21280002 */  addu       $a1, $s0, $zero
    /* EC1C 8007741C 21302002 */  addu       $a2, $s1, $zero
    /* EC20 80077420 0F80103C */  lui        $s0, %hi(vs_battle_actors)
    /* EC24 80077424 28190326 */  addiu      $v1, $s0, %lo(vs_battle_actors)
    /* EC28 80077428 80101400 */  sll        $v0, $s4, 2
    /* EC2C 8007742C 21104300 */  addu       $v0, $v0, $v1
    /* EC30 80077430 000055AC */  sw         $s5, 0x0($v0)
    /* EC34 80077434 21384002 */  addu       $a3, $s2, $zero
    /* EC38 80077438 54DB010C */  jal        func_80076D50
    /* EC3C 8007743C 1000B3AF */   sw        $s3, 0x10($sp)
    /* EC40 80077440 21208002 */  addu       $a0, $s4, $zero
    /* EC44 80077444 00900534 */  ori        $a1, $zero, 0x9000
    /* EC48 80077448 0100063C */  lui        $a2, (0x12000 >> 16)
    /* EC4C 8007744C BF82020C */  jal        func_800A0AFC
    /* EC50 80077450 0020C634 */   ori       $a2, $a2, (0x12000 & 0xFFFF)
    /* EC54 80077454 21208002 */  addu       $a0, $s4, $zero
    /* EC58 80077458 CF77020C */  jal        func_8009DF3C
    /* EC5C 8007745C 21280000 */   addu      $a1, $zero, $zero
    /* EC60 80077460 1C00A296 */  lhu        $v0, 0x1C($s5)
    /* EC64 80077464 00000000 */  nop
    /* EC68 80077468 07004230 */  andi       $v0, $v0, 0x7
    /* EC6C 8007746C 0C004010 */  beqz       $v0, .L800774A0
    /* EC70 80077470 00000000 */   nop
    /* EC74 80077474 09008012 */  beqz       $s4, .L8007749C
    /* EC78 80077478 00000000 */   nop
    /* EC7C 8007747C 2819028E */  lw         $v0, %lo(vs_battle_actors)($s0)
    /* EC80 80077480 00000000 */  nop
    /* EC84 80077484 0000428C */  lw         $v0, 0x0($v0)
    /* EC88 80077488 00000000 */  nop
    /* EC8C 8007748C 0000A2AE */  sw         $v0, 0x0($s5)
    /* EC90 80077490 2819028E */  lw         $v0, %lo(vs_battle_actors)($s0)
    /* EC94 80077494 28DD0108 */  j          .L800774A0
    /* EC98 80077498 000055AC */   sw        $s5, 0x0($v0)
  .L8007749C:
    /* EC9C 8007749C 0000A0AE */  sw         $zero, 0x0($s5)
  .L800774A0:
    /* ECA0 800774A0 2000A28E */  lw         $v0, 0x20($s5)
    /* ECA4 800774A4 00000000 */  nop
    /* ECA8 800774A8 01004230 */  andi       $v0, $v0, 0x1
    /* ECAC 800774AC 03004010 */  beqz       $v0, .L800774BC
    /* ECB0 800774B0 21208002 */   addu      $a0, $s4, $zero
    /* ECB4 800774B4 30DD0108 */  j          .L800774C0
    /* ECB8 800774B8 46180524 */   addiu     $a1, $zero, 0x1846
  .L800774BC:
    /* ECBC 800774BC 46000524 */  addiu      $a1, $zero, 0x46
  .L800774C0:
    /* ECC0 800774C0 1F82020C */  jal        func_800A087C
    /* ECC4 800774C4 00000000 */   nop
    /* ECC8 800774C8 2120A002 */  addu       $a0, $s5, $zero
    /* ECCC 800774CC FFFF0524 */  addiu      $a1, $zero, -0x1
    /* ECD0 800774D0 5E98030C */  jal        func_800E6178
    /* ECD4 800774D4 3800A0AE */   sw        $zero, 0x38($s5)
    /* ECD8 800774D8 3000BF8F */  lw         $ra, 0x30($sp)
    /* ECDC 800774DC 2C00B58F */  lw         $s5, 0x2C($sp)
    /* ECE0 800774E0 2800B48F */  lw         $s4, 0x28($sp)
    /* ECE4 800774E4 2400B38F */  lw         $s3, 0x24($sp)
    /* ECE8 800774E8 2000B28F */  lw         $s2, 0x20($sp)
    /* ECEC 800774EC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* ECF0 800774F0 1800B08F */  lw         $s0, 0x18($sp)
    /* ECF4 800774F4 0800E003 */  jr         $ra
    /* ECF8 800774F8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800773BC
