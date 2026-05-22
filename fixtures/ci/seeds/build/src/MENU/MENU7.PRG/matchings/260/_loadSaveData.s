nonmatching _loadSaveData, 0x274

glabel _loadSaveData
    /* 15D0 80103DD0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 15D4 80103DD4 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 15D8 80103DD8 F0AD428C */  lw         $v0, %lo(_spmcimg)($v0)
    /* 15DC 80103DDC 21288000 */  addu       $a1, $a0, $zero
    /* 15E0 80103DE0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 15E4 80103DE4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 15E8 80103DE8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 15EC 80103DEC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 15F0 80103DF0 1800A010 */  beqz       $a1, .L80103E54
    /* 15F4 80103DF4 005C5224 */   addiu     $s2, $v0, 0x5C00
    /* 15F8 80103DF8 21100000 */  addu       $v0, $zero, $zero
    /* 15FC 80103DFC 1180033C */  lui        $v1, %hi(_loadSaveDataState)
    /* 1600 80103E00 85AA60A0 */  sb         $zero, %lo(_loadSaveDataState)($v1)
    /* 1604 80103E04 1180033C */  lui        $v1, %hi(_loadSaveDataErrors)
    /* 1608 80103E08 89AA60A0 */  sb         $zero, %lo(_loadSaveDataErrors)($v1)
    /* 160C 80103E0C 1180033C */  lui        $v1, %hi(_loadSaveDataErrorOffset)
    /* 1610 80103E10 1180043C */  lui        $a0, %hi(_loadSaveDataPort)
    /* 1614 80103E14 44AE60A0 */  sb         $zero, %lo(_loadSaveDataErrorOffset)($v1)
    /* 1618 80103E18 031B0500 */  sra        $v1, $a1, 12
    /* 161C 80103E1C 86AA83A0 */  sb         $v1, %lo(_loadSaveDataPort)($a0)
    /* 1620 80103E20 1180043C */  lui        $a0, %hi(_isTempSave)
    /* 1624 80103E24 031A0500 */  sra        $v1, $a1, 8
    /* 1628 80103E28 01006330 */  andi       $v1, $v1, 0x1
    /* 162C 80103E2C 88AA83A0 */  sb         $v1, %lo(_isTempSave)($a0)
    /* 1630 80103E30 1180043C */  lui        $a0, %hi(_loadSaveDataFile)
    /* 1634 80103E34 0F00A330 */  andi       $v1, $a1, 0xF
    /* 1638 80103E38 87AA83A0 */  sb         $v1, %lo(_loadSaveDataFile)($a0)
    /* 163C 80103E3C 1180043C */  lui        $a0, %hi(_fileProgressPosition)
    /* 1640 80103E40 50000324 */  addiu      $v1, $zero, 0x50
    /* 1644 80103E44 4AAE83A4 */  sh         $v1, %lo(_fileProgressPosition)($a0)
    /* 1648 80103E48 1180033C */  lui        $v1, %hi(_filePreviousProgressCounter)
    /* 164C 80103E4C 0B100408 */  j          .L8010402C
    /* 1650 80103E50 48AE60A4 */   sh        $zero, %lo(_filePreviousProgressCounter)($v1)
  .L80103E54:
    /* 1654 80103E54 1180023C */  lui        $v0, %hi(_loadSaveDataState)
    /* 1658 80103E58 85AA4390 */  lbu        $v1, %lo(_loadSaveDataState)($v0)
    /* 165C 80103E5C 00000000 */  nop
    /* 1660 80103E60 05006010 */  beqz       $v1, .L80103E78
    /* 1664 80103E64 01000224 */   addiu     $v0, $zero, 0x1
    /* 1668 80103E68 57006210 */  beq        $v1, $v0, .L80103FC8
    /* 166C 80103E6C 21200000 */   addu      $a0, $zero, $zero
    /* 1670 80103E70 05100408 */  j          .L80104014
    /* 1674 80103E74 1180023C */   lui       $v0, %hi(_loadSaveDataErrors)
  .L80103E78:
    /* 1678 80103E78 11800D3C */  lui        $t5, %hi(_fileProgressPosition)
    /* 167C 80103E7C 11800B3C */  lui        $t3, %hi(_fileProgressCounter)
    /* 1680 80103E80 11800C3C */  lui        $t4, %hi(_filePreviousProgressCounter)
    /* 1684 80103E84 1180073C */  lui        $a3, %hi(_loadSaveDataErrorOffset)
    /* 1688 80103E88 48AE8295 */  lhu        $v0, %lo(_filePreviousProgressCounter)($t4)
    /* 168C 80103E8C 4CAE648D */  lw         $a0, %lo(_fileProgressCounter)($t3)
    /* 1690 80103E90 44AEE390 */  lbu        $v1, %lo(_loadSaveDataErrorOffset)($a3)
    /* 1694 80103E94 4AAEA995 */  lhu        $t1, %lo(_fileProgressPosition)($t5)
    /* 1698 80103E98 23208200 */  subu       $a0, $a0, $v0
    /* 169C 80103E9C 80100300 */  sll        $v0, $v1, 2
    /* 16A0 80103EA0 21104300 */  addu       $v0, $v0, $v1
    /* 16A4 80103EA4 80100200 */  sll        $v0, $v0, 2
    /* 16A8 80103EA8 C0FE2325 */  addiu      $v1, $t1, -0x140
    /* 16AC 80103EAC 23104300 */  subu       $v0, $v0, $v1
    /* 16B0 80103EB0 18008200 */  mult       $a0, $v0
    /* 16B4 80103EB4 11800A3C */  lui        $t2, %hi(_fileProgressTarget)
    /* 16B8 80103EB8 12180000 */  mflo       $v1
    /* 16BC 80103EBC 46AE4895 */  lhu        $t0, %lo(_fileProgressTarget)($t2)
    /* 16C0 80103EC0 00000000 */  nop
    /* 16C4 80103EC4 1A006800 */  div        $zero, $v1, $t0
    /* 16C8 80103EC8 12400000 */  mflo       $t0
    /* 16CC 80103ECC 21280000 */  addu       $a1, $zero, $zero
    /* 16D0 80103ED0 005C0624 */  addiu      $a2, $zero, 0x5C00
    /* 16D4 80103ED4 21204002 */  addu       $a0, $s2, $zero
    /* 16D8 80103ED8 1180023C */  lui        $v0, %hi(_loadSaveDataErrors)
    /* 16DC 80103EDC 1180033C */  lui        $v1, %hi(_isTempSave)
    /* 16E0 80103EE0 88AA6390 */  lbu        $v1, %lo(_isTempSave)($v1)
    /* 16E4 80103EE4 89AA4290 */  lbu        $v0, %lo(_loadSaveDataErrors)($v0)
    /* 16E8 80103EE8 C0190300 */  sll        $v1, $v1, 7
    /* 16EC 80103EEC 44AEE2A0 */  sb         $v0, %lo(_loadSaveDataErrorOffset)($a3)
    /* 16F0 80103EF0 C0000224 */  addiu      $v0, $zero, 0xC0
    /* 16F4 80103EF4 4CAE6795 */  lhu        $a3, %lo(_fileProgressCounter)($t3)
    /* 16F8 80103EF8 23104300 */  subu       $v0, $v0, $v1
    /* 16FC 80103EFC 46AE42A5 */  sh         $v0, %lo(_fileProgressTarget)($t2)
    /* 1700 80103F00 48AE87A5 */  sh         $a3, %lo(_filePreviousProgressCounter)($t4)
    /* 1704 80103F04 21482801 */  addu       $t1, $t1, $t0
    /* 1708 80103F08 AD9B000C */  jal        memset
    /* 170C 80103F0C 4AAEA9A5 */   sh        $t1, %lo(_fileProgressPosition)($t5)
    /* 1710 80103F10 1180033C */  lui        $v1, %hi(_loadSaveDataFile)
    /* 1714 80103F14 87AA6590 */  lbu        $a1, %lo(_loadSaveDataFile)($v1)
    /* 1718 80103F18 00000000 */  nop
    /* 171C 80103F1C 0800A230 */  andi       $v0, $a1, 0x8
    /* 1720 80103F20 06004010 */  beqz       $v0, .L80103F3C
    /* 1724 80103F24 1180023C */   lui       $v0, %hi(_loadSaveDataPort)
    /* 1728 80103F28 86AA4490 */  lbu        $a0, %lo(_loadSaveDataPort)($v0)
    /* 172C 80103F2C 0E0B040C */  jal        _memcardMakeTempFilename
    /* 1730 80103F30 0700A530 */   andi      $a1, $a1, 0x7
    /* 1734 80103F34 D40F0408 */  j          .L80103F50
    /* 1738 80103F38 21204000 */   addu      $a0, $v0, $zero
  .L80103F3C:
    /* 173C 80103F3C 86AA4490 */  lbu        $a0, %lo(_loadSaveDataPort)($v0)
    /* 1740 80103F40 87AA6590 */  lbu        $a1, %lo(_loadSaveDataFile)($v1)
    /* 1744 80103F44 EF0A040C */  jal        _memcardMakeFilename
    /* 1748 80103F48 00000000 */   nop
    /* 174C 80103F4C 21204000 */  addu       $a0, $v0, $zero
  .L80103F50:
    /* 1750 80103F50 659A000C */  jal        open
    /* 1754 80103F54 01800534 */   ori       $a1, $zero, 0x8001
    /* 1758 80103F58 1180103C */  lui        $s0, %hi(_loadSaveDataFd)
    /* 175C 80103F5C FFFF1124 */  addiu      $s1, $zero, -0x1
    /* 1760 80103F60 11005110 */  beq        $v0, $s1, .L80103FA8
    /* 1764 80103F64 8CAA02AE */   sw        $v0, %lo(_loadSaveDataFd)($s0)
    /* 1768 80103F68 B70A040C */  jal        _resetMemcardEvents
    /* 176C 80103F6C 21200000 */   addu      $a0, $zero, $zero
    /* 1770 80103F70 1180023C */  lui        $v0, %hi(_isTempSave)
    /* 1774 80103F74 88AA4290 */  lbu        $v0, %lo(_isTempSave)($v0)
    /* 1778 80103F78 00000000 */  nop
    /* 177C 80103F7C 02004010 */  beqz       $v0, .L80103F88
    /* 1780 80103F80 005C0624 */   addiu     $a2, $zero, 0x5C00
    /* 1784 80103F84 00200624 */  addiu      $a2, $zero, 0x2000
  .L80103F88:
    /* 1788 80103F88 8CAA048E */  lw         $a0, %lo(_loadSaveDataFd)($s0)
    /* 178C 80103F8C 699A000C */  jal        read
    /* 1790 80103F90 21284002 */   addu      $a1, $s2, $zero
    /* 1794 80103F94 0A005114 */  bne        $v0, $s1, .L80103FC0
    /* 1798 80103F98 1180033C */   lui       $v1, %hi(_loadSaveDataState)
    /* 179C 80103F9C 8CAA048E */  lw         $a0, %lo(_loadSaveDataFd)($s0)
    /* 17A0 80103FA0 719A000C */  jal        close
    /* 17A4 80103FA4 00000000 */   nop
  .L80103FA8:
    /* 17A8 80103FA8 1180033C */  lui        $v1, %hi(_loadSaveDataErrors)
    /* 17AC 80103FAC 89AA6290 */  lbu        $v0, %lo(_loadSaveDataErrors)($v1)
    /* 17B0 80103FB0 00000000 */  nop
    /* 17B4 80103FB4 01004224 */  addiu      $v0, $v0, 0x1
    /* 17B8 80103FB8 03100408 */  j          .L8010400C
    /* 17BC 80103FBC 89AA62A0 */   sb        $v0, %lo(_loadSaveDataErrors)($v1)
  .L80103FC0:
    /* 17C0 80103FC0 01000224 */  addiu      $v0, $zero, 0x1
    /* 17C4 80103FC4 85AA62A0 */  sb         $v0, %lo(_loadSaveDataState)($v1)
  .L80103FC8:
    /* 17C8 80103FC8 980A040C */  jal        _testMemcardEvents
    /* 17CC 80103FCC 21200000 */   addu      $a0, $zero, $zero
    /* 17D0 80103FD0 21804000 */  addu       $s0, $v0, $zero
    /* 17D4 80103FD4 0400022A */  slti       $v0, $s0, 0x4
    /* 17D8 80103FD8 0C004010 */  beqz       $v0, .L8010400C
    /* 17DC 80103FDC 1180023C */   lui       $v0, %hi(_loadSaveDataFd)
    /* 17E0 80103FE0 8CAA448C */  lw         $a0, %lo(_loadSaveDataFd)($v0)
    /* 17E4 80103FE4 719A000C */  jal        close
    /* 17E8 80103FE8 00000000 */   nop
    /* 17EC 80103FEC 0F000012 */  beqz       $s0, .L8010402C
    /* 17F0 80103FF0 01000224 */   addiu     $v0, $zero, 0x1
    /* 17F4 80103FF4 1180023C */  lui        $v0, %hi(_loadSaveDataErrors)
    /* 17F8 80103FF8 89AA4390 */  lbu        $v1, %lo(_loadSaveDataErrors)($v0)
    /* 17FC 80103FFC 1180043C */  lui        $a0, %hi(_loadSaveDataState)
    /* 1800 80104000 85AA80A0 */  sb         $zero, %lo(_loadSaveDataState)($a0)
    /* 1804 80104004 01006324 */  addiu      $v1, $v1, 0x1
    /* 1808 80104008 89AA43A0 */  sb         $v1, %lo(_loadSaveDataErrors)($v0)
  .L8010400C:
    /* 180C 8010400C 21200000 */  addu       $a0, $zero, $zero
    /* 1810 80104010 1180023C */  lui        $v0, %hi(_loadSaveDataErrors)
  .L80104014:
    /* 1814 80104014 89AA4390 */  lbu        $v1, %lo(_loadSaveDataErrors)($v0)
    /* 1818 80104018 03000224 */  addiu      $v0, $zero, 0x3
    /* 181C 8010401C 03006214 */  bne        $v1, $v0, .L8010402C
    /* 1820 80104020 21108000 */   addu      $v0, $a0, $zero
    /* 1824 80104024 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 1828 80104028 21108000 */  addu       $v0, $a0, $zero
  .L8010402C:
    /* 182C 8010402C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1830 80104030 1800B28F */  lw         $s2, 0x18($sp)
    /* 1834 80104034 1400B18F */  lw         $s1, 0x14($sp)
    /* 1838 80104038 1000B08F */  lw         $s0, 0x10($sp)
    /* 183C 8010403C 0800E003 */  jr         $ra
    /* 1840 80104040 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _loadSaveData
