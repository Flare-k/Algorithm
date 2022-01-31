#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

// 출처:
// https:  // rebas.kr/788 [PROJECT REBAS]

int N, L;
int arr[MAX][MAX];
int answer;

void run(int i, int c) {
    int cnt = 1;
    for (int j = 0; j < N - 1; j++) {
        int d = c == 1 ? arr[i][j + 1] - arr[i][j] : arr[j + 1][i] - arr[j][i];
        if (d == 0) cnt++;
        else if (d == 1 && cnt >= L) cnt = 1;
        else if (d == -1 && cnt >= 0) cnt = -L + 1;
        else return;
    }
    if (cnt >= 0) answer += 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        run(i, 1);
        run(i, 0);
    }

    cout << answer;

    return 0;
}