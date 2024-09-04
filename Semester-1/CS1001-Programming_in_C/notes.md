# Programming in C

---

Topic: Programming in C

Author: Pranaov S

Lecturer: Mr. Subin Sahayam

Subject Code: CS1001

---

<!--toc:start-->
- [Programming in C](#programming-in-c)
  - [Introduction to C](#introduction-to-c)
    - [Tokens](#tokens)
    - [Compiler and Linker](#compiler-and-linker)
  - [Data](#data)
    - [Data Types](#data-types)
    - [Memory storage](#memory-storage)
  - [Software development life cycle](#software-development-life-cycle)
  - [Algorithm](#algorithm)
    - [Flowchart](#flowchart)
  - [Variable declaration](#variable-declaration)
    - [Syntax](#syntax)
    - [Definitions](#definitions)
      - [Keywords](#keywords)
  - [Library](#library)
  - [Format specifier](#format-specifier)
  - [Print Formatted (`printf`)](#print-formatted-printf)
    - [Syntax](#syntax)
    - [Printing Variables](#printing-variables)
      - [Syntax](#syntax)
<!--toc:end-->

## Introduction to C

### Tokens

**Tokens are the smallest unit in a program**

* Identifiers
* Keywords (32)
* Constants (Literals)
* Strings
* Special symbols/characters
* Operators

### Compiler and Linker

Machine (Binary) <=> Operating System (Object Codes) <=> C Program (Humans)
Compiler and linker are between OS and C Program

## Data

* Data - Raw facts
* Information - Processed meaningful data

### Data Types

1. Basic datatypes

* int
* float
* char
* void
* double
* short
* long
* string

2. Derived datatypes

* Arrays
* Functions
* Pointers
* Unions (`union`)
* Structures (`struct`)

3. Enumeration datatypes

* `enum`

### Memory storage

Memory addresses are stored in hexadecimal

* Binary digit is called a **bit**
* 8 Bits = 1 Byte

First digit of a binary number is called **MSB (Most signifiant bit)**

Last digit of a binary number is called **LSB (Least signifiant bit)**

## Software development life cycle

| Number | Phase | Engineer |
| --------------- | --------------- | --------------- |
| 1 | Analysis | Product Owner, Project Manager, Business Analysist, CTO |
| 2 | Design | System architect, Ui/UX Designer |
| 3 | Development | Front-end developer, Back-end developer |
| 4 | Testing | Solutions Architect, QA Engineer, Tester, DevOps |
| 5 | Deployment | Data Administrator, DevOps |
| 6 | Maintanence | Users, Testers, Support managers|

**Designing is important for software development. Planning is required**

## Algorithm

**An algorithm is a step by step process to solve a problem**
An algorithm is essentially a plan

### Flowchart

Diagrammatic representation of an algorithm

| Column1   | Column2    |
|--------------- | --------------- |
| Oval   | Terminal (Start/Stop)  |
| Rectangle   | Process   |
| Diamond   | Decision   |
| Parallelogram   | Input/Output   |
| Circle | Connector |
| Arrow/Line ---> | Flow Line |

## Variable declaration

* A CPU does processes in the computer
* We can access the CPU using main memory or RAM
* The OS (Kernel) manages the RAM
* To give Input to a computer to perform any operation or process, the program requests memory location from the kernel (OS). It is done with the help of **variable declaration**.

Variables are names of location. They are used to store data. It is used for simplicity since there are so many memory addresses, a human-readable name is given. The kernel manages variable name to address mapping.

### Syntax

`datatype identifier1, identifier2, ..., identifierN;`

### Definitions

An **undefined value** is returned when a variable is accesses without assigning a value.

Assigning a value to an empty variable is called a **Initialization Statement**

Assigning a new value to a variable is called **Assignment Statement**

`=` is called the **Assignment Operator**

```c
int num1,num2 = 15; //Assignment, Initialization
float num3
num1 = 5 //Initialization
```

#### Keywords

1. `int` - 4 bytes (32 bits)
2. `float` - 4 bytes (32 bits)
3. `char` - 1 byte (8 bits)
4. `double` - 8 bytes (64 bits)

## Library

Library is a set of programs written by someone else (or even personally). It is used to de-duplicate and reduce boilerplate code, by abstracting complex code.

Also know as the __Header File__.
__stdio.h__ - Standard Input/Output. Contains `printf` and `scanf`.

To add a library to a program, use the `include` keyword.

__Syntax__

```c
#include <headerFile.h>

int main() {
  return 0;
}
```

A program starts execution at the `main()` function.

## Format specifier

A format specifier is a way to present data.

| Format specifier   | Data type    |
|--------------- | --------------- |
| %d   | Integers   |
| %f   | Float   |
| %c   | Characters   |
| %s   | Strings   |
| %p | Memory Addresses (Pointers) |
| %x | Hexadecimal values |


## Print Formatted (`printf`)

`printf` is an _identifier_.

### Syntax

```c
#include <stdio.h>

int main() {
  printf("Hello, World!");
  return 0;
}
```

It returns the number of characters printed, or returns negative value if failed.

### Printing Variables

To print variables, we specify `printf` and pass in the format string and argument list (variables) as arguments.

#### Syntax

```c
#include <stdio.h>

int main() {
  int a = 10;

  printf("Hello, World!\n%d", a);
  return 0;
}
```

> `\` is called an escape sequence. It is used to escape normal operation and modify. Example, `\n` is used to print a newline. `\\` is used to insert literal `\`.
