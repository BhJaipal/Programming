# Aloo

## Info

- It is a library I made on top of GTK 4
- To try example, run run.sh in examples with

```bash
cd examples
./run.sh
```

## API

> Run `doxygen`
>
> **For Docs in [html](docs/html/aloo_8h.html), [latex](docs/latex/aloo_8h.tex), [rtf](docs/rtf/aloo_8h__incl.dot), [man](docs/man/man3/aloo.h.3), [xml](docs/xml/aloo_8h.xml), open docs folder**

## How to use

> In your project, include `aloo.h` for C and include at the end if you are running project with gcc instead of CMake `libaloo.a`
>
> For C++, I will do after completing it in C

```c
#include "aloo.h"
```

> and follow CMake configs from [examples CMake](examples/CMakeLists.txt)

## CLI

A CLI for creating aloo app is out but it works only with bun or compile it

### Create CLI with

```bash
python3 setup.py
```

### Create App

```bash
# create app without project name on arguments
$ [path to this dir]/bin/aloo create-app
Enter Project Name:  [aloo-project] aloo-app
Enter App Name:  [Example App] Hello World

# create app with project name on arguments
$ [path to this dir]/bin/aloo create-app aloo-project
Enter App Name:  [Example App]
```

### Run app

```bash
[path to this dir]/bin/aloo run
```

### Run test

```bash
[path to this dir]/bin/aloo test
```

### Create Model

```bash
[path to this dir]/bin/aloo model <name> <property-name>:[int| string | bool | float]
```

### Connect DB to a model

```bash
[path to this dir]/bin/aloo connect-db [sqlite3 | mongo]
```
