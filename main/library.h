/**
 * @file library.h
 * @author Mathias Jochum
 * @brief Server communication library header
 * @date 2024-12-06
 *
 * @copyright Copyright (c) 2024
 *
 * This header defines the interface for server communication functions
 * that simulate network latency and connection management for performance
 * testing and latency optimization exercises.
 */

#ifndef MAIN_LIBRARY_H_
#define MAIN_LIBRARY_H_

#include <stdint.h>

#define MAX_CONNECTIONS 10 //!< Maximum simultaneous connections allowed

/**
 * @brief Simulates requesting data from a remote server
 *
 * This function mocks a network request to a server with the given UID.
 * It simulates network behavior including:
 * - Random connection latency (0-1000ms)
 * - Connection pooling with a maximum of MAX_CONNECTIONS concurrent
 *   connections
 * - Request/response round-trip time
 * - Connection establishment and teardown overhead
 *
 * The function may be called from several tasks at the same time. Each call
 * holds one connection open until it returns.
 *
 * @param uid Unique identifier of the server to request data from (0-based)
 * @return int32_t The server's response data (currently returns the UID as
 *         mock data)
 *
 * @note This function will block indefinitely if more than MAX_CONNECTIONS
 *       concurrent connections are attempted, printing an error message every
 *       second
 */
int32_t requestDataFromServer(int32_t uid);

#endif // MAIN_LIBRARY_H_
