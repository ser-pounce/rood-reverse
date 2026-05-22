nonmatching func_8006A438, 0xA0

glabel func_8006A438
    /* 1C38 8006A438 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C3C 8006A43C 21288000 */  addu       $a1, $a0, $zero
    /* 1C40 8006A440 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1C44 8006A444 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C48 8006A448 0800A284 */  lh         $v0, 0x8($a1)
    /* 1C4C 8006A44C 01000424 */  addiu      $a0, $zero, 0x1
    /* 1C50 8006A450 05004414 */  bne        $v0, $a0, .L8006A468
    /* 1C54 8006A454 02000224 */   addiu     $v0, $zero, 0x2
    /* 1C58 8006A458 0800A2A4 */  sh         $v0, 0x8($a1)
    /* 1C5C 8006A45C 0E80023C */  lui        $v0, %hi(D_800DC189)
    /* 1C60 8006A460 0A00A0A4 */  sh         $zero, 0xA($a1)
    /* 1C64 8006A464 89C144A0 */  sb         $a0, %lo(D_800DC189)($v0)
  .L8006A468:
    /* 1C68 8006A468 0A00A294 */  lhu        $v0, 0xA($a1)
    /* 1C6C 8006A46C 80000324 */  addiu      $v1, $zero, 0x80
    /* 1C70 8006A470 01004224 */  addiu      $v0, $v0, 0x1
    /* 1C74 8006A474 0A00A2A4 */  sh         $v0, 0xA($a1)
    /* 1C78 8006A478 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 1C7C 8006A47C 09004314 */  bne        $v0, $v1, .L8006A4A4
    /* 1C80 8006A480 0E80103C */   lui       $s0, %hi(D_800DC19C)
    /* 1C84 8006A484 0E00A294 */  lhu        $v0, 0xE($a1)
    /* 1C88 8006A488 00000000 */  nop
    /* 1C8C 8006A48C 02004010 */  beqz       $v0, .L8006A498
    /* 1C90 8006A490 0E80023C */   lui       $v0, %hi(D_800DC188)
    /* 1C94 8006A494 88C144A0 */  sb         $a0, %lo(D_800DC188)($v0)
  .L8006A498:
    /* 1C98 8006A498 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1C9C 8006A49C 0800A2A4 */  sh         $v0, 0x8($a1)
    /* 1CA0 8006A4A0 0E80103C */  lui        $s0, %hi(D_800DC19C)
  .L8006A4A4:
    /* 1CA4 8006A4A4 21200000 */  addu       $a0, $zero, $zero
    /* 1CA8 8006A4A8 0A00A584 */  lh         $a1, 0xA($a1)
    /* 1CAC 8006A4AC 95AB010C */  jal        func_8006AE54
    /* 1CB0 8006A4B0 80000624 */   addiu     $a2, $zero, 0x80
    /* 1CB4 8006A4B4 C0110200 */  sll        $v0, $v0, 7
    /* 1CB8 8006A4B8 03130200 */  sra        $v0, $v0, 12
    /* 1CBC 8006A4BC 80000324 */  addiu      $v1, $zero, 0x80
    /* 1CC0 8006A4C0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1CC4 8006A4C4 23186200 */  subu       $v1, $v1, $v0
    /* 1CC8 8006A4C8 9CC103A6 */  sh         $v1, %lo(D_800DC19C)($s0)
    /* 1CCC 8006A4CC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1CD0 8006A4D0 0800E003 */  jr         $ra
    /* 1CD4 8006A4D4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006A438
