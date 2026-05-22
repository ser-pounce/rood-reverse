nonmatching _memcardMakeFilename, 0x7C

glabel _memcardMakeFilename
    /* 3BC 80102BBC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3C0 80102BC0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3C4 80102BC4 21808000 */  addu       $s0, $a0, $zero
    /* 3C8 80102BC8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3CC 80102BCC 2190A000 */  addu       $s2, $a1, $zero
    /* 3D0 80102BD0 1180023C */  lui        $v0, %hi(_filename0)
    /* 3D4 80102BD4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3D8 80102BD8 40AA5124 */  addiu      $s1, $v0, %lo(_filename0)
    /* 3DC 80102BDC 21202002 */  addu       $a0, $s1, $zero
    /* 3E0 80102BE0 21280000 */  addu       $a1, $zero, $zero
    /* 3E4 80102BE4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3E8 80102BE8 AD9B000C */  jal        memset
    /* 3EC 80102BEC 20000624 */   addiu     $a2, $zero, 0x20
    /* 3F0 80102BF0 1180023C */  lui        $v0, %hi(_memcardFilenameTemplate)
    /* 3F4 80102BF4 B4A2458C */  lw         $a1, %lo(_memcardFilenameTemplate)($v0)
    /* 3F8 80102BF8 A19B000C */  jal        strcpy
    /* 3FC 80102BFC 21202002 */   addu      $a0, $s1, $zero
    /* 400 80102C00 02000016 */  bnez       $s0, .L80102C0C
    /* 404 80102C04 31000224 */   addiu     $v0, $zero, 0x31
    /* 408 80102C08 30000224 */  addiu      $v0, $zero, 0x30
  .L80102C0C:
    /* 40C 80102C0C 020022A2 */  sb         $v0, 0x2($s1)
    /* 410 80102C10 1180023C */  lui        $v0, %hi(_filename0)
    /* 414 80102C14 40AA4224 */  addiu      $v0, $v0, %lo(_filename0)
    /* 418 80102C18 30004326 */  addiu      $v1, $s2, 0x30
    /* 41C 80102C1C 140043A0 */  sb         $v1, 0x14($v0)
    /* 420 80102C20 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 424 80102C24 1800B28F */  lw         $s2, 0x18($sp)
    /* 428 80102C28 1400B18F */  lw         $s1, 0x14($sp)
    /* 42C 80102C2C 1000B08F */  lw         $s0, 0x10($sp)
    /* 430 80102C30 0800E003 */  jr         $ra
    /* 434 80102C34 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _memcardMakeFilename
