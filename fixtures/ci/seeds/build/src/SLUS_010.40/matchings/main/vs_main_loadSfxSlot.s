nonmatching vs_main_loadSfxSlot, 0x12C

glabel vs_main_loadSfxSlot
    /* 365E0 80045DE0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 365E4 80045DE4 2400B3AF */  sw         $s3, 0x24($sp)
    /* 365E8 80045DE8 21988000 */  addu       $s3, $a0, $zero
    /* 365EC 80045DEC 2800B4AF */  sw         $s4, 0x28($sp)
    /* 365F0 80045DF0 21A0A000 */  addu       $s4, $a1, $zero
    /* 365F4 80045DF4 FFFF8426 */  addiu      $a0, $s4, -0x1
    /* 365F8 80045DF8 0300822C */  sltiu      $v0, $a0, 0x3
    /* 365FC 80045DFC 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 36600 80045E00 2000B2AF */  sw         $s2, 0x20($sp)
    /* 36604 80045E04 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 36608 80045E08 37004010 */  beqz       $v0, .L80045EE8
    /* 3660C 80045E0C 1800B0AF */   sw        $s0, 0x18($sp)
    /* 36610 80045E10 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 36614 80045E14 38E04224 */  addiu      $v0, $v0, %lo(vs_main_soundData)
    /* 36618 80045E18 80180400 */  sll        $v1, $a0, 2
    /* 3661C 80045E1C 21286200 */  addu       $a1, $v1, $v0
    /* 36620 80045E20 4C00A28C */  lw         $v0, 0x4C($a1)
    /* 36624 80045E24 00000000 */  nop
    /* 36628 80045E28 30004014 */  bnez       $v0, .L80045EEC
    /* 3662C 80045E2C 21100000 */   addu      $v0, $zero, $zero
    /* 36630 80045E30 0580023C */  lui        $v0, %hi(_seLBAs)
    /* 36634 80045E34 E0A94224 */  addiu      $v0, $v0, %lo(_seLBAs)
    /* 36638 80045E38 80181300 */  sll        $v1, $s3, 2
    /* 3663C 80045E3C 21106200 */  addu       $v0, $v1, $v0
    /* 36640 80045E40 0000428C */  lw         $v0, 0x0($v0)
    /* 36644 80045E44 00000000 */  nop
    /* 36648 80045E48 1000A2AF */  sw         $v0, 0x10($sp)
    /* 3664C 80045E4C 0580023C */  lui        $v0, %hi(_seFileSizes)
    /* 36650 80045E50 20B04224 */  addiu      $v0, $v0, %lo(_seFileSizes)
    /* 36654 80045E54 21186200 */  addu       $v1, $v1, $v0
    /* 36658 80045E58 0000628C */  lw         $v0, 0x0($v1)
    /* 3665C 80045E5C 00000000 */  nop
    /* 36660 80045E60 1400A2AF */  sw         $v0, 0x14($sp)
    /* 36664 80045E64 5800A38C */  lw         $v1, 0x58($a1)
    /* 36668 80045E68 00000000 */  nop
    /* 3666C 80045E6C 06006010 */  beqz       $v1, .L80045E88
    /* 36670 80045E70 21888000 */   addu      $s1, $a0, $zero
    /* 36674 80045E74 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 36678 80045E78 03006210 */  beq        $v1, $v0, .L80045E88
    /* 3667C 80045E7C 8F000424 */   addiu     $a0, $zero, 0x8F
    /* 36680 80045E80 2624010C */  jal        vs_main_nop9
    /* 36684 80045E84 21280000 */   addu      $a1, $zero, $zero
  .L80045E88:
    /* 36688 80045E88 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 3668C 80045E8C 1000A427 */   addiu     $a0, $sp, 0x10
    /* 36690 80045E90 0680033C */  lui        $v1, %hi(vs_main_soundData)
    /* 36694 80045E94 38E07224 */  addiu      $s2, $v1, %lo(vs_main_soundData)
    /* 36698 80045E98 80181100 */  sll        $v1, $s1, 2
    /* 3669C 80045E9C 21807200 */  addu       $s0, $v1, $s2
    /* 366A0 80045EA0 4C00038E */  lw         $v1, 0x4C($s0)
    /* 366A4 80045EA4 00000000 */  nop
    /* 366A8 80045EA8 04006010 */  beqz       $v1, .L80045EBC
    /* 366AC 80045EAC 580002AE */   sw        $v0, 0x58($s0)
    /* 366B0 80045EB0 90000424 */  addiu      $a0, $zero, 0x90
    /* 366B4 80045EB4 2624010C */  jal        vs_main_nop9
    /* 366B8 80045EB8 21280000 */   addu      $a1, $zero, $zero
  .L80045EBC:
    /* 366BC 80045EBC 21103202 */  addu       $v0, $s1, $s2
    /* 366C0 80045EC0 480053A0 */  sb         $s3, 0x48($v0)
    /* 366C4 80045EC4 1400A48F */  lw         $a0, 0x14($sp)
    /* 366C8 80045EC8 8F0F010C */  jal        vs_main_allocHeapR
    /* 366CC 80045ECC 00000000 */   nop
    /* 366D0 80045ED0 5800048E */  lw         $a0, 0x58($s0)
    /* 366D4 80045ED4 21284000 */  addu       $a1, $v0, $zero
    /* 366D8 80045ED8 F112010C */  jal        vs_main_cdEnqueue
    /* 366DC 80045EDC 4C0005AE */   sw        $a1, 0x4C($s0)
    /* 366E0 80045EE0 BB170108 */  j          .L80045EEC
    /* 366E4 80045EE4 21108002 */   addu      $v0, $s4, $zero
  .L80045EE8:
    /* 366E8 80045EE8 21100000 */  addu       $v0, $zero, $zero
  .L80045EEC:
    /* 366EC 80045EEC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 366F0 80045EF0 2800B48F */  lw         $s4, 0x28($sp)
    /* 366F4 80045EF4 2400B38F */  lw         $s3, 0x24($sp)
    /* 366F8 80045EF8 2000B28F */  lw         $s2, 0x20($sp)
    /* 366FC 80045EFC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 36700 80045F00 1800B08F */  lw         $s0, 0x18($sp)
    /* 36704 80045F04 0800E003 */  jr         $ra
    /* 36708 80045F08 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_main_loadSfxSlot
