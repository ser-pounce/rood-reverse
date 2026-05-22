nonmatching func_800A48CC, 0x158

glabel func_800A48CC
    /* 3C0CC 800A48CC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3C0D0 800A48D0 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 3C0D4 800A48D4 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 3C0D8 800A48D8 80180400 */  sll        $v1, $a0, 2
    /* 3C0DC 800A48DC 21186200 */  addu       $v1, $v1, $v0
    /* 3C0E0 800A48E0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3C0E4 800A48E4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3C0E8 800A48E8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3C0EC 800A48EC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3C0F0 800A48F0 0000708C */  lw         $s0, 0x0($v1)
    /* 3C0F4 800A48F4 2190A000 */  addu       $s2, $a1, $zero
    /* 3C0F8 800A48F8 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 3C0FC 800A48FC 00000000 */  nop
    /* 3C100 800A4900 03004230 */  andi       $v0, $v0, 0x3
    /* 3C104 800A4904 40004014 */  bnez       $v0, .L800A4A08
    /* 3C108 800A4908 2188C000 */   addu      $s1, $a2, $zero
    /* 3C10C 800A490C 0800038E */  lw         $v1, 0x8($s0)
    /* 3C110 800A4910 1800023C */  lui        $v0, (0x180000 >> 16)
    /* 3C114 800A4914 24106200 */  and        $v0, $v1, $v0
    /* 3C118 800A4918 3B004014 */  bnez       $v0, .L800A4A08
    /* 3C11C 800A491C 0700023C */   lui       $v0, (0x70000 >> 16)
    /* 3C120 800A4920 24106200 */  and        $v0, $v1, $v0
    /* 3C124 800A4924 05004010 */  beqz       $v0, .L800A493C
    /* 3C128 800A4928 00000000 */   nop
    /* 3C12C 800A492C 2AD9020C */  jal        func_800B64A8
    /* 3C130 800A4930 00000000 */   nop
    /* 3C134 800A4934 82920208 */  j          .L800A4A08
    /* 3C138 800A4938 00000000 */   nop
  .L800A493C:
    /* 3C13C 800A493C 15002016 */  bnez       $s1, .L800A4994
    /* 3C140 800A4940 21282002 */   addu      $a1, $s1, $zero
    /* 3C144 800A4944 2F000524 */  addiu      $a1, $zero, 0x2F
    /* 3C148 800A4948 21300000 */  addu       $a2, $zero, $zero
    /* 3C14C 800A494C FBFF0324 */  addiu      $v1, $zero, -0x5
    /* 3C150 800A4950 B005028E */  lw         $v0, 0x5B0($s0)
    /* 3C154 800A4954 04000724 */  addiu      $a3, $zero, 0x4
    /* 3C158 800A4958 24104300 */  and        $v0, $v0, $v1
    /* 3C15C 800A495C FCFF0324 */  addiu      $v1, $zero, -0x4
    /* 3C160 800A4960 24104300 */  and        $v0, $v0, $v1
    /* 3C164 800A4964 8180020C */  jal        func_800A0204
    /* 3C168 800A4968 B00502AE */   sw        $v0, 0x5B0($s0)
    /* 3C16C 800A496C F8FF043C */  lui        $a0, (0xFFF8FFFF >> 16)
    /* 3C170 800A4970 FFFF8434 */  ori        $a0, $a0, (0xFFF8FFFF & 0xFFFF)
    /* 3C174 800A4974 0800028E */  lw         $v0, 0x8($s0)
    /* 3C178 800A4978 06000324 */  addiu      $v1, $zero, 0x6
    /* 3C17C 800A497C 110003A2 */  sb         $v1, 0x11($s0)
    /* 3C180 800A4980 0200033C */  lui        $v1, (0x20000 >> 16)
    /* 3C184 800A4984 24104400 */  and        $v0, $v0, $a0
    /* 3C188 800A4988 25104300 */  or         $v0, $v0, $v1
    /* 3C18C 800A498C 7E920208 */  j          .L800A49F8
    /* 3C190 800A4990 080002AE */   sw        $v0, 0x8($s0)
  .L800A4994:
    /* 3C194 800A4994 FBFF0324 */  addiu      $v1, $zero, -0x5
    /* 3C198 800A4998 B005028E */  lw         $v0, 0x5B0($s0)
    /* 3C19C 800A499C FCFF0624 */  addiu      $a2, $zero, -0x4
    /* 3C1A0 800A49A0 24104300 */  and        $v0, $v0, $v1
    /* 3C1A4 800A49A4 24204600 */  and        $a0, $v0, $a2
    /* 3C1A8 800A49A8 01008434 */  ori        $a0, $a0, 0x1
    /* 3C1AC 800A49AC 02002106 */  bgez       $s1, .L800A49B8
    /* 3C1B0 800A49B0 B00504AE */   sw        $a0, 0x5B0($s0)
    /* 3C1B4 800A49B4 FF0F2526 */  addiu      $a1, $s1, 0xFFF
  .L800A49B8:
    /* 3C1B8 800A49B8 B9050392 */  lbu        $v1, 0x5B9($s0)
    /* 3C1BC 800A49BC 03130500 */  sra        $v0, $a1, 12
    /* 3C1C0 800A49C0 2A104300 */  slt        $v0, $v0, $v1
    /* 3C1C4 800A49C4 05004014 */  bnez       $v0, .L800A49DC
    /* 3C1C8 800A49C8 F8FF023C */   lui       $v0, (0xFFF8FFFF >> 16)
    /* 3C1CC 800A49CC 24108600 */  and        $v0, $a0, $a2
    /* 3C1D0 800A49D0 06004234 */  ori        $v0, $v0, 0x6
    /* 3C1D4 800A49D4 B00502AE */  sw         $v0, 0x5B0($s0)
    /* 3C1D8 800A49D8 F8FF023C */  lui        $v0, (0xFFF8FFFF >> 16)
  .L800A49DC:
    /* 3C1DC 800A49DC 0800038E */  lw         $v1, 0x8($s0)
    /* 3C1E0 800A49E0 FFFF4234 */  ori        $v0, $v0, (0xFFF8FFFF & 0xFFFF)
    /* 3C1E4 800A49E4 110000A2 */  sb         $zero, 0x11($s0)
    /* 3C1E8 800A49E8 24186200 */  and        $v1, $v1, $v0
    /* 3C1EC 800A49EC 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 3C1F0 800A49F0 25186200 */  or         $v1, $v1, $v0
    /* 3C1F4 800A49F4 080003AE */  sw         $v1, 0x8($s0)
  .L800A49F8:
    /* 3C1F8 800A49F8 07000224 */  addiu      $v0, $zero, 0x7
    /* 3C1FC 800A49FC 481802A2 */  sb         $v0, 0x1848($s0)
    /* 3C200 800A4A00 4C1812A6 */  sh         $s2, 0x184C($s0)
    /* 3C204 800A4A04 501811AE */  sw         $s1, 0x1850($s0)
  .L800A4A08:
    /* 3C208 800A4A08 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3C20C 800A4A0C 1800B28F */  lw         $s2, 0x18($sp)
    /* 3C210 800A4A10 1400B18F */  lw         $s1, 0x14($sp)
    /* 3C214 800A4A14 1000B08F */  lw         $s0, 0x10($sp)
    /* 3C218 800A4A18 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 3C21C 800A4A1C 0800E003 */  jr         $ra
    /* 3C220 800A4A20 00000000 */   nop
endlabel func_800A48CC
