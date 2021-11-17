#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 52;
char candy[MAX][MAX];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int N;
int maxx = -21e8;

int cntCandy() {
    int maxCnt = -21e8;
    int len;
    string target = "";
    
    // row
    for (int i = 0; i < N; i++) {
        target = candy[i][0];
        for (int j = 1; j < N; j++) {
            if (target.back() == candy[i][j]) target += candy[i][j];
            else {
                len = target.length();
                maxCnt = max(maxCnt, len);
                target = candy[i][j];
            }
        }

        len = target.length();
        maxCnt = max(maxCnt, len);
    }

    // column
    for (int i = 0; i < N; i++) {
        target = candy[0][i];
        for (int j = 1; j < N; j++) {
            if (target.back() == candy[j][i]) target += candy[j][i];
            else {
                len = target.length();
                maxCnt = max(maxCnt, len);
                target = candy[j][i];
            }
        }
        len = target.length();
        maxCnt = max(maxCnt, len);
    }

    return maxCnt;
}

void changeCandy() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            char cur = candy[x][y];

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (candy[nx][ny] == candy[x][y]) continue;

                swap(candy[nx][ny], candy[x][y]);
                maxx = max(maxx, cntCandy());
                swap(candy[nx][ny], candy[x][y]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> candy[i][j];
        }
    }

    changeCandy();

    cout << maxx;

    return 0;
}
