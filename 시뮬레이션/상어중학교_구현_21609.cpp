#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 21;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int N, M;
int arr[MAX][MAX];
int cpy[MAX][MAX];
bool visit[MAX][MAX];
int score;

struct Node {
    int color, x, y, size, rainbow;
};

struct Dir {
    int x, y;
};

vector<Node> blocks;

bool cmp(Node a, Node b) {
    if (a.size> b.size) return true;
    else if (a.size == b.size) {
        if (a.rainbow > b.rainbow) return true;
        else if (a.rainbow == b.rainbow) {
            if (a.x > b.x) return true;
            else if (a.x == b.x) return a.y > b.y;
        }
    }
    return false;
}

void rotateArray() {
    memcpy(cpy, arr, sizeof(arr));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[N-j-1][i] = cpy[i][j];
        }
    }
}

void gravity() {
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 1; j--) {
            if (arr[j][i] == -2) {
                for (int k = j - 1; k >= 0; k--) {
                    if (arr[k][i] >= 0) {
                        arr[j][i] = arr[k][i];
                        arr[k][i] = -2;
                        break;
                    }
                    else if (arr[k][i] == -1) break;
                }
            }
        }
    }
}

void findBlockGroups(int x, int y, int color) {
    queue<Dir> q;

    visit[x][y] = true;
    q.push({x, y});

    int rainbow = 0, size = 1;

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visit[nx][ny] || arr[nx][ny] < 0) continue;
            if (arr[nx][ny] != 0 && arr[nx][ny] != color) continue;
            
            if (arr[nx][ny] == 0) {rainbow++;}

            size++;
            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
    // 무지개 방문 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 0 && visit[i][j]) visit[i][j] = false;
        }
    }

    if (size >= 2)
        blocks.push_back({color, x, y, size, rainbow});
}

void removeBlock(int x, int y, int color) {
    memset(visit, false, sizeof(visit));
    queue<Dir> q;
    
    visit[x][y] = true;
    arr[x][y] = -2;
    q.push({x, y});

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (arr[nx][ny] != 0 && arr[nx][ny] != color) continue;
            if (visit[nx][ny] == true) continue;
            
            visit[nx][ny] = true;
            arr[nx][ny] = -2;
            q.push({nx, ny});
        }
    }
}

void checkBlock() {
    blocks.clear();
    memset(visit, false, sizeof(visit));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j] && arr[i][j] > 0) {
                findBlockGroups(i, j, arr[i][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    while (1) {
        // 큰 블록 찾기
        checkBlock();
        if (blocks.size() == 0) break;

        sort(blocks.begin(), blocks.end(), cmp);

        // 블록 제거
        Node big = blocks.front();
        removeBlock(big.x, big.y, big.color);
        score += (big.size * big.size);

        gravity();      // 중력
        rotateArray();  // 회전
        gravity();      // 중력
    }

    cout << score;

    return 0;
}
/*
6 3
1 1 1 0 0 0
1 1 1 0 0 0
1 1 3 0 0 0
0 0 0 2 2 2
0 0 0 2 2 2
0 0 0 2 2 2

> 793

5 3
0 0 0 0 1
-1 -1 0 -1 0
-1 -1 3 -1 -1
-1 -1 0 -1 -1
0 0 2 0 0

> 74
*/