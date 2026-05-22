nonmatching SoundVM_B7_AttackMode, 0x44

glabel SoundVM_B7_AttackMode
    /* CD6C 8001C56C 21288000 */  addu       $a1, $a0, $zero
    /* CD70 8001C570 0000A28C */  lw         $v0, 0x0($a1)
    /* CD74 8001C574 0601A394 */  lhu        $v1, 0x106($a1)
    /* CD78 8001C578 00004490 */  lbu        $a0, 0x0($v0)
    /* CD7C 8001C57C 01004224 */  addiu      $v0, $v0, 0x1
    /* CD80 8001C580 FF7F6330 */  andi       $v1, $v1, 0x7FFF
    /* CD84 8001C584 0000A2AC */  sw         $v0, 0x0($a1)
    /* CD88 8001C588 05000224 */  addiu      $v0, $zero, 0x5
    /* CD8C 8001C58C 03008214 */  bne        $a0, $v0, .L8001C59C
    /* CD90 8001C590 0601A3A4 */   sh        $v1, 0x106($a1)
    /* CD94 8001C594 00806234 */  ori        $v0, $v1, 0x8000
    /* CD98 8001C598 0601A2A4 */  sh         $v0, 0x106($a1)
  .L8001C59C:
    /* CD9C 8001C59C F800A28C */  lw         $v0, 0xF8($a1)
    /* CDA0 8001C5A0 00000000 */  nop
    /* CDA4 8001C5A4 00014234 */  ori        $v0, $v0, 0x100
    /* CDA8 8001C5A8 0800E003 */  jr         $ra
    /* CDAC 8001C5AC F800A2AC */   sw        $v0, 0xF8($a1)
endlabel SoundVM_B7_AttackMode
