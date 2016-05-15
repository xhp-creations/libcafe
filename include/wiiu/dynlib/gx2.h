#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

#include <wiiu/types.h>
#include <wiiu/dynlib/dynlib.h>

#include <wiiu/dynlib/coreinit/mem.h>
#include <wiiu/dynlib/coreinit/os.h>

typedef union GX2MetricResult GX2MetricResult;

typedef struct GX2UserContext GX2UserContext;
typedef struct GX2CompSel GX2CompSel;
typedef struct GX2DisplayListOverrun GX2DisplayListOverrun;
typedef struct GX2ContextState GX2ContextState;
typedef struct GX2PerfData GX2PerfData;
typedef struct _GX2CounterInfo _GX2CounterInfo;
typedef struct GX2PerfInfo GX2PerfInfo;
typedef struct GX2CounterInfo GX2CounterInfo;
typedef struct GX2QueryInfo GX2QueryInfo;
typedef struct GX2StreamOutStats GX2StreamOutStats;
typedef struct GX2DepthStencilControlReg GX2DepthStencilControlReg;
typedef struct GX2PolygonControlReg GX2PolygonControlReg;
typedef struct GX2StencilMaskReg GX2StencilMaskReg;
typedef struct GX2AlphaTestReg GX2AlphaTestReg;
typedef struct GX2AlphaToMaskReg GX2AlphaToMaskReg;
typedef struct GX2PolygonOffsetReg GX2PolygonOffsetReg;
typedef struct GX2TargetChannelMaskReg GX2TargetChannelMaskReg;
typedef struct GX2AAMaskReg GX2AAMaskReg;
typedef struct GX2ColorControlReg GX2ColorControlReg;
typedef struct GX2BlendControlReg GX2BlendControlReg;
typedef struct GX2BlendConstantColorReg GX2BlendConstantColorReg;
typedef struct GX2PointSizeReg GX2PointSizeReg;
typedef struct GX2PointLimitsReg GX2PointLimitsReg;
typedef struct GX2LineWidthReg GX2LineWidthReg;
typedef struct GX2ViewportReg GX2ViewportReg;
typedef struct GX2ScissorReg GX2ScissorReg;
typedef struct GX2RBuffer GX2RBuffer;
typedef struct GX2UniformBlock GX2UniformBlock;
typedef struct GX2UniformInitialValue GX2UniformInitialValue;
typedef struct GX2UniformVar GX2UniformVar;
typedef struct GX2AttribVar GX2AttribVar;
typedef struct GX2AttribStream GX2AttribStream;
typedef struct GX2SamplerVar GX2SamplerVar;
typedef struct GX2VertexShader GX2VertexShader;
typedef struct GX2GeometryShader GX2GeometryShader;
typedef struct GX2PixelShader GX2PixelShader;
typedef struct GX2FetchShader GX2FetchShader;
typedef struct GX2DispatchParams GX2DispatchParams;
typedef struct GX2ComputeShader GX2ComputeShader;
typedef struct GX2StreamOutContext GX2StreamOutContext;
typedef struct GX2StreamOutBuffer GX2StreamOutBuffer;
typedef struct GX2Surface GX2Surface;
typedef struct GX2ColorBuffer GX2ColorBuffer;
typedef struct GX2DepthBuffer GX2DepthBuffer;
typedef struct GX2HiStencilState GX2HiStencilState;
typedef struct GX2HiStencilInfo GX2HiStencilInfo;
typedef struct GX2RectInt GX2RectInt;
typedef struct GX2PointInt GX2PointInt;
typedef struct GX2AASampleLoc GX2AASampleLoc;
typedef struct GX2Texture GX2Texture;
typedef struct GX2Sampler GX2Sampler;

TYPED_ENUM(u32, GX2DRCEventReason) {
    GX2_DRC_DETATCH = 0,
    GX2_DRC_ATTACH  = 1
};

TYPED_ENUM(u32, GX2InitAttrib) {
    GX2_INIT_ATTRIB_NULL              = 0,
    GX2_INIT_ATTRIB_CB_BASE           = 1,
    GX2_INIT_ATTRIB_CB_SIZE           = 2,
    GX2_INIT_ATTRIB_UDA_LEVEL         = 3,
    GX2_INIT_ATTRIB_UDA_TESTMODE      = 4,
    GX2_INIT_ATTRIB_UDA_DISABLE_ALERT = 5,
    GX2_INIT_ATTRIB_UDA_MAXFIRECOUNT  = 6,
    GX2_INIT_ATTRIB_ARGC              = 7,
    GX2_INIT_ATTRIB_ARGV              = 8,
    GX2_INIT_ATTRIB_PROFILE_MODE      = 9,
    GX2_INIT_ATTRIB_TOSS_STAGE        = 10
};

TYPED_ENUM(u32, GX2FrontFaceMode) {
    GX2_FRONT_FACE_CCW = 0,
    GX2_FRONT_FACE_CW  = 1
};

TYPED_ENUM(u32, GX2PolygonMode) {
    GX2_POLYGON_MODE_POINT    = 0,
    GX2_POLYGON_MODE_LINE     = 1,
    GX2_POLYGON_MODE_TRIANGLE = 2
};

TYPED_ENUM(u32, GX2CompareFunction) {
    GX2_COMPARE_NEVER    = 0,
    GX2_COMPARE_LESS     = 1,
    GX2_COMPARE_EQUAL    = 2,
    GX2_COMPARE_LEQUAL   = 3,
    GX2_COMPARE_GREATER  = 4,
    GX2_COMPARE_NOTEQUAL = 5,
    GX2_COMPARE_GEQUAL   = 6,
    GX2_COMPARE_ALWAYS   = 7
};

TYPED_ENUM(u32, GX2StencilFunction) {
    GX2_STENCIL_KEEP      = 0,
    GX2_STENCIL_ZERO      = 1,
    GX2_STENCIL_REPLACE   = 2,
    GX2_STENCIL_INCR      = 3,
    GX2_STENCIL_DECR      = 4,
    GX2_STENCIL_INVERT    = 5,
    GX2_STENCIL_INCR_WRAP = 6,
    GX2_STENCIL_DECR_WRAP = 7
};

TYPED_ENUM(u32, GX2ChannelMask) {
    GX2_CHANNEL_MASK_NONE = 0,
    GX2_CHANNEL_MASK_R    = 1 << 0,
    GX2_CHANNEL_MASK_G    = 1 << 1,
    GX2_CHANNEL_MASK_B    = 1 << 2,
    GX2_CHANNEL_MASK_A    = 1 << 3
};

TYPED_ENUM(u32, GX2LogicOp) {
    GX2_LOGIC_OP_CLEAR   = 0x00,
    GX2_LOGIC_OP_SET     = 0xFF,
    GX2_LOGIC_OP_COPY    = 0xCC,
    GX2_LOGIC_OP_INVCOPY = 0x33,
    GX2_LOGIC_OP_NOOP    = 0xAA,
    GX2_LOGIC_OP_INV     = 0x55,
    GX2_LOGIC_OP_AND     = 0x88,
    GX2_LOGIC_OP_NAND    = 0x77,
    GX2_LOGIC_OP_OR      = 0xEE,
    GX2_LOGIC_OP_NOR     = 0x11,
    GX2_LOGIC_OP_XOR     = 0x66,
    GX2_LOGIC_OP_EQUIV   = 0x99,
    GX2_LOGIC_OP_REVAND  = 0x44,
    GX2_LOGIC_OP_INVAND  = 0x22,
    GX2_LOGIC_OP_REVOR   = 0xDD,
    GX2_LOGIC_OP_INVOR   = 0xBB
};

TYPED_ENUM(u32, GX2BlendFunction) {
    GX2_BLEND_ZERO                     = 0,
    GX2_BLEND_ONE                      = 1,
    GX2_BLEND_SRC_COLOR                = 2,
    GX2_BLEND_ONE_MINUS_SRC_COLOR      = 3,
    GX2_BLEND_SRC_ALPHA                = 4,
    GX2_BLEND_ONE_MINUS_SRC_ALPHA      = 5,
    GX2_BLEND_DST_ALPHA                = 6,
    GX2_BLEND_ONE_MINUS_DST_ALPHA      = 7,
    GX2_BLEND_DST_COLOR                = 8,
    GX2_BLEND_ONE_MINUS_DST_COLOR      = 9,
    GX2_BLEND_SRC_ALPHA_SATURATE       = 10,
    GX2_BLEND_CONSTANT_COLOR           = 13,
    GX2_BLEND_ONE_MINUS_CONSTANT_COLOR = 14,
    GX2_BLEND_SRC1_COLOR               = 15,
    GX2_BLEND_ONE_MINUS_SRC1_COLOR     = 16,
    GX2_BLEND_SRC1_ALPHA               = 17,
    GX2_BLEND_ONE_MINUS_SRC1_ALPHA     = 18,
    GX2_BLEND_CONSTANT_ALPHA           = 19,
    GX2_BLEND_ONE_MINUS_CONSTANT_ALPHA = 20
};

TYPED_ENUM(u32, GX2BlendCombine) {
    GX2_BLEND_COMBINE_ADD           = 0,
    GX2_BLEND_COMBINE_SRC_MINUS_DST = 1,
    GX2_BLEND_COMBINE_MIN           = 2,
    GX2_BLEND_COMBINE_MAX           = 3,
    GX2_BLEND_COMBINE_DST_MINUS_SRC = 4
};

TYPED_ENUM(u32, GX2AlphaToMaskMode) {
    GX2_ALPHA_TO_MASK_0 = 0,
    GX2_ALPHA_TO_MASK_1 = 1,
    GX2_ALPHA_TO_MASK_2 = 2,
    GX2_ALPHA_TO_MASK_3 = 3,
    GX2_ALPHA_TO_MASK_4 = 4
};

TYPED_ENUM(u32, GX2RenderTarget) {
    GX2_RENDER_TARGET_0 = 0,
    GX2_RENDER_TARGET_1 = 1,
    GX2_RENDER_TARGET_2 = 2,
    GX2_RENDER_TARGET_3 = 3,
    GX2_RENDER_TARGET_4 = 4,
    GX2_RENDER_TARGET_5 = 5,
    GX2_RENDER_TARGET_6 = 6,
    GX2_RENDER_TARGET_7 = 7
};

TYPED_ENUM(u32, GX2SpecialState) {
    GX2_SPECIAL_STATE_CLEAR                = 0,
    GX2_SPECIAL_STATE_CLEAR_HIZ            = 1,
    GX2_SPECIAL_STATE_COPY                 = 2,
    GX2_SPECIAL_STATE_EXPAND_COLOR         = 3,
    GX2_SPECIAL_STATE_EXPAND_DEPTH         = 4,
    GX2_SPECIAL_STATE_CONVERT_DEPTH        = 5,
    GX2_SPECIAL_STATE_CONVERT_AADEPTH      = 6,
    GX2_SPECIAL_STATE_RESOLVE_COLOR        = 7,
    GX2_SPECIAL_STATE_CLEAR_COLOR_AS_DEPTH = 8
};

TYPED_ENUM(u32, GX2AttribFormat) {
    GX2_ATTRIB_FORMAT_8_UNORM                   = 0x000,
    GX2_ATTRIB_FORMAT_8_UINT                    = 0x100,
    GX2_ATTRIB_FORMAT_8_SNORM                   = 0x200,
    GX2_ATTRIB_FORMAT_8_SINT                    = 0x300,
    GX2_ATTRIB_FORMAT_8_UINT_TO_FLOAT           = 0x800,
    GX2_ATTRIB_FORMAT_8_SINT_TO_FLOAT           = 0xA00,
    GX2_ATTRIB_FORMAT_4_4_UNORM                 = 0x001,
    GX2_ATTRIB_FORMAT_16_UNORM                  = 0x002,
    GX2_ATTRIB_FORMAT_16_UINT                   = 0x102,
    GX2_ATTRIB_FORMAT_16_SNORM                  = 0x202,
    GX2_ATTRIB_FORMAT_16_SINT                   = 0x302,
    GX2_ATTRIB_FORMAT_16_FLOAT                  = 0x803,
    GX2_ATTRIB_FORMAT_16_UINT_TO_FLOAT          = 0x802,
    GX2_ATTRIB_FORMAT_16_SINT_TO_FLOAT          = 0xA02,
    GX2_ATTRIB_FORMAT_8_8_UNORM                 = 0x004,
    GX2_ATTRIB_FORMAT_8_8_UINT                  = 0x104,
    GX2_ATTRIB_FORMAT_8_8_SNORM                 = 0x204,
    GX2_ATTRIB_FORMAT_8_8_SINT                  = 0x304,
    GX2_ATTRIB_FORMAT_8_8_UINT_TO_FLOAT         = 0x804,
    GX2_ATTRIB_FORMAT_8_8_SINT_TO_FLOAT         = 0xA04,
    GX2_ATTRIB_FORMAT_32_UINT                   = 0x105,
    GX2_ATTRIB_FORMAT_32_SINT                   = 0x305,
    GX2_ATTRIB_FORMAT_32_FLOAT                  = 0x806,
    GX2_ATTRIB_FORMAT_16_16_UNORM               = 0x007,
    GX2_ATTRIB_FORMAT_16_16_UINT                = 0x107,
    GX2_ATTRIB_FORMAT_16_16_SNORM               = 0x207,
    GX2_ATTRIB_FORMAT_16_16_SINT                = 0x307,
    GX2_ATTRIB_FORMAT_16_16_FLOAT               = 0x808,
    GX2_ATTRIB_FORMAT_16_16_UINT_TO_FLOAT       = 0x807,
    GX2_ATTRIB_FORMAT_16_16_SINT_TO_FLOAT       = 0xA07,
    GX2_ATTRIB_FORMAT_10_11_11_FLOAT            = 0x809,
    GX2_ATTRIB_FORMAT_8_8_8_8_UNORM             = 0x00A,
    GX2_ATTRIB_FORMAT_8_8_8_8_UINT              = 0x10A,
    GX2_ATTRIB_FORMAT_8_8_8_8_SNORM             = 0x20A,
    GX2_ATTRIB_FORMAT_8_8_8_8_SINT              = 0x30A,
    GX2_ATTRIB_FORMAT_8_8_8_8_UINT_TO_FLOAT     = 0x80A,
    GX2_ATTRIB_FORMAT_8_8_8_8_SINT_TO_FLOAT     = 0xA0A,
    GX2_ATTRIB_FORMAT_10_10_10_2_UNORM          = 0x00B,
    GX2_ATTRIB_FORMAT_10_10_10_2_UINT           = 0x10B,
    GX2_ATTRIB_FORMAT_10_10_10_2_SNORM          = 0x20B,
    GX2_ATTRIB_FORMAT_10_10_10_2_SINT           = 0x30B,
    GX2_ATTRIB_FORMAT_32_32_UINT                = 0x10C,
    GX2_ATTRIB_FORMAT_32_32_SINT                = 0x30C,
    GX2_ATTRIB_FORMAT_32_32_FLOAT               = 0x80D,
    GX2_ATTRIB_FORMAT_16_16_16_16_UNORM         = 0x00E,
    GX2_ATTRIB_FORMAT_16_16_16_16_UINT          = 0x10E,
    GX2_ATTRIB_FORMAT_16_16_16_16_SNORM         = 0x20E,
    GX2_ATTRIB_FORMAT_16_16_16_16_SINT          = 0x30E,
    GX2_ATTRIB_FORMAT_16_16_16_16_FLOAT         = 0x80F,
    GX2_ATTRIB_FORMAT_16_16_16_16_UINT_TO_FLOAT = 0x80E,
    GX2_ATTRIB_FORMAT_16_16_16_16_SINT_TO_FLOAT = 0xA0E,
    GX2_ATTRIB_FORMAT_32_32_32_UINT             = 0x110,
    GX2_ATTRIB_FORMAT_32_32_32_SINT             = 0x310,
    GX2_ATTRIB_FORMAT_32_32_32_FLOAT            = 0x811,
    GX2_ATTRIB_FORMAT_32_32_32_32_UINT          = 0x112,
    GX2_ATTRIB_FORMAT_32_32_32_32_SINT          = 0x312,
    GX2_ATTRIB_FORMAT_32_32_32_32_FLOAT         = 0x813
};

TYPED_ENUM(u32, GX2AttribIndexType) {
    GX2_ATTRIB_INDEX_VERTEX_ID   = 0,
    GX2_ATTRIB_INDEX_INSTANCE_ID = 1
};

TYPED_ENUM(u32, GX2Component) {
    GX2_COMPONENT_X_R = 0,
    GX2_COMPONENT_Y_G = 1,
    GX2_COMPONENT_Z_B = 2,
    GX2_COMPONENT_W_A = 3,
    GX2_COMPONENT_C_0 = 4,
    GX2_COMPONENT_C_1 = 5
};

TYPED_ENUM(u32, GX2ShaderMode) {
    GX2_SHADER_MODE_UNIFORM_REGISTER = 0,
    GX2_SHADER_MODE_UNIFORM_BLOCK    = 1,
    GX2_SHADER_MODE_GEOMETRY_SHADER  = 2,
    GX2_SHADER_MODE_COMPUTE_SHADE    = 3
};

TYPED_ENUM(u32, GX2VarType) {
    GX2_VAR_TYPE_VOID    = 0,
    GX2_VAR_TYPE_BOOL    = 1,
    GX2_VAR_TYPE_INT     = 2,
    GX2_VAR_TYPE_UINT    = 3,
    GX2_VAR_TYPE_FLOAT   = 4,
    GX2_VAR_TYPE_DOUBLE  = 5,
    GX2_VAR_TYPE_DVEC2   = 6,
    GX2_VAR_TYPE_DVEC3   = 7,
    GX2_VAR_TYPE_DVEC4   = 8,
    GX2_VAR_TYPE_VEC2    = 9,
    GX2_VAR_TYPE_VEC3    = 10,
    GX2_VAR_TYPE_VEC4    = 11,
    GX2_VAR_TYPE_BVEC2   = 12,
    GX2_VAR_TYPE_BVEC3   = 13,
    GX2_VAR_TYPE_BVEC4   = 14,
    GX2_VAR_TYPE_IVEC2   = 15,
    GX2_VAR_TYPE_IVEC3   = 16,
    GX2_VAR_TYPE_IVEC4   = 17,
    GX2_VAR_TYPE_UVEC2   = 18,
    GX2_VAR_TYPE_UVEC3   = 19,
    GX2_VAR_TYPE_UVEC4   = 20,
    GX2_VAR_TYPE_MAT2    = 21,
    GX2_VAR_TYPE_MAT2X3  = 22,
    GX2_VAR_TYPE_MAT2X4  = 23,
    GX2_VAR_TYPE_MAT3X2  = 24,
    GX2_VAR_TYPE_MAT3    = 25,
    GX2_VAR_TYPE_MAT3X4  = 26,
    GX2_VAR_TYPE_MAT4X2  = 27,
    GX2_VAR_TYPE_MAT4X3  = 28,
    GX2_VAR_TYPE_MAT4    = 29,
    GX2_VAR_TYPE_DMAT2   = 30,
    GX2_VAR_TYPE_DMAT2X3 = 31,
    GX2_VAR_TYPE_DMAT2X4 = 32,
    GX2_VAR_TYPE_DMAT3X2 = 33,
    GX2_VAR_TYPE_DMAT3   = 34,
    GX2_VAR_TYPE_DMAT3X4 = 35,
    GX2_VAR_TYPE_DMAT4X2 = 36,
    GX2_VAR_TYPE_DMAT4X3 = 37,
    GX2_VAR_TYPE_DMAT4   = 38
};

TYPED_ENUM(u32, GX2SamplerType) {
    GX2_SAMPLER_TYPE_1D                       = 0,
    GX2_SAMPLER_TYPE_2D                       = 1,
    GX2_SAMPLER_TYPE_2D_RECT                  = 2,
    GX2_SAMPLER_TYPE_3D                       = 3,
    GX2_SAMPLER_TYPE_CUBE                     = 4,
    GX2_SAMPLER_TYPE_1D_SHADOW                = 5,
    GX2_SAMPLER_TYPE_2D_SHADOW                = 6,
    GX2_SAMPLER_TYPE_2D_RECT_SHADOW           = 7,
    GX2_SAMPLER_TYPE_CUBE_SHADOW              = 8,
    GX2_SAMPLER_TYPE_1D_ARRAY                 = 9,
    GX2_SAMPLER_TYPE_2D_ARRAY                 = 10,
    GX2_SAMPLER_TYPE_1D_ARRAY_SHADOW          = 11,
    GX2_SAMPLER_TYPE_2D_ARRAY_SHADOW          = 12,
    GX2_SAMPLER_TYPE_CUBE_ARRAY               = 13,
    GX2_SAMPLER_TYPE_CUBE_ARRAY_SHADOW        = 14,
    GX2_SAMPLER_TYPE_BUFFER                   = 15,
    GX2_SAMPLER_TYPE_RESERVED_1               = 16,
    GX2_SAMPLER_TYPE_2D_MS                    = 17,
    GX2_SAMPLER_TYPE_2D_MS_ARRAY              = 18,
    GX2_SAMPLER_TYPE_INT_1D                   = 19,
    GX2_SAMPLER_TYPE_INT_2D                   = 20,
    GX2_SAMPLER_TYPE_INT_2D_RECT              = 21,
    GX2_SAMPLER_TYPE_INT_3D                   = 22,
    GX2_SAMPLER_TYPE_INT_CUBE                 = 23,
    GX2_SAMPLER_TYPE_INT_1D_ARRAY             = 24,
    GX2_SAMPLER_TYPE_INT_2D_ARRAY             = 25,
    GX2_SAMPLER_TYPE_INT_CUBE_ARRAY           = 26,
    GX2_SAMPLER_TYPE_INT_BUFFER               = 27,
    GX2_SAMPLER_TYPE_RESERVED_2               = 28,
    GX2_SAMPLER_TYPE_INT_2D_MS                = 29,
    GX2_SAMPLER_TYPE_INT_2D_MS_ARRAY          = 30,
    GX2_SAMPLER_TYPE_UNSIGNED_INT_1D          = 31,
    GX2_SAMPLER_TYPE_UNSIGNED_INT_2D          = 32,
    GX2_SAMPLER_TYPE_UNSIGNED_INT_2D_RECT     = 33,
    GX2_SAMPLER_TYPE_UNSIGNED_INT_3D          = 34,
    GX2_SAMPLER_TYPE_UNSIGNED_INT_CUBE        = 35,
    GX2_SAMPLER_TYPE_UNSIGNED_INT_1D_ARRAY    = 36,
    GX2_SAMPLER_TYPE_UNSIGNED_INT_2D_ARRAY    = 37,
    GX2_SAMPLER_TYPE_UNSIGNED_INT_CUBE_ARRAY  = 38,
    GX2_SAMPLER_TYPE_UNSIGNED_INT_BUFFER      = 39,
    GX2_SAMPLER_TYPE_RESERVED_3               = 40,
    GX2_SAMPLER_TYPE_UNSIGNED_INT_2D_MS       = 41,
    GX2_SAMPLER_TYPE_UNSIGNED_INT_2D_MS_ARRAY = 42
};

TYPED_ENUM(u32, GX2IndexFormat) {
    GX2_INDEX_FORMAT_U16_LE = 0,
    GX2_INDEX_FORMAT_U32_LE = 1,
    GX2_INDEX_FORMAT_U16    = 4,
    GX2_INDEX_FORMAT_U32    = 9
};

TYPED_ENUM(u32, GX2PrimitiveType) {
    GX2_PRIMITIVE_POINTS                      = 0x01,
    GX2_PRIMITIVE_LINES                       = 0x02,
    GX2_PRIMITIVE_LINE_STRIP                  = 0x03,
    GX2_PRIMITIVE_TRIANGLES                   = 0x04,
    GX2_PRIMITIVE_TRIANGLE_FAN                = 0x05,
    GX2_PRIMITIVE_TRIANGLE_STRIP              = 0x06,
    GX2_PRIMITIVE_LINES_ADJACENCY             = 0x0A,
    GX2_PRIMITIVE_LINE_STRIP_ADJACENCY        = 0x0B,
    GX2_PRIMITIVE_TRIANGLES_ADJACENCY         = 0x0C,
    GX2_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY    = 0x0D,
    GX2_PRIMITIVE_RECTS                       = 0x11,
    GX2_PRIMITIVE_LINE_LOOP                   = 0x12,
    GX2_PRIMITIVE_QUADS                       = 0x13,
    GX2_PRIMITIVE_QUAD_STRIP                  = 0x14,
    GX2_PRIMITIVE_TESSELLATE_LINES            = 0x82,
    GX2_PRIMITIVE_TESSELLATE_LINE_STRIP       = 0x83,
    GX2_PRIMITIVE_TESSELLATE_TRIANGLES        = 0x84,
    GX2_PRIMITIVE_TESSELLATE_TRIANGLE_STRIP   = 0x86,
    GX2_PRIMITIVE_TESSELLATE_QUADS            = 0x93,
    GX2_PRIMITIVE_TESSELLATE_QUAD_STRIP       = 0x94
};

TYPED_ENUM(u32, GX2ClearMode) {
    GX2_CLEAR_NONE    = 0,
    GX2_CLEAR_DEPTH   = 1 << 0,
    GX2_CLEAR_STENCIL = 1 << 1,
    GX2_CLEAR_D_REG   = 1 << 2,
    GX2_CLEAR_S_REG   = 1 << 3
};

TYPED_ENUM(u32, GX2SurfaceFormat) {
    GX2_SURFACE_FORMAT_INVALID                  = 0x000,
    GX2_SURFACE_FORMAT_TC_R8_UNORM              = 0x001,
    GX2_SURFACE_FORMAT_TC_R8_UINT               = 0x101,
    GX2_SURFACE_FORMAT_TC_R8_SNORM              = 0x201,
    GX2_SURFACE_FORMAT_TC_R8_SINT               = 0x301,
    GX2_SURFACE_FORMAT_T_R4_G4_UNORM            = 0x002,
    GX2_SURFACE_FORMAT_TCD_R16_UNORM            = 0x005,
    GX2_SURFACE_FORMAT_TC_R16_UINT              = 0x105,
    GX2_SURFACE_FORMAT_TC_R16_SNORM             = 0x205,
    GX2_SURFACE_FORMAT_TC_R16_SINT              = 0x305,
    GX2_SURFACE_FORMAT_TC_R16_FLOAT             = 0x806,
    GX2_SURFACE_FORMAT_TC_R8_G8_UNORM           = 0x007,
    GX2_SURFACE_FORMAT_TC_R8_G8_UINT            = 0x107,
    GX2_SURFACE_FORMAT_TC_R8_G8_SNORM           = 0x207,
    GX2_SURFACE_FORMAT_TC_R8_G8_SINT            = 0x307,
    GX2_SURFACE_FORMAT_TCS_R5_G6_B5_UNORM       = 0x008,
    GX2_SURFACE_FORMAT_TC_R5_G5_B5_A1_UNORM     = 0x00A,
    GX2_SURFACE_FORMAT_TC_R4_G4_B4_A4_UNORM     = 0x00B,
    GX2_SURFACE_FORMAT_TC_A1_B5_G5_R5_UNORM     = 0x00C,
    GX2_SURFACE_FORMAT_TC_R32_UINT              = 0x10D,
    GX2_SURFACE_FORMAT_TC_R32_SINT              = 0x30D,
    GX2_SURFACE_FORMAT_TCD_R32_FLOAT            = 0x80E,
    GX2_SURFACE_FORMAT_TC_R16_G16_UNORM         = 0x00F,
    GX2_SURFACE_FORMAT_TC_R16_G16_UINT          = 0x10F,
    GX2_SURFACE_FORMAT_TC_R16_G16_SNORM         = 0x20F,
    GX2_SURFACE_FORMAT_TC_R16_G16_SINT          = 0x30F,
    GX2_SURFACE_FORMAT_TC_R16_G16_FLOAT         = 0x810,
    GX2_SURFACE_FORMAT_D_D24_S8_UNORM           = 0x011,
    GX2_SURFACE_FORMAT_T_R24_UNORM_X8           = 0x011,
    GX2_SURFACE_FORMAT_T_X24_G8_UINT            = 0x111,
    GX2_SURFACE_FORMAT_D_D24_S8_FLOAT           = 0x811,
    GX2_SURFACE_FORMAT_TC_R11_G11_B10_FLOAT     = 0x816,
    GX2_SURFACE_FORMAT_TCS_R10_G10_B10_A2_UNORM = 0x019,
    GX2_SURFACE_FORMAT_TC_R10_G10_B10_A2_UINT   = 0x119,
    GX2_SURFACE_FORMAT_T_R10_G10_B10_A2_SNORM   = 0x219,
    GX2_SURFACE_FORMAT_TC_R10_G10_B10_A2_SINT   = 0x319,
    GX2_SURFACE_FORMAT_TCS_R8_G8_B8_A8_UNORM    = 0x01A,
    GX2_SURFACE_FORMAT_TC_R8_G8_B8_A8_UINT      = 0x11A,
    GX2_SURFACE_FORMAT_TC_R8_G8_B8_A8_SNORM     = 0x21A,
    GX2_SURFACE_FORMAT_TC_R8_G8_B8_A8_SINT      = 0x31A,
    GX2_SURFACE_FORMAT_TCS_R8_G8_B8_A8_SRGB     = 0x41A,
    GX2_SURFACE_FORMAT_TCS_A2_B10_G10_R10_UNORM = 0x01B,
    GX2_SURFACE_FORMAT_TC_A2_B10_G10_R10_UINT   = 0x11B,
    GX2_SURFACE_FORMAT_D_D32_FLOAT_S8_UINT_X24  = 0x81C,
    GX2_SURFACE_FORMAT_T_R32_FLOAT_X8_X24       = 0x81C,
    GX2_SURFACE_FORMAT_T_X32_G8_UINT_X24        = 0x11C,
    GX2_SURFACE_FORMAT_TC_R32_G32_UINT          = 0x11D,
    GX2_SURFACE_FORMAT_TC_R32_G32_SINT          = 0x31D,
    GX2_SURFACE_FORMAT_TC_R32_G32_FLOAT         = 0x81E,
    GX2_SURFACE_FORMAT_TC_R16_G16_B16_A16_UNORM = 0x01F,
    GX2_SURFACE_FORMAT_TC_R16_G16_B16_A16_UINT  = 0x11F,
    GX2_SURFACE_FORMAT_TC_R16_G16_B16_A16_SNORM = 0x21F,
    GX2_SURFACE_FORMAT_TC_R16_G16_B16_A16_SINT  = 0x31F,
    GX2_SURFACE_FORMAT_TC_R16_G16_B16_A16_FLOAT = 0x820,
    GX2_SURFACE_FORMAT_TC_R32_G32_B32_A32_UINT  = 0x122,
    GX2_SURFACE_FORMAT_TC_R32_G32_B32_A32_SINT  = 0x322,
    GX2_SURFACE_FORMAT_TC_R32_G32_B32_A32_FLOAT = 0x823,
    GX2_SURFACE_FORMAT_T_BC1_UNORM              = 0x031,
    GX2_SURFACE_FORMAT_T_BC1_SRGB               = 0x431,
    GX2_SURFACE_FORMAT_T_BC2_UNORM              = 0x032,
    GX2_SURFACE_FORMAT_T_BC2_SRGB               = 0x432,
    GX2_SURFACE_FORMAT_T_BC3_UNORM              = 0x033,
    GX2_SURFACE_FORMAT_T_BC3_SRGB               = 0x433,
    GX2_SURFACE_FORMAT_T_BC4_UNORM              = 0x034,
    GX2_SURFACE_FORMAT_T_BC4_SNORM              = 0x234,
    GX2_SURFACE_FORMAT_T_BC5_UNORM              = 0x035,
    GX2_SURFACE_FORMAT_T_BC5_SNORM              = 0x235,
    GX2_SURFACE_FORMAT_T_NV12_UNORM             = 0x081
};

TYPED_ENUM(u32, GX2TileMode) {
    GX2_TILE_MODE_DEFAULT         = 0,
    GX2_TILE_MODE_LINEAR_ALIGNED  = 1,
    GX2_TILE_MODE_1D_TILED_THIN1  = 2,
    GX2_TILE_MODE_1D_TILED_THICK  = 3,
    GX2_TILE_MODE_2D_TILED_THIN1  = 4,
    GX2_TILE_MODE_2D_TILED_THIN2  = 5,
    GX2_TILE_MODE_2D_TILED_THIN4  = 6,
    GX2_TILE_MODE_2D_TILED_THICK  = 7,
    GX2_TILE_MODE_2B_TILED_THIN1  = 8,
    GX2_TILE_MODE_2B_TILED_THIN2  = 9,
    GX2_TILE_MODE_2B_TILED_THIN4  = 10,
    GX2_TILE_MODE_2B_TILED_THICK  = 11,
    GX2_TILE_MODE_3D_TILED_THIN1  = 12,
    GX2_TILE_MODE_3D_TILED_THICK  = 13,
    GX2_TILE_MODE_3B_TILED_THIN1  = 14,
    GX2_TILE_MODE_3B_TILED_THICK  = 15,
    GX2_TILE_MODE_LINEAR_SPECIAL  = 16,
    GX2_TILE_MODE_DEFAULT_FIX2197 = 32
};

TYPED_ENUM(u32, GX2SurfaceUse) {
    GX2_SURFACE_USE_TEXTURE      = 1 << 0,
    GX2_SURFACE_USE_COLOR_BUFFER = 1 << 1,
    GX2_SURFACE_USE_DEPTH_BUFFER = 1 << 2,
    GX2_SURFACE_USE_SCAN_BUFFER  = 1 << 3,
    GX2_SURFACE_USE_FTV          = 1 << 31
};

TYPED_ENUM(u32, GX2SurfaceDim) {
    GX2_SURFACE_DIM_1D            = 0,
    GX2_SURFACE_DIM_2D            = 1,
    GX2_SURFACE_DIM_3D            = 2,
    GX2_SURFACE_DIM_CUBE          = 3,
    GX2_SURFACE_DIM_1D_ARRAY      = 4,
    GX2_SURFACE_DIM_2D_ARRAY      = 5,
    GX2_SURFACE_DIM_2D_MSAA       = 6,
    GX2_SURFACE_DIM_2D_MSAA_ARRAY = 7
};

TYPED_ENUM(u32, GX2AAMode) {
    GX2_AA_MODE_1X = 0,
    GX2_AA_MODE_2X = 1,
    GX2_AA_MODE_4X = 2,
    GX2_AA_MODE_8X = 3
};

TYPED_ENUM(u32, GX2TexClamp) {
    GX2_TEX_CLAMP_WRAP                    = 0,
    GX2_TEX_CLAMP_MIRROR                  = 1,
    GX2_TEX_CLAMP_CLAMP                   = 2,
    GX2_TEX_CLAMP_MIRROR_ONCE             = 3,
    GX2_TEX_CLAMP_CLAMP_HALF_BORDER       = 4,
    GX2_TEX_CLAMP_MIRROR_ONCE_HALF_BORDER = 5,
    GX2_TEX_CLAMP_CLAMP_BORDER            = 6,
    GX2_TEX_CLAMP_MIRROR_ONCE_BORDER      = 7
};

