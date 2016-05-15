#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/dynlib/coreinit/fs.h>

void FSDrvInit(FSClient* client, FSCmdBlock* cmdBlock);
void FSDrvShutdown();

#ifdef __cplusplus
}
#endif