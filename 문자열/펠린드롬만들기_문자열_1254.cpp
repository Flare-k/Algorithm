#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool checkPelindrome(string s) {
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int idx = str.length() - 1;
    int minLen = 21e8;;

    // 주어진 문자열의 가장 마지막 문자를 펠린드롬의 축이라고 가정
    // 0 ~ 중심-n 을 계속 붙여봤을 때 가장 작은 펠린드롬이 나오면 체크
    // 펠린드롬 특징상 가장 안쪽보다 가에 있는 원소가 대칭되는게 적절하다고 생각하고 풀이
    while (idx >= 0) {
        string tmp = str.substr(0, idx--);  
        reverse(tmp.begin(), tmp.end());

        string check = str + tmp;

        if (checkPelindrome(check)) {
            if (minLen > check.length()) {
                minLen = check.length();
            }
        }
    }

    cout << minLen;

    return 0;
}