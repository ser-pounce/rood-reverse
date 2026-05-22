nonmatching func_80077130, 0xB0

glabel func_80077130
    /* E930 80077130 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* E934 80077134 3800B4AF */  sw         $s4, 0x38($sp)
    /* E938 80077138 21A08000 */  addu       $s4, $a0, $zero
    /* E93C 8007713C 3400B3AF */  sw         $s3, 0x34($sp)
    /* E940 80077140 2198A000 */  addu       $s3, $a1, $zero
    /* E944 80077144 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* E948 80077148 2188C000 */  addu       $s1, $a2, $zero
    /* E94C 8007714C 3000B2AF */  sw         $s2, 0x30($sp)
    /* E950 80077150 2190E000 */  addu       $s2, $a3, $zero
    /* E954 80077154 FF000224 */  addiu      $v0, $zero, 0xFF
    /* E958 80077158 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* E95C 8007715C 18002212 */  beq        $s1, $v0, .L800771C0
    /* E960 80077160 2800B0AF */   sw        $s0, 0x28($sp)
    /* E964 80077164 40101300 */  sll        $v0, $s3, 1
    /* E968 80077168 21805200 */  addu       $s0, $v0, $s2
    /* E96C 8007716C A16A020C */  jal        func_8009AA84
    /* E970 80077170 21200002 */   addu      $a0, $s0, $zero
    /* E974 80077174 12002012 */  beqz       $s1, .L800771C0
    /* E978 80077178 03000224 */   addiu     $v0, $zero, 0x3
    /* E97C 8007717C 1000A2A3 */  sb         $v0, 0x10($sp)
    /* E980 80077180 80101200 */  sll        $v0, $s2, 2
    /* E984 80077184 21108202 */  addu       $v0, $s4, $v0
    /* E988 80077188 1100B0A3 */  sb         $s0, 0x11($sp)
    /* E98C 8007718C 1200B1A7 */  sh         $s1, 0x12($sp)
    /* E990 80077190 4800428C */  lw         $v0, 0x48($v0)
    /* E994 80077194 2000B3A3 */  sb         $s3, 0x20($sp)
    /* E998 80077198 03004016 */  bnez       $s2, .L800771A8
    /* E99C 8007719C 1400A2AF */   sw        $v0, 0x14($sp)
    /* E9A0 800771A0 6BDC0108 */  j          .L800771AC
    /* E9A4 800771A4 F0000224 */   addiu     $v0, $zero, 0xF0
  .L800771A8:
    /* E9A8 800771A8 F1000224 */  addiu      $v0, $zero, 0xF1
  .L800771AC:
    /* E9AC 800771AC 2100A2A3 */  sb         $v0, 0x21($sp)
    /* E9B0 800771B0 5000A28F */  lw         $v0, 0x50($sp)
    /* E9B4 800771B4 1000A427 */  addiu      $a0, $sp, 0x10
    /* E9B8 800771B8 7A65020C */  jal        vs_battle_populateDataSlot
    /* E9BC 800771BC 2200A2A3 */   sb        $v0, 0x22($sp)
  .L800771C0:
    /* E9C0 800771C0 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* E9C4 800771C4 3800B48F */  lw         $s4, 0x38($sp)
    /* E9C8 800771C8 3400B38F */  lw         $s3, 0x34($sp)
    /* E9CC 800771CC 3000B28F */  lw         $s2, 0x30($sp)
    /* E9D0 800771D0 2C00B18F */  lw         $s1, 0x2C($sp)
    /* E9D4 800771D4 2800B08F */  lw         $s0, 0x28($sp)
    /* E9D8 800771D8 0800E003 */  jr         $ra
    /* E9DC 800771DC 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80077130
