nonmatching _getLocationId, 0x58

glabel _getLocationId
    /* 1401C 8007C81C 21180000 */  addu       $v1, $zero, $zero
    /* 14020 8007C820 01000724 */  addiu      $a3, $zero, 0x1
    /* 14024 8007C824 0580023C */  lui        $v0, %hi(vs_main_locationZoneMapIds)
    /* 14028 8007C828 CCF04824 */  addiu      $t0, $v0, %lo(vs_main_locationZoneMapIds)
    /* 1402C 8007C82C 21300001 */  addu       $a2, $t0, $zero
  .L8007C830:
    /* 14030 8007C830 0000C290 */  lbu        $v0, 0x0($a2)
    /* 14034 8007C834 00000000 */  nop
    /* 14038 8007C838 07008214 */  bne        $a0, $v0, .L8007C858
    /* 1403C 8007C83C 2110E800 */   addu      $v0, $a3, $t0
    /* 14040 8007C840 00004290 */  lbu        $v0, 0x0($v0)
    /* 14044 8007C844 00000000 */  nop
    /* 14048 8007C848 0400A214 */  bne        $a1, $v0, .L8007C85C
    /* 1404C 8007C84C 0200E724 */   addiu     $a3, $a3, 0x2
    /* 14050 8007C850 0800E003 */  jr         $ra
    /* 14054 8007C854 21106000 */   addu      $v0, $v1, $zero
  .L8007C858:
    /* 14058 8007C858 0200E724 */  addiu      $a3, $a3, 0x2
  .L8007C85C:
    /* 1405C 8007C85C 01006324 */  addiu      $v1, $v1, 0x1
    /* 14060 8007C860 00026228 */  slti       $v0, $v1, 0x200
    /* 14064 8007C864 F2FF4014 */  bnez       $v0, .L8007C830
    /* 14068 8007C868 0200C624 */   addiu     $a2, $a2, 0x2
    /* 1406C 8007C86C 0800E003 */  jr         $ra
    /* 14070 8007C870 21100000 */   addu      $v0, $zero, $zero
endlabel _getLocationId
