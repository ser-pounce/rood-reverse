nonmatching _combineShields, 0x274

glabel _combineShields
    /* 8D98 8010B598 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 8D9C 8010B59C 2800B4AF */  sw         $s4, 0x28($sp)
    /* 8DA0 8010B5A0 21A08000 */  addu       $s4, $a0, $zero
    /* 8DA4 8010B5A4 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 8DA8 8010B5A8 21A8A000 */  addu       $s5, $a1, $zero
    /* 8DAC 8010B5AC 2400B3AF */  sw         $s3, 0x24($sp)
    /* 8DB0 8010B5B0 2198C000 */  addu       $s3, $a2, $zero
    /* 8DB4 8010B5B4 21206002 */  addu       $a0, $s3, $zero
    /* 8DB8 8010B5B8 21288002 */  addu       $a1, $s4, $zero
    /* 8DBC 8010B5BC 28000624 */  addiu      $a2, $zero, 0x28
    /* 8DC0 8010B5C0 3000BFAF */  sw         $ra, 0x30($sp)
    /* 8DC4 8010B5C4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 8DC8 8010B5C8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 8DCC 8010B5CC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 8DD0 8010B5D0 0000E28C */  lw         $v0, 0x0($a3)
    /* 8DD4 8010B5D4 1180113C */  lui        $s1, %hi(_combinationResults)
    /* 8DD8 8010B5D8 2110E200 */  addu       $v0, $a3, $v0
    /* 8DDC 8010B5DC 80BD22AE */  sw         $v0, %lo(_combinationResults)($s1)
    /* 8DE0 8010B5E0 0400E28C */  lw         $v0, 0x4($a3)
    /* 8DE4 8010B5E4 1180103C */  lui        $s0, %hi(_materialResults)
    /* 8DE8 8010B5E8 2110E200 */  addu       $v0, $a3, $v0
    /* 8DEC 8010B5EC 84BD02AE */  sw         $v0, %lo(_materialResults)($s0)
    /* 8DF0 8010B5F0 0800E28C */  lw         $v0, 0x8($a3)
    /* 8DF4 8010B5F4 1180123C */  lui        $s2, %hi(_shieldCombinationInitData)
    /* 8DF8 8010B5F8 2138E200 */  addu       $a3, $a3, $v0
    /* 8DFC 8010B5FC 2C24010C */  jal        vs_main_memcpy
    /* 8E00 8010B600 8CBD47AE */   sw        $a3, %lo(_shieldCombinationInitData)($s2)
    /* 8E04 8010B604 24008396 */  lhu        $v1, 0x24($s4)
    /* 8E08 8010B608 2400A496 */  lhu        $a0, 0x24($s5)
    /* 8E0C 8010B60C 84BD028E */  lw         $v0, %lo(_materialResults)($s0)
    /* 8E10 8010B610 C0180300 */  sll        $v1, $v1, 3
    /* 8E14 8010B614 21186400 */  addu       $v1, $v1, $a0
    /* 8E18 8010B618 21104300 */  addu       $v0, $v0, $v1
    /* 8E1C 8010B61C 00004290 */  lbu        $v0, 0x0($v0)
    /* 8E20 8010B620 00000000 */  nop
    /* 8E24 8010B624 240062A6 */  sh         $v0, 0x24($s3)
    /* 8E28 8010B628 01008292 */  lbu        $v0, 0x1($s4)
    /* 8E2C 8010B62C 0100A492 */  lbu        $a0, 0x1($s5)
    /* 8E30 8010B630 00190200 */  sll        $v1, $v0, 4
    /* 8E34 8010B634 21186200 */  addu       $v1, $v1, $v0
    /* 8E38 8010B638 80BD228E */  lw         $v0, %lo(_combinationResults)($s1)
    /* 8E3C 8010B63C 21186400 */  addu       $v1, $v1, $a0
    /* 8E40 8010B640 21104300 */  addu       $v0, $v0, $v1
    /* 8E44 8010B644 00004290 */  lbu        $v0, 0x0($v0)
    /* 8E48 8010B648 24006396 */  lhu        $v1, 0x24($s3)
    /* 8E4C 8010B64C 010062A2 */  sb         $v0, 0x1($s3)
    /* 8E50 8010B650 7E004224 */  addiu      $v0, $v0, 0x7E
    /* 8E54 8010B654 000062A2 */  sb         $v0, 0x0($s3)
    /* 8E58 8010B658 01006292 */  lbu        $v0, 0x1($s3)
    /* 8E5C 8010B65C 8CBD448E */  lw         $a0, %lo(_shieldCombinationInitData)($s2)
    /* 8E60 8010B660 C0100200 */  sll        $v0, $v0, 3
    /* 8E64 8010B664 21208200 */  addu       $a0, $a0, $v0
    /* 8E68 8010B668 01008290 */  lbu        $v0, 0x1($a0)
    /* 8E6C 8010B66C 00000000 */  nop
    /* 8E70 8010B670 020062A2 */  sb         $v0, 0x2($s3)
    /* 8E74 8010B674 02008290 */  lbu        $v0, 0x2($a0)
    /* 8E78 8010B678 0580063C */  lui        $a2, %hi(vs_main_materialModifiers)
    /* 8E7C 8010B67C 030062A2 */  sb         $v0, 0x3($s3)
    /* 8E80 8010B680 03008290 */  lbu        $v0, 0x3($a0)
    /* 8E84 8010B684 DCEDC624 */  addiu      $a2, $a2, %lo(vs_main_materialModifiers)
    /* 8E88 8010B688 0C0062A2 */  sb         $v0, 0xC($s3)
    /* 8E8C 8010B68C 00110300 */  sll        $v0, $v1, 4
    /* 8E90 8010B690 23104300 */  subu       $v0, $v0, $v1
    /* 8E94 8010B694 40100200 */  sll        $v0, $v0, 1
    /* 8E98 8010B698 21104600 */  addu       $v0, $v0, $a2
    /* 8E9C 8010B69C 04008390 */  lbu        $v1, 0x4($a0)
    /* 8EA0 8010B6A0 18004290 */  lbu        $v0, 0x18($v0)
    /* 8EA4 8010B6A4 24006596 */  lhu        $a1, 0x24($s3)
    /* 8EA8 8010B6A8 21186200 */  addu       $v1, $v1, $v0
    /* 8EAC 8010B6AC 00110500 */  sll        $v0, $a1, 4
    /* 8EB0 8010B6B0 23104500 */  subu       $v0, $v0, $a1
    /* 8EB4 8010B6B4 40100200 */  sll        $v0, $v0, 1
    /* 8EB8 8010B6B8 21104600 */  addu       $v0, $v0, $a2
    /* 8EBC 8010B6BC 0D0063A2 */  sb         $v1, 0xD($s3)
    /* 8EC0 8010B6C0 05008390 */  lbu        $v1, 0x5($a0)
    /* 8EC4 8010B6C4 1A004290 */  lbu        $v0, 0x1A($v0)
    /* 8EC8 8010B6C8 00000000 */  nop
    /* 8ECC 8010B6CC 21186200 */  addu       $v1, $v1, $v0
    /* 8ED0 8010B6D0 00110500 */  sll        $v0, $a1, 4
    /* 8ED4 8010B6D4 23104500 */  subu       $v0, $v0, $a1
    /* 8ED8 8010B6D8 40100200 */  sll        $v0, $v0, 1
    /* 8EDC 8010B6DC 21104600 */  addu       $v0, $v0, $a2
    /* 8EE0 8010B6E0 0E0063A2 */  sb         $v1, 0xE($s3)
    /* 8EE4 8010B6E4 06008390 */  lbu        $v1, 0x6($a0)
    /* 8EE8 8010B6E8 1C004290 */  lbu        $v0, 0x1C($v0)
    /* 8EEC 8010B6EC 00000000 */  nop
    /* 8EF0 8010B6F0 21186200 */  addu       $v1, $v1, $v0
    /* 8EF4 8010B6F4 0F0063A2 */  sb         $v1, 0xF($s3)
    /* 8EF8 8010B6F8 04008296 */  lhu        $v0, 0x4($s4)
    /* 8EFC 8010B6FC 0400A396 */  lhu        $v1, 0x4($s5)
    /* 8F00 8010B700 00000000 */  nop
    /* 8F04 8010B704 21104300 */  addu       $v0, $v0, $v1
    /* 8F08 8010B708 43100200 */  sra        $v0, $v0, 1
    /* 8F0C 8010B70C 080062A6 */  sh         $v0, 0x8($s3)
    /* 8F10 8010B710 040062A6 */  sh         $v0, 0x4($s3)
    /* 8F14 8010B714 06008296 */  lhu        $v0, 0x6($s4)
    /* 8F18 8010B718 0600A396 */  lhu        $v1, 0x6($s5)
    /* 8F1C 8010B71C 00000000 */  nop
    /* 8F20 8010B720 21104300 */  addu       $v0, $v0, $v1
    /* 8F24 8010B724 43100200 */  sra        $v0, $v0, 1
    /* 8F28 8010B728 060062A6 */  sh         $v0, 0x6($s3)
    /* 8F2C 8010B72C 0A008296 */  lhu        $v0, 0xA($s4)
    /* 8F30 8010B730 0A00A396 */  lhu        $v1, 0xA($s5)
    /* 8F34 8010B734 00000000 */  nop
    /* 8F38 8010B738 21104300 */  addu       $v0, $v0, $v1
    /* 8F3C 8010B73C 43100200 */  sra        $v0, $v0, 1
    /* 8F40 8010B740 0A0062A6 */  sh         $v0, 0xA($s3)
    /* 8F44 8010B744 24008396 */  lhu        $v1, 0x24($s4)
    /* 8F48 8010B748 2400A296 */  lhu        $v0, 0x24($s5)
    /* 8F4C 8010B74C 00000000 */  nop
    /* 8F50 8010B750 12006214 */  bne        $v1, $v0, .L8010B79C
    /* 8F54 8010B754 14008426 */   addiu     $a0, $s4, 0x14
    /* 8F58 8010B758 1400A526 */  addiu      $a1, $s5, 0x14
    /* 8F5C 8010B75C 14006626 */  addiu      $a2, $s3, 0x14
    /* 8F60 8010B760 21380000 */  addu       $a3, $zero, $zero
    /* 8F64 8010B764 8E2B040C */  jal        _setClassAffinities
    /* 8F68 8010B768 1000A0AF */   sw        $zero, 0x10($sp)
    /* 8F6C 8010B76C 1C008426 */  addiu      $a0, $s4, 0x1C
    /* 8F70 8010B770 1C00A526 */  addiu      $a1, $s5, 0x1C
    /* 8F74 8010B774 1C006626 */  addiu      $a2, $s3, 0x1C
    /* 8F78 8010B778 21380000 */  addu       $a3, $zero, $zero
    /* 8F7C 8010B77C 01000224 */  addiu      $v0, $zero, 0x1
    /* 8F80 8010B780 8E2B040C */  jal        _setClassAffinities
    /* 8F84 8010B784 1000A2AF */   sw        $v0, 0x10($sp)
    /* 8F88 8010B788 10008426 */  addiu      $a0, $s4, 0x10
    /* 8F8C 8010B78C 1000A526 */  addiu      $a1, $s5, 0x10
    /* 8F90 8010B790 10006626 */  addiu      $a2, $s3, 0x10
    /* 8F94 8010B794 F72D0408 */  j          .L8010B7DC
    /* 8F98 8010B798 21380000 */   addu      $a3, $zero, $zero
  .L8010B79C:
    /* 8F9C 8010B79C 1400A526 */  addiu      $a1, $s5, 0x14
    /* 8FA0 8010B7A0 14006626 */  addiu      $a2, $s3, 0x14
    /* 8FA4 8010B7A4 01000724 */  addiu      $a3, $zero, 0x1
    /* 8FA8 8010B7A8 8E2B040C */  jal        _setClassAffinities
    /* 8FAC 8010B7AC 1000A0AF */   sw        $zero, 0x10($sp)
    /* 8FB0 8010B7B0 1C008426 */  addiu      $a0, $s4, 0x1C
    /* 8FB4 8010B7B4 1C00A526 */  addiu      $a1, $s5, 0x1C
    /* 8FB8 8010B7B8 1C006626 */  addiu      $a2, $s3, 0x1C
    /* 8FBC 8010B7BC 01000724 */  addiu      $a3, $zero, 0x1
    /* 8FC0 8010B7C0 2110E000 */  addu       $v0, $a3, $zero
    /* 8FC4 8010B7C4 8E2B040C */  jal        _setClassAffinities
    /* 8FC8 8010B7C8 1000A2AF */   sw        $v0, 0x10($sp)
    /* 8FCC 8010B7CC 10008426 */  addiu      $a0, $s4, 0x10
    /* 8FD0 8010B7D0 1000A526 */  addiu      $a1, $s5, 0x10
    /* 8FD4 8010B7D4 10006626 */  addiu      $a2, $s3, 0x10
    /* 8FD8 8010B7D8 01000724 */  addiu      $a3, $zero, 0x1
  .L8010B7DC:
    /* 8FDC 8010B7DC 542C040C */  jal        _setTypeValues
    /* 8FE0 8010B7E0 00000000 */   nop
    /* 8FE4 8010B7E4 21106002 */  addu       $v0, $s3, $zero
    /* 8FE8 8010B7E8 3000BF8F */  lw         $ra, 0x30($sp)
    /* 8FEC 8010B7EC 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 8FF0 8010B7F0 2800B48F */  lw         $s4, 0x28($sp)
    /* 8FF4 8010B7F4 2400B38F */  lw         $s3, 0x24($sp)
    /* 8FF8 8010B7F8 2000B28F */  lw         $s2, 0x20($sp)
    /* 8FFC 8010B7FC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 9000 8010B800 1800B08F */  lw         $s0, 0x18($sp)
    /* 9004 8010B804 0800E003 */  jr         $ra
    /* 9008 8010B808 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _combineShields
