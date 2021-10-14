#include <iostream>
#include <string>
using namespace std;

// 문제에서 주어진 알파벳의 획수
int alp[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int dp[4001];
string A, B;

int main() {

    cin >> A >> B;

    int i = 0;
    for (char ch : A) {
        dp[2 * i] = alp[ch - 'A'];
        i++;
    }

    i = 0;
    for (char ch : B) {
        dp[2 * i + 1] = alp[ch - 'A'];
        i++;
    }

    int len = A.length() * 2;
    int idx = 0;

    while (len != 2) {
        dp[idx] = (dp[idx] + dp[idx + 1]) % 10;
        idx++;

        if (idx == len) {
            dp[idx - 1] = 0;
            idx = 0;
            len--;
        }
    }

    cout << dp[0] << dp[1];

   return 0;
}