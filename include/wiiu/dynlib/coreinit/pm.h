#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

EXPORT_FUNC_H(void, PMBegin, void);
EXPORT_FUNC_H(void, PMEnd, void);
EXPORT_FUNC_H(u32, PMCycles, void);
EXPORT_FUNC_H(u32, PML1FetchMisses, void);
EXPORT_FUNC_H(u32, PML1MissCycles, void);
EXPORT_FUNC_H(u32, PMInstructions, void);

#ifdef __cplusplus
}
#endif