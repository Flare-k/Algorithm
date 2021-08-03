#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, bool> m;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    while (n--) {
        m.clear();
        string s;
        cin >> s;

        for (char ch : s) {
            if (m[ch]) continue;
            m[ch] = true;
        }

        int sum = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            if (m[ch] == false) sum += ch;
        }

        cout << sum << '\n';
    }

    return 0;
}