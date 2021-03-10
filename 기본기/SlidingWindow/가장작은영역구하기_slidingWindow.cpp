#include <iostream>
using namespace std;

/*
  배열에서 연속 되어있는 네 칸의 합을 구했을 때,
  가장 작은 값이 몇 인지 출력
*/

int main() {
    int n;
    cin >> n;

    int arr[100001];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += arr[i];
    }

    int minSum = 987654321;
    for (int i = 0; i <= n - 4; i++) {
        if (minSum > sum) minSum = sum;

        if (i == n - 4) break;

        sum -= arr[i];
        sum += arr[i + 4];
    }

    cout << minSum << '\n';

    return 0;
}