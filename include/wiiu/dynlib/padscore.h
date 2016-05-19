#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#include <wiiu/dynlib/coreinit/os.h>

#define KPAD_MAX_READ_BUFS 16

typedef struct DPDObject DPDObject;
typedef struct DPDObjEx DPDObjEx;
typedef struct WPADStatus WPADStatus;
typedef struct WPADFSStatus WPADFSStatus;
typedef struct WPADCLStatus WPADCLStatus;
typedef struct WPADUCStatus WPADUCStatus;
typedef struct WPADCMStatus WPADCMStatus;
typedef struct WPADStatusEx WPADStatusEx;
typedef struct WPADMpls WPADMpls;
typedef struct WPADMPStatus WPADMPStatus;
typedef struct WPADInfo WPADInfo;
typedef struct WPADAcc WPADAcc;
typedef struct WPADBLStatus WPADBLStatus;
typedef struct WPADBKStatus WPADBKStatus;
typedef struct WPADTRStatus WPADTRStatus;
typedef struct WENCInfo WENCInfo;
typedef struct KPADVec2 KPADVec2;
typedef struct KPADVec3 KPADVec3;
typedef struct KPADRect KPADRect;
typedef union KPADEXStatus KPADEXStatus;
typedef struct KPADMPDir KPADMPDir;
typedef struct KPADMPStatus KPADMPStatus;
typedef struct KPADStatus KPADStatus;
typedef struct KPADUnifiedWpadStatus KPADUnifiedWpadStatus;

TYPED_ENUM(s32, WBCError) {
    WBC_ERR_NONE          = 0,
    WBC_ERR_NO_CONTROLLER = -1,
    WBC_ERR_BUSY          = -2,
    WBC_ERR_WRONG_TEMP    = -3,
    WBC_ERR_WRONG_PARAM   = -4
};

TYPED_ENUM(s32, WPADChannel) {
    WPAD_CHAN0 = 0,
    WPAD_CHAN1 = 1,
    WPAD_CHAN2 = 2,
    WPAD_CHAN3 = 3
};

TYPED_ENUM(u32, WPADMotorCommand) {
    WPAD_MOTOR_STOP   = 0,
    WPAD_MOTOR_RUMBLE = 1
};

TYPED_ENUM(u16, WPADButton) {
    WPAD_BUTTON_LEFT  = 1 << 0,
    WPAD_BUTTON_RIGHT = 1 << 1,
    WPAD_BUTTON_DOWN  = 1 << 2,
    WPAD_BUTTON_UP    = 1 << 3,
    WPAD_BUTTON_PLUS  = 1 << 4,
    WPAD_BUTTON_2     = 1 << 8,
    WPAD_BUTTON_1     = 1 << 9,
    WPAD_BUTTON_B     = 1 << 10,
    WPAD_BUTTON_A     = 1 << 11,
    WPAD_BUTTON_MINUS = 1 << 12,
    WPAD_BUTTON_Z     = 1 << 13,
    WPAD_BUTTON_C     = 1 << 14,
    WPAD_BUTTON_HOME  = 1 << 15
};

TYPED_ENUM(u16, WPADCLButton) {
    WPAD_CL_BUTTON_UP    = 1 << 0,
    WPAD_CL_BUTTON_LEFT  = 1 << 1,
    WPAD_CL_BUTTON_ZR    = 1 << 2,
    WPAD_CL_BUTTON_X     = 1 << 3,
    WPAD_CL_BUTTON_A     = 1 << 4,
    WPAD_CL_BUTTON_Y     = 1 << 5,
    WPAD_CL_BUTTON_B     = 1 << 6,
    WPAD_CL_BUTTON_ZL    = 1 << 7,
    WPAD_CL_BUTTON_R     = 1 << 9,
    WPAD_CL_BUTTON_PLUS  = 1 << 10,
    WPAD_CL_BUTTON_HOME  = 1 << 11,
    WPAD_CL_BUTTON_MINUS = 1 << 12,
    WPAD_CL_BUTTON_L     = 1 << 13,
    WPAD_CL_BUTTON_DOWN  = 1 << 14,
    WPAD_CL_BUTTON_RIGHT = 1 << 15
};

TYPED_ENUM(u32, WPADUCButton) {
    WPAD_UC_BUTTON_UP      = 1 << 0,
    WPAD_UC_BUTTON_LEFT    = 1 << 1,
    WPAD_UC_BUTTON_ZR      = 1 << 2,
    WPAD_UC_BUTTON_X       = 1 << 3,
    WPAD_UC_BUTTON_A       = 1 << 4,
    WPAD_UC_BUTTON_Y       = 1 << 5,
    WPAD_UC_BUTTON_B       = 1 << 6,
    WPAD_UC_BUTTON_ZL      = 1 << 7,
    WPAD_UC_RESERVED       = 1 << 8,
    WPAD_UC_BUTTON_R       = 1 << 9,
    WPAD_UC_BUTTON_PLUS    = 1 << 10,
    WPAD_UC_BUTTON_HOME    = 1 << 11,
    WPAD_UC_BUTTON_MINUS   = 1 << 12,
    WPAD_UC_BUTTON_L       = 1 << 13,
    WPAD_UC_BUTTON_DOWN    = 1 << 14,
    WPAD_UC_BUTTON_RIGHT   = 1 << 15,
    WPAD_UC_BUTTON_STICK_R = 1 << 16,
    WPAD_UC_BUTTON_STICK_L = 1 << 17,
};

TYPED_ENUM(u32, WPADDpdCommand) {
    WPAD_DPD_OFF  = 0,
    WPAD_DPD_STD  = 1,
    WPAD_DPD_EXP  = 2,
    WPAD_DPD_FULL = 5
};

TYPED_ENUM(u32, WPADSpeakerCommand) {
    WPAD_SPEAKER_OFF      = 0,
    WPAD_SPEAKER_ON       = 1,
    WPAD_SPEAKER_MUTE     = 2,
    WPAD_SPEAKER_MUTE_OFF = 3,
    WPAD_SPEAKER_PLAY     = 4,
    WPAD_SPEAKER_RESET    = 5
};

