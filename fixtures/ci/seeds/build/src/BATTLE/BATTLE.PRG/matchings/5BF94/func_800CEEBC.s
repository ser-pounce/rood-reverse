nonmatching func_800CEEBC, 0x50

glabel func_800CEEBC
    /* 666BC 800CEEBC 0F80023C */  lui        $v0, %hi(D_800F531C)
    /* 666C0 800CEEC0 1C53428C */  lw         $v0, %lo(D_800F531C)($v0)
    /* 666C4 800CEEC4 00000000 */  nop
    /* 666C8 800CEEC8 FCFF4224 */  addiu      $v0, $v0, -0x4
    /* 666CC 800CEECC 0200422C */  sltiu      $v0, $v0, 0x2
    /* 666D0 800CEED0 0C004010 */  beqz       $v0, .L800CEF04
    /* 666D4 800CEED4 21280000 */   addu      $a1, $zero, $zero
    /* 666D8 800CEED8 0F80023C */  lui        $v0, %hi(D_800F5224)
    /* 666DC 800CEEDC 0F80033C */  lui        $v1, %hi(D_800F5228)
    /* 666E0 800CEEE0 2452448C */  lw         $a0, %lo(D_800F5224)($v0)
    /* 666E4 800CEEE4 2852628C */  lw         $v0, %lo(D_800F5228)($v1)
    /* 666E8 800CEEE8 00000000 */  nop
    /* 666EC 800CEEEC 2A104400 */  slt        $v0, $v0, $a0
    /* 666F0 800CEEF0 04004010 */  beqz       $v0, .L800CEF04
    /* 666F4 800CEEF4 0F80023C */   lui       $v0, %hi(D_800F521C)
    /* 666F8 800CEEF8 1C52428C */  lw         $v0, %lo(D_800F521C)($v0)
    /* 666FC 800CEEFC 00000000 */  nop
    /* 66700 800CEF00 2B28A200 */  sltu       $a1, $a1, $v0
  .L800CEF04:
    /* 66704 800CEF04 0800E003 */  jr         $ra
    /* 66708 800CEF08 2110A000 */   addu      $v0, $a1, $zero
endlabel func_800CEEBC
