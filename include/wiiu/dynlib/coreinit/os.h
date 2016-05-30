#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#define OS_THREAD_SPECIFIC_MAX 16

#define OS_MAX_CLIPBOARD_SIZE 2048

#define OS_ARGS_SIZE    4096
#define OS_MAX_NUM_ARGS 32

#define OS_PAGE_SIZE (128 * 1024)

#define OS_LOG_FUNC_NAME_SIZE_LIMIT 32
#define OS_LOG_DATA_SIZE_LIMIT      (1024 * 1024)
#define OS_LOG_PRINTF_SIZE_LIMIT    128
#define OS_LOG_ENTRY_MAX_ARGS       8
#define OS_LOG_MAX_FILEFUNC_DATA_SIZE ((OS_LOG_ENTRY_MAX_ARGS * sizeof(u32)) + sizeof(OSLogEntryFileFuncData))

#define OS_SCREEN_BUFFER_ALIGN 0x40

typedef s64 OSTime;
typedef u32 OSTick;
typedef void* OSModuleHandle;
typedef u32 va_t;
typedef u32 pa_t;

typedef union OSAtomicVar OSAtomicVar;
typedef union OSAtomicVar64 OSAtomicVar64;
typedef union OSLogEntryPayload OSLogEntryPayload;

typedef struct OSCalendarTime OSCalendarTime;
typedef struct OSThreadQueue OSThreadQueue;
typedef struct OSThreadSmallQueue OSThreadSmallQueue;
typedef struct OSThreadLink OSThreadLink;
typedef struct OSMutexQueue OSMutexQueue;
typedef struct OSMutexLink OSMutexLink;
typedef struct OSTLSBlock OSTLSBlock;
typedef struct OSFastMutexQueue OSFastMutexQueue;
typedef struct OSFastMutexLink OSFastMutexLink;
typedef struct OSThread OSThread;
typedef struct OSAlarm OSAlarm;
typedef struct OSAlarmQueue OSAlarmQueue;
typedef struct OSCond OSCond;
typedef struct OSContext OSContext;
typedef struct OSCoroutine OSCoroutine;
typedef struct OSNotifyHdr OSNotifyHdr;
typedef struct OSLoaderHeapStatistics OSLoaderHeapStatistics;
typedef struct OSCrashControl OSCrashControl;
typedef struct OSCrashInfo OSCrashInfo;
typedef struct OSEvent OSEvent;
typedef struct OSFastCond OSFastCond;
typedef struct OSFastMutex OSFastMutex;
typedef struct OSHDPInfo OSHDPInfo;
typedef struct OSSystemInfo OSSystemInfo;
typedef struct OSMessage OSMessage;
typedef struct OSDeviceMessage OSDeviceMessage;
typedef struct OSMessageQueue OSMessageQueue;
typedef struct OSMutex OSMutex;
typedef struct OSRendezvous OSRendezvous;
typedef struct OSSemaphore OSSemaphore;
typedef struct OSSpinLock OSSpinLock;
typedef struct OSLogEntryHeader OSLogEntryHeader;
typedef struct OSLogEntryFileFuncData OSLogEntryFileFuncData;
typedef struct OSLogEntryFilterPolicy OSLogEntryFilterPolicy;
typedef struct OSLogRetrieval OSLogRetrieval;

typedef int  (*OSThreadFunc)           (int intArg, void* ptrArg);
typedef void (*OSThreadCleanupFunc)    (void* thread, void* stackEnd);
typedef void (*OSThreadDeallocatorFunc)(void* thread, void* stackEnd);
typedef void (*OSAlarmHandler)     (OSAlarm* alarm, OSContext* context);
typedef void (*OSNotifyFunc)       (OSModuleHandle moduleHandle, void* userArg, int isLoad, const OSNotifyHdr* notify);
typedef int  (*OSMemAllocFunc)     (int memBytes, int memAlign, void** retAddr);
typedef void (*OSMemFreeFunc)      (void* addr);
typedef void (*OSPanicCBFunc)      (void* arg);
typedef bool (*OSExceptionCallback)(OSContext* interruptedContext);

TYPED_ENUM(u32, OSCoreId) {
    OS_CORE_0 = 0,
    OS_CORE_1 = 1,
    OS_CORE_2 = 2,

    OS_NUM_CORES = 3
};

TYPED_ENUM(u16, OSCoreAffinity) {
    OS_CORE_AFFINITY_0 = 1 << OS_CORE_0,
    OS_CORE_AFFINITY_1 = 1 << OS_CORE_1,
    OS_CORE_AFFINITY_2 = 1 << OS_CORE_2
};

TYPED_ENUM(s32, OSPriority) {
    OS_PRIORITY_MIN = 0,
    OS_PRIORITY_MAX = 31
};

TYPED_ENUM(u32, OSThreadCancelState) {
    OS_THREAD_CANCEL_ENABLED            = 0x00000000,
    OS_THREAD_CANCEL_DISABLED_USER      = 0x00000001,
    OS_THREAD_CANCEL_DISABLED_MUTEX     = 0x00010000,
    OS_THREAD_CANCEL_DISABLED_SPINLOCK  = 0x00020000,
    OS_THREAD_CANCEL_DISABLED_STACK     = 0x00040000,
    OS_THREAD_CANCEL_DISABLED_FASTMUTEX = 0x00080000
};

TYPED_ENUM(s16, OSThreadID) {
    OS_THREAD_ID_APP_IO_START = (s16) 0x5000,
    OS_THREAD_ID_DRV_START    = (s16) 0x6000,
    OS_THREAD_ID_NONE         = (s16) 0x8000
};

TYPED_ENUM(u8, OSThreadAttribute) {
    OS_THREAD_ATTR_AFFINITY_CORE0  = OS_CORE_AFFINITY_0,
    OS_THREAD_ATTR_AFFINITY_CORE1  = OS_CORE_AFFINITY_1,
    OS_THREAD_ATTR_AFFINITY_CORE2  = OS_CORE_AFFINITY_2,
    OS_THREAD_ATTR_DETACH          = 0x08,
    OS_THREAD_ATTR_PINNED_AFFINITY = 0x10,
    OS_THREAD_ATTR_CHECK_STACK_USE = 0x40,
    OS_THREAD_ATTR_NAME_SENT       = 0x80
};

TYPED_ENUM(u32, OSThreadType) {
    OSTHREAD_TYPE_DRVR,
    OSTHREAD_TYPE_APP_IO,
    OSTHREAD_TYPE_APP
};

TYPED_ENUM(u8, OSThreadState) {
    OS_THREAD_STATE_NONE     = 0,
    OS_THREAD_STATE_READY    = 1,
    OS_THREAD_STATE_RUNNING  = 2,
    OS_THREAD_STATE_WAITING  = 4,
    OS_THREAD_STATE_MORIBUND = 8
};

TYPED_ENUM(u32, OSThreadRequestFlag) {
    OS_THREAD_REQUEST_NONE    = 0x0,
    OS_THREAD_REQUEST_SUSPEND = 0x1,
    OS_THREAD_REQUEST_CANCEL  = 0x2
};

TYPED_ENUM(u32, OSAlarmState) {
    OS_ALARM_STATE_IDLE = 0,
    // TODO
};

TYPED_ENUM(u8, OSSecCodeGenMode) {
    OS_SEC_CODEGEN_MODE_RW = 0,
    OS_SEC_CODEGEN_MODE_RX = 1
};

TYPED_ENUM(u16, OSContextState) {
    OS_CONTEXT_STATE_EXC            = 1 << 1,
    OS_CONTEXT_STATE_PMCSAVED       = 1 << 2,
    OS_CONTEXT_STATE_OSCALLBACK     = 1 << 3,
    OS_CONTEXT_STATE_USERMODE_SAVED = 1 << 4
};

TYPED_ENUM(u32, OSContextAttribute) {
    OS_CONTEXT_ATTR_AFFINITY_CORE0 = OS_CORE_AFFINITY_0,
    OS_CONTEXT_ATTR_AFFINITY_CORE1 = OS_CORE_AFFINITY_1,
    OS_CONTEXT_ATTR_AFFINITY_CORE2 = OS_CORE_AFFINITY_2
};

