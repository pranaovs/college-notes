# Linear Algebra
## MA1001 - Dr. Venugopal

## Binary operations

> A Set is a collection of well defined objects

Let $S$ be a non empty set, then $*$ is said to be a binary operation on $S$, if $a*b$ is defined for all $a,b$ in $S$.
That is, Binary operation $*$ is a rule defined by $S*S \rightarrow S$

1. Denoted by $(S,*)$
2. Some of the binary operations are: Addition $(+)$, Subtraction $(-)$, Multiplication $(\times)$, Division $(\div)$. Combination of the above are also binary operations.

### Properties of Binary Operations

#### 1. Closure Property:

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

**Note: It is denoted by $(S, *)$**

### Example:

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
* A semigroup satisfying identity property is called a Moniod.
* Denoted be $(M, *)$

## Group

__A non empty set $M$ is said to be a Moniod with respect to binary operation $*$ if:__

1. $a * b \in G ~\forall~ a,b \in G$ (Closure property)
2. $(a *b)* c = a *(b* c) ~\forall~ a,b,c \in G$ (Associative property)
3. For every $a \in M$, there exists an element $e \in M$ (called identity) such that $a *e = e* a = a$ (Identity property satisfied)
4. For every $a \in G$, there exists an element $a^{-1} \in G$, such that $a * a^{-1} = a^{-1} * a = e$ (Existence of inverse)

* Note: It is denoted be $(G, *)$

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

### Examples:

1. $(Z,+)$, $(Q, +)$, $(R, +)$, $(C, +)$ are abelian group.
2. Set of non real numbers for multiplication.
3. Set of non zero, Integers, Rational numbers for multiplication.

### Not abelian group examples:

1. The set of square matrices of order $n$, with matrix multiplication $(I_{n \times n}, \times)$. Matrix multiplication is not commutative. Hence it is not an abelian group.

## Ring

__A non empty set $R$ is said to be a ring with two binary operations, $+$ and $\cdot$ , called *addition* and *multiplication*, respectively, such that:__

1. $(R, +)$ is an abelian group
2. Multiplication is associative
3. Left and right distributive laws hold

* Note: A ring in with the multiplicative operation is commutative, it is called commutative ring.

### Examples:

1. $(Z; +, \cdot)$, $(Q; +, \cdot)$, $(R; +, \cdot)$, $(C; +, \cdot)$
2. $N$ is __not__ a ring for usual addition and multiplication: There is no additive identity element, $0 \notin N$

<!-- TODO: b. Multip... -->

## Field

__A non empty set F with at least two elements and two binary operations ($+$) and ($\cdot$), such that:__

1. $(F, +)$ is an abelian group
2. $(F - \{0\}, \cdot)$ is an abelian group
3. Distributive laws hold

### Examples:

1. Set of non-zero real numbers $R$, with usual addition ($+$) and multiplication ($\cdot$)
2. Set $Z$ is not a field. Inverse property does not satisfy. But it is a ring.



