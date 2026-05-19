#pragma once

#define squashLba(file) squashLbaVal((file##_LBA), (file##_SIZE))
#define squashLbaVal(lba, size) ((lba) << 8 | ((size) >> 11))
#define mkCdFile(file)                                                                   \
    {                                                                                    \
        VS_##file##_LBA, VS_##file##_SIZE                                                \
    }
#define mkHfoPair(file) mkCdFile(file##_HF1), mkCdFile(file##_HF0)