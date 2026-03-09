// From
// https://github.com/jdperos/chrono-cross-decomp/blob/ecef6eeac85fe573c08644041d7098beed1a9bf5/include/hw.h

#ifndef _HW_H
#define _HW_H

#define VOICE_00_LEFT_RIGHT ((u_short*)0x1F801C00)
#define VOICE_00_ADPCM_SAMPLE_RATE ((u_short*)0x1F801C04)
#define VOICE_00_ADPCM_START_ADDR ((u_short*)0x1F801C06)
#define VOICE_00_ADPCM_ADSR_LOWER ((u_short*)0x1F801C08)
#define VOICE_00_ADPCM_ADSR_UPPER ((u_short*)0x1F801C0A)
#define VOICE_00_ADPCM_REPEAT_ADDR ((u_short*)0x1F801C0E)
#define SPU_VOICE_KEY_ON_LO ((u_short*)0x1F801D88)
#define SPU_VOICE_KEY_ON_HI ((u_short*)0x1F801D8A)
#define SPU_VOICE_KEY_OFF_LO ((u_short*)0x1F801D8C)
#define SPU_VOICE_KEY_OFF_HI ((u_short*)0x1F801D8E)
#define SPU_VOICE_CHN_FM_MODE_LO ((u_short*)0x1F801D90)
#define SPU_VOICE_CHN_FM_MODE_HI ((u_short*)0x1F801D92)
#define SPU_VOICE_CHN_NOISE_MODE_LO ((u_short*)0x1F801D94)
#define SPU_VOICE_CHN_NOISE_MODE_HI ((u_short*)0x1F801D96)
#define SPU_VOICE_CHN_REVERB_MODE_LO ((u_short*)0x1F801D98)
#define SPU_VOICE_CHN_REVERB_MODE_HI ((u_short*)0x1F801D9A)

#define CD_VOL_L ((u_short*)0x1F801DB0)
#define CD_VOL_R ((u_short*)0x1F801DB2)

#endif
