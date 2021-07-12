#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool visit[101][101];

struct Node {
    int x, y;
};

void run(int i, int j, int m, int n, int type, int& cnt, vector<vector<int>> picture) {
    queue<Node> q;
    q.push({i, j});
    visit[i][j] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (picture[nx][ny] != type) continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny] = true;
            q.push({nx, ny});
            cnt++;
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int typeSize = 0;
    int maxSize = -1;
    memset(visit, false, sizeof(visit));

    for (int i = 0; i < picture.size(); i++) {
        for (int j = 0; j < picture[i].size(); j++) {
            if (!visit[i][j] && picture[i][j] != 0) {
                int cnt = 1;
                run(i, j, m, n, picture[i][j], cnt, picture);
                maxSize = max(maxSize, cnt);
                typeSize++;
            }
        }
    }


    vector<int> answer(2);
    answer[0] = typeSize;
    answer[1] = maxSize;

    return answer;
}

int main() {
    
    vector<int> ans = solution(6, 4, {{1, 1, 1, 0},
                                    {1, 2, 2, 0}, 
                                    {1, 0, 0, 1},
                                    {0, 0, 0, 1},
                                    {0, 0, 0, 3},
                                    {0, 0, 0, 3}});

    for (int num : ans) {
        cout << num << ' ';
    }

    return 0;
}