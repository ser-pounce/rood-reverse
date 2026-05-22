nonmatching func_800D6448, 0x9C

glabel func_800D6448
    /* 6DC48 800D6448 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6DC4C 800D644C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6DC50 800D6450 21908000 */  addu       $s2, $a0, $zero
    /* 6DC54 800D6454 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6DC58 800D6458 2180A000 */  addu       $s0, $a1, $zero
    /* 6DC5C 800D645C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6DC60 800D6460 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6DC64 800D6464 2E5E030C */  jal        func_800D78B8
    /* 6DC68 800D6468 2188C000 */   addu      $s1, $a2, $zero
    /* 6DC6C 800D646C FF003132 */  andi       $s1, $s1, 0xFF
    /* 6DC70 800D6470 CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 6DC74 800D6474 CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 6DC78 800D6478 19002202 */  multu      $s1, $v0
    /* 6DC7C 800D647C FF001032 */  andi       $s0, $s0, 0xFF
    /* 6DC80 800D6480 40101000 */  sll        $v0, $s0, 1
    /* 6DC84 800D6484 21105000 */  addu       $v0, $v0, $s0
    /* 6DC88 800D6488 80100200 */  sll        $v0, $v0, 2
    /* 6DC8C 800D648C 21105000 */  addu       $v0, $v0, $s0
    /* 6DC90 800D6490 00110200 */  sll        $v0, $v0, 4
    /* 6DC94 800D6494 21904202 */  addu       $s2, $s2, $v0
    /* 6DC98 800D6498 50004492 */  lbu        $a0, 0x50($s2)
    /* 6DC9C 800D649C 51004592 */  lbu        $a1, 0x51($s2)
    /* 6DCA0 800D64A0 10180000 */  mfhi       $v1
    /* 6DCA4 800D64A4 C2380300 */  srl        $a3, $v1, 3
    /* 6DCA8 800D64A8 80100700 */  sll        $v0, $a3, 2
    /* 6DCAC 800D64AC 21104700 */  addu       $v0, $v0, $a3
    /* 6DCB0 800D64B0 40100200 */  sll        $v0, $v0, 1
    /* 6DCB4 800D64B4 23882202 */  subu       $s1, $s1, $v0
    /* 6DCB8 800D64B8 FF002632 */  andi       $a2, $s1, 0xFF
    /* 6DCBC 800D64BC EA3D030C */  jal        func_800CF7A8
    /* 6DCC0 800D64C0 FF00E730 */   andi      $a3, $a3, 0xFF
    /* 6DCC4 800D64C4 335E030C */  jal        func_800D78CC
    /* 6DCC8 800D64C8 00000000 */   nop
    /* 6DCCC 800D64CC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6DCD0 800D64D0 1800B28F */  lw         $s2, 0x18($sp)
    /* 6DCD4 800D64D4 1400B18F */  lw         $s1, 0x14($sp)
    /* 6DCD8 800D64D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 6DCDC 800D64DC 0800E003 */  jr         $ra
    /* 6DCE0 800D64E0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D6448
