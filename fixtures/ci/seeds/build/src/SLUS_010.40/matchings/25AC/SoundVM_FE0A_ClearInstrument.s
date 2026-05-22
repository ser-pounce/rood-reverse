nonmatching SoundVM_FE0A_ClearInstrument, 0x6C

glabel SoundVM_FE0A_ClearInstrument
    /* C1B8 8001B9B8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C1BC 8001B9BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* C1C0 8001B9C0 21808000 */  addu       $s0, $a0, $zero
    /* C1C4 8001B9C4 0380053C */  lui        $a1, %hi(g_InstrumentInfo)
    /* C1C8 8001B9C8 8867A524 */  addiu      $a1, $a1, %lo(g_InstrumentInfo)
    /* C1CC 8001B9CC 1800BFAF */  sw         $ra, 0x18($sp)
    /* C1D0 8001B9D0 1400B1AF */  sw         $s1, 0x14($sp)
    /* C1D4 8001B9D4 0000028E */  lw         $v0, 0x0($s0)
    /* C1D8 8001B9D8 10100624 */  addiu      $a2, $zero, 0x1010
    /* C1DC 8001B9DC 00005190 */  lbu        $s1, 0x0($v0)
    /* C1E0 8001B9E0 01004224 */  addiu      $v0, $v0, 0x1
    /* C1E4 8001B9E4 000002AE */  sw         $v0, 0x0($s0)
    /* C1E8 8001B9E8 00111100 */  sll        $v0, $s1, 4
    /* C1EC 8001B9EC 186C000C */  jal        Sound_CopyInstrumentInfoToChannel
    /* C1F0 8001B9F0 21284500 */   addu      $a1, $v0, $a1
    /* C1F4 8001B9F4 FFE6033C */  lui        $v1, (0xE6FFEFF7 >> 16)
    /* C1F8 8001B9F8 3400028E */  lw         $v0, 0x34($s0)
    /* C1FC 8001B9FC F7EF6334 */  ori        $v1, $v1, (0xE6FFEFF7 & 0xFFFF)
    /* C200 8001BA00 6A0011A6 */  sh         $s1, 0x6A($s0)
    /* C204 8001BA04 0A0100A6 */  sh         $zero, 0x10A($s0)
    /* C208 8001BA08 24104300 */  and        $v0, $v0, $v1
    /* C20C 8001BA0C 340002AE */  sw         $v0, 0x34($s0)
    /* C210 8001BA10 1800BF8F */  lw         $ra, 0x18($sp)
    /* C214 8001BA14 1400B18F */  lw         $s1, 0x14($sp)
    /* C218 8001BA18 1000B08F */  lw         $s0, 0x10($sp)
    /* C21C 8001BA1C 0800E003 */  jr         $ra
    /* C220 8001BA20 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel SoundVM_FE0A_ClearInstrument
