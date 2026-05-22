nonmatching vs_main_initHeap, 0x40

glabel vs_main_initHeap
    /* 34774 80043F74 0580023C */  lui        $v0, %hi(heapA)
    /* 34778 80043F78 A80144AC */  sw         $a0, %lo(heapA)($v0)
    /* 3477C 80043F7C A8014224 */  addiu      $v0, $v0, %lo(heapA)
    /* 34780 80043F80 02290500 */  srl        $a1, $a1, 4
    /* 34784 80043F84 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 34788 80043F88 0580033C */  lui        $v1, %hi(heapB)
    /* 3478C 80043F8C 040044AC */  sw         $a0, 0x4($v0)
    /* 34790 80043F90 080040AC */  sw         $zero, 0x8($v0)
    /* 34794 80043F94 000082AC */  sw         $v0, 0x0($a0)
    /* 34798 80043F98 040082AC */  sw         $v0, 0x4($a0)
    /* 3479C 80043F9C B8016224 */  addiu      $v0, $v1, %lo(heapB)
    /* 347A0 80043FA0 080085AC */  sw         $a1, 0x8($a0)
    /* 347A4 80043FA4 B80162AC */  sw         $v0, %lo(heapB)($v1)
    /* 347A8 80043FA8 040042AC */  sw         $v0, 0x4($v0)
    /* 347AC 80043FAC 0800E003 */  jr         $ra
    /* 347B0 80043FB0 080040AC */   sw        $zero, 0x8($v0)
endlabel vs_main_initHeap
