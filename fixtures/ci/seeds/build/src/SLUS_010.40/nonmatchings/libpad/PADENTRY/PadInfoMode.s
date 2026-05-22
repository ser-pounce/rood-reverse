nonmatching PadInfoMode, 0xF8

glabel PadInfoMode
    /* 1C15C 8002B95C 0380023C */  lui        $v0, %hi(D_800335B0)
    /* 1C160 8002B960 B035428C */  lw         $v0, %lo(D_800335B0)($v0)
    /* 1C164 8002B964 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C168 8002B968 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C16C 8002B96C 2180A000 */  addu       $s0, $a1, $zero
    /* 1C170 8002B970 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1C174 8002B974 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1C178 8002B978 09F84000 */  jalr       $v0
    /* 1C17C 8002B97C 2188C000 */   addu      $s1, $a2, $zero
    /* 1C180 8002B980 21184000 */  addu       $v1, $v0, $zero
    /* 1C184 8002B984 03000224 */  addiu      $v0, $zero, 0x3
    /* 1C188 8002B988 16000212 */  beq        $s0, $v0, .L8002B9E4
    /* 1C18C 8002B98C 0400022A */   slti      $v0, $s0, 0x4
    /* 1C190 8002B990 07004010 */  beqz       $v0, .L8002B9B0
    /* 1C194 8002B994 01000224 */   addiu     $v0, $zero, 0x1
    /* 1C198 8002B998 0C000212 */  beq        $s0, $v0, .L8002B9CC
    /* 1C19C 8002B99C 02000224 */   addiu     $v0, $zero, 0x2
    /* 1C1A0 8002B9A0 0D000212 */  beq        $s0, $v0, .L8002B9D8
    /* 1C1A4 8002B9A4 21100000 */   addu      $v0, $zero, $zero
    /* 1C1A8 8002B9A8 90AE0008 */  j          .L8002BA40
    /* 1C1AC 8002B9AC 00000000 */   nop
  .L8002B9B0:
    /* 1C1B0 8002B9B0 04000224 */  addiu      $v0, $zero, 0x4
    /* 1C1B4 8002B9B4 0E000212 */  beq        $s0, $v0, .L8002B9F0
    /* 1C1B8 8002B9B8 64000224 */   addiu     $v0, $zero, 0x64
    /* 1C1BC 8002B9BC 1C000212 */  beq        $s0, $v0, .L8002BA30
    /* 1C1C0 8002B9C0 21100000 */   addu      $v0, $zero, $zero
    /* 1C1C4 8002B9C4 90AE0008 */  j          .L8002BA40
    /* 1C1C8 8002B9C8 00000000 */   nop
  .L8002B9CC:
    /* 1C1CC 8002B9CC E8006290 */  lbu        $v0, 0xE8($v1)
    /* 1C1D0 8002B9D0 90AE0008 */  j          .L8002BA40
    /* 1C1D4 8002B9D4 00000000 */   nop
  .L8002B9D8:
    /* 1C1D8 8002B9D8 E6006294 */  lhu        $v0, 0xE6($v1)
    /* 1C1DC 8002B9DC 90AE0008 */  j          .L8002BA40
    /* 1C1E0 8002B9E0 00000000 */   nop
  .L8002B9E4:
    /* 1C1E4 8002B9E4 E4006290 */  lbu        $v0, 0xE4($v1)
    /* 1C1E8 8002B9E8 90AE0008 */  j          .L8002BA40
    /* 1C1EC 8002B9EC 00000000 */   nop
  .L8002B9F0:
    /* 1C1F0 8002B9F0 04002106 */  bgez       $s1, .L8002BA04
    /* 1C1F4 8002B9F4 00000000 */   nop
    /* 1C1F8 8002B9F8 E3006290 */  lbu        $v0, 0xE3($v1)
    /* 1C1FC 8002B9FC 90AE0008 */  j          .L8002BA40
    /* 1C200 8002BA00 00000000 */   nop
  .L8002BA04:
    /* 1C204 8002BA04 E3006290 */  lbu        $v0, 0xE3($v1)
    /* 1C208 8002BA08 00000000 */  nop
    /* 1C20C 8002BA0C 2A102202 */  slt        $v0, $s1, $v0
    /* 1C210 8002BA10 0A004010 */  beqz       $v0, .L8002BA3C
    /* 1C214 8002BA14 40101100 */   sll       $v0, $s1, 1
    /* 1C218 8002BA18 0000638C */  lw         $v1, 0x0($v1)
    /* 1C21C 8002BA1C 00000000 */  nop
    /* 1C220 8002BA20 21104300 */  addu       $v0, $v0, $v1
    /* 1C224 8002BA24 00004294 */  lhu        $v0, 0x0($v0)
    /* 1C228 8002BA28 90AE0008 */  j          .L8002BA40
    /* 1C22C 8002BA2C 00000000 */   nop
  .L8002BA30:
    /* 1C230 8002BA30 4C00628C */  lw         $v0, 0x4C($v1)
    /* 1C234 8002BA34 90AE0008 */  j          .L8002BA40
    /* 1C238 8002BA38 00000000 */   nop
  .L8002BA3C:
    /* 1C23C 8002BA3C 21100000 */  addu       $v0, $zero, $zero
  .L8002BA40:
    /* 1C240 8002BA40 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1C244 8002BA44 1400B18F */  lw         $s1, 0x14($sp)
    /* 1C248 8002BA48 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C24C 8002BA4C 0800E003 */  jr         $ra
    /* 1C250 8002BA50 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel PadInfoMode
