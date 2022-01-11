#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int MAX = 50001;
int d[MAX];
int N, M;

struct Node {
    int next, cost;
};

vector<Node> g[MAX];

void run(int node) {
    fill(d, d + MAX, 1e9);
    
    priority_queue<pair<int, int>> pq;
    pq.push({node, 0});

    while (!pq.empty()) {
        int now = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();

        if (d[now] < cost) continue;    // 현재 비용보다 작다면 패스

        for (int i = 0; i < g[now].size(); i++) {
            int ncost = cost + g[now][i].cost;

            if (ncost < d[g[now][i].next]) {    // 다음 노드에 누적된 값보다 ncost가 작으면? 갱신필요
                d[g[now][i].next] = ncost;
                pq.push({g[now][i].next, -ncost});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int A, B, C;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        g[A].push_back({B, C});
        g[B].push_back({A, C});
    }

    run(1);

    cout << d[N];

    return 0;
}