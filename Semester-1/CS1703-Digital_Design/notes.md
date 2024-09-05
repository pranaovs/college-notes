# Digital Design

<!--toc:start-->
- [Digital Design](#digital-design)
  - [Processes involved in recording and playing back sound](#processes-involved-in-recording-and-playing-back-sound)
  - [Sampling](#sampling)
  - [Digital and Analog quantities](#digital-and-analog-quantities)
    - [Conversion](#conversion)
  - [Binary Arithmetic](#binary-arithmetic)
    - [Addition](#addition)
    - [Subtraction](#subtraction)
  - [Logic Gates](#logic-gates)
    - [1. NOT Gate](#1-not-gate)
    - [2. AND Gate](#2-and-gate)
    - [3. OR Gate](#3-or-gate)
    - [4. NOR Gate](#4-nor-gate)
    - [5. NAND Gate](#5-nand-gate)
    - [6. XOR  Gate](#6-xor-gate)
    - [7. XNOR Gate](#7-xnor-gate)
  - [Binary Simplification](#binary-simplification)
  - [Complements](#complements)
    - [1's Complement](#1s-complement)
    - [2's Complement](#2s-complement)
      - [Shortcut](#shortcut)
  - [Signed numbers](#signed-numbers)
    - [Signed Magnitude](#signed-magnitude)
    - [Signed binary arithmetic examples](#signed-binary-arithmetic-examples)
  - [Conversion from one number system to another](#conversion-from-one-number-system-to-another)
  - [Boolean Expression solving](#boolean-expression-solving)
    - [Simplification Theorem](#simplification-theorem)
    - [De Morgan's Law](#de-morgans-law)
      - [Examples](#examples)
<!--toc:end-->

---

Topic: Digital Design

Author: Pranaov S

Lecturer: Mr. Dinesh Ganesan

Subject Code: CS1703

---

### Processes involved in recording and playing back sound

- Signal Acquisition - conversion from acoustic signal to electrical signal by a  electrical signal is still continuous Microphone, from a class of devices known as a Transducer - a device that converts energy from one form to another.
- Filtering - Noise removal by software
- Analog to Digital Conversion - Electrical signal is converted to a Digital signal by an ADC (Analog to Digital Converter) Digital signals are discrete packets of energy.
- Conversion is necessary to store the signal on a device as analog signals have infinitely many points with varying energies. Samples are taken from the analog signal and is then converted to a digital signal to be stored and played back.
- Storage - The digital signal is stored as a discrete series of 0s and 1s
- Digital to Analog Conversion - Digital signal is converted into an Electrical signal by a DAC (Digital to Analog Converter) via interpolation.
- Playback - The electrical signal is played via a loudspeaker.
  
### Sampling

A set of points are taken for sampling and the required number of bits are assigned to represent the corresponding amplitude. Each bit represent the amplitude as a voltage.

Nyquist's theorem governs the no. of sample points that should be taken in order for the signal that is converted back to not be distorted. it states that "**a periodic signal must be sampled at more than twice the highest frequency component of the signal**". In practice, because of the finite time available, a sample rate somewhat higher than this is necessary. A sample rate of 4 per cycle at oscilloscope bandwidth would be typical.

In an actual circuit, there are 4 possible levels and not just 2, namely - 0, 1, unknown, high impedance.

## Digital and Analog quantities

Analog signals continues with respect to time and amplitude.

These naturally occurring signals are captured and are converted to electric signals using a device called the **Transducer**.

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
| 08 | 1000 | 10 | 8 |
| 09 | 1001 | 11 | 9 |
| 10 | 1010 | 12 | A |
| 11 | 1011 | 13 | B |
| 12 | 1100 | 14 | C |
| 13 | 1101 | 15 | D |
| 14 | 1110 | 16 | E |
| 15 | 1111 | 17 | F |

The number of digits required to store a decimal number in binary form is $2^{n}$ (n = number of digits in the binary form)

To represent the decimal number 7 in binary, we need $2^{3} = 8$ digits ($7_{10} = 111_{2}$)

> Decimal to Hexadecimal and Decimal to Octal is similar to Decimal to Binary
but with denominators of 16 and 8 respectively.

Example:

1. Convert $1121_{10}$ to binary

| Number | Quotient | Remainder |
| --------------- | --------------- | --------------- |
| 1121 | 560 | **1** |
| 560 | 280 | **0** |
| 280 | 140 | **0** |
| 140 | 70 | **0** |
| 70 | 35 | **0** |
| 35 | 17 | **1** |
| 17 | 8 | **1** |
| 8 | 4 | **0** |
| 4 | 2 | **0** |
| 2 | **1** | **0** |

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

| +N | Positive Integers | -N | Signed Magnitude | 1's complement | 2's complement |
| --------------- | --------------- | --------------- | --------------- | --------------- | --------------- |
| +0 | 0000 | -0 | 1000 | 1111 | 0000 |
| +1 | 0001 | -1 | 1001 | 1110 | 1111 |
| +2 | 0010 | -2 | 1010 | 1101 | 1110 |
| +3 | 0011 | -3 | 1011 | 1100 | 1101 |
| +4 | 0100 | -4 | 1100 | 1011 | 1100 |
| +5 | 0101 | -5 | 1101 | 1010 | 1011 |
| +6 | 0110 | -6 | 1110 | 1001 | 1010 |
| +7 | 0111 | -7 | 1111 | 1000 | 1001 |

> 2's complement is better as it has the same representation for +0 and -0 hence prevents ambiguity.

### Signed binary arithmetic examples

1. $(+3)_{10} + (+4)_{10}$

$$
~~ ~~ 011\\
~+ 100\\
= 111\\~\\

\implies 111_{10} = 7_{2}

$$

2. $(-3) + (-4)$

$$

\textrm{Convert to 2's complement (ignoring signed bit)}\\
-3 \rightarrow 1011 \rightarrow 1101\\
-4 \rightarrow 1100 \rightarrow 1100 \\

1101 + 1100 = (1)1001~(\textrm{Discard the overflow bit}) = 1001\\~\\

\textrm{Take 2's complement of answer: } 1001 \rightarrow 1111_{2}\\
1111_{2} = -7_{10}

$$

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

- Excess-3 code is adding 3 to BCD code
- In gray code, any two successive bits, only one bit is being toggled.
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

#### Examples

1. $Z = [A + \bar BC + D + EF][A + \bar BC + \overline{(D + EF)}]$

$$
Z = [a + b][a + \bar b]~(\textrm{where } a = A + \bar BC, b = D + EF)\\
= [aa + a \bar b + ab +  b \bar b]\\
= [a + a \bar b + ab + 0]\\
= a + a[\bar b + b]\\
= [a + a]\\
= a\\
= A + \bar BC
$$
  
2. $\bar AB + \bar A \bar B \bar C \bar D + ABC\bar D$

$$
\bar AB + \bar A \bar B \bar C \bar D + ABC\bar D \\
\bar A B + \bar D(\bar A \bar B \bar C + ABC) \\
\bar A B + \bar D(\bar A \bar B \bar C + ABC) \\
TODO: Solve \\
$$
