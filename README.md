# Sparse Matrices with Linked Lists

University of Rhode Island 

CSC 212: Data Structures and Abstractions

Spring 2023 Term Project

Group Members: C. Horton, P. Peralta, W. Kingvilay, A. Frias

## Overview
A sparse matrix is a matrix which omits nodes from memory whose values are equal to a default, enabling efficient storage of data mostly comprised of a uniform value. This project provides a C++ implementation of a sparse matrix using linked lists for its rows and columns. It then uses a sparse matrix to generate valid boards for the game Minesweeper.

## How to Use
> Note: The Minesweeper implementation uses the [``color-console``](https://github.com/aafulei/color-console) library to color-code the outputted board in the console. This can slightly increase compilation times.

### Minesweeper
- Download `Minesweeper.cpp`, `sparseMatrix.cpp`, and `sparseMatrix.h` from this repository
- Download [``color.hpp``](https://github.com/aafulei/color-console/blob/master/include/color.hpp) to the same directory as the files from this repository
- Open your terminal and compile with G++ using `g++ sparseMatrix.cpp Minesweeper.cpp -o mines`

**Usage:** ``.\mines <rows> <cols> <mines> <seed>`` (all arguments are integers)

Outputs a board directly to the console.

 - `rows`: Width of the board
 - `cols`: Height of the board
 - `mines`: Amount of mines to place (0 <= mines <= rows*cols)
 - `seed`: Seed for the board's random mine placement. If seed is set to 0, it will use a random seed (based on the current time).

### Test cases
 - Download `testCases.cpp`, `sparseMatrix.cpp`, `sparseMatrix.h`, `testmatrix1.txt`, and `testmatrix2.txt` from this repository
 - Open your terminal and compile with G++ using `g++ sparseMatrix.cpp testCases.cpp -o test`

**Usage:** ``.\test``

Outputs sparse matrix class test cases directly to the console.

`testmatrix1.txt` and `testmatrix2.txt` are simply read and outputted to the console at the end of the program. You can change these files to be whatever sparse matrices you desire. The file format is described below:

 - First line: Default value (typically 0)
 - All other lines: ``row col value`` (Inserts value at position `row, col`, with row and col starting at zero in the top left corner)

## Group Guidelines
All team members will make at least some contribution to the code. However, each team member has an additional specialty:
| Team Member | Specialty |
|--|--|
| C. Horton | GitHub management |
| P. Peralta | Presentation |
| W. Kingvilay | Report |
| A. Frias | Presentation |

It is up to each team member to cover the area designated by their specialty, and to assist one another as requested.
