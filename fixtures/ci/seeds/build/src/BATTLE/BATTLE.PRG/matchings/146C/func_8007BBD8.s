nonmatching func_8007BBD8, 0xF4

glabel func_8007BBD8
    /* 133D8 8007BBD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 133DC 8007BBDC 0580023C */  lui        $v0, %hi(D_80050468)
    /* 133E0 8007BBE0 68044724 */  addiu      $a3, $v0, %lo(D_80050468)
    /* 133E4 8007BBE4 680444A0 */  sb         $a0, %lo(D_80050468)($v0)
    /* 133E8 8007BBE8 01000224 */  addiu      $v0, $zero, 0x1
    /* 133EC 8007BBEC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 133F0 8007BBF0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 133F4 8007BBF4 0200E5A4 */  sh         $a1, 0x2($a3)
    /* 133F8 8007BBF8 0700E0A0 */  sb         $zero, 0x7($a3)
    /* 133FC 8007BBFC 0600E0A0 */  sb         $zero, 0x6($a3)
    /* 13400 8007BC00 0500E0A0 */  sb         $zero, 0x5($a3)
    /* 13404 8007BC04 1D008210 */  beq        $a0, $v0, .L8007BC7C
    /* 13408 8007BC08 0400E0A0 */   sb        $zero, 0x4($a3)
    /* 1340C 8007BC0C 0200C104 */  bgez       $a2, .L8007BC18
    /* 13410 8007BC10 2110C000 */   addu      $v0, $a2, $zero
    /* 13414 8007BC14 FF00C224 */  addiu      $v0, $a2, 0xFF
  .L8007BC18:
    /* 13418 8007BC18 031A0200 */  sra        $v1, $v0, 8
    /* 1341C 8007BC1C 00120300 */  sll        $v0, $v1, 8
    /* 13420 8007BC20 2310C200 */  subu       $v0, $a2, $v0
    /* 13424 8007BC24 0400E2A0 */  sb         $v0, 0x4($a3)
    /* 13428 8007BC28 02006104 */  bgez       $v1, .L8007BC34
    /* 1342C 8007BC2C 21106000 */   addu      $v0, $v1, $zero
    /* 13430 8007BC30 FF006224 */  addiu      $v0, $v1, 0xFF
  .L8007BC34:
    /* 13434 8007BC34 03220200 */  sra        $a0, $v0, 8
    /* 13438 8007BC38 00120400 */  sll        $v0, $a0, 8
    /* 1343C 8007BC3C 23106200 */  subu       $v0, $v1, $v0
    /* 13440 8007BC40 0500E2A0 */  sb         $v0, 0x5($a3)
    /* 13444 8007BC44 02008104 */  bgez       $a0, .L8007BC50
    /* 13448 8007BC48 21108000 */   addu      $v0, $a0, $zero
    /* 1344C 8007BC4C FF008224 */  addiu      $v0, $a0, 0xFF
  .L8007BC50:
    /* 13450 8007BC50 031A0200 */  sra        $v1, $v0, 8
    /* 13454 8007BC54 00120300 */  sll        $v0, $v1, 8
    /* 13458 8007BC58 23108200 */  subu       $v0, $a0, $v0
    /* 1345C 8007BC5C 0600E2A0 */  sb         $v0, 0x6($a3)
    /* 13460 8007BC60 02006104 */  bgez       $v1, .L8007BC6C
    /* 13464 8007BC64 21106000 */   addu      $v0, $v1, $zero
    /* 13468 8007BC68 FF006224 */  addiu      $v0, $v1, 0xFF
  .L8007BC6C:
    /* 1346C 8007BC6C 03120200 */  sra        $v0, $v0, 8
    /* 13470 8007BC70 00120200 */  sll        $v0, $v0, 8
    /* 13474 8007BC74 23106200 */  subu       $v0, $v1, $v0
    /* 13478 8007BC78 0700E2A0 */  sb         $v0, 0x7($a3)
  .L8007BC7C:
    /* 1347C 8007BC7C 0580103C */  lui        $s0, %hi(D_80050468)
    /* 13480 8007BC80 68041026 */  addiu      $s0, $s0, %lo(D_80050468)
    /* 13484 8007BC84 04000592 */  lbu        $a1, 0x4($s0)
    /* 13488 8007BC88 05FB020C */  jal        vs_battle_setStateFlag
    /* 1348C 8007BC8C A0000424 */   addiu     $a0, $zero, 0xA0
    /* 13490 8007BC90 05000592 */  lbu        $a1, 0x5($s0)
    /* 13494 8007BC94 05FB020C */  jal        vs_battle_setStateFlag
    /* 13498 8007BC98 A1000424 */   addiu     $a0, $zero, 0xA1
    /* 1349C 8007BC9C 06000592 */  lbu        $a1, 0x6($s0)
    /* 134A0 8007BCA0 05FB020C */  jal        vs_battle_setStateFlag
    /* 134A4 8007BCA4 A2000424 */   addiu     $a0, $zero, 0xA2
    /* 134A8 8007BCA8 07000592 */  lbu        $a1, 0x7($s0)
    /* 134AC 8007BCAC 05FB020C */  jal        vs_battle_setStateFlag
    /* 134B0 8007BCB0 A3000424 */   addiu     $a0, $zero, 0xA3
    /* 134B4 8007BCB4 542D030C */  jal        func_800CB550
    /* 134B8 8007BCB8 00000000 */   nop
    /* 134BC 8007BCBC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 134C0 8007BCC0 1000B08F */  lw         $s0, 0x10($sp)
    /* 134C4 8007BCC4 0800E003 */  jr         $ra
    /* 134C8 8007BCC8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BBD8
