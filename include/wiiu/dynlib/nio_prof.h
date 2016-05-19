#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#define IO_PROF_BUFFER_ALIGN 64

typedef struct IOProfilerStat IOProfilerStat;

TYPED_ENUM(s32, IOProfilerError) {
    IO_PROFILER_ERROR_OK            = 0,
    IO_PROFILER_ERROR_INVALID_ARG   = -3145728,
    IO_PROFILER_ERROR_NOT_AVAILABLE = -3145729,
    IO_PROFILER_ERROR_INVALID_STATE = -3145730,
    IO_PROFILER_ERROR_NOT_READY     = -3145731
};

TYPED_ENUM(u32, IOProfilerFlag) {
    IO_PROFILER_FLAG_NONE              = 0,
    IO_PROFILER_FLAG_RESET_AND_RESTART = 1
};

TYPED_ENUM(u32, IOProfilerChannel) {
    IO_CHANNEL_USB        = 0,
    IO_CHANNEL_NET        = 1,
    IO_CHANNEL_CONTROLLER = 2,
    IO_CHANNEL_SECIO      = 3,
    IO_CHANNEL_FS         = 4,
    IO_CHANNEL_SYS        = 5
};

struct IOProfilerStat {
    IOProfilerChannel channel;
    float             percentBandwidth;
} __attribute__((packed));

EXPORT_FUNC_H(IOProfilerError, IO_ProfilerLibInit, void);
EXPORT_FUNC_H(IOProfilerError, IO_ProfilerLibFinish, void);
EXPORT_FUNC_H(IOProfilerError, IO_ProfilerStartCheckpoint, IOProfilerFlag flags);
EXPORT_FUNC_H(IOProfilerError, IO_ProfilerGetStatsAndEndCheckpoint, IOProfilerFlag flags, u32* duration, IOProfilerStat* stats, int* numStats);
EXPORT_FUNC_H(IOProfilerError, IO_ProfilerGetStatsAndRestartCheckpoint, IOProfilerFlag flags, u32* duration, IOProfilerStat* stats, int* numStats);

#ifdef __cplusplus
}
#endif