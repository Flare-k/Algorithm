#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        string a, b;
        cin >> a >> b;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int len = a.length();

        bool flag = true;

        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) {
                flag = false;
                break;
            }
        }

        if (flag) cout << "Possible\n";
        else cout << "Impossible\n";
    }

    return 0;
}