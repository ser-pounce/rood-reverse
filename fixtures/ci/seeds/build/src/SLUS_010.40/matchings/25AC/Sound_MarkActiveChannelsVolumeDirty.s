nonmatching Sound_MarkActiveChannelsVolumeDirty, 0x48

glabel Sound_MarkActiveChannelsVolumeDirty
    /* 7164 80016964 0400828C */  lw         $v0, 0x4($a0)
    /* 7168 80016968 00000000 */  nop
    /* 716C 8001696C 0D004010 */  beqz       $v0, .L800169A4
    /* 7170 80016970 21204000 */   addu      $a0, $v0, $zero
    /* 7174 80016974 01000324 */  addiu      $v1, $zero, 0x1
    /* 7178 80016978 F800A524 */  addiu      $a1, $a1, 0xF8
  .L8001697C:
    /* 717C 8001697C 24108300 */  and        $v0, $a0, $v1
    /* 7180 80016980 05004010 */  beqz       $v0, .L80016998
    /* 7184 80016984 00000000 */   nop
    /* 7188 80016988 0000A28C */  lw         $v0, 0x0($a1)
    /* 718C 8001698C 26208300 */  xor        $a0, $a0, $v1
    /* 7190 80016990 03004234 */  ori        $v0, $v0, 0x3
    /* 7194 80016994 0000A2AC */  sw         $v0, 0x0($a1)
  .L80016998:
    /* 7198 80016998 1001A524 */  addiu      $a1, $a1, 0x110
    /* 719C 8001699C F7FF8014 */  bnez       $a0, .L8001697C
    /* 71A0 800169A0 40180300 */   sll       $v1, $v1, 1
  .L800169A4:
    /* 71A4 800169A4 0800E003 */  jr         $ra
    /* 71A8 800169A8 00000000 */   nop
endlabel Sound_MarkActiveChannelsVolumeDirty
