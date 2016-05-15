#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#include <wiiu/dynlib/coreinit/os.h>

#define VPAD_MAX_READ_BUFS 16

#define VPAD_MOTOR_PATTERN_SIZE_MAX   15
#define VPAD_MOTOR_PATTERN_LENGTH_MAX 120

typedef struct VPADTPData VPADTPData;
typedef struct VPADTPCalibrationParam VPADTPCalibrationParam;
typedef struct VPADVec2 VPADVec2;
typedef struct VPADVec3 VPADVec3;
typedef struct VPADDir VPADDir;
typedef struct VPADStatus VPADStatus;

typedef void (*VPADSamplingCallback)(s32 chan);

TYPED_ENUM(s32, VPADChannel) {
    VPAD_CHANNEL_DRC1 = 0,
    VPAD_CHANNEL_DRC2 = 1
};

TYPED_ENUM(u32, VPADButton) {
    VPAD_BUTTON_HOME                    = 1 << 1,
    VPAD_BUTTON_MINUS                   = 1 << 2,
    VPAD_BUTTON_PLUS                    = 1 << 3,
    VPAD_BUTTON_R                       = 1 << 4,
    VPAD_BUTTON_L                       = 1 << 5,
    VPAD_BUTTON_ZR                      = 1 << 6,
    VPAD_BUTTON_ZL                      = 1 << 7,
    VPAD_BUTTON_DOWN                    = 1 << 8,
    VPAD_BUTTON_UP                      = 1 << 9,
    VPAD_BUTTON_RIGHT                   = 1 << 10,
    VPAD_BUTTON_LEFT                    = 1 << 11,
    VPAD_BUTTON_Y                       = 1 << 12,
    VPAD_BUTTON_X                       = 1 << 13,
    VPAD_BUTTON_B                       = 1 << 14,
    VPAD_BUTTON_A                       = 1 << 15,
    VPAD_BUTTON_STICK_R                 = 1 << 17,
    VPAD_BUTTON_STICK_L                 = 1 << 18,
    VPAD_BUTTON_STICK_R_EMULATION_DOWN  = 1 << 23,
    VPAD_BUTTON_STICK_R_EMULATION_UP    = 1 << 24,
    VPAD_BUTTON_STICK_R_EMULATION_RIGHT = 1 << 25,
    VPAD_BUTTON_STICK_R_EMULATION_LEFT  = 1 << 26,
    VPAD_BUTTON_STICK_L_EMULATION_DOWN  = 1 << 27,
    VPAD_BUTTON_STICK_L_EMULATION_UP    = 1 << 28,
    VPAD_BUTTON_STICK_L_EMULATION_RIGHT = 1 << 29,
    VPAD_BUTTON_STICK_L_EMULATION_LEFT  = 1 << 30,
    VPAD_BUTTON_RPT                     = 1 << 31
};

TYPED_ENUM(s32, VPADReadError) {
    VPAD_READ_ERROR_NONE          = 0,
    VPAD_READ_ERROR_NO_DATA       = -1,
    VPAD_READ_ERROR_NO_CONTROLLER = -2,
    VPAD_READ_ERROR_SETUP         = -3,
    VPAD_READ_ERROR_LOCKED        = -4,
    VPAD_READ_ERROR_INIT          = -5
};

TYPED_ENUM(u8, VPADButtonProcMode) {
    VPAD_BUTTON_PROC_MODE_LOOSE = 0,
    VPAD_BUTTON_PROC_MODE_TIGHT = 1
};

TYPED_ENUM(u16, VPADTpTouch) {
    VPAD_TP_TOUCH_OFF = 0,
    VPAD_TP_TOUCH_ON  = 1
};

TYPED_ENUM(u16, VPADTpValidity) {
    VPAD_TP_VALIDITY_VALID     = 0,
    VPAD_TP_VALIDITY_INVALID_X = 1 << 0,
    VPAD_TP_VALIDITY_INVALID_Y = 1 << 1,
};

