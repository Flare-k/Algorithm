/*
    2차원에서
    특정 구간의 합을 O(1)으로 처리하기
    Prefix Sum - Immutable 2D Array

    1. 원래 테이블 보다 크게 만든다. 최상단과 좌측에 0으로 둘러싸게끔
    Range Sum은 전체에서 나머지들을 빼야할 것
*/

#include <iostream>
using namespace std;

int row, col;
long long arr[6][5] = {
    3, 1, 5, 7, 2,
    9, 4, 8, 9, 7,
    3, 9, 2, 3, 6,
    2, 7, 5, 6, 1,
    4, 6, 8, 5, 3,
    3, 5, 9, 2, 7,
};
long long prefixSum[7][6];


int sumRegion(int row1, int col1, int row2, int col2) {
    long long A = prefixSum[row2 + 1][col2 + 1];
    long long B = prefixSum[row2 + 1][col1];
    long long C = prefixSum[row1][col2 + 1];
    long long D = prefixSum[row1][col1];
    return int(prefixSum[row2 + 1][col2 + 1]
            - prefixSum[row2 + 1][col1]
            - prefixSum[row1][col2 + 1]
            + prefixSum[row1][col1]);
}

int main() {
    row = 6;
    col = 5;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] 
                                    + prefixSum[i][j + 1] 
                                    - prefixSum[i][j] 
                                    + arr[i][j];
        }
    }

    cout << sumRegion(2, 2, 4, 3) << '\n';

    return 0;
}