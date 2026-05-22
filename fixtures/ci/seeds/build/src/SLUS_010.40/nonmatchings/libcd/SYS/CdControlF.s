nonmatching CdControlF, 0x134

glabel CdControlF
    /* 10E9C 8002069C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 10EA0 800206A0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 10EA4 800206A4 2188A000 */  addu       $s1, $a1, $zero
    /* 10EA8 800206A8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 10EAC 800206AC 21988000 */  addu       $s3, $a0, $zero
    /* 10EB0 800206B0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 10EB4 800206B4 03001024 */  addiu      $s0, $zero, 0x3
    /* 10EB8 800206B8 3000BEAF */  sw         $fp, 0x30($sp)
    /* 10EBC 800206BC 01001E24 */  addiu      $fp, $zero, 0x1
    /* 10EC0 800206C0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 10EC4 800206C4 FF007232 */  andi       $s2, $s3, 0xFF
    /* 10EC8 800206C8 0380033C */  lui        $v1, %hi(D_80032174)
    /* 10ECC 800206CC 74216324 */  addiu      $v1, $v1, %lo(D_80032174)
    /* 10ED0 800206D0 2000B4AF */  sw         $s4, 0x20($sp)
    /* 10ED4 800206D4 0380143C */  lui        $s4, %hi(D_800321FC)
    /* 10ED8 800206D8 FC21948E */  lw         $s4, %lo(D_800321FC)($s4)
    /* 10EDC 800206DC 80101200 */  sll        $v0, $s2, 2
    /* 10EE0 800206E0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 10EE4 800206E4 21A84300 */  addu       $s5, $v0, $v1
    /* 10EE8 800206E8 2800B6AF */  sw         $s6, 0x28($sp)
    /* 10EEC 800206EC 21B00000 */  addu       $s6, $zero, $zero
    /* 10EF0 800206F0 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 10EF4 800206F4 FFFF1724 */  addiu      $s7, $zero, -0x1
    /* 10EF8 800206F8 3400BFAF */  sw         $ra, 0x34($sp)
  .L800206FC:
    /* 10EFC 800206FC 0380013C */  lui        $at, %hi(D_800321FC)
    /* 10F00 80020700 0B005E12 */  beq        $s2, $fp, .L80020730
    /* 10F04 80020704 FC2120AC */   sw        $zero, %lo(D_800321FC)($at)
    /* 10F08 80020708 0380023C */  lui        $v0, %hi(D_80032208)
    /* 10F0C 8002070C 08224290 */  lbu        $v0, %lo(D_80032208)($v0)
    /* 10F10 80020710 00000000 */  nop
    /* 10F14 80020714 10004230 */  andi       $v0, $v0, 0x10
    /* 10F18 80020718 05004010 */  beqz       $v0, .L80020730
    /* 10F1C 8002071C 01000424 */   addiu     $a0, $zero, 0x1
    /* 10F20 80020720 21280000 */  addu       $a1, $zero, $zero
    /* 10F24 80020724 21300000 */  addu       $a2, $zero, $zero
    /* 10F28 80020728 1C85000C */  jal        CD_cw
    /* 10F2C 8002072C 21380000 */   addu      $a3, $zero, $zero
  .L80020730:
    /* 10F30 80020730 0B002012 */  beqz       $s1, .L80020760
    /* 10F34 80020734 00000000 */   nop
    /* 10F38 80020738 0000A28E */  lw         $v0, 0x0($s5)
    /* 10F3C 8002073C 00000000 */  nop
    /* 10F40 80020740 07004010 */  beqz       $v0, .L80020760
    /* 10F44 80020744 02000424 */   addiu     $a0, $zero, 0x2
    /* 10F48 80020748 21282002 */  addu       $a1, $s1, $zero
    /* 10F4C 8002074C 21300000 */  addu       $a2, $zero, $zero
    /* 10F50 80020750 1C85000C */  jal        CD_cw
    /* 10F54 80020754 21380000 */   addu      $a3, $zero, $zero
    /* 10F58 80020758 0A004014 */  bnez       $v0, .L80020784
    /* 10F5C 8002075C 00000000 */   nop
  .L80020760:
    /* 10F60 80020760 0380013C */  lui        $at, %hi(D_800321FC)
    /* 10F64 80020764 FC2134AC */  sw         $s4, %lo(D_800321FC)($at)
    /* 10F68 80020768 FF006432 */  andi       $a0, $s3, 0xFF
    /* 10F6C 8002076C 21282002 */  addu       $a1, $s1, $zero
    /* 10F70 80020770 21300000 */  addu       $a2, $zero, $zero
    /* 10F74 80020774 1C85000C */  jal        CD_cw
    /* 10F78 80020778 01000724 */   addiu     $a3, $zero, 0x1
    /* 10F7C 8002077C 08004010 */  beqz       $v0, .L800207A0
    /* 10F80 80020780 0100C226 */   addiu     $v0, $s6, 0x1
  .L80020784:
    /* 10F84 80020784 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 10F88 80020788 DCFF1716 */  bne        $s0, $s7, .L800206FC
    /* 10F8C 8002078C 00000000 */   nop
    /* 10F90 80020790 0380013C */  lui        $at, %hi(D_800321FC)
    /* 10F94 80020794 FC2134AC */  sw         $s4, %lo(D_800321FC)($at)
    /* 10F98 80020798 FFFF1624 */  addiu      $s6, $zero, -0x1
    /* 10F9C 8002079C 0100C226 */  addiu      $v0, $s6, 0x1
  .L800207A0:
    /* 10FA0 800207A0 3400BF8F */  lw         $ra, 0x34($sp)
    /* 10FA4 800207A4 3000BE8F */  lw         $fp, 0x30($sp)
    /* 10FA8 800207A8 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 10FAC 800207AC 2800B68F */  lw         $s6, 0x28($sp)
    /* 10FB0 800207B0 2400B58F */  lw         $s5, 0x24($sp)
    /* 10FB4 800207B4 2000B48F */  lw         $s4, 0x20($sp)
    /* 10FB8 800207B8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 10FBC 800207BC 1800B28F */  lw         $s2, 0x18($sp)
    /* 10FC0 800207C0 1400B18F */  lw         $s1, 0x14($sp)
    /* 10FC4 800207C4 1000B08F */  lw         $s0, 0x10($sp)
    /* 10FC8 800207C8 0800E003 */  jr         $ra
    /* 10FCC 800207CC 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel CdControlF
