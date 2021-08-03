#include <iostream>
#include <algorithm>
using namespace std;

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long a, b, c, d;
    while (1) {
        cin >> a >> b >> c >> d;

        if (a == 0 && b == 0 && c == 0 && d == 0) break;

        int cnt = 0;
        while (1) {
            if (a == b && b == c && c == d && d == a) break;
            
            long long tmpa = a;
            a = abs(a - b);
            b = abs(b - c);
            c = abs(c - d);
            d = abs(d - tmpa);

            cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}