nonmatching func_80093A14, 0x5C

glabel func_80093A14
    /* 2B214 80093A14 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2B218 80093A18 0F80033C */  lui        $v1, %hi(D_800F1D00)
    /* 2B21C 80093A1C 01000224 */  addiu      $v0, $zero, 0x1
    /* 2B220 80093A20 001D62A4 */  sh         $v0, %lo(D_800F1D00)($v1)
    /* 2B224 80093A24 0F80023C */  lui        $v0, %hi(D_800F2258)
    /* 2B228 80093A28 58224684 */  lh         $a2, %lo(D_800F2258)($v0)
    /* 2B22C 80093A2C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2B230 80093A30 0B00C210 */  beq        $a2, $v0, .L80093A60
    /* 2B234 80093A34 1800BFAF */   sw        $ra, 0x18($sp)
    /* 2B238 80093A38 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 2B23C 80093A3C F81B4324 */  addiu      $v1, $v0, %lo(vs_battle_roomData)
    /* 2B240 80093A40 B000628C */  lw         $v0, 0xB0($v1)
    /* 2B244 80093A44 00000000 */  nop
    /* 2B248 80093A48 05004010 */  beqz       $v0, .L80093A60
    /* 2B24C 80093A4C 00020424 */   addiu     $a0, $zero, 0x200
    /* 2B250 80093A50 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2B254 80093A54 B000658C */  lw         $a1, 0xB0($v1)
    /* 2B258 80093A58 2519010C */  jal        func_80046494
    /* 2B25C 80093A5C 7F000724 */   addiu     $a3, $zero, 0x7F
  .L80093A60:
    /* 2B260 80093A60 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2B264 80093A64 00000000 */  nop
    /* 2B268 80093A68 0800E003 */  jr         $ra
    /* 2B26C 80093A6C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80093A14