TYPED_ENUM(s32, OSDynLoadError) {
    OS_DYNLOAD_ERROR_NONE                                 = 0,
    OS_DYNLOAD_ERROR_UNKNOWN                              = 0xBAD10001,
    OS_DYNLOAD_ERROR_MEMORY_ALLOCATION_FAILURE            = 0xBAD10002,
    OS_DYNLOAD_ERROR_BAD_MODULE_HANDLE                    = 0xBAD10003,
    OS_DYNLOAD_ERROR_FILE_TOO_SMALL                       = 0xBAD10004,
    OS_DYNLOAD_ERROR_BAD_ELF_HEADER                       = 0xBAD10005,
    OS_DYNLOAD_ERROR_NOT_32BIT_ELF                        = 0xBAD10006,
    OS_DYNLOAD_ERROR_WRONG_ENDIANNESS                     = 0xBAD10007,
    OS_DYNLOAD_ERROR_UNSUPPORTED_HEADER_VERSION           = 0xBAD10008,
    OS_DYNLOAD_ERROR_WRONG_TARGET_MACHINE                 = 0xBAD10009,
    OS_DYNLOAD_ERROR_UNSUPPORTED_FILE_VERSION             = 0xBAD1000A,
    OS_DYNLOAD_ERROR_NO_SECTION_HEADERS                   = 0xBAD1000B,
    OS_DYNLOAD_ERROR_MALFORMED_RPL                        = 0xBAD1000C,
    OS_DYNLOAD_ERROR_NOT_CAFE_RPL                         = 0xBAD1000D,
    OS_DYNLOAD_ERROR_NOTIFY_FUNCPTR_IS_NULL               = 0xBAD1000E,
    OS_DYNLOAD_ERROR_NULL_FILENAME                        = 0xBAD1000F,
    OS_DYNLOAD_ERROR_EMPTY_FILENAME                       = 0xBAD10010,
    OS_DYNLOAD_ERROR_BAD_HANDLE_RETURN_POINTER            = 0xBAD10011,
    OS_DYNLOAD_ERROR_NO_FILENAME                          = 0xBAD10012,
    OS_DYNLOAD_ERROR_LOADER_RETURNED_NO_DATA              = 0xBAD10013,
    OS_DYNLOAD_ERROR_LOADER_PTR_BAD                       = 0xBAD10014,
    OS_DYNLOAD_ERROR_NULL_LOADER                          = 0xBAD10015,
    OS_DYNLOAD_ERROR_CANT_LOAD_INSIDE_MODULE_ENTRYPOINT   = 0xBAD10016,
    OS_DYNLOAD_ERROR_ALLOCATOR_PTR_BAD                    = 0xBAD10017,
    OS_DYNLOAD_ERROR_MODULE_HAS_NONRELOCATABLE_CODE       = 0xBAD10018,
    OS_DYNLOAD_ERROR_CANT_LINK_BLIND_SYMBOL               = 0xBAD10019,
    OS_DYNLOAD_ERROR_IMPORT_NOT_FOUND_IN_EXPORTING_MODULE = 0xBAD1001A,
    OS_DYNLOAD_ERROR_MODULE_HAS_NO_DATA_EXPORTS           = 0xBAD1001B,
    OS_DYNLOAD_ERROR_MODULE_HAS_NO_CODE_EXPORTS           = 0xBAD1001C,
    OS_DYNLOAD_ERROR_EXPORT_NOT_FOUND                     = 0xBAD1001D,
    OS_DYNLOAD_ERROR_BAD_ARGUMENT                         = 0xBAD1001E,
    OS_DYNLOAD_ERROR_BUFFER_TOO_SMALL                     = 0xBAD1001F,
    OS_DYNLOAD_ERROR_LOADER_FAILURE                       = 0xBAD10021,
    OS_DYNLOAD_ERROR_TAG_NOT_FOUND                        = 0xBAD10022,
    OS_DYNLOAD_ERROR_MODULE_NOT_FOUND                     = 0xBAD10023,
    OS_DYNLOAD_ERROR_ALLOC_FAILED_LD_SECT_INFO            = 0xBAD10024,
    OS_DYNLOAD_ERROR_ALLOC_FAILED_MAIN_NOTIF_ENTRY        = 0xBAD10025,
    OS_DYNLOAD_ERROR_FAILED_DEBUG_SET_CALLBACK            = 0xBAD10026,
    OS_DYNLOAD_ERROR_NULL_OBJECT                          = 0xBAD10027,
    OS_DYNLOAD_ERROR_CONTAINING_MODULE_NOT_FOUND          = 0xBAD10028,
    OS_DYNLOAD_ERROR_LOAD_ENTRYPOINT_FAILED               = 0xBAD10029,
    OS_DYNLOAD_ERROR_UNKNOWN_MOD_FOR_HANDLE               = 0xBAD1002A,
    OS_DYNLOAD_ERROR_LOADER_BUSY                          = 0xBAD1002B,
    OS_DYNLOAD_ERROR_LOADER_MEM_INFO_BAD_PTR              = 0xBAD1002C,
    OS_DYNLOAD_ERROR_NULL_LOADER_MEM_INFO                 = 0xBAD1002D,
    OS_DYNLOAD_ERROR_PREVIOUS_LOADER_FAILURE              = 0xBAD1002E,
    OS_DYNLOAD_ERROR_SYS_HEAP_MEMORY_ALLOCATION_FAILURE   = 0xBAD1002F,
    OS_DYNLOAD_ERROR_TLS_INCONSISTENCY                    = 0xBAD10030,
    OS_DYNLOAD_ERROR_TLS_ALLOCATOR_UNCHANGEABLE           = 0xBAD10031,
    OS_DYNLOAD_ERROR_TLS_TOO_MANY_MODULES                 = 0xBAD10032,
    OS_DYNLOAD_ERROR_TLS_FINDEXPORT_UNSUPPORTED           = 0xBAD10033,
    OS_DYNLOAD_ERROR_TAG_ADDRSPACE_WRONG                  = 0xBAD10034,
    OS_DYNLOAD_ERROR_INVAL_TAG_VALUE_RET_BUF              = 0xBAD10035,
    OS_DYNLOAD_ERROR_INVAL_TAG_VALUE_SIZE_RET_BUF         = 0xBAD10036,
    OS_DYNLOAD_ERROR_INVAL_TAG_INPUT_BUF                  = 0xBAD10037,
    OS_DYNLOAD_ERROR_TAG_SNPRINTF_INTERNAL                = 0xBAD10038,
    OS_DYNLOAD_ERROR_TAG_VALUE_SIZE_IS_ZERO               = 0xBAD10039,
    OS_DYNLOAD_ERROR_MISSING_SHSTRTAB_INDEX               = 0xBAD1003A,
    OS_DYNLOAD_ERROR_MISSING_SHSTRTAB                     = 0xBAD1003B,
    OS_DYNLOAD_ERROR_MISSING_IMPORT_NAME                  = 0xBAD1003C,
    OS_DYNLOAD_ERROR_MISSING_TLS_DATA                     = 0xBAD1003D,
    OS_DYNLOAD_ERROR_MISSING_RPX_ENTRYPOINT               = 0xBAD1003E,
    OS_DYNLOAD_ERROR_DISPLACEMENT_TOO_FAR                 = 0xBAD1003F
};

TYPED_ENUM(u32, OSSegmentRestrictionFlags) {
    OS_SEGMENT_RESTRICTION_NONE,
    OS_SEGMENT_RESTRICTION_CODE,
    OS_SEGMENT_RESTRICTION_DATA
};

TYPED_ENUM(u32, OSError) {
    OS_ERROR_SYSTEM_RESET       = 0,
    OS_ERROR_MACHINE_CHECK      = 1,
    OS_ERROR_DSI                = 2,
    OS_ERROR_ISI                = 3,
    OS_ERROR_EXTERNAL_INTERRUPT = 4,
    OS_ERROR_ALIGNMENT          = 5,
    OS_ERROR_PROGRAM            = 6,
    OS_ERROR_FLOATING_POINT     = 7,
    OS_ERROR_DECREMENTER        = 8,
    OS_ERROR_SYSTEM_CALL        = 9,
    OS_ERROR_TRACE              = 10,
    OS_ERROR_PERFORMACE_MONITOR = 11,
    OS_ERROR_BREAKPOINT         = 12,
    OS_ERROR_SYSTEM_INTERRUPT   = 13,
    OS_ERROR_THERMAL_INTERRUPT  = 14,
    OS_ERROR_PROTECTION         = 15,
    OS_ERROR_FPE                = 16
};

TYPED_ENUM(u32, OSCrashControlMode) {
    OS_CRASH_CONTROL_MODE_NONE      = 0,
    OS_CRASH_CONTROL_MODE_UNHANDLED = 1,
    OS_CRASH_CONTROL_MODE_RESTART   = 2,
    OS_CRASH_CONTROL_MODE_REBOOT    = 3,
    OS_CRASH_CONTROL_MODE_KILL      = 4
};

TYPED_ENUM(u32, OSCrashDumpType) {
    OS_CRASH_DUMP_TYPE_MINI = 0,
    OS_CRASH_DUMP_TYPE_FULL = 1
};

TYPED_ENUM(u32, OSCrashDetailLevel) {
    OS_CRASH_DETAIL_LEVEL_ERROR     = 0,
    OS_CRASH_DETAIL_LEVEL_WARNINGS  = 1,
    OS_CRASH_DETAIL_LEVEL_NOTICES   = 2,
    OS_CRASH_DETAIL_LEVEL_VERBOSE   = 7,

    OS_CRASH_DETAIL_LEVEL_UNDEFINED = 0xFFFFFFFF
};

TYPED_ENUM(s32, OSEventMode) {
    OS_EVENT_MANUAL = 0,
    OS_EVENT_AUTO   = 1
};

TYPED_ENUM(u8, OSExceptionMode) {
    OS_EXCEPTION_MODE_SYSTEM           = 0,
    OS_EXCEPTION_MODE_THREAD           = 1,
    OS_EXCEPTION_MODE_GLOBAL           = 2,
    OS_EXCEPTION_MODE_THREAD_ALL_CORES = 3,
    OS_EXCEPTION_MODE_GLOBAL_ALL_CORES = 4,
};

TYPED_ENUM(u8, OSExceptionType) {
    OS_EXCEPTION_TYPE_SYSTEM_RESET        = 0,
    OS_EXCEPTION_TYPE_MACHINE_CHECK       = 1,
    OS_EXCEPTION_TYPE_DSI                 = 2,
    OS_EXCEPTION_TYPE_ISI                 = 3,
    OS_EXCEPTION_TYPE_EXTERNAL_INTERRUPT  = 4,
    OS_EXCEPTION_TYPE_ALIGNMENT           = 5,
    OS_EXCEPTION_TYPE_PROGRAM             = 6,
    OS_EXCEPTION_TYPE_FLOATING_POINT      = 7,
    OS_EXCEPTION_TYPE_DECREMENTER         = 8,
    OS_EXCEPTION_TYPE_SYSTEM_CALL         = 9,
    OS_EXCEPTION_TYPE_TRACE               = 10,
    OS_EXCEPTION_TYPE_PERFORMANCE_MONITOR = 11,
    OS_EXCEPTION_TYPE_BREAKPOINT          = 12,
    OS_EXCEPTION_TYPE_SYSTEM_INTERRUPT    = 13,
    OS_EXCEPTION_TYPE_ICI                 = 14,
};

