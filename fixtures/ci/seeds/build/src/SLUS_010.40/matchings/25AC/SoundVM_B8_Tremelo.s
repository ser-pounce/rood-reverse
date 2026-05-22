nonmatching SoundVM_B8_Tremelo, 0xB0

glabel SoundVM_B8_Tremelo
    /* C684 8001BE84 21288000 */  addu       $a1, $a0, $zero
    /* C688 8001BE88 3400A28C */  lw         $v0, 0x34($a1)
    /* C68C 8001BE8C 0000A38C */  lw         $v1, 0x0($a1)
    /* C690 8001BE90 02004234 */  ori        $v0, $v0, 0x2
    /* C694 8001BE94 3400A2AC */  sw         $v0, 0x34($a1)
    /* C698 8001BE98 00006490 */  lbu        $a0, 0x0($v1)
    /* C69C 8001BE9C 6400A294 */  lhu        $v0, 0x64($a1)
    /* C6A0 8001BEA0 01006324 */  addiu      $v1, $v1, 0x1
    /* C6A4 8001BEA4 07004010 */  beqz       $v0, .L8001BEC4
    /* C6A8 8001BEA8 0000A3AC */   sw        $v1, 0x0($a1)
    /* C6AC 8001BEAC 06008010 */  beqz       $a0, .L8001BEC8
    /* C6B0 8001BEB0 B000A0A4 */   sh        $zero, 0xB0($a1)
    /* C6B4 8001BEB4 7F008230 */  andi       $v0, $a0, 0x7F
    /* C6B8 8001BEB8 00120200 */  sll        $v0, $v0, 8
    /* C6BC 8001BEBC B26F0008 */  j          .L8001BEC8
    /* C6C0 8001BEC0 BA00A2A4 */   sh        $v0, 0xBA($a1)
  .L8001BEC4:
    /* C6C4 8001BEC4 B000A4A4 */  sh         $a0, 0xB0($a1)
  .L8001BEC8:
    /* C6C8 8001BEC8 0000A28C */  lw         $v0, 0x0($a1)
    /* C6CC 8001BECC 00000000 */  nop
    /* C6D0 8001BED0 00004390 */  lbu        $v1, 0x0($v0)
    /* C6D4 8001BED4 01004224 */  addiu      $v0, $v0, 0x1
    /* C6D8 8001BED8 0000A2AC */  sw         $v0, 0x0($a1)
    /* C6DC 8001BEDC 03006014 */  bnez       $v1, .L8001BEEC
    /* C6E0 8001BEE0 B400A3A4 */   sh        $v1, 0xB4($a1)
    /* C6E4 8001BEE4 00010224 */  addiu      $v0, $zero, 0x100
    /* C6E8 8001BEE8 B400A2A4 */  sh         $v0, 0xB4($a1)
  .L8001BEEC:
    /* C6EC 8001BEEC 0000A28C */  lw         $v0, 0x0($a1)
    /* C6F0 8001BEF0 00000000 */  nop
    /* C6F4 8001BEF4 00004390 */  lbu        $v1, 0x0($v0)
    /* C6F8 8001BEF8 01004224 */  addiu      $v0, $v0, 0x1
    /* C6FC 8001BEFC 0000A2AC */  sw         $v0, 0x0($a1)
    /* C700 8001BF00 B800A3A4 */  sh         $v1, 0xB8($a1)
    /* C704 8001BF04 0380033C */  lui        $v1, %hi(g_Sound_LfoTable)
    /* C708 8001BF08 B800A294 */  lhu        $v0, 0xB8($a1)
    /* C70C 8001BF0C A0016324 */  addiu      $v1, $v1, %lo(g_Sound_LfoTable)
    /* C710 8001BF10 80100200 */  sll        $v0, $v0, 2
    /* C714 8001BF14 21104300 */  addu       $v0, $v0, $v1
    /* C718 8001BF18 B000A394 */  lhu        $v1, 0xB0($a1)
    /* C71C 8001BF1C 0000448C */  lw         $a0, 0x0($v0)
    /* C720 8001BF20 01000224 */  addiu      $v0, $zero, 0x1
    /* C724 8001BF24 B600A2A4 */  sh         $v0, 0xB6($a1)
    /* C728 8001BF28 B200A3A4 */  sh         $v1, 0xB2($a1)
    /* C72C 8001BF2C 0800E003 */  jr         $ra
    /* C730 8001BF30 2000A4AC */   sw        $a0, 0x20($a1)
endlabel SoundVM_B8_Tremelo