TYPED_ENUM(u8, WPADMplsCommand) {
    WPAD_MPLS_OFF  = 0,
    WPAD_MPLS_STD  = 4,
    WPAD_MPLS_FS   = 5,
    WPAD_MPLS_CL   = 7,
    WPAD_MPLS_ZRST = 128
};

TYPED_ENUM(u8, WPADMplsStatus) {
    WPAD_MPLS_STATUS_ATTACH = 1 << 0,
    WPAD_MPLS_STATUS_ROLSEL = 1 << 1,
    WPAD_MPLS_STATUS_PITSEL = 1 << 2,
    WPAD_MPLS_STATUS_YAWSEL = 1 << 3,
    WPAD_MPLS_STATUS_EXTVLD = 1 << 6,
    WPAD_MPLS_STATUS_PLSVLD = 1 << 7
};

TYPED_ENUM(u32, WPADExtGimmickCommand) {
    WPAD_EXT_GIMMICK_OFF = 0,
    WPAD_EXT_GIMMICK_ON  = 1
};

TYPED_ENUM(u8, WPADDevice) {
    WPAD_DEV_CORE            = 0,
    WPAD_DEV_FREESTYLE       = 1,
    WPAD_DEV_CLASSIC         = 2,
    WPAD_DEV_BALANCE_CHECKER = 3,
    WPAD_DEV_MPLS            = 5,
    WPAD_DEV_MPLS_FREESTYLE  = 6,
    WPAD_DEV_MPLS_CLASSIC    = 7,
    WPAD_DEV_TRAIN           = 16,
    WPAD_DEV_GUITAR          = 17,
    WPAD_DEV_DRUM            = 18,
    WPAD_DEV_TAIKO           = 19,
    WPAD_DEV_BULK_01         = 21,
    WPAD_DEV_BULK_02         = 22,
    WPAD_DEV_BULK_03         = 23,
    WPAD_DEV_BULK_04         = 24,
    WPAD_DEV_BULK_05         = 25,
    WPAD_DEV_BULK_06         = 26,
    WPAD_DEV_BULK_07         = 27,
    WPAD_DEV_BULK_08         = 28,
    WPAD_DEV_URCC            = 31,
    WPAD_DEV_MPLS_FUTURE     = 250,
    WPAD_DEV_FUTURE          = 251,
    WPAD_DEV_NOT_SUPPORTED   = 252,
    WPAD_DEV_NOT_FOUND       = 253,
    WPAD_DEV_UNKNOWN         = 255
};

TYPED_ENUM(u8, WPADFormat) {
    WPAD_FORMAT_CORE              = 0,
    WPAD_FORMAT_CORE_ACC          = 1,
    WPAD_FORMAT_CORE_ACC_DPD      = 2,
    WPAD_FORMAT_FREESTYLE         = 3,
    WPAD_FORMAT_FREESTYLE_ACC     = 4,
    WPAD_FORMAT_FREESTYLE_ACC_DPD = 5,
    WPAD_FORMAT_CLASSIC           = 6,
    WPAD_FORMAT_CLASSIC_ACC       = 7,
    WPAD_FORMAT_CLASSIC_ACC_DPD   = 8,
    WPAD_FORMAT_CORE_ACC_DPD_FULL = 9,
    WPAD_FORMAT_TRAIN             = 10,
    WPAD_FORMAT_GUITAR            = 11,
    WPAD_FORMAT_BALANCE_CHECKER   = 12,
    WPAD_FORMAT_DRUM              = 15,
    WPAD_FORMAT_MPLS              = 16,
    WPAD_FORMAT_TAIKO             = 17,
    WPAD_FORMAT_BULK              = 19,
    WPAD_FORMAT_URCC              = 22
};

TYPED_ENUM(s32, WPADState) {
    WPAD_STATE_DISABLED = 0,
    WPAD_STATE_ENABLED  = 1
};

TYPED_ENUM(u8, WPADBatteryLevel) {
    WPAD_BATTERY_LEVEL_CRITICAL = 0,
    WPAD_BATTERY_LEVEL_LOW      = 1,
    WPAD_BATTERY_LEVEL_MEDIUM   = 2,
    WPAD_BATTERY_LEVEL_HIGH     = 3,
    WPAD_BATTERY_LEVEL_MAX      = 4
};

TYPED_ENUM(u8, WPADLedChannel) {
    WPAD_LED_CHAN1 = 1 << 0,
    WPAD_LED_CHAN2 = 1 << 1,
    WPAD_LED_CHAN3 = 1 << 2,
    WPAD_LED_CHAN4 = 1 << 3
};

TYPED_ENUM(u32, WPADStickClamp) {
    WPAD_STICK_CLAMP_OCTA_WITH_PLAY      = 0,
    WPAD_STICK_CLAMP_OCTA_WITHOUT_PLAY   = 1,
    WPAD_STICK_CLAMP_CIRCLE_WITH_PLAY    = 2,
    WPAD_STICK_CLAMP_CIRCLE_WITHOUT_PLAY = 3
};

TYPED_ENUM(u32, WPADTriggerClamp) {
    WPAD_TRIGGER_CLAMP_FIXED_BASE      = 0,
    WPAD_TRIGGER_CLAMP_INDIVIDUAL_BASE = 1
};

TYPED_ENUM(u32, WPADAccClamp) {
    WPAD_ACC_CLAMP_CUBE   = 0,
    WPAD_ACC_CLAMP_SPHERE = 1
};

TYPED_ENUM(u32, WPADSensorBarPosition) {
    WPAD_SENSOR_BAR_POS_BOTTOM = 0,
    WPAD_SENSOR_BAR_POS_TOP    = 1
};

TYPED_ENUM(u8, WPADSyncType) {
    WPAD_SYNC_TYPE_STD = 0,
    WPAD_SYNC_TYPE_SMP = 1
};

