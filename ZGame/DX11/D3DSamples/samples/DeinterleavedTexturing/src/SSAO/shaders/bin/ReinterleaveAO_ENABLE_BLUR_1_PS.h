#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /O3 /T ps_5_0 src/ReinterleaveAO_PS.hlsl /E
//    ReinterleaveAO_ENABLE_BLUR_1_PS /DENABLE_BLUR=1
//    /DMAIN_FUNCTION=ReinterleaveAO_ENABLE_BLUR_1_PS /Fh
//    bin\ReinterleaveAO_ENABLE_BLUR_1_PS.h
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// PointSampler                      sampler      NA          NA    0        1
// AOTexture                         texture   float     2darray    0        1
// DepthTexture                      texture   float          2d    1        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Position              0   xyzw        0      POS  float   xy  
// TEXCOORD                 0   xy          1     NONE  float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_TARGET                0   xy          0   TARGET  float   xy  
//
ps_5_0
dcl_globalFlags refactoringAllowed
dcl_sampler s0, mode_default
dcl_resource_texture2darray (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_input_ps_siv linear noperspective v0.xy, position
dcl_input_ps linear v1.xy
dcl_output o0.xy
dcl_temps 2
ftoi r0.xy, v0.xyxx
bfi r0.z, l(2), l(2), r0.y, l(0)
bfi r1.z, l(2), l(0), r0.x, r0.z
ishr r1.xy, r0.xyxx, l(2, 2, 0, 0)
mov r1.w, l(0)
ld_indexable(texture2darray)(float,float,float,float) r0.x, r1.xyzw, t0.xyzw
mov o0.x, r0.x
sample_indexable(texture2d)(float,float,float,float) r0.x, v1.xyxx, t1.xyzw, s0
mov o0.y, r0.x
ret 
// Approximately 10 instruction slots used
#endif

const BYTE g_ReinterleaveAO_ENABLE_BLUR_1_PS[] =
{
     68,  88,  66,  67,   3, 114, 
      1, 204,  13,  69, 225,  42, 
     18, 110, 205,  24, 233, 114, 
    210, 100,   1,   0,   0,   0, 
    236,   3,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     48,   1,   0,   0, 136,   1, 
      0,   0, 188,   1,   0,   0, 
     80,   3,   0,   0,  82,  68, 
     69,  70, 244,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
    255, 255,   0, 129,   0,   0, 
    192,   0,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    156,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 169,   0,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   5,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 179,   0, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     80, 111, 105, 110, 116,  83, 
     97, 109, 112, 108, 101, 114, 
      0,  65,  79,  84, 101, 120, 
    116, 117, 114, 101,   0,  68, 
    101, 112, 116, 104,  84, 101, 
    120, 116, 117, 114, 101,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  57, 
     46,  50,  57,  46,  57,  53, 
     50,  46,  51,  49,  49,  49, 
      0, 171, 171, 171,  73,  83, 
     71,  78,  80,   0,   0,   0, 
      2,   0,   0,   0,   8,   0, 
      0,   0,  56,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   3, 
      0,   0,  68,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,   3,   3, 
      0,   0,  83,  86,  95,  80, 
    111, 115, 105, 116, 105, 111, 
    110,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0, 171, 
    171, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   3,  12,   0,   0, 
     83,  86,  95,  84,  65,  82, 
     71,  69,  84,   0, 171, 171, 
     83,  72,  69,  88, 140,   1, 
      0,   0,  80,   0,   0,   0, 
     99,   0,   0,   0, 106,   8, 
      0,   1,  90,   0,   0,   3, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  88,  64,   0,   4, 
      0, 112,  16,   0,   0,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   1,   0,   0,   0, 
     85,  85,   0,   0, 100,  32, 
      0,   4,  50,  16,  16,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  98,  16,   0,   3, 
     50,  16,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
     50,  32,  16,   0,   0,   0, 
      0,   0, 104,   0,   0,   2, 
      2,   0,   0,   0,  27,   0, 
      0,   5,  50,   0,  16,   0, 
      0,   0,   0,   0,  70,  16, 
     16,   0,   0,   0,   0,   0, 
    140,   0,   0,  11,  66,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0, 140,   0,   0,  11, 
     66,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
      0,  10,  50,   0,  16,   0, 
      1,   0,   0,   0,  70,   0, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
    130,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  45,   0, 
      0, 137,   2,   2,   0, 128, 
     67,  85,  21,   0,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5,  18,  32,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     69,   0,   0, 139, 194,   0, 
      0, 128,  67,  85,  21,   0, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  70,  16,  16,   0, 
      1,   0,   0,   0,  70, 126, 
     16,   0,   1,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
     34,  32,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    148,   0,   0,   0,  10,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0
};
