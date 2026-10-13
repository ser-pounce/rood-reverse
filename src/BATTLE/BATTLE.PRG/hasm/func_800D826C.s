# hasm: func_800D820C and func_800D836C branch into the shared return.
# Returns whether the unsigned halfword state counter at 0x8E is at least 32.
glabel func_800D826C
    lhu     $v0, 0x8E($a0)
    nop
    slti    $v0, $v0, 32
.L800D8278:
    jr      $ra
    xori    $v0, $v0, 1
endlabel func_800D826C
