nonmatching vs_battle_populateDataSlot, 0x94

glabel vs_battle_populateDataSlot
    /* 30DE8 800995E8 21408000 */  addu       $t0, $a0, $zero
    /* 30DEC 800995EC 21180000 */  addu       $v1, $zero, $zero
    /* 30DF0 800995F0 0F80023C */  lui        $v0, %hi(vs_battle_objectDataSlots)
    /* 30DF4 800995F4 10234424 */  addiu      $a0, $v0, %lo(vs_battle_objectDataSlots)
  .L800995F8:
    /* 30DF8 800995F8 00008290 */  lbu        $v0, 0x0($a0)
    /* 30DFC 800995FC 00000000 */  nop
    /* 30E00 80099600 06004010 */  beqz       $v0, .L8009961C
    /* 30E04 80099604 21386000 */   addu      $a3, $v1, $zero
    /* 30E08 80099608 01006324 */  addiu      $v1, $v1, 0x1
    /* 30E0C 8009960C 10006228 */  slti       $v0, $v1, 0x10
    /* 30E10 80099610 F9FF4014 */  bnez       $v0, .L800995F8
    /* 30E14 80099614 14008424 */   addiu     $a0, $a0, 0x14
    /* 30E18 80099618 FFFF0724 */  addiu      $a3, $zero, -0x1
  .L8009961C:
    /* 30E1C 8009961C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 30E20 80099620 1300E210 */  beq        $a3, $v0, .L80099670
    /* 30E24 80099624 80100700 */   sll       $v0, $a3, 2
    /* 30E28 80099628 21104700 */  addu       $v0, $v0, $a3
    /* 30E2C 8009962C 80100200 */  sll        $v0, $v0, 2
    /* 30E30 80099630 0F80033C */  lui        $v1, %hi(vs_battle_objectDataSlots)
    /* 30E34 80099634 10236324 */  addiu      $v1, $v1, %lo(vs_battle_objectDataSlots)
    /* 30E38 80099638 21104300 */  addu       $v0, $v0, $v1
    /* 30E3C 8009963C 0000038D */  lw         $v1, 0x0($t0)
    /* 30E40 80099640 0400048D */  lw         $a0, 0x4($t0)
    /* 30E44 80099644 0800058D */  lw         $a1, 0x8($t0)
    /* 30E48 80099648 0C00068D */  lw         $a2, 0xC($t0)
    /* 30E4C 8009964C 000043AC */  sw         $v1, 0x0($v0)
    /* 30E50 80099650 040044AC */  sw         $a0, 0x4($v0)
    /* 30E54 80099654 080045AC */  sw         $a1, 0x8($v0)
    /* 30E58 80099658 0C0046AC */  sw         $a2, 0xC($v0)
    /* 30E5C 8009965C 1000038D */  lw         $v1, 0x10($t0)
    /* 30E60 80099660 00000000 */  nop
    /* 30E64 80099664 100043AC */  sw         $v1, 0x10($v0)
    /* 30E68 80099668 9D650208 */  j          .L80099674
    /* 30E6C 8009966C 2110E000 */   addu      $v0, $a3, $zero
  .L80099670:
    /* 30E70 80099670 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L80099674:
    /* 30E74 80099674 0800E003 */  jr         $ra
    /* 30E78 80099678 00000000 */   nop
endlabel vs_battle_populateDataSlot
