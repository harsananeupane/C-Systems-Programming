# C Systems Programming

A collection of projects developed as part of my Systems Programming coursework at the **University of North Texas**. These projects explore C programming, low-level data representation, memory management, Linux command-line tools, and text processing.

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

---

### 3. Regular Expression Text Processing

A Linux command-line project that uses regular expressions to search a text dataset and extract structured information.

#### Tasks Completed

- Extracted email-like patterns
- Identified lines containing numerical data
- Extracted Unix-style file paths
- Identified dates using `/` and `-` separators
- Redirected extracted results into separate output files

#### Concepts Practiced

- Regular expressions (Regex)
- Pattern matching
- Linux command-line processing
- `egrep`
- File redirection
- Text processing
- Structured data extraction
- Terminal session recording

#### Example

```bash
egrep '[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}' datafile.txt > emails.txt
```

This searches the dataset for email-like patterns and stores matching lines in `emails.txt`.

[View Regex Text Processing Project](./regex-text-processing)

---

## Technologies & Tools

- C
- Linux
- GCC
- Bash
- Command Line
- Regular Expressions (Regex)
- `egrep`
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
- Regular expressions and pattern matching
- Command-line text processing
- File redirection
- Structured data extraction
- Low-level problem solving

## Project Structure

```text
C-Systems-Programming/
│
├── README.md
├── ascii_bits.c
├── xor_swap.c
│
└── regex-text-processing/
    ├── README.md
    └── regex_commands.sh
```

## What I Learned

These projects strengthened my understanding of systems programming and how software interacts with data and memory at a lower level.

Through the C programming exercises, I gained hands-on experience with **bitwise operations, binary data representation, pointers, dynamic memory allocation, and memory management** using `malloc()` and `free()`.

I also developed experience working in a **Linux command-line environment**, including compiling and testing programs, designing regular expressions, processing text data, redirecting command output, and extracting structured information from larger datasets.

As I continue my Systems Programming coursework, I plan to expand this repository with selected exercises that demonstrate new concepts and technical skills.
