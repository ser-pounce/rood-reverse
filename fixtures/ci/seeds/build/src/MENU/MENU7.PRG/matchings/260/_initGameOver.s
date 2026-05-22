nonmatching _initGameOver, 0x114

glabel _initGameOver
    /* 5EDC 801086DC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5EE0 801086E0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 5EE4 801086E4 15008010 */  beqz       $a0, .L8010873C
    /* 5EE8 801086E8 1800B0AF */   sw        $s0, 0x18($sp)
    /* 5EEC 801086EC 0100023C */  lui        $v0, (0x14CD4 >> 16)
    /* 5EF0 801086F0 D44C4234 */  ori        $v0, $v0, (0x14CD4 & 0xFFFF)
    /* 5EF4 801086F4 1000A427 */  addiu      $a0, $sp, 0x10
    /* 5EF8 801086F8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5EFC 801086FC 00180224 */  addiu      $v0, $zero, 0x1800
    /* 5F00 80108700 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 5F04 80108704 1400A2AF */   sw        $v0, 0x14($sp)
    /* 5F08 80108708 00180424 */  addiu      $a0, $zero, 0x1800
    /* 5F0C 8010870C 1180103C */  lui        $s0, %hi(_initGameOverQueueSlot)
    /* 5F10 80108710 8F0F010C */  jal        vs_main_allocHeapR
    /* 5F14 80108714 0CAB02AE */   sw        $v0, %lo(_initGameOverQueueSlot)($s0)
    /* 5F18 80108718 21284000 */  addu       $a1, $v0, $zero
    /* 5F1C 8010871C 0CAB048E */  lw         $a0, %lo(_initGameOverQueueSlot)($s0)
    /* 5F20 80108720 1180023C */  lui        $v0, %hi(_gameOverBin)
    /* 5F24 80108724 F112010C */  jal        vs_main_cdEnqueue
    /* 5F28 80108728 10AB45AC */   sw        $a1, %lo(_gameOverBin)($v0)
    /* 5F2C 8010872C 21100000 */  addu       $v0, $zero, $zero
    /* 5F30 80108730 1180033C */  lui        $v1, %hi(_initGameOverState)
    /* 5F34 80108734 F8210408 */  j          .L801087E0
    /* 5F38 80108738 14AB60AC */   sw        $zero, %lo(_initGameOverState)($v1)
  .L8010873C:
    /* 5F3C 8010873C 1180103C */  lui        $s0, %hi(_initGameOverState)
    /* 5F40 80108740 14AB038E */  lw         $v1, %lo(_initGameOverState)($s0)
    /* 5F44 80108744 00000000 */  nop
    /* 5F48 80108748 05006010 */  beqz       $v1, .L80108760
    /* 5F4C 8010874C 01000224 */   addiu     $v0, $zero, 0x1
    /* 5F50 80108750 1D006210 */  beq        $v1, $v0, .L801087C8
    /* 5F54 80108754 1180023C */   lui       $v0, %hi(_gameOverBin)
    /* 5F58 80108758 F8210408 */  j          .L801087E0
    /* 5F5C 8010875C 21100000 */   addu      $v0, $zero, $zero
  .L80108760:
    /* 5F60 80108760 1180023C */  lui        $v0, %hi(_initGameOverQueueSlot)
    /* 5F64 80108764 0CAB448C */  lw         $a0, %lo(_initGameOverQueueSlot)($v0)
    /* 5F68 80108768 00000000 */  nop
    /* 5F6C 8010876C 00008384 */  lh         $v1, 0x0($a0)
    /* 5F70 80108770 04000224 */  addiu      $v0, $zero, 0x4
    /* 5F74 80108774 1A006214 */  bne        $v1, $v0, .L801087E0
    /* 5F78 80108778 21100000 */   addu      $v0, $zero, $zero
    /* 5F7C 8010877C E012010C */  jal        vs_main_freeCdQueueSlot
    /* 5F80 80108780 00000000 */   nop
    /* 5F84 80108784 0001043C */  lui        $a0, (0x1000340 >> 16)
    /* 5F88 80108788 40038434 */  ori        $a0, $a0, (0x1000340 & 0xFFFF)
    /* 5F8C 8010878C 8000063C */  lui        $a2, (0x800018 >> 16)
    /* 5F90 80108790 1180023C */  lui        $v0, %hi(_gameOverBin)
    /* 5F94 80108794 10AB458C */  lw         $a1, %lo(_gameOverBin)($v0)
    /* 5F98 80108798 6A33030C */  jal        vs_battle_drawImage
    /* 5F9C 8010879C 1800C634 */   ori       $a2, $a2, (0x800018 & 0xFFFF)
    /* 5FA0 801087A0 8001043C */  lui        $a0, (0x1800340 >> 16)
    /* 5FA4 801087A4 40038434 */  ori        $a0, $a0, (0x1800340 & 0xFFFF)
    /* 5FA8 801087A8 1180053C */  lui        $a1, %hi(_menuItemTextClut)
    /* 5FAC 801087AC 30A9A524 */  addiu      $a1, $a1, %lo(_menuItemTextClut)
    /* 5FB0 801087B0 0100063C */  lui        $a2, (0x10030 >> 16)
    /* 5FB4 801087B4 6A33030C */  jal        vs_battle_drawImage
    /* 5FB8 801087B8 3000C634 */   ori       $a2, $a2, (0x10030 & 0xFFFF)
    /* 5FBC 801087BC 01000224 */  addiu      $v0, $zero, 0x1
    /* 5FC0 801087C0 F7210408 */  j          .L801087DC
    /* 5FC4 801087C4 14AB02AE */   sw        $v0, %lo(_initGameOverState)($s0)
  .L801087C8:
    /* 5FC8 801087C8 10AB448C */  lw         $a0, %lo(_gameOverBin)($v0)
    /* 5FCC 801087CC 180F010C */  jal        vs_main_freeHeapR
    /* 5FD0 801087D0 00000000 */   nop
    /* 5FD4 801087D4 F8210408 */  j          .L801087E0
    /* 5FD8 801087D8 01000224 */   addiu     $v0, $zero, 0x1
  .L801087DC:
    /* 5FDC 801087DC 21100000 */  addu       $v0, $zero, $zero
  .L801087E0:
    /* 5FE0 801087E0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 5FE4 801087E4 1800B08F */  lw         $s0, 0x18($sp)
    /* 5FE8 801087E8 0800E003 */  jr         $ra
    /* 5FEC 801087EC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _initGameOver