TYPED_ENUM(s8, WPADError) {
    WPAD_ERROR_NONE          = 0,
    WPAD_ERROR_NO_CONTROLLER = -1,
    WPAD_ERROR_BUSY          = -2,
    WPAD_ERROR_TRANSFER      = -3,
    WPAD_ERROR_INVALID       = -4,
    WPAD_ERROR_NOPERM        = -5,
    WPAD_ERROR_BROKEN        = -6,
    WPAD_ERROR_CORRUPTED     = -7
};

TYPED_ENUM(u8, WPADBLCommand) {
    WPAD_BL_COMMAND_UPDATE_TEMPERATURE = 0,
    WPAD_BL_COMMAND_OFF                = 0x55,
    WPAD_BL_COMMAND_ON                 = 0xAA
};

TYPED_ENUM(u32, WENCFlag) {
    WENC_FLAG_FIRST = 0,
    WENC_FLAG_CONT  = 1,
    WENC_FLAG_LAST  = 2
};

TYPED_ENUM(u32, KPADButton) {
    KPAD_BUTTON_LEFT  = 1 << 0,
    KPAD_BUTTON_RIGHT = 1 << 1,
    KPAD_BUTTON_DOWN  = 1 << 2,
    KPAD_BUTTON_UP    = 1 << 3,
    KPAD_BUTTON_PLUS  = 1 << 4,
    KPAD_BUTTON_2     = 1 << 8,
    KPAD_BUTTON_1     = 1 << 9,
    KPAD_BUTTON_B     = 1 << 10,
    KPAD_BUTTON_A     = 1 << 11,
    KPAD_BUTTON_MINUS = 1 << 12,
    KPAD_BUTTON_Z     = 1 << 13,
    KPAD_BUTTON_C     = 1 << 14,
    KPAD_BUTTON_HOME  = 1 << 15,
    KPAD_BUTTON_RPT   = 1 << 31
};

TYPED_ENUM(u32, KPADCLButton) {
    KPAD_CL_BUTTON_UP                      = 1 << 0,
    KPAD_CL_BUTTON_LEFT                    = 1 << 1,
    KPAD_CL_BUTTON_ZR                      = 1 << 2,
    KPAD_CL_BUTTON_X                       = 1 << 3,
    KPAD_CL_BUTTON_A                       = 1 << 4,
    KPAD_CL_BUTTON_Y                       = 1 << 5,
    KPAD_CL_BUTTON_B                       = 1 << 6,
    KPAD_CL_BUTTON_ZL                      = 1 << 7,
    KPAD_CL_BUTTON_R                       = 1 << 9,
    KPAD_CL_BUTTON_PLUS                    = 1 << 10,
    KPAD_CL_BUTTON_HOME                    = 1 << 11,
    KPAD_CL_BUTTON_MINUS                   = 1 << 12,
    KPAD_CL_BUTTON_L                       = 1 << 13,
    KPAD_CL_BUTTON_DOWN                    = 1 << 14,
    KPAD_CL_BUTTON_RIGHT                   = 1 << 15,
    KPAD_CL_BUTTON_STICK_L_EMULATION_LEFT  = 1 << 16,
    KPAD_CL_BUTTON_STICK_L_EMULATION_RIGHT = 1 << 17,
    KPAD_CL_BUTTON_STICK_L_EMULATION_DOWN  = 1 << 18,
    KPAD_CL_BUTTON_STICK_L_EMULATION_UP    = 1 << 19,
    KPAD_CL_BUTTON_STICK_R_EMULATION_LEFT  = 1 << 20,
    KPAD_CL_BUTTON_STICK_R_EMULATION_RIGHT = 1 << 21,
    KPAD_CL_BUTTON_STICK_R_EMULATION_DOWN  = 1 << 22,
    KPAD_CL_BUTTON_STICK_R_EMULATION_UP    = 1 << 23
};

TYPED_ENUM(u32, KPADUCButton) {
    KPAD_UC_BUTTON_UP                      = 1 << 0,
    KPAD_UC_BUTTON_LEFT                    = 1 << 1,
    KPAD_UC_BUTTON_ZR                      = 1 << 2,
    KPAD_UC_BUTTON_X                       = 1 << 3,
    KPAD_UC_BUTTON_A                       = 1 << 4,
    KPAD_UC_BUTTON_Y                       = 1 << 5,
    KPAD_UC_BUTTON_B                       = 1 << 6,
    KPAD_UC_BUTTON_ZL                      = 1 << 7,
    KPAD_UC_RESERVED                       = 1 << 8,
    KPAD_UC_BUTTON_R                       = 1 << 9,
    KPAD_UC_BUTTON_PLUS                    = 1 << 10,
    KPAD_UC_BUTTON_HOME                    = 1 << 11,
    KPAD_UC_BUTTON_MINUS                   = 1 << 12,
    KPAD_UC_BUTTON_L                       = 1 << 13,
    KPAD_UC_BUTTON_DOWN                    = 1 << 14,
    KPAD_UC_BUTTON_RIGHT                   = 1 << 15,
    KPAD_UC_BUTTON_STICK_R                 = 1 << 16,
    KPAD_UC_BUTTON_STICK_L                 = 1 << 17,
    KPAD_UC_BUTTON_STICK_L_EMULATION_LEFT  = 1 << 18,
    KPAD_UC_BUTTON_STICK_L_EMULATION_RIGHT = 1 << 19,
    KPAD_UC_BUTTON_STICK_L_EMULATION_DOWN  = 1 << 20,
    KPAD_UC_BUTTON_STICK_L_EMULATION_UP    = 1 << 21,
    KPAD_UC_BUTTON_STICK_R_EMULATION_LEFT  = 1 << 22,
    KPAD_UC_BUTTON_STICK_R_EMULATION_RIGHT = 1 << 23,
    KPAD_UC_BUTTON_STICK_R_EMULATION_DOWN  = 1 << 24,
    KPAD_UC_BUTTON_STICK_R_EMULATION_UP    = 1 << 25
};

TYPED_ENUM(u32, KPADFSButton) {
    KPAD_FS_BUTTON_STICK_EMULATION_LEFT  = 1 << 0,
    KPAD_FS_BUTTON_STICK_EMULATION_RIGHT = 1 << 1,
    KPAD_FS_BUTTON_STICK_EMULATION_DOWN  = 1 << 2,
    KPAD_FS_BUTTON_STICK_EMULATION_UP    = 1 << 3
};

