nonmatching func_800CABE0, 0xF0

glabel func_800CABE0
    /* 623E0 800CABE0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 623E4 800CABE4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 623E8 800CABE8 21908000 */  addu       $s2, $a0, $zero
    /* 623EC 800CABEC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 623F0 800CABF0 0F80113C */  lui        $s1, %hi(vs_battle_characterState)
    /* 623F4 800CABF4 FC19228E */  lw         $v0, %lo(vs_battle_characterState)($s1)
    /* 623F8 800CABF8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 623FC 800CABFC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 62400 800CAC00 3C00508C */  lw         $s0, 0x3C($v0)
    /* 62404 800CAC04 F882020C */  jal        func_800A0BE0
    /* 62408 800CAC08 21200000 */   addu      $a0, $zero, $zero
    /* 6240C 800CAC0C 0800033C */  lui        $v1, (0x80000 >> 16)
    /* 62410 800CAC10 24184300 */  and        $v1, $v0, $v1
    /* 62414 800CAC14 2B180300 */  sltu       $v1, $zero, $v1
    /* 62418 800CAC18 40200300 */  sll        $a0, $v1, 1
    /* 6241C 800CAC1C 1040033C */  lui        $v1, (0x40100000 >> 16)
    /* 62420 800CAC20 24104300 */  and        $v0, $v0, $v1
    /* 62424 800CAC24 1000033C */  lui        $v1, (0x100000 >> 16)
    /* 62428 800CAC28 02004314 */  bne        $v0, $v1, .L800CAC34
    /* 6242C 800CAC2C 00000000 */   nop
    /* 62430 800CAC30 04008434 */  ori        $a0, $a0, 0x4
  .L800CAC34:
    /* 62434 800CAC34 FC19228E */  lw         $v0, %lo(vs_battle_characterState)($s1)
    /* 62438 800CAC38 00000000 */  nop
    /* 6243C 800CAC3C 4400428C */  lw         $v0, 0x44($v0)
    /* 62440 800CAC40 00000000 */  nop
    /* 62444 800CAC44 0800428C */  lw         $v0, 0x8($v0)
    /* 62448 800CAC48 8000033C */  lui        $v1, (0x800000 >> 16)
    /* 6244C 800CAC4C 24104300 */  and        $v0, $v0, $v1
    /* 62450 800CAC50 02004014 */  bnez       $v0, .L800CAC5C
    /* 62454 800CAC54 00000000 */   nop
    /* 62458 800CAC58 08008434 */  ori        $a0, $a0, 0x8
  .L800CAC5C:
    /* 6245C 800CAC5C 1C000286 */  lh         $v0, 0x1C($s0)
    /* 62460 800CAC60 00000000 */  nop
    /* 62464 800CAC64 02004014 */  bnez       $v0, .L800CAC70
    /* 62468 800CAC68 21188000 */   addu      $v1, $a0, $zero
    /* 6246C 800CAC6C 20006334 */  ori        $v1, $v1, 0x20
  .L800CAC70:
    /* 62470 800CAC70 18000286 */  lh         $v0, 0x18($s0)
    /* 62474 800CAC74 00000000 */  nop
    /* 62478 800CAC78 02004014 */  bnez       $v0, .L800CAC84
    /* 6247C 800CAC7C 00000000 */   nop
    /* 62480 800CAC80 40006334 */  ori        $v1, $v1, 0x40
  .L800CAC84:
    /* 62484 800CAC84 4809048E */  lw         $a0, 0x948($s0)
    /* 62488 800CAC88 00000000 */  nop
    /* 6248C 800CAC8C 01108230 */  andi       $v0, $a0, 0x1001
    /* 62490 800CAC90 02004010 */  beqz       $v0, .L800CAC9C
    /* 62494 800CAC94 00208230 */   andi      $v0, $a0, 0x2000
    /* 62498 800CAC98 80006334 */  ori        $v1, $v1, 0x80
  .L800CAC9C:
    /* 6249C 800CAC9C 02004010 */  beqz       $v0, .L800CACA8
    /* 624A0 800CACA0 02000224 */   addiu     $v0, $zero, 0x2
    /* 624A4 800CACA4 00016334 */  ori        $v1, $v1, 0x100
  .L800CACA8:
    /* 624A8 800CACA8 02004216 */  bne        $s2, $v0, .L800CACB4
    /* 624AC 800CACAC 00000000 */   nop
    /* 624B0 800CACB0 00026334 */  ori        $v1, $v1, 0x200
  .L800CACB4:
    /* 624B4 800CACB4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 624B8 800CACB8 1800B28F */  lw         $s2, 0x18($sp)
    /* 624BC 800CACBC 1400B18F */  lw         $s1, 0x14($sp)
    /* 624C0 800CACC0 1000B08F */  lw         $s0, 0x10($sp)
    /* 624C4 800CACC4 21106000 */  addu       $v0, $v1, $zero
    /* 624C8 800CACC8 0800E003 */  jr         $ra
    /* 624CC 800CACCC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CABE0
