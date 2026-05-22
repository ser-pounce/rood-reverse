nonmatching func_800BDBB4, 0xE8

glabel func_800BDBB4
    /* 553B4 800BDBB4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 553B8 800BDBB8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 553BC 800BDBBC 21808000 */  addu       $s0, $a0, $zero
    /* 553C0 800BDBC0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 553C4 800BDBC4 1E000286 */  lh         $v0, 0x1E($s0)
    /* 553C8 800BDBC8 00000000 */  nop
    /* 553CC 800BDBCC 03004014 */  bnez       $v0, .L800BDBDC
    /* 553D0 800BDBD0 0680023C */   lui       $v0, %hi(vs_gametime_tickspeed)
    /* 553D4 800BDBD4 23F70208 */  j          .L800BDC8C
    /* 553D8 800BDBD8 21100000 */   addu      $v0, $zero, $zero
  .L800BDBDC:
    /* 553DC 800BDBDC 4CE2428C */  lw         $v0, %lo(vs_gametime_tickspeed)($v0)
    /* 553E0 800BDBE0 1C000596 */  lhu        $a1, 0x1C($s0)
    /* 553E4 800BDBE4 01000492 */  lbu        $a0, 0x1($s0)
    /* 553E8 800BDBE8 1E000686 */  lh         $a2, 0x1E($s0)
    /* 553EC 800BDBEC 43100200 */  sra        $v0, $v0, 1
    /* 553F0 800BDBF0 2128A200 */  addu       $a1, $a1, $v0
    /* 553F4 800BDBF4 1C0005A6 */  sh         $a1, 0x1C($s0)
    /* 553F8 800BDBF8 002C0500 */  sll        $a1, $a1, 16
    /* 553FC 800BDBFC AFFF020C */  jal        func_800BFEBC
    /* 55400 800BDC00 032C0500 */   sra       $a1, $a1, 16
    /* 55404 800BDC04 801F043C */  lui        $a0, (0x1F800088 >> 16)
    /* 55408 800BDC08 88008434 */  ori        $a0, $a0, (0x1F800088 & 0xFFFF)
    /* 5540C 800BDC0C 000082AC */  sw         $v0, 0x0($a0)
    /* 55410 800BDC10 12000386 */  lh         $v1, 0x12($s0)
    /* 55414 800BDC14 00000000 */  nop
    /* 55418 800BDC18 18006200 */  mult       $v1, $v0
    /* 5541C 800BDC1C 0A000296 */  lhu        $v0, 0xA($s0)
    /* 55420 800BDC20 12380000 */  mflo       $a3
    /* 55424 800BDC24 031B0700 */  sra        $v1, $a3, 12
    /* 55428 800BDC28 21104300 */  addu       $v0, $v0, $v1
    /* 5542C 800BDC2C 14000386 */  lh         $v1, 0x14($s0)
    /* 55430 800BDC30 020002A6 */  sh         $v0, 0x2($s0)
    /* 55434 800BDC34 0000828C */  lw         $v0, 0x0($a0)
    /* 55438 800BDC38 00000000 */  nop
    /* 5543C 800BDC3C 18006200 */  mult       $v1, $v0
    /* 55440 800BDC40 0C000296 */  lhu        $v0, 0xC($s0)
    /* 55444 800BDC44 12380000 */  mflo       $a3
    /* 55448 800BDC48 031B0700 */  sra        $v1, $a3, 12
    /* 5544C 800BDC4C 21104300 */  addu       $v0, $v0, $v1
    /* 55450 800BDC50 16000386 */  lh         $v1, 0x16($s0)
    /* 55454 800BDC54 040002A6 */  sh         $v0, 0x4($s0)
    /* 55458 800BDC58 0000828C */  lw         $v0, 0x0($a0)
    /* 5545C 800BDC5C 00000000 */  nop
    /* 55460 800BDC60 18006200 */  mult       $v1, $v0
    /* 55464 800BDC64 1C000586 */  lh         $a1, 0x1C($s0)
    /* 55468 800BDC68 0E000296 */  lhu        $v0, 0xE($s0)
    /* 5546C 800BDC6C 1E000386 */  lh         $v1, 0x1E($s0)
    /* 55470 800BDC70 12380000 */  mflo       $a3
    /* 55474 800BDC74 03230700 */  sra        $a0, $a3, 12
    /* 55478 800BDC78 21104400 */  addu       $v0, $v0, $a0
    /* 5547C 800BDC7C 0200A314 */  bne        $a1, $v1, .L800BDC88
    /* 55480 800BDC80 060002A6 */   sh        $v0, 0x6($s0)
    /* 55484 800BDC84 1E0000A6 */  sh         $zero, 0x1E($s0)
  .L800BDC88:
    /* 55488 800BDC88 01000224 */  addiu      $v0, $zero, 0x1
  .L800BDC8C:
    /* 5548C 800BDC8C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 55490 800BDC90 1000B08F */  lw         $s0, 0x10($sp)
    /* 55494 800BDC94 0800E003 */  jr         $ra
    /* 55498 800BDC98 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BDBB4
