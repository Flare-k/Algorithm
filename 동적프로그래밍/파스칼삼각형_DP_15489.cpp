#include <iostream>
using namespace std;

const int MAX = 31;
int R, C, W, T;
int arr[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> W;

    arr[1][1] = 1;

    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) arr[i][j] = 1;
            else arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j <= i; j++) {
            sum += arr[R + i][C + j];
        }
    }

    return 0;
}