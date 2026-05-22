nonmatching _sortWeaponsByStat, 0x180

glabel _sortWeaponsByStat
    /* 29F8 801051F8 E8FDBD27 */  addiu      $sp, $sp, -0x218
    /* 29FC 801051FC 1802A4AF */  sw         $a0, 0x218($sp)
    /* 2A00 80105200 21200000 */  addu       $a0, $zero, $zero
    /* 2A04 80105204 0402B5AF */  sw         $s5, 0x204($sp)
    /* 2A08 80105208 21A88000 */  addu       $s5, $a0, $zero
    /* 2A0C 8010520C 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 2A10 80105210 1002BEAF */  sw         $fp, 0x210($sp)
    /* 2A14 80105214 21F04000 */  addu       $fp, $v0, $zero
    /* 2A18 80105218 0802B6AF */  sw         $s6, 0x208($sp)
    /* 2A1C 8010521C 8C9AD68F */  lw         $s6, %lo(vs_menuD_containerData)($fp)
    /* 2A20 80105220 A801A227 */  addiu      $v0, $sp, 0x1A8
    /* 2A24 80105224 1402BFAF */  sw         $ra, 0x214($sp)
    /* 2A28 80105228 0C02B7AF */  sw         $s7, 0x20C($sp)
    /* 2A2C 8010522C 0002B4AF */  sw         $s4, 0x200($sp)
    /* 2A30 80105230 FC01B3AF */  sw         $s3, 0x1FC($sp)
    /* 2A34 80105234 F801B2AF */  sw         $s2, 0x1F8($sp)
    /* 2A38 80105238 F401B1AF */  sw         $s1, 0x1F4($sp)
    /* 2A3C 8010523C F001B0AF */  sw         $s0, 0x1F0($sp)
    /* 2A40 80105240 E801A2AF */  sw         $v0, 0x1E8($sp)
    /* 2A44 80105244 250B040C */  jal        _getContainerIndicesOffset
    /* 2A48 80105248 2128C002 */   addu      $a1, $s6, $zero
    /* 2A4C 8010524C 40000524 */  addiu      $a1, $zero, 0x40
    /* 2A50 80105250 E801A48F */  lw         $a0, 0x1E8($sp)
    /* 2A54 80105254 0733030C */  jal        vs_battle_rMemzero
    /* 2A58 80105258 21B84000 */   addu      $s7, $v0, $zero
    /* 2A5C 8010525C 0080143C */  lui        $s4, (0x80000000 >> 16)
  .L80105260:
    /* 2A60 80105260 21880000 */  addu       $s1, $zero, $zero
    /* 2A64 80105264 2190E002 */  addu       $s2, $s7, $zero
  .L80105268:
    /* 2A68 80105268 00005096 */  lhu        $s0, 0x0($s2)
    /* 2A6C 8010526C 00000000 */  nop
    /* 2A70 80105270 0E000012 */  beqz       $s0, .L801052AC
    /* 2A74 80105274 1000A427 */   addiu     $a0, $sp, 0x10
    /* 2A78 80105278 40291000 */  sll        $a1, $s0, 5
    /* 2A7C 8010527C E0FFA524 */  addiu      $a1, $a1, -0x20
    /* 2A80 80105280 8C9AC68F */  lw         $a2, %lo(vs_menuD_containerData)($fp)
    /* 2A84 80105284 8D0A040C */  jal        vs_menuD_initUiWeapon
    /* 2A88 80105288 2128C502 */   addu      $a1, $s6, $a1
    /* 2A8C 8010528C 1802A48F */  lw         $a0, 0x218($sp)
    /* 2A90 80105290 4514040C */  jal        _getWeaponStat
    /* 2A94 80105294 1000A527 */   addiu     $a1, $sp, 0x10
    /* 2A98 80105298 21184000 */  addu       $v1, $v0, $zero
    /* 2A9C 8010529C 2A108302 */  slt        $v0, $s4, $v1
    /* 2AA0 801052A0 02004010 */  beqz       $v0, .L801052AC
    /* 2AA4 801052A4 00000000 */   nop
    /* 2AA8 801052A8 21A06000 */  addu       $s4, $v1, $zero
  .L801052AC:
    /* 2AAC 801052AC 01003126 */  addiu      $s1, $s1, 0x1
    /* 2AB0 801052B0 2000222A */  slti       $v0, $s1, 0x20
    /* 2AB4 801052B4 ECFF4014 */  bnez       $v0, .L80105268
    /* 2AB8 801052B8 02005226 */   addiu     $s2, $s2, 0x2
    /* 2ABC 801052BC 0080023C */  lui        $v0, (0x80000000 >> 16)
    /* 2AC0 801052C0 1D008212 */  beq        $s4, $v0, .L80105338
    /* 2AC4 801052C4 21880000 */   addu      $s1, $zero, $zero
    /* 2AC8 801052C8 2190E002 */  addu       $s2, $s7, $zero
    /* 2ACC 801052CC E801A78F */  lw         $a3, 0x1E8($sp)
    /* 2AD0 801052D0 40101500 */  sll        $v0, $s5, 1
    /* 2AD4 801052D4 21984700 */  addu       $s3, $v0, $a3
  .L801052D8:
    /* 2AD8 801052D8 00005096 */  lhu        $s0, 0x0($s2)
    /* 2ADC 801052DC 00000000 */  nop
    /* 2AE0 801052E0 0F000012 */  beqz       $s0, .L80105320
    /* 2AE4 801052E4 1000A427 */   addiu     $a0, $sp, 0x10
    /* 2AE8 801052E8 40291000 */  sll        $a1, $s0, 5
    /* 2AEC 801052EC E0FFA524 */  addiu      $a1, $a1, -0x20
    /* 2AF0 801052F0 8C9AC68F */  lw         $a2, %lo(vs_menuD_containerData)($fp)
    /* 2AF4 801052F4 8D0A040C */  jal        vs_menuD_initUiWeapon
    /* 2AF8 801052F8 2128C502 */   addu      $a1, $s6, $a1
    /* 2AFC 801052FC 1802A48F */  lw         $a0, 0x218($sp)
    /* 2B00 80105300 4514040C */  jal        _getWeaponStat
    /* 2B04 80105304 1000A527 */   addiu     $a1, $sp, 0x10
    /* 2B08 80105308 05005414 */  bne        $v0, $s4, .L80105320
    /* 2B0C 8010530C 00000000 */   nop
    /* 2B10 80105310 000070A6 */  sh         $s0, 0x0($s3)
    /* 2B14 80105314 02007326 */  addiu      $s3, $s3, 0x2
    /* 2B18 80105318 0100B526 */  addiu      $s5, $s5, 0x1
    /* 2B1C 8010531C 000040A6 */  sh         $zero, 0x0($s2)
  .L80105320:
    /* 2B20 80105320 01003126 */  addiu      $s1, $s1, 0x1
    /* 2B24 80105324 2000222A */  slti       $v0, $s1, 0x20
    /* 2B28 80105328 EBFF4014 */  bnez       $v0, .L801052D8
    /* 2B2C 8010532C 02005226 */   addiu     $s2, $s2, 0x2
    /* 2B30 80105330 98140408 */  j          .L80105260
    /* 2B34 80105334 0080143C */   lui       $s4, (0x80000000 >> 16)
  .L80105338:
    /* 2B38 80105338 2120E002 */  addu       $a0, $s7, $zero
    /* 2B3C 8010533C A801A527 */  addiu      $a1, $sp, 0x1A8
    /* 2B40 80105340 7800030C */  jal        vs_battle_memcpy
    /* 2B44 80105344 40000624 */   addiu     $a2, $zero, 0x40
    /* 2B48 80105348 1402BF8F */  lw         $ra, 0x214($sp)
    /* 2B4C 8010534C 1002BE8F */  lw         $fp, 0x210($sp)
    /* 2B50 80105350 0C02B78F */  lw         $s7, 0x20C($sp)
    /* 2B54 80105354 0802B68F */  lw         $s6, 0x208($sp)
    /* 2B58 80105358 0402B58F */  lw         $s5, 0x204($sp)
    /* 2B5C 8010535C 0002B48F */  lw         $s4, 0x200($sp)
    /* 2B60 80105360 FC01B38F */  lw         $s3, 0x1FC($sp)
    /* 2B64 80105364 F801B28F */  lw         $s2, 0x1F8($sp)
    /* 2B68 80105368 F401B18F */  lw         $s1, 0x1F4($sp)
    /* 2B6C 8010536C F001B08F */  lw         $s0, 0x1F0($sp)
    /* 2B70 80105370 0800E003 */  jr         $ra
    /* 2B74 80105374 1802BD27 */   addiu     $sp, $sp, 0x218
endlabel _sortWeaponsByStat
