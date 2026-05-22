nonmatching func_8008EA90, 0x54

glabel func_8008EA90
    /* 26290 8008EA90 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x8C)
    /* 26294 8008EA94 841C428C */  lw         $v0, %lo(vs_battle_roomData + 0x8C)($v0)
    /* 26298 8008EA98 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2629C 8008EA9C 0C004010 */  beqz       $v0, .L8008EAD0
    /* 262A0 8008EAA0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 262A4 8008EAA4 05008010 */  beqz       $a0, .L8008EABC
    /* 262A8 8008EAA8 21284000 */   addu      $a1, $v0, $zero
    /* 262AC 8008EAAC 3400A384 */  lh         $v1, 0x34($a1)
    /* 262B0 8008EAB0 01000224 */  addiu      $v0, $zero, 0x1
    /* 262B4 8008EAB4 02006210 */  beq        $v1, $v0, .L8008EAC0
    /* 262B8 8008EAB8 21200000 */   addu      $a0, $zero, $zero
  .L8008EABC:
    /* 262BC 8008EABC 3400A484 */  lh         $a0, 0x34($a1)
  .L8008EAC0:
    /* 262C0 8008EAC0 0B43020C */  jal        func_80090C2C
    /* 262C4 8008EAC4 00000000 */   nop
    /* 262C8 8008EAC8 B53A0208 */  j          .L8008EAD4
    /* 262CC 8008EACC 01000224 */   addiu     $v0, $zero, 0x1
  .L8008EAD0:
    /* 262D0 8008EAD0 21100000 */  addu       $v0, $zero, $zero
  .L8008EAD4:
    /* 262D4 8008EAD4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 262D8 8008EAD8 00000000 */  nop
    /* 262DC 8008EADC 0800E003 */  jr         $ra
    /* 262E0 8008EAE0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008EA90
