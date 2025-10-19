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
 * - Each request has random 0-1000ms delay
 * - Connection pooling limits concurrent requests to 10
 *
 * Optimization opportunities:
 * - Implement concurrent/parallel requests
 * - Utilize connection pooling efficiently
 * - Consider caching strategies
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"

#include "library.h"

// Total number of servers to request data from
const int32_t nb_servers = 100;

/**
 * @brief Calculate the mean value of the data from various servers
 *
 * @todo Optimize this function to run faster
 *
 * @return Calculated mean value
 */
static int32_t calculateMean()
{
    int64_t sum = 0;  // Use 64-bit to prevent overflow during summation

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
    printf("Start calculating mean value...\n");
    printf("Requesting data from %ld servers...\n", nb_servers);

    // Performance measurement using ESP32's high-resolution timer
    const uint64_t start_us = esp_timer_get_time();
    const int32_t mean = calculateMean();
    const uint64_t end_us = esp_timer_get_time();

    printf("Mean value: %ld (time: %lldms)\n", mean, (end_us - start_us) / 1000);
}
