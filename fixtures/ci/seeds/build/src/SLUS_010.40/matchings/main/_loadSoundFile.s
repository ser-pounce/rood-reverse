nonmatching _loadSoundFile, 0xF8

glabel _loadSoundFile
    /* 36E78 80046678 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 36E7C 8004667C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 36E80 80046680 21888000 */  addu       $s1, $a0, $zero
    /* 36E84 80046684 2000BFAF */  sw         $ra, 0x20($sp)
    /* 36E88 80046688 C247000C */  jal        func_80011F08
    /* 36E8C 8004668C 1800B0AF */   sw        $s0, 0x18($sp)
    /* 36E90 80046690 21184000 */  addu       $v1, $v0, $zero
    /* 36E94 80046694 04006104 */  bgez       $v1, .L800466A8
    /* 36E98 80046698 03240200 */   sra       $a0, $v0, 16
    /* 36E9C 8004669C FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* 36EA0 800466A0 21106200 */  addu       $v0, $v1, $v0
    /* 36EA4 800466A4 03240200 */  sra        $a0, $v0, 16
  .L800466A8:
    /* 36EA8 800466A8 00140400 */  sll        $v0, $a0, 16
    /* 36EAC 800466AC 23106200 */  subu       $v0, $v1, $v0
    /* 36EB0 800466B0 2A005110 */  beq        $v0, $s1, .L8004675C
    /* 36EB4 800466B4 00000000 */   nop
    /* 36EB8 800466B8 28009110 */  beq        $a0, $s1, .L8004675C
    /* 36EBC 800466BC 0580023C */   lui       $v0, %hi(_soundLBAs)
    /* 36EC0 800466C0 30A54224 */  addiu      $v0, $v0, %lo(_soundLBAs)
    /* 36EC4 800466C4 80181100 */  sll        $v1, $s1, 2
    /* 36EC8 800466C8 21106200 */  addu       $v0, $v1, $v0
    /* 36ECC 800466CC 0000428C */  lw         $v0, 0x0($v0)
    /* 36ED0 800466D0 00000000 */  nop
    /* 36ED4 800466D4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 36ED8 800466D8 0580023C */  lui        $v0, %hi(_soundFileSizes)
    /* 36EDC 800466DC 70AB4224 */  addiu      $v0, $v0, %lo(_soundFileSizes)
    /* 36EE0 800466E0 21186200 */  addu       $v1, $v1, $v0
    /* 36EE4 800466E4 0680023C */  lui        $v0, %hi(vs_main_soundData + 0x84)
    /* 36EE8 800466E8 0000638C */  lw         $v1, 0x0($v1)
    /* 36EEC 800466EC BCE0448C */  lw         $a0, %lo(vs_main_soundData + 0x84)($v0)
    /* 36EF0 800466F0 00000000 */  nop
    /* 36EF4 800466F4 06008010 */  beqz       $a0, .L80046710
    /* 36EF8 800466F8 1400A3AF */   sw        $v1, 0x14($sp)
    /* 36EFC 800466FC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 36F00 80046700 03008210 */  beq        $a0, $v0, .L80046710
    /* 36F04 80046704 93000424 */   addiu     $a0, $zero, 0x93
    /* 36F08 80046708 2624010C */  jal        vs_main_nop9
    /* 36F0C 8004670C 21280000 */   addu      $a1, $zero, $zero
  .L80046710:
    /* 36F10 80046710 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 36F14 80046714 1000A427 */   addiu     $a0, $sp, 0x10
    /* 36F18 80046718 0680033C */  lui        $v1, %hi(vs_main_soundData)
    /* 36F1C 8004671C 38E07024 */  addiu      $s0, $v1, %lo(vs_main_soundData)
    /* 36F20 80046720 8000038E */  lw         $v1, 0x80($s0)
    /* 36F24 80046724 00000000 */  nop
    /* 36F28 80046728 04006010 */  beqz       $v1, .L8004673C
    /* 36F2C 8004672C 840002AE */   sw        $v0, 0x84($s0)
    /* 36F30 80046730 94000424 */  addiu      $a0, $zero, 0x94
    /* 36F34 80046734 2624010C */  jal        vs_main_nop9
    /* 36F38 80046738 21280000 */   addu      $a1, $zero, $zero
  .L8004673C:
    /* 36F3C 8004673C 1400A48F */  lw         $a0, 0x14($sp)
    /* 36F40 80046740 8F0F010C */  jal        vs_main_allocHeapR
    /* 36F44 80046744 00000000 */   nop
    /* 36F48 80046748 8400048E */  lw         $a0, 0x84($s0)
    /* 36F4C 8004674C 21284000 */  addu       $a1, $v0, $zero
    /* 36F50 80046750 800005AE */  sw         $a1, 0x80($s0)
    /* 36F54 80046754 F112010C */  jal        vs_main_cdEnqueue
    /* 36F58 80046758 7C0011AE */   sw        $s1, 0x7C($s0)
  .L8004675C:
    /* 36F5C 8004675C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 36F60 80046760 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 36F64 80046764 1800B08F */  lw         $s0, 0x18($sp)
    /* 36F68 80046768 0800E003 */  jr         $ra
    /* 36F6C 8004676C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _loadSoundFile
