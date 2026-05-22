nonmatching _spu_FsetRXXa, 0xA4

glabel _spu_FsetRXXa
    /* EBA4 8001E3A4 0380023C */  lui        $v0, %hi(D_80030884)
    /* EBA8 8001E3A8 8408428C */  lw         $v0, %lo(D_80030884)($v0)
    /* EBAC 8001E3AC 00000000 */  nop
    /* EBB0 8001E3B0 10004010 */  beqz       $v0, .L8001E3F4
    /* EBB4 8001E3B4 21308000 */   addu      $a2, $a0, $zero
    /* EBB8 8001E3B8 0380043C */  lui        $a0, %hi(D_8003088C)
    /* EBBC 8001E3BC 8C08848C */  lw         $a0, %lo(D_8003088C)($a0)
    /* EBC0 8001E3C0 00000000 */  nop
    /* EBC4 8001E3C4 1B00A400 */  divu       $zero, $a1, $a0
    /* EBC8 8001E3C8 02008014 */  bnez       $a0, .L8001E3D4
    /* EBCC 8001E3CC 00000000 */   nop
    /* EBD0 8001E3D0 0D000700 */  break      7
  .L8001E3D4:
    /* EBD4 8001E3D4 10100000 */  mfhi       $v0
    /* EBD8 8001E3D8 06004010 */  beqz       $v0, .L8001E3F4
    /* EBDC 8001E3DC 00000000 */   nop
    /* EBE0 8001E3E0 0380023C */  lui        $v0, %hi(D_80030890)
    /* EBE4 8001E3E4 9008428C */  lw         $v0, %lo(D_80030890)($v0)
    /* EBE8 8001E3E8 2128A400 */  addu       $a1, $a1, $a0
    /* EBEC 8001E3EC 27100200 */  nor        $v0, $zero, $v0
    /* EBF0 8001E3F0 2428A200 */  and        $a1, $a1, $v0
  .L8001E3F4:
    /* EBF4 8001E3F4 0380023C */  lui        $v0, %hi(D_80030888)
    /* EBF8 8001E3F8 8808428C */  lw         $v0, %lo(D_80030888)($v0)
    /* EBFC 8001E3FC 00000000 */  nop
    /* EC00 8001E400 06384500 */  srlv       $a3, $a1, $v0
    /* EC04 8001E404 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* EC08 8001E408 0600C210 */  beq        $a2, $v0, .L8001E424
    /* EC0C 8001E40C 2118E000 */   addu      $v1, $a3, $zero
    /* EC10 8001E410 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* EC14 8001E414 0500C214 */  bne        $a2, $v0, .L8001E42C
    /* EC18 8001E418 2110A000 */   addu      $v0, $a1, $zero
    /* EC1C 8001E41C 10790008 */  j          .L8001E440
    /* EC20 8001E420 FFFF6230 */   andi      $v0, $v1, 0xFFFF
  .L8001E424:
    /* EC24 8001E424 10790008 */  j          .L8001E440
    /* EC28 8001E428 2110A000 */   addu      $v0, $a1, $zero
  .L8001E42C:
    /* EC2C 8001E42C 0380043C */  lui        $a0, %hi(D_80030860)
    /* EC30 8001E430 6008848C */  lw         $a0, %lo(D_80030860)($a0)
    /* EC34 8001E434 40180600 */  sll        $v1, $a2, 1
    /* EC38 8001E438 21186400 */  addu       $v1, $v1, $a0
    /* EC3C 8001E43C 000067A4 */  sh         $a3, 0x0($v1)
  .L8001E440:
    /* EC40 8001E440 0800E003 */  jr         $ra
    /* EC44 8001E444 00000000 */   nop
endlabel _spu_FsetRXXa
