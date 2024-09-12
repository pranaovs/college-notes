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
  - [Pointers](#pointers)
    - [Syntax](#syntax)
  - [Escape Sequence](#escape-sequence)
  - [Operators](#operators)
    - [Expression](#expression)
    - [Operators Precedence](#operators-precedence)
    - [Relational Operators](#relational-operators)
    - [Operators Precedence and Associativity](#operators-precedence-and-associativity)
      - [Left to right](#left-to-right)
      - [Right to left](#right-to-left)
  - [Control Flow](#control-flow)
    - [Simple if](#simple-if)
      - [Syntax](#syntax)
    - [if-else](#if-else)
      - [Syntax](#syntax)
      - [Example](#example)
    - [if-else-if ladder](#if-else-if-ladder)
      - [Syntax](#syntax)
    - [Nested if](#nested-if)
      - [Syntax](#syntax)
    - [switch](#switch)
      - [Syntax](#syntax)
      - [Example](#example)
  - [Looping](#looping)
    - [Increment/Decrement operator](#incrementdecrement-operator)
      - [Example](#example)
        - [Output](#output)
        - [Output](#output)
<!--toc:end-->

## Introduction to C

### Tokens

**Tokens are the smallest unit in a program**

- Identifiers
- Keywords (32)
- Constants (Literals)
- Strings
- Special symbols/characters
- Operators

### Compiler and Linker

Machine (Binary) <=> Operating System (Object Codes) <=> C Program (Humans)
Compiler and linker are between OS and C Program

## Data

- Data - Raw facts
- Information - Processed meaningful data

### Data Types

1. Basic datatypes

- int
- float
- char
- void
- double
- short
- long
- string

2. Derived datatypes

- Arrays
- Functions
- Pointers
- Unions (`union`)
- Structures (`struct`)

3. Enumeration datatypes

- `enum`

### Memory storage

Memory addresses are stored in hexadecimal

- Binary digit is called a **bit**
- 8 Bits = 1 Byte

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

- A CPU does processes in the computer
- We can access the CPU using main memory or RAM
- The OS (Kernel) manages the RAM
- To give Input to a computer to perform any operation or process, the program requests memory location from the kernel (OS). It is done with the help of **variable declaration**.

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

Also know as the **Header File**.
**stdio.h** - Standard Input/Output. Contains `printf` and `scanf`.

To add a library to a program, use the `include` keyword.

**Syntax**

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

---

## Pointers

Pointers are special variables to store addresses.

> Declaration
Telling the computer that you are going to use a variable/memory location with a specific name.

### Syntax

Syntax + Pointer declaration

`datatype *identifier;`

Use `&` to get the address of a variable

`identifier = &var;`

```c
#include<stdio.h>

int main() {
  int a = 5;
  int *b = &a;

  printf("%p\n", b); //prints value of b (memory address of a)
  printf("%p\n", &b); //prints memory address of b
  printf("%d\n", *b); //prints data stored in pointer b (value of a)

  return 0;
}
```

## Escape Sequence

| Escape Sequence   | Description    |
|--------------- | --------------- |
| `\n`   | Newline character   |
| `\t`   | Horizontal Tab   |
| `\a`   | Produces a sound or visible alert   |
| `\\`   | Literal backslash (\\)  |
| `\"` | Literal double quote (") |

## Operators

Symbols that implement mathematical operations.

### Expression

Combination of operands and operators.

- Unary, Binary, Ternary Operators

Types of operators

| Operator | Example |
| -------- | ------- |
| Unary | `++`, `--` |
| Arithmetic | `+`,`-`,`*` |
| Relational | `<`, `>`, `==`, `<=`, `!=` |
| Logical | `&&`, `\|\|`, `!` |
| Assignment | `=`,`+=`,`-=`, `%=` |
| Ternary/Conditional | `?:` |
| Bitwise | `&`,`\|`, `<<`, `^`, `~` |

### Operators Precedence

| Priority | Operator | Operation |
| --------------- | --------------- | --------------- |
| 1 | `()` | Parenthesis |
| 2 | `*` | Multiplication |
| 3 | `/` | Division |
| 4 | `%` | Remainder |
| 5 | `+` | Addition |
| 6 | `-` | Subtraction |
| 7 | `=` | Assignment |

### Relational Operators

| Operator   | Returns `true` if    |
|--------------- | --------------- |
| `==`   | equal   |
| `!=`   | not equal   |
| `<`   | lesser than   |
| `>`   | greater than   |
| `>=`   | lesser than or equal to   |
| `>`   | greater than or equal to  |

### Operators Precedence and Associativity

| Operators | Associativity | Type |
| --------------- | --------------- | --------------- |
| `++` (postfix), `--` (postfix) | right to left | postfix |
| `+` (type), `-` (type), `++` (prefix), `--` (prefix) | right to left | unary |
| `*`, `/`, `%` | left to right | multiplicative |
| `+`, `-` | left to right | additive |
| `<`, `<=`, `>`, `>=` | left to right | relational |
| `==`, `!=` | left to right | equality |
| `?:` | right to left | conditional |
| `=`, `+=`, `-=`, `*=`, `%=` | right to left | assignment |

Refer [Increment/Decrement operator](#incrementdecrement-operator)

#### Left to right

- `()`, `*`, `/`, `%`, `+`, `-`, `<`, `<=`, `>`, `>=`, `==`, `!=`

#### Right to left

- `++`, `--`, `+`, `-`
- `+=`, `-=`, `*=`, `%=`
- `=` (Assignment operator)

## Control Flow

Order in which a program's instructions/statements are executed.

Some statements can decide the control flow, they are called control statements

1. Conditional/Selection
    - `if`,`if-else`,`nested-if`, `switch`
2. Iterative/Looping
    - `do-while`, `while`, `for`
3. Jump
    - `break`, `continue`, `goto`

> & - Reference operator

### Simple if

#### Syntax

```c
if (expression) {
  // Block of statements to execute if expression is true
}
```

**Note:**

- If there is only one statement, `{}` can be ignored

- There is no semicolon in `if` statement. Using a semi-colon, the `if` statement will be terminated.

### if-else

#### Syntax

```c
if (expression) {
  // Block of statements to execute if expression is true
} else {
  // Block of statements to execute if expression if false
}
```

#### Example

Program to check if given number is odd or even.

```c
#include <stdio.h>

int inp;

int main() {

  printf("Enter the number to check for odd or even: ");
  scanf("%d", &inp);

  printf("\n");

  if (inp % 2 == 0)
    printf("%d is an even number\n", inp);
  else
    printf("%d is an odd number\n", inp);

  return 0;
}
```

### if-else-if ladder

#### Syntax

```c
if (expression) {
  // Block of statements to execute if expression1 is true
} else if (expression2) {
  // Block of statements to execute if expression2 is true
} else if (expression3) {
  // Block of statements to execute if expression3 is true
} else {
  // Block of statements to execute if all expressions are false
}
```

### Nested if

#### Syntax

```c
if (expression1) {
  // Code to execute if expression1 is true
  if (expression12) {
    // Code to execute if expression12 is also true
    if (expression123) {
      // Code to execute if expression123 is also true
    }
  }
}
```

### switch

#### Syntax

```c
switch (expression) {
  case value1:
    // Code to execute if expression equals value1
    break;

  case value2:
    // Code to execute if expression equals value2
    break;

  case value3:
    // Code to execute if expression equals value3
    break;

  default:
    // Code to execute if non of the cases match
}
```

#### Example

Write a program to print textual alternatives to 1, 2 and 3 if entered

```c
#include <stdio.h>

int num;

int main() {
  printf("Program to return the textual numbers for 1,2 and 3\n");
  printf("Enter a number: ");
  scanf("%d", &num);

  printf("\n");

  switch (num) {
  case 1:
    printf("One\n");
    break;
  case 2:
    printf("Two\n");
    break;
  case 3:
    printf("Three\n");
    break;
  default:
    printf("Input is not 1, 2 or 3\n");
  }

  return 0;
}
```

**Note:**

- Without using a `break`, the switch case checking does not exit. The `default` code block is always executed in this case.

## Looping

### Increment/Decrement operator

| Operator | Sample Expression | Explanation |
| --------------- | --------------- | --------------- |
| `++` | `++a` | Increment a by 1, and use the new value of a in the expression |
| `++` | `a++` | Use the current value of a for the expression, then increment it by 1 |
| `--` | `--b` | Decrement b by 1, and use the new value of b in the expression |
| `--` | `b--` | Use the current value of b in the operation, then decrement it by 1 |

#### Example

1.

```c
#include <stdio.h>

int num = 3;

int main() {
  printf("Init value of num is: %d\n", num);
  printf("num++ is: %d\n", num++);
  printf("Value of num after num++ is: %d\n", num);
  printf("++num is: %d\n", ++num);
  printf("Value of num after ++num is: %d\n", num);

  return 0;
}
```

##### Output

```txt
Init value of num is: 3
num++ is: 3
Value of num after num++ is: 4
++num is: 5
Value of num after ++num is: 5
```

2.

```c
#include <stdio.h>

int num = 3;
int num2 = 3;
int num3 = 3;
int num4 = 3;
int num5 = 3;

int main() {

  printf("%d\n", num);
  printf("%d\n", num2++);
  printf("%d\n", ++num3);
  printf("%d\n", num4++ + ++num4);
  printf("%d\n", num4);

  int i = num++ + ++num + num++;
  printf("\n%d\n", i);

  return 0;
}
```

##### Output

```txt
3
3
4
8
5

13
```
