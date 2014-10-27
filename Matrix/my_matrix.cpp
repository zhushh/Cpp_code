#include "matrix.h"
#include <iostream>
using namespace std;
Matrix::Matrix(const Matrix& otherMatrix) {
    int i, j;
    for (i = 0; i < otherMatrix.N; ++i) {
        for (j = 0; j < otherMatrix.N; ++j) {
            m[i][j] = otherMatrix.m[i][j];
        }
    }
}
void Matrix::setElement(int x, int y, int value) {
    m[x][y] = value;
}
Matrix Matrix::multiply(const Matrix& otherMatrix) {
    Matrix temp;
    int i, j, k, l, sum;
    temp.N = N;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            temp.m[i][j] = 0;
        }
    }
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                temp.m[j][i] += m[j][k] * otherMatrix.m[k][i];
            }
        }
    }
    return temp;
}
Matrix Matrix::transposition() {
    int i, j;
    Matrix temp;
    temp.N = N;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            temp.m[i][j] = 0;
        }
    }
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            temp.m[j][i] = m[i][j];
        }
    }
    return temp;
}
void Matrix::print() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; ++j) {
            cout << m[i][j];
            if (j != N - 1) cout << " ";
        }
        cout << endl;
    }
}
