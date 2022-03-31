#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1501
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int arr[MAX][MAX];
bool visit[MAX][MAX];
int R, C, start_x, start_y;
int sx1, sy1, sx2, sy2;
bool Meet;
enum { WATER, ICE };
struct Node { int x, y; };
queue<Node> water, swan, waterToIce, swanToIce;

void meltIceburg() {
    while (!water.empty()) {
        Node now = water.front();
        water.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

            if (arr[nx][ny] == ICE) {
                arr[nx][ny] = WATER;
                waterToIce.push({nx, ny});
            }
        }
    }

}

void findSwan() {
    while (!swan.empty() && !Meet) {
        Node now = swan.front();
        swan.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny] = true;

            if (nx == sx2 && ny == sy2) {
                Meet = true;
                break;
            }
            else if (arr[nx][ny] == WATER) swan.push({nx, ny});
            else swanToIce.push({nx, ny});
        }
    }
}

void initQ() {
    while (!waterToIce.empty()) waterToIce.pop();
    while (!swanToIce.empty()) swanToIce.pop();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    char ch;
    int cnt= 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> ch;

            if (ch != 'X') {
                arr[i][j] = WATER;
                water.push({i, j});

                if (ch == 'L') {
                    cnt++;
                    if (cnt == 1) {
                        sx1 = i;
                        sy1 = j;
                    }
                    else {
                        sx2 = i;
                        sy2 = j;
                    }
                }
            }
            else if (ch == 'X') arr[i][j] = ICE;
        }
    }

    int answer = 0;
    visit[sx1][sy1] = true;
    swan.push({sx1, sy1});

    while (!Meet) {
        meltIceburg();
        if (Meet) break;
        findSwan();
        
        water = waterToIce;
        swan = swanToIce;

        initQ();

        answer++;
    }

    cout << answer << '\n';

    return 0;
}