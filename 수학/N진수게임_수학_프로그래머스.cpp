#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string convertFunc(int last, int N) {
    if (last == 0) return "0";
    
    string str = "0";

    for (int i = 1; i <= last; i++) {
        string tmp = "";
        int num = i;

        while (num != 0) {
            int mid = num % N;
            
            if (mid >= 0 && mid <= 9) tmp += to_string(mid);
            else if (mid >= 10 && mid <= 15) tmp += char(mid + 55);
            
            num /= N;
        }

        reverse(tmp.begin(), tmp.end());
        str += tmp;
    }
    
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string str = convertFunc(m * t, n);        // m * t로 하는게 포인트

    for (int i = 0; i < str.length(); i += m) {
        answer += str[i + p - 1];
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