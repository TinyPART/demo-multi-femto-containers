#include <stdint.h>
#include "bpf/bpfapi/helpers.h"

int heart_rate_read(void *ctx)
{
    (void)ctx;
    unsigned type = 0x80; /* "any" sensor */
    bpf_saul_reg_t *sensor;
    phydat_t measurement;

    /* Find temp sensor */
    sensor = bpf_saul_reg_find_type(type);

    if (!sensor ||
        (bpf_saul_reg_read(sensor,
                           &measurement) < 0)) {
        return 80; /* random heart rate to simulate */
    }

    /** format */
    return measurement.val[0] * 100;
}
