nonmatching _setMenuItemClut, 0x120

glabel _setMenuItemClut
    /* 7AAC 800702AC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 7AB0 800702B0 21708000 */  addu       $t6, $a0, $zero
    /* 7AB4 800702B4 2160A000 */  addu       $t4, $a1, $zero
    /* 7AB8 800702B8 01000B24 */  addiu      $t3, $zero, 0x1
    /* 7ABC 800702BC 0780023C */  lui        $v0, %hi(_menuItemTextClut)
    /* 7AC0 800702C0 B44A4D24 */  addiu      $t5, $v0, %lo(_menuItemTextClut)
    /* 7AC4 800702C4 1A00AA27 */  addiu      $t2, $sp, 0x1A
    /* 7AC8 800702C8 40390700 */  sll        $a3, $a3, 5
    /* 7ACC 800702CC 0200E924 */  addiu      $t1, $a3, 0x2
    /* 7AD0 800702D0 40310600 */  sll        $a2, $a2, 5
    /* 7AD4 800702D4 0200C824 */  addiu      $t0, $a2, 0x2
    /* 7AD8 800702D8 3800BFAF */  sw         $ra, 0x38($sp)
    /* 7ADC 800702DC 1800A0A7 */  sh         $zero, 0x18($sp)
  .L800702E0:
    /* 7AE0 800702E0 21100D01 */  addu       $v0, $t0, $t5
    /* 7AE4 800702E4 00004394 */  lhu        $v1, 0x0($v0)
    /* 7AE8 800702E8 21102D01 */  addu       $v0, $t1, $t5
    /* 7AEC 800702EC 00004294 */  lhu        $v0, 0x0($v0)
    /* 7AF0 800702F0 E0036530 */  andi       $a1, $v1, 0x3E0
    /* 7AF4 800702F4 007C6630 */  andi       $a2, $v1, 0x7C00
    /* 7AF8 800702F8 1F006330 */  andi       $v1, $v1, 0x1F
    /* 7AFC 800702FC E0034430 */  andi       $a0, $v0, 0x3E0
    /* 7B00 80070300 007C4730 */  andi       $a3, $v0, 0x7C00
    /* 7B04 80070304 1F004230 */  andi       $v0, $v0, 0x1F
    /* 7B08 80070308 23104300 */  subu       $v0, $v0, $v1
    /* 7B0C 8007030C 18004C00 */  mult       $v0, $t4
    /* 7B10 80070310 12C00000 */  mflo       $t8
    /* 7B14 80070314 23208500 */  subu       $a0, $a0, $a1
    /* 7B18 80070318 00000000 */  nop
    /* 7B1C 8007031C 18008C00 */  mult       $a0, $t4
    /* 7B20 80070320 02002925 */  addiu      $t1, $t1, 0x2
    /* 7B24 80070324 12200000 */  mflo       $a0
    /* 7B28 80070328 02000825 */  addiu      $t0, $t0, 0x2
    /* 7B2C 8007032C 2338E600 */  subu       $a3, $a3, $a2
    /* 7B30 80070330 1800EC00 */  mult       $a3, $t4
    /* 7B34 80070334 01006B25 */  addiu      $t3, $t3, 0x1
    /* 7B38 80070338 0700023C */  lui        $v0, (0x7C000 >> 16)
    /* 7B3C 8007033C 00C04234 */  ori        $v0, $v0, (0x7C000 & 0xFFFF)
    /* 7B40 80070340 00190300 */  sll        $v1, $v1, 4
    /* 7B44 80070344 00290500 */  sll        $a1, $a1, 4
    /* 7B48 80070348 00310600 */  sll        $a2, $a2, 4
    /* 7B4C 8007034C 21187800 */  addu       $v1, $v1, $t8
    /* 7B50 80070350 F0016330 */  andi       $v1, $v1, 0x1F0
    /* 7B54 80070354 2128A400 */  addu       $a1, $a1, $a0
    /* 7B58 80070358 003EA530 */  andi       $a1, $a1, 0x3E00
    /* 7B5C 8007035C 25186500 */  or         $v1, $v1, $a1
    /* 7B60 80070360 12380000 */  mflo       $a3
    /* 7B64 80070364 2130C700 */  addu       $a2, $a2, $a3
    /* 7B68 80070368 2430C200 */  and        $a2, $a2, $v0
    /* 7B6C 8007036C 25186600 */  or         $v1, $v1, $a2
    /* 7B70 80070370 03190300 */  sra        $v1, $v1, 4
    /* 7B74 80070374 00806334 */  ori        $v1, $v1, 0x8000
    /* 7B78 80070378 000043A5 */  sh         $v1, 0x0($t2)
    /* 7B7C 8007037C 10006229 */  slti       $v0, $t3, 0x10
    /* 7B80 80070380 D7FF4014 */  bnez       $v0, .L800702E0
    /* 7B84 80070384 02004A25 */   addiu     $t2, $t2, 0x2
    /* 7B88 80070388 1000A427 */  addiu      $a0, $sp, 0x10
    /* 7B8C 8007038C E0010224 */  addiu      $v0, $zero, 0x1E0
    /* 7B90 80070390 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 7B94 80070394 8001C225 */  addiu      $v0, $t6, 0x180
    /* 7B98 80070398 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 7B9C 8007039C 10000224 */  addiu      $v0, $zero, 0x10
    /* 7BA0 800703A0 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 7BA4 800703A4 01000224 */  addiu      $v0, $zero, 0x1
    /* 7BA8 800703A8 1800A527 */  addiu      $a1, $sp, 0x18
    /* 7BAC 800703AC 3FA2000C */  jal        LoadImage
    /* 7BB0 800703B0 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 7BB4 800703B4 94A1000C */  jal        DrawSync
    /* 7BB8 800703B8 21200000 */   addu      $a0, $zero, $zero
    /* 7BBC 800703BC 3800BF8F */  lw         $ra, 0x38($sp)
    /* 7BC0 800703C0 00000000 */  nop
    /* 7BC4 800703C4 0800E003 */  jr         $ra
    /* 7BC8 800703C8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _setMenuItemClut
