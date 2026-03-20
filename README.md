# Polynomial Calculator

A command-line calculator written in C that calculates the sum and product of polynomials with integer coefficients.

## 📝 About The Project

This calculator reads a polynomial (up to the 10th degree) and performs addition and multiplication operations. It features a built-in memory register called the **accumulator**, which stores a single polynomial. The initial value of the accumulator is always a zero polynomial.

The program reads a mathematical operation (`+` for addition, `*` for multiplication) followed by a polynomial in a single line. It executes the command, computing the result using the accumulator's current value and the polynomial provided as an argument. After each operation, the calculator outputs the result and saves it back into the accumulator. The program stops execution when it detects a dot (`.`) as the input.

*Author: Bartosz Kościołek*

## 🛠️ Built With

* [C](https://en.wikipedia.org/wiki/C_(programming_language))
* GCC (GNU Compiler Collection)

## 🚀 Getting Started

To get a local copy up and running, follow these simple steps.

### Prerequisites

You need a C compiler (like GCC) installed on your system.

### Compilation

Open your terminal and compile the code using the following command:

`gcc kalkulator.c -o kalkulator`

### Execution

Run the compiled program:

**On Linux/macOS:**
`./kalkulator`

**On Windows:**
`kalkulator.exe`

## 💡 Example Usage

Below is an example of interacting with the program in the terminal. The first line is the user input (operation and polynomial), and the second line is the program's output (current accumulator state).

+ 2x^2 + 3x - 1
2x^2 + 3x - 1
* 3x
6x^3 + 9x^2 - 3x
+ -5x^2 + 2
6x^3 + 4x^2 - 3x + 2
.
