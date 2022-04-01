#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
string str;
long long answer = -21e8;

int calculate(int A, int B, char oper) {
    int result = A;

    if (oper == '+') result += B;
    else if (oper == '-') result -= B;
    else if (oper == '*') result *= B;

    return result;
}

void run(int idx, long long now) {
    if (idx > N - 1) {
        answer = max(answer, now);
        return;
    }

    char oper = (idx == 0) ? '+' : str[idx - 1];

    if (idx + 2 < N) {
        int join = calculate(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
        run(idx + 4, calculate(now, join, oper));
    }

    run(idx + 2, calculate(now, str[idx] - '0', oper));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> str;
    run(0, 0);
    
    cout << answer << '\n';

    return 0;
}