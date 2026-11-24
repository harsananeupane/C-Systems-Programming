/*
 * Name: Harsana Neupane
 * Course: CSCE 3600
 * Date: November 14, 2026
 * Assignment: Minor Assignment 4
 * File: minor4svr.c
 * Description: UDP server that receives PING messages, simulates 30% packet loss, and sends PONG replies.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    // Check that the user provided exactly one port number
    if (argc != 2)
    {
        printf("usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Convert the port number from a string to an integer
    int port = atoi(argv[1]);

    // Check that the port number is valid
    if (port < 1 || port > 65535)
    {
        fprintf(stderr, "Error: Invalid port number.\n");
        return 1;
    }

    // Create a UDP socket using the IPv4 Internet domain
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // Check whether socket creation was successful
    if (sockfd < 0)
    {
        perror("socket");
        return 1;
    }

    // Declare a structure to store the server's address
    struct sockaddr_in server_addr;

    // Clear the address structure before using it
    memset(&server_addr, 0, sizeof(server_addr));

    // Configure the server to use IPv4
    server_addr.sin_family = AF_INET;

    // Accept incoming packets from any network interface
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Convert the port number to network byte order
    server_addr.sin_port = htons(port);

    // Bind the UDP socket to the server's IP address and port
    if (bind(sockfd, (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("bind");
        close(sockfd);
        return 1;
    }

    // Display a message indicating the server is ready
    printf("[server]: ready to accept data...\n");

    // Seed the random number generator for packet loss simulation
    srand(time(NULL));

    // Buffer to store incoming PING messages
    char buffer[1024];

    // Structure to store the client's address
    struct sockaddr_in client_addr;

    // Store the size of the client's address structure
    socklen_t client_len;

	    // Store the client's IP address.
    char client_ip[INET_ADDRSTRLEN];

	// Store up to 100 different client IP addresses.
char client_ips[100][INET_ADDRSTRLEN] = {{0}};

// Store the number of messages received from each client.
int message_counts[100] = {0};

// Track the number of clients recorded.
int client_total = 0;
    // Keep the server running to receive incoming messages
    while (1)
    {
        // Reset the buffer and client address length
        memset(buffer, 0, sizeof(buffer));
        client_len = sizeof(client_addr);

        // Receive a UDP message from the client
        ssize_t bytes_received = recvfrom(
            sockfd, buffer, sizeof(buffer) - 1, 0,
            (struct sockaddr *)&client_addr, &client_len
        );

        // Check whether receiving the message failed
        if (bytes_received < 0)
        {
            perror("recvfrom");
            continue;
        }

        // Ensure the received message is null-terminated
        buffer[bytes_received] = '\0';
	        // Convert the client's IP address into readable text.
        if (inet_ntop(AF_INET, &client_addr.sin_addr,
                      client_ip, sizeof(client_ip)) == NULL)
        {
            perror("inet_ntop");
            continue;
        }

	// Find the client in the list of known IP addresses.
int client_index = -1;

for (int i = 0; i < client_total; i++)
{
    if (strcmp(client_ips[i], client_ip) == 0)
    {
        client_index = i;
        break;
    }
}

// Add the client if this IP address is new.
if (client_index == -1)
{
    if (client_total >= 100)
    {
        fprintf(stderr, "Error: Client list is full.\n");
        continue;
    }

    client_index = client_total;
    strcpy(client_ips[client_index], client_ip);
    client_total++;
}

// Update this client's message count.
message_counts[client_index]++;

// Display the client's statistics.
printf("[server]: Client IP: %s, Messages received: %d\n",
       client_ip, message_counts[client_index]);
        // Generate a random number from 0 to 9
        int status = rand() % 10;

        // Simulate 30% packet loss
        if (status < 3)
        {
            printf("[server]: dropped packet\n");
            continue;
        }

        // Display the received message if the packet was not dropped
        printf("[client]: %s\n", buffer);

        // Send a PONG response back to the client
        const char *response = "PONG";

        if (sendto(sockfd, response, strlen(response), 0,
                   (struct sockaddr *)&client_addr, client_len) < 0)
        {
            perror("sendto");
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}
