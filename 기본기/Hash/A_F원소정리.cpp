#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> um;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'f') s[i] = toupper(s[i]);
        um[s[i]]++;
    }

    for (char ch = 'A'; ch <= 'F'; ch++) {
        if (um.count(ch)) {
            cout << ch << ":" << um[ch] << '\n';
        }
        else {
            cout << ch << ":" << 0 << '\n';
        }
    }

    return 0;
}