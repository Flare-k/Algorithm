#include <iostream>
#include <string>

using namespace std;

/*
1 = 1
2 = 2 4 8 6
3 = 3 9 7 1
4 = 4 6
5 = 5
6 = 6
7 = 7 9 3 1
8 = 8 4 2 6
9 = 9 1
최대 4주기
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;  // 전체 테스트 케이스 개수
    cin >> T;

    while (T--) {
        long a, b;
        cin >> a >> b;
        
        long res = a;
        b = b % 4 + 4;    // 최대 4주기 이므로 최대한 경우를 줄여준다.

        for (long i = 2; i <= b; i++) {
            res = (res * a) % 10;      // 1의 자리수만 곱한다.
        }
        if (res == 0) {
            res = 10;
        }

        cout << res  << '\n';
    }

    return 0;
}