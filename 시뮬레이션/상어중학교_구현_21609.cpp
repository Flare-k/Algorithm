#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10; // 21로 변경예정
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

vector<Node> blocks;

void rotateArray() {
    memcpy(cpy, arr, sizeof(arr));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[N-j+1][i] = cpy[i][j];
        }
    }
}

void gravity() {
    int j;
    for (int i = 0; i < N; i++) {
        j = N - 1;

        while (1) {
            if (arr[j][i])
        }
    }
}

void run(int x, int y, int color) {
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
            
            if (arr[nx][ny] == 0) rainbow++;

            size++;
            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
    blocks.push_back({color, x, y, size, rainbow});
}

void removeBlock(int x, int y) {
    queue<Dir> q;

    q.push({x, y});

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (arr[nx][ny] != color) continue;
            
            arr[nx][ny] = -2;
            q.push({nx, ny});
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
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cnt++;
                if (!visit[i][j] && arr[i][j] > 0) {
                    run(i, j, arr[i][j]);
                    cnt--;
                }
            }
        }
        
        if (cnt == N*N) break;

        // 큰 블록 찾기
        sort(blocks.begin(), blocks.end(), cmp);

        // 블록 제거
        Node bigBlock = blocks.front();
        removeBlock(bigBlock.x, bigBlock.y);
        score += (bigBlock.size * bigBlock.size);

        gravity();  // 중력
        rotateArray();  // 회전
        gravity();  // 중력
    }


    return 0;
}