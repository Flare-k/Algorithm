#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

int arr[MAX][MAX];
int tmp[MAX][MAX];
int N, M, R;

void first() {
    // 상하 반전
    memset(tmp, 0, sizeof(tmp));
    
    for (int j = 0; j < M; j++) {
        for (int i = N - 1; i >= 0; i--) {
            tmp[N - 1 - i][j] = arr[i][j];
        }
    }

    memcpy(arr, tmp, sizeof(arr));
}

void second() {
    // 좌우 반전
    memset(tmp, 0, sizeof(tmp));

    for (int i = 0; i < N; i++) {
        for (int j = M - 1; j >= 0; j--) {
            tmp[i][M - 1 - j] = arr[i][j];
        }
    }

    memcpy(arr, tmp, sizeof(arr));
}

void third() {
    // 오른쪽으로 90도
    memset(tmp, 0, sizeof(tmp));

    for (int j = 0; j < M; j++) {
        int c = 0;
        for (int i = N - 1; i >= 0; i--) {
            tmp[j][c++] = arr[i][j];
        }
    }

    memcpy(arr, tmp, sizeof(arr));
    swap(N, M);
}

void fourth() {
    // 왼쪽으로 90도
    memset(tmp, 0, sizeof(tmp));

    int r = 0;
    for (int j = M - 1; j >= 0; j--) {
        int c = 0;
        for (int i = 0; i < N; i++) {
            tmp[r][c++] = arr[i][j];
        }
        r++;
    }

    memcpy(arr, tmp, sizeof(arr));
    swap(N, M);
}

void fifth() {
    memset(tmp, 0, sizeof(tmp));
    // 1 -> 2
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < M / 2; j++) {
            tmp[i][M / 2 + j] = arr[i][j];
        }
    }
    // 2 -> 3
    for (int i = 0; i < N / 2; i++) {
        for (int j = M / 2; j < M; j++) {
            tmp[N / 2 + i][j] = arr[i][j];
        }
    }
    // 3 -> 4
    for (int i = N / 2; i < N; i++) {
        for (int j = M / 2; j < M; j++) {
            tmp[i][j - M / 2] = arr[i][j];
        }
    }
    // 4 -> 1
    for (int i = N / 2; i < N; i++) {
        for (int j = 0; j < M / 2; j++) {
            tmp[i - N / 2][j] = arr[i][j];
        }
    }

    memcpy(arr, tmp, sizeof(arr));
}

void sixth() {
    memset(tmp, 0, sizeof(tmp));
    // 1 -> 4
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < M / 2; j++) {
            tmp[N / 2 + i][j] = arr[i][j];
        }
    }
    // 4 -> 3
    for (int i = N / 2; i < N; i++) {
        for (int j = 0; j < M / 2; j++) {
            tmp[i][M / 2 + j] = arr[i][j];
        }
    }
    // 3 -> 2
    for (int i = N / 2; i < N; i++) {
        for (int j = M / 2; j < M; j++) {
            tmp[i - N / 2][j] = arr[i][j];
        }
    }
    // 2 -> 1
    for (int i = 0; i < N / 2; i++) {
        for (int j = M / 2; j < M; j++) {
            tmp[i][j - M / 2] = arr[i][j];
        }
    }

    memcpy(arr, tmp, sizeof(arr));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    while (R--) {
        int oper;
        cin >> oper;

        if (oper == 1) first();
        else if (oper == 2) second();
        else if (oper == 3) third();
        else if (oper == 4) fourth();
        else if (oper == 5) fifth();
        else if (oper == 6) sixth();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}