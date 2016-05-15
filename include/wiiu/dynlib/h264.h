#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#include <wiiu/dynlib/coreinit/os.h>

typedef struct H264VUIParameters H264VUIParameters;
typedef struct H264Result H264Result;
typedef struct H264Output H264Output;

TYPED_ENUM(s32, H264Error) {
    H264_ERROR_USE_FM       = 0x0000080,
    H264_ERROR_FM_STAT      = 0x00000FF,
    H264_ERROR_BUFFEREMPTY  = 0x0080000,
    H264_ERROR_STREAM       = 0x1000000,
    H264_ERROR_PARAM        = 0x1010000,
    H264_ERROR_OUTOFMEMORY  = 0x1020000,
    H264_ERROR_INTERNAL     = 0x1030000,
    H264_ERROR_SEQUENCE     = 0x1050000,
    H264_ERROR_MEMSEGMENT   = 0x1060000,
    H264_ERROR_MAX_SIZE     = 0x1070000,
    H264_ERROR_PROFILE      = 0x1080000,
    H264_ERROR_NODATA       = 0x1100000,
    H264_ERROR_NOTSUPPORTED = 0x1180000
};

TYPED_ENUM(u32, H264ParamID) {
    H264_PARAM_ID_FPTR_OUTPUT      = 0x00000001,
    H264_PARAM_ID_OUTPUT_PER_FRAME = 0x20000002,
    H264_PARAM_ID_USER_MEMORY      = 0x70000001
};

TYPED_ENUM(u32, H264Profile) {
    H264_PROFILE_BASELINE = 66,
    H264_PROFILE_MAIN     = 77,
    H264_PROFILE_HIGH     = 100
};

TYPED_ENUM(u32, H264OutputPerFrameFlag) {
    H264_OUTPUT_PER_FRAME_BUFFERING   = 0,
    H264_OUTPUT_PER_FRAME_UNBUFFERING = 1
};

struct H264VUIParameters {
    u8  aspectRatioInfoPresentFlag;
    u8  aspectRatioIdc;
    s16 sarWidth;
    s16 sarHeight;
    u8  overscanInfoPresentFlag;
    u8  overscanAppropriateFlag;
    u8  videoSignalTypePresentFlag;
    u8  videoFormat;
    u8  videoFullRangeFlag;
    u8  colorDescriptionPresentFlag;
    u8  colorPrimaries;
    u8  transferCharacteristics;
    u8  matrixCoefficients;
    u8  chromaLocInfoPresentFlag;
    u8  chromaSampleLocTypeTopField;
    u8  chromaSampleLocTypeBottomField;
    u8  timingInfoPresentFlag;
    u32 numUnitsInTick;
    u32 timeScale;
    u8  fixedFrameRateFlag;
    u8  nalHrdParametersPresentFlag;
    u8  vclHrdParametersPresentFlag;
    u8  lowDelayHrdFlag;
    u8  picStructPresentFlag;
    u8  bitstreamRestrictionFlag;
    u8  motionVectorsOverPicBoundariesFlag;
    s16 maxBytesPerPicDenom;
    s16 maxBitsPerMbDenom;
    s16 log2MaxMvLengthHorizontal;
    s16 log2MaxMvLengthVertical;
    s16 numReorderFrames;
    s16 maxDecFrameBuffering;
};

struct H264Result {
    s32                decStatus;
    f64                timeStamp;
    s32                resultWidth;
    s32                resultHeight;
    s32                nextLine;
    u8                 cropEnableFlag;
    s32                topCrop;
    s32                bottomCrop;
    s32                leftCrop;
    s32                rightCrop;
    u8                 panScanEnableFlag;
    s32                topPanScan;
    s32                bottomPanScan;
    s32                leftPanScan;
    s32                rightPanScan;
    void*              Result;
    u8                 vuiParametersPresentFlag;
    H264VUIParameters* vuiParameters;
    s32                reserved[10];
};

struct H264Output {
    s32          fmCnt;
    H264Result** decResPtr;
    void*        userMemory;
};

EXPORT_FUNC_H(H264Error, H264DECInitParam, s32 memSize, void* memPtr);
EXPORT_FUNC_H(H264Error, H264DECSetParam, void* memPtr, H264ParamID paramid, void* param);
EXPORT_FUNC_H(H264Error, H264DECOpen, void* memPtr);
EXPORT_FUNC_H(H264Error, H264DECBegin, void* memPtr);
EXPORT_FUNC_H(H264Error, H264DECSetBitstream, void* memPtr, const u8* bitStream, const s32 length, const f64 timeStamp);
EXPORT_FUNC_H(H264Error, H264DECExecute, void* memPtr, void* strFmPtr);
EXPORT_FUNC_H(H264Error, H264DECFlush, void* memPtr);
EXPORT_FUNC_H(H264Error, H264DECEnd, void* memPtr);
EXPORT_FUNC_H(H264Error, H264DECClose, void* memPtr);
EXPORT_FUNC_H(H264Error, H264DECMemoryRequirement, H264Profile profile, s32 level, s32 maxWidth, s32 maxHeight, s32* codecMemSize);
EXPORT_FUNC_H(H264Error, H264DECGetImageSize, const u8* buf, s32 totalBytes, s32 streamOffset, s32* width, s32* height);
EXPORT_FUNC_H(H264Error, H264DECFindDecstartpoint, const u8* buf, s32 totalBytes, s32* streamOffset);
EXPORT_FUNC_H(H264Error, H264DECFindIdrpoint, const u8* buf, s32 totalBytes, s32* streamOffset);
EXPORT_FUNC_H(H264Error, H264DECCheckDecunitLength, void* memPtr, const u8* buf, s32 totalBytes, s32 streamOffset, s32* length);
EXPORT_FUNC_H(H264Error, H264DECCheckMemSegmentation, void* memPtr, u32 size);
EXPORT_FUNC_H(H264Error, H264DECCheckSkipableFrame, const u8* buf, s32 length, s32* skipFlag);
EXPORT_FUNC_H(H264Error, H264DECSetParam_FPTR_OUTPUT, void* memPtr, int (*func)(void*));
EXPORT_FUNC_H(H264Error, H264DECSetParam_OUTPUT_PER_FRAME, void* memPtr, H264OutputPerFrameFlag flag);
EXPORT_FUNC_H(H264Error, H264DECSetParam_USER_MEMORY, void* memPtr, void** userMem);

#ifdef __cplusplus
}
#endif