nonmatching SoundVM_BF_ReleaseMode, 0x44

glabel SoundVM_BF_ReleaseMode
    /* CE28 8001C628 21288000 */  addu       $a1, $a0, $zero
    /* CE2C 8001C62C 0000A28C */  lw         $v0, 0x0($a1)
    /* CE30 8001C630 0801A394 */  lhu        $v1, 0x108($a1)
    /* CE34 8001C634 00004490 */  lbu        $a0, 0x0($v0)
    /* CE38 8001C638 01004224 */  addiu      $v0, $v0, 0x1
    /* CE3C 8001C63C DFFF6330 */  andi       $v1, $v1, 0xFFDF
    /* CE40 8001C640 0000A2AC */  sw         $v0, 0x0($a1)
    /* CE44 8001C644 07000224 */  addiu      $v0, $zero, 0x7
    /* CE48 8001C648 03008214 */  bne        $a0, $v0, .L8001C658
    /* CE4C 8001C64C 0801A3A4 */   sh        $v1, 0x108($a1)
    /* CE50 8001C650 20006234 */  ori        $v0, $v1, 0x20
    /* CE54 8001C654 0801A2A4 */  sh         $v0, 0x108($a1)
  .L8001C658:
    /* CE58 8001C658 F800A28C */  lw         $v0, 0xF8($a1)
    /* CE5C 8001C65C 00000000 */  nop
    /* CE60 8001C660 00044234 */  ori        $v0, $v0, 0x400
    /* CE64 8001C664 0800E003 */  jr         $ra
    /* CE68 8001C668 F800A2AC */   sw        $v0, 0xF8($a1)
endlabel SoundVM_BF_ReleaseMode