TYPED_ENUM(u32, OSFPUExceptionMask) {
    OS_FPSCR_FX     = 0x80000000,
    OS_FPSCR_FEX    = 0x40000000,
    OS_FPSCR_VX     = 0x20000000,
    OS_FPSCR_OX     = 0x10000000,
    OS_FPSCR_UX     = 0x08000000,
    OS_FPSCR_ZX     = 0x04000000,
    OS_FPSCR_XX     = 0x02000000,
    OS_FPSCR_VXSNAN = 0x01000000,
    OS_FPSCR_VXISI  = 0x00800000,
    OS_FPSCR_VXIDI  = 0x00400000,
    OS_FPSCR_VXZDZ  = 0x00200000,
    OS_FPSCR_VXIMZ  = 0x00100000,
    OS_FPSCR_VXVC   = 0x00080000,
    OS_FPSCR_FR     = 0x00040000,
    OS_FPSCR_FI     = 0x00020000,
    OS_FPSCR_VXSOFT = 0x00000400,
    OS_FPSCR_VXSQRT = 0x00000200,
    OS_FPSCR_VXCVI  = 0x00000100,
    OS_FPSCR_VE     = 0x00000080,
    OS_FPSCR_OE     = 0x00000040,
    OS_FPSCR_UE     = 0x00000020,
    OS_FPSCR_ZE     = 0x00000010,
    OS_FPSCR_XE     = 0x00000008,
    OS_FPSCR_NI     = 0x00000004,

    OS_FPSCR_ALL_ENABLE = (OS_FPSCR_VE | OS_FPSCR_OE | OS_FPSCR_UE | OS_FPSCR_ZE | OS_FPSCR_XE),
    OS_FPSCR_ALL_STATUS = (OS_FPSCR_FX | OS_FPSCR_FEX | OS_FPSCR_VX | OS_FPSCR_OX | OS_FPSCR_UX | OS_FPSCR_ZX | OS_FPSCR_XX | OS_FPSCR_VXSNAN | OS_FPSCR_VXISI | OS_FPSCR_VXIDI | OS_FPSCR_VXZDZ | OS_FPSCR_VXIMZ | OS_FPSCR_VXVC | OS_FPSCR_FI | OS_FPSCR_VXSOFT | OS_FPSCR_VXSQRT | OS_FPSCR_VXCVI)
};

// TODO: Work this in to API.
TYPED_ENUM(u32, OSConsoleType) {
    OS_CONSOLE_TYPE_RETAIL      = 0x00000000,
    OS_CONSOLE_TYPE_DEVELOPMENT = 0x10000000,

    OS_CONSOLE_TYPE_MASK        = 0xF0000000
};

TYPED_ENUM(u32, OSSecurityLevel) {
    OS_SECURITY_LEVEL_PROD = 0,
    OS_SECURITY_LEVEL_DEV = 1
};

TYPED_ENUM(u32, OSInfoType) {
    OS_INFO_PMC_THREADS = 0,
    OS_INFO_HDP         = 1
};

TYPED_ENUM(u32, OSInfoOption) {
    OS_INFO_OPTION_NONE = 0
};

TYPED_ENUM(u64, OSTitleID) {
    OS_TITLEID_INVALID  = (u64) -1,
    OS_TITLEID_COLDBOOT = (u64) -2,
    OS_TITLEID_SYSMENU  = (u64) -3
};

TYPED_ENUM(u32, UPID) {
    OS_UPID_KERNEL         = 0,
    OS_UPID_ROOT           = 1,
    OS_UPID_CAFEMENU       = 2,
    OS_UPID_CAFETV         = 3,
    OS_UPID_EMANUAL        = 4,
    OS_UPID_HOMEBUTTONMENU = 5,
    OS_UPID_ERRORDISPLAY   = 6,
    OS_UPID_MINIMIIVERSE   = 7,
    OS_UPID_BROWSER        = 8,
    OS_UPID_MIIVERSE       = 9,
    OS_UPID_ESHOP          = 10,
    OS_UPID_FLV            = 11,
    OS_UPID_DOWNLOADMGR    = 12,
    OS_UPID_GAME           = 15,
    OS_UPID_MINTU          = 16,
    OS_UPID_CABINETU       = 17,
    OS_UPID_TESTOVERLAY    = 31
};

TYPED_ENUM(u32, OSShutdownReason) {
    OS_SHUTDOWN_NO_SHUTDOWN = 0,
    OS_SHUTDOWN_POWER_OFF   = 1,
    OS_SHUTDOWN_RESTART     = 2,
    OS_SHUTDOWN_STANDBY     = 3
};

TYPED_ENUM(u32, OSShutdownFlag) {
    OS_SHUTDOWN_FLAG_NONE        = 0,
    OS_SHUTDOWN_FLAG_APD_REQUEST = 1 << 0
};

TYPED_ENUM(u32, OSPolicyRequest) {
    OS_POLICY_EXIT = 1,
    OS_POLICY_NOTIFY_NET_TO_START = 2,
    OS_POLICY_NOTIFY_NET_TO_END = 3,
    OS_POLICY_NOTIFY_HOME_BUTTON_DENIED = 4
};

TYPED_ENUM(int, OSMapMode) {
    OS_MAP_INVALID   = 0,
    OS_MAP_RO        = 1,
    OS_MAP_RW        = 2,
    OS_MAP_FREE      = 3,
    OS_MAP_ALLOCATED = 4
};

TYPED_ENUM(u32, OSOverlayArenaError) {
    OS_OVERLAY_ARENA_ERROR_INVALID              = -1,
    OS_OVERLAY_ARENA_ERROR_IN_SHUTDOWN          = -3,
    OS_OVERLAY_ARENA_ERROR_TIMEOUT              = -4,
    OS_OVERLAY_ARENA_ERROR_ALREADY_ENABLED      = -5,
    OS_OVERLAY_ARENA_ERROR_NOT_ENABLED          = -6,
    OS_OVERLAY_ARENA_ERROR_UNKNOWN              = -7,
    OS_OVERLAY_ARENA_ERROR_NOT_SET_IN_PLAT_INFO = -8
};

TYPED_ENUM(u32, OSMemType) {
    OS_MEM1 = 1,
    OS_MEM2 = 2
};

TYPED_ENUM(u32, OSShared) {
    OS_SHARED_FONT_CAFECN,
    OS_SHARED_FONT_CAFEKR,
    OS_SHARED_FONT_CAFESTD,
    OS_SHARED_FONT_CAFETW
};

TYPED_ENUM(s32, OSMessageFlag) {
    OS_MESSAGE_NOBLOCK       = 0,
    OS_MESSAGE_BLOCK         = 1,
    OS_MESSAGE_HIGH_PRIORITY = 2
};

TYPED_ENUM(u32, OSSystemMessageData0) {
    OS_SYSTEM_MESSAGE_DATA0_RELEASE_FOREGROUND  = 0xFACEBACC,
    OS_SYSTEM_MESSAGE_DATA0_ACQUIRED_FOREGROUND = 0xFACEF000,
    OS_SYSTEM_MESSAGE_DATA0_EXIT                = 0xD1E0D1E0,
    OS_SYSTEM_MESSAGE_DATA0_NETIO_CHANGE        = 0xAAC0FFEE,
    OS_SYSTEM_MESSAGE_DATA0_HOMEBUTTON_DENIED   = 0xCCC0FFEE,
    OS_SYSTEM_MESSAGE_DATA0_ROOT_RECYCLE        = 0xAAFECAAA
};

TYPED_ENUM(u32, OSSystemMessageData1) {
    OS_SYSTEM_MESSAGE_DATA1_RELEASE_FOREGROUND_SHUTDOWN_FLAG = 1
};

TYPED_ENUM(u32, OSFunctionType) {
    HIO_OPEN = 1,
    HIO_READ_ASYNC,
    HIO_WRITE_ASYNC,
    FSA_CMD_ASYNC,
    FSA_PR_CMD_ASYNC,
    FSA_PR_CMD_ASYNC_NO_ALLOC,
    FSA_ATTACH_EVENT,
    FS_CMD_ASYNC,
    FS_CMD_HANDLER,
    FS_ATTACH_EVENT,
    FS_STATE_CHANGE_EVENT
};

TYPED_ENUM(u32, OSPMMask) {
    PM_MASK_MMCR0 = 1 << 0,
    PM_MASK_MMCR1 = 1 << 1,
    PM_MASK_PMC1  = 1 << 2,
    PM_MASK_PMC2  = 1 << 3,
    PM_MASK_PMC3  = 1 << 4,
    PM_MASK_PMC4  = 1 << 5
};

TYPED_ENUM(u32, OSLogCategory) {
    OS_LOG_CATEGORY_OS       = 0,
    OS_LOG_CATEGORY_OSREPORT = 1,
    OS_LOG_CATEGORY_LOADER   = 2,
    OS_LOG_CATEGORY_APP      = 3,
    OS_LOG_CATEGORY_GFX      = 4,
    OS_LOG_CATEGORY_DRC      = 5,
    OS_LOG_CATEGORY_SOUND    = 6,
    OS_LOG_CATEGORY_FS       = 7,

    OS_LOG_CATEGORY_ALL      = 256
};

TYPED_ENUM(u32, OSLogLevel) {
    OS_LOG_LEVEL_NOISE   = 0,
    OS_LOG_LEVEL_NOTICE  = 1,
    OS_LOG_LEVEL_WARNING = 2,
    OS_LOG_LEVEL_ERROR   = 3
};

