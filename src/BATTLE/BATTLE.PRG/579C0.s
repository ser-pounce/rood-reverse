.include "macro.inc"

.set noreorder

.section .text, "ax"

nonmatching vs_battle_copyAligned, 0x20

glabel vs_battle_copyAligned
    and        $t0, $a2, 0x7
    beqz       $t0, vs_battle_memcpy
     lh        $t0, 0x0($a1)
    addiu      $a1, 0x2
    sh         $t0, 0x0($a0)
    addiu      $a0, 0x2
    j          vs_battle_copyAligned
     add       $a2, -0x2
endlabel vs_battle_copyAligned

nonmatching vs_battle_memcpy, 0x34

glabel vs_battle_memcpy
    addu       $a2, $a1, $a2
  0:
    lh         $t0, 0x0($a1)
    lh         $t1, 0x2($a1)
    lh         $t2, 0x4($a1)
    lh         $t3, 0x6($a1)
    addiu      $a1, 0x8
    sh         $t0, 0x0($a0)
    sh         $t1, 0x2($a0)
    sh         $t2, 0x4($a0)
    sh         $t3, 0x6($a0)
    bne        $a1, $a2, 0b
     addiu     $a0, 0x8
    jr         $ra
endlabel vs_battle_memcpy

nonmatching vs_battle_setSpriteDefault, 0x10

glabel vs_battle_setSpriteDefault
    lui        $v1, %hi(0x1F800008)
    addu       $a2, $a0, $zero
    li         $a0, 0x80
    lw         $a3, %lo(0x1F800008)($v1)
endlabel vs_battle_setSpriteDefault

nonmatching vs_battle_setSpriteDefaultTexPage, 0xC

glabel vs_battle_setSpriteDefaultTexPage
    lui        $t1, %hi(0xE100000C)
    j          .L800C0234
     or        $t1, (0xE100000C & 0xFFFF)
endlabel vs_battle_setSpriteDefaultTexPage

nonmatching vs_battle_setSprite, 0x78

glabel vs_battle_setSprite
    addu       $t1, $zero, $zero
  .L800C0234:
    lw         $t0, 0x0($a3)
    li         $v1, 0x1F800000
    li         $t2, 0x5000000
    lw         $v0, %lo(0x1F800000)($v1)
    sll        $t0, 8
    srl        $t0, 8
    or         $t0, $t2
    and        $t3, $a0, 0xFF
    sll        $t4, $t3, 8
    or         $t2, $t3, $t4
    sll        $t3, 16
    or         $t2, $t3
    srl        $t3, $a0, 7
    and        $t3, 0x2
    addiu      $t3, 0x64
    sll        $t3, 24
    or         $t2, $t3
    sll        $t3, $v0, 8
    srl        $t3, 8
    addiu      $t4, $v0, 0x18
    sw         $t0, 0x0($v0)
    sw         $t1, 0x4($v0)
    sw         $t2, 0x8($v0)
    sw         $a1, 0xC($v0)
    sw         $zero, 0x10($v0)
    sw         $a2, 0x14($v0)
    sw         $t3, 0x0($a3)
    jr         $ra
     sw        $t4, %lo(0x1F800000)($v1)
endlabel vs_battle_setSprite

nonmatching func_800C02A8, 0x30

glabel func_800C02A8
    addiu      $sp, -0x8
    sw         $ra, 0x0($sp)
    lui        $a0, %hi(vs_scratch + 0x14)
    jal        SetRotMatrix
     addiu     $a0, %lo(vs_scratch + 0x14)
    lui        $a0, %hi(vs_scratch + 0x14)
    jal        SetTransMatrix
     addiu     $a0, %lo(vs_scratch + 0x14)
    lw         $ra, 0x0($sp)
    nop
    jr         $ra
     addiu     $sp, 0x8
endlabel func_800C02A8

nonmatching vs_battle_playSfx10, 0x8

glabel vs_battle_playSfx10
    j          .L800C02FC
     li        $a1, 0xA
endlabel vs_battle_playSfx10

nonmatching vs_battle_playInvalidSfx, 0x8

glabel vs_battle_playInvalidSfx
    j          .L800C02FC
     li        $a1, 0x7
endlabel vs_battle_playInvalidSfx

nonmatching vs_battle_playMenuLeaveSfx, 0x8

glabel vs_battle_playMenuLeaveSfx
    j          .L800C02FC
     li        $a1, 0x6
endlabel vs_battle_playMenuLeaveSfx

nonmatching vs_battle_playMenuSelectSfx, 0x8

glabel vs_battle_playMenuSelectSfx
    j          .L800C02FC
     li        $a1, 0x5
endlabel vs_battle_playMenuSelectSfx

nonmatching vs_battle_playMenuChangeSfx, 0x24

glabel vs_battle_playMenuChangeSfx
    li         $a1, 0x4
  .L800C02FC:
    addiu      $sp, -0x8
    sw         $ra, 0x0($sp)
    jal        vs_main_playSfxDefault
     li        $a0, 0x7E
    lw         $ra, 0x0($sp)
    nop
    jr         $ra
     addiu     $sp, 0x8
endlabel vs_battle_playMenuChangeSfx
