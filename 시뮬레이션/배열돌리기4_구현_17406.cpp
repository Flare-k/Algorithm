#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAX = 51;

int N, M, K;
int arr[MAX][MAX];
int cpy[MAX][MAX];
int minn = 21e8;
unordered_map<string, bool> m;

struct Node {
    int r, c, s, idx;
};

Node iter[6];

bool cmp(Node a, Node b) {
    if (a.idx < b.idx) return true;
    return false;
}

void sumRow() {
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= M; j++) {
            sum += arr[i][j];
        }
        minn = min(minn, sum);
    }
}

void rotateArray(int r, int c, int s) {
    for (int k = s; k > 0; k--) {

        int tmp = arr[r-k][c+k];

        // 좌->우
        for (int i = c+k; i > c-k; i--) {
            arr[r-k][i] = arr[r-k][i-1];
        }

        // 하->상
        for (int i = r-k; i < r+k; i++) {
            arr[i][c-k] = arr[i+1][c-k];
        }

        // 우->좌
        for (int i = c-k; i < c+k; i++) {
            arr[r+k][i] = arr[r+k][i+1];
        }

        // 상->하
        for (int i = r+k; i > r-k; i--) {
            arr[i][c+k] = arr[i-1][c+k];
        }

        arr[r-k+1][c+k] = tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    memcpy(cpy, arr, sizeof(arr));

    int r, c, s;
    for (int i = 0; i < K; i++) {
        cin >> r >> c >> s;
        iter[i] = {r, c, s, i + 1};
    }

    sort(iter, iter + 6, cmp);

    do {
        memcpy(arr, cpy, sizeof(cpy));

        for (int i = 0; i < 6; i++) {
            if (iter[i].idx != 0) {
                Node now = iter[i];
                rotateArray(now.r, now.c, now.s);
            }
        }

        sumRow();

    } while (next_permutation(iter, iter + 6, cmp));


    cout << minn;

    return 0;
}