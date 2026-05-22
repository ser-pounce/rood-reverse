nonmatching func_8002E478, 0x264

glabel func_8002E478
    /* 1EC78 8002E478 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1EC7C 8002E47C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1EC80 8002E480 21808000 */  addu       $s0, $a0, $zero
    /* 1EC84 8002E484 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1EC88 8002E488 3C00028E */  lw         $v0, 0x3C($s0)
    /* 1EC8C 8002E48C 00000000 */  nop
    /* 1EC90 8002E490 00004390 */  lbu        $v1, 0x0($v0)
    /* 1EC94 8002E494 00000000 */  nop
    /* 1EC98 8002E498 F0006230 */  andi       $v0, $v1, 0xF0
    /* 1EC9C 8002E49C 10004014 */  bnez       $v0, .L8002E4E0
    /* 1ECA0 8002E4A0 02190300 */   srl       $v1, $v1, 4
    /* 1ECA4 8002E4A4 3000038E */  lw         $v1, 0x30($s0)
    /* 1ECA8 8002E4A8 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 1ECAC 8002E4AC 000062A0 */  sb         $v0, 0x0($v1)
    /* 1ECB0 8002E4B0 3000028E */  lw         $v0, 0x30($s0)
    /* 1ECB4 8002E4B4 00000000 */  nop
    /* 1ECB8 8002E4B8 010040A0 */  sb         $zero, 0x1($v0)
    /* 1ECBC 8002E4BC E80000A2 */  sb         $zero, 0xE8($s0)
    /* 1ECC0 8002E4C0 350000A2 */  sb         $zero, 0x35($s0)
    /* 1ECC4 8002E4C4 0380023C */  lui        $v0, %hi(D_800335A0)
    /* 1ECC8 8002E4C8 A035428C */  lw         $v0, %lo(D_800335A0)($v0)
    /* 1ECCC 8002E4CC 00000000 */  nop
    /* 1ECD0 8002E4D0 09F84000 */  jalr       $v0
    /* 1ECD4 8002E4D4 00000000 */   nop
    /* 1ECD8 8002E4D8 B3B90008 */  j          .L8002E6CC
    /* 1ECDC 8002E4DC 00000000 */   nop
  .L8002E4E0:
    /* 1ECE0 8002E4E0 E8000592 */  lbu        $a1, 0xE8($s0)
    /* 1ECE4 8002E4E4 0F000224 */  addiu      $v0, $zero, 0xF
    /* 1ECE8 8002E4E8 03006214 */  bne        $v1, $v0, .L8002E4F8
    /* 1ECEC 8002E4EC E80003A2 */   sb        $v1, 0xE8($s0)
    /* 1ECF0 8002E4F0 56B90008 */  j          .L8002E558
    /* 1ECF4 8002E4F4 E80005A2 */   sb        $a1, 0xE8($s0)
  .L8002E4F8:
    /* 1ECF8 8002E4F8 3000028E */  lw         $v0, 0x30($s0)
    /* 1ECFC 8002E4FC 00000000 */  nop
    /* 1ED00 8002E500 000040A0 */  sb         $zero, 0x0($v0)
    /* 1ED04 8002E504 3C00028E */  lw         $v0, 0x3C($s0)
    /* 1ED08 8002E508 3000038E */  lw         $v1, 0x30($s0)
    /* 1ED0C 8002E50C 00004290 */  lbu        $v0, 0x0($v0)
    /* 1ED10 8002E510 02000424 */  addiu      $a0, $zero, 0x2
    /* 1ED14 8002E514 010062A0 */  sb         $v0, 0x1($v1)
    /* 1ED18 8002E518 44000292 */  lbu        $v0, 0x44($s0)
    /* 1ED1C 8002E51C 44000392 */  lbu        $v1, 0x44($s0)
    /* 1ED20 8002E520 2A108200 */  slt        $v0, $a0, $v0
    /* 1ED24 8002E524 0C004010 */  beqz       $v0, .L8002E558
    /* 1ED28 8002E528 350003A2 */   sb        $v1, 0x35($s0)
  .L8002E52C:
    /* 1ED2C 8002E52C 3C00028E */  lw         $v0, 0x3C($s0)
    /* 1ED30 8002E530 3000038E */  lw         $v1, 0x30($s0)
    /* 1ED34 8002E534 21104400 */  addu       $v0, $v0, $a0
    /* 1ED38 8002E538 00004290 */  lbu        $v0, 0x0($v0)
    /* 1ED3C 8002E53C 21186400 */  addu       $v1, $v1, $a0
    /* 1ED40 8002E540 000062A0 */  sb         $v0, 0x0($v1)
    /* 1ED44 8002E544 44000292 */  lbu        $v0, 0x44($s0)
    /* 1ED48 8002E548 01008424 */  addiu      $a0, $a0, 0x1
    /* 1ED4C 8002E54C 2A108200 */  slt        $v0, $a0, $v0
    /* 1ED50 8002E550 F6FF4014 */  bnez       $v0, .L8002E52C
    /* 1ED54 8002E554 00000000 */   nop
  .L8002E558:
    /* 1ED58 8002E558 3C00028E */  lw         $v0, 0x3C($s0)
    /* 1ED5C 8002E55C 00000000 */  nop
    /* 1ED60 8002E560 01004290 */  lbu        $v0, 0x1($v0)
    /* 1ED64 8002E564 00000000 */  nop
    /* 1ED68 8002E568 0D004014 */  bnez       $v0, .L8002E5A0
    /* 1ED6C 8002E56C 01000224 */   addiu     $v0, $zero, 0x1
    /* 1ED70 8002E570 46000392 */  lbu        $v1, 0x46($s0)
    /* 1ED74 8002E574 00000000 */  nop
    /* 1ED78 8002E578 05006214 */  bne        $v1, $v0, .L8002E590
    /* 1ED7C 8002E57C 00000000 */   nop
    /* 1ED80 8002E580 1400028E */  lw         $v0, 0x14($s0)
    /* 1ED84 8002E584 00000000 */  nop
    /* 1ED88 8002E588 05004010 */  beqz       $v0, .L8002E5A0
    /* 1ED8C 8002E58C 00000000 */   nop
  .L8002E590:
    /* 1ED90 8002E590 50000292 */  lbu        $v0, 0x50($s0)
    /* 1ED94 8002E594 00000000 */  nop
    /* 1ED98 8002E598 05004010 */  beqz       $v0, .L8002E5B0
    /* 1ED9C 8002E59C 00000000 */   nop
  .L8002E5A0:
    /* 1EDA0 8002E5A0 E8000292 */  lbu        $v0, 0xE8($s0)
    /* 1EDA4 8002E5A4 00000000 */  nop
    /* 1EDA8 8002E5A8 06004510 */  beq        $v0, $a1, .L8002E5C4
    /* 1EDAC 8002E5AC 00000000 */   nop
  .L8002E5B0:
    /* 1EDB0 8002E5B0 0380023C */  lui        $v0, %hi(D_800335A0)
    /* 1EDB4 8002E5B4 A035428C */  lw         $v0, %lo(D_800335A0)($v0)
    /* 1EDB8 8002E5B8 00000000 */  nop
    /* 1EDBC 8002E5BC 09F84000 */  jalr       $v0
    /* 1EDC0 8002E5C0 21200002 */   addu      $a0, $s0, $zero
  .L8002E5C4:
    /* 1EDC4 8002E5C4 46000492 */  lbu        $a0, 0x46($s0)
    /* 1EDC8 8002E5C8 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 1EDCC 8002E5CC FF008330 */  andi       $v1, $a0, 0xFF
    /* 1EDD0 8002E5D0 3E006210 */  beq        $v1, $v0, .L8002E6CC
    /* 1EDD4 8002E5D4 4A0000A2 */   sb        $zero, 0x4A($s0)
    /* 1EDD8 8002E5D8 05006010 */  beqz       $v1, .L8002E5F0
    /* 1EDDC 8002E5DC FEFF8224 */   addiu     $v0, $a0, -0x2
    /* 1EDE0 8002E5E0 37000292 */  lbu        $v0, 0x37($s0)
    /* 1EDE4 8002E5E4 00000000 */  nop
    /* 1EDE8 8002E5E8 38004010 */  beqz       $v0, .L8002E6CC
    /* 1EDEC 8002E5EC FEFF8224 */   addiu     $v0, $a0, -0x2
  .L8002E5F0:
    /* 1EDF0 8002E5F0 FF004230 */  andi       $v0, $v0, 0xFF
    /* 1EDF4 8002E5F4 FC00422C */  sltiu      $v0, $v0, 0xFC
    /* 1EDF8 8002E5F8 0E004010 */  beqz       $v0, .L8002E634
    /* 1EDFC 8002E5FC 00000000 */   nop
    /* 1EE00 8002E600 3C00028E */  lw         $v0, 0x3C($s0)
    /* 1EE04 8002E604 00000000 */  nop
    /* 1EE08 8002E608 00004390 */  lbu        $v1, 0x0($v0)
    /* 1EE0C 8002E60C F3000224 */  addiu      $v0, $zero, 0xF3
    /* 1EE10 8002E610 08006210 */  beq        $v1, $v0, .L8002E634
    /* 1EE14 8002E614 00000000 */   nop
    /* 1EE18 8002E618 0380023C */  lui        $v0, %hi(D_800335A0)
    /* 1EE1C 8002E61C A035428C */  lw         $v0, %lo(D_800335A0)($v0)
    /* 1EE20 8002E620 00000000 */  nop
    /* 1EE24 8002E624 09F84000 */  jalr       $v0
    /* 1EE28 8002E628 21200002 */   addu      $a0, $s0, $zero
    /* 1EE2C 8002E62C B3B90008 */  j          .L8002E6CC
    /* 1EE30 8002E630 00000000 */   nop
  .L8002E634:
    /* 1EE34 8002E634 46000392 */  lbu        $v1, 0x46($s0)
    /* 1EE38 8002E638 01000424 */  addiu      $a0, $zero, 0x1
    /* 1EE3C 8002E63C 0E006410 */  beq        $v1, $a0, .L8002E678
    /* 1EE40 8002E640 02006228 */   slti      $v0, $v1, 0x2
    /* 1EE44 8002E644 05004010 */  beqz       $v0, .L8002E65C
    /* 1EE48 8002E648 FE000224 */   addiu     $v0, $zero, 0xFE
    /* 1EE4C 8002E64C 07006010 */  beqz       $v1, .L8002E66C
    /* 1EE50 8002E650 00000000 */   nop
    /* 1EE54 8002E654 A5B90008 */  j          .L8002E694
    /* 1EE58 8002E658 00000000 */   nop
  .L8002E65C:
    /* 1EE5C 8002E65C 0B006210 */  beq        $v1, $v0, .L8002E68C
    /* 1EE60 8002E660 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 1EE64 8002E664 A5B90008 */  j          .L8002E694
    /* 1EE68 8002E668 00000000 */   nop
  .L8002E66C:
    /* 1EE6C 8002E66C 46000292 */  lbu        $v0, 0x46($s0)
    /* 1EE70 8002E670 A0B90008 */  j          .L8002E680
    /* 1EE74 8002E674 490004A2 */   sb        $a0, 0x49($s0)
  .L8002E678:
    /* 1EE78 8002E678 46000292 */  lbu        $v0, 0x46($s0)
    /* 1EE7C 8002E67C 470000A2 */  sb         $zero, 0x47($s0)
  .L8002E680:
    /* 1EE80 8002E680 01004224 */  addiu      $v0, $v0, 0x1
    /* 1EE84 8002E684 B3B90008 */  j          .L8002E6CC
    /* 1EE88 8002E688 460002A2 */   sb        $v0, 0x46($s0)
  .L8002E68C:
    /* 1EE8C 8002E68C B3B90008 */  j          .L8002E6CC
    /* 1EE90 8002E690 460002A2 */   sb        $v0, 0x46($s0)
  .L8002E694:
    /* 1EE94 8002E694 1800028E */  lw         $v0, 0x18($s0)
    /* 1EE98 8002E698 00000000 */  nop
    /* 1EE9C 8002E69C 05004010 */  beqz       $v0, .L8002E6B4
    /* 1EEA0 8002E6A0 00000000 */   nop
    /* 1EEA4 8002E6A4 09F84000 */  jalr       $v0
    /* 1EEA8 8002E6A8 21200002 */   addu      $a0, $s0, $zero
    /* 1EEAC 8002E6AC AFB90008 */  j          .L8002E6BC
    /* 1EEB0 8002E6B0 00000000 */   nop
  .L8002E6B4:
    /* 1EEB4 8002E6B4 CDB2000C */  jal        _padRecvAtLoadInfo
    /* 1EEB8 8002E6B8 21200002 */   addu      $a0, $s0, $zero
  .L8002E6BC:
    /* 1EEBC 8002E6BC 46000392 */  lbu        $v1, 0x46($s0)
    /* 1EEC0 8002E6C0 00000000 */  nop
    /* 1EEC4 8002E6C4 21186200 */  addu       $v1, $v1, $v0
    /* 1EEC8 8002E6C8 460003A2 */  sb         $v1, 0x46($s0)
  .L8002E6CC:
    /* 1EECC 8002E6CC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1EED0 8002E6D0 1000B08F */  lw         $s0, 0x10($sp)
    /* 1EED4 8002E6D4 0800E003 */  jr         $ra
    /* 1EED8 8002E6D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002E478
