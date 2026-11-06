#pragma once
#include <sys/types.h>

typedef struct {
    u_int x : 8;
    u_int y : 8;
    u_int z : 8;
    u_int status : 8;
} vs_battle_movementPosition;
