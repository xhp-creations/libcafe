#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#define ENV_MAX_VALUE_SIZE 256

EXPORT_FUNC_H(int, ENVGetEnvironmentVariable, const char* key, char* value, u32 valueSize);

#ifdef __cplusplus
}
#endif