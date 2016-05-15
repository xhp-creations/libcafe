#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#include <wiiu/dynlib/coreinit/os.h>

#define FS_MAX_CLIENTS     63
#define FS_MAX_MOUNTPOINTS 48

#define FS_MAX_LOCALPATH_SIZE 511
#define FS_MAX_MOUNTPATH_SIZE 128
#define FS_MAX_FULLPATH_SIZE  (FS_MAX_LOCALPATH_SIZE + FS_MAX_MOUNTPATH_SIZE)

#define FS_IO_BUFFER_ALIGN 0x40

typedef s32 FSDirHandle;
typedef s32 FSFileHandle;
typedef u64 FSTime;

typedef struct FSClient FSClient;
typedef struct FSCmdBlock FSCmdBlock;
typedef struct FSMountSource FSMountSource;
typedef struct FSStat FSStat;
typedef struct FSDirEntry FSDirEntry;
typedef struct FSAsyncParams FSAsyncParams;
typedef struct FSStateChangeParams FSStateChangeParams;
typedef struct FSMessage FSMessage;
typedef struct FSAsyncResult FSAsyncResult;
typedef struct FSStateNoticeInfo FSStateNoticeInfo;

TYPED_ENUM(s32, FSStatus) {
    FS_STATUS_OK               = 0,
    FS_STATUS_CANCELED         = -1,
    FS_STATUS_END              = -2,
    FS_STATUS_MAX              = -3,
    FS_STATUS_ALREADY_OPEN     = -4,
    FS_STATUS_EXISTS           = -5,
    FS_STATUS_NOT_FOUND        = -6,
    FS_STATUS_NOT_FILE         = -7,
    FS_STATUS_NOT_DIR          = -8,
    FS_STATUS_ACCESS_ERROR     = -9,
    FS_STATUS_PERMISSION_ERROR = -10,
    FS_STATUS_FILE_TOO_BIG     = -11,
    FS_STATUS_STORAGE_FULL     = -12,
    FS_STATUS_JOURNAL_FULL     = -13,
    FS_STATUS_UNSUPPORTED_CMD  = -14,
    FS_STATUS_MEDIA_NOT_READY  = -15,
    FS_STATUS_INVALID_MEDIA    = -16,
    FS_STATUS_MEDIA_ERROR      = -17,
    FS_STATUS_DATA_CORRUPTED   = -18,
    FS_STATUS_WRITE_PROTECTED  = -19,
    FS_STATUS_FATAL_ERROR      = -1024
};

TYPED_ENUM(s32, FSError) {
    FS_ERROR_OK                    = 0,
    FS_ERROR_NOT_INIT              = -196609,
    FS_ERROR_BUSY                  = -196610,
    FS_ERROR_CANCELED              = -196611,
    FS_ERROR_END_OF_DIRECTORY      = -196612,
    FS_ERROR_END_OF_FILE           = -196613,
    FS_ERROR_MAX_MOUNTPOINTS       = -196624,
    FS_ERROR_MAX_VOLUMES           = -196625,
    FS_ERROR_MAX_CLIENTS           = -196626,
    FS_ERROR_MAX_FILES             = -196627,
    FS_ERROR_MAX_DIRS              = -196628,
    FS_ERROR_ALREADY_OPEN          = -196629,
    FS_ERROR_ALREADY_EXISTS        = -196630,
    FS_ERROR_NOT_FOUND             = -196631,
    FS_ERROR_NOT_EMPTY             = -196632,
    FS_ERROR_ACCESS_ERROR          = -196633,
    FS_ERROR_PERMISSION_ERROR      = -196634,
    FS_ERROR_DATA_CORRUPTED        = -196635,
    FS_ERROR_STORAGE_FULL          = -196636,
    FS_ERROR_JOURNAL_FULL          = -196637,
    FS_ERROR_UNAVAILABLE_CMD       = -196639,
    FS_ERROR_UNSUPPORTED_CMD       = -196640,
    FS_ERROR_INVALID_PARAM         = -196641,
    FS_ERROR_INVALID_PATH          = -196642,
    FS_ERROR_INVALID_BUFFER        = -196643,
    FS_ERROR_INVALID_ALIGNMENT     = -196644,
    FS_ERROR_INVALID_CLIENT_HANDLE = -196645,
    FS_ERROR_INVALID_FILE_HANDLE   = -196646,
    FS_ERROR_INVALID_DIR_HANDLE    = -196647,
    FS_ERROR_NOT_FILE              = -196648,
    FS_ERROR_NOT_DIR               = -196649,
    FS_ERROR_FILE_TOO_BIG          = -196650,
    FS_ERROR_OUT_OF_RANGE          = -196651,
    FS_ERROR_OUT_OF_RESOURCES      = -196652,
    FS_ERROR_MEDIA_NOT_READY       = -196672,
    FS_ERROR_MEDIA_ERROR           = -196673,
    FS_ERROR_WRITE_PROTECTED       = -196674,
    FS_ERROR_INVALID_MEDIA         = -196675,
    FS_ERROR_FATAL                 = -197632
};

