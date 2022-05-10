#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 11
#define INF 987654321
using namespace std;

int N, K;
int board[MAX][MAX];
int answer;

void run() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j || j == k || k == i) continue;
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    run();

    vector<int> tmp;

    for (int i = 0; i < N; i++) {
        tmp.push_back(i);
    }

    answer = INF;

    do {
        if (tmp[0] != K) continue;

        int dist = 0;

        for (int i = 0; i < N - 1; i++) {
            int now = tmp[i];
            int next = tmp[i + 1];
            dist += board[now][next];
        }

        answer = min(answer, dist);

    } while (next_permutation(tmp.begin(), tmp.end()));

    cout << answer << '\n';

    return 0;
}