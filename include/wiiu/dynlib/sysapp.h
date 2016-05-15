#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#include <wiiu/dynlib/coreinit/os.h>

typedef struct SYSStandardArgsIn SYSStandardArgsIn;
typedef struct SYSStandardArgs SYSStandardArgs;
typedef struct SYSBrowserArgsIn SYSBrowserArgsIn;
typedef struct SYSBrowserArgsInForCallbackURL SYSBrowserArgsInForCallbackURL;
typedef struct SYSAccountArgsIn SYSAccountArgsIn;
typedef struct SYSSettingsArgsIn SYSSettingsArgsIn;
typedef struct SYSVodArgs SYSVodArgs;
typedef struct SYSArgBase SYSArgBase;
typedef struct SYSArgU32 SYSArgU32;
typedef struct SYSArgU64 SYSArgU64;
typedef struct SYSArgDataBlock SYSArgDataBlock;
typedef struct SYSArgConstDataBlock SYSArgConstDataBlock;
typedef struct SYSCallerData SYSCallerData;
typedef struct SYSEShopArgsIn SYSEShopArgsIn;

typedef union SYSArgSlot SYSArgSlot;

TYPED_ENUM(s32, SYSError) {
    SYS_ERROR_NONE                      = 0,
    SYS_ERROR_NO_ARGS                   = 1,
    SYS_ERROR_SERIALIZE_ANCHOR_SIZE_MAX = -40000,
    SYS_ERROR_SERIALIZE_URL_SIZE_MAX    = -50000,
    SYS_ERROR_FATAL                     = -100000
};

TYPED_ENUM(u32, SYSSettingsJumpTo) {
    SYS_SETTINGS_JUMP_TO_TOP         = 0,
    SYS_SETTINGS_JUMP_TO_INTERNET    = 1,
    SYS_SETTINGS_JUMP_TO_DATA_MANAGE = 2,
    SYS_SETTINGS_JUMP_TO_TV_REMOTE   = 3,
    SYS_SETTINGS_JUMP_TO_DATE_TIME   = 4,
    SYS_SETTINGS_JUMP_TO_COUNTRY     = 5,
    SYS_SETTINGS_JUMP_TO_UPDATE      = 6,
};

TYPED_ENUM(u32, SYSArgType) {
    SYS_ARG_TYPE_NODATA           = 0,
    SYS_ARG_TYPE_U32              = 1,
    SYS_ARG_TYPE_U64              = 2,
    SYS_ARG_TYPE_DATA_BLOCK       = 3,
    SYS_ARG_TYPE_CONST_DATA_BLOCK = 4
};

TYPED_ENUM(u32, SYSArgID) {
    SYS_ARG_ID_TERMINATOR    = 0,
    SYS_ARG_ID_ANCHOR        = 100,
    SYS_ARG_ID_RESULT        = 101,
    SYS_ARG_ID_VOD_URL       = 200,
    SYS_ARG_ID_MIIVERSE_DATA = 300,
    SYS_ARG_ID_JOIN_PID      = 400
};

TYPED_ENUM(u32, SYSCallerType) {
    SYS_CALLER_TYPE_INVALID       = -1,
    SYS_CALLER_TYPE_LAUNCHER      = 2,
    SYS_CALLER_TYPE_TVII          = 3,
    SYS_CALLER_TYPE_HBM           = 5,
    SYS_CALLER_TYPE_MINI_MIIVERSE = 7,
    SYS_CALLER_TYPE_MIIVERSE      = 9,
    SYS_CALLER_TYPE_FRIEND_LIST   = 11,
    SYS_CALLER_TYPE_GAME          = 15
};

TYPED_ENUM(u32, SYSCheckableSystemApplicationID) {
    SYS_CHECK_ID_EMANUAL       = 4,
    SYS_CHECK_ID_MINI_MIIVERSE = 7,
    SYS_CHECK_ID_BROWSER       = 8,
    SYS_CHECK_ID_MIIVERSE      = 9,
    SYS_CHECK_ID_ESHOP         = 10
};

struct SYSStandardArgsIn {
    const char* anchor;
    u32         anchorSize;
};

struct SYSStandardArgs {
    const char* anchor;
    u32         anchorSize;
    char*       result;
    u32         resultSize;
};

struct SYSBrowserArgsIn {
    SYSStandardArgsIn stdIn;
    const char*       url;
    u32               urlSize;
};

struct SYSBrowserArgsInForCallbackURL {
    SYSStandardArgsIn stdIn;
    const char*       url;
    u32               urlSize;
    const char*       callbackURL;
    u32               callbackUrlSize;
    bool              hbmDisable;
};

struct SYSAccountArgsIn {
    SYSStandardArgsIn stdIn;
    u32               slotId;
};

struct SYSSettingsArgsIn {
    SYSStandardArgsIn stdIn;
    SYSSettingsJumpTo jumpTo;
};

struct SYSVodArgs {
    SYSStandardArgs std;
    const char*     url;
    u32             urlSize;
};

struct SYSArgBase {
    SYSArgID   id;
    SYSArgType type;
};

struct SYSArgU32 {
    SYSArgBase base;
    u32        value;
};

struct SYSArgU64 {
    SYSArgBase base;
    u64        value;
};

struct SYSArgDataBlock {
    SYSArgBase base;
    char*      data;
    u32        dataSize;
};

struct SYSArgConstDataBlock {
    SYSArgBase  base;
    const char* data;
    u32         dataSize;
};

struct SYSCallerData {
    SYSCallerType type;
    u64           titleId;
};

struct SYSEShopArgsIn {
    SYSStandardArgsIn stdIn;
    const char*       query;
    u32               querySize;
};

union SYSArgSlot {
    SYSArgBase           base;
    SYSArgU32            u32Val;
    SYSArgU64            u64Val;
    SYSArgDataBlock      blk;
    SYSArgConstDataBlock constBlk;
};

EXPORT_FUNC_H(SYSError, SYSGetVodArgs, SYSVodArgs* args);
EXPORT_FUNC_H(SYSError, SYSGetArguments, SYSArgSlot* sysArgSlot, SYSCallerData* caller);
EXPORT_FUNC_H(bool, SYSCheckSystemApplicationExists, SYSCheckableSystemApplicationID id);
EXPORT_FUNC_H(bool, SYSCheckTitleExists, OSTitleID titleId);

EXPORT_FUNC_H(SYSError, SYSRelaunchTitle, u32 argc, char** argv);
EXPORT_FUNC_H(SYSError, SYSLaunchTitle, OSTitleID titleId);
EXPORT_FUNC_H(SYSError, SYSLaunchMenu, void);
EXPORT_FUNC_H(SYSError, SYSLaunchAccount, const SYSAccountArgsIn* args);
EXPORT_FUNC_H(SYSError, SYSLaunchSettings, const SYSSettingsArgsIn* args);
EXPORT_FUNC_H(SYSError, SYSSwitchToBrowser, const SYSBrowserArgsIn* args);
EXPORT_FUNC_H(SYSError, SYSSwitchToBrowserForCallbackURL, const SYSBrowserArgsInForCallbackURL* args);
EXPORT_FUNC_H(SYSError, SYSSwitchToEManual, void);
EXPORT_FUNC_H(SYSError, SYSSwitchToEShop, const SYSEShopArgsIn* args);
EXPORT_FUNC_H(SYSError, SYSSwitchToEShopAocList, const SYSStandardArgsIn* args);
EXPORT_FUNC_H(SYSError, SYSSwitchToEShopTicketList, const SYSStandardArgsIn* args);
EXPORT_FUNC_H(SYSError, SYSSwitchToSyncControllerOnHBM, void);

#ifdef __cplusplus
}
#endif