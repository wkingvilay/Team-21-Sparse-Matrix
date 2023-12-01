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
Matrix Class Helpers
*/

Node* SparseMatrix::findBeforeRow(int row, int col) {
    Node* beforeRow = this->topOfRow[row];
    while (beforeRow != nullptr) {
        if (beforeRow->col < col && beforeRow->nextInRow == nullptr) return beforeRow;
        if (beforeRow->nextInRow == nullptr || beforeRow->col == col) return nullptr;
        if (beforeRow->nextInRow->col >= col) return beforeRow;
        beforeRow = beforeRow->nextInRow;
    }
    return nullptr;
}

Node* SparseMatrix::findBeforeCol(int row, int col) {
    Node* beforeCol = this->topOfCol[col];
    while (beforeCol != nullptr) {
        if (beforeCol->row < row && beforeCol->nextInCol == nullptr) return beforeCol;
        if (beforeCol->nextInCol == nullptr || beforeCol->row == row) return nullptr;
        if (beforeCol->nextInCol->row >= row) return beforeCol;
        beforeCol = beforeCol->nextInCol;
    }
    return nullptr;
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

// Return node present at (row, col). If not present, return nullptr
Node* SparseMatrix::getNode(int row, int col) { 
    // Check bounds
    if (row < 0 || row >= topOfRow.size() || col < 0 || col >= topOfCol.size()) return nullptr;
    // Iterate through rows
    Node* i = this->topOfRow[row];
    while (i != nullptr && i->col <= col) {
        if (i->col == col) return i;
        i = i->nextInRow;
    }
    return nullptr;
}

// Get value of matrix at (row, col), regardless if node exists
int SparseMatrix::getValue(int row, int col) {
    Node* target = getNode(row, col);
    if (target != nullptr) return target->value; // If node exists
    return defaultValue; // If node doesn't exist
}

// Set node with value at (row, col)
void SparseMatrix::setNode(int row, int col, int value) {
    // Check bounds and extend lists if too small
    if (row < 0 || col < 0) return;
    while (row >= topOfRow.size()) {
        topOfRow.push_back(nullptr);
    }
    while (col >= topOfCol.size()) {
        topOfCol.push_back(nullptr);
    }

    // Check if node already exists
    Node* target = getNode(row, col);
    if (target != nullptr) {
        if (value == defaultValue) return removeNode(row, col); // Node shouldn't exist
        target->value = value;
        return;
    }

    // Find pointers of before/after nodes in row and col
    Node* beforeRow = findBeforeRow(row, col);
    Node* beforeCol = findBeforeCol(row, col);

    // Create node and set its pointers
    Node* insert = new Node(row, col, value);
    if (beforeRow != nullptr) {
        insert->nextInRow = beforeRow->nextInRow;
        beforeRow->nextInRow = insert;
    } else {
        if (topOfRow[row] != nullptr) insert->nextInRow = this->topOfRow[row];
        this->topOfRow[row] = insert;
    }
    if (beforeCol != nullptr) {
        insert->nextInCol = beforeCol->nextInCol;
        beforeCol->nextInCol = insert;
    } else {
        if (topOfCol[col] != nullptr) insert->nextInCol = this->topOfCol[col];
        this->topOfCol[col] = insert;
    }
}

// Remove node at (row, col)
void SparseMatrix::removeNode(int row, int col) {
    Node* target = getNode(row, col);
    if (target == nullptr) return; // Make sure node exists
    // Find pointers of before/after nodes in row and col
    Node* beforeRow = findBeforeRow(row, col);
    Node* beforeCol = findBeforeCol(row, col);
    // Set before pointers to point to after node
    if (beforeRow != nullptr) {
        beforeRow->nextInRow = target->nextInRow;
    } else {
        topOfRow[row] = target->nextInRow;
    }
    if (beforeCol != nullptr) {
        beforeCol->nextInCol = target->nextInCol;
    } else {
        topOfCol[col] = target->nextInCol;
    }
    // Delete node
    delete target;
}

// Return a string that can be printed
std::string SparseMatrix::showMatrix() {
    //Variable to store string
    std::string matrixString = "";
    // Traverse through rows
    for (int row = 0; row < topOfRow.size(); ++row) {
        //Start at first node
        Node* current = topOfRow[row];
        // Traverse through columns
        for (int col = 0; col < topOfCol.size(); ++col) {
            if (current != nullptr && current->col == col) {
                // If node exists at (row, col), append its value
                std::string currentVal = std::to_string(current->value); //Turn the value into a string
                matrixString += (currentVal + " ");
                current = current->nextInRow; //Move to the next row
            } else {
                // If node doesn't exist, append the default value
                std::string defaultVal = std::to_string(defaultValue); //Turn the value into a string
                matrixString += (defaultVal + " ");
            }
        }
        // Move to the next line
        matrixString += "\n";
    }
    return matrixString;
}

/*
Matrix Class Matrix Operations
*/

// Adds operand matrix to this matrix
void SparseMatrix::sumMatrix(SparseMatrix* operand) {
    //Return if nullptr, or matrices not of equal size
    if (operand == nullptr || operand->topOfRow.size() != this->topOfRow.size() || operand->topOfCol.size() != this->topOfCol.size()) {
        return;
    }

    //Traverse through matrix
    for (int row = 0; row < this->topOfRow.size(); row++) {
        for (int col = 0; col < this->topOfCol.size(); col++) {
            // Get values from both matrices
            int val1 = getValue(row, col);
            int val2 = operand->getValue(row, col);
            // Calculate sum
            int sum = val1 + val2;
            // Set the result in the current matrix
            setNode(row, col, sum);
        }
    }
}

// Multiplies this matrix by operand matrix
// As I write this, I figure we may need to add two more parameters of some sort
// So right now, Psuedocode will have to do until we figure something out of some sort. 
// Still trying to figure a work around on how should I account for matrices when rows != cols so that
// A matrix multiplication is possible
void SparseMatrix::multiplyMatrix(SparseMatrix* operand) {

    for (int row = 0; row < this->topOfRow.size(); ++row) {
        for (int col = 0; col < this->topOfCol.size(); ++col) {
            int sum = 0;
            
            // Dot Product
            for(int k = 0; k < this->topOfCol.size(); k++){
                int val1 = this->getValue(row, col);
                int val2 = operand->getValue(row, col);
                sum += val1 * val2;
            

                // Add result to the matrix
                if(sum != 0){
                    this->setNode(row, col, sum);
                }

            }
        }
    }
}

// 
// std::vector<std::vector<int>> SparseMatrix::Transpose(){
//     
//
//     return matrix;
// }
