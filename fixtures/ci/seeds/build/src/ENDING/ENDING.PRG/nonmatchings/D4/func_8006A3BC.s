nonmatching func_8006A3BC, 0x7C

glabel func_8006A3BC
    /* 1BBC 8006A3BC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1BC0 8006A3C0 21288000 */  addu       $a1, $a0, $zero
    /* 1BC4 8006A3C4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1BC8 8006A3C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1BCC 8006A3CC 0800A384 */  lh         $v1, 0x8($a1)
    /* 1BD0 8006A3D0 01000224 */  addiu      $v0, $zero, 0x1
    /* 1BD4 8006A3D4 03006214 */  bne        $v1, $v0, .L8006A3E4
    /* 1BD8 8006A3D8 02000224 */   addiu     $v0, $zero, 0x2
    /* 1BDC 8006A3DC 0A00A0A4 */  sh         $zero, 0xA($a1)
    /* 1BE0 8006A3E0 0800A2A4 */  sh         $v0, 0x8($a1)
  .L8006A3E4:
    /* 1BE4 8006A3E4 0A00A294 */  lhu        $v0, 0xA($a1)
    /* 1BE8 8006A3E8 80000324 */  addiu      $v1, $zero, 0x80
    /* 1BEC 8006A3EC 01004224 */  addiu      $v0, $v0, 0x1
    /* 1BF0 8006A3F0 0A00A2A4 */  sh         $v0, 0xA($a1)
    /* 1BF4 8006A3F4 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 1BF8 8006A3F8 05004314 */  bne        $v0, $v1, .L8006A410
    /* 1BFC 8006A3FC 0E80103C */   lui       $s0, %hi(D_800DC19C)
    /* 1C00 8006A400 0E80023C */  lui        $v0, %hi(D_800DC189)
    /* 1C04 8006A404 89C140A0 */  sb         $zero, %lo(D_800DC189)($v0)
    /* 1C08 8006A408 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1C0C 8006A40C 0800A2A4 */  sh         $v0, 0x8($a1)
  .L8006A410:
    /* 1C10 8006A410 21200000 */  addu       $a0, $zero, $zero
    /* 1C14 8006A414 0A00A584 */  lh         $a1, 0xA($a1)
    /* 1C18 8006A418 95AB010C */  jal        func_8006AE54
    /* 1C1C 8006A41C 80000624 */   addiu     $a2, $zero, 0x80
    /* 1C20 8006A420 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1C24 8006A424 42110200 */  srl        $v0, $v0, 5
    /* 1C28 8006A428 9CC102A6 */  sh         $v0, %lo(D_800DC19C)($s0)
    /* 1C2C 8006A42C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C30 8006A430 0800E003 */  jr         $ra
    /* 1C34 8006A434 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006A3BC
