nonmatching func_800B6438, 0x70

glabel func_800B6438
    /* 4DC38 800B6438 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 4DC3C 800B643C 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 4DC40 800B6440 80180400 */  sll        $v1, $a0, 2
    /* 4DC44 800B6444 21104300 */  addu       $v0, $v0, $v1
    /* 4DC48 800B6448 0000428C */  lw         $v0, 0x0($v0)
    /* 4DC4C 800B644C 00000000 */  nop
    /* 4DC50 800B6450 0A004380 */  lb         $v1, 0xA($v0)
  .L800B6454:
    /* 4DC54 800B6454 ECFFBD27 */  addiu      $sp, $sp, -0x14
    /* 4DC58 800B6458 0000A2AF */  sw         $v0, 0x0($sp)
    /* 4DC5C 800B645C 0400A5AF */  sw         $a1, 0x4($sp)
    /* 4DC60 800B6460 0800A6AF */  sw         $a2, 0x8($sp)
    /* 4DC64 800B6464 0C00A7AF */  sw         $a3, 0xC($sp)
    /* 4DC68 800B6468 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4DC6C 800B646C 60006334 */  ori        $v1, $v1, 0x60
    /* 4DC70 800B6470 0A0043A0 */  sb         $v1, 0xA($v0)
    /* 4DC74 800B6474 1F000534 */  ori        $a1, $zero, 0x1F
    /* 4DC78 800B6478 21300000 */  addu       $a2, $zero, $zero
    /* 4DC7C 800B647C 8180020C */  jal        func_800A0204
    /* 4DC80 800B6480 08000734 */   ori       $a3, $zero, 0x8
    /* 4DC84 800B6484 0000A48F */  lw         $a0, 0x0($sp)
    /* 4DC88 800B6488 0400A58F */  lw         $a1, 0x4($sp)
    /* 4DC8C 800B648C 0800A68F */  lw         $a2, 0x8($sp)
    /* 4DC90 800B6490 2388020C */  jal        func_800A208C
    /* 4DC94 800B6494 0C00A78F */   lw        $a3, 0xC($sp)
    /* 4DC98 800B6498 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4DC9C 800B649C 1400BD27 */  addiu      $sp, $sp, 0x14
    /* 4DCA0 800B64A0 0800E003 */  jr         $ra
    /* 4DCA4 800B64A4 00000000 */   nop
endlabel func_800B6438