TYPED_ENUM(u32, OSLogHeaderUseCase) {
    OS_LOG_HEADER_USE_CASE_DEFAULT    = 0,
    OS_LOG_HEADER_USE_CASE_FUNC_ENTRY = 1,
    OS_LOG_HEADER_USE_CASE_FUNC_EXIT  = 2
};

TYPED_ENUM(u32, OSLogHeaderDataFormat) {
    OS_LOG_HEADER_DATA_FORMAT_PRINT    = 1,
    OS_LOG_HEADER_DATA_FORMAT_FILEFUNC = 2,
    OS_LOG_HEADER_DATA_FORMAT_RAW      = 3
};

TYPED_ENUM(u32, OSLogDataOpt) {
    OS_LOG_DATA_OPT_ARGC_MASK                 = 0xF,
    OS_LOG_DATA_OPT_DATA_FORMAT_MASK          = 0xF << 4,
    OS_LOG_DATA_OPT_DATA_FORMAT_PRINT_MASK    = OS_LOG_HEADER_DATA_FORMAT_PRINT << 4,
    OS_LOG_DATA_OPT_DATA_FORMAT_FILEFUNC_MASK = OS_LOG_HEADER_DATA_FORMAT_FILEFUNC << 4,
    OS_LOG_DATA_OPT_DATA_FORMAT_RAW_MASK      = OS_LOG_HEADER_DATA_FORMAT_RAW << 4,
    OS_LOG_DATA_OPT_PRIVATE_MASK              = 1 << 8,
    OS_LOG_DATA_OPT_FUNC_ENTER_MASK           = 1 << 9,
    OS_LOG_DATA_OPT_FUNC_EXIT_MASK            = 1 << 10,
    OS_LOG_DATA_OPT_KEY_ARG_MASK              = 1 << 11,
    OS_LOG_DATA_OPT_CTX_ARG_MASK              = 1 << 12
};

TYPED_ENUM(u32, OSLogRetrievalOpt) {
    OS_LOG_RETRIEVAL_OPT_EXCLUDE_CORE0_MASK          = 1 << 0,
    OS_LOG_RETRIEVAL_OPT_EXCLUDE_CORE1_MASK          = 1 << 1,
    OS_LOG_RETRIEVAL_OPT_EXCLUDE_CORE2_MASK          = 1 << 2,
    OS_LOG_RETRIEVAL_OPT_EXCLUDE_USER_NOISE_MASK     = 1 << 3,
    OS_LOG_RETRIEVAL_OPT_EXCLUDE_USER_NOTICE_MASK    = 1 << 4,
    OS_LOG_RETRIEVAL_OPT_EXCLUDE_USER_WARNING_MASK   = 1 << 5,
    OS_LOG_RETRIEVAL_OPT_EXCLUDE_USER_ERROR_MASK     = 1 << 6,
    OS_LOG_RETRIEVAL_OPT_EXCLUDE_KERNEL_NOISE_MASK   = 1 << 7,
    OS_LOG_RETRIEVAL_OPT_EXCLUDE_KERNEL_NOTICE_MASK  = 1 << 8,
    OS_LOG_RETRIEVAL_OPT_EXCLUDE_KERNEL_WARNING_MASK = 1 << 9,
    OS_LOG_RETRIEVAL_OPT_EXCLUDE_KERNEL_ERROR_MASK   = 1 << 10,
    OS_LOG_RETRIEVAL_OPT_IGNORE_FILTERS_MASK         = 1 << 11,
    OS_LOG_RETRIEVAL_OPT_IGNORE_SESSION_MISMATCH     = 1 << 12
};

union OSAtomicVar {
    u32   u32Val;
    s32   s32Val;
    void* ptr32Val;
};

union OSLogEntryPayload {
    struct {
        u32 key;
        u32 arg0;
    } __attribute__((packed)) keyOnly;
    struct {
        u32 ctx;
        u32 arg0;
    } __attribute__((packed)) ctxOnly;
    struct {
        u32 key;
        u32 ctx;
        u32 arg0;
    } __attribute__((packed)) keyAndCtx;
} __attribute__((packed));

union OSAtomicVar64 {
    u64 u64Val;
    s64 s64Val;
};

struct OSCalendarTime {
    int sec;
    int min;
    int hour;
    int mday;
    int mon;
    int year;
    int wday;
    int yday;
    int msec;
    int usec;
};

struct OSThreadQueue {
    OSThread* head;
    OSThread* tail;
    void*     parentStruct;
    u32       osReserved;
};

struct OSThreadSmallQueue {
    OSThread* head;
    OSThread* tail;
};

struct OSThreadLink {
    OSThread* next;
    OSThread* prev;
};

struct OSMutexQueue {
    OSMutex* head;
    OSMutex* tail;
    void*    parentStruct;
    u32      osReserved;
};

struct OSMutexLink {
    OSMutex* next;
    OSMutex* prev;
};

struct OSTLSBlock {
    char* address;
    int   status;
};

struct OSFastMutexQueue {
    OSFastMutex* head;
    OSFastMutex* tail;
};

struct OSFastMutexLink {
    OSFastMutex* next;
    OSFastMutex* prev;
};

#define OS_CONTEXT_TXT_TAG1 0x4F53436F
#define OS_CONTEXT_TXT_TAG2 0x6E747874
struct OSContext {
    u32                txtTag1;
    u32                txtTag2;
    u32                gpr[32];
    u32                cr;
    u32                lr;
    u32                ctr;
    u32                xer;
    u32                srr0;
    u32                srr1;
    u32                exceptionSpecific0;
    u32                exceptionSpecific1;
    u32                osReserved1;
    u32                osReserved2;
    u32                fpscrPad;
    u32                fpscr;
    f64                fpr[32];
    u16                spinLockCount;
    OSContextState     state;
    u32                gqr[8];
    u32                pir;
    f64                psf[32];
    u64                coretime[OS_NUM_CORES];
    u64                startTime;
    u32                error;
    OSContextAttribute attributes;
    u32                pmc1;
    u32                pmc2;
    u32                pmc3;
    u32                pmc4;
    u32                mmcr0;
    u32                mmcr1;
};

#define OSTHREAD_TXT_TAG 0x74487244
struct OSThread {
    OSContext               context;
    u32                     txtTag;
    OSThreadState           state;
    OSThreadAttribute       attr;
    OSThreadID              threadId;
    s32                     suspend;
    OSPriority              priority;
    OSPriority              base;
    int                     val;
    OSThreadQueue*          runQueue[OS_NUM_CORES];
    OSThreadLink            linkRun[OS_NUM_CORES];
    OSThreadQueue*          queue;
    OSThreadLink            link;
    OSThreadQueue           queueJoin;
    OSMutex*                mutex;
    OSMutexQueue            queueMutex;
    OSThreadLink            linkActive;
    u8*                     stackBase;
    u32*                    stackEnd;
    OSThreadFunc            entryPoint;
    u8                      crt[0x1D8];
    s32                     alarmCancelled;
    void*                   specific[OS_THREAD_SPECIFIC_MAX];
    OSThreadType            type;
    const char*             name;
    OSAlarm*                waitAlarm;
    u32                     userStackPointer;
    OSThreadCleanupFunc     cleanupCallback;
    OSThreadDeallocatorFunc deallocator;
    OSThreadCancelState     cancelState;
    OSThreadRequestFlag     requestFlag;
    s32                     pendingSuspend;
    s32                     suspendResult;
    OSThreadQueue           suspendQueue;
    u64                     quantumTicks;
    u64                     coretimeSumQuantumStart;
    u64                     wakeCount;
    OSTime                  sumWakeDelta;
    OSTime                  awakenedTime;
    OSTime                  minWakeDelta;
    OSTime                  maxWakeDelta;
    OSExceptionCallback     dsiExCallback[OS_NUM_CORES];
    OSExceptionCallback     isiExCallback[OS_NUM_CORES];
    OSExceptionCallback     programExCallback[OS_NUM_CORES];
    OSExceptionCallback     perfMonExCallback[OS_NUM_CORES];
    u32                     stackSyncObjAllowed;
    short                   numAllocatedTLSImages;
    short                   tlsStatus;
    OSTLSBlock*             tlsImageAddrs;
    OSFastMutex*            waitingFastMutex;
    OSFastMutexQueue        contendedFastMutexes;
    OSFastMutexQueue        ownedFastMutexes;
    OSExceptionCallback     alignExCallback[OS_NUM_CORES];
    u32                     osReserved[5];
};

#define OSALARMQUEUE_TXT_TAG 0x614C6D51
struct OSAlarmQueue {
    u32           txtTag;
    char*         name;
    u32           osReserved;
    OSThreadQueue queue;
    OSAlarm*      head;
    OSAlarm*      tail;
};

#define OSALARM_TXT_TAG 0x614C724D
struct OSAlarm {
    u32            txtTag;
    char*          name;
    u32            osReserved;
    OSAlarmHandler handler;
    u32            tag;
    OSTime         nextFire;
    OSAlarm*       prev;
    OSAlarm*       next;
    OSTime         period;
    OSTime         tbrStart;
    void*          userData;
    OSAlarmState   state;
    OSThreadQueue  waitQueue;
    OSAlarmQueue*  alarmQueue;
    OSContext*     context;
};

#define OSCOND_TXT_TAG  0x634E6456
struct OSCond {
    u32           txtTag;
    char*         name;
    u32           osReserved;
    OSThreadQueue queue;
};

struct OSCoroutine {
    u32 lr;
    u32 cr;
    u32 gqr1;
    u32 r1;
    u32 r2;
    u32 r13;
    u32 gpr[18];
    f64 fpr[18];
    f64 psr[18];
};

