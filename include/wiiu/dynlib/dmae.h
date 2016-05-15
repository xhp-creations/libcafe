#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#include <wiiu/dynlib/coreinit/os.h>

typedef u64 DMAETimeStamp;

TYPED_ENUM(u32, DMAEEndian) {
    DMAE_ENDIAN_NONE  = 0,
    DMAE_ENDIAN_8IN16 = 1,
    DMAE_ENDIAN_8IN32 = 2,
    DMAE_ENDIAN_8IN64 = 3,
};

TYPED_ENUM(u32, DMAESemaphoreAction) {
    DMAE_SEMAPHORE_WAIT   = 0,
    DMAE_SEMAPHORE_SIGNAL = 1,
};

EXPORT_FUNC_H(bool, DMAEWaitDone, DMAETimeStamp ts);
EXPORT_FUNC_H(DMAETimeStamp, DMAEGetLastSubmittedTimeStamp, void);
EXPORT_FUNC_H(DMAETimeStamp, DMAEGetRetiredTimeStamp, void);
EXPORT_FUNC_H(DMAETimeStamp, DMAESemaphore, u64* semaphoreAddr, DMAESemaphoreAction semaphoreAction);
EXPORT_FUNC_H(DMAETimeStamp, DMAECopyMem, void* dst, const void* src, u32 sizeInU32s, DMAEEndian endian);
EXPORT_FUNC_H(DMAETimeStamp, DMAEFillMem, void* dst, u32 fillData, u32 sizeInU32s);
EXPORT_FUNC_H(DMAETimeStamp, DMAEFillMemPhys, u32 dstPA, u32 fillData, u32 sizeInU32s);
EXPORT_FUNC_H(void, DMAESetTimeout, u32 millisec);
EXPORT_FUNC_H(u32, DMAEGetTimeout, void);

#ifdef __cplusplus
}
#endif