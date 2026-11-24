# UDP Network Monitoring Tool

A C-based client-server application developed for my Systems Programming course at the University of North Texas. It uses UDP sockets to simulate packet loss and measure network performance.

## Features

- Sends 10 PING requests from the client to the server.
- Simulates 30% packet loss.
- Measures round-trip time (RTT).
- Calculates minimum, maximum, and average latency.
- Handles response timeouts and socket errors.
- Tracks client IP addresses and message counts.
- Supports IPv6-first address selection with IPv4 fallback on the client.

## Technologies

C, Linux, GCC, UDP/IP, Socket Programming

## Files

- `client.c` – Sends requests and calculates network statistics.
- `server.c` – Receives requests and simulates packet loss using an IPv4 socket.

## What I Learned

This project helped me understand network communication, socket programming, packet loss, and network performance analysis.
