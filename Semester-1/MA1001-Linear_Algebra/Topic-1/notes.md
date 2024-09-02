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

A set of numbers written in row form $(\begin{bmatrix}x&y\end{bmatrix})$ or column form $(\begin{bmatrix}x\\y\end{bmatrix})$ is said to be a _Row Vector_ or _Column Vector_.

The integral numbers in the vector are called _components_ or _entry_ or _elements_.

A vector having $n$ elements is called _n-dimensional vector_ or _n-tuple_.

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

**Definition:** A non empty set $V$ is said to be a vector space over a field $F$ if there are 2 binary operators (Vector Addition and Scalar Multiplication) satisfying the following properties:

Let $x,y,z \in V$ and $\alpha,\beta \in F$

1. **For vector addition:**
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

2. **For Scalar Multiplication**

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

**Note:**

1. The vector space $B$ over a field $F$ is denoted as $B(F)$
2. Also known as _Linear Space_
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

(\alpha \beta)x = (\alpha \beta)[x_{1},x_{2}, \dots x_{n}]\\
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

**Definition:**
A subset $W$ of a vector space $V$ over a field $F$ is called a subspace of $V$ if $W$ is a vector space over $F$ with the operations of vector addition and scalar multiplication defined on $V$.

**Note:**

1. $V$ and $V\{0\}$ are called improper or trivial subspaces.
2. $W$ subset of $V$ is called proper subspace of $V$.

**Examples:**

1. $R^{2}$
    1. It is a vector space
    2. Subspace of $R^{2}$

> As $W$ is a subspace of $V$, commutative and associative properties under addition hold good. Also the properties of scalar multiplication $V$ satisfies on $W$. Therefore, to prove $W$ is a subspace of $V$, it is enough to verify closure property, identity property and inverse property (optional).


**Theorem:**

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
