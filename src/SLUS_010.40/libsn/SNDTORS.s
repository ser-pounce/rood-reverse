.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

# hasm: temp register usage
glabel __do_global_dtors
    lui     $t0, %hi(__initialised)
    lw      $t0, %lo(__initialised)($t0)
    addiu   $sp, $sp, -0x10
    sw      $s0, 0x4($sp)
    sw      $s1, 0x8($sp)
    sw      $ra, 0xC($sp)
    beqz    $t0, .L8001F6AC
    nop
    lui     $s0, %hi(vs_overlay_slots)
    addiu   $s0, $s0, %lo(vs_overlay_slots)
    lui     $s1, 0x0
    addiu   $s1, $s1, 0x0
    beqz    $s1, .L8001F6AC
    nop
.L8001F694:
    lw      $t0, 0x0($s0)
    addiu   $s0, $s0, 0x4
    jalr    $t0
    addiu   $s1, $s1, -0x1
    bnez    $s1, .L8001F694
    nop
.L8001F6AC:
    lw      $ra, 0xC($sp)
    lw      $s1, 0x8($sp)
    lw      $s0, 0x4($sp)
    addiu   $sp, $sp, 0x10
    jr      $ra
    nop
endlabel __do_global_dtors
