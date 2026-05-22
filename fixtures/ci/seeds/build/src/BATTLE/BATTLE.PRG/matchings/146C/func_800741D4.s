nonmatching func_800741D4, 0x78

glabel func_800741D4
    /* B9D4 800741D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B9D8 800741D8 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* B9DC 800741DC 02000224 */  addiu      $v0, $zero, 0x2
    /* B9E0 800741E0 F01862AC */  sw         $v0, %lo(_cameraMode)($v1)
    /* B9E4 800741E4 0F80023C */  lui        $v0, %hi(D_800F196C)
    /* B9E8 800741E8 6C19438C */  lw         $v1, %lo(D_800F196C)($v0)
    /* B9EC 800741EC 08000224 */  addiu      $v0, $zero, 0x8
    /* B9F0 800741F0 0C006214 */  bne        $v1, $v0, .L80074224
    /* B9F4 800741F4 1000BFAF */   sw        $ra, 0x10($sp)
    /* B9F8 800741F8 0F80023C */  lui        $v0, %hi(D_800F1910)
    /* B9FC 800741FC 10194324 */  addiu      $v1, $v0, %lo(D_800F1910)
    /* BA00 80074200 04006524 */  addiu      $a1, $v1, 0x4
    /* BA04 80074204 0680073C */  lui        $a3, %hi(vs_gametime_tickspeed)
    /* BA08 80074208 1019448C */  lw         $a0, %lo(D_800F1910)($v0)
    /* BA0C 8007420C 1000668C */  lw         $a2, 0x10($v1)
    /* BA10 80074210 04000224 */  addiu      $v0, $zero, 0x4
    /* BA14 80074214 4CCF010C */  jal        func_80073D30
    /* BA18 80074218 4CE2E2AC */   sw        $v0, %lo(vs_gametime_tickspeed)($a3)
    /* BA1C 8007421C 8FD00108 */  j          .L8007423C
    /* BA20 80074220 00000000 */   nop
  .L80074224:
    /* BA24 80074224 0F80023C */  lui        $v0, %hi(D_800F1910)
    /* BA28 80074228 1019448C */  lw         $a0, %lo(D_800F1910)($v0)
    /* BA2C 8007422C 10194224 */  addiu      $v0, $v0, %lo(D_800F1910)
    /* BA30 80074230 1000458C */  lw         $a1, 0x10($v0)
    /* BA34 80074234 8CCF010C */  jal        func_80073E30
    /* BA38 80074238 00000000 */   nop
  .L8007423C:
    /* BA3C 8007423C 1000BF8F */  lw         $ra, 0x10($sp)
    /* BA40 80074240 00000000 */  nop
    /* BA44 80074244 0800E003 */  jr         $ra
    /* BA48 80074248 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800741D4
