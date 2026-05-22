nonmatching func_800BD610, 0xB4

glabel func_800BD610
    /* 54E10 800BD610 0F80023C */  lui        $v0, %hi(D_800F4BA4)
    /* 54E14 800BD614 A44B458C */  lw         $a1, %lo(D_800F4BA4)($v0)
    /* 54E18 800BD618 00000000 */  nop
    /* 54E1C 800BD61C 0000A290 */  lbu        $v0, 0x0($a1)
    /* 54E20 800BD620 B400A390 */  lbu        $v1, 0xB4($a1)
    /* 54E24 800BD624 0F004238 */  xori       $v0, $v0, 0xF
    /* 54E28 800BD628 0100462C */  sltiu      $a2, $v0, 0x1
    /* 54E2C 800BD62C 0F000224 */  addiu      $v0, $zero, 0xF
    /* 54E30 800BD630 02006214 */  bne        $v1, $v0, .L800BD63C
    /* 54E34 800BD634 2120C000 */   addu      $a0, $a2, $zero
    /* 54E38 800BD638 0200C434 */  ori        $a0, $a2, 0x2
  .L800BD63C:
    /* 54E3C 800BD63C 7201A284 */  lh         $v0, 0x172($a1)
    /* 54E40 800BD640 00000000 */  nop
    /* 54E44 800BD644 02004014 */  bnez       $v0, .L800BD650
    /* 54E48 800BD648 00000000 */   nop
    /* 54E4C 800BD64C 04008434 */  ori        $a0, $a0, 0x4
  .L800BD650:
    /* 54E50 800BD650 8901A290 */  lbu        $v0, 0x189($a1)
    /* 54E54 800BD654 00000000 */  nop
    /* 54E58 800BD658 02004014 */  bnez       $v0, .L800BD664
    /* 54E5C 800BD65C 00000000 */   nop
    /* 54E60 800BD660 08008434 */  ori        $a0, $a0, 0x8
  .L800BD664:
    /* 54E64 800BD664 9501A290 */  lbu        $v0, 0x195($a1)
    /* 54E68 800BD668 00000000 */  nop
    /* 54E6C 800BD66C 02004014 */  bnez       $v0, .L800BD678
    /* 54E70 800BD670 00000000 */   nop
    /* 54E74 800BD674 10008434 */  ori        $a0, $a0, 0x10
  .L800BD678:
    /* 54E78 800BD678 A101A290 */  lbu        $v0, 0x1A1($a1)
    /* 54E7C 800BD67C 00000000 */  nop
    /* 54E80 800BD680 02004014 */  bnez       $v0, .L800BD68C
    /* 54E84 800BD684 00000000 */   nop
    /* 54E88 800BD688 20008434 */  ori        $a0, $a0, 0x20
  .L800BD68C:
    /* 54E8C 800BD68C 7A02A284 */  lh         $v0, 0x27A($a1)
    /* 54E90 800BD690 00000000 */  nop
    /* 54E94 800BD694 02004014 */  bnez       $v0, .L800BD6A0
    /* 54E98 800BD698 00000000 */   nop
    /* 54E9C 800BD69C 40008434 */  ori        $a0, $a0, 0x40
  .L800BD6A0:
    /* 54EA0 800BD6A0 AF01A290 */  lbu        $v0, 0x1AF($a1)
    /* 54EA4 800BD6A4 BB01A390 */  lbu        $v1, 0x1BB($a1)
    /* 54EA8 800BD6A8 00000000 */  nop
    /* 54EAC 800BD6AC 21104300 */  addu       $v0, $v0, $v1
    /* 54EB0 800BD6B0 02004014 */  bnez       $v0, .L800BD6BC
    /* 54EB4 800BD6B4 00000000 */   nop
    /* 54EB8 800BD6B8 80008434 */  ori        $a0, $a0, 0x80
  .L800BD6BC:
    /* 54EBC 800BD6BC 0800E003 */  jr         $ra
    /* 54EC0 800BD6C0 FF008230 */   andi      $v0, $a0, 0xFF
endlabel func_800BD610
