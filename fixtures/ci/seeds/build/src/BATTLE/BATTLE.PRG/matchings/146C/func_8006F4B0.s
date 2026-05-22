nonmatching func_8006F4B0, 0x8C

glabel func_8006F4B0
    /* 6CB0 8006F4B0 00FFBD27 */  addiu      $sp, $sp, -0x100
    /* 6CB4 8006F4B4 21000224 */  addiu      $v0, $zero, 0x21
    /* 6CB8 8006F4B8 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 6CBC 8006F4BC 01000224 */  addiu      $v0, $zero, 0x1
    /* 6CC0 8006F4C0 1200A2A3 */  sb         $v0, 0x12($sp)
    /* 6CC4 8006F4C4 04000224 */  addiu      $v0, $zero, 0x4
    /* 6CC8 8006F4C8 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 6CCC 8006F4CC 05000224 */  addiu      $v0, $zero, 0x5
    /* 6CD0 8006F4D0 F800BFAF */  sw         $ra, 0xF8($sp)
    /* 6CD4 8006F4D4 1300A0A3 */  sb         $zero, 0x13($sp)
    /* 6CD8 8006F4D8 1800A0A3 */  sb         $zero, 0x18($sp)
    /* 6CDC 8006F4DC 2000A2A7 */  sh         $v0, 0x20($sp)
    /* 6CE0 8006F4E0 00008290 */  lbu        $v0, 0x0($a0)
    /* 6CE4 8006F4E4 00000000 */  nop
    /* 6CE8 8006F4E8 C0110200 */  sll        $v0, $v0, 7
    /* 6CEC 8006F4EC 40004224 */  addiu      $v0, $v0, 0x40
    /* 6CF0 8006F4F0 2400A2A7 */  sh         $v0, 0x24($sp)
    /* 6CF4 8006F4F4 02008290 */  lbu        $v0, 0x2($a0)
    /* 6CF8 8006F4F8 00000000 */  nop
    /* 6CFC 8006F4FC C0110200 */  sll        $v0, $v0, 7
    /* 6D00 8006F500 40004224 */  addiu      $v0, $v0, 0x40
    /* 6D04 8006F504 2800A2A7 */  sh         $v0, 0x28($sp)
    /* 6D08 8006F508 0F80023C */  lui        $v0, %hi(D_800F1868)
    /* 6D0C 8006F50C 6818428C */  lw         $v0, %lo(D_800F1868)($v0)
    /* 6D10 8006F510 06008394 */  lhu        $v1, 0x6($a0)
    /* 6D14 8006F514 02004230 */  andi       $v0, $v0, 0x2
    /* 6D18 8006F518 04004014 */  bnez       $v0, .L8006F52C
    /* 6D1C 8006F51C 2600A3A7 */   sh        $v1, 0x26($sp)
    /* 6D20 8006F520 1000A427 */  addiu      $a0, $sp, 0x10
    /* 6D24 8006F524 FE3C030C */  jal        func_800CF3F8
    /* 6D28 8006F528 21280000 */   addu      $a1, $zero, $zero
  .L8006F52C:
    /* 6D2C 8006F52C F800BF8F */  lw         $ra, 0xF8($sp)
    /* 6D30 8006F530 00000000 */  nop
    /* 6D34 8006F534 0800E003 */  jr         $ra
    /* 6D38 8006F538 0001BD27 */   addiu     $sp, $sp, 0x100
endlabel func_8006F4B0
