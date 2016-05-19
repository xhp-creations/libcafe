#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

typedef u32 HIDDeviceHandle;
typedef s32 HIDError;

typedef struct HIDDevice HIDDevice;
typedef struct HIDClient HIDClient;

TYPED_ENUM(u32, HIDErrorCategory) {
    HID_ERROR_CATEGORY_HID = 29
};

TYPED_ENUM(s32, HIDErrorCode) {
    HID_ERROR_CODE_ALLOC_IPC_BUFFER      = -1,
    HID_ERROR_CODE_INVALID_RM_CMD        = -100,
    HID_ERROR_CODE_INVALID_IOCTLV_CMD    = -102,
    HID_ERROR_CODE_VECTOR_COUNT          = -103,
    HID_ERROR_CODE_MEMORY_BANK           = -104,
    HID_ERROR_CODE_DATA_ALIGNMENT        = -105,
    HID_ERROR_CODE_DATA_SIZE             = -106,
    HID_ERROR_CODE_REQUEST_CANCELLED     = -107,
    HID_ERROR_CODE_REQUEST_TIMEOUT       = -108,
    HID_ERROR_CODE_REQUEST_ABORTED       = -109,
    HID_ERROR_CODE_CLIENT_PRIORITY       = -110,
    HID_ERROR_CODE_INVALID_DEVICE_HANDLE = -111
};

TYPED_ENUM(u32, HIDAttachEvent) {
    HID_ATTACH_EVENT_ATTACH = 0,
    HID_ATTACH_EVENT_DETACH = 1
};

typedef int  (*HIDAttachCallback)(HIDClient* client, HIDDevice* device, HIDAttachEvent event);
typedef void (*HIDCallback)      (HIDDeviceHandle handle, HIDError error, u8* buffer, u32 bytesTransferred, void* userData);

struct HIDDevice {
    HIDDeviceHandle handle;
    u32             physicalDeviceInst;
    u16             vid;
    u16             pid;
    u8              interfaceIndex;
    u8              subClass;
    u8              protocol;
    u16             maxPacketSizeRx;
    u16             maxPacketSizeTx;
};

struct HIDClient {
    HIDClient*        next;
    HIDAttachCallback attachCallback;
};

EXPORT_FUNC_H(HIDError, HIDSetup, void);
EXPORT_FUNC_H(HIDError, HIDTeardown, void);
EXPORT_FUNC_H(HIDError, HIDAddClient, HIDClient* client, HIDAttachCallback attachCallback);
EXPORT_FUNC_H(HIDError, HIDDelClient, HIDClient* client);
EXPORT_FUNC_H(HIDError, HIDGetDescriptor, HIDDeviceHandle handle, u8 descriptorType, u8 descriptorIndex, u16 languageId, u8* buffer, u32 bufferLength, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_H(HIDError, HIDSetDescriptor, HIDDeviceHandle handle, u8 descriptorType, u8 descriptorIndex, u16 languageId, u8* buffer, u32 bufferLength, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_H(HIDError, HIDGetReport, HIDDeviceHandle handle, u8 reportType, u8 reportId, u8* buffer, u32 bufferLength, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_H(HIDError, HIDSetReport, HIDDeviceHandle handle, u8 reportType, u8 reportId, u8* buffer, u32 bufferLength, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_H(HIDError, HIDGetProtocol, HIDDeviceHandle handle, u8 interfaceIndex, u8* protocol, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_H(HIDError, HIDSetProtocol, HIDDeviceHandle handle, u8 interfaceIndex, u8 protocol, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_H(HIDError, HIDGetIdle, HIDDeviceHandle handle, u8 interfaceIndex, u8 reportId, u8* idle, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_H(HIDError, HIDSetIdle, HIDDeviceHandle handle, u8 interfaceIndex, u8 reportId, u8 duration, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_H(HIDError, HIDRead, HIDDeviceHandle handle, u8* buffer, u32 bufferLength, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_H(HIDError, HIDWrite, HIDDeviceHandle handle, u8* buffer, u32 bufferLength, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_H(HIDError, HIDResetDevice, HIDDeviceHandle handle, HIDCallback asyncCallback, void* userData);
EXPORT_FUNC_H(void, HIDDecodeError, HIDError error, HIDErrorCategory* category, HIDErrorCode* code);

#ifdef __cplusplus
}
#endif