TYPED_ENUM(s32, KPADReadError) {
    KPAD_READ_ERROR_NONE          = 0,
    KPAD_READ_ERROR_NO_DATA       = -1,
    KPAD_READ_ERROR_NO_CONTROLLER = -2,
    KPAD_READ_ERROR_SETUP         = -3,
    KPAD_READ_ERROR_LOCKED        = -4,
    KPAD_READ_ERROR_INIT          = -5
};

TYPED_ENUM(s32, KPADWBCError) {
    KPAD_WBC_ERROR_EXIST        = 1,
    KPAD_WBC_ERROR_NONE         = 0,
    KPAD_WBC_ERROR_NO_BATTERY   = -1,
    KPAD_WBC_ERROR_SETUP        = -2,
    KPAD_WBC_ERROR_WRONG_TEMP   = -3,
    KPAD_WBC_ERROR_WRONG_ZERO   = -4,
    KPAD_WBC_ERROR_WEIGHT_OVER  = -5,
    KPAD_WBC_ERROR_CALIBRATION  = -6,
    KPAD_WBC_ERROR_NO_ZEROPOINT = -7,
    KPAD_WBC_ERROR_ZEROPOINT    = -8
};

TYPED_ENUM(s32, KPADWBCTGCError) {
    KPAD_WBC_TGC_ERROR_READY    = 1,
    KPAD_WBC_TGC_ERROR_NONE     = 0,
    KPAD_WBC_TGC_ERROR_UNSTABLE = -1,
    KPAD_WBC_TGC_ERROR_UNKNOWN  = -2,
    KPAD_WBC_TGC_ERROR_TIMEOUT  = -3,
    KPAD_WBC_TGC_ERROR_BUSY     = -4
};

TYPED_ENUM(s32, KPADControlDpdState) {
    KPAD_CONTROL_DPD_STATE_START    = 0,
    KPAD_CONTROL_DPD_STATE_FINISHED = 1
};

TYPED_ENUM(u8, KPADButtonProcMode) {
    KPAD_BUTTON_PROC_MODE_LOOSE = 0,
    KPAD_BUTTON_PROC_MODE_TIGHT = 1
};

TYPED_ENUM(s32, KPADControlMplsState) {
    KPAD_CONTROL_MPLS_STATE_FAILED_CL  = -3,
    KPAD_CONTROL_MPLS_STATE_FAILED_FS  = -2,
    KPAD_CONTROL_MPLS_STATE_FAILED_STD = -1,
    KPAD_CONTROL_MPLS_STATE_START      = 0,
    KPAD_CONTROL_MPLS_STATE_FINISHED   = 1,
};

TYPED_ENUM(u8, KPADDPDDetectionMode) {
    KPAD_DPD_DEFAULT  = 0,
    KPAD_DPD_DOWNWARD = 1
};

TYPED_ENUM(u32, KPADPlayMode) {
    KPAD_PLAY_MODE_LOOSE = 0,
    KPAD_PLAY_MODE_TIGHT = 1
};

TYPED_ENUM(u32, KPADMplsZeroDriftMode) {
    KPAD_MPLS_ZERODRIFT_LOOSE    = 0,
    KPAD_MPLS_ZERODRIFT_STANDARD = 1,
    KPAD_MPLS_ZERODRIFT_TIGHT    = 2
};

typedef void  (*WPADExtensionCallback)  (WPADChannel chan, WPADError result);
typedef void  (*WPADSamplingCallback)   (WPADChannel chan);
typedef void  (*WPADConnectCallback)    (WPADChannel chan, WPADError reason);
typedef void  (*WPADCallback)           (WPADChannel chan, WPADError result);
typedef void* (*WPADAlloc)              (u32 size);
typedef u8    (*WPADFree)               (void* ptr);
typedef void  (*WPADSyncDeviceCallback) (WPADError result, s32 num);
typedef void  (*WPADClearDeviceCallback)(WPADError result);
typedef void  (*KPADControlDpdCallback) (WPADChannel chan, KPADControlDpdState reason);
typedef void  (*KPADControlMplsCallback)(WPADChannel chan, KPADControlMplsState reason);

struct DPDObject {
    s16 x;
    s16 y;
    u16 size;
    u8  traceId;
};

struct DPDObjEx {
    s16 rangeX1;
    s16 rangeY1;
    s16 rangeX2;
    s16 rangeY2;
    u16 pixel;
    s8  radius;
};

struct WPADStatus {
    WPADButton button;
    s16        accX;
    s16        accY;
    s16        accZ;
    DPDObject  obj[4];
    WPADDevice dev;
    WPADError  err;
};

struct WPADFSStatus {
    WPADButton button;
    s16        accX;
    s16        accY;
    s16        accZ;
    DPDObject  obj[4];
    WPADDevice dev;
    WPADError  err;
    s16        fsAccX;
    s16        fsAccY;
    s16        fsAccZ;
    s8         fsStickX;
    s8         fsStickY;
};

struct WPADCLStatus {
    WPADButton   button;
    s16          accX;
    s16          accY;
    s16          accZ;
    DPDObject    obj[4];
    WPADDevice   dev;
    WPADError    err;
    WPADCLButton clButton;
    s16          clLStickX;
    s16          clLStickY;
    s16          clRStickX;
    s16          clRStickY;
    u8           clTriggerL;
    u8           clTriggerR;
};

struct WPADUCStatus {
    WPADButton   button;
    s16          accX;
    s16          accY;
    s16          accZ;
    DPDObject    obj[4];
    WPADDevice   dev;
    WPADError    err;
    WPADUCButton ucButton;
    s16          ucLStickX;
    s16          ucLStickY;
    s16          ucRStickX;
    s16          ucRStickY;
    bool         charge;
    bool         cable;
};

struct WPADCMStatus {
    WPADButton button;
    s16        accX;
    s16        accY;
    s16        accZ;
    DPDObject  obj[4];
    WPADDevice dev;
    WPADError  err;
    u16        cmButton;
    u8         custom[20];
};

