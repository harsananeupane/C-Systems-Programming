# C Systems Programming

A collection of C programs developed as part of my Systems Programming recitation project at the University of North Texas. These projects explore low-level programming concepts including bitwise operations, binary data representation, pointers, and dynamic memory management in a Linux environment.

## Projects

### 1. ASCII Bits & Bytes

A C program that accepts a printable ASCII character and displays its decimal, hexadecimal, and 8-bit binary representations.

The binary representation is generated manually using bitwise operations rather than a built-in binary conversion function.

#### Concepts Practiced

- ASCII character encoding
- Binary and hexadecimal representation
- Bitwise AND (`&`)
- Bit shifting (`>>`)
- Loops and conditional logic
- Unsigned character data types
- Low-level data representation

#### Example

Input:

```text
A
```

Output:

```text
The ASCII value of A is:
    dec - 65
    hex - 41
    bin -
    01000001
```

---

### 2. XOR Integer Swap

A C program that dynamically allocates memory for two integers and swaps their values using the bitwise XOR operator without using a temporary variable.

#### Concepts Practiced

- Pointers
- Dynamic memory allocation
- `malloc()`
- `free()`
- Memory allocation error handling
- Bitwise XOR (`^`)
- Arrays and pointer-based memory access

#### How the XOR Swap Works

The swap is performed using three XOR operations:

```c
int_ptr[0] = int_ptr[0] ^ int_ptr[1];
int_ptr[1] = int_ptr[0] ^ int_ptr[1];
int_ptr[0] = int_ptr[0] ^ int_ptr[1];
```

This exchanges the values stored in the two memory locations without requiring an additional temporary variable.

#### Example

Input:

```text
571
18
```

Output:

```text
Original values: 1st = 571, 2nd = 18
Swapped values: 1st = 18, 2nd = 571
```

## Technologies & Tools

- C
- Linux
- GCC
- Command Line
- Git
- GitHub

## Concepts Covered

- Systems programming fundamentals
- Bitwise operations
- Binary data representation
- ASCII encoding
- Pointers
- Dynamic memory allocation
- Memory management
- Error handling
- Low-level problem solving

## Project Structure

```text
c-systems-programming/
│
├── README.md
├── ascii_bits.c
└── xor_swap.c
```

## What I Learned

These projects strengthened my understanding of how C interacts with data and memory at a lower level. I gained hands-on experience using bitwise operators to manipulate individual bits, working with pointers and dynamically allocated memory, and managing memory with `malloc()` and `free()`.

I also gained experience compiling, testing, and running C programs in a Linux command-line environment.
