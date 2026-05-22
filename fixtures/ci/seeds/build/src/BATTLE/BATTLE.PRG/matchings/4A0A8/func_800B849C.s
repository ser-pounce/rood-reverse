nonmatching func_800B849C, 0x74

glabel func_800B849C
    /* 4FC9C 800B849C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4FCA0 800B84A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4FCA4 800B84A4 21808000 */  addu       $s0, $a0, $zero
    /* 4FCA8 800B84A8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4FCAC 800B84AC 80FF020C */  jal        vs_battle_getShort
    /* 4FCB0 800B84B0 01000426 */   addiu     $a0, $s0, 0x1
    /* 4FCB4 800B84B4 94FF020C */  jal        func_800BFE50
    /* 4FCB8 800B84B8 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4FCBC 800B84BC 21204000 */  addu       $a0, $v0, $zero
    /* 4FCC0 800B84C0 04000392 */  lbu        $v1, 0x4($s0)
    /* 4FCC4 800B84C4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 4FCC8 800B84C8 03006214 */  bne        $v1, $v0, .L800B84D8
    /* 4FCCC 800B84CC 0F80023C */   lui       $v0, %hi(D_800E9B58)
    /* 4FCD0 800B84D0 3DE10208 */  j          .L800B84F4
    /* 4FCD4 800B84D4 FFFF0524 */   addiu     $a1, $zero, -0x1
  .L800B84D8:
    /* 4FCD8 800B84D8 589B4224 */  addiu      $v0, $v0, %lo(D_800E9B58)
    /* 4FCDC 800B84DC 03000392 */  lbu        $v1, 0x3($s0)
    /* 4FCE0 800B84E0 04000592 */  lbu        $a1, 0x4($s0)
    /* 4FCE4 800B84E4 21186200 */  addu       $v1, $v1, $v0
    /* 4FCE8 800B84E8 00006290 */  lbu        $v0, 0x0($v1)
    /* 4FCEC 800B84EC 00000000 */  nop
    /* 4FCF0 800B84F0 21284500 */  addu       $a1, $v0, $a1
  .L800B84F4:
    /* 4FCF4 800B84F4 F67E020C */  jal        func_8009FBD8
    /* 4FCF8 800B84F8 00000000 */   nop
    /* 4FCFC 800B84FC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4FD00 800B8500 1000B08F */  lw         $s0, 0x10($sp)
    /* 4FD04 800B8504 21100000 */  addu       $v0, $zero, $zero
    /* 4FD08 800B8508 0800E003 */  jr         $ra
    /* 4FD0C 800B850C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B849C
