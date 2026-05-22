nonmatching _setTitleExitFlags, 0xBC

glabel _setTitleExitFlags
    /* 94E0 80071CE0 01000524 */  addiu      $a1, $zero, 0x1
    /* 94E4 80071CE4 28008510 */  beq        $a0, $a1, .L80071D88
    /* 94E8 80071CE8 02008228 */   slti      $v0, $a0, 0x2
    /* 94EC 80071CEC 05004010 */  beqz       $v0, .L80071D04
    /* 94F0 80071CF0 03000224 */   addiu     $v0, $zero, 0x3
    /* 94F4 80071CF4 09008010 */  beqz       $a0, .L80071D1C
    /* 94F8 80071CF8 0680023C */   lui       $v0, %hi(vs_main_stateFlags)
    /* 94FC 80071CFC 64C70108 */  j          .L80071D90
    /* 9500 80071D00 98154224 */   addiu     $v0, $v0, %lo(vs_main_stateFlags)
  .L80071D04:
    /* 9504 80071D04 0D008210 */  beq        $a0, $v0, .L80071D3C
    /* 9508 80071D08 04000224 */   addiu     $v0, $zero, 0x4
    /* 950C 80071D0C 14008210 */  beq        $a0, $v0, .L80071D60
    /* 9510 80071D10 0680023C */   lui       $v0, %hi(vs_main_stateFlags)
    /* 9514 80071D14 64C70108 */  j          .L80071D90
    /* 9518 80071D18 98154224 */   addiu     $v0, $v0, %lo(vs_main_stateFlags)
  .L80071D1C:
    /* 951C 80071D1C 98154224 */  addiu      $v0, $v0, %lo(vs_main_stateFlags)
    /* 9520 80071D20 0C0040A0 */  sb         $zero, 0xC($v0)
    /* 9524 80071D24 0D0040A0 */  sb         $zero, 0xD($v0)
    /* 9528 80071D28 0680023C */  lui        $v0, %hi(D_80061068)
    /* 952C 80071D2C 681045A0 */  sb         $a1, %lo(D_80061068)($v0)
  .L80071D30:
    /* 9530 80071D30 68104224 */  addiu      $v0, $v0, %lo(D_80061068)
    /* 9534 80071D34 0800E003 */  jr         $ra
    /* 9538 80071D38 010040A0 */   sb        $zero, 0x1($v0)
  .L80071D3C:
    /* 953C 80071D3C 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 9540 80071D40 98154224 */  addiu      $v0, $v0, %lo(vs_main_stateFlags)
    /* 9544 80071D44 0C0040A0 */  sb         $zero, 0xC($v0)
    /* 9548 80071D48 0D0045A0 */  sb         $a1, 0xD($v0)
    /* 954C 80071D4C 0E0045A0 */  sb         $a1, 0xE($v0)
    /* 9550 80071D50 0680023C */  lui        $v0, %hi(D_80061068)
    /* 9554 80071D54 14000324 */  addiu      $v1, $zero, 0x14
    /* 9558 80071D58 4CC70108 */  j          .L80071D30
    /* 955C 80071D5C 681043A0 */   sb        $v1, %lo(D_80061068)($v0)
  .L80071D60:
    /* 9560 80071D60 98154224 */  addiu      $v0, $v0, %lo(vs_main_stateFlags)
    /* 9564 80071D64 0C0040A0 */  sb         $zero, 0xC($v0)
    /* 9568 80071D68 0D0045A0 */  sb         $a1, 0xD($v0)
    /* 956C 80071D6C 0E0045A0 */  sb         $a1, 0xE($v0)
    /* 9570 80071D70 0680023C */  lui        $v0, %hi(D_80061068)
    /* 9574 80071D74 02000324 */  addiu      $v1, $zero, 0x2
    /* 9578 80071D78 681043A0 */  sb         $v1, %lo(D_80061068)($v0)
    /* 957C 80071D7C 68104224 */  addiu      $v0, $v0, %lo(D_80061068)
    /* 9580 80071D80 0800E003 */  jr         $ra
    /* 9584 80071D84 010045A0 */   sb        $a1, 0x1($v0)
  .L80071D88:
    /* 9588 80071D88 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 958C 80071D8C 98154224 */  addiu      $v0, $v0, %lo(vs_main_stateFlags)
  .L80071D90:
    /* 9590 80071D90 0C0040A0 */  sb         $zero, 0xC($v0)
    /* 9594 80071D94 0800E003 */  jr         $ra
    /* 9598 80071D98 0D0040A0 */   sb        $zero, 0xD($v0)
endlabel _setTitleExitFlags
