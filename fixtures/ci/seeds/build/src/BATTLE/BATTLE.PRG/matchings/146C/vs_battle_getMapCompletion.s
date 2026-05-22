nonmatching vs_battle_getMapCompletion, 0xB8

glabel vs_battle_getMapCompletion
    /* 25DF0 8008E5F0 0680023C */  lui        $v0, %hi(vs_main_mapStatus)
    /* 25DF4 8008E5F4 D8FF4324 */  addiu      $v1, $v0, %lo(vs_main_mapStatus)
    /* 25DF8 8008E5F8 0400648C */  lw         $a0, 0x4($v1)
    /* 25DFC 8008E5FC 8000023C */  lui        $v0, (0x800000 >> 16)
    /* 25E00 8008E600 24108200 */  and        $v0, $a0, $v0
    /* 25E04 8008E604 03004010 */  beqz       $v0, .L8008E614
    /* 25E08 8008E608 4000023C */   lui       $v0, (0x400000 >> 16)
    /* 25E0C 8008E60C 25108200 */  or         $v0, $a0, $v0
    /* 25E10 8008E610 040062AC */  sw         $v0, 0x4($v1)
  .L8008E614:
    /* 25E14 8008E614 21280000 */  addu       $a1, $zero, $zero
    /* 25E18 8008E618 2140A000 */  addu       $t0, $a1, $zero
    /* 25E1C 8008E61C 01000924 */  addiu      $t1, $zero, 0x1
    /* 25E20 8008E620 0F80023C */  lui        $v0, %hi(vs_battle_mapCompletionFlags)
    /* 25E24 8008E624 08854724 */  addiu      $a3, $v0, %lo(vs_battle_mapCompletionFlags)
    /* 25E28 8008E628 21306000 */  addu       $a2, $v1, $zero
  .L8008E62C:
    /* 25E2C 8008E62C 0000C38C */  lw         $v1, 0x0($a2)
    /* 25E30 8008E630 0000E28C */  lw         $v0, 0x0($a3)
    /* 25E34 8008E634 21200000 */  addu       $a0, $zero, $zero
    /* 25E38 8008E638 24186200 */  and        $v1, $v1, $v0
    /* 25E3C 8008E63C 04108900 */  sllv       $v0, $t1, $a0
  .L8008E640:
    /* 25E40 8008E640 24106200 */  and        $v0, $v1, $v0
    /* 25E44 8008E644 02004010 */  beqz       $v0, .L8008E650
    /* 25E48 8008E648 00000000 */   nop
    /* 25E4C 8008E64C 0100A524 */  addiu      $a1, $a1, 0x1
  .L8008E650:
    /* 25E50 8008E650 01008424 */  addiu      $a0, $a0, 0x1
    /* 25E54 8008E654 20008228 */  slti       $v0, $a0, 0x20
    /* 25E58 8008E658 F9FF4014 */  bnez       $v0, .L8008E640
    /* 25E5C 8008E65C 04108900 */   sllv      $v0, $t1, $a0
    /* 25E60 8008E660 0400E724 */  addiu      $a3, $a3, 0x4
    /* 25E64 8008E664 01000825 */  addiu      $t0, $t0, 0x1
    /* 25E68 8008E668 10000229 */  slti       $v0, $t0, 0x10
    /* 25E6C 8008E66C EFFF4014 */  bnez       $v0, .L8008E62C
    /* 25E70 8008E670 0400C624 */   addiu     $a2, $a2, 0x4
    /* 25E74 8008E674 C55A033C */  lui        $v1, (0x5AC5242B >> 16)
    /* 25E78 8008E678 2B246334 */  ori        $v1, $v1, (0x5AC5242B & 0xFFFF)
    /* 25E7C 8008E67C 40100500 */  sll        $v0, $a1, 1
    /* 25E80 8008E680 21104500 */  addu       $v0, $v0, $a1
    /* 25E84 8008E684 C0100200 */  sll        $v0, $v0, 3
    /* 25E88 8008E688 21104500 */  addu       $v0, $v0, $a1
    /* 25E8C 8008E68C 80100200 */  sll        $v0, $v0, 2
    /* 25E90 8008E690 18004300 */  mult       $v0, $v1
    /* 25E94 8008E694 C3170200 */  sra        $v0, $v0, 31
    /* 25E98 8008E698 10500000 */  mfhi       $t2
    /* 25E9C 8008E69C C3190A00 */  sra        $v1, $t2, 7
    /* 25EA0 8008E6A0 0800E003 */  jr         $ra
    /* 25EA4 8008E6A4 23106200 */   subu      $v0, $v1, $v0
endlabel vs_battle_getMapCompletion
