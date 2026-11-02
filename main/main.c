/**
 * @file main.c
 * @brief Latency optimization exercise - Main application
 *
 * This application demonstrates a latency-sensitive workload that calculates
 * the mean value from 100 simulated server requests. The goal is to optimize
 * the calculateMean() function to reduce overall execution time while
 * maintaining the same result accuracy.
 *
 * Performance bottlenecks:
 * - Sequential server requests create cumulative latency
 * - Each request takes a random time between 0 and 2 s
 * - Connection pooling limits concurrent requests to 10
 */

#include <esp_log.h>
#include <esp_timer.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <inttypes.h>

#include "library.h"

static const char *TAG = "main";

//! Total number of servers to request data from
static const int32_t nb_servers = 100;

/**
 * @brief Calculate the mean value of the data from various servers
 *
 * @todo Optimize this function to run faster
 *
 * @return Calculated mean value
 */
static int32_t calculateMean(void)
{
    int64_t sum = 0; // Use 64-bit to prevent overflow during summation

    for (int32_t uid = 0; uid < nb_servers; uid++)
    {
        sum += requestDataFromServer(uid);
    }

    return (int32_t)(sum / nb_servers);
}

/**
 * @brief Main application entry point
 */
void app_main(void)
{
    // The mock server returns its uid as data, so the mean of the values
    // 0 ... nb_servers - 1 is known in advance
    const int32_t expected_mean = (nb_servers - 1) / 2;

    ESP_LOGI(TAG, "Requesting data from %" PRId32 " servers...", nb_servers);

    // Performance measurement using ESP32's high-resolution timer
    const int64_t start_us = esp_timer_get_time();
    const int32_t mean = calculateMean();
    const int64_t elapsed_ms = (esp_timer_get_time() - start_us) / 1000;

    ESP_LOGI(TAG,
             "Mean value: %" PRId32 " (expected %" PRId32 ", used %" PRId64
             " ms)",
             mean, expected_mean, elapsed_ms);
}
