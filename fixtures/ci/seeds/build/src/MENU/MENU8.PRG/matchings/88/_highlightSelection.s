nonmatching _highlightSelection, 0xA0

glabel _highlightSelection
    /* 1E50 80104650 FF000E3C */  lui        $t6, (0xFFFFFF >> 16)
    /* 1E54 80104654 FFFFCE35 */  ori        $t6, $t6, (0xFFFFFF & 0xFFFF)
    /* 1E58 80104658 00E10B3C */  lui        $t3, (0xE1000220 >> 16)
    /* 1E5C 8010465C 20026B35 */  ori        $t3, $t3, (0xE1000220 & 0xFFFF)
    /* 1E60 80104660 C03A033C */  lui        $v1, (0x3AC0A080 >> 16)
    /* 1E64 80104664 80A06334 */  ori        $v1, $v1, (0x3AC0A080 & 0xFFFF)
    /* 1E68 80104668 C0000D3C */  lui        $t5, (0xC0A080 >> 16)
    /* 1E6C 8010466C 801F0A3C */  lui        $t2, (0x1F800000 >> 16)
    /* 1E70 80104670 00004225 */  addiu      $v0, $t2, %lo(D_1F800000)
    /* 1E74 80104674 80A0AD35 */  ori        $t5, $t5, (0xC0A080 & 0xFFFF)
    /* 1E78 80104678 08004C8C */  lw         $t4, 0x8($v0)
    /* 1E7C 8010467C 0000488D */  lw         $t0, (0x1F800000 & 0xFFFF)($t2)
    /* 1E80 80104680 0000898D */  lw         $t1, 0x0($t4)
    /* 1E84 80104684 21308600 */  addu       $a2, $a0, $a2
    /* 1E88 80104688 080003AD */  sw         $v1, 0x8($t0)
    /* 1E8C 8010468C 001C0500 */  sll        $v1, $a1, 16
    /* 1E90 80104690 25108300 */  or         $v0, $a0, $v1
    /* 1E94 80104694 2518C300 */  or         $v1, $a2, $v1
    /* 1E98 80104698 2128A700 */  addu       $a1, $a1, $a3
    /* 1E9C 8010469C 002C0500 */  sll        $a1, $a1, 16
    /* 1EA0 801046A0 25208500 */  or         $a0, $a0, $a1
    /* 1EA4 801046A4 2530C500 */  or         $a2, $a2, $a1
    /* 1EA8 801046A8 0C0002AD */  sw         $v0, 0xC($t0)
    /* 1EAC 801046AC 0009023C */  lui        $v0, (0x9000000 >> 16)
    /* 1EB0 801046B0 04000BAD */  sw         $t3, 0x4($t0)
    /* 1EB4 801046B4 100000AD */  sw         $zero, 0x10($t0)
    /* 1EB8 801046B8 140003AD */  sw         $v1, 0x14($t0)
    /* 1EBC 801046BC 180000AD */  sw         $zero, 0x18($t0)
    /* 1EC0 801046C0 1C0004AD */  sw         $a0, 0x1C($t0)
    /* 1EC4 801046C4 20000DAD */  sw         $t5, 0x20($t0)
    /* 1EC8 801046C8 240006AD */  sw         $a2, 0x24($t0)
    /* 1ECC 801046CC 24482E01 */  and        $t1, $t1, $t6
    /* 1ED0 801046D0 25482201 */  or         $t1, $t1, $v0
    /* 1ED4 801046D4 00120800 */  sll        $v0, $t0, 8
    /* 1ED8 801046D8 02120200 */  srl        $v0, $v0, 8
    /* 1EDC 801046DC 000009AD */  sw         $t1, 0x0($t0)
    /* 1EE0 801046E0 28000825 */  addiu      $t0, $t0, 0x28
    /* 1EE4 801046E4 000082AD */  sw         $v0, 0x0($t4)
    /* 1EE8 801046E8 0800E003 */  jr         $ra
    /* 1EEC 801046EC 000048AD */   sw        $t0, (0x1F800000 & 0xFFFF)($t2)
endlabel _highlightSelection
