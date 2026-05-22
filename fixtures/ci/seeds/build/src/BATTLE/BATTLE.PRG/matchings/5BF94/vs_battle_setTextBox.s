nonmatching vs_battle_setTextBox, 0x9C

glabel vs_battle_setTextBox
    /* 5E3F0 800C6BF0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5E3F4 800C6BF4 40180400 */  sll        $v1, $a0, 1
    /* 5E3F8 800C6BF8 21186400 */  addu       $v1, $v1, $a0
    /* 5E3FC 800C6BFC 00190300 */  sll        $v1, $v1, 4
    /* 5E400 800C6C00 0F80023C */  lui        $v0, %hi(vs_battle_textBoxes)
    /* 5E404 800C6C04 E04F4224 */  addiu      $v0, $v0, %lo(vs_battle_textBoxes)
    /* 5E408 800C6C08 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5E40C 800C6C0C 21806200 */  addu       $s0, $v1, $v0
    /* 5E410 800C6C10 1800BFAF */  sw         $ra, 0x18($sp)
    /* 5E414 800C6C14 1100A010 */  beqz       $a1, .L800C6C5C
    /* 5E418 800C6C18 1400B1AF */   sw        $s1, 0x14($sp)
    /* 5E41C 800C6C1C 03000292 */  lbu        $v0, 0x3($s0)
    /* 5E420 800C6C20 01001124 */  addiu      $s1, $zero, 0x1
    /* 5E424 800C6C24 080005AE */  sw         $a1, 0x8($s0)
    /* 5E428 800C6C28 0C0011A6 */  sh         $s1, 0xC($s0)
    /* 5E42C 800C6C2C 040000A6 */  sh         $zero, 0x4($s0)
    /* 5E430 800C6C30 3F004430 */  andi       $a0, $v0, 0x3F
    /* 5E434 800C6C34 20004230 */  andi       $v0, $v0, 0x20
    /* 5E438 800C6C38 0E004014 */  bnez       $v0, .L800C6C74
    /* 5E43C 800C6C3C 0E0000A6 */   sh        $zero, 0xE($s0)
    /* 5E440 800C6C40 21280000 */  addu       $a1, $zero, $zero
    /* 5E444 800C6C44 2E000686 */  lh         $a2, 0x2E($s0)
    /* 5E448 800C6C48 01000724 */  addiu      $a3, $zero, 0x1
    /* 5E44C 800C6C4C 53AB020C */  jal        func_800AAD4C
    /* 5E450 800C6C50 0100C624 */   addiu     $a2, $a2, 0x1
    /* 5E454 800C6C54 1D1B0308 */  j          .L800C6C74
    /* 5E458 800C6C58 2C0011A6 */   sh        $s1, 0x2C($s0)
  .L800C6C5C:
    /* 5E45C 800C6C5C 0C000396 */  lhu        $v1, 0xC($s0)
    /* 5E460 800C6C60 FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 5E464 800C6C64 04006210 */  beq        $v1, $v0, .L800C6C78
    /* 5E468 800C6C68 21100000 */   addu      $v0, $zero, $zero
    /* 5E46C 800C6C6C 02006014 */  bnez       $v1, .L800C6C78
    /* 5E470 800C6C70 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L800C6C74:
    /* 5E474 800C6C74 21100000 */  addu       $v0, $zero, $zero
  .L800C6C78:
    /* 5E478 800C6C78 1800BF8F */  lw         $ra, 0x18($sp)
    /* 5E47C 800C6C7C 1400B18F */  lw         $s1, 0x14($sp)
    /* 5E480 800C6C80 1000B08F */  lw         $s0, 0x10($sp)
    /* 5E484 800C6C84 0800E003 */  jr         $ra
    /* 5E488 800C6C88 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_battle_setTextBox
