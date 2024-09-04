# Digital Design

---

Topic: Digital Design

Author: Pranaov S

Lecturer: Mr. Dinesh Ganesan

Subject Code: CS1703

---

## Digital and Analog quantities

Analog signals continues with respect to time and amplitude.

These naturally occurring signals are captured and are converted to electric signals using a device called the __Transducer__.

Analog (continuous) $\rightarrow$ Discrete time signals $\rightarrow$ Digital signals (discrete time and amplitude)

### Conversion

| Decimal | Binary | Octal | Hexadecimal |
| --------------- | --------------- | --------------- | --------------- |
| 00 | 0000 | 00 | 0 |
| 01 | 0001 | 01 | 1 |
| 02 | 0010 | 02 | 2 |
| 03 | 0011 | 03 | 3 |
| 04 | 0100 | 04 | 4 |
| 05 | 0101 | 05 | 5 |
| 06 | 0110 | 06 | 6 |
| 07 | 0111 | 07 | 7 |
| 08 | 1000 | 08 | 8 |
| 09 | 1001 | 09 | 9 |
| 10 | 1010 | 10 | A |
| 11 | 1011 | 11 | B |
| 12 | 1100 | 12 | C |
| 13 | 1101 | 13 | D |
| 14 | 1110 | 14 | E |
| 15 | 1111 | 15 | F |

The number of digits required to store a decimal number in binary form is $2^{n}$ (n = number of digits in the binary form)

To represent the decimal number 7 in binary, we need $2^{3} = 8$ digits ($7_{10} = 111_{2}$)

> Decimal to Hexadecimal and Decimal to Octal is similar to Decimal to Binary
but with denominators of 16 and 8 respectively.

Example:

1. Convert $1121_{10}$ to binary

| Number | Quotient | Remainder |
| --------------- | --------------- | --------------- |
| 1121 | 560 | __1__ |
| 560 | 280 | __0__ |
| 280 | 140 | __0__ |
| 140 | 70 | __0__ |
| 70 | 35 | __0__ |
| 35 | 17 | __1__ |
| 17 | 8 | __1__ |
| 8 | 4 | __0__ |
| 4 | 2 | __0__ |
| 2 | __1__ | __0__ |

Hence $1121_{10} = 10001100001_{2}$

2. Convert $62276_{8}$ to decimal

$$
62276_{8} = 6 \times 8^{4} + 2 \times 8^{3} + 2 \times 8^{2} + 7 \times 8^{1} + 6 \times 8^{0}\\
= 6 \times 4096 + 2 \times 512 + 2 \times 64 + 7 \times 8 + 6 \times 1\\
= 24576 + 1024 + 128 + 56 + 6\\
= 25790_{10}\\~\\

\therefore 62276_{8} = 25790_{10}
$$

3. Convert $01011101_{2}$ to Hexadecimal

> Group numbers in sets of 4 and convert to Hexadecimal via Decimals

$$
01011101_{2}\\

\underline{0101}~\underline{1101} \\
= \underline{5_{10}}~\underline{13_{10}} \\
= \underline{5_{16}}~\underline{D_{16}} \\
= 5D _{16}
$$

4. Convert $10110110{2}$ to Octal

> Group numbers in sets of 3 and convert to Octal via Decimals

$$
10110110_{2}\\

\underline{010}~\underline{110}~\underline{110} \\
\underline{2_{10}}~\underline{6_{10}}~\underline{6_{10}} \\
\underline{2_{8}}~\underline{6_{8}}~\underline{6_{8}} \\
= 266_{8}

$$

5. Convert $23.24_{10}$ to binary

$$
23.24_{10}\\
= 23_{10} + 0.24_{10}\\
= 10111_{2} + \\~\\
\implies 0.24 \times 2=  \textbf{0}.48 \rightarrow 0\\
0.48 \times 2 = \textbf{0}.96 \rightarrow 0\\
0.96 \times 2 = \textbf{1}.92  \rightarrow 1 \implies 1.92 - 1 \\
0.92 \times 2 = \textbf{1}.84 \rightarrow 1 \implies 1.84 - 1 \\
0.84 \times 2 = \textbf{1}.68 \implies 1.68 - 1\\
\vdots \\~\\

\implies 23.24_{10} = (10111.00111\dots)_{2}
$$

## Binary Arithmetic

### Addition

$$

0 + 0 = 0\\
0 + 1 = 1\\
1 + 0 = 1\\
1 + 1 = 10 (\textrm{1 is carry})\\

$$

### Subtraction

$$
0-0 = 0\\
1-0 = 1\\
1-1 = 0\\
0-1 = 11 (borrowed)

$$

## Logic Gates

### 1. NOT Gate

