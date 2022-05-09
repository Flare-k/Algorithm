#include <iostream>
#include <algorithm>
#include <string>
#define MAX 51
#define INF 987654321
using namespace std;

int board[MAX][MAX];
int N, answer;

void run() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j || j == k || k == i) continue;
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            else if (board[i][j] <= 2) cnt++;
        }

        answer = max(answer, cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            if (i == j) board[i][j] = 0;
            else if (s[j - 1] == 'Y') board[i][j] = 1;
            else if (s[j - 1] == 'N') board[i][j] = INF;
        }
    }

    run();

    cout << answer << '\n';

    return 0;
}