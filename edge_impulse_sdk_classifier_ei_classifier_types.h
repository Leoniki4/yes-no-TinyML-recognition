#pragma once
#include <stdint.h>
#include <stddef.h>  // Aggiungi questo include per size_t

typedef enum {
    EIDSP_OK = 0,
    EIDSP_ERROR = -1
} ei_dsp_error_t;

typedef struct {
    float *buffer;
    uint32_t buf_size;
    uint16_t n_samples;
    uint32_t total_length;
    ei_dsp_error_t (*get_data)(size_t offset, size_t length, float *out_ptr);
} signal_t;

typedef struct {
    const char *label;
    float value;
} ei_classifier_result_t;

typedef struct {
    ei_classifier_result_t classification[2];
    uint32_t timing_us;
} ei_impulse_result_t;

typedef enum {
    EI_IMPULSE_OK = 0,
    EI_IMPULSE_ERROR_SHAPES_DONT_MATCH = -1
} EI_IMPULSE_ERROR;
