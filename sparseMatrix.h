/*
Sparse Matrices with Linked Lists
URI CSC 212 Spring 2023 Term Project
Group Members: C. Horton, P. Meralta, W. Kingvilay, A. Frias
*/

#pragma once

#include <vector>
#include <string>

class Node {
    private:
        int value; // Data stored in node
        int row; // The row the node is in
        int col; // The column the node is in
        Node* nextInRow = nullptr; // Points to next node in row
        Node* nextInCol = nullptr; // Points to next node in col
    public:
        // Constructors
        Node(int row, int col, int value);
        ~Node();
    friend class SparseMatrix;
};

class SparseMatrix {
    private:
        int defaultValue = 0; // The default value. Nodes with values = default are omitted.
        std::vector<Node*> topOfRow; // Pointers to the first node in row
        std::vector<Node*> topOfCol; // Pointers to the first node in col
        // Helpers
        Node* findBeforeRow(int row, int col); // Find the last item before (row, col) in row
        Node* findBeforeCol(int row, int col); // Find the last item before (row, col) in col
    public:
        // Constructors
        SparseMatrix();
        SparseMatrix(int defaultValue);
        SparseMatrix(int defaultValue, std::string fname); // Load matrix from file
        ~SparseMatrix();
        // Basic operations
        Node* getNode(int row, int col); // Return node present at (row, col). If not present, return nullptr
        int getValue(int row, int col); // Get value of matrix at (row, col), regardless if node exists
        void setNode(int row, int col, int value); // Set node with value at (row, col)
        void removeNode(int row, int col); // Remove node at (row, col)
        std::string showMatrix(); // Return a string that can be printed
        // Matrix operations
        SparseMatrix sumMatrix(SparseMatrix* operand); // Adds operand matrix to this matrix
        SparseMatrix multiplyMatrix(SparseMatrix* operand); // Multiplies this matrix by operand matrix
};