TYPED_ENUM(u32, GX2TexBorderType) {
    GX2_TEX_BORDER_CLEAR_BLACK  = 0,
    GX2_TEX_BORDER_SOLID_BLACK  = 1,
    GX2_TEX_BORDER_SOLID_WHITE  = 2,
    GX2_TEX_BORDER_USE_REGISTER = 3
};

TYPED_ENUM(u32, GX2RoundingModeType) {
    GX2_ROUNDING_MODE_ROUND_TO_EVEN = 0,
    GX2_ROUNDING_MODE_TRUNCATE      = 1
};

TYPED_ENUM(u32, GX2TexXYFilterType) {
    GX2_TEX_XY_FILTER_POINT    = 0,
    GX2_TEX_XY_FILTER_BILINEAR = 1
};

TYPED_ENUM(u32, GX2TexZFilterType) {
    GX2_TEX_Z_FILTER_USE_XY = 0,
    GX2_TEX_Z_FILTER_POINT  = 1,
    GX2_TEX_Z_FILTER_LINEAR = 2
};

TYPED_ENUM(u32, GX2TexMipFilterType) {
    GX2_TEX_MIP_FILTER_NO_MIP = 0,
    GX2_TEX_MIP_FILTER_POINT  = 1,
    GX2_TEX_MIP_FILTER_LINEAR = 2
};

TYPED_ENUM(u32, GX2TexZPerfType) {
    GX2_TEX_Z_PERF_0 = 0,
    GX2_TEX_Z_PERF_1 = 1,
    GX2_TEX_Z_PERF_2 = 2,
    GX2_TEX_Z_PERF_3 = 3
};

TYPED_ENUM(u32, GX2TexMipPerfType) {
    GX2_TEX_MIP_PERF_0 = 0,
    GX2_TEX_MIP_PERF_1 = 1,
    GX2_TEX_MIP_PERF_2 = 2,
    GX2_TEX_MIP_PERF_3 = 3,
    GX2_TEX_MIP_PERF_4 = 4,
    GX2_TEX_MIP_PERF_5 = 5,
    GX2_TEX_MIP_PERF_6 = 6,
    GX2_TEX_MIP_PERF_7 = 7
};

TYPED_ENUM(u32, GX2TexAnisoRatio) {
    GX2_TEX_ANISO_1_TO_1  = 0,
    GX2_TEX_ANISO_2_TO_1  = 1,
    GX2_TEX_ANISO_4_TO_1  = 2,
    GX2_TEX_ANISO_8_TO_1  = 3,
    GX2_TEX_ANISO_16_TO_1 = 4
};

TYPED_ENUM(u32, GX2TVScanMode) {
    GX2_TV_SCAN_MODE_NONE     = 0,
    GX2_TV_SCAN_MODE_576I     = 1,
    GX2_TV_SCAN_MODE_480I     = 2,
    GX2_TV_SCAN_MODE_480P     = 3,
    GX2_TV_SCAN_MODE_720P     = 4,
    GX2_TV_SCAN_MODE_RESERVED = 5,
    GX2_TV_SCAN_MODE_1080I    = 6,
    GX2_TV_SCAN_MODE_1080P    = 7
};

TYPED_ENUM(u32, GX2AspectRatio) {
    GX2_ASPECT_RATIO_4_BY_3  = 0,
    GX2_ASPECT_RATIO_16_BY_9 = 1
};

TYPED_ENUM(u32, GX2DRCMode) {
    GX2_DRC_NONE        = 0,
    GX2_DRC_SINGLE      = 1,
    GX2_DRC_DOUBLE      = 2,
    GX2_DRC_SINGLE_30HZ = 3
};

TYPED_ENUM(u32, GX2TVRenderMode) {
    GX2_TV_RENDER_NONE       = 0,
    GX2_TV_RENDER_480_NARROW = 1,
    GX2_TV_RENDER_480_WIDE   = 2,
    GX2_TV_RENDER_720        = 3,
    GX2_TV_RENDER_RESERVED   = 4,
    GX2_TV_RENDER_1080       = 5
};

TYPED_ENUM(u32, GX2BufferingMode) {
    GX2_BUFFERING_SINGLE = 1,
    GX2_BUFFERING_DOUBLE = 2,
    GX2_BUFFERING_TRIPLE = 3,
    GX2_BUFFERING_QUAD   = 4
};

TYPED_ENUM(u32, GX2ScanTarget) {
    GX2_SCAN_TARGET_TV_LEFT    = 1 << 0,
    GX2_SCAN_TARGET_TV_RIGHT   = 1 << 1,
    GX2_SCAN_TARGET_DRC_FIRST  = 1 << 2,
    GX2_SCAN_TARGET_DRC_SECOND = 1 << 3
};

TYPED_ENUM(u32, GX2DRCEncodingHint) {
    GX2_DRC_ENCODING_INVALLIDATE   = 1,
    GX2_DRC_ENCODING_MOTION_VECTOR = 4
};

TYPED_ENUM(u32, GX2PipeEvent) {
    GX2_PIPE_EVENT_TOP                = 0,
    GX2_PIPE_EVENT_BOTTOM             = 1,
    GX2_PIPE_EVENT_BOTTOM_AFTER_FLUSH = 2
};

TYPED_ENUM(u32, GX2CallbackEvent) {
    GX2_CB_EVENT_USER_TS_TOP    = 0,
    GX2_CB_EVENT_USER_TS_BOTTOM = 1,
    GX2_CB_EVENT_VSYNC          = 2,
    GX2_CB_EVENT_FLIP           = 3,
    GX2_CB_EVENT_DL_OVERRUN     = 4
};

TYPED_ENUM(u32, GX2SemaphoreAction) {
    GX2_SEMAPHORE_WAIT   = 0,
    GX2_SEMAPHORE_SIGNAL = 1
};

TYPED_ENUM(u32, GX2PatchType) {
    GX2_PATCH_TYPE_FETCH_SHADER         = 1,
    GX2_PATCH_TYPE_VERTEX_SHADER        = 2,
    GX2_PATCH_TYPE_GEOMETRY_COPY_SHADER = 3,
    GX2_PATCH_TYPE_GEOMETRY_SHADER      = 4,
    GX2_PATCH_TYPE_PIXEL_SHADER         = 5,
    GX2_PATCH_TYPE_COMPUTE_SHADER       = 6
};

TYPED_ENUM(u32, GX2InvalidateType) {
    GX2_INVALIDATE_ATTRIB_BUFFER    = 1 << 0,
    GX2_INVALIDATE_TEXTURE          = 1 << 1,
    GX2_INVALIDATE_UNIFORM_BLOCK    = 1 << 2,
    GX2_INVALIDATE_SHADER           = 1 << 3,
    GX2_INVALIDATE_COLOR_BUFFER     = 1 << 4,
    GX2_INVALIDATE_DEPTH_BUFFER     = 1 << 5,
    GX2_INVALIDATE_CPU              = 1 << 6,
    GX2_INVALIDATE_STREAMOUT_BUFFER = 1 << 7,
    GX2_INVALIDATE_EXPORT_BUFFER    = 1 << 8
};

TYPED_ENUM(u32, GX2DebugMode) {
    GX2_DEBUG_MODE_NONE           = 0,
    GX2_DEBUG_MODE_FLUSH_PER_DRAW = 1,
    GX2_DEBUG_MODE_DONE_PER_FLUSH = 2
};

TYPED_ENUM(u32, GX2ProfileMode) {
    GX2_PROFILE_MODE_NONE                     = 0,
    GX2_PROFILE_MODE_INFINITELY_FAST_HARDWARE = 1 << 0,
    GX2_PROFILE_MODE_WIREFRAME                = 1 << 1,
    GX2_PROFILE_MODE_DISABLE_ALPHABLEND       = 1 << 2,
    GX2_PROFILE_MODE_DISABLE_COLORWRITES      = 1 << 3,
    GX2_PROFILE_MODE_DISABLE_COLOR            = 1 << 4,
    GX2_PROFILE_MODE_MIN_VERTEX_SHADER        = 1 << 5,
    GX2_PROFILE_MODE_MIN_GEOMETRY_SHADER      = 1 << 6,
    GX2_PROFILE_MODE_MIN_PIXEL_SHADER         = 1 << 7,
    GX2_PROFILE_MODE_MIN_VERTEX_FETCH         = 1 << 8,
    GX2_PROFILE_MODE_MIN_TEXTURE_FETCH        = 1 << 9,
    GX2_PROFILE_MODE_DISABLE_Z                = 1 << 10,
    GX2_PROFILE_MODE_DISABLE_ZWRITES          = 1 << 11,
    GX2_PROFILE_MODE_DISABLE_STENCIL          = 1 << 12,
    GX2_PROFILE_MODE_DISABLE_TRILINEAR        = 1 << 13,
    GX2_PROFILE_MODE_DISABLE_ANISO            = 1 << 14,
    GX2_PROFILE_MODE_DISABLE_COLOR_CLEARS     = 1 << 15,
    GX2_PROFILE_MODE_DISABLE_Z_CLEARS         = 1 << 16,
    GX2_PROFILE_MODE_DISABLE_STENCIL_CLEARS   = 1 << 17,
    GX2_PROFILE_MODE_DISABLE_EARLY_Z          = 1 << 18
};

TYPED_ENUM(u32, GX2TossStage) {
    GX2_TOSS_STAGE_NONE                  = 0,
    GX2_TOSS_STAGE_AFTER_VERTEX_FETCH    = 1,
    GX2_TOSS_STAGE_AFTER_VERTEX_SHADER   = 2,
    GX2_TOSS_STAGE_AFTER_GEOMETRY_SHADER = 3,
    GX2_TOSS_STAGE_AFTER_CLIPPING        = 4,
    GX2_TOSS_STAGE_AFTER_PRIMITIVE_SETUP = 5,
    GX2_TOSS_STAGE_AFTER_SCAN_CONVERSION = 6,
    GX2_TOSS_STAGE_AFTER_RASTERIZATION   = 7,
    GX2_TOSS_STAGE_AFTER_PIXEL_SHADER    = 8
};

TYPED_ENUM(u32, GX2EndianSwapMode) {
    GX2_ENDIANSWAP_NONE    = 0,
    GX2_ENDIANSWAP_8IN16   = 1,
    GX2_ENDIANSWAP_8IN32   = 2,
    GX2_ENDIANSWAP_DEFAULT = 3
};

TYPED_ENUM(u32, GX2TessellationMode) {
    GX2_TESSELLATION_MODE_DISCRETE   = 0,
    GX2_TESSELLATION_MODE_CONTINUOUS = 1,
    GX2_TESSELLATION_MODE_ADAPTIVE   = 2
};

TYPED_ENUM(u32, GX2FetchShaderType) {
    GX2_FETCH_SHADER_TESSELATION_NONE      = 0,
    GX2_FETCH_SHADER_TESSELATION_LINES     = 1,
    GX2_FETCH_SHADER_TESSELATION_TRIANGLES = 2,
    GX2_FETCH_SHADER_TESSELATION_QUADS     = 3
};

TYPED_ENUM(u32, GX2QueryType) {
    GX2_QUERY_TYPE_OCCLUSION_CPU       = 0,
    GX2_QUERY_TYPE_STREAMOUT_STATS_CPU = 1,
    GX2_QUERY_TYPE_OCCLUSION_GPU       = 2,
    GX2_QUERY_TYPE_STREAMOUT_STATS_GPU = 3
};

TYPED_ENUM(u32, GX2StreamOutOffsetInit) {
    GX2_STREAMOUT_OFFSET_READ_FROM_CONTEXT = 0,
    GX2_STREAMOUT_OFFSET_RESET             = 1,
    GX2_STREAMOUT_OFFSET_EXPLICIT          = 2
};

TYPED_ENUM(u32, GX2ZRangeBase) {
    GX2_ZRANGE_BASE_ZMIN = 0,
    GX2_ZRANGE_BASE_ZMAX = 1
};

TYPED_ENUM(u32, GX2UDAAlertID) {
    GX2_UDAID_NOALERT              = -1,
    GX2_UDAID_ENABLESTATESHADOWING = 0
};

TYPED_ENUM(u32, GX2UDAAlertLevel) {
    GX2_UDALEVEL_NONE     = 0,
    GX2_UDALEVEL_SEVERE   = 1,
    GX2_UDALEVEL_ORDINARY = 2,
    GX2_UDALEVEL_PEDANTIC = 3
};

TYPED_ENUM(u32, GX2LogAttrib) {
    GX2_LOG_ATTRIB_ENABLE = 0
};

TYPED_ENUM(u32, GX2DebugTagUserStringType) {
    GX2_DEBUG_TAG_INDENT   = 0,
    GX2_DEBUG_TAG_UNDENT   = 1,
    GX2_DEBUG_TAG_COMMENT  = 2,
    GX2_DEBUG_TAG_BOOKMARK = 3
};

TYPED_ENUM(u32, GX2DebugCaptureOptions) {
    GX2_DEBUG_CAPTURE_DEFAULT  = 0,
    GX2_DEBUG_CAPTURE_NO_FLUSH = 1
};

TYPED_ENUM(u32, GX2MiscType) {
    GX2_MISC_HANG_STATE              = 0,
    GX2_MISC_HANG_RESPONSE           = 1,
    GX2_MISC_HANG_RESET_SWAP_TIMEOUT = 2,
    GX2_MISC_HANG_RESET_SWAP_COUNT   = 3
};

TYPED_ENUM(u32, GX2HangState) {
    GX2_HANG_STATE_OK  = 0,
    GX2_HANG_STATE_TS  = 1,
    GX2_HANG_STATE_CB  = 2,
    GX2_HANG_STATE_RB  = 3,
    GX2_HANG_STATE_WF  = 4,
    GX2_HANG_STATE_ETC = 5
};

TYPED_ENUM(u32, GX2HangResponse) {
    GX2_HANG_RESPONSE_NONE  = 0,
    GX2_HANG_RESPONSE_DEBUG = 1,
    GX2_HANG_RESPONSE_RESET = 2
};

TYPED_ENUM(u32, GX2PerfMetricType) {
    GX2_PERF_METRICTYPE_U64 = 0,
    GX2_PERF_METRICTYPE_F32 = 1
};

TYPED_ENUM(u32, GX2CounterId) {
    GX2_COUNTER_CP_0     = 0,
    GX2_COUNTER_GRBM_0   = 1,
    GX2_COUNTER_GRBM_1   = 2,
    GX2_COUNTER_PA_SU_0  = 3,
    GX2_COUNTER_PA_SU_1  = 4,
    GX2_COUNTER_PA_SU_2  = 5,
    GX2_COUNTER_PA_SU_3  = 6,
    GX2_COUNTER_PA_SC_0  = 7,
    GX2_COUNTER_PA_SC_1  = 8,
    GX2_COUNTER_PA_SC_2  = 9,
    GX2_COUNTER_PA_SC_3  = 10,
    GX2_COUNTER_VGT_0    = 11,
    GX2_COUNTER_VGT_1    = 12,
    GX2_COUNTER_VGT_2    = 13,
    GX2_COUNTER_VGT_3    = 14,
    GX2_COUNTER_SQ_0     = 15,
    GX2_COUNTER_SQ_1     = 16,
    GX2_COUNTER_SQ_2     = 17,
    GX2_COUNTER_SQ_3     = 18,
    GX2_COUNTER_SPI_0    = 19,
    GX2_COUNTER_SPI_1    = 20,
    GX2_COUNTER_SPI_2    = 21,
    GX2_COUNTER_SPI_3    = 22,
    GX2_COUNTER_SX_0     = 23,
    GX2_COUNTER_SX_1     = 24,
    GX2_COUNTER_SX_2     = 25,
    GX2_COUNTER_SX_3     = 26,
    GX2_COUNTER_SMX_0    = 27,
    GX2_COUNTER_SMX_1    = 28,
    GX2_COUNTER_SMX_2    = 29,
    GX2_COUNTER_SMX_3    = 30,
    GX2_COUNTER_TD_0_0   = 31,
    GX2_COUNTER_TD_0_1   = 32,
    GX2_COUNTER_TA_0_0   = 33,
    GX2_COUNTER_TA_0_1   = 34,
    GX2_COUNTER_TA_1_0   = 35,
    GX2_COUNTER_TA_1_1   = 36,
    GX2_COUNTER_TCP_0_0  = 37,
    GX2_COUNTER_TCP_0_1  = 38,
    GX2_COUNTER_TCP_1_0  = 39,
    GX2_COUNTER_TCP_1_1  = 40,
    GX2_COUNTER_TCP_2_0  = 41,
    GX2_COUNTER_TCP_2_1  = 42,
    GX2_COUNTER_TCP_3_0  = 43,
    GX2_COUNTER_TCP_3_1  = 44,
    GX2_COUNTER_TCC_0_0  = 45,
    GX2_COUNTER_TCC_0_1  = 46,
    GX2_COUNTER_TCC_1_0  = 47,
    GX2_COUNTER_TCC_1_1  = 48,
    GX2_COUNTER_TCC_2_0  = 49,
    GX2_COUNTER_TCC_2_1  = 50,
    GX2_COUNTER_TCC_3_0  = 51,
    GX2_COUNTER_TCC_3_1  = 52,
    GX2_COUNTER_DB_0_0   = 53,
    GX2_COUNTER_DB_0_1   = 54,
    GX2_COUNTER_DB_1_0   = 55,
    GX2_COUNTER_DB_1_1   = 56,
    GX2_COUNTER_DB_2_0   = 57,
    GX2_COUNTER_DB_2_1   = 58,
    GX2_COUNTER_DB_3_0   = 59,
    GX2_COUNTER_DB_3_1   = 60,
    GX2_COUNTER_CB_0_0   = 61,
    GX2_COUNTER_CB_0_1   = 62,
    GX2_COUNTER_CB_1_0   = 63,
    GX2_COUNTER_CB_1_1   = 64,
    GX2_COUNTER_CB_2_0   = 65,
    GX2_COUNTER_CB_2_1   = 66,
    GX2_COUNTER_CB_3_0   = 67,
    GX2_COUNTER_CB_3_1   = 68,
    GX2_COUNTER_PIPELINE = 69
};

TYPED_ENUM(u32, GX2SqType) {
    GX2_SQ_PS = 1 << 8,
    GX2_SQ_VS = 1 << 9,
    GX2_SQ_GS = 1 << 10,
    GX2_SQ_ES = 1 << 11
};

