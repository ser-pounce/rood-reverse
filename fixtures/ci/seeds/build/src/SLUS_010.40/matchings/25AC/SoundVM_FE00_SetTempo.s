nonmatching SoundVM_FE00_SetTempo, 0x4C

glabel SoundVM_FE00_SetTempo
    /* BA48 8001B248 0000828C */  lw         $v0, 0x0($a0)
    /* BA4C 8001B24C 0380053C */  lui        $a1, %hi(g_pActiveMusicConfig)
    /* BA50 8001B250 00004390 */  lbu        $v1, 0x0($v0)
    /* BA54 8001B254 2078A58C */  lw         $a1, %lo(g_pActiveMusicConfig)($a1)
    /* BA58 8001B258 001C0300 */  sll        $v1, $v1, 16
    /* BA5C 8001B25C 2000A3AC */  sw         $v1, 0x20($a1)
    /* BA60 8001B260 0000828C */  lw         $v0, 0x0($a0)
    /* BA64 8001B264 00000000 */  nop
    /* BA68 8001B268 01004290 */  lbu        $v0, 0x1($v0)
    /* BA6C 8001B26C 00000000 */  nop
    /* BA70 8001B270 00160200 */  sll        $v0, $v0, 24
    /* BA74 8001B274 25186200 */  or         $v1, $v1, $v0
    /* BA78 8001B278 2000A3AC */  sw         $v1, 0x20($a1)
    /* BA7C 8001B27C 0000828C */  lw         $v0, 0x0($a0)
    /* BA80 8001B280 00000000 */  nop
    /* BA84 8001B284 02004224 */  addiu      $v0, $v0, 0x2
    /* BA88 8001B288 000082AC */  sw         $v0, 0x0($a0)
    /* BA8C 8001B28C 0800E003 */  jr         $ra
    /* BA90 8001B290 6C00A0A4 */   sh        $zero, 0x6C($a1)
endlabel SoundVM_FE00_SetTempo
