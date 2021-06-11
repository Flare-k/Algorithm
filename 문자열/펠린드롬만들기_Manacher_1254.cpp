#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s;
int len;

bool palindrome(int idx) {
    for (int i = 0; idx + i < len - i - 1; i++) {
        if (s[idx + i] != s[len - i - 1]) return false;
    }
    return true;
}

int main() {

    cin >> s;

    len = s.length();
    int res = 0;

    for (int i = 0; i < len; i++) {
        if (palindrome(i)) {
            res = len + i;
            break;
        }
    }

    cout << res;

    return 0;
}