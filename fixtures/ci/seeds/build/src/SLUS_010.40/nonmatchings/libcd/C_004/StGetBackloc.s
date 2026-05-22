nonmatching StGetBackloc, 0x58

glabel StGetBackloc
    /* 12AA0 800222A0 0480023C */  lui        $v0, %hi(D_80039C80)
    /* 12AA4 800222A4 809C428C */  lw         $v0, %lo(D_80039C80)($v0)
    /* 12AA8 800222A8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12AAC 800222AC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 12AB0 800222B0 21808000 */  addu       $s0, $a0, $zero
    /* 12AB4 800222B4 0B004014 */  bnez       $v0, .L800222E4
    /* 12AB8 800222B8 1400BFAF */   sw        $ra, 0x14($sp)
    /* 12ABC 800222BC 0480043C */  lui        $a0, %hi(D_80039C88)
    /* 12AC0 800222C0 568C000C */  jal        CdPosToInt
    /* 12AC4 800222C4 889C8424 */   addiu     $a0, $a0, %lo(D_80039C88)
    /* 12AC8 800222C8 01004424 */  addiu      $a0, $v0, 0x1
    /* 12ACC 800222CC 158C000C */  jal        CdIntToPos
    /* 12AD0 800222D0 21280002 */   addu      $a1, $s0, $zero
    /* 12AD4 800222D4 0480023C */  lui        $v0, %hi(D_80039C8C)
    /* 12AD8 800222D8 8C9C428C */  lw         $v0, %lo(D_80039C8C)($v0)
    /* 12ADC 800222DC BA880008 */  j          .L800222E8
    /* 12AE0 800222E0 00000000 */   nop
  .L800222E4:
    /* 12AE4 800222E4 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L800222E8:
    /* 12AE8 800222E8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 12AEC 800222EC 1000B08F */  lw         $s0, 0x10($sp)
    /* 12AF0 800222F0 0800E003 */  jr         $ra
    /* 12AF4 800222F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel StGetBackloc
    /* 12AF8 800222F8 00000000 */  nop
    /* 12AFC 800222FC 00000000 */  nop
    /* 12B00 80022300 00000000 */  nop
