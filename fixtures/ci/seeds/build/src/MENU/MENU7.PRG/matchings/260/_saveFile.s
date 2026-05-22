nonmatching _saveFile, 0x380

glabel _saveFile
    /* 1844 80104044 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1848 80104048 21288000 */  addu       $a1, $a0, $zero
    /* 184C 8010404C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1850 80104050 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1854 80104054 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1858 80104058 1400B1AF */  sw         $s1, 0x14($sp)
    /* 185C 8010405C 1900A010 */  beqz       $a1, .L801040C4
    /* 1860 80104060 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1864 80104064 1180023C */  lui        $v0, %hi(_saveFileErrors)
    /* 1868 80104068 93AA40A0 */  sb         $zero, %lo(_saveFileErrors)($v0)
    /* 186C 8010406C 1180023C */  lui        $v0, %hi(_saveFileRenameErrors)
    /* 1870 80104070 94AA40A0 */  sb         $zero, %lo(_saveFileRenameErrors)($v0)
    /* 1874 80104074 1180023C */  lui        $v0, %hi(_loadSaveDataErrorOffset)
    /* 1878 80104078 1180033C */  lui        $v1, %hi(_saveFilePort)
    /* 187C 8010407C 44AE40A0 */  sb         $zero, %lo(_loadSaveDataErrorOffset)($v0)
    /* 1880 80104080 03130500 */  sra        $v0, $a1, 12
    /* 1884 80104084 1180043C */  lui        $a0, %hi(_saveFileFile)
    /* 1888 80104088 92AA62A0 */  sb         $v0, %lo(_saveFilePort)($v1)
    /* 188C 8010408C 0700A230 */  andi       $v0, $a1, 0x7
    /* 1890 80104090 1180033C */  lui        $v1, %hi(_fileProgressPosition)
    /* 1894 80104094 91AA82A0 */  sb         $v0, %lo(_saveFileFile)($a0)
    /* 1898 80104098 91AA8490 */  lbu        $a0, %lo(_saveFileFile)($a0)
    /* 189C 8010409C 50000224 */  addiu      $v0, $zero, 0x50
    /* 18A0 801040A0 4AAE62A4 */  sh         $v0, %lo(_fileProgressPosition)($v1)
    /* 18A4 801040A4 1180023C */  lui        $v0, %hi(_filePreviousProgressCounter)
    /* 18A8 801040A8 48AE40A4 */  sh         $zero, %lo(_filePreviousProgressCounter)($v0)
    /* 18AC 801040AC 030C040C */  jal        _memcardSaveIdExists
    /* 18B0 801040B0 40008424 */   addiu     $a0, $a0, 0x40
    /* 18B4 801040B4 1180033C */  lui        $v1, %hi(_saveFileState)
    /* 18B8 801040B8 90AA62A0 */  sb         $v0, %lo(_saveFileState)($v1)
    /* 18BC 801040BC EA100408 */  j          .L801043A8
    /* 18C0 801040C0 21100000 */   addu      $v0, $zero, $zero
  .L801040C4:
    /* 18C4 801040C4 1180023C */  lui        $v0, %hi(_saveFileState)
    /* 18C8 801040C8 90AA4390 */  lbu        $v1, %lo(_saveFileState)($v0)
    /* 18CC 801040CC 00000000 */  nop
    /* 18D0 801040D0 0500622C */  sltiu      $v0, $v1, 0x5
    /* 18D4 801040D4 AD004010 */  beqz       $v0, .L8010438C
    /* 18D8 801040D8 1080023C */   lui       $v0, %hi(jtbl_801028B0)
    /* 18DC 801040DC B0284224 */  addiu      $v0, $v0, %lo(jtbl_801028B0)
    /* 18E0 801040E0 80180300 */  sll        $v1, $v1, 2
    /* 18E4 801040E4 21186200 */  addu       $v1, $v1, $v0
    /* 18E8 801040E8 0000628C */  lw         $v0, 0x0($v1)
    /* 18EC 801040EC 00000000 */  nop
    /* 18F0 801040F0 08004000 */  jr         $v0
    /* 18F4 801040F4 00000000 */   nop
    /* 18F8 801040F8 1180113C */  lui        $s1, %hi(_saveFilePort)
    /* 18FC 801040FC 1180103C */  lui        $s0, %hi(_saveFileFile)
    /* 1900 80104100 92AA2492 */  lbu        $a0, %lo(_saveFilePort)($s1)
    /* 1904 80104104 91AA0592 */  lbu        $a1, %lo(_saveFileFile)($s0)
    /* 1908 80104108 EF0A040C */  jal        _memcardMakeFilename
    /* 190C 8010410C 00000000 */   nop
    /* 1910 80104110 92AA2492 */  lbu        $a0, %lo(_saveFilePort)($s1)
    /* 1914 80104114 91AA0592 */  lbu        $a1, %lo(_saveFileFile)($s0)
    /* 1918 80104118 0E0B040C */  jal        _memcardMakeTempFilename
    /* 191C 8010411C 21804000 */   addu      $s0, $v0, $zero
    /* 1920 80104120 21200002 */  addu       $a0, $s0, $zero
    /* 1924 80104124 799A000C */  jal        rename
    /* 1928 80104128 21284000 */   addu      $a1, $v0, $zero
    /* 192C 8010412C 8E004010 */  beqz       $v0, .L80104368
    /* 1930 80104130 1180023C */   lui       $v0, %hi(_saveFileErrors)
    /* 1934 80104134 93AA40A0 */  sb         $zero, %lo(_saveFileErrors)($v0)
    /* 1938 80104138 1180023C */  lui        $v0, %hi(_saveFileRenameErrors)
    /* 193C 8010413C 1180033C */  lui        $v1, %hi(_saveFileState)
    /* 1940 80104140 94AA40A0 */  sb         $zero, %lo(_saveFileRenameErrors)($v0)
    /* 1944 80104144 01000224 */  addiu      $v0, $zero, 0x1
    /* 1948 80104148 E3100408 */  j          .L8010438C
    /* 194C 8010414C 90AA62A0 */   sb        $v0, %lo(_saveFileState)($v1)
    /* 1950 80104150 1180063C */  lui        $a2, %hi(_fileProgressCounter)
    /* 1954 80104154 11800A3C */  lui        $t2, %hi(_filePreviousProgressCounter)
    /* 1958 80104158 1180093C */  lui        $t1, %hi(_fileProgressPosition)
    /* 195C 8010415C 48AE4295 */  lhu        $v0, %lo(_filePreviousProgressCounter)($t2)
    /* 1960 80104160 4CAEC38C */  lw         $v1, %lo(_fileProgressCounter)($a2)
    /* 1964 80104164 4AAE2795 */  lhu        $a3, %lo(_fileProgressPosition)($t1)
    /* 1968 80104168 23186200 */  subu       $v1, $v1, $v0
    /* 196C 8010416C 40010224 */  addiu      $v0, $zero, 0x140
    /* 1970 80104170 23104700 */  subu       $v0, $v0, $a3
    /* 1974 80104174 18006200 */  mult       $v1, $v0
    /* 1978 80104178 1180083C */  lui        $t0, %hi(_fileProgressTarget)
    /* 197C 8010417C 12600000 */  mflo       $t4
    /* 1980 80104180 46AE0395 */  lhu        $v1, %lo(_fileProgressTarget)($t0)
    /* 1984 80104184 00000000 */  nop
    /* 1988 80104188 1A008301 */  div        $zero, $t4, $v1
    /* 198C 8010418C 12180000 */  mflo       $v1
    /* 1990 80104190 4CAEC694 */  lhu        $a2, %lo(_fileProgressCounter)($a2)
    /* 1994 80104194 00000000 */  nop
    /* 1998 80104198 48AE46A5 */  sh         $a2, %lo(_filePreviousProgressCounter)($t2)
    /* 199C 8010419C 1180023C */  lui        $v0, %hi(_saveFilePort)
    /* 19A0 801041A0 92AA4490 */  lbu        $a0, %lo(_saveFilePort)($v0)
    /* 19A4 801041A4 1180023C */  lui        $v0, %hi(_saveFileFile)
    /* 19A8 801041A8 91AA4590 */  lbu        $a1, %lo(_saveFileFile)($v0)
    /* 19AC 801041AC 80010224 */  addiu      $v0, $zero, 0x180
    /* 19B0 801041B0 46AE02A5 */  sh         $v0, %lo(_fileProgressTarget)($t0)
    /* 19B4 801041B4 2138E300 */  addu       $a3, $a3, $v1
    /* 19B8 801041B8 0E0B040C */  jal        _memcardMakeTempFilename
    /* 19BC 801041BC 4AAE27A5 */   sh        $a3, %lo(_fileProgressPosition)($t1)
    /* 19C0 801041C0 21204000 */  addu       $a0, $v0, $zero
    /* 19C4 801041C4 659A000C */  jal        open
    /* 19C8 801041C8 02800534 */   ori       $a1, $zero, 0x8002
    /* 19CC 801041CC 1180103C */  lui        $s0, %hi(_saveFileFd)
    /* 19D0 801041D0 FFFF1124 */  addiu      $s1, $zero, -0x1
    /* 19D4 801041D4 0D005110 */  beq        $v0, $s1, .L8010420C
    /* 19D8 801041D8 98AA02AE */   sw        $v0, %lo(_saveFileFd)($s0)
    /* 19DC 801041DC B70A040C */  jal        _resetMemcardEvents
    /* 19E0 801041E0 21200000 */   addu      $a0, $zero, $zero
    /* 19E4 801041E4 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 19E8 801041E8 98AA048E */  lw         $a0, %lo(_saveFileFd)($s0)
    /* 19EC 801041EC F0AD458C */  lw         $a1, %lo(_spmcimg)($v0)
    /* 19F0 801041F0 6D9A000C */  jal        write
    /* 19F4 801041F4 005C0624 */   addiu     $a2, $zero, 0x5C00
    /* 19F8 801041F8 0A005114 */  bne        $v0, $s1, .L80104224
    /* 19FC 801041FC 1180033C */   lui       $v1, %hi(_saveFileState)
    /* 1A00 80104200 98AA048E */  lw         $a0, %lo(_saveFileFd)($s0)
    /* 1A04 80104204 719A000C */  jal        close
    /* 1A08 80104208 00000000 */   nop
  .L8010420C:
    /* 1A0C 8010420C 1180033C */  lui        $v1, %hi(_saveFileErrors)
    /* 1A10 80104210 93AA6290 */  lbu        $v0, %lo(_saveFileErrors)($v1)
    /* 1A14 80104214 00000000 */  nop
    /* 1A18 80104218 01004224 */  addiu      $v0, $v0, 0x1
    /* 1A1C 8010421C E3100408 */  j          .L8010438C
    /* 1A20 80104220 93AA62A0 */   sb        $v0, %lo(_saveFileErrors)($v1)
  .L80104224:
    /* 1A24 80104224 02000224 */  addiu      $v0, $zero, 0x2
    /* 1A28 80104228 90AA62A0 */  sb         $v0, %lo(_saveFileState)($v1)
    /* 1A2C 8010422C 980A040C */  jal        _testMemcardEvents
    /* 1A30 80104230 21200000 */   addu      $a0, $zero, $zero
    /* 1A34 80104234 21984000 */  addu       $s3, $v0, $zero
    /* 1A38 80104238 0400622A */  slti       $v0, $s3, 0x4
    /* 1A3C 8010423C 53004010 */  beqz       $v0, .L8010438C
    /* 1A40 80104240 1180023C */   lui       $v0, %hi(_saveFileFd)
    /* 1A44 80104244 98AA448C */  lw         $a0, %lo(_saveFileFd)($v0)
    /* 1A48 80104248 719A000C */  jal        close
    /* 1A4C 8010424C 00000000 */   nop
    /* 1A50 80104250 13006016 */  bnez       $s3, .L801042A0
    /* 1A54 80104254 1180053C */   lui       $a1, %hi(_saveFileErrors)
    /* 1A58 80104258 1180113C */  lui        $s1, %hi(_fileProgressPosition)
    /* 1A5C 8010425C 1180103C */  lui        $s0, %hi(_filePreviousProgressCounter)
    /* 1A60 80104260 1180033C */  lui        $v1, %hi(_saveFileState)
    /* 1A64 80104264 03000224 */  addiu      $v0, $zero, 0x3
    /* 1A68 80104268 90AA62A0 */  sb         $v0, %lo(_saveFileState)($v1)
    /* 1A6C 8010426C 1180023C */  lui        $v0, %hi(_saveFilePort)
    /* 1A70 80104270 1180033C */  lui        $v1, %hi(_saveFileFile)
    /* 1A74 80104274 4AAE3296 */  lhu        $s2, %lo(_fileProgressPosition)($s1)
    /* 1A78 80104278 48AE1396 */  lhu        $s3, %lo(_filePreviousProgressCounter)($s0)
    /* 1A7C 8010427C 92AA4290 */  lbu        $v0, %lo(_saveFilePort)($v0)
    /* 1A80 80104280 91AA6490 */  lbu        $a0, %lo(_saveFileFile)($v1)
    /* 1A84 80104284 00130200 */  sll        $v0, $v0, 12
    /* 1A88 80104288 08008424 */  addiu      $a0, $a0, 0x8
    /* 1A8C 8010428C 740F040C */  jal        _loadSaveData
    /* 1A90 80104290 25204400 */   or        $a0, $v0, $a0
    /* 1A94 80104294 4AAE32A6 */  sh         $s2, %lo(_fileProgressPosition)($s1)
    /* 1A98 80104298 E3100408 */  j          .L8010438C
    /* 1A9C 8010429C 48AE13A6 */   sh        $s3, %lo(_filePreviousProgressCounter)($s0)
  .L801042A0:
    /* 1AA0 801042A0 1180043C */  lui        $a0, %hi(_saveFileState)
    /* 1AA4 801042A4 93AAA290 */  lbu        $v0, %lo(_saveFileErrors)($a1)
    /* 1AA8 801042A8 01000324 */  addiu      $v1, $zero, 0x1
    /* 1AAC 801042AC 90AA83A0 */  sb         $v1, %lo(_saveFileState)($a0)
    /* 1AB0 801042B0 01004224 */  addiu      $v0, $v0, 0x1
    /* 1AB4 801042B4 E3100408 */  j          .L8010438C
    /* 1AB8 801042B8 93AAA2A0 */   sb        $v0, %lo(_saveFileErrors)($a1)
    /* 1ABC 801042BC 740F040C */  jal        _loadSaveData
    /* 1AC0 801042C0 21200000 */   addu      $a0, $zero, $zero
    /* 1AC4 801042C4 21984000 */  addu       $s3, $v0, $zero
    /* 1AC8 801042C8 31006012 */  beqz       $s3, .L80104390
    /* 1ACC 801042CC 1180023C */   lui       $v0, %hi(_saveFileErrors)
    /* 1AD0 801042D0 11006006 */  bltz       $s3, .L80104318
    /* 1AD4 801042D4 21900000 */   addu      $s2, $zero, $zero
    /* 1AD8 801042D8 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 1ADC 801042DC F0AD448C */  lw         $a0, %lo(_spmcimg)($v0)
    /* 1AE0 801042E0 00000000 */  nop
    /* 1AE4 801042E4 21109200 */  addu       $v0, $a0, $s2
  .L801042E8:
    /* 1AE8 801042E8 00004390 */  lbu        $v1, 0x0($v0)
    /* 1AEC 801042EC 005C4290 */  lbu        $v0, 0x5C00($v0)
    /* 1AF0 801042F0 00000000 */  nop
    /* 1AF4 801042F4 06006214 */  bne        $v1, $v0, .L80104310
    /* 1AF8 801042F8 005C422A */   slti      $v0, $s2, 0x5C00
    /* 1AFC 801042FC 01005226 */  addiu      $s2, $s2, 0x1
    /* 1B00 80104300 005C422A */  slti       $v0, $s2, 0x5C00
    /* 1B04 80104304 F8FF4014 */  bnez       $v0, .L801042E8
    /* 1B08 80104308 21109200 */   addu      $v0, $a0, $s2
    /* 1B0C 8010430C 005C422A */  slti       $v0, $s2, 0x5C00
  .L80104310:
    /* 1B10 80104310 03004010 */  beqz       $v0, .L80104320
    /* 1B14 80104314 1180033C */   lui       $v1, %hi(_saveFileState)
  .L80104318:
    /* 1B18 80104318 EA100408 */  j          .L801043A8
    /* 1B1C 8010431C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80104320:
    /* 1B20 80104320 04000224 */  addiu      $v0, $zero, 0x4
    /* 1B24 80104324 E3100408 */  j          .L8010438C
    /* 1B28 80104328 90AA62A0 */   sb        $v0, %lo(_saveFileState)($v1)
    /* 1B2C 8010432C 1180113C */  lui        $s1, %hi(_saveFilePort)
    /* 1B30 80104330 1180103C */  lui        $s0, %hi(_saveFileFile)
    /* 1B34 80104334 92AA2492 */  lbu        $a0, %lo(_saveFilePort)($s1)
    /* 1B38 80104338 91AA0592 */  lbu        $a1, %lo(_saveFileFile)($s0)
    /* 1B3C 8010433C 0E0B040C */  jal        _memcardMakeTempFilename
    /* 1B40 80104340 00000000 */   nop
    /* 1B44 80104344 92AA2492 */  lbu        $a0, %lo(_saveFilePort)($s1)
    /* 1B48 80104348 91AA0592 */  lbu        $a1, %lo(_saveFileFile)($s0)
    /* 1B4C 8010434C EF0A040C */  jal        _memcardMakeFilename
    /* 1B50 80104350 21804000 */   addu      $s0, $v0, $zero
    /* 1B54 80104354 21200002 */  addu       $a0, $s0, $zero
    /* 1B58 80104358 799A000C */  jal        rename
    /* 1B5C 8010435C 21284000 */   addu      $a1, $v0, $zero
    /* 1B60 80104360 11004014 */  bnez       $v0, .L801043A8
    /* 1B64 80104364 01000224 */   addiu     $v0, $zero, 0x1
  .L80104368:
    /* 1B68 80104368 1180023C */  lui        $v0, %hi(_saveFileRenameErrors)
    /* 1B6C 8010436C 94AA4390 */  lbu        $v1, %lo(_saveFileRenameErrors)($v0)
    /* 1B70 80104370 00000000 */  nop
    /* 1B74 80104374 01006324 */  addiu      $v1, $v1, 0x1
    /* 1B78 80104378 94AA43A0 */  sb         $v1, %lo(_saveFileRenameErrors)($v0)
    /* 1B7C 8010437C 1180023C */  lui        $v0, %hi(_saveFileErrors)
    /* 1B80 80104380 FF006330 */  andi       $v1, $v1, 0xFF
    /* 1B84 80104384 02190300 */  srl        $v1, $v1, 4
    /* 1B88 80104388 93AA43A0 */  sb         $v1, %lo(_saveFileErrors)($v0)
  .L8010438C:
    /* 1B8C 8010438C 1180023C */  lui        $v0, %hi(_saveFileErrors)
  .L80104390:
    /* 1B90 80104390 93AA4390 */  lbu        $v1, %lo(_saveFileErrors)($v0)
    /* 1B94 80104394 03000224 */  addiu      $v0, $zero, 0x3
    /* 1B98 80104398 02006214 */  bne        $v1, $v0, .L801043A4
    /* 1B9C 8010439C 21200000 */   addu      $a0, $zero, $zero
    /* 1BA0 801043A0 FFFF0424 */  addiu      $a0, $zero, -0x1
  .L801043A4:
    /* 1BA4 801043A4 21108000 */  addu       $v0, $a0, $zero
  .L801043A8:
    /* 1BA8 801043A8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1BAC 801043AC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1BB0 801043B0 1800B28F */  lw         $s2, 0x18($sp)
    /* 1BB4 801043B4 1400B18F */  lw         $s1, 0x14($sp)
    /* 1BB8 801043B8 1000B08F */  lw         $s0, 0x10($sp)
    /* 1BBC 801043BC 0800E003 */  jr         $ra
    /* 1BC0 801043C0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _saveFile
