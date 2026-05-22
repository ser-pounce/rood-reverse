nonmatching SoundVM_FE04_ClearKeymapTable, 0x38

glabel SoundVM_FE04_ClearKeymapTable
    /* D12C 8001C92C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* D130 8001C930 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* D134 8001C934 00000000 */  nop
    /* D138 8001C938 4000428C */  lw         $v0, 0x40($v0)
    /* D13C 8001C93C 00000000 */  nop
    /* D140 8001C940 06004010 */  beqz       $v0, .L8001C95C
    /* D144 8001C944 FFE6033C */   lui       $v1, (0xE6FFEFF7 >> 16)
    /* D148 8001C948 3400828C */  lw         $v0, 0x34($a0)
    /* D14C 8001C94C F7EF6334 */  ori        $v1, $v1, (0xE6FFEFF7 & 0xFFFF)
    /* D150 8001C950 24104300 */  and        $v0, $v0, $v1
    /* D154 8001C954 08004234 */  ori        $v0, $v0, 0x8
    /* D158 8001C958 340082AC */  sw         $v0, 0x34($a0)
  .L8001C95C:
    /* D15C 8001C95C 0800E003 */  jr         $ra
    /* D160 8001C960 00000000 */   nop
endlabel SoundVM_FE04_ClearKeymapTable
