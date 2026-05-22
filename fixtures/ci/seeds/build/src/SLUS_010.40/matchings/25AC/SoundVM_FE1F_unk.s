nonmatching SoundVM_FE1F_unk, 0x3C

glabel SoundVM_FE1F_unk
    /* BA0C 8001B20C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* BA10 8001B210 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* BA14 8001B214 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* BA18 8001B218 1000BFAF */  sw         $ra, 0x10($sp)
    /* BA1C 8001B21C 0000428C */  lw         $v0, 0x0($v0)
    /* BA20 8001B220 0100033C */  lui        $v1, (0x10000 >> 16)
    /* BA24 8001B224 24104300 */  and        $v0, $v0, $v1
    /* BA28 8001B228 03004010 */  beqz       $v0, .L8001B238
    /* BA2C 8001B22C 00000000 */   nop
    /* BA30 8001B230 4E6C000C */  jal        SoundVM_A0_FinishChannel
    /* BA34 8001B234 00000000 */   nop
  .L8001B238:
    /* BA38 8001B238 1000BF8F */  lw         $ra, 0x10($sp)
    /* BA3C 8001B23C 00000000 */  nop
    /* BA40 8001B240 0800E003 */  jr         $ra
    /* BA44 8001B244 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SoundVM_FE1F_unk
