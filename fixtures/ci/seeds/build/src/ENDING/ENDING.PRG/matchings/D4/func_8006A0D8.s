nonmatching func_8006A0D8, 0x2E4

glabel func_8006A0D8
    /* 18D8 8006A0D8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 18DC 8006A0DC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 18E0 8006A0E0 801F133C */  lui        $s3, (0x1F800000 >> 16)
    /* 18E4 8006A0E4 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 18E8 8006A0E8 2800B6AF */  sw         $s6, 0x28($sp)
    /* 18EC 8006A0EC 2400B5AF */  sw         $s5, 0x24($sp)
    /* 18F0 8006A0F0 2000B4AF */  sw         $s4, 0x20($sp)
    /* 18F4 8006A0F4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 18F8 8006A0F8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 18FC 8006A0FC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1900 8006A100 0000768E */  lw         $s6, (0x1F800000 & 0xFFFF)($s3)
    /* 1904 8006A104 89AD000C */  jal        SetSprt
    /* 1908 8006A108 2120C002 */   addu      $a0, $s6, $zero
    /* 190C 8006A10C 2128C002 */  addu       $a1, $s6, $zero
    /* 1910 8006A110 0A001424 */  addiu      $s4, $zero, 0xA
    /* 1914 8006A114 00011124 */  addiu      $s1, $zero, 0x100
    /* 1918 8006A118 CC001524 */  addiu      $s5, $zero, 0xCC
    /* 191C 8006A11C 0E80103C */  lui        $s0, %hi(D_800DC19C)
    /* 1920 8006A120 0C00C0A2 */  sb         $zero, 0xC($s6)
    /* 1924 8006A124 0D00D4A2 */  sb         $s4, 0xD($s6)
    /* 1928 8006A128 9CC10292 */  lbu        $v0, %lo(D_800DC19C)($s0)
    /* 192C 8006A12C F03F1224 */  addiu      $s2, $zero, 0x3FF0
    /* 1930 8006A130 0800C0A6 */  sh         $zero, 0x8($s6)
    /* 1934 8006A134 0A00D4A6 */  sh         $s4, 0xA($s6)
    /* 1938 8006A138 1000D1A6 */  sh         $s1, 0x10($s6)
    /* 193C 8006A13C 1200D5A6 */  sh         $s5, 0x12($s6)
    /* 1940 8006A140 0E00D2A6 */  sh         $s2, 0xE($s6)
    /* 1944 8006A144 0600C2A2 */  sb         $v0, 0x6($s6)
    /* 1948 8006A148 0500C2A2 */  sb         $v0, 0x5($s6)
    /* 194C 8006A14C 0400C2A2 */  sb         $v0, 0x4($s6)
    /* 1950 8006A150 0400648E */  lw         $a0, (0x1F800004 & 0xFFFF)($s3)
    /* 1954 8006A154 1400D626 */  addiu      $s6, $s6, 0x14
    /* 1958 8006A158 35AD000C */  jal        AddPrim
    /* 195C 8006A15C FC1F8424 */   addiu     $a0, $a0, 0x1FFC
    /* 1960 8006A160 2C000424 */  addiu      $a0, $zero, 0x2C
    /* 1964 8006A164 FF070524 */  addiu      $a1, $zero, 0x7FF
    /* 1968 8006A168 56AA010C */  jal        _insertTpage
    /* 196C 8006A16C 000076AE */   sw        $s6, (0x1F800000 & 0xFFFF)($s3)
    /* 1970 8006A170 21B04000 */  addu       $s6, $v0, $zero
    /* 1974 8006A174 89AD000C */  jal        SetSprt
    /* 1978 8006A178 2120C002 */   addu      $a0, $s6, $zero
    /* 197C 8006A17C 2128C002 */  addu       $a1, $s6, $zero
    /* 1980 8006A180 0C00C0A2 */  sb         $zero, 0xC($s6)
    /* 1984 8006A184 0D00D4A2 */  sb         $s4, 0xD($s6)
    /* 1988 8006A188 9CC10392 */  lbu        $v1, %lo(D_800DC19C)($s0)
    /* 198C 8006A18C 40000224 */  addiu      $v0, $zero, 0x40
    /* 1990 8006A190 0800D1A6 */  sh         $s1, 0x8($s6)
    /* 1994 8006A194 0A00D4A6 */  sh         $s4, 0xA($s6)
    /* 1998 8006A198 1000C2A6 */  sh         $v0, 0x10($s6)
    /* 199C 8006A19C 1200D5A6 */  sh         $s5, 0x12($s6)
    /* 19A0 8006A1A0 0E00D2A6 */  sh         $s2, 0xE($s6)
    /* 19A4 8006A1A4 0600C3A2 */  sb         $v1, 0x6($s6)
    /* 19A8 8006A1A8 0500C3A2 */  sb         $v1, 0x5($s6)
    /* 19AC 8006A1AC 0400C3A2 */  sb         $v1, 0x4($s6)
    /* 19B0 8006A1B0 0400648E */  lw         $a0, (0x1F800004 & 0xFFFF)($s3)
    /* 19B4 8006A1B4 1400D626 */  addiu      $s6, $s6, 0x14
    /* 19B8 8006A1B8 35AD000C */  jal        AddPrim
    /* 19BC 8006A1BC FC1F8424 */   addiu     $a0, $a0, 0x1FFC
    /* 19C0 8006A1C0 2D000424 */  addiu      $a0, $zero, 0x2D
    /* 19C4 8006A1C4 FF070524 */  addiu      $a1, $zero, 0x7FF
    /* 19C8 8006A1C8 56AA010C */  jal        _insertTpage
    /* 19CC 8006A1CC 000076AE */   sw        $s6, (0x1F800000 & 0xFFFF)($s3)
    /* 19D0 8006A1D0 21804000 */  addu       $s0, $v0, $zero
    /* 19D4 8006A1D4 79AD000C */  jal        SetPolyG4
    /* 19D8 8006A1D8 21200002 */   addu      $a0, $s0, $zero
    /* 19DC 8006A1DC 21280002 */  addu       $a1, $s0, $zero
    /* 19E0 8006A1E0 40011224 */  addiu      $s2, $zero, 0x140
    /* 19E4 8006A1E4 1E000224 */  addiu      $v0, $zero, 0x1E
    /* 19E8 8006A1E8 220002A6 */  sh         $v0, 0x22($s0)
    /* 19EC 8006A1EC 1A0002A6 */  sh         $v0, 0x1A($s0)
    /* 19F0 8006A1F0 07000292 */  lbu        $v0, 0x7($s0)
    /* 19F4 8006A1F4 FF001124 */  addiu      $s1, $zero, 0xFF
    /* 19F8 8006A1F8 180000A6 */  sh         $zero, 0x18($s0)
    /* 19FC 8006A1FC 080000A6 */  sh         $zero, 0x8($s0)
    /* 1A00 8006A200 200012A6 */  sh         $s2, 0x20($s0)
    /* 1A04 8006A204 100012A6 */  sh         $s2, 0x10($s0)
    /* 1A08 8006A208 120014A6 */  sh         $s4, 0x12($s0)
    /* 1A0C 8006A20C 0A0014A6 */  sh         $s4, 0xA($s0)
    /* 1A10 8006A210 0E0011A2 */  sb         $s1, 0xE($s0)
    /* 1A14 8006A214 060011A2 */  sb         $s1, 0x6($s0)
    /* 1A18 8006A218 0D0011A2 */  sb         $s1, 0xD($s0)
    /* 1A1C 8006A21C 050011A2 */  sb         $s1, 0x5($s0)
    /* 1A20 8006A220 0C0011A2 */  sb         $s1, 0xC($s0)
    /* 1A24 8006A224 040011A2 */  sb         $s1, 0x4($s0)
    /* 1A28 8006A228 1E0000A2 */  sb         $zero, 0x1E($s0)
    /* 1A2C 8006A22C 160000A2 */  sb         $zero, 0x16($s0)
    /* 1A30 8006A230 1D0000A2 */  sb         $zero, 0x1D($s0)
    /* 1A34 8006A234 150000A2 */  sb         $zero, 0x15($s0)
    /* 1A38 8006A238 1C0000A2 */  sb         $zero, 0x1C($s0)
    /* 1A3C 8006A23C 140000A2 */  sb         $zero, 0x14($s0)
    /* 1A40 8006A240 02004234 */  ori        $v0, $v0, 0x2
    /* 1A44 8006A244 070002A2 */  sb         $v0, 0x7($s0)
    /* 1A48 8006A248 0400648E */  lw         $a0, (0x1F800004 & 0xFFFF)($s3)
    /* 1A4C 8006A24C 24001026 */  addiu      $s0, $s0, 0x24
    /* 1A50 8006A250 35AD000C */  jal        AddPrim
    /* 1A54 8006A254 08008424 */   addiu     $a0, $a0, 0x8
    /* 1A58 8006A258 79AD000C */  jal        SetPolyG4
    /* 1A5C 8006A25C 21200002 */   addu      $a0, $s0, $zero
    /* 1A60 8006A260 21280002 */  addu       $a1, $s0, $zero
    /* 1A64 8006A264 C2000224 */  addiu      $v0, $zero, 0xC2
    /* 1A68 8006A268 120002A6 */  sh         $v0, 0x12($s0)
    /* 1A6C 8006A26C 0A0002A6 */  sh         $v0, 0xA($s0)
    /* 1A70 8006A270 07000292 */  lbu        $v0, 0x7($s0)
    /* 1A74 8006A274 D6001524 */  addiu      $s5, $zero, 0xD6
    /* 1A78 8006A278 180000A6 */  sh         $zero, 0x18($s0)
    /* 1A7C 8006A27C 080000A6 */  sh         $zero, 0x8($s0)
    /* 1A80 8006A280 200012A6 */  sh         $s2, 0x20($s0)
    /* 1A84 8006A284 100012A6 */  sh         $s2, 0x10($s0)
    /* 1A88 8006A288 220015A6 */  sh         $s5, 0x22($s0)
    /* 1A8C 8006A28C 1A0015A6 */  sh         $s5, 0x1A($s0)
    /* 1A90 8006A290 0E0000A2 */  sb         $zero, 0xE($s0)
    /* 1A94 8006A294 060000A2 */  sb         $zero, 0x6($s0)
    /* 1A98 8006A298 0D0000A2 */  sb         $zero, 0xD($s0)
    /* 1A9C 8006A29C 050000A2 */  sb         $zero, 0x5($s0)
    /* 1AA0 8006A2A0 0C0000A2 */  sb         $zero, 0xC($s0)
    /* 1AA4 8006A2A4 040000A2 */  sb         $zero, 0x4($s0)
    /* 1AA8 8006A2A8 1E0011A2 */  sb         $s1, 0x1E($s0)
    /* 1AAC 8006A2AC 160011A2 */  sb         $s1, 0x16($s0)
    /* 1AB0 8006A2B0 1D0011A2 */  sb         $s1, 0x1D($s0)
    /* 1AB4 8006A2B4 150011A2 */  sb         $s1, 0x15($s0)
    /* 1AB8 8006A2B8 1C0011A2 */  sb         $s1, 0x1C($s0)
    /* 1ABC 8006A2BC 140011A2 */  sb         $s1, 0x14($s0)
    /* 1AC0 8006A2C0 02004234 */  ori        $v0, $v0, 0x2
    /* 1AC4 8006A2C4 070002A2 */  sb         $v0, 0x7($s0)
    /* 1AC8 8006A2C8 24001026 */  addiu      $s0, $s0, 0x24
    /* 1ACC 8006A2CC 0400648E */  lw         $a0, (0x1F800004 & 0xFFFF)($s3)
    /* 1AD0 8006A2D0 10001126 */  addiu      $s1, $s0, 0x10
    /* 1AD4 8006A2D4 35AD000C */  jal        AddPrim
    /* 1AD8 8006A2D8 08008424 */   addiu     $a0, $a0, 0x8
    /* 1ADC 8006A2DC 91AD000C */  jal        SetTile
    /* 1AE0 8006A2E0 21200002 */   addu      $a0, $s0, $zero
    /* 1AE4 8006A2E4 060000A2 */  sb         $zero, 0x6($s0)
    /* 1AE8 8006A2E8 050000A2 */  sb         $zero, 0x5($s0)
    /* 1AEC 8006A2EC 040000A2 */  sb         $zero, 0x4($s0)
    /* 1AF0 8006A2F0 0C0012A6 */  sh         $s2, 0xC($s0)
    /* 1AF4 8006A2F4 0E0014A6 */  sh         $s4, 0xE($s0)
    /* 1AF8 8006A2F8 080000A6 */  sh         $zero, 0x8($s0)
    /* 1AFC 8006A2FC 0A0000A6 */  sh         $zero, 0xA($s0)
    /* 1B00 8006A300 0400648E */  lw         $a0, (0x1F800004 & 0xFFFF)($s3)
    /* 1B04 8006A304 21280002 */  addu       $a1, $s0, $zero
    /* 1B08 8006A308 35AD000C */  jal        AddPrim
    /* 1B0C 8006A30C 08008424 */   addiu     $a0, $a0, 0x8
    /* 1B10 8006A310 91AD000C */  jal        SetTile
    /* 1B14 8006A314 21202002 */   addu      $a0, $s1, $zero
    /* 1B18 8006A318 21282002 */  addu       $a1, $s1, $zero
    /* 1B1C 8006A31C 060020A2 */  sb         $zero, 0x6($s1)
    /* 1B20 8006A320 050020A2 */  sb         $zero, 0x5($s1)
    /* 1B24 8006A324 040020A2 */  sb         $zero, 0x4($s1)
    /* 1B28 8006A328 0C0032A6 */  sh         $s2, 0xC($s1)
    /* 1B2C 8006A32C 0E0034A6 */  sh         $s4, 0xE($s1)
    /* 1B30 8006A330 080020A6 */  sh         $zero, 0x8($s1)
    /* 1B34 8006A334 0A0020A6 */  sh         $zero, 0xA($s1)
    /* 1B38 8006A338 0400648E */  lw         $a0, (0x1F800004 & 0xFFFF)($s3)
    /* 1B3C 8006A33C 20001126 */  addiu      $s1, $s0, 0x20
    /* 1B40 8006A340 35AD000C */  jal        AddPrim
    /* 1B44 8006A344 08008424 */   addiu     $a0, $a0, 0x8
    /* 1B48 8006A348 91AD000C */  jal        SetTile
    /* 1B4C 8006A34C 21202002 */   addu      $a0, $s1, $zero
    /* 1B50 8006A350 21282002 */  addu       $a1, $s1, $zero
    /* 1B54 8006A354 060020A2 */  sb         $zero, 0x6($s1)
    /* 1B58 8006A358 050020A2 */  sb         $zero, 0x5($s1)
    /* 1B5C 8006A35C 040020A2 */  sb         $zero, 0x4($s1)
    /* 1B60 8006A360 0C0032A6 */  sh         $s2, 0xC($s1)
    /* 1B64 8006A364 0E0034A6 */  sh         $s4, 0xE($s1)
    /* 1B68 8006A368 080020A6 */  sh         $zero, 0x8($s1)
    /* 1B6C 8006A36C 0A0035A6 */  sh         $s5, 0xA($s1)
    /* 1B70 8006A370 0400648E */  lw         $a0, (0x1F800004 & 0xFFFF)($s3)
    /* 1B74 8006A374 30001126 */  addiu      $s1, $s0, 0x30
    /* 1B78 8006A378 35AD000C */  jal        AddPrim
    /* 1B7C 8006A37C 08008424 */   addiu     $a0, $a0, 0x8
    /* 1B80 8006A380 C0000424 */  addiu      $a0, $zero, 0xC0
    /* 1B84 8006A384 02000524 */  addiu      $a1, $zero, 0x2
    /* 1B88 8006A388 56AA010C */  jal        _insertTpage
    /* 1B8C 8006A38C 000071AE */   sw        $s1, (0x1F800000 & 0xFFFF)($s3)
    /* 1B90 8006A390 000062AE */  sw         $v0, (0x1F800000 & 0xFFFF)($s3)
    /* 1B94 8006A394 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 1B98 8006A398 2800B68F */  lw         $s6, 0x28($sp)
    /* 1B9C 8006A39C 2400B58F */  lw         $s5, 0x24($sp)
    /* 1BA0 8006A3A0 2000B48F */  lw         $s4, 0x20($sp)
    /* 1BA4 8006A3A4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1BA8 8006A3A8 1800B28F */  lw         $s2, 0x18($sp)
    /* 1BAC 8006A3AC 1400B18F */  lw         $s1, 0x14($sp)
    /* 1BB0 8006A3B0 1000B08F */  lw         $s0, 0x10($sp)
    /* 1BB4 8006A3B4 0800E003 */  jr         $ra
    /* 1BB8 8006A3B8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8006A0D8
