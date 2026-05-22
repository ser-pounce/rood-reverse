nonmatching func_800D4FB4, 0x94

glabel func_800D4FB4
    /* 6C7B4 800D4FB4 21408000 */  addu       $t0, $a0, $zero
    /* 6C7B8 800D4FB8 21280000 */  addu       $a1, $zero, $zero
    /* 6C7BC 800D4FBC 0F80093C */  lui        $t1, %hi(D_800F569C)
    /* 6C7C0 800D4FC0 0F80023C */  lui        $v0, %hi(D_800EC330)
    /* 6C7C4 800D4FC4 30C34724 */  addiu      $a3, $v0, %lo(D_800EC330)
    /* 6C7C8 800D4FC8 04000624 */  addiu      $a2, $zero, 0x4
  .L800D4FCC:
    /* 6C7CC 800D4FCC 80200500 */  sll        $a0, $a1, 2
    /* 6C7D0 800D4FD0 360D0295 */  lhu        $v0, 0xD36($t0)
    /* 6C7D4 800D4FD4 9C56238D */  lw         $v1, %lo(D_800F569C)($t1)
    /* 6C7D8 800D4FD8 C0100200 */  sll        $v0, $v0, 3
    /* 6C7DC 800D4FDC 21108200 */  addu       $v0, $a0, $v0
    /* 6C7E0 800D4FE0 21104700 */  addu       $v0, $v0, $a3
    /* 6C7E4 800D4FE4 0800638C */  lw         $v1, 0x8($v1)
    /* 6C7E8 800D4FE8 00004290 */  lbu        $v0, 0x0($v0)
    /* 6C7EC 800D4FEC 21186600 */  addu       $v1, $v1, $a2
    /* 6C7F0 800D4FF0 C40062A0 */  sb         $v0, 0xC4($v1)
    /* 6C7F4 800D4FF4 360D0295 */  lhu        $v0, 0xD36($t0)
    /* 6C7F8 800D4FF8 00000000 */  nop
    /* 6C7FC 800D4FFC C0100200 */  sll        $v0, $v0, 3
    /* 6C800 800D5000 21108200 */  addu       $v0, $a0, $v0
    /* 6C804 800D5004 21104700 */  addu       $v0, $v0, $a3
    /* 6C808 800D5008 01004290 */  lbu        $v0, 0x1($v0)
    /* 6C80C 800D500C 00000000 */  nop
    /* 6C810 800D5010 C50062A0 */  sb         $v0, 0xC5($v1)
    /* 6C814 800D5014 360D0295 */  lhu        $v0, 0xD36($t0)
    /* 6C818 800D5018 0100A524 */  addiu      $a1, $a1, 0x1
    /* 6C81C 800D501C C0100200 */  sll        $v0, $v0, 3
    /* 6C820 800D5020 21208200 */  addu       $a0, $a0, $v0
    /* 6C824 800D5024 21208700 */  addu       $a0, $a0, $a3
    /* 6C828 800D5028 02008290 */  lbu        $v0, 0x2($a0)
    /* 6C82C 800D502C 00000000 */  nop
    /* 6C830 800D5030 C60062A0 */  sb         $v0, 0xC6($v1)
    /* 6C834 800D5034 0200A228 */  slti       $v0, $a1, 0x2
    /* 6C838 800D5038 E4FF4014 */  bnez       $v0, .L800D4FCC
    /* 6C83C 800D503C CC00C624 */   addiu     $a2, $a2, 0xCC
    /* 6C840 800D5040 0800E003 */  jr         $ra
    /* 6C844 800D5044 01000224 */   addiu     $v0, $zero, 0x1
endlabel func_800D4FB4
