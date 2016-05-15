#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

typedef struct IMParameters IMParameters;

TYPED_ENUM(u32, IMState) {
    IM_DISABLE = 0,
    IM_ENABLE  = 1
};

struct IMParameters {
    u32     inactiveSeconds;
    IMState dimEnable;
    u32     dimSeconds;
    IMState apdEnable;
    u32     apdSeconds;
};

EXPORT_FUNC_H(int, IMEnableDim, void);
EXPORT_FUNC_H(int, IMDisableDim, void);
EXPORT_FUNC_H(int, IMIsDimEnabled, IMState* enabled);
EXPORT_FUNC_H(int, IMGetDimPeriod, u32* second);
EXPORT_FUNC_H(int, IMGetTimeBeforeDimming, u32* second);

EXPORT_FUNC_H(int, IMGetDimEnableTV, IMState* enabled);
EXPORT_FUNC_H(int, IMGetDimEnableDRC, IMState* enabled);
EXPORT_FUNC_H(int, IMSetDimEnableTV, IMState enable);
EXPORT_FUNC_H(int, IMSetDimEnableDRC, IMState enable);

EXPORT_FUNC_H(int, IMEnableAPD, void);
EXPORT_FUNC_H(int, IMDisableAPD, void);
EXPORT_FUNC_H(int, IMIsAPDEnabled, IMState* enabled);
EXPORT_FUNC_H(int, IMIsAPDEnabledBySysSettings, IMState* enabled);
EXPORT_FUNC_H(int, IMGetAPDPeriod, u32* second);
EXPORT_FUNC_H(int, IMGetTimeBeforeAPD, u32* second);

EXPORT_FUNC_H(int, IM_GetParameters, IMParameters* params);

#ifdef __cplusplus
}
#endif