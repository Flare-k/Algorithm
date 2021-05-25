#include <iostream>
#include <queue>
using namespace std;

// 상하좌우의 합 max 값구하기

int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};

int arr[4][4] = {
    4, 3, 5, 1,
    1, 2, 3, 6,
    7, 3, 6, 4, 
    2, 2, 2, 5
};

int getSum(int x, int y) {
    int sum = 0;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
        sum += arr[nx][ny];
    }

    return sum;
}

int main() {

    int maxSum = -21e8;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            int ret = getSum(i, j);
            if (maxSum < ret) maxSum = ret;
        }
    }

    cout << maxSum;

    return 0;
}