struct OSNotifyHdr {
    char* name;
    void* textAddr;
    u32   textOffset;
    u32   textSize;
    void* dataAddr;
    u32   dataOffset;
    u32   dataSize;
    void* readAddr;
    u32   readOffset;
    u32   readSize;
};

struct OSLoaderHeapStatistics {
    u32 codeMemBytesUsed;
    u32 codeUsedNumAllocations;
    u32 codeMemBytesFree;
    u32 codeMemLargestBlockFree;
    u32 dataMemBytesUsed;
    u32 dataUsedNumAllocations;
};

struct OSCrashControl {
    OSCrashControlMode mode;
    void*              message;
    u32                data0;
    u32                data1;
    u32                data2;
};

struct OSCrashInfo {
    OSError error;
    UPID    upid;
    u64     titleid;
};

#define OSEVENT_TXT_TAG 0x65566E54
struct OSEvent {
    u32           txtTag;
    char*         name;
    u32           osReserved;
    bool          state;
    OSThreadQueue queue;
    s32           mode;
};

#define OSFASTCOND_TXT_TAG  0x664E6456
struct OSFastCond {
    u32           txtTag;
    char*         name;
    u32           osReserved;
    OSThreadQueue queue;
};

#define OSFASTMUTEX_TXT_TAG 0x664D7458
struct OSFastMutex {
    u32                txtTag;
    char*              name;
    bool               in_contended_queue;
    OSThreadSmallQueue contendedQueue;
    OSFastMutexLink    ownedLink;
    u32                lock;
    s32                lockCount;
    OSFastMutexLink    contendedLink;
};

struct OSHDPInfo {
    void* hdpStartAddr;
    u32   hdpSize;
};

struct OSSystemInfo {
    u32    busClockSpeed;
    u32    coreClockSpeed;
    OSTime timeBase;
    u32    L2Size[OS_NUM_CORES];
    u32    cpuFreqRatio;
};

struct OSMessage {
    void* message;
    u32   data0;
    u32   data1;
    u32   data2;
};

struct OSDeviceMessage {
    void*          message;
    u32            data0;
    u32            data1;
    OSFunctionType type;
};

#define OSMESSAGEQ_TXT_TAG 0x6D536751
struct OSMessageQueue {
    u32           txtTag;
    char*         name;
    u32           osReserved;
    OSThreadQueue queueSend;
    OSThreadQueue queueReceive;
    OSMessage*    msgArray;
    s32           msgCount;
    s32           firstIndex;
    s32           usedCount;
};

#define OSMUTEX_TXT_TAG 0x6D557458
struct OSMutex {
    u32           txtTag;
    char*         name;
    u32           osReserved;
    OSThreadQueue queue;
    OSThread*     thread;
    s32           count;
    OSMutexLink   link;
};

struct OSRendezvous {
    volatile u32 core[OS_NUM_CORES];
    u32          rendezvousId;
};

#define OSSEMAPHORE_TXT_TAG 0x73506852
struct OSSemaphore {
    u32           txtTag;
    char*         name;
    u32           osReserved;
    s32           count;
    OSThreadQueue queue;
};

struct OSSpinLock {
    u32 spinlock;
    u32 spinlockId;
    u32 recursionCount;
    u32 interrupts_enabled;
};

struct OSLogEntryHeader {
    u32                   size;
    u64                   timeStamp;
    u32                   tag;
    u32                   session    : 8;
    u32                   seqByte    : 8;
    u32                   argc       : 4;
    u32                   keyArg     : 1;
    u32                   ctxArg     : 1;
    OSLogHeaderDataFormat dataFormat : 3;
    OSLogHeaderUseCase    useCase    : 3;
    u32                   unused1    : 4;
    u32                   intEnabled : 1;
    u32                   intPending : 1;
    OSCoreId              coreId     : 2;
    u32                   userMode   : 1;
    u32                   procId     : 6;
    u32                   procCfg    : 2;
    OSLogLevel            level      : 8;
    OSLogCategory         category   : 8;
    u32                   unused2    : 3;
} __attribute__((packed));

struct OSLogEntryFileFuncData {
    u16  lineNumber;
    char funcName[OS_LOG_FUNC_NAME_SIZE_LIMIT];
} __attribute__((packed));

struct OSLogEntryFilterPolicy {
    OSLogCategory category;
    OSLogLevel    level;
} __attribute__((packed));

struct OSLogRetrieval {
    u32              totalSize;
    u32              numberOfEntries;
    u32              currentSession;
    OSLogEntryHeader firstEntry;
} __attribute__((packed));

EXPORT_FUNC_H(OSTick, OSGetTick, void);
EXPORT_FUNC_H(OSTime, OSGetTime, void);
EXPORT_FUNC_H(OSTick, OSGetSystemTick, void);
EXPORT_FUNC_H(OSTime, OSGetSystemTime, void);
EXPORT_FUNC_H(OSTime, OSCalendarTimeToTicks, OSCalendarTime* td);
EXPORT_FUNC_H(void, OSTicksToCalendarTime, OSTime ticks, OSCalendarTime* td);
EXPORT_FUNC_H(void, OSWaitMicroseconds, OSTime microseconds);

EXPORT_FUNC_H(void, OSInitThreadQueue, OSThreadQueue* queue);
EXPORT_FUNC_H(void, OSInitThreadQueueEx, OSThreadQueue* queue, void* parent_struct);

EXPORT_FUNC_H(OSThread*, OSGetCurrentThread, void);
EXPORT_FUNC_H(OSThread*, OSGetDefaultThread, OSCoreId coreId);
EXPORT_FUNC_H(long, OSCheckActiveThreads, void);

EXPORT_FUNC_H(bool, OSCreateThread, OSThread* thread, OSThreadFunc entryPoint, int intArg, void* ptrArg, void* stack, u32 stackSize, OSPriority priority, u16 attr);
EXPORT_FUNC_H(bool, OSCreateThreadType, OSThread* thread, OSThreadFunc entryPoint, int intArg, void* ptrArg, void* stack, u32 stackSize, OSPriority priority, u16 attr, OSThreadType type);
EXPORT_FUNC_H(bool, OSRunThread, OSThread* thread, OSThreadFunc func, int intArg, void* ptrArg);
EXPORT_FUNC_H(void, OSExitThread, int val);
EXPORT_FUNC_H(void, OSCancelThread, OSThread* thread);
EXPORT_FUNC_H(bool, OSJoinThread, OSThread* thread, int* val);
EXPORT_FUNC_H(void, OSDetachThread, OSThread* thread);
EXPORT_FUNC_H(void, OSSleepThread, OSThreadQueue* queue);
EXPORT_FUNC_H(void, OSSleepTicks, OSTime ticks);
EXPORT_FUNC_H(void, OSWakeupThread, OSThreadQueue* queue);
EXPORT_FUNC_H(s32, OSSuspendThread, OSThread* thread);
EXPORT_FUNC_H(s32, OSResumeThread, OSThread* thread);
EXPORT_FUNC_H(void, OSYieldThread, void);
EXPORT_FUNC_H(void, OSContinueThread, OSThread* thread);

EXPORT_FUNC_H(bool, OSIsThreadSuspended, OSThread* thread);
EXPORT_FUNC_H(bool, OSIsThreadTerminated, OSThread* thread);

EXPORT_FUNC_H(bool, OSGetActiveThreadLink, OSThread* thread, OSThreadLink* threadLink);
EXPORT_FUNC_H(void, OSSetThreadName, OSThread* thread, const char* name);
EXPORT_FUNC_H(const char*, OSGetThreadName, OSThread const* thread);
EXPORT_FUNC_H(bool, OSSetThreadPriority, OSThread* thread, OSPriority priority);
EXPORT_FUNC_H(OSPriority, OSGetThreadPriority, OSThread* thread);
EXPORT_FUNC_H(bool, OSSetThreadAffinity, OSThread* thread, OSCoreAffinity affinity);
EXPORT_FUNC_H(OSCoreAffinity, OSGetThreadAffinity, OSThread* thread);
EXPORT_FUNC_H(void*, OSGetThreadSpecific, s32 index);
EXPORT_FUNC_H(void, OSSetThreadSpecific, s32 index, void* ptr);
EXPORT_FUNC_H(OSTime, OSGetThreadCoreTime, const OSThread* thread, OSCoreAffinity affinity);
EXPORT_FUNC_H(bool, OSSetThreadRunQuantum, OSThread* thread, u32 quantumMicrosec);
EXPORT_FUNC_H(OSThreadCleanupFunc, OSSetThreadCleanupCallback, OSThread* thread, OSThreadCleanupFunc callback);
EXPORT_FUNC_H(OSThreadDeallocatorFunc, OSSetThreadDeallocator, OSThread* thread, OSThreadDeallocatorFunc deallocator);

EXPORT_FUNC_H(u32, OSGetUserStackPointer, OSThread* thread);
EXPORT_FUNC_H(bool, OSSetThreadStackUsage, OSThread* thread);
EXPORT_FUNC_H(void, OSClearThreadStackUsage, OSThread* thread);
EXPORT_FUNC_H(s32, OSCheckThreadStackUsage, OSThread* thread);
EXPORT_FUNC_H(void, OSClearStack, u8 val);

EXPORT_FUNC_H(void, OSTestThreadCancel, void);
EXPORT_FUNC_H(bool, OSSetThreadCancelState, bool cancelState);

EXPORT_FUNC_H(bool, OSIsSchedulerLocked, void* lockid);

EXPORT_FUNC_H(u32, OSGetCoreCount, void);
EXPORT_FUNC_H(OSCoreId, OSGetCoreId, void);
EXPORT_FUNC_H(OSCoreId, OSGetMainCoreId, void);
EXPORT_FUNC_H(bool, OSIsMainCore, void);

