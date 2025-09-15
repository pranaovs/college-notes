# Assignment 02

## Question 1

Show that each of the following are not valid rules about FD’s by giving example relations that satisfy the given FD’s (following the “if”) but not the FD that allegedly follows (after the “then”):

1. If A -> B then B -> A.
2. If AB -> C and A->C, then B->C.
3. If AB->C, then A -> C or B -> C.

### Solution

#### Solution 1

If $A \rightarrow B$ then $b \rightarrow A$.

Consider relation $R(A,B)$

| A | B |
| - | - |
| 1 | 2 |
| 2 | 2 |

For each value of $A$ there is a unique value of $B$, but not vice versa.

So, $A \rightarrow B$ holds, but $B \rightarrow A$ does not.

#### Solution 2

If $AB \rightarrow C$ and $A \rightarrow C$, then $B \rightarrow C$.

Consider relation $R(A,B,C)$

| A | B | C |
| - | - | - |
| 1 | 1 | 5 |
| 1 | 2 | 5 |
| 2 | 2 | 7 |

* Checking $AB \rightarrow C$:
  * For $(1,1)$ and $(1,2)$, both have $C=5$.
  * For $(2,2)$, $C=7$.

  So, $AB \rightarrow C$ holds.

* Checking $A \rightarrow C$:
  * For $A=1$, $C=5$.
  * For $A=2$, $C=7$.

  So, $A \rightarrow C$ holds.

* Checking $B \rightarrow C$:
  * For $B=1$, $C=5$.
  * For $B=2$, $C=5$ and $C=7$.

  So, $B \rightarrow C$ does not hold.

#### Solution 3

| A | B | C |
| - | - | - |
| 1 | 1 | 1 |
| 1 | 2 | 2 |
| 2 | 1 | 2 |
| 2 | 2 | 1 |

* Checking $AB \rightarrow C$
  * Each combination of $A$ and $B$ gives a unique $C$.

* Checking $A \rightarrow C$
  * For $A=1$, $C$ can be 1 or 2.
  * For $A=2$, $C$ can be 1 or 2.

  So, $A \rightarrow C$ does not hold.

* Checking $B \rightarrow C$
  * For $B=1$, $C$ can be 1 or 2.
  * For $B=2$, $C$ can be 1 or 2.

  So, $B \rightarrow C$ does not hold.

## Question 2

Suppose a relational schema $R (A, B, C, D, E)$ and set of functional dependencies $F: {A ->B, B-> E, C->D}$. Check out that relation is in 3NF or not? If not decompose it in 3NF.

### Solution

#### 1. Find candidate keys

* $A^+ = \{A\} \xrightarrow{A \to B} \{A,B\} \xrightarrow{B \to E} \{A,B,E\}$

  So $A^+ = \{A,B,E\}$ — not all attributes.

* $C^+ = \{C\} \xrightarrow{C \to D} \{C,D\}$

  So $C^+ = \{C,D\}$ — not all attributes.

* $(A,C)^+ = A^+ \cup C^+ = \{A,B,E\} \cup \{C,D\} = \{A,B,C,D,E\}$
  So $(A,C)$ is a candidate key.

Check minimality: neither $A$ nor $C$ alone is a key, so $AC$ is a candidate key.

Prime attributes: $\{A,C\}$.

#### 2. Check each FD for 3NF

A FD $X \to Y$ satisfies 3NF if:

1. $X$ is a superkey, or
2. every attribute in $Y$ is prime.

Check:

* $A \to B$:
  * $A$ is not a superkey.
  * $B$ is not prime.
  **Violates 3NF**.

* $B \to E$:
  * $B$ is not a superkey.
  * $E$ is not prime.
  **Violates 3NF**.

* $C \to D$:
  * $C$ is not a superkey.
  * $D$ is not prime.
  **Violates 3NF**.

So **$R$ is not in 3NF**.

#### 3. Decompose into 3NF

