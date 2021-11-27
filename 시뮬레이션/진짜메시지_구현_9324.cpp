#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        map<char, int> m;

        string s;
        cin >> s;

        bool flag = false;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (++m[s[i]] == 3) {
                if (s[i+1] != s[i]) {
                    flag = true;
                    break;
                }
                m[s[i]] = 0;
                ++i;
            }
        }

        if (flag) cout << "FAKE" << '\n';
        else cout << "OK" << '\n';
    }

    return 0;
}