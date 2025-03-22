#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> matrix1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << "Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]" << endl;
    solution.setZeroes(matrix1);
    cout << "Output: [[";
    for (size_t i = 0; i < matrix1.size(); ++i) {
        for (size_t j = 0; j < matrix1[i].size(); ++j) {
            cout << matrix1[i][j];
            if (j < matrix1[i].size() - 1) cout << ",";
        }
        if (i < matrix1.size() - 1) cout << "],[";
    }
    cout << "]]" << endl;

    // Test case 2
    vector<vector<int>> matrix2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    cout << "Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]" << endl;
    solution.setZeroes(matrix2);
    cout << "Output: [[";
    for (size_t i = 0; i < matrix2.size(); ++i) {
        for (size_t j = 0; j < matrix2[i].size(); ++j) {
            cout << matrix2[i][j];
            if (j < matrix2[i].size() - 1) cout << ",";
        }
        if (i < matrix2.size() - 1) cout << "],[";
    }
    cout << "]]" << endl;

    return 0;
}