EXPORT_FUNC_H(void, OSInitAlarmQueue, OSAlarmQueue* queue);
EXPORT_FUNC_H(void, OSInitAlarmQueueEx, OSAlarmQueue* queue, char* name);

EXPORT_FUNC_H(void, OSCreateAlarm, OSAlarm* alarm);
EXPORT_FUNC_H(void, OSCreateAlarmEx, OSAlarm* alarm, char* name);
EXPORT_FUNC_H(bool, OSSetAlarm, OSAlarm* alarm, OSTime tick, OSAlarmHandler handler);
EXPORT_FUNC_H(bool, OSSetPeriodicAlarm, OSAlarm* alarm, OSTime start, OSTime period, OSAlarmHandler handler);
EXPORT_FUNC_H(void, OSSetAlarmTag, OSAlarm* alarm, u32 tag);
EXPORT_FUNC_H(void, OSSetAlarmUserData, OSAlarm* alarm, void* data);
EXPORT_FUNC_H(void*, OSGetAlarmUserData, const OSAlarm* alarm);
EXPORT_FUNC_H(bool, OSCancelAlarm, OSAlarm* alarm);
EXPORT_FUNC_H(void, OSCancelAlarms, u32 tag);
EXPORT_FUNC_H(bool, OSWaitAlarm, OSAlarm* alarm);

EXPORT_FUNC_H(s32, OSAddAtomic, volatile OSAtomicVar* ptr, s32 val);
EXPORT_FUNC_H(u32, OSOrAtomic, volatile OSAtomicVar* ptr, u32 mask);
EXPORT_FUNC_H(u32, OSAndAtomic, volatile OSAtomicVar* ptr, u32 mask);
EXPORT_FUNC_H(u32, OSXorAtomic, volatile OSAtomicVar* ptr, u32 mask);
EXPORT_FUNC_H(u32, OSSwapAtomic, volatile OSAtomicVar* ptr, u32 val);
EXPORT_FUNC_H(bool, OSCompareAndSwapAtomic, volatile OSAtomicVar* ptr, u32 cmpVal, u32 newVal);
EXPORT_FUNC_H(bool, OSCompareAndSwapAtomicEx, volatile OSAtomicVar* ptr, u32 cmpVal, u32 newVal, u32* origVal);
EXPORT_FUNC_H(bool, OSTestAndSetAtomic, volatile OSAtomicVar* ptr, u32 bitnum);
EXPORT_FUNC_H(bool, OSTestAndClearAtomic, volatile OSAtomicVar* ptr, u32 bitnum);

EXPORT_FUNC_H(u64, OSGetAtomic64, volatile OSAtomicVar64* ptr);
EXPORT_FUNC_H(u64, OSSetAtomic64, volatile OSAtomicVar64* ptr, u64 val);
EXPORT_FUNC_H(s64, OSAddAtomic64, volatile OSAtomicVar64* ptr, s64 val);
EXPORT_FUNC_H(u64, OSOrAtomic64, volatile OSAtomicVar64* ptr, u64 mask);
EXPORT_FUNC_H(u64, OSAndAtomic64, volatile OSAtomicVar64* ptr, u64 mask);
EXPORT_FUNC_H(u64, OSXorAtomic64, volatile OSAtomicVar64* ptr, u64 mask);
EXPORT_FUNC_H(u64, OSSwapAtomic64, volatile OSAtomicVar64* ptr, u64 val);
EXPORT_FUNC_H(bool, OSCompareAndSwapAtomic64, volatile OSAtomicVar64* ptr, u64 cmpVal, u64 newVal);
EXPORT_FUNC_H(bool, OSCompareAndSwapAtomicEx64, volatile OSAtomicVar64* ptr, u64 cmpVal, u64 newVal, u64* origVal);
EXPORT_FUNC_H(bool, OSTestAndSetAtomic64, volatile OSAtomicVar64* ptr, u32 bitnum);
EXPORT_FUNC_H(bool, OSTestAndClearAtomic64, volatile OSAtomicVar64* ptr, u32 bitnum);

EXPORT_FUNC_H(bool, OSIsAddressRangeDCValid, const void* addr, u32 nBytes);

EXPORT_FUNC_H(void, OSMemoryBarrier, void);
EXPORT_FUNC_H(void, OSCoherencyBarrier, void);

EXPORT_FUNC_H(bool, OSCopyToClipboard, const void* ptr, u32 size);
EXPORT_FUNC_H(bool, OSCopyFromClipboard, void* ptr, u32* pSize);

EXPORT_FUNC_H(void, OSGetCodegenVirtAddrRange, va_t* va, size_t* size);
EXPORT_FUNC_H(u32, OSGetCodegenCore, void);
EXPORT_FUNC_H(u32, OSGetCodegenMode, void);
EXPORT_FUNC_H(bool, OSSwitchSecCodeGenMode, OSSecCodeGenMode mode);
EXPORT_FUNC_H(OSSecCodeGenMode, OSGetSecCodeGenMode, void);
EXPORT_FUNC_H(bool, OSCodegenCopy, void* dst, const void* src, size_t size);

EXPORT_FUNC_H(void, OSInitCond, OSCond* cond);
EXPORT_FUNC_H(void, OSInitCondEx, OSCond* cond, char* name);
EXPORT_FUNC_H(void, OSWaitCond, OSCond* cond, OSMutex* mutex);
EXPORT_FUNC_H(void, OSSignalCond, OSCond* cond);

EXPORT_FUNC_H(u32, OSGetStackPointer, void);
EXPORT_FUNC_H(u32, OSSwitchStack, u32 newSP);

EXPORT_FUNC_H(int, OSSwitchFiber, u32 pc, u32 newSP);
EXPORT_FUNC_H(int, OSSwitchFiberEx, u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 pc, u32 newSP);

EXPORT_FUNC_H(void, OSSetCurrentContext, OSContext* context);
EXPORT_FUNC_H(OSContext*, OSGetCurrentContext, void);
EXPORT_FUNC_H(u32, OSSaveContext, OSContext* context);
EXPORT_FUNC_H(void, OSLoadContext, OSContext* context);
EXPORT_FUNC_H(void, OSClearContext, OSContext* context);
EXPORT_FUNC_H(void, OSInitContext, OSContext* context, u32 pc, u32 sp);

EXPORT_FUNC_H(OSContext*, OSGetCurrentFPUContext, void);
EXPORT_FUNC_H(void, OSSetCurrentFPUContext, OSContext* context);
EXPORT_FUNC_H(void, OSLoadFPUContext, OSContext* context);
EXPORT_FUNC_H(void, OSSaveFPUContext, OSContext* context);
EXPORT_FUNC_H(void, OSDumpContext, OSContext* context);

EXPORT_FUNC_H(void, OSInitCoroutine, OSCoroutine* coroutine, void* pc, void* sp);
EXPORT_FUNC_H(void, OSLoadCoroutine, OSCoroutine* coroutine, void* retval);
EXPORT_FUNC_H(void*, OSSaveCoroutine, OSCoroutine* coroutine);
EXPORT_FUNC_H(void, OSSwitchCoroutine, OSCoroutine* current, OSCoroutine* next);

EXPORT_FUNC_H(bool, OSIsDebuggerPresent, void);
EXPORT_FUNC_H(bool, OSIsDebuggerInitialized, void);

EXPORT_FUNC_H(void, OSReport, const char* msg, ...);
EXPORT_FUNC_H(void, OSVReport, const char* msg, va_list list);
EXPORT_FUNC_H(void, OSReportWarn, const char* msg, ...);
EXPORT_FUNC_H(void, OSReportInfo, const char* msg, ...);
EXPORT_FUNC_H(void, OSReportVerbose, const char* msg, ...);

EXPORT_FUNC_H(void, OSConsoleWrite, const char* buf, unsigned long len);
EXPORT_FUNC_H(void, OSSupressConsoleOutput, bool umSuppress, bool appSuppress, bool kmSuppress);

EXPORT_FUNC_H(void, COSWarn, u32 module, const char* msg, ...);
EXPORT_FUNC_H(void, COSInfo, u32 module, const char* msg, ...);
EXPORT_FUNC_H(void, COSVerbose, u32 module, const char* msg, ...);
EXPORT_FUNC_H(void, COSError, u32 module, const char* msg, ...);
EXPORT_FUNC_H(void, COSVReport, u32 module, const char* msg, va_list list);

EXPORT_FUNC_H(int, OSDynLoad_GetNumberOfRPLs, void);
EXPORT_FUNC_H(bool, OSDynLoad_GetRPLInfo, u32 index, u32 count, OSNotifyHdr* infobuffer);

EXPORT_FUNC_H(OSDynLoadError, OSDynLoad_AddNotifyCallback, OSNotifyFunc func, void* userArg);
EXPORT_FUNC_H(void, OSDynLoad_DelNotifyCallback, OSNotifyFunc func, void* userArg);

EXPORT_FUNC_H(OSDynLoadError, OSDynLoad_SetAllocator, OSMemAllocFunc alloc, OSMemFreeFunc free);
EXPORT_FUNC_H(OSDynLoadError, OSDynLoad_GetAllocator, OSMemAllocFunc* retAlloc, OSMemFreeFunc* retFree);

EXPORT_FUNC_H(OSDynLoadError, OSDynLoad_SetTLSAllocator, OSMemAllocFunc alloc, OSMemFreeFunc free);
EXPORT_FUNC_H(OSDynLoadError, OSDynLoad_GetTLSAllocator, OSMemAllocFunc* retAlloc, OSMemFreeFunc* retFree);

