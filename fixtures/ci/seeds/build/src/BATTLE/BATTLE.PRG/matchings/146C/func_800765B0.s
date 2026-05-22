nonmatching func_800765B0, 0x1D4

glabel func_800765B0
    /* DDB0 800765B0 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* DDB4 800765B4 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* DDB8 800765B8 21888000 */  addu       $s1, $a0, $zero
    /* DDBC 800765BC 3000B2AF */  sw         $s2, 0x30($sp)
    /* DDC0 800765C0 2190A000 */  addu       $s2, $a1, $zero
    /* DDC4 800765C4 3400B3AF */  sw         $s3, 0x34($sp)
    /* DDC8 800765C8 2198C000 */  addu       $s3, $a2, $zero
    /* DDCC 800765CC 3800B4AF */  sw         $s4, 0x38($sp)
    /* DDD0 800765D0 21A0E000 */  addu       $s4, $a3, $zero
    /* DDD4 800765D4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* DDD8 800765D8 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* DDDC 800765DC 17002216 */  bne        $s1, $v0, .L8007663C
    /* DDE0 800765E0 2800B0AF */   sw        $s0, 0x28($sp)
    /* DDE4 800765E4 02000324 */  addiu      $v1, $zero, 0x2
    /* DDE8 800765E8 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* DDEC 800765EC 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* DDF0 800765F0 08004424 */  addiu      $a0, $v0, 0x8
  .L800765F4:
    /* DDF4 800765F4 0000828C */  lw         $v0, 0x0($a0)
    /* DDF8 800765F8 00000000 */  nop
    /* DDFC 800765FC 0D004010 */  beqz       $v0, .L80076634
    /* DE00 80076600 00000000 */   nop
    /* DE04 80076604 01006324 */  addiu      $v1, $v1, 0x1
    /* DE08 80076608 10006228 */  slti       $v0, $v1, 0x10
    /* DE0C 8007660C F9FF4014 */  bnez       $v0, .L800765F4
    /* DE10 80076610 04008424 */   addiu     $a0, $a0, 0x4
  .L80076614:
    /* DE14 80076614 10006228 */  slti       $v0, $v1, 0x10
    /* DE18 80076618 09004014 */  bnez       $v0, .L80076640
    /* DE1C 8007661C 0F80023C */   lui       $v0, %hi(vs_battle_actors)
    /* DE20 80076620 86000424 */  addiu      $a0, $zero, 0x86
    /* DE24 80076624 2824010C */  jal        vs_main_nop10
    /* DE28 80076628 21280000 */   addu      $a1, $zero, $zero
    /* DE2C 8007662C D9D90108 */  j          .L80076764
    /* DE30 80076630 21100000 */   addu      $v0, $zero, $zero
  .L80076634:
    /* DE34 80076634 85D90108 */  j          .L80076614
    /* DE38 80076638 21886000 */   addu      $s1, $v1, $zero
  .L8007663C:
    /* DE3C 8007663C 0F80023C */  lui        $v0, %hi(vs_battle_actors)
  .L80076640:
    /* DE40 80076640 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* DE44 80076644 80181100 */  sll        $v1, $s1, 2
    /* DE48 80076648 21186200 */  addu       $v1, $v1, $v0
    /* DE4C 8007664C 0000628C */  lw         $v0, 0x0($v1)
    /* DE50 80076650 00000000 */  nop
    /* DE54 80076654 43004014 */  bnez       $v0, .L80076764
    /* DE58 80076658 21100000 */   addu      $v0, $zero, $zero
    /* DE5C 8007665C B10F010C */  jal        vs_main_allocHeap
    /* DE60 80076660 2C0B0424 */   addiu     $a0, $zero, 0xB2C
    /* DE64 80076664 21804000 */  addu       $s0, $v0, $zero
    /* DE68 80076668 21200002 */  addu       $a0, $s0, $zero
    /* DE6C 8007666C 4424010C */  jal        vs_main_bzero
    /* DE70 80076670 B4090524 */   addiu     $a1, $zero, 0x9B4
    /* DE74 80076674 50000226 */  addiu      $v0, $s0, 0x50
    /* DE78 80076678 3C0002AE */  sw         $v0, 0x3C($s0)
    /* DE7C 8007667C B4090226 */  addiu      $v0, $s0, 0x9B4
    /* DE80 80076680 440002AE */  sw         $v0, 0x44($s0)
    /* DE84 80076684 FE000224 */  addiu      $v0, $zero, 0xFE
    /* DE88 80076688 180002A6 */  sh         $v0, 0x18($s0)
    /* DE8C 8007668C 10000224 */  addiu      $v0, $zero, 0x10
    /* DE90 80076690 1C0002A6 */  sh         $v0, 0x1C($s0)
    /* DE94 80076694 06000224 */  addiu      $v0, $zero, 0x6
    /* DE98 80076698 400000AE */  sw         $zero, 0x40($s0)
    /* DE9C 8007669C 040011AE */  sw         $s1, 0x4($s0)
    /* DEA0 800766A0 000000AE */  sw         $zero, 0x0($s0)
    /* DEA4 800766A4 260000A2 */  sb         $zero, 0x26($s0)
    /* DEA8 800766A8 1000A2A3 */  sb         $v0, 0x10($sp)
    /* DEAC 800766AC 1100B1A3 */  sb         $s1, 0x11($sp)
    /* DEB0 800766B0 0000628E */  lw         $v0, 0x0($s3)
    /* DEB4 800766B4 00000000 */  nop
    /* DEB8 800766B8 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* DEBC 800766BC 1D00A293 */  lbu        $v0, 0x1D($sp)
    /* DEC0 800766C0 00000000 */  nop
    /* DEC4 800766C4 01004230 */  andi       $v0, $v0, 0x1
    /* DEC8 800766C8 1D00A2A3 */  sb         $v0, 0x1D($sp)
    /* DECC 800766CC 4400028E */  lw         $v0, 0x44($s0)
    /* DED0 800766D0 21184002 */  addu       $v1, $s2, $zero
    /* DED4 800766D4 2000B2A3 */  sb         $s2, 0x20($sp)
    /* DED8 800766D8 02004106 */  bgez       $s2, .L800766E4
    /* DEDC 800766DC 1400A2AF */   sw        $v0, 0x14($sp)
    /* DEE0 800766E0 FF004326 */  addiu      $v1, $s2, 0xFF
  .L800766E4:
    /* DEE4 800766E4 03120300 */  sra        $v0, $v1, 8
    /* DEE8 800766E8 2100A2A3 */  sb         $v0, 0x21($sp)
    /* DEEC 800766EC 2200B4A3 */  sb         $s4, 0x22($sp)
    /* DEF0 800766F0 01006292 */  lbu        $v0, 0x1($s3)
    /* DEF4 800766F4 1000A427 */  addiu      $a0, $sp, 0x10
    /* DEF8 800766F8 02110200 */  srl        $v0, $v0, 4
    /* DEFC 800766FC 7A65020C */  jal        vs_battle_populateDataSlot
    /* DF00 80076700 2300A2A3 */   sb        $v0, 0x23($sp)
  .L80076704:
    /* DF04 80076704 6C65020C */  jal        vs_battle_getEmptyObjectDataSlot
    /* DF08 80076708 00000000 */   nop
    /* DF0C 8007670C 07004010 */  beqz       $v0, .L8007672C
    /* DF10 80076710 0F80033C */   lui       $v1, %hi(vs_battle_actors)
    /* DF14 80076714 9F65020C */  jal        vs_battle_processObjectDataQueue
    /* DF18 80076718 00000000 */   nop
    /* DF1C 8007671C 8709010C */  jal        vs_main_gametimeUpdate
    /* DF20 80076720 21200000 */   addu      $a0, $zero, $zero
    /* DF24 80076724 C1D90108 */  j          .L80076704
    /* DF28 80076728 00000000 */   nop
  .L8007672C:
    /* DF2C 8007672C 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* DF30 80076730 80101100 */  sll        $v0, $s1, 2
    /* DF34 80076734 21104300 */  addu       $v0, $v0, $v1
    /* DF38 80076738 000050AC */  sw         $s0, 0x0($v0)
    /* DF3C 8007673C 21202002 */  addu       $a0, $s1, $zero
    /* DF40 80076740 1FD9010C */  jal        func_8007647C
    /* DF44 80076744 21284002 */   addu      $a1, $s2, $zero
    /* DF48 80076748 21200002 */  addu       $a0, $s0, $zero
    /* DF4C 8007674C 5E98030C */  jal        func_800E6178
    /* DF50 80076750 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* DF54 80076754 21202002 */  addu       $a0, $s1, $zero
    /* DF58 80076758 1F82020C */  jal        func_800A087C
    /* DF5C 8007675C 46180524 */   addiu     $a1, $zero, 0x1846
    /* DF60 80076760 21100002 */  addu       $v0, $s0, $zero
  .L80076764:
    /* DF64 80076764 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* DF68 80076768 3800B48F */  lw         $s4, 0x38($sp)
    /* DF6C 8007676C 3400B38F */  lw         $s3, 0x34($sp)
    /* DF70 80076770 3000B28F */  lw         $s2, 0x30($sp)
    /* DF74 80076774 2C00B18F */  lw         $s1, 0x2C($sp)
    /* DF78 80076778 2800B08F */  lw         $s0, 0x28($sp)
    /* DF7C 8007677C 0800E003 */  jr         $ra
    /* DF80 80076780 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800765B0
