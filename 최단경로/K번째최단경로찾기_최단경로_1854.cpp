#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define INF 1e9
using namespace std;

// k 번쨰 최단 경로
const int MAX = 1001;
int n, m, k, a, b, c;
priority_queue<int> d[MAX];
vector<pair<int, int>> graph[MAX];

void dijkstra(int start) {
    d[start].push(0);
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});    // 가중치, 노드

    while (!pq.empty()){
        int dist = -pq.top().first; // 가중치
        int now = pq.top().second;  // 노드
        pq.pop();

        for (int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i].first;
            int cost = dist + graph[now][i].second;
            
            if (d[next].size() < k || d[next].top() > cost) {
                if (d[next].size() == k) d[next].pop();

                d[next].push(cost);
                pq.push({-cost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    dijkstra(1);

    for (int i = 1; i <= n; i++) {
        if (d[i].size() != k) cout << -1 << '\n';
        else cout << d[i].top() << '\n';
    }

    return 0;
}