#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n;
char puzzle[5][6];
bool exitFlag;

void spin(int x, int y) {
    char tmp[5][5];
    memset(tmp, 0, sizeof(tmp));
    x -= 1;
    y -= 1;

    // tmp는 0 ~ 3으로 해도 무방하다. puzzle의 인덱스만 조절하면 됨
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tmp[j][2 - i] = puzzle[x + i][y + j];
        }
    }

    // 회전한 지역만큼 업데이트
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            puzzle[x + i][y + j] = tmp[i][j];
        }
    }
}

// AAA가 연달아 나오는지 확인
bool isAAA(int x, int y) {
    for (int i = -1; i <= 1; i++) {
        bool flag = false;
        for (int j = -1; j <= 1; j++) {
            if (puzzle[x + i][y + j] != 'A') {
                flag = true;
                break;
            }
        }
        if (flag == false) return true;
    }

    return false;
}


void run(int level) {
    if (level == 6) return;

    char backUp[5][6];
    memcpy(backUp, puzzle, 5 * 6);

    for (int i = 1 ; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            spin(i, j);

            if (isAAA(i, j)) {
                exitFlag = true;
                return;
            }

            run(level + 1);
            if (exitFlag) return;

            memcpy(puzzle, backUp, 5 * 6);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < n; j++) {
            puzzle[i][j] = input[j];
        }
    }

    run(0);

    if (exitFlag) cout << "가능";
    else cout << "불가능";

    return 0;
}