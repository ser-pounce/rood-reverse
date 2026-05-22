nonmatching func_800B810C, 0x94

glabel func_800B810C
    /* 4F90C 800B810C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4F910 800B8110 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4F914 800B8114 21808000 */  addu       $s0, $a0, $zero
    /* 4F918 800B8118 01000426 */  addiu      $a0, $s0, 0x1
    /* 4F91C 800B811C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 4F920 800B8120 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 4F924 800B8124 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4F928 800B8128 80FF020C */  jal        vs_battle_getShort
    /* 4F92C 800B812C 1400B1AF */   sw        $s1, 0x14($sp)
    /* 4F930 800B8130 94FF020C */  jal        func_800BFE50
    /* 4F934 800B8134 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F938 800B8138 FFFF5230 */  andi       $s2, $v0, 0xFFFF
    /* 4F93C 800B813C F882020C */  jal        func_800A0BE0
    /* 4F940 800B8140 21204002 */   addu      $a0, $s2, $zero
    /* 4F944 800B8144 81005338 */  xori       $s3, $v0, 0x81
    /* 4F948 800B8148 21886002 */  addu       $s1, $s3, $zero
    /* 4F94C 800B814C 80FF020C */  jal        vs_battle_getShort
    /* 4F950 800B8150 03000426 */   addiu     $a0, $s0, 0x3
    /* 4F954 800B8154 21804000 */  addu       $s0, $v0, $zero
    /* 4F958 800B8158 01000232 */  andi       $v0, $s0, 0x1
    /* 4F95C 800B815C 07004010 */  beqz       $v0, .L800B817C
    /* 4F960 800B8160 24103002 */   and       $v0, $s1, $s0
    /* 4F964 800B8164 0FF4010C */  jal        func_8007D03C
    /* 4F968 800B8168 21204002 */   addu      $a0, $s2, $zero
    /* 4F96C 800B816C 03004014 */  bnez       $v0, .L800B817C
    /* 4F970 800B8170 24103002 */   and       $v0, $s1, $s0
    /* 4F974 800B8174 01007136 */  ori        $s1, $s3, 0x1
    /* 4F978 800B8178 24103002 */  and        $v0, $s1, $s0
  .L800B817C:
    /* 4F97C 800B817C FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 4F980 800B8180 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4F984 800B8184 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4F988 800B8188 1800B28F */  lw         $s2, 0x18($sp)
    /* 4F98C 800B818C 1400B18F */  lw         $s1, 0x14($sp)
    /* 4F990 800B8190 1000B08F */  lw         $s0, 0x10($sp)
    /* 4F994 800B8194 2B100200 */  sltu       $v0, $zero, $v0
    /* 4F998 800B8198 0800E003 */  jr         $ra
    /* 4F99C 800B819C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800B810C
