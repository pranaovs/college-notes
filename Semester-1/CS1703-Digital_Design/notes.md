# Digital Design

---

Topic: Digital Design

Author: Pranaov S

Lecturer: Mr. Dinesh Ganesan

Subject Code: CS1703

---

## Conversion from one number system to another

| Decimal Digit | 8-4-2-1 Code (BCD) | 6-3-1-1 Code | Excess Code | Gray Code |
| --------------- | --------------- | --------------- | --------------- | --------------- |
| 0 | 0000 |  | 0011 | 0000 |
| 1 | 0001 |  | 0100 | 0001 |
| 2 | 0010 |  | 0101 | 0011 |
| 3 | 0011 |  | 0110 | 0010 |
| 4 | 0100 |  | 0111 | 0110 |
| 5 | 0101 |  | 1000 | 0111 |
| 6 | 0110 |  | 1001 | 0101 |
| 7 | 0111 |  | 1010 | 0100 |
| 8 | 1000 |  | 1011 | 1100 |
| 9 | 1001 |  | 1100 | 1101 |

* Excess-3 code is adding 3 to BCD code
* In gray code, any two successive bits, only one bit is being toggled. It is more efficient during a physical transition, where energy and time is a constraint. Hence, the energy loss and time delay is reduced.

## Boolean Expression solving

Boolean Expression: $y = \bar ABC + A\bar B$

$y = f(A,B,C)$

> Any circuits that have memory is called sequential circuits. Output is going to depend on current input and previous input/output. There is a feedback mechanism.

> A circuit without memory is called combinational circuit. There is no feedback inputs.

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
