#include <wiiu.h>

#include <sys/iosupport.h>
#include <sys/time.h>
#include <malloc.h>

static OSSpinLock memLock;

static int __wiiu_lock_init(int* lock, int recursive) {
    if(lock == NULL) {
        return -1;
    }

    OSSpinLock* spinLock = (OSSpinLock*) calloc(1, sizeof(OSSpinLock));
    OSInitSpinLock(spinLock);

    *lock = (int) spinLock;
    return 0;
}

static int __wiiu_lock_close(int* lock) {
    if(lock == NULL || *lock == 0) {
        return -1;
    }

    OSSpinLock* spinLock = (OSSpinLock*) *lock;
    free(spinLock);

    return 0;
}

static int __wiiu_lock_release(int* lock) {
    if(lock == NULL || *lock == 0) {
        return -1;
    }

    OSSpinLock* spinLock = (OSSpinLock*) *lock;
    if(!OSReleaseSpinLock(spinLock)) {
        return -2;
    }

    return 0;
}

static int __wiiu_lock_acquire(int* lock) {
    if(lock == NULL || *lock == 0) {
        return -1;
    }

    OSSpinLock* spinLock = (OSSpinLock*) *lock;
    if(!OSAcquireSpinLock(spinLock)) {
        return -2;
    }

    return 0;
}

static void __wiiu_malloc_lock(struct _reent* r) {
    int ret = 0;
    if(!OSAcquireSpinLock(&memLock)) {
        ret = -1;
    }

    if(r != NULL) {
        r->_errno = ret;
    }
}

static void __wiiu_malloc_unlock(struct _reent* r) {
    int ret = 0;
    if(!OSReleaseSpinLock(&memLock)) {
        ret = -1;
    }

    if(r != NULL) {
        r->_errno = ret;
    }
}

static void __wiiu_exit(int rc) {
    // Perform the homebrew launcher's reload process.
    OSModuleHandle coreinitHandle;
    OSDynLoad_Acquire("coreinit.rpl", &coreinitHandle);

    void (*exit)();
    OSDynLoad_FindExport(coreinitHandle, 0, "exit", (void**) &exit);

    *(u32*) (0x00801400) = 0xDEADC0DE;

    SYSRelaunchTitle(0, 0);
    exit();
}

static int __wiiu_gettod_r(struct _reent* ptr, struct timeval* tp, struct timezone* tz) {
    if(tp != NULL) {
        OSTime time = OSGetTime();

        tp->tv_sec = (time_t) ((time * 4) / OSGetSystemInfo()->busClockSpeed + 946684800);
        tp->tv_usec = (time_t) ((time * 4000000) / OSGetSystemInfo()->busClockSpeed + 946684800000000);
    }

    if(tz != NULL) {
        tz->tz_minuteswest = 0;
        tz->tz_dsttime = 0;
    }

    return 0;
}

int usleep(useconds_t usec) {
    OSSleepTicks(usec * (OSGetSystemInfo()->busClockSpeed / 4) / 1000000);
    return 0;
}

void __wiiu_syscall_install() {
    OSInitSpinLock(&memLock);

    __syscalls.lock_init = __wiiu_lock_init;
    __syscalls.lock_close = __wiiu_lock_close;
    __syscalls.lock_release = __wiiu_lock_release;
    __syscalls.lock_acquire = __wiiu_lock_acquire;

    __syscalls.malloc_lock = __wiiu_malloc_lock;
    __syscalls.malloc_unlock = __wiiu_malloc_unlock;

    __syscalls.exit = __wiiu_exit;

    __syscalls.gettod_r = __wiiu_gettod_r;
}

void __wiiu_syscall_uninstall() {
    __syscalls.lock_init = NULL;
    __syscalls.lock_close = NULL;
    __syscalls.lock_release = NULL;
    __syscalls.lock_acquire = NULL;

    __syscalls.malloc_lock = NULL;
    __syscalls.malloc_unlock = NULL;

    __syscalls.exit = NULL;

    __syscalls.gettod_r = NULL;
}