#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX = 1003;
int d[MAX];
int path[MAX];
int n, m, start, dest;

struct Node {
    int next, dist;
};

vector<Node> g[MAX];

void run(int node) {
    fill(d, d + MAX, 1e9);
    priority_queue<pair<int, int>> pq;
    pq.push({0, node});
    d[node] = 0;
    
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (now == dest) break;
        if (d[now] < dist) continue;

        for (int i = 0; i < g[now].size(); i++) {
            int cost = dist + g[now][i].dist;
            int next = g[now][i].next;

            if (cost < d[next]) {
                d[next] = cost;
                path[next] = now;
                pq.push({-cost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int s, e, dist;
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> dist;
        g[s].push_back({e, dist});
    }

    cin >> start >> dest;

    run(start);

    vector<int> tmp;

    int idx = dest;

    while (idx) {
        tmp.push_back(idx);
        idx = path[idx];
    }

    cout << d[dest] << '\n';
    cout << tmp.size() << '\n';

    // 내림차순 정렬했다가 계속 틀렸음;; 경론데..
    for (int i = tmp.size() - 1; i >= 0; i--) {
        cout << tmp[i] << ' ';
    }
    cout << '\n';

    return 0;
}