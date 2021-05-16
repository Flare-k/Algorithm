#include <iostream>
using namespace std;

int map[7][3] = {0};
int acc[7][3] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        acc[0][i] = map[0][i];
    }
    
    int dy[3] = {-1, 0, 1};

    for (int i = 1; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i][j] == 0) continue;

            for (int k = 0; k < 3; k++) {
                int nx = i - 1;
                int ny = j + dy[k];

                if (nx < 0 || ny < 0 || nx >= 7 || ny >= 3) continue;
                if (map[nx][ny] == 0) continue;

                if (acc[i][j] < acc[nx][ny] + map[i][j]) {
                    acc[i][j] = acc[nx][ny] + map[i][j];
                }
            }
        }
    }

    int maxScore = -21e8;
    for (int i = 0; i < 3; i++) {
        if (maxScore < acc[6][i]) maxScore = acc[6][i];
    }

    cout << maxScore;

    return 0;
}