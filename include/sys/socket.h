#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/dynlib/dynlib.h>

#include <sys/time.h>
#include <stdint.h>

#define SOL_SOCKET (-1)

#define PF_UNSPEC 0
#define PF_INET   2

#define AF_UNSPEC PF_UNSPEC
#define AF_INET   PF_INET

#define SOCK_STREAM 1
#define SOCK_DGRAM  2

#define MSG_OOB        (1 << 0)
#define MSG_PEEK       (1 << 1)
#define MSG_DONTROUTE  (1 << 2)
#define MSG_NEWPIPE    (1 << 3)
#define MSG_EOR        (1 << 4)
#define MSG_DONTWAIT   (1 << 5)
#define MSG_IP_RECVTTL (1 << 6)

#define SHUT_RD   0
#define SHUT_WR   1
#define SHUT_RDWR 2

#define SO_REUSEADDR 0x0004
#define SO_KEEPALIVE 0x0008
#define SO_DONTROUTE 0x0010
#define SO_BROADCAST 0x0020
#define SO_LINGER    0x0080
#define SO_OOBINLINE 0x0100
#define SO_TCPSACK   0x0200
#define SO_WINSCALE  0x0400
#define SO_SNDBUF    0x1001
#define SO_RCVBUF    0x1002
#define SO_LASTERROR 0x1007
#define SO_TYPE      0x1008
#define SO_HOPCNT    0x1009
#define SO_MAXMSG    0x1010
#define SO_RXDATA    0x1011
#define SO_TXDATA    0x1012
#define SO_MYADDR    0x1013
#define SO_NBIO      0x1014
#define SO_BIO       0x1015
#define SO_NONBLOCK  0x1016
#define SO_KEEPIDLE  0x1019
#define SO_KEEPINTVL 0x101A
#define SO_KEEPCNT   0x101B
#define SO_HDRINCL   0x2000
#define SO_RUSRBUF   0x10000

typedef uint32_t socklen_t;
typedef uint16_t sa_family_t;

struct sockaddr {
    sa_family_t sa_family;
    char        sa_data[];
};

struct sockaddr_storage {
    sa_family_t ss_family;
    char        __ss_padding[32];
};

struct linger {
    int l_onoff;
    int l_linger;
};

EXPORT_FUNC_H(int, accept, int socket, struct sockaddr* address, socklen_t* address_len);
EXPORT_FUNC_H(int, bind, int socket, const struct sockaddr* address, socklen_t address_len);
EXPORT_FUNC_H(int, connect, int socket, const struct sockaddr* address, socklen_t address_len);
EXPORT_FUNC_H(int, getpeername, int socket, struct sockaddr* address, socklen_t* address_len);
EXPORT_FUNC_H(int, getsockname, int socket, struct sockaddr* address, socklen_t* address_len);
EXPORT_FUNC_H(int, getsockopt, int socket, int level, int option_name, void* option_value, socklen_t* option_len);
EXPORT_FUNC_H(int, listen, int socket, int backlog);
EXPORT_FUNC_H(ssize_t, recv, int socket, void* buffer, size_t length, int flags);
EXPORT_FUNC_H(ssize_t, recvfrom, int socket, void* buffer, size_t length, int flags, struct sockaddr* address, socklen_t* address_len);
EXPORT_FUNC_H(ssize_t, send, int socket, const void* buffer, size_t length, int flags);
EXPORT_FUNC_H(ssize_t, sendto, int socket, const void* buffer, size_t length, int flags, const struct sockaddr* address, socklen_t address_len);
EXPORT_FUNC_H(int, setsockopt, int socket, int level, int option_name, const void* option_value, socklen_t option_len);
EXPORT_FUNC_H(int, shutdown, int socket, int how);
EXPORT_FUNC_H(int, socket, int domain, int type, int protocol);

// Extensions

