nonmatching _decDCToutCallback, 0x12C

glabel _decDCToutCallback
    /* 6974 8006F174 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6978 8006F178 1800B0AF */  sw         $s0, 0x18($sp)
    /* 697C 8006F17C 0480103C */  lui        $s0, %hi(StCdIntrFlag)
    /* 6980 8006F180 149C028E */  lw         $v0, %lo(StCdIntrFlag)($s0)
    /* 6984 8006F184 00000000 */  nop
    /* 6988 8006F188 04004010 */  beqz       $v0, .L8006F19C
    /* 698C 8006F18C 1C00BFAF */   sw        $ra, 0x1C($sp)
    /* 6990 8006F190 5989000C */  jal        StCdInterrupt
    /* 6994 8006F194 00000000 */   nop
    /* 6998 8006F198 149C00AE */  sw         $zero, %lo(StCdIntrFlag)($s0)
  .L8006F19C:
    /* 699C 8006F19C 0E80023C */  lui        $v0, %hi(_movieData)
    /* 69A0 8006F1A0 A8ED4624 */  addiu      $a2, $v0, %lo(_movieData)
    /* 69A4 8006F1A4 2F00C988 */  lwl        $t1, 0x2F($a2)
    /* 69A8 8006F1A8 2C00C998 */  lwr        $t1, 0x2C($a2)
    /* 69AC 8006F1AC 3300CA88 */  lwl        $t2, 0x33($a2)
    /* 69B0 8006F1B0 3000CA98 */  lwr        $t2, 0x30($a2)
    /* 69B4 8006F1B4 1300A9AB */  swl        $t1, 0x13($sp)
    /* 69B8 8006F1B8 1000A9BB */  swr        $t1, 0x10($sp)
    /* 69BC 8006F1BC 1700AAAB */  swl        $t2, 0x17($sp)
    /* 69C0 8006F1C0 1400AABB */  swr        $t2, 0x14($sp)
    /* 69C4 8006F1C4 1400D08C */  lw         $s0, 0x14($a2)
    /* 69C8 8006F1C8 2C00C394 */  lhu        $v1, 0x2C($a2)
    /* 69CC 8006F1CC 3000C594 */  lhu        $a1, 0x30($a2)
    /* 69D0 8006F1D0 2800C78C */  lw         $a3, 0x28($a2)
    /* 69D4 8006F1D4 21100002 */  addu       $v0, $s0, $zero
    /* 69D8 8006F1D8 0100482C */  sltiu      $t0, $v0, 0x1
    /* 69DC 8006F1DC 21186500 */  addu       $v1, $v1, $a1
    /* 69E0 8006F1E0 2C00C3A4 */  sh         $v1, 0x2C($a2)
    /* 69E4 8006F1E4 001C0300 */  sll        $v1, $v1, 16
    /* 69E8 8006F1E8 C0100700 */  sll        $v0, $a3, 3
    /* 69EC 8006F1EC 21104600 */  addu       $v0, $v0, $a2
    /* 69F0 8006F1F0 1400C8AC */  sw         $t0, 0x14($a2)
    /* 69F4 8006F1F4 18004484 */  lh         $a0, 0x18($v0)
    /* 69F8 8006F1F8 1C004284 */  lh         $v0, 0x1C($v0)
    /* 69FC 8006F1FC 031C0300 */  sra        $v1, $v1, 16
    /* 6A00 8006F200 21208200 */  addu       $a0, $a0, $v0
    /* 6A04 8006F204 2A186400 */  slt        $v1, $v1, $a0
    /* 6A08 8006F208 0E006010 */  beqz       $v1, .L8006F244
    /* 6A0C 8006F20C 002C0500 */   sll       $a1, $a1, 16
    /* 6A10 8006F210 3200C284 */  lh         $v0, 0x32($a2)
    /* 6A14 8006F214 032C0500 */  sra        $a1, $a1, 16
    /* 6A18 8006F218 1800A200 */  mult       $a1, $v0
    /* 6A1C 8006F21C 80100800 */  sll        $v0, $t0, 2
    /* 6A20 8006F220 21104600 */  addu       $v0, $v0, $a2
    /* 6A24 8006F224 0C00448C */  lw         $a0, 0xC($v0)
    /* 6A28 8006F228 12280000 */  mflo       $a1
    /* 6A2C 8006F22C C2170500 */  srl        $v0, $a1, 31
    /* 6A30 8006F230 2128A200 */  addu       $a1, $a1, $v0
    /* 6A34 8006F234 DCC7010C */  jal        DecDCTout
    /* 6A38 8006F238 43280500 */   sra       $a1, $a1, 1
    /* 6A3C 8006F23C 9EBC0108 */  j          .L8006F278
    /* 6A40 8006F240 0E80033C */   lui       $v1, %hi(_movieData)
  .L8006F244:
    /* 6A44 8006F244 01000224 */  addiu      $v0, $zero, 0x1
    /* 6A48 8006F248 3400C2AC */  sw         $v0, 0x34($a2)
    /* 6A4C 8006F24C 2B10E200 */  sltu       $v0, $a3, $v0
    /* 6A50 8006F250 2800C2AC */  sw         $v0, 0x28($a2)
    /* 6A54 8006F254 C0100200 */  sll        $v0, $v0, 3
    /* 6A58 8006F258 21104600 */  addu       $v0, $v0, $a2
    /* 6A5C 8006F25C 18004394 */  lhu        $v1, 0x18($v0)
    /* 6A60 8006F260 00000000 */  nop
    /* 6A64 8006F264 2C00C3A4 */  sh         $v1, 0x2C($a2)
    /* 6A68 8006F268 1A004294 */  lhu        $v0, 0x1A($v0)
    /* 6A6C 8006F26C 00000000 */  nop
    /* 6A70 8006F270 2E00C2A4 */  sh         $v0, 0x2E($a2)
    /* 6A74 8006F274 0E80033C */  lui        $v1, %hi(_movieData)
  .L8006F278:
    /* 6A78 8006F278 A8ED6324 */  addiu      $v1, $v1, %lo(_movieData)
    /* 6A7C 8006F27C 80101000 */  sll        $v0, $s0, 2
    /* 6A80 8006F280 21104300 */  addu       $v0, $v0, $v1
    /* 6A84 8006F284 0C00458C */  lw         $a1, 0xC($v0)
    /* 6A88 8006F288 3FA2000C */  jal        LoadImage
    /* 6A8C 8006F28C 1000A427 */   addiu     $a0, $sp, 0x10
    /* 6A90 8006F290 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6A94 8006F294 1800B08F */  lw         $s0, 0x18($sp)
    /* 6A98 8006F298 0800E003 */  jr         $ra
    /* 6A9C 8006F29C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _decDCToutCallback
