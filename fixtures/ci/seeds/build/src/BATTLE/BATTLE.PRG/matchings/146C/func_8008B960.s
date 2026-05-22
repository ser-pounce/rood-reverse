nonmatching func_8008B960, 0x168

glabel func_8008B960
    /* 23160 8008B960 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 23164 8008B964 2138A000 */  addu       $a3, $a1, $zero
    /* 23168 8008B968 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 2316C 8008B96C F81B4224 */  addiu      $v0, $v0, %lo(vs_battle_roomData)
    /* 23170 8008B970 1400BFAF */  sw         $ra, 0x14($sp)
    /* 23174 8008B974 1000B0AF */  sw         $s0, 0x10($sp)
    /* 23178 8008B978 7000458C */  lw         $a1, 0x70($v0)
    /* 2317C 8008B97C 00000000 */  nop
    /* 23180 8008B980 3B00A010 */  beqz       $a1, .L8008BA70
    /* 23184 8008B984 2180A000 */   addu      $s0, $a1, $zero
    /* 23188 8008B988 1000438C */  lw         $v1, 0x10($v0)
    /* 2318C 8008B98C AAAA023C */  lui        $v0, (0xAAAAAAAB >> 16)
    /* 23190 8008B990 ABAA4234 */  ori        $v0, $v0, (0xAAAAAAAB & 0xFFFF)
    /* 23194 8008B994 19006200 */  multu      $v1, $v0
    /* 23198 8008B998 10780000 */  mfhi       $t7
    /* 2319C 8008B99C C2600F00 */  srl        $t4, $t7, 3
    /* 231A0 8008B9A0 31008011 */  beqz       $t4, .L8008BA68
    /* 231A4 8008B9A4 21580000 */   addu      $t3, $zero, $zero
    /* 231A8 8008B9A8 0200CE28 */  slti       $t6, $a2, 0x2
    /* 231AC 8008B9AC FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 231B0 8008B9B0 55550D3C */  lui        $t5, (0x55555556 >> 16)
    /* 231B4 8008B9B4 5655AD35 */  ori        $t5, $t5, (0x55555556 & 0xFFFF)
    /* 231B8 8008B9B8 FFFFE524 */  addiu      $a1, $a3, -0x1
    /* 231BC 8008B9BC 02000926 */  addiu      $t1, $s0, 0x2
  .L8008B9C0:
    /* 231C0 8008B9C0 0700C015 */  bnez       $t6, .L8008B9E0
    /* 231C4 8008B9C4 00000000 */   nop
    /* 231C8 8008B9C8 00002295 */  lhu        $v0, 0x0($t1)
    /* 231CC 8008B9CC 00000000 */  nop
    /* 231D0 8008B9D0 82120200 */  srl        $v0, $v0, 10
    /* 231D4 8008B9D4 07004230 */  andi       $v0, $v0, 0x7
    /* 231D8 8008B9D8 23004610 */  beq        $v0, $a2, .L8008BA68
    /* 231DC 8008B9DC 00000000 */   nop
  .L8008B9E0:
    /* 231E0 8008B9E0 00002395 */  lhu        $v1, 0x0($t1)
    /* 231E4 8008B9E4 00000000 */  nop
    /* 231E8 8008B9E8 FFFF6830 */  andi       $t0, $v1, 0xFFFF
    /* 231EC 8008B9EC 82120800 */  srl        $v0, $t0, 10
    /* 231F0 8008B9F0 07004230 */  andi       $v0, $v0, 0x7
    /* 231F4 8008B9F4 17004614 */  bne        $v0, $a2, .L8008BA54
    /* 231F8 8008B9F8 21380000 */   addu      $a3, $zero, $zero
    /* 231FC 8008B9FC 1F006A30 */  andi       $t2, $v1, 0x1F
    /* 23200 8008BA00 42110800 */  srl        $v0, $t0, 5
    /* 23204 8008BA04 1F004830 */  andi       $t0, $v0, 0x1F
    /* 23208 8008BA08 1800ED00 */  mult       $a3, $t5
  .L8008BA0C:
    /* 2320C 8008BA0C C3170700 */  sra        $v0, $a3, 31
    /* 23210 8008BA10 10780000 */  mfhi       $t7
    /* 23214 8008BA14 2318E201 */  subu       $v1, $t7, $v0
    /* 23218 8008BA18 40100300 */  sll        $v0, $v1, 1
    /* 2321C 8008BA1C 21104300 */  addu       $v0, $v0, $v1
    /* 23220 8008BA20 2310E200 */  subu       $v0, $a3, $v0
    /* 23224 8008BA24 21108200 */  addu       $v0, $a0, $v0
    /* 23228 8008BA28 03004215 */  bne        $t2, $v0, .L8008BA38
    /* 2322C 8008BA2C 2110A300 */   addu      $v0, $a1, $v1
    /* 23230 8008BA30 06000211 */  beq        $t0, $v0, .L8008BA4C
    /* 23234 8008BA34 09000224 */   addiu     $v0, $zero, 0x9
  .L8008BA38:
    /* 23238 8008BA38 0100E724 */  addiu      $a3, $a3, 0x1
    /* 2323C 8008BA3C 0900E228 */  slti       $v0, $a3, 0x9
    /* 23240 8008BA40 F2FF4014 */  bnez       $v0, .L8008BA0C
    /* 23244 8008BA44 1800ED00 */   mult      $a3, $t5
    /* 23248 8008BA48 09000224 */  addiu      $v0, $zero, 0x9
  .L8008BA4C:
    /* 2324C 8008BA4C 0600E214 */  bne        $a3, $v0, .L8008BA68
    /* 23250 8008BA50 00000000 */   nop
  .L8008BA54:
    /* 23254 8008BA54 01006B25 */  addiu      $t3, $t3, 0x1
    /* 23258 8008BA58 0C002925 */  addiu      $t1, $t1, 0xC
    /* 2325C 8008BA5C 2A106C01 */  slt        $v0, $t3, $t4
    /* 23260 8008BA60 D7FF4014 */  bnez       $v0, .L8008B9C0
    /* 23264 8008BA64 0C001026 */   addiu     $s0, $s0, 0xC
  .L8008BA68:
    /* 23268 8008BA68 02006C15 */  bne        $t3, $t4, .L8008BA74
    /* 2326C 8008BA6C 00000000 */   nop
  .L8008BA70:
    /* 23270 8008BA70 21800000 */  addu       $s0, $zero, $zero
  .L8008BA74:
    /* 23274 8008BA74 0A000012 */  beqz       $s0, .L8008BAA0
    /* 23278 8008BA78 0F80043C */   lui       $a0, %hi(D_800F1CC8)
    /* 2327C 8008BA7C C81C8424 */  addiu      $a0, $a0, %lo(D_800F1CC8)
    /* 23280 8008BA80 21280002 */  addu       $a1, $s0, $zero
    /* 23284 8008BA84 2C24010C */  jal        vs_main_memcpy
    /* 23288 8008BA88 0C000624 */   addiu     $a2, $zero, 0xC
    /* 2328C 8008BA8C 08000492 */  lbu        $a0, 0x8($s0)
    /* 23290 8008BA90 2036020C */  jal        _getDoorId
    /* 23294 8008BA94 00000000 */   nop
    /* 23298 8008BA98 AD2E0208 */  j          .L8008BAB4
    /* 2329C 8008BA9C 0F80033C */   lui       $v1, %hi(vs_battle_doorEntered)
  .L8008BAA0:
    /* 232A0 8008BAA0 C81C8424 */  addiu      $a0, $a0, %lo(D_800F1CC8)
    /* 232A4 8008BAA4 4424010C */  jal        vs_main_bzero
    /* 232A8 8008BAA8 0C000524 */   addiu     $a1, $zero, 0xC
    /* 232AC 8008BAAC 0F80033C */  lui        $v1, %hi(vs_battle_doorEntered)
    /* 232B0 8008BAB0 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8008BAB4:
    /* 232B4 8008BAB4 BE1B62A4 */  sh         $v0, %lo(vs_battle_doorEntered)($v1)
    /* 232B8 8008BAB8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 232BC 8008BABC 1000B08F */  lw         $s0, 0x10($sp)
    /* 232C0 8008BAC0 0800E003 */  jr         $ra
    /* 232C4 8008BAC4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008B960
