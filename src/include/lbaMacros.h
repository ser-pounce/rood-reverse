#pragma once

#define squashLba(file) ((file##_LBA) << 8 | (file##_SIZE >> 11))
#define mkCdFile(file)                                                                   \
    {                                                                                    \
        VS_##file##_LBA, VS_##file##_SIZE                                                \
    }
#define mkHfoPair(file) mkCdFile(file##_HF1), mkCdFile(file##_HF0)