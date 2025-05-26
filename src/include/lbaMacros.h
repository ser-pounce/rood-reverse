#pragma once

#define squashLba(file) ((file##_LBA) << 8 | (file##_SIZE >> 11))
