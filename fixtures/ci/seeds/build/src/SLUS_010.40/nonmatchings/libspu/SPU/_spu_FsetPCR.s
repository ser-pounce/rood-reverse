nonmatching _spu_FsetPCR, 0x58

glabel _spu_FsetPCR
    /* EC84 8001E484 0380053C */  lui        $a1, %hi(D_80030870)
    /* EC88 8001E488 7008A58C */  lw         $a1, %lo(D_80030870)($a1)
    /* EC8C 8001E48C F8FF033C */  lui        $v1, (0xFFF8FFFF >> 16)
    /* EC90 8001E490 0000A28C */  lw         $v0, 0x0($a1)
    /* EC94 8001E494 FFFF6334 */  ori        $v1, $v1, (0xFFF8FFFF & 0xFFFF)
    /* EC98 8001E498 24104300 */  and        $v0, $v0, $v1
    /* EC9C 8001E49C 07008010 */  beqz       $a0, .L8001E4BC
    /* ECA0 8001E4A0 0000A2AC */   sw        $v0, 0x0($a1)
    /* ECA4 8001E4A4 0380023C */  lui        $v0, %hi(D_80030870)
    /* ECA8 8001E4A8 7008428C */  lw         $v0, %lo(D_80030870)($v0)
    /* ECAC 8001E4AC 00000000 */  nop
    /* ECB0 8001E4B0 0000438C */  lw         $v1, 0x0($v0)
    /* ECB4 8001E4B4 34790008 */  j          .L8001E4D0
    /* ECB8 8001E4B8 0300043C */   lui       $a0, (0x30000 >> 16)
  .L8001E4BC:
    /* ECBC 8001E4BC 0380023C */  lui        $v0, %hi(D_80030870)
    /* ECC0 8001E4C0 7008428C */  lw         $v0, %lo(D_80030870)($v0)
    /* ECC4 8001E4C4 00000000 */  nop
    /* ECC8 8001E4C8 0000438C */  lw         $v1, 0x0($v0)
    /* ECCC 8001E4CC 0500043C */  lui        $a0, (0x50000 >> 16)
  .L8001E4D0:
    /* ECD0 8001E4D0 25186400 */  or         $v1, $v1, $a0
    /* ECD4 8001E4D4 0800E003 */  jr         $ra
    /* ECD8 8001E4D8 000043AC */   sw        $v1, 0x0($v0)
endlabel _spu_FsetPCR
