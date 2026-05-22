nonmatching vs_battle_decreaseMiscCount, 0x80

glabel vs_battle_decreaseMiscCount
    /* 6439C 800CCB9C 43018228 */  slti       $v0, $a0, 0x143
    /* 643A0 800CCBA0 02004010 */  beqz       $v0, .L800CCBAC
    /* 643A4 800CCBA4 0F80023C */   lui       $v0, %hi(D_800F5210)
    /* 643A8 800CCBA8 105240A0 */  sb         $zero, %lo(D_800F5210)($v0)
  .L800CCBAC:
    /* 643AC 800CCBAC 21280000 */  addu       $a1, $zero, $zero
    /* 643B0 800CCBB0 0F80073C */  lui        $a3, %hi(D_800F5210)
    /* 643B4 800CCBB4 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 643B8 800CCBB8 68014624 */  addiu      $a2, $v0, %lo(vs_battle_inventory)
  .L800CCBBC:
    /* 643BC 800CCBBC 1052E290 */  lbu        $v0, %lo(D_800F5210)($a3)
    /* 643C0 800CCBC0 00000000 */  nop
    /* 643C4 800CCBC4 21104500 */  addu       $v0, $v0, $a1
    /* 643C8 800CCBC8 3F004230 */  andi       $v0, $v0, 0x3F
    /* 643CC 800CCBCC 80100200 */  sll        $v0, $v0, 2
    /* 643D0 800CCBD0 21184600 */  addu       $v1, $v0, $a2
    /* 643D4 800CCBD4 000E6294 */  lhu        $v0, 0xE00($v1)
    /* 643D8 800CCBD8 00000000 */  nop
    /* 643DC 800CCBDC 09004414 */  bne        $v0, $a0, .L800CCC04
    /* 643E0 800CCBE0 00000000 */   nop
    /* 643E4 800CCBE4 020E6290 */  lbu        $v0, 0xE02($v1)
    /* 643E8 800CCBE8 00000000 */  nop
    /* 643EC 800CCBEC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 643F0 800CCBF0 02004014 */  bnez       $v0, .L800CCBFC
    /* 643F4 800CCBF4 020E62A0 */   sb        $v0, 0xE02($v1)
    /* 643F8 800CCBF8 000E60A4 */  sh         $zero, 0xE00($v1)
  .L800CCBFC:
    /* 643FC 800CCBFC 0800E003 */  jr         $ra
    /* 64400 800CCC00 01000224 */   addiu     $v0, $zero, 0x1
  .L800CCC04:
    /* 64404 800CCC04 0100A524 */  addiu      $a1, $a1, 0x1
    /* 64408 800CCC08 4000A228 */  slti       $v0, $a1, 0x40
    /* 6440C 800CCC0C EBFF4014 */  bnez       $v0, .L800CCBBC
    /* 64410 800CCC10 21100000 */   addu      $v0, $zero, $zero
    /* 64414 800CCC14 0800E003 */  jr         $ra
    /* 64418 800CCC18 00000000 */   nop
endlabel vs_battle_decreaseMiscCount