EXPORT_FUNC_H(OSDynLoadError, OSDynLoad_Acquire, const char* baseModuleName, OSModuleHandle* retHandle);
EXPORT_FUNC_H(OSDynLoadError, OSDynLoad_AcquireContainingModule, void* object, OSSegmentRestrictionFlags restrictFlags, OSModuleHandle* retHandle);
EXPORT_FUNC_H(void, OSDynLoad_Release, OSModuleHandle moduleHandle);
EXPORT_FUNC_H(OSDynLoadError, OSDynLoad_IsModuleLoaded, const char* fileName, OSModuleHandle* retHandle);
EXPORT_FUNC_H(OSDynLoadError, OSDynLoad_GetModuleName, OSModuleHandle moduleHandle, char* retBuffer, int* bufferSize);
EXPORT_FUNC_H(OSDynLoadError, OSDynLoad_FindExport, OSModuleHandle moduleHandle, int isData, const char* exportName, void** retAddr);
EXPORT_FUNC_H(OSDynLoadError, OSDynLoad_FindTag, OSModuleHandle moduleHandle, const char* tag, char* retBuffer, int* bufferSize);

EXPORT_FUNC_H(OSDynLoadError, OSDynLoad_GetLoaderHeapStatistics, OSLoaderHeapStatistics* retLoaderHeapStatistics);

EXPORT_FUNC_H(OSError, OSGetLastError, void);
EXPORT_FUNC_H(void*, OSGetSymbolName, u32 addr, u8* symbolName, u32 nameBufSize);

EXPORT_FUNC_H(void, OSSetPanicCallback, OSPanicCBFunc func, void* arg);

EXPORT_FUNC_H(void, OSGetCrashInfo, OSCrashInfo* info);
EXPORT_FUNC_H(OSCrashDumpType, OSGetCrashDumpType, void);
EXPORT_FUNC_H(void, OSSetCrashDumpType, OSCrashDumpType type);
EXPORT_FUNC_H(OSCrashDetailLevel, OSGetCrashDetailLevel, void);
EXPORT_FUNC_H(void, OSSetCrashDetailLevel, OSCrashDetailLevel type);
EXPORT_FUNC_H(bool, OSRestartCrashedApp, void* args, u32 argsBytes);
EXPORT_FUNC_H(bool, OSRebootCrash, void);

EXPORT_FUNC_H(u32, OSGetTimestampLevel, void);
EXPORT_FUNC_H(void, OSSetTimestampLevel, bool enabled);

EXPORT_FUNC_H(void, OSFatal, const char* msg);
EXPORT_FUNC_H(void, OSPanic, const char* file, int line, const char* msg, ...);

EXPORT_FUNC_H(void, OSInitEvent, OSEvent* event, bool initialState, OSEventMode mode);
EXPORT_FUNC_H(void, OSInitEventEx, OSEvent* event, bool initialState, OSEventMode mode, char* name);
EXPORT_FUNC_H(void, OSSignalEvent, OSEvent* event);
EXPORT_FUNC_H(void, OSSignalEventAll, OSEvent* event);
EXPORT_FUNC_H(void, OSWaitEvent, OSEvent* event);
EXPORT_FUNC_H(void, OSResetEvent, OSEvent* event);
EXPORT_FUNC_H(bool, OSWaitEventWithTimeout, OSEvent* event, OSTime timeout);

EXPORT_FUNC_H(OSExceptionCallback, OSSetExceptionCallback, OSExceptionType exceptionType, OSExceptionCallback callback);
EXPORT_FUNC_H(OSExceptionCallback, OSSetExceptionCallbackEx, OSExceptionMode exceptionMode, OSExceptionType exceptionType, OSExceptionCallback callback);

EXPORT_FUNC_H(void, OSSetDABR, bool allCores, void* address, bool matchReads, bool matchWrites);
EXPORT_FUNC_H(void, OSSetIABR, bool allCores, void* address);

EXPORT_FUNC_H(bool, OSEnableThreadFPUException, OSThread* thread, OSFPUExceptionMask fpuExMask);
EXPORT_FUNC_H(u32, OSEnableAllThreadFPUException, OSFPUExceptionMask fpuExMask);
EXPORT_FUNC_H(bool, OSDisableThreadFPUException, OSThread* thread);
EXPORT_FUNC_H(u32, OSDisableAllThreadFPUException, void);
EXPORT_FUNC_H(void, OSDisableContextFPUException, OSContext* context);

EXPORT_FUNC_H(void, OSFastCond_Init, OSFastCond* fastCond, char* name);
EXPORT_FUNC_H(void, OSFastCond_Wait, OSFastCond* fastCond, OSFastMutex* fastMutex);
EXPORT_FUNC_H(void, OSFastCond_Signal, OSFastCond* fastCond);

EXPORT_FUNC_H(void, OSFastMutex_Init, OSFastMutex* fastMutex, char* name);
EXPORT_FUNC_H(void, OSFastMutex_Lock, OSFastMutex* fastMutex);
EXPORT_FUNC_H(void, OSFastMutex_Unlock, OSFastMutex* fastMutex);
EXPORT_FUNC_H(bool, OSFastMutex_TryLock, OSFastMutex* fastMutex);

EXPORT_FUNC_H(u16, OSReadRegister16, u32 device, u32 id);
EXPORT_FUNC_H(u32, OSReadRegister32, u32 device, u32 id);
EXPORT_FUNC_H(void, OSWriteRegister16, u32 device, u32 id, u16 value);
EXPORT_FUNC_H(void, OSWriteRegister32, u32 device, u32 id, u32 value);

EXPORT_FUNC_H(void, OSEnforceInorderIO, void);

EXPORT_FUNC_H(u64, OSGetOSID, void);
EXPORT_FUNC_H(u32, OSGetConsoleType, void);
EXPORT_FUNC_H(OSSecurityLevel, OSGetSecurityLevel, void);

EXPORT_FUNC_H(bool, OSSetInfo, OSInfoType selector, void* infoSrcAddr, u32 size, OSInfoOption options);
EXPORT_FUNC_H(bool, OSGetInfo, OSInfoType selector, void* infoDestAddr, u32 size, OSInfoOption options);

EXPORT_FUNC_H(OSSystemInfo*, OSGetSystemInfo, void);

EXPORT_FUNC_H(bool, OSDisableInterrupts, void);
EXPORT_FUNC_H(bool, OSEnableInterrupts, void);
EXPORT_FUNC_H(bool, OSRestoreInterrupts, bool level);
EXPORT_FUNC_H(bool, OSIsInterruptEnabled, void);

EXPORT_FUNC_H(OSTitleID, OSGetTitleID, void);

EXPORT_FUNC_H(int, OSLaunchTitlev, u64 titleId, u32 argc, char* argv[]);
EXPORT_FUNC_H(int, OSLaunchTitlel, u64 titleId, u32 argc, ...);
EXPORT_FUNC_H(int, OSLaunchTitleByPathv, const char* path, u32 pathLen, u32 argc, char* argv[]);
EXPORT_FUNC_H(int, OSLaunchTitleByPathl, const char* path, u32 pathLen, u32 argc, ...);

EXPORT_FUNC_H(int, OSRestartGame, u32 argc, char** argv);
EXPORT_FUNC_H(void, OSForceFullRelaunch, void);

EXPORT_FUNC_H(OSShutdownReason, OSGetShutdownReason, void);
EXPORT_FUNC_H(OSShutdownFlag, OSGetShutdownFlags, void);

EXPORT_FUNC_H(void, OSBlockThreadsOnExit, void);
EXPORT_FUNC_H(bool, OSIsBlockThreadsOnExit, void);

EXPORT_FUNC_H(void, OSRunThreadsOnExit, void);

EXPORT_FUNC_H(void, OSSavesDone_ReadyToRelease, void);
EXPORT_FUNC_H(bool, OSRequestFastExit, u32 flags, bool runExit);

EXPORT_FUNC_H(void, OSEnableForegroundExit, void);
EXPORT_FUNC_H(void, OSReleaseForeground, void);
EXPORT_FUNC_H(bool, OSGetForegroundBucket, void** retArea, u32* retSizeBytes);
EXPORT_FUNC_H(bool, OSGetForegroundBucketFreeArea, void** retArea, u32* retSizeBytes);

EXPORT_FUNC_H(bool, OSSendAppSwitchRequest, UPID procId, void* args, u32 argsBytes);
EXPORT_FUNC_H(bool, OSGetCallArgs, UPID* retCaller, u8* buffer, u32 bufferBytes);
EXPORT_FUNC_H(void, OSGetArgcArgv, int* retArgc, char const*** retArgv);

EXPORT_FUNC_H(bool, OSSetScreenCapturePermission, bool enabled);
EXPORT_FUNC_H(bool, OSGetScreenCapturePermission, void);
EXPORT_FUNC_H(bool, OSSetScreenCapturePermissionEx, bool tvEnabled, bool drcEnabled);
EXPORT_FUNC_H(bool, OSGetScreenCapturePermissionEx, bool* tvEnabled, bool* drcEnabled);

EXPORT_FUNC_H(bool, OSIsHomeButtonMenuEnabled, void);
EXPORT_FUNC_H(bool, OSEnableHomeButtonMenu, bool enable);

EXPORT_FUNC_H(bool, OSIsColdBoot, void);
EXPORT_FUNC_H(bool, OSIsSelfRefreshBoot, void);
EXPORT_FUNC_H(bool, OSIsNormalBoot, void);
EXPORT_FUNC_H(bool, OSIsECOBoot, void);
EXPORT_FUNC_H(bool, OSIsStandbyBoot, void);
EXPORT_FUNC_H(bool, OSIsOffBoot, void);
EXPORT_FUNC_H(bool, OSIsCompatBoot, void);
EXPORT_FUNC_H(bool, OSIsProdMode, void);
EXPORT_FUNC_H(bool, OSIsECOMode, void);

