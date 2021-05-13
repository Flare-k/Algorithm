#include <iostream>
#include <algorithm>
#include <vector>
#define XX -999999
using namespace std;

// 술 주정뱅이... 집까지 오는데 최대정수 출력.. 방향 (/ | \)

int dir[6][4];
int acc[6][4] = {3, 2, 5, 1};
int roads[6][4] = {
    3, 2, 5, 1,
    -7, -5, 3, XX,
    1, -5, XX, 4,
    4, XX, -8, -9,
    5, XX, -1, -2,
    4, 2, 6, XX
};

enum {
    LEFT,   // 0
    UP,   // 1
    RIGHT   // 2
};

int main() {

    int direct[3] = {-1, 0, 1};
    int ans = 0;
    
    for (int i = 1; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (roads[i][j] == XX) continue;

            for (int k = 0; k < 3; k++) {
                int nx = i - 1;
                int ny = j + direct[k];

                if (nx < 0 || ny < 0 || nx >= 6 || ny >= 4) continue;
                if (roads[nx][ny] == XX) continue;

                if (acc[i][j] < roads[i][j] + acc[nx][ny]) {
                    acc[i][j] = roads[i][j] + acc[nx][ny];
                }
            }
        }
    }

    
    for (int i = 0; i < 4; i++) {
        if (acc[5][i] > ans) ans = acc[5][i];
    }

    cout << ans;

    return 0;
}