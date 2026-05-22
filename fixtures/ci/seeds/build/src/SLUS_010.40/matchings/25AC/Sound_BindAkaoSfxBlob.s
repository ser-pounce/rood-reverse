nonmatching Sound_BindAkaoSfxBlob, 0x54

glabel Sound_BindAkaoSfxBlob
    /* 25EC 80011DEC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25F0 80011DF0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 25F4 80011DF4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 25F8 80011DF8 1A4D000C */  jal        Sound_IsNotAkaoFile
    /* 25FC 80011DFC 21808000 */   addu      $s0, $a0, $zero
    /* 2600 80011E00 21184000 */  addu       $v1, $v0, $zero
    /* 2604 80011E04 09006014 */  bnez       $v1, .L80011E2C
    /* 2608 80011E08 10001026 */   addiu     $s0, $s0, 0x10
    /* 260C 80011E0C 0380023C */  lui        $v0, %hi(g_Sound_SfxProgramOffsets)
    /* 2610 80011E10 EC7750AC */  sw         $s0, %lo(g_Sound_SfxProgramOffsets)($v0)
    /* 2614 80011E14 00061026 */  addiu      $s0, $s0, 0x600
    /* 2618 80011E18 0380023C */  lui        $v0, %hi(g_Sound_SfxMetadataTable)
    /* 261C 80011E1C F47750AC */  sw         $s0, %lo(g_Sound_SfxMetadataTable)($v0)
    /* 2620 80011E20 00031026 */  addiu      $s0, $s0, 0x300
    /* 2624 80011E24 0380023C */  lui        $v0, %hi(g_Sound_SfxProgramData)
    /* 2628 80011E28 F87750AC */  sw         $s0, %lo(g_Sound_SfxProgramData)($v0)
  .L80011E2C:
    /* 262C 80011E2C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2630 80011E30 1000B08F */  lw         $s0, 0x10($sp)
    /* 2634 80011E34 21106000 */  addu       $v0, $v1, $zero
    /* 2638 80011E38 0800E003 */  jr         $ra
    /* 263C 80011E3C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_BindAkaoSfxBlob
