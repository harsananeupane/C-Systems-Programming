# Multithreading Performance Optimization

A C program that uses the producer-consumer model to read and display user input. I improved the provided program by implementing condition variables to reduce unnecessary CPU usage.

## Features

- One producer thread and two consumer threads.
- Shared circular buffer.
- Thread synchronization using mutex locks.
- Condition variables to prevent busy waiting.
- Handling of spurious wakeups.

## Technologies

C, Linux, GCC, POSIX Threads (pthread)

## How to Run

```bash
gcc -pthread producer_consumer.c -o producer_consumer
./producer_consumer
```

## What I Learned

This project helped me understand multithreading, thread synchronization, shared memory management, and CPU performance optimization.
