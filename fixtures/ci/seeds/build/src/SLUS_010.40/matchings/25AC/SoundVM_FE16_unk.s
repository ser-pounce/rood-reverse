nonmatching SoundVM_FE16_unk, 0x3C

glabel SoundVM_FE16_unk
    /* D1B4 8001C9B4 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* D1B8 8001C9B8 0000858C */  lw         $a1, 0x0($a0)
    /* D1BC 8001C9BC 2078468C */  lw         $a2, %lo(g_pActiveMusicConfig)($v0)
    /* D1C0 8001C9C0 0000A290 */  lbu        $v0, 0x0($a1)
    /* D1C4 8001C9C4 0100A524 */  addiu      $a1, $a1, 0x1
    /* D1C8 8001C9C8 7C00C2A4 */  sh         $v0, 0x7C($a2)
    /* D1CC 8001C9CC 000085AC */  sw         $a1, 0x0($a0)
    /* D1D0 8001C9D0 0000A290 */  lbu        $v0, 0x0($a1)
    /* D1D4 8001C9D4 0100A524 */  addiu      $a1, $a1, 0x1
    /* D1D8 8001C9D8 7C00C394 */  lhu        $v1, 0x7C($a2)
    /* D1DC 8001C9DC 00120200 */  sll        $v0, $v0, 8
    /* D1E0 8001C9E0 25186200 */  or         $v1, $v1, $v0
    /* D1E4 8001C9E4 7C00C3A4 */  sh         $v1, 0x7C($a2)
    /* D1E8 8001C9E8 0800E003 */  jr         $ra
    /* D1EC 8001C9EC 000085AC */   sw        $a1, 0x0($a0)
endlabel SoundVM_FE16_unk
