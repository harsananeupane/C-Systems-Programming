/*
 * Name: Harsana Neupane
 * Course: CSCE 3600
 * Date: November 19, 2026
 * Assignment: Minor Assignment 4
 * File: minor4cli.c
 * Description: UDP client that sends 10 PING messages,
 * measures round-trip time, and calculates packet loss.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include <netdb.h>
#include <arpa/inet.h>
int main(int argc, char *argv[])
{
    // Check that the user provided a hostname and port number.
    if (argc != 3)
    {
        printf("usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Store the server hostname and port number.
    char *hostname = argv[1];
    char *port = argv[2];

    // Structure used to look up IPv6 and IPv4 server addresses.
    struct addrinfo hints;
    struct addrinfo *result;

    // Initialize the structure with zeros.
    memset(&hints, 0, sizeof(hints));

    // Request UDP addresses for either IPv6 or IPv4.
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
	    // Look up the server's IPv6 and IPv4 addresses.
    int status = getaddrinfo(hostname, port, &hints, &result);

    if (status != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    // Variables for the socket and server addresses.
    int sockfd = -1;
    struct addrinfo *p;
    struct sockaddr_storage server_addr;
    socklen_t server_len;

    // Try IPv6 first, then IPv4.
    for (int family = AF_INET6; family != 0;
         family = (family == AF_INET6) ? AF_INET : 0)
    {
        for (p = result; p != NULL; p = p->ai_next)
        {
            if (p->ai_family != family)
                continue;

            sockfd = socket(p->ai_family, p->ai_socktype,
                            p->ai_protocol);

	if (sockfd < 0)
    continue;

// Attempt to connect the UDP socket to the server.
if (connect(sockfd, p->ai_addr, p->ai_addrlen) < 0)
{
    close(sockfd);
    sockfd = -1;
    continue;
}

// Save the address of the selected server.
            memcpy(&server_addr, p->ai_addr, p->ai_addrlen);
            server_len = p->ai_addrlen;
            break;
        }

        if (sockfd >= 0)
            break;
    }

    // Check whether a UDP socket was created.
    if (sockfd < 0)
    {
        fprintf(stderr, "Error: Could not create UDP socket.\n");
        freeaddrinfo(result);
        return 1;
    }

    freeaddrinfo(result);

    // Variables for tracking packet statistics.
    int sent = 0;
    int received = 0;

    // Variables for calculating round-trip times.
    double min_rtt = 0.0;
    double max_rtt = 0.0;
    double total_rtt = 0.0;

    // Send 10 PING messages to the server.
    for (int i = 1; i <= 10; i++)
    {
        char buffer[1024];
        struct timeval start, end;

        // Record the time before sending the PING.
        gettimeofday(&start, NULL);

        // Send the PING message using UDP.
        if (sendto(sockfd, "PING", 4, 0,
                   (struct sockaddr *)&server_addr,
                   server_len) < 0)
        {
            perror("sendto");
            close(sockfd);
            return 1;
        }

        sent++;

        // Display the PING number and status.
        printf("%d: Sent... ", i);
	fflush(stdout);
	        // Set a one-second timeout for receiving a reply.
        fd_set readfds;
        struct timeval timeout;

        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        // Wait for a response from the server.
        int ready = select(sockfd + 1, &readfds,
                           NULL, NULL, &timeout);

        if (ready < 0)
        {
            perror("select");
            close(sockfd);
            return 1;
        }
        else if (ready == 0)
        {
            // No response received within one second.
            printf("Timed Out\n");
        }
        else
        {
            // Receive the PONG message.
            ssize_t bytes = recvfrom(sockfd, buffer,
                                     sizeof(buffer) - 1,
                                     0, NULL, NULL);

            if (bytes < 0)
            {
                perror("recvfrom");
                close(sockfd);
                return 1;
            }

            buffer[bytes] = '\0';

            // Check whether the server replied with PONG.
            if (strcmp(buffer, "PONG") == 0)
            {
                gettimeofday(&end, NULL);

                // Calculate round-trip time in milliseconds.
                double rtt =
                    (end.tv_sec - start.tv_sec) * 1000.0 +
                    (end.tv_usec - start.tv_usec) / 1000.0;

                received++;
                total_rtt += rtt;

                // Update minimum and maximum RTT.
                if (received == 1 || rtt < min_rtt)
                    min_rtt = rtt;

                if (received == 1 || rtt > max_rtt)
                    max_rtt = rtt;

                printf("RTT=%.6f ms\n", rtt);
            }
            else
            {
                printf("Unexpected response\n");
            }
        }
    } // End of the 10 PING messages loop

    // Calculate the percentage of packets lost.
    double loss_rate = ((sent - received) / (double)sent) * 100.0;

    // Display packet statistics.
    printf("\n%d pkts xmited, %d pkts rcvd, %.0f%% pkt loss\n",
           sent, received, loss_rate);

    // Display RTT statistics for successful responses.
    if (received > 0)
    {
        double avg_rtt = total_rtt / received;

        printf("min: %.6f ms, max: %.6f ms, avg: %.6f ms\n",
               min_rtt, max_rtt, avg_rtt);
    }
    else
    {
        printf("No RTT statistics available.\n");
    }

    // Close the UDP socket.
    close(sockfd);

    return 0;
}

