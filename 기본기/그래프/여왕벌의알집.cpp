#include <iostream>
#include <queue>
using namespace std;

int beeHive[4][9];  // 배열의 숫자들은 벌의 종류를 의미
bool check[4][9];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Bee {
    int x, y, type;
};

queue<Bee> bee;

int BFS(int a, int b, int type) {
    bee.push({a, b, type});
    check[a][b] = true;

    int ans = 0;

    while (!bee.empty()) {
        Bee tmpBee = bee.front();
        int x = tmpBee.x;
        int y = tmpBee.y;
        ans++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 9) continue;
            if (beeHive[nx][ny] != type) continue;
            if (check[nx][ny]) continue;

            check[nx][ny] = true;
            bee.push({nx, ny, type});
        }
        
        bee.pop();
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> beeHive[i][j];
        }
    }

    int maxCnt = -21e8;
    int maxNum;
    int arr[10] = {0, };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 9; j++) {
            if (!check[i][j]) {
                int type = beeHive[i][j];
                arr[type] = max(arr[type], BFS(i, j, type));
                
                if (maxCnt < arr[type]) {
                    maxCnt = arr[type];
                    maxNum = arr[type] * type;
                }
                
            }
        }
    }

    cout << maxNum;

    return 0;
}

/*
0 1 2 1 4 8 3 1 3
2 3 2 3 4 2 3 1 3
2 2 2 3 4 3 4 3 3
0 2 1 3 4 2 1 3 2
> 14


0 1 2 1 4 8 3 1 3
2 3 1 3 4 2 3 1 3
2 2 2 3 3 3 3 3 3
0 2 1 3 4 2 1 3 2
> 39
*/