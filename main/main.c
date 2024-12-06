/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"

#include "library.h"

/**
 * @brief Calculate the mean value of the data from various servers
 * 
 * @todo Optimize this function to run faster
 * 
 * @return Calculated mean value
 */
static int32_t calculateMean()
{
    int64_t sum = 0;
    const int32_t nb_servers = 100;
    for (int32_t uid = 0; uid < nb_servers; uid++)
    {
        sum += requestDataFromServer(uid);
    }
    return (int32_t)(sum / nb_servers);
}

void app_main(void)
{
    printf("Start calculating mean value...\n");
    const uint64_t start_us =  esp_timer_get_time();
    const int32_t mean = calculateMean();
    const uint64_t end_us =  esp_timer_get_time();
    printf("Mean value: %ld (time: %lldms)!\n", mean, (end_us - start_us) / 1000);
}
