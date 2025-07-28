#include "edge_impulse_sdk_classifier_ei_run_classifier.h"
#include "edge_impulse_sdk_classifier_ei_classifier_types.h"

EI_IMPULSE_ERROR run_classifier(
    const signal_t *signal,
    ei_impulse_result_t *result,
    bool debug
) {
    // Implementazione fittizia per il test
    result->classification[0].label = "sì";
    result->classification[0].value = 0.9f;
    result->classification[1].label = "no";
    result->classification[1].value = 0.1f;
    return EI_IMPULSE_OK;
}
