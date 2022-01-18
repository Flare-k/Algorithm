#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int cnt = 0;

    for (char ch : s) {
        if (ch == ',') cnt++;
    }

    cout << cnt + 1;

    return 0;
}