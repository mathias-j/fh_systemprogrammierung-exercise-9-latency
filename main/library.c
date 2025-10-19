/**
 * @file library.c
 * @brief Server communication simulation
 *
 * This file implements mock server communication functions that simulate
 * real-world network latency and connection management for testing purposes.
 * The implementation is designed to help analyze and optimize latency-sensitive
 * applications by providing realistic timing behavior without actual network I/O.
 */

#include "library.h"

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>

#include <esp_random.h>

/**
 * @brief Mock function to request data from server
 *
 * Simulates a complete HTTP/network request cycle including:
 * 1. Connection establishment with random latency (0-1000ms)
 * 2. Request transmission
 * 3. Response waiting time (equal to connection latency)
 * 4. Connection cleanup
 *
 * The function implements a simple connection pool mechanism that prevents
 * more than 10 simultaneous connections to avoid resource exhaustion.
 * If the connection limit is exceeded, the function enters an infinite loop
 * printing error messages - this simulates a server overload condition.
 *
 * @param uid Unique identifier of the server to get data from
 * @return int32_t Server response data (mock implementation returns the UID)
 *
 * @note Uses esp_random() to generate realistic network timing variability
 * @warning Will hang indefinitely if connection count exceeds 10
 */
int32_t requestDataFromServer(int32_t uid)
{
    static size_t connection_count = 0;

    // Simulate a random connection latency between 0-999ms
    const uint32_t connection_latency_ms = esp_random() % 1000;

    // Build up the connection - increment active connection counter
    connection_count++;

    // Connection pool limit check - prevent resource exhaustion
    // In real systems, this would return an error or queue the request
    if(connection_count > MAX_CONNECTIONS)
    {
        for(;;)
        {
            printf("Too many connections - server overloaded\n");
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }

    // Simulate connection establishment time
    vTaskDelay(pdMS_TO_TICKS(connection_latency_ms));

    // Send request (simulated - no actual data transmission)
    // In real implementation: serialize request, send over socket

    // Wait for response - simulate server processing + network round-trip
    vTaskDelay(pdMS_TO_TICKS(connection_latency_ms));

    // Close the connection - decrement active connection counter
    connection_count--;

    // Process response and return mock data
    // In real implementation: parse response, handle errors, return actual data
    return uid; // For now just return the uid as placeholder data
}
