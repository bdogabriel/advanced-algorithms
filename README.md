# Advanced Algorithms

This repository contains many exercises I solved for the ***Advanced Algorithms*** class in university. Most of them are problems taken or adapted from competitive programming contests and sites.

## What are the problems like

They cover a variety of algorithm categories, including:

* Greedy Algorithms;
* Backtracking;
* Divide and Conquer;
* Dynamic Programming;
* Graphs;
* Geometry;

## How this repository is structured

Every folder contains a `PDF` file with the problem description, the solution in `C++`, some test cases, and a `Makefile` for conviniently building and running the tests.

## How to run the tests
### Dependencies
* `make`
* `g++`
* `valgrind`

For compiling, I use `g++` with flags for checking errors and warnings more strictly, and `valgrind` is used to check for memory leaks. It's all set in the `Makefile`, so just run `make`.

To run the tests, simply change the test file name in the `Makefile` on the run directive, for example:

```
run: exe
  valgrind ./exe < test_cases/5.in > out.out
```

Then run `make run`.

A file called `out.out` will be created with the output of the program.
