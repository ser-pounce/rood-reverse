nonmatching func_800B6868, 0x5C

glabel func_800B6868
    /* 4E068 800B6868 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 4E06C 800B686C 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 4E070 800B6870 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4E074 800B6874 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4E078 800B6878 21808000 */  addu       $s0, $a0, $zero
    /* 4E07C 800B687C 2C4C40A0 */  sb         $zero, %lo(D_800F4C2C)($v0)
    /* 4E080 800B6880 02000224 */  addiu      $v0, $zero, 0x2
    /* 4E084 800B6884 FF006330 */  andi       $v1, $v1, 0xFF
    /* 4E088 800B6888 07006210 */  beq        $v1, $v0, .L800B68A8
    /* 4E08C 800B688C 1400BFAF */   sw        $ra, 0x14($sp)
    /* 4E090 800B6890 80FF020C */  jal        vs_battle_getShort
    /* 4E094 800B6894 01000426 */   addiu     $a0, $s0, 0x1
    /* 4E098 800B6898 00140200 */  sll        $v0, $v0, 16
    /* 4E09C 800B689C 03140200 */  sra        $v0, $v0, 16
    /* 4E0A0 800B68A0 2DDA0208 */  j          .L800B68B4
    /* 4E0A4 800B68A4 21100202 */   addu      $v0, $s0, $v0
  .L800B68A8:
    /* 4E0A8 800B68A8 DED9020C */  jal        func_800B6778
    /* 4E0AC 800B68AC 21200002 */   addu      $a0, $s0, $zero
    /* 4E0B0 800B68B0 04000224 */  addiu      $v0, $zero, 0x4
  .L800B68B4:
    /* 4E0B4 800B68B4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4E0B8 800B68B8 1000B08F */  lw         $s0, 0x10($sp)
    /* 4E0BC 800B68BC 0800E003 */  jr         $ra
    /* 4E0C0 800B68C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B6868
