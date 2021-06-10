#include <iostream>
#include <cstring>
#include <vector>
#define INF 1001
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> map(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        map[s - 1][e - 1] = 1;
        map[e - 1][s - 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        map[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][k] + map[k][j] < map[i][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }

    int minSum = 21e8;
    int person = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += map[i][j];
        }
        
        if (minSum > sum) {
            minSum = sum;
            person = i + 1;
        }
    }

    cout << person;

    return 0;
}