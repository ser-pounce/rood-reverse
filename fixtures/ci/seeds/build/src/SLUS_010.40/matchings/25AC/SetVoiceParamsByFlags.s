nonmatching SetVoiceParamsByFlags, 0x11C

glabel SetVoiceParamsByFlags
    /* 45B0 80013DB0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 45B4 80013DB4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 45B8 80013DB8 2188A000 */  addu       $s1, $a1, $zero
    /* 45BC 80013DBC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 45C0 80013DC0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 45C4 80013DC4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 45C8 80013DC8 0400308E */  lw         $s0, 0x4($s1)
    /* 45CC 80013DCC 00000000 */  nop
    /* 45D0 80013DD0 38000012 */  beqz       $s0, .L80013EB4
    /* 45D4 80013DD4 21908000 */   addu      $s2, $a0, $zero
    /* 45D8 80013DD8 10000232 */  andi       $v0, $s0, 0x10
    /* 45DC 80013DDC 07004010 */  beqz       $v0, .L80013DFC
    /* 45E0 80013DE0 040020AE */   sw        $zero, 0x4($s1)
    /* 45E4 80013DE4 EFFF0224 */  addiu      $v0, $zero, -0x11
    /* 45E8 80013DE8 10002596 */  lhu        $a1, 0x10($s1)
    /* 45EC 80013DEC E84E000C */  jal        SetVoiceSampleRate
    /* 45F0 80013DF0 24800202 */   and       $s0, $s0, $v0
    /* 45F4 80013DF4 2F000012 */  beqz       $s0, .L80013EB4
    /* 45F8 80013DF8 00000000 */   nop
  .L80013DFC:
    /* 45FC 80013DFC 03000232 */  andi       $v0, $s0, 0x3
    /* 4600 80013E00 09004010 */  beqz       $v0, .L80013E28
    /* 4604 80013E04 FCFF0224 */   addiu     $v0, $zero, -0x4
    /* 4608 80013E08 24800202 */  and        $s0, $s0, $v0
    /* 460C 80013E0C 18002586 */  lh         $a1, 0x18($s1)
    /* 4610 80013E10 1A002686 */  lh         $a2, 0x1A($s1)
    /* 4614 80013E14 16002796 */  lhu        $a3, 0x16($s1)
    /* 4618 80013E18 D64E000C */  jal        SetVoiceVolume
    /* 461C 80013E1C 21204002 */   addu      $a0, $s2, $zero
    /* 4620 80013E20 24000012 */  beqz       $s0, .L80013EB4
    /* 4624 80013E24 00000000 */   nop
  .L80013E28:
    /* 4628 80013E28 80000232 */  andi       $v0, $s0, 0x80
    /* 462C 80013E2C 07004010 */  beqz       $v0, .L80013E4C
    /* 4630 80013E30 7FFF0224 */   addiu     $v0, $zero, -0x81
    /* 4634 80013E34 24800202 */  and        $s0, $s0, $v0
    /* 4638 80013E38 0800258E */  lw         $a1, 0x8($s1)
    /* 463C 80013E3C EE4E000C */  jal        SetVoiceStartAddr
    /* 4640 80013E40 21204002 */   addu      $a0, $s2, $zero
    /* 4644 80013E44 1B000012 */  beqz       $s0, .L80013EB4
    /* 4648 80013E48 00000000 */   nop
  .L80013E4C:
    /* 464C 80013E4C 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 4650 80013E50 24100202 */  and        $v0, $s0, $v0
    /* 4654 80013E54 08004010 */  beqz       $v0, .L80013E78
    /* 4658 80013E58 FEFF023C */   lui       $v0, (0xFFFEFFFF >> 16)
    /* 465C 80013E5C FFFF4234 */  ori        $v0, $v0, (0xFFFEFFFF & 0xFFFF)
    /* 4660 80013E60 24800202 */  and        $s0, $s0, $v0
    /* 4664 80013E64 0C00258E */  lw         $a1, 0xC($s1)
    /* 4668 80013E68 F54E000C */  jal        SetVoiceRepeatAddr
    /* 466C 80013E6C 21204002 */   addu      $a0, $s2, $zero
    /* 4670 80013E70 10000012 */  beqz       $s0, .L80013EB4
    /* 4674 80013E74 00000000 */   nop
  .L80013E78:
    /* 4678 80013E78 00660232 */  andi       $v0, $s0, 0x6600
    /* 467C 80013E7C 07004010 */  beqz       $v0, .L80013E9C
    /* 4680 80013E80 FF990224 */   addiu     $v0, $zero, -0x6601
    /* 4684 80013E84 24800202 */  and        $s0, $s0, $v0
    /* 4688 80013E88 14002596 */  lhu        $a1, 0x14($s1)
    /* 468C 80013E8C 024F000C */  jal        SetVoiceAdsrUpper
    /* 4690 80013E90 21204002 */   addu      $a0, $s2, $zero
    /* 4694 80013E94 07000012 */  beqz       $s0, .L80013EB4
    /* 4698 80013E98 00000000 */   nop
  .L80013E9C:
    /* 469C 80013E9C 00990232 */  andi       $v0, $s0, 0x9900
    /* 46A0 80013EA0 04004010 */  beqz       $v0, .L80013EB4
    /* 46A4 80013EA4 00000000 */   nop
    /* 46A8 80013EA8 12002596 */  lhu        $a1, 0x12($s1)
    /* 46AC 80013EAC FC4E000C */  jal        SetVoiceAdsrLower
    /* 46B0 80013EB0 21204002 */   addu      $a0, $s2, $zero
  .L80013EB4:
    /* 46B4 80013EB4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 46B8 80013EB8 1800B28F */  lw         $s2, 0x18($sp)
    /* 46BC 80013EBC 1400B18F */  lw         $s1, 0x14($sp)
    /* 46C0 80013EC0 1000B08F */  lw         $s0, 0x10($sp)
    /* 46C4 80013EC4 0800E003 */  jr         $ra
    /* 46C8 80013EC8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel SetVoiceParamsByFlags
