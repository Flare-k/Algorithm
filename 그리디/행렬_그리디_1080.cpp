#include <iostream>
#include <string>
using namespace std;

// 3x3의 크기로 연산을 수행할 수 있다.

bool check[50][50];  // 뒤집어졌는지 확인

void trans(int r, int c) {
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            check[i][j] = !check[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> r >> c;

    int A[r][c];
    int B[r][c];

    for (int i = 0; i < r; i++) {
        string rowA;
        cin >> rowA;
        for (int j = 0; j < c; j++) {
            A[i][j] = rowA[j] - '0';
        }
    }

    for (int i = 0; i < r; i++) {
        string rowB;
        cin >> rowB;
        for (int j = 0; j < c; j++) {
            B[i][j] = rowB[j] - '0';
            if (B[i][j] != A[i][j]) check[i][j] = true;
        }
    }

    int ans = 0;
    // 3x3씩 바꿀 수 있으므로 그 이하의 크기의 경우 A,B가 다른 행렬이면 -1
    if (r < 3 || c < 3) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (check[i][j]) {
                    ans = -1;
                    cout << ans;
                    return 0;
                }
            }
        }
    }
    else {
        for (int i = 0; i <= r - 3; i++) {
            for (int j = 0; j <= c - 3; j++) {
                if (check[i][j]) {
                    trans(i, j);
                    ans++;
                }
            }
        }
    }

    // 마지막으로 안 바뀐 곳이 있는지 다시 확인
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (check[i][j]) {
                ans = -1;
            }
        }
    }

    cout << ans;

    return 0;
}