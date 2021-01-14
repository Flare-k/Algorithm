#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const int INF = 1e9;
    const int MAX = 501;

    int n, m;   // n = 학생수, m = 두 학생 키를 비교한 횟수
    cin >> n >> m;

    int dist[MAX][MAX], path[MAX];
    fill(path, path + MAX, 0);
    memset(dist, 0, sizeof(dist));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = i == j ? 0 : INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a - 1][b - 1] = 1;
    }

    //Floyd Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            if (dist[i][j] < INF) {
                path[i]++;
                path[j]++;
                
                if (path[i] == n - 1) ans++;
                if (path[j] == n - 1) ans++;
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}