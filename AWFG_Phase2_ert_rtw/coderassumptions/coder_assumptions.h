/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "AWFG_Phase2_ca.h"

/* global results variable mapping for static code */
#define CA_Expected_HWImpl             CA_AWFG_Phase2_ExpHW
#define CA_Actual_HWImpl               CA_AWFG_Phase2_ActHW
#define CA_HWImpl_Results              CA_AWFG_Phase2_HWRes
#define CA_PortableWordSizes_Results   CA_AWFG_Phase2_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   AWFG_Phase2_caRunTests
#endif                                 /* CODER_ASSUMPTIONS_H */
