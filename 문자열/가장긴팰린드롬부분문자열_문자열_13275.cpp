#include <iostream>
using namespace std;

const int MAX = 100001 * 2;
int A[MAX];

void manachers(string s, int N) {
    int r = 0, p = 0;

    for (int i = 0; i < N; i++) {
        if (i <= r) A[i] = min(A[2*p - i], r - i);
        else A[i] = 0;

        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && s[i - A[i] - 1] == s[i + A[i] + 1]) A[i]++;

        if (r < i + A[i]) {
            r = i + A[i];
            p = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;

    int len = s.length();

    string str = "";
    for (int i = 0; i < len; i++) {
        str += '#';
        str += s[i];
    }
    str += '#';

    manachers(str, str.length());

    len = str.length();

    int answer = -1;

    for (int i = 0; i < len; i++) {
        answer = max(answer, A[i]);
    }
    
    cout << answer;
    
    return 0;
}