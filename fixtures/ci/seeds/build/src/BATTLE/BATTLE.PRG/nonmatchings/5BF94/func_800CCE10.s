nonmatching func_800CCE10, 0xF8

glabel func_800CCE10
    /* 64610 800CCE10 C0280500 */  sll        $a1, $a1, 3
    /* 64614 800CCE14 0F80023C */  lui        $v0, %hi(D_800EC284)
    /* 64618 800CCE18 84C24224 */  addiu      $v0, $v0, %lo(D_800EC284)
    /* 6461C 800CCE1C 2128A200 */  addu       $a1, $a1, $v0
    /* 64620 800CCE20 1000AB8F */  lw         $t3, 0x10($sp)
    /* 64624 800CCE24 83300600 */  sra        $a2, $a2, 2
    /* 64628 800CCE28 0300C230 */  andi       $v0, $a2, 0x3
    /* 6462C 800CCE2C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 64630 800CCE30 0200422C */  sltiu      $v0, $v0, 0x2
    /* 64634 800CCE34 02004010 */  beqz       $v0, .L800CCE40
    /* 64638 800CCE38 00000000 */   nop
    /* 6463C 800CCE3C 0400A524 */  addiu      $a1, $a1, 0x4
  .L800CCE40:
    /* 64640 800CCE40 0000A58C */  lw         $a1, 0x0($a1)
    /* 64644 800CCE44 00000000 */  nop
    /* 64648 800CCE48 00150500 */  sll        $v0, $a1, 20
    /* 6464C 800CCE4C 03450200 */  sra        $t0, $v0, 20
    /* 64650 800CCE50 00520500 */  sll        $t2, $a1, 8
    /* 64654 800CCE54 03550A00 */  sra        $t2, $t2, 20
    /* 64658 800CCE58 024E0500 */  srl        $t1, $a1, 24
    /* 6465C 800CCE5C 0100C230 */  andi       $v0, $a2, 0x1
    /* 64660 800CCE60 03004010 */  beqz       $v0, .L800CCE70
    /* 64664 800CCE64 03002931 */   andi      $t1, $t1, 0x3
    /* 64668 800CCE68 23400800 */  negu       $t0, $t0
    /* 6466C 800CCE6C 02002939 */  xori       $t1, $t1, 0x2
  .L800CCE70:
    /* 64670 800CCE70 00F00224 */  addiu      $v0, $zero, -0x1000
    /* 64674 800CCE74 24186200 */  and        $v1, $v1, $v0
    /* 64678 800CCE78 40100700 */  sll        $v0, $a3, 1
    /* 6467C 800CCE7C 21104700 */  addu       $v0, $v0, $a3
    /* 64680 800CCE80 80100200 */  sll        $v0, $v0, 2
    /* 64684 800CCE84 0A004224 */  addiu      $v0, $v0, 0xA
    /* 64688 800CCE88 43100200 */  sra        $v0, $v0, 1
    /* 6468C 800CCE8C 23100201 */  subu       $v0, $t0, $v0
    /* 64690 800CCE90 FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 64694 800CCE94 25186200 */  or         $v1, $v1, $v0
    /* 64698 800CCE98 00FF023C */  lui        $v0, (0xFF000FFF >> 16)
    /* 6469C 800CCE9C FF0F4234 */  ori        $v0, $v0, (0xFF000FFF & 0xFFFF)
    /* 646A0 800CCEA0 24186200 */  and        $v1, $v1, $v0
    /* 646A4 800CCEA4 40100B00 */  sll        $v0, $t3, 1
    /* 646A8 800CCEA8 21104B00 */  addu       $v0, $v0, $t3
    /* 646AC 800CCEAC 80100200 */  sll        $v0, $v0, 2
    /* 646B0 800CCEB0 21104B00 */  addu       $v0, $v0, $t3
    /* 646B4 800CCEB4 04004224 */  addiu      $v0, $v0, 0x4
    /* 646B8 800CCEB8 43100200 */  sra        $v0, $v0, 1
    /* 646BC 800CCEBC 23104201 */  subu       $v0, $t2, $v0
    /* 646C0 800CCEC0 FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* 646C4 800CCEC4 00130200 */  sll        $v0, $v0, 12
    /* 646C8 800CCEC8 25186200 */  or         $v1, $v1, $v0
    /* 646CC 800CCECC FFFC023C */  lui        $v0, (0xFCFFFFFF >> 16)
    /* 646D0 800CCED0 FFFF4234 */  ori        $v0, $v0, (0xFCFFFFFF & 0xFFFF)
    /* 646D4 800CCED4 24186200 */  and        $v1, $v1, $v0
    /* 646D8 800CCED8 03002231 */  andi       $v0, $t1, 0x3
    /* 646DC 800CCEDC 00160200 */  sll        $v0, $v0, 24
    /* 646E0 800CCEE0 25186200 */  or         $v1, $v1, $v0
    /* 646E4 800CCEE4 FFC3023C */  lui        $v0, (0xC3FFFFFF >> 16)
    /* 646E8 800CCEE8 FFFF4234 */  ori        $v0, $v0, (0xC3FFFFFF & 0xFFFF)
    /* 646EC 800CCEEC 24186200 */  and        $v1, $v1, $v0
    /* 646F0 800CCEF0 003C023C */  lui        $v0, (0x3C000000 >> 16)
    /* 646F4 800CCEF4 2410A200 */  and        $v0, $a1, $v0
    /* 646F8 800CCEF8 25186200 */  or         $v1, $v1, $v0
    /* 646FC 800CCEFC 000083AC */  sw         $v1, 0x0($a0)
    /* 64700 800CCF00 0800E003 */  jr         $ra
    /* 64704 800CCF04 21108000 */   addu      $v0, $a0, $zero
endlabel func_800CCE10
