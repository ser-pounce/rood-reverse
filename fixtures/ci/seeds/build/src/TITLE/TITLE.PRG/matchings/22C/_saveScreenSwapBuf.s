nonmatching _saveScreenSwapBuf, 0xAC

glabel _saveScreenSwapBuf
    /* 5E8C 8006E68C 60FFBD27 */  addiu      $sp, $sp, -0xA0
    /* 5E90 8006E690 1800A427 */  addiu      $a0, $sp, 0x18
    /* 5E94 8006E694 21300000 */  addu       $a2, $zero, $zero
    /* 5E98 8006E698 40010724 */  addiu      $a3, $zero, 0x140
    /* 5E9C 8006E69C 0E80033C */  lui        $v1, %hi(_frameBuf)
    /* 5EA0 8006E6A0 76ED6590 */  lbu        $a1, %lo(_frameBuf)($v1)
    /* 5EA4 8006E6A4 01000224 */  addiu      $v0, $zero, 0x1
    /* 5EA8 8006E6A8 9400B1AF */  sw         $s1, 0x94($sp)
    /* 5EAC 8006E6AC F0001124 */  addiu      $s1, $zero, 0xF0
    /* 5EB0 8006E6B0 9C00BFAF */  sw         $ra, 0x9C($sp)
    /* 5EB4 8006E6B4 9800B2AF */  sw         $s2, 0x98($sp)
    /* 5EB8 8006E6B8 9000B0AF */  sw         $s0, 0x90($sp)
    /* 5EBC 8006E6BC 1000B1AF */  sw         $s1, 0x10($sp)
    /* 5EC0 8006E6C0 23104500 */  subu       $v0, $v0, $a1
    /* 5EC4 8006E6C4 76ED62A0 */  sb         $v0, %lo(_frameBuf)($v1)
    /* 5EC8 8006E6C8 FF004230 */  andi       $v0, $v0, 0xFF
    /* 5ECC 8006E6CC 80800200 */  sll        $s0, $v0, 2
    /* 5ED0 8006E6D0 21800202 */  addu       $s0, $s0, $v0
    /* 5ED4 8006E6D4 80811000 */  sll        $s0, $s0, 6
    /* 5ED8 8006E6D8 2128E000 */  addu       $a1, $a3, $zero
    /* 5EDC 8006E6DC 0DAD000C */  jal        SetDefDispEnv
    /* 5EE0 8006E6E0 2328B000 */   subu      $a1, $a1, $s0
    /* 5EE4 8006E6E4 3000B227 */  addiu      $s2, $sp, 0x30
    /* 5EE8 8006E6E8 21204002 */  addu       $a0, $s2, $zero
    /* 5EEC 8006E6EC 21280002 */  addu       $a1, $s0, $zero
    /* 5EF0 8006E6F0 21300000 */  addu       $a2, $zero, $zero
    /* 5EF4 8006E6F4 40010724 */  addiu      $a3, $zero, 0x140
    /* 5EF8 8006E6F8 DDAC000C */  jal        SetDefDrawEnv
    /* 5EFC 8006E6FC 1000B1AF */   sw        $s1, 0x10($sp)
    /* 5F00 8006E700 1800A427 */  addiu      $a0, $sp, 0x18
    /* 5F04 8006E704 08000224 */  addiu      $v0, $zero, 0x8
    /* 5F08 8006E708 2200A2A7 */  sh         $v0, 0x22($sp)
    /* 5F0C 8006E70C E0000224 */  addiu      $v0, $zero, 0xE0
    /* 5F10 8006E710 A0A3000C */  jal        PutDispEnv
    /* 5F14 8006E714 2600A2A7 */   sh        $v0, 0x26($sp)
    /* 5F18 8006E718 2DA3000C */  jal        PutDrawEnv
    /* 5F1C 8006E71C 21204002 */   addu      $a0, $s2, $zero
    /* 5F20 8006E720 9C00BF8F */  lw         $ra, 0x9C($sp)
    /* 5F24 8006E724 9800B28F */  lw         $s2, 0x98($sp)
    /* 5F28 8006E728 9400B18F */  lw         $s1, 0x94($sp)
    /* 5F2C 8006E72C 9000B08F */  lw         $s0, 0x90($sp)
    /* 5F30 8006E730 0800E003 */  jr         $ra
    /* 5F34 8006E734 A000BD27 */   addiu     $sp, $sp, 0xA0
endlabel _saveScreenSwapBuf
