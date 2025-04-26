# OS-FILES

This repository contains various C programs related to Operating System (OS) practicals, such as scheduling algorithms and memory management.

## System Requirements

- Linux-based system (Ubuntu, Debian, Fedora, etc.)
- GCC Compiler
- `make` utility

You can install requirements on Ubuntu/Debian using:

```bash
sudo apt update
sudo apt install build-essential
```

## Building the Project

To build all executables, run:

```bash
make
```

The compiled executables will be placed inside the `build/` folder.

## Running the Executables

After building, navigate to the `build/` directory and run any executable:

```bash
cd build
./FCFS
./SJF
./RR
...
```

## Cleaning the Project

To clean all the compiled files, run:

```bash
make clean
```