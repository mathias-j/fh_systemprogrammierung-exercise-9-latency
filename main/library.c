#include "library.h"

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <esp_random.h>

/**
 * @brief Mock function to request data from server
 * 
 * @param uid Id of the server to get data from
 */
int32_t requestDataFromServer(int32_t uid)
{
    static size_t connection_count = 0;

    // Simulate a random connection latency
    const uint32_t connection_latency_ms = esp_random() % 1000;

    // Build up the connection
    connection_count++;
    if(connection_count>10)
    {
        for(;;)
        {
            printf("Too many connections");
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }
    vTaskDelay(pdMS_TO_TICKS(connection_latency_ms)); // Connection latency

    // Send request

    // Wait for response
    vTaskDelay(pdMS_TO_TICKS(connection_latency_ms)); // Response latency

    // Close the connection
    connection_count--;

    // Process response
    return uid; // For now just return the uid
}
