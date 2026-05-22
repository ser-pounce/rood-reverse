nonmatching func_8006EBF8, 0x84

glabel func_8006EBF8
    /* 63F8 8006EBF8 0F80023C */  lui        $v0, %hi(D_800F1968)
    /* 63FC 8006EBFC 6819428C */  lw         $v0, %lo(D_800F1968)($v0)
    /* 6400 8006EC00 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 6404 8006EC04 3400BFAF */  sw         $ra, 0x34($sp)
    /* 6408 8006EC08 03004014 */  bnez       $v0, .L8006EC18
    /* 640C 8006EC0C 3000B0AF */   sw        $s0, 0x30($sp)
    /* 6410 8006EC10 6393020C */  jal        func_800A4D8C
    /* 6414 8006EC14 00000000 */   nop
  .L8006EC18:
    /* 6418 8006EC18 21200000 */  addu       $a0, $zero, $zero
    /* 641C 8006EC1C 4284020C */  jal        func_800A1108
    /* 6420 8006EC20 1000A527 */   addiu     $a1, $sp, 0x10
    /* 6424 8006EC24 FAFF053C */  lui        $a1, (0xFFFA6000 >> 16)
    /* 6428 8006EC28 0060A534 */  ori        $a1, $a1, (0xFFFA6000 & 0xFFFF)
    /* 642C 8006EC2C 2000A427 */  addiu      $a0, $sp, 0x20
    /* 6430 8006EC30 1400A287 */  lh         $v0, 0x14($sp)
    /* 6434 8006EC34 1600A387 */  lh         $v1, 0x16($sp)
    /* 6438 8006EC38 00130200 */  sll        $v0, $v0, 12
    /* 643C 8006EC3C 001B0300 */  sll        $v1, $v1, 12
    /* 6440 8006EC40 2000A2AF */  sw         $v0, 0x20($sp)
    /* 6444 8006EC44 1800A287 */  lh         $v0, 0x18($sp)
    /* 6448 8006EC48 21186500 */  addu       $v1, $v1, $a1
    /* 644C 8006EC4C 2400A3AF */  sw         $v1, 0x24($sp)
    /* 6450 8006EC50 00130200 */  sll        $v0, $v0, 12
    /* 6454 8006EC54 F8B7010C */  jal        _snapLookAtToPosition
    /* 6458 8006EC58 2800A2AF */   sw        $v0, 0x28($sp)
    /* 645C 8006EC5C 0F80043C */  lui        $a0, %hi(vs_battle_cameraCurrentSpherical)
    /* 6460 8006EC60 B3EA010C */  jal        _setCameraPositionFromAngles
    /* 6464 8006EC64 D0198424 */   addiu     $a0, $a0, %lo(vs_battle_cameraCurrentSpherical)
    /* 6468 8006EC68 21100002 */  addu       $v0, $s0, $zero
    /* 646C 8006EC6C 3400BF8F */  lw         $ra, 0x34($sp)
    /* 6470 8006EC70 3000B08F */  lw         $s0, 0x30($sp)
    /* 6474 8006EC74 0800E003 */  jr         $ra
    /* 6478 8006EC78 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8006EBF8
