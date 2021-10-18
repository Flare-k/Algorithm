#include <iostream>
using namespace std;

const int MAX = 31;
int R, C, W, T;
int arr[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> W;

    T = R + W;
    arr[1][1] = 1;
    arr[2][1] = 1;
    arr[2][2] = 1;

    for (int i = 3; i <= T; i++) {
        arr[i][1] = 1;
        arr[i][i] = 1;
        for (int j = 2; j <= i; j++) {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    int sum = 0;
    int k = C+1;
    for (int i = R; i < T; i++) {
        for (int j = C; j < k; j++) {
            sum += arr[i][j];
        }
        k++;
    }

    cout << sum;

    return 0;
}