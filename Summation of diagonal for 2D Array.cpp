#include <iostream>
using namespace std;

const int MAX_SIZE = 100;


int diagonalSum(int arr[][MAX_SIZE], int rows, int cols, int startRow, int startCol) {
    int sum = 0;
    int row = startRow;
    int col = startCol;


    while (row < rows && col < cols) {
        sum += arr[row][col];
        row++;
        col++;
    }

    return sum;
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows and columns of the 2D array: ";
    cin >> rows >> cols;

    int arr[MAX_SIZE][MAX_SIZE];

    cout << "Enter the elements of the " << rows << "x" << cols << " 2D array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "The 2D array is:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int startRow, startCol;

    cout << "Enter the starting row index and starting column index of the diagonal: ";
    cin >> startRow >> startCol;

    if (startRow >= 0 && startRow < rows && startCol >= 0 && startCol < cols) {
        int diagonal = diagonalSum(arr, rows, cols, startRow, startCol);
        cout << "The summation of all the elements of the diagonal is: " << diagonal << endl;
    } else {
        cout << "Invalid starting row index or starting column index!" << endl;
    }

    return 0;
}