TYPED_ENUM(u32, GX2StatId) {
    GX2_STAT_CP_CP_COUNT                                   = 0x0000,
    GX2_STAT_CP_RBIU_FIFO_FULL                             = 0x0001,
    GX2_STAT_CP_CSF_RTS_BUT_MIU_NOT_RTR                    = 0x0002,
    GX2_STAT_CP_CSF_I1_BASE_SIZE_FIFO_FULL_6XX             = 0x0003,
    GX2_STAT_CP_CSF_I2_BASE_SIZE_FIFO_FULL_6XX             = 0x0004,
    GX2_STAT_CP_CSF_ST_BASE_SIZE_FIFO_FULL                 = 0x0005,
    GX2_STAT_CP_RING_REORDER_QUEUE_FULL                    = 0x0006,
    GX2_STAT_CP_I1_REORDER_QUEUE_FULL                      = 0x0007,
    GX2_STAT_CP_I2_REORDER_QUEUE_FULL                      = 0x0008,
    GX2_STAT_CP_ST_REORDER_QUEUE_FULL                      = 0x0009,
    GX2_STAT_CP_CSF_RB_WPTR_NEQ_RPTR                       = 0x000A,
    GX2_STAT_CP_CSF_I1_SIZE_NEQ_ZERO                       = 0x000B,
    GX2_STAT_CP_CSF_I2_SIZE_NEQ_ZERO                       = 0x000C,
    GX2_STAT_CP_BRUSH_WR_CONFIRM_FIFO_FULL_6XX             = 0x000D,
    GX2_STAT_CP_CP_GRBM_DWORDS_SENT                        = 0x000E,
    GX2_STAT_CP_ME_PARSER_BUSY                             = 0x000F,
    GX2_STAT_CP_COUNT_TYPE0_PACKETS                        = 0x0010,
    GX2_STAT_CP_COUNT_TYPE3_PACKETS                        = 0x0011,
    GX2_STAT_CP_CSF_RBI1I2_FETCHING                        = 0x0012,
    GX2_STAT_CP_ME_STALLED_FOR_DATA_FROM_PFP               = 0x0013,
    GX2_STAT_CP_CP_GRBM_OUT_OF_CREDITS                     = 0x0014,
    GX2_STAT_CP_CP_PFP_GRBM_OUT_OF_CREDITS                 = 0x0015,
    GX2_STAT_CP_RCIU_STALLED_ON_ME_READ                    = 0x0016,
    GX2_STAT_CP_RCIU_STALLED_ON_DMA_READ                   = 0x0017,
    GX2_STAT_CP_MIU_STALLED_ON_RDREQ_CREDITS_6XX           = 0x0018,
    GX2_STAT_CP_MIU_STALLED_ON_WRREQ_CREDITS_6XX           = 0x0019,
    GX2_STAT_CP_MIU_STALLED_ON_WRCLEAN_PHASE_6XX           = 0x001A,
    GX2_STAT_CP_SSU_STALLED_ON_ACTIVE_CNTX                 = 0x001B,
    GX2_STAT_CP_SSU_STALLED_ON_CLEAN_SIGNALS               = 0x001C,
    GX2_STAT_CP_QU_STALLED_ON_RECT_DONE_PULSE_6XX          = 0x001D,
    GX2_STAT_CP_QU_STALLED_ON_RECT_DONE_WR_CONFIRM_6XX     = 0x001E,
    GX2_STAT_CP_QU_STALLED_ON_SC_EOP_DONE_PULSE            = 0x001F,
    GX2_STAT_CP_QU_STALLED_ON_SX_EOP_DONE_PULSE            = 0x0020,
    GX2_STAT_CP_QU_STALLED_ON_EOP_DONE_WR_CONFIRM          = 0x0021,
    GX2_STAT_CP_QU_STALLED_ON_SIGNAL_SEMAPHORE             = 0x0022,
    GX2_STAT_CP_QU_STALLED_ON_STREAMOUT_ADDRESS            = 0x0023,
    GX2_STAT_CP_QU_STALLED_ON_STREAMOUT_DATA               = 0x0024,
    GX2_STAT_CP_QU_STALLED_ON_PIPELINE_STATISTICS          = 0x0025,
    GX2_STAT_CP_PFP_STALLED_ON_CSF_READY                   = 0x0026,
    GX2_STAT_CP_PFP_STALLED_ON_MEQ_READY                   = 0x0027,
    GX2_STAT_CP_PFP_STALLED_ON_VGT_READY                   = 0x0028,
    GX2_STAT_CP_PFP_STALLED_ON_PENDING_MULTIPASS           = 0x0029,
    GX2_STAT_CP_ME_STALLED_ON_BRUSH_WR_CONFIRM_6XX         = 0x002A,
    GX2_STAT_CP_ME_STALLED_ON_BUSY_BRUSH_LOGIC_6XX         = 0x002B,
    GX2_STAT_CP_ME_STALLED_ON_NO_AVAIL_CR_CNTX_6XX         = 0x002C,
    GX2_STAT_CP_ME_STALLED_ON_NO_AVAIL_GFX_CNTX            = 0x002D,
    GX2_STAT_CP_ME_STALLED_WRITING_TO_RCIU                 = 0x002E,
    GX2_STAT_CP_ME_STALLED_WRITING_CONSTANTS               = 0x002F,
    GX2_STAT_CP_RBIU_STALLED_WRITING_DMA_REGS              = 0x0030,
    GX2_STAT_CP_RBIU_STALLED_WRITING_SEM_REGS              = 0x0031,
    GX2_STAT_CP_RBIU_STALLED_WRITING_MC_WR_ADDR            = 0x0032,
    GX2_STAT_CP_RBIU_STALLED_WRITING_MC_RD_ADDR_6XX        = 0x0033,
    GX2_STAT_CP_RBIU_STALLED_WRITING_EOPDONE_FIFO_600      = 0x0034,
    GX2_STAT_CP_RBIU_STALLED_WRITING_RECTDONE_FIFO_6XX     = 0x0035,
    GX2_STAT_CP_RBIU_STALLED_WRITING_STREAMOUT_FIFO_600    = 0x0036,
    GX2_STAT_CP_RBIU_STALLED_WRITING_PIPESTATS_FIFO_600    = 0x0037,
    GX2_STAT_CP_SEMAPHORE_BUSY_POLLING_FOR_PASS            = 0x0038,
    GX2_STAT_CP_LOAD_STALLED_ON_SET_COHERENCY              = 0x0039,
    GX2_STAT_CP_ME_STALLED_ON_PARTIAL_FLUSH                = 0x003A,
    GX2_STAT_CP_CSF_IDLE_CONFIRM_TO_ACTIVE_6XX             = 0x003B,
    GX2_STAT_CP_DYNAMIC_CLK_VALID                          = 0x003C,
    GX2_STAT_CP_REGISTER_CLK_VALID                         = 0x003D,
    GX2_STAT_GRBM_COUNT                                    = 0x1000,
    GX2_STAT_GRBM_GUI_ACTIVE                               = 0x1001,
    GX2_STAT_GRBM_VGT_NO_DMA_BUSY                          = 0x1002,
    GX2_STAT_GRBM_VGT_DMA_BUSY                             = 0x1003,
    GX2_STAT_GRBM_TA0_BUSY                                 = 0x1004,
    GX2_STAT_GRBM_TA1_BUSY                                 = 0x1005,
    GX2_STAT_GRBM_TA2_BUSY                                 = 0x1006,
    GX2_STAT_GRBM_TA3_BUSY                                 = 0x1007,
    GX2_STAT_GRBM_TC_BUSY_R6XX                             = 0x1008,
    GX2_STAT_GRBM_SX_BUSY                                  = 0x1009,
    GX2_STAT_GRBM_SH_BUSY                                  = 0x100A,
    GX2_STAT_GRBM_SPI_BUSY                                 = 0x100B,
    GX2_STAT_GRBM_SMX_BUSY_R6XX                            = 0x100C,
    GX2_STAT_GRBM_SC_BUSY                                  = 0x100D,
    GX2_STAT_GRBM_DRMDMA_BUSY_R6XX                         = 0x100E,
    GX2_STAT_GRBM_PA_BUSY                                  = 0x100F,
    GX2_STAT_GRBM_DB0_BUSY                                 = 0x1010,
    GX2_STAT_GRBM_DB1_BUSY                                 = 0x1011,
    GX2_STAT_GRBM_DB2_BUSY                                 = 0x1012,
    GX2_STAT_GRBM_DB3_BUSY                                 = 0x1013,
    GX2_STAT_GRBM_CR_BUSY_R6XX                             = 0x1014,
    GX2_STAT_GRBM_CP_COHER_BUSY                            = 0x1015,
    GX2_STAT_GRBM_CP_BUSY                                  = 0x1016,
    GX2_STAT_GRBM_CP_DMA_BUSY                              = 0x1017,
    GX2_STAT_GRBM_CB0_BUSY                                 = 0x1018,
    GX2_STAT_GRBM_CB1_BUSY                                 = 0x1019,
    GX2_STAT_GRBM_CB2_BUSY                                 = 0x101A,
    GX2_STAT_GRBM_CB3_BUSY                                 = 0x101B,
    GX2_STAT_GRBM_VC_BUSY_R6XX                             = 0x101C,
    GX2_STAT_GRBM_EXTERN_STALL                             = 0x101D,
    GX2_STAT_GRBM_CP_DMA_IDLE_STALL                        = 0x101E,
    GX2_STAT_GRBM_GFX_IDLE_STALL                           = 0x101F,
    GX2_STAT_GRBM_GFX_IDLE_CLEAN_STALL                     = 0x1020,
    GX2_STAT_GRBM_GFX_IDLE_STALL_R600                      = 0x1021,
    GX2_STAT_GRBM_GFX_IDLE_CLEAN_STALL_R600                = 0x1022,
    GX2_STAT_GRBM_TA4_BUSY                                 = 0x1023,
    GX2_STAT_GRBM_TA5_BUSY                                 = 0x1024,
    GX2_STAT_GRBM_TA6_BUSY                                 = 0x1025,
    GX2_STAT_GRBM_TA7_BUSY                                 = 0x1026,
    GX2_STAT_GRBM_TA8_BUSY                                 = 0x1027,
    GX2_STAT_GRBM_TA9_BUSY                                 = 0x1028,
    GX2_STAT_GRBM_TA10_BUSY                                = 0x1029,
    GX2_STAT_GRBM_TA11_BUSY                                = 0x102A,
    GX2_STAT_GRBM_TA12_BUSY                                = 0x102B,
    GX2_STAT_GRBM_TA13_BUSY                                = 0x102C,
    GX2_STAT_GRBM_TA14_BUSY                                = 0x102D,
    GX2_STAT_GRBM_TA15_BUSY                                = 0x102E,
    GX2_STAT_GRBM_RESERVED0                                = 0x102F,
    GX2_STAT_GRBM_RESERVED1                                = 0x1030,
    GX2_STAT_GRBM_RESERVED2                                = 0x1031,
    GX2_STAT_GRBM_RESERVED3                                = 0x1032,
    GX2_STAT_GRBM_RESERVED4                                = 0x1033,
    GX2_STAT_GRBM_RESERVED5                                = 0x1034,
    GX2_STAT_GRBM_RESERVED6                                = 0x1035,
    GX2_STAT_GRBM_RESERVED7                                = 0x1036,
    GX2_STAT_GRBM_RESERVED8                                = 0x1037,
    GX2_STAT_GRBM_RESERVED9                                = 0x1038,
    GX2_STAT_GRBM_RESERVED10                               = 0x1039,
    GX2_STAT_GRBM_RESERVED11                               = 0x103A,
    GX2_STAT_GRBM_RESERVED12                               = 0x103B,
    GX2_STAT_GRBM_RESERVED13                               = 0x103C,
    GX2_STAT_GRBM_RESERVED14                               = 0x103D,
    GX2_STAT_GRBM_RESERVED15                               = 0x103E,
    GX2_STAT_GRBM_USER_DEFINED_BUSY                        = 0x103F,
    GX2_STAT_PA_SU_PASX_REQ                                = 0x2000,
    GX2_STAT_PA_SU_PASX_DISABLE_PIPE                       = 0x2001,
    GX2_STAT_PA_SU_PASX_FIRST_VECTOR                       = 0x2002,
    GX2_STAT_PA_SU_PASX_SECOND_VECTOR                      = 0x2003,
    GX2_STAT_PA_SU_PASX_FIRST_DEAD                         = 0x2004,
    GX2_STAT_PA_SU_PASX_SECOND_DEAD                        = 0x2005,
    GX2_STAT_PA_SU_PASX_VTX_KILL_DISCARD                   = 0x2006,
    GX2_STAT_PA_SU_PASX_VTX_NAN_DISCARD                    = 0x2007,
    GX2_STAT_PA_SU_PA_INPUT_PRIM                           = 0x2008,
    GX2_STAT_PA_SU_PA_INPUT_NULL_PRIM                      = 0x2009,
    GX2_STAT_PA_SU_PA_INPUT_EVENT_FLAG                     = 0x200A,
    GX2_STAT_PA_SU_PA_INPUT_FIRST_PRIM_SLOT                = 0x200B,
    GX2_STAT_PA_SU_PA_INPUT_END_OF_PACKET                  = 0x200C,
    GX2_STAT_PA_SU_PA_INPUT_EXTENDED_EVENT                 = 0x200D,
    GX2_STAT_PA_SU_CLPR_CULL_PRIM                          = 0x200E,
    GX2_STAT_PA_SU_CLPR_VVUCP_CULL_PRIM                    = 0x200F,
    GX2_STAT_PA_SU_CLPR_VV_CULL_PRIM                       = 0x2010,
    GX2_STAT_PA_SU_CLPR_UCP_CULL_PRIM                      = 0x2011,
    GX2_STAT_PA_SU_CLPR_VTX_KILL_CULL_PRIM                 = 0x2012,
    GX2_STAT_PA_SU_CLPR_VTX_NAN_CULL_PRIM                  = 0x2013,
    GX2_STAT_PA_SU_CLPR_CULL_TO_NULL_PRIM                  = 0x2014,
    GX2_STAT_PA_SU_CLPR_VVUCP_CLIP_PRIM                    = 0x2015,
    GX2_STAT_PA_SU_CLPR_VV_CLIP_PRIM                       = 0x2016,
    GX2_STAT_PA_SU_CLPR_UCP_CLIP_PRIM                      = 0x2017,
    GX2_STAT_PA_SU_CLPR_POINT_CLIP_CANDIDATE               = 0x2018,
    GX2_STAT_PA_SU_CLPR_CLIP_PLANE_CNT_1                   = 0x2019,
    GX2_STAT_PA_SU_CLPR_CLIP_PLANE_CNT_2                   = 0x201A,
    GX2_STAT_PA_SU_CLPR_CLIP_PLANE_CNT_3                   = 0x201B,
    GX2_STAT_PA_SU_CLPR_CLIP_PLANE_CNT_4                   = 0x201C,
    GX2_STAT_PA_SU_CLPR_CLIP_PLANE_CNT_5_8                 = 0x201D,
    GX2_STAT_PA_SU_CLPR_CLIP_PLANE_CNT_9_12                = 0x201E,
    GX2_STAT_PA_SU_CLPR_CLIP_PLANE_NEAR                    = 0x201F,
    GX2_STAT_PA_SU_CLPR_CLIP_PLANE_FAR                     = 0x2020,
    GX2_STAT_PA_SU_CLPR_CLIP_PLANE_LEFT                    = 0x2021,
    GX2_STAT_PA_SU_CLPR_CLIP_PLANE_RIGHT                   = 0x2022,
    GX2_STAT_PA_SU_CLPR_CLIP_PLANE_TOP                     = 0x2023,
    GX2_STAT_PA_SU_CLPR_CLIP_PLANE_BOTTOM                  = 0x2024,
    GX2_STAT_PA_SU_CLPR_GSC_KILL_CULL_PRIM                 = 0x2025,
    GX2_STAT_PA_SU_CLPR_RASTER_KILL_CULL_PRIM              = 0x2026,
    GX2_STAT_PA_SU_CLSM_NULL_PRIM                          = 0x2027,
    GX2_STAT_PA_SU_CLSM_TOTALLY_VISIBLE_PRIM               = 0x2028,
    GX2_STAT_PA_SU_CLSM_CULL_TO_NULL_PRIM                  = 0x2029,
    GX2_STAT_PA_SU_CLSM_OUT_PRIM_CNT_1                     = 0x202A,
    GX2_STAT_PA_SU_CLSM_OUT_PRIM_CNT_2                     = 0x202B,
    GX2_STAT_PA_SU_CLSM_OUT_PRIM_CNT_3                     = 0x202C,
    GX2_STAT_PA_SU_CLSM_OUT_PRIM_CNT_4                     = 0x202D,
    GX2_STAT_PA_SU_CLSM_OUT_PRIM_CNT_5_8                   = 0x202E,
    GX2_STAT_PA_SU_CLSM_OUT_PRIM_CNT_9_13                  = 0x202F,
    GX2_STAT_PA_SU_CLIPGA_VTE_KILL_PRIM                    = 0x2030,
    GX2_STAT_PA_SU_SU_INPUT_PRIM                           = 0x2031,
    GX2_STAT_PA_SU_SU_INPUT_CLIP_PRIM                      = 0x2032,
    GX2_STAT_PA_SU_SU_INPUT_NULL_PRIM                      = 0x2033,
    GX2_STAT_PA_SU_SU_INPUT_PRIM_DUAL                      = 0x2034,
    GX2_STAT_PA_SU_SU_INPUT_CLIP_PRIM_DUAL                 = 0x2035,
    GX2_STAT_PA_SU_SU_ZERO_AREA_CULL_PRIM                  = 0x2036,
    GX2_STAT_PA_SU_SU_BACK_FACE_CULL_PRIM                  = 0x2037,
    GX2_STAT_PA_SU_SU_FRONT_FACE_CULL_PRIM                 = 0x2038,
    GX2_STAT_PA_SU_SU_POLYMODE_FACE_CULL                   = 0x2039,
    GX2_STAT_PA_SU_SU_POLYMODE_BACK_CULL                   = 0x203A,
    GX2_STAT_PA_SU_SU_POLYMODE_FRONT_CULL                  = 0x203B,
    GX2_STAT_PA_SU_SU_POLYMODE_INVALID_FILL                = 0x203C,
    GX2_STAT_PA_SU_SU_OUTPUT_PRIM                          = 0x203D,
    GX2_STAT_PA_SU_SU_OUTPUT_CLIP_PRIM                     = 0x203E,
    GX2_STAT_PA_SU_SU_OUTPUT_NULL_PRIM                     = 0x203F,
    GX2_STAT_PA_SU_SU_OUTPUT_EVENT_FLAG                    = 0x2040,
    GX2_STAT_PA_SU_SU_OUTPUT_FIRST_PRIM_SLOT               = 0x2041,
    GX2_STAT_PA_SU_SU_OUTPUT_END_OF_PACKET                 = 0x2042,
    GX2_STAT_PA_SU_SU_OUTPUT_POLYMODE_FACE                 = 0x2043,
    GX2_STAT_PA_SU_SU_OUTPUT_POLYMODE_BACK                 = 0x2044,
    GX2_STAT_PA_SU_SU_OUTPUT_POLYMODE_FRONT                = 0x2045,
    GX2_STAT_PA_SU_SU_OUT_CLIP_POLYMODE_FACE               = 0x2046,
    GX2_STAT_PA_SU_SU_OUT_CLIP_POLYMODE_BACK               = 0x2047,
    GX2_STAT_PA_SU_SU_OUT_CLIP_POLYMODE_FRONT              = 0x2048,
    GX2_STAT_PA_SU_SU_OUTPUT_PRIM_DUAL                     = 0x2049,
    GX2_STAT_PA_SU_SU_OUTPUT_CLIP_PRIM_DUAL                = 0x204A,
    GX2_STAT_PA_SU_SU_OUTPUT_POLYMODE_DUAL                 = 0x204B,
    GX2_STAT_PA_SU_SU_OUTPUT_CLIP_POLYMODE_DUAL            = 0x204C,
    GX2_STAT_PA_SU_PASX_REQ_IDLE                           = 0x204D,
    GX2_STAT_PA_SU_PASX_REQ_BUSY                           = 0x204E,
    GX2_STAT_PA_SU_PASX_REQ_STALLED                        = 0x204F,
    GX2_STAT_PA_SU_PASX_REC_IDLE                           = 0x2050,
    GX2_STAT_PA_SU_PASX_REC_BUSY                           = 0x2051,
    GX2_STAT_PA_SU_PASX_REC_STARVED_SX                     = 0x2052,
    GX2_STAT_PA_SU_PASX_REC_STALLED                        = 0x2053,
    GX2_STAT_PA_SU_PASX_REC_STALLED_POS_MEM                = 0x2054,
    GX2_STAT_PA_SU_PASX_REC_STALLED_CCGSM_IN               = 0x2055,
    GX2_STAT_PA_SU_CCGSM_IDLE                              = 0x2056,
    GX2_STAT_PA_SU_CCGSM_BUSY                              = 0x2057,
    GX2_STAT_PA_SU_CCGSM_STALLED                           = 0x2058,
    GX2_STAT_PA_SU_CLPRIM_IDLE                             = 0x2059,
    GX2_STAT_PA_SU_CLPRIM_BUSY                             = 0x205A,
    GX2_STAT_PA_SU_CLPRIM_STALLED                          = 0x205B,
    GX2_STAT_PA_SU_CLPRIM_STARVED_CCGSM                    = 0x205C,
    GX2_STAT_PA_SU_CLIPSM_IDLE                             = 0x205D,
    GX2_STAT_PA_SU_CLIPSM_BUSY                             = 0x205E,
    GX2_STAT_PA_SU_CLIPSM_WAIT_CLIP_VERT_ENGH              = 0x205F,
    GX2_STAT_PA_SU_CLIPSM_WAIT_HIGH_PRI_SEQ                = 0x2060,
    GX2_STAT_PA_SU_CLIPSM_WAIT_CLIPGA                      = 0x2061,
    GX2_STAT_PA_SU_CLIPSM_WAIT_AVAIL_VTE_CLIP              = 0x2062,
    GX2_STAT_PA_SU_CLIPSM_WAIT_CLIP_OUTSM                  = 0x2063,
    GX2_STAT_PA_SU_CLIPGA_IDLE                             = 0x2064,
    GX2_STAT_PA_SU_CLIPGA_BUSY                             = 0x2065,
    GX2_STAT_PA_SU_CLIPGA_STARVED_VTE_CLIP                 = 0x2066,
    GX2_STAT_PA_SU_CLIPGA_STALLED                          = 0x2067,
    GX2_STAT_PA_SU_CLIP_IDLE                               = 0x2068,
    GX2_STAT_PA_SU_CLIP_BUSY                               = 0x2069,
    GX2_STAT_PA_SU_SU_IDLE                                 = 0x206A,
    GX2_STAT_PA_SU_SU_BUSY                                 = 0x206B,
    GX2_STAT_PA_SU_SU_STARVED_CLIP                         = 0x206C,
    GX2_STAT_PA_SU_SU_STALLED_SC                           = 0x206D,
    GX2_STAT_PA_SU_PA_DYN_SCLK_VLD                         = 0x206E,
    GX2_STAT_PA_SU_PA_REG_SCLK_VLD                         = 0x206F,
    GX2_STAT_PA_SC_SRPS_WINDOW_VALID                       = 0x3000,
    GX2_STAT_PA_SC_PSSW_WINDOW_VALID                       = 0x3001,
    GX2_STAT_PA_SC_TPQZ_WINDOW_VALID                       = 0x3002,
    GX2_STAT_PA_SC_QZQP_WINDOW_VALID                       = 0x3003,
    GX2_STAT_PA_SC_TRPK_WINDOW_VALID                       = 0x3004,
    GX2_STAT_PA_SC_SRPS_WINDOW_VALID_BUSY                  = 0x3005,
    GX2_STAT_PA_SC_PSSW_WINDOW_VALID_BUSY                  = 0x3006,
    GX2_STAT_PA_SC_TPQZ_WINDOW_VALID_BUSY                  = 0x3007,
    GX2_STAT_PA_SC_QZQP_WINDOW_VALID_BUSY                  = 0x3008,
    GX2_STAT_PA_SC_TRPK_WINDOW_VALID_BUSY                  = 0x3009,
    GX2_STAT_PA_SC_STARVED_BY_PA                           = 0x300A,
    GX2_STAT_PA_SC_STALLED_BY_PRIMFIFO                     = 0x300B,
    GX2_STAT_PA_SC_STARVED_BY_DB_TILE                      = 0x300C,
    GX2_STAT_PA_SC_STARVED_BY_DB_QUAD                      = 0x300D,
    GX2_STAT_PA_SC_STALLED_BY_TILEORDERFIFO                = 0x300E,
    GX2_STAT_PA_SC_STALLED_BY_TILEFIFO                     = 0x300F,
    GX2_STAT_PA_SC_STALLED_BY_QUADFIFO                     = 0x3010,
    GX2_STAT_PA_SC_STALLED_BY_DB_TILE                      = 0x3011,
    GX2_STAT_PA_SC_STALLED_BY_DB_QUAD                      = 0x3012,
    GX2_STAT_PA_SC_STALLED_BY_SX                           = 0x3013,
    GX2_STAT_PA_SC_STALLED_BY_SPI                          = 0x3014,
    GX2_STAT_PA_SC_SCISSOR_DISCARD                         = 0x3015,
    GX2_STAT_PA_SC_BB_DISCARD                              = 0x3016,
    GX2_STAT_PA_SC_MULTICHIP_PRIM_DISCARD                  = 0x3017,
    GX2_STAT_PA_SC_SUPERTILE_COUNT                         = 0x3018,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H0                   = 0x3019,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H1                   = 0x301A,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H2                   = 0x301B,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H3                   = 0x301C,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H4                   = 0x301D,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H5                   = 0x301E,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H6                   = 0x301F,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H7                   = 0x3020,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H8                   = 0x3021,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H9                   = 0x3022,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H10                  = 0x3023,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H11                  = 0x3024,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H12                  = 0x3025,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H13                  = 0x3026,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H14                  = 0x3027,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H15                  = 0x3028,
    GX2_STAT_PA_SC_SUPERTILE_PER_PRIM_H16                  = 0x3029,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H0                        = 0x302A,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H1                        = 0x302B,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H2                        = 0x302C,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H3                        = 0x302D,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H4                        = 0x302E,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H5                        = 0x302F,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H6                        = 0x3030,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H7                        = 0x3031,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H8                        = 0x3032,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H9                        = 0x3033,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H10                       = 0x3034,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H11                       = 0x3035,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H12                       = 0x3036,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H13                       = 0x3037,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H14                       = 0x3038,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H15                       = 0x3039,
    GX2_STAT_PA_SC_TILE_PER_PRIM_H16                       = 0x303A,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H0                   = 0x303B,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H1                   = 0x303C,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H2                   = 0x303D,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H3                   = 0x303E,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H4                   = 0x303F,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H5                   = 0x3040,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H6                   = 0x3041,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H7                   = 0x3042,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H8                   = 0x3043,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H9                   = 0x3044,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H10                  = 0x3045,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H11                  = 0x3046,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H12                  = 0x3047,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H13                  = 0x3048,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H14                  = 0x3049,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H15                  = 0x304A,
    GX2_STAT_PA_SC_TILE_PER_SUPERTILE_H16                  = 0x304B,
    GX2_STAT_PA_SC_TILE_PICKED_H1                          = 0x304C,
    GX2_STAT_PA_SC_TILE_PICKED_H2                          = 0x304D,
    GX2_STAT_PA_SC_TILE_PICKED_CONFLICT                    = 0x304E,
    GX2_STAT_PA_SC_QZ0_MULTICHIP_TILE_DISCARD              = 0x304F,
    GX2_STAT_PA_SC_QZ1_MULTICHIP_TILE_DISCARD              = 0x3050,
    GX2_STAT_PA_SC_QZ0_TILE_COUNT                          = 0x3051,
    GX2_STAT_PA_SC_QZ1_TILE_COUNT                          = 0x3052,
    GX2_STAT_PA_SC_QZ0_TILE_COVERED_COUNT                  = 0x3053,
    GX2_STAT_PA_SC_QZ1_TILE_COVERED_COUNT                  = 0x3054,
    GX2_STAT_PA_SC_QZ0_TILE_NOT_COVERED_COUNT              = 0x3055,
    GX2_STAT_PA_SC_QZ1_TILE_NOT_COVERED_COUNT              = 0x3056,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H0                    = 0x3057,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H1                    = 0x3058,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H2                    = 0x3059,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H3                    = 0x305A,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H4                    = 0x305B,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H5                    = 0x305C,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H6                    = 0x305D,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H7                    = 0x305E,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H8                    = 0x305F,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H9                    = 0x3060,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H10                   = 0x3061,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H11                   = 0x3062,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H12                   = 0x3063,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H13                   = 0x3064,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H14                   = 0x3065,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H15                   = 0x3066,
    GX2_STAT_PA_SC_QZ0_QUAD_PER_TILE_H16                   = 0x3067,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H0                    = 0x3068,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H1                    = 0x3069,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H2                    = 0x306A,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H3                    = 0x306B,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H4                    = 0x306C,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H5                    = 0x306D,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H6                    = 0x306E,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H7                    = 0x306F,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H8                    = 0x3070,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H9                    = 0x3071,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H10                   = 0x3072,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H11                   = 0x3073,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H12                   = 0x3074,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H13                   = 0x3075,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H14                   = 0x3076,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H15                   = 0x3077,
    GX2_STAT_PA_SC_QZ1_QUAD_PER_TILE_H16                   = 0x3078,
    GX2_STAT_PA_SC_QZ0_QUAD_COUNT                          = 0x3079,
    GX2_STAT_PA_SC_QZ1_QUAD_COUNT                          = 0x307A,
    GX2_STAT_PA_SC_QUAD0_NOT_PICKED_TB_R6XX                = 0x307B,
    GX2_STAT_PA_SC_QUAD1_NOT_PICKED_TB_R6XX                = 0x307C,
    GX2_STAT_PA_SC_QUAD2_NOT_PICKED_TB_R6XX                = 0x307D,
    GX2_STAT_PA_SC_QUAD3_NOT_PICKED_TB_R6XX                = 0x307E,
    GX2_STAT_PA_SC_P0_HIZ_TILE_COUNT                       = 0x307F,
    GX2_STAT_PA_SC_P1_HIZ_TILE_COUNT                       = 0x3080,
    GX2_STAT_PA_SC_P2_HIZ_TILE_COUNT                       = 0x3081,
    GX2_STAT_PA_SC_P3_HIZ_TILE_COUNT                       = 0x3082,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H0                 = 0x3083,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H1                 = 0x3084,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H2                 = 0x3085,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H3                 = 0x3086,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H4                 = 0x3087,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H5                 = 0x3088,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H6                 = 0x3089,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H7                 = 0x308A,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H8                 = 0x308B,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H9                 = 0x308C,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H10                = 0x308D,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H11                = 0x308E,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H12                = 0x308F,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H13                = 0x3090,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H14                = 0x3091,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H15                = 0x3092,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_PER_TILE_H16                = 0x3093,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H0                 = 0x3094,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H1                 = 0x3095,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H2                 = 0x3096,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H3                 = 0x3097,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H4                 = 0x3098,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H5                 = 0x3099,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H6                 = 0x309A,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H7                 = 0x309B,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H8                 = 0x309C,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H9                 = 0x309D,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H10                = 0x309E,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H11                = 0x309F,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H12                = 0x30A0,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H13                = 0x30A1,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H14                = 0x30A2,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H15                = 0x30A3,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_PER_TILE_H16                = 0x30A4,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H0                 = 0x30A5,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H1                 = 0x30A6,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H2                 = 0x30A7,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H3                 = 0x30A8,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H4                 = 0x30A9,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H5                 = 0x30AA,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H6                 = 0x30AB,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H7                 = 0x30AC,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H8                 = 0x30AD,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H9                 = 0x30AE,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H10                = 0x30AF,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H11                = 0x30B0,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H12                = 0x30B1,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H13                = 0x30B2,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H14                = 0x30B3,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H15                = 0x30B4,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_PER_TILE_H16                = 0x30B5,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H0                 = 0x30B6,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H1                 = 0x30B7,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H2                 = 0x30B8,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H3                 = 0x30B9,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H4                 = 0x30BA,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H5                 = 0x30BB,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H6                 = 0x30BC,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H7                 = 0x30BD,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H8                 = 0x30BE,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H9                 = 0x30BF,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H10                = 0x30C0,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H11                = 0x30C1,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H12                = 0x30C2,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H13                = 0x30C3,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H14                = 0x30C4,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H15                = 0x30C5,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_PER_TILE_H16                = 0x30C6,
    GX2_STAT_PA_SC_P0_HIZ_QUAD_COUNT                       = 0x30C7,
    GX2_STAT_PA_SC_P1_HIZ_QUAD_COUNT                       = 0x30C8,
    GX2_STAT_PA_SC_P2_HIZ_QUAD_COUNT                       = 0x30C9,
    GX2_STAT_PA_SC_P3_HIZ_QUAD_COUNT                       = 0x30CA,
    GX2_STAT_PA_SC_P0_DETAIL_QUAD_COUNT                    = 0x30CB,
    GX2_STAT_PA_SC_P1_DETAIL_QUAD_COUNT                    = 0x30CC,
    GX2_STAT_PA_SC_P2_DETAIL_QUAD_COUNT                    = 0x30CD,
    GX2_STAT_PA_SC_P3_DETAIL_QUAD_COUNT                    = 0x30CE,
    GX2_STAT_PA_SC_P0_DETAIL_QUAD_WITH_1_PIX               = 0x30CF,
    GX2_STAT_PA_SC_P0_DETAIL_QUAD_WITH_2_PIX               = 0x30D0,
    GX2_STAT_PA_SC_P0_DETAIL_QUAD_WITH_3_PIX               = 0x30D1,
    GX2_STAT_PA_SC_P0_DETAIL_QUAD_WITH_4_PIX               = 0x30D2,
    GX2_STAT_PA_SC_P1_DETAIL_QUAD_WITH_1_PIX               = 0x30D3,
    GX2_STAT_PA_SC_P1_DETAIL_QUAD_WITH_2_PIX               = 0x30D4,
    GX2_STAT_PA_SC_P1_DETAIL_QUAD_WITH_3_PIX               = 0x30D5,
    GX2_STAT_PA_SC_P1_DETAIL_QUAD_WITH_4_PIX               = 0x30D6,
    GX2_STAT_PA_SC_P2_DETAIL_QUAD_WITH_1_PIX               = 0x30D7,
    GX2_STAT_PA_SC_P2_DETAIL_QUAD_WITH_2_PIX               = 0x30D8,
    GX2_STAT_PA_SC_P2_DETAIL_QUAD_WITH_3_PIX               = 0x30D9,
    GX2_STAT_PA_SC_P2_DETAIL_QUAD_WITH_4_PIX               = 0x30DA,
    GX2_STAT_PA_SC_P3_DETAIL_QUAD_WITH_1_PIX               = 0x30DB,
    GX2_STAT_PA_SC_P3_DETAIL_QUAD_WITH_2_PIX               = 0x30DC,
    GX2_STAT_PA_SC_P3_DETAIL_QUAD_WITH_3_PIX               = 0x30DD,
    GX2_STAT_PA_SC_P3_DETAIL_QUAD_WITH_4_PIX               = 0x30DE,
    GX2_STAT_PA_SC_EARLYZ_QUAD_COUNT                       = 0x30DF,
    GX2_STAT_PA_SC_EARLYZ_QUAD_WITH_1_PIX                  = 0x30E0,
    GX2_STAT_PA_SC_EARLYZ_QUAD_WITH_2_PIX                  = 0x30E1,
    GX2_STAT_PA_SC_EARLYZ_QUAD_WITH_3_PIX                  = 0x30E2,
    GX2_STAT_PA_SC_EARLYZ_QUAD_WITH_4_PIX                  = 0x30E3,
    GX2_STAT_PA_SC_TILE_REORDER_DB_CONFLICT_R6XX           = 0x30E4,
    GX2_STAT_PA_SC_PKR_QUAD_PER_ROW_H1                     = 0x30E5,
    GX2_STAT_PA_SC_PKR_QUAD_PER_ROW_H2                     = 0x30E6,
    GX2_STAT_PA_SC_PKR_QUAD_PER_ROW_H3                     = 0x30E7,
    GX2_STAT_PA_SC_PKR_QUAD_PER_ROW_H4                     = 0x30E8,
    GX2_STAT_PA_SC_PKR_END_OF_VECTOR                       = 0x30E9,
    GX2_STAT_PA_SC_PKR_CONTROL_XFER                        = 0x30EA,
    GX2_STAT_PA_SC_PKR_DBHANG_FORCE_EOV                    = 0x30EB,
    GX2_STAT_PA_SC_REG_SCLK_BUSY                           = 0x30EC,
    GX2_STAT_PA_SC_GRP0_DYN_SCLK_BUSY                      = 0x30ED,
    GX2_STAT_PA_SC_GRP1_DYN_SCLK_BUSY                      = 0x30EE,
    GX2_STAT_PA_SC_GRP2_DYN_SCLK_BUSY                      = 0x30EF,
    GX2_STAT_PA_SC_GRP3_DYN_SCLK_BUSY                      = 0x30F0,
    GX2_STAT_PA_SC_GRP4_DYN_SCLK_BUSY                      = 0x30F1,
    GX2_STAT_VGT_VGT_SPI_ESTHREAD_EVENT_WINDOW_ACTIVE      = 0x4000,
    GX2_STAT_VGT_VGT_SPI_ESVERT_VALID                      = 0x4001,
    GX2_STAT_VGT_VGT_SPI_ESVERT_EOV                        = 0x4002,
    GX2_STAT_VGT_VGT_SPI_ESVERT_STALLED                    = 0x4003,
    GX2_STAT_VGT_VGT_SPI_ESVERT_STARVED_BUSY               = 0x4004,
    GX2_STAT_VGT_VGT_SPI_ESVERT_STARVED_IDLE               = 0x4005,
    GX2_STAT_VGT_VGT_SPI_ESVERT_STATIC                     = 0x4006,
    GX2_STAT_VGT_VGT_SPI_ESTHREAD_IS_EVENT                 = 0x4007,
    GX2_STAT_VGT_VGT_SPI_ESTHREAD_SEND                     = 0x4008,
    GX2_STAT_VGT_VGT_SPI_GSPRIM_VALID                      = 0x4009,
    GX2_STAT_VGT_VGT_SPI_GSPRIM_EOV                        = 0x400A,
    GX2_STAT_VGT_VGT_SPI_GSPRIM_CONT                       = 0x400B,
    GX2_STAT_VGT_VGT_SPI_GSPRIM_STALLED                    = 0x400C,
    GX2_STAT_VGT_VGT_SPI_GSPRIM_STARVED_BUSY               = 0x400D,
    GX2_STAT_VGT_VGT_SPI_GSPRIM_STARVED_IDLE               = 0x400E,
    GX2_STAT_VGT_VGT_SPI_GSPRIM_STATIC                     = 0x400F,
    GX2_STAT_VGT_VGT_SPI_GSTHREAD_EVENT_WINDOW_ACTIVE      = 0x4010,
    GX2_STAT_VGT_VGT_SPI_GSTHREAD_IS_EVENT                 = 0x4011,
    GX2_STAT_VGT_VGT_SPI_GSTHREAD_SEND                     = 0x4012,
    GX2_STAT_VGT_VGT_SPI_VSTHREAD_EVENT_WINDOW_ACTIVE      = 0x4013,
    GX2_STAT_VGT_VGT_SPI_VSVERT_SEND                       = 0x4014,
    GX2_STAT_VGT_VGT_SPI_VSVERT_EOV                        = 0x4015,
    GX2_STAT_VGT_VGT_SPI_VSVERT_STALLED                    = 0x4016,
    GX2_STAT_VGT_VGT_SPI_VSVERT_STARVED_BUSY               = 0x4017,
    GX2_STAT_VGT_VGT_SPI_VSVERT_STARVED_IDLE               = 0x4018,
    GX2_STAT_VGT_VGT_SPI_VSVERT_STATIC                     = 0x4019,
    GX2_STAT_VGT_VGT_SPI_VSTHREAD_IS_EVENT                 = 0x401A,
    GX2_STAT_VGT_VGT_SPI_VSTHREAD_SEND                     = 0x401B,
    GX2_STAT_VGT_VGT_PA_EVENT_WINDOW_ACTIVE                = 0x401C,
    GX2_STAT_VGT_VGT_PA_CLIPV_SEND                         = 0x401D,
    GX2_STAT_VGT_VGT_PA_CLIPV_FIRSTVERT                    = 0x401E,
    GX2_STAT_VGT_VGT_PA_CLIPV_STALLED                      = 0x401F,
    GX2_STAT_VGT_VGT_PA_CLIPV_STARVED_BUSY                 = 0x4020,
    GX2_STAT_VGT_VGT_PA_CLIPV_STARVED_IDLE                 = 0x4021,
    GX2_STAT_VGT_VGT_PA_CLIPV_STATIC                       = 0x4022,
    GX2_STAT_VGT_VGT_PA_CLIPP_SEND                         = 0x4023,
    GX2_STAT_VGT_VGT_PA_CLIPP_EOP                          = 0x4024,
    GX2_STAT_VGT_VGT_PA_CLIPP_IS_EVENT                     = 0x4025,
    GX2_STAT_VGT_VGT_PA_CLIPP_NULL_PRIM                    = 0x4026,
    GX2_STAT_VGT_VGT_PA_CLIPP_NEW_VTX_VECT                 = 0x4027,
    GX2_STAT_VGT_VGT_PA_CLIPP_STALLED                      = 0x4028,
    GX2_STAT_VGT_VGT_PA_CLIPP_STARVED_BUSY                 = 0x4029,
    GX2_STAT_VGT_VGT_PA_CLIPP_STARVED_IDLE                 = 0x402A,
    GX2_STAT_VGT_VGT_PA_CLIPP_STATIC                       = 0x402B,
    GX2_STAT_VGT_VGT_PA_CLIPS_SEND                         = 0x402C,
    GX2_STAT_VGT_VGT_PA_CLIPS_STALLED                      = 0x402D,
    GX2_STAT_VGT_VGT_PA_CLIPS_STARVED_BUSY                 = 0x402E,
    GX2_STAT_VGT_VGT_PA_CLIPS_STARVED_IDLE                 = 0x402F,
    GX2_STAT_VGT_VGT_PA_CLIPS_STATIC                       = 0x4030,
    GX2_STAT_VGT_RBIU_FIFOS_EVENT_WINDOW_ACTIVE            = 0x4031,
    GX2_STAT_VGT_RBIU_IM_FIFO_STARVED                      = 0x4032,
    GX2_STAT_VGT_RBIU_IM_FIFO_STALLED                      = 0x4033,
    GX2_STAT_VGT_RBIU_DR_FIFO_STARVED                      = 0x4034,
    GX2_STAT_VGT_RBIU_DR_FIFO_STALLED                      = 0x4035,
    GX2_STAT_VGT_RBIU_DI_FIFO_STARVED                      = 0x4036,
    GX2_STAT_VGT_RBIU_DI_FIFO_STALLED                      = 0x4037,
    GX2_STAT_VGT_MC_LAT_BIN_0                              = 0x4038,
    GX2_STAT_VGT_MC_LAT_BIN_1                              = 0x4039,
    GX2_STAT_VGT_MC_LAT_BIN_2                              = 0x403A,
    GX2_STAT_VGT_MC_LAT_BIN_3                              = 0x403B,
    GX2_STAT_VGT_MC_LAT_BIN_4                              = 0x403C,
    GX2_STAT_VGT_MC_LAT_BIN_5                              = 0x403D,
    GX2_STAT_VGT_MC_LAT_BIN_6                              = 0x403E,
    GX2_STAT_VGT_MC_LAT_BIN_7                              = 0x403F,
    GX2_STAT_VGT_VGT_BUSY                                  = 0x4040,
    GX2_STAT_VGT_VGT_GS_BUSY                               = 0x4041,
    GX2_STAT_VGT_ESVERT_STALLED_ES_TBL                     = 0x4042,
    GX2_STAT_VGT_ESVERT_STALLED_GS_TBL                     = 0x4043,
    GX2_STAT_VGT_ESVERT_STALLED_GS_EVENT                   = 0x4044,
    GX2_STAT_VGT_ESVERT_STALLED_GSPRIM                     = 0x4045,
    GX2_STAT_VGT_GSPRIM_STALLED_ES_TBL                     = 0x4046,
    GX2_STAT_VGT_GSPRIM_STALLED_GS_TBL                     = 0x4047,
    GX2_STAT_VGT_GSPRIM_STALLED_GS_EVENT                   = 0x4048,
    GX2_STAT_VGT_GSPRIM_STALLED_ESVERT                     = 0x4049,
    GX2_STAT_VGT_ESTHREAD_STALLED_ES_RB_FULL               = 0x404A,
    GX2_STAT_VGT_ESTHREAD_STALLED_SPI_BP                   = 0x404B,
    GX2_STAT_VGT_COUNTERS_AVAIL_STALLED                    = 0x404C,
    GX2_STAT_VGT_GS_RB_SPACE_AVAIL_STALLED                 = 0x404D,
    GX2_STAT_VGT_GS_ISSUE_RTR_STALLED                      = 0x404E,
    GX2_STAT_VGT_GSTHREAD_STALLED                          = 0x404F,
    GX2_STAT_VGT_ES_CACHE_INVLD_STALLED                    = 0x4050,
    GX2_STAT_VGT_WAIT_FOR_ES_DONE_STALLED                  = 0x4051,
    GX2_STAT_VGT_CM_STALLED_BY_GOG                         = 0x4052,
    GX2_STAT_VGT_CM_READING_STALLED                        = 0x4053,
    GX2_STAT_VGT_CM_STALLED_BY_GSFETCH_DONE                = 0x4054,
    GX2_STAT_VGT_GOG_VS_TBL_STALLED                        = 0x4055,
    GX2_STAT_VGT_GOG_OUT_INDX_STALLED                      = 0x4056,
    GX2_STAT_VGT_GOG_OUT_PRIM_STALLED                      = 0x4057,
    GX2_STAT_VGT_GS_RB_INVLD_STALLED                       = 0x4058,
    GX2_STAT_VGT_GOG_BUSY                                  = 0x4059,
    GX2_STAT_VGT_REUSED_VS_INDICES                         = 0x405A,
    GX2_STAT_VGT_SCLK_REG_VLD_EVENT                        = 0x405B,
    GX2_STAT_VGT_SCLK_INPUT_VLD_EVENT                      = 0x405C,
    GX2_STAT_VGT_SCLK_CORE_VLD_EVENT                       = 0x405D,
    GX2_STAT_VGT_SCLK_INVAL_VLD_EVENT                      = 0x405E,
    GX2_STAT_VGT_SCLK_GS_VLD_EVENT                         = 0x405F,
    GX2_STAT_SQ_NONE                                       = 0x5000,
    GX2_STAT_SQ_CYCLES                                     = 0x5001,
    GX2_STAT_SQ_BUSY_CYCLES                                = 0x5002,
    GX2_STAT_SQ_ANY_BUSY_PER_TYPE                          = 0x5003,
    GX2_STAT_SQ_EVENTS_PER_TYPE                            = 0x5004,
    GX2_STAT_SQ_EVENTS_BUSY_PER_TYPE                       = 0x5005,
    GX2_STAT_SQ_EVENT_LEVEL_PER_TYPE                       = 0x5006,
    GX2_STAT_SQ_ITEMS_PER_TYPE                             = 0x5007,
    GX2_STAT_SQ_ITEMS_GT_48_PER_TYPE                       = 0x5008,
    GX2_STAT_SQ_ITEMS_GT_32_PER_TYPE                       = 0x5009,
    GX2_STAT_SQ_ITEMS_GT_16_PER_TYPE                       = 0x500A,
    GX2_STAT_SQ_QUADS                                      = 0x500B,
    GX2_STAT_SQ_THREADS_BUSY_PER_TYPE                      = 0x500C,
    GX2_STAT_SQ_THREADS_PER_TYPE                           = 0x500D,
    GX2_STAT_SQ_THREAD_LEVEL_PER_TYPE                      = 0x500E,
    GX2_STAT_SQ_THREAD_LEVEL_WAIT_CREATE_PER_TYPE          = 0x500F,
    GX2_STAT_SQ_THREAD_LEVEL_UNALLOC_PARAM_PER_TYPE        = 0x5010,
    GX2_STAT_SQ_THREAD_LEVEL_UNALLOC_PIX_PER_TYPE          = 0x5011,
    GX2_STAT_SQ_THREAD_LEVEL_UNALLOC_POS_PER_TYPE          = 0x5012,
    GX2_STAT_SQ_THREADS_NONPS                              = 0x5013,
    GX2_STAT_SQ_THREAD_LEVEL_NONPS                         = 0x5014,
    GX2_STAT_SQ_THREAD_LEVEL_WAIT_ALLOC_NONPS              = 0x5015,
    GX2_STAT_SQ_THREAD_LEVEL_WAIT_OTHER_NONPS              = 0x5016,
    GX2_STAT_SQ_THREAD_LEVEL_WAIT_ALLOC_PS                 = 0x5017,
    GX2_STAT_SQ_THREAD_LEVEL_WAIT_OTHER_PS                 = 0x5018,
    GX2_STAT_SQ_CF_INST_ISSUES_PER_TYPE                    = 0x5019,
    GX2_STAT_SQ_CF_INST_ISSUE_ONE                          = 0x501A,
    GX2_STAT_SQ_CF_INST_ISSUE_TWO                          = 0x501B,
    GX2_STAT_SQ_CF_INST_ISSUE_IDLE_PER_TYPE                = 0x501C,
    GX2_STAT_SQ_CF_INST_ISSUE_FS_PER_TYPE                  = 0x501D,
    GX2_STAT_SQ_CF_INST_ISSUE_ALU_PER_TYPE                 = 0x501E,
    GX2_STAT_SQ_CF_INST_ISSUE_TF_PER_TYPE                  = 0x501F,
    GX2_STAT_SQ_CF_INST_ISSUE_VF_PER_TYPE                  = 0x5020,
    GX2_STAT_SQ_CF_INST_ISSUE_EX_PER_TYPE                  = 0x5021,
    GX2_STAT_SQ_CF_INST_ISSUE_SMX_WR_PER_TYPE              = 0x5022,
    GX2_STAT_SQ_CF_INST_ISSUE_SMX_RD_PER_TYPE              = 0x5023,
    GX2_STAT_SQ_CF_INST_ISSUE_GF_PER_TYPE                  = 0x5024,
    GX2_STAT_SQ_CF_INST_ISSUE_OTHER_PER_TYPE               = 0x5025,
    GX2_STAT_SQ_CF_INST_ISSUE_ALU_CF_PER_TYPE              = 0x5026,
    GX2_STAT_SQ_CF_INST_ISSUE_BL_PER_TYPE                  = 0x5027,
    GX2_STAT_SQ_CF_INST_REJECT_ALU_PER_TYPE                = 0x5028,
    GX2_STAT_SQ_CF_INST_REJECT_TF_PER_TYPE                 = 0x5029,
    GX2_STAT_SQ_CF_INST_REJECT_VF_PER_TYPE                 = 0x502A,
    GX2_STAT_SQ_CF_INST_REJECT_EX_PER_TYPE                 = 0x502B,
    GX2_STAT_SQ_CF_INST_REJECT_SMX_WR_PER_TYPE             = 0x502C,
    GX2_STAT_SQ_CF_INST_REJECT_SMX_RD_PER_TYPE             = 0x502D,
    GX2_STAT_SQ_CF_INST_REJECT_GF_PER_TYPE                 = 0x502E,
    GX2_STAT_SQ_CF_INST_REJECT_OTHER_PER_TYPE              = 0x502F,
    GX2_STAT_SQ_CF_INST_FIFO_SEND_ALU_PER_TYPE             = 0x5030,
    GX2_STAT_SQ_CF_INST_FIFO_SEND_TF_PER_TYPE              = 0x5031,
    GX2_STAT_SQ_CF_INST_FIFO_SEND_VF_PER_TYPE              = 0x5032,
    GX2_STAT_SQ_CF_INST_FIFO_SEND_EX_PER_TYPE              = 0x5033,
    GX2_STAT_SQ_CF_INST_FIFO_SEND_SMX_WR_PER_TYPE          = 0x5034,
    GX2_STAT_SQ_CF_INST_FIFO_SEND_SMX_RD_PER_TYPE          = 0x5035,
    GX2_STAT_SQ_CF_INST_FIFO_SEND_GF_PER_TYPE              = 0x5036,
    GX2_STAT_SQ_CF_INST_FIFO_SEND_OTHER_PER_TYPE           = 0x5037,
    GX2_STAT_SQ_CF_INST_FIFO_SEND_ALU_KCACHE_NONE_PER_TYPE = 0x5038,
    GX2_STAT_SQ_CF_INST_FIFO_SEND_ALU_KCACHE_ONE_PER_TYPE  = 0x5039,
    GX2_STAT_SQ_CF_INST_FIFO_SEND_ALU_KCACHE_TWO_PER_TYPE  = 0x503A,
    GX2_STAT_SQ_CF_INST_FIFO_SEND_ALU_KCACHE_PER_TYPE      = 0x503B,
    GX2_STAT_SQ_CF_INST_FIFO_FULL_ALU                      = 0x503C,
    GX2_STAT_SQ_CF_INST_FIFO_FULL_TF                       = 0x503D,
    GX2_STAT_SQ_CF_INST_FIFO_FULL_VF                       = 0x503E,
    GX2_STAT_SQ_CF_INST_FIFO_FULL_EX                       = 0x503F,
    GX2_STAT_SQ_CF_INST_FIFO_FULL_SMX                      = 0x5040,
    GX2_STAT_SQ_CF_INST_FIFO_FULL_GF                       = 0x5041,
    GX2_STAT_SQ_CF_INST_FIFO_FULL_OTHER                    = 0x5042,
    GX2_STAT_SQ_CF_INST_FIFO_LEVEL_ALU                     = 0x5043,
    GX2_STAT_SQ_CF_INST_FIFO_LEVEL_TF                      = 0x5044,
    GX2_STAT_SQ_CF_INST_FIFO_LEVEL_VF                      = 0x5045,
    GX2_STAT_SQ_CF_INST_FIFO_LEVEL_EX                      = 0x5046,
    GX2_STAT_SQ_CF_INST_FIFO_LEVEL_SMX                     = 0x5047,
    GX2_STAT_SQ_CF_INST_FIFO_LEVEL_GF                      = 0x5048,
    GX2_STAT_SQ_CF_INST_FIFO_LEVEL_OTHER                   = 0x5049,
    GX2_STAT_SQ_CF_INST_FIFO_EMPTY_ALU                     = 0x504A,
    GX2_STAT_SQ_CF_INST_FIFO_EMPTY_TF                      = 0x504B,
    GX2_STAT_SQ_CF_INST_FIFO_EMPTY_VF                      = 0x504C,
    GX2_STAT_SQ_CF_INST_FIFO_EMPTY_EX                      = 0x504D,
    GX2_STAT_SQ_CF_INST_FIFO_EMPTY_SMX                     = 0x504E,
    GX2_STAT_SQ_CF_INST_FIFO_EMPTY_GF                      = 0x504F,
    GX2_STAT_SQ_CF_INST_FIFO_EMPTY_OTHER                   = 0x5050,
    GX2_STAT_SQ_CF_INST_ISSUE_LEVEL_ALU_PER_TYPE           = 0x5051,
    GX2_STAT_SQ_CF_INST_ISSUE_LEVEL_TF_PER_TYPE            = 0x5052,
    GX2_STAT_SQ_CF_INST_ISSUE_LEVEL_VF_PER_TYPE            = 0x5053,
    GX2_STAT_SQ_CF_INST_ISSUE_LEVEL_EX_PER_TYPE            = 0x5054,
    GX2_STAT_SQ_CF_INST_ISSUE_LEVEL_SMX_WR_PER_TYPE        = 0x5055,
    GX2_STAT_SQ_CF_INST_ISSUE_LEVEL_SMX_RD_PER_TYPE        = 0x5056,
    GX2_STAT_SQ_CF_INST_ISSUE_LEVEL_GF_PER_TYPE            = 0x5057,
    GX2_STAT_SQ_CF_INST_ISSUE_LEVEL_OTHER_PER_TYPE         = 0x5058,
    GX2_STAT_SQ_CF_INST_CHECKPOINT                         = 0x5059,
    GX2_STAT_SQ_CF_INST_CHECKPOINT_BEFORE                  = 0x505A,
    GX2_STAT_SQ_CF_INST_CHECKPOINT_ITEMS_VALID             = 0x505B,
    GX2_STAT_SQ_CF_INST_CHECKPOINT_ITEMS_VALID_NONE        = 0x505C,
    GX2_STAT_SQ_CF_INST_CHECKPOINT_ITEMS_ACTIVE            = 0x505D,
    GX2_STAT_SQ_CF_INST_CHECKPOINT_ITEMS_ACTIVE_NONE       = 0x505E,
    GX2_STAT_SQ_CF_INST_CHECKPOINT_QUADS_ACTIVE            = 0x505F,
    GX2_STAT_SQ_CF_INST_CHECKPOINT_QUADS_VALID             = 0x5060,
    GX2_STAT_SQ_CF_INST_CHECKPOINT_THREADS                 = 0x5061,
    GX2_STAT_SQ_CF_INST_CHECKPOINT_THREAD_LEVEL            = 0x5062,
    GX2_STAT_SQ_CF_INST_FETCH_PER_TYPE                     = 0x5063,
    GX2_STAT_SQ_CF_INST_FETCH_RETURNS_PER_TYPE             = 0x5064,
    GX2_STAT_SQ_CF_INST_FETCH_INSTS_PER_TYPE               = 0x5065,
    GX2_STAT_SQ_CF_INST_FETCH_LEVEL_PER_TYPE               = 0x5066,
    GX2_STAT_SQ_CF_INST_FETCH_EXTRA_PER_TYPE               = 0x5067,
    GX2_STAT_SQ_CF_INST_FETCH_FIFO_SEND                    = 0x5068,
    GX2_STAT_SQ_CF_INST_FETCH_FIFO_LEVEL                   = 0x5069,
    GX2_STAT_SQ_CF_INST_FETCH_FIFO_STALL                   = 0x506A,
    GX2_STAT_SQ_CF_INST_CACHE_FIFO_SEND                    = 0x506B,
    GX2_STAT_SQ_CF_INST_CACHE_FIFO_LEVEL                   = 0x506C,
    GX2_STAT_SQ_CF_INST_CACHE_FIFO_FULL                    = 0x506D,
    GX2_STAT_SQ_CF_INST_ISSUE_DONES                        = 0x506E,
    GX2_STAT_SQ_CF_INST_ISSUE_DONE_LEVEL                   = 0x506F,
    GX2_STAT_SQ_CF_INST_ISSUE_DONE_STALL                   = 0x5070,
    GX2_STAT_SQ_CF_INST_ISSUE_DONE_FIFO_SEND               = 0x5071,
    GX2_STAT_SQ_CF_INST_ISSUE_DONE_FIFO_LEVEL              = 0x5072,
    GX2_STAT_SQ_CF_INST_ALU_UPDATE_FIFO_SEND               = 0x5073,
    GX2_STAT_SQ_CF_INST_ALU_UPDATE_FIFO_LEVEL              = 0x5074,
    GX2_STAT_SQ_CF_INST_ALU_UPDATE_FIFO_STALL              = 0x5075,
    GX2_STAT_SQ_OFIFO_LEVEL_PER_TYPE                       = 0x5076,
    GX2_STAT_SQ_SX_EVENT_FIFO_FULL_PER_TYPE                = 0x5077,
    GX2_STAT_SQ_ALU_CLAUSE_INSTR_GROUPS_PER_TYPE           = 0x5078,
    GX2_STAT_SQ_ALU_CLAUSE_INSTRS_PER_TYPE                 = 0x5079,
    GX2_STAT_SQ_ALU_KWATERFALL_PER_TYPE                    = 0x507A,
    GX2_STAT_SQ_ALU_GPRWATERFALL_PER_TYPE                  = 0x507B,
    GX2_STAT_SQ_ALU_K_INSTR_PER_TYPE                       = 0x507C,
    GX2_STAT_SQ_ALU_ICACHE_BUSY_PER_TYPE                   = 0x507D,
    GX2_STAT_SQ_ALU_KCACHE_BUSY_PER_TYPE                   = 0x507E,
    GX2_STAT_SQ_ALU_MOVA_IDLE_WAIT_PER_TYPE                = 0x507F,
    GX2_STAT_SQ_ALU_LOCK_WAIT                              = 0x5080,
    GX2_STAT_SQ_ALU_ICACHE_READS_PER_TYPE                  = 0x5081,
    GX2_STAT_SQ_ALU_KCACHE_READS_PER_TYPE                  = 0x5082,
    GX2_STAT_SQ_ALU_DONE_FIFO_FULL                         = 0x5083,
    GX2_STAT_SQ_ALU_MOVA_WAIT_PER_TYPE                     = 0x5084,
    GX2_STAT_SQ_ALU_THREADS_IN_FIFO_PER_TYPE               = 0x5085,
    GX2_STAT_SQ_UNUSED_006                                 = 0x5086,
    GX2_STAT_SQ_UNUSED_007                                 = 0x5087,
    GX2_STAT_SQ_TV_ICACHE_WAIT_PER_TYPE                    = 0x5088,
    GX2_STAT_SQ_UNUSED_010                                 = 0x5089,
    GX2_STAT_SQ_UNUSED_001                                 = 0x508A,
    GX2_STAT_SQ_UNUSED_002                                 = 0x508B,
    GX2_STAT_SQ_TF_TA_STALL_PER_TYPE                       = 0x508C,
    GX2_STAT_SQ_VF_VC_INSTR_STALL_PER_TYPE                 = 0x508D,
    GX2_STAT_SQ_VF_VC_INDEX_STALL_PER_TYPE                 = 0x508E,
    GX2_STAT_SQ_UNUSED_003                                 = 0x508F,
    GX2_STAT_SQ_UNUSED_008                                 = 0x5090,
    GX2_STAT_SQ_UNUSED_004                                 = 0x5091,
    GX2_STAT_SQ_UNUSED_009                                 = 0x5092,
    GX2_STAT_SQ_EXPORT_INSTR_PER_TYPE                      = 0x5093,
    GX2_STAT_SQ_EXPORT_IDLE                                = 0x5094,
    GX2_STAT_SQ_EXPORT_SMX_AL_STALL                        = 0x5095,
    GX2_STAT_SQ_EXPORT_PC_AL_STALL                         = 0x5096,
    GX2_STAT_SQ_EXPORT_POS_AL_STALL                        = 0x5097,
    GX2_STAT_SQ_EXPORT_PIX_AL_STALL                        = 0x5098,
    GX2_STAT_SQ_EXPORT_POS_CYCLE                           = 0x5099,
    GX2_STAT_SQ_EXPORT_PIX_CYCLE                           = 0x509A,
    GX2_STAT_SQ_EXPORT_PC_CYCLE                            = 0x509B,
    GX2_STAT_SQ_EXPORT_SMX_CYCLE_PER_TYPE                  = 0x509C,
    GX2_STAT_SQ_CACHE_INVAL_ANY                            = 0x509D,
    GX2_STAT_SQ_CACHE_INVAL_ALL                            = 0x509E,
    GX2_STAT_SQ_CACHE_INVAL_CYCLES                         = 0x509F,
    GX2_STAT_SQ_CF_ICACHE_HITS                             = 0x50A0,
    GX2_STAT_SQ_TF_ICACHE_HITS                             = 0x50A1,
    GX2_STAT_SQ_VF_ICACHE_HITS                             = 0x50A2,
    GX2_STAT_SQ_ALU_ICACHE_HITS                            = 0x50A3,
    GX2_STAT_SQ_ALU_KCACHE_HITS                            = 0x50A4,
    GX2_STAT_SQ_CF_ICACHE_MISSES                           = 0x50A5,
    GX2_STAT_SQ_TF_ICACHE_MISSES                           = 0x50A6,
    GX2_STAT_SQ_VF_ICACHE_MISSES                           = 0x50A7,
    GX2_STAT_SQ_ALU_ICACHE_MISSES                          = 0x50A8,
    GX2_STAT_SQ_ALU_KCACHE_MISSES                          = 0x50A9,
    GX2_STAT_SQ_CF_ICACHE_DUP_MISSES                       = 0x50AA,
    GX2_STAT_SQ_TF_ICACHE_DUP_MISSES                       = 0x50AB,
    GX2_STAT_SQ_VF_ICACHE_DUP_MISSES                       = 0x50AC,
    GX2_STAT_SQ_ALU_ICACHE_DUP_MISSES                      = 0x50AD,
    GX2_STAT_SQ_ALU_KCACHE_DUP_MISSES                      = 0x50AE,
    GX2_STAT_SQ_CF_ICACHE_ACCESSES                         = 0x50AF,
    GX2_STAT_SQ_TF_ICACHE_ACCESSES                         = 0x50B0,
    GX2_STAT_SQ_VF_ICACHE_ACCESSES                         = 0x50B1,
    GX2_STAT_SQ_ALU_ICACHE_ACCESSES                        = 0x50B2,
    GX2_STAT_SQ_ALU_KCACHE_ACCESSES                        = 0x50B3,
    GX2_STAT_SQ_CF_ICACHE_INPUT_FIFO_ENTRIES               = 0x50B4,
    GX2_STAT_SQ_TF_ICACHE_INPUT_FIFO_ENTRIES               = 0x50B5,
    GX2_STAT_SQ_VF_ICACHE_INPUT_FIFO_ENTRIES               = 0x50B6,
    GX2_STAT_SQ_ALU_ICACHE_INPUT_FIFO_ENTRIES              = 0x50B7,
    GX2_STAT_SQ_ALU_KCACHE_INPUT_FIFO_ENTRIES              = 0x50B8,
    GX2_STAT_SQ_CF_ICACHE_MISS_MEM_STALL                   = 0x50B9,
    GX2_STAT_SQ_TF_ICACHE_MISS_MEM_STALL                   = 0x50BA,
    GX2_STAT_SQ_VF_ICACHE_MISS_MEM_STALL                   = 0x50BB,
    GX2_STAT_SQ_ALU_ICACHE_MISS_MEM_STALL                  = 0x50BC,
    GX2_STAT_SQ_ALU_KCACHE_MISS_MEM_STALL                  = 0x50BD,
    GX2_STAT_SQ_CF_ICACHE_MISS_FIFO_STALL                  = 0x50BE,
    GX2_STAT_SQ_TF_ICACHE_MISS_FIFO_STALL                  = 0x50BF,
    GX2_STAT_SQ_VF_ICACHE_MISS_FIFO_STALL                  = 0x50C0,
    GX2_STAT_SQ_ALU_ICACHE_MISS_FIFO_STALL                 = 0x50C1,
    GX2_STAT_SQ_ALU_KCACHE_MISS_FIFO_STALL                 = 0x50C2,
    GX2_STAT_SQ_CF_ICACHE_HIT_STALL                        = 0x50C3,
    GX2_STAT_SQ_CF_ICACHE_MISS_LOCKED_STALL                = 0x50C4,
    GX2_STAT_SQ_TF_ICACHE_MISS_LOCKED_STALL                = 0x50C5,
    GX2_STAT_SQ_VF_ICACHE_MISS_LOCKED_STALL                = 0x50C6,
    GX2_STAT_SQ_ALU_ICACHE_MISS_LOCKED_STALL               = 0x50C7,
    GX2_STAT_SQ_ALU_KCACHE_MISS_LOCKED_STALL               = 0x50C8,
    GX2_STAT_SQ_CF_ICACHE_LOCKED_TAGS                      = 0x50C9,
    GX2_STAT_SQ_TF_ICACHE_LOCKED_TAGS                      = 0x50CA,
    GX2_STAT_SQ_VF_ICACHE_LOCKED_TAGS                      = 0x50CB,
    GX2_STAT_SQ_ALU_ICACHE_LOCKED_TAGS                     = 0x50CC,
    GX2_STAT_SQ_ALU_KCACHE_LOCKED_TAGS                     = 0x50CD,
    GX2_STAT_SQ_CF_ICACHE_MISS_LOCKED_TAGS                 = 0x50CE,
    GX2_STAT_SQ_TF_ICACHE_MISS_LOCKED_TAGS                 = 0x50CF,
    GX2_STAT_SQ_VF_ICACHE_MISS_LOCKED_TAGS                 = 0x50D0,
    GX2_STAT_SQ_ALU_ICACHE_MISS_LOCKED_TAGS                = 0x50D1,
    GX2_STAT_SQ_ALU_KCACHE_MISS_LOCKED_TAGS                = 0x50D2,
    GX2_STAT_SQ_CACHE_MEM_REQUESTS                         = 0x50D3,
    GX2_STAT_SQ_CF_ICACHE_MEM_REQUESTS                     = 0x50D4,
    GX2_STAT_SQ_TV_ICACHE_MEM_REQUESTS                     = 0x50D5,
    GX2_STAT_SQ_ALU_ICACHE_MEM_REQUESTS                    = 0x50D6,
    GX2_STAT_SQ_ALU_KCACHE_MEM_REQUESTS                    = 0x50D7,
    GX2_STAT_SQ_CF_ICACHE_RD_WR_COLLISION                  = 0x50D8,
    GX2_STAT_SQ_CF_ICACHE_MISS_HIT_RD_COLLISION            = 0x50D9,
    GX2_STAT_SQ_CF_ICACHE_MEM_REQUESTS_IN_FLIGHT           = 0x50DA,
    GX2_STAT_SQ_TV_ICACHE_MEM_REQUESTS_IN_FLIGHT           = 0x50DB,
    GX2_STAT_SQ_ALU_ICACHE_MEM_REQUESTS_IN_FLIGHT          = 0x50DC,
    GX2_STAT_SQ_ALU_KCACHE_MEM_REQUESTS_IN_FLIGHT          = 0x50DD,
    GX2_STAT_SQ_CF_ICACHE_MISS_FIFO_MISSES                 = 0x50DE,
    GX2_STAT_SQ_TF_ICACHE_MISS_FIFO_MISSES                 = 0x50DF,
    GX2_STAT_SQ_VF_ICACHE_MISS_FIFO_MISSES                 = 0x50E0,
    GX2_STAT_SQ_ALU_ICACHE_MISS_FIFO_MISSES                = 0x50E1,
    GX2_STAT_SQ_ALU_KCACHE_MISS_FIFO_MISSES                = 0x50E2,
    GX2_STAT_SQ_CACHE_MEM_REQUESTS_IN_FLIGHT               = 0x50E3,
    GX2_STAT_SQ_CACHE_MEM_STALL                            = 0x50E4,
    GX2_STAT_SQ_TM_TS64_STALL                              = 0x50E5,
    GX2_STAT_SQ_TM_ALU_CONST_STALL                         = 0x50E6,
    GX2_STAT_SQ_TM_LOOP_CONST_STALL                        = 0x50E7,
    GX2_STAT_SQ_TM_TEX_BASE_CONST_STALL                    = 0x50E8,
    GX2_STAT_SQ_TM_TEX_SAMPLER_STALL                       = 0x50E9,
    GX2_STAT_SQ_TM_TEX_RESOURCE_STALL                      = 0x50EA,
    GX2_STAT_SQ_UNUSED_005                                 = 0x50EB,
    GX2_STAT_SQ_TA_TEX_INSTRS_PER_TYPE                     = 0x50EC,
    GX2_STAT_SQ_TA_VTX_INSTRS_PER_TYPE                     = 0x50ED,
    GX2_STAT_SQ_VC_INSTRS_PER_TYPE                         = 0x50EE,
    GX2_STAT_SQ_TV_LOCK_WAIT                               = 0x50EF,
    GX2_STAT_SQ_TA_SRC_C                                   = 0x50F0,
    GX2_STAT_SQ_VC_SRC_C                                   = 0x50F1,
    GX2_STAT_SQ_TV_KILLED_FETCH_PER_TYPE                   = 0x50F2,
    GX2_STAT_SQ_TV_NULL_FETCH_PER_TYPE                     = 0x50F3,
    GX2_STAT_SQ_TV_THREADS_IN_FIFO_PER_TYPE                = 0x50F4,
    GX2_STAT_SQ_EXPORT_SPQ_LEVEL                           = 0x50F5,
    GX2_STAT_SQ_EXPORT_SPQ_STALL                           = 0x50F6,
    GX2_STAT_SPI_VS_WINDOW_VALID                           = 0x6000,
    GX2_STAT_SPI_VS_BUSY                                   = 0x6001,
    GX2_STAT_SPI_VS_INPUT_STARVED                          = 0x6002,
    GX2_STAT_SPI_VS_VSR_STALL                              = 0x6003,
    GX2_STAT_SPI_VS_VSR_FULL                               = 0x6004,
    GX2_STAT_SPI_VS_GPR_STALL                              = 0x6005,
    GX2_STAT_SPI_VS_INPUT_STALL                            = 0x6006,
    GX2_STAT_SPI_VS_MEM_STALL                              = 0x6007,
    GX2_STAT_SPI_VS_TB_FULL                                = 0x6008,
    GX2_STAT_SPI_VS_EV_FIFO_FULL                           = 0x6009,
    GX2_STAT_SPI_VS_THREAD_STALL                           = 0x600A,
    GX2_STAT_SPI_VS_EVENT_VECTOR                           = 0x600B,
    GX2_STAT_SPI_VS_VECTOR                                 = 0x600C,
    GX2_STAT_SPI_GS_WINDOW_VALID                           = 0x600D,
    GX2_STAT_SPI_GS_BUSY                                   = 0x600E,
    GX2_STAT_SPI_GS_INPUT_STARVED                          = 0x600F,
    GX2_STAT_SPI_GS_GSR_STALL                              = 0x6010,
    GX2_STAT_SPI_GS_GSR_FULL                               = 0x6011,
    GX2_STAT_SPI_GS_GPR_STALL                              = 0x6012,
    GX2_STAT_SPI_GS_INPUT_STALL                            = 0x6013,
    GX2_STAT_SPI_GS_MEM_STALL                              = 0x6014,
    GX2_STAT_SPI_GS_TB_FULL                                = 0x6015,
    GX2_STAT_SPI_GS_EV_FIFO_FULL                           = 0x6016,
    GX2_STAT_SPI_GS_THREAD_STALL                           = 0x6017,
    GX2_STAT_SPI_GS_EVENT_VECTOR                           = 0x6018,
    GX2_STAT_SPI_GS_VECTOR                                 = 0x6019,
    GX2_STAT_SPI_ES_WINDOW_VALID                           = 0x601A,
    GX2_STAT_SPI_ES_BUSY                                   = 0x601B,
    GX2_STAT_SPI_ES_INPUT_STARVED                          = 0x601C,
    GX2_STAT_SPI_ES_ESR_STALL                              = 0x601D,
    GX2_STAT_SPI_ES_ESR_FULL                               = 0x601E,
    GX2_STAT_SPI_ES_GPR_STALL                              = 0x601F,
    GX2_STAT_SPI_ES_INPUT_STALL                            = 0x6020,
    GX2_STAT_SPI_ES_MEM_STALL                              = 0x6021,
    GX2_STAT_SPI_ES_TB_FULL                                = 0x6022,
    GX2_STAT_SPI_ES_EV_FIFO_FULL                           = 0x6023,
    GX2_STAT_SPI_ES_THREAD_STALL                           = 0x6024,
    GX2_STAT_SPI_ES_EVENT_VECTOR                           = 0x6025,
    GX2_STAT_SPI_ES_VECTOR                                 = 0x6026,
    GX2_STAT_SPI_ITER_CTRL_WINDOW_VALID                    = 0x6027,
    GX2_STAT_SPI_ITER_CTRL_ACTIVE                          = 0x6028,
    GX2_STAT_SPI_ITER_CTRL_FULL                            = 0x6029,
    GX2_STAT_SPI_ITER_CTRL_STALL_PV                        = 0x602A,
    GX2_STAT_SPI_ITER_CTRL_STALL_EV                        = 0x602B,
    GX2_STAT_SPI_ITER_STARVED                              = 0x602C,
    GX2_STAT_SPI_ITER_ACTIVE                               = 0x602D,
    GX2_STAT_SPI_ITER_FULL                                 = 0x602E,
    GX2_STAT_SPI_ITER_STALL                                = 0x602F,
    GX2_STAT_SPI_PTR_BUFF_WINDOW_VALID                     = 0x6030,
    GX2_STAT_SPI_PTR_BUFF_BUSY                             = 0x6031,
    GX2_STAT_SPI_PTR_BUFF_ACTIVE                           = 0x6032,
    GX2_STAT_SPI_PTR_BUFF_STALL                            = 0x6033,
    GX2_STAT_SPI_PTR_BUFF_GPR_STALL                        = 0x6034,
    GX2_STAT_SPI_PTR_BUFF_MEM_STALL                        = 0x6035,
    GX2_STAT_SPI_PTR_BUFF_IJ_STALL                         = 0x6036,
    GX2_STAT_SPI_PTR_BUFF_CTL_STALL                        = 0x6037,
    GX2_STAT_SPI_PTR_BUFF_EVENT_VECTOR                     = 0x6038,
    GX2_STAT_SPI_PTR_BUFF_VECTOR                           = 0x6039,
    GX2_STAT_SPI_PTR_BUFF_2_PASS_VEC                       = 0x603A,
    GX2_STAT_SPI_PTR_BUFF_3_PASS_VEC                       = 0x603B,
    GX2_STAT_SPI_PTR_BUFF_4_PASS_VEC                       = 0x603C,
    GX2_STAT_SPI_PCTL0_INPUT_STALL                         = 0x603D,
    GX2_STAT_SPI_PCTL0_PI_PPB_STALL                        = 0x603E,
    GX2_STAT_SPI_PCTL0_THREAD_STALL                        = 0x603F,
    GX2_STAT_SPI_PCTL0_PI_BUSY                             = 0x6040,
    GX2_STAT_SPI_PCTL0_SX_VALID                            = 0x6041,
    GX2_STAT_SPI_PCTL1_INPUT_STALL                         = 0x6042,
    GX2_STAT_SPI_PCTL1_PI_PPB_STALL                        = 0x6043,
    GX2_STAT_SPI_PCTL1_THREAD_STALL                        = 0x6044,
    GX2_STAT_SPI_PCTL1_PI_BUSY                             = 0x6045,
    GX2_STAT_SPI_PCTL1_SX_VALID                            = 0x6046,
    GX2_STAT_SPI_PS_TB_FULL                                = 0x6047,
    GX2_STAT_SPI_PS_EV_FIFO_FULL                           = 0x6048,
    GX2_STAT_SPI_THREAD_CONFLICT                           = 0x6049,
    GX2_STAT_SPI_VS_STK_STALL                              = 0x604A,
    GX2_STAT_SPI_VS_TMP_STALL                              = 0x604B,
    GX2_STAT_SPI_GS_STK_STALL                              = 0x604C,
    GX2_STAT_SPI_GS_TMP_STALL                              = 0x604D,
    GX2_STAT_SPI_ES_STK_STALL                              = 0x604E,
    GX2_STAT_SPI_ES_TMP_STALL                              = 0x604F,
    GX2_STAT_SPI_PS_STK_STALL                              = 0x6050,
    GX2_STAT_SPI_PS_TMP_STALL                              = 0x6051,
    GX2_STAT_SPI_PS_FBUF_STALL                             = 0x6052,
    GX2_STAT_SPI_PTR_BUFF_FPOS                             = 0x6053,
    GX2_STAT_SPI_PTR_BUFF_DEALLOC                          = 0x6054,
    GX2_STAT_SPI_PTR_BUFF_0_CONFLICT_VEC                   = 0x6055,
    GX2_STAT_SPI_PTR_BUFF_1_CONFLICT_VEC                   = 0x6056,
    GX2_STAT_SPI_PTR_BUFF_2_CONFLICT_VEC                   = 0x6057,
    GX2_STAT_SPI_PTR_BUFF_3_CONFLICT_VEC                   = 0x6058,
    GX2_STAT_SPI_PTR_BUFF_4_CONFLICT_VEC                   = 0x6059,
    GX2_STAT_SPI_PTR_BUFF_5_CONFLICT_VEC                   = 0x605A,
    GX2_STAT_SPI_DYN_GPR_PS_SKIP_SIMD                      = 0x605B,
    GX2_STAT_SPI_DYN_GPR_VS_SKIP_SIMD                      = 0x605C,
    GX2_STAT_SPI_DYN_GPR_GS_SKIP_SIMD                      = 0x605D,
    GX2_STAT_SPI_DYN_GPR_ES_SKIP_SIMD                      = 0x605E,
    GX2_STAT_SPI_DYN_GPR_PS_WRAP_SOONER                    = 0x605F,
    GX2_STAT_SPI_DYN_GPR_VS_WRAP_SOONER                    = 0x6060,
    GX2_STAT_SPI_DYN_GPR_GS_WRAP_SOONER                    = 0x6061,
    GX2_STAT_SPI_DYN_GPR_ES_WRAP_SOONER                    = 0x6062,
    GX2_STAT_SPI_CLKGATE_BUSY_STALL                        = 0x6063,
    GX2_STAT_SPI_CLKGATE_ACTIVE_STALL                      = 0x6064,
    GX2_STAT_SPI_CLKGATE_ALL_CLOCKS_ON                     = 0x6065,
    GX2_STAT_SPI_CLKGATE_SPI_CLOCKS_ON                     = 0x6066,
    GX2_STAT_SX_GS_FLUSH_EVENT_IN                          = 0x7000,
    GX2_STAT_SX_ES_FLUSH_EVENT_IN                          = 0x7001,
    GX2_STAT_SX_TS_EVENT_IN                                = 0x7002,
    GX2_STAT_SX_CONTEXT_EVENT_IN                           = 0x7003,
    GX2_STAT_SX_GS_FLUSH_EVENT_OUT                         = 0x7004,
    GX2_STAT_SX_ES_FLUSH_EVENT_OUT                         = 0x7005,
    GX2_STAT_SX_TS_EVENT_OUT                               = 0x7006,
    GX2_STAT_SX_CONTEXT_EVENT_OUT                          = 0x7007,
    GX2_STAT_SX_DB0_IDLE_CYCLES                            = 0x7008,
    GX2_STAT_SX_DB0_STALL_CYCLES                           = 0x7009,
    GX2_STAT_SX_DB0_HALF_QUADS                             = 0x700A,
    GX2_STAT_SX_DB0_PIXELS                                 = 0x700B,
    GX2_STAT_SX_DB0_PRED_PIXELS                            = 0x700C,
    GX2_STAT_SX_DB1_IDLE_CYCLES                            = 0x700D,
    GX2_STAT_SX_DB1_STALL_CYCLES                           = 0x700E,
    GX2_STAT_SX_DB1_HALF_QUADS                             = 0x700F,
    GX2_STAT_SX_DB1_PIXELS                                 = 0x7010,
    GX2_STAT_SX_DB1_PRED_PIXELS                            = 0x7011,
    GX2_STAT_SX_DB2_IDLE_CYCLES                            = 0x7012,
    GX2_STAT_SX_DB2_STALL_CYCLES                           = 0x7013,
    GX2_STAT_SX_DB2_HALF_QUADS                             = 0x7014,
    GX2_STAT_SX_DB2_PIXELS                                 = 0x7015,
    GX2_STAT_SX_DB2_PRED_PIXELS                            = 0x7016,
    GX2_STAT_SX_DB3_IDLE_CYCLES                            = 0x7017,
    GX2_STAT_SX_DB3_STALL_CYCLES                           = 0x7018,
    GX2_STAT_SX_DB3_HALF_QUADS                             = 0x7019,
    GX2_STAT_SX_DB3_PIXELS                                 = 0x701A,
    GX2_STAT_SX_DB3_PRED_PIXELS                            = 0x701B,
    GX2_STAT_SX_DB4_IDLE_CYCLES                            = 0x701C,
    GX2_STAT_SX_DB4_STALL_CYCLES                           = 0x701D,
    GX2_STAT_SX_DB4_HALF_QUADS                             = 0x701E,
    GX2_STAT_SX_DB4_PIXELS                                 = 0x701F,
    GX2_STAT_SX_DB4_PRED_PIXELS                            = 0x7020,
    GX2_STAT_SX_DB5_IDLE_CYCLES                            = 0x7021,
    GX2_STAT_SX_DB5_STALL_CYCLES                           = 0x7022,
    GX2_STAT_SX_DB5_HALF_QUADS                             = 0x7023,
    GX2_STAT_SX_DB5_PIXELS                                 = 0x7024,
    GX2_STAT_SX_DB5_PRED_PIXELS                            = 0x7025,
    GX2_STAT_SX_DB6_IDLE_CYCLES                            = 0x7026,
    GX2_STAT_SX_DB6_STALL_CYCLES                           = 0x7027,
    GX2_STAT_SX_DB6_HALF_QUADS                             = 0x7028,
    GX2_STAT_SX_DB6_PIXELS                                 = 0x7029,
    GX2_STAT_SX_DB6_PRED_PIXELS                            = 0x702A,
    GX2_STAT_SX_DB7_IDLE_CYCLES                            = 0x702B,
    GX2_STAT_SX_DB7_STALL_CYCLES                           = 0x702C,
    GX2_STAT_SX_DB7_HALF_QUADS                             = 0x702D,
    GX2_STAT_SX_DB7_PIXELS                                 = 0x702E,
    GX2_STAT_SX_DB7_PRED_PIXELS                            = 0x702F,
    GX2_STAT_SX_PA_IDLE_CYCLES                             = 0x7030,
    GX2_STAT_SX_PA_REQ                                     = 0x7031,
    GX2_STAT_SX_PA_POS                                     = 0x7032,
    GX2_STAT_SX_SPI_REQ_0                                  = 0x7033,
    GX2_STAT_SX_SPI_REQ_1                                  = 0x7034,
    GX2_STAT_SX_CLOCK_PS                                   = 0x7035,
    GX2_STAT_SX_CLOCK_VS                                   = 0x7036,
    GX2_STAT_SX_CLOCK_GS                                   = 0x7037,
    GX2_STAT_SX_CLOCK_ES                                   = 0x7038,
    GX2_STAT_SX_CLOCK                                      = 0x7039,
    GX2_STAT_SX_DB0_ACK_REQUEST                            = 0x703A,
    GX2_STAT_SX_DB1_ACK_REQUEST                            = 0x703B,
    GX2_STAT_SX_DB2_ACK_REQUEST                            = 0x703C,
    GX2_STAT_SX_DB3_ACK_REQUEST                            = 0x703D,
    GX2_STAT_SX_DB4_ACK_REQUEST                            = 0x703E,
    GX2_STAT_SX_DB5_ACK_REQUEST                            = 0x703F,
    GX2_STAT_SX_DB6_ACK_REQUEST                            = 0x7040,
    GX2_STAT_SX_DB7_ACK_REQUEST                            = 0x7041,
    GX2_STAT_SX_SC_CLOCK                                   = 0x7042,
    GX2_STAT_SX_PS_ADJUSTED_CLOCK                          = 0x7043,
    GX2_STAT_SX_DB0_ALPHA_KILLED_PIXELS                    = 0x7044,
    GX2_STAT_SX_DB1_ALPHA_KILLED_PIXELS                    = 0x7045,
    GX2_STAT_SX_DB2_ALPHA_KILLED_PIXELS                    = 0x7046,
    GX2_STAT_SX_DB3_ALPHA_KILLED_PIXELS                    = 0x7047,
    GX2_STAT_SX_GATE_EN1                                   = 0x7048,
    GX2_STAT_SX_GATE_EN2                                   = 0x7049,
    GX2_STAT_SX_GATE_EN3                                   = 0x704A,
    GX2_STAT_SX_GATE_EN4                                   = 0x704B,
    GX2_STAT_SX_GATE_EN5                                   = 0x704C,
    GX2_STAT_SX_PIX_CLK_VALID                              = 0x704D,
    GX2_STAT_SX_SC_CLK_VALID                               = 0x704E,
    GX2_STAT_SX_PA_CLK_VALID                               = 0x704F,
    GX2_STAT_SX_REG_CLK_VALID                              = 0x7050,
    GX2_STAT_SX_SMX_CLK_VALID                              = 0x7051,
    GX2_STAT_SX_ARB_QP0_COLLISION                          = 0x7052,
    GX2_STAT_SX_ARB_QP1_COLLISION                          = 0x7053,
    GX2_STAT_SX_ARB_QP2_COLLISION                          = 0x7054,
    GX2_STAT_SX_ARB_QP3_COLLISION                          = 0x7055,
    GX2_STAT_SMX_CACHE_IDLE_CYCLES                         = 0x8000,
    GX2_STAT_SMX_CACHE_STALL_CYCLES                        = 0x8001,
    GX2_STAT_SMX_WRITE_REQS                                = 0x8002,
    GX2_STAT_SMX_WRITE_REQS_PS                             = 0x8003,
    GX2_STAT_SMX_WRITE_REQS_VS                             = 0x8004,
    GX2_STAT_SMX_WRITE_REQS_GS                             = 0x8005,
    GX2_STAT_SMX_WRITE_REQS_ES                             = 0x8006,
    GX2_STAT_SMX_WRITE_REQS_STREAM0                        = 0x8007,
    GX2_STAT_SMX_WRITE_REQS_STREAM1                        = 0x8008,
    GX2_STAT_SMX_WRITE_REQS_STREAM2                        = 0x8009,
    GX2_STAT_SMX_WRITE_REQS_STREAM3                        = 0x800A,
    GX2_STAT_SMX_WRITE_REQS_SCRATCH                        = 0x800B,
    GX2_STAT_SMX_WRITE_REQS_REDUCTION                      = 0x800C,
    GX2_STAT_SMX_WRITE_REQS_RING                           = 0x800D,
    GX2_STAT_SMX_WRITE_REQS_FBUFFER                        = 0x800E,
    GX2_STAT_SMX_WRITE_REQS_SCATTER                        = 0x800F,
    GX2_STAT_SMX_VF_STALL                                  = 0x8010,
    GX2_STAT_SMX0_NUMBER_OF_PARTIAL_LINES                  = 0x8011,
    GX2_STAT_SMX0_NUMBER_OF_ES_FLUSH                       = 0x8012,
    GX2_STAT_SMX0_NUMBER_OF_GS_FLUSH                       = 0x8013,
    GX2_STAT_SMX0_NUMBER_OF_SYNC_FLUSH                     = 0x8014,
    GX2_STAT_SMX0_NUMBER_OF_ACK_FLUSH                      = 0x8015,
    GX2_STAT_SMX0_NUMBER_OF_FLUSH                          = 0x8016,
    GX2_STAT_SMX0_DW_WRITTEN                               = 0x8017,
    GX2_STAT_SMX0_DW_MISS                                  = 0x8018,
    GX2_STAT_SMX0_DB_STALL                                 = 0x8019,
    GX2_STAT_SMX1_NUMBER_OF_PARTIAL_LINES                  = 0x801A,
    GX2_STAT_SMX1_NUMBER_OF_ES_FLUSH                       = 0x801B,
    GX2_STAT_SMX1_NUMBER_OF_GS_FLUSH                       = 0x801C,
    GX2_STAT_SMX1_NUMBER_OF_SYNC_FLUSH                     = 0x801D,
    GX2_STAT_SMX1_NUMBER_OF_ACK_FLUSH                      = 0x801E,
    GX2_STAT_SMX1_NUMBER_OF_FLUSH                          = 0x801F,
    GX2_STAT_SMX1_DW_WRITTEN                               = 0x8020,
    GX2_STAT_SMX1_DW_MISS                                  = 0x8021,
    GX2_STAT_SMX1_DB_STALL                                 = 0x8022,
    GX2_STAT_SMX2_NUMBER_OF_PARTIAL_LINES                  = 0x8023,
    GX2_STAT_SMX2_NUMBER_OF_ES_FLUSH                       = 0x8024,
    GX2_STAT_SMX2_NUMBER_OF_GS_FLUSH                       = 0x8025,
    GX2_STAT_SMX2_NUMBER_OF_SYNC_FLUSH                     = 0x8026,
    GX2_STAT_SMX2_NUMBER_OF_ACK_FLUSH                      = 0x8027,
    GX2_STAT_SMX2_NUMBER_OF_FLUSH                          = 0x8028,
    GX2_STAT_SMX2_DW_WRITTEN                               = 0x8029,
    GX2_STAT_SMX2_DW_MISS                                  = 0x802A,
    GX2_STAT_SMX2_DB_STALL                                 = 0x802B,
    GX2_STAT_SMX3_NUMBER_OF_PARTIAL_LINES                  = 0x802C,
    GX2_STAT_SMX3_NUMBER_OF_ES_FLUSH                       = 0x802D,
    GX2_STAT_SMX3_NUMBER_OF_GS_FLUSH                       = 0x802E,
    GX2_STAT_SMX3_NUMBER_OF_SYNC_FLUSH                     = 0x802F,
    GX2_STAT_SMX3_NUMBER_OF_ACK_FLUSH                      = 0x8030,
    GX2_STAT_SMX3_NUMBER_OF_FLUSH                          = 0x8031,
    GX2_STAT_SMX3_DW_WRITTEN                               = 0x8032,
    GX2_STAT_SMX3_DW_MISS                                  = 0x8033,
    GX2_STAT_SMX3_DB_STALL                                 = 0x8034,
    GX2_STAT_SMX0_SET0_CNT                                 = 0x8035,
    GX2_STAT_SMX0_SET1_CNT                                 = 0x8036,
    GX2_STAT_SMX0_SET2_CNT                                 = 0x8037,
    GX2_STAT_SMX0_SET3_CNT                                 = 0x8038,
    GX2_STAT_SMX0_SET4_CNT                                 = 0x8039,
    GX2_STAT_SMX0_SET5_CNT                                 = 0x803A,
    GX2_STAT_SMX0_SET6_CNT                                 = 0x803B,
    GX2_STAT_SMX0_SET7_CNT                                 = 0x803C,
    GX2_STAT_SMX1_SET0_CNT                                 = 0x803D,
    GX2_STAT_SMX1_SET1_CNT                                 = 0x803E,
    GX2_STAT_SMX1_SET2_CNT                                 = 0x803F,
    GX2_STAT_SMX1_SET3_CNT                                 = 0x8040,
    GX2_STAT_SMX1_SET4_CNT                                 = 0x8041,
    GX2_STAT_SMX1_SET5_CNT                                 = 0x8042,
    GX2_STAT_SMX1_SET6_CNT                                 = 0x8043,
    GX2_STAT_SMX1_SET7_CNT                                 = 0x8044,
    GX2_STAT_SMX2_SET0_CNT                                 = 0x8045,
    GX2_STAT_SMX2_SET1_CNT                                 = 0x8046,
    GX2_STAT_SMX2_SET2_CNT                                 = 0x8047,
    GX2_STAT_SMX2_SET3_CNT                                 = 0x8048,
    GX2_STAT_SMX2_SET4_CNT                                 = 0x8049,
    GX2_STAT_SMX2_SET5_CNT                                 = 0x804A,
    GX2_STAT_SMX2_SET6_CNT                                 = 0x804B,
    GX2_STAT_SMX2_SET7_CNT                                 = 0x804C,
    GX2_STAT_SMX3_SET0_CNT                                 = 0x804D,
    GX2_STAT_SMX3_SET1_CNT                                 = 0x804E,
    GX2_STAT_SMX3_SET2_CNT                                 = 0x804F,
    GX2_STAT_SMX3_SET3_CNT                                 = 0x8050,
    GX2_STAT_SMX3_SET4_CNT                                 = 0x8051,
    GX2_STAT_SMX3_SET5_CNT                                 = 0x8052,
    GX2_STAT_SMX3_SET6_CNT                                 = 0x8053,
    GX2_STAT_SMX3_SET7_CNT                                 = 0x8054,
    GX2_STAT_SMX0_PROBE_COLLISION                          = 0x8055,
    GX2_STAT_SMX1_PROBE_COLLISION                          = 0x8056,
    GX2_STAT_SMX2_PROBE_COLLISION                          = 0x8057,
    GX2_STAT_SMX3_PROBE_COLLISION                          = 0x8058,
    GX2_STAT_TD_TD_BUSY                                    = 0x9000,
    GX2_STAT_TD_INPUT_BUSY                                 = 0x9008,
    GX2_STAT_TD_OUTPUT_BUSY                                = 0x9009,
    GX2_STAT_TD_SAMPLE_LATENCY_FIFO_BUSY                   = 0x900A,
    GX2_STAT_TD_CONSTANT_LATENCY_FIFO_BUSY                 = 0x900B,
    GX2_STAT_TD_FASTPATH_BUSY                              = 0x900C,
    GX2_STAT_TD_SH_FIFO_BUSY                               = 0x900D,
    GX2_STAT_TD_PHASE_SYNC_BUSY                            = 0x900E,
    GX2_STAT_TD_DATAOUT_FIFO_BUSY                          = 0x900F,
    GX2_STAT_TD_LATENCY_FIFO_BUSY_PIPE_IDLE                = 0x9010,
    GX2_STAT_TD_SYNC_PHASE_COUNT                           = 0x9011,
    GX2_STAT_TD_VC_DATA_RETURN                             = 0x9012,
    GX2_STAT_TD_STALL_DUE_TO_VC                            = 0x9013,
    GX2_STAT_TD_STALL_DUE_TO_RSP                           = 0x9014,
    GX2_STAT_TD_STALL_DUE_TO_VC_OR_RSP                     = 0x9015,
    GX2_STAT_TD_TD_REG_SCLK_VLD                            = 0x9016,
    GX2_STAT_TD_TD_LOCAL_CG_DYN_SCLK_GRP0_EN               = 0x9017,
    GX2_STAT_TD_TD_LOCAL_CG_DYN_SCLK_GRP1_EN               = 0x9018,
    GX2_STAT_TA_TA_BUSY                                    = 0xA000,
    GX2_STAT_TA_GRADIENT_BUSY                              = 0xA001,
    GX2_STAT_TA_GRADIENT_FIFO_BUSY                         = 0xA002,
    GX2_STAT_TA_LOD_BUSY                                   = 0xA003,
    GX2_STAT_TA_LOD_FIFO_BUSY                              = 0xA004,
    GX2_STAT_TA_ADDRESSER_BUSY                             = 0xA005,
    GX2_STAT_TA_ADDRESSER_FIFO_BUSY                        = 0xA006,
    GX2_STAT_TA_ALIGNER_BUSY                               = 0xA007,
    GX2_STAT_TA_PIX_0_QUAD                                 = 0xA008,
    GX2_STAT_TA_PIX_1_QUAD                                 = 0xA009,
    GX2_STAT_TA_PIX_2_QUAD                                 = 0xA00A,
    GX2_STAT_TA_PIX_3_QUAD                                 = 0xA00B,
    GX2_STAT_TA_PIX_4_QUAD                                 = 0xA00C,
    GX2_STAT_TA_INPUT_CYCLES                               = 0xA010,
    GX2_STAT_TA_GRADIENT_BALANCING_CYCLES                  = 0xA011,
    GX2_STAT_TA_GRADIENT_CYCLES                            = 0xA012,
    GX2_STAT_TA_WALKER_BALANCING_CYCLES                    = 0xA013,
    GX2_STAT_TA_WALKER_CYCLES                              = 0xA014,
    GX2_STAT_TA_ALIGNER_BALANCING_CYCLES                   = 0xA015,
    GX2_STAT_TA_ALIGNER_CYCLES                             = 0xA016,
    GX2_STAT_TA_MIP_1_CYCLE_PIXELS                         = 0xA018,
    GX2_STAT_TA_MIP_2_CYCLE_PIXELS                         = 0xA019,
    GX2_STAT_TA_VOL_1_CYCLE_PIXELS                         = 0xA01A,
    GX2_STAT_TA_VOL_2_CYCLE_PIXELS                         = 0xA01B,
    GX2_STAT_TA_BILIN_POINT_1_CYCLE_PIXELS                 = 0xA01C,
    GX2_STAT_TA_BICUBIC_4_CYCLE_PIXELS                     = 0xA01D,
    GX2_STAT_TA_MIPMAP_LOD_0_SAMPLES                       = 0xA020,
    GX2_STAT_TA_MIPMAP_LOD_1_SAMPLES                       = 0xA021,
    GX2_STAT_TA_MIPMAP_LOD_2_SAMPLES                       = 0xA022,
    GX2_STAT_TA_MIPMAP_LOD_3_SAMPLES                       = 0xA023,
    GX2_STAT_TA_MIPMAP_LOD_4_SAMPLES                       = 0xA024,
    GX2_STAT_TA_MIPMAP_LOD_5_SAMPLES                       = 0xA025,
    GX2_STAT_TA_MIPMAP_LOD_6_SAMPLES                       = 0xA026,
    GX2_STAT_TA_MIPMAP_LOD_7_SAMPLES                       = 0xA027,
    GX2_STAT_TA_MIPMAP_LOD_8_SAMPLES                       = 0xA028,
    GX2_STAT_TA_MIPMAP_LOD_9_SAMPLES                       = 0xA029,
    GX2_STAT_TA_MIPMAP_LOD_10_SAMPLES                      = 0xA02A,
    GX2_STAT_TA_MIPMAP_LOD_11_SAMPLES                      = 0xA02B,
    GX2_STAT_TA_MIPMAP_LOD_12_SAMPLES                      = 0xA02C,
    GX2_STAT_TA_MIPMAP_LOD_13_SAMPLES                      = 0xA02D,
    GX2_STAT_TA_MIPMAP_LOD_14_SAMPLES                      = 0xA02E,
    GX2_STAT_TA_ANISO_1_1_QUADS                            = 0xA030,
    GX2_STAT_TA_ANISO_2_1_QUADS                            = 0xA031,
    GX2_STAT_TA_ANISO_3_1_QUADS                            = 0xA032,
    GX2_STAT_TA_ANISO_4_1_QUADS                            = 0xA033,
    GX2_STAT_TA_ANISO_5_1_QUADS                            = 0xA034,
    GX2_STAT_TA_ANISO_6_1_QUADS                            = 0xA035,
    GX2_STAT_TA_ANISO_7_1_QUADS                            = 0xA036,
    GX2_STAT_TA_ANISO_8_1_QUADS                            = 0xA037,
    GX2_STAT_TA_ANISO_9_1_QUADS                            = 0xA038,
    GX2_STAT_TA_ANISO_10_1_QUADS                           = 0xA039,
    GX2_STAT_TA_ANISO_11_1_QUADS                           = 0xA03A,
    GX2_STAT_TA_ANISO_12_1_QUADS                           = 0xA03B,
    GX2_STAT_TA_ANISO_13_1_QUADS                           = 0xA03C,
    GX2_STAT_TA_ANISO_14_1_QUADS                           = 0xA03D,
    GX2_STAT_TA_ANISO_15_1_QUADS                           = 0xA03E,
    GX2_STAT_TA_ANISO_16_1_QUADS                           = 0xA03F,
    GX2_STAT_TA_TA_REG_SCLK_VLD                            = 0xA040,
    GX2_STAT_TA_TA_LOCAL_CG_DYN_SCLK_GRP0_EN               = 0xA041,
    GX2_STAT_TA_TA_LOCAL_CG_DYN_SCLK_GRP1_EN               = 0xA042,
    GX2_STAT_TA_TA_LOCAL_CG_DYN_SCLK_GRP1_MEMS_EN          = 0xA043,
    GX2_STAT_TCP_TA_TCP_STARVE_CYCLES                      = 0xB000,
    GX2_STAT_TCP_TCP_TA_STALL_CYCLES                       = 0xB001,
    GX2_STAT_TCP_TD_TCP_STALL_CYCLES                       = 0xB002,
    GX2_STAT_TCP_TCC_TCP_STALL_CYCLES                      = 0xB003,
    GX2_STAT_TCP_TCC0_TCP_STALL_CYCLES                     = 0xB004,
    GX2_STAT_TCP_TCC1_TCP_STALL_CYCLES                     = 0xB005,
    GX2_STAT_TCP_TCC2_TCP_STALL_CYCLES                     = 0xB006,
    GX2_STAT_TCP_TCC3_TCP_STALL_CYCLES                     = 0xB007,
    GX2_STAT_TCP_TCC4_TCP_STALL_CYCLES                     = 0xB008,
    GX2_STAT_TCP_TCC5_TCP_STALL_CYCLES                     = 0xB009,
    GX2_STAT_TCP_TCC6_TCP_STALL_CYCLES                     = 0xB00A,
    GX2_STAT_TCP_TCC7_TCP_STALL_CYCLES                     = 0xB00B,
    GX2_STAT_TCP_TCP_LOD_STALL_CYCLES                      = 0xB00C,
    GX2_STAT_TCP_TCP_TAGCONFLICT_STALL_CYCLES              = 0xB00D,
    GX2_STAT_TCP_TCP_ALLOC_STALL_CYCLES                    = 0xB00E,
    GX2_STAT_TCP_TCP_LFIFO_STALL_CYCLES                    = 0xB00F,
    GX2_STAT_TCP_TCP_RFIFO_STALL_CYCLES                    = 0xB010,
    GX2_STAT_TCP_TCP_FFIFO_STALL_CYCLES                    = 0xB011,
    GX2_STAT_TCP_TCP_CFIFO_STALL_CYCLES                    = 0xB012,
    GX2_STAT_TCP_TCP_READCONFLICT_STALL_CYCLES             = 0xB013,
    GX2_STAT_TCP_TCP_PENDING_STALL_CYCLES                  = 0xB014,
    GX2_STAT_TCP_TCP_READFIFO_STALL_CYCLES                 = 0xB015,
    GX2_STAT_TCP_TCP_LATENCY                               = 0xB016,
    GX2_STAT_TCP_TCC_REQ_LATENCY                           = 0xB017,
    GX2_STAT_TCP_TCC0_REQ_LATENCY                          = 0xB018,
    GX2_STAT_TCP_TCC1_REQ_LATENCY                          = 0xB019,
    GX2_STAT_TCP_TCC2_REQ_LATENCY                          = 0xB01A,
    GX2_STAT_TCP_TCC3_REQ_LATENCY                          = 0xB01B,
    GX2_STAT_TCP_TCC4_REQ_LATENCY                          = 0xB01C,
    GX2_STAT_TCP_TCC5_REQ_LATENCY                          = 0xB01D,
    GX2_STAT_TCP_TCC6_REQ_LATENCY                          = 0xB01E,
    GX2_STAT_TCP_TCC7_REQ_LATENCY                          = 0xB01F,
    GX2_STAT_TCP_TCC_FREE_LATENCY                          = 0xB020,
    GX2_STAT_TCP_TCC0_FREE_LATENCY                         = 0xB021,
    GX2_STAT_TCP_TCC1_FREE_LATENCY                         = 0xB022,
    GX2_STAT_TCP_TCC2_FREE_LATENCY                         = 0xB023,
    GX2_STAT_TCP_TCC3_FREE_LATENCY                         = 0xB024,
    GX2_STAT_TCP_TCC4_FREE_LATENCY                         = 0xB025,
    GX2_STAT_TCP_TCC5_FREE_LATENCY                         = 0xB026,
    GX2_STAT_TCP_TCC6_FREE_LATENCY                         = 0xB027,
    GX2_STAT_TCP_TCC7_FREE_LATENCY                         = 0xB028,
    GX2_STAT_TCP_TCP_TCC_REQ                               = 0xB029,
    GX2_STAT_TCP_TCP_TCC0_REQ                              = 0xB02A,
    GX2_STAT_TCP_TCP_TCC1_REQ                              = 0xB02B,
    GX2_STAT_TCP_TCP_TCC2_REQ                              = 0xB02C,
    GX2_STAT_TCP_TCP_TCC3_REQ                              = 0xB02D,
    GX2_STAT_TCP_TCP_TCC4_REQ                              = 0xB02E,
    GX2_STAT_TCP_TCP_TCC5_REQ                              = 0xB02F,
    GX2_STAT_TCP_TCP_TCC6_REQ                              = 0xB030,
    GX2_STAT_TCP_TCP_TCC7_REQ                              = 0xB031,
    GX2_STAT_TCP_TCC_TCP_RDRET                             = 0xB032,
    GX2_STAT_TCP_TCC0_TCP_RDRET                            = 0xB033,
    GX2_STAT_TCP_TCC1_TCP_RDRET                            = 0xB034,
    GX2_STAT_TCP_TCC2_TCP_RDRET                            = 0xB035,
    GX2_STAT_TCP_TCC3_TCP_RDRET                            = 0xB036,
    GX2_STAT_TCP_TCC4_TCP_RDRET                            = 0xB037,
    GX2_STAT_TCP_TCC5_TCP_RDRET                            = 0xB038,
    GX2_STAT_TCP_TCC6_TCP_RDRET                            = 0xB039,
    GX2_STAT_TCP_TCC7_TCP_RDRET                            = 0xB03A,
    GX2_STAT_TCP_TOTAL_PIXELS                              = 0xB03B,
    GX2_STAT_TCP_UNCACHED_PIXELS                           = 0xB03C,
    GX2_STAT_TCP_FMT_1_PIXELS                              = 0xB03D,
    GX2_STAT_TCP_FMT_8_PIXELS                              = 0xB03E,
    GX2_STAT_TCP_FMT_16_PIXELS                             = 0xB03F,
    GX2_STAT_TCP_FMT_32_PIXELS                             = 0xB040,
    GX2_STAT_TCP_FMT_32_AS_8_PIXELS                        = 0xB041,
    GX2_STAT_TCP_FMT_32_AS_16_PIXELS                       = 0xB042,
    GX2_STAT_TCP_FMT_64_2_CYCLE_PIXELS                     = 0xB043,
    GX2_STAT_TCP_FMT_64_1_CYCLE_PIXELS                     = 0xB044,
    GX2_STAT_TCP_FMT_96_PIXELS                             = 0xB045,
    GX2_STAT_TCP_FMT_128_4_CYCLE_PIXELS                    = 0xB046,
    GX2_STAT_TCP_FMT_128_1_CYCLE_PIXELS                    = 0xB047,
    GX2_STAT_TCP_FMT_BC1_PIXELS                            = 0xB048,
    GX2_STAT_TCP_FMT_BC2_PIXELS                            = 0xB049,
    GX2_STAT_TCP_FMT_BC3_PIXELS                            = 0xB04A,
    GX2_STAT_TCP_FMT_BC4_PIXELS                            = 0xB04B,
    GX2_STAT_TCP_FMT_BC5_PIXELS                            = 0xB04C,
    GX2_STAT_TCP_FMT_I8_PIXELS                             = 0xB04D,
    GX2_STAT_TCP_FMT_I16_PIXELS                            = 0xB04E,
    GX2_STAT_TCP_FMT_I32_PIXELS                            = 0xB04F,
    GX2_STAT_TCP_FMT_I32_AS_8_PIXELS                       = 0xB050,
    GX2_STAT_TCP_FMT_I32_AS_16_PIXELS                      = 0xB051,
    GX2_STAT_TCP_FMT_D16_PIXELS                            = 0xB052,
    GX2_STAT_TCP_FMT_D32_PIXELS                            = 0xB053,
    GX2_STAT_TCP_FMT_V8_PIXELS                             = 0xB054,
    GX2_STAT_TCP_FMT_V16_PIXELS                            = 0xB055,
    GX2_STAT_TCP_FMT_V32_PIXELS                            = 0xB056,
    GX2_STAT_TCP_FMT_V64_2_CYCLE_PIXELS                    = 0xB057,
    GX2_STAT_TCP_FMT_V64_1_CYCLE_PIXELS                    = 0xB058,
    GX2_STAT_TCP_FMT_V128_4_CYCLE_PIXELS                   = 0xB059,
    GX2_STAT_TCP_FMT_V128_2_CYCLE_PIXELS                   = 0xB05A,
    GX2_STAT_TCP_FMT_V128_1_CYCLE_PIXELS                   = 0xB05B,
    GX2_STAT_TCP_ARR_LINEAR_GENERAL_PIXELS                 = 0xB05C,
    GX2_STAT_TCP_ARR_LINEAR_ALIGNED_PIXELS                 = 0xB05D,
    GX2_STAT_TCP_ARR_1D_THIN1_PIXELS                       = 0xB05E,
    GX2_STAT_TCP_ARR_1D_THICK_PIXELS                       = 0xB05F,
    GX2_STAT_TCP_ARR_2D_THIN1_PIXELS                       = 0xB060,
    GX2_STAT_TCP_ARR_2D_THIN2_PIXELS                       = 0xB061,
    GX2_STAT_TCP_ARR_2D_THIN4_PIXELS                       = 0xB062,
    GX2_STAT_TCP_ARR_2D_THICK_PIXELS                       = 0xB063,
    GX2_STAT_TCP_ARR_2B_THIN1_PIXELS                       = 0xB064,
    GX2_STAT_TCP_ARR_2B_THIN2_PIXELS                       = 0xB065,
    GX2_STAT_TCP_ARR_2B_THIN4_PIXELS                       = 0xB066,
    GX2_STAT_TCP_ARR_2B_THICK_PIXELS                       = 0xB067,
    GX2_STAT_TCP_ARR_3D_THIN1_PIXELS                       = 0xB068,
    GX2_STAT_TCP_ARR_3D_THICK_PIXELS                       = 0xB069,
    GX2_STAT_TCP_ARR_3B_THIN1_PIXELS                       = 0xB06A,
    GX2_STAT_TCP_ARR_3B_THICK_PIXELS                       = 0xB06B,
    GX2_STAT_TCP_DIM_1D_PIXELS                             = 0xB06C,
    GX2_STAT_TCP_DIM_2D_PIXELS                             = 0xB06D,
    GX2_STAT_TCP_DIM_3D_PIXELS                             = 0xB06E,
    GX2_STAT_TCP_DIM_CUBE_PIXELS                           = 0xB06F,
    GX2_STAT_TCP_DIM_1D_ARRAY_PIXELS                       = 0xB070,
    GX2_STAT_TCP_DIM_2D_ARRAY_PIXELS                       = 0xB071,
    GX2_STAT_TCP_DIM_2D_MSAA_PIXELS                        = 0xB072,
    GX2_STAT_TCP_DIM_2D_ARRAY_MSAA_PIXELS                  = 0xB073,
    GX2_STAT_TCP_DIM_CUBE_ARRAY_PIXELS                     = 0xB074,
    GX2_STAT_TCP_VGT_TCP_INVALIDATE                        = 0xB075,
    GX2_STAT_TCP_TA_TCP_STATE_READ                         = 0xB076,
    GX2_STAT_TCP_TCP_TAGRAM0_REQ                           = 0xB077,
    GX2_STAT_TCP_TCP_TAGRAM1_REQ                           = 0xB078,
    GX2_STAT_TCP_TCP_TAGRAM2_REQ                           = 0xB079,
    GX2_STAT_TCP_TCP_TAGRAM3_REQ                           = 0xB07A,
    GX2_STAT_TCP_TCP_GATE_EN1                              = 0xB07B,
    GX2_STAT_TCP_TCP_GATE_EN2                              = 0xB07C,
    GX2_STAT_TCP_TCP_CORE_REG_SCLK_VLD                     = 0xB07D,
    GX2_STAT_TCP_FMT_V96_PIXELS                            = 0xB07E,
    GX2_STAT_TCC_NONE                                      = 0xC000,
    GX2_STAT_TCC_CYCLES                                    = 0xC001,
    GX2_STAT_TCC_BUSY                                      = 0xC002,
    GX2_STAT_TCC_BUSY_TC_TF                                = 0xC003,
    GX2_STAT_TCC_BUSY_TC_VF                                = 0xC004,
    GX2_STAT_TCC_BUSY_VC_VF                                = 0xC005,
    GX2_STAT_TCC_REQS                                      = 0xC006,
    GX2_STAT_TCC_REQS_HIT                                  = 0xC007,
    GX2_STAT_TCC_REQS_MISS                                 = 0xC008,
    GX2_STAT_TCC_REQS_UNCACHED                             = 0xC009,
    GX2_STAT_TCC_REQS_CLIENT_0                             = 0xC00A,
    GX2_STAT_TCC_REQS_CLIENT_1                             = 0xC00B,
    GX2_STAT_TCC_REQS_CLIENT_2                             = 0xC00C,
    GX2_STAT_TCC_REQS_CLIENT_3                             = 0xC00D,
    GX2_STAT_TCC_REQS_CLIENT_4                             = 0xC00E,
    GX2_STAT_TCC_REQS_CLIENT_5                             = 0xC00F,
    GX2_STAT_TCC_REQS_CLIENT_6                             = 0xC010,
    GX2_STAT_TCC_REQS_CLIENT_7                             = 0xC011,
    GX2_STAT_TCC_REQS_CLIENT_8                             = 0xC012,
    GX2_STAT_TCC_REQS_CLIENT_9                             = 0xC013,
    GX2_STAT_TCC_REQS_CLIENT_10                            = 0xC014,
    GX2_STAT_TCC_REQS_CLIENT_11                            = 0xC015,
    GX2_STAT_TCC_REQS_CLIENT_12                            = 0xC016,
    GX2_STAT_TCC_REQS_CLIENT_13                            = 0xC017,
    GX2_STAT_TCC_REQS_CLIENT_14                            = 0xC018,
    GX2_STAT_TCC_REQS_CLIENT_15                            = 0xC019,
    GX2_STAT_TCC_REQS_CLIENT_16                            = 0xC01A,
    GX2_STAT_TCC_REQS_CLIENT_17                            = 0xC01B,
    GX2_STAT_TCC_REQS_CLIENT_18                            = 0xC01C,
    GX2_STAT_TCC_REQS_CLIENT_19                            = 0xC01D,
    GX2_STAT_TCC_REQS_CLIENT_20                            = 0xC01E,
    GX2_STAT_TCC_REQS_CLIENT_21                            = 0xC01F,
    GX2_STAT_TCC_REQS_CLIENT_22                            = 0xC020,
    GX2_STAT_TCC_REQS_CLIENT_23                            = 0xC021,
    GX2_STAT_TCC_REQS_TC_TF                                = 0xC022,
    GX2_STAT_TCC_REQS_TC_TF_HIT                            = 0xC023,
    GX2_STAT_TCC_REQS_TC_TF_MISS                           = 0xC024,
    GX2_STAT_TCC_REQS_TC_VF                                = 0xC025,
    GX2_STAT_TCC_REQS_TC_VF_HIT                            = 0xC026,
    GX2_STAT_TCC_REQS_TC_VF_MISS                           = 0xC027,
    GX2_STAT_TCC_REQS_VC_VF                                = 0xC028,
    GX2_STAT_TCC_REQS_VC_VF_HIT                            = 0xC029,
    GX2_STAT_TCC_REQS_VC_VF_MISS                           = 0xC02A,
    GX2_STAT_TCC_REQ_LEVEL_TC_TF                           = 0xC02B,
    GX2_STAT_TCC_REQ_LEVEL_TC_VF                           = 0xC02C,
    GX2_STAT_TCC_REQ_LEVEL_VC_VF                           = 0xC02D,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_0                        = 0xC02E,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_1                        = 0xC02F,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_2                        = 0xC030,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_3                        = 0xC031,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_4                        = 0xC032,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_5                        = 0xC033,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_6                        = 0xC034,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_7                        = 0xC035,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_8                        = 0xC036,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_9                        = 0xC037,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_10                       = 0xC038,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_11                       = 0xC039,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_12                       = 0xC03A,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_13                       = 0xC03B,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_14                       = 0xC03C,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_15                       = 0xC03D,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_16                       = 0xC03E,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_17                       = 0xC03F,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_18                       = 0xC040,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_19                       = 0xC041,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_20                       = 0xC042,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_21                       = 0xC043,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_22                       = 0xC044,
    GX2_STAT_TCC_REQ_LEVEL_CLIENT_23                       = 0xC045,
    GX2_STAT_TCC_MC_REQS                                   = 0xC046,
    GX2_STAT_TCC_MC_REQS_TC_TF                             = 0xC047,
    GX2_STAT_TCC_MC_REQS_TC_VF                             = 0xC048,
    GX2_STAT_TCC_MC_REQS_VC_VF                             = 0xC049,
    GX2_STAT_TCC_MC_FULL                                   = 0xC04A,
    GX2_STAT_TCC_MC_REQ_LEVEL                              = 0xC04B,
    GX2_STAT_TCC_MC_REQ_LEVEL_TC_TF                        = 0xC04C,
    GX2_STAT_TCC_MC_REQ_LEVEL_TC_VF                        = 0xC04D,
    GX2_STAT_TCC_MC_REQ_LEVEL_VC_VF                        = 0xC04E,
    GX2_STAT_TCC_MC_CREDIT_LEVEL                           = 0xC04F,
    GX2_STAT_TCC_CG_CORE_ENABLED                           = 0xC050,
    GX2_STAT_TCC_CG_BLOCK_ENABLED                          = 0xC051,
    GX2_STAT_TCC_LF_FULL                                   = 0xC052,
    GX2_STAT_TCC_LF_FULL_VC                                = 0xC053,
    GX2_STAT_TCC_LF_FULL_TC                                = 0xC054,
    GX2_STAT_TCC_LF_FULL_CLIENT_VC                         = 0xC055,
    GX2_STAT_TCC_LF_FULL_CLIENT_TC                         = 0xC056,
    GX2_STAT_TCC_LF_LEVEL                                  = 0xC057,
    GX2_STAT_TCC_LF_LEVEL_VC_VF                            = 0xC058,
    GX2_STAT_TCC_LF_LEVEL_TC_VF                            = 0xC059,
    GX2_STAT_TCC_LF_LEVEL_TC_TF                            = 0xC05A,
    GX2_STAT_TCC_LF_BLOCK_LEVEL                            = 0xC05B,
    GX2_STAT_TCC_LF_BLOCK_LEVEL_VC                         = 0xC05C,
    GX2_STAT_TCC_LF_BLOCK_LEVEL_TC                         = 0xC05D,
    GX2_STAT_TCC_OF_LEVEL                                  = 0xC05E,
    GX2_STAT_TCC_OF_LEVEL_VC_VF                            = 0xC05F,
    GX2_STAT_TCC_OF_LEVEL_TC_VF                            = 0xC060,
    GX2_STAT_TCC_OF_LEVEL_TC_TF                            = 0xC061,
    GX2_STAT_TCC_TCA_LEVEL                                 = 0xC062,
    GX2_STAT_TCC_TCA_LEVEL_VC_VF                           = 0xC063,
    GX2_STAT_TCC_TCA_LEVEL_TC_VF                           = 0xC064,
    GX2_STAT_TCC_TCA_LEVEL_TC_TF                           = 0xC065,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_0                        = 0xC066,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_1                        = 0xC067,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_2                        = 0xC068,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_3                        = 0xC069,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_4                        = 0xC06A,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_5                        = 0xC06B,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_6                        = 0xC06C,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_7                        = 0xC06D,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_8                        = 0xC06E,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_9                        = 0xC06F,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_10                       = 0xC070,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_11                       = 0xC071,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_12                       = 0xC072,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_13                       = 0xC073,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_14                       = 0xC074,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_15                       = 0xC075,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_16                       = 0xC076,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_17                       = 0xC077,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_18                       = 0xC078,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_19                       = 0xC079,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_20                       = 0xC07A,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_21                       = 0xC07B,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_22                       = 0xC07C,
    GX2_STAT_TCC_TCA_LEVEL_CLIENT_23                       = 0xC07D,
    GX2_STAT_TCC_CLIENTS_FULL                              = 0xC07E,
    GX2_STAT_TCC_CLIENTS_FULL_VC                           = 0xC07F,
    GX2_STAT_TCC_CLIENTS_FULL_TC                           = 0xC080,
    GX2_STAT_TCC_ARB_BURST                                 = 0xC081,
    GX2_STAT_TCC_ARB_BURST_VC                              = 0xC082,
    GX2_STAT_TCC_ARB_BURST_TC                              = 0xC083,
    GX2_STAT_TCC_CACHE_TAG_STALL_TC_TF                     = 0xC084,
    GX2_STAT_TCC_CACHE_TAG_RENAME_TC_TF                    = 0xC085,
    GX2_STAT_TCC_CACHE_TAG_STALL_TC_VF                     = 0xC086,
    GX2_STAT_TCC_CACHE_TAG_RENAME_TC_VF                    = 0xC087,
    GX2_STAT_TCC_CACHE_TAG_STALL_VC_VF                     = 0xC088,
    GX2_STAT_TCC_CACHE_TAG_RENAME_VC_VF                    = 0xC089,
    GX2_STAT_TCC_CACHE_STALL                               = 0xC08A,
    GX2_STAT_TCC_DEALLOC                                   = 0xC08B,
    GX2_STAT_TCC_DEALLOC_ALL                               = 0xC08C,
    GX2_STAT_TCC_DEALLOC_LINES                             = 0xC08D,
    GX2_STAT_TCC_DEALLOC_CYCLES                            = 0xC08E,
    GX2_STAT_TCC_REG_WRITES                                = 0xC08F,
    GX2_STAT_TCC_REG_READS                                 = 0xC090,
    GX2_STAT_TCC_DEBUG_BUS                                 = 0xC091,
    GX2_STAT_TCC_DUMMY_LAST                                = 0xC092,
    GX2_STAT_CB_BUSY                                       = 0xD000,
    GX2_STAT_CB_DB_CB_TILE_VALID_READY                     = 0xD001,
    GX2_STAT_CB_DB_CB_TILE_VALID_READYB                    = 0xD002,
    GX2_STAT_CB_DB_CB_TILE_VALIDB_READY                    = 0xD003,
    GX2_STAT_CB_DB_CB_TILE_VALIDB_READYB                   = 0xD004,
    GX2_STAT_CB_DB_CB_LQUAD_VALID_READY                    = 0xD005,
    GX2_STAT_CB_DB_CB_LQUAD_VALID_READYB                   = 0xD006,
    GX2_STAT_CB_DB_CB_LQUAD_VALIDB_READY                   = 0xD007,
    GX2_STAT_CB_DB_CB_LQUAD_VALIDB_READYB                  = 0xD008,
    GX2_STAT_CB_CB_TAP_WRREQ_VALID_READY                   = 0xD009,
    GX2_STAT_CB_CB_TAP_WRREQ_VALID_READYB                  = 0xD00A,
    GX2_STAT_CB_CB_TAP_WRREQ_VALIDB_READY                  = 0xD00B,
    GX2_STAT_CB_CB_TAP_WRREQ_VALIDB_READYB                 = 0xD00C,
    GX2_STAT_CB_CB_TAP_RDREQ_VALID_READY                   = 0xD00D,
    GX2_STAT_CB_CB_TAP_RDREQ_VALID_READYB                  = 0xD00E,
    GX2_STAT_CB_CB_TAP_RDREQ_VALIDB_READY                  = 0xD00F,
    GX2_STAT_CB_CB_TAP_RDREQ_VALIDB_READYB                 = 0xD010,
    GX2_STAT_CB_CM_FC_TILE_VALID_READY                     = 0xD011,
    GX2_STAT_CB_CM_FC_TILE_VALID_READYB                    = 0xD012,
    GX2_STAT_CB_CM_FC_TILE_VALIDB_READY                    = 0xD013,
    GX2_STAT_CB_CM_FC_TILE_VALIDB_READYB                   = 0xD014,
    GX2_STAT_CB_FC_CC_QUADFRAG_VALID_READY                 = 0xD015,
    GX2_STAT_CB_FC_CC_QUADFRAG_VALID_READYB                = 0xD016,
    GX2_STAT_CB_FC_CC_QUADFRAG_VALIDB_READY                = 0xD017,
    GX2_STAT_CB_FC_CC_QUADFRAG_VALIDB_READYB               = 0xD018,
    GX2_STAT_CB_FOP_IN_VALID_READY                         = 0xD019,
    GX2_STAT_CB_FOP_IN_VALID_READYB                        = 0xD01A,
    GX2_STAT_CB_FOP_IN_VALIDB_READY                        = 0xD01B,
    GX2_STAT_CB_FOP_IN_VALIDB_READYB                       = 0xD01C,
    GX2_STAT_CB_CC_IB_TB_FRAG_VALID_READY                  = 0xD01D,
    GX2_STAT_CB_CC_IB_TB_FRAG_VALID_READYB                 = 0xD01E,
    GX2_STAT_CB_CC_IB_TB_FRAG_VALIDB_READY                 = 0xD01F,
    GX2_STAT_CB_CC_IB_TB_FRAG_VALIDB_READYB                = 0xD020,
    GX2_STAT_CB_CC_SF_FULL                                 = 0xD021,
    GX2_STAT_CB_CC_RB_FULL                                 = 0xD022,
    GX2_STAT_CB_FC_RDLAT_FIFO_FULL                         = 0xD023,
    GX2_STAT_CB_CM_TQ_FULL                                 = 0xD024,
    GX2_STAT_CB_LQUAD_NO_TILE                              = 0xD025,
    GX2_STAT_CB_CM_CACHE_HIT                               = 0xD026,
    GX2_STAT_CB_CM_CACHE_TAG_MISS                          = 0xD027,
    GX2_STAT_CB_CM_CACHE_SECTOR_MISS                       = 0xD028,
    GX2_STAT_CB_CM_CACHE_REEVICTION_STALL                  = 0xD029,
    GX2_STAT_CB_CM_CACHE_EVICT_NONZERO_INFLIGHT_STALL      = 0xD02A,
    GX2_STAT_CB_CM_CACHE_EVICT_NONRESIDENT_STALL           = 0xD02B,
    GX2_STAT_CB_CM_CACHE_REPLACE_PENDING_EVICT_STALL       = 0xD02C,
    GX2_STAT_CB_CM_CACHE_INFLIGHT_COUNTER_MAXIMUM_STALL    = 0xD02D,
    GX2_STAT_CB_CM_CACHE_READ_OUTPUT_STALL                 = 0xD02E,
    GX2_STAT_CB_CM_CACHE_WRITE_OUTPUT_STALL                = 0xD02F,
    GX2_STAT_CB_CM_CACHE_ACK_OUTPUT_STALL                  = 0xD030,
    GX2_STAT_CB_CM_CACHE_FLUSH                             = 0xD031,
    GX2_STAT_CB_FC_CACHE_HIT                               = 0xD032,
    GX2_STAT_CB_FC_CACHE_TAG_MISS                          = 0xD033,
    GX2_STAT_CB_FC_CACHE_SECTOR_MISS                       = 0xD034,
    GX2_STAT_CB_FC_CACHE_REEVICTION_STALL                  = 0xD035,
    GX2_STAT_CB_FC_CACHE_EVICT_NONZERO_INFLIGHT_STALL      = 0xD036,
    GX2_STAT_CB_FC_CACHE_EVICT_NONRESIDENT_STALL           = 0xD037,
    GX2_STAT_CB_FC_CACHE_REPLACE_PENDING_EVICT_STALL       = 0xD038,
    GX2_STAT_CB_FC_CACHE_INFLIGHT_COUNTER_MAXIMUM_STALL    = 0xD039,
    GX2_STAT_CB_FC_CACHE_READ_OUTPUT_STALL                 = 0xD03A,
    GX2_STAT_CB_FC_CACHE_WRITE_OUTPUT_STALL                = 0xD03B,
    GX2_STAT_CB_FC_CACHE_ACK_OUTPUT_STALL                  = 0xD03C,
    GX2_STAT_CB_FC_CACHE_FLUSH                             = 0xD03D,
    GX2_STAT_CB_CC_CACHE_HIT                               = 0xD03E,
    GX2_STAT_CB_CC_CACHE_TAG_MISS                          = 0xD03F,
    GX2_STAT_CB_CC_CACHE_SECTOR_MISS                       = 0xD040,
    GX2_STAT_CB_CC_CACHE_REEVICTION_STALL                  = 0xD041,
    GX2_STAT_CB_CC_CACHE_EVICT_NONZERO_INFLIGHT_STALL      = 0xD042,
    GX2_STAT_CB_CC_CACHE_EVICT_NONRESIDENT_STALL           = 0xD043,
    GX2_STAT_CB_CC_CACHE_REPLACE_PENDING_EVICT_STALL       = 0xD044,
    GX2_STAT_CB_CC_CACHE_INFLIGHT_COUNTER_MAXIMUM_STALL    = 0xD045,
    GX2_STAT_CB_CC_CACHE_READ_OUTPUT_STALL                 = 0xD046,
    GX2_STAT_CB_CC_CACHE_WRITE_OUTPUT_STALL                = 0xD047,
    GX2_STAT_CB_CC_CACHE_ACK_OUTPUT_STALL                  = 0xD048,
    GX2_STAT_CB_CC_CACHE_WA_TO_RMW_CONVERSION              = 0xD049,
    GX2_STAT_CB_CC_CACHE_FLUSH                             = 0xD04A,
    GX2_STAT_CB_CM_MC_READ_REQUEST                         = 0xD04B,
    GX2_STAT_CB_FC_MC_READ_REQUEST                         = 0xD04C,
    GX2_STAT_CB_CC_MC_READ_REQUEST                         = 0xD04D,
    GX2_STAT_CB_CM_MC_WRITE_REQUEST                        = 0xD04E,
    GX2_STAT_CB_FC_MC_WRITE_REQUEST                        = 0xD04F,
    GX2_STAT_CB_CC_MC_WRITE_REQUEST                        = 0xD050,
    GX2_STAT_CB_CM_MC_READ_REQUESTS_IN_FLIGHT              = 0xD051,
    GX2_STAT_CB_FC_MC_READ_REQUESTS_IN_FLIGHT              = 0xD052,
    GX2_STAT_CB_CC_MC_READ_REQUESTS_IN_FLIGHT              = 0xD053,
    GX2_STAT_CB_CM_MC_WRITE_REQUESTS_IN_FLIGHT             = 0xD054,
    GX2_STAT_CB_FC_MC_WRITE_REQUESTS_IN_FLIGHT             = 0xD055,
    GX2_STAT_CB_CC_MC_WRITE_REQUESTS_IN_FLIGHT             = 0xD056,
    GX2_STAT_CB_CC_SURFACE_SYNC                            = 0xD057,
    GX2_STAT_CB_TWO_PROBE_QUAD_FRAGMENT                    = 0xD058,
    GX2_STAT_CB_SLOW_MODE_QUAD_FRAGMENT                    = 0xD059,
    GX2_STAT_CB_DUAL_SOURCE_COLOR_QUAD_FRAGMENT            = 0xD05A,
    GX2_STAT_CB_DRAWN_QUAD                                 = 0xD05B,
    GX2_STAT_CB_DRAWN_PIXEL                                = 0xD05C,
    GX2_STAT_CB_DRAWN_QUAD_FRAGMENT                        = 0xD05D,
    GX2_STAT_CB_BLENDER_RAW_HAZARD_STALL                   = 0xD05E,
    GX2_STAT_CB_EVENT                                      = 0xD05F,
    GX2_STAT_CB_EVENT_CACHE_FLUSH_TS                       = 0xD060,
    GX2_STAT_CB_EVENT_CONTEXT_DONE                         = 0xD061,
    GX2_STAT_CB_EVENT_CACHE_FLUSH                          = 0xD062,
    GX2_STAT_CB_EVENT_CACHE_FLUSH_AND_INV_TS_EVENT         = 0xD063,
    GX2_STAT_CB_EVENT_CACHE_FLUSH_AND_INV_EVENT            = 0xD064,
    GX2_STAT_CB_EVENT_FLUSH_AND_INV_CB_DATA_TS             = 0xD065,
    GX2_STAT_CB_EVENT_FLUSH_AND_INV_CB_META                = 0xD066,
    GX2_STAT_CB_CMASK_READ_DATA_0XC                        = 0xD067,
    GX2_STAT_CB_CMASK_READ_DATA_0XD                        = 0xD068,
    GX2_STAT_CB_CMASK_READ_DATA_0XE                        = 0xD069,
    GX2_STAT_CB_CMASK_READ_DATA_0XF                        = 0xD06A,
    GX2_STAT_CB_CMASK_WRITE_DATA_0XC                       = 0xD06B,
    GX2_STAT_CB_CMASK_WRITE_DATA_0XD                       = 0xD06C,
    GX2_STAT_CB_CMASK_WRITE_DATA_0XE                       = 0xD06D,
    GX2_STAT_CB_CMASK_WRITE_DATA_0XF                       = 0xD06E,
    GX2_STAT_CB_CORE_SCLK_VLD                              = 0xD06F,
    GX2_STAT_CB_REG_SCLK_VLD                               = 0xD070,
    GX2_STAT_DB_SC_DB_TILE_SENDS                           = 0xE000,
    GX2_STAT_DB_SC_DB_TILE_BUSY                            = 0xE001,
    GX2_STAT_DB_SC_DB_TILE_STALLS                          = 0xE002,
    GX2_STAT_DB_SC_DB_TILE_EVENTS                          = 0xE003,
    GX2_STAT_DB_SC_DB_TILE_TILES                           = 0xE004,
    GX2_STAT_DB_SC_DB_TILE_COVERED                         = 0xE005,
    GX2_STAT_DB_HIZ_TC_READ_STARVED                        = 0xE006,
    GX2_STAT_DB_HIZ_TC_WRITE_STALL                         = 0xE007,
    GX2_STAT_DB_HIZ_QTILES_CULLED                          = 0xE008,
    GX2_STAT_DB_HIS_QTILES_CULLED                          = 0xE009,
    GX2_STAT_DB_DB_SC_TILE_SENDS                           = 0xE00A,
    GX2_STAT_DB_DB_SC_TILE_BUSY                            = 0xE00B,
    GX2_STAT_DB_DB_SC_TILE_STALLS                          = 0xE00C,
    GX2_STAT_DB_DB_SC_TILE_DF_STALLS                       = 0xE00D,
    GX2_STAT_DB_DB_SC_TILE_TILES                           = 0xE00E,
    GX2_STAT_DB_DB_SC_TILE_CULLED                          = 0xE00F,
    GX2_STAT_DB_DB_SC_TILE_HIER_KILL                       = 0xE010,
    GX2_STAT_DB_DB_SC_TILE_FAST_OPS                        = 0xE011,
    GX2_STAT_DB_DB_SC_TILE_NO_OPS                          = 0xE012,
    GX2_STAT_DB_DB_SC_TILE_PIXEL_RATE                      = 0xE013,
    GX2_STAT_DB_DB_SC_TILE_SSAA_KILL                       = 0xE014,
    GX2_STAT_DB_DB_SC_TILE_FAST_Z_OPS                      = 0xE015,
    GX2_STAT_DB_DB_SC_TILE_FAST_STENCIL_OPS                = 0xE016,
    GX2_STAT_DB_SC_DB_QUAD_SENDS                           = 0xE017,
    GX2_STAT_DB_SC_DB_QUAD_BUSY                            = 0xE018,
    GX2_STAT_DB_SC_DB_QUAD_SQUADS                          = 0xE019,
    GX2_STAT_DB_SC_DB_QUAD_TILES                           = 0xE01A,
    GX2_STAT_DB_SC_DB_QUAD_PIXELS                          = 0xE01B,
    GX2_STAT_DB_SC_DB_QUAD_KILLED_TILES                    = 0xE01C,
    GX2_STAT_DB_DB_SC_QUAD_SENDS                           = 0xE01D,
    GX2_STAT_DB_DB_SC_QUAD_BUSY                            = 0xE01E,
    GX2_STAT_DB_DB_SC_QUAD_STALLS                          = 0xE01F,
    GX2_STAT_DB_DB_SC_QUAD_SQUADS                          = 0xE020,
    GX2_STAT_DB_DB_SC_QUAD_TILES                           = 0xE021,
    GX2_STAT_DB_DB_SC_QUAD_QUADS                           = 0xE022,
    GX2_STAT_DB_DB_CB_TILE_SENDS                           = 0xE023,
    GX2_STAT_DB_DB_CB_TILE_BUSY                            = 0xE024,
    GX2_STAT_DB_DB_CB_TILE_STALLS                          = 0xE025,
    GX2_STAT_DB_SX_DB_QUAD_SENDS                           = 0xE026,
    GX2_STAT_DB_SX_DB_QUAD_BUSY                            = 0xE027,
    GX2_STAT_DB_SX_DB_QUAD_STALLS                          = 0xE028,
    GX2_STAT_DB_SX_DB_QUAD_QUADS                           = 0xE029,
    GX2_STAT_DB_SX_DB_QUAD_PIXELS                          = 0xE02A,
    GX2_STAT_DB_SX_DB_QUAD_EXPORTS                         = 0xE02B,
    GX2_STAT_DB_SH_QUADS_OUTSTANDING_SUM                   = 0xE02C,
    GX2_STAT_DB_DB_CB_LQUAD_SENDS                          = 0xE02D,
    GX2_STAT_DB_DB_CB_LQUAD_BUSY                           = 0xE02E,
    GX2_STAT_DB_DB_CB_LQUAD_STALLS                         = 0xE02F,
    GX2_STAT_DB_DB_CB_LQUAD_QUADS                          = 0xE030,
    GX2_STAT_DB_TILE_RD_SENDS                              = 0xE031,
    GX2_STAT_DB_MI_TILE_RD_OUTSTANDING_SUM                 = 0xE032,
    GX2_STAT_DB_QUAD_RD_SENDS                              = 0xE033,
    GX2_STAT_DB_QUAD_RD_BUSY                               = 0xE034,
    GX2_STAT_DB_QUAD_RD_MI_STALL                           = 0xE035,
    GX2_STAT_DB_QUAD_RD_RW_COLLISION                       = 0xE036,
    GX2_STAT_DB_QUAD_RD_TAG_STALL                          = 0xE037,
    GX2_STAT_DB_QUAD_RD_32BYTE_REQS                        = 0xE038,
    GX2_STAT_DB_QUAD_RD_PANIC                              = 0xE039,
    GX2_STAT_DB_MI_QUAD_RD_OUTSTANDING_SUM                 = 0xE03A,
    GX2_STAT_DB_QUAD_RDRET_SENDS                           = 0xE03B,
    GX2_STAT_DB_QUAD_RDRET_BUSY                            = 0xE03C,
    GX2_STAT_DB_TILE_WR_SENDS                              = 0xE03D,
    GX2_STAT_DB_TILE_WR_ACKS                               = 0xE03E,
    GX2_STAT_DB_MI_TILE_WR_OUTSTANDING_SUM                 = 0xE03F,
    GX2_STAT_DB_QUAD_WR_SENDS                              = 0xE040,
    GX2_STAT_DB_QUAD_WR_BUSY                               = 0xE041,
    GX2_STAT_DB_QUAD_WR_MI_STALL                           = 0xE042,
    GX2_STAT_DB_QUAD_WR_COHERENCY_STALL                    = 0xE043,
    GX2_STAT_DB_QUAD_WR_ACKS                               = 0xE044,
    GX2_STAT_DB_MI_QUAD_WR_OUTSTANDING_SUM                 = 0xE045,
    GX2_STAT_DB_TILE_CACHE_MISSES                          = 0xE046,
    GX2_STAT_DB_TILE_CACHE_HITS                            = 0xE047,
    GX2_STAT_DB_TILE_CACHE_FLUSHES                         = 0xE048,
    GX2_STAT_DB_TILE_CACHE_SURFACE_STALL                   = 0xE049,
    GX2_STAT_DB_TILE_CACHE_STARVES                         = 0xE04A,
    GX2_STAT_DB_TILE_CACHE_MEM_RETURN_STARVE               = 0xE04B,
    GX2_STAT_DB_TCP_DISPATCHER_READS                       = 0xE04C,
    GX2_STAT_DB_TCP_PREFETCHER_READS                       = 0xE04D,
    GX2_STAT_DB_TCP_PRELOADER_READS                        = 0xE04E,
    GX2_STAT_DB_TCP_DISPATCHER_FLUSHES                     = 0xE04F,
    GX2_STAT_DB_TCP_PREFETCHER_FLUSHES                     = 0xE050,
    GX2_STAT_DB_TCP_PRELOADER_FLUSHES                      = 0xE051,
    GX2_STAT_DB_DEPTH_TILE_CACHE_SENDS                     = 0xE052,
    GX2_STAT_DB_DEPTH_TILE_CACHE_BUSY                      = 0xE053,
    GX2_STAT_DB_DEPTH_TILE_CACHE_STARVES                   = 0xE054,
    GX2_STAT_DB_DEPTH_TILE_CACHE_DTILE_LOCKED              = 0xE055,
    GX2_STAT_DB_DEPTH_TILE_CACHE_ALLOC_STALL               = 0xE056,
    GX2_STAT_DB_DEPTH_TILE_CACHE_MISSES                    = 0xE057,
    GX2_STAT_DB_DEPTH_TILE_CACHE_HITS                      = 0xE058,
    GX2_STAT_DB_DEPTH_TILE_CACHE_FLUSHES                   = 0xE059,
    GX2_STAT_DB_DEPTH_TILE_CACHE_NOOP_TILE                 = 0xE05A,
    GX2_STAT_DB_DEPTH_TILE_CACHE_DETAILED_NOOP             = 0xE05B,
    GX2_STAT_DB_DEPTH_TILE_CACHE_EVENT                     = 0xE05C,
    GX2_STAT_DB_DEPTH_TILE_CACHE_TILE_FREES                = 0xE05D,
    GX2_STAT_DB_DEPTH_TILE_CACHE_DATA_FREES                = 0xE05E,
    GX2_STAT_DB_DEPTH_TILE_CACHE_MEM_RETURN_STARVE         = 0xE05F,
    GX2_STAT_DB_STENCIL_CACHE_MISSES                       = 0xE060,
    GX2_STAT_DB_STENCIL_CACHE_HITS                         = 0xE061,
    GX2_STAT_DB_STENCIL_CACHE_FLUSHES                      = 0xE062,
    GX2_STAT_DB_STENCIL_CACHE_STARVES                      = 0xE063,
    GX2_STAT_DB_STENCIL_CACHE_FREES                        = 0xE064,
    GX2_STAT_DB_Z_CACHE_SEPARATE_Z_MISSES                  = 0xE065,
    GX2_STAT_DB_Z_CACHE_SEPARATE_Z_HITS                    = 0xE066,
    GX2_STAT_DB_Z_CACHE_SEPARATE_Z_FLUSHES                 = 0xE067,
    GX2_STAT_DB_Z_CACHE_SEPARATE_Z_STARVES                 = 0xE068,
    GX2_STAT_DB_Z_CACHE_PMASK_MISSES                       = 0xE069,
    GX2_STAT_DB_Z_CACHE_PMASK_HITS                         = 0xE06A,
    GX2_STAT_DB_Z_CACHE_PMASK_FLUSHES                      = 0xE06B,
    GX2_STAT_DB_Z_CACHE_PMASK_STARVES                      = 0xE06C,
    GX2_STAT_DB_Z_CACHE_FREES                              = 0xE06D,
    GX2_STAT_DB_PLANE_CACHE_MISSES                         = 0xE06E,
    GX2_STAT_DB_PLANE_CACHE_HITS                           = 0xE06F,
    GX2_STAT_DB_PLANE_CACHE_FLUSHES                        = 0xE070,
    GX2_STAT_DB_PLANE_CACHE_STARVES                        = 0xE071,
    GX2_STAT_DB_PLANE_CACHE_FREES                          = 0xE072,
    GX2_STAT_DB_FLUSH_EXPANDED_STENCIL                     = 0xE073,
    GX2_STAT_DB_FLUSH_COMPRESSED_STENCIL                   = 0xE074,
    GX2_STAT_DB_FLUSH_SINGLE_STENCIL                       = 0xE075,
    GX2_STAT_DB_FLUSH_1PLANE                               = 0xE076,
    GX2_STAT_DB_FLUSH_2PLANE                               = 0xE077,
    GX2_STAT_DB_FLUSH_3PLANE                               = 0xE078,
    GX2_STAT_DB_FLUSH_4PLANE                               = 0xE079,
    GX2_STAT_DB_FLUSH_5PLANE                               = 0xE07A,
    GX2_STAT_DB_FLUSH_6PLANE                               = 0xE07B,
    GX2_STAT_DB_FLUSH_7PLANE                               = 0xE07C,
    GX2_STAT_DB_FLUSH_8PLANE                               = 0xE07D,
    GX2_STAT_DB_FLUSH_9PLANE                               = 0xE07E,
    GX2_STAT_DB_FLUSH_10PLANE                              = 0xE07F,
    GX2_STAT_DB_FLUSH_11PLANE                              = 0xE080,
    GX2_STAT_DB_FLUSH_12PLANE                              = 0xE081,
    GX2_STAT_DB_FLUSH_13PLANE                              = 0xE082,
    GX2_STAT_DB_FLUSH_14PLANE                              = 0xE083,
    GX2_STAT_DB_FLUSH_15PLANE                              = 0xE084,
    GX2_STAT_DB_FLUSH_16PLANE                              = 0xE085,
    GX2_STAT_DB_FLUSH_EXPANDED_Z                           = 0xE086,
    GX2_STAT_DB_EARLYZ_WAITING_FOR_POSTZ_DONE              = 0xE087,
    GX2_STAT_DB_REZ_WAITING_FOR_POSTZ_DONE                 = 0xE088,
    GX2_STAT_DB_DK_TILE_SENDS                              = 0xE089,
    GX2_STAT_DB_DK_TILE_BUSY                               = 0xE08A,
    GX2_STAT_DB_DK_TILE_QUAD_STARVES                       = 0xE08B,
    GX2_STAT_DB_DK_TILE_STALLS                             = 0xE08C,
    GX2_STAT_DB_DK_SQUAD_SENDS                             = 0xE08D,
    GX2_STAT_DB_DK_SQUAD_BUSY                              = 0xE08E,
    GX2_STAT_DB_DK_SQUAD_STALLS                            = 0xE08F,
    GX2_STAT_DB_OP_PIPE_BUSY                               = 0xE090,
    GX2_STAT_DB_OP_PIPE_MC_READ_STALL                      = 0xE091,
    GX2_STAT_DB_QC_BUSY                                    = 0xE092,
    GX2_STAT_DB_QC_XFC                                     = 0xE093,
    GX2_STAT_DB_QC_CONFLICTS                               = 0xE094,
    GX2_STAT_DB_QC_FULL_STALL                              = 0xE095,
    GX2_STAT_DB_QC_IN_PREZ_TILE_STALLS_POSTZ               = 0xE096,
    GX2_STAT_DB_QC_IN_POSTZ_TILE_STALLS_PREZ               = 0xE097,
    GX2_STAT_DB_TSC_INSERT_SUMMARIZE_STALL                 = 0xE098,
    GX2_STAT_DB_TL_BUSY                                    = 0xE099,
    GX2_STAT_DB_TL_DTC_READ_STARVED                        = 0xE09A,
    GX2_STAT_DB_TL_Z_FETCH_STALL                           = 0xE09B,
    GX2_STAT_DB_TL_STENCIL_STALL                           = 0xE09C,
    GX2_STAT_DB_TL_Z_DECOMPRESS_STALL                      = 0xE09D,
    GX2_STAT_DB_TL_STENCIL_LOCKED_STALL                    = 0xE09E,
    GX2_STAT_DB_TL_EVENTS                                  = 0xE09F,
    GX2_STAT_DB_TL_SUMMARIZE_SQUADS                        = 0xE0A0,
    GX2_STAT_DB_TL_FLUSH_EXPAND_SQUADS                     = 0xE0A1,
    GX2_STAT_DB_TL_EXPAND_SQUADS                           = 0xE0A2,
    GX2_STAT_DB_TL_PREZ_SQUADS                             = 0xE0A3,
    GX2_STAT_DB_TL_POSTZ_SQUADS                            = 0xE0A4,
    GX2_STAT_DB_TL_PREZ_NOOP_SQUADS                        = 0xE0A5,
    GX2_STAT_DB_TL_POSTZ_NOOP_SQUADS                       = 0xE0A6,
    GX2_STAT_DB_TL_GETZ_SQUADS                             = 0xE0A7,
    GX2_STAT_DB_TL_TILE_OPS                                = 0xE0A8,
    GX2_STAT_DB_TL_IN_XFC                                  = 0xE0A9,
    GX2_STAT_DB_TL_IN_SINGLE_STENCIL_EXPAND_STALL          = 0xE0AA,
    GX2_STAT_DB_TL_IN_CONSTANT_STENCIL_WALK_STALL          = 0xE0AB,
    GX2_STAT_DB_TL_IN_FAST_Z_STALL                         = 0xE0AC,
    GX2_STAT_DB_TL_OUT_XFC                                 = 0xE0AD,
    GX2_STAT_DB_TL_OUT_SQUADS                              = 0xE0AE,
    GX2_STAT_DB_ZF_PLANE_MULTICYCLE                        = 0xE0AF,
    GX2_STAT_DB_POSTZ_SAMPLES_PASSING_Z                    = 0xE0B0,
    GX2_STAT_DB_POSTZ_SAMPLES_FAILING_Z                    = 0xE0B1,
    GX2_STAT_DB_POSTZ_SAMPLES_FAILING_S                    = 0xE0B2,
    GX2_STAT_DB_PREZ_SAMPLES_PASSING_Z                     = 0xE0B3,
    GX2_STAT_DB_PREZ_SAMPLES_FAILING_Z                     = 0xE0B4,
    GX2_STAT_DB_PREZ_SAMPLES_FAILING_S                     = 0xE0B5,
    GX2_STAT_DB_TS_TC_UPDATE_STALL                         = 0xE0B6,
    GX2_STAT_DB_SC_KICK_START                              = 0xE0B7,
    GX2_STAT_DB_SC_KICK_END                                = 0xE0B8,
    GX2_STAT_DB_SX_DB_MEM_EXPORTS                          = 0xE0B9,
    GX2_STAT_DB_SX_DB_MEM_EXPORTS_ACKED                    = 0xE0BA,
    GX2_STAT_DB_SX_DB_ACK_MEM_EXPORTS                      = 0xE0BB,
    GX2_STAT_DB_SX_DB_ACK_MEM_EXPORTS_ACKED                = 0xE0BC,
    GX2_STAT_DB_MEM_EXPORT_BUSY                            = 0xE0BD,
    GX2_STAT_DB_MEM_EXPORT_MI_STALL                        = 0xE0BE,
    GX2_STAT_DB_MEM_EXPORT_TAG_STALL                       = 0xE0BF,
    GX2_STAT_DB_CLOCK_REG_ACTIVE                           = 0xE0C0,
    GX2_STAT_DB_CLOCK_MAIN_ACTIVE                          = 0xE0C1,
    GX2_STAT_DB_CLOCK_MEM_EXPORT_ACTIVE                    = 0xE0C2,
    GX2_STAT_DB_ESR_OUT_BUSY                               = 0xE0C3,
    GX2_STAT_DB_ESR_OUT_SC_STALL                           = 0xE0C4,
    GX2_STAT_DB_ESR_OUT_LQUAD_FIFO_FULL_STALL              = 0xE0C5,
    GX2_STAT_DB_ETR_OUT_SEND                               = 0xE0C6,
    GX2_STAT_DB_ETR_OUT_BUSY                               = 0xE0C7,
    GX2_STAT_DB_ETR_OUT_LTILE_PROBE_FIFO_FULL_STALL        = 0xE0C8,
    GX2_STAT_DB_ETR_OUT_CB_TILE_STALL                      = 0xE0C9,
    GX2_STAT_DB_ETR_OUT_ESR_STALL                          = 0xE0CA,
    GX2_STAT_PIPELINE                                      = 0xF000
};

