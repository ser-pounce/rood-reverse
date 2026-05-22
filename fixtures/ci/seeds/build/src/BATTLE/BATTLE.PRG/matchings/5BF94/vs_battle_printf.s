nonmatching vs_battle_printf, 0x394

glabel vs_battle_printf
    /* 5E05C 800C685C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5E060 800C6860 21388000 */  addu       $a3, $a0, $zero
    /* 5E064 800C6864 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5E068 800C6868 2180A000 */  addu       $s0, $a1, $zero
    /* 5E06C 800C686C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 5E070 800C6870 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5E074 800C6874 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5E078 800C6878 00000492 */  lbu        $a0, 0x0($s0)
    /* 5E07C 800C687C E7000224 */  addiu      $v0, $zero, 0xE7
    /* 5E080 800C6880 D3008210 */  beq        $a0, $v0, .L800C6BD0
    /* 5E084 800C6884 01001026 */   addiu     $s0, $s0, 0x1
    /* 5E088 800C6888 0F80023C */  lui        $v0, %hi(vs_battle_stringContext)
    /* 5E08C 800C688C 68515224 */  addiu      $s2, $v0, %lo(vs_battle_stringContext)
    /* 5E090 800C6890 6666113C */  lui        $s1, (0x66666667 >> 16)
    /* 5E094 800C6894 67663136 */  ori        $s1, $s1, (0x66666667 & 0xFFFF)
  .L800C6898:
    /* 5E098 800C6898 EC008228 */  slti       $v0, $a0, 0xEC
    /* 5E09C 800C689C C6004014 */  bnez       $v0, .L800C6BB8
    /* 5E0A0 800C68A0 FE000224 */   addiu     $v0, $zero, 0xFE
    /* 5E0A4 800C68A4 4E008210 */  beq        $a0, $v0, .L800C69E0
    /* 5E0A8 800C68A8 FF008228 */   slti      $v0, $a0, 0xFF
    /* 5E0AC 800C68AC 05004010 */  beqz       $v0, .L800C68C4
    /* 5E0B0 800C68B0 FD000224 */   addiu     $v0, $zero, 0xFD
    /* 5E0B4 800C68B4 08008210 */  beq        $a0, $v0, .L800C68D8
    /* 5E0B8 800C68B8 00000000 */   nop
    /* 5E0BC 800C68BC E91A0308 */  j          .L800C6BA4
    /* 5E0C0 800C68C0 0000E4A0 */   sb        $a0, 0x0($a3)
  .L800C68C4:
    /* 5E0C4 800C68C4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 5E0C8 800C68C8 AD008210 */  beq        $a0, $v0, .L800C6B80
    /* 5E0CC 800C68CC 00000000 */   nop
    /* 5E0D0 800C68D0 E91A0308 */  j          .L800C6BA4
    /* 5E0D4 800C68D4 0000E4A0 */   sb        $a0, 0x0($a3)
  .L800C68D8:
    /* 5E0D8 800C68D8 00000492 */  lbu        $a0, 0x0($s0)
    /* 5E0DC 800C68DC 00000000 */  nop
    /* 5E0E0 800C68E0 18009100 */  mult       $a0, $s1
    /* 5E0E4 800C68E4 C3170400 */  sra        $v0, $a0, 31
    /* 5E0E8 800C68E8 10480000 */  mfhi       $t1
    /* 5E0EC 800C68EC 83180900 */  sra        $v1, $t1, 2
    /* 5E0F0 800C68F0 23186200 */  subu       $v1, $v1, $v0
    /* 5E0F4 800C68F4 80100300 */  sll        $v0, $v1, 2
    /* 5E0F8 800C68F8 21104300 */  addu       $v0, $v0, $v1
    /* 5E0FC 800C68FC 40100200 */  sll        $v0, $v0, 1
    /* 5E100 800C6900 23108200 */  subu       $v0, $a0, $v0
    /* 5E104 800C6904 80100200 */  sll        $v0, $v0, 2
    /* 5E108 800C6908 21105200 */  addu       $v0, $v0, $s2
    /* 5E10C 800C690C 0000468C */  lw         $a2, 0x0($v0)
    /* 5E110 800C6910 00000000 */  nop
    /* 5E114 800C6914 0500C104 */  bgez       $a2, .L800C692C
    /* 5E118 800C6918 01001026 */   addiu     $s0, $s0, 0x1
    /* 5E11C 800C691C 23300600 */  negu       $a2, $a2
    /* 5E120 800C6920 A7000224 */  addiu      $v0, $zero, 0xA7
    /* 5E124 800C6924 0000E2A0 */  sb         $v0, 0x0($a3)
    /* 5E128 800C6928 0100E724 */  addiu      $a3, $a3, 0x1
  .L800C692C:
    /* 5E12C 800C692C 0A008228 */  slti       $v0, $a0, 0xA
    /* 5E130 800C6930 1B004010 */  beqz       $v0, .L800C69A0
    /* 5E134 800C6934 FFFF6424 */   addiu     $a0, $v1, -0x1
    /* 5E138 800C6938 0300C014 */  bnez       $a2, .L800C6948
    /* 5E13C 800C693C 0010053C */   lui       $a1, (0x10000000 >> 16)
    /* 5E140 800C6940 EF1A0308 */  j          .L800C6BBC
    /* 5E144 800C6944 0000E0A0 */   sb        $zero, 0x0($a3)
  .L800C6948:
    /* 5E148 800C6948 1A00C500 */  div        $zero, $a2, $a1
    /* 5E14C 800C694C 12100000 */  mflo       $v0
    /* 5E150 800C6950 00000000 */  nop
    /* 5E154 800C6954 07004014 */  bnez       $v0, .L800C6974
    /* 5E158 800C6958 00000000 */   nop
  .L800C695C:
    /* 5E15C 800C695C 03290500 */  sra        $a1, $a1, 4
    /* 5E160 800C6960 1A00C500 */  div        $zero, $a2, $a1
    /* 5E164 800C6964 12100000 */  mflo       $v0
    /* 5E168 800C6968 00000000 */  nop
    /* 5E16C 800C696C FBFF4010 */  beqz       $v0, .L800C695C
    /* 5E170 800C6970 00000000 */   nop
  .L800C6974:
    /* 5E174 800C6974 9200A010 */  beqz       $a1, .L800C6BC0
    /* 5E178 800C6978 00000000 */   nop
  .L800C697C:
    /* 5E17C 800C697C 1A00C500 */  div        $zero, $a2, $a1
    /* 5E180 800C6980 12100000 */  mflo       $v0
    /* 5E184 800C6984 03290500 */  sra        $a1, $a1, 4
    /* 5E188 800C6988 0F004230 */  andi       $v0, $v0, 0xF
    /* 5E18C 800C698C 0000E2A0 */  sb         $v0, 0x0($a3)
    /* 5E190 800C6990 FAFFA014 */  bnez       $a1, .L800C697C
    /* 5E194 800C6994 0100E724 */   addiu     $a3, $a3, 0x1
    /* 5E198 800C6998 F01A0308 */  j          .L800C6BC0
    /* 5E19C 800C699C 00000000 */   nop
  .L800C69A0:
    /* 5E1A0 800C69A0 04008010 */  beqz       $a0, .L800C69B4
    /* 5E1A4 800C69A4 01000524 */   addiu     $a1, $zero, 0x1
  .L800C69A8:
    /* 5E1A8 800C69A8 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 5E1AC 800C69AC FEFF8014 */  bnez       $a0, .L800C69A8
    /* 5E1B0 800C69B0 00290500 */   sll       $a1, $a1, 4
  .L800C69B4:
    /* 5E1B4 800C69B4 8200A010 */  beqz       $a1, .L800C6BC0
    /* 5E1B8 800C69B8 00000000 */   nop
  .L800C69BC:
    /* 5E1BC 800C69BC 1A00C500 */  div        $zero, $a2, $a1
    /* 5E1C0 800C69C0 12100000 */  mflo       $v0
    /* 5E1C4 800C69C4 03290500 */  sra        $a1, $a1, 4
    /* 5E1C8 800C69C8 0F004230 */  andi       $v0, $v0, 0xF
    /* 5E1CC 800C69CC 0000E2A0 */  sb         $v0, 0x0($a3)
    /* 5E1D0 800C69D0 FAFFA014 */  bnez       $a1, .L800C69BC
    /* 5E1D4 800C69D4 0100E724 */   addiu     $a3, $a3, 0x1
    /* 5E1D8 800C69D8 F01A0308 */  j          .L800C6BC0
    /* 5E1DC 800C69DC 00000000 */   nop
  .L800C69E0:
    /* 5E1E0 800C69E0 00000492 */  lbu        $a0, 0x0($s0)
    /* 5E1E4 800C69E4 00000000 */  nop
    /* 5E1E8 800C69E8 18009100 */  mult       $a0, $s1
    /* 5E1EC 800C69EC C3170400 */  sra        $v0, $a0, 31
    /* 5E1F0 800C69F0 10480000 */  mfhi       $t1
    /* 5E1F4 800C69F4 83180900 */  sra        $v1, $t1, 2
    /* 5E1F8 800C69F8 23186200 */  subu       $v1, $v1, $v0
    /* 5E1FC 800C69FC 80100300 */  sll        $v0, $v1, 2
    /* 5E200 800C6A00 21104300 */  addu       $v0, $v0, $v1
    /* 5E204 800C6A04 40100200 */  sll        $v0, $v0, 1
    /* 5E208 800C6A08 23108200 */  subu       $v0, $a0, $v0
    /* 5E20C 800C6A0C 80100200 */  sll        $v0, $v0, 2
    /* 5E210 800C6A10 21105200 */  addu       $v0, $v0, $s2
    /* 5E214 800C6A14 0000468C */  lw         $a2, 0x0($v0)
    /* 5E218 800C6A18 00000000 */  nop
    /* 5E21C 800C6A1C 0500C104 */  bgez       $a2, .L800C6A34
    /* 5E220 800C6A20 01001026 */   addiu     $s0, $s0, 0x1
    /* 5E224 800C6A24 23300600 */  negu       $a2, $a2
    /* 5E228 800C6A28 A7000224 */  addiu      $v0, $zero, 0xA7
    /* 5E22C 800C6A2C 0000E2A0 */  sb         $v0, 0x0($a3)
    /* 5E230 800C6A30 0100E724 */  addiu      $a3, $a3, 0x1
  .L800C6A34:
    /* 5E234 800C6A34 0A008228 */  slti       $v0, $a0, 0xA
    /* 5E238 800C6A38 2F004010 */  beqz       $v0, .L800C6AF8
    /* 5E23C 800C6A3C FFFF6424 */   addiu     $a0, $v1, -0x1
    /* 5E240 800C6A40 0300C014 */  bnez       $a2, .L800C6A50
    /* 5E244 800C6A44 9A3B053C */   lui       $a1, (0x3B9ACA00 >> 16)
    /* 5E248 800C6A48 EF1A0308 */  j          .L800C6BBC
    /* 5E24C 800C6A4C 0000E0A0 */   sb        $zero, 0x0($a3)
  .L800C6A50:
    /* 5E250 800C6A50 00CAA534 */  ori        $a1, $a1, (0x3B9ACA00 & 0xFFFF)
    /* 5E254 800C6A54 1A00C500 */  div        $zero, $a2, $a1
    /* 5E258 800C6A58 12100000 */  mflo       $v0
    /* 5E25C 800C6A5C 00000000 */  nop
    /* 5E260 800C6A60 0A004014 */  bnez       $v0, .L800C6A8C
    /* 5E264 800C6A64 1800B100 */   mult      $a1, $s1
  .L800C6A68:
    /* 5E268 800C6A68 C3170500 */  sra        $v0, $a1, 31
    /* 5E26C 800C6A6C 10180000 */  mfhi       $v1
    /* 5E270 800C6A70 83180300 */  sra        $v1, $v1, 2
    /* 5E274 800C6A74 23286200 */  subu       $a1, $v1, $v0
    /* 5E278 800C6A78 1A00C500 */  div        $zero, $a2, $a1
    /* 5E27C 800C6A7C 12100000 */  mflo       $v0
    /* 5E280 800C6A80 00000000 */  nop
    /* 5E284 800C6A84 F8FF4010 */  beqz       $v0, .L800C6A68
    /* 5E288 800C6A88 1800B100 */   mult      $a1, $s1
  .L800C6A8C:
    /* 5E28C 800C6A8C 4C00A010 */  beqz       $a1, .L800C6BC0
    /* 5E290 800C6A90 00000000 */   nop
  .L800C6A94:
    /* 5E294 800C6A94 1A00C500 */  div        $zero, $a2, $a1
    /* 5E298 800C6A98 12200000 */  mflo       $a0
    /* 5E29C 800C6A9C 00000000 */  nop
    /* 5E2A0 800C6AA0 00000000 */  nop
    /* 5E2A4 800C6AA4 1800B100 */  mult       $a1, $s1
    /* 5E2A8 800C6AA8 10180000 */  mfhi       $v1
    /* 5E2AC 800C6AAC 00000000 */  nop
    /* 5E2B0 800C6AB0 00000000 */  nop
    /* 5E2B4 800C6AB4 18009100 */  mult       $a0, $s1
    /* 5E2B8 800C6AB8 C3170500 */  sra        $v0, $a1, 31
    /* 5E2BC 800C6ABC 83180300 */  sra        $v1, $v1, 2
    /* 5E2C0 800C6AC0 23286200 */  subu       $a1, $v1, $v0
    /* 5E2C4 800C6AC4 C3170400 */  sra        $v0, $a0, 31
    /* 5E2C8 800C6AC8 10400000 */  mfhi       $t0
    /* 5E2CC 800C6ACC 83180800 */  sra        $v1, $t0, 2
    /* 5E2D0 800C6AD0 23186200 */  subu       $v1, $v1, $v0
    /* 5E2D4 800C6AD4 80100300 */  sll        $v0, $v1, 2
    /* 5E2D8 800C6AD8 21104300 */  addu       $v0, $v0, $v1
    /* 5E2DC 800C6ADC 40100200 */  sll        $v0, $v0, 1
    /* 5E2E0 800C6AE0 23208200 */  subu       $a0, $a0, $v0
    /* 5E2E4 800C6AE4 0000E4A0 */  sb         $a0, 0x0($a3)
    /* 5E2E8 800C6AE8 EAFFA014 */  bnez       $a1, .L800C6A94
    /* 5E2EC 800C6AEC 0100E724 */   addiu     $a3, $a3, 0x1
    /* 5E2F0 800C6AF0 F01A0308 */  j          .L800C6BC0
    /* 5E2F4 800C6AF4 00000000 */   nop
  .L800C6AF8:
    /* 5E2F8 800C6AF8 06008010 */  beqz       $a0, .L800C6B14
    /* 5E2FC 800C6AFC 01000524 */   addiu     $a1, $zero, 0x1
  .L800C6B00:
    /* 5E300 800C6B00 80100500 */  sll        $v0, $a1, 2
    /* 5E304 800C6B04 21104500 */  addu       $v0, $v0, $a1
    /* 5E308 800C6B08 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 5E30C 800C6B0C FCFF8014 */  bnez       $a0, .L800C6B00
    /* 5E310 800C6B10 40280200 */   sll       $a1, $v0, 1
  .L800C6B14:
    /* 5E314 800C6B14 2A00A010 */  beqz       $a1, .L800C6BC0
    /* 5E318 800C6B18 00000000 */   nop
  .L800C6B1C:
    /* 5E31C 800C6B1C 1A00C500 */  div        $zero, $a2, $a1
    /* 5E320 800C6B20 12200000 */  mflo       $a0
    /* 5E324 800C6B24 00000000 */  nop
    /* 5E328 800C6B28 00000000 */  nop
    /* 5E32C 800C6B2C 1800B100 */  mult       $a1, $s1
    /* 5E330 800C6B30 10180000 */  mfhi       $v1
    /* 5E334 800C6B34 00000000 */  nop
    /* 5E338 800C6B38 00000000 */  nop
    /* 5E33C 800C6B3C 18009100 */  mult       $a0, $s1
    /* 5E340 800C6B40 C3170500 */  sra        $v0, $a1, 31
    /* 5E344 800C6B44 83180300 */  sra        $v1, $v1, 2
    /* 5E348 800C6B48 23286200 */  subu       $a1, $v1, $v0
    /* 5E34C 800C6B4C C3170400 */  sra        $v0, $a0, 31
    /* 5E350 800C6B50 10400000 */  mfhi       $t0
    /* 5E354 800C6B54 83180800 */  sra        $v1, $t0, 2
    /* 5E358 800C6B58 23186200 */  subu       $v1, $v1, $v0
    /* 5E35C 800C6B5C 80100300 */  sll        $v0, $v1, 2
    /* 5E360 800C6B60 21104300 */  addu       $v0, $v0, $v1
    /* 5E364 800C6B64 40100200 */  sll        $v0, $v0, 1
    /* 5E368 800C6B68 23208200 */  subu       $a0, $a0, $v0
    /* 5E36C 800C6B6C 0000E4A0 */  sb         $a0, 0x0($a3)
    /* 5E370 800C6B70 EAFFA014 */  bnez       $a1, .L800C6B1C
    /* 5E374 800C6B74 0100E724 */   addiu     $a3, $a3, 0x1
    /* 5E378 800C6B78 F01A0308 */  j          .L800C6BC0
    /* 5E37C 800C6B7C 00000000 */   nop
  .L800C6B80:
    /* 5E380 800C6B80 00000292 */  lbu        $v0, 0x0($s0)
    /* 5E384 800C6B84 01001026 */  addiu      $s0, $s0, 0x1
    /* 5E388 800C6B88 80100200 */  sll        $v0, $v0, 2
    /* 5E38C 800C6B8C 21105200 */  addu       $v0, $v0, $s2
    /* 5E390 800C6B90 2800458C */  lw         $a1, 0x28($v0)
    /* 5E394 800C6B94 171A030C */  jal        vs_battle_printf
    /* 5E398 800C6B98 2120E000 */   addu      $a0, $a3, $zero
    /* 5E39C 800C6B9C F01A0308 */  j          .L800C6BC0
    /* 5E3A0 800C6BA0 21384000 */   addu      $a3, $v0, $zero
  .L800C6BA4:
    /* 5E3A4 800C6BA4 0100E724 */  addiu      $a3, $a3, 0x1
    /* 5E3A8 800C6BA8 00000292 */  lbu        $v0, 0x0($s0)
    /* 5E3AC 800C6BAC 01001026 */  addiu      $s0, $s0, 0x1
    /* 5E3B0 800C6BB0 EF1A0308 */  j          .L800C6BBC
    /* 5E3B4 800C6BB4 0000E2A0 */   sb        $v0, 0x0($a3)
  .L800C6BB8:
    /* 5E3B8 800C6BB8 0000E4A0 */  sb         $a0, 0x0($a3)
  .L800C6BBC:
    /* 5E3BC 800C6BBC 0100E724 */  addiu      $a3, $a3, 0x1
  .L800C6BC0:
    /* 5E3C0 800C6BC0 00000492 */  lbu        $a0, 0x0($s0)
    /* 5E3C4 800C6BC4 E7000224 */  addiu      $v0, $zero, 0xE7
    /* 5E3C8 800C6BC8 33FF8214 */  bne        $a0, $v0, .L800C6898
    /* 5E3CC 800C6BCC 01001026 */   addiu     $s0, $s0, 0x1
  .L800C6BD0:
    /* 5E3D0 800C6BD0 0000E4A0 */  sb         $a0, 0x0($a3)
    /* 5E3D4 800C6BD4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 5E3D8 800C6BD8 1800B28F */  lw         $s2, 0x18($sp)
    /* 5E3DC 800C6BDC 1400B18F */  lw         $s1, 0x14($sp)
    /* 5E3E0 800C6BE0 1000B08F */  lw         $s0, 0x10($sp)
    /* 5E3E4 800C6BE4 2110E000 */  addu       $v0, $a3, $zero
    /* 5E3E8 800C6BE8 0800E003 */  jr         $ra
    /* 5E3EC 800C6BEC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_battle_printf
