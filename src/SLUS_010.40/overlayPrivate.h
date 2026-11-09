#pragma once
#include "common.h"
#include "overlay.h"

void vs_overlay_getSp(int*);
VS_HIDDEN(vs_overlay_getSp);

void vs_overlay_jumpToTitle(int*);
VS_HIDDEN(vs_overlay_jumpToTitle);

void vs_overlay_jumpToBattle(int*);
VS_HIDDEN(vs_overlay_jumpToBattle);

void vs_overlay_wait(void);
VS_HIDDEN(vs_overlay_wait);
