nonmatching func_800D1EF0, 0xFC

glabel func_800D1EF0
    /* 696F0 800D1EF0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 696F4 800D1EF4 0F80023C */  lui        $v0, %hi(D_800F54B8)
    /* 696F8 800D1EF8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 696FC 800D1EFC B8545024 */  addiu      $s0, $v0, %lo(D_800F54B8)
    /* 69700 800D1F00 2800B6AF */  sw         $s6, 0x28($sp)
    /* 69704 800D1F04 4800B68F */  lw         $s6, 0x48($sp)
    /* 69708 800D1F08 4C00A28F */  lw         $v0, 0x4C($sp)
    /* 6970C 800D1F0C 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 69710 800D1F10 21B88000 */  addu       $s7, $a0, $zero
    /* 69714 800D1F14 3000BEAF */  sw         $fp, 0x30($sp)
    /* 69718 800D1F18 21F0C000 */  addu       $fp, $a2, $zero
    /* 6971C 800D1F1C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 69720 800D1F20 21880000 */  addu       $s1, $zero, $zero
    /* 69724 800D1F24 2000B4AF */  sw         $s4, 0x20($sp)
    /* 69728 800D1F28 1F00B430 */  andi       $s4, $a1, 0x1F
    /* 6972C 800D1F2C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 69730 800D1F30 5000B58F */  lw         $s5, 0x50($sp)
    /* 69734 800D1F34 0100E730 */  andi       $a3, $a3, 0x1
    /* 69738 800D1F38 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6973C 800D1F3C 40990700 */  sll        $s3, $a3, 5
    /* 69740 800D1F40 3400BFAF */  sw         $ra, 0x34($sp)
    /* 69744 800D1F44 1800B2AF */  sw         $s2, 0x18($sp)
    /* 69748 800D1F48 01004230 */  andi       $v0, $v0, 0x1
    /* 6974C 800D1F4C 80910200 */  sll        $s2, $v0, 6
  .L800D1F50:
    /* 69750 800D1F50 07103702 */  srav       $v0, $s7, $s1
    /* 69754 800D1F54 01004230 */  andi       $v0, $v0, 0x1
    /* 69758 800D1F58 14004010 */  beqz       $v0, .L800D1FAC
    /* 6975C 800D1F5C 21200002 */   addu      $a0, $s0, $zero
    /* 69760 800D1F60 01000292 */  lbu        $v0, 0x1($s0)
    /* 69764 800D1F64 04001EA2 */  sb         $fp, 0x4($s0)
    /* 69768 800D1F68 020016A2 */  sb         $s6, 0x2($s0)
    /* 6976C 800D1F6C 030015A2 */  sb         $s5, 0x3($s0)
    /* 69770 800D1F70 000000A2 */  sb         $zero, 0x0($s0)
    /* 69774 800D1F74 E0004230 */  andi       $v0, $v0, 0xE0
    /* 69778 800D1F78 25105400 */  or         $v0, $v0, $s4
    /* 6977C 800D1F7C 010002A2 */  sb         $v0, 0x1($s0)
    /* 69780 800D1F80 DF004230 */  andi       $v0, $v0, 0xDF
    /* 69784 800D1F84 25105300 */  or         $v0, $v0, $s3
    /* 69788 800D1F88 010002A2 */  sb         $v0, 0x1($s0)
    /* 6978C 800D1F8C BF004230 */  andi       $v0, $v0, 0xBF
    /* 69790 800D1F90 25105200 */  or         $v0, $v0, $s2
    /* 69794 800D1F94 9E47030C */  jal        func_800D1E78
    /* 69798 800D1F98 010002A2 */   sb        $v0, 0x1($s0)
    /* 6979C 800D1F9C 01000424 */  addiu      $a0, $zero, 0x1
    /* 697A0 800D1FA0 04202402 */  sllv       $a0, $a0, $s1
    /* 697A4 800D1FA4 7947030C */  jal        func_800D1DE4
    /* 697A8 800D1FA8 050002A2 */   sb        $v0, 0x5($s0)
  .L800D1FAC:
    /* 697AC 800D1FAC 01003126 */  addiu      $s1, $s1, 0x1
    /* 697B0 800D1FB0 0400222A */  slti       $v0, $s1, 0x4
    /* 697B4 800D1FB4 E6FF4014 */  bnez       $v0, .L800D1F50
    /* 697B8 800D1FB8 06001026 */   addiu     $s0, $s0, 0x6
    /* 697BC 800D1FBC 3400BF8F */  lw         $ra, 0x34($sp)
    /* 697C0 800D1FC0 3000BE8F */  lw         $fp, 0x30($sp)
    /* 697C4 800D1FC4 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 697C8 800D1FC8 2800B68F */  lw         $s6, 0x28($sp)
    /* 697CC 800D1FCC 2400B58F */  lw         $s5, 0x24($sp)
    /* 697D0 800D1FD0 2000B48F */  lw         $s4, 0x20($sp)
    /* 697D4 800D1FD4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 697D8 800D1FD8 1800B28F */  lw         $s2, 0x18($sp)
    /* 697DC 800D1FDC 1400B18F */  lw         $s1, 0x14($sp)
    /* 697E0 800D1FE0 1000B08F */  lw         $s0, 0x10($sp)
    /* 697E4 800D1FE4 0800E003 */  jr         $ra
    /* 697E8 800D1FE8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800D1EF0
