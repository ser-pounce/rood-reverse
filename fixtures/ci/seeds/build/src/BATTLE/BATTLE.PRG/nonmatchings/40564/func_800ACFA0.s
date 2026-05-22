nonmatching func_800ACFA0, 0x68

glabel func_800ACFA0
    /* 447A0 800ACFA0 0000A790 */  lbu        $a3, 0x0($a1)
    /* 447A4 800ACFA4 0100A290 */  lbu        $v0, 0x1($a1)
    /* 447A8 800ACFA8 003A0700 */  sll        $a3, $a3, 8
    /* 447AC 800ACFAC 2538E200 */  or         $a3, $a3, $v0
    /* 447B0 800ACFB0 40100700 */  sll        $v0, $a3, 1
    /* 447B4 800ACFB4 000082A4 */  sh         $v0, 0x0($a0)
    /* 447B8 800ACFB8 0200A790 */  lbu        $a3, 0x2($a1)
    /* 447BC 800ACFBC 0300A290 */  lbu        $v0, 0x3($a1)
    /* 447C0 800ACFC0 003A0700 */  sll        $a3, $a3, 8
    /* 447C4 800ACFC4 2538E200 */  or         $a3, $a3, $v0
    /* 447C8 800ACFC8 40100700 */  sll        $v0, $a3, 1
    /* 447CC 800ACFCC 020082A4 */  sh         $v0, 0x2($a0)
    /* 447D0 800ACFD0 0400A790 */  lbu        $a3, 0x4($a1)
    /* 447D4 800ACFD4 0500A390 */  lbu        $v1, 0x5($a1)
    /* 447D8 800ACFD8 06000224 */  addiu      $v0, $zero, 0x6
    /* 447DC 800ACFDC 060082A4 */  sh         $v0, 0x6($a0)
    /* 447E0 800ACFE0 003A0700 */  sll        $a3, $a3, 8
    /* 447E4 800ACFE4 2538E300 */  or         $a3, $a3, $v1
    /* 447E8 800ACFE8 40100700 */  sll        $v0, $a3, 1
    /* 447EC 800ACFEC 040082A4 */  sh         $v0, 0x4($a0)
    /* 447F0 800ACFF0 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 447F4 800ACFF4 0200C210 */  beq        $a2, $v0, .L800AD000
    /* 447F8 800ACFF8 00000000 */   nop
    /* 447FC 800ACFFC 060080A4 */  sh         $zero, 0x6($a0)
  .L800AD000:
    /* 44800 800AD000 0800E003 */  jr         $ra
    /* 44804 800AD004 A60280A4 */   sh        $zero, 0x2A6($a0)
endlabel func_800ACFA0
