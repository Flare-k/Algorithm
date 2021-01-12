#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/**
 * LCS - Longest Common Subsequence, 최장 공통 부분 수열
 * = 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    int res[1002][1002];

    int i, j;
    for (i = 1; i <= b.length(); i++) {
        for (j = 1 ; j <= a.length(); j++) {
            if (b[i - 1] == a[j - 1]) { // 두 문자가 같으면 좌대각 + 1
                res[i][j] = res[i - 1][j - 1] + 1;
            }
            else {  // 두 문자가 다르면 왼쪽값과 위쪽값 중 큰 값
                res[i][j] = max(res[i - 1][j], res[i][j - 1]);
            }
        }
    }

    cout << res[i - 1][j - 1];

    return 0;
}