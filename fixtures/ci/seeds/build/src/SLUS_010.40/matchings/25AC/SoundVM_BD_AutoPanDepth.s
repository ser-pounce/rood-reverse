nonmatching SoundVM_BD_AutoPanDepth, 0x20

glabel SoundVM_BD_AutoPanDepth
    /* C858 8001C058 0000828C */  lw         $v0, 0x0($a0)
    /* C85C 8001C05C 00000000 */  nop
    /* C860 8001C060 00004390 */  lbu        $v1, 0x0($v0)
    /* C864 8001C064 01004224 */  addiu      $v0, $v0, 0x1
    /* C868 8001C068 000082AC */  sw         $v0, 0x0($a0)
    /* C86C 8001C06C C0190300 */  sll        $v1, $v1, 7
    /* C870 8001C070 0800E003 */  jr         $ra
    /* C874 8001C074 C60083A4 */   sh        $v1, 0xC6($a0)
endlabel SoundVM_BD_AutoPanDepth
