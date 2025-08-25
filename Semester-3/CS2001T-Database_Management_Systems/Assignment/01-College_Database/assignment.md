# Assignment

Consider the following information about a university database:

* Professors have an SSN, a name, an age, a rank, and a research specialty.
* Projects have a project number, a sponsor name (e.g., NSF), a starting date, an ending date, and a budget.
* Graduate students have an SSN, a name, an age, and a degree program (e.g., M.S. or Ph.D.).
* Each project is managed by one professor (known as the project’s principal investigator).
* Each project is worked on by one or more professors (known as the project’s co-investigators).
* Professors can manage and/or work on multiple projects. Each project is worked on by one or more graduate students (known as the project’s research assistants).
* When graduate students work on a project, a professor must supervise their work on the project. Graduate students can work on multiple projects, in which case they will have a (potentially different) supervisor for each one.
* Departments have a department number, a department name, and a main office.
* Departments have a professor (known as the chairman) who runs the department.
* Professors work in one or more departments, and for each department that they work in, a time percentage is associated with their job.
* Graduate students have one major department in which they are working on their degree.
* Each graduate student has another, more senior graduate student (known as a student advisor) who advises him or her on what courses to take.

## Question 1

Design and draw an ER diagram that captures the information about the university. Use only the basic ER model here; that is, entities, relationships, and attributes. Be sure to indicate any key and participation constraints.

### Diagram

![ER Diagram](./assets/er_diagram.svg)

## Question 2

Write SQL statements to create the corresponding relations and capture as many of the constraints as possible. If you cannot capture some constraints, explain why.

### Solution

```sql
-- Table for Entity A
CREATE TABLE A (
    a1 INT PRIMARY KEY,
    a2 INT
);

-- Table for Entity B
CREATE TABLE B (
    b1 INT PRIMARY KEY,
    b2 INT
);

-- Table for Entity C
CREATE TABLE C (
    c1 INT PRIMARY KEY,
    c2 INT
);

-- Table for Ternary Relationship R
CREATE TABLE R (
    a1 INT,
    b1 INT,
    c1 INT,
    PRIMARY KEY (a1, b1, c1),
    FOREIGN KEY (a1) REFERENCES A(a1),
    FOREIGN KEY (b1) REFERENCES B(b1),
    FOREIGN KEY (c1) REFERENCES C(c1),
    UNIQUE (a1, c1),
    UNIQUE (b1, c1)
);
```
