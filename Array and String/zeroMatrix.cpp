// O(M * N)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    unordered_set<int> rows_with_zero;
    unordered_set<int> cols_with_zero;

    // Traverse the matrix and store the rows and columns with zeros
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                rows_with_zero.insert(i);
                cols_with_zero.insert(j);
            }
        }
    }

    // Set entire rows to 0
    for (int row : rows_with_zero) {
        for (int j = 0; j < n; ++j) {
            matrix[row][j] = 0;
        }
    }

    // Set entire columns to 0
    for (int col : cols_with_zero) {
        for (int i = 0; i < m; ++i) {
            matrix[i][col] = 0;
        }
    }
}

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    setZeroes(matrix);

    cout << "Matrix after setting zeroes:" << endl;
    printMatrix(matrix);

    return 0;
}
