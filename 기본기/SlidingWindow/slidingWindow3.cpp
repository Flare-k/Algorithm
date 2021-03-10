#include <iostream>
#include <string>

using namespace std;

/*
 연속된 네 개 구간에서 가장 많이 등장하는 알파벳의 수를 출력하라
*/

int alpha[26]{0,};

int cntMax() {
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (ans < alpha[i]) {
            ans = alpha[i];
        }
    }

    return ans;
}

int main() {
    string arr = "ABABTTTTCABATBCQ";

    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        alpha[arr[i] - 65]++;
    }

    int maxNum = cntMax();
    int maxCnt = -1;
    for (int i = 0; i <= arr.length() - 4; i++) {
        if (maxCnt < maxNum) {
            maxCnt = maxNum;
        }
        
        if (i == arr.length() - 4) break;

        alpha[arr[i] - 65]--;
        alpha[arr[i + 4] - 65]++;
        maxNum = cntMax();
    }

    cout << maxCnt << '\n';

    return 0;
}