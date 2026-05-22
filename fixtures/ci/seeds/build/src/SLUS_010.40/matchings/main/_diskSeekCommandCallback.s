nonmatching _diskSeekCommandCallback, 0x60

glabel _diskSeekCommandCallback
    /* 349C4 800441C4 FF008430 */  andi       $a0, $a0, 0xFF
    /* 349C8 800441C8 02000224 */  addiu      $v0, $zero, 0x2
    /* 349CC 800441CC 0D008210 */  beq        $a0, $v0, .L80044204
    /* 349D0 800441D0 03008228 */   slti      $v0, $a0, 0x3
    /* 349D4 800441D4 05004010 */  beqz       $v0, .L800441EC
    /* 349D8 800441D8 05000224 */   addiu     $v0, $zero, 0x5
    /* 349DC 800441DC 0F008010 */  beqz       $a0, .L8004421C
    /* 349E0 800441E0 0580033C */   lui       $v1, %hi(vs_main_disk)
    /* 349E4 800441E4 86100108 */  j          .L80044218
    /* 349E8 800441E8 04000224 */   addiu     $v0, $zero, 0x4
  .L800441EC:
    /* 349EC 800441EC 08008210 */  beq        $a0, $v0, .L80044210
    /* 349F0 800441F0 06000224 */   addiu     $v0, $zero, 0x6
    /* 349F4 800441F4 09008210 */  beq        $a0, $v0, .L8004421C
    /* 349F8 800441F8 0580033C */   lui       $v1, %hi(vs_main_disk)
    /* 349FC 800441FC 86100108 */  j          .L80044218
    /* 34A00 80044200 04000224 */   addiu     $v0, $zero, 0x4
  .L80044204:
    /* 34A04 80044204 0580023C */  lui        $v0, %hi(vs_main_disk)
    /* 34A08 80044208 0800E003 */  jr         $ra
    /* 34A0C 8004420C 105D40A0 */   sb        $zero, %lo(vs_main_disk)($v0)
  .L80044210:
    /* 34A10 80044210 0580033C */  lui        $v1, %hi(vs_main_disk)
    /* 34A14 80044214 04000224 */  addiu      $v0, $zero, 0x4
  .L80044218:
    /* 34A18 80044218 105D62A0 */  sb         $v0, %lo(vs_main_disk)($v1)
  .L8004421C:
    /* 34A1C 8004421C 0800E003 */  jr         $ra
    /* 34A20 80044220 00000000 */   nop
endlabel _diskSeekCommandCallback