| A | $\bar A$ |
| -------------- | --------------- |
| 1 | 0 |
| 0 | 1 |

$A \rightarrow \bar A$

> CMOS is the commonly used NOT gate.
CMOS: Complementary Metal Oxide Semiconductor

### 2. AND Gate

| A | B | $A \cdot B$ |
| --------------- | --------------- | --------------- |
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

### 3. OR Gate

| A | B | $A+B$ |
| --------------- | --------------- | --------------- |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

### 4. NOR Gate

| A | B | $\overline{(A+B)}$ |
| --------------- | --------------- | --------------- |
| 0 | 0 | 1 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 0 |

### 5. NAND Gate

| A | B | $\overline{(A \cdot B)}$ |
| --------------- | --------------- | --------------- |
| 0 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

### 6. XOR  Gate

| A | B | $A \bigodot B$ |
| --------------- | --------------- | --------------- |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

$A \bigodot B = \bar AB + \bar BA$

### 7. XNOR Gate

| A | B | $A \bigoplus B$ |
| --------------- | --------------- | --------------- |
| 0 | 0 | 1 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

$A \bigoplus B = AB + \bar A \bar B$

## Binary Simplification

1. $AA + AB + AC + BC$

$$
AA + AB + AC + BC \\
= A + AC + AB + BC\\
= A(1+C) + AB + BC\\
= A + AB + BC\\
= A(1+B) + BC\\
= A + BC
$$

2. $A + \bar AB$

$$
A + \bar AB\\
= A + AB + \bar AB~(\because A = A+B + A(1+B))\\
= A + B(A + \bar A)\\
= A + B

$$

## Complements

### 1's Complement

To find 1's complement, invert the digits

$101 \rightarrow 010$

$$(2^{n}-1)-N\\(n-\textrm{Number of bits, N = number)}$$

### 2's Complement

To find 2's complement, do $\textrm{(1's complement)} + 1$

$101 \rightarrow 010 \rightarrow 011$

#### Shortcut

1. Read from right
2. Retail last digit
3. Retain digits till the first $1$ appears
4. Flip all bits after the first $1$

Example:

110100 -> 001100

## Signed numbers

The MSB is the signed bit.

### Signed Magnitude

MSB = 0 for positive numbers.

MSB = -1 for negative numbers.

> Note: This method only represents numbers till $-(2^{n}-1)$

## Conversion from one number system to another

| Decimal Digit | 8-4-2-1 Code (BCD) | 6-3-1-1 Code | Excess Code | Gray Code |
| --------------- | --------------- | --------------- | --------------- | --------------- |
| 0 | 0000 | 0000 | 0011 | 0000 |
| 1 | 0001 | 0001 | 0100 | 0001 |
| 2 | 0010 | 0011 | 0101 | 0011 |
| 3 | 0011 | 0100 | 0110 | 0010 |
| 4 | 0100 | 0101 | 0111 | 0110 |
| 5 | 0101 | 0111 | 1000 | 0111 |
| 6 | 0110 | 1000 | 1001 | 0101 |
| 7 | 0111 | 1001 | 1010 | 0100 |
| 8 | 1000 | 1011 | 1011 | 1100 |
| 9 | 1001 | 1100 | 1100 | 1101 |

* Excess-3 code is adding 3 to BCD code
* In gray code, any two successive bits, only one bit is being toggled.
It is more efficient during a physical transition, where energy and time is a constraint.
Hence, the energy loss and time delay is reduced.

## Boolean Expression solving

Boolean Expression: $y = \bar ABC + A\bar B$

$y = f(A,B,C)$

> Any circuits that have memory is called sequential circuits.
Output is going to depend on current input and previous input/output.
There is a feedback mechanism.

> A circuit without memory is called combinational circuit.
There are no feedback inputs.

The current circuit is called combinational logic

### Simplification Theorem

$$
XY + X \bar Y = X \\
X(1+Y) = X \\
XY + \bar Y Y = XY \\
(X + y)(X = \bar Y) = XX + X \bar Y + XY + Y \bar Y = X + X \bar Y + XY \\
X(X + Y) = XX + XY = X(1+Y) = X \\
X \bar Y + Y = X + Y
$$

### De Morgan's Law

De Morgan's law is used to get complement of a logic Expression
$$
y = \overline{(A + B)} \\
\implies y = \bar A \cdot \bar B
$$
2. $\bar AB + \bar A \bar B \bar C \bar D + ABC\bar D$

$$
\bar AB + \bar A \bar B \bar C \bar D + ABC\bar D \\
\bar A B + \bar D(\bar A \bar B \bar C + ABC) \\
\bar A B + \bar D(\bar A \bar B \bar C + ABC) \\
TODO: Solve \\
$$
