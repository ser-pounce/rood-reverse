nonmatching vs_main_processSoundQueue, 0xDC

glabel vs_main_processSoundQueue
    /* 36FA0 800467A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 36FA4 800467A4 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 36FA8 800467A8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 36FAC 800467AC 38E05024 */  addiu      $s0, $v0, %lo(vs_main_soundData)
    /* 36FB0 800467B0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 36FB4 800467B4 8400048E */  lw         $a0, 0x84($s0)
    /* 36FB8 800467B8 00000000 */  nop
    /* 36FBC 800467BC 2A008010 */  beqz       $a0, .L80046868
    /* 36FC0 800467C0 07000524 */   addiu     $a1, $zero, 0x7
    /* 36FC4 800467C4 00008384 */  lh         $v1, 0x0($a0)
    /* 36FC8 800467C8 00000000 */  nop
    /* 36FCC 800467CC 13006514 */  bne        $v1, $a1, .L8004681C
    /* 36FD0 800467D0 04000224 */   addiu     $v0, $zero, 0x4
    /* 36FD4 800467D4 014B000C */  jal        vs_sound_spuTransferring
    /* 36FD8 800467D8 00000000 */   nop
    /* 36FDC 800467DC 21184000 */  addu       $v1, $v0, $zero
    /* 36FE0 800467E0 09006014 */  bnez       $v1, .L80046808
    /* 36FE4 800467E4 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 36FE8 800467E8 8400048E */  lw         $a0, 0x84($s0)
    /* 36FEC 800467EC E012010C */  jal        vs_main_freeCdQueueSlot
    /* 36FF0 800467F0 00000000 */   nop
    /* 36FF4 800467F4 8000048E */  lw         $a0, 0x80($s0)
    /* 36FF8 800467F8 180F010C */  jal        vs_main_freeHeapR
    /* 36FFC 800467FC 840000AE */   sw        $zero, 0x84($s0)
    /* 37000 80046800 171A0108 */  j          .L8004685C
    /* 37004 80046804 21100000 */   addu      $v0, $zero, $zero
  .L80046808:
    /* 37008 80046808 18006214 */  bne        $v1, $v0, .L8004686C
    /* 3700C 8004680C 01000224 */   addiu     $v0, $zero, 0x1
    /* 37010 80046810 8400048E */  lw         $a0, 0x84($s0)
    /* 37014 80046814 111A0108 */  j          .L80046844
    /* 37018 80046818 00000000 */   nop
  .L8004681C:
    /* 3701C 8004681C 07006214 */  bne        $v1, $v0, .L8004683C
    /* 37020 80046820 06000224 */   addiu     $v0, $zero, 0x6
    /* 37024 80046824 000085A4 */  sh         $a1, 0x0($a0)
    /* 37028 80046828 8000048E */  lw         $a0, 0x80($s0)
    /* 3702C 8004682C 624C000C */  jal        func_80013188
    /* 37030 80046830 21280000 */   addu      $a1, $zero, $zero
    /* 37034 80046834 1B1A0108 */  j          .L8004686C
    /* 37038 80046838 01000224 */   addiu     $v0, $zero, 0x1
  .L8004683C:
    /* 3703C 8004683C 0B006214 */  bne        $v1, $v0, .L8004686C
    /* 37040 80046840 01000224 */   addiu     $v0, $zero, 0x1
  .L80046844:
    /* 37044 80046844 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 37048 80046848 00000000 */   nop
    /* 3704C 8004684C 8000048E */  lw         $a0, 0x80($s0)
    /* 37050 80046850 180F010C */  jal        vs_main_freeHeapR
    /* 37054 80046854 840000AE */   sw        $zero, 0x84($s0)
    /* 37058 80046858 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8004685C:
    /* 3705C 8004685C 800000AE */  sw         $zero, 0x80($s0)
    /* 37060 80046860 1B1A0108 */  j          .L8004686C
    /* 37064 80046864 7C0000AE */   sw        $zero, 0x7C($s0)
  .L80046868:
    /* 37068 80046868 21100000 */  addu       $v0, $zero, $zero
  .L8004686C:
    /* 3706C 8004686C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 37070 80046870 1000B08F */  lw         $s0, 0x10($sp)
    /* 37074 80046874 0800E003 */  jr         $ra
    /* 37078 80046878 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_processSoundQueue
