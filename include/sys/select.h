#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/dynlib/dynlib.h>

#include <sys/time.h>

EXPORT_FUNC_H(int, select, int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, struct timeval* timeout);

#ifdef __cplusplus
}
#endif