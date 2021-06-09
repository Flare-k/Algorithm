#include <iostream>
#include <cstring>
#define INF 9876543
using namespace std;

const int MAX = 1001;
int n, m, x;

int run(int arr[MAX][MAX]) {
    int d[MAX][MAX];
    
    memcpy(d, arr, sizeof(d));

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    int maxSum = 0;
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        if (maxSum < d[i][x] + d[x][i]) maxSum = d[i][x] + d[x][i];
    }

    return maxSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> x;

    int arr[MAX][MAX];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            arr[i][j] = INF;
        }
    }

    int f, t, d;
    for (int i = 0; i < m; i++) {
        cin >> f >> t >> d;
        arr[f][t] = d;
    }

    cout << run(arr);

    return 0;
}