TYPED_ENUM(u32, GX2PerfMetric) {
    GX2_PERF_U64_TIME                     = 0,
    GX2_PERF_U64_GPU_TIME                 = 1,
    GX2_PERF_F32_GPU_BUSY                 = 2,
    GX2_PERF_F32_SHADER_BUSY              = 3,
    GX2_PERF_U64_REUSED_INDICES_VS        = 4,
    GX2_PERF_F32_SHADER_BUSY_VS           = 5,
    GX2_PERF_F32_SHADER_BUSY_GS           = 6,
    GX2_PERF_F32_SHADER_BUSY_PS           = 7,
    GX2_PERF_F32_ALU_BUSY                 = 8,
    GX2_PERF_F32_TEX_BUSY                 = 9,
    GX2_PERF_U64_VS_VERTICES_IN           = 10,
    GX2_PERF_F32_VS_TEX_INST_COUNT        = 11,
    GX2_PERF_F32_VS_TEX_BUSY              = 12,
    GX2_PERF_F32_VS_ALU_INST_COUNT        = 13,
    GX2_PERF_F32_VS_ALU_BUSY              = 14,
    GX2_PERF_F32_VS_ALU_EFFICIENCY        = 15,
    GX2_PERF_F32_VS_ALU_TEX_RATIO         = 16,
    GX2_PERF_F32_GS_TEX_INST_COUNT        = 17,
    GX2_PERF_F32_GS_TEX_BUSY              = 18,
    GX2_PERF_F32_GS_ALU_INST_COUNT        = 19,
    GX2_PERF_F32_GS_ALU_BUSY              = 20,
    GX2_PERF_F32_GS_ALU_EFFICIENCY        = 21,
    GX2_PERF_F32_GS_ALU_TEX_RATIO         = 22,
    GX2_PERF_F32_PRIMITIVE_ASSEMBLY_BUSY  = 23,
    GX2_PERF_U64_PRIMITIVES_IN            = 24,
    GX2_PERF_F32_PA_STALLED_ON_RASTERIZER = 25,
    GX2_PERF_F32_INTERP_BUSY              = 26,
    GX2_PERF_U64_PS_PIXELS_IN             = 27,
    GX2_PERF_F32_PS_TEX_INST_COUNT        = 28,
    GX2_PERF_F32_PS_TEX_BUSY              = 29,
    GX2_PERF_F32_PS_ALU_INST_COUNT        = 30,
    GX2_PERF_F32_PS_ALU_BUSY              = 31,
    GX2_PERF_F32_PS_ALU_EFFICIENCY        = 32,
    GX2_PERF_F32_PS_ALU_TEX_RATIO         = 33,
    GX2_PERF_U64_PS_PIXELS_OUT            = 34,
    GX2_PERF_F32_PS_EXPORT_STALLS         = 35,
    GX2_PERF_F32_TEX_UNIT_BUSY            = 36,
    GX2_PERF_U64_TEXEL_FETCH_COUNT        = 37,
    GX2_PERF_F32_TEX_CACHE_STALLED        = 38,
    GX2_PERF_F32_TEX_MISS_RATE            = 39,
    GX2_PERF_U64_TEX_MEM_BYTES_READ       = 40,
    GX2_PERF_F32_DEPTH_STENCIL_TEST_BUSY  = 41,
    GX2_PERF_F32_HIZ_TRIVIAL_ACCEPT       = 42,
    GX2_PERF_F32_HIZ_REJECT               = 43,
    GX2_PERF_U64_PRE_Z_SAMPLES_PASSING    = 44,
    GX2_PERF_U64_PRE_Z_SAMPLES_FAILING_S  = 45,
    GX2_PERF_U64_PRE_Z_SAMPLES_FAILING_Z  = 46,
    GX2_PERF_U64_POST_Z_SAMPLES_PASSING   = 47,
    GX2_PERF_U64_POST_Z_SAMPLES_FAILING_S = 48,
    GX2_PERF_U64_POST_Z_SAMPLES_FAILING_Z = 49,
    GX2_PERF_F32_Z_UNIT_STALLED           = 50,
    GX2_PERF_U64_PIXELS_AT_CB             = 51,
    GX2_PERF_U64_PIXELS_CB_MEM_WRITTEN    = 52,
    GX2_PERF_U64_IA_VERTICES              = 53,
    GX2_PERF_U64_IA_PRIMITIVES            = 54,
    GX2_PERF_U64_VS_INVOCATIONS           = 55,
    GX2_PERF_U64_GS_INVOCATIONS           = 56,
    GX2_PERF_U64_GS_PRIMITIVES            = 57,
    GX2_PERF_U64_C_INVOCATIONS            = 58,
    GX2_PERF_U64_C_PRIMITIVES             = 59,
    GX2_PERF_U64_PS_INVOCATIONS           = 60,
    GX2_PERF_U64_PA_INPUT_PRIM            = 61
};

