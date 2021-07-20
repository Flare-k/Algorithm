#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, bool> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string cam = "CAMBRIDGE";

    for (int i = 0; i < cam.length(); i++) {
        m[cam[i]] = true;
    }

    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (m.count(str[i])) continue;
        cout << str[i];
    }

    return 0;
}