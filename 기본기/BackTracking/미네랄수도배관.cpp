#include <iostream>
using namespace std;

int maxScore = -21e8;

int pipe[11][11];
int N;

void run(int level, int score) {
    if (level == N - 1) {
        if (maxScore < score) maxScore = score;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (pipe[level + 1][i] == 0) continue;
        run(level + 1, score * pipe[level + 1][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> pipe[i][j];
        }   
    }

    for (int i = 0; i < N; i++) {
        run(0, pipe[0][i]);
    }

    cout << maxScore;

    return 0;
}

/*

4
3 4 -2 6
0 -4 4 1
-4 4 0 -2
5 1 6 9

> 864
*/