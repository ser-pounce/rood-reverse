nonmatching func_8008FA14, 0xB4

glabel func_8008FA14
    /* 27214 8008FA14 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 27218 8008FA18 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x8C)
    /* 2721C 8008FA1C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 27220 8008FA20 841C508C */  lw         $s0, %lo(vs_battle_roomData + 0x8C)($v0)
    /* 27224 8008FA24 1400B1AF */  sw         $s1, 0x14($sp)
    /* 27228 8008FA28 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2722C 8008FA2C B19B000C */  jal        rand
    /* 27230 8008FA30 21888000 */   addu      $s1, $a0, $zero
    /* 27234 8008FA34 4C000386 */  lh         $v1, 0x4C($s0)
    /* 27238 8008FA38 00000000 */  nop
    /* 2723C 8008FA3C 1A004300 */  div        $zero, $v0, $v1
    /* 27240 8008FA40 10180000 */  mfhi       $v1
    /* 27244 8008FA44 48000296 */  lhu        $v0, 0x48($s0)
    /* 27248 8008FA48 00000000 */  nop
    /* 2724C 8008FA4C 21104300 */  addu       $v0, $v0, $v1
    /* 27250 8008FA50 B19B000C */  jal        rand
    /* 27254 8008FA54 000022A6 */   sh        $v0, 0x0($s1)
    /* 27258 8008FA58 4E000386 */  lh         $v1, 0x4E($s0)
    /* 2725C 8008FA5C 00000000 */  nop
    /* 27260 8008FA60 1A004300 */  div        $zero, $v0, $v1
    /* 27264 8008FA64 10180000 */  mfhi       $v1
    /* 27268 8008FA68 4A000296 */  lhu        $v0, 0x4A($s0)
    /* 2726C 8008FA6C 00000000 */  nop
    /* 27270 8008FA70 21104300 */  addu       $v0, $v0, $v1
    /* 27274 8008FA74 B19B000C */  jal        rand
    /* 27278 8008FA78 040022A6 */   sh        $v0, 0x4($s1)
    /* 2727C 8008FA7C 21184000 */  addu       $v1, $v0, $zero
    /* 27280 8008FA80 03006104 */  bgez       $v1, .L8008FA90
    /* 27284 8008FA84 43120200 */   sra       $v0, $v0, 9
    /* 27288 8008FA88 FF016224 */  addiu      $v0, $v1, 0x1FF
    /* 2728C 8008FA8C 43120200 */  sra        $v0, $v0, 9
  .L8008FA90:
    /* 27290 8008FA90 40120200 */  sll        $v0, $v0, 9
    /* 27294 8008FA94 23106200 */  subu       $v0, $v1, $v0
    /* 27298 8008FA98 00024224 */  addiu      $v0, $v0, 0x200
    /* 2729C 8008FA9C 020022A6 */  sh         $v0, 0x2($s1)
    /* 272A0 8008FAA0 B19B000C */  jal        rand
    /* 272A4 8008FAA4 0C0020A2 */   sb        $zero, 0xC($s1)
    /* 272A8 8008FAA8 0F004230 */  andi       $v0, $v0, 0xF
    /* 272AC 8008FAAC 08004224 */  addiu      $v0, $v0, 0x8
    /* 272B0 8008FAB0 0F0022A2 */  sb         $v0, 0xF($s1)
    /* 272B4 8008FAB4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 272B8 8008FAB8 1400B18F */  lw         $s1, 0x14($sp)
    /* 272BC 8008FABC 1000B08F */  lw         $s0, 0x10($sp)
    /* 272C0 8008FAC0 0800E003 */  jr         $ra
    /* 272C4 8008FAC4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008FA14
