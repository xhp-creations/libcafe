#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

typedef struct IOSVector IOSVector;

struct IOSVector {
    void*  addr;
    size_t len;
};

EXPORT_FUNC_H(int, IOS_Open, const char* device, int mode);
EXPORT_FUNC_H(int, IOS_Close, int fd);
EXPORT_FUNC_H(int, IOS_Read, int fd, void* addr, size_t len);
EXPORT_FUNC_H(int, IOS_Write, int fd, void* addr, size_t len);
EXPORT_FUNC_H(int, IOS_Seek, int fd, int where, int whence);
EXPORT_FUNC_H(int, IOS_Ioctl, int fd, u32 request, IOSVector in, IOSVector out);
EXPORT_FUNC_H(int, IOS_Ioctlv, int fd, u32 request, u32 numIn, u32 numOut, IOSVector* vectors);

#ifdef __cplusplus
}
#endif