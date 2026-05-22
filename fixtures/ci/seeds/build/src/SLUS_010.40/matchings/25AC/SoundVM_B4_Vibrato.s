nonmatching SoundVM_B4_Vibrato, 0xF8

glabel SoundVM_B4_Vibrato
    /* C49C 8001BC9C 21288000 */  addu       $a1, $a0, $zero
    /* C4A0 8001BCA0 3400A28C */  lw         $v0, 0x34($a1)
    /* C4A4 8001BCA4 6400A394 */  lhu        $v1, 0x64($a1)
    /* C4A8 8001BCA8 01004234 */  ori        $v0, $v0, 0x1
    /* C4AC 8001BCAC 0A006010 */  beqz       $v1, .L8001BCD8
    /* C4B0 8001BCB0 3400A2AC */   sw        $v0, 0x34($a1)
    /* C4B4 8001BCB4 0000A28C */  lw         $v0, 0x0($a1)
    /* C4B8 8001BCB8 9E00A0A4 */  sh         $zero, 0x9E($a1)
    /* C4BC 8001BCBC 00004390 */  lbu        $v1, 0x0($v0)
    /* C4C0 8001BCC0 01004224 */  addiu      $v0, $v0, 0x1
    /* C4C4 8001BCC4 0A006010 */  beqz       $v1, .L8001BCF0
    /* C4C8 8001BCC8 0000A2AC */   sw        $v0, 0x0($a1)
    /* C4CC 8001BCCC 00120300 */  sll        $v0, $v1, 8
    /* C4D0 8001BCD0 3C6F0008 */  j          .L8001BCF0
    /* C4D4 8001BCD4 AA00A2A4 */   sh        $v0, 0xAA($a1)
  .L8001BCD8:
    /* C4D8 8001BCD8 0000A28C */  lw         $v0, 0x0($a1)
    /* C4DC 8001BCDC 00000000 */  nop
    /* C4E0 8001BCE0 00004390 */  lbu        $v1, 0x0($v0)
    /* C4E4 8001BCE4 01004224 */  addiu      $v0, $v0, 0x1
    /* C4E8 8001BCE8 0000A2AC */  sw         $v0, 0x0($a1)
    /* C4EC 8001BCEC 9E00A3A4 */  sh         $v1, 0x9E($a1)
  .L8001BCF0:
    /* C4F0 8001BCF0 0000A28C */  lw         $v0, 0x0($a1)
    /* C4F4 8001BCF4 00000000 */  nop
    /* C4F8 8001BCF8 00004390 */  lbu        $v1, 0x0($v0)
    /* C4FC 8001BCFC 01004224 */  addiu      $v0, $v0, 0x1
    /* C500 8001BD00 0000A2AC */  sw         $v0, 0x0($a1)
    /* C504 8001BD04 03006014 */  bnez       $v1, .L8001BD14
    /* C508 8001BD08 A200A3A4 */   sh        $v1, 0xA2($a1)
    /* C50C 8001BD0C 00010224 */  addiu      $v0, $zero, 0x100
    /* C510 8001BD10 A200A2A4 */  sh         $v0, 0xA2($a1)
  .L8001BD14:
    /* C514 8001BD14 0000A28C */  lw         $v0, 0x0($a1)
    /* C518 8001BD18 AA00A394 */  lhu        $v1, 0xAA($a1)
    /* C51C 8001BD1C 00004490 */  lbu        $a0, 0x0($v0)
    /* C520 8001BD20 01004224 */  addiu      $v0, $v0, 0x1
    /* C524 8001BD24 0000A2AC */  sw         $v0, 0x0($a1)
    /* C528 8001BD28 007F6230 */  andi       $v0, $v1, 0x7F00
    /* C52C 8001BD2C 00806330 */  andi       $v1, $v1, 0x8000
    /* C530 8001BD30 A600A4A4 */  sh         $a0, 0xA6($a1)
    /* C534 8001BD34 2C00A494 */  lhu        $a0, 0x2C($a1)
    /* C538 8001BD38 06006014 */  bnez       $v1, .L8001BD54
    /* C53C 8001BD3C 02320200 */   srl       $a2, $v0, 8
    /* C540 8001BD40 00110400 */  sll        $v0, $a0, 4
    /* C544 8001BD44 23104400 */  subu       $v0, $v0, $a0
    /* C548 8001BD48 03120200 */  sra        $v0, $v0, 8
    /* C54C 8001BD4C 566F0008 */  j          .L8001BD58
    /* C550 8001BD50 1800C200 */   mult      $a2, $v0
  .L8001BD54:
    /* C554 8001BD54 1800C400 */  mult       $a2, $a0
  .L8001BD58:
    /* C558 8001BD58 12380000 */  mflo       $a3
    /* C55C 8001BD5C C2110700 */  srl        $v0, $a3, 7
    /* C560 8001BD60 0380033C */  lui        $v1, %hi(g_Sound_LfoTable)
    /* C564 8001BD64 A800A2A4 */  sh         $v0, 0xA8($a1)
    /* C568 8001BD68 A600A294 */  lhu        $v0, 0xA6($a1)
    /* C56C 8001BD6C A0016324 */  addiu      $v1, $v1, %lo(g_Sound_LfoTable)
    /* C570 8001BD70 80100200 */  sll        $v0, $v0, 2
    /* C574 8001BD74 21104300 */  addu       $v0, $v0, $v1
    /* C578 8001BD78 9E00A394 */  lhu        $v1, 0x9E($a1)
    /* C57C 8001BD7C 0000448C */  lw         $a0, 0x0($v0)
    /* C580 8001BD80 01000224 */  addiu      $v0, $zero, 0x1
    /* C584 8001BD84 A400A2A4 */  sh         $v0, 0xA4($a1)
    /* C588 8001BD88 A000A3A4 */  sh         $v1, 0xA0($a1)
    /* C58C 8001BD8C 0800E003 */  jr         $ra
    /* C590 8001BD90 1C00A4AC */   sw        $a0, 0x1C($a1)
endlabel SoundVM_B4_Vibrato
