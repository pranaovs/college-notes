# Database Management Systems (DBMS)

## Basic Concepts

### Data Model

A set of concepts to describe the structure of a database.

### Data Operations

1. Insert
2. Delete

<!-- TODO: Complete notes -->

## Categories of DBMS

Three Schema Architecture

### Conceptual Data Model

It is a high-level data model.

Does not depend on the physical storage of data.
It describes what data is stored in the database and the relationships among those data.

It is conceptual and independent of how data is stored physically. It is not programming language specific.

* Attributes are properties of entities.

Can be presented in the form of __Entity-Relationship Diagrams (ERD)__.

### Physical data model

It is a low-level data model.

Describes how data is actually/physical stored in the database.

It is logical. It is not programming language specific.

__Unified Modeling Language (UML)__ is a common way to represent physical data models.
UML allows visualization of the structure of a database.

### Implementation Data Model

<!-- TODO: Complete notes -->

## Schema

A schema is a logical structure of a database.
It is a blueprint of how the database is constructed, divided into database tables for relational databases.

### Three Schema Architecture

| External Level (End Users) | Conceptual Level | Internal Level |
| --------------- | --------------- | --------------- |
| External View | Conceptual Schema | Internal Schema |

## Data Independence

### Logical Data Independence

The ability to change the conceptual schema without having to change external schemas or application programs (external view).

For example, adding a new field to a table does not require changes to the application programs that use that table.

### Physical Data Independence

The ability to change the internal schema without having to change the conceptual schema.

For example, changing the storage device or file organization does not affect the conceptual schema.

## DBMS Languages

1. Data Definition Language (DDL)
   * Used to define the database structure.
   * Examples: CREATE, ALTER, DROP statements.

2. Data Manipulation Language (DML)
   * Used to manipulate data in the database.
   * Examples: SELECT, INSERT, UPDATE, DELETE statements.

When there is no strict definition between conceptual schema and internal schema, the DDL is used to define both.

## Entity Relationship Diagram

1. Strong Entity
2. Weak Entity

### Entity

A property of an entity that describes it.

Denoted by a Rectangle in ERD.

### Weak Entity

A property which is related to an entity but is not related to the database without the entity.

Denoted by a Double Rectangle in ERD.

### Attribute

An attribute is a property of an entity or a weak entity.

It is denoted by an Oval in ERD.

#### Key Attribute

A key attribute is an attribute that uniquely identifies an entity or a weak entity.

It is denoted by a Double Oval in ERD.

#### Multi-valued Attribute

A multi-valued attribute is an attribute that can have multiple values for a single entity or weak entity.
It is an attribute that can have more than one value.

It is denoted by a Double Oval in ERD.

#### Composite Attribute

A composite attribute is an attribute that can be divided into smaller sub-attributes.
It is an attribute that can be broken down into smaller parts.

It is denoted by an Oval with a dashed line in ERD.

#### Derived Attribute

A derived attribute is an attribute that can be derived from other attributes.
It can be calculated from other attributes or entities.

It is denoted by a Dashed Oval in ERD.

#### Complex Attribute

A complex attribute is an attribute that can have multiple values and can be divided into smaller sub-attributes.
It is an attribute that can have more than one value and can be broken down into smaller parts.

It does not have a specific notation in ERD, but it can be represented using a combination of the above notations.
Usually, it is represented separately in the ERD.

### Relationship

It is a connection between two or more entities.
The relationship can be one-to-one, one-to-many, or many-to-many.
There can also be self-relationships.

It is denoted by a Diamond in ERD.

#### 1-n relationship

One to many (1:n) relationship indicates that one entity can be associated with many instances of the related entity.
For example, a department can have many employees, but each employee belongs to only one department.

#### n-1 relationship

Many to one (n:1) relationship indicates that many entities can be associated with one instance of another entity.
This is the inverse of a one-to-many relationship.

#### n-m relationship

Many to many (n:m) relationship indicates that many entities can be associated with many instances of another entity.
For example, students can enroll in multiple courses, and courses can have multiple students.

#### 1-1 relationship

One to one (1:1) relationship indicates that one entity is associated with exactly one instance of another entity.
For example, one person has one passport, and one passport belongs to one person.

#### min-max notation

_(min,max)_ notation can be used to denote structural constraints.

### Identifying Relationship

A relationship that connects a weak entity to its owner entity.

It is denoted by a Double Diamond in ERD.

### Entity Set

An entity set represents all instances of a specific entity type in the database.

### Enhanced Entity-Relationship Model (EER)

It is used to represent more complex relationships and constraints in the database.
It can include additional features such as specialization, generalization, and aggregation.
