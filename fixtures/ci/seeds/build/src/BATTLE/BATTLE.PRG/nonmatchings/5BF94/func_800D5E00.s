nonmatching func_800D5E00, 0x18C

glabel func_800D5E00
    /* 6D600 800D5E00 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6D604 800D5E04 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6D608 800D5E08 2180A000 */  addu       $s0, $a1, $zero
    /* 6D60C 800D5E0C 01000624 */  addiu      $a2, $zero, 0x1
    /* 6D610 800D5E10 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6D614 800D5E14 06000286 */  lh         $v0, 0x6($s0)
    /* 6D618 800D5E18 0000088E */  lw         $t0, 0x0($s0)
    /* 6D61C 800D5E1C 4C0D838C */  lw         $v1, 0xD4C($a0)
    /* 6D620 800D5E20 0410C200 */  sllv       $v0, $v0, $a2
    /* 6D624 800D5E24 21104800 */  addu       $v0, $v0, $t0
    /* 6D628 800D5E28 00004594 */  lhu        $a1, 0x0($v0)
    /* 6D62C 800D5E2C 02006384 */  lh         $v1, 0x2($v1)
    /* 6D630 800D5E30 FF01A230 */  andi       $v0, $a1, 0x1FF
    /* 6D634 800D5E34 03004310 */  beq        $v0, $v1, .L800D5E44
    /* 6D638 800D5E38 21380000 */   addu      $a3, $zero, $zero
    /* 6D63C 800D5E3C DF570308 */  j          .L800D5F7C
    /* 6D640 800D5E40 2110C000 */   addu      $v0, $a2, $zero
  .L800D5E44:
    /* 6D644 800D5E44 821B0500 */  srl        $v1, $a1, 14
    /* 6D648 800D5E48 0E006610 */  beq        $v1, $a2, .L800D5E84
    /* 6D64C 800D5E4C 02006228 */   slti      $v0, $v1, 0x2
    /* 6D650 800D5E50 05004010 */  beqz       $v0, .L800D5E68
    /* 6D654 800D5E54 00000000 */   nop
    /* 6D658 800D5E58 19006010 */  beqz       $v1, .L800D5EC0
    /* 6D65C 800D5E5C 00000000 */   nop
    /* 6D660 800D5E60 CD570308 */  j          .L800D5F34
    /* 6D664 800D5E64 00000000 */   nop
  .L800D5E68:
    /* 6D668 800D5E68 02000224 */  addiu      $v0, $zero, 0x2
    /* 6D66C 800D5E6C 0C006210 */  beq        $v1, $v0, .L800D5EA0
    /* 6D670 800D5E70 03000224 */   addiu     $v0, $zero, 0x3
    /* 6D674 800D5E74 14006210 */  beq        $v1, $v0, .L800D5EC8
    /* 6D678 800D5E78 0F80023C */   lui       $v0, %hi(D_800F569C)
    /* 6D67C 800D5E7C CD570308 */  j          .L800D5F34
    /* 6D680 800D5E80 00000000 */   nop
  .L800D5E84:
    /* 6D684 800D5E84 1C0D8394 */  lhu        $v1, 0xD1C($a0)
    /* 6D688 800D5E88 04000224 */  addiu      $v0, $zero, 0x4
    /* 6D68C 800D5E8C 29006214 */  bne        $v1, $v0, .L800D5F34
    /* 6D690 800D5E90 00000000 */   nop
    /* 6D694 800D5E94 200D8290 */  lbu        $v0, 0xD20($a0)
    /* 6D698 800D5E98 AD570308 */  j          .L800D5EB4
    /* 6D69C 800D5E9C 00000000 */   nop
  .L800D5EA0:
    /* 6D6A0 800D5EA0 340D8394 */  lhu        $v1, 0xD34($a0)
    /* 6D6A4 800D5EA4 04000224 */  addiu      $v0, $zero, 0x4
    /* 6D6A8 800D5EA8 22006214 */  bne        $v1, $v0, .L800D5F34
    /* 6D6AC 800D5EAC 00000000 */   nop
    /* 6D6B0 800D5EB0 380D8290 */  lbu        $v0, 0xD38($a0)
  .L800D5EB4:
    /* 6D6B4 800D5EB4 00000000 */  nop
    /* 6D6B8 800D5EB8 1E004014 */  bnez       $v0, .L800D5F34
    /* 6D6BC 800D5EBC 00000000 */   nop
  .L800D5EC0:
    /* 6D6C0 800D5EC0 CD570308 */  j          .L800D5F34
    /* 6D6C4 800D5EC4 01000724 */   addiu     $a3, $zero, 0x1
  .L800D5EC8:
    /* 6D6C8 800D5EC8 9C56428C */  lw         $v0, %lo(D_800F569C)($v0)
    /* 6D6CC 800D5ECC 00000000 */  nop
    /* 6D6D0 800D5ED0 D000438C */  lw         $v1, 0xD0($v0)
    /* 6D6D4 800D5ED4 00000000 */  nop
    /* 6D6D8 800D5ED8 02006290 */  lbu        $v0, 0x2($v1)
    /* 6D6DC 800D5EDC 00000000 */  nop
    /* 6D6E0 800D5EE0 2A10E200 */  slt        $v0, $a3, $v0
    /* 6D6E4 800D5EE4 13004010 */  beqz       $v0, .L800D5F34
    /* 6D6E8 800D5EE8 21200000 */   addu      $a0, $zero, $zero
    /* 6D6EC 800D5EEC 04000524 */  addiu      $a1, $zero, 0x4
  .L800D5EF0:
    /* 6D6F0 800D5EF0 10006294 */  lhu        $v0, 0x10($v1)
    /* 6D6F4 800D5EF4 00000000 */  nop
    /* 6D6F8 800D5EF8 05004514 */  bne        $v0, $a1, .L800D5F10
    /* 6D6FC 800D5EFC 0F80023C */   lui       $v0, %hi(D_800F569C)
    /* 6D700 800D5F00 14006290 */  lbu        $v0, 0x14($v1)
    /* 6D704 800D5F04 00000000 */  nop
    /* 6D708 800D5F08 EDFF4010 */  beqz       $v0, .L800D5EC0
    /* 6D70C 800D5F0C 0F80023C */   lui       $v0, %hi(D_800F569C)
  .L800D5F10:
    /* 6D710 800D5F10 9C56428C */  lw         $v0, %lo(D_800F569C)($v0)
    /* 6D714 800D5F14 00000000 */  nop
    /* 6D718 800D5F18 D000428C */  lw         $v0, 0xD0($v0)
    /* 6D71C 800D5F1C 00000000 */  nop
    /* 6D720 800D5F20 02004290 */  lbu        $v0, 0x2($v0)
    /* 6D724 800D5F24 01008424 */  addiu      $a0, $a0, 0x1
    /* 6D728 800D5F28 2A108200 */  slt        $v0, $a0, $v0
    /* 6D72C 800D5F2C F0FF4014 */  bnez       $v0, .L800D5EF0
    /* 6D730 800D5F30 0C006324 */   addiu     $v1, $v1, 0xC
  .L800D5F34:
    /* 6D734 800D5F34 0F00E010 */  beqz       $a3, .L800D5F74
    /* 6D738 800D5F38 0F80033C */   lui       $v1, %hi(D_800F569C)
    /* 6D73C 800D5F3C FF000524 */  addiu      $a1, $zero, 0xFF
    /* 6D740 800D5F40 06000286 */  lh         $v0, 0x6($s0)
    /* 6D744 800D5F44 9C56638C */  lw         $v1, %lo(D_800F569C)($v1)
    /* 6D748 800D5F48 40100200 */  sll        $v0, $v0, 1
    /* 6D74C 800D5F4C 21104800 */  addu       $v0, $v0, $t0
    /* 6D750 800D5F50 00004294 */  lhu        $v0, 0x0($v0)
    /* 6D754 800D5F54 C000638C */  lw         $v1, 0xC0($v1)
    /* 6D758 800D5F58 02120200 */  srl        $v0, $v0, 8
    /* 6D75C 800D5F5C 3E004230 */  andi       $v0, $v0, 0x3E
    /* 6D760 800D5F60 21104300 */  addu       $v0, $v0, $v1
    /* 6D764 800D5F64 04004484 */  lh         $a0, 0x4($v0)
    /* 6D768 800D5F68 01000624 */  addiu      $a2, $zero, 0x1
    /* 6D76C 800D5F6C ED0C010C */  jal        func_800433B4
    /* 6D770 800D5F70 21206400 */   addu      $a0, $v1, $a0
  .L800D5F74:
    /* 6D774 800D5F74 E055030C */  jal        func_800D5780
    /* 6D778 800D5F78 21200002 */   addu      $a0, $s0, $zero
  .L800D5F7C:
    /* 6D77C 800D5F7C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6D780 800D5F80 1000B08F */  lw         $s0, 0x10($sp)
    /* 6D784 800D5F84 0800E003 */  jr         $ra
    /* 6D788 800D5F88 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D5E00
