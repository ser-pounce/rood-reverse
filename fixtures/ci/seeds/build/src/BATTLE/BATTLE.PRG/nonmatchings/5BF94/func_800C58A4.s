nonmatching func_800C58A4, 0x54

glabel func_800C58A4
    /* 5D0A4 800C58A4 42210400 */  srl        $a0, $a0, 5
    /* 5D0A8 800C58A8 21180000 */  addu       $v1, $zero, $zero
    /* 5D0AC 800C58AC 0F80023C */  lui        $v0, %hi(D_800EA868)
    /* 5D0B0 800C58B0 68A84624 */  addiu      $a2, $v0, %lo(D_800EA868)
    /* 5D0B4 800C58B4 72000524 */  addiu      $a1, $zero, 0x72
  .L800C58B8:
    /* 5D0B8 800C58B8 06106400 */  srlv       $v0, $a0, $v1
    /* 5D0BC 800C58BC 01004230 */  andi       $v0, $v0, 0x1
    /* 5D0C0 800C58C0 07004010 */  beqz       $v0, .L800C58E0
    /* 5D0C4 800C58C4 01006324 */   addiu     $v1, $v1, 0x1
    /* 5D0C8 800C58C8 2110A600 */  addu       $v0, $a1, $a2
    /* 5D0CC 800C58CC 00004294 */  lhu        $v0, 0x0($v0)
    /* 5D0D0 800C58D0 00000000 */  nop
    /* 5D0D4 800C58D4 40100200 */  sll        $v0, $v0, 1
    /* 5D0D8 800C58D8 0800E003 */  jr         $ra
    /* 5D0DC 800C58DC 21104600 */   addu      $v0, $v0, $a2
  .L800C58E0:
    /* 5D0E0 800C58E0 18006228 */  slti       $v0, $v1, 0x18
    /* 5D0E4 800C58E4 F4FF4014 */  bnez       $v0, .L800C58B8
    /* 5D0E8 800C58E8 0200A524 */   addiu     $a1, $a1, 0x2
    /* 5D0EC 800C58EC 0F80023C */  lui        $v0, %hi(D_800EAA54)
    /* 5D0F0 800C58F0 0800E003 */  jr         $ra
    /* 5D0F4 800C58F4 54AA4224 */   addiu     $v0, $v0, %lo(D_800EAA54)
endlabel func_800C58A4
