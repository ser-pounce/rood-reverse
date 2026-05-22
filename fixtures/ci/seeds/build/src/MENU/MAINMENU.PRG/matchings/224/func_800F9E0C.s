nonmatching func_800F9E0C, 0xAC

glabel func_800F9E0C
    /* 60C 800F9E0C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 610 800F9E10 1800B0AF */  sw         $s0, 0x18($sp)
    /* 614 800F9E14 0F80103C */  lui        $s0, %hi(D_800F4538)
    /* 618 800F9E18 38451026 */  addiu      $s0, $s0, %lo(D_800F4538)
    /* 61C 800F9E1C 0F80023C */  lui        $v0, %hi(D_800F4588)
    /* 620 800F9E20 88454224 */  addiu      $v0, $v0, %lo(D_800F4588)
    /* 624 800F9E24 2000BFAF */  sw         $ra, 0x20($sp)
    /* 628 800F9E28 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 62C 800F9E2C 0400118E */  lw         $s1, 0x4($s0)
    /* 630 800F9E30 0800438C */  lw         $v1, 0x8($v0)
    /* 634 800F9E34 0C00428C */  lw         $v0, 0xC($v0)
    /* 638 800F9E38 01000424 */  addiu      $a0, $zero, 0x1
    /* 63C 800F9E3C 1000A3AF */  sw         $v1, 0x10($sp)
    /* 640 800F9E40 EC73020C */  jal        func_8009CFB0
    /* 644 800F9E44 1400A2AF */   sw        $v0, 0x14($sp)
    /* 648 800F9E48 540F010C */  jal        vs_main_freeHeap
    /* 64C 800F9E4C 21202002 */   addu      $a0, $s1, $zero
    /* 650 800F9E50 4000118E */  lw         $s1, 0x40($s0)
    /* 654 800F9E54 00000000 */  nop
    /* 658 800F9E58 05002012 */  beqz       $s1, .L800F9E70
    /* 65C 800F9E5C 00000000 */   nop
    /* 660 800F9E60 EC73020C */  jal        func_8009CFB0
    /* 664 800F9E64 10000424 */   addiu     $a0, $zero, 0x10
    /* 668 800F9E68 540F010C */  jal        vs_main_freeHeap
    /* 66C 800F9E6C 21202002 */   addu      $a0, $s1, $zero
  .L800F9E70:
    /* 670 800F9E70 1000A48F */  lw         $a0, 0x10($sp)
    /* 674 800F9E74 00000000 */  nop
    /* 678 800F9E78 03008010 */  beqz       $a0, .L800F9E88
    /* 67C 800F9E7C 00000000 */   nop
    /* 680 800F9E80 540F010C */  jal        vs_main_freeHeap
    /* 684 800F9E84 00000000 */   nop
  .L800F9E88:
    /* 688 800F9E88 1400A48F */  lw         $a0, 0x14($sp)
    /* 68C 800F9E8C 00000000 */  nop
    /* 690 800F9E90 03008010 */  beqz       $a0, .L800F9EA0
    /* 694 800F9E94 00000000 */   nop
    /* 698 800F9E98 540F010C */  jal        vs_main_freeHeap
    /* 69C 800F9E9C 00000000 */   nop
  .L800F9EA0:
    /* 6A0 800F9EA0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6A4 800F9EA4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6A8 800F9EA8 1800B08F */  lw         $s0, 0x18($sp)
    /* 6AC 800F9EAC 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 6B0 800F9EB0 0800E003 */  jr         $ra
    /* 6B4 800F9EB4 00000000 */   nop
endlabel func_800F9E0C
