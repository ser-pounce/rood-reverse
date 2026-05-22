nonmatching func_800B884C, 0x88

glabel func_800B884C
    /* 5004C 800B884C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 50050 800B8850 2800B0AF */  sw         $s0, 0x28($sp)
    /* 50054 800B8854 21808000 */  addu       $s0, $a0, $zero
    /* 50058 800B8858 01000426 */  addiu      $a0, $s0, 0x1
    /* 5005C 800B885C 3400BFAF */  sw         $ra, 0x34($sp)
    /* 50060 800B8860 3000B2AF */  sw         $s2, 0x30($sp)
    /* 50064 800B8864 80FF020C */  jal        vs_battle_getShort
    /* 50068 800B8868 2C00B1AF */   sw        $s1, 0x2C($sp)
    /* 5006C 800B886C FFFF4430 */  andi       $a0, $v0, 0xFFFF
    /* 50070 800B8870 A3ED020C */  jal        func_800BB68C
    /* 50074 800B8874 1000A527 */   addiu     $a1, $sp, 0x10
    /* 50078 800B8878 01001224 */  addiu      $s2, $zero, 0x1
    /* 5007C 800B887C 0F80023C */  lui        $v0, %hi(D_800E9B4C)
    /* 50080 800B8880 4C9B5124 */  addiu      $s1, $v0, %lo(D_800E9B4C)
  .L800B8884:
    /* 50084 800B8884 E2ED020C */  jal        func_800BB788
    /* 50088 800B8888 1000A427 */   addiu     $a0, $sp, 0x10
    /* 5008C 800B888C FFFF4430 */  andi       $a0, $v0, 0xFFFF
    /* 50090 800B8890 0A009210 */  beq        $a0, $s2, .L800B88BC
    /* 50094 800B8894 21100000 */   addu      $v0, $zero, $zero
    /* 50098 800B8898 03000292 */  lbu        $v0, 0x3($s0)
    /* 5009C 800B889C 00000000 */  nop
    /* 500A0 800B88A0 80100200 */  sll        $v0, $v0, 2
    /* 500A4 800B88A4 21105100 */  addu       $v0, $v0, $s1
    /* 500A8 800B88A8 0000458C */  lw         $a1, 0x0($v0)
    /* 500AC 800B88AC 2BF0010C */  jal        func_8007C0AC
    /* 500B0 800B88B0 00000000 */   nop
    /* 500B4 800B88B4 21E20208 */  j          .L800B8884
    /* 500B8 800B88B8 00000000 */   nop
  .L800B88BC:
    /* 500BC 800B88BC 3400BF8F */  lw         $ra, 0x34($sp)
    /* 500C0 800B88C0 3000B28F */  lw         $s2, 0x30($sp)
    /* 500C4 800B88C4 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 500C8 800B88C8 2800B08F */  lw         $s0, 0x28($sp)
    /* 500CC 800B88CC 0800E003 */  jr         $ra
    /* 500D0 800B88D0 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800B884C
