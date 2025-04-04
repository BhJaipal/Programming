# How to make a SQLite based DB?

1. Select a low level language (Prefered: C, C++, Rust, Zig)
2. `Table` has array of attributes (`TableAttr`) called `TableAttrArray` and table name
3. Each attribute has a name, a type and isNullable property
4. `TableData` has table and row (`TableRows`) of arrays containing data for table
5. `TableAttr` cannot have array or dictionary as values

> install dynamic-typed and logging folder and put them in same dir/folder
>
> then install generate.sh/bat in folder where logging and dynamic-typed are stored
>
> If you use *Windows* [generate.bat](generate.bat)
>
> else install meson and run [generate.sh](generate.sh)

