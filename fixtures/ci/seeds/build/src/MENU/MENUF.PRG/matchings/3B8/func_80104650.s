nonmatching func_80104650, 0xA8

glabel func_80104650
    /* 1E50 80104650 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1E54 80104654 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1E58 80104658 21908000 */  addu       $s2, $a0, $zero
    /* 1E5C 8010465C 2400B3AF */  sw         $s3, 0x24($sp)
    /* 1E60 80104660 2198A000 */  addu       $s3, $a1, $zero
    /* 1E64 80104664 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1E68 80104668 2188C000 */  addu       $s1, $a2, $zero
    /* 1E6C 8010466C 4100222A */  slti       $v0, $s1, 0x41
    /* 1E70 80104670 2800BFAF */  sw         $ra, 0x28($sp)
    /* 1E74 80104674 02004014 */  bnez       $v0, .L80104680
    /* 1E78 80104678 1800B0AF */   sw        $s0, 0x18($sp)
    /* 1E7C 8010467C 40001124 */  addiu      $s1, $zero, 0x40
  .L80104680:
    /* 1E80 80104680 1600201A */  blez       $s1, .L801046DC
    /* 1E84 80104684 21286002 */   addu      $a1, $s3, $zero
    /* 1E88 80104688 54000624 */  addiu      $a2, $zero, 0x54
    /* 1E8C 8010468C 1180103C */  lui        $s0, %hi(D_801091D8)
    /* 1E90 80104690 D8911026 */  addiu      $s0, $s0, %lo(D_801091D8)
    /* 1E94 80104694 A2020292 */  lbu        $v0, 0x2A2($s0)
    /* 1E98 80104698 21382002 */  addu       $a3, $s1, $zero
    /* 1E9C 8010469C 18004224 */  addiu      $v0, $v0, 0x18
    /* 1EA0 801046A0 43100200 */  sra        $v0, $v0, 1
    /* 1EA4 801046A4 23904202 */  subu       $s2, $s2, $v0
    /* 1EA8 801046A8 0D17040C */  jal        func_80105C34
    /* 1EAC 801046AC 21204002 */   addu      $a0, $s2, $zero
    /* 1EB0 801046B0 FFFF6526 */  addiu      $a1, $s3, -0x1
    /* 1EB4 801046B4 21382002 */  addu       $a3, $s1, $zero
    /* 1EB8 801046B8 F47F0224 */  addiu      $v0, $zero, 0x7FF4
    /* 1EBC 801046BC 0C004326 */  addiu      $v1, $s2, 0xC
    /* 1EC0 801046C0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1EC4 801046C4 0680023C */  lui        $v0, %hi(vs_main_stateFlags + 0xC4)
    /* 1EC8 801046C8 A2020492 */  lbu        $a0, 0x2A2($s0)
    /* 1ECC 801046CC 5C164690 */  lbu        $a2, %lo(vs_main_stateFlags + 0xC4)($v0)
    /* 1ED0 801046D0 21206400 */  addu       $a0, $v1, $a0
    /* 1ED4 801046D4 7617040C */  jal        func_80105DD8
    /* 1ED8 801046D8 0100C624 */   addiu     $a2, $a2, 0x1
  .L801046DC:
    /* 1EDC 801046DC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1EE0 801046E0 2400B38F */  lw         $s3, 0x24($sp)
    /* 1EE4 801046E4 2000B28F */  lw         $s2, 0x20($sp)
    /* 1EE8 801046E8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1EEC 801046EC 1800B08F */  lw         $s0, 0x18($sp)
    /* 1EF0 801046F0 0800E003 */  jr         $ra
    /* 1EF4 801046F4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80104650
