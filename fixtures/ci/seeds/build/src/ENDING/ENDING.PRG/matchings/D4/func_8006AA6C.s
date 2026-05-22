nonmatching func_8006AA6C, 0x34

glabel func_8006AA6C
    /* 226C 8006AA6C 0E80023C */  lui        $v0, %hi(D_800DBB88)
    /* 2270 8006AA70 88BB4324 */  addiu      $v1, $v0, %lo(D_800DBB88)
    /* 2274 8006AA74 21200000 */  addu       $a0, $zero, $zero
  .L8006AA78:
    /* 2278 8006AA78 080060A4 */  sh         $zero, 0x8($v1)
    /* 227C 8006AA7C 01008224 */  addiu      $v0, $a0, 0x1
    /* 2280 8006AA80 21204000 */  addu       $a0, $v0, $zero
    /* 2284 8006AA84 00140200 */  sll        $v0, $v0, 16
    /* 2288 8006AA88 03140200 */  sra        $v0, $v0, 16
    /* 228C 8006AA8C 20004228 */  slti       $v0, $v0, 0x20
    /* 2290 8006AA90 F9FF4014 */  bnez       $v0, .L8006AA78
    /* 2294 8006AA94 30006324 */   addiu     $v1, $v1, 0x30
    /* 2298 8006AA98 0800E003 */  jr         $ra
    /* 229C 8006AA9C 00000000 */   nop
endlabel func_8006AA6C
