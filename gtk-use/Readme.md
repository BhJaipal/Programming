# Aloo

## Info

- It is a library I made on top of GTK 4
- To try example, run run.sh in examples with

```bash
cd examples
./run.sh
```

## API

> **Markdown documentation in [here](api/index.md)**
>
> **For other docs like in [html](docs/html/aloo_8h.html), [latex](docs/latex/aloo_8h.tex), [rtf](docs/rtf/aloo_8h__incl.dot), [man](docs/man/man3/aloo.h.3), [xml](docs/xml/aloo_8h.xml), open docs folder**

## How to use

> In your project, include `aloo.h` for C
>
> For C++, I will do after completing it in C

```c
#include "aloo.h"
```

> and follow CMake configs from [examples CMake](examples/CMakeLists.txt)

## CLI

A CLI for creating aloo app is out but it works only with bun or compile it

### Create App

```bash
# create app without project name on arguments
$ path/aloo create-app
Enter Project Name:  [aloo-project] aloo-app
Enter App Name:  [Example App] Hello World

# create app with project name on arguments
$ path/aloo create-app aloo-project
Enter App Name:  [Example App]
```

### Run app

```bash
path/aloo run
```

### Run test

```bash
path/aloo test
```
