nonmatching func_800BBE94, 0x80

glabel func_800BBE94
    /* 53694 800BBE94 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 53698 800BBE98 2000B0AF */  sw         $s0, 0x20($sp)
    /* 5369C 800BBE9C 0F80103C */  lui        $s0, %hi(D_800F4BA4)
    /* 536A0 800BBEA0 A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 536A4 800BBEA4 2400BFAF */  sw         $ra, 0x24($sp)
    /* 536A8 800BBEA8 E8018394 */  lhu        $v1, 0x1E8($a0)
    /* 536AC 800BBEAC 00200224 */  addiu      $v0, $zero, 0x2000
    /* 536B0 800BBEB0 05006214 */  bne        $v1, $v0, .L800BBEC8
    /* 536B4 800BBEB4 00000000 */   nop
    /* 536B8 800BBEB8 F40180AC */  sw         $zero, 0x1F4($a0)
    /* 536BC 800BBEBC F00180AC */  sw         $zero, 0x1F0($a0)
    /* 536C0 800BBEC0 C1EF0208 */  j          .L800BBF04
    /* 536C4 800BBEC4 EC0180AC */   sw        $zero, 0x1EC($a0)
  .L800BBEC8:
    /* 536C8 800BBEC8 E8018494 */  lhu        $a0, 0x1E8($a0)
    /* 536CC 800BBECC 4284020C */  jal        func_800A1108
    /* 536D0 800BBED0 1000A527 */   addiu     $a1, $sp, 0x10
    /* 536D4 800BBED4 1400A287 */  lh         $v0, 0x14($sp)
    /* 536D8 800BBED8 A44B038E */  lw         $v1, %lo(D_800F4BA4)($s0)
    /* 536DC 800BBEDC 00130200 */  sll        $v0, $v0, 12
    /* 536E0 800BBEE0 EC0162AC */  sw         $v0, 0x1EC($v1)
    /* 536E4 800BBEE4 1600A287 */  lh         $v0, 0x16($sp)
    /* 536E8 800BBEE8 00000000 */  nop
    /* 536EC 800BBEEC 00130200 */  sll        $v0, $v0, 12
    /* 536F0 800BBEF0 F00162AC */  sw         $v0, 0x1F0($v1)
    /* 536F4 800BBEF4 1800A287 */  lh         $v0, 0x18($sp)
    /* 536F8 800BBEF8 00000000 */  nop
    /* 536FC 800BBEFC 00130200 */  sll        $v0, $v0, 12
    /* 53700 800BBF00 F40162AC */  sw         $v0, 0x1F4($v1)
  .L800BBF04:
    /* 53704 800BBF04 2400BF8F */  lw         $ra, 0x24($sp)
    /* 53708 800BBF08 2000B08F */  lw         $s0, 0x20($sp)
    /* 5370C 800BBF0C 0800E003 */  jr         $ra
    /* 53710 800BBF10 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800BBE94
