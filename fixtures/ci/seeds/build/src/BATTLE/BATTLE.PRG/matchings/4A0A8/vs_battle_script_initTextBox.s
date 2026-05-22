nonmatching vs_battle_script_initTextBox, 0x1A8

glabel vs_battle_script_initTextBox
    /* 4E108 800B6908 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4E10C 800B690C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 4E110 800B6910 21888000 */  addu       $s1, $a0, $zero
    /* 4E114 800B6914 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 4E118 800B6918 2800B2AF */  sw         $s2, 0x28($sp)
    /* 4E11C 800B691C 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4E120 800B6920 01002292 */  lbu        $v0, 0x1($s1)
    /* 4E124 800B6924 00000000 */  nop
    /* 4E128 800B6928 0F004330 */  andi       $v1, $v0, 0xF
    /* 4E12C 800B692C 02210200 */  srl        $a0, $v0, 4
    /* 4E130 800B6930 17006414 */  bne        $v1, $a0, .L800B6990
    /* 4E134 800B6934 00000000 */   nop
    /* 4E138 800B6938 04002492 */  lbu        $a0, 0x4($s1)
    /* 4E13C 800B693C 06002392 */  lbu        $v1, 0x6($s1)
    /* 4E140 800B6940 40200400 */  sll        $a0, $a0, 1
    /* 4E144 800B6944 40100300 */  sll        $v0, $v1, 1
    /* 4E148 800B6948 21104300 */  addu       $v0, $v0, $v1
    /* 4E14C 800B694C 80100200 */  sll        $v0, $v0, 2
    /* 4E150 800B6950 08004224 */  addiu      $v0, $v0, 0x8
    /* 4E154 800B6954 43100200 */  sra        $v0, $v0, 1
    /* 4E158 800B6958 E0FF4224 */  addiu      $v0, $v0, -0x20
    /* 4E15C 800B695C 21908200 */  addu       $s2, $a0, $v0
    /* 4E160 800B6960 E0FF0234 */  ori        $v0, $zero, 0xFFE0
    /* 4E164 800B6964 05002492 */  lbu        $a0, 0x5($s1)
    /* 4E168 800B6968 07002392 */  lbu        $v1, 0x7($s1)
    /* 4E16C 800B696C 21208200 */  addu       $a0, $a0, $v0
    /* 4E170 800B6970 40100300 */  sll        $v0, $v1, 1
    /* 4E174 800B6974 21104300 */  addu       $v0, $v0, $v1
    /* 4E178 800B6978 80100200 */  sll        $v0, $v0, 2
    /* 4E17C 800B697C 21104300 */  addu       $v0, $v0, $v1
    /* 4E180 800B6980 04004224 */  addiu      $v0, $v0, 0x4
    /* 4E184 800B6984 43100200 */  sra        $v0, $v0, 1
    /* 4E188 800B6988 77DA0208 */  j          .L800B69DC
    /* 4E18C 800B698C 21808200 */   addu      $s0, $a0, $v0
  .L800B6990:
    /* 4E190 800B6990 7D33030C */  jal        vs_battle_getTextBox
    /* 4E194 800B6994 00000000 */   nop
    /* 4E198 800B6998 21804000 */  addu       $s0, $v0, $zero
    /* 4E19C 800B699C 14004494 */  lhu        $a0, 0x14($v0)
    /* 4E1A0 800B69A0 20000392 */  lbu        $v1, 0x20($s0)
    /* 4E1A4 800B69A4 04008424 */  addiu      $a0, $a0, 0x4
    /* 4E1A8 800B69A8 40100300 */  sll        $v0, $v1, 1
    /* 4E1AC 800B69AC 21104300 */  addu       $v0, $v0, $v1
    /* 4E1B0 800B69B0 40100200 */  sll        $v0, $v0, 1
    /* 4E1B4 800B69B4 21000392 */  lbu        $v1, 0x21($s0)
    /* 4E1B8 800B69B8 21908200 */  addu       $s2, $a0, $v0
    /* 4E1BC 800B69BC 40100300 */  sll        $v0, $v1, 1
    /* 4E1C0 800B69C0 21104300 */  addu       $v0, $v0, $v1
    /* 4E1C4 800B69C4 80100200 */  sll        $v0, $v0, 2
    /* 4E1C8 800B69C8 21104300 */  addu       $v0, $v0, $v1
    /* 4E1CC 800B69CC 04004224 */  addiu      $v0, $v0, 0x4
    /* 4E1D0 800B69D0 16000396 */  lhu        $v1, 0x16($s0)
    /* 4E1D4 800B69D4 43100200 */  sra        $v0, $v0, 1
    /* 4E1D8 800B69D8 21806200 */  addu       $s0, $v1, $v0
  .L800B69DC:
    /* 4E1DC 800B69DC 80FF020C */  jal        vs_battle_getShort
    /* 4E1E0 800B69E0 02002426 */   addiu     $a0, $s1, 0x2
    /* 4E1E4 800B69E4 00140200 */  sll        $v0, $v0, 16
    /* 4E1E8 800B69E8 01002492 */  lbu        $a0, 0x1($s1)
    /* 4E1EC 800B69EC 04002692 */  lbu        $a2, 0x4($s1)
    /* 4E1F0 800B69F0 05002792 */  lbu        $a3, 0x5($s1)
    /* 4E1F4 800B69F4 06002392 */  lbu        $v1, 0x6($s1)
    /* 4E1F8 800B69F8 0F008430 */  andi       $a0, $a0, 0xF
    /* 4E1FC 800B69FC 1000A3AF */  sw         $v1, 0x10($sp)
    /* 4E200 800B6A00 001C1200 */  sll        $v1, $s2, 16
    /* 4E204 800B6A04 07002592 */  lbu        $a1, 0x7($s1)
    /* 4E208 800B6A08 031C0300 */  sra        $v1, $v1, 16
    /* 4E20C 800B6A0C 1800A3AF */  sw         $v1, 0x18($sp)
    /* 4E210 800B6A10 001C1000 */  sll        $v1, $s0, 16
    /* 4E214 800B6A14 031C0300 */  sra        $v1, $v1, 16
    /* 4E218 800B6A18 40300600 */  sll        $a2, $a2, 1
    /* 4E21C 800B6A1C E0FFC624 */  addiu      $a2, $a2, -0x20
    /* 4E220 800B6A20 E0FFE724 */  addiu      $a3, $a3, -0x20
    /* 4E224 800B6A24 1C00A3AF */  sw         $v1, 0x1C($sp)
    /* 4E228 800B6A28 1400A5AF */  sw         $a1, 0x14($sp)
    /* 4E22C 800B6A2C C233030C */  jal        vs_battle_initTextBox
    /* 4E230 800B6A30 032C0200 */   sra       $a1, $v0, 16
    /* 4E234 800B6A34 01002492 */  lbu        $a0, 0x1($s1)
    /* 4E238 800B6A38 7D33030C */  jal        vs_battle_getTextBox
    /* 4E23C 800B6A3C 0F008430 */   andi      $a0, $a0, 0xF
    /* 4E240 800B6A40 21804000 */  addu       $s0, $v0, $zero
    /* 4E244 800B6A44 0A002292 */  lbu        $v0, 0xA($s1)
    /* 4E248 800B6A48 08002426 */  addiu      $a0, $s1, 0x8
    /* 4E24C 800B6A4C 80FF020C */  jal        vs_battle_getShort
    /* 4E250 800B6A50 2E0002A6 */   sh        $v0, 0x2E($s0)
    /* 4E254 800B6A54 21204000 */  addu       $a0, $v0, $zero
    /* 4E258 800B6A58 00140400 */  sll        $v0, $a0, 16
    /* 4E25C 800B6A5C 03140200 */  sra        $v0, $v0, 16
    /* 4E260 800B6A60 00204228 */  slti       $v0, $v0, 0x2000
    /* 4E264 800B6A64 0B004010 */  beqz       $v0, .L800B6A94
    /* 4E268 800B6A68 00000000 */   nop
    /* 4E26C 800B6A6C 94FF020C */  jal        func_800BFE50
    /* 4E270 800B6A70 FFFF8430 */   andi      $a0, $a0, 0xFFFF
    /* 4E274 800B6A74 FFC0043C */  lui        $a0, (0xC0FFFFFF >> 16)
    /* 4E278 800B6A78 FFFF8434 */  ori        $a0, $a0, (0xC0FFFFFF & 0xFFFF)
    /* 4E27C 800B6A7C 3F004230 */  andi       $v0, $v0, 0x3F
    /* 4E280 800B6A80 0000038E */  lw         $v1, 0x0($s0)
    /* 4E284 800B6A84 00160200 */  sll        $v0, $v0, 24
    /* 4E288 800B6A88 24186400 */  and        $v1, $v1, $a0
    /* 4E28C 800B6A8C 25186200 */  or         $v1, $v1, $v0
    /* 4E290 800B6A90 000003AE */  sw         $v1, 0x0($s0)
  .L800B6A94:
    /* 4E294 800B6A94 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 4E298 800B6A98 2800B28F */  lw         $s2, 0x28($sp)
    /* 4E29C 800B6A9C 2400B18F */  lw         $s1, 0x24($sp)
    /* 4E2A0 800B6AA0 2000B08F */  lw         $s0, 0x20($sp)
    /* 4E2A4 800B6AA4 21100000 */  addu       $v0, $zero, $zero
    /* 4E2A8 800B6AA8 0800E003 */  jr         $ra
    /* 4E2AC 800B6AAC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_battle_script_initTextBox
