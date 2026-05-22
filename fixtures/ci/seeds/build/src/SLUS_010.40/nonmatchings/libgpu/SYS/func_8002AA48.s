nonmatching func_8002AA48, 0x13C

glabel func_8002AA48
    /* 1B248 8002AA48 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B24C 8002AA4C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B250 8002AA50 2A008014 */  bnez       $a0, .L8002AAFC
    /* 1B254 8002AA54 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1B258 8002AA58 E1AA000C */  jal        func_8002AB84
    /* 1B25C 8002AA5C 00000000 */   nop
    /* 1B260 8002AA60 A0AA0008 */  j          .L8002AA80
    /* 1B264 8002AA64 00000000 */   nop
  .L8002AA68:
    /* 1B268 8002AA68 A6A9000C */  jal        func_8002A698
    /* 1B26C 8002AA6C 00000000 */   nop
    /* 1B270 8002AA70 EEAA000C */  jal        func_8002ABB8
    /* 1B274 8002AA74 00000000 */   nop
    /* 1B278 8002AA78 3E004014 */  bnez       $v0, .L8002AB74
    /* 1B27C 8002AA7C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8002AA80:
    /* 1B280 8002AA80 0380033C */  lui        $v1, %hi(D_8003356C)
    /* 1B284 8002AA84 6C35638C */  lw         $v1, %lo(D_8003356C)($v1)
    /* 1B288 8002AA88 0380023C */  lui        $v0, %hi(D_80033570)
    /* 1B28C 8002AA8C 7035428C */  lw         $v0, %lo(D_80033570)($v0)
    /* 1B290 8002AA90 00000000 */  nop
    /* 1B294 8002AA94 07006210 */  beq        $v1, $v0, .L8002AAB4
    /* 1B298 8002AA98 00000000 */   nop
    /* 1B29C 8002AA9C 9AAA0008 */  j          .L8002AA68
    /* 1B2A0 8002AAA0 00000000 */   nop
  .L8002AAA4:
    /* 1B2A4 8002AAA4 EEAA000C */  jal        func_8002ABB8
    /* 1B2A8 8002AAA8 00000000 */   nop
    /* 1B2AC 8002AAAC 31004014 */  bnez       $v0, .L8002AB74
    /* 1B2B0 8002AAB0 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8002AAB4:
    /* 1B2B4 8002AAB4 0380023C */  lui        $v0, %hi(D_80033558)
    /* 1B2B8 8002AAB8 5835428C */  lw         $v0, %lo(D_80033558)($v0)
    /* 1B2BC 8002AABC 00000000 */  nop
    /* 1B2C0 8002AAC0 0000428C */  lw         $v0, 0x0($v0)
    /* 1B2C4 8002AAC4 0001033C */  lui        $v1, (0x1000000 >> 16)
    /* 1B2C8 8002AAC8 24104300 */  and        $v0, $v0, $v1
    /* 1B2CC 8002AACC F5FF4014 */  bnez       $v0, .L8002AAA4
    /* 1B2D0 8002AAD0 00000000 */   nop
    /* 1B2D4 8002AAD4 0380023C */  lui        $v0, %hi(D_8003354C)
    /* 1B2D8 8002AAD8 4C35428C */  lw         $v0, %lo(D_8003354C)($v0)
    /* 1B2DC 8002AADC 00000000 */  nop
    /* 1B2E0 8002AAE0 0000428C */  lw         $v0, 0x0($v0)
    /* 1B2E4 8002AAE4 0004033C */  lui        $v1, (0x4000000 >> 16)
    /* 1B2E8 8002AAE8 24104300 */  and        $v0, $v0, $v1
    /* 1B2EC 8002AAEC EDFF4010 */  beqz       $v0, .L8002AAA4
    /* 1B2F0 8002AAF0 21100000 */   addu      $v0, $zero, $zero
    /* 1B2F4 8002AAF4 DDAA0008 */  j          .L8002AB74
    /* 1B2F8 8002AAF8 00000000 */   nop
  .L8002AAFC:
    /* 1B2FC 8002AAFC 0380023C */  lui        $v0, %hi(D_8003356C)
    /* 1B300 8002AB00 6C35428C */  lw         $v0, %lo(D_8003356C)($v0)
    /* 1B304 8002AB04 0380033C */  lui        $v1, %hi(D_80033570)
    /* 1B308 8002AB08 7035638C */  lw         $v1, %lo(D_80033570)($v1)
    /* 1B30C 8002AB0C 00000000 */  nop
    /* 1B310 8002AB10 23104300 */  subu       $v0, $v0, $v1
    /* 1B314 8002AB14 3F005030 */  andi       $s0, $v0, 0x3F
    /* 1B318 8002AB18 03000012 */  beqz       $s0, .L8002AB28
    /* 1B31C 8002AB1C 00000000 */   nop
    /* 1B320 8002AB20 A6A9000C */  jal        func_8002A698
    /* 1B324 8002AB24 00000000 */   nop
  .L8002AB28:
    /* 1B328 8002AB28 0380023C */  lui        $v0, %hi(D_80033558)
    /* 1B32C 8002AB2C 5835428C */  lw         $v0, %lo(D_80033558)($v0)
    /* 1B330 8002AB30 00000000 */  nop
    /* 1B334 8002AB34 0000428C */  lw         $v0, 0x0($v0)
    /* 1B338 8002AB38 0001033C */  lui        $v1, (0x1000000 >> 16)
    /* 1B33C 8002AB3C 24104300 */  and        $v0, $v0, $v1
    /* 1B340 8002AB40 09004014 */  bnez       $v0, .L8002AB68
    /* 1B344 8002AB44 00000000 */   nop
    /* 1B348 8002AB48 0380023C */  lui        $v0, %hi(D_8003354C)
    /* 1B34C 8002AB4C 4C35428C */  lw         $v0, %lo(D_8003354C)($v0)
    /* 1B350 8002AB50 00000000 */  nop
    /* 1B354 8002AB54 0000428C */  lw         $v0, 0x0($v0)
    /* 1B358 8002AB58 0004033C */  lui        $v1, (0x4000000 >> 16)
    /* 1B35C 8002AB5C 24104300 */  and        $v0, $v0, $v1
    /* 1B360 8002AB60 04004014 */  bnez       $v0, .L8002AB74
    /* 1B364 8002AB64 21100002 */   addu      $v0, $s0, $zero
  .L8002AB68:
    /* 1B368 8002AB68 02000016 */  bnez       $s0, .L8002AB74
    /* 1B36C 8002AB6C 21100002 */   addu      $v0, $s0, $zero
    /* 1B370 8002AB70 01000224 */  addiu      $v0, $zero, 0x1
  .L8002AB74:
    /* 1B374 8002AB74 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B378 8002AB78 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B37C 8002AB7C 0800E003 */  jr         $ra
    /* 1B380 8002AB80 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002AA48