TYPED_ENUM(u32, GX2PerfCollectionMethod) {
    GX2_PERF_COLLECT_NONE            = 0,
    GX2_PERF_COLLECT_TAGS_ACCUMULATE = 1,
    GX2_PERF_COLLECT_TAGS_INDIVIDUAL = 2
};

TYPED_ENUM(u32, GX2PerfType) {
    GX2_PERF_TYPE_GPU_METRIC = 0,
    GX2_PERF_TYPE_GPU_STAT   = 1,
    GX2_PERF_TYPE_MEM_STAT   = 2
};

TYPED_ENUM(u32, GX2RDebugOptions) {
    GX2R_DEBUG_NONE                     = 0,
    GX2R_DEBUG_GUARD_BANDS_ENABLED      = 1 << 0,
    GX2R_DEBUG_GUARD_BANDS_CHECK_ALWAYS = 1 << 1,
    GX2R_DEBUG_LEAK_CHECK               = 1 << 2,
    GX2R_DEBUG_CHECK_GPU_CONTENTION     = 1 << 3
};

TYPED_ENUM(u32, GX2RResourceFlags) {
    GX2R_RESOURCE_FLAGS_NONE      = 0,
    GX2R_BIND_TEXTURE             = GX2_SURFACE_USE_TEXTURE,
    GX2R_BIND_COLOR_BUFFER        = GX2_SURFACE_USE_COLOR_BUFFER,
    GX2R_BIND_DEPTH_BUFFER        = GX2_SURFACE_USE_DEPTH_BUFFER,
    GX2R_BIND_SCAN_BUFFER         = GX2_SURFACE_USE_SCAN_BUFFER,
    GX2R_BIND_VERTEX_BUFFER       = 1 << 4,
    GX2R_BIND_INDEX_BUFFER        = 1 << 5,
    GX2R_BIND_UNIFORM_BLOCK       = 1 << 6,
    GX2R_BIND_SHADER_PROGRAM      = 1 << 7,
    GX2R_BIND_STREAM_OUTPUT       = 1 << 8,
    GX2R_BIND_DISPLAY_LIST        = 1 << 9,
    GX2R_BIND_GS_RING             = 1 << 10,
    GX2R_USAGE_CPU_READ           = 1 << 11,
    GX2R_USAGE_CPU_WRITE          = 1 << 12,
    GX2R_USAGE_GPU_READ           = 1 << 13,
    GX2R_USAGE_GPU_WRITE          = 1 << 14,
    GX2R_USAGE_DMA_READ           = 1 << 15,
    GX2R_USAGE_DMA_WRITE          = 1 << 16,
    GX2R_USAGE_FORCE_MEM1         = 1 << 17,
    GX2R_USAGE_FORCE_MEM2         = 1 << 18,
    GX2R_OPTION_IGNORE_IN_USE     = 1 << 19,
    GX2R_OPTION_NO_CPU_INVALIDATE = 1 << 20,
    GX2R_OPTION_NO_GPU_INVALIDATE = 1 << 21,
    GX2R_OPTION_LOCK_READONLY     = 1 << 22,
    GX2R_OPTION_NO_TOUCH_DESTROY  = 1 << 23,
    GX2R_RESOURCE_FLAG_RESERVED2  = 1 << 28,
    GX2R_RESOURCE_FLAG_RESERVED1  = 1 << 29,
    GX2R_RESOURCE_FLAG_RESERVED0  = 1 << 30
};

