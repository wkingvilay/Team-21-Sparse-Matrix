/*
Sparse Matrices with Linked Lists
URI CSC 212 Spring 2023 Term Project
Group Members: C. Horton, P. Peralta, W. Kingvilay, A. Frias
*/

/*
Minesweeper Board Generator
 */

#include "sparseMatrix.h"
#include "color.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

void layMine(int row, int col, int rows, int cols, SparseMatrix* board);
void printMatrix(int rows, int cols, SparseMatrix board);

int main(int argc, char* argv[]) {
    int rows = std::stoi(argv[1]);
    int cols = std::stoi(argv[2]);
    int mines = std::stoi(argv[3]);
    std::srand(std::stoi(argv[4]));

    if (mines < 0) {
        std::cout << "Error - must have at least zero mines.";
        return 0;
    } else if (mines > rows*cols) {
        std::cout << "Error - too many mines! This grid can't fit more than " << rows*cols;
        return 0;
    }

    // If seed = 0, use current time as seed instead
    if (std::stoi(argv[4]) == 0) std::srand(std::time(nullptr));

    SparseMatrix board = SparseMatrix();
    // Set the matrix to be the correct size by expanding to bottom right corner
    board.setNode(rows-1, cols-1, 0);

    int minesLaid = 0;
    while (minesLaid < mines) {
        int tryRow = rand()%rows;
        int tryCol = rand()%cols;
        if (board.getValue(tryRow, tryCol) < 9) { // Open
            // Lay a mine here
            layMine(tryRow, tryCol, rows, cols, &board);
            minesLaid++;
        }
    }

    printMatrix(rows, cols, board);
}

// Lay a mine at position row, col while respecting boundaries
void layMine(int row, int col, int rows, int cols, SparseMatrix* board) {
    // Increment surrounding numbers
    for (int rMod = -1; rMod < 2; rMod++) {
        for (int cMod = -1; cMod < 2; cMod++) {
            if ((0 <= row+rMod) && (row+rMod < rows) && (0 <= col+cMod) && (col+cMod < cols)) {
                int curVal = board->getValue(row+rMod, col+cMod);
                board->setNode(row+rMod, col+cMod, curVal+1);
            }
        }
    }
    // Replace center number with 9. Anything < 8 indicates mine here.
    board->setNode(row, col, 9);
}

void printMatrix(int rows, int cols, SparseMatrix board) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int value = board.getValue(row, col);
            switch (value) {
                case 0:
                    std::cout << value;
                    break;
                case 1:
                    std::cout << dye::light_blue(value);
                    break;
                case 2:
                    std::cout << dye::light_green(value);
                    break;
                case 3:
                    std::cout << dye::light_yellow(value);
                    break;
                case 4:
                    std::cout << dye::light_purple(value);
                    break;
                case 5:
                    std::cout << dye::blue(value);
                    break;
                case 6:
                    std::cout << dye::green(value);
                    break;
                case 7:
                    std::cout << dye::yellow(value);
                    break;
                case 8:
                    std::cout << dye::purple(value);
                    break;
                default:
                    std::cout << dye::red("X");
                    break;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
