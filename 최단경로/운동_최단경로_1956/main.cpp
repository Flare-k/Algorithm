/*플로이드 워셜*/
#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    int graph[401][401];
    cin >> n >> m;
    // 초기값 셋팅
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j){
                graph[i][j] = 0;
            }
            else{
                graph[i][j] = INF;
            }
        }
    }
    // 연결 관계 입력
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    // 최단 경로 설정
    for (int k = 1; k <= n; k++) {
       for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) {
             if (graph[i][k] + graph[k][j] < graph[i][j]) {
                graph[i][j] = graph[i][k] + graph[k][j];
             }
          }
       }
    }

    int res = INF;
    for (int i = 1; i <= n; i++){
       for (int j = 1; j <= n; j++) {
           if (i == j) continue;
           res = min(res, graph[i][j] + graph[j][i]);
       }
    }
    
    if(res == INF)
        cout << -1;
    else
        cout << res;

    return 0;
}