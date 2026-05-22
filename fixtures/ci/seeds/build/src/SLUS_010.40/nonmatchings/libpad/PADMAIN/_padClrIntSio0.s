nonmatching _padClrIntSio0, 0x90

glabel _padClrIntSio0
    /* 1D1B0 8002C9B0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D1B4 8002C9B4 0380033C */  lui        $v1, %hi(D_800335FC)
    /* 1D1B8 8002C9B8 FC35638C */  lw         $v1, %lo(D_800335FC)($v1)
    /* 1D1BC 8002C9BC 0380043C */  lui        $a0, %hi(D_80033600)
    /* 1D1C0 8002C9C0 0036848C */  lw         $a0, %lo(D_80033600)($a0)
    /* 1D1C4 8002C9C4 7FFF0224 */  addiu      $v0, $zero, -0x81
    /* 1D1C8 8002C9C8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1D1CC 8002C9CC 000062AC */  sw         $v0, 0x0($v1)
    /* 1D1D0 8002C9D0 04008294 */  lhu        $v0, 0x4($a0)
    /* 1D1D4 8002C9D4 00000000 */  nop
    /* 1D1D8 8002C9D8 80004230 */  andi       $v0, $v0, 0x80
    /* 1D1DC 8002C9DC 0D004010 */  beqz       $v0, .L8002CA14
    /* 1D1E0 8002C9E0 00000000 */   nop
  .L8002C9E4:
    /* 1D1E4 8002C9E4 05BA000C */  jal        chkRC2wait
    /* 1D1E8 8002C9E8 00000000 */   nop
    /* 1D1EC 8002C9EC 10004014 */  bnez       $v0, .L8002CA30
    /* 1D1F0 8002C9F0 21100000 */   addu      $v0, $zero, $zero
    /* 1D1F4 8002C9F4 0380023C */  lui        $v0, %hi(D_80033600)
    /* 1D1F8 8002C9F8 0036428C */  lw         $v0, %lo(D_80033600)($v0)
    /* 1D1FC 8002C9FC 00000000 */  nop
    /* 1D200 8002CA00 04004294 */  lhu        $v0, 0x4($v0)
    /* 1D204 8002CA04 00000000 */  nop
    /* 1D208 8002CA08 80004230 */  andi       $v0, $v0, 0x80
    /* 1D20C 8002CA0C F5FF4014 */  bnez       $v0, .L8002C9E4
    /* 1D210 8002CA10 00000000 */   nop
  .L8002CA14:
    /* 1D214 8002CA14 0380043C */  lui        $a0, %hi(D_80033600)
    /* 1D218 8002CA18 0036848C */  lw         $a0, %lo(D_80033600)($a0)
    /* 1D21C 8002CA1C 00000000 */  nop
    /* 1D220 8002CA20 0A008394 */  lhu        $v1, 0xA($a0)
    /* 1D224 8002CA24 01000224 */  addiu      $v0, $zero, 0x1
    /* 1D228 8002CA28 10006334 */  ori        $v1, $v1, 0x10
    /* 1D22C 8002CA2C 0A0083A4 */  sh         $v1, 0xA($a0)
  .L8002CA30:
    /* 1D230 8002CA30 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1D234 8002CA34 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1D238 8002CA38 0800E003 */  jr         $ra
    /* 1D23C 8002CA3C 00000000 */   nop
endlabel _padClrIntSio0
