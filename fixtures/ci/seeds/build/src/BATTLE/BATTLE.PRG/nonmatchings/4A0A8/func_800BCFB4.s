nonmatching func_800BCFB4, 0x304

glabel func_800BCFB4
    /* 547B4 800BCFB4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 547B8 800BCFB8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 547BC 800BCFBC 21888000 */  addu       $s1, $a0, $zero
    /* 547C0 800BCFC0 801F043C */  lui        $a0, (0x1F800098 >> 16)
    /* 547C4 800BCFC4 98008434 */  ori        $a0, $a0, (0x1F800098 & 0xFFFF)
    /* 547C8 800BCFC8 A4002526 */  addiu      $a1, $s1, 0xA4
    /* 547CC 800BCFCC 24002626 */  addiu      $a2, $s1, 0x24
    /* 547D0 800BCFD0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 547D4 800BCFD4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 547D8 800BCFD8 9BF9020C */  jal        _vectorSubtract
    /* 547DC 800BCFDC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 547E0 800BCFE0 801F043C */  lui        $a0, (0x1F800098 >> 16)
    /* 547E4 800BCFE4 98008434 */  ori        $a0, $a0, (0x1F800098 & 0xFFFF)
    /* 547E8 800BCFE8 801F053C */  lui        $a1, (0x1F8000F8 >> 16)
    /* 547EC 800BCFEC 27FA020C */  jal        _vecToRotMatrix
    /* 547F0 800BCFF0 F800A534 */   ori       $a1, $a1, (0x1F8000F8 & 0xFFFF)
    /* 547F4 800BCFF4 801F103C */  lui        $s0, (0x1F800088 >> 16)
    /* 547F8 800BCFF8 2400228E */  lw         $v0, 0x24($s1)
    /* 547FC 800BCFFC 88001036 */  ori        $s0, $s0, (0x1F800088 & 0xFFFF)
    /* 54800 800BD000 03130200 */  sra        $v0, $v0, 12
    /* 54804 800BD004 840002AE */  sw         $v0, 0x84($s0)
    /* 54808 800BD008 2800228E */  lw         $v0, 0x28($s1)
    /* 5480C 800BD00C 00000000 */  nop
    /* 54810 800BD010 03130200 */  sra        $v0, $v0, 12
    /* 54814 800BD014 880002AE */  sw         $v0, 0x88($s0)
    /* 54818 800BD018 2C00228E */  lw         $v0, 0x2C($s1)
    /* 5481C 800BD01C 801F043C */  lui        $a0, (0x1F8000F8 >> 16)
    /* 54820 800BD020 03130200 */  sra        $v0, $v0, 12
    /* 54824 800BD024 8C0002AE */  sw         $v0, 0x8C($s0)
    /* 54828 800BD028 2400228E */  lw         $v0, 0x24($s1)
    /* 5482C 800BD02C 8400238E */  lw         $v1, 0x84($s1)
    /* 54830 800BD030 F8008434 */  ori        $a0, $a0, (0x1F8000F8 & 0xFFFF)
    /* 54834 800BD034 23104300 */  subu       $v0, $v0, $v1
    /* 54838 800BD038 AEF4020C */  jal        func_800BD2B8
    /* 5483C 800BD03C 100002AE */   sw        $v0, 0x10($s0)
    /* 54840 800BD040 8800238E */  lw         $v1, 0x88($s1)
    /* 54844 800BD044 801F043C */  lui        $a0, (0x1F800098 >> 16)
    /* 54848 800BD048 23104300 */  subu       $v0, $v0, $v1
    /* 5484C 800BD04C 140002AE */  sw         $v0, 0x14($s0)
    /* 54850 800BD050 2C00228E */  lw         $v0, 0x2C($s1)
    /* 54854 800BD054 8C00238E */  lw         $v1, 0x8C($s1)
    /* 54858 800BD058 98008434 */  ori        $a0, $a0, (0x1F800098 & 0xFFFF)
    /* 5485C 800BD05C 23104300 */  subu       $v0, $v0, $v1
    /* 54860 800BD060 D0F9020C */  jal        _vectorMagnitude
    /* 54864 800BD064 180002AE */   sw        $v0, 0x18($s0)
    /* 54868 800BD068 000002AE */  sw         $v0, 0x0($s0)
    /* 5486C 800BD06C 0800238E */  lw         $v1, 0x8($s1)
    /* 54870 800BD070 00000000 */  nop
    /* 54874 800BD074 1A004300 */  div        $zero, $v0, $v1
    /* 54878 800BD078 12180000 */  mflo       $v1
    /* 5487C 800BD07C 00000000 */  nop
    /* 54880 800BD080 02006228 */  slti       $v0, $v1, 0x2
    /* 54884 800BD084 1C004010 */  beqz       $v0, .L800BD0F8
    /* 54888 800BD088 040003AE */   sw        $v1, 0x4($s0)
    /* 5488C 800BD08C 05002292 */  lbu        $v0, 0x5($s1)
    /* 54890 800BD090 43F40208 */  j          .L800BD10C
    /* 54894 800BD094 040022A2 */   sb        $v0, 0x4($s1)
  .L800BD098:
    /* 54898 800BD098 801F043C */  lui        $a0, (0x1F800098 >> 16)
    /* 5489C 800BD09C 2000028E */  lw         $v0, 0x20($s0)
    /* 548A0 800BD0A0 8400238E */  lw         $v1, 0x84($s1)
    /* 548A4 800BD0A4 98008434 */  ori        $a0, $a0, (0x1F800098 & 0xFFFF)
    /* 548A8 800BD0A8 23104300 */  subu       $v0, $v0, $v1
    /* 548AC 800BD0AC 100002AE */  sw         $v0, 0x10($s0)
    /* 548B0 800BD0B0 8800228E */  lw         $v0, 0x88($s1)
    /* 548B4 800BD0B4 801F053C */  lui        $a1, (0x1F800098 >> 16)
    /* 548B8 800BD0B8 2310C200 */  subu       $v0, $a2, $v0
    /* 548BC 800BD0BC 140002AE */  sw         $v0, 0x14($s0)
    /* 548C0 800BD0C0 2800028E */  lw         $v0, 0x28($s0)
    /* 548C4 800BD0C4 8C00238E */  lw         $v1, 0x8C($s1)
    /* 548C8 800BD0C8 9800A534 */  ori        $a1, $a1, (0x1F800098 & 0xFFFF)
    /* 548CC 800BD0CC 23104300 */  subu       $v0, $v0, $v1
    /* 548D0 800BD0D0 50FA020C */  jal        _toNormalIntegerVector
    /* 548D4 800BD0D4 180002AE */   sw        $v0, 0x18($s0)
    /* 548D8 800BD0D8 801F043C */  lui        $a0, (0x1F800098 >> 16)
    /* 548DC 800BD0DC 98008434 */  ori        $a0, $a0, (0x1F800098 & 0xFFFF)
    /* 548E0 800BD0E0 801F053C */  lui        $a1, (0x1F800098 >> 16)
    /* 548E4 800BD0E4 0800268E */  lw         $a2, 0x8($s1)
    /* 548E8 800BD0E8 ACF9020C */  jal        _vectorFixedPointMult
    /* 548EC 800BD0EC 9800A534 */   ori       $a1, $a1, (0x1F800098 & 0xFFFF)
    /* 548F0 800BD0F0 84F40208 */  j          .L800BD210
    /* 548F4 800BD0F4 801F043C */   lui       $a0, (0x1F8000A8 >> 16)
  .L800BD0F8:
    /* 548F8 800BD0F8 0B006228 */  slti       $v0, $v1, 0xB
    /* 548FC 800BD0FC 04004014 */  bnez       $v0, .L800BD110
    /* 54900 800BD100 801F043C */   lui       $a0, (0x1F800098 >> 16)
    /* 54904 800BD104 0A000224 */  addiu      $v0, $zero, 0xA
    /* 54908 800BD108 040002AE */  sw         $v0, 0x4($s0)
  .L800BD10C:
    /* 5490C 800BD10C 801F043C */  lui        $a0, (0x1F800098 >> 16)
  .L800BD110:
    /* 54910 800BD110 98008434 */  ori        $a0, $a0, (0x1F800098 & 0xFFFF)
    /* 54914 800BD114 801F053C */  lui        $a1, (0x1F800098 >> 16)
    /* 54918 800BD118 50FA020C */  jal        _toNormalIntegerVector
    /* 5491C 800BD11C 9800A534 */   ori       $a1, $a1, (0x1F800098 & 0xFFFF)
    /* 54920 800BD120 801F043C */  lui        $a0, (0x1F800098 >> 16)
    /* 54924 800BD124 98008434 */  ori        $a0, $a0, (0x1F800098 & 0xFFFF)
    /* 54928 800BD128 801F053C */  lui        $a1, (0x1F800098 >> 16)
    /* 5492C 800BD12C 0800268E */  lw         $a2, 0x8($s1)
    /* 54930 800BD130 ACF9020C */  jal        _vectorFixedPointMult
    /* 54934 800BD134 9800A534 */   ori       $a1, $a1, (0x1F800098 & 0xFFFF)
    /* 54938 800BD138 801F043C */  lui        $a0, (0x1F8000A8 >> 16)
    /* 5493C 800BD13C A8008434 */  ori        $a0, $a0, (0x1F8000A8 & 0xFFFF)
    /* 54940 800BD140 C7F9020C */  jal        _copyVector
    /* 54944 800BD144 84002526 */   addiu     $a1, $s1, 0x84
    /* 54948 800BD148 801F023C */  lui        $v0, (0x1F80008C >> 16)
    /* 5494C 800BD14C 8C00428C */  lw         $v0, (0x1F80008C & 0xFFFF)($v0)
    /* 54950 800BD150 00000000 */  nop
    /* 54954 800BD154 2D004018 */  blez       $v0, .L800BD20C
    /* 54958 800BD158 01001224 */   addiu     $s2, $zero, 0x1
    /* 5495C 800BD15C 801F103C */  lui        $s0, (0x1F800088 >> 16)
    /* 54960 800BD160 88001036 */  ori        $s0, $s0, (0x1F800088 & 0xFFFF)
    /* 54964 800BD164 801F043C */  lui        $a0, (0x1F8000A8 >> 16)
  .L800BD168:
    /* 54968 800BD168 A8008434 */  ori        $a0, $a0, (0x1F8000A8 & 0xFFFF)
    /* 5496C 800BD16C 801F053C */  lui        $a1, (0x1F8000A8 >> 16)
    /* 54970 800BD170 A800A534 */  ori        $a1, $a1, (0x1F8000A8 & 0xFFFF)
    /* 54974 800BD174 801F063C */  lui        $a2, (0x1F800098 >> 16)
    /* 54978 800BD178 8AF9020C */  jal        _vectorAdd
    /* 5497C 800BD17C 9800C634 */   ori       $a2, $a2, (0x1F800098 & 0xFFFF)
    /* 54980 800BD180 801F043C */  lui        $a0, (0x1F8000B8 >> 16)
    /* 54984 800BD184 B8008434 */  ori        $a0, $a0, (0x1F8000B8 & 0xFFFF)
    /* 54988 800BD188 A4002526 */  addiu      $a1, $s1, 0xA4
    /* 5498C 800BD18C 801F063C */  lui        $a2, (0x1F8000A8 >> 16)
    /* 54990 800BD190 9BF9020C */  jal        _vectorSubtract
    /* 54994 800BD194 A800C634 */   ori       $a2, $a2, (0x1F8000A8 & 0xFFFF)
    /* 54998 800BD198 801F043C */  lui        $a0, (0x1F8000B8 >> 16)
    /* 5499C 800BD19C B8008434 */  ori        $a0, $a0, (0x1F8000B8 & 0xFFFF)
    /* 549A0 800BD1A0 801F053C */  lui        $a1, (0x1F8000F8 >> 16)
    /* 549A4 800BD1A4 27FA020C */  jal        _vecToRotMatrix
    /* 549A8 800BD1A8 F800A534 */   ori       $a1, $a1, (0x1F8000F8 & 0xFFFF)
    /* 549AC 800BD1AC 801F043C */  lui        $a0, (0x1F8000F8 >> 16)
    /* 549B0 800BD1B0 F8008434 */  ori        $a0, $a0, (0x1F8000F8 & 0xFFFF)
    /* 549B4 800BD1B4 2000028E */  lw         $v0, 0x20($s0)
    /* 549B8 800BD1B8 2800038E */  lw         $v1, 0x28($s0)
    /* 549BC 800BD1BC 03130200 */  sra        $v0, $v0, 12
    /* 549C0 800BD1C0 840002AE */  sw         $v0, 0x84($s0)
    /* 549C4 800BD1C4 2400028E */  lw         $v0, 0x24($s0)
    /* 549C8 800BD1C8 031B0300 */  sra        $v1, $v1, 12
    /* 549CC 800BD1CC 8C0003AE */  sw         $v1, 0x8C($s0)
    /* 549D0 800BD1D0 03130200 */  sra        $v0, $v0, 12
    /* 549D4 800BD1D4 AEF4020C */  jal        func_800BD2B8
    /* 549D8 800BD1D8 880002AE */   sw        $v0, 0x88($s0)
    /* 549DC 800BD1DC 2400038E */  lw         $v1, 0x24($s0)
    /* 549E0 800BD1E0 21304000 */  addu       $a2, $v0, $zero
    /* 549E4 800BD1E4 2A18C300 */  slt        $v1, $a2, $v1
    /* 549E8 800BD1E8 ABFF6014 */  bnez       $v1, .L800BD098
    /* 549EC 800BD1EC 01004226 */   addiu     $v0, $s2, 0x1
    /* 549F0 800BD1F0 21904000 */  addu       $s2, $v0, $zero
    /* 549F4 800BD1F4 00140200 */  sll        $v0, $v0, 16
    /* 549F8 800BD1F8 0400038E */  lw         $v1, 0x4($s0)
    /* 549FC 800BD1FC 03140200 */  sra        $v0, $v0, 16
    /* 54A00 800BD200 2A186200 */  slt        $v1, $v1, $v0
    /* 54A04 800BD204 D8FF6010 */  beqz       $v1, .L800BD168
    /* 54A08 800BD208 801F043C */   lui       $a0, (0x1F8000A8 >> 16)
  .L800BD20C:
    /* 54A0C 800BD20C 801F043C */  lui        $a0, (0x1F8000A8 >> 16)
  .L800BD210:
    /* 54A10 800BD210 A8008434 */  ori        $a0, $a0, (0x1F8000A8 & 0xFFFF)
    /* 54A14 800BD214 801F053C */  lui        $a1, (0x1F800098 >> 16)
    /* 54A18 800BD218 9800A534 */  ori        $a1, $a1, (0x1F800098 & 0xFFFF)
    /* 54A1C 800BD21C 8AF9020C */  jal        _vectorAdd
    /* 54A20 800BD220 84002626 */   addiu     $a2, $s1, 0x84
    /* 54A24 800BD224 801F053C */  lui        $a1, (0x1F800088 >> 16)
    /* 54A28 800BD228 8800A534 */  ori        $a1, $a1, (0x1F800088 & 0xFFFF)
    /* 54A2C 800BD22C 0F80023C */  lui        $v0, %hi(D_800F4BA4)
    /* 54A30 800BD230 A44B448C */  lw         $a0, %lo(D_800F4BA4)($v0)
    /* 54A34 800BD234 2000A38C */  lw         $v1, 0x20($a1)
    /* 54A38 800BD238 7C02828C */  lw         $v0, 0x27C($a0)
    /* 54A3C 800BD23C 00000000 */  nop
    /* 54A40 800BD240 0E006214 */  bne        $v1, $v0, .L800BD27C
    /* 54A44 800BD244 0F80023C */   lui       $v0, %hi(D_800F4BA4)
    /* 54A48 800BD248 2400A38C */  lw         $v1, 0x24($a1)
    /* 54A4C 800BD24C 8002828C */  lw         $v0, 0x280($a0)
    /* 54A50 800BD250 00000000 */  nop
    /* 54A54 800BD254 09006214 */  bne        $v1, $v0, .L800BD27C
    /* 54A58 800BD258 0F80023C */   lui       $v0, %hi(D_800F4BA4)
    /* 54A5C 800BD25C 2800A38C */  lw         $v1, 0x28($a1)
    /* 54A60 800BD260 8402828C */  lw         $v0, 0x284($a0)
    /* 54A64 800BD264 00000000 */  nop
    /* 54A68 800BD268 04006214 */  bne        $v1, $v0, .L800BD27C
    /* 54A6C 800BD26C 0F80023C */   lui       $v0, %hi(D_800F4BA4)
    /* 54A70 800BD270 05002292 */  lbu        $v0, 0x5($s1)
    /* 54A74 800BD274 A8F40208 */  j          .L800BD2A0
    /* 54A78 800BD278 040022A2 */   sb        $v0, 0x4($s1)
  .L800BD27C:
    /* 54A7C 800BD27C A44B448C */  lw         $a0, %lo(D_800F4BA4)($v0)
    /* 54A80 800BD280 84003026 */  addiu      $s0, $s1, 0x84
    /* 54A84 800BD284 21280002 */  addu       $a1, $s0, $zero
    /* 54A88 800BD288 C7F9020C */  jal        _copyVector
    /* 54A8C 800BD28C 7C028424 */   addiu     $a0, $a0, 0x27C
    /* 54A90 800BD290 21200002 */  addu       $a0, $s0, $zero
    /* 54A94 800BD294 801F053C */  lui        $a1, (0x1F8000A8 >> 16)
    /* 54A98 800BD298 C7F9020C */  jal        _copyVector
    /* 54A9C 800BD29C A800A534 */   ori       $a1, $a1, (0x1F8000A8 & 0xFFFF)
  .L800BD2A0:
    /* 54AA0 800BD2A0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 54AA4 800BD2A4 1800B28F */  lw         $s2, 0x18($sp)
    /* 54AA8 800BD2A8 1400B18F */  lw         $s1, 0x14($sp)
    /* 54AAC 800BD2AC 1000B08F */  lw         $s0, 0x10($sp)
    /* 54AB0 800BD2B0 0800E003 */  jr         $ra
    /* 54AB4 800BD2B4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800BCFB4
