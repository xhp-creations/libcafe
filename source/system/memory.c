#include <wiiu.h>

#include <string.h>

void* _malloc_r(struct _reent* r, size_t size) {
    return (*MEMAllocFromDefaultHeap)(size);
}

void* _memalign_r(struct _reent* r, size_t align, size_t size) {
    if(align < 4) {
        align = 4;
    }

    return (*MEMAllocFromDefaultHeapEx)(size, align);
}

void _free_r(struct _reent* r, void* p) {
    if(p != 0) {
        (*MEMFreeToDefaultHeap)(p);
    }
}

void* _calloc_r(struct _reent* r, size_t n, size_t size) {
    void* p = _malloc_r(r, n * size);
    if(p != 0) {
        memset(p, 0, n * size);
    }

    return p;
}

size_t _malloc_usable_size_r(struct _reent* r, void* p) {
    // TODO
    return 0x7FFFFFFF;
}

void* _realloc_r(struct _reent* r, void* p, size_t size) {
    void* newPtr = _malloc_r(r, size);
    if(newPtr != 0) {
        memcpy(newPtr, p, _malloc_usable_size_r(r, p) < size ? _malloc_usable_size_r(r, p) : size);

        _free_r(r, p);
    }

    return newPtr;
}

void* malloc(size_t size) {
    return _malloc_r(_REENT, size);
}

void* memalign(size_t align, size_t size) {
    return _memalign_r(_REENT, align, size);
}

void free(void* p) {
    _free_r(_REENT, p);
}

void* calloc(size_t n, size_t size) {
    return _calloc_r(_REENT, n, size);
}

size_t malloc_usable_size(void* p) {
    return _malloc_usable_size_r(_REENT, p);
}

void* realloc(void* p, size_t size) {
    return _realloc_r(_REENT, p, size);
}