#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// 이동방향 아래 - 우 - 좌 상향  .. 반복

vector<int> solution(int n) {
    vector<int> answer;

    int snail[n + 1][n + 1];
    memset(snail, 0, sizeof(snail));

    int target = 1;
    int finalTarget = (n * (n + 1)) / 2;

    int top = 1;
    int bottom = n;
    int left = 0;
    int right = 1;

    int direction = 0;  // 0 = 아래, 1 = 오른쪽, 2 = 좌상향

    while (target <= finalTarget) {
        if (direction == 0) {
            for (int i = top; i <= bottom; i++) {
                snail[i][right] = target++;
            }
            top++;
            right++;
            direction = 1;
        }
        else if (direction == 1) {
            for (int i = right; i <= bottom - left; i++) {
                snail[bottom][i] = target++;
            }
            bottom--;
            direction = 2;
        }
        else if (direction == 2) {
            for (int i = bottom; i >= top; i--) {
                snail[i][i - left] = target++;
            }
            top++;
            left++;
            direction = 0;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (snail[i][j] != 0)
            answer.push_back(snail[i][j]);
        }
    }

    return answer;
}

int main() {

    for (int i = 0; i < solution(4).size(); i++){
        cout << solution(4)[i] << '\n';
    }
    // cout << solution(5) << '\n';
    // cout << solution(6) << '\n';
}