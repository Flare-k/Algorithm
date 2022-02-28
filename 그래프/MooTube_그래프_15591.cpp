#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define ll long long
#define MAX 5001
using namespace std;

int N, Q;
bool visit[MAX];
struct Node {
    ll node, usado;
};
vector<Node> graph[MAX];

void run(ll K, ll V) {
    queue<Node> q;
    memset(visit, false, sizeof(visit));
    
    visit[V] = true;
    int answer = 0;

    // 기준이 되는 동영상과 인접한 동영상들을 후보로 담기
    for (auto g : graph[V]) {
        visit[g.node] = true;
        q.push({g.node, g.usado});
    }

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (now.usado >= K) {
            // 유사도가 K이상이면 answer++
            answer++;

            // 연결된 노드의 다음 노드 중 방문하지 않았던 노드가 있다면
            for (auto next : graph[now.node]) {
                if (!visit[next.node]) {
                    visit[next.node] = true;
                    q.push({next.node, min(now.usado, next.usado)});
                }
            }
        }
    }

    cout << answer << '\n';
}

void init() {
    cin >> N >> Q;

    for (int i = 0; i < N - 1; i++) {
        ll p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back({q, r});
        graph[q].push_back({p, r});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    for (int i = 0; i < Q; i++) {
        ll K, V;
        cin >> K >> V;
        run(K, V);
    }
   
    return 0;
}