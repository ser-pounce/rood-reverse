nonmatching func_8008B1FC, 0x90

glabel func_8008B1FC
    /* 229FC 8008B1FC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 22A00 8008B200 1000B0AF */  sw         $s0, 0x10($sp)
    /* 22A04 8008B204 21808000 */  addu       $s0, $a0, $zero
    /* 22A08 8008B208 801F043C */  lui        $a0, (0x1F800014 >> 16)
    /* 22A0C 8008B20C 14008434 */  ori        $a0, $a0, (0x1F800014 & 0xFFFF)
    /* 22A10 8008B210 1800BFAF */  sw         $ra, 0x18($sp)
    /* 22A14 8008B214 6605010C */  jal        SetRotMatrix
    /* 22A18 8008B218 1400B1AF */   sw        $s1, 0x14($sp)
    /* 22A1C 8008B21C 801F043C */  lui        $a0, (0x1F800014 >> 16)
    /* 22A20 8008B220 5E05010C */  jal        SetTransMatrix
    /* 22A24 8008B224 14008434 */   ori       $a0, $a0, (0x1F800014 & 0xFFFF)
    /* 22A28 8008B228 FE60020C */  jal        func_800983F8
    /* 22A2C 8008B22C 21200002 */   addu      $a0, $s0, $zero
    /* 22A30 8008B230 21200002 */  addu       $a0, $s0, $zero
    /* 22A34 8008B234 0F80023C */  lui        $v0, %hi(D_800F19C8)
    /* 22A38 8008B238 801F103C */  lui        $s0, (0x1F800000 >> 16)
    /* 22A3C 8008B23C C819458C */  lw         $a1, %lo(D_800F19C8)($v0)
    /* 22A40 8008B240 0000028E */  lw         $v0, (0x1F800000 & 0xFFFF)($s0)
    /* 22A44 8008B244 0F80113C */  lui        $s1, %hi(D_800F1CC0)
    /* 22A48 8008B248 8F5C020C */  jal        func_8009723C
    /* 22A4C 8008B24C C01C22AE */   sw        $v0, %lo(D_800F1CC0)($s1)
    /* 22A50 8008B250 0F80023C */  lui        $v0, %hi(D_800F1BB0)
    /* 22A54 8008B254 B01B4624 */  addiu      $a2, $v0, %lo(D_800F1BB0)
    /* 22A58 8008B258 0000058E */  lw         $a1, (0x1F800000 & 0xFFFF)($s0)
    /* 22A5C 8008B25C 0600C384 */  lh         $v1, 0x6($a2)
    /* 22A60 8008B260 0F80023C */  lui        $v0, %hi(D_800F1BB8)
    /* 22A64 8008B264 04006010 */  beqz       $v1, .L8008B278
    /* 22A68 8008B268 B81B45AC */   sw        $a1, %lo(D_800F1BB8)($v0)
    /* 22A6C 8008B26C C01C248E */  lw         $a0, %lo(D_800F1CC0)($s1)
    /* 22A70 8008B270 5B63020C */  jal        func_80098D6C
    /* 22A74 8008B274 21380000 */   addu      $a3, $zero, $zero
  .L8008B278:
    /* 22A78 8008B278 1800BF8F */  lw         $ra, 0x18($sp)
    /* 22A7C 8008B27C 1400B18F */  lw         $s1, 0x14($sp)
    /* 22A80 8008B280 1000B08F */  lw         $s0, 0x10($sp)
    /* 22A84 8008B284 0800E003 */  jr         $ra
    /* 22A88 8008B288 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008B1FC