struct WPADStatusEx {
    WPADButton button;
    s16        accX;
    s16        accY;
    s16        accZ;
    DPDObject  obj[4];
    WPADDevice dev;
    WPADError  err;
    DPDObjEx   exp[4];
};

struct WPADMpls {
    f32 pitchZero;
    f32 pitchScale;
    f32 yawZero;
    f32 yawScale;
    f32 rollZero;
    f32 rollScale;
    s32 degrees;
};

struct WPADMPStatus {
    WPADButton     button;
    s16            accX;
    s16            accY;
    s16            accZ;
    DPDObject      obj[4];
    WPADDevice     dev;
    WPADError      err;
    union {
        struct {
            s16 fsAccX;
            s16 fsAccY;
            s16 fsAccZ;
            s8  fsStickX;
            s8  fsStickY;
        } fs;

        struct {
            u16 clButton;
            s16 clLStickX;
            s16 clLStickY;
            s16 clRStickX;
            s16 clRStickY;
            u8  clTriggerL;
            u8  clTriggerR;
        } cl;
    }              ext;
    WPADMplsStatus stat;
    u8             reserved;
    s16            pitch;
    s16            yaw;
    s16            roll;
};

struct WPADInfo {
    bool             dpd;
    bool             speaker;
    bool             attach;
    bool             lowBat;
    bool             nearEmpty;
    WPADBatteryLevel battery;
    WPADLedChannel   led;
    u8               protocol;
    u8               firmware;
};

struct WPADAcc {
    s16 x;
    s16 y;
    s16 z;
};

struct WPADBLStatus {
    WPADButton       button;
    s16              accX;
    s16              accY;
    s16              accZ;
    DPDObject        obj[4];
    WPADDevice       dev;
    WPADError        err;
    u16              press[4];
    s8               temperature;
    WPADBatteryLevel battery;
};

struct WPADBKStatus {
    WPADButton button;
    s16        accX;
    s16        accY;
    s16        accZ;
    DPDObject  obj[4];
    WPADDevice dev;
    WPADError  err;
    u8         bulk[21];
    u8         padding;
};

struct WPADTRStatus {
    WPADButton   button;
    s16          accX;
    s16          accY;
    s16          accZ;
    DPDObject    obj[4];
    WPADDevice   dev;
    WPADError    err;
    WPADCLButton trButton;
    u8           brake;
    u8           mascon;
};

struct WENCInfo {
    u8 data[32];
};

struct KPADVec2 {
    f32 x;
    f32 y;
};

struct KPADVec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct KPADRect {
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
};

union KPADEXStatus {
    struct {
        KPADVec2     stick;
        KPADVec3     acc;
        f32          accValue;
        f32          accSpeed;
        KPADFSButton hold;
        KPADFSButton trig;
        KPADFSButton release;
    } fs;

    struct {
        KPADCLButton hold;
        KPADCLButton trig;
        KPADCLButton release;
        KPADVec2     lStick;
        KPADVec2     rStick;
        f32          lTrigger;
        f32          rTrigger;
    } cl;

    struct {
        KPADUCButton hold;
        KPADUCButton trig;
        KPADUCButton release;
        KPADVec2     lStick;
        KPADVec2     rStick;
        bool         charge;
        bool         cable;
    } uc;

    struct {
        double          tgcWeight;
        double          weight[4];
        double          weightAve[4];
        KPADWBCError    weightErr;
        KPADWBCTGCError tgcWeightErr;
    } bl;

    struct {
        u32 hold;
        u32 trig;
        u32 release;
    } cm;
};

struct KPADMPDir {
    KPADVec3 x;
    KPADVec3 y;
    KPADVec3 z;
};

struct KPADMPStatus {
    KPADVec3  mpls;
    KPADVec3  angle;
    KPADMPDir dir;
};

struct KPADStatus {
    KPADButton   hold;
    KPADButton   trig;
    KPADButton   release;
    KPADVec3     acc;
    f32          accValue;
    f32          accSpeed;
    KPADVec2     pos;
    KPADVec2     vec;
    f32          speed;
    KPADVec2     horizon;
    KPADVec2     horiVec;
    f32          horiSpeed;
    f32          dist;
    f32          distVec;
    f32          distSpeed;
    KPADVec2     accVertical;
    WPADDevice   devType;
    WPADError    wpadErr;
    s8           dpdValidFg;
    WPADFormat   dataFormat;
    KPADEXStatus exStatus;
    KPADMPStatus mpls;
    u8           padding[4];
};

struct KPADUnifiedWpadStatus {
    union {
        WPADStatus   core;
        WPADFSStatus fs;
        WPADCLStatus cl;
        WPADTRStatus tr;
        WPADBLStatus bl;
        WPADMPStatus mp;
        WPADBKStatus bk;
        WPADUCStatus uc;
        WPADCMStatus cm;
    }          status;
    WPADFormat fmt;
    u8         padding;
};

EXPORT_FUNC_H(bool, WBCSetupCalibration, void);
EXPORT_FUNC_H(bool, WBCGetCalibrationStatus, void);
EXPORT_FUNC_H(s32, WBCRead, WPADBLStatus* status, double* weight, u32 size);
EXPORT_FUNC_H(s32, WBCGetBatteryLevel, u8 battery);
EXPORT_FUNC_H(s32, WBCSetZEROPoint, double* pressAvg, u32 size);
EXPORT_FUNC_H(s32, WBCGetTGCWeight, double totalWeightAvg, double *tgcWeight, WPADBLStatus* status);

EXPORT_FUNC_H(void, WPADInit, void);
EXPORT_FUNC_H(void, WPADShutdown, void);
EXPORT_FUNC_H(void, WPADRegisterAllocator, WPADAlloc alloc, WPADFree free);
EXPORT_FUNC_H(u32, WPADGetWorkMemorySize, void);

