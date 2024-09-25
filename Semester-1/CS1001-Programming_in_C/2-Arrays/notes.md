# Arrays

---

Topic: Arrays

Author: Pranaov S

Lecturer: Mr. Subin Sahayam

Subject Code: CS1001

---

<!--toc:start-->
- [Arrays](#arrays)
  - [Introduction](#introduction)
    - [Syntax](#syntax)
      - [Declaration](#declaration)
      - [Assignment](#assignment)
      - [Accessing](#accessing)
      - [Example](#example)
<!--toc:end-->

## Introduction

Arrays are collection of variables of the same data type.

They are a _Homogeneous_ data type

Arrays are _unbounded_.
Care must be taken as to not overflow the array during assignment or accessing.

### Syntax

#### Declaration

`datatype arrayName[size];`

> When initializing an array, it is not necessary to provide array size.
> It is automatically inferred.
>
> `datatype arrayName[] = {array_elements};`

#### Assignment

`arrayName[index] = value;`

#### Accessing

`arrayName[index];`

#### Example

`int arr[5];`

`int arr[] = {1,2,3,4};`

```c
int main() {

  int num[5];

  for (int i = 1; i < sizeof(num); i++) {
    num[i] = i;
  }

  return 0;
}
```
