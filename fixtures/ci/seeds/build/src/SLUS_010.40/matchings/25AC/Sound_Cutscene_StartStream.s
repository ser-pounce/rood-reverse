nonmatching Sound_Cutscene_StartStream, 0x23C

glabel Sound_Cutscene_StartStream
    /* D6A8 8001CEA8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* D6AC 8001CEAC 1800B2AF */  sw         $s2, 0x18($sp)
    /* D6B0 8001CEB0 21908000 */  addu       $s2, $a0, $zero
    /* D6B4 8001CEB4 1400B1AF */  sw         $s1, 0x14($sp)
    /* D6B8 8001CEB8 2188A000 */  addu       $s1, $a1, $zero
    /* D6BC 8001CEBC 2800B6AF */  sw         $s6, 0x28($sp)
    /* D6C0 8001CEC0 21B0C000 */  addu       $s6, $a2, $zero
    /* D6C4 8001CEC4 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* D6C8 8001CEC8 2400B5AF */  sw         $s5, 0x24($sp)
    /* D6CC 8001CECC 2000B4AF */  sw         $s4, 0x20($sp)
    /* D6D0 8001CED0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* D6D4 8001CED4 7473000C */  jal        func_8001CDD0
    /* D6D8 8001CED8 1000B0AF */   sw        $s0, 0x10($sp)
    /* D6DC 8001CEDC 21A04000 */  addu       $s4, $v0, $zero
    /* D6E0 8001CEE0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* D6E4 8001CEE4 75008212 */  beq        $s4, $v0, .L8001D0BC
    /* D6E8 8001CEE8 21200000 */   addu      $a0, $zero, $zero
    /* D6EC 8001CEEC 0480153C */  lui        $s5, %hi(g_Sound_Cutscene_StreamState)
    /* D6F0 8001CEF0 089BB026 */  addiu      $s0, $s5, %lo(g_Sound_Cutscene_StreamState)
    /* D6F4 8001CEF4 457A000C */  jal        SpuSetIRQ
    /* D6F8 8001CEF8 4C0011AE */   sw        $s1, 0x4C($s0)
    /* D6FC 8001CEFC A57A000C */  jal        SpuSetIRQCallback
    /* D700 8001CF00 21200000 */   addu      $a0, $zero, $zero
    /* D704 8001CF04 21984002 */  addu       $s3, $s2, $zero
    /* D708 8001CF08 40006226 */  addiu      $v0, $s3, 0x40
    /* D70C 8001CF0C 01001224 */  addiu      $s2, $zero, 0x1
    /* D710 8001CF10 089BA2AE */  sw         $v0, %lo(g_Sound_Cutscene_StreamState)($s5)
    /* D714 8001CF14 1000628E */  lw         $v0, 0x10($s3)
    /* D718 8001CF18 04889202 */  sllv       $s1, $s2, $s4
    /* D71C 8001CF1C 140002AE */  sw         $v0, 0x14($s0)
    /* D720 8001CF20 21109202 */  addu       $v0, $s4, $s2
    /* D724 8001CF24 04105200 */  sllv       $v0, $s2, $v0
    /* D728 8001CF28 25882202 */  or         $s1, $s1, $v0
    /* D72C 8001CF2C 2000628E */  lw         $v0, 0x20($s3)
    /* D730 8001CF30 21202002 */  addu       $a0, $s1, $zero
    /* D734 8001CF34 100014AE */  sw         $s4, 0x10($s0)
    /* D738 8001CF38 0C0011AE */  sw         $s1, 0xC($s0)
    /* D73C 8001CF3C BA4E000C */  jal        SetVoiceKeyOff
    /* D740 8001CF40 180002AE */   sw        $v0, 0x18($s0)
    /* D744 8001CF44 1800628E */  lw         $v0, 0x18($s3)
    /* D748 8001CF48 00000000 */  nop
    /* D74C 8001CF4C 080002AE */  sw         $v0, 0x8($s0)
    /* D750 8001CF50 1C006296 */  lhu        $v0, 0x1C($s3)
    /* D754 8001CF54 21202002 */  addu       $a0, $s1, $zero
    /* D758 8001CF58 100014AE */  sw         $s4, 0x10($s0)
    /* D75C 8001CF5C 0C0004AE */  sw         $a0, 0xC($s0)
    /* D760 8001CF60 BA4E000C */  jal        SetVoiceKeyOff
    /* D764 8001CF64 580002AE */   sw        $v0, 0x58($s0)
    /* D768 8001CF68 097B000C */  jal        SpuSetTransferMode
    /* D76C 8001CF6C 21200000 */   addu      $a0, $zero, $zero
    /* D770 8001CF70 F17A000C */  jal        SpuSetTransferStartAddr
    /* D774 8001CF74 00110424 */   addiu     $a0, $zero, 0x1100
    /* D778 8001CF78 0800028E */  lw         $v0, 0x8($s0)
    /* D77C 8001CF7C 0380033C */  lui        $v1, %hi(_isSpuTransfer)
    /* D780 8001CF80 F07772AC */  sw         $s2, %lo(_isSpuTransfer)($v1)
    /* D784 8001CF84 02004230 */  andi       $v0, $v0, 0x2
    /* D788 8001CF88 05004010 */  beqz       $v0, .L8001CFA0
    /* D78C 8001CF8C 00000000 */   nop
    /* D790 8001CF90 089BA38E */  lw         $v1, %lo(g_Sound_Cutscene_StreamState)($s5)
    /* D794 8001CF94 1400628E */  lw         $v0, 0x14($s3)
    /* D798 8001CF98 E9730008 */  j          .L8001CFA4
    /* D79C 8001CF9C 21186200 */   addu      $v1, $v1, $v0
  .L8001CFA0:
    /* D7A0 8001CFA0 21180000 */  addu       $v1, $zero, $zero
  .L8001CFA4:
    /* D7A4 8001CFA4 0480023C */  lui        $v0, %hi(g_Sound_Cutscene_StreamState)
    /* D7A8 8001CFA8 089B4524 */  addiu      $a1, $v0, %lo(g_Sound_Cutscene_StreamState)
    /* D7AC 8001CFAC 0800A48C */  lw         $a0, 0x8($a1)
    /* D7B0 8001CFB0 00000000 */  nop
    /* D7B4 8001CFB4 01008230 */  andi       $v0, $a0, 0x1
    /* D7B8 8001CFB8 10004010 */  beqz       $v0, .L8001CFFC
    /* D7BC 8001CFBC 040003AE */   sw        $v1, 0x4($s0)
    /* D7C0 8001CFC0 02008230 */  andi       $v0, $a0, 0x2
    /* D7C4 8001CFC4 06004010 */  beqz       $v0, .L8001CFE0
    /* D7C8 8001CFC8 2130A000 */   addu      $a2, $a1, $zero
    /* D7CC 8001CFCC 1400628E */  lw         $v0, 0x14($s3)
    /* D7D0 8001CFD0 1400A38C */  lw         $v1, 0x14($a1)
    /* D7D4 8001CFD4 42100200 */  srl        $v0, $v0, 1
    /* D7D8 8001CFD8 F9730008 */  j          .L8001CFE4
    /* D7DC 8001CFDC 23186200 */   subu      $v1, $v1, $v0
  .L8001CFE0:
    /* D7E0 8001CFE0 21180000 */  addu       $v1, $zero, $zero
  .L8001CFE4:
    /* D7E4 8001CFE4 1C00C3AC */  sw         $v1, 0x1C($a2)
    /* D7E8 8001CFE8 0280043C */  lui        $a0, %hi(func_8001D3D4)
    /* D7EC 8001CFEC 157B000C */  jal        SpuSetTransferCallback
    /* D7F0 8001CFF0 D4D38424 */   addiu     $a0, $a0, %lo(func_8001D3D4)
    /* D7F4 8001CFF4 0C740008 */  j          .L8001D030
    /* D7F8 8001CFF8 00200524 */   addiu     $a1, $zero, 0x2000
  .L8001CFFC:
    /* D7FC 8001CFFC 02008230 */  andi       $v0, $a0, 0x2
    /* D800 8001D000 05004010 */  beqz       $v0, .L8001D018
    /* D804 8001D004 00000000 */   nop
    /* D808 8001D008 1400A38C */  lw         $v1, 0x14($a1)
    /* D80C 8001D00C 1400628E */  lw         $v0, 0x14($s3)
    /* D810 8001D010 07740008 */  j          .L8001D01C
    /* D814 8001D014 23186200 */   subu      $v1, $v1, $v0
  .L8001D018:
    /* D818 8001D018 21180000 */  addu       $v1, $zero, $zero
  .L8001D01C:
    /* D81C 8001D01C 1C00A3AC */  sw         $v1, 0x1C($a1)
    /* D820 8001D020 0280043C */  lui        $a0, %hi(func_8001CE60)
    /* D824 8001D024 157B000C */  jal        SpuSetTransferCallback
    /* D828 8001D028 60CE8424 */   addiu     $a0, $a0, %lo(func_8001CE60)
    /* D82C 8001D02C 00080524 */  addiu      $a1, $zero, 0x800
  .L8001D030:
    /* D830 8001D030 0480023C */  lui        $v0, %hi(g_Sound_Cutscene_StreamState)
    /* D834 8001D034 089B448C */  lw         $a0, %lo(g_Sound_Cutscene_StreamState)($v0)
    /* D838 8001D038 D97A000C */  jal        SpuWrite
    /* D83C 8001D03C 089B5024 */   addiu     $s0, $v0, %lo(g_Sound_Cutscene_StreamState)
    /* D840 8001D040 0800C012 */  beqz       $s6, .L8001D064
    /* D844 8001D044 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
    /* D848 8001D048 90784224 */  addiu      $v0, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* D84C 8001D04C 2000438C */  lw         $v1, 0x20($v0)
    /* D850 8001D050 0C00048E */  lw         $a0, 0xC($s0)
    /* D854 8001D054 00000000 */  nop
    /* D858 8001D058 25186400 */  or         $v1, $v1, $a0
    /* D85C 8001D05C 1F740008 */  j          .L8001D07C
    /* D860 8001D060 200043AC */   sw        $v1, 0x20($v0)
  .L8001D064:
    /* D864 8001D064 90784224 */  addiu      $v0, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* D868 8001D068 0C00038E */  lw         $v1, 0xC($s0)
    /* D86C 8001D06C 2000448C */  lw         $a0, 0x20($v0)
    /* D870 8001D070 27180300 */  nor        $v1, $zero, $v1
    /* D874 8001D074 24208300 */  and        $a0, $a0, $v1
    /* D878 8001D078 200044AC */  sw         $a0, 0x20($v0)
  .L8001D07C:
    /* D87C 8001D07C 0380063C */  lui        $a2, %hi(g_Sound_VoiceSchedulerState)
    /* D880 8001D080 9078C624 */  addiu      $a2, $a2, %lo(g_Sound_VoiceSchedulerState)
    /* D884 8001D084 0480023C */  lui        $v0, %hi(D_80039B14)
    /* D888 8001D088 0480043C */  lui        $a0, %hi(g_Sound_GlobalFlags)
    /* D88C 8001D08C F89A8424 */  addiu      $a0, $a0, %lo(g_Sound_GlobalFlags)
    /* D890 8001D090 149B458C */  lw         $a1, %lo(D_80039B14)($v0)
    /* D894 8001D094 2400C28C */  lw         $v0, 0x24($a2)
    /* D898 8001D098 27280500 */  nor        $a1, $zero, $a1
    /* D89C 8001D09C 24104500 */  and        $v0, $v0, $a1
    /* D8A0 8001D0A0 2400C2AC */  sw         $v0, 0x24($a2)
    /* D8A4 8001D0A4 1C00C28C */  lw         $v0, 0x1C($a2)
    /* D8A8 8001D0A8 0800838C */  lw         $v1, 0x8($a0)
    /* D8AC 8001D0AC 24104500 */  and        $v0, $v0, $a1
    /* D8B0 8001D0B0 00016334 */  ori        $v1, $v1, 0x100
    /* D8B4 8001D0B4 1C00C2AC */  sw         $v0, 0x1C($a2)
    /* D8B8 8001D0B8 080083AC */  sw         $v1, 0x8($a0)
  .L8001D0BC:
    /* D8BC 8001D0BC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* D8C0 8001D0C0 2800B68F */  lw         $s6, 0x28($sp)
    /* D8C4 8001D0C4 2400B58F */  lw         $s5, 0x24($sp)
    /* D8C8 8001D0C8 2000B48F */  lw         $s4, 0x20($sp)
    /* D8CC 8001D0CC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* D8D0 8001D0D0 1800B28F */  lw         $s2, 0x18($sp)
    /* D8D4 8001D0D4 1400B18F */  lw         $s1, 0x14($sp)
    /* D8D8 8001D0D8 1000B08F */  lw         $s0, 0x10($sp)
    /* D8DC 8001D0DC 0800E003 */  jr         $ra
    /* D8E0 8001D0E0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Sound_Cutscene_StartStream