EXPORT_FUNC_H(WPADError, WPADProbe, WPADChannel chan, WPADDevice* type);
EXPORT_FUNC_H(WPADState, WPADGetStatus, void);
EXPORT_FUNC_H(WPADFormat, WPADGetDataFormat, WPADChannel chan);
EXPORT_FUNC_H(WPADError, WPADSetDataFormat, WPADChannel chan, WPADFormat fmt);
EXPORT_FUNC_H(void, WPADRead, WPADChannel chan, void* status);

EXPORT_FUNC_H(void, WPADSetAutoSamplingBuf, WPADChannel chan, void* buf, u32 length);
EXPORT_FUNC_H(u32, WPADGetLatestIndexInBuf, WPADChannel chan);

EXPORT_FUNC_H(void, WPADGetAccGravityUnit, WPADChannel chan, u32 type, WPADAcc* acc);
EXPORT_FUNC_H(void, WPADGetCLTriggerThreshold, WPADChannel chan, u8* left, u8* right);
EXPORT_FUNC_H(void, WPADClampStick, WPADChannel chan, void* status, WPADStickClamp type);
EXPORT_FUNC_H(void, WPADClampTrigger, WPADChannel chan, void* status, WPADTriggerClamp type);
EXPORT_FUNC_H(void, WPADClampAcc, WPADChannel chan, void* status, WPADAccClamp type);

EXPORT_FUNC_H(bool, WPADIsDpdEnabled, WPADChannel chan);
EXPORT_FUNC_H(WPADDpdCommand, WPADGetDpdFormat, WPADChannel chan);
EXPORT_FUNC_H(WPADError, WPADControlDpd, WPADChannel chan, WPADDpdCommand command, WPADCallback callback);
EXPORT_FUNC_H(u8, WPADGetDpdSensitivity, void);
EXPORT_FUNC_H(WPADError, WPADControlExtGimmick, WPADChannel chan, WPADExtGimmickCommand command, WPADCallback callback);

EXPORT_FUNC_H(void, WPADDisconnect, WPADChannel chan);
EXPORT_FUNC_H(WPADError, WPADGetInfo, WPADChannel chan, WPADInfo* info);
EXPORT_FUNC_H(WPADError, WPADGetInfoAsync, WPADChannel chan, WPADInfo* info, WPADCallback callback);
EXPORT_FUNC_H(void, WPADGetAddress, WPADChannel chan, u8* addr);
EXPORT_FUNC_H(u8, WPADGetRegisteredDevNum, void);
EXPORT_FUNC_H(u8, WPADGetRadioSensitivity, WPADChannel chan);
EXPORT_FUNC_H(WPADBatteryLevel, WPADGetBatteryLevel, WPADChannel chan);

EXPORT_FUNC_H(bool, WPADIsSpeakerEnabled, WPADChannel chan);
EXPORT_FUNC_H(WPADError, WPADControlSpeaker, WPADChannel chan, WPADSpeakerCommand command, WPADCallback callback);
EXPORT_FUNC_H(u8, WPADGetSpeakerVolume, void);

EXPORT_FUNC_H(WPADError, WPADSendStreamData, WPADChannel chan, void* buf, u16 len);
EXPORT_FUNC_H(bool, WPADCanSendStreamData, WPADChannel chan);

EXPORT_FUNC_H(void, WPADControlMotor, WPADChannel chan, WPADMotorCommand command);
EXPORT_FUNC_H(bool, WPADIsMotorEnabled, void);

EXPORT_FUNC_H(void, WPADSetAutoSleepTime, u8 minutes);
EXPORT_FUNC_H(u32, WPADGetAutoSleepTimeCount, WPADChannel chan);
EXPORT_FUNC_H(void, WPADResetAutoSleepTimeCount, WPADChannel chan);

EXPORT_FUNC_H(WPADSensorBarPosition, WPADGetSensorBarPosition, void);
EXPORT_FUNC_H(void, WPADEnableSensorBar, WPADSensorBarPosition sensorBar);
EXPORT_FUNC_H(void, WPADSetSensorBar, bool on);

EXPORT_FUNC_H(void, WPADSetGameTitleUtf16, const u16* title);
EXPORT_FUNC_H(WPADError, WPADGetGameTitleUtf16, WPADChannel chan, const u16** title);
EXPORT_FUNC_H(WPADError, WPADGetGameDataTimeStamp, WPADChannel chan, OSTime* time);

EXPORT_FUNC_H(bool, WPADSetAcceptConnection, bool accept);
EXPORT_FUNC_H(bool, WPADGetAcceptConnection, void);

EXPORT_FUNC_H(bool, WPADStartSyncDevice, void);
EXPORT_FUNC_H(bool, WPADPurgeBtDb, void);
EXPORT_FUNC_H(bool, WPADCancelSyncDevice, void);
EXPORT_FUNC_H(bool, WPADIsBusyForSync, void);
EXPORT_FUNC_H(WPADError, WPADGetSyncType, WPADChannel chan, WPADSyncType* type);

EXPORT_FUNC_H(WPADSamplingCallback, WPADSetSamplingCallback, WPADChannel chan, WPADSamplingCallback callback);
EXPORT_FUNC_H(WPADExtensionCallback, WPADSetExtensionCallback, WPADChannel chan, WPADExtensionCallback callback);
EXPORT_FUNC_H(WPADConnectCallback, WPADSetConnectCallback, WPADChannel chan, WPADConnectCallback callback);
EXPORT_FUNC_H(WPADSyncDeviceCallback, WPADSetSyncDeviceCallback, WPADSyncDeviceCallback callback);
EXPORT_FUNC_H(WPADClearDeviceCallback, WPADSetClearDeviceCallback, WPADClearDeviceCallback callback);

EXPORT_FUNC_H(bool, WPADAttachDummyExtension, WPADChannel chan, WPADDevice type);
EXPORT_FUNC_H(bool, WPADDetachDummyExtension, WPADChannel chan);

EXPORT_FUNC_H(WPADError, WPADIsMplsAttached, WPADChannel chan, bool* attached, WPADCallback callback);
EXPORT_FUNC_H(WPADError, WPADIsMplsIntegrated, WPADChannel chan);
EXPORT_FUNC_H(bool, WPADGetCalibrationStatus, WPADChannel chan);

