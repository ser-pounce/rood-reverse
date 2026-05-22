nonmatching _drawPointsRemaining, 0x138

glabel _drawPointsRemaining
    /* 114 80102914 6666023C */  lui        $v0, (0x66666667 >> 16)
    /* 118 80102918 67664234 */  ori        $v0, $v0, (0x66666667 & 0xFFFF)
    /* 11C 8010291C 1800A200 */  mult       $a1, $v0
    /* 120 80102920 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 124 80102924 21408000 */  addu       $t0, $a0, $zero
    /* 128 80102928 C3170500 */  sra        $v0, $a1, 31
    /* 12C 8010292C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 130 80102930 2800B2AF */  sw         $s2, 0x28($sp)
    /* 134 80102934 2400B1AF */  sw         $s1, 0x24($sp)
    /* 138 80102938 2000B0AF */  sw         $s0, 0x20($sp)
    /* 13C 8010293C 10480000 */  mfhi       $t1
    /* 140 80102940 83180900 */  sra        $v1, $t1, 2
    /* 144 80102944 23186200 */  subu       $v1, $v1, $v0
    /* 148 80102948 80100300 */  sll        $v0, $v1, 2
    /* 14C 8010294C 21104300 */  addu       $v0, $v0, $v1
    /* 150 80102950 40100200 */  sll        $v0, $v0, 1
    /* 154 80102954 2318A200 */  subu       $v1, $a1, $v0
    /* 158 80102958 0680023C */  lui        $v0, %hi(vs_main_artsStatus)
    /* 15C 8010295C 40004424 */  addiu      $a0, $v0, %lo(vs_main_artsStatus)
    /* 160 80102960 21106400 */  addu       $v0, $v1, $a0
    /* 164 80102964 00005190 */  lbu        $s1, 0x0($v0)
    /* 168 80102968 04000224 */  addiu      $v0, $zero, 0x4
    /* 16C 8010296C 31002212 */  beq        $s1, $v0, .L80102A34
    /* 170 80102970 40100300 */   sll       $v0, $v1, 1
    /* 174 80102974 21104400 */  addu       $v0, $v0, $a0
    /* 178 80102978 0580043C */  lui        $a0, %hi(vs_main_artsPointsRequirements)
    /* 17C 8010297C E4FD8424 */  addiu      $a0, $a0, %lo(vs_main_artsPointsRequirements)
    /* 180 80102980 0C004794 */  lhu        $a3, 0xC($v0)
    /* 184 80102984 40101100 */  sll        $v0, $s1, 1
    /* 188 80102988 C0180300 */  sll        $v1, $v1, 3
    /* 18C 8010298C 21104300 */  addu       $v0, $v0, $v1
    /* 190 80102990 21104400 */  addu       $v0, $v0, $a0
    /* 194 80102994 00004294 */  lhu        $v0, 0x0($v0)
    /* 198 80102998 00000000 */  nop
    /* 19C 8010299C 23384700 */  subu       $a3, $v0, $a3
    /* 1A0 801029A0 0200E104 */  bgez       $a3, .L801029AC
    /* 1A4 801029A4 CE000325 */   addiu     $v1, $t0, 0xCE
    /* 1A8 801029A8 21380000 */  addu       $a3, $zero, $zero
  .L801029AC:
    /* 1AC 801029AC 00110600 */  sll        $v0, $a2, 4
    /* 1B0 801029B0 32004224 */  addiu      $v0, $v0, 0x32
    /* 1B4 801029B4 00140200 */  sll        $v0, $v0, 16
    /* 1B8 801029B8 25906200 */  or         $s2, $v1, $v0
    /* 1BC 801029BC 0C001124 */  addiu      $s1, $zero, 0xC
    /* 1C0 801029C0 1000B027 */  addiu      $s0, $sp, 0x10
    /* 1C4 801029C4 54000224 */  addiu      $v0, $zero, 0x54
    /* 1C8 801029C8 1E00A2A3 */  sb         $v0, 0x1E($sp)
    /* 1CC 801029CC 50000224 */  addiu      $v0, $zero, 0x50
    /* 1D0 801029D0 1F00A0A3 */  sb         $zero, 0x1F($sp)
    /* 1D4 801029D4 1D00A2A3 */  sb         $v0, 0x1D($sp)
  .L801029D8:
    /* 1D8 801029D8 1533030C */  jal        vs_battle_toBCD
    /* 1DC 801029DC 2120E000 */   addu      $a0, $a3, $zero
    /* 1E0 801029E0 21384000 */  addu       $a3, $v0, $zero
    /* 1E4 801029E4 21181102 */  addu       $v1, $s0, $s1
    /* 1E8 801029E8 0F00E230 */  andi       $v0, $a3, 0xF
    /* 1EC 801029EC 30004224 */  addiu      $v0, $v0, 0x30
    /* 1F0 801029F0 000062A0 */  sb         $v0, 0x0($v1)
    /* 1F4 801029F4 03390700 */  sra        $a3, $a3, 4
    /* 1F8 801029F8 F7FFE014 */  bnez       $a3, .L801029D8
    /* 1FC 801029FC FFFF3126 */   addiu     $s1, $s1, -0x1
    /* 200 80102A00 1000B027 */  addiu      $s0, $sp, 0x10
    /* 204 80102A04 21801102 */  addu       $s0, $s0, $s1
    /* 208 80102A08 23000224 */  addiu      $v0, $zero, 0x23
    /* 20C 80102A0C 000002A2 */  sb         $v0, 0x0($s0)
    /* 210 80102A10 1080043C */  lui        $a0, %hi(D_80102804)
    /* 214 80102A14 04288424 */  addiu      $a0, $a0, %lo(D_80102804)
    /* 218 80102A18 21284002 */  addu       $a1, $s2, $zero
    /* 21C 80102A1C 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 220 80102A20 21300000 */   addu      $a2, $zero, $zero
    /* 224 80102A24 21200002 */  addu       $a0, $s0, $zero
    /* 228 80102A28 60004526 */  addiu      $a1, $s2, 0x60
    /* 22C 80102A2C 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 230 80102A30 21300000 */   addu      $a2, $zero, $zero
  .L80102A34:
    /* 234 80102A34 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 238 80102A38 2800B28F */  lw         $s2, 0x28($sp)
    /* 23C 80102A3C 2400B18F */  lw         $s1, 0x24($sp)
    /* 240 80102A40 2000B08F */  lw         $s0, 0x20($sp)
    /* 244 80102A44 0800E003 */  jr         $ra
    /* 248 80102A48 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _drawPointsRemaining
