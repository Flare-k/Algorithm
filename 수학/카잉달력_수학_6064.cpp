#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, M, N, x, y;

    cin >> T;

    while (T--) {
        cin >> M >> N >> x >> y;

        if (x == y) {
            cout << x << '\n';
            continue;
        }

        int limit = M * N;
        bool flag = false;

        for (int num = x; num <= limit; num += M) {
            
            int result = (num % N == 0) ? N : num % N;

            if (result == y) {
                cout << num << '\n';
                flag = true;
                break;
            }
        }

        if (!flag) cout << -1 << '\n';
    }
    
    return 0;
}