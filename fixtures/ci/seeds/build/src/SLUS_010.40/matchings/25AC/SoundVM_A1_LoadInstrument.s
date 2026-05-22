nonmatching SoundVM_A1_LoadInstrument, 0xA8

glabel SoundVM_A1_LoadInstrument
    /* C110 8001B910 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C114 8001B914 1400B1AF */  sw         $s1, 0x14($sp)
    /* C118 8001B918 21888000 */  addu       $s1, $a0, $zero
    /* C11C 8001B91C 1800BFAF */  sw         $ra, 0x18($sp)
    /* C120 8001B920 1000B0AF */  sw         $s0, 0x10($sp)
    /* C124 8001B924 0000228E */  lw         $v0, 0x0($s1)
    /* C128 8001B928 64002396 */  lhu        $v1, 0x64($s1)
    /* C12C 8001B92C 00004590 */  lbu        $a1, 0x0($v0)
    /* C130 8001B930 01004224 */  addiu      $v0, $v0, 0x1
    /* C134 8001B934 09006014 */  bnez       $v1, .L8001B95C
    /* C138 8001B938 000022AE */   sw        $v0, 0x0($s1)
    /* C13C 8001B93C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* C140 8001B940 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* C144 8001B944 00000000 */  nop
    /* C148 8001B948 0000448C */  lw         $a0, 0x0($v0)
    /* C14C 8001B94C 8B68000C */  jal        func_8001A22C
    /* C150 8001B950 00000000 */   nop
    /* C154 8001B954 5B6E0008 */  j          .L8001B96C
    /* C158 8001B958 21804000 */   addu      $s0, $v0, $zero
  .L8001B95C:
    /* C15C 8001B95C 3800248E */  lw         $a0, 0x38($s1)
    /* C160 8001B960 7D68000C */  jal        func_8001A1F4
    /* C164 8001B964 00000000 */   nop
    /* C168 8001B968 21804000 */  addu       $s0, $v0, $zero
  .L8001B96C:
    /* C16C 8001B96C 00291000 */  sll        $a1, $s0, 4
    /* C170 8001B970 0380023C */  lui        $v0, %hi(g_InstrumentInfo)
    /* C174 8001B974 88674224 */  addiu      $v0, $v0, %lo(g_InstrumentInfo)
    /* C178 8001B978 2128A200 */  addu       $a1, $a1, $v0
    /* C17C 8001B97C 0000A68C */  lw         $a2, 0x0($a1)
    /* C180 8001B980 186C000C */  jal        Sound_CopyInstrumentInfoToChannel
    /* C184 8001B984 21202002 */   addu      $a0, $s1, $zero
    /* C188 8001B988 FFE6033C */  lui        $v1, (0xE6FFEFF7 >> 16)
    /* C18C 8001B98C 3400228E */  lw         $v0, 0x34($s1)
    /* C190 8001B990 F7EF6334 */  ori        $v1, $v1, (0xE6FFEFF7 & 0xFFFF)
    /* C194 8001B994 6A0030A6 */  sh         $s0, 0x6A($s1)
    /* C198 8001B998 0A0120A6 */  sh         $zero, 0x10A($s1)
    /* C19C 8001B99C 24104300 */  and        $v0, $v0, $v1
    /* C1A0 8001B9A0 340022AE */  sw         $v0, 0x34($s1)
    /* C1A4 8001B9A4 1800BF8F */  lw         $ra, 0x18($sp)
    /* C1A8 8001B9A8 1400B18F */  lw         $s1, 0x14($sp)
    /* C1AC 8001B9AC 1000B08F */  lw         $s0, 0x10($sp)
    /* C1B0 8001B9B0 0800E003 */  jr         $ra
    /* C1B4 8001B9B4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel SoundVM_A1_LoadInstrument
