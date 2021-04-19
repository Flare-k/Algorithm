#include <iostream>
#include <string>
using namespace std;

string meat;
int minCnt = 21e8;
int cnt, n;

bool isOX() {
    char pivot = meat[0];
    for (int i = 0; i < meat.length(); i++) {
        if (pivot != meat[i]) return false;
    }

    return true;
}

// 좌 가운데 우 | 값이 X 또는 O일 경우 그 반대로 변경
void changeOX(int idx) {
    for (int i = -1; i <= 1; i++) {
        int conn = idx + i;
        if (conn <= 0 || conn >= n) continue;

        if (meat[conn] == 'O') meat[conn] = 'X';
        else meat[conn] = 'O';
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
    n = meat.length();

    run(0);

    if (minCnt == 21e8) {
        cout << "impossible";
    }
    else {
        cout << minCnt;
    }

    return 0;
}