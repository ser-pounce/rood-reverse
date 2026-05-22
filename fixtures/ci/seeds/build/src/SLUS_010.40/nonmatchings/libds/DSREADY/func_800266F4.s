nonmatching func_800266F4, 0x78

glabel func_800266F4
    /* 16EF4 800266F4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 16EF8 800266F8 21200000 */  addu       $a0, $zero, $zero
    /* 16EFC 800266FC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 16F00 80026700 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 16F04 80026704 069A000C */  jal        DsReadyCallback
    /* 16F08 80026708 1800B0AF */   sw        $s0, 0x18($sp)
    /* 16F0C 8002670C 4C92000C */  jal        DS_lastpos
    /* 16F10 80026710 00000000 */   nop
    /* 16F14 80026714 9A96000C */  jal        DsPosToInt
    /* 16F18 80026718 21204000 */   addu      $a0, $v0, $zero
    /* 16F1C 8002671C 0380013C */  lui        $at, %hi(D_80032804)
    /* 16F20 80026720 4892000C */  jal        DS_lastmode
    /* 16F24 80026724 042822AC */   sw        $v0, %lo(D_80032804)($at)
    /* 16F28 80026728 4C92000C */  jal        DS_lastpos
    /* 16F2C 8002672C FF005030 */   andi      $s0, $v0, 0xFF
    /* 16F30 80026730 5392000C */  jal        DS_lastread
    /* 16F34 80026734 21884000 */   addu      $s1, $v0, $zero
    /* 16F38 80026738 21200002 */  addu       $a0, $s0, $zero
    /* 16F3C 8002673C FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 16F40 80026740 21282002 */  addu       $a1, $s1, $zero
    /* 16F44 80026744 FF004630 */  andi       $a2, $v0, 0xFF
    /* 16F48 80026748 0280073C */  lui        $a3, %hi(func_8002676C)
    /* 16F4C 8002674C 6C67E724 */  addiu      $a3, $a3, %lo(func_8002676C)
    /* 16F50 80026750 5E8F000C */  jal        DsPacket
    /* 16F54 80026754 1000A3AF */   sw        $v1, 0x10($sp)
    /* 16F58 80026758 2000BF8F */  lw         $ra, 0x20($sp)
    /* 16F5C 8002675C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 16F60 80026760 1800B08F */  lw         $s0, 0x18($sp)
    /* 16F64 80026764 0800E003 */  jr         $ra
    /* 16F68 80026768 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800266F4
