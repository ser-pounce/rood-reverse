nonmatching _intepolateMenuItemBgColour, 0xB4

glabel _intepolateMenuItemBgColour
    /* 2C58 80105458 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2C5C 8010545C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2C60 80105460 21908000 */  addu       $s2, $a0, $zero
    /* 2C64 80105464 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2C68 80105468 2180A000 */  addu       $s0, $a1, $zero
    /* 2C6C 8010546C 0900022E */  sltiu      $v0, $s0, 0x9
    /* 2C70 80105470 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2C74 80105474 10004010 */  beqz       $v0, .L801054B8
    /* 2C78 80105478 1400B1AF */   sw        $s1, 0x14($sp)
    /* 2C7C 8010547C 6B00043C */  lui        $a0, (0x6B4100 >> 16)
    /* 2C80 80105480 00418434 */  ori        $a0, $a0, (0x6B4100 & 0xFFFF)
    /* 2C84 80105484 6C00053C */  lui        $a1, (0x6C8219 >> 16)
    /* 2C88 80105488 1982A534 */  ori        $a1, $a1, (0x6C8219 & 0xFFFF)
    /* 2C8C 8010548C FF14040C */  jal        _interpolateRGB
    /* 2C90 80105490 21300002 */   addu      $a2, $s0, $zero
    /* 2C94 80105494 21884000 */  addu       $s1, $v0, $zero
    /* 2C98 80105498 3300043C */  lui        $a0, (0x330500 >> 16)
    /* 2C9C 8010549C 00058434 */  ori        $a0, $a0, (0x330500 & 0xFFFF)
    /* 2CA0 801054A0 2600053C */  lui        $a1, (0x262801 >> 16)
    /* 2CA4 801054A4 0128A534 */  ori        $a1, $a1, (0x262801 & 0xFFFF)
    /* 2CA8 801054A8 FF14040C */  jal        _interpolateRGB
    /* 2CAC 801054AC 21300002 */   addu      $a2, $s0, $zero
    /* 2CB0 801054B0 3A150408 */  j          .L801054E8
    /* 2CB4 801054B4 21202002 */   addu      $a0, $s1, $zero
  .L801054B8:
    /* 2CB8 801054B8 1180023C */  lui        $v0, %hi(colors1)
    /* 2CBC 801054BC 20A94224 */  addiu      $v0, $v0, %lo(colors1)
    /* 2CC0 801054C0 C2181000 */  srl        $v1, $s0, 3
    /* 2CC4 801054C4 FEFF6324 */  addiu      $v1, $v1, -0x2
    /* 2CC8 801054C8 80180300 */  sll        $v1, $v1, 2
    /* 2CCC 801054CC 21106200 */  addu       $v0, $v1, $v0
    /* 2CD0 801054D0 0000518C */  lw         $s1, 0x0($v0)
    /* 2CD4 801054D4 1180023C */  lui        $v0, %hi(colors2)
    /* 2CD8 801054D8 28A94224 */  addiu      $v0, $v0, %lo(colors2)
    /* 2CDC 801054DC 21186200 */  addu       $v1, $v1, $v0
    /* 2CE0 801054E0 0000628C */  lw         $v0, 0x0($v1)
    /* 2CE4 801054E4 21202002 */  addu       $a0, $s1, $zero
  .L801054E8:
    /* 2CE8 801054E8 21284000 */  addu       $a1, $v0, $zero
    /* 2CEC 801054EC FF14040C */  jal        _interpolateRGB
    /* 2CF0 801054F0 21304002 */   addu      $a2, $s2, $zero
    /* 2CF4 801054F4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2CF8 801054F8 1800B28F */  lw         $s2, 0x18($sp)
    /* 2CFC 801054FC 1400B18F */  lw         $s1, 0x14($sp)
    /* 2D00 80105500 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D04 80105504 0800E003 */  jr         $ra
    /* 2D08 80105508 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _intepolateMenuItemBgColour
