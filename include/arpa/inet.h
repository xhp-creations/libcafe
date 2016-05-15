#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/dynlib/dynlib.h>

#include <netinet/in.h>

EXPORT_FUNC_H(uint32_t, ntohl, uint32_t val);
EXPORT_FUNC_H(uint32_t, htonl, uint32_t val);
EXPORT_FUNC_H(uint16_t, ntohs, uint16_t val);
EXPORT_FUNC_H(uint16_t, htons, uint16_t val);

EXPORT_FUNC_H(int, inet_aton, const char* cp, struct in_addr* addr);
EXPORT_FUNC_H(char*, inet_ntoa, struct in_addr in);
EXPORT_FUNC_H(const char*, inet_ntop, int af, const void* src, char* dst, socklen_t size);
EXPORT_FUNC_H(int, inet_pton, int af, const char* src, void* dst);

// Extensions
EXPORT_FUNC_H(char*, inet_ntoa_r, struct in_addr in, char* buf);

#ifdef __cplusplus
}
#endif