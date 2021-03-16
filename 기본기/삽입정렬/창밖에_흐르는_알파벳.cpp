#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    string res = "";
    for (int i = 0; i < s.length(); i++) {
        res += "_";
    }

    cout << s << '\n';
    while (res != s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '_' && s[i] != 'A') {
                s[i] = char(s[i] - 1);
            }
            else if (s[i] == 'A') {
                s[i] = '_';
            }
            cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}