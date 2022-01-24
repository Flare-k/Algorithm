#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int N, M, K, X;
const int MAX = 300001;
int d[MAX];
struct Node {
    int next, dist;
};
vector<Node> g[MAX];

void run(int node) {
    fill(d, d + (N + 1), 1e9);
    priority_queue<pair<int, int>> pq;
    pq.push({0, node});
    d[node] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;

        for (int i = 0; i < g[now].size(); i++) {
            int cost = dist + g[now][i].dist;
            int next = g[now][i].next;

            if (cost < d[next]) {
                d[next] = cost;
                pq.push({-cost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        g[s].push_back({e, 1});
    }

    run(X);

    bool flag = false;
    for (int i = 1; i<= N; i++) {
        if (d[i] == K) {
            cout << i << '\n';
            flag = true;
        }
    }

    if (!flag) cout << -1 << '\n';

    return 0;
}