TYPED_ENUM(u32, GX2VerifyLevel) {
    GX2_VERIFY_WARNING_NONE   = 0,
    GX2_VERIFY_WARNING_SEVERE = 1,
    GX2_VERIFY_WARNING_MEDIUM = 2,
    GX2_VERIFY_WARNING_ALL    = 3
};

typedef void        (*GX2DRCConnectCB)       (s32 chan, GX2DRCEventReason reason);
typedef void        (*GX2CallbackFunction)   (GX2CallbackEvent event, void* userDataPtr);
typedef void*       (*GX2DefaultAllocateFunc)(u32 userArg, u32 byteCount, u32 alignment);
typedef void        (*GX2DefaultFreeFunc)    (u32 userArg, void* mem);
typedef const char* (*GX2PerfTag2StringFunc) (u32 tag);
typedef void*       (*GX2RAllocateFunc)      (GX2RResourceFlags resourceFlags, u32 byteCount, u32 alignment);
typedef void        (*GX2RFreeFunc)          (GX2RResourceFlags resourceFlags, void* mem);
typedef void        (*GX2VerifyCallback)     (const char* file, GX2VerifyLevel level, u32 line, const char* format, ...);

union GX2MetricResult {
    f32 f32Result;
    u64 u64Result;
};

struct GX2CompSel {
    u8 x;
    u8 y;
    u8 z;
    u8 w;
};

