nonmatching func_800AACDC, 0x70

glabel func_800AACDC
    /* 424DC 800AACDC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 424E0 800AACE0 D6010224 */  addiu      $v0, $zero, 0x1D6
    /* 424E4 800AACE4 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 424E8 800AACE8 80010224 */  addiu      $v0, $zero, 0x180
    /* 424EC 800AACEC 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 424F0 800AACF0 12000224 */  addiu      $v0, $zero, 0x12
    /* 424F4 800AACF4 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 424F8 800AACF8 24000224 */  addiu      $v0, $zero, 0x24
    /* 424FC 800AACFC 1000A527 */  addiu      $a1, $sp, 0x10
    /* 42500 800AAD00 10000624 */  addiu      $a2, $zero, 0x10
    /* 42504 800AAD04 1800B0AF */  sw         $s0, 0x18($sp)
    /* 42508 800AAD08 801F103C */  lui        $s0, (0x1F800000 >> 16)
    /* 4250C 800AAD0C 0000108E */  lw         $s0, (0x1F800000 & 0xFFFF)($s0)
    /* 42510 800AAD10 90010724 */  addiu      $a3, $zero, 0x190
    /* 42514 800AAD14 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 42518 800AAD18 1600A2A7 */  sh         $v0, 0x16($sp)
    /* 4251C 800AAD1C ADAD000C */  jal        SetDrawMove
    /* 42520 800AAD20 21200002 */   addu      $a0, $s0, $zero
    /* 42524 800AAD24 09EA010C */  jal        func_8007A824
    /* 42528 800AAD28 21200002 */   addu      $a0, $s0, $zero
    /* 4252C 800AAD2C 18001026 */  addiu      $s0, $s0, 0x18
    /* 42530 800AAD30 801F013C */  lui        $at, (0x1F800000 >> 16)
    /* 42534 800AAD34 000030AC */  sw         $s0, (0x1F800000 & 0xFFFF)($at)
    /* 42538 800AAD38 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4253C 800AAD3C 1800B08F */  lw         $s0, 0x18($sp)
    /* 42540 800AAD40 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 42544 800AAD44 0800E003 */  jr         $ra
    /* 42548 800AAD48 00000000 */   nop
endlabel func_800AACDC
