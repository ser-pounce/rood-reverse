nonmatching func_8001217C, 0x74

glabel func_8001217C
    /* 297C 8001217C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2980 80012180 FF038430 */  andi       $a0, $a0, 0x3FF
    /* 2984 80012184 0380023C */  lui        $v0, %hi(g_Sound_SfxProgramOffsets)
    /* 2988 80012188 EC77438C */  lw         $v1, %lo(g_Sound_SfxProgramOffsets)($v0)
    /* 298C 8001218C 80100400 */  sll        $v0, $a0, 2
    /* 2990 80012190 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2994 80012194 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2998 80012198 21104300 */  addu       $v0, $v0, $v1
    /* 299C 8001219C 0000508C */  lw         $s0, 0x0($v0)
    /* 29A0 800121A0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 29A4 800121A4 0D000212 */  beq        $s0, $v0, .L800121DC
    /* 29A8 800121A8 FF00023C */   lui       $v0, (0xFFFFFF >> 16)
    /* 29AC 800121AC FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 29B0 800121B0 0380033C */  lui        $v1, %hi(D_800378C0)
    /* 29B4 800121B4 C07864AC */  sw         $a0, %lo(D_800378C0)($v1)
    /* 29B8 800121B8 C0786324 */  addiu      $v1, $v1, %lo(D_800378C0)
    /* 29BC 800121BC 2410A200 */  and        $v0, $a1, $v0
    /* 29C0 800121C0 040062AC */  sw         $v0, 0x4($v1)
    /* 29C4 800121C4 FF00C230 */  andi       $v0, $a2, 0xFF
    /* 29C8 800121C8 080062AC */  sw         $v0, 0x8($v1)
    /* 29CC 800121CC 7F00E230 */  andi       $v0, $a3, 0x7F
    /* 29D0 800121D0 20000424 */  addiu      $a0, $zero, 0x20
    /* 29D4 800121D4 0C63000C */  jal        func_80018C30
    /* 29D8 800121D8 0C0062AC */   sw        $v0, 0xC($v1)
  .L800121DC:
    /* 29DC 800121DC 21100002 */  addu       $v0, $s0, $zero
    /* 29E0 800121E0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 29E4 800121E4 1000B08F */  lw         $s0, 0x10($sp)
    /* 29E8 800121E8 0800E003 */  jr         $ra
    /* 29EC 800121EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001217C
