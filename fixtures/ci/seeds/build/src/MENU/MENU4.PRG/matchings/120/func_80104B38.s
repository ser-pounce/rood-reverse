nonmatching func_80104B38, 0xD4

glabel func_80104B38
    /* 2338 80104B38 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 233C 80104B3C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 2340 80104B40 21808000 */  addu       $s0, $a0, $zero
    /* 2344 80104B44 08000224 */  addiu      $v0, $zero, 0x8
    /* 2348 80104B48 1000A2AF */  sw         $v0, 0x10($sp)
    /* 234C 80104B4C 1080023C */  lui        $v0, %hi(D_80107448)
    /* 2350 80104B50 48744324 */  addiu      $v1, $v0, %lo(D_80107448)
    /* 2354 80104B54 0200022A */  slti       $v0, $s0, 0x2
    /* 2358 80104B58 04004010 */  beqz       $v0, .L80104B6C
    /* 235C 80104B5C 1C00BFAF */   sw        $ra, 0x1C($sp)
    /* 2360 80104B60 09000226 */  addiu      $v0, $s0, 0x9
    /* 2364 80104B64 DC120408 */  j          .L80104B70
    /* 2368 80104B68 40100200 */   sll       $v0, $v0, 1
  .L80104B6C:
    /* 236C 80104B6C 16000224 */  addiu      $v0, $zero, 0x16
  .L80104B70:
    /* 2370 80104B70 21106200 */  addu       $v0, $v1, $v0
    /* 2374 80104B74 20000424 */  addiu      $a0, $zero, 0x20
    /* 2378 80104B78 00004394 */  lhu        $v1, 0x0($v0)
    /* 237C 80104B7C 1080023C */  lui        $v0, %hi(D_80107448)
    /* 2380 80104B80 48744224 */  addiu      $v0, $v0, %lo(D_80107448)
    /* 2384 80104B84 5CFF0524 */  addiu      $a1, $zero, -0xA4
    /* 2388 80104B88 12000624 */  addiu      $a2, $zero, 0x12
    /* 238C 80104B8C A4000724 */  addiu      $a3, $zero, 0xA4
    /* 2390 80104B90 40180300 */  sll        $v1, $v1, 1
    /* 2394 80104B94 21186200 */  addu       $v1, $v1, $v0
    /* 2398 80104B98 9723030C */  jal        vs_battle_setMenuItem
    /* 239C 80104B9C 1400A3AF */   sw        $v1, 0x14($sp)
    /* 23A0 80104BA0 21184000 */  addu       $v1, $v0, $zero
    /* 23A4 80104BA4 1C000524 */  addiu      $a1, $zero, 0x1C
    /* 23A8 80104BA8 05000224 */  addiu      $v0, $zero, 0x5
    /* 23AC 80104BAC 000062A0 */  sb         $v0, 0x0($v1)
    /* 23B0 80104BB0 10000224 */  addiu      $v0, $zero, 0x10
    /* 23B4 80104BB4 180062A4 */  sh         $v0, 0x18($v1)
    /* 23B8 80104BB8 01000224 */  addiu      $v0, $zero, 0x1
    /* 23BC 80104BBC 03000016 */  bnez       $s0, .L80104BCC
    /* 23C0 80104BC0 060062A0 */   sb        $v0, 0x6($v1)
    /* 23C4 80104BC4 F7120408 */  j          .L80104BDC
    /* 23C8 80104BC8 18000524 */   addiu     $a1, $zero, 0x18
  .L80104BCC:
    /* 23CC 80104BCC 01000224 */  addiu      $v0, $zero, 0x1
    /* 23D0 80104BD0 03000216 */  bne        $s0, $v0, .L80104BE0
    /* 23D4 80104BD4 0A000426 */   addiu     $a0, $s0, 0xA
    /* 23D8 80104BD8 1B000524 */  addiu      $a1, $zero, 0x1B
  .L80104BDC:
    /* 23DC 80104BDC 0A000426 */  addiu      $a0, $s0, 0xA
  .L80104BE0:
    /* 23E0 80104BE0 9223030C */  jal        vs_battle_getMenuItem
    /* 23E4 80104BE4 090065A0 */   sb        $a1, 0x9($v1)
    /* 23E8 80104BE8 21184000 */  addu       $v1, $v0, $zero
    /* 23EC 80104BEC 03000224 */  addiu      $v0, $zero, 0x3
    /* 23F0 80104BF0 000062A0 */  sb         $v0, 0x0($v1)
    /* 23F4 80104BF4 12000224 */  addiu      $v0, $zero, 0x12
    /* 23F8 80104BF8 180062A4 */  sh         $v0, 0x18($v1)
    /* 23FC 80104BFC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2400 80104C00 1800B08F */  lw         $s0, 0x18($sp)
    /* 2404 80104C04 0800E003 */  jr         $ra
    /* 2408 80104C08 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80104B38
