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
};

class SparseMatrix {
    private:
        int defaultValue = 0; // The default value. Nodes with values = default are omitted.
        int rows = 0; // Amount of rows
        int cols = 0; // Amount of cols
        std::vector<Node*> topOfRow; // Pointers to the first node in row
        std::vector<Node*> topOfCol; // Pointers to the first node in col
    public:
        // Constructors
        SparseMatrix();
        SparseMatrix(int defaultValue);
        ~SparseMatrix();
        // Basic operations
        Node* getNode(int row, int col); // Return node is present at (row, col). If not present, return nullptr
        int getValue(int row, int col); // Get value of node at (row, col)
        void setNode(int row, int col, int value); // Set node with value at (row, col)
        void removeNode(int row, int col); // Remove node at (row, col)
        std::string showMatrix(); // Return a string that can be printed
        // Matrix operations
        void sumMatrix(SparseMatrix* operand); // Adds operand matrix to this matrix
        void multiplyMatrix(SparseMatrix* operand); // Multiplies this matrix by operand matrix
};
