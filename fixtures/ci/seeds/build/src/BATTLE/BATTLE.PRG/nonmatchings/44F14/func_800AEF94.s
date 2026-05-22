nonmatching func_800AEF94, 0x754

glabel func_800AEF94
    /* 46794 800AEF94 A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* 46798 800AEF98 5400B5AF */  sw         $s5, 0x54($sp)
    /* 4679C 800AEF9C 21A88000 */  addu       $s5, $a0, $zero
    /* 467A0 800AEFA0 5800BFAF */  sw         $ra, 0x58($sp)
    /* 467A4 800AEFA4 5000B4AF */  sw         $s4, 0x50($sp)
    /* 467A8 800AEFA8 4C00B3AF */  sw         $s3, 0x4C($sp)
    /* 467AC 800AEFAC 4800B2AF */  sw         $s2, 0x48($sp)
    /* 467B0 800AEFB0 4400B1AF */  sw         $s1, 0x44($sp)
    /* 467B4 800AEFB4 28BB020C */  jal        func_800AECA0
    /* 467B8 800AEFB8 4000B0AF */   sw        $s0, 0x40($sp)
    /* 467BC 800AEFBC 21900000 */  addu       $s2, $zero, $zero
    /* 467C0 800AEFC0 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 467C4 800AEFC4 38455424 */  addiu      $s4, $v0, %lo(D_800F4538)
    /* 467C8 800AEFC8 80101200 */  sll        $v0, $s2, 2
  .L800AEFCC:
    /* 467CC 800AEFCC 21105400 */  addu       $v0, $v0, $s4
    /* 467D0 800AEFD0 0000508C */  lw         $s0, 0x0($v0)
    /* 467D4 800AEFD4 00000000 */  nop
    /* 467D8 800AEFD8 39010012 */  beqz       $s0, .L800AF4C0
    /* 467DC 800AEFDC 00000000 */   nop
    /* 467E0 800AEFE0 00000292 */  lbu        $v0, 0x0($s0)
    /* 467E4 800AEFE4 00000000 */  nop
    /* 467E8 800AEFE8 35014010 */  beqz       $v0, .L800AF4C0
    /* 467EC 800AEFEC 00000000 */   nop
    /* 467F0 800AEFF0 0800028E */  lw         $v0, 0x8($s0)
    /* 467F4 800AEFF4 00000000 */  nop
    /* 467F8 800AEFF8 01004230 */  andi       $v0, $v0, 0x1
    /* 467FC 800AEFFC 30014014 */  bnez       $v0, .L800AF4C0
    /* 46800 800AF000 FC000224 */   addiu     $v0, $zero, 0xFC
    /* 46804 800AF004 13000392 */  lbu        $v1, 0x13($s0)
    /* 46808 800AF008 00000000 */  nop
    /* 4680C 800AF00C 2C016210 */  beq        $v1, $v0, .L800AF4C0
    /* 46810 800AF010 00000000 */   nop
    /* 46814 800AF014 A7AB020C */  jal        func_800AAE9C
    /* 46818 800AF018 21200002 */   addu      $a0, $s0, $zero
    /* 4681C 800AF01C 64000292 */  lbu        $v0, 0x64($s0)
    /* 46820 800AF020 00000000 */  nop
    /* 46824 800AF024 04004010 */  beqz       $v0, .L800AF038
    /* 46828 800AF028 21200002 */   addu      $a0, $s0, $zero
    /* 4682C 800AF02C 21280000 */  addu       $a1, $zero, $zero
    /* 46830 800AF030 E2AD020C */  jal        func_800AB788
    /* 46834 800AF034 2130A000 */   addu      $a2, $a1, $zero
  .L800AF038:
    /* 46838 800AF038 0800028E */  lw         $v0, 0x8($s0)
    /* 4683C 800AF03C 00000000 */  nop
    /* 46840 800AF040 000F4230 */  andi       $v0, $v0, 0xF00
    /* 46844 800AF044 04004010 */  beqz       $v0, .L800AF058
    /* 46848 800AF048 FF7F023C */   lui       $v0, (0x7FFFFFFF >> 16)
    /* 4684C 800AF04C 69AE020C */  jal        func_800AB9A4
    /* 46850 800AF050 21200002 */   addu      $a0, $s0, $zero
    /* 46854 800AF054 FF7F023C */  lui        $v0, (0x7FFFFFFF >> 16)
  .L800AF058:
    /* 46858 800AF058 0800038E */  lw         $v1, 0x8($s0)
    /* 4685C 800AF05C FFFF4234 */  ori        $v0, $v0, (0x7FFFFFFF & 0xFFFF)
    /* 46860 800AF060 24106200 */  and        $v0, $v1, $v0
    /* 46864 800AF064 04006330 */  andi       $v1, $v1, 0x4
    /* 46868 800AF068 5C006010 */  beqz       $v1, .L800AF1DC
    /* 4686C 800AF06C 080002AE */   sw        $v0, 0x8($s0)
    /* 46870 800AF070 E4170392 */  lbu        $v1, 0x17E4($s0)
    /* 46874 800AF074 01000224 */  addiu      $v0, $zero, 0x1
    /* 46878 800AF078 2E006214 */  bne        $v1, $v0, .L800AF134
    /* 4687C 800AF07C 00000000 */   nop
    /* 46880 800AF080 E7170292 */  lbu        $v0, 0x17E7($s0)
    /* 46884 800AF084 00000000 */  nop
    /* 46888 800AF088 2A004010 */  beqz       $v0, .L800AF134
    /* 4688C 800AF08C 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 46890 800AF090 4CE2438C */  lw         $v1, %lo(vs_gametime_tickspeed)($v0)
    /* 46894 800AF094 E7170592 */  lbu        $a1, 0x17E7($s0)
    /* 46898 800AF098 C2170300 */  srl        $v0, $v1, 31
    /* 4689C 800AF09C 21186200 */  addu       $v1, $v1, $v0
    /* 468A0 800AF0A0 43180300 */  sra        $v1, $v1, 1
    /* 468A4 800AF0A4 2A10A300 */  slt        $v0, $a1, $v1
    /* 468A8 800AF0A8 02004010 */  beqz       $v0, .L800AF0B4
    /* 468AC 800AF0AC 00000000 */   nop
    /* 468B0 800AF0B0 2118A000 */  addu       $v1, $a1, $zero
  .L800AF0B4:
    /* 468B4 800AF0B4 EA170292 */  lbu        $v0, 0x17EA($s0)
    /* 468B8 800AF0B8 E6170692 */  lbu        $a2, 0x17E6($s0)
    /* 468BC 800AF0BC 00000000 */  nop
    /* 468C0 800AF0C0 23204600 */  subu       $a0, $v0, $a2
    /* 468C4 800AF0C4 09008010 */  beqz       $a0, .L800AF0EC
    /* 468C8 800AF0C8 18008300 */   mult      $a0, $v1
    /* 468CC 800AF0CC 12200000 */  mflo       $a0
    /* 468D0 800AF0D0 00000000 */  nop
    /* 468D4 800AF0D4 00000000 */  nop
    /* 468D8 800AF0D8 1A008500 */  div        $zero, $a0, $a1
    /* 468DC 800AF0DC 12200000 */  mflo       $a0
    /* 468E0 800AF0E0 00000000 */  nop
    /* 468E4 800AF0E4 2110C400 */  addu       $v0, $a2, $a0
    /* 468E8 800AF0E8 E61702A2 */  sb         $v0, 0x17E6($s0)
  .L800AF0EC:
    /* 468EC 800AF0EC E9170292 */  lbu        $v0, 0x17E9($s0)
    /* 468F0 800AF0F0 E5170592 */  lbu        $a1, 0x17E5($s0)
    /* 468F4 800AF0F4 00000000 */  nop
    /* 468F8 800AF0F8 23204500 */  subu       $a0, $v0, $a1
    /* 468FC 800AF0FC 09008010 */  beqz       $a0, .L800AF124
    /* 46900 800AF100 18008300 */   mult      $a0, $v1
    /* 46904 800AF104 12200000 */  mflo       $a0
    /* 46908 800AF108 E7170292 */  lbu        $v0, 0x17E7($s0)
    /* 4690C 800AF10C 00000000 */  nop
    /* 46910 800AF110 1A008200 */  div        $zero, $a0, $v0
    /* 46914 800AF114 12200000 */  mflo       $a0
    /* 46918 800AF118 00000000 */  nop
    /* 4691C 800AF11C 2110A400 */  addu       $v0, $a1, $a0
    /* 46920 800AF120 E51702A2 */  sb         $v0, 0x17E5($s0)
  .L800AF124:
    /* 46924 800AF124 E7170292 */  lbu        $v0, 0x17E7($s0)
    /* 46928 800AF128 00000000 */  nop
    /* 4692C 800AF12C 23104300 */  subu       $v0, $v0, $v1
    /* 46930 800AF130 E71702A2 */  sb         $v0, 0x17E7($s0)
  .L800AF134:
    /* 46934 800AF134 0C00401A */  blez       $s2, .L800AF168
    /* 46938 800AF138 21180000 */   addu      $v1, $zero, $zero
    /* 4693C 800AF13C E6060596 */  lhu        $a1, 0x6E6($s0)
    /* 46940 800AF140 21208002 */  addu       $a0, $s4, $zero
  .L800AF144:
    /* 46944 800AF144 0000828C */  lw         $v0, 0x0($a0)
    /* 46948 800AF148 00000000 */  nop
    /* 4694C 800AF14C E6064294 */  lhu        $v0, 0x6E6($v0)
    /* 46950 800AF150 00000000 */  nop
    /* 46954 800AF154 06004510 */  beq        $v0, $a1, .L800AF170
    /* 46958 800AF158 01006324 */   addiu     $v1, $v1, 0x1
    /* 4695C 800AF15C 2A107200 */  slt        $v0, $v1, $s2
    /* 46960 800AF160 F8FF4014 */  bnez       $v0, .L800AF144
    /* 46964 800AF164 04008424 */   addiu     $a0, $a0, 0x4
  .L800AF168:
    /* 46968 800AF168 3CAD020C */  jal        func_800AB4F0
    /* 4696C 800AF16C 21200002 */   addu      $a0, $s0, $zero
  .L800AF170:
    /* 46970 800AF170 AC05028E */  lw         $v0, 0x5AC($s0)
    /* 46974 800AF174 00000000 */  nop
    /* 46978 800AF178 03004230 */  andi       $v0, $v0, 0x3
    /* 4697C 800AF17C 03004010 */  beqz       $v0, .L800AF18C
    /* 46980 800AF180 21204002 */   addu      $a0, $s2, $zero
    /* 46984 800AF184 50B1020C */  jal        func_800AC540
    /* 46988 800AF188 21280002 */   addu      $a1, $s0, $zero
  .L800AF18C:
    /* 4698C 800AF18C 0680023C */  lui        $v0, %hi(vs_gametime_tickspeed)
    /* 46990 800AF190 4CE2438C */  lw         $v1, %lo(vs_gametime_tickspeed)($v0)
    /* 46994 800AF194 04000224 */  addiu      $v0, $zero, 0x4
    /* 46998 800AF198 05006214 */  bne        $v1, $v0, .L800AF1B0
    /* 4699C 800AF19C 00000000 */   nop
    /* 469A0 800AF1A0 B2050292 */  lbu        $v0, 0x5B2($s0)
    /* 469A4 800AF1A4 00000000 */  nop
    /* 469A8 800AF1A8 40100200 */  sll        $v0, $v0, 1
    /* 469AC 800AF1AC B20502A2 */  sb         $v0, 0x5B2($s0)
  .L800AF1B0:
    /* 469B0 800AF1B0 BABD020C */  jal        func_800AF6E8
    /* 469B4 800AF1B4 21200002 */   addu      $a0, $s0, $zero
    /* 469B8 800AF1B8 01000224 */  addiu      $v0, $zero, 0x1
    /* 469BC 800AF1BC B20502A2 */  sb         $v0, 0x5B2($s0)
    /* 469C0 800AF1C0 B005028E */  lw         $v0, 0x5B0($s0)
    /* 469C4 800AF1C4 00000000 */  nop
    /* 469C8 800AF1C8 C2100200 */  srl        $v0, $v0, 3
    /* 469CC 800AF1CC 01004230 */  andi       $v0, $v0, 0x1
    /* 469D0 800AF1D0 01004224 */  addiu      $v0, $v0, 0x1
    /* 469D4 800AF1D4 79BC0208 */  j          .L800AF1E4
    /* 469D8 800AF1D8 B20502A2 */   sb        $v0, 0x5B2($s0)
  .L800AF1DC:
    /* 469DC 800AF1DC BABA020C */  jal        func_800AEAE8
    /* 469E0 800AF1E0 21200002 */   addu      $a0, $s0, $zero
  .L800AF1E4:
    /* 469E4 800AF1E4 0800028E */  lw         $v0, 0x8($s0)
    /* 469E8 800AF1E8 00000000 */  nop
    /* 469EC 800AF1EC 00204230 */  andi       $v0, $v0, 0x2000
    /* 469F0 800AF1F0 0D004010 */  beqz       $v0, .L800AF228
    /* 469F4 800AF1F4 21200002 */   addu      $a0, $s0, $zero
    /* 469F8 800AF1F8 21300000 */  addu       $a2, $zero, $zero
    /* 469FC 800AF1FC 12000292 */  lbu        $v0, 0x12($s0)
    /* 46A00 800AF200 13000592 */  lbu        $a1, 0x13($s0)
    /* 46A04 800AF204 80100200 */  sll        $v0, $v0, 2
    /* 46A08 800AF208 21105400 */  addu       $v0, $v0, $s4
    /* 46A0C 800AF20C 40290500 */  sll        $a1, $a1, 5
    /* 46A10 800AF210 0000428C */  lw         $v0, 0x0($v0)
    /* 46A14 800AF214 6C00A524 */  addiu      $a1, $a1, 0x6C
    /* 46A18 800AF218 2ACA020C */  jal        func_800B28A8
    /* 46A1C 800AF21C 21284500 */   addu      $a1, $v0, $a1
    /* 46A20 800AF220 23BD0208 */  j          .L800AF48C
    /* 46A24 800AF224 00000000 */   nop
  .L800AF228:
    /* 46A28 800AF228 2128A002 */  addu       $a1, $s5, $zero
    /* 46A2C 800AF22C 2ACA020C */  jal        func_800B28A8
    /* 46A30 800AF230 21300000 */   addu      $a2, $zero, $zero
    /* 46A34 800AF234 FD170292 */  lbu        $v0, 0x17FD($s0)
    /* 46A38 800AF238 00000000 */  nop
    /* 46A3C 800AF23C 93004010 */  beqz       $v0, .L800AF48C
    /* 46A40 800AF240 0200422C */   sltiu     $v0, $v0, 0x2
    /* 46A44 800AF244 5C004014 */  bnez       $v0, .L800AF3B8
    /* 46A48 800AF248 801F133C */   lui       $s3, (0x1F800004 >> 16)
    /* 46A4C 800AF24C FD170292 */  lbu        $v0, 0x17FD($s0)
    /* 46A50 800AF250 00000000 */  nop
    /* 46A54 800AF254 80100200 */  sll        $v0, $v0, 2
    /* 46A58 800AF258 21105400 */  addu       $v0, $v0, $s4
    /* 46A5C 800AF25C 0000518C */  lw         $s1, 0x0($v0)
    /* 46A60 800AF260 A7AB020C */  jal        func_800AAE9C
    /* 46A64 800AF264 21202002 */   addu      $a0, $s1, $zero
    /* 46A68 800AF268 64002292 */  lbu        $v0, 0x64($s1)
    /* 46A6C 800AF26C 00000000 */  nop
    /* 46A70 800AF270 04004010 */  beqz       $v0, .L800AF284
    /* 46A74 800AF274 21202002 */   addu      $a0, $s1, $zero
    /* 46A78 800AF278 21280000 */  addu       $a1, $zero, $zero
    /* 46A7C 800AF27C E2AD020C */  jal        func_800AB788
    /* 46A80 800AF280 2130A000 */   addu      $a2, $a1, $zero
  .L800AF284:
    /* 46A84 800AF284 0800228E */  lw         $v0, 0x8($s1)
    /* 46A88 800AF288 00000000 */  nop
    /* 46A8C 800AF28C 000F4230 */  andi       $v0, $v0, 0xF00
    /* 46A90 800AF290 03004010 */  beqz       $v0, .L800AF2A0
    /* 46A94 800AF294 00000000 */   nop
    /* 46A98 800AF298 69AE020C */  jal        func_800AB9A4
    /* 46A9C 800AF29C 21202002 */   addu      $a0, $s1, $zero
  .L800AF2A0:
    /* 46AA0 800AF2A0 0800028E */  lw         $v0, 0x8($s0)
    /* 46AA4 800AF2A4 00000000 */  nop
    /* 46AA8 800AF2A8 04004230 */  andi       $v0, $v0, 0x4
    /* 46AAC 800AF2AC 41004010 */  beqz       $v0, .L800AF3B4
    /* 46AB0 800AF2B0 01000224 */   addiu     $v0, $zero, 0x1
    /* 46AB4 800AF2B4 E4172392 */  lbu        $v1, 0x17E4($s1)
    /* 46AB8 800AF2B8 00000000 */  nop
    /* 46ABC 800AF2BC 2E006214 */  bne        $v1, $v0, .L800AF378
    /* 46AC0 800AF2C0 00000000 */   nop
    /* 46AC4 800AF2C4 E7172292 */  lbu        $v0, 0x17E7($s1)
    /* 46AC8 800AF2C8 00000000 */  nop
    /* 46ACC 800AF2CC 2A004010 */  beqz       $v0, .L800AF378
    /* 46AD0 800AF2D0 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 46AD4 800AF2D4 4CE2438C */  lw         $v1, %lo(vs_gametime_tickspeed)($v0)
    /* 46AD8 800AF2D8 E7172592 */  lbu        $a1, 0x17E7($s1)
    /* 46ADC 800AF2DC C2170300 */  srl        $v0, $v1, 31
    /* 46AE0 800AF2E0 21186200 */  addu       $v1, $v1, $v0
    /* 46AE4 800AF2E4 43180300 */  sra        $v1, $v1, 1
    /* 46AE8 800AF2E8 2A10A300 */  slt        $v0, $a1, $v1
    /* 46AEC 800AF2EC 02004010 */  beqz       $v0, .L800AF2F8
    /* 46AF0 800AF2F0 00000000 */   nop
    /* 46AF4 800AF2F4 2118A000 */  addu       $v1, $a1, $zero
  .L800AF2F8:
    /* 46AF8 800AF2F8 EA172292 */  lbu        $v0, 0x17EA($s1)
    /* 46AFC 800AF2FC E6172692 */  lbu        $a2, 0x17E6($s1)
    /* 46B00 800AF300 00000000 */  nop
    /* 46B04 800AF304 23204600 */  subu       $a0, $v0, $a2
    /* 46B08 800AF308 09008010 */  beqz       $a0, .L800AF330
    /* 46B0C 800AF30C 18008300 */   mult      $a0, $v1
    /* 46B10 800AF310 12200000 */  mflo       $a0
    /* 46B14 800AF314 00000000 */  nop
    /* 46B18 800AF318 00000000 */  nop
    /* 46B1C 800AF31C 1A008500 */  div        $zero, $a0, $a1
    /* 46B20 800AF320 12200000 */  mflo       $a0
    /* 46B24 800AF324 00000000 */  nop
    /* 46B28 800AF328 2110C400 */  addu       $v0, $a2, $a0
    /* 46B2C 800AF32C E61722A2 */  sb         $v0, 0x17E6($s1)
  .L800AF330:
    /* 46B30 800AF330 E9172292 */  lbu        $v0, 0x17E9($s1)
    /* 46B34 800AF334 E5172592 */  lbu        $a1, 0x17E5($s1)
    /* 46B38 800AF338 00000000 */  nop
    /* 46B3C 800AF33C 23204500 */  subu       $a0, $v0, $a1
    /* 46B40 800AF340 09008010 */  beqz       $a0, .L800AF368
    /* 46B44 800AF344 18008300 */   mult      $a0, $v1
    /* 46B48 800AF348 12200000 */  mflo       $a0
    /* 46B4C 800AF34C E7172292 */  lbu        $v0, 0x17E7($s1)
    /* 46B50 800AF350 00000000 */  nop
    /* 46B54 800AF354 1A008200 */  div        $zero, $a0, $v0
    /* 46B58 800AF358 12200000 */  mflo       $a0
    /* 46B5C 800AF35C 00000000 */  nop
    /* 46B60 800AF360 2110A400 */  addu       $v0, $a1, $a0
    /* 46B64 800AF364 E51722A2 */  sb         $v0, 0x17E5($s1)
  .L800AF368:
    /* 46B68 800AF368 E7172292 */  lbu        $v0, 0x17E7($s1)
    /* 46B6C 800AF36C 00000000 */  nop
    /* 46B70 800AF370 23104300 */  subu       $v0, $v0, $v1
    /* 46B74 800AF374 E71722A2 */  sb         $v0, 0x17E7($s1)
  .L800AF378:
    /* 46B78 800AF378 0C00401A */  blez       $s2, .L800AF3AC
    /* 46B7C 800AF37C 21180000 */   addu      $v1, $zero, $zero
    /* 46B80 800AF380 E6062596 */  lhu        $a1, 0x6E6($s1)
    /* 46B84 800AF384 21208002 */  addu       $a0, $s4, $zero
  .L800AF388:
    /* 46B88 800AF388 0000828C */  lw         $v0, 0x0($a0)
    /* 46B8C 800AF38C 00000000 */  nop
    /* 46B90 800AF390 E6064294 */  lhu        $v0, 0x6E6($v0)
    /* 46B94 800AF394 00000000 */  nop
    /* 46B98 800AF398 06004510 */  beq        $v0, $a1, .L800AF3B4
    /* 46B9C 800AF39C 01006324 */   addiu     $v1, $v1, 0x1
    /* 46BA0 800AF3A0 2A107200 */  slt        $v0, $v1, $s2
    /* 46BA4 800AF3A4 F8FF4014 */  bnez       $v0, .L800AF388
    /* 46BA8 800AF3A8 04008424 */   addiu     $a0, $a0, 0x4
  .L800AF3AC:
    /* 46BAC 800AF3AC 3CAD020C */  jal        func_800AB4F0
    /* 46BB0 800AF3B0 21202002 */   addu      $a0, $s1, $zero
  .L800AF3B4:
    /* 46BB4 800AF3B4 801F133C */  lui        $s3, (0x1F800004 >> 16)
  .L800AF3B8:
    /* 46BB8 800AF3B8 21200002 */  addu       $a0, $s0, $zero
    /* 46BBC 800AF3BC F7060292 */  lbu        $v0, 0x6F7($s0)
    /* 46BC0 800AF3C0 0400638E */  lw         $v1, (0x1F800004 & 0xFFFF)($s3)
    /* 46BC4 800AF3C4 80100200 */  sll        $v0, $v0, 2
    /* 46BC8 800AF3C8 21186200 */  addu       $v1, $v1, $v0
    /* 46BCC 800AF3CC 040063AE */  sw         $v1, (0x1F800004 & 0xFFFF)($s3)
    /* 46BD0 800AF3D0 F4060392 */  lbu        $v1, 0x6F4($s0)
    /* 46BD4 800AF3D4 FD170592 */  lbu        $a1, 0x17FD($s0)
    /* 46BD8 800AF3D8 F5060792 */  lbu        $a3, 0x6F5($s0)
    /* 46BDC 800AF3DC F6060692 */  lbu        $a2, 0x6F6($s0)
    /* 46BE0 800AF3E0 1C000296 */  lhu        $v0, 0x1C($s0)
    /* 46BE4 800AF3E4 001E0300 */  sll        $v1, $v1, 24
    /* 46BE8 800AF3E8 031E0300 */  sra        $v1, $v1, 24
    /* 46BEC 800AF3EC 003E0700 */  sll        $a3, $a3, 24
    /* 46BF0 800AF3F0 033E0700 */  sra        $a3, $a3, 24
    /* 46BF4 800AF3F4 00360600 */  sll        $a2, $a2, 24
    /* 46BF8 800AF3F8 03360600 */  sra        $a2, $a2, 24
    /* 46BFC 800AF3FC 21104300 */  addu       $v0, $v0, $v1
    /* 46C00 800AF400 1C0002A6 */  sh         $v0, 0x1C($s0)
    /* 46C04 800AF404 1E000296 */  lhu        $v0, 0x1E($s0)
    /* 46C08 800AF408 20000396 */  lhu        $v1, 0x20($s0)
    /* 46C0C 800AF40C 21104700 */  addu       $v0, $v0, $a3
    /* 46C10 800AF410 21186600 */  addu       $v1, $v1, $a2
    /* 46C14 800AF414 1E0002A6 */  sh         $v0, 0x1E($s0)
    /* 46C18 800AF418 0BC0020C */  jal        func_800B002C
    /* 46C1C 800AF41C 200003A6 */   sh        $v1, 0x20($s0)
    /* 46C20 800AF420 21200002 */  addu       $a0, $s0, $zero
    /* 46C24 800AF424 FD170692 */  lbu        $a2, 0x17FD($s0)
    /* 46C28 800AF428 2ACA020C */  jal        func_800B28A8
    /* 46C2C 800AF42C 2128A002 */   addu      $a1, $s5, $zero
    /* 46C30 800AF430 F7060292 */  lbu        $v0, 0x6F7($s0)
    /* 46C34 800AF434 0400638E */  lw         $v1, (0x1F800004 & 0xFFFF)($s3)
    /* 46C38 800AF438 80100200 */  sll        $v0, $v0, 2
    /* 46C3C 800AF43C 23186200 */  subu       $v1, $v1, $v0
    /* 46C40 800AF440 040063AE */  sw         $v1, (0x1F800004 & 0xFFFF)($s3)
    /* 46C44 800AF444 F4060392 */  lbu        $v1, 0x6F4($s0)
    /* 46C48 800AF448 F5060592 */  lbu        $a1, 0x6F5($s0)
    /* 46C4C 800AF44C F6060492 */  lbu        $a0, 0x6F6($s0)
    /* 46C50 800AF450 1C000296 */  lhu        $v0, 0x1C($s0)
    /* 46C54 800AF454 001E0300 */  sll        $v1, $v1, 24
    /* 46C58 800AF458 031E0300 */  sra        $v1, $v1, 24
    /* 46C5C 800AF45C 002E0500 */  sll        $a1, $a1, 24
    /* 46C60 800AF460 032E0500 */  sra        $a1, $a1, 24
    /* 46C64 800AF464 00260400 */  sll        $a0, $a0, 24
    /* 46C68 800AF468 03260400 */  sra        $a0, $a0, 24
    /* 46C6C 800AF46C 23104300 */  subu       $v0, $v0, $v1
    /* 46C70 800AF470 1C0002A6 */  sh         $v0, 0x1C($s0)
    /* 46C74 800AF474 1E000296 */  lhu        $v0, 0x1E($s0)
    /* 46C78 800AF478 20000396 */  lhu        $v1, 0x20($s0)
    /* 46C7C 800AF47C 23104500 */  subu       $v0, $v0, $a1
    /* 46C80 800AF480 23186400 */  subu       $v1, $v1, $a0
    /* 46C84 800AF484 1E0002A6 */  sh         $v0, 0x1E($s0)
    /* 46C88 800AF488 200003A6 */  sh         $v1, 0x20($s0)
  .L800AF48C:
    /* 46C8C 800AF48C 3C060296 */  lhu        $v0, 0x63C($s0)
    /* 46C90 800AF490 00000000 */  nop
    /* 46C94 800AF494 8000422C */  sltiu      $v0, $v0, 0x80
    /* 46C98 800AF498 09004014 */  bnez       $v0, .L800AF4C0
    /* 46C9C 800AF49C 00000000 */   nop
    /* 46CA0 800AF4A0 CC050292 */  lbu        $v0, 0x5CC($s0)
    /* 46CA4 800AF4A4 00000000 */  nop
    /* 46CA8 800AF4A8 05004010 */  beqz       $v0, .L800AF4C0
    /* 46CAC 800AF4AC 0080033C */   lui       $v1, (0x80000000 >> 16)
    /* 46CB0 800AF4B0 0800028E */  lw         $v0, 0x8($s0)
    /* 46CB4 800AF4B4 00000000 */  nop
    /* 46CB8 800AF4B8 25104300 */  or         $v0, $v0, $v1
    /* 46CBC 800AF4BC 080002AE */  sw         $v0, 0x8($s0)
  .L800AF4C0:
    /* 46CC0 800AF4C0 01005226 */  addiu      $s2, $s2, 0x1
    /* 46CC4 800AF4C4 1100422A */  slti       $v0, $s2, 0x11
    /* 46CC8 800AF4C8 C0FE4014 */  bnez       $v0, .L800AEFCC
    /* 46CCC 800AF4CC 80101200 */   sll       $v0, $s2, 2
    /* 46CD0 800AF4D0 21900000 */  addu       $s2, $zero, $zero
    /* 46CD4 800AF4D4 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 46CD8 800AF4D8 38455324 */  addiu      $s3, $v0, %lo(D_800F4538)
    /* 46CDC 800AF4DC 0F80023C */  lui        $v0, %hi(D_800F4588)
    /* 46CE0 800AF4E0 88455124 */  addiu      $s1, $v0, %lo(D_800F4588)
  .L800AF4E4:
    /* 46CE4 800AF4E4 0000248E */  lw         $a0, 0x0($s1)
    /* 46CE8 800AF4E8 00000000 */  nop
    /* 46CEC 800AF4EC 22008010 */  beqz       $a0, .L800AF578
    /* 46CF0 800AF4F0 00000000 */   nop
    /* 46CF4 800AF4F4 0800828C */  lw         $v0, 0x8($a0)
    /* 46CF8 800AF4F8 00000000 */  nop
    /* 46CFC 800AF4FC 10004230 */  andi       $v0, $v0, 0x10
    /* 46D00 800AF500 1D004010 */  beqz       $v0, .L800AF578
    /* 46D04 800AF504 00000000 */   nop
    /* 46D08 800AF508 0D008290 */  lbu        $v0, 0xD($a0)
    /* 46D0C 800AF50C 00000000 */  nop
    /* 46D10 800AF510 19004010 */  beqz       $v0, .L800AF578
    /* 46D14 800AF514 00000000 */   nop
    /* 46D18 800AF518 08008290 */  lbu        $v0, 0x8($a0)
    /* 46D1C 800AF51C 00000000 */  nop
    /* 46D20 800AF520 0F004230 */  andi       $v0, $v0, 0xF
    /* 46D24 800AF524 80100200 */  sll        $v0, $v0, 2
    /* 46D28 800AF528 21105300 */  addu       $v0, $v0, $s3
    /* 46D2C 800AF52C 0000508C */  lw         $s0, 0x0($v0)
    /* 46D30 800AF530 00000000 */  nop
    /* 46D34 800AF534 10000012 */  beqz       $s0, .L800AF578
    /* 46D38 800AF538 00000000 */   nop
    /* 46D3C 800AF53C 0800038E */  lw         $v1, 0x8($s0)
    /* 46D40 800AF540 00000000 */  nop
    /* 46D44 800AF544 01006230 */  andi       $v0, $v1, 0x1
    /* 46D48 800AF548 0B004014 */  bnez       $v0, .L800AF578
    /* 46D4C 800AF54C 02006230 */   andi      $v0, $v1, 0x2
    /* 46D50 800AF550 09004010 */  beqz       $v0, .L800AF578
    /* 46D54 800AF554 00106230 */   andi      $v0, $v1, 0x1000
    /* 46D58 800AF558 07004014 */  bnez       $v0, .L800AF578
    /* 46D5C 800AF55C 00000000 */   nop
    /* 46D60 800AF560 0D008590 */  lbu        $a1, 0xD($a0)
    /* 46D64 800AF564 00000000 */  nop
    /* 46D68 800AF568 40290500 */  sll        $a1, $a1, 5
    /* 46D6C 800AF56C 6C00A524 */  addiu      $a1, $a1, 0x6C
    /* 46D70 800AF570 5FC8020C */  jal        func_800B217C
    /* 46D74 800AF574 21280502 */   addu      $a1, $s0, $a1
  .L800AF578:
    /* 46D78 800AF578 01005226 */  addiu      $s2, $s2, 0x1
    /* 46D7C 800AF57C 1400422A */  slti       $v0, $s2, 0x14
    /* 46D80 800AF580 D8FF4014 */  bnez       $v0, .L800AF4E4
    /* 46D84 800AF584 04003126 */   addiu     $s1, $s1, 0x4
    /* 46D88 800AF588 801F113C */  lui        $s1, (0x1F80035C >> 16)
    /* 46D8C 800AF58C 5C033136 */  ori        $s1, $s1, (0x1F80035C & 0xFFFF)
    /* 46D90 800AF590 801F133C */  lui        $s3, (0x1F800004 >> 16)
    /* 46D94 800AF594 21900000 */  addu       $s2, $zero, $zero
    /* 46D98 800AF598 0F80033C */  lui        $v1, %hi(D_800F45E0)
    /* 46D9C 800AF59C 0400628E */  lw         $v0, (0x1F800004 & 0xFFFF)($s3)
    /* 46DA0 800AF5A0 E0457424 */  addiu      $s4, $v1, %lo(D_800F45E0)
    /* 46DA4 800AF5A4 10004224 */  addiu      $v0, $v0, 0x10
    /* 46DA8 800AF5A8 040062AE */  sw         $v0, (0x1F800004 & 0xFFFF)($s3)
  .L800AF5AC:
    /* 46DAC 800AF5AC 0000908E */  lw         $s0, 0x0($s4)
    /* 46DB0 800AF5B0 00000000 */  nop
    /* 46DB4 800AF5B4 35000012 */  beqz       $s0, .L800AF68C
    /* 46DB8 800AF5B8 00000000 */   nop
    /* 46DBC 800AF5BC 00000292 */  lbu        $v0, 0x0($s0)
    /* 46DC0 800AF5C0 00000000 */  nop
    /* 46DC4 800AF5C4 31004010 */  beqz       $v0, .L800AF68C
    /* 46DC8 800AF5C8 0F80023C */   lui       $v0, %hi(D_800F4B19)
    /* 46DCC 800AF5CC 194B4290 */  lbu        $v0, %lo(D_800F4B19)($v0)
    /* 46DD0 800AF5D0 00000000 */  nop
    /* 46DD4 800AF5D4 05004216 */  bne        $s2, $v0, .L800AF5EC
    /* 46DD8 800AF5D8 0F80023C */   lui       $v0, %hi(D_800F4B18)
    /* 46DDC 800AF5DC 184B4290 */  lbu        $v0, %lo(D_800F4B18)($v0)
    /* 46DE0 800AF5E0 00000000 */  nop
    /* 46DE4 800AF5E4 05004010 */  beqz       $v0, .L800AF5FC
    /* 46DE8 800AF5E8 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
  .L800AF5EC:
    /* 46DEC 800AF5EC 1A000386 */  lh         $v1, 0x1A($s0)
    /* 46DF0 800AF5F0 F7000224 */  addiu      $v0, $zero, 0xF7
    /* 46DF4 800AF5F4 07006214 */  bne        $v1, $v0, .L800AF614
    /* 46DF8 800AF5F8 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
  .L800AF5FC:
    /* 46DFC 800AF5FC 4CE2458C */  lw         $a1, %lo(vs_gametime_tickspeed)($v0)
    /* 46E00 800AF600 21200002 */  addu       $a0, $s0, $zero
    /* 46E04 800AF604 C2170500 */  srl        $v0, $a1, 31
    /* 46E08 800AF608 2128A200 */  addu       $a1, $a1, $v0
    /* 46E0C 800AF60C 42C2020C */  jal        func_800B0908
    /* 46E10 800AF610 43280500 */   sra       $a1, $a1, 1
  .L800AF614:
    /* 46E14 800AF614 20000296 */  lhu        $v0, 0x20($s0)
    /* 46E18 800AF618 1C00048E */  lw         $a0, 0x1C($s0)
    /* 46E1C 800AF61C 580022A6 */  sh         $v0, 0x58($s1)
    /* 46E20 800AF620 6800028E */  lw         $v0, 0x68($s0)
    /* 46E24 800AF624 00000000 */  nop
    /* 46E28 800AF628 5000438C */  lw         $v1, 0x50($v0)
    /* 46E2C 800AF62C 540024AE */  sw         $a0, 0x54($s1)
    /* 46E30 800AF630 C2170300 */  srl        $v0, $v1, 31
    /* 46E34 800AF634 21186200 */  addu       $v1, $v1, $v0
    /* 46E38 800AF638 56002296 */  lhu        $v0, 0x56($s1)
    /* 46E3C 800AF63C 43180300 */  sra        $v1, $v1, 1
    /* 46E40 800AF640 21104300 */  addu       $v0, $v0, $v1
    /* 46E44 800AF644 560022A6 */  sh         $v0, 0x56($s1)
    /* 46E48 800AF648 64000292 */  lbu        $v0, 0x64($s0)
    /* 46E4C 800AF64C 00000000 */  nop
    /* 46E50 800AF650 04004010 */  beqz       $v0, .L800AF664
    /* 46E54 800AF654 21200000 */   addu      $a0, $zero, $zero
    /* 46E58 800AF658 21280002 */  addu       $a1, $s0, $zero
    /* 46E5C 800AF65C E2AD020C */  jal        func_800AB788
    /* 46E60 800AF660 21308000 */   addu      $a2, $a0, $zero
  .L800AF664:
    /* 46E64 800AF664 0800028E */  lw         $v0, 0x8($s0)
    /* 46E68 800AF668 00000000 */  nop
    /* 46E6C 800AF66C 000F4230 */  andi       $v0, $v0, 0xF00
    /* 46E70 800AF670 04004010 */  beqz       $v0, .L800AF684
    /* 46E74 800AF674 21200002 */   addu      $a0, $s0, $zero
    /* 46E78 800AF678 69AE020C */  jal        func_800AB9A4
    /* 46E7C 800AF67C 21200002 */   addu      $a0, $s0, $zero
    /* 46E80 800AF680 21200002 */  addu       $a0, $s0, $zero
  .L800AF684:
    /* 46E84 800AF684 9AC6020C */  jal        func_800B1A68
    /* 46E88 800AF688 2128A002 */   addu      $a1, $s5, $zero
  .L800AF68C:
    /* 46E8C 800AF68C 01005226 */  addiu      $s2, $s2, 0x1
    /* 46E90 800AF690 1000422A */  slti       $v0, $s2, 0x10
    /* 46E94 800AF694 C5FF4014 */  bnez       $v0, .L800AF5AC
    /* 46E98 800AF698 04009426 */   addiu     $s4, $s4, 0x4
    /* 46E9C 800AF69C 0F80023C */  lui        $v0, %hi(D_800F4B18)
    /* 46EA0 800AF6A0 0F80043C */  lui        $a0, %hi(D_800E9308)
    /* 46EA4 800AF6A4 184B40A0 */  sb         $zero, %lo(D_800F4B18)($v0)
    /* 46EA8 800AF6A8 0400628E */  lw         $v0, (0x1F800004 & 0xFFFF)($s3)
    /* 46EAC 800AF6AC 0893838C */  lw         $v1, %lo(D_800E9308)($a0)
    /* 46EB0 800AF6B0 F0FF4224 */  addiu      $v0, $v0, -0x10
    /* 46EB4 800AF6B4 01006324 */  addiu      $v1, $v1, 0x1
    /* 46EB8 800AF6B8 040062AE */  sw         $v0, (0x1F800004 & 0xFFFF)($s3)
    /* 46EBC 800AF6BC 089383AC */  sw         $v1, %lo(D_800E9308)($a0)
    /* 46EC0 800AF6C0 5800BF8F */  lw         $ra, 0x58($sp)
    /* 46EC4 800AF6C4 5400B58F */  lw         $s5, 0x54($sp)
    /* 46EC8 800AF6C8 5000B48F */  lw         $s4, 0x50($sp)
    /* 46ECC 800AF6CC 4C00B38F */  lw         $s3, 0x4C($sp)
    /* 46ED0 800AF6D0 4800B28F */  lw         $s2, 0x48($sp)
    /* 46ED4 800AF6D4 4400B18F */  lw         $s1, 0x44($sp)
    /* 46ED8 800AF6D8 4000B08F */  lw         $s0, 0x40($sp)
    /* 46EDC 800AF6DC 6000BD27 */  addiu      $sp, $sp, 0x60
    /* 46EE0 800AF6E0 0800E003 */  jr         $ra
    /* 46EE4 800AF6E4 00000000 */   nop
endlabel func_800AEF94
