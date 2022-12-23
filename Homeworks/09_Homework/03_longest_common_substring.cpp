#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int DYNAMIC_PROGRAMMING_MATRIX_ROWS = 2;

int main() {
    string firstString;
    cin >> firstString;

    string secondString;
    cin >> secondString;

    int **matrix = new int *[DYNAMIC_PROGRAMMING_MATRIX_ROWS];
    int cols = secondString.length();

    for (int i = 0; i < DYNAMIC_PROGRAMMING_MATRIX_ROWS; ++i) {
        matrix[i] = new int[cols + 1];
    }

    for (int i = 0; i < DYNAMIC_PROGRAMMING_MATRIX_ROWS; ++i) {
        for (int j = 0; j <= cols; ++j) {
            matrix[i][j] = 0;
        }
    }

    int bestLength = 0;
    int rows = firstString.length();
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (firstString[row] == secondString[col]) {
                int currentLength = matrix[row % 2][col] + 1;
                matrix[(row + 1) % 2][col + 1] = currentLength;

                if (bestLength < currentLength) {
                    bestLength = currentLength;
                }
            } else {
                matrix[(row + 1) % 2][col + 1] = 0;
            }
        }
    }

    cout << bestLength;
}