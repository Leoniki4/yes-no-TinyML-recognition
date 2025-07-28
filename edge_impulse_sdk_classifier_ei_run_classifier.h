#pragma once
#include "edge_impulse_sdk_classifier_ei_classifier_types.h"

#ifdef __cplusplus
extern "C" {
#endif

EI_IMPULSE_ERROR run_classifier(
    const signal_t *signal,
    ei_impulse_result_t *result,
    bool debug = false
);

#ifdef __cplusplus
}
#endif
