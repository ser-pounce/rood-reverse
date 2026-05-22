nonmatching func_800AAD4C, 0x150

glabel func_800AAD4C
    /* 4254C 800AAD4C 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 42550 800AAD50 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 42554 800AAD54 80100400 */  sll        $v0, $a0, 2
    /* 42558 800AAD58 21104300 */  addu       $v0, $v0, $v1
    /* 4255C 800AAD5C 0000438C */  lw         $v1, 0x0($v0)
    /* 42560 800AAD60 00000000 */  nop
    /* 42564 800AAD64 4B006010 */  beqz       $v1, .L800AAE94
    /* 42568 800AAD68 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 4256C 800AAD6C 0200A228 */  slti       $v0, $a1, 0x2
    /* 42570 800AAD70 03004014 */  bnez       $v0, .L800AAD80
    /* 42574 800AAD74 01000224 */   addiu     $v0, $zero, 0x1
    /* 42578 800AAD78 A5AB0208 */  j          .L800AAE94
    /* 4257C 800AAD7C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L800AAD80:
    /* 42580 800AAD80 0400E214 */  bne        $a3, $v0, .L800AAD94
    /* 42584 800AAD84 80100500 */   sll       $v0, $a1, 2
    /* 42588 800AAD88 4200C010 */  beqz       $a2, .L800AAE94
    /* 4258C 800AAD8C 21100000 */   addu      $v0, $zero, $zero
    /* 42590 800AAD90 80100500 */  sll        $v0, $a1, 2
  .L800AAD94:
    /* 42594 800AAD94 0C184224 */  addiu      $v0, $v0, 0x180C
    /* 42598 800AAD98 01000924 */  addiu      $t1, $zero, 0x1
    /* 4259C 800AAD9C 1000E910 */  beq        $a3, $t1, .L800AADE0
    /* 425A0 800AADA0 21406200 */   addu      $t0, $v1, $v0
    /* 425A4 800AADA4 0200E228 */  slti       $v0, $a3, 0x2
    /* 425A8 800AADA8 05004010 */  beqz       $v0, .L800AADC0
    /* 425AC 800AADAC 00000000 */   nop
    /* 425B0 800AADB0 0800E010 */  beqz       $a3, .L800AADD4
    /* 425B4 800AADB4 00000000 */   nop
    /* 425B8 800AADB8 A5AB0208 */  j          .L800AAE94
    /* 425BC 800AADBC 21100000 */   addu      $v0, $zero, $zero
  .L800AADC0:
    /* 425C0 800AADC0 02000224 */  addiu      $v0, $zero, 0x2
    /* 425C4 800AADC4 2100E210 */  beq        $a3, $v0, .L800AAE4C
    /* 425C8 800AADC8 21100000 */   addu      $v0, $zero, $zero
    /* 425CC 800AADCC A5AB0208 */  j          .L800AAE94
    /* 425D0 800AADD0 00000000 */   nop
  .L800AADD4:
    /* 425D4 800AADD4 00000291 */  lbu        $v0, 0x0($t0)
    /* 425D8 800AADD8 A3AB0208 */  j          .L800AAE8C
    /* 425DC 800AADDC 0F004230 */   andi      $v0, $v0, 0xF
  .L800AADE0:
    /* 425E0 800AADE0 00000991 */  lbu        $t1, 0x0($t0)
    /* 425E4 800AADE4 10000224 */  addiu      $v0, $zero, 0x10
    /* 425E8 800AADE8 F0002331 */  andi       $v1, $t1, 0xF0
    /* 425EC 800AADEC 03006214 */  bne        $v1, $v0, .L800AADFC
    /* 425F0 800AADF0 0F002231 */   andi      $v0, $t1, 0xF
    /* 425F4 800AADF4 27004610 */  beq        $v0, $a2, .L800AAE94
    /* 425F8 800AADF8 21100000 */   addu      $v0, $zero, $zero
  .L800AADFC:
    /* 425FC 800AADFC 00000291 */  lbu        $v0, 0x0($t0)
    /* 42600 800AAE00 0F00C330 */  andi       $v1, $a2, 0xF
    /* 42604 800AAE04 020000A1 */  sb         $zero, 0x2($t0)
    /* 42608 800AAE08 F0004230 */  andi       $v0, $v0, 0xF0
    /* 4260C 800AAE0C 25104300 */  or         $v0, $v0, $v1
    /* 42610 800AAE10 000002A1 */  sb         $v0, 0x0($t0)
    /* 42614 800AAE14 01000224 */  addiu      $v0, $zero, 0x1
    /* 42618 800AAE18 0600A214 */  bne        $a1, $v0, .L800AAE34
    /* 4261C 800AAE1C 00000000 */   nop
    /* 42620 800AAE20 80100400 */  sll        $v0, $a0, 2
    /* 42624 800AAE24 21104400 */  addu       $v0, $v0, $a0
    /* 42628 800AAE28 40100200 */  sll        $v0, $v0, 1
    /* 4262C 800AAE2C 8EAB0208 */  j          .L800AAE38
    /* 42630 800AAE30 030002A1 */   sb        $v0, 0x3($t0)
  .L800AAE34:
    /* 42634 800AAE34 030000A1 */  sb         $zero, 0x3($t0)
  .L800AAE38:
    /* 42638 800AAE38 00000291 */  lbu        $v0, 0x0($t0)
    /* 4263C 800AAE3C 00190700 */  sll        $v1, $a3, 4
    /* 42640 800AAE40 0F004230 */  andi       $v0, $v0, 0xF
    /* 42644 800AAE44 A3AB0208 */  j          .L800AAE8C
    /* 42648 800AAE48 25104300 */   or        $v0, $v0, $v1
  .L800AAE4C:
    /* 4264C 800AAE4C 00000491 */  lbu        $a0, 0x0($t0)
    /* 42650 800AAE50 00000000 */  nop
    /* 42654 800AAE54 02190400 */  srl        $v1, $a0, 4
    /* 42658 800AAE58 08006910 */  beq        $v1, $t1, .L800AAE7C
    /* 4265C 800AAE5C 0F008230 */   andi      $v0, $a0, 0xF
    /* 42660 800AAE60 02006228 */  slti       $v0, $v1, 0x2
    /* 42664 800AAE64 0B004014 */  bnez       $v0, .L800AAE94
    /* 42668 800AAE68 21100000 */   addu      $v0, $zero, $zero
    /* 4266C 800AAE6C 05006710 */  beq        $v1, $a3, .L800AAE84
    /* 42670 800AAE70 00000000 */   nop
    /* 42674 800AAE74 A5AB0208 */  j          .L800AAE94
    /* 42678 800AAE78 00000000 */   nop
  .L800AAE7C:
    /* 4267C 800AAE7C A3AB0208 */  j          .L800AAE8C
    /* 42680 800AAE80 20004234 */   ori       $v0, $v0, 0x20
  .L800AAE84:
    /* 42684 800AAE84 0F008230 */  andi       $v0, $a0, 0xF
    /* 42688 800AAE88 10004234 */  ori        $v0, $v0, 0x10
  .L800AAE8C:
    /* 4268C 800AAE8C 000002A1 */  sb         $v0, 0x0($t0)
    /* 42690 800AAE90 21100000 */  addu       $v0, $zero, $zero
  .L800AAE94:
    /* 42694 800AAE94 0800E003 */  jr         $ra
    /* 42698 800AAE98 00000000 */   nop
endlabel func_800AAD4C
