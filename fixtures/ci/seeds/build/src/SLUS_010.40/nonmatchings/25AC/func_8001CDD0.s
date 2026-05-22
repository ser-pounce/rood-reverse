nonmatching func_8001CDD0, 0x90

glabel func_8001CDD0
    /* D5D0 8001CDD0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* D5D4 8001CDD4 1400B1AF */  sw         $s1, 0x14($sp)
    /* D5D8 8001CDD8 0380113C */  lui        $s1, %hi(g_Sound_VoiceSchedulerState)
    /* D5DC 8001CDDC 1800B2AF */  sw         $s2, 0x18($sp)
    /* D5E0 8001CDE0 90783226 */  addiu      $s2, $s1, %lo(g_Sound_VoiceSchedulerState)
    /* D5E4 8001CDE4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* D5E8 8001CDE8 1000B0AF */  sw         $s0, 0x10($sp)
    /* D5EC 8001CDEC C000053C */  lui        $a1, (0xC00000 >> 16)
  .L8001CDF0:
    /* D5F0 8001CDF0 9078238E */  lw         $v1, %lo(g_Sound_VoiceSchedulerState)($s1)
    /* D5F4 8001CDF4 1000428E */  lw         $v0, 0x10($s2)
    /* D5F8 8001CDF8 0C000424 */  addiu      $a0, $zero, 0xC
    /* D5FC 8001CDFC 25806200 */  or         $s0, $v1, $v0
  .L8001CE00:
    /* D600 8001CE00 24100502 */  and        $v0, $s0, $a1
    /* D604 8001CE04 04004010 */  beqz       $v0, .L8001CE18
    /* D608 8001CE08 00000000 */   nop
    /* D60C 8001CE0C FEFF8424 */  addiu      $a0, $a0, -0x2
    /* D610 8001CE10 FBFF8014 */  bnez       $a0, .L8001CE00
    /* D614 8001CE14 82280500 */   srl       $a1, $a1, 2
  .L8001CE18:
    /* D618 8001CE18 0B008014 */  bnez       $a0, .L8001CE48
    /* D61C 8001CE1C 0A008224 */   addiu     $v0, $a0, 0xA
    /* D620 8001CE20 21200000 */  addu       $a0, $zero, $zero
    /* D624 8001CE24 7158000C */  jal        func_800161C4
    /* D628 8001CE28 0040053C */   lui       $a1, (0x40000000 >> 16)
    /* D62C 8001CE2C 9078228E */  lw         $v0, %lo(g_Sound_VoiceSchedulerState)($s1)
    /* D630 8001CE30 1000438E */  lw         $v1, 0x10($s2)
    /* D634 8001CE34 00000000 */  nop
    /* D638 8001CE38 25104300 */  or         $v0, $v0, $v1
    /* D63C 8001CE3C ECFF0216 */  bne        $s0, $v0, .L8001CDF0
    /* D640 8001CE40 C000053C */   lui       $a1, (0xC00000 >> 16)
    /* D644 8001CE44 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8001CE48:
    /* D648 8001CE48 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* D64C 8001CE4C 1800B28F */  lw         $s2, 0x18($sp)
    /* D650 8001CE50 1400B18F */  lw         $s1, 0x14($sp)
    /* D654 8001CE54 1000B08F */  lw         $s0, 0x10($sp)
    /* D658 8001CE58 0800E003 */  jr         $ra
    /* D65C 8001CE5C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001CDD0