TYPED_ENUM(u8, VPADBatteryLevel) {
    VPAD_BATTERY_LEVEL_CHARGE   = 0,
    VPAD_BATTERY_LEVEL_SHUTDOWN = 1,
    VPAD_BATTERY_LEVEL_CRITICAL = 2,
    VPAD_BATTERY_LEVEL_LOW      = 3,
    VPAD_BATTERY_LEVEL_MEDIUM   = 4,
    VPAD_BATTERY_LEVEL_HIGH     = 5,
    VPAD_BATTERY_LEVEL_MAX      = 6,
};

TYPED_ENUM(u8, VPADMicStatus) {
    VPAD_MIC_STATUS_NONE = 0,
    VPAD_MIC_STATUS_ON   = 1 << 3
};

TYPED_ENUM(u32, VPADTPResolution) {
    VPAD_TP_1920X1080 = 0,
    VPAD_TP_1280X720  = 1,
    VPAD_TP_854X480   = 2
};

TYPED_ENUM(u32, VPADGyroZeroDriftMode) {
    VPAD_GYRO_ZERODRIFT_LOOSE    = 0,
    VPAD_GYRO_ZERODRIFT_STANDARD = 1,
    VPAD_GYRO_ZERODRIFT_TIGHT    = 2,
    VPAD_GYRO_ZERODRIFT_NONE     = 3
};

TYPED_ENUM(u32, VPADLcdMode) {
    VPAD_LCD_MODE_MUTE            = 0,
    VPAD_LCD_MODE_GAME_CONTROLLER = 1,
    VPAD_LCD_MODE_ON              = 255
};

TYPED_ENUM(u32, VPADPlayMode) {
    VPAD_PLAY_MODE_LOOSE = 0,
    VPAD_PLAY_MODE_TIGHT = 1
};

struct VPADTPData {
    u16            x;
    u16            y;
    VPADTpTouch    touch;
    VPADTpValidity validity;
};

struct VPADTPCalibrationParam {
    s16 offsetX;
    s16 offsetY;
    f32 scaleX;
    f32 scaleY;
};

struct VPADVec2 {
    f32 x;
    f32 y;
};

struct VPADVec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct VPADDir {
    VPADVec3 x;
    VPADVec3 y;
    VPADVec3 z;
};

struct VPADStatus {
    VPADButton       hold;
    VPADButton       trig;
    VPADButton       release;
    VPADVec2         lStick;
    VPADVec2         rStick;
    VPADVec3         acc;
    f32              accValue;
    f32              accSpeed;
    VPADVec2         accVertical;
    VPADVec3         gyro;
    VPADVec3         angle;
    s8               vpadErr;
    VPADTPData       tpData;
    VPADTPData       tpFilteredData1;
    VPADTPData       tpFilteredData2;
    VPADDir          dir;
    bool             headphoneStatus;
    VPADVec3         magnet;
    u8               slideVolume;
    VPADBatteryLevel batteryLevel;
    VPADMicStatus    micStatus;
    u8               slideVolumeCalibrated;
    u8               padding[7];
};

EXPORT_FUNC_H(void, VPADInit, void);
EXPORT_FUNC_H(void, VPADShutdown, void);

EXPORT_FUNC_H(s32, VPADRead, VPADChannel chan, VPADStatus* samplingBufs, u32 length, VPADReadError* err);

EXPORT_FUNC_H(void, VPADSetAccParam, VPADChannel chan, f32 playRadius, f32 sensitivity);
EXPORT_FUNC_H(void, VPADGetAccParam, VPADChannel chan, f32* playRadius, f32* sensitivity);

EXPORT_FUNC_H(void, VPADSetBtnRepeat, VPADChannel chan, f32 delaySec, f32 pulseSec);

