nonmatching _intepolateMenuItemBgColour, 0xB4

glabel _intepolateMenuItemBgColour
    /* 2CEC 8006B4EC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2CF0 8006B4F0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2CF4 8006B4F4 21908000 */  addu       $s2, $a0, $zero
    /* 2CF8 8006B4F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2CFC 8006B4FC 2180A000 */  addu       $s0, $a1, $zero
    /* 2D00 8006B500 0900022E */  sltiu      $v0, $s0, 0x9
    /* 2D04 8006B504 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2D08 8006B508 10004010 */  beqz       $v0, .L8006B54C
    /* 2D0C 8006B50C 1400B1AF */   sw        $s1, 0x14($sp)
    /* 2D10 8006B510 6B00043C */  lui        $a0, (0x6B4100 >> 16)
    /* 2D14 8006B514 00418434 */  ori        $a0, $a0, (0x6B4100 & 0xFFFF)
    /* 2D18 8006B518 6C00053C */  lui        $a1, (0x6C8219 >> 16)
    /* 2D1C 8006B51C 1982A534 */  ori        $a1, $a1, (0x6C8219 & 0xFFFF)
    /* 2D20 8006B520 24AD010C */  jal        _interpolateRGB
    /* 2D24 8006B524 21300002 */   addu      $a2, $s0, $zero
    /* 2D28 8006B528 21884000 */  addu       $s1, $v0, $zero
    /* 2D2C 8006B52C 3300043C */  lui        $a0, (0x330500 >> 16)
    /* 2D30 8006B530 00058434 */  ori        $a0, $a0, (0x330500 & 0xFFFF)
    /* 2D34 8006B534 2600053C */  lui        $a1, (0x262801 >> 16)
    /* 2D38 8006B538 0128A534 */  ori        $a1, $a1, (0x262801 & 0xFFFF)
    /* 2D3C 8006B53C 24AD010C */  jal        _interpolateRGB
    /* 2D40 8006B540 21300002 */   addu      $a2, $s0, $zero
    /* 2D44 8006B544 5FAD0108 */  j          .L8006B57C
    /* 2D48 8006B548 21202002 */   addu      $a0, $s1, $zero
  .L8006B54C:
    /* 2D4C 8006B54C 0780023C */  lui        $v0, %hi(_menuItemColors1)
    /* 2D50 8006B550 FC2E4224 */  addiu      $v0, $v0, %lo(_menuItemColors1)
    /* 2D54 8006B554 C2181000 */  srl        $v1, $s0, 3
    /* 2D58 8006B558 FEFF6324 */  addiu      $v1, $v1, -0x2
    /* 2D5C 8006B55C 80180300 */  sll        $v1, $v1, 2
    /* 2D60 8006B560 21106200 */  addu       $v0, $v1, $v0
    /* 2D64 8006B564 0000518C */  lw         $s1, 0x0($v0)
    /* 2D68 8006B568 0780023C */  lui        $v0, %hi(_menuItemColors2)
    /* 2D6C 8006B56C 042F4224 */  addiu      $v0, $v0, %lo(_menuItemColors2)
    /* 2D70 8006B570 21186200 */  addu       $v1, $v1, $v0
    /* 2D74 8006B574 0000628C */  lw         $v0, 0x0($v1)
    /* 2D78 8006B578 21202002 */  addu       $a0, $s1, $zero
  .L8006B57C:
    /* 2D7C 8006B57C 21284000 */  addu       $a1, $v0, $zero
    /* 2D80 8006B580 24AD010C */  jal        _interpolateRGB
    /* 2D84 8006B584 21304002 */   addu      $a2, $s2, $zero
    /* 2D88 8006B588 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2D8C 8006B58C 1800B28F */  lw         $s2, 0x18($sp)
    /* 2D90 8006B590 1400B18F */  lw         $s1, 0x14($sp)
    /* 2D94 8006B594 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D98 8006B598 0800E003 */  jr         $ra
    /* 2D9C 8006B59C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _intepolateMenuItemBgColour
