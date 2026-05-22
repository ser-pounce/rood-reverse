nonmatching func_800BDC9C, 0x2D0

glabel func_800BDC9C
    /* 5549C 800BDC9C 21308000 */  addu       $a2, $a0, $zero
    /* 554A0 800BDCA0 0000C390 */  lbu        $v1, 0x0($a2)
    /* 554A4 800BDCA4 EB000224 */  addiu      $v0, $zero, 0xEB
    /* 554A8 800BDCA8 39006210 */  beq        $v1, $v0, .L800BDD90
    /* 554AC 800BDCAC EC006228 */   slti      $v0, $v1, 0xEC
    /* 554B0 800BDCB0 05004010 */  beqz       $v0, .L800BDCC8
    /* 554B4 800BDCB4 EA000224 */   addiu     $v0, $zero, 0xEA
    /* 554B8 800BDCB8 0A006210 */  beq        $v1, $v0, .L800BDCE4
    /* 554BC 800BDCBC 0F80043C */   lui       $a0, %hi(D_800F4BA4)
    /* 554C0 800BDCC0 0800E003 */  jr         $ra
    /* 554C4 800BDCC4 00000000 */   nop
  .L800BDCC8:
    /* 554C8 800BDCC8 EC000224 */  addiu      $v0, $zero, 0xEC
    /* 554CC 800BDCCC 56006210 */  beq        $v1, $v0, .L800BDE28
    /* 554D0 800BDCD0 EF000224 */   addiu     $v0, $zero, 0xEF
    /* 554D4 800BDCD4 7E006210 */  beq        $v1, $v0, .L800BDED0
    /* 554D8 800BDCD8 00000000 */   nop
    /* 554DC 800BDCDC 0800E003 */  jr         $ra
    /* 554E0 800BDCE0 00000000 */   nop
  .L800BDCE4:
    /* 554E4 800BDCE4 A44B838C */  lw         $v1, %lo(D_800F4BA4)($a0)
    /* 554E8 800BDCE8 0300C290 */  lbu        $v0, 0x3($a2)
    /* 554EC 800BDCEC 00000000 */  nop
    /* 554F0 800BDCF0 890162A0 */  sb         $v0, 0x189($v1)
    /* 554F4 800BDCF4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 554F8 800BDCF8 0F004014 */  bnez       $v0, .L800BDD38
    /* 554FC 800BDCFC 00000000 */   nop
    /* 55500 800BDD00 0100C290 */  lbu        $v0, 0x1($a2)
    /* 55504 800BDD04 A44B838C */  lw         $v1, %lo(D_800F4BA4)($a0)
    /* 55508 800BDD08 04004010 */  beqz       $v0, .L800BDD1C
    /* 5550C 800BDD0C 00000000 */   nop
    /* 55510 800BDD10 0100C290 */  lbu        $v0, 0x1($a2)
    /* 55514 800BDD14 48F70208 */  j          .L800BDD20
    /* 55518 800BDD18 80100200 */   sll       $v0, $v0, 2
  .L800BDD1C:
    /* 5551C 800BDD1C 00020224 */  addiu      $v0, $zero, 0x200
  .L800BDD20:
    /* 55520 800BDD20 820162A4 */  sh         $v0, 0x182($v1)
    /* 55524 800BDD24 0F80023C */  lui        $v0, %hi(D_800F4BA4)
    /* 55528 800BDD28 A44B438C */  lw         $v1, %lo(D_800F4BA4)($v0)
    /* 5552C 800BDD2C 01000224 */  addiu      $v0, $zero, 0x1
    /* 55530 800BDD30 62F70208 */  j          .L800BDD88
    /* 55534 800BDD34 800162A0 */   sb        $v0, 0x180($v1)
  .L800BDD38:
    /* 55538 800BDD38 0100C290 */  lbu        $v0, 0x1($a2)
    /* 5553C 800BDD3C A44B848C */  lw         $a0, %lo(D_800F4BA4)($a0)
    /* 55540 800BDD40 07004010 */  beqz       $v0, .L800BDD60
    /* 55544 800BDD44 00000000 */   nop
    /* 55548 800BDD48 0100C290 */  lbu        $v0, 0x1($a2)
    /* 5554C 800BDD4C 82018394 */  lhu        $v1, 0x182($a0)
    /* 55550 800BDD50 80100200 */  sll        $v0, $v0, 2
    /* 55554 800BDD54 23104300 */  subu       $v0, $v0, $v1
    /* 55558 800BDD58 59F70208 */  j          .L800BDD64
    /* 5555C 800BDD5C 840183A4 */   sh        $v1, 0x184($a0)
  .L800BDD60:
    /* 55560 800BDD60 00020224 */  addiu      $v0, $zero, 0x200
  .L800BDD64:
    /* 55564 800BDD64 860182A4 */  sh         $v0, 0x186($a0)
    /* 55568 800BDD68 0F80043C */  lui        $a0, %hi(D_800F4BA4)
    /* 5556C 800BDD6C A44B838C */  lw         $v1, %lo(D_800F4BA4)($a0)
    /* 55570 800BDD70 0200C290 */  lbu        $v0, 0x2($a2)
    /* 55574 800BDD74 00000000 */  nop
    /* 55578 800BDD78 810162A0 */  sb         $v0, 0x181($v1)
    /* 5557C 800BDD7C A44B828C */  lw         $v0, %lo(D_800F4BA4)($a0)
    /* 55580 800BDD80 00000000 */  nop
    /* 55584 800BDD84 880140A0 */  sb         $zero, 0x188($v0)
  .L800BDD88:
    /* 55588 800BDD88 0800E003 */  jr         $ra
    /* 5558C 800BDD8C 21100000 */   addu      $v0, $zero, $zero
  .L800BDD90:
    /* 55590 800BDD90 0F80053C */  lui        $a1, %hi(D_800F4BA4)
    /* 55594 800BDD94 A44BA38C */  lw         $v1, %lo(D_800F4BA4)($a1)
    /* 55598 800BDD98 0300C290 */  lbu        $v0, 0x3($a2)
    /* 5559C 800BDD9C 00000000 */  nop
    /* 555A0 800BDDA0 950162A0 */  sb         $v0, 0x195($v1)
    /* 555A4 800BDDA4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 555A8 800BDDA8 0A004014 */  bnez       $v0, .L800BDDD4
    /* 555AC 800BDDAC 00000000 */   nop
    /* 555B0 800BDDB0 0100C290 */  lbu        $v0, 0x1($a2)
    /* 555B4 800BDDB4 A44BA38C */  lw         $v1, %lo(D_800F4BA4)($a1)
    /* 555B8 800BDDB8 02004010 */  beqz       $v0, .L800BDDC4
    /* 555BC 800BDDBC 40000424 */   addiu     $a0, $zero, 0x40
    /* 555C0 800BDDC0 0100C490 */  lbu        $a0, 0x1($a2)
  .L800BDDC4:
    /* 555C4 800BDDC4 01000224 */  addiu      $v0, $zero, 0x1
    /* 555C8 800BDDC8 8E0164A4 */  sh         $a0, 0x18E($v1)
    /* 555CC 800BDDCC 62F70208 */  j          .L800BDD88
    /* 555D0 800BDDD0 8C0162A0 */   sb        $v0, 0x18C($v1)
  .L800BDDD4:
    /* 555D4 800BDDD4 A44BA48C */  lw         $a0, %lo(D_800F4BA4)($a1)
    /* 555D8 800BDDD8 00000000 */  nop
    /* 555DC 800BDDDC 8E018294 */  lhu        $v0, 0x18E($a0)
    /* 555E0 800BDDE0 00000000 */  nop
    /* 555E4 800BDDE4 900182A4 */  sh         $v0, 0x190($a0)
    /* 555E8 800BDDE8 00140200 */  sll        $v0, $v0, 16
    /* 555EC 800BDDEC 0100C390 */  lbu        $v1, 0x1($a2)
    /* 555F0 800BDDF0 032C0200 */  sra        $a1, $v0, 16
    /* 555F4 800BDDF4 02006010 */  beqz       $v1, .L800BDE00
    /* 555F8 800BDDF8 40000224 */   addiu     $v0, $zero, 0x40
    /* 555FC 800BDDFC 21106000 */  addu       $v0, $v1, $zero
  .L800BDE00:
    /* 55600 800BDE00 23104500 */  subu       $v0, $v0, $a1
    /* 55604 800BDE04 920182A4 */  sh         $v0, 0x192($a0)
    /* 55608 800BDE08 0F80043C */  lui        $a0, %hi(D_800F4BA4)
    /* 5560C 800BDE0C A44B838C */  lw         $v1, %lo(D_800F4BA4)($a0)
    /* 55610 800BDE10 0200C290 */  lbu        $v0, 0x2($a2)
    /* 55614 800BDE14 00000000 */  nop
    /* 55618 800BDE18 8D0162A0 */  sb         $v0, 0x18D($v1)
    /* 5561C 800BDE1C A44B828C */  lw         $v0, %lo(D_800F4BA4)($a0)
    /* 55620 800BDE20 62F70208 */  j          .L800BDD88
    /* 55624 800BDE24 940140A0 */   sb        $zero, 0x194($v0)
  .L800BDE28:
    /* 55628 800BDE28 0F80043C */  lui        $a0, %hi(D_800F4BA4)
    /* 5562C 800BDE2C A44B838C */  lw         $v1, %lo(D_800F4BA4)($a0)
    /* 55630 800BDE30 0300C290 */  lbu        $v0, 0x3($a2)
    /* 55634 800BDE34 00000000 */  nop
    /* 55638 800BDE38 A10162A0 */  sb         $v0, 0x1A1($v1)
    /* 5563C 800BDE3C FF004230 */  andi       $v0, $v0, 0xFF
    /* 55640 800BDE40 0F004014 */  bnez       $v0, .L800BDE80
    /* 55644 800BDE44 00000000 */   nop
    /* 55648 800BDE48 0100C290 */  lbu        $v0, 0x1($a2)
    /* 5564C 800BDE4C A44B838C */  lw         $v1, %lo(D_800F4BA4)($a0)
    /* 55650 800BDE50 04004010 */  beqz       $v0, .L800BDE64
    /* 55654 800BDE54 00000000 */   nop
    /* 55658 800BDE58 0100C290 */  lbu        $v0, 0x1($a2)
    /* 5565C 800BDE5C 9AF70208 */  j          .L800BDE68
    /* 55660 800BDE60 C0110200 */   sll       $v0, $v0, 7
  .L800BDE64:
    /* 55664 800BDE64 00100224 */  addiu      $v0, $zero, 0x1000
  .L800BDE68:
    /* 55668 800BDE68 9A0162A4 */  sh         $v0, 0x19A($v1)
    /* 5566C 800BDE6C 0F80023C */  lui        $v0, %hi(D_800F4BA4)
    /* 55670 800BDE70 A44B438C */  lw         $v1, %lo(D_800F4BA4)($v0)
    /* 55674 800BDE74 01000224 */  addiu      $v0, $zero, 0x1
    /* 55678 800BDE78 62F70208 */  j          .L800BDD88
    /* 5567C 800BDE7C 980162A0 */   sb        $v0, 0x198($v1)
  .L800BDE80:
    /* 55680 800BDE80 0100C290 */  lbu        $v0, 0x1($a2)
    /* 55684 800BDE84 A44B848C */  lw         $a0, %lo(D_800F4BA4)($a0)
    /* 55688 800BDE88 07004010 */  beqz       $v0, .L800BDEA8
    /* 5568C 800BDE8C 00000000 */   nop
    /* 55690 800BDE90 0100C290 */  lbu        $v0, 0x1($a2)
    /* 55694 800BDE94 9A018394 */  lhu        $v1, 0x19A($a0)
    /* 55698 800BDE98 C0110200 */  sll        $v0, $v0, 7
    /* 5569C 800BDE9C 23104300 */  subu       $v0, $v0, $v1
    /* 556A0 800BDEA0 ABF70208 */  j          .L800BDEAC
    /* 556A4 800BDEA4 9C0183A4 */   sh        $v1, 0x19C($a0)
  .L800BDEA8:
    /* 556A8 800BDEA8 00100224 */  addiu      $v0, $zero, 0x1000
  .L800BDEAC:
    /* 556AC 800BDEAC 9E0182A4 */  sh         $v0, 0x19E($a0)
    /* 556B0 800BDEB0 0F80043C */  lui        $a0, %hi(D_800F4BA4)
    /* 556B4 800BDEB4 A44B838C */  lw         $v1, %lo(D_800F4BA4)($a0)
    /* 556B8 800BDEB8 0200C290 */  lbu        $v0, 0x2($a2)
    /* 556BC 800BDEBC 00000000 */  nop
    /* 556C0 800BDEC0 990162A0 */  sb         $v0, 0x199($v1)
    /* 556C4 800BDEC4 A44B828C */  lw         $v0, %lo(D_800F4BA4)($a0)
    /* 556C8 800BDEC8 62F70208 */  j          .L800BDD88
    /* 556CC 800BDECC A00140A0 */   sb        $zero, 0x1A0($v0)
  .L800BDED0:
    /* 556D0 800BDED0 0F80023C */  lui        $v0, %hi(D_800F4BA4)
    /* 556D4 800BDED4 A44B448C */  lw         $a0, %lo(D_800F4BA4)($v0)
    /* 556D8 800BDED8 0200C290 */  lbu        $v0, 0x2($a2)
    /* 556DC 800BDEDC 00000000 */  nop
    /* 556E0 800BDEE0 15004014 */  bnez       $v0, .L800BDF38
    /* 556E4 800BDEE4 A6018324 */   addiu     $v1, $a0, 0x1A6
    /* 556E8 800BDEE8 21100000 */  addu       $v0, $zero, $zero
    /* 556EC 800BDEEC BB0180A0 */  sb         $zero, 0x1BB($a0)
    /* 556F0 800BDEF0 0800E003 */  jr         $ra
    /* 556F4 800BDEF4 090060A0 */   sb        $zero, 0x9($v1)
  .L800BDEF8:
    /* 556F8 800BDEF8 0100C290 */  lbu        $v0, 0x1($a2)
    /* 556FC 800BDEFC 00000000 */  nop
    /* 55700 800BDF00 040062A4 */  sh         $v0, 0x4($v1)
    /* 55704 800BDF04 0200C290 */  lbu        $v0, 0x2($a2)
    /* 55708 800BDF08 00000000 */  nop
    /* 5570C 800BDF0C 060062A4 */  sh         $v0, 0x6($v1)
    /* 55710 800BDF10 0300C290 */  lbu        $v0, 0x3($a2)
    /* 55714 800BDF14 00000000 */  nop
    /* 55718 800BDF18 0A0062A0 */  sb         $v0, 0xA($v1)
    /* 5571C 800BDF1C 0400C290 */  lbu        $v0, 0x4($a2)
    /* 55720 800BDF20 00000000 */  nop
    /* 55724 800BDF24 010062A0 */  sb         $v0, 0x1($v1)
    /* 55728 800BDF28 0500C290 */  lbu        $v0, 0x5($a2)
    /* 5572C 800BDF2C 080060A0 */  sb         $zero, 0x8($v1)
    /* 55730 800BDF30 D9F70208 */  j          .L800BDF64
    /* 55734 800BDF34 090062A0 */   sb        $v0, 0x9($v1)
  .L800BDF38:
    /* 55738 800BDF38 21200000 */  addu       $a0, $zero, $zero
  .L800BDF3C:
    /* 5573C 800BDF3C 09006290 */  lbu        $v0, 0x9($v1)
    /* 55740 800BDF40 00000000 */  nop
    /* 55744 800BDF44 ECFF4010 */  beqz       $v0, .L800BDEF8
    /* 55748 800BDF48 01008224 */   addiu     $v0, $a0, 0x1
    /* 5574C 800BDF4C 21204000 */  addu       $a0, $v0, $zero
    /* 55750 800BDF50 00140200 */  sll        $v0, $v0, 16
    /* 55754 800BDF54 03140200 */  sra        $v0, $v0, 16
    /* 55758 800BDF58 02004228 */  slti       $v0, $v0, 0x2
    /* 5575C 800BDF5C F7FF4014 */  bnez       $v0, .L800BDF3C
    /* 55760 800BDF60 0C006324 */   addiu     $v1, $v1, 0xC
  .L800BDF64:
    /* 55764 800BDF64 0800E003 */  jr         $ra
    /* 55768 800BDF68 21100000 */   addu      $v0, $zero, $zero
endlabel func_800BDC9C
