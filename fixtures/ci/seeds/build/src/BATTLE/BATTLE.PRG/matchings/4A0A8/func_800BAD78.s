nonmatching func_800BAD78, 0x68

glabel func_800BAD78
    /* 52578 800BAD78 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 5257C 800BAD7C 2800B0AF */  sw         $s0, 0x28($sp)
    /* 52580 800BAD80 21808000 */  addu       $s0, $a0, $zero
    /* 52584 800BAD84 01000426 */  addiu      $a0, $s0, 0x1
    /* 52588 800BAD88 3000BFAF */  sw         $ra, 0x30($sp)
    /* 5258C 800BAD8C 80FF020C */  jal        vs_battle_getShort
    /* 52590 800BAD90 2C00B1AF */   sw        $s1, 0x2C($sp)
    /* 52594 800BAD94 FFFF4430 */  andi       $a0, $v0, 0xFFFF
    /* 52598 800BAD98 A3ED020C */  jal        func_800BB68C
    /* 5259C 800BAD9C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 525A0 800BADA0 01001124 */  addiu      $s1, $zero, 0x1
  .L800BADA4:
    /* 525A4 800BADA4 E2ED020C */  jal        func_800BB788
    /* 525A8 800BADA8 1000A427 */   addiu     $a0, $sp, 0x10
    /* 525AC 800BADAC FFFF4430 */  andi       $a0, $v0, 0xFFFF
    /* 525B0 800BADB0 06009110 */  beq        $a0, $s1, .L800BADCC
    /* 525B4 800BADB4 21100000 */   addu      $v0, $zero, $zero
    /* 525B8 800BADB8 03000592 */  lbu        $a1, 0x3($s0)
    /* 525BC 800BADBC 23F4010C */  jal        func_8007D08C
    /* 525C0 800BADC0 00000000 */   nop
    /* 525C4 800BADC4 69EB0208 */  j          .L800BADA4
    /* 525C8 800BADC8 00000000 */   nop
  .L800BADCC:
    /* 525CC 800BADCC 3000BF8F */  lw         $ra, 0x30($sp)
    /* 525D0 800BADD0 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 525D4 800BADD4 2800B08F */  lw         $s0, 0x28($sp)
    /* 525D8 800BADD8 0800E003 */  jr         $ra
    /* 525DC 800BADDC 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800BAD78
