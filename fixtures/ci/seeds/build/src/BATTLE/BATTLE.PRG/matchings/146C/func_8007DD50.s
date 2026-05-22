nonmatching func_8007DD50, 0x5C

glabel func_8007DD50
    /* 15550 8007DD50 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 15554 8007DD54 1400BFAF */  sw         $ra, 0x14($sp)
    /* 15558 8007DD58 0D008010 */  beqz       $a0, .L8007DD90
    /* 1555C 8007DD5C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 15560 8007DD60 0F80043C */  lui        $a0, %hi(D_800F1B98)
    /* 15564 8007DD64 0F80103C */  lui        $s0, %hi(D_800F1ABC)
    /* 15568 8007DD68 BC1A038E */  lw         $v1, %lo(D_800F1ABC)($s0)
    /* 1556C 8007DD6C 01000224 */  addiu      $v0, $zero, 0x1
    /* 15570 8007DD70 0A006014 */  bnez       $v1, .L8007DD9C
    /* 15574 8007DD74 981B82AC */   sw        $v0, %lo(D_800F1B98)($a0)
    /* 15578 8007DD78 8F0F010C */  jal        vs_main_allocHeapR
    /* 1557C 8007DD7C D0020424 */   addiu     $a0, $zero, 0x2D0
    /* 15580 8007DD80 07F5010C */  jal        func_8007D41C
    /* 15584 8007DD84 BC1A02AE */   sw        $v0, %lo(D_800F1ABC)($s0)
    /* 15588 8007DD88 67F70108 */  j          .L8007DD9C
    /* 1558C 8007DD8C 00000000 */   nop
  .L8007DD90:
    /* 15590 8007DD90 0F80033C */  lui        $v1, %hi(D_800F1B98)
    /* 15594 8007DD94 03000224 */  addiu      $v0, $zero, 0x3
    /* 15598 8007DD98 981B62AC */  sw         $v0, %lo(D_800F1B98)($v1)
  .L8007DD9C:
    /* 1559C 8007DD9C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 155A0 8007DDA0 1000B08F */  lw         $s0, 0x10($sp)
    /* 155A4 8007DDA4 0800E003 */  jr         $ra
    /* 155A8 8007DDA8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007DD50
