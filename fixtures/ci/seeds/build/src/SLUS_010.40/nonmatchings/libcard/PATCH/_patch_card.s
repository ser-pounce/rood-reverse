nonmatching _patch_card, 0x94

glabel _patch_card
    /* 1F790 8002EF90 0480013C */  lui        $at, %hi(D_8003FED8)
    /* 1F794 8002EF94 D8FE3FAC */  sw         $ra, %lo(D_8003FED8)($at)
    /* 1F798 8002EF98 5D9A000C */  jal        EnterCriticalSection
    /* 1F79C 8002EF9C 00000000 */   nop
    /* 1F7A0 8002EFA0 56000924 */  addiu      $t1, $zero, 0x56
    /* 1F7A4 8002EFA4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1F7A8 8002EFA8 09F84001 */  jalr       $t2
    /* 1F7AC 8002EFAC 00000000 */   nop
    /* 1F7B0 8002EFB0 1800428C */  lw         $v0, 0x18($v0)
    /* 1F7B4 8002EFB4 00000000 */  nop
    /* 1F7B8 8002EFB8 7000438C */  lw         $v1, 0x70($v0)
    /* 1F7BC 8002EFBC 00000000 */  nop
    /* 1F7C0 8002EFC0 FFFF6930 */  andi       $t1, $v1, 0xFFFF
    /* 1F7C4 8002EFC4 004C0900 */  sll        $t1, $t1, 16
    /* 1F7C8 8002EFC8 7400438C */  lw         $v1, 0x74($v0)
    /* 1F7CC 8002EFCC 00000000 */  nop
    /* 1F7D0 8002EFD0 FFFF6A30 */  andi       $t2, $v1, 0xFFFF
    /* 1F7D4 8002EFD4 21182A01 */  addu       $v1, $t1, $t2
    /* 1F7D8 8002EFD8 28006224 */  addiu      $v0, $v1, 0x28
    /* 1F7DC 8002EFDC 03800A3C */  lui        $t2, %hi(func_8002EF68)
    /* 1F7E0 8002EFE0 68EF4A25 */  addiu      $t2, $t2, %lo(func_8002EF68)
    /* 1F7E4 8002EFE4 0380093C */  lui        $t1, %hi(func_8002EF68 + 0x14)
    /* 1F7E8 8002EFE8 7CEF2925 */  addiu      $t1, $t1, %lo(func_8002EF68 + 0x14)
  .L8002EFEC:
    /* 1F7EC 8002EFEC 0000438D */  lw         $v1, 0x0($t2)
    /* 1F7F0 8002EFF0 00000000 */  nop
    /* 1F7F4 8002EFF4 000043AC */  sw         $v1, 0x0($v0)
    /* 1F7F8 8002EFF8 04004A25 */  addiu      $t2, $t2, 0x4
    /* 1F7FC 8002EFFC FBFF4915 */  bne        $t2, $t1, .L8002EFEC
    /* 1F800 8002F000 04004224 */   addiu     $v0, $v0, 0x4
    /* 1F804 8002F004 0100013C */  lui        $at, (0x10000 >> 16)
    /* 1F808 8002F008 1D9A000C */  jal        FlushCache
    /* 1F80C 8002F00C FCDF22AC */   sw        $v0, -0x2004($at)
    /* 1F810 8002F010 04801F3C */  lui        $ra, %hi(D_8003FED8)
    /* 1F814 8002F014 D8FEFF8F */  lw         $ra, %lo(D_8003FED8)($ra)
    /* 1F818 8002F018 00000000 */  nop
    /* 1F81C 8002F01C 0800E003 */  jr         $ra
    /* 1F820 8002F020 00000000 */   nop
endlabel _patch_card
