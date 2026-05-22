nonmatching func_8007CAA4, 0xE0

glabel func_8007CAA4
    /* 142A4 8007CAA4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 142A8 8007CAA8 2000B2AF */  sw         $s2, 0x20($sp)
    /* 142AC 8007CAAC 21908000 */  addu       $s2, $a0, $zero
    /* 142B0 8007CAB0 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 142B4 8007CAB4 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 142B8 8007CAB8 80101200 */  sll        $v0, $s2, 2
    /* 142BC 8007CABC 21104300 */  addu       $v0, $v0, $v1
    /* 142C0 8007CAC0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 142C4 8007CAC4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 142C8 8007CAC8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 142CC 8007CACC 0000518C */  lw         $s1, 0x0($v0)
    /* 142D0 8007CAD0 00000000 */  nop
    /* 142D4 8007CAD4 25002012 */  beqz       $s1, .L8007CB6C
    /* 142D8 8007CAD8 00000000 */   nop
    /* 142DC 8007CADC 3C00308E */  lw         $s0, 0x3C($s1)
    /* 142E0 8007CAE0 00000000 */  nop
    /* 142E4 8007CAE4 21000012 */  beqz       $s0, .L8007CB6C
    /* 142E8 8007CAE8 00000000 */   nop
    /* 142EC 8007CAEC 54000296 */  lhu        $v0, 0x54($s0)
    /* 142F0 8007CAF0 00000000 */  nop
    /* 142F4 8007CAF4 07004010 */  beqz       $v0, .L8007CB14
    /* 142F8 8007CAF8 21202002 */   addu      $a0, $s1, $zero
    /* 142FC 8007CAFC 21284002 */  addu       $a1, $s2, $zero
    /* 14300 8007CB00 44010692 */  lbu        $a2, 0x144($s0)
    /* 14304 8007CB04 67000292 */  lbu        $v0, 0x67($s0)
    /* 14308 8007CB08 21380000 */  addu       $a3, $zero, $zero
    /* 1430C 8007CB0C C9F20108 */  j          .L8007CB24
    /* 14310 8007CB10 1000A2AF */   sw        $v0, 0x10($sp)
  .L8007CB14:
    /* 14314 8007CB14 1000A0AF */  sw         $zero, 0x10($sp)
    /* 14318 8007CB18 21284002 */  addu       $a1, $s2, $zero
    /* 1431C 8007CB1C 21300000 */  addu       $a2, $zero, $zero
    /* 14320 8007CB20 2138C000 */  addu       $a3, $a2, $zero
  .L8007CB24:
    /* 14324 8007CB24 4CDC010C */  jal        func_80077130
    /* 14328 8007CB28 00000000 */   nop
    /* 1432C 8007CB2C EC010296 */  lhu        $v0, 0x1EC($s0)
    /* 14330 8007CB30 00000000 */  nop
    /* 14334 8007CB34 07004010 */  beqz       $v0, .L8007CB54
    /* 14338 8007CB38 21202002 */   addu      $a0, $s1, $zero
    /* 1433C 8007CB3C 21284002 */  addu       $a1, $s2, $zero
    /* 14340 8007CB40 AC020692 */  lbu        $a2, 0x2AC($s0)
    /* 14344 8007CB44 FF010292 */  lbu        $v0, 0x1FF($s0)
    /* 14348 8007CB48 01000724 */  addiu      $a3, $zero, 0x1
    /* 1434C 8007CB4C D9F20108 */  j          .L8007CB64
    /* 14350 8007CB50 1000A2AF */   sw        $v0, 0x10($sp)
  .L8007CB54:
    /* 14354 8007CB54 1000A0AF */  sw         $zero, 0x10($sp)
    /* 14358 8007CB58 21284002 */  addu       $a1, $s2, $zero
    /* 1435C 8007CB5C 21300000 */  addu       $a2, $zero, $zero
    /* 14360 8007CB60 2138C000 */  addu       $a3, $a2, $zero
  .L8007CB64:
    /* 14364 8007CB64 4CDC010C */  jal        func_80077130
    /* 14368 8007CB68 00000000 */   nop
  .L8007CB6C:
    /* 1436C 8007CB6C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 14370 8007CB70 2000B28F */  lw         $s2, 0x20($sp)
    /* 14374 8007CB74 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 14378 8007CB78 1800B08F */  lw         $s0, 0x18($sp)
    /* 1437C 8007CB7C 0800E003 */  jr         $ra
    /* 14380 8007CB80 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007CAA4
