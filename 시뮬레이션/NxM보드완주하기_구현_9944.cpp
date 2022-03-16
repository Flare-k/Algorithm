// NxM보드완주하기_구현_9944.cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 31
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int N, M, answer;
int arr[MAX][MAX];
bool visit[MAX][MAX];

bool exit() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0 && !visit[i][j]) return false;
        }
    }

    return true;
}

bool possible(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (visit[nx][ny] || arr[nx][ny] == 1) continue;

        return true;
    }

    return false;
}

void DFS(int x, int y, int level) {
    visit[x][y] = true;
    
    if (!possible(x, y)) {
        if (exit()) answer = min(answer, level);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        bool flag = false;

        while (1) {
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
            if (visit[nx][ny] || arr[nx][ny] == 1) break;

            visit[nx][ny] = true;
            nx += dx[i];
            ny += dy[i];

            flag = true;
        }

        nx -= dx[i];
        ny -= dy[i];

        if (flag) {
            
            DFS(nx, ny, level + 1);

            while (nx != x || ny != y) {
                visit[nx][ny] = false;
                nx -= dx[i];
                ny -= dy[i];
            }
        }
        
    }
}

void init(int r, int c, int cnt) {
    N = r;
    M = c;

    char ch;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ch;

            if (ch == '.') arr[i][j] = 0;
            else if (ch == '*') arr[i][j] = 1;
        }
    }

    answer = 21e8;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                memset(visit, false, sizeof(visit));
                DFS(i, j, 0);
            }
        }
    }

    if (answer == 21e8) answer = -1;
    
    cout << "Case " << cnt << ": " << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 1;
    int r, c;

    while (cin >> r >> c) {
        if (cin.eof()) break;

        init(r, c, cnt);
        cnt++;
    }

    return 0;
}