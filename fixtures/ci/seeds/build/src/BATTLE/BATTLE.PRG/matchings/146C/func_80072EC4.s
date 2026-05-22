nonmatching func_80072EC4, 0x1F8

glabel func_80072EC4
    /* A6C4 80072EC4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* A6C8 80072EC8 2400B3AF */  sw         $s3, 0x24($sp)
    /* A6CC 80072ECC 21988000 */  addu       $s3, $a0, $zero
    /* A6D0 80072ED0 1800B0AF */  sw         $s0, 0x18($sp)
    /* A6D4 80072ED4 2180A000 */  addu       $s0, $a1, $zero
    /* A6D8 80072ED8 4C080524 */  addiu      $a1, $zero, 0x84C
    /* A6DC 80072EDC 0F80033C */  lui        $v1, %hi(D_800F196C)
    /* A6E0 80072EE0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* A6E4 80072EE4 0F80113C */  lui        $s1, %hi(D_800F19CC)
    /* A6E8 80072EE8 CC19248E */  lw         $a0, %lo(D_800F19CC)($s1)
    /* A6EC 80072EEC 02000224 */  addiu      $v0, $zero, 0x2
    /* A6F0 80072EF0 2800BFAF */  sw         $ra, 0x28($sp)
    /* A6F4 80072EF4 2000B2AF */  sw         $s2, 0x20($sp)
    /* A6F8 80072EF8 6C1962AC */  sw         $v0, %lo(D_800F196C)($v1)
    /* A6FC 80072EFC 4424010C */  jal        vs_main_bzero
    /* A700 80072F00 08008424 */   addiu     $a0, $a0, 0x8
    /* A704 80072F04 CC19228E */  lw         $v0, %lo(D_800F19CC)($s1)
    /* A708 80072F08 00000000 */  nop
    /* A70C 80072F0C 0C0053A0 */  sb         $s3, 0xC($v0)
    /* A710 80072F10 CC19238E */  lw         $v1, %lo(D_800F19CC)($s1)
    /* A714 80072F14 4C0040AC */  sw         $zero, 0x4C($v0)
    /* A718 80072F18 C4BB010C */  jal        func_8006EF10
    /* A71C 80072F1C 080070A4 */   sh        $s0, 0x8($v1)
    /* A720 80072F20 2823020C */  jal        func_80088CA0
    /* A724 80072F24 00000000 */   nop
    /* A728 80072F28 04006012 */  beqz       $s3, .L80072F3C
    /* A72C 80072F2C 01000224 */   addiu     $v0, $zero, 0x1
    /* A730 80072F30 CC19228E */  lw         $v0, %lo(D_800F19CC)($s1)
    /* A734 80072F34 D2CB0108 */  j          .L80072F48
    /* A738 80072F38 842940AC */   sw        $zero, 0x2984($v0)
  .L80072F3C:
    /* A73C 80072F3C CC19238E */  lw         $v1, %lo(D_800F19CC)($s1)
    /* A740 80072F40 00000000 */  nop
    /* A744 80072F44 842962AC */  sw         $v0, 0x2984($v1)
  .L80072F48:
    /* A748 80072F48 0F80113C */  lui        $s1, %hi(D_800F19CC)
    /* A74C 80072F4C CC19238E */  lw         $v1, %lo(D_800F19CC)($s1)
    /* A750 80072F50 FF000224 */  addiu      $v0, $zero, 0xFF
    /* A754 80072F54 8D2962A0 */  sb         $v0, 0x298D($v1)
    /* A758 80072F58 8C2962A0 */  sb         $v0, 0x298C($v1)
    /* A75C 80072F5C 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* A760 80072F60 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* A764 80072F64 80101300 */  sll        $v0, $s3, 2
    /* A768 80072F68 21104300 */  addu       $v0, $v0, $v1
    /* A76C 80072F6C 0000448C */  lw         $a0, 0x0($v0)
    /* A770 80072F70 CC19238E */  lw         $v1, %lo(D_800F19CC)($s1)
    /* A774 80072F74 10008290 */  lbu        $v0, 0x10($a0)
    /* A778 80072F78 00000000 */  nop
    /* A77C 80072F7C C92962A0 */  sb         $v0, 0x29C9($v1)
    /* A780 80072F80 CC19238E */  lw         $v1, %lo(D_800F19CC)($s1)
    /* A784 80072F84 12008290 */  lbu        $v0, 0x12($a0)
    /* A788 80072F88 00000000 */  nop
    /* A78C 80072F8C CA2962A0 */  sb         $v0, 0x29CA($v1)
    /* A790 80072F90 CC19228E */  lw         $v0, %lo(D_800F19CC)($s1)
    /* A794 80072F94 00000000 */  nop
    /* A798 80072F98 8E2940A0 */  sb         $zero, 0x298E($v0)
    /* A79C 80072F9C CC19238E */  lw         $v1, %lo(D_800F19CC)($s1)
    /* A7A0 80072FA0 520040A4 */  sh         $zero, 0x52($v0)
    /* A7A4 80072FA4 0C006490 */  lbu        $a0, 0xC($v1)
    /* A7A8 80072FA8 7179020C */  jal        func_8009E5C4
    /* A7AC 80072FAC 040060AC */   sw        $zero, 0x4($v1)
    /* A7B0 80072FB0 CC19228E */  lw         $v0, %lo(D_800F19CC)($s1)
    /* A7B4 80072FB4 00000000 */  nop
    /* A7B8 80072FB8 8429428C */  lw         $v0, 0x2984($v0)
    /* A7BC 80072FBC 00000000 */  nop
    /* A7C0 80072FC0 09004010 */  beqz       $v0, .L80072FE8
    /* A7C4 80072FC4 00000000 */   nop
    /* A7C8 80072FC8 C700030C */  jal        func_800C031C
    /* A7CC 80072FCC 00000000 */   nop
    /* A7D0 80072FD0 1000A0AF */  sw         $zero, 0x10($sp)
    /* A7D4 80072FD4 0D000424 */  addiu      $a0, $zero, 0xD
    /* A7D8 80072FD8 04000524 */  addiu      $a1, $zero, 0x4
    /* A7DC 80072FDC FCFF0624 */  addiu      $a2, $zero, -0x4
    /* A7E0 80072FE0 43EC010C */  jal        func_8007B10C
    /* A7E4 80072FE4 2138C000 */   addu      $a3, $a2, $zero
  .L80072FE8:
    /* A7E8 80072FE8 94B0010C */  jal        func_8006C250
    /* A7EC 80072FEC 21800000 */   addu      $s0, $zero, $zero
    /* A7F0 80072FF0 21902002 */  addu       $s2, $s1, $zero
    /* A7F4 80072FF4 FBFF1124 */  addiu      $s1, $zero, -0x5
  .L80072FF8:
    /* A7F8 80072FF8 CC19428E */  lw         $v0, %lo(D_800F19CC)($s2)
    /* A7FC 80072FFC 00000000 */  nop
    /* A800 80073000 0C004290 */  lbu        $v0, 0xC($v0)
    /* A804 80073004 00000000 */  nop
    /* A808 80073008 09000212 */  beq        $s0, $v0, .L80073030
    /* A80C 8007300C 00000000 */   nop
    /* A810 80073010 F882020C */  jal        func_800A0BE0
    /* A814 80073014 21200002 */   addu      $a0, $s0, $zero
    /* A818 80073018 21284000 */  addu       $a1, $v0, $zero
    /* A81C 8007301C 0400A230 */  andi       $v0, $a1, 0x4
    /* A820 80073020 03004010 */  beqz       $v0, .L80073030
    /* A824 80073024 21200002 */   addu      $a0, $s0, $zero
    /* A828 80073028 1F82020C */  jal        func_800A087C
    /* A82C 8007302C 2428B100 */   and       $a1, $a1, $s1
  .L80073030:
    /* A830 80073030 01001026 */  addiu      $s0, $s0, 0x1
    /* A834 80073034 1000022A */  slti       $v0, $s0, 0x10
    /* A838 80073038 EFFF4014 */  bnez       $v0, .L80072FF8
    /* A83C 8007303C 00000000 */   nop
    /* A840 80073040 03006016 */  bnez       $s3, .L80073050
    /* A844 80073044 00000000 */   nop
    /* A848 80073048 322D020C */  jal        func_8008B4C8
    /* A84C 8007304C 21200000 */   addu      $a0, $zero, $zero
  .L80073050:
    /* A850 80073050 2F2D020C */  jal        func_8008B4BC
    /* A854 80073054 01000424 */   addiu     $a0, $zero, 0x1
    /* A858 80073058 6535020C */  jal        func_8008D594
    /* A85C 8007305C 01000424 */   addiu     $a0, $zero, 0x1
    /* A860 80073060 0F80103C */  lui        $s0, %hi(D_800F19CC)
    /* A864 80073064 CC19028E */  lw         $v0, %lo(D_800F19CC)($s0)
    /* A868 80073068 00000000 */  nop
    /* A86C 8007306C 8429428C */  lw         $v0, 0x2984($v0)
    /* A870 80073070 00000000 */  nop
    /* A874 80073074 03004010 */  beqz       $v0, .L80073084
    /* A878 80073078 00000000 */   nop
    /* A87C 8007307C DC56020C */  jal        func_80095B70
    /* A880 80073080 01000424 */   addiu     $a0, $zero, 0x1
  .L80073084:
    /* A884 80073084 CC19028E */  lw         $v0, %lo(D_800F19CC)($s0)
    /* A888 80073088 00000000 */  nop
    /* A88C 8007308C 08004494 */  lhu        $a0, 0x8($v0)
    /* A890 80073090 EACA010C */  jal        func_80072BA8
    /* A894 80073094 00000000 */   nop
    /* A898 80073098 FB23010C */  jal        vs_main_setClutState
    /* A89C 8007309C 21200000 */   addu      $a0, $zero, $zero
    /* A8A0 800730A0 2800BF8F */  lw         $ra, 0x28($sp)
    /* A8A4 800730A4 2400B38F */  lw         $s3, 0x24($sp)
    /* A8A8 800730A8 2000B28F */  lw         $s2, 0x20($sp)
    /* A8AC 800730AC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* A8B0 800730B0 1800B08F */  lw         $s0, 0x18($sp)
    /* A8B4 800730B4 0800E003 */  jr         $ra
    /* A8B8 800730B8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80072EC4
