#pragma once

#ifdef __cplusplus
"C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

typedef u32 MCPHandle;

EXPORT_FUNC_H(MCPHandle, MCP_Open, void);
EXPORT_FUNC_H(int, MCP_Close, MCPHandle handle);
EXPORT_FUNC_H(int, MCP_GetOwnTitleInfo, MCPHandle handle, void* data);
EXPORT_FUNC_H(int, MCP_InstallTitleAbort, MCPHandle handle);
EXPORT_FUNC_H(int, MCP_InstallGetInfo, MCPHandle handle, const char* path, void* mcpInfo);
EXPORT_FUNC_H(int, MCP_InstallTitleAsync, MCPHandle handle, const char* path, void* mcpInfo);
EXPORT_FUNC_H(int, MCP_InstallGetProgress, MCPHandle handle, void* buffer);
EXPORT_FUNC_H(int, MCP_InstallSetTargetDevice, MCPHandle handle, int device);
EXPORT_FUNC_H(int, MCP_InstallSetTargetUsb, MCPHandle handle, int device);
EXPORT_FUNC_H(int, MCP_GetLastRawError, void);

#ifdef __cplusplus
}
#endif