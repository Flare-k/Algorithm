#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int K, N, M;
    cin >> K >> N >> M;

    if (K * N > M) {
        cout << (K * N) - M;
    }
    else cout << 0;

    return 0;
}