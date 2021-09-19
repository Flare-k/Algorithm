#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 501;
bool list[MAX][MAX];
bool friends[MAX];
bool visit[MAX];
int n, m, answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        
        list[a][b] = true;
        list[b][a] = true;
    }

    // 상근이와 친구
    for (int i = 2; i <= n; i++) {
        if (list[1][i]) {
            visit[i] = true;
            friends[i] = true;
        }
    }

    // 친구와 친구
    for (int i = 2; i <= n; i++) {
        if (friends[i]) {
            for (int j = 1; j <= n; j++) {
                if (i != j && list[i][j]) {
                    visit[j] = true;
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (visit[i]) answer++;
    }

    cout << answer;

    return 0;
}