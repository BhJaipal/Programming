# How to make a SQLite based DB?

1. Select a low level language (Prefered: C, C++, Rust, Zig)
2. `Table` has array of attributes (`TableAttr`) called `TableAttrArray` and table name
3. Each attribute has a name, a type and isNullable property
4. `TableData` has table and row (`TableRows`) of arrays containing data for table
5. `TableAttr` cannot have array or dictionary as values

> [!NOTE]
> You can use my [dynamic-typed folder](dynamic-typed) for dynamic typing in C & C++

Add this line to your C/C++ file and start using dynamic typing

```c
#include "dynamic-typed/dynamic-typed.h"
```

> Before running, run `make` to compile the both C and C++ to compile this library
>
> Then while running your code

**For C:**

```bash
gcc file.c dynamic-typed/libdynamic.so
```

**And for C:**

```bash
gcc file.cpp dynamic-typed/libdynamic++.so
```