EXPORT_FUNC_H(bool, OSSendPolicyRequest, OSPolicyRequest policy, UPID targetProcId);

EXPORT_FUNC_H(va_t, OSAllocVirtAddr, va_t va, size_t size, size_t align);
EXPORT_FUNC_H(bool, OSFreeVirtAddr, va_t va, size_t size);
EXPORT_FUNC_H(int, OSQueryVirtAddr, va_t va);

EXPORT_FUNC_H(void, OSGetMapVirtAddrRange, va_t* va, size_t* size);
EXPORT_FUNC_H(void, OSGetDataPhysAddrRange, pa_t* dataPA, size_t* dataSize);
EXPORT_FUNC_H(void, OSGetAvailPhysAddrRange, pa_t* availPA, size_t* availSize);
EXPORT_FUNC_H(pa_t, OSEffectiveToPhysical, va_t va);

EXPORT_FUNC_H(bool, OSMapMemory, va_t va, pa_t pa, size_t size, OSMapMode mode);
EXPORT_FUNC_H(bool, OSUnmapMemory, va_t va, size_t size);

EXPORT_FUNC_H(OSOverlayArenaError, OSGetMemBound, OSMemType memType, u32* retStart, u32* retSizeBytes);
EXPORT_FUNC_H(OSOverlayArenaError, OSSetMemBound, OSMemType memType, u32 start, u32 sizeBytes);

EXPORT_FUNC_H(void*, OSAllocFromSystem, u32 size, int align);
EXPORT_FUNC_H(void, OSFreeToSystem, void* ptr);
EXPORT_FUNC_H(bool, OSIsAddressValid, void* addr);

EXPORT_FUNC_H(void*, OSBlockMove, void* dst, const void* src, size_t size, bool flush);
EXPORT_FUNC_H(void*, OSBlockSet, void* dst, u8 val, size_t size);

EXPORT_FUNC_H(bool, OSGetSharedData, OSShared shared, u32 flags, void** retArea, u32* retSizeBytes);

EXPORT_FUNC_H(bool, OSIsEnabledOverlayArenaDev, void);
EXPORT_FUNC_H(void, OSEnableOverlayArenaDev, bool allowAV, u32* addr, u32* size);
EXPORT_FUNC_H(bool, OSEnableOverlayArenaWithTimeoutDev, bool allowAV, u32 timeout, u32* error, u32* addr, u32* size);
EXPORT_FUNC_H(void, OSDisableOverlayArenaDev, void);
EXPORT_FUNC_H(bool, OSDisableOverlayArenaWithTimeoutDev, u32 timeout, u32* error);
EXPORT_FUNC_H(void, OSGetOverlayArenaRangeDev, u32* addr, u32* size);

EXPORT_FUNC_H(void, OSInitMessageQueue, OSMessageQueue* queue, OSMessage* msgArray, s32 msgCount);
EXPORT_FUNC_H(void, OSInitMessageQueueEx, OSMessageQueue* queue, OSMessage* msgArray, s32 msgCount, char* name);
EXPORT_FUNC_H(bool, OSSendMessage, OSMessageQueue* queue, OSMessage* msg, OSMessageFlag flags);
EXPORT_FUNC_H(bool, OSReceiveMessage, OSMessageQueue* queue, OSMessage* msg, OSMessageFlag flags);
EXPORT_FUNC_H(bool, OSPeekMessage, OSMessageQueue* queue, OSMessage* msg);

EXPORT_FUNC_H(OSMessageQueue*, OSGetSystemMessageQueue, void);
EXPORT_FUNC_H(OSMessageQueue*, OSGetDefaultAppIOQueue, void);

EXPORT_FUNC_H(void, OSInitMutex, OSMutex* mutex);
EXPORT_FUNC_H(void, OSInitMutexEx, OSMutex* mutex, char* name);
EXPORT_FUNC_H(void, OSLockMutex, OSMutex* mutex);
EXPORT_FUNC_H(void, OSUnlockMutex, OSMutex* mutex);
EXPORT_FUNC_H(bool, OSTryLockMutex, OSMutex* mutex);

EXPORT_FUNC_H(u32, OSGetBootPMFlags, void);
EXPORT_FUNC_H(u32, OSGetLastPMState, void);
EXPORT_FUNC_H(u32, OSGetCurrentPMState, void);

EXPORT_FUNC_H(void, OSSetPerformanceMonitor, OSPMMask pmMask, u32 mmcr0, u32 mmcr1, u32 pmc1, u32 pmc2, u32 pmc3, u32 pmc4);

EXPORT_FUNC_H(void, OSInitRendezvous, OSRendezvous* ren);
EXPORT_FUNC_H(bool, OSWaitRendezvous, OSRendezvous* ren, u32 mask);
EXPORT_FUNC_H(bool, OSWaitRendezvousWithTimeout, OSRendezvous* ren, u32 mask, OSTime timeout);

EXPORT_FUNC_H(int, __os_snprintf, char* s, int n, const char * format, ...);
EXPORT_FUNC_H(void, OSScreenInit, void);
EXPORT_FUNC_H(void, OSScreenShutdown, void);
EXPORT_FUNC_H(void, OSScreenEnableEx, int bufferId, bool enable);
EXPORT_FUNC_H(size_t, OSScreenGetBufferSizeEx, int bufferId);
EXPORT_FUNC_H(void, OSScreenSetBufferEx, int bufferId, void* buffer);
EXPORT_FUNC_H(void, OSScreenFlipBuffersEx, int bufferId);
EXPORT_FUNC_H(void, OSScreenClearBufferEx, int bufferId, u32 color);
EXPORT_FUNC_H(void, OSScreenPutPixelEx, int bufferId, u32 x, u32 y, u32 color);
EXPORT_FUNC_H(void, OSScreenPutFontEx, int bufferId, u32 x, u32 y, const char* str);

EXPORT_FUNC_H(void, OSInitSemaphore, OSSemaphore* sem, s32 count);
EXPORT_FUNC_H(void, OSInitSemaphoreEx, OSSemaphore* sem, s32 count, char* name);
EXPORT_FUNC_H(s32, OSWaitSemaphore, OSSemaphore* sem);
EXPORT_FUNC_H(s32, OSTryWaitSemaphore, OSSemaphore* sem);
EXPORT_FUNC_H(s32, OSSignalSemaphore, OSSemaphore* sem);
EXPORT_FUNC_H(s32, OSGetSemaphoreCount, OSSemaphore* sem);

EXPORT_FUNC_H(void, OSInitSpinLock, OSSpinLock* spinlock);
EXPORT_FUNC_H(bool, OSAcquireSpinLock, OSSpinLock* spinlock);
EXPORT_FUNC_H(bool, OSTryAcquireSpinLock, OSSpinLock* spinlock);
EXPORT_FUNC_H(bool, OSTryAcquireSpinLockWithTimeout, OSSpinLock* spinlock, OSTime timeout);
EXPORT_FUNC_H(bool, OSReleaseSpinLock, OSSpinLock* spinlock);

EXPORT_FUNC_H(bool, OSUninterruptibleSpinLock_Acquire, OSSpinLock* inSpinlock);
EXPORT_FUNC_H(bool, OSUninterruptibleSpinLock_TryAcquire, OSSpinLock* inSpinLock);
EXPORT_FUNC_H(bool, OSUninterruptibleSpinLock_TryAcquireWithTimeout, OSSpinLock* inSpinLock, OSTime timeout);
EXPORT_FUNC_H(bool, OSUninterruptibleSpinLock_Release, OSSpinLock* inSpinlock);

EXPORT_FUNC_H(void, OSLogBuffer, OSLogCategory category, OSLogLevel level, OSLogDataOpt options, void* pBuffer, size_t size);
EXPORT_FUNC_H(void, OSLogArgs, OSLogCategory category, OSLogLevel level, OSLogDataOpt options, u32 seqByte, u32 arg0, u32 arg1, u32 arg2, u32 arg3);
EXPORT_FUNC_H(void, OSLogFunc, OSLogCategory category, OSLogLevel level, OSLogDataOpt options, const char* funcName, u32 funcNameSize, u32 lineNumber, u32* argv, u32 argc);
EXPORT_FUNC_H(void, OSLogPrintf, OSLogCategory category, OSLogLevel level, OSLogDataOpt options, const char* fmt, ...);
EXPORT_FUNC_H(void, OSLogSetFilterPolicy, OSLogCategory category, OSLogLevel minimumLevel);
EXPORT_FUNC_H(bool, OSLogReport, OSLogRetrievalOpt retrievalOptions, void* pWorkspace, u32 workSpaceSize);
EXPORT_FUNC_H(bool, OSLogRetrieve, OSLogRetrievalOpt retrievalOptions, OSLogRetrieval* pRetrieval, u32 maxRetrievedSize);
EXPORT_FUNC_H(bool, OSLogSaveCrashDump, void);

EXPORT_FUNC_H(void, __OSBoostThreadPriority, OSThread* currentThread);
EXPORT_FUNC_H(void, __OSDeboostThreadPrioriy, OSThread* currentThread);

EXPORT_FUNC_H(void, __OSGetAppCrashControl, OSCrashControl* cntl);
EXPORT_FUNC_H(void, __OSSetAppCrashControl, OSCrashControl* cntl);
EXPORT_FUNC_H(void, __OSClearAppCrash, void);

EXPORT_FUNC_H(void, __OSSetTestSetting, const char* name, u32 value);
EXPORT_FUNC_H(u32, __OSGetTestSetting, const char* name);

EXPORT_FUNC_H(u32, __OSSetLaunchTimeout, u32 timeoutMs);

#ifdef __cplusplus
}
#endif
