# TCP Client-Server Communication

A C networking project completed during my Systems Programming course at UNT. I completed the provided client-server programs using TCP socket APIs.

## Features

- TCP communication using IPv4.
- Server connection management.
- Message transmission between client and server.
- Socket address reuse using SO_REUSEADDR.
- Basic socket error handling.

## Technologies

C, Linux, GCC, TCP/IP, Socket Programming

## How to Run

Compile both programs:

```bash
gcc server.c -o server
gcc client.c -o client
```

Start the server:

```bash
./server 8001
```

Run the client in another terminal:

```bash
./client 8001
```

## What I Learned

This project helped me understand TCP connections, socket APIs, and client-server communication.
