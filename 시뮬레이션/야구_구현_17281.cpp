// 17281
#include <iostream>
#include <algorithm>
#include <vector>
#define I 51
#define P 10
using namespace std;

int N, answer;
bool player[P];
int order[P];
int status[I][P];
bool base[4];

enum {
    OUT, SINGLE, DOUBLE, TRIPLE, HOMERUN
};

void homerun(int& score) {
    score++;
                
    for (int h = 1; h <= 3; h++) {
        if (base[h] == true) {
            base[h] = false;
            score++;
        }
    }
}

void gobase(int hit, int& score) {
    for (int i = 3; i >= 1; i--) {
        if (base[i] == true) {
            if (i + hit > 3) {
                score++;
                base[i] = false;
            }
            else {
                base[i + hit] = true;
                base[i] = false;
            }
        }
    }

    base[hit] = 1;
}

void run() {
    int maxScore = 0, j = 1;

    for (int i = 1; i <= N; i++) {
        fill(base, base + 4, false);
        int outcount = 0;
        int score = 0;

        while (outcount < 3) {
            if (j == P) j = 1;

            int hit = status[i][order[j]];

            if (hit == SINGLE) gobase(hit, score);
            else if (hit == DOUBLE) gobase(hit, score);
            else if (hit == TRIPLE) gobase(hit, score);
            else if (hit == HOMERUN) homerun(score);
            else if (hit == OUT) outcount++;

            j++;
        }

        maxScore += score;
    } 

    answer = max(answer, maxScore);
}

void orderCase(int level) {
    if (level == P) {
        run();
        return;
    }

    for (int i = 1; i < P; i++) {
        if (player[i]) continue;

        player[i] = true;
        order[i] = level;
        orderCase(level + 1);
        player[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < P; j++) {
            cin >> status[i][j];
        }
    }

    // 1번 선수를 4번 타자로 고정
    player[4] = true;
    order[4] = 1;

    orderCase(2);

    cout << answer << '\n';

    return 0;
}
