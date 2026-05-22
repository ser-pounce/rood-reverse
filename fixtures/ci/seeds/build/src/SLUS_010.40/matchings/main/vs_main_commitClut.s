nonmatching vs_main_commitClut, 0x60

glabel vs_main_commitClut
    /* 3978C 80048F8C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 39790 80048F90 1800B0AF */  sw         $s0, 0x18($sp)
    /* 39794 80048F94 0580103C */  lui        $s0, %hi(_clutState)
    /* 39798 80048F98 585D0296 */  lhu        $v0, %lo(_clutState)($s0)
    /* 3979C 80048F9C 00000000 */  nop
    /* 397A0 80048FA0 0E004010 */  beqz       $v0, .L80048FDC
    /* 397A4 80048FA4 1C00BFAF */   sw        $ra, 0x1C($sp)
    /* 397A8 80048FA8 00030224 */  addiu      $v0, $zero, 0x300
    /* 397AC 80048FAC 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 397B0 80048FB0 E0000224 */  addiu      $v0, $zero, 0xE0
    /* 397B4 80048FB4 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 397B8 80048FB8 00010224 */  addiu      $v0, $zero, 0x100
    /* 397BC 80048FBC 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 397C0 80048FC0 0E000224 */  addiu      $v0, $zero, 0xE
    /* 397C4 80048FC4 0680053C */  lui        $a1, %hi(_clutBuffer)
    /* 397C8 80048FC8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 397CC 80048FCC 50E2A524 */  addiu      $a1, $a1, %lo(_clutBuffer)
    /* 397D0 80048FD0 3FA2000C */  jal        LoadImage
    /* 397D4 80048FD4 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 397D8 80048FD8 585D00A6 */  sh         $zero, %lo(_clutState)($s0)
  .L80048FDC:
    /* 397DC 80048FDC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 397E0 80048FE0 1800B08F */  lw         $s0, 0x18($sp)
    /* 397E4 80048FE4 0800E003 */  jr         $ra
    /* 397E8 80048FE8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_main_commitClut