TYPED_ENUM(u32, FSRetFlag) {
    FS_RET_NO_ERROR         = 0,
    FS_RET_MAX              = 1 << 0,
    FS_RET_ALREADY_OPEN     = 1 << 1,
    FS_RET_EXISTS           = 1 << 2,
    FS_RET_NOT_FOUND        = 1 << 3,
    FS_RET_NOT_FILE         = 1 << 4,
    FS_RET_NOT_DIR          = 1 << 5,
    FS_RET_ACCESS_ERROR     = 1 << 6,
    FS_RET_PERMISSION_ERROR = 1 << 7,
    FS_RET_FILE_TOO_BIG     = 1 << 8,
    FS_RET_STORAGE_FULL     = 1 << 9,
    FS_RET_UNSUPPORTED_CMD  = 1 << 10,
    FS_RET_JOURNAL_FULL     = 1 << 11,
    FS_RET_ALL_ERROR        = 0xFFFFFFFF
};

TYPED_ENUM(u32, FSMode) {
    FS_MODE_IXOTH = 1 << 0,
    FS_MODE_IWOTH = 1 << 1,
    FS_MODE_IROTH = 1 << 2,
    FS_MODE_IXGRP = 1 << 4,
    FS_MODE_IWGRP = 1 << 5,
    FS_MODE_IRGRP = 1 << 6,
    FS_MODE_IXUSR = 1 << 8,
    FS_MODE_IWUSR = 1 << 9,
    FS_MODE_IRUSR = 1 << 10,
};

TYPED_ENUM(s32, FSPriority) {
    FS_PRIORITY_MIN = 0,
    FS_PRIORITY_MAX = 31
};

TYPED_ENUM(u32, FSVolumeState) {
    FS_VOLSTATE_INITIAL         = 0,
    FS_VOLSTATE_READY           = 1,
    FS_VOLSTATE_NO_MEDIA        = 2,
    FS_VOLSTATE_INVALID_MEDIA   = 3,
    FS_VOLSTATE_DIRTY_MEDIA     = 4,
    FS_VOLSTATE_WRONG_MEDIA     = 5,
    FS_VOLSTATE_MEDIA_ERROR     = 6,
    FS_VOLSTATE_DATA_CORRUPTED  = 7,
    FS_VOLSTATE_WRITE_PROTECTED = 8,
    FS_VOLSTATE_JOURNAL_FULL    = 9,
    FS_VOLSTATE_FATAL           = 10
};

TYPED_ENUM(u32, FSSourceType) {
    FS_SOURCETYPE_EXTERNAL = 0,
    FS_SOURCETYPE_HFIO     = 1
};

TYPED_ENUM(u32, FSIOFlag) {
    FS_IO_FLAG_NONE = 0,
    // TODO
};

TYPED_ENUM(u32, FSStatFlag) {
    FS_STAT_FLAG_IS_UNSUPPORTED_CHAR  = 1 << 19,
    FS_STAT_FLAG_SPRT_DIR_SIZE        = 1 << 20,
    FS_STAT_FLAG_IS_RAW_FILE          = 1 << 23,
    FS_STAT_FLAG_SPRT_FILE_ALLOC_SIZE = 1 << 24,
    FS_STAT_FLAG_SPRT_ATTRIBUTES      = 1 << 25,
    FS_STAT_FLAG_SPRT_MTIME           = 1 << 26,
    FS_STAT_FLAG_SPRT_CTIME           = 1 << 27,
    FS_STAT_FLAG_SPRT_ENTID           = 1 << 28,
    FS_STAT_FLAG_SPRT_QUOTA_SIZE      = 1 << 29,
    FS_STAT_FLAG_IS_QUOTA             = 1 << 30,
    FS_STAT_FLAG_IS_DIRECTORY         = 1 << 31,
};

typedef void (*FSAsyncCallback)      (FSClient* client, FSCmdBlock* block, FSStatus result, void* context);
typedef void (*FSStateChangeCallback)(FSClient* client, FSVolumeState state, void* context);

struct FSClient {
    u8 buffer[0x1700];
};

struct FSCmdBlock {
    u8 buffer[0xA80];
};

struct FSMountSource {
    FSSourceType type;
    char         path[FS_MAX_FULLPATH_SIZE];
};

struct FSStat {
    FSStatFlag flag;
    FSMode     permission;
    u32        ownerId;
    u32        groupId;
    u32        size;
    u32        allocSize;
    u64        quotaSize;
    u32        entId;
    FSTime     createdTime;
    FSTime     modifiedTime;
    u8         attributes[48];
} __attribute__((packed));

