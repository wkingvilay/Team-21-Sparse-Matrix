/*
Sparse Matrices with Linked Lists
URI CSC 212 Spring 2023 Term Project
Group Members: C. Horton, P. Meralta, W. Kingvilay, A. Frias
*/

#include "sparseMatrix.h"

/*
Node Class Constructors
*/

Node::Node(int row, int col, int val) {
    this->row = row;
    this->col = col;
    this->value = val;
}

Node::~Node() {
    
}

/*
Matrix Class Constructors
*/

SparseMatrix::SparseMatrix() {

}

SparseMatrix::SparseMatrix(int defaultValue) {
    this->defaultValue = defaultValue;
}

SparseMatrix::~SparseMatrix() {

}

/*
Matrix Class Basic Operations
*/

// Return node is present at (row, col). If not present, return nullptr
Node* SparseMatrix::getNode(int row, int col) { 

}

// Get value of node at (row, col)
int SparseMatrix::getValue(int row, int col) {

}

// Set node with value at (row, col)
void SparseMatrix::setNode(int row, int col, int value) {

}

// Remove node at (row, col)
void SparseMatrix::removeNode(int row, int col) {

}

// Return a string that can be printed
std::string SparseMatrix::showMatrix() {

}

/*
Matrix Class Matrix Operations
*/

// Adds operand matrix to this matrix
void SparseMatrix::sumMatrix(SparseMatrix* operand) {

}

// Multiplies this matrix by operand matrix
void SparseMatrix::multiplyMatrix(SparseMatrix* operand) {

}