EXPORT_FUNC_H(void, VPADEnableStickCrossClamp, VPADChannel chan);
EXPORT_FUNC_H(void, VPADDisableStickCrossClamp, VPADChannel chan);
EXPORT_FUNC_H(void, VPADSetLStickClampThreshold, VPADChannel chan, s32 max, s32 min);
EXPORT_FUNC_H(void, VPADSetRStickClampThreshold, VPADChannel chan, s32 max, s32 min);
EXPORT_FUNC_H(void, VPADGetLStickClampThreshold, VPADChannel chan, s32* max, s32* min);
EXPORT_FUNC_H(void, VPADGetRStickClampThreshold, VPADChannel chan, s32* max, s32* min);
EXPORT_FUNC_H(void, VPADSetStickOrigin, VPADChannel chan);
EXPORT_FUNC_H(void, VPADDisableLStickZeroClamp, VPADChannel chan);
EXPORT_FUNC_H(void, VPADDisableRStickZeroClamp, VPADChannel chan);
EXPORT_FUNC_H(void, VPADEnableLStickZeroClamp, VPADChannel chan);
EXPORT_FUNC_H(void, VPADEnableRStickZeroClamp, VPADChannel chan);
EXPORT_FUNC_H(void, VPADSetCrossStickEmulationParamsL, VPADChannel chan, f32 rotDeg, f32 xyDeg, f32 radius);
EXPORT_FUNC_H(void, VPADSetCrossStickEmulationParamsR, VPADChannel chan, f32 rotDeg, f32 xyDeg, f32 radius);
EXPORT_FUNC_H(void, VPADGetCrossStickEmulationParamsL, VPADChannel chan, f32* rotDeg, f32* xyDeg, f32* radius);
EXPORT_FUNC_H(void, VPADGetCrossStickEmulationParamsR, VPADChannel chan, f32* rotDeg, f32* xyDeg, f32* radius);

EXPORT_FUNC_H(VPADSamplingCallback, VPADSetSamplingCallback, VPADChannel chan, VPADSamplingCallback callback);

EXPORT_FUNC_H(void, VPADSetAccPlayMode, VPADChannel chan, VPADPlayMode mode);
EXPORT_FUNC_H(VPADPlayMode, VPADGetAccPlayMode, VPADChannel chan);

EXPORT_FUNC_H(void, VPADSetButtonProcMode, VPADChannel chan, VPADButtonProcMode mode);
EXPORT_FUNC_H(VPADButtonProcMode, VPADGetButtonProcMode, VPADChannel chan);

EXPORT_FUNC_H(void, VPADSetGyroAngle, VPADChannel chan, f32 ax, f32 ay, f32 az);
EXPORT_FUNC_H(void, VPADSetGyroDirection, VPADChannel chan, VPADDir* dir);
EXPORT_FUNC_H(void, VPADSetGyroDirectionMag, VPADChannel chan, f32 mag);
EXPORT_FUNC_H(void, VPADSetGyroMagnification, VPADChannel chan, f32 pitch, f32 yaw, f32 roll);

EXPORT_FUNC_H(void, VPADEnableGyroZeroPlay, VPADChannel chan);
EXPORT_FUNC_H(void, VPADEnableGyroDirRevise, VPADChannel chan);
EXPORT_FUNC_H(void, VPADEnableGyroAccRevise, VPADChannel chan);

EXPORT_FUNC_H(void, VPADDisableGyroZeroPlay, VPADChannel chan);
EXPORT_FUNC_H(void, VPADDisableGyroDirRevise, VPADChannel chan);
EXPORT_FUNC_H(void, VPADDisableGyroAccRevise, VPADChannel chan);

EXPORT_FUNC_H(f32, VPADIsEnableGyroZeroPlay, VPADChannel chan);
EXPORT_FUNC_H(f32, VPADIsEnableGyroZeroDrift, VPADChannel chan);
EXPORT_FUNC_H(f32, VPADIsEnableGyroDirRevise, VPADChannel chan);
EXPORT_FUNC_H(f32, VPADIsEnableGyroAccRevise, VPADChannel chan);

