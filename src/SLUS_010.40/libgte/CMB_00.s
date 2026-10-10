.include "macro.inc"
.set noreorder

# hasm: single-nop gte hazard
glabel RotTransPers4
    lwc2    $0, 0($a0)
    lwc2    $1, 4($a0)
    lwc2    $2, 0($a1)
    lwc2    $3, 4($a1)
    lwc2    $4, 0($a2)
    lwc2    $5, 4($a2)
    .nop
    RTPT
    lw      $t0, 0x10($sp)
    lw      $t1, 0x14($sp)
    lw      $t2, 0x18($sp)
    swc2    $12, 0($t0)
    swc2    $13, 0($t1)
    swc2    $14, 0($t2)
    cfc2    $v1, $31
    lwc2    $0, 0($a3)
    lwc2    $1, 4($a3)
    .nop
    RTPS
    lw      $t0, 0x1C($sp)
    lw      $t1, 0x20($sp)
    lw      $t2, 0x24($sp)
    swc2    $14, 0($t0)
    swc2    $8, 0($t1)
    cfc2    $t0, $31
    mfc2    $v0, $19
    or      $t0, $v1
    sw      $t0, 0($t2)
    j       $ra
    sra     $v0, 2
endlabel RotTransPers4
