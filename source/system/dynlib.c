#include <wiiu.h>

#define CURL_DISABLE_TYPECHECK
#define CURL_ALLOW_OLD_MULTI_SOCKET

#include <curl/curl.h>
#include <netinet/in.h>
#include <netdb.h>
#include <zlib.h>

EXPORT_FUNC_C(void, DCInvalidateRange, void* addr, u32 nBytes);
EXPORT_FUNC_C(void, DCFlushRange, const void* addr, u32 nBytes);
EXPORT_FUNC_C(void, DCStoreRange, const void* addr, u32 nBytes);
EXPORT_FUNC_C(void, DCFlushRangeNoSync, const void* addr, u32 nBytes);
EXPORT_FUNC_C(void, DCStoreRangeNoSync, const void* addr, u32 nBytes);
EXPORT_FUNC_C(void, DCZeroRange, void* addr, u32 nBytes);
EXPORT_FUNC_C(void, DCTouchRange, const void* addr, u32 nBytes);
EXPORT_FUNC_C(bool, DCCoreFlushAll, void* flush_buf, u32 size);

EXPORT_FUNC_C(void, ICInvalidateRange, const void* addr, u32 nBytes);

EXPORT_FUNC_C(bool, LCHardwareIsAvailable, void);
EXPORT_FUNC_C(u32, LCGetMaxSize, void);
EXPORT_FUNC_C(u32, LCGetUnallocated, void);
EXPORT_FUNC_C(u32, LCGetAllocatableSize, void);
EXPORT_FUNC_C(void*, LCAlloc, u32 nBytes);
EXPORT_FUNC_C(void, LCDealloc, void* lcAddr);
EXPORT_FUNC_C(bool, LCEnableDMA, void);
EXPORT_FUNC_C(void, LCDisableDMA, void);
EXPORT_FUNC_C(bool, LCIsDMAEnabled, void);
EXPORT_FUNC_C(void, LCLoadDMABlocks, void* lcDestAddr, const void* memSrcAddr, u32 numBlocks);
EXPORT_FUNC_C(void, LCStoreDMABlocks, void* memDestAddr, const void* lcSrcAddr, u32 numBlocks);
EXPORT_FUNC_C(u32, LCGetDMAQueueLength, void);
EXPORT_FUNC_C(void, LCWaitDMAQueue, u32 len);

EXPORT_FUNC_C(void, DisassemblePPCOpcode, u32* opcode, char* out, u32 size, DisassembleGetSym getSym, DisassembleFlag options);
EXPORT_FUNC_C(void, DisassemblePPCRange, void* start, void* end, DisassembleReport report, DisassembleGetSym getSym, DisassembleFlag options);

EXPORT_FUNC_C(int, ENVGetEnvironmentVariable, const char* key, char* value, u32 valueSize);

EXPORT_FUNC_C(void, FSInit, void);
EXPORT_FUNC_C(void, FSShutdown, void);

EXPORT_FUNC_C(u32, FSGetClientNum, void);
EXPORT_FUNC_C(FSStatus, FSAddClient, FSClient* client, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSDelClient, FSClient* client, FSRetFlag errHandling);

EXPORT_FUNC_C(void, FSInitCmdBlock, FSCmdBlock* block);
EXPORT_FUNC_C(void, FSCancelCommand, FSClient* client, FSCmdBlock* block);
EXPORT_FUNC_C(void, FSCancelAllCommands, FSClient* client);
EXPORT_FUNC_C(void, FSSetUserData, FSCmdBlock* block, void* userData);
EXPORT_FUNC_C(void*, FSGetUserData, FSCmdBlock* block);
EXPORT_FUNC_C(FSMessage*, FSGetFSMessage, FSCmdBlock* block);
EXPORT_FUNC_C(FSCmdBlock*, FSGetCurrentCmdBlock, FSClient* client);
EXPORT_FUNC_C(FSStatus, FSSetCmdPriority, FSCmdBlock* block, FSPriority priority);
EXPORT_FUNC_C(FSPriority, FSGetCmdPriority, FSCmdBlock* block);

EXPORT_FUNC_C(FSVolumeState, FSGetVolumeState, FSClient* client);
EXPORT_FUNC_C(void, FSSetStateChangeNotification, FSClient* client, FSStateChangeParams* changeParams);
EXPORT_FUNC_C(FSAsyncResult*, FSGetAsyncResult, FSMessage* ioMsg);
EXPORT_FUNC_C(FSStateNoticeInfo*, FSGetStateChangeInfo, FSMessage* ioMsg);

EXPORT_FUNC_C(FSStatus, FSGetMountSource, FSClient* client, FSCmdBlock* block, FSSourceType type, FSMountSource* source, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSGetMountSourceAsync, FSClient* client, FSCmdBlock* block, FSSourceType type, FSMountSource* source, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSGetMountSourceNext, FSClient* client, FSCmdBlock* block, FSMountSource* source, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSGetMountSourceNextAsync, FSClient* client, FSCmdBlock* block, FSMountSource* source, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSMount, FSClient* client, FSCmdBlock* block, FSMountSource* source, char* target, u32 bytes, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSMountAsync, FSClient* client, FSCmdBlock* block, FSMountSource* source, char* target, u32 bytes, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSUnmount, FSClient* client, FSCmdBlock* block, const char* target, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSUnmountAsync, FSClient* client, FSCmdBlock* block, const char* target, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_C(FSStatus, FSGetCwd, FSClient* client, FSCmdBlock* block, char* returnedPath, u32 bytes, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSGetCwdAsync, FSClient* client, FSCmdBlock* block, char* returnedPath, u32 bytes, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSChangeDir, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSChangeDirAsync, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_C(FSStatus, FSOpenFile, FSClient* client, FSCmdBlock* block, const char* path, const char* mode, FSFileHandle* fileHandle, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSOpenFileAsync, FSClient* client, FSCmdBlock* block, const char* path, const char* mode, FSFileHandle* fileHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSCloseFile, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSCloseFileAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSReadFile, FSClient* client, FSCmdBlock* block, void* dest, u32 size, u32 count, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSReadFileAsync, FSClient* client, FSCmdBlock* block, void* dest, u32 size, u32 count, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSWriteFile, FSClient* client, FSCmdBlock* block, const void* source, u32 size, u32 count, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSWriteFileAsync, FSClient* client, FSCmdBlock* block, const void* source, u32 size, u32 count, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSReadFileWithPos, FSClient* client, FSCmdBlock* block, void* dest, u32 size, u32 count, u32 fpos, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSReadFileWithPosAsync, FSClient* client, FSCmdBlock* block, void* dest, u32 size, u32 count, u32 fpos, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSWriteFileWithPos, FSClient* client, FSCmdBlock* block, const void* source, u32 size, u32 count, u32 fpos, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSWriteFileWithPosAsync, FSClient* client, FSCmdBlock* block, const void* source, u32 size, u32 count, u32 fpos, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSAppendFile, FSClient* client, FSCmdBlock* block, u32 size, u32 count, FSFileHandle fileHandle, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSAppendFileAsync, FSClient* client, FSCmdBlock* block, u32 size, u32 count, FSFileHandle fileHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSTruncateFile, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSTruncateFileAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSFlushFile, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSFlushFileAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSGetPosFile, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, u32* returnedFpos, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSGetPosFileAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, u32* returnedFpos, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSSetPosFile, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, u32 fpos, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSSetPosFileAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, u32 fpos, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSGetStatFile, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSStat* returnedStat, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSGetStatFileAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSStat* returnedStat, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSIsEof, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSIsEofAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_C(FSStatus, FSOpenDir, FSClient* client, FSCmdBlock* block, const char* path, FSDirHandle* dirHandle, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSOpenDirAsync, FSClient* client, FSCmdBlock* block, const char* path, FSDirHandle* dirHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSCloseDir, FSClient* client, FSCmdBlock* block, FSDirHandle dirHandle, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSCloseDirAsync, FSClient* client, FSCmdBlock* block, FSDirHandle dirHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSReadDir, FSClient* client, FSCmdBlock* block, FSDirHandle dirHandle, FSDirEntry* returnedDirEntry, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSReadDirAsync, FSClient* client, FSCmdBlock* block, FSDirHandle dirHandle, FSDirEntry* returnedDirEntry, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSRewindDir, FSClient* client, FSCmdBlock* block, FSDirHandle dirHandle, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSRewindDirAsync, FSClient* client, FSCmdBlock* block, FSDirHandle dirHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSMakeDir, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSMakeDirAsync, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_C(FSStatus, FSRemove, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSRemoveAsync, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSRename, FSClient* client, FSCmdBlock* block, const char* oldPath, const char* newPath, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSRenameAsync, FSClient* client, FSCmdBlock* block, const char* oldPath, const char* newPath, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_C(FSStatus, FSMakeQuota, FSClient* client, FSCmdBlock* block, const char* path, FSMode mode, u64 size, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSMakeQuotaAsync, FSClient* client, FSCmdBlock* block, const char* path, FSMode mode, u64 size, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSRemoveQuota, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSRemoveQuotaAsync, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSFlushQuota, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSFlushQuotaAsync, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSRollbackQuota, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSRollbackQuotaAsync, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_C(FSStatus, FSGetStat, FSClient* client, FSCmdBlock* block, const char* path, FSStat* returnedStat, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSGetStatAsync, FSClient* client, FSCmdBlock* block, const char* path, FSStat* returnedStat, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSGetFreeSpaceSize, FSClient* client, FSCmdBlock* block, const char* path, u64* returnedFreeSize, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSGetFreeSpaceSizeAsync, FSClient* client, FSCmdBlock* block, const char* path, u64* returnedFreeSize, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSGetDirSize, FSClient* client, FSCmdBlock* block, const char* path, u32* returnedDirSize, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSGetDirSizeAsync, FSClient* client, FSCmdBlock* block, const char* path, u32* returnedDirSize, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_C(FSStatus, FSGetEntryNum, FSClient* client, FSCmdBlock* block, const char* path, u32* returnedEntryNum, FSRetFlag errHandling);
EXPORT_FUNC_C(FSStatus, FSGetEntryNumAsync, FSClient* client, FSCmdBlock* block, const char* path, u32* returnedEntryNum, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_C(s32, FSGetLastErrorCodeForViewer, FSClient* client);
EXPORT_FUNC_C(s32, FSGetErrorCodeForViewer, FSClient* client, FSCmdBlock* block);
EXPORT_FUNC_C(void, FSTimeToCalendarTime, FSTime time, OSCalendarTime* td);

EXPORT_FUNC_C(FSError, FSGetLastError, FSClient* client);
EXPORT_FUNC_C(FSStatus, FSSetEmulatedError, FSClient* client, FSError error);
EXPORT_FUNC_C(FSError, FSGetEmulatedError, FSClient* client);

EXPORT_FUNC_C(int, IMEnableDim, void);
EXPORT_FUNC_C(int, IMDisableDim, void);
EXPORT_FUNC_C(int, IMIsDimEnabled, IMState* enabled);
EXPORT_FUNC_C(int, IMGetDimPeriod, u32* second);
EXPORT_FUNC_C(int, IMGetTimeBeforeDimming, u32* second);

EXPORT_FUNC_C(int, IMGetDimEnableTV, IMState* enabled);
EXPORT_FUNC_C(int, IMGetDimEnableDRC, IMState* enabled);
EXPORT_FUNC_C(int, IMSetDimEnableTV, IMState enable);
EXPORT_FUNC_C(int, IMSetDimEnableDRC, IMState enable);

EXPORT_FUNC_C(int, IMEnableAPD, void);
EXPORT_FUNC_C(int, IMDisableAPD, void);
EXPORT_FUNC_C(int, IMIsAPDEnabled, IMState* enabled);
EXPORT_FUNC_C(int, IMIsAPDEnabledBySysSettings, IMState* enabled);
EXPORT_FUNC_C(int, IMGetAPDPeriod, u32* second);
EXPORT_FUNC_C(int, IMGetTimeBeforeAPD, u32* second);

EXPORT_FUNC_C(int, IM_GetParameters, IMParameters* params);

EXPORT_FUNC_C(int, IOS_Open, const char* device, int mode);
EXPORT_FUNC_C(int, IOS_Close, int fd);
EXPORT_FUNC_C(int, IOS_Read, int fd, void* addr, size_t len);
EXPORT_FUNC_C(int, IOS_Write, int fd, void* addr, size_t len);
EXPORT_FUNC_C(int, IOS_Seek, int fd, int where, int whence);
EXPORT_FUNC_C(int, IOS_Ioctl, int fd, u32 request, IOSVector in, IOSVector out);
EXPORT_FUNC_C(int, IOS_Ioctlv, int fd, u32 request, u32 numIn, u32 numOut, IOSVector* vectors);

EXPORT_FUNC_C(MCPHandle, MCP_Open, void);
EXPORT_FUNC_C(int, MCP_Close, MCPHandle handle);
EXPORT_FUNC_C(int, MCP_GetOwnTitleInfo, MCPHandle handle, void* data);
EXPORT_FUNC_C(int, MCP_InstallTitleAbort, MCPHandle handle);
EXPORT_FUNC_C(int, MCP_InstallGetInfo, MCPHandle handle, const char* path, void* mcpInfo);
EXPORT_FUNC_C(int, MCP_InstallTitleAsync, MCPHandle handle, const char* path, void* mcpInfo);
EXPORT_FUNC_C(int, MCP_InstallGetProgress, MCPHandle handle, void* buffer);
EXPORT_FUNC_C(int, MCP_InstallSetTargetDevice, MCPHandle handle, int device);
EXPORT_FUNC_C(int, MCP_InstallSetTargetUsb, MCPHandle handle, int device);
EXPORT_FUNC_C(int, MCP_GetLastRawError, void);

EXPORT_FUNC_C(MEMHeapHandle, MEMFindContainHeap, const void* memBlock);
EXPORT_FUNC_C(MEMHeapHandle, MEMFindParentHeap, MEMHeapHandle heap);

EXPORT_FUNC_C(void, MEMDumpHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(bool, MEMCheckHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(u32, MEMSetFillValForHeap, MEMHeapFillType type, u32 val);
EXPORT_FUNC_C(u32, MEMGetFillValForHeap, MEMHeapFillType type);

EXPORT_FUNC_C(void, MEMInitList, MEMList* list, u16 offset);
EXPORT_FUNC_C(void, MEMAppendListObject, MEMList* list, void* object);
EXPORT_FUNC_C(void, MEMPrependListObject, MEMList* list, void* object);
EXPORT_FUNC_C(void, MEMInsertListObject, MEMList* list, void* target, void* object);
EXPORT_FUNC_C(void, MEMRemoveListObject, MEMList* list, void* object);
EXPORT_FUNC_C(void*, MEMGetNextListObject, MEMList* list, void* object);
EXPORT_FUNC_C(void*, MEMGetPrevListObject, MEMList* list, void* object);
EXPORT_FUNC_C(void*, MEMGetNthListObject, MEMList* list, u16 index);

EXPORT_FUNC_C(void, CoreInitDefaultHeap, MEMHeapHandle* mem1, MEMHeapHandle* memFG, MEMHeapHandle* mem2);
EXPORT_FUNC_C(MEMHeapHandle, MEMCreateUserHeapHandle, void* startAddress, u32 size);
EXPORT_DATA_FUNC_C(void*, MEMAllocFromDefaultHeap, u32 size);
EXPORT_DATA_FUNC_C(void*, MEMAllocFromDefaultHeapEx, u32 size, int alignment);
EXPORT_DATA_FUNC_C(void, MEMFreeToDefaultHeap, void* memBlock);

EXPORT_FUNC_C(void*, MEMAllocFromAllocator, MEMAllocator* allocator, u32 size);
EXPORT_FUNC_C(void, MEMFreeToAllocator, MEMAllocator* allocator, void* memBlock);

EXPORT_FUNC_C(void, MEMInitAllocatorForDefaultHeap, MEMAllocator* allocator);
EXPORT_FUNC_C(void, MEMInitAllocatorForBlockHeap, MEMAllocator* allocator, MEMHeapHandle heap, int alignment);
EXPORT_FUNC_C(void, MEMInitAllocatorForExpHeap, MEMAllocator* allocator, MEMHeapHandle heap, int alignment);
EXPORT_FUNC_C(void, MEMInitAllocatorForFrmHeap, MEMAllocator* allocator, MEMHeapHandle heap, int alignment);
EXPORT_FUNC_C(void, MEMInitAllocatorForUnitHeap, MEMAllocator* allocator, MEMHeapHandle heap);

EXPORT_FUNC_C(MEMArena, MEMGetArena, MEMHeapHandle heap);
EXPORT_FUNC_C(MEMHeapHandle, MEMGetBaseHeapHandle, MEMArena arena);
EXPORT_FUNC_C(MEMHeapHandle, MEMSetBaseHeapHandle, MEMArena arena, MEMHeapHandle heap);

EXPORT_FUNC_C(MEMHeapHandle, MEMInitBlockHeap, MEMBlockHeap* tracking, void* start_addr, void* end_addr, void* init_track_mem, u32 init_track_mem_bytes, MEMHeapOpt optFlag);
EXPORT_FUNC_C(int, MEMAddBlockHeapTracking, MEMHeapHandle heap, void* track_mem, u32 track_mem_bytes);
EXPORT_FUNC_C(void*, MEMDestroyBlockHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(void*, MEMAllocFromBlockHeapAt, MEMHeapHandle heap, void* place, u32 size);
EXPORT_FUNC_C(void*, MEMAllocFromBlockHeapEx, MEMHeapHandle heap, u32 size, int alignment);
EXPORT_FUNC_C(void, MEMFreeToBlockHeap, MEMHeapHandle heap, void* memBlock);
EXPORT_FUNC_C(u32, MEMGetTrackingLeftInBlockHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(u32, MEMGetTotalFreeSizeForBlockHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(u32, MEMGetAllocatableSizeForBlockHeapEx, MEMHeapHandle heap, int alignment);

EXPORT_FUNC_C(MEMHeapHandle, MEMCreateExpHeapEx, void* startAddress, u32 size, MEMHeapOpt optFlag);
EXPORT_FUNC_C(void*, MEMDestroyExpHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(void*, MEMAllocFromExpHeapEx, MEMHeapHandle heap, u32 size, int alignment);
EXPORT_FUNC_C(u32, MEMResizeForMBlockExpHeap, MEMHeapHandle heap, void* memBlock, u32 size);
EXPORT_FUNC_C(void, MEMFreeToExpHeap, MEMHeapHandle heap, void* memBlock);
EXPORT_FUNC_C(u32, MEMGetTotalFreeSizeForExpHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(u32, MEMGetAllocatableSizeForExpHeapEx, MEMHeapHandle heap, int alignment);
EXPORT_FUNC_C(u16, MEMSetAllocModeForExpHeap, MEMHeapHandle heap, u16 mode);
EXPORT_FUNC_C(u16, MEMGetAllocModeForExpHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(bool, MEMUseMarginOfAlignmentForExpHeap, MEMHeapHandle heap, bool reuse);
EXPORT_FUNC_C(u16, MEMSetGroupIDForExpHeap, MEMHeapHandle heap, u16 groupID);
EXPORT_FUNC_C(u16, MEMGetGroupIDForExpHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(void, MEMVisitAllocatedForExpHeap, MEMHeapHandle heap, MEMHeapVisitor visitor, u32 userParam);
EXPORT_FUNC_C(u32, MEMGetSizeForMBlockExpHeap, const void* memBlock);
EXPORT_FUNC_C(u16, MEMGetGroupIDForMBlockExpHeap, const void* memBlock);
EXPORT_FUNC_C(u16, MEMGetAllocDirForMBlockExpHeap, const void* memBlock);
EXPORT_FUNC_C(u32, MEMAdjustExpHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(bool, MEMCheckExpHeap, MEMHeapHandle heap, MEMHeapCheckOpt optFlag);
EXPORT_FUNC_C(bool, MEMCheckForMBlockExpHeap, const void* memBlock, MEMHeapHandle heap, MEMHeapCheckOpt optFlag);
EXPORT_FUNC_C(bool, MEMiIsEmptyExpHeap, MEMHeapHandle heap);

EXPORT_FUNC_C(MEMHeapHandle, MEMCreateFrmHeapEx, void* startAddress, u32 size, MEMHeapOpt optFlag);
EXPORT_FUNC_C(void*, MEMDestroyFrmHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(void*, MEMAllocFromFrmHeapEx, MEMHeapHandle heap, u32 size, int alignment);
EXPORT_FUNC_C(void, MEMFreeToFrmHeap, MEMHeapHandle heap, MEMFrmHeapFreeMode mode);
EXPORT_FUNC_C(u32, MEMGetAllocatableSizeForFrmHeapEx, MEMHeapHandle heap, int alignment);
EXPORT_FUNC_C(bool, MEMRecordStateForFrmHeap, MEMHeapHandle heap, u32 tagName);
EXPORT_FUNC_C(bool, MEMFreeByStateToFrmHeap, MEMHeapHandle heap, u32 tagName);
EXPORT_FUNC_C(u32, MEMAdjustFrmHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(u32, MEMResizeForMBlockFrmHeap, MEMHeapHandle heap, void* memBlock, u32 newSize);
EXPORT_FUNC_C(void*, MEMiGetFreeStartForFrmHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(void*, MEMiGetFreeEndForFrmHeap, MEMHeapHandle heap);

EXPORT_FUNC_C(MEMHeapHandle, MEMCreateUnitHeapEx, void* startAddress, u32 heapSize, u32 memBlockSize, int alignment, u16 optFlag);
EXPORT_FUNC_C(void*, MEMDestroyUnitHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(void*, MEMAllocFromUnitHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(void, MEMFreeToUnitHeap, MEMHeapHandle heap, void* memBlock);
EXPORT_FUNC_C(u32, MEMCountFreeBlockForUnitHeap, MEMHeapHandle heap);
EXPORT_FUNC_C(u32, MEMCalcHeapSizeForUnitHeap, u32 memBlockSize, u32 memBlockNum, int alignment);

EXPORT_FUNC_C(void, MPInitTaskQ, MPTaskQ* taskQ, MPTask** taskList, u32 numTasks);
EXPORT_FUNC_C(bool, MPTermTaskQ, MPTaskQ* taskQ);
EXPORT_FUNC_C(bool, MPGetTaskQInfo, MPTaskQ* taskQ, MPTaskQInfo* taskQInfo);
EXPORT_FUNC_C(bool, MPStartTaskQ, MPTaskQ* taskQ);
EXPORT_FUNC_C(bool, MPRunTasksFromTaskQ, MPTaskQ* taskQ, int dequeGranularity);
EXPORT_FUNC_C(bool, MPStopTaskQ, MPTaskQ* taskQ);
EXPORT_FUNC_C(bool, MPWaitTaskQ, MPTaskQ* taskQ, MPWaitMask mask);
EXPORT_FUNC_C(bool, MPWaitTaskQWithTimeout, MPTaskQ* taskQ, MPWaitMask mask, OSTime timeoutNs);
EXPORT_FUNC_C(bool, MPEnqueTask, MPTaskQ* taskQ, MPTask* task);
EXPORT_FUNC_C(MPTask*, MPDequeTask, MPTaskQ* taskQ);
EXPORT_FUNC_C(u32, MPDequeTasks, MPTaskQ* taskQ, MPTask** tasks, int maxTasks);
EXPORT_FUNC_C(bool, MPResetTaskQ, MPTaskQ* taskQ);
EXPORT_FUNC_C(bool, MPPrintTaskQStats, MPTaskQ* taskQ, int size);

EXPORT_FUNC_C(void, MPInitTask, MPTask* task, void* func, void* data, u32 dataLen);
EXPORT_FUNC_C(bool, MPTermTask, MPTask* task);
EXPORT_FUNC_C(bool, MPGetTaskInfo, MPTask* task, MPTaskInfo* taskInfo);
EXPORT_FUNC_C(bool, MPRunTask, MPTask* task);
EXPORT_FUNC_C(void*, MPGetTaskUserData, MPTask* task);
EXPORT_FUNC_C(void, MPSetTaskUserData, MPTask* task, void* userData);

EXPORT_FUNC_C(OSTick, OSGetTick, void);
EXPORT_FUNC_C(OSTime, OSGetTime, void);
EXPORT_FUNC_C(OSTick, OSGetSystemTick, void);
EXPORT_FUNC_C(OSTime, OSGetSystemTime, void);
EXPORT_FUNC_C(OSTime, OSCalendarTimeToTicks, OSCalendarTime* td);
EXPORT_FUNC_C(void, OSTicksToCalendarTime, OSTime ticks, OSCalendarTime* td);
EXPORT_FUNC_C(void, OSWaitMicroseconds, OSTime microseconds);

EXPORT_FUNC_C(void, OSInitThreadQueue, OSThreadQueue* queue);
EXPORT_FUNC_C(void, OSInitThreadQueueEx, OSThreadQueue* queue, void* parent_struct);

EXPORT_FUNC_C(OSThread*, OSGetCurrentThread, void);
EXPORT_FUNC_C(OSThread*, OSGetDefaultThread, OSCoreId coreId);
EXPORT_FUNC_C(long, OSCheckActiveThreads, void);

EXPORT_FUNC_C(bool, OSCreateThread, OSThread* thread, OSThreadFunc entryPoint, int intArg, void* ptrArg, void* stack, u32 stackSize, OSPriority priority, u16 attr);
EXPORT_FUNC_C(bool, OSCreateThreadType, OSThread* thread, OSThreadFunc entryPoint, int intArg, void* ptrArg, void* stack, u32 stackSize, OSPriority priority, u16 attr, OSThreadType type);
EXPORT_FUNC_C(bool, OSRunThread, OSThread* thread, OSThreadFunc func, int intArg, void* ptrArg);
EXPORT_FUNC_C(void, OSExitThread, int val);
EXPORT_FUNC_C(void, OSCancelThread, OSThread* thread);
EXPORT_FUNC_C(bool, OSJoinThread, OSThread* thread, int* val);
EXPORT_FUNC_C(void, OSDetachThread, OSThread* thread);
EXPORT_FUNC_C(void, OSSleepThread, OSThreadQueue* queue);
EXPORT_FUNC_C(void, OSSleepTicks, OSTime ticks);
EXPORT_FUNC_C(void, OSWakeupThread, OSThreadQueue* queue);
EXPORT_FUNC_C(s32, OSSuspendThread, OSThread* thread);
EXPORT_FUNC_C(s32, OSResumeThread, OSThread* thread);
EXPORT_FUNC_C(void, OSYieldThread, void);
EXPORT_FUNC_C(void, OSContinueThread, OSThread* thread);

EXPORT_FUNC_C(bool, OSIsThreadSuspended, OSThread* thread);
EXPORT_FUNC_C(bool, OSIsThreadTerminated, OSThread* thread);

EXPORT_FUNC_C(bool, OSGetActiveThreadLink, OSThread* thread, OSThreadLink* threadLink);
EXPORT_FUNC_C(void, OSSetThreadName, OSThread* thread, const char* name);
EXPORT_FUNC_C(const char*, OSGetThreadName, OSThread const* thread);
EXPORT_FUNC_C(bool, OSSetThreadPriority, OSThread* thread, OSPriority priority);
EXPORT_FUNC_C(OSPriority, OSGetThreadPriority, OSThread* thread);
EXPORT_FUNC_C(bool, OSSetThreadAffinity, OSThread* thread, OSCoreAffinity affinity);
EXPORT_FUNC_C(OSCoreAffinity, OSGetThreadAffinity, OSThread* thread);
EXPORT_FUNC_C(void*, OSGetThreadSpecific, s32 index);
EXPORT_FUNC_C(void, OSSetThreadSpecific, s32 index, void* ptr);
EXPORT_FUNC_C(OSTime, OSGetThreadCoreTime, const OSThread* thread, OSCoreAffinity affinity);
EXPORT_FUNC_C(bool, OSSetThreadRunQuantum, OSThread* thread, u32 quantumMicrosec);
EXPORT_FUNC_C(OSThreadCleanupFunc, OSSetThreadCleanupCallback, OSThread* thread, OSThreadCleanupFunc callback);
EXPORT_FUNC_C(OSThreadDeallocatorFunc, OSSetThreadDeallocator, OSThread* thread, OSThreadDeallocatorFunc deallocator);

EXPORT_FUNC_C(u32, OSGetUserStackPointer, OSThread* thread);
EXPORT_FUNC_C(bool, OSSetThreadStackUsage, OSThread* thread);
EXPORT_FUNC_C(void, OSClearThreadStackUsage, OSThread* thread);
EXPORT_FUNC_C(s32, OSCheckThreadStackUsage, OSThread* thread);
EXPORT_FUNC_C(void, OSClearStack, u8 val);

EXPORT_FUNC_C(void, OSTestThreadCancel, void);
EXPORT_FUNC_C(bool, OSSetThreadCancelState, bool cancelState);

EXPORT_FUNC_C(bool, OSIsSchedulerLocked, void* lockid);

EXPORT_FUNC_C(u32, OSGetCoreCount, void);
EXPORT_FUNC_C(OSCoreId, OSGetCoreId, void);
EXPORT_FUNC_C(OSCoreId, OSGetMainCoreId, void);
EXPORT_FUNC_C(bool, OSIsMainCore, void);

EXPORT_FUNC_C(void, OSInitAlarmQueue, OSAlarmQueue* queue);
EXPORT_FUNC_C(void, OSInitAlarmQueueEx, OSAlarmQueue* queue, char* name);

EXPORT_FUNC_C(void, OSCreateAlarm, OSAlarm* alarm);
EXPORT_FUNC_C(void, OSCreateAlarmEx, OSAlarm* alarm, char* name);
EXPORT_FUNC_C(bool, OSSetAlarm, OSAlarm* alarm, OSTime tick, OSAlarmHandler handler);
EXPORT_FUNC_C(bool, OSSetPeriodicAlarm, OSAlarm* alarm, OSTime start, OSTime period, OSAlarmHandler handler);
EXPORT_FUNC_C(void, OSSetAlarmTag, OSAlarm* alarm, u32 tag);
EXPORT_FUNC_C(void, OSSetAlarmUserData, OSAlarm* alarm, void* data);
EXPORT_FUNC_C(void*, OSGetAlarmUserData, const OSAlarm* alarm);
EXPORT_FUNC_C(bool, OSCancelAlarm, OSAlarm* alarm);
EXPORT_FUNC_C(void, OSCancelAlarms, u32 tag);
EXPORT_FUNC_C(bool, OSWaitAlarm, OSAlarm* alarm);

EXPORT_FUNC_C(s32, OSAddAtomic, volatile OSAtomicVar* ptr, s32 val);
EXPORT_FUNC_C(u32, OSOrAtomic, volatile OSAtomicVar* ptr, u32 mask);
EXPORT_FUNC_C(u32, OSAndAtomic, volatile OSAtomicVar* ptr, u32 mask);
EXPORT_FUNC_C(u32, OSXorAtomic, volatile OSAtomicVar* ptr, u32 mask);
EXPORT_FUNC_C(u32, OSSwapAtomic, volatile OSAtomicVar* ptr, u32 val);
EXPORT_FUNC_C(bool, OSCompareAndSwapAtomic, volatile OSAtomicVar* ptr, u32 cmpVal, u32 newVal);
EXPORT_FUNC_C(bool, OSCompareAndSwapAtomicEx, volatile OSAtomicVar* ptr, u32 cmpVal, u32 newVal, u32* origVal);
EXPORT_FUNC_C(bool, OSTestAndSetAtomic, volatile OSAtomicVar* ptr, u32 bitnum);
EXPORT_FUNC_C(bool, OSTestAndClearAtomic, volatile OSAtomicVar* ptr, u32 bitnum);

EXPORT_FUNC_C(u64, OSGetAtomic64, volatile OSAtomicVar64* ptr);
EXPORT_FUNC_C(u64, OSSetAtomic64, volatile OSAtomicVar64* ptr, u64 val);
EXPORT_FUNC_C(s64, OSAddAtomic64, volatile OSAtomicVar64* ptr, s64 val);
EXPORT_FUNC_C(u64, OSOrAtomic64, volatile OSAtomicVar64* ptr, u64 mask);
EXPORT_FUNC_C(u64, OSAndAtomic64, volatile OSAtomicVar64* ptr, u64 mask);
EXPORT_FUNC_C(u64, OSXorAtomic64, volatile OSAtomicVar64* ptr, u64 mask);
EXPORT_FUNC_C(u64, OSSwapAtomic64, volatile OSAtomicVar64* ptr, u64 val);
EXPORT_FUNC_C(bool, OSCompareAndSwapAtomic64, volatile OSAtomicVar64* ptr, u64 cmpVal, u64 newVal);
EXPORT_FUNC_C(bool, OSCompareAndSwapAtomicEx64, volatile OSAtomicVar64* ptr, u64 cmpVal, u64 newVal, u64* origVal);
EXPORT_FUNC_C(bool, OSTestAndSetAtomic64, volatile OSAtomicVar64* ptr, u32 bitnum);
EXPORT_FUNC_C(bool, OSTestAndClearAtomic64, volatile OSAtomicVar64* ptr, u32 bitnum);

EXPORT_FUNC_C(bool, OSIsAddressRangeDCValid, const void* addr, u32 nBytes);

EXPORT_FUNC_C(void, OSMemoryBarrier, void);
EXPORT_FUNC_C(void, OSCoherencyBarrier, void);

EXPORT_FUNC_C(bool, OSCopyToClipboard, const void* ptr, u32 size);
EXPORT_FUNC_C(bool, OSCopyFromClipboard, void* ptr, u32* pSize);

EXPORT_FUNC_C(void, OSGetCodegenVirtAddrRange, va_t* va, size_t* size);
EXPORT_FUNC_C(u32, OSGetCodegenCore, void);
EXPORT_FUNC_C(u32, OSGetCodegenMode, void);
EXPORT_FUNC_C(bool, OSSwitchSecCodeGenMode, OSSecCodeGenMode mode);
EXPORT_FUNC_C(OSSecCodeGenMode, OSGetSecCodeGenMode, void);
EXPORT_FUNC_C(bool, OSCodegenCopy, void* dst, const void* src, size_t size);

EXPORT_FUNC_C(void, OSInitCond, OSCond* cond);
EXPORT_FUNC_C(void, OSInitCondEx, OSCond* cond, char* name);
EXPORT_FUNC_C(void, OSWaitCond, OSCond* cond, OSMutex* mutex);
EXPORT_FUNC_C(void, OSSignalCond, OSCond* cond);

EXPORT_FUNC_C(u32, OSGetStackPointer, void);
EXPORT_FUNC_C(u32, OSSwitchStack, u32 newSP);

EXPORT_FUNC_C(int, OSSwitchFiber, u32 pc, u32 newSP);
EXPORT_FUNC_C(int, OSSwitchFiberEx, u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 pc, u32 newSP);

EXPORT_FUNC_C(void, OSSetCurrentContext, OSContext* context);
EXPORT_FUNC_C(OSContext*, OSGetCurrentContext, void);
EXPORT_FUNC_C(u32, OSSaveContext, OSContext* context);
EXPORT_FUNC_C(void, OSLoadContext, OSContext* context);
EXPORT_FUNC_C(void, OSClearContext, OSContext* context);
EXPORT_FUNC_C(void, OSInitContext, OSContext* context, u32 pc, u32 sp);

EXPORT_FUNC_C(OSContext*, OSGetCurrentFPUContext, void);
EXPORT_FUNC_C(void, OSSetCurrentFPUContext, OSContext* context);
EXPORT_FUNC_C(void, OSLoadFPUContext, OSContext* context);
EXPORT_FUNC_C(void, OSSaveFPUContext, OSContext* context);
EXPORT_FUNC_C(void, OSDumpContext, OSContext* context);

EXPORT_FUNC_C(void, OSInitCoroutine, OSCoroutine* coroutine, void* pc, void* sp);
EXPORT_FUNC_C(void, OSLoadCoroutine, OSCoroutine* coroutine, void* retval);
EXPORT_FUNC_C(void*, OSSaveCoroutine, OSCoroutine* coroutine);
EXPORT_FUNC_C(void, OSSwitchCoroutine, OSCoroutine* current, OSCoroutine* next);

EXPORT_FUNC_C(bool, OSIsDebuggerPresent, void);
EXPORT_FUNC_C(bool, OSIsDebuggerInitialized, void);

EXPORT_FUNC_C(void, OSReport, const char* msg, ...);
EXPORT_FUNC_C(void, OSVReport, const char* msg, va_list list);
EXPORT_FUNC_C(void, OSReportWarn, const char* msg, ...);
EXPORT_FUNC_C(void, OSReportInfo, const char* msg, ...);
EXPORT_FUNC_C(void, OSReportVerbose, const char* msg, ...);

EXPORT_FUNC_C(void, OSConsoleWrite, const char* buf, unsigned long len);
EXPORT_FUNC_C(void, OSSupressConsoleOutput, bool umSuppress, bool appSuppress, bool kmSuppress);

EXPORT_FUNC_C(void, COSWarn, u32 module, const char* msg, ...);
EXPORT_FUNC_C(void, COSInfo, u32 module, const char* msg, ...);
EXPORT_FUNC_C(void, COSVerbose, u32 module, const char* msg, ...);
EXPORT_FUNC_C(void, COSError, u32 module, const char* msg, ...);
EXPORT_FUNC_C(void, COSVReport, u32 module, const char* msg, va_list list);

EXPORT_FUNC_C(int, OSDynLoad_GetNumberOfRPLs, void);
EXPORT_FUNC_C(bool, OSDynLoad_GetRPLInfo, u32 index, u32 count, OSNotifyHdr* infobuffer);

EXPORT_FUNC_C(OSDynLoadError, OSDynLoad_AddNotifyCallback, OSNotifyFunc func, void* userArg);
EXPORT_FUNC_C(void, OSDynLoad_DelNotifyCallback, OSNotifyFunc func, void* userArg);

EXPORT_FUNC_C(OSDynLoadError, OSDynLoad_SetAllocator, OSMemAllocFunc alloc, OSMemFreeFunc free);
EXPORT_FUNC_C(OSDynLoadError, OSDynLoad_GetAllocator, OSMemAllocFunc* retAlloc, OSMemFreeFunc* retFree);

EXPORT_FUNC_C(OSDynLoadError, OSDynLoad_SetTLSAllocator, OSMemAllocFunc alloc, OSMemFreeFunc free);
EXPORT_FUNC_C(OSDynLoadError, OSDynLoad_GetTLSAllocator, OSMemAllocFunc* retAlloc, OSMemFreeFunc* retFree);

EXPORT_FUNC_C(OSDynLoadError, OSDynLoad_Acquire, const char* baseModuleName, OSModuleHandle* retHandle);
EXPORT_FUNC_C(OSDynLoadError, OSDynLoad_AcquireContainingModule, void* object, OSSegmentRestrictionFlags restrictFlags, OSModuleHandle* retHandle);
EXPORT_FUNC_C(void, OSDynLoad_Release, OSModuleHandle moduleHandle);
EXPORT_FUNC_C(OSDynLoadError, OSDynLoad_IsModuleLoaded, const char* fileName, OSModuleHandle* retHandle);
EXPORT_FUNC_C(OSDynLoadError, OSDynLoad_GetModuleName, OSModuleHandle moduleHandle, char* retBuffer, int* bufferSize);
EXPORT_FUNC_C(OSDynLoadError, OSDynLoad_FindExport, OSModuleHandle moduleHandle, int isData, const char* exportName, void** retAddr);
EXPORT_FUNC_C(OSDynLoadError, OSDynLoad_FindTag, OSModuleHandle moduleHandle, const char* tag, char* retBuffer, int* bufferSize);

EXPORT_FUNC_C(OSDynLoadError, OSDynLoad_GetLoaderHeapStatistics, OSLoaderHeapStatistics* retLoaderHeapStatistics);

EXPORT_FUNC_C(OSError, OSGetLastError, void);
EXPORT_FUNC_C(void*, OSGetSymbolName, u32 addr, u8* symbolName, u32 nameBufSize);

EXPORT_FUNC_C(void, OSSetPanicCallback, OSPanicCBFunc func, void* arg);

EXPORT_FUNC_C(void, OSGetCrashInfo, OSCrashInfo* info);
EXPORT_FUNC_C(OSCrashDumpType, OSGetCrashDumpType, void);
EXPORT_FUNC_C(void, OSSetCrashDumpType, OSCrashDumpType type);
EXPORT_FUNC_C(OSCrashDetailLevel, OSGetCrashDetailLevel, void);
EXPORT_FUNC_C(void, OSSetCrashDetailLevel, OSCrashDetailLevel type);
EXPORT_FUNC_C(bool, OSRestartCrashedApp, void* args, u32 argsBytes);
EXPORT_FUNC_C(bool, OSRebootCrash, void);

EXPORT_FUNC_C(u32, OSGetTimestampLevel, void);
EXPORT_FUNC_C(void, OSSetTimestampLevel, bool enabled);

EXPORT_FUNC_C(void, OSFatal, const char* msg);
EXPORT_FUNC_C(void, OSPanic, const char* file, int line, const char* msg, ...);

EXPORT_FUNC_C(void, OSInitEvent, OSEvent* event, bool initialState, OSEventMode mode);
EXPORT_FUNC_C(void, OSInitEventEx, OSEvent* event, bool initialState, OSEventMode mode, char* name);
EXPORT_FUNC_C(void, OSSignalEvent, OSEvent* event);
EXPORT_FUNC_C(void, OSSignalEventAll, OSEvent* event);
EXPORT_FUNC_C(void, OSWaitEvent, OSEvent* event);
EXPORT_FUNC_C(void, OSResetEvent, OSEvent* event);
EXPORT_FUNC_C(bool, OSWaitEventWithTimeout, OSEvent* event, OSTime timeout);

EXPORT_FUNC_C(OSExceptionCallback, OSSetExceptionCallback, OSExceptionType exceptionType, OSExceptionCallback callback);
EXPORT_FUNC_C(OSExceptionCallback, OSSetExceptionCallbackEx, OSExceptionMode exceptionMode, OSExceptionType exceptionType, OSExceptionCallback newCallback);

EXPORT_FUNC_C(void, OSSetDABR, bool allCores, void* address, bool matchReads, bool matchWrites);
EXPORT_FUNC_C(void, OSSetIABR, bool allCores, void* address);

EXPORT_FUNC_C(bool, OSEnableThreadFPUException, OSThread* thread, OSFPUExceptionMask fpuExMask);
EXPORT_FUNC_C(u32, OSEnableAllThreadFPUException, OSFPUExceptionMask fpuExMask);
EXPORT_FUNC_C(bool, OSDisableThreadFPUException, OSThread* thread);
EXPORT_FUNC_C(u32, OSDisableAllThreadFPUException, void);
EXPORT_FUNC_C(void, OSDisableContextFPUException, OSContext* context);

EXPORT_FUNC_C(void, OSFastCond_Init, OSFastCond* fastCond, char* name);
EXPORT_FUNC_C(void, OSFastCond_Wait, OSFastCond* fastCond, OSFastMutex* fastMutex);
EXPORT_FUNC_C(void, OSFastCond_Signal, OSFastCond* fastCond);

EXPORT_FUNC_C(void, OSFastMutex_Init, OSFastMutex* fastMutex, char* name);
EXPORT_FUNC_C(void, OSFastMutex_Lock, OSFastMutex* fastMutex);
EXPORT_FUNC_C(void, OSFastMutex_Unlock, OSFastMutex* fastMutex);
EXPORT_FUNC_C(bool, OSFastMutex_TryLock, OSFastMutex* fastMutex);

EXPORT_FUNC_C(u16, OSReadRegister16, u32 device, u32 id);
EXPORT_FUNC_C(u32, OSReadRegister32, u32 device, u32 id);
EXPORT_FUNC_C(void, OSWriteRegister16, u32 device, u32 id, u16 value);
EXPORT_FUNC_C(void, OSWriteRegister32, u32 device, u32 id, u32 value);

EXPORT_FUNC_C(void, OSEnforceInorderIO, void);

EXPORT_FUNC_C(u64, OSGetOSID, void);
EXPORT_FUNC_C(u32, OSGetConsoleType, void);
EXPORT_FUNC_C(OSSecurityLevel, OSGetSecurityLevel, void);

EXPORT_FUNC_C(bool, OSSetInfo, OSInfoType selector, void* infoSrcAddr, u32 size, OSInfoOption options);
EXPORT_FUNC_C(bool, OSGetInfo, OSInfoType selector, void* infoDestAddr, u32 size, OSInfoOption options);

EXPORT_FUNC_C(OSSystemInfo*, OSGetSystemInfo, void);

EXPORT_FUNC_C(bool, OSDisableInterrupts, void);
EXPORT_FUNC_C(bool, OSEnableInterrupts, void);
EXPORT_FUNC_C(bool, OSRestoreInterrupts, bool level);
EXPORT_FUNC_C(bool, OSIsInterruptEnabled, void);

EXPORT_FUNC_C(OSTitleID, OSGetTitleID, void);

EXPORT_FUNC_C(int, OSLaunchTitlev, u64 titleId, u32 argc, char* argv[]);
EXPORT_FUNC_C(int, OSLaunchTitlel, u64 titleId, u32 argc, ...);
EXPORT_FUNC_C(int, OSLaunchTitleByPathv, const char* path, u32 pathLen, u32 argc, char* argv[]);
EXPORT_FUNC_C(int, OSLaunchTitleByPathl, const char* path, u32 pathLen, u32 argc, ...);

EXPORT_FUNC_C(int, OSRestartGame, u32 argc, char** argv);
EXPORT_FUNC_C(void, OSForceFullRelaunch, void);

EXPORT_FUNC_C(OSShutdownReason, OSGetShutdownReason, void);
EXPORT_FUNC_C(OSShutdownFlag, OSGetShutdownFlags, void);

EXPORT_FUNC_C(void, OSBlockThreadsOnExit, void);
EXPORT_FUNC_C(bool, OSIsBlockThreadsOnExit, void);

EXPORT_FUNC_C(void, OSRunThreadsOnExit, void);

EXPORT_FUNC_C(void, OSSavesDone_ReadyToRelease, void);
EXPORT_FUNC_C(bool, OSRequestFastExit, u32 flags, bool runExit);

EXPORT_FUNC_C(void, OSEnableForegroundExit, void);
EXPORT_FUNC_C(void, OSReleaseForeground, void);
EXPORT_FUNC_C(bool, OSGetForegroundBucket, void** retArea, u32* retSizeBytes);
EXPORT_FUNC_C(bool, OSGetForegroundBucketFreeArea, void** retArea, u32* retSizeBytes);

EXPORT_FUNC_C(bool, OSSendAppSwitchRequest, UPID procId, void* args, u32 argsBytes);
EXPORT_FUNC_C(bool, OSGetCallArgs, UPID* retCaller, u8* buffer, u32 bufferBytes);
EXPORT_FUNC_C(void, OSGetArgcArgv, int* retArgc, char const*** retArgv);

EXPORT_FUNC_C(bool, OSSetScreenCapturePermission, bool enabled);
EXPORT_FUNC_C(bool, OSGetScreenCapturePermission, void);
EXPORT_FUNC_C(bool, OSSetScreenCapturePermissionEx, bool tvEnabled, bool drcEnabled);
EXPORT_FUNC_C(bool, OSGetScreenCapturePermissionEx, bool* tvEnabled, bool* drcEnabled);

EXPORT_FUNC_C(bool, OSIsHomeButtonMenuEnabled, void);
EXPORT_FUNC_C(bool, OSEnableHomeButtonMenu, bool enable);

EXPORT_FUNC_C(bool, OSIsColdBoot, void);
EXPORT_FUNC_C(bool, OSIsSelfRefreshBoot, void);
EXPORT_FUNC_C(bool, OSIsNormalBoot, void);
EXPORT_FUNC_C(bool, OSIsECOBoot, void);
EXPORT_FUNC_C(bool, OSIsStandbyBoot, void);
EXPORT_FUNC_C(bool, OSIsOffBoot, void);
EXPORT_FUNC_C(bool, OSIsCompatBoot, void);
EXPORT_FUNC_C(bool, OSIsProdMode, void);
EXPORT_FUNC_C(bool, OSIsECOMode, void);

EXPORT_FUNC_C(bool, OSSendPolicyRequest, OSPolicyRequest policy, UPID targetProcId);

EXPORT_FUNC_C(va_t, OSAllocVirtAddr, va_t va, size_t size, size_t align);
EXPORT_FUNC_C(bool, OSFreeVirtAddr, va_t va, size_t size);
EXPORT_FUNC_C(int, OSQueryVirtAddr, va_t va);

EXPORT_FUNC_C(void, OSGetMapVirtAddrRange, va_t* va, size_t* size);
EXPORT_FUNC_C(void, OSGetDataPhysAddrRange, pa_t* dataPA, size_t* dataSize);
EXPORT_FUNC_C(void, OSGetAvailPhysAddrRange, pa_t* availPA, size_t* availSize);
EXPORT_FUNC_C(pa_t, OSEffectiveToPhysical, va_t va);

EXPORT_FUNC_C(bool, OSMapMemory, va_t va, pa_t pa, size_t size, OSMapMode mode);
EXPORT_FUNC_C(bool, OSUnmapMemory, va_t va, size_t size);

EXPORT_FUNC_C(OSOverlayArenaError, OSGetMemBound, OSMemType memType, u32* retStart, u32* retSizeBytes);
EXPORT_FUNC_C(OSOverlayArenaError, OSSetMemBound, OSMemType memType, u32 start, u32 sizeBytes);

EXPORT_FUNC_C(void*, OSAllocFromSystem, u32 size, int align);
EXPORT_FUNC_C(void, OSFreeToSystem, void* ptr);
EXPORT_FUNC_C(bool, OSIsAddressValid, void* addr);

EXPORT_FUNC_C(void*, OSBlockMove, void* dst, const void* src, size_t size, bool flush);
EXPORT_FUNC_C(void*, OSBlockSet, void* dst, u8 val, size_t size);

EXPORT_FUNC_C(bool, OSGetSharedData, OSShared shared, u32 flags, void** retArea, u32* retSizeBytes);

EXPORT_FUNC_C(bool, OSIsEnabledOverlayArenaDev, void);
EXPORT_FUNC_C(void, OSEnableOverlayArenaDev, bool allowAV, u32* addr, u32* size);
EXPORT_FUNC_C(bool, OSEnableOverlayArenaWithTimeoutDev, bool allowAV, u32 timeout, u32* error, u32* addr, u32* size);
EXPORT_FUNC_C(void, OSDisableOverlayArenaDev, void);
EXPORT_FUNC_C(bool, OSDisableOverlayArenaWithTimeoutDev, u32 timeout, u32* error);
EXPORT_FUNC_C(void, OSGetOverlayArenaRangeDev, u32* addr, u32* size);

EXPORT_FUNC_C(void, OSInitMessageQueue, OSMessageQueue* queue, OSMessage* msgArray, s32 msgCount);
EXPORT_FUNC_C(void, OSInitMessageQueueEx, OSMessageQueue* queue, OSMessage* msgArray, s32 msgCount, char* name);
EXPORT_FUNC_C(bool, OSSendMessage, OSMessageQueue* queue, OSMessage* msg, OSMessageFlag flags);
EXPORT_FUNC_C(bool, OSReceiveMessage, OSMessageQueue* queue, OSMessage* msg, OSMessageFlag flags);
EXPORT_FUNC_C(bool, OSPeekMessage, OSMessageQueue* queue, OSMessage* msg);

EXPORT_FUNC_C(OSMessageQueue*, OSGetSystemMessageQueue, void);
EXPORT_FUNC_C(OSMessageQueue*, OSGetDefaultAppIOQueue, void);

EXPORT_FUNC_C(void, OSInitMutex, OSMutex* mutex);
EXPORT_FUNC_C(void, OSInitMutexEx, OSMutex* mutex, char* name);
EXPORT_FUNC_C(void, OSLockMutex, OSMutex* mutex);
EXPORT_FUNC_C(void, OSUnlockMutex, OSMutex* mutex);
EXPORT_FUNC_C(bool, OSTryLockMutex, OSMutex* mutex);

EXPORT_FUNC_C(u32, OSGetBootPMFlags, void);
EXPORT_FUNC_C(u32, OSGetLastPMState, void);
EXPORT_FUNC_C(u32, OSGetCurrentPMState, void);

EXPORT_FUNC_C(void, OSSetPerformanceMonitor, OSPMMask pmMask, u32 mmcr0, u32 mmcr1, u32 pmc1, u32 pmc2, u32 pmc3, u32 pmc4);

EXPORT_FUNC_C(void, OSInitRendezvous, OSRendezvous* ren);
EXPORT_FUNC_C(bool, OSWaitRendezvous, OSRendezvous* ren, u32 mask);
EXPORT_FUNC_C(bool, OSWaitRendezvousWithTimeout, OSRendezvous* ren, u32 mask, OSTime timeout);

EXPORT_FUNC_C(void, OSScreenInit, void);
EXPORT_FUNC_C(void, OSScreenShutdown, void);
EXPORT_FUNC_C(void, OSScreenEnableEx, int bufferId, bool enable);
EXPORT_FUNC_C(size_t, OSScreenGetBufferSizeEx, int bufferId);
EXPORT_FUNC_C(void, OSScreenSetBufferEx, int bufferId, void* buffer);
EXPORT_FUNC_C(void, OSScreenFlipBuffersEx, int bufferId);
EXPORT_FUNC_C(void, OSScreenClearBufferEx, int bufferId, u32 color);
EXPORT_FUNC_C(void, OSScreenPutPixelEx, int bufferId, u32 x, u32 y, u32 color);
EXPORT_FUNC_C(void, OSScreenPutFontEx, int bufferId, u32 x, u32 y, const char* str);

EXPORT_FUNC_C(void, OSInitSemaphore, OSSemaphore* sem, s32 count);
EXPORT_FUNC_C(void, OSInitSemaphoreEx, OSSemaphore* sem, s32 count, char* name);
EXPORT_FUNC_C(s32, OSWaitSemaphore, OSSemaphore* sem);
EXPORT_FUNC_C(s32, OSTryWaitSemaphore, OSSemaphore* sem);
EXPORT_FUNC_C(s32, OSSignalSemaphore, OSSemaphore* sem);
EXPORT_FUNC_C(s32, OSGetSemaphoreCount, OSSemaphore* sem);

EXPORT_FUNC_C(void, OSInitSpinLock, OSSpinLock* spinlock);
EXPORT_FUNC_C(bool, OSAcquireSpinLock, OSSpinLock* spinlock);
EXPORT_FUNC_C(bool, OSTryAcquireSpinLock, OSSpinLock* spinlock);
EXPORT_FUNC_C(bool, OSTryAcquireSpinLockWithTimeout, OSSpinLock* spinlock, OSTime timeout);
EXPORT_FUNC_C(bool, OSReleaseSpinLock, OSSpinLock* spinlock);

EXPORT_FUNC_C(bool, OSUninterruptibleSpinLock_Acquire, OSSpinLock* inSpinlock);
EXPORT_FUNC_C(bool, OSUninterruptibleSpinLock_TryAcquire, OSSpinLock* inSpinLock);
EXPORT_FUNC_C(bool, OSUninterruptibleSpinLock_TryAcquireWithTimeout, OSSpinLock* inSpinLock, OSTime timeout);
EXPORT_FUNC_C(bool, OSUninterruptibleSpinLock_Release, OSSpinLock* inSpinlock);

EXPORT_FUNC_C(void, OSLogBuffer, OSLogCategory category, OSLogLevel level, OSLogDataOpt options, void* pBuffer, size_t size);
EXPORT_FUNC_C(void, OSLogArgs, OSLogCategory category, OSLogLevel level, OSLogDataOpt options, u32 seqByte, u32 arg0, u32 arg1, u32 arg2, u32 arg3);
EXPORT_FUNC_C(void, OSLogFunc, OSLogCategory category, OSLogLevel level, OSLogDataOpt options, const char* funcName, u32 funcNameSize, u32 lineNumber, u32* argv, u32 argc);
EXPORT_FUNC_C(void, OSLogPrintf, OSLogCategory category, OSLogLevel level, OSLogDataOpt options, const char* fmt, ...);
EXPORT_FUNC_C(void, OSLogSetFilterPolicy, OSLogCategory category, OSLogLevel minimumLevel);
EXPORT_FUNC_C(bool, OSLogReport, OSLogRetrievalOpt retrievalOptions, void* pWorkspace, u32 workSpaceSize);
EXPORT_FUNC_C(bool, OSLogRetrieve, OSLogRetrievalOpt retrievalOptions, OSLogRetrieval* pRetrieval, u32 maxRetrievedSize);
EXPORT_FUNC_C(bool, OSLogSaveCrashDump, void);

EXPORT_FUNC_C(void, __OSBoostThreadPriority, OSThread* currentThread);
EXPORT_FUNC_C(void, __OSDeboostThreadPrioriy, OSThread* currentThread);

EXPORT_FUNC_C(void, __OSGetAppCrashControl, OSCrashControl* cntl);
EXPORT_FUNC_C(void, __OSSetAppCrashControl, OSCrashControl* cntl);
EXPORT_FUNC_C(void, __OSClearAppCrash, void);

EXPORT_FUNC_C(void, __OSSetTestSetting, const char* name, u32 value);
EXPORT_FUNC_C(u32, __OSGetTestSetting, const char* name);

EXPORT_FUNC_C(u32, __OSSetLaunchTimeout, u32 timeoutMs);

EXPORT_FUNC_C(void, PMBegin, void);
EXPORT_FUNC_C(void, PMEnd, void);
EXPORT_FUNC_C(u32, PMCycles, void);
EXPORT_FUNC_C(u32, PML1FetchMisses, void);
EXPORT_FUNC_C(u32, PML1MissCycles, void);
EXPORT_FUNC_C(u32, PMInstructions, void);

EXPORT_FUNC_C(u32, PPCMfmsr, void);
EXPORT_FUNC_C(void, PPCMtmsr, u32 newMSR);
EXPORT_FUNC_C(u32, PPCOrMsr, u32 value);
EXPORT_FUNC_C(u32, PPCAndMsr, u32 value);
EXPORT_FUNC_C(u32, PPCAndCMsr, u32 value);

EXPORT_FUNC_C(u32, PPCMfhid0, void);
EXPORT_FUNC_C(void, PPCMthid0, u32 newHID0);

EXPORT_FUNC_C(u32, PPCMfhid1, void);

EXPORT_FUNC_C(u32, PPCMfhid2, void);
EXPORT_FUNC_C(void, PPCMthid2, u32 newHID2);

EXPORT_FUNC_C(u32, PPCMfwpar, void);
EXPORT_FUNC_C(void, PPCMtwpar, u32 newWpar);

EXPORT_FUNC_C(u32, PPCMfdmaU, void);
EXPORT_FUNC_C(u32, PPCMfdmaL, void);

EXPORT_FUNC_C(void, PPCMtdmaU, u32 newDmau);
EXPORT_FUNC_C(void, PPCMtdmaL, u32 newDmal);

EXPORT_FUNC_C(u32, PPCMfl2cr, void);
EXPORT_FUNC_C(void, PPCMtl2cr, u32 newL2cr);

EXPORT_FUNC_C(void, PPCMtdec, u32 newDec);
EXPORT_FUNC_C(u32, PPCMfdec, void);

EXPORT_FUNC_C(void, PPCSync, void);
EXPORT_FUNC_C(void, PPCEieio, void);

EXPORT_FUNC_C(void, PPCHalt, char* msg, u32 size);
EXPORT_FUNC_C(void, PPCIsync, void);

EXPORT_FUNC_C(u32, PPCMfmmcr0, void);
EXPORT_FUNC_C(void, PPCMtmmcr0, u32 newMmcr0);
EXPORT_FUNC_C(u32, PPCMfmmcr1, void);
EXPORT_FUNC_C(void, PPCMtmmcr1, u32 newMmcr1);
EXPORT_FUNC_C(u32, PPCMfpmc1, void);
EXPORT_FUNC_C(void, PPCMtpmc1, u32 newPmc1);
EXPORT_FUNC_C(u32, PPCMfpmc2, void);
EXPORT_FUNC_C(void, PPCMtpmc2, u32 newPmc2);
EXPORT_FUNC_C(u32, PPCMfpmc3, void);
EXPORT_FUNC_C(void, PPCMtpmc3, u32 newPmc3);
EXPORT_FUNC_C(u32, PPCMfpmc4, void);
EXPORT_FUNC_C(void, PPCMtpmc4, u32 newPmc4);
EXPORT_FUNC_C(u32, PPCMfsia, void);
EXPORT_FUNC_C(void, PPCMtsia, u32 newSia);

EXPORT_FUNC_C(u32, PPCMfpvr, void);

EXPORT_FUNC_C(u32, PPCMffpscr, void);
EXPORT_FUNC_C(void, PPCMtfpscr, u32 newFPSCR);

EXPORT_FUNC_C(void, PPCEnableSpeculation, void);
EXPORT_FUNC_C(void, PPCDisableSpeculation, void);

EXPORT_FUNC_C(void, PPCSetFpIEEEMode, void);
EXPORT_FUNC_C(void, PPCSetFpNonIEEEMode, void);

EXPORT_FUNC_C(u32, PPCMfhid4, void);
EXPORT_FUNC_C(void, PPCMthid4, register u32 newHID4);

EXPORT_FUNC_C(u32, PPCMfpir, void);
EXPORT_FUNC_C(u32, PPCMfsprg0, void);

EXPORT_FUNC_C(void, __PPCHalt, void);
EXPORT_FUNC_C(void, __PPCExit, int result);

EXPORT_FUNC_C(CAMHandle, CAMInit, CAMInstance instance, CAMSetupInfo* setup, CAMError* err);
EXPORT_FUNC_C(void, CAMExit, CAMHandle cam);
EXPORT_FUNC_C(CAMError, CAMOpen, CAMHandle cam);
EXPORT_FUNC_C(CAMError, CAMClose, CAMHandle cam);
EXPORT_FUNC_C(CAMError, CAMGetMemReq, CAMStreamInfo* streamInfo);
EXPORT_FUNC_C(CAMError, CAMSubmitTargetSurface, CAMHandle cam, CAMSurface* surface);
EXPORT_FUNC_C(CAMError, CAMGetState, CAMHandle cam, CAMState state, int* val);
EXPORT_FUNC_C(CAMError, CAMGetStateInfo, CAMHandle cam, CAMState state, CAMStateInfo* info);
EXPORT_FUNC_C(CAMError, CAMSetState, CAMHandle cam, CAMState state, int* val);
EXPORT_FUNC_C(CAMError, CAMCheckMemSegmentation, void* mem, unsigned int size);

EXPORT_FUNC_C(bool, DMAEWaitDone, DMAETimeStamp ts);
EXPORT_FUNC_C(DMAETimeStamp, DMAEGetLastSubmittedTimeStamp, void);
EXPORT_FUNC_C(DMAETimeStamp, DMAEGetRetiredTimeStamp, void);
EXPORT_FUNC_C(DMAETimeStamp, DMAESemaphore, u64* semaphoreAddr, DMAESemaphoreAction semaphoreAction);
EXPORT_FUNC_C(DMAETimeStamp, DMAECopyMem, void* dst, const void* src, u32 sizeInU32s, DMAEEndian endian);
EXPORT_FUNC_C(DMAETimeStamp, DMAEFillMem, void* dst, u32 fillData, u32 sizeInU32s);
EXPORT_FUNC_C(DMAETimeStamp, DMAEFillMemPhys, u32 dstPA, u32 fillData, u32 sizeInU32s);
EXPORT_FUNC_C(void, DMAESetTimeout, u32 millisec);
EXPORT_FUNC_C(u32, DMAEGetTimeout, void);

EXPORT_FUNC_C(GX2TVScanMode, GX2GetSystemTVScanMode, void);
EXPORT_FUNC_C(GX2AspectRatio, GX2GetSystemTVAspectRatio, void);
EXPORT_FUNC_C(bool, GX2IsVideoOutReady, void);
EXPORT_FUNC_C(GX2DRCMode, GX2GetSystemDRCMode, void);
EXPORT_FUNC_C(GX2DRCMode, GX2GetSystemDRCScanMode, void);
EXPORT_FUNC_C(GX2DRCConnectCB, GX2SetDRCConnectCallback, s32 chan, GX2DRCConnectCB callback);
EXPORT_FUNC_C(void, GX2GetDRCVerticalInfo, u32* vCount, u32* vPhase);
EXPORT_FUNC_C(void, GX2CalcTVSize, GX2TVRenderMode tvRenderMode, GX2SurfaceFormat fmt, GX2BufferingMode bufferingMode, u32* size, bool* scaleNeeded);
EXPORT_FUNC_C(void, GX2CalcDRCSize, GX2DRCMode mode, GX2SurfaceFormat fmt, GX2BufferingMode bufferingMode, u32* size, bool* scaleNeeded);
EXPORT_FUNC_C(void, GX2SetTVBuffer, void* buffer, u32 size, GX2TVRenderMode tvRenderMode, GX2SurfaceFormat fmt, GX2BufferingMode bufferingMode);
EXPORT_FUNC_C(void, GX2SetDRCBuffer, void* buffer, u32 size, GX2DRCMode mode, GX2SurfaceFormat fmt, GX2BufferingMode bufferingMode);
EXPORT_FUNC_C(void, GX2SetTVScale, u32 actualWidth, u32 actualHeight);
EXPORT_FUNC_C(void, GX2SetDRCScale, u32 actualWidth, u32 actualHeight);
EXPORT_FUNC_C(void, GX2SetTVGamma, f32 gamma);
EXPORT_FUNC_C(void, GX2GetTVGamma, f32* gamma);
EXPORT_FUNC_C(void, GX2GetTVGammaEx, f32* gamma);
EXPORT_FUNC_C(void, GX2GetDRCGamma, f32* gamma);
EXPORT_FUNC_C(void, GX2GetDRCGammaEx, f32* gamma);
EXPORT_FUNC_C(void, GX2SetDRCGamma, f32 gamma);
EXPORT_FUNC_C(void, GX2SetTVEnable, bool enable);
EXPORT_FUNC_C(void, GX2SetDRCEnable, bool enable);
EXPORT_FUNC_C(void, GX2CopyColorBufferToScanBuffer, const GX2ColorBuffer* renderBuffer, GX2ScanTarget target);
EXPORT_FUNC_C(void, GX2SwapScanBuffers, void);
EXPORT_FUNC_C(void, GX2GetSwapStatus, u32* swapCount, u32* flipCount, OSTime* lastFlipTime, OSTime* lastVsyncTime);
EXPORT_FUNC_C(void, GX2WaitForFlip, void);
EXPORT_FUNC_C(void, GX2WaitForVsync, void);
EXPORT_FUNC_C(void, GX2SetSwapInterval, u32 swapInterval);
EXPORT_FUNC_C(u32, GX2GetSwapInterval, void);
EXPORT_FUNC_C(bool, GX2SetVideoEncodingHint, GX2DRCEncodingHint hintBitmap, s8  motionVectorX, s8  motionVectorY);
EXPORT_FUNC_C(bool, GX2GetLastFrame, GX2ScanTarget target, GX2Texture* texture);
EXPORT_FUNC_C(bool, GX2GetLastFrameGamma, GX2ScanTarget target, f32* gamma);

EXPORT_FUNC_C(void, GX2ClearColor, GX2ColorBuffer* colorBuffer, f32 r, f32 g, f32 b, f32 a);
EXPORT_FUNC_C(void, GX2ClearDepthStencilEx, GX2DepthBuffer* depthBuffer, f32 depthValue, u8 stencilValue, GX2ClearMode clearFlags);
EXPORT_FUNC_C(void, GX2ClearBuffersEx, GX2ColorBuffer* colorBuffer, GX2DepthBuffer* depthBuffer, f32 r, f32 g, f32 b, f32 a, f32 depthValue, u8 stencilValue, GX2ClearMode clearFlags);
EXPORT_FUNC_C(void, GX2SetClearDepthStencil, GX2DepthBuffer* depthBuffer, f32 depthValue, u8 stencilValue);
EXPORT_FUNC_C(void, GX2SetClearDepth, GX2DepthBuffer* depthBuffer, f32 depthValue);
EXPORT_FUNC_C(void, GX2SetClearStencil, GX2DepthBuffer* depthBuffer, u8 stencilValue);
EXPORT_FUNC_C(void, GX2SetAttribBuffer, u32 index, u32 size, u32 stride, const void* ptr);
EXPORT_FUNC_C(void, GX2SetPrimitiveRestartIndex, u32 index);
EXPORT_FUNC_C(void, GX2DrawIndexedEx, GX2PrimitiveType mode, u32 count, GX2IndexFormat indexFormat, const void* indices, u32 baseVertex, u32 numInstances);
EXPORT_FUNC_C(void, GX2DrawIndexedEx2, GX2PrimitiveType mode, u32 count, GX2IndexFormat indexFormat, const void* indices, u32 baseVertex, u32 numInstances, u32 baseInstance);
EXPORT_FUNC_C(void, GX2DrawIndexedImmediateEx, GX2PrimitiveType mode, u32 count, GX2IndexFormat indexFormat, const void* indices, u32 baseVertex, u32 numInstances);
EXPORT_FUNC_C(void, GX2DrawEx, GX2PrimitiveType mode, u32 count, u32 firstVertex, u32 numInstances);
EXPORT_FUNC_C(void, GX2DrawEx2, GX2PrimitiveType mode, u32 count, u32 firstVertex, u32 numInstances, u32 baseInstance);
EXPORT_FUNC_C(void, GX2DrawStreamOut, GX2PrimitiveType mode, const GX2StreamOutBuffer* streamOutBuf);
EXPORT_FUNC_C(void, GX2DispatchCompute, GX2DispatchParams* dispatchParams);

EXPORT_FUNC_C(void, GX2Init, GX2InitAttrib* initAttribs);
EXPORT_FUNC_C(void, GX2Shutdown, void);
EXPORT_FUNC_C(s32, GX2GetMainCoreId, void);
EXPORT_FUNC_C(void, GX2Flush, void);
EXPORT_FUNC_C(bool, GX2DrawDone, void);
EXPORT_FUNC_C(u64, GX2GetLastSubmittedTimeStamp, void);
EXPORT_FUNC_C(u64, GX2GetRetiredTimeStamp, void);
EXPORT_FUNC_C(bool, GX2WaitTimeStamp, u64 ts);
EXPORT_FUNC_C(void, GX2SetEventCallback, GX2CallbackEvent event, GX2CallbackFunction functionPtr, void* userDataPtr);
EXPORT_FUNC_C(void, GX2GetEventCallback, GX2CallbackEvent event, GX2CallbackFunction* functionPtr, void** userDataPtr);
EXPORT_FUNC_C(void, GX2SubmitUserTimeStamp, u64* tsBuffer, u64 timeStampValue, GX2PipeEvent when, bool triggerIntCB);
EXPORT_FUNC_C(void, GX2SetGPUFence, u32* fencePtr, u32 fenceMask, GX2CompareFunction op, u32 fenceValue);
EXPORT_FUNC_C(void*, GX2BeginGPUTask, void);
EXPORT_FUNC_C(void, GX2EndGPUTask, u32* fencePtr);
EXPORT_FUNC_C(void, GX2InsertGPUTask, u32* dlPatchLoc, u32* displayList, u32 byteSize);
EXPORT_FUNC_C(void, GX2SetSemaphore, u64* semaphoreAddr, GX2SemaphoreAction semaphoreAction);
EXPORT_FUNC_C(bool, GX2SetMiscParam, GX2MiscType param, u32 value);
EXPORT_FUNC_C(u32, GX2GetMiscParam, GX2MiscType param);
EXPORT_FUNC_C(void, GX2ResetGPU, u32 reserved);
EXPORT_FUNC_C(void, GX2BeginDisplayListEx, void* displayList, u32 byteSize, bool enableProfiling);
EXPORT_FUNC_C(u32, GX2EndDisplayList, void* displayList);
EXPORT_FUNC_C(void, GX2DirectCallDisplayList, void* displayList, u32 byteSize);
EXPORT_FUNC_C(void, GX2CallDisplayList, void* displayList, u32 byteSize);
EXPORT_FUNC_C(bool, GX2GetDisplayListWriteStatus, void);
EXPORT_FUNC_C(bool, GX2GetCurrentDisplayList, void** displayList, u32* byteSizeMax);
EXPORT_FUNC_C(void, GX2CopyDisplayList, void* displayList, u32 byteSize);

EXPORT_FUNC_C(void, GX2SetDefaultAllocator, GX2DefaultAllocateFunc alloc, GX2DefaultFreeFunc free);
EXPORT_FUNC_C(void, GX2GetDefaultAllocator, GX2DefaultAllocateFunc* alloc, GX2DefaultFreeFunc* free);
EXPORT_FUNC_C(void, GX2NotifyMemAlloc, void* addr, u32 size, u32 align);
EXPORT_FUNC_C(void, GX2NotifyMemFree, void* addr);
EXPORT_FUNC_C(void, GX2Invalidate, GX2InvalidateType invType, void* ptr, u32 size);
EXPORT_FUNC_C(void, GX2SetDebugMode, GX2DebugMode mode);
EXPORT_FUNC_C(void, GX2SetGPUTimeout, u32 millisec);
EXPORT_FUNC_C(u32, GX2GetGPUTimeout, void);
EXPORT_FUNC_C(void, GX2SetInterruptCountLimit, u32 limit);
EXPORT_FUNC_C(void, GX2PrintGPUStatus, void);
EXPORT_FUNC_C(void, GX2LogSetMisc, GX2LogAttrib attrib, u32 value);
EXPORT_FUNC_C(void, GX2DebugTagUserString, GX2DebugTagUserStringType userTagType, const char* formatString, ...);
EXPORT_FUNC_C(void, GX2DebugTagUserStringVA, GX2DebugTagUserStringType userTagType, const char* formatString, va_list args);
EXPORT_FUNC_C(void, GX2DebugCaptureFrame, const char* filename);
EXPORT_FUNC_C(void, GX2DebugCaptureFrames, const char* filename, u32 numFrames);
EXPORT_FUNC_C(void, GX2DebugCaptureStart, const char* filename, GX2DebugCaptureOptions optionFlags);
EXPORT_FUNC_C(void, GX2DebugCaptureEnd, GX2DebugCaptureOptions optionFlags);
EXPORT_FUNC_C(void, GX2SetDefaultState, void);
EXPORT_FUNC_C(void, GX2SetupContextStateEx, GX2ContextState* state, bool enableProfiling);
EXPORT_FUNC_C(void, GX2SetContextState, const GX2ContextState* state);
EXPORT_FUNC_C(void, GX2GetContextStateDisplayList, const GX2ContextState* state, void** displayList, u32* byteSize);
EXPORT_FUNC_C(void, GX2PatchDisplayList, void* displayList, GX2PatchType type, u32 offset, void* gx2ObjectPointer);

EXPORT_FUNC_C(GX2PerfMetricType, GX2GetPerfMetricType, GX2PerfMetric metric);
EXPORT_FUNC_C(void, GX2PerfInit, GX2PerfData* perfData, u32 maxTags, MEMAllocator* allocator);
EXPORT_FUNC_C(void, GX2PerfFree, GX2PerfData* perfData);
EXPORT_FUNC_C(void, GX2PerfSetCollectionMethod, GX2PerfData* perfData, GX2PerfCollectionMethod method);
EXPORT_FUNC_C(GX2PerfCollectionMethod, GX2PerfGetCollectionMethod, GX2PerfData* perfData);
EXPORT_FUNC_C(void, GX2PerfMetricsClear, GX2PerfData* perfData);
EXPORT_FUNC_C(bool, GX2PerfMetricEnable, GX2PerfData* perfData, GX2PerfType type, u32 id);
EXPORT_FUNC_C(bool, GX2PerfMetricIsEnabled, GX2PerfData* perfData, GX2PerfType type, u32 metricId);
EXPORT_FUNC_C(bool, GX2PerfMetricGetEnabled, GX2PerfData* perfData, u32 index, GX2PerfType* type, u32* metricId);
EXPORT_FUNC_C(void, GX2PerfTagEnable, GX2PerfData* perfData, u32 tag, bool enable);
EXPORT_FUNC_C(void, GX2PerfTagEnableAll, GX2PerfData* perfData);
EXPORT_FUNC_C(void, GX2PerfTagDisableAll, GX2PerfData* perfData);
EXPORT_FUNC_C(bool, GX2PerfTagIsEnabled, GX2PerfData* perfData, u32 tag);
EXPORT_FUNC_C(void, GX2PerfFrameStart, GX2PerfData* perfData);
EXPORT_FUNC_C(void, GX2PerfFrameEnd, GX2PerfData* perfData);
EXPORT_FUNC_C(u32, GX2PerfGetNumPasses, GX2PerfData* perfData);
EXPORT_FUNC_C(void, GX2PerfPassStart, GX2PerfData* perfData);
EXPORT_FUNC_C(void, GX2PerfPassEnd, GX2PerfData* perfData);
EXPORT_FUNC_C(void, GX2PerfTagStart, GX2PerfData* perfData, u32 tag);
EXPORT_FUNC_C(void, GX2PerfTagEnd, GX2PerfData* perfData, u32 tag);
EXPORT_FUNC_C(bool, GX2PerfGetResultByFrame, GX2PerfData* perfData, GX2PerfType type, u32 id, GX2MetricResult* result);
EXPORT_FUNC_C(bool, GX2PerfGetResultByTagId, GX2PerfData* perfData, GX2PerfType type, u32 id, u32 tag, u32 number, GX2MetricResult* result);
EXPORT_FUNC_C(bool, GX2PerfGetResultByTagSequence, GX2PerfData* perfData, GX2PerfType type, u32 id, u32 sequence, u32* tag, u32* number, u32* depth, GX2MetricResult* result);
EXPORT_FUNC_C(void, GX2PerfPrintFrameResults, GX2PerfData* perfData);
EXPORT_FUNC_C(void, GX2PerfPrintTagResults, GX2PerfData* perfData, GX2PerfTag2StringFunc func);
EXPORT_FUNC_C(void, GX2PerfSetPassCoherEnable, GX2PerfData* perfData, bool enable);
EXPORT_FUNC_C(bool, GX2PerfGetPassCoherEnable, GX2PerfData* perfData);

EXPORT_FUNC_C(void, _GX2InitCounterInfo, _GX2CounterInfo* info, GX2CounterId id, GX2StatId parm);
EXPORT_FUNC_C(void, _GX2SetCounterInfo, const _GX2CounterInfo* info);
EXPORT_FUNC_C(void, _GX2ResetCounters, void);
EXPORT_FUNC_C(void, _GX2StartCounters, const _GX2CounterInfo* info);
EXPORT_FUNC_C(void, _GX2StopCounters, const _GX2CounterInfo* info);
EXPORT_FUNC_C(void, _GX2SampleCounters, _GX2CounterInfo* info);
EXPORT_FUNC_C(bool, GX2InitPerfMetric, GX2PerfInfo* perfInfo, GX2PerfMetric metric);
EXPORT_FUNC_C(void, GX2GetPerfMetricU64, const GX2PerfInfo* perfInfo, GX2PerfMetric metric, u64* result);
EXPORT_FUNC_C(void, GX2GetPerfMetricF32, const GX2PerfInfo* perfInfo, GX2PerfMetric metric, f32* result);

EXPORT_FUNC_C(u32, GX2GetGPUSystemClock, void);
EXPORT_FUNC_C(void, GX2ResetCounterInfo, GX2CounterInfo* info);
EXPORT_FUNC_C(bool, GX2InitCounterInfo, GX2CounterInfo* info, GX2CounterId cid, GX2StatId sid);
EXPORT_FUNC_C(bool, GX2GetCounterSetting, GX2CounterInfo* info, GX2CounterId cid, GX2StatId* sid);
EXPORT_FUNC_C(u32, GX2GetCounterResultSize, GX2CounterInfo* info);
EXPORT_FUNC_C(void, GX2SetCounterInfo, const GX2CounterInfo* info);
EXPORT_FUNC_C(void, GX2SampleCountersEx, GX2CounterInfo* info, u64* alignedResultBuffer);
EXPORT_FUNC_C(void, GX2SampleCounters, GX2CounterInfo* info);
EXPORT_FUNC_C(u64, GX2GetCounterResultEx, GX2CounterInfo* info, u64* alignedResultBuffer, GX2StatId sid);
EXPORT_FUNC_C(u64, GX2GetCounterResult, GX2CounterInfo* info, GX2StatId sid);
EXPORT_FUNC_C(void, GX2StopCounters, const GX2CounterInfo* info);
EXPORT_FUNC_C(void, GX2StartCounters, const GX2CounterInfo* info);
EXPORT_FUNC_C(void, GX2ResetCounters, const GX2CounterInfo* info);

EXPORT_FUNC_C(void, GX2SampleTopGPUCycle, u64* addr);
EXPORT_FUNC_C(void, GX2SampleBottomGPUCycle, u64* addr);
EXPORT_FUNC_C(u64, GX2CPUTimeToGPUTime, u64 cpuTime);
EXPORT_FUNC_C(u64, GX2GPUTimeToCPUTime, u64 gpuTime);
EXPORT_FUNC_C(void, GX2QueryBegin, GX2QueryType type, GX2QueryInfo* queryInfo);
EXPORT_FUNC_C(void, GX2QueryEnd, GX2QueryType type, GX2QueryInfo* queryInfo);
EXPORT_FUNC_C(bool, GX2QueryGetOcclusionResult, const GX2QueryInfo* queryInfo, u64* zPass);
EXPORT_FUNC_C(bool, GX2QueryGetStreamOutStatsResult, const GX2QueryInfo* queryInfo, GX2StreamOutStats* stats);
EXPORT_FUNC_C(void, GX2QueryBeginConditionalRender, GX2QueryType type, const GX2QueryInfo* queryInfo, bool hint, bool predicate);
EXPORT_FUNC_C(void, GX2QueryEndConditionalRender, void);

EXPORT_FUNC_C(void, GX2RDestroyBufferEx, GX2RBuffer* gx2Buffer, GX2RResourceFlags optionFlags);
EXPORT_FUNC_C(void*, GX2RLockBufferEx, const GX2RBuffer* gx2Buffer, GX2RResourceFlags optionFlags);
EXPORT_FUNC_C(void*, GX2RLockBufferRegionEx, const GX2RBuffer* gx2Buffer, u32 byteOffset, u32 byteCount, GX2RResourceFlags optionFlags);
EXPORT_FUNC_C(void, GX2RUnlockBufferEx, const GX2RBuffer* gx2Buffer, GX2RResourceFlags optionFlags);
EXPORT_FUNC_C(bool, GX2RCreateBuffer, GX2RBuffer* gx2Buffer);
EXPORT_FUNC_C(bool, GX2RCreateBufferUserMemory, GX2RBuffer* gx2Buffer, void* userMem, u32 userByteCount);
EXPORT_FUNC_C(bool, GX2RBufferExists, const GX2RBuffer* gx2Buffer);
EXPORT_FUNC_C(void, GX2RSetBufferName, GX2RBuffer* gx2Buffer, const char* name);
EXPORT_FUNC_C(const char*, GX2RGetBufferName, const GX2RBuffer* gx2Buffer);
EXPORT_FUNC_C(void, GX2RSetAttributeBuffer, const GX2RBuffer* vertexBuffer, u32 slot, u32 stride, u32 byteOffset);
EXPORT_FUNC_C(void, GX2RSetVertexUniformBlock, const GX2RBuffer* uniformBlock, u32 location, u32 byteOffset);
EXPORT_FUNC_C(void, GX2RSetGeometryUniformBlock, const GX2RBuffer* uniformBlock, u32 location, u32 byteOffset);
EXPORT_FUNC_C(void, GX2RSetPixelUniformBlock, const GX2RBuffer* uniformBlock, u32 location, u32 byteOffset);
EXPORT_FUNC_C(void, GX2RSetStreamOutBuffer, u32 soTarget, const GX2StreamOutBuffer* streamOutBuffer);
EXPORT_FUNC_C(void, GX2RDrawIndexed, GX2PrimitiveType primitiveType, const GX2RBuffer* indexBuffer, GX2IndexFormat indexFormat, u32 indexCount, u32 startIndex, u32 startVertex, u32 numInstances);
EXPORT_FUNC_C(void, GX2RDrawIndexedImmediate, GX2PrimitiveType primitiveType, const GX2RBuffer* indexBuffer, GX2IndexFormat indexFormat, u32 indexCount, u32 startIndex, u32 startVertex, u32 numInstances);
EXPORT_FUNC_C(void, GX2RBeginDisplayListEx, const GX2RBuffer* displayList, bool enableProfiling, GX2RResourceFlags optionFlags);
EXPORT_FUNC_C(u32, GX2REndDisplayList, const GX2RBuffer* displayList);
EXPORT_FUNC_C(void, GX2RCallDisplayList, const GX2RBuffer* displayList, u32 byteSize);
EXPORT_FUNC_C(void, GX2RDirectCallDisplayList, const GX2RBuffer* displayList, u32 byteSize);
EXPORT_FUNC_C(void, GX2RSetGeometryShaderInputRingBuffer, const GX2RBuffer* ringInBuffer);
EXPORT_FUNC_C(void, GX2RSetGeometryShaderOutputRingBuffer, const GX2RBuffer* ringOutBuffer);
EXPORT_FUNC_C(void, GX2RInitFetchShader, GX2FetchShader* fetchShader, const GX2RBuffer* shaderProgram, u32 attribCount, const GX2AttribStream* attribStreams, GX2FetchShaderType type, GX2TessellationMode tessMode);
EXPORT_FUNC_C(u32, GX2RGetBufferAlignment, GX2RResourceFlags resourceFlags);
EXPORT_FUNC_C(u32, GX2RGetBufferAllocationSize, const GX2RBuffer* gx2Buffer);
EXPORT_FUNC_C(void, GX2RInvalidateMemory, GX2RResourceFlags resourceFlags, void* mem, u32 byteCount);
EXPORT_FUNC_C(void, GX2RInvalidateBuffer, const GX2RBuffer* gx2Buffer, GX2RResourceFlags optionFlags);
EXPORT_FUNC_C(u32, GX2RGetBufferGuardBandSize, GX2RResourceFlags resourceFlags);

EXPORT_FUNC_C(void, GX2SetDepthStencilControl, bool depthEnable, bool depthWriteEnable, GX2CompareFunction depthFunc, bool stencilTestEnable, bool backStencilEnable, GX2CompareFunction frontStencilFunc, GX2StencilFunction frontStencilZPass, GX2StencilFunction frontStencilZFail, GX2StencilFunction frontStencilFail, GX2CompareFunction backStencilFunc, GX2StencilFunction backStencilZPass, GX2StencilFunction backStencilZFail, GX2StencilFunction backStencilFail);
EXPORT_FUNC_C(void, GX2SetDepthOnlyControl, bool depthEnable, bool depthWriteEnable, GX2CompareFunction depthFunc);
EXPORT_FUNC_C(void, GX2SetPolygonControl, GX2FrontFaceMode frontFaceMode, bool cullFront, bool cullBack, bool enablePolygonModes, GX2PolygonMode polygonModeFront, GX2PolygonMode polygonModeBack, bool polyOffsetFrontEnable, bool polyOffsetBackEnable, bool pointLineOffsetEnable);
EXPORT_FUNC_C(void, GX2SetCullOnlyControl, GX2FrontFaceMode frontFaceMode, bool cullFront, bool cullBack);
EXPORT_FUNC_C(void, GX2SetStencilMask, u8 preMaskFront, u8 writeMaskFront, u8 refFront, u8 preMaskBack, u8 writeMaskBack, u8 refBack);
EXPORT_FUNC_C(void, GX2SetSpecialState, GX2SpecialState state, bool enable);
EXPORT_FUNC_C(void, GX2SetAlphaTest, bool alphaTestEnable, GX2CompareFunction alphaFunc, f32 ref);
EXPORT_FUNC_C(void, GX2SetAlphaToMask, bool alphaToMaskEnable, GX2AlphaToMaskMode mode);
EXPORT_FUNC_C(void, GX2SetPolygonOffset, f32 frontOffset, f32 frontSlopeScale, f32 backOffset, f32 backSlopeScale, f32 clamp);
EXPORT_FUNC_C(void, GX2SetTargetChannelMasks, GX2ChannelMask target0, GX2ChannelMask target1, GX2ChannelMask target2, GX2ChannelMask target3, GX2ChannelMask target4, GX2ChannelMask target5, GX2ChannelMask target6, GX2ChannelMask target7);
EXPORT_FUNC_C(void, GX2SetAAMask, u8 upperLeftMask, u8 upperRightMask, u8 lowerLeftMask, u8 lowerRightMask);
EXPORT_FUNC_C(void, GX2SetColorControl, GX2LogicOp lop, u8 blendEnableMask, bool multiwriteEnable, bool colorBufferEnable);
EXPORT_FUNC_C(void, GX2SetBlendControl, GX2RenderTarget target, GX2BlendFunction colorSrcBlend, GX2BlendFunction colorDstBlend, GX2BlendCombine colorCombine, bool separateAlphaBlend, GX2BlendFunction alphaSrcBlend, GX2BlendFunction alphaDstBlend, GX2BlendCombine alphaCombine);
EXPORT_FUNC_C(void, GX2SetBlendConstantColor, f32 red, f32 green, f32 blue, f32 alpha);
EXPORT_FUNC_C(void, GX2SetPointSize, f32 width, f32 height);
EXPORT_FUNC_C(void, GX2SetPointLimits, f32 min, f32 max);
EXPORT_FUNC_C(void, GX2SetLineWidth, f32 width);
EXPORT_FUNC_C(void, GX2SetViewport, f32 xOrig, f32 yOrig, f32 wd, f32 ht, f32 nearZ, f32 farZ);
EXPORT_FUNC_C(void, GX2SetScissor, u32 xOrig, u32 yOrig, u32 wd, u32 ht);
EXPORT_FUNC_C(void, GX2SetRasterizerClipControl, bool rasterizerEnable, bool zClipEnable);
EXPORT_FUNC_C(void, GX2SetRasterizerClipControlEx, bool rasterizerEnable, bool zClipEnable, bool enableHalfSizeClipSpace);
EXPORT_FUNC_C(void, GX2SetRasterizerClipControlHalfZ, bool rasterizerEnable, bool zClipEnable, bool enableHalfSizeClipSpace);

EXPORT_FUNC_C(void, GX2InitDepthStencilControlReg, GX2DepthStencilControlReg* state, bool depthEnable, bool depthWriteEnable, GX2CompareFunction depthFunc, bool stencilTestEnable, bool backStencilEnable, GX2CompareFunction frontStencilFunc, GX2StencilFunction frontStencilZPass, GX2StencilFunction frontStencilZFail, GX2StencilFunction frontStencilFail, GX2CompareFunction backStencilFunc, GX2StencilFunction backStencilZPass, GX2StencilFunction backStencilZFail, GX2StencilFunction backStencilFail);
EXPORT_FUNC_C(void, GX2GetDepthStencilControlReg, const GX2DepthStencilControlReg* state, bool* depthEnable, bool* depthWriteEnable, GX2CompareFunction* depthFunc, bool* stencilTestEnable, bool* backStencilEnable, GX2CompareFunction* frontStencilFunc, GX2StencilFunction* frontStencilZPass, GX2StencilFunction* frontStencilZFail, GX2StencilFunction* frontStencilFail, GX2CompareFunction* backStencilFunc, GX2StencilFunction* backStencilZPass, GX2StencilFunction* backStencilZFail, GX2StencilFunction* backStencilFail);
EXPORT_FUNC_C(void, GX2SetDepthStencilControlReg, const GX2DepthStencilControlReg* state);
EXPORT_FUNC_C(void, GX2InitPolygonControlReg, GX2PolygonControlReg* state, GX2FrontFaceMode frontFaceMode, bool cullFront, bool cullBack, bool enablePolygonModes, GX2PolygonMode polygonModeFront, GX2PolygonMode polygonModeBack, bool polyOffsetFrontEnable, bool polyOffsetBackEnable, bool pointLineOffsetEnable);
EXPORT_FUNC_C(void, GX2GetPolygonControlReg, const GX2PolygonControlReg* state, GX2FrontFaceMode* frontFaceMode, bool* cullFront, bool* cullBack, bool* enablePolygonModes, GX2PolygonMode* polygonModeFront, GX2PolygonMode* polygonModeBack, bool* polyOffsetFrontEnable, bool* polyOffsetBackEnable, bool* pointLineOffsetEnable);
EXPORT_FUNC_C(void, GX2SetPolygonControlReg, const GX2PolygonControlReg* state);
EXPORT_FUNC_C(void, GX2InitStencilMaskReg, GX2StencilMaskReg* state, u8 preMaskFront, u8 writeMaskFront, u8 refFront, u8 preMaskBack, u8 writeMaskBack, u8 refBack);
EXPORT_FUNC_C(void, GX2GetStencilMaskReg, const GX2StencilMaskReg* state, u8* preMaskFront, u8* writeMaskFront, u8* refFront, u8* preMaskBack, u8* writeMaskBack, u8* refBack);
EXPORT_FUNC_C(void, GX2SetStencilMaskReg, const GX2StencilMaskReg* state);
EXPORT_FUNC_C(void, GX2InitAlphaTestReg, GX2AlphaTestReg* state, bool alphaTestEnable, GX2CompareFunction alphaFunc, f32 ref);
EXPORT_FUNC_C(void, GX2GetAlphaTestReg, const GX2AlphaTestReg* state, bool* alphaTestEnable, GX2CompareFunction* alphaFunc, f32* ref);
EXPORT_FUNC_C(void, GX2SetAlphaTestReg, const GX2AlphaTestReg* state);
EXPORT_FUNC_C(void, GX2InitAlphaToMaskReg, GX2AlphaToMaskReg* state, bool alphaToMaskEnable, GX2AlphaToMaskMode mode);
EXPORT_FUNC_C(void, GX2GetAlphaToMaskReg, const GX2AlphaToMaskReg* state, bool* alphaToMaskEnable, GX2AlphaToMaskMode* mode);
EXPORT_FUNC_C(void, GX2SetAlphaToMaskReg, const GX2AlphaToMaskReg* state);
EXPORT_FUNC_C(void, GX2InitPolygonOffsetReg, GX2PolygonOffsetReg* state, f32 frontOffset, f32 frontSlopeScale, f32 backOffset, f32 backSlopeScale, f32 clamp);
EXPORT_FUNC_C(void, GX2GetPolygonOffsetReg, const GX2PolygonOffsetReg* state, f32* frontOffset, f32* frontSlopeScale, f32* backOffset, f32* backSlopeScale, f32* clamp);
EXPORT_FUNC_C(void, GX2SetPolygonOffsetReg, const GX2PolygonOffsetReg* state);
EXPORT_FUNC_C(void, GX2InitTargetChannelMasksReg, GX2TargetChannelMaskReg* state, GX2ChannelMask target0, GX2ChannelMask target1, GX2ChannelMask target2, GX2ChannelMask target3, GX2ChannelMask target4, GX2ChannelMask target5, GX2ChannelMask target6, GX2ChannelMask target7);
EXPORT_FUNC_C(void, GX2GetTargetChannelMasksReg, const GX2TargetChannelMaskReg* state, GX2ChannelMask* target0, GX2ChannelMask* target1, GX2ChannelMask* target2, GX2ChannelMask* target3, GX2ChannelMask* target4, GX2ChannelMask* target5, GX2ChannelMask* target6, GX2ChannelMask* target7);
EXPORT_FUNC_C(void, GX2SetTargetChannelMasksReg, const GX2TargetChannelMaskReg* state);
EXPORT_FUNC_C(void, GX2InitAAMaskReg, GX2AAMaskReg* state, u8 upperLeftMask, u8 upperRightMask, u8 lowerLeftMask, u8 lowerRightMask);
EXPORT_FUNC_C(void, GX2GetAAMaskReg, const GX2AAMaskReg* state, u8* upperLeftMask, u8* upperRightMask, u8* lowerLeftMask, u8* lowerRightMask);
EXPORT_FUNC_C(void, GX2SetAAMaskReg, const GX2AAMaskReg* state);
EXPORT_FUNC_C(void, GX2InitColorControlReg, GX2ColorControlReg* state, GX2LogicOp lop, u8 blendEnableMask, bool multiwriteEnable, bool colorBufferEnable);
EXPORT_FUNC_C(void, GX2GetColorControlReg, const GX2ColorControlReg* state, GX2LogicOp* lop, u8* blendEnableMask, bool* multiwriteEnable, bool* colorBufferEnable);
EXPORT_FUNC_C(void, GX2SetColorControlReg, const GX2ColorControlReg* state);
EXPORT_FUNC_C(void, GX2InitBlendControlReg, GX2BlendControlReg* state, GX2RenderTarget target, GX2BlendFunction colorSrcBlend, GX2BlendFunction colorDstBlend, GX2BlendCombine colorCombine, bool separateAlphaBlend, GX2BlendFunction alphaSrcBlend, GX2BlendFunction alphaDstBlend, GX2BlendCombine alphaCombine);
EXPORT_FUNC_C(void, GX2GetBlendControlReg, const GX2BlendControlReg* state, GX2RenderTarget* target, GX2BlendFunction* colorSrcBlend, GX2BlendFunction* colorDstBlend, GX2BlendCombine* colorCombine, bool* separateAlphaBlend, GX2BlendFunction* alphaSrcBlend, GX2BlendFunction* alphaDstBlend, GX2BlendCombine* alphaCombine);
EXPORT_FUNC_C(void, GX2SetBlendControlReg, const GX2BlendControlReg* state);
EXPORT_FUNC_C(void, GX2InitBlendConstantColorReg, GX2BlendConstantColorReg* state, f32 red, f32 green, f32 blue, f32 alpha);
EXPORT_FUNC_C(void, GX2GetBlendConstantColorReg, const GX2BlendConstantColorReg* state, f32* red, f32* green, f32* blue, f32* alpha);
EXPORT_FUNC_C(void, GX2SetBlendConstantColorReg, const GX2BlendConstantColorReg* state);
EXPORT_FUNC_C(void, GX2InitPointSizeReg, GX2PointSizeReg* state, f32 width, f32 height);
EXPORT_FUNC_C(void, GX2GetPointSizeReg, const GX2PointSizeReg* state, f32* width, f32* height);
EXPORT_FUNC_C(void, GX2SetPointSizeReg, const GX2PointSizeReg* state);
EXPORT_FUNC_C(void, GX2InitPointLimitsReg, GX2PointLimitsReg* state, f32 min, f32 max);
EXPORT_FUNC_C(void, GX2GetPointLimitsReg, const GX2PointLimitsReg* state, f32* min, f32* max);
EXPORT_FUNC_C(void, GX2SetPointLimitsReg, const GX2PointLimitsReg* state);
EXPORT_FUNC_C(void, GX2InitLineWidthReg, GX2LineWidthReg* state, f32 width);
EXPORT_FUNC_C(void, GX2GetLineWidthReg, const GX2LineWidthReg* state, f32* width);
EXPORT_FUNC_C(void, GX2SetLineWidthReg, const GX2LineWidthReg* state);
EXPORT_FUNC_C(void, GX2InitViewportReg, GX2ViewportReg* state, f32 xOrig, f32 yOrig, f32 wd, f32 ht, f32 nearZ, f32 farZ);
EXPORT_FUNC_C(void, GX2GetViewportReg, const GX2ViewportReg* state, f32* xOrig, f32* yOrig, f32* wd, f32* ht, f32* nearZ, f32* farZ);
EXPORT_FUNC_C(void, GX2SetViewportReg, const GX2ViewportReg* state);
EXPORT_FUNC_C(void, GX2InitScissorReg, GX2ScissorReg* state, u32 xOrig, u32 yOrig, u32 wd, u32 ht);
EXPORT_FUNC_C(void, GX2GetScissorReg, const GX2ScissorReg* state, u32* xOrig, u32* yOrig, u32* wd, u32* ht);
EXPORT_FUNC_C(void, GX2SetScissorReg, const GX2ScissorReg* state);

EXPORT_FUNC_C(bool, GX2RIsUserMemory, GX2RResourceFlags resourceFlags);
EXPORT_FUNC_C(void, GX2RSetAllocator, GX2RAllocateFunc alloc, GX2RFreeFunc free);
EXPORT_FUNC_C(void, GX2RSetDebugOptions, GX2RDebugOptions debugOptions);
EXPORT_FUNC_C(GX2RDebugOptions, GX2RGetDebugOptions, void);

EXPORT_FUNC_C(void, GX2RDestroySurfaceEx, GX2Surface* surface, GX2RResourceFlags optionFlags);
EXPORT_FUNC_C(void*, GX2RLockSurfaceEx, const GX2Surface* surface, s32 mipLevel, GX2RResourceFlags optionFlags);
EXPORT_FUNC_C(void, GX2RUnlockSurfaceEx, const GX2Surface* surface, s32 mipLevel, GX2RResourceFlags optionFlags);
EXPORT_FUNC_C(bool, GX2RCreateSurface, GX2Surface* surface, GX2RResourceFlags resourceFlags);
EXPORT_FUNC_C(bool, GX2RCreateSurfaceUserMemory, GX2Surface* surface, void* imagePtr, void* mipPtr, GX2RResourceFlags resourceFlags);
EXPORT_FUNC_C(bool, GX2RSurfaceExists, const GX2Surface* surface);
EXPORT_FUNC_C(void, GX2RSetSurfaceName, const GX2Surface* surface, const char* name);
EXPORT_FUNC_C(const char*, GX2RGetSurfaceName, const GX2Surface* surface);
EXPORT_FUNC_C(void, GX2RInvalidateSurface, const GX2Surface* surface, s32 mipLevel, GX2RResourceFlags optionFlags);

EXPORT_FUNC_C(u32, GX2GetVertexShaderGPRs, const GX2VertexShader* shader);
EXPORT_FUNC_C(u32, GX2GetVertexShaderStackEntries, const GX2VertexShader* shader);
EXPORT_FUNC_C(u32, GX2GetGeometryShaderGPRs, const GX2GeometryShader* shader);
EXPORT_FUNC_C(u32, GX2GetGeometryShaderStackEntries, const GX2GeometryShader* shader);
EXPORT_FUNC_C(u32, GX2GetPixelShaderGPRs, const GX2PixelShader* shader);
EXPORT_FUNC_C(u32, GX2GetPixelShaderStackEntries, const GX2PixelShader* shader);
EXPORT_FUNC_C(void, GX2SetVertexUniformReg, u32 offset, u32 count, const void* values);
EXPORT_FUNC_C(void, GX2SetPixelUniformReg, u32 offset, u32 count, const void* values);
EXPORT_FUNC_C(void, GX2SetVertexUniformBlock, u32 location, u32 size, const void* addr);
EXPORT_FUNC_C(void, GX2SetGeometryUniformBlock, u32 location, u32 size, const void* addr);
EXPORT_FUNC_C(void, GX2SetPixelUniformBlock, u32 location, u32 size, const void* addr);
EXPORT_FUNC_C(void, GX2SetComputeUniformBlock, u32 location, u32 size, const void* addr);
EXPORT_FUNC_C(u32, GX2CalcFetchShaderSizeEx, u32 numAttrib, GX2FetchShaderType fsType, GX2TessellationMode tessMode);
EXPORT_FUNC_C(void, GX2InitFetchShaderEx, GX2FetchShader* fs, void* fsBuffer, u32 count, const GX2AttribStream* attribs, GX2FetchShaderType type, GX2TessellationMode tessMode);
EXPORT_FUNC_C(u32, GX2GetAttribFormatBits, GX2AttribFormat format);
EXPORT_FUNC_C(u32, GX2CalcGeometryShaderInputRingBufferSize, u32 maxVSItemSize);
EXPORT_FUNC_C(u32, GX2CalcGeometryShaderOutputRingBufferSize, u32 maxGSItemSize);
EXPORT_FUNC_C(void, GX2SetGeometryShaderInputRingBuffer, void* ringBuffer, u32 size);
EXPORT_FUNC_C(void, GX2SetGeometryShaderOutputRingBuffer, void* ringBuffer, u32 size);
EXPORT_FUNC_C(void, GX2SetShaderModeEx, GX2ShaderMode mode, u32 vsGprs, u32 vsStackSize, u32 gsGprs, u32 gsStackSize, u32 psGprs, u32 psStackSize);
EXPORT_FUNC_C(void, GX2SetFetchShader, GX2UserContext* context, const GX2FetchShader* fs);
EXPORT_FUNC_C(void, GX2SetVertexShader, GX2UserContext* context, const GX2VertexShader* vs);
EXPORT_FUNC_C(void, GX2SetGeometryShader, GX2UserContext* context, const GX2GeometryShader* gs);
EXPORT_FUNC_C(void, GX2SetPixelShader, GX2UserContext* context, const GX2PixelShader* ps);
EXPORT_FUNC_C(void, GX2SetComputeShader, GX2UserContext* context, const GX2ComputeShader* cs);
EXPORT_FUNC_C(void, GX2SetStreamOutBuffer, u32 soTarget, const GX2StreamOutBuffer* streamOutBuf);
EXPORT_FUNC_C(void, GX2SaveStreamOutContext, u32 soTarget, const GX2StreamOutBuffer* streamOutBuf);
EXPORT_FUNC_C(void, GX2SetStreamOutContext, u32 soTarget, const GX2StreamOutBuffer* streamOutBuf, bool reset);
EXPORT_FUNC_C(void, GX2SetStreamOutEnable, bool enable);
EXPORT_FUNC_C(void, GX2SetShaderExportBuffer, void* buffer, u32 size);

EXPORT_FUNC_C(void, GX2CalcSurfaceSizeAndAlignment, GX2Surface* surface);
EXPORT_FUNC_C(void, GX2CalcColorBufferAuxInfo, GX2ColorBuffer* colorBuffer, u32* size, u32* align);
EXPORT_FUNC_C(void, GX2InitColorBufferRegs, GX2ColorBuffer* colorBuffer);
EXPORT_FUNC_C(void, GX2CalcDepthBufferHiZInfo, GX2DepthBuffer* depthBuffer, u32* size, u32* align);
EXPORT_FUNC_C(void, GX2InitDepthBufferRegs, GX2DepthBuffer* depthBuffer);
EXPORT_FUNC_C(void, GX2InitDepthBufferHiZEnable, GX2DepthBuffer* depthBuffer, bool hiZEnable);
EXPORT_FUNC_C(void, GX2InitDepthBufferRangeBase, GX2DepthBuffer* depthBuffer, GX2ZRangeBase rangeBase);
EXPORT_FUNC_C(void, GX2InitHiStencilInfoRegs, GX2HiStencilInfo* hiStencilInfo);
EXPORT_FUNC_C(void, GX2SetColorBuffer, const GX2ColorBuffer* colorBuffer, GX2RenderTarget target);
EXPORT_FUNC_C(void, GX2SetDepthBuffer, const GX2DepthBuffer* depthBuffer);
EXPORT_FUNC_C(void, GX2SetHiStencilInfo, const GX2HiStencilInfo* hiStencilInfo);
EXPORT_FUNC_C(void, GX2CopySurface, const GX2Surface* srcSurface, u32 srcMip, u32 srcSlice, GX2Surface* dstSurface, u32 dstMip, u32 dstSlice);
EXPORT_FUNC_C(void, GX2CopySurfaceEx, const GX2Surface* srcSurface, u32 srcMip, u32 srcSlice, GX2Surface* dstSurface, u32 dstMip, u32 dstSlice, u32 numRects, GX2RectInt* srcRects, GX2PointInt* dstPoints);
EXPORT_FUNC_C(void, GX2AllocateTilingApertureEx, const GX2Surface* surface, u32 mip, u32 slice, GX2EndianSwapMode mode, u32* appHandle, void** appAddress);
EXPORT_FUNC_C(void, GX2FreeTilingAperture, u32 appHandle);
EXPORT_FUNC_C(void, GX2ResolveAAColorBuffer, const GX2ColorBuffer* srcBuffer, GX2Surface* dstSurface, u32 dstMip, u32 dstSlice);
EXPORT_FUNC_C(void, GX2ExpandAAColorBuffer, GX2ColorBuffer* buffer);
EXPORT_FUNC_C(void, GX2ExpandDepthBuffer, GX2DepthBuffer* buffer);
EXPORT_FUNC_C(void, GX2ConvertDepthBufferToTextureSurface, const GX2DepthBuffer* srcBuffer, GX2Surface* dstSurface, u32 dstMip, u32 dstSlice);
EXPORT_FUNC_C(u32, GX2GetSurfaceFormatBits, GX2SurfaceFormat format);
EXPORT_FUNC_C(u32, GX2GetSurfaceSwizzleOffset, GX2Surface* surface, u32 mipLevel);
EXPORT_FUNC_C(u32, GX2GetSurfaceSwizzle, GX2Surface* surface);
EXPORT_FUNC_C(void, GX2SetSurfaceSwizzle, GX2Surface* surface, u32 swizzle);
EXPORT_FUNC_C(u32, GX2GetSurfaceMipPitch, GX2Surface* surface, u32 mipLevel);
EXPORT_FUNC_C(u32, GX2GetSurfaceMipSliceSize, GX2Surface* surface, u32 mipLevel);
EXPORT_FUNC_C(bool, GX2SurfaceIsCompressed, GX2SurfaceFormat format);
EXPORT_FUNC_C(bool, GX2CheckSurfaceUseVsFormat, GX2SurfaceUse use, GX2SurfaceFormat format);
EXPORT_FUNC_C(void, GX2SetAAMode, GX2AAMode aa);
EXPORT_FUNC_C(void, GX2SetAAModeEx, GX2AASampleLoc* sampleLoc, GX2AAMode aa);

EXPORT_FUNC_C(u32, GX2TempGetGPUVersion, void);
EXPORT_FUNC_C(u32, GX2TempGetResourceCount, void);
EXPORT_FUNC_C(u32, GX2TempGetNonUserMemoryResourceCount, void);
EXPORT_FUNC_C(void, GX2TempDumpResources, void);
EXPORT_FUNC_C(void, GX2TempDumpGPUResourceContext, void);

EXPORT_FUNC_C(void, GX2SetTessellation, GX2TessellationMode mode, GX2PrimitiveType primType, GX2IndexFormat indexFmt);
EXPORT_FUNC_C(void, GX2SetMaxTessellationLevel, f32 maxLevel);
EXPORT_FUNC_C(void, GX2SetMinTessellationLevel, f32 minLevel);

EXPORT_FUNC_C(void, GX2InitTextureRegs, GX2Texture* texture);
EXPORT_FUNC_C(void, GX2SetVertexTexture, const GX2Texture* texture, u32 textureUnitNumber);
EXPORT_FUNC_C(void, GX2SetGeometryTexture, const GX2Texture* texture, u32 textureUnitNumber);
EXPORT_FUNC_C(void, GX2SetPixelTexture, const GX2Texture* texture, u32 textureUnitNumber);
EXPORT_FUNC_C(void, GX2SetComputeTexture, const GX2Texture* texture, u32 textureUnitNumber);

EXPORT_FUNC_C(void, GX2InitSampler, GX2Sampler* sampler, GX2TexClamp clampAll, GX2TexXYFilterType minMagFilter);
EXPORT_FUNC_C(void, GX2InitSamplerClamping, GX2Sampler* sampler, GX2TexClamp clampX, GX2TexClamp clampY, GX2TexClamp clampZ);
EXPORT_FUNC_C(void, GX2InitSamplerXYFilter, GX2Sampler* sampler, GX2TexXYFilterType magFilter, GX2TexXYFilterType minFilter, GX2TexAnisoRatio maxAniso);
EXPORT_FUNC_C(void, GX2InitSamplerZMFilter, GX2Sampler* sampler, GX2TexZFilterType zFilter, GX2TexMipFilterType mipFilter);
EXPORT_FUNC_C(void, GX2InitSamplerLOD, GX2Sampler* sampler, f32 minLod, f32 maxLod, f32 lodBias);
EXPORT_FUNC_C(void, GX2InitSamplerBorderType, GX2Sampler* sampler, GX2TexBorderType border);
EXPORT_FUNC_C(void, GX2InitSamplerRoundingMode, GX2Sampler* sampler, GX2RoundingModeType roundingMode);
EXPORT_FUNC_C(void, GX2SetVertexSamplerBorderColor, u32 samplerUnitNumber, f32 red, f32 green, f32 blue, f32 alpha);
EXPORT_FUNC_C(void, GX2SetGeometrySamplerBorderColor, u32 samplerUnitNumber, f32 red, f32 green, f32 blue, f32 alpha);
EXPORT_FUNC_C(void, GX2SetPixelSamplerBorderColor, u32 samplerUnitNumber, f32 red, f32 green, f32 blue, f32 alpha);
EXPORT_FUNC_C(void, GX2SetComputeSamplerBorderColor, u32 samplerUnitNumber, f32 red, f32 green, f32 blue, f32 alpha);
EXPORT_FUNC_C(void, GX2InitSamplerDepthCompare, GX2Sampler* sampler, GX2CompareFunction depthCompare);
EXPORT_FUNC_C(void, GX2InitSamplerFilterAdjust, GX2Sampler* sampler, bool highPrecision, GX2TexMipPerfType perfMip, GX2TexZPerfType perfZ);
EXPORT_FUNC_C(void, GX2InitSamplerLODAdjust, GX2Sampler* sampler, f32 anisoBias, bool lodUsesMinorAxis);
EXPORT_FUNC_C(void, GX2SetVertexSampler, const GX2Sampler* sampler, u32 samplerUnitNumber);
EXPORT_FUNC_C(void, GX2SetGeometrySampler, const GX2Sampler* sampler, u32 samplerUnitNumber);
EXPORT_FUNC_C(void, GX2SetPixelSampler, const GX2Sampler* sampler, u32 samplerUnitNumber);
EXPORT_FUNC_C(void, GX2SetComputeSampler, const GX2Sampler* sampler, u32 samplerUnitNumber);

EXPORT_FUNC_C(GX2UDAAlertID, GX2UDAGetLastAlert, void);
EXPORT_FUNC_C(void, GX2UDAResetAlertFireCount, GX2UDAAlertID id);
EXPORT_FUNC_C(void, GX2UDASetAlertLevel, GX2UDAAlertLevel newLevel);
EXPORT_FUNC_C(void, GX2UDASetAlertEnable, GX2UDAAlertID id, bool enable);

EXPORT_FUNC_C(void, GX2SetVerifyLevel, GX2VerifyLevel level);
EXPORT_FUNC_C(GX2VerifyCallback, GX2SetVerifyCallback, GX2VerifyCallback cb);

EXPORT_FUNC_C(H264Error, H264DECInitParam, s32 memSize, void* memPtr);
EXPORT_FUNC_C(H264Error, H264DECSetParam, void* memPtr, H264ParamID paramid, void* param);
EXPORT_FUNC_C(H264Error, H264DECOpen, void* memPtr);
EXPORT_FUNC_C(H264Error, H264DECBegin, void* memPtr);
EXPORT_FUNC_C(H264Error, H264DECSetBitstream, void* memPtr, const u8* bitStream, const s32 length, const f64 timeStamp);
EXPORT_FUNC_C(H264Error, H264DECExecute, void* memPtr, void* strFmPtr);
EXPORT_FUNC_C(H264Error, H264DECFlush, void* memPtr);
EXPORT_FUNC_C(H264Error, H264DECEnd, void* memPtr);
EXPORT_FUNC_C(H264Error, H264DECClose, void* memPtr);
EXPORT_FUNC_C(H264Error, H264DECMemoryRequirement, H264Profile profile, s32 level, s32 maxWidth, s32 maxHeight, s32* codecMemSize);
EXPORT_FUNC_C(H264Error, H264DECGetImageSize, const u8* buf, s32 totalBytes, s32 streamOffset, s32* width, s32* height);
EXPORT_FUNC_C(H264Error, H264DECFindDecstartpoint, const u8* buf, s32 totalBytes, s32* streamOffset);
EXPORT_FUNC_C(H264Error, H264DECFindIdrpoint, const u8* buf, s32 totalBytes, s32* streamOffset);
EXPORT_FUNC_C(H264Error, H264DECCheckDecunitLength, void* memPtr, const u8* buf, s32 totalBytes, s32 streamOffset, s32* length);
EXPORT_FUNC_C(H264Error, H264DECCheckMemSegmentation, void* memPtr, u32 size);
EXPORT_FUNC_C(H264Error, H264DECCheckSkipableFrame, const u8* buf, s32 length, s32* skipFlag);
EXPORT_FUNC_C(H264Error, H264DECSetParam_FPTR_OUTPUT, void* memPtr, int (*func)(void*));
EXPORT_FUNC_C(H264Error, H264DECSetParam_OUTPUT_PER_FRAME, void* memPtr, H264OutputPerFrameFlag flag);
EXPORT_FUNC_C(H264Error, H264DECSetParam_USER_MEMORY, void* memPtr, void** userMem);

EXPORT_FUNC_C(MICHandle, MICInit, MICInstance instance, MEMResource* res, MICRingBuffer* rb, MICError* err);
EXPORT_FUNC_C(MICError, MICUninit, MICHandle mic);
EXPORT_FUNC_C(MICError, MICOpen, MICHandle mic);
EXPORT_FUNC_C(MICError, MICGetStatus, MICHandle mic, MICStatus* status);
EXPORT_FUNC_C(MICError, MICSetDataConsumed, MICHandle mic, u32 consumedSamples);
EXPORT_FUNC_C(MICError, MICSetState, MICHandle mic, MICState state, u32 value);
EXPORT_FUNC_C(MICError, MICGetState, MICHandle mic, MICState state, u32* value);
EXPORT_FUNC_C(MICError, MICClose, MICHandle mic);

EXPORT_FUNC_C(IOProfilerError, IO_ProfilerLibInit, void);
EXPORT_FUNC_C(IOProfilerError, IO_ProfilerLibFinish, void);
EXPORT_FUNC_C(IOProfilerError, IO_ProfilerStartCheckpoint, IOProfilerFlag flags);
EXPORT_FUNC_C(IOProfilerError, IO_ProfilerGetStatsAndEndCheckpoint, IOProfilerFlag flags, u32* duration, IOProfilerStat* stats, int* numStats);
EXPORT_FUNC_C(IOProfilerError, IO_ProfilerGetStatsAndRestartCheckpoint, IOProfilerFlag flags, u32* duration, IOProfilerStat* stats, int* numStats);

EXPORT_FUNC_C(CURLFORMcode, curl_formadd, struct curl_httppost **httppost, struct curl_httppost **last_post, ...);
EXPORT_FUNC_C(void, curl_formfree, struct curl_httppost *form);
EXPORT_FUNC_C(char*, curl_getenv, const char *variable);
EXPORT_FUNC_C(char*, curl_version, void);
EXPORT_FUNC_C(char*, curl_easy_escape, CURL *handle, const char *string, int length);
EXPORT_FUNC_C(char*, curl_escape, const char *string, int length);
EXPORT_FUNC_C(char*, curl_easy_unescape, CURL *handle, const char *string, int length, int *outlength);
EXPORT_FUNC_C(char*, curl_unescape, const char *string, int length);
EXPORT_FUNC_C(void, curl_free, void *p);
EXPORT_FUNC_C(CURLcode, curl_global_init, long flags);
EXPORT_FUNC_C(CURLcode, curl_global_init_mem, long flags, curl_malloc_callback m, curl_free_callback f, curl_realloc_callback r, curl_strdup_callback s, curl_calloc_callback c);
EXPORT_FUNC_C(void, curl_global_cleanup, void);
EXPORT_FUNC_C(struct curl_slist*, curl_slist_append, struct curl_slist *, const char *);
EXPORT_FUNC_C(void, curl_slist_free_all, struct curl_slist *);
EXPORT_FUNC_C(time_t, curl_getdate, const char *p, const time_t *unused);
EXPORT_FUNC_C(CURLSH*, curl_share_init, void);
EXPORT_FUNC_C(CURLSHcode, curl_share_setopt, CURLSH *, CURLSHoption option, ...);
EXPORT_FUNC_C(CURLSHcode, curl_share_cleanup, CURLSH *);
EXPORT_FUNC_C(curl_version_info_data*, curl_version_info, CURLversion);
EXPORT_FUNC_C(const char*, curl_easy_strerror, CURLcode);
EXPORT_FUNC_C(const char*, curl_share_strerror, CURLSHcode);
EXPORT_FUNC_C(CURLcode, curl_easy_pause, CURL *handle, int bitmask);

EXPORT_FUNC_C(CURL*, curl_easy_init, void);
EXPORT_FUNC_C(CURLcode, curl_easy_setopt, CURL *curl, CURLoption option, ...);
EXPORT_FUNC_C(CURLcode, curl_easy_perform, CURL *curl);
EXPORT_FUNC_C(void, curl_easy_cleanup, CURL *curl);
EXPORT_FUNC_C(CURLcode, curl_easy_getinfo, CURL *curl, CURLINFO info, ...);
EXPORT_FUNC_C(CURL*, curl_easy_duphandle, CURL *curl);
EXPORT_FUNC_C(void, curl_easy_reset, CURL *curl);
EXPORT_FUNC_C(CURLcode, curl_easy_recv, CURL *curl, void *buffer, size_t buflen, size_t *n);
EXPORT_FUNC_C(CURLcode, curl_easy_send, CURL *curl, const void *buffer, size_t buflen, size_t *n);

EXPORT_FUNC_C(int, curl_mprintf, const char *format, ...);
EXPORT_FUNC_C(int, curl_mfprintf, FILE *fd, const char *format, ...);
EXPORT_FUNC_C(int, curl_msprintf, char *buffer, const char *format, ...);
EXPORT_FUNC_C(int, curl_msnprintf, char *buffer, size_t maxlength, const char *format, ...);
EXPORT_FUNC_C(int, curl_mvprintf, const char *format, va_list args);
EXPORT_FUNC_C(int, curl_mvfprintf, FILE *fd, const char *format, va_list args);
EXPORT_FUNC_C(int, curl_mvsprintf, char *buffer, const char *format, va_list args);
EXPORT_FUNC_C(int, curl_mvsnprintf, char *buffer, size_t maxlength, const char *format, va_list args);
EXPORT_FUNC_C(char*, curl_maprintf, const char *format, ...);
EXPORT_FUNC_C(char*, curl_mvaprintf, const char *format, va_list args);

EXPORT_FUNC_C(CURLM*, curl_multi_init, void);
EXPORT_FUNC_C(CURLMcode, curl_multi_add_handle, CURLM *multi_handle, CURL *curl_handle);
EXPORT_FUNC_C(CURLMcode, curl_multi_remove_handle, CURLM *multi_handle, CURL *curl_handle);
EXPORT_FUNC_C(CURLMcode, curl_multi_fdset, CURLM *multi_handle, fd_set *read_fd_set, fd_set *write_fd_set, fd_set *exc_fd_set, int *max_fd);
EXPORT_FUNC_C(CURLMcode, curl_multi_perform, CURLM *multi_handle, int *running_handles);
EXPORT_FUNC_C(CURLMcode, curl_multi_cleanup, CURLM *multi_handle);
EXPORT_FUNC_C(CURLMsg*, curl_multi_info_read, CURLM *multi_handle, int *msgs_in_queue);
EXPORT_FUNC_C(const char*, curl_multi_strerror, CURLMcode);
EXPORT_FUNC_C(CURLMcode, curl_multi_socket, CURLM *multi_handle, curl_socket_t s, int *running_handles);
EXPORT_FUNC_C(CURLMcode, curl_multi_socket_action, CURLM *multi_handle, curl_socket_t s, int ev_bitmask, int *running_handles);
EXPORT_FUNC_C(CURLMcode, curl_multi_socket_all, CURLM *multi_handle, int *running_handles);
EXPORT_FUNC_C(CURLMcode, curl_multi_timeout, CURLM *multi_handle, long *milliseconds);
EXPORT_FUNC_C(CURLMcode, curl_multi_setopt, CURLM *multi_handle, CURLMoption option, ...);
EXPORT_FUNC_C(CURLMcode, curl_multi_assign, CURLM *multi_handle, curl_socket_t sockfd, void *sockp);

EXPORT_FUNC_C(HIDError, HIDSetup, void);
EXPORT_FUNC_C(HIDError, HIDTeardown, void);
EXPORT_FUNC_C(HIDError, HIDAddClient, HIDClient* client, HIDAttachCallback attachCallback);
EXPORT_FUNC_C(HIDError, HIDDelClient, HIDClient* client);
EXPORT_FUNC_C(HIDError, HIDGetDescriptor, HIDDeviceHandle handle, u8 descriptorType, u8 descriptorIndex, u16 languageId, u8* buffer, u32 bufferLength, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_C(HIDError, HIDSetDescriptor, HIDDeviceHandle handle, u8 descriptorType, u8 descriptorIndex, u16 languageId, u8* buffer, u32 bufferLength, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_C(HIDError, HIDGetReport, HIDDeviceHandle handle, u8 reportType, u8 reportId, u8* buffer, u32 bufferLength, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_C(HIDError, HIDSetReport, HIDDeviceHandle handle, u8 reportType, u8 reportId, u8* buffer, u32 bufferLength, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_C(HIDError, HIDGetProtocol, HIDDeviceHandle handle, u8 interfaceIndex, u8* protocol, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_C(HIDError, HIDSetProtocol, HIDDeviceHandle handle, u8 interfaceIndex, u8 protocol, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_C(HIDError, HIDGetIdle, HIDDeviceHandle handle, u8 interfaceIndex, u8 reportId, u8* idle, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_C(HIDError, HIDSetIdle, HIDDeviceHandle handle, u8 interfaceIndex, u8 reportId, u8 duration, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_C(HIDError, HIDRead, HIDDeviceHandle handle, u8* buffer, u32 bufferLength, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_C(HIDError, HIDWrite, HIDDeviceHandle handle, u8* buffer, u32 bufferLength, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_C(HIDError, HIDResetDevice, HIDDeviceHandle handle, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_C(void, HIDDecodeError, HIDError error, u32* category, s32* code);

EXPORT_FUNC_C(uint32_t, ntohl, uint32_t val);
EXPORT_FUNC_C(uint32_t, htonl, uint32_t val);
EXPORT_FUNC_C(uint16_t, ntohs, uint16_t val);
EXPORT_FUNC_C(uint16_t, htons, uint16_t val);

EXPORT_FUNC_C(int, inet_aton, const char* cp, struct in_addr* addr);
EXPORT_FUNC_C(char*, inet_ntoa, struct in_addr in);
EXPORT_FUNC_C(const char*, inet_ntop, int af, const void* src, char* dst, socklen_t size);
EXPORT_FUNC_C(int, inet_pton, int af, const char* src, void* dst);

EXPORT_FUNC_C(char*, inet_ntoa_r, struct in_addr in, char* buf);

EXPORT_FUNC_C(int, select, int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, struct timeval* timeout);

EXPORT_FUNC_C(int, accept, int socket, struct sockaddr* address, socklen_t* address_len);
EXPORT_FUNC_C(int, bind, int socket, const struct sockaddr* address, socklen_t address_len);
EXPORT_FUNC_C(int, connect, int socket, const struct sockaddr* address, socklen_t address_len);
EXPORT_FUNC_C(int, getpeername, int socket, struct sockaddr* address, socklen_t* address_len);
EXPORT_FUNC_C(int, getsockname, int socket, struct sockaddr* address, socklen_t* address_len);
EXPORT_FUNC_C(int, getsockopt, int socket, int level, int option_name, void* option_value, socklen_t* option_len);
EXPORT_FUNC_C(int, listen, int socket, int backlog);
EXPORT_FUNC_C(ssize_t, recv, int socket, void* buffer, size_t length, int flags);
EXPORT_FUNC_C(ssize_t, recvfrom, int socket, void* buffer, size_t length, int flags, struct sockaddr* address, socklen_t* address_len);
EXPORT_FUNC_C(ssize_t, send, int socket, const void* buffer, size_t length, int flags);
EXPORT_FUNC_C(ssize_t, sendto, int socket, const void* buffer, size_t length, int flags, const struct sockaddr* address, socklen_t address_len);
EXPORT_FUNC_C(int, setsockopt, int socket, int level, int option_name, const void* option_value, socklen_t option_len);
EXPORT_FUNC_C(int, shutdown, int socket, int how);
EXPORT_FUNC_C(int, socket, int domain, int type, int protocol);

EXPORT_FUNC_C(int, socket_lib_init, void);
EXPORT_FUNC_C(int, socket_lib_finish, void);
EXPORT_FUNC_C(int, set_resolver_allocator, void* (*alloc)(uint32_t size), void (*free)(void* ptr));

EXPORT_FUNC_C(int, socketlasterr, void);

EXPORT_FUNC_C(int, socketclose, int socket);
EXPORT_FUNC_C(int, recvfrom_ex, int socket, void* buffer, int len, int flags, struct sockaddr* from, int* fromlen, uint8_t* msg, int msglen);
EXPORT_FUNC_C(int, recvfrom_multi, int socket, int flags, struct recvfrom_multi_buffers* buffs, int recv_datagram_len, int recv_datagram_count, struct timeval* timeout);
EXPORT_FUNC_C(int, sendto_multi, int socket, const void* buffer, int len, int flags, const struct sockaddr* dest_addrs, int dest_count);
EXPORT_FUNC_C(int, sendto_multi_ex, int socket, int flags, struct sendto_multi_ex_buffers* buffs, int send_datagram_count);
EXPORT_FUNC_C(int, setsocklibopt, int liboptname, int optval);
EXPORT_FUNC_C(int, getsocklibopt, int liboptname, int* optval);

EXPORT_FUNC_C(int*, get_h_errno, void);
EXPORT_FUNC_C(struct hostent*, gethostbyname, const char* name);
EXPORT_FUNC_C(struct hostent*, gethostbyaddr, const void* addr, int len, int type);
EXPORT_FUNC_C(int, getnameinfo, const struct sockaddr* addr, socklen_t addrlen, char* host, socklen_t hostlen, char* serv, socklen_t servlen, int flags);
EXPORT_FUNC_C(int, getaddrinfo, const char* node, const char* service, const struct addrinfo* hints, struct addrinfo** res);
EXPORT_FUNC_C(void, freeaddrinfo, struct addrinfo* res);
EXPORT_FUNC_C(const char*, gai_strerror, int errcode);

EXPORT_FUNC_C(int, getaddrinfo_rs, const char* node, const char* service, const struct addrinfo* hints, struct addrinfo** res);

EXPORT_FUNC_C(bool, WBCSetupCalibration, void);
EXPORT_FUNC_C(bool, WBCGetCalibrationStatus, void);
EXPORT_FUNC_C(s32, WBCRead, WPADBLStatus* status, double* weight, u32 size);
EXPORT_FUNC_C(s32, WBCGetBatteryLevel, u8 battery);
EXPORT_FUNC_C(s32, WBCSetZEROPoint, double* pressAvg, u32 size);
EXPORT_FUNC_C(s32, WBCGetTGCWeight, double totalWeightAvg, double *tgcWeight, WPADBLStatus* status);

EXPORT_FUNC_C(void, WPADInit, void);
EXPORT_FUNC_C(void, WPADShutdown, void);
EXPORT_FUNC_C(void, WPADRegisterAllocator, WPADAlloc alloc, WPADFree free);
EXPORT_FUNC_C(u32, WPADGetWorkMemorySize, void);

EXPORT_FUNC_C(WPADError, WPADProbe, WPADChannel chan, WPADDevice* type);
EXPORT_FUNC_C(WPADState, WPADGetStatus, void);
EXPORT_FUNC_C(WPADFormat, WPADGetDataFormat, WPADChannel chan);
EXPORT_FUNC_C(WPADError, WPADSetDataFormat, WPADChannel chan, WPADFormat fmt);
EXPORT_FUNC_C(void, WPADRead, WPADChannel chan, void* status);

EXPORT_FUNC_C(void, WPADSetAutoSamplingBuf, WPADChannel chan, void* buf, u32 length);
EXPORT_FUNC_C(u32, WPADGetLatestIndexInBuf, WPADChannel chan);

EXPORT_FUNC_C(void, WPADGetAccGravityUnit, WPADChannel chan, u32 type, WPADAcc* acc);
EXPORT_FUNC_C(void, WPADGetCLTriggerThreshold, WPADChannel chan, u8* left, u8* right);
EXPORT_FUNC_C(void, WPADClampStick, WPADChannel chan, void* status, WPADStickClamp type);
EXPORT_FUNC_C(void, WPADClampTrigger, WPADChannel chan, void* status, WPADTriggerClamp type);
EXPORT_FUNC_C(void, WPADClampAcc, WPADChannel chan, void* status, WPADAccClamp type);

EXPORT_FUNC_C(bool, WPADIsDpdEnabled, WPADChannel chan);
EXPORT_FUNC_C(WPADDpdCommand, WPADGetDpdFormat, WPADChannel chan);
EXPORT_FUNC_C(WPADError, WPADControlDpd, WPADChannel chan, WPADDpdCommand command, WPADCallback callback);
EXPORT_FUNC_C(u8, WPADGetDpdSensitivity, void);
EXPORT_FUNC_C(WPADError, WPADControlExtGimmick, WPADChannel chan, WPADExtGimmickCommand command, WPADCallback callback);

EXPORT_FUNC_C(void, WPADDisconnect, WPADChannel chan);
EXPORT_FUNC_C(WPADError, WPADGetInfo, WPADChannel chan, WPADInfo* info);
EXPORT_FUNC_C(WPADError, WPADGetInfoAsync, WPADChannel chan, WPADInfo* info, WPADCallback callback);
EXPORT_FUNC_C(void, WPADGetAddress, WPADChannel chan, u8* addr);
EXPORT_FUNC_C(u8, WPADGetRegisteredDevNum, void);
EXPORT_FUNC_C(u8, WPADGetRadioSensitivity, WPADChannel chan);
EXPORT_FUNC_C(WPADBatteryLevel, WPADGetBatteryLevel, WPADChannel chan);

EXPORT_FUNC_C(bool, WPADIsSpeakerEnabled, WPADChannel chan);
EXPORT_FUNC_C(WPADError, WPADControlSpeaker, WPADChannel chan, WPADSpeakerCommand command, WPADCallback callback);
EXPORT_FUNC_C(u8, WPADGetSpeakerVolume, void);

EXPORT_FUNC_C(WPADError, WPADSendStreamData, WPADChannel chan, void* buf, u16 len);
EXPORT_FUNC_C(bool, WPADCanSendStreamData, WPADChannel chan);

EXPORT_FUNC_C(void, WPADControlMotor, WPADChannel chan, WPADMotorCommand command);
EXPORT_FUNC_C(bool, WPADIsMotorEnabled, void);

EXPORT_FUNC_C(void, WPADSetAutoSleepTime, u8 minutes);
EXPORT_FUNC_C(u32, WPADGetAutoSleepTimeCount, WPADChannel chan);
EXPORT_FUNC_C(void, WPADResetAutoSleepTimeCount, WPADChannel chan);

EXPORT_FUNC_C(WPADSensorBarPosition, WPADGetSensorBarPosition, void);
EXPORT_FUNC_C(void, WPADEnableSensorBar, WPADSensorBarPosition sensorBar);
EXPORT_FUNC_C(void, WPADSetSensorBar, bool on);

EXPORT_FUNC_C(void, WPADSetGameTitleUtf16, const u16* title);
EXPORT_FUNC_C(WPADError, WPADGetGameTitleUtf16, WPADChannel chan, const u16** title);
EXPORT_FUNC_C(WPADError, WPADGetGameDataTimeStamp, WPADChannel chan, OSTime* time);

EXPORT_FUNC_C(bool, WPADSetAcceptConnection, bool accept);
EXPORT_FUNC_C(bool, WPADGetAcceptConnection, void);

EXPORT_FUNC_C(bool, WPADStartSyncDevice, void);
EXPORT_FUNC_C(bool, WPADPurgeBtDb, void);
EXPORT_FUNC_C(bool, WPADCancelSyncDevice, void);
EXPORT_FUNC_C(bool, WPADIsBusyForSync, void);
EXPORT_FUNC_C(WPADError, WPADGetSyncType, WPADChannel chan, WPADSyncType* type);

EXPORT_FUNC_C(WPADSamplingCallback, WPADSetSamplingCallback, WPADChannel chan, WPADSamplingCallback callback);
EXPORT_FUNC_C(WPADExtensionCallback, WPADSetExtensionCallback, WPADChannel chan, WPADExtensionCallback callback);
EXPORT_FUNC_C(WPADConnectCallback, WPADSetConnectCallback, WPADChannel chan, WPADConnectCallback callback);
EXPORT_FUNC_C(WPADSyncDeviceCallback, WPADSetSyncDeviceCallback, WPADSyncDeviceCallback callback);
EXPORT_FUNC_C(WPADClearDeviceCallback, WPADSetClearDeviceCallback, WPADClearDeviceCallback callback);

EXPORT_FUNC_C(bool, WPADAttachDummyExtension, WPADChannel chan, WPADDevice type);
EXPORT_FUNC_C(bool, WPADDetachDummyExtension, WPADChannel chan);

EXPORT_FUNC_C(WPADError, WPADIsMplsAttached, WPADChannel chan, bool* attached, WPADCallback callback);
EXPORT_FUNC_C(WPADError, WPADIsMplsIntegrated, WPADChannel chan);
EXPORT_FUNC_C(bool, WPADGetCalibrationStatus, WPADChannel chan);

EXPORT_FUNC_C(void, WPADEnableURCC, bool enable);
EXPORT_FUNC_C(void, WPADEnableWiiRemote, bool enable);
EXPORT_FUNC_C(void, WPADDisableBluetooth, void);

EXPORT_FUNC_C(s32, WPADControlBLC, WPADChannel chan, WPADBLCommand command, WPADCallback callback);
EXPORT_FUNC_C(s32, WPADGetBLCalibration, WPADChannel chan, u8* data, u16 addr, u16 len, WPADCallback callback);
EXPORT_FUNC_C(bool, WPADIsRegisteredBLC, void);
EXPORT_FUNC_C(void, WPADRegisterBLCWorkarea, void* workArea);
EXPORT_FUNC_C(bool, WPADIsEnabledWBC, void);
EXPORT_FUNC_C(void, WPADEnableWBC, void);

EXPORT_FUNC_C(s32, WENCGetEncodeData, WENCInfo* info, WENCFlag flag, const s16* pcmData, s32 sampleNum, u8* pbyEncData);

EXPORT_FUNC_C(void, KPADInit, void);
EXPORT_FUNC_C(void, KPADInitEx, KPADUnifiedWpadStatus* uniRingBufs, u32 length);
EXPORT_FUNC_C(void, KPADShutdown, void);
EXPORT_FUNC_C(void, KPADReset, void);

EXPORT_FUNC_C(s32, KPADRead, WPADChannel chan, KPADStatus* samplingBufs, u32 count);
EXPORT_FUNC_C(s32, KPADReadEx, WPADChannel chan, KPADStatus* samplingBufs, u32 count, KPADReadError* err);
EXPORT_FUNC_C(void, KPADGetUnifiedWpadStatus, WPADChannel chan, KPADUnifiedWpadStatus* dst, u32 count);
EXPORT_FUNC_C(void, KPADGetProjectionPos, KPADVec2* dst, const KPADVec2* src, const KPADRect* projRect, f32 viRatio);

EXPORT_FUNC_C(void, KPADSetPosParam, WPADChannel chan, f32 playRadius, f32 sensitivity);
EXPORT_FUNC_C(void, KPADSetHoriParam, WPADChannel chan, f32 playRadius, f32 sensitivity);
EXPORT_FUNC_C(void, KPADSetDistParam, WPADChannel chan, f32 playRadius, f32 sensitivity);
EXPORT_FUNC_C(void, KPADSetAccParam, WPADChannel chan, f32 playRadius, f32 sensitivity);
EXPORT_FUNC_C(void, KPADSetCrossStickEmulationParamsL, WPADChannel chan, f32 rotDeg, f32 xyDeg, f32 radius);
EXPORT_FUNC_C(void, KPADSetCrossStickEmulationParamsR, WPADChannel chan, f32 rotDeg, f32 xyDeg, f32 radius);
EXPORT_FUNC_C(void, KPADGetPosParam, WPADChannel chan, f32* playRadius, f32* sensitivity);
EXPORT_FUNC_C(void, KPADGetHoriParam, WPADChannel chan, f32* playRadius, f32* sensitivity);
EXPORT_FUNC_C(void, KPADGetDistParam, WPADChannel chan, f32* playRadius, f32* sensitivity);
EXPORT_FUNC_C(void, KPADGetAccParam, WPADChannel chan, f32* playRadius, f32* sensitivity);
EXPORT_FUNC_C(void, KPADGetCrossStickEmulationParamsL, WPADChannel chan, f32* rotDeg, f32* xyDeg, f32* radius);
EXPORT_FUNC_C(void, KPADGetCrossStickEmulationParamsR, WPADChannel chan, f32* rotDeg, f32* xyDeg, f32* radius);

EXPORT_FUNC_C(void, KPADSetBtnRepeat, WPADChannel chan, f32 delaySec, f32 pulseSec);
EXPORT_FUNC_C(void, KPADSetObjInterval, f32 interval);

EXPORT_FUNC_C(void, KPADDisableDPD, WPADChannel chan);
EXPORT_FUNC_C(void, KPADEnableDPD, WPADChannel chan);
EXPORT_FUNC_C(s32, KPADCalibrateDPD, WPADChannel chan);

EXPORT_FUNC_C(void, KPADSetSensorHeight, WPADChannel chan, f32 level);
EXPORT_FUNC_C(f32, KPADGetSensorHeight, WPADChannel chan);

EXPORT_FUNC_C(void, KPADEnableStickCrossClamp, void);
EXPORT_FUNC_C(void, KPADDisableStickCrossClamp, void);
EXPORT_FUNC_C(void, KPADSetFSStickClamp, s8 min, s8 max);

EXPORT_FUNC_C(void, KPADEnableAimingMode, WPADChannel chan);
EXPORT_FUNC_C(void, KPADDisableAimingMode, WPADChannel chan);
EXPORT_FUNC_C(u8, KPADIsEnableAimingMode, WPADChannel chan);

EXPORT_FUNC_C(void, KPADSetControlDpdCallback, WPADChannel chan, KPADControlDpdCallback callback);
EXPORT_FUNC_C(WPADSamplingCallback, KPADSetSamplingCallback, WPADChannel chan, WPADSamplingCallback callback);
EXPORT_FUNC_C(WPADConnectCallback, KPADSetConnectCallback, WPADChannel chan, WPADConnectCallback callback);

EXPORT_FUNC_C(void, KPADSetReviseMode, WPADChannel chan, bool sw);
EXPORT_FUNC_C(f32, KPADReviseAcc, KPADVec3* acc);
EXPORT_FUNC_C(f32, KPADGetReviseAngle, void);
EXPORT_FUNC_C(void, KPADSetPosPlayMode, WPADChannel chan, KPADPlayMode mode);
EXPORT_FUNC_C(void, KPADSetHoriPlayMode, WPADChannel chan, KPADPlayMode mode);
EXPORT_FUNC_C(void, KPADSetDistPlayMode, WPADChannel chan, KPADPlayMode mode);
EXPORT_FUNC_C(void, KPADSetAccPlayMode, WPADChannel chan, KPADPlayMode mode);
EXPORT_FUNC_C(KPADPlayMode, KPADGetPosPlayMode, WPADChannel chan);
EXPORT_FUNC_C(KPADPlayMode, KPADGetHoriPlayMode, WPADChannel chan);
EXPORT_FUNC_C(KPADPlayMode, KPADGetDistPlayMode, WPADChannel chan);
EXPORT_FUNC_C(KPADPlayMode, KPADGetAccPlayMode, WPADChannel chan);
EXPORT_FUNC_C(void, KPADSetButtonProcMode, WPADChannel chan, KPADButtonProcMode mode);
EXPORT_FUNC_C(KPADButtonProcMode, KPADGetButtonProcMode, WPADChannel chan);

EXPORT_FUNC_C(void, KPADResetWbcZeroPoint, void);
EXPORT_FUNC_C(void, KPADResetWbcTgcWeight, void);

EXPORT_FUNC_C(void, KPADDisableMpls, WPADChannel chan);
EXPORT_FUNC_C(void, KPADEnableMpls, WPADChannel chan, WPADMplsCommand mode);
EXPORT_FUNC_C(u8, KPADGetMplsStatus, WPADChannel chan);
EXPORT_FUNC_C(void, KPADSetControlMplsCallback, WPADChannel chan, KPADControlMplsCallback callback);
EXPORT_FUNC_C(u32, KPADGetMplsWorkSize, void);
EXPORT_FUNC_C(void, KPADSetMplsWorkarea, void* ptr);
EXPORT_FUNC_C(void, KPADResetMpls, WPADChannel chan);
EXPORT_FUNC_C(void, KPADSetMplsAngle, WPADChannel chan, f32 ax, f32 ay, f32 az);
EXPORT_FUNC_C(void, KPADSetMplsDirection, WPADChannel chan, KPADMPDir* dir);
EXPORT_FUNC_C(void, KPADStartMplsCalibration, WPADChannel chan);
EXPORT_FUNC_C(f32, KPADWorkMplsCalibration, WPADChannel chan);
EXPORT_FUNC_C(void, KPADStopMplsCalibration, WPADChannel chan);
EXPORT_FUNC_C(void, KPADSetMplsDirectionMag, WPADChannel chan, f32 mag);
EXPORT_FUNC_C(void, KPADEnableMplsZeroPlay, WPADChannel chan);
EXPORT_FUNC_C(void, KPADEnableMplsDirRevise, WPADChannel chan);
EXPORT_FUNC_C(void, KPADEnableMplsAccRevise, WPADChannel chan);
EXPORT_FUNC_C(void, KPADEnableMplsDpdRevise, WPADChannel chan);
EXPORT_FUNC_C(void, KPADDisableMplsZeroPlay, WPADChannel chan);
EXPORT_FUNC_C(void, KPADDisableMplsDirRevise, WPADChannel chan);
EXPORT_FUNC_C(void, KPADDisableMplsAccRevise, WPADChannel chan);
EXPORT_FUNC_C(void, KPADDisableMplsDpdRevise, WPADChannel chan);
EXPORT_FUNC_C(f32, KPADIsEnableMplsZeroPlay, WPADChannel chan);
EXPORT_FUNC_C(f32, KPADIsEnableMplsZeroDrift, WPADChannel chan);
EXPORT_FUNC_C(f32, KPADIsEnableMplsDirRevise, WPADChannel chan);
EXPORT_FUNC_C(f32, KPADIsEnableMplsAccRevise, WPADChannel chan);
EXPORT_FUNC_C(f32, KPADIsEnableMplsDpdRevise, WPADChannel chan);
EXPORT_FUNC_C(void, KPADSetMplsZeroPlayParam, WPADChannel chan, f32 radius);
EXPORT_FUNC_C(void, KPADSetMplsDirReviseParam, WPADChannel chan, f32 revisePw);
EXPORT_FUNC_C(void, KPADSetMplsAccReviseParam, WPADChannel chan, f32 revisePw, f32 reviseRange);
EXPORT_FUNC_C(void, KPADSetMplsDpdReviseParam, WPADChannel chan, f32 revisePw);
EXPORT_FUNC_C(void, KPADSetMplsDirReviseBase, WPADChannel chan, KPADMPDir* base);
EXPORT_FUNC_C(void, KPADGetMplsZeroPlayParam, WPADChannel chan, f32* radius);
EXPORT_FUNC_C(void, KPADGetMplsDirReviseParam, WPADChannel chan, f32* revisePw);
EXPORT_FUNC_C(void, KPADGetMplsAccReviseParam, WPADChannel chan, f32* revisePw, f32* reviseRange);
EXPORT_FUNC_C(void, KPADGetMplsDpdReviseParam, WPADChannel chan, f32* revisePw);
EXPORT_FUNC_C(void, KPADInitMplsZeroPlayParam, WPADChannel chan);
EXPORT_FUNC_C(void, KPADInitMplsDirReviseParam, WPADChannel chan);
EXPORT_FUNC_C(void, KPADInitMplsAccReviseParam, WPADChannel chan);
EXPORT_FUNC_C(void, KPADInitMplsDpdReviseParam, WPADChannel chan);
EXPORT_FUNC_C(void, KPADInitMplsZeroDriftMode, WPADChannel chan);
EXPORT_FUNC_C(void, KPADSetMplsZeroDriftMode, WPADChannel chan, KPADMplsZeroDriftMode mode);
EXPORT_FUNC_C(void, KPADGetMplsZeroDriftMode, WPADChannel chan, KPADMplsZeroDriftMode* mode);
EXPORT_FUNC_C(void, KPADSetMplsMagnification, WPADChannel chan, f32 pitch, f32 yaw, f32 roll);

EXPORT_FUNC_C(void, KPADSetDpdDetection, KPADDPDDetectionMode mode);
EXPORT_FUNC_C(KPADDPDDetectionMode, KPADGetDpdDetection, void);

EXPORT_FUNC_C(void, ProcUIInit, ProcUISaveCallbackFunction func);
EXPORT_FUNC_C(void, ProcUIInitEx, ProcUISaveCallbackFunctionEx func, void* data);
EXPORT_FUNC_C(void, ProcUIShutdown, void);

EXPORT_FUNC_C(bool, ProcUIIsRunning, void);
EXPORT_FUNC_C(bool, ProcUIInForeground, void);
EXPORT_FUNC_C(bool, ProcUIInShutdown, void);

EXPORT_FUNC_C(ProcUIStatus, ProcUISubProcessMessages, bool block);
EXPORT_FUNC_C(ProcUIStatus, ProcUIProcessMessages, bool block);

EXPORT_FUNC_C(void, ProcUIDrawDoneRelease, void);

EXPORT_FUNC_C(u32, ProcUICalcMemorySize, u32 numCallbacks);
EXPORT_FUNC_C(ProcUIError, ProcUISetMemoryPool, void* memory, u32 sizeInBytes);
EXPORT_FUNC_C(void, ProcUISetMEM1Storage, void* data, u32 size);
EXPORT_FUNC_C(void, ProcUISetBucketStorage, void* data, u32 size);

EXPORT_FUNC_C(void, ProcUIClearCallbacks, void);
EXPORT_FUNC_C(void, ProcUISetCallbackStackSize, u32 size);
EXPORT_FUNC_C(void, ProcUIRegisterBackgroundCallback, ProcUICallbackFunction func, void* data, OSTime ticksToDelay);
EXPORT_FUNC_C(void, ProcUIRegisterCallback, ProcUIMessage message, ProcUICallbackFunction func, void* data, s32 priority);
EXPORT_FUNC_C(void, ProcUIRegisterCallbackCore, ProcUIMessage message, ProcUICallbackFunction func, void* data, s32 priority, OSCoreId core);
EXPORT_FUNC_C(void, ProcUISetSaveCallback, ProcUISaveCallbackFunctionEx func, void* data);

EXPORT_FUNC_C(void, AIInit, u8* stack);
EXPORT_FUNC_C(void, AIReset, void);
EXPORT_FUNC_C(void, AIQuit, void);
EXPORT_FUNC_C(bool, AICheckInit, void);

EXPORT_FUNC_C(AIDMACallback, AIRegisterDMACallback, AIDMACallback callback);
EXPORT_FUNC_C(AIDMACallback, AIDRCRegisterDMACallback, AIDMACallback callback);

EXPORT_FUNC_C(void, AIInitDMA, u32 startAddr, u32 length);
EXPORT_FUNC_C(bool, AIGetDMAEnableFlag, void);
EXPORT_FUNC_C(void, AIStartDMA, void);
EXPORT_FUNC_C(void, AIStopDMA, void);
EXPORT_FUNC_C(void, AIGetDMARange, u32 startAddr, u32* addrHi, u32* addrLow);
EXPORT_FUNC_C(u32, AIGetDMABytesLeft, void);
EXPORT_FUNC_C(u32, AIGetDMAStartAddr, void);
EXPORT_FUNC_C(u32, AIDRCGetDMAStartAddr, void);
EXPORT_FUNC_C(u32, AIGetDMALength, void);
EXPORT_FUNC_C(u32, AIDRCGetDMALength, void);

EXPORT_FUNC_C(u32, AIGetAudioFrameCount, void);
EXPORT_FUNC_C(AISampleRate, AIGetDSPSampleRate, void);
EXPORT_FUNC_C(void, AISetDSPSampleRate, AISampleRate rate);
EXPORT_FUNC_C(void, AISetChannel, AIChannel channel, bool stuffing);

EXPORT_FUNC_C(void, AXInit, void);
EXPORT_FUNC_C(void, AXInitEx, AXOutputBufferMode outputBufferMode);
EXPORT_FUNC_C(AXInitError, AXInitWithParams, AXInitParams* initParams);
EXPORT_FUNC_C(void, AXGetCurrentParams, AXInitParams* currentParams);
EXPORT_FUNC_C(bool, AXIsInit, void);
EXPORT_FUNC_C(void, AXQuit, void);

EXPORT_FUNC_C(u32, AXGetLibraryVersion, void);

EXPORT_FUNC_C(bool, AXIsAudioOutReady, void);
EXPORT_FUNC_C(u16, AXGetMasterVolume, void);
EXPORT_FUNC_C(void, AXSetMasterVolume, u16 volume);

EXPORT_FUNC_C(void, AXInitProfile, AXProfile* profile, u32 maxProfiles);
EXPORT_FUNC_C(u32, AXGetProfile, void);
EXPORT_FUNC_C(u32, AXGetSwapProfile, AXProfile* profile, u32 maxProfiles);

EXPORT_FUNC_C(void, AXSetMaxDspCycles, u32 cycles);
EXPORT_FUNC_C(u32, AXGetMaxDspCycles, void);
EXPORT_FUNC_C(u32, AXGetDspCycles, void);

EXPORT_FUNC_C(void, AXSetPpcLoadLimit, f32 limit);
EXPORT_FUNC_C(f32, AXGetPpcLoadLimit, void);
EXPORT_FUNC_C(f32, AXGetPpcLoad, void);
EXPORT_FUNC_C(void, AXSetDspLoadLimit, f32 limit);
EXPORT_FUNC_C(f32, AXGetDspLoadLimit, void);
EXPORT_FUNC_C(f32, AXGetDspLoad, void);

EXPORT_FUNC_C(u32, AXGetInputSamplesPerFrame, void);
EXPORT_FUNC_C(u32, AXGetInputSamplesPerSec, void);

EXPORT_FUNC_C(AXMixerSelect, AXSetDefaultMixerSelect, AXMixerSelect mixerSelect);
EXPORT_FUNC_C(AXMixerSelect, AXGetDefaultMixerSelect, void);
EXPORT_FUNC_C(AXRendererFrequency, AXGetRendererFreq, void);

EXPORT_FUNC_C(AXUserCallback, AXRegisterCallback, AXUserCallback callback);
EXPORT_FUNC_C(AXUserCallback, AXRegisterDRCCallback, AXUserCallback callback);
EXPORT_FUNC_C(AXUserCallback, AXRegisterFrameCallback, AXUserCallback fcb);
EXPORT_FUNC_C(void, AXRegisterExceedCallback, AXExceedCallback callback);
EXPORT_FUNC_C(AXError, AXRegisterAppFrameCallback, AXUserCallback fcb);
EXPORT_FUNC_C(AXError, AXDeregisterAppFrameCallback, AXUserCallback fcb);

EXPORT_FUNC_C(AXError, AXRegisterDeviceFinalMixCallback, AXDeviceType device, AXUserFinalMixCallback fcb);
EXPORT_FUNC_C(AXError, AXGetDeviceFinalMixCallback, AXDeviceType device, AXUserFinalMixCallback* fcb);
EXPORT_FUNC_C(AXError, AXSetDeviceMode, AXDeviceType device, AXDeviceMode mode);
EXPORT_FUNC_C(AXError, AXGetDeviceMode, AXDeviceType device, AXDeviceMode* mode);
EXPORT_FUNC_C(AXError, AXGetDeviceChannelCount, AXDeviceType device, u32 id, u32* count);
EXPORT_FUNC_C(AXError, AXSetDeviceVolume, AXDeviceType device, u32 id, u16 volume);
EXPORT_FUNC_C(AXError, AXGetDeviceVolume, AXDeviceType device, u32 id, u16* volume);
EXPORT_FUNC_C(AXError, AXSetDeviceRemixMatrix, AXDeviceType device, const u32 numInChns, const u32 numOutChns, const f32* matrixPtr);
EXPORT_FUNC_C(AXError, AXGetDeviceRemixMatrix, AXDeviceType device, const u32 numInChns, const u32 numOutChns, const f32** matrixPtr);
EXPORT_FUNC_C(AXError, AXGetDeviceUpsampleStage, AXDeviceType device, bool* post);
EXPORT_FUNC_C(AXError, AXSetDeviceUpsampleStage, AXDeviceType device, bool post);
EXPORT_FUNC_C(AXError, AXGetDeviceFinalOutput, AXDeviceType device, s16* dataPtr, const u32 size, AXDeviceFinalOutput* axDeviceFinalOutputStruct);
EXPORT_FUNC_C(AXError, AXSetDeviceLinearUpsampler, AXDeviceType device, u32 deviceId, bool flag);
EXPORT_FUNC_C(AXError, AXSetDeviceCompressor, AXDeviceType device, AXCompressorState state);
EXPORT_FUNC_C(AXError, AXSetDeviceCompressorTable, AXDeviceType device, u16* table, u16 frames);
EXPORT_FUNC_C(void, AXMakeCompressorTable, f32 gain, u16 frames, u16* table);

EXPORT_FUNC_C(AXError, AXSetDRCVSMode, AXDRCVSModeType mode);
EXPORT_FUNC_C(AXError, AXGetDRCVSMode, AXDRCVSModeType* mode);
EXPORT_FUNC_C(AXError, AXSetDRCVSLC, AXDRCVSLCMode mode);
EXPORT_FUNC_C(AXError, AXSetDRCVSSpeakerPosition, AXDRCVSOutputMode output, AXDRCVSSpeakerPosition pos);
EXPORT_FUNC_C(AXError, AXSetDRCVSSurroundDepth, AXDRCVSOutputMode output, f32 depth);
EXPORT_FUNC_C(AXError, AXSetDRCVSDownmixBalance, AXDRCVSOutputMode output, f32 balance);
EXPORT_FUNC_C(AXError, AXSetDRCVSSurroundLevelGain, AXDRCVSSurroundLevelGain gain);
EXPORT_FUNC_C(AXError, AXSetDRCVSOutputGain, AXDRCVSOutputMode output, f32 gain);
EXPORT_FUNC_C(AXError, AXSetDRCVSLimiter, bool enable);
EXPORT_FUNC_C(AXError, AXSetDRCVSLimiterThreshold, f32 level);

EXPORT_FUNC_C(u16, AXGetMasterDRCVolume, void);
EXPORT_FUNC_C(void, AXSetMasterDRCVolume, u16 volume);
EXPORT_FUNC_C(u16, AXGetDRCAuxReturnVolume, void);
EXPORT_FUNC_C(void, AXSetDRCAuxReturnVolume, u16 volume);
EXPORT_FUNC_C(void, AXRegisterAuxDRCCallback, AXAuxCallback callback, void* context);
EXPORT_FUNC_C(void, AXGetAuxDRCCallback, AXAuxCallback* callback, void** context);

EXPORT_FUNC_C(AXError, AXRegisterAuxCallback, AXDeviceType device, u32 id, u32 auxId, AXUserAuxCallback fcb, void* context);
EXPORT_FUNC_C(AXError, AXGetAuxCallback, AXDeviceType device, u32 id, u32 auxId, AXUserAuxCallback* fcb, void** context);
EXPORT_FUNC_C(AXError, AXSetAuxReturnVolume, AXDeviceType device, u32 id, u32 auxId, u16 volume);
EXPORT_FUNC_C(AXError, AXGetAuxReturnVolume, AXDeviceType device, u32 id, u32 auxId, u16* volume);
EXPORT_FUNC_C(void, AXRegisterAuxACallback, AXAuxCallback callback, void* context);
EXPORT_FUNC_C(void, AXRegisterAuxBCallback, AXAuxCallback callback, void* context);
EXPORT_FUNC_C(void, AXRegisterAuxCCallback, AXAuxCallback callback, void* context);
EXPORT_FUNC_C(void, AXGetAuxACallback, AXAuxCallback* callback, void** context);
EXPORT_FUNC_C(void, AXGetAuxBCallback, AXAuxCallback* callback, void** context);
EXPORT_FUNC_C(void, AXGetAuxCCallback, AXAuxCallback* callback, void** context);
EXPORT_FUNC_C(u16, AXGetAuxAReturnVolume, void);
EXPORT_FUNC_C(u16, AXGetAuxBReturnVolume, void);
EXPORT_FUNC_C(u16, AXGetAuxCReturnVolume, void);
EXPORT_FUNC_C(void, AXSetAuxAReturnVolume, u16 volume);
EXPORT_FUNC_C(void, AXSetAuxBReturnVolume, u16 volume);
EXPORT_FUNC_C(void, AXSetAuxCReturnVolume, u16 volume);

EXPORT_FUNC_C(void, AXPrepareEfxData, const void* samples, u32 size);
EXPORT_FUNC_C(void, AXSetStepMode, u32 mode);
EXPORT_FUNC_C(void, AXComputeLpfCoefs, u16 freq, u16* a0, u16* b0);

EXPORT_FUNC_C(s32, AXGetAdpcmOutputSize, s32 samples);
EXPORT_FUNC_C(s32, AXGetAdpcmWorkSize, s32 samples);
EXPORT_FUNC_C(s32, AXGetAdpcmData, const s16* input, s32 samples, s32 rate, s32 loopStart, s32 loopEnd, u8* output, AXDspAdpcmHeader* info, void* work);
EXPORT_FUNC_C(s32, AXDecodeAdpcmData, const u8* input, AXDspAdpcmHeader* info, s32 samples, s16* output);

EXPORT_FUNC_C(u32, AXGetMaxDspVoices, void);
EXPORT_FUNC_C(void, AXSetMaxDspVoices, u32 maxVoices);
EXPORT_FUNC_C(u32, AXGetMaxVoices, void);
EXPORT_FUNC_C(u32, AXGetNumVoices, void);
EXPORT_FUNC_C(u32, AXGetNumDspVoices, void);
EXPORT_FUNC_C(u32, AXGetDroppedVoiceCount, void);

EXPORT_FUNC_C(AXSyncError, AXUserBegin, void);
EXPORT_FUNC_C(AXSyncError, AXUserEnd, void);
EXPORT_FUNC_C(bool, AXUserIsProtected, void);

EXPORT_FUNC_C(AXSyncError, AXVoiceBegin, AXVoice* voice);
EXPORT_FUNC_C(AXSyncError, AXVoiceEnd, AXVoice* voice);
EXPORT_FUNC_C(bool, AXVoiceIsProtected, AXVoice* voice);

EXPORT_FUNC_C(AXVoice*, AXAcquireVoice, u32 priority, AXVoiceCallback callback, u32 userContext);
EXPORT_FUNC_C(AXVoice*, AXAcquireVoiceEx, u32 priority, AXVoiceCallbackEx callback, u32 userContext);
EXPORT_FUNC_C(void, AXFreeVoice, AXVoice* voice);
EXPORT_FUNC_C(bool, AXIsVoiceRunning, AXVoice* voice);
EXPORT_FUNC_C(u32, AXGetVoiceLoopCount, AXVoice* voice);
EXPORT_FUNC_C(AXMixerSelect, AXSetVoiceMixerSelect, AXVoice* voice, AXMixerSelect mixerSelect);
EXPORT_FUNC_C(AXMixerSelect, AXGetVoiceMixerSelect, AXVoice* voice);
EXPORT_FUNC_C(void, AXSetVoicePriority, AXVoice* voice, u32 priority);
EXPORT_FUNC_C(void, AXSetVoiceSrcType, AXVoice* voice, AXSrcType type);
EXPORT_FUNC_C(void, AXSetVoiceState, AXVoice* voice, AXVoiceState state);
EXPORT_FUNC_C(void, AXSetVoiceType, AXVoice* voice, AXVoiceType type);
EXPORT_FUNC_C(void, AXSetVoiceVe, AXVoice* voice, const AXVolumeEnvelope* ve);
EXPORT_FUNC_C(void, AXSetVoiceVeDelta, AXVoice* voice, s16 delta);
EXPORT_FUNC_C(void, AXSetVoiceLoop, AXVoice* voice, AXLoopFlag loop);
EXPORT_FUNC_C(void, AXGetVoiceOffsets, AXVoice* voice, AXVoiceOffsets* addr);
EXPORT_FUNC_C(void, AXGetVoiceOffsetsEx, AXVoice* voice, AXVoiceOffsets* addr, const void* samples);
EXPORT_FUNC_C(void, AXSetVoiceOffsets, AXVoice* voice, const AXVoiceOffsets* addr);
EXPORT_FUNC_C(void, AXSetVoiceOffsetsEx, AXVoice* voice, const AXVoiceOffsets* addr, const void* samples);
EXPORT_FUNC_C(void, AXSetVoiceLoopOffset, AXVoice* voice, u32 offset);
EXPORT_FUNC_C(void, AXSetVoiceLoopOffsetEx, AXVoice* voice, u32 offset, const void* samples);
EXPORT_FUNC_C(void, AXSetVoiceEndOffset, AXVoice* voice, u32 offset);
EXPORT_FUNC_C(void, AXSetVoiceEndOffsetEx, AXVoice* voice, u32 offset, const void* samples);
EXPORT_FUNC_C(void, AXSetVoiceCurrentOffset, AXVoice* voice, u32 offset);
EXPORT_FUNC_C(void, AXSetVoiceCurrentOffsetEx, AXVoice* voice, u32 offset, const void* samples);
EXPORT_FUNC_C(u32, AXGetVoiceCurrentOffsetEx, AXVoice* voice, const void* samples);
EXPORT_FUNC_C(void, AXSetVoiceDRCMix, AXVoice* voice, const AXDRCMix* mix);
EXPORT_FUNC_C(void, AXSetVoiceRmtMix, AXVoice* voice, const AXRemoteMix* mix);
EXPORT_FUNC_C(void, AXSetVoiceSamplesAddr, AXVoice* voice, const void* samples);
EXPORT_FUNC_C(void, AXSetVoiceAdpcm, AXVoice* voice, const AXAdpcmState* adpcm);
EXPORT_FUNC_C(void, AXSetVoiceSrc, AXVoice* voice, const AXSampleRateConversionState* src);
EXPORT_FUNC_C(AXSrcRatioError, AXSetVoiceSrcRatio, AXVoice* voice, f32 ratio);
EXPORT_FUNC_C(void, AXSetVoiceAdpcmLoop, AXVoice* voice, const AXAdpcmLoopData* adpcmloop);
EXPORT_FUNC_C(void, AXSetVoiceLpf, AXVoice* voice, const AXLowPassFilter* lpf);
EXPORT_FUNC_C(void, AXSetVoiceLpfCoefs, AXVoice* voice, u16 a0, u16 b0);
EXPORT_FUNC_C(void, AXSetVoiceBiquad, AXVoice* voice, const AXBiquadFilter* biquad);
EXPORT_FUNC_C(void, AXSetVoiceBiquadCoefs, AXVoice* voice, u16 b0, u16 b1, u16 b2, u16 a1, u16 a2);
EXPORT_FUNC_C(AXError, AXSetVoiceDeviceMix, AXVoice* voice, AXDeviceType device, u32 id, AXChannelMix* mix);
EXPORT_FUNC_C(void, AXSetMaxVoices, u32 num);
EXPORT_FUNC_C(void, AXSetVoiceRmtOn, AXVoice* voice, AXVoiceRemoteState on);
EXPORT_FUNC_C(void, AXSetVoiceRmtSrc, AXVoice* voice, const AXRemoteSampleRateConversionState* src);
EXPORT_FUNC_C(void, AXSetVoiceRmtIIR, AXVoice* voice, const AXRemoteFilter* iir);
EXPORT_FUNC_C(void, AXSetVoiceRmtIIRCoefs, AXVoice* voice, AXFilterType type, ...);
EXPORT_FUNC_C(s32, AXRmtGetSamplesLeft, void);
EXPORT_FUNC_C(s32, AXRmtGetSamples, s32 chan, s16* buffer, s32 samples);
EXPORT_FUNC_C(s32, AXRmtAdvancePtr, s32 samples);
EXPORT_FUNC_C(u32, AXCheckVoiceOffsets, const AXVoiceOffsets* maddr);
EXPORT_FUNC_C(void, AXSetVoiceMix, AXVoice* voice, const AXVoiceMix* mix);
EXPORT_FUNC_C(void, AXSetVoiceItdOn, AXVoice* voice);
EXPORT_FUNC_C(void, AXSetVoiceItdTarget, AXVoice* voice, u16 lShift, u16 rShift);
EXPORT_FUNC_C(AXError, AXSetVoiceInitialTimeDelay, AXVoice* voice, u16 timeDelay);

EXPORT_FUNC_C(AXError, AXAcquireMultiVoice, u32 priority, AXVoiceCallbackEx callback, u32 userContext, AXDspAdpcmHeader* mdsp, AXMultiVoice** mvp);
EXPORT_FUNC_C(void, AXFreeMultiVoice, AXMultiVoice* multiVoice);
EXPORT_FUNC_C(void, AXSetMultiVoicePriority, AXMultiVoice* multiVoice, u32 priority);
EXPORT_FUNC_C(void, AXSetMultiVoiceSrcType, AXMultiVoice* multiVoice, AXSrcType type);
EXPORT_FUNC_C(void, AXSetMultiVoiceState, AXMultiVoice* multiVoice, AXVoiceState state);
EXPORT_FUNC_C(void, AXSetMultiVoiceType, AXMultiVoice* multiVoice, AXVoiceType type);
EXPORT_FUNC_C(void, AXSetMultiVoiceVe, AXMultiVoice* multiVoice, const AXVolumeEnvelope* ve);
EXPORT_FUNC_C(void, AXSetMultiVoiceVeDelta, AXMultiVoice* multiVoice, s16 delta);
EXPORT_FUNC_C(void, AXSetMultiVoiceOffsets, AXMultiVoice* multiVoice, AXVoiceOffsets* offsets);
EXPORT_FUNC_C(void, AXSetMultiVoiceLoop, AXMultiVoice* multiVoice, AXLoopFlag loop);
EXPORT_FUNC_C(void, AXSetMultiVoiceAdpcm, AXMultiVoice* multiVoice, AXDspAdpcmHeader* data);
EXPORT_FUNC_C(void, AXSetMultiVoiceSrc, AXMultiVoice* multiVoice, const AXSampleRateConversionState* src);
EXPORT_FUNC_C(AXSrcRatioError, AXSetMultiVoiceSrcRatio, AXMultiVoice* multiVoice, f32 ratio);
EXPORT_FUNC_C(void, AXSetMultiVoiceAdpcmLoop, AXMultiVoice* multiVoice, AXAdpcmLoopData* loops);
EXPORT_FUNC_C(void, AXSetMultiVoiceLpf, AXMultiVoice* multiVoice, const AXLowPassFilter* lpf);
EXPORT_FUNC_C(void, AXSetMultiVoiceLpfCoefs, AXMultiVoice* multiVoice, u16 a0, u16 b0);
EXPORT_FUNC_C(void, AXSetMultiVoiceBiquad, AXMultiVoice* multiVoice, const AXBiquadFilter* biquad);
EXPORT_FUNC_C(void, AXSetMultiVoiceBiquadCoefs, AXMultiVoice* multiVoice, u16 b0, u16 b1, u16 b2, u16 a1, u16 a2);
EXPORT_FUNC_C(AXMixerSelect, AXSetMultiVoiceRenderer, AXMultiVoice* multiVoice, AXMixerSelect mixerSelect);
EXPORT_FUNC_C(AXMixerSelect, AXGetMultiVoiceRenderer, AXMultiVoice* multiVoice);
EXPORT_FUNC_C(void, AXSetMultiVoiceLoopOffset, AXMultiVoice* multiVoice, u32 offset);
EXPORT_FUNC_C(void, AXSetMultiVoiceEndOffset, AXMultiVoice* multiVoice, u32 offset);
EXPORT_FUNC_C(void, AXSetMultiVoiceCurrentOffset, AXMultiVoice* multiVoice, u32 offset);
EXPORT_FUNC_C(void, AXGetMultiVoiceOffsets, AXMultiVoice* multiVoice, AXVoiceOffsets* addr);
EXPORT_FUNC_C(bool, AXIsMultiVoiceRunning, AXMultiVoice* multiVoice);
EXPORT_FUNC_C(AXError, AXSetMultiVoiceDeviceMix, AXMultiVoice* multiVoice, AXDeviceType device, u32 id, AXBusType bus, u16 vol, s16 volDelta);
EXPORT_FUNC_C(AXError, AXGetMultiVoiceReformatBufferSize, u32 format, u32 numChans, u32 numBytes, u32* size);

EXPORT_FUNC_C(u32, __AXGetMixMode, void);

EXPORT_FUNC_C(SYSError, SYSGetVodArgs, SYSVodArgs* args);
EXPORT_FUNC_C(SYSError, SYSGetArguments, SYSArgSlot* sysArgSlot, SYSCallerData* caller);
EXPORT_FUNC_C(bool, SYSCheckSystemApplicationExists, SYSCheckableSystemApplicationID id);
EXPORT_FUNC_C(bool, SYSCheckTitleExists, OSTitleID titleId);

EXPORT_FUNC_C(SYSError, SYSRelaunchTitle, u32 argc, char** argv);
EXPORT_FUNC_C(SYSError, SYSLaunchTitle, OSTitleID titleId);
EXPORT_FUNC_C(SYSError, SYSLaunchMenu, void);
EXPORT_FUNC_C(SYSError, SYSLaunchAccount, const SYSAccountArgsIn* args);
EXPORT_FUNC_C(SYSError, SYSLaunchSettings, const SYSSettingsArgsIn* args);
EXPORT_FUNC_C(SYSError, SYSSwitchToBrowser, const SYSBrowserArgsIn* args);
EXPORT_FUNC_C(SYSError, SYSSwitchToBrowserForCallbackURL, const SYSBrowserArgsInForCallbackURL* args);
EXPORT_FUNC_C(SYSError, SYSSwitchToEManual, void);
EXPORT_FUNC_C(SYSError, SYSSwitchToEShop, const SYSEShopArgsIn* args);
EXPORT_FUNC_C(SYSError, SYSSwitchToEShopAocList, const SYSStandardArgsIn* args);
EXPORT_FUNC_C(SYSError, SYSSwitchToEShopTicketList, const SYSStandardArgsIn* args);
EXPORT_FUNC_C(SYSError, SYSSwitchToSyncControllerOnHBM, void);

EXPORT_FUNC_C(void, VPADInit, void);
EXPORT_FUNC_C(void, VPADShutdown, void);

EXPORT_FUNC_C(s32, VPADRead, VPADChannel chan, VPADStatus* samplingBufs, u32 length, VPADReadError* err);

EXPORT_FUNC_C(void, VPADSetAccParam, VPADChannel chan, f32 playRadius, f32 sensitivity);
EXPORT_FUNC_C(void, VPADGetAccParam, VPADChannel chan, f32* playRadius, f32* sensitivity);

EXPORT_FUNC_C(void, VPADSetBtnRepeat, VPADChannel chan, f32 delaySec, f32 pulseSec);

EXPORT_FUNC_C(void, VPADEnableStickCrossClamp, VPADChannel chan);
EXPORT_FUNC_C(void, VPADDisableStickCrossClamp, VPADChannel chan);
EXPORT_FUNC_C(void, VPADSetLStickClampThreshold, VPADChannel chan, s32 max, s32 min);
EXPORT_FUNC_C(void, VPADSetRStickClampThreshold, VPADChannel chan, s32 max, s32 min);
EXPORT_FUNC_C(void, VPADGetLStickClampThreshold, VPADChannel chan, s32* max, s32* min);
EXPORT_FUNC_C(void, VPADGetRStickClampThreshold, VPADChannel chan, s32* max, s32* min);
EXPORT_FUNC_C(void, VPADSetStickOrigin, VPADChannel chan);
EXPORT_FUNC_C(void, VPADDisableLStickZeroClamp, VPADChannel chan);
EXPORT_FUNC_C(void, VPADDisableRStickZeroClamp, VPADChannel chan);
EXPORT_FUNC_C(void, VPADEnableLStickZeroClamp, VPADChannel chan);
EXPORT_FUNC_C(void, VPADEnableRStickZeroClamp, VPADChannel chan);
EXPORT_FUNC_C(void, VPADSetCrossStickEmulationParamsL, VPADChannel chan, f32 rotDeg, f32 xyDeg, f32 radius);
EXPORT_FUNC_C(void, VPADSetCrossStickEmulationParamsR, VPADChannel chan, f32 rotDeg, f32 xyDeg, f32 radius);
EXPORT_FUNC_C(void, VPADGetCrossStickEmulationParamsL, VPADChannel chan, f32* rotDeg, f32* xyDeg, f32* radius);
EXPORT_FUNC_C(void, VPADGetCrossStickEmulationParamsR, VPADChannel chan, f32* rotDeg, f32* xyDeg, f32* radius);

EXPORT_FUNC_C(VPADSamplingCallback, VPADSetSamplingCallback, VPADChannel chan, VPADSamplingCallback callback);

EXPORT_FUNC_C(void, VPADSetAccPlayMode, VPADChannel chan, VPADPlayMode mode);
EXPORT_FUNC_C(VPADPlayMode, VPADGetAccPlayMode, VPADChannel chan);

EXPORT_FUNC_C(void, VPADSetButtonProcMode, VPADChannel chan, VPADButtonProcMode mode);
EXPORT_FUNC_C(VPADButtonProcMode, VPADGetButtonProcMode, VPADChannel chan);

EXPORT_FUNC_C(void, VPADSetGyroAngle, VPADChannel chan, f32 ax, f32 ay, f32 az);
EXPORT_FUNC_C(void, VPADSetGyroDirection, VPADChannel chan, VPADDir* dir);
EXPORT_FUNC_C(void, VPADSetGyroDirectionMag, VPADChannel chan, f32 mag);
EXPORT_FUNC_C(void, VPADSetGyroMagnification, VPADChannel chan, f32 pitch, f32 yaw, f32 roll);

EXPORT_FUNC_C(void, VPADEnableGyroZeroPlay, VPADChannel chan);
EXPORT_FUNC_C(void, VPADEnableGyroDirRevise, VPADChannel chan);
EXPORT_FUNC_C(void, VPADEnableGyroAccRevise, VPADChannel chan);

EXPORT_FUNC_C(void, VPADDisableGyroZeroPlay, VPADChannel chan);
EXPORT_FUNC_C(void, VPADDisableGyroDirRevise, VPADChannel chan);
EXPORT_FUNC_C(void, VPADDisableGyroAccRevise, VPADChannel chan);

EXPORT_FUNC_C(f32, VPADIsEnableGyroZeroPlay, VPADChannel chan);
EXPORT_FUNC_C(f32, VPADIsEnableGyroZeroDrift, VPADChannel chan);
EXPORT_FUNC_C(f32, VPADIsEnableGyroDirRevise, VPADChannel chan);
EXPORT_FUNC_C(f32, VPADIsEnableGyroAccRevise, VPADChannel chan);

EXPORT_FUNC_C(void, VPADSetGyroZeroPlayParam, VPADChannel chan, f32 radius);
EXPORT_FUNC_C(void, VPADSetGyroDirReviseParam, VPADChannel chan, f32 revisePw);
EXPORT_FUNC_C(void, VPADSetGyroAccReviseParam, VPADChannel chan, f32 revisePw, f32 reviseRange);
EXPORT_FUNC_C(void, VPADSetGyroDirReviseBase, VPADChannel chan, VPADDir* base);

EXPORT_FUNC_C(void, VPADGetGyroZeroPlayParam, VPADChannel chan, f32* radius);
EXPORT_FUNC_C(void, VPADGetGyroDirReviseParam, VPADChannel chan, f32* revisePw);
EXPORT_FUNC_C(void, VPADGetGyroAccReviseParam, VPADChannel chan, f32* revisePw, f32* reviseRange);

EXPORT_FUNC_C(void, VPADInitGyroZeroPlayParam, VPADChannel chan);
EXPORT_FUNC_C(void, VPADInitGyroDirReviseParam, VPADChannel chan);
EXPORT_FUNC_C(void, VPADInitGyroAccReviseParam, VPADChannel chan);

EXPORT_FUNC_C(void, VPADInitGyroZeroDriftMode, VPADChannel chan);
EXPORT_FUNC_C(void, VPADSetGyroZeroDriftMode, VPADChannel chan, VPADGyroZeroDriftMode mode);
EXPORT_FUNC_C(void, VPADGetGyroZeroDriftMode, VPADChannel chan, VPADGyroZeroDriftMode* mode);

EXPORT_FUNC_C(s16, VPADCalcTPCalibrationParam, VPADTPCalibrationParam* param, u16 rawX1, u16 rawY1, u16 x1, u16 y1, u16 rawX2, u16 rawY2, u16 x2, u16 y2);
EXPORT_FUNC_C(void, VPADSetTPCalibrationParam, VPADChannel chan, const VPADTPCalibrationParam param);
EXPORT_FUNC_C(void, VPADGetTPCalibrationParam, VPADChannel chan, VPADTPCalibrationParam* param);
EXPORT_FUNC_C(void, VPADGetTPCalibratedPoint, VPADChannel chan, VPADTPData* disp, const VPADTPData* raw);
EXPORT_FUNC_C(void, VPADGetTPCalibratedPointEx, VPADChannel chan, VPADTPResolution tpReso, VPADTPData* disp, const VPADTPData* raw);

EXPORT_FUNC_C(s32, VPADControlMotor, VPADChannel chan, u8* pattern, u8 length);
EXPORT_FUNC_C(void, VPADStopMotor, VPADChannel chan);

EXPORT_FUNC_C(s32, VPADSetSensorBar, VPADChannel chan, bool on);

EXPORT_FUNC_C(s32, VPADSetLcdMode, VPADChannel chan, VPADLcdMode mode);
EXPORT_FUNC_C(s32, VPADGetLcdMode, VPADChannel chan, VPADLcdMode* mode);

EXPORT_FUNC_C(u8, VPADGetTVMenuStatus, VPADChannel chan);

EXPORT_FUNC_C(f32, VPADIsStartedGyroMagRevise, VPADChannel chan);
EXPORT_FUNC_C(void, VPADStartGyroMagRevise, VPADChannel chan);
EXPORT_FUNC_C(void, VPADStopGyroMagRevise, VPADChannel chan);

EXPORT_FUNC_C(void, VPADSetGyroMagReviseParam, VPADChannel chan, f32 revisePw, f32 playAngle);
EXPORT_FUNC_C(void, VPADGetGyroMagReviseParam, VPADChannel chan, f32* revisePw, f32* playAngle);

EXPORT_FUNC_C(const char *, zlibVersion, void);
EXPORT_FUNC_C(uLong, zlibCompileFlags, void);

EXPORT_FUNC_C(int, deflateInit_, z_streamp strm, int level, const char *version, int stream_size);
EXPORT_FUNC_C(int, deflateInit2_, z_streamp strm, int  level, int  method, int windowBits, int memLevel, int strategy, const char *version, int stream_size);
EXPORT_FUNC_C(int, deflate, z_streamp strm, int flush);
EXPORT_FUNC_C(int, deflateEnd, z_streamp strm);
EXPORT_FUNC_C(int, deflateSetDictionary, z_streamp strm, const Bytef *dictionary, uInt  dictLength);
EXPORT_FUNC_C(int, deflateCopy, z_streamp dest, z_streamp source);
EXPORT_FUNC_C(int, deflateReset, z_streamp strm);
EXPORT_FUNC_C(int, deflateParams, z_streamp strm, int level, int strategy);
EXPORT_FUNC_C(int, deflateTune, z_streamp strm, int good_length, int max_lazy, int nice_length, int max_chain);
EXPORT_FUNC_C(uLong, deflateBound, z_streamp strm, uLong sourceLen);
EXPORT_FUNC_C(int, deflatePrime, z_streamp strm, int bits, int value);
EXPORT_FUNC_C(int, deflateSetHeader, z_streamp strm, gz_headerp head);

EXPORT_FUNC_C(int, inflateInit_, z_streamp strm, const char *version, int stream_size);
EXPORT_FUNC_C(int, inflateInit2_, z_streamp strm, int  windowBits, const char *version, int stream_size);
EXPORT_FUNC_C(int, inflateBackInit_, z_streamp strm, int windowBits, unsigned char FAR *window, const char *version, int stream_size);
EXPORT_FUNC_C(int, inflate, z_streamp strm, int flush);
EXPORT_FUNC_C(int, inflateEnd, z_streamp strm);
EXPORT_FUNC_C(int, inflateSetDictionary, z_streamp strm, const Bytef *dictionary, uInt  dictLength);
EXPORT_FUNC_C(int, inflateSync, z_streamp strm);
EXPORT_FUNC_C(int, inflateCopy, z_streamp dest, z_streamp source);
EXPORT_FUNC_C(int, inflateReset, z_streamp strm);
EXPORT_FUNC_C(int, inflateReset2, z_streamp strm, int windowBits);
EXPORT_FUNC_C(int, inflatePrime, z_streamp strm, int bits, int value);
EXPORT_FUNC_C(long, inflateMark, z_streamp strm);
EXPORT_FUNC_C(int, inflateGetHeader, z_streamp strm, gz_headerp head);
EXPORT_FUNC_C(int, inflateBack, z_streamp strm, in_func in, void FAR *in_desc, out_func out, void FAR *out_desc);
EXPORT_FUNC_C(int, inflateBackEnd, z_streamp strm);

EXPORT_FUNC_C(int, compress, Bytef *dest,   uLongf *destLen, const Bytef *source, uLong sourceLen);
EXPORT_FUNC_C(int, compress2, Bytef *dest,   uLongf *destLen, const Bytef *source, uLong sourceLen, int level);
EXPORT_FUNC_C(uLong, compressBound, uLong sourceLen);
EXPORT_FUNC_C(int, uncompress, Bytef *dest,   uLongf *destLen, const Bytef *source, uLong sourceLen);

EXPORT_FUNC_C(uLong, adler32, uLong adler, const Bytef *buf, uInt len);
EXPORT_FUNC_C(uLong, crc32  , uLong crc, const Bytef *buf, uInt len);

static OSModuleHandle coreinitHandle = NULL;
static OSModuleHandle cameraHandle = NULL;
static OSModuleHandle dmaeHandle = NULL;
static OSModuleHandle gx2Handle = NULL;
static OSModuleHandle h264Handle = NULL;
static OSModuleHandle micHandle = NULL;
static OSModuleHandle nio_profHandle = NULL;
static OSModuleHandle nlibcurlHandle = NULL;
static OSModuleHandle nsyshidHandle = NULL;
static OSModuleHandle nsysnetHandle = NULL;
static OSModuleHandle padscoreHandle = NULL;
static OSModuleHandle proc_uiHandle = NULL;
static OSModuleHandle sndcore2Handle = NULL;
static OSModuleHandle sysappHandle = NULL;
static OSModuleHandle vpadHandle = NULL;
static OSModuleHandle zlib125Handle = NULL;

void __wiiu_dynlib_install() {
    EXPORT_SET(*(void**) 0x00801500, OSDynLoad_Acquire);
    EXPORT_SET(*(void**) 0x00801504, OSDynLoad_FindExport);

    if(OSDynLoad_Acquire("coreinit.rpl", &coreinitHandle) == OS_DYNLOAD_ERROR_NONE) {
        // Find OSFatal first so we can report missing functions in the future.
        EXPORT_FIND_FUNC(coreinitHandle, OSFatal);

        EXPORT_FIND_FUNC(coreinitHandle, DCInvalidateRange);
        EXPORT_FIND_FUNC(coreinitHandle, DCFlushRange);
        EXPORT_FIND_FUNC(coreinitHandle, DCStoreRange);
        EXPORT_FIND_FUNC(coreinitHandle, DCFlushRangeNoSync);
        EXPORT_FIND_FUNC(coreinitHandle, DCStoreRangeNoSync);
        EXPORT_FIND_FUNC(coreinitHandle, DCZeroRange);
        EXPORT_FIND_FUNC(coreinitHandle, DCTouchRange);
        EXPORT_FIND_FUNC(coreinitHandle, DCCoreFlushAll);

        EXPORT_FIND_FUNC(coreinitHandle, ICInvalidateRange);

        EXPORT_FIND_FUNC(coreinitHandle, LCHardwareIsAvailable);
        EXPORT_FIND_FUNC(coreinitHandle, LCGetMaxSize);
        EXPORT_FIND_FUNC(coreinitHandle, LCGetUnallocated);
        EXPORT_FIND_FUNC(coreinitHandle, LCGetAllocatableSize);
        EXPORT_FIND_FUNC(coreinitHandle, LCAlloc);
        EXPORT_FIND_FUNC(coreinitHandle, LCDealloc);
        EXPORT_FIND_FUNC(coreinitHandle, LCEnableDMA);
        EXPORT_FIND_FUNC(coreinitHandle, LCDisableDMA);
        EXPORT_FIND_FUNC(coreinitHandle, LCIsDMAEnabled);
        EXPORT_FIND_FUNC(coreinitHandle, LCLoadDMABlocks);
        EXPORT_FIND_FUNC(coreinitHandle, LCStoreDMABlocks);
        EXPORT_FIND_FUNC(coreinitHandle, LCGetDMAQueueLength);
        EXPORT_FIND_FUNC(coreinitHandle, LCWaitDMAQueue);

        EXPORT_FIND_FUNC(coreinitHandle, DisassemblePPCOpcode);
        EXPORT_FIND_FUNC(coreinitHandle, DisassemblePPCRange);

        EXPORT_FIND_FUNC(coreinitHandle, ENVGetEnvironmentVariable);

        EXPORT_FIND_FUNC(coreinitHandle, FSInit);
        EXPORT_FIND_FUNC(coreinitHandle, FSShutdown);

        EXPORT_FIND_FUNC(coreinitHandle, FSGetClientNum);
        EXPORT_FIND_FUNC(coreinitHandle, FSAddClient);
        EXPORT_FIND_FUNC(coreinitHandle, FSDelClient);

        EXPORT_FIND_FUNC(coreinitHandle, FSInitCmdBlock);
        EXPORT_FIND_FUNC(coreinitHandle, FSCancelCommand);
        EXPORT_FIND_FUNC(coreinitHandle, FSCancelAllCommands);
        EXPORT_FIND_FUNC(coreinitHandle, FSSetUserData);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetUserData);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetFSMessage);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetCurrentCmdBlock);
        EXPORT_FIND_FUNC(coreinitHandle, FSSetCmdPriority);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetCmdPriority);

        EXPORT_FIND_FUNC(coreinitHandle, FSGetVolumeState);
        EXPORT_FIND_FUNC(coreinitHandle, FSSetStateChangeNotification);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetAsyncResult);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetStateChangeInfo);

        EXPORT_FIND_FUNC(coreinitHandle, FSGetMountSource);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetMountSourceAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetMountSourceNext);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetMountSourceNextAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSMount);
        EXPORT_FIND_FUNC(coreinitHandle, FSMountAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSUnmount);
        EXPORT_FIND_FUNC(coreinitHandle, FSUnmountAsync);

        EXPORT_FIND_FUNC(coreinitHandle, FSGetCwd);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetCwdAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSChangeDir);
        EXPORT_FIND_FUNC(coreinitHandle, FSChangeDirAsync);

        EXPORT_FIND_FUNC(coreinitHandle, FSOpenFile);
        EXPORT_FIND_FUNC(coreinitHandle, FSOpenFileAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSCloseFile);
        EXPORT_FIND_FUNC(coreinitHandle, FSCloseFileAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSReadFile);
        EXPORT_FIND_FUNC(coreinitHandle, FSReadFileAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSWriteFile);
        EXPORT_FIND_FUNC(coreinitHandle, FSWriteFileAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSReadFileWithPos);
        EXPORT_FIND_FUNC(coreinitHandle, FSReadFileWithPosAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSWriteFileWithPos);
        EXPORT_FIND_FUNC(coreinitHandle, FSWriteFileWithPosAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSAppendFile);
        EXPORT_FIND_FUNC(coreinitHandle, FSAppendFileAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSTruncateFile);
        EXPORT_FIND_FUNC(coreinitHandle, FSTruncateFileAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSFlushFile);
        EXPORT_FIND_FUNC(coreinitHandle, FSFlushFileAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetPosFile);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetPosFileAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSSetPosFile);
        EXPORT_FIND_FUNC(coreinitHandle, FSSetPosFileAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetStatFile);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetStatFileAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSIsEof);
        EXPORT_FIND_FUNC(coreinitHandle, FSIsEofAsync);

        EXPORT_FIND_FUNC(coreinitHandle, FSOpenDir);
        EXPORT_FIND_FUNC(coreinitHandle, FSOpenDirAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSCloseDir);
        EXPORT_FIND_FUNC(coreinitHandle, FSCloseDirAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSReadDir);
        EXPORT_FIND_FUNC(coreinitHandle, FSReadDirAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSRewindDir);
        EXPORT_FIND_FUNC(coreinitHandle, FSRewindDirAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSMakeDir);
        EXPORT_FIND_FUNC(coreinitHandle, FSMakeDirAsync);

        EXPORT_FIND_FUNC(coreinitHandle, FSRemove);
        EXPORT_FIND_FUNC(coreinitHandle, FSRemoveAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSRename);
        EXPORT_FIND_FUNC(coreinitHandle, FSRenameAsync);

        EXPORT_FIND_FUNC(coreinitHandle, FSMakeQuota);
        EXPORT_FIND_FUNC(coreinitHandle, FSMakeQuotaAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSRemoveQuota);
        EXPORT_FIND_FUNC(coreinitHandle, FSRemoveQuotaAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSFlushQuota);
        EXPORT_FIND_FUNC(coreinitHandle, FSFlushQuotaAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSRollbackQuota);
        EXPORT_FIND_FUNC(coreinitHandle, FSRollbackQuotaAsync);

        EXPORT_FIND_FUNC(coreinitHandle, FSGetStat);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetStatAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetFreeSpaceSize);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetFreeSpaceSizeAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetDirSize);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetDirSizeAsync);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetEntryNum);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetEntryNumAsync);

        EXPORT_FIND_FUNC(coreinitHandle, FSGetLastErrorCodeForViewer);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetErrorCodeForViewer);
        EXPORT_FIND_FUNC(coreinitHandle, FSTimeToCalendarTime);

        EXPORT_FIND_FUNC(coreinitHandle, FSGetLastError);
        EXPORT_FIND_FUNC(coreinitHandle, FSSetEmulatedError);
        EXPORT_FIND_FUNC(coreinitHandle, FSGetEmulatedError);

        EXPORT_FIND_FUNC(coreinitHandle, IMEnableDim);
        EXPORT_FIND_FUNC(coreinitHandle, IMDisableDim);
        EXPORT_FIND_FUNC(coreinitHandle, IMIsDimEnabled);
        EXPORT_FIND_FUNC(coreinitHandle, IMGetDimPeriod);
        EXPORT_FIND_FUNC(coreinitHandle, IMGetTimeBeforeDimming);

        EXPORT_FIND_FUNC(coreinitHandle, IMGetDimEnableTV);
        EXPORT_FIND_FUNC(coreinitHandle, IMGetDimEnableDRC);
        EXPORT_FIND_FUNC(coreinitHandle, IMSetDimEnableTV);
        EXPORT_FIND_FUNC(coreinitHandle, IMSetDimEnableDRC);

        EXPORT_FIND_FUNC(coreinitHandle, IMEnableAPD);
        EXPORT_FIND_FUNC(coreinitHandle, IMDisableAPD);
        EXPORT_FIND_FUNC(coreinitHandle, IMIsAPDEnabled);
        EXPORT_FIND_FUNC(coreinitHandle, IMIsAPDEnabledBySysSettings);
        EXPORT_FIND_FUNC(coreinitHandle, IMGetAPDPeriod);
        EXPORT_FIND_FUNC(coreinitHandle, IMGetTimeBeforeAPD);

        EXPORT_FIND_FUNC(coreinitHandle, IM_GetParameters);

        EXPORT_FIND_FUNC(coreinitHandle, IOS_Open);
        EXPORT_FIND_FUNC(coreinitHandle, IOS_Close);
        EXPORT_FIND_FUNC(coreinitHandle, IOS_Read);
        EXPORT_FIND_FUNC(coreinitHandle, IOS_Write);
        EXPORT_FIND_FUNC(coreinitHandle, IOS_Seek);
        EXPORT_FIND_FUNC(coreinitHandle, IOS_Ioctl);
        EXPORT_FIND_FUNC(coreinitHandle, IOS_Ioctlv);

        EXPORT_FIND_FUNC(coreinitHandle, MCP_Open);
        EXPORT_FIND_FUNC(coreinitHandle, MCP_Close);
        EXPORT_FIND_FUNC(coreinitHandle, MCP_GetOwnTitleInfo);
        EXPORT_FIND_FUNC(coreinitHandle, MCP_InstallTitleAbort);
        EXPORT_FIND_FUNC(coreinitHandle, MCP_InstallGetInfo);
        EXPORT_FIND_FUNC(coreinitHandle, MCP_InstallTitleAsync);
        EXPORT_FIND_FUNC(coreinitHandle, MCP_InstallGetProgress);
        EXPORT_FIND_FUNC(coreinitHandle, MCP_InstallSetTargetDevice);
        EXPORT_FIND_FUNC(coreinitHandle, MCP_InstallSetTargetUsb);
        EXPORT_FIND_FUNC(coreinitHandle, MCP_GetLastRawError);

        EXPORT_FIND_FUNC(coreinitHandle, MEMFindContainHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMFindParentHeap);

        EXPORT_FIND_FUNC(coreinitHandle, MEMDumpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMCheckHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMSetFillValForHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetFillValForHeap);

        EXPORT_FIND_FUNC(coreinitHandle, MEMInitList);
        EXPORT_FIND_FUNC(coreinitHandle, MEMAppendListObject);
        EXPORT_FIND_FUNC(coreinitHandle, MEMPrependListObject);
        EXPORT_FIND_FUNC(coreinitHandle, MEMInsertListObject);
        EXPORT_FIND_FUNC(coreinitHandle, MEMRemoveListObject);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetNextListObject);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetPrevListObject);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetNthListObject);

        EXPORT_FIND_FUNC(coreinitHandle, CoreInitDefaultHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMCreateUserHeapHandle);
        EXPORT_FIND_DATA(coreinitHandle, MEMAllocFromDefaultHeap);
        EXPORT_FIND_DATA(coreinitHandle, MEMAllocFromDefaultHeapEx);
        EXPORT_FIND_DATA(coreinitHandle, MEMFreeToDefaultHeap);

        EXPORT_FIND_FUNC(coreinitHandle, MEMAllocFromAllocator);
        EXPORT_FIND_FUNC(coreinitHandle, MEMFreeToAllocator);

        EXPORT_FIND_FUNC(coreinitHandle, MEMInitAllocatorForDefaultHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMInitAllocatorForBlockHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMInitAllocatorForExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMInitAllocatorForFrmHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMInitAllocatorForUnitHeap);

        EXPORT_FIND_FUNC(coreinitHandle, MEMGetArena);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetBaseHeapHandle);
        EXPORT_FIND_FUNC(coreinitHandle, MEMSetBaseHeapHandle);

        EXPORT_FIND_FUNC(coreinitHandle, MEMInitBlockHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMAddBlockHeapTracking);
        EXPORT_FIND_FUNC(coreinitHandle, MEMDestroyBlockHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMAllocFromBlockHeapAt);
        EXPORT_FIND_FUNC(coreinitHandle, MEMAllocFromBlockHeapEx);
        EXPORT_FIND_FUNC(coreinitHandle, MEMFreeToBlockHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetTrackingLeftInBlockHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetTotalFreeSizeForBlockHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetAllocatableSizeForBlockHeapEx);

        EXPORT_FIND_FUNC(coreinitHandle, MEMCreateExpHeapEx);
        EXPORT_FIND_FUNC(coreinitHandle, MEMDestroyExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMAllocFromExpHeapEx);
        EXPORT_FIND_FUNC(coreinitHandle, MEMResizeForMBlockExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMFreeToExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetTotalFreeSizeForExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetAllocatableSizeForExpHeapEx);
        EXPORT_FIND_FUNC(coreinitHandle, MEMSetAllocModeForExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetAllocModeForExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMUseMarginOfAlignmentForExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMSetGroupIDForExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetGroupIDForExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMVisitAllocatedForExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetSizeForMBlockExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetGroupIDForMBlockExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetAllocDirForMBlockExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMAdjustExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMCheckExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMCheckForMBlockExpHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMiIsEmptyExpHeap);

        EXPORT_FIND_FUNC(coreinitHandle, MEMCreateFrmHeapEx);
        EXPORT_FIND_FUNC(coreinitHandle, MEMDestroyFrmHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMAllocFromFrmHeapEx);
        EXPORT_FIND_FUNC(coreinitHandle, MEMFreeToFrmHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMGetAllocatableSizeForFrmHeapEx);
        EXPORT_FIND_FUNC(coreinitHandle, MEMRecordStateForFrmHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMFreeByStateToFrmHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMAdjustFrmHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMResizeForMBlockFrmHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMiGetFreeStartForFrmHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMiGetFreeEndForFrmHeap);

        EXPORT_FIND_FUNC(coreinitHandle, MEMCreateUnitHeapEx);
        EXPORT_FIND_FUNC(coreinitHandle, MEMDestroyUnitHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMAllocFromUnitHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMFreeToUnitHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMCountFreeBlockForUnitHeap);
        EXPORT_FIND_FUNC(coreinitHandle, MEMCalcHeapSizeForUnitHeap);

        EXPORT_FIND_FUNC(coreinitHandle, MPInitTaskQ);
        EXPORT_FIND_FUNC(coreinitHandle, MPTermTaskQ);
        EXPORT_FIND_FUNC(coreinitHandle, MPGetTaskQInfo);
        EXPORT_FIND_FUNC(coreinitHandle, MPStartTaskQ);
        EXPORT_FIND_FUNC(coreinitHandle, MPRunTasksFromTaskQ);
        EXPORT_FIND_FUNC(coreinitHandle, MPStopTaskQ);
        EXPORT_FIND_FUNC(coreinitHandle, MPWaitTaskQ);
        EXPORT_FIND_FUNC(coreinitHandle, MPWaitTaskQWithTimeout);
        EXPORT_FIND_FUNC(coreinitHandle, MPEnqueTask);
        EXPORT_FIND_FUNC(coreinitHandle, MPDequeTask);
        EXPORT_FIND_FUNC(coreinitHandle, MPDequeTasks);
        EXPORT_FIND_FUNC(coreinitHandle, MPResetTaskQ);
        EXPORT_FIND_FUNC(coreinitHandle, MPPrintTaskQStats);

        EXPORT_FIND_FUNC(coreinitHandle, MPInitTask);
        EXPORT_FIND_FUNC(coreinitHandle, MPTermTask);
        EXPORT_FIND_FUNC(coreinitHandle, MPGetTaskInfo);
        EXPORT_FIND_FUNC(coreinitHandle, MPRunTask);
        EXPORT_FIND_FUNC(coreinitHandle, MPGetTaskUserData);
        EXPORT_FIND_FUNC(coreinitHandle, MPSetTaskUserData);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetTick);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetTime);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetSystemTick);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetSystemTime);
        EXPORT_FIND_FUNC(coreinitHandle, OSCalendarTimeToTicks);
        EXPORT_FIND_FUNC(coreinitHandle, OSTicksToCalendarTime);
        EXPORT_FIND_FUNC(coreinitHandle, OSWaitMicroseconds);

        EXPORT_FIND_FUNC(coreinitHandle, OSInitThreadQueue);
        EXPORT_FIND_FUNC(coreinitHandle, OSInitThreadQueueEx);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetCurrentThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetDefaultThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSCheckActiveThreads);

        EXPORT_FIND_FUNC(coreinitHandle, OSCreateThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSCreateThreadType);
        EXPORT_FIND_FUNC(coreinitHandle, OSRunThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSExitThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSCancelThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSJoinThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSDetachThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSSleepThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSSleepTicks);
        EXPORT_FIND_FUNC(coreinitHandle, OSWakeupThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSSuspendThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSResumeThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSYieldThread);
        EXPORT_FIND_FUNC(coreinitHandle, OSContinueThread);

        EXPORT_FIND_FUNC(coreinitHandle, OSIsThreadSuspended);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsThreadTerminated);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetActiveThreadLink);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetThreadName);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetThreadName);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetThreadPriority);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetThreadPriority);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetThreadAffinity);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetThreadAffinity);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetThreadSpecific);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetThreadSpecific);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetThreadCoreTime);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetThreadRunQuantum);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetThreadCleanupCallback);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetThreadDeallocator);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetUserStackPointer);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetThreadStackUsage);
        EXPORT_FIND_FUNC(coreinitHandle, OSClearThreadStackUsage);
        EXPORT_FIND_FUNC(coreinitHandle, OSCheckThreadStackUsage);
        EXPORT_FIND_FUNC(coreinitHandle, OSClearStack);

        EXPORT_FIND_FUNC(coreinitHandle, OSTestThreadCancel);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetThreadCancelState);

        EXPORT_FIND_FUNC(coreinitHandle, OSIsSchedulerLocked);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetCoreCount);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetCoreId);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetMainCoreId);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsMainCore);

        EXPORT_FIND_FUNC(coreinitHandle, OSInitAlarmQueue);
        EXPORT_FIND_FUNC(coreinitHandle, OSInitAlarmQueueEx);

        EXPORT_FIND_FUNC(coreinitHandle, OSCreateAlarm);
        EXPORT_FIND_FUNC(coreinitHandle, OSCreateAlarmEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetAlarm);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetPeriodicAlarm);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetAlarmTag);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetAlarmUserData);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetAlarmUserData);
        EXPORT_FIND_FUNC(coreinitHandle, OSCancelAlarm);
        EXPORT_FIND_FUNC(coreinitHandle, OSCancelAlarms);
        EXPORT_FIND_FUNC(coreinitHandle, OSWaitAlarm);

        EXPORT_FIND_FUNC(coreinitHandle, OSAddAtomic);
        EXPORT_FIND_FUNC(coreinitHandle, OSOrAtomic);
        EXPORT_FIND_FUNC(coreinitHandle, OSAndAtomic);
        EXPORT_FIND_FUNC(coreinitHandle, OSXorAtomic);
        EXPORT_FIND_FUNC(coreinitHandle, OSSwapAtomic);
        EXPORT_FIND_FUNC(coreinitHandle, OSCompareAndSwapAtomic);
        EXPORT_FIND_FUNC(coreinitHandle, OSCompareAndSwapAtomicEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSTestAndSetAtomic);
        EXPORT_FIND_FUNC(coreinitHandle, OSTestAndClearAtomic);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetAtomic64);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetAtomic64);
        EXPORT_FIND_FUNC(coreinitHandle, OSAddAtomic64);
        EXPORT_FIND_FUNC(coreinitHandle, OSOrAtomic64);
        EXPORT_FIND_FUNC(coreinitHandle, OSAndAtomic64);
        EXPORT_FIND_FUNC(coreinitHandle, OSXorAtomic64);
        EXPORT_FIND_FUNC(coreinitHandle, OSSwapAtomic64);
        EXPORT_FIND_FUNC(coreinitHandle, OSCompareAndSwapAtomic64);
        EXPORT_FIND_FUNC(coreinitHandle, OSCompareAndSwapAtomicEx64);
        EXPORT_FIND_FUNC(coreinitHandle, OSTestAndSetAtomic64);
        EXPORT_FIND_FUNC(coreinitHandle, OSTestAndClearAtomic64);

        EXPORT_FIND_FUNC(coreinitHandle, OSIsAddressRangeDCValid);

        EXPORT_FIND_FUNC(coreinitHandle, OSMemoryBarrier);
        EXPORT_FIND_FUNC(coreinitHandle, OSCoherencyBarrier);

        EXPORT_FIND_FUNC(coreinitHandle, OSCopyToClipboard);
        EXPORT_FIND_FUNC(coreinitHandle, OSCopyFromClipboard);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetCodegenVirtAddrRange);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetCodegenCore);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetCodegenMode);
        EXPORT_FIND_FUNC(coreinitHandle, OSSwitchSecCodeGenMode);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetSecCodeGenMode);
        EXPORT_FIND_FUNC(coreinitHandle, OSCodegenCopy);

        EXPORT_FIND_FUNC(coreinitHandle, OSInitCond);
        EXPORT_FIND_FUNC(coreinitHandle, OSInitCondEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSWaitCond);
        EXPORT_FIND_FUNC(coreinitHandle, OSSignalCond);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetStackPointer);
        EXPORT_FIND_FUNC(coreinitHandle, OSSwitchStack);

        EXPORT_FIND_FUNC(coreinitHandle, OSSwitchFiber);
        EXPORT_FIND_FUNC(coreinitHandle, OSSwitchFiberEx);

        EXPORT_FIND_FUNC(coreinitHandle, OSSetCurrentContext);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetCurrentContext);
        EXPORT_FIND_FUNC(coreinitHandle, OSSaveContext);
        EXPORT_FIND_FUNC(coreinitHandle, OSLoadContext);
        EXPORT_FIND_FUNC(coreinitHandle, OSClearContext);
        EXPORT_FIND_FUNC(coreinitHandle, OSInitContext);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetCurrentFPUContext);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetCurrentFPUContext);
        EXPORT_FIND_FUNC(coreinitHandle, OSLoadFPUContext);
        EXPORT_FIND_FUNC(coreinitHandle, OSSaveFPUContext);
        EXPORT_FIND_FUNC(coreinitHandle, OSDumpContext);

        EXPORT_FIND_FUNC(coreinitHandle, OSInitCoroutine);
        EXPORT_FIND_FUNC(coreinitHandle, OSLoadCoroutine);
        EXPORT_FIND_FUNC(coreinitHandle, OSSaveCoroutine);
        EXPORT_FIND_FUNC(coreinitHandle, OSSwitchCoroutine);

        EXPORT_FIND_FUNC(coreinitHandle, OSIsDebuggerPresent);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsDebuggerInitialized);

        EXPORT_FIND_FUNC(coreinitHandle, OSReport);
        EXPORT_FIND_FUNC(coreinitHandle, OSVReport);
        EXPORT_FIND_FUNC(coreinitHandle, OSReportWarn);
        EXPORT_FIND_FUNC(coreinitHandle, OSReportInfo);
        EXPORT_FIND_FUNC(coreinitHandle, OSReportVerbose);

        EXPORT_FIND_FUNC(coreinitHandle, OSConsoleWrite);
        EXPORT_FIND_FUNC(coreinitHandle, OSSupressConsoleOutput);

        EXPORT_FIND_FUNC(coreinitHandle, COSWarn);
        EXPORT_FIND_FUNC(coreinitHandle, COSInfo);
        EXPORT_FIND_FUNC(coreinitHandle, COSVerbose);
        EXPORT_FIND_FUNC(coreinitHandle, COSError);
        EXPORT_FIND_FUNC(coreinitHandle, COSVReport);

        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_GetNumberOfRPLs);
        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_GetRPLInfo);

        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_AddNotifyCallback);
        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_DelNotifyCallback);

        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_SetAllocator);
        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_GetAllocator);

        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_SetTLSAllocator);
        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_GetTLSAllocator);

        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_AcquireContainingModule);
        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_Release);
        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_IsModuleLoaded);
        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_GetModuleName);
        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_FindTag);

        EXPORT_FIND_FUNC(coreinitHandle, OSDynLoad_GetLoaderHeapStatistics);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetLastError);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetSymbolName);

        EXPORT_FIND_FUNC(coreinitHandle, OSSetPanicCallback);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetCrashInfo);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetCrashDumpType);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetCrashDumpType);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetCrashDetailLevel);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetCrashDetailLevel);
        EXPORT_FIND_FUNC(coreinitHandle, OSRestartCrashedApp);
        EXPORT_FIND_FUNC(coreinitHandle, OSRebootCrash);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetTimestampLevel);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetTimestampLevel);

        EXPORT_FIND_FUNC(coreinitHandle, OSPanic);

        EXPORT_FIND_FUNC(coreinitHandle, OSInitEvent);
        EXPORT_FIND_FUNC(coreinitHandle, OSInitEventEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSSignalEvent);
        EXPORT_FIND_FUNC(coreinitHandle, OSSignalEventAll);
        EXPORT_FIND_FUNC(coreinitHandle, OSWaitEvent);
        EXPORT_FIND_FUNC(coreinitHandle, OSResetEvent);
        EXPORT_FIND_FUNC(coreinitHandle, OSWaitEventWithTimeout);

        EXPORT_FIND_FUNC(coreinitHandle, OSSetExceptionCallback);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetExceptionCallbackEx);

        EXPORT_FIND_FUNC(coreinitHandle, OSSetDABR);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetIABR);

        EXPORT_FIND_FUNC(coreinitHandle, OSEnableThreadFPUException);
        EXPORT_FIND_FUNC(coreinitHandle, OSEnableAllThreadFPUException);
        EXPORT_FIND_FUNC(coreinitHandle, OSDisableThreadFPUException);
        EXPORT_FIND_FUNC(coreinitHandle, OSDisableAllThreadFPUException);
        EXPORT_FIND_FUNC(coreinitHandle, OSDisableContextFPUException);

        EXPORT_FIND_FUNC(coreinitHandle, OSFastCond_Init);
        EXPORT_FIND_FUNC(coreinitHandle, OSFastCond_Wait);
        EXPORT_FIND_FUNC(coreinitHandle, OSFastCond_Signal);

        EXPORT_FIND_FUNC(coreinitHandle, OSFastMutex_Init);
        EXPORT_FIND_FUNC(coreinitHandle, OSFastMutex_Lock);
        EXPORT_FIND_FUNC(coreinitHandle, OSFastMutex_Unlock);
        EXPORT_FIND_FUNC(coreinitHandle, OSFastMutex_TryLock);

        EXPORT_FIND_FUNC(coreinitHandle, OSReadRegister16);
        EXPORT_FIND_FUNC(coreinitHandle, OSReadRegister32);
        EXPORT_FIND_FUNC(coreinitHandle, OSWriteRegister16);
        EXPORT_FIND_FUNC(coreinitHandle, OSWriteRegister32);

        EXPORT_FIND_FUNC(coreinitHandle, OSEnforceInorderIO);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetOSID);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetConsoleType);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetSecurityLevel);

        EXPORT_FIND_FUNC(coreinitHandle, OSSetInfo);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetInfo);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetSystemInfo);

        EXPORT_FIND_FUNC(coreinitHandle, OSDisableInterrupts);
        EXPORT_FIND_FUNC(coreinitHandle, OSEnableInterrupts);
        EXPORT_FIND_FUNC(coreinitHandle, OSRestoreInterrupts);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsInterruptEnabled);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetTitleID);

        EXPORT_FIND_FUNC(coreinitHandle, OSLaunchTitlev);
        EXPORT_FIND_FUNC(coreinitHandle, OSLaunchTitlel);
        EXPORT_FIND_FUNC(coreinitHandle, OSLaunchTitleByPathv);
        EXPORT_FIND_FUNC(coreinitHandle, OSLaunchTitleByPathl);

        EXPORT_FIND_FUNC(coreinitHandle, OSRestartGame);
        EXPORT_FIND_FUNC(coreinitHandle, OSForceFullRelaunch);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetShutdownReason);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetShutdownFlags);

        EXPORT_FIND_FUNC(coreinitHandle, OSBlockThreadsOnExit);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsBlockThreadsOnExit);

        EXPORT_FIND_FUNC(coreinitHandle, OSRunThreadsOnExit);

        EXPORT_FIND_FUNC(coreinitHandle, OSSavesDone_ReadyToRelease);
        EXPORT_FIND_FUNC(coreinitHandle, OSRequestFastExit);

        EXPORT_FIND_FUNC(coreinitHandle, OSEnableForegroundExit);
        EXPORT_FIND_FUNC(coreinitHandle, OSReleaseForeground);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetForegroundBucket);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetForegroundBucketFreeArea);

        EXPORT_FIND_FUNC(coreinitHandle, OSSendAppSwitchRequest);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetCallArgs);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetArgcArgv);

        EXPORT_FIND_FUNC(coreinitHandle, OSSetScreenCapturePermission);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetScreenCapturePermission);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetScreenCapturePermissionEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetScreenCapturePermissionEx);

        EXPORT_FIND_FUNC(coreinitHandle, OSIsHomeButtonMenuEnabled);
        EXPORT_FIND_FUNC(coreinitHandle, OSEnableHomeButtonMenu);

        EXPORT_FIND_FUNC(coreinitHandle, OSIsColdBoot);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsSelfRefreshBoot);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsNormalBoot);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsECOBoot);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsStandbyBoot);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsOffBoot);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsCompatBoot);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsProdMode);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsECOMode);

        EXPORT_FIND_FUNC(coreinitHandle, OSSendPolicyRequest);

        EXPORT_FIND_FUNC(coreinitHandle, OSAllocVirtAddr);
        EXPORT_FIND_FUNC(coreinitHandle, OSFreeVirtAddr);
        EXPORT_FIND_FUNC(coreinitHandle, OSQueryVirtAddr);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetMapVirtAddrRange);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetDataPhysAddrRange);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetAvailPhysAddrRange);
        EXPORT_FIND_FUNC(coreinitHandle, OSEffectiveToPhysical);

        EXPORT_FIND_FUNC(coreinitHandle, OSMapMemory);
        EXPORT_FIND_FUNC(coreinitHandle, OSUnmapMemory);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetMemBound);
        EXPORT_FIND_FUNC(coreinitHandle, OSSetMemBound);

        EXPORT_FIND_FUNC(coreinitHandle, OSAllocFromSystem);
        EXPORT_FIND_FUNC(coreinitHandle, OSFreeToSystem);
        EXPORT_FIND_FUNC(coreinitHandle, OSIsAddressValid);

        EXPORT_FIND_FUNC(coreinitHandle, OSBlockMove);
        EXPORT_FIND_FUNC(coreinitHandle, OSBlockSet);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetSharedData);

        EXPORT_FIND_FUNC(coreinitHandle, OSIsEnabledOverlayArenaDev);
        EXPORT_FIND_FUNC(coreinitHandle, OSEnableOverlayArenaDev);
        EXPORT_FIND_FUNC(coreinitHandle, OSEnableOverlayArenaWithTimeoutDev);
        EXPORT_FIND_FUNC(coreinitHandle, OSDisableOverlayArenaDev);
        EXPORT_FIND_FUNC(coreinitHandle, OSDisableOverlayArenaWithTimeoutDev);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetOverlayArenaRangeDev);

        EXPORT_FIND_FUNC(coreinitHandle, OSInitMessageQueue);
        EXPORT_FIND_FUNC(coreinitHandle, OSInitMessageQueueEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSSendMessage);
        EXPORT_FIND_FUNC(coreinitHandle, OSReceiveMessage);
        EXPORT_FIND_FUNC(coreinitHandle, OSPeekMessage);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetSystemMessageQueue);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetDefaultAppIOQueue);

        EXPORT_FIND_FUNC(coreinitHandle, OSInitMutex);
        EXPORT_FIND_FUNC(coreinitHandle, OSInitMutexEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSLockMutex);
        EXPORT_FIND_FUNC(coreinitHandle, OSUnlockMutex);
        EXPORT_FIND_FUNC(coreinitHandle, OSTryLockMutex);

        EXPORT_FIND_FUNC(coreinitHandle, OSGetBootPMFlags);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetLastPMState);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetCurrentPMState);

        EXPORT_FIND_FUNC(coreinitHandle, OSSetPerformanceMonitor);

        EXPORT_FIND_FUNC(coreinitHandle, OSInitRendezvous);
        EXPORT_FIND_FUNC(coreinitHandle, OSWaitRendezvous);
        EXPORT_FIND_FUNC(coreinitHandle, OSWaitRendezvousWithTimeout);

        EXPORT_FIND_FUNC(coreinitHandle, OSScreenInit);
        EXPORT_FIND_FUNC(coreinitHandle, OSScreenShutdown);
        EXPORT_FIND_FUNC(coreinitHandle, OSScreenEnableEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSScreenGetBufferSizeEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSScreenSetBufferEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSScreenFlipBuffersEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSScreenClearBufferEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSScreenPutPixelEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSScreenPutFontEx);

        EXPORT_FIND_FUNC(coreinitHandle, OSInitSemaphore);
        EXPORT_FIND_FUNC(coreinitHandle, OSInitSemaphoreEx);
        EXPORT_FIND_FUNC(coreinitHandle, OSWaitSemaphore);
        EXPORT_FIND_FUNC(coreinitHandle, OSTryWaitSemaphore);
        EXPORT_FIND_FUNC(coreinitHandle, OSSignalSemaphore);
        EXPORT_FIND_FUNC(coreinitHandle, OSGetSemaphoreCount);

        EXPORT_FIND_FUNC(coreinitHandle, OSInitSpinLock);
        EXPORT_FIND_FUNC(coreinitHandle, OSAcquireSpinLock);
        EXPORT_FIND_FUNC(coreinitHandle, OSTryAcquireSpinLock);
        EXPORT_FIND_FUNC(coreinitHandle, OSTryAcquireSpinLockWithTimeout);
        EXPORT_FIND_FUNC(coreinitHandle, OSReleaseSpinLock);

        EXPORT_FIND_FUNC(coreinitHandle, OSUninterruptibleSpinLock_Acquire);
        EXPORT_FIND_FUNC(coreinitHandle, OSUninterruptibleSpinLock_TryAcquire);
        EXPORT_FIND_FUNC(coreinitHandle, OSUninterruptibleSpinLock_TryAcquireWithTimeout);
        EXPORT_FIND_FUNC(coreinitHandle, OSUninterruptibleSpinLock_Release);

        EXPORT_FIND_FUNC(coreinitHandle, OSLogBuffer);
        EXPORT_FIND_FUNC(coreinitHandle, OSLogArgs);
        EXPORT_FIND_FUNC(coreinitHandle, OSLogFunc);
        EXPORT_FIND_FUNC(coreinitHandle, OSLogPrintf);
        EXPORT_FIND_FUNC(coreinitHandle, OSLogSetFilterPolicy);
        EXPORT_FIND_FUNC(coreinitHandle, OSLogReport);
        EXPORT_FIND_FUNC(coreinitHandle, OSLogRetrieve);
        EXPORT_FIND_FUNC(coreinitHandle, OSLogSaveCrashDump);

        EXPORT_FIND_FUNC(coreinitHandle, __OSBoostThreadPriority);
        EXPORT_FIND_FUNC(coreinitHandle, __OSDeboostThreadPrioriy);

        EXPORT_FIND_FUNC(coreinitHandle, __OSGetAppCrashControl);
        EXPORT_FIND_FUNC(coreinitHandle, __OSSetAppCrashControl);
        EXPORT_FIND_FUNC(coreinitHandle, __OSClearAppCrash);

        EXPORT_FIND_FUNC(coreinitHandle, __OSSetTestSetting);
        EXPORT_FIND_FUNC(coreinitHandle, __OSGetTestSetting);

        EXPORT_FIND_FUNC(coreinitHandle, __OSSetLaunchTimeout);

        EXPORT_FIND_FUNC(coreinitHandle, PMBegin);
        EXPORT_FIND_FUNC(coreinitHandle, PMEnd);
        EXPORT_FIND_FUNC(coreinitHandle, PMCycles);
        EXPORT_FIND_FUNC(coreinitHandle, PML1FetchMisses);
        EXPORT_FIND_FUNC(coreinitHandle, PML1MissCycles);
        EXPORT_FIND_FUNC(coreinitHandle, PMInstructions);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMfmsr);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMtmsr);
        EXPORT_FIND_FUNC(coreinitHandle, PPCOrMsr);
        EXPORT_FIND_FUNC(coreinitHandle, PPCAndMsr);
        EXPORT_FIND_FUNC(coreinitHandle, PPCAndCMsr);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMfhid0);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMthid0);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMfhid1);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMfhid2);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMthid2);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMfwpar);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMtwpar);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMfdmaU);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMfdmaL);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMtdmaU);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMtdmaL);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMfl2cr);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMtl2cr);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMtdec);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMfdec);

        EXPORT_FIND_FUNC(coreinitHandle, PPCSync);
        EXPORT_FIND_FUNC(coreinitHandle, PPCEieio);

        EXPORT_FIND_FUNC(coreinitHandle, PPCHalt);
        EXPORT_FIND_FUNC(coreinitHandle, PPCIsync);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMfmmcr0);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMtmmcr0);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMfmmcr1);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMtmmcr1);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMfpmc1);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMtpmc1);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMfpmc2);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMtpmc2);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMfpmc3);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMtpmc3);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMfpmc4);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMtpmc4);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMfsia);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMtsia);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMfpvr);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMffpscr);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMtfpscr);

        EXPORT_FIND_FUNC(coreinitHandle, PPCEnableSpeculation);
        EXPORT_FIND_FUNC(coreinitHandle, PPCDisableSpeculation);

        EXPORT_FIND_FUNC(coreinitHandle, PPCSetFpIEEEMode);
        EXPORT_FIND_FUNC(coreinitHandle, PPCSetFpNonIEEEMode);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMfhid4);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMthid4);

        EXPORT_FIND_FUNC(coreinitHandle, PPCMfpir);
        EXPORT_FIND_FUNC(coreinitHandle, PPCMfsprg0);

        EXPORT_FIND_FUNC(coreinitHandle, __PPCHalt);
        EXPORT_FIND_FUNC(coreinitHandle, __PPCExit);
    }

    if(OSDynLoad_Acquire("camera.rpl", &cameraHandle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(cameraHandle, CAMInit);
        EXPORT_FIND_FUNC(cameraHandle, CAMExit);
        EXPORT_FIND_FUNC(cameraHandle, CAMOpen);
        EXPORT_FIND_FUNC(cameraHandle, CAMClose);
        EXPORT_FIND_FUNC(cameraHandle, CAMGetMemReq);
        EXPORT_FIND_FUNC(cameraHandle, CAMSubmitTargetSurface);
        EXPORT_FIND_FUNC(cameraHandle, CAMGetState);
        EXPORT_FIND_FUNC(cameraHandle, CAMGetStateInfo);
        EXPORT_FIND_FUNC(cameraHandle, CAMSetState);
        EXPORT_FIND_FUNC(cameraHandle, CAMCheckMemSegmentation);
    }

    if(OSDynLoad_Acquire("dmae.rpl", &dmaeHandle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(dmaeHandle, DMAEWaitDone);
        EXPORT_FIND_FUNC(dmaeHandle, DMAEGetLastSubmittedTimeStamp);
        EXPORT_FIND_FUNC(dmaeHandle, DMAEGetRetiredTimeStamp);
        EXPORT_FIND_FUNC(dmaeHandle, DMAESemaphore);
        EXPORT_FIND_FUNC(dmaeHandle, DMAECopyMem);
        EXPORT_FIND_FUNC(dmaeHandle, DMAEFillMem);
        EXPORT_FIND_FUNC(dmaeHandle, DMAEFillMemPhys);
        EXPORT_FIND_FUNC(dmaeHandle, DMAESetTimeout);
        EXPORT_FIND_FUNC(dmaeHandle, DMAEGetTimeout);
    }

    if(OSDynLoad_Acquire("gx2.rpl", &gx2Handle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(gx2Handle, GX2GetSystemTVScanMode);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetSystemTVAspectRatio);
        EXPORT_FIND_FUNC(gx2Handle, GX2IsVideoOutReady);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetSystemDRCMode);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetSystemDRCScanMode);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetDRCConnectCallback);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetDRCVerticalInfo);
        EXPORT_FIND_FUNC(gx2Handle, GX2CalcTVSize);
        EXPORT_FIND_FUNC(gx2Handle, GX2CalcDRCSize);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetTVBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetDRCBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetTVScale);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetDRCScale);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetTVGamma);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetTVGamma);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetTVGammaEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetDRCGamma);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetDRCGammaEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetDRCGamma);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetTVEnable);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetDRCEnable);
        EXPORT_FIND_FUNC(gx2Handle, GX2CopyColorBufferToScanBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2SwapScanBuffers);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetSwapStatus);
        EXPORT_FIND_FUNC(gx2Handle, GX2WaitForFlip);
        EXPORT_FIND_FUNC(gx2Handle, GX2WaitForVsync);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetSwapInterval);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetSwapInterval);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetVideoEncodingHint);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetLastFrame);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetLastFrameGamma);

        EXPORT_FIND_FUNC(gx2Handle, GX2ClearColor);
        EXPORT_FIND_FUNC(gx2Handle, GX2ClearDepthStencilEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2ClearBuffersEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetClearDepthStencil);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetClearDepth);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetClearStencil);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetAttribBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPrimitiveRestartIndex);
        EXPORT_FIND_FUNC(gx2Handle, GX2DrawIndexedEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2DrawIndexedEx2);
        EXPORT_FIND_FUNC(gx2Handle, GX2DrawIndexedImmediateEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2DrawEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2DrawEx2);
        EXPORT_FIND_FUNC(gx2Handle, GX2DrawStreamOut);
        EXPORT_FIND_FUNC(gx2Handle, GX2DispatchCompute);

        EXPORT_FIND_FUNC(gx2Handle, GX2Init);
        EXPORT_FIND_FUNC(gx2Handle, GX2Shutdown);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetMainCoreId);
        EXPORT_FIND_FUNC(gx2Handle, GX2Flush);
        EXPORT_FIND_FUNC(gx2Handle, GX2DrawDone);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetLastSubmittedTimeStamp);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetRetiredTimeStamp);
        EXPORT_FIND_FUNC(gx2Handle, GX2WaitTimeStamp);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetEventCallback);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetEventCallback);
        EXPORT_FIND_FUNC(gx2Handle, GX2SubmitUserTimeStamp);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetGPUFence);
        EXPORT_FIND_FUNC(gx2Handle, GX2BeginGPUTask);
        EXPORT_FIND_FUNC(gx2Handle, GX2EndGPUTask);
        EXPORT_FIND_FUNC(gx2Handle, GX2InsertGPUTask);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetSemaphore);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetMiscParam);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetMiscParam);
        EXPORT_FIND_FUNC(gx2Handle, GX2ResetGPU);
        EXPORT_FIND_FUNC(gx2Handle, GX2BeginDisplayListEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2EndDisplayList);
        EXPORT_FIND_FUNC(gx2Handle, GX2DirectCallDisplayList);
        EXPORT_FIND_FUNC(gx2Handle, GX2CallDisplayList);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetDisplayListWriteStatus);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetCurrentDisplayList);
        EXPORT_FIND_FUNC(gx2Handle, GX2CopyDisplayList);

        EXPORT_FIND_FUNC(gx2Handle, GX2SetDefaultAllocator);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetDefaultAllocator);
        EXPORT_FIND_FUNC(gx2Handle, GX2NotifyMemAlloc);
        EXPORT_FIND_FUNC(gx2Handle, GX2NotifyMemFree);
        EXPORT_FIND_FUNC(gx2Handle, GX2Invalidate);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetDebugMode);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetGPUTimeout);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetGPUTimeout);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetInterruptCountLimit);
        EXPORT_FIND_FUNC(gx2Handle, GX2PrintGPUStatus);
        EXPORT_FIND_FUNC(gx2Handle, GX2LogSetMisc);
        EXPORT_FIND_FUNC(gx2Handle, GX2DebugTagUserString);
        EXPORT_FIND_FUNC(gx2Handle, GX2DebugTagUserStringVA);
        EXPORT_FIND_FUNC(gx2Handle, GX2DebugCaptureFrame);
        EXPORT_FIND_FUNC(gx2Handle, GX2DebugCaptureFrames);
        EXPORT_FIND_FUNC(gx2Handle, GX2DebugCaptureStart);
        EXPORT_FIND_FUNC(gx2Handle, GX2DebugCaptureEnd);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetDefaultState);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetupContextStateEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetContextState);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetContextStateDisplayList);
        EXPORT_FIND_FUNC(gx2Handle, GX2PatchDisplayList);

        EXPORT_FIND_FUNC(gx2Handle, GX2GetPerfMetricType);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfInit);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfFree);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfSetCollectionMethod);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfGetCollectionMethod);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfMetricsClear);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfMetricEnable);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfMetricIsEnabled);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfMetricGetEnabled);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfTagEnable);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfTagEnableAll);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfTagDisableAll);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfTagIsEnabled);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfFrameStart);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfFrameEnd);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfGetNumPasses);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfPassStart);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfPassEnd);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfTagStart);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfTagEnd);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfGetResultByFrame);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfGetResultByTagId);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfGetResultByTagSequence);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfPrintFrameResults);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfPrintTagResults);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfSetPassCoherEnable);
        EXPORT_FIND_FUNC(gx2Handle, GX2PerfGetPassCoherEnable);

        EXPORT_FIND_FUNC(gx2Handle, _GX2InitCounterInfo);
        EXPORT_FIND_FUNC(gx2Handle, _GX2SetCounterInfo);
        EXPORT_FIND_FUNC(gx2Handle, _GX2ResetCounters);
        EXPORT_FIND_FUNC(gx2Handle, _GX2StartCounters);
        EXPORT_FIND_FUNC(gx2Handle, _GX2StopCounters);
        EXPORT_FIND_FUNC(gx2Handle, _GX2SampleCounters);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitPerfMetric);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetPerfMetricU64);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetPerfMetricF32);

        EXPORT_FIND_FUNC(gx2Handle, GX2GetGPUSystemClock);
        EXPORT_FIND_FUNC(gx2Handle, GX2ResetCounterInfo);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitCounterInfo);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetCounterSetting);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetCounterResultSize);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetCounterInfo);
        EXPORT_FIND_FUNC(gx2Handle, GX2SampleCountersEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2SampleCounters);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetCounterResultEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetCounterResult);
        EXPORT_FIND_FUNC(gx2Handle, GX2StopCounters);
        EXPORT_FIND_FUNC(gx2Handle, GX2StartCounters);
        EXPORT_FIND_FUNC(gx2Handle, GX2ResetCounters);

        EXPORT_FIND_FUNC(gx2Handle, GX2SampleTopGPUCycle);
        EXPORT_FIND_FUNC(gx2Handle, GX2SampleBottomGPUCycle);
        EXPORT_FIND_FUNC(gx2Handle, GX2CPUTimeToGPUTime);
        EXPORT_FIND_FUNC(gx2Handle, GX2GPUTimeToCPUTime);
        EXPORT_FIND_FUNC(gx2Handle, GX2QueryBegin);
        EXPORT_FIND_FUNC(gx2Handle, GX2QueryEnd);
        EXPORT_FIND_FUNC(gx2Handle, GX2QueryGetOcclusionResult);
        EXPORT_FIND_FUNC(gx2Handle, GX2QueryGetStreamOutStatsResult);
        EXPORT_FIND_FUNC(gx2Handle, GX2QueryBeginConditionalRender);
        EXPORT_FIND_FUNC(gx2Handle, GX2QueryEndConditionalRender);

        EXPORT_FIND_FUNC(gx2Handle, GX2RDestroyBufferEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2RLockBufferEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2RLockBufferRegionEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2RUnlockBufferEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2RCreateBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2RCreateBufferUserMemory);
        EXPORT_FIND_FUNC(gx2Handle, GX2RBufferExists);
        EXPORT_FIND_FUNC(gx2Handle, GX2RSetBufferName);
        EXPORT_FIND_FUNC(gx2Handle, GX2RGetBufferName);
        EXPORT_FIND_FUNC(gx2Handle, GX2RSetAttributeBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2RSetVertexUniformBlock);
        EXPORT_FIND_FUNC(gx2Handle, GX2RSetGeometryUniformBlock);
        EXPORT_FIND_FUNC(gx2Handle, GX2RSetPixelUniformBlock);
        EXPORT_FIND_FUNC(gx2Handle, GX2RSetStreamOutBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2RDrawIndexed);
        EXPORT_FIND_FUNC(gx2Handle, GX2RDrawIndexedImmediate);
        EXPORT_FIND_FUNC(gx2Handle, GX2RBeginDisplayListEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2REndDisplayList);
        EXPORT_FIND_FUNC(gx2Handle, GX2RCallDisplayList);
        EXPORT_FIND_FUNC(gx2Handle, GX2RDirectCallDisplayList);
        EXPORT_FIND_FUNC(gx2Handle, GX2RSetGeometryShaderInputRingBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2RSetGeometryShaderOutputRingBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2RInitFetchShader);
        EXPORT_FIND_FUNC(gx2Handle, GX2RGetBufferAlignment);
        EXPORT_FIND_FUNC(gx2Handle, GX2RGetBufferAllocationSize);
        EXPORT_FIND_FUNC(gx2Handle, GX2RInvalidateMemory);
        EXPORT_FIND_FUNC(gx2Handle, GX2RInvalidateBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2RGetBufferGuardBandSize);

        EXPORT_FIND_FUNC(gx2Handle, GX2SetDepthStencilControl);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetDepthOnlyControl);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPolygonControl);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetCullOnlyControl);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetStencilMask);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetSpecialState);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetAlphaTest);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetAlphaToMask);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPolygonOffset);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetTargetChannelMasks);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetAAMask);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetColorControl);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetBlendControl);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetBlendConstantColor);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPointSize);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPointLimits);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetLineWidth);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetViewport);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetScissor);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetRasterizerClipControl);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetRasterizerClipControlEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetRasterizerClipControlHalfZ);

        EXPORT_FIND_FUNC(gx2Handle, GX2InitDepthStencilControlReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetDepthStencilControlReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetDepthStencilControlReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitPolygonControlReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetPolygonControlReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPolygonControlReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitStencilMaskReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetStencilMaskReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetStencilMaskReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitAlphaTestReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetAlphaTestReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetAlphaTestReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitAlphaToMaskReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetAlphaToMaskReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetAlphaToMaskReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitPolygonOffsetReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetPolygonOffsetReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPolygonOffsetReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitTargetChannelMasksReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetTargetChannelMasksReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetTargetChannelMasksReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitAAMaskReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetAAMaskReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetAAMaskReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitColorControlReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetColorControlReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetColorControlReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitBlendControlReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetBlendControlReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetBlendControlReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitBlendConstantColorReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetBlendConstantColorReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetBlendConstantColorReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitPointSizeReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetPointSizeReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPointSizeReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitPointLimitsReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetPointLimitsReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPointLimitsReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitLineWidthReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetLineWidthReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetLineWidthReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitViewportReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetViewportReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetViewportReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitScissorReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetScissorReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetScissorReg);

        EXPORT_FIND_FUNC(gx2Handle, GX2RIsUserMemory);
        EXPORT_FIND_FUNC(gx2Handle, GX2RSetAllocator);
        EXPORT_FIND_FUNC(gx2Handle, GX2RSetDebugOptions);
        EXPORT_FIND_FUNC(gx2Handle, GX2RGetDebugOptions);

        EXPORT_FIND_FUNC(gx2Handle, GX2RDestroySurfaceEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2RLockSurfaceEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2RUnlockSurfaceEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2RCreateSurface);
        EXPORT_FIND_FUNC(gx2Handle, GX2RCreateSurfaceUserMemory);
        EXPORT_FIND_FUNC(gx2Handle, GX2RSurfaceExists);
        EXPORT_FIND_FUNC(gx2Handle, GX2RSetSurfaceName);
        EXPORT_FIND_FUNC(gx2Handle, GX2RGetSurfaceName);
        EXPORT_FIND_FUNC(gx2Handle, GX2RInvalidateSurface);

        EXPORT_FIND_FUNC(gx2Handle, GX2GetVertexShaderGPRs);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetVertexShaderStackEntries);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetGeometryShaderGPRs);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetGeometryShaderStackEntries);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetPixelShaderGPRs);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetPixelShaderStackEntries);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetVertexUniformReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPixelUniformReg);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetVertexUniformBlock);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetGeometryUniformBlock);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPixelUniformBlock);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetComputeUniformBlock);
        EXPORT_FIND_FUNC(gx2Handle, GX2CalcFetchShaderSizeEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitFetchShaderEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetAttribFormatBits);
        EXPORT_FIND_FUNC(gx2Handle, GX2CalcGeometryShaderInputRingBufferSize);
        EXPORT_FIND_FUNC(gx2Handle, GX2CalcGeometryShaderOutputRingBufferSize);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetGeometryShaderInputRingBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetGeometryShaderOutputRingBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetShaderModeEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetFetchShader);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetVertexShader);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetGeometryShader);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPixelShader);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetComputeShader);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetStreamOutBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2SaveStreamOutContext);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetStreamOutContext);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetStreamOutEnable);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetShaderExportBuffer);

        EXPORT_FIND_FUNC(gx2Handle, GX2CalcSurfaceSizeAndAlignment);
        EXPORT_FIND_FUNC(gx2Handle, GX2CalcColorBufferAuxInfo);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitColorBufferRegs);
        EXPORT_FIND_FUNC(gx2Handle, GX2CalcDepthBufferHiZInfo);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitDepthBufferRegs);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitDepthBufferHiZEnable);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitDepthBufferRangeBase);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitHiStencilInfoRegs);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetColorBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetDepthBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetHiStencilInfo);
        EXPORT_FIND_FUNC(gx2Handle, GX2CopySurface);
        EXPORT_FIND_FUNC(gx2Handle, GX2CopySurfaceEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2AllocateTilingApertureEx);
        EXPORT_FIND_FUNC(gx2Handle, GX2FreeTilingAperture);
        EXPORT_FIND_FUNC(gx2Handle, GX2ResolveAAColorBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2ExpandAAColorBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2ExpandDepthBuffer);
        EXPORT_FIND_FUNC(gx2Handle, GX2ConvertDepthBufferToTextureSurface);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetSurfaceFormatBits);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetSurfaceSwizzleOffset);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetSurfaceSwizzle);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetSurfaceSwizzle);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetSurfaceMipPitch);
        EXPORT_FIND_FUNC(gx2Handle, GX2GetSurfaceMipSliceSize);
        EXPORT_FIND_FUNC(gx2Handle, GX2SurfaceIsCompressed);
        EXPORT_FIND_FUNC(gx2Handle, GX2CheckSurfaceUseVsFormat);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetAAMode);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetAAModeEx);

        EXPORT_FIND_FUNC(gx2Handle, GX2TempGetGPUVersion);
        EXPORT_FIND_FUNC(gx2Handle, GX2TempGetResourceCount);
        EXPORT_FIND_FUNC(gx2Handle, GX2TempGetNonUserMemoryResourceCount);
        EXPORT_FIND_FUNC(gx2Handle, GX2TempDumpResources);
        EXPORT_FIND_FUNC(gx2Handle, GX2TempDumpGPUResourceContext);

        EXPORT_FIND_FUNC(gx2Handle, GX2SetTessellation);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetMaxTessellationLevel);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetMinTessellationLevel);

        EXPORT_FIND_FUNC(gx2Handle, GX2InitTextureRegs);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetVertexTexture);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetGeometryTexture);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPixelTexture);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetComputeTexture);

        EXPORT_FIND_FUNC(gx2Handle, GX2InitSampler);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitSamplerClamping);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitSamplerXYFilter);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitSamplerZMFilter);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitSamplerLOD);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitSamplerBorderType);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitSamplerRoundingMode);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetVertexSamplerBorderColor);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetGeometrySamplerBorderColor);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPixelSamplerBorderColor);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetComputeSamplerBorderColor);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitSamplerDepthCompare);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitSamplerFilterAdjust);
        EXPORT_FIND_FUNC(gx2Handle, GX2InitSamplerLODAdjust);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetVertexSampler);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetGeometrySampler);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetPixelSampler);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetComputeSampler);

        EXPORT_FIND_FUNC(gx2Handle, GX2UDAGetLastAlert);
        EXPORT_FIND_FUNC(gx2Handle, GX2UDAResetAlertFireCount);
        EXPORT_FIND_FUNC(gx2Handle, GX2UDASetAlertLevel);
        EXPORT_FIND_FUNC(gx2Handle, GX2UDASetAlertEnable);

        EXPORT_FIND_FUNC(gx2Handle, GX2SetVerifyLevel);
        EXPORT_FIND_FUNC(gx2Handle, GX2SetVerifyCallback);
    }

    if(OSDynLoad_Acquire("h264.rpl", &h264Handle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(h264Handle, H264DECInitParam);
        EXPORT_FIND_FUNC(h264Handle, H264DECSetParam);
        EXPORT_FIND_FUNC(h264Handle, H264DECOpen);
        EXPORT_FIND_FUNC(h264Handle, H264DECBegin);
        EXPORT_FIND_FUNC(h264Handle, H264DECSetBitstream);
        EXPORT_FIND_FUNC(h264Handle, H264DECExecute);
        EXPORT_FIND_FUNC(h264Handle, H264DECFlush);
        EXPORT_FIND_FUNC(h264Handle, H264DECEnd);
        EXPORT_FIND_FUNC(h264Handle, H264DECClose);
        EXPORT_FIND_FUNC(h264Handle, H264DECMemoryRequirement);
        EXPORT_FIND_FUNC(h264Handle, H264DECGetImageSize);
        EXPORT_FIND_FUNC(h264Handle, H264DECFindDecstartpoint);
        EXPORT_FIND_FUNC(h264Handle, H264DECFindIdrpoint);
        EXPORT_FIND_FUNC(h264Handle, H264DECCheckDecunitLength);
        EXPORT_FIND_FUNC(h264Handle, H264DECCheckMemSegmentation);
        EXPORT_FIND_FUNC(h264Handle, H264DECCheckSkipableFrame);
        EXPORT_FIND_FUNC(h264Handle, H264DECSetParam_FPTR_OUTPUT);
        EXPORT_FIND_FUNC(h264Handle, H264DECSetParam_OUTPUT_PER_FRAME);
        EXPORT_FIND_FUNC(h264Handle, H264DECSetParam_USER_MEMORY);
    }

    if(OSDynLoad_Acquire("mic.rpl", &micHandle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(micHandle, MICInit);
        EXPORT_FIND_FUNC(micHandle, MICUninit);
        EXPORT_FIND_FUNC(micHandle, MICOpen);
        EXPORT_FIND_FUNC(micHandle, MICGetStatus);
        EXPORT_FIND_FUNC(micHandle, MICSetDataConsumed);
        EXPORT_FIND_FUNC(micHandle, MICSetState);
        EXPORT_FIND_FUNC(micHandle, MICGetState);
        EXPORT_FIND_FUNC(micHandle, MICClose);
    }

    if(OSDynLoad_Acquire("nio_prof.rpl", &nio_profHandle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(nio_profHandle, IO_ProfilerLibInit);
        EXPORT_FIND_FUNC(nio_profHandle, IO_ProfilerLibFinish);
        EXPORT_FIND_FUNC(nio_profHandle, IO_ProfilerStartCheckpoint);
        EXPORT_FIND_FUNC(nio_profHandle, IO_ProfilerGetStatsAndEndCheckpoint);
        EXPORT_FIND_FUNC(nio_profHandle, IO_ProfilerGetStatsAndRestartCheckpoint);
    }

    if(OSDynLoad_Acquire("nlibcurl.rpl", &nlibcurlHandle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_formadd);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_formfree);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_getenv);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_version);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_escape);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_escape);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_unescape);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_unescape);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_free);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_global_init);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_global_init_mem);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_global_cleanup);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_slist_append);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_slist_free_all);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_getdate);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_share_init);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_share_setopt);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_share_cleanup);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_version_info);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_strerror);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_share_strerror);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_pause);

        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_init);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_setopt);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_perform);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_cleanup);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_getinfo);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_duphandle);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_reset);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_recv);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_easy_send);

        EXPORT_FIND_FUNC(nlibcurlHandle, curl_mprintf);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_mfprintf);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_msprintf);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_msnprintf);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_mvprintf);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_mvfprintf);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_mvsprintf);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_mvsnprintf);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_maprintf);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_mvaprintf);

        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_init);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_add_handle);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_remove_handle);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_fdset);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_perform);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_cleanup);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_info_read);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_strerror);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_socket);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_socket_action);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_socket_all);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_timeout);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_setopt);
        EXPORT_FIND_FUNC(nlibcurlHandle, curl_multi_assign);
    }

    if(OSDynLoad_Acquire("nsyshid.rpl", &nsyshidHandle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(nsyshidHandle, HIDSetup);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDTeardown);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDAddClient);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDDelClient);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDGetDescriptor);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDSetDescriptor);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDGetReport);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDSetReport);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDGetProtocol);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDSetProtocol);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDGetIdle);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDSetIdle);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDRead);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDWrite);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDResetDevice);
        EXPORT_FIND_FUNC(nsyshidHandle, HIDDecodeError);
    }

    if(OSDynLoad_Acquire("nsysnet.rpl", &nsysnetHandle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(nsysnetHandle, ntohl);
        EXPORT_FIND_FUNC(nsysnetHandle, htonl);
        EXPORT_FIND_FUNC(nsysnetHandle, ntohs);
        EXPORT_FIND_FUNC(nsysnetHandle, htons);

        EXPORT_FIND_FUNC(nsysnetHandle, inet_aton);
        EXPORT_FIND_FUNC(nsysnetHandle, inet_ntoa);
        EXPORT_FIND_FUNC(nsysnetHandle, inet_ntop);
        EXPORT_FIND_FUNC(nsysnetHandle, inet_pton);

        EXPORT_FIND_FUNC(nsysnetHandle, inet_ntoa_r);

        EXPORT_FIND_FUNC(nsysnetHandle, select);

        EXPORT_FIND_FUNC(nsysnetHandle, accept);
        EXPORT_FIND_FUNC(nsysnetHandle, bind);
        EXPORT_FIND_FUNC(nsysnetHandle, connect);
        EXPORT_FIND_FUNC(nsysnetHandle, getpeername);
        EXPORT_FIND_FUNC(nsysnetHandle, getsockname);
        EXPORT_FIND_FUNC(nsysnetHandle, getsockopt);
        EXPORT_FIND_FUNC(nsysnetHandle, listen);
        EXPORT_FIND_FUNC(nsysnetHandle, recv);
        EXPORT_FIND_FUNC(nsysnetHandle, recvfrom);
        EXPORT_FIND_FUNC(nsysnetHandle, send);
        EXPORT_FIND_FUNC(nsysnetHandle, sendto);
        EXPORT_FIND_FUNC(nsysnetHandle, setsockopt);
        EXPORT_FIND_FUNC(nsysnetHandle, shutdown);
        EXPORT_FIND_FUNC(nsysnetHandle, socket);

        EXPORT_FIND_FUNC(nsysnetHandle, socket_lib_init);
        EXPORT_FIND_FUNC(nsysnetHandle, socket_lib_finish);
        EXPORT_FIND_FUNC(nsysnetHandle, set_resolver_allocator);

        EXPORT_FIND_FUNC(nsysnetHandle, socketlasterr);

        EXPORT_FIND_FUNC(nsysnetHandle, socketclose);
        EXPORT_FIND_FUNC(nsysnetHandle, recvfrom_ex);
        EXPORT_FIND_FUNC(nsysnetHandle, recvfrom_multi);
        EXPORT_FIND_FUNC(nsysnetHandle, sendto_multi);
        EXPORT_FIND_FUNC(nsysnetHandle, sendto_multi_ex);
        EXPORT_FIND_FUNC(nsysnetHandle, setsocklibopt);
        EXPORT_FIND_FUNC(nsysnetHandle, getsocklibopt);

        EXPORT_FIND_FUNC(nsysnetHandle, get_h_errno);
        EXPORT_FIND_FUNC(nsysnetHandle, gethostbyname);
        EXPORT_FIND_FUNC(nsysnetHandle, gethostbyaddr);
        EXPORT_FIND_FUNC(nsysnetHandle, getnameinfo);
        EXPORT_FIND_FUNC(nsysnetHandle, getaddrinfo);
        EXPORT_FIND_FUNC(nsysnetHandle, freeaddrinfo);
        EXPORT_FIND_FUNC(nsysnetHandle, gai_strerror);

        EXPORT_FIND_FUNC(nsysnetHandle, getaddrinfo_rs);
    }

    if(OSDynLoad_Acquire("padscore.rpl", &padscoreHandle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(padscoreHandle, WBCSetupCalibration);
        EXPORT_FIND_FUNC(padscoreHandle, WBCGetCalibrationStatus);
        EXPORT_FIND_FUNC(padscoreHandle, WBCRead);
        EXPORT_FIND_FUNC(padscoreHandle, WBCGetBatteryLevel);
        EXPORT_FIND_FUNC(padscoreHandle, WBCSetZEROPoint);
        EXPORT_FIND_FUNC(padscoreHandle, WBCGetTGCWeight);

        EXPORT_FIND_FUNC(padscoreHandle, WPADInit);
        EXPORT_FIND_FUNC(padscoreHandle, WPADShutdown);
        EXPORT_FIND_FUNC(padscoreHandle, WPADRegisterAllocator);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetWorkMemorySize);

        EXPORT_FIND_FUNC(padscoreHandle, WPADProbe);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetStatus);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetDataFormat);
        EXPORT_FIND_FUNC(padscoreHandle, WPADSetDataFormat);
        EXPORT_FIND_FUNC(padscoreHandle, WPADRead);

        EXPORT_FIND_FUNC(padscoreHandle, WPADSetAutoSamplingBuf);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetLatestIndexInBuf);

        EXPORT_FIND_FUNC(padscoreHandle, WPADGetAccGravityUnit);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetCLTriggerThreshold);
        EXPORT_FIND_FUNC(padscoreHandle, WPADClampStick);
        EXPORT_FIND_FUNC(padscoreHandle, WPADClampTrigger);
        EXPORT_FIND_FUNC(padscoreHandle, WPADClampAcc);

        EXPORT_FIND_FUNC(padscoreHandle, WPADIsDpdEnabled);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetDpdFormat);
        EXPORT_FIND_FUNC(padscoreHandle, WPADControlDpd);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetDpdSensitivity);
        EXPORT_FIND_FUNC(padscoreHandle, WPADControlExtGimmick);

        EXPORT_FIND_FUNC(padscoreHandle, WPADDisconnect);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetInfo);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetInfoAsync);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetAddress);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetRegisteredDevNum);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetRadioSensitivity);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetBatteryLevel);

        EXPORT_FIND_FUNC(padscoreHandle, WPADIsSpeakerEnabled);
        EXPORT_FIND_FUNC(padscoreHandle, WPADControlSpeaker);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetSpeakerVolume);

        EXPORT_FIND_FUNC(padscoreHandle, WPADSendStreamData);
        EXPORT_FIND_FUNC(padscoreHandle, WPADCanSendStreamData);

        EXPORT_FIND_FUNC(padscoreHandle, WPADControlMotor);
        EXPORT_FIND_FUNC(padscoreHandle, WPADIsMotorEnabled);

        EXPORT_FIND_FUNC(padscoreHandle, WPADSetAutoSleepTime);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetAutoSleepTimeCount);
        EXPORT_FIND_FUNC(padscoreHandle, WPADResetAutoSleepTimeCount);

        EXPORT_FIND_FUNC(padscoreHandle, WPADGetSensorBarPosition);
        EXPORT_FIND_FUNC(padscoreHandle, WPADEnableSensorBar);
        EXPORT_FIND_FUNC(padscoreHandle, WPADSetSensorBar);

        EXPORT_FIND_FUNC(padscoreHandle, WPADSetGameTitleUtf16);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetGameTitleUtf16);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetGameDataTimeStamp);

        EXPORT_FIND_FUNC(padscoreHandle, WPADSetAcceptConnection);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetAcceptConnection);

        EXPORT_FIND_FUNC(padscoreHandle, WPADStartSyncDevice);
        EXPORT_FIND_FUNC(padscoreHandle, WPADPurgeBtDb);
        EXPORT_FIND_FUNC(padscoreHandle, WPADCancelSyncDevice);
        EXPORT_FIND_FUNC(padscoreHandle, WPADIsBusyForSync);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetSyncType);

        EXPORT_FIND_FUNC(padscoreHandle, WPADSetSamplingCallback);
        EXPORT_FIND_FUNC(padscoreHandle, WPADSetExtensionCallback);
        EXPORT_FIND_FUNC(padscoreHandle, WPADSetConnectCallback);
        EXPORT_FIND_FUNC(padscoreHandle, WPADSetSyncDeviceCallback);
        EXPORT_FIND_FUNC(padscoreHandle, WPADSetClearDeviceCallback);

        EXPORT_FIND_FUNC(padscoreHandle, WPADAttachDummyExtension);
        EXPORT_FIND_FUNC(padscoreHandle, WPADDetachDummyExtension);

        EXPORT_FIND_FUNC(padscoreHandle, WPADIsMplsAttached);
        EXPORT_FIND_FUNC(padscoreHandle, WPADIsMplsIntegrated);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetCalibrationStatus);

        EXPORT_FIND_FUNC(padscoreHandle, WPADEnableURCC);
        EXPORT_FIND_FUNC(padscoreHandle, WPADEnableWiiRemote);
        EXPORT_FIND_FUNC(padscoreHandle, WPADDisableBluetooth);

        EXPORT_FIND_FUNC(padscoreHandle, WPADControlBLC);
        EXPORT_FIND_FUNC(padscoreHandle, WPADGetBLCalibration);
        EXPORT_FIND_FUNC(padscoreHandle, WPADIsRegisteredBLC);
        EXPORT_FIND_FUNC(padscoreHandle, WPADRegisterBLCWorkarea);
        EXPORT_FIND_FUNC(padscoreHandle, WPADIsEnabledWBC);
        EXPORT_FIND_FUNC(padscoreHandle, WPADEnableWBC);

        EXPORT_FIND_FUNC(padscoreHandle, WENCGetEncodeData);

        EXPORT_FIND_FUNC(padscoreHandle, KPADInit);
        EXPORT_FIND_FUNC(padscoreHandle, KPADInitEx);
        EXPORT_FIND_FUNC(padscoreHandle, KPADShutdown);
        EXPORT_FIND_FUNC(padscoreHandle, KPADReset);

        EXPORT_FIND_FUNC(padscoreHandle, KPADRead);
        EXPORT_FIND_FUNC(padscoreHandle, KPADReadEx);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetUnifiedWpadStatus);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetProjectionPos);

        EXPORT_FIND_FUNC(padscoreHandle, KPADSetPosParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetHoriParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetDistParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetAccParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetCrossStickEmulationParamsL);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetCrossStickEmulationParamsR);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetPosParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetHoriParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetDistParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetAccParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetCrossStickEmulationParamsL);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetCrossStickEmulationParamsR);

        EXPORT_FIND_FUNC(padscoreHandle, KPADSetBtnRepeat);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetObjInterval);

        EXPORT_FIND_FUNC(padscoreHandle, KPADDisableDPD);
        EXPORT_FIND_FUNC(padscoreHandle, KPADEnableDPD);
        EXPORT_FIND_FUNC(padscoreHandle, KPADCalibrateDPD);

        EXPORT_FIND_FUNC(padscoreHandle, KPADSetSensorHeight);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetSensorHeight);

        EXPORT_FIND_FUNC(padscoreHandle, KPADEnableStickCrossClamp);
        EXPORT_FIND_FUNC(padscoreHandle, KPADDisableStickCrossClamp);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetFSStickClamp);

        EXPORT_FIND_FUNC(padscoreHandle, KPADEnableAimingMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADDisableAimingMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADIsEnableAimingMode);

        EXPORT_FIND_FUNC(padscoreHandle, KPADSetControlDpdCallback);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetSamplingCallback);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetConnectCallback);

        EXPORT_FIND_FUNC(padscoreHandle, KPADSetReviseMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADReviseAcc);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetReviseAngle);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetPosPlayMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetHoriPlayMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetDistPlayMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetAccPlayMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetPosPlayMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetHoriPlayMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetDistPlayMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetAccPlayMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetButtonProcMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetButtonProcMode);

        EXPORT_FIND_FUNC(padscoreHandle, KPADResetWbcZeroPoint);
        EXPORT_FIND_FUNC(padscoreHandle, KPADResetWbcTgcWeight);

        EXPORT_FIND_FUNC(padscoreHandle, KPADDisableMpls);
        EXPORT_FIND_FUNC(padscoreHandle, KPADEnableMpls);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetMplsStatus);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetControlMplsCallback);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetMplsWorkSize);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetMplsWorkarea);
        EXPORT_FIND_FUNC(padscoreHandle, KPADResetMpls);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetMplsAngle);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetMplsDirection);
        EXPORT_FIND_FUNC(padscoreHandle, KPADStartMplsCalibration);
        EXPORT_FIND_FUNC(padscoreHandle, KPADWorkMplsCalibration);
        EXPORT_FIND_FUNC(padscoreHandle, KPADStopMplsCalibration);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetMplsDirectionMag);
        EXPORT_FIND_FUNC(padscoreHandle, KPADEnableMplsZeroPlay);
        EXPORT_FIND_FUNC(padscoreHandle, KPADEnableMplsDirRevise);
        EXPORT_FIND_FUNC(padscoreHandle, KPADEnableMplsAccRevise);
        EXPORT_FIND_FUNC(padscoreHandle, KPADEnableMplsDpdRevise);
        EXPORT_FIND_FUNC(padscoreHandle, KPADDisableMplsZeroPlay);
        EXPORT_FIND_FUNC(padscoreHandle, KPADDisableMplsDirRevise);
        EXPORT_FIND_FUNC(padscoreHandle, KPADDisableMplsAccRevise);
        EXPORT_FIND_FUNC(padscoreHandle, KPADDisableMplsDpdRevise);
        EXPORT_FIND_FUNC(padscoreHandle, KPADIsEnableMplsZeroPlay);
        EXPORT_FIND_FUNC(padscoreHandle, KPADIsEnableMplsZeroDrift);
        EXPORT_FIND_FUNC(padscoreHandle, KPADIsEnableMplsDirRevise);
        EXPORT_FIND_FUNC(padscoreHandle, KPADIsEnableMplsAccRevise);
        EXPORT_FIND_FUNC(padscoreHandle, KPADIsEnableMplsDpdRevise);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetMplsZeroPlayParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetMplsDirReviseParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetMplsAccReviseParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetMplsDpdReviseParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetMplsDirReviseBase);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetMplsZeroPlayParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetMplsDirReviseParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetMplsAccReviseParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetMplsDpdReviseParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADInitMplsZeroPlayParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADInitMplsDirReviseParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADInitMplsAccReviseParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADInitMplsDpdReviseParam);
        EXPORT_FIND_FUNC(padscoreHandle, KPADInitMplsZeroDriftMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetMplsZeroDriftMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetMplsZeroDriftMode);
        EXPORT_FIND_FUNC(padscoreHandle, KPADSetMplsMagnification);

        EXPORT_FIND_FUNC(padscoreHandle, KPADSetDpdDetection);
        EXPORT_FIND_FUNC(padscoreHandle, KPADGetDpdDetection);
    }
    
    if(OSDynLoad_Acquire("proc_ui.rpl", &proc_uiHandle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUIInit);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUIInitEx);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUIShutdown);

        EXPORT_FIND_FUNC(proc_uiHandle, ProcUIIsRunning);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUIInForeground);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUIInShutdown);

        EXPORT_FIND_FUNC(proc_uiHandle, ProcUISubProcessMessages);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUIProcessMessages);

        EXPORT_FIND_FUNC(proc_uiHandle, ProcUIDrawDoneRelease);

        EXPORT_FIND_FUNC(proc_uiHandle, ProcUICalcMemorySize);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUISetMemoryPool);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUISetMEM1Storage);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUISetBucketStorage);

        EXPORT_FIND_FUNC(proc_uiHandle, ProcUIClearCallbacks);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUISetCallbackStackSize);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUIRegisterBackgroundCallback);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUIRegisterCallback);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUIRegisterCallbackCore);
        EXPORT_FIND_FUNC(proc_uiHandle, ProcUISetSaveCallback);
    }
    
    if(OSDynLoad_Acquire("sndcore2.rpl", &sndcore2Handle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(sndcore2Handle, AIInit);
        EXPORT_FIND_FUNC(sndcore2Handle, AIReset);
        EXPORT_FIND_FUNC(sndcore2Handle, AIQuit);
        EXPORT_FIND_FUNC(sndcore2Handle, AICheckInit);

        EXPORT_FIND_FUNC(sndcore2Handle, AIRegisterDMACallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AIDRCRegisterDMACallback);

        EXPORT_FIND_FUNC(sndcore2Handle, AIInitDMA);
        EXPORT_FIND_FUNC(sndcore2Handle, AIGetDMAEnableFlag);
        EXPORT_FIND_FUNC(sndcore2Handle, AIStartDMA);
        EXPORT_FIND_FUNC(sndcore2Handle, AIStopDMA);
        EXPORT_FIND_FUNC(sndcore2Handle, AIGetDMARange);
        EXPORT_FIND_FUNC(sndcore2Handle, AIGetDMABytesLeft);
        EXPORT_FIND_FUNC(sndcore2Handle, AIGetDMAStartAddr);
        EXPORT_FIND_FUNC(sndcore2Handle, AIDRCGetDMAStartAddr);
        EXPORT_FIND_FUNC(sndcore2Handle, AIGetDMALength);
        EXPORT_FIND_FUNC(sndcore2Handle, AIDRCGetDMALength);

        EXPORT_FIND_FUNC(sndcore2Handle, AIGetAudioFrameCount);
        EXPORT_FIND_FUNC(sndcore2Handle, AIGetDSPSampleRate);
        EXPORT_FIND_FUNC(sndcore2Handle, AISetDSPSampleRate);
        EXPORT_FIND_FUNC(sndcore2Handle, AISetChannel);

        EXPORT_FIND_FUNC(sndcore2Handle, AXInit);
        EXPORT_FIND_FUNC(sndcore2Handle, AXInitEx);
        EXPORT_FIND_FUNC(sndcore2Handle, AXInitWithParams);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetCurrentParams);
        EXPORT_FIND_FUNC(sndcore2Handle, AXIsInit);
        EXPORT_FIND_FUNC(sndcore2Handle, AXQuit);

        EXPORT_FIND_FUNC(sndcore2Handle, AXGetLibraryVersion);

        EXPORT_FIND_FUNC(sndcore2Handle, AXIsAudioOutReady);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetMasterVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMasterVolume);

        EXPORT_FIND_FUNC(sndcore2Handle, AXInitProfile);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetProfile);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetSwapProfile);

        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMaxDspCycles);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetMaxDspCycles);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDspCycles);

        EXPORT_FIND_FUNC(sndcore2Handle, AXSetPpcLoadLimit);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetPpcLoadLimit);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetPpcLoad);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDspLoadLimit);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDspLoadLimit);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDspLoad);

        EXPORT_FIND_FUNC(sndcore2Handle, AXGetInputSamplesPerFrame);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetInputSamplesPerSec);

        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDefaultMixerSelect);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDefaultMixerSelect);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetRendererFreq);

        EXPORT_FIND_FUNC(sndcore2Handle, AXRegisterCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXRegisterDRCCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXRegisterFrameCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXRegisterExceedCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXRegisterAppFrameCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXDeregisterAppFrameCallback);

        EXPORT_FIND_FUNC(sndcore2Handle, AXRegisterDeviceFinalMixCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDeviceFinalMixCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDeviceMode);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDeviceMode);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDeviceChannelCount);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDeviceVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDeviceVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDeviceRemixMatrix);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDeviceRemixMatrix);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDeviceUpsampleStage);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDeviceUpsampleStage);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDeviceFinalOutput);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDeviceLinearUpsampler);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDeviceCompressor);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDeviceCompressorTable);
        EXPORT_FIND_FUNC(sndcore2Handle, AXMakeCompressorTable);

        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDRCVSMode);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDRCVSMode);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDRCVSLC);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDRCVSSpeakerPosition);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDRCVSSurroundDepth);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDRCVSDownmixBalance);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDRCVSSurroundLevelGain);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDRCVSOutputGain);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDRCVSLimiter);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDRCVSLimiterThreshold);

        EXPORT_FIND_FUNC(sndcore2Handle, AXGetMasterDRCVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMasterDRCVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDRCAuxReturnVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetDRCAuxReturnVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXRegisterAuxDRCCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetAuxDRCCallback);

        EXPORT_FIND_FUNC(sndcore2Handle, AXRegisterAuxCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetAuxCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetAuxReturnVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetAuxReturnVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXRegisterAuxACallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXRegisterAuxBCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXRegisterAuxCCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetAuxACallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetAuxBCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetAuxCCallback);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetAuxAReturnVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetAuxBReturnVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetAuxCReturnVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetAuxAReturnVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetAuxBReturnVolume);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetAuxCReturnVolume);

        EXPORT_FIND_FUNC(sndcore2Handle, AXPrepareEfxData);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetStepMode);
        EXPORT_FIND_FUNC(sndcore2Handle, AXComputeLpfCoefs);

        EXPORT_FIND_FUNC(sndcore2Handle, AXGetAdpcmOutputSize);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetAdpcmWorkSize);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetAdpcmData);
        EXPORT_FIND_FUNC(sndcore2Handle, AXDecodeAdpcmData);

        EXPORT_FIND_FUNC(sndcore2Handle, AXGetMaxDspVoices);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMaxDspVoices);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetMaxVoices);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetNumVoices);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetNumDspVoices);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetDroppedVoiceCount);

        EXPORT_FIND_FUNC(sndcore2Handle, AXUserBegin);
        EXPORT_FIND_FUNC(sndcore2Handle, AXUserEnd);
        EXPORT_FIND_FUNC(sndcore2Handle, AXUserIsProtected);

        EXPORT_FIND_FUNC(sndcore2Handle, AXVoiceBegin);
        EXPORT_FIND_FUNC(sndcore2Handle, AXVoiceEnd);
        EXPORT_FIND_FUNC(sndcore2Handle, AXVoiceIsProtected);

        EXPORT_FIND_FUNC(sndcore2Handle, AXAcquireVoice);
        EXPORT_FIND_FUNC(sndcore2Handle, AXAcquireVoiceEx);
        EXPORT_FIND_FUNC(sndcore2Handle, AXFreeVoice);
        EXPORT_FIND_FUNC(sndcore2Handle, AXIsVoiceRunning);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetVoiceLoopCount);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceMixerSelect);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetVoiceMixerSelect);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoicePriority);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceSrcType);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceState);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceType);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceVe);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceVeDelta);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceLoop);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetVoiceOffsets);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetVoiceOffsetsEx);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceOffsets);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceOffsetsEx);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceLoopOffset);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceLoopOffsetEx);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceEndOffset);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceEndOffsetEx);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceCurrentOffset);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceCurrentOffsetEx);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetVoiceCurrentOffsetEx);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceDRCMix);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceRmtMix);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceSamplesAddr);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceAdpcm);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceSrc);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceSrcRatio);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceAdpcmLoop);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceLpf);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceLpfCoefs);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceBiquad);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceBiquadCoefs);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceDeviceMix);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMaxVoices);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceRmtOn);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceRmtSrc);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceRmtIIR);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceRmtIIRCoefs);
        EXPORT_FIND_FUNC(sndcore2Handle, AXRmtGetSamplesLeft);
        EXPORT_FIND_FUNC(sndcore2Handle, AXRmtGetSamples);
        EXPORT_FIND_FUNC(sndcore2Handle, AXRmtAdvancePtr);
        EXPORT_FIND_FUNC(sndcore2Handle, AXCheckVoiceOffsets);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceMix);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceItdOn);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceItdTarget);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetVoiceInitialTimeDelay);

        EXPORT_FIND_FUNC(sndcore2Handle, AXAcquireMultiVoice);
        EXPORT_FIND_FUNC(sndcore2Handle, AXFreeMultiVoice);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoicePriority);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceSrcType);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceState);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceType);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceVe);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceVeDelta);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceOffsets);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceLoop);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceAdpcm);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceSrc);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceSrcRatio);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceAdpcmLoop);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceLpf);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceLpfCoefs);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceBiquad);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceBiquadCoefs);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceRenderer);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetMultiVoiceRenderer);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceLoopOffset);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceEndOffset);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceCurrentOffset);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetMultiVoiceOffsets);
        EXPORT_FIND_FUNC(sndcore2Handle, AXIsMultiVoiceRunning);
        EXPORT_FIND_FUNC(sndcore2Handle, AXSetMultiVoiceDeviceMix);
        EXPORT_FIND_FUNC(sndcore2Handle, AXGetMultiVoiceReformatBufferSize);

        EXPORT_FIND_FUNC(sndcore2Handle, __AXGetMixMode);
    }

    if(OSDynLoad_Acquire("sysapp.rpl", &sysappHandle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(sysappHandle, SYSGetVodArgs);
        EXPORT_FIND_FUNC(sysappHandle, SYSGetArguments);
        EXPORT_FIND_FUNC(sysappHandle, SYSCheckSystemApplicationExists);
        EXPORT_FIND_FUNC(sysappHandle, SYSCheckTitleExists);

        EXPORT_FIND_FUNC(sysappHandle, SYSRelaunchTitle);
        EXPORT_FIND_FUNC(sysappHandle, SYSLaunchTitle);
        EXPORT_FIND_FUNC(sysappHandle, SYSLaunchMenu);
        EXPORT_FIND_FUNC(sysappHandle, SYSLaunchAccount);
        EXPORT_FIND_FUNC(sysappHandle, SYSLaunchSettings);
        EXPORT_FIND_FUNC(sysappHandle, SYSSwitchToBrowser);
        EXPORT_FIND_FUNC(sysappHandle, SYSSwitchToBrowserForCallbackURL);
        EXPORT_FIND_FUNC(sysappHandle, SYSSwitchToEManual);
        EXPORT_FIND_FUNC(sysappHandle, SYSSwitchToEShop);
        EXPORT_FIND_FUNC(sysappHandle, SYSSwitchToEShopAocList);
        EXPORT_FIND_FUNC(sysappHandle, SYSSwitchToEShopTicketList);
        EXPORT_FIND_FUNC(sysappHandle, SYSSwitchToSyncControllerOnHBM);
    }

    if(OSDynLoad_Acquire("vpad.rpl", &vpadHandle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(vpadHandle, VPADInit);
        EXPORT_FIND_FUNC(vpadHandle, VPADShutdown);

        EXPORT_FIND_FUNC(vpadHandle, VPADRead);

        EXPORT_FIND_FUNC(vpadHandle, VPADSetAccParam);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetAccParam);

        EXPORT_FIND_FUNC(vpadHandle, VPADSetBtnRepeat);

        EXPORT_FIND_FUNC(vpadHandle, VPADEnableStickCrossClamp);
        EXPORT_FIND_FUNC(vpadHandle, VPADDisableStickCrossClamp);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetLStickClampThreshold);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetRStickClampThreshold);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetLStickClampThreshold);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetRStickClampThreshold);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetStickOrigin);
        EXPORT_FIND_FUNC(vpadHandle, VPADDisableLStickZeroClamp);
        EXPORT_FIND_FUNC(vpadHandle, VPADDisableRStickZeroClamp);
        EXPORT_FIND_FUNC(vpadHandle, VPADEnableLStickZeroClamp);
        EXPORT_FIND_FUNC(vpadHandle, VPADEnableRStickZeroClamp);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetCrossStickEmulationParamsL);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetCrossStickEmulationParamsR);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetCrossStickEmulationParamsL);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetCrossStickEmulationParamsR);

        EXPORT_FIND_FUNC(vpadHandle, VPADSetSamplingCallback);

        EXPORT_FIND_FUNC(vpadHandle, VPADSetAccPlayMode);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetAccPlayMode);

        EXPORT_FIND_FUNC(vpadHandle, VPADSetButtonProcMode);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetButtonProcMode);

        EXPORT_FIND_FUNC(vpadHandle, VPADSetGyroAngle);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetGyroDirection);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetGyroDirectionMag);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetGyroMagnification);

        EXPORT_FIND_FUNC(vpadHandle, VPADEnableGyroZeroPlay);
        EXPORT_FIND_FUNC(vpadHandle, VPADEnableGyroDirRevise);
        EXPORT_FIND_FUNC(vpadHandle, VPADEnableGyroAccRevise);

        EXPORT_FIND_FUNC(vpadHandle, VPADDisableGyroZeroPlay);
        EXPORT_FIND_FUNC(vpadHandle, VPADDisableGyroDirRevise);
        EXPORT_FIND_FUNC(vpadHandle, VPADDisableGyroAccRevise);

        EXPORT_FIND_FUNC(vpadHandle, VPADIsEnableGyroZeroPlay);
        EXPORT_FIND_FUNC(vpadHandle, VPADIsEnableGyroZeroDrift);
        EXPORT_FIND_FUNC(vpadHandle, VPADIsEnableGyroDirRevise);
        EXPORT_FIND_FUNC(vpadHandle, VPADIsEnableGyroAccRevise);

        EXPORT_FIND_FUNC(vpadHandle, VPADSetGyroZeroPlayParam);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetGyroDirReviseParam);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetGyroAccReviseParam);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetGyroDirReviseBase);

        EXPORT_FIND_FUNC(vpadHandle, VPADGetGyroZeroPlayParam);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetGyroDirReviseParam);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetGyroAccReviseParam);

        EXPORT_FIND_FUNC(vpadHandle, VPADInitGyroZeroPlayParam);
        EXPORT_FIND_FUNC(vpadHandle, VPADInitGyroDirReviseParam);
        EXPORT_FIND_FUNC(vpadHandle, VPADInitGyroAccReviseParam);

        EXPORT_FIND_FUNC(vpadHandle, VPADInitGyroZeroDriftMode);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetGyroZeroDriftMode);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetGyroZeroDriftMode);

        EXPORT_FIND_FUNC(vpadHandle, VPADCalcTPCalibrationParam);
        EXPORT_FIND_FUNC(vpadHandle, VPADSetTPCalibrationParam);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetTPCalibrationParam);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetTPCalibratedPoint);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetTPCalibratedPointEx);

        EXPORT_FIND_FUNC(vpadHandle, VPADControlMotor);
        EXPORT_FIND_FUNC(vpadHandle, VPADStopMotor);

        EXPORT_FIND_FUNC(vpadHandle, VPADSetSensorBar);

        EXPORT_FIND_FUNC(vpadHandle, VPADSetLcdMode);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetLcdMode);

        EXPORT_FIND_FUNC(vpadHandle, VPADGetTVMenuStatus);

        EXPORT_FIND_FUNC(vpadHandle, VPADIsStartedGyroMagRevise);
        EXPORT_FIND_FUNC(vpadHandle, VPADStartGyroMagRevise);
        EXPORT_FIND_FUNC(vpadHandle, VPADStopGyroMagRevise);

        EXPORT_FIND_FUNC(vpadHandle, VPADSetGyroMagReviseParam);
        EXPORT_FIND_FUNC(vpadHandle, VPADGetGyroMagReviseParam);
    }
    
    if(OSDynLoad_Acquire("zlib125.rpl", &zlib125Handle) == OS_DYNLOAD_ERROR_NONE) {
        EXPORT_FIND_FUNC(zlib125Handle, zlibVersion);
        EXPORT_FIND_FUNC(zlib125Handle, zlibCompileFlags);

        EXPORT_FIND_FUNC(zlib125Handle, deflateInit_);
        EXPORT_FIND_FUNC(zlib125Handle, deflateInit2_);
        EXPORT_FIND_FUNC(zlib125Handle, deflate);
        EXPORT_FIND_FUNC(zlib125Handle, deflateEnd);
        EXPORT_FIND_FUNC(zlib125Handle, deflateSetDictionary);
        EXPORT_FIND_FUNC(zlib125Handle, deflateCopy);
        EXPORT_FIND_FUNC(zlib125Handle, deflateReset);
        EXPORT_FIND_FUNC(zlib125Handle, deflateParams);
        EXPORT_FIND_FUNC(zlib125Handle, deflateTune);
        EXPORT_FIND_FUNC(zlib125Handle, deflateBound);
        EXPORT_FIND_FUNC(zlib125Handle, deflatePrime);
        EXPORT_FIND_FUNC(zlib125Handle, deflateSetHeader);

        EXPORT_FIND_FUNC(zlib125Handle, inflateInit_);
        EXPORT_FIND_FUNC(zlib125Handle, inflateInit2_);
        EXPORT_FIND_FUNC(zlib125Handle, inflateBackInit_);
        EXPORT_FIND_FUNC(zlib125Handle, inflate);
        EXPORT_FIND_FUNC(zlib125Handle, inflateEnd);
        EXPORT_FIND_FUNC(zlib125Handle, inflateSetDictionary);
        EXPORT_FIND_FUNC(zlib125Handle, inflateSync);
        EXPORT_FIND_FUNC(zlib125Handle, inflateCopy);
        EXPORT_FIND_FUNC(zlib125Handle, inflateReset);
        EXPORT_FIND_FUNC(zlib125Handle, inflateReset2);
        EXPORT_FIND_FUNC(zlib125Handle, inflatePrime);
        EXPORT_FIND_FUNC(zlib125Handle, inflateMark);
        EXPORT_FIND_FUNC(zlib125Handle, inflateGetHeader);
        EXPORT_FIND_FUNC(zlib125Handle, inflateBack);
        EXPORT_FIND_FUNC(zlib125Handle, inflateBackEnd);

        EXPORT_FIND_FUNC(zlib125Handle, compress);
        EXPORT_FIND_FUNC(zlib125Handle, compress2);
        EXPORT_FIND_FUNC(zlib125Handle, compressBound);
        EXPORT_FIND_FUNC(zlib125Handle, uncompress);

        EXPORT_FIND_FUNC(zlib125Handle, adler32);
        EXPORT_FIND_FUNC(zlib125Handle, crc32);
    }
}

