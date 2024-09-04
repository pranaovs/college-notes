# Linear Algebra

---
Title: Linear Algebra

Author: Pranaov S

Lecturer: Dr. Venugopal

Subject Code: MA1001

---

<!--toc:start-->
- [Linear Algebra](#linear-algebra)
  - [Binary operations](#binary-operations)
    - [Properties of Binary Operations](#properties-of-binary-operations)
      - [1. Closure Property](#1-closure-property)
      - [2. Commutative property](#2-commutative-property)
      - [3. Associative Property](#3-associative-property)
      - [4. Distributive Property](#4-distributive-property)
      - [5. Identity Property](#5-identity-property)
      - [6. Inverse property](#6-inverse-property)
  - [Semigroup](#semigroup)
    - [Example](#example)
      - [__Let A = ${1,3,5, ...}$, the set of all odd positive integers and the binary operations * is usual multiplication. Is $(A, *)$ is a semigroup?__](#let-a-135-the-set-of-all-odd-positive-integers-and-the-binary-operations-is-usual-multiplication-is-a-is-a-semigroup)
  - [Moniod](#moniod)
  - [Group](#group)
    - [Examples](#examples)
  - [Abelian Group](#abelian-group)
    - [Examples](#examples)
    - [Not abelian group examples](#not-abelian-group-examples)
  - [Ring](#ring)
    - [Examples](#examples)
  - [Field](#field)
    - [Examples](#examples)
  - [Scalars and Vectors](#scalars-and-vectors)
    - [Scalar](#scalar)
    - [Vector](#vector)
    - [Graphical representation of a Vector](#graphical-representation-of-a-vector)
    - [Matrix representation of a Vector](#matrix-representation-of-a-vector)
    - [Addition of Vectors](#addition-of-vectors)
    - [Multiplication of a Vector by a scalar](#multiplication-of-a-vector-by-a-scalar)
  - [Vector Space](#vector-space)
    - [Examples](#examples)
    - [Subspace](#subspace)
      - [Single point criterion](#single-point-criterion)
        - [Proof](#proof)
    - [Linear combination and linear systems of equations](#linear-combination-and-linear-systems-of-equations)
<!--toc:end-->

## Binary operations

> A Set is a collection of well defined objects

Let $S$ be a non empty set, then $*$ is said to be a binary operation on $S$, if $a*b$ is defined for all $a,b$ in $S$.
That is, Binary operation $*$ is a rule defined by $S*S \rightarrow S$

1. Denoted by $(S,*)$
2. Some of the binary operations are: Addition $(+)$, Subtraction $(-)$, Multiplication $(\times)$, Division $(\div)$. Combination of the above are also binary operations.

### Properties of Binary Operations

#### 1. Closure Property

An operation $*$ on a non-empty set $A$ has closure property, if $a,b \in A \implies a * b \in A$.

Example: $(N, +) ~ \forall ~ (a,b) \in N$

#### 2. Commutative property

A binary operation on $*$ non-empty set $A$ is commutative if $a*b = b*a ~\forall~ a,b \in A$.

Example: Let $a,b \in N$, $(N, +)$ is commutative but $(N, -)$ is not.

#### 3. Associative Property

A binary operation $*$ on a non-empty set $A$ is Associative if $a*(b*c) = (a*b)*c$.

Example: Let $a,b,c \in N$, $a*(b*c) = (a*b)*c$ if $(* = +$ or $\times)$

#### 4. Distributive Property

Let $+$ and $\times$ be two binary operations defined on a non-empty set $A$. Then binary operations are distributive if:

$$
a \cdot (b + c) = a \cdot b + a \cdot c
\\
\text{(or)}
\\
(b+c) \cdot a = b \cdot a + c \cdot a
$$

#### 5. Identity Property

Let $A$ be a non-empty set and $*$ be the binary operation on $A$. An element $e$ is the identity element on set $A$ if $a*e = e*a=a ~\forall~ a \in A$.

Example:

1. $(N, +)$ does not satisfy identity property as $0 \notin N$
2. $(N, \times)$ satisfies identity property as $1 \in N$
3. $(N, \div)$ does not satisfy identity property

#### 6. Inverse property

Let $A$ be a non-empty set and $*$ be the binary operation on $A$. An element $b$ is said to be the inverse element of $a \in A$ if $a*b = b*a = e ~\forall~ a,b \in A$

We can write $b$ as $a^{-1}$

$a * a^{-1} = a^{-1}*a = e$

## Semigroup

__A nonempty set $S$ together with a binary operation $*$ defined on it, is said   to be a semigroup if the following properties are satisfied:__

1. $a * b \in G, \forall a,b \in G$ (Closure property)
2. $(a *b)* c = a *(b* c), \forall a,b,c \in G$ (Associative property)

__Note: It is denoted by $(S, *)$__

### Example

#### __Let A = ${1,3,5, ...}$, the set of all odd positive integers and the binary operations * is usual multiplication. Is $(A, *)$ is a semigroup?__

Closure property: multiplication of two positive odd integers is again a positive odd integer.
Associative property: Clearly $(a*b)*c = a*(b*c) ~\forall~ a,b,c \in A$

Therefore $(A, *)$ is a semigroup.

## Moniod

__A non empty set M is said to be a Moniod with respect to binary operation $*$ if:__

1. a * b $\in$ G, $\forall$ a,b $\in$ G (Closure property)
2. $(a *b)* c = a *(b* c) ~\forall~ a,b,c \in G$ (Associative property)
3. For every $a \in M$, there exists an element $e \in M$ (called identity) such that $a*e = e*a = a$ (Identity property satisfied)

__Note:__

- A semigroup satisfying identity property is called a Moniod.
- Denoted be $(M, *)$

## Group

__A non empty set $M$ is said to be a Moniod with respect to binary operation $*$ if:__

1. $a * b \in G ~\forall~ a,b \in G$ (Closure property)
2. $(a *b)* c = a *(b* c) ~\forall~ a,b,c \in G$ (Associative property)
3. For every $a \in M$, there exists an element $e \in M$ (called identity) such that $a *e = e* a = a$ (Identity property satisfied)
4. For every $a \in G$, there exists an element $a^{-1} \in G$, such that $a * a^{-1} = a^{-1} * a = e$ (Existence of inverse)

- Note: It is denoted be $(G, *)$

### Examples

1. Set of integers Z with usual addition $(+)$:
    1. Closure satisfied $(Z1 + Z2 = Z3 ~\forall~ Z3 \in G)$
    2. Associative property satisfied
    3. Identity exists (0)
    4. Inverse exists (-Z)

Hence the set of integers $Z$ is a group with usual addition binary operation $(Z, +)$

2. Set of real numbers R with usual addition (+):
    1. Closure satisfied $(R1 + R2 = R3 ~\forall~ R3 \in G)$
    2. Associative property satisfied
    3. Identity exists (0)
    4. Inverse exists (-R)

Hence the set of real numbers $R$ is a group with usual addition binary operation $(R, +)$

3. Set of non-zero real numbers $R$ $(R*= R - \{0\})$ with usual multiplication $(*)$:
    1. Closure satisfied $(R1 * R2 = R3 ~\forall~ R3 \in G)$
    2. Associative property satisfied
    3. Identity exists (1)
    4. Inverse exists $(\frac{1}{R})$

Hence the set of non-zero real numbers $R$ $(R~*= R - \{0\})$ is a group with usual multiplication binary operation $(R,*)$

4. Set of real numbers R with usual multiplication (*):
    1. Closure satisfied $(R1 * R2 = R3 ~\forall~ R3 \in G)$
    2. Associative property satisfied
    3. Identity exists (1)
    4. Inverse does not exist $(\frac{1}{R}$ where $R = 0$, $\frac{1}{0}$ is not defined)

Hence the set of real numbers R is __not__ a group with usual multiplication binary operation (R, *). But it is a moniod.

5. Set of natural numbers N, with usual addition (+):
    1. Closure satisfied $(N1 + N2 = N3 ~\forall~ N3 \in G)$
    2. Associative property satisfied
    3. Identity does not exist $(0 \notin N)$
    4. Inverse does not exists $(-N \notin N)$

Hence the set of natural numbers N is __not__ a group with usual multiplication binary operation $(N, *)$. But it is a semigroup.

## Abelian Group

__A group $(G,*)$ is said to be an Abelian group or commutative group if $a* b = b * a$, for ever $a,b \in G$.__

### Examples

1. $(Z,+)$, $(Q, +)$, $(R, +)$, $(C, +)$ are abelian group.
2. Set of non real numbers for multiplication.
3. Set of non zero, Integers, Rational numbers for multiplication.

### Not abelian group examples

1. The set of square matrices of order $n$, with matrix multiplication $(I_{n \times n}, \times)$. Matrix multiplication is not commutative. Hence it is not an abelian group.

## Ring

__A non empty set $R$ is said to be a ring with two binary operations, $+$ and $\cdot$ , called *addition* and *multiplication*, respectively, such that:__

1. $(R, +)$ is an abelian group
2. Multiplication is associative
3. Left and right distributive laws hold

- Note: A ring in with the multiplicative operation is commutative, it is called commutative ring.

### Examples

1. $(Z; +, \cdot)$, $(Q; +, \cdot)$, $(R; +, \cdot)$, $(C; +, \cdot)$
2. $N$ is __not__ a ring for usual addition and multiplication: There is no additive identity element, $0 \notin N$

<!-- TODO: b. Multip... -->

## Field

__A non empty set F with at least two elements and two binary operations ($+$) and ($\cdot$), such that:__

1. $(F, +)$ is an abelian group
2. $(F - \{0\}, \cdot)$ is an abelian group
3. Distributive laws hold

### Examples

1. Set of non-zero real numbers $R$, with usual addition ($+$) and multiplication ($\cdot$)
2. Set $Z$ is not a field. Inverse property does not satisfy. But it is a ring.

## Scalars and Vectors

### Scalar

A quantity that has only magnitude but no direction is known as a scalar. Example: Speed, Distance.

### Vector

A quantity that has both magnitude and direction is known as a vector. Example: Velocity, Displacement.

### Graphical representation of a Vector

Vectors are graphically represented by an arrow or a directed line segment.
The length of the arrow indicated the magnitude of the vector and the direction pointed by the head is the direction of the vector.

### Matrix representation of a Vector

An object moving 5 km/h in East direction: $\begin{bmatrix}5 \\0\end{bmatrix}$

$\bar a = (x, y) = \begin{bmatrix}x\\y\end{bmatrix}$

A set of numbers written in row form $(\begin{bmatrix}x&y\end{bmatrix})$ or column form $(\begin{bmatrix}x\\y\end{bmatrix})$ is said to be a *Row Vector* or *Column Vector*.

The integral numbers in the vector are called *components* or *entry* or *elements*.

A vector having $n$ elements is called *n-dimensional vector* or *n-tuple*.

### Addition of Vectors

To add two vectors, we have to add the corresponding elemetns of the vector, i.e. if $\bar x = (x_{1}, x_{2})$ and $\bar y = (y_{1}, y_{2})$, then $\bar x + \bar y = (x_{1}+ y_{1}, x_{2}+ y_{2})$

Example:

$$
\bar x = (4, -3)\\
\bar y = (-2, -5)\\
\\
\bar x + \bar y = (4 + (-2), -3 + (-5))\\
\bar x + \bar y = (2, -8)
$$

### Multiplication of a Vector by a scalar

To multiply a vector by a scalar multiplying the scalar to each components.

If $\bar x = (x_{1} + x_{2})$, then $\alpha x = (\alpha x_{1}, \alpha x_{2})$, where $\alpha$ is a scalar.

Example:
$$
\bar x = (3,5) \\
4 \bar x = (4 \times 3, 4 \times 5) \\
4 \bar x = (12, 20)\\
|\bar x| = \sqrt{3^{2} + 5^{2}} \\
|4 \bar x| = \sqrt{12^{2} + 20^{2}} = \sqrt{544} = \sqrt{14\times 34}  \\
= 4\sqrt{34}
$$

Multiplication of a vector by a scalar by $\alpha$ times increasing the magnitude of vector (by $\alpha$ times)

__Note:__

1. By multiplying a vector by minus $(-)$ sign, its direction is inverted.
2. Scalar multiplication is just scaling a vector.

## Vector Space

It is a set of vectors with rules for vector addition and scalar multiplication.

__Definition:__ A non empty set $V$ is said to be a vector space over a field $F$ if there are 2 binary operators (Vector Addition and Scalar Multiplication) satisfying the following properties:

Let $x,y,z \in V$ and $\alpha,\beta \in F$

1. __For vector addition:__
    1. Closure property

    $$x,y \in V \implies x + y \in V$$

    2. Associative property

    $$(x+y)+z = x + (y+z)$$

    3. Commutative property

    $$x + y = y + x$$

    4. Existence of Identity

    $$\textrm{There exists identity element } 0 \in V \textrm{ such that } x + 0 = 0 + x = x \textrm{ for all } x \in B$$

    5. Existence of Inverse

    $$~\forall~a\in B, \exist (-a) \textrm{ in } B\\ \ni a + (-a) = (-a) + a = 0$$

2. __For Scalar Multiplication__

    1. Closure property
    $$\alpha \in F,~x \in V\\\implies\alpha x \in V $$

    2. Distributive property (1)
    $$\alpha (x + y) = \alpha x + \alpha y$$

    3. Distributive property (2)
    $$(\alpha + \beta)x = \alpha x + \beta x$$

    4. Associative property
    $$(\alpha \beta) x = \alpha (\beta x)$$

    5. Unitary property

    $$1 \cdot x = x ~\forall~ 1 \in F ~\&~ x \in B$$

__Note:__

1. The vector space $B$ over a field $F$ is denoted as $B(F)$
2. Also known as *Linear Space*
3. The elements of the field are scalar the elements of vector space $V$ are vectors.

#### Examples

1. Prove that the set $V_n(F)$ of all ordered n-tuples of all elements is a vector space with respect to vector addition and scalar multiplication component wise.

$$
\textrm{Let }x,y,z \in R^{n} \\

\implies x = (x_{1}, x_{2}, x_{3} \dots x_{n} )~\&\\
y = (y_{1}, y_{2}, y_{3}\dots y_{n})~\&\\
z = (z_{1}, z_{2}, z_{3}\dots z_{n} ) \\

\textrm{and let } \alpha,\beta \in F\\
~\\
x + y = (x_{1}, x_{2}, x_{3} \dots x_{n} ) + (y_{1}, y_{2}, y_{3} \dots y_{n} ) \\
\implies (x_{1} + y_{1}) + (x_{2}  + y_{2}) + \dots + (x_{n} + y_{n})\\
~\\
\textrm{Scalar Multiplication is defined as, }\\
\alpha x = \alpha x_{1} + \alpha x_{2} + \alpha x_{3} + \dots + \alpha x_{n}\\
~\\

\textrm{\textbf{Vector Addition}}\\~\\
\textrm{1. Closure property}\\
x + y = (x_{1} + y_{1}, x_{2} + y_{2}, \dots, x_{n} + y_{n}) \in R^{n} \\
\therefore \textrm{Closure property is satisfied}\\~\\

2. \textrm{ Associative property}\\
x + (y + z) = (x_{1} ,x_{2}, \dots, x_{n}) + (y_{1} + z_{1}, y_{2} + z_{2}, \dots, y_{n} + z_{n})\\
= x_{1} + (y_{1} + z_{1}) + x_{2} + (y_{2}+z_{2}) + \dots + x_{n} + (y_{n} + z_{n}) \\
= ((x_{1}+y_{1})+ z_{1}) + (x_{2} + (y_{2} + z_{2})) + \dots + (x_{n} + (y_{n} + z_{n})) \\
= (x_{1} + y_{1}, x_{2}+ y_{2}, x_{3}+ y_{3} + \dots + x_{n} + y_{n} ) + (z_{1} + z_{2} + z_{3} + \dots + z_{n}) \\
= (x + y) + z\\
\therefore \textrm{Associative property satisfied} \\~\\

3. \textrm{ Commutative property}\\
x + y = (x_{1} + y_{1}, x_{2} + y_{2}, x_{3} + y_{3} + \dots + x_{n} + y_{n})\\
(y_{1} + x_{1}, y_{2}+ x_{2}, y_{3}+ y_{3} + \dots + y_{n} + x_{n})\\
= y + x\\
\therefore \textrm{Commutative property satisfied} \\~\\

4. \textrm{ Identity property}\\
\textrm{For every element }x = (x_{1}, x_{2}, x_{3}, \dots, x_{n}) \in R^{n}, \textrm{there exists }\\
x + 0 = (x_{1}+0, x_{2}+0, x_{3}+0, \dots, x_{n} + 0) \\
= (x_{1} + x_{2} + x_{3} + \dots + x_{n}) = x \\

\textrm{Similarly: } 0 + x = x\\

\therefore \textrm{Identity property is satisfied}\\
0 = (0, 0, 0, \dots, 0)\textrm{ is said to be null vector/identity element} \\~\\

5. \textrm{ Inverse property}\\

\textrm{For every element } x = (x_{1}, x_{2}, x_{3}, \dots, x_{n}) \in R^{n}\\
\textrm{There exist } -x = (x_{1}, x_{2}, \dots, x_{n}) \in R^{n}\\
\textrm{Such that: } x + (-x) = 0\\
(x-x_{1}, x-x_{2}, \dots, x-x_{n})\\
= (0,0,\dots, 0)\\
= 0\\

\therefore \textrm{Inverse property exists. It is }0\\~\\

\textrm{\textbf{Scalar multiplication}}\\~\\

1. \textrm{ Closure property}\\
\textrm{Let } \alpha \in F ~\&~x = (x_{1}, x_{2}, x_{3}, \dots, x_{n}) \in R^{n}\\
\textrm{Now, } \alpha x = (\alpha x_{1}, \alpha x_{2}, \alpha x_{3}, \dots, \alpha x^{n}) \in R^{n}\\

\therefore \textrm{Closure property satisfied} \\~\\

2. \textrm{ Distributive property}\\
\textrm{Let } \alpha,\beta \in F ~\&~ x \in R^{n}\\
(\alpha + \beta)x =  (\alpha + \beta)(x_{1},x_{2},\dots, x_{n})\\
= ((\alpha + \beta)x_{1}, (\alpha + \beta) x_{2}, \dots, (\alpha + \beta)x_{n})\\
= (\alpha x_{1} + \beta x_{1}, \alpha x_{2} + \beta x_{2}, \dots, \alpha x_{n} + \beta x_{n})\\
= (\alpha x_{1} + \alpha x_{2} + \dots + \alpha x_{n}) + (\beta x_{1} + \beta x_{2} + \dots + \beta x_{n})\\
= \alpha x + \beta x\\
\therefore \textrm{Distributive property satisfied}\\~\\

3. \textrm{Distributive property}\\
\textrm{Let } \alpha \in F ~\&~ x,y \in R^{n}\\
\alpha(x+y) =  \alpha(x_{1} + y_{1},x_{2} + y_{2},\dots, x_{n} + y_{n})\\
= \alpha (x_{1} + y_{1}), (\alpha  x_{2} + y_{2}), \dots, \alpha (x_{n} + y_{n})\\
= \alpha x_{1} + \alpha y_{1}, \alpha x_{2} + \alpha y_{2}, \dots,  \alpha x_{n} + \alpha y_{n}\\
= \alpha (x_{1} + x_{2} + \dots + x_{n}) + \alpha (y_{1} + y_{2} + \dots + y_{n})\\
= \alpha x + \alpha y\\
\therefore \textrm{Distributive property satisfied}\\~\\

4. \textrm{ Associative property}\\
\textrm{Let }\alpha, \beta ~\&~ x \in R^{n}\\

(\alpha \beta)x = [\alpha \beta](x_{1},x_{2}, \dots x_{n})\\
= [\alpha \beta (x_{1}), \alpha \beta (x_{2}), \dots, \alpha \beta (x_{n})]\\
= [\alpha (\beta x_{1}), \alpha (\beta x_{2}), \dots, \alpha (\beta x_{n})]\\
= \alpha (\beta x_{1}, \beta x_{2}, \dots, \beta x_{n})\\
= \alpha (\beta x)\\
\therefore \textrm{Associative property satisfied}\\~\\

5. \textrm{ Unitary property}
1 \in F ~\&~ x \in R^{n}\\

\textrm{Now, } 1 \cdot x = 1 \cdot (x_{1},x_{2},x_{3}, \dots x_{n})\\
= (1 \cdot x_{1}, 1 \cdot x_{2}, 1 \cdot x_{3}, \dots, 1 \cdot x_{n})
= (x_{1},x_{2},x_{3},\dots, x_{n}) = x\\

\therefore \textrm{Unitary property satisfied}
$$

Since all the properties of vector spaces are satisfied, $R^{n}$ (or) $V_{n}(F)$ is a vector space.

### Subspace

__Definition:__
A subset $W$ of a vector space $V$ over a field $F$ is called a subspace of $V$ if $W$ is a vector space over $F$ with the operations of vector addition and scalar multiplication defined on $V$.

__Note:__

1. $V$ and $V\{0\}$ are called improper or trivial subspaces.
2. $W$ subset of $V$ is called proper subspace of $V$.

__Examples:__

1. $R^{2}$
    1. It is a vector space
    2. Subspace of $R^{2}$

> As $W$ is a subspace of $V$, commutative and associative properties under addition hold good. Also the properties of scalar multiplication $V$ satisfies on $W$. Therefore, to prove $W$ is a subspace of $V$, it is enough to verify closure property, identity property and inverse property (optional).

__Theorem:__

A non empty subset $W$ of a vector space $V$ is a subspace of $V$ only if $W$ is closed under addition and scalar multiplication.

(or)

Let $V$ be a vector space, then $W$ is a subspace of $V$ only if the following 3 conditions hold for the operations defined in V.

1. $0 \in W$
2. $x + y \in W ~\forall~ x,y \in W$
3. $\alpha x \in W ~\forall~ x \in W ~\&~ \alpha \in F$

<!--#### Examples-->
<!---->
<!--1. Check whether the set $W = \{(a_{1}, a_{2}, a_{3}) \in R^{3}: 5 a_{1}^{2}-3a_{2}^{2}+6a_{3}^{2} = 0\}$ is a subspace of $R^{3}$-->
<!---->
<!--    1. $$-->
<!--0 = (0,0,0) \in R^{3}\\-->
<!--\text{Now}~5(0)^{3} - 3(0)^{3} + 6(0)^{3} = 0 \\-->
<!--\therefore 0 \in W-->
<!--$$-->
<!---->
<!--    2. $$-->
<!--\text{Let}~x = (a_{1},a_{2},a_{3})~\&~ y = (b_{1},b_{2},b_{3}) \\-->
<!--\implies 5 a_{1}^{2} - 3a_{2}^{2} + 6a_{3}^{2} = 0\\-->
<!--\&~ 5 b_{1}^{2} - 3b_{2}^{2} + 6b_{3}^{2} = 0\\-->
<!--~\\-->
<!--\text{Now } x + y = (a_{1}, a_{2}, a_{3}) + (b_{1}, b_{2}, b_{3}) \\-->
<!--= ((a_{1} + b_{1}), (a_{2} + b_{2}), (a_{3} + b_{3}))\\-->
<!--5(a_{1} + b_{1})^{2} - 3(a_{2} + b_{2})^{2} + 6(a_{3} + b_{3})^{2}  \\-->
<!---->
<!--\# TODO-->
<!--$$-->
<!---->
<!--2. Let $V = R^{3}$, check whether $W = \{a_{1}, a_{2}, a_{3} \in R^{3}: a_{1} = a_{3}+2\}$ is a vector subspace of $R^{3}$-->
<!---->
<!---->
<!--3. Check whether the set $W = \{(a_{1}, a_{2}, a_{3}) \in R^{3}: a_{1}+2a_{2}+3a_{3} = 0\}$ is a subspace of $R^{3}$-->
<!---->
<!--j-->

#### Single point criterion

A non empty subset, $W \subset V$ is a subspace of $V(F)$ if and only if $\alpha, \beta \in F ~\&~ x,y \in W$, implies $\alpha x + \beta y \in W$

- $W \subset V \iff \alpha, \beta \in F ~\&~ x,y \in W \implies \alpha x + \beta y \in W$

##### Proof

$$
1. \textrm{Part 1}\\~\\
\textrm{Let } W \subset V(f) \textrm{ be a subspace}\\~\\

\textrm{Let }\alpha, \beta \in F ~\&~ x,y \in W\\
\alpha x, \beta y \in W \textrm{ (Closed with respect to scalar multiplication)}\\
\implies \alpha x + \beta y \in W \textrm{ (Closed with respect to vector addition)} \\~\\
\textrm{Converse part}\\
\textrm{Let } \alpha x + \beta y \in W ~\forall~\alpha,\beta \in F ~\&~ x,y \in W \rightarrow 1\\~\\

\textrm{To prove: W is a subspace of V}\\~\\

1. \textrm{Put }\alpha = 0, \beta = 0 \textrm{ in } 1\\
0 \in W ~(\therefore \textrm{ Identity exists})\\~\\

2. \textrm{Put } \alpha = \beta = 2 \textrm{ in } 1\\
x + y \in W ~(\therefore \textrm{ Closed with respect to vector addition})\\~\\

3. \textrm{Put } \beta = 0 \textrm{ in }1\\
\alpha x \in W ~(\therefore \textrm{ Closed with respect to scalar multiplication})\\~\\

\therefore \textrm{W is a subspace of V}\\
\textrm{Hence proved}
$$

### Linear combination and linear systems of equations

Let S be non non empty subset of the vector space $V(F)$.
A vector $v \in V ~\&~ \notin S$ is called a linear combination of vectors of $S$,
if there exists finite vectors that $x_{1},x_{2},x_{3},\dots , x_{n} \in S$ and scalars $\alpha_{1}, \alpha_{2}\, \alpha_{3}, \dots, \alpha_{n}$

$$\sum_{i=1}^{n}\alpha_{i}x_{i}$$

__Note:__

1. Here $\alpha_{1}, \alpha_{2}\, \alpha_{3}, \dots, \alpha_{n}$ are called coefficient of linear combination.
2. In any vector space $V$, $0 \cdot v = 0$ for each $v \in V$, this implies, zero vector can be written as linear combination of non-empty set of vectors of $V$, i.e. $0 = 0 \cdot x_{1} + 0 \cdot x_{2} + \dots + 0 \cdot x_{n}$

__Examples:__

1. Express $x = (1, 7, -4)$ is a linear combination of vectors $x_{1} = (1, -3,4)$ and $x_{2} = (2, -1, 1)$ in a vector space $V_{3}(R)$

$$
\textrm{The linear combination of x in terms of } x_{1} \textrm{ and } x_{2} \textrm{ is: }\\

x = a x_{1} + b x_{2}\\

(1,7,-4) = (a + 2b, -3-b, 2a + b)\\~\\

\textrm{Equating the corresponding components: }\\

1 = a + 2b \rightarrow 1\\
7 = -3a -b \rightarrow 2\\
-4 = 2a + b \rightarrow 3\\~\\

1:~ a + 2b = 1\\
2: ~ 4a + 2b = -8\\~\\

\implies a = -3 \textrm{ and } b = 2\\~\\

\textrm{Substituting } a = -3 \textrm{ and } b = 2 \textrm{ in equation }3 \\

7 = -3(-3) -2 \\
= 9-2 \\
= 7 \textrm{ (Satisfied)} \\~\\

\therefore x \textrm{ can be written as a linear combination with } x_{1} \textrm{ and } x_{2} \textrm{, i.e. } x = -3 x_{1} + 2 x_{2}

$$

__Note:__

1. While solving the system of equations, the values obtained for the coefficients $\alpha_{1}, \alpha_{2}$, must satisfy all the equations, otherwise we say the system is inconsistent (no solution).
In such case, we say linear combination does not exist.
