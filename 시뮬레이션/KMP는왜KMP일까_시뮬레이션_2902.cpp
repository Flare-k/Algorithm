#include <iostream>
#include <string>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    string s;
    cin >> s;

    string ans = "";
    ans += s[0];
    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == '-') {
            ans += s[i];
        }
    }

    cout << ans;

    return 0;
}