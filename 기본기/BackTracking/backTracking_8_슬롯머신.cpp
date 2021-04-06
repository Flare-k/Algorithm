#include <iostream>
using namespace std;

/*
  1. 바닥 조건
  2. 함수 인터페이스
  3. 가지치기
  4. 복구 유무
*/

int slot[3][4] {
    -3, 7, 5, -7,
    7, 4, -7, 1,
    1, 2, 7, -3
};

// 슬롯 머신을 돌렸을 때 가운데 행의 MAX 값을 구해라

int maxScore = -21e8;

void spin(int idx) {
    int back = slot[2][idx];
    slot[2][idx] = slot[1][idx];
    slot[1][idx] = slot[0][idx];
    slot[0][idx] = back;
}

int centerScore() {
    int score = 0;
    score = slot[1][0] * slot[1][1] * slot[1][2] * slot[1][3];

    return score;
}

void run(int level, int score) {
    if (level == 4) {
        if (maxScore < score) {
            maxScore = score;
        }

        return;
    }

    for (int j = 0; j < 3; j++) {
        spin(level);
        run(level + 1, score * slot[1][level]);
    }
    // spin(level);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    run(0, 1);

    cout << maxScore;

    return 0;
}