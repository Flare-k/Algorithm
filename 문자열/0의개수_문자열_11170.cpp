#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int checkZero(string s) {
    int cnt = 0;

    for (char ch : s) {
        if (ch == '0') cnt++;
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int a, b;
        cin >> a >> b;

        int sum = 0;
        for (int i = a; i <= b; i++) {
            sum += checkZero(to_string(i));
        }

        cout << sum << '\n';
   }

    return 0;
}