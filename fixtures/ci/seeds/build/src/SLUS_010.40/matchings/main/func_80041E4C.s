nonmatching func_80041E4C, 0xE8

glabel func_80041E4C
    /* 3264C 80041E4C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 32650 80041E50 0800033C */  lui        $v1, (0x8D800 >> 16)
    /* 32654 80041E54 00D86334 */  ori        $v1, $v1, (0x8D800 & 0xFFFF)
    /* 32658 80041E58 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3265C 80041E5C 4C040224 */  addiu      $v0, $zero, 0x44C
    /* 32660 80041E60 2000BFAF */  sw         $ra, 0x20($sp)
    /* 32664 80041E64 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 32668 80041E68 1800B0AF */  sw         $s0, 0x18($sp)
    /* 3266C 80041E6C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 32670 80041E70 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 32674 80041E74 1400A3AF */   sw        $v1, 0x14($sp)
    /* 32678 80041E78 21804000 */  addu       $s0, $v0, $zero
    /* 3267C 80041E7C 0180023C */  lui        $v0, %hi(vs_overlay_slots)
    /* 32680 80041E80 0000458C */  lw         $a1, %lo(vs_overlay_slots)($v0)
    /* 32684 80041E84 FD12010C */  jal        vs_main_cdEnqueuePriority
    /* 32688 80041E88 21200002 */   addu      $a0, $s0, $zero
    /* 3268C 80041E8C 00000386 */  lh         $v1, 0x0($s0)
    /* 32690 80041E90 04000224 */  addiu      $v0, $zero, 0x4
    /* 32694 80041E94 07006210 */  beq        $v1, $v0, .L80041EB4
    /* 32698 80041E98 21884000 */   addu      $s1, $v0, $zero
  .L80041E9C:
    /* 3269C 80041E9C 8709010C */  jal        vs_main_gametimeUpdate
    /* 326A0 80041EA0 21200000 */   addu      $a0, $zero, $zero
    /* 326A4 80041EA4 00000286 */  lh         $v0, 0x0($s0)
    /* 326A8 80041EA8 00000000 */  nop
    /* 326AC 80041EAC FBFF5114 */  bne        $v0, $s1, .L80041E9C
    /* 326B0 80041EB0 00000000 */   nop
  .L80041EB4:
    /* 326B4 80041EB4 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 326B8 80041EB8 21200002 */   addu      $a0, $s0, $zero
    /* 326BC 80041EBC 1000A427 */  addiu      $a0, $sp, 0x10
    /* 326C0 80041EC0 67050224 */  addiu      $v0, $zero, 0x567
    /* 326C4 80041EC4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 326C8 80041EC8 00200224 */  addiu      $v0, $zero, 0x2000
    /* 326CC 80041ECC C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 326D0 80041ED0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 326D4 80041ED4 21804000 */  addu       $s0, $v0, $zero
    /* 326D8 80041ED8 0180023C */  lui        $v0, %hi(vs_overlay_slots + 0x4)
    /* 326DC 80041EDC 0400458C */  lw         $a1, %lo(vs_overlay_slots + 0x4)($v0)
    /* 326E0 80041EE0 FD12010C */  jal        vs_main_cdEnqueuePriority
    /* 326E4 80041EE4 21200002 */   addu      $a0, $s0, $zero
    /* 326E8 80041EE8 00000386 */  lh         $v1, 0x0($s0)
    /* 326EC 80041EEC 04000224 */  addiu      $v0, $zero, 0x4
    /* 326F0 80041EF0 07006210 */  beq        $v1, $v0, .L80041F10
    /* 326F4 80041EF4 21884000 */   addu      $s1, $v0, $zero
  .L80041EF8:
    /* 326F8 80041EF8 8709010C */  jal        vs_main_gametimeUpdate
    /* 326FC 80041EFC 21200000 */   addu      $a0, $zero, $zero
    /* 32700 80041F00 00000286 */  lh         $v0, 0x0($s0)
    /* 32704 80041F04 00000000 */  nop
    /* 32708 80041F08 FBFF5114 */  bne        $v0, $s1, .L80041EF8
    /* 3270C 80041F0C 00000000 */   nop
  .L80041F10:
    /* 32710 80041F10 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 32714 80041F14 21200002 */   addu      $a0, $s0, $zero
    /* 32718 80041F18 1D0B010C */  jal        vs_main_wait
    /* 3271C 80041F1C 00000000 */   nop
    /* 32720 80041F20 2000BF8F */  lw         $ra, 0x20($sp)
    /* 32724 80041F24 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 32728 80041F28 1800B08F */  lw         $s0, 0x18($sp)
    /* 3272C 80041F2C 0800E003 */  jr         $ra
    /* 32730 80041F30 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80041E4C