EXPORT_FUNC_H(void, WPADEnableURCC, bool enable);
EXPORT_FUNC_H(void, WPADEnableWiiRemote, bool enable);
EXPORT_FUNC_H(void, WPADDisableBluetooth, void);

EXPORT_FUNC_H(s32, WPADControlBLC, WPADChannel chan, WPADBLCommand command, WPADCallback callback);
EXPORT_FUNC_H(s32, WPADGetBLCalibration, WPADChannel chan, u8* data, u16 addr, u16 len, WPADCallback callback);
EXPORT_FUNC_H(bool, WPADIsRegisteredBLC, void);
EXPORT_FUNC_H(void, WPADRegisterBLCWorkarea, void* workArea);
EXPORT_FUNC_H(bool, WPADIsEnabledWBC, void);
EXPORT_FUNC_H(void, WPADEnableWBC, void);

EXPORT_FUNC_H(s32, WENCGetEncodeData, WENCInfo* info, WENCFlag flag, const s16* pcmData, s32 sampleNum, u8* pbyEncData);

EXPORT_FUNC_H(void, KPADInit, void);
EXPORT_FUNC_H(void, KPADInitEx, KPADUnifiedWpadStatus* uniRingBufs, u32 length);
EXPORT_FUNC_H(void, KPADShutdown, void);
EXPORT_FUNC_H(void, KPADReset, void);

EXPORT_FUNC_H(s32, KPADRead, WPADChannel chan, KPADStatus* samplingBufs, u32 count);
EXPORT_FUNC_H(s32, KPADReadEx, WPADChannel chan, KPADStatus* samplingBufs, u32 count, KPADReadError* err);
EXPORT_FUNC_H(void, KPADGetUnifiedWpadStatus, WPADChannel chan, KPADUnifiedWpadStatus* dst, u32 count);
EXPORT_FUNC_H(void, KPADGetProjectionPos, KPADVec2* dst, const KPADVec2* src, const KPADRect* projRect, f32 viRatio);

EXPORT_FUNC_H(void, KPADSetPosParam, WPADChannel chan, f32 playRadius, f32 sensitivity);
EXPORT_FUNC_H(void, KPADSetHoriParam, WPADChannel chan, f32 playRadius, f32 sensitivity);
EXPORT_FUNC_H(void, KPADSetDistParam, WPADChannel chan, f32 playRadius, f32 sensitivity);
EXPORT_FUNC_H(void, KPADSetAccParam, WPADChannel chan, f32 playRadius, f32 sensitivity);
EXPORT_FUNC_H(void, KPADSetCrossStickEmulationParamsL, WPADChannel chan, f32 rotDeg, f32 xyDeg, f32 radius);
EXPORT_FUNC_H(void, KPADSetCrossStickEmulationParamsR, WPADChannel chan, f32 rotDeg, f32 xyDeg, f32 radius);
EXPORT_FUNC_H(void, KPADGetPosParam, WPADChannel chan, f32* playRadius, f32* sensitivity);
EXPORT_FUNC_H(void, KPADGetHoriParam, WPADChannel chan, f32* playRadius, f32* sensitivity);
EXPORT_FUNC_H(void, KPADGetDistParam, WPADChannel chan, f32* playRadius, f32* sensitivity);
EXPORT_FUNC_H(void, KPADGetAccParam, WPADChannel chan, f32* playRadius, f32* sensitivity);
EXPORT_FUNC_H(void, KPADGetCrossStickEmulationParamsL, WPADChannel chan, f32* rotDeg, f32* xyDeg, f32* radius);
EXPORT_FUNC_H(void, KPADGetCrossStickEmulationParamsR, WPADChannel chan, f32* rotDeg, f32* xyDeg, f32* radius);

EXPORT_FUNC_H(void, KPADSetBtnRepeat, WPADChannel chan, f32 delaySec, f32 pulseSec);
EXPORT_FUNC_H(void, KPADSetObjInterval, f32 interval);

EXPORT_FUNC_H(void, KPADDisableDPD, WPADChannel chan);
EXPORT_FUNC_H(void, KPADEnableDPD, WPADChannel chan);
EXPORT_FUNC_H(s32, KPADCalibrateDPD, WPADChannel chan);

EXPORT_FUNC_H(void, KPADSetSensorHeight, WPADChannel chan, f32 level);
EXPORT_FUNC_H(f32, KPADGetSensorHeight, WPADChannel chan);

EXPORT_FUNC_H(void, KPADEnableStickCrossClamp, void);
EXPORT_FUNC_H(void, KPADDisableStickCrossClamp, void);
EXPORT_FUNC_H(void, KPADSetFSStickClamp, s8 min, s8 max);

EXPORT_FUNC_H(void, KPADEnableAimingMode, WPADChannel chan);
EXPORT_FUNC_H(void, KPADDisableAimingMode, WPADChannel chan);
EXPORT_FUNC_H(u8, KPADIsEnableAimingMode, WPADChannel chan);

EXPORT_FUNC_H(void, KPADSetControlDpdCallback, WPADChannel chan, KPADControlDpdCallback callback);
EXPORT_FUNC_H(WPADSamplingCallback, KPADSetSamplingCallback, WPADChannel chan, WPADSamplingCallback callback);
EXPORT_FUNC_H(WPADConnectCallback, KPADSetConnectCallback, WPADChannel chan, WPADConnectCallback callback);

