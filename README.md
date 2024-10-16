# Readme Whetstone Benchmark – **Modernized Edition** 🚀

Welcome to the **modernized Whetstone Benchmark**, a high-performance testing tool designed to measure the computational capabilities of your system with various data types (e.g., `int`, `float`, `double`). This version builds upon the classic 1998 C implementation of the **Whetstone Double Precision Benchmark** but now supports **template-based flexibility**, **multiple data types**, and better integration with modern compilers. Whether you’re benchmarking simple arithmetic or heavy transcendental operations, this version has been reworked to reflect **modern hardware capabilities**.

---

## What's New? 🌟

This isn't your grandma's Whetstone benchmark! We’ve taken the original double-precision-only implementation and **pimped it up** with the following new features:

1. **Templated Benchmark Class**:  
   Run benchmarks with `int`, `float`, `double`, or any other numeric type, thanks to C++ templates.

2. **Command-Line Control**:  
   Customize the loop count easily through command-line arguments to adjust the workload.

3. **Trigonometric and Arithmetic Operations**:  
   Our enhanced benchmark ensures that transcendental functions (like `sin`, `cos`, and `exp`) and arithmetic calculations are thoroughly tested.

4. **Modular and Clean Design**:  
   Clear class-based design to allow developers to extend or modify benchmarks easily.

5. **Optimized for Compiler Performance**:  
   Take advantage of modern compiler optimizations (e.g., `-O3`, `-ffast-math`) for better performance on today’s CPUs.

6. **SIMD Potential**:  
   Ready for future upgrades to use SIMD optimizations or lookup tables for transcendental functions.

---

## Original Credits 📜  

This version is based on the original 1998 Whetstone benchmark, converted to C by Rich Painter from the **FORTRAN version** at [www.netlib.org](http://www.netlib.org/). Below is the original copyright notice:
C Converted Whetstone Double Precision Benchmark
Version 1.2, 22 March 1998
(c) Copyright 1998 Painter Engineering, Inc.
All Rights Reserved.

Permission is granted to use, duplicate, and publish this text and program as long as it includes this entire comment block and limited rights reference.



