nonmatching __main, 0x70

glabel __main
    /* FDEC 8001F5EC 0380083C */  lui        $t0, %hi(__initialised)
    /* FDF0 8001F5F0 B00F088D */  lw         $t0, %lo(__initialised)($t0)
    /* FDF4 8001F5F4 F0FFBD27 */  addiu      $sp, $sp, -0x10
    /* FDF8 8001F5F8 0400B0AF */  sw         $s0, 0x4($sp)
    /* FDFC 8001F5FC 0800B1AF */  sw         $s1, 0x8($sp)
    /* FE00 8001F600 0C00BFAF */  sw         $ra, 0xC($sp)
    /* FE04 8001F604 0F000015 */  bnez       $t0, .L8001F644
    /* FE08 8001F608 01000834 */   ori       $t0, $zero, 0x1
    /* FE0C 8001F60C 0380013C */  lui        $at, %hi(__initialised)
    /* FE10 8001F610 B00F28AC */  sw         $t0, %lo(__initialised)($at)
    /* FE14 8001F614 0180103C */  lui        $s0, %hi(vs_overlay_slots)
    /* FE18 8001F618 00001026 */  addiu      $s0, $s0, %lo(vs_overlay_slots)
    /* FE1C 8001F61C 0000113C */  lui        $s1, (0x0 >> 16)
    /* FE20 8001F620 00003126 */  addiu      $s1, $s1, 0x0
    /* FE24 8001F624 07002012 */  beqz       $s1, .L8001F644
    /* FE28 8001F628 00000000 */   nop
  .L8001F62C:
    /* FE2C 8001F62C 0000088E */  lw         $t0, 0x0($s0)
    /* FE30 8001F630 04001026 */  addiu      $s0, $s0, 0x4
    /* FE34 8001F634 09F80001 */  jalr       $t0
    /* FE38 8001F638 FFFF3126 */   addiu     $s1, $s1, -0x1
    /* FE3C 8001F63C FBFF2016 */  bnez       $s1, .L8001F62C
    /* FE40 8001F640 00000000 */   nop
  .L8001F644:
    /* FE44 8001F644 0C00BF8F */  lw         $ra, 0xC($sp)
    /* FE48 8001F648 0800B18F */  lw         $s1, 0x8($sp)
    /* FE4C 8001F64C 0400B08F */  lw         $s0, 0x4($sp)
    /* FE50 8001F650 1000BD27 */  addiu      $sp, $sp, 0x10
    /* FE54 8001F654 0800E003 */  jr         $ra
    /* FE58 8001F658 00000000 */   nop
endlabel __main
