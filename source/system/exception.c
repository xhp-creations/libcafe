#include <wiiu.h>

#include <stdio.h>

typedef struct stack_frame {
    struct stack_frame* next;
    void* lr;
} stack_frame;

static char codeDump[1024];
static size_t codeDumpPos;

static void __wiiu_report_disassm(char* fmt, ...) {
    va_list list;
    va_start(list, fmt);

    codeDumpPos += vsnprintf(codeDump + codeDumpPos, sizeof(codeDump) - codeDumpPos, fmt, list);

    va_end(list);
}

static bool __wiiu_default_exception_handler(OSContext* interruptedContext, const char* name) {
    char stackDump[256];
    size_t stackDumpPos = 0;

    stackDumpPos += snprintf(stackDump + stackDumpPos, sizeof(stackDump) - stackDumpPos, "%08X", interruptedContext->srr0);

    if(interruptedContext->lr != 0) {
        stackDumpPos += snprintf(stackDump + stackDumpPos, sizeof(stackDump) - stackDumpPos, " --> %08X", interruptedContext->lr);
    }

    stack_frame* frame = (stack_frame*) interruptedContext->gpr[1];
    for(u32 i = 2; i < 12 && frame != NULL && frame->next != NULL; i++, frame = frame->next) {
        if(i > 0) {
            stackDumpPos += snprintf(stackDump + stackDumpPos, sizeof(stackDump) - stackDumpPos, " --> ");

            if(i % 4 == 0) {
                stackDumpPos += snprintf(stackDump + stackDumpPos, sizeof(stackDump) - stackDumpPos, "\n");
            }
        }

        stackDumpPos += snprintf(stackDump + stackDumpPos, sizeof(stackDump) - stackDumpPos, "%08X", (u32) frame->next->lr);
    }

    codeDumpPos = 0;
    DisassemblePPCRange((void*) (interruptedContext->srr0 - 0x10), (void*) (interruptedContext->srr0 + 0x10), __wiiu_report_disassm, NULL, DISASM_FLAG_NONE);

    char final[2048];
    snprintf(final, sizeof(final),
             "Exception (%s) occurred!\n"
             "GPR00 %08X GPR08 %08X GPR16 %08X GPR24 %08X\n"
             "GPR01 %08X GPR09 %08X GPR17 %08X GPR25 %08X\n"
             "GPR02 %08X GPR10 %08X GPR18 %08X GPR26 %08X\n"
             "GPR03 %08X GPR11 %08X GPR19 %08X GPR27 %08X\n"
             "GPR04 %08X GPR12 %08X GPR20 %08X GPR28 %08X\n"
             "GPR05 %08X GPR13 %08X GPR21 %08X GPR29 %08X\n"
             "GPR06 %08X GPR14 %08X GPR22 %08X GPR30 %08X\n"
             "GPR07 %08X GPR15 %08X GPR23 %08X GPR31 %08X\n"
             "LR    %08X SRR0  %08X SRR1  %08X\n"
             "DAR   %08X DSISR %08X\n"
             "STACK DUMP:\n"
             "%s\n"
             "CODE DUMP:\n"
             "%s\n",

             name,
             interruptedContext->gpr[0],             interruptedContext->gpr[8],             interruptedContext->gpr[16], interruptedContext->gpr[24],
             interruptedContext->gpr[1],             interruptedContext->gpr[9],             interruptedContext->gpr[17], interruptedContext->gpr[25],
             interruptedContext->gpr[2],             interruptedContext->gpr[10],            interruptedContext->gpr[18], interruptedContext->gpr[26],
             interruptedContext->gpr[3],             interruptedContext->gpr[11],            interruptedContext->gpr[19], interruptedContext->gpr[27],
             interruptedContext->gpr[4],             interruptedContext->gpr[12],            interruptedContext->gpr[20], interruptedContext->gpr[28],
             interruptedContext->gpr[5],             interruptedContext->gpr[13],            interruptedContext->gpr[21], interruptedContext->gpr[29],
             interruptedContext->gpr[6],             interruptedContext->gpr[14],            interruptedContext->gpr[22], interruptedContext->gpr[30],
             interruptedContext->gpr[7],             interruptedContext->gpr[15],            interruptedContext->gpr[23], interruptedContext->gpr[31],
             interruptedContext->lr,                 interruptedContext->srr0,               interruptedContext->srr1,
             interruptedContext->exceptionSpecific0, interruptedContext->exceptionSpecific1,
             stackDump,
             codeDump);

    OSFatal(final);

    return true;
}

static bool __wiiu_default_exception_handler_dsi(OSContext* interruptedContext) {
    return __wiiu_default_exception_handler(interruptedContext, "DSI");
}

static bool __wiiu_default_exception_handler_isi(OSContext* interruptedContext) {
    return __wiiu_default_exception_handler(interruptedContext, "ISI");
}

static bool __wiiu_default_exception_handler_program(OSContext* interruptedContext) {
    return __wiiu_default_exception_handler(interruptedContext, "Program");
}

void __wiiu_exception_handlers_install() {
    OSSetExceptionCallbackEx(OS_EXCEPTION_MODE_GLOBAL_ALL_CORES, OS_EXCEPTION_TYPE_DSI, __wiiu_default_exception_handler_dsi);
    OSSetExceptionCallbackEx(OS_EXCEPTION_MODE_GLOBAL_ALL_CORES, OS_EXCEPTION_TYPE_ISI, __wiiu_default_exception_handler_isi);
    OSSetExceptionCallbackEx(OS_EXCEPTION_MODE_GLOBAL_ALL_CORES, OS_EXCEPTION_TYPE_PROGRAM, __wiiu_default_exception_handler_program);
}

void __wiiu_exception_handlers_uninstall() {
    OSSetExceptionCallbackEx(OS_EXCEPTION_MODE_GLOBAL_ALL_CORES, OS_EXCEPTION_TYPE_DSI, NULL);
    OSSetExceptionCallbackEx(OS_EXCEPTION_MODE_GLOBAL_ALL_CORES, OS_EXCEPTION_TYPE_ISI, NULL);
    OSSetExceptionCallbackEx(OS_EXCEPTION_MODE_GLOBAL_ALL_CORES, OS_EXCEPTION_TYPE_PROGRAM, NULL);
}