nonmatching func_8007BF6C, 0x54

glabel func_8007BF6C
    /* 1376C 8007BF6C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13770 8007BF70 1000B0AF */  sw         $s0, 0x10($sp)
    /* 13774 8007BF74 21808000 */  addu       $s0, $a0, $zero
    /* 13778 8007BF78 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 1377C 8007BF7C 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 13780 8007BF80 80181000 */  sll        $v1, $s0, 2
    /* 13784 8007BF84 21186200 */  addu       $v1, $v1, $v0
    /* 13788 8007BF88 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1378C 8007BF8C 0000628C */  lw         $v0, 0x0($v1)
    /* 13790 8007BF90 00000000 */  nop
    /* 13794 8007BF94 06004010 */  beqz       $v0, .L8007BFB0
    /* 13798 8007BF98 00000000 */   nop
    /* 1379C 8007BF9C F882020C */  jal        func_800A0BE0
    /* 137A0 8007BFA0 00000000 */   nop
    /* 137A4 8007BFA4 21200002 */  addu       $a0, $s0, $zero
    /* 137A8 8007BFA8 1F82020C */  jal        func_800A087C
    /* 137AC 8007BFAC 01004534 */   ori       $a1, $v0, 0x1
  .L8007BFB0:
    /* 137B0 8007BFB0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 137B4 8007BFB4 1000B08F */  lw         $s0, 0x10($sp)
    /* 137B8 8007BFB8 0800E003 */  jr         $ra
    /* 137BC 8007BFBC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BF6C
