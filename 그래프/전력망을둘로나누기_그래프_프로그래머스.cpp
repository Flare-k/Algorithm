#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 101;
bool visit[MAX][MAX];
bool used[MAX];
vector<int> graph[MAX];
int cnt;

/*
    wire에 대해서 n번 반복하면서
    한 wire마다 연결을 끊고 두 트리가 몇개의 노드와 연결되어있는지 카운팅함
    카운팅이 끝나면 wire는 다시 연결함(visit[x][y] = true)
*/

void DFS(int node) {
    used[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (!used[next] && visit[node][next] && visit[next][node]) {
            cnt++;
            DFS(next);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int maxx = -21e8;

    for (auto wire : wires) {
        int x = wire[0];
        int y = wire[1];
        maxx = max(maxx, max(x, y));
        
        visit[x][y] = true;
        visit[y][x] = true;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> tmp;
    int minn = 21e8;

    for (auto wire : wires) {
        int count = 0;
        memset(used, false, sizeof(used));
        tmp.clear();
        int x = wire[0];
        int y = wire[1];
        visit[x][y] = false;
        visit[y][x] = false;

        for (int i = 1; i <= maxx; i++) {
            if (!used[i]) {
                count++;
                cnt = 1;
                DFS(i);
                tmp.push_back(cnt);
                if (count == 2) break;
            }
        }

        minn = min(minn, abs(tmp[0] - tmp[1]));
        visit[x][y] = true;
        visit[y][x] = true;
    }

    return minn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> wires ={{1, 3},
                                {2, 3},
                                {3, 4},
                                {4, 5},
                                {4, 6},
                                {4, 7},
                                {7, 8},
                                {7, 9} };

    cout << solution(9, wires) << '\n';

    return 0;
}