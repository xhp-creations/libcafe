#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#include <wiiu/dynlib/coreinit/os.h>

typedef struct MEMLink MEMLink;
typedef struct MEMList MEMList;
typedef struct MEMiHeapHead MEMiHeapHead;
typedef struct MEMAllocator MEMAllocator;
typedef struct MEMAllocatorFunc MEMAllocatorFunc;
typedef struct MEMBlockHeap MEMBlockHeap;
typedef struct MEMiExpHeapMBlockHead MEMiExpHeapMBlockHead;
typedef struct MEMiExpMBlockList MEMiExpMBlockList;
typedef struct MEMiExpHeapHead MEMiExpHeapHead;
typedef struct MEMiFrmHeapState MEMiFrmHeapState;
typedef struct MEMiFrmHeapHead MEMiFrmHeapHead;
typedef struct MEMiUnitHeapMBlockHead MEMiUnitHeapMBlockHead;
typedef struct MEMiUnitMBlockList MEMiUnitMBlockList;
typedef struct MEMiUnitHeapHead MEMiUnitHeapHead;
typedef struct MEMResourceQueryElement MEMResourceQueryElement;
typedef struct MEMResourceQuery MEMResourceQuery;
typedef struct MEMResourceElement MEMResourceElement;
typedef struct MEMResource MEMResource;

typedef MEMiHeapHead* MEMHeapHandle;

typedef void* (*MEMFuncAllocatorAlloc)(MEMAllocator* allocator, u32 size);
typedef void  (*MEMFuncAllocatorFree) (MEMAllocator* allocator, void* memBlock);
typedef void  (*MEMHeapVisitor)(void* memBlock, MEMHeapHandle heap, u32 userParam);

TYPED_ENUM(u32, MEMArena) {
    MEM_ARENA_1  = 0,
    MEM_ARENA_2  = 1,
    MEM_ARENA_3  = 2,
    MEM_ARENA_4  = 3,
    MEM_ARENA_5  = 4,
    MEM_ARENA_6  = 5,
    MEM_ARENA_7  = 6,
    MEM_ARENA_8  = 7,
    MEM_ARENA_FG = 8
};

TYPED_ENUM(u16, MEMHeapOpt) {
    MEM_HEAP_OPT_ZERO_CLEAR  = 1 << 0,
    MEM_HEAP_OPT_DEBUG_FILL  = 1 << 1,
    MEM_HEAP_OPT_THREAD_SAFE = 1 << 2,
};

TYPED_ENUM(u32, MEMHeapCheckOpt) {
    MEM_HEAP_CHECK_OPT_PRINT_ERROR = 1 << 0
};

TYPED_ENUM(int, MEMHeapFillType){
    MEM_HEAP_FILL_NOUSE = 0,
    MEM_HEAP_FILL_ALLOC = 1,
    MEM_HEAP_FILL_FREE  = 2
};

TYPED_ENUM(u32, MEMExpHeapAllocDir) {
    MEM_EXPHEAP_ALLOC_DIR_FRONT = 0,
    MEM_EXPHEAP_ALLOC_DIR_REAR  = 1
};

TYPED_ENUM(u16, MEMExpHeapAllocMode) {
    MEM_EXPHEAP_ALLOC_MODE_FIRST = 0,
    MEM_EXPHEAP_ALLOC_MODE_NEAR  = 1
};

TYPED_ENUM(int, MEMFrmHeapFreeMode) {
    MEM_FRMHEAP_FREE_HEAD = 1 << 0,
    MEM_FRMHEAP_FREE_TAIL = 1 << 1
};

TYPED_ENUM(u32, MEMResourceFlag) {
    MEM_RESOURCE_FLAG_DMA         = 1 << 0,
    MEM_RESOURCE_FLAG_ITD         = 1 << 1,
    MEM_RESOURCE_FLAG_ITD_PAYLOAD = 1 << 2,
    MEM_RESOURCE_FLAG_IPC         = 1 << 3,
    MEM_RESOURCE_FLAG_INST        = 1 << 4,
    MEM_RESOURCE_FLAG_OVERPROVIDE = 1 << 5
};

