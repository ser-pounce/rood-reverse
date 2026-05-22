nonmatching _padSetActAlign, 0x68

glabel _padSetActAlign
    /* 1DB50 8002D350 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1DB54 8002D354 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1DB58 8002D358 21808000 */  addu       $s0, $a0, $zero
    /* 1DB5C 8002D35C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1DB60 8002D360 0380023C */  lui        $v0, %hi(D_800335B8)
    /* 1DB64 8002D364 B835428C */  lw         $v0, %lo(D_800335B8)($v0)
    /* 1DB68 8002D368 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1DB6C 8002D36C 09F84000 */  jalr       $v0
    /* 1DB70 8002D370 2188A000 */   addu      $s1, $a1, $zero
    /* 1DB74 8002D374 0B004014 */  bnez       $v0, .L8002D3A4
    /* 1DB78 8002D378 21100000 */   addu      $v0, $zero, $zero
    /* 1DB7C 8002D37C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1DB80 8002D380 01000324 */  addiu      $v1, $zero, 0x1
    /* 1DB84 8002D384 460003A2 */  sb         $v1, 0x46($s0)
    /* 1DB88 8002D388 0380033C */  lui        $v1, %hi(func_8002D3B8)
    /* 1DB8C 8002D38C B8D36324 */  addiu      $v1, $v1, %lo(func_8002D3B8)
    /* 1DB90 8002D390 140003AE */  sw         $v1, 0x14($s0)
    /* 1DB94 8002D394 0380033C */  lui        $v1, %hi(func_8002D3D4)
    /* 1DB98 8002D398 D4D36324 */  addiu      $v1, $v1, %lo(func_8002D3D4)
    /* 1DB9C 8002D39C 200011AE */  sw         $s1, 0x20($s0)
    /* 1DBA0 8002D3A0 180003AE */  sw         $v1, 0x18($s0)
  .L8002D3A4:
    /* 1DBA4 8002D3A4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1DBA8 8002D3A8 1400B18F */  lw         $s1, 0x14($sp)
    /* 1DBAC 8002D3AC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1DBB0 8002D3B0 0800E003 */  jr         $ra
    /* 1DBB4 8002D3B4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _padSetActAlign
