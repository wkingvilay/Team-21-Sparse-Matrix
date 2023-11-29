#include "sparseMatrix.h"
#include <iostream>

/*
Test cases for the sparse matrix class
*/

void printMatrix(SparseMatrix matrix);

int main(int argc, char*argv[]) {
    // First matrix
    SparseMatrix matrix = SparseMatrix();
    printMatrix(matrix);
    matrix.setNode(1, 1, 50);
    matrix.setNode(0, 1, 25);
    printMatrix(matrix);
    matrix.removeNode(0, 1);
    printMatrix(matrix);

    // Second matrix
    SparseMatrix matrix2 = SparseMatrix(5);
    matrix2.setNode(1, 1, 15);
    printMatrix(matrix2);

    // Sum the two matrices
    matrix.sumMatrix(&matrix2);
    printMatrix(matrix);
}

void printMatrix(SparseMatrix matrix) {
    std::cout << "Matrix:\n" << matrix.showMatrix() << "\n";
}