struct FSDirEntry {
    FSStat stat;
    char   name[256];
} __attribute__((packed));

struct FSAsyncParams {
    FSAsyncCallback userCallback;
    void*           userContext;
    OSMessageQueue* ioMsgQueue;
};

struct FSStateChangeParams {
    FSStateChangeCallback userCallback;
    void*                 userContext;
    OSMessageQueue*       ioMsgQueue;
};

struct FSMessage {
    void*          data;
    u32            reserved1;
    u32            reserved2;
    OSFunctionType type;
} __attribute__((packed));

struct FSAsyncResult {
    FSAsyncParams userParams;
    FSMessage     ioMsg;
    FSClient*     client;
    FSCmdBlock*   block;
    FSStatus      status;
} __attribute__((packed));

struct FSStateNoticeInfo {
    FSStateChangeParams userParams;
    FSMessage           ioMsg;
    FSClient*           client;
    FSVolumeState       state;
} __attribute__((packed));

EXPORT_FUNC_H(void, FSInit, void);
EXPORT_FUNC_H(void, FSShutdown, void);

EXPORT_FUNC_H(u32, FSGetClientNum, void);
EXPORT_FUNC_H(FSStatus, FSAddClient, FSClient* client, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSDelClient, FSClient* client, FSRetFlag errHandling);

EXPORT_FUNC_H(void, FSInitCmdBlock, FSCmdBlock* block);
EXPORT_FUNC_H(void, FSCancelCommand, FSClient* client, FSCmdBlock* block);
EXPORT_FUNC_H(void, FSCancelAllCommands, FSClient* client);
EXPORT_FUNC_H(void, FSSetUserData, FSCmdBlock* block, void* userData);
EXPORT_FUNC_H(void*, FSGetUserData, FSCmdBlock* block);
EXPORT_FUNC_H(FSMessage*, FSGetFSMessage, FSCmdBlock* block);
EXPORT_FUNC_H(FSCmdBlock*, FSGetCurrentCmdBlock, FSClient* client);
EXPORT_FUNC_H(FSStatus, FSSetCmdPriority, FSCmdBlock* block, FSPriority priority);
EXPORT_FUNC_H(FSPriority, FSGetCmdPriority, FSCmdBlock* block);

EXPORT_FUNC_H(FSVolumeState, FSGetVolumeState, FSClient* client);
EXPORT_FUNC_H(void, FSSetStateChangeNotification, FSClient* client, FSStateChangeParams* changeParams);
EXPORT_FUNC_H(FSAsyncResult*, FSGetAsyncResult, FSMessage* ioMsg);
EXPORT_FUNC_H(FSStateNoticeInfo*, FSGetStateChangeInfo, FSMessage* ioMsg);

