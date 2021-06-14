#include <iostream>
#define INF 100000
using namespace std;

const int MAX = 401;
int vect[MAX][MAX];
int n, k;
int a, b;

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) vect[i][j] = INF;
            else vect[i][j] = 0;
        }
    } 
    
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        vect[a - 1][b - 1] = 1;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    init();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vect[i][k] + vect[k][j] < vect[i][j]) {
                    vect[i][j] = vect[i][k] + vect[k][j];
                }
            }
        }
    }


    int s;
    cin >> s;

    for (int i = 0; i < s; i++) {
        cin >> a >> b;
        a--;
        b--;

        if (vect[a][b] != INF && vect[b][a] == INF) cout << -1 << '\n';
        else if (vect[a][b] == INF && vect[b][a] != INF) cout << 1 << '\n';
        else if (vect[a][b] == INF && vect[b][a] == INF) cout << 0 << '\n';
    }


    return 0;
}