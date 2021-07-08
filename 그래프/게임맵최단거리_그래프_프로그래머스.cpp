#include<iostream>
#include<vector>
#include <cstring>
#include <queue>
#define MAX 101
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
bool visit[MAX][MAX];

struct Node {
    int x, y;
};

int solution(vector<vector<int>> maps) {
    memset(visit, false, sizeof(visit));
    queue<Node> q;
    
    q.push({0, 0});
    visit[0][0] = true;

    int r = maps.size();
    int c = maps[0].size();

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (maps[nx][ny] == 0) continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny] = true;
            maps[nx][ny] += maps[now.x][now.y];
            q.push({nx, ny});
        }
    }

    return visit[r - 1][c - 1] == true ? maps[r - 1][c - 1] : -1;
}

int main() {
    int result = solution({  {1, 0, 1, 1, 1},
                             {1, 0, 1, 0, 1},
                             {1, 0, 1, 1, 1},
                             {1, 1, 1, 0, 1},
                             {0, 0, 0, 0, 1}});

    cout << result;

    return 0;
}