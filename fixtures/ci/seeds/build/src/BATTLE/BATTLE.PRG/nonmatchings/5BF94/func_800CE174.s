nonmatching func_800CE174, 0x4D0

glabel func_800CE174
    /* 65974 800CE174 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 65978 800CE178 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6597C 800CE17C 21808000 */  addu       $s0, $a0, $zero
    /* 65980 800CE180 2000B2AF */  sw         $s2, 0x20($sp)
    /* 65984 800CE184 2190C000 */  addu       $s2, $a2, $zero
    /* 65988 800CE188 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 6598C 800CE18C 02000224 */  addiu      $v0, $zero, 0x2
    /* 65990 800CE190 3000BFAF */  sw         $ra, 0x30($sp)
    /* 65994 800CE194 2800B4AF */  sw         $s4, 0x28($sp)
    /* 65998 800CE198 2400B3AF */  sw         $s3, 0x24($sp)
    /* 6599C 800CE19C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 659A0 800CE1A0 0800118E */  lw         $s1, 0x8($s0)
    /* 659A4 800CE1A4 1600A210 */  beq        $a1, $v0, .L800CE200
    /* 659A8 800CE1A8 01001524 */   addiu     $s5, $zero, 0x1
    /* 659AC 800CE1AC 0300A22C */  sltiu      $v0, $a1, 0x3
    /* 659B0 800CE1B0 05004010 */  beqz       $v0, .L800CE1C8
    /* 659B4 800CE1B4 03000224 */   addiu     $v0, $zero, 0x3
    /* 659B8 800CE1B8 0900B510 */  beq        $a1, $s5, .L800CE1E0
    /* 659BC 800CE1BC 2110A002 */   addu      $v0, $s5, $zero
    /* 659C0 800CE1C0 88390308 */  j          .L800CE620
    /* 659C4 800CE1C4 00000000 */   nop
  .L800CE1C8:
    /* 659C8 800CE1C8 0D01A210 */  beq        $a1, $v0, .L800CE600
    /* 659CC 800CE1CC 04000224 */   addiu     $v0, $zero, 0x4
    /* 659D0 800CE1D0 0E01A210 */  beq        $a1, $v0, .L800CE60C
    /* 659D4 800CE1D4 2110A002 */   addu      $v0, $s5, $zero
    /* 659D8 800CE1D8 88390308 */  j          .L800CE620
    /* 659DC 800CE1DC 00000000 */   nop
  .L800CE1E0:
    /* 659E0 800CE1E0 8F0F010C */  jal        vs_main_allocHeapR
    /* 659E4 800CE1E4 B4000424 */   addiu     $a0, $zero, 0xB4
    /* 659E8 800CE1E8 21884000 */  addu       $s1, $v0, $zero
    /* 659EC 800CE1EC 080011AE */  sw         $s1, 0x8($s0)
    /* 659F0 800CE1F0 040020AE */  sw         $zero, 0x4($s1)
    /* 659F4 800CE1F4 080020AE */  sw         $zero, 0x8($s1)
    /* 659F8 800CE1F8 87390308 */  j          .L800CE61C
    /* 659FC 800CE1FC 000032AE */   sw        $s2, 0x0($s1)
  .L800CE200:
    /* 65A00 800CE200 21380000 */  addu       $a3, $zero, $zero
    /* 65A04 800CE204 00002492 */  lbu        $a0, 0x0($s1)
    /* 65A08 800CE208 0400228E */  lw         $v0, 0x4($s1)
    /* 65A0C 800CE20C 01002592 */  lbu        $a1, 0x1($s1)
    /* 65A10 800CE210 01004224 */  addiu      $v0, $v0, 0x1
    /* 65A14 800CE214 07004230 */  andi       $v0, $v0, 0x7
    /* 65A18 800CE218 C0300200 */  sll        $a2, $v0, 3
    /* 65A1C 800CE21C 0C00C624 */  addiu      $a2, $a2, 0xC
    /* 65A20 800CE220 21302602 */  addu       $a2, $s1, $a2
    /* 65A24 800CE224 BE86020C */  jal        func_800A1AF8
    /* 65A28 800CE228 040022AE */   sw        $v0, 0x4($s1)
    /* 65A2C 800CE22C 01000724 */  addiu      $a3, $zero, 0x1
    /* 65A30 800CE230 00002492 */  lbu        $a0, 0x0($s1)
    /* 65A34 800CE234 0400268E */  lw         $a2, 0x4($s1)
    /* 65A38 800CE238 01002592 */  lbu        $a1, 0x1($s1)
    /* 65A3C 800CE23C C0300600 */  sll        $a2, $a2, 3
    /* 65A40 800CE240 4C00C624 */  addiu      $a2, $a2, 0x4C
    /* 65A44 800CE244 BE86020C */  jal        func_800A1AF8
    /* 65A48 800CE248 21302602 */   addu      $a2, $s1, $a2
    /* 65A4C 800CE24C 0800248E */  lw         $a0, 0x8($s1)
    /* 65A50 800CE250 00000000 */  nop
    /* 65A54 800CE254 01008324 */  addiu      $v1, $a0, 0x1
    /* 65A58 800CE258 04006228 */  slti       $v0, $v1, 0x4
    /* 65A5C 800CE25C DD004014 */  bnez       $v0, .L800CE5D4
    /* 65A60 800CE260 080023AE */   sw        $v1, 0x8($s1)
    /* 65A64 800CE264 09006228 */  slti       $v0, $v1, 0x9
    /* 65A68 800CE268 02004010 */  beqz       $v0, .L800CE274
    /* 65A6C 800CE26C 05001424 */   addiu     $s4, $zero, 0x5
    /* 65A70 800CE270 FEFF9424 */  addiu      $s4, $a0, -0x2
  .L800CE274:
    /* 65A74 800CE274 801F103C */  lui        $s0, %hi(D_1F800014_mat)
    /* 65A78 800CE278 14001026 */  addiu      $s0, $s0, %lo(D_1F800014_mat)
    /* 65A7C 800CE27C 6605010C */  jal        SetRotMatrix
    /* 65A80 800CE280 21200002 */   addu      $a0, $s0, $zero
    /* 65A84 800CE284 5E05010C */  jal        SetTransMatrix
    /* 65A88 800CE288 21200002 */   addu      $a0, $s0, $zero
    /* 65A8C 800CE28C 00F01024 */  addiu      $s0, $zero, -0x1000
    /* 65A90 800CE290 0400278E */  lw         $a3, 0x4($s1)
    /* 65A94 800CE294 8C002226 */  addiu      $v0, $s1, 0x8C
    /* 65A98 800CE298 1000B0AF */  sw         $s0, 0x10($sp)
    /* 65A9C 800CE29C 1400A2AF */  sw         $v0, 0x14($sp)
    /* 65AA0 800CE2A0 C0200700 */  sll        $a0, $a3, 3
    /* 65AA4 800CE2A4 0C008424 */  addiu      $a0, $a0, 0xC
    /* 65AA8 800CE2A8 21202402 */  addu       $a0, $s1, $a0
    /* 65AAC 800CE2AC FFFFE524 */  addiu      $a1, $a3, -0x1
    /* 65AB0 800CE2B0 0700A530 */  andi       $a1, $a1, 0x7
    /* 65AB4 800CE2B4 C0280500 */  sll        $a1, $a1, 3
    /* 65AB8 800CE2B8 0C00A524 */  addiu      $a1, $a1, 0xC
    /* 65ABC 800CE2BC 21282502 */  addu       $a1, $s1, $a1
    /* 65AC0 800CE2C0 FEFFE624 */  addiu      $a2, $a3, -0x2
    /* 65AC4 800CE2C4 0700C630 */  andi       $a2, $a2, 0x7
    /* 65AC8 800CE2C8 C0300600 */  sll        $a2, $a2, 3
    /* 65ACC 800CE2CC 0C00C624 */  addiu      $a2, $a2, 0xC
    /* 65AD0 800CE2D0 21302602 */  addu       $a2, $s1, $a2
    /* 65AD4 800CE2D4 FDFFE724 */  addiu      $a3, $a3, -0x3
    /* 65AD8 800CE2D8 0700E730 */  andi       $a3, $a3, 0x7
    /* 65ADC 800CE2DC C0380700 */  sll        $a3, $a3, 3
    /* 65AE0 800CE2E0 0C00E724 */  addiu      $a3, $a3, 0xC
    /* 65AE4 800CE2E4 E444030C */  jal        func_800D1390
    /* 65AE8 800CE2E8 21382702 */   addu      $a3, $s1, $a3
    /* 65AEC 800CE2EC 00F81324 */  addiu      $s3, $zero, -0x800
    /* 65AF0 800CE2F0 0400278E */  lw         $a3, 0x4($s1)
    /* 65AF4 800CE2F4 9C002226 */  addiu      $v0, $s1, 0x9C
    /* 65AF8 800CE2F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 65AFC 800CE2FC 1400A2AF */  sw         $v0, 0x14($sp)
    /* 65B00 800CE300 C0200700 */  sll        $a0, $a3, 3
    /* 65B04 800CE304 4C008424 */  addiu      $a0, $a0, 0x4C
    /* 65B08 800CE308 21202402 */  addu       $a0, $s1, $a0
    /* 65B0C 800CE30C FFFFE524 */  addiu      $a1, $a3, -0x1
    /* 65B10 800CE310 0700A530 */  andi       $a1, $a1, 0x7
    /* 65B14 800CE314 C0280500 */  sll        $a1, $a1, 3
    /* 65B18 800CE318 4C00A524 */  addiu      $a1, $a1, 0x4C
    /* 65B1C 800CE31C 21282502 */  addu       $a1, $s1, $a1
    /* 65B20 800CE320 FEFFE624 */  addiu      $a2, $a3, -0x2
    /* 65B24 800CE324 0700C630 */  andi       $a2, $a2, 0x7
    /* 65B28 800CE328 C0300600 */  sll        $a2, $a2, 3
    /* 65B2C 800CE32C 4C00C624 */  addiu      $a2, $a2, 0x4C
    /* 65B30 800CE330 21302602 */  addu       $a2, $s1, $a2
    /* 65B34 800CE334 FDFFE724 */  addiu      $a3, $a3, -0x3
    /* 65B38 800CE338 0700E730 */  andi       $a3, $a3, 0x7
    /* 65B3C 800CE33C C0380700 */  sll        $a3, $a3, 3
    /* 65B40 800CE340 4C00E724 */  addiu      $a3, $a3, 0x4C
    /* 65B44 800CE344 E444030C */  jal        func_800D1390
    /* 65B48 800CE348 21382702 */   addu      $a3, $s1, $a3
    /* 65B4C 800CE34C 01008226 */  addiu      $v0, $s4, 0x1
    /* 65B50 800CE350 40800200 */  sll        $s0, $v0, 1
  .L800CE354:
    /* 65B54 800CE354 0400278E */  lw         $a3, 0x4($s1)
    /* 65B58 800CE358 94002226 */  addiu      $v0, $s1, 0x94
    /* 65B5C 800CE35C 1000B3AF */  sw         $s3, 0x10($sp)
    /* 65B60 800CE360 1400A2AF */  sw         $v0, 0x14($sp)
    /* 65B64 800CE364 C0200700 */  sll        $a0, $a3, 3
    /* 65B68 800CE368 0C008424 */  addiu      $a0, $a0, 0xC
    /* 65B6C 800CE36C 21202402 */  addu       $a0, $s1, $a0
    /* 65B70 800CE370 FFFFE524 */  addiu      $a1, $a3, -0x1
    /* 65B74 800CE374 0700A530 */  andi       $a1, $a1, 0x7
    /* 65B78 800CE378 C0280500 */  sll        $a1, $a1, 3
    /* 65B7C 800CE37C 0C00A524 */  addiu      $a1, $a1, 0xC
    /* 65B80 800CE380 21282502 */  addu       $a1, $s1, $a1
    /* 65B84 800CE384 FEFFE624 */  addiu      $a2, $a3, -0x2
    /* 65B88 800CE388 0700C630 */  andi       $a2, $a2, 0x7
    /* 65B8C 800CE38C C0300600 */  sll        $a2, $a2, 3
    /* 65B90 800CE390 0C00C624 */  addiu      $a2, $a2, 0xC
    /* 65B94 800CE394 21302602 */  addu       $a2, $s1, $a2
    /* 65B98 800CE398 FDFFE724 */  addiu      $a3, $a3, -0x3
    /* 65B9C 800CE39C 0700E730 */  andi       $a3, $a3, 0x7
    /* 65BA0 800CE3A0 C0380700 */  sll        $a3, $a3, 3
    /* 65BA4 800CE3A4 0C00E724 */  addiu      $a3, $a3, 0xC
    /* 65BA8 800CE3A8 E444030C */  jal        func_800D1390
    /* 65BAC 800CE3AC 21382702 */   addu      $a3, $s1, $a3
    /* 65BB0 800CE3B0 0400278E */  lw         $a3, 0x4($s1)
    /* 65BB4 800CE3B4 1000B3AF */  sw         $s3, 0x10($sp)
    /* 65BB8 800CE3B8 00087326 */  addiu      $s3, $s3, 0x800
    /* 65BBC 800CE3BC A4002226 */  addiu      $v0, $s1, 0xA4
    /* 65BC0 800CE3C0 1400A2AF */  sw         $v0, 0x14($sp)
    /* 65BC4 800CE3C4 C0200700 */  sll        $a0, $a3, 3
    /* 65BC8 800CE3C8 4C008424 */  addiu      $a0, $a0, 0x4C
    /* 65BCC 800CE3CC 21202402 */  addu       $a0, $s1, $a0
    /* 65BD0 800CE3D0 FFFFE524 */  addiu      $a1, $a3, -0x1
    /* 65BD4 800CE3D4 0700A530 */  andi       $a1, $a1, 0x7
    /* 65BD8 800CE3D8 C0280500 */  sll        $a1, $a1, 3
    /* 65BDC 800CE3DC 4C00A524 */  addiu      $a1, $a1, 0x4C
    /* 65BE0 800CE3E0 21282502 */  addu       $a1, $s1, $a1
    /* 65BE4 800CE3E4 FEFFE624 */  addiu      $a2, $a3, -0x2
    /* 65BE8 800CE3E8 0700C630 */  andi       $a2, $a2, 0x7
    /* 65BEC 800CE3EC C0300600 */  sll        $a2, $a2, 3
    /* 65BF0 800CE3F0 4C00C624 */  addiu      $a2, $a2, 0x4C
    /* 65BF4 800CE3F4 21302602 */  addu       $a2, $s1, $a2
    /* 65BF8 800CE3F8 FDFFE724 */  addiu      $a3, $a3, -0x3
    /* 65BFC 800CE3FC 0700E730 */  andi       $a3, $a3, 0x7
    /* 65C00 800CE400 C0380700 */  sll        $a3, $a3, 3
    /* 65C04 800CE404 4C00E724 */  addiu      $a3, $a3, 0x4C
    /* 65C08 800CE408 E444030C */  jal        func_800D1390
    /* 65C0C 800CE40C 21382702 */   addu      $a3, $s1, $a3
    /* 65C10 800CE410 21202002 */  addu       $a0, $s1, $zero
    /* 65C14 800CE414 C22F1000 */  srl        $a1, $s0, 31
    /* 65C18 800CE418 21280502 */  addu       $a1, $s0, $a1
    /* 65C1C 800CE41C 43280500 */  sra        $a1, $a1, 1
    /* 65C20 800CE420 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 65C24 800CE424 C2371000 */  srl        $a2, $s0, 31
    /* 65C28 800CE428 21300602 */  addu       $a2, $s0, $a2
    /* 65C2C 800CE42C 2F37030C */  jal        func_800CDCBC
    /* 65C30 800CE430 43300600 */   sra       $a2, $a2, 1
    /* 65C34 800CE434 9700288A */  lwl        $t0, 0x97($s1)
    /* 65C38 800CE438 9400289A */  lwr        $t0, 0x94($s1)
    /* 65C3C 800CE43C 9B00298A */  lwl        $t1, 0x9B($s1)
    /* 65C40 800CE440 9800299A */  lwr        $t1, 0x98($s1)
    /* 65C44 800CE444 8F0028AA */  swl        $t0, 0x8F($s1)
    /* 65C48 800CE448 8C0028BA */  swr        $t0, 0x8C($s1)
    /* 65C4C 800CE44C 930029AA */  swl        $t1, 0x93($s1)
    /* 65C50 800CE450 900029BA */  swr        $t1, 0x90($s1)
    /* 65C54 800CE454 A700288A */  lwl        $t0, 0xA7($s1)
    /* 65C58 800CE458 A400289A */  lwr        $t0, 0xA4($s1)
    /* 65C5C 800CE45C AB00298A */  lwl        $t1, 0xAB($s1)
    /* 65C60 800CE460 A800299A */  lwr        $t1, 0xA8($s1)
    /* 65C64 800CE464 9F0028AA */  swl        $t0, 0x9F($s1)
    /* 65C68 800CE468 9C0028BA */  swr        $t0, 0x9C($s1)
    /* 65C6C 800CE46C A30029AA */  swl        $t1, 0xA3($s1)
    /* 65C70 800CE470 A00029BA */  swr        $t1, 0xA0($s1)
    /* 65C74 800CE474 B7FF6006 */  bltz       $s3, .L800CE354
    /* 65C78 800CE478 00000000 */   nop
    /* 65C7C 800CE47C 5500801A */  blez       $s4, .L800CE5D4
    /* 65C80 800CE480 21980000 */   addu      $s3, $zero, $zero
  .L800CE484:
    /* 65C84 800CE484 21900000 */  addu       $s2, $zero, $zero
  .L800CE488:
    /* 65C88 800CE488 0400278E */  lw         $a3, 0x4($s1)
    /* 65C8C 800CE48C 94002226 */  addiu      $v0, $s1, 0x94
    /* 65C90 800CE490 1000B2AF */  sw         $s2, 0x10($sp)
    /* 65C94 800CE494 1400A2AF */  sw         $v0, 0x14($sp)
    /* 65C98 800CE498 2338F300 */  subu       $a3, $a3, $s3
    /* 65C9C 800CE49C 0700E430 */  andi       $a0, $a3, 0x7
    /* 65CA0 800CE4A0 C0200400 */  sll        $a0, $a0, 3
    /* 65CA4 800CE4A4 0C008424 */  addiu      $a0, $a0, 0xC
    /* 65CA8 800CE4A8 21202402 */  addu       $a0, $s1, $a0
    /* 65CAC 800CE4AC FFFFE524 */  addiu      $a1, $a3, -0x1
    /* 65CB0 800CE4B0 0700A530 */  andi       $a1, $a1, 0x7
    /* 65CB4 800CE4B4 C0280500 */  sll        $a1, $a1, 3
    /* 65CB8 800CE4B8 0C00A524 */  addiu      $a1, $a1, 0xC
    /* 65CBC 800CE4BC 21282502 */  addu       $a1, $s1, $a1
    /* 65CC0 800CE4C0 FEFFE624 */  addiu      $a2, $a3, -0x2
    /* 65CC4 800CE4C4 0700C630 */  andi       $a2, $a2, 0x7
    /* 65CC8 800CE4C8 C0300600 */  sll        $a2, $a2, 3
    /* 65CCC 800CE4CC 0C00C624 */  addiu      $a2, $a2, 0xC
    /* 65CD0 800CE4D0 21302602 */  addu       $a2, $s1, $a2
    /* 65CD4 800CE4D4 FDFFE724 */  addiu      $a3, $a3, -0x3
    /* 65CD8 800CE4D8 0700E730 */  andi       $a3, $a3, 0x7
    /* 65CDC 800CE4DC C0380700 */  sll        $a3, $a3, 3
    /* 65CE0 800CE4E0 0C00E724 */  addiu      $a3, $a3, 0xC
    /* 65CE4 800CE4E4 E444030C */  jal        func_800D1390
    /* 65CE8 800CE4E8 21382702 */   addu      $a3, $s1, $a3
    /* 65CEC 800CE4EC 0400278E */  lw         $a3, 0x4($s1)
    /* 65CF0 800CE4F0 1000B2AF */  sw         $s2, 0x10($sp)
    /* 65CF4 800CE4F4 00085226 */  addiu      $s2, $s2, 0x800
    /* 65CF8 800CE4F8 A4002226 */  addiu      $v0, $s1, 0xA4
    /* 65CFC 800CE4FC 1400A2AF */  sw         $v0, 0x14($sp)
    /* 65D00 800CE500 2338F300 */  subu       $a3, $a3, $s3
    /* 65D04 800CE504 0700E430 */  andi       $a0, $a3, 0x7
    /* 65D08 800CE508 C0200400 */  sll        $a0, $a0, 3
    /* 65D0C 800CE50C 4C008424 */  addiu      $a0, $a0, 0x4C
    /* 65D10 800CE510 21202402 */  addu       $a0, $s1, $a0
    /* 65D14 800CE514 FFFFE524 */  addiu      $a1, $a3, -0x1
    /* 65D18 800CE518 0700A530 */  andi       $a1, $a1, 0x7
    /* 65D1C 800CE51C C0280500 */  sll        $a1, $a1, 3
    /* 65D20 800CE520 4C00A524 */  addiu      $a1, $a1, 0x4C
    /* 65D24 800CE524 21282502 */  addu       $a1, $s1, $a1
    /* 65D28 800CE528 FEFFE624 */  addiu      $a2, $a3, -0x2
    /* 65D2C 800CE52C 0700C630 */  andi       $a2, $a2, 0x7
    /* 65D30 800CE530 C0300600 */  sll        $a2, $a2, 3
    /* 65D34 800CE534 4C00C624 */  addiu      $a2, $a2, 0x4C
    /* 65D38 800CE538 21302602 */  addu       $a2, $s1, $a2
    /* 65D3C 800CE53C FDFFE724 */  addiu      $a3, $a3, -0x3
    /* 65D40 800CE540 0700E730 */  andi       $a3, $a3, 0x7
    /* 65D44 800CE544 C0380700 */  sll        $a3, $a3, 3
    /* 65D48 800CE548 4C00E724 */  addiu      $a3, $a3, 0x4C
    /* 65D4C 800CE54C E444030C */  jal        func_800D1390
    /* 65D50 800CE550 21382702 */   addu      $a3, $s1, $a3
    /* 65D54 800CE554 21202002 */  addu       $a0, $s1, $zero
    /* 65D58 800CE558 C22F1000 */  srl        $a1, $s0, 31
    /* 65D5C 800CE55C 21280502 */  addu       $a1, $s0, $a1
    /* 65D60 800CE560 43280500 */  sra        $a1, $a1, 1
    /* 65D64 800CE564 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 65D68 800CE568 C2371000 */  srl        $a2, $s0, 31
    /* 65D6C 800CE56C 21300602 */  addu       $a2, $s0, $a2
    /* 65D70 800CE570 2F37030C */  jal        func_800CDCBC
    /* 65D74 800CE574 43300600 */   sra       $a2, $a2, 1
    /* 65D78 800CE578 0010422A */  slti       $v0, $s2, 0x1000
    /* 65D7C 800CE57C 9700288A */  lwl        $t0, 0x97($s1)
    /* 65D80 800CE580 9400289A */  lwr        $t0, 0x94($s1)
    /* 65D84 800CE584 9B00298A */  lwl        $t1, 0x9B($s1)
    /* 65D88 800CE588 9800299A */  lwr        $t1, 0x98($s1)
    /* 65D8C 800CE58C 8F0028AA */  swl        $t0, 0x8F($s1)
    /* 65D90 800CE590 8C0028BA */  swr        $t0, 0x8C($s1)
    /* 65D94 800CE594 930029AA */  swl        $t1, 0x93($s1)
    /* 65D98 800CE598 900029BA */  swr        $t1, 0x90($s1)
    /* 65D9C 800CE59C A700288A */  lwl        $t0, 0xA7($s1)
    /* 65DA0 800CE5A0 A400289A */  lwr        $t0, 0xA4($s1)
    /* 65DA4 800CE5A4 AB00298A */  lwl        $t1, 0xAB($s1)
    /* 65DA8 800CE5A8 A800299A */  lwr        $t1, 0xA8($s1)
    /* 65DAC 800CE5AC 9F0028AA */  swl        $t0, 0x9F($s1)
    /* 65DB0 800CE5B0 9C0028BA */  swr        $t0, 0x9C($s1)
    /* 65DB4 800CE5B4 A30029AA */  swl        $t1, 0xA3($s1)
    /* 65DB8 800CE5B8 A00029BA */  swr        $t1, 0xA0($s1)
    /* 65DBC 800CE5BC B2FF4014 */  bnez       $v0, .L800CE488
    /* 65DC0 800CE5C0 00000000 */   nop
    /* 65DC4 800CE5C4 01007326 */  addiu      $s3, $s3, 0x1
    /* 65DC8 800CE5C8 2A107402 */  slt        $v0, $s3, $s4
    /* 65DCC 800CE5CC ADFF4014 */  bnez       $v0, .L800CE484
    /* 65DD0 800CE5D0 00000000 */   nop
  .L800CE5D4:
    /* 65DD4 800CE5D4 03002392 */  lbu        $v1, 0x3($s1)
    /* 65DD8 800CE5D8 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 65DDC 800CE5DC 02006210 */  beq        $v1, $v0, .L800CE5E8
    /* 65DE0 800CE5E0 FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 65DE4 800CE5E4 030022A2 */  sb         $v0, 0x3($s1)
  .L800CE5E8:
    /* 65DE8 800CE5E8 03002292 */  lbu        $v0, 0x3($s1)
    /* 65DEC 800CE5EC 00000000 */  nop
    /* 65DF0 800CE5F0 0B004014 */  bnez       $v0, .L800CE620
    /* 65DF4 800CE5F4 2110A002 */   addu      $v0, $s5, $zero
    /* 65DF8 800CE5F8 87390308 */  j          .L800CE61C
    /* 65DFC 800CE5FC 21A80000 */   addu      $s5, $zero, $zero
  .L800CE600:
    /* 65E00 800CE600 08000224 */  addiu      $v0, $zero, 0x8
    /* 65E04 800CE604 87390308 */  j          .L800CE61C
    /* 65E08 800CE608 030022A2 */   sb        $v0, 0x3($s1)
  .L800CE60C:
    /* 65E0C 800CE60C 180F010C */  jal        vs_main_freeHeapR
    /* 65E10 800CE610 21202002 */   addu      $a0, $s1, $zero
    /* 65E14 800CE614 080000AE */  sw         $zero, 0x8($s0)
    /* 65E18 800CE618 21A80000 */  addu       $s5, $zero, $zero
  .L800CE61C:
    /* 65E1C 800CE61C 2110A002 */  addu       $v0, $s5, $zero
  .L800CE620:
    /* 65E20 800CE620 3000BF8F */  lw         $ra, 0x30($sp)
    /* 65E24 800CE624 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 65E28 800CE628 2800B48F */  lw         $s4, 0x28($sp)
    /* 65E2C 800CE62C 2400B38F */  lw         $s3, 0x24($sp)
    /* 65E30 800CE630 2000B28F */  lw         $s2, 0x20($sp)
    /* 65E34 800CE634 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 65E38 800CE638 1800B08F */  lw         $s0, 0x18($sp)
    /* 65E3C 800CE63C 0800E003 */  jr         $ra
    /* 65E40 800CE640 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800CE174
