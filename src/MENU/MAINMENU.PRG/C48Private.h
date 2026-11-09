#pragma once
#include "C48.h"

/**
 * Ranks the two top class and affinity values.
 *
 * @return Packed value:
 *
 * - Bits 0-7: The rank from 0-10 of the second highest stat.
 *
 * - Bits 8-15: The rank from 0-3 of the highest stat.
 *
 * - Bits 16+: The highest stat identifier, where 0-5 == class, 6-12 == affinity.
 */
int vs_mainMenu_getEquipmentMaxStats(void* item, u_int itemCategory);