* From $A \to B$: $R_1(A,B)$
* From $B \to E$: $R_2(B,E)$
* From $C \to D$: $R_3(C,D)$

None of these contain the candidate key $(A,C)$, so add:

* $R_4(A,C)$

**Final decomposition:**
$R_1(A,B),\; R_2(B,E),\; R_3(C,D),\; R_4(A,C)$.

#### 4. Verify

* **Dependency-preserving:** Yes (all original FDs appear in some relation).
* **Lossless join:** Yes (because $AC$ — a candidate key — is in $R_4$).
* **Each relation is in 3NF:** Yes.

**Answer:**

* Is $R(A,B,C,D,E)$ in 3NF? **No**.
* 3NF decomposition:
$R_1(A,B),\; R_2(B,E),\; R_3(C,D),\; R_4(A,C)$

## Question 3

Decompose the table into 3NF:

| StudentID | StudentName | Address           | HouseName | HouseColor | Subject   | SubjectCost | Grade |
| --------- | ----------- | ----------------- | --------- | ---------- | --------- | ----------- | ----- |
| 19594332X | Mary Watson | 10 Charles Street | Bob       | Red        | English   | \$50        | B     |
|           |             |                   |           |            | Maths     | \$50        | A     |
|           |             |                   |           |            | Info Tech | \$100       | B+    |

### Solution

#### 1. Attributes

* **Student-related:** StudentID, StudentName, Address
* **House-related:** HouseName, HouseColor
* **Subject-related:** Subject, SubjectCost
* **Other:** Grade

#### 2. Functional Dependencies (FDs)

From the table:

* $StudentID \to StudentName,\ Address,\ HouseName$
* $HouseName \to HouseColor$
* $Subject \to SubjectCost$
* $(StudentID,\ Subject) \to Grade$

#### 3. Candidate Key

* The table stores multiple subjects for the same student.  
* To uniquely identify each row, we need **StudentID + Subject**.  
So, **Candidate Key:** $(StudentID,\ Subject)$.

#### 4. Check for 3NF

A FD $X \to Y$ satisfies 3NF if:

1. $X$ is a superkey, or  
2. every attribute in $Y$ is prime (part of some candidate key).

Check FDs:

* $StudentID \to StudentName,\ Address,\ HouseName$  
  * LHS is not a superkey (needs Subject).  
  * RHS attributes are not prime.  
  **Violates 3NF**.

* $HouseName \to HouseColor$  
  * LHS is not a superkey.  
  * RHS is not prime.  
  **Violates 3NF**.

* $Subject \to SubjectCost$  
  * LHS is not a superkey.  
  * RHS is not prime.  
  **Violates 3NF**.

* $(StudentID,\ Subject) \to Grade$  
  * LHS is a superkey.  
  **OK**.

So the table is **not in 3NF**.

#### 5. Decompose into 3NF

Create separate relations:

* $R_1(StudentID,\ StudentName,\ Address,\ HouseName)$  
  (because $StudentID \to StudentName,\ Address,\ HouseName$)

* $R_2(HouseName,\ HouseColor)$  
  (because $HouseName \to HouseColor$)

* $R_3(Subject,\ SubjectCost)$  
  (because $Subject \to SubjectCost$)

* $R_4(StudentID,\ Subject,\ Grade)$  
  (for the main relationship, candidate key is $(StudentID,\ Subject)$)

#### 6. Final 3NF Relations

* $Student(StudentID,\ StudentName,\ Address,\ HouseName)$  
* $House(HouseName,\ HouseColor)$  
* $Subject(Subject,\ SubjectCost)$  
* $Enrollment(StudentID,\ Subject,\ Grade)$

**3NF decomposition:**  

$Student(StudentID,\ StudentName,\ Address,\ HouseName)$

$House(HouseName,\ HouseColor)$

$Subject(Subject,\ SubjectCost)$

$Enrollment(StudentID,\ Subject,\ Grade)$
