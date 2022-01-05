#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 200000000
using namespace std;

const int MAX = 801;
int N, E;
int v1, v2;
struct Node {
    int node, dist;
};
vector<Node> graph[MAX];
long long dp[MAX];

int run(int node, int dest) {
    fill(dp, dp + MAX, INF);
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, node});
    dp[node] = 0;

    while (!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dp[now] < dist) continue;

        for (int i = 0; i < graph[now].size(); i++){
            int cost = dist + graph[now][i].dist;
            
            if (cost < dp[graph[now][i].node]){
                dp[graph[now][i].node] = cost;
                pq.push({-cost, graph[now][i].node});
            }
        }
    }

    return dp[dest];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> E;

    int a, b, dist;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> dist;  // 양방향
        graph[a].push_back({b, dist});
        graph[b].push_back({a, dist});
    }

    cin >> v1 >> v2;    // 반드시 지나야하는 두 정점

    long long r1 = (run(1, v1) + run(v1, v2) + run(v2, N));
    long long r2 = (run(1, v2) + run(v2, v1) + run(v1, N));
    long long answer = min(r1, r2);

    if (answer >= INF) cout << -1;
    else cout << answer;

    return 0;
}