void __wiiu_dynlib_uninstall() {
    if(zlib125Handle != NULL) {
        OSDynLoad_Release(zlib125Handle);
        zlib125Handle = NULL;
    }
    
    if(vpadHandle != NULL) {
        OSDynLoad_Release(vpadHandle);
        vpadHandle = NULL;
    }

    if(sysappHandle != NULL) {
        OSDynLoad_Release(sysappHandle);
        sysappHandle = NULL;
    }

    if(sndcore2Handle != NULL) {
        OSDynLoad_Release(sndcore2Handle);
        sndcore2Handle = NULL;
    }

    if(proc_uiHandle != NULL) {
        OSDynLoad_Release(proc_uiHandle);
        proc_uiHandle = NULL;
    }

    if(padscoreHandle != NULL) {
        OSDynLoad_Release(padscoreHandle);
        padscoreHandle = NULL;
    }

    if(nsysnetHandle != NULL) {
        OSDynLoad_Release(nsysnetHandle);
        nsysnetHandle = NULL;
    }

    if(nsyshidHandle != NULL) {
        OSDynLoad_Release(nsyshidHandle);
        nsyshidHandle = NULL;
    }

    if(nlibcurlHandle != NULL) {
        OSDynLoad_Release(nlibcurlHandle);
        nlibcurlHandle = NULL;
    }

    if(nio_profHandle != NULL) {
        OSDynLoad_Release(nio_profHandle);
        nio_profHandle = NULL;
    }

    if(micHandle != NULL) {
        OSDynLoad_Release(micHandle);
        micHandle = NULL;
    }

    if(h264Handle != NULL) {
        OSDynLoad_Release(h264Handle);
        h264Handle = NULL;
    }

    if(gx2Handle != NULL) {
        OSDynLoad_Release(gx2Handle);
        gx2Handle = NULL;
    }

    if(dmaeHandle != NULL) {
        OSDynLoad_Release(dmaeHandle);
        dmaeHandle = NULL;
    }

    if(cameraHandle != NULL) {
        OSDynLoad_Release(cameraHandle);
        cameraHandle = NULL;
    }

    if(coreinitHandle != NULL) {
        OSDynLoad_Release(coreinitHandle);
        coreinitHandle = NULL;
    }
}