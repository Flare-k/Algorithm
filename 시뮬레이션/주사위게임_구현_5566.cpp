#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> map;
vector<int> dice;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    map.resize(N);
    dice.resize(M);

    for (int i = 0 ; i < N; i++) {
        cin >> map[i];    
    }

    for (int i = 0 ; i < M; i++) {
        cin >> dice[i];
    }

    int idx = 0;
    int i;
    for (i = 0; i < M; i++) {
        idx += dice[i];
        if (idx >= N - 1) break;
        
        idx += map[idx];
        if (idx >= N - 1) break;
        if (idx < 0) idx = 0;
    }

    if (i != M) cout << i + 1;
    else cout << M;

    return 0;
}