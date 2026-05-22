nonmatching vs_main_freeSfxQueueSlot, 0x88

glabel vs_main_freeSfxQueueSlot
    /* 36764 80045F64 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 36768 80045F68 FFFF8324 */  addiu      $v1, $a0, -0x1
    /* 3676C 80045F6C 0300622C */  sltiu      $v0, $v1, 0x3
    /* 36770 80045F70 1400BFAF */  sw         $ra, 0x14($sp)
    /* 36774 80045F74 18004010 */  beqz       $v0, .L80045FD8
    /* 36778 80045F78 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3677C 80045F7C 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 36780 80045F80 38E04224 */  addiu      $v0, $v0, %lo(vs_main_soundData)
    /* 36784 80045F84 80180300 */  sll        $v1, $v1, 2
    /* 36788 80045F88 21806200 */  addu       $s0, $v1, $v0
    /* 3678C 80045F8C 5800048E */  lw         $a0, 0x58($s0)
    /* 36790 80045F90 00000000 */  nop
    /* 36794 80045F94 10008010 */  beqz       $a0, .L80045FD8
    /* 36798 80045F98 04000224 */   addiu     $v0, $zero, 0x4
    /* 3679C 80045F9C 00008384 */  lh         $v1, 0x0($a0)
    /* 367A0 80045FA0 00000000 */  nop
    /* 367A4 80045FA4 05006214 */  bne        $v1, $v0, .L80045FBC
    /* 367A8 80045FA8 06000224 */   addiu     $v0, $zero, 0x6
    /* 367AC 80045FAC E012010C */  jal        vs_main_freeCdQueueSlot
    /* 367B0 80045FB0 00000000 */   nop
    /* 367B4 80045FB4 F6170108 */  j          .L80045FD8
    /* 367B8 80045FB8 580000AE */   sw        $zero, 0x58($s0)
  .L80045FBC:
    /* 367BC 80045FBC 07006214 */  bne        $v1, $v0, .L80045FDC
    /* 367C0 80045FC0 01000224 */   addiu     $v0, $zero, 0x1
    /* 367C4 80045FC4 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 367C8 80045FC8 00000000 */   nop
    /* 367CC 80045FCC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 367D0 80045FD0 F7170108 */  j          .L80045FDC
    /* 367D4 80045FD4 580002AE */   sw        $v0, 0x58($s0)
  .L80045FD8:
    /* 367D8 80045FD8 21100000 */  addu       $v0, $zero, $zero
  .L80045FDC:
    /* 367DC 80045FDC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 367E0 80045FE0 1000B08F */  lw         $s0, 0x10($sp)
    /* 367E4 80045FE4 0800E003 */  jr         $ra
    /* 367E8 80045FE8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_freeSfxQueueSlot
