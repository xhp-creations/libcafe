#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#include <wiiu/dynlib/coreinit/os.h>

typedef struct MPTaskInfo MPTaskInfo;
typedef struct MPTaskFunc MPTaskFunc;
typedef struct MPTask MPTask;
typedef struct MPTaskQInfo MPTaskQInfo;
typedef struct MPTaskQ MPTaskQ;

TYPED_ENUM(u32, MPTaskQState) {
    MP_TASKQ_INIT     = 1 << 0,
    MP_TASKQ_RUN      = 1 << 1,
    MP_TASKQ_STOPPING = 1 << 2,
    MP_TASKQ_STOP     = 1 << 3,
    MP_TASKQ_DONE     = 1 << 4
};

TYPED_ENUM(u32, MPTaskState) {
    MP_TASK_INIT  = 1 << 0,
    MP_TASK_READY = 1 << 1,
    MP_TASK_RUN   = 1 << 2,
    MP_TASK_DONE  = 1 << 3
};

TYPED_ENUM(u32, MPWaitMask) {
    MP_WAIT_TASKQ_RUN  = MP_TASKQ_RUN,
    MP_WAIT_TASKQ_STOP = MP_TASKQ_STOP,
    MP_WAIT_TASKQ_DONE = MP_TASKQ_DONE
};

struct MPTaskInfo {
    MPTaskState state;
    u32         funcResult;
    OSCoreId    coreId;
    OSTime      runTime;
};

struct MPTaskFunc {
    u32   (*func)(void* data, u32 data_len);
    void* data;
    u32   dataLen;
    u32   result;
};

struct MPTask {
    u32         id;
    MPTaskQ*    taskQ;
    MPTaskState state;
    MPTaskFunc  func;
    OSCoreId    coreid;
    OSTime      runtime;
    void*       udata;
};

struct MPTaskQInfo {
    volatile MPTaskQState state;
    u32                   numTask;
    u32                   numTaskReady;
    u32                   numTaskRun;
    u32                   numTaskDone;
};

struct MPTaskQ {
    u32                   id;
    volatile MPTaskQState state;
    u32                   numTask;
    u32                   numTaskReady;
    u32                   numTaskRun;
    u32                   numTaskDone[OS_NUM_CORES];
    s32                   nextIndex[OS_NUM_CORES];
    s32                   endIndex[OS_NUM_CORES];
    MPTask**              queue;
    u32                   queueLen;
    OSSpinLock            spinlock;
};

EXPORT_FUNC_H(void, MPInitTaskQ, MPTaskQ* taskQ, MPTask** taskList, u32 numTasks);
EXPORT_FUNC_H(bool, MPTermTaskQ, MPTaskQ* taskQ);
EXPORT_FUNC_H(bool, MPGetTaskQInfo, MPTaskQ* taskQ, MPTaskQInfo* taskQInfo);
EXPORT_FUNC_H(bool, MPStartTaskQ, MPTaskQ* taskQ);
EXPORT_FUNC_H(bool, MPRunTasksFromTaskQ, MPTaskQ* taskQ, int dequeGranularity);
EXPORT_FUNC_H(bool, MPStopTaskQ, MPTaskQ* taskQ);
EXPORT_FUNC_H(bool, MPWaitTaskQ, MPTaskQ* taskQ, MPWaitMask mask);
EXPORT_FUNC_H(bool, MPWaitTaskQWithTimeout, MPTaskQ* taskQ, MPWaitMask mask, OSTime timeoutNs);
EXPORT_FUNC_H(bool, MPEnqueTask, MPTaskQ* taskQ, MPTask* task);
EXPORT_FUNC_H(MPTask*, MPDequeTask, MPTaskQ* taskQ);
EXPORT_FUNC_H(u32, MPDequeTasks, MPTaskQ* taskQ, MPTask** tasks, int maxTasks);
EXPORT_FUNC_H(bool, MPResetTaskQ, MPTaskQ* taskQ);
EXPORT_FUNC_H(bool, MPPrintTaskQStats, MPTaskQ* taskQ, int size);

EXPORT_FUNC_H(void, MPInitTask, MPTask* task, void* func, void* data, u32 dataLen);
EXPORT_FUNC_H(bool, MPTermTask, MPTask* task);
EXPORT_FUNC_H(bool, MPGetTaskInfo, MPTask* task, MPTaskInfo* taskInfo);
EXPORT_FUNC_H(bool, MPRunTask, MPTask* task);
EXPORT_FUNC_H(void*, MPGetTaskUserData, MPTask* task);
EXPORT_FUNC_H(void, MPSetTaskUserData, MPTask* task, void* userData);

#ifdef __cplusplus
}
#endif