#include "matrix.h"
#include <iostream>
using namespace std;
     
Matrix::Matrix(const Matrix& otherMatrix) {
    N = otherMatrix.N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            m[i][j] = otherMatrix.m[i][j];
        }
    }
     
void Matrix::setElement(int x, int y, int value) {
    m[x][y] = value;
}
     
Matrix Matrix::multiply(const Matrix& otherMatrix) {
    Matrix c(N);
    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp = 0;
            for (int k = 0; k < N; k++) {
                temp += m[i][k] * otherMatrix.m[k][j];
            }
            c.m[i][j] = temp;
        }
    }
    return c;
}
     
Matrix Matrix::transposition() {
    Matrix c(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            c.m[i][j] = m[j][i];
        }
    }
    return c;
}
     
void Matrix::print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            cout << m[i][j] << " ";
        }
        cout << m[i][N - 1] << endl;
    }
}

