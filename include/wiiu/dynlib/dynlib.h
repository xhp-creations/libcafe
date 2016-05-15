#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define EXPORT_FUNC_H(ret, name, ...) extern ret (*name)(__VA_ARGS__);
#define EXPORT_FUNC_C(ret, name, ...) ret (*name)(__VA_ARGS__) = 0;

#define EXPORT_DATA_H(type, name) extern type* name;
#define EXPORT_DATA_C(type, name) type* name;

#define EXPORT_DATA_FUNC_H(ret, name, ...) extern ret (**name)(__VA_ARGS__);
#define EXPORT_DATA_FUNC_C(ret, name, ...) ret (**name)(__VA_ARGS__) = 0;

#define EXPORT_SET(ptr, name) name = ptr;

#define EXPORT_FIND(libhandle, name, data)                                                      \
    name = NULL;                                                                                \
    if(OSDynLoad_FindExport(libhandle, data, #name, (void**) &name) != OS_DYNLOAD_ERROR_NONE) { \
        OSFatal("Failed to find export "#name".");                                              \
    }

#define EXPORT_FIND_FUNC(libhandle, name) EXPORT_FIND(libhandle, name, 0)
#define EXPORT_FIND_DATA(libhandle, name) EXPORT_FIND(libhandle, name, 1)

#ifdef __cplusplus
}
#endif