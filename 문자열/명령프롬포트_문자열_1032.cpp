#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;   // 문자열 개수

    string cmd[n];

    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
    }

    string res = "";    // 비교하기 위한 문자열 변수
    res += cmd[0];      // 가장 첫 문자열을 res에 갱신
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < cmd[i].length(); j++) {
            if (res[j] != cmd[i][j]) {
                res[j] = '?';
            }
        }
    }

    cout << res;

    return 0;
}