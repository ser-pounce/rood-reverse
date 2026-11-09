#pragma once
#include "common.h"
#include "58EC.h"

/**
 * Renders the provided value with preset colors based on
 * a comparison to `threshold`.
 */
int vs_mainMenu_renderIntWithThreshold(int value, int xy, int threshold, u_long* before);
VS_HIDDEN(vs_mainMenu_renderIntWithThreshold);

/**
 * Invokes `vs_mainMenu_renderIntColor` with a neutral gray color.
 */
void vs_mainMenu_renderIntColorDefault(int value, int xy, u_long* before);
VS_HIDDEN(vs_mainMenu_renderIntColorDefault);

/**
 * Redraws the entire screen based on the current state.
 */
void vs_mainMenu_renderScreen(void);
VS_HIDDEN(vs_mainMenu_renderScreen);
