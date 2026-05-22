nonmatching func_800D4778, 0x48

glabel func_800D4778
    /* 6BF78 800D4778 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 6BF7C 800D477C 3800B0AF */  sw         $s0, 0x38($sp)
    /* 6BF80 800D4780 21808000 */  addu       $s0, $a0, $zero
    /* 6BF84 800D4784 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 6BF88 800D4788 0C00028E */  lw         $v0, 0xC($s0)
    /* 6BF8C 800D478C 6654030C */  jal        func_800D5198
    /* 6BF90 800D4790 2400A2AF */   sw        $v0, 0x24($sp)
    /* 6BF94 800D4794 1000A427 */  addiu      $a0, $sp, 0x10
    /* 6BF98 800D4798 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 6BF9C 800D479C 1C0D1026 */  addiu      $s0, $s0, 0xD1C
    /* 6BFA0 800D47A0 2800A2AF */  sw         $v0, 0x28($sp)
    /* 6BFA4 800D47A4 0F3A030C */  jal        func_800CE83C
    /* 6BFA8 800D47A8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6BFAC 800D47AC 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 6BFB0 800D47B0 3800B08F */  lw         $s0, 0x38($sp)
    /* 6BFB4 800D47B4 01000224 */  addiu      $v0, $zero, 0x1
    /* 6BFB8 800D47B8 0800E003 */  jr         $ra
    /* 6BFBC 800D47BC 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800D4778
