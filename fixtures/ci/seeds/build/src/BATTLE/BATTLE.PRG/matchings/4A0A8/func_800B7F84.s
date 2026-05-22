nonmatching func_800B7F84, 0xC8

glabel func_800B7F84
    /* 4F784 800B7F84 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4F788 800B7F88 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 4F78C 800B7F8C 21888000 */  addu       $s1, $a0, $zero
    /* 4F790 800B7F90 01002426 */  addiu      $a0, $s1, 0x1
    /* 4F794 800B7F94 2000BFAF */  sw         $ra, 0x20($sp)
    /* 4F798 800B7F98 80FF020C */  jal        vs_battle_getShort
    /* 4F79C 800B7F9C 1800B0AF */   sw        $s0, 0x18($sp)
    /* 4F7A0 800B7FA0 94FF020C */  jal        func_800BFE50
    /* 4F7A4 800B7FA4 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F7A8 800B7FA8 FFFF063C */  lui        $a2, (0xFFFF00FF >> 16)
    /* 4F7AC 800B7FAC FF00C634 */  ori        $a2, $a2, (0xFFFF00FF & 0xFFFF)
    /* 4F7B0 800B7FB0 00FF073C */  lui        $a3, (0xFF00FFFF >> 16)
    /* 4F7B4 800B7FB4 00FF0524 */  addiu      $a1, $zero, -0x100
    /* 4F7B8 800B7FB8 FFFFE734 */  ori        $a3, $a3, (0xFF00FFFF & 0xFFFF)
    /* 4F7BC 800B7FBC FFFF5030 */  andi       $s0, $v0, 0xFFFF
    /* 4F7C0 800B7FC0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 4F7C4 800B7FC4 1000A38F */  lw         $v1, 0x10($sp)
    /* 4F7C8 800B7FC8 03002492 */  lbu        $a0, 0x3($s1)
    /* 4F7CC 800B7FCC 24186500 */  and        $v1, $v1, $a1
    /* 4F7D0 800B7FD0 25186400 */  or         $v1, $v1, $a0
    /* 4F7D4 800B7FD4 1000A3AF */  sw         $v1, 0x10($sp)
    /* 4F7D8 800B7FD8 24186600 */  and        $v1, $v1, $a2
    /* 4F7DC 800B7FDC 04002492 */  lbu        $a0, 0x4($s1)
    /* 4F7E0 800B7FE0 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 4F7E4 800B7FE4 00220400 */  sll        $a0, $a0, 8
    /* 4F7E8 800B7FE8 25186400 */  or         $v1, $v1, $a0
    /* 4F7EC 800B7FEC 1000A3AF */  sw         $v1, 0x10($sp)
    /* 4F7F0 800B7FF0 05002492 */  lbu        $a0, 0x5($s1)
    /* 4F7F4 800B7FF4 24186700 */  and        $v1, $v1, $a3
    /* 4F7F8 800B7FF8 00240400 */  sll        $a0, $a0, 16
    /* 4F7FC 800B7FFC 25186400 */  or         $v1, $v1, $a0
    /* 4F800 800B8000 1000A3AF */  sw         $v1, 0x10($sp)
    /* 4F804 800B8004 06002392 */  lbu        $v1, 0x6($s1)
    /* 4F808 800B8008 00000000 */  nop
    /* 4F80C 800B800C 02006210 */  beq        $v1, $v0, .L800B8018
    /* 4F810 800B8010 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4F814 800B8014 21306000 */  addu       $a2, $v1, $zero
  .L800B8018:
    /* 4F818 800B8018 37A7020C */  jal        func_800A9CDC
    /* 4F81C 800B801C 21200002 */   addu      $a0, $s0, $zero
    /* 4F820 800B8020 0F80023C */  lui        $v0, %hi(D_800F4B70)
    /* 4F824 800B8024 704B4224 */  addiu      $v0, $v0, %lo(D_800F4B70)
    /* 4F828 800B8028 21100202 */  addu       $v0, $s0, $v0
    /* 4F82C 800B802C 01000324 */  addiu      $v1, $zero, 0x1
    /* 4F830 800B8030 000043A0 */  sb         $v1, 0x0($v0)
    /* 4F834 800B8034 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4F838 800B8038 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 4F83C 800B803C 1800B08F */  lw         $s0, 0x18($sp)
    /* 4F840 800B8040 21100000 */  addu       $v0, $zero, $zero
    /* 4F844 800B8044 0800E003 */  jr         $ra
    /* 4F848 800B8048 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800B7F84
