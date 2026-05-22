nonmatching func_800A69B4, 0xEC

glabel func_800A69B4
    /* 3E1B4 800A69B4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3E1B8 800A69B8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 3E1BC 800A69BC 21808000 */  addu       $s0, $a0, $zero
    /* 3E1C0 800A69C0 00020424 */  addiu      $a0, $zero, 0x200
    /* 3E1C4 800A69C4 2000BFAF */  sw         $ra, 0x20($sp)
    /* 3E1C8 800A69C8 CA03010C */  jal        rsin
    /* 3E1CC 800A69CC 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* 3E1D0 800A69D0 3C060396 */  lhu        $v1, 0x63C($s0)
    /* 3E1D4 800A69D4 00000000 */  nop
    /* 3E1D8 800A69D8 18004300 */  mult       $v0, $v1
    /* 3E1DC 800A69DC 12180000 */  mflo       $v1
    /* 3E1E0 800A69E0 02006104 */  bgez       $v1, .L800A69EC
    /* 3E1E4 800A69E4 21880000 */   addu      $s1, $zero, $zero
    /* 3E1E8 800A69E8 FF0F6324 */  addiu      $v1, $v1, 0xFFF
  .L800A69EC:
    /* 3E1EC 800A69EC 0F80023C */  lui        $v0, %hi(D_800F49F9)
    /* 3E1F0 800A69F0 F9494290 */  lbu        $v0, %lo(D_800F49F9)($v0)
    /* 3E1F4 800A69F4 031B0300 */  sra        $v1, $v1, 12
    /* 3E1F8 800A69F8 1000A0A7 */  sh         $zero, 0x10($sp)
    /* 3E1FC 800A69FC 42100200 */  srl        $v0, $v0, 1
    /* 3E200 800A6A00 01004230 */  andi       $v0, $v0, 0x1
    /* 3E204 800A6A04 03004010 */  beqz       $v0, .L800A6A14
    /* 3E208 800A6A08 1400A0A7 */   sh        $zero, 0x14($sp)
    /* 3E20C 800A6A0C 869A0208 */  j          .L800A6A18
    /* 3E210 800A6A10 1400A3A7 */   sh        $v1, 0x14($sp)
  .L800A6A14:
    /* 3E214 800A6A14 1000A3A7 */  sh         $v1, 0x10($sp)
  .L800A6A18:
    /* 3E218 800A6A18 0F80023C */  lui        $v0, %hi(D_800F4B08)
    /* 3E21C 800A6A1C 084B5024 */  addiu      $s0, $v0, %lo(D_800F4B08)
    /* 3E220 800A6A20 21200002 */  addu       $a0, $s0, $zero
    /* 3E224 800A6A24 1000A587 */  lh         $a1, 0x10($sp)
    /* 3E228 800A6A28 1400A687 */  lh         $a2, 0x14($sp)
    /* 3E22C 800A6A2C BA9B020C */  jal        func_800A6EE8
    /* 3E230 800A6A30 01000724 */   addiu     $a3, $zero, 0x1
    /* 3E234 800A6A34 02000386 */  lh         $v1, 0x2($s0)
    /* 3E238 800A6A38 00000000 */  nop
    /* 3E23C 800A6A3C 23184300 */  subu       $v1, $v0, $v1
    /* 3E240 800A6A40 C1FF6228 */  slti       $v0, $v1, -0x3F
    /* 3E244 800A6A44 10004014 */  bnez       $v0, .L800A6A88
    /* 3E248 800A6A48 21102002 */   addu      $v0, $s1, $zero
    /* 3E24C 800A6A4C 21200002 */  addu       $a0, $s0, $zero
    /* 3E250 800A6A50 01000724 */  addiu      $a3, $zero, 0x1
    /* 3E254 800A6A54 1000A587 */  lh         $a1, 0x10($sp)
    /* 3E258 800A6A58 1400A687 */  lh         $a2, 0x14($sp)
    /* 3E25C 800A6A5C 23280500 */  negu       $a1, $a1
    /* 3E260 800A6A60 BA9B020C */  jal        func_800A6EE8
    /* 3E264 800A6A64 23300600 */   negu      $a2, $a2
    /* 3E268 800A6A68 02000386 */  lh         $v1, 0x2($s0)
    /* 3E26C 800A6A6C 00000000 */  nop
    /* 3E270 800A6A70 23184300 */  subu       $v1, $v0, $v1
    /* 3E274 800A6A74 C1FF6228 */  slti       $v0, $v1, -0x3F
    /* 3E278 800A6A78 03004014 */  bnez       $v0, .L800A6A88
    /* 3E27C 800A6A7C 21102002 */   addu      $v0, $s1, $zero
    /* 3E280 800A6A80 01001124 */  addiu      $s1, $zero, 0x1
    /* 3E284 800A6A84 21102002 */  addu       $v0, $s1, $zero
  .L800A6A88:
    /* 3E288 800A6A88 2000BF8F */  lw         $ra, 0x20($sp)
    /* 3E28C 800A6A8C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 3E290 800A6A90 1800B08F */  lw         $s0, 0x18($sp)
    /* 3E294 800A6A94 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 3E298 800A6A98 0800E003 */  jr         $ra
    /* 3E29C 800A6A9C 00000000 */   nop
endlabel func_800A69B4
