nonmatching vs_battle_script_setFlagImm, 0x18C

glabel vs_battle_script_setFlagImm
    /* 50550 800B8D50 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 50554 800B8D54 1800BFAF */  sw         $ra, 0x18($sp)
    /* 50558 800B8D58 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5055C 800B8D5C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 50560 800B8D60 02008390 */  lbu        $v1, 0x2($a0)
    /* 50564 800B8D64 01008590 */  lbu        $a1, 0x1($a0)
    /* 50568 800B8D68 03009190 */  lbu        $s1, 0x3($a0)
    /* 5056C 800B8D6C 82180300 */  srl        $v1, $v1, 2
    /* 50570 800B8D70 0F00A230 */  andi       $v0, $a1, 0xF
    /* 50574 800B8D74 80110200 */  sll        $v0, $v0, 6
    /* 50578 800B8D78 21806200 */  addu       $s0, $v1, $v0
    /* 5057C 800B8D7C F000A530 */  andi       $a1, $a1, 0xF0
    /* 50580 800B8D80 30000224 */  addiu      $v0, $zero, 0x30
    /* 50584 800B8D84 3300A210 */  beq        $a1, $v0, .L800B8E54
    /* 50588 800B8D88 3100A228 */   slti      $v0, $a1, 0x31
    /* 5058C 800B8D8C 0D004010 */  beqz       $v0, .L800B8DC4
    /* 50590 800B8D90 10000224 */   addiu     $v0, $zero, 0x10
    /* 50594 800B8D94 2100A210 */  beq        $a1, $v0, .L800B8E1C
    /* 50598 800B8D98 1100A228 */   slti      $v0, $a1, 0x11
    /* 5059C 800B8D9C 05004010 */  beqz       $v0, .L800B8DB4
    /* 505A0 800B8DA0 20000224 */   addiu     $v0, $zero, 0x20
    /* 505A4 800B8DA4 1700A010 */  beqz       $a1, .L800B8E04
    /* 505A8 800B8DA8 00000000 */   nop
    /* 505AC 800B8DAC B1E30208 */  j          .L800B8EC4
    /* 505B0 800B8DB0 00000000 */   nop
  .L800B8DB4:
    /* 505B4 800B8DB4 1F00A210 */  beq        $a1, $v0, .L800B8E34
    /* 505B8 800B8DB8 00000000 */   nop
    /* 505BC 800B8DBC B1E30208 */  j          .L800B8EC4
    /* 505C0 800B8DC0 00000000 */   nop
  .L800B8DC4:
    /* 505C4 800B8DC4 50000224 */  addiu      $v0, $zero, 0x50
    /* 505C8 800B8DC8 3000A210 */  beq        $a1, $v0, .L800B8E8C
    /* 505CC 800B8DCC 5100A228 */   slti      $v0, $a1, 0x51
    /* 505D0 800B8DD0 05004010 */  beqz       $v0, .L800B8DE8
    /* 505D4 800B8DD4 40000224 */   addiu     $v0, $zero, 0x40
    /* 505D8 800B8DD8 2500A210 */  beq        $a1, $v0, .L800B8E70
    /* 505DC 800B8DDC 00000000 */   nop
    /* 505E0 800B8DE0 B1E30208 */  j          .L800B8EC4
    /* 505E4 800B8DE4 00000000 */   nop
  .L800B8DE8:
    /* 505E8 800B8DE8 60000224 */  addiu      $v0, $zero, 0x60
    /* 505EC 800B8DEC 2C00A210 */  beq        $a1, $v0, .L800B8EA0
    /* 505F0 800B8DF0 70000224 */   addiu     $v0, $zero, 0x70
    /* 505F4 800B8DF4 3000A210 */  beq        $a1, $v0, .L800B8EB8
    /* 505F8 800B8DF8 21200002 */   addu      $a0, $s0, $zero
    /* 505FC 800B8DFC B1E30208 */  j          .L800B8EC4
    /* 50600 800B8E00 00000000 */   nop
  .L800B8E04:
    /* 50604 800B8E04 FDFA020C */  jal        vs_battle_getStateFlag
    /* 50608 800B8E08 21200002 */   addu      $a0, $s0, $zero
    /* 5060C 800B8E0C 21200002 */  addu       $a0, $s0, $zero
    /* 50610 800B8E10 21102202 */  addu       $v0, $s1, $v0
    /* 50614 800B8E14 AFE30208 */  j          .L800B8EBC
    /* 50618 800B8E18 FF004530 */   andi      $a1, $v0, 0xFF
  .L800B8E1C:
    /* 5061C 800B8E1C FDFA020C */  jal        vs_battle_getStateFlag
    /* 50620 800B8E20 21200002 */   addu      $a0, $s0, $zero
    /* 50624 800B8E24 21200002 */  addu       $a0, $s0, $zero
    /* 50628 800B8E28 23105100 */  subu       $v0, $v0, $s1
    /* 5062C 800B8E2C AFE30208 */  j          .L800B8EBC
    /* 50630 800B8E30 FF004530 */   andi      $a1, $v0, 0xFF
  .L800B8E34:
    /* 50634 800B8E34 FDFA020C */  jal        vs_battle_getStateFlag
    /* 50638 800B8E38 21200002 */   addu      $a0, $s0, $zero
    /* 5063C 800B8E3C FF004230 */  andi       $v0, $v0, 0xFF
    /* 50640 800B8E40 18002202 */  mult       $s1, $v0
    /* 50644 800B8E44 21200002 */  addu       $a0, $s0, $zero
    /* 50648 800B8E48 12300000 */  mflo       $a2
    /* 5064C 800B8E4C AFE30208 */  j          .L800B8EBC
    /* 50650 800B8E50 FF00C530 */   andi      $a1, $a2, 0xFF
  .L800B8E54:
    /* 50654 800B8E54 FDFA020C */  jal        vs_battle_getStateFlag
    /* 50658 800B8E58 21200002 */   addu      $a0, $s0, $zero
    /* 5065C 800B8E5C FF004530 */  andi       $a1, $v0, 0xFF
    /* 50660 800B8E60 1A00B100 */  div        $zero, $a1, $s1
    /* 50664 800B8E64 12280000 */  mflo       $a1
    /* 50668 800B8E68 AFE30208 */  j          .L800B8EBC
    /* 5066C 800B8E6C 21200002 */   addu      $a0, $s0, $zero
  .L800B8E70:
    /* 50670 800B8E70 FDFA020C */  jal        vs_battle_getStateFlag
    /* 50674 800B8E74 21200002 */   addu      $a0, $s0, $zero
    /* 50678 800B8E78 FF004230 */  andi       $v0, $v0, 0xFF
    /* 5067C 800B8E7C 1A005100 */  div        $zero, $v0, $s1
    /* 50680 800B8E80 10280000 */  mfhi       $a1
    /* 50684 800B8E84 AFE30208 */  j          .L800B8EBC
    /* 50688 800B8E88 21200002 */   addu      $a0, $s0, $zero
  .L800B8E8C:
    /* 5068C 800B8E8C FDFA020C */  jal        vs_battle_getStateFlag
    /* 50690 800B8E90 21200002 */   addu      $a0, $s0, $zero
    /* 50694 800B8E94 21200002 */  addu       $a0, $s0, $zero
    /* 50698 800B8E98 AFE30208 */  j          .L800B8EBC
    /* 5069C 800B8E9C 24282202 */   and       $a1, $s1, $v0
  .L800B8EA0:
    /* 506A0 800B8EA0 FDFA020C */  jal        vs_battle_getStateFlag
    /* 506A4 800B8EA4 21200002 */   addu      $a0, $s0, $zero
    /* 506A8 800B8EA8 21200002 */  addu       $a0, $s0, $zero
    /* 506AC 800B8EAC 25102202 */  or         $v0, $s1, $v0
    /* 506B0 800B8EB0 AFE30208 */  j          .L800B8EBC
    /* 506B4 800B8EB4 FF004530 */   andi      $a1, $v0, 0xFF
  .L800B8EB8:
    /* 506B8 800B8EB8 21282002 */  addu       $a1, $s1, $zero
  .L800B8EBC:
    /* 506BC 800B8EBC 05FB020C */  jal        vs_battle_setStateFlag
    /* 506C0 800B8EC0 00000000 */   nop
  .L800B8EC4:
    /* 506C4 800B8EC4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 506C8 800B8EC8 1400B18F */  lw         $s1, 0x14($sp)
    /* 506CC 800B8ECC 1000B08F */  lw         $s0, 0x10($sp)
    /* 506D0 800B8ED0 21100000 */  addu       $v0, $zero, $zero
    /* 506D4 800B8ED4 0800E003 */  jr         $ra
    /* 506D8 800B8ED8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_battle_script_setFlagImm
