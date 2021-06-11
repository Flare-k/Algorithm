#include <iostream>
using namespace std;

int map[101][11] = {0};
int acc[101][11] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < c; i++) {
        acc[0][i] = map[0][i];
    }
    
    int dy[3] = {-1, 0, 1};

    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 0) continue;

            for (int k = 0; k < 3; k++) {
                int nx = i - 1;
                int ny = j + dy[k];

                if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                if (map[nx][ny] == 0) continue;

                if (acc[i][j] < acc[nx][ny] + map[i][j]) {
                    acc[i][j] = acc[nx][ny] + map[i][j];
                }
            }
        }
    }

    int maxScore = -21e8;
    for (int i = 0; i < c; i++) {
        if (maxScore < acc[r - 1][i]) maxScore = acc[r - 1][i];
    }

    cout << maxScore;

    return 0;
}