#include <iostream>
#include <string>
using namespace std;

bool flag = false;

bool checkSeq(string s) {
    int len = s.length();
    int idx = len / 2;

    for (int i = 1; i <= idx; i++) {
        string str1 = s.substr(len - (2 * i), i);
        string str2 = s.substr(len - i, i);
        if (str1 == str2) return false;
    }

    return true;
}

void run(int level, int n, string answer) {
    if (level == n) {
        cout << answer << '\n';
        flag = true;
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (checkSeq(answer + to_string(i))) {
            run(level + 1, n, answer + to_string(i));
        }

        if (flag) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    run(0, n, "");

    return 0;
}