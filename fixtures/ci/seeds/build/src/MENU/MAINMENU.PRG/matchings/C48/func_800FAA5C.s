nonmatching func_800FAA5C, 0x6C

glabel func_800FAA5C
    /* 125C 800FAA5C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1260 800FAA60 40008430 */  andi       $a0, $a0, 0x40
    /* 1264 800FAA64 07008010 */  beqz       $a0, .L800FAA84
    /* 1268 800FAA68 1000BFAF */   sw        $ra, 0x10($sp)
    /* 126C 800FAA6C 0F80023C */  lui        $v0, %hi(vs_battle_menuState)
    /* 1270 800FAA70 C05140A0 */  sb         $zero, %lo(vs_battle_menuState)($v0)
    /* 1274 800FAA74 C324030C */  jal        func_800C930C
    /* 1278 800FAA78 01000424 */   addiu     $a0, $zero, 0x1
    /* 127C 800FAA7C AEEA0308 */  j          .L800FAAB8
    /* 1280 800FAA80 21100000 */   addu      $v0, $zero, $zero
  .L800FAA84:
    /* 1284 800FAA84 0F80023C */  lui        $v0, %hi(D_800F4FDB)
    /* 1288 800FAA88 DB4F4290 */  lbu        $v0, %lo(D_800F4FDB)($v0)
    /* 128C 800FAA8C 00000000 */  nop
    /* 1290 800FAA90 06004014 */  bnez       $v0, .L800FAAAC
    /* 1294 800FAA94 0F80033C */   lui       $v1, %hi(vs_battle_menuState)
    /* 1298 800FAA98 1A000424 */  addiu      $a0, $zero, 0x1A
    /* 129C 800FAA9C 03000524 */  addiu      $a1, $zero, 0x3
    /* 12A0 800FAAA0 2AF8010C */  jal        func_8007E0A8
    /* 12A4 800FAAA4 06000624 */   addiu     $a2, $zero, 0x6
    /* 12A8 800FAAA8 0F80033C */  lui        $v1, %hi(vs_battle_menuState)
  .L800FAAAC:
    /* 12AC 800FAAAC 7F000224 */  addiu      $v0, $zero, 0x7F
    /* 12B0 800FAAB0 C05162A0 */  sb         $v0, %lo(vs_battle_menuState)($v1)
    /* 12B4 800FAAB4 01000224 */  addiu      $v0, $zero, 0x1
  .L800FAAB8:
    /* 12B8 800FAAB8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 12BC 800FAABC 00000000 */  nop
    /* 12C0 800FAAC0 0800E003 */  jr         $ra
    /* 12C4 800FAAC4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FAA5C
