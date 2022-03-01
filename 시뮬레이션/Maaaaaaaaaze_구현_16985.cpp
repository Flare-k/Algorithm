#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 5
using namespace std;

const int dh[6] = {0, 0, 0, 0, -1, 1};
const int dx[6] = {-1, 1, 0, 0, 0, 0};
const int dy[6] = {0, 0, -1, 1, 0, 0};
int miro[MAX][MAX][MAX];
int mazes[MAX][MAX][MAX];
int tmp[MAX][MAX];
bool visit[MAX][MAX][MAX];
enum { WALL, EMPTY };
struct Node { int h, x, y, dist; };
vector<int> iter = {0, 1, 2, 3, 4};
int answer;

void clockwise(int h) {
    memset(tmp, 0, sizeof(tmp));

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            tmp[j][MAX - i - 1] = mazes[h][i][j];
        }
    }

    memcpy(mazes[h], tmp, sizeof(mazes[h]));
}

void run() {
    memset(visit, false, sizeof(visit));
    queue<Node> q;
    q.push({0, 0, 0, 0});
    visit[0][0][0] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (now.h == 4 && now.x == 4 && now.y == 4) {
            answer = min(answer, now.dist);
            break;
        }

        for (int i = 0; i < 6; i++) {
            int nh = now.h + dh[i];
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nh < 0 || nh >= MAX || nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
            if (visit[nh][nx][ny]) continue;
            if (mazes[nh][nx][ny] == WALL) continue;

            visit[nh][nx][ny] = true;
            q.push({nh, nx, ny, now.dist + 1});
        }
    }
}

void init() {
    answer = 21e8;

    for (int h = 0; h < MAX; h++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                cin >> mazes[h][i][j];
                miro[h][i][j] = mazes[h][i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    do {
        for (int h = 0; h < MAX; h++) {
            memcpy(mazes[h], miro[iter[h]], sizeof(mazes[h]));
        }

        for (int i = 0; i < 4; i++) {
            if (i != 0) clockwise(0);
            for (int j = 0; j < 4; j++) {
                if (j != 0) clockwise(1);
                for (int k = 0; k < 4; k++) {
                    if (k != 0) clockwise(2);
                    for (int a = 0; a < 4; a++) {
                        if (a != 0) clockwise(3);
                        for (int b = 0; b < 4; b++) {
                            if (b != 0) clockwise(4);
                            
                            if (mazes[0][0][0] == WALL || mazes[4][4][4] == WALL) continue;
                            run();
                        }
                    }
                }
            }
        }


    } while (next_permutation(iter.begin(), iter.end()));

    if (answer == 21e8) cout << -1 << '\n';
    else cout << answer << '\n';

    return 0;
}