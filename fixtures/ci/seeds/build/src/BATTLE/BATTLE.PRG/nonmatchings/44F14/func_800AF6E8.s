nonmatching func_800AF6E8, 0x15C

glabel func_800AF6E8
    /* 46EE8 800AF6E8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 46EEC 800AF6EC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 46EF0 800AF6F0 21808000 */  addu       $s0, $a0, $zero
    /* 46EF4 800AF6F4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 46EF8 800AF6F8 540C1126 */  addiu      $s1, $s0, 0xC54
    /* 46EFC 800AF6FC 21282002 */  addu       $a1, $s1, $zero
    /* 46F00 800AF700 21300000 */  addu       $a2, $zero, $zero
    /* 46F04 800AF704 2400BFAF */  sw         $ra, 0x24($sp)
    /* 46F08 800AF708 8ABE020C */  jal        func_800AFA28
    /* 46F0C 800AF70C 2000B2AF */   sw        $s2, 0x20($sp)
    /* 46F10 800AF710 CC050292 */  lbu        $v0, 0x5CC($s0)
    /* 46F14 800AF714 00000000 */  nop
    /* 46F18 800AF718 3C004010 */  beqz       $v0, .L800AF80C
    /* 46F1C 800AF71C 01001224 */   addiu     $s2, $zero, 0x1
    /* 46F20 800AF720 04005214 */  bne        $v0, $s2, .L800AF734
    /* 46F24 800AF724 04070426 */   addiu     $a0, $s0, 0x704
    /* 46F28 800AF728 00000692 */  lbu        $a2, 0x0($s0)
    /* 46F2C 800AF72C 11BE020C */  jal        func_800AF844
    /* 46F30 800AF730 21282002 */   addu      $a1, $s1, $zero
  .L800AF734:
    /* 46F34 800AF734 B2050392 */  lbu        $v1, 0x5B2($s0)
    /* 46F38 800AF738 00000000 */  nop
    /* 46F3C 800AF73C 0E007210 */  beq        $v1, $s2, .L800AF778
    /* 46F40 800AF740 04070426 */   addiu     $a0, $s0, 0x704
    /* 46F44 800AF744 CC050292 */  lbu        $v0, 0x5CC($s0)
    /* 46F48 800AF748 00000000 */  nop
    /* 46F4C 800AF74C FF004224 */  addiu      $v0, $v0, 0xFF
    /* 46F50 800AF750 21106200 */  addu       $v0, $v1, $v0
    /* 46F54 800AF754 CD050392 */  lbu        $v1, 0x5CD($s0)
    /* 46F58 800AF758 CC0502A2 */  sb         $v0, 0x5CC($s0)
    /* 46F5C 800AF75C FF004230 */  andi       $v0, $v0, 0xFF
    /* 46F60 800AF760 2B104300 */  sltu       $v0, $v0, $v1
    /* 46F64 800AF764 04004014 */  bnez       $v0, .L800AF778
    /* 46F68 800AF768 00000000 */   nop
    /* 46F6C 800AF76C CC0500A2 */  sb         $zero, 0x5CC($s0)
    /* 46F70 800AF770 04BE0208 */  j          .L800AF810
    /* 46F74 800AF774 CD0500A2 */   sb        $zero, 0x5CD($s0)
  .L800AF778:
    /* 46F78 800AF778 00000692 */  lbu        $a2, 0x0($s0)
    /* 46F7C 800AF77C CC050792 */  lbu        $a3, 0x5CC($s0)
    /* 46F80 800AF780 CD050292 */  lbu        $v0, 0x5CD($s0)
    /* 46F84 800AF784 540C0526 */  addiu      $a1, $s0, 0xC54
    /* 46F88 800AF788 1FC5020C */  jal        func_800B147C
    /* 46F8C 800AF78C 1000A2AF */   sw        $v0, 0x10($sp)
    /* 46F90 800AF790 FEFF033C */  lui        $v1, (0xFFFEFFFF >> 16)
    /* 46F94 800AF794 FFFF6334 */  ori        $v1, $v1, (0xFFFEFFFF & 0xFFFF)
    /* 46F98 800AF798 FDFF073C */  lui        $a3, (0xFFFDFFFF >> 16)
    /* 46F9C 800AF79C FFFFE734 */  ori        $a3, $a3, (0xFFFDFFFF & 0xFFFF)
    /* 46FA0 800AF7A0 21200002 */  addu       $a0, $s0, $zero
    /* 46FA4 800AF7A4 21280000 */  addu       $a1, $zero, $zero
    /* 46FA8 800AF7A8 4C0C068E */  lw         $a2, 0xC4C($s0)
    /* 46FAC 800AF7AC 9E110296 */  lhu        $v0, 0x119E($s0)
    /* 46FB0 800AF7B0 2430C300 */  and        $a2, $a2, $v1
    /* 46FB4 800AF7B4 01004230 */  andi       $v0, $v0, 0x1
    /* 46FB8 800AF7B8 00140200 */  sll        $v0, $v0, 16
    /* 46FBC 800AF7BC 2530C200 */  or         $a2, $a2, $v0
    /* 46FC0 800AF7C0 2438C700 */  and        $a3, $a2, $a3
    /* 46FC4 800AF7C4 9C11028E */  lw         $v0, 0x119C($s0)
    /* 46FC8 800AF7C8 0200033C */  lui        $v1, (0x20000 >> 16)
    /* 46FCC 800AF7CC 4C0C06AE */  sw         $a2, 0xC4C($s0)
    /* 46FD0 800AF7D0 24104300 */  and        $v0, $v0, $v1
    /* 46FD4 800AF7D4 2538E200 */  or         $a3, $a3, $v0
    /* 46FD8 800AF7D8 0BC0020C */  jal        func_800B002C
    /* 46FDC 800AF7DC 4C0C07AE */   sw        $a3, 0xC4C($s0)
    /* 46FE0 800AF7E0 CC050292 */  lbu        $v0, 0x5CC($s0)
    /* 46FE4 800AF7E4 CD050392 */  lbu        $v1, 0x5CD($s0)
    /* 46FE8 800AF7E8 01004224 */  addiu      $v0, $v0, 0x1
    /* 46FEC 800AF7EC CC0502A2 */  sb         $v0, 0x5CC($s0)
    /* 46FF0 800AF7F0 FF004230 */  andi       $v0, $v0, 0xFF
    /* 46FF4 800AF7F4 2B104300 */  sltu       $v0, $v0, $v1
    /* 46FF8 800AF7F8 0B004014 */  bnez       $v0, .L800AF828
    /* 46FFC 800AF7FC 00000000 */   nop
    /* 47000 800AF800 CC0500A2 */  sb         $zero, 0x5CC($s0)
    /* 47004 800AF804 0ABE0208 */  j          .L800AF828
    /* 47008 800AF808 CD0500A2 */   sb        $zero, 0x5CD($s0)
  .L800AF80C:
    /* 4700C 800AF80C 04070426 */  addiu      $a0, $s0, 0x704
  .L800AF810:
    /* 47010 800AF810 540C0526 */  addiu      $a1, $s0, 0xC54
    /* 47014 800AF814 2C24010C */  jal        vs_main_memcpy
    /* 47018 800AF818 50050624 */   addiu     $a2, $zero, 0x550
    /* 4701C 800AF81C 21200002 */  addu       $a0, $s0, $zero
    /* 47020 800AF820 0BC0020C */  jal        func_800B002C
    /* 47024 800AF824 21280000 */   addu      $a1, $zero, $zero
  .L800AF828:
    /* 47028 800AF828 2400BF8F */  lw         $ra, 0x24($sp)
    /* 4702C 800AF82C 2000B28F */  lw         $s2, 0x20($sp)
    /* 47030 800AF830 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 47034 800AF834 1800B08F */  lw         $s0, 0x18($sp)
    /* 47038 800AF838 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 4703C 800AF83C 0800E003 */  jr         $ra
    /* 47040 800AF840 00000000 */   nop
endlabel func_800AF6E8
