#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

struct Node {
    int x, y;
};
int N, M, L, K;
Node board[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> L >> K;

    for (int i = 0; i < K; i++) {
        cin >> board[i].x >> board[i].y;
    }

    int answer = 0;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            int cnt = 0;
            for (int k = 0; k < K; k++) {
                if (board[i].x <= board[k].x && board[k].x <= board[i].x + L && board[j].y <= board[k].y && board[k].y <= board[j].y + L) cnt++;
            }

            answer = max(answer, cnt);
        }
    }

    cout << K - answer << '\n';

    return 0;
}