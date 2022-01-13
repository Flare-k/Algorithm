#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 10001;
int d[MAX];
int T, n, cnt, idx;
struct Node {
    int next, dist;
};
vector<Node > graph[MAX];

void run(int node) {
    fill(d, d + MAX, 1e9);
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, node});
    d[node] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;

        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].dist;
            int next = graph[now][i].next;

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

    cin >> T;

    while (T--) {

        for (int i = 1; i <= n; i++) {  // 테스크 케이스 문제이므로 초기화 중요
            graph[i].clear();
        }

        cin >> n >> cnt >> idx;
        
        for (int i = 0; i < cnt; i++) {
            int a, b, s;
            cin >> a >> b >> s; // 컴퓨터 b가 감염되면 s초 후 컴퓨터 a도 감염됨을 뜻한다
            graph[b].push_back({a, s});
        }


        run(idx);

        int computer = 0, time = 0;
        for (int i = 1; i <= n; i++) {
            if (d[i] != 1e9) {
                computer++;
                time = max(time, d[i]);
            }
        }

        cout << computer << ' ' << time << '\n';
    }

    return 0;
}