#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 32768;
bool visit[MAX];
vector<int> graph[MAX];

int distance(pair<int, int>& w1, pair<int, int>& w2){
    int ans = 0 ;
    ans = abs(w1.first - w2.first) + abs(w1.second - w2.second);

    return ans;
}

void DFS(int n){
    visit[n] = true;

    for (int i = 0; i < graph[n].size(); i++){
        int next = graph[n][i];
        if (!visit[next]){
            DFS(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;

    while (T--) {
        for (int i = 0; i < MAX; i++){
            graph[i].clear();
        }
        memset(visit, false, sizeof(visit));

        int n;
        cin >> n;  // 편의점의 개수
        vector<pair<int, int>> way;

        for (int i = 0; i < n + 2; i++) {
            int x, y;
            cin >> x >> y;
            way.push_back({x, y});  // 상근이네, n개의 편의점, 락 페스티벌 좌표 push_back
        }

        for (int i = 0; i < n + 2; i++) {
            for (int j = i + 1; j < n + 2; j++) {
                int dist = distance(way[i], way[j]);
                if (dist <= 1000){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }   // 만약 거리가 1000 이하라면 행복하게 페스티벌에 갈 수 있으므로 해당 노드들을 연결시켜준다.

        DFS(0);

        if (visit[n + 1]){  // 맨마지막 노드인 페스티벌 노드까지 방문 표시가 되었는지 확인
            cout << "happy" << endl;
        }
        else{
            cout << "sad" << endl;
        }
    }   // T 반복

   return 0;
}