struct GX2DisplayListOverrun {
    void* oldDisplayList;
    u32   oldByteSize;
    void* newDisplayList;
    u32   newByteSize;
    u32   padding0;
    u32   padding1;
};

struct GX2ContextState {
    u32 data[0x2840];
};

struct GX2PerfData {
    u8 reserved[0x8A0];
};

struct _GX2CounterInfo {
    u64       results[0x55];
    u8        padding[0x40];
    bool      enabled[0x46];
    GX2StatId stats[0x46];
    GX2SqType sqType[0x04];
};

struct GX2PerfInfo {
    _GX2CounterInfo counterInfo;
    u8              usedCpCount;
    u8              usedGrbmCount;
    u8              usedPaSuCount;
    u8              usedVgtCount;
    u8              usedSqCount;
    u8              usedSpiCount;
    u8              usedSxCount;
    u8              usedTaCount;
    u8              usedTcpCount;
    u8              usedTccCount;
    u8              usedDbCount;
    u8              usedCbCount;
    u8              idxGrbmCount;
    u8              idxGrbmGuiActive;
    u8              idxGrbmShBusy;
    u8              idxPaSuClipBusy;
    u8              idxPaSuClprCullPrim;
    u8              idxPaSuSuZeroAreaCullPrim;
    u8              idxPaSuSuBackFaceCullPrim;
    u8              idxPaSuSuFrontFaceCullPrim;
    u8              idxPaSuSuPolyModeFaceCull;
    u8              idxPaSuPaInputPrim;
    u8              idxPaSuSuStalledSc;
    u8              idxVgtVgtPaClippSend;
    u8              idxVgtVgtPaClippIsEvent;
    u8              idxVgtReusedVsIndices;
    u8              idxVgtPaClippSend;
    u8              idxVgtPaClippIsEvent;
    u8              idxSqEsVsItemsPerType;
    u8              idxSqPsItemsPerType;
    u8              idxSqEsVsGsPsTaTexInstrsPerType;
    u8              idxSqEsVsTaTexInstrsPerType;
    u8              idxSqGsTaTexInstrsPerType;
    u8              idxSqPsTaTexInstrsPerType;
    u8              idxSqEsVsAluClauseInstrsPerType;
    u8              idxSqGsAluClauseInstrsPerType;
    u8              idxSqPsAluClauseInstrsPerType;
    u8              idxSqEsVsGsPsAluClauseInstrGroupsPerType;
    u8              idxSqEsVsAluClauseInstrGroupsPerType;
    u8              idxSqGsAluClauseInstrGroupsPerType;
    u8              idxSqPsAluClauseInstrGroupsPerType;
    u8              idxSqEsVsThreadLevelPerType;
    u8              idxSqGsThreadLevelPerType;
    u8              idxSqPsThreadLevelPerType;
    u8              idxSqEsVsGsPsThreadLevelPerType;
    u8              idxSqEsVsThreadsPerType;
    u8              idxSqGsThreadsPerType;
    u8              idxSqPsThreadsPerType;
    u8              idxSpiPctL0PiBusy;
    u8              idxSpiPctL1PiBusy;
    u8              idxSxDb0Pixels;
    u8              idxSxDb1Pixels;
    u8              idxSxDb0StallCycles;
    u8              idxSxDb1StallCycles;
    u8              idxTaAlignerCycles;
    u8              idxTcpTcpTaStallCycles;
    u8              idxTcpTcpTagconflictStallCycles;
    u8              idxTcpFmtV8Pixels;
    u8              idxTcpFmtV16Pixels;
    u8              idxTcpFmtV32Pixels;
    u8              idxTcpFmtV642Pixels;
    u8              idxTcpFmtV641Pixels;
    u8              idxTcpFmtV1284CyclePixels;
    u8              idxTcpFmtV1282CyclePixels;
    u8              idxTcpFmtV1281CyclePixels;
    u8              idxTcpTotalPixels;
    u8              idxTccReqsTcTfMiss;
    u8              idxDbOpPipeBusy;
    u8              idxDbDbScTileNoOps;
    u8              idxDbDbScTilePixelRate;
    u8              idxDbDbScTileFastOps;
    u8              idxDbDbScTileHierKill;
    u8              idxDbDbScQuadTiles;
    u8              idxDbPreZSamplesPassingZ;
    u8              idxDbPreZSamplesFailingS;
    u8              idxDbPreZSamplesFailingZ;
    u8              idxDbPostZSamplesPassingZ;
    u8              idxDbPostZSamplesFailingS;
    u8              idxDbPostZSamplesFailingZ;
    u8              idxDbScDbTileTiles;
    u8              idxDbDbCbLqiadStalls;
    u8              idxCbDrawnPixel;
    u8              idxCbCcMcWriteRequest;
};

struct GX2CounterInfo {
    u8 reserved[0x4A0];
    u8 results[0x340] __attribute__ ((aligned(32)));
};

struct GX2QueryInfo {
    u64 reg[8];
};

struct GX2StreamOutStats {
    u64 primitivesWritten;
    u64 storageNeeded;
};

struct GX2DepthStencilControlReg {
    u32 reg;
};

struct GX2PolygonControlReg {
    u32 reg;
};

struct GX2StencilMaskReg {
    u32 reg[2];
};

struct GX2AlphaTestReg {
    u32 reg[2];
};

struct GX2AlphaToMaskReg {
    u32 reg;
};

struct GX2PolygonOffsetReg {
    union {
        u32 u32Val;
        f32 f32Val;
    } reg[5];
};

struct GX2TargetChannelMaskReg {
    u32 reg;
};

struct GX2AAMaskReg {
    u32 reg;
};

struct GX2ColorControlReg {
    u32 reg;
};

struct GX2BlendControlReg {
    u32 reg[2];
};

struct GX2BlendConstantColorReg {
    union {
        u32 u32Val;
        f32 f32Val;
    } reg[4];
};

struct GX2PointSizeReg {
    u32 reg;
};

struct GX2PointLimitsReg {
    u32 reg;
};

struct GX2LineWidthReg {
    u32 reg;
};

struct GX2ViewportReg {
    union {
        u32 u32Val;
        f32 f32Val;
    } reg[12];
};

struct GX2ScissorReg {
    u32 reg[2];
};

struct GX2RBuffer {
    GX2RResourceFlags resourceFlags;
    u32               elementSize;
    u32               elementCount;
    u32               reserved;
};

struct GX2UniformBlock {
    const char* name;
    u32         location;
    u32         size;
};

struct GX2UniformInitialValue {
    f32 value[4];
    u32 offset;
};

struct GX2UniformVar {
    const char* name;
    GX2VarType  type;
    u32         arrayCount;
    u32         offset;
    u32         blockIndex;
};

struct GX2AttribVar {
    const char* name;
    GX2VarType  type;
    u32         arrayCount;
    u32         location;
};

struct GX2AttribStream {
    u32                location;
    u32                buffer;
    u32                offset;
    GX2AttribFormat    format;
    GX2AttribIndexType indexType;
    u32                aluDivisor;
    GX2CompSel         destSel;
    GX2EndianSwapMode  endianSwap;
};

struct GX2SamplerVar {
    const char*    name;
    GX2SamplerType type;
    u32            location;
};

struct GX2VertexShader {
    u32                     regs[52];
    u32                     shaderSize;
    void*                   shaderPtr;
    GX2ShaderMode           shaderMode;
    u32                     numUniformBlocks;
    GX2UniformBlock*        uniformBlocks;
    u32                     numUniforms;
    GX2UniformVar*          uniformVars;
    u32                     numInitialValues;
    GX2UniformInitialValue* initialValues;
    u32                     numLoops;
    void*                   loopVars;
    u32                     numSamplers;
    GX2SamplerVar*          samplerVars;
    u32                     numAttribs;
    GX2AttribVar*           attribVars;
    u32                     ringItemsize;
    bool                    hasStreamOut;
    u32                     streamOutVertexStride[4];
    GX2RBuffer              shaderProgram;
};

struct GX2GeometryShader {
    u32                     regs[19];
    u32                     shaderSize;
    void*                   shaderPtr;
    u32                     copyShaderSize;
    void*                   copyShaderPtr;
    GX2ShaderMode           shaderMode;
    u32                     numUniformBlocks;
    GX2UniformBlock*        uniformBlocks;
    u32                     numUniforms;
    GX2UniformVar*          uniformVars;
    u32                     numInitialValues;
    GX2UniformInitialValue* initialValues;
    u32                     numLoops;
    void*                   loopVars;
    u32                     numSamplers;
    GX2SamplerVar*          samplerVars;
    u32                     ringItemsize;
    bool                    hasStreamOut;
    u32                     streamOutVertexStride[4];
    GX2RBuffer              shaderProgram;
    GX2RBuffer              copyShaderProgram;
};

struct GX2PixelShader {
    u32                     regs[41];
    u32                     shaderSize;
    void*                   shaderPtr;
    GX2ShaderMode           shaderMode;
    u32                     numUniformBlocks;
    GX2UniformBlock*        uniformBlocks;
    u32                     numUniforms;
    GX2UniformVar*          uniformVars;
    u32                     numInitialValues;
    GX2UniformInitialValue* initialValues;
    u32                     numLoops;
    void*                   loopVars;
    u32                     numSamplers;
    GX2SamplerVar*          samplerVars;
    GX2RBuffer              shaderProgram;
};

struct GX2FetchShader {
    GX2FetchShaderType type;
    u32                regs[1];
    u32                shaderSize;
    void*              shaderPtr;
    u32                numAttribs;
    u32                numDivisors;
    u32                divisors[2];
};

struct GX2DispatchParams {
    u32 numGroupsX;
    u32 numGroupsY;
    u32 numGroupsZ;
    u32 padding;
};

struct GX2ComputeShader {
    u32                     regs[12];
    u32                     shaderSize;
    void*                   shaderPtr;
    u32                     numUniformBlocks;
    GX2UniformBlock*        uniformBlocks;
    u32                     numUniforms;
    GX2UniformVar*          uniformVars;
    u32                     numInitialValues;
    GX2UniformInitialValue* initialValues;
    u32                     numLoops;
    void*                   loopVars;
    u32                     numSamplers;
    GX2SamplerVar*          samplerVars;
    u32                     layoutSizeX;
    u32                     layoutSizeY;
    u32                     layoutSizeZ;
    bool                    over64Mode;
    u32                     numWavesPerSIMD;
    GX2RBuffer              shaderProgram;
};

struct GX2StreamOutContext {
    u32 data[1];
};

struct GX2StreamOutBuffer {
    u32                  size;
    void*                dataPtr;
    u32                  vertexStride;
    GX2RBuffer           streamOutData;
    GX2StreamOutContext* ctxPtr;
};

struct GX2Surface {
    GX2SurfaceDim         dim;
    u32                   width;
    u32                   height;
    u32                   depth;
    u32                   numMips;
    GX2SurfaceFormat      format;
    GX2AAMode             aa;
    union {
        GX2SurfaceUse     use;
        GX2RResourceFlags resourceFlags;
    };
    u32                   imageSize;
    union {
        void*             imagePtr;
        void*             pMem;
    };
    u32                   mipSize;
    void*                 mipPtr;
    GX2TileMode           tileMode;
    u32                   swizzle;
    u32                   alignment;
    u32                   pitch;
    u32                   mipOffset[13];
};

struct GX2ColorBuffer {
    GX2Surface surface;
    u32        viewMip;
    u32        viewFirstSlice;
    u32        viewNumSlices;
    void*      auxPtr;
    u32        auxSize;
    u32        regs[5];
};

struct GX2DepthBuffer {
    GX2Surface surface;
    u32        viewMip;
    u32        viewFirstSlice;
    u32        viewNumSlices;
    void*      hiZPtr;
    u32        hiZSize;
    f32        clearDepth;
    u32        clearStencil;
    u32        regs[7];
};

struct GX2HiStencilState {
    GX2CompareFunction function;
    u8                 reference;
    u8                 mask;
    bool               enable;
};

struct GX2HiStencilInfo {
    GX2HiStencilState state[2];
    u32               regs[2];
};

struct GX2RectInt {
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
};

struct GX2PointInt {
    s32 x;
    s32 y;
};

struct GX2AASampleLoc {
    s8 x[8];
    s8 y[8];
};

struct GX2Texture {
    GX2Surface surface;
    u32        viewFirstMip;
    u32        viewNumMips;
    u32        viewFirstSlice;
    u32        viewNumSlices;
    GX2CompSel compSel;
    u32        regs[5];
};

struct GX2Sampler {
    u32 samplerReg[3];
};

EXPORT_FUNC_H(GX2TVScanMode, GX2GetSystemTVScanMode, void);
EXPORT_FUNC_H(GX2AspectRatio, GX2GetSystemTVAspectRatio, void);
EXPORT_FUNC_H(bool, GX2IsVideoOutReady, void);
EXPORT_FUNC_H(GX2DRCMode, GX2GetSystemDRCMode, void);
EXPORT_FUNC_H(GX2DRCMode, GX2GetSystemDRCScanMode, void);
EXPORT_FUNC_H(GX2DRCConnectCB, GX2SetDRCConnectCallback, s32 chan, GX2DRCConnectCB callback);
EXPORT_FUNC_H(void, GX2GetDRCVerticalInfo, u32* vCount, u32* vPhase);
EXPORT_FUNC_H(void, GX2CalcTVSize, GX2TVRenderMode tvRenderMode, GX2SurfaceFormat fmt, GX2BufferingMode bufferingMode, u32* size, bool* scaleNeeded);
EXPORT_FUNC_H(void, GX2CalcDRCSize, GX2DRCMode mode, GX2SurfaceFormat fmt, GX2BufferingMode bufferingMode, u32* size, bool* scaleNeeded);
EXPORT_FUNC_H(void, GX2SetTVBuffer, void* buffer, u32 size, GX2TVRenderMode tvRenderMode, GX2SurfaceFormat fmt, GX2BufferingMode bufferingMode);
EXPORT_FUNC_H(void, GX2SetDRCBuffer, void* buffer, u32 size, GX2DRCMode mode, GX2SurfaceFormat fmt, GX2BufferingMode bufferingMode);
EXPORT_FUNC_H(void, GX2SetTVScale, u32 actualWidth, u32 actualHeight);
EXPORT_FUNC_H(void, GX2SetDRCScale, u32 actualWidth, u32 actualHeight);
EXPORT_FUNC_H(void, GX2SetTVGamma, f32 gamma);
EXPORT_FUNC_H(void, GX2GetTVGamma, f32* gamma);
EXPORT_FUNC_H(void, GX2GetTVGammaEx, f32* gamma);
EXPORT_FUNC_H(void, GX2GetDRCGamma, f32* gamma);
EXPORT_FUNC_H(void, GX2GetDRCGammaEx, f32* gamma);
EXPORT_FUNC_H(void, GX2SetDRCGamma, f32 gamma);
EXPORT_FUNC_H(void, GX2SetTVEnable, bool enable);
EXPORT_FUNC_H(void, GX2SetDRCEnable, bool enable);
EXPORT_FUNC_H(void, GX2CopyColorBufferToScanBuffer, const GX2ColorBuffer* renderBuffer, GX2ScanTarget target);
EXPORT_FUNC_H(void, GX2SwapScanBuffers, void);
EXPORT_FUNC_H(void, GX2GetSwapStatus, u32* swapCount, u32* flipCount, OSTime* lastFlipTime, OSTime* lastVsyncTime);
EXPORT_FUNC_H(void, GX2WaitForFlip, void);
EXPORT_FUNC_H(void, GX2WaitForVsync, void);
EXPORT_FUNC_H(void, GX2SetSwapInterval, u32 swapInterval);
EXPORT_FUNC_H(u32, GX2GetSwapInterval, void);
EXPORT_FUNC_H(bool, GX2SetVideoEncodingHint, GX2DRCEncodingHint hintBitmap, s8  motionVectorX, s8  motionVectorY);
EXPORT_FUNC_H(bool, GX2GetLastFrame, GX2ScanTarget target, GX2Texture* texture);
EXPORT_FUNC_H(bool, GX2GetLastFrameGamma, GX2ScanTarget target, f32* gamma);

EXPORT_FUNC_H(void, GX2ClearColor, GX2ColorBuffer* colorBuffer, f32 r, f32 g, f32 b, f32 a);
EXPORT_FUNC_H(void, GX2ClearDepthStencilEx, GX2DepthBuffer* depthBuffer, f32 depthValue, u8 stencilValue, GX2ClearMode clearFlags);
EXPORT_FUNC_H(void, GX2ClearBuffersEx, GX2ColorBuffer* colorBuffer, GX2DepthBuffer* depthBuffer, f32 r, f32 g, f32 b, f32 a, f32 depthValue, u8 stencilValue, GX2ClearMode clearFlags);
EXPORT_FUNC_H(void, GX2SetClearDepthStencil, GX2DepthBuffer* depthBuffer, f32 depthValue, u8 stencilValue);
EXPORT_FUNC_H(void, GX2SetClearDepth, GX2DepthBuffer* depthBuffer, f32 depthValue);
EXPORT_FUNC_H(void, GX2SetClearStencil, GX2DepthBuffer* depthBuffer, u8 stencilValue);
EXPORT_FUNC_H(void, GX2SetAttribBuffer, u32 index, u32 size, u32 stride, const void* ptr);
EXPORT_FUNC_H(void, GX2SetPrimitiveRestartIndex, u32 index);
EXPORT_FUNC_H(void, GX2DrawIndexedEx, GX2PrimitiveType mode, u32 count, GX2IndexFormat indexFormat, const void* indices, u32 baseVertex, u32 numInstances);
EXPORT_FUNC_H(void, GX2DrawIndexedEx2, GX2PrimitiveType mode, u32 count, GX2IndexFormat indexFormat, const void* indices, u32 baseVertex, u32 numInstances, u32 baseInstance);
EXPORT_FUNC_H(void, GX2DrawIndexedImmediateEx, GX2PrimitiveType mode, u32 count, GX2IndexFormat indexFormat, const void* indices, u32 baseVertex, u32 numInstances);
EXPORT_FUNC_H(void, GX2DrawEx, GX2PrimitiveType mode, u32 count, u32 firstVertex, u32 numInstances);
EXPORT_FUNC_H(void, GX2DrawEx2, GX2PrimitiveType mode, u32 count, u32 firstVertex, u32 numInstances, u32 baseInstance);
EXPORT_FUNC_H(void, GX2DrawStreamOut, GX2PrimitiveType mode, const GX2StreamOutBuffer* streamOutBuf);
EXPORT_FUNC_H(void, GX2DispatchCompute, GX2DispatchParams* dispatchParams);

EXPORT_FUNC_H(void, GX2Init, GX2InitAttrib* initAttribs);
EXPORT_FUNC_H(void, GX2Shutdown, void);
EXPORT_FUNC_H(s32, GX2GetMainCoreId, void);
EXPORT_FUNC_H(void, GX2Flush, void);
EXPORT_FUNC_H(bool, GX2DrawDone, void);
EXPORT_FUNC_H(u64, GX2GetLastSubmittedTimeStamp, void);
EXPORT_FUNC_H(u64, GX2GetRetiredTimeStamp, void);
EXPORT_FUNC_H(bool, GX2WaitTimeStamp, u64 ts);
EXPORT_FUNC_H(void, GX2SetEventCallback, GX2CallbackEvent event, GX2CallbackFunction functionPtr, void* userDataPtr);
EXPORT_FUNC_H(void, GX2GetEventCallback, GX2CallbackEvent event, GX2CallbackFunction* functionPtr, void** userDataPtr);
EXPORT_FUNC_H(void, GX2SubmitUserTimeStamp, u64* tsBuffer, u64 timeStampValue, GX2PipeEvent when, bool triggerIntCB);
EXPORT_FUNC_H(void, GX2SetGPUFence, u32* fencePtr, u32 fenceMask, GX2CompareFunction op, u32 fenceValue);
EXPORT_FUNC_H(void*, GX2BeginGPUTask, void);
EXPORT_FUNC_H(void, GX2EndGPUTask, u32* fencePtr);
EXPORT_FUNC_H(void, GX2InsertGPUTask, u32* dlPatchLoc, u32* displayList, u32 byteSize);
EXPORT_FUNC_H(void, GX2SetSemaphore, u64* semaphoreAddr, GX2SemaphoreAction semaphoreAction);
EXPORT_FUNC_H(bool, GX2SetMiscParam, GX2MiscType param, u32 value);
EXPORT_FUNC_H(u32, GX2GetMiscParam, GX2MiscType param);
EXPORT_FUNC_H(void, GX2ResetGPU, u32 reserved);
EXPORT_FUNC_H(void, GX2BeginDisplayListEx, void* displayList, u32 byteSize, bool enableProfiling);
EXPORT_FUNC_H(u32, GX2EndDisplayList, void* displayList);
EXPORT_FUNC_H(void, GX2DirectCallDisplayList, void* displayList, u32 byteSize);
EXPORT_FUNC_H(void, GX2CallDisplayList, void* displayList, u32 byteSize);
EXPORT_FUNC_H(bool, GX2GetDisplayListWriteStatus, void);
EXPORT_FUNC_H(bool, GX2GetCurrentDisplayList, void** displayList, u32* byteSizeMax);
EXPORT_FUNC_H(void, GX2CopyDisplayList, void* displayList, u32 byteSize);

EXPORT_FUNC_H(void, GX2SetDefaultAllocator, GX2DefaultAllocateFunc alloc, GX2DefaultFreeFunc free);
EXPORT_FUNC_H(void, GX2GetDefaultAllocator, GX2DefaultAllocateFunc* alloc, GX2DefaultFreeFunc* free);
EXPORT_FUNC_H(void, GX2NotifyMemAlloc, void* addr, u32 size, u32 align);
EXPORT_FUNC_H(void, GX2NotifyMemFree, void* addr);
EXPORT_FUNC_H(void, GX2Invalidate, GX2InvalidateType invType, void* ptr, u32 size);
EXPORT_FUNC_H(void, GX2SetDebugMode, GX2DebugMode mode);
EXPORT_FUNC_H(void, GX2SetGPUTimeout, u32 millisec);
EXPORT_FUNC_H(u32, GX2GetGPUTimeout, void);
EXPORT_FUNC_H(void, GX2SetInterruptCountLimit, u32 limit);
EXPORT_FUNC_H(void, GX2PrintGPUStatus, void);
EXPORT_FUNC_H(void, GX2LogSetMisc, GX2LogAttrib attrib, u32 value);
EXPORT_FUNC_H(void, GX2DebugTagUserString, GX2DebugTagUserStringType userTagType, const char* formatString, ...);
EXPORT_FUNC_H(void, GX2DebugTagUserStringVA, GX2DebugTagUserStringType userTagType, const char* formatString, va_list args);
EXPORT_FUNC_H(void, GX2DebugCaptureFrame, const char* filename);
EXPORT_FUNC_H(void, GX2DebugCaptureFrames, const char* filename, u32 numFrames);
EXPORT_FUNC_H(void, GX2DebugCaptureStart, const char* filename, GX2DebugCaptureOptions optionFlags);
EXPORT_FUNC_H(void, GX2DebugCaptureEnd, GX2DebugCaptureOptions optionFlags);
EXPORT_FUNC_H(void, GX2SetDefaultState, void);
EXPORT_FUNC_H(void, GX2SetupContextStateEx, GX2ContextState* state, bool enableProfiling);
EXPORT_FUNC_H(void, GX2SetContextState, const GX2ContextState* state);
EXPORT_FUNC_H(void, GX2GetContextStateDisplayList, const GX2ContextState* state, void** displayList, u32* byteSize);
EXPORT_FUNC_H(void, GX2PatchDisplayList, void* displayList, GX2PatchType type, u32 offset, void* gx2ObjectPointer);

EXPORT_FUNC_H(GX2PerfMetricType, GX2GetPerfMetricType, GX2PerfMetric metric);
EXPORT_FUNC_H(void, GX2PerfInit, GX2PerfData* perfData, u32 maxTags, MEMAllocator* allocator);
EXPORT_FUNC_H(void, GX2PerfFree, GX2PerfData* perfData);
EXPORT_FUNC_H(void, GX2PerfSetCollectionMethod, GX2PerfData* perfData, GX2PerfCollectionMethod method);
EXPORT_FUNC_H(GX2PerfCollectionMethod, GX2PerfGetCollectionMethod, GX2PerfData* perfData);
EXPORT_FUNC_H(void, GX2PerfMetricsClear, GX2PerfData* perfData);
EXPORT_FUNC_H(bool, GX2PerfMetricEnable, GX2PerfData* perfData, GX2PerfType type, u32 id);
EXPORT_FUNC_H(bool, GX2PerfMetricIsEnabled, GX2PerfData* perfData, GX2PerfType type, u32 metricId);
EXPORT_FUNC_H(bool, GX2PerfMetricGetEnabled, GX2PerfData* perfData, u32 index, GX2PerfType* type, u32* metricId);
EXPORT_FUNC_H(void, GX2PerfTagEnable, GX2PerfData* perfData, u32 tag, bool enable);
EXPORT_FUNC_H(void, GX2PerfTagEnableAll, GX2PerfData* perfData);
EXPORT_FUNC_H(void, GX2PerfTagDisableAll, GX2PerfData* perfData);
EXPORT_FUNC_H(bool, GX2PerfTagIsEnabled, GX2PerfData* perfData, u32 tag);
EXPORT_FUNC_H(void, GX2PerfFrameStart, GX2PerfData* perfData);
EXPORT_FUNC_H(void, GX2PerfFrameEnd, GX2PerfData* perfData);
EXPORT_FUNC_H(u32, GX2PerfGetNumPasses, GX2PerfData* perfData);
EXPORT_FUNC_H(void, GX2PerfPassStart, GX2PerfData* perfData);
EXPORT_FUNC_H(void, GX2PerfPassEnd, GX2PerfData* perfData);
EXPORT_FUNC_H(void, GX2PerfTagStart, GX2PerfData* perfData, u32 tag);
EXPORT_FUNC_H(void, GX2PerfTagEnd, GX2PerfData* perfData, u32 tag);
EXPORT_FUNC_H(bool, GX2PerfGetResultByFrame, GX2PerfData* perfData, GX2PerfType type, u32 id, GX2MetricResult* result);
EXPORT_FUNC_H(bool, GX2PerfGetResultByTagId, GX2PerfData* perfData, GX2PerfType type, u32 id, u32 tag, u32 number, GX2MetricResult* result);
EXPORT_FUNC_H(bool, GX2PerfGetResultByTagSequence, GX2PerfData* perfData, GX2PerfType type, u32 id, u32 sequence, u32* tag, u32* number, u32* depth, GX2MetricResult* result);
EXPORT_FUNC_H(void, GX2PerfPrintFrameResults, GX2PerfData* perfData);
EXPORT_FUNC_H(void, GX2PerfPrintTagResults, GX2PerfData* perfData, GX2PerfTag2StringFunc func);
EXPORT_FUNC_H(void, GX2PerfSetPassCoherEnable, GX2PerfData* perfData, bool enable);
EXPORT_FUNC_H(bool, GX2PerfGetPassCoherEnable, GX2PerfData* perfData);

EXPORT_FUNC_H(void, _GX2InitCounterInfo, _GX2CounterInfo* info, GX2CounterId id, GX2StatId parm);
EXPORT_FUNC_H(void, _GX2SetCounterInfo, const _GX2CounterInfo* info);
EXPORT_FUNC_H(void, _GX2ResetCounters, void);
EXPORT_FUNC_H(void, _GX2StartCounters, const _GX2CounterInfo* info);
EXPORT_FUNC_H(void, _GX2StopCounters, const _GX2CounterInfo* info);
EXPORT_FUNC_H(void, _GX2SampleCounters, _GX2CounterInfo* info);
EXPORT_FUNC_H(bool, GX2InitPerfMetric, GX2PerfInfo* perfInfo, GX2PerfMetric metric);
EXPORT_FUNC_H(void, GX2GetPerfMetricU64, const GX2PerfInfo* perfInfo, GX2PerfMetric metric, u64* result);
EXPORT_FUNC_H(void, GX2GetPerfMetricF32, const GX2PerfInfo* perfInfo, GX2PerfMetric metric, f32* result);

