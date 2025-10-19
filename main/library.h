/**
 * @file library.h
 * @brief Server communication library header
 *
 * This header defines the interface for server communication functions
 * that simulate network latency and connection management for performance
 * testing and latency optimization exercises.
 */

#ifndef MAIN_LIBRARY_H_
#define MAIN_LIBRARY_H_

#include <stdint.h>

#define MAX_CONNECTIONS 10  // Maximum simultaneous connections allowed

/**
 * @brief Simulates requesting data from a remote server
 *
 * This function mocks a network request to a server with the given UID.
 * It simulates network behavior including:
 * - Random connection latency (0-1000ms)
 * - Connection pooling with a maximum of 10 concurrent connections
 * - Request/response round-trip time
 * - Connection establishment and teardown overhead
 *
 * @param uid Unique identifier of the server to request data from (0-based)
 * @return int32_t The server's response data (currently returns the UID as mock data)
 *
 * @note This function will block indefinitely if more than 10 concurrent
 *       connections are attempted, printing an error message every second
 */
int32_t requestDataFromServer(int32_t uid);

#endif // MAIN_LIBRARY_H_