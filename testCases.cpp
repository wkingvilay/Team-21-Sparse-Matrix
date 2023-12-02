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
    matrix.setNode(1, 0, 25);
    matrix.setNode(1, 1, 50);
    matrix.setNode(2, 2, 111);
    printMatrix(matrix);

    // Second matrix
    SparseMatrix matrix2 = SparseMatrix(5);
    matrix2.setNode(1, 0, 1);
    matrix2.setNode(1, 1, 15);
    matrix2.setNode(2, 0, 5);
    matrix2.setNode(0, 2, 5);
    printMatrix(matrix2);

    // Sum the two matrices
    matrix = matrix.sumMatrix(&matrix2);
    printMatrix(matrix);

    // Test deletion in the middle of a matrix
    SparseMatrix matrix3 = SparseMatrix();
    matrix3.setNode(1, 0, 5);
    matrix3.setNode(0, 1, 5);
    matrix3.setNode(1, 2, 5);
    matrix3.setNode(2, 1, 5);
    matrix3.setNode(1, 1, 25);
    printMatrix(matrix3);
    matrix3.removeNode(1, 1);
    printMatrix(matrix3);

    // Test matrix multiplication
    SparseMatrix matrix4 = SparseMatrix(1);
    matrix4.setNode(0, 1, 2);
    matrix4.setNode(0, 2, 3);
    matrix4.setNode(1, 0, 4);
    matrix4.setNode(1, 1, 5);
    matrix4.setNode(1, 2, 6);
    printMatrix(matrix4);
    SparseMatrix matrix5 = SparseMatrix(7);
    matrix5.setNode(0, 1, 8);
    matrix5.setNode(1, 0, 9);
    matrix5.setNode(1, 1, 10);
    matrix5.setNode(2, 0, 11);
    matrix5.setNode(2, 1, 12);
    printMatrix(matrix5);
    matrix4 = matrix4.multiplyMatrix(&matrix5); // matrix4 x matrix5
    printMatrix(matrix4);

    // Test reading matrices from file
    SparseMatrix matrix6 = SparseMatrix("matrix1.txt");
    printMatrix(matrix6);
    SparseMatrix matrix7 = SparseMatrix("matrix2.txt");
    printMatrix(matrix7);
}

void printMatrix(SparseMatrix matrix) {
    std::cout << "Matrix:\n" << matrix.showMatrix() << "\n";
}
