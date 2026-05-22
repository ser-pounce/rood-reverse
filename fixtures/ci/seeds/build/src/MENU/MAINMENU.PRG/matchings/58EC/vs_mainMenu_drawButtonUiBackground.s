nonmatching vs_mainMenu_drawButtonUiBackground, 0xD0

glabel vs_mainMenu_drawButtonUiBackground
    /* 6B44 80100344 F8FFBD27 */  addiu      $sp, $sp, -0x8
    /* 6B48 80100348 0000B0AF */  sw         $s0, 0x0($sp)
    /* 6B4C 8010034C 2180A000 */  addu       $s0, $a1, $zero
    /* 6B50 80100350 21480000 */  addu       $t1, $zero, $zero
    /* 6B54 80100354 801F023C */  lui        $v0, (0x1F800000 >> 16)
    /* 6B58 80100358 00004324 */  addiu      $v1, $v0, %lo(D_1F800000)
    /* 6B5C 8010035C 0400638C */  lw         $v1, 0x4($v1)
    /* 6B60 80100360 00004A8C */  lw         $t2, (0x1F800000 & 0xFFFF)($v0)
    /* 6B64 80100364 2600E018 */  blez       $a3, .L80100400
    /* 6B68 80100368 F4FF6B24 */   addiu     $t3, $v1, -0xC
    /* 6B6C 8010036C FF00183C */  lui        $t8, (0xFFFFFF >> 16)
    /* 6B70 80100370 FFFF1837 */  ori        $t8, $t8, (0xFFFFFF & 0xFFFF)
    /* 6B74 80100374 0006053C */  lui        $a1, (0x6000000 >> 16)
    /* 6B78 80100378 00E10F3C */  lui        $t7, (0xE1000200 >> 16)
    /* 6B7C 8010037C 0002EF35 */  ori        $t7, $t7, (0xE1000200 & 0xFFFF)
    /* 6B80 80100380 20500E3C */  lui        $t6, (0x50203840 >> 16)
    /* 6B84 80100384 4038CE35 */  ori        $t6, $t6, (0x50203840 & 0xFFFF)
    /* 6B88 80100388 FFFF8D30 */  andi       $t5, $a0, 0xFFFF
    /* 6B8C 8010038C 08000C3C */  lui        $t4, (0x81010 >> 16)
    /* 6B90 80100390 10108C35 */  ori        $t4, $t4, (0x81010 & 0xFFFF)
    /* 6B94 80100394 21308600 */  addu       $a2, $a0, $a2
    /* 6B98 80100398 00E1193C */  lui        $t9, (0xE1000000 >> 16)
    /* 6B9C 8010039C 18004825 */  addiu      $t0, $t2, 0x18
  .L801003A0:
    /* 6BA0 801003A0 21200902 */  addu       $a0, $s0, $t1
    /* 6BA4 801003A4 2318C900 */  subu       $v1, $a2, $t1
    /* 6BA8 801003A8 01002925 */  addiu      $t1, $t1, 0x1
    /* 6BAC 801003AC 00240400 */  sll        $a0, $a0, 16
    /* 6BB0 801003B0 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 6BB4 801003B4 0000628D */  lw         $v0, 0x0($t3)
    /* 6BB8 801003B8 25186400 */  or         $v1, $v1, $a0
    /* 6BBC 801003BC 24105800 */  and        $v0, $v0, $t8
    /* 6BC0 801003C0 25104500 */  or         $v0, $v0, $a1
    /* 6BC4 801003C4 000042AD */  sw         $v0, 0x0($t2)
    /* 6BC8 801003C8 2510A401 */  or         $v0, $t5, $a0
    /* 6BCC 801003CC ECFF0FAD */  sw         $t7, -0x14($t0)
    /* 6BD0 801003D0 F0FF0EAD */  sw         $t6, -0x10($t0)
    /* 6BD4 801003D4 F4FF02AD */  sw         $v0, -0xC($t0)
    /* 6BD8 801003D8 F8FF0CAD */  sw         $t4, -0x8($t0)
    /* 6BDC 801003DC FCFF03AD */  sw         $v1, -0x4($t0)
    /* 6BE0 801003E0 000019AD */  sw         $t9, 0x0($t0)
    /* 6BE4 801003E4 1C000825 */  addiu      $t0, $t0, 0x1C
    /* 6BE8 801003E8 00120A00 */  sll        $v0, $t2, 8
    /* 6BEC 801003EC 02120200 */  srl        $v0, $v0, 8
    /* 6BF0 801003F0 000062AD */  sw         $v0, 0x0($t3)
    /* 6BF4 801003F4 2A102701 */  slt        $v0, $t1, $a3
    /* 6BF8 801003F8 E9FF4014 */  bnez       $v0, .L801003A0
    /* 6BFC 801003FC 1C004A25 */   addiu     $t2, $t2, 0x1C
  .L80100400:
    /* 6C00 80100400 0000B08F */  lw         $s0, 0x0($sp)
    /* 6C04 80100404 801F023C */  lui        $v0, (0x1F800000 >> 16)
    /* 6C08 80100408 00004AAC */  sw         $t2, (0x1F800000 & 0xFFFF)($v0)
    /* 6C0C 8010040C 0800E003 */  jr         $ra
    /* 6C10 80100410 0800BD27 */   addiu     $sp, $sp, 0x8
endlabel vs_mainMenu_drawButtonUiBackground
