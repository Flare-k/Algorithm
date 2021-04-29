#include <iostream>
#include <string>
using namespace std;

// 0과 1중 더미가 적은곳의 위치를 바꿔주면 최소의 횟수로 뒤집게 된다.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;

    int zero = 0;
    int one = 0;
    int flag = -1;

    for (char c : s) {
        if (flag != 0 && c == '0') {
            flag = 0;
            ++zero;
        }
        else if (flag != 1 && c == '1') {
            flag = 1;
            ++one;
        }
    }

    cout << min(zero, one);

    return 0;
}