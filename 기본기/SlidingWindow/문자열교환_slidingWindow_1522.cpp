#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    int cnt = 0;
    int len = str.length();

    for (int i = 0; i < len; i++) {
        if (str[i] == 'a') cnt++;
    }

    int answer = cnt;

    for (int i = 0; i < len; i++) {
        int b = 0;

        for (int j = i; j < i + cnt; j++) {
            if (str[j % len] == 'b') b++;
        }

        answer = min(answer, b);
    }

    cout << answer << '\n';

    return 0;
}
