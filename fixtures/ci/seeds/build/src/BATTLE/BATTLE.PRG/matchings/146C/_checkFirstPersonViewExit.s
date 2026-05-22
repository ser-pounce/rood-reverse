nonmatching _checkFirstPersonViewExit, 0x158

glabel _checkFirstPersonViewExit
    /* BDEC 800745EC 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* BDF0 800745F0 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* BDF4 800745F4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* BDF8 800745F8 2400BFAF */  sw         $ra, 0x24($sp)
    /* BDFC 800745FC 400C4230 */  andi       $v0, $v0, 0xC40
    /* BE00 80074600 4C004010 */  beqz       $v0, .L80074734
    /* BE04 80074604 2000B0AF */   sw        $s0, 0x20($sp)
    /* BE08 80074608 21200000 */  addu       $a0, $zero, $zero
    /* BE0C 8007460C 1000A527 */  addiu      $a1, $sp, 0x10
    /* BE10 80074610 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* BE14 80074614 02000224 */  addiu      $v0, $zero, 0x2
    /* BE18 80074618 F01862AC */  sw         $v0, %lo(_cameraMode)($v1)
    /* BE1C 8007461C 0F80023C */  lui        $v0, %hi(_firstPersonViewEnabled)
    /* BE20 80074620 6C1840AC */  sw         $zero, %lo(_firstPersonViewEnabled)($v0)
    /* BE24 80074624 0F80023C */  lui        $v0, %hi(D_800F19C8)
    /* BE28 80074628 4284020C */  jal        func_800A1108
    /* BE2C 8007462C C81940AC */   sw        $zero, %lo(D_800F19C8)($v0)
    /* BE30 80074630 21200000 */  addu       $a0, $zero, $zero
    /* BE34 80074634 C5D2010C */  jal        func_80074B14
    /* BE38 80074638 1000A527 */   addiu     $a1, $sp, 0x10
    /* BE3C 8007463C 0F80103C */  lui        $s0, %hi(vs_battle_cameraTransition)
    /* BE40 80074640 0419048E */  lw         $a0, %lo(vs_battle_cameraTransition)($s0)
    /* BE44 80074644 14EA010C */  jal        vs_battle_syncCameraAnglesFromPosition
    /* BE48 80074648 6C008424 */   addiu     $a0, $a0, 0x6C
    /* BE4C 8007464C 0419048E */  lw         $a0, %lo(vs_battle_cameraTransition)($s0)
    /* BE50 80074650 00000000 */  nop
    /* BE54 80074654 6C00838C */  lw         $v1, 0x6C($a0)
    /* BE58 80074658 00000000 */  nop
    /* BE5C 8007465C 02006104 */  bgez       $v1, .L80074668
    /* BE60 80074660 21106000 */   addu      $v0, $v1, $zero
    /* BE64 80074664 FF016224 */  addiu      $v0, $v1, 0x1FF
  .L80074668:
    /* BE68 80074668 43120200 */  sra        $v0, $v0, 9
    /* BE6C 8007466C 40120200 */  sll        $v0, $v0, 9
    /* BE70 80074670 23106200 */  subu       $v0, $v1, $v0
    /* BE74 80074674 01014228 */  slti       $v0, $v0, 0x101
    /* BE78 80074678 04004014 */  bnez       $v0, .L8007468C
    /* BE7C 8007467C 00FE0224 */   addiu     $v0, $zero, -0x200
    /* BE80 80074680 24106200 */  and        $v0, $v1, $v0
    /* BE84 80074684 A4D10108 */  j          .L80074690
    /* BE88 80074688 00024224 */   addiu     $v0, $v0, 0x200
  .L8007468C:
    /* BE8C 8007468C 24106200 */  and        $v0, $v1, $v0
  .L80074690:
    /* BE90 80074690 6C0082AC */  sw         $v0, 0x6C($a0)
    /* BE94 80074694 0F80023C */  lui        $v0, %hi(vs_battle_cameraTransition)
    /* BE98 80074698 0419428C */  lw         $v0, %lo(vs_battle_cameraTransition)($v0)
    /* BE9C 8007469C 00000000 */  nop
    /* BEA0 800746A0 6C004624 */  addiu      $a2, $v0, 0x6C
    /* BEA4 800746A4 34004524 */  addiu      $a1, $v0, 0x34
    /* BEA8 800746A8 6C00438C */  lw         $v1, 0x6C($v0)
    /* BEAC 800746AC 54004424 */  addiu      $a0, $v0, 0x54
    /* BEB0 800746B0 440040AC */  sw         $zero, 0x44($v0)
    /* BEB4 800746B4 340043AC */  sw         $v1, 0x34($v0)
  .L800746B8:
    /* BEB8 800746B8 0000A78C */  lw         $a3, 0x0($a1)
    /* BEBC 800746BC 0400A88C */  lw         $t0, 0x4($a1)
    /* BEC0 800746C0 0800A98C */  lw         $t1, 0x8($a1)
    /* BEC4 800746C4 0C00AA8C */  lw         $t2, 0xC($a1)
    /* BEC8 800746C8 0000C7AC */  sw         $a3, 0x0($a2)
    /* BECC 800746CC 0400C8AC */  sw         $t0, 0x4($a2)
    /* BED0 800746D0 0800C9AC */  sw         $t1, 0x8($a2)
    /* BED4 800746D4 0C00CAAC */  sw         $t2, 0xC($a2)
    /* BED8 800746D8 1000A524 */  addiu      $a1, $a1, 0x10
    /* BEDC 800746DC F6FFA414 */  bne        $a1, $a0, .L800746B8
    /* BEE0 800746E0 1000C624 */   addiu     $a2, $a2, 0x10
    /* BEE4 800746E4 0F80103C */  lui        $s0, %hi(vs_battle_cameraTransition)
    /* BEE8 800746E8 0419048E */  lw         $a0, %lo(vs_battle_cameraTransition)($s0)
    /* BEEC 800746EC 0000A78C */  lw         $a3, 0x0($a1)
    /* BEF0 800746F0 0400A88C */  lw         $t0, 0x4($a1)
    /* BEF4 800746F4 0800A98C */  lw         $t1, 0x8($a1)
    /* BEF8 800746F8 0000C7AC */  sw         $a3, 0x0($a2)
    /* BEFC 800746FC 0400C8AC */  sw         $t0, 0x4($a2)
    /* BF00 80074700 0800C9AC */  sw         $t1, 0x8($a2)
    /* BF04 80074704 6000828C */  lw         $v0, 0x60($a0)
    /* BF08 80074708 6400838C */  lw         $v1, 0x64($a0)
    /* BF0C 8007470C 6800868C */  lw         $a2, 0x68($a0)
    /* BF10 80074710 10008524 */  addiu      $a1, $a0, 0x10
    /* BF14 80074714 A00086AC */  sw         $a2, 0xA0($a0)
    /* BF18 80074718 6C008624 */  addiu      $a2, $a0, 0x6C
    /* BF1C 8007471C 980082AC */  sw         $v0, 0x98($a0)
    /* BF20 80074720 77EA010C */  jal        _computeSphericalOffset
    /* BF24 80074724 9C0083AC */   sw        $v1, 0x9C($a0)
    /* BF28 80074728 0419048E */  lw         $a0, %lo(vs_battle_cameraTransition)($s0)
    /* BF2C 8007472C D7BB010C */  jal        _computeCameraTransition
    /* BF30 80074730 00000000 */   nop
  .L80074734:
    /* BF34 80074734 2400BF8F */  lw         $ra, 0x24($sp)
    /* BF38 80074738 2000B08F */  lw         $s0, 0x20($sp)
    /* BF3C 8007473C 0800E003 */  jr         $ra
    /* BF40 80074740 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _checkFirstPersonViewExit
