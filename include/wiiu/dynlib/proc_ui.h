#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#include <wiiu/dynlib/coreinit/os.h>

TYPED_ENUM(s32, ProcUIError) {
    PROCUI_ERROR_OK           = 0,
    PROCUI_ERROR_INVALID_HEAP = -1
};

TYPED_ENUM(u32, ProcUIStatus) {
    PROCUI_STATUS_FOREGROUND = 0,
    PROCUI_STATUS_BACKGROUND = 1,
    PROCUI_STATUS_RELEASING  = 2,
    PROCUI_STATUS_EXIT       = 3
};

TYPED_ENUM(u32, ProcUIMessage) {
    PROCUI_MESSAGE_ACQUIRE     = 0,
    PROCUI_MESSAGE_RELEASE     = 1,
    PROCUI_MESSAGE_EXIT        = 2,
    PROCUI_MESSAGE_NETIO_START = 3,
    PROCUI_MESSAGE_NETIO_STOP  = 4,
    PROCUI_MESSAGE_HBDENIED    = 5
};

typedef void (*ProcUISaveCallbackFunction)  (void);
typedef u32  (*ProcUISaveCallbackFunctionEx)(void*);
typedef u32  (*ProcUICallbackFunction)      (void*);

EXPORT_FUNC_H(void, ProcUIInit, ProcUISaveCallbackFunction func);
EXPORT_FUNC_H(void, ProcUIInitEx, ProcUISaveCallbackFunctionEx func, void* data);
EXPORT_FUNC_H(void, ProcUIShutdown, void);

EXPORT_FUNC_H(bool, ProcUIIsRunning, void);
EXPORT_FUNC_H(bool, ProcUIInForeground, void);
EXPORT_FUNC_H(bool, ProcUIInShutdown, void);

EXPORT_FUNC_H(ProcUIStatus, ProcUISubProcessMessages, bool block);
EXPORT_FUNC_H(ProcUIStatus, ProcUIProcessMessages, bool block);

EXPORT_FUNC_H(void, ProcUIDrawDoneRelease, void);

EXPORT_FUNC_H(u32, ProcUICalcMemorySize, u32 numCallbacks);
EXPORT_FUNC_H(ProcUIError, ProcUISetMemoryPool, void* memory, u32 sizeInBytes);
EXPORT_FUNC_H(void, ProcUISetMEM1Storage, void* data, u32 size);
EXPORT_FUNC_H(void, ProcUISetBucketStorage, void* data, u32 size);

EXPORT_FUNC_H(void, ProcUIClearCallbacks, void);
EXPORT_FUNC_H(void, ProcUISetCallbackStackSize, u32 size);
EXPORT_FUNC_H(void, ProcUIRegisterBackgroundCallback, ProcUICallbackFunction func, void* data, OSTime ticksToDelay);
EXPORT_FUNC_H(void, ProcUIRegisterCallback, ProcUIMessage message, ProcUICallbackFunction func, void* data, s32 priority);
EXPORT_FUNC_H(void, ProcUIRegisterCallbackCore, ProcUIMessage message, ProcUICallbackFunction func, void* data, s32 priority, OSCoreId core);
EXPORT_FUNC_H(void, ProcUISetSaveCallback, ProcUISaveCallbackFunctionEx func, void* data);

#ifdef __cplusplus
}
#endif