#define SO_SUCCESS         0
#define SO_ENOBUFS         1
#define SO_ETIMEDOUT       2
#define SO_EISCONN         3
#define SO_EOPNOTSUPP      4
#define SO_ECONNABORTED    5
#define SO_EWOULDBLOCK     6
#define SO_ECONNREFUSED    7
#define SO_ECONNRESET      8
#define SO_ENOTCONN        9
#define SO_EALREADY        10
#define SO_EINVAL          11
#define SO_EMSGSIZE        12
#define SO_EPIPE           13
#define SO_EDESTADDRREQ    14
#define SO_ESHUTDOWN       15
#define SO_ENOPROTOOPT     16
#define SO_EHAVEOOB        17
#define SO_ENOMEM          18
#define SO_EADDRNOTAVAIL   19
#define SO_EADDRINUSE      20
#define SO_EAFNOSUPPORT    21
#define SO_EINPROGRESS     22
#define SO_ELOWER          23
#define SO_ENOTSOCK        24
#define SO_EIEIO           27
#define SO_ETOOMANYREFS    28
#define SO_EFAULT          29
#define SO_ENETUNREACH     30
#define SO_EPROTONOSUPPORT 31
#define SO_EPROTOTYPE      32
#define SO_ERROR           41
#define SO_ENOLIBRM        42
#define SO_ELIBNOTREADY    43
#define SO_EBUSY           44
#define SO_EUNKNOWN        45
#define SO_EAPIERROR       46
#define SO_ERANGEINVALID   47
#define SO_ENORESOURCES    48
#define SO_EBADFD          49
#define SO_EABORTED        50
#define SO_EMFILE          51

#define SOLIB_OPT_AVOID_CLOSE_ALL       0x3000
#define SOLIB_OPT_SOCKFD_TBL_INIT_COUNT 0x3001
#define SOLIB_OPT_SOCKBUF_CONSUMPTION   0x3002

#define SO_SOCKBUF_CONSUMPTTION_LOW  (1 << 0)
#define SO_SOCKBUF_CONSUMPTTION_MED  (1 << 1)
#define SO_SOCKBUF_CONSUMPTTION_HIGH (1 << 2)
#define SO_SOCKBUF_CONSUMPTTION_MAX  (1 << 3)

struct recvfrom_multi_buffers {
    void*            buffer;
    unsigned int     bufferlen;
    struct sockaddr* froms;
    unsigned int     fromslen;
    int*             results;
    unsigned int     resultslen;
};

struct sendto_multi_ex_buffers {
    void*            buffer;
    unsigned int     bufferlen;
    int*             datagram_lens;
    unsigned int     datagram_lens_len;
    struct sockaddr* dests;
    unsigned int     destslen;
    int*             results;
    unsigned int     resultslen;
};

EXPORT_FUNC_H(int, socket_lib_init, void);
EXPORT_FUNC_H(int, socket_lib_finish, void);
EXPORT_FUNC_H(int, set_resolver_allocator, void* (*alloc)(uint32_t size), void (*free)(void* ptr));

EXPORT_FUNC_H(int, socketlasterr, void);

EXPORT_FUNC_H(int, socketclose, int socket);
EXPORT_FUNC_H(int, recvfrom_ex, int socket, void* buffer, int len, int flags, struct sockaddr* from, int* fromlen, uint8_t* msg, int msglen);
EXPORT_FUNC_H(int, recvfrom_multi, int socket, int flags, struct recvfrom_multi_buffers* buffs, int recv_datagram_len, int recv_datagram_count, struct timeval* timeout);
EXPORT_FUNC_H(int, sendto_multi, int socket, const void* buffer, int len, int flags, const struct sockaddr* dest_addrs, int dest_count);
EXPORT_FUNC_H(int, sendto_multi_ex, int socket, int flags, struct sendto_multi_ex_buffers* buffs, int send_datagram_count);
EXPORT_FUNC_H(int, setsocklibopt, int liboptname, int optval);
EXPORT_FUNC_H(int, getsocklibopt, int liboptname, int* optval);

#ifdef __cplusplus
}
#endif