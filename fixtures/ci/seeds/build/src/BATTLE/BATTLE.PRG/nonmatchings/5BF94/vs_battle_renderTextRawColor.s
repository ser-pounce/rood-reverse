nonmatching vs_battle_renderTextRawColor, 0x2E8

glabel vs_battle_renderTextRawColor
    /* 5DD40 800C6540 21688000 */  addu       $t5, $a0, $zero
    /* 5DD44 800C6544 2160A000 */  addu       $t4, $a1, $zero
    /* 5DD48 800C6548 801F033C */  lui        $v1, (0x1F800000 >> 16)
    /* 5DD4C 800C654C 00006B8C */  lw         $t3, (0x1F800000 & 0xFFFF)($v1)
    /* 5DD50 800C6550 037C0C00 */  sra        $t7, $t4, 16
    /* 5DD54 800C6554 00140C00 */  sll        $v0, $t4, 16
    /* 5DD58 800C6558 03640200 */  sra        $t4, $v0, 16
    /* 5DD5C 800C655C 0200E014 */  bnez       $a3, .L800C6568
    /* 5DD60 800C6560 00006324 */   addiu     $v1, $v1, %lo(D_1F800000)
    /* 5DD64 800C6564 0800678C */  lw         $a3, 0x8($v1)
  .L800C6568:
    /* 5DD68 800C6568 00E1053C */  lui        $a1, (0xE100000C >> 16)
    /* 5DD6C 800C656C 0C00A534 */  ori        $a1, $a1, (0xE100000C & 0xFFFF)
    /* 5DD70 800C6570 08006425 */  addiu      $a0, $t3, 0x8
    /* 5DD74 800C6574 00120400 */  sll        $v0, $a0, 8
    /* 5DD78 800C6578 02120200 */  srl        $v0, $v0, 8
    /* 5DD7C 800C657C 0001033C */  lui        $v1, (0x1000000 >> 16)
    /* 5DD80 800C6580 25104300 */  or         $v0, $v0, $v1
    /* 5DD84 800C6584 000062AD */  sw         $v0, 0x0($t3)
    /* 5DD88 800C6588 040065AD */  sw         $a1, 0x4($t3)
    /* 5DD8C 800C658C 21588000 */  addu       $t3, $a0, $zero
    /* 5DD90 800C6590 0000A991 */  lbu        $t1, 0x0($t5)
    /* 5DD94 800C6594 00000000 */  nop
    /* 5DD98 800C6598 95002011 */  beqz       $t1, .L800C67F0
    /* 5DD9C 800C659C 0100AD25 */   addiu     $t5, $t5, 0x1
    /* 5DDA0 800C65A0 0F80023C */  lui        $v0, %hi(D_800EB7B4)
    /* 5DDA4 800C65A4 B4B75924 */  addiu      $t9, $v0, %lo(D_800EB7B4)
    /* 5DDA8 800C65A8 0F80023C */  lui        $v0, %hi(D_800EB708)
    /* 5DDAC 800C65AC 08B75824 */  addiu      $t8, $v0, %lo(D_800EB708)
  .L800C65B0:
    /* 5DDB0 800C65B0 E0FF2E25 */  addiu      $t6, $t1, -0x20
    /* 5DDB4 800C65B4 2148C001 */  addu       $t1, $t6, $zero
    /* 5DDB8 800C65B8 FF002831 */  andi       $t0, $t1, 0xFF
    /* 5DDBC 800C65BC 3B00022D */  sltiu      $v0, $t0, 0x3B
    /* 5DDC0 800C65C0 06004014 */  bnez       $v0, .L800C65DC
    /* 5DDC4 800C65C4 FDFF0225 */   addiu     $v0, $t0, -0x3
    /* 5DDC8 800C65C8 3B000224 */  addiu      $v0, $zero, 0x3B
    /* 5DDCC 800C65CC 84000215 */  bne        $t0, $v0, .L800C67E0
    /* 5DDD0 800C65D0 00000000 */   nop
    /* 5DDD4 800C65D4 F8190308 */  j          .L800C67E0
    /* 5DDD8 800C65D8 FFFF8C25 */   addiu     $t4, $t4, -0x1
  .L800C65DC:
    /* 5DDDC 800C65DC 0200422C */  sltiu      $v0, $v0, 0x2
    /* 5DDE0 800C65E0 32004010 */  beqz       $v0, .L800C66AC
    /* 5DDE4 800C65E4 21500000 */   addu      $t2, $zero, $zero
    /* 5DDE8 800C65E8 0000A491 */  lbu        $a0, 0x0($t5)
    /* 5DDEC 800C65EC 00000000 */  nop
    /* 5DDF0 800C65F0 29008010 */  beqz       $a0, .L800C6698
    /* 5DDF4 800C65F4 0100A825 */   addiu     $t0, $t5, 0x1
  .L800C65F8:
    /* 5DDF8 800C65F8 E0FF8324 */  addiu      $v1, $a0, -0x20
    /* 5DDFC 800C65FC FF006530 */  andi       $a1, $v1, 0xFF
    /* 5DE00 800C6600 3C00A22C */  sltiu      $v0, $a1, 0x3C
    /* 5DE04 800C6604 20004010 */  beqz       $v0, .L800C6688
    /* 5DE08 800C6608 DFFF6424 */   addiu     $a0, $v1, -0x21
    /* 5DE0C 800C660C 42100500 */  srl        $v0, $a1, 1
    /* 5DE10 800C6610 21105900 */  addu       $v0, $v0, $t9
    /* 5DE14 800C6614 00004390 */  lbu        $v1, 0x0($v0)
    /* 5DE18 800C6618 80100500 */  sll        $v0, $a1, 2
    /* 5DE1C 800C661C 04004230 */  andi       $v0, $v0, 0x4
    /* 5DE20 800C6620 07184300 */  srav       $v1, $v1, $v0
    /* 5DE24 800C6624 0F006330 */  andi       $v1, $v1, 0xF
    /* 5DE28 800C6628 21504301 */  addu       $t2, $t2, $v1
    /* 5DE2C 800C662C FF008330 */  andi       $v1, $a0, 0xFF
    /* 5DE30 800C6630 1A00622C */  sltiu      $v0, $v1, 0x1A
    /* 5DE34 800C6634 14004010 */  beqz       $v0, .L800C6688
    /* 5DE38 800C6638 00000000 */   nop
    /* 5DE3C 800C663C 00000291 */  lbu        $v0, 0x0($t0)
    /* 5DE40 800C6640 00000000 */  nop
    /* 5DE44 800C6644 BFFF4524 */  addiu      $a1, $v0, -0x41
    /* 5DE48 800C6648 1A00A22C */  sltiu      $v0, $a1, 0x1A
    /* 5DE4C 800C664C 0E004010 */  beqz       $v0, .L800C6688
    /* 5DE50 800C6650 40100300 */   sll       $v0, $v1, 1
    /* 5DE54 800C6654 21104300 */  addu       $v0, $v0, $v1
    /* 5DE58 800C6658 80100200 */  sll        $v0, $v0, 2
    /* 5DE5C 800C665C 21104300 */  addu       $v0, $v0, $v1
    /* 5DE60 800C6660 40100200 */  sll        $v0, $v0, 1
    /* 5DE64 800C6664 2128A200 */  addu       $a1, $a1, $v0
    /* 5DE68 800C6668 82100500 */  srl        $v0, $a1, 2
    /* 5DE6C 800C666C 21105800 */  addu       $v0, $v0, $t8
    /* 5DE70 800C6670 00004390 */  lbu        $v1, 0x0($v0)
    /* 5DE74 800C6674 0300A230 */  andi       $v0, $a1, 0x3
    /* 5DE78 800C6678 40100200 */  sll        $v0, $v0, 1
    /* 5DE7C 800C667C 07184300 */  srav       $v1, $v1, $v0
    /* 5DE80 800C6680 03006330 */  andi       $v1, $v1, 0x3
    /* 5DE84 800C6684 23504301 */  subu       $t2, $t2, $v1
  .L800C6688:
    /* 5DE88 800C6688 00000491 */  lbu        $a0, 0x0($t0)
    /* 5DE8C 800C668C 00000000 */  nop
    /* 5DE90 800C6690 D9FF8014 */  bnez       $a0, .L800C65F8
    /* 5DE94 800C6694 01000825 */   addiu     $t0, $t0, 0x1
  .L800C6698:
    /* 5DE98 800C6698 FF002231 */  andi       $v0, $t1, 0xFF
    /* 5DE9C 800C669C FDFF4224 */  addiu      $v0, $v0, -0x3
    /* 5DEA0 800C66A0 06104A00 */  srlv       $v0, $t2, $v0
    /* 5DEA4 800C66A4 F8190308 */  j          .L800C67E0
    /* 5DEA8 800C66A8 23608201 */   subu      $t4, $t4, $v0
  .L800C66AC:
    /* 5DEAC 800C66AC 42100800 */  srl        $v0, $t0, 1
    /* 5DEB0 800C66B0 21105900 */  addu       $v0, $v0, $t9
    /* 5DEB4 800C66B4 00004390 */  lbu        $v1, 0x0($v0)
    /* 5DEB8 800C66B8 80100800 */  sll        $v0, $t0, 2
    /* 5DEBC 800C66BC 04004230 */  andi       $v0, $v0, 0x4
    /* 5DEC0 800C66C0 07184300 */  srav       $v1, $v1, $v0
    /* 5DEC4 800C66C4 0F006A30 */  andi       $t2, $v1, 0xF
    /* 5DEC8 800C66C8 45004011 */  beqz       $t2, .L800C67E0
    /* 5DECC 800C66CC 0F80023C */   lui       $v0, %hi(D_800EB7D4)
    /* 5DED0 800C66D0 D4B74224 */  addiu      $v0, $v0, %lo(D_800EB7D4)
    /* 5DED4 800C66D4 21100201 */  addu       $v0, $t0, $v0
    /* 5DED8 800C66D8 14006925 */  addiu      $t1, $t3, 0x14
    /* 5DEDC 800C66DC 00004590 */  lbu        $a1, 0x0($v0)
    /* 5DEE0 800C66E0 00120900 */  sll        $v0, $t1, 8
    /* 5DEE4 800C66E4 02120200 */  srl        $v0, $v0, 8
    /* 5DEE8 800C66E8 0004033C */  lui        $v1, (0x4000000 >> 16)
    /* 5DEEC 800C66EC 25104300 */  or         $v0, $v0, $v1
    /* 5DEF0 800C66F0 000062AD */  sw         $v0, 0x0($t3)
    /* 5DEF4 800C66F4 0064023C */  lui        $v0, (0x64000000 >> 16)
    /* 5DEF8 800C66F8 2510C200 */  or         $v0, $a2, $v0
    /* 5DEFC 800C66FC 040062AD */  sw         $v0, 0x4($t3)
    /* 5DF00 800C6700 FFFF8231 */  andi       $v0, $t4, 0xFFFF
    /* 5DF04 800C6704 001C0F00 */  sll        $v1, $t7, 16
    /* 5DF08 800C6708 25104300 */  or         $v0, $v0, $v1
    /* 5DF0C 800C670C 080062AD */  sw         $v0, 0x8($t3)
    /* 5DF10 800C6710 0A00023C */  lui        $v0, (0xA0000 >> 16)
    /* 5DF14 800C6714 25104201 */  or         $v0, $t2, $v0
    /* 5DF18 800C6718 100062AD */  sw         $v0, 0x10($t3)
    /* 5DF1C 800C671C FE00A430 */  andi       $a0, $a1, 0xFE
    /* 5DF20 800C6720 0100A330 */  andi       $v1, $a1, 0x1
    /* 5DF24 800C6724 80100300 */  sll        $v0, $v1, 2
    /* 5DF28 800C6728 21104300 */  addu       $v0, $v0, $v1
    /* 5DF2C 800C672C 40120200 */  sll        $v0, $v0, 9
    /* 5DF30 800C6730 004C4224 */  addiu      $v0, $v0, 0x4C00
    /* 5DF34 800C6734 25208200 */  or         $a0, $a0, $v0
    /* 5DF38 800C6738 F637023C */  lui        $v0, (0x37F60000 >> 16)
    /* 5DF3C 800C673C 25208200 */  or         $a0, $a0, $v0
    /* 5DF40 800C6740 0A000224 */  addiu      $v0, $zero, 0xA
    /* 5DF44 800C6744 0D000215 */  bne        $t0, $v0, .L800C677C
    /* 5DF48 800C6748 0C0064AD */   sw        $a0, 0xC($t3)
    /* 5DF4C 800C674C F637043C */  lui        $a0, (0x37F64BE8 >> 16)
    /* 5DF50 800C6750 E84B8434 */  ori        $a0, $a0, (0x37F64BE8 & 0xFFFF)
    /* 5DF54 800C6754 FFFF8325 */  addiu      $v1, $t4, -0x1
    /* 5DF58 800C6758 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 5DF5C 800C675C FFFFE225 */  addiu      $v0, $t7, -0x1
    /* 5DF60 800C6760 00140200 */  sll        $v0, $v0, 16
    /* 5DF64 800C6764 25186200 */  or         $v1, $v1, $v0
    /* 5DF68 800C6768 0B00023C */  lui        $v0, (0xB0000 >> 16)
    /* 5DF6C 800C676C 25104201 */  or         $v0, $t2, $v0
    /* 5DF70 800C6770 080063AD */  sw         $v1, 0x8($t3)
    /* 5DF74 800C6774 0C0064AD */  sw         $a0, 0xC($t3)
    /* 5DF78 800C6778 100062AD */  sw         $v0, 0x10($t3)
  .L800C677C:
    /* 5DF7C 800C677C 21582001 */  addu       $t3, $t1, $zero
    /* 5DF80 800C6780 DFFFC925 */  addiu      $t1, $t6, -0x21
    /* 5DF84 800C6784 FF002331 */  andi       $v1, $t1, 0xFF
    /* 5DF88 800C6788 1A00622C */  sltiu      $v0, $v1, 0x1A
    /* 5DF8C 800C678C 14004010 */  beqz       $v0, .L800C67E0
    /* 5DF90 800C6790 21608A01 */   addu      $t4, $t4, $t2
    /* 5DF94 800C6794 0000A291 */  lbu        $v0, 0x0($t5)
    /* 5DF98 800C6798 00000000 */  nop
    /* 5DF9C 800C679C BFFF4524 */  addiu      $a1, $v0, -0x41
    /* 5DFA0 800C67A0 1A00A22C */  sltiu      $v0, $a1, 0x1A
    /* 5DFA4 800C67A4 0E004010 */  beqz       $v0, .L800C67E0
    /* 5DFA8 800C67A8 40100300 */   sll       $v0, $v1, 1
    /* 5DFAC 800C67AC 21104300 */  addu       $v0, $v0, $v1
    /* 5DFB0 800C67B0 80100200 */  sll        $v0, $v0, 2
    /* 5DFB4 800C67B4 21104300 */  addu       $v0, $v0, $v1
    /* 5DFB8 800C67B8 40100200 */  sll        $v0, $v0, 1
    /* 5DFBC 800C67BC 2128A200 */  addu       $a1, $a1, $v0
    /* 5DFC0 800C67C0 82100500 */  srl        $v0, $a1, 2
    /* 5DFC4 800C67C4 21105800 */  addu       $v0, $v0, $t8
    /* 5DFC8 800C67C8 00004390 */  lbu        $v1, 0x0($v0)
    /* 5DFCC 800C67CC 0300A230 */  andi       $v0, $a1, 0x3
    /* 5DFD0 800C67D0 40100200 */  sll        $v0, $v0, 1
    /* 5DFD4 800C67D4 07184300 */  srav       $v1, $v1, $v0
    /* 5DFD8 800C67D8 03006330 */  andi       $v1, $v1, 0x3
    /* 5DFDC 800C67DC 23608301 */  subu       $t4, $t4, $v1
  .L800C67E0:
    /* 5DFE0 800C67E0 0000A991 */  lbu        $t1, 0x0($t5)
    /* 5DFE4 800C67E4 00000000 */  nop
    /* 5DFE8 800C67E8 71FF2015 */  bnez       $t1, .L800C65B0
    /* 5DFEC 800C67EC 0100AD25 */   addiu     $t5, $t5, 0x1
  .L800C67F0:
    /* 5DFF0 800C67F0 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 5DFF4 800C67F4 0000E28C */  lw         $v0, 0x0($a3)
    /* 5DFF8 800C67F8 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 5DFFC 800C67FC 24104300 */  and        $v0, $v0, $v1
    /* 5E000 800C6800 801F033C */  lui        $v1, (0x1F800000 >> 16)
    /* 5E004 800C6804 000062AD */  sw         $v0, 0x0($t3)
    /* 5E008 800C6808 0000628C */  lw         $v0, (0x1F800000 & 0xFFFF)($v1)
    /* 5E00C 800C680C 00000000 */  nop
    /* 5E010 800C6810 00120200 */  sll        $v0, $v0, 8
    /* 5E014 800C6814 02120200 */  srl        $v0, $v0, 8
    /* 5E018 800C6818 0000E2AC */  sw         $v0, 0x0($a3)
    /* 5E01C 800C681C 04006225 */  addiu      $v0, $t3, 0x4
    /* 5E020 800C6820 0800E003 */  jr         $ra
    /* 5E024 800C6824 000062AC */   sw        $v0, (0x1F800000 & 0xFFFF)($v1)
endlabel vs_battle_renderTextRawColor