struct MEMLink {
    void* prevObject;
    void* nextObject;
};

struct MEMList {
    void* headObject;
    void* tailObject;
    u16   numObjects;
    u16   offset;
};

#define MEM_EXP_HEAP_SIGNATURE 0x45585048
#define MEM_FRM_HEAP_SIGNATURE 0x46524D48
#define MEM_UNIT_HEAP_SIGNATURE 0x554E5448
#define MEM_USER_HEAP_SIGNATURE 0x55535248
#define MEM_BLOCK_HEAP_SIGNATURE 0x424C4B48
struct MEMiHeapHead {
    u32        signature;
    MEMLink    link;
    MEMList    childList;
    void*      heapStart;
    void*      heapEnd;
    OSSpinLock slock;

    union {
        u32 val;
        struct {
            u32        reserved : 24;
            MEMHeapOpt optFlag   :  8;
        }   fields;
    }          attribute;
};

struct MEMAllocator {
    const MEMAllocatorFunc* func;
    void*                   heap;
    u32                     heapParam1;
    u32                     heapParam2;
};

struct MEMAllocatorFunc {
    MEMFuncAllocatorAlloc alloc;
    MEMFuncAllocatorFree  free;
};

struct MEMBlockHeap {
    MEMiHeapHead head;
    u8           nullBlock[36];
    void*        firstBlock;
    void*        lastBlock;
    void*        nextFreeBlock;
    u32          numFreeBlocksLeft;
};

struct MEMiExpHeapMBlockHead {
    union {
        u32 val;
        struct {
            MEMExpHeapAllocDir allocDir  : 1;
            u32                alignment : 23;
            u32                groupID   : 8;
        }   fields;
    }                      attribute;

    u32                    blockSize;
    MEMiExpHeapMBlockHead* mbHeadPrev;
    MEMiExpHeapMBlockHead* mbHeadNext;
    u16                    signature;
};

struct MEMiExpMBlockList {
    MEMiExpHeapMBlockHead* head;
    MEMiExpHeapMBlockHead* tail;
};

struct MEMiExpHeapHead {
    MEMiExpMBlockList mbFreeList;
    MEMiExpMBlockList mbUsedList;
    u16               groupID;

    union {
        u16 val;
        struct
        {
            u16                 reserved        : 14;
            u16                 useMarginOfAlign : 1;
            MEMExpHeapAllocMode allocMode        : 1;
        }   fields;
    }                 feature;
};

struct MEMiFrmHeapState {
    u32               tagName;
    void*             headAllocator;
    void*             tailAllocator;
    MEMiFrmHeapState* prevState;
};

struct MEMiFrmHeapHead {
    void*             headAllocator;
    void*             tailAllocator;
    MEMiFrmHeapState* state;
};

struct MEMiUnitHeapMBlockHead {
    MEMiUnitHeapMBlockHead* mBlkHdNext;
};

struct MEMiUnitMBlockList {
    MEMiUnitHeapMBlockHead* head;
};

struct MEMiUnitHeapHead {
    MEMiUnitMBlockList mbFreeList;
    u32               mBlkSize;
};

struct MEMResourceQueryElement {
    u32             size;
    u32             alignment;
    u32             quantum;
    u32             numQuanta;
    u32             maxQuanta;
    MEMResourceFlag flags;
    u32             links[3];
};

struct MEMResourceQuery {
    u32                      numMemRes;
    MEMResourceQueryElement* memRes;
};

struct MEMResourceElement {
    u32             size;
    u32             alignment;
    u32             quantum;
    u32             numQuanta;
    MEMResourceFlag flags;
    void*           pv;
};

struct MEMResource {
    u32                 numMemRes;
    MEMResourceElement* memRes;
};

EXPORT_FUNC_H(MEMHeapHandle, MEMFindContainHeap, const void* memBlock);
EXPORT_FUNC_H(MEMHeapHandle, MEMFindParentHeap, MEMHeapHandle heap);

