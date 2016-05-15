#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

typedef void  (*DisassembleReport)(char* fmt, ...);
typedef void* (*DisassembleGetSym)(void* addr, char* out, size_t outLength);

TYPED_ENUM(int, DisassembleFlag) {
    DISASM_FLAG_NONE        = 0,
    DISASM_FLAG_SIMPLIFY    = 1 << 0,
    DISASM_FLAG_REG_SPACES  = 1 << 5,
    DISASM_FLAG_EMIT_DISASM = 1 << 6,
    DISASM_FLAG_EMIT_ADDR   = 1 << 7,
    DISASM_FLAG_EMIT_FUNCS  = 1 << 8
};

EXPORT_FUNC_H(void, DisassemblePPCOpcode, u32* opcode, char* out, u32 size, DisassembleGetSym getSym, DisassembleFlag options);
EXPORT_FUNC_H(void, DisassemblePPCRange, void* start, void* end, DisassembleReport report, DisassembleGetSym getSym, DisassembleFlag options);

#ifdef __cplusplus
}
#endif