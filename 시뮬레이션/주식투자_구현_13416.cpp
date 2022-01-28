#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        
        int answer = 0;

        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            int tmp1 = max(a, b);
            int num = max(tmp1, c);

            if (num > 0) answer += num;
        }

        cout << answer << '\n';
    }

    return 0;
}