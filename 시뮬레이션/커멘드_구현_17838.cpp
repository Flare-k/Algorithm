#include <iostream>
#include <string>
#include <set>
using namespace std;

int N;
set<char> s;

bool checkString(string cmd) {
    if ((cmd[0] == cmd[1] && cmd[0] == cmd[4]) && (cmd[2] == cmd[3] && cmd[3] == cmd[5] && cmd[5] == cmd[6]) && cmd[0] != cmd[2]) return true;
    return false;
}

bool checkPattern(string cmd) {
    int len = cmd.length();

    if (len == 7) {
        // 몇 종류?
        s.clear();
        for (char ch : cmd) {
            s.insert(ch);
        }

        if (s.size() == 2) {
            if (checkString(cmd)) return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if (checkPattern(cmd)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}