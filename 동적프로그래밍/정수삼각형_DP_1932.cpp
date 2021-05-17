#include <iostream>
#include <cstring>
using namespace std;

int triangle[501][501];
int acc[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(triangle, -1, sizeof(triangle));
    memset(acc, -1, sizeof(acc));

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> triangle[i][j];
        }
    }

    acc[0][0] = triangle[0][0];
    
    int dy[2] = {-1, 0};
    
    // 현재 위치에서 이전의 대각선 왼쪽, 오른쪽 중 더했을 때 최대값으로 갱신
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (triangle[i][j] == -1) continue;

            for (int k = 0; k < 2; k++) {
                int px = i - 1;     // pre_X
                int py = j + dy[k]; // pre_Y

                if (j == 0) py = 0;

                if (px < 0 || py < 0 || px >= n || py >= i + 1) continue;       // py는 0 ~ i + 1개
                if (acc[px][py] == -1) continue;

                if (acc[i][j] < acc[px][py] + triangle[i][j]) {
                    acc[i][j] = acc[px][py] + triangle[i][j];
                }
            }
        }
    }

    int maxRoute = -21e8;
    for (int i = 0; i < n; i++) {
        if (maxRoute < acc[n - 1][i]) maxRoute = acc[n - 1][i];
    }

    cout << maxRoute;

    return 0;
}