nonmatching func_80093E64, 0xC0

glabel func_80093E64
    /* 2B664 80093E64 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2B668 80093E68 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 2B66C 80093E6C 21888000 */  addu       $s1, $a0, $zero
    /* 2B670 80093E70 0F80053C */  lui        $a1, %hi(D_800F227E)
    /* 2B674 80093E74 7E22A284 */  lh         $v0, %lo(D_800F227E)($a1)
    /* 2B678 80093E78 0F80033C */  lui        $v1, %hi(D_800F1BAC)
    /* 2B67C 80093E7C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 2B680 80093E80 AC1B708C */  lw         $s0, %lo(D_800F1BAC)($v1)
    /* 2B684 80093E84 21200000 */  addu       $a0, $zero, $zero
    /* 2B688 80093E88 11004018 */  blez       $v0, .L80093ED0
    /* 2B68C 80093E8C 2000BFAF */   sw        $ra, 0x20($sp)
    /* 2B690 80093E90 04000624 */  addiu      $a2, $zero, 0x4
    /* 2B694 80093E94 2118A000 */  addu       $v1, $a1, $zero
  .L80093E98:
    /* 2B698 80093E98 08000296 */  lhu        $v0, 0x8($s0)
    /* 2B69C 80093E9C 00000000 */  nop
    /* 2B6A0 80093EA0 05004614 */  bne        $v0, $a2, .L80093EB8
    /* 2B6A4 80093EA4 00000000 */   nop
    /* 2B6A8 80093EA8 1159020C */  jal        func_80096444
    /* 2B6AC 80093EAC 00000000 */   nop
    /* 2B6B0 80093EB0 B44F0208 */  j          .L80093ED0
    /* 2B6B4 80093EB4 00000000 */   nop
  .L80093EB8:
    /* 2B6B8 80093EB8 01008424 */  addiu      $a0, $a0, 0x1
    /* 2B6BC 80093EBC 7E226284 */  lh         $v0, %lo(D_800F227E)($v1)
    /* 2B6C0 80093EC0 00000000 */  nop
    /* 2B6C4 80093EC4 2A108200 */  slt        $v0, $a0, $v0
    /* 2B6C8 80093EC8 F3FF4014 */  bnez       $v0, .L80093E98
    /* 2B6CC 80093ECC 18001026 */   addiu     $s0, $s0, 0x18
  .L80093ED0:
    /* 2B6D0 80093ED0 B958020C */  jal        func_800962E4
    /* 2B6D4 80093ED4 00000000 */   nop
    /* 2B6D8 80093ED8 21804000 */  addu       $s0, $v0, $zero
    /* 2B6DC 80093EDC 04000224 */  addiu      $v0, $zero, 0x4
    /* 2B6E0 80093EE0 0B0000A2 */  sb         $zero, 0xB($s0)
    /* 2B6E4 80093EE4 080002A2 */  sb         $v0, 0x8($s0)
    /* 2B6E8 80093EE8 090000A2 */  sb         $zero, 0x9($s0)
    /* 2B6EC 80093EEC B19B000C */  jal        rand
    /* 2B6F0 80093EF0 0C0011A6 */   sh        $s1, 0xC($s0)
    /* 2B6F4 80093EF4 07004230 */  andi       $v0, $v0, 0x7
    /* 2B6F8 80093EF8 0F80043C */  lui        $a0, %hi(D_800F227E)
    /* 2B6FC 80093EFC 0F0002A2 */  sb         $v0, 0xF($s0)
    /* 2B700 80093F00 21100000 */  addu       $v0, $zero, $zero
    /* 2B704 80093F04 7E228394 */  lhu        $v1, %lo(D_800F227E)($a0)
    /* 2B708 80093F08 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2B70C 80093F0C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 2B710 80093F10 1800B08F */  lw         $s0, 0x18($sp)
    /* 2B714 80093F14 01006324 */  addiu      $v1, $v1, 0x1
    /* 2B718 80093F18 7E2283A4 */  sh         $v1, %lo(D_800F227E)($a0)
    /* 2B71C 80093F1C 0800E003 */  jr         $ra
    /* 2B720 80093F20 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80093E64
