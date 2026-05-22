nonmatching func_8008EFCC, 0x130

glabel func_8008EFCC
    /* 267CC 8008EFCC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 267D0 8008EFD0 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0xA0)
    /* 267D4 8008EFD4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 267D8 8008EFD8 981C508C */  lw         $s0, %lo(vs_battle_roomData + 0xA0)($v0)
    /* 267DC 8008EFDC 0F80033C */  lui        $v1, %hi(D_800F1DC8)
    /* 267E0 8008EFE0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 267E4 8008EFE4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 267E8 8008EFE8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 267EC 8008EFEC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 267F0 8008EFF0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 267F4 8008EFF4 34000012 */  beqz       $s0, .L8008F0C8
    /* 267F8 8008EFF8 C81D64A0 */   sb        $a0, %lo(D_800F1DC8)($v1)
    /* 267FC 8008EFFC FF008430 */  andi       $a0, $a0, 0xFF
    /* 26800 8008F000 0F80033C */  lui        $v1, %hi(D_800F1DBE)
    /* 26804 8008F004 00000296 */  lhu        $v0, 0x0($s0)
    /* 26808 8008F008 05000624 */  addiu      $a2, $zero, 0x5
    /* 2680C 8008F00C 002C0200 */  sll        $a1, $v0, 16
    /* 26810 8008F010 032C0500 */  sra        $a1, $a1, 16
    /* 26814 8008F014 FCF7010C */  jal        func_8007DFF0
    /* 26818 8008F018 BE1D62A4 */   sh        $v0, %lo(D_800F1DBE)($v1)
    /* 2681C 8008F01C 2A004010 */  beqz       $v0, .L8008F0C8
    /* 26820 8008F020 40001226 */   addiu     $s2, $s0, 0x40
    /* 26824 8008F024 84001326 */  addiu      $s3, $s0, 0x84
    /* 26828 8008F028 0400448E */  lw         $a0, 0x4($s2)
    /* 2682C 8008F02C 0400708E */  lw         $s0, 0x4($s3)
    /* 26830 8008F030 FF078330 */  andi       $v1, $a0, 0x7FF
    /* 26834 8008F034 02006010 */  beqz       $v1, .L8008F040
    /* 26838 8008F038 00088224 */   addiu     $v0, $a0, 0x800
    /* 2683C 8008F03C 23204300 */  subu       $a0, $v0, $v1
  .L8008F040:
    /* 26840 8008F040 FF070332 */  andi       $v1, $s0, 0x7FF
    /* 26844 8008F044 02006010 */  beqz       $v1, .L8008F050
    /* 26848 8008F048 00080226 */   addiu     $v0, $s0, 0x800
    /* 2684C 8008F04C 23804300 */  subu       $s0, $v0, $v1
  .L8008F050:
    /* 26850 8008F050 8F0F010C */  jal        vs_main_allocHeapR
    /* 26854 8008F054 0F80113C */   lui       $s1, %hi(D_800F1DD0)
    /* 26858 8008F058 21200002 */  addu       $a0, $s0, $zero
    /* 2685C 8008F05C 8F0F010C */  jal        vs_main_allocHeapR
    /* 26860 8008F060 D01D22AE */   sw        $v0, %lo(D_800F1DD0)($s1)
    /* 26864 8008F064 D01D238E */  lw         $v1, %lo(D_800F1DD0)($s1)
    /* 26868 8008F068 0F80143C */  lui        $s4, %hi(D_800F1DCC)
    /* 2686C 8008F06C 03006010 */  beqz       $v1, .L8008F07C
    /* 26870 8008F070 CC1D82AE */   sw        $v0, %lo(D_800F1DCC)($s4)
    /* 26874 8008F074 03004014 */  bnez       $v0, .L8008F084
    /* 26878 8008F078 00000000 */   nop
  .L8008F07C:
    /* 2687C 8008F07C 373C0208 */  j          .L8008F0DC
    /* 26880 8008F080 21100000 */   addu      $v0, $zero, $zero
  .L8008F084:
    /* 26884 8008F084 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 26888 8008F088 21204002 */   addu      $a0, $s2, $zero
    /* 2688C 8008F08C 21206002 */  addu       $a0, $s3, $zero
    /* 26890 8008F090 0F80103C */  lui        $s0, %hi(D_800F1DAC)
    /* 26894 8008F094 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 26898 8008F098 AC1D02AE */   sw        $v0, %lo(D_800F1DAC)($s0)
    /* 2689C 8008F09C AC1D048E */  lw         $a0, %lo(D_800F1DAC)($s0)
    /* 268A0 8008F0A0 D01D258E */  lw         $a1, %lo(D_800F1DD0)($s1)
    /* 268A4 8008F0A4 0F80103C */  lui        $s0, %hi(D_800F1DB0)
    /* 268A8 8008F0A8 F112010C */  jal        vs_main_cdEnqueue
    /* 268AC 8008F0AC B01D02AE */   sw        $v0, %lo(D_800F1DB0)($s0)
    /* 268B0 8008F0B0 B01D048E */  lw         $a0, %lo(D_800F1DB0)($s0)
    /* 268B4 8008F0B4 CC1D858E */  lw         $a1, %lo(D_800F1DCC)($s4)
    /* 268B8 8008F0B8 F112010C */  jal        vs_main_cdEnqueue
    /* 268BC 8008F0BC 00000000 */   nop
    /* 268C0 8008F0C0 373C0208 */  j          .L8008F0DC
    /* 268C4 8008F0C4 01000224 */   addiu     $v0, $zero, 0x1
  .L8008F0C8:
    /* 268C8 8008F0C8 21100000 */  addu       $v0, $zero, $zero
    /* 268CC 8008F0CC 0F80033C */  lui        $v1, %hi(D_800F1DAC)
    /* 268D0 8008F0D0 AC1D60AC */  sw         $zero, %lo(D_800F1DAC)($v1)
    /* 268D4 8008F0D4 0F80033C */  lui        $v1, %hi(D_800F1DB0)
    /* 268D8 8008F0D8 B01D60AC */  sw         $zero, %lo(D_800F1DB0)($v1)
  .L8008F0DC:
    /* 268DC 8008F0DC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 268E0 8008F0E0 2000B48F */  lw         $s4, 0x20($sp)
    /* 268E4 8008F0E4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 268E8 8008F0E8 1800B28F */  lw         $s2, 0x18($sp)
    /* 268EC 8008F0EC 1400B18F */  lw         $s1, 0x14($sp)
    /* 268F0 8008F0F0 1000B08F */  lw         $s0, 0x10($sp)
    /* 268F4 8008F0F4 0800E003 */  jr         $ra
    /* 268F8 8008F0F8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8008EFCC
