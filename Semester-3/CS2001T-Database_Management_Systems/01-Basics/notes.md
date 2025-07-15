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
If there is clear separation, DDL is used for the conceptual schema and a __Structure Definition Language (SDL)__ (like SQL) is used for the internal schema.
