nonmatching func_8009FFA8, 0x7C

glabel func_8009FFA8
    /* 377A8 8009FFA8 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 377AC 8009FFAC 38454524 */  addiu      $a1, $v0, %lo(D_800F4538)
    /* 377B0 8009FFB0 80200400 */  sll        $a0, $a0, 2
    /* 377B4 8009FFB4 21208500 */  addu       $a0, $a0, $a1
    /* 377B8 8009FFB8 0000848C */  lw         $a0, 0x0($a0)
    /* 377BC 8009FFBC 00000000 */  nop
    /* 377C0 8009FFC0 12008390 */  lbu        $v1, 0x12($a0)
    /* 377C4 8009FFC4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 377C8 8009FFC8 03006214 */  bne        $v1, $v0, .L8009FFD8
    /* 377CC 8009FFCC F8FFBD27 */   addiu     $sp, $sp, -0x8
    /* 377D0 8009FFD0 06800208 */  j          .L800A0018
    /* 377D4 8009FFD4 FEFF0224 */   addiu     $v0, $zero, -0x2
  .L8009FFD8:
    /* 377D8 8009FFD8 11006228 */  slti       $v0, $v1, 0x11
    /* 377DC 8009FFDC 08004010 */  beqz       $v0, .L800A0000
    /* 377E0 8009FFE0 80100300 */   sll       $v0, $v1, 2
    /* 377E4 8009FFE4 21104500 */  addu       $v0, $v0, $a1
    /* 377E8 8009FFE8 0000428C */  lw         $v0, 0x0($v0)
    /* 377EC 8009FFEC 00000000 */  nop
    /* 377F0 8009FFF0 00004290 */  lbu        $v0, 0x0($v0)
    /* 377F4 8009FFF4 00000000 */  nop
    /* 377F8 8009FFF8 03004014 */  bnez       $v0, .L800A0008
    /* 377FC 8009FFFC FFDF0324 */   addiu     $v1, $zero, -0x2001
  .L800A0000:
    /* 37800 800A0000 06800208 */  j          .L800A0018
    /* 37804 800A0004 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L800A0008:
    /* 37808 800A0008 0800828C */  lw         $v0, 0x8($a0)
    /* 3780C 800A000C 00000000 */  nop
    /* 37810 800A0010 24104300 */  and        $v0, $v0, $v1
    /* 37814 800A0014 080082AC */  sw         $v0, 0x8($a0)
  .L800A0018:
    /* 37818 800A0018 0800BD27 */  addiu      $sp, $sp, 0x8
    /* 3781C 800A001C 0800E003 */  jr         $ra
    /* 37820 800A0020 00000000 */   nop
endlabel func_8009FFA8