EXPORT_FUNC_H(u32, GX2GetGPUSystemClock, void);
EXPORT_FUNC_H(void, GX2ResetCounterInfo, GX2CounterInfo* info);
EXPORT_FUNC_H(bool, GX2InitCounterInfo, GX2CounterInfo* info, GX2CounterId cid, GX2StatId sid);
EXPORT_FUNC_H(bool, GX2GetCounterSetting, GX2CounterInfo* info, GX2CounterId cid, GX2StatId* sid);
EXPORT_FUNC_H(u32, GX2GetCounterResultSize, GX2CounterInfo* info);
EXPORT_FUNC_H(void, GX2SetCounterInfo, const GX2CounterInfo* info);
EXPORT_FUNC_H(void, GX2SampleCountersEx, GX2CounterInfo* info, u64* alignedResultBuffer);
EXPORT_FUNC_H(void, GX2SampleCounters, GX2CounterInfo* info);
EXPORT_FUNC_H(u64, GX2GetCounterResultEx, GX2CounterInfo* info, u64* alignedResultBuffer, GX2StatId sid);
EXPORT_FUNC_H(u64, GX2GetCounterResult, GX2CounterInfo* info, GX2StatId sid);
EXPORT_FUNC_H(void, GX2StopCounters, const GX2CounterInfo* info);
EXPORT_FUNC_H(void, GX2StartCounters, const GX2CounterInfo* info);
EXPORT_FUNC_H(void, GX2ResetCounters, const GX2CounterInfo* info);

EXPORT_FUNC_H(void, GX2SampleTopGPUCycle, u64* addr);
EXPORT_FUNC_H(void, GX2SampleBottomGPUCycle, u64* addr);
EXPORT_FUNC_H(u64, GX2CPUTimeToGPUTime, u64 cpuTime);
EXPORT_FUNC_H(u64, GX2GPUTimeToCPUTime, u64 gpuTime);
EXPORT_FUNC_H(void, GX2QueryBegin, GX2QueryType type, GX2QueryInfo* queryInfo);
EXPORT_FUNC_H(void, GX2QueryEnd, GX2QueryType type, GX2QueryInfo* queryInfo);
EXPORT_FUNC_H(bool, GX2QueryGetOcclusionResult, const GX2QueryInfo* queryInfo, u64* zPass);
EXPORT_FUNC_H(bool, GX2QueryGetStreamOutStatsResult, const GX2QueryInfo* queryInfo, GX2StreamOutStats* stats);
EXPORT_FUNC_H(void, GX2QueryBeginConditionalRender, GX2QueryType type, const GX2QueryInfo* queryInfo, bool hint, bool predicate);
EXPORT_FUNC_H(void, GX2QueryEndConditionalRender, void);

EXPORT_FUNC_H(void, GX2RDestroyBufferEx, GX2RBuffer* gx2Buffer, GX2RResourceFlags optionFlags);
EXPORT_FUNC_H(void*, GX2RLockBufferEx, const GX2RBuffer* gx2Buffer, GX2RResourceFlags optionFlags);
EXPORT_FUNC_H(void*, GX2RLockBufferRegionEx, const GX2RBuffer* gx2Buffer, u32 byteOffset, u32 byteCount, GX2RResourceFlags optionFlags);
EXPORT_FUNC_H(void, GX2RUnlockBufferEx, const GX2RBuffer* gx2Buffer, GX2RResourceFlags optionFlags);
EXPORT_FUNC_H(bool, GX2RCreateBuffer, GX2RBuffer* gx2Buffer);
EXPORT_FUNC_H(bool, GX2RCreateBufferUserMemory, GX2RBuffer* gx2Buffer, void* userMem, u32 userByteCount);
EXPORT_FUNC_H(bool, GX2RBufferExists, const GX2RBuffer* gx2Buffer);
EXPORT_FUNC_H(void, GX2RSetBufferName, GX2RBuffer* gx2Buffer, const char* name);
EXPORT_FUNC_H(const char*, GX2RGetBufferName, const GX2RBuffer* gx2Buffer);
EXPORT_FUNC_H(void, GX2RSetAttributeBuffer, const GX2RBuffer* vertexBuffer, u32 slot, u32 stride, u32 byteOffset);
EXPORT_FUNC_H(void, GX2RSetVertexUniformBlock, const GX2RBuffer* uniformBlock, u32 location, u32 byteOffset);
EXPORT_FUNC_H(void, GX2RSetGeometryUniformBlock, const GX2RBuffer* uniformBlock, u32 location, u32 byteOffset);
EXPORT_FUNC_H(void, GX2RSetPixelUniformBlock, const GX2RBuffer* uniformBlock, u32 location, u32 byteOffset);
EXPORT_FUNC_H(void, GX2RSetStreamOutBuffer, u32 soTarget, const GX2StreamOutBuffer* streamOutBuffer);
EXPORT_FUNC_H(void, GX2RDrawIndexed, GX2PrimitiveType primitiveType, const GX2RBuffer* indexBuffer, GX2IndexFormat indexFormat, u32 indexCount, u32 startIndex, u32 startVertex, u32 numInstances);
EXPORT_FUNC_H(void, GX2RDrawIndexedImmediate, GX2PrimitiveType primitiveType, const GX2RBuffer* indexBuffer, GX2IndexFormat indexFormat, u32 indexCount, u32 startIndex, u32 startVertex, u32 numInstances);
EXPORT_FUNC_H(void, GX2RBeginDisplayListEx, const GX2RBuffer* displayList, bool enableProfiling, GX2RResourceFlags optionFlags);
EXPORT_FUNC_H(u32, GX2REndDisplayList, const GX2RBuffer* displayList);
EXPORT_FUNC_H(void, GX2RCallDisplayList, const GX2RBuffer* displayList, u32 byteSize);
EXPORT_FUNC_H(void, GX2RDirectCallDisplayList, const GX2RBuffer* displayList, u32 byteSize);
EXPORT_FUNC_H(void, GX2RSetGeometryShaderInputRingBuffer, const GX2RBuffer* ringInBuffer);
EXPORT_FUNC_H(void, GX2RSetGeometryShaderOutputRingBuffer, const GX2RBuffer* ringOutBuffer);
EXPORT_FUNC_H(void, GX2RInitFetchShader, GX2FetchShader* fetchShader, const GX2RBuffer* shaderProgram, u32 attribCount, const GX2AttribStream* attribStreams, GX2FetchShaderType type, GX2TessellationMode tessMode);
EXPORT_FUNC_H(u32, GX2RGetBufferAlignment, GX2RResourceFlags resourceFlags);
EXPORT_FUNC_H(u32, GX2RGetBufferAllocationSize, const GX2RBuffer* gx2Buffer);
EXPORT_FUNC_H(void, GX2RInvalidateMemory, GX2RResourceFlags resourceFlags, void* mem, u32 byteCount);
EXPORT_FUNC_H(void, GX2RInvalidateBuffer, const GX2RBuffer* gx2Buffer, GX2RResourceFlags optionFlags);
EXPORT_FUNC_H(u32, GX2RGetBufferGuardBandSize, GX2RResourceFlags resourceFlags);

EXPORT_FUNC_H(void, GX2SetDepthStencilControl, bool depthEnable, bool depthWriteEnable, GX2CompareFunction depthFunc, bool stencilTestEnable, bool backStencilEnable, GX2CompareFunction frontStencilFunc, GX2StencilFunction frontStencilZPass, GX2StencilFunction frontStencilZFail, GX2StencilFunction frontStencilFail, GX2CompareFunction backStencilFunc, GX2StencilFunction backStencilZPass, GX2StencilFunction backStencilZFail, GX2StencilFunction backStencilFail);
EXPORT_FUNC_H(void, GX2SetDepthOnlyControl, bool depthEnable, bool depthWriteEnable, GX2CompareFunction depthFunc);
EXPORT_FUNC_H(void, GX2SetPolygonControl, GX2FrontFaceMode frontFaceMode, bool cullFront, bool cullBack, bool enablePolygonModes, GX2PolygonMode polygonModeFront, GX2PolygonMode polygonModeBack, bool polyOffsetFrontEnable, bool polyOffsetBackEnable, bool pointLineOffsetEnable);
EXPORT_FUNC_H(void, GX2SetCullOnlyControl, GX2FrontFaceMode frontFaceMode, bool cullFront, bool cullBack);
EXPORT_FUNC_H(void, GX2SetStencilMask, u8 preMaskFront, u8 writeMaskFront, u8 refFront, u8 preMaskBack, u8 writeMaskBack, u8 refBack);
EXPORT_FUNC_H(void, GX2SetSpecialState, GX2SpecialState state, bool enable);
EXPORT_FUNC_H(void, GX2SetAlphaTest, bool alphaTestEnable, GX2CompareFunction alphaFunc, f32 ref);
EXPORT_FUNC_H(void, GX2SetAlphaToMask, bool alphaToMaskEnable, GX2AlphaToMaskMode mode);
EXPORT_FUNC_H(void, GX2SetPolygonOffset, f32 frontOffset, f32 frontSlopeScale, f32 backOffset, f32 backSlopeScale, f32 clamp);
EXPORT_FUNC_H(void, GX2SetTargetChannelMasks, GX2ChannelMask target0, GX2ChannelMask target1, GX2ChannelMask target2, GX2ChannelMask target3, GX2ChannelMask target4, GX2ChannelMask target5, GX2ChannelMask target6, GX2ChannelMask target7);
EXPORT_FUNC_H(void, GX2SetAAMask, u8 upperLeftMask, u8 upperRightMask, u8 lowerLeftMask, u8 lowerRightMask);
EXPORT_FUNC_H(void, GX2SetColorControl, GX2LogicOp lop, u8 blendEnableMask, bool multiwriteEnable, bool colorBufferEnable);
EXPORT_FUNC_H(void, GX2SetBlendControl, GX2RenderTarget target, GX2BlendFunction colorSrcBlend, GX2BlendFunction colorDstBlend, GX2BlendCombine colorCombine, bool separateAlphaBlend, GX2BlendFunction alphaSrcBlend, GX2BlendFunction alphaDstBlend, GX2BlendCombine alphaCombine);
EXPORT_FUNC_H(void, GX2SetBlendConstantColor, f32 red, f32 green, f32 blue, f32 alpha);
EXPORT_FUNC_H(void, GX2SetPointSize, f32 width, f32 height);
EXPORT_FUNC_H(void, GX2SetPointLimits, f32 min, f32 max);
EXPORT_FUNC_H(void, GX2SetLineWidth, f32 width);
EXPORT_FUNC_H(void, GX2SetViewport, f32 xOrig, f32 yOrig, f32 wd, f32 ht, f32 nearZ, f32 farZ);
EXPORT_FUNC_H(void, GX2SetScissor, u32 xOrig, u32 yOrig, u32 wd, u32 ht);
EXPORT_FUNC_H(void, GX2SetRasterizerClipControl, bool rasterizerEnable, bool zClipEnable);
EXPORT_FUNC_H(void, GX2SetRasterizerClipControlEx, bool rasterizerEnable, bool zClipEnable, bool enableHalfSizeClipSpace);
EXPORT_FUNC_H(void, GX2SetRasterizerClipControlHalfZ, bool rasterizerEnable, bool zClipEnable, bool enableHalfSizeClipSpace);

EXPORT_FUNC_H(void, GX2InitDepthStencilControlReg, GX2DepthStencilControlReg* state, bool depthEnable, bool depthWriteEnable, GX2CompareFunction depthFunc, bool stencilTestEnable, bool backStencilEnable, GX2CompareFunction frontStencilFunc, GX2StencilFunction frontStencilZPass, GX2StencilFunction frontStencilZFail, GX2StencilFunction frontStencilFail, GX2CompareFunction backStencilFunc, GX2StencilFunction backStencilZPass, GX2StencilFunction backStencilZFail, GX2StencilFunction backStencilFail);
EXPORT_FUNC_H(void, GX2GetDepthStencilControlReg, const GX2DepthStencilControlReg* state, bool* depthEnable, bool* depthWriteEnable, GX2CompareFunction* depthFunc, bool* stencilTestEnable, bool* backStencilEnable, GX2CompareFunction* frontStencilFunc, GX2StencilFunction* frontStencilZPass, GX2StencilFunction* frontStencilZFail, GX2StencilFunction* frontStencilFail, GX2CompareFunction* backStencilFunc, GX2StencilFunction* backStencilZPass, GX2StencilFunction* backStencilZFail, GX2StencilFunction* backStencilFail);
EXPORT_FUNC_H(void, GX2SetDepthStencilControlReg, const GX2DepthStencilControlReg* state);
EXPORT_FUNC_H(void, GX2InitPolygonControlReg, GX2PolygonControlReg* state, GX2FrontFaceMode frontFaceMode, bool cullFront, bool cullBack, bool enablePolygonModes, GX2PolygonMode polygonModeFront, GX2PolygonMode polygonModeBack, bool polyOffsetFrontEnable, bool polyOffsetBackEnable, bool pointLineOffsetEnable);
EXPORT_FUNC_H(void, GX2GetPolygonControlReg, const GX2PolygonControlReg* state, GX2FrontFaceMode* frontFaceMode, bool* cullFront, bool* cullBack, bool* enablePolygonModes, GX2PolygonMode* polygonModeFront, GX2PolygonMode* polygonModeBack, bool* polyOffsetFrontEnable, bool* polyOffsetBackEnable, bool* pointLineOffsetEnable);
EXPORT_FUNC_H(void, GX2SetPolygonControlReg, const GX2PolygonControlReg* state);
EXPORT_FUNC_H(void, GX2InitStencilMaskReg, GX2StencilMaskReg* state, u8 preMaskFront, u8 writeMaskFront, u8 refFront, u8 preMaskBack, u8 writeMaskBack, u8 refBack);
EXPORT_FUNC_H(void, GX2GetStencilMaskReg, const GX2StencilMaskReg* state, u8* preMaskFront, u8* writeMaskFront, u8* refFront, u8* preMaskBack, u8* writeMaskBack, u8* refBack);
EXPORT_FUNC_H(void, GX2SetStencilMaskReg, const GX2StencilMaskReg* state);
EXPORT_FUNC_H(void, GX2InitAlphaTestReg, GX2AlphaTestReg* state, bool alphaTestEnable, GX2CompareFunction alphaFunc, f32 ref);
EXPORT_FUNC_H(void, GX2GetAlphaTestReg, const GX2AlphaTestReg* state, bool* alphaTestEnable, GX2CompareFunction* alphaFunc, f32* ref);
EXPORT_FUNC_H(void, GX2SetAlphaTestReg, const GX2AlphaTestReg* state);
EXPORT_FUNC_H(void, GX2InitAlphaToMaskReg, GX2AlphaToMaskReg* state, bool alphaToMaskEnable, GX2AlphaToMaskMode mode);
EXPORT_FUNC_H(void, GX2GetAlphaToMaskReg, const GX2AlphaToMaskReg* state, bool* alphaToMaskEnable, GX2AlphaToMaskMode* mode);
EXPORT_FUNC_H(void, GX2SetAlphaToMaskReg, const GX2AlphaToMaskReg* state);
EXPORT_FUNC_H(void, GX2InitPolygonOffsetReg, GX2PolygonOffsetReg* state, f32 frontOffset, f32 frontSlopeScale, f32 backOffset, f32 backSlopeScale, f32 clamp);
EXPORT_FUNC_H(void, GX2GetPolygonOffsetReg, const GX2PolygonOffsetReg* state, f32* frontOffset, f32* frontSlopeScale, f32* backOffset, f32* backSlopeScale, f32* clamp);
EXPORT_FUNC_H(void, GX2SetPolygonOffsetReg, const GX2PolygonOffsetReg* state);
EXPORT_FUNC_H(void, GX2InitTargetChannelMasksReg, GX2TargetChannelMaskReg* state, GX2ChannelMask target0, GX2ChannelMask target1, GX2ChannelMask target2, GX2ChannelMask target3, GX2ChannelMask target4, GX2ChannelMask target5, GX2ChannelMask target6, GX2ChannelMask target7);
EXPORT_FUNC_H(void, GX2GetTargetChannelMasksReg, const GX2TargetChannelMaskReg* state, GX2ChannelMask* target0, GX2ChannelMask* target1, GX2ChannelMask* target2, GX2ChannelMask* target3, GX2ChannelMask* target4, GX2ChannelMask* target5, GX2ChannelMask* target6, GX2ChannelMask* target7);
EXPORT_FUNC_H(void, GX2SetTargetChannelMasksReg, const GX2TargetChannelMaskReg* state);
EXPORT_FUNC_H(void, GX2InitAAMaskReg, GX2AAMaskReg* state, u8 upperLeftMask, u8 upperRightMask, u8 lowerLeftMask, u8 lowerRightMask);
EXPORT_FUNC_H(void, GX2GetAAMaskReg, const GX2AAMaskReg* state, u8* upperLeftMask, u8* upperRightMask, u8* lowerLeftMask, u8* lowerRightMask);
EXPORT_FUNC_H(void, GX2SetAAMaskReg, const GX2AAMaskReg* state);
EXPORT_FUNC_H(void, GX2InitColorControlReg, GX2ColorControlReg* state, GX2LogicOp lop, u8 blendEnableMask, bool multiwriteEnable, bool colorBufferEnable);
EXPORT_FUNC_H(void, GX2GetColorControlReg, const GX2ColorControlReg* state, GX2LogicOp* lop, u8* blendEnableMask, bool* multiwriteEnable, bool* colorBufferEnable);
EXPORT_FUNC_H(void, GX2SetColorControlReg, const GX2ColorControlReg* state);
EXPORT_FUNC_H(void, GX2InitBlendControlReg, GX2BlendControlReg* state, GX2RenderTarget target, GX2BlendFunction colorSrcBlend, GX2BlendFunction colorDstBlend, GX2BlendCombine colorCombine, bool separateAlphaBlend, GX2BlendFunction alphaSrcBlend, GX2BlendFunction alphaDstBlend, GX2BlendCombine alphaCombine);
EXPORT_FUNC_H(void, GX2GetBlendControlReg, const GX2BlendControlReg* state, GX2RenderTarget* target, GX2BlendFunction* colorSrcBlend, GX2BlendFunction* colorDstBlend, GX2BlendCombine* colorCombine, bool* separateAlphaBlend, GX2BlendFunction* alphaSrcBlend, GX2BlendFunction* alphaDstBlend, GX2BlendCombine* alphaCombine);
EXPORT_FUNC_H(void, GX2SetBlendControlReg, const GX2BlendControlReg* state);
EXPORT_FUNC_H(void, GX2InitBlendConstantColorReg, GX2BlendConstantColorReg* state, f32 red, f32 green, f32 blue, f32 alpha);
EXPORT_FUNC_H(void, GX2GetBlendConstantColorReg, const GX2BlendConstantColorReg* state, f32* red, f32* green, f32* blue, f32* alpha);
EXPORT_FUNC_H(void, GX2SetBlendConstantColorReg, const GX2BlendConstantColorReg* state);
EXPORT_FUNC_H(void, GX2InitPointSizeReg, GX2PointSizeReg* state, f32 width, f32 height);
EXPORT_FUNC_H(void, GX2GetPointSizeReg, const GX2PointSizeReg* state, f32* width, f32* height);
EXPORT_FUNC_H(void, GX2SetPointSizeReg, const GX2PointSizeReg* state);
EXPORT_FUNC_H(void, GX2InitPointLimitsReg, GX2PointLimitsReg* state, f32 min, f32 max);
EXPORT_FUNC_H(void, GX2GetPointLimitsReg, const GX2PointLimitsReg* state, f32* min, f32* max);
EXPORT_FUNC_H(void, GX2SetPointLimitsReg, const GX2PointLimitsReg* state);
EXPORT_FUNC_H(void, GX2InitLineWidthReg, GX2LineWidthReg* state, f32 width);
EXPORT_FUNC_H(void, GX2GetLineWidthReg, const GX2LineWidthReg* state, f32* width);
EXPORT_FUNC_H(void, GX2SetLineWidthReg, const GX2LineWidthReg* state);
EXPORT_FUNC_H(void, GX2InitViewportReg, GX2ViewportReg* state, f32 xOrig, f32 yOrig, f32 wd, f32 ht, f32 nearZ, f32 farZ);
EXPORT_FUNC_H(void, GX2GetViewportReg, const GX2ViewportReg* state, f32* xOrig, f32* yOrig, f32* wd, f32* ht, f32* nearZ, f32* farZ);
EXPORT_FUNC_H(void, GX2SetViewportReg, const GX2ViewportReg* state);
EXPORT_FUNC_H(void, GX2InitScissorReg, GX2ScissorReg* state, u32 xOrig, u32 yOrig, u32 wd, u32 ht);
EXPORT_FUNC_H(void, GX2GetScissorReg, const GX2ScissorReg* state, u32* xOrig, u32* yOrig, u32* wd, u32* ht);
EXPORT_FUNC_H(void, GX2SetScissorReg, const GX2ScissorReg* state);

EXPORT_FUNC_H(bool, GX2RIsUserMemory, GX2RResourceFlags resourceFlags);
EXPORT_FUNC_H(void, GX2RSetAllocator, GX2RAllocateFunc alloc, GX2RFreeFunc free);
EXPORT_FUNC_H(void, GX2RSetDebugOptions, GX2RDebugOptions debugOptions);
EXPORT_FUNC_H(GX2RDebugOptions, GX2RGetDebugOptions, void);

EXPORT_FUNC_H(void, GX2RDestroySurfaceEx, GX2Surface* surface, GX2RResourceFlags optionFlags);
EXPORT_FUNC_H(void*, GX2RLockSurfaceEx, const GX2Surface* surface, s32 mipLevel, GX2RResourceFlags optionFlags);
EXPORT_FUNC_H(void, GX2RUnlockSurfaceEx, const GX2Surface* surface, s32 mipLevel, GX2RResourceFlags optionFlags);
EXPORT_FUNC_H(bool, GX2RCreateSurface, GX2Surface* surface, GX2RResourceFlags resourceFlags);
EXPORT_FUNC_H(bool, GX2RCreateSurfaceUserMemory, GX2Surface* surface, void* imagePtr, void* mipPtr, GX2RResourceFlags resourceFlags);
EXPORT_FUNC_H(bool, GX2RSurfaceExists, const GX2Surface* surface);
EXPORT_FUNC_H(void, GX2RSetSurfaceName, const GX2Surface* surface, const char* name);
EXPORT_FUNC_H(const char*, GX2RGetSurfaceName, const GX2Surface* surface);
EXPORT_FUNC_H(void, GX2RInvalidateSurface, const GX2Surface* surface, s32 mipLevel, GX2RResourceFlags optionFlags);

EXPORT_FUNC_H(u32, GX2GetVertexShaderGPRs, const GX2VertexShader* shader);
EXPORT_FUNC_H(u32, GX2GetVertexShaderStackEntries, const GX2VertexShader* shader);
EXPORT_FUNC_H(u32, GX2GetGeometryShaderGPRs, const GX2GeometryShader* shader);
EXPORT_FUNC_H(u32, GX2GetGeometryShaderStackEntries, const GX2GeometryShader* shader);
EXPORT_FUNC_H(u32, GX2GetPixelShaderGPRs, const GX2PixelShader* shader);
EXPORT_FUNC_H(u32, GX2GetPixelShaderStackEntries, const GX2PixelShader* shader);
EXPORT_FUNC_H(void, GX2SetVertexUniformReg, u32 offset, u32 count, const void* values);
EXPORT_FUNC_H(void, GX2SetPixelUniformReg, u32 offset, u32 count, const void* values);
EXPORT_FUNC_H(void, GX2SetVertexUniformBlock, u32 location, u32 size, const void* addr);
EXPORT_FUNC_H(void, GX2SetGeometryUniformBlock, u32 location, u32 size, const void* addr);
EXPORT_FUNC_H(void, GX2SetPixelUniformBlock, u32 location, u32 size, const void* addr);
EXPORT_FUNC_H(void, GX2SetComputeUniformBlock, u32 location, u32 size, const void* addr);
EXPORT_FUNC_H(u32, GX2CalcFetchShaderSizeEx, u32 numAttrib, GX2FetchShaderType fsType, GX2TessellationMode tessMode);
EXPORT_FUNC_H(void, GX2InitFetchShaderEx, GX2FetchShader* fs, void* fsBuffer, u32 count, const GX2AttribStream* attribs, GX2FetchShaderType type, GX2TessellationMode tessMode);
EXPORT_FUNC_H(u32, GX2GetAttribFormatBits, GX2AttribFormat format);
EXPORT_FUNC_H(u32, GX2CalcGeometryShaderInputRingBufferSize, u32 maxVSItemSize);
EXPORT_FUNC_H(u32, GX2CalcGeometryShaderOutputRingBufferSize, u32 maxGSItemSize);
EXPORT_FUNC_H(void, GX2SetGeometryShaderInputRingBuffer, void* ringBuffer, u32 size);
EXPORT_FUNC_H(void, GX2SetGeometryShaderOutputRingBuffer, void* ringBuffer, u32 size);
EXPORT_FUNC_H(void, GX2SetShaderModeEx, GX2ShaderMode mode, u32 vsGprs, u32 vsStackSize, u32 gsGprs, u32 gsStackSize, u32 psGprs, u32 psStackSize);
EXPORT_FUNC_H(void, GX2SetFetchShader, GX2UserContext* context, const GX2FetchShader* fs);
EXPORT_FUNC_H(void, GX2SetVertexShader, GX2UserContext* context, const GX2VertexShader* vs);
EXPORT_FUNC_H(void, GX2SetGeometryShader, GX2UserContext* context, const GX2GeometryShader* gs);
EXPORT_FUNC_H(void, GX2SetPixelShader, GX2UserContext* context, const GX2PixelShader* ps);
EXPORT_FUNC_H(void, GX2SetComputeShader, GX2UserContext* context, const GX2ComputeShader* cs);
EXPORT_FUNC_H(void, GX2SetStreamOutBuffer, u32 soTarget, const GX2StreamOutBuffer* streamOutBuf);
EXPORT_FUNC_H(void, GX2SaveStreamOutContext, u32 soTarget, const GX2StreamOutBuffer* streamOutBuf);
EXPORT_FUNC_H(void, GX2SetStreamOutContext, u32 soTarget, const GX2StreamOutBuffer* streamOutBuf, bool reset);
EXPORT_FUNC_H(void, GX2SetStreamOutEnable, bool enable);
EXPORT_FUNC_H(void, GX2SetShaderExportBuffer, void* buffer, u32 size);

EXPORT_FUNC_H(void, GX2CalcSurfaceSizeAndAlignment, GX2Surface* surface);
EXPORT_FUNC_H(void, GX2CalcColorBufferAuxInfo, GX2ColorBuffer* colorBuffer, u32* size, u32* align);
EXPORT_FUNC_H(void, GX2InitColorBufferRegs, GX2ColorBuffer* colorBuffer);
EXPORT_FUNC_H(void, GX2CalcDepthBufferHiZInfo, GX2DepthBuffer* depthBuffer, u32* size, u32* align);
EXPORT_FUNC_H(void, GX2InitDepthBufferRegs, GX2DepthBuffer* depthBuffer);
EXPORT_FUNC_H(void, GX2InitDepthBufferHiZEnable, GX2DepthBuffer* depthBuffer, bool hiZEnable);
EXPORT_FUNC_H(void, GX2InitDepthBufferRangeBase, GX2DepthBuffer* depthBuffer, GX2ZRangeBase rangeBase);
EXPORT_FUNC_H(void, GX2InitHiStencilInfoRegs, GX2HiStencilInfo* hiStencilInfo);
EXPORT_FUNC_H(void, GX2SetColorBuffer, const GX2ColorBuffer* colorBuffer, GX2RenderTarget target);
EXPORT_FUNC_H(void, GX2SetDepthBuffer, const GX2DepthBuffer* depthBuffer);
EXPORT_FUNC_H(void, GX2SetHiStencilInfo, const GX2HiStencilInfo* hiStencilInfo);
EXPORT_FUNC_H(void, GX2CopySurface, const GX2Surface* srcSurface, u32 srcMip, u32 srcSlice, GX2Surface* dstSurface, u32 dstMip, u32 dstSlice);
EXPORT_FUNC_H(void, GX2CopySurfaceEx, const GX2Surface* srcSurface, u32 srcMip, u32 srcSlice, GX2Surface* dstSurface, u32 dstMip, u32 dstSlice, u32 numRects, GX2RectInt* srcRects, GX2PointInt* dstPoints);
EXPORT_FUNC_H(void, GX2AllocateTilingApertureEx, const GX2Surface* surface, u32 mip, u32 slice, GX2EndianSwapMode mode, u32* appHandle, void** appAddress);
EXPORT_FUNC_H(void, GX2FreeTilingAperture, u32 appHandle);
EXPORT_FUNC_H(void, GX2ResolveAAColorBuffer, const GX2ColorBuffer* srcBuffer, GX2Surface* dstSurface, u32 dstMip, u32 dstSlice);
EXPORT_FUNC_H(void, GX2ExpandAAColorBuffer, GX2ColorBuffer* buffer);
EXPORT_FUNC_H(void, GX2ExpandDepthBuffer, GX2DepthBuffer* buffer);
EXPORT_FUNC_H(void, GX2ConvertDepthBufferToTextureSurface, const GX2DepthBuffer* srcBuffer, GX2Surface* dstSurface, u32 dstMip, u32 dstSlice);
EXPORT_FUNC_H(u32, GX2GetSurfaceFormatBits, GX2SurfaceFormat format);
EXPORT_FUNC_H(u32, GX2GetSurfaceSwizzleOffset, GX2Surface* surface, u32 mipLevel);
EXPORT_FUNC_H(u32, GX2GetSurfaceSwizzle, GX2Surface* surface);
EXPORT_FUNC_H(void, GX2SetSurfaceSwizzle, GX2Surface* surface, u32 swizzle);
EXPORT_FUNC_H(u32, GX2GetSurfaceMipPitch, GX2Surface* surface, u32 mipLevel);
EXPORT_FUNC_H(u32, GX2GetSurfaceMipSliceSize, GX2Surface* surface, u32 mipLevel);
EXPORT_FUNC_H(bool, GX2SurfaceIsCompressed, GX2SurfaceFormat format);
EXPORT_FUNC_H(bool, GX2CheckSurfaceUseVsFormat, GX2SurfaceUse use, GX2SurfaceFormat format);
EXPORT_FUNC_H(void, GX2SetAAMode, GX2AAMode aa);
EXPORT_FUNC_H(void, GX2SetAAModeEx, GX2AASampleLoc* sampleLoc, GX2AAMode aa);

EXPORT_FUNC_H(u32, GX2TempGetGPUVersion, void);
EXPORT_FUNC_H(u32, GX2TempGetResourceCount, void);
EXPORT_FUNC_H(u32, GX2TempGetNonUserMemoryResourceCount, void);
EXPORT_FUNC_H(void, GX2TempDumpResources, void);
EXPORT_FUNC_H(void, GX2TempDumpGPUResourceContext, void);

EXPORT_FUNC_H(void, GX2SetTessellation, GX2TessellationMode mode, GX2PrimitiveType primType, GX2IndexFormat indexFmt);
EXPORT_FUNC_H(void, GX2SetMaxTessellationLevel, f32 maxLevel);
EXPORT_FUNC_H(void, GX2SetMinTessellationLevel, f32 minLevel);

EXPORT_FUNC_H(void, GX2InitTextureRegs, GX2Texture* texture);
EXPORT_FUNC_H(void, GX2SetVertexTexture, const GX2Texture* texture, u32 textureUnitNumber);
EXPORT_FUNC_H(void, GX2SetGeometryTexture, const GX2Texture* texture, u32 textureUnitNumber);
EXPORT_FUNC_H(void, GX2SetPixelTexture, const GX2Texture* texture, u32 textureUnitNumber);
EXPORT_FUNC_H(void, GX2SetComputeTexture, const GX2Texture* texture, u32 textureUnitNumber);

EXPORT_FUNC_H(void, GX2InitSampler, GX2Sampler* sampler, GX2TexClamp clampAll, GX2TexXYFilterType minMagFilter);
EXPORT_FUNC_H(void, GX2InitSamplerClamping, GX2Sampler* sampler, GX2TexClamp clampX, GX2TexClamp clampY, GX2TexClamp clampZ);
EXPORT_FUNC_H(void, GX2InitSamplerXYFilter, GX2Sampler* sampler, GX2TexXYFilterType magFilter, GX2TexXYFilterType minFilter, GX2TexAnisoRatio maxAniso);
EXPORT_FUNC_H(void, GX2InitSamplerZMFilter, GX2Sampler* sampler, GX2TexZFilterType zFilter, GX2TexMipFilterType mipFilter);
EXPORT_FUNC_H(void, GX2InitSamplerLOD, GX2Sampler* sampler, f32 minLod, f32 maxLod, f32 lodBias);
EXPORT_FUNC_H(void, GX2InitSamplerBorderType, GX2Sampler* sampler, GX2TexBorderType border);
EXPORT_FUNC_H(void, GX2InitSamplerRoundingMode, GX2Sampler* sampler, GX2RoundingModeType roundingMode);
EXPORT_FUNC_H(void, GX2SetVertexSamplerBorderColor, u32 samplerUnitNumber, f32 red, f32 green, f32 blue, f32 alpha);
EXPORT_FUNC_H(void, GX2SetGeometrySamplerBorderColor, u32 samplerUnitNumber, f32 red, f32 green, f32 blue, f32 alpha);
EXPORT_FUNC_H(void, GX2SetPixelSamplerBorderColor, u32 samplerUnitNumber, f32 red, f32 green, f32 blue, f32 alpha);
EXPORT_FUNC_H(void, GX2SetComputeSamplerBorderColor, u32 samplerUnitNumber, f32 red, f32 green, f32 blue, f32 alpha);
EXPORT_FUNC_H(void, GX2InitSamplerDepthCompare, GX2Sampler* sampler, GX2CompareFunction depthCompare);
EXPORT_FUNC_H(void, GX2InitSamplerFilterAdjust, GX2Sampler* sampler, bool highPrecision, GX2TexMipPerfType perfMip, GX2TexZPerfType perfZ);
EXPORT_FUNC_H(void, GX2InitSamplerLODAdjust, GX2Sampler* sampler, f32 anisoBias, bool lodUsesMinorAxis);
EXPORT_FUNC_H(void, GX2SetVertexSampler, const GX2Sampler* sampler, u32 samplerUnitNumber);
EXPORT_FUNC_H(void, GX2SetGeometrySampler, const GX2Sampler* sampler, u32 samplerUnitNumber);
EXPORT_FUNC_H(void, GX2SetPixelSampler, const GX2Sampler* sampler, u32 samplerUnitNumber);
EXPORT_FUNC_H(void, GX2SetComputeSampler, const GX2Sampler* sampler, u32 samplerUnitNumber);

EXPORT_FUNC_H(GX2UDAAlertID, GX2UDAGetLastAlert, void);
EXPORT_FUNC_H(void, GX2UDAResetAlertFireCount, GX2UDAAlertID id);
EXPORT_FUNC_H(void, GX2UDASetAlertLevel, GX2UDAAlertLevel newLevel);
EXPORT_FUNC_H(void, GX2UDASetAlertEnable, GX2UDAAlertID id, bool enable);

EXPORT_FUNC_H(void, GX2SetVerifyLevel, GX2VerifyLevel level);
EXPORT_FUNC_H(GX2VerifyCallback, GX2SetVerifyCallback, GX2VerifyCallback cb);

#ifdef __cplusplus
}
#endif