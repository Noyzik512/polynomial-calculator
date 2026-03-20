# Polynomial Calculator

A command-line calculator written in C that calculates the sum and product of polynomials with integer coefficients.

## 📝 About The Project

This calculator features a built-in memory register called the **accumulator**, which stores a single polynomial. The initial value of the accumulator is always a zero polynomial. 

The program executes commands to compute either the sum or the product of the accumulator's current value and a polynomial provided as an argument. After each operation, the calculator outputs the result and automatically saves it back into the accumulator for future calculations.

## 🛠️ Built With

* [C](https://en.wikipedia.org/wiki/C_(programming_language))
* GCC (GNU Compiler Collection)

## 🚀 Getting Started

To get a local copy up and running, follow these simple steps.

### Prerequisites

You need a C compiler (like GCC) installed on your system.

### Compilation

Open your terminal and compile the code using the following command:

```bash
gcc kalkulator.c -o kalkulator
