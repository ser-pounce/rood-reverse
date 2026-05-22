nonmatching SoundVM_B5_VibratoDepth, 0x60

glabel SoundVM_B5_VibratoDepth
    /* C594 8001BD94 21288000 */  addu       $a1, $a0, $zero
    /* C598 8001BD98 0000A38C */  lw         $v1, 0x0($a1)
    /* C59C 8001BD9C 00000000 */  nop
    /* C5A0 8001BDA0 00006290 */  lbu        $v0, 0x0($v1)
    /* C5A4 8001BDA4 01006324 */  addiu      $v1, $v1, 0x1
    /* C5A8 8001BDA8 0000A3AC */  sw         $v1, 0x0($a1)
    /* C5AC 8001BDAC 2C00A38C */  lw         $v1, 0x2C($a1)
    /* C5B0 8001BDB0 00120200 */  sll        $v0, $v0, 8
    /* C5B4 8001BDB4 AA00A2A4 */  sh         $v0, 0xAA($a1)
    /* C5B8 8001BDB8 21204000 */  addu       $a0, $v0, $zero
    /* C5BC 8001BDBC 007F8230 */  andi       $v0, $a0, 0x7F00
    /* C5C0 8001BDC0 00808430 */  andi       $a0, $a0, 0x8000
    /* C5C4 8001BDC4 06008014 */  bnez       $a0, .L8001BDE0
    /* C5C8 8001BDC8 02320200 */   srl       $a2, $v0, 8
    /* C5CC 8001BDCC 00110300 */  sll        $v0, $v1, 4
    /* C5D0 8001BDD0 23104300 */  subu       $v0, $v0, $v1
    /* C5D4 8001BDD4 03120200 */  sra        $v0, $v0, 8
    /* C5D8 8001BDD8 796F0008 */  j          .L8001BDE4
    /* C5DC 8001BDDC 1800C200 */   mult      $a2, $v0
  .L8001BDE0:
    /* C5E0 8001BDE0 1800C300 */  mult       $a2, $v1
  .L8001BDE4:
    /* C5E4 8001BDE4 12380000 */  mflo       $a3
    /* C5E8 8001BDE8 C2110700 */  srl        $v0, $a3, 7
    /* C5EC 8001BDEC 0800E003 */  jr         $ra
    /* C5F0 8001BDF0 A800A2A4 */   sh        $v0, 0xA8($a1)
endlabel SoundVM_B5_VibratoDepth
