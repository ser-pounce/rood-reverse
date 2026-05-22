nonmatching func_8007C928, 0xF8

glabel func_8007C928
    /* 14128 8007C928 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 1412C 8007C92C 3800B2AF */  sw         $s2, 0x38($sp)
    /* 14130 8007C930 21908000 */  addu       $s2, $a0, $zero
    /* 14134 8007C934 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 14138 8007C938 2198A000 */  addu       $s3, $a1, $zero
    /* 1413C 8007C93C 4000B4AF */  sw         $s4, 0x40($sp)
    /* 14140 8007C940 21A0C000 */  addu       $s4, $a2, $zero
    /* 14144 8007C944 1000422E */  sltiu      $v0, $s2, 0x10
    /* 14148 8007C948 4400BFAF */  sw         $ra, 0x44($sp)
    /* 1414C 8007C94C 3400B1AF */  sw         $s1, 0x34($sp)
    /* 14150 8007C950 2A004010 */  beqz       $v0, .L8007C9FC
    /* 14154 8007C954 3000B0AF */   sw        $s0, 0x30($sp)
    /* 14158 8007C958 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 1415C 8007C95C 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 14160 8007C960 80181200 */  sll        $v1, $s2, 2
    /* 14164 8007C964 21886200 */  addu       $s1, $v1, $v0
    /* 14168 8007C968 0000228E */  lw         $v0, 0x0($s1)
    /* 1416C 8007C96C 00000000 */  nop
    /* 14170 8007C970 22004014 */  bnez       $v0, .L8007C9FC
    /* 14174 8007C974 00000000 */   nop
    /* 14178 8007C978 B10F010C */  jal        vs_main_allocHeap
    /* 1417C 8007C97C 842E0424 */   addiu     $a0, $zero, 0x2E84
    /* 14180 8007C980 21204002 */  addu       $a0, $s2, $zero
    /* 14184 8007C984 21286002 */  addu       $a1, $s3, $zero
    /* 14188 8007C988 21300000 */  addu       $a2, $zero, $zero
    /* 1418C 8007C98C 2138C000 */  addu       $a3, $a2, $zero
    /* 14190 8007C990 21804000 */  addu       $s0, $v0, $zero
    /* 14194 8007C994 50000226 */  addiu      $v0, $s0, 0x50
    /* 14198 8007C998 000030AE */  sw         $s0, 0x0($s1)
    /* 1419C 8007C99C 3C0002AE */  sw         $v0, 0x3C($s0)
    /* 141A0 8007C9A0 01000224 */  addiu      $v0, $zero, 0x1
    /* 141A4 8007C9A4 400002AE */  sw         $v0, 0x40($s0)
    /* 141A8 8007C9A8 B4090226 */  addiu      $v0, $s0, 0x9B4
    /* 141AC 8007C9AC 440002AE */  sw         $v0, 0x44($s0)
    /* 141B0 8007C9B0 B4220226 */  addiu      $v0, $s0, 0x22B4
    /* 141B4 8007C9B4 480002AE */  sw         $v0, 0x48($s0)
    /* 141B8 8007C9B8 9C280226 */  addiu      $v0, $s0, 0x289C
    /* 141BC 8007C9BC 4C0002AE */  sw         $v0, 0x4C($s0)
    /* 141C0 8007C9C0 06000224 */  addiu      $v0, $zero, 0x6
    /* 141C4 8007C9C4 54DB010C */  jal        func_80076D50
    /* 141C8 8007C9C8 1000A2AF */   sw        $v0, 0x10($sp)
    /* 141CC 8007C9CC 21200002 */  addu       $a0, $s0, $zero
    /* 141D0 8007C9D0 21284002 */  addu       $a1, $s2, $zero
    /* 141D4 8007C9D4 21306002 */  addu       $a2, $s3, $zero
    /* 141D8 8007C9D8 21388002 */  addu       $a3, $s4, $zero
    /* 141DC 8007C9DC 1EDC010C */  jal        func_80077078
    /* 141E0 8007C9E0 1000A0AF */   sw        $zero, 0x10($sp)
    /* 141E4 8007C9E4 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 141E8 8007C9E8 0000248E */  lw         $a0, 0x0($s1)
    /* 141EC 8007C9EC 5E98030C */  jal        func_800E6178
    /* 141F0 8007C9F0 21804000 */   addu      $s0, $v0, $zero
    /* 141F4 8007C9F4 80F20108 */  j          .L8007CA00
    /* 141F8 8007C9F8 01000226 */   addiu     $v0, $s0, 0x1
  .L8007C9FC:
    /* 141FC 8007C9FC 21100000 */  addu       $v0, $zero, $zero
  .L8007CA00:
    /* 14200 8007CA00 4400BF8F */  lw         $ra, 0x44($sp)
    /* 14204 8007CA04 4000B48F */  lw         $s4, 0x40($sp)
    /* 14208 8007CA08 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 1420C 8007CA0C 3800B28F */  lw         $s2, 0x38($sp)
    /* 14210 8007CA10 3400B18F */  lw         $s1, 0x34($sp)
    /* 14214 8007CA14 3000B08F */  lw         $s0, 0x30($sp)
    /* 14218 8007CA18 0800E003 */  jr         $ra
    /* 1421C 8007CA1C 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8007C928
