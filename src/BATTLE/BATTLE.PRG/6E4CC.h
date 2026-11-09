#pragma once
#include "actor.h"
#include "battleEffect.h"
#include "hitEntity.h"
#include <sys/types.h>
#include <libgte.h>

typedef struct {
    int meta;
    u_char data[0];
} PFile;

void func_800E6EAC(void);
