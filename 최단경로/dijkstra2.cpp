#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 1e9
using namespace std;

/* 우선순위 큐를 이용하므로 get_smallestNode 함수는 필요없다.*/

int n, m, start;
vector<pair<int, int> > graph[100001];
int d[100001];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    // dist 부분에서 마이너스를 안 쓸려면?
    // -> priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
    pq.push({0, start}); // {가중치, 노드}
    d[start] = 0;

    while (!pq.empty()){
        // 우선순위 큐이므로 거리가 먼 값을 고려하기 위해 음수 처리하여 거리가 가까운 값을 최우선으로 오도록 만든다.
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;

        for (int i = 0; i < graph[now].size(); i++){
            int cost = dist + graph[now][i].second;
            
            if (cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> start;

    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    fill(d, d + 100001, INF);

    dijkstra(start);

    for (int i = 1; i <= n; i++){
        if (d[i] == INF){
            cout << "INFINITY" << "\n";
        }
        else{
            cout << d[i] << "\n";
        }
    }

    return 0;
}