EXPORT_FUNC_H(void, KPADSetReviseMode, WPADChannel chan, bool sw);
EXPORT_FUNC_H(f32, KPADReviseAcc, KPADVec3* acc);
EXPORT_FUNC_H(f32, KPADGetReviseAngle, void);
EXPORT_FUNC_H(void, KPADSetPosPlayMode, WPADChannel chan, KPADPlayMode mode);
EXPORT_FUNC_H(void, KPADSetHoriPlayMode, WPADChannel chan, KPADPlayMode mode);
EXPORT_FUNC_H(void, KPADSetDistPlayMode, WPADChannel chan, KPADPlayMode mode);
EXPORT_FUNC_H(void, KPADSetAccPlayMode, WPADChannel chan, KPADPlayMode mode);
EXPORT_FUNC_H(KPADPlayMode, KPADGetPosPlayMode, WPADChannel chan);
EXPORT_FUNC_H(KPADPlayMode, KPADGetHoriPlayMode, WPADChannel chan);
EXPORT_FUNC_H(KPADPlayMode, KPADGetDistPlayMode, WPADChannel chan);
EXPORT_FUNC_H(KPADPlayMode, KPADGetAccPlayMode, WPADChannel chan);
EXPORT_FUNC_H(void, KPADSetButtonProcMode, WPADChannel chan, KPADButtonProcMode mode);
EXPORT_FUNC_H(KPADButtonProcMode, KPADGetButtonProcMode, WPADChannel chan);

EXPORT_FUNC_H(void, KPADResetWbcZeroPoint, void);
EXPORT_FUNC_H(void, KPADResetWbcTgcWeight, void);

EXPORT_FUNC_H(void, KPADDisableMpls, WPADChannel chan);
EXPORT_FUNC_H(void, KPADEnableMpls, WPADChannel chan, WPADMplsCommand mode);
EXPORT_FUNC_H(u8, KPADGetMplsStatus, WPADChannel chan);
EXPORT_FUNC_H(void, KPADSetControlMplsCallback, WPADChannel chan, KPADControlMplsCallback callback);
EXPORT_FUNC_H(u32, KPADGetMplsWorkSize, void);
EXPORT_FUNC_H(void, KPADSetMplsWorkarea, void* ptr);
EXPORT_FUNC_H(void, KPADResetMpls, WPADChannel chan);
EXPORT_FUNC_H(void, KPADSetMplsAngle, WPADChannel chan, f32 ax, f32 ay, f32 az);
EXPORT_FUNC_H(void, KPADSetMplsDirection, WPADChannel chan, KPADMPDir* dir);
EXPORT_FUNC_H(void, KPADStartMplsCalibration, WPADChannel chan);
EXPORT_FUNC_H(f32, KPADWorkMplsCalibration, WPADChannel chan);
EXPORT_FUNC_H(void, KPADStopMplsCalibration, WPADChannel chan);
EXPORT_FUNC_H(void, KPADSetMplsDirectionMag, WPADChannel chan, f32 mag);
EXPORT_FUNC_H(void, KPADEnableMplsZeroPlay, WPADChannel chan);
EXPORT_FUNC_H(void, KPADEnableMplsDirRevise, WPADChannel chan);
EXPORT_FUNC_H(void, KPADEnableMplsAccRevise, WPADChannel chan);
EXPORT_FUNC_H(void, KPADEnableMplsDpdRevise, WPADChannel chan);
EXPORT_FUNC_H(void, KPADDisableMplsZeroPlay, WPADChannel chan);
EXPORT_FUNC_H(void, KPADDisableMplsDirRevise, WPADChannel chan);
EXPORT_FUNC_H(void, KPADDisableMplsAccRevise, WPADChannel chan);
EXPORT_FUNC_H(void, KPADDisableMplsDpdRevise, WPADChannel chan);
EXPORT_FUNC_H(f32, KPADIsEnableMplsZeroPlay, WPADChannel chan);
EXPORT_FUNC_H(f32, KPADIsEnableMplsZeroDrift, WPADChannel chan);
EXPORT_FUNC_H(f32, KPADIsEnableMplsDirRevise, WPADChannel chan);
EXPORT_FUNC_H(f32, KPADIsEnableMplsAccRevise, WPADChannel chan);
EXPORT_FUNC_H(f32, KPADIsEnableMplsDpdRevise, WPADChannel chan);
EXPORT_FUNC_H(void, KPADSetMplsZeroPlayParam, WPADChannel chan, f32 radius);
EXPORT_FUNC_H(void, KPADSetMplsDirReviseParam, WPADChannel chan, f32 revisePw);
EXPORT_FUNC_H(void, KPADSetMplsAccReviseParam, WPADChannel chan, f32 revisePw, f32 reviseRange);
EXPORT_FUNC_H(void, KPADSetMplsDpdReviseParam, WPADChannel chan, f32 revisePw);
EXPORT_FUNC_H(void, KPADSetMplsDirReviseBase, WPADChannel chan, KPADMPDir* base);
EXPORT_FUNC_H(void, KPADGetMplsZeroPlayParam, WPADChannel chan, f32* radius);
EXPORT_FUNC_H(void, KPADGetMplsDirReviseParam, WPADChannel chan, f32* revisePw);
EXPORT_FUNC_H(void, KPADGetMplsAccReviseParam, WPADChannel chan, f32* revisePw, f32* reviseRange);
EXPORT_FUNC_H(void, KPADGetMplsDpdReviseParam, WPADChannel chan, f32* revisePw);
EXPORT_FUNC_H(void, KPADInitMplsZeroPlayParam, WPADChannel chan);
EXPORT_FUNC_H(void, KPADInitMplsDirReviseParam, WPADChannel chan);
EXPORT_FUNC_H(void, KPADInitMplsAccReviseParam, WPADChannel chan);
EXPORT_FUNC_H(void, KPADInitMplsDpdReviseParam, WPADChannel chan);
EXPORT_FUNC_H(void, KPADInitMplsZeroDriftMode, WPADChannel chan);
EXPORT_FUNC_H(void, KPADSetMplsZeroDriftMode, WPADChannel chan, KPADMplsZeroDriftMode mode);
EXPORT_FUNC_H(void, KPADGetMplsZeroDriftMode, WPADChannel chan, KPADMplsZeroDriftMode* mode);
EXPORT_FUNC_H(void, KPADSetMplsMagnification, WPADChannel chan, f32 pitch, f32 yaw, f32 roll);

EXPORT_FUNC_H(void, KPADSetDpdDetection, KPADDPDDetectionMode mode);
EXPORT_FUNC_H(KPADDPDDetectionMode, KPADGetDpdDetection, void);

#ifdef __cplusplus
}
#endif