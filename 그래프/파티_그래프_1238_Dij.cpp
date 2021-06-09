#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
#define INF 1e9
using namespace std;


const int MAX = 1001;
int n, m, x;
vector<pair<int, int> > graph[MAX];
vector<vector<int>> d;

void dijkstra(int start){
    
    priority_queue<pair<int, int>> pq;
        
    pq.push({0, start}); // {가중치, 노드}
    d[start][start] = 0;

    while (!pq.empty()){
        
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[start][now] < dist) continue;    // 현재 노드의 가중치가 기존 누적보다 크다면 continue

        for (int i = 0; i < graph[now].size(); i++){    // 현재 노드와 연결되어 있는 노드를 탐색
            int node = graph[now][i].first;
            int cost = dist + graph[now][i].second;
            
            // 누적 가중치보다 작다면 cost 갱신
            if (cost < d[start][node]){
                d[start][node] = cost;
                pq.push({-cost, node});
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 노드 개수, 간선 개수, 시작 노드
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;     // a 노드에서 b 노드의 거리 = c
        graph[a].push_back({b, c});
    }

    
    d.assign(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d[x][i] + d[i][x]);
    }
    cout << ans << '\n';
    

    return 0;
}