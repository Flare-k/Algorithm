#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        string s;
        getline(cin, s);

        if (s == "END") break;

        reverse(s.begin(), s.end());

        cout << s << '\n';
    }

    return 0;
}