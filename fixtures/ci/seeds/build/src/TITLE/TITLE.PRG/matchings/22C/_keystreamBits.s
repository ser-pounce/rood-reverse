nonmatching _keystreamBits, 0x2C

glabel _keystreamBits
    /* 2D4 80068AD4 1900033C */  lui        $v1, (0x19660D >> 16)
    /* 2D8 80068AD8 0780023C */  lui        $v0, %hi(_keystreamState)
    /* 2DC 80068ADC 9028458C */  lw         $a1, %lo(_keystreamState)($v0)
    /* 2E0 80068AE0 0D666334 */  ori        $v1, $v1, (0x19660D & 0xFFFF)
    /* 2E4 80068AE4 1800A300 */  mult       $a1, $v1
    /* 2E8 80068AE8 12300000 */  mflo       $a2
    /* 2EC 80068AEC 902846AC */  sw         $a2, %lo(_keystreamState)($v0)
    /* 2F0 80068AF0 20000224 */  addiu      $v0, $zero, 0x20
    /* 2F4 80068AF4 23104400 */  subu       $v0, $v0, $a0
    /* 2F8 80068AF8 0800E003 */  jr         $ra
    /* 2FC 80068AFC 06104500 */   srlv      $v0, $a1, $v0
endlabel _keystreamBits