EXPORT_FUNC_H(void, VPADSetGyroZeroPlayParam, VPADChannel chan, f32 radius);
EXPORT_FUNC_H(void, VPADSetGyroDirReviseParam, VPADChannel chan, f32 revisePw);
EXPORT_FUNC_H(void, VPADSetGyroAccReviseParam, VPADChannel chan, f32 revisePw, f32 reviseRange);
EXPORT_FUNC_H(void, VPADSetGyroDirReviseBase, VPADChannel chan, VPADDir* base);

EXPORT_FUNC_H(void, VPADGetGyroZeroPlayParam, VPADChannel chan, f32* radius);
EXPORT_FUNC_H(void, VPADGetGyroDirReviseParam, VPADChannel chan, f32* revisePw);
EXPORT_FUNC_H(void, VPADGetGyroAccReviseParam, VPADChannel chan, f32* revisePw, f32* reviseRange);

EXPORT_FUNC_H(void, VPADInitGyroZeroPlayParam, VPADChannel chan);
EXPORT_FUNC_H(void, VPADInitGyroDirReviseParam, VPADChannel chan);
EXPORT_FUNC_H(void, VPADInitGyroAccReviseParam, VPADChannel chan);

EXPORT_FUNC_H(void, VPADInitGyroZeroDriftMode, VPADChannel chan);
EXPORT_FUNC_H(void, VPADSetGyroZeroDriftMode, VPADChannel chan, VPADGyroZeroDriftMode mode);
EXPORT_FUNC_H(void, VPADGetGyroZeroDriftMode, VPADChannel chan, VPADGyroZeroDriftMode* mode);

EXPORT_FUNC_H(s16, VPADCalcTPCalibrationParam, VPADTPCalibrationParam* param, u16 rawX1, u16 rawY1, u16 x1, u16 y1, u16 rawX2, u16 rawY2, u16 x2, u16 y2);
EXPORT_FUNC_H(void, VPADSetTPCalibrationParam, VPADChannel chan, const VPADTPCalibrationParam param);
EXPORT_FUNC_H(void, VPADGetTPCalibrationParam, VPADChannel chan, VPADTPCalibrationParam* param);
EXPORT_FUNC_H(void, VPADGetTPCalibratedPoint, VPADChannel chan, VPADTPData* disp, const VPADTPData* raw);
EXPORT_FUNC_H(void, VPADGetTPCalibratedPointEx, VPADChannel chan, VPADTPResolution tpReso, VPADTPData* disp, const VPADTPData* raw);

EXPORT_FUNC_H(s32, VPADControlMotor, VPADChannel chan, u8* pattern, u8 length);
EXPORT_FUNC_H(void, VPADStopMotor, VPADChannel chan);

EXPORT_FUNC_H(s32, VPADSetSensorBar, VPADChannel chan, bool on);

EXPORT_FUNC_H(s32, VPADSetLcdMode, VPADChannel chan, VPADLcdMode mode);
EXPORT_FUNC_H(s32, VPADGetLcdMode, VPADChannel chan, VPADLcdMode* mode);

EXPORT_FUNC_H(u8, VPADGetTVMenuStatus, VPADChannel chan);

EXPORT_FUNC_H(f32, VPADIsStartedGyroMagRevise, VPADChannel chan);
EXPORT_FUNC_H(void, VPADStartGyroMagRevise, VPADChannel chan);
EXPORT_FUNC_H(void, VPADStopGyroMagRevise, VPADChannel chan);

EXPORT_FUNC_H(void, VPADSetGyroMagReviseParam, VPADChannel chan, f32 revisePw, f32 playAngle);
EXPORT_FUNC_H(void, VPADGetGyroMagReviseParam, VPADChannel chan, f32* revisePw, f32* playAngle);

#ifdef __cplusplus
}
#endif