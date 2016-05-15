#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/dynlib/dynlib.h>

#include <netinet/in.h>

#define NETDB_INTERNAL -1
#define NETDB_SUCCESS  0
#define HOST_NOT_FOUND 1
#define TRY_AGAIN      2
#define NO_RECOVERY    3
#define NO_DATA        4
#define NO_ADDRESS     NO_DATA

#define AI_PASSIVE     (1 << 0)
#define AI_CANONNAME   (1 << 1)
#define AI_NUMERICHOST (1 << 2)
#define AI_NUMERICSERV (1 << 3)

#define NI_MAXHOST 1025
#define NI_MAXSERV 32

#define NI_NOFQDN      (1 << 0)
#define NI_NUMERICHOST (1 << 1)
#define NI_NAMEREQD    (1 << 2)
#define NI_NUMERICSERV (1 << 3)
#define NI_DGRAM       (1 << 4)

#define	EAI_ADDRFAMILY 1
#define	EAI_AGAIN      2
#define	EAI_BADFLAGS   3
#define	EAI_FAIL       4
#define	EAI_FAMILY     5
#define	EAI_MEMORY     6
#define	EAI_NODATA     7
#define	EAI_NONAME     8
#define	EAI_SERVICE    9
#define	EAI_SOCKTYPE   10
#define	EAI_SYSTEM     11
#define	EAI_BADHINTS   12
#define	EAI_PROTOCOL   13
#define EAI_OVERFLOW   14
#define EAI_INPROGRESS 15
#define	EAI_MAX        16

struct hostent {
    char*   h_name;
    char**  h_aliases;
    int     h_addrtype;
    int     h_length;
    char**  h_addr_list;
#define h_addr h_addr_list[0]
};

struct addrinfo {
    int              ai_flags;
    int              ai_family;
    int              ai_socktype;
    int              ai_protocol;
    socklen_t        ai_addrlen;
    char*            ai_canonname;
    struct sockaddr* ai_addr;
    struct addrinfo* ai_next;
};

#define h_errno (*get_h_errno())

EXPORT_FUNC_H(int*, get_h_errno, void);
EXPORT_FUNC_H(struct hostent*, gethostbyname, const char* name);
EXPORT_FUNC_H(struct hostent*, gethostbyaddr, const void* addr, int len, int type);
EXPORT_FUNC_H(int, getnameinfo, const struct sockaddr* addr, socklen_t addrlen, char* host, socklen_t hostlen, char* serv, socklen_t servlen, int flags);
EXPORT_FUNC_H(int, getaddrinfo, const char* node, const char* service, const struct addrinfo* hints, struct addrinfo** res);
EXPORT_FUNC_H(void, freeaddrinfo, struct addrinfo* res);
EXPORT_FUNC_H(const char*, gai_strerror, int errcode);

// Extensions
EXPORT_FUNC_H(int, getaddrinfo_rs, const char* node, const char* service, const struct addrinfo* hints, struct addrinfo** res);

#ifdef __cplusplus
}
#endif