#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int arr[101][101][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n, k;
    cin >> t;

    arr[1][0][0] = 1;
    arr[1][0][1] = 1;

    for (int i = 2; i < 101; i++) {
        for (int j = 0; j < i; j++) {
            // 마지막 비트가 0인데 길이는 n이고 연속된 비트가 k인 수열의 개수는 길이 n-1짜리에서 마지막 비트가 0, 1인 두 개의 수를 합치면 된다.
            arr[i][j][0] = arr[i - 1][j][0] + arr[i - 1][j][1];
            // 마지막 비트가 0이고 k개 연속 비트 수에 1를 추가하면 되고,
            // 마지막 비트가 1이고 k-1개 연속 비트에 1를 붙이면 k개 연속 비트가 된다.
            arr[i][j][1] = arr[i - 1][j][0] + arr[i - 1][j - 1][1];
        }
    }

    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        cout << arr[n][k][0] + arr[n][k][1] << '\n';
    }

    return 0;
}