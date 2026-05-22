nonmatching func_800C00E8, 0x68

glabel func_800C00E8
    /* 578E8 800C00E8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 578EC 800C00EC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 578F0 800C00F0 2180A000 */  addu       $s0, $a1, $zero
    /* 578F4 800C00F4 0100063C */  lui        $a2, (0x1ADB0 >> 16)
    /* 578F8 800C00F8 B0ADC634 */  ori        $a2, $a2, (0x1ADB0 & 0xFFFF)
    /* 578FC 800C00FC 0F80053C */  lui        $a1, %hi(D_800F4BF0)
    /* 57900 800C0100 F04BA424 */  addiu      $a0, $a1, %lo(D_800F4BF0)
    /* 57904 800C0104 0F80023C */  lui        $v0, %hi(_evtFile)
    /* 57908 800C0108 524C4384 */  lh         $v1, %lo(_evtFile)($v0)
    /* 5790C 800C010C 00180224 */  addiu      $v0, $zero, 0x1800
    /* 57910 800C0110 1400BFAF */  sw         $ra, 0x14($sp)
    /* 57914 800C0114 040082AC */  sw         $v0, 0x4($a0)
    /* 57918 800C0118 40100300 */  sll        $v0, $v1, 1
    /* 5791C 800C011C 21104300 */  addu       $v0, $v0, $v1
    /* 57920 800C0120 21104600 */  addu       $v0, $v0, $a2
    /* 57924 800C0124 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 57928 800C0128 F04BA2AC */   sw        $v0, %lo(D_800F4BF0)($a1)
    /* 5792C 800C012C 21204000 */  addu       $a0, $v0, $zero
    /* 57930 800C0130 0F80023C */  lui        $v0, %hi(D_800F4BBC)
    /* 57934 800C0134 21280002 */  addu       $a1, $s0, $zero
    /* 57938 800C0138 F112010C */  jal        vs_main_cdEnqueue
    /* 5793C 800C013C BC4B44AC */   sw        $a0, %lo(D_800F4BBC)($v0)
    /* 57940 800C0140 1400BF8F */  lw         $ra, 0x14($sp)
    /* 57944 800C0144 1000B08F */  lw         $s0, 0x10($sp)
    /* 57948 800C0148 0800E003 */  jr         $ra
    /* 5794C 800C014C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800C00E8
