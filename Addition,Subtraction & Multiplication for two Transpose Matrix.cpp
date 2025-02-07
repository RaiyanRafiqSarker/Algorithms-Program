#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void transpose(int mat[][MAX_SIZE], int trans[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            trans[j][i] = mat[i][j];
        }
    }
}

void addMatrices(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int result[][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[j][k];
            }
        }
    }
}

void displayMatrix(int mat[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> rows1 >> cols1;
    int mat1[MAX_SIZE][MAX_SIZE];
    cout << "Enter the elements of the first matrix:\n";
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> rows2 >> cols2;
    int mat2[MAX_SIZE][MAX_SIZE];
    cout << "Enter the elements of the second matrix:\n";
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cin >> mat2[i][j];
        }
    }

    if (rows1 != rows2 || cols1 != cols2) {
        cout << "Matrices are not compatible for addition and subtraction.\n";
        return 0;
    }

    int trans1[MAX_SIZE][MAX_SIZE], trans2[MAX_SIZE][MAX_SIZE];
    transpose(mat1, trans1, rows1, cols1);
    transpose(mat2, trans2, rows2, cols2);

    int sum[MAX_SIZE][MAX_SIZE];
    addMatrices(trans1, trans2, sum, cols1, rows1);
    cout << "Addition of transpose matrices:\n";
    displayMatrix(sum, cols1, rows1);
    cout << endl;

    int difference[MAX_SIZE][MAX_SIZE];
    subtractMatrices(trans1, trans2, difference, cols1, rows1);
    cout << "Subtraction of transpose matrices:\n";
    displayMatrix(difference, cols1, rows1);
    cout << endl;

    int product[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(mat1, trans2, product, rows1, cols1, cols2);
    cout << "Multiplication of first matrix with the transpose of the second matrix:\n";
    displayMatrix(product, rows1, cols2);

    return 0;
}