EXPORT_FUNC_H(FSStatus, FSGetMountSource, FSClient* client, FSCmdBlock* block, FSSourceType type, FSMountSource* source, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSGetMountSourceAsync, FSClient* client, FSCmdBlock* block, FSSourceType type, FSMountSource* source, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSGetMountSourceNext, FSClient* client, FSCmdBlock* block, FSMountSource* source, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSGetMountSourceNextAsync, FSClient* client, FSCmdBlock* block, FSMountSource* source, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSMount, FSClient* client, FSCmdBlock* block, FSMountSource* source, char* target, u32 bytes, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSMountAsync, FSClient* client, FSCmdBlock* block, FSMountSource* source, char* target, u32 bytes, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSUnmount, FSClient* client, FSCmdBlock* block, const char* target, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSUnmountAsync, FSClient* client, FSCmdBlock* block, const char* target, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_H(FSStatus, FSGetCwd, FSClient* client, FSCmdBlock* block, char* returnedPath, u32 bytes, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSGetCwdAsync, FSClient* client, FSCmdBlock* block, char* returnedPath, u32 bytes, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSChangeDir, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSChangeDirAsync, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_H(FSStatus, FSOpenFile, FSClient* client, FSCmdBlock* block, const char* path, const char* mode, FSFileHandle* fileHandle, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSOpenFileAsync, FSClient* client, FSCmdBlock* block, const char* path, const char* mode, FSFileHandle* fileHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSCloseFile, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSCloseFileAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSReadFile, FSClient* client, FSCmdBlock* block, void* dest, u32 size, u32 count, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSReadFileAsync, FSClient* client, FSCmdBlock* block, void* dest, u32 size, u32 count, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSWriteFile, FSClient* client, FSCmdBlock* block, const void* source, u32 size, u32 count, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSWriteFileAsync, FSClient* client, FSCmdBlock* block, const void* source, u32 size, u32 count, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSReadFileWithPos, FSClient* client, FSCmdBlock* block, void* dest, u32 size, u32 count, u32 fpos, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSReadFileWithPosAsync, FSClient* client, FSCmdBlock* block, void* dest, u32 size, u32 count, u32 fpos, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSWriteFileWithPos, FSClient* client, FSCmdBlock* block, const void* source, u32 size, u32 count, u32 fpos, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSWriteFileWithPosAsync, FSClient* client, FSCmdBlock* block, const void* source, u32 size, u32 count, u32 fpos, FSFileHandle fileHandle, FSIOFlag flag, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSAppendFile, FSClient* client, FSCmdBlock* block, u32 size, u32 count, FSFileHandle fileHandle, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSAppendFileAsync, FSClient* client, FSCmdBlock* block, u32 size, u32 count, FSFileHandle fileHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSTruncateFile, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSTruncateFileAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSFlushFile, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSFlushFileAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSGetPosFile, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, u32* returnedFpos, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSGetPosFileAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, u32* returnedFpos, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSSetPosFile, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, u32 fpos, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSSetPosFileAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, u32 fpos, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSGetStatFile, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSStat* returnedStat, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSGetStatFileAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSStat* returnedStat, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSIsEof, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSIsEofAsync, FSClient* client, FSCmdBlock* block, FSFileHandle fileHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_H(FSStatus, FSOpenDir, FSClient* client, FSCmdBlock* block, const char* path, FSDirHandle* dirHandle, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSOpenDirAsync, FSClient* client, FSCmdBlock* block, const char* path, FSDirHandle* dirHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSCloseDir, FSClient* client, FSCmdBlock* block, FSDirHandle dirHandle, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSCloseDirAsync, FSClient* client, FSCmdBlock* block, FSDirHandle dirHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSReadDir, FSClient* client, FSCmdBlock* block, FSDirHandle dirHandle, FSDirEntry* returnedDirEntry, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSReadDirAsync, FSClient* client, FSCmdBlock* block, FSDirHandle dirHandle, FSDirEntry* returnedDirEntry, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSRewindDir, FSClient* client, FSCmdBlock* block, FSDirHandle dirHandle, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSRewindDirAsync, FSClient* client, FSCmdBlock* block, FSDirHandle dirHandle, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSMakeDir, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSMakeDirAsync, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_H(FSStatus, FSRemove, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSRemoveAsync, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSRename, FSClient* client, FSCmdBlock* block, const char* oldPath, const char* newPath, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSRenameAsync, FSClient* client, FSCmdBlock* block, const char* oldPath, const char* newPath, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_H(FSStatus, FSMakeQuota, FSClient* client, FSCmdBlock* block, const char* path, FSMode mode, u64 size, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSMakeQuotaAsync, FSClient* client, FSCmdBlock* block, const char* path, FSMode mode, u64 size, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSRemoveQuota, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSRemoveQuotaAsync, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSFlushQuota, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSFlushQuotaAsync, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSRollbackQuota, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSRollbackQuotaAsync, FSClient* client, FSCmdBlock* block, const char* path, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_H(FSStatus, FSGetStat, FSClient* client, FSCmdBlock* block, const char* path, FSStat* returnedStat, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSGetStatAsync, FSClient* client, FSCmdBlock* block, const char* path, FSStat* returnedStat, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSGetFreeSpaceSize, FSClient* client, FSCmdBlock* block, const char* path, u64* returnedFreeSize, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSGetFreeSpaceSizeAsync, FSClient* client, FSCmdBlock* block, const char* path, u64* returnedFreeSize, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSGetDirSize, FSClient* client, FSCmdBlock* block, const char* path, u32* returnedDirSize, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSGetDirSizeAsync, FSClient* client, FSCmdBlock* block, const char* path, u32* returnedDirSize, FSRetFlag errHandling, const FSAsyncParams* asyncParams);
EXPORT_FUNC_H(FSStatus, FSGetEntryNum, FSClient* client, FSCmdBlock* block, const char* path, u32* returnedEntryNum, FSRetFlag errHandling);
EXPORT_FUNC_H(FSStatus, FSGetEntryNumAsync, FSClient* client, FSCmdBlock* block, const char* path, u32* returnedEntryNum, FSRetFlag errHandling, const FSAsyncParams* asyncParams);

EXPORT_FUNC_H(s32, FSGetLastErrorCodeForViewer, FSClient* client);
EXPORT_FUNC_H(s32, FSGetErrorCodeForViewer, FSClient* client, FSCmdBlock* block);
EXPORT_FUNC_H(void, FSTimeToCalendarTime, FSTime time, OSCalendarTime* td);

EXPORT_FUNC_H(FSError, FSGetLastError, FSClient* client);
EXPORT_FUNC_H(FSStatus, FSSetEmulatedError, FSClient* client, FSError error);
EXPORT_FUNC_H(FSError, FSGetEmulatedError, FSClient* client);

#ifdef __cplusplus
}
#endif