#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string convertFunc(int num, int N) {
    if (num == 0) return "0";

    string str = "";
    while (num != 0) {
        int mid = num % N;
        
        if (mid >= 0 && mid <= 9) str += to_string(mid);
        else if (mid >= 10 && mid <= 15) str += char(mid + 55);
        
        num /= N;
    }
    reverse(str.rbegin(), str.rend());

    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp;
    int mt = m * t;

    for (int num = 0; tmp.length() <= mt; num++) {
        tmp += convertFunc(num, n);
    }

    for (int i = 0; i < tmp.length(); i += m) {
        answer += tmp[i + p - 1];
        if (answer.length() == t) break;
    }

    return answer;
}

int main() {
    
    cout << solution(2, 4, 2, 1) << '\n';
    cout << solution(16, 16, 2, 1) << '\n';
    cout << solution(16, 16, 2, 2) << '\n';

    return 0;
}