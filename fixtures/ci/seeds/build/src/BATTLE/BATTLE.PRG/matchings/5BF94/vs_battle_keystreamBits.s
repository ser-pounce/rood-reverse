nonmatching vs_battle_keystreamBits, 0x2C

glabel vs_battle_keystreamBits
    /* 6448C 800CCC8C 1900033C */  lui        $v1, (0x19660D >> 16)
    /* 64490 800CCC90 0F80023C */  lui        $v0, %hi(_keystreamState)
    /* 64494 800CCC94 6CC2458C */  lw         $a1, %lo(_keystreamState)($v0)
    /* 64498 800CCC98 0D666334 */  ori        $v1, $v1, (0x19660D & 0xFFFF)
    /* 6449C 800CCC9C 1800A300 */  mult       $a1, $v1
    /* 644A0 800CCCA0 12300000 */  mflo       $a2
    /* 644A4 800CCCA4 6CC246AC */  sw         $a2, %lo(_keystreamState)($v0)
    /* 644A8 800CCCA8 20000224 */  addiu      $v0, $zero, 0x20
    /* 644AC 800CCCAC 23104400 */  subu       $v0, $v0, $a0
    /* 644B0 800CCCB0 0800E003 */  jr         $ra
    /* 644B4 800CCCB4 06104500 */   srlv      $v0, $a1, $v0
endlabel vs_battle_keystreamBits
