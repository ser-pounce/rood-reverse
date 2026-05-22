nonmatching func_800CCA90, 0x10C

glabel func_800CCA90
    /* 64290 800CCA90 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 64294 800CCA94 21308000 */  addu       $a2, $a0, $zero
    /* 64298 800CCA98 0F80033C */  lui        $v1, %hi(D_800EB9BC)
    /* 6429C 800CCA9C C0110600 */  sll        $v0, $a2, 7
    /* 642A0 800CCAA0 23104600 */  subu       $v0, $v0, $a2
    /* 642A4 800CCAA4 BCB9638C */  lw         $v1, %lo(D_800EB9BC)($v1)
    /* 642A8 800CCAA8 C0100200 */  sll        $v0, $v0, 3
    /* 642AC 800CCAAC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 642B0 800CCAB0 21206200 */  addu       $a0, $v1, $v0
    /* 642B4 800CCAB4 02008290 */  lbu        $v0, 0x2($a0)
    /* 642B8 800CCAB8 03008390 */  lbu        $v1, 0x3($a0)
    /* 642BC 800CCABC F0FF4224 */  addiu      $v0, $v0, -0x10
    /* 642C0 800CCAC0 07006014 */  bnez       $v1, .L800CCAE0
    /* 642C4 800CCAC4 80290200 */   sll       $a1, $v0, 6
    /* 642C8 800CCAC8 0000828C */  lw         $v0, 0x0($a0)
    /* 642CC 800CCACC 02000324 */  addiu      $v1, $zero, 0x2
    /* 642D0 800CCAD0 C2100200 */  srl        $v0, $v0, 3
    /* 642D4 800CCAD4 07004230 */  andi       $v0, $v0, 0x7
    /* 642D8 800CCAD8 2C004314 */  bne        $v0, $v1, .L800CCB8C
    /* 642DC 800CCADC 00000000 */   nop
  .L800CCAE0:
    /* 642E0 800CCAE0 0000838C */  lw         $v1, 0x0($a0)
    /* 642E4 800CCAE4 00000000 */  nop
    /* 642E8 800CCAE8 82100300 */  srl        $v0, $v1, 2
    /* 642EC 800CCAEC 01004230 */  andi       $v0, $v0, 0x1
    /* 642F0 800CCAF0 06004010 */  beqz       $v0, .L800CCB0C
    /* 642F4 800CCAF4 02130300 */   srl       $v0, $v1, 12
    /* 642F8 800CCAF8 01004230 */  andi       $v0, $v0, 0x1
    /* 642FC 800CCAFC 06004014 */  bnez       $v0, .L800CCB18
    /* 64300 800CCB00 03110500 */   sra       $v0, $a1, 4
    /* 64304 800CCB04 C8320308 */  j          .L800CCB20
    /* 64308 800CCB08 F0380524 */   addiu     $a1, $zero, 0x38F0
  .L800CCB0C:
    /* 6430C 800CCB0C 00110600 */  sll        $v0, $a2, 4
    /* 64310 800CCB10 2110A200 */  addu       $v0, $a1, $v0
    /* 64314 800CCB14 03110200 */  sra        $v0, $v0, 4
  .L800CCB18:
    /* 64318 800CCB18 3F004230 */  andi       $v0, $v0, 0x3F
    /* 6431C 800CCB1C C07F4534 */  ori        $a1, $v0, 0x7FC0
  .L800CCB20:
    /* 64320 800CCB20 0F80023C */  lui        $v0, %hi(D_800F51C8)
    /* 64324 800CCB24 0F80033C */  lui        $v1, %hi(D_800EC25C)
    /* 64328 800CCB28 C85140A0 */  sb         $zero, %lo(D_800F51C8)($v0)
    /* 6432C 800CCB2C 0000828C */  lw         $v0, 0x0($a0)
    /* 64330 800CCB30 5CC26324 */  addiu      $v1, $v1, %lo(D_800EC25C)
    /* 64334 800CCB34 42100200 */  srl        $v0, $v0, 1
    /* 64338 800CCB38 1C004230 */  andi       $v0, $v0, 0x1C
    /* 6433C 800CCB3C 21384300 */  addu       $a3, $v0, $v1
    /* 64340 800CCB40 0C008294 */  lhu        $v0, 0xC($a0)
    /* 64344 800CCB44 00000000 */  nop
    /* 64348 800CCB48 00404230 */  andi       $v0, $v0, 0x4000
    /* 6434C 800CCB4C 06004010 */  beqz       $v0, .L800CCB68
    /* 64350 800CCB50 002C0500 */   sll       $a1, $a1, 16
    /* 64354 800CCB54 801F023C */  lui        $v0, (0x1F800004 >> 16)
    /* 64358 800CCB58 80180600 */  sll        $v1, $a2, 2
    /* 6435C 800CCB5C 0400428C */  lw         $v0, (0x1F800004 & 0xFFFF)($v0)
    /* 64360 800CCB60 DE320308 */  j          .L800CCB78
    /* 64364 800CCB64 08E06324 */   addiu     $v1, $v1, -0x1FF8
  .L800CCB68:
    /* 64368 800CCB68 801F023C */  lui        $v0, (0x1F800008 >> 16)
    /* 6436C 800CCB6C C0180600 */  sll        $v1, $a2, 3
    /* 64370 800CCB70 0800428C */  lw         $v0, (0x1F800008 & 0xFFFF)($v0)
    /* 64374 800CCB74 E8FF6324 */  addiu      $v1, $v1, -0x18
  .L800CCB78:
    /* 64378 800CCB78 23304300 */  subu       $a2, $v0, $v1
    /* 6437C 800CCB7C 0000E28C */  lw         $v0, 0x0($a3)
    /* 64380 800CCB80 00000000 */  nop
    /* 64384 800CCB84 09F84000 */  jalr       $v0
    /* 64388 800CCB88 00000000 */   nop
  .L800CCB8C:
    /* 6438C 800CCB8C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 64390 800CCB90 00000000 */  nop
    /* 64394 800CCB94 0800E003 */  jr         $ra
    /* 64398 800CCB98 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CCA90
