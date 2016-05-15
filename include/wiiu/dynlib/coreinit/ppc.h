#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

EXPORT_FUNC_H(u32, PPCMfmsr, void);
EXPORT_FUNC_H(void, PPCMtmsr, u32 newMSR);
EXPORT_FUNC_H(u32, PPCOrMsr, u32 value);
EXPORT_FUNC_H(u32, PPCAndMsr, u32 value);
EXPORT_FUNC_H(u32, PPCAndCMsr, u32 value);

EXPORT_FUNC_H(u32, PPCMfhid0, void);
EXPORT_FUNC_H(void, PPCMthid0, u32 newHID0);

EXPORT_FUNC_H(u32, PPCMfhid1, void);

EXPORT_FUNC_H(u32, PPCMfhid2, void);
EXPORT_FUNC_H(void, PPCMthid2, u32 newHID2);

EXPORT_FUNC_H(u32, PPCMfwpar, void);
EXPORT_FUNC_H(void, PPCMtwpar, u32 newWpar);

EXPORT_FUNC_H(u32, PPCMfdmaU, void);
EXPORT_FUNC_H(u32, PPCMfdmaL, void);

EXPORT_FUNC_H(void, PPCMtdmaU, u32 newDmau);
EXPORT_FUNC_H(void, PPCMtdmaL, u32 newDmal);

EXPORT_FUNC_H(u32, PPCMfl2cr, void);
EXPORT_FUNC_H(void, PPCMtl2cr, u32 newL2cr);

EXPORT_FUNC_H(void, PPCMtdec, u32 newDec);
EXPORT_FUNC_H(u32, PPCMfdec, void);

EXPORT_FUNC_H(void, PPCSync, void);
EXPORT_FUNC_H(void, PPCEieio, void);

EXPORT_FUNC_H(void, PPCHalt, char* msg, u32 size);
EXPORT_FUNC_H(void, PPCIsync, void);

EXPORT_FUNC_H(u32, PPCMfmmcr0, void);
EXPORT_FUNC_H(void, PPCMtmmcr0, u32 newMmcr0);
EXPORT_FUNC_H(u32, PPCMfmmcr1, void);
EXPORT_FUNC_H(void, PPCMtmmcr1, u32 newMmcr1);
EXPORT_FUNC_H(u32, PPCMfpmc1, void);
EXPORT_FUNC_H(void, PPCMtpmc1, u32 newPmc1);
EXPORT_FUNC_H(u32, PPCMfpmc2, void);
EXPORT_FUNC_H(void, PPCMtpmc2, u32 newPmc2);
EXPORT_FUNC_H(u32, PPCMfpmc3, void);
EXPORT_FUNC_H(void, PPCMtpmc3, u32 newPmc3);
EXPORT_FUNC_H(u32, PPCMfpmc4, void);
EXPORT_FUNC_H(void, PPCMtpmc4, u32 newPmc4);
EXPORT_FUNC_H(u32, PPCMfsia, void);
EXPORT_FUNC_H(void, PPCMtsia, u32 newSia);

EXPORT_FUNC_H(u32, PPCMfpvr, void);

EXPORT_FUNC_H(u32, PPCMffpscr, void);
EXPORT_FUNC_H(void, PPCMtfpscr, u32 newFPSCR);

EXPORT_FUNC_H(void, PPCEnableSpeculation, void);
EXPORT_FUNC_H(void, PPCDisableSpeculation, void);

EXPORT_FUNC_H(void, PPCSetFpIEEEMode, void);
EXPORT_FUNC_H(void, PPCSetFpNonIEEEMode, void);

EXPORT_FUNC_H(u32, PPCMfhid4, void);
EXPORT_FUNC_H(void, PPCMthid4, register u32 newHID4);

EXPORT_FUNC_H(u32, PPCMfpir, void);
EXPORT_FUNC_H(u32, PPCMfsprg0, void);

EXPORT_FUNC_H(void, __PPCHalt, void);
EXPORT_FUNC_H(void, __PPCExit, int result);

#ifdef __cplusplus
}
#endif