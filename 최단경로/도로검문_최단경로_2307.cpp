#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
#define INF 999999999
using namespace std;

struct Node {
    int node, dist;
};
int N, M;
vector<Node> graph[MAX];
vector<int> path;
vector<int> d;
bool flag;
int city1, city2;

int dijkstra() {
    priority_queue<pair<int, int>> pq;
    d.clear();
    d.resize(N + 1, INF);
    d[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].node;
            int cost = graph[now][i].dist + dist;

            if (city1 == now && city2 == next) continue;
            if (city1 == next && city2 == now) continue;
            if (cost < d[next]) {
                if (flag) path[next] = now;
                d[next] = cost;
                pq.push({-cost, next});
            }
        }
    }

    return d[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    path.resize(N + 1, -1);
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }

    path[1] = 1;
    flag = true;
    int fTime = dijkstra();
    flag = false;

    int answer = 0;
    for (int i = N; i != path[i]; i = path[i]) {
        city1 = i;
        city2 = path[i];
        // 지금까지 온 경로들을 막으면서 최단거리 구하기
        answer = max(answer, dijkstra());
        if (answer == INF) break;
    }

    if (answer == INF) cout << -1 << '\n';
    else cout << answer - fTime << '\n';

    return 0;
}