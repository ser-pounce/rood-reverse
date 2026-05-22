nonmatching SpuSetIRQAddr, 0x40

glabel SpuSetIRQAddr
    /* F254 8001EA54 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F258 8001EA58 21288000 */  addu       $a1, $a0, $zero
    /* F25C 8001EA5C 0700023C */  lui        $v0, (0x7FFF8 >> 16)
    /* F260 8001EA60 F8FF4234 */  ori        $v0, $v0, (0x7FFF8 & 0xFFFF)
    /* F264 8001EA64 2B104500 */  sltu       $v0, $v0, $a1
    /* F268 8001EA68 05004014 */  bnez       $v0, .L8001EA80
    /* F26C 8001EA6C 1000BFAF */   sw        $ra, 0x10($sp)
    /* F270 8001EA70 E978000C */  jal        _spu_FsetRXXa
    /* F274 8001EA74 D2000424 */   addiu     $a0, $zero, 0xD2
    /* F278 8001EA78 A17A0008 */  j          .L8001EA84
    /* F27C 8001EA7C 00000000 */   nop
  .L8001EA80:
    /* F280 8001EA80 21100000 */  addu       $v0, $zero, $zero
  .L8001EA84:
    /* F284 8001EA84 1000BF8F */  lw         $ra, 0x10($sp)
    /* F288 8001EA88 1800BD27 */  addiu      $sp, $sp, 0x18
    /* F28C 8001EA8C 0800E003 */  jr         $ra
    /* F290 8001EA90 00000000 */   nop
endlabel SpuSetIRQAddr
