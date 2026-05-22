nonmatching LoadTPage, 0xE8

glabel LoadTPage
    /* 1BA14 8002B214 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1BA18 8002B218 2400B3AF */  sw         $s3, 0x24($sp)
    /* 1BA1C 8002B21C 4000B38F */  lw         $s3, 0x40($sp)
    /* 1BA20 8002B220 4400A38F */  lw         $v1, 0x44($sp)
    /* 1BA24 8002B224 4800A28F */  lw         $v0, 0x48($sp)
    /* 1BA28 8002B228 21408000 */  addu       $t0, $a0, $zero
    /* 1BA2C 8002B22C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1BA30 8002B230 2180A000 */  addu       $s0, $a1, $zero
    /* 1BA34 8002B234 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1BA38 8002B238 2190C000 */  addu       $s2, $a2, $zero
    /* 1BA3C 8002B23C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1BA40 8002B240 2188E000 */  addu       $s1, $a3, $zero
    /* 1BA44 8002B244 2800BFAF */  sw         $ra, 0x28($sp)
    /* 1BA48 8002B248 1000B1A7 */  sh         $s1, 0x10($sp)
    /* 1BA4C 8002B24C 1600A2A7 */  sh         $v0, 0x16($sp)
    /* 1BA50 8002B250 01000224 */  addiu      $v0, $zero, 0x1
    /* 1BA54 8002B254 13000212 */  beq        $s0, $v0, .L8002B2A4
    /* 1BA58 8002B258 1200B3A7 */   sh        $s3, 0x12($sp)
    /* 1BA5C 8002B25C 0200022A */  slti       $v0, $s0, 0x2
    /* 1BA60 8002B260 05004010 */  beqz       $v0, .L8002B278
    /* 1BA64 8002B264 00000000 */   nop
    /* 1BA68 8002B268 08000012 */  beqz       $s0, .L8002B28C
    /* 1BA6C 8002B26C 1000A427 */   addiu     $a0, $sp, 0x10
    /* 1BA70 8002B270 B0AC0008 */  j          .L8002B2C0
    /* 1BA74 8002B274 00000000 */   nop
  .L8002B278:
    /* 1BA78 8002B278 02000224 */  addiu      $v0, $zero, 0x2
    /* 1BA7C 8002B27C 0E000212 */  beq        $s0, $v0, .L8002B2B8
    /* 1BA80 8002B280 1000A427 */   addiu     $a0, $sp, 0x10
    /* 1BA84 8002B284 B0AC0008 */  j          .L8002B2C0
    /* 1BA88 8002B288 00000000 */   nop
  .L8002B28C:
    /* 1BA8C 8002B28C 02006104 */  bgez       $v1, .L8002B298
    /* 1BA90 8002B290 21106000 */   addu      $v0, $v1, $zero
    /* 1BA94 8002B294 03006224 */  addiu      $v0, $v1, 0x3
  .L8002B298:
    /* 1BA98 8002B298 83100200 */  sra        $v0, $v0, 2
    /* 1BA9C 8002B29C AFAC0008 */  j          .L8002B2BC
    /* 1BAA0 8002B2A0 1400A2A7 */   sh        $v0, 0x14($sp)
  .L8002B2A4:
    /* 1BAA4 8002B2A4 C2170300 */  srl        $v0, $v1, 31
    /* 1BAA8 8002B2A8 21106200 */  addu       $v0, $v1, $v0
    /* 1BAAC 8002B2AC 43100200 */  sra        $v0, $v0, 1
    /* 1BAB0 8002B2B0 AFAC0008 */  j          .L8002B2BC
    /* 1BAB4 8002B2B4 1400A2A7 */   sh        $v0, 0x14($sp)
  .L8002B2B8:
    /* 1BAB8 8002B2B8 1400A3A7 */  sh         $v1, 0x14($sp)
  .L8002B2BC:
    /* 1BABC 8002B2BC 1000A427 */  addiu      $a0, $sp, 0x10
  .L8002B2C0:
    /* 1BAC0 8002B2C0 3FA2000C */  jal        LoadImage
    /* 1BAC4 8002B2C4 21280001 */   addu      $a1, $t0, $zero
    /* 1BAC8 8002B2C8 21200002 */  addu       $a0, $s0, $zero
    /* 1BACC 8002B2CC 21284002 */  addu       $a1, $s2, $zero
    /* 1BAD0 8002B2D0 21302002 */  addu       $a2, $s1, $zero
    /* 1BAD4 8002B2D4 1DAD000C */  jal        GetTPage
    /* 1BAD8 8002B2D8 21386002 */   addu      $a3, $s3, $zero
    /* 1BADC 8002B2DC FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 1BAE0 8002B2E0 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1BAE4 8002B2E4 2400B38F */  lw         $s3, 0x24($sp)
    /* 1BAE8 8002B2E8 2000B28F */  lw         $s2, 0x20($sp)
    /* 1BAEC 8002B2EC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1BAF0 8002B2F0 1800B08F */  lw         $s0, 0x18($sp)
    /* 1BAF4 8002B2F4 0800E003 */  jr         $ra
    /* 1BAF8 8002B2F8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel LoadTPage
    /* 1BAFC 8002B2FC 00000000 */  nop
    /* 1BB00 8002B300 00000000 */  nop
