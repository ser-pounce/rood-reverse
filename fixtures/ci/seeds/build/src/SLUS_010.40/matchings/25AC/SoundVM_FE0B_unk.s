nonmatching SoundVM_FE0B_unk, 0xB8

glabel SoundVM_FE0B_unk
    /* D3CC 8001CBCC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D3D0 8001CBD0 1000B0AF */  sw         $s0, 0x10($sp)
    /* D3D4 8001CBD4 21808000 */  addu       $s0, $a0, $zero
    /* D3D8 8001CBD8 1400BFAF */  sw         $ra, 0x14($sp)
    /* D3DC 8001CBDC 0000048E */  lw         $a0, 0x0($s0)
    /* D3E0 8001CBE0 00000000 */  nop
    /* D3E4 8001CBE4 01008290 */  lbu        $v0, 0x1($a0)
    /* D3E8 8001CBE8 00008390 */  lbu        $v1, 0x0($a0)
    /* D3EC 8001CBEC 00120200 */  sll        $v0, $v0, 8
    /* D3F0 8001CBF0 25104300 */  or         $v0, $v0, $v1
    /* D3F4 8001CBF4 03004010 */  beqz       $v0, .L8001CC04
    /* D3F8 8001CBF8 21108200 */   addu      $v0, $a0, $v0
    /* D3FC 8001CBFC 02730008 */  j          .L8001CC08
    /* D400 8001CC00 02004524 */   addiu     $a1, $v0, 0x2
  .L8001CC04:
    /* D404 8001CC04 21280000 */  addu       $a1, $zero, $zero
  .L8001CC08:
    /* D408 8001CC08 02008424 */  addiu      $a0, $a0, 0x2
    /* D40C 8001CC0C 01008290 */  lbu        $v0, 0x1($a0)
    /* D410 8001CC10 00008390 */  lbu        $v1, 0x0($a0)
    /* D414 8001CC14 00120200 */  sll        $v0, $v0, 8
    /* D418 8001CC18 25104300 */  or         $v0, $v0, $v1
    /* D41C 8001CC1C 03004010 */  beqz       $v0, .L8001CC2C
    /* D420 8001CC20 21108200 */   addu      $v0, $a0, $v0
    /* D424 8001CC24 0C730008 */  j          .L8001CC30
    /* D428 8001CC28 02004624 */   addiu     $a2, $v0, 0x2
  .L8001CC2C:
    /* D42C 8001CC2C 21300000 */  addu       $a2, $zero, $zero
  .L8001CC30:
    /* D430 8001CC30 0380043C */  lui        $a0, %hi(D_80037800)
    /* D434 8001CC34 007880AC */  sw         $zero, %lo(D_80037800)($a0)
    /* D438 8001CC38 00788424 */  addiu      $a0, $a0, %lo(D_80037800)
    /* D43C 8001CC3C 040080AC */  sw         $zero, 0x4($a0)
    /* D440 8001CC40 8E000296 */  lhu        $v0, 0x8E($s0)
    /* D444 8001CC44 00000000 */  nop
    /* D448 8001CC48 02120200 */  srl        $v0, $v0, 8
    /* D44C 8001CC4C 080082AC */  sw         $v0, 0x8($a0)
    /* D450 8001CC50 4800028E */  lw         $v0, 0x48($s0)
    /* D454 8001CC54 21380000 */  addu       $a3, $zero, $zero
    /* D458 8001CC58 C3150200 */  sra        $v0, $v0, 23
    /* D45C 8001CC5C D159000C */  jal        Sound_PlaySfxProgram
    /* D460 8001CC60 0C0082AC */   sw        $v0, 0xC($a0)
    /* D464 8001CC64 0000028E */  lw         $v0, 0x0($s0)
    /* D468 8001CC68 00000000 */  nop
    /* D46C 8001CC6C 04004224 */  addiu      $v0, $v0, 0x4
    /* D470 8001CC70 000002AE */  sw         $v0, 0x0($s0)
    /* D474 8001CC74 1400BF8F */  lw         $ra, 0x14($sp)
    /* D478 8001CC78 1000B08F */  lw         $s0, 0x10($sp)
    /* D47C 8001CC7C 0800E003 */  jr         $ra
    /* D480 8001CC80 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SoundVM_FE0B_unk
