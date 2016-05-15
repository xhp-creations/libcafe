#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#define LC_MAX_DMA_BLOCKS 128
#define LC_MAX_DMA_BYTES  (LC_MAX_DMA_BLOCKS * 32)

#define LC_MAX_BYTES 0x4000
#define LC_MIN_ALLOC 0x0200

EXPORT_FUNC_H(void, DCInvalidateRange, void* addr, u32 nBytes);
EXPORT_FUNC_H(void, DCFlushRange, const void* addr, u32 nBytes);
EXPORT_FUNC_H(void, DCStoreRange, const void* addr, u32 nBytes);
EXPORT_FUNC_H(void, DCFlushRangeNoSync, const void* addr, u32 nBytes);
EXPORT_FUNC_H(void, DCStoreRangeNoSync, const void* addr, u32 nBytes);
EXPORT_FUNC_H(void, DCZeroRange, void* addr, u32 nBytes);
EXPORT_FUNC_H(void, DCTouchRange, const void* addr, u32 nBytes);
EXPORT_FUNC_H(bool, DCCoreFlushAll, void* flush_buf, u32 size);

EXPORT_FUNC_H(void, ICInvalidateRange, const void* addr, u32 nBytes);

EXPORT_FUNC_H(bool, LCHardwareIsAvailable, void);
EXPORT_FUNC_H(u32, LCGetMaxSize, void);
EXPORT_FUNC_H(u32, LCGetUnallocated, void);
EXPORT_FUNC_H(u32, LCGetAllocatableSize, void);
EXPORT_FUNC_H(void*, LCAlloc, u32 nBytes);
EXPORT_FUNC_H(void, LCDealloc, void* lcAddr);
EXPORT_FUNC_H(bool, LCEnableDMA, void);
EXPORT_FUNC_H(void, LCDisableDMA, void);
EXPORT_FUNC_H(bool, LCIsDMAEnabled, void);
EXPORT_FUNC_H(void, LCLoadDMABlocks, void* lcDestAddr, const void* memSrcAddr, u32 numBlocks);
EXPORT_FUNC_H(void, LCStoreDMABlocks, void* memDestAddr, const void* lcSrcAddr, u32 numBlocks);
EXPORT_FUNC_H(u32, LCGetDMAQueueLength, void);
EXPORT_FUNC_H(void, LCWaitDMAQueue, u32 len);

#ifdef __cplusplus
}
#endif