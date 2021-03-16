#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

// 상 하 좌 우
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char frame[3][7] = {"ABCEFG",
                        "HIJKLM",
                        "NOPQRS"};

    char sharp[3][6];
    memset(sharp, '0', sizeof(sharp));

    string s;
    cin >> s;

    int len = s.length();

    int idx = 0;
    while (len--) {
        int x, y;
        bool flag = false;
        // 좌표 찾기
        for (int i = 0; i < 3; i++) {
            if (flag) break;
            for (int j = 0; j < 6; j++) {
                if (s[idx] == frame[i][j]) {
                    x = i;
                    y = j;
                    flag = true;
                    break;
                }
            }
        }
        
        // '#' 표시하기
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 6) {
                if (sharp[nx][ny] != '#') {
                    sharp[nx][ny] = '#';
                }
                else {
                    sharp[nx][ny] = '0';
                }
            }
        }
        sharp[x][y] = '#';
        idx++;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            if (sharp[i][j] == '#') {
                cout << sharp[i][j];
            }
            else {
                cout << frame[i][j];
            }
        }
        cout << '\n';
    }

    return 0;
}