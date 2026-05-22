nonmatching __do_global_dtors, 0x68

glabel __do_global_dtors
    /* FE5C 8001F65C 0380083C */  lui        $t0, %hi(__initialised)
    /* FE60 8001F660 B00F088D */  lw         $t0, %lo(__initialised)($t0)
    /* FE64 8001F664 F0FFBD27 */  addiu      $sp, $sp, -0x10
    /* FE68 8001F668 0400B0AF */  sw         $s0, 0x4($sp)
    /* FE6C 8001F66C 0800B1AF */  sw         $s1, 0x8($sp)
    /* FE70 8001F670 0C00BFAF */  sw         $ra, 0xC($sp)
    /* FE74 8001F674 0D000011 */  beqz       $t0, .L8001F6AC
    /* FE78 8001F678 00000000 */   nop
    /* FE7C 8001F67C 0180103C */  lui        $s0, %hi(vs_overlay_slots)
    /* FE80 8001F680 00001026 */  addiu      $s0, $s0, %lo(vs_overlay_slots)
    /* FE84 8001F684 0000113C */  lui        $s1, (0x0 >> 16)
    /* FE88 8001F688 00003126 */  addiu      $s1, $s1, 0x0
    /* FE8C 8001F68C 07002012 */  beqz       $s1, .L8001F6AC
    /* FE90 8001F690 00000000 */   nop
  .L8001F694:
    /* FE94 8001F694 0000088E */  lw         $t0, 0x0($s0)
    /* FE98 8001F698 04001026 */  addiu      $s0, $s0, 0x4
    /* FE9C 8001F69C 09F80001 */  jalr       $t0
    /* FEA0 8001F6A0 FFFF3126 */   addiu     $s1, $s1, -0x1
    /* FEA4 8001F6A4 FBFF2016 */  bnez       $s1, .L8001F694
    /* FEA8 8001F6A8 00000000 */   nop
  .L8001F6AC:
    /* FEAC 8001F6AC 0C00BF8F */  lw         $ra, 0xC($sp)
    /* FEB0 8001F6B0 0800B18F */  lw         $s1, 0x8($sp)
    /* FEB4 8001F6B4 0400B08F */  lw         $s0, 0x4($sp)
    /* FEB8 8001F6B8 1000BD27 */  addiu      $sp, $sp, 0x10
    /* FEBC 8001F6BC 0800E003 */  jr         $ra
    /* FEC0 8001F6C0 00000000 */   nop
endlabel __do_global_dtors
