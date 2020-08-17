/*
 * File: AWFG_Phase2_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "AWFG_Phase2_ca.h"

CA_HWImpl_TestResults CA_AWFG_Phase2_HWRes;
CA_PWS_TestResults CA_AWFG_Phase2_PWSRes;
const CA_HWImpl CA_AWFG_Phase2_ExpHW = {
  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  64,                                  /* BitPerPointer */
  64,                                  /* BitPerSizeT */
  64,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */
  1,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "Custom Processor->MATLAB Host Computer",/* HWDeviceType */
  0                                    /* MemoryAtStartup */
};

CA_HWImpl CA_AWFG_Phase2_ActHW;
void AWFG_Phase2_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_AWFG_Phase2_ActHW, &CA_AWFG_Phase2_ExpHW,
    &CA_AWFG_Phase2_PWSRes);
  caVerifyHWImpl(&CA_AWFG_Phase2_ActHW, &CA_AWFG_Phase2_ExpHW,
                 &CA_AWFG_Phase2_HWRes);
}
