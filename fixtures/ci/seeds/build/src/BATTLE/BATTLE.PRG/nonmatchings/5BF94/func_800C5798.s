nonmatching func_800C5798, 0x10C

glabel func_800C5798
    /* 5CF98 800C5798 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 5CF9C 800C579C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5CFA0 800C57A0 2188A000 */  addu       $s1, $a1, $zero
    /* 5CFA4 800C57A4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5CFA8 800C57A8 2180C000 */  addu       $s0, $a2, $zero
    /* 5CFAC 800C57AC 0F80033C */  lui        $v1, %hi(D_800EB9B8)
    /* 5CFB0 800C57B0 80100400 */  sll        $v0, $a0, 2
    /* 5CFB4 800C57B4 21104400 */  addu       $v0, $v0, $a0
    /* 5CFB8 800C57B8 80100200 */  sll        $v0, $v0, 2
    /* 5CFBC 800C57BC 90094224 */  addiu      $v0, $v0, 0x990
    /* 5CFC0 800C57C0 B8B9638C */  lw         $v1, %lo(D_800EB9B8)($v1)
    /* 5CFC4 800C57C4 14000524 */  addiu      $a1, $zero, 0x14
    /* 5CFC8 800C57C8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 5CFCC 800C57CC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5CFD0 800C57D0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5CFD4 800C57D4 21906200 */  addu       $s2, $v1, $v0
    /* 5CFD8 800C57D8 40100400 */  sll        $v0, $a0, 1
    /* 5CFDC 800C57DC 21104400 */  addu       $v0, $v0, $a0
    /* 5CFE0 800C57E0 C0100200 */  sll        $v0, $v0, 3
    /* 5CFE4 800C57E4 4000638C */  lw         $v1, 0x40($v1)
    /* 5CFE8 800C57E8 21204002 */  addu       $a0, $s2, $zero
    /* 5CFEC 800C57EC 0733030C */  jal        vs_battle_rMemzero
    /* 5CFF0 800C57F0 21986200 */   addu      $s3, $v1, $v0
    /* 5CFF4 800C57F4 40101000 */  sll        $v0, $s0, 1
    /* 5CFF8 800C57F8 21105000 */  addu       $v0, $v0, $s0
    /* 5CFFC 800C57FC 80100200 */  sll        $v0, $v0, 2
    /* 5D000 800C5800 23105000 */  subu       $v0, $v0, $s0
    /* 5D004 800C5804 20004224 */  addiu      $v0, $v0, 0x20
    /* 5D008 800C5808 000051A2 */  sb         $s1, 0x0($s2)
    /* 5D00C 800C580C 060042A2 */  sb         $v0, 0x6($s2)
    /* 5D010 800C5810 0000628E */  lw         $v0, 0x0($s3)
    /* 5D014 800C5814 0400638E */  lw         $v1, 0x4($s3)
    /* 5D018 800C5818 080042AE */  sw         $v0, 0x8($s2)
    /* 5D01C 800C581C 02000224 */  addiu      $v0, $zero, 0x2
    /* 5D020 800C5820 0D002216 */  bne        $s1, $v0, .L800C5858
    /* 5D024 800C5824 0C0043AE */   sw        $v1, 0xC($s2)
    /* 5D028 800C5828 40010224 */  addiu      $v0, $zero, 0x140
    /* 5D02C 800C582C 0F80033C */  lui        $v1, %hi(vs_battle_hitlocations)
    /* 5D030 800C5830 040042A6 */  sh         $v0, 0x4($s2)
    /* 5D034 800C5834 08006292 */  lbu        $v0, 0x8($s3)
    /* 5D038 800C5838 20A66324 */  addiu      $v1, $v1, %lo(vs_battle_hitlocations)
    /* 5D03C 800C583C 80100200 */  sll        $v0, $v0, 2
    /* 5D040 800C5840 21104300 */  addu       $v0, $v0, $v1
    /* 5D044 800C5844 0000428C */  lw         $v0, 0x0($v0)
    /* 5D048 800C5848 00000000 */  nop
    /* 5D04C 800C584C 01004224 */  addiu      $v0, $v0, 0x1
    /* 5D050 800C5850 21160308 */  j          .L800C5884
    /* 5D054 800C5854 100042AE */   sw        $v0, 0x10($s2)
  .L800C5858:
    /* 5D058 800C5858 B8FF0224 */  addiu      $v0, $zero, -0x48
    /* 5D05C 800C585C 0F80033C */  lui        $v1, %hi(vs_battle_hitlocations)
    /* 5D060 800C5860 040042A6 */  sh         $v0, 0x4($s2)
    /* 5D064 800C5864 08006292 */  lbu        $v0, 0x8($s3)
    /* 5D068 800C5868 20A66324 */  addiu      $v1, $v1, %lo(vs_battle_hitlocations)
    /* 5D06C 800C586C 80100200 */  sll        $v0, $v0, 2
    /* 5D070 800C5870 21104300 */  addu       $v0, $v0, $v1
    /* 5D074 800C5874 0000438C */  lw         $v1, 0x0($v0)
    /* 5D078 800C5878 01000224 */  addiu      $v0, $zero, 0x1
    /* 5D07C 800C587C 070042A2 */  sb         $v0, 0x7($s2)
    /* 5D080 800C5880 100043AE */  sw         $v1, 0x10($s2)
  .L800C5884:
    /* 5D084 800C5884 21104002 */  addu       $v0, $s2, $zero
    /* 5D088 800C5888 2000BF8F */  lw         $ra, 0x20($sp)
    /* 5D08C 800C588C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5D090 800C5890 1800B28F */  lw         $s2, 0x18($sp)
    /* 5D094 800C5894 1400B18F */  lw         $s1, 0x14($sp)
    /* 5D098 800C5898 1000B08F */  lw         $s0, 0x10($sp)
    /* 5D09C 800C589C 0800E003 */  jr         $ra
    /* 5D0A0 800C58A0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800C5798
