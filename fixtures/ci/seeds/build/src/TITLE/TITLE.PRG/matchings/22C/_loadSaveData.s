nonmatching _loadSaveData, 0x274

glabel _loadSaveData
    /* 16A8 80069EA8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 16AC 80069EAC 0E80023C */  lui        $v0, %hi(_spmcimg)
    /* 16B0 80069EB0 B8EA428C */  lw         $v0, %lo(_spmcimg)($v0)
    /* 16B4 80069EB4 21288000 */  addu       $a1, $a0, $zero
    /* 16B8 80069EB8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 16BC 80069EBC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 16C0 80069EC0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 16C4 80069EC4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 16C8 80069EC8 1800A010 */  beqz       $a1, .L80069F2C
    /* 16CC 80069ECC 005C5224 */   addiu     $s2, $v0, 0x5C00
    /* 16D0 80069ED0 21100000 */  addu       $v0, $zero, $zero
    /* 16D4 80069ED4 0E80033C */  lui        $v1, %hi(_loadSaveDataState)
    /* 16D8 80069ED8 ADC860A0 */  sb         $zero, %lo(_loadSaveDataState)($v1)
    /* 16DC 80069EDC 0E80033C */  lui        $v1, %hi(_loadSaveDataErrors)
    /* 16E0 80069EE0 B1C860A0 */  sb         $zero, %lo(_loadSaveDataErrors)($v1)
    /* 16E4 80069EE4 0E80033C */  lui        $v1, %hi(_loadSaveDataErrorOffset)
    /* 16E8 80069EE8 0E80043C */  lui        $a0, %hi(_readCardPort)
    /* 16EC 80069EEC 0CEB60A0 */  sb         $zero, %lo(_loadSaveDataErrorOffset)($v1)
    /* 16F0 80069EF0 031B0500 */  sra        $v1, $a1, 12
    /* 16F4 80069EF4 AEC883A0 */  sb         $v1, %lo(_readCardPort)($a0)
    /* 16F8 80069EF8 0E80043C */  lui        $a0, %hi(_isTempSave)
    /* 16FC 80069EFC 031A0500 */  sra        $v1, $a1, 8
    /* 1700 80069F00 01006330 */  andi       $v1, $v1, 0x1
    /* 1704 80069F04 B0C883A0 */  sb         $v1, %lo(_isTempSave)($a0)
    /* 1708 80069F08 0E80043C */  lui        $a0, %hi(_readFileNo)
    /* 170C 80069F0C 0F00A330 */  andi       $v1, $a1, 0xF
    /* 1710 80069F10 AFC883A0 */  sb         $v1, %lo(_readFileNo)($a0)
    /* 1714 80069F14 0E80043C */  lui        $a0, %hi(_fileProgressPosition)
    /* 1718 80069F18 50000324 */  addiu      $v1, $zero, 0x50
    /* 171C 80069F1C 12EB83A4 */  sh         $v1, %lo(_fileProgressPosition)($a0)
    /* 1720 80069F20 0E80033C */  lui        $v1, %hi(_filePreviousProgressCounter)
    /* 1724 80069F24 41A80108 */  j          .L8006A104
    /* 1728 80069F28 10EB60A4 */   sh        $zero, %lo(_filePreviousProgressCounter)($v1)
  .L80069F2C:
    /* 172C 80069F2C 0E80023C */  lui        $v0, %hi(_loadSaveDataState)
    /* 1730 80069F30 ADC84390 */  lbu        $v1, %lo(_loadSaveDataState)($v0)
    /* 1734 80069F34 00000000 */  nop
    /* 1738 80069F38 05006010 */  beqz       $v1, .L80069F50
    /* 173C 80069F3C 01000224 */   addiu     $v0, $zero, 0x1
    /* 1740 80069F40 57006210 */  beq        $v1, $v0, .L8006A0A0
    /* 1744 80069F44 21200000 */   addu      $a0, $zero, $zero
    /* 1748 80069F48 3BA80108 */  j          .L8006A0EC
    /* 174C 80069F4C 0E80023C */   lui       $v0, %hi(_loadSaveDataErrors)
  .L80069F50:
    /* 1750 80069F50 0E800D3C */  lui        $t5, %hi(_fileProgressPosition)
    /* 1754 80069F54 0E800B3C */  lui        $t3, %hi(_fileProgressCounter)
    /* 1758 80069F58 0E800C3C */  lui        $t4, %hi(_filePreviousProgressCounter)
    /* 175C 80069F5C 0E80073C */  lui        $a3, %hi(_loadSaveDataErrorOffset)
    /* 1760 80069F60 10EB8295 */  lhu        $v0, %lo(_filePreviousProgressCounter)($t4)
    /* 1764 80069F64 14EB648D */  lw         $a0, %lo(_fileProgressCounter)($t3)
    /* 1768 80069F68 0CEBE390 */  lbu        $v1, %lo(_loadSaveDataErrorOffset)($a3)
    /* 176C 80069F6C 12EBA995 */  lhu        $t1, %lo(_fileProgressPosition)($t5)
    /* 1770 80069F70 23208200 */  subu       $a0, $a0, $v0
    /* 1774 80069F74 80100300 */  sll        $v0, $v1, 2
    /* 1778 80069F78 21104300 */  addu       $v0, $v0, $v1
    /* 177C 80069F7C 80100200 */  sll        $v0, $v0, 2
    /* 1780 80069F80 C0FE2325 */  addiu      $v1, $t1, -0x140
    /* 1784 80069F84 23104300 */  subu       $v0, $v0, $v1
    /* 1788 80069F88 18008200 */  mult       $a0, $v0
    /* 178C 80069F8C 0E800A3C */  lui        $t2, %hi(_fileProgressTarget)
    /* 1790 80069F90 12180000 */  mflo       $v1
    /* 1794 80069F94 0EEB4895 */  lhu        $t0, %lo(_fileProgressTarget)($t2)
    /* 1798 80069F98 00000000 */  nop
    /* 179C 80069F9C 1A006800 */  div        $zero, $v1, $t0
    /* 17A0 80069FA0 12400000 */  mflo       $t0
    /* 17A4 80069FA4 21280000 */  addu       $a1, $zero, $zero
    /* 17A8 80069FA8 005C0624 */  addiu      $a2, $zero, 0x5C00
    /* 17AC 80069FAC 21204002 */  addu       $a0, $s2, $zero
    /* 17B0 80069FB0 0E80023C */  lui        $v0, %hi(_loadSaveDataErrors)
    /* 17B4 80069FB4 0E80033C */  lui        $v1, %hi(_isTempSave)
    /* 17B8 80069FB8 B0C86390 */  lbu        $v1, %lo(_isTempSave)($v1)
    /* 17BC 80069FBC B1C84290 */  lbu        $v0, %lo(_loadSaveDataErrors)($v0)
    /* 17C0 80069FC0 C0190300 */  sll        $v1, $v1, 7
    /* 17C4 80069FC4 0CEBE2A0 */  sb         $v0, %lo(_loadSaveDataErrorOffset)($a3)
    /* 17C8 80069FC8 C0000224 */  addiu      $v0, $zero, 0xC0
    /* 17CC 80069FCC 14EB6795 */  lhu        $a3, %lo(_fileProgressCounter)($t3)
    /* 17D0 80069FD0 23104300 */  subu       $v0, $v0, $v1
    /* 17D4 80069FD4 0EEB42A5 */  sh         $v0, %lo(_fileProgressTarget)($t2)
    /* 17D8 80069FD8 10EB87A5 */  sh         $a3, %lo(_filePreviousProgressCounter)($t4)
    /* 17DC 80069FDC 21482801 */  addu       $t1, $t1, $t0
    /* 17E0 80069FE0 AD9B000C */  jal        memset
    /* 17E4 80069FE4 12EBA9A5 */   sh        $t1, %lo(_fileProgressPosition)($t5)
    /* 17E8 80069FE8 0E80033C */  lui        $v1, %hi(_readFileNo)
    /* 17EC 80069FEC AFC86590 */  lbu        $a1, %lo(_readFileNo)($v1)
    /* 17F0 80069FF0 00000000 */  nop
    /* 17F4 80069FF4 0800A230 */  andi       $v0, $a1, 0x8
    /* 17F8 80069FF8 06004010 */  beqz       $v0, .L8006A014
    /* 17FC 80069FFC 0E80023C */   lui       $v0, %hi(_readCardPort)
    /* 1800 8006A000 AEC84490 */  lbu        $a0, %lo(_readCardPort)($v0)
    /* 1804 8006A004 36A3010C */  jal        _memcardMakeTempFilename
    /* 1808 8006A008 0700A530 */   andi      $a1, $a1, 0x7
    /* 180C 8006A00C 0AA80108 */  j          .L8006A028
    /* 1810 8006A010 21204000 */   addu      $a0, $v0, $zero
  .L8006A014:
    /* 1814 8006A014 AEC84490 */  lbu        $a0, %lo(_readCardPort)($v0)
    /* 1818 8006A018 AFC86590 */  lbu        $a1, %lo(_readFileNo)($v1)
    /* 181C 8006A01C 17A3010C */  jal        _memcardMakeFilename
    /* 1820 8006A020 00000000 */   nop
    /* 1824 8006A024 21204000 */  addu       $a0, $v0, $zero
  .L8006A028:
    /* 1828 8006A028 659A000C */  jal        open
    /* 182C 8006A02C 01800534 */   ori       $a1, $zero, 0x8001
    /* 1830 8006A030 0E80103C */  lui        $s0, %hi(_memCardFd)
    /* 1834 8006A034 FFFF1124 */  addiu      $s1, $zero, -0x1
    /* 1838 8006A038 11005110 */  beq        $v0, $s1, .L8006A080
    /* 183C 8006A03C B4C802AE */   sw        $v0, %lo(_memCardFd)($s0)
    /* 1840 8006A040 DFA2010C */  jal        _resetMemcardEvents
    /* 1844 8006A044 21200000 */   addu      $a0, $zero, $zero
    /* 1848 8006A048 0E80023C */  lui        $v0, %hi(_isTempSave)
    /* 184C 8006A04C B0C84290 */  lbu        $v0, %lo(_isTempSave)($v0)
    /* 1850 8006A050 00000000 */  nop
    /* 1854 8006A054 02004010 */  beqz       $v0, .L8006A060
    /* 1858 8006A058 005C0624 */   addiu     $a2, $zero, 0x5C00
    /* 185C 8006A05C 00200624 */  addiu      $a2, $zero, 0x2000
  .L8006A060:
    /* 1860 8006A060 B4C8048E */  lw         $a0, %lo(_memCardFd)($s0)
    /* 1864 8006A064 699A000C */  jal        read
    /* 1868 8006A068 21284002 */   addu      $a1, $s2, $zero
    /* 186C 8006A06C 0A005114 */  bne        $v0, $s1, .L8006A098
    /* 1870 8006A070 0E80033C */   lui       $v1, %hi(_loadSaveDataState)
    /* 1874 8006A074 B4C8048E */  lw         $a0, %lo(_memCardFd)($s0)
    /* 1878 8006A078 719A000C */  jal        close
    /* 187C 8006A07C 00000000 */   nop
  .L8006A080:
    /* 1880 8006A080 0E80033C */  lui        $v1, %hi(_loadSaveDataErrors)
    /* 1884 8006A084 B1C86290 */  lbu        $v0, %lo(_loadSaveDataErrors)($v1)
    /* 1888 8006A088 00000000 */  nop
    /* 188C 8006A08C 01004224 */  addiu      $v0, $v0, 0x1
    /* 1890 8006A090 39A80108 */  j          .L8006A0E4
    /* 1894 8006A094 B1C862A0 */   sb        $v0, %lo(_loadSaveDataErrors)($v1)
  .L8006A098:
    /* 1898 8006A098 01000224 */  addiu      $v0, $zero, 0x1
    /* 189C 8006A09C ADC862A0 */  sb         $v0, %lo(_loadSaveDataState)($v1)
  .L8006A0A0:
    /* 18A0 8006A0A0 C0A2010C */  jal        _testMemcardEvents
    /* 18A4 8006A0A4 21200000 */   addu      $a0, $zero, $zero
    /* 18A8 8006A0A8 21804000 */  addu       $s0, $v0, $zero
    /* 18AC 8006A0AC 0400022A */  slti       $v0, $s0, 0x4
    /* 18B0 8006A0B0 0C004010 */  beqz       $v0, .L8006A0E4
    /* 18B4 8006A0B4 0E80023C */   lui       $v0, %hi(_memCardFd)
    /* 18B8 8006A0B8 B4C8448C */  lw         $a0, %lo(_memCardFd)($v0)
    /* 18BC 8006A0BC 719A000C */  jal        close
    /* 18C0 8006A0C0 00000000 */   nop
    /* 18C4 8006A0C4 0F000012 */  beqz       $s0, .L8006A104
    /* 18C8 8006A0C8 01000224 */   addiu     $v0, $zero, 0x1
    /* 18CC 8006A0CC 0E80023C */  lui        $v0, %hi(_loadSaveDataErrors)
    /* 18D0 8006A0D0 B1C84390 */  lbu        $v1, %lo(_loadSaveDataErrors)($v0)
    /* 18D4 8006A0D4 0E80043C */  lui        $a0, %hi(_loadSaveDataState)
    /* 18D8 8006A0D8 ADC880A0 */  sb         $zero, %lo(_loadSaveDataState)($a0)
    /* 18DC 8006A0DC 01006324 */  addiu      $v1, $v1, 0x1
    /* 18E0 8006A0E0 B1C843A0 */  sb         $v1, %lo(_loadSaveDataErrors)($v0)
  .L8006A0E4:
    /* 18E4 8006A0E4 21200000 */  addu       $a0, $zero, $zero
    /* 18E8 8006A0E8 0E80023C */  lui        $v0, %hi(_loadSaveDataErrors)
  .L8006A0EC:
    /* 18EC 8006A0EC B1C84390 */  lbu        $v1, %lo(_loadSaveDataErrors)($v0)
    /* 18F0 8006A0F0 03000224 */  addiu      $v0, $zero, 0x3
    /* 18F4 8006A0F4 03006214 */  bne        $v1, $v0, .L8006A104
    /* 18F8 8006A0F8 21108000 */   addu      $v0, $a0, $zero
    /* 18FC 8006A0FC FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 1900 8006A100 21108000 */  addu       $v0, $a0, $zero
  .L8006A104:
    /* 1904 8006A104 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1908 8006A108 1800B28F */  lw         $s2, 0x18($sp)
    /* 190C 8006A10C 1400B18F */  lw         $s1, 0x14($sp)
    /* 1910 8006A110 1000B08F */  lw         $s0, 0x10($sp)
    /* 1914 8006A114 0800E003 */  jr         $ra
    /* 1918 8006A118 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _loadSaveData
