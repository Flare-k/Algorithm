#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define endl "\n"
#define INF 0x7fffffff
#define MAX 100001
using namespace std;
vector<pair<int, int> > arr[MAX];

int visit[MAX];
bool check[MAX];
int dist[MAX];
int sum;
int from, to, weight;

void BFS(int n) {
    queue<int> q;
    q.push(n);
    visit[n] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < arr[node].size(); i++) {
            if (!visit[arr[node][i].first]) {
                visit[arr[node][i].first] = true;
                q.push(arr[node][i].first);
                dist[arr[node][i].first] = dist[node] + arr[node][i].second;
                // 1~3의 거리는... 노드 1과 3의 거리 = 노드 1의 거리 + 노드 1과
                // 3의 가중치
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> from;
        while (1) {
            cin >> to;
            if (to == -1) {
                break;
            }
            cin >> weight;
            arr[from].push_back(make_pair(to, weight));
        }
    }

    // 임의로 설정한 루트 1번으로부터의 거리를 구하기 위한 bfs탐색
    BFS(1);

    // bfs를 통해 루트로 부터 각 점의 거리를 저장하였으므로 가장 먼 점을 찾음
    int farthest_point = 1;
    for (int i = 2; i <= n; i++) {
        if (dist[farthest_point] < dist[i]) {
            farthest_point = i;
        }
    }  // farthest_point = dist[5] == 11

    memset(visit, false, sizeof(visit));
    memset(dist, 0, sizeof(dist));

    // 앞에서 찾은 점을 루트로 하여 다시 이로부터의 각 점의 거리를 구함
    BFS(farthest_point);

    // 다시 루트로부터 가장 멀리 떨어진 점을 찾음
    for (int i = 1; i <= n; i++) {
        if (dist[farthest_point] < dist[i]) farthest_point = i;
    }

    // 루트로부터 가장 멀리 떨어진 점의 dist값을 출력
    cout << dist[farthest_point] << "\n";
    return 0;
}
/*
5
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1
*/