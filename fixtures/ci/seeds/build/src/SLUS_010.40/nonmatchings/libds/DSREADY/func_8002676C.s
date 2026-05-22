nonmatching func_8002676C, 0x30

glabel func_8002676C
    /* 16F6C 8002676C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16F70 80026770 FF008430 */  andi       $a0, $a0, 0xFF
    /* 16F74 80026774 02000224 */  addiu      $v0, $zero, 0x2
    /* 16F78 80026778 04008214 */  bne        $a0, $v0, .L8002678C
    /* 16F7C 8002677C 1000BFAF */   sw        $ra, 0x10($sp)
    /* 16F80 80026780 0280043C */  lui        $a0, %hi(func_80026360)
    /* 16F84 80026784 069A000C */  jal        DsReadyCallback
    /* 16F88 80026788 60638424 */   addiu     $a0, $a0, %lo(func_80026360)
  .L8002678C:
    /* 16F8C 8002678C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16F90 80026790 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 16F94 80026794 0800E003 */  jr         $ra
    /* 16F98 80026798 00000000 */   nop
endlabel func_8002676C
