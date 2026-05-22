nonmatching _loadSyd, 0xD8

glabel _loadSyd
    /* 4F04 80107704 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4F08 80107708 2000BFAF */  sw         $ra, 0x20($sp)
    /* 4F0C 8010770C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 4F10 80107710 1E008010 */  beqz       $a0, .L8010778C
    /* 4F14 80107714 1800B0AF */   sw        $s0, 0x18($sp)
    /* 4F18 80107718 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 4F1C 8010771C 1180113C */  lui        $s1, %hi(_sydSizes)
    /* 4F20 80107720 68BB3126 */  addiu      $s1, $s1, %lo(_sydSizes)
    /* 4F24 80107724 80800400 */  sll        $s0, $a0, 2
    /* 4F28 80107728 21881102 */  addu       $s1, $s0, $s1
    /* 4F2C 8010772C 0000248E */  lw         $a0, 0x0($s1)
    /* 4F30 80107730 8F0F010C */  jal        vs_main_allocHeapR
    /* 4F34 80107734 00000000 */   nop
    /* 4F38 80107738 1180033C */  lui        $v1, %hi(_sydLbas)
    /* 4F3C 8010773C 5CBB6324 */  addiu      $v1, $v1, %lo(_sydLbas)
    /* 4F40 80107740 21800302 */  addu       $s0, $s0, $v1
    /* 4F44 80107744 0000038E */  lw         $v1, 0x0($s0)
    /* 4F48 80107748 1000A427 */  addiu      $a0, $sp, 0x10
    /* 4F4C 8010774C 1000A3AF */  sw         $v1, 0x10($sp)
    /* 4F50 80107750 0000238E */  lw         $v1, 0x0($s1)
    /* 4F54 80107754 1180103C */  lui        $s0, %hi(_sydData)
    /* 4F58 80107758 58BB02AE */  sw         $v0, %lo(_sydData)($s0)
    /* 4F5C 8010775C C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 4F60 80107760 1400A3AF */   sw        $v1, 0x14($sp)
    /* 4F64 80107764 21204000 */  addu       $a0, $v0, $zero
    /* 4F68 80107768 58BB058E */  lw         $a1, %lo(_sydData)($s0)
    /* 4F6C 8010776C 1180023C */  lui        $v0, %hi(_sydCdQueueSlot)
    /* 4F70 80107770 F112010C */  jal        vs_main_cdEnqueue
    /* 4F74 80107774 54BC44AC */   sw        $a0, %lo(_sydCdQueueSlot)($v0)
    /* 4F78 80107778 21100000 */  addu       $v0, $zero, $zero
    /* 4F7C 8010777C 1180043C */  lui        $a0, %hi(_sydFileLoading)
    /* 4F80 80107780 01000324 */  addiu      $v1, $zero, 0x1
    /* 4F84 80107784 F21D0408 */  j          .L801077C8
    /* 4F88 80107788 58BC83A0 */   sb        $v1, %lo(_sydFileLoading)($a0)
  .L8010778C:
    /* 4F8C 8010778C 1180103C */  lui        $s0, %hi(_sydFileLoading)
    /* 4F90 80107790 58BC0292 */  lbu        $v0, %lo(_sydFileLoading)($s0)
    /* 4F94 80107794 00000000 */  nop
    /* 4F98 80107798 0A004010 */  beqz       $v0, .L801077C4
    /* 4F9C 8010779C 1180023C */   lui       $v0, %hi(_sydCdQueueSlot)
    /* 4FA0 801077A0 54BC448C */  lw         $a0, %lo(_sydCdQueueSlot)($v0)
    /* 4FA4 801077A4 00000000 */  nop
    /* 4FA8 801077A8 00008384 */  lh         $v1, 0x0($a0)
    /* 4FAC 801077AC 04000224 */  addiu      $v0, $zero, 0x4
    /* 4FB0 801077B0 05006214 */  bne        $v1, $v0, .L801077C8
    /* 4FB4 801077B4 21100000 */   addu      $v0, $zero, $zero
    /* 4FB8 801077B8 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 4FBC 801077BC 00000000 */   nop
    /* 4FC0 801077C0 58BC00A2 */  sb         $zero, %lo(_sydFileLoading)($s0)
  .L801077C4:
    /* 4FC4 801077C4 01000224 */  addiu      $v0, $zero, 0x1
  .L801077C8:
    /* 4FC8 801077C8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4FCC 801077CC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 4FD0 801077D0 1800B08F */  lw         $s0, 0x18($sp)
    /* 4FD4 801077D4 0800E003 */  jr         $ra
    /* 4FD8 801077D8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _loadSyd
