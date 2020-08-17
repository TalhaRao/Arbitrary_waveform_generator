/*
 * File: AWFG_Phase2_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef AWFG_PHASE2_CA_H
#define AWFG_PHASE2_CA_H

/* preprocessor validation checks */
#include "AWFG_Phase2_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_AWFG_Phase2_HWRes;
extern CA_PWS_TestResults CA_AWFG_Phase2_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_AWFG_Phase2_ExpHW;
extern CA_HWImpl CA_AWFG_Phase2_ActHW;

/* entry point function to run tests */
void AWFG_Phase2_caRunTests(void);

#endif                                 /* AWFG_PHASE2_CA_H */
