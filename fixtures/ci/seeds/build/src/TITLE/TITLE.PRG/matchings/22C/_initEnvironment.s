nonmatching _initEnvironment, 0xE0

glabel _initEnvironment
    /* 8A54 80071254 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 8A58 80071258 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8A5C 8007125C 0680103C */  lui        $s0, %hi(vs_main_settings)
    /* 8A60 80071260 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8A64 80071264 20001126 */  addiu      $s1, $s0, %lo(vs_main_settings)
    /* 8A68 80071268 21202002 */  addu       $a0, $s1, $zero
    /* 8A6C 8007126C 21280000 */  addu       $a1, $zero, $zero
    /* 8A70 80071270 2400BFAF */  sw         $ra, 0x24($sp)
    /* 8A74 80071274 2000B4AF */  sw         $s4, 0x20($sp)
    /* 8A78 80071278 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 8A7C 8007127C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 8A80 80071280 0B003492 */  lbu        $s4, 0xB($s1)
    /* 8A84 80071284 0A003292 */  lbu        $s2, 0xA($s1)
    /* 8A88 80071288 AD9B000C */  jal        memset
    /* 8A8C 8007128C 20000624 */   addiu     $a2, $zero, 0x20
    /* 8A90 80071290 D8020224 */  addiu      $v0, $zero, 0x2D8
    /* 8A94 80071294 01001324 */  addiu      $s3, $zero, 0x1
    /* 8A98 80071298 020022A6 */  sh         $v0, 0x2($s1)
    /* 8A9C 8007129C 03000224 */  addiu      $v0, $zero, 0x3
    /* 8AA0 800712A0 0580033C */  lui        $v1, %hi(vs_main_titleScreenCount)
    /* 8AA4 800712A4 080033A2 */  sb         $s3, 0x8($s1)
    /* 8AA8 800712A8 090022A2 */  sb         $v0, 0x9($s1)
    /* 8AAC 800712AC 2000028E */  lw         $v0, %lo(vs_main_settings)($s0)
    /* 8AB0 800712B0 28A5638C */  lw         $v1, %lo(vs_main_titleScreenCount)($v1)
    /* 8AB4 800712B4 30004234 */  ori        $v0, $v0, 0x30
    /* 8AB8 800712B8 200002AE */  sw         $v0, %lo(vs_main_settings)($s0)
    /* 8ABC 800712BC 04006014 */  bnez       $v1, .L800712D0
    /* 8AC0 800712C0 010033A2 */   sb        $s3, 0x1($s1)
    /* 8AC4 800712C4 53BD010C */  jal        _displayPublisherAndDeveloper
    /* 8AC8 800712C8 01001424 */   addiu     $s4, $zero, 0x1
    /* 8ACC 800712CC 21900000 */  addu       $s2, $zero, $zero
  .L800712D0:
    /* 8AD0 800712D0 2B101200 */  sltu       $v0, $zero, $s2
    /* 8AD4 800712D4 0A0022A2 */  sb         $v0, 0xA($s1)
    /* 8AD8 800712D8 FF004430 */  andi       $a0, $v0, 0xFF
    /* 8ADC 800712DC 2B101400 */  sltu       $v0, $zero, $s4
    /* 8AE0 800712E0 2F1A010C */  jal        vs_main_setMonoSound
    /* 8AE4 800712E4 0B0022A2 */   sb        $v0, 0xB($s1)
    /* 8AE8 800712E8 8C4C000C */  jal        vs_sound_setCdVol
    /* 8AEC 800712EC 7F000424 */   addiu     $a0, $zero, 0x7F
    /* 8AF0 800712F0 0680043C */  lui        $a0, %hi(vs_main_inventoryIndices)
    /* 8AF4 800712F4 D8198424 */  addiu      $a0, $a0, %lo(vs_main_inventoryIndices)
    /* 8AF8 800712F8 21280000 */  addu       $a1, $zero, $zero
    /* 8AFC 800712FC AD9B000C */  jal        memset
    /* 8B00 80071300 B0000624 */   addiu     $a2, $zero, 0xB0
    /* 8B04 80071304 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 8B08 80071308 98154224 */  addiu      $v0, $v0, %lo(vs_main_stateFlags)
    /* 8B0C 8007130C 010053A0 */  sb         $s3, 0x1($v0)
    /* 8B10 80071310 1C0153A0 */  sb         $s3, 0x11C($v0)
    /* 8B14 80071314 2400BF8F */  lw         $ra, 0x24($sp)
    /* 8B18 80071318 2000B48F */  lw         $s4, 0x20($sp)
    /* 8B1C 8007131C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 8B20 80071320 1800B28F */  lw         $s2, 0x18($sp)
    /* 8B24 80071324 1400B18F */  lw         $s1, 0x14($sp)
    /* 8B28 80071328 1000B08F */  lw         $s0, 0x10($sp)
    /* 8B2C 8007132C 0800E003 */  jr         $ra
    /* 8B30 80071330 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _initEnvironment
