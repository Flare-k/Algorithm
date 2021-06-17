#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int start, endN;
struct Node {
    int node, dist;
};

bool operator<(Node a, Node b) {
    return a.dist >= b.dist;
}

vector<Node> g[1002];
int d[1002];    // 비용

void run(int s) {
    priority_queue<Node> pq;
    pq.push({s, 0});    // node, dist
    d[s] = 0;

    while (!pq.empty()) {
        int node = pq.top().node;
        int dist = -pq.top().dist;
        pq.pop();

        if (d[node] < dist) continue;

        for (int i = 0; i < g[node].size(); i++) {
            int cost = dist + g[node][i].dist;
            int targetNode = g[node][i].node;

            if (cost < d[targetNode]){
                d[targetNode] = cost;
                pq.push({targetNode, -cost});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int node, cnt;
    cin >> node >> cnt;

    int a, b, c;
    for (int i = 0; i < cnt; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    fill(d, d + 1002, INF);

    cin >> start >> endN;

    run(start);

    cout << d[endN];

    return 0;
}