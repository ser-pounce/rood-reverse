nonmatching func_8008ABF0, 0x88

glabel func_8008ABF0
    /* 223F0 8008ABF0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 223F4 8008ABF4 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 223F8 8008ABF8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 223FC 8008ABFC F81B5024 */  addiu      $s0, $v0, %lo(vs_battle_roomData)
    /* 22400 8008AC00 F81B4390 */  lbu        $v1, %lo(vs_battle_roomData)($v0)
    /* 22404 8008AC04 01000224 */  addiu      $v0, $zero, 0x1
    /* 22408 8008AC08 16006214 */  bne        $v1, $v0, .L8008AC64
    /* 2240C 8008AC0C 1400BFAF */   sw        $ra, 0x14($sp)
    /* 22410 8008AC10 02000286 */  lh         $v0, 0x2($s0)
    /* 22414 8008AC14 00000000 */  nop
    /* 22418 8008AC18 13004414 */  bne        $v0, $a0, .L8008AC68
    /* 2241C 8008AC1C 21100000 */   addu      $v0, $zero, $zero
    /* 22420 8008AC20 8D3C020C */  jal        func_8008F234
    /* 22424 8008AC24 00000000 */   nop
    /* 22428 8008AC28 DE44020C */  jal        func_80091378
    /* 2242C 8008AC2C 00000000 */   nop
    /* 22430 8008AC30 864A020C */  jal        func_80092A18
    /* 22434 8008AC34 00000000 */   nop
    /* 22438 8008AC38 6400048E */  lw         $a0, 0x64($s0)
    /* 2243C 8008AC3C 00000000 */  nop
    /* 22440 8008AC40 03008010 */  beqz       $a0, .L8008AC50
    /* 22444 8008AC44 00000000 */   nop
    /* 22448 8008AC48 540F010C */  jal        vs_main_freeHeap
    /* 2244C 8008AC4C 00000000 */   nop
  .L8008AC50:
    /* 22450 8008AC50 21200002 */  addu       $a0, $s0, $zero
    /* 22454 8008AC54 4424010C */  jal        vs_main_bzero
    /* 22458 8008AC58 C4000524 */   addiu     $a1, $zero, 0xC4
    /* 2245C 8008AC5C 1A2B0208 */  j          .L8008AC68
    /* 22460 8008AC60 01000224 */   addiu     $v0, $zero, 0x1
  .L8008AC64:
    /* 22464 8008AC64 21100000 */  addu       $v0, $zero, $zero
  .L8008AC68:
    /* 22468 8008AC68 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2246C 8008AC6C 1000B08F */  lw         $s0, 0x10($sp)
    /* 22470 8008AC70 0800E003 */  jr         $ra
    /* 22474 8008AC74 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008ABF0
