#include <iostream>
using namespace std;
/*
    / | \ 의 방향으로만 움직였을 때 합이 가장 큰 값은?
    level : 5 (아래로 총 다섯번 가야 리턴하므로)
    branch : 3 (세 방향이므로)
*/

int dy[3] = {0, -1, 1};

int map[5][4] = {
    3, 2, 4, 1,
    0, 1, 0, 5,
    2, 0, 3, 0,
    5, 4, 0, 2,
    2, -5, 0, 3
};

int maxSum = -21e8; // -21억


void run(int level, int now, int sum) {
    if (level == 5) {
        if (maxSum < sum) {
            maxSum = sum;
        }
        return;
    }

    for (int i = 0; i < 3; i++) {
        int ny = now + dy[i];
        if (ny < 0 || ny >= 4) continue;
        if (map[level][ny] == 0) continue;

        run(level + 1, ny, sum + map[level][ny]);
    }

}

int main() {

    for (int i = 0; i < 4; i++){
        run(0, i, 0);
    }
    
    cout << maxSum;

    return 0;
}