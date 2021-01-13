#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define INF 1e9
using namespace std;

int n, m, start;
vector<pair<int, int>> graph[300001];
int d[300001];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;  // {거리, 현재노드}
    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;
        // pq(거리, 노드)
        // graph[출발](도착, 거리)
        for (int i = 0; i < graph[now].size(); i++){
            int cost = dist + graph[now][i].second; // 가중치 합 = 현재 가중치 + 다음의 가중치

            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> start;

    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    fill(d, d + 300001, INF);

    dijkstra(start);

    for (int i = 1; i <= n; i++){
        if (d[i] == INF){
            cout << "INF" << '\n';
        }
        else{
            cout << d[i] << '\n';
        }
    }

    return 0;
}