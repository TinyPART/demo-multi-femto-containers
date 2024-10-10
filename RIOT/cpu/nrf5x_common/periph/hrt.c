/*
 * Copyright (C) 2019 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 *
 */

/**
 * @ingroup     cpu_nrf5x_common
 * @{
 *
 * @file
 * @brief       Implementation of the temperature peripheral internal driver
 *
 * @author      Alexandre Abadie <alexandre.abadie@inria.fr>
 *
 * @}
 */

#include <stdint.h>
#include "random.h"
#include "saul.h"
#include "saul_reg.h"
#include "phydat.h"

static uint8_t heart_rate = 80;

/**
 * @brief   Read the temperature in E-02 °C
 * @return  The measured temperature in E-02 °C (e.g. 1825 would mean 18.25 °C)
 */
static int16_t heart_rate_read(void)
{
    if (heart_rate == 60) {
        heart_rate++;
    }
    else if (heart_rate == 180) {
        heart_rate--;
    }
    else {
        heart_rate += random_uint32_range(0, 3) - 1;
    }

    return heart_rate;
}

static int _read_hrt(const void *dev, phydat_t *res)
{
    (void)dev;
    res->val[0] = heart_rate_read();
    res->val[1] = 0;
    res->val[2] = 0;
    res->unit = UNIT_UNDEF;
    res->scale = 0;
    return 1;
}

const saul_reg_info_t nrf_hrt_saul_info = {
    .name = "NRF_HRT"
};

const saul_driver_t nrf_hrt_saul_driver = {
    .read = _read_hrt,
    .write = saul_notsup,
    .type = SAUL_SENSE_ANY,
};

