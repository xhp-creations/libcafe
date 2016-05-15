#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#include <wiiu/dynlib/coreinit/mem.h>
#include <wiiu/dynlib/coreinit/os.h>

typedef s32 MICHandle;

typedef struct MICRingBuffer MICRingBuffer;
typedef struct MICStatus MICStatus;

TYPED_ENUM(s32, MICError) {
    MIC_ERROR_NONE          = 0,
    MIC_ERROR_NOT_SUP       = -1,
    MIC_ERROR_INV_ARG       = -2,
    MIC_ERROR_INV_STATE     = -3,
    MIC_ERROR_NO_MEM        = -4,
    MIC_ERROR_ALREADY_OPEN  = -5,
    MIC_ERROR_NOT_OPEN      = -6,
    MIC_ERROR_NOT_INIT      = -7,
    MIC_ERROR_NOT_CONNECTED = -8
};

TYPED_ENUM(u32, MICStatusFlag) {
    MIC_STATUS_FLAG_PCM16     = 1 << 0,
    MIC_STATUS_FLAG_OPEN      = 1 << 1,
    MIC_STATUS_FLAG_CONNECTED = 1 << 2
};

TYPED_ENUM(u32, MICState) {
    MIC_STATE_SAMPLE_RATE       = 0,
    MIC_STATE_GAIN_DB           = 1,
    MIC_STATE_GAIN_MIN          = 2,
    MIC_STATE_GAIN_MAX          = 3,
    MIC_STATE_GAIN_STEP         = 4,
    MIC_STATE_MUTE              = 5,
    MIC_STATE_ECHO_CANCELLATION = 7,
    MIC_STATE_AUTO_SELECTION    = 8,
    MIC_STATE_DIGITAL_GAIN_DB   = 9
};

TYPED_ENUM(u32, MICInstance) {
    MIC_INSTANCE_0 = 0,
    MIC_INSTANCE_1 = 1
};

struct MICRingBuffer {
    u32  modulus;
    s16* base;
};

struct MICStatus {
    MICStatusFlag flags;
    u32           available;
    u32           readPos;
};

EXPORT_FUNC_H(MICHandle, MICInit, MICInstance instance, MEMResource* res, MICRingBuffer* rb, MICError* err);
EXPORT_FUNC_H(MICError, MICUninit, MICHandle mic);
EXPORT_FUNC_H(MICError, MICOpen, MICHandle mic);
EXPORT_FUNC_H(MICError, MICGetStatus, MICHandle mic, MICStatus* status);
EXPORT_FUNC_H(MICError, MICSetDataConsumed, MICHandle mic, u32 consumedSamples);
EXPORT_FUNC_H(MICError, MICSetState, MICHandle mic, MICState state, u32 value);
EXPORT_FUNC_H(MICError, MICGetState, MICHandle mic, MICState state, u32* value);
EXPORT_FUNC_H(MICError, MICClose, MICHandle mic);

#ifdef __cplusplus
}
#endif