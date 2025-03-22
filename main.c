#include <stdio.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int ii[200] = {0};
    int jj[200] = {0};
    int len = matrixColSize[0];
    
    // First pass to identify rows and columns to be zeroed
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < len; j++) {
            if (matrix[i][j] == 0) {
                ii[i] = 1; // Mark the row
                jj[j] = 1; // Mark the column
            }
        }
    }
    
    // Zero out the marked rows
    for (int i = 0; i < matrixSize; i++) {
        if (ii[i] == 1) {
            for (int j = 0; j < len; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Zero out the marked columns
    for (int j = 0; j < len; j++) {
        if (jj[j] == 1) {
            for (int i = 0; i < matrixSize; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    // Test case 1
    int matrix1[3][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int* ptr1[3] = {matrix1[0], matrix1[1], matrix1[2]};
    int colSize1[1] = {3};
    printf("Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]\n");
    setZeroes(ptr1, 3, colSize1);
    printf("Output: [[");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", matrix1[i][j]);
            if (j < 2) printf(",");
        }
        if (i < 2) printf("],[");
    }
    printf("]]\n");

    // Test case 2
    int matrix2[3][4] = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    int* ptr2[3] = {matrix2[0], matrix2[1], matrix2[2]};
    int colSize2[1] = {4};
    printf("Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]\n");
    setZeroes(ptr2, 3, colSize2);
    printf("Output: [[");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d", matrix2[i][j]);
            if (j < 3) printf(",");
        }
        if (i < 2) printf("],[");
    }
    printf("]]\n");

    return 0;
}
