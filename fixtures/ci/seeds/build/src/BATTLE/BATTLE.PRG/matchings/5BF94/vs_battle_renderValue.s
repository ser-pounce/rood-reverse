nonmatching vs_battle_renderValue, 0x8C

glabel vs_battle_renderValue
    /* 61150 800C9950 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 61154 800C9954 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 61158 800C9958 21988000 */  addu       $s3, $a0, $zero
    /* 6115C 800C995C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 61160 800C9960 2188A000 */  addu       $s1, $a1, $zero
    /* 61164 800C9964 1000B0AF */  sw         $s0, 0x10($sp)
    /* 61168 800C9968 2180C000 */  addu       $s0, $a2, $zero
    /* 6116C 800C996C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 61170 800C9970 2190E000 */  addu       $s2, $a3, $zero
    /* 61174 800C9974 05004016 */  bnez       $s2, .L800C998C
    /* 61178 800C9978 2000BFAF */   sw        $ra, 0x20($sp)
    /* 6117C 800C997C 801F023C */  lui        $v0, (0x1F800004 >> 16)
    /* 61180 800C9980 0400428C */  lw         $v0, (0x1F800004 & 0xFFFF)($v0)
    /* 61184 800C9984 00000000 */  nop
    /* 61188 800C9988 F0FF5224 */  addiu      $s2, $v0, -0x10
  .L800C998C:
    /* 6118C 800C998C 1533030C */  jal        vs_battle_toBCD
    /* 61190 800C9990 21200002 */   addu      $a0, $s0, $zero
    /* 61194 800C9994 21804000 */  addu       $s0, $v0, $zero
    /* 61198 800C9998 21206002 */  addu       $a0, $s3, $zero
    /* 6119C 800C999C 21282002 */  addu       $a1, $s1, $zero
    /* 611A0 800C99A0 0F000632 */  andi       $a2, $s0, 0xF
    /* 611A4 800C99A4 3026030C */  jal        _renderDigit
    /* 611A8 800C99A8 21384002 */   addu      $a3, $s2, $zero
    /* 611AC 800C99AC FBFF2226 */  addiu      $v0, $s1, -0x5
    /* 611B0 800C99B0 03811000 */  sra        $s0, $s0, 4
    /* 611B4 800C99B4 F5FF0016 */  bnez       $s0, .L800C998C
    /* 611B8 800C99B8 23885300 */   subu      $s1, $v0, $s3
    /* 611BC 800C99BC 21102002 */  addu       $v0, $s1, $zero
    /* 611C0 800C99C0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 611C4 800C99C4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 611C8 800C99C8 1800B28F */  lw         $s2, 0x18($sp)
    /* 611CC 800C99CC 1400B18F */  lw         $s1, 0x14($sp)
    /* 611D0 800C99D0 1000B08F */  lw         $s0, 0x10($sp)
    /* 611D4 800C99D4 0800E003 */  jr         $ra
    /* 611D8 800C99D8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_battle_renderValue