EXPORT_FUNC_H(void, MEMDumpHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(bool, MEMCheckHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(u32, MEMSetFillValForHeap, MEMHeapFillType type, u32 val);
EXPORT_FUNC_H(u32, MEMGetFillValForHeap, MEMHeapFillType type);

EXPORT_FUNC_H(void, MEMInitList, MEMList* list, u16 offset);
EXPORT_FUNC_H(void, MEMAppendListObject, MEMList* list, void* object);
EXPORT_FUNC_H(void, MEMPrependListObject, MEMList* list, void* object);
EXPORT_FUNC_H(void, MEMInsertListObject, MEMList* list, void* target, void* object);
EXPORT_FUNC_H(void, MEMRemoveListObject, MEMList* list, void* object);
EXPORT_FUNC_H(void*, MEMGetNextListObject, MEMList* list, void* object);
EXPORT_FUNC_H(void*, MEMGetPrevListObject, MEMList* list, void* object);
EXPORT_FUNC_H(void*, MEMGetNthListObject, MEMList* list, u16 index);

EXPORT_FUNC_H(void, CoreInitDefaultHeap, MEMHeapHandle* mem1, MEMHeapHandle* memFG, MEMHeapHandle* mem2);
EXPORT_FUNC_H(MEMHeapHandle, MEMCreateUserHeapHandle, void* startAddress, u32 size);
EXPORT_DATA_FUNC_H(void*, MEMAllocFromDefaultHeap, u32 size);
EXPORT_DATA_FUNC_H(void*, MEMAllocFromDefaultHeapEx, u32 size, int alignment);
EXPORT_DATA_FUNC_H(void, MEMFreeToDefaultHeap, void* memBlock);

EXPORT_FUNC_H(void*, MEMAllocFromAllocator, MEMAllocator* allocator, u32 size);
EXPORT_FUNC_H(void, MEMFreeToAllocator, MEMAllocator* allocator, void* memBlock);

EXPORT_FUNC_H(void, MEMInitAllocatorForDefaultHeap, MEMAllocator* allocator);
EXPORT_FUNC_H(void, MEMInitAllocatorForBlockHeap, MEMAllocator* allocator, MEMHeapHandle heap, int alignment);
EXPORT_FUNC_H(void, MEMInitAllocatorForExpHeap, MEMAllocator* allocator, MEMHeapHandle heap, int alignment);
EXPORT_FUNC_H(void, MEMInitAllocatorForFrmHeap, MEMAllocator* allocator, MEMHeapHandle heap, int alignment);
EXPORT_FUNC_H(void, MEMInitAllocatorForUnitHeap, MEMAllocator* allocator, MEMHeapHandle heap);

EXPORT_FUNC_H(MEMArena, MEMGetArena, MEMHeapHandle heap);
EXPORT_FUNC_H(MEMHeapHandle, MEMGetBaseHeapHandle, MEMArena arena);
EXPORT_FUNC_H(MEMHeapHandle, MEMSetBaseHeapHandle, MEMArena arena, MEMHeapHandle heap);

EXPORT_FUNC_H(MEMHeapHandle, MEMInitBlockHeap, MEMBlockHeap* tracking, void* start_addr, void* end_addr, void* init_track_mem, u32 init_track_mem_bytes, MEMHeapOpt optFlag);
EXPORT_FUNC_H(int, MEMAddBlockHeapTracking, MEMHeapHandle heap, void* track_mem, u32 track_mem_bytes);
EXPORT_FUNC_H(void*, MEMDestroyBlockHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(void*, MEMAllocFromBlockHeapAt, MEMHeapHandle heap, void* place, u32 size);
EXPORT_FUNC_H(void*, MEMAllocFromBlockHeapEx, MEMHeapHandle heap, u32 size, int alignment);
EXPORT_FUNC_H(void, MEMFreeToBlockHeap, MEMHeapHandle heap, void* memBlock);
EXPORT_FUNC_H(u32, MEMGetTrackingLeftInBlockHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(u32, MEMGetTotalFreeSizeForBlockHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(u32, MEMGetAllocatableSizeForBlockHeapEx, MEMHeapHandle heap, int alignment);

EXPORT_FUNC_H(MEMHeapHandle, MEMCreateExpHeapEx, void* startAddress, u32 size, MEMHeapOpt optFlag);
EXPORT_FUNC_H(void*, MEMDestroyExpHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(void*, MEMAllocFromExpHeapEx, MEMHeapHandle heap, u32 size, int alignment);
EXPORT_FUNC_H(u32, MEMResizeForMBlockExpHeap, MEMHeapHandle heap, void* memBlock, u32 size);
EXPORT_FUNC_H(void, MEMFreeToExpHeap, MEMHeapHandle heap, void* memBlock);
EXPORT_FUNC_H(u32, MEMGetTotalFreeSizeForExpHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(u32, MEMGetAllocatableSizeForExpHeapEx, MEMHeapHandle heap, int alignment);
EXPORT_FUNC_H(u16, MEMSetAllocModeForExpHeap, MEMHeapHandle heap, u16 mode);
EXPORT_FUNC_H(u16, MEMGetAllocModeForExpHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(bool, MEMUseMarginOfAlignmentForExpHeap, MEMHeapHandle heap, bool reuse);
EXPORT_FUNC_H(u16, MEMSetGroupIDForExpHeap, MEMHeapHandle heap, u16 groupID);
EXPORT_FUNC_H(u16, MEMGetGroupIDForExpHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(void, MEMVisitAllocatedForExpHeap, MEMHeapHandle heap, MEMHeapVisitor visitor, u32 userParam);
EXPORT_FUNC_H(u32, MEMGetSizeForMBlockExpHeap, const void* memBlock);
EXPORT_FUNC_H(u16, MEMGetGroupIDForMBlockExpHeap, const void* memBlock);
EXPORT_FUNC_H(u16, MEMGetAllocDirForMBlockExpHeap, const void* memBlock);
EXPORT_FUNC_H(u32, MEMAdjustExpHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(bool, MEMCheckExpHeap, MEMHeapHandle heap, MEMHeapCheckOpt optFlag);
EXPORT_FUNC_H(bool, MEMCheckForMBlockExpHeap, const void* memBlock, MEMHeapHandle heap, MEMHeapCheckOpt optFlag);
EXPORT_FUNC_H(bool, MEMiIsEmptyExpHeap, MEMHeapHandle heap);

EXPORT_FUNC_H(MEMHeapHandle, MEMCreateFrmHeapEx, void* startAddress, u32 size, MEMHeapOpt optFlag);
EXPORT_FUNC_H(void*, MEMDestroyFrmHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(void*, MEMAllocFromFrmHeapEx, MEMHeapHandle heap, u32 size, int alignment);
EXPORT_FUNC_H(void, MEMFreeToFrmHeap, MEMHeapHandle heap, MEMFrmHeapFreeMode mode);
EXPORT_FUNC_H(u32, MEMGetAllocatableSizeForFrmHeapEx, MEMHeapHandle heap, int alignment);
EXPORT_FUNC_H(bool, MEMRecordStateForFrmHeap, MEMHeapHandle heap, u32 tagName);
EXPORT_FUNC_H(bool, MEMFreeByStateToFrmHeap, MEMHeapHandle heap, u32 tagName);
EXPORT_FUNC_H(u32, MEMAdjustFrmHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(u32, MEMResizeForMBlockFrmHeap, MEMHeapHandle heap, void* memBlock, u32 newSize);
EXPORT_FUNC_H(void*, MEMiGetFreeStartForFrmHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(void*, MEMiGetFreeEndForFrmHeap, MEMHeapHandle heap);

EXPORT_FUNC_H(MEMHeapHandle, MEMCreateUnitHeapEx, void* startAddress, u32 heapSize, u32 memBlockSize, int alignment, u16 optFlag);
EXPORT_FUNC_H(void*, MEMDestroyUnitHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(void*, MEMAllocFromUnitHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(void, MEMFreeToUnitHeap, MEMHeapHandle heap, void* memBlock);
EXPORT_FUNC_H(u32, MEMCountFreeBlockForUnitHeap, MEMHeapHandle heap);
EXPORT_FUNC_H(u32, MEMCalcHeapSizeForUnitHeap, u32 memBlockSize, u32 memBlockNum, int alignment);

#ifdef __cplusplus
}
#endif