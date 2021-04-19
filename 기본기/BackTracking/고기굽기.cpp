#include <iostream>
#include <string>
using namespace std;

string meat;
int minCnt = 21e8;
int cnt;

bool isOX() {
    char pivot = meat[0];
    for (int i = 0; i < meat.length(); i++) {
        if (pivot != meat[i]) return false;
    }

    return true;
}

void changeOX(int i) {
    if (meat[i] == 'X') meat[i] = 'O';
    else meat[i] = 'X';

    if (i - 1 >= 0) {
        if (meat[i - 1] == 'X') meat[i - 1] = 'O';
        else meat[i - 1] = 'X';
    }

    if (i + 1 < meat.length()) {
        if (meat[i + 1] == 'X') meat[i + 1] = 'O';
        else meat[i + 1] = 'X';
    }

}

void run(int level) {
    if (level >= minCnt) return;

    if (isOX()) {
        if (minCnt > level) minCnt = level;
        return;
    }

    if (level == 4) return;

    string tmp;
    tmp = meat;

    for (int i = 0; i < meat.length(); i++) {
        changeOX(i);
        run(level + 1);
        meat = tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> meat;

    run(0);

    if (minCnt == 21e8) {
        cout << "impossible";
    }
    else {
        cout << minCnt;
    }

    return 0;
}