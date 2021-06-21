#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1001;
const int MAX = 201;
int map[MAX][MAX];
vector<int> routes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) map[i][j] = INF;
            map[i][i] = 1;  // 출발지와 도착지와 같을 수 있으므로..
        }
    }

    // floyd Warshall
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }

    int a;
    for (int i = 0; i < M; i++) {
        cin >> a;
        routes.push_back(a);
    }

    bool flag = false;

    for (int i = 0; i < routes.size() - 1; i++) {
        int start = routes[i] - 1;
        int end = routes[i + 1] - 1;

        if (map[start][end] == INF) {
            flag = true;
            break;
        }
    }

    if (flag) cout << "NO" << '\n';
    else cout << "YES" << '\n';

    return 0;
}
/*
5
5
0 1 0 1 1
1 0 0 1 0
0 0 0 0 0
1 1 0 0 0
1 0 0 0 0
5 3 2 3 4
> NO

5
5
0 1 0 1 1
1 0 1 1 0
0 1 0 0 0
1 1 0 0 0
1 0 0 0 0
5 3 2 3 5
> YES

3
2
0 0 0
0 0 0
0 0 0
1 